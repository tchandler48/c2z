
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

  while((strcmp(in_stack[ndx], varname) != 0) && (ndx < imax_vars))
  {
    if(vflag == 0)
    {
     if(in_stack[ndx][0] == ' ')
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
      strcpy(in_stack[ndx],varname);
    }
    else
    {
      strcpy(in_stack[ndx], varname);
    }
  }

  pi = iswhite(pi);
  ch = p_string[pi];
  e_pos = pi;
  Match('=');
  iv_stack[ndx] = rdp_start();
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
