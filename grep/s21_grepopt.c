#define _GNU_SOURCE
#include "s21_grepopt.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/s21_errproc.h"
#include "s21_grep.h"

void getOptions(int acount, char** args, OptList* opt, char** pstr) {
  const char* shortopt = "e:ivclnhsof:";
  const struct option longopt[] = {{"regexp", 1, NULL, 'e'},
                                   {"ignore-case", 0, NULL, 'i'},
                                   {"invert-match", 0, NULL, 'v'},
                                   {"count", 0, NULL, 'c'},
                                   {"files-with-matches", 0, NULL, 'l'},
                                   {"line-number", 0, NULL, 'n'},
                                   {"no-filename", 0, NULL, 'h'},
                                   {"no-messages", 0, NULL, 's'},
                                   {"file", 1, NULL, 'f'},
                                   {"only-matching", 0, NULL, 'o'},
                                   {NULL, 0, NULL, 0}};
  char optleter;
  short int fstop = 0;

  while ((optleter = getopt_long(acount, args, shortopt, longopt, NULL)) !=
             -1 &&
         !fstop) {
    switch (optleter) {
      case 'e':
        getPattern(pstr, optarg);
        break;
      case 'f':
        getPatternFromFile(pstr, optarg);
        break;
      case 'i':
        opt->caseinsensitive = 1;
        break;
      case 'v':
        opt->invertcondition = 1;
        break;
      case 'c':
        opt->showlinecount = 1;
        break;
      case 'l':
        opt->showsamefiles = 1;
        break;
      case 'n':
        opt->showlinenumber = 1;
        break;
      case 'h':
        opt->showonlystrings = 1;
        break;
      case 's':
        opt->suppreswarnings = 1;
        break;
      case 'o':
        opt->printonlyparts = 1;
        break;
      case '?':
        printErrorMsg(PROGNAME, WRONG_OPT, &optleter);
        printf(USAGE_MSG);
        fstop = 1;
        break;
      default:
        printf(USAGE_MSG);
        fstop = 1;
    };
  }
}

void getPatternFromFile(char** patterns, const char* patternfile) {
  static int wasFile = 0;
  if (!wasFile) {
    FILE* pf = fopen(patternfile, "r");

    if (pf) {
      char* str = NULL;
      size_t memlen = 0;
      int read;

      while ((read = getline(&str, &memlen, pf)) != -1) {
        if (str[read - 1] == '\n') str[read - 1] = '\0';
        if (strlen(str) != 0) getPattern(patterns, str);
      }
      if (str) free(str);
    } else {
      printErrorMsg(PROGNAME, WRONG_FILE, patternfile);
    }
    if (pf) fclose(pf);
    wasFile++;
  }
}

void getPattern(char** patterns, const char* pattern) {
  if (!(*patterns)) {
    *patterns = malloc((strlen(pattern) + 1) * sizeof(char));
    strcpy(*patterns, pattern);
  } else {
    const char* delim = "|";
    char* p = malloc(sizeof(char) * (strlen(pattern) + 2));
    strcpy(p, delim);
    strcat(p, pattern);
    *patterns =
        realloc(*patterns, (strlen(*patterns) + strlen(p) + 1) * sizeof(char));
    strcat(*patterns, p);
    free(p);
  }
}

void getFiles(list** filelist, const char* filename) {
  if (!(*filelist)) {
    *filelist = malloc(sizeof(list));
    (*filelist)->count = 0;
    (*filelist)->pStr = NULL;
  }
  if (*filelist) {
    (*filelist)->count++;
    (*filelist)->pStr =
        realloc((*filelist)->pStr, (*filelist)->count * sizeof(char*));
    char* fn = malloc(sizeof(char) * (strlen(filename) + 1));
    strcpy(fn, filename);
    (*filelist)->pStr[(*filelist)->count - 1] = fn;
  }
}