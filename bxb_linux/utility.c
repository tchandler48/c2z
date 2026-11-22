/* bxbasic : Utility.c : alpha version */
/* ----- function prototypes ----- */
#include "prototyp.h"



char *local_var(char *name)
{   static char varname[VAR_NAME];
    char thisvarname[VAR_NAME];
    int ii, limit;

    strcpy(varname, name);		/* is this a passed argument name */
		/**/
    if(callFlag > 0)
    {   limit = StackPtr + paramCnt;
        ii = StackPtr;
		/**/
        while((ii < limit) && (strcmp(varname, paramStack[ii]) != 0))
        {   ii++;
        }
        if(ii == limit)
        {   strcpy(thisvarname, SubNameStack[thisSub]);
            strcat(thisvarname, varname);
            strcpy(varname, thisvarname);
        }
    }
    return varname;
}
/*------- end local_var -------*/


void InitObj()			/* initialize object name/type array */
{
    int ndx;
    unsigned size;

    if(ObjNdxCnt == 0)
    {
        ndx = ObjNdxCnt;  
        ObjNdxCnt++;
        size = ObjNdxCnt;
        ObjIndx = malloc(size * sizeof(char *));
        ObjType = malloc(size * sizeof(int *));
        size = VAR_NAME;
        ObjIndx[ndx] = malloc(size * sizeof(char));
        size = 2;
        ObjType[ndx] = malloc(size * sizeof(int));
    }
    else
    {
        ndx = ObjNdxCnt;
        ObjNdxCnt++;
        size = ObjNdxCnt;
        ObjIndx = realloc(ObjIndx, size * sizeof(char *));
        ObjType = realloc(ObjType, size * sizeof(int *));
        size = VAR_NAME;
        ObjIndx[ndx] = malloc(size * sizeof(char));
        size = 2;
        ObjType[ndx] = malloc(size * sizeof(int));
    }
}
/*---------- end InitObj ----------*/


void Sav_ObjName(char *name, int type, int parm)
{   char varname[VAR_NAME];
    int ndx=0, bool=0;

    strcpy(varname, name);
    InitObj();
    
    ndx = ObjNdxCnt - 1;
    strcpy(ObjIndx[ndx], varname);
    ObjType[ndx][0] = type;
    ObjType[ndx][1] = parm;
   
}
/*---------- end Sav_ObjName ----------*/


int get_ObjectType(char *name)          /* identify object type specifier */
{   char varname[VAR_NAME];
    int ndx=0, type=-1;

    strcpy(varname, name);
    while((ndx < ObjNdxCnt) && (strcmp(varname, ObjIndx[ndx]) != 0))
      {
         ndx++;
      }
    if(ndx < ObjNdxCnt)
      {
         type = ObjType[ndx][0];
      }
    /* put in by tc */
    if(ndx == ObjNdxCnt)
      {
         type = -1;
      }
    return type;
}
/*---------- end get_ObjectType ----------*/


int get_ObjectParam(char *name)	/* return object parameters count */
{   char varname[VAR_NAME];
    int ndx=0, param;

    strcpy(varname, name);
    while((ndx < ObjNdxCnt) && (strcmp(varname, ObjIndx[ndx]) != 0))
    {   ndx++;
    }
    if(ndx < ObjNdxCnt)
    {   param = ObjType[ndx][1];
    }
   

    return param;
}
/*---------- end get_ObjectParam ----------*/


int get_arrayndx(char *name)				/* string arrays */
{   char varname[VAR_NAME];
    int indx=0, ab_code=35, x=line_ndx;

    strcpy(varname, name);
		/**/
    while((strcmp(varname, strArry[indx].name) != 0) && (indx < sArryCnt))
    {   indx++;
    }
    if(indx == sArryCnt)              /* error: did not find it */
    {   strcpy(xstring, varname);
        a_bort(ab_code, x);
    }
    return indx;
}
/*---------- end get_arrayndx ----------*/


int get_iarrayndx(char *name)				/* integer arrays */
{   char varname[VAR_NAME];
    int indx=0, ab_code=35, x=line_ndx;

    strcpy(varname, name);
		/**/
    while((strcmp(varname, intArry[indx].name) != 0) && (indx < iArryCnt))
    {   indx++;
    }
    if(indx == iArryCnt)              /* error: did not find it */
    {   strcpy(xstring, varname);
        a_bort(ab_code, x);
    }
    return indx;
}
/*---------- end get_iarrayndx ----------*/


int get_farrayndx(char *name)				/* float arrays */
{   char varname[VAR_NAME];
    int indx=0, ab_code=35, x=line_ndx;

    strcpy(varname, name);
		/**/
    while((strcmp(varname, fltArry[indx].name) != 0) && (indx < fArryCnt))
    {   indx++;
    }
    if(indx == fArryCnt)              /* error: did not find it */
    {   strcpy(xstring, varname);
        a_bort(ab_code, x);
    }
    return indx;
}
/*---------- end get_farrayndx ----------*/


int get_darrayndx(char *name)				/* double arrays */
{   char varname[VAR_NAME];
    int indx=0, ab_code=35, x=line_ndx;

    strcpy(varname, name);
		/**/
    while((strcmp(varname, dblArry[indx].name) != 0) && (indx < dArryCnt))
    {   indx++;
    }
    if(indx == dArryCnt)              /* error: did not find it */
    {   strcpy(xstring, varname);
        a_bort(ab_code, x);
    }
    return indx;
}
/*---------- end get_darrayndx ----------*/


int get_offset(int param, int len)
{   int pi, ii, limit, subscript, offset;

    offset = 0;
    limit = param - 1;
    for(ii=0; ii < limit; ii++)
    {   subscript = (int) get_avalue();
        subscript--;
        offset += subscript;
        offset *= param;
    

        pi = e_pos;
        pi = get_digit(pi, len);
        e_pos = pi;
    }
    subscript = (int) get_avalue();
    subscript--;
    offset += subscript;
/* printf("subscript=%d offset=%d\n", subscript, offset); */

    return offset;
}
/*---------- end get_offset ----------*/


int get_paramsCount(int pi, int len)
{   char ch;
    int xcnt=0;

    ch = p_string[pi];
    while((ch != ')') && (pi < len))		/* get params count */
    {   pi = get_alnum(pi, len);
        ch = p_string[pi];
        if(isalnum(ch))
        {   xcnt++;
            pi = get_NextOp(pi);
            ch = p_string[pi];
        }
    }        
    return xcnt;
}
/*---------- end get_paramsCount ----------*/


int get_objtype(int pi)
{   char ch, chx;
    int type=-1;

    pi = iswhite(pi);
    ch = p_string[pi];
    chx = p_string[(pi+1)];
    if(ch == '$')
    {   type = 0;
        if(chx == '(')					/* an array subscript */
        {   type = 6;					/* abc$(1,2,3)        */
        }
    }
    else
    {   type = get_Nvtype(pi);
        if(chx == '(')				/* an array subscript */
        {   switch(ch)
            {   case '%':
                    type = 7;			/* integer array */
                    break;
                case '!':
                    type = 8;			/* float array */
                    break;
                case '#':
                    type = 9;			/* double array */
                    break;
            }
        }
    }
    return type;
}
/*------- end get_objtype --------*/


int get_Arrytype(int pi)
{   char ch, chx;
    int type=0;

    pi = iswhite(pi);
    ch = p_string[pi];
    chx = p_string[(pi+1)];
    if(ch == '$')
    {   if(chx == '(')					/* an array subscript */
        {   type = 6;					/* abc$(1,2,3)        */
        }
    }
    else if(strchr("%!#", ch))
    {   if(chx == '(')				/* an array subscript */
        {   switch(ch)
            {   case '%':
                    type = 7;			/* integer array */
                    break;
                case '!':
                    type = 8;			/* float array */
                    break;
                case '#':
                    type = 9;			/* double array */
                    break;
            }
        }
    }
    return type;
}
/*------- end get_Arrytype --------*/



int get_Nvtype(int pi)
{   char ch;
    int type=0;

    pi = while_isalnum(pi);
    ch = p_string[pi];
    if(strchr(", )=+*-/\n", ch))
    {   type = 1;		/* a 16 Bit Word Integer */
    }
    else if(ch == '%')
    {   type = 2;		/* a 32 Bit Long Integer */
    }
    else if(ch == '!')
    {   type = 3;		/* a 32 Bit Floating Point */
    }
    else if(ch == '#')
    {   type = 4;		/* a 64 Bit Double Float */
    }
    else if((ch == '&') || (ch == '@'))
    {   type = 5;		/* a 64 Bit Long Integer */
    }
    return type;
}
/*------- end get_Nvtype --------*/


int get_NextOp(int pi)
{
    pi = while_isalnum(pi);
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


int get_alnum(int pi, int len)
{   char ch;

    ch = p_string[pi];
    while((isalnum(ch) == 0) && (pi < len))
    {   pi++;
        ch = p_string[pi];
    }
    return pi;
}
/*---------- end get_alnum ---------*/



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


int while_isalnum(int pi)
{   char ch;

    ch = p_string[pi];
    while((isalnum(ch)) || (strchr("._", ch)))
    {   pi++;
        ch = p_string[pi];
    }
    return pi;
}
/*-------- end while_isalnum ---------*/


int get_quote(int pi, int len)
{   char ch, quote='\"';

    pi++;
    ch = p_string[pi];
    while((ch != quote) && (pi < len))
    {   pi++;
        ch = p_string[pi];
    }
    if(ch == quote)
    {   pi++;
    }
    return pi;
}
/*-------- end get_quote ---------*/

double get_avalue()
{   char ch, varname[VAR_NAME];
    int pi, si=0, type;
    double value=0;

    pi = e_pos;
    ch = p_string[pi];
    if(isalpha(ch))                   /* this is a variable name */
    {   e_pos = pi;
        s_pos = pi;
        strcpy(s_holder, get_varname());
		/**/
/*        strcpy(s_holder, local_var(s_holder)); */
        type = get_ObjectType(s_holder);
        if(type == -1)
        {   type = get_objtype(pi);
            Sav_ObjName(varname, type, 0);
        }
		/**/
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
double get_varvalue()
{   char ch, varname[VAR_NAME];
    int pi, ndx=0, type, ab_code=13, x=line_ndx;
    double value;

    strcpy(varname, s_holder);
    pi = e_pos;
    var_type = p_string[pi];
    type = get_ObjectType(varname);		/* identify object type */
		/**/
    switch(type)
    {   case 0:                                 /* string$ = "12345.67" */
            nam_stack = sn_stack;               /* indirect reference to name_stack */
            max_vars = smax_vars;
            _GetChar();                         /* increment character pointer */
            break;
        case 1:
            nam_stack = in_stack;
            max_vars = imax_vars;
            break;
        case 2:
            nam_stack = ln_stack;
            max_vars = lmax_vars;
            _GetChar();
            break;
        case 3:
            nam_stack = fn_stack;
            max_vars = fmax_vars;
            _GetChar();
            break;
        case 4:
            nam_stack = dn_stack;
            max_vars = dmax_vars;
            _GetChar();
            break;
    }
    if(type < 6)
    {   while((ndx < max_vars) && (strcmp(nam_stack[ndx], varname) != 0))
        {   ndx++;				/* find varname in stack */
        }
        if(ndx == max_vars)			/* error: did not find it */
        {   printf("\n\"%s\"", varname);
            a_bort(ab_code, x);
        }
    }
    switch(type)
    {   case 0:
            value = atof(sv_stack[ndx]);
            break;
        case 1:
            value = (double) iv_stack[ndx];
            break;
        case 2:
            value = (double) lv_stack[ndx];
            break;
        case 3:
            value = (double) fv_stack[ndx];
            break;
        case 4:
            value = dv_stack[ndx];
            break;
        case 7:
            value = let_intarray(varname);
            break;
        case 8:
            value = let_fltarray(varname);
            break;
        case 9:
            value = let_dblarray(varname);
            break;
    }
    return value;
}
/*--------- end get_varvalue ----------*/



