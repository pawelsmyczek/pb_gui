#include "boxeslist.h"
#include "ui_boxeslist.h"

BoxesList::BoxesList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoxesList)
{
    ui->setupUi(this);
    tableViewModel = new QStandardItemModel(ui->tableView);
    ui->tableView->setModel(tableViewModel);

    tableViewModel->setColumnCount(6);
    tableViewModel->setHorizontalHeaderLabels(
                                            // box_number, corridor, is_rented, active_reservation, price, size
                                                 {"Numer boxu",
                                                  "Numer Korytarza",
                                                  "Czy wynajety",
                                                  "Numer rezerwacji",
                                                  "Cena za miesiąc [zł/m2]",
                                                  "Rozmiar[m2]"}
                                              );
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // ustawiam tryb bez możliwości edytowania pól tabeli
    QBrush brushBackground(Qt::gray); // tworzę brush wypełnienia tła komórek

//    foreach(Country country, countries){
    setTableWidget(tableViewModel, brushBackground, Qt::white);
//    }

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // ustawiam zaznaczanie całych wierszy
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //
}

void BoxesList::setTableWidget(QStandardItemModel *countriesTableModel,
                                      const QBrush& backgroundColor, const QColor& color){
    int index = countriesTableModel->rowCount();
    countriesTableModel->setRowCount(index+1);
    std::unique_ptr<QSqlQuery> reservations (new QSqlQuery(QSqlDatabase::database("PB_CONN")));

    if(!reservations->exec(SEL_BOXES)) qDebug() << "Failed to execute query SEL_RES" << reservations->lastError().text();
    while(reservations->next()){
        qDebug() << index;
        for(int x: {0, 1, 2, 3, 4, 5}){
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

void BoxesList::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);

    QRect size = ui->centralwidget->geometry();

    ui->tableView->setGeometry(0, 0, size.width(), size.height());
}


BoxesList::~BoxesList()
{
    delete ui;
}
