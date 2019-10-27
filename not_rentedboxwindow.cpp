#include "not_rentedboxwindow.h"
#include "ui_not_rentedboxwindow.h"

NotRentedBoxWindow::NotRentedBoxWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::not_rentedboxwindow)
{
    ui->setupUi(this);
    connect(ui->actionPowr_t, SIGNAL(triggered()), this, SLOT(backToMain()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(openRenterAddition()));
}

NotRentedBoxWindow::~NotRentedBoxWindow()
{
    delete ui;
}


void NotRentedBoxWindow::changeTitle(bool checked)
{
    // this->close();
    auto button = qobject_cast<QPushButton *>(sender());
    Q_ASSERT(button);
    qDebug() << button->text();
    title = button->text();
    NotRentedBoxWindow* box_window = new NotRentedBoxWindow();

    box_window->setWindowTitle(title);
    box_window->show();
}

void NotRentedBoxWindow::openRenterAddition()
{
    new_renter = new RenterAddition();
    new_renter->show();
}

void NotRentedBoxWindow::backToMain()
{
    this->close();
}
