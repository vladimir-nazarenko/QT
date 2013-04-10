#include "gun.h"
#include <qmath.h>
#include <math.h>
#include <qpainter.h>
#include <qpoint.h>
#include <missle.h>
#include <qdebug.h>

Gun::Gun(QGraphicsScene &parent)
{
    size = 50;
    difAngle = 4;
    angle = 30 * difAngle;
    ///temporary
    angle = 45;
    ////////
    kLength = 2;
}

void Gun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //variables
    QTransform transform;
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
    //painter->drawRect(this->boundingRect());

    painter->drawPie(-size, -size, size * 2, size * 2, 0, 1440);
//    transform.rotate(-45 + angle);
    painter->rotate(angle - 90);
    ////////////////////////
    painter->drawLine(first);
    painter->drawLine(second);
    painter->drawLine(third);
    Missle mis(10, 10, 10);
//    painter->drawEllipse(getMissleStartPoint(), 10, 10);
//    painter->drawRect(mis.boundingRect());
//    transform.rotate(90 + angle);
//    painter->setTransform(transform, true);

}

QRectF Gun::boundingRect() const
{
    return QRectF(0, -2 * size, 2 * size, 2 * size);
}

void Gun::rotate(qreal plusAngle, QGraphicsScene& scene)
{
    angle += plusAngle;
}

int Gun::getAngle()
{
    return angle;
}

QPoint Gun::getMissleStartPoint()
{
    qreal x = (kLength * size * qCos((angle + (difAngle)) * M_PI / 180))
               /*kLength * size * qCos(-difAngle * M_PI / 180)) / 2*/;
    qreal y = -(kLength * size * qSin((angle + (difAngle)) * M_PI / 180) )/*+
               size * qSin(difAngle * M_PI / 180)) / 2*/;
    qDebug() << "output from guts of Gun: y = " << y;
        qDebug() << "output from guts of Gun: sin = " << qSin(difAngle * M_PI / 180) ;

    return QPoint(x, y);
}
