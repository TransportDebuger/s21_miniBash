#include <stdio.h>

#include "../common/s21_ctypedef.h"
#include "s21_grepopt.h"
//#include "../common/s21_getopt.h"


int main(int argc, char** argv) {
    int errCode = 0;
    OptList* opt = getOptions(argc, argv);

    if (opt) {

    } else {
        errCode++;
    }


    return errCode;
}