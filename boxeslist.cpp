#include "boxeslist.h"
#include "ui_boxeslist.h"

BoxesList::BoxesList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoxesList)
{
    ui->setupUi(this);
    tableViewModel = new TableModel(ui->tableView);
    ui->tableView->setModel(tableViewModel);
    this->setWindowTitle("Lista boxów");
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
    tableViewModel->setTableWidget(6, brushBackground, Qt::white);
//    }

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // ustawiam zaznaczanie całych wierszy
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //
}


void BoxesList::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);

    QRect size = ui->centralwidget->geometry();

    ui->tableView->setGeometry(0, 0, size.width(), size.height());
}


BoxesList::~BoxesList()
{
    delete ui;
    delete tableViewModel;
}
