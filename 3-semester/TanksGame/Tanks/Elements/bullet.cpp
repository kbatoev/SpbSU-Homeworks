#include "bullet.h"
#include "game.h"

Bullet::Bullet()
{

}

Bullet::Bullet(QPointF center, qreal angle, Game *game)
{
    bulletCenter = center;
    initialCenter= center;
    iteration = 0;
    bulletRadius = 5;
    coefficient = 4.0;
    this->angle = angle;
    speed = 55;
    timer = nullptr;
    isReadyToBurst = false;
    this->game = game;
    damage = 10;
    radiusOfBurst = 40;
    this->game->addBullet(this);
}

Bullet::~Bullet()
{
    delete timer;
}

void Bullet::drawBurst(Burstable *reason)
{
    if (isReadyToBurst && !hasBurst)
    {
        timer->stop();
        hasBurst = true;
        setVisible(false);
        game->getScene()->removeItem(this);
        Burst *burst = new Burst(bulletCenter, game->getScene(), radiusOfBurst, damage);
        game->addBurst(burst);
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
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawEllipse(bulletCenter, bulletRadius, bulletRadius);
}

void Bullet::addYourselfToScene()
{
    game->getScene()->addItem(this);
}

void Bullet::fly()
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePosition()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateStatus()));
    timer->start(msec);
}

int Bullet::getDamage() const
{
    return damage;
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
        hasBurst = true;
        setVisible(false);
        timer->stop();
        game->getScene()->removeItem(this);
    }

    checkDistanceFromLandscape();

}

void Bullet::updateStatus()
{
    isReadyToBurst = iteration > 7;
}

void Bullet::checkDistanceFromLandscape()
{
    qreal x = bulletCenter.x();
    QPointF point = game->getLandscape()->getPointWithXCoordinate(x);
    qreal distance = countDistanceFromBulletCenter(point);
    if (distance < 2.0 * bulletRadius)
    {
        isReadyToBurst = true;
        drawBurst();
    }
}

qreal Bullet::countDistanceFromBulletCenter(QPointF point)
{
    return sqrt((bulletCenter.x() - point.x()) * (bulletCenter.x() - point.x()) +
                (bulletCenter.y() - point.y()) * (bulletCenter.y() - point.y()));
}

int Bullet::getBulletRadius() const
{
    return bulletRadius;
}

