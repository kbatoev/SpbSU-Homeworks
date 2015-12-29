#pragma once

#include <QGraphicsEllipseItem>
#include <QPen>
#include <QPainter>
#include <QTimer>

#include "contactable.h"
#include "../Constants/constants.h"
#include "bullet.h"
#include "lightbullet.h"
#include "heavybullet.h"

class Game;

class Tank : public QObject, public Contactable
{
    Q_OBJECT

public:
    Tank(Game *game, int xCoordiante, int yCoordinate, QColor color);
    Tank(Game *game, QPointF point, QColor color);
    Tank();
    ~Tank();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /// are called when tank intersects with Bullet, Burst, Tank
    void isContactedBy(Contactable *reason = 0);
    int makeDamage();

    /// Getters
    int getSpeed() const;
    QPointF getCenter() const;
    qreal getGunAngleInRadians() const;
    int getRadius() const;

    /// changes position of tank in QGraphicsScene
    void setCenter(QPointF newCenter);
    void increaseAngle();
    void decreaseAngle();
    void shoot();
    void changeBullet();

    qreal getGunAngle() const;
    void setGunAngle(const qreal &value);

    int getBulletType() const;
    void setBulletType(int value);

    QString getBulletName() const;

private slots:
    /// when tank is damaged it is in safe during 1 second
    void readyToBeDamagedAgain();

signals:
    /// inform Game that tank has got damage
    void changedHealth(int health, QColor color);
    void gameIsOver(QColor color);

private:
    void drawGun(QPainter *painter);
    QColor color;

    Game *game;
    QPointF center;
    int radius;
    int speed;
    qreal gunAngle;

    int hitpoints;
    bool isJustDamaged;
    QList<Bullet *> typesOfbullets;
    int bulletType;
    QTimer *damageTimer;
};

