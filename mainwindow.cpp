#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materiel.h"
#include <QMessageBox>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->le_reference->setValidator(new QIntValidator(0, 99999999, this));
   ui->tab_materiel->setModel(M.afficher());
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Pb_Ajouter_clicked()
{
    int reference=ui->le_reference->text().toInt();
     QString nom=ui->le_nom->text();
     QString couleur=ui->le_couleur->text();
    Materiel M(couleur,nom,reference);
    M.ajouter();

ui->tab_materiel->setModel(M.afficher());
 }








void MainWindow::on_supprimer_clicked()
{
    int reference =ui->le_reference_supp->text().toInt();
        bool test=M.supprimer(reference);

        if(test)
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("supression effectué .\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("échec suprresion.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
        ui->tab_materiel->setModel(M.afficher());

}

void MainWindow::on_Modifier_clicked()
{
    int reference=ui->le_Reference_Modifier->text().toInt();
     QString nom=ui->le_nom_Modifier->text();
     QString couleur=ui->le_couleur_modifier->text();
    Materiel M(couleur,nom,reference);
    M.modifer();

ui->tab_materiel->setModel(M.afficher());
}
