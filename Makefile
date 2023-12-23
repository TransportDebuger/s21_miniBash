CC = gcc
FLAGS = -Werror -Wextra -Wall -std=c11
TCAT = 
TGREP = 

s21_cat: common.o

s21_grep: common.o
	$(CC) $(FLAGS) common.o -o $(BUILD_PATH)$(TARGET1)

common.o:
	${CC} $(FLAGS) -c ./common/common.c

cipher: cipher.o
	$(CC) $(FLAGS) cipher.o -o $(BUILD_PATH)$(TARGET1)

cipher.o:
	$(CC) $(FLAGS) -c cipher.c

clean:
	rm -rf *.o
	rm -rf ../build/cipher