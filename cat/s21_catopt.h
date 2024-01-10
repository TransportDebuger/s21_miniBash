#ifndef S21_CATOPT_H
#define S21_CATOPT_H

#include "../common/s21_optproc.h"

typedef struct option OptList;
struct option {
  FLIST* pathList;
  short int help;
  short int version;
  short int shownpr;
  short int showtabs;
  short int showends;
  short int strnum;
  short int strnumnbl;
};

OptList* parseCli(int inArgc, char** inArgv, OptList* optList, int* errCode);
OptList* allocateOptList();
void deallocOptList(OptList* inOptList);

// Options in array
/*struct options optarr[] = {{
                            "help",
                            0,
                        '\0'},
                        {
                            "version",
                            0,
                            '\0'
                        },
                        {"show-nonprinting", 0, 'v'},
                        {"show-tabs", 0, 'T'},
                        {"squeeze-blank", 0, 's'},
                        {"number", 0, 'n'},
                        {"show-ends", 0, 'E'},
                        {"number-nonblank", 0, 'b'},
                        {"show-all", 0, 'A'},
                        {NULL, 0, 'e'}};
*/
#endif