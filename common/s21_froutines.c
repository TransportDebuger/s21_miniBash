#include "s21_froutines.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_optproc.h"

FILE* openFile(char* fname) {
  FILE* f = fopen(fname, "r");

  return f;
}

void printFile(FILE* inFile, OptList* popt) {
  int c = fgetc(inFile);
  // Output modifiers needed

  while (c != EOF) {
    putc(c, stdout);
    c = fgetc(inFile);
  }
}

void closeFile(FILE* file) {
  fclose(file);
}