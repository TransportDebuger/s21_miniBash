CC = gcc
CFLAGS = -Werror -Wextra -Wall -std=c11

all: s21_cat

rebuild:

s21_cat: s21_cat.o
	${CC} ${CFLAGS} s21_cat.o -o s21_cat

s21_cat.o:
	${CC} ${CFLAGS} -c s21_cat.c

clean:
