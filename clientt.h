#ifndef CLIENTT_H
#define CLIENTT_H

#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
#include <QPdfWriter>
#include <QPainter>

#include <QPainter>
//#include <QChart>
//#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

using namespace QtCharts;


class clientt
{
public:
    clientt();
    clientt(int,QString,QString,int,QString);
    int getcin();
    QString getnom();
    QString getprenom();
    int gettel();
    QString getadresse();
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void settel(int);
    void setadresse(QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel *afficher();
    bool modifier(int,QString,QString,int,QString);
    QSqlQueryModel * trierprenom();
    QSqlQueryModel * trieradresse();
    QSqlQueryModel * triertel();
   QSqlQueryModel *  trierfreq();
    void recherche(QTableView * table, QString);
    void telechargerPDF();

    QChart* chart_bar();
    QChart* chart_pie();
private:
    int cin,tel;
    QString nom,prenom,adresse;
};



#endif // CLIENTT_H
