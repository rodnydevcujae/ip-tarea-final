#include <stdio.h>
#include "Logic/data.h"
#include "Interface/menu.h"
#include "Logic/logic.h"

int main() {
  InterYearTeam teams[5];
  char sports[][SPORT_S] = {
    "fútbol",
    "baloncesto",
    "voleibol",
    "béisbol",
    "dominó",
    "ajedrez"
  };
  
  clearTeams(teams);
  displayAppInfo();
  displayMainMenu(teams);
  return 0;
}