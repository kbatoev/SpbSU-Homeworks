#pragma once

#include <iostream>
#include "avl-tree.h"

using namespace std;

void addToTree(Tree *tree);
void deleteFromTree(Tree *tree);
void subsists(Tree *tree);

void showDecrescentOrder(Tree *tree);
void showIncrescentOrder(Tree *tree);
void showPreorder(Tree *tree);

void startMenu();
