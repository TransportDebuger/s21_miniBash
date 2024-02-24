#ifndef S21_FILEPROC_H
#define S21_FILEPROC_H

#include "../common/s21_ctypedef.h"

void fileprocessing(char* filename, char* patterns, const OptList* opt,
                    int filecount);
int ismatch(char* str, char* patterns, int CFlag);

#endif