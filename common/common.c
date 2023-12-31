#include "common.h"

#include <stdlib.h>

#ifdef DEBUG
#include <stdio.h>
#endif


#ifdef DEBUG
void printParameters(int inArgc, char** inArgv) {
    int count = 1;
    while (count < inArgc) {
        printf("%s\n", inArgv[count]);
        ++count;
    }
}

#endif

int getSettingsCount(int inArgc, char** inArgv) {
    int count = 0;
    while (count+1<inArgc && inArgv[count+1][0]=='-') {
        ++count;
    }
    return count;
}


struct settings** parseModifiers(int modc, char** modv) {
    struct settings** modlist;
    if (modc == 0) modlist = NULL;
    else {
        modlist = malloc(modc*sizeof(struct settings));
        int index = 1;
        while (index < modc) {
            index++;
        }
    }
    return modlist;
}