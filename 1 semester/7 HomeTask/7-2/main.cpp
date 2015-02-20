#include <iostream>
#include "myString.h"

using namespace std;

int main()
{
    MyString *myString = createString();
    MyString *clone = cloneString(myString);
    printString(clone);

    if (areEqual(clone, myString))
        cout << "Cloning procedure is correct" << endl;
    else
        cout << "Something wrong :(" << endl;

    concatenateStrings(clone, myString);
    printString(clone);
    cout << "Size of string is " << countLength(clone) << endl;
    if (isEmpty(clone))
        cout << "MyString is empty" << endl;
    else
        cout << "MyString isn't empty" << endl;

    MyString *substring = chooseSubstring(myString);
    printString(substring);

    char *line = convertToChar(myString);
    cout << line << endl;

    deleteString(myString);
    deleteString(clone);
    deleteString(substring);
    delete[] line;

    return 0;
}

