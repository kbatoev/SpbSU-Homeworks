#include <iostream>
#include "lexer.h"

using namespace std;

const int maxSize = 1000;

void readLine(char *line)
{
    int i = 0;
    char symbol = '0';
    while (symbol != '\0' && symbol != '\n')
    {
        symbol = getchar();
        line[i++] = symbol;
    }
    line[i - 1] = '\0';
}

bool isAction(char symbol)
{
    return (symbol == '+' || symbol == '*' || symbol == '-' || symbol == '/');
}

bool isBracket(char symbol)
{
    return (symbol == '(' || symbol == ')');
}

bool convertLine(char* &line)
{
    char *newLine = new char[maxSize];
    int current = 0;
    int i = 0;
    bool mustBeAction = false;
    while (line[i] != '\0')
    {
        if (line[i] == ' ')
        {
            i++;
            continue;
        }
        if (isBracket(line[i]))
        {
            newLine[current++] = line[i];
            i++;
            continue;
        }
        if (mustBeAction)
        {
            if (isAction(line[i]) || line[i] == '\0')
            {
                newLine[current++] = line[i];
                if (line[i] == '\0')
                    break;
                i++;
            }
            else
                return false;
            mustBeAction = false;
        }
        else
        {
            int index = isRealNumber(line, i);
            newLine[current++] = 'R';
            if (i == index)
                return false;
            i = index;
            mustBeAction = true;
        }
    }
    newLine[current++] = '\0';
    delete[] line;
    line = newLine;
    return true;
}

int isCorrect(char *line, int index, int depth)
{
    const int maxDepth = 10;
    if (depth > maxDepth)
        return index;
    const int amountOfWays = 10;
    int indexToReturn = index;
    char *expressions[amountOfWays] = {"R", "R+E", "R-E", "R*E", "R/E", "(E)",
                                       "E+E", "E-E", "E*E", "E/E"};
    for (int k = 0; k < amountOfWays; k++)
    {
        int currentIndex = index;
        int i = 0;
        while (expressions[k][i] != '\0')
        {
            if (expressions[k][i] == 'E')
            {
                int newIndex = isCorrect(line, currentIndex, depth + 1);
                if (newIndex == currentIndex)
                    currentIndex = index;
                else
                    currentIndex = newIndex;
            }
            else
                if (line[currentIndex] != expressions[k][i])
                {
                    currentIndex = index;
                    break;
                }
                else
                {
                    currentIndex++;
                }
            i++;
        }
        if (currentIndex > indexToReturn)
            indexToReturn = currentIndex;
    }
    return indexToReturn;
}

int main()
{
    const int firstSymbolOfLine = 0;
    const int firstLevel = 0;
    char *line = new char[maxSize];
    cout << "Enter a math's expression: " << endl;
    readLine(line);

    if (convertLine(line))
    {
        cout << line << endl;
        cout << "Expression: ";
        int index = isCorrect(line, firstSymbolOfLine, firstLevel);
        if (line[index] == '\0')
            cout << "Ok" << endl;
        else
            cout << "Error in position " << index << endl;
    }
    else
    {
        cout << "Incorrect expression!" << endl;
    }
    delete[] line;

    return 0;
}
