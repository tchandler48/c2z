
void parse_let()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int si=0;
  int stlen;
  int ndx=0;
  int ab_code = 13;
  int x=line_ndx;
  int process = 0;

  stlen = strlen(p_string);
  pi = e_pos;
  pi = get_alpha(pi, stlen);


  if(pi == stlen)
  {
    ab_code = 11;
    a_bort(ab_code, x);
  }

  e_pos = pi;
  strcpy(varname, get_varname());

  pi = e_pos;
  ch = p_string[pi];

  process = 0;
  if((ch == '#') && (process == 0))
  {
    ndx = get_dblndx(varname);
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
    Match('=');
    dv_stack[ndx] = rdp_start();
    process = 1;
  }
 
  if((ch == '$') && (process == 0))
  {
    e_pos = pi;
    parse_str(varname);
    process = 1;
  }

  if(process == 0)
  {
    ndx = get_intndx(varname);
    pi = iswhite(pi);
    e_pos = pi;
    Match('=');
    iv_stack[ndx] = rdp_start();
    process = 1;
  }
}

int get_intndx(char *name)
{
  char varname[VAR_NAME];
  int ndx = 0;
  int vflag = 0;
  int vi_pos = 0;

  strcpy(varname, name);

  vflag = 0;

  while((strcmp(in_stack[ndx], varname) != 0) && (ndx < imax_vars))
  {

printf("in_stack[ndx] = %s\n",in_stack[ndx]);


    if(vflag == 0)
    {
      if(in_stack[ndx] == ' ')
      {
        vi_pos = ndx;
        vflag = 0;
      }
    }
    ndx++;
  }

printf("get_intndx ndx = %d\n",ndx);

printf("get_intndx imax_vars = %d\n",imax_vars);

printf("get_intndx vflag = %d\n",vflag);


  if(ndx == imax_vars)
  {
    if(vflag == 0)
    {
      imax_vars--;
      init_int();
      ndx = imax_vars;
      ndx--;

printf("get_intndx varname = %s\n",varname);

printf("get_intndx ndx = %d\n",ndx);

      strcpy(in_stack[ndx], varname);
      
printf("in_stack[ndx] = %s\n",in_stack[ndx]);

    }
    else
    {
      strcpy(in_stack[ndx], varname);
    }
  }
  return ndx;
}

int get_dblndx(char *name)
{
  char varname[VAR_NAME];
  int ndx = 0, vflag = 0, vi_pos = 0;

  strcpy(varname, name);
  while((strcmp(dn_stack[ndx], varname) != 0) && (ndx < dmax_vars))
  {
    if(vflag == 0)
    {
      if(dn_stack[ndx] == ' ')
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
      init_dbl();
      ndx = dmax_vars;
      ndx--;
      strcpy(dn_stack[ndx], varname);
    }
    else
    {
      strcpy(dn_stack[ndx], varname);
    }
  }
  return ndx;
}

char get_varname()
{
  char ch;
  char varname[VAR_NAME];
   int pi, si = 0;

  pi = e_pos;

  ch = p_string[pi];
  while(isalnum(ch) != 0)
  {
    varname[si] = ch;
    si++;
    pi++;
    ch = p_string[pi];
  }
  varname[pi] = '0';

  e_pos = pi;
  return varname;
}


int get_varvalue()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int ndx = 0;
  int ab_code=13, x=line_ndx;
  int value; 
  int I;

  strcpy(varname, get_varname());

printf("get_varvalue varname = %s\n",varname);

  pi = e_pos;
  ch = p_string[pi];
  var_type = ch;

printf("get_varvalue ch = %s\n",ch);

printf("get_varvalue imax_vars = %d\n",imax_vars);

for(I = 0; I < 4; I++)
{
printf("in_stack[ndx] = %s\n",in_stack[ndx]);
}

  if(ch == '#')
  {
    while((strcmp(dn_stack[ndx], varname) != 0) && (ndx < dmax_vars))
    {
      ndx++;
    }
 
    if(ndx == dmax_vars)
    {
      a_bort(ab_code, x);
    }
    value = dv_stack[ndx];
    _GetChar();
  }
  else
  {
    while((strcmp(in_stack[ndx], varname) != 0) && (ndx < imax_vars))
    {
      ndx++;
    }
 
    if(ndx == imax_vars)
    {
      a_bort(ab_code, x);
    }
    value = iv_stack[ndx];
  }
  return value;
}

void clr_vars()
{
  clr_int();
  clr_dbl();
  clr_str();
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
  }
  else
  {
    ndx = imax_vars;
    imax_vars++;
    size = imax_vars;
  }
}

void clr_int()
{
  int ndx;

  if(imax_vars > 0)
  {
    imax_vars = 0;
  }
}


void init_dbl()
{
  int ndx;
  unsigned size;

  if(dmax_vars == 0)
  {
    ndx = dmax_vars;
    dmax_vars++;
    size = dmax_vars;
  }
  else
  {
    ndx = dmax_vars;
    dmax_vars++;
    size = dmax_vars;
  }
}
    

void clr_dbl()
{
  int ndx;

  if(dmax_vars > 0)
  {
    dmax_vars = 0;
  }
}


void init_str()
{
  int ndx;
  unsigned size;

  if(smax_vars == 0)
  {
    ndx = smax_vars;
    smax_vars++;
    size = smax_vars;
  }
  else
  {
    ndx = smax_vars;
    smax_vars++;
    size = smax_vars;
  }
}


void clr_str()
{
  int ndx;

  if(smax_vars > 0)
  {
    smax_vars = 0;
    free(sv_stack);
    free(sn_stack);
  }
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
  int I;

  stlen = strlen(p_string);
  e_pos++;
  pi = e_pos;
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
  smax_vars++;
}


int get_varndx(char *name) 
{

  char varname[VAR_NAME];
  int ndx=0, vflag=0, vi_pos=0;

  strcpy(varname, name);

  while((strcmp(sn_stack[ndx], varname) != 0) && (ndx < imax_vars))
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

  if(ndx == imax_vars)
  {
    ndx = vi_pos;

    if(vflag == 0)
    {
      init_int();
      ndx = imax_vars;
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

