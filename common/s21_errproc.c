#include "s21_errproc.h"

#include <stdio.h>

void printErrorMsg(char* progname, char* errMsg, char* errValue) {
  printf(errMsg, progname, errValue);
}
