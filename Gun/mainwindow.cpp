#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <qmath.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawItems();
    connect(ui->rotationSlider, SIGNAL(valueChanged(int)), this, SLOT(rotateGun(int)));
    connect(ui->fireButton, SIGNAL(clicked()), this, SLOT(bang()));
    connect(ui->powerSlider, SIGNAL(valueChanged(int)), this, SLOT(setPower(int)));
    connect(ui->generateTargetBtn, SIGNAL(clicked()), this, SLOT(setTarget()));
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
    this->setWindowTitle(QString::number(qTan(gun->getAngle() * M_PI / 180)));
    scene.update();
}

void MainWindow::bang()
{
    clearMissle();
    timer->start();
    missle = new Missle(10, 10);
    scene.addItem(missle);
    QPointF p = QPointF(gun->getMissleStartPoint().x(), gun->getMissleStartPoint().y());
    missle->setPos(p);
    qreal yPower = qTan(gun->getAngle() * M_PI / 180) * power > 5 ? 5 : qTan(gun->getAngle() * M_PI / 180) * power;
    dir = QPointF(power, -yPower);
}

void MainWindow::drawItems()
{
    timer = new QTimer();
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeMisslePosition()));
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    gun = new Gun(scene);
    missle = NULL;
    scene.addItem(gun);
    lastAmount = 50;
    power = 0.1;
    aim = new Target(20, 20);
    scene.addItem(aim);
    aim->setPos(rand() % (ui->graphicsView->width() - 299) + 300, rand() % (-ui->graphicsView->height() + 299) - 300);
}

void MainWindow::changeMisslePosition()
{
    QPointF newPoint (missle->x(), missle->y());
    dir += QPointF(0, 0.01);
    newPoint += dir;
    missle->setPos(newPoint);
    if (newPoint.x() > ui->graphicsView->width() * 0.95
        || -newPoint.y() < ui->graphicsView->height() * 0.05
        || -newPoint.y() > ui->graphicsView->height() * 0.95)
    {
       clearMissle();
    }

    //know if intersects
    if (missle != NULL)
    {
        qreal r = sqrt(pow(aim->x() - missle->x() + 5, 2) + pow(aim->y() - missle->y() + 5, 2));
        if (r < 15)
        {
            aim->hit();
            clearMissle();
        }
    }
}

void MainWindow::setPower(int newValue)
{
    const int ratio = 25;
    power = newValue / ratio;
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

void MainWindow::setTarget()
{
    scene.removeItem(aim);
    aim = new Target(20, 20);
    scene.addItem(aim);
    aim->setPos(rand() % (ui->graphicsView->width() - 400) + 300, rand() % (-ui->graphicsView->height() + 299) - 250);
}
