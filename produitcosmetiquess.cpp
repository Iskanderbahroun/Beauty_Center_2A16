#include "produitcosmetiquess.h"
#include "ui_produitcosmetiquess.h"
#include "produitscosmetiques.h"
#include <QIntValidator>
#include "QSqlQuery"
#include "QStringListModel"
#include <QMessageBox>















produitcosmetiques::produitcosmetiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::produitcosmetiques)
{
    ui->setupUi(this);
    ui->Le_num->setValidator(new QIntValidator(0,99999999,this));
       ui->Le_prix->setValidator(new QIntValidator(0,999999999,this));
       ui->Le_Q->setValidator(new QIntValidator(0,999999999,this));
    ui->tableView->setModel(P.afficher());
ui->comboBox->setModel(P.afficher());
}

produitcosmetiques::~produitcosmetiques()
{
    delete ui;
}

void produitcosmetiques::on_pb_ajouter_clicked()
{
    int Num=ui->Le_num->text().toInt();
        QString  Marque=ui->Le_Marque->text();
        QString Nom=ui->Le_nom->text();
        int Quantite=ui->Le_Q->text().toInt();
        QString QRCODE=ui->LE_QR->text();
        int Prix=ui->Le_prix->text().toInt();
       ProduitsCosmetiques p(Num,QRCODE,Prix,Nom,Quantite,Marque);
       bool test=p.ajouter();
       QMessageBox msgBox;
       if(test)
           msgBox.setText("ajout avec succes");

       else
           msgBox.setText("echec");
       msgBox.exec();
       ui->tableView->setModel(P.afficher()); //refrech
    ui->comboBox->setModel(P.afficher()); //refrech
}

void produitcosmetiques::on_pb_supp_clicked()
{
    int Num =ui->comboBox->currentText().toInt();
        bool test=P.supprimer(Num);

        if(test)
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("supression effectué .\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("échec suprresion.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(P.afficher());
    ui->comboBox->setModel(P.afficher());
}

void produitcosmetiques::on_Modifier_clicked()
{
    int Num=ui->Le_num->text().toInt();
        QString  Marque=ui->Le_Marque->text();
        QString Nom=ui->Le_nom->text();
        int Quantite=ui->Le_Q->text().toInt();
        QString QRCODE=ui->LE_QR->text();
        int Prix=ui->Le_prix->text().toInt();
       ProduitsCosmetiques p(Num,QRCODE,Prix,Nom,Quantite,Marque);


         bool test=P.modifier(Num,QRCODE,Prix,Nom,Quantite,Marque);
         if(test)
       {ui->tableView->setModel(P.afficher());
       QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                         QObject::tr("invite modifiée.\n"
                                     "Click ok to exit."), QMessageBox::Ok);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}

void produitcosmetiques::on_comboBox_activated(const QString &arg1)
{
    int NUM = ui->comboBox->currentText().toInt();
         QString id_string= QString::number(NUM);
                QSqlQuery query;
                query.prepare("select * from PRODUITCOSMETIQUE where NUM='"+id_string+"'");

                if(query.exec()){

                    while(query.next())
                    {
                        ui->LE_QR->setText(query.value(1).toString());
                   ui->Le_num->setText(query.value(0).toString());

                    ui->Le_Q->setText(query.value(2).toString());
                    ui->Le_nom->setText(query.value(3).toString());
                    ui->Le_Marque->setText(query.value(4).toString());
                    ui->Le_prix->setText(query.value(5).toString());
    }}
                else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}





void produitcosmetiques::on_trierprix_clicked()
{
    ui->tableView->setModel(P.triprix());
}

void produitcosmetiques::on_trienom_clicked()
{
    ui->tableView->setModel(P.trinom());
}

void produitcosmetiques::on_triemarque_clicked()
{
    ui->tableView->setModel(P.triprix());
}


void produitcosmetiques::on_pb_ajouter_2_clicked()
{
    QString qr=ui->LE_QR_2->text();
    if(qr=="1")
          {
              QPixmap pix("C:/Users/asus/Desktop/Beauty_Center_2A16-Fournisseur/1.png");
              int w = ui->label_pic_2->width();
              int h = ui->label_pic_2->height();
               ui->label_pic_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


          }
   else if(qr=="2")
          {
              QPixmap pix("C:/Users/asus/Desktop/Beauty_Center_2A16-Fournisseur/2.png");
              int w = ui->label_pic_2->width();
              int h = ui->label_pic_2->height();
               ui->label_pic_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


          }
   else if(qr=="3")
          {
              QPixmap pix("C:/Users/asus/Desktop/Beauty_Center_2A16-Fournisseur/3.png");
              int w = ui->label_pic_2->width();
              int h = ui->label_pic_2->height();
               ui->label_pic_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


          }
    else
    {
        QMessageBox msgBox;

               msgBox.setText("taper 1 ou 2 ou 3");
           msgBox.exec();

 }


}

void produitcosmetiques::on_pb_stat_clicked()
{
    Statistique =new statistique(this);
    Statistique->show();
}
