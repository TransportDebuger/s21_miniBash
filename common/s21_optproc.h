#ifndef S21_OPTPROC_H
#define S21_OPTPROC_H

#include <stdio.h>

#include "s21_ctypedef.h"

FLIST* allocatePaths();
char** addPath(char** flist, char* fname, const int fcount);
void deallocPaths(FLIST* inFileList);

/*struct options {
  char* longName;
  int haveArg;
  char shortName;
};*/

#endif