#include <stdio.h>
#include <stdlib.h>

#include "../common/common.h"

//FILE* openFile(char* fileName);
void printFile(FILE* inFile, struct settings** mod);

//void closeFile(FILE* inFile);


int main(int argc, char** argv) {
    int errCode = 0;
    int setNumber = getSettingsCount(argc, argv);
    struct settings** mod;
    
    #ifdef DEBUG
    printf("%d\n", setNumber);
    //printParameters(argc, argv);
    #endif

    if (argc != 1) {
        mod = parseModifiers(setNumber, argv);
       
        //TO-DO: file read
        //TO-DO: file(s) terminal print with 

    } else {
        printFile(stdin, mod);
    }
    if (mod != NULL) free(mod);

    return errCode;
}

void printFile(FILE* inFile, struct settings** mod) {
    int c = fgetc(inFile);
    //Output modifiers needed

    while (c != EOF) {
        putc(c, stdout);
        c = fgetc(inFile);
    }
};

void printHelp() {
    printf("Usage: cat [OPTION]... [FILE]...\n");
    printf("Concatenate FILE(s) to standard output.\n\n");
    printf("With no FILE, or when FILE is -, read standard input.\n\n");
    printf("  -A, --show-all           equivalent to -vET\n");
    printf("  -b, --number-nonblank    number nonempty output lines, overrides -n\n");
    printf("  -e                       equivalent to -vE\n");
    printf("  -E, --show-ends          display $ at end of each line\n");
    printf("  -n, --number             number all output lines\n");
    printf("  -s, --squeeze-blank      suppress repeated empty output lines\n");
    printf("  -t                       equivalent to -vT\n");
    printf("  -T, --show-tabs          display TAB characters as ^I\n");
    printf("  -u                       (ignored)\n");
    printf("  -v, --show-nonprinting   use ^ and M- notation, except for LFD and TAB\n");
    printf("      --help     display this help and exit\n");
    printf("      --version  output version information and exit\n\n");
    printf("Examples:\n" );
//    printf("  cat f - g  Output f's contents, then standard input, then g's contents.\n");
    printf("  cat        Copy standard input to standard output.\n\n");
}

void printVersion() {
    printf("s21_cat 1.0\n");
    printf("Written by Artem Ulianov (provemet)\n\n");
}