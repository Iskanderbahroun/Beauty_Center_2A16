#include "client.h"
#include "ui_client.h"
#include "clientt.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

//#include "excelexporteur.h"

client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    ui->tab_client->setModel(c.afficher());
    ui->comboBox_2->setModel(c.afficher());
}

client::~client()
{
    delete ui;
}


void client::on_pb_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int tel=ui->le_tel->text().toInt();
    QString adresse=ui->le_adresse->text();

clientt c (cin,nom,prenom,tel,adresse);
bool test=c.ajouter();
if(test)
  {  QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajout effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
   { QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("ajout non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void client::on_pb_modifier_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int tel=ui->le_tel->text().toInt();
    QString adresse=ui->le_adresse->text();

        clientt c (cin,nom,prenom,tel,adresse);
        bool test=c.modifier(cin,nom,prenom,tel,adresse);
            if(test)
          {ui->tab_client->setModel(c.afficher());
          QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),
                            QObject::tr("invite modifiée.\n"
                                        "Click ok to exit."), QMessageBox::Ok);

          }
            else
                QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void client::on_pb_supprimer_clicked()
{
int cin=ui->le_cin->text().toInt();
bool test=c.supprimer(cin);
if(test)
{
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

void client::on_pb_afficher_clicked()
{
    ui->tab_client->setModel(c.afficher());

}

void client::on_pb_importer_clicked()
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


void client::on_comboBox_2_activated(const QString &arg1)
{
    int cin = ui->comboBox_2->currentText().toInt();
         QString cin_string= QString::number(cin);
                QSqlQuery query;
                query.prepare("select * from client where cin='"+cin_string+"'");

                if(query.exec()){

                    while(query.next())
                    {

                   ui->le_cin->setText(query.value(0).toString());
                    ui->le_nom->setText(query.value(1).toString());
                    ui->le_prenom->setText(query.value(2).toString());
                    ui->le_tel->setText(query.value(3).toString());
                    ui->le_adresse->setText(query.value(4).toString());
               }
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void client::on_trier_prenom_clicked()
{
ui->tab_client->setModel(c.trierprenom());
}

void client::on_trier_annees_clicked()
{
ui->tab_client->setModel(c.trieradresse());
}

void client::on_lineEdit_3_textChanged(const QString &arg1)   ///mtaa el recherche
{
   clientt c;

    QString rech = ui->lineEdit_3->text();
        c.recherche(ui->tab_client,rech);
        if (ui->lineEdit_3->text().isEmpty())
        {
            ui->tab_client->setModel(c.afficher());
        }
}

void client::on_export_pdf_clicked()
{
    c.telechargerPDF();
     QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);

}

void client::on_tab_client_activated(const QModelIndex &index)
{client f;
  QString val=ui->tab_client->model()->data(index).toString();
  QSqlQuery query;
  query.prepare("select * from client where cin='"+val+"'");

  if(query.exec()){

      while(query.next())
      {

     ui->le_cin->setText(query.value(0).toString());
      ui->le_nom->setText(query.value(1).toString());
      ui->le_prenom->setText(query.value(2).toString());
      ui->le_tel->setText(query.value(3).toString());
      ui->le_adresse->setText(query.value(4).toString());


 }
  }
  else
      QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


//{

//}

void client::on_tri_tel_clicked()
{
    ui->tab_client->setModel(c.triertel());
}



void client::on_pushButton_stat_clicked()
{
    QChart* chart_bar = c.chart_pie();
    QChartView* chart_view_bar = new QChartView(chart_bar, ui->label_stat);
    chart_view_bar->setRenderHint(QPainter::Antialiasing);
    chart_view_bar->setMinimumSize(400,400);
    chart_view_bar->show();
}

void client::on_tri_freq_clicked()
{
    ui->tab_client->setModel(c.trierfreq());

}

/*void client::on_export_excel_clicked()
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
