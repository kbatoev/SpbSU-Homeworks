#include <iostream>
#include <fstream>
#include "myString.h"

using namespace std;

const int primeNumber = 67;
const int factor = 58;

int countHash(MyString *myString, int patternLength)
{
    int result = 0;
    char *line = convertToChar(myString);
    for (int i = 0; i < patternLength; i++)
        result = (result * factor + line[i]) % primeNumber;
    return result;
}

int countMaxFactor(int patternLength)
{
    int result = 1;
    for (int i = 0; i < patternLength; i++)
        result = (result * factor) % primeNumber;
    return result;
}

int renewHash(int currentHash, char symbolToAdd, char symbolToSubtract, int maxFactor)
{
    currentHash = (currentHash - symbolToSubtract * maxFactor) % primeNumber;
    if (currentHash < 0)
        currentHash += primeNumber;
    currentHash = (currentHash * factor) % primeNumber;
    currentHash = (currentHash + symbolToAdd) % primeNumber;
    return currentHash;
}

bool isFoundPattern(MyString *myString, MyString *pattern)
{
    bool isFound = false;

    int patternLength = getLength(pattern);
    int lineLength = getLength(myString);
    int maxFactor = countMaxFactor(patternLength - 1);

    if (patternLength > lineLength)
        return isFound;
    int patternHash = countHash(pattern, patternLength);
    int currentHash = countHash(myString, patternLength);
    char *line = convertToChar(myString);
    for (int i = patternLength; i < lineLength + 1; i++)
    {
        if (patternHash == currentHash)
        {
            MyString *currentString = chooseSubstring(myString, i - patternLength, patternLength);
            if (areEqual(currentString, pattern))
            {
                isFound = true;
                cout << i - patternLength << " ";
            }
            deleteString(currentString);
        }
        if (i < lineLength)
            currentHash = renewHash(currentHash, line[i], line[i - patternLength], maxFactor);
    }
    return isFound;
}

int main()
{
    ifstream in("test.txt");
    //cout << "Enter a line: " << endl;
    MyString *line = readString(in);

    //cout << "Enter a pattern: " << endl;
    MyString *pattern = readString(in);

    cout << "Current pattern is found on positions: " << endl;
    bool isFound = isFoundPattern(line, pattern);

    if (!isFound)
        cout << "Not found" << endl;

    in.close();
    deleteString(line);
    deleteString(pattern);

    return 0;
}
