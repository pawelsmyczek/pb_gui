#include "not_rentedboxwindow.h"
#include "ui_not_rentedboxwindow.h"
#include "db_handler.h"
#include "calendar.h"
#include <QSqlQuery>


NotRentedBoxWindow::NotRentedBoxWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::not_rentedboxwindow)
{
    ui->setupUi(this);
    connect(ui->actionPowr_t, SIGNAL(triggered()), this, SLOT(backToMain()));


     //qDebug() << "box from constructor" << box;
}

NotRentedBoxWindow::~NotRentedBoxWindow()
{
    delete ui;
}


void NotRentedBoxWindow::initializeBoxWindow(bool checked)
{
    // this->close();
    auto button = qobject_cast<QPushButton *>(sender());
    Q_ASSERT(button);
    QSqlQuery *q = new QSqlQuery(QSqlDatabase::database("PB_CONN"));
    title = button->text();
    QRegularExpression re("(?<=Box ).+");
    QRegularExpressionMatch match = re.match(title);
    this->setWindowTitle(title);
    this->show();
    this->number1 = match.captured(0);
    int box = this->number1.toInt();
    this->ui->lineEdit->setText(selectBoxSize(q, box));
    qDebug() << button->text() << box;
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(openRenterAddition()));
}



void NotRentedBoxWindow::openRenterAddition()
{
    new_renter = new RenterAddition(this);
    // connect(new_renter,SIGNAL(closed()),this,SLOT(close()));
    new_renter->boxNumber = this->number1;
    new_renter->show();
}

void NotRentedBoxWindow::backToMain()
{
    this->close();
}
