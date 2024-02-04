#ifndef S21_CATOPT_H
#define S21_CATOPT_H

#include "../common/s21_ctypedef.h"

struct options {
#ifndef APPLE
  short int help;     //--help (Linux)
  short int version;  //--version (Linux)
#endif
  short int shownpr;    // -v (Linux, Mac)
  short int showtabs;   // -t (Mac), -T (Linux)
  short int showends;   // -e (Mac), -E (Linux)
  short int strnum;     // -n (Linux, Mac)
  short int strnumnbl;  // -b (Linux, Mac)
  short int sblank;     // -s (Linux, Mac)
};

OptList* parseOptions(int pcount, char** pAgs);
int setParameters(char* optstr, OptList* optList);
OptList initOptList();
void deallocOptList(OptList* inOptList);

#endif