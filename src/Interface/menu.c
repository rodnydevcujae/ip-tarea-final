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
  switch (choice) {
    case 1:
      printSep();
      displayInsertMenu(teams, 0);
      break;
    case 2:
      printSep();
      displayAutoMenu(teams, false);
      printSep();
      displayMainMenu(teams);
      break;
    case 3:
      displayReportsMenu(teams);
      printSep();
      break;
    case 4:
      printSep();
      displayAppInfo();
      printSep();
      printlInfo("Saliendo del programa...");
      printOutro("\n");
      break;
  }
}