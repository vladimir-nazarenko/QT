#include "target.h"
#include "qpainter.h"

void Target::hit()
{
    hitBrush = QBrush(QColor::fromRgb(rand() % 200, rand() % 255, rand() % 255));
    this->update();
}


QRectF Target::boundingRect() const
{
    return QRectF(-ySize / 2, -ySize / 2, xSize, ySize);
}


void Target::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(hitBrush);
    painter->drawEllipse(-xSize / 2, -ySize / 2, xSize, ySize);
}


Target::Target(int x, int y)
{
    xSize = x;
    ySize = y;
    hitBrush = QBrush(QColor::fromRgb(255, 255, 255));
}

Target::~Target()
{
}
