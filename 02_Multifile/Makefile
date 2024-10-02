.RECIPEPREFIX=:
GENERATES = prog prog-a prog-so README *.a *.so
TRASH = *.o *~ o.* test*
CFLAGS = -Wall -fPIC

all:    README prog prog-a prog-so test

.SECONDARY:	fun.o const.o
.INTERMEDIATE:	liboutput_static.a(fun.o const.o)

liboutput_static.a:	liboutput_static.a(fun.o const.o)

liboutput.so:	fun.o const.o
:	cc -shared -o $@ $^

prog:	prog.o fun.o const.o

prog-a:	prog.o liboutput_static.a
:	cc $< -L. -loutput_static -o $@

prog-so:	prog.o liboutput.so
:	cc $< -L. -loutput -o $@


test: test0 test1 test2

test0: prog prog-a prog-so
:  ./prog 2> $@
:  ./prog-a 2> $@-a
:  LD_LIBRARY_PATH=`pwd` ./prog-so 2> $@-so
:  sed -rsi 's/prog(-a|-so)?//g' $@ $@-a $@-so
:  cmp $@ $@-a
:  cmp $@ $@-so
:  cmp $@-a $@-so

test1: prog prog-a prog-so
:  ./prog a > $@
:  ./prog a > $@-a
:  LD_LIBRARY_PATH=`pwd` ./prog a > $@-so
:  cmp $@ $@-a
:  cmp $@ $@-so
:  cmp $@-a $@-so

test2: prog prog-a prog-so
:  ./prog a b > $@
:  ./prog a b > $@-a
:  LD_LIBRARY_PATH=`pwd` ./prog a b > $@-so
:  cmp $@ $@-a
:  cmp $@ $@-so
:  cmp $@-a $@-so


README: prog
:	./$< 2> $@

fun.o prog.o:  outlib.h

clean:
:	rm -f $(TRASH)

distclean:      clean
:	rm -rf $(GENERATES)
