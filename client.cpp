#include "client.h"

#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
//#include <QIntValidator>
//#include <QSystemTrayIcon>
#include <QPrinter>
#include <QPrintDialog>
#include <QSqlTableModel>
#include <QPagedPaintDevice>




//#include "ui_client.h"

client::client()
{
cin=0;
tel=0;

}
client::client(int cin,QString nom ,QString prenom,int tel,QString adresse)
{
   this->cin=cin;
   this->nom=nom;
   this->prenom=prenom;
   this->tel=tel;
   this->adresse=adresse;
}

int client::getcin(){return cin;}
QString client::getnom(){return nom;}
QString client::getprenom(){return prenom;}
int client::gettel(){return tel;}
QString client::getadresse(){return adresse;}
void client::setcin(int cin){this->cin=cin;}
void client::setnom(QString nom){this->nom=nom;}
void client::setprenom(QString prenom){this->prenom=prenom;}
void client::settel(int tel){this->tel=tel;}
void client::setadresse(QString nationalite){this->adresse=adresse;}
bool client::ajouter()
{
  //bool test=false;
   QSqlQuery query;
   QString cin_string=QString::number(cin);
    QString tel_string=QString::number(tel);
         query.prepare("INSERT INTO client (cin,nom,prenom,tel,adresse) "
                       "VALUES (:cin,:nom,:prenom,:tel,:adresse)");
         query.bindValue(0, cin_string);
         query.bindValue(1,nom);
         query.bindValue(2, prenom);
         query.bindValue(3, tel_string);
         query.bindValue(4,adresse);
         return  query.exec();



}
QSqlQueryModel * client::afficher(){



    QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT* FROM client");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));


        return model;

}
bool client::supprimer(int cin2)
{
 QSqlQuery query;
 QString res=QString::number(cin2);
 query.prepare("delete from client where cin= :cin");
 query.bindValue(":cin",res);
 return query.exec();
}
bool client::modifier(int cin,QString nom,QString prenom,int tel,QString adresse)
{
    QSqlQuery query;

         QString cin_string=QString::number(cin);
         QString tel_string= QString::number(tel);
           query.prepare(" UPDATE client set cin=:cin ,nom=:nom,prenom=:prenom, tel=:tel,adresse=:adresse where cin=:cin");
           query.bindValue(":cin",cin_string);
           query.bindValue(":nom",nom);
           query.bindValue(":prenom",prenom);
           query.bindValue(":tel",tel_string);
           query.bindValue(":adresse",adresse);

           return query.exec();
}
QSqlQueryModel * client::trierprenom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM client ORDER BY prenom");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
    return model;
}
QSqlQueryModel * client::trieradresse()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM client ORDER BY adresse");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
    return model;
}
QSqlQueryModel * client::triertel()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM client ORDER BY tel");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
    return model;
}

QSqlQueryModel * client::trierfreq()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM client ORDER BY frequence");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
    return model;
}


void client::recherche(QTableView * table, QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        //QString annees_string=QString::number(annees);
        QSqlQuery *query=new QSqlQuery;
        query->prepare("select * from client where adresse like '%"+rech+"%' or cin like '%"+rech+"%' or nom like '%"+rech+"%' ;");
        query->exec();
        model->setQuery(*query);
        table->setModel(model);
        table->show();
}
void  client::telechargerPDF(){


                     QPdfWriter pdf("C:\\Users\\Iskander\\Documents\\work\\QT\\Beauty_Center_2A16-integration_ibtihel_farhat\\import.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::blue);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"GESTION DU CLIENT");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial",14));
                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial",11));
                         painter.drawText(200,3300,"CIN");
                         painter.drawText(1300,3300,"NOM");
                         painter.drawText(2200,3300,"PRENOM");
                         painter.drawText(3200,3300,"TEL");
                         painter.drawText(5300,3300,"ADRESSE");

                         QSqlQuery query;
                        // query.prepare("select * from client where cin='"+val+"'");
                         query.prepare("select * from client");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(1).toString());
                             painter.drawText(2200,i,query.value(2).toString());
                             painter.drawText(3200,i,query.value(3).toString());
                             painter.drawText(5300,i,query.value(4).toString());


                            i = i + 500;
                         }}







QChart* client::chart_pie()
{
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM CLIENT");
    q1.exec();

    q2.prepare("SELECT * FROM CLIENT WHERE CIN<=9000000");
    q2.exec();

    q3.prepare("SELECT * FROM CLIENT WHERE CIN<=15000000 AND CIN>9000000");
    q3.exec();

    q4.prepare("SELECT * FROM CLIENT WHERE CIN<=91999999 AND CIN>15000000");
    q4.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;

//     Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("inf 3", c1);
    series->append("inf 10", c2);
    series->append("inf 20", c3);
//     Create the chart widget
    QChart *chart = new QChart();

//     Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();

    return chart;
}

