#include "boxwindow.h"
#include "ui_boxwindow.h"
#include "calendar.h"
#include "db_handler.h"

BoxWindow::BoxWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoxWindow)
{
    //calendar = new Calendar(ui->calendarWidget);


}

void BoxWindow::initializeBoxWindow(bool checked)
{
    // this->close();
    // BoxWindow* box_window = new BoxWindow();
    QSqlQuery *q = new QSqlQuery(QSqlDatabase::database("PB_CONN"));
    QSqlQuery *q1 = new QSqlQuery(QSqlDatabase::database("PB_CONN"));
    auto button = qobject_cast<QPushButton *>(sender());
    title = button->text();
    Q_ASSERT(button);
    QRegularExpression re("(?<=Box ).+");
    QRegularExpressionMatch match = re.match(title);
    number1 = match.captured(0);
    selectReservation(q, number1, &reservationData);
    selectRenter(q1, reservationData.at(2), &renterData);
    starting_date = QDate::fromString(reservationData.at(0), "yyyy-MM-dd");
    end_date = QDate::fromString(reservationData.at(1), "yyyy-MM-dd");
    qDebug() << title << number1 << starting_date  << end_date;
    ui->setupUi(this);
    connect(ui->actionPowr_t, SIGNAL(triggered()), this, SLOT(backToMain()));
    this->setWindowTitle(title);
    ui->calendarWidget->setStartOfRent(starting_date);
    ui->calendarWidget->setEndOfRent(end_date);
    ui->lineEdit->setText(renterData.at(0) + " " + renterData.at(1));
    this->show();
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
