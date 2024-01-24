#include "s21_optproc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FLIST* allocatePaths() {
  FLIST* paths = (FLIST*)malloc(sizeof(FLIST));

  if (paths) {
    paths->count = 0;
    paths->path = NULL;
  }

  return paths;
}

void deallocPaths(FLIST* inFileList) {
  if (inFileList->path != NULL) {
    free(inFileList);
  }
}

char** addPath(char** flist, char* fname, const int fcount) {
  if (!flist) {
    flist = (char**)malloc(sizeof(char*));
  } else {
    flist = (char**)realloc(flist, fcount * sizeof(char*));
  }
  flist[fcount - 1] = fname;

  return flist;
}

//#include "s21_froutines.h"