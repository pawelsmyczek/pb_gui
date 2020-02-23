#ifndef CLIENTSLIST_H
#define CLIENTSLIST_H

#include <QMainWindow>
#include <tablemodel.h>

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
    TableModel *tableViewModel;
    void resizeEvent(QResizeEvent *event);
};

#endif // CLIENTSLIST_H
