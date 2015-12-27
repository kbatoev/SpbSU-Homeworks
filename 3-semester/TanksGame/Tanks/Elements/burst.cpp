#include "burst.h"

Burst::Burst(QGraphicsScene *scene, int radius, int damage)
    : scene(scene),
      maxBurstRadius(radius),
      initialRadius(5),
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
    if (!isOver)
    {
       return QRectF(burstCenter.x() - iteration * initialRadius, burstCenter.y() - iteration * initialRadius,
                     2 * iteration * initialRadius, 2 * iteration * initialRadius);

    }
}

void Burst::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (!isOver)
    {
        QPen pen;
        pen.setColor(Qt::black);
        pen.setWidth(3);
        painter->setPen(pen);
        painter->drawEllipse(burstCenter, initialRadius * iteration, initialRadius * iteration);
    }
}

void Burst::start()
{
    iteration = 0;
    timer->start(msec);
    scene->addItem(this);
}

void Burst::drawBurst(Burstable *reason)
{

}

int Burst::makeDamage()
{
    return damage;
}

void Burst::updateStatusOfBurst()
{
    isOver = iteration * initialRadius >= maxBurstRadius;
}

void Burst::incrementIteration()
{
    updateStatusOfBurst();
    if (isOver)
    {
        timer->stop();
        scene->removeItem(this);
    }
    iteration++;
}

void Burst::setBurstCenter(const QPointF &value)
{
    burstCenter = value;
}

