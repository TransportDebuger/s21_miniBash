CC = gcc 
CFLAGS = -Werror -Wextra -Wall
VPATH :=.:../common
NAME = s21_cat
OBJ = s21_cat.o s21_catopt.o s21_catmes.o s21_fileproc.o s21_errproc.o
OS = $(shell uname)
DFLAG = 
TEST = ./test_func_cat.sh

ifeq ($(OS), Apple) 
	DFLAG = -D APPLE 
else ifeq ($(OS), Darwin)
	DFLAG = -D APPLE 
endif

.PHONY: all

all: s21_cat
	echo ${OS}

.PHONY: rebuld

rebuild: clean all

s21_cat: ${OBJ}
	${CC} ${CFLAGS} ${DFLAG} $(OBJ) -o ${NAME}

s21_cat.o: s21_cat.c
	${CC} ${CFLAGS} ${DFLAG} -c s21_cat.c

s21_catopt.o: s21_catopt.c
	${CC} ${CFLAGS} $(DFLAG) -c s21_catopt.c

s21_catmes.o: s21_catmes.c
	${CC} ${CFLAGS} ${DFLAG} -c s21_catmes.c

s21_fileproc.o: s21_fileproc.c
	${CC} ${CFLAGS} ${DFLAG} -c s21_fileproc.c

s21_errproc.o: ../common/s21_errproc.c
	${CC} ${CFLAGS} -c ../common/s21_errproc.c

.PHONY: test

test: all
	${TEST}

.PHONY: clean

clean: 
	rm -rf *.o
