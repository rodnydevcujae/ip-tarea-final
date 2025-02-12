#ifndef DATA_H
#define DATA_H

#include <stdbool.h>

#define PLAYERS_S 100
#define NAME_S 50
#define SPORT_S 30
#define RESPONSIBLE_S 50

// Estructura para un participante
typedef struct {
  char name[NAME_S];   // nombre
  char sex;            // masculino o femenino (m/f)
  char sport[SPORT_S]; // deporte
  bool hasMedal;       // tiene medalla?
} Player;


// Estructura para un año de los Juegos Interaños
typedef struct {
  char responsible[RESPONSIBLE_S];  // responsable de la FEU
  Player players[PLAYERS_S];        // participantes
  int playersLen;                   // cantidad de participantes
} InterYearTeam;

#endif