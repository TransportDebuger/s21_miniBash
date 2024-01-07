#ifndef S21_FROUTINES_H
#define S21_FROUTINES_H

#include <stdio.h>

typedef struct fileList FLIST;
struct fileList {
  int count;
  char** name;
};

int testPath(char* fileName);
// FILE* openFile(char* fileName);
// void closeFile(FILE* inFile);
void printFile(FILE* inFile);

#endif