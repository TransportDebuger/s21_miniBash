CC = gcc CFLAGS =
    -Werror - Wextra - Wall - std =
        c11 VPATH %.c./ VPATH %.c../ common / OBJ =
            s21_cat.o s21_catopt.o s21_catmes.o OS = $(shell uname)

                ifeq($(OS), Apple) DFLAG = -D __APPLE endif

                                                .PHONY : all all : s21_cat

                                                .PHONY : rebuld rebuild
    : clean all

          s21_cat : $(OBJ) ${CC} ${CFLAGS} $(OBJ) -
                                           o s21_cat

                                               s21_cat.o : ${CC} ${CFLAGS} -
                                           c s21_cat
                                               .c

                                                   s21_catopt.o
    : ${CC} ${CFLAGS} $(DFLAG) -
                                           c s21_catopt
                                               .c

                                                   s21_catmes.o
    : ${CC} ${CFLAGS} -
                                           c s21_catmes
                                               .c

                                               .PHONY : clean clean
    : rm - rf *.o
