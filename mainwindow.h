#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"materiel.h"

#include <QMainWindow>
#include <QDialog>
#include <QFileDialog>

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
    void on_Pb_Ajouter_clicked();





    void on_supprimer_clicked();


    void on_Modifier_clicked();









    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();



    void on_pushButton_6_clicked();

    void on_le_reference_3_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_stock_btn_clicked();

void on_comboBox_2_activated(const QString &arg1);



    void on_pushButton_browse_email_clicked();

    void on_pushButton_send_email_clicked();
    void mailSent(QString);

private:
    Ui::MainWindow *ui;
    Materiel M;
    QStringList files;
};
#endif // MAINWINDOW_H
