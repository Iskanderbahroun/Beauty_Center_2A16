#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QMainWindow>
#include <QMessageBox>
#include <employe.h>
#include <QFileInfo>
#include <mainwindow.h>
#include "employee.h"







namespace Ui {
class Authentification;
}

class Authentification : public QMainWindow
{
    Q_OBJECT

public:
    explicit Authentification(QWidget *parent = nullptr);
    ~Authentification();

private slots:


    void on_login_clicked();

private:
    Ui::Authentification *ui;
    MainWindow *mainwindow;

};

#endif // AUTHENTIFICATION_H
