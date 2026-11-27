
#define BUFSIZE             80
#define LINE_NUM            6
#define TOKEN_LEN           21
#define VAR_NAME            32
#define LLEN                33
#define TOKEN_LEN           21
#define MAX_VARS           255

	FILE *pgm, *f_out,*f_in;
	char *prog_name;
	char p_string[BUFSIZE];
       char array1[25][50];
       char array2[25][10];
	char t_holder[20];
	char s_holder[BUFSIZE];
       char token[TOKEN_LEN];
       char xstring[BUFSIZE];
	 int nrows;
 	 int ncolumns=BUFSIZE;
	 int line_ndx;
	 int s_pos, e_pos;

        int iv_stack[25];
       char in_stack[25][50];
	 int imax_vars = 0;

       void pgm_parser(void);
       void get_token(void);
       void parser(void);
       void xstring_array(void);
       void go_to(void);

/*	error.c 	*/
	void a_bort(int,int);

/*	input.c	*/
	void line_cnt(char *argv[]);
	void program_array(void);
	

/*	output.c	*/
	void beep(void);
	void cls(void);
	void get_prnstring(void);
	void get_prnvar(void);


/* 	utility.c	*/
	 int get_upper(int,int);
	 int get_alpha(int,int);
	 int get_digit(int,int);
	 int iswhite(int);
	

/*	variable.c 	*/
	void parse_let(void);
        int get_varvalue(void);
       void init_int(void);
       void clr_int(void);


#include "error.c"
#include "utility.c"
#include "output.c"
#include "variable.c"
#include "input.c"


int main(int argc, char *argv[])
{	
  int I;

  printf("BXBasic Intepreter\n");
  line_cnt(argv);
  program_array();
  pgm_parser();
  for(I=0; I < 6; I++);
  {
    printf("in_stack = %s\n",in_stack[I]);
  }

  for(I=0; I < 6; I++)
  {
    printf("iv_stack = %d\n",iv_stack[I]);
  }

  exit(1);
}


void pgm_parser()
{
  line_ndx = 0;
  while(line_ndx < nrows)
  {
    s_pos = 0;
    e_pos = 0;
    get_token();

    parser();
    line_ndx++;
  }
}
 

void get_token()
{
  char ch;
  int pi=0;
  int ti=0;
  int ab_code=3;
  int stlen;
  int x=line_ndx;

  strcpy(p_string, array1[line_ndx]);
  stlen = strlen(p_string);  
  pi = get_upper(pi,stlen);
  ch = p_string[pi];

  if(pi == stlen)
  {
    a_bort(ab_code, x);
  }
  while(isupper(ch))
  {
    token[ti] = ch;
    ti++;
    pi++;
    ch = p_string[pi];
  }

  token[ti] = '\0';
  e_pos = pi;
}


void parser()
{
  int ab_code=4;
  int x=line_ndx;
  int process;

  process = 0;
  if(strcmp(token, "REM") == 0)
  {
    process = 1;
  }

  if(strcmp(token, "LET") == 0)
  {
    parse_let();
    process = 1;
  }

  if(strcmp(token, "PRINT") == 0)
  {
    xstring_array();
    get_prnstring();
    process = 1;
  }

  if(strcmp(token, "GOTO") == 0)
  {
    go_to();
    process = 1;
  }

  if(strcmp(token, "BEEP") == 0)
  {
    process = 1;
  }

  if(strcmp(token, "CLS") == 0)
  {
    process = 1;
  }

  if(strcmp(token, "END") == 0)
  {
    process = 1;
    printf("End of Program\n");
    line_ndx = nrows;
  }

  if(process == 0)
  {
    a_bort(ab_code, x);
  }
}

void xstring_array()
{
  char ch;
  int pi;
  int si=0;
  int ab_code;
  int stlen;
  int  x=line_ndx;

  pi = e_pos;
  pi = iswhite(pi);
  e_pos = pi;
  ch = p_string[pi];
  if(ch == ':')
  {
    return;
  }
  if(isalpha(ch))
  {
    return;
  }
  stlen = strlen(p_string);
  if((ch != '\"') || (pi == stlen))
  {
    ab_code=9;
    a_bort(ab_code, x);
  }
  else
  {
    ch = ' ';
    while((ch != '\"') && (pi < stlen))
    {
      si++;
      pi++;
      ch = p_string[pi];
    }
    if((si <= 1) && (pi < stlen))
    {
      ab_code=5;
      a_bort(ab_code, x);
    }
    else
    {
      if(pi >= stlen)
      {
        ab_code=6;
        a_bort(ab_code, x);
      }
      else
      {
        si++;
      }
    }
  }
}



void go_to()
{
  char ch;
  char gtl_holder[VAR_NAME];
  int pi=0;
  int lh=0;
  int ab_code;
  int xtest;
  int stlen;
  int x=line_ndx;
  int z = 0;
 
  gtl_holder[0] = '\0';
  ch = p_string[pi];
  while(isdigit(ch))
  {
    ch = p_string[pi];
    pi++;
  }

  pi++;
  ch = p_string[pi];
  while(isupper(ch))
  {
    ch = p_string[pi];
    pi++;
  }

  ch = p_string[pi];
  if(isdigit(ch) == 0)
  {
    ab_code = 7;
    a_bort(ab_code, x);
  }

  while(isdigit(ch))
  {
    gtl_holder[lh] = ch;
    pi++;
    lh++;
    ch = p_string[pi];
  }
  gtl_holder[lh] = '\0';
 
  z = atoi(gtl_holder);

  z--;
  z--;
  pi = z;
  line_ndx = pi;
}





void a_bort(int code, int line_ndx)
{
  switch(code)
  {
    case 1:
      printf("Unspecified Program Name\n");
      break;

   case 2:
     printf("Unspecified Program Name\n");
     break;

   case 3:
     printf("Syntax error in program line: = %d\n",line_ndx);
     break;

   case 4:
     printf("Syntax error in program line: = %d\n",line_ndx);
     break; 

   case 5:
     printf("Case 5 Error\n");
     break;

   case 6:
     printf("Case 6 Error\n");
     break;

   case 7:
     printf("Case 7 Error\n");
     break;

   case 8:
     printf("Case 8 Error\n");
     break;

   case 9:
     printf("Case 9 Error Syntax error in program line: %d\n",line_ndx);
     break;

   case 10:
     printf("Case 10 Error\n");
     break;

   case 11:
     printf("Case 11 Error Syntax error in program line: = %d\n",line_ndx);
     break;

   case 12:
     printf("Case 12 Error Out of stack space line: = %d\n",line_ndx);
     break;

   case 13:
     printf("Case 13 Error Variable not found in line: %d\n",line_ndx);
     break;

   default:
     printf("Program aborted, undefined error.");
     break;
  }
  exit(1);
}




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




void beep()
{

}


void cls()
{


}


void get_prnstring()
{
  char ch;
  int pi;
  int si = 0;;
  
  pi = e_pos;
  ch = p_string[pi];

  if(ch == ':')
  {
    printf("\n");
    return;
  }
  else
  {
    if(isalpha(ch))
    {
      get_prnvar();
      return;
    }
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
  pi = iswhite(pi);
  ch = p_string[pi];

  if(ch == ';')
  {
    printf("%s",xstring);
  }
  else
  {
    printf)"%s\n",xstring);
  }

}



void get_prnvar()
{
  char ch;
  int pi;
  int ivalue;

  pi = e_pos;
  pi = iswhite(pi);
  e_pos = pi;
  ivalue = get_varvalue();
  pi = e_pos;
  pi = iswhite(pi);
  ch = p_string[pi];

  if(ch == ',')
  {
    printf("%d", ivalue);
  }
  if(ch == ';')
  {
    printf("%d",ivalue);
  }
  else
  {
    printf("%d\n",ivalue);
  }

}





void parse_let()
{
  char ch;
  char varname[VAR_NAME];
  char cvalue[6];
  int pi;
  int si=0;
  int stlen;
  int ndx=0;
  int x=line_ndx;
  int vflag=0;
  int vi_pos = 0;
  int ivalue;
  int ab_code;

  stlen = strlen(p_string);
  pi = e_pos;
  pi = get_alpha(pi, stlen);
  ch = p_string[pi];
  if(pi == stlen)
  {
    ab_code = 11;
    a_bort(ab_code, x);
  }
  si = 0;
  while((isalnum(ch) != 0)
  {
    varname[si] = ch;
    si++;
    pi++;
    ch = p_string[pi];
  }
  varname[si] = '\0';

  while((strcmp(in_stack[ndx], varname) != 0) && (ndx < imax_vars))
  {
    if(vflag == 0)
    {
     if(in_stack[ndx][0] == ' ')
      {
        vi_pos = ndx;
        vflag = 1;
      }
    }
    ndx++;
  }

  if(ndx == imax_vars)
  {
    ndx = vi_pos;
    if(vflag == 0)
    {
      init_int();
      ndx = imax_vars;
      ndx--;
      strcpy(in_stack[ndx],varname);
    }
    else
    {
      strcpy(in_stack[ndx], varname);
    }
  }

  pi = iswhite(pi);
  ch = p_string[pi];
  if(ch == '=')
  {
    pi++;
    pi = iswhite(pi);
    ch = p_string[pi];
    pi = get_digit(pi, stlen);
    ch = p_string[pi];
    vi_pos = 0;
 
    while((isdigit(ch) != 0) && (vi_pos <= 5))
    {
      cvalue[vi_pos] = ch;
      pi++;
      vi_pos++;
      ch = p_string[pi];
    }
    cvalue[vi_pos] = '\0';
    ivalue = atoi(cvalue);
    iv_stack[ndx] = ivalue;
  }
  else
  {
    ab_code = 0;
    a_bort(ab_code,x);
  }
}


int get_varvalue()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int si=0;
  int ndx=0;
  int ivalue;
  int ab_code=13;
  int x=line_ndx;

  pi = e_pos;
  ch = p_string[pi];
  while((isalnum(ch) != 0))
  {
    varname[si] = ch;
    si++;
    pi++;
    ch = p_string[pi];
  }
  varname[si] = '\0';
  ndx = 0;

  while(strcmp(in_stack[ndx], varname) != 0)
  {
    ndx++;
  }
 
  if(ndx == imax_vars)
  {
    a_bort(ab_code, x);
  }

  ivalue = iv_stack[ndx];

  e_pos = pi;
  return ivalue;

}


void init_int()
{
  int ndx;
  unsigned size;

  if(imax_vars == 0)
  {
     ndx = imax_vars;
     imax_vars++;
     size = imax_vars;
     iv_stack = malloc(size * sizzeof(long));
     in_stack = malloc(size * sizeof(char *));
     size = VAR_NAME;
     in_stack[ndx] = malloc(size * sizeof(char));
  }
  else
  {
     ndx = imax_vars;
     imax_vars++;
     size = imax_vars;
     iv_stack = realloc(iv_stack, size * sizeof(long));
     in_stack = realloc(in_stack, size * sizeof(char *));
     size = VAR_NAME;
     in_stack[ndx] = malloc(size * sizeof(char));
  }
}
}

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


