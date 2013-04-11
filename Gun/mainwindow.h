#pragma once

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <qgraphicsscene.h>
#include "gun.h"
#include "missle.h"
#include "aim.h"
#include <qtimer.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    void setScene();
    Ui::MainWindow *ui;
    Gun* gun;
    Aim* aim;
    Missle* missle;
    QGraphicsScene scene;
    int lastAmount;
    QTimer* timer;
    void drawItems();
    void clearMissle();
    QPoint dir;

private slots:
    void rotateGun(int diff);
    void bang();
    void changeMisslePosition();
};
