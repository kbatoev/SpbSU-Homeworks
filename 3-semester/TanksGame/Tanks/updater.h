#pragma once

#include <QTimer>
#include <QObject>

class Updater : public QObject
{
    Q_OBJECT

public:
    Updater();
    void execute();

signals:
    void doUpdate();

private:
    QTimer *timer;
    int interval;
};
