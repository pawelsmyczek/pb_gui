#ifndef RESERVATION_LIST_H
#define RESERVATION_LIST_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <memory>
#include "db_handler.h"

namespace Ui {
class reservation_list;
}

class reservation_list : public QMainWindow
{
    Q_OBJECT
public:
    explicit reservation_list(QWidget *parent = nullptr);
    ~reservation_list();

private:
    Ui::reservation_list *ui;
    QStandardItemModel *tableViewModel;
    void resizeEvent(QResizeEvent *event);
    void setTableWidget(QStandardItemModel *, const QBrush&, const QColor&);
};

#endif // RESERVATION_LIST_H
