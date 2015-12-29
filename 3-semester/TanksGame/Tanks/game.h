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
 * It keeps scene, tanks, landscape
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

    /// deals with tank accorrding to key
    void keyPressEvent(const Keys &key);

    QGraphicsScene *getScene() const;
    QPointF getPointWithXCoordinate(qreal x);

    Tank *getCurrentTank() const;
    void setCurrentTank(int number);

    /// collect info for transmission
    QString collectLandscapeInformation();
    QString collectCurrentInformation();

    /// sets info after transmission
    void setCurrentInformation(const QString &message);
    void currentTankShot();

    /// Label sets bullet name
    QString getBulletName() const;

public slots:
    void updateScene();
    void setNextTank();

private:
    void createTank(int xcoordinate, QColor color);

signals:
    void finishedMove();
    void changedHealth(int health, QColor color);
    void gameIsOver(QColor color);

private:
    QGraphicsScene *scene;
    Landscape *landscape;
    QList<Tank *> tanks;
    QTimer *gameTimer;

    bool hasShot;
    int currentTankNumber;
};

