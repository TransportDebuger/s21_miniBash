#ifndef S21_FROUTINES_H
#define S21_FROUTINES_H

#include <stdio.h>

#include "s21_ctypedef.h"
#include "s21_optproc.h"

FLIST* createFileList(const int pcount, char** pArgs);
void destroyFileList(FLIST* flist);

FILE* openFile(char* fname);
void printFile(FILE* inFile, OptList* popt);
void closeFile(FILE* pfile);

#endif