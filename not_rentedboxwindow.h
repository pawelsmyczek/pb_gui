#ifndef NOT_RENTEDBOXWINDOW_H
#define NOT_RENTEDBOXWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPushButton>
#include <QSqlDatabase>
#include <QRegularExpression>
#include "renter_addition.h"

namespace Ui {
class not_rentedboxwindow;
}

class NotRentedBoxWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NotRentedBoxWindow(QWidget *parent = nullptr);
    ~NotRentedBoxWindow();
public slots:
    void initializeBoxWindow(bool);
private slots:
    void backToMain();
    void openRenterAddition();
private:
    Ui::not_rentedboxwindow *ui;
    QString title;
    RenterAddition *new_renter;
    QString number1;
};

#endif // NOT_RENTEDBOXWINDOW_H
