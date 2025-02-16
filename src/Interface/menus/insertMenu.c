
#include "insertMenu.h"

/**
 * Menú principal/Introducir datos
 */
void displayInsertMenu (InterYearTeam teams[5], int teamId) {
  int choice;
  int i;
  char temp[100];
  char teamSelect[6][SELECT_S]; // los 5 años + opción menu principal = 6
  char menuSelect[5][SELECT_S] = {
    "(+) Añadir participante",
    "(-) Eliminar participante",
    "(*) Editar representante de la FEU",
    "... Seleccionar otro año",
    "... Menú Principal",
  };
  
  printlInfo("< Menú Introducir datos >");
  // si ya se seleccionó un año
  if (teamId) {
    i = teamId - 1;
    
    // mostrar información parcial del año
    sprintf(temp, "%s", teams[i].nickname);
    printlLog(temp);

    sprintf(temp, "Participantes: %d", teams[i].playersLen);
    printlLog(temp);
    
    sprintf(temp, "FEU: %s", 
      strlen(teams[i].responsible) > 0 ?
        teams[i].responsible : "(no asignado)" 
    );
    printLog(temp);
    
    // menu
    choice = requestSelect("", menuSelect, 5);
    printSep();
    switch (choice) {
      case 1:
        displayAddPlayer(&teams[i]);
        printSep();
        displayInsertMenu(teams, teamId);
        break;
      
      case 2:
        displayRemovePlayer(&teams[i]);
        printSep();
        displayInsertMenu(teams, teamId);
        break;
      
      case 3:
        displayEditResponsible(&teams[i]);
        printSep();
        displayInsertMenu(teams, teamId);
        break;
        
      case 4:
        displayInsertMenu(teams, 0);
        break;

      case 5:
        displayMainMenu(teams);
        break;
    }
  }
  // si aun no se ha seleccionado un año
  else {
    printLog("");

    createTeamSelect(teams, teamSelect);
    strcpy(teamSelect[5], "... Menú principal");

    choice = requestSelect("Dónde desea modificar los datos?", teamSelect, 6);
    printSep();
    if (choice == 6) {
      displayMainMenu(teams);
    }
    else {
      displayInsertMenu(teams, choice);
    }
  }
  
}

/**
 * Introducir datos/Opción 1
 */
void displayAddPlayer (InterYearTeam *team) {
  Player player;
  char temp[100];

  // arreglos de menus
  char sexMenu[2][SELECT_S] = {
    "Masculino",
    "Femenino"
  };
  char medalMenu[2][SELECT_S] = {
    "(+) Es medallista",
    "(-) No ha ganado una medalla"
  };
  
  printInfo("< Añadir participante >");
  
  // Caben más participantes?
  if (team->playersLen < PLAYERS_S) {

    // pedir nombre
    requestName("Ingrese el nombre", player.name);
    
    // pedir genero
    if (requestSelect("", sexMenu, 2) == 1) {
      player.sex = 'M';
    }
    else {
      player.sex = 'F';
    }
    
    // pedir deporte
    printlLog("");
    requestSportSelect("En que deporte participó?", player.sport);
    
    // es medallista?
    printlLog("");
    player.hasMedal = requestSelect("", medalMenu, 2) == 1;

    // añadir a los datos
    team->players[team->playersLen++] = player;
    
    printlLog("");
    printlInfo("Participante añadido exitosamente!");
    printPlayer(player);
  }

  else {
    sprintf(temp, "Ups!!! Ya se alcanzó el máximo de participantes en este año (%d)", PLAYERS_S);
    printError(temp);
  }
}

/**
 * Introducir datos/Opción 2
 */
void displayRemovePlayer (InterYearTeam *team) {
  int i;
  int choice;
  char playersMenu[PLAYERS_S][SELECT_S];
  char temp[SELECT_S];
  int len = team->playersLen;


  for (i = 0; i < len; i++) {
    sprintf(temp, "%s[X]%s %s %s[%s%s%s]%s", RED, RESET, team->players[i].name, CYAN, RESET, team->players[i].sport, CYAN, RESET);
    strcpy(playersMenu[i], temp);
  }

  strcpy(playersMenu[len++], "... Atrás");
  choice = requestSelect("Seleccione el participante que quiere eliminar", playersMenu, len);

  if (choice < len) {
    sprintf(temp, "Participante [%s] eliminado exitosamente", team->players[choice - 1].name);
    team->playersLen--;
    for (i = choice - 1; i < team->playersLen; i++) {
      team->players[i] = team->players[i + 1];
    }
    printInfo(temp);
  }
}

/**
 * Introducir datos/Opción 3
 */
void displayEditResponsible (InterYearTeam *team) {
  int i;
  char temp[100];

  if (strlen(team->responsible) > 0) {
    sprintf(temp, "%sActual:%s %s", CYAN, RESET, team->responsible);
    printlInfo(temp);
  }
  requestName("Ingrese el nuevo nombre para el responsable de la FEU", team->responsible);

  sprintf(temp, "FEU %s", team->nickname);
  printlInfo(temp);
  printLog(team->responsible);
}

