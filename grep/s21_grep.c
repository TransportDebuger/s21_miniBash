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

  if (argc == 1) {
    printErrorMsg("", USAGE_MSG, "");
  } else {
    getOptions(argc, argv, &opt);
    if (opt.patternlist) {
      int c = argc - 1;
      while (c >= 1 && argv[c][0] != '-') {
        if (strcmp(argv[c-1], "-e") != 0 && strcmp(argv[c-1], "-f") != 0 && strcmp(argv[c-1], "--regexp") != 0 && strcmp(argv[c-1], "--file") != 0) {
          opt.filelist = getFiles(opt.filelist, argv[c]);
        }
        c--;
      }
    } else {
      int c = argc - 1;
      while (c >= 1 && argv[c][0] != '-') {
        if (argv[c-1][0] != '-' && c > 1) {
          opt.filelist = getFiles(opt.filelist, argv[c]);
        } else {
          opt.patternlist = getPattern(opt.patternlist, argv[c]);
        }
        c--;
      }
    }
    //debug printing. delete after finish coding
    for (int c = 0; c < opt.patternlist->count; c++) {
        printf("%p %s\n", opt.patternlist->fname[c], opt.patternlist->fname[c]);
    }

    if (opt.filelist) {
      for (int c = 0; c < opt.filelist->count; c++) {
        printf("%s\n", opt.filelist->fname[c]);
      }
    }
    //delete block higher after debug finish
    if (opt.filelist) {
      for (int c = opt.filelist->count-1; c >= 0; c--) {
        fileprocessing(opt.filelist->fname[c], &opt);
      }
    } else {
      fileprocessing(NULL, &opt);
    }

    if (opt.patternlist) {
      for (int c = 0; c < opt.patternlist->count; c++) {
        if (opt.patternlist->fname[c]) free(opt.patternlist->fname[c]);
      }
      if (opt.patternlist->fname) free(opt.patternlist->fname);
      free(opt.patternlist);
    }
    if (opt.filelist) {for (int c = 0; c < opt.filelist->count; c++) {
        if (opt.filelist->fname[c]) free(opt.filelist->fname[c]);
      }
      if (opt.filelist->fname) free(opt.filelist->fname);
      free(opt.filelist);}
  }

  return errCode;
}