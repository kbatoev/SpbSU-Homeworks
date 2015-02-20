#include "hashtable.h"

struct HashTable
{
    double loadFactor;
    double averageLength;
    int words;
    int places;
    int index;
    List *array[hashTableSize];
};

HashTable *createHashTable()
{
    HashTable *table = new HashTable;
    table->words = 0;
    table->loadFactor = 0;
    table->averageLength = 0;
    table->index = -1;
    table->places = 0;
    for (int i = 0; i < hashTableSize; i++)
        table->array[i] = createList();
    return table;
}

int hashFunction(const char *line)
{
    int primeNumber = 71;
    int factor = 1;
    int i = 0;
    int sum = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        sum = (sum + factor * line[i++]) % hashTableSize;
        if (sum < 0)
            sum += hashTableSize;
        factor = (factor * primeNumber) % hashTableSize;
    }
    return sum;
}

bool isNewIndex(int i, HashTable *table)
{
    return showNext(table->array[i]);
}

bool isMaxChain(int i, HashTable *table)
{
    if (table->index == -1)
        return true;
    else
    {
        int j = table->index;
        int maxAmount = getAmount(table->array[j]);
        int currentAmount = getAmount(table->array[i]);
        return maxAmount < currentAmount;
    }
}

void addLine(HashTable *table, char *line)
{
    int i = hashFunction(line);
    MyString *myString = createString(line);

    if (isNewIndex(i, table))
        table->places++;

    table->words++;
    table->loadFactor = (double)table->words / (double)hashTableSize;
    table->averageLength = (double)table->words / table->places;
    addElement(myString, table->array[i]);
    if (isMaxChain(i, table))
        table->index = i;
}

void deleteHashTable(HashTable *table)
{
    for (int i = 0; i < hashTableSize; i++)
        deleteList(table->array[i]);
    delete[] table;
}

double showLoadFactor(HashTable *table)
{
    return table->loadFactor;
}

double showAverageLength(HashTable *table)
{
    return table->averageLength;
}

int showMaxLengthOfChain(HashTable *table)
{
    if (table->index != -1)
        return getAmount(table->array[table->index]);
    else
        return 0;
}

void showStringsInMaxChain(HashTable *table)
{
    if (table->index != -1)
        printList(table->array[table->index]);
}

int showAmountOfWords(HashTable *table)
{
    return table->words;
}

int showEmptyCells(HashTable *table)
{
    return hashTableSize - table->places;
}

void printHashTable(HashTable *table, ofstream &out)
{
    for (int i = 0; i < hashTableSize; i++)
    {
        if (!isNewIndex(i, table))
        {
            out << "Key " << i << " has " << getAmount(table->array[i]) << " words: " << endl;
            printList(table->array[i], out);
            out << endl;
        }
    }
}

bool isInHashTable(HashTable *table, char *line)
{
    int i = hashFunction(line);
    MyString *myString = createString(line);

    return isInList(myString, table->array[i]);
}
