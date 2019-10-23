#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "string"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setMouseTracking(true);
    //centralWidget()->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->setupUi(this);
    qApp->installEventFilter(this);
    int count = 1;
    int buttons_count = 0;
    QString name;
    qDebug() << "Main window started";
//    QSignalMapper* signalMapper = new QSignalMapper(this);
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            p_button = new QPushButton(" ", this);
            box_window = new BoxWindow();
            p_button->setGeometry(QRect(QPoint((i*100)+(i*10),((j+1)*50)+(j*10)), QSize(100, 50)));
            name = "Box " + QString::number(count++);
            p_button->setText(name);
            buttons[buttons_count] = p_button;
//            connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(clicked(QString)));
//            signalMapper->setMapping(buttons[buttons_count], name);
            connect(buttons[buttons_count], SIGNAL(clicked(bool)), box_window, SLOT(changeTitle(bool)));
            buttons_count++;
        }
    }

}


bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
        QHoverEvent *mouseEvent = static_cast<QHoverEvent*>(event);

//        statusBar()->showMessage(QString("button %1").arg(get_button->text()));
        statusBar()->showMessage(QString("Mouse move (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));

    }
    return false;
}

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

