#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "offre.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QFileInfo>
#include <QLineEdit>
#include "statistique.h"
#include "video.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_code->setValidator( new QIntValidator(0, 99999999, this));///accepte seulement les entiers
    ui->le_prix->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_cin->setValidator( new QIntValidator(0, 99999999, this));
    ui->tab_offre->setModel(o.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}

QString  cheminAbsolu;
void MainWindow::on_pb_ajouter_clicked()
{


    int code=ui->le_code->text().toInt();
    int prix=ui->le_prix->text().toInt();
    QString type=ui->le_type->text();
    //QString type =ui->comboBox->currentIndex();
    int cin_e=ui->le_cin->text().toInt();
      QString photos;

       photos=cheminAbsolu;


    offre o(code,prix,type,cin_e,photos);
    bool test=o.ajouter();

    if (test){

    QMessageBox::information(nullptr, QObject::tr("Ajout d'un offre"),
                           QObject::tr("Ajout effectué\n"
                                       "Click cancel to exit."), QMessageBox::Cancel );
    ui->tab_offre->setModel(o.afficher());//refreche
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Ajout d'un offre"),
                               QObject::tr("Ajout non effectué\n"
                                           "Click cancel to exit."), QMessageBox::Cancel );
     }
   /* ui->le_code->clear();
    ui->le_prix->clear();
    ui->le_type->clear();
    ui->le_cin->clear();*/
}

void MainWindow::on_pb_supprimer_clicked()
{
    offre o1; o1.setcode(ui->le_code_supp->text().toInt());

    bool test=o1.supprimer(o1.getcode());
    if (test){

    QMessageBox::information(nullptr, QObject::tr("Supprimer un offre"),
                           QObject::tr("Supprimer effectué\n"
                                       "Click cancel to exit."), QMessageBox::Cancel );
    ui->tab_offre->setModel(o.afficher());//refreche
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un offre"),
                               QObject::tr("Supprimer non effectué\n"
                                           "Click cancel to exit."), QMessageBox::Cancel );}
    ui->le_code_supp->clear();



}
void MainWindow::on_pb_modifier_clicked()
{
    int code=ui->le_code->text().toInt();
    int prix=ui->le_prix->text().toInt();
    QString type=ui->le_type->text();
    int cin_e=ui->le_cin->text().toInt();
QString photos=cheminAbsolu;
        offre o(code,prix,type,cin_e,photos);


         bool test=o.modifier(o.getcode());
         if(test)
       {
             ui->tab_offre->setModel( o.afficher());//refresh

       QMessageBox::information(nullptr, QObject::tr("Modifier un offre"),
                         QObject::tr("client modifiée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else{
             QMessageBox::critical(nullptr, QObject::tr("Modifier un offre"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);}

         ui->le_code->clear();
         ui->le_prix->clear();
         ui->le_type->clear();
         ui->le_cin->clear();
}


QString MainWindow::on_pb_image_clicked()
{

    QString filename = QFileDialog::getOpenFileName(this, tr("choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if(QString::compare(filename, QString()) !=0)
    {
        QImage image;

        bool valid = image.load(filename);
        if(valid)
        {
             ui->tb_image->setPixmap(QPixmap::fromImage(image));
             QFileInfo fileinfo(filename);
             cheminAbsolu =fileinfo.filePath();
             ui->label_image->setText(cheminAbsolu);
            QMessageBox::information(nullptr, QObject::tr("Image importer\n"),
                                     QObject::tr("Imporation avec succée\n""Click Cancel to exit."), QMessageBox::Cancel);
            return cheminAbsolu;

        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Image importer"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            //erreur
        }
}

}


void MainWindow::on_pb_trier_code_clicked()
{
    QMessageBox msgBox ;



                   bool test=o.tricode();
                   if(test){


                 QMessageBox::information(nullptr, QObject::tr("trier les  offres par code"),
                                   QObject::tr("tri  effectué .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                  ui->tableView->setModel(o.tricode());

               }  else
                     QMessageBox::critical(nullptr, QObject::tr("trier les  offres par code"),
              QObject::tr("tri non effectué\n"
                                                       "Click cancel to exit."), QMessageBox::Cancel );




}

void MainWindow::on_pb_trier_prix_clicked()
{
    QMessageBox msgBox ;



                   bool test=o.triprix();
                   if(test){
 ui->tableView->setModel(o.triprix());

                 QMessageBox::information(nullptr, QObject::tr("trier les  offres par prix"),
                                   QObject::tr("tri  effectué .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);



               }  else
                     QMessageBox::critical(nullptr, QObject::tr("trier les  offres par prix"),
              QObject::tr("tri non effectué\n"
                                                       "Click cancel to exit."), QMessageBox::Cancel );


}

void MainWindow::on_pb_trier_type_clicked()
{
    QMessageBox msgBox ;



                   bool test=o.tritype();
                   if(test){
 ui->tableView->setModel(o.tritype());

                 QMessageBox::information(nullptr, QObject::tr("trier les  offres par type"),
                                   QObject::tr("tri  effectué .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);



               }  else
                     QMessageBox::critical(nullptr, QObject::tr("trier les  offres par type"),
              QObject::tr("tri non effectué\n"
                                                       "Click cancel to exit."), QMessageBox::Cancel );


}
void MainWindow::on_pb_chercher_code_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString codee;

                offre o;
    codee =o.getcode();

        codee= ui->le_code_ch->text();

        model->setQuery("Select * from offre "
                        "where code='"+codee+"' ");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin_e"));


           bool test=o.chercher_code();
           if(test)
         {
         QMessageBox::information(nullptr, QObject::tr("Chercher un offre"),
                           QObject::tr("affichage offre .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tableView->setModel(model);
         ui->tableView->show();


    }
           else{
               QMessageBox::information(nullptr, QObject::tr("Chercher un offre"),
                           QObject::tr("Erreur .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           }



}
void MainWindow::on_pb_chercher_prix_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString prixx;

                offre o;
    prixx =o.getprix();

        prixx= ui->le_prix_ch->text();

        model->setQuery("Select * from offre "
                        "where prix='"+prixx+"' ");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin_e"));


           bool test=o.chercher_prix();
           if(test)
         {
         QMessageBox::information(nullptr, QObject::tr("Chercher un offre"),
                           QObject::tr("affichage offre .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tableView->setModel(model);
         ui->tableView->show();


    }
           else{
               QMessageBox::information(nullptr, QObject::tr("Chercher un offre"),
                           QObject::tr("Erreur .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           }


}

void MainWindow::on_pb_chercher_type_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString typee;

                offre o;
    typee =o.gettype();

        typee= ui->le_type_ch->text();

        model->setQuery("Select * from offre "
                        "where type='"+typee+"' ");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin_e"));


           bool test=o.chercher_type();
           if(test)
         {
         QMessageBox::information(nullptr, QObject::tr("Chercher un offre"),
                           QObject::tr("affichage offre .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tableView->setModel(model);
         ui->tableView->show();


    }
           else{
               QMessageBox::information(nullptr, QObject::tr("Chercher un offre"),
                           QObject::tr("Erreur .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           }


}

void MainWindow::on_pb_stat_clicked()
{
statistique=new Statistique(this);
statistique->show();
}

void MainWindow::on_pb_video_clicked()
{
Video=new video(this);
Video->show();

}
