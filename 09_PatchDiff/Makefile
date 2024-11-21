.RECIPEPREFIX=:

GENERATES=maze0 maze1 maze2 maze3 maze0.c maze1.c maze2.c maze3.c
CC=gcc
EXE=maze

maze0: 
: cp maze.c maze0.c
: $(CC) maze0.c -o maze0

maze1:
: cp maze0.c maze1.c
: patch maze1.c < 1.patch
: $(CC) maze1.c -o maze1

maze2:
: cp maze1.c maze2.c
: patch maze2.c < 2.patch
: $(CC) maze2.c -o maze2

maze3:
: cp maze2.c maze3.c
: patch maze3.c < 3.patch
: $(CC) maze3.c -o maze3

all: maze0 maze1 maze2 maze3

run: all
: ./maze0
: ./maze1 7
: ./maze2 -X 7
: ./maze3 12 -X 7

clean:
: rm -f $(GENERATES)