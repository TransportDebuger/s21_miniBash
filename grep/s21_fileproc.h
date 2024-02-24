#ifndef S21_FILEPROC_H
#define S21_FILEPROC_H

#include <regex.h>
#include <stdio.h>

#include "../common/s21_ctypedef.h"

void fileprocessing(char* filename, char* patterns, const OptList* opt,
                    int filecount);
int regex_compile(regex_t* re, char* patterns, int caseinsensitive);
void print_file(FILE* f, const OptList* opt, regex_t* re, int filecount,
                char* filename);
int ismatch(char* str, regex_t* re, regmatch_t* rm);

#endif