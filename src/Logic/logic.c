
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
    // 1er año
    strcpy(teams[0].responsible, "Eduardo Brau");
    teams[0].playersLen = 10;
    teams[0].players[0].hasMedal = true; teams[0].players[0].sex = 'M'; strcpy(teams[0].players[0].name, "Alberto Antonio"); strcpy(teams[0].players[0].sport, "Ajedrez");
    teams[0].players[1].hasMedal = true; teams[0].players[1].sex = 'F'; strcpy(teams[0].players[1].name, "Maria Lopez"); strcpy(teams[0].players[1].sport, "Fútbol");
    teams[0].players[2].hasMedal = true; teams[0].players[2].sex = 'M'; strcpy(teams[0].players[2].name, "Carlos Ruiz"); strcpy(teams[0].players[2].sport, "Fútbol");
    teams[0].players[3].hasMedal = false; teams[0].players[3].sex = 'F'; strcpy(teams[0].players[3].name, "Ana Torres"); strcpy(teams[0].players[3].sport, "Baloncesto");
    teams[0].players[4].hasMedal = true; teams[0].players[4].sex = 'M'; strcpy(teams[0].players[4].name, "Javier Perez"); strcpy(teams[0].players[4].sport, "Baloncesto");
    teams[0].players[5].hasMedal = true; teams[0].players[5].sex = 'F'; strcpy(teams[0].players[5].name, "Claudia Martinez"); strcpy(teams[0].players[5].sport, "Ajedrez");
    teams[0].players[6].hasMedal = true; teams[0].players[6].sex = 'M'; strcpy(teams[0].players[6].name, "Luis Gomez"); strcpy(teams[0].players[6].sport, "Ajedrez");
    teams[0].players[7].hasMedal = false; teams[0].players[7].sex = 'F'; strcpy(teams[0].players[7].name, "Sofia Jimenez"); strcpy(teams[0].players[7].sport, "Fútbol");
    teams[0].players[8].hasMedal = true; teams[0].players[8].sex = 'M'; strcpy(teams[0].players[8].name, "Diego Ramirez"); strcpy(teams[0].players[8].sport, "Voleibol");
    teams[0].players[9].hasMedal = true; teams[0].players[9].sex = 'F'; strcpy(teams[0].players[9].name, "Lucia Castro"); strcpy(teams[0].players[9].sport, "Voleibol");
    
    // 2do año
    strcpy(teams[1].responsible, "Carlos Perez");
    teams[1].playersLen = 10;
    teams[1].players[0].hasMedal = true; teams[1].players[0].sex = 'M'; strcpy(teams[1].players[0].name, "Juan Martinez"); strcpy(teams[1].players[0].sport, "Ajedrez");
    teams[1].players[1].hasMedal = true; teams[1].players[1].sex = 'M'; strcpy(teams[1].players[1].name, "Alex Perdomo"); strcpy(teams[1].players[1].sport, "Fútbol");
    teams[1].players[2].hasMedal = false; teams[1].players[2].sex = 'M'; strcpy(teams[1].players[2].name, "Pedro Sanchez"); strcpy(teams[1].players[2].sport, "Baloncesto");
    teams[1].players[3].hasMedal = true; teams[1].players[3].sex = 'M'; strcpy(teams[1].players[3].name, "Roger Gorriaran"); strcpy(teams[1].players [3].sport, "Fútbol");
    teams[1].players[4].hasMedal = false; teams[1].players[4].sex = 'M'; strcpy(teams[1].players[4].name, "Jorge Lopez"); strcpy(teams[1].players[4].sport, "Voleibol");
    teams[1].players[5].hasMedal = true; teams[1].players[5].sex = 'F'; strcpy(teams[1].players[5].name, "Isabel Torres"); strcpy(teams[1].players[5].sport, "Voleibol");
    teams[1].players[6].hasMedal = true; teams[1].players[6].sex = 'M'; strcpy(teams[1].players[6].name, "Ricardo Ramirez"); strcpy(teams[1].players[6].sport, "Voleibol");
    teams[1].players[7].hasMedal = true; teams[1].players[7].sex = 'F'; strcpy(teams[1].players[7].name, "Patricia Jimenez"); strcpy(teams[1].players[7].sport, "Domino");
    teams[1].players[8].hasMedal = false; teams[1].players[8].sex = 'M'; strcpy(teams[1].players[8].name, "Fernando Castro"); strcpy(teams[1].players[8].sport, "Béisbol");
    teams[1].players[9].hasMedal = true; teams[1].players[9].sex = 'F'; strcpy(teams[1].players[9].name, "Veronica Morales"); strcpy(teams[1].players[9].sport, "Béisbol");

    // 3er año
    strcpy(teams[2].responsible, "Laura Fernandez");
    teams[2].playersLen = 10;
    teams[2].players[0].hasMedal = false; teams[2].players[0].sex = 'F'; strcpy(teams[2].players[0].name, "Debora Dominguez"); strcpy(teams[2].players[0].sport, "Baloncesto");
    teams[2].players[1].hasMedal = false; teams[2].players[1].sex = 'F'; strcpy(teams[2].players[1].name, "Lucia Torres"); strcpy(teams[2].players[1].sport, "Fútbol");
    teams[2].players[2].hasMedal = false; teams[2].players[2].sex = 'F'; strcpy(teams[2].players[2].name, "Adriana Gomez"); strcpy(teams[2].players[2].sport, "Fútbol");
    teams[2].players[3].hasMedal = true; teams[2].players[3].sex = 'F'; strcpy(teams[2].players[3].name, "Maria Ruiz"); strcpy(teams[2].players[3].sport, "Fútbol");
    teams[2].players[4].hasMedal = false; teams[2].players[4].sex = 'F'; strcpy(teams[2].players[4].name, "Jenny Lopez"); strcpy(teams[2].players[4].sport, "Ajedrez");
    teams[2].players[5].hasMedal = true; teams[2].players[5].sex = 'F'; strcpy(teams[2].players[5].name, "Claudia Fernandez"); strcpy(teams[2].players[5].sport, "Béisbol");
    teams[2].players[6].hasMedal = false; teams[2].players[6].sex = 'M'; strcpy(teams[2].players[6].name, "Dayan Fajardo"); strcpy(teams[2].players[6].sport, "Béisbol");
    teams[2].players[7].hasMedal = true; teams[2].players[7].sex = 'F'; strcpy(teams[2].players[7].name, "Patricia Lopez"); strcpy(teams[2].players[7].sport, "Voleibol");
    teams[2].players[8].hasMedal = false; teams[2].players[8].sex = 'M'; strcpy(teams[2].players[8].name, "Javier Castro"); strcpy(teams[2].players[8].sport, "Béisbol");
    teams[2].players[9].hasMedal = true; teams[2].players[9].sex = 'F'; strcpy(teams[2].players[9].name, "Isabel Babastro"); strcpy(teams[2].players[9].sport, "Baloncesto");

    // 4to año
    strcpy(teams[3].responsible, "Javier Ruiz");
    teams[3].playersLen = 10;
    teams[3].players[0].hasMedal = true; teams[3].players[0].sex = 'M'; strcpy(teams[3].players[0].name, "Erick Honesto"); strcpy(teams[3].players[0].sport, "Voleibol");
    teams[3].players[1].hasMedal = false; teams[3].players[1].sex = 'F'; strcpy(teams[3].players[1].name, "Alicia Bravo"); strcpy(teams[3].players[1].sport, "Dominó");
    teams[3].players[2].hasMedal = false; teams[3].players[2].sex = 'M'; strcpy(teams[3].players[2].name, "Fernando Lopez"); strcpy(teams[3].players[2].sport, "Dominó");
    teams[3].players[3].hasMedal = false; teams[3].players[3].sex = 'F'; strcpy(teams[3].players[3].name, "Claudia Torres"); strcpy(teams[3].players[3].sport, "Voleibol");
    teams[3].players[4].hasMedal = true; teams[3].players[4].sex = 'M'; strcpy(teams[3].players[4].name, "Jorge Martinez"); strcpy(teams[3].players[4].sport, "Béisbol");
    teams[3].players[5].hasMedal = false; teams[3].players[5].sex = 'F'; strcpy(teams[3].players[5].name, "Patricia Garcia"); strcpy(teams[3].players[5].sport, "Béisbol");
    teams[3].players[6].hasMedal = true; teams[3].players[6].sex = 'M'; strcpy(teams[3].players[6].name, "Luis Ramirez"); strcpy(teams[3].players[6].sport, "Béisbol");
    teams[3].players[7].hasMedal = false; teams[3].players[7].sex = 'F'; strcpy(teams[3].players[7].name, "Ana Morales"); strcpy(teams[3].players[7].sport, "Dominó");
    teams[3].players[8].hasMedal = false; teams[3].players[8].sex = 'M'; strcpy(teams[3].players[8].name, "Ricardo Castro"); strcpy(teams[3].players[8].sport, "Ajedrez");
    teams[3].players[9].hasMedal = false; teams[3].players[9].sex = 'F'; strcpy(teams[3].players[9].name, "Lucia Fernandez"); strcpy(teams[3].players[9].sport, "Baloncesto");

    // 5to año
    strcpy(teams[4].responsible, "Isabel Castro");
    teams[4].playersLen = 10;
    teams[4].players[0].hasMedal = false; teams[4].players[0].sex = 'M'; strcpy(teams[4].players[0].name, "Luis Hernandez"); strcpy(teams[4].players[0].sport, "Baloncesto");
    teams[4].players[1].hasMedal = false; teams[4].players[1].sex = 'F'; strcpy(teams[4].players[1].name, "Jessy Morales"); strcpy(teams[4].players[1].sport, "Béisbol");
    teams[4].players[2].hasMedal = false; teams[4].players[2].sex = 'F'; strcpy(teams[4].players[2].name, "Mairelys Acosta"); strcpy(teams[4].players[2].sport, "Baloncesto");
    teams[4].players[3].hasMedal = true; teams[4].players[3].sex = 'F'; strcpy(teams[4].players[3].name, "Maria Jimenez"); strcpy(teams[4].players[3].sport, "Ajedrez");
    teams[4].players[4].hasMedal = false; teams[4].players[4].sex = 'M'; strcpy(teams[4].players[4].name, "Andres Torres"); strcpy(teams[4].players[4].sport, "Ajedrez");
    teams[4].players[5].hasMedal = false; teams[4].players[5].sex = 'F'; strcpy(teams[4].players[5].name, "Dayana Montero"); strcpy(teams[4].players[5].sport, "Dominó");
    teams[4].players[6].hasMedal = false; teams[4].players[6].sex = 'M'; strcpy(teams[4].players[6].name, "John Cabrera"); strcpy(teams[4].players[6].sport, "Dominó");
    teams[4].players[7].hasMedal = false; teams[4].players[7].sex = 'F'; strcpy(teams[4].players[7].name, "Isabel Castro"); strcpy(teams[4].players[7].sport, "Fútbol");
    teams[4].players[8].hasMedal = false; teams[4].players[8].sex = 'M'; strcpy(teams[4].players[8].name, "Fernando Gomez"); strcpy(teams[4].players[8].sport, "Voleibol");
    teams[4].players[9].hasMedal = true; teams[4].players[9].sex = 'F'; strcpy(teams[4].players[9].name, "Claudia Gitana"); strcpy(teams[4].players[9].sport, "Dominó");
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
 * 
 */
void removePlayer(InterYearTeam *team, int playerId) {
  int i;

  team->playersLen--;
  for (i = playerId; i < team->playersLen; i++) {
    team->players[i] = team->players[i + 1];
  }
}

/**
 * 
 */
void addPlayer(InterYearTeam *team, Player player) {
  team->players[ team->playersLen++ ] = player;
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

