#include "s21_grepopt.h"

#include <stdlib.h>

OptList initOptList() {
    OptList opt = {.tmplt=0, 
                   .caseinsensitive=0, 
                   .invertcondition=0, 
                   .printonlyparts=0,
                   .regexfile=0,
                   .showlinecount=0,
                   .showlinenumber=0,
                   .showonlystrings=0,
                   .showsamefiles=0,
                   .suppreswarnings=0};

    return opt;
}

OptList* getOptions(int acount, char** args) {
    OptList* opt = malloc(sizeof(OptList));
    if (opt) *opt = initOptList();
    else opt = NULL;

    return opt;
}

void deallocOptList(OptList* opt) {
    free(opt);
}