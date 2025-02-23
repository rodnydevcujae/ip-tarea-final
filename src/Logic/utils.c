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

/**
 * Retorna 0 si es un nombre correcto
 * Retorna 1 si contiene caracteres que no sean letras
 * Retorna 2 si tiene mas de 1 espacio (solo se acepta un apellido)
 * Retorna 3 si el nombre tiene menos de 3 letras
 */
int isName(char *str) {
  int spaceCount = 0;
  int letterCount = 0;
  bool inName = true; // true si estamos iterando en el nombre
                      // falso si estamos en el apellido
  int flag = 0; // todo bien hasta el momento
  int i = 0;

  while (str[i] != '\0' && !flag) {
    // el caracter es un espacio?
    if (str[i] == ' ') {
      spaceCount++;
      inName = false;

      if (spaceCount > 1) {
        // hay más de un espacio
        flag = 2;
      }
    } 

    // el carácter no es una letra?
    else if (!isalpha(str[i])) {
      flag = 1;
    }
    else if (inName) {
      letterCount++;
    }

    i++;
  }

  if (!flag && letterCount < 3) {
    flag = 3;
  }

  return flag;
}

/**
 * Recortar espacios extras
 */
void trimStr (char *str) {
  char newStr[200] = "";
  bool inSpace = false;
  bool inStart = false;
  int i;
  int len = strlen(str);
  int newLen = 0;

  for (i = 0; i < len; i++) {
    if (str[i] == ' ') {
      if(i == 0) inStart = true;
      if (!inStart) {
        inSpace = true;
      }
    } 
    else {
      inStart = false;
      if (inSpace) {
        newStr[newLen++] = ' ';
        inSpace = false;
      }
      newStr[newLen++] = str[i];
    }
  }

  newStr[newLen] = '\0';
  strcpy(str, newStr);
}

/**
 * Reestructurar string a un formato de nombre adecuado
 */
void parseName(char *str) {
  int i = 0;
  bool inWord = false; 

  while (str[i] != '\0') {
    if (str[i] != ' ') {
      if (!inWord) {
        // no es una palabra, convertir a mayúscula
        str[i] = toupper(str[i]);
        inWord = true;
      } else {
        str[i] = tolower(str[i]);
      }
    } else {
      inWord = false;
    }
    i++;
  }

}