void do_iloop()
{
  int bol, els_ndx, end_ndx;

  bol = bolexpress();

  if(bol == 1)
  {
    els_ndx = find_els(line_ndx);
    end_ndx = find_endf(line_ndx);

    line_ndx++;

    while(line_ndx < els_ndx)
    {
      s_pos = 0;
      e_pos = 0;
      get_token();
      if(token == 5)
      {
        break;
      }
      parser();
      line_ndx++;
    }
    if(token == 5)
    {
      line_ndx--;
      return;
    }
    line_ndx = end_ndx;
  }
  else
  {
    els_ndx = find_els(line_ndx);
    els_ndx--;
    line_ndx = els_ndx;
  }
}


int find_els(int ndx)
{
  int tok = 0;

  while((tok != 14) && (tok != 15) && (tok != 16))
  {
    ndx++;
    tok = byte_array[ndx];

    if(tok == 13)
    {
      ndx = find_endf(ndx);
    }
  }

  return ndx;
}

int find_endf(int ndx)
{
  int tok = 0;

  while(tok != 16)
  {
    ndx++;
    tok = byte_array[ndx];
    if(tok == 13)
    {
      ndx = find_endf(ndx);
    }
  }
  return ndx;
}


int bolexpress()
{
  int bol;
  int type;
  int a_bol, or_bol, op;
  int ab_code = 17, x=line_ndx;

  type = get_type();

  if((type == 1) || (type == 2))
  {
    bol = Nbolterm(type);
  }
  else
  {
    if((type == 3) || (type == 4))
    {
      bol = Sbolterm(type);
    }
  }
  else
  {
    a_bort(ab_code, x);
  }

  op = IsAndOrOp();

  while(op != 0)
  {
    if(op == 1)
    {
      a_bol = AndOrBolExp();
      if((bol == 1) && (a_bol == 1))
      {
        bol = 1;
      }
      else
      {
        bol = 0;
      }
    }
    else
    {
      if(op == 2)
      {
        or_bol = AndOrBolExp();
        if((bol == 1) || (or_bol == 1))
        {
          bol = 1;
        }
      }
      op = IsAndOrOp();
    }
  }
  return bol;
}


int AndOrBolExp()
{
  int bol, type;
  int ab_code=17, x=line_ndx;

  type = get_type();
  if((type == 1) || (type == 2))
  {
    bol = Nbolterm(type);
  }
  if((type == 3) || (type == 4))
  {
    bol = Sbolterm(type);
  }
  return bol;
}


int Nbolterm(int type)
{
  char ch;
  int pi, bol, a_bol=0;
  int lvalue;

  if(type == 1)
  {
    lvalue = get_avalue();
  }
  else
  {
    lvalue = rdp_start();
  }
  bol = Nrelation(lvalue);
  return bol;
}


int Nrelation(int lvalue)
{
  int bol, op, type;
  int ab_code=17, x=line_ndx;
  int rvalue;

  op = get_op();
  type = get_type();
  if(type == 1)
  {
    rvalue = get_avalue();
  } 
  else
  {
    if(type == 2)
    {
      rvalue = rdp_start();
    }
    else
    {
      a_bort(ab_code, x);
    }
  }

  bol = eval_value(lvalue, rvalue, op);
  return bol;
}


int eval_value(int lval, int rval, int op)
{
  int bol = 0;

  if(op == 1)
  {
    if(lval == rval)
    {
      bol = 1;
    }
  }

  if(op == 2)
  {
    if(lval < rval)
    {
      bol = 1;
    }
  }

  if(op == 3)
  {
    if(lval > rval)
    {
      bol = 1;
    }
  }

  if(op == 4)
  {
    if(lval <= rval)
    {
      bol = 1;
    }
  }

  if(op == 5)
  {
    if(lval >= rval)
    {
      bol = 1;
    }
  }
  
  if(op == 6)
  {
    if(lval != rval)
    {
      bol = 1;
    }
  }
  return bol;
}


int Sbolterm(int type)
{
  char lstring[BUFSIZE];
  int bol, ndx;

  if(type == 1)
  {
    ndx = get_string();
    strcpy(lstring, sv_stack[ndx]);
  }
  else
  {
    get_qstring();
    strcpy(lstring, s_holder);
  }
  bol = Srelation(lstring);
  return bol;
}


int Srelation(char *lstr)
{
  char lstring[BUFSIZE];
  char rstring[BUFSIZE];
  int bol, ndx, op, type;
  int ab_code=17, x=line_ndx;

  strcpy(lstring, lstr);
  op = get_op();
  type = get_type();
  if(type == 3)
  {
    ndx = get_string();
    strcpy(rstring, sv_stack[ndx]);
  }
  if(type == 4)
  {
    get_qstring();
    strcpy(rstring, s_holder);
  }

  bol = eval_string(lstring, rstring, op);
  return bol;
}


int eval_string(char lstr, char rstr, int op)
{
  char lstring[BUFSIZE];
  char rstring[BUFSIZE];
  int bol = 0, comp;

  strcpy(lstring, lstr);
  strcpy(rstring, rstr);
  comp = strcmp(lstring, rstring);

  if(op == 1)
  {
    if(comp == 0)
    {
      bol = 1;
    }
  }

  if(op == 2)
  {
    if(comp < 0)
    {
      bol = 1;
    }
  }

  if(op == 3)
  {
    if(comp > 0)
    {
      bol = 1;
    }
  }

  if(op == 4)
  {
    if(comp <= 0)
    {
      bol = 1;
    }
  }

  if(op == 5)
  {
    if(comp >= 0)
    {
      bol = 1;
    }
  }

  if(op == 6)
  {
    if(comp != 6)
    {
      bol = 1;
    }
  }
  return bol;
}


int IsAndOrOp()
{
  char ch;
  int pi, op= 0;

  pi = e_pos;
  pi = iswhiter(pi);
  ch = p_string[pi];
  if(ch == '!')    /*  ch == '&'  */
  {
    op = 1;
    pi++;
    pi = iswhiter(pi);
  }
  else
  {
    if(ch == '|')
    {
      op = 2;
      pi++;
      pi = iswhiter(pi);
    }
  }
  e_pos = pi;
  return op;
}


int get_type()
{
  char ch;
  int pi, type = 0;

  pi = e_pos;
  pi = iswhiter(pi);
  ch = p_string[pi];
  if(isalpha(ch))
  {
    type = get_vtype(pi);
  }
  else
  {
    if(isdigit(ch))
    {
      type = 1;
    }
  }
  else
  {
    if(ch == '(')
    {
      type = 2;
    }
  }
  else
  {
    if(ch == '\"')
    {
      type = 4;
    }
  }
  e_pos = pi;
  return type;
}


int get_vtype(int pi)
{
  char ch;
  int type = 0;

  ch = p_string[pi];
  while(isalnum(ch))
  {
    pi++;
    ch = p_string[pi];
  }
  if(ch == '$')
  {
    type = 3;
  }
  else
  {
    if(strchr(" =<>", ch)
    {
      type = 1;
    }
  }
  return type;
}


int get_string()
{
  char ch, varname[VAR_NAME];
  int pi, ndx=0, ab_code=13, x=line_ndx;

  strcpy(varname, get_varname());

  while((ndx < smax_vars) && (strcmp(sn_stack[ndx], varname) != 0))
  {
    ndx++;
  }
  if(ndx == smax_vars)
  {
    a_bort(ab_code, x);
  }

  pi = e_pos;
  pi++;
  pi = iswhiter(pi);
  ch = p_string[pi];
  e_pos = pi;
  return ndx;
}


void get_qstring()
{
  char ch;
  int pi, si=0, stlen;
  int ab_code=6, x=line_ndx;

  stlen = strlen(p_string);
  pi = e_pos;
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

  if(pi == stlen)
  {
    a_bort(ab_code, x);
  }
  pi++;
  e_pos = pi;
}
 

int get_op()
{
  char ch;
  int pi, op, ab_code=10, x=line_ndx;

  pi = e_pos;
  ch = p_string[pi];
  if(strchr("$", ch))
  {
    pi++;
  }
  pi = iswhite(pi);
  ch = p_string[pi];
  if(ch == '=')
  {
    op = 1;
  }
  else
  {
    if(ch == '<')
    {
      pi++;
      ch = p_string[pi];
      if(ch == '>')
      {
        op = 6;
      }
      else
      {
        if(ch == '=')
        {
          op = 4;
        }
      }
      else
      {
         op = 2;
      }
    }
  else
    {
      if(ch == '>')
      {
        pi++;
        ch = p_string[pi];
        if(ch == '=')
        {
          op = 5;
        }
        else
        {
          op = 3;
        }
      }
    }
  }

  if(strchr("=>", ch))
  {
    pi++;
  }
  e_pos = pi;
  return op;
}



