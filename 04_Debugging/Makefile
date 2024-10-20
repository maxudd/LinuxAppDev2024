.RECIPEPREFIX=:

SRC = range.c
EXE = range
CC = cc
CFLAGS = -O0 -g

GENERATES = $(EXE) *.out

all: $(EXE)

test: $(EXE)
:	gdb -q $(EXE) --command=script1.gdb | grep '@@@' > 1.out
:	gdb -q $(EXE) --command=script2.gdb | grep '@@@' > 2.out
:	cmp 1.test 1.out
:	cmp 2.test 2.out

clean:
: rm -f $(GENERATES)