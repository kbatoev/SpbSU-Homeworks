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
    bool letter[numberOfLettersInEnglish];
    for (int i = 0; i < numberOfLettersInEnglish; i++)
        letter[i] = false;

    for (int i = 0; i < arraySize; i++)
        if (!letter[line[i] - 'a'])
            letter[line[i] - 'a'] = true;

    int counter = 0;
    int letterPos[numberOfLettersInEnglish];
    for (int i = 0; i < numberOfLettersInEnglish; i++)
        if (letter[i])
            letterPos[i] = counter++;
        else
            letterPos[i] = arraySize + 1;

    counter = 0;
    for (int i = 0; i < arraySize; i++)
    {
        int number = line[i] - 'a';
        array[counter++] = letterPos[number];
        for (int k = 0; k < numberOfLettersInEnglish; k++)
            if (letterPos[k] < letterPos[number])
                letterPos[k]++;
        letterPos[number] = 0;
    }
}

void MoveToFront::print()
{
    for (int i = 0; i < arraySize; i++)
        std::cout << array[i] << " ";
}

