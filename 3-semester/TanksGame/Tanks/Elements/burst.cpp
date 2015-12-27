#include "burst.h"

Burst::Burst(QGraphicsScene *scene, int radius, int damage)
    : scene(scene),
      maxBurstRadius(radius),
      currentRadius(5),
      iteration(0),
      isOver(false),
      timer(new QTimer()),
      damage(damage)
{
    connect(timer, SIGNAL(timeout()), this, SLOT(incrementIteration()));
    //timer->start(msec);
}

Burst::~Burst()
{
    delete timer;
}

QRectF Burst::boundingRect() const
{

    QPointF topLeft(burstCenter.x() - currentRadius, burstCenter.y() - currentRadius);
    QPointF bottomRight(burstCenter.x() + currentRadius, burstCenter.y() + currentRadius);
    return QRectF(topLeft, bottomRight);

}

void Burst::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (!isOver)
    {
        QPen pen;
        pen.setColor(Qt::black);
        pen.setWidth(3);
        painter->setPen(pen);
        painter->drawEllipse(burstCenter, currentRadius, currentRadius);
        painter->drawRect(boundingRect());
    }
}

void Burst::start()
{
    isOver = false;
    currentRadius = 0;
    timer->start(msec);
    scene->addItem(this);
}

void Burst::isContactedBy(Contactable *reason)
{

}

int Burst::makeDamage()
{
    return damage;
}

void Burst::updateStatusOfBurst()
{
    currentRadius += 5;
    isOver = currentRadius >= maxBurstRadius;
}

void Burst::incrementIteration()
{
    updateStatusOfBurst();
    if (isOver)
    {
        timer->stop();
        scene->removeItem(this);
    }
}

void Burst::setBurstCenter(const QPointF &value)
{
    burstCenter = value;
}

