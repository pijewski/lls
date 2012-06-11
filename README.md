lls: lightweight ls(1) replacement


## Usage

	# lls [-n <num>] [-o <offset>]


## Overview

This lightweight tool lists files in a directory without all the bells and
whistles of the standard ls(1) command.  It will not sort, colorize, filter,
print timestamps, show permissions, or even indicate whether a dirent is a
normal file or a directory.  However, it will print the files in a given
directory quickly.  Moreover, since it eschews all of that functionality for
performance, it will not consume gigabytes of memory while listing very large
directories (millions of files). 

You can think of this tool as a very thin wrapper over the standard
opendir(3C)/readdir(3C)/closedir(3C) interface.  As with that interface, the
contents of the directory may change while listing files, and if that happens,
the behavior is undefined.

The output can be paginated with the num and offset arguments.  However, as with
all directory streams accessed through readdir(3C), the relative order of
dirents in the stream will not change in subsequent invocations.


## License

MIT.
