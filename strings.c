
void parse_str(char *name)
{
  char ch, varname[VAR_NAME];
  int pi, ndx;
  int ab_code=11, x=line_ndx;
  int process;

  strcpy(varname, name);

  pi = e_pos;
  ch = p_string[pi];
  ndx = get_varndx(varname);
  pi++;
  pi = iswhite(pi);
  e_pos = pi;

  Match('=');
  pi = e_pos;
  ch = p_string[pi];

  process = 0;
  if(ch == '\"')
  {
    strng_assgn(ndx);
    process = 1;
  }

  if((isdigit(ch)) && (process == 0))
  {
    asn_function();
    process = 1;
  }

  if(process == 0) 
  {
    strvar_assgn(ndx);
  }
  strcpy(sv_stack[ndx], s_holder);
}



void str_functn(int ndx)
{
  char ch, temp[VAR_NAME];
   int pi = 0, type;

  strcpy(p_string, temp_prog[ndx]);

  type = get_vtype(pi);

  if(type != 3)
  {
    return;
  }

  while(IsEqu(pi) == 0)
  {
    pi = e_pos;
    pi++;
  }

  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  ch = p_string[pi];

  if(isalpha(ch) == 0)
  {
    return;
  }
  else
  {
    if(isupper(ch) == 0)
    {
      return;
    }
  }

  e_pos = pi; 
  strcpy(temp, get_varname());

  e_pos = pi;
  get_strfunc(temp, ndx);
}


int IsEqu(int pi)
{
  char ch;
  int bol = 0;

  pi = iswhite(pi);
  e_pos = pi;
  ch = p_string[pi];
  if(ch == '=')
  {
    bol = 1;
  }
  return bol;
}


void get_strfunc(char *name, int ndx)
{
  char varname[VAR_NAME], temp[TOKEN_LEN];

  strcpy(varname, name);

  temp[0] = '\0';


  if(strcmp(varname, "CHR") == 0)
  {
    strcpy(temp, "   1");
  }
  if(strcmp(varname, "LEFT") == 0)
  {
    strcpy(temp, "    2");
  }
  if(strcmp(varname, "RIGHT") == 0)
  {
    strcpy(temp, "     3");
  }
  if(strcmp(varname, "MID") == 0)
  {
    strcpy(temp, "   4");
  }
  if(strcmp(varname, "SPACE") == 0)
  {
    strcpy(temp, "     5");
  }
  if(strcmp(varname, "STR") == 0)
  {
    strcpy(temp, "   6");
  }
  if(strcmp(varname, "STRING") == 0)
  {
    strcpy(temp, "      7");
  }
  str_copy(temp, ndx);
}


void str_copy(char *temp, int ndx)
{
  char ch, tok[TOKEN_LEN];
   int pi, si = 0;

  strcpy(tok, temp);

  pi = e_pos;
  ch = tok[si];
  if(ch == ' ')
  {
    while(ch == ' ')
    {
      p_string[pi] = ch;
      si++;
      pi++;
      ch = tok[si];
    }

    while(isdigit(ch))
    {
      p_string[pi] = ch;
      si++;
      pi++;
      ch = tok[si];
    }

    strcpy(temp_prog[ndx], p_string);
    e_pos = pi;
  }
}


void strvar_assgn(int ndx)
{
  char ch, varname[VAR_NAME];
  int pi, indx=0;
  int ab_code=13, x=line_ndx;
  int size;

  strcpy(varname, get_varname());
  while((indx < smax_vars) && (strcmp(sn_stack[ndx], varname) != 0))
  {
    indx++;
  }
  if(indx == smax_vars)
  {
    a_bort(ab_code, x);
  }

  size = strlen(sv_stack[indx]);
  size++;
  sv_stack[ndx] = realloc(sv_stack[ndx], size * sizeof(char));
  strcpy(sv_stack[ndx], sv_stack[indx]);
}


void asn_function()
{
  int type;

  type = get_avalue();

  switch(type)
  {
    case 2:
      leftstr();
      break;

    case 3:
      rightstr();
      break;

    case 4:
      midstr();
      break;

    case 5:
      spacestr();
      break;

    case 6:
      strsval();
      break;

    case 7:
      stringstr();
      break;

  }
}


void leftstr()
{
  int i, pi, indx, count, len;

  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  e_pos = pi;

  indx = get_strndx();

  pi = e_pos;

  /* pi =+ 2; */
  pi = pi + 2;

  pi = iswhite(pi);
  e_pos = pi;

  count = get_avalue();

  if(count < 1)
  {
    count = 0;
  }
  len = strlen(sv_stack[indx];

  if(count > len)
  {
    count = len;
  }

  for(i = 0; i < count; i++)
  {
    s_holder[i] = sv_stack[indx][i];
  }
  s_holder[count] = '\0';
}


int get_strndx()
{
  char varname[VAR_NAME];  
   int indx = 0, ab_code = 13, x = line_ndx;

  strcpy(varname, get_varname());

  while((strcmp(sn_stack[indx], varname) != 0) && (indx < smax_vars))
  {
    indx++;
  }

  if(indx == smax_vars)
  {
    a_bort(ab_code, x);
  }

  return indx;
}


void rightstr()
{
  int ii, pi, indx, count, len, left;

  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  e_pos = pi;

  indx = get_strndx();

  pi = e_pos;

  /* pi =+ 2; */
  pi = pi + 2;

  pi = iswhite(pi);
  e_pos = pi;

  count = get_avalue();

  if(count < 1)
  {
    count = 0;
  }
  len = strlen(sv_stack[indx];

  if(count > len)
  {
    count = len;
  }

  left = len - count;

  for(ii = 0; ii < count; ii++, left++)
  {
    s_holder[ii] = sv_stack[indx][left];
  }
  s_holder[count] = '\0';
}


void midstr()
{
  char ch;
  int ii, pi, indx, count, len, left;

  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  e_pos = pi;

  indx = get_strndx();

  pi = e_pos;

  /* pi =+ 2; */
  pi = pi + 2;

  pi = iswhite(pi);
  e_pos = pi;

  left = get_avalue();
  pi = e_pos;
  pi = iswhite(pi);
  ch = p_string[pi];
  e_pos = pi;

  if(ch == ')')
  {
    count = 255;
  }
  else
  {
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
    count = get_avalue();
  }

  if(count < 1)
  {
    count = 0;
  }

  len = strlen(sv_stack[indx];
  left--;

  if((left + count) > len)
  {
    count = len - left;
  }

  for(ii = 0; ii < count; ii++, left++)
  {
    s_holder[ii] = sv_stack[indx][left];
  }
  s_holder[count] = '\0';
}


void spacestr()
{
  int ii, pi, count;

  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  e_pos = pi;

  count = get_avalue();
  if(count < 1)
  {
    count = 0;
  }
  else
  {
    if(count > 255)
    {
      count = 255;
    }
  }

  for(ii = 0; ii < count; ii++)
  {
    s_holder[ii] = ' ';
  }
  s_holder[count] = '\0';
}

void strsval()
{   
    char ch;
    int pi;
    int value;

    pi = e_pos;               
    pi++;                     
    pi = iswhite(pi);
    e_pos = pi;
    value = get_avalue();

/*    strcpy(s_holder, value2strng(value)); */
}



void stringstr()
{   
    char ch;
    char char_x;
  
    int ii;
    int pi;
    int count;
    int xxx;

    pi = e_pos;            
    pi++;                 
    pi = iswhite(pi);
    e_pos = pi;

    count = get_avalue();
    if(count < 1)
    {   
      count = 0;
    }
    else if(count > 255)
    {   
      count = 255;
    }
    pi = e_pos;                
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
    ch = p_string[pi];

    if(ch == '\"')               
    {   
        pi++;
        ch = p_string[pi];
        char_x = ch;
        while(ch != ')')           
        {   
            pi++;
            ch = p_string[pi];
        }
        e_pos = pi;
    }
    else 
    {	
        xxx =  get_avalue();
        char_x = xxx;
    }
    for(ii=0; ii < count; ii++)
    {   
        s_holder[ii] = char_x;
    }
    s_holder[count] = '\0';
}

