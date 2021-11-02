#include"employe.h"
#include"connection.h"
#include<QString>
#include<QSqlQuery>
#include<QtDebug>
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
                        "VALUES (:Cin, :Nom, :Prenom, :Age, :Role, :Salaire)");
          query.bindValue(0, Cin_string);
          query.bindValue(1, Nom);
          query.bindValue(2, Prenom);
          query.bindValue(3, Age_string);
           query.bindValue(4, Role);
           query.bindValue(5, Salaire_string);
           return  query.exec();

 }
