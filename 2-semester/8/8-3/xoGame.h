#pragma once

/**
 * @brief The XOGame class
 */

class XOGame
{
public:

    /// makes matrix with given size and fills it with Move::none
    XOGame(int size);
    ~XOGame();

    enum Move
    {
        none = -1,
        os = 0,
        xs = 1,
        draw
    };
    /// returns a winner of current position, if it's not NONE
    Move checkPosition();

    /// changes matrix
    void makeMove(Move move, int i, int j);

private:

    /// checks if the game is over
    bool isFinished(int repetitions, Move previousButton);

    /// Three X or O is a win
    Move horizontalBypass();
    Move verticalBypass();
    Move sumBypass();
    Move subtractBypass();

    int numberOfMoves;
    int fieldSize;
    Move **matrix;
};

