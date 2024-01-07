#ifndef S21_CATOPT_H
#define S21_CATOPT_H

#include "../common/s21_optproc.h"

// Var1: option representation as bitset
enum optconst {
  HELPOPT = 1,
  VERSOPT = 2,
  NUMOPT = 4,
  NBNUMOPT = 8,
  SENDOPT = 16,
  STABSOPT = 32,
  SNPROPT = 64,
  SQBLNOPT = 128
};

// Options in array
struct options opt[] = {{
                            "help",
                            0,
                        },
                        {
                            "version",
                            0,
                        },
                        {"show-nonprinting", 0, 'v'},
                        {"show-tabs", 0, 'T'},
                        {"squeeze-blank", 0, 's'},
                        {"number", 0, 'n'},
                        {"show-ends", 0, 'E'},
                        {"number-nonblank", 0, 'b'},
                        {"show-all", 0, 'A'},
                        {NULL, 0, 'e'}};

#endif