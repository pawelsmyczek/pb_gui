#include "renter_addition.h"
#include "ui_renter_addition.h"
#include "mainwindow.h"

RenterAddition::RenterAddition(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::renter_addition)
{
    ui->setupUi(this);
    ui->lineEdit_5->setInputMask("999-999-999");
    ui->lineEdit_6->setInputMask("NNNNNNNNNN@NNNNNNN.NNN");
    ui->lineEdit_7->setInputMask("99 9999 9999 9999 9999 9999 9999");
//    showAllHiddenTopLevelWidgets();
    connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(addRenter()));

    // connect(this, SIGNAL(buttonClicked()), this->parent(), SLOT(close()));
}

void RenterAddition::addRenter()
{
    QSqlQuery *q = new QSqlQuery(QSqlDatabase::database("PB_CONN"));
    QSqlQuery *q1 = new QSqlQuery(QSqlDatabase::database("PB_CONN"));
    QSqlQuery *q2 = new QSqlQuery(QSqlDatabase::database("PB_CONN"));

    this->name        = ui->lineEdit->text();
    this->surname     = ui->lineEdit_2->text();
    this->address     = ui->lineEdit_3->text();
    this->id          = ui->lineEdit_4->text();
    // QRegularExpression reMobile("[0-9]{9}");
    // QRegularExpressionMatch matchMobile = reMobile.match(ui->lineEdit_5->text());

    if(ui->lineEdit_5->hasAcceptableInput())
    this->mobile      = ui->lineEdit_5->text();
    else qDebug() << "Not a valid phone number";

    if(ui->lineEdit_6->hasAcceptableInput())
    this->mail        = ui->lineEdit_6->text();
    else qDebug() << "Not a valid e-mail";

    if(ui->lineEdit_7->hasAcceptableInput())
    this->account_nr  = ui->lineEdit_7->text();
    else qDebug() << "Not a valid account nr";

    if(this->name.isNull() || this->surname.isNull() || this->address.isNull() || this->id.isNull() || this->mobile.isNull() || this->mail.isNull() || this->account_nr.isNull())
        QMessageBox::warning(nullptr, "Empty values",
                         "Some values are still empty");
    else
    {
        QSqlDatabase::database().transaction();
        try {
            QString cli_id = insertRenter(q, this->name, this->surname, this->address,
                     this->id, this->mobile, this->mail, this->account_nr);
            insertReservation(q1, ui->dateEdit->date(), ui->dateEdit_2->date(), this->boxNumber, cli_id);
            updateBoxState(q2, this->boxNumber);
            qDebug() << this->name << this->surname << this->address << this->id << this->mobile << this->mail << this->account_nr << "has been inserted";
            QMessageBox::StandardButton added = QMessageBox::information(this, "Renter added",
                             "You have succesfully added renter to box");
            if(added == QMessageBox::Ok || added == QMessageBox::Close) {
                this->parentWidget()->parentWidget()->close();
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
    }
}

void RenterAddition::showAllHiddenTopLevelWidgets()
{
    const QWidgetList topLevelWidgets = QApplication::topLevelWidgets();
    for (QWidget *widget : topLevelWidgets) {
            widget->close();
    }

}


RenterAddition::~RenterAddition()
{
    delete ui;
}
