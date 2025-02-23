
#include "autoMenu.h"

/**
 * Menú principal/Generar datos
 */
void displayAutoMenu (InterYearTeam teams[5], bool confirm) {
  char confirmMenu[2][SELECT_S] = {
    "Generar datos de prueba",
    "Cancelar"
  };

  if (!confirm) {
    clearLogs();
    printIntro("");
    printlError("Advertencia! Esta operación sobreescribirá los datos.");
    if (requestSelect("", confirmMenu, 2) == 1) {
      displayAutoMenu(teams, true);
    }
    else {
      clearLogs();
      printIntro("");
    }
  }
  else {
    generateTeams(teams);
    clearLogs();
    printInfo("Datos de prueba inicializados exitosamente!!");
    printSep();
  }
}
