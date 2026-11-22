/* bxbasic : Strings.c : alpha version */
/* ----- includes ----- */
#include "prototyp.h"

void parse_strarry(char *name)
{
    char ch, temp[BUFSIZE], varname[VAR_NAME];
    int pi, len, indx, param, offset;
    unsigned size;

    strcpy(varname, name);
    indx = get_arrayndx(varname);
    len = strlen(p_string);
    pi = e_pos;
    pi = get_paren(pi, len);
    pi++;
    e_pos = pi;
    param = strArry[indx].dim;
    offset = get_offset(param, len);
    pi = e_pos;
    pi++;
    pi = iswhiter(pi);
    e_pos = pi;

/* --- now get assignment string --- */
    Match('=');
    strcpy(temp, str_express());

/* --- make string assignment --- */
    size = strlen(temp);
    size++;
    strArry[indx].elem[offset] = realloc(strArry[indx].elem[offset], size * sizeof(char));
    strcpy(strArry[indx].elem[offset], temp);
    
}


void parse_str(char *name)
{   char ch, varname[VAR_NAME], temp[BUFSIZE];
    int pi, ndx;
    unsigned size;

    strcpy(varname, name);
    nam_stack = sn_stack;    /* indirect reference to name_stack */
    max_vars = smax_vars;
    init_fn = init_str;        /* indirect reference to function */
    ndx = get_varndx(varname);
    pi = e_pos;
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
/* --- now get assignment string --- */
    Match('=');
    strcpy(temp, str_express());

/* --- make string assignment --- */
    size = strlen(temp);
    size++;
    sv_stack[ndx] = realloc(sv_stack[ndx], size * sizeof(char));
    strcpy(sv_stack[ndx], temp);
}
/*---------- end parse_str ----------*/

char *str_express()
{   char ch;
    static char temp[BUFSIZE];
    int pi, len;

    temp[0] = '\0';
    len = strlen(p_string);
    pi = e_pos;
    while(pi < len)
    {   ch = p_string[pi];
        if(ch == '\"')
        {   strng_assgn();		/* quotes string */
        }
        else if(isdigit(ch))
        {   asn_function();		/* string function */
        }
        else
        {   strvar_assgn();		/* copy variable */
        }
        strcat(temp, s_holder);		/* concatenate */
        pi = e_pos;
        pi++;
        pi = iswhite(pi);
        e_pos = pi;
        if(pi < len)
        {   Match('+');			/* concatenate symbol */
            pi = e_pos;
        }
    }
    return temp;
}
/*---------- end str_express ----------*/


void asn_function()
	{
		int type;

		type = (int) get_avalue();
		switch(type)
			{
				case 1:
					chrstr();		/* a$ = CHR$(n) */
					break;
				case 2:
					leftstr();		/* a$ = LEFT$(x$,n) */
					break;
				case 3:
					rightstr();		/* a$ = RIGHT$(x$,n) */
					break;
				case 4:
					midstr();		/* a$ = MID$(x$,n,n) */
					break;
				case 5:
					spacestr();		/* a$ = SPACE$(n) */
					break;
				case 6:
					strsval();		/* a$ = STR$(n) */
					break;
				case 7:
					stringstr();		/* a$ = STRING$(n,c) */
					break;
				case 8:
					inkeystr();		/* a$ = INKEY$ */
					break;
				case 9:
					inputstr();		/* a$ = INPUT$(n) */
					break;
				default:
					/* error */
					break;
			}
	}
/*---------- end asn_function ----------*/


void inputstr()
	{
		char ch;
		int pi, count, i, len;

		pi = e_pos;                      /* pi enters pointing to: (n) */
		pi++;                            /* advance to number: n) */
		e_pos = pi;

/* --- get count --- */
		count = (int) get_avalue();

/* --- zero s_holder --- */
		for(i=0; i <= count; i++)
			{
				s_holder[i] = '\0';
			}
		i = 0;
		while(i < count)
			{
				#ifdef Windows
					ch = getche();
            			#endif
				#ifdef Linux
					ch = getchar();
            			#endif
				if((ch > 31) && (ch < 127))	/* ascii chars */
					{
						s_holder[i] = ch;
						i++;
					}
				else if((ch == 8) && (i > 0))	/* backspace */
					{
						s_holder[i] = '\0';
						i--;
					}
			}
		s_holder[count] = '\0';
	}
/*---------- end inputstr ----------*/

void inkeystr()
	{
		char ch;
		int chr;
		#ifdef Windows
			chr = kbhit();
		#endif
		#ifdef Linux
	/*		ch =  */
       	#endif
		if(chr == 0)
			{
				s_holder[0] = '\0';
			}
			else
			{
				#ifdef Windows
					ch = getch();
				#endif
				#ifdef Linux
					ch = getchar();
       			#endif
				if(ch == 0)
					{
						s_holder[0] = ' ';
						#ifdef Windows
							ch = getch();
						#endif
						#ifdef Linux
							ch = getchar();
       					#endif
						s_holder[1] = ch;
						s_holder[2] = '\0';
					}
					else
					{
						s_holder[0] = ch;
						s_holder[1] = '\0';
					}
			}
	}
/*---------- end inkeystr ----------*/

void stringstr()
{   char ch, char_x, quote='\"';
    int ii, pi, count;
    long xxx;

    pi = e_pos;            /* pi enters pointing to: (num, chr) */
    pi++;                 /* advance to first number: num, chr) */
    pi = iswhite(pi);
    e_pos = pi;
/* --- get count --- */
    count = (int) get_avalue();
    if(count < 1)
    {   count = 0;
    }
    else if(count > 255)
    {   count = 255;
    }
    pi = e_pos;                /* pi re-enters pointing to: ,chr) */
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
    ch = p_string[pi];
/* --- get character --- */
    if(ch == quote)               /* is it a quoted char: "*") */
    {   pi++;
        ch = p_string[pi];
        char_x = ch;
        while(ch != ')')           /* advance to paren */
        {   pi++;
            ch = p_string[pi];
        }
        e_pos = pi;
    }
    else 
    {	xxx = (long) get_avalue();
        char_x = xxx;
    }
    for(ii=0; ii < count; ii++)
    {   s_holder[ii] = char_x;
    }
    s_holder[count] = '\0';
}
/*---------- end stringstr ----------*/

void strsval()
{   char ch;
    int pi;
    double value;

    pi = e_pos;               /* pi enters pointing to: (abc) */
    pi++;                     /* advance to first alpha: abc) */
    pi = iswhite(pi);
    e_pos = pi;
/* --- get value --- */
    value = get_avalue();

/* --- convert value to string --- */
    strcpy(s_holder, value2strng(value));
}
/*---------- end strsval ----------*/

void spacestr()
{   char space=32;
    int ii, pi, count;

    pi = e_pos;               /* pi enters pointing to: (n) */
    pi++;                  /* advance to first alpha/num: n) */
    pi = iswhite(pi);
    e_pos = pi;
/* --- get count --- */
    count = (int) get_avalue();
    if(count < 1)
    {   count = 0;
    }
    else if(count > 255)
    {   count = 255;
    }
    for(ii=0; ii < count; ii++)
    {   s_holder[ii] = space;
    }
    s_holder[count] = '\0';
}
/*---------- end spacestr ----------*/

void midstr()
{   char ch;
    int ii, pi, indx, count, len, left;

    pi = e_pos;                 /* pi enters pointing to: ( */
    pi++;                   /* advance to first alpha: a$,s,n) */
    pi = iswhite(pi);
    e_pos = pi;
/* --- get string index --- */
    indx = get_strndx();
    pi = e_pos;              /* pi re-enters pointing to: $,s,n) */
    pi += 2;                  /* advance to first al/num: s,n) */
    pi = iswhite(pi);
    e_pos = pi;
/* --- get left start point --- */
    left = (int) get_avalue();
    pi = e_pos;              	/* pi re-enters pointing to: ,n) */
    pi = iswhite(pi);           /* -or- pointing to: ) */
    ch = p_string[pi];
    e_pos = pi;
    if(ch == ')')
    {   count = 255;		/* force it to upper limit */
    }
    else
    {   pi++;                 /* advance to first alpha/num: n) */
        pi = iswhite(pi);
        e_pos = pi;
    /* --- get count --- */
        count = (int) get_avalue();
    }
    if(count < 1)
    {   count = 0;
    }
    len = strlen(sv_stack[indx]);
    left--;		    		/* correct string[index] */
    if((left + count) > len)
    {   count = (len - left);
    }
    for(ii=0; ii < count; ii++, left++)
    {   s_holder[ii] = sv_stack[indx][left];
    }
    s_holder[count] = '\0';
}
/*---------- end midstr ----------*/

void rightstr()
{   int ii, pi, indx, count, len, left;

    pi = e_pos;                 /* pi enters pointing to: ( */
    pi++;                   /* advance to first alpha: a$,n) */
    pi = iswhite(pi);
    e_pos = pi;
/* --- get string index --- */
    indx = get_strndx();
    pi = e_pos;              /* pi re-enters pointing to: $,n) */
    pi += 2;                   /* advance to first digit: n) */
    pi = iswhite(pi);
    e_pos = pi;
/* --- get count --- */
    count = (int) get_avalue();
    if(count < 1)
    {   count = 0;
    }
    len = strlen(sv_stack[indx]);
    if(count > len)
    {   count = len;
    }
    left = (len - count);
    for(ii=0; ii < count; ii++, left++)
    {   s_holder[ii] = sv_stack[indx][left];
    }
    s_holder[count] = '\0';
}
/*---------- end rightstr ----------*/

void leftstr()
{   int i, pi, indx, count, len;

    pi = e_pos;                  /* pi enters pointing to: ( */
    pi++;                    /* advance to first alpha: a$,n) */
    pi = iswhite(pi);
    e_pos = pi;
/* --- get string index --- */
    indx = get_strndx();
    pi = e_pos;               /* pi re-enters pointing to: $,n) */
    pi += 2;                    /* advance to first digit: n) */
    pi = iswhite(pi);
    e_pos = pi;
/* --- get count --- */
    count = (int) get_avalue();
    if(count < 1)
    {   count = 0;
    }
    len = strlen(sv_stack[indx]);
    if(count > len)
    {   count = len;
    }
    for(i=0; i < count; i++)
    {   s_holder[i] = sv_stack[indx][i];
    }
    s_holder[count] = '\0';
}
/*---------- end leftstr ----------*/

void chrstr()
{   int pi;
    long xxxchar;

    pi = e_pos;              /* pi enters pointing to: ( */
    pi++;                    /* advance to alpha/num: 10) */
    pi = iswhite(pi);
    e_pos = pi;
    xxxchar = (long) get_avalue();
    s_holder[0] = (int) xxxchar;
    s_holder[1] = '\0';
}
/*---------- end chrstr ----------*/

void strvar_assgn()
{   int indx;

/* --- get string index --- */
    indx = get_strndx();
    strcpy(s_holder, sv_stack[indx]);
}
/*---------- end strvar_assgn ----------*/

void strng_assgn()
{   char ch, quote='\"';
    int pi, stlen, si=0, ab_code=6, x=line_ndx;

    stlen = strlen(p_string);
    pi = e_pos;                        /* plant "pi" with first quote */
    pi++;
    ch = p_string[pi];

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
    e_pos = pi;
}
/*---------- end strng_assgn ----------*/

int get_strndx()
{   char varname[VAR_NAME];
    int indx=0, ab_code=13, x=line_ndx;

/* --- get string name --- */
    strcpy(varname, get_varname());
    while((indx < smax_vars)&&(strcmp(sn_stack[indx],varname) != 0))
    {   indx++;
    }
    if(indx == smax_vars)              /* error: did not find it */
    {   a_bort(ab_code, x);
    }
    return indx;
}
/*---------- end get_strndx ----------*/

