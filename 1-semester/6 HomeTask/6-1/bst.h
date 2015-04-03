#pragma once

#include <iostream>

using namespace std;

struct BSTreeNode;
struct BSTree;

BSTree *createBSTree();
void deleteBSTree(BSTree *tree);

void addElement(BSTree *tree, int value);
void deleteElement(BSTree* tree, int value);
bool exists(BSTree *tree, int value);

void printDecreasingOrder(BSTree *tree);
void printIncreasingOrder(BSTree *tree);
void printPreorder(BSTree *tree);
