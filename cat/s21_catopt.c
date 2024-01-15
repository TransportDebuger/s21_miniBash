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
      if (!strcmp("--show-all", optstr)) {
        optList->showtabs = 1;
        optList->shownpr = 1;
        optList->showends = 1;        
      } else if (!strcmp("--number-nonblank", optstr)) {
        optList->strnum = 0;
        optList->strnumnbl = 1;
      } else if (!strcmp("--number", optstr)) {
        optList->strnum = 1;
      } else if (!strcmp("--show-ends", optstr)) {
        optList->showends = 1;
      } else if (!strcmp("--squeeze-blank", optstr)) {
        optList->sblank = 1;
      } else if (!strcmp("--show-tabs", optstr)) {
        optList->showtabs = 1;
      } else if (!strcmp("--show-nonprinting", optstr)) {
        optList->shownpr = 1;
      } else if (!strcmp("--help", optstr)) {
        optList->help = 1;
      } else if (!strcmp("--version", optstr)) {
        optList->version = 1;
      }
    #endif
    
    // parse parameters posix-type ("--parameter")
  } else {
    for (unsigned int c = 1; c < strlen(optstr) && !err; c++) {
      switch (optstr[c]) {
        case 'b': 
          optList->strnum = 0;
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
        if (optList->help || optList->version) break;
      } else {
        optList->pathList->count++;
        //filelist processing
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