#include <stdio.h>
#include <stdlib.h>

#include "s21_cat.h"
#include "../common/s21_ctypedef.h"
#include "s21_catopt.h"
#include "s21_catmes.h"
#include "../common/s21_froutines.h"
#include "../common/s21_optproc.h"



int main(int argc, char** argv) {
  int errCode = 0; 
  OptList* options = NULL;
  FILE* pfile;
  options = parseCli(argc, argv, options, &errCode);

  if (!errCode) {
  #ifndef APPLE
    if (options->help)
      printHelp();
    else if (options->version)
     printVersion();
    else 
  #endif
    if (options->pathList->count) {
      for (int c = 0; c < options->pathList->count; c++) {
        if (options->pathList->path[c][0] == '-') printFile(stdin, options);
        else {
          if ((pfile = openFile(options->pathList->path[c])) != NULL) printFile(pfile, options);
          else printf("file not found\n");
          closeFile(pfile);
        }
      }
    } else
      printFile(stdin, options);
    }
  if (options != NULL) deallocOptList(options);
  return errCode;
}