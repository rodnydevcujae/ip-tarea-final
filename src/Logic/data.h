#ifndef DATA_H
#define DATA_H

#include <stdbool.h>

#define SELECT_S 100
#define PLAYERS_S 100
#define NAME_S 50
#define SPORT_S 30

// Estructura para un participante
typedef struct {
  char name[NAME_S];   // nombre
  char sex;            // masculino o femenino (m/f)
  char sport[SPORT_S]; // deporte
  bool hasMedal;       // tiene medalla?
} Player;


// Estructura para un año (equipo) de los Juegos Interaños
typedef struct {
  char nickname[NAME_S];     // seudonimo para el año
  char responsible[NAME_S];  // responsable de la FEU
  int playersLen;            // cantidad de participantes
  Player players[PLAYERS_S]; // participantes
} InterYearTeam;

#endif