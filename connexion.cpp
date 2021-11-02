#include "connexion.h"
#include "QtSql"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_sarah");
db.setUserName("sarah");//inserer nom de l'utilisateur
db.setPassword("sarah");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
