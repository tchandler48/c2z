/* bxbasic : Utility.c : alpha version */
/* ----- function prototypes ----- */
#include "prototyp.h"



int get_NextOp(int pi)
{   char ch;

    ch = p_string[pi];
    while(isalnum(ch))
    {   pi++;
        ch = p_string[pi];
    }
    pi = iswhiter(pi);
    return pi;
}
/*---------- end get_NextOp ----------*/

int get_paren(int pi, int stlen)
{   char ch;

    ch = p_string[pi];
    while((strchr("()", ch) == 0) && (pi < stlen))
    {   pi++;
        ch = p_string[pi];
    }
    return pi;
}
/*---------- end get_paren ----------*/

int get_upper(int pi, int stlen)
{   char ch;

    ch = p_string[pi];
    while((isupper(ch) == 0) && (pi < stlen))
    {   pi++;
        ch = p_string[pi];
    }
    return pi;
}
/*-------------------------------*/

int get_alpha(int pi, int stlen)
{   char ch;

    ch = p_string[pi];
    while((isalpha(ch) == 0) && (pi < stlen))
    {   pi++;
        ch = p_string[pi];
    }
    return pi;
}
/*-------------------------------*/

int get_digit(int pi, int stlen)
{   char ch;

    ch = p_string[pi];
    while((isdigit(ch) == 0) && (pi < stlen))
    {   pi++;
        ch = p_string[pi];
    }
    return pi;
}
/*-------------------------------*/

int iswhite(int pi)
{   char ch;

    ch = p_string[pi];                  /* if next char is "whitespace" */
    while(isspace(ch) != 0)                            /* get rid of it */
    {   pi++;
        ch = p_string[pi];
    }
    return pi;
}
/*-------- end iswhite ----------*/

int iswhiter(int pi)
{   char ch, space=32;

    ch = p_string[pi];                   /* if next char is "space" */
    while(ch == space)                             /* get rid of it */
    {   pi++;
        ch = p_string[pi];
    }
    return pi;
}
/*-------- end iswhiter ---------*/

void clr_arrays()
{   int ii;

/* --- free program array memory --- */
    for(ii=0; ii < nrows; ii++)
    {   free(label_nam[ii]);
        free(array1[ii]);
    }
    free(label_nam);
    free(byte_array);
    free(array1);
}
/*-------- end clr_arrays ----------*/

int find_strng(char *tmp)
{   char ch, cx, quote='\"';
    char temp[TOKEN_LEN], xxstring[TOKEN_LEN];
    int pi, i, mark, len, len2;

    strcpy(xxstring, tmp);
    len = strlen(p_string);        /* locate xxstring within p_string */
    len2 = strlen(xxstring);
    pi = s_pos;                         /* plant pi w/starting position */
    ch = p_string[pi];
    cx = xxstring[0];             /* plant cx with 1st char in xxstring */
    while(pi < len)
    {   while((ch != cx) && (pi < len))        /* find cx in p_string */
        {   if(ch == quote)            /* line contains a quoted string */
            {   pi++;                    /* advance past quoted strings */
                ch = p_string[pi];
                while(ch != quote)
                {   pi++;
                    ch = p_string[pi];
                }
            }
            pi++;
            ch = p_string[pi];
        }
        if((pi == len) || (pi > len))
        {   mark = 0;        /* an error trap, in case string not found */
            return mark;
        }
        mark = pi;         /* this marks the beginning of search string */
        for(i=0; i < len2; i++)         /* load temp with test string */
        {   temp[i] = ch;
            pi++;
            ch = p_string[pi];
        }
        temp[i] = '\0';
        if(strcmp(temp, xxstring) != 0)      /* test failed, loop again */
        {   pi = (mark+1);               /* advance pi by 1 from "mark" */
            ch = p_string[pi];
        }
        else
        {   mark++;
            pi = len;
        }
    }
    return mark;
}
/*-------- end find_strng ---------*/
