#include "gun.h"
#include <qmath.h>
#include <math.h>
#include <qpainter.h>
#include <qpoint.h>
#include <missle.h>
#include <qdebug.h>

Gun::Gun(QGraphicsScene &parent)
{
    Q_UNUSED(parent);
    size = 50;
    difAngle = 4;
    currentAngle = 45;
    kLength = 2;
}

void Gun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //variables
    //круто было бы перерисовать всё это трансформами
    QLineF first (
                size * qCos(difAngle * M_PI / 180),
                size * qSin(difAngle * M_PI / 180),
                kLength * size * qCos(difAngle * M_PI / 180),
                size * qSin(difAngle * M_PI / 180)
                );
    QLineF second (
                size * qCos(-difAngle * M_PI / 180),
                size * qSin(-difAngle * M_PI / 180),
                kLength * size * qCos(-difAngle * M_PI / 180),
                size * qSin(-difAngle * M_PI / 180)
                );
    QLineF third (
                kLength * size * qCos(difAngle * M_PI / 180),
                size * qSin(difAngle * M_PI / 180),
                kLength * size * qCos(-difAngle * M_PI / 180),
                size * qSin(-difAngle * M_PI / 180)
                );
    painter->drawPie(-size, -size, size * 2, size * 2, 0, 1440);
    painter->rotate(currentAngle - 90);
    painter->drawLine(first);
    painter->drawLine(second);
    painter->drawLine(third);
}

QRectF Gun::boundingRect() const
{
    return QRectF(0, -2 * size, 2 * size, 2 * size);
}

void Gun::rotate(qreal angle)
{
    currentAngle += angle;
}

QPoint Gun::getMissleStartPoint() const
{
    QTransform transform;
    transform.rotate(-90 + currentAngle);
    transform.translate(kLength * size, 0);
    return transform.map(QPoint(0, 0));
}
