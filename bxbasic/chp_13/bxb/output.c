
void beep()
{

}


void cls()
{


}


void get_prnstring()
{
  char ch;
  char type;
  int pi;
  int si = 0;
  int stlen;
  int ab_code;
  int x=line_ndx;
  int s = 0;
  
  pi = e_pos;
  pi = iswhite(pi);
  ch = p_string[pi];

  if(ch == ':')
  {
    printf(" \n");
    return;
  }
  else
  {
    if(isalpha(ch))
    {
      type = get_vartype();
      if(type == '$')
      {
        get_strvar();
      }
      else
      {
        get_prnvar();
      }
      return;
    }
  }

  stlen = strlen(p_string);
  if((ch != '\'') || (pi == stlen))
  {
    ab_code = 9;
    a_bort(ab_code, x);
  }
  else
  {
    ch = ' ';
    for(s=0; s < BUFSIZE; s++)
    {
      xstring[s] = ch;
    }


    pi++;
    ch = p_string[pi];


    while(ch != '\"')
    {
      xstring[si] = ch;
      si++; 
      pi++;
      ch = p_string[pi];
    }
    xstring[si] = '\0';
  }

  pi++;
  pi = iswhite(pi);
  ch = p_string[pi];

  if(ch == ';')
  {
    printf(" %s",xstring);
  }
  else
  {
    printf(" %s\n",xstring);
  }
  e_pos = pi;
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
  pi--;
  ch = p_string[pi];

  return ch;
}


void get_prnvar()
{
  char ch;
  int pi;
  int ivalue;

  pi = e_pos;
  pi = iswhite(pi);
  e_pos = pi;
  ivalue = get_varvalue();
  pi = e_pos;
  pi = iswhite(pi);
  ch = p_string[pi];

  if(ch == ',')
  {
    printf(" %d", ivalue);
  }
  if(ch == ';')
  {
    printf(" %d",ivalue);
  }
  else
  {
    printf(" %d\n",ivalue);
  }
}

void get_strvar()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int ndx=0;
  int ab_code=13;
  int x=line_ndx;

  strcpy(varname, get_varname());

  while(strcmp(sn_stack[ndx], varname) != 0) 
  {
    ndx++;
  }

  if(ndx > MAX_VARS)
  {
    a_bort(ab_code, x);
  }
  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  ch = p_string[pi];

  printf(" %s\n",sv_stack[ndx]);
}


void set_TabNl(int ch)
{
  if(ch == ',')
  {
    printf("\t");
  }
  else
  {
    printf("\n");
  }
}


