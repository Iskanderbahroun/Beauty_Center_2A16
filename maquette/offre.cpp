#include "offre.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
offre::offre()
{
code=0 ;prix=0.0 ;type=" ";
}
offre::offre(int code,double prix,QString type)
{
    this->code=code;
    this->prix=prix;
    this->type=type;
}
int offre::getcode()
{return code;}
double offre::getprix()
{return prix;}
QString offre::gettype()
{return type;}
void offre::setcode(int code)
{this->code=code;}
void offre::setprix(double prix)
{this->prix=prix;}
void offre::settype(QString type)
{this->type=type;}
bool offre::ajouter()
{

    QSqlQuery query;
    QString code_string= QString::number(code);
    QString prix_string= QString::number(prix);
          query.prepare("INSERT INTO offre (code, prix, type) "
                        "VALUES (:code, :prix, :type)");
          query.bindValue(":code", code_string);
          query.bindValue(":prix", prix_string);
          query.bindValue(":type", type);
            return query.exec();

}
bool offre::supprimer(int code)
{
    QSqlQuery query;
    query.prepare(" Delete from offre where code=:code");
    query.bindValue(":code", code);
      return query.exec();
}
QSqlQueryModel* offre::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT* FROM offre");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    return model;

}
/*bool offre::modifier(int code)
{
*/
     /*QSqlQuery query;

    int A=int(code);
     query.prepare("UPDATE INTO offre SET code=:code, prix:=prix, type:=type WHERE code:=code");
     query.bindValue(":code", code);
     query.bindValue(":prix", prix);
     query.bindValue(":type", type);
       return query.exec();*/
    bool offre::modifier(int code)
      {
          QSqlQuery query;
          int res= int(code);

          query.prepare("UPDATE offre SET code=:code, prix=:ssprix, type=:type WHERE code=:code");
          query.bindValue(":code", code);
          query.bindValue(":prix", prix);
          query.bindValue(":type", type);


          return    query.exec();
     // }



}
