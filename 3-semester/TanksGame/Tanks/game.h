#pragma once

#include <iostream>
#include <cstdio>

#include <QGraphicsScene>
#include <QEvent>
#include <QKeyEvent>
#include <QTextStream>

#include "landscape.h"
#include "tank.h"
#include "updater.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    ~Game();

    bool event(QEvent *qEvent);
    QGraphicsScene *getScene();

    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);

public slots:
    void update();

private:
    QTextStream *stream;
    int release = 0;
    int press = 0;

    QGraphicsScene *scene;
    Landscape *landscape;
    Tank *tank1, *tank2;
    Updater *updater;
};

