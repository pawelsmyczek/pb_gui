#ifndef CLIENTSLIST_H
#define CLIENTSLIST_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <memory>
#include "db_handler.h"

namespace Ui {
class ClientsList;
}

class ClientsList : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientsList(QWidget *parent = nullptr);
    ~ClientsList();

private:
    Ui::ClientsList *ui;
    QStandardItemModel *tableViewModel;
    void resizeEvent(QResizeEvent *event);
    void setTableWidget(QStandardItemModel *, const QBrush&, const QColor&);
};

#endif // CLIENTSLIST_H
