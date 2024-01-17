#include "s21_errproc.h"

#include <stdio.h>

void printErrorMsg(char* errMsg) {
    int i = 0;
    while (errMsg[i] != '\0') {
        putchar(errMsg[i]);
        ++i;
    }
}
