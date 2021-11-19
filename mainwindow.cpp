#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include"joueurs.h"
//#include"ui_joueurs.h"

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
//joueurs::joueurs(QWidget *parent)
//    : Joueurs(parent)
//    , ui(new Ui::joueurs)
//{
//    ui->setupUi(this);
//}

//joueurs::~joueurs()
//{
//    delete ui;
//}
