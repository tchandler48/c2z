/* Enginput.c : alpha version */
/* ----- includes ----- */
#include "prototyp.h"


void load_bas1()
{   char ch, *tmp=s_holder;
    int ii, len, pi;
    unsigned size, buffr=10;
    long offset, f_len;           /* offset: Engine.exe file length */

/* --- open file --- */
	strcat(tmp, ".exe");
    f_in = fopen(tmp,"r");        /* source file is now: "filename.exe" */

/* --- get offset from end-of-file --- */
    f_len = filelength(fileno(f_in));
    offset = (f_len-7);
    fseek(f_in, offset, SEEK_SET);
    fgets(p_string, buffr, f_in);
    while((p_string[0] == '\n') && (offset < f_len))
    {   offset++;
        fseek(f_in, offset, SEEK_SET);
        fgets(p_string, buffr, f_in);
    }
    offset = atol(p_string);

/* --- get nrows --- */
    fseek(f_in, offset, SEEK_SET);
    fgets(p_string, buffr, f_in);
    nrows = atoi(p_string);

/* --- create program arrays --- */
    array1 = malloc(nrows * sizeof(char *));
    label_nam = malloc(nrows * sizeof(char *));
    for(ii = 0; ii < nrows; ii++)
    {   label_nam[ii] = malloc(LLEN * sizeof(char));
    }
    byte_array = malloc(nrows * sizeof(int));

/* --- read byte code --- */
    for(ii=0; ii < nrows; ii++)
    {   fgets(p_string, BUFSIZE, f_in);    /* read in labels */
        len = strlen(p_string);
        len--;
        p_string[len] = '\0';
        strcpy(label_nam[ii], p_string);
    }
    for(ii=0; ii < nrows; ii++)
    {   fgets(p_string, buffr, f_in);    /* read in byte code */
        byte_array[ii] = atoi(p_string);
    }
    for(ii=0; ii < nrows; ii++)
    {   fgets(p_string, BUFSIZE, f_in);    /* read in statement */
        len = strlen(p_string);
        size = (len + 1);
        array1[ii] = malloc(size * sizeof(char));
        strcpy(array1[ii], p_string);
    }
    fclose(f_in);
}
/*-------------------------------*/

