#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include<QSqlQueryModel>
class Fournisseur{
public:
    Fournisseur();
    Fournisseur(int,int,QString);
    int getid();
    int getnumtel();
    QString getnom();
    void setid(int);
    void setnumtel(int);
    void setnom(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
private:
    QString nom;
    int id, numtel;

};

#endif // FOURNISSEUR_H
