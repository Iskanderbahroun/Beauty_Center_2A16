#include "fournisseurs.h"
#include "ui_fournisseurs.h"
#include "Fournisseur.h"
#include <QIntValidator>
#include "QSqlQuery"
#include "QStringListModel"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "historique.h"

Fournisseurs::Fournisseurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fournisseurs)
{
    ui->setupUi(this);
    ui->ges_label_logo->setPixmap(QPixmap("C:/Users/Iskander/Documents/work/QT/Project/interfacefournisseur/log.png"));
    ui->labellogo->setPixmap(QPixmap("C:/Users/Iskander/Documents/work/QT/Project/interfacefournisseur/log.png"));


    ui->le_id->setValidator(new QIntValidator(0,99999999,this));
    ui->le_numtel->setValidator(new QIntValidator(0,999999999,this));
ui->tabfournisseur->setModel(F.afficher());
ui->tableView_email->setModel(F.afficheremail());

ui->comboBox->setModel(F.afficher());
}

Fournisseurs::~Fournisseurs()
{
    delete ui;
}

void Fournisseurs::on_pb_ajouter_clicked()
{

    int id=ui->le_id->text().toInt();
    int numtel=ui->le_numtel->text().toInt();
    QString nom=ui->le_nom->text();
    QString qualite=ui->Le_qal->text();
    QString category =ui->Le_cat->text();
    QString Email =ui->Le_email->text();
   Fournisseur F(id,numtel,nom,qualite,category,Email);
   bool test=F.ajouter();
   QMessageBox msgBox;
   if(test){
       msgBox.setText("ajout avec succes");
      H.saveajouter();

}
   else
       msgBox.setText("echec");
   msgBox.exec();
   ui->tabfournisseur->setModel(F.afficher());
ui->comboBox->setModel(F.afficher());





}


void Fournisseurs::on_pb_supp_clicked()
{
   int id =ui->comboBox->currentText().toInt();
    bool test=F.supprimer(id);

    if(test){
        H.savesupp();
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("supression effectué .\n"
                                "Click Ok to exit."), QMessageBox::Ok);}
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("échec suprresion.\n"
                                "Click cancel to exit."), QMessageBox::Cancel);
    ui->tabfournisseur->setModel(F.afficher());
ui->comboBox->setModel(F.afficher());
}

void Fournisseurs::on_pb_modifier_clicked()
{
    int id = ui->le_id->text().toInt();
     int numtel = ui->le_numtel->text().toInt();
       QString nom= ui->le_nom->text();
       QString qualite= ui->Le_qal->text();
       QString category =ui->Le_cat->text();
       QString Email =ui->Le_email->text();

     Fournisseur F(id,numtel,nom,qualite,category,Email);


     bool test=F.modifier(id,numtel,nom,qualite,category,Email);
     if(test)
   {ui->tabfournisseur->setModel(F.afficher());
         H.savemodifier();
   QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                     QObject::tr("invite modifiée.\n"
                                 "Click ok to exit."), QMessageBox::Ok);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}






void Fournisseurs::on_comboBox_activated()
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
                ui->Le_email->setText(query.value(5).toString());
}}
            else
                QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}

void Fournisseurs::on_trie_ref_clicked()
{
 ui->tabfournisseur->setModel(F.trinom());

}

void Fournisseurs::on_trie_cat_clicked()
{
    ui->tabfournisseur->setModel(F.tricategory());

}

void Fournisseurs::on_trie_qual_clicked()
{
    ui->tabfournisseur->setModel(F.triqual());

}

void Fournisseurs::on_recher_edit_textChanged()
{

    {
        Fournisseur F;


    QString nom = ui->recher_edit->text();
     QString qualite = ui->recher_edit->text();
      int id = ui->recher_edit->text().toInt();
    F.recherche(ui->tabfournisseur,nom,qualite,id);
    if (ui->recher_edit->text().isEmpty())
    {
       ui->tabfournisseur->setModel(F.afficher());
    }
    }
}

void Fournisseurs::on_pushButton_browse_email_clicked()
{
    files.clear();

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

void Fournisseurs::on_pushButton_send_email_clicked()
{
    //    QSslConfiguration sslCfg = QSslConfiguration::defaultConfiguration();
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
void   Fournisseurs::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "email" ), tr( "Message sent.\n\n" ) );
    ui->lineEdit_to_email->clear();
    ui->lineEdit_subject_email->clear();
    ui->lineEdit_atchmnt_email->clear();
    ui->textEdit_email->clear();
    ui->lineEdit_psswrd_email->clear();
}


