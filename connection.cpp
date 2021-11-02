#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("test_bd");
db.setUserName("emna");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
