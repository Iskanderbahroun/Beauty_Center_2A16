#ifndef PRODUITCOSMETIQUES_H
#define PRODUITCOSMETIQUES_H

#include <QDialog>
#include "produitscosmetiques.h"
#include "statistique.h"
namespace Ui {
class produitcosmetiques;
}

class produitcosmetiques : public QDialog
{
    Q_OBJECT

public:
    explicit produitcosmetiques(QWidget *parent = nullptr);
    ~produitcosmetiques();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_Modifier_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_trierprix_clicked();

    void on_trienom_clicked();

    void on_triemarque_clicked();



    void on_pb_ajouter_2_clicked();

    void on_pb_stat_clicked();

private:
    Ui::produitcosmetiques *ui;
    ProduitsCosmetiques P;
statistique *Statistique;
};

#endif // PRODUITCOSMETIQUES_H
