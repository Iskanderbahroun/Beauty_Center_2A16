#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include "stats.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_91->setText("Store closed");
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
    ui->stackedWidget->setCurrentIndex(0);
    ui->Le_num7->setValidator(new QIntValidator(0,99999999,this));
       ui->Le_prix7->setValidator(new QIntValidator(0,999999999,this));
       ui->Le_Q7->setValidator(new QIntValidator(0,999999999,this));
    ui->tableView7->setModel(P.afficher());
ui->comboBox_72->setModel(P.afficher());
    ui->tab_client->setModel(c.afficher());
    ui->comboBox_35->setModel(c.afficher());
    QString language = "FR";
    ui->le_reference3->setValidator(new QIntValidator(0, 99999999, this)); // controle de saisir mta l reference
    ui->tab_materiel->setModel(M.afficher());
    ui->comboBox32->setModel(M.afficher());
    ui->comboBox_32->addItem("FR");
    ui->comboBox_32->addItem("ENG");

    ui->le_id6->setValidator(new QIntValidator(0,99999999,this));
    ui->le_numtel6->setValidator(new QIntValidator(0,999999999,this));
ui->tabfournisseur->setModel(F.afficher());
ui->tableView_email6->setModel(F.afficheremail());

ui->comboBox6->setModel(F.afficher());
ui->comboBox_26->setModel(F.afficher());
mMediaPlayer = new QMediaPlayer(this);

connect(mMediaPlayer,&QMediaPlayer::positionChanged, [&](quint64 pos)
{
    ui->avance_2->setValue(pos);
});
connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](quint64 dur)
{
    ui->avance_2->setMaximum(dur);
});
ui->le_cin_2->setValidator( new QIntValidator(0,99999999, this) );
ui->le_age_2->setValidator( new QIntValidator(0,99, this) );
ui->le_salaire_2->setValidator( new QIntValidator(0,9999, this) );
ui->tab_employes_2->setModel(E.afficher());
ui->comboBox_12->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;

}
QString  cheminAbsolu;
QString language = "FR";
void MainWindow::on_login_clicked()
{
    {
           QString username = ui->lineEdit_username->text();
           QString password = ui->lineEdit_password->text();

           if(username ==  "emna" && password == "emna") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
               ui->stackedWidget->setCurrentIndex(1);
           }
         else if(username ==  "sarah" && password == "sarah") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
               ui->stackedWidget->setCurrentIndex(2);
           }
           else if(username ==  "ibtihel" && password == "ibtihel") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
               ui->stackedWidget->setCurrentIndex(3);
           }
           else if(username ==  "youssef" && password == "youssef") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
               ui->stackedWidget->setCurrentIndex(4);
           }
           else if(username ==  "skander" && password == "skander") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
              ui->stackedWidget->setCurrentIndex(5);
           }
           else if(username ==  "ghaith" && password == "ghaith") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
               ui->stackedWidget->setCurrentIndex(6);
           }
           else if(username ==  "admin" && password == "admin"){
               QMessageBox::information(this, "Login", "Username and password is correct");
               ui->stackedWidget->setCurrentIndex(7);
           }
           else {
               QMessageBox::warning(this,"Login", "Username and password is not correct");
           }

       }
ui->lineEdit_username->clear();
ui->lineEdit_password->clear();
}

void MainWindow::on_pb_ajouter6_clicked()
{
    int id=ui->le_id6->text().toInt();
    int numtel=ui->le_numtel6->text().toInt();
    QString nom=ui->le_nom6->text();
    QString qualite=ui->Le_qal6->text();
    QString category =ui->Le_cat6->text();
    QString Email =ui->Le_email6->text();
    QString adresse= ui->Le_adresse6->text();
   Fournisseur F(id,numtel,nom,qualite,category,Email,adresse);
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
ui->comboBox6->setModel(F.afficher());
}

void MainWindow::on_pb_modifier6_clicked()
{
    int id=ui->le_id6->text().toInt();
    int numtel=ui->le_numtel6->text().toInt();
    QString nom=ui->le_nom6->text();
    QString qualite=ui->Le_qal6->text();
    QString category =ui->Le_cat6->text();
    QString Email =ui->Le_email6->text();
    QString adresse= ui->Le_adresse6->text();

     Fournisseur F(id,numtel,nom,qualite,category,Email,adresse);


     bool test=F.modifier(id,numtel,nom,qualite,category,Email,adresse);
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

void MainWindow::on_pb_supp6_clicked()
{
    int id =ui->comboBox6->currentText().toInt();
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
 ui->comboBox6->setModel(F.afficher());
}

void MainWindow::on_comboBox6_activated(const QString &arg1)
{
    int id = ui->comboBox6->currentText().toInt();
     QString id_string= QString::number(id);
            QSqlQuery query;
            query.prepare("select * from FOURNISSEUR where ID='"+id_string+"'");

            if(query.exec()){

                while(query.next())
                {
                    ui->le_numtel6->setText(query.value(1).toString());
               ui->le_id6->setText(query.value(0).toString());

                ui->le_nom6->setText(query.value(2).toString());
                ui->Le_qal6->setText(query.value(3).toString());
                ui->Le_cat6->setText(query.value(4).toString());
                ui->Le_email6->setText(query.value(5).toString());
                ui->Le_adresse6->setText(query.value(6).toString());
}}
            else
                QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_trie_ref6_clicked()
{
    ui->tabfournisseur->setModel(F.trinom());
}

void MainWindow::on_trie_cat6_clicked()
{
    ui->tabfournisseur->setModel(F.tricategory());
}

void MainWindow::on_trie_qual6_clicked()
{
    ui->tabfournisseur->setModel(F.triqual());
}

void MainWindow::on_pushButton_browse_email6_clicked()
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

    ui->lineEdit_atchmnt_email6->setText( fileListString );
}

void MainWindow::on_pushButton_send_email6_clicked()
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
        // ui->textEdit6_email->setText("test text");

        QString from = ui->lineEdit_from_email6->text();
        QString to = ui->lineEdit_to_email6->text();
        QString subject = ui->lineEdit_subject_email6->text();
        QString password = ui->lineEdit_psswrd_email6->text();
        QString email_text = ui->textEdit_email6->toPlainText();

        Smtp* smtp = new Smtp(from, password);
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        if( !files.isEmpty() )
            smtp->sendMail(from, to, subject, email_text, files);
        else
            smtp->sendMail(from, to, subject, email_text);

}

void MainWindow::on_comboBox_26_activated(const QString &arg1)
{
    int id = ui->comboBox_26->currentText().toInt();

         QString id_string= QString::number(id);
                QSqlQuery query;
                query.prepare("select * from FOURNISSEUR where ID='"+id_string+"'");

                if(query.exec()){

                    while(query.next())
                    { ui->textEdit6->setText(query.value(6).toString());


                        if  (ui->textEdit6->toPlainText()== "tunis")
                                    {ui->label_pic->clear();

                              QPixmap pix(":/img/img/tunis.png");
                             int w = ui->label_pic->width();
                             int h = ui->label_pic->height();
                              ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
                          }

                           else if(ui->textEdit6->toPlainText()=="sousse")
                             { ui->label_pic->clear();
                                 QPixmap pix(":/img/img/sousse.png");
                                 int w = ui->label_pic->width();
                                 int h = ui->label_pic->height();
                                  ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                             }
                             else if(ui->textEdit6->toPlainText()=="bizerte")
                                {ui->label_pic->clear();
                                    QPixmap pix(":/img/img/bizerte.png");
                                    int w = ui->label_pic->width();
                                    int h = ui->label_pic->height();
                                     ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

                                }
                             else if(ui->textEdit6->toPlainText()=="nabeul")
                                {ui->label_pic->clear();
                                    QPixmap pix(":/img/img/nabeul.png");
                                    int w = ui->label_pic->width();
                                    int h = ui->label_pic->height();
                                     ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                }
                             else if(ui->textEdit6->toPlainText()=="jendouba")
                                {ui->label_pic->clear();
                                    QPixmap pix(":/img/img/jendouba.png");
                                    int w = ui->label_pic->width();
                                    int h = ui->label_pic->height();
                                     ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                }
                             else if(ui->textEdit6->toPlainText()=="siliana")
                                {ui->label_pic->clear();
                                    QPixmap pix(":/img/img/siliana.png");
                                    int w = ui->label_pic->width();
                                    int h = ui->label_pic->height();
                                     ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


                                }
                             else
                             {
                                 QMessageBox msgBox;

                                        msgBox.setText("region inconnu");
                                    msgBox.exec();}








                    }} else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_recher_edit6_textChanged(const QString &arg1)
{
    {
        Fournisseur F;


    QString nom = ui->recher_edit6->text();
     QString qualite = ui->recher_edit6->text();
      int id = ui->recher_edit6->text().toInt();
    F.recherche(ui->tabfournisseur,nom,qualite,id);
    if (ui->recher_edit6->text().isEmpty())
    {
       ui->tabfournisseur->setModel(F.afficher());
    }
    }
}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "email" ), tr( "Message sent.\n\n" ) );
    ui->lineEdit_to_email6->clear();
    ui->lineEdit_subject_email6->clear();
    ui->lineEdit_atchmnt_email6->clear();
    ui->textEdit_email6->clear();
    ui->lineEdit_psswrd_email6->clear();
}



void MainWindow::on_pb_ajouter4_clicked()
{
    int code=ui->le_code4->text().toInt();
    int prix=ui->le_prix4->text().toInt();
    QString type=ui->le_type4->text();
    //QString type =ui->comboBox->currentIndex();
    int cin_e=ui->le_cin4->text().toInt();
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

QString MainWindow::on_pb_image4_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if(QString::compare(filename, QString()) !=0)
    {
        QImage image;

        bool valid = image.load(filename);
        if(valid)
        {
             ui->tb_image4->setPixmap(QPixmap::fromImage(image));
             QFileInfo fileinfo(filename);
             cheminAbsolu =fileinfo.filePath();
             ui->label_image4->setText(cheminAbsolu);
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
}}

void MainWindow::on_pb_modifier4_clicked()
{
    int code=ui->le_code4->text().toInt();
    int prix=ui->le_prix4->text().toInt();
    QString type=ui->le_type4->text();
    int cin_e=ui->le_cin4->text().toInt();
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

         ui->le_code4->clear();
         ui->le_prix4->clear();
         ui->le_type4->clear();
         ui->le_cin4->clear();
}

void MainWindow::on_pb_supprimer4_clicked()
{

}

void MainWindow::on_pb_chercher_code4_clicked()
{QSqlQueryModel *model = new QSqlQueryModel();
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
         ui->tableView4->setModel(model);
         ui->tableView4->show();


    }
           else{
               QMessageBox::information(nullptr, QObject::tr("Chercher un offre"),
                           QObject::tr("Erreur .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           }



}

void MainWindow::on_pb_chercher_prix4_clicked()
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
         ui->tableView4->setModel(model);
         ui->tableView4->show();


    }
           else{
               QMessageBox::information(nullptr, QObject::tr("Chercher un offre"),
                           QObject::tr("Erreur .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           }
}

void MainWindow::on_pb_chercher_type4_clicked()
{QSqlQueryModel *model = new QSqlQueryModel();
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
         ui->tableView4->setModel(model);
         ui->tableView4->show();


    }
           else{
               QMessageBox::information(nullptr, QObject::tr("Chercher un offre"),
                           QObject::tr("Erreur .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           }


}

void MainWindow::on_pb_trier_code4_clicked()
{QMessageBox msgBox ;



    bool test=o.tricode();
    if(test){


  QMessageBox::information(nullptr, QObject::tr("trier les  offres par code"),
                    QObject::tr("tri  effectué .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

   ui->tableView4->setModel(o.tricode());

}  else
      QMessageBox::critical(nullptr, QObject::tr("trier les  offres par code"),
QObject::tr("tri non effectué\n"
                                        "Click cancel to exit."), QMessageBox::Cancel );


}

void MainWindow::on_pb_trier_prix4_clicked()
{
    QMessageBox msgBox ;



                   bool test=o.triprix();
                   if(test){
 ui->tableView4->setModel(o.triprix());

                 QMessageBox::information(nullptr, QObject::tr("trier les  offres par prix"),
                                   QObject::tr("tri  effectué .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);



               }  else
                     QMessageBox::critical(nullptr, QObject::tr("trier les  offres par prix"),
              QObject::tr("tri non effectué\n"
                                                       "Click cancel to exit."), QMessageBox::Cancel );

}

void MainWindow::on_pb_trier_type4_clicked()
{
    QMessageBox msgBox ;



                   bool test=o.tritype();
                   if(test){
 ui->tableView4->setModel(o.tritype());

                 QMessageBox::information(nullptr, QObject::tr("trier les  offres par type"),
                                   QObject::tr("tri  effectué .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);



               }  else
                     QMessageBox::critical(nullptr, QObject::tr("trier les  offres par type"),
              QObject::tr("tri non effectué\n"
                                                       "Click cancel to exit."), QMessageBox::Cancel );
}

void MainWindow::on_pb_video4_clicked()
{
    Video=new video(this);
    Video->show();
}

void MainWindow::on_pb_stat4_clicked()
{
    Statistique=new statistique(this);
    Statistique->show();
}
void MainWindow::on_pb_ajout_2_clicked()
{  int Cin=ui->le_cin_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    int Age=ui->le_age_2->text().toInt();
    QString Role=ui->le_role_2->text();
    int Salaire=ui->le_salaire_2->text().toInt();


  Employe E(Cin,nom,prenom,Age,Role,Salaire);
bool test=E.ajouter();
QMessageBox msgBox;
if (test)
{msgBox.setText("Ajout avec succes. ");
    ui->tab_employes_2->setModel(E.afficher());
ui->comboBox_12->setModel(E.afficher());}}




void MainWindow::on_le_supprimer_2_clicked()
{
    Employe E1;
    int id = ui->comboBox_12->currentText().toInt();
        bool test=E1.supprimer(id);
QMessageBox msgBox ;
        if(test){
            msgBox.setText("supression effectué .\n"
                            "Click Ok to exit.");
            ui->tab_employes_2->setModel(E.afficher());
            ui->comboBox_12->setModel(E.afficher());

        }else
            msgBox.setText("Echec de suppression" );
                    msgBox.exec();
            }



void MainWindow::on_le_modifier_2_clicked()
{
    int Cin = ui->le_cin_2->text().toInt();
     QString Nom= ui->le_nom_2->text();
     QString Prenom= ui->le_prenom_2->text();
      int Age = ui->le_age_2->text().toInt();
      QString Role=ui->le_role_2->text();
      int Salaire=ui->le_salaire_2->text().toInt();

       Employe E(Cin,Nom,Prenom,Age,Role,Salaire);


       bool test=E.modifier(Cin,Nom,Prenom,Age,Role,Salaire);
       if(test)
     {ui->tab_employes_2->setModel(E.afficher());
           ui->comboBox_12->setModel(E.afficher());
     QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                       QObject::tr("invite modifiée.\n"
                                   "Click ok to exit."), QMessageBox::Ok);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
  }






  void MainWindow::on_comboBox_12_activated(const QString &arg1)
  {
      int Cin = ui->comboBox_12->currentText().toInt();
       QString Cin_string= QString::number(Cin);
              QSqlQuery query;
              query.prepare("select * from EMPLOYES where CIN='"+Cin_string+"'");

              if(query.exec()){

                  while(query.next())
                  {
                      ui->le_cin_2->setText(query.value(0).toString());
                 ui->le_nom_2->setText(query.value(1).toString());

                  ui->le_prenom_2->setText(query.value(2).toString());
                  ui->le_age_2->setText(query.value(3).toString());
                  ui->le_role_2->setText(query.value(4).toString());
                  ui->le_salaire_2->setText(query.value(5).toString());
  }}
              else
                  QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

  }

void MainWindow::on_le_trie_par_nom_2_clicked()
{

     ui->tab_employes_2->setModel(E.triNom());
    }


void MainWindow::on_le_trie_age_2_clicked()
{
  ui->tab_employes_2->setModel(E.triAge());
}

void MainWindow::on_le_trie_salaire_2_clicked()
{
   ui->tab_employes_2->setModel(E.triSalaire());
}




void MainWindow::on_rech_2_textChanged(const QString &arg1)
{
    Employe E;

        int Cin = ui->rech_2->text().toInt();
         int Age = ui->rech_2->text().toInt();
         int Salaire = ui->rech_2->text().toInt();

            E.rechercher(ui->tab_employes_2,Cin,Age,Salaire);
            if (ui->rech_2->text().isEmpty())
            {
               ui->tab_employes_2->setModel(E.afficher());
            }
}

void MainWindow::on_export_pdf_2_clicked()
{
    {
        E.telechargerPDF();

         QMessageBox::information(nullptr,QObject::tr("OK"),
                    QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);

    }
}
void MainWindow::on_abrir_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Abrir");
    if (filename.isEmpty())
    {
        return ;
    }
    mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));

    mMediaPlayer->setVolume(ui->volum_2->value());
    on_play_2_clicked();
}

void MainWindow::on_play_2_clicked()
{
    mMediaPlayer->play();

}

void MainWindow::on_pause_2_clicked()
{
    mMediaPlayer->pause();

}

void MainWindow::on_stop_2_clicked()
{
    mMediaPlayer->stop();


}
void MainWindow::on_mute_2_clicked()
{
    if(ui->mute_2->text()=="Mute")
    {mMediaPlayer->setMuted(true);
        ui->mute_2->setText("Unmute");}
    else
    {mMediaPlayer->setMuted(false);
        ui->mute_2->setText("Mute");}

}

void MainWindow::on_volum_2_valueChanged(int  value)
{
    mMediaPlayer->setVolume(value);
}
void MainWindow::on_comboBox_32_activated(const QString &arg1)
{
  language = ui->comboBox_32->currentText();

  if(language == "FR"){
      ui->label_55->setText("Gestion des matériels ");
      ui->pushButton_34->setText("Trier par reference");
      ui->pushButton_35->setText("trier par nom");
      ui->pushButton_36->setText("trier par couleur");
      ui->stock_btn3->setText("voir stock ");
      ui->le_reference_3->setPlaceholderText("chercher..."); // besh ytala3ha gris fate7

     ui->Label_fnom->setText("Nom ");
     ui->Label_fcouleur->setText("couleur");
     ui->Label_fRef->setText("référence ");
     ui->Label_fFour->setText("id fourniseur");
     ui->Modifier3->setText("Modifier");
     ui->supprimer3->setText("Supprimer");
     ui->Pb_Ajouter3->setText("Ajouter");









  }else{
      ui->label_55->setText("Products managment");
      ui->pushButton_34->setText("order by reference");
      ui->pushButton_35->setText("order by name");
      ui->pushButton_36->setText("order by color ");
      ui->stock_btn3->setText("see stock ");
      ui->le_reference_3->setPlaceholderText("find...");


      ui->Label_fnom->setText("Name ");
      ui->Label_fcouleur->setText("color");
      ui->Label_fRef->setText("reference ");
      ui->Label_fFour->setText("id fourniseur");
      ui->Modifier3->setText("Modify");
      ui->supprimer3->setText("delete");
      ui->Pb_Ajouter3->setText("Add");









  }


}

void MainWindow::on_Pb_Ajouter3_clicked()
{
    int reference=ui->le_reference3->text().toInt();
    int id_fourniseur=ui->le_id_fourniseur3->text().toInt();
     QString nom=ui->le_nom3->text();
     QString couleur=ui->le_couleur3->text();

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


    ui->le_nom3->clear();
    ui->le_reference3->clear();
    ui->le_id_fourniseur3->clear();
    ui->le_couleur3->clear();
ui->tab_materiel->setModel(M.afficher());
ui->comboBox32->setModel(M.afficher());
 }

void MainWindow::on_supprimer3_clicked()
{
    QString Nom =ui->comboBox32->currentText();
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

        ui->le_nom3->clear();
        ui->le_reference3->clear();
        ui->le_id_fourniseur3->clear();
        ui->le_couleur3->clear();
        ui->tab_materiel->setModel(M.afficher());
        ui->comboBox32->setModel(M.afficher());

}

void MainWindow::on_Modifier3_clicked()
{
    int reference=ui->le_reference3->text().toInt();
    int id_fourniseur=ui->le_id_fourniseur3->text().toInt();
     QString nom=ui->le_nom3->text();
     QString couleur=ui->le_couleur3->text();
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
ui->le_nom3->clear();
ui->le_reference3->clear();
ui->le_id_fourniseur3->clear();
ui->le_couleur3->clear();
ui->tab_materiel->setModel(M.afficher());
ui->comboBox32->setModel(M.afficher());
}

void MainWindow::on_comboBox32_activated(const QString &arg1)
{

    QString Nom = ui->comboBox32->currentText();

                QSqlQuery query;
                query.prepare("select * from MATERIEL where NOM='"+Nom+"'");

                if(query.exec()){

                    while(query.next())
                    {
                        ui->le_nom3->setText(query.value(0).toString());
                   ui->le_couleur3->setText(query.value(1).toString());

                    ui->le_reference3->setText(query.value(2).toString());
                    ui->le_id_fourniseur3->setText(query.value(3).toString());

    }}
                else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_34_clicked()
{
    Materiel M;
        ui->tab_materiel->setModel(M.tri());
}



void MainWindow::on_pushButton_35_clicked()
{
    Materiel M;
        ui->tab_materiel->setModel(M.tri1());
}

void MainWindow::on_pushButton_36_clicked()
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


void MainWindow::on_stock_btn3_clicked()
{
  QString nom = ui->le_reference_3->text();

  int somme = M.calculer_stock(nom);
  QString id_string=QString::number(somme);
  ui->label_5->setText(id_string);

}




void MainWindow::on_pushButton_browse_email3_clicked()
{files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->lineEdit_atchmnt_email3->setText( fileListString );

}

void MainWindow::on_pushButton_send_email3_clicked()
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

        QString from = ui->lineEdit_from_email3->text();
        QString to = ui->lineEdit_to_email3->text();
        QString subject = ui->lineEdit_subject_email3->text();
        QString password = ui->lineEdit_psswrd_email3->text();
        QString email_text = ui->textEdit_email3->toPlainText();

        Smtp* smtp = new Smtp(from, password);
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        if( !files.isEmpty() )
            smtp->sendMail(from, to, subject, email_text, files);
        else
            smtp->sendMail(from, to, subject, email_text);

}
void   MainWindow::mailSent3(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "email" ), tr( "Message sent.\n\n" ) );
    ui->lineEdit_to_email3->clear();
    ui->lineEdit_subject_email3->clear();
    ui->lineEdit_atchmnt_email3->clear();
    ui->textEdit_email3->clear();
    ui->lineEdit_psswrd_email3->clear();
}
void MainWindow::on_pb_ajouter5_clicked()
{
    int cin=ui->le_cin_5->text().toInt();
    QString nom=ui->le_nom_5->text();
    QString prenom=ui->le_prenom_5->text();
    int tel=ui->le_tel5->text().toInt();
    QString adresse=ui->le_adresse5->text();

client c (cin,nom,prenom,tel,adresse);
bool test=c.ajouter();
if(test)

  { ui->comboBox_35->setModel(c.afficher());
    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajout effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
   { QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("ajout non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
 ui->tab_client->setModel(c.afficher());
}

void MainWindow::on_pb_modifier5_clicked()
{
    int cin=ui->le_cin_5->text().toInt();
    QString nom=ui->le_nom_5->text();
    QString prenom=ui->le_prenom_5->text();
    int tel=ui->le_tel5->text().toInt();
    QString adresse=ui->le_adresse5->text();

        client c (cin,nom,prenom,tel,adresse);
        bool test=c.modifier(cin,nom,prenom,tel,adresse);
            if(test)
          {ui->tab_client->setModel(c.afficher());
                ui->comboBox_35->setModel(c.afficher());
          QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                            QObject::tr("invite modifiée.\n"
                                        "Click ok to exit."), QMessageBox::Ok);

          }
            else
                QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer5_clicked()
{
int cin=ui->le_cin_5->text().toInt();
bool test=c.supprimer(cin);
if(test)
{ ui->comboBox_35->setModel(c.afficher());
    QMessageBox::information(nullptr, QObject::tr("ok"),
                   QObject::tr("suppression effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
      { QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                   QObject::tr("suppression non effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }

}

void MainWindow::on_pb_afficher5_clicked()
{
    ui->tab_client->setModel(c.afficher());
    ui->comboBox_35->setModel(c.afficher());

}

void MainWindow::on_pb_importer5_clicked()
{
QString filename= QFileDialog::getOpenFileName(this ,tr("choisir"),"",tr("photos(*.png)"));
if(QString::compare(filename, QString())!=0)
{
    QImage photo;
    bool valid=photo.load(filename);
    if(valid)
    {   photo=photo.scaledToWidth(ui->label_9->width(), Qt::SmoothTransformation);
        ui->label_9->setPixmap(QPixmap::fromImage(photo));
    }
    else
    {
    //error
    }
}

}


void MainWindow::on_comboBox_35_activated(const QString &arg1)
{
    int cin = ui->comboBox_35->currentText().toInt();
         QString cin_string= QString::number(cin);
                QSqlQuery query;
                query.prepare("select * from client where cin='"+cin_string+"'");

                if(query.exec()){

                    while(query.next())
                    {

                   ui->le_cin_5->setText(query.value(0).toString());
                    ui->le_nom_5->setText(query.value(1).toString());
                    ui->le_prenom_5->setText(query.value(2).toString());
                    ui->le_tel5->setText(query.value(3).toString());
                    ui->le_adresse5->setText(query.value(4).toString());
               }
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_trier_prenom5_clicked()
{
ui->tab_client->setModel(c.trierprenom());
}

void MainWindow::on_trier_annees5_clicked()
{
ui->tab_client->setModel(c.trieradresse());
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)   ///mtaa el recherche
{
   client c;

    QString rech = ui->lineEdit_5->text();
        c.recherche(ui->tab_client,rech);
        if (ui->lineEdit_5->text().isEmpty())
        {
            ui->tab_client->setModel(c.afficher());
        }
}



void MainWindow::on_tab_client_activated(const QModelIndex &index)
{client f;
  QString val=ui->tab_client->model()->data(index).toString();
  QSqlQuery query;
  query.prepare("select * from client where cin='"+val+"'");

  if(query.exec()){

      while(query.next())
      {

     ui->le_cin_5->setText(query.value(0).toString());
      ui->le_nom_5->setText(query.value(1).toString());
      ui->le_prenom_5->setText(query.value(2).toString());
      ui->le_tel5->setText(query.value(3).toString());
      ui->le_adresse5->setText(query.value(4).toString());


 }
  }
  else
      QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


//{

//}

void MainWindow::on_tri_tel5_clicked()
{
    ui->tab_client->setModel(c.triertel());
}



void MainWindow::on_pushButton_stat5_clicked()
{
    QChart* chart_bar = c.chart_pie();
    QChartView* chart_view_bar = new QChartView(chart_bar, ui->label_stat5);
    chart_view_bar->setRenderHint(QPainter::Antialiasing);
    chart_view_bar->setMinimumSize(400,400);
    chart_view_bar->show();
}

void MainWindow::on_tri_freq5_clicked()
{
    ui->tab_client->setModel(c.trierfreq());

}

/*void MainWindow::on_export_excel_clicked()
{
    try
        {
            const QString fileName = "g:\\temp\\kaka2.xlsx";

            ExcelExportHelper helper;

            helper.SetCellValue(1,1,"Test-11");
            helper.SetCellValue(1,2,"Test-12");

            helper.SaveAs(fileName);
        }
        catch (const exception& e)
        {
            QMessageBox::critical(this, "Error - Demo", e.what());
        }
}
*/
void MainWindow::on_pb_ajouter7_clicked()
{
    int Num=ui->Le_num7->text().toInt();
        QString  Marque=ui->Le_Marque7->text();
        QString Nom=ui->Le_nom7->text();
        int Quantite=ui->Le_Q7->text().toInt();
        QString QRCODE=ui->LE_QR7->text();
        int Prix=ui->Le_prix7->text().toInt();
       ProduitsCosmetiques p(Num,QRCODE,Prix,Nom,Quantite,Marque);
       bool test=p.ajouter();
       QMessageBox msgBox;
       if(test)
           msgBox.setText("ajout avec succes");

       else
           msgBox.setText("echec");
       msgBox.exec();
       ui->tableView7->setModel(P.afficher()); //refrech
    ui->comboBox_72->setModel(P.afficher()); //refrech
}

void MainWindow::on_pb_supp7_clicked()
{
    int Num =ui->comboBox_72->currentText().toInt();
        bool test=P.supprimer(Num);

        if(test)
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("supression effectué .\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("échec suprresion.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
        ui->tableView7->setModel(P.afficher());
    ui->comboBox_72->setModel(P.afficher());
}

void MainWindow::on_Modifier7_clicked()
{
    int Num=ui->Le_num7->text().toInt();
        QString  Marque=ui->Le_Marque7->text();
        QString Nom=ui->Le_nom7->text();
        int Quantite=ui->Le_Q7->text().toInt();
        QString QRCODE=ui->LE_QR7->text();
        int Prix=ui->Le_prix7->text().toInt();
       ProduitsCosmetiques p(Num,QRCODE,Prix,Nom,Quantite,Marque);


         bool test=P.modifier(Num,QRCODE,Prix,Nom,Quantite,Marque);
         if(test)
       {ui->tableView7->setModel(P.afficher());
       QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                         QObject::tr("invite modifiée.\n"
                                     "Click ok to exit."), QMessageBox::Ok);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_comboBox_72_activated(const QString &arg1)
{
    int NUM = ui->comboBox_72->currentText().toInt();
         QString id_string= QString::number(NUM);
                QSqlQuery query;
                query.prepare("select * from PRODUITCOSMETIQUE where NUM='"+id_string+"'");

                if(query.exec()){

                    while(query.next())
                    {
                        ui->LE_QR7->setText(query.value(1).toString());
                   ui->Le_num7->setText(query.value(0).toString());

                    ui->Le_Q7->setText(query.value(2).toString());
                    ui->Le_nom7->setText(query.value(3).toString());
                    ui->Le_Marque7->setText(query.value(4).toString());
                    ui->Le_prix7->setText(query.value(5).toString());
    }}
                else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_trierprix7_clicked()
{
    ui->tableView7->setModel(P.triprix());
}

void MainWindow::on_trienom7_clicked()
{
    ui->tableView7->setModel(P.trinom());
}

void MainWindow::on_triemarque7_clicked()
{
    ui->tableView7->setModel(P.triprix());
}


void MainWindow::on_pb_ajouter_27_clicked()
{
    QString qr=ui->LE_QR_27->text();
    if(qr=="1")
          {
              QPixmap pix("C:/Users/asus/Desktop/Beauty_Center_2A16-Fournisseur/1.png");
              int w = ui->label_pic_27->width();
              int h = ui->label_pic_27->height();
               ui->label_pic_27->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


          }
   else if(qr=="2")
          {
              QPixmap pix("C:/Users/asus/Desktop/Beauty_Center_2A16-Fournisseur/2.png");
              int w = ui->label_pic_27->width();
              int h = ui->label_pic_27->height();
               ui->label_pic_27->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


          }
   else if(qr=="3")
          {
              QPixmap pix("C:/Users/asus/Desktop/Beauty_Center_2A16-Fournisseur/3.png");
              int w = ui->label_pic_27->width();
              int h = ui->label_pic_27->height();
               ui->label_pic_27->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


          }
    else
    {
        QMessageBox msgBox;

               msgBox.setText("taper 1 ou 2 ou 3");
           msgBox.exec();

 }


}

void MainWindow::on_pb_stat7_clicked()
{
    Statistiques =new statistiques(this);
    Statistiques->show();
}





void MainWindow::on_pb_deco2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pb_deco3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_deco4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_deco5_clicked()
{
 ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_deco6_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_deco7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}






void MainWindow::on_retour_3offre_clicked()
{
ui->tabWidget_2->setCurrentIndex(0);
}

void MainWindow::on_retour_2offre_clicked()
{
    ui->tabWidget_2->setCurrentIndex(0);

}

void MainWindow::on_retouroffre_clicked()
{
ui->tabWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pb_g_offre_clicked()
{
ui->tabWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pb_consulter_offre_clicked()
{
ui->tabWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pb_stats_offre_clicked()
{
ui->tabWidget_2->setCurrentIndex(3);
}

void MainWindow::on_retour_1Prod_clicked()
{
    ui->tabWidget_5->setCurrentIndex(0);
}

void MainWindow::on_retour_2Prod_clicked()
{
    ui->tabWidget_5->setCurrentIndex(0);
}

void MainWindow::on_retour_3Prod_clicked()
{
    ui->tabWidget_5->setCurrentIndex(0);
}

void MainWindow::on_retour_4Prod_clicked()
{
    ui->tabWidget_5->setCurrentIndex(0);
}

void MainWindow::on_retour_1Fou_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_2Fou_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_3Four_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_4Fou_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_3Clie_clicked()
{
    ui->impression_badges->setCurrentIndex(0);
}

void MainWindow::on_retour_2Clie_clicked()
{
    ui->impression_badges->setCurrentIndex(0);
}

void MainWindow::on_retour_1Clie_clicked()
{
    ui->impression_badges->setCurrentIndex(0);
}

void MainWindow::on_retour_1Mat_clicked()
{
    ui->tabWidget_3->setCurrentIndex(0);
}

void MainWindow::on_retour_2Mat_clicked()
{
    ui->tabWidget_3->setCurrentIndex(0);
}

void MainWindow::on_retour_3Mat_clicked()
{
     ui->tabWidget_3->setCurrentIndex(0);
}

void MainWindow::on_retour_1Emp_clicked()
{
    ui->tabWidget_4->setCurrentIndex(0);
}

void MainWindow::on_retour_2Emp_clicked()
{
     ui->tabWidget_4->setCurrentIndex(0);
}

void MainWindow::on_retour_3Emp_clicked()
{
     ui->tabWidget_4->setCurrentIndex(0);
}

void MainWindow::on_PB_G_emp_clicked()
{
    ui->tabWidget_4->setCurrentIndex(1);
}

void MainWindow::on_PB_C_emp_clicked()
{
    ui->tabWidget_4->setCurrentIndex(2);
}

void MainWindow::on_PB_Imp_emp_clicked()
{
    ui->tabWidget_4->setCurrentIndex(3);
}

void MainWindow::on_PB_G_mat_clicked()
{
    ui->tabWidget_3->setCurrentIndex(1);
}

void MainWindow::on_PB_C_mat_clicked()
{
    ui->tabWidget_3->setCurrentIndex(2);
}

void MainWindow::on_PB_M_Mat_clicked()
{
    ui->tabWidget_3->setCurrentIndex(3);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->impression_badges->setCurrentIndex(1);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->impression_badges->setCurrentIndex(2);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->impression_badges->setCurrentIndex(3);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_13_clicked()
{
     ui->tabWidget_5->setCurrentIndex(1);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->tabWidget_5->setCurrentIndex(2);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->tabWidget_5->setCurrentIndex(2);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->tabWidget_5->setCurrentIndex(3);
}

void MainWindow::on_Gestion_clients_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_gestion_pc_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_gestion_employe_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_gestion_materiel_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_gestion_fourni_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_gestion_offres_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pb_deco8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_export_pdf_5_clicked()
{
    c.telechargerPDF();
    QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);
}

void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_91->setText("Store open"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_91->setText("Store closed");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}

void MainWindow::on_pushButton_clicked()   // implémentation du slot bouton on
{
     A.write_to_arduino("1"); //envoyer 1 à arduino
}

void MainWindow::on_pushButton_2_clicked()  // implémentation du slot bouton off
{

     A.write_to_arduino("0");  //envoyer 0 à arduino
}
