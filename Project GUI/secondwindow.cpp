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
    //QStringList range;

    //range << "0";

    //![1]


        std::list<Block>::reverse_iterator it;
        for (it = m->memory.rbegin(); it != m->memory.rend(); ++it)
        {


            QBarSet *memorySet = new QBarSet(it->getProcessName() == ""
                                             ? "HOLE"
                                             : it->getProcessName() + ": " +  it->getSegmentName());

            if (it->getProcessName() == "")
            {
                memorySet->setColor(QColor(125, 125, 125));
            }
            else if (it->getProcessName().contains("Old Process"))
            {
                memorySet->setColor(QColor(255, 0, 0));
            }

            *memorySet <<it->getSize();

            series->append(memorySet);

            //range << QString::number(it->getEnd());
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
        QBarCategoryAxis *axis_x = new QBarCategoryAxis();
        QBarCategoryAxis *axis_y = new QBarCategoryAxis();

        axis_x->setReverse(true);

        //axis_y->append(range);


//      axis_x->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis_x, series);
        //chart->setAxisY(axis_y);


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
