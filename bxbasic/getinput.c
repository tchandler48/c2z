

void get_input()
{
   char ch, varname[VAR_NAME];
   int pi, len, type, loc=0;
   int ab_code=19, x=line_ndx;
 
   pi = e_pos;
   ch = p_string[pi];

printf("get_input #1 pi = %d\n",pi);
printf("get_input #1 ch = %s\n",ch);

   if(ch == ';')
   {
     loc = 1;
     pi++;
     pi = iswhite(pi);
     ch = p_string[pi];
     e_pos = pi;
   }

   len = strlen(p_string);

printf("get_input #2 pi = %d\n",pi);
printf("get_input len = %d\n",len);

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
     else
     {
       if(isalpha(ch))
       {
         type = get_vtype(pi);

printf("get_input type = %d\n",type);

         strcpy(varname, get_varname());

printf("get_input varname = %s\n",varname);
printf("get_input loc = %d\n",loc);

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
}


void input_str(char *name, int loc)
{
  char ch, varname[VAR_NAME], string[BUFSIZE];
   int pi, ndx,len,for,col;
   int xsize;

  strcpy(varname, name);

printf("input_str varname = %s\n",varname);

  ndx = get_varndx(varname);

printf("input_str loc = %d\n",loc);

  if(loc == 1)
  {
    gets(string);
    len = strlen(string);
  }
  else
  {
    gets(string);
  }

printf("input_str string = %s\n",string);

  strcpy(sv_stack[ndx], string);

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

   ndx = get_varndx(varname);
   iv_stack[ndx] = atoi(string);

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




