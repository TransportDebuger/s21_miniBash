#include <stdio.h>
#include <stdlib.h>

#include "s21_catopt.h"
#include "s21_catmes.h"
#include "../common/s21_optproc.h"
#include "../common/s21_froutines.h"


void printHelp();
void printVersion();

int main(int argc, char** argv) {
  int errCode = 0;
  OptList* options = NULL;
  options = parseCli(argc, argv, options, &errCode);
  
  if (options->help) printHelp();
  else if (options->version) printVersion();
  else if (options->pathList->count) {
    // --> Обработка чтения списка файлов
  } else printFile(stdin);
  
  if (options != NULL) deallocOptList(options);
  return errCode;
}