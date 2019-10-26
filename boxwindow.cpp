#include "boxwindow.h"
#include "ui_boxwindow.h"

BoxWindow::BoxWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoxWindow)
{
    ui->setupUi(this);
    connect(ui->actionPowr_t, SIGNAL(triggered()), this, SLOT(backToMain()));
    //calendar = new Calendar(ui->calendarWidget);
    QDate starting_date(2019, 10, 24);
    QDate end_date(2019, 10, 29);
    ui->calendarWidget->setStartOfRent(starting_date);
    ui->calendarWidget->setEndOfRent(end_date);
}

void BoxWindow::changeTitle(bool checked)
{
    // this->close();
    auto button = qobject_cast<QPushButton *>(sender());
    Q_ASSERT(button);
    qDebug() << button->text();
    title = button->text();
    BoxWindow* box_window = new BoxWindow();

    box_window->setWindowTitle(title);
    box_window->show();
}

void BoxWindow::paintCalendar(Calendar& calendar)
{
    // QPainter * painter = new QPainter;
    QDate starting_date(2019, 10, 26);
    QDate end_date(2019, 10, 29);
    //ui->calendarWidget->paintCell()
}

void BoxWindow::backToMain()
{
    this->close();
}

BoxWindow::~BoxWindow()
{
    delete ui;
}
