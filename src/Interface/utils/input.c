
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
int requestSelect (const char *message, char options[][SELECT_S], int len) {
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
 * @param teams - los años a verificar
 * @param opt - 1 para comparar con todos los participantes, 2 con los de la FEU
 */
bool requestName (const char *message, char name[NAME_S], InterYearTeam teams[5], int opt) {
  int i, j;
  bool valid = true;
  bool userCancel = false;
  int flag;
  char temp[200] = "";

  do {
    printf(" " GREEN IMG6 RESET " %s\n", message);
    printf(" " IMG1 " " GREEN IMG7 ":" RESET " ");

    valid = getInput(temp, NAME_S - 2);
    if (valid) {
      // cancelar operación
      if (strcmp(temp, "0") == 0) userCancel = true;
      else {
        trimStr(temp);
        flag = isName(temp);
        valid = !flag;
  
        if (valid) {
          // acomodar el nombre
          parseName(temp);
  
          // verificar si ya existe
          if (opt == 1) {
            i = 0;
            while (valid && i < 5) {
              j = 0;
              while(valid && j < teams[i].playersLen) {
                if (strcmp(temp, teams[i].players[j].name) == 0) {
                  valid = false;
                }
                else j++;
              }
              if (valid) i++;
            }
  
            if (!valid) {
              sprintf(temp, "Error! Nombre duplicado. Ese participante ya existe en %s", teams[i].nickname);
              printError(temp);
            }
          }
          else if (opt == 2){
            i = 0;
            while (valid && i < 5) {
              if (strcmp(temp, teams[i].responsible) == 0) {
                valid = false;
              }
              if (valid) i++;
            }
            if (!valid) {
              sprintf(temp, "Error! Nombre duplicado. Ese nombre forma parte de la FEU de %s", teams[i].nickname);
              printError(temp);
            }
          }
          
          if (valid) strcpy(name, temp);
        }
        else {
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
      }
    }
    else {
      sprintf(temp, RED "Error, entrada muy extensa." RESET " Su entrada no debe de superar las %d letras.", NAME_S - 2);
      printError(temp);
    }
  } while (!valid);

  return userCancel;
}

/**
 * Solicitar un deporte
 * @param message - mensaje de la solicitud
 * @param name - almacenar entrada del usuario
 * @return - verdadero si el usuario canceló la operación
 */
bool requestSportSelect (const char *message, char sport[SPORT_S]) {
  int sportId;
  bool userCancel = false;
  char sportMenu[7][SELECT_S] = {
    "Fútbol",
    "Baloncesto",
    "Voleibol",
    "Béisbol",
    "Dominó",
    "Ajedrez",
    "... Cancelar"
  };
  
  sportId = requestSelect(message, sportMenu, 7);
  userCancel = sportId == 7;

  if (!userCancel) {
    strcpy(sport, sportMenu[sportId - 1]);
  }
  return userCancel;
}
