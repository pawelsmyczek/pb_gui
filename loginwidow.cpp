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
    name = ui->lineEdit->text();
    pass = ui->lineEdit_2->text();
    if(addConnection("QPSQL", "polbox", "localhost", name, pass, 5432)){
        MainWindow *m = new MainWindow(this);
        //m->setLayout(layout);
        m->show();
        this->hide();
    }
    ui->lineEdit_2->setText("");
    //QVBoxLayout *layout = new QVBoxLayout();

}
