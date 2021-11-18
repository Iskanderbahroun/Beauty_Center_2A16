#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materiel.h"
#include <QMessageBox>
#include<QIntValidator>//
#include "QSqlQuery" //  pour acceder a la base de donnees
#include"smtp.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString language = "FR";
    ui->le_reference->setValidator(new QIntValidator(0, 99999999, this)); // controle de saisir mta l reference
    ui->tab_materiel->setModel(M.afficher());
    ui->comboBox->setModel(M.afficher());
    ui->comboBox_2->addItem("FR");
    ui->comboBox_2->addItem("ENG");
}
QString language = "FR";
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
  language = ui->comboBox_2->currentText();

  if(language == "FR"){
      ui->label->setText("Gestion des matériels ");
      ui->pushButton_4->setText("Trier par reference");
      ui->pushButton_5->setText("trier par nom");
      ui->pushButton_6->setText("trier par couleur");
      ui->stock_btn->setText("voir stock ");
      ui->le_reference_3->setPlaceholderText("chercher..."); // besh ytala3ha gris fate7

     ui->label_4->setText("Nom ");
     ui->label_3->setText("couleur");
     ui->label_2->setText("référence ");
     ui->label_26->setText("id fourniseur");
     ui->Modifier->setText("Modifier");
     ui->supprimer->setText("Supprimer");
     ui->Pb_Ajouter->setText("Ajouter");









  }else{
      ui->label->setText("Products managment");
      ui->pushButton_4->setText("order by reference");
      ui->pushButton_5->setText("order by name");
      ui->pushButton_6->setText("order by color ");
      ui->stock_btn->setText("see stock ");
      ui->le_reference_3->setPlaceholderText("find...");


      ui->label_4->setText("Name ");
      ui->label_3->setText("color");
      ui->label_2->setText("reference ");
      ui->label_26->setText("id fourniseur");
      ui->Modifier->setText("Modify");
      ui->supprimer->setText("delete");
      ui->Pb_Ajouter->setText("Add");









  }


}

void MainWindow::on_Pb_Ajouter_clicked()
{
    int reference=ui->le_reference->text().toInt();
    int id_fourniseur=ui->le_id_fourniseur->text().toInt();
     QString nom=ui->le_nom->text();
     QString couleur=ui->le_couleur->text();

    Materiel M(nom,couleur,reference,id_fourniseur);
   bool test= M.ajouter();
    if(test){
        if(language == "FR"){
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("Ajout effectué .\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
        }else{
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("Added correctly .\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
        }

    }

    else{


        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("échec ajout.\n"
                                "Click cancel to exit."), QMessageBox::Cancel);
    }


    ui->le_nom->clear();
    ui->le_reference->clear();
    ui->le_id_fourniseur->clear();
    ui->le_couleur->clear();
ui->tab_materiel->setModel(M.afficher());
ui->comboBox->setModel(M.afficher());
 }

void MainWindow::on_supprimer_clicked()
{
    QString Nom =ui->comboBox->currentText();
        bool test=M.supprimer(Nom);

        if(test){
            if (language == "FR") {
                QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("Suppression effectué .\n"
                                        "Click Ok to exit."), QMessageBox::Ok);
            }else{

            }

        }

        else{
            if(language == "FR"){
                QMessageBox::critical(nullptr, QObject::tr("not ok"),
                            QObject::tr("échec sup.\n"
                                        "Click cancel to exit."), QMessageBox::Cancel);
            }else{

            }

        }

        ui->le_nom->clear();
        ui->le_reference->clear();
        ui->le_id_fourniseur->clear();
        ui->le_couleur->clear();
        ui->tab_materiel->setModel(M.afficher());
        ui->comboBox->setModel(M.afficher());

}

void MainWindow::on_Modifier_clicked()
{
    int reference=ui->le_reference->text().toInt();
    int id_fourniseur=ui->le_id_fourniseur->text().toInt();
     QString nom=ui->le_nom->text();
     QString couleur=ui->le_couleur->text();
    Materiel M(couleur,nom,reference,id_fourniseur);
  bool test= M.modifier( reference,  id_fourniseur,   nom,couleur);
    if(test)
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("Modification effectué .\n"
                                "Click Ok to exit."), QMessageBox::Ok);

    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("échec modification.\n"
                                "Click cancel to exit."), QMessageBox::Cancel);
ui->le_nom->clear();
ui->le_reference->clear();
ui->le_id_fourniseur->clear();
ui->le_couleur->clear();
ui->tab_materiel->setModel(M.afficher());
ui->comboBox->setModel(M.afficher());
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{

    QString Nom = ui->comboBox->currentText();

                QSqlQuery query;
                query.prepare("select * from MATERIEL where NOM='"+Nom+"'");

                if(query.exec()){

                    while(query.next())
                    {
                        ui->le_nom->setText(query.value(0).toString());
                   ui->le_couleur->setText(query.value(1).toString());

                    ui->le_reference->setText(query.value(2).toString());
                    ui->le_id_fourniseur->setText(query.value(3).toString());

    }}
                else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_4_clicked()
{
    Materiel M;
        ui->tab_materiel->setModel(M.tri());
}



void MainWindow::on_pushButton_5_clicked()
{
    Materiel M;
        ui->tab_materiel->setModel(M.tri1());
}

void MainWindow::on_pushButton_6_clicked()
{
    Materiel M;
        ui->tab_materiel->setModel(M.tri2());
}

void MainWindow::on_le_reference_3_textChanged(const QString &arg1)
{

    Materiel M;


QString nom = ui->le_reference_3->text();
 QString couleur= ui->le_reference_3->text();
  int reference = ui->le_reference_3->text().toInt();
M.recherche(ui->tab_materiel,nom,couleur,reference);
if (ui->le_reference_3->text().isEmpty())
{
   ui->tab_materiel->setModel(M.afficher());
}
}


void MainWindow::on_stock_btn_clicked()
{
  QString nom = ui->le_reference_3->text();

  int somme = M.calculer_stock(nom);
  QString id_string=QString::number(somme);
  ui->label_5->setText(id_string);

}




void MainWindow::on_pushButton_browse_email_clicked()
{files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->lineEdit_atchmnt_email->setText( fileListString );

}

void MainWindow::on_pushButton_send_email_clicked()
{//    QSslConfiguration sslCfg = QSslConfiguration::defaultConfiguration();
    //    QList<QSslCertificate> ca_list = sslCfg.caCertificates();
    //    QList<QSslCertificate> ca_new = QSslCertificate::fromData("CaCertificates");
    //    ca_list += ca_new;

    //    sslCfg.setCaCertificates(ca_list);

    //    sslCfg.setProtocol( QSsl::TlsV1SslV3 );

    //    QSslConfiguration::setDefaultConfiguration(sslCfg);

        qDebug() <<  "Loaded SSL Library version: " << QSslSocket::sslLibraryVersionString();

        // ui->lineEdit_to_email->setText("email_ili_bch_tab3athlou@gmail.com");
        // ui->lineEdit_from_email->setText("email_ili_bch_tab3ith_minou@gmail.com");
        // ui->lineEdit_psswrd_email->setText("mdp mta3 l email ili bch tab3th minou");

        // ui->lineEdit_subject_email->setText("test subject");
        // ui->textEdit_email->setText("test text");

        QString from = ui->lineEdit_from_email->text();
        QString to = ui->lineEdit_to_email->text();
        QString subject = ui->lineEdit_subject_email->text();
        QString password = ui->lineEdit_psswrd_email->text();
        QString email_text = ui->textEdit_email->toPlainText();

        Smtp* smtp = new Smtp(from, password);
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        if( !files.isEmpty() )
            smtp->sendMail(from, to, subject, email_text, files);
        else
            smtp->sendMail(from, to, subject, email_text);

}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "email" ), tr( "Message sent.\n\n" ) );
    ui->lineEdit_to_email->clear();
    ui->lineEdit_subject_email->clear();
    ui->lineEdit_atchmnt_email->clear();
    ui->textEdit_email->clear();
    ui->lineEdit_psswrd_email->clear();
}
