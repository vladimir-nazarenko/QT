#pragma once

#include <QGraphicsItem>
#include <qgraphicsscene.h>
#include <qgraphicsitem.h>

class Missle : public QGraphicsItem
{
public:
    Missle(int x, int y, int startAngle);
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
    //virtual void rotate(qreal angle, QGraphicsScene& scene);
    virtual QRectF boundingRect() const;

private:
    qreal xSize;
    qreal ySize;
    qreal angle;
    
};
