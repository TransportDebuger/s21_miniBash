#include <string.h>

#include "s21_cat.h"
#include "../common/s21_ctypedef.h"
#include "../common/s21_errproc.h"
#include "s21_catopt.h"
#include "s21_fileproc.h"

#ifndef APPLE
  #include "s21_catmes.h"
#endif

int main(int argc, char** argv) {
  OptList* opt = parseOptions(argc, argv);
  int errCode = 0;

  if (opt) {
#ifndef APPLE
    if (opt->help == 1)
      printHelp();
    else if (opt->version == 1)
      printVersion();
    else
#endif
    {
      if (argc == 1) {
        printFile(stdin, opt);
      } else {
        short int fd = 0;
        for (int c = 1; c < argc; c++) {
          if (argv[c][0] != '-') {
            FILE* f;
            fd++;
            if ((f = fopen(argv[c], "r")) != NULL) {
              printFile(f, opt);
              fclose(f);
            } else {
              printErrorMsg(PROGNAME, WRONG_FILE, argv[c]);
            }
          } else if (strcmp("-", argv[c]) == 0 || strcmp("--", argv[c]) == 0) {
            fd++;
            printFile(stdin, opt);
          }
        }
        if (!fd) {
          printFile(stdin, opt);
        }
      }
    }
    deallocOptList(opt);
  } else {
    errCode++;
  }

  return errCode;
}