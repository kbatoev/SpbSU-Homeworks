#pragma once

#include <iostream>

using namespace std;

struct Node;
struct Tree;

Tree *createTree();
void deleteTree(Tree *tree);

void addElement(Tree *tree, int value);

void deleteElement(Tree *tree, int value);
bool exists(Tree *tree, int value);

void printDecreasingOrder(Tree *tree);
void printIncreasingOrder(Tree *tree);
void printPreorder(Tree *tree);
