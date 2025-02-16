
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
    printSep();
    printInfo("< Menú de Reportes >");
    choice = requestSelect("", menuSelect, 6);

    switch (choice) {
      case 1:
        printSep();
        displayReportA(teams);
        displayReportsMenu(teams);
        break;
      
      case 2:
        printSep();
        displayReportB(teams);
        displayReportsMenu(teams);
        break;
      
      case 3:
        printSep();
        displayReportC(teams);
        displayReportsMenu(teams);
        break;
      
      case 4:
        printSep();
        displayReportD(teams);
        displayReportsMenu(teams);
        break;
      
      case 5:
        printSep();
        displayReportE(teams);
        displayReportsMenu(teams);
        break;

      case 6:
        printSep();
        displayMainMenu(teams);
        break;
    }
  }
  else {
    printlError("No puede acceder al menú de reportes.");
    printlLog("Los datos están vacíos, introduzca al menos uno.");
    printSep();
    displayMainMenu(teams);
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
  
  // obtener mejores equipos
  indicesLen = getBestMedals(teams, indices);
  
  if (indicesLen == 1) {
    printInfo("Equipo con mayor cantidad de medallas.");
  } 
  else {
    printInfo("Equipos con mayor cantidad de medallas.");
  }
  
  for(i = 0; i < indicesLen; i++) {
    printTeam(teams[indices[i]]);
  }

  printLog("");
  requestSelect("", menuSelect, 1);
}

/**
 * 
 */
void displayReportB (InterYearTeam teams[5]) {
  int i;

  char menuSelect[1][SELECT_S] = {
    "... Atrás"
  };
  
  printlInfo("Información de los equipos");
  
  for(i = 0; i < 5; i++) {
    printTeam(teams[i]);
    printLog("");
  }

  requestSelect("", menuSelect, 1);
}

/**
 * 
 */
void displayReportC (InterYearTeam teams[5]) {
  int i;
  char temp[100];

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
}


/**
 * 
 */
void displayReportD (InterYearTeam teams[5]) {
  int indices[5];
  int femCounters[5];
  int indicesLen;
  int i;
  char temp[100];

  char menuSelect[1][SELECT_S] = {
    "... Atrás"
  };
  
  // obtener equipos con más participación femenina que masculina
  indicesLen = getMajorFemSex(teams, indices, femCounters);
  
  switch (indicesLen) {
    case 0:
      printf("No hay equipos donde la participación femenina supera la masculina.");
    case 1:
      printInfo("Equipo donde la participación femenina supera la masculina:");
      break;
    default:
      printInfo("Equipos donde la participación femenina supera la masculina:");
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
  char temp[100];

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
    requestSportSelect("Deporte a obtener.", sport);

    indicesLen = getPlayers(teams[teamIndex], sport, indices);
    printSep();

    switch (indicesLen) {
      case 0:
        sprintf(temp, "No hay participantes en %s en el deporte %s", teams[teamIndex].nickname, sport);
        printInfo(temp);
        break;
      default:
        printlInfo("Participantes");
        sprintf(temp, "Equipo: %s", teams[teamIndex].nickname);
        printLog(temp);
        for(i = 0; i < indicesLen; i++) {
          printPlayer(teams[teamIndex].players[indices[i]]);
          printlLog("");
        }
        break;
    } 
    
  }
  
  requestSelect("", menuSelect, 1);
}