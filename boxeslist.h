#ifndef BOXESLIST_H
#define BOXESLIST_H

#include <QMainWindow>
#include <tablemodel.h>

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
    TableModel *tableViewModel;
    void resizeEvent(QResizeEvent *event);
};

#endif // BOXESLIST_H
