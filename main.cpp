#include "mainwindow.h"
#include "loginwidow.h"
#include <QSqlDatabase>
#include <QApplication>

int main(int argc, char *argv[])
{
    int currentExitCode = 0;
    do{
    QApplication a(argc, argv);
    if(QSqlDatabase::contains("PB_CONN"))
    {
        MainWindow *w = new MainWindow();
        w->show();
        currentExitCode = a.exec();
    }
    else
    {
        LoginWidow *l = new LoginWidow();
        l->show();
        currentExitCode = a.exec();
        qDebug() << "no db like that";
    }
    } while(currentExitCode == MainWindow::EXIT_CODE_REBOOT);

    return currentExitCode;
}
