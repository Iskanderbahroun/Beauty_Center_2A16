#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("testbd");
db.setUserName("youssef");//inserer nom de l'utilisateur
db.setPassword("youssef1");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
