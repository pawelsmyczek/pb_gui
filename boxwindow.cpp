#include "boxwindow.h"
#include "ui_boxwindow.h"

BoxWindow::BoxWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoxWindow)
{
    ui->setupUi(this);
    connect(ui->actionPowr_t, SIGNAL(triggered()), this, SLOT(backToMain()));
}

void BoxWindow::backToMain()
{
    this->close();
}

BoxWindow::~BoxWindow()
{
    delete ui;
}
