#pragma once

class XOGame
{
public:
    XOGame(int size);
    ~XOGame();

    enum Move
    {
        none = -1,
        os = 0,
        xs = 1
    };
    Move checkPosition();
    void makeMove(Move move, int i, int j);

private:

    bool isFinished(int repetitions, Move previousButton);

    Move horizontalBypass();
    Move verticalBypass();
    Move sumBypass();
    Move subtractBypass();

    int fieldSize;
    Move **matrix;
};

