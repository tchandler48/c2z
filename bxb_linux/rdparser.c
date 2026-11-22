/* bxbasic : Rdparser.c : alpha version */
/* special credits to: Jack Crenshaw's 
   "How to Build a Compiler"            */

/* ----- function prototypes ----- */
#include "prototyp.h"


double rdp_main()		/* Recursive Decent Parser Main */
{   double value;

    value = Expression();
    return value;
}
/*---------- end rdp_main ----------*/


void do_random()
{   char ch;
    int pi;
    unsigned seed=0;
    double value;

    pi = e_pos;
    pi = iswhite(pi);
    ch = p_string[pi];
    if((isalpha(ch)) || (isdigit(ch)))	/* this is a variable name */
      {
        e_pos = pi;
        value = get_avalue();
        seed = (unsigned) value;
      }
    srand(seed);
}
/*-------------------------------*/


double Expression()	/* Parse and Translate an Expression */
{   char ch;
    int pi;
    double Value;

    pi = e_pos;
    ch = p_string[pi];
    if(IsAddop(ch))
    {   Value = 0;
    }
    else
    {   Value = Term();
        pi = e_pos;
        ch = p_string[pi];
    }
    while(IsAddop(ch))
    {   switch(ch)
        {    case '+':
                 Match('+');
                 Value = Value + Term();
                 break;
             case '-':
                 Match('-');
                 Value = Value - Term();
                 break;
             default:
                 break;
        }
        pi = e_pos;
        ch = p_string[pi];
    }
    return Value;
}
/*---------- end Expression ----------*/

double Term()		/* Parse and Translate a Math Term */
{   char ch;
    int pi;
    double Value, power;

    Value = Factor();
    pi = e_pos;
    ch = p_string[pi];
    while(IsMultop(ch))
    {    switch(ch)
         {    case '*':
                  Match('*');
                  Value = Value * Factor();
                  break;
              case '/':
                  Match('/');
                  Value = Value / Factor();
                  break;
              case '^':
                  Match('^');
                  Value = pow(Value, Factor());
                  break;
              case '%':
                  Match('%');
                  Value = (int) Value % (int) Factor();
                  break;
              default:
                  break;
         }
         pi = e_pos;
         ch = p_string[pi];
    }
    return Value;
}
/*---------- end Term ----------*/

double Factor()		/* Parse and Translate a Math Factor */
{   char ch;
    int pi;
    double value;

    pi = e_pos;
    ch = p_string[pi];
    if(ch == '(')
    {   Match('(');
        value = Expression();
        Match(')');
    }
    else
    {   if(isalpha(ch))			/* variable name */
        {   strcpy(s_holder, get_varname());
            value = get_varvalue();
            SkipWhite();
        }
        else if(ch == '?')		/* math function */
        {   value = math_functn();
            SkipWhite();
        }
        else				/* numeric value */
        {   value = GetNum();
        }
    }
    return value;
}
/*---------- end Factor ----------*/

double math_functn()
{   int pi, type;
    double value=0;

    pi = e_pos;		/* enter: ?1(x) */
    pi++;		/*    ----^     */
    e_pos = pi;
    type = (int) get_avalue();
    switch(type)
    {   case 1:
            value = get_ABS();		/* a = ABS(exp) */
            break;
        case 2:
            value = get_ASC();		/* a = ASC(str$) */
            break;
        case 3:
            value = get_ATN();		/* a = ATN(exp) */
            break;
        case 4:
            value = get_COS();		/* a = COS(exp) */
            break;
        case 5:
            value = get_SIN();		/* a = SIN(exp) */
            break;
        case 6:
            value = get_TAN();		/* a = TAN(exp) */
            break;
        case 7:
            value = get_SQRT();		/* a = SQRT(exp) */
            break;
       case 8:
              value = get_INT();		/* a = INT(exp) */
		break;
	case 16:				/* a = CLOCK(exp) */
		value = get_CLOCK();
		break;
 	case 17:
              value = do_RAND();
              break;

        default:
            /* error */
            break;
    }
    switch(type)
    {   case 1:
        case 2:
        case 8:
        case 9:
        case 10:
        case 11:
        case 13:
            func_type = '%';
            break;
        case 12:
            func_type = '#';
            break;
        default:
            func_type = '!';
            break;
    }
    return value;
}
/*---------- end math_functn ----------*/

double get_INT()
{   long ivalue;
    double value;

    ivalue = (long) Factor();
    value = (double) ivalue;
    return value;
}
/*---------- end get_INT ----------*/

double get_SQRT()
{   double value;

    value = Factor();
    value = sqrt(value);
    return value;
}
/*---------- end get_SQRT ----------*/

double get_TAN()
{   double value;

    value = Factor();
    value = tan(value);
    return value;
}
/*---------- end get_TAN ----------*/

double get_SIN()
{   double value;

    value = Factor();
    value = sin(value);
    return value;
}
/*---------- end get_SIN ----------*/

double get_COS()
{   double value;

    value = Factor();
    value = cos(value);
    return value;
}
/*---------- end get_COS ----------*/

double get_ATN()
{   double value;

    value = Factor();
    value = atan(value);
    return value;
}
/*---------- end get_ATN ----------*/

double get_ASC()
{   char ch;
    int pi, ndx, len;
    double value;

    pi = e_pos;
    pi++;
    pi = iswhite(pi);
    ch = p_string[pi];
    e_pos = pi;
    if(isalpha(ch))			/* string varname */
    {   ndx = get_strndx();
        ch = sv_stack[ndx][0];
    }
    else				/* quoted "string" */
    {   pi++;
        ch = p_string[pi];
    }
    len = strlen(p_string);
    pi = get_paren(pi, len);		/* advance to: ')' */
    pi++;
    e_pos = pi;
    value = (double) ch;
    return value;
}
/*---------- end get_ASC ----------*/

double get_ABS()
{   long ivalue;              /* do not change because: abs(int!) */
    double value;

    ivalue = (long) Factor();
    value = (double) abs(ivalue);
    return value;
}
/*---------- end get_ABS ----------*/


void Match(char x)	/* Match a Specific Input Character */
{   char ch, string[6];
    int pi, ab_code=12, ln=line_ndx;

    pi = e_pos;
    ch = p_string[pi];
    if(ch != x)
    {   strcpy(string, "\" \"");
        string[1] = x;
        strcpy(t_holder, string);
        a_bort(ab_code,ln);
    }
    else
    {   _GetChar();
        SkipWhite();
    }
}
/*---------- end Match ----------*/

void _GetChar()
{
    e_pos++;
}
/*---------- end _GetChar ----------*/

int Is_White(char ch)
{   int test=0;

    if((ch == ' ') || (ch == '\t'))
    {   test = -1;
    }
    return test;
}
/*---------- end Is_White ----------*/

void SkipWhite() 	/* Skip Over Leading White Space */
{   char ch;
    int pi;

    pi = e_pos;
    ch = p_string[pi];
    while(Is_White(ch))
    {   _GetChar();
        pi = e_pos;
        ch = p_string[pi];
    }
}
/*---------- end SkipWhite ----------*/

double GetNum()			/* Get a Number */
{   char ch;
    int pi, ab_code=12, ln=line_ndx;
    double value=0;

    pi = e_pos;
    ch = p_string[pi];
    if((! isdigit(ch)) && (ch != '.'))
    {   strcpy(t_holder, "Numeric Value");
        a_bort(ab_code,ln);
    }
    value = asc_2_dbl();
    pi = e_pos;
    ch = p_string[pi];
    if(isdigit(ch))
    {   while(isdigit(ch))
        {   pi++;
            ch = p_string[pi];
        }
        e_pos = pi;
    }
    SkipWhite();
    return value;
}
/*---------- end GetNum ----------*/

int IsAddop(char ch) 		/* Recognize an Addop */
{   int rval=0;

    if((ch == '+') || (ch == '-'))
    {   rval = 1;
    }
    return rval;
}
/*---------- end IsAddop ----------*/

int IsMultop(char ch) 		/* Recognize an Addop */
{   int rval=0;

    if(strchr("*^/%", ch))
    {   rval = 1;
    }
    return rval;
}
/*---------- end IsMultop ----------*/

double asc_2_dbl()
{   char ch, cvalue[33];
    int pi, vi_pos=0;
    double fvalue;

    pi = e_pos;
    ch = p_string[pi];
    while((isdigit(ch)) || (ch == '.') && (vi_pos <= 32))
    {   cvalue[vi_pos] = ch;
        pi++;
        vi_pos++;
        ch = p_string[pi];
    }
    cvalue[vi_pos] = '\0';
    fvalue = atof(cvalue);                 /* convert ascii to integer */
    e_pos = pi;
    return fvalue;
}
/*------- end asc_2_dbl ---------*/

void let_double(char *name)
{   char varname[VAR_NAME];
    int pi, ndx;

    strcpy(varname, name);
    pi = e_pos;
    nam_stack = dn_stack;
    max_vars = dmax_vars;
    init_fn = init_dbl;
    ndx = get_varndx(varname);
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
    Match('=');					/* now get assignment value */
    dv_stack[ndx] = rdp_main();
}
/*-------- end let_double --------*/


void let_single(char *name)
{   char varname[VAR_NAME];
    int pi, ndx;

    strcpy(varname, name);
    pi = e_pos;
    nam_stack = fn_stack;
    max_vars = fmax_vars;
    init_fn = init_flt;
    ndx = get_varndx(varname);
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
    Match('=');					/* now get assignment value */
    fv_stack[ndx] = (float) rdp_main();
}
/*-------- end let_single --------*/


void let_long(char *name)
{   char varname[VAR_NAME];
    int pi, ndx;

    strcpy(varname, name);
    pi = e_pos;
		/**/
    nam_stack = ln_stack;
    max_vars = lmax_vars;
    init_fn = init_lng;
    ndx = get_varndx(varname);
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
    Match('=');					/* now get assignment value */
    lv_stack[ndx] = (long) rdp_main();
}
/*-------- end let_long --------*/


void let_int(char *name)
{   char varname[VAR_NAME];
    int pi, ndx;

    strcpy(varname, name);
    pi = e_pos;
		/**/
    nam_stack = in_stack;
    max_vars = imax_vars;
    init_fn = init_int;
    ndx = get_varndx(varname);
    pi = iswhite(pi);
    e_pos = pi;
    Match('=');					/* now get assignment value */
    iv_stack[ndx] = (int) rdp_main();
}
/*-------- end let_int --------*/


double let_intarray(char *name)
{   char varname[VAR_NAME];
    int pi, indx, len, param, offset;
    double value;

    e_pos = s_pos;
    strcpy(varname, name);
    indx = get_iarrayndx(varname);
    len = strlen(p_string);
    pi = e_pos;
    pi = get_paren(pi, len);
    pi++;
    e_pos = pi;
    param = intArry[indx].dim;
    offset = get_offset(param, len);
    pi = e_pos;
    pi++;
    pi = iswhiter(pi);
    e_pos = pi;
    value = (double) intArry[indx].elem[offset];
    return value;
}
/*-------- end let_intarray --------*/


double let_fltarray(char *name)
{   char varname[VAR_NAME];
    int pi, indx, len, param, offset;
    double value;

    e_pos = s_pos;
    strcpy(varname, name);
    indx = get_farrayndx(varname);
    len = strlen(p_string);
    pi = e_pos;
    pi = get_paren(pi, len);
    pi++;
    e_pos = pi;
    param = fltArry[indx].dim;
    offset = get_offset(param, len);
    pi = e_pos;
    pi++;
    pi = iswhiter(pi);
    e_pos = pi;
    value = (double) fltArry[indx].elem[offset];
    return value;
}
/*-------- end let_fltarray --------*/


double let_dblarray(char *name)
{   char varname[VAR_NAME];
    int pi, indx, len, param, offset;
    double value;

    e_pos = s_pos;
    strcpy(varname, name);
    indx = get_darrayndx(varname);
    len = strlen(p_string);
    pi = e_pos;
    pi = get_paren(pi, len);
    pi++;
    e_pos = pi;
    param = dblArry[indx].dim;
    offset = get_offset(param, len);
    pi = e_pos;
    pi++;
    pi = iswhiter(pi);
    e_pos = pi;
    value = dblArry[indx].elem[offset];
    return value;
}
/*-------- end let_dblarray --------*/

long get_CLOCK()
	{
		long value;
		value = clock();
		return value;
	}
/*---------- end get_CLOCK ----------*/

int do_RAND()
{   char ch;
    int pi, len, random_val;

    len = strlen(p_string);
    pi = e_pos;
    ch = p_string[pi];
    while((ch != ')') && (pi < len))
      {
        pi++;
        ch = p_string[pi];
      }
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
    random_val = rand();
    return random_val;
}
/**------ END RND_HANDLER -------**/
