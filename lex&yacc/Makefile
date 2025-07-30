# %W% %G%

# make and run all the example programs for
# lex & yacc, Second Edition
CFLAGES=-Wall -g
CC = gcc-13
LIBS = -ly -ll
LEX = flex
YACC = bison -y
CFLAGS = -DYYDEBUG=1

ch1-06.pgm: ch1-06l.o ch1-06y.o
	${CC} -o ch1-06.pgm ch1-06l.o ch1-06y.o ${LIBS}

ch1-06l.c:	ch1-06.l
	${LEX} ch1-06.l
	mv lex.yy.c ch1-06l.c

ch1-06l.o:	ch1-06l.c ch1-06y.h

ch1-06y.h ch1-06y.c:	ch1-06.y
	${YACC} -d ch1-06.y
	mv y.tab.c ch1-06y.c
	mv y.tab.h ch1-06y.h

clean:
	- rm -rf *.o *.pgm *l.c *y.c *.tab.c *.tab.h *y.h
	- rm -rf ch1-02 ch1-04 