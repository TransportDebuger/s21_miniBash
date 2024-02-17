#ifndef S21_GREPOPT_H
#define S21_GREPOPT_H

#include "../common/s21_ctypedef.h"

struct options {
  list* filelist;
  list* patternlist;    //-e template
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

void getOptions(int acount, char** args, OptList* opt);
void destroyOptions(OptList* opt);
list* getPatternFromFile(list* patternlist, char* patternfile);
list* getPattern(list* patternlist, char* pattern);
void destroyPatternList(list* patternlist);
list* getFiles(list* filelist, char* filename);

#endif