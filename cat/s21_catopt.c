#include "s21_catopt.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int setParameters(char* optstr, OptList* optList) {
  int err = 0;
  if (optstr[1] == '-') {
    #ifdef __APPLE
      err++;
      printf("there are not any function to print error message about illegal parameter\n");
      printf("Sample: cat: illegal option -- \"option\"\nusage: cat [-benstuv] [file ...]\n");
    #else
      printf("POSIX options processing here");
    #endif
    
    // parse parameters posix-type ("--parameter")
  } else {
    for (int c = 1; c < strlen(optstr) && !err; c++) {
      switch (optstr[c]) {
        case 'b': 
          optList->strnumnbl = 1;
          break;
        case 'n': 
          optList->strnum = 1;
          break;
        case 's': 
          optList->sblank = 1;
          break;
        case 'v':
          optList->shownpr = 1;
          break;
      #ifdef __APPLE
        case 'e':
          optList->showends = 1;
          break;
        case 't':
          optList->showtabs = 1;
          break;
      #else
        case 'e':
          optList->showends = 1;
          optList->shownpr = 1;
          break;
        case 'E':
          optList->showends = 1;
          break;
        case 't':
          optList->showtabs = 1;
          optList->shownpr = 1;
          break;
        case 'T':
          optList->showtabs = 1;
          break;
        case 'A':
          optList->showtabs = 1;
          optList->shownpr = 1;
          optList->showends = 1;
          break;
      #endif

        default :
          err++;
          printf("error \n");
      }
    }
  }
  return err;
}

OptList* parseCli(int inArgc, char** inArgv, OptList* optList, int* errCode) {
  optList = allocateOptList();
  optList->help = 0;
  optList->version = 0;
  optList->shownpr = 0;
  optList->showtabs = 0;
  optList->showends = 0;
  optList->strnum = 0;
  optList->strnumnbl = 0;
  optList->sblank = 0;

  if (inArgc != 1) {
    for (int c = 1; c < inArgc; c++) {
      if (inArgv[c][0] == '-' && inArgv[c][1] != '\0') {
        *errCode = setParameters(inArgv[c], optList);
      } else {
        optList->pathList->count++;
      }
    }
  }

  printf("file count %d\n", optList->pathList->count);

  return optList;
}

OptList* allocateOptList() {
  OptList* opt = malloc(sizeof(OptList));
  opt->pathList = allocatePaths();
  if (opt) {
    opt->pathList->count = 0;
    opt->pathList->path = NULL;
  }
  return opt;
}

void deallocOptList(OptList* inOptList) {
    if (!(inOptList->pathList)) deallocPaths(inOptList->pathList);
    free(inOptList);
}