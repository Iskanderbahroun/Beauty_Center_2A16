#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "offre.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_code->setValidator( new QIntValidator(0, 999, this));///accepte seulement les entiers
    ui->le_prix->setValidator( new QIntValidator(0, 999, this));//il n'accepte pas les vergule pour les doubles
    ui->tab_offre->setModel(o.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int code=ui->le_code->text().toInt();
    double prix=ui->le_prix->text().toDouble();
    QString type=ui->le_type->text();
    offre o(code,prix,type);
    bool test=o.ajouter();

    if (test){

    QMessageBox::information(nullptr, QObject::tr("OK"),
                           QObject::tr("Ajout effectué\n"
                                       "Click cancel to exit."), QMessageBox::Cancel );
    ui->tab_offre->setModel(o.afficher());//refreche
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                               QObject::tr("Ajout non effectué\n"
                                           "Click cancel to exit."), QMessageBox::Cancel );
}

void MainWindow::on_pb_supprimer_clicked()
{
    offre o1; o1.setcode(ui->le_code_supp->text().toInt());
    bool test=o1.supprimer(o1.getcode());
    if (test){

    QMessageBox::information(nullptr, QObject::tr("OK"),
                           QObject::tr("Supprimer effectué\n"
                                       "Click cancel to exit."), QMessageBox::Cancel );
    ui->tab_offre->setModel(o.afficher());//refreche
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                               QObject::tr("Supprimer non effectué\n"
                                           "Click cancel to exit."), QMessageBox::Cancel );

}
