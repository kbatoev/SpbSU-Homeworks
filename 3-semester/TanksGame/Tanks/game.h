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
#include "keyController.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    ~Game();

    QGraphicsScene *getScene();

    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);

public slots:
    void update();

private:
    KeyController *keyController;
    QGraphicsScene *scene;
    Landscape *landscape;
    Tank *tank;
    Updater *updater;
};

