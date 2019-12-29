#include "loginwidow.h"
#include "ui_loginwidow.h"

LoginWidow::LoginWidow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWidow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(connectToDB()));
}

LoginWidow::~LoginWidow()
{
    delete ui;
}

void LoginWidow::connectToDB()
{
    name = ui->lineEdit->text();
    pass = ui->lineEdit_2->text();
    db = addConnection("QPSQL", "polbox", "localhost", name, pass, 5432);
    //QVBoxLayout *layout = new QVBoxLayout();
    MainWindow *m = new MainWindow(this);
    //m->setLayout(layout);
    m->show();
    this->hide();
}
