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
    Bullet(QPointF center, qreal angle, Game *game);
    ~Bullet();

    void drawBurst();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void addYourselfToScene();

    /// bullet starts flying
    void fly();

public slots:
    void updatePosition();
    void updateStatus();

private:
    /// if distances is too small, calls method 'drawBurst'
    void checkDistanceFromLandscape();
    /// counts distance from point on Landscape
    qreal countDistanceFromBulletCenter(QPointF point);

private:
    static int numberOfCreatedBullets;

private:
    QPointF bulletCenter;
    QPointF initialCenter;
    int iteration;
    int bulletRadius;
    qreal coefficient;
    qreal angle;
    qreal speed;
    QTimer *timer;

    bool isReadyToBurst;
    Game *game;
    int id;
};
