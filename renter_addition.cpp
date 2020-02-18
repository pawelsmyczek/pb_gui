#include "renter_addition.h"
#include "ui_renter_addition.h"
#include "mainwindow.h"

RenterAddition::RenterAddition(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::renter_addition)
{
    ui->setupUi(this);
    model = new QSortFilterSqlQueryModel(this);
    model->setQuery("select name, surname, adress, id, mobile, mail, account_nr from \"polbox_schema\".\"t_client_ind\"", QSqlDatabase::database("PB_CONN"));
    // model->setFilter("test");

    ui->lineEdit_8->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->label_11->setVisible(false);
    ui->lineEdit_5->setInputMask("+99-999-999-999");
    ui->lineEdit_7->setInputMask("99 9999 9999 9999 9999 9999 9999");
    connect(ui->actionPowr_t, SIGNAL(triggered()), this, SLOT(backToMain()));
    connect(ui->actionDodaj_z_bazy_danych, SIGNAL(triggered()), this, SLOT(showTableView()));
    connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(addRenter()));
    connect(ui->lineEdit_8, SIGNAL (textChanged(QString)), model, SLOT (filter(QString)));
    connect(ui->comboBox, SIGNAL (highlighted(int)), this, SLOT (switchFilters(int)));
    connect(ui->pushButton_2,SIGNAL(clicked()), this, SLOT(addRenter()));
    ui->tableView->setModel(model);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // ustawiam tryb bez możliwości edytowania pól tabeli
    QBrush brushBackground(Qt::gray); // tworzę brush wypełnienia tła komórek

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // ustawiam zaznaczanie całych wierszy
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //
    ui->tableView->setVisible(false);
}

void RenterAddition::addRenter()
{
    std::unique_ptr<QSqlQuery> q (new QSqlQuery(QSqlDatabase::database("PB_CONN")));
    std::unique_ptr<QSqlQuery>q1 (new QSqlQuery(QSqlDatabase::database("PB_CONN")));
    std::unique_ptr<QSqlQuery>q2 (new QSqlQuery(QSqlDatabase::database("PB_CONN")));
    QObject* _sender = sender();
    QString cli_id = "";

    if(_sender == ui->pushButton_2){
        qDebug() << "button 2 pressed";
        int row_index = ui->tableView->selectionModel()->currentIndex().row();
        this->name        = model->index(row_index, 0).data().toString();
        this->surname     = model->index(row_index, 1).data().toString();
        this->address     = model->index(row_index, 2).data().toString();
        this->id          = model->index(row_index, 3).data().toString();
        this->mobile      = model->index(row_index, 4).data().toString();
        this->mail        = model->index(row_index, 5).data().toString();
        this->account_nr  = model->index(row_index, 6).data().toString();
        qDebug() << model->index(row_index, 0).data().toString();
    } else if(_sender == ui->pushButton) {
        qDebug() << "button pressed";
        this->name        = ui->lineEdit->text();
        this->surname     = ui->lineEdit_2->text();
        this->address     = ui->lineEdit_3->text();
        this->id          = ui->lineEdit_4->text();

        if(ui->lineEdit_5->hasAcceptableInput())
        this->mobile      = ui->lineEdit_5->text();
        else qDebug() << "Not a valid phone number";

        this->mail        = ui->lineEdit_6->text();

        if(ui->lineEdit_7->hasAcceptableInput())
        this->account_nr  = ui->lineEdit_7->text();
        else qDebug() << "Not a valid account nr";

        if(this->name.isNull() || this->surname.isNull() || this->address.isNull() || this->id.isNull() || this->mobile.isNull() || this->mail.isNull())
            QMessageBox::warning(nullptr, "Empty values",
                             "Some values are still empty");
    }
            QSqlDatabase::database().transaction();
            try {
                if(_sender == ui->pushButton) cli_id = insertRenter(q, this->name, this->surname, this->address,
                         this->id, this->mobile, this->mail, this->account_nr);
                if(_sender == ui->pushButton_2) cli_id = selectRenterID(q, this->name, this->surname, this->address,
                                                                              this->id, this->mobile, this->mail, this->account_nr);
                QString res_id = insertReservation(q1, ui->dateEdit->date(), ui->dateEdit_2->date(), this->boxNumber, cli_id);
                updateBoxState(q2, this->boxNumber, res_id);
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

void RenterAddition::switchFilters(int index){
    qDebug() << "in switch filters";
                if(index == 0) { qDebug() << "Option 1";     model->setFilterColumn("name");
                    model->setFilterFlags(Qt::MatchContains);
                    model->select();}
                if(index == 1) { qDebug() << "Option 2";     model->setFilterColumn("surname");
                    model->setFilterFlags(Qt::MatchContains);
                    model->select();}
                if(index == 2) { qDebug() << "Option 3";     model->setFilterColumn("adress");
                    model->setFilterFlags(Qt::MatchContains);
                    model->select();}
                if(index == 3) { qDebug() << "Option 4";     model->setFilterColumn("id");
                    model->setFilterFlags(Qt::MatchContains);
                    model->select();}
                if(index == 4) { qDebug() << "Option 5";     model->setFilterColumn("mobile");
                    model->setFilterFlags(Qt::MatchContains);
                    model->select();}
                if(index == 5) { qDebug() << "Option 6";     model->setFilterColumn("mail");
                    model->setFilterFlags(Qt::MatchContains);
                    model->select();}
    }

void RenterAddition::showTableView(){
    //db data
    ui->pushButton_2->setVisible(!ui->pushButton_2->isVisible());
    ui->label_11->setVisible(!ui->label_11->isVisible());
    ui->tableView->setVisible(!ui->tableView->isVisible());
    ui->lineEdit_8->setVisible(!ui->lineEdit_8->isVisible());
    ui->comboBox->setVisible(!ui->comboBox->isVisible());

    //manual insertion

    ui->lineEdit->setVisible(!ui->lineEdit->isVisible());
    ui->lineEdit_2->setVisible(!ui->lineEdit_2->isVisible());
    ui->lineEdit_3->setVisible(!ui->lineEdit_3->isVisible());
    ui->lineEdit_4->setVisible(!ui->lineEdit_4->isVisible());
    ui->lineEdit_5->setVisible(!ui->lineEdit_5->isVisible());
    ui->lineEdit_6->setVisible(!ui->lineEdit_6->isVisible());
    ui->lineEdit_7->setVisible(!ui->lineEdit_7->isVisible());

    ui->label->setVisible(!ui->label->isVisible());
    ui->label_2->setVisible(!ui->label_2->isVisible());
    ui->label_3->setVisible(!ui->label_3->isVisible());
    ui->label_4->setVisible(!ui->label_4->isVisible());
    ui->label_5->setVisible(!ui->label_5->isVisible());
    ui->label_6->setVisible(!ui->label_6->isVisible());
    ui->label_7->setVisible(!ui->label_7->isVisible());
    ui->label_8->setVisible(!ui->label_8->isVisible());

    ui->pushButton->setVisible(!ui->pushButton->isVisible());
}

void RenterAddition::showAllHiddenTopLevelWidgets()
{
    const QWidgetList topLevelWidgets = QApplication::topLevelWidgets();
    for (QWidget *widget : topLevelWidgets) {
            widget->close();
    }

}


void RenterAddition::backToMain(){
    this->close();
}

RenterAddition::~RenterAddition()
{
    delete ui;
}
