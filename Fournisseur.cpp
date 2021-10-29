#include "Fournisseur.h"
#include "QSqlQuery"
#include<QDebug>
#include <QObject>
Fournisseur::Fournisseur()
{   id=0;
    numtel=0;
    nom= "";
}
Fournisseur::Fournisseur(int id ,int numtel ,QString nom){
    this->id=id; this->numtel=numtel; this->nom=nom;
}
int Fournisseur::getid(){return id;}
int Fournisseur::getnumtel(){return numtel;}
QString Fournisseur::getnom(){return nom;}
void Fournisseur::setid(int id){this->id=id;}
void Fournisseur::setnumtel(int numtel){this->numtel=numtel;}
void Fournisseur::setnom(QString nom){this->nom=nom;}
bool Fournisseur::ajouter(){


    QSqlQuery query;
    QString numtel_string= QString::number(numtel);
    QString id_string= QString::number(id);
          query.prepare("INSERT INTO FOURNISSEUR (id, numtel, nom) "
                        "VALUES (:id, :numtel, :nom)");
                    query.bindValue(0, id_string);
                    query.bindValue(1, numtel_string);
                    query.bindValue(2, nom);
          return  query.exec();



}
QSqlQueryModel* Fournisseur::afficher(){

    QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("SELECT* FROM Fournisseur");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("numtel"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));

    return model;
}
bool Fournisseur::supprimer(int id){
      QSqlQuery query;
      QString res=QString::number(id);
    query.prepare("Delete from Fournisseur where id=:id");
    query.bindValue(":id", res);

    return  query.exec();



}
