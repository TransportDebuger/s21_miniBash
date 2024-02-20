#define _GNU_SOURCE
#include "s21_grepopt.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/s21_errproc.h"
#include "s21_grep.h"

void getOptions(int acount, char** args, OptList* opt) {
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
        // opt->pattern = getPattern(opt->pattern, optarg);
        break;
      case 'f':
        opt->pattern = getPatternFromFile(opt->pattern, optarg);
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
        [[fallthrough]];
      default:
        printf(USAGE_MSG);
        fstop = 1;
    };
  }
}

/*void destroyOptions(OptList* opt) {
  if (opt != NULL) {
    if (opt->pattern) free(opt->pattern);
    free(opt);
  }
}*/

char* getPatternFromFile(char* patterns, char* patternfile) {
  char* pl = patterns;
  static int wasFile = 0;
  if (!wasFile) {
    FILE* pf = fopen(patternfile, "r");

    if (pf) {
      char* str = NULL;
      size_t memlen = 0;

      while (feof(pf) == 0) {
        int read = getline(&str, &memlen, pf);
        if (str[read - 1] == '\n') str[read - 1] = '\0';
        pl = getPattern(pl, str);
      }
      if (str) free(str);
    } else {
      printErrorMsg(PROGNAME, WRONG_FILE, patternfile);
    }
    if (pf) fclose(pf);
    wasFile++;
  }

  return pl;
}

char* getPattern(char* patterns, char* pattern) {
  char* pl = patterns;
  char delim = '|';

  if (!pl) {
    pl = malloc(sizeof(char));
  }
  if (pl) {
    if (strlen(pl) == 0) {
      pl = realloc(pl, (strlen(pattern) + 1) * sizeof(char));
      strcpy(pl, pattern);
    } else {
      char* p = malloc(sizeof(char) * (strlen(pattern) + 2));
      strcpy(p, &delim);
      strcat(p, pattern);
      pl = realloc(pl, (strlen(pl) + strlen(p) + 1) * sizeof(char));
      strcat(pl, p);
    }
  }

  return pl;
}

list* getFiles(list* filelist, char* filename) {
  list* fl = filelist;
  if (!fl) {
    fl = malloc(sizeof(list));
  }
  if (fl) {
    fl->count++;
    fl->pStr = realloc(fl->pStr, fl->count * sizeof(char*));
    char* fn = malloc(sizeof(char) * (strlen(filename) + 1));
    strcpy(fn, filename);
    fl->pStr[fl->count - 1] = fn;
  }

  return fl;
}