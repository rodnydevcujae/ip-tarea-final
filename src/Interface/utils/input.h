
#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Logic/data.h"
#include "Logic/utils.h"
#include "colors.h"

bool getInput(char input[], int maxbuffer);
int requestSelect (const char *message, char options[][SELECT_S], int len);
bool requestName (const char *message, char name[NAME_S], InterYearTeam teams[5], int opt);
bool requestSportSelect (const char *message, char sport[SPORT_S]);

#endif