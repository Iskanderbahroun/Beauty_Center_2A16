#ifndef CLIENT_H
#define CLIENT_H

#include"clientt.h"

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);

    ~client();

private slots:


    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_afficher_clicked();

    void on_pb_importer_clicked();


    void on_comboBox_2_activated(const QString &arg1);


    void on_trier_prenom_clicked();

    void on_trier_annees_clicked();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_export_pdf_clicked();

    void on_tab_client_activated(const QModelIndex &index);

//    void on_calcul_score_clicked();

    void on_tri_tel_clicked();

    void on_pushButton_stat_clicked();

    void on_tri_freq_clicked();

    void on_export_excel_clicked();

private:
    Ui::client *ui;
    clientt c;
};

#endif // CLIENT_H
