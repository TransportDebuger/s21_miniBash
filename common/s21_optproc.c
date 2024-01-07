#include "s21_optproc.h"

#include <stdlib.h>
//#include <stdio.h>

#include "s21_froutines.h"

int parseCli(int inArgc, char** inArgv, int* outOptc, FLIST* outFileList) {
  int errCode = 0, count = 1, optcount = 0;
  outFileList->count = 0;
  while (count < inArgc && !errCode) {
    if (inArgv[count][0]=='-') {
        if (inArgv[count][1] == '\0') {
            ++outFileList->count;
        } 
    } else {
        ++outFileList->count;
    }
    ++count;
  }
  if (outFileList->count == 0) {
      outFileList->count++;
  }
  return errCode;
}