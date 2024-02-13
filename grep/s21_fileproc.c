#include "s21_fileproc.h"

#include <stdio.h>
#include <string.h>

#include "s21_grep.h"
#include "s21_grepopt.h"
#include "../common/s21_ctypedef.h"
#include "../common/s21_errproc.h"

void fileprocessing(char* fname, const OptList* opt) {
    FILE* f;
    int strcount = 0, matchcount = 0;

    if (!fname) {
      f = stdin;
    } else {
      f = fopen(fname, "r");
      if (!f && !(opt->suppreswarnings)){
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
          int m = isSubstrFound(str, opt->patternlist->fname[i]);
          if (m == 1 && !(opt->invertcondition)) {
            match = 1;
            matchcount++;
            break;
          } else if (m == 0 && opt->invertcondition) {
            match = 1;
          } else if (m == 1 && opt->invertcondition) {
            match = 0;
            matchcount++;
            break;
          }
        }
        if (match && !(opt->showsamefiles) && !(opt->showlinecount)) {
          if (fname && opt->filelist->count > 1 && !(opt->showonlystrings)) printf("%s:", fname);
          else if (!(fname) && opt->filelist->count > 1 && !(opt->showonlystrings)) printf("(standard input):");
          if (opt->showlinenumber) printf("%d:", strcount);
          fputs(str, stdout);
        }
      }
      if (matchcount && opt->showsamefiles) printf("%s\n", fname);
      else if (matchcount && opt->showlinecount) {
        if (opt->filelist->count > 1) printf("%s:%d\n", fname, matchcount);
        else {printf("%d\n", matchcount);}
      }
      fclose(f);
    }
    
}

int isSubstrFound(char* str, char* pattern) {
  int match = 0;
  int strl = strlen(str);
  int pl = strlen(pattern);

  if (*pattern =='\0' || pattern == NULL || *str == '\0' || str == NULL || strl < pl) {
    match = 0;
  } else {
    int next[pl+1];
    
    for (int i = 0; i < pl + 1; i++) {
      next[i] = 0;
    }

    for (int i = 1; i < pl; i++) {
      int j = next[i];

      while (j > 0 && pattern[j] != pattern[i]) {
        j = next[j];
      }

      if (j > 0 || pattern[j] == pattern[i]) {
        next[i+1] = j + 1;
      }
    }

    for (int i = 0, j = 0; i < strl; i++) {
      if (*(str + i) == *(pattern + j)) {
        if (++j == pl) {
          match = 1;
          break;
        }
      } else if (j > 0) {
        j = next[j];
        i--;
      }
    }
  }

  return match;
}