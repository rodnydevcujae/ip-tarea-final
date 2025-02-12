
#include "logic.h"

/**
 * Vaciar 
 */
void clearTeams (InterYearTeam teams[5]) {
  int i;

  for (i = 0; i < 5; i++) {
    teams[i].playersLen = 0;
    teams[i].responsible[0] = '\0';
  }
}

/**
 * Verificar si tiene al menos un participante
 */
bool hasPlayers (InterYearTeam teams[5]) {
  int i = 0, j;
  bool valid = false;

  while (!valid && i < 5) {
    if (teams[i].playersLen) {
      valid = true;
    }
    else i++;
  }

  return valid;
}
