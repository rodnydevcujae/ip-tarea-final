
#include "input.h"
#include "output.h"

/**
 * Obtiene la entrada del usuario y la almacena en la cadena
 * Retorna falso si el usuario ingreso mas de lo posible, de lo contrario verdadero
 */
bool getInput (char input[], int maxbuffer) {
  int len;
  bool valid = true;

  fgets(input, maxbuffer + 2, stdin);
  len = strlen(input);

  // verificar si el buffer tomo toda la cadena hasta el final
  if (input[len - 1] != '\n') {
    valid = false;
    while(getchar() != '\n'); // limpiar buffer en exceso
  }
  
  // si añadió el salto de línea, eliminarlo
  if (input[len - 1] == '\n') input[len - 1] = '\0';

  return valid;
}

/**
 * Solicitar una opcion
 * @param message - mensaje de pregunta personalizado
 * @param options - arreglo de strings
 * @param len - tamaño 
 */
int requestSelect (char *message, char options[][SELECT_S], int len) {
  int i;
  bool valid = true;
  char temp[200] = "";
  int option;

  do {
    if (message[0] != '\0') printf(" %s%s%s %s\n", GREEN, IMG6, RESET, message);
    printf(" %s%s%s Seleccione una opción:\n", GREEN, IMG6, RESET);
    for (i = 0; i < len; i++) {
      printf(" %s   %s%s%2d. %s %s\n", IMG1, GREEN, IMG7, i + 1, RESET, options[i]);
    }
    printf(" %s Tu elección: ", IMG9);

    valid = getInput(temp, 3);
    if (valid) {
      valid = isInt(temp);
      if (valid) {
        option = atoi(temp);
        valid = option >= 1 && option <= len;
      }
    }
    
    if (!valid) {
     sprintf(temp, "%sUps! Opción Inválida.%s Solo se admite un número en el rango 1 a %d de las opciones propuestas", RED, RESET, len);
     printError(temp);
    }
  } while (!valid);
  
  return option;
}

/**
 * Solicitar nombre
 * @param message - mensaje de la solicitud
 * @param name - almacenar entrada del usuario
 */
void requestName (const char *message, char name[NAME_S]) {
  int i;
  bool valid = true;
  int flag;
  char temp[100] = "";

  do {
    printf(" %s%s%s %s\n", GREEN, IMG6, RESET, message);
    printf(" %s %s%s:%s ", IMG1, GREEN, IMG7, RESET);

    valid = getInput(temp, NAME_S - 2);
    if (valid) {
      trimStr(temp, name);
      flag = isName(name);
      valid = !flag;

      switch (flag) {
        case 1:
          printError("Error. Verifique que su entrada solo contenga letras.");
          break;
        case 2:
          printError("Error. Más de un apellido no está soportado.");
          break;
        case 3:
          printError("Error. Asegúrese que el nombre tenga 3 o más letras.");
          break;
      }
    }
    else {
      sprintf(temp, "%sError, entrada muy extensa.%s Su entrada no debe de superar las %d letras.", RED, RESET, NAME_S - 2);
      printError(temp);
    }
  } while (!valid);

  // acomodar el nombre
  parseName(name);
}

/**
 * Solicitar un deporte
 * @param message - mensaje de la solicitud
 * @param name - almacenar entrada del usuario
 */
void requestSportSelect (const char *message, char sport[SPORT_S]) {
  int sportId;
  char sportMenu[6][SELECT_S] = {
    "Fútbol",
    "Baloncesto",
    "Voleibol",
    "Béisbol",
    "Dominó",
    "Ajedrez"
  };
  
  sportId = requestSelect(message, sportMenu, 6);
  strcpy(sport, sportMenu[sportId - 1]);
}
