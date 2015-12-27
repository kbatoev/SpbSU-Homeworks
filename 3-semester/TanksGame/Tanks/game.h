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
    static QString readUntilSeparator(QString message, int &startIndex);

    /// delegates event to KeyController
    void keyPressEvent(Keys key);

    /// if needed returns private fields
    QGraphicsScene *getScene() const;
    QPointF getPointWithXCoordinate(qreal x);

    Tank *getCurrentTank() const;
    void setCurrentTank(int number);

    QString collectLandscapeInformation();
    QString collectCurrentInformation();

    void setCurrentInformation(QString message);
    void currentTankShot();

    QString getBulletName() const;


signals:
    void finishedMove();
    void changedHealth(int health, QColor color);
    void gameIsOver(QColor color);

private:
    void createTank(int xcoordinate, QColor color);

public slots:
    void updateScene();
    void setNextTank();

private:
    QGraphicsScene *scene;
    Landscape *landscape;
    QList<Tank *> tanks;
    QTimer *gameTimer;

    bool hasShot;
    int currentTankNumber;
};

