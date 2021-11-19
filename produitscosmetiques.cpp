#include "produitscosmetiques.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QVector>








ProduitsCosmetiques::ProduitsCosmetiques()
{
Num =0;
QRCODE=" ";
Quantite=0;
Nom=" ";
Prix=0;
Marque=" ";
}
ProduitsCosmetiques::ProduitsCosmetiques(int Num,QString QRCODE,int Quantite,QString Nom,int Prix,QString Marque)
{
    this->Num=Num;
    this->QRCODE=QRCODE ;
    this->Quantite=Quantite;
    this->Nom=Nom;
    this->Prix=Prix;
    this->Marque=Marque;
}
int ProduitsCosmetiques::getnum(){return Num;}
QString ProduitsCosmetiques::getqrcode(){return QRCODE;}
int ProduitsCosmetiques::getquantite(){return Quantite;}
QString ProduitsCosmetiques::getnom(){return Nom;}
int ProduitsCosmetiques::getprix(){return Prix;}
QString ProduitsCosmetiques::getmarque(){return Marque;}
void ProduitsCosmetiques::setnum(int Num){this->Num=Num;}
void ProduitsCosmetiques::setcode(QString QRCODE){this->QRCODE=QRCODE;}
void ProduitsCosmetiques::setquantite(int Quantite){this->Quantite=Quantite;}
void ProduitsCosmetiques::setnom(QString Nom){this->Nom=Nom;}
void ProduitsCosmetiques::setprix(int Prix){this->Prix=Prix;}
void ProduitsCosmetiques::setmarque(QString Marque){this->Marque=Marque;}
bool ProduitsCosmetiques::supprimer(int Num)
{ QString Nums = QString::number(Num);
    QSqlQuery query;
    query.prepare("DELETE FROM PRODUITCOSMETIQUE where NUM=:num");
    query.bindValue(":num", Nums);

    return query.exec();
}
bool ProduitsCosmetiques::ajouter()
{
    QString Nums = QString::number(Num);
    QString Quantite_string= QString::number(Quantite);
    QString Prix_string= QString::number(Prix);
    QSqlQuery query;

    query.prepare("INSERT INTO PRODUITCOSMETIQUE (Num, QRCODE, Quantite,Nom,Marque , prix) "
                            "VALUES (:num, :qrcode, :quantite, :nom, :marque, :prix)");
    query.bindValue(0, Nums);
    query.bindValue(1, QRCODE);
    query.bindValue(2, Quantite_string);
    query.bindValue(3, Nom);
    query.bindValue(4, Marque);
    query.bindValue(5, Prix_string);

    return query.exec();
}
QSqlQueryModel* ProduitsCosmetiques::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT* FROM PRODUITCOSMETIQUE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QRCODE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Marque"));


    return model;
}
bool ProduitsCosmetiques::modifier(int Num, QString QRCODE, int Quantite, QString Nom, int Prix, QString Marque)
{QSqlQuery query;
    QString Num_string= QString::number(Num);
    QString Quantite_string= QString::number(Quantite);
    QString Prix_string= QString::number(Prix);
           query.prepare(" UPDATE PRODUITCOSMETIQUE set Num=:num ,QRCODE=:qrcode,Nom=:nom ,prix=:prix, Marque=:marque  where Num=:num");
           query.bindValue(":num",Num_string);
           query.bindValue(":qrcode",QRCODE);
           query.bindValue(":quantite",Quantite_string);
           query.bindValue(":marque",Marque);
           query.bindValue(":nom",Nom);
           query.bindValue(":prix",Prix_string);

    return query.exec();
}
QSqlQueryModel * ProduitsCosmetiques::triprix()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUITSCOSMETIQUE ORDER BY PRIX");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QRCODE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Marque"));


    return model;
}
QSqlQueryModel * ProduitsCosmetiques::trinom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUITSCOSMETIQUE ORDER BY NOM");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QRCODE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Marque"));


    return model;
}
QSqlQueryModel * ProduitsCosmetiques::trimarque()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUITSCOSMETIQUE ORDER BY MARQUE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QRCODE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Marque"));


    return model;
}
void ProduitsCosmetiques:: rechercher(QTableView * table ,int Num, QString QRCODE,int Quantite,QString Nom,int Prix,QString Marque   )
{
    QSqlQueryModel *model= new QSqlQueryModel();

    QSqlQuery *query =new QSqlQuery;
    QString Num_string= QString::number(Num);
    QString Quantite_string= QString::number(Quantite);
    QString Prix_string= QString::number(Prix);


    query->prepare("SELECT * FROM PRODUITSCOSMETIQUE where NUM like '%"+Num_string+"%' or QRCODE like '%"+QRCODE+"%' or QUANTITE like '%"+Quantite_string+"%' or NOM like '%"+Nom+"%' or PRIX like '%"+Prix_string+"%' or MARQUE like '%"+Marque+"%' ;");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
