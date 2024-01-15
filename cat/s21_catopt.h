#ifndef S21_CATOPT_H
#define S21_CATOPT_H

#include "../common/s21_optproc.h"

typedef struct option OptList;
struct option {
  FLIST* pathList;
  short int help;      //--help (Linux)
  short int version;   //--version (Linux)
  short int shownpr;   // -v (Linux, Mac)
  short int showtabs;  // -t (Mac), -T (Linux)
  short int showends;  // -e (Mac), -E (Linux) 
  short int strnum;    // -n (Linux, Mac)
  short int strnumnbl; // -b (Linux, Mac)
  short int sblank;    // -s (Linux, Mac)
};

OptList* parseCli(int inArgc, char** inArgv, OptList* optList, int* errCode);
OptList* allocateOptList();
void deallocOptList(OptList* inOptList);

#endif