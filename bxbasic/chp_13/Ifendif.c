
void do_iloop()
{
  int bol;
  int els_ndx;
  int end_ndx;

  bol = bolexpress();

printf("do_iloop bol = %d\n",bol):

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

  while(tok != 15)
  {
    ndx++;
    tok = byte_array[ndx];
    if(tok == 11)
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
  int a_bol;
  int or_bol;
  int op;
  int ab_code = 17;
  int x=line_ndx;

  type = get_vtype();

printf("bolexpress type = %d\n",type);

  if((type == 1) || (type == 2))
  {
printf("bolexpress 1 or 2 type = %d\n",type);
    bol = Nbolterm(type);
  }
  else
  {
    if((type == 3) || (type == 4))
    {
printf("bolexpress 3 or 4\n");
      bol = Sbolterm(type);
    }
  }
  else
  {
    a_bort(ab_code, x);
  }
printf("bolexpress bol = %d\n",bol);
  return bol;
}


int AndOrBolExp()
{
  int bol;
  int type;
  int ab_code=17;
  int x=line_ndx;

  type = get_vtype();
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
  int pi;
  int bol;
  int a_bol=0;
  int lvalue;

printf("Nbolterm START type = %d\n",type);

  if(type == 1)
  {
printf("Nbolterm b4 avalue\n");
    lvalue = get_avalue();
printf("Nbolterm lvalue = %d\n",lvalue);
  }
  else
  {
    lvalue = rdp_start();
  }
  bol = Nrelation(lvalue);
printf("Nbolterm bol = %d\n",bol);
  return bol;
}


int Nrelation(int lvalue)
{
  int bol;
  int op;
  int type;
  int ab_code=17;
  int x=line_ndx;
  int rvalue;

  op = get_op();
  type = get_vtype();
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
  int bol;
  int ndx;

printf("Sbolterm type = %d\n",type);

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
printf("Sbolterm bol = %d\n",bol);
  return bol;
}


int Srelation(char *lstr)
{
  char lstring[BUFSIZE];
  char rstring[BUFSIZE];
  int bol;
  int ndx;
  int op;
  int type;
  int ab_code=17;
  int x=line_ndx;

  strcpy(lstring, lstr);
printf("Srelation lstring = %s\n",lstring);

  op = get_op();
printf("Srelation op = %d\n",op);

  type = get_vtype();
printf("Srelation type = %d\n",type);

  if(type == 3)
  {
    ndx = get_string();
printf("Srelation ndx = %d\n",ndx);

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


int eval_string(char *lstr, char *rstr, int op)
{
  char lstring[BUFSIZE];
  char rstring[BUFSIZE];
  int bol = 0;
  int comp;

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
  int pi;
  int op= 0;

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
  int pi;
  int type = 0;

  pi = e_pos;
  pi = iswhiter(pi);
  ch = p_string[pi];

printf("get_type p_string = %s\n",p_string);
printf("get_type pi = %d\n",pi);
printf("get_type ch = %s\n",ch);

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

  pi--;
  ch = p_string[pi];

  if(strchr("$",ch)
  {
    type = 3;
  }
  else
  {
    if(strchr(" ", ch)
    {
      type = 1;
    }
  }
  e_pos = pi;
  return type;
}


int get_string()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int ndx=0;
  int ab_code=13;
  int x=line_ndx;

  strcpy(varname, get_varname());
printf("get_string varname = %s\n",varname);

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

  int pi;
  int si=0;
  int stlen;
  int ab_code=6;
  int x=line_ndx;

  stlen = strlen(p_string);
  stlen++;

  pi = e_pos;

  pi++;
  ch = p_string[pi];
  while(ch != '\"')
  {
    pi++;
    ch = p_string[pi];
printf("get_qstring #1 pi = %d\n",pi);
printf("get_qstring #1 ch = %s\n",ch);

  }

   pi++;
   ch = p_string[pi];
printf("get_qstring #2 pi = %d\n",pi);
printf("get_qstring #2 ch = %s\n",ch);
printf("get_qstring #2 stlen = %d\n",stlen);

  si = 0;
  while(ch != '\"')
  {
    s_holder[si] = ch;
    si++;
    pi++;
    ch = p_string[pi];
  }
  s_holder[si] = '\0';
printf("get_qstring s_holder = %s\n",s_holder);
printf("get_qstring si = %d\n",si);

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

  int pi;
  int op;
  int ab_code=10;
  int x=line_ndx;

  pi = e_pos;
  ch = p_string[pi];

printf("get_op #1 pi = %d\n",pi);
printf("get_op #1 ch = %s\n",ch);

  if(strchr("$", ch))
  {
    pi++;
  }
  pi = iswhite(pi);
  ch = p_string[pi];
printf("get_op #2 pi = %d\n",pi);
printf("get_op #2 ch = %s\n",ch);

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
          op = 6;
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
          op = 1;
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

