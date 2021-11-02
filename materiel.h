#ifndef MATERIEL_H
#define MATERIEL_H

#include <QString>
#include<QSqlQueryModel>
class Materiel
{
public:
    Materiel();
    Materiel(QString,QString,int);
    int getreference();
    QString getnom();
    QString getcouleur();
    void setreference(int);
    void setprenom(QString);
    void setcouleur(QString);
    bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(int);
    bool modifer();

private :
    int reference;
    QString couleur;
    QString nom;
    int mat_modif;
};

#endif // MATERIEL_H
