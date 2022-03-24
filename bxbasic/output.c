/*	output.c	*/

void beep()
{

}


void cls()
{


}


void locate()
{

}

   
void get_prnstring()
{
  char ch;
  int pi;
  int si = 0;;
  char holder[BUFSIZE];
  char type;

  pi = e_pos;
  ch = p_string[pi];
  if(ch == ':')
  {
    printf("\n");
    return;
  }

  if(isalpha(ch))
  {
     type = get_vartype();
     if(type == '$')
     {
       get_strvar();
     }
     else
     {
       get_prnvar();
     }
     return;
  }

  pi++;
  ch = p_string[pi];
  while(ch != '\"')
  {
    xstring[si] = ch;
    si++; 
    pi++;
    ch = p_string[pi];
  }
  xstring[si] = '\0';
  pi++;
  ch = p_string[pi];
  
  printf(" %s\n",xstring);
}


void get_prnvar()
{
   char ch;
   int pi, ivalue;
   int process;

   pi = e_pos;
   pi = iswhite(pi);
   e_pos = pi;
   ivalue = get_varvalue();
   pi = e_pos;
   pi = iswhite(pi);
   ch = p_string[pi];
/*  comma = tab  semi-colon = no */
   process = 0;

   if(ch == ',')
   {
      printf(" %d",ivalue);
      process = 1;
   }
   
   if((ch == ':') && (process == 0))
   {
      printf(" %d\n",ivalue);
      process = 1;
   }

   if(process == 0)
   {
      printf(" %d\n",ivalue);
   }
}


char get_vartype()
{
   char ch;
    int pi;

   pi = e_pos;
   ch = p_string[pi];
   while(isalnum(ch))
   {
     pi++;
     ch = p_string[pi];
   }
   return ch;
}


void get_strvar()
{
  char ch, varname[VAR_NAME];
   int pi, ndx = 0, ab_code = 13, x = line_ndx;

  strcpy(varname, get_varname());

  while((strcmp(sn_stack[ndx], varname) != 0) && (ndx < smax_vars))
  {
    ndx++;
  }
 
  if(ndx == smax_vars)
  {
    a_bort(ab_code, x);
  }

  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  ch = p_string[pi];

  printf(" %s\n", sv_stack[ndx]);
}



