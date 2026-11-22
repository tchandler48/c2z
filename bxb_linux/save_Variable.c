/* bxbasic : Variable.c : alpha version */
/* ----- includes ----- */
#include "prototyp.h"

/* variable types:
      int=no symbol,
     long=%,
    float=!,
   double=#,
   string=$
*/


void parse_let()
{   char ch, varname[VAR_NAME];
    int pi, stlen, ndx=0;
    int ab_code=11, x=line_ndx;

    stlen = strlen(p_string);
    pi = e_pos;

/* --- retrieve variable name from statement --- */
    pi = get_alpha(pi, stlen);
    if(pi == stlen)                      /* error: didn't find it */
    {   a_bort(ab_code, x);
    }
    e_pos = pi;
    strcpy(varname, get_varname());
    pi = e_pos;
    ch = p_string[pi];                     /* get the type character */
/* --- we now have varname and type --- */

/* --- is this a character string --- */
    if(ch == '$')
    {   e_pos = pi;
        parse_str(varname);
    }
/* --- compare name to double array --- */
    else if(ch == '#')                          /* double sign */
    {   nam_stack = dn_stack;    /* indirect reference to name_stack */
        max_vars = dmax_vars;
        init_fn = init_dbl;        /* indirect reference to function */
        ndx = get_varndx(varname);
        pi++;
        pi = iswhite(pi);
        e_pos = pi;
   /* --- now get assignment value --- */
        Match('=');
        dv_stack[ndx] = rdp_main();
    }
/* --- compare name to float array --- */
    else if(ch == '!')                          /* float sign */
    {   nam_stack = fn_stack;    /* indirect reference to name_stack */
        max_vars = fmax_vars;
        init_fn = init_flt;        /* indirect reference to function */
        ndx = get_varndx(varname);
        pi++;
        pi = iswhite(pi);
        e_pos = pi;
   /* --- now get assignment value --- */
        Match('=');
        fv_stack[ndx] = (float) rdp_main();
    }
/* --- compare name to long array --- */
    else if(ch == '%')                          /* long sign */
    {   nam_stack = ln_stack;    /* indirect reference to name_stack */
        max_vars = lmax_vars;
        init_fn = init_lng;        /* indirect reference to function */
        ndx = get_varndx(varname);
        pi++;
        pi = iswhite(pi);
        e_pos = pi;
   /* --- now get assignment value --- */
        Match('=');
        lv_stack[ndx] = (long) rdp_main();
    }
/* --- compare name to integer array --- */
    else                                   /* no type sign */
    {   nam_stack = in_stack;    /* indirect reference to name_stack */
        max_vars = imax_vars;
        init_fn = init_int;        /* indirect reference to function */
        ndx = get_varndx(varname);
        pi = iswhite(pi);
        e_pos = pi;
   /* --- now get assignment value --- */
        Match('=');
        iv_stack[ndx] = (int) rdp_main();
    }
}
/*-------------------------------*/

int get_varndx(char *name)
{   char varname[VAR_NAME];
    int ndx=0, vflag=0, vi_pos=0;

    strcpy(varname, name);
    while((ndx < max_vars) && (strcmp(nam_stack[ndx], varname) != 0))
    {   if(vflag == 0)
        {   if(nam_stack[ndx][0] == '\0')         /* found a null */
            {   vi_pos = ndx;            /* mark this array index */
                vflag = 1;           /* set the exit flag to true */
            }
        }
        ndx++;                             /* increment the index */
    }
    if(ndx == max_vars)      /* did we reach the end of the stack */
    {   ndx = vi_pos;            /* next available stack location */
        if(vflag == 0)
        {   (*init_fn)();      /* initialize a new variable */
            ndx = max_vars;
            ndx--;
        }
        strcpy(nam_stack[ndx], varname);
    }
    return ndx;
}
/*-------------------------------*/

char *get_varname()
{   char ch;
    static char varname[VAR_NAME];
    int pi, si=0;

    pi = e_pos;
    ch = p_string[pi];
    while((isalnum(ch) != 0))
    {   varname[si] = ch;
        si++;
        pi++;
        ch = p_string[pi];
    }
    varname[si] = '\0';
    e_pos = pi;
    return varname;
}
/*-------------------------------*/

double get_varvalue()
{   char ch, varname[VAR_NAME];
    int pi, ndx=0, ab_code=13, x=line_ndx;
    double value;

/* --- get varname --- */
    strcpy(varname, s_holder);

/* --- get var type --- */
    pi = e_pos;
    ch = p_string[pi];
    var_type = ch;

/* --- now compare to var type array --- */
    if(ch == '#')
    {   nam_stack = dn_stack;    /* indirect reference to name_stack */
        max_vars = dmax_vars;
        _GetChar();               /* increment character pointer */
    }
    else if(ch == '!')
    {   nam_stack = fn_stack;    /* indirect reference to name_stack */
        max_vars = fmax_vars;
        _GetChar();               /* increment character pointer */
    }
    else if(ch == '%')
    {   nam_stack = ln_stack;    /* indirect reference to name_stack */
        max_vars = lmax_vars;
        _GetChar();               /* increment character pointer */
    }
    else
    {   nam_stack = in_stack;    /* indirect reference to name_stack */
        max_vars = imax_vars;
    }
    while((ndx < max_vars) && (strcmp(nam_stack[ndx], varname) != 0))
    {   ndx++;                        /* find varname in stack */
    }
    if(ndx == max_vars)              /* error: did not find it */
    {   a_bort(ab_code, x);
    }
    if(ch == '#')
    {   value = dv_stack[ndx];
    }
    else if(ch == '!')
    {   value = (double) fv_stack[ndx];
    }
    else if(ch == '%')
    {   value = (double) lv_stack[ndx];
    }
    else
    {   value = (double) iv_stack[ndx];
    }
    return value;
}
/*-------------------------------*/

double get_avalue()
{   char ch, varname[VAR_NAME];
    int pi, si=0;
    double value=0;

    pi = e_pos;
    ch = p_string[pi];
    if(isalpha(ch))                   /* this is a variable name */
    {   e_pos = pi;
        strcpy(s_holder, get_varname());
        value = get_varvalue();
        pi = e_pos;
    }
    else if((isdigit(ch)) || (IsAddop(ch)))    /* this is a number */
    {   if(IsAddop(ch))
        {   varname[si] = ch;
            si++;
            pi++;
            ch = p_string[pi];
        }
        while(isdigit(ch) != 0)
        {   varname[si] = ch;
            pi++;
            si++;
            ch = p_string[pi];
        }
        varname[si] = '\0';
        value = atof(varname);      /* convert alpha to float */
    }
    pi = iswhite(pi);
    e_pos = pi;
    return value;
}
/*-------- end get_avalue --------*/

void init_int()
{   int ndx;
    unsigned size;

    if(imax_vars == 0)
    {   ndx = imax_vars;
        imax_vars++;
        size = imax_vars;
        iv_stack = malloc(size * sizeof(int));
        in_stack = malloc(size * sizeof(char *));
        size = VAR_NAME;
        in_stack[ndx] = malloc(size * sizeof(char));
    }
    else
    {   ndx = imax_vars;
        imax_vars++;
        size = imax_vars;
        iv_stack = realloc(iv_stack, size * sizeof(int));
        in_stack = realloc(in_stack, size * sizeof(char *));
        size = VAR_NAME;
        in_stack[ndx] = malloc(size * sizeof(char));
    }
    nam_stack = in_stack;
    max_vars = imax_vars;
}
/*---------- end init_int -----------*/

void init_lng()
{   int ndx;
    unsigned size;

    if(lmax_vars == 0)
    {   ndx = lmax_vars;
        lmax_vars++;
        size = lmax_vars;
        lv_stack = malloc(size * sizeof(long));
        ln_stack = malloc(size * sizeof(char *));
        size = VAR_NAME;
        ln_stack[ndx] = malloc(size * sizeof(char));
    }
    else
    {   ndx = lmax_vars;
        lmax_vars++;
        size = lmax_vars;
        lv_stack = realloc(lv_stack, size * sizeof(long));
        ln_stack = realloc(ln_stack, size * sizeof(char *));
        size = VAR_NAME;
        ln_stack[ndx] = malloc(size * sizeof(char));
    }
    nam_stack = ln_stack;
    max_vars = lmax_vars;
}
/*---------- end init_lng -----------*/

void init_flt()
{   int ndx;
    unsigned size;

    if(fmax_vars == 0)
    {   ndx = fmax_vars;
        fmax_vars++;
        size = fmax_vars;
        fv_stack = malloc(size * sizeof(float));
        fn_stack = malloc(size * sizeof(char *));
        size = VAR_NAME;
        fn_stack[ndx] = malloc(size * sizeof(char));
    }
    else
    {   ndx = fmax_vars;
        fmax_vars++;
        size = fmax_vars;
        fv_stack = realloc(fv_stack, size * sizeof(float));
        fn_stack = realloc(fn_stack, size * sizeof(char *));
        size = VAR_NAME;
        fn_stack[ndx] = malloc(size * sizeof(char));
    }
    nam_stack = fn_stack;
    max_vars = fmax_vars;
}
/*---------- end init_flt -----------*/

void init_dbl()
{   int ndx;
    unsigned size;

    if(dmax_vars == 0)
    {   ndx = dmax_vars;
        dmax_vars++;
        size = dmax_vars;
        dv_stack = malloc(size * sizeof(double));
        dn_stack = malloc(size * sizeof(char *));
        size = VAR_NAME;
        dn_stack[ndx] = malloc(size * sizeof(char));
    }
    else
    {   ndx = dmax_vars;
        dmax_vars++;
        size = dmax_vars;
        dv_stack = realloc(dv_stack, size * sizeof(double));
        dn_stack = realloc(dn_stack, size * sizeof(char *));
        size = VAR_NAME;
        dn_stack[ndx] = malloc(size * sizeof(char));
    }
    nam_stack = dn_stack;
    max_vars = dmax_vars;
}
/*---------- end init_dbl -----------*/

void init_str()
{   int ndx;
    unsigned size;

    if(smax_vars == 0)
    {   ndx = smax_vars;
        smax_vars++;
        size = smax_vars;
        sv_stack = malloc(size * sizeof(char *));
        sv_stack[ndx] = malloc(1 * sizeof(char));
        sn_stack = malloc(size * sizeof(char *));
        size = VAR_NAME;
        sn_stack[ndx] = malloc(size * sizeof(char));
    }
    else
    {   ndx = smax_vars;
        smax_vars++;
        size = smax_vars;
        sv_stack = realloc(sv_stack, size * sizeof(char *));
        sv_stack[ndx] = malloc(1 * sizeof(char));
        sn_stack = realloc(sn_stack, size * sizeof(char *));
        size = VAR_NAME;
        sn_stack[ndx] = malloc(size * sizeof(char));
    }
    nam_stack = sn_stack;
    max_vars = smax_vars;
}
/*---------- end init_str -----------*/

void clr_vars()
{   char ch;
    int pi;

    pi = e_pos;
    pi = iswhiter(pi);
    ch = p_string[pi];
    e_pos = pi;
    if(isalpha(ch))
    {   parse_clr();               /* a list of variables */
    }
    else
    {   clr_int();                 /* clear all variables */
        clr_dbl();
        clr_lng();
        clr_flt();
        clr_str();
    }
}
/*--------- end clr_vars --------*/

void parse_clr()
{   char ch, varname[VAR_NAME];
    int pi;

    pi = e_pos;
    ch = p_string[pi];
    while(ch != '\n')
    {   if(isupper(ch))
        {   strcpy(varname, get_varname());
            if(strcmp("INT", varname) == 0)
            {   clr_int();                /* clear variable type */
            }
            else if(strcmp("LNG", varname) == 0)
            {   clr_lng();
            }
            else if(strcmp("FLT", varname) == 0)
            {   clr_flt();
            }
            else if(strcmp("DBL", varname) == 0)
            {   clr_dbl();
            }
            else if(strcmp("STR", varname) == 0)
            {   clr_str();
            }
            else
            {   clr_indvar(varname);      /* individual var */
            }
        }
        else
        {   strcpy(varname, get_varname());
            clr_indvar(varname);          /* individual var */
        }
        pi = e_pos;
        pi = iswhiter(pi);
        ch = p_string[pi];
        if(ch != '\n')
        {   pi++;
            pi = iswhiter(pi);
            ch = p_string[pi];
        }
        e_pos = pi;
/* --- loop: until done --- */
    }
}
/*-------- end parse_clr ---------*/

void clr_indvar(char *name)
{   char ch, varname[VAR_NAME];
    int pi, ndx=0;

    strcpy(varname, name);
    pi = e_pos;
    ch = p_string[pi];

/* --- indirect pointers --- */
    if(ch == '$')
    {   if(smax_vars == 0)
        {   return;
        }
        nam_stack = sn_stack;
        max_vars = smax_vars;
        _GetChar();
    }
    else if(ch == '#')
    {   if(dmax_vars == 0)
        {   return;
        }
        nam_stack = dn_stack;
        max_vars = dmax_vars;
        _GetChar();
    }
    else if(ch == '!')
    {   if(fmax_vars == 0)
        {   return;
        }
        nam_stack = fn_stack;
        max_vars = fmax_vars;
        _GetChar();
    }
    else if(ch == '%')
    {   if(lmax_vars == 0)
        {   return;
        }
        nam_stack = ln_stack;
        max_vars = lmax_vars;
        _GetChar();
    }
    else
    {   if(imax_vars == 0)
        {   return;
        }
        nam_stack = in_stack;
        max_vars = imax_vars;
    }

/* --- get variable index --- */
    while((ndx < max_vars) && (strcmp(nam_stack[ndx], varname) != 0))
    {   ndx++;                        /* find varname in stack */
    }
    if(ndx == max_vars)
    {   return;                      /* reached end: not found */
    }

/* --- zero individual variable --- */
    else if((ch == '$') && (ndx < max_vars))
    {   sv_stack[ndx][0] = '\0';             /* clear string */
        sn_stack[ndx][0] = '\0';
    }
    else if((ch == '#') && (ndx < max_vars))
    {   dv_stack[ndx] = 0;                  /* clear double */
        dn_stack[ndx][0] = '\0';
    }
    else if((ch == '!') && (ndx < max_vars))
    {   fv_stack[ndx] = 0;                  /* clear float */
        fn_stack[ndx][0] = '\0';
    }
    else if((ch == '%') && (ndx < max_vars))
    {   lv_stack[ndx] = 0;                   /* clear long */
        ln_stack[ndx][0] = '\0';
    }
    else if(ndx < max_vars)
    {   iv_stack[ndx] = 0;                  /* clear integer */
        in_stack[ndx][0] = '\0';
    }
}
/*-------- end clr_indvar --------*/

void clr_int()
{   int ndx;

    if(imax_vars > 0)
    {   free(iv_stack);
        for(ndx=0; ndx < imax_vars; ndx++)
        {   free(in_stack[ndx]);
        }
        free(in_stack);
        imax_vars = 0;
    }
}
/*---------- end clr_int -----------*/

void clr_lng()
{   int ndx;

    if(lmax_vars > 0)
    {   free(lv_stack);
        for(ndx=0; ndx < lmax_vars; ndx++)
        {   free(ln_stack[ndx]);
        }
        free(ln_stack);
        lmax_vars = 0;
    }
}
/*---------- end clr_lng -----------*/

void clr_flt()
{   int ndx;

    if(fmax_vars > 0)
    {   free(fv_stack);
        for(ndx=0; ndx < fmax_vars; ndx++)
        {   free(fn_stack[ndx]);
        }
        free(fn_stack);
        fmax_vars = 0;
    }
}
/*---------- end clr_flt -----------*/

void clr_dbl()
{   int ndx;

    if(dmax_vars > 0)
    {   free(dv_stack);
        for(ndx=0; ndx < dmax_vars; ndx++)
        {   free(dn_stack[ndx]);
        }
        free(dn_stack);
        dmax_vars = 0;
    }
}
/*---------- end clr_dbl -----------*/

void clr_str()
{   int ndx;

    if(smax_vars > 0)
    {   for(ndx=0; ndx < smax_vars; ndx++)
        {   free(sv_stack[ndx]);
            free(sn_stack[ndx]);
        }
        free(sv_stack);
        free(sn_stack);
        smax_vars = 0;
    }
}
/*---------- end clr_str -----------*/

