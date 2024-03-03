#include "s21_fileproc.h"

#include <stdio.h>

#include "../common/s21_ctypedef.h"
#include "s21_catopt.h"

#define HIGHBIT 128

void printSymbol(char c, const OptList* popt) {
  if (c == '\n') {
    if (popt->showends)
      printf("$\n");
    else
      putc(c, stdout);
  } else if (c == '\t') {
    if (popt->showtabs)
      printf("^I");
    else
      putc(c, stdout);
  } else if ((c & HIGHBIT) && popt->shownpr) {
    printf("M-");
    c = (c & (~HIGHBIT));
    if (c < 32 || c == 127)
      printf("^%c", c + 64);
    else
      putchar(c);
  } else if (popt->shownpr) {
    if (c < 32)
      printf("^%c", c + 64);
    else if (c == 127)
      printf("^%c", c - 64);
    else
      putchar(c);
  } else {
    putc(c, stdout);
  }
}

void printFile(FILE* inFile, const OptList* popt) {
  int c = fgetc(inFile);
  int prevc = '\n';
  static int linecount = 1;
  short int blineprn = 0;

  while (c != EOF) {
    if (!(popt->sblank && prevc == '\n' && c == '\n' && blineprn)) {
      if (prevc == '\n' && c == '\n')
        blineprn = 1;
      else
        blineprn = 0;
      if (((popt->strnum && !(popt->strnumnbl)) ||
           (popt->strnumnbl && c != '\n')) &&
          prevc == '\n') {
        printf("%6d\t", linecount);
        linecount++;
      }
      printSymbol(c, popt);
    }
    prevc = c;
    c = fgetc(inFile);
  }
}