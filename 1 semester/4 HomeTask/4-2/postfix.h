#pragma once

#include <stdlib.h> 
#include "stack.h"

char *convertToPostfix(char *infix);

bool isNumber(char symbol);
int countPriority(char action);