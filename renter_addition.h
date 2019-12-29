#ifndef RENTER_ADDITION_H
#define RENTER_ADDITION_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <db_handler.h>

namespace Ui {
class renter_addition;
}

class RenterAddition : public QMainWindow
{
    Q_OBJECT

public:
    explicit RenterAddition(QWidget *parent = nullptr);
    QString boxNumber;
    ~RenterAddition();
public slots:
    void addRenter();


private:
    Ui::renter_addition *ui;
    QRegularExpressionMatch match;
    QMessageBox message;
    QString name, surname, id, address, mobile, mail, account_nr;
    void showAllHiddenTopLevelWidgets();
};

#endif // RENTER_ADDITION_H
