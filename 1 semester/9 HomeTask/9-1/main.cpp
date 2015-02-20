#include <iostream>
#include "hashtable.h"

using namespace std;

int main()
{
    const int maxSize = 10000;
    FILE *file = fopen("test1.txt", "r");
    cout << "I will open test1.txt and test2.txt and find equal lines." << endl;

    HashTable* table = createHashTable();

    char *line = new char[maxSize];
    while (!feof(file))
    {
        fgets(line, maxSize, file);
        addLine(table, line);
    }

    file = fopen("test2.txt", "r");
    FILE *out = fopen("out.txt", "w");
    while (!feof(file))
    {
        fgets(line, maxSize, file);
        if (isInHashTable(table, line))
            fputs(line, out);
    }

    delete[] line;
    fclose(file);
    fclose(out);
    deleteHashTable(table);
    cout << "Results are in out.txt." << endl;

    return 0;
}

