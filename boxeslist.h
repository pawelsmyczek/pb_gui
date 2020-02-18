#ifndef BOXESLIST_H
#define BOXESLIST_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <memory>
#include "db_handler.h"

namespace Ui {
class BoxesList;
}

class BoxesList : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoxesList(QWidget *parent = nullptr);
    ~BoxesList();

private:
    Ui::BoxesList *ui;
    QStandardItemModel *tableViewModel;
    void resizeEvent(QResizeEvent *event);
    void setTableWidget(QStandardItemModel *, const QBrush&, const QColor&);
};

#endif // BOXESLIST_H
