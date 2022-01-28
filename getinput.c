

void get_input()
{
   char ch, varname[VAR_NAME];
   int pi, len, type, loc=0;
   int ab_code=19, x=line_ndx;
 
   pi = e_pos;
   ch = p_string[pi];

   if(ch == ';')
   {
     loc = 1;
     pi++;
     pi = iswhite(pi);
     ch = p_string[pi];
     e_pos = pi;
   }

   len = strlen(p_string);

   while(pi < len)
   {
     if(ch == '\"')
     {
       get_prnstring();
       pi = e_pos;
       pi++;
       pi = iswhite(pi);
       ch = p_string[pi];
       e_pos = pi;
     }
 
       if(isalpha(ch))
       {
         type = get_vtype(pi);

         strcpy(varname, get_varname());

         if(type == 3)
         {
           input_str(varname, loc);
           pi = e_pos;
           ch = p_string[pi];
         }
         else
         {
           input_val(varname, loc);
           pi = e_pos; 
           ch = p_string[pi];
         }
       }
     
   }
}


void input_str(char *name, int loc)
{
  char ch, varname[VAR_NAME], string[BUFSIZE];
   int pi, ndx,len,for,col;
   int xsize;

  strcpy(varname, name);

  ndx = get_varndx(varname);

  if(loc == 1)
  {
    gets(string);
    len = strlen(string);
  }
  else
  {
    gets(string);
  }

  strcpy(sv_stack[ndx], string);
  smax_vars++;

  pi = e_pos;
  pi++;
  ch = p_string[pi];
  if(strchr(":;,",ch))
  {
    pi++;
    set_TabNl(ch);
  }
  pi = iswhite(pi);
  e_pos = pi;
}


void input_val(char *name, int loc)
{
  char ch, cx;
  char varname[VAR_NAME], string[VAR_NAME];
   
   int pi, ndx, len,row, col;

   strcpy(varname, name);

   ndx = get_intndx(varname);

   pi = e_pos;
   ch = p_string[pi];

   if(loc == 1)
   {
     gets(string);
     len = strlen(string);
   }
   else
   {
     gets(string);
   }

   iv_stack[ndx] = atoi(string);
   imax_vars++;

   pi = iswhite(pi);
   ch = p_string[pi];
   if(strchr(":;,",ch))
   {
     pi++;
     set_TabNl(ch);
   }
   pi = iswhite(pi);
   e_pos = pi;
}




void set_TabNl(char ch)
{
  if(ch == '.')
  {
    printf("     ");
  }
  else
  {
    if(ch == ':')
    {
      printf("\n");
    }
  }
}




