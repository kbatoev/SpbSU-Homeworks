#pragma once

#include <iostream>
#include <cstdio>

#include <QGraphicsScene>
#include <QEvent>
#include <QKeyEvent>
#include <QTextStream>
#include <QTimer>

#include "landscape.h"
#include "tank.h"
#include "updater.h"
#include "keyController.h"
#include "bullet.h"
#include "burst.h"
#include "constants.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    ~Game();


    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);

    void addBullet(Bullet *newBullet);
    void addBurst(Burst *newBurst);

    QGraphicsScene *getScene() const;
    Landscape *getLandscape() const;
    Tank *getTank() const;

public slots:
    void updateScene();

private:
    QPointF tankPointOnScene;

    KeyController *keyController;
    QGraphicsScene *scene;
    Landscape *landscape;
    Tank *tank;
    QList<Bullet *> bullets;
    QList<Burst *> bursts;
    QTimer *gameTimer;
};

