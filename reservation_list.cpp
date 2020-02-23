#include "reservation_list.h"
#include "ui_reservation_list.h"

reservation_list::reservation_list(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::reservation_list)
{
    ui->setupUi(this);
    tableViewModel = new TableModel(ui->tableView);
    ui->tableView->setModel(tableViewModel);
    this->setWindowTitle("Lista rezerwacji");
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
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QBrush brushBackground(Qt::gray);

    tableViewModel->setTableWidget(7, brushBackground, Qt::white);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

void reservation_list::initializeActivereservations(){

}



void reservation_list::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);

    QRect size = ui->centralwidget->geometry();

    ui->tableView->setGeometry(0, 0, size.width(), size.height());
}

reservation_list::~reservation_list()
{
    delete ui;
    delete tableViewModel;
}
