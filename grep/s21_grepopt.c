#include "s21_grepopt.h"

#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "s21_grep.h"
#include "../common/s21_errproc.h"


OptList initOptList() {
  OptList opt = {.filelist = NULL,
                 .patternlist = NULL,
                 .caseinsensitive = 0,
                 .invertcondition = 0,
                 .printonlyparts = 0,
                 .regexfile = 0,
                 .showlinecount = 0,
                 .showlinenumber = 0,
                 .showonlystrings = 0,
                 .showsamefiles = 0,
                 .suppreswarnings = 0};

  return opt;
}

OptList* getOptions(int acount, char** args) {
  OptList* opt = NULL;
  if (acount > 1) {
    opt = malloc(sizeof(OptList));
    if (opt) {
      const char* shortopt = "e:ivclnhsof:";
      const struct option longopt[] = {
        { "regexp", 1, NULL, 'e' },
        { "ignore-case", 0, NULL, 'i' },
        { "invert-match", 0, NULL, 'v' },
        { "count", 0, NULL, 'c' },
        { "files-with-matches", 0, NULL, 'l' },
        { "line-number", 0, NULL, 'n' },
        { "no-filename", 0, NULL, 'h' },
        { "no-messages", 0, NULL, 's' },
        { "file", 1, NULL, 'f' },
        { "only-matching", 0, NULL, 'o' },
        { NULL, 0, NULL, 0 }
      };
      char optleter;
      short int fstop = 0;

      *opt = initOptList();
      opterr = 0;
      while((optleter = getopt_long(acount, args, shortopt, longopt, NULL)) != -1 && !fstop) {
        switch (optleter) {
            case 'e':
                opt->patternlist = getPattern(opt->patternlist, optarg);
                break;
            case 'f':
                opt->patternlist = getPatternFromFile(opt->patternlist, optarg); //files parsing
                break;
            case 'i':
                opt->caseinsensitive = 1;
                break;
            case 'v':
                opt->invertcondition = 1;
                break;
            case 'c':
                opt->showlinenumber = 1;
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
            case '?': printErrorMsg(PROGNAME, WRONG_OPT, &optleter);
            default :
                printf("USAGE ...\n");    
                fstop = 1;
        };
        printf("%c\n", optleter);
      }
    }
  }

  return opt;
}

void destroyOptions(OptList* opt) {
  if (opt) {
    destroyPatternList(opt->patternlist);
    free(opt);
  }
}

list* getPatternFromFile(list* patternlist, char* patternfile) {
  static int wasFile = 0;
  if (!wasFile) {
    FILE* pf = fopen(patternfile, "r");
    if (pf) {
      //read patterns by line from file
      while (feof(pf) == 0) {
        char str[256];
        char* linebuffer = fgets(str, sizeof(str), pf);
        printf("linebuffer filled: %s", linebuffer);
        //patternlist = getPattern(patternlist, linebuffer);
      }
    } else {
      printErrorMsg(PROGNAME, WRONG_FILE, patternfile);
    }
    fclose(pf);
    wasFile++;
  }
  return patternlist;
}

list* getPattern(list* patternlist, char* pattern) {
  if (!patternlist) {
    patternlist =  malloc(sizeof(list));
    patternlist->count = 0;
  }
  patternlist->fname = realloc(patternlist->fname, patternlist->count * sizeof(char*));
  patternlist->fname[patternlist->count] = pattern;
  patternlist->count++;
  return patternlist;
}

void destroyPatternList(list* patternlist) {
  if (patternlist) {
    if (patternlist->fname) {
      for (int c = 0; c < patternlist->count; c++) {
        free(patternlist->fname[c]);
      }
    }
    free(patternlist);
  }
}

list* getFiles(list* filelist, char* filename) {

  return NULL;
}

void destroyFileList(list* filelist) {

}
