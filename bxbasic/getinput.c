  
/*  Getinput.c  */

void get_input()
{   
    char ch, varname[VAR_NAME];
    int pi, len, type, loc=0;
    int ab_code=19, x=line_ndx;

    pi = e_pos;
    ch = p_string[pi];

    if(ch == '#')		
    {
/*	input_io(); */
	return;
    }

    if(ch == ';')		
    {   
        loc = 1;
        pi++;
        pi = iswhite(pi);
        ch = p_string[pi];
        e_pos = pi;
    }

    len = strlen(p_string);

    while(pi < len)                       
    {   
        if(ch == '\"')          	
        {   
            get_prnstring();
            pi = e_pos;
            pi++;
            pi = iswhite(pi);
            ch = p_string[pi];
            e_pos = pi;
        }
        else 
        {
            if(isalpha(ch))
            {
              type = get_vtype(pi);
              strcpy(varname, get_varname());
            }

            if(type == 3)       	
            {   
                input_str(varname,loc);
                pi = e_pos;
                ch = p_string[pi];
            }
            else  		 
            {   
                input_val(varname,loc);
                pi = e_pos;
                ch = p_string[pi];
            }
        }
/*        else   */
/*        {      */
/*         a_bort(ab_code, x);  */
/*        }      */
    }
}


void get_lninput()
{   
    char ch, varname[VAR_NAME];
    int pi, loc=0;

    pi = e_pos;
    ch = p_string[pi];

    if(ch == ';')		
    {   
        loc = 1;
        pi++;
        pi = iswhite(pi);
        ch = p_string[pi];
        e_pos = pi;
    }

    if(ch == '\"')          	
    {   
        get_prnstring();
        pi = e_pos;
        pi++;
        pi = iswhite(pi);
        ch = p_string[pi];
        e_pos = pi;
    }
    strcpy(varname, get_varname());
    input_str(varname,loc);
}


void input_str(char *name, int loc)
{   
    char ch, varname[VAR_NAME], string[BUFSIZE];
    int pi, ndx, len, row, col;
    int xsize;

    strcpy(varname, name);
 
    ndx = get_varndx(varname);

    gets(string);
     
/* --- store data --- */
    xsize = strlen(string);
    xsize++;
    sv_stack[ndx] = realloc(sv_stack[ndx], xsize * sizeof(char));
    strcpy(sv_stack[ndx], string); 

    pi = e_pos;
    pi++;
    ch = p_string[pi];
    if(strchr(":;,", ch))
    {   
        pi++;
 
    }
    pi = iswhite(pi);
    e_pos = pi;
}


void input_val(char *name, int loc)
{   
    char ch, cx;
    char varname[VAR_NAME];
    char string[VAR_NAME];

    int pi;
    int ndx;
    int len, row, col;
    int process = 0;

    strcpy(varname, name);
    pi = e_pos;
    ch = p_string[pi];

    gets(string);
    len = strlen(string);

    if(ch == '#')
    {   
        ndx = get_varndx(varname);
     /*   dv_stack[ndx] = atof(string); */
        pi++;
        process = 1;
    }

    if((ch == '!') && (process == 0))
    {   
        ndx = get_varndx(varname);
 /*       fv_stack[ndx] = atof(string); */
        pi++;
        process = 1;
    }

    if((ch == '%') && (process == 0))
    {   
        ndx = get_varndx(varname);
        lv_stack[ndx] = atol(string);
        pi++;
        process = 1;
    }

    if(process == 0)
    {   
        ndx = get_varndx(varname);
        iv_stack[ndx] = atoi(string);
    }

    pi = iswhite(pi);
    ch = p_string[pi];
    if(strchr(":;,", ch))
    {   
       pi++;
       		
    }
    pi = iswhite(pi);
    e_pos = pi;



}
