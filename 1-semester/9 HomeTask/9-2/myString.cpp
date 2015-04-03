#include "myString.h"

struct MyString
{
    char *line;
    int length;
    int maxSize;
};

char *increaseLine(char *line, int &maxSize)
{
    int oldSize = maxSize;
    maxSize *= 2;
    char *newLine = new char[maxSize];
    for (int i = 0; i < oldSize; i++)
        newLine[i] = line[i];
    delete[] line;
    return newLine;
}

bool isNormalSymbol(char symbol)
{
    return ((symbol >= 'a' && symbol <= 'z') ||
           (symbol >= 'A' && symbol <= 'Z') ||
           (symbol >= '0' && symbol <= '9'));
}

char *readLine(int &length, int &maxSize)
{
    int current = 0;
    char *line = new char[maxSize];
    char symbol = '0';
    while (isNormalSymbol(symbol))
    {
        symbol = getchar();
        if (isNormalSymbol(symbol))
        {
            if (current == maxSize)
                line = increaseLine(line, maxSize);
            line[current++] = symbol;
        }
    }
    line[current] = '\0';
    length = current;
    return line;
}

char *readLine(int &length, int &maxSize, ifstream &in)
{
    int current = 0;
    char *line = new char[maxSize];
    char symbol = 'a';
    while (isNormalSymbol(symbol))
    {
        symbol = in.get();
        if (isNormalSymbol(symbol))
        {
            if (current == maxSize)
                line = increaseLine(line, maxSize);
            line[current++] = symbol;
        }
    }
    line[current] = '\0';
    length = current;
    return line;
}

MyString *createString(char *line, int length, int maxSize)
{
    MyString *myString = new MyString;
    myString->line = line;
    myString->length = length;
    myString->maxSize = maxSize;
    return myString;
}

MyString *readString()
{
    int length = 0;
    int maxSize = 10;
    char *line = readLine(length, maxSize);
    return createString(line, length, maxSize);
}

MyString *readString(ifstream &in)
{
    int length = 0;
    int maxSize = 10;
    char *line = readLine(length, maxSize, in);
    return createString(line, length, maxSize);
}

void deleteString(MyString* myString)
{
    delete[] myString->line;
    delete myString;
}

MyString *cloneString(MyString *myString)
{
    int length = myString->length;
    int maxSize = myString->maxSize;
    char *line = myString->line;
    char *newLine = new char[maxSize];
    for (int i = 0; i < length; i++)
        newLine[i] = line[i];
    newLine[length] = '\0';
    MyString *newString = createString(newLine, length, maxSize);
    return newString;
}

void printString(MyString *myString)
{
    char *line = myString->line;
    cout << line << endl;
}

void concatenateStrings(MyString *myString, MyString *tail)
{
    int maxSize = myString->maxSize;
    int current = myString->length;
    char *line = myString->line;
    char *lineToAdd = tail->line;
    int size = tail->length;
    for (int i = 0; i <= size; i++)
    {
        if (current == maxSize)
            line = increaseLine(line, maxSize);
        line[current++] = lineToAdd[i];
    }
    myString->line = line;
    myString->length = current;
    myString->maxSize = maxSize;
}

bool areEqual(MyString *first, MyString *second)
{
    return !strcmp(first->line, second->line);
}

int getLength(MyString *myString)
{
    return myString->length;
}

bool isEmpty(MyString *myString)
{
    return myString->length == 0;
}

MyString *chooseSubstring(MyString *myString, int index, int length)
{
    char *line = myString->line;
    char *newLine = new char[length];
    for (int i = 0; i < length; i++)
        newLine[i] = line[index++];
    newLine[length] = '\0';
    MyString *newString = createString(newLine, length, length);
    return newString;
}

char *convertToChar(MyString *myString)
{
    int length = myString->length;
    char *line = myString->line;
    char *newLine = new char[length];
    for (int i = 0; i <= length; i++)
        newLine[i] = line[i];
    return newLine;
}


