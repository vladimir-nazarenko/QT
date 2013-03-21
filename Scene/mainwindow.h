#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <QGraphicsRectItem>
#include <QTimer>

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
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QGraphicsRectItem* graphic;
    QTimer timer;
    QTransform matrix;

public slots:
    void buttonClicked();

private slots:
    void rotate();
};

#endif // MAINWINDOW_H
