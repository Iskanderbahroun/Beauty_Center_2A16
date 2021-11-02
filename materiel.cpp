#include "materiel.h"
#include "QSqlQueryModel"
#include<QDebug>
#include <QObject>
#include<QSqlQuery>

Materiel::Materiel()
{
reference=0; nom=" "; couleur=" ";
}
Materiel::Materiel( QString nom ,QString couleur,int reference)
{
this ->reference=reference;
this->nom=nom;
this->couleur=couleur;
}
int Materiel:: getreference(){return reference;}
QString Materiel:: getnom(){return nom;}
QString Materiel:: getcouleur(){return couleur;}
void Materiel:: setreference(int reference){this->reference=reference;}
void Materiel:: setprenom(QString nom){this->nom=nom;}
void Materiel :: setcouleur(QString couleur){this->couleur=couleur;}
 bool Materiel::ajouter()
 {



     QSqlQuery query;
     QString id_string=QString::number(reference);
     query.prepare("INSERT INTO Materiel (nom, couleur, reference) "
                   "VALUES (:nom, :couleur, :reference)");
      query.bindValue(":nom",nom);
      query.bindValue(":couleur",couleur);
     query.bindValue(":reference",reference );
     return query.exec();




}
 QSqlQueryModel* Materiel::afficher()
 {
     QSqlQueryModel* model=new QSqlQueryModel();

           model->setQuery("SELECT*  FROM Materiel");
           model->setHeaderData(0, Qt::Horizontal,QObject::tr("nom "));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("couleur"));
           model->setHeaderData(1, Qt::Horizontal,QObject::tr("reference "));


     return model;
 }
 bool Materiel::supprimer(int reference)
 {
     QSqlQuery query;
     QString res=QString::number(reference);

     query.prepare("Delete from MATERIEL where REFERENCE=REFERENCE ");
     query.bindValue(":REFERENCE",res);
     return query.exec();


 }


 bool Materiel::modifier(QString nom,QString couleur ,int refrence,int mat_modif)
 {
     QSqlQuery query;
     query.prepare("update system.materiel set nom=:nom,couleur=:couleur,reference=:reference where matricule=:mat_modif");
     query.bindValue(":nom",nom);
     query.bindValue(":couleur",couleur);
     query.bindValue(":reference",reference);
     query.bindValue(":mat_modif",mat_modif);
     return query.exec();

 }
  bool modifier(QString mat,QString comp,QString model,QString mat_modif);

