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


## Status

lls has been compiled and tested on SmartOS, a distribution of the
[illumos](http://github.com/illumos/illumos-gate) operating system.  The work to
port it to other platforms involves reconciling the various struct dirent
definitions, and while that work isn't hard, it won't work as is.


## License

MIT.
