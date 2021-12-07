#ifndef OFFRE_H
#define OFFRE_H

#include <QString>
#include <QSqlQueryModel>
class offre
{
public:
    offre();
    offre(int,int,QString,int,QString);
    //les getteurs
    int getcode();
    int getprix();
    QString gettype();
    int getcin_e();
    QString getphotos();
    //les setteurs
    void setcode(int);
    void setprix(int);
    void settype(QString);
    void setcin_e(int);
    void setphotos(QString);
    /*CRUD*/
    bool ajouter();
    QSqlQueryModel* afficher();///requette de type sql
    bool supprimer(int);
    bool modifier(int code);
    /*trier les offres*/
QSqlQueryModel * tricode();
QSqlQueryModel * triprix();
QSqlQueryModel * tritype();
/*chercher un offre*/
bool chercher_code();
bool chercher_prix();
bool chercher_type();
private:
    int code;
    int prix;
    QString type;
    int cin_e;
     QString photos;
};

#endif // OFFRE_H
