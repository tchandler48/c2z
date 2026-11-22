
int get_upper(int pi, int stlen)
{
  char ch;
  
  ch = p_string[pi];
  while((isupper(ch) == 0) && (pi < stlen))
  {
    pi++;
    ch = p_string[pi];
  }
  return pi;
}


int get_alpha(int pi, int stlen)
{
  char ch;

  ch = p_string[pi];
  while((isalpha(ch) == 0) && (pi < stlen))
  {
    pi++;
    ch = p_string[pi];
  }
  return pi;
}

int get_digit(int pi, int stlen)
{
  char ch;

  ch = p_string[pi];
  while((isdigit(ch) == 0) && (pi < stlen))
  {
    pi++;
    ch = p_string[pi];
  }
  return pi;
}


int iswhite(int pi)
{
  char ch;
 
  ch = p_string[pi];
  while(isspace(ch) != 0)
  {
    pi++;
    ch = p_string[pi];
  }
  return pi;
}

void clr_arrays()
{

}


