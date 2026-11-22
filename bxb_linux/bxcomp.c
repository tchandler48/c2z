/* bxbasic: Bxcomp.c : alpha version.13 */

#define Linux  
/* #define Windows */

/* --- declare headers --- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#ifdef Windows
    #include <io.h>    
#endif


/* --- declare constants --- */
#define BUFSIZE     256
#define PATH        129
#define TOKEN_LEN   21
#define LLEN        33
#define VAR_NAME    33


/* ------ global vars ------------ */
    FILE *f_in, *f_out;      /* these are the i/o file handles    */
    char *prog_name;         /* program source-file name          */
    char p_string[BUFSIZE];  /* file input string                 */
    char **array1;           /* program array                     */
    char t_holder[20];       /* token data holder                 */
    char s_holder[BUFSIZE];  /* xstring (print) data holder       */
     int nrows;              /* numbers of lines in source file   */
     int ncolumns=BUFSIZE;   /* dimension for array1[][columns]   */
     int line_ndx;           /* current execution line            */
     int s_pos, e_pos;       /* pointers to start & end of token  */
/**/
    char xstring[BUFSIZE];   /* the print string                  */
    char **temp_prog;        /* temp program array                */
    char **temp_label;       /* temp label name array             */
     int *temp_byte;         /* temp byte code array              */
     int *byte_array;        /* byte code array                   */
    char **label_nam;        /* labels name array                 */
     int token;              /* token: current byte code          */
    long offset;             /* offset:engine file length         */
/**/


/* ----- function prototypes ----- */
    void write_src(void);
    void merge_source(void);
 
#include "prototyp.h"

/* --- function includes --- */
#include "input.c"
#include "error.c"


/* ----- begin program ------------- */

int main(int argc, char *argv[])
{   int ab_code=1, x=0;

    printf("Bxbasic Compiler\n");
    if(argc != 2)
    {    a_bort(ab_code,x);
    }
    strcpy(t_holder, argv[1]);
    line_cnt(argv);
    merge_source();

    /* --- end of program --- */
    clr_arrays();
    return 0;
}
/*-------------------------------*/

void merge_source()
{   char ch, dot='.', *destin, source[20];
    int ii, data, ab_code=3, x=0;
    unsigned size=PATH;

    destin = malloc(size * sizeof(char));
    strcpy(destin, s_holder);           /* copy source file name */
    ii = 0;
    ch = '\0';
    while(ch != dot)
    {   ch = s_holder[ii];          /* make source.bas = source. */
        ii++;
    }
    destin[ii] = '\0';
    strcat(destin, "exe");            /* append "exe" to filename */

/* --- open destination file (write-binary) --- */
    f_out = fopen(destin,"wb");
    printf("Destination file: %s\n",destin);

/* --- read-in scripting engine (read-binary) --- */
    strcpy(source, "engine.exe");
    f_in = fopen(source, "rb");
    if(f_in == NULL)
    {   a_bort(ab_code,x);
    }
    printf("Source file: %s\n",source);

/* --- get engine file-length offset --- */
    offset = filelength(fileno(f_in));
    printf("Offset=%ld\n", offset);
    while(! feof(f_in))
    {   data = fgetc(f_in);             /* data = incoming stream */
        if(! feof(f_in))
        {   fputc(data, f_out);      /* write to destination file */
        }
    }
    fclose(f_in);                          /* done copying engine */

/* --- store byte code --- */
    printf("Source file:%s\n",s_holder);
    write_src();
    fclose(f_out);

    printf("Program lines=%d\nDone!\n",nrows);
    free(destin);
}
/*------ end merge_source -------*/

void write_src()
{   char *tmp="source.tmp";
    int ii;

/* --- store nrows --- */
    fprintf(f_out,"%d\n", nrows);          /* write nrows */

/* --- write byte code --- */
    for(ii=0; ii < nrows; ii++)
    {   fprintf(f_out,"%s\n", label_nam[ii]);  /* write block label */
    }
    for(ii=0; ii < nrows; ii++)
    {   fprintf(f_out,"%d\n", byte_array[ii]);  /* write byte_code */
    }
    for(ii=0; ii < nrows; ii++)
    {   fprintf(f_out,"%s", array1[ii]);       /* write statement */
    }

/* --- write offset --- */
    fprintf(f_out,"%ld\n", offset);          /* write nrows */
}
/*-------------------------------*/
