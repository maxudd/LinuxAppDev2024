bin_PROGRAMS=num_guess
tests_SOURCES=tests.c num_guess.c

@DX_RULES@

doxygen-doc/man/man1/num_guess.c.1:	doxygen-doc

man1_MANS=doxygen-doc/man/man1/num_guess.c.1

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

all:	ru/LC_MESSAGES/num_guess.mo doxygen-doc

ru.po:	num_guess.c
	xgettext -k_ -c num_guess.c -o num_guess.pot
	msgmerge -U $@ num_guess.pot

ru/LC_MESSAGES/num_guess.mo:	ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

http:	doxygen-doc
	python3 -m http.server --directory $</html 8001

test: tests
	@./tests

install:
	@echo "Installing num-guess..."
	@sudo mkdir -p /usr/local
	@sudo mkdir -p /usr/local/share/man/man1
	@sudo cp doxygen-doc/man/man1/num_guess.c.1 /usr/local/share/man/man1/num_guess.1
	@sudo cp num_guess /usr/local/bin
	@sudo cp -r ru/LC_MESSAGES /usr/local/bin/LC_MESSAGES
	@echo "Done."

uninstall:
	@echo "Uninstalling num-guess..."
	@sudo rm -rf /usr/local/bin/num_guess
	@sudo rm -rf /usr/local/share/man/man1
	@sudo rm -rf /usr/local/bin/LC_MESSAGES
	@echo "Done."	

clean:
	git clean -xdf
