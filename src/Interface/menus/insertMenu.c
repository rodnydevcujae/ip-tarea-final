
#include "insertMenu.h"

/**
 * Menú principal/Introducir datos
 */
void displayInsertMenu (InterYearTeam teams[5], int teamId) {
  int choice;
  char temp[200];
  char teamSelect[6][SELECT_S]; // los 5 años + opción menu principal = 6
  char menuSelect[4][SELECT_S] = {
    "(+) Añadir participante",
    "(-) Eliminar participante",
    "(*) Editar representante de la FEU",
    "... Atrás"
  };
  
  printlInfo("< Menú Introducir datos >");
  // si ya se seleccionó un año
  if (teamId > -1) {
    
    // mostrar información parcial del año
    sprintf(temp, "%s", teams[teamId].nickname);
    printlLog(temp);

    sprintf(temp, "Participantes: %d", teams[teamId].playersLen);
    printlLog(temp);
    
    sprintf(temp, "FEU: %s", 
      strlen(teams[teamId].responsible) > 0 ?
        teams[teamId].responsible : "(no asignado)" 
    );
    printLog(temp);
    
    // menu
    choice = requestSelect("", menuSelect, 4);
    
    clearLogs();
    printIntro("");

    switch (choice) {
      case 1:
        displayAddPlayer(teams, teamId);
        displayInsertMenu(teams, teamId);
        break;
      
      case 2:
        displayRemovePlayer(&teams[teamId]);
        displayInsertMenu(teams, teamId);
        break;
      
      case 3:
        displayEditResponsible(teams, teamId);
        displayInsertMenu(teams, teamId);
        break;
        
      case 4:
        displayInsertMenu(teams, -1);
        break;
    }
  }
  // si aun no se ha seleccionado un año
  else {
    printLog("");

    createTeamSelect(teams, teamSelect);
    strcpy(teamSelect[5], "... Menú principal");

    choice = requestSelect("Dónde desea modificar los datos?", teamSelect, 6);

    clearLogs();
    printIntro("");
    if (choice < 6) {
      displayInsertMenu(teams, choice - 1);
    }
  }
  
}

/**
 * Introducir datos/Opción 1
 */
void displayAddPlayer (InterYearTeam teams[5], int teamId) {
  Player player;
  char temp[200];
  int choice;
  bool userCancel = false;

  // arreglos de menus
  char sexMenu[3][SELECT_S] = {
    "Masculino",
    "Femenino",
    "... Cancelar"
  };
  char medalMenu[3][SELECT_S] = {
    "(+) Es medallista",
    "(-) No ha ganado una medalla",
    "... Cancelar"
  };
  char confirmMenu[2][SELECT_S] = {
    "Añadir",
    "Cancelar"
  };
  
  printInfo("< Añadir participante >");
  
  // Caben más participantes?
  if (teams[teamId].playersLen < PLAYERS_S) {

    // pedir nombre
    userCancel = requestName("Ingrese el nombre del participante (0 para cancelar)", player.name, teams, 1);
    
    if (!userCancel) {

      //  pedir genero
      printlLog("");
      choice = requestSelect("", sexMenu, 3);
      userCancel = choice == 3;
      
      if (!userCancel) {
        player.sex = choice == 1 ? 'M' : 'F';
    
        // pedir deporte
        printlLog("");
        userCancel = requestSportSelect("En que deporte participó?", player.sport);
        
        if (!userCancel) {
          // es medallista?
          printlLog("");
          choice = requestSelect("", medalMenu, 3);
          userCancel = choice == 3;
          
          if (!userCancel) {
            
            clearLogs();
            printIntro("");
            printlInfo("Participante creado.");
            printPlayer(player);
            printlLog("");
            userCancel = requestSelect("", confirmMenu, 2) == 2;
            
            // añadir a los datos
            if (!userCancel) {
              addPlayer(&teams[teamId], player);
              clearLogs();
              printIntro("");
              printlInfo("Participante añadido exitosamente!");
              printSep();
            } 
          }

        }
      }
    }
  }
  else {
    sprintf(temp, "Ups!!! Ya se alcanzó el máximo de participantes en este año (%d)", PLAYERS_S);
    printError(temp);
  }

  if (userCancel) {
    clearLogs();
    printIntro("");
    printInfo("Operación cancelada");
    printSep();
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
    sprintf(temp, RED "[X]" RESET " %s " CYAN "[%s]" RESET, team->players[i].name, team->players[i].sport);
    strcpy(playersMenu[i], temp);
  }

  strcpy(playersMenu[len++], "... Atrás");
  choice = requestSelect("Seleccione el participante que quiere eliminar", playersMenu, len);

  clearLogs();
  if (choice < len) {
    removePlayer(team, choice - 1);
    printIntro("");
    sprintf(temp, "Participante [%s] eliminado exitosamente", team->players[choice - 1].name);
    printInfo(temp);
    printSep();
  }
  else {
    printIntro("");
  }
}

/**
 * Introducir datos/Opción 3
 */
void displayEditResponsible (InterYearTeam teams[5], int teamId) {
  char temp[200];
  bool userCancel = false;

  if (strlen(teams[teamId].responsible) > 0) {
    sprintf(temp, CYAN "Actual:" RESET " %s", teams[teamId].responsible);
    printlInfo(temp);
  }
  userCancel = requestName("Ingrese el nuevo nombre para el responsable de la FEU (0 para regresar)", teams[teamId].responsible, teams, 2);
  
  clearLogs();
  if (!userCancel) {
    sprintf(temp, "FEU %s", teams[teamId].nickname);
    printlInfo(temp);
    printLog(teams[teamId].responsible);
    printOutro("");
    printf("\n");
  }

  printIntro("");
}

