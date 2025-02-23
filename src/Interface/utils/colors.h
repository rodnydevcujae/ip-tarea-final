#ifndef COLORS_H
#define COLORS_H

#define IMG2E "┌───────────────────────────────────────────"
#define IMG2  "┌ "
#define IMG1  "│ "
#define IMG3  "└ "
#define IMG3E "└───────────────────────────────────────────"
#define IMG4 "♦ "
#define IMG5 "■ "
#define IMG6 "► "
#define IMG7 "→ "
#define IMG8 "▲ "
#define IMG9 "├─ "

// Color de texto
#if _WIN32
  // para windows no disponible
  #define RESET       ""
  #define BLACK       ""
  #define RED         ""
  #define GREEN       "" 
  #define YELLOW      ""
  #define BLUE        "" 
  #define MAGENTA     "" 
  #define CYAN        ""
  #define WHITE       ""
#else
  #define RESET       "\033[0m"   // Restablecer color
  #define BLACK       "\033[30m"
  #define RED         "\033[31m"
  #define GREEN       "\033[32m" 
  #define YELLOW      "\033[33m"
  #define BLUE        "\033[34m" 
  #define MAGENTA     "\033[35m" 
  #define CYAN        "\033[36m"
  #define WHITE       "\033[37m"
#endif

#endif
