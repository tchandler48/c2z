
void parse_let()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int stlen;
  int ndx=0;
  int x=line_ndx;
  int ab_code=11;
  int s;
	
  stlen = strlen(p_string);
  pi = e_pos;
  pi = get_alpha(pi, stlen);
  if(pi == stlen)
  {
    a_bort(ab_code,x);
  }

  e_pos = pi;
  strcpy(varname, get_varname());

  s = strlen(varname);
  ch = varname[s];

  if(ch == '$')
  {
    pi = e_pos;
    parse_str(varname);
  }
  else
  {
    pi = e_pos;
    ndx = get_intndx(varname);
    pi = iswhite(pi);
    e_pos = pi;
    Match('=');
    iv_stack[ndx] = rdp_start();
  }
}



int get_intndx(char *name)
{
  char varname[VAR_NAME];
  int ndx=0;
  int vflag=0;
  int vi_pos=0;

  strcpy(varname, name);

  while((ndx < imax_vars) && (strcmp(in_stack[ndx], varname) != 0))
  {
    if(vflag == 0)
    {
      if(in_stack[ndx][0] == '\0')
      {
        vi_pos = ndx;
        vflag = 1;
      }
    }
    ndx++;
  }

  if(ndx == imax_vars)
  {
    ndx = vi_pos;

    if(vflag == 0)
    {
      
      imax_vars++;
      ndx = imax_vars;
      ndx--;
      strcpy(in_stack[ndx], varname);
    }
    else
    {
      strcpy(in_stack[ndx], varname);
    }
  }
  return ndx;
}


int get_varvalue()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int si=0;
  int ndx=0;
  int ivalue;
  int ab_code=13;
  int x=line_ndx;

  pi = e_pos;
  ch = p_string[pi];

  while((isalnum(ch) != 0))
  {
    varname[si] = ch;
    si++;
    pi++;
    ch = p_string[pi];
  }
  varname[si] = '\0';

  e_pos = pi;
  ndx = 0;
  while(strcmp(in_stack[ndx], varname) != 0)
  {
    ndx++;
  }
 
  if(ndx == imax_vars)
  {
printf("get_varvalue a_bort \n");
    a_bort(ab_code, x);
  }

  ivalue = iv_stack[ndx];

  e_pos = pi;

  return ivalue;
}


int get_varndx(char *name) 
{
  char varname[VAR_NAME];
  int ndx=0;
  int vflag=0;
  int vi_pos=0;

  strcpy(varname, name);

  while((strcmp(sn_stack[ndx], varname) != 0) && (ndx < smax_vars))
  {
    if(vflag == 0)
    {
      if(sn_stack[ndx][0] == '\0')
      {
        vi_pos = ndx;
        vflag = 1;
      }
    }
    ndx++;
  }

  if(ndx == smax_vars)
  {
    ndx = vi_pos;

    if(vflag == 0)
    {
      smax_vars++;
      ndx = smax_vars;
      ndx--;
      strcpy(sn_stack[ndx], varname);
    }
    else
    {
      strcpy(sn_stack[ndx], varname);
    }
  }
  return ndx;
}


char get_varname()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int si=0;

  pi = e_pos;
  ch = p_string[pi];
  while((isalnum(ch) != 0))
  {
    varname[si] = ch;
    si++;
    pi++;
    ch = p_string[pi];
  }
  varname[si] = '\0';

  e_pos = pi;
  return varname;
}



