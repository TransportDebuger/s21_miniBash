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
    if (!patterns) {
      int c = 1;
      while (c < argc) {
        if (argv[c][0] != '-' && !patterns)
          getPattern(&patterns, argv[c]);
        else if (argv[c][0] != '-')
          getFiles(&filelist, argv[c]);
        c++;
      }
    } else {
      int c = 1;
      while (c < argc) {
        if (argv[c][0] != '-') {
          int s = strlen(argv[c - 1]);
          if (argv[c - 1][0] == '-' &&
              (argv[c - 1][0] == 'e' || argv[c - 1][0] == 'f') &&
              strlen(argv[c - 1]) > 2)
            getFiles(&filelist, argv[c]);
          else if (argv[c - 1][0] == '-' && argv[c - 1][s - 1] != 'e' &&
                   argv[c - 1][s - 1] != 'f')
            getFiles(&filelist, argv[c]);
          else if (argv[c - 1][0] != '-')
            getFiles(&filelist, argv[c]);
        }
        c++;
      }
    }

    if (filelist) {
      for (int c = 0; c < filelist->count; c++) {
        fileprocessing(filelist->pStr[c], patterns, &opt, filelist->count);
      }
    } else {
      fileprocessing(NULL, patterns, &opt, filelist->count);
    }

    if (filelist) {
      for (int c = 0; c < filelist->count; c++) {
        if (filelist->pStr[c]) free(filelist->pStr[c]);
      }
      free(filelist->pStr);
      free(filelist);
    }
    if (patterns) {
      free(patterns);
    }
  }

  return errCode;
}