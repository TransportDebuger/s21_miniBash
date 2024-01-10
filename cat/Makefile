CC = gcc
CFLAGS = -Werror -Wextra -Wall -std=c11

all: s21_cat

rebuild:

s21_cat: s21_cat.o s21_catopt.o s21_catmes.o
	${CC} ${CFLAGS} s21_cat.o -o s21_cat

s21_cat.o:
	${CC} ${CFLAGS} -c s21_cat.c

s21_catopt.o:
	${CC} ${CFLAGS} -c s21_catopt.c

s21_catmes.o:
	${CC} ${CFLAGS} -c s21_catmes.c


clean:
