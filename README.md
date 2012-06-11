lls: lightweight ls(1) replacement


## Usage

	# lls [-n <num>] [-o <offset>]


## Overview

This lightweight tool lists files in a directory without all the bells and
whistles of the usual ls(1) command.  It will not sort, colorize, filter, print
timestamps, show permissions, or even indicate whether a dirent is a normal file
or a directory.  However, it will print the dirents in a given directory
quickly.  Since it eschews most functionality for performance, it will not
consume gigabytes of memory while listing very large directories (millions of
files). 

You can think of this tool as a very thin wrapper over the standard
opendir(3C)/readdir(3C)/closedir(3C) interface.  As with that interface, the
contents of the directory may change while listing files, and if that happens,
the behavior is undefined.

The output can be paginated with the num and offset arguments.  YMMV with said
pagination if the contents of the directory are changing. However, as with all
directory streams accessed through readdir(3C), the order of dirents in the
stream will not change in subsequent invocations as long as the contents of the
directory are the same.


## Performance

	# time /usr/bin/amd64/ls -1 | wc -l  
	 32783927
	
	real	11m27.115s
	user	10m3.117s
	sys	1m20.608s
	# time /usr/bin/amd64/ls -U1 | wc -l  
	 32783927
	
	real	2m24.796s
	user	0m58.586s
	sys	1m21.492s
	# time lls | wc -l  
	 32783927
	
	real	0m15.833s
	user	0m5.750s
	sys	0m13.713s

During the above tests, ls(1) consumed over 20 GB of memory at its highest.  lls
was steady with about 1.5 KB of memory used.


## Status

lls has been compiled and tested on SmartOS, a distribution of the
[illumos](http://github.com/illumos/illumos-gate) operating system.  The work to
port it to other platforms involves reconciling the various struct dirent
definitions, and while that work isn't hard, it won't work as is.


## License

MIT.
