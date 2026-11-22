
#define BUFSIZE             100
#define LINE_NUM            6
#define TOKEN_LEN           21
#define VAR_NAME            32
#define LLEN                33
#define TOKEN_LEN           21
#define MAX_VARS           255

	FILE *pgm, *f_out,*f_in;
	char *prog_name;
	char p_string[BUFSIZE];
       char **array1;
	char t_holder[20];
	char s_holder[BUFSIZE];
	 int nrows;
 	 int ncolumns=BUFSIZE;
	 int line_ndx;
	 int s_pos;
        int e_pos;

       char xstring[BUFSIZE];
       char **temp_prog;
       char **temp_label;
        int *temp_byte;
        int *byte_array;
       char **label_nam;
        int token;
 
        int *iv_stack;
       char **in_stack;
	 int imax_vars = 0;

       char **sn_stack;
       char **sv_stack;
        int smax_vars = 0;

       void pgm_parser(void);
       void get_token(void);
       void parser(void);
       void xstring_array(void);
       void go_to(void);

	void a_bort(int,int);


	void line_cnt(char *argv[]);
	void load_src(void);
       void save_tmp(void);
       void tmp_byte(int);
       void loader_1(void);
       void tmp_label(int);
        int get_byte(int);
       void tmp_prog(int);
       void loader_2(void);
	

	void beep(void);
	void cls(void);
	void get_prnstring(void);
	void get_prnvar(void);
       void get_strvar(void);
       char get_vartype(void);


        int rdp_start(void);
        int Expression(void);
        int Term(void);
        int Factor(void);
       void _GetChar(void);
       void Match(char);
        int Is_White(char);
       void SkipWhite(void);
        int GetNum(void);
        int IsAddop(char);
        int IsMultop(char);


	 int get_upper(int,int);
	 int get_alpha(int,int);
	 int get_digit(int,int);
	 int iswhite(int);
        int clr_arrays(void);
       void clr_str(void);
	

	void parse_let(void);
        int get_varvalue(void);
       void init_int(void);
       void init_var(void);
       void clr_int(void);
        int get_intndx(char *);
       int get_varndx(char *);
       void strng_assgn(int);
       char *get_varname(void);




int main(int argc, char *argv[])
{	
  int I;

  printf("BXBasic Intepreter\n");
  line_cnt(argv);
  pgm_parser();
  printf(" \n");
  for(I=0; I < 6; I++);
  {
    printf("in_stack = %s\n",in_stack[I]);
  }

  printf(" \n");
  for(I=0; I < 6; I++)
  {
    printf("iv_stack = %d\n",iv_stack[I]);
  }

  printf(" \n");
  for(I=0; I < 6; I++);
  {
    printf("sn_stack = %s\n",sn_stack[I]);
  }

  printf(" \n");
  for(I=0; I < 6; I++);
  {
    printf("sv_stack = %s\n",sv_stack[I]);
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
  strcpy(p_string, array1[line_ndx]);
  token = byte_array[line_ndx];
}


void parser()
{
  int ab_code=4;
  int x=line_ndx;
  int I;

  switch(token)
  {
    case 0:
      break;

    case 1:
      parse_let();
      break;
	
    case 2:
      clr_arrays();
      break;
    
    case 3:
      break;
	
    case 4:
      xstring_array();
      get_prnstring(); 
      break;

    case 5:
      go_to();
      break;
	
    case 6:
      beep();
      break;
	
    case 7:
      cls();
      break;
	
    case 8:
      printf("End of Program\n");
      line_ndx = nrows;
      break;

    case -1:
      break;

    default:
      printf("parser Inside DEFAULT\n");
      printf("p_string = %s\n",p_string);
      a_bort(ab_code, x);
      break;
  }
}




void xstring_array()
{
  char ch;
  int pi;
  int si=0;
  int ab_code;
  int stlen;
  int x=line_ndx;

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
    }
  }
}


void go_to()
{
  char ch;
  char go_to_label[LLEN];
  int pi;
  int si=0;
  int ab_code=8;
  int xtest;
  int stlen;
  int x=line_ndx;

  pi = e_pos;
  pi = iswhite(pi);
  ch = p_string[pi];
  while(isalnum(ch))
  {
    go_to_label[si] = ch;
    pi++;
    si++;
    ch = p_string[pi];
  }
  go_to_label[si] = '\0';

  pi = -1;
  xtest = -1;
  while(xtest != 0)
  {
    pi++;
    xtest = strcmp(label_nam[pi], go_to_label);
    if(pi == nrows)
    {
       a_bort(ab_code, x);
    }
  }
  pi--;
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

void clr_str()
{
  int ndx = 0;

  for(ndx=0; ndx < MAX_VARS; ndx++)
  {
      sv_stack[ndx] =  '\0';
      sn_stack[ndx] =  '\0';
  }
}


void clr_arrays()
{

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
  char type;
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
  pi--;
  ch = p_string[pi];

  return ch;
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

void get_strvar()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int ndx=0;
  int ab_code=13;
  int x=line_ndx;

  strcpy(varname, get_varname());

  while(strcmp(sn_stack[ndx], varname) != 0) 
  {
    ndx++;
  }

  if(ndx > MAX_VARS)
  {
    a_bort(ab_code, x);
  }
  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  ch = p_string[pi];

  printf("%s\n",sv_stack[ndx]);
}




int rdp_start()
{
  int value;

  value = Expression();
  return value;
}

 
int Expression()
{
  char ch;
  int pi;
  int Value;

  pi = e_pos;
  pi++;
  ch = p_string[pi];

  if(IsAddop(ch))
  {
    Value = 0;
  }
  else
  {
    Value = Term();
    pi = e_pos;
    pi++;
    ch = p_string[pi];
    e_pos = pi;
  }

    while(IsAddop(ch))  
    {
      e_pos = pi;

      switch(ch)
      {
        case '+':
          Match('+');
          Value = Value + Term();
          break;
        case '-':
          Match('-');
          Value = Value - Term();
          break;
        default:
          break;
      }
    
      pi = e_pos;
      ch = p_string[pi];
      e_pos = pi;
    }
    return Value;
}

 
int Term()
{
  char ch;
  int pi;
  int Value;

  Value = Factor();
 
  pi = e_pos;
  pi++;
  ch = p_string[pi];

  while(IsMultop(ch))
  {
    e_pos = pi;

    switch(ch)
    {
      case '*':
        Match('*');
        Value = Value * Factor();
        break;
      case '/':
        Match('/');
        Value = Value / Factor();
        break;
      default:
        break;
    }
    pi = e_pos;
    ch = p_string[pi];
  }
  return Value;
}


int Factor()
{
  char ch;
  int value;
  int pi;

  pi = e_pos;
  pi++;
  ch = p_string[pi];

  if(ch == '(')
  {
    Match('(');
    value = Expression();
    Match(')');
  }
  else
  {
    if(isalpha(ch))
    {
      e_pos = pi;
      value = get_varvalue();
      SkipWhite();
    }
    else
    {
      value = GetNum();
    }
  }
  return value;
}


void Match(char x)
{
  char ch;
  char string[6];
  int ab_code=12;
  int ln=line_ndx;
  int pi;

  pi = e_pos;
  ch = p_string[pi];

  if(ch != x)
  {
    strcpy(string, "\");
    string[1] = x;
    strcpy(t_holder, string);
    a_bort(ab_code, ln);
  }
  else
  {
    _GetChar();
    SkipWhite();
  }
}


void _GetChar()
{
  e_pos++;
}


int Is_White(char ch)
{
  int test = 0;

  if(ch == ' ') 
  {
    test = 1;
  }
  return test;
}



void SkipWhite()
{
  char ch;
  int pi;
  
  pi = e_pos;
  ch = p_string[pi];
  while(ch == ' ')
  {
    _GetChar();
    pi = e_pos;
    ch = p_string[pi];
  }
}


int GetNum()
{
  char ch;
  int pi;
  int Value=0;
  int ab_code=13;
  int ln=line_ndx;
  int si;
  char cvalue[6];

  
  pi = e_pos;
  pi++;
  ch = p_string[pi];

  if(!isdigit(ch))
  {
    strcpy(t_holder, "Integer");
    a_bort(ab_code, ln);
  }
  si = 0;

  while(isdigit(ch))
  {
    cvalue[si] = ch;
    si++; 
    pi++;
    ch = p_string[pi];
  }
  cvalue[si] = '\0';
  Value = atoi(cvalue);
  SkipWhite();
  e_pos = pi;
  return Value;
}


int IsAddop(char ch)
{
  int rval = 0;

  if((ch == '+') || (ch == '-'))
  {
    rval = 1;
  }
  return rval;
}


int IsMultop(char ch)
{
  int rval = 0;    

  if((ch == '*') || (ch == '/'))
  {
    rval = 1;
  }
  return rval;
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
  int s;

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
  s = si - 1;
  ch = varname[s];

  if(ch == '$')
  {
    ndx = get_varndx(varname);
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
    Match('=');
    strng_assgn(ndx);
  }
  else
  {
    ndx = get_intndx(varname);
    pi++;
    pi = iswhite(pi);
    e_pos = pi;
    Match('=');
    iv_stack[ndx] = rdp_start();
  }
}



int get_intndx(char *name)
{
  char varname[VAR_NAME];
  int ndx=0;
  int vflag=0;
  int vi_pos=0;

  strcpy(varname, name);

  while((ndx < imax_vars) && (strcmp(in_stack[ndx], varname) != 0))
  {
    if(vflag == 0)
    {
      if(in_stack[ndx][0] == '\0')
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
      strcpy(in_stack[ndx], varname);
    }
    else
    {
      strcpy(in_stack[ndx], varname);
    }
  }
  return ndx;
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

  e_pos = pi;
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


int get_varndx(char *name) 
{
  char varname[VAR_NAME];
  int ndx=0;
  int vflag=0;
  int vi_pos=0;

  strcpy(varname, name);

  while((strcmp(sn_stack[ndx], varname) != 0) && (ndx < smax_vars))
  {
    if(vflag == 0)
    {
      if(sn_stack[ndx][0] == '\0')
      {
        vi_pos = ndx;
        vflag = 1;
      }
    }
    ndx++;
  }

  if(ndx == smax_vars)
  {
    ndx = vi_pos;

    if(vflag == 0)
    {
      init_var();
      ndx = smax_vars;
      ndx--;
      strcpy(sn_stack[ndx], varname);
    }
    else
    {
      strcpy(sn_stack[ndx], varname);
    }
  }
  return ndx;
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

  size = strlen(s_holder);
  size++;
  strcpy(sv_stack[ndx], s_holder);
}


char get_varname()
{
  char ch;
  static char varname[VAR_NAME];
  int pi;
  int si=0;

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

  e_pos = pi;
  return varname;
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

void init_var()
{
  int ndx;
  unsigned size;

  if(smax_vars == 0)
  {
     ndx = smax_vars;
     smax_vars++;
     size = smax_vars;
     iv_stack = malloc(size * sizzeof(long));
     in_stack = malloc(size * sizeof(char *));
     size = VAR_NAME;
     sn_stack[ndx] = malloc(size * sizeof(char));
  }
  else
  {
     ndx = smax_vars;
     smax_vars++;
     size = smax_vars;
     iv_stack = realloc(iv_stack, size * sizeof(long));
     in_stack = realloc(in_stack, size * sizeof(char *));
     size = VAR_NAME;
     sn_stack[ndx] = malloc(size * sizeof(char));
  }
}





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
  int pi, len;

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


