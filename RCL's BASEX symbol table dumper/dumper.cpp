/**************************************************************

			BASEX Symbol Table Dumper


	  Copyright (c) 2026 RCL9. All Rights Reserved.

		     By RCL9 - April 2 2026

		(Rob's Retro Computing Archive)
		RetroComputingArchive@gmail.com
			github.com/rcl9

	Written to be compiled with Microsoft Visual Studio.

***************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define	TRUE	1
#define	FALSE	0

// -------------------------------------------------------------------------------------------

	int
main (int argc, char *argv[])
{
	FILE	*inf, *outf;

	if ( argc < 2 ) {
		fprintf (stderr, "Usage: %s [-h = 'sort by hex digits'] symbol_file.txt\n", argv[0] );
		exit (1);
	}

	char in_filename[4096];

	bool sort_by_hex_digits = FALSE;

	/* Pick up any command line options */
	int fnum = 0;
	if (argc >= 1) {
		while (argc > 1) {
			char *str = argv[1];

			if (str[0] == '-') {
				_strlwr(++str);

				if ( *str == 'h') {
					sort_by_hex_digits = TRUE;
					++str;
				}
			} else if (str && strlen(str)) {
				// Pick up the two filenames
				if ( !strlen(in_filename) )
					strcpy( in_filename, str );
			}

			argv++;
			argc--;
		}
	}

	if ( !strlen(in_filename) ) {
		fprintf (stderr, "The input symbol table filename needs to be provided.\n");
		exit (2);
	}

	// Read the file into memory
	inf = fopen ( in_filename, "r" );
	if (!inf) {
		fprintf (stderr, "Error opening the file '%s' for reading.\n", in_filename );
		exit (2);
	}
	if (fseek( inf, 0L, SEEK_END) != 0) {
		fprintf (stderr, "Error while seeking to the end of the file %s.\n", in_filename );
		exit (2);
	}
	int size = ftell( inf );
	if (size == -1L) {
		fprintf (stderr, "Error from ftell() for the file %s.\n", in_filename );
		exit (2);
	}
	if (fseek( inf, 0L, SEEK_SET) != 0) {
		fprintf (stderr, "Error from fseek( end ) for the file %s.\n", in_filename );
		exit (2);
	}

	char *ptr = (char *) malloc( size );
	int num_bytes_read = (int) fread( ptr, 1, size, inf );
	fclose(inf);

	// Parse the symbol table
	while (size > 0) {
		char sym[4096];

		while ( !*ptr ) {
			++ptr;	// Skip past any leading zeros
			--size;
		}

		if (!*ptr)
			break;

		short end_char = 0;

		// Grab the symbol name
		int offset = 0;
		do {
			end_char = *ptr;
			sym[offset++] = end_char & 0x7F;
			--size;
		} while (!(*(ptr++) & 0x80));
		sym[offset++] = 0;

		short dim =0;	// Dimension of arrays or strings

		if ( end_char == '$' + 128 ) {
			// String array
			dim = *ptr++;
			--size;

			fprintf( stderr, "%s = %d [ ", sym, dim );

			// Loop over each of the dim-strings, each zero terminated
			for (int i=0; i < dim; ++i) {
				char str[4096];

				int offset = 0;
				do {
					str[offset++] = *ptr;
					--size;
				} while (*ptr++);
				str[offset++] = 0;

				fprintf( stderr, "\"%s\" ", str);
			}

			fprintf( stderr, " ]\n");
		} else if ( end_char == '(' + 128 ) {
			// Data array
			dim = *ptr++;
			--size;

			fprintf( stderr, "%s = %d [ ", sym, dim );

			// Loop over each of the dim-values
			for (int i=0; i < dim; ++i) {

				signed short val = *ptr + (*(ptr+1) << 8);
				++ptr; ++ptr;
				--size;
				--size;

				if (val > 32767)
					val = -val;

				fprintf( stderr, "%d ", val );
			}

			fprintf( stderr, " ]\n");
		} else {
			// Grab the memory offset
			signed short addr = *ptr + (*(ptr+1) << 8);
			++ptr; ++ptr;
			--size;
			--size;

			if (addr > 32767)
				addr = -addr;

			if ( sort_by_hex_digits )
				fprintf( stderr, "0x%x (%d) = %s\n", addr, addr, sym);
			else
				fprintf( stderr, "%s = 0x%x (%d)\n", sym, addr, addr);
		}

		// Skip past the zero at the end of each symbol
		++ptr;
		--size;
	}
}

