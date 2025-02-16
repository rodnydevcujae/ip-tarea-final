#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include <string.h>
#include "colors.h"
#include "Logic/logic.h"

void printIntro(char *message);
void printLog(char *message);
void printlLog(char *message);
void printOutro(char *message);

void printInfo(char *message);
void printlInfo(char *message);

void printError(char *message);
void printlError(char *message);

void printSep();

void printPlayer(Player player);
void printTeam(InterYearTeam team);

#endif