#include "updater.h"

Updater::Updater()
{
    timer = new QTimer();
    interval = 17;
    connect(timer, SIGNAL(timeout()), this, SIGNAL(doUpdate()));
}

void Updater::execute()
{
    timer->start(interval);
}

