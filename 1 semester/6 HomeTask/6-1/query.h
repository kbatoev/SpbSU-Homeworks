#pragma once

#include <iostream>
#include "bst.h"

using namespace std;

void addToBST(BSTree *tree);
void deleteFromBST(BSTree *tree);
void subsists(BSTree *tree);

void showDecrescentOrder(BSTree *tree);
void showIncrescentOrder(BSTree *tree);
void showPreorder(BSTree *tree);

void startMenu();
