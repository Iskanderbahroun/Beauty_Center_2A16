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

}

MainWindow::~MainWindow()
{
    delete ui;
}



