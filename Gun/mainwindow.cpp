#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawItems();
    connect(ui->rotationSlider, SIGNAL(valueChanged(int)), this, SLOT(rotateGun(int)));
    connect(ui->fireButton, SIGNAL(clicked()), this, SLOT(bang()));
    connect(ui->rotationSlider, SIGNAL(valueChanged(int)), this, SLOT(changeMisslePosition()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rotateGun(int amount)
{
    qreal diff = 0.85 * (lastAmount - amount);
    lastAmount = amount;
    gun->rotate(diff, scene);
    scene.update();
}

void MainWindow::bang()
{

}

void MainWindow::drawItems()
{

    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    gun = new Gun(scene);
    scene.addItem(gun);
    lastAmount = 50;
    missle = new Missle(10,10,10);
    scene.addItem(missle);
    qDebug() << gun->getMissleStartPoint().x();
    qDebug() << " ";
    qDebug() << gun->getMissleStartPoint().y();
    QPoint p = QPoint(gun->getMissleStartPoint().x() - gun->pos().x(), gun->getMissleStartPoint().y() - gun->pos().y());
    missle->setPos(p);
//    scene.addEllipse(0, 0, 20, 20);
}

void MainWindow::changeMisslePosition()
{
    //QPoint p = QPoint(gun->getMissleStartPoint().x() - gun->pos().x(), gun->getMissleStartPoint().y() - gun->pos().y());
    //missle->setPos(p);
}
