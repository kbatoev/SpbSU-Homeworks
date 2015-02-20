#pragma once

#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

struct HashTable;

const int hashTableSize = 1000;

HashTable *createHashTable();
void deleteHashTable(HashTable *table);

void addLine(HashTable *table, char *line);

double showLoadFactor(HashTable *table);
double showAverageLength(HashTable *table);

int showMaxLengthOfChain(HashTable *table);
void showStringsInMaxChain(HashTable *table);

int showAmountOfWords(HashTable *table);
int showEmptyCells(HashTable *table);

void printHashTable(HashTable *table, ofstream &out);

