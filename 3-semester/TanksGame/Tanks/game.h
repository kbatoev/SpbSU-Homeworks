#pragma once

#include <QGraphicsScene>
#include <QEvent>
#include <QKeyEvent>

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

public slots:
    void update();

private:
    QGraphicsScene *scene;
    Landscape *landscape;
    Tank *tank1, *tank2;
    Updater *updater;
};

