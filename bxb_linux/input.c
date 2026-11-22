/* bxbasic:  bxreq.c  */


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

int get_vtype(int pi)
{   char ch;
    int type=0;

    ch = p_string[pi];
    while(isalnum(ch))
    {   pi++;
        ch = p_string[pi];
    }
    if(ch == '$')
    {   type = 3;			/* a string variable */
    }
    else if(strchr(" =<>%!#", ch))
    {   type = 1;			/* a numeric variable */
    }
    return type;
}
/*------- end get_vtype --------*/

void line_cnt(char *argv[])
{   int pi, len, ii=0, x=0;
    int ab_code=2;
    unsigned fnam_len;

    nrows = 0;
/* --- get length of command line argument --- */
    fnam_len = strlen(argv[1]);
    len = fnam_len;
    fnam_len += 5;                      /* add padding */
    prog_name = malloc(fnam_len * sizeof(char));
    strcpy(prog_name, argv[1]);

/* --- does source filename end in: .bas --- */
    pi = (len-4);
    for(; pi < len; pi++)
    {   p_string[ii] = prog_name[pi];
        ii++;
    }
    if(strcmp(p_string, ".bas") != 0)         /* if not, add it */
    {   strcat(prog_name, ".bas");
    }
    p_string[0] = '\0';
    strcpy(s_holder, prog_name);

/* --- open filename.bas for Read --- */
    f_in = fopen(prog_name,"r");
    if(f_in == NULL)                /* error:file not found */
    {   a_bort(ab_code, x);
    }
    else
    {   load_src();            /* read source-file, write temp-file */
        loader_1();            /* read temp-file, load temp arrays */
        loader_2();            /* load program arrays */
        free(prog_name);
        x = remove("source.tmp");   /* if test is '0', successful */
    }
}
/*------- end line_cnt ----------*/

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
void load_src()
{   char *tmp="source.tmp";
    int pi, len;

    f_out = fopen(tmp,"w");                     /* open output file */
    while(!feof(f_in))
    {   fgets(p_string, BUFSIZE, f_in);
        pi = 0;
        pi = iswhite(pi);
        len = strlen(p_string);
        if((len > 2) && (pi < len))        /* skip over blank lines */
        {   if(!feof(f_in))
            {   save_tmp();                /* write data to file */
            }
        }
    }
    fclose(f_in);
    fclose(f_out);
}
/*------- end load_src ----------*/
void save_tmp()
{   char ch;
    int pi, len;

/* --- setup xstring to write indented line --- */
    strcpy(xstring, "  ");
    strcat(xstring, p_string);
    pi = 0;
    ch = p_string[pi];

/* --- test for a Label: --- */
    if(isupper(ch) != 0)
    {   len = (LLEN-2);
        while(isalnum(ch) != 0)             /* loop thru "Label:" */
        {   pi++;
            ch = p_string[pi];
        }
        if((ch == ':') && (pi <= len))
        {   pi++;
            p_string[pi] = '\0';
            strcat(p_string, "\n\0");
            fprintf(f_out,"%s", p_string);     /* write block label */
            nrows++;
        }
        else
        {   fprintf(f_out,"%s", xstring);    /* write indented line */
            nrows++;
        }
    }

/* --- test for numbered line --- */
    else if(isdigit(ch))
    {   fprintf(f_out,"%s", p_string);        /* write numbered line */
        nrows++;
    }
    else
    {   pi = iswhite(pi);
        ch = p_string[pi];
        if(ch != '\'')                 /* eliminate comment lines */
        {   fprintf(f_out,"%s", xstring);  /* write indented line */
            nrows++;
        }
    }
}

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
void loader_1()
{   char ch, ln_holder[LLEN];
    char *tmp="source.tmp";
    int ii, len, pi;
    unsigned size=ncolumns;

/* --- create temp arrays --- */
    temp_prog = malloc(nrows * sizeof(char *));
    for(ii = 0; ii < nrows; ii++)
    {   temp_prog[ii] = malloc(size * sizeof(char));
    }
    temp_label = malloc(nrows * sizeof(char *));
    for(ii = 0; ii < nrows; ii++)
    {   temp_label[ii] = malloc(LLEN * sizeof(char));
    }
    temp_byte = malloc(nrows * sizeof(int));

/* --- open source.tmp for Read --- */
    f_in = fopen(tmp,"r");
    ii = 0;
    while(!feof(f_in))             /* p_string holds incoming-data */
    {   fgets(p_string, BUFSIZE, f_in);
        if(!feof(f_in))
        {   len = strlen(p_string);

         /* ----- fill temp_label[] here ----- */
            tmp_label(ii);               /* call label filter */
            pi = e_pos;
            ch = p_string[pi];
            if(ch == ':')                       /* found a label */
            {   temp_byte[ii] = -1;
                strcpy(temp_prog[ii], "\n\0");
            }

         /* ----- fill temp_byte[] here ----- */
            else
            {   tmp_byte(ii);            /* call byte filter */
                tmp_prog(ii);
            }
        }
        ii++;
    }
    fclose(f_in);
}
/*---------- end loader_1 ----------*/
void loader_2()
{   int ndx, ii, line_count=0, lines=nrows;
    unsigned size;

/* --- re-count number of lines --- */
    for(ndx=0; ndx < nrows; ndx++)
    {   if(temp_byte[ndx] != 0)
        {   line_count++;
        }
        if((temp_byte[ndx] == 13) || (temp_byte[ndx] == 14))
        {   token_if(ndx);		/* tokenize expression */
        }
        else if(temp_byte[ndx] == 1)
        {   str_functn(ndx);	  /* tokenize string functions */
        }
        else if(temp_byte[ndx] == 4)
        {   str_funct2(ndx);	  /* tokenize string functions */
        }
    }
    nrows = line_count;

/* --- create program arrays --- */
    array1 = malloc(nrows * sizeof(char *));
    label_nam = malloc(nrows * sizeof(char *));
    for(ii = 0; ii < nrows; ii++)
    {   label_nam[ii] = malloc(LLEN * sizeof(char));
    }
    byte_array = malloc(nrows * sizeof(int));

/* --- transfer temp_arrays to program_arrays --- */
    ndx = 0;
    for(ii=0; ii < lines; ii++)
    {   if(temp_byte[ii] != 0)
        {   strcpy(label_nam[ndx], temp_label[ii]);
            byte_array[ndx] = temp_byte[ii];
        /**/
            size = strlen(temp_prog[ii]);
            size++;
            array1[ndx] = malloc(size * sizeof(char));
            strcpy(array1[ndx], temp_prog[ii]);
            ndx++;
        }
    }

/* --- free temp array memory --- */
    for(ii=0; ii < lines; ii++)
    {   free(temp_label[ii]);
        free(temp_prog[ii]);
    }
    free(temp_label);
    free(temp_byte);
    free(temp_prog);
}
/*---------- end loader_2 ----------*/
void tmp_label(int ii)
{   char ch, ln_label[LLEN];
    int pi;

/* ----- fill temp_label[] here ----- */
    pi = 0;
    ch = p_string[pi];
    if(isalnum(ch))
    {   while(isalnum(ch))
        {   ln_label[pi] = ch;
            pi++;
            ch = p_string[pi];
        }
        ln_label[pi] = '\0';
        strcpy(temp_label[ii], ln_label);
    }
    else
    {   strcpy(temp_label[ii], " \0");
    }
    e_pos = pi;
}
/*---------- end tmp_label ----------*/
void tmp_byte(int ii)
{   char ch;
    int pi, si, byte;
    int x=ii, ab_code=4;

/* ----- fill temp_byte[] here ----- */
    pi = e_pos;
    pi = iswhite(pi);
    ch = p_string[pi];
    if(ch == '\'')                  /* it's a comment */
    {   byte = 0;
        strcpy(temp_prog[ii], "\n\0");
    }
    else
    {   if(isupper(ch))              /* is this a keyword */
        {   e_pos = pi;
            byte = get_byte(ii);      /* call get_byte */
            pi = e_pos;
        }
        else if(isalpha(ch))          /* a possible assignment */
        {   si = pi;                 /* save pointer position */
            while(isalnum(ch))
            {   pi++;
                ch = p_string[pi];
            }
            pi = iswhite(pi);
            ch = p_string[pi];
            if(strchr("=#%!$", ch))      /* a variable assignment */
            {   byte = 1;
                get_MOD(pi);         /* scan for a MOD expression */
                pi = si;
            }
            else
            {   a_bort(ab_code, x);       /* not an assignment */
            }
        }
        else 
        {   a_bort(ab_code, x);    /* not a keyword or variable */
        }
    }
    temp_byte[ii] = byte;
    e_pos = pi;
}
/*---------- end tmp_byte ----------*/
void tmp_prog(int ii)
{   char ch, prog[BUFSIZE];
    int pi, si=0, len;

    len = strlen(p_string);
    pi = e_pos;
    pi = iswhite(pi);

/* --- correct: LINE INPUT --- */
    if(temp_byte[ii] == 18)
    {   ch = p_string[pi];
        while(isupper(ch))
        {   pi++;		/* advance past INPUT */
            ch = p_string[pi];
        }
        pi = iswhite(pi);
        ch = p_string[pi];
        while(ch != '\0')
        {   prog[si] = ch;
            si++;
            pi++;
            ch = p_string[pi];
        }
        prog[si] = '\0';
    }
    else if((pi < len) && (temp_byte[ii] != 0))
    {   ch = p_string[pi];
        while(ch != '\0')
        {   prog[si] = ch;
            si++;
            pi++;
            ch = p_string[pi];
        }
        prog[si] = '\0';
    }
    else
    {   strcpy(prog, "\n\0");
    }
    strcpy(temp_prog[ii], prog);
}
/*---------- end tmp_prog ----------*/
void token_if(int ndx)
{   char temp[TOKEN_LEN];
    int loc;

    strcpy(p_string, temp_prog[ndx]);
    s_pos = 0;
    strcpy(temp, "AND");
    loc = 0;
    while(loc >= 0)
    {   loc = find_strng(temp);
        loc--;
        if(loc > 0)
        {   p_string[loc] = '&';          /* replace AND w/token */
            p_string[(loc+1)] = ' ';
            p_string[(loc+2)] = ' ';
        }
    }
    strcpy(temp, "OR");
    loc = 0;
    while(loc >= 0)
    {   loc = find_strng(temp);
        loc--;
        if(loc > 0)
        {   p_string[loc] = '|';          /* replace OR w/token */
            p_string[(loc+1)] = ' ';
        }
    }
    strcpy(temp, "THEN");
    loc = 0;
    while(loc >= 0)
    {   loc = find_strng(temp);
        loc--;
        if(loc > 0)
        {   p_string[loc] = '\n';          /* replace THEN w/EOL */
            p_string[(loc+1)] = '\0';
        }
    }
    strcpy(temp_prog[ndx], p_string);
}
/*---------- end token_if ----------*/
void str_functn(int ndx)
{   char ch, temp[VAR_NAME]; 	    /* tokenize string functions */
    int pi=0, len;

    strcpy(p_string, temp_prog[ndx]);
    while(IsEqu(pi) == 0)		/* advance to '=' sign */
    {   pi = e_pos;
        pi++;
    }
    pi = e_pos;			/* leave this, IsEqu() changes e_pos */
    len = strlen(p_string);
/* --- loop --- */
    while(pi < len)
    {   pi = get_upper(pi, len);	/* advance to uppercase */
        if(pi < len)
        {   e_pos = pi;
            strcpy(temp, get_varname());	/* get varname */
            s_pos = e_pos;
            ch = p_string[s_pos];
            if(ch == '$')			/* valid '$' symbol */
            {   e_pos = pi;
                get_strfunc(temp,ndx);		/* identify function */
            }
            else
            {   e_pos = pi;
                get_mathfunc(temp,ndx);	   /* identify math function */
            }
            pi = e_pos;
            pi++;
        }
    }
}
/*---------- end str_functn ----------*/
void str_funct2(int ndx)
{   char ch, temp[VAR_NAME]; 	    /* tokenize string functions */
    int pi=0, len;		    /* Print */

    strcpy(p_string, temp_prog[ndx]);
    len = strlen(p_string);
/* --- loop --- */
    while(pi < len)
    {   pi = get_upper(pi, len);	/* advance to uppercase */
        if(pi < len)
        {   e_pos = pi;
            strcpy(temp, get_varname());	/* get varname */
            s_pos = e_pos;
            ch = p_string[s_pos];
            if(ch == '$')		/* valid '$' symbol */
            {   e_pos = pi;
                get_strfunc(temp,ndx);	  /* identify function */
            }
            else
            {   e_pos = pi;
                get_mathfunc(temp,ndx);	  /* identify math function */
            }
            pi = e_pos;
            pi++;
        }
    }
}
/*---------- end str_funct2 ----------*/
int get_byte(int ii)
	{
		char ch, keyword[TOKEN_LEN];
		int pi, si=0, byte;
		int x=ii, ab_code=4;

		pi = e_pos;
		ch = p_string[pi];
		while(isalnum(ch))
			{
				keyword[si] = ch;
				si++;
				pi++;
				ch = p_string[pi];
			}
		keyword[si] = '\0';

		/* --- assign byte code --- */
		if(strcmp(keyword, "REM") == 0)         byte=0;
			else if(strcmp(keyword, "LET") == 0)
				{
					byte=1;  
					get_MOD(pi);
				}        /* scan for a MOD expression */
			else if(strcmp(keyword, "CLEAR") == 0)  byte=2;
			else if(strcmp(keyword, "LOCATE") == 0) byte=3;
			else if(strcmp(keyword, "PRINT") == 0)  byte=4;
			else if(strcmp(keyword, "GOTO") == 0)   byte=5;
			else if(strcmp(keyword, "BEEP") == 0)   byte=6;
			else if(strcmp(keyword, "CLS") == 0)    byte=7;
			else if(strcmp(keyword, "END") == 0)    byte=8;
			else if(strcmp(keyword, "GOSUB") == 0)  byte=9;
			else if(strcmp(keyword, "RETURN") == 0) byte=10;
			else if(strcmp(keyword, "FOR") == 0)    byte=11;
			else if(strcmp(keyword, "NEXT") == 0)   byte=12;
			else if(strcmp(keyword, "IF") == 0)     byte=13;
			else if(strcmp(keyword, "ELSEIF") == 0) byte=14;
			else if(strcmp(keyword, "ELSE") == 0)   byte=15;
			else if(strcmp(keyword, "ENDIF") == 0)  byte=16;
			else if(strcmp(keyword, "INPUT") == 0)  byte=17;
			else if(strcmp(keyword, "LINE") == 0)   byte=18;
			else if(strcmp(keyword, "OPEN") == 0)   byte=19;
			else if(strcmp(keyword, "CLOSE") == 0)  byte=20;
			else if(strcmp(keyword, "WRITE") == 0)  byte=21;
			else if(strcmp(keyword, "FIELD") == 0)      byte=22;
			else if(strcmp(keyword, "LSET") == 0)       byte=23;
			else if(strcmp(keyword, "RSET") == 0)       byte=24;
			else if(strcmp(keyword, "PUT") == 0)        byte=25;
			else if(strcmp(keyword, "GET") == 0)        byte=26;
			else if(strcmp(keyword, "STOP") == 0)       byte=27;
			else if(strcmp(keyword, "SYSTEM") == 0)     byte=28;
			else if(strcmp(keyword, "COLOR") == 0)      byte=29;
			else if(strcmp(keyword, "RANDOM") == 0)     byte=30;
			else if(strcmp(keyword, "KILL") == 0)       byte=31;
			else if(strcmp(keyword, "SHELL") == 0)      byte=32;
			else if(strcmp(keyword, "SLEEP") == 0)      byte=34;
			else if(strcmp(keyword, "DIM") == 0)        byte=35;
			else if(strcmp(keyword, "DECLARE") == 0)    byte=36;
			else if(strcmp(keyword, "CALL") == 0)       byte=37;
			else if(strcmp(keyword, "SUB") == 0)        byte=38;
			else if(strcmp(keyword, "ENDSUB") == 0)     byte=39;
			else if(strcmp(keyword, "ERASE") == 0)      byte=43;
			else if(strcmp(keyword, "FMCLOSE") == 0)    byte=44;
			

			else
				{
					pi = iswhite(pi);
					ch = p_string[pi];
					if(strchr("=#%!$(", ch))          /* a variable assignment */
						{
							byte = 1;
							get_MOD(pi);             /* scan for a MOD expression */
							pi = e_pos;              /* push pointer back */
						}
					else
						{
							a_bort(ab_code, x); /* not a keyword or variable */
						}
				}
			e_pos = pi;
			return byte;
	}
/*---------- end get_byte ----------*/
void get_MOD(int pi)
{   char ch, temp[VAR_NAME];
    int i, si=0, xi, len;

    len = strlen(p_string);
    pi++;
    pi = iswhite(pi);
    ch = p_string[pi];
    while( pi < (len - 2))
    {   if(ch == 'M')                        /* is this a MOD */
        {   si = pi;
            i = 0;
            while(isalnum(ch))
            {   temp[i] = ch;
                pi++;
                i++;
                ch = p_string[pi];
            }
            temp[i] = '\0';
            if(strcmp(temp, "MOD") == 0)   /* compare(temp,"MOD") */
            {   p_string[si] = '%';
                si++;
                xi = si;                    /* save si pointer */
                while(pi < len)             /* squeeze p_string */
                {   p_string[si] = p_string[pi];
                    pi++;
                    si++;
                }
                p_string[si] = '\0';
                pi = xi;                    /* restore pi */
            }
            pi++;
        }
        else
        {   pi++;
        }
        ch = p_string[pi];
    }
}
/*---------- end get_MOD ----------*/

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
int IsEqu(int pi)
{   char ch;			/* is equal sign */
    int bool=0;

    pi = iswhite(pi);
    e_pos = pi;
    ch = p_string[pi];
    if(ch == '=')
    {   bool = 1;
    }
    return bool;
}
/*---------- end IsEqu ----------*/
void get_strfunc(char *name,int ndx)		/* identify function */
	{
		char varname[VAR_NAME], temp[TOKEN_LEN];
		strcpy(varname, name);
		temp[0] = '\0';

/* --- now compare to functions --- */
		if(strcmp(varname, "CHR") == 0)
			{
				strcpy(temp, "   1");	    /* is this a chr$(n) assnmnt */
			}
			else if(strcmp(varname, "LEFT") == 0)
			{
				strcpy(temp, "    2");	        /* a left$(a$,n) assnmnt */
			}
			else if(strcmp(varname, "RIGHT") == 0)
			{
				strcpy(temp, "     3");	       /* a right$(a$,n) assnmnt */
			}
			else if(strcmp(varname, "MID") == 0)
			{
				strcpy(temp, "   4");	       /* a mid$(a$,s,n) assnmnt */
			}
			else if(strcmp(varname, "SPACE") == 0)
			{
				strcpy(temp, "     5");	          /* a space$(n) assnmnt */
			}
			else if(strcmp(varname, "STR") == 0)
			{
				strcpy(temp, "   6");	            /* a str$(x) assnmnt */
			}
			else if(strcmp(varname, "STRING") == 0)
			{
				strcpy(temp, "      7");       /* a string$(n,a) assnmnt */
			}
			else if(strcmp(varname, "INKEY") == 0)
			{
				strcpy(temp, "     8");             /* an inkey$ assnmnt */
			}
			else if(strcmp(varname, "INPUT") == 0)
			{
				strcpy(temp, "     9");             /* an input$ assnmnt */
			}
			else if(strcmp(varname, "MKD") == 0)
    			{   strcpy(temp, "  10");                   /* a MKD$ assnmnt */
			}
			else if(strcmp(varname, "MKI") == 0)
			{   strcpy(temp, "  11");                   /* a MKI$ assnmnt */
			}
			else if(strcmp(varname, "MKS") == 0)
			{   strcpy(temp, "  12");                   /* a MKS$ assnmnt */
			}
			else if(strcmp(varname, "UCASE") == 0)
			{   strcpy(temp, "    13");                 /* a UCASE$ assnmnt */
			}
			else if(strcmp(varname, "LCASE") == 0)
			{   strcpy(temp, "    14");                 /* a LCASE$ assnmnt */
			}

		str_copy(temp,ndx);		/* replace function name w/token */
	}
/*---------- end get_strfunc ----------*/
void get_mathfunc(char *name,int ndx)	/* identify math function */
{   char varname[VAR_NAME], temp[TOKEN_LEN];

    strcpy(varname, name);
    temp[0] = '\0';

/* --- now compare to functions --- */
 if(strcmp(varname, "ABS") == 0)
    {   strcpy(temp, " ?1");                    /* a abs(n) assnmnt */
    }
    else if(strcmp(varname, "ASC") == 0)
    {   strcpy(temp, " ?2");		        /* a asc(a$) assnmnt */
    }
    else if(strcmp(varname, "ATN") == 0)
    {   strcpy(temp, " ?3");                    /* a atn(n) assnmnt */
    }
    else if(strcmp(varname, "COS") == 0)
    {   strcpy(temp, " ?4");                    /* a cos(n) assnmnt */
    }
    else if(strcmp(varname, "SIN") == 0)
    {   strcpy(temp, " ?5");                    /* a sin(n) assnmnt */
    }
    else if(strcmp(varname, "TAN") == 0)
    {   strcpy(temp, " ?6");                    /* a tan(n) assnmnt */
    }
    else if(strcmp(varname, "SQRT") == 0)
    {   strcpy(temp, "  ?7");		        /* a sqrt(n) assnmnt */
    }
    else if(strcmp(varname, "INT") == 0)
    {   strcpy(temp, " ?8");                    /* a int(n) assnmnt */
    }
    else if(strcmp(varname, "LEN") == 0)
    {   strcpy(temp, " ?9");                    /* a len($) assnmnt */
    }
    else if(strcmp(varname, "LOF") == 0)
    {   strcpy(temp, "?10");                    /* a lof(n) assnmnt */
    }
    else if(strcmp(varname, "LOC") == 0)
    {   strcpy(temp, "?11");                    /* a loc(n) assnmnt */
    }
    else if(strcmp(varname, "CVD") == 0)
    {   strcpy(temp, "?12");                    /* a cvd($) assnmnt */
    }
    else if(strcmp(varname, "CVI") == 0)
    {   strcpy(temp, "?13");                    /* a cvi($) assnmnt */
    }
    else if(strcmp(varname, "CVS") == 0)
    {   strcpy(temp, "?14");                    /* a cvs($) assnmnt */
    }
    else if(strcmp(varname, "VAL") == 0)
    {   strcpy(temp, "?15");                    /* a val($) assnmnt */
    }
    else if(strcmp(varname, "CLOCK") == 0)
    {   strcpy(temp, "  ?16");                  /* a clock assnmnt */
    }
    else if(strcmp(varname, "RAND") == 0)
    {   strcpy(temp, " ?17");                   /* a rand assnmnt */
    }
    else if(strcmp(varname, "LOG") == 0)
    {   strcpy(temp, "?18");                    /* a log assnmnt */
    }
    else if(strcmp(varname, "LOG10") == 0)
    {   strcpy(temp, "  ?19");                  /* a log10 assnmnt */
    }
    str_copy(temp,ndx);		/* replace function name w/token */
}
/*---------- end get_mathfunc ----------*/
void str_copy(char *temp,int ndx)
{   char ch, tok[TOKEN_LEN];	/* replace function name w/token */
    int pi, si=0;

    strcpy(tok, temp);
    pi = e_pos;
    ch = tok[si];
    if(ch != '\0')
    {   while(ch != '\0')
        {   p_string[pi] = ch;
            si++;
            pi++;
            ch = tok[si];
        }
        strcpy(temp_prog[ndx], p_string);
        e_pos = pi;
    }
    else
    {   e_pos = s_pos;		/* not a function */
    }
}
/*---------- end str_copy ----------*/

void beep()
{   printf("%c", 7);
}
/*-------------------------------*/


