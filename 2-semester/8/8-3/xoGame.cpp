#include "xoGame.h"

XOGame::XOGame(int size)
{
    fieldSize = size;
    matrix = new Move*[fieldSize];
    for (int i = 0; i < fieldSize; i++)
        matrix[i] = new Move[fieldSize];

    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
            matrix[i][j] = none;
}

XOGame::~XOGame()
{

}

XOGame::Move XOGame::checkPosition()
{
    Move hor = horizontalBypass();
    Move ver = verticalBypass();
    Move diagonalSum = sumBypass();
    Move diagonalSubtract = subtractBypass();

    if (hor != none)
        return hor;
    if (ver != none)
        return ver;
    if (diagonalSum != none)
        return diagonalSum;
    if (diagonalSubtract != none)
        return diagonalSubtract;
}

void XOGame::makeMove(XOGame::Move move, int i, int j)
{
    matrix[i][j] = move;
}

bool XOGame::isFinished(int repetitions, XOGame::Move previousButton)
{
    return (repetitions >= 3 && previousButton != -1);
}

XOGame::Move XOGame::horizontalBypass()
{
    int repetitions = 0;
    Move previousButton = none;
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
            if (!j || previousButton != matrix[i][j])
            {
                repetitions = 1;
                previousButton = matrix[i][j];
            }
            else
            {
                repetitions++;
                if (isFinished(repetitions, previousButton))
                    return previousButton;
            }

    return none;
}

XOGame::Move XOGame::verticalBypass()
{
    int repetitions = 0;
    Move previousButton = none;
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
            if (!j || previousButton != matrix[j][i])
            {
                repetitions = 1;
                previousButton = matrix[j][i];
            }
            else
            {
                repetitions++;
                if (isFinished(repetitions, previousButton))
                    return previousButton;
            }

    return none;
}

XOGame::Move XOGame::sumBypass()
{
    for (int count = 0; count < 2 *(fieldSize - 1); count++)
    {
        int j = 0;
        int i = count;
        while (i >= fieldSize)
        {
            j++;
            i--;
        }
        int repetitions = 0;
        Move previousButton = matrix[j][i];

        while (j < fieldSize && i >= 0)
        {
            if (previousButton != matrix[j][i])
            {
                repetitions = 1;
                previousButton = matrix[j][i];
            }
            else
            {
                repetitions++;
                if (isFinished(repetitions, previousButton))
                    return previousButton;
            }
            j++;
            i--;
        }
    }

    return none;
}

XOGame::Move XOGame::subtractBypass()
{
    int beginning = -fieldSize + 1;
    int ending = fieldSize - 1;
    for (int count = beginning; count <= ending; count++)
    {
        int i = 0;
        int j = i - count;
        while (j < 0)
        {
            i++;
            j++;
        }

        int repetitions = 0;
        Move previousButton = matrix[j][i];

        while (i < fieldSize && j < fieldSize)
        {
            if (previousButton != matrix[j][i])
            {
                repetitions = 1;
                previousButton = matrix[j][i];
            }
            else
            {
                repetitions++;
                if (isFinished(repetitions, previousButton))
                    return previousButton;
            }
            j++;
            i++;
        }
    }
    return none;
}

