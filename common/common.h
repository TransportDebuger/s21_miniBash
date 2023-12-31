#ifndef COMMON_H
#define COMMON_H


struct settings{
    int position;
    char parameter;
};

#ifdef DEBUG
void printParameters(int inArgc, char** inArgv);
#endif

int getSettingsCount(int inArgc, char** inArgv);

struct settings** parseModifiers(int modc, char** modv);

#endif