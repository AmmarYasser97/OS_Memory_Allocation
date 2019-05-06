#include "secondwindow.h"
#include "ui_secondwindow.h"

secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);

    extern Memory *m;
//    QStringList categories;

    QT_CHARTS_USE_NAMESPACE

    QStackedBarSeries *series = new QStackedBarSeries();

    //![1]

        std::list<Block>::iterator it;
        for (it = m->memory.begin(); it != m->memory.end(); ++it)
        {
            QBarSet *memorySet = new QBarSet((*it).getProcessName());

            *memorySet <<(*it).getSize();

            series->append(memorySet);

//            categories << (*it).getProcessName();

        }

    //![1]

    //![2]
    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Memory visualization");
        chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
        QBarCategoryAxis *axis = new QBarCategoryAxis();
//        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);
    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]
        QChartView *chartView = new QChartView(chart, this);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![6]

    //![7]
        ui->verticalLayout->addWidget(chartView);
//        chartView->show();
    //![7]

}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_pushButton_clicked()
{
    this->close();
}
