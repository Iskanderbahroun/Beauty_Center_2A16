#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("offre");
db.setUserName("ibtihel");//inserer nom de l'utilisateur
db.setPassword("root");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
