
#include "reportMenu.h"

/**
 * Menú Principal/Reportes
 */
void displayReportsMenu (InterYearTeam teams[5]) {
  int choice;
  char menuSelect[6][SELECT_S] = {
    "a) Mostrar año con más medallas",
    "b) Mostrar datos de todos los años",
    "c) Mostrar porcentaje de medallas",
    "d) Mostrar años con mayor cantidad de mujeres",
    "e) Mostrar participantes",
    "... Atrás"
  };

  if (hasPlayers(teams)) {
    printInfo("< Menú de Reportes >");
    choice = requestSelect("", menuSelect, 6);

    clearLogs();
    printIntro("");
    switch (choice) {
      case 1:
        displayReportA(teams);
        displayReportsMenu(teams);
        break;
      
      case 2:
        displayReportB(teams);
        displayReportsMenu(teams);
        break;
      
      case 3:
        displayReportC(teams);
        displayReportsMenu(teams);
        break;
      
      case 4:
        displayReportD(teams);
        displayReportsMenu(teams);
        break;
      
      case 5:
        displayReportE(teams);
        displayReportsMenu(teams);
        break;

      case 6:
        // main menu
        break;
    }
  }
  else {
    printlError("No puede acceder al menú de reportes.");
    printlLog("Los datos están vacíos, introduzca al menos uno.");
    printSep();
  }
}

/**
 * 
 */
void displayReportA (InterYearTeam teams[5]) {
  int indices[5];
  int indicesLen;
  int i;

  char menuSelect[1][SELECT_S] = {
    "... Atrás"
  };
  
  // obtener mejores años
  indicesLen = getBestMedals(teams, indices);
  
  if (indicesLen == 1) {
    printInfo("Año con mayor cantidad de medallas.");
  } 
  else {
    printInfo("Años con mayor cantidad de medallas.");
  }
  
  for(i = 0; i < indicesLen; i++) {
    printTeam(teams[indices[i]]);
  }

  printLog("");
  requestSelect("", menuSelect, 1);
  clearLogs();
  printIntro("");
}

/**
 * 
 */
void displayReportB (InterYearTeam teams[5]) {
  int i;

  char menuSelect[1][SELECT_S] = {
    "... Atrás"
  };
  
  printlInfo("Información de los años");
  
  for(i = 0; i < 5; i++) {
    printTeam(teams[i]);
    printLog("");
  }

  requestSelect("", menuSelect, 1);
  clearLogs();
  printIntro("");
}

/**
 * 
 */
void displayReportC (InterYearTeam teams[5]) {
  int i;
  char temp[200];

  char menuSelect[1][SELECT_S] = {
    "... Atrás"
  };
  
  printInfo("Porcentaje de medallas según participantes:");
  
  sprintf(temp, "%25s %s%s", "Año ", IMG1, " Porcentaje");
  printlLog(temp);
  for(i = 0; i < 5; i++) {
    sprintf(temp, "%25s %s%%%.2f", teams[i].nickname, IMG1, getMedalsPercent(teams[i]));
    printlLog(temp);
  }

  printSep();
  requestSelect("", menuSelect, 1);
  clearLogs();
  printIntro("");
}


/**
 * 
 */
void displayReportD (InterYearTeam teams[5]) {
  int indices[5];
  int femCounters[5];
  int indicesLen;
  int i;
  char temp[200];

  char menuSelect[1][SELECT_S] = {
    "... Atrás"
  };
  
  // obtener años con más participación femenina que masculina
  indicesLen = getMajorFemSex(teams, indices, femCounters);
  
  switch (indicesLen) {
    case 0:
      printError("No hay años donde la participación femenina supera la masculina.");
      break;
    case 1:
      printInfo("Año donde la participación femenina supera la masculina:");
      break;
    default:
      printInfo("Años donde la participación femenina supera la masculina:");
  } 
  
  for(i = 0; i < indicesLen; i++) {
    sprintf(temp, "%s #: %s", IMG7, teams[indices[i]].nickname);
    printf(" %s    ", IMG1);
    printIntro(temp);

    sprintf(temp, "%s Part. Femenina: %d", IMG7, femCounters[i]);
    printf(" %s    ", IMG1);
    printlLog(temp);
    
    sprintf(temp, "%s Part. Masculina: %d", IMG7, 
      teams[indices[i]].playersLen - femCounters[i]
    );
    printf(" %s    ", IMG1);
    printOutro(temp);
    printLog("");
  }

  requestSelect("", menuSelect, 1);
  clearLogs();
  printIntro("");
}

/**
 * 
 */
void displayReportE (InterYearTeam teams[5]) {
  int indices[PLAYERS_S];
  int indicesLen;
  int choice;
  int teamIndex;
  char sport[SPORT_S];
  int i;
  char temp[200];

  char teamSelect[6][SELECT_S];
  char menuSelect[1][SELECT_S] = {
    "... Atrás"
  };

  createTeamSelect(teams, teamSelect);
  strcpy(teamSelect[5], "... Cancelar");
  choice = requestSelect("De que año desea ver los participantes?", teamSelect, 6);
  if (choice < 6) {
    teamIndex = choice - 1;
    printlLog("");
    if (!requestSportSelect("Deporte a obtener.", sport)) {
      indicesLen = getPlayers(teams[teamIndex], sport, indices);
      printSep();
      
      switch (indicesLen) {
        case 0:
          sprintf(temp, "No hay participantes en %s en el deporte %s", teams[teamIndex].nickname, sport);
          printInfo(temp);
          break;
        default:
          printlInfo("Participantes");
          printLog(teams[teamIndex].nickname);
          for(i = 0; i < indicesLen; i++) {
            printPlayer(teams[teamIndex].players[indices[i]]);
            printlLog("");
          }
      } 
      requestSelect("", menuSelect, 1);
    }    
  }
  clearLogs();
  printIntro("");
}