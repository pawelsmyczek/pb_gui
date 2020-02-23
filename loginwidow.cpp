#include "loginwidow.h"
#include "ui_loginwidow.h"

LoginWidow::LoginWidow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWidow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(connectToDB()));
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

LoginWidow::~LoginWidow()
{
    delete ui;
}

void LoginWidow::connectToDB()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    qDebug() << "Windows target";
#elif __linux__
    qDebug() << "Linux target";
#endif
    name = ui->lineEdit->text();
    pass = ui->lineEdit_2->text();
    if(addConnection("QPSQL", "some_db", "some_host", name, pass, 35942)){
        MainWindow *m = new MainWindow(this);
        //m->setLayout(layout);
        m->show();
        this->hide();
    }
    ui->lineEdit_2->setText("");

}
