#include "missle.h"

#include <qpainter.h>


Missle::Missle(int x, int y, int startAngle)
{
//    angle = startAngle;
    xSize = x;
    ySize = y;
}

void Missle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(0, 0, xSize, ySize);
}

QRectF Missle::boundingRect() const
{
    return QRectF(0, 0, 20, 20);
}

