#include <iostream>
#include <fstream>
#include "hashtable.h"

using namespace std;

int main()
{
    HashTable *table = createHashTable();

    ifstream in("test.txt");
    const int maxSizeOfLine = 1000;
    char *line = new char[maxSizeOfLine];
    while (in >> line)
        addLine(table, line);

    cout << "Load factor is: " << showLoadFactor(table) << endl;
    cout << "Average length of chain is: " << showAverageLength(table) << endl;
    cout << "Amount of words is: " << showAmountOfWords(table) << endl;
    cout << "Amount of empty cells is: " << showEmptyCells(table) << endl;
    cout << "Max length of chain is: " << showMaxLengthOfChain(table) << endl;
    cout << "Words of max chain are: " << endl;
    showStringsInMaxChain(table);
    cout << endl;

    ofstream out("output.txt");
    printHashTable(table, out);

    out.close();
    delete[] line;
    in.close();
    deleteHashTable(table);

    return 0;
}

