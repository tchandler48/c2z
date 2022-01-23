
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

  pi = e_pos;
  ch = p_string[pi];

  if(IsAddop(ch))
  {
    Value = 0;
  }
  else
  {
    Value = Term();
    pi = e_pos;
    ch = p_string[pi];
  }

  while(IsAddop(ch))  
  {
    switch(ch)
    {
      case '+':
        Match('+');
        e_pos++;
        SkipWhite();
        Value = Value + Term();
        break;
      case '-':
        Match('-');
        e_pos++;
        SkipWhite();
        Value = Value - Term();
        break;
      default:
        break;
    }
   
    pi = e_pos;
    ch = p_string[pi];
  }
  return Value;
}

 
int Term()
{
  char ch;
  int pi, Value;

  Value = Factor();
  pi = e_pos;
  ch = p_string[pi];

  while(IsMultop(ch))
  {
    switch(ch)
    {
      case '*':
        Match('*');
        e_pos++;
        SkipWhite();
        Value = Value * Factor();
        break;
      case '/':
        Match('/');
        e_pos++;
        SkipWhite();
        Value = Value / Factor();
        break;
      default:
        break;
    }
   
    pi = e_pos;
    ch = p_string[pi];
  }
  return Value;
}


int Factor()
{
  char ch;
  int value;
  int pi;

  pi = e_pos;
  ch = p_string[pi];

  if(ch == '(')
  {
    Match('(');
    value = Expression();
    Match(')');
  }
  else
  {
      if(isalpha(ch))
      {
        value = get_varvalue();
        SkipWhite();
      }
      else
      {
        value = GetNum();
      }
  }
  return value;
}


void Match(char x)
{
  char ch, string[6];
  int ab_code=12, ln=line_ndx;
  int pi;

  pi = e_pos;
  ch = p_string[pi];
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
  int pi;
  
  pi = e_pos;
  ch = p_string[pi];
  while(Is_White(ch))
  {
    _GetChar();
    pi = e_pos;
    ch = p_string[pi];
  }
}


int GetNum()
{
  char ch;
  int pi, Value=0, ab_code=13, ln=line_ndx;
  int si;
  char cvalue[6];

  pi = e_pos;
  ch = p_string[pi];

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
    _GetChar();
    pi =  e_pos;
    ch = p_string[pi];
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



