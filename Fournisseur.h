#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include<QSqlQueryModel>
class Fournisseur{
public:
    Fournisseur();
    Fournisseur(int,int,QString,QString,QString);
    int getid();
    int getnumtel();
    QString getnom();
    QString getqualite();
    QString getcategory();
    void setid(int);
    void setnumtel(int);
    void setnom(QString);
    void setqualite(QString);
    void setcategory(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
private:
    QString nom,qualite,category;

    int id, numtel;

};

#endif // FOURNISSEUR_H
