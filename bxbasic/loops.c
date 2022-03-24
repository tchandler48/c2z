/*	loops.c	*/

void do_loop()
{
  char ch, varname[VAR_NAME];
  int pi, f_ndx, Inc = 1;
  int ab_code;
  int start, next_tru, x = line_ndx;
  int From, Final;
  int I;
		
  f_ndx = get_From();

  Final = get_To();

  pi = e_pos;
  ch = p_string[pi];

  if(ch == 'S')
  {
    Inc = get_Step();
  }

  From = iv_stack[f_ndx];
  start = line_ndx;

  frnxt_flg++;

  if(From < Final)
  {
    for(; From < Final; From += Inc)
    {
      next_tru = 1;
      line_ndx = start + 1;
      while(next_tru == 1)
      {
        get_token();
        e_pos = 0;
        s_pos = 0;
        parser();
        if(token == 12)
 	 {
	   next_tru = 0;
	   token = 0;
	 }
	 else
	 {
          line_ndx++;
	 }
      }
    }
  }
  else
  {
    for(; From >= Final; From += Inc)
    {
      next_tru = 1;
      line_ndx = start + 1;
      while(next_tru == 1)
      {
        get_token();
	 s_pos = 0;
	 e_pos = 0;
	 parser();
	 if(token == 12)
	 {
	   next_tru = 0;
	   token = 0;
	 }
	 else
	 {
	   line_ndx++;
	 }
      }
    }
  }
  frnxt_flg++;
}

int get_From()
{
  char ch, varname[VAR_NAME];
   int f_ndx, pi,sav_pi;
   int ab_code, x = line_ndx;
		
  pi = e_pos;
  sav_pi = pi;
  strcpy(varname, get_varname());

  e_pos = sav_pi;
  parse_let();
  pi = e_pos;
  ch = p_string[pi];
  f_ndx = get_varndx(varname);

  return f_ndx;
}


int get_To()
{
  char ch, varname[VAR_NAME];
  int pi, ab_code, x = line_ndx;
  int Final;

  pi = e_pos;
  ch = p_string[pi];

  if(ch != 'T')
  {
    ab_code = 7;
    a_bort(ab_code,x);
  }
  else
  {
    strcpy(varname, get_varname());
    pi = e_pos;
    ch = p_string[pi];
    if(strcmp(varname, "TO") != 0)
    {
      ab_code = 7;
      a_bort(ab_code,x);
    }
  }
  pi = iswhite(pi);
  ch = p_string[pi];
  e_pos = pi;
  if(isalnum(ch))
  {
    Final = get_avalue();
  }
  else
  {
    ab_code = 15;
    a_bort(ab_code,x);
  }
  return Final;
}


int get_Step()
{
  char ch, varname[VAR_NAME];
   int pi, Inc;
   int ab_code, x=line_ndx;
  char sav_ch;

  strcpy(varname, get_varname());
  if(strcmp(varname, "STEP") != 0)
  {
    ab_code = 7;
    a_bort(ab_code,x);
  }
  pi = e_pos;
  pi = iswhiter(pi);
  ch = p_string[pi];
  if(IsAddop(ch))
  {
    sav_ch = ch;
    pi++;
    pi = iswhiter(pi);
    ch = p_string[pi];
  }
  e_pos = pi;
  if(isalnum(ch))
  {
    Inc = get_avalue();
  }
  else
  {
    ab_code = 15;
    a_bort(ab_code, x);
  }
  if(sav_ch == '-')
  {	
    Inc = 0 - Inc;
  }
  return Inc;
}



void do_next()
{
  int ab_code = 16, x = line_ndx;

  if(frnxt_flg == 0)
  {
    a_bort(ab_code,x);
  }
}

