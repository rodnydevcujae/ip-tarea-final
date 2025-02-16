#include <stdio.h>
#include "Logic/data.h"
#include "Interface/menu.h"
#include "Logic/logic.h"

int main() {
  InterYearTeam teams[5];
  
  clearTeams(teams);
  displayAppInfo();
  printSep();
  displayMainMenu(teams);
  return 0;
}
