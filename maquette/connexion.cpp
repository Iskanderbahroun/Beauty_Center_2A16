#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("offre");
db.setUserName("ibtihel");//inserer nom de l'utilisateur
db.setPassword("root");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
void Connexion::closeConnection(){db.close();}
