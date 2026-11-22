
void parse_str(char *name)
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int ndx;
  int ab_code=11;
  int x=line_ndx;
  int x1 = 0;

  strcpy(varname, name);
  pi = e_pos;
  ch = p_string[pi];
  ndx = get_varndx(varname);

  pi++;
  pi = iswhite(pi);
  e_pos = pi;

  Match('=');
  pi = e_pos;
  pi++;

  pi = iswhite(pi);
  e_pos = pi;

  ch = p_string[pi];

  if(ch == '\"')
  {
    x1 = 1;
    strng_assgn(ndx);
  }

  if((isdigit(ch)) && (x1 == 0))  
  {
    x1 = 1;
    asn_function();
  }
  if(x1 == 0)
  {
    strvar_assgn(ndx);
  }

  strcpy(sv_stack[ndx], s_holder);

}

  
void strng_assgn(int ndx)
{
  char ch;
  int pi;
  int stlen;
  int si=0;
  int ab_code=6;
  int x=line_ndx;
  unsigned size;

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

  if(pi > stlen)
  {
    a_bort(ab_code, x);
  }

  strcpy(sv_stack[ndx], s_holder);
}




void strvar_assgn(int ndx)
{
  int indx=0;

  indx = get_strndx();

  strcpy(s_holder, sv_stack[indx]);
}


int get_strndx()
{
  char varname[VAR_NAME];
  int indx=0;
  int ab_code=13;
  int x=line_ndx;
 
  strcpy(varname, get_varname());

  while((indx < smax_vars) && (strcmp(sn_stack[indx], varname) != 0))
  {
    indx++;
  }
  if(indx == smax_vars)
  {
    a_bort(ab_code, x);
  }
  return indx;
}


void asn_function()
{
  int type;

  type = get_avalue();

printf("asn_function type = %d\n",type);

  switch(type)
  {
    case 1:
        chrstr();		/* a$ = CHR$(n) */
        break;
    case 2:
        leftstr();		/* a$ = LEFT$(x$,n) */
        break;
    case 3:
        rightstr();		/* a$ = RIGHT$(x$,n) */
        break;
    case 4:
        midstr();		/* a$ = MID$(x$,n,n) */
        break;
    case 5:
        spacestr();		/* a$ = SPACE$(n) */
        break;
    case 6:
        strsval();		/* a$ = STR$(n) */
        break;
    case 7:
        stringstr();		/* a$ = STRING$(n,c) */
        break;
    default:
        /* error */
        break;
  }
}


void chrstr()
{   
    int pi;
    long xxxchar;

    pi = e_pos;              
    pi++;                    
    pi = iswhite(pi);
    e_pos = pi;
    xxxchar = get_avalue();
    s_holder[0] =  xxxchar;
    s_holder[1] = '\0';
}


void leftstr()
{   
    int i;
    int pi;
    int indx;
    int count;
    int len;
    char w_holder[BUFSIZE];

    pi = e_pos;                  
    pi++;    
           
    pi = iswhite(pi);
    e_pos = pi;

    indx = get_strndx();
    pi = e_pos;              
    pi += 1;                    
    pi = iswhite(pi);
    e_pos = pi;
    

    count = get_avalue();
    if(count < 1)
    {   
      count = 0;
    }
    len = strlen(sv_stack[indx]);
    len++;
    if(count > len)
    {   
       count = len;
    }
  
    strncpy(s_holder,sv_stack[indx],count);
    s_holder[count] = '\0';
}



void rightstr()
{   
    int ii;
    int pi;
    int indx;
    int count;
    int len;
    int left;

    pi = e_pos;                
    pi++;                   
    pi = iswhite(pi);
    e_pos = pi;

    indx = get_strndx();
    pi = e_pos;              
    pi += 2;                  
    pi = iswhite(pi);
    e_pos = pi;

    count = get_avalue();
    if(count < 1)
    {   
      count = 0;
    }
    len = strlen(sv_stack[indx]);
    if(count > len)
    {   
      count = len;
    }
    left = len - count;
    for(ii=0; ii < count; ii++, left++)
    {   
      s_holder[ii] = sv_stack[indx][left];
    }
    s_holder[count] = '\0';
}



void midstr()
{   
    char ch;
    int ii;
    int pi;
    int indx;
    int count;
    int len;
    int left;

    pi = e_pos;                 
    pi++;                   
    pi = iswhite(pi);
    e_pos = pi;
    indx = get_strndx();
    pi = e_pos;              
    pi += 2;                  
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
    len = strlen(sv_stack[indx]);
    left--;		    		
    if((left + count) > len)
    {   
       count = len - left;
    }
    for(ii=0; ii < count; ii++, left++)
    {   
       s_holder[ii] = sv_stack[indx][left];
    }
    s_holder[count] = '\0';
}



void spacestr()
{   
    char space=' ';
    int ii;
    int pi;
    int count;

    pi = e_pos;               
    pi++;                 
    pi = iswhite(pi);
    e_pos = pi;
    count = get_avalue();
    if(count < 1)
    {   
      count = 0;
    }
    if(count > 255)
    {   
      count = 255;
    }
    for(ii=0; ii < count; ii++)
    {   
      s_holder[ii] = space;
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

    strcpy(s_holder, value2strng(value));
}



void stringstr()
{   
    char ch;
    char char_x;
    char quote='\"';
    int ii;
    int pi;
    int count;
    long xxx;

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

    if(ch == quote)               
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
        xxx = get_avalue();
        char_x = xxx;
    }
    for(ii=0; ii < count; ii++)
    {   
        s_holder[ii] = char_x;
    }
    s_holder[count] = '\0';
}

