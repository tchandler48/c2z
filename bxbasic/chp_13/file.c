
void input_io()
{
  int pi;
  int port;
  int len;
  int maxfile=(IOARRAY-1);
  int x=line_ndx;
  int ab_code=21;
  int fileno;

  len = strlen(p_string);
  pi = e_pos;
  pi = get_digit(pi, len);
  if(pi == len)				
  {
    strcpy(xstring, "Invalid Input Format:");
    a_bort(ab_code, x);
  }
  else
  {
    e_pos = pi;
    fileno = get_avalue();
    port = fileno;
    port--;
    if((port < 0) || (port > maxfile))
    {
      strcpy(xstring, "Invalid File Number:\t1 to 99:\n");
      a_bort(ab_code, x);		
    }
    else
    {
      get_finput(port, len);
    }
  }
}

void get_finput(int port, int len)
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int type;

  pi = e_pos;
  ch = p_string[pi];
  while(pi < len)
  {
    if(isalpha(ch) == 0)
    {
      pi = get_alpha(pi, len);
      ch = p_string[pi];
    }
    if(pi < len)
    {
      e_pos = pi;
      type = get_vtype(pi);
      e_pos = pi;
      strcpy(varname, get_varname());
      if(type == 3)			
      {
        read_fstring(port, varname);
      }
      else			
      {
        read_fvalue(port, varname);
      }
      pi = e_pos;
      ch = p_string[pi];
    }
  }
}


void read_fstring(int port, char *name)
{
  char chIn='\0';
  char varname[VAR_NAME];
  char temp[BUFSIZE];
   int ii=0;
   int ndx=0;
   int indx=0;
   int xsize;
  FILE *handle;

  strcpy(varname, name);
				
  ndx = get_varndx(varname);

  handle = fp[port].fptr;
  while((chIn != '\"') && (!feof(handle)))
  {
    ii = fgetc(handle);
    chIn = ii;
  }
  chIn = '\0';
  if(!feof(handle))
  {
    while((chIn != '\"') && (!feof(handle)))
    {
      ii = fgetc(handle);
      chIn = ii;
      if(chIn != '\"')
      {
        temp[indx] = chIn;
        indx++;
      }
    }
  }
  temp[indx] = '\0';

  xsize = strlen(temp);
  xsize++;
  sv_stack[ndx] = realloc(sv_stack[ndx], xsize * sizeof(char));
  strcpy(sv_stack[ndx], temp);			
}


void read_fvalue(int port, char *name)
{
  char chi='\0';
  char varname[VAR_NAME];
  char temp[BUFSIZE];
  int pi;
  int type;
  int ii=0;
  int ndx=0;
  int indx=0;
  FILE *handle;

  strcpy(varname, name);
  pi = e_pos;
  type = get_vtype(pi);

  if(type == 4)				
  {
 
  }
  if(type == 3)		
  {
   
  }
  if(type == 2)		
  {
   
  }
  else 				
  {
    
  }
  ndx = get_varndx(varname);
			
  handle = fp[port].fptr;
  while((isdigit(chi) == 0) && (!feof(handle)))
  {
    ii = fgetc(handle);		
    chi = ii;
    if((chi == '-') || (chi == '.'))
    {
      temp[indx] = chi;
      indx++;
    }
  }
  while((isdigit(chi) != 0) || (chi =='.') && (!feof(handle)))
  {
    temp[indx] = chi;
    indx++;
    ii = fgetc(handle);
    chi = ii;
  }
  temp[indx] = '\0';

  if(type == 4)
  {
    dv_stack[ndx] = atof(temp);
  }
  if(type == 3)
  {
    fv_stack[ndx] = atof(temp);
  }
  if(type == 2)
  {
    lv_stack[ndx] = atol(temp);
  }
  else 
  {
    iv_stack[ndx] = atoi(temp);
  }
}

