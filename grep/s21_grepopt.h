#ifndef S21_GREPOPT_H
#define S21_GREPOPT_H

#include "../common/s21_ctypedef.h"

struct option {
    int tmplt; //-e template
    int caseinsensitive; //-i ignore case diffrence;
    int invertcondition; //-v invert condition of search
    int showlinecount; //-c show number of same lines
    int showsamefiles; //-l show only files with same content
    int showlinenumber; //-n
    int showonlystrings; //-h without file names
    int suppreswarnings; //-s suppress error messages
    int regexfile; //-f <file> get reular expressions from file
    int printonlyparts; //-0 print onl;y the same (nonbanck) parts of strings
};

OptList* getOptions(int acount, char** args);
void deallocOptList(OptList* opt);

#endif