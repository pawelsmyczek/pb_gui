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
#include <memory>

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
    void setPaymentState();
public slots:
    void initializeBoxWindow(bool);
protected:
    void changeStateOfUi();
private slots:
    void backToMain();
    void editMode();
    void editPayment();
    void depositPayment();
    void approveTransaction();
    void approveComment();
    void generateInvoice();
    void endReservation();
    void editComment();
private:
    //Calendar *calendar;
    Ui::BoxWindow *ui;
    QString title;
    bool is_payed;
    QString number1, amount, comment;
    QDate starting_date, end_date, trans_date, trans_start, trans_end;
    std::vector<QString> reservationData;
    std::vector<QString> renterData;
    std::vector<QString> payment_data;
};

#endif // BOXWINDOW_H
