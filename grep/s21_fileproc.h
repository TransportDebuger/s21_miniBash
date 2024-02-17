#ifndef S21_FILEPROC_H
#define S21_FILEPROC_H

#include <stdio.h>

#include "../common/s21_ctypedef.h"

void fileprocessing(char* fname, const OptList* opt);
int ismatch(char* str, char* pattern, int CFlag);

#endif