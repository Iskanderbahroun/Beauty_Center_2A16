#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->le_cin->setValidator( new QIntValidator(0,99999999, this) );
ui->le_age->setValidator( new QIntValidator(0,99, this) );
ui->le_salaire->setValidator( new QIntValidator(0,9999, this) );
ui->tab_employes->setModel(E.afficher());
ui->comboBox->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajout_clicked()
{  int Cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int Age=ui->le_age->text().toInt();
    QString Role=ui->le_role->text();
    int Salaire=ui->le_salaire->text().toInt();


  Employe E(Cin,nom,prenom,Age,Role,Salaire);
bool test=E.ajouter();
QMessageBox msgBox;
if (test)
{msgBox.setText("Ajout avec succes. ");
    ui->tab_employes->setModel(E.afficher());
ui->comboBox->setModel(E.afficher());}}




void MainWindow::on_le_supprimer_clicked()
{
    Employe E1;
    int id = ui->comboBox->currentText().toInt();
        bool test=E1.supprimer(id);
QMessageBox msgBox ;
        if(test){
            msgBox.setText("supression effectué .\n"
                            "Click Ok to exit.");
            ui->tab_employes->setModel(E.afficher());
            ui->comboBox->setModel(E.afficher());

        }else
            msgBox.setText("Echec de suppression" );
                    msgBox.exec();
            }



void MainWindow::on_le_modifier_clicked()
{
    int Cin = ui->le_cin->text().toInt();
     QString Nom= ui->le_nom->text();
     QString Prenom= ui->le_prenom->text();
      int Age = ui->le_age->text().toInt();
      QString Role=ui->le_role->text();
      int Salaire=ui->le_salaire->text().toInt();

       Employe E(Cin,Nom,Prenom,Age,Role,Salaire);


       bool test=E.modifier(Cin,Nom,Prenom,Age,Role,Salaire);
       if(test)
     {ui->tab_employes->setModel(E.afficher());
           ui->comboBox->setModel(E.afficher());
     QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                       QObject::tr("invite modifiée.\n"
                                   "Click ok to exit."), QMessageBox::Ok);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
  }






  void MainWindow::on_comboBox_activated(const QString &arg1)
  {
      int Cin = ui->comboBox->currentText().toInt();
       QString Cin_string= QString::number(Cin);
              QSqlQuery query;
              query.prepare("select * from EMPLOYES where CIN='"+Cin_string+"'");

              if(query.exec()){

                  while(query.next())
                  {
                      ui->le_cin->setText(query.value(0).toString());
                 ui->le_nom->setText(query.value(1).toString());

                  ui->le_prenom->setText(query.value(2).toString());
                  ui->le_age->setText(query.value(3).toString());
                  ui->le_role->setText(query.value(4).toString());
                  ui->le_salaire->setText(query.value(5).toString());
  }}
              else
                  QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

  }

void MainWindow::on_le_trie_par_nom_clicked()
{

     ui->tab_employes->setModel(E.triNom());
    }


void MainWindow::on_le_trie_age_clicked()
{
  ui->tab_employes->setModel(E.triAge());
}

void MainWindow::on_le_trie_salaire_clicked()
{
   ui->tab_employes->setModel(E.triSalaire());
}




void MainWindow::on_rech_textChanged(const QString &arg1)
{
    Employe E;

        int Cin = ui->rech->text().toInt();
         int Age = ui->rech->text().toInt();
         int Salaire = ui->rech->text().toInt();

            E.rechercher(ui->tab_employes,Cin,Age,Salaire);
            if (ui->rech->text().isEmpty())
            {
               ui->tab_employes->setModel(E.afficher());
            }
}
