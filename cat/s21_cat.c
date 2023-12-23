#include <stdio.h>
#include "../common/common.h"

//FILE* openFile(char* fileName);
void printFile(FILE* inFile);
//void printFile(FILE* inFile, int modifier);
//void closeFile(FILE* inFile);


int main(int argc, char** argv) {
    struct modifier** mod;
    if (argc != 1) {
        mod = getModifiers(argc, argv);
        
        //TO-DO: file read
        //TO-DO: file(s) terminal print with 

    } else {
        printFile(stdin);
    }

    return 0;
}


void printFile(FILE* inFile) {
    int c = fgetc(inFile);
    //code may changes whith modifier variable

    while (c != EOF) {
        putc(c, stdout);
        c = fgetc(inFile);
    }
};