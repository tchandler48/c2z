
void parse_let()
{
  char ch;
  char varname[VAR_NAME];
  char cvalue[6];
  int pi;
  int si=0;
  int stlen;
  int ndx=0;
  int x=line_ndx;
  int vflag=0;
  int vi_pos = 0;
  int ivalue;
  int ab_code;
  int s;

  stlen = strlen(p_string);
  pi = e_pos;
  pi = get_alpha(pi, stlen);
  ch = p_string[pi];
  if(pi == stlen)
  {
    ab_code = 11;
    a_bort(ab_code, x);
  }
  si = 0;
  while((isalnum(ch) != 0)
  {
    varname[si] = ch;
    si++;
    pi++;
    ch = p_string[pi];
  }
  varname[si] = '\0';
  s = si - 1;
  ch = varname[s];

  if(ch == '$')
  {
    ndx = get_varndx(varname);
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
    Match('=');
    strng_assgn(ndx);
  }
  else
  {
    ndx = get_intndx(varname);
    pi++;
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
      init_int();
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
      init_var();
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


  
void strng_assgn(int ndx)
{
  char ch;
  int pi;
  int stlen;
  int si=0;
  int ab_code=6;
  int x=line_ndx;
  unsigned size;

  stlen = strlen(p_string);
  pi = e_pos;
  pi++;
  pi++;
  ch = p_string[pi];

  si = 0;
  while((ch != '\"') && (pi < stlen))
  {
    s_holder[si] = ch;
    si++;
    pi++;
    ch = p_string[pi];
  }
  s_holder[si] = '\0';

  if(pi > stlen)
  {
    a_bort(ab_code, x);
  }

  size = strlen(s_holder);
  size++;
  strcpy(sv_stack[ndx], s_holder);
}


char get_varname()
{
  char ch;
  static char varname[VAR_NAME];
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


void init_int()
{
  int ndx;
  unsigned size;

  if(imax_vars == 0)
  {
     ndx = imax_vars;
     imax_vars++;
     size = imax_vars;
     iv_stack = malloc(size * sizzeof(long));
     in_stack = malloc(size * sizeof(char *));
     size = VAR_NAME;
     in_stack[ndx] = malloc(size * sizeof(char));
  }
  else
  {
     ndx = imax_vars;
     imax_vars++;
     size = imax_vars;
     iv_stack = realloc(iv_stack, size * sizeof(long));
     in_stack = realloc(in_stack, size * sizeof(char *));
     size = VAR_NAME;
     in_stack[ndx] = malloc(size * sizeof(char));
  }
}

void init_var()
{
  int ndx;
  unsigned size;

  if(smax_vars == 0)
  {
     ndx = smax_vars;
     smax_vars++;
     size = smax_vars;
     iv_stack = malloc(size * sizzeof(long));
     in_stack = malloc(size * sizeof(char *));
     size = VAR_NAME;
     sn_stack[ndx] = malloc(size * sizeof(char));
  }
  else
  {
     ndx = smax_vars;
     smax_vars++;
     size = smax_vars;
     iv_stack = realloc(iv_stack, size * sizeof(long));
     in_stack = realloc(in_stack, size * sizeof(char *));
     size = VAR_NAME;
     sn_stack[ndx] = malloc(size * sizeof(char));
  }
}


