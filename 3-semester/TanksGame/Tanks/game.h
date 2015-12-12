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

//const qreal PI = 3.141592653;

const int msec = 30;

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    ~Game();


    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);

    QGraphicsScene *getScene() const;

public slots:
    void updateScene();

private:
    QPointF tankPointOnScene;

    KeyController *keyController;
    QGraphicsScene *scene;
    Landscape *landscape;
    Tank *tank;
    //Updater *updater;
    QTimer *gameTimer;
};

