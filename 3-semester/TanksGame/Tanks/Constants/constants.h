#pragma once

#include <QObject>

const int msec = 17;
const qreal PI = 3.141592653;

// for Game
const qreal startXCoordinate1 = 100;
const qreal startXCoordinate2 = 600;
const QChar separator = ';';

// for Bullet
const qreal periodOfSettingPositionOfBullet = 8.0;

// for Tank
const qreal degreesInPI = 180.0;
const qreal leftBorderForGun = 180.0;
const qreal rightBorderForGun = 0.0;
const qreal addingToAngle = 7.0;
const int intervalOfGettingDamage = 1000;
const int initialHitPoints = 40;

// for Gun
const qreal length = 23;
const qreal width = 7;


// for Landscape
const int widthOfFrame = 800;
const int heightOfFrame = 600;
const int interval = 40;

const int yCoordinateAdding = 250;
const int maxDistanceBetweenTwoYCoordinates = 70;
const int moduleForYCoordinate = 350;

//for Burst
const int additionToRadius = 5;

enum Keys
{
    leftMove = 1,
    rightMove,
    leftGun,
    rightGun,
    changingBullet,
    shot
};
