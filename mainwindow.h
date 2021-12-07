#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>

#include <QFileInfo>
#include <QMainWindow>
#include "fournisseur.h"
#include "historique.h"
#include "smtp.h"
#include <QDialog>
#include <QFileDialog>
#include "offre.h"
#include "statistique.h"
#include "video.h"
#include <QMediaPlayer>
#include "employe.h"
#include "materiels.h"
#include "client.h"
#include "produitcosmetiques.h"
#include "statistiques.h"
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:


    void on_login_clicked();

    //*******Iskander****///
    void on_pb_ajouter6_clicked();
    void on_pb_modifier6_clicked();
    void on_pb_supp6_clicked();
    void on_comboBox6_activated(const QString &arg1);
    void on_trie_ref6_clicked();
    void on_trie_cat6_clicked();
    void on_trie_qual6_clicked();
    void on_pushButton_browse_email6_clicked();
    void on_pushButton_send_email6_clicked();
    void on_comboBox_26_activated(const QString &arg1);
    void on_recher_edit6_textChanged(const QString &arg1);
      void mailSent(QString);

    //*******Ibtihel******///
      void on_pb_ajouter4_clicked();
      QString on_pb_image4_clicked();
      void on_pb_modifier4_clicked();
      void on_pb_supprimer4_clicked();
      void on_pb_chercher_code4_clicked();
      void on_pb_chercher_prix4_clicked();
      void on_pb_chercher_type4_clicked();
      void on_pb_trier_code4_clicked();
      void on_pb_trier_prix4_clicked();
      void on_pb_trier_type4_clicked();
      void on_pb_video4_clicked();
      void on_pb_stat4_clicked();

      //*******emna****///
      void on_le_supprimer_2_clicked();
      void on_le_modifier_2_clicked();
      void on_comboBox_12_activated(const QString &arg1);
      void on_le_trie_par_nom_2_clicked();
      void on_le_trie_age_2_clicked();
      void on_le_trie_salaire_2_clicked();
      void on_rech_2_textChanged(const QString &arg1);
      void on_export_pdf_2_clicked();
      void on_abrir_2_clicked();
      void on_play_2_clicked();
      void on_pause_2_clicked();
      void on_stop_2_clicked();
      void on_mute_2_clicked();
      void on_volum_2_valueChanged(int value);
      void on_pb_ajout_2_clicked();

      //********sarah*****//
      void on_Pb_Ajouter3_clicked();
      void on_supprimer3_clicked();
      void on_Modifier3_clicked();
      void on_comboBox32_activated(const QString &arg1);
      void on_pushButton_34_clicked();
      void on_pushButton_35_clicked();
      void on_pushButton_36_clicked();
      void on_le_reference_3_textChanged(const QString &arg1);
      void on_stock_btn3_clicked();
  void on_comboBox_32_activated(const QString &arg1);
      void on_pushButton_browse_email3_clicked();
      void on_pushButton_send_email3_clicked();
      void mailSent3(QString);

      //****** youssef*****//
      void on_pb_ajouter5_clicked();
      void on_pb_modifier5_clicked();
      void on_pb_supprimer5_clicked();
      void on_pb_afficher5_clicked();
      void on_pb_importer5_clicked();
      void on_comboBox_35_activated(const QString &arg1);
      void on_trier_prenom5_clicked();
      void on_trier_annees5_clicked();
      void on_lineEdit_5_textChanged(const QString &arg1);
      void on_export_pdf5_clicked();
      void on_tab_client_activated(const QModelIndex &index);
      void on_tri_tel5_clicked();
      void on_pushButton_stat5_clicked();
      void on_tri_freq5_clicked();
      //void on_export_excel5_clicked();

          //*****ghayth****/
      void on_pb_ajouter7_clicked();
      void on_pb_supp7_clicked();
      void on_Modifier7_clicked();
      void on_comboBox_72_activated(const QString &arg1);
      void on_trierprix7_clicked();
      void on_trienom7_clicked();
      void on_triemarque7_clicked();
      void on_pb_ajouter_27_clicked();
      void on_pb_stat7_clicked();

//*********boutondeco******//
      void on_pb_deco2_clicked();
      void on_pb_deco3_clicked();
      void on_pb_deco4_clicked();
      void on_pb_deco5_clicked();
      void on_pb_deco6_clicked();
      void on_pb_deco7_clicked();



      void on_retour_3offre_clicked();

      void on_retour_2offre_clicked();

      void on_retouroffre_clicked();

      void on_pb_g_offre_clicked();

      void on_pb_consulter_offre_clicked();

      void on_pb_stats_offre_clicked();

      void on_retour_1Prod_clicked();

      void on_retour_2Prod_clicked();

      void on_retour_3Prod_clicked();

      void on_retour_4Prod_clicked();

      void on_retour_1Fou_clicked();

      void on_retour_2Fou_clicked();

      void on_retour_3Four_clicked();

      void on_retour_4Fou_clicked();

      void on_retour_3Clie_clicked();

      void on_retour_2Clie_clicked();

      void on_retour_1Clie_clicked();

      void on_retour_1Mat_clicked();

      void on_retour_2Mat_clicked();

      void on_retour_3Mat_clicked();

      void on_retour_1Emp_clicked();

      void on_retour_2Emp_clicked();

      void on_retour_3Emp_clicked();

      void on_PB_G_emp_clicked();

      void on_PB_C_emp_clicked();

      void on_PB_Imp_emp_clicked();

      void on_PB_G_mat_clicked();

      void on_PB_C_mat_clicked();

      void on_PB_M_Mat_clicked();

      void on_pushButton_7_clicked();

      void on_pushButton_8_clicked();

      void on_pushButton_9_clicked();

      void on_pushButton_3_clicked();

      void on_pushButton_4_clicked();

      void on_pushButton_5_clicked();

      void on_pushButton_6_clicked();

      void on_pushButton_13_clicked();

      void on_pushButton_14_clicked();

      void on_pushButton_15_clicked();

      void on_pushButton_16_clicked();

      void on_Gestion_clients_clicked();

      void on_gestion_pc_clicked();

      void on_gestion_employe_clicked();

      void on_gestion_materiel_clicked();

      void on_gestion_fourni_clicked();

      void on_gestion_offres_clicked();

      void on_pb_deco8_clicked();
      /////////////arduino

      void update_label();

      void on_pb_on_clicked();

      void on_pb_off_clicked();

private:
    Ui::MainWindow *ui;
    Fournisseur F;
    offre o;
    Historique H;
    QStringList files;
    statistique *Statistique;
    video *Video;
    Employe E;
   // QStringList files;
     QMediaPlayer *mMediaPlayer ;
     Materiel M;
     client c;
     ProduitsCosmetiques P;
 statistiques *Statistiques;

 QByteArray data; // variable contenant les données reçues

 Arduino A1; // objet temporaire
};
#endif // MAINWINDOW_H
