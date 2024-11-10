AM_CFLAGS = -O0 -g

bin_PROGRAMS=rhasher

rhasher_SOURCES=rhasher.c

TESTS=md5.sh sha1.sh

md5.sh:
	echo 'Md5 rhasher.c' | ./rhasher | cut -d ' ' -f 2 > md5.out
	md5sum rhasher.c | cut -d ' ' -f 1 > md5.true 
	echo 'test "`cat md5.out`" = "`cat md5.true`"' > $@
	chmod +x $@

sha1.sh:
	echo 'Sha1 rhasher.c' | ./rhasher | cut -d ' ' -f 2 > sha1.out
	sha1sum rhasher.c | cut -d ' ' -f 1 > sha1.true 
	echo 'test "`cat sha1.out`" = "`cat sha1.true`"' > $@
	chmod +x $@

gitclean:
	git clean -df