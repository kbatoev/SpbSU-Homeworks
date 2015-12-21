#pragma once

#include <QObject>
#include <QMainWindow>
#include <QGraphicsView>
#include <QEvent>

#include "game.h"


class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);

    bool event(QEvent *event);

private:
    QGraphicsView *view;
    Game *game;
};

