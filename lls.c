/*
 * Copyright (c) 2012, Bill Pijewski. All rights reserved.
 *
 * lls.c: lightweight ls(1) replacement
 *
 * This simple tool lists files in a directory without all the bells and
 * whistles of ls(1).
 */

#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int
list_directory(const char *dir,
    unsigned long long offset, unsigned long long nfiles)
{
	DIR *dirp;
	dirent_t *dp;
	unsigned long long index = 0, nprinted = 0;

	if ((dirp = opendir(dir)) == NULL) {
		fprintf(stderr, "failed to list '%s': %s\n",
		    dir, strerror(errno));
		return (-1);
	}

	while (index < offset) {
		if ((dp = readdir(dirp)) == NULL) {
			/*
			 * In this case, the offset specified must be more than
			 * the number of files in the directory, so do nothing.
			 */
			goto out;
		}

		/* Skip over dirents for '.' and '..' */
		if (dp->d_off == 1 || dp->d_off == 2)
			continue;

		index++;
	}

	while ((dp = readdir(dirp)) != NULL) {
		/* Skip over dirents for '.' and '..' */
		if (dp->d_off == 1 || dp->d_off == 2)
			continue;

		printf("%s\n", dp->d_name);

		if (nfiles > 0 && ++nprinted == nfiles)
			break;
	}

out:
	(void) closedir(dirp);
	return (0);
}

int
main(int argc, char *argv[])
{
	extern int optind, optopt;
	extern char *optarg;
	char c;

	unsigned long long offset = 0, nfiles = 0;
	int ii, rv;

	errno = 0;

	while ((c = getopt(argc, argv, "n:o:")) != EOF) {
		switch (c) {
		case 'n':
			nfiles = atoll(optarg);
			break;
		case 'o':
			offset = atoll(optarg);
			break;
		default:
			fprintf(stderr,
			    "Unrecognized option: -%c\n", optopt);
			return (-1);
		}
	}

	if (argc == optind) {
		rv = list_directory(".", offset, nfiles);
	} else {
		for (ii = optind; ii < argc; ii++) {
			if ((rv = list_directory(argv[ii],
			    offset, nfiles)) != 0)
				break;
		}
	}

	return (rv);
}
