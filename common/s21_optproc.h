#ifndef S21_OPTPROC_H
#define S21_OPTPROC_H

typedef struct fileList FLIST;
struct fileList {
  int count;
  char** path;
};

FLIST* allocatePaths();
void deallocPaths(FLIST* inFileList);

/*struct options {
  char* longName;
  int haveArg;
  char shortName;
};*/

#endif