#ifndef DB_HANDLER_H
#define DB_HANDLER_H
#include <QSqlError>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QSqlQuery>
#include <QDate>
#include <string>
#include <algorithm>
#include <vector>

bool addConnection(const QString &, const QString &, const QString &,
                            const QString &, const QString &, int);

const auto SEL_BOXES = QLatin1String(R"(
                                     SELECT box_number, corridor, is_rented
                                     FROM "polbox_schema"."t_box"
                                     ORDER BY box_number ASC)"
                                     );



int countBoxes(QSqlQuery*, int);
void updateBoxState(QSqlQuery*, QString);
const QString insertRenter(QSqlQuery*, QString, QString, QString, QString, QString, QString, QString);
void insertReservation(QSqlQuery*, QDate, QDate, QString, QString);
void insertTransaction(QSqlQuery*, QString, QDate, QString, QString, QString, QString, QDate = QDate::fromString("01011900", "dd.MM.yy"), QDate = QDate::fromString("01011900", "dd.MM.yy"));
const QString selectBoxSize(QSqlQuery*, int);
void selectReservation(QSqlQuery*, QString, std::vector<QString>*);
void selectRenter(QSqlQuery*, QString, std::vector<QString>*);
#endif // DB_HANDLER_H
