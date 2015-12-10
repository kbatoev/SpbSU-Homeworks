#include "bullet.h"

Bullet::Bullet(QPointF center, qreal angle)
{
    this->bulletCenter = center;
    this->radiusOfBurst = 40;
    this->bulletRadius = 10;
    this->msec = 16;
    this->angle = angle;
    this->speed = 70;
}

void Bullet::drawBurst()
{

}

QRectF Bullet::boundingRect() const
{
    return QRectF(bulletCenter.x() - bulletRadius, bulletCenter.y() - bulletRadius,
                  bulletCenter.x() + bulletRadius, bulletCenter.y() + bulletRadius);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawEllipse(bulletCenter, bulletRadius, bulletRadius);
}

void Bullet::fly()
{
    initialCenter = bulletCenter;
    timer = new QTimer();
    iteration = 0;
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePosition()));
    timer->start(msec);
}

void Bullet::updatePosition()
{
    iteration++;
    qreal t = iteration / 10.0;
    qreal x = initialCenter.x() + speed * t * ::cos(-angle);
    qreal y = initialCenter.y() - speed * t * ::sin(-angle)
            + 5.0 * t * t;
    bulletCenter = QPointF(x, y);
}

