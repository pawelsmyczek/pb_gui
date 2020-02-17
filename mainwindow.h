#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHoverEvent>
#include <QSignalMapper>
#include <QDebug>
#include <QMouseEvent>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <vector>
#include <memory>
#include "reservation_list.h"
#include "clientslist.h"
#include "boxwindow.h"
#include "not_rentedboxwindow.h"
#include "db_handler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;
             }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mouseMoveEvent(QMouseEvent*);
//    bool eventFilter(QObject*, QEvent*);
    void connectButton(bool, bool, QPushButton*);
//protected:
    static const int EXIT_CODE_REBOOT;
    void populate_boxes();
    
private slots:
    void logoutFromDB();
    void showActiveReservations();
    void showActiveClients();
private:
    Ui::MainWindow *ui;
    BoxWindow *box_window;
    NotRentedBoxWindow *not_rentedboxwindow;
    reservation_list* reservations;
    ClientsList* clients;
    // QSqlDatabase db;
    QPushButton *p_button;
    std::vector<QPushButton*> buttons;
    std::vector<QString> payment_data;
};
#endif // MAINWINDOW_H
