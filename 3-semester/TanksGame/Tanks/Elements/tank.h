#pragma once

#include <QGraphicsEllipseItem>
#include <QPen>
#include <QPainter>
#include <QTimer>

#include "burstable.h"
#include "../Constants/constants.h"

class Tank : public QObject, public Burstable
{
    Q_OBJECT

public:
    Tank(int xCoordiante, int yCoordinate, QColor color);
    Tank(QPointF point, QColor color);
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

    /// get the point in the end of Gun
    QPointF getStartPointForBullet() const;

private slots:
    void readyToBeDamagedAgain();

private:
    void drawGun(QPainter *painter);
    QPen pen;

    /// normalizes vector with the beginning - (0, 0) and end - point
    QPointF normalize(QPointF point);

    QPointF center;
    QPointF startPointForBullet;
    static const int radius = 15;
    int speed;
    qreal gunAngle;

    int hitpoints;
    bool isJustDamaged;
    QTimer *damageTimer;
};

