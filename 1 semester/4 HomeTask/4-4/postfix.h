#pragma once

#include <stdlib.h> 
#include "stack.h"

char *convertToPostfix(char *infix);

bool isFigure(char symbol);
int countPriority(char action);