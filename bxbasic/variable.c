
/*	variable.c	*/


void parse_let()
{
   char ch;
   char varname[VAR_NAME];
  
   int pi, stlen;
   int ndx = 0, x = line_ndx;
   int ab_code = 11;
   int process = 0;
   int I;

   stlen = strlen(p_string);
   pi = e_pos;
/*  retrieve variable name from statement */
   pi = get_alpha(pi, stlen);
   ch = p_string[pi];
   if(pi == stlen)
   {
     a_bort(ab_code, x);
   }

   e_pos = pi;
   strcpy(varname, get_varname());

   pi = e_pos;
   ch = p_string[pi];

/*  we now have arname and type */
/* compare name to double array */

   if(ch == '#')
   {
      process = 1;
      ndx = get_dblndx(varname);
      pi++;
      pi = iswhite(pi);
      e_pos = pi;
      Match('=');
      dv_stack[ndx] = rdp_start();
    }

    if(ch == '$')
    {
      process = 1;
      e_pos = pi;
      parse_str(varname);
    }
    
    if(process == 0)
    {
      process = 1;
      ndx = get_intndx(varname);
      pi = iswhite(pi);
      e_pos = pi;
/*  now get assignment value */
      Match('=');
      iv_stack[ndx] = rdp_start();
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

  if(ndx == imax_vars)
  {
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

  if(ndx == dmax_vars)
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
  varname[pi] = '\0';
  e_pos = pi;
  return varname;
}



int get_varvalue()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int ndx=0;
  int ab_code=13, x=line_ndx;
  int value; 
  int I;

  strcpy(varname, get_varname());

  pi = e_pos;
  ch = p_string[pi];
  var_type = ch;

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


void init_int()
{
   int ndx;

   ndx = imax_vars;
   imax_vars++;
}


void init_dbl()
{
   int ndx;

   ndx = dmax_vars;
   dmax_vars++;
}


void clr_vars()
{
   clr_int();

}


void clr_int()
{
   int ndx;

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


int get_varndx(char *name) 
{

  char varname[VAR_NAME];
  int ndx=0, vflag=0, vi_pos=0;

  strcpy(varname, name);

  while((strcmp(sn_stack[ndx], varname) != 0) && (ndx < smax_vars))
  {
    if(vflag == 0)
    {
      if(sn_stack[ndx] == '\0')
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
      init_str();
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



int get_avalue()
{
  char ch, varname[VAR_NAME];
   int pi, si=0;
   int value = 0;


  pi = e_pos;
  ch = p_string[pi];
  if(isalpha(ch))
  {
    e_pos = pi;
    value = get_varvalue();
    pi = e_pos;
  }
  else
  {
    if((isdigit(ch)) || (IsAddop(ch))
    {
      if(IsAddop(ch))
      {
        varname[si] = ch;
 	 si++;
	 pi++;
	 ch = p_string[pi];
      }
      while(isdigit(ch) != 0)
      {
	 varname[si] = ch;
	 pi++;
	 si++;
	 ch = p_string[pi];
      }
      varname[si] = '\0';
      value = atoi(varname);
    }
  }
  pi = iswhite(pi);
  e_pos = pi;
  return value;
}


