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
    virtual void rotate(qreal angle);
    virtual QRectF boundingRect() const;
    QPoint getMissleStartPoint() const;
    qreal getAngle();

private:
    qreal currentAngle;
    qreal size;
    qreal difAngle;
    qreal kLength;
};
