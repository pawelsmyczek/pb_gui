#ifndef RESERVATION_LIST_H
#define RESERVATION_LIST_H

#include <QMainWindow>
#include <QTableView>
#include <memory>
#include <tablemodel.h>

namespace Ui {
class reservation_list;
}

class reservation_list : public QMainWindow
{
    Q_OBJECT
public:
    explicit reservation_list(QWidget *parent = nullptr);
    ~reservation_list();
public slots:
    void initializeActivereservations();
private:
    Ui::reservation_list *ui;
    TableModel *tableViewModel;
    void resizeEvent(QResizeEvent *event);
};

#endif // RESERVATION_LIST_H
