#ifndef PRODUITSCOSMETIQUES_H
#define PRODUITSCOSMETIQUES_H
#include <QString>
#include <QSqlQueryModel>
#include<QTableView>
class ProduitsCosmetiques
{
public:
    ProduitsCosmetiques();
    ProduitsCosmetiques(int,QString,int,QString,int,QString);
    int getnum();
    QString getqrcode();
    int getquantite();
    QString getnom();
    int getprix();
    QString getmarque();
    void setnum(int);
    void setcode(QString);
    void setquantite(int);
    void setnom(QString);
    void setprix(int);
    void setmarque(QString);
    QSqlQueryModel* triprix();
    QSqlQueryModel* trinom();
    QSqlQueryModel* trimarque();
    void generer_codeqr();
    bool modifier(int,QString,int,QString,int,QString);
    bool supprimer(int);
    bool ajouter();
    void rechercher(QTableView * tabl, int,QString,int,QString,int,QString);
    void consulter_produit();
    void statistique(QVector<double>* ticks,QVector<QString> *labels);
    QSqlQueryModel* afficher();
private:
    int Num;
    QString QRCODE;
    int Quantite;
    QString Nom;
    int Prix;
    QString Marque;
};

#endif // PRODUITSCOSMETIQUES_H
