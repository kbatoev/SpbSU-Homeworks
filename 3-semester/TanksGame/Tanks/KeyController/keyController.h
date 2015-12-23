#pragma once

#include <QKeyEvent>
#include <QObject>


class Game;

/**
 * @brief The KeyController class
 * Manages what to do with Tank
 *
 */

class KeyController : public QObject
{
    Q_OBJECT

public:
    KeyController(Game *game);

    /**
     * @brief handleKey
     * @param keyEvent
     * Left, Right, Up, Down, Enter
     */
    void handleKey(QKeyEvent *keyEvent);

private:
    Game *game;
};
