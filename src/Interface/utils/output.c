#include "output.h"

/**
 * Estos son un conjunto de funciones printf decoradas
 */


void printIntro(char *message) {
  if (message[0] != '\0') {
    printf(" %s %s\n", IMG2, message);
  }
  else {
    printf(" %s\n", IMG2E);
  }
}

void printLog(char *message) {
  printf(" %s %s\n %s \n", IMG1, message, IMG1);
}
void printlLog(char *message) {
  printf(" %s %s\n", IMG1, message);
}

void printOutro(char *message) {
  if (message[0] != '\0') {
    printf(" %s %s\n", IMG3, message);
  }
  else {
    printf(" %s\n", IMG3E);
  }
}


void printInfo(char *message) {
  printf(" %s%s%s %s\n %s \n", CYAN, IMG4, RESET, message, IMG1);
}
void printlInfo(char *message) {
  printf(" %s%s%s %s\n", CYAN, IMG4, RESET, message);
}

void printError(char *message) {
  printf(" %s%s%s %s\n %s \n", RED, IMG8, RESET, message, IMG1);
}
void printlError(char *message) {
  printf(" %s%s%s %s\n", RED, IMG8, RESET, message);
}

/**
 * Imprimir separacion entre menus
 */
void printSep() {
  printOutro("");
  printf("\n");
  printIntro("");
}

/**
 * Mostrar ficha de jugador
 */
void printPlayer(Player player) {
  char temp[100];

  printf(" %s    ", IMG1);
  sprintf(temp, "%s #: %s", IMG7, player.name);
  printIntro(temp);

  printf(" %s    ", IMG1);
  sprintf(temp, "%s Género: %c", IMG7, player.sex);
  printlLog(temp);
  
  printf(" %s    ", IMG1);
  sprintf(temp, "%s %s%s%s", IMG7, CYAN, player.sport, RESET);
  printlLog(temp);
  
  printf(" %s    ", IMG1);
  if (player.hasMedal) {
    sprintf(temp, "%s%s Medallista %s", YELLOW, IMG4, RESET);
  }
  else {
    sprintf(temp, "%s%s - %s", YELLOW, IMG5, RESET);
  } 
  
  printOutro(temp);
}

/**
 * Mostrar ficha de equipo
 */
void printTeam(InterYearTeam team) {
  char temp[100];

  printf(" %s    ", IMG1);
  sprintf(temp, "%s #: %s", IMG7, team.nickname);
  printIntro(temp);

  printf(" %s    ", IMG1);
  sprintf(temp, "%s Participantes: %d", IMG7, team.playersLen);
  printlLog(temp);
  
  printf(" %s    ", IMG1);
  sprintf(temp, "%s FEU: %s", IMG7, 
    strlen(team.responsible) > 0 ? 
      team.responsible : 
      "(no asignado)"
  );
  printlLog(temp);
  
  printf(" %s    ", IMG1);
  sprintf(temp, "%s%s Medallas: %s%d ", YELLOW, IMG4, RESET, getMedals(team));
  printOutro(temp);
}
