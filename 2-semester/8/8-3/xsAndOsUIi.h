#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QSignalMapper>

#include "xoGame.h"

namespace Ui {
class XsAndOsUI;
}

class XsAndOsUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit XsAndOsUI(QWidget *parent = 0);
    ~XsAndOsUI();

private slots:
    void play(int id);

private:
    XOGame::Move move;
    int fieldSize;
    XOGame *game;

    Ui::XsAndOsUI *ui;
    QSignalMapper *signalMapper;
    QPushButton **field;
};

