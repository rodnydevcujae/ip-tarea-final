
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Logic/utils.h"
#include "colors.h"

#define SELECT_S 100

bool getInput(char input[], int maxbuffer);
int requestSelect(char options[][SELECT_S], int len);
