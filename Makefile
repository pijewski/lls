#
# Copyright (c) 2012, Bill Pijewski. All rights reserved.
#

all:
	gcc -o lls lls.c

clean:
	rm -f lls

check:
	cstyle lls.c
