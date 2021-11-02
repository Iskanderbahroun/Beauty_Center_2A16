#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
E.ajouter();
}
