#include "s21_grep.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/s21_ctypedef.h"
#include "../common/s21_errproc.h"
#include "s21_fileproc.h"
#include "s21_grepopt.h"

int main(int argc, char** argv) {
  int errCode = 0;
  OptList opt = {.filelist = NULL,
                 .pattern = NULL,
                 .caseinsensitive = 0,
                 .invertcondition = 0,
                 .printonlyparts = 0,
                 .regexfile = 0,
                 .showlinecount = 0,
                 .showlinenumber = 0,
                 .showonlystrings = 0,
                 .showsamefiles = 0,
                 .suppreswarnings = 0};

  if (argc == 1) {
    printErrorMsg("", USAGE_MSG, "");
  } else {
    getOptions(argc, argv, &opt);
    printf("%s\n", opt.pattern);
    /*if (opt.pattern) {
      int c = argc - 1;
      while (c >= 1 && argv[c][0] != '-') {
        if (strcmp(argv[c - 1], "-e") != 0 && strcmp(argv[c - 1], "-f") != 0 &&
            strcmp(argv[c - 1], "--regexp") != 0 &&
            strcmp(argv[c - 1], "--file") != 0) {
          opt.filelist = getFiles(opt.filelist, argv[c]);
        }
        c--;
      }
    } else {
      int c = argc - 1;
      while (c >= 1 && argv[c][0] != '-') {
        if (argv[c - 1][0] != '-' && c > 1) {
          opt.filelist = getFiles(opt.filelist, argv[c]);
        } else {
          opt.pattern = getPattern(opt.pattern, argv[c]);
        }
        c--;
      }
    }*/

    /*if (opt.filelist) {
      for (int c = opt.filelist->count - 1; c >= 0; c--) {
        printf("enter fproc %d\n", c);
        fileprocessing(opt.filelist->pStr[c], &opt);
      }
    } else {
      fileprocessing(NULL, &opt);
    }*/

    /*if (opt.pattern) {
      for (int c = 0; c < opt.pattern->count; c++) {
        if (opt.pattern->pStr[c]) free(opt.pattern->pStr[c]);
      }
      if (opt.pattern->pStr) free(opt.pattern->pStr);
      free(opt.pattern);
    }
    if (opt.filelist) {
      for (int c = 0; c < opt.filelist->count; c++) {
        if (opt.filelist->pStr[c]) free(opt.filelist->pStr[c]);
      }
      if (opt.filelist->pStr) free(opt.filelist->pStr);
      free(opt.filelist);
    }*/
  }

  return errCode;
}