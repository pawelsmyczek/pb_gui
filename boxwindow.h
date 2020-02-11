#ifndef BOXWINDOW_H
#define BOXWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPushButton>
#include <QRegularExpression>
#include "calendar.h"
#include "db_handler.h"
#include "invoicegen.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <vector>

namespace Ui {
class BoxWindow;
}

class BoxWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoxWindow(QWidget *parent = nullptr);
    ~BoxWindow();
    void paintCalendar(Calendar&);
public slots:
    void initializeBoxWindow(bool);
    void generateInvoice();
protected:
    void changeStateOfUi();
private slots:
    void backToMain();
    void editMode();
    void addPayment();
    void depositPayment();
    void approveChanges();
private:
    //Calendar *calendar;
    Ui::BoxWindow *ui;
    QString title;

    QString number1, amount;
    QDate starting_date, end_date, trans_date, trans_start, trans_end;
    std::vector<QString> reservationData;
    std::vector<QString> renterData;
};

#endif // BOXWINDOW_H
