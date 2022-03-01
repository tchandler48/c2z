
void line_cnt(char *argv[])
{
  int pi;
  int len;
  int ii=0;
  int x=0;
  int ab_code=2;
  unsigned fnam_len;
  int I;
  int x99 = 0;

  nrows = 0;
  len = fnam_len;
  fnam_len += 5;                      
  prog_name = malloc(fnam_len * sizeof(char));
  
  pi = len - 4;
  for(; pi < len; pi++)
  {
    p_string[ii] = prog_name[pi];
    ii++;
  }
  if(strcmp(p_string, ".bas") != 0)         
  {
    strcat(prog_name, ".bas");
  }
  p_string[0] = '\0';
  strcpy(s_holder, prog_name);

  f_in = fopen(prog_name,"r");
  if(f_in == NULL)                
  {
    a_bort(ab_code, x);
  }
  else
  {
    load_src();            
    loader_1();  
    loader_2();           
    free(prog_name);
    x = remove("source.tmp");
  }
}


void load_src()
{
  char tmp[24];
  int pi, len;

  strcpy(tmp, "source.tmp");
  f_out = fopen(tmp, "w");
  while(!feof(pgm))
  {
    fgets(p_string, BUFSIZE, f_in);
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
  fclose(f_in);
  fclose(f_out);
}


void save_tmp()
{
  int pi, len;
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
  char ch, ln_holder[LLEN];
  char tmp[24];
  int ii, len, pi;
  int size=ncolumns;
  int I;

  strcpy(tmp, "source.tmp");
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
        strcpy(temp_prog[ii],"\0");
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
  char ch, ln_label[LLEN];
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
    ln_label[pi] = ' ';
    strcpy(temp_label[ii], ln_label);
  }
  else
  {
    strcpy(temp_label[ii], " ");
  }
  e_pos = pi;
}


void tmp_byte(int ii) 
{
  char ch;
  int pi, si, byte;
  int x=ii, ab_code=4;

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
      if(strchr("=#$",ch))
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
  char ch, keyword[TOKEN_LEN];
  int pi, si=0, byte=0;
  int x=ii, ab_code=4;
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
    if(strchr("=#$",ch))
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
  char ch, prog[BUFSIZE];
  int pi, si=0, len;
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
  int ndx, ii, line_count=0, lines=nrows;
  int size;
  int I;
	

  for(ndx = 0; ndx < nrows; ndx++)
  {
    line_count++;

    if((temp_byte[ndx] == 13) || (temp_byte[ndx] == 14))
    {
      token_ix(ndx);
    }

    if(temp_byte[ndx] == 1)
    {
      str_functn(ndx);
    }
  }

  nrows = line_count;
  I = 0;
  ndx = 0;
  for(ii = 0; ii < line_count; ii++)
  {	
    if(temp_byte[ii] != 0)
    {	
      strcpy(label_nam[ndx], temp_label[I]);

      strcpy(array1[ndx], temp_prog[I]);

      byte_array[ndx] = temp_byte[I]; 

      ndx++;
      I++; 
    } 
  }
}

void program_array()
{
  int ii;
  int len;
  int pi;
  int pi2;
  int I;
  char ch;
  char ln_holder[LINE_NUM];

  free(array1);

  array1 = malloc(nrows * sizeof(char *));
  for(ii = 0; ii < nrows; ii++)
  {
    array1[ii] = malloc(ncolumns * sizeof(char));
  }

  array2 = malloc(nrows * sizeof(char *));
  for(ii = 0; ii < nrows; ii++)
  {
    array2[ii] = malloc(LINE_NUM * sizeof(char));
  }
  ii = 0;
  f_src = fopen(prog_name, "r");
  while(!feof(f_src))
  {
    fgets(p_string, BUFSIZE, f_src);
    if(!feof(f_src)
    {
      len = strlen(p_string);
      strcpy(array1[ii], p_string);
      array1[ii][len] = '\0';
      pi = 0;
      pi2 = 0;
      ch = p_string[pi];
      while(isdigit(ch))
      {
         ln_holder[pi2] = ch;
         pi2++;
         pi++;
         ch = p_string[pi];
      }
      ln_holder[pi2] = '\0';
      strcpy(array2[ii], ln_holder);
    }
    ii++;
  }
  fclose(f_src);
  for(I=0; I < 17; I++)
  {
     printf("array1 = %s\n",array1[I]);
  }
}


void token_ix(int ndx)
{
  char temp[TOKEN_LEN];
  int loc;

  strcpy(p_string, temp_prog[ndx]);
  s_pos = 0;
  strcpy(temp, "AND");
  loc = 0;
  while(loc >= 0)
  {
    loc = find_strng(temp);
    loc--;
    if(loc > 0)
    {
      p_string[loc] = ' ';
      p_string[loc + 1] = ' ';
      p_string[loc + 2] = ' ';
    }
  }

  strcpy(temp, "OR");
  loc = 0;
  while(loc >= 0)
  {
    loc = find_strng(temp);
    loc--;
    if(loc > 0)
    {
      p_string[loc] = '|';
      p_string[loc + 1] = ' ';
    }
  }

  strcpy(temp, "THEN");
  loc = 0;
  while(loc >= 0)
  {
    loc = find_strng(temp);
    loc--;
    if(loc > 0)
    {
      p_string[loc] = '\n';
    }
  }

  strcpy(temp_prog[ndx], p_string);
}



