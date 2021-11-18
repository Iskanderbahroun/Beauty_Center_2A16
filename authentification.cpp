#include "authentification.h"
#include "ui_authentification.h"
#include "employe.h"

Authentification::Authentification(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Authentification)
{
    ui->setupUi(this);
}

Authentification::~Authentification()
{
    delete ui;
}



void Authentification::on_login_clicked()
{
    {
           QString username = ui->lineEdit_username->text();
           QString password = ui->lineEdit_password->text();

           if(username ==  "emna" && password == "emna") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
               mainwindow = new MainWindow(this);
               mainwindow->show();
           }
           else if(username ==  "rym" && password == "rym") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
               mainwindow = new MainWindow(this);
               mainwindow->show();
           }
           else if(username ==  "sarah" && password == "sarah") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
               mainwindow = new MainWindow(this);
               mainwindow->show();
           }
           else if(username ==  "ibtihel" && password == "ibtihel") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
               mainwindow = new MainWindow(this);
               mainwindow->show();
           }
           else if(username ==  "youssef" && password == "youssef") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
               mainwindow = new MainWindow(this);
               mainwindow->show();
           }
           else if(username ==  "skander" && password == "skander") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
               mainwindow = new MainWindow(this);
               mainwindow->show();
           }
           else if(username ==  "ghaith" && password == "ghaith") {
               QMessageBox::information(this, "Login", "Username and password is correct");
               //hide();
               mainwindow = new MainWindow(this);
               mainwindow->show();
           }
           else {
               QMessageBox::warning(this,"Login", "Username and password is not correct");
           }
       }

}


