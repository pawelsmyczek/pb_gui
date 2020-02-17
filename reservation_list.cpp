#include "reservation_list.h"
#include "ui_reservation_list.h"

reservation_list::reservation_list(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::reservation_list)
{
    ui->setupUi(this);
    tableViewModel = new QStandardItemModel(ui->tableView);
    ui->tableView->setModel(tableViewModel);

    tableViewModel->setColumnCount(7);
    tableViewModel->setHorizontalHeaderLabels(
                                                {"Nr rezerwacji",
                                                 "Początek rezerwacji",
                                                 "Koniec rezerwacji",
                                                 "Nr boxu",
                                                 "Data platnosci za box",
                                                 "Data waznosci platnosci",
                                                 "Kwota"}
                                              );
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // ustawiam tryb bez możliwości edytowania pól tabeli
    QBrush brushBackground(Qt::blue); // tworzę brush wypełnienia tła komórek

//    foreach(Country country, countries){
    setTableWidget(tableViewModel, brushBackground, Qt::white);
//    }

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // ustawiam zaznaczanie całych wierszy
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //
}


void reservation_list::setTableWidget(QStandardItemModel *countriesTableModel,
                                      const QBrush& backgroundColor, const QColor& color){
    int index = countriesTableModel->rowCount();
    countriesTableModel->setRowCount(index+1);
    std::unique_ptr<QSqlQuery> reservations (new QSqlQuery(QSqlDatabase::database("PB_CONN")));

    if(!reservations->exec(SEL_RES)) qDebug() << "Failed to execute query SEL_RES" << reservations->lastError().text();
    while(reservations->next()){
        qDebug() << index;
        for(int x: {0, 1, 2, 3, 4, 5, 6}){
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

void reservation_list::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);

    QRect size = ui->centralwidget->geometry();

    ui->tableView->setGeometry(0, 0, size.width(), size.height());
}

reservation_list::~reservation_list()
{
    delete ui;
}
