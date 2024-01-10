#include "s21_catopt.h"

#include <stdlib.h>
#include <stdio.h>

OptList* parseCli(int inArgc, char** inArgv, OptList* optList, int* errCode) {
  optList = allocateOptList();
  int optcount = 0;

  if (inArgc != 1) {
    for (int c = 1; c < inArgc; c++) {
      if (inArgv[c][0] == '-' && inArgv[c][1] != '\0') {
        optcount++;
      } else {
        optList->pathList->count++;
      }
    }
  }
/*
  if (optList->pathList->count == 0) {
    optList->pathList->count++;
  }
*/
  printf("opt count %d\n", optcount);
  printf("file count %d\n", optList->pathList->count);

  return optList;
}

/*
  while (count < inArgc && !errCode) {
    if (inArgv[count][0] == '-') {
      if (inArgv[count][1] == '\0') {
        ++outPathList->count;
        //addPath(inArgv[count], outPathList->count, outPathList);
      } else {
        *outOptc+=1;
      }
    } else {
      ++outPathList->count;
      //addPath(inArgv[count], outPathList->count, outPathList);
    }
    ++count;
  }
  if (outPathList->count == 0) {
    outPathList->count++;
    //addPath("-", outPathList->count, outPathList);
  }*/

OptList* allocateOptList() {
  OptList* opt = malloc(sizeof(OptList));
  opt->pathList = allocatePaths();
  if (opt) {
    opt->pathList->count = 0;
    opt->pathList->path = NULL;
  }
  return opt;
}

void deallocOptList(OptList* inOptList) {
    if (!(inOptList->pathList)) deallocPaths(inOptList->pathList);
    free(inOptList);
}