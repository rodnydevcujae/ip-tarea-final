#include "output.h"

void printIntro(char *message) {
  if (message[0] == '\0') {
    printf(" %s\n", IMG2);
  } 
  else {
    printf(" %s %s\n %s \n", IMG2, message, IMG1);
  }
}

void printLog(char *message) {
  printf(" %s %s\n %s \n", IMG1, message, IMG1);
}
void printlLog(char *message) {
  printf(" %s %s\n", IMG1, message);
}

void printOutro(char *message) {
  printf(" %s %s\n", IMG3, message);
}

void printInfo(char *message) {
  printf(" %s%s%s %s\n %s \n", MAGENTA, IMG4, RESET, message, IMG1);
}
void printlInfo(char *message) {
  printf(" %s%s%s %s\n", MAGENTA, IMG4, RESET, message);
}

void printError(char *message) {
  printf(" %s%s%s %s\n %s \n", RED, IMG8, RESET, message, IMG1);
}
void printlError(char *message) {
  printf(" %s%s%s %s\n", RED, IMG8, RESET, message);
}

void printQuestion(char *message) {
  printf(" %s%s%s %s\n", CYAN, IMG7, RESET, message);
  printf(" %s%s%s ", CYAN, IMG1, RESET);
}