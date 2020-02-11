#include "mainwindow.h"
#include "loginwidow.h"
#include <QSqlDatabase>
#include <QApplication>

int main(int argc, char *argv[])
{
    int currentExitCode = 0;
    QApplication a(argc, argv);
    do{
    if(QSqlDatabase::contains("PB_CONN"))
    {
        MainWindow *w = new MainWindow();
        w->show();
        currentExitCode = a.exec();
    }
    else
    {
        qDebug() << "no db like that";
        LoginWidow *l = new LoginWidow();
        l->show();
        currentExitCode = a.exec();
    }
    } while(currentExitCode == MainWindow::EXIT_CODE_REBOOT);

    return currentExitCode;
}
