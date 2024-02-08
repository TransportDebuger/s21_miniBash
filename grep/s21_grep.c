#include "s21_grep.h"

#include <stdio.h>
#include <stdlib.h>

#include "../common/s21_ctypedef.h"
#include "../common/s21_errproc.h"
#include "s21_grepopt.h"
// #include "../common/s21_getopt.h"

int main(int argc, char** argv) {
  int errCode = 0;
  OptList* opt = NULL;
  opt = getOptions(argc, argv);
  printf("%p\n", opt);
  if (opt) {
    for (int c = 0; c < opt->patternlist->count; c++) {
      printf("%s\n", opt->patternlist->fname[c]);
    }
    errCode = 0;
  } else {
    errCode++;
  }

  destroyOptions(opt);
  return errCode;
}