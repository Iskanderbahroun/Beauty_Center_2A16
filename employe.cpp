#include"employe.h"
#include"connection.h"
#include<QString>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
 Employe::Employe()
 {
     Cin =0; Nom="";Prenom=""; Age=0;Role=""; Salaire=0;
 }
 Employe::Employe( int Cin,QString Nom,QString Prenom,int Age,QString Role,int Salaire)
 {

 this->Cin=Cin;
 this->Nom=Nom;
 this->Prenom=Prenom;
 this->Age=Age;
 this->Role=Role;
 this->Salaire=Salaire; }

 int Employe::getCin(){return Cin;}
 QString Employe::getNom(){return Nom;}
 QString Employe::getPrenom(){return Prenom;}
 int Employe::getAge(){return Age;}
 QString Employe::getRole(){return Role;}
 int Employe::getSalaire(){return Salaire;}

 void Employe::setCin (int Cin){this->Cin=Cin;}
 void Employe::setNom(QString Nom){this->Nom=Nom;}
 void Employe::setPrenom(QString Prenom){this->Prenom=Prenom;}
 void Employe::setAge(int Age){this->Age=Age;}
 void Employe::setRole(QString Role){this->Role=Role;}
 void Employe::setSalaire(int Salaire){this->Salaire=Salaire;}
 bool Employe::ajouter()
 {
     QSqlQuery query;
     QString Cin_string= QString::number(Cin);
     QString Age_string= QString::number(Age);
     QString Salaire_string= QString::number(Salaire);


          query.prepare("INSERT INTO EMPLOYES (Cin, Nom, Prenom, Age, Role, Salaire) "
                        "VALUES (:cin, :Nom, :Prenom, :Age, :Role, :Salaire)");
          query.bindValue(0,Cin_string);
          query.bindValue(1,Nom);
          query.bindValue(2,Prenom);
          query.bindValue(3,Age_string);
           query.bindValue(4,Role);
           query.bindValue(5,Salaire_string);
           return  query.exec();

 }
QSqlQueryModel * Employe::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel ();
     model->setQuery("SELECT * FROM employes");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Role"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));




return model;
}
 bool Employe::supprimer(int Cin)
 {
     QSqlQuery query;
     QString res=QString::number(Cin);
 query.prepare("Delete from employes where CIN=:CIN");
  query.bindValue(":CIN",res);

     return query.exec(); }

 bool Employe::modifier(int Cin,QString Nom,QString Prenom,int Age,QString Role,int Salaire){
       QSqlQuery query;
       QString Cin_string= QString::number(Cin);
       QString Age_string= QString::number(Age);
       QString Salaire_string= QString::number(Salaire);
       query.prepare(" UPDATE employes set cin=:cin ,nom=:nom,prenom=:prenom ,age=:age, role=:role , salaire=:salaire  where cin=:cin");
              query.bindValue(":cin",Cin_string);
              query.bindValue(":nom",Nom);
              query.bindValue(":prenom",Prenom);
              query.bindValue(":age",Age_string);
              query.bindValue(":role",Role);
               query.bindValue(":salaire",Salaire_string);




        return query.exec();
 }
 QSqlQueryModel* Employe::triNom()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("SELECT * FROM employes ORDER BY NOM");
            return model;
 }
 QSqlQueryModel* Employe::triAge()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("SELECT * FROM employes ORDER BY AGE");
            return model;
 }
 QSqlQueryModel* Employe::triSalaire()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("SELECT * FROM employes ORDER BY SALAIRE");
            return model;
 }

 void Employe :: rechercher(QTableView * table ,int Cin ,int Age,int Salaire )
     {
         QSqlQueryModel *model= new QSqlQueryModel();

         QSqlQuery *query=new QSqlQuery;
         QString  Cin_string  =QString::number(Cin);
         QString  Salaire_string  =QString::number(Salaire);
          QString Age_string  =QString::number(Age);

         query->prepare("select * FROM employes where CIN like '%"+Cin_string+"%' or AGE like '%"+Age_string+"%'  or SALAIRE like '%"+Salaire_string+"%'  ;");


         query->exec();
         model->setQuery(*query);
         table->setModel(model);
         table->show();

     }
