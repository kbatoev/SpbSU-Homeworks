#pragma once

#include <iostream>
#include <cstdio>

#include <QGraphicsScene>
#include <QEvent>
#include <QKeyEvent>
#include <QTextStream>
#include <QTimer>
#include <QRectF>

#include "Elements/landscape.h"
#include "Elements/tank.h"
#include "Elements/bullet.h"
#include "Elements/burst.h"
#include "Constants/constants.h"
#include "KeyController/keyController.h"

/**
 * @brief The Game class is a model.
 * It keeps all elements and interacts with KeyController
 *
 */

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    ~Game();

    /// delegates event to KeyController
    void keyPressEvent(QKeyEvent *keyEvent);

    /// adds these elements to lists to empty memory after closing game
    void addBullet(Bullet *newBullet);
    void addBurst(Burst *newBurst);

    /// if needed returns private fields
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

