#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPen>
#include <QPainter>
#include <QObject>
#include <QTimer>

#include "burstable.h"
#include "landscape.h"
#include "burst.h"
#include "constants.h"

class Game;

class Bullet : public QObject, public Burstable
{
    Q_OBJECT
public:
    Bullet(QPointF center, qreal angle, Landscape *landscape, QGraphicsScene *scene);
    ~Bullet();

    void drawBurst();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void fly();

public slots:
    void updatePosition();

private:
    void checkDistanceFromLandscape();
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
    Landscape *landscape;
    QGraphicsScene *scene;
};
