#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QVector"
#include "QString"
#include <QMessageBox>
#include "my_memory.h"

QVector<int> holeStartVector;
QVector<int> holeSizeVector;
QVector<int> segmentSizeVector;
QVector<QString> processName;
QVector<QString> segmentName;
Memory *m=new Memory();
Process *p_ptr;
int memSize;
QTreeWidgetItem *prnt = new QTreeWidgetItem();


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->holeList->setColumnCount(2);
    ui->holeList->setHeaderLabels(QStringList()<<"Hole Start"<<"Hole Size");
    ui->processTree->setColumnCount(3);
    ui->processTree->setHeaderLabels(QStringList()<<"Process Name"<<"Segment Name"<<"Segment Size");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_hole_clicked()
{
    int holeSize = ui->holeSize->value();
    int holeStart= ui->holeStart->value();

    if(m->Is_Empty_Boolean(holeStart,(holeStart+holeSize-1)))
    {
            m->Add_Block("", "", holeStart, holeSize);
            holeSizeVector.push_back(ui->holeSize->value());
            holeStartVector.push_back(ui->holeStart->value());
            QTreeWidgetItem *itm = new QTreeWidgetItem(ui->holeList);
            itm->setText(0,QString::number(ui->holeStart->value()));
            itm->setText(1,QString::number(ui->holeSize->value()));
            ui->holeList->addTopLevelItem(itm);
            ui->holeSize->setValue(0);
            ui->holeStart->setValue(0);
    }
    else
    {
        QMessageBox::information(this,"Error","Hole is Already Declared");
        return;

    }


}

void MainWindow::on_add_segment_clicked()
{
    if (p_ptr->segments.size() ==ui->noSegments->value()-1){
        ui->allocate->setEnabled(true);
        ui->add_segment->setEnabled(false);
        ui->segmentSize->setEnabled(false);
        ui->SegmentName->setEnabled(false);

        //QMessageBox::information(this,"error","number of segments exceeded");
        //return;
    }
    segmentName.push_back(ui->SegmentName->text());
    segmentSizeVector.push_back(ui->segmentSize->value());


    QTreeWidgetItem *itm = new QTreeWidgetItem(prnt);
    itm->setText(1,ui->SegmentName->text());
    itm->setText(2,QString::number(ui->segmentSize->value()));

    ui->processTree->addTopLevelItem(itm);

    Segment s;
    s.name = ui->SegmentName->text();
    s.size = ui->segmentSize->value();

    qDebug() << ui->segmentSize->value();
    p_ptr->segments.push_back(s);

}

void MainWindow::on_pushButton_clicked()
{
    memSize=ui->memSize->value();
    m->setSize(memSize);
    qDebug()<<QString::number(m->getSize());
    m->Print_Memory();
    ui->memSize->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->holeSize->setEnabled(true);
    ui->holeStart->setEnabled(true);
    ui->add_hole->setEnabled(true);
    ui->finishHoles->setEnabled(true);
}

void MainWindow::on_deallocate_clicked()
{
    m->Deallocate_Process(ui->processes->currentText());


//    QTreeWidgetItem *i=new QTreeWidgetItem(ui->processTree);
//    i = ui->processTree->topLevelItem(0);

    QTreeWidgetItem *i;

    if(ui->processTree->findItems(ui->processes->currentText(), Qt::MatchExactly, 0).isEmpty()){
        QMessageBox::information(this,"error","error");
    }
    else{
        i=ui->processTree->findItems(ui->processes->currentText(), Qt::MatchExactly, 0)[0];
    }
    qDebug() << ui->processTree->indexOfTopLevelItem(i);

    //delete i->parent()->takeChild(i->parent()->indexOfChild(i));
    delete ui->processTree->takeTopLevelItem(ui->processTree->indexOfTopLevelItem(i));
    ui->processes->removeItem(ui->processes->currentIndex());
//    i->setText(0,ui->processes->currentText());
//    ui->processTree->removeItemWidget(i,0);

    /*while (*i)
    {
        if ((*i)->text(0) == ui->processes->currentText())
        {
            delete ui->processTree->takeTopLevelItem(ui->processTree->indexOfTopLevelItem(*i));
            break;
        }
        i++;
    }*/
}

void MainWindow::on_allocate_clicked()
{
    ui->processes->addItem(ui->processName->text());

    ui->add_process->setEnabled(true);
    ui->processName->setEnabled(true);
    ui->noSegments->setEnabled(true);

    m->Print_Memory();
    qDebug() << "-------------";
    switch (ui->processes_2->currentIndex()) {
    case 0:
       m->first_fit(*p_ptr);
       break;
    case 1:
        m->best_fit(*p_ptr);
        break;
    case 2:
        m->worst_fit(*p_ptr);
        break;
    default:
        break;
    }

    m->Print_Memory();
}

void MainWindow::on_add_process_clicked()
{
    ui->add_process->setEnabled(false);
    ui->processName->setEnabled(false);
    ui->noSegments->setEnabled(false);
    ui->add_segment->setEnabled(true);
    ui->segmentSize->setEnabled(true);
    ui->SegmentName->setEnabled(true);

    if (processName.count(ui->processName->text()) == 1)
    {
        QMessageBox::information(this,"error","Process already existsS");
        return;
    }

    processName.push_back(ui->processName->text());


    static Process P;
    p_ptr = &P;

    P.segments.clear();
    P.name = ui->processName->text();
    P.num_of_segments = ui->noSegments->value();

    prnt = new QTreeWidgetItem(ui->processTree);
    prnt->setText(0,ui->processName->text());
    ui->processTree->addTopLevelItem(prnt);


}

void MainWindow::on_finishHoles_clicked()
{
    ui->holeSize->setEnabled(false);
    ui->holeStart->setEnabled(false);
    ui->add_hole->setEnabled(false);
    ui->finishHoles->setEnabled(false);
    ui->processName->setEnabled(true);
    ui->noSegments->setEnabled(true);
    ui->add_process->setEnabled(true);
    ui->deallocate->setEnabled(true);

    QVector<QString> old_Processes = m->Flip_Blocks();

    for (QString s : old_Processes)
    {
        ui->processes->addItem(s);
    }
}
