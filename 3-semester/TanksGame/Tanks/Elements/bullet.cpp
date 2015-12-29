#include "bullet.h"
#include "game.h"

Bullet::Bullet()
{
    iteration = 0;
    bulletRadius = 5;
    coefficient = 4.0;
    speed = 55;
    isReadyToBurst = false;
    damage = 10;
    radiusOfBurst = 40;
    isFlying = false;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePosition()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateStatus()));
    timer->start(msec);
}

Bullet::Bullet(Game *game) :
    Bullet()
{
    this->game = game;
}

Bullet::~Bullet()
{
    delete timer;
}

void Bullet::isContactedBy(Contactable *reason)
{
    if (isReadyToBurst && !hasBurst)
    {
        isFlying = false;
        hasBurst = true;
        setVisible(false);
        game->getScene()->removeItem(this);
        burst->setBurstCenter(bulletCenter);
        burst->start();
    }
}

int Bullet::makeDamage()
{
    return 0;
}

QRectF Bullet::boundingRect() const
{
    QPointF topLeft(bulletCenter.x() - bulletRadius, bulletCenter.y() - bulletRadius);
    QPointF bottomRight(bulletCenter.x() + bulletRadius, bulletCenter.y() + bulletRadius);
    return QRectF(topLeft, bottomRight);
}

QPainterPath Bullet::shape() const
{
    QPainterPath painterPath;
    painterPath.addRect(boundingRect());
    return painterPath;
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(bulletCenter, bulletRadius, bulletRadius);
}

void Bullet::fly()
{
    iteration = 0;
    setVisible(true);
    isFlying = true;
}

void Bullet::updatePosition()
{
    if (isFlying)
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
            isFlying = false;
            hasBurst = true;
            setVisible(false);
            game->getScene()->removeItem(this);
        }

        checkDistanceFromLandscape();
    }

}

void Bullet::updateStatus()
{
    if (isFlying)
        isReadyToBurst = iteration > 7;
}

void Bullet::checkDistanceFromLandscape()
{
    qreal x = bulletCenter.x();
    QPointF point = game->getPointWithXCoordinate(x);
    qreal distance = countDistanceFromBulletCenter(point);
    if (distance < 2.0 * bulletRadius)
    {
        isReadyToBurst = true;
        isContactedBy();
    }
}

qreal Bullet::countDistanceFromBulletCenter(QPointF point)
{
    return sqrt((bulletCenter.x() - point.x()) * (bulletCenter.x() - point.x()) +
                (bulletCenter.y() - point.y()) * (bulletCenter.y() - point.y()));
}

void Bullet::setAngle(const qreal &value)
{
    if (!isFlying)
    {
        angle = value;
        hasBurst = false;
    }
}

void Bullet::setCenter(const QPointF &value)
{
    if (!isFlying)
    {
        bulletCenter = value;
        initialCenter = value;
        hasBurst = false;
    }
}

