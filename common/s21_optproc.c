#include "s21_optproc.h"

#include <stdlib.h>

FLIST* allocatePaths() {
  FLIST* paths = malloc(sizeof(FLIST));

  return paths;
}

void deallocPaths(FLIST* inFileList) {
  if (inFileList->path != NULL) {

  }
  free(inFileList);
}

//#include "s21_froutines.h"