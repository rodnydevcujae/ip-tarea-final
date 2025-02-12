#include "menu.h"

/**
 * Mostrar información del programa
 */
void displayAppInfo () {
  printIntro("");
  printInfo("Interaños Informática 1.0");
  printlLog("Estudiante: Rodny Roberto Estrada León");
  printlLog("Grupo 11");
  printlInfo("Número 13");
  printOutro("\n");
}

/**
 * Menú principal
 */
void displayMainMenu (InterYearTeam teams[5]) {
  int choice;
  char menuSelect[4][SELECT_S] = {
    "Introducir datos",
    "Generar datos predefinidos (solo para testeos)",
    "Reportes",
    "... Salir"
  };
  
  printInfo("< Menú Principal >");
  choice = requestSelect(menuSelect, 4);
  switch (choice) {
    case 3:
      printOutro("\n");
      printIntro("");
      displayReportsMenu(teams);
      break;
    case 4:
      printOutro("\n");
      displayAppInfo();
      printIntro("");
      printlInfo("Saliendo del programa...");
      printOutro("\n");
      break;
    default:
      printError("Esta opción no ha sido implementada aún.");
      displayMainMenu(teams);
  }
}

/**
 * Menú Principal/Reportes
 */
void displayReportsMenu (InterYearTeam teams[5]) {
  int choice;
  char menuSelect[6][SELECT_S] = {
    "... Atrás",
    "a) Mostrar año con más medallas",
    "b) Mostrar datos de todos los años",
    "c) Mostrar porcentaje de medallas",
    "d) Mostrar años con mayor cantidad de mujeres",
    "e) Mostrar participantes"
  };

  if (!hasPlayers(teams)) {
    printInfo("< Menú de Reportes >");
    choice = requestSelect(menuSelect, 6);

    switch (choice) {
      case 1:
        printOutro("\n");
        printIntro("");
        displayMainMenu(teams);
        break;
    
      default:
        printError("Esta opción no ha sido implementada aún.");
        displayReportsMenu(teams);
        break;
    }
  }
  else {
    printlError("No puede acceder al menú de reportes.");
    printLog("Los datos están vacíos, introduzca al menos uno.");
    displayMainMenu(teams);
  }
}