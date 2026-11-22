/* zbxbasic : zIfendif.c : alpha version */

void do_if()
{   int bool, els_ndx, end_ndx;

    bool = boolexpress();

/* --- now take action --- */
    if(bool == 1)
    {   els_ndx = find_else(line_ndx);   /* find next elseif/else */
        end_ndx = find_endif(line_ndx);  /* find the endif */

        line_ndx++;			 /* increment line */
        while(line_ndx < els_ndx)
        {   s_pos = 0;
            e_pos = 0;
            get_token();
            if(token == 5)
            {   break;
            }
            parser();
            line_ndx++;
        }
        if(token == 5)
        {   line_ndx--;
            return;
        }
        line_ndx = end_ndx;
    }
    else
    {   els_ndx = find_else(line_ndx);     /* find this elseif/else */
        els_ndx--;
        line_ndx = els_ndx;
    }
}
/*------- end do_if ----------*/

int find_else(int ndx)
{   int tok=0;

    while((tok != 14) && (tok != 15) && (tok != 16))
    {   ndx++;			    /* find: elseif, else, endif */
        tok = byte_array[ndx];
        if(tok == 13)
        {   ndx = find_endif(ndx); 	/* find next exit point */
        }
    }
    return ndx;
}
/*------- end find_else -------*/

int find_endif(int ndx)
{   int tok=0;

    while(tok != 16)  		/* find the exit point */
    {   ndx++;
        tok = byte_array[ndx];
        if(tok == 13)
        {   ndx = find_endif(ndx);
        }
    }
    return ndx;
}
/*------- end find_endif -------*/

int boolexpress()
	{
		int bool, type, a_bool, or_bool, op;
		int ab_code=17, x=line_ndx;

		type = get_type();		/* what type of comparison is it */
		if((type == 1) || (type == 2))
			{
				bool = Nboolterm(type);		/* numeric evaluation */
			}
			else if((type == 3) || (type == 4))
			{
				bool = Sboolterm(type);        /* a string evaluation */
			}
			else if(type == 5)
			{
				bool = is_eof();			/* an EOF evaluation */
				if(bool != 0)
					{
						bool = 1;
					}
			}
			else
			{
				a_bort(ab_code,x);
			}

/* --- process AND / OR --- */
    op = IsAndOrOp();
    while(op != 0)
    {   if(op == 1)
        {   a_bool = AndOrBoolExp();		/* do: AND */
            if((bool == 1) && (a_bool == 1))
            {   bool = 1;
            }
            else
            {   bool = 0;
            }
        }
        else if(op == 2)
        {   or_bool = AndOrBoolExp();		/* do: OR */
            if((bool == 1) || (or_bool == 1))
            {   bool = 1;
            }
        }
        op = IsAndOrOp();
    }
    return bool;
}
/*------- end boolexpress --------*/

int AndOrBoolExp()
{   int bool, type;
    int ab_code=17, x=line_ndx;

    type = get_type();		/* what type of comparison is it */
    if((type == 1) || (type == 2))
    {   bool = Nboolterm(type);		/* numeric evaluation */
    }
    else if((type == 3) || (type == 4))
    {   bool = Sboolterm(type);        /* a string evaluation */
    }
    else
    {   a_bort(ab_code,x);
    }
    return bool;
}
/*------- end AndOrBoolExp --------*/

int Nboolterm(int type)
{   char ch;
    int pi, bool, a_bool=0;
    double lvalue;

    if(type == 1)
    {   lvalue = get_avalue();	     /* variable or digit value */
    }
    else
    {   lvalue = rdp_main();	    /* expression within parens */
    }
    bool = Nrelation(lvalue);
    return bool;
}
/*------- end Nboolterm --------*/

int Nrelation(double lvalue)
{   int bool, op, type;
    int ab_code=17, x=line_ndx;
    double rvalue;

    op = get_op();			/* get eval op type */
    type = get_type();			/* get right side type */
    if(type == 1)
    {   rvalue = get_avalue();	     /* variable or digit value */
    }
    else if(type == 2)
    {   rvalue = rdp_main();	    /* expression within parens */
    }
    else
    {   a_bort(ab_code,x);
    }
    bool = eval_value(lvalue,rvalue,op);  /* evaluate operators */
    return bool;
}
/*------- end Nrelation --------*/

int eval_value(double lval,double rval,int op)
{   int bool=0;

    if(op == 1)
    {   if(lval == rval)
        {   bool = 1;
        }
    }
    else if(op == 2)
    {   if(lval < rval)
        {   bool = 1;
        }
    }
    else if(op == 3)
    {   if(lval > rval)
        {   bool = 1;
        }
    }
    else if(op == 4)
    {   if(lval <= rval)
        {   bool = 1;
        }
    }
    else if(op == 5)
    {   if(lval >= rval)
        {   bool = 1;
        }
    }
    else if(op == 6)
    {   if(lval != rval)
        {   bool = 1;
        }
    }
    return bool;
}
/*------- end eval_value -------*/

int Sboolterm(int type)
{   char lstring[BUFSIZE];
    int bool, ndx;

    if(type == 3)
    {   ndx = get_string();		/* string variable */
        strcpy(lstring, sv_stack[ndx]);
    }
    else
    {   get_qstring();			/* quoted string */
        strcpy(lstring, s_holder);
    }
    bool = Srelation(lstring);
    return bool;
}
/*------- end Sboolterm --------*/

int Srelation(char *lstr)
{   char lstring[BUFSIZE], rstring[BUFSIZE];
    int bool, ndx, op, type;
    int ab_code=17, x=line_ndx;

    strcpy(lstring, lstr);
    op = get_op();			/* get eval op type */
    type = get_type();			/* get right side type */
    if(type == 3)
    {   ndx = get_string();		/* string variable */
        strcpy(rstring, sv_stack[ndx]);
    }
    else if(type == 4)
    {   get_qstring();			/* quoted string */
        strcpy(rstring, s_holder);
    }
    else
    {   a_bort(ab_code,x);
    }
    bool = eval_string(lstring,rstring,op);
    return bool;
}
/*------- end Srelation --------*/

int eval_string(char *lstr,char *rstr,int op)
{   char lstring[BUFSIZE], rstring[BUFSIZE];
    int bool=0, comp;

    strcpy(lstring, lstr);
    strcpy(rstring, rstr);
    comp = strcmp(lstring, rstring);

/* --- now test expression --- */
    if(op == 1)
    {   if(comp == 0)
        {   bool = 1;
        }
    }
    else if(op == 2)
    {   if(comp < 0)
        {   bool = 1;
        }
    }
    else if(op == 3)
    {   if(comp > 0)
        {   bool = 1;
        }
    }
    else if(op == 4)
    {   if(comp <= 0)
        {   bool = 1;
        }
    }
    else if(op == 5)
    {   if(comp >= 0)
        {   bool = 1;
        }
    }
    else if(op == 6)
    {   if(comp != 0)
        {   bool = 1;
        }
    }
    return bool;
}
/*------- end eval_string -------*/

int IsAndOrOp()
{   char ch;
    int pi, op=0;

    pi = e_pos;
    pi = iswhiter(pi);
    ch = p_string[pi];
    if(ch == '&')
    {   op = 1;
        pi++;
        pi = iswhiter(pi);
    }
    else if(ch == '|')
    {   op = 2;
        pi++;
        pi = iswhiter(pi);
    }
    e_pos = pi;
    return op;
}
/*------- end IsAndOrOp --------*/

int get_type()
{   char ch;
    int pi, type=0;

    pi = e_pos;
    pi = iswhiter(pi);
    ch = p_string[pi];
    if(isalpha(ch))
    {   type = get_vtype(pi);          /* variable name */
    }
    else if(isdigit(ch))
    {   type = 1;                      /* number value */
    }
    else if(ch == '(')
    {   type = 2;                      /* expression in parens */
    }
    else if(ch == '\"')
    {   type = 4;                      /* quoted string */
    }
    e_pos = pi;
    return type;
}
/*------- end get_type ---------*/


int get_string()
{   char ch, varname[VAR_NAME];
    int pi, ndx=0, ab_code=13, x=line_ndx;

/* --- get varname --- */
    strcpy(varname, get_varname());

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
    return ndx;
}
/*------- end get_string -------*/

void get_qstring()
{   char ch, quote='\"';
    int pi, si=0, stlen, ab_code=6, x=line_ndx;

    stlen = strlen(p_string);
    pi = e_pos;                        /* plant "pi" with first quote */
    pi++;
    ch = p_string[pi];
/* --- we now have first character --- */

/* --- fill buffer with string --- */
    si = 0;
    while((ch != quote) && (pi < stlen))
    {   s_holder[si] = ch;
        si++;
        pi++;
        ch = p_string[pi];
    }
    s_holder[si] = '\0';
    if(pi == stlen)                 /* error:if at end of line */
    {   a_bort(ab_code,x);
    }
    pi++;
    e_pos = pi;
}
/*------- end get_qstring -------*/

int get_op()
{   char ch;
    int pi, op, ab_code=18, x=line_ndx;

    pi = e_pos;
    ch = p_string[pi];
    if(strchr("\"$%!#", ch))
    {   pi++;			/* increment past current symbol */
    }
    pi = iswhite(pi);
    ch = p_string[pi];
    if(ch == '=')
    {   op = 1;			/* an is_equal evaluation */
    }
    else if(ch == '<')
    {   pi++;
        ch = p_string[pi];
        if(ch == '>')
        {   op = 6;		/* a not_equal evaluation */
        }
        else if(ch == '=')
        {   op = 4;		/* a less-than or equal eval */
        }
        else
        {   op = 2;		/* a less-than evaluation */
        }
    }
    else if(ch == '>')
    {   pi++;
        ch = p_string[pi];
        if(ch == '=')
        {   op = 5;		/* a greater-than or equal eval */
        }
        else
        {   op = 3;		/* a greater-than evaluation */
        }
    }
    else
    {   a_bort(ab_code,x);
    }
    if(strchr("=>", ch))
    {   pi++;
    }
    e_pos = pi;
    return op;
}
/*------- end get_op -------*/


int if_eof()
	{
		char tmp[4];
		int flag=0;

		strcpy(tmp, "EOF");
		flag = find_strng(tmp);
		return flag;
	}


int is_eof()
	{
		char ch;
		int pi, len, bool, port;
		int maxfiles=(IOARRAY-1), x=line_ndx, ab_code=23;
		double fileno;
		FILE *handle;

		len = strlen(p_string);
		pi = e_pos;			/* this function is a file handler only */
		e_pos = get_digit(pi, len);
		fileno = get_avalue();
		port = (int) fileno;
		port--;
		if((port < 0) || (port > maxfiles))     /* if it's out of range, abort */
			{
				strcpy(xstring, "Invalid File Number:\n1 to 99:");
				a_bort(ab_code, x);
			}
			else if(fp[port].path[0] == '\0')
			{
				strcpy(xstring, "File Handle is Closed.\n");	/* if path[0]==\0, it's closed */
				a_bort(ab_code, x);		/* if closed, abort */
			}
		handle = fp[port].fptr;
		bool = feof(handle);
		return bool;
	}

