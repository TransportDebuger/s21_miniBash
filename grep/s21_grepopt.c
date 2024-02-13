#include "s21_grepopt.h"

#include <getopt.h>
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
        opt->patternlist = getPattern(opt->patternlist, optarg);
        break;
      case 'f':
        opt->patternlist = getPatternFromFile(opt->patternlist, optarg);
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
      default:
        printf(USAGE_MSG);
        fstop = 1;
    };
  }
}

void destroyOptions(OptList* opt) {
  if (opt != NULL) {
    if (opt->patternlist) free(opt->patternlist);
    free(opt);
  }
}

list* getPatternFromFile(list* patternlist, char* patternfile) {
  list* pl = patternlist;
  static int wasFile = 0;
  if (!wasFile) {
    FILE* pf = fopen(patternfile, "r");
    if (pf) {
      while (feof(pf) == 0) {
        char str[256];
        pl = getPattern(pl, fgets(str, sizeof(str), pf));
      }
    } else {
      printErrorMsg(PROGNAME, WRONG_FILE, patternfile);
    }
    if (pf) fclose(pf);
    wasFile++;
  }

  return pl;
}

list* getPattern(list* patternlist, char* pattern) {
  list* pl = patternlist;
  if (!pl) {
    pl = malloc(sizeof(list));
    pl->count = 0;
    pl->fname = NULL;
  }
  if (pl) {
    pl->count++;
    pl->fname =
        realloc(pl->fname, (pl->count) * sizeof(char *));
    char* p = malloc(sizeof(char) * (strlen(pattern)+1));
    strcpy(p, pattern);
    pl->fname[pl->count - 1] = p;
  }

  return pl;
}

list* getFiles(list* filelist, char* filename) {
  list* fl = filelist;
  printf("%p ", fl);
  if (!fl) {
    fl = malloc(sizeof(list));
  }
  printf("%p\n", fl);
  if (fl) {
    fl->count++;
    fl->fname = realloc(fl->fname, fl->count * sizeof(char *));
    char* fn = malloc(sizeof(char) * (strlen(filename)+1));
    strcpy(fn, filename);
    fl->fname[fl->count - 1] = fn;
  }

  return fl;
}

void destroyFileList(list* filelist) {}
