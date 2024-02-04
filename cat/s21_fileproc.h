#ifndef S21_FILEPROC_H
#define S21_FILEPROC_H

#include <stdio.h>

#include "../common/s21_ctypedef.h"

// FLIST* createFileList(const int pcount, char** pArgs);
// void destroyFileList(FLIST* flist);

// FILE* openFile(char* fname);
void printFile(FILE* inFile, OptList* popt);
// void closeFile(FILE* pfile);

#endif