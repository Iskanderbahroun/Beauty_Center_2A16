#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"client.h"

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
    void on_ob_tri_clicked();

    void on_ob_statistique_clicked();

    void on_ob_excel_clicked();

    void on_ob_cadeaux_clicked();

    void on_ob_ajouterclient_clicked();

    void on_ob_afficherclient_clicked();

    void on_ob_modifierclient_clicked();

    void on_ob_supprimerclient_clicked();
    void on_pb_supprimer_clicked();

private:
    Ui::MainWindow *ui;
    client C;
};
#endif // MAINWINDOW_H
