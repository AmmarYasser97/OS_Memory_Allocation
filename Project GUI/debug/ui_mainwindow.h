/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionQuit;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *processName;
    QSpinBox *noSegments;
    QPushButton *add_process;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_8;
    QLineEdit *SegmentName;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_7;
    QSpinBox *segmentSize;
    QPushButton *add_segment;
    QTreeWidget *processTree;
    QPushButton *drawButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *memSize;
    QPushButton *pushButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *holeStart;
    QSpinBox *holeSize;
    QPushButton *add_hole;
    QTreeWidget *holeList;
    QPushButton *finishHoles;
    QHBoxLayout *horizontalLayout_10;
    QComboBox *processes;
    QPushButton *deallocate;
    QHBoxLayout *horizontalLayout_11;
    QComboBox *processes_2;
    QPushButton *allocate;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *draw_btn;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(770, 435);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(280, 30, 471, 351));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_8->addWidget(label_7);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        processName = new QLineEdit(layoutWidget);
        processName->setObjectName(QStringLiteral("processName"));
        processName->setEnabled(false);

        horizontalLayout_9->addWidget(processName);

        noSegments = new QSpinBox(layoutWidget);
        noSegments->setObjectName(QStringLiteral("noSegments"));
        noSegments->setEnabled(false);
        noSegments->setMinimum(1);

        horizontalLayout_9->addWidget(noSegments);

        add_process = new QPushButton(layoutWidget);
        add_process->setObjectName(QStringLiteral("add_process"));
        add_process->setEnabled(false);

        horizontalLayout_9->addWidget(add_process);


        verticalLayout_5->addLayout(horizontalLayout_9);


        verticalLayout_3->addLayout(verticalLayout_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_6->addWidget(label_8);

        SegmentName = new QLineEdit(layoutWidget);
        SegmentName->setObjectName(QStringLiteral("SegmentName"));
        SegmentName->setEnabled(false);

        verticalLayout_6->addWidget(SegmentName);


        horizontalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        segmentSize = new QSpinBox(layoutWidget);
        segmentSize->setObjectName(QStringLiteral("segmentSize"));
        segmentSize->setEnabled(false);
        segmentSize->setMinimum(1);
        segmentSize->setMaximum(9999999);

        horizontalLayout_7->addWidget(segmentSize);


        verticalLayout_4->addLayout(horizontalLayout_7);


        horizontalLayout_5->addLayout(verticalLayout_4);

        add_segment = new QPushButton(layoutWidget);
        add_segment->setObjectName(QStringLiteral("add_segment"));
        add_segment->setEnabled(false);

        horizontalLayout_5->addWidget(add_segment);


        verticalLayout_3->addLayout(horizontalLayout_5);

        processTree = new QTreeWidget(layoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        processTree->setHeaderItem(__qtreewidgetitem);
        processTree->setObjectName(QStringLiteral("processTree"));

        verticalLayout_3->addWidget(processTree);

        drawButton = new QPushButton(layoutWidget);
        drawButton->setObjectName(QStringLiteral("drawButton"));

        verticalLayout_3->addWidget(drawButton);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 216, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        memSize = new QSpinBox(layoutWidget1);
        memSize->setObjectName(QStringLiteral("memSize"));
        memSize->setMinimum(1);
        memSize->setMaximum(9999999);

        horizontalLayout->addWidget(memSize);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 40, 260, 343));
        verticalLayout_7 = new QVBoxLayout(layoutWidget2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        holeStart = new QSpinBox(layoutWidget2);
        holeStart->setObjectName(QStringLiteral("holeStart"));
        holeStart->setEnabled(false);
        holeStart->setMaximum(9999999);

        horizontalLayout_3->addWidget(holeStart);

        holeSize = new QSpinBox(layoutWidget2);
        holeSize->setObjectName(QStringLiteral("holeSize"));
        holeSize->setEnabled(false);
        holeSize->setMinimum(1);
        holeSize->setMaximum(9999999);

        horizontalLayout_3->addWidget(holeSize);

        add_hole = new QPushButton(layoutWidget2);
        add_hole->setObjectName(QStringLiteral("add_hole"));
        add_hole->setEnabled(false);

        horizontalLayout_3->addWidget(add_hole);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);

        holeList = new QTreeWidget(layoutWidget2);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        holeList->setHeaderItem(__qtreewidgetitem1);
        holeList->setObjectName(QStringLiteral("holeList"));

        verticalLayout_2->addWidget(holeList);

        finishHoles = new QPushButton(layoutWidget2);
        finishHoles->setObjectName(QStringLiteral("finishHoles"));
        finishHoles->setEnabled(false);

        verticalLayout_2->addWidget(finishHoles);


        verticalLayout_7->addLayout(verticalLayout_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        processes = new QComboBox(layoutWidget2);
        processes->setObjectName(QStringLiteral("processes"));

        horizontalLayout_10->addWidget(processes);

        deallocate = new QPushButton(layoutWidget2);
        deallocate->setObjectName(QStringLiteral("deallocate"));
        deallocate->setEnabled(false);

        horizontalLayout_10->addWidget(deallocate);


        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        processes_2 = new QComboBox(layoutWidget2);
        processes_2->setObjectName(QStringLiteral("processes_2"));

        horizontalLayout_11->addWidget(processes_2);

        allocate = new QPushButton(layoutWidget2);
        allocate->setObjectName(QStringLiteral("allocate"));
        allocate->setEnabled(false);

        horizontalLayout_11->addWidget(allocate);


        verticalLayout_7->addLayout(horizontalLayout_11);

        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(340, 0, 216, 25));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        draw_btn = new QPushButton(layoutWidget_2);
        draw_btn->setObjectName(QStringLiteral("draw_btn"));
        draw_btn->setEnabled(false);

        horizontalLayout_12->addWidget(draw_btn);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 770, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Memory Allocation Simulator", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        label_6->setText(QApplication::translate("MainWindow", "Process Name", 0));
        label_7->setText(QApplication::translate("MainWindow", "No. of Segments", 0));
        add_process->setText(QApplication::translate("MainWindow", "Add Process", 0));
        label_8->setText(QApplication::translate("MainWindow", "Segment Name", 0));
        label_5->setText(QApplication::translate("MainWindow", "Size", 0));
        add_segment->setText(QApplication::translate("MainWindow", "Add Segment", 0));
        drawButton->setText(QApplication::translate("MainWindow", "Draw", 0));
        label->setText(QApplication::translate("MainWindow", "Memory Size", 0));
        pushButton->setText(QApplication::translate("MainWindow", "OK", 0));
        label_3->setText(QApplication::translate("MainWindow", "Hole Start", 0));
        label_2->setText(QApplication::translate("MainWindow", "Hole Size", 0));
        add_hole->setText(QApplication::translate("MainWindow", "Add Hole", 0));
        finishHoles->setText(QApplication::translate("MainWindow", "Finish", 0));
        deallocate->setText(QApplication::translate("MainWindow", "Deallocate", 0));
        processes_2->clear();
        processes_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "First Fit", 0)
         << QApplication::translate("MainWindow", "Best Fit", 0)
         << QApplication::translate("MainWindow", "Worst Fit", 0)
        );
        allocate->setText(QApplication::translate("MainWindow", "Allocate", 0));
        draw_btn->setText(QApplication::translate("MainWindow", "Draw", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
