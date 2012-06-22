#
# Copyright (c) 2012, Bill Pijewski. All rights reserved.
#
PREFIX?=/opt/local

all:
	gcc -o lls lls.c

clean:
	rm -f lls

check:
	cstyle lls.c

install:
	cp -f lls $(PREFIX)/bin/lls

uninstall:
	rm -f $(PREFIX)/bin/lls