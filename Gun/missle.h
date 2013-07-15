#pragma once
#include <qgraphicsitem.h>

class Missle : public QGraphicsItem
{
public:
    Missle(int x, int y);
    virtual ~Missle();
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ); virtual QRectF boundingRect() const;

private:
    qreal xSize;
    qreal ySize;
};
