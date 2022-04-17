USERID GCCCMS
/*  rpilot.h - universal macros and the like. */

#ifndef _rpilot_h_
#define _rpilot_h_

#define MAXLINE 256         /* Max length of a source line */

/* Status indicators */
#define       STAT_RUN      1
#define       STAT_HALT     2
#define       STAT_END      3


/* Used to check conditional values */ 
#define        FALSE        0
#define        TRUE         1

/* What string is displayed for an accept command? */
#define        ACCEPT_STR   ">"


/* Remove a terminating newline */
#define chop( str )   if(str[strlen(str)-1] == '\n') str[strlen(str)-1] = '\0'

/*
Initialize randon number based on time
#define srandom() srand( (unsigned)time(NULL) );
*/

/* The version number, of course */
#define         VERSION      "1.4"

/* exported functions */
int get_nv( char *str );
void set_var( char *name, char *val );
int run( char *filename );
void jump( char *str );
void use( char *str );
void execute( char *str );
char *get_stvl( char *str );
void init(); 
int readfile( char *filename );
int express( char *form );
int interp();


#endif
