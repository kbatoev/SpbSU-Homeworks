#include "bullet.h"

Bullet::Bullet(QPointF center, qreal angle, Landscape *landscape)
    : bulletCenter(center),
      initialCenter(center),
      iteration(0),
      bulletRadius(5),
      coefficient(4.0),
      angle(angle),
      speed(55),
      timer(nullptr),
      landscape(landscape)
{
//    this->radiusOfBurst = 40;
}

void Bullet::drawBurst()
{
    timer->stop();
    //this->setVisible(false);
}

QRectF Bullet::boundingRect() const
{
    return QRectF(bulletCenter.x() - bulletRadius, bulletCenter.y() - bulletRadius,
                  2 * bulletRadius, 2 * bulletRadius);
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
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePosition()));
    timer->start(msec);
}

void Bullet::updatePosition()
{
    iteration++;
    qreal t = iteration / periodOfSettingPositionOfBullet;
    qreal x = initialCenter.x() + speed * t * ::cos(-angle);
    qreal y = initialCenter.y() - speed * t * ::sin(-angle) + coefficient * t * t;

    if (x >= 0 && x < widthOfFrame && y >= 0 && y < heightOfFrame)
    {
        bulletCenter = QPointF(x, y);
    }
    else
    {
        setVisible(false);
    }
    checkDistanceFromLandscape();

}

void Bullet::checkDistanceFromLandscape()
{
    qreal x = bulletCenter.x();
    QPointF point = landscape->getPointWithXCoordinate(x);
    qreal distance = countDistanceFromBulletCenter(point);
    if (distance < bulletRadius)
    {
        this->drawBurst();
    }
}

qreal Bullet::countDistanceFromBulletCenter(QPointF point)
{
    return sqrt((bulletCenter.x() - point.x()) * (bulletCenter.x() - point.x()) +
                (bulletCenter.y() - point.y()) * (bulletCenter.y() - point.y()));
}

