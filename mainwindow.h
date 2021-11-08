#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Fournisseur.h"

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


    void on_pb_supp_clicked();

    void on_pb_modifier_clicked();






    void on_comboBox_activated(const QString &arg1);

    void on_trie_ref_clicked();

    void on_trie_cat_clicked();

    void on_trie_qual_clicked();

    void on_recher_edit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Fournisseur F;
};
#endif // MAINWINDOW_H
