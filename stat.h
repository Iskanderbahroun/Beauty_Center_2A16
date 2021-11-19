#ifndef STAT_H
#define STAT_H

#include <QDialog>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>

#include <QWidget>
namespace Ui {
class stat;
}

class stat : public QDialog
{
    Q_OBJECT

public:
    explicit stat(QWidget *parent = nullptr);
    ~stat();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::stat *ui;
    int id;
};

#endif // STAT_H
