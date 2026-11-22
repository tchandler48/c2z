/* bxbasic : Getinput.c : alpha version */
/* ----- includes ----- */
#include "prototyp.h"


void get_lninput()
{   char ch, varname[VAR_NAME];
    int pi, loc=0;

    pi = e_pos;
    ch = p_string[pi];
    if(ch == ';')		/* do not echo newline */
    {   loc = 1;
        pi++;
        pi = iswhite(pi);
        ch = p_string[pi];
        e_pos = pi;
    }
    if(ch == '\"')          	/* Prompt: "enter string"; */
    {   get_prnstring();
        pi = e_pos;
        pi++;
        pi = iswhite(pi);
        ch = p_string[pi];
        e_pos = pi;
    }
/* --- input string --- */
    strcpy(varname, get_varname());
    input_str(varname,loc);
}
/*---------- end get_lninput ----------*/


void get_input()
{   char ch, varname[VAR_NAME];
    int pi, len, type, loc=0;
    int ab_code=19, x=line_ndx;

    pi = e_pos;
    ch = p_string[pi];
	if(ch == '#')		/* this is a file: [INPUT#1, var:] */
		{
			input_io();
			return;
		}
    if(ch == ';')		/* do not echo newline */
    {   loc = 1;
        pi++;
        pi = iswhite(pi);
        ch = p_string[pi];
        e_pos = pi;
    }
    len = strlen(p_string);
    while(pi < len)                       /* process to end of line */
    {   if(ch == '\"')          	/* INPUT "Print string"; */
        {   get_prnstring();
            pi = e_pos;
            pi++;
            pi = iswhite(pi);
            ch = p_string[pi];
            e_pos = pi;
        }
    /* --- a string$ or numeric variable --- */
        else if(isalpha(ch))
        {   type = get_vtype(pi);
            strcpy(varname, get_varname());
            if(type == 3)       	/* a string$ assignment */
            {   input_str(varname,loc);
                pi = e_pos;
                ch = p_string[pi];
            }
            else  		 /* type==1: numeric assignment */
            {   input_val(varname,loc);
                pi = e_pos;
                ch = p_string[pi];
            }
        }
        else
        {   a_bort(ab_code, x);
        }
    }
}
/*---------- end get_input ----------*/

void input_val(char *name, int loc)
{   char ch, cx, varname[VAR_NAME], string[VAR_NAME];
    int pi, ndx, len, row, col;

    strcpy(varname, name);
    pi = e_pos;
    ch = p_string[pi];

/* --- get cursor --- */
    if(loc == 1)
    {   row = cursor_row();
        col = cursor_col();
    /* --- get data-input --- */
        #ifdef Windows
            cx = getch();
        #endif
        gets(string);
        len = strlen(string);
        reset_cursor(loc,len,col,row);
    }
    else
    {
        #ifdef Windows
            cx = getch();
        #endif
        gets(string);
    }

  /* --- double --- */
    if(ch == '#')
    {   nam_stack = dn_stack;    /* indirect ref.to name_stack */
        max_vars = dmax_vars;
        init_fn = init_dbl;        /* indirect ref.to function */
        ndx = get_varndx(varname);
        dv_stack[ndx] = (double) atof(string);
        pi++;
    }
  /* --- float --- */
    else if(ch == '!')
    {   nam_stack = fn_stack;    /* indirect ref.to name_stack */
        max_vars = fmax_vars;
        init_fn = init_flt;        /* indirect ref.to function */
        ndx = get_varndx(varname);
        fv_stack[ndx] = (float) atof(string);
        pi++;
    }
  /* --- long --- */
    else if(ch == '%')
    {   nam_stack = ln_stack;    /* indirect ref.to name_stack */
        max_vars = lmax_vars;
        init_fn = init_lng;        /* indirect ref.to function */
        ndx = get_varndx(varname);
        lv_stack[ndx] = atol(string);
        pi++;
    }
  /* --- integer --- */
    else
    {   nam_stack = in_stack;    /* indirect ref.to name_stack */
        max_vars = imax_vars;
        init_fn = init_int;        /* indirect ref.to function */
        ndx = get_varndx(varname);
        iv_stack[ndx] = atoi(string);
    }
    pi = iswhite(pi);
    ch = p_string[pi];
    if(strchr(":;,", ch))
    {   pi++;
        set_TabNl(ch);			/* Tab-NewLine */
    }
    pi = iswhite(pi);
    e_pos = pi;
}
/*---------- end input_val ----------*/


void input_str(char *name, int loc)
{   char ch, varname[VAR_NAME], string[BUFSIZE];
    int pi, ndx, len, row, col;
    unsigned xsize;

    strcpy(varname, name);
    nam_stack = sn_stack;    /* indirect ref.to name_stack */
    max_vars = smax_vars;
    init_fn = init_str;        /* indirect ref.to function */
    ndx = get_varndx(varname);

/* --- get cursor --- */
    if(loc == 1)
    {   row = cursor_row();
        col = cursor_col();
    /* --- get data-input --- */
        #ifdef Windows
            ch = getch();
        #endif
        gets(string);
        len = strlen(string);
        reset_cursor(loc,len,col,row);
    }
    else
    {
        #ifdef Windows
            ch = getch();
        #endif
        gets(string);
    }

/* --- store data --- */
    xsize = strlen(string);
    xsize++;
    sv_stack[ndx] = realloc(sv_stack[ndx], xsize * sizeof(char));
    strcpy(sv_stack[ndx], string);              /* save new string */

    pi = e_pos;
    pi++;
    ch = p_string[pi];
    if(strchr(":;,", ch))
    {   pi++;
        set_TabNl(ch);			/* Tab-NewLine */
    }
    pi = iswhite(pi);
    e_pos = pi;
}
/*---------- end input_str ----------*/
