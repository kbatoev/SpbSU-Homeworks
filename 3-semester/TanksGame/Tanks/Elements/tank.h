#pragma once

#include <QGraphicsEllipseItem>
#include <QPen>
#include <QPainter>
#include <QTimer>

#include "burstable.h"
#include "../Constants/constants.h"
#include "bullet.h"
#include "lightbullet.h"
#include "heavybullet.h"

class Game;

class Tank : public QObject, public Burstable
{
    Q_OBJECT

public:
    Tank(Game *game, int xCoordiante, int yCoordinate, QColor color);
    Tank(Game *game, QPointF point, QColor color);
    Tank();
    ~Tank();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void drawBurst(Burstable *reason = 0);
    int makeDamage();

    /// Getters
    int getSpeed() const;
    QPointF getCenter() const;
    qreal getGunAngleInRadians() const;
    static int getRadius();

    /// changes position of tank in QGraphicsScene
    void setCenter(QPointF newCenter);
    void increaseAngle();
    void decreaseAngle();
    void shoot();

    /// get the point in the end of Gun
    QPointF getStartPointForBullet() const;

    qreal getGunAngle() const;
    void setGunAngle(const qreal &value);

private slots:
    void readyToBeDamagedAgain();

private:
    void drawGun(QPainter *painter);
    QPen pen;

    /// normalizes vector with the beginning - (0, 0) and end - point
    QPointF normalize(QPointF point);

    Game *game;
    QPointF center;
    QPointF startPointForBullet;
    static const int radius = 15;
    int speed;
    qreal gunAngle;

    int hitpoints;
    bool isJustDamaged;
    QList<Bullet *> listOfBullets;
    Bullet *bullet;
    QTimer *damageTimer;
};

