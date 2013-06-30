#pragma once

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <qgraphicsscene.h>
#include "gun.h"
#include "missle.h"
#include "target.h"
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
    Missle* missle;
    QGraphicsScene scene;
    int lastAmount;
    QTimer* timer;
    void drawItems();
    void clearMissle();
    QPointF dir;
    qreal power;
    Target* aim;

private slots:
    void rotateGun(int diff);
    void bang();
    void changeMisslePosition();
    void setPower(int newValue);
    void setTarget();
};
