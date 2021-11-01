#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Fournisseur.h"
#include <QIntValidator>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lb_img_ajt->setPixmap(QPixmap("C:/Users/Iskander/Documents/work/QT/Project/interfacefournisseur/background.jpg"));
    ui->bg_home->setPixmap(QPixmap("C:/Users/Iskander/Documents/work/QT/Project/interfacefournisseur/background.jpg"));
    ui->bg_afficher->setPixmap(QPixmap("C:/Users/Iskander/Documents/work/QT/Project/interfacefournisseur/background.jpg"));
    ui->bg_supp->setPixmap(QPixmap("C:/Users/Iskander/Documents/work/QT/Project/interfacefournisseur/background.jpg"));
    ui->le_id->setValidator(new QIntValidator(0,99999999,this));
    ui->le_numtel->setValidator(new QIntValidator(0,999999999,this));
ui->tabfournisseur->setModel(F.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    int numtel=ui->le_numtel->text().toInt();
    QString nom=ui->le_nom->text();
    QString qualite=ui->Le_qal->text();
    QString category=ui->Le_cat->text();
   Fournisseur F(id,numtel,nom,qualite,category);
   bool test=F.ajouter();
   QMessageBox msgBox;
   if(test)
       msgBox.setText("ajout avec succes");

   else
       msgBox.setText("echec");
   msgBox.exec();
   ui->tabfournisseur->setModel(F.afficher());

}


void MainWindow::on_pb_supp_clicked()
{
   int id =ui->le_id_supp->text().toInt();
    bool test=F.supprimer(id);

    if(test)
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supression effectué .\n"
                                "Click Ok to exit."), QMessageBox::Ok);
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("échec suprresion.\n"
                                "Click cancel to exit."), QMessageBox::Cancel);
    ui->tabfournisseur->setModel(F.afficher());

}

void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->le_id_modif->text().toInt();
     int numtel = ui->le_numtel_modif->text().toInt();
       QString nom= ui->le_nom_modif->text();
       QString qualite= ui->Le_qal_modif->text();
       QString category =ui->Le_cat_modif->text();

     Fournisseur F(id,numtel,nom,qualite,category);


     bool test=F.modifier(id,numtel,nom,qualite,category);
     if(test)
   {ui->tabfournisseur->setModel(F.afficher());
   QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                     QObject::tr("invite modifiée.\n"
                                 "Click ok to exit."), QMessageBox::Ok);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}
