#pragma once

#include <iostream>
#include <cstdio>

#include <QGraphicsScene>
#include <QEvent>
#include <QKeyEvent>
#include <QTextStream>
#include <QTimer>

#include "Elements/landscape.h"
#include "Elements/tank.h"
#include "Elements/bullet.h"
#include "Elements/burst.h"
#include "Constants/constants.h"
#include "KeyController/keyController.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    ~Game();

    void keyPressEvent(QKeyEvent *keyEvent);

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

