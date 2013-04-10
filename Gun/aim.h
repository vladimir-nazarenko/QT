#pragma once

#include <QGraphicsItem>
#include <qgraphicsscene.h>
#include <qgraphicsitem.h>

class Aim : public QGraphicsItem
{
public:
    Aim(QGraphicsScene& parent);
    Aim(QGraphicsScene& parent, int x, int y);
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
    //virtual void rotate(qreal angle, QGraphicsScene& scene);
    virtual QRectF boundingRect() const;
};

