SUBDIRS = src tests

clean:
	git clean -xdf

gcov:	check
	$(MAKE) $(MAKEFLAGS) -C src gcov