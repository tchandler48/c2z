
void do_loop()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int f_ndx;
  int Inc=1;
  int ab_code;
  int start;
  int next_tru;
  int x=line_ndx;
  int From;
  int Final;
		
  f_ndx = get_From();
  Final = get_To();

  pi = e_pos;
  ch = p_string[pi];
  if(ch == 'S')
  {
    Inc = get_Step();
  }

  From = f_ndx;
  start = line_ndx;
  frnxt_flg++;

  if(From < Final)
  {
    for(; From <= Final; From += Inc)
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
  char ch;
  char varname[VAR_NAME];
  char cvalue[6];
  int f_ndx;
  int pi;
  int pi2;
  int sav_pi;
  int ab_code;
  int x=line_ndx;

  pi = e_pos;
  sav_pi = pi;
  strcpy(varname, get_varname());

  e_pos = pi;
  ch = p_string[pi];

  while(ch != '=')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];

  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];

  while(isdigit(ch))
  {
    pi2 = 0;
    while(ch != ' ')
    {
      cvalue[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    cvalue[pi2] = '\0';
    f_ndx = atoi(cvalue);
  }

  if(isalpha(ch))
  {
    e_pos = pi;
    f_ndx = get_varvalue();
    pi = e_pos;
  }

  ch = p_string[pi];
  e_pos = pi;
 		
  return f_ndx;
}


int get_To()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int pi2;
  int ab_code;
  int x=line_ndx;
  int Final;
  int x10 = 0;

  pi = e_pos;
  pi++;

  ch = p_string[pi];

  if(ch != 'T')
  {	
    ab_code = 7;
    a_bort(ab_code,x);
  }
  else
  {
    pi2 = 0;
    varname[pi2] = ch;
    pi++;
    ch = p_string[pi];
    pi2++;
    varname[pi2] = ch;
    pi2++;
    varname[pi2] = '\0';
   
    if(strcmp(varname, "TO") != 0)
    {
      ab_code=7;
      a_bort(ab_code,x);
    }
  }

  pi++;
  pi = iswhite(pi);
  ch = p_string[pi];

  if(isalpha(ch))
  {
    x10 = 1;
    e_pos = pi;
    Final = get_varvalue();
    pi = e_pos;
  }


  e_pos = pi;
  if((isdigit(ch)) && (x10 == 0))
  {
    Final = get_avalue();
  }
  else
  {
    if((isdigit(ch)) && (x10 == 0))
    {
      Final = get_avalue();
    }
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
    ab_code=7;
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
  int ab_code=16, x=line_ndx;

  if(frnxt_flg == 0)
  {
    a_bort(ab_code,x);
  }
}


int get_avalue()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int si=0;
  int value = 0;

  pi = e_pos;
  ch = p_string[pi];

printf("get_avalue pi = %d\n",pi);
printf("get_avalue ch = %s\n",ch);

  if(isalpha(ch))
  {
    e_pos = pi;
    strcpy(s_holder, get_varname());
printf("get_avalue s_holder = %s\n",s_holder);
    value = get_varvalue();
printf("get_avalue value = %d\n",value);
    pi = e_pos;
  }
  else
  {
      if(IsAddop(ch))
      {
        varname[si] = ch;
        si++;
        pi++;
        ch = p_string[pi];
      }
      si = 0;
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
 
  pi = iswhite(pi);
  e_pos = pi;
  return value;
}

