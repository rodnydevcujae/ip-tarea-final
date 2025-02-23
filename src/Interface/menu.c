#include "menu.h"

/**
 * Mostrar información del programa
 */
void displayAppInfo () {
  printInfo("Interaños Informática 1.0");
  printlLog("Estudiante: Rodny Roberto Estrada León");
  printlLog("Grupo 11");
  printlInfo("Número 13");
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
  choice = requestSelect("", menuSelect, 4);
  
  clearLogs();
  printIntro("");

  switch (choice) {
    case 1:
      displayInsertMenu(teams, -1);
      displayMainMenu(teams);
      break;
    case 2:
      displayAutoMenu(teams, false);
      displayMainMenu(teams);
      break;
      case 3:
      displayReportsMenu(teams);
      displayMainMenu(teams);
      break;
    case 4:
      printSep();
      displayAppInfo();
      printSep();
      printlInfo("Saliendo del programa...");
      printOutro("");
      break;
  }
}