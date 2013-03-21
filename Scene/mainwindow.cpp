#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graphic = scene.addRect(QRect(0, 0, 100, 100));
    ui->graphicsView->setScene(&scene);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    timer.setInterval(100);
    connect(&timer, SIGNAL(timeout()), this, SLOT(rotate()));
    timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClicked()
{
    graphic = scene.addRect(QRect(50, 50, 100, 100));
    QTransform matrix;
    matrix.rotate(45);
    graphic->setTransform(matrix);
    graphic->setFlag(QGraphicsItem::ItemIsMovable, true);
}

void MainWindow::rotate()
{
    matrix.rotate(5);
    graphic->setTransform(matrix);
}
