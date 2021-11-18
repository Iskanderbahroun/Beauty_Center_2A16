#include "materiel.h"
#include "QSqlQueryModel"
#include<QDebug>
#include <QObject>
#include<QSqlQuery>

Materiel::Materiel()
{
reference=0; nom=" "; couleur=" ";
}
Materiel::Materiel( QString nom ,QString couleur,int reference ,int id_reference)
{
this ->reference=reference;
this->nom=nom;
this->couleur=couleur;
this->id_fourniseur=id_reference;
}
int Materiel:: getreference(){return reference;}
int Materiel:: getidfourniseur(){return id_fourniseur;}
QString Materiel:: getnom(){return nom;}
QString Materiel:: getcouleur(){return couleur;}
void Materiel:: setreference(int reference){this->reference=reference;}
void Materiel:: setprenom(QString nom){this->nom=nom;}
void Materiel :: setcouleur(QString couleur){this->couleur=couleur;}
 bool Materiel::ajouter()
 {



     QSqlQuery query;
     QString id_string=QString::number(reference);
     QString id_string1=QString::number(id_fourniseur);
     query.prepare("INSERT INTO Materiel (nom, couleur, reference ,ID_FOURNISEUR) "
                   "VALUES (:nom, :couleur, :reference, :ID_FOURNISEUR)");
      query.bindValue(0,nom);
      query.bindValue(1,couleur);
     query.bindValue(2,id_string );
     query.bindValue(3,id_string1 );
     return query.exec();




}
 QSqlQueryModel* Materiel::afficher()
 {
     QSqlQueryModel* model=new QSqlQueryModel();

           model->setQuery("SELECT*  FROM Materiel");
           model->setHeaderData(0, Qt::Horizontal,QObject::tr("nom "));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("couleur"));
           model->setHeaderData(2, Qt::Horizontal,QObject::tr("reference "));
           model->setHeaderData(3, Qt::Horizontal,QObject::tr("id_fourniseur "));

     return model;
 }
 bool Materiel::supprimer(QString Nom)
 {
     QSqlQuery query;


     query.prepare("Delete from MATERIEL where Nom=:Nom");
     query.bindValue(":Nom",Nom);
     return query.exec();


 }


 bool Materiel::modifier(int reference, int id_fourniseur,  QString nom,QString couleur )
 {
     QSqlQuery query;
     QString id_string=QString::number(reference);
     QString id_string1=QString::number(id_fourniseur);
     query.prepare("update materiel set nom=:nom,couleur=:couleur,reference=:reference , id_fourniseur=id_fourniseur where reference=:reference");
     query.bindValue(":nom",nom);
     query.bindValue(":couleur",couleur);
     query.bindValue(":reference",reference);
      query.bindValue(":id_fourniseur",id_fourniseur);
     return query.exec();

 }
 QSqlQueryModel * Materiel::tri()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM Materiel ORDER BY Reference");
         return model;
 }

 QSqlQueryModel * Materiel::tri1()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM Materiel ORDER BY NOM");
         return model;
 }
 QSqlQueryModel * Materiel::tri2()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM Materiel ORDER BY couleur");
         return model;
 }
 void Materiel::recherche(QTableView * table,QString nom, QString couleur,int reference )
 {
     QSqlQueryModel *model= new QSqlQueryModel();
       QString id_string=QString::number(reference);
        QList<Materiel> list;
        int somme = 0;

     QSqlQuery *query=new QSqlQuery;
     query->prepare("SELECT * from Materiel where NOM like '%"+nom+"%' or couleur like '%"+couleur+"%' or Reference like '%"+id_string+"%' ;");


     query->exec();
     model->setQuery(*query);
     table->setModel(model);
     table->show();

}

 int Materiel::calculer_stock(QString nom){
      QSqlQueryModel *model= new QSqlQueryModel();
      Materiel *M();

      QSqlQuery *query=new QSqlQuery;
      query->prepare("SELECT nom from Materiel where NOM like '%"+nom+"%';");

      query->exec();
      model->setQuery(*query);

      int somme = model->rowCount();
      return somme;
 }

