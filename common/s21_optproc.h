#ifndef S21_OPTPROC_H
#define S21_OPTPROC_H

#include "s21_froutines.h"

struct options {
  char* longName;
  int haveArg;
  char shortName;
};

int parseCli(int inArgc, char** inArgv, int* outOptc, FLIST* outFileList);

#endif