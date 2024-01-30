#include "s21_fileproc.h"

#include <stdio.h>
//#include <stdlib.h>
#include "../common/s21_ctypedef.h"
#include "s21_catopt.h"

void printFile(FILE* inFile, OptList* popt) {
  char c = fgetc(inFile);
  
  // Output modifiers needed

  while (c != EOF) {
    if (c == '\t' && popt->showtabs) {
        printf("^I");
    } else if (c == '\n' && popt->showends){
        printf("$\n");
    } else {
        putc(c, stdout);
    }
    c = fgetc(inFile);
  }
}