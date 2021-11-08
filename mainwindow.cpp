#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Fournisseur.h"
#include <QIntValidator>
#include "QSqlQuery"
#include "QStringListModel"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lb_img_ajt->setPixmap(QPixmap("C:/Users/Iskander/Documents/work/QT/Project/interfacefournisseur/background.jpg"));
    ui->bg_home->setPixmap(QPixmap("C:/Users/Iskander/Documents/work/QT/Project/interfacefournisseur/background.jpg"));
    ui->bg_afficher->setPixmap(QPixmap("C:/Users/Iskander/Documents/work/QT/Project/interfacefournisseur/background.jpg"));

    ui->le_id->setValidator(new QIntValidator(0,99999999,this));
    ui->le_numtel->setValidator(new QIntValidator(0,999999999,this));
ui->tabfournisseur->setModel(F.afficher());

ui->comboBox->setModel(F.afficher());
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
    QString category =ui->Le_cat->text();
   Fournisseur F(id,numtel,nom,qualite,category);
   bool test=F.ajouter();
   QMessageBox msgBox;
   if(test)
       msgBox.setText("ajout avec succes");

   else
       msgBox.setText("echec");
   msgBox.exec();
   ui->tabfournisseur->setModel(F.afficher());
ui->comboBox->setModel(F.afficher());
}


void MainWindow::on_pb_supp_clicked()
{
   int id =ui->comboBox->currentText().toInt();
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
ui->comboBox->setModel(F.afficher());
}

void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->le_id->text().toInt();
     int numtel = ui->le_numtel->text().toInt();
       QString nom= ui->le_nom->text();
       QString qualite= ui->Le_qal->text();
       QString category =ui->Le_cat->text();

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






void MainWindow::on_comboBox_activated(const QString &arg1)
{
    int id = ui->comboBox->currentText().toInt();
     QString id_string= QString::number(id);
            QSqlQuery query;
            query.prepare("select * from FOURNISSEUR where ID='"+id_string+"'");

            if(query.exec()){

                while(query.next())
                {
                    ui->le_numtel->setText(query.value(1).toString());
               ui->le_id->setText(query.value(0).toString());

                ui->le_nom->setText(query.value(2).toString());
                ui->Le_qal->setText(query.value(3).toString());
                ui->Le_cat->setText(query.value(4).toString());
}}
            else
                QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_trie_ref_clicked()
{
 ui->tabfournisseur->setModel(F.trinom());
}

void MainWindow::on_trie_cat_clicked()
{
    ui->tabfournisseur->setModel(F.tricategory());
}

void MainWindow::on_trie_qual_clicked()
{
    ui->tabfournisseur->setModel(F.triqual());
}

void MainWindow::on_recher_edit_textChanged(const QString &arg1)
{

    {
        Fournisseur F;


    QString nom = ui->recher_edit->text();
     QString qualite = ui->recher_edit->text();
      QString category = ui->recher_edit->text();
    F.recherche(ui->tabfournisseur,nom,qualite,category);
    if (ui->recher_edit->text().isEmpty())
    {
       ui->tabfournisseur->setModel(F.afficher());
    }
    }
}
