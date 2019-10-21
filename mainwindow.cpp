#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "string"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int count = 1;
    QString name;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            p_button = new QPushButton(" ", this);
            p_button->setGeometry(QRect(QPoint((i*100)+(i*10),((j+1)*50)+(j*10)), QSize(100, 50)));
            name = "Box " + QString::number(count++);
            p_button->setText(name);
            connect(p_button, SIGNAL(released()), this, SLOT(handleButton()));
        }
    }
}

void MainWindow::handleButton()
{
    // this->close();

    QString title = p_button->text();
    BoxWindow* box_window = new BoxWindow();
    box_window->setWindowTitle(title);
    box_window->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

