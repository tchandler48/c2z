/* bxbasic : Output.c : alpha version */
/* ----- includes ----- */
#include "prototyp.h"

void color()
{
    char ch, rows[3], cols[3];
    int pi, stlen, row_x, col_y;
    int si=0, ab_code=10, x=line_ndx;

    stlen = strlen(p_string);
    pi = e_pos;
    pi = iswhite(pi);
    ch = p_string[pi];

/* -------- rows -------- */
    if(isalpha(ch))                      /* this is a variable name */
    {   e_pos = pi;
        strcpy(s_holder, get_varname());
        row_x = (int) get_varvalue();
        pi = e_pos;
        pi = iswhite(pi);
        ch = p_string[pi];
    }
    else if(isdigit(ch))                 /* this is a number */
    {   while(isdigit(ch) != 0)
        {   rows[si] = ch;
            pi++;
            si++;
            ch = p_string[pi];
        }
        rows[si] = '\0';
        row_x = atoi(rows);              /* convert alpha to integer */
    }
    else                                 /* error: failed to find an alpha */
    {   a_bort(ab_code, x);
    }
    pi = iswhite(pi);
    ch = p_string[pi];
    if(ch == ',')                        /* comma separates row and column */
    {   pi++;
        pi = iswhite(pi);
        ch = p_string[pi];
    }
    else
    {   a_bort(ab_code, x);
    }

/* -------- columns -------- */
    if(isalpha(ch))                      /* this is a variable name */
    {   e_pos = pi;
        strcpy(s_holder, get_varname());
        col_y = (int) get_varvalue();
    }
    else if(isdigit(ch))                 /* this is a number */
    {   si = 0;
	while(isdigit(ch) != 0)
        {   cols[si] = ch;
            pi++;
            si++;
            ch = p_string[pi];
        }
        cols[si] = '\0';
        col_y = atoi(cols);              /* convert alpha to integer */
    }
    else
    {   a_bort(ab_code, x);
    }
/* -------- now position cursor -------- */

/* -------- Windows version ---------------- */
#ifdef Windows
    textcolor(row_x);
    textbackground(col_y);
#endif
}
/*-------------------------------------- */


void set_TabNl(int ch)
{
    if(ch == ',')
    {   printf("\t");
    }
    else if(ch == ':')
    {   printf("\n");
    }
}
/*---------- end set_TabNl ----------*/

void reset_cursor(loc,len,col,row)
    int loc, len, col, row;
{
    if(loc == 1)
    {   col += len;
        
        #ifdef Windows
            gotoxy(col,row);	/* LCC.ver */
        #endif
    }
}
/*---------- end reset_cursor ----------*/

int cursor_col()
{   int col;

   
    #ifdef Windows
        col = wherex();		/* LCC.ver */
    #endif
    return col;
}
/*---------- end cursor_col ----------*/

int cursor_row()
{   int row;

   
    #ifdef Windows
        row = wherey();		/* LCC.ver */
    #endif
    return row;
}
/*---------- end cursor_row ----------*/


void cls()
{
 
 #ifdef Windows
    clrscr();      /* CLS - LCC.ver */
 #endif
}
/*------ end cls ------*/

void parse_print()
{   char ch, quote='\"', paren='(';
    int pi, type, ab_code=9, x=line_ndx;

    pi = e_pos;
    pi = iswhiter(pi);
    ch = p_string[pi];
    e_pos = pi;

/* --- print newline --- */
    if(strchr(":\n", ch))
    {   printf("\n");
        return;
    }

/* --- LOOP: multiple print statements --- */
    while(ch != '\n')
    {    if(isalpha(ch))	/* --- print variable --- */
        {   type = get_vtype(pi);
            if(type == 3)
            {   strcpy(s_holder, get_varname());
                get_strvar();           /* string variable */
            }
            else
            {   get_prnvar();		/* variable or expression */
            }
        }
        else if(isdigit(ch))
        {   proc_digit();	 /* string function or expression */
        }
        else if(ch == '?')
        {   var_type = '?';
            get_prnvar();		/* string function */
        }
        else if(ch == paren)
        {   get_prnvar();		/* expression */
        }
        else if(ch == quote)    	/* quoted string */
        {   get_prnstring();
        }
     /* --- error: --- */
        else
        {   a_bort(ab_code, x);
        }

     /* --- return from subroutines --- */
        pi = e_pos;
        ch = p_string[pi];

     /* --- is it end of statement --- */
        if(ch != '\n')
        {   pi++;
            pi = iswhiter(pi);
            ch = p_string[pi];
            e_pos = pi;
        }
/* --- LOOP: if more to print --- */
    }
}
/*-------- end parse_print --------*/


void proc_digit()
{   char ch, val_strng[VAR_NAME];
    int pi, len, px;
    double value;

    pi = e_pos;
    len = strlen(p_string);
    px = get_paren(pi, len);	/* find next paren: "("     */
    pi = get_NextOp(pi);	/* find next Op             */
    if(pi == px)		/* string function: 1(abc$) */
    {   prn_strfunc();		/* if px is paren----^      */
    }
    else
    {   value = rdp_main();	/* math expression */
        strcpy(val_strng, value2strng(value));
        pi = e_pos;
        pi = iswhiter(pi);
        ch = p_string[pi];
        e_pos = pi;
        if(ch == ',')      printf("%s \t", val_strng);
        else if(ch == ';') printf("%s ", val_strng);
        else               printf("%s \n", val_strng);
    }
}
/*-------- end proc_digit --------*/

void prn_strfunc()
{   char ch;
    int pi;

/* --- get function --- */
    asn_function();
    pi = e_pos;
    pi++;
    pi = iswhiter(pi);
    ch = p_string[pi];
    e_pos = pi;

/* --- display string$ --- */
    if(ch == ',')      printf("%s\t", s_holder);
    else if(ch == ';') printf("%s", s_holder);
    else               printf("%s\n", s_holder);
}
/*--------- end prn_strfunc -----------*/


void get_prnstring()
{   char ch, quote='\"';
    int pi, si=0, stlen;
    int ab_code=6, x=line_ndx;

    stlen = strlen(p_string);
    pi = e_pos;
    pi++;
    ch = p_string[pi];
    while((ch != quote) && (pi < stlen))
    {   xstring[si] = ch;
        pi++;
        si++;
        ch = p_string[pi];
    }
    xstring[si]='\0';

/* --- error: no closing quote --- */
    if(pi >= stlen)
    {   a_bort(ab_code, x);
    }

/* --- advance to next character --- */
    pi++;
    pi = iswhiter(pi);
    ch = p_string[pi];
    e_pos = pi;

/* --- print quoted string --- */
    if(ch == ',')      printf("%s\t", xstring);
    else if(ch == ';') printf("%s", xstring);
    else               printf("%s\n", xstring);
}
/*-------- end get_prnstring --------*/

void get_strvar()
{   char ch, varname[VAR_NAME];
    int pi, ndx=0, ab_code=13, x=line_ndx;
/* --- get varname --- */
    strcpy(varname, s_holder);

/* --- get stack index --- */
    while((ndx < smax_vars) && (strcmp(sn_stack[ndx], varname) != 0))
    {   ndx++;                        /* find varname in stack */
    }
    if(ndx == smax_vars)              /* error: did not find it */
    {   a_bort(ab_code, x);
    }
    pi = e_pos;
    pi++;
    pi = iswhiter(pi);
    ch = p_string[pi];
    e_pos = pi;

/* --- display string$ --- */
    if(ch == ',')      printf("%s\t", sv_stack[ndx]);
    else if(ch == ';') printf("%s", sv_stack[ndx]);
    else               printf("%s\n", sv_stack[ndx]);
}
/*--------- end get_strvar -----------*/

void get_prnvar()
{   char ch=var_type, val_strng[VAR_NAME];
    int pi;
    double value;

/* --- call math parser --- */
    value = rdp_main();

    if(ch == '?')
    {   var_type = func_type;
    }

/* --- convert value to string$ --- */
    strcpy(val_strng, value2strng(value));
 
    pi = e_pos;
    pi = iswhiter(pi);
    ch = p_string[pi];
    e_pos = pi;
    if(ch == ',')      printf("%s \t", val_strng);
    else if(ch == ';') printf("%s ", val_strng);
    else               printf("%s \n", val_strng);
}
/*--------- end get_prnvar -----------*/

void locate()
{   char ch, rows[3], cols[3];
    int pi, stlen, row_x, col_y;
    int si=0, ab_code=10, x=line_ndx;

    stlen = strlen(p_string);
    pi = e_pos;
    pi = iswhite(pi);
    ch = p_string[pi];

/* -------- rows -------- */
    if(isalpha(ch))                   /* this is a variable name */
    {   e_pos = pi;
        strcpy(s_holder, get_varname());
        row_x = (int) get_varvalue();
        pi = e_pos;
        pi = iswhite(pi);
        ch = p_string[pi];
    }
    else if(isdigit(ch))                 /* this is a number */
    {   while(isdigit(ch) != 0)
        {   rows[si] = ch;
            pi++;
            si++;
            ch = p_string[pi];
        }
        rows[si] = '\0';
        row_x = atoi(rows);      /* convert alpha to integer */
    }
    else                       /* error: failed to find an alpha */
    {   a_bort(ab_code, x);
    }
    pi = iswhite(pi);
    ch = p_string[pi];
    if(ch == ',')             /* comma separates row and column */
    {   pi++;
        pi = iswhite(pi);
        ch = p_string[pi];
    }
    else
    {   a_bort(ab_code, x);
    }

/* -------- columns -------- */
    if(isalpha(ch))                   /* this is a variable name */
    {   e_pos = pi;
        strcpy(s_holder, get_varname());
        col_y = (int) get_varvalue();
    }
    else if(isdigit(ch))                 /* this is a number */
    {   si = 0;
	while(isdigit(ch) != 0)
        {   cols[si] = ch;
            pi++;
            si++;
            ch = p_string[pi];
        }
        cols[si] = '\0';
        col_y = atoi(cols);      /* convert alpha to integer */
    }
    else
    {   a_bort(ab_code, x);
    }
/* -------- now position cursor -------- */

    /* --- Lcc version --- */
#ifdef Windows
    row_x++;
    col_y++;
    gotoxy(col_y,row_x);
#endif
}
/*-------------------------------*/

char *value2strng(double value)
{   static char buffer[81];
    int pi, len, idx=0, dot=0;
    char ch, chx=var_type;


/* --- convert to ascii, here --- */
    sprintf(buffer, "% f", value);
    len = strlen(buffer);
    ch = buffer[idx];

/* --- trim trailing zeros --- */
    if(chx == '#')                          /* Double: '#' */
    {   idx = (len-1);
        ch = buffer[idx];
        while(ch == '0')
        {   idx--;
            ch = buffer[idx];
        }
        buffer[(idx+1)] = '\0';
    }

/* --- round up to .nn --- */
    else if(chx == '!')                     /* Single: '!' */
    {   dot = (len-5);
        idx = (len-1);
        while(idx > dot)
        {   if((buffer[idx] >= '5') && (buffer[(idx-1)] == '9'))
            {   buffer[idx] = '\0';
            }
            else if(buffer[idx] >= '5')
            {   buffer[(idx-1)]++;
                buffer[idx] = '\0';
            }
            else
            {   buffer[idx] = '\0';
            }
            idx--;
        }
    }
/* --- trim to dot --- */
    else                           /* Integers: '%' */
    {   idx = (len-7);
        buffer[idx] = '\0';
    }
    return buffer;
}
/*------ end value2strng -------*/

