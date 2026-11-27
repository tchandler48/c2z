
void beep()
{

}


void cls()
{


}


void get_prnstring()
{
  char ch;
  int pi;
  int si = 0;;
  
  pi = e_pos;
  ch = p_string[pi];

  if(ch == ':')
  {
    printf("\n");
    return;
  }
  else
  {
    if(isalpha(ch))
    {
      get_prnvar();
      return;
    }
  }

  pi++;
  ch = p_string[pi];

  while(ch != '\"')
  {
    xstring[si] = ch;
    si++; 
    pi++;
    ch = p_string[pi];
  }
  xstring[si] = '\0';

  pi++;
  pi = iswhite(pi);
  ch = p_string[pi];

  if(ch == ';')
  {
    printf("%s",xstring);
  }
  else
  {
    printf)"%s\n",xstring);
  }

}



void get_prnvar()
{
  char ch;
  int pi;
  int ivalue;

  pi = e_pos;
  pi = iswhite(pi);
  e_pos = pi;
  ivalue = get_varvalue();
  pi = e_pos;
  pi = iswhite(pi);
  ch = p_string[pi];

  if(ch == ',')
  {
    printf("%d", ivalue);
  }
  if(ch == ';')
  {
    printf("%d",ivalue);
  }
  else
  {
    printf("%d\n",ivalue);
  }

}



