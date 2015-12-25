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
    Game(QVector<QPointF> *serverPoints = 0);
    ~Game();

    static QVector<QPointF> *makeVectorFromQString(QString message);

    /// delegates event to KeyController
    void keyPressEvent(QKeyEvent *keyEvent);

    /// adds these elements to lists to empty memory after closing game
    void addBullet(Bullet *newBullet);
    void addBurst(Burst *newBurst);

    /// if needed returns private fields
    QGraphicsScene *getScene() const;
    Landscape *getLandscape() const;

    Tank *getCurrentTank() const;
    void setCurrentTank(int number);
    void setNextTank();

    QString collectLandscapeInformation();
    QString collectCurrentInformation();

    void setCurrentInformation(QString message);


signals:
    void finishedMove();

private:
    void createTank(int xcoordinate, QColor color);

public slots:
    void updateScene();

private:
    QPointF tankPointOnScene;
    int currentTankNumber;

    KeyController *keyController;
    QGraphicsScene *scene;
    Landscape *landscape;
    QList<Tank *> tanks;
    QList<Bullet *> bullets;
    QList<Burst *> bursts;
    QTimer *gameTimer;
};

