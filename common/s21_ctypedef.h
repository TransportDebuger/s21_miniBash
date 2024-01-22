#ifndef S21_CTYPEDEF_H
#define S21_CTYPEDEF_H

#include <stdio.h>

typedef struct option OptList;

typedef struct fileList FLIST;
struct fileList {
  int count;
  char** path; //It must be deleted after full project test
  FILE** files;
};


#endif