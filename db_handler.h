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
#include <memory>


const auto SEL_BOXES = QLatin1String(R"(
                                     SELECT box_number, corridor, is_rented, active_reservation, price_per_month, size
                                     FROM "polbox_schema"."t_box"
                                     ORDER BY box_number ASC
                                     )");

const auto SEL_RES = QLatin1String(R"(
                                   SELECT reservation_id, start_rent, end_rent, "polbox_schema"."t_transactions".t_box_id, date_trans, trans_end, sum FROM "polbox_schema"."t_reservation"
                                   LEFT JOIN "polbox_schema"."t_transactions" ON "polbox_schema"."t_transactions".reservation_id = "polbox_schema"."t_reservation".id_reservation
                                   LEFT JOIN "polbox_schema"."t_box" on "polbox_schema"."t_box".active_reservation = "polbox_schema"."t_reservation".id_reservation
                                   WHERE "polbox_schema"."t_transactions".is_deposit = FALSE
                                   )");

const auto SEL_CLI = QLatin1String(R"(
                                   select name, surname, adress, id, mobile, mail, account_nr, t_box_id from "polbox_schema"."t_client_ind"
                                   left join "polbox_schema"."t_reservation" on "polbox_schema"."t_reservation".t_client_ind = "polbox_schema"."t_client_ind".id_client_ind
                                   left join "polbox_schema"."t_box" on "polbox_schema"."t_box".active_reservation = "polbox_schema"."t_reservation".id_reservation
                                   where "polbox_schema"."t_box".active_reservation is not NULL
                                   )");


void addComment(std::unique_ptr<QSqlQuery>&, QString, QString);
bool addConnection(const QString &, const QString &, const QString &,
                            const QString &, const QString &, int);
int countBoxes(std::weak_ptr<QSqlQuery>, int);
void boxReservationEnd(std::unique_ptr<QSqlQuery>&, QString, QString, QString);
bool ifPayed(std::unique_ptr<QSqlQuery>&, QString, std::vector<QString>*);
const QString insertRenter(std::unique_ptr<QSqlQuery>&, QString, QString, QString, QString, QString, QString, QString);
const QString insertReservation(std::unique_ptr<QSqlQuery>&, QDate, QDate, QString, QString);
void insertTransaction(std::unique_ptr<QSqlQuery>&, QString, QDate, QString, QString, QString, QString,
                       QDate = QDate::fromString("01011900", "dd.MM.yy"), QDate = QDate::fromString("01011900", "dd.MM.yy"));
const QString selectBoxSize(QSqlQuery*, int);
const QString selectBoxComment(std::unique_ptr<QSqlQuery>&, QString);
void listOfReservations(std::unique_ptr<QSqlQuery>&, QString, std::vector<QString>*);
void selectReservationData(std::unique_ptr<QSqlQuery>&, QString, std::vector<QString>*);
void selectRenter(std::unique_ptr<QSqlQuery>&, QString, std::vector<QString>*);
const QString selectRenterID(std::unique_ptr<QSqlQuery>&, QString, QString, QString,QString, QString, QString, QString);
void updateBoxState(std::unique_ptr<QSqlQuery>&, QString, QString);
void updateDB(std::unique_ptr<QSqlQuery>&);
#endif // DB_HANDLER_H
