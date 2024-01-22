#include "s21_catopt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/s21_ctypedef.h"


int setParameters(char* optstr, OptList* optList) {
  int err = 0;
  if (optstr[1] == '-') {
#ifdef APPLE
    err++;
    printf(
        "there are not any function to print error message about illegal "
        "parameter\n");
    printf(
        "Sample: cat: illegal option -- \"option\"\nusage: cat [-benstuv] "
        "[file ...]\n");
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
#ifdef APPLE
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
        default:
          err++;
          printf("error \n");
      }
    }
  }
  return err;
}


/*OptList* parseCli(int inArgc, char** inArgv, OptList* optList, int* errCode) {
  optList = allocateOptList();

  if (inArgc != 1) {
    for (int c = 1; c < inArgc; c++) {
      if (inArgv[c][0] == '-' && inArgv[c][1] != '\0') {
        *errCode = setParameters(inArgv[c], optList);
        #ifndef APPLE
        if (optList->help || optList->version) break;
        #endif
      } else {
        optList->pathList->count++;
        optList->pathList->path = addPath(optList->pathList->path, inArgv[c], optList->pathList->count);
      }
    }
  }

  //printf("file count %d\n", optList->pathList->count);

  return optList;
}*/


OptList* allocateOptList() {
  OptList* opt = malloc(sizeof(OptList));

  if (opt) {
    opt->pathList = allocatePaths();
    #ifndef APPLE
    opt->help = 0;
    opt->version = 0;
    #endif
    opt->shownpr = 0;
    opt->showtabs = 0;
    opt->showends = 0;
    opt->strnum = 0;
    opt->strnumnbl = 0;
    opt->sblank = 0;
  }

  return opt;
}

void deallocOptList(OptList* inOptList) {
  if (inOptList->pathList != NULL) deallocPaths(inOptList->pathList);
  free(inOptList);
}