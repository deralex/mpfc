/******************************************************************
 * Copyright (C) 2003 by SG Software.
 ******************************************************************/

/* FILE NAME   : util.h
 * PURPOSE     : SG Konsamp. Interface for different utility
 *               functions.
 * PROGRAMMER  : Sergey Galanov
 * LAST UPDATE : 27.07.2003
 * NOTE        : Module prefix 'util'.
 *
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License 
 * as published by the Free Software Foundation; either version 2 
 * of the License, or (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public 
 * License along with this program; if not, write to the Free 
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, 
 * MA 02111-1307, USA.
 */

#ifndef __SG_KONSAMP_UTIL_H__
#define __SG_KONSAMP_UTIL_H__

#include <stdio.h>
#include "types.h"

/* Write message to log file */
void util_log( char *format, ... );

/* Search for a substring */
bool util_search_str( char *ptext, char *text );

/* Get file extension */
char *util_get_ext( char *name );

/* Delay */
void util_delay( long s, long ns );

/* Get file name without full path */
char *util_get_file_short_name( char *name );

/* Convert file name to the one with escaped special symbols */
char *util_escape_fname( char *out, char *in );

/* Get short plugin name */
char *util_get_plugin_short_name( char *dest, char *src );

/* Open a file expanding home directories */
FILE *util_fopen( char *filename, char *flags );

/****** Buffered file input management ******/

/* Buffer type */
typedef struct tag_util_buf_t
{
	/* File descriptor */
	FILE *m_fd;

	/* Buffer */
	byte *m_buf;
	int m_size;

	/* Real buffer size */
	int m_real_size;

	/* Buffer position */
	int m_pos;

	/* Offset of the buffer start */
	int m_offset;

	/* File size */
	int m_file_size;
} util_buf_t;

/* Open file for buffered input */
util_buf_t *util_buf_open( char *filename, int buf_size );

/* Close file */
void util_buf_close( util_buf_t *buf );

/* Buffered read */
int util_buf_read( void *ptr, int size, util_buf_t *buf );

/* Seek file opened for buffered input */
void util_buf_seek( util_buf_t *buf, int offset, int whence );

/* Tell file position */
int util_buf_tell( util_buf_t *buf );

#endif

/* End of 'util.h' file */

