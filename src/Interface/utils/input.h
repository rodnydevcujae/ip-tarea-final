
#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Logic/data.h"
#include "Logic/utils.h"
#include "colors.h"

bool getInput(char input[], int maxbuffer);
int requestSelect(char *message, char options[][SELECT_S], int len);
void requestName(const char *message, char name[NAME_S]);
void requestSportSelect (const char *message, char sport[SPORT_S]);

#endif