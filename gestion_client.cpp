#include "gestion_client.h"
#include "ui_gestion_client.h"
#include "client.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>

gestion_client::gestion_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_client)
{
    ui->setupUi(this);
    ui->le_id->setValidator (new QIntValidator(0, 9999999, this));
    ui->tab_client1->setModel (C.afficher());
    ui->comboBox->setModel(C.afficher());
}

gestion_client::~gestion_client()
{
    delete ui;
}

void gestion_client::on_ob_tri_clicked()
{


}

void gestion_client::on_ob_statistique_clicked()
{

}

void gestion_client::on_ob_excel_clicked()
{

}

void gestion_client::on_ob_cadeaux_clicked()
{

}

void gestion_client::on_ob_ajouterclient_clicked()
{
    QString nom=ui->le_name->text();
    QString prenom=ui->le_prename->text();
    int age=ui->Le_age->text().toInt();
    int id=ui->le_Id->text().toInt();

    client C(nom,prenom,age,id);
    C.ajouter();
    ui->tab_client1->setModel (C.afficher());

}


void gestion_client::on_ob_modifierclient_clicked()
{
    client C ;
    QString nom=ui->le_name->text();
    QString prenom=ui->le_prename->text();
    int age=ui->Le_age->text().toInt();
    int id=ui->le_Id->text().toInt();

           client c(nom,prenom,age,id);


         bool test=C.modifier(nom,prenom,id,age);
         if(test)
       { ui->tab_client1->setModel(c.afficher());
       QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                         QObject::tr("invite modifiée.\n"
                                     "Click ok to exit."), QMessageBox::Ok);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                         QObject::tr("echec d'ajout !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);


}



void gestion_client::on_pb_supprimer_clicked()
{
   client c1 ;
    QString nom =ui->comboBox->currentText();
        bool test=c1.supprimer(nom);

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




void gestion_client::on_comboBox_activated(const QString &arg1)
{
    QString id = ui->comboBox->currentText();

            QSqlQuery query;
            query.prepare("select * from client where NOM='"+id+"'");

            if(query.exec()){

                while(query.next())
                {

               ui->le_name->setText(query.value(0).toString());
               ui->le_prename->setText(query.value(1).toString());
                ui->Le_age->setText(query.value(2).toString());
                ui->le_Id->setText(query.value(3).toString());

}}
            else
                QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}





