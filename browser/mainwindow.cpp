#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->but_Reload, SIGNAL(clicked()), this, SLOT(reload()));
    connect(ui->but_Back, SIGNAL(clicked()), this, SLOT(prev()));
    connect(ui->but_Next, SIGNAL(clicked()), this, SLOT(next()));
    connect(ui->but_Stop, SIGNAL(clicked()), this, SLOT(stop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reload()
{
    QUrl url;
    url.setUrl("http://" + ui->lineEdit->text());
    ui->webView->load(url);
}

void MainWindow::stop()
{
    ui->webView->stop();
}

void MainWindow::next()
{
    ui->webView->forward();
}

void MainWindow::prev()
{
    ui->webView->back();
}
