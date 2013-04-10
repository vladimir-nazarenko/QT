#pragma once

#include <qgraphicsscene.h>
#include <qgraphicsitem.h>
#include "missle.h"
#include "qpoint.h"

class Gun : public QGraphicsItem
{
public:
    Gun(QGraphicsScene & parent);
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
    virtual void rotate(qreal angle, QGraphicsScene& scene);
    virtual QRectF boundingRect() const;
    int getAngle();
    QPoint getMissleStartPoint();

private:
    qreal angle;
    qreal size;
    qreal difAngle;
    qreal kLength;
    QGraphicsScene parent; 
};
