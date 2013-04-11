#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawItems();
    connect(ui->rotationSlider, SIGNAL(valueChanged(int)), this, SLOT(rotateGun(int)));
    connect(ui->fireButton, SIGNAL(clicked()), this, SLOT(bang()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rotateGun(int amount)
{
    qreal diff = 0.85 * (lastAmount - amount);
    lastAmount = amount;
    gun->rotate(diff);
    scene.update();
}

void MainWindow::bang()
{
    clearMissle();
    timer->start();
    missle = new Missle(10, 10);
    scene.addItem(missle);
    QPoint p = QPoint(gun->getMissleStartPoint().x(), gun->getMissleStartPoint().y());
    missle->setPos(p);
    dir = QPoint(2, -1);
    //scene.addEllipse(dir.x() - 5, dir.y() - 5, 10, 10);
}

void MainWindow::drawItems()
{
    timer = new QTimer();
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeMisslePosition()));
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    gun = new Gun(scene);
    missle = NULL;
    scene.addItem(gun);
    lastAmount = 50;
    scene.addEllipse(200, -100, 50, 50);
}

void MainWindow::changeMisslePosition()
{
    QPoint plPoint = QPoint(100 / (200 - missle->x()), 100 / (-100 - missle->y()));
    QPoint newPoint (missle->x(), missle->y());
    newPoint += dir;
    newPoint += plPoint;
    missle->setPos(newPoint);
//    qDebug() << dest.x();
//    qDebug() << dest.y();
    if (newPoint.x() > ui->graphicsView->width() * 0.95|| -newPoint.y() > ui->graphicsView->height() * 0.95)
    {
       clearMissle();
    }
}

void MainWindow::clearMissle()
{
    if (timer->isActive())
        timer->stop();
    if (missle != NULL)
    {
        scene.removeItem(missle);
        delete missle;
        missle = NULL;
    }
}

