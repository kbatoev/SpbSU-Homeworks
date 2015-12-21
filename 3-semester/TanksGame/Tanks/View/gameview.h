#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QMainWindow>
#include <QEvent>
#include <QObject>

#include "game.h"

/**
 * @brief The GameView class
 * the purpose is to create QGraphicsView from game->getScene()
 */

class GameView : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameView(QWidget *widget = 0);
    ~GameView();

//    /// delegates event to Game class
//    void keyPressEvent(QKeyEvent *keyEvent);


//    virtual bool event(QEvent *event);

//    QGraphicsView *getGraphicsView() const;

    //void show();

private:
    Game *game;
    QGraphicsView *graphicsView;
};
