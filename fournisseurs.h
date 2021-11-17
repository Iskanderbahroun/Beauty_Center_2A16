#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H
#include "Fournisseur.h"
#include <QDialog>
#include "historique.h"
QT_BEGIN_NAMESPACE
namespace Ui {class Fournisseurs; }
QT_END_NAMESPACE
class Fournisseurs : public QDialog
{
    Q_OBJECT

public:
    explicit Fournisseurs(QWidget *parent = nullptr);
    ~Fournisseurs();

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
   Ui::Fournisseurs *ui;
    Fournisseur F;
    Historique H;
};

#endif // FOURNISSEURS_H