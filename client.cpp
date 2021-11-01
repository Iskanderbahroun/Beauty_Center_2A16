#include "client.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
client::client()
{
    age=0;id=0;nom="";prenom="";


}


client::client(QString nom,QString prenom,int age,int id)
{
this->nom=nom;
this->prenom=prenom;
this->age=age;
this->id=id;
}

   int client::getage(){return age ;}
  int client::getid(){return id;}
 QString client::getnom(){return nom ;}
  QString client::getprenom(){return prenom ;}



   void client:: setage(int age){this->age=age;}
    void client::setid(int id){this->id=id;}
    void client::setnom(QString nom){this->nom=nom;}
    void client::setprenom(QString prenom){this->prenom=prenom;}
    bool client::ajouter()
    {
        QSqlQuery query;
        QString id_string=QString::number(id);
         QString age_string=QString::number(age);
              query.prepare("INSERT INTO client (nom,prenom,age,id) "
                            "VALUES (:nom, :prenom,:age,:id)");
              query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
              query.bindValue(":age", age_string);
              query.bindValue(":id", id_string);


        return query.exec();

    }
bool client:: supprimer(int id)
{
    QSqlQuery query;

QString res=QString::number(id);


          query.prepare("Delete from client where id=:id ");
          query.bindValue(":id", res);

    return query.exec();






}
QSqlQueryModel* client::afficher()

{
QSqlQueryModel* model=new QSqlQueryModel();

 model->setQuery("SELECT* FROM client");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("AGE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));

    return model;
}

