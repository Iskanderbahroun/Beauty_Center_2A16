#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QSqlQuery>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>
#include <QPdfWriter>
#include <QPainter>


class Employe
{
public:
    Employe();
    Employe(int,QString,QString,int,QString,int);

    int getCin () ;
    QString getNom();
    QString getPrenom();
    int getAge ();
    QString getRole();
    int getSalaire ();

    void setCin (int);
    void setNom(QString);
    void setPrenom(QString);
    void setAge(int);
    void setRole(QString);
    void setSalaire (int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier(int,QString,QString,int,QString,int);
      QSqlQueryModel * triNom();
      QSqlQueryModel * triAge();
      QSqlQueryModel * triSalaire();
       void rechercher(QTableView * tabl,int,int,int);
       void telechargerPDF();

private:
    QString Nom , Prenom , Role  ;
        int Age , Salaire ;
         int Cin ;

};

#endif // EMPLOYE_H
