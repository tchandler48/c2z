
void get_lninput()
{   
  char ch;
  char varname[VAR_NAME];
  int pi;
  int loc=0;

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


void get_input()
{   
  char ch;
  char varname[VAR_NAME];
  int pi;
  int len;
  int type;
  int loc=0;
  int ab_code=19;
  int x=line_ndx;

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
    e_pos = pi;
    if(isalpha(ch))
    {
      type = get_vtype(pi);
      e_pos = pi;
      strcpy(varname, get_varname());
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
    else
    {
      a_bort(ab_code, x);
    }
  }
}


void input_val(char *name, int loc)
{   
  char ch;
  char cx;
  char varname[VAR_NAME];
  char string[VAR_NAME];
  int pi;
  int ndx;
  int len;
  int row, col;

  strcpy(varname, name);
  pi = e_pos;
  ch = p_string[pi];

  if(loc == 1)
  {
    gets(string);
    len = strlen(string);
    reset_cursor(loc,len,col,row);
  }
  else
  {
    gets(string);
  }
  
  if(ch == '#')
  {
    ndx = get_varndx(varname);
    dv_stack[ndx] = atof(string);
    pi++;
  }
 
  else if(ch == '!')
  {
    ndx = get_varndx(varname);
    fv_stack[ndx] = atof(string);
    pi++;
  }

  else if(ch == '%')
  { 
    ndx = get_varndx(varname);
    lv_stack[ndx] = atol(string);
    pi++;
  }
  
  else
  {
    ndx = get_varndx(varname);
    iv_stack[ndx] = atoi(string);
  }
  pi = iswhite(pi);
  ch = p_string[pi];
  if(strchr(":;,", ch))
  {
    pi++;
    set_TabNl(ch);			
  }
  pi = iswhite(pi);
  e_pos = pi;
}


void input_str(char *name, int loc)
{   
  char ch;
  char varname[VAR_NAME];
  char string[BUFSIZE];
  int pi;
  int ndx;
  int len;
  int row;
  int col;
  int xsize;

  strcpy(varname, name);

  ndx = get_varndx(varname);

  if(loc == 1)
  {
    gets(string);
    len = strlen(string);
    reset_cursor(loc,len,col,row);
  }
  else
  {
     gets(string);
  }

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
    set_TabNl(ch);			
  }
  pi = iswhite(pi);
  e_pos = pi;
}

