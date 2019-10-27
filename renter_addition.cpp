#include "renter_addition.h"
#include "ui_renter_addition.h"

RenterAddition::RenterAddition(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::renter_addition)
{
    ui->setupUi(this);
}

RenterAddition::~RenterAddition()
{
    delete ui;
}
