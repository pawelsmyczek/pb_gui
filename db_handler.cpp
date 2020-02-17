#include "db_handler.h"

void addComment(std::unique_ptr<QSqlQuery>& q, QString comment, QString box_id){
    std::string str = "UPDATE \"polbox_schema\".\"t_box\" SET comment = '" + comment.toStdString() + "' WHERE \"box_number\" = " + box_id.toStdString() + ";";
    const char* to_char = str.c_str();
    const auto ADD_COMMENT = QLatin1String(to_char);
    if(!q->exec(ADD_COMMENT)) qDebug() << "Failed to add comment " << q->lastError().text();
    q->first();
}

bool addConnection(const QString &driver, const QString &dbName, const QString &host,
                            const QString &user, const QString &passwd, int port) {
    QSqlError err;
    QSqlDatabase db = QSqlDatabase::addDatabase(driver, "PB_CONN");
    db.setDatabaseName(dbName);
    db.setHostName(host);
    db.setPort(port);
    db.open();
    if (!db.open(user, passwd)) {
        err = db.lastError();
        QMessageBox::warning(nullptr, "Unable to open database",
                             "An error occured while connecting to db: "+err.text());
        qDebug() << "Could not open connection: " << err.text();
        return false;
    }
    return true;
}

//zakonczenie rezerwacji skutkujace zmiana stanu boxa oraz zmiana konca rezerwacji boxa na current date
void boxReservationEnd(std::unique_ptr<QSqlQuery>& q, QString client_id, QString box_id, QString reservation_id) {
    std::string str = "UPDATE \"polbox_schema\".\"t_box\" SET is_rented = FALSE, active_reservation = NULL WHERE \"box_number\" = " + box_id.toStdString() + ";"
                      "UPDATE \"polbox_schema\".\"t_reservation\" SET end_rent = current_date "
                        "WHERE \"t_box_id\" = " + box_id.toStdString() + " AND \"t_client_ind\" = "+ client_id.toStdString() + " AND \"id_reservation\" = " + reservation_id.toStdString() +";";
    const char* to_char = str.c_str();
    const auto END_RESERVATION = QLatin1String(to_char);
    if(!q->exec(END_RESERVATION)) qDebug() << "Failed to end reservation " << q->lastError().text();
    q->first();

}

int countBoxes(std::weak_ptr<QSqlQuery> q, int number) {
    std::string str = "SELECT COUNT(*) FROM \"polbox_schema\".\"t_box\" WHERE \"corridor\" = " + std::to_string(number);
    const char* to_char = str.c_str();
    const auto COUNT_BOXES_BY_CORR = QLatin1String(to_char);
    if(q.expired()){
        qDebug() << "Resource expired";
        return -1;
    }
    else{
        auto locked = q.lock();
        if(!locked->exec(COUNT_BOXES_BY_CORR)) qDebug() << "Failed to count boxes " << locked->lastError().text();
        locked->first();
        return locked->value(0).toInt();
    }
}



const QString selectBoxSize(QSqlQuery* q, int boxNumber) {
    std::string str = "SELECT \"size\" FROM \"polbox_schema\".\"t_box\" WHERE \"box_number\" = " + std::to_string(boxNumber);
    const char* to_char = str.c_str();
    const auto GET_BOX_SIZE = QLatin1String(to_char);
    if(!q->exec(GET_BOX_SIZE)) qDebug() << "Failed to select box size " << q->lastError().text();
    q->first();
    return q->value(0).toString();
}

void updateBoxState(std::unique_ptr<QSqlQuery>& q, QString boxNumber, QString active_reservation) {
    std::string str = "UPDATE \"polbox_schema\".\"t_box\" SET is_rented=True, active_reservation = " + active_reservation.toStdString() + " where box_number =" + boxNumber.toStdString();
    // str.erase(std::remove(str.begin(), str.end(), "\\"), str.end());
    const char* to_char = str.c_str();
    const auto GET_BOX_SIZE = QLatin1String(to_char);
    if(!q->exec(GET_BOX_SIZE)) qDebug() << "Failed to update box state" << q->lastError().text();
    q->first();
}

const QString insertRenter(std::unique_ptr<QSqlQuery>& q, QString name, QString surname, QString adress,
                  QString id, QString mobile, QString mail, QString account_nr) {
    std::string str = "INSERT INTO \"polbox_schema\".\"t_client_ind\" (name,surname,adress,id,mobile,mail,account_nr)"
                      "VALUES ('" + name.toStdString() + "', '" + surname.toStdString() + "', '"
            + adress.toStdString() + "', " + id.toStdString() + ", '" + mobile.toStdString() + "', '"
            + mail.toStdString() + "', '" + account_nr.toStdString() + "') RETURNING id_client_ind";
    //str.erase(std::remove(str.begin(), str.end(), "\\"), str.end());
    const char* to_char = str.c_str();
    const auto INSERT_RENTER = QLatin1String(to_char);
    if(!q->exec(INSERT_RENTER)) qDebug() << "Failed to add renter" << q->lastError().text() ;
    q->first();
    return q->value(0).toString();
}

QString insertReservation(std::unique_ptr<QSqlQuery>& q, QDate start, QDate end, QString box_id, QString client_id) {
    std::string str = "INSERT INTO \"polbox_schema\".\"t_reservation\" (start_rent,end_rent,t_box_id, t_client_ind)"
                      "VALUES ( date'" + start.toString("dd.MM.yy").toStdString() + "', date'" + end.toString("dd.MM.yy").toStdString()  + "', "+ box_id.toStdString() +", "+ client_id.toStdString() +")"
                      "RETURNING id_reservation";
    //str.erase(std::remove(str.begin(), str.end(), "\\"), str.end());
    const char* to_char = str.c_str();
    const auto INSERT_RESERVATION = QLatin1String(to_char);
    if(!q->exec(INSERT_RESERVATION)) qDebug() << "Failed to add reservation" << q->lastError().text();
    q->first();
    return q->value(0).toString();
}

void insertTransaction(std::unique_ptr<QSqlQuery>& q, QString sum, QDate trans_date, QString client_id, QString box_id, QString reservation_id, QString is_deposit, QDate period_start, QDate period_end){
    std::string str;
    if(period_start == QDate::fromString("01011900", "dd.MM.yy") || period_end == QDate::fromString("01011900", "dd.MM.yy") ){
        std::string str = "INSERT INTO \"polbox_schema\".\"t_transactions\" (sum,date_trans, t_client_ind_id, t_box_id, reservation_id, is_deposit)"
                          "VALUES ( " + sum.toStdString() + ", " + "date'" + trans_date.toString("dd.MM.yy").toStdString() + "', "+ client_id.toStdString() + ", " + box_id.toStdString() + ", " +
                reservation_id.toStdString() + ",  " + is_deposit.toStdString() + ")";
        const char* to_char = str.c_str();
        const auto INSERT_TRANSACTION = QLatin1String(to_char);
        if(!q->exec(INSERT_TRANSACTION)) qDebug() << "Failed to add transaction" << q->lastError().text();
        q->first();
    } else {
        std::string str = "INSERT INTO \"polbox_schema\".\"t_transactions\" (sum,date_trans, t_client_ind_id, t_box_id, reservation_id, is_deposit, trans_start, trans_end)"
                          "VALUES ( " + sum.toStdString() + ", " + "date'" + trans_date.toString("dd.MM.yy").toStdString() + "', "+ client_id.toStdString() + ", " + box_id.toStdString() + ", " +
                reservation_id.toStdString() + ", " + is_deposit.toStdString() + ", date'" + period_start.toString("dd.MM.yy").toStdString() + "', " + "date'" + period_end.toString("dd.MM.yy").toStdString() + "')";
        const char* to_char = str.c_str();
        const auto INSERT_TRANSACTION = QLatin1String(to_char);
        if(!q->exec(INSERT_TRANSACTION)) qDebug() << "Failed to add transaction" << q->lastError().text();
        q->first();
    }

}

bool ifPayed(std::unique_ptr<QSqlQuery>& q, QString reservation_id, std::vector<QString>* payment_container){
    bool payed = false;
    std::string str = "SELECT is_deposit, trans_start, trans_end FROM \"polbox_schema\".\"t_transactions\""
                      "WHERE reservation_id = " + reservation_id.toStdString() + ";";
    const char* to_char = str.c_str();
    const auto IS_PAYED = QLatin1String(to_char);
    if(!q->exec(IS_PAYED)) qDebug() << "Failed to check box payment" << q->lastError().text();
    q->first();
    if(q->size() != 0){
        do{
            if(q->value(0).toString() != ""){
                qDebug() << q->value(0).toString();
                payment_container->push_back(q->value(0).toString());
                if(q->value(0).toString() == "false") payed = true; // XDDD because there is a record in transactions that contains a value of "is_deposit" set to false,
                                                                    // meaning that there is a payment for that specific reservation
                if(q->value(2).toString() != ""){
                    qDebug() << q->value(2).toString();
                    payment_container->push_back(q->value(2).toString());
                }
            }
        }while(q->next());
    }
    return payed;
}

const QString selectBoxComment(std::unique_ptr<QSqlQuery>& q, QString boxNumber){
    std::string str = "SELECT comment FROM \"polbox_schema\".\"t_box\" "
                      "WHERE box_number = " + boxNumber.toStdString();
    //str.erase(std::remove(str.begin(), str.end(), "\\"), str.end());
    const char* to_char = str.c_str();
    const auto SELECT_RESERVATION = QLatin1String(to_char);
    if(!q->exec(SELECT_RESERVATION)) qDebug() << "Failed to sel comment" << q->lastError().text();
    q->first();
    if(q->size() != 0)
        return q->value(0).toString();
    else return "";
}



void selectReservationData(std::unique_ptr<QSqlQuery>& q, QString boxNumber, std::vector<QString>* iterator) {
    std::string str = "SELECT start_rent, end_rent, t_client_ind, id_reservation FROM \"polbox_schema\".\"t_reservation\" "
                      "WHERE t_box_id = " + boxNumber.toStdString();
    //str.erase(std::remove(str.begin(), str.end(), "\\"), str.end());
    const char* to_char = str.c_str();
    const auto SELECT_RESERVATION = QLatin1String(to_char);
    if(!q->exec(SELECT_RESERVATION)) qDebug() << "Failed to sel reservation" << q->lastError().text();
    q->first();
    iterator->push_back(q->value(0).toString());
    iterator->push_back(q->value(1).toString());
    iterator->push_back(q->value(2).toString());
    iterator->push_back(q->value(3).toString());
}

void selectRenter(std::unique_ptr<QSqlQuery>& q, QString cliNumber, std::vector<QString>* iterator) {
    std::string str = "SELECT name, surname, mobile, mail FROM \"polbox_schema\".\"t_client_ind\" "
                      "WHERE id_client_ind = " +cliNumber.toStdString();
    //str.erase(std::remove(str.begin(), str.end(), "\\"), str.end());
    const char* to_char = str.c_str();
    const auto SELECT_RENTER = QLatin1String(to_char);
    if(!q->exec(SELECT_RENTER)) qDebug() << "Failed to sel renter" << q->lastError().text();
    q->first();
    iterator->push_back(q->value(0).toString());
    iterator->push_back(q->value(1).toString());
}

void updateDB(std::unique_ptr<QSqlQuery>& q){
    std::string str = "select * from \"polbox_schema\".update_boxes();";
    const char* to_char = str.c_str();
    const auto UPDATE_STATES = QLatin1String(to_char);
    if(!q->exec(UPDATE_STATES)) qDebug() << "Failed to end reservation " << q->lastError().text();
    q->first();
}
