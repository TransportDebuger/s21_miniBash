CC = gcc 
CFLAGS = -Werror -Wextra -Wall
VPATH :=.:../common
NAME = s21_grep
OBJ = s21_grep.o s21_grepopt.o s21_fileproc.o s21_errproc.o
TEST = ./test_func_grep.sh

.PHONY: all

all: s21_grep

.PHONY: rebuld

rebuild: clean all

s21_grep: ${OBJ}
	${CC} ${CFLAGS} $(OBJ) -o ${NAME}

s21_cat.o: s21_grep.c
	${CC} ${CFLAGS} ${DFLAG} -c s21_grep.c

s21_catopt.o: s21_grepopt.c
	${CC} ${CFLAGS} $(DFLAG) -c s21_grepopt.c

s21_fileproc.o: s21_fileproc.c
	${CC} ${CFLAGS} ${DFLAG} -c s21_fileproc.c

s21_errproc.o: ../common/s21_errproc.c
	${CC} ${CFLAGS} -c ../common/s21_errproc.c

.PHONY: test

test: all
	$(TEST)

.PHONY: clean

clean: 
	rm -rf *.o