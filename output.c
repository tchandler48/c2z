
/*	output.c	*/


void beep()
{

}


void cls()
{


}


void parse_print()
{
  char ch;
  int pi;
  int si = 0;
  int stlen;
  int ab_code, x = line_ndx;
  int process;

  pi = e_pos;
  pi = iswhiter(pi);
  ch = p_string[pi];
  e_pos = pi;

  if(ch == ':')
  {
    printf(" \n");
    return;
  }

    process = 0;
    if(isalpha(ch))
    {
      strcpy(s_holder, get_varname());
      pi = e_pos;
      ch = p_string[pi];

      if((ch == '$') && (process == 0))
      {
        pi = 0;
        e_pos = 0;
        get_strvar();
        process = 1;
      }

      if(process == 0)
      { 
        pi = 0;
        e_pos = 0;
        get_prnvar();
        process = 1;
      }
    }

    if(ch == '\"')
    {
      get_prnstring();
      process = 1;
    }
 
}



void get_prnstring()
{
  char ch;
  int pi;
  int si = 0;
  int stlen;
  int ab_code = 6, x = line_ndx;

  stlen = strlen(p_string);
  si = 0;
  pi = e_pos;
  pi++;
  ch = p_string[pi];
 
  while((ch != '\"') && (pi < stlen))
  {
    xstring[si] = ch;
    si++; 
    pi++;
    ch = p_string[pi];
  }
  xstring[si] = '\0';

  if(pi >= stlen)
  {
    ab_code = 6;
    a_bort(ab_code, x);
  }
  
  pi++;
  pi = iswhiter(pi);
  ch = p_string[pi];
  e_pos = pi;

  printf(" %s\n",xstring);
}


void get_prnvar()
{
  char ch;
  int pi, value;

  pi = e_pos;
  pi = iswhite(pi);
  e_pos = pi;

  value = get_varvalue();
  pi = e_pos;
  pi = iswhite(pi);
  ch = p_string[pi];

  printf(" %d\n",value);
}


void locate()
{

}

char get_vartype()
{
  char ch;
   int pi;

  pi = e_pos;
  ch = p_string[pi];
  while(isalnum(ch))
  {
    pi++;
    ch = p_string[pi];
  }
  return ch;
}


void get_strvar()
{
  char ch, varname[VAR_NAME];
   int pi, ndx = 0, ab_code = 13, x = line_ndx;

  strcpy(varname, get_varname());

  while((strcmp(sn_stack[ndx], varname) != 0) && (ndx < smax_vars))
  {
    ndx++;
  }
 
  if(ndx == smax_vars)
  {
    a_bort(ab_code, x);
  }

  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  ch = p_string[pi];

  printf(" %s\n", sv_stack[ndx]);
}


