#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Source_Projet2A");
db.setUserName("Iskander");//inserer nom de l'utilisateur
db.setPassword("Iskander50805029");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
