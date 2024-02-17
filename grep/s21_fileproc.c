#include "s21_fileproc.h"

#include <stdio.h>
#include <string.h>
#include <regex.h>

#include "../common/s21_ctypedef.h"
#include "../common/s21_errproc.h"
#include "s21_grep.h"
#include "s21_grepopt.h"

void fileprocessing(char* fname, const OptList* opt) {
  FILE* f;
  int strcount = 0, matchcount = 0;

  if (!fname) {
    f = stdin;
  } else {
    f = fopen(fname, "r");
    if (!f && !(opt->suppreswarnings)) {
      printErrorMsg(PROGNAME, WRONG_FILE, fname);
    }
  }
  
  if (f) {
    while (feof(f) == 0) {
      char str[256];
      fgets(str, sizeof(str), f);
      strcount++;
      int match = 0;
      for (int i = 0; i < opt->patternlist->count; i++) {
        int m;
        if (opt->caseinsensitive) m = ismatch(str, opt->patternlist->fname[i], 1);
        else m = ismatch(str, opt->patternlist->fname[i], 0);
        printf("m1\n");
        if (m == 0 && !(opt->invertcondition)) {
          match = 1;
          matchcount++;
          break;
        } else if (m == 1 && opt->invertcondition) {
          match = 1;
        } else if (m == 0 && opt->invertcondition) {
          match = 0;
          matchcount++;
          break;
        }
      }
      if (match && !(opt->showsamefiles) && !(opt->showlinecount)) {
        if (fname && opt->filelist->count > 1 && !(opt->showonlystrings))
          printf("%s:", fname);
        else if (!(fname) && opt->filelist->count > 1 &&
                 !(opt->showonlystrings))
          printf("(standard input):");
        if (opt->showlinenumber) printf("%d:", strcount);
        fputs(str, stdout);
      }
    }
    if (matchcount && opt->showsamefiles)
      printf("%s\n", fname);
    else if (matchcount && opt->showlinecount) {
      if (opt->filelist->count > 1)
        printf("%s:%d\n", fname, matchcount);
      else {
        printf("%d\n", matchcount);
      }
    }
    fclose(f);
  }
}

int ismatch(char* str, char* pattern, int caseinsensitive) {
  int retval = 0;
  regex_t* re = NULL;
  int flag = REG_EXTENDED;
  
  if (caseinsensitive) flag = (flag | REG_ICASE);
  printf("%d\n", retval);
  retval = regcomp(re, pattern, flag);
  printf("%d\n", retval);
  if (retval == 0) {
    printf("%d\n", retval);
    retval = regexec(re, str, 0, NULL, 0);
  }
  
  return retval;
}