#ifndef STATS_H
#define STATS_H

#include <QDialog>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include <QWidget>
namespace Ui {
class stats;
}

class stats : public QDialog
{
    Q_OBJECT

public:
    explicit stats(QWidget *parent = nullptr);
    ~stats();
    void make();
    int getid();
private slots:
  //  void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::stats *ui;
    int id;
};

#endif // STATS_H
