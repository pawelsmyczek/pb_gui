#ifndef BOXWINDOW_H
#define BOXWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPushButton>
#include "calendar.h"
#include <QRegularExpression>
#include "db_handler.h"
#include <QSqlQuery>
#include <vector>
#include <iterator>

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
private slots:
    void backToMain();
private:
    //Calendar *calendar;
    Ui::BoxWindow *ui;
    QString title;
    QString number1;
    QDate starting_date, end_date;
    std::vector<QString> reservationData;
    std::vector<QString> renterData;
};

#endif // BOXWINDOW_H
