#define GESTION_CLIENT_H
#define GESTION_CLIENT_H

#include <QDialog>
#include "client.h"


namespace Ui {
class gestion_client;
}

class gestion_client : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_client(QWidget *parent = nullptr);
    ~gestion_client();

private slots:
    void on_ob_tri_clicked();

    void on_ob_statistique_clicked();

    void on_ob_excel_clicked();

    void on_ob_cadeaux_clicked();

    void on_ob_ajouterclient_clicked();

    void on_ob_modifierclient_clicked();

    void on_pb_supprimer_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_radioButton_clicked();

    void on_tri_nom_clicked();

    void on_tri_prenom_clicked();

    void on_tri_age_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_export2Excel_clicked();

private:
    Ui::gestion_client *ui;
    client C ;
};

