#include "movetofront.h"

MoveToFront::~MoveToFront()
{
    delete[] array;
}

int *MoveToFront::getResult()
{
    transform();
    return array;
}

void MoveToFront::transform()
{
    bool letter[numberOfLettersInEnglish] = {false};
    int numberOfUniqueLetters = 0;
    for (int i = 0; i < line.size(); i++)
        if (!letter[line[i] - 'a'])
        {
            letter[line[i] - 'a'] = true;
            numberOfUniqueLetters++;
        }

    int j = 0;
    int letterPos[numberOfUniqueLetters];
    for (int i = 0; i < numberOfLettersInEnglish; i++)
        letterPos[i] = i;

    j = 0;
    for (int i = 0; i < line.size(); i++)
    {
        int number = line[i] - 'a';
        array[j++] = letterPos[number];
        for (int k = 0; k < numberOfLettersInEnglish; k++)
            if (letterPos[k] < letterPos[number])
                letterPos[k]++;
        letterPos[number] = 0;
    }
}

void MoveToFront::print()
{
    for (int i = 0; i < line.size(); i++)
        std::cout << array[i] << " ";
}

