
void line_cnt(char *argv[])
{
  int line_counter = 0;
  int ab_code = 2;
  int fnam_len = 0;
  int x=0;

  fnam_len++;
  prog_name = malloc(fnam_len *( sizeof(char));
  f_in = fopen(prog_name, "r");
  if(f_in == NULL)
  {
    a_bort(ab_code, x);
  }
  else
  {
    while(!feof(f_in))
    {
      fgets(p_string, BUFSIZE, f_in);
      if(!feof(f_in))
      {
        line_counter++;
      }
    }
    fclose(f_in);
  }
  nrows=line_counter;
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

