/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Apr 17 09:17:40 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QActionEvent>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QSlider *rotationSlider;
    QPushButton *fireButton;
    QPushButton *generateTargetBtn;
    QSlider *powerSlider;
    QMenuBar *menuBar;
    QMenu *menuHorizontal_slider_for_direction_vertical_one_for_power;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(546, 369);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        rotationSlider = new QSlider(centralWidget);
        rotationSlider->setObjectName(QString::fromUtf8("rotationSlider"));
        rotationSlider->setValue(50);
        rotationSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(rotationSlider);

        fireButton = new QPushButton(centralWidget);
        fireButton->setObjectName(QString::fromUtf8("fireButton"));

        verticalLayout->addWidget(fireButton);

        generateTargetBtn = new QPushButton(centralWidget);
        generateTargetBtn->setObjectName(QString::fromUtf8("generateTargetBtn"));

        verticalLayout->addWidget(generateTargetBtn);


        horizontalLayout->addLayout(verticalLayout);

        powerSlider = new QSlider(centralWidget);
        powerSlider->setObjectName(QString::fromUtf8("powerSlider"));
        powerSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(powerSlider);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 546, 21));
        menuHorizontal_slider_for_direction_vertical_one_for_power = new QMenu(menuBar);
        menuHorizontal_slider_for_direction_vertical_one_for_power->setObjectName(QString::fromUtf8("menuHorizontal_slider_for_direction_vertical_one_for_power"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHorizontal_slider_for_direction_vertical_one_for_power->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        fireButton->setText(QApplication::translate("MainWindow", "Fire", 0, QApplication::UnicodeUTF8));
        generateTargetBtn->setText(QApplication::translate("MainWindow", "Generate Target", 0, QApplication::UnicodeUTF8));
        menuHorizontal_slider_for_direction_vertical_one_for_power->setTitle(QApplication::translate("MainWindow", "Horizontal slider for direction, vertical one for power", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
