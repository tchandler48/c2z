

void line_cnt(char *argv[])
{
  int line_counter=0;
  int ab_code=2;
   
  pgm = fopen(prog_name, "r");
  load_src();
  loader_1();
  loader_2();
}



void load_src()
{
  char *tmp="source.tmp";
  int pi;
  int len;

  f_out = fopen(tmp, "w");
  while(!feof(pgm))
  {
    fgets(p_string, BUFSIZE, pgm);
    printf("load_src p_string = %s\n",p_string);
    pi = 0;
    pi = iswhite(pi);
    len = strlen(p_string);
    if((len > 2) && (pi < len))
    {
      if(!feof(pgm))
      {
        save_tmp();
      }
    }
  }
  fclose(pgm);
  fclose(f_out);
}


void save_tmp()
{
  int pi;
  int len;
  char ch;

  strcpy(xstring, "  ");
  strcat(xstring, p_string);
		
  pi = 0;
  ch = p_string[pi];
  if(isupper(ch) != 0)
  {	
    len = LLEN - 2;
    while(isalnum(ch) != 0)
    {
      pi++;
      ch = p_string[pi];
    }
	
    if((ch == ':') && (pi <= len))
    {
      pi++;
      p_string[pi] = '\0';
      fprintf(f_out, "%s", p_string);
      nrows++;
    }
    else
    {	
      fprintf(f_out, "%s", xstring);
      nrows++;
    }
  }
  else
  {
    if(isdigit(ch))
    {	
      fprintf(f_out, "%s", p_string);
      nrows++;
    }
    else
    {
      pi = iswhite(pi);
      ch = p_string[pi];
			
      fprintf(f_out, "%s", xstring);
      nrows++;
    }
  }
}



void loader_1()
{
  char ch;
  char ln_holder[LLEN];
  char *tmp="source.tmp";
  int ii;
  int len;
  int pi;
  int size=ncolumns;
  int I;

  f_in = fopen(tmp, "r");
  ii = 0;
  while(!feof(f_in))
  {
    fgets(p_string, BUFSIZE, f_in);
    if(!feof(f_in))
    {	
      len = strlen(p_string);
      tmp_label(ii);
      pi = e_pos;
      ch = p_string[pi];
      if(ch == ':')
      {
        temp_byte[ii] = -1;
        strcpy(temp_prog[ii],"\0";
      }
      else
      {
        tmp_byte(ii);
        tmp_prog(ii);
      }
    }
    ii++;
  }
  fclose(f_in);
}


void tmp_label(int ii)
{
  char ch;
  char ln_label[LLEN];
  int pi;

  pi = 0;
  ch = p_string[pi];
  if(isalnum(ch))
  {
    while(isalnum(ch))
    {
      ln_label[pi] = ch;
      pi++;
      ch = p_string[pi];
    }
    ln_label[pi] = '\0';
    strcpy(temp_label[ii], ln_label);
  }
  else
  {
    strcpy(temp_label[ii], "\0";
  }
  e_pos = pi;
}


void tmp_byte(int ii) 
{
  char ch;
  int pi;
  int si;
  int byte;
  int x=ii;
  int ab_code=4;

  pi = e_pos;
  pi = iswhite(pi);
  ch = p_string[pi];
		
  if(isupper(ch))
  {	
    e_pos = pi;
    byte = get_byte(ii);
    pi = e_pos;
  }
  else
  {
    if(isalpha(ch))
    {	
      si = pi;
      while(isalnum(ch))
      {
        pi++;
        ch = p_string[pi];
      }
      pi = iswhite(pi);
      ch = p_string[pi];
      if(ch == '=')
      {
        byte = 1;
        pi = si;
      }
      else
      {	
        a_bort(ab_code, x);
      }
    }
  }
  temp_byte[ii] = byte;
  e_pos = pi;
}	



int get_byte(int ii)
{
  char ch;
  char keyword[TOKEN_LEN];
  int pi;
  int si=0;
  int byte=0;
  int x=ii;
  int ab_code=4;
  int x1 = 0;

  pi = e_pos;
  ch = p_string[pi];
  while(isalnum(ch))
  {
    keyword[si] = ch;
    si++;
    pi++;
    ch = p_string[pi];
  }
  keyword[si] = '\0';

  if(strcmp(keyword, "REM") == 0)
  {
    byte = 0;
    x1 = 1;
  }

  if(strcmp(keyword, "LET") == 0)
  {
    byte = 1;
    x1 = 1;
  }

  if(strcmp(keyword, "CLEAR") == 0)
  {
    byte = 2;
    x1 = 1;
  }

  if(strcmp(keyword, "LOCATE") == 0)
  {
    byte = 3;
    x1 = 1;
  }

  if(strcmp(keyword, "PRINT") == 0)
  {
    byte = 4;
    x1 = 1;
  }

  if(strcmp(keyword, "GOTO") == 0)
  {
    byte = 5;
    x1 = 1;
  }

  if(strcmp(keyword, "BEEP") == 0)
  {
    byte = 6;
    x1 = 1;
  }

  if(strcmp(keyword, "CLS") == 0)
  {
    byte = 7;
    x1 = 1;
  }

  if(strcmp(keyword, "END") == 0)
  {
    byte = 8;
    x1 = 1;
  }

  if(strcmp(keyword, "GOSUB") == 0)
  {
    byte = 9;
    x1 = 1;
  }

  if(strcmp(keyword, "RETURN") == 0)
  {
    byte = 10;
    x1 = 1;
  }

  if(strcmp(keyword, "FOR") == 0)
  {
    byte = 11;
    x1 = 1;
  }

  if(strcmp(keyword, "NEXT") == 0)
  {
    byte = 12;
    x1 = 1;
  }

  if(strcmp(keyword, "IF") == 0)
  {
    byte = 13;
    x1 = 1;
  }

  if(strcmp(keyword, "ELSEIF") == 0)
  {
    byte = 14;
    x1 = 1;
  }

  if(strcmp(keyword, "ELSE") == 0)
  {
    byte = 15;
    x1 = 1;
  }

  if(strcmp(keyword, "ENDIF") == 0)
  {
    byte = 16;
    x1 = 1;
  }

  if(strcmp(keyword, "INPUT") == 0)
  {
    byte = 17;
    x1 = 1;
  }

  if(x1 == 0)
  {
    pi = iswhite(pi);
    ch = p_string[pi];
    if(strchr("=$#",ch))
    {
      byte = 1;
      pi = e_pos;
    }
    else
    {
      a_bort(ab_code, x);
    }
  }
  e_pos = pi;
  return byte;
}



void tmp_prog(int ii)
{
  char ch;
  char prog[BUFSIZE];
  int pi;
  int si=0;
  int len;
  int I;

  len = strlen(p_string);
  pi = e_pos;
  pi = iswhite(pi);
  if((temp_byte[ii] != 0) && (pi < len))
  {
    ch = p_string[pi];
    while(ch != '\0')
    {
      prog[si] = ch;
      si++;
      pi++;
      ch = p_string[pi];
    }
  }
  prog[si] = '\0';
  strcpy(temp_prog[ii], prog);
}



void loader_2()
{
  int ndx;
  int ii;
  int line_count=0;
  int lines=nrows;
  int size;
  int I;

  for(ndx=0; ndx < nrows; ndx++)
  {
    if(temp_byte[ndx] != 0)
    {
      line_count++;
    }

    if((temp_byte[ndx] == 13) || (temp_byte[ndx] == 14))
    {
      token_if();
    }
   
    if(temp_byte[ndx] == 1)
    {
       str_functn(ndx);
    }
  }
 
  ndx = 0;
  for(ii=0; ii < nrows; ii++)
  {
      strcpy(array1[ndx], temp_prog[ii]);
      byte_array[ndx] = temp_byte[ii];
      strcpy(label_nam[ndx], temp_label[ii]);
      ndx++;
  }
}


void token_if(int ndx) 
{
  char temp[TOKEN_LEN];
  int loc;

  strcpy(p_string, temp_prog[ndx]);
  s_pos = 0;
  strcpy(temp, "AND");
  loc = 0;
  while (loc >= 0) 
  {
    loc = find_strng(temp);
    loc--;
    if (loc > 0) 
    {
      p_string[loc] = ' '; 		
      p_string[(loc + 1)] = ' ';
      p_string[(loc + 2)] = ' ';
    }
  }
  strcpy(temp, "OR");
  loc = 0;
  while (loc >= 0) 
  {
    loc = find_strng(temp);
    loc--;
    if (loc > 0) 
    {
      p_string[loc] = '|'; 		
      p_string[(loc + 1)] = ' ';
    }
  }
  strcpy(temp, "THEN");
  loc = 0;
  while (loc >= 0) 
  {
    loc = find_strng(temp);
    loc--;
    if (loc > 0) 
    {
      p_string[loc] = '\n'; 		
      p_string[(loc + 1)] = '\0';
    }
  }
  strcpy(temp_prog[ndx], p_string);
}


int find_strng(char *tmp)
{
  char ch;
  char cx;
  char quote='\"';
  char temp[TOKEN_LEN];
  char xxstring[TOKEN_LEN];
   int pi;
   int i;
   int mark;
   int len;
   int len2;

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
      if(ch == quote)
      {
        pi++;
        ch = p_string[pi];
        while(ch != quote)
        {
          pi++;
          ch = p_string[pi];
        }
      }
      pi++;
      ch = p_string[pi];
    }

    if(pi == len) || (pi > len))
    {
      mark = 0;
      return mark;
    }

    mark = pi;
    for(i = 0; i < len2; i++)
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


void str_functn(int ndx)
{   
    char ch;
    char temp[VAR_NAME]; 	    
    int pi=0;
    int type;

    strcpy(p_string, temp_prog[ndx]);

    type = get_vtype(pi);

    pi = e_pos;
    if(type != 3)
    {
      return;
    }

    while(IsEqu(pi) == 0)		
    {   
        pi++;
    }

    pi = e_pos;
    pi++;
    pi = iswhite(pi);
    ch = p_string[pi];

    if(ch == '\"')
    {
      return;
    }

    if(isupper(ch) == 0)
    {
      return;
    }
    else
    {
      e_pos = pi;
      strcpy(temp, get_varname());	
      e_pos = pi;
      get_strfunc(temp,ndx);
      return;
    }

    if(isalpha(ch) == 0)
    {
      return;
    }
}



void get_strfunc(char *name,int ndx)		
{
  char varname[VAR_NAME];
  char temp[TOKEN_LEN];

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

  if(strcmp(varname, "INKEY") == 0)
  {
    strcpy(temp, "     8");            
  }

  if(strcmp(varname, "INPUT") == 0)
  {
    strcpy(temp, "     9");            
  }

  if(strcmp(varname, "MKD") == 0)
  {   
    strcpy(temp, "  10");                   
  }

  if(strcmp(varname, "MKI") == 0)
  {   
    strcpy(temp, "  11");                   
  }

  if(strcmp(varname, "MKS") == 0)
  {   
    strcpy(temp, "  12");                   
  }

  if(strcmp(varname, "UCASE") == 0)
  {   
    strcpy(temp, "    13");                 
  }

  if(strcmp(varname, "LCASE") == 0)
  {   
    strcpy(temp, "    14");                 
  }

  str_copy(temp,ndx);		
}


void str_copy(char *temp,int ndx)
{   
    char ch;
    char tok[TOKEN_LEN];
    char wp_string[BUFSIZE];
	
    int pi;
    int si=0;
    int pi2;

    strcpy(tok, temp);

    strcpy(wp_string, p_string);

    pi = e_pos;
    ch = tok[si];

    if(ch != '\0')
    {   
        while(ch != '\0')
        {   
            p_string[pi] = ch;
            si++;
            pi++;
            ch = tok[si];
        }

        pi--;
        pi2 = pi;
        ch = wp_string[pi];

        while(ch != '\0')
        {
           ch = wp_string[pi];
           p_string[pi2] = ch;
           pi++;
           pi2++;
         }
         p_string[pi2] = '\0';

        strcpy(temp_prog[ndx], p_string);
        e_pos = pi;
    }
    else
    {   
       e_pos = s_pos;		
    }
}


int IsEqu(int pi)
{
    char ch;			
    int bool=0;

    pi = iswhite(pi);
    e_pos = pi;
    ch = p_string[pi];
    if(ch == '=')
    {   
      bool = 1;
    }
    return bool;
}

