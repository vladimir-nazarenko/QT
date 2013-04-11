#include "missle.h"

#include <qpainter.h>


Missle::Missle(int x, int y)
{
    xSize = x;
    ySize = y;
}

void Missle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawEllipse(-xSize / 2, -ySize / 2, xSize, ySize);
}

QRectF Missle::boundingRect() const
{
    return QRectF(-ySize / 2, -ySize / 2, xSize, ySize);
}

Missle::~Missle()
{

}



