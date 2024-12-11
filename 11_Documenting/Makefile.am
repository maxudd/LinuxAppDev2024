@DX_RULES@
doxygen-doc/man/man1/num_guess.c.1:	doxygen-doc

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

man1_MANS = doxygen-doc/man/man1/num_guess.c.1
bin_PROGRAMS=num_guess

all:	doxygen-doc

http:	doxygen-doc
	python3 -m http.server --directory $</html
