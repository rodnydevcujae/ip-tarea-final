#include "output.h"

/**
 * Limpiar consola (multiplataforma)
 */
void clearLogs () {
  #if _WIN32
    system("cls");
  #else
    system("clear");
  #endif

  printf("\n");
}

/**
 * Estos son un conjunto de funciones printf decoradas
 */
void printIntro(char *message) {
  if (message[0] != '\0') {
    printf(" " IMG2 " %s\n", message);
  }
  else {
    printf(" " IMG2E "\n");
  }
}

void printLog(char *message) {
  printf(" " IMG1 " %s\n " IMG1 " \n", message);
}
void printlLog(char *message) {
  printf(" " IMG1 " %s\n", message);
}

void printOutro(char *message) {
  if (message[0] != '\0') {
    printf(" " IMG3 " %s\n", message);
  }
  else {
    printf(" " IMG3E "\n");
  }
}

void printInfo(char *message) {
  printf(" " CYAN IMG4 RESET " %s\n " IMG1 " \n", message);
}
void printlInfo(char *message) {
  printf(" " CYAN IMG4 RESET " %s\n", message);
}

void printError(char *message) {
  printf(" " RED IMG8 RESET " %s\n " IMG1 " \n", message);
}
void printlError(char *message) {
  printf(" " RED IMG8 RESET " %s\n", message);
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
  char temp[200];

  printf(" " IMG1 "    ");
  sprintf(temp, IMG7 " #: %s", player.name);
  printIntro(temp);

  printf(" " IMG1 "    ");
  sprintf(temp, IMG7 " Género: %c", player.sex);
  printlLog(temp);
  
  printf(" " IMG1 "    ");
  sprintf(temp, IMG7 CYAN " %s" RESET, player.sport);
  printlLog(temp);
  
  printf(" " IMG1 "    ");
  if (player.hasMedal) {
    printOutro(YELLOW IMG4 " Medallista " RESET);
  }
  else {
    printOutro(YELLOW IMG5 " - " RESET);
  } 
}

/**
 * Mostrar ficha del año
 */
void printTeam(InterYearTeam team) {
  char temp[200];

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
