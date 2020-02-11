#ifndef LOGINWIDOW_H
#define LOGINWIDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <db_handler.h>
#include "mainwindow.h"
#include <QVBoxLayout>

namespace Ui {
class LoginWidow;
}

class LoginWidow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWidow(QWidget *parent = nullptr);
    ~LoginWidow();
public slots:
    void connectToDB();
private:
    Ui::LoginWidow *ui;
    QString name;
    QString pass;
    MainWindow *main;
};

#endif // LOGINWIDOW_H
