#pragma once

#include <qgraphicsitem.h>
#include <qbrush.h>

class Target : public QGraphicsItem
{
public:
    Target(int x, int y);
    virtual ~Target();
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
    virtual QRectF boundingRect() const;
    void hit();

private:
    qreal xSize;
    qreal ySize;
    QBrush hitBrush;
};
