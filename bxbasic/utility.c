/* utility.c	*/

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
  int ii;

  for(ii = 0; ii < nrows; ii++)
  {
    free(label_nam[ii]);
    free(array1[ii]);
  }
  free(label_nam);
  free(byte_array);
  free(array1);
}



int iswhiter(int pi)
{
  char ch;
 
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }
  return pi;
}



int find_strng(char *tmp)
{
  char ch, cx;
  char temp[TOKEN_LEN];
  char xxstring[TOKEN_LEN];
   int pi, i, mark;
   int len, len2;

  strcpy(xxstring, tmp);
  len = strlen(p_string);
  len2 = strlen(xxstring);
  pi = e_pos;
  ch = p_string[pi];
  cx = xxstring[0];
  while(pi < len)
  {
    while((ch != cx) && (pi < len))
    {
      if(ch == '\"')
      {
        pi++;
        ch = p_string[pi];
        while(ch != '\"')
        {
          pi++;
          ch = p_string[pi];
        }
      }
      pi++;
      ch = p_string[pi];
    }
   
    if((pi == len) || (pi > len))
    {
      mark = 0;
      return mark;
    }

    mark = pi;
    for(i=0; i < len2; i++)
    {
      temp[i] = ch;
      pi++;
      ch = p_string[pi];
    }
    temp[i] = '\0';
 
    if(strcmp(temp, xxstring) != 0)
    {
      pi = mark + 1;
      ch = p_string[pi];
    }
    else
    {
      mark++;
      pi = len;
    }
  }
  return mark;
}

