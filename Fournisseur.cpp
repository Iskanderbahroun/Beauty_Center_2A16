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
Fournisseur::Fournisseur(int id ,int numtel ,QString nom, QString qualite, QString category,QString email){
    this->id=id; this->numtel=numtel; this->nom=nom; this->qualite=qualite; this->category=category; this->email=email;
}
int Fournisseur::getid(){return id;}
int Fournisseur::getnumtel(){return numtel;}
QString Fournisseur::getnom(){return nom;}
QString Fournisseur ::getqualite(){return  qualite;}
QString Fournisseur :: getcategory(){return category;}
QString Fournisseur :: getemail(){return email;}
void Fournisseur::setid(int id){this->id=id;}
void Fournisseur::setnumtel(int numtel){this->numtel=numtel;}
void Fournisseur::setnom(QString nom){this->nom=nom;}
void Fournisseur ::setqualite(QString qualite){this->qualite=qualite;}
void Fournisseur ::setcategory(QString category){this->category=category;}
void Fournisseur :: setemail(QString email){this->email=email;}
bool Fournisseur::ajouter(){


    QSqlQuery query;
    QString numtel_string= QString::number(numtel);
    QString id_string= QString::number(id);
          query.prepare("INSERT INTO FOURNISSEUR (id, numtel, nom, qualite , category,email) "
                        "VALUES (:id, :numtel, :nom, :qualite, :category, :email)");
                    query.bindValue(0, id_string);
                    query.bindValue(1, numtel_string);
                    query.bindValue(2, nom);
                    query.bindValue(3,qualite);
                    query.bindValue(4,category);
                    query.bindValue(5,email);
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
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
    return model;
}
QSqlQueryModel* Fournisseur::afficheremail(){

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT email FROM Fournisseur ");
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
    return model;
}
bool Fournisseur::supprimer(int id){
      QSqlQuery query;
      QString res=QString::number(id);




    query.prepare("Delete from Fournisseur where id=:id");
    query.bindValue(":id", res);

    return  query.exec();



}
bool Fournisseur::modifier(int id, int numtel, QString nom, QString qualite, QString category,QString email){
    QSqlQuery query;
     QString id_string= QString::number(id);
     QString numtel_string= QString::number(numtel);
       query.prepare(" UPDATE Fournisseur set id=:id ,numtel=:numtel,nom=:nom ,qualite=:qualite, category=:category, email=:email where id=:id");
       query.bindValue(":id",id_string);
       query.bindValue(":numtel",numtel_string);
       query.bindValue(":nom",nom);
       query.bindValue(":qualite",qualite);
       query.bindValue(":category",category);
       query.bindValue(":email",email);
       return query.exec();
}
QSqlQueryModel * Fournisseur::trinom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Fournisseur ORDER BY NOM");
    /*model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("qualite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("category"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));*/


    return model;
}
QSqlQueryModel * Fournisseur::triqual()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Fournisseur ORDER BY QUALITE");
    /*model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("qualite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("category"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));*/

    return model;
}
QSqlQueryModel * Fournisseur::tricategory()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM Fournisseur ORDER BY CATEGORY");
   /* model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("qualite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("category"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));*/

    return model;
}
void Fournisseur :: recherche(QTableView * table ,QString nom, QString qualite,int id )
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QString id_string= QString::number(id);

    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from Fournisseur where NOM like '%"+nom+"%' or QUALITE like '%"+qualite+"%' or ID like '%"+id_string+"%' ;");


    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
