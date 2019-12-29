#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <QSqlQuery>

/*
 * TODO:
 * - generator faktur
 * - sprawdzenie, czy kaucja oplacona
 * - edycja boxu
 *
 */



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
//    setMouseTracking(true);
    //centralWidget()->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->setupUi(this);
    qApp->installEventFilter(this);
    int box = 0, corridor = 1, number_of_boxes = 0, boxes_flag = 1, boxes_on_side = 1, divider = 0, offset = 1;
    bool is_rented = false;
    connect(ui->actionWyloguj,SIGNAL(triggered()),this,SLOT(logoutFromDB()));
    QString name;
    QSqlQuery *q = new QSqlQuery(QSqlDatabase::database("PB_CONN"));
    QSqlQuery *counter = new QSqlQuery(QSqlDatabase::database("PB_CONN"));
    if(!q->exec(SEL_BOXES)) qDebug() << "Failed to execute query SEL_BOXES" << q->lastError().text();
    // MAPOWANIE BOXOW
    number_of_boxes = countBoxes(counter, corridor);
    while(q->next()){
        box             = q->value(0).toInt();
        corridor        = q->value(1).toInt();
        is_rented       = q->value(2).toBool();

        // qDebug() << box << number_of_boxes << corridor << boxes_flag;

        name = "Box " + QString::number(box);
        p_button = new QPushButton(" ", this);
        p_button->setGeometry(QRect(QPoint(offset*50+offset*10,boxes_on_side*25+boxes_on_side*10),
                                    QSize(50, 25)));
        p_button->setText(name);
        buttons.push_back(p_button);
        connectButton(is_rented, buttons.back());

        divider = number_of_boxes/2;

        if(boxes_on_side < number_of_boxes-divider && boxes_flag < number_of_boxes) boxes_on_side++;
        else                                                                        { offset++; boxes_on_side = 1; }
        if(boxes_flag == number_of_boxes)                                           boxes_flag = 1;
        else if(boxes_flag < number_of_boxes)                                       boxes_flag++;

        number_of_boxes = countBoxes(counter, corridor);
    }
    qDebug() << "Main window started";
}

int const MainWindow::EXIT_CODE_REBOOT = -123456789;

void MainWindow::connectButton(bool is_rented, QPushButton *button)
{
    if(!is_rented)
    {
        not_rentedboxwindow = new NotRentedBoxWindow(this);
        button->setStyleSheet("background-color:red;");
        connect(button, SIGNAL(clicked(bool)), not_rentedboxwindow, SLOT(initializeBoxWindow(bool)));
    }
    else
    {
        box_window = new BoxWindow(this);
        button->setStyleSheet("background-color:green;");
        connect(button, SIGNAL(clicked(bool)), box_window, SLOT(initializeBoxWindow(bool)));
    }
}

void MainWindow::logoutFromDB(){
    QSqlDatabase::database("PB_CONN").close();
    parentWidget()->
    parentWidget()->show();
    this->close();
}

//bool MainWindow::eventFilter(QObject *obj, QEvent *event)
//{
//    if (event->type() == QEvent::MouseMove)
//    {
//        QHoverEvent *mouseEvent = static_cast<QHoverEvent*>(event);

////        statusBar()->showMessage(QString("button %1").arg(get_button->text()));
//        statusBar()->showMessage(QString("Mouse move (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));

//    }
//    return false;
//}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    QString x, y;
    x = QString::number(event->x());
    y = QString::number(event->y());
    qDebug() << x;
    qDebug() << y;
}

MainWindow::~MainWindow()
{
    delete ui;
}

