#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QDialog>

namespace Ui {
class statistiques;
}

class statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit statistiques(QWidget *parent = nullptr);
    ~statistiques();
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::statistiques *ui;
};

#endif // STATISTIQUES_H
