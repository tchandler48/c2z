
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
        int frnxt_flg = 0;

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

        int *gosub_stack;
        int gs_ptr = -1;

       void pgm_parser(void);
       void get_token(void);
       void parser(void);
       void go_to(void);
       void do_gs(void);
       void do_ret(void);


       void do_iloop(void);
        int bolexpress(void);
        int Nbolterm(int);
        int Nrelation(double);
        int eval_value(double,double,int);
        int AndOrBolExp(void);
        int IsAndOrOp(void);
        int Sbolterm(int);
        int Srelation(char *);
        int eval_string(char *,char *,int);
        int get_vtype(void);
        int get_type(void);
        int get_string(void);
       void get_qstring(void);
        int get_op(void);
        int find_endf(int);
        int find_els(int);
        int if_eof(void);
        int is_eof(void);


	void a_bort(int,int);


       void clr_iohandles(void);
       void parse_open(void);
       void get_iomode(int);
       void fopen_short(char, int, int);
       void do_fclose(void);
       void input_io(void);
       void get_finput(int, int);
       void read_fstring(int, char *);
       void read_fvalue(int, char *);
       void write_io(void);
       void get_foutput(int, int);
        int write_fstring(int, int, char *);
        int write_fvalue(int, int, char *);

	void line_cnt(char *argv[]);
	void load_src(void);
       void save_tmp(void);
       void tmp_byte(int);
       void loader_1(void);
       void tmp_label(int);
        int get_byte(int);
       void tmp_prog(int);
       void loader_2(void);
        int find_strng(char *);
       void token_if(int);
       void str_functn(int);
       void str_func(char *, int);
        int IsEqu(int);
       void get_strfunc(char *, int);
       void str_copy(char *, int);


    void get_input(void);
    void input_str(char *,int);
    void input_val(char *,int);
    void get_lninput(void);


	void do_loop(void);
	void do_next(void);
	 int get_From(void);
	 int get_To(void);
	 int get_Step(void);
	 int get_avalue(void);
	

	void beep(void);
	void cls(void);
	void get_prnstring(void);
	void get_prnvar(void);
       void get_strvar(void);
       char get_vartype(void);
       void set_TabNl(int);


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


       void parse_str(char *);
       void strvar_assgn(int);
       void asn_function(void);
       void chrstr(void);
       void leftstr(void);
       void rightstr(void);
       void midstr(void);
       void spacestr(void);
       void strsval(void);
       void stringstr(void);
       void get_strndx(void);
       void inkeystr(void);


	 int get_upper(int,int);
	 int get_alpha(int,int);
	 int get_digit(int,int);
	 int iswhite(int);
        int clr_arrays(void);
       void clr_str(void);
        int iswhiter(int);
	

	void parse_let(void);
        int get_varvalue(void);
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
      printf(" End of Program\n");
      line_ndx = nrows;
      break;

    case 9:
      do_gs();
      break;

    case 10:
      do_ret();
      break;

    case 11:
      do_loop();
      break;

    case 12:
      do_next();
      break;

    case 13:
      do_iloop();
      break;

    case 14:
      do_iloop();
      break;

    case 15:
      return;
      break;

    case 16:
      return;
      break;

    case 17:
      get_input();
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


void do_gs()
{
  unsigned size;

  gs_ptr++;
  if(gs_ptr == 0)
  {
    size = 1;
    gosub_stack = malloc(size * sizeof(int));
  }
  else
  {

    size = gs_ptr + 1;
    gosub_stack = realloc(gosub_stack, size * sizeof(int));
  }
  gosub_stack[gs_ptr] = line_ndx;
  go_to();
}


void do_ret()
{
  unsigned size;

  if(gs_ptr < 0)
  {
    return;
  }
  else
  {
    if(gs_ptr == 0)
    {
      line_ndx = gosub_stack[gs_ptr];
    }
    else
    {
      line_ndx = gosub_stack[gs_ptr];
    }
  }
  gs_ptr--;
}

  


void do_iloop()
{
  int bol;
  int els_ndx;
  int end_ndx;

  bol = bolexpress();

printf("do_iloop bol = %d\n",bol):

  if(bol == 1)
  {
    els_ndx = find_els(line_ndx);
    end_ndx = find_endf(line_ndx);

    line_ndx++;
    while(line_ndx < els_ndx)
    {
      s_pos = 0;
      e_pos = 0;
      get_token();
      if(token == 5)
      {
        break;
      }
      parser();
      line_ndx++;
    }
    if(token == 5)
    {
      line_ndx--;
      return;
    }
    line_ndx = end_ndx;
  }
  else
  {
    els_ndx = find_els(line_ndx);
    els_ndx--;
    line_ndx = els_ndx;
  }
}


int find_els(int ndx)
{
  int tok = 0;

  while((tok != 14) && (tok != 15) && (tok != 16))
  {
    ndx++;
    tok = byte_array[ndx];
    if(tok == 13)
    {
      ndx = find_endf(ndx);
    }
  }
  return ndx;
}


int find_endf(int ndx)
{
  int tok = 0;

  while(tok != 15)
  {
    ndx++;
    tok = byte_array[ndx];
    if(tok == 11)
    {
      ndx = find_endf(ndx);
    }
  }
  return ndx;
}


int bolexpress()
{
  int bol;
  int type;
  int a_bol;
  int or_bol;
  int op;
  int ab_code = 17;
  int x=line_ndx;

  type = get_vtype();

printf("bolexpress type = %d\n",type);

  if((type == 1) || (type == 2))
  {
printf("bolexpress 1 or 2 type = %d\n",type);
    bol = Nbolterm(type);
  }
  else
  {
    if((type == 3) || (type == 4))
    {
printf("bolexpress 3 or 4\n");
      bol = Sbolterm(type);
    }
  }
  else
  {
    a_bort(ab_code, x);
  }
printf("bolexpress bol = %d\n",bol);
  return bol;
}


int AndOrBolExp()
{
  int bol;
  int type;
  int ab_code=17;
  int x=line_ndx;

  type = get_vtype();
  if((type == 1) || (type == 2))
  {
    bol = Nbolterm(type);
  }
  if((type == 3) || (type == 4))
  {
    bol = Sbolterm(type);
  }
  return bol;
}



int Nbolterm(int type)
{
  char ch;
  int pi;
  int bol;
  int a_bol=0;
  int lvalue;

printf("Nbolterm START type = %d\n",type);

  if(type == 1)
  {
printf("Nbolterm b4 avalue\n");
    lvalue = get_avalue();
printf("Nbolterm lvalue = %d\n",lvalue);
  }
  else
  {
    lvalue = rdp_start();
  }
  bol = Nrelation(lvalue);
printf("Nbolterm bol = %d\n",bol);
  return bol;
}


int Nrelation(int lvalue)
{
  int bol;
  int op;
  int type;
  int ab_code=17;
  int x=line_ndx;
  int rvalue;

  op = get_op();
  type = get_vtype();
  if(type == 1)
  {
    rvalue = get_avalue();
  } 
  else
  {
    if(type == 2)
    {
      rvalue = rdp_start();
    }
    else
    {
      a_bort(ab_code, x);
    }
  }
  bol = eval_value(lvalue, rvalue, op);
  return bol;
}


int eval_value(int lval, int rval, int op)
{
  int bol = 0;

  if(op == 1)
  {
    if(lval == rval)
    {
      bol = 1;
    }
  }

  if(op == 2)
  {
    if(lval < rval)
    {
      bol = 1;
    }
  }

  if(op == 3)
  {
    if(lval > rval)
    {
      bol = 1;
    }
  }

  if(op == 4)
  {
    if(lval <= rval)
    {
      bol = 1;
    }
  }

  if(op == 5)
  {
    if(lval >= rval)
    {
      bol = 1;
    }
  }
  
  if(op == 6)
  {
    if(lval != rval)
    {
      bol = 1;
    }
  }
  return bol;
}


int Sbolterm(int type)
{
  char lstring[BUFSIZE];
  int bol;
  int ndx;

printf("Sbolterm type = %d\n",type);

  if(type == 1)
  {
    ndx = get_string();
    strcpy(lstring, sv_stack[ndx]);
  }
  else
  {
    get_qstring();
    strcpy(lstring, s_holder);
  }
  bol = Srelation(lstring);
printf("Sbolterm bol = %d\n",bol);
  return bol;
}


int Srelation(char *lstr)
{
  char lstring[BUFSIZE];
  char rstring[BUFSIZE];
  int bol;
  int ndx;
  int op;
  int type;
  int ab_code=17;
  int x=line_ndx;

  strcpy(lstring, lstr);
printf("Srelation lstring = %s\n",lstring);

  op = get_op();
printf("Srelation op = %d\n",op);

  type = get_vtype();
printf("Srelation type = %d\n",type);

  if(type == 3)
  {
    ndx = get_string();
printf("Srelation ndx = %d\n",ndx);

    strcpy(rstring, sv_stack[ndx]);
  }
  if(type == 4)
  {
    get_qstring();
    strcpy(rstring, s_holder);
  }

  bol = eval_string(lstring, rstring, op);
  return bol;
}


int eval_string(char *lstr, char *rstr, int op)
{
  char lstring[BUFSIZE];
  char rstring[BUFSIZE];
  int bol = 0;
  int comp;

  strcpy(lstring, lstr);
  strcpy(rstring, rstr);
  comp = strcmp(lstring, rstring);

  if(op == 1)
  {
    if(comp == 0)
    {
      bol = 1;
    }
  }

  if(op == 2)
  {
    if(comp < 0)
    {
      bol = 1;
    }
  }

  if(op == 3)
  {
    if(comp > 0)
    {
      bol = 1;
    }
  }

  if(op == 4)
  {
    if(comp <= 0)
    {
      bol = 1;
    }
  }

  if(op == 5)
  {
    if(comp >= 0)
    {
      bol = 1;
    }
  }

  if(op == 6)
  {
    if(comp != 6)
    {
      bol = 1;
    }
  }
  return bol;
}

int IsAndOrOp()
{
  char ch;
  int pi;
  int op= 0;

  pi = e_pos;
  pi = iswhiter(pi);
  ch = p_string[pi];
  if(ch == '!')    /*  ch == '&'  */
  {
    op = 1;
    pi++;
    pi = iswhiter(pi);
  }
  else
  {
    if(ch == '|')
    {
      op = 2;
      pi++;
      pi = iswhiter(pi);
    }
  }
  e_pos = pi;
  return op;
}


int get_type()
{
  char ch;
  int pi;
  int type = 0;

  pi = e_pos;
  pi = iswhiter(pi);
  ch = p_string[pi];

printf("get_type p_string = %s\n",p_string);
printf("get_type pi = %d\n",pi);
printf("get_type ch = %s\n",ch);

  if(isalpha(ch))
  {
    type = get_vtype(pi);
  }
  else
  {
    if(isdigit(ch))
    {
      type = 1;
    }
  }
  else
  {
    if(ch == '(')
    {
      type = 2;
    }
  }
  else
  {
    if(ch == '\"')
    {
      type = 4;
    }
  }
  e_pos = pi;
  return type;
}


int get_vtype(int pi)
{
  char ch;
  int type = 0;

  ch = p_string[pi];
  while(isalnum(ch))
  {
    pi++;
    ch = p_string[pi];
  }

  pi--;
  ch = p_string[pi];

  if(strchr("$",ch)
  {
    type = 3;
  }
  else
  {
    if(strchr(" ", ch)
    {
      type = 1;
    }
  }
  e_pos = pi;
  return type;
}


int get_string()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int ndx=0;
  int ab_code=13;
  int x=line_ndx;

  strcpy(varname, get_varname());
printf("get_string varname = %s\n",varname);

  while((ndx < smax_vars) && (strcmp(sn_stack[ndx], varname) != 0))
  {
    ndx++;
  }
  if(ndx == smax_vars)
  {
    a_bort(ab_code, x);
  }

  pi = e_pos;
  pi++;
  pi = iswhiter(pi);
  ch = p_string[pi];
  e_pos = pi;
  return ndx;
}


void get_qstring()
{
  char ch;

  int pi;
  int si=0;
  int stlen;
  int ab_code=6;
  int x=line_ndx;

  stlen = strlen(p_string);
  stlen++;

  pi = e_pos;

  pi++;
  ch = p_string[pi];
  while(ch != '\"')
  {
    pi++;
    ch = p_string[pi];
printf("get_qstring #1 pi = %d\n",pi);
printf("get_qstring #1 ch = %s\n",ch);

  }

   pi++;
   ch = p_string[pi];
printf("get_qstring #2 pi = %d\n",pi);
printf("get_qstring #2 ch = %s\n",ch);
printf("get_qstring #2 stlen = %d\n",stlen);

  si = 0;
  while(ch != '\"')
  {
    s_holder[si] = ch;
    si++;
    pi++;
    ch = p_string[pi];
  }
  s_holder[si] = '\0';
printf("get_qstring s_holder = %s\n",s_holder);
printf("get_qstring si = %d\n",si);

  if(pi == stlen)
  {
    a_bort(ab_code, x);
  }
  pi++;
  e_pos = pi;
}
 

int get_op()
{
  char ch;

  int pi;
  int op;
  int ab_code=10;
  int x=line_ndx;

  pi = e_pos;
  ch = p_string[pi];

printf("get_op #1 pi = %d\n",pi);
printf("get_op #1 ch = %s\n",ch);

  if(strchr("$", ch))
  {
    pi++;
  }
  pi = iswhite(pi);
  ch = p_string[pi];
printf("get_op #2 pi = %d\n",pi);
printf("get_op #2 ch = %s\n",ch);

  if(ch == '=')
  {
    op = 1;
  }
  else
  {
    if(ch == '<')
    {
      pi++;
      ch = p_string[pi];
      if(ch == '>')
      {
        op = 6;
      }
      else
      {
        if(ch == '=')
        {
          op = 6;
        }
      }
      else
      {
         op = 2;
      }
    }
  else
    {
      if(ch == '>')
      {
        pi++;
        ch = p_string[pi];
        if(ch == '=')
        {
          op = 5;
        }
        else
        {
          op = 1;
        }
      }
    }
  }

  if(strchr("=>", ch))
  {
    pi++;
  }
  e_pos = pi;
  return op;
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



void get_lninput()
{   
  char ch;
  char varname[VAR_NAME];
  int pi;
  int loc=0;

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
  if(ch == '\"')          	
  {
    get_prnstring();
    pi = e_pos;
    pi++;
    pi = iswhite(pi);
    ch = p_string[pi];
    e_pos = pi;
  }
  strcpy(varname, get_varname());
  input_str(varname,loc);
}


void get_input()
{   
  char ch;
  char varname[VAR_NAME];
  int pi;
  int len;
  int type;
  int loc=0;
  int ab_code=19;
  int x=line_ndx;

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
    e_pos = pi;
    if(isalpha(ch))
    {
      type = get_vtype(pi);
      e_pos = pi;
      strcpy(varname, get_varname());
      if(type == 3)       	
      {
        input_str(varname,loc);
        pi = e_pos;
        ch = p_string[pi];
      }
      else  		 
      {
        input_val(varname,loc);
        pi = e_pos;
        ch = p_string[pi];
      }
    }
    else
    {
      a_bort(ab_code, x);
    }
  }
}


void input_val(char *name, int loc)
{   
  char ch;
  char cx;
  char varname[VAR_NAME];
  char string[VAR_NAME];
  int pi;
  int ndx;
  int len;
  int row, col;

  strcpy(varname, name);
  pi = e_pos;
  ch = p_string[pi];

  if(loc == 1)
  {
    gets(string);
    len = strlen(string);
    reset_cursor(loc,len,col,row);
  }
  else
  {
    gets(string);
  }
  
  if(ch == '#')
  {
    ndx = get_varndx(varname);
    dv_stack[ndx] = atof(string);
    pi++;
  }
 
  else if(ch == '!')
  {
    ndx = get_varndx(varname);
    fv_stack[ndx] = atof(string);
    pi++;
  }

  else if(ch == '%')
  { 
    ndx = get_varndx(varname);
    lv_stack[ndx] = atol(string);
    pi++;
  }
  
  else
  {
    ndx = get_varndx(varname);
    iv_stack[ndx] = atoi(string);
  }
  pi = iswhite(pi);
  ch = p_string[pi];
  if(strchr(":;,", ch))
  {
    pi++;
    set_TabNl(ch);			
  }
  pi = iswhite(pi);
  e_pos = pi;
}


void input_str(char *name, int loc)
{   
  char ch;
  char varname[VAR_NAME];
  char string[BUFSIZE];
  int pi;
  int ndx;
  int len;
  int row;
  int col;
  int xsize;

  strcpy(varname, name);

  ndx = get_varndx(varname);

  if(loc == 1)
  {
    gets(string);
    len = strlen(string);
    reset_cursor(loc,len,col,row);
  }
  else
  {
     gets(string);
  }

  xsize = strlen(string);
  xsize++;
  sv_stack[ndx] = realloc(sv_stack[ndx], xsize * sizeof(char));
  strcpy(sv_stack[ndx], string);              

  pi = e_pos;
  pi++;
  ch = p_string[pi];
  if(strchr(":;,", ch))
  {
    pi++;
    set_TabNl(ch);			
  }
  pi = iswhite(pi);
  e_pos = pi;
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



void do_loop()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int f_ndx;
  int Inc=1;
  int ab_code;
  int start;
  int next_tru;
  int x=line_ndx;
  int From;
  int Final;
		
  f_ndx = get_From();
  Final = get_To();

  pi = e_pos;
  ch = p_string[pi];
  if(ch == 'S')
  {
    Inc = get_Step();
  }

  From = f_ndx;
  start = line_ndx;
  frnxt_flg++;

  if(From < Final)
  {
    for(; From <= Final; From += Inc)
    {
      next_tru = 1;
      line_ndx = start + 1;

      while(next_tru == 1)
      {
        get_token();
        e_pos = 0;
        s_pos = 0;
        parser();
        if(token == 12)
        {
          next_tru = 0;
          token = 0;
        }
        else
        {
          line_ndx++;
        }
      }
    }
  }
  else
  {
    for(; From >= Final; From += Inc)
    {
      next_tru = 1;
      line_ndx = start + 1;
      while(next_tru == 1)
      {
        get_token();
        s_pos = 0;
        e_pos = 0;
        parser();
        if(token == 12)
        {
          next_tru = 0;
          token = 0;
        }
        else
        {
          line_ndx++;
        }
      }
    }
  }
  frnxt_flg++;
}


int get_From()
{
  char ch;
  char varname[VAR_NAME];
  char cvalue[6];
  int f_ndx;
  int pi;
  int pi2;
  int sav_pi;
  int ab_code;
  int x=line_ndx;

  pi = e_pos;
  sav_pi = pi;
  strcpy(varname, get_varname());

  e_pos = pi;
  ch = p_string[pi];

  while(ch != '=')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];

  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];

  while(isdigit(ch))
  {
    pi2 = 0;
    while(ch != ' ')
    {
      cvalue[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    cvalue[pi2] = '\0';
    f_ndx = atoi(cvalue);
  }

  if(isalpha(ch))
  {
    e_pos = pi;
    f_ndx = get_varvalue();
    pi = e_pos;
  }

  ch = p_string[pi];
  e_pos = pi;
 		
  return f_ndx;
}


int get_To()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int pi2;
  int ab_code;
  int x=line_ndx;
  int Final;
  int x10 = 0;

  pi = e_pos;
  pi++;

  ch = p_string[pi];

  if(ch != 'T')
  {	
    ab_code = 7;
    a_bort(ab_code,x);
  }
  else
  {
    pi2 = 0;
    varname[pi2] = ch;
    pi++;
    ch = p_string[pi];
    pi2++;
    varname[pi2] = ch;
    pi2++;
    varname[pi2] = '\0';
   
    if(strcmp(varname, "TO") != 0)
    {
      ab_code=7;
      a_bort(ab_code,x);
    }
  }

  pi++;
  pi = iswhite(pi);
  ch = p_string[pi];

  if(isalpha(ch))
  {
    x10 = 1;
    e_pos = pi;
    Final = get_varvalue();
    pi = e_pos;
  }


  e_pos = pi;
  if((isdigit(ch)) && (x10 == 0))
  {
    Final = get_avalue();
  }
  else
  {
    if((isdigit(ch)) && (x10 == 0))
    {
      Final = get_avalue();
    }
  }

  return Final;
}


int get_Step()
{
  char ch, varname[VAR_NAME];
  int pi, Inc;
  int ab_code, x=line_ndx;
  char sav_ch;

  strcpy(varname, get_varname());
  if(strcmp(varname, "STEP") != 0)
  {
    ab_code=7;
    a_bort(ab_code,x);
  }
  pi = e_pos;
  pi = iswhiter(pi);
  ch = p_string[pi];
  if(IsAddop(ch))
  {
    sav_ch = ch;
    pi++;
    pi = iswhiter(pi);
    ch = p_string[pi];
  }
  e_pos = pi;
  if(isalnum(ch))
  {
    Inc = get_avalue();
  }
  else
  {
    ab_code = 15;
    a_bort(ab_code, x);
  }
  if(sav_ch == '-')
  {	
    Inc = 0 - Inc;
  }
  return Inc;
}

void do_next()
{
  int ab_code=16, x=line_ndx;

  if(frnxt_flg == 0)
  {
    a_bort(ab_code,x);
  }
}


int get_avalue()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int si=0;
  int value = 0;

  pi = e_pos;
  ch = p_string[pi];

  if(isalpha(ch))
  {
    e_pos = pi;
    strcpy(s_holder, get_varname());
    value = get_varvalue();
    pi = e_pos;
  }
  else
  {
      if(IsAddop(ch))
      {
        varname[si] = ch;
        si++;
        pi++;
        ch = p_string[pi];
      }
      si = 0;
      while(isdigit(ch) != 0)
      {
        varname[si] = ch;
        pi++;
        si++;
        ch = p_string[pi];
      }
      varname[si] = '\0';

      value = atoi(varname);
    }
 
  pi = iswhite(pi);
  e_pos = pi;
  return value;
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
  int si = 0;
  int stlen;
  int ab_code;
  int x=line_ndx;
  int s = 0;
  
  pi = e_pos;
  pi = iswhite(pi);
  ch = p_string[pi];

  if(ch == ':')
  {
    printf(" \n");
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

  stlen = strlen(p_string);
  if((ch != '\'') || (pi == stlen))
  {
    ab_code = 9;
    a_bort(ab_code, x);
  }
  else
  {
    ch = ' ';
    for(s=0; s < BUFSIZE; s++)
    {
      xstring[s] = ch;
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
  }

  pi++;
  pi = iswhite(pi);
  ch = p_string[pi];

  if(ch == ';')
  {
    printf(" %s",xstring);
  }
  else
  {
    printf(" %s\n",xstring);
  }
  e_pos = pi;
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
    printf(" %d", ivalue);
  }
  if(ch == ';')
  {
    printf(" %d",ivalue);
  }
  else
  {
    printf(" %d\n",ivalue);
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

  printf(" %s\n",sv_stack[ndx]);
}


void set_TabNl(int ch)
{
  if(ch == ',')
  {
    printf("\t");
  }
  else
  {
    printf("\n");
  }
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
    case 8:
        inkeystr();
        break;
    default:
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

void inkeystr()
{


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


int iswhiter(int pi)
{   
    char ch;

    ch = p_string[pi];                   
    while(ch == ' ')                   
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




void parse_let()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int stlen;
  int ndx=0;
  int x=line_ndx;
  int ab_code=11;
  int s;
	
  stlen = strlen(p_string);
  pi = e_pos;
  pi = get_alpha(pi, stlen);
  if(pi == stlen)
  {
    a_bort(ab_code,x);
  }

  e_pos = pi;
  strcpy(varname, get_varname());

  s = strlen(varname);
  ch = varname[s];

  if(ch == '$')
  {
    pi = e_pos;
    parse_str(varname);
  }
  else
  {
    pi = e_pos;
    ndx = get_intndx(varname);
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
      
      imax_vars++;
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
      smax_vars++;
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


char get_varname()
{
  char ch;
  char varname[VAR_NAME];
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




