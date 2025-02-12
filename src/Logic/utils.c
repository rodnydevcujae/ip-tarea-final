#include "utils.h"

/**
 * Verifica si la cadena contiene solo numeros
 */
bool isInt(char *str) {
  int i = 0;
  int len = strlen(str);
  bool valid = true;

  while (valid && i < len) {
    valid = isdigit(str[i]);
    i++;
  }

  return valid;
}

