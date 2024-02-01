#include "s21_fileproc.h"

#include <stdio.h>
//#include <stdlib.h>
#include "../common/s21_ctypedef.h"
#include "s21_catopt.h"

void printSymbol(char c, OptList* popt) {
  if (c == '\n') {
    if (popt->showends) printf("$\n");
    else putc(c, stdout);
  } else if (c == '\t') {
    if (popt->showtabs) printf("^I");
    else putc(c, stdout);
  } else if (c < 32 || c == 127) {
    if (popt->shownpr) {
      putc('^', stdout);
      putc(c + 64, stdout);
    } else {
      putc(c, stdout); 
    }
  } else if (c > 127) {
    if (popt->shownpr) {
      printf("M-");
      putc(c - 128 + 64, stdout);
    } else {
      putc(c, stdout); 
    }
  } else {  
    putc(c, stdout);
  }
}

void printFile(FILE* inFile, OptList* popt) {
  char c = fgetc(inFile);
  char prevc = '\n';
  static int linecount = 1;
  short int blineprn = 0;
  // Output modifiers needed

  while (c != EOF) {
    if (!(popt->sblank && prevc == '\n' && c == '\n' && blineprn)) { 
      if (prevc == '\n' && c == '\n') blineprn = 1;
      else blineprn = 0;
      if ((popt->strnum && !(popt->strnumnbl) || (popt->strnumnbl && c != '\n')) && prevc == '\n') {
        printf("%6d\t", linecount);
        linecount++;
      }
      printSymbol(c, popt);
    }
    prevc = c;
    c = fgetc(inFile);
  }
}