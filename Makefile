CC = gcc
CFLAGS = -Werror -Wextra -Wall -std=c11
COMMON_SRC = common\
COMMON_OBJ = common\obj\
CAT_SRC = .\cat\
CAT_OBJ = .\cat\obj\
CAT_TARGET = .\cat\
GREP_SRC = .\grep\
GREP_OBJ = .\grep\obj\
GREP_TARGET = .\grep\


all: s21_cat s21_grep

debug: s21_cat_debug s21_grep_debug

s21_cat: common

s21_cat_debug:

s21_grep: common

s21_grep_debug:

common: common_obj_dir
	${CC} $(CFLAGS) -c $(COMMON_SRC)common.c=$(COMMON_OBJ)common.o

common_debug:
	$(CC) $(CFLAGS) -DDEBUG -c $(COMMON_SRC)common.c=$(COMMON_OBJ)common.o

common_obj_dir:
	mkdir -p $(COMMON_OBJ)

clean:
	rm -rf *.o
	rm -rf ../build/cipher