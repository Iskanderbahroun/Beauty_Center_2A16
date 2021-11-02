#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QMainWindow>

namespace Ui {
class Authentification;
}

class Authentification : public QMainWindow
{
    Q_OBJECT

public:
    explicit Authentification(QWidget *parent = nullptr);
    ~Authentification();

private:
    Ui::Authentification *ui;
};

#endif // AUTHENTIFICATION_H
