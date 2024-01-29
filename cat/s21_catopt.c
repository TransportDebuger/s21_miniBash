#include "s21_catopt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_cat.h"
#include "../common/s21_ctypedef.h"
#include "../common/s21_errproc.h"

OptList* parseOptions(const int pcount, char** pArgs) {
  OptList* opt = malloc(sizeof(OptList));

  if (opt) {
    *opt = initOptList();
    for (int c = 1; c < pcount; c++) {
      int err = 0;
      if (pArgs[c][0] == '-') {
        if ((err = setParameters(pArgs[c], opt)) != 0) {
          deallocOptList(opt);
          opt = NULL;
          break;
        }
        if (opt->help == 1 || opt->version == 1) {
          break;
        }
      }
    }
  }

  return opt;
}

OptList initOptList() {
#ifdef APPLE
  OptList init = {.shownpr = 0,
                  .showtabs = 0,
                  .showends = 0,
                  .strnum = 0,
                  .strnumnbl = 0,
                  .sblank = 0};
#else
  OptList init = {.help = 0,
                  .version = 0,
                  .shownpr = 0,
                  .showtabs = 0,
                  .showends = 0,
                  .strnum = 0,
                  .strnumnbl = 0,
                  .sblank = 0};
#endif

  return init;
}

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
          printErrorMsg(PROGNAME, WRONG_OPT, &(optstr[c]));
      }
    }
  }
  return err;
}

void deallocOptList(OptList* inOptList) { free(inOptList); }