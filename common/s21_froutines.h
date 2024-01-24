#ifndef S21_FROUTINES_H
#define S21_FROUTINES_H

#include <stdio.h>

#include "s21_optproc.h"

FILE* openFile(char* fname);
void printFile(FILE* inFile, OptList* popt);
void closeFile(FILE* pfile);

#endif