#pragma once

#include <QGraphicsItem>

class Contactable : public QGraphicsItem
{
public:
    virtual void isContactedBy(Contactable *reason = 0) = 0;
    virtual int makeDamage() = 0;

protected:
    bool hasBurst = false;
    int radiusOfBurst;
};
