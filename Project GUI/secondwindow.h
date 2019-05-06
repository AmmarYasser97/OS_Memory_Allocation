#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "QString"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QStackedBarSeries>
#include <QValueAxis>

#include "my_memory.h"

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = 0);
    ~secondwindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::secondwindow *ui;
};

#endif // SECONDWINDOW_H
