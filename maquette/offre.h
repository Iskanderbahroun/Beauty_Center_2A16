#ifndef OFFRE_H
#define OFFRE_H

#include <QString>
#include <QSqlQueryModel>
class offre
{
public:
    offre();
    offre(int,double,QString);
    int getcode();
    double getprix();
    QString gettype();
    void setcode(int);
    void setprix(double);
    void settype(QString);
    bool ajouter();
    QSqlQueryModel* afficher();///requette de type sql
    bool supprimer(int);
    bool modifier(int code);
private:
    int code;
    double prix;
    QString type;
};

#endif // OFFRE_H
