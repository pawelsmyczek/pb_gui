#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QObject>
#include <QWidget>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QTableView>
#include <memory>
#include "db_handler.h"

/*
model for table views
*/

class TableModel: public QStandardItemModel
{
    Q_OBJECT
private:
    QTableView* tableview;
public:
    TableModel(QWidget * parent = nullptr);
    void setTableWidget(const int, const QBrush&, const QColor&);
};

#endif // TABLEMODEL_H
