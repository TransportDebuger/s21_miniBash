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
  OptList opt = {.caseinsensitive = 0,
                 .invertcondition = 0,
                 .printonlyparts = 0,
                 .regexfile = 0,
                 .showlinecount = 0,
                 .showlinenumber = 0,
                 .showonlystrings = 0,
                 .showsamefiles = 0,
                 .suppreswarnings = 0};
  char* patterns = NULL;
  list* filelist = NULL;

  if (argc == 1) {
    printErrorMsg("", USAGE_MSG, "");
  } else {
    getOptions(argc, argv, &opt, &patterns);
    if (patterns) {
      int c = argc - 1;
      while (c >= 1 && argv[c][0] != '-') {
        if (strcmp(argv[c - 1], "-e") != 0 && strcmp(argv[c - 1], "-f") != 0 &&
            strcmp(argv[c - 1], "--regexp") != 0 &&
            strcmp(argv[c - 1], "--file") != 0) {
            getFiles(&filelist, argv[c]);
        }
        c--;
      }
    } else {
      int c = argc - 1;
      while (c >= 1 && argv[c][0] != '-') {
        if (argv[c - 1][0] != '-' && c > 1) {
          getFiles(&filelist, argv[c]);
        } else {
          getPattern(&patterns, argv[c]);
        }
        c--;
      }
    }
    
    if (filelist) {
      for (int c = filelist->count - 1; c >= 0; c--) {
        fileprocessing(filelist->pStr[c], patterns, &opt, filelist->count);
      }
    } else {
      fileprocessing(NULL, patterns, &opt, filelist->count);
    }

    if (filelist) {
      for (int c = 0; c < filelist->count; c++) {
        if (filelist->pStr[c]) free(filelist->pStr[c]);
      }
      free(filelist);
    }
    if (patterns) {
      free(patterns);
    }
  }

  return errCode;
}