#include "boxwindow.h"
#include "ui_boxwindow.h"
#include "mainwindow.h"

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
    ui->radioButton->setChecked(true);
    connect(ui->actionPowr_t, SIGNAL(triggered()), this, SLOT(backToMain()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(generateInvoice()));
    connect(ui->actionEdytuj_wszystko, SIGNAL(triggered()), this, SLOT(editMode()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(approveChanges()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(addPayment()));
    connect(ui->radioButton, SIGNAL(clicked()), this, SLOT(depositPayment()));
    this->setWindowTitle(title);
    ui->calendarWidget->setStartOfRent(starting_date);
    ui->calendarWidget->setEndOfRent(end_date);
    // edit ui members
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->radioButton->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_8->setVisible(false);
    ui->label_9->setVisible(false);
    ui->dateEdit->setVisible(false);
    ui->dateEdit_2->setVisible(false);
    ui->dateEdit_3->setVisible(false);
    ui->lineEdit_5->setVisible(false);
    ui->lineEdit->setText(renterData.at(0) + " " + renterData.at(1));
    this->show();
    delete q;
    delete q1;
}


void BoxWindow::changeStateOfUi(){
    ui->lineEdit_2->setVisible(!ui->lineEdit_2->isVisible());
    ui->lineEdit_3->setVisible(!ui->lineEdit_3->isVisible());
    ui->label_2->setVisible(!ui->label_2->isVisible());
    ui->label_3->setVisible(!ui->label_3->isVisible());


    ui->pushButton_2->setVisible(!ui->pushButton_2->isVisible());
    ui->pushButton_3->setVisible(!ui->pushButton_3->isVisible());
    ui->pushButton_4->setVisible(!ui->pushButton_4->isVisible());

    ui->radioButton->setVisible(!ui->radioButton->isVisible());
    ui->label_4->setVisible(!ui->label_4->isVisible());
    ui->label_5->setVisible(!ui->label_5->isVisible());
    ui->label_6->setVisible(!ui->label_6->isVisible());
    ui->dateEdit_2->setVisible(!ui->dateEdit_2->isVisible());
    ui->lineEdit_5->setVisible(!ui->lineEdit_5->isVisible());
    if(!ui->label_7->isVisible() && !ui->label_8->isVisible() && !ui->label_9->isVisible() && !ui->dateEdit->isVisible() && !ui->dateEdit_3->isVisible())
    {
        ui->label_7->setVisible(false);
        ui->label_8->setVisible(false);
        ui->label_9->setVisible(false);

        ui->dateEdit->setVisible(false);
        ui->dateEdit_3->setVisible(false);
    } else {
        ui->label_7->setVisible(!ui->label_7->isVisible());
        ui->label_8->setVisible(!ui->label_8->isVisible());
        ui->label_9->setVisible(!ui->label_9->isVisible());
        ui->dateEdit->setVisible(!ui->dateEdit->isVisible());
        ui->dateEdit_3->setVisible(!ui->dateEdit_3->isVisible());

    }

}

void BoxWindow::editMode(){
    changeStateOfUi();
}


void BoxWindow::approveChanges(){

    QSqlQuery* q = new QSqlQuery(QSqlDatabase::database("PB_CONN"));

    if(ui->lineEdit_5->text() != ""){
        QSqlDatabase::database().transaction();
        qDebug() << ui->lineEdit_5->text() << ui->dateEdit_2->date() << reservationData.at(2) << number1 << reservationData.at(3);
        try {
            if(ui->radioButton->isChecked()){
              // insert a transaction for deposit payment
                insertTransaction(q, ui->lineEdit_5->text(), ui->dateEdit_2->date(), reservationData.at(2), number1, reservationData.at(3), "TRUE");
                changeStateOfUi();
            } else {
              // insert a transaction for reservation payment
                insertTransaction(q, ui->lineEdit_5->text(), ui->dateEdit_2->date(), reservationData.at(2), number1, reservationData.at(3), "FALSE", ui->dateEdit->date(), ui->dateEdit_3->date());
                changeStateOfUi();
            }
            QMessageBox::StandardButton added = QMessageBox::information(this, "Renter added",
                                         "Transaction succesfully added");
            if(added == QMessageBox::Ok || added == QMessageBox::Close) {
                this->parentWidget()->close();
                this->close();
                qDebug() << "Performing application reboot...";
                QSqlDatabase::database().commit();
                qApp->exit( MainWindow::EXIT_CODE_REBOOT );
            }
        } catch (...) {
            QSqlDatabase::database().rollback();
            QMessageBox::warning(nullptr, "DB Error",
                             "Something went wrong");
        }
        } else {
        qDebug() << "Some values are still empty" ;
    }

    delete q;

}

void BoxWindow::paintCalendar(Calendar& calendar)
{
    // QPainter * painter = new QPainter;
    QDate starting_date(2019, 10, 26);
    QDate end_date(2019, 10, 29);
    //ui->calendarWidget->paintCell()
}

void BoxWindow::generateInvoice(){
    generatePdf();
}

void BoxWindow::addPayment(){
    ui->radioButton->setVisible(!ui->radioButton->isVisible());
    ui->label_4->setVisible(!ui->label_4->isVisible());
    ui->label_5->setVisible(!ui->label_5->isVisible());
    ui->label_6->setVisible(!ui->label_6->isVisible());
    ui->dateEdit_2->setVisible(!ui->dateEdit_2->isVisible());
    ui->lineEdit_5->setVisible(!ui->lineEdit_5->isVisible());
    if(!ui->label_7->isVisible() && !ui->label_8->isVisible() && !ui->label_9->isVisible() && !ui->dateEdit->isVisible() && !ui->dateEdit_3->isVisible())
    {
        ui->label_7->setVisible(false);
        ui->label_8->setVisible(false);
        ui->label_9->setVisible(false);

        ui->dateEdit->setVisible(false);
        ui->dateEdit_3->setVisible(false);
    } else {
        ui->label_7->setVisible(!ui->label_7->isVisible());
        ui->label_8->setVisible(!ui->label_8->isVisible());
        ui->label_9->setVisible(!ui->label_9->isVisible());
        ui->dateEdit->setVisible(!ui->dateEdit->isVisible());
        ui->dateEdit_3->setVisible(!ui->dateEdit_3->isVisible());

    }
}


void BoxWindow::depositPayment(){
    ui->label_7->setVisible(!ui->label_7->isVisible());
    ui->label_8->setVisible(!ui->label_8->isVisible());
    ui->label_9->setVisible(!ui->label_9->isVisible());

    ui->dateEdit->setVisible(!ui->dateEdit->isVisible());
    ui->dateEdit_3->setVisible(!ui->dateEdit_3->isVisible());
}

void BoxWindow::backToMain()
{
    this->close();
}

BoxWindow::~BoxWindow()
{
    delete ui;
}
