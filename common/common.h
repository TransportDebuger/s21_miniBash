#ifndef COMMON_H
#define COMMON_H


struct modifier{
    int position;
    char parameter;
};


struct modifier** getModifiers(int modc, char** modv);

#endif