#ifndef S21_GREPOPT_H
#define S21_GREPOPT_H

#include <stdio.h>

#include "../common/s21_ctypedef.h"

struct options {
  int caseinsensitive;  //-i ignore case diffrence;
  int invertcondition;  //-v invert condition of search
  int showlinecount;    //-c show number of same lines
  int showsamefiles;    //-l show only files with same content
  int showlinenumber;   //-n
  int showonlystrings;  //-h without file names
  int suppreswarnings;  //-s suppress error messages
  int regexfile;        //-f <file> get reular expressions from file
  int printonlyparts;   //-o print only the same (nonbanck) parts of strings
};

void getOptions(int acount, char** args, OptList* opt, char** pstr);
void getPatternFromFile(char** patterns, const char* patternfile);
void getPattern(char** patterns, const char* pattern);
void destroypattern(char* pattern);
void getFiles(list** filelist, const char* filename);

#endif