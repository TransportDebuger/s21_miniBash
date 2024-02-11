CC = gcc 
CFLAGS = -Werror -Wextra -Wall -std=c11
VPATH :=.:../common
NAME = s21_cat
OBJ = s21_cat.o s21_catopt.o s21_catmes.o s21_fileproc.o s21_errproc.o
OS = $(shell uname)

ifeq ($(OS), Apple) 
	DFLAG = -D APPLE 
endif

.PHONY: all

all: s21_cat

.PHONY: rebuld

rebuild: clean all

s21_cat: ${OBJ}
	${CC} ${CFLAGS} $(OBJ) -o ${NAME}

s21_cat.o: s21_cat.c
	${CC} ${CFLAGS} -c s21_cat.c

s21_catopt.o: s21_catopt.c
	${CC} ${CFLAGS} $(DFLAG) -c s21_catopt.c

s21_catmes.o: s21_catmes.c
	${CC} ${CFLAGS} -c s21_catmes.c

s21_fileproc.o: s21_errproc.c
	${CC} ${CFLAGS} -c s21_fileproc.c

s21_errproc.o: ../common/s21_errproc.c
	${CC} ${CFLAGS} -c ../common/s21_errproc.c

.PHONY: clean

clean: 
	rm -rf *.o
