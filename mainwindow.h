#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHoverEvent>
#include <QSignalMapper>
#include <QDebug>
#include <QMouseEvent>
#include <QWidget>
#include "boxwindow.h"
#include "not_rentedboxwindow.h"

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
    bool eventFilter(QObject*, QEvent*);
private:
    Ui::MainWindow *ui;
    BoxWindow *box_window;
    NotRentedBoxWindow *not_rentedboxwindow;
    QPushButton *p_button;
    QPushButton* buttons[10];
};
#endif // MAINWINDOW_H
