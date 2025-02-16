
#include "logic.h"

/**
 * Vaciar (se usa para inicializar)
 */
void clearTeams (InterYearTeam teams[5]) {
  int i;

  for (i = 0; i < 5; i++) {
    teams[i].playersLen = 0;
    teams[i].responsible[0] = '\0';
  }

  strcpy(teams[0].nickname, "Primer Año (Orkirby)");
  strcpy(teams[1].nickname, "Segundo Año (Bitorca)");
  strcpy(teams[2].nickname, "Tercer Año (Mobybit)");
  strcpy(teams[3].nickname, "Cuarto Año");
  strcpy(teams[4].nickname, "Quinto Año");
}

/**
 * Rellenar con datos de prueba
 */
void generateTeams(InterYearTeam teams[5]) {
    // Equipo 1
    strcpy(teams[0].responsible, "Eduardo Brau");
    teams[0].playersLen = 10;
    teams[0].players[0].hasMedal = true; teams[0].players[0].sex = 'M'; strcpy(teams[0].players[0].name, "Alberto Antonio"); strcpy(teams[0].players[0].sport, "Ajedrez");
    teams[0].players[1].hasMedal = true; teams[0].players[1].sex = 'F'; strcpy(teams[0].players[1].name, "María López"); strcpy(teams[0].players[1].sport, "Fútbol");
    teams[0].players[2].hasMedal = true; teams[0].players[2].sex = 'M'; strcpy(teams[0].players[2].name, "Carlos Ruiz"); strcpy(teams[0].players[2].sport, "Fútbol");
    teams[0].players[3].hasMedal = false; teams[0].players[3].sex = 'F'; strcpy(teams[0].players[3].name, "Ana Torres"); strcpy(teams[0].players[3].sport, "Baloncesto");
    teams[0].players[4].hasMedal = true; teams[0].players[4].sex = 'M'; strcpy(teams[0].players[4].name, "Javier Pérez"); strcpy(teams[0].players[4].sport, "Baloncesto");
    teams[0].players[5].hasMedal = true; teams[0].players[5].sex = 'F'; strcpy(teams[0].players[5].name, "Claudia Martínez"); strcpy(teams[0].players[5].sport, "Ajedrez");
    teams[0].players[6].hasMedal = true; teams[0].players[6].sex = 'M'; strcpy(teams[0].players[6].name, "Luis Gómez"); strcpy(teams[0].players[6].sport, "Ajedrez");
    teams[0].players[7].hasMedal = false; teams[0].players[7].sex = 'F'; strcpy(teams[0].players[7].name, "Sofía Jiménez"); strcpy(teams[0].players[7].sport, "Fútbol");
    teams[0].players[8].hasMedal = true; teams[0].players[8].sex = 'M'; strcpy(teams[0].players[8].name, "Diego Ramírez"); strcpy(teams[0].players[8].sport, "Voleibol");
    teams[0].players[9].hasMedal = true; teams[0].players[9].sex = 'F'; strcpy(teams[0].players[9].name, "Lucía Castro"); strcpy(teams[0].players[9].sport, "Voleibol");
    
    // Equipo 2
    strcpy(teams[1].responsible, "Carlos Pérez");
    teams[1].playersLen = 10;
    teams[1].players[0].hasMedal = true; teams[1].players[0].sex = 'M'; strcpy(teams[1].players[0].name, "Juan Martínez"); strcpy(teams[1].players[0].sport, "Ajedrez");
    teams[1].players[1].hasMedal = true; teams[1].players[1].sex = 'M'; strcpy(teams[1].players[1].name, "Alex Perdomo"); strcpy(teams[1].players[1].sport, "Fútbol");
    teams[1].players[2].hasMedal = false; teams[1].players[2].sex = 'M'; strcpy(teams[1].players[2].name, "Pedro Sánchez"); strcpy(teams[1].players[2].sport, "Baloncesto");
    teams[1].players[3].hasMedal = true; teams[1].players[3].sex = 'M'; strcpy(teams[1].players[3].name, "Roger Gorriarán"); strcpy(teams[1].players [3].sport, "Fútbol");
    teams[1].players[4].hasMedal = false; teams[1].players[4].sex = 'M'; strcpy(teams[1].players[4].name, "Jorge López"); strcpy(teams[1].players[4].sport, "Voleibol");
    teams[1].players[5].hasMedal = true; teams[1].players[5].sex = 'F'; strcpy(teams[1].players[5].name, "Isabel Torres"); strcpy(teams[1].players[5].sport, "Voleibol");
    teams[1].players[6].hasMedal = true; teams[1].players[6].sex = 'M'; strcpy(teams[1].players[6].name, "Ricardo Ramírez"); strcpy(teams[1].players[6].sport, "Voleibol");
    teams[1].players[7].hasMedal = true; teams[1].players[7].sex = 'F'; strcpy(teams[1].players[7].name, "Patricia Jiménez"); strcpy(teams[1].players[7].sport, "Dominó");
    teams[1].players[8].hasMedal = false; teams[1].players[8].sex = 'M'; strcpy(teams[1].players[8].name, "Fernando Castro"); strcpy(teams[1].players[8].sport, "Béisbol");
    teams[1].players[9].hasMedal = true; teams[1].players[9].sex = 'F'; strcpy(teams[1].players[9].name, "Verónica Morales"); strcpy(teams[1].players[9].sport, "Béisbol");

    // Equipo 3
    strcpy(teams[2].responsible, "Laura Fernández");
    teams[2].playersLen = 10;
    teams[2].players[0].hasMedal = false; teams[2].players[0].sex = 'M'; strcpy(teams[2].players[0].name, "Pedro Sánchez"); strcpy(teams[2].players[0].sport, "Baloncesto");
    teams[2].players[1].hasMedal = false; teams[2].players[1].sex = 'F'; strcpy(teams[2].players[1].name, "Lucía Torres"); strcpy(teams[2].players[1].sport, "Fútbol");
    teams[2].players[2].hasMedal = false; teams[2].players[2].sex = 'F'; strcpy(teams[2].players[2].name, "Adriana Gómez"); strcpy(teams[2].players[2].sport, "Fútbol");
    teams[2].players[3].hasMedal = true; teams[2].players[3].sex = 'F'; strcpy(teams[2].players[3].name, "María Ruiz"); strcpy(teams[2].players[3].sport, "Fútbol");
    teams[2].players[4].hasMedal = false; teams[2].players[4].sex = 'F'; strcpy(teams[2].players[4].name, "Jenny López"); strcpy(teams[2].players[4].sport, "Ajedrez");
    teams[2].players[5].hasMedal = true; teams[2].players[5].sex = 'F'; strcpy(teams[2].players[5].name, "Claudia Fernández"); strcpy(teams[2].players[5].sport, "Béisbol");
    teams[2].players[6].hasMedal = false; teams[2].players[6].sex = 'M'; strcpy(teams[2].players[6].name, "Diego Ramírez"); strcpy(teams[2].players[6].sport, "Béisbol");
    teams[2].players[7].hasMedal = true; teams[2].players[7].sex = 'F'; strcpy(teams[2].players[7].name, "Patricia López"); strcpy(teams[2].players[7].sport, "Voleibol");
    teams[2].players[8].hasMedal = false; teams[2].players[8].sex = 'M'; strcpy(teams[2].players[8].name, "Javier Castro"); strcpy(teams[2].players[8].sport, "Béisbol");
    teams[2].players[9].hasMedal = true; teams[2].players[9].sex = 'F'; strcpy(teams[2].players[9].name, "Isabel Torres"); strcpy(teams[2].players[9].sport, "Baloncesto");

    // Equipo  4
    strcpy(teams[3].responsible, "Javier Ruiz");
    teams[3].playersLen = 10;
    teams[3].players[0].hasMedal = true; teams[3].players[0].sex = 'M'; strcpy(teams[3].players[0].name, "Diego Ramírez"); strcpy(teams[3].players[0].sport, "Voleibol");
    teams[3].players[1].hasMedal = false; teams[3].players[1].sex = 'F'; strcpy(teams[3].players[1].name, "Sofía Jiménez"); strcpy(teams[3].players[1].sport, "Dominó");
    teams[3].players[2].hasMedal = false; teams[3].players[2].sex = 'M'; strcpy(teams[3].players[2].name, "Fernando López"); strcpy(teams[3].players[2].sport, "Dominó");
    teams[3].players[3].hasMedal = false; teams[3].players[3].sex = 'F'; strcpy(teams[3].players[3].name, "Claudia Torres"); strcpy(teams[3].players[3].sport, "Voleibol");
    teams[3].players[4].hasMedal = true; teams[3].players[4].sex = 'M'; strcpy(teams[3].players[4].name, "Jorge Martínez"); strcpy(teams[3].players[4].sport, "Béisbol");
    teams[3].players[5].hasMedal = false; teams[3].players[5].sex = 'F'; strcpy(teams[3].players[5].name, "Patricia García"); strcpy(teams[3].players[5].sport, "Béisbol");
    teams[3].players[6].hasMedal = true; teams[3].players[6].sex = 'M'; strcpy(teams[3].players[6].name, "Luis Ramírez"); strcpy(teams[3].players[6].sport, "Béisbol");
    teams[3].players[7].hasMedal = false; teams[3].players[7].sex = 'F'; strcpy(teams[3].players[7].name, "Ana Morales"); strcpy(teams[3].players[7].sport, "Dominó");
    teams[3].players[8].hasMedal = false; teams[3].players[8].sex = 'M'; strcpy(teams[3].players[8].name, "Ricardo Castro"); strcpy(teams[3].players[8].sport, "Ajedrez");
    teams[3].players[9].hasMedal = false; teams[3].players[9].sex = 'F'; strcpy(teams[3].players[9].name, "Lucía Fernández"); strcpy(teams[3].players[9].sport, "Baloncesto");

    // Equipo 5
    strcpy(teams[4].responsible, "Isabel Castro");
    teams[4].playersLen = 10;
    teams[4].players[0].hasMedal = false; teams[4].players[0].sex = 'M'; strcpy(teams[4].players[0].name, "Luis Hernández"); strcpy(teams[4].players[0].sport, "Baloncesto");
    teams[4].players[1].hasMedal = false; teams[4].players[1].sex = 'F'; strcpy(teams[4].players[1].name, "Juana Morales"); strcpy(teams[4].players[1].sport, "Béisbol");
    teams[4].players[2].hasMedal = false; teams[4].players[2].sex = 'F'; strcpy(teams[4].players[2].name, "Mairelys Acosta"); strcpy(teams[4].players[2].sport, "Baloncesto");
    teams[4].players[3].hasMedal = true; teams[4].players[3].sex = 'F'; strcpy(teams[4].players[3].name, "María Jiménez"); strcpy(teams[4].players[3].sport, "Ajedrez");
    teams[4].players[4].hasMedal = false; teams[4].players[4].sex = 'M'; strcpy(teams[4].players[4].name, "Andrés Torres"); strcpy(teams[4].players[4].sport, "Ajedrez");
    teams[4].players[5].hasMedal = false; teams[4].players[5].sex = 'F'; strcpy(teams[4].players[5].name, "Patricia López"); strcpy(teams[4].players[5].sport, "Dominó");
    teams[4].players[6].hasMedal = false; teams[4].players[6].sex = 'M'; strcpy(teams[4].players[6].name, "Diego Ramírez"); strcpy(teams[4].players[6].sport, "Dominó");
    teams[4].players[7].hasMedal = false; teams[4].players[7].sex = 'F'; strcpy(teams[4].players[7].name, "Isabel Castro"); strcpy(teams[4].players[7].sport, "Fútbol");
    teams[4].players[8].hasMedal = false; teams[4].players[8].sex = 'M'; strcpy(teams[4].players[8].name, "Fernando Gómez"); strcpy(teams[4].players[8].sport, "Voleibol");
    teams[4].players[9].hasMedal = true; teams[4].players[9].sex = 'F'; strcpy(teams[4].players[9].name, "Claudia Torres"); strcpy(teams[4].players[9].sport, "Dominó");
}

/**
 * Verificar si tiene al menos un participante
 */
bool hasPlayers (InterYearTeam teams[5]) {
  int i = 0;
  bool valid = false;

  while (!valid && i < 5) {
    if (teams[i].playersLen) {
      valid = true;
    }
    else i++;
  }

  return valid;
}

/**
 * Obtener total de medallas de un año
 */
int getMedals (InterYearTeam team) {
  int i;
  int medals = 0;

  for (i = 0; i < team.playersLen; i++) {
    if (team.players[i].hasMedal) {
      medals++;
    }
  }
  return medals;
}

/**
 * Obtener porcentaje de medallas por participante
 */
float getMedalsPercent(InterYearTeam team) {
  int medals = getMedals(team);
  int players = team.playersLen;

  return (float)medals / players * 100;
}


/**
 * Obtener años con mayor cantidad de medallas
 */
int getBestMedals (InterYearTeam teams[5], int indices[5]) {
  int indicesLen = 0;
  int bestMedals = 0;
  int medals;
  int i;

  for (i = 0; i < 5; i++) {
    medals = getMedals(teams[i]);
    if (medals > bestMedals) {
      indices[0] = i;
      indicesLen = 1;
      bestMedals = medals;
    }
    else if (medals == bestMedals){
      indices[indicesLen++] = i;
    }
  }

  return indicesLen;
}


/**
 * Filtrar los años que hubo más participación femenina que masculina
 * @param teams - los 5 años
 * @param indices - almacenar indices de los años filtrados
 * @param femCounters - almacenar total de mujeres de los años filtrados
 * @returns - tamaño lógico de los arreglos de almacenaje
 */
int getMajorFemSex (InterYearTeam teams[5], int indices[5], int femCounters[5]) {
  int i, j;
  int indicesLen = 0;
  int femCounter;
  int maleCounter;
  int playersLen;

  for (i = 0; i < 5; i++) {
    femCounter = 0;
    maleCounter = 0;
    playersLen = teams[i].playersLen;
    for (j = 0; j < playersLen; j++) {
      if (teams[i].players[j].sex == 'F') {
        femCounter++;
      }
      else maleCounter ++;
    }

    if (femCounter > maleCounter) {
      femCounters[indicesLen] = femCounter;
      indices[indicesLen++] = i;
    }
  }

  return indicesLen;
}

/**
 * Filtrar jugadores según el deporte
 * @param teams - los 5 años
 * @param sport - deporte a filtrar
 * @param indices - almacenar indices de los jugadores filtrados
 * @returns - tamaño lógico del arreglo
 */
int getPlayers (InterYearTeam team, char sport[SPORT_S], int indices[]) {
  int indicesLen = 0;
  int i;

  for(i = 0; i < team.playersLen; i++) {
    if (strcmp(team.players[i].sport, sport) == 0) {
      indices[indicesLen++] = i;
    }
  }

  return indicesLen;
}


/**
 * Generar arreglo de opciones de selección con los años
 * @param teams - Los 5 años
 * @param options - lista de seleccion para almacenar los nombres de los años
 */
int createTeamSelect (InterYearTeam teams[5], char options[][SELECT_S]) {
  int i;

  // generar lista de nombres de años
  for (i = 0; i < 5; i++) {
    strcpy(options[i], teams[i].nickname);
  }

  return 5;
}
