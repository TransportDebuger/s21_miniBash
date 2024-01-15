#include "s21_froutines.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printFile(FILE* inFile) {
  int c = fgetc(inFile);
  // Output modifiers needed

  while (c != EOF) {
    putc(c, stdout);
    c = fgetc(inFile);
  }
}