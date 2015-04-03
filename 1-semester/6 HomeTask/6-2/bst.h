#pragma once

#include <iostream>

using namespace std;

struct BSTreeNode;
struct BSTree;

BSTree *createBSTree();
void deleteBSTree(BSTree *tree);

void addElement(BSTree *tree, int number, char operation);
bool isOperation(char operation);

void printInfix(BSTree *tree);

int countExpression(BSTree *tree);
