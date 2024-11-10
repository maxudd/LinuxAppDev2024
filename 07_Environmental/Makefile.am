AM_CFLAGS = -O0 -g

bin_PROGRAMS=rhasher

rhasher_SOURCES=rhasher.c

TESTS=md5.sh

md5.sh:
	echo 'test "`./rhasher <<<'md5 "lala"' 2>&1 | head -n 1`" = "> LjgXKT/CddvudL1xzm6wVg=="' > $@
	chmod +x $@

# distclean:
# 	rm -rf .deps *.cache *.log config.* config.* configure configure~ rhasher *.o *.m4 install-sh Makefile Makefile.in missing stamp-h1 compile depcomp test-driver *.log src/.deps src/.dirstamp src/rhasher.o

gitclean:
	git clean -df