#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employe.h"
#include <QMainWindow>
#include<QTableView>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QDialog>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QMediaPlayer ;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pb_ajout_clicked();

    void on_le_supprimer_clicked();

    void on_le_modifier_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_le_trie_par_nom_clicked();

    void on_le_trie_age_clicked();

    void on_le_trie_salaire_clicked();



    void on_rech_textChanged(const QString &arg1);

    void on_export_pdf_clicked();

    

    void on_abrir_clicked();

    void on_play_clicked();

    void on_pause_clicked();

    void on_stop_clicked();

    void on_mute_clicked();

    void on_volum_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    Employe E ;
    QStringList files;
    QMediaPlayer *mMediaPlayer ;
};
#endif // MAINWINDOW_H
