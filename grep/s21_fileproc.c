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

void fileprocessing(char* filename, char* patterns, const OptList* opt, int filecount) {
  FILE* f;
  int strcount = 0, matchcount = 0;

  if (!filename) {
    f = stdin;
  } else {
    f = fopen(filename, "r");
    if (!f && !(opt->suppreswarnings)) {
      printErrorMsg(PROGNAME, WRONG_FILE, filename);
    }
  }

  if (f) {
    while (feof(f) == 0) {
      char* str = NULL;
      size_t memlen = 0;
      getline(&str, &memlen, f);
      strcount++;
      int match = 0;
      int m;
      
      if (opt->caseinsensitive)
        m = ismatch(str, patterns, 1);
      else
        m = ismatch(str, patterns, 0);

      if (m == 0 && !(opt->invertcondition)) {
        match = 1;
        matchcount++;
      } else if (m == 1 && opt->invertcondition) {
        match = 1;
        matchcount++;
      }

      if (match && !(opt->showsamefiles) && !(opt->showlinecount)) {
        if (filename && filecount > 1 && !(opt->showonlystrings))
          printf("%s:", filename);
        else if (!(filename) && filecount > 1 && !(opt->showonlystrings))
          printf("(standard input):");
        if (opt->showlinenumber) printf("%d:", strcount);
          fputs(str, stdout);
      }
      free(str);
    }

    if (matchcount && opt->showsamefiles)
      printf("%s\n", filename);
    else if (matchcount && opt->showlinecount) {
      if (filecount > 1)
        printf("%s:%d\n", filename, matchcount);
      else {
        printf("%d\n", matchcount);
      }
    }
    
    fclose(f);
  }
}

int ismatch(char* str, char* pattern, int caseinsensitive) {
  int retval = 0;
  regex_t re;
  int flag = REG_EXTENDED;

  if (caseinsensitive) flag = (flag | REG_ICASE);
  
  if ((retval = regcomp(&re, pattern, flag)) == 0)
      retval = regexec(&re, str, 0, NULL, 0);

  regfree(&re);
  return retval;
}

/*v9888888888888888888888888888888888888899999999999\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\oid putSubstr(char* str, char* pattern, int caseinsensitive) {
#define BUFSIZE 256
  regex_t re;
  regmatch_t pmatch[100];
  // char    buf[BUFSIZE];
  int flag = REG_EXTENDED;

  if (caseinsensitive) flag = (flag | REG_ICASE);

  // int     retval;
  int status;
  char* ps;

  // int      eflag;

  if ((status = regcomp(&re, pattern, flag)) == 0) {
    ps = str;

    while ((status = regexec(&re, ps, 1, pmatch, 0)) == 0) {
      printf("найдено соответствие в позиции %d, строка: %s\n", pmatch[0].rm_so,
             ps + pmatch[0].rm_so);
      ps += pmatch[0].rm_eo;
      printf("\nследующая строка для сравнения: %s\n", ps);
      // eflag = REG_NOTBOL;
    }
    regfree(&re);
  }
}*/