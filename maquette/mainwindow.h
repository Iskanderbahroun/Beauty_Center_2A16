#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFileDialog>
#include <QMainWindow>
#include "offre.h"
#include <QVBoxLayout>
#include "statistique.h"
#include "video.h"
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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();


    void on_pb_chercher_code_clicked();

    QString on_pb_image_clicked();

    void on_pb_trier_code_clicked();

    void on_pb_trier_prix_clicked();

    void on_pb_trier_type_clicked();

    void on_pb_chercher_prix_clicked();

    void on_pb_chercher_type_clicked();

    void on_pb_stat_clicked();

    void on_pb_video_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    offre o;
    Statistique *statistique;
    video *Video;

};
#endif // MAINWINDOW_H
