#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPen>
#include <QPainter>
#include <QPainterPath>
#include <QObject>
#include <QRectF>
#include <QTimer>

#include "burstable.h"
#include "landscape.h"
#include "burst.h"
#include "Constants/constants.h"

class Game;

class Bullet : public QObject, public Burstable
{
    Q_OBJECT

public:
    Bullet();
    Bullet(Game *game);
    ~Bullet();

    void drawBurst(Burstable *reason = 0);
    int makeDamage();
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

    /// bullet starts flying
    void fly();

    int getDamage() const;

    int getBulletRadius() const;

    void setAngle(const qreal &value);
    void setCenter(const QPointF &value);

public slots:
    void updatePosition();
    void updateStatus();

protected:
    /// if distances is too small, calls method 'drawBurst'
    void checkDistanceFromLandscape();
    /// counts distance from point on Landscape
    qreal countDistanceFromBulletCenter(QPointF point);

protected:
    QPointF bulletCenter;
    QPointF initialCenter;
    int iteration;
    int bulletRadius;
    qreal coefficient;
    qreal angle;
    qreal speed;
    int damage;
    QTimer *timer;

    bool isFlying;
    bool isReadyToBurst;
    Game *game;

    Burst *burst;
};
