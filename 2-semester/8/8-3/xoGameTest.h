#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <xoGame.h>


const XOGame::Move x = XOGame::xs;
const XOGame::Move o = XOGame::os;
const XOGame::Move none = XOGame::none;
const XOGame::Move draw = XOGame::draw;
const int size = 3;

class XOGameTest : public QObject
{
    Q_OBJECT
public:
    explicit XOGameTest(QObject *parent = 0) : QObject(parent)
    {}

private slots:

    void init()
    {
        game = new XOGame(size);
    }

    void cleanup()
    {
        delete game;
    }

    void checkHorizontalXWin()
    {
        XOGame::Move matrix[3][3] = {{none, o, o},
                                     {x, x, x},
                                     {none, none, none}};

        XOGame::Move result = makeMovesAndGetResult(matrix);
        QVERIFY(result == XOGame::xs);
    }

    void checkVerticalXWin()
    {
        XOGame::Move matrix[3][3] = {{x, o, none},
                                     {x, o, none},
                                     {x, none, none}};

        XOGame::Move result = makeMovesAndGetResult(matrix);
        QVERIFY(result == XOGame::xs);
    }

    void checkDiagonalSumXWin()
    {
        XOGame::Move matrix[3][3] = {{none, o, x},
                                     {none, x, o},
                                     {x, none, none}};

        XOGame::Move result = makeMovesAndGetResult(matrix);
        QVERIFY(result == XOGame::xs);
    }

    void checkDiagonalSubstractXWin()
    {
        XOGame::Move matrix[3][3] = {{x, o, none},
                                     {none, x, o},
                                     {x, none, x}};

        XOGame::Move result = makeMovesAndGetResult(matrix);
        QVERIFY(result == XOGame::xs);
    }


    void checkHorizontalOsWin()
    {
        XOGame::Move matrix[3][3] = {{o, o, o},
                                     {x, x, none},
                                     {none, x, none}};
        XOGame::Move result = makeMovesAndGetResult(matrix);
        QVERIFY(result == XOGame::os);
    }

    void checkVerticalOsWin()
    {
        XOGame::Move matrix[3][3] = {{x, o, none},
                                     {x, o, none},
                                     {none, o, x}};

        XOGame::Move result = makeMovesAndGetResult(matrix);
        QVERIFY(result == XOGame::os);
    }

    void checkDiagonalSumOsWin()
    {
        XOGame::Move matrix[3][3] = {{none, x, o},
                                     {none, o, x},
                                     {o, none, x}};

        XOGame::Move result = makeMovesAndGetResult(matrix);
        QVERIFY(result == XOGame::os);
    }

    void checkDiagonalSubstractOsWin()
    {
        XOGame::Move matrix[3][3] = {{o, x, none},
                                     {x, o, x},
                                     {none, none, o}};

        XOGame::Move result = makeMovesAndGetResult(matrix);
        QVERIFY(result == XOGame::os);
    }

    void checkUnfinishedPosition()
    {
        XOGame::Move matrix[3][3] = {{none, x, none},
                                     {none, none, none},
                                     {none, none, o}};

        XOGame::Move result = makeMovesAndGetResult(matrix);
        QVERIFY(result == XOGame::none);
    }

    void checkDrawPosition()
    {
        XOGame::Move matrix[3][3] = {{x, x, o},
                                     {o, o, x},
                                     {x, x, o}};

        XOGame::Move result = makeMovesAndGetResult(matrix);
        QVERIFY(result == XOGame::draw);
    }

private:

    XOGame::Move makeMovesAndGetResult(XOGame::Move matrix[size][size])
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                game->makeMove(matrix[i][j], i, j);
        return game->checkPosition();
    }

    XOGame *game;
};
