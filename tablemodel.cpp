#include "tablemodel.h"

TableModel::TableModel(QWidget* view): QStandardItemModel(view)
{
}

void TableModel::setTableWidget(const int numberOfRows, const QBrush& backgroundColor, const QColor& color){
    int index = this->rowCount();
    this->setRowCount(index);
    std::unique_ptr<QSqlQuery> reservations (new QSqlQuery(QSqlDatabase::database("PB_CONN")));
    QList<QStandardItem*> itemsInRowList;
    if(!reservations->exec(SEL_RES)) qDebug() << "Failed to execute query SEL_RES" << reservations->lastError().text();
    while(reservations->next()){
        qDebug() << index;
        for(int x = 0; x < numberOfRows; x++){
            std::unique_ptr<QStandardItem> reservationItem (new QStandardItem(reservations->value(x).toString()));
            reservationItem->setData(QVariant::fromValue(backgroundColor), Qt::BackgroundRole); // ustawiam mu wypełnienie
            reservationItem->setData(QVariant::fromValue(color), Qt::ForegroundRole); // ustawiam kolor tekstu
            itemsInRowList.append(reservationItem.get());
            //reservationTableModel->setItem(index, x, reservationItem);
            qDebug() << reservations->value(x).toString();
            reservationItem.release();
        }
        this->insertRow(index,itemsInRowList);
        itemsInRowList.clear();
        //reservationTableModel->setRowCount(index+1);
        index++;
    }
}
