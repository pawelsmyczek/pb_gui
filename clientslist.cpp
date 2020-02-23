#include "clientslist.h"
#include "ui_clientslist.h"

ClientsList::ClientsList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientsList)
{
    ui->setupUi(this);

    tableViewModel = new TableModel(ui->tableView);
    ui->tableView->setModel(tableViewModel);
    this->setWindowTitle("Lista klientów");
    tableViewModel->setColumnCount(8);
    tableViewModel->setHorizontalHeaderLabels(
                                                {"Imie",
                                               "Nazwisko",
                                               "Adres",
                                               "NIP/PESEL",
                                               "Numer tel.",
                                               "e-mail",
                                               "Numer konta",
                                               "Numer boxu"}
                                              );
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QBrush brushBackground(Qt::gray);
    tableViewModel->setTableWidget(8, brushBackground, Qt::white);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

void ClientsList::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    QRect size = ui->centralwidget->geometry();
    ui->tableView->setGeometry(0, 0, size.width(), size.height());
}


ClientsList::~ClientsList()
{
    delete ui;
    delete tableViewModel;
}
