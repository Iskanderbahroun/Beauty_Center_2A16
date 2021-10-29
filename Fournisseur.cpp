#include "Fournisseur.h"
#include "QSqlQuery"
#include<QDebug>
#include <QObject>
Fournisseur::Fournisseur()
{   id=0;
    numtel=0;
    nom= "";
    qualite="";
    category="";
}
Fournisseur::Fournisseur(int id ,int numtel ,QString nom, QString qualite, QString category){
    this->id=id; this->numtel=numtel; this->nom=nom; this->qualite=qualite; this->category=category;
}
int Fournisseur::getid(){return id;}
int Fournisseur::getnumtel(){return numtel;}
QString Fournisseur::getnom(){return nom;}
QString Fournisseur ::getqualite(){return  qualite;}
QString Fournisseur :: getcategory(){return category;}
void Fournisseur::setid(int id){this->id=id;}
void Fournisseur::setnumtel(int numtel){this->numtel=numtel;}
void Fournisseur::setnom(QString nom){this->nom=nom;}
void Fournisseur ::setqualite(QString qualite){this->qualite=qualite;}
void Fournisseur ::setcategory(QString category){this->category=category;}
bool Fournisseur::ajouter(){


    QSqlQuery query;
    QString numtel_string= QString::number(numtel);
    QString id_string= QString::number(id);
          query.prepare("INSERT INTO FOURNISSEUR (id, numtel, nom, qualite , category) "
                        "VALUES (:id, :numtel, :nom, :qualite, :category)");
                    query.bindValue(0, id_string);
                    query.bindValue(1, numtel_string);
                    query.bindValue(2, nom);
                    query.bindValue(3,qualite);
                    query.bindValue(4,category);
          return  query.exec();



}
QSqlQueryModel* Fournisseur::afficher(){

    QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("SELECT* FROM Fournisseur");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("numtel"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("qualite"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("category"));

    return model;
}
bool Fournisseur::supprimer(int id){
      QSqlQuery query;
      QString res=QString::number(id);
    query.prepare("Delete from Fournisseur where id=:id");
    query.bindValue(":id", res);

    return  query.exec();



}