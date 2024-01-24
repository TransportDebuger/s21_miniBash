#include "s21_cat.h"

#include <stdio.h>
#include <stdlib.h>

#include "../common/s21_ctypedef.h"
#include "../common/s21_froutines.h"
#include "../common/s21_optproc.h"
#include "s21_catmes.h"
#include "s21_catopt.h"

int main(int argc, char** argv) {
  OptList* opt = parseOptions(argc, argv);
  int errCode = 0;
  if (opt) {
    FLIST* files;
    deallocOptList(opt);
  } else {
    errCode++;
  }
  // FILE* pfile;
  /*
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
          if ((pfile = openFile(options->pathList->path[c])) != NULL)
  printFile(pfile, options); else printf("file not found\n"); closeFile(pfile);
        }
      }
    } else
      printFile(stdin, options);
    }*/

  return errCode;  //возврат кода ошибки должен быть здесь
}