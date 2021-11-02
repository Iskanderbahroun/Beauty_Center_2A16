#include "authentification.h"
#include "ui_authentification.h"

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
