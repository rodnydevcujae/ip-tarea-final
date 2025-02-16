#include <stdbool.h>
#include <string.h>
#include "data.h"

void clearTeams(InterYearTeam teams[5]);
void generateTeams (InterYearTeam teams[5]);
bool hasPlayers(InterYearTeam teams[5]);

int getMedals (InterYearTeam team);
float getMedalsPercent (InterYearTeam team);
int getBestMedals (InterYearTeam teams[5], int indices[5]);
int getMajorFemSex (InterYearTeam teams[5], int indices[5], int femCounters[5]);
int getPlayers (InterYearTeam team, char sport[SPORT_S], int indices[]);
int createTeamSelect(InterYearTeam teams[5], char options[][SELECT_S]);