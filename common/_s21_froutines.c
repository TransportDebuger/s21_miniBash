#include "s21_froutines.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_optproc.h"

/*FLIST* createFileList(const int pcount, char** pArgs) {
  FLIST* fl = NULL;
  short int errFlag;

  fl = malloc(sizeof(FLIST));
  if (fl) {
    fl->count = 0;
    fl->files = NULL;
    if (pcount > 1) {
      for (int c = 1; c < pcount; c++) {
        if (pArgs[c][0] != '-') {
          fl->count++;
          fl->files = realloc(fl->files, fl->count * sizeof(FILE*));
          fl->fnames = realloc(fl->files, fl->count * sizeof(char*));
          fl->fnames[fl->count - 1] = pArgs[c];
          fl->files[fl->count - 1] = openFile(pArgs[c]);
        } else if (strcmp("-", pArgs[c]) == 0 || strcmp("--", pArgs[c]) == 0) {
          fl->count++;
          fl->files = realloc(fl->files, fl->count * sizeof(FILE*));
          fl->fnames = realloc(fl->files, fl->count * sizeof(char*));
          fl->fnames[fl->count - 1] = NULL;
          fl->files[fl->count - 1] = NULL;
        }
      }
      
    } 
    if (fl->count == 0) {
      fl->count++;
      fl->files = realloc(fl->files, fl->count * sizeof(FILE*));
      fl->fnames = realloc(fl->files, fl->count * sizeof(char*));
      fl->fnames[fl->count - 1] = NULL;
      fl->files[fl->count - 1] = NULL;
    }
  }
  // needs to create error processing
  return fl;
}*/

/*void destroyFileList(FLIST* flist) { 
  if (flist->files) {
    for (int c = 0; c < flist->count; c++) {
      if (flist->files[c]) closeFile(flist->files[c]);
    }
  }
  free(flist); 
}*/

/*FILE* openFile(char* fname) {
  FILE* f = fopen(fname, "r");
  
  return f;
}*/

void printFile(FILE* inFile, OptList* popt) {
  char c = fgetc(inFile);
  
  // Output modifiers needed

  while (c != EOF) {
    if (c == '\t' && popt->)
    putc(c, stdout);
    c = fgetc(inFile);
  }
}

/*void closeFile(FILE* file) { fclose(file); }*/