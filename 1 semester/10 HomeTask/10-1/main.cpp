#include <iostream>

using namespace std;

bool isZero(char symbol)
{
    return symbol == '0';
}

bool isDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

bool isSign(char symbol)
{
    return symbol == '+' || symbol == '-';
}

enum State
{
    start,
    finish,
    other,
    hasSign,
    integerPart,
    beginsWithZero,
    firstDigitOfFractionalPart,
    fractionalPart,
    hasExponentPart,
    hasSignOfExponentNumber,
    exponentNumber
};

bool isRealNumber(char *line)
{
    int i = 0;
    State condition = start;

    while (true)
    {
        char symbol = line[i];
        switch (condition)
        {
        case start:
            if (isDigit(symbol) && !isZero(symbol))
                condition = integerPart;
            else
            if (isSign(symbol))
                condition = hasSign;
            else
            if (isZero(symbol))
                condition = beginsWithZero;
            else
                condition = other;
            break;
        case hasSign:
            if (isDigit(symbol) && !isZero(symbol))
                condition = integerPart;
            else
            if (isZero(symbol))
                condition = beginsWithZero;
            else
                condition = other;
            break;
        case integerPart:
            if (symbol == '.')
                condition = firstDigitOfFractionalPart;
            else
            if (symbol == 'E' || symbol == 'e')
                condition = hasExponentPart;
            else
            if (!isDigit(symbol))
                condition = other;
            break;
        case beginsWithZero:
            if (symbol == '.')
                condition = firstDigitOfFractionalPart;
            else
                condition = other;
            break;
        case firstDigitOfFractionalPart:
            if (isDigit(symbol))
                condition = fractionalPart;
            else
                condition = other;
            break;
        case fractionalPart:
            if (symbol == 'E' || symbol == 'e')
                condition = hasExponentPart;
            else
            if (!isDigit(symbol))
                condition = other;
            break;
        case hasExponentPart:
            if (isSign(symbol))
                condition = hasSignOfExponentNumber;
            else
            if (isDigit(symbol) && !isZero(symbol))
                condition = exponentNumber;
            else
                condition = other;
            break;
        case hasSignOfExponentNumber:
            if (isDigit(symbol) && !isZero(symbol))
                condition = exponentNumber;
            else
                condition = other;
            break;
        case exponentNumber:
            if (!isDigit(symbol))
                condition = other;
            break;
        case other:
            return false;
        }
        i++;
        if (line[i] == '\0')
        {
            if (condition == integerPart || condition == fractionalPart ||
                condition == exponentNumber || condition == beginsWithZero)
                condition = finish;
            break;
        }
    }
    return condition == finish;
}

int main()
{
    const int maxSize = 1000;
    char *line = new char[maxSize];
    cout << "Enter a real number: " << endl;
    cin >> line;

    if (isRealNumber(line))
        cout << "OK!!!" << endl;
    else
        cout << "Wrong." << endl;

    delete[] line;

    return 0;
}
