#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include<QSqlQueryModel>
#include<QTableView>
class Fournisseur{
public:
    Fournisseur();
    Fournisseur(int,int,QString,QString,QString,QString);
    int getid();
    int getnumtel();
    QString getnom();
    QString getqualite();
    QString getcategory();
    QString getemail();
    void setid(int);
    void setnumtel(int);
    void setnom(QString);
    void setqualite(QString);
    void setcategory(QString);
    void setemail(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficheremail();
    bool supprimer(int);
    bool modifier(int,int,QString,QString,QString,QString);
    QSqlQueryModel* trinom();
    QSqlQueryModel* triqual();
    QSqlQueryModel* tricategory();
    void recherche(QTableView * tabl, QString,QString,int);


private:
    QString nom,qualite,category,email;

    int id, numtel;

};

#endif // FOURNISSEUR_H
