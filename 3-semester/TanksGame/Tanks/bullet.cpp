#include "bullet.h"

Bullet::Bullet(QPointF center, qreal angle, Landscape *landscape)
{
    this->bulletCenter = center;
    this->radiusOfBurst = 40;
    this->bulletRadius = 5;
    this->msec = 16;
    this->angle = angle;
    this->speed = 55;
    this->landscape = landscape;
}

void Bullet::drawBurst()
{
    timer->stop();
    //this->setVisible(false);
}

QRectF Bullet::boundingRect() const
{
    return QRectF(bulletCenter.x() - bulletRadius, bulletCenter.y() + bulletRadius,
                  bulletCenter.x() + bulletRadius, bulletCenter.y() - bulletRadius);
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
    if (x >= 0 && x < widthOfFrame && y >= 0 && y < heightOfFrame)
    {
        bulletCenter = QPointF(x, y);
    }
    else
    {
        this->setVisible(false);
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

