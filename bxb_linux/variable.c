/* bxbasic : Variable.c : alpha version
/* ----- includes ----- */
#include "prototyp.h"

/* variable types:
	int    = no symbol,
	long   = %,
	float  = !,
	double = #,
	string = $
/* ---------------
   array types:
	long   = %,
	float  = !,
	double = #,
	string = $
*/


void erase_array()
{   char ch, varname[VAR_NAME];
    int pi, len, type, indx, params, ii, multiplier, subscript;
    int ab_code=32, x=line_ndx;

    len = strlen(p_string);
    pi = e_pos;
		/**/
 /* --- get array name from statement --- */
    pi = get_alpha(pi, len);
    if(pi == len)					/* error: didn't find it */
    {   a_bort(ab_code, x);
    }
    e_pos = pi;
    strcpy(varname, get_varname());			/* this array's name */
/*    strcpy(varname, local_var(varname)); */
    pi = e_pos;
 /* --- get array type --- */
    type = get_ObjectType(varname);
    if(type < 6)
    {
        ab_code = 33;
        a_bort(ab_code, x);
    }
    else if(type == 6)					/* string array */
    {   indx = get_arrayndx(varname);
        params = strArry[indx].dim;
        
        multiplier = 1;
        for(ii=0; ii < params; ii++)
        {   subscript = strArry[indx].sub[ii];
            multiplier = multiplier * subscript;
        }
/*    printf("multiplier=%d\n", multiplier); */
        multiplier--;
        for(ii=multiplier; ii >= 0; ii--)
        {   if(strArry[indx].elem[ii] != NULL)
            {   free(strArry[indx].elem[ii]);
         /*   printf("ii=%d\n", ii);  */

            }
        }
      /* free(strArry[indx]); */
			/**/
        indx = 0;
        while((indx < ObjNdxCnt) && (strcmp(varname, ObjIndx[indx]) != 0))
        {   indx++;
     /*   printf("indx=%d\n", indx); */

        }
        ObjIndx[indx] = realloc(ObjIndx[indx], 1 * sizeof(char));
        ObjIndx[indx][0] = '\0';
        ObjType[indx][0] = 0;
        ObjType[indx][1] = 0;

    }
    else if(type >= 7)					/* (long) integer array */
    {   
    }


}
/*------- end erase_array -------*/


void do_dim()
{   char ch, varname[VAR_NAME];
    int pi, len, type, ab_code=32, x=line_ndx;

    len = strlen(p_string);
    pi = e_pos;

/* --- get array name from statement --- */
    pi = get_alpha(pi, len);
    if(pi == len)                         	/* error: didn't find it */
       {   
           a_bort(ab_code, x);
       }
    e_pos = pi;
    strcpy(varname, get_varname());             /* this array's name */
    pi = e_pos;

/* --- get array type --- */
    type = get_Arrytype(pi);                    /* this array type */
    if(type < 6)
       {   
           ab_code = 33;
           a_bort(ab_code, x);
       }
    else if(type == 6)                          /* string array */
       {   
           dim_strarry(varname, len, type);
       }
    else if(type == 7)                          /* (long) integer array */
       {   
           dim_intarry(varname, len, type);
       }
    else if(type == 8)                          /* single float array */
       {   
           dim_fltarry(varname, len, type);
       }
    else if(type == 9)                          /* double float array */
       {   
           dim_dblarry(varname, len, type);
       }
    else
       {   
           /* other array types */
       }
}
/*------- end do_dim -------*/


void dim_dblarry(char *name, int len, int type)
{   char ch, varname[VAR_NAME];
    int pi, ii, indx, param, subscript, ab_code, x=line_ndx;
    unsigned multiplier, size;

    pi = e_pos;
    strcpy(varname, name);
		/**/
    if(type == 9)					/* float array */
    {   if(dArryCnt > 0)
        {   indx = 0;
            while((strcmp(varname, dblArry[indx].name) != 0)
								&& (indx < dArryCnt))
            {   indx++;
            }
            if(indx < dArryCnt)		/* found a duplicate name */
            {   ab_code = 34;
                a_bort(ab_code, x);
            }
        }
	/* --- dynamically create array structures --- */
        if(dArryCnt == 0)
        {   size = 1;
            dblArry = malloc(size * sizeof(struct double_array));
        }
        else
        {   size = dArryCnt + 1;
            dblArry = realloc(dblArry, size * sizeof(struct double_array));
        }
		/**/
        strcpy(dblArry[dArryCnt].name, varname);
        param = get_paramsCount(pi, len);	/* get number of parameters */
        dblArry[dArryCnt].dim = param;
        Sav_ObjName(varname, type, param);
			/**/
        pi = get_paren(pi, len);
        pi++;
        e_pos = pi;
        multiplier = 1;
        for(indx=0; indx < param; indx++)
        {   subscript = (int) get_avalue();
            dblArry[dArryCnt].sub[indx] = subscript;
            multiplier = multiplier * subscript;
            pi = e_pos;
            pi = get_digit(pi, len);
            e_pos = pi;
        }
        dblArry[dArryCnt].elem = malloc(multiplier * sizeof(double));
        dArryCnt++;					/* next array index */
    }
    else
    {   /* other array types */
    }
}
/*------- end dim_dblarry -------*/


void dim_fltarry(char *name, int len, int type)
{   char ch, varname[VAR_NAME];
    int pi, ii, indx, param, subscript, ab_code, x=line_ndx;
    unsigned multiplier, size;

    pi = e_pos;
    strcpy(varname, name);
		/**/
    if(type == 8)					/* float array */
    {   if(fArryCnt > 0)
        {   indx = 0;
            while((strcmp(varname, fltArry[indx].name) != 0)
								&& (indx < fArryCnt))
            {   indx++;
            }
            if(indx < fArryCnt)		/* found a duplicate name */
            {   ab_code = 34;
                a_bort(ab_code, x);
            }
        }
	/* --- dynamically create array structures --- */
        if(fArryCnt == 0)
        {   size = 1;
            fltArry = malloc(size * sizeof(struct float_array));
        }
        else
        {   size = fArryCnt + 1;
            fltArry = realloc(fltArry, size * sizeof(struct float_array));
        }
		/**/
        strcpy(fltArry[fArryCnt].name, varname);
        param = get_paramsCount(pi, len);	/* get number of parameters */
        fltArry[fArryCnt].dim = param;
        Sav_ObjName(varname, type, param);
			/**/
        pi = get_paren(pi, len);
        pi++;
        e_pos = pi;
        multiplier = 1;
        for(indx=0; indx < param; indx++)
        {   subscript = (int) get_avalue();
            fltArry[fArryCnt].sub[indx] = subscript;
            multiplier = multiplier * subscript;
            pi = e_pos;
            pi = get_digit(pi, len);
            e_pos = pi;
        }
        fltArry[fArryCnt].elem = malloc(multiplier * sizeof(float));
        fArryCnt++;					/* next array index */
    }
    else
    {   /* other array types */
    }
}
/*------- end dim_fltarry -------*/


void dim_intarry(char *name, int len, int type)
{   char ch, varname[VAR_NAME];
    int pi, ii, indx, param, subscript, ab_code, x=line_ndx;
    unsigned multiplier, size;

    pi = e_pos;
    strcpy(varname, name);
		/**/
    if(type == 7)				/* integer array */
    {   if(iArryCnt > 0)
        {   indx = 0;
            while((strcmp(varname, intArry[indx].name) != 0)
								&& (indx < iArryCnt))
            {   indx++;
            }
            if(indx < iArryCnt)		/* found a duplicate name */
            {   ab_code = 34;
                a_bort(ab_code, x);
            }
        }
	/* --- dynamically create array structures --- */
        if(iArryCnt == 0)
        {   size = 1;
            intArry = malloc(size * sizeof(struct integer_array));
        }
        else
        {   size = iArryCnt + 1;
            intArry = realloc(intArry, size * sizeof(struct integer_array));
        }
		/**/
        strcpy(intArry[iArryCnt].name, varname);
        param = get_paramsCount(pi, len);	/* get number of parameters */
        intArry[iArryCnt].dim = param;
        Sav_ObjName(varname, type, param);
			/**/
        pi = get_paren(pi, len);
        pi++;
        e_pos = pi;
        multiplier = 1;
        for(indx=0; indx < param; indx++)
        {   subscript = (int) get_avalue();
            intArry[iArryCnt].sub[indx] = subscript;
            multiplier = multiplier * subscript;
            pi = e_pos;
            pi = get_digit(pi, len);
            e_pos = pi;
        }
        intArry[iArryCnt].elem = malloc(multiplier * sizeof(long));
        iArryCnt++;					/* next array index */
    }
    else
    {   /* other array types */
    }
}
/*------- end dim_intarry -------*/


void dim_strarry(char *name, int len, int type)
{   char ch, varname[VAR_NAME];
    int pi, ii, indx, param, subscript, ab_code, x=line_ndx;
    unsigned multiplier, size;

    pi = e_pos;
    strcpy(varname, name);
		/**/
    if(type == 6)				/* string array */
    {   if(sArryCnt > 0)
        {   indx = 0;
            while((strcmp(varname, strArry[indx].name) != 0) 
								&& (indx < sArryCnt))
            {   indx++;
            }
            if(indx < sArryCnt)		/* found a duplicate name */
            {   ab_code = 34;
                a_bort(ab_code, x);
            }
        }
	/* --- dynamically create array structures --- */
        if(sArryCnt == 0)
        {   size = 1;
            strArry = malloc(size * sizeof(struct string_array));
        }
        else
        {   size = sArryCnt + 1;
            strArry = realloc(strArry, size * sizeof(struct string_array));
        }
		/**/
        strcpy(strArry[sArryCnt].name, varname);
        param = get_paramsCount(pi, len);	/* get number of parameters */
        strArry[sArryCnt].dim = param;
        Sav_ObjName(varname, type, param);
			/**/
        pi = get_paren(pi, len);
        pi++;
        e_pos = pi;
        multiplier = 1;
        for(indx=0; indx < param; indx++)
        {   subscript = (int) get_avalue();
            strArry[sArryCnt].sub[indx] = subscript;
            multiplier = multiplier * subscript;
            pi = e_pos;
            pi = get_digit(pi, len);
            e_pos = pi;
        }
        strArry[sArryCnt].elem = malloc(multiplier * sizeof(char *));
								/* initialize array */
        for(ii=0; ii < multiplier; ii++)
        {   strArry[sArryCnt].elem[ii] = malloc(1 * sizeof(char));
        }
        sArryCnt++;					/* next array index */
    }
    else
    {   /* other array types */
    }
}
/*------- end dim_strarry -------*/


void parse_let()
{
    char ch, varname[VAR_NAME];
    int pi, len, ndx=0, type, ab_code=11, x=line_ndx;
    int ii, limit;

    len = strlen(p_string);
    pi = e_pos;
    pi = get_alpha(pi, len);
    if(pi == len)                               /* error: didn't find it */
      {
         a_bort(ab_code, x);
      }
    e_pos = pi;
    strcpy(varname, get_varname());		/* get variable name */
    pi = e_pos;
/*    strcpy(varname, local_var(varname)); */
		/**/
    type = get_ObjectType(varname);  
    if(type == -1)
      {
          type = get_objtype(pi);
          Sav_ObjName(varname, type, 0);
      }
    
    e_pos = pi;
		/**/
    switch(type)
    {   case 0:                                 /* string */
            parse_str(varname);
            break;
        case 1:                                 /* no type sign */
            let_int(varname);
            break;
        case 2:                                 /* long integer */
            let_long(varname);
            break;
        case 3:                                 /* single float */
            let_single(varname);
            break;
        case 4:                                 /* double float */
            let_double(varname);
            break;
        case 6:                                 /* string array */
            parse_strarry(varname);
            break;
        case 7:                                 /* integer array */
            parse_intarry(varname);
            break;
        case 8:                                 /* single float array */
            parse_fltarry(varname);
            break;
        case 9:					/* double float array */
            parse_dblarry(varname);
            break;
    }
}
/*-------- end parse_let ---------*/


void parse_dblarry(char *name)
{   char ch, varname[VAR_NAME];
    int pi, len, indx, param, offset;

    strcpy(varname, name);
    indx = get_darrayndx(varname);
    len = strlen(p_string);
    pi = e_pos;
    pi = get_paren(pi, len);
    pi++;
    e_pos = pi;
		/**/
    param = dblArry[indx].dim;
    offset = get_offset(param, len);
    pi = e_pos;
    pi++;
    pi = iswhiter(pi);
    e_pos = pi;
		/**/
/* --- now get assignment value --- */
    Match('=');
    dblArry[indx].elem[offset] = (float) rdp_main();
}
/*---------- end parse_dblarry ----------*/


void parse_fltarry(char *name)
{   char ch, varname[VAR_NAME];
    int pi, len, indx, param, offset;

    strcpy(varname, name);
    indx = get_farrayndx(varname);
    len = strlen(p_string);
    pi = e_pos;
    pi = get_paren(pi, len);
    pi++;
    e_pos = pi;
		/**/
    param = fltArry[indx].dim;
    offset = get_offset(param, len);
    pi = e_pos;
    pi++;
    pi = iswhiter(pi);
    e_pos = pi;
		/**/
/* --- now get assignment value --- */
    Match('=');
    fltArry[indx].elem[offset] = (float) rdp_main();
}
/*---------- end parse_fltarry ----------*/


void parse_intarry(char *name)
{   char ch, varname[VAR_NAME];
    int pi, len, indx, param, offset;

    strcpy(varname, name);
    indx = get_iarrayndx(varname);
    len = strlen(p_string);
    pi = e_pos;
    pi = get_paren(pi, len);
    pi++;
    e_pos = pi;
		/**/
    param = intArry[indx].dim;
    offset = get_offset(param, len);
    pi = e_pos;
    pi++;
    pi = iswhiter(pi);
    e_pos = pi;
		/**/
/* --- now get assignment value --- */
    Match('=');
    intArry[indx].elem[offset] = (long) rdp_main();
}
/*---------- end parse_intarry ----------*/


int get_varndx(char *name)
{   char varname[VAR_NAME];
    int ndx=0, vflag=0, vi_pos=0;

    strcpy(varname, name);
    while((ndx < max_vars) && (strcmp(nam_stack[ndx], varname) != 0))
    {   if(vflag == 0)
        {   if(nam_stack[ndx][0] == '\0')   /* found a null */
            {   vi_pos = ndx;               /* mark this array index */
                vflag = 1;                  /* set the exit flag to true */
            }
        }
        ndx++;                              /* increment the index */
    }
    if(ndx == max_vars)                     /* did we reach the end of the stack */
    {   ndx = vi_pos;                       /* next available stack location */
        if(vflag == 0)
        {   (*init_fn)();                   /* initialize a new variable */
            ndx = max_vars;
            ndx--;
        }
        strcpy(nam_stack[ndx], varname);
    }
    return ndx;
}
/*--------- end get_varndx ----------*/







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
    switch(ch)
    {   case '$':
            if(smax_vars == 0)
            {   return;
            }
            nam_stack = sn_stack;
            max_vars = smax_vars;
            _GetChar();
            break;
        case '#':
            if(dmax_vars == 0)
            {   return;
            }
            nam_stack = dn_stack;
            max_vars = dmax_vars;
            _GetChar();
            break;
       case '!':
            if(fmax_vars == 0)
            {   return;
            }
            nam_stack = fn_stack;
            max_vars = fmax_vars;
            _GetChar();
            break;
       case '%':
            if(lmax_vars == 0)
            {   return;
            }
            nam_stack = ln_stack;
            max_vars = lmax_vars;
            _GetChar();
            break;
       default:
            if(imax_vars == 0)
            {   return;
            }
            nam_stack = in_stack;
            max_vars = imax_vars;
            break;
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


