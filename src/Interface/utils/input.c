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
 * @param options - arreglo de strings
 * @param len - tamaño 
 */
int requestSelect (char options[][SELECT_S], int len) {
  int i;
  bool valid = true;
  char temp[200] = "";
  int option;

  do {
    printf(" %s%s%s Seleccione una opción:\n", GREEN, IMG6, RESET);
    for (i = 0; i < len; i++) {
      printf(" %s   %s%s %d. %s %s\n", IMG1, GREEN, IMG7, i + 1, RESET, options[i]);
    }
    printf(" %s Tu elección: ", IMG9);

    valid = getInput(temp, 1);
    if (valid) {
      valid = isInt(temp);
      if (valid) {
        option = atoi(temp);
        valid = option >= 1 && option <= len;
      }
    }
    
    if (!valid) {
     sprintf(temp, "%sUps! Opción Inválida.%s Solo se admite un dígito en el rango 1 a %d de las opciones propuestas", RED, RESET, len);
     printError(temp);
    }
  } while (!valid);
  
  return option;
}