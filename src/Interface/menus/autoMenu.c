
#include "autoMenu.h"

/**
 * Menú principal/Generar datos
 */
void displayAutoMenu (InterYearTeam teams[5], bool confirm) {
  char confirmMenu[2][SELECT_S] = {
    "Generar datos",
    "Cancelar"
  };

  if (!confirm) {
    printlError("Advertencia! Esta operación sobreescribirá los datos.");
    if (requestSelect("", confirmMenu, 2) == 1) {
      displayAutoMenu(teams, true);
    }
  }
  else {
    generateTeams(teams);
    printInfo("Datos de prueba inicializados exitosamente!!");
  }
}
