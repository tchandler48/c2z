
int rdp_start()
{
  int value;

  value = Expression();
  return value;
}


int Expression()
{
  char ch;
  int pi, Value;

 ch = p_string[e_pos];

  if(IsAddop(ch))
  {
    Value = 0;
  }
  else
  {
    Value = Term();
    ch = p_string[e_pos];
  }

  while(IsAddop(ch))  
  {
    switch(ch)
    {
      case '+':
        Match('+');
        Value = Value + Term();
        break;
      case '-':
        Match('-');
        Value = Value - Term();
        break;
      default:
        break;
    }
   
    ch = p_string[e_pos];
  }
  return Value;
}

 
int Term()
{
  char ch;
  int pi, Value;

  Value = Factor();
 
  ch = p_string[e_pos];
  while(IsMultop(ch))
  {
    switch(ch)
    {
      case '*':
        Match('*');
        Value = Value * Factor();
        break;
      case '/':
        Match('/');
        Value = Value / Factor();
        break;
      default:
        break;
    }
   
    ch = p_string[e_pos];
  }
  return Value;
}


int Factor()
{
  char ch;
  int value;

  ch = p_string[e_pos];
  if(ch == '(')
  {
    Match('(');
    value = Expression();
    Match(')');
  }
  
  if(isalpha(ch)
  {
    value = get_varvalue();
    SkipWhite();
  }
  else
  {
      value = GetNum();
  }
  return value;
}


void Match(char x)
{
  char ch, string[6];
  int ab_code=12, ln=line_ndx;

  ch = p_string[e_pos];
  if(ch != x)
  {
    strcpy(string, "\");
    string[1] = x;
    strcpy(t_holder, string);
    a_bort(ab_code, ln);
  }
  else
  {
    _GetChar();
    SkipWhite();
  }
}


void _GetChar()
{
  e_pos++;
}


int Is_White(char ch)
{
  int test = 0;

  if(ch == ' ') 
  {
    test = 1;
  }
  return test;
}



void SkipWhite()
{
  char ch;
  
  ch = p_string[e_pos];
  while(ch == ' ')
  {
    _GetChar();
    ch = p_string[e_pos];
  }
}


int GetNum()
{
  char ch;
  int pi, Value=0, ab_code=13, ln=line_ndx;
  int si;
  char cvalue[6];

  ch = p_string[e_pos];
  if(!isdigit(ch))
  {
    strcpy(t_holder, "Integer");
    a_bort(ab_code, ln);
  }
  si = 0;

  while(isdigit(ch))
  {
    cvalue[si] = ch;
    si++; 
    e_pos++;
   
    ch = p_string[e_pos];
  }
  cvalue[si] = '\0';
  Value = atoi(cvalue);
  SkipWhite();
  return Value;
}



int IsAddop(char ch)
{
  int rval = 0;

  if((ch == '+') || (ch == '-'))
  {
    rval = 1;
  }
  return rval;
}


int IsMultop(char ch)
{
  int rval = 0;    

  if((ch == '*') || (ch == '/'))
  {
    rval = 1;
  }
  return rval;
}



