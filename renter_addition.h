#ifndef RENTER_ADDITION_H
#define RENTER_ADDITION_H

#include <QMainWindow>

namespace Ui {
class renter_addition;
}

class RenterAddition : public QMainWindow
{
    Q_OBJECT

public:
    explicit RenterAddition(QWidget *parent = nullptr);
    ~RenterAddition();

private:
    Ui::renter_addition *ui;
};

#endif // RENTER_ADDITION_H
