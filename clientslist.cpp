#include "clientslist.h"
#include "ui_clientslist.h"

ClientsList::ClientsList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientsList)
{
    ui->setupUi(this);
    tableViewModel = new QStandardItemModel(ui->tableView);
    ui->tableView->setModel(tableViewModel);

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
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // ustawiam tryb bez możliwości edytowania pól tabeli
    QBrush brushBackground(Qt::gray); // tworzę brush wypełnienia tła komórek

//    foreach(Country country, countries){
    setTableWidget(tableViewModel, brushBackground, Qt::white);
//    }

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // ustawiam zaznaczanie całych wierszy
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //
}


void ClientsList::setTableWidget(QStandardItemModel *countriesTableModel,
                                      const QBrush& backgroundColor, const QColor& color){
    int index = countriesTableModel->rowCount();
    countriesTableModel->setRowCount(index+1);
    std::unique_ptr<QSqlQuery> reservations (new QSqlQuery(QSqlDatabase::database("PB_CONN")));

    if(!reservations->exec(SEL_CLI)) qDebug() << "Failed to execute query SEL_RES" << reservations->lastError().text();
    while(reservations->next()){
        qDebug() << index;
        for(int x: {0, 1, 2, 3, 4, 5, 6, 7}){
            QStandardItem *itemCountry = new QStandardItem(reservations->value(x).toString());
            itemCountry->setData(QVariant::fromValue(backgroundColor), Qt::BackgroundRole); // ustawiam mu wypełnienie
            itemCountry->setData(QVariant::fromValue(color), Qt::ForegroundRole); // ustawiam kolor tekstu
            countriesTableModel->setItem(index, x, itemCountry);
            qDebug() << reservations->value(x).toString();
        }
        countriesTableModel->setRowCount(index+1);
        index++;
    }
}

void ClientsList::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);

    QRect size = ui->centralwidget->geometry();

    ui->tableView->setGeometry(0, 0, size.width(), size.height());
}


ClientsList::~ClientsList()
{
    delete ui;
}
