#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("Iskander");//inserer nom de l'utilisateur
db.setPassword("Iskander50805029");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
