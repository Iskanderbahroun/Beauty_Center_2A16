#include "mainwindow.h"
#include"ui_mainwindow.h"
#include "mainwindow.h"
#include "client.h"
#include <QMessageBOX>
#include <QIntValidator>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->le_id->setValidator (new QIntValidator(0, 9999999, this));
ui->tab_client1->setModel (C.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ob_tri_clicked()
{


}

void MainWindow::on_ob_statistique_clicked()
{

}

void MainWindow::on_ob_excel_clicked()
{

}

void MainWindow::on_ob_cadeaux_clicked()
{

}

void MainWindow::on_ob_ajouterclient_clicked()
{
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int age=ui->le_age->text().toInt();
    int id=ui->le_id->text().toInt();

    client C(nom,prenom,age,id);
    C.ajouter();
    ui->tab_client1->setModel (C.afficher());

}


void MainWindow::on_ob_afficherclient_clicked()
{

}

void MainWindow::on_ob_modifierclient_clicked()
{

}

void MainWindow::on_ob_supprimerclient_clicked()

{
    /*
client c1;
c1.setnom(ui->le_nom->text());
bool test=c1.supprimer(c1.getnom());
c1.setprenom(ui->le_prenom->text());
bool test=c1.supprimer(c1.getprenom());
c1.setage(ui->le_age->text().toInt());
bool test=c1.supprimer(c1.getage());
c1.setid(ui->le_id->text().toInt());
bool test=c1.supprimer(c1.getid());
QMessageBox msgBox;
   if(test)
       msgBox.setText("suppression avec succes");

   else
       msgBox.setText("echec de suppression");
   msgBox.exec();
   */
}

void MainWindow::on_pb_supprimer_clicked()
{
   client c1 ;
    int id =ui->le_id_supprimer->text().toInt();
        bool test=c1.supprimer(id);

        if(test)
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("supression effectué .\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("échec suprresion.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
        ui->tab_client1->setModel(c1.afficher());
}
