#include "statistiques.h"
#include "ui_statistiques.h"
#include <QSqlQuery>
#include <QPainter>
#include <QRectF>
#include <QStaticText>

statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);
}

statistiques::~statistiques()
{
    delete ui;
}
void statistiques::paintEvent(QPaintEvent *)
{
    int nbA=0;
    int nbB=0;
    int nbC=0;
   QSqlQuery A( "SELECT * FROM PRODUITCOSMETIQUE where marque like 'lella' ");
   while(A.next())
   {
        nbA++;
   }
   QSqlQuery B( "SELECT * FROM PRODUITCOSMETIQUE where marque like 'clear' ");
   while(B.next())
   {
        nbB++;
   }
   QSqlQuery C( "SELECT * FROM PRODUITCOSMETIQUE where marque like 'kk' ");
   while(C.next())
   {
        nbC++;
   }
   float nb=nbA+nbB+nbC;
   float s1=nbA*100;
   float s2=nbB*100;
   float xA;
           xA=s1/nb;
   float xB;
          xB=s2 /nb;
          float y,m,z;
   y=(xA*360)/100;
   m=(xB*360)/100;
   z=360-(y+m);
    QPainter painter(this);
    QRectF size =QRect(10,10, this->width()-100, this->width()-100);
    painter.setBrush(Qt::green);
    painter.drawPie(size,0, 16*y);

    painter.setBrush(Qt::red);
    painter.drawPie(size, 16*y, 16*m);

    painter.setBrush(Qt::darkYellow);
    painter.drawPie(size, 16*(m+y), 16*z);


painter.drawText(size," GREEN : lella \n RED : clear \n YELLOW : kk ");


}
