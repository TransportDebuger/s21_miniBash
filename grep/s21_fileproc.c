#define _GNU_SOURCE
#include "s21_fileproc.h"

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/s21_ctypedef.h"
#include "../common/s21_errproc.h"
#include "s21_grep.h"
#include "s21_grepopt.h"

void fileprocessing(char* filename, char* patterns, const OptList* opt,
                    int filecount) {
  FILE* f;
  regex_t re;
  int err = regex_compile(&re, patterns, opt->caseinsensitive);

  if (!filename) {
    f = stdin;
  } else {
    f = fopen(filename, "r");
    if (!f && !(opt->suppreswarnings)) {
      printErrorMsg(PROGNAME, WRONG_FILE, filename);
    }
  }

  if (f && !err) {
    print_file(f, opt, &re, filecount, filename);
  }
  regfree(&re);
}

int ismatch(char* str, regex_t* re, regmatch_t* rm) {
  int retval = 0;

  retval = regexec(re, str, re->re_nsub + 1, rm, 0);

  return retval;
}

int regex_compile(regex_t* re, char* patterns, int caseinsensitive) {
  int err;
  int flag = REG_EXTENDED;

  if (caseinsensitive) flag = (flag | REG_ICASE);
  if ((err = regcomp(re, patterns, flag)) != 0)
    printErrorMsg(PROGNAME, REGEX_COMP_ERR, NULL);

  return err;
}

void print_file(FILE* f, const OptList* opt, regex_t* re, int filecount,
                char* filename) {
  int strcount = 0, matchcount = 0;

  while (feof(f) == 0) {
    regmatch_t* rm = malloc(sizeof(regex_t) * (re->re_nsub + 1));
    char* str = NULL;
    size_t memlen = 0;
    getline(&str, &memlen, f);
    strcount++;
    int match = 0;
    int m;

    if (opt->caseinsensitive)
      m = ismatch(str, re, rm);
    else
      m = ismatch(str, re, rm);

    if (m == 0 && !(opt->invertcondition)) {
      match = 1;
      matchcount++;
    } else if (m == 1 && opt->invertcondition) {
      match = 1;
      matchcount++;
    }

    if (match && !(opt->showsamefiles) && !(opt->showlinecount)) {
      if (!(opt->printonlyparts)) {
        if (filename && filecount > 1 && !(opt->showonlystrings))
          printf("%s:", filename);
        else if (!(filename) && filecount > 1 && !(opt->showonlystrings))
          printf("(standard input):");
        if (opt->showlinenumber) printf("%d:", strcount);
        fputs(str, stdout);
        if (str[strlen(str) - 1] != '\n') fputs("\n", stdout);
      } else {
        // printf("%lu::", re->re_nsub);
        // for (size_t i = 0; i < re->re_nsub; i++) {
        if (!(opt->invertcondition)) {
          if (filename && filecount > 1 && !(opt->showonlystrings))
            printf("%s:", filename);
          else if (!(filename) && filecount > 1 && !(opt->showonlystrings))
            printf("(standard input):");
          if (opt->showlinenumber) printf("%d:", strcount);
          for (int j = rm[0].rm_so; j < rm[0].rm_eo; j++) {
            printf("%c", str[j]);
          }
          printf("\n");
        }
        //}
      }
    }
    free(str);
    if (rm) free(rm);
  }

  if (matchcount && opt->showsamefiles)
    printf("%s\n", filename);
  else if (opt->showlinecount && !(opt->showsamefiles)) {
    if (filecount > 1 && !(opt->showonlystrings))
      printf("%s:%d\n", filename, matchcount);
    else {
      printf("%d\n", matchcount);
    }
  }

  fclose(f);
}