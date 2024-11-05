.RECIPEPREFIX=:

SRC=move.c
EXE=move
CC=cc
CFLAGS=-Wall -Wextra

GENERATES=$(EXE)
TRASH=*.o *.so file* *.out

all: $(EXE) test

test-1: $(EXE)
: echo "test string" > file1
: cp file1 file1_save
: ./$(EXE) file1 file2
: ! test -f file1
: cmp file1_save file2

test-2: $(EXE)
: echo "test string" > file1
: strace -eopenat -e fault=openat:error=ENOMEM ./move file1 file2 2> $@.out || true
: grep "Cannot allocate memory" $@.out

test-3: $(EXE) protected.so
: echo "test string" > file1PROTECT
: LD_PRELOAD=`pwd`/protected.so ./$(EXE) file1PROTECT file2
: test -f file1PROTECT

test: test-1 test-2 test-3

protected.so: protected.c
: cc -shared -o $@ $<

clean:
: rm -f $(TRASH)

distclean: clean
: rm -f $(GENERATES)