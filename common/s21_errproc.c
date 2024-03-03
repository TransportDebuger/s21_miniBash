#include "s21_errproc.h"

#include <stdio.h>

void printErrorMsg(const char* progname, const char* errMsg,
                   const char* errValue) {
  printf(errMsg, progname, errValue);
}
