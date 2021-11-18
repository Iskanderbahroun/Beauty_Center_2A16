#ifndef MATERIEL_H
#define MATERIEL_H
#include <QTableView>
#include <QString>
#include<QSqlQueryModel>
class Materiel
{
public:
    Materiel();
    Materiel(QString,QString,int,int);
    int getidfourniseur();
    int getreference();
    QString getnom();
    QString getcouleur();
    void setreference(int);
     void setidfourniseur(int);
    void setprenom(QString);
    void setcouleur(QString);

    bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(QString);
    bool modifier(int,int,QString,QString);
     QSqlQueryModel * tri();
         QSqlQueryModel * tri1();
             QSqlQueryModel * tri2();
      void recherche(QTableView * tabl, QString,QString,int);
      int calculer_stock(QString nom);
private :
    int reference;
    int id_fourniseur;
    QString couleur;
    QString nom;

};

#endif // MATERIEL_H
