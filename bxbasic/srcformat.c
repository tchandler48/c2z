   

#define BUFSIZE             78
#define LINE_NUM            6
#define TOKEN_LEN           21
#define VAR_NAME            32
#define LLEN                33
#define TOKEN_LEN           21

	FILE *pgm, *f_out,*f_in;
	char prog_name[32];
	char p_string[BUFSIZE];
       char **array1;
	char t_holder[20];
	char s_holder[BUFSIZE];

        int nrows; 
 	 int ncolumns = BUFSIZE;
	 int line_ndx;
	 int s_pos, e_pos;
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

       char var_type;
        int *dv_stack;
       char **dn_stack;
        int dmax_vars = 0;

       char **sv_stack;
       char **sn_stack;
        int smax_vars = 0;

        int *gosub_stack;
        int gs_ptr = -1;

	
       void pgm_parser(void);
       void get_token(void);
       void parser(void);
       void xstring_array(void);
       void go_to(void);
       void do_gs(void);
       void do_ret(void);


	void a_bort(int, int);


       void get_input(void);
       void input_str(char *, int);
       void input_val(char *, int);
       void set_TabNl(char *);


	void do_iloop(void);
        int bolexpress(void);
        int Nbolterm(int);
        int Nrelation(int);
        int eval_value(int, int, int);
        int AndOrBolExp(void);
        int IsAndOrOp(void);
        int Sbolterm(int);
        int Srelation(char *);
        int eval_string(char *, char *, int);
        int get_type(void);
        int get_vtype(int);
        int get_string(void);
       void get_qstring(void);
        int get_op(void);
        int find_endf(int);
        int find_els(int);


       void line_cnt(char *argv[]);
       void load_src(void);
       void save_tmp(void);
       void tmp_byte(int);
       void loader_1(void);
       void tmp_label(int);
        int get_byte(int);
       void tmp_prog(int);
       void loader_2(void);
       void token_ix(void);


      void do_loop(void);
      void do_next(void);
       int get_From(void);
       int get_To(void);
       int get_Step(void);


      void get_prnstring(void);
      void get_prnvar(void);
      void locate(void);
      void beep(void);
      void cls(void);
      void get_vartype(void);
      void get_strvar(void);


	int rdp_start(void);
	int Expression(void);
       int Term(void);
	int Factor(void);
      void Match(char);
      void _GetChar(void);
       int GetNum(void);
       int IsAddop(char);
       int IsMultop(char);
       int Is_White(char);
      void SkipWhite(void);



	void parse_str(char *);
       void strng_assgn(int);
       void strvar_assgn(int);
   	void asn_function(void);
       void leftstr(void);
       void rightstr(void);
	void midstr(void);
       void spacestr(void);
       void strsval(void);
  	void stringstr(void);
       void str_functn(int);
        int IsEqu(int);
       void get_strfunc(char *, int);
       void str_copy(char *, int);
        int get_strndx(void);
       char *value2strng(int);


       int get_upper(int, int);
       int get_alpha(int, int);
       int get_digit(int, int);
       int iswhite(int);
      void clr_arrays(void);
       int iswhiter(int);
       int find_strng(char *);

      void parse_let(void);
       int get_varvalue(void);
      char get_varname(void);
       int get_intndx(char *);
       int get_dblndx(char *);
       int get_varndx(char *);
       int get_avalue(void);

      void clr_vars(void);
      void clr_int(void);
      void clr_dbl(void);

      void init_int(void);
      void init_dbl(void);
      void init_str(void);




int main(int argc, char *argv[])
{	
  printf("BXBasic Intepreter\n");
  line_cnt(argv);
  pgm_parser();
  clr_arrays();
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

  switch(token)
  {
    case 0: 
      break; 
    
    case 1:
      parse_let();
      break;

    case 2:
      break;

    case 3:
      locate();
      break;

    case 4:
      get_prnstring();
      break;

    case 5:
      go_to();
      break;
 
    case 6:
      break;

    case 7:
      break;

    case 8:
      printf("End of Program\n");
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
      a_bort(ab_code, x);
      break;
  }
}


void xstring_array()
{
  char ch;
  int pi = 0;
  int si = 0;
  int ab_code;
  int stlen;
  int x = line_ndx;

printf("xstring START\n");

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
    ab_code = 9;
    a_bort(ab_code, x);
  }
  else
  {
    pi++; 
    ch = p_string[pi]; 
    ch = ' ';
    while((ch != '\"') && (pi < stlen))
    {
       si++;
       pi++;
       ch = p_string[pi];
    }

    if((si <= 1) && (pi < stlen))
    {
      ab_code = 5;
      a_bort(ab_code,x);
    }

    if(pi >= stlen)
    { 
      ab_code = 6;
      a_bort(ab_code,x);
    }
  }
}


void go_to()
{
  char ch;
  char go_to_label[LLEN];
  int pi, si = 0, ab_code = 8;
  int xtest, stlen, x = line_ndx;
  int I;
  int x9;

  si = 0;
  pi = e_pos;
  pi = iswhite(pi);
  ch = p_string[pi];
  while(ch != '\0')
  {
    go_to_label[si] = ch;
    pi++;
    si++;
    ch = p_string[pi];
  }
  go_to_label[si] = '\0';

  x9 = si;
  if(si != 1)
  {
   x9--;
  }

  pi = 0;
  xtest = -1;
  while(xtest != 0)
  {
    pi++;
    if(pi == nrows)
    {
       a_bort(ab_code, x);
    }
    xtest = strncmp(go_to_label, temp_label[pi],x9);
  }
 
  pi--;
  line_ndx = pi;
}


void do_gs()
{
  int size;

  gs_ptr++;

  gosub_stack[gs_ptr] = line_ndx;

  go_to();
}


void do_ret()
{
  int size;

  if(gs_ptr < 0)
  {
    return;
  }

  if(gs_ptr == 0)
  {
    line_ndx = gosub_stack[gs_ptr]);
  }
  else
  {
    line_ndx = gosub_stack[gs_ptr];
  }
  gs_ptr--;
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
     printf("Case 3 Syntax error in program line: = %d\n",line_ndx);
     printf("Case 3 Variable p_string = %s\n",p_string);
     break;

   case 4:
     printf("Case 4 Syntax error in program line: = %d\n",line_ndx);
     printf("Case 4 Variable p_string = %s\n",p_string);
     break; 

   case 5:
     printf("Case 5 Variable p_string = %s\n",p_string);
     break;

   case 6:
     printf("Case 6 Variable p_string = %s\n",p_string);
     break;

   case 7:
     printf("Case 7 Error\n");
     break;

   case 8:
     printf("Case 8 Error\n");
     break;

   case 9:
     printf("Case 9 Syntax Error p_string = %s\n",p_string);
     break;

   case 10:
     printf("Case 10 Error\n");
     break;

   case 11:
     printf("Case 11 Syntax error:\n");
     printf("Case 11 Variable p_string = %s\n",p_string);
     break;

   case 12:
     printf("Case 12 Out of Stack Space\n");
     printf("Case 12 Variable p_string = %s\n",p_string);
     break;

   case 13:
     printf("Case 13 Variable Not Found p_string = %s\n",p_string);
     break;

   case 19:
     printf("Case 19 Syntax error:\n");
     printf("Case 19 Variable p_string = %s\n",p_string);
     break;


   default:
     printf("Program aborted, undefined error.");
     break;
  }
  exit(1);
}



  

void get_input()
{   
    char ch, varname[VAR_NAME];
    int pi, len, type, loc=0;
    int ab_code=19, x=line_ndx;

    pi = e_pos;
    ch = p_string[pi];

    if(ch == '#')		
    {
	return;
    }

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
        else 
        {
            if(isalpha(ch))
            {
              type = get_vtype(pi);
              strcpy(varname, get_varname());
            }

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
    }
}


void get_lninput()
{   
    char ch, varname[VAR_NAME];
    int pi, loc=0;

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


void input_str(char *name, int loc)
{   
    char ch, varname[VAR_NAME], string[BUFSIZE];
    int pi, ndx, len, row, col;
    int xsize;

    strcpy(varname, name);
 
    ndx = get_varndx(varname);

    gets(string);
     
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
 
    }
    pi = iswhite(pi);
    e_pos = pi;
}


void input_val(char *name, int loc)
{   
    char ch, cx;
    char varname[VAR_NAME];
    char string[VAR_NAME];

    int pi;
    int ndx;
    int len, row, col;
    int process = 0;

    strcpy(varname, name);
    pi = e_pos;
    ch = p_string[pi];

    gets(string);
    len = strlen(string);

    if(ch == '#')
    {   
        ndx = get_varndx(varname);
        pi++;
        process = 1;
    }

    if((ch == '!') && (process == 0))
    {   
        ndx = get_varndx(varname);
        pi++;
        process = 1;
    }

    if((ch == '%') && (process == 0))
    {   
        ndx = get_varndx(varname);
        lv_stack[ndx] = atol(string);
        pi++;
        process = 1;
    }

    if(process == 0)
    {   
        ndx = get_varndx(varname);
        iv_stack[ndx] = atoi(string);
    }

    pi = iswhite(pi);
    ch = p_string[pi];
    if(strchr(":;,", ch))
    {   
       pi++;
       		
    }
    pi = iswhite(pi);
    e_pos = pi;



}
}

void do_iloop()
{
  int bol, els_ndx, end_ndx;

  bol = bolexpress();

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

  while(tok != 16)
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


int bolexpress()
{
  int bol;
  int type;
  int a_bol, or_bol, op;
  int ab_code = 17, x=line_ndx;

  type = get_type();

  if((type == 1) || (type == 2))
  {
    bol = Nbolterm(type);
  }
  else
  {
    if((type == 3) || (type == 4))
    {
      bol = Sbolterm(type);
    }
  }
  else
  {
    a_bort(ab_code, x);
  }

  op = IsAndOrOp();

  while(op != 0)
  {
    if(op == 1)
    {
      a_bol = AndOrBolExp();
      if((bol == 1) && (a_bol == 1))
      {
        bol = 1;
      }
      else
      {
        bol = 0;
      }
    }
    else
    {
      if(op == 2)
      {
        or_bol = AndOrBolExp();
        if((bol == 1) || (or_bol == 1))
        {
          bol = 1;
        }
      }
      op = IsAndOrOp();
    }
  }
  return bol;
}


int AndOrBolExp()
{
  int bol, type;
  int ab_code=17, x=line_ndx;

  type = get_type();
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
  int pi, bol, a_bol=0;
  int lvalue;

  if(type == 1)
  {
    lvalue = get_avalue();
  }
  else
  {
    lvalue = rdp_start();
  }
  bol = Nrelation(lvalue);
  return bol;
}


int Nrelation(int lvalue)
{
  int bol, op, type;
  int ab_code=17, x=line_ndx;
  int rvalue;

  op = get_op();
  type = get_type();
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
  int bol, ndx;

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
  return bol;
}


int Srelation(char *lstr)
{
  char lstring[BUFSIZE];
  char rstring[BUFSIZE];
  int bol, ndx, op, type;
  int ab_code=17, x=line_ndx;

  strcpy(lstring, lstr);
  op = get_op();
  type = get_type();
  if(type == 3)
  {
    ndx = get_string();
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


int eval_string(char lstr, char rstr, int op)
{
  char lstring[BUFSIZE];
  char rstring[BUFSIZE];
  int bol = 0, comp;

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
  int pi, op= 0;

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
  int pi, type = 0;

  pi = e_pos;
  pi = iswhiter(pi);
  ch = p_string[pi];
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
  if(ch == '$')
  {
    type = 3;
  }
  else
  {
    if(strchr(" =<>", ch)
    {
      type = 1;
    }
  }
  return type;
}


int get_string()
{
  char ch, varname[VAR_NAME];
  int pi, ndx=0, ab_code=13, x=line_ndx;

  strcpy(varname, get_varname());

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
  int pi, si=0, stlen;
  int ab_code=6, x=line_ndx;

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
  int pi, op, ab_code=10, x=line_ndx;

  pi = e_pos;
  ch = p_string[pi];
  if(strchr("$", ch))
  {
    pi++;
  }
  pi = iswhite(pi);
  ch = p_string[pi];
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
          op = 4;
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
          op = 3;
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






void line_cnt(char *argv[])
{
  int pi;
  int len;
  int ii=0;
  int x=0;
  int ab_code=2;
  unsigned fnam_len;
  int I;

  nrows = 0;
  len = fnam_len;
  fnam_len += 5;                      
  prog_name = malloc(fnam_len * sizeof(char));
  
  pi = len - 4;
  if(strcmp(p_string, ".bas") != 0)         
  {
    strcat(prog_name, "bas");
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
printf("loader_1 p_string = %s\n",p_string);
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
  int x = ii, ab_code = 4;

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




void do_loop()
{
  char ch, varname[VAR_NAME];
  int pi, f_ndx, Inc = 1;
  int ab_code;
  int start, next_tru, x = line_ndx;
  int From, Final;
  int I;
		
  f_ndx = get_From();

  Final = get_To();

  pi = e_pos;
  ch = p_string[pi];

  if(ch == 'S')
  {
    Inc = get_Step();
  }

  From = iv_stack[f_ndx];
  start = line_ndx;

  frnxt_flg++;

  if(From < Final)
  {
    for(; From < Final; From += Inc)
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
  char ch, varname[VAR_NAME];
   int f_ndx, pi,sav_pi;
   int ab_code, x = line_ndx;
		
  pi = e_pos;
  sav_pi = pi;
  strcpy(varname, get_varname());

  e_pos = sav_pi;
  parse_let();
  pi = e_pos;
  ch = p_string[pi];
  f_ndx = get_varndx(varname);

  return f_ndx;
}


int get_To()
{
  char ch, varname[VAR_NAME];
  int pi, ab_code, x = line_ndx;
  int Final;

  pi = e_pos;
  ch = p_string[pi];

  if(ch != 'T')
  {
    ab_code = 7;
    a_bort(ab_code,x);
  }
  else
  {
    strcpy(varname, get_varname());
    pi = e_pos;
    ch = p_string[pi];
    if(strcmp(varname, "TO") != 0)
    {
      ab_code = 7;
      a_bort(ab_code,x);
    }
  }
  pi = iswhite(pi);
  ch = p_string[pi];
  e_pos = pi;
  if(isalnum(ch))
  {
    Final = get_avalue();
  }
  else
  {
    ab_code = 15;
    a_bort(ab_code,x);
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
    ab_code = 7;
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
  int ab_code = 16, x = line_ndx;

  if(frnxt_flg == 0)
  {
    a_bort(ab_code,x);
  }
}




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
  ch = p_string[pi];

  if(IsAddop(ch))
  {
    Value = 0;
  }
  else
  {
    Value = Term();
    pi = e_pos;
    ch = p_string[pi];
    e_pos = pi;
  }

  while(IsAddop(ch))  
  {
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
    ch = p_string[e_pos];
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
  ch = p_string[pi];
 
  while(IsMultop(ch))
  {
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
    ch = p_string[e_pos];
  }
  return Value;
}


int Factor()
{
  char ch;
  int value;
  int pi;

  pi = e_pos;
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

  int ab_code = 12;
  int ln = line_ndx;
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
    ch = p_string[e_pos];
  }
}


int GetNum()
{
  char ch;
  int pi, Value=0, ab_code = 13, ln = line_ndx;
  int si;
  char cvalue[6];

  pi = e_pos;
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
    e_pos++;
    pi = e_pos;
    ch = p_string[pi];
  }
  cvalue[si] = '\0';
  Value = atoi(cvalue);
  SkipWhite();
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
  ch = p_string[pi];
 
  x1 = 0;
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


void strvar_assgn(int ndx)
{
  int indx;

  indx = get_strndx();
  strcpy(s_holder, sv_stack[indx]);
}


int get_strndx()
{
  char varname[VAR_NAME];  
   int indx = 0, ab_code = 13, x = line_ndx;

  strcpy(varname, get_varname());

  while((strcmp(sn_stack[indx], varname) != 0) && (indx < smax_vars))
  {
    indx++;
  }

  if(indx == smax_vars)
  {
    a_bort(ab_code, x);
  }

  return indx;
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
  int I;

  stlen = strlen(p_string);
  e_pos++;
  pi = e_pos;
 
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

  if(pi == stlen)
  {
    a_bort(ab_code, x);
  }

  init_str();
  size = strlen(s_holder);
  size++;
  strcpy(sv_stack[ndx], s_holder);
}



void str_functn(int ndx)
{
  char ch, temp[VAR_NAME];
   int pi = 0, type;

  strcpy(p_string, temp_prog[ndx]);

  type = get_vtype(pi);

  if(type != 3)
  {
    return;
  }

  while(IsEqu(pi) == 0)
  {
    pi = e_pos;
    pi++;
  }

  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  ch = p_string[pi];

  if(isalpha(ch) == 0)
  {
    return;
  }
  else
  {
    if(isupper(ch) == 0)
    {
      return;
    }
  }

  e_pos = pi; 
  strcpy(temp, get_varname());
  e_pos = pi;
  get_strfunc(temp, ndx);
}



void get_strfunc(char *name, int ndx)
{
  char varname[VAR_NAME], temp[TOKEN_LEN];

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
  str_copy(temp, ndx);
}



void str_copy(char *temp, int ndx)
{
  char ch, tok[TOKEN_LEN];
   int pi, si = 0;
   int I;

  strcpy(tok, temp);

  pi = e_pos;
  ch = tok[si];

  if(ch == ' ')
  {
    while(ch == ' ')
    {
      p_string[pi] = ch;
      si++;
      pi++;
      ch = tok[si];
    }

    while(isdigit(ch))
    {
      p_string[pi] = ch;
      si++;
      pi++;
      ch = tok[si];
    }

    strcpy(temp_prog[ndx], p_string);
    e_pos = pi;
  }
}



int IsEqu(int pi)
{
  char ch;
  int bol = 0;

  pi = iswhite(pi);
  e_pos = pi;
  ch = p_string[pi];
  if(ch == '=')
  {
    bol = 1;
  }
  return bol;
}



void asn_function()
{
  int type;

  type = get_avalue();

  switch(type)
  {
    case 2:
      leftstr();
      break;

    case 3:
      rightstr();
      break;

    case 4:
      midstr();
      break;

    case 5:
      spacestr();
      break;

    case 6:
      strsval();
      break;

    case 7:
      stringstr();
      break;

    default:
      break;
  }
}


void leftstr()
{
  int i, pi, indx, count, len;

  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  e_pos = pi;

  indx = get_strndx();

  pi = e_pos;

  pi = pi + 2;

  pi = iswhite(pi);
  e_pos = pi;

  count = get_avalue();

  if(count < 1)
  {
    count = 0;
  }
  len = strlen(sv_stack[indx];

  if(count > len)
  {
    count = len;
  }

  for(i = 0; i < count; i++)
  {
    s_holder[i] = sv_stack[indx][i];
  }
  s_holder[count] = '\0';
}



void rightstr()
{
  int ii, pi, indx, count, len, left;

  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  e_pos = pi;

  indx = get_strndx();

  pi = e_pos;

  pi = pi + 2;

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

  for(ii = 0; ii < count; ii++, left++)
  {
    s_holder[ii] = sv_stack[indx][left];
  }
  s_holder[count] = '\0';
}



void midstr()
{
  char ch;
  int ii, pi, indx, count, len, left;

  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  e_pos = pi;

  indx = get_strndx();

  pi = e_pos;

  pi = pi + 2;

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

  len = strlen(sv_stack[indx];
  left--;

  if((left + count) > len)
  {
    count = len - left;
  }

  for(ii = 0; ii < count; ii++, left++)
  {
    s_holder[ii] = sv_stack[indx][left];
  }
  s_holder[count] = '\0';
}



void spacestr()
{
  int ii, pi, count;

  pi = e_pos;
  pi++;
  pi = iswhite(pi);
  e_pos = pi;

  count = get_avalue();
  if(count < 1)
  {
    count = 0;
  }
  else
  {
    if(count > 255)
    {
      count = 255;
    }
  }

  for(ii = 0; ii < count; ii++)
  {
    s_holder[ii] = ' ';
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

}



void stringstr()
{   
    char ch;
    char char_x;
  
    int ii;
    int pi;
    int count;
    int xxx;

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

    if(ch == '\"')               
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
        xxx =  get_avalue();
        char_x = xxx;
    }
    for(ii=0; ii < count; ii++)
    {   
        s_holder[ii] = char_x;
    }
    s_holder[count] = '\0';
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



void clr_arrays()
{
  int ii;

  for(ii = 0; ii < nrows; ii++)
  {
    free(label_nam[ii]);
    free(array1[ii]);
  }
  free(label_nam);
  free(byte_array);
  free(array1);
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



int find_strng(char *tmp)
{
  char ch, cx;
  char temp[TOKEN_LEN];
  char xxstring[TOKEN_LEN];
   int pi, i, mark;
   int len, len2;

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
      if(ch == '\"')
      {
        pi++;
        ch = p_string[pi];
        while(ch != '\"')
        {
          pi++;
          ch = p_string[pi];
        }
      }
      pi++;
      ch = p_string[pi];
    }
   
    if((pi == len) || (pi > len))
    {
      mark = 0;
      return mark;
    }

    mark = pi;
    for(i=0; i < len2; i++)
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





void parse_let()
{
   char ch;
   char varname[VAR_NAME];
  
   int pi, stlen;
   int ndx = 0, x = line_ndx;
   int ab_code = 11;
   int process = 0;
   int I;

   stlen = strlen(p_string);
   pi = e_pos;
   pi = get_alpha(pi, stlen);
   ch = p_string[pi];
   if(pi == stlen)
   {
     a_bort(ab_code, x);
   }

   e_pos = pi;
   strcpy(varname, get_varname());

   pi = e_pos;
   ch = p_string[pi];


   if(ch == '#')
   {
      process = 1;
      ndx = get_dblndx(varname);
      pi++;
      pi = iswhite(pi);
      e_pos = pi;
      Match('=');
      dv_stack[ndx] = rdp_start();
    }

    if(ch == '$')
    {
      process = 1;
      e_pos = pi;
      parse_str(varname);
    }
    
    if(process == 0)
    {
      process = 1;
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
  int ndx = 0;
  int vflag = 0;
  int vi_pos = 0;

  strcpy(varname, name);

  vflag = 0;

  while((strcmp(in_stack[ndx], varname) != 0) && (ndx < imax_vars))
  {
    if(vflag == 0)
    {
      if(in_stack[ndx] == ' ')
      {
        vi_pos = ndx;
        vflag = 0;
      }
    }
    ndx++;
  }

  if(ndx == imax_vars)
  {
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

int get_dblndx(char *name)
{
  char varname[VAR_NAME];
  int ndx = 0, vflag = 0, vi_pos = 0;

  strcpy(varname, name);

  while((strcmp(dn_stack[ndx], varname) != 0) && (ndx < dmax_vars))
  {
    if(vflag == 0)
    {
      if(dn_stack[ndx] == ' ')
      {
        vi_pos = ndx;
        vflag = 1;
      }
    }
    ndx++;
  }

  if(ndx == dmax_vars)
  {
    ndx = vi_pos;
    if(vflag == 0)
    {
      init_dbl();
      ndx = dmax_vars;
      ndx--;
      strcpy(dn_stack[ndx], varname);
    }
    else
    {
      strcpy(dn_stack[ndx], varname);
    }
  }
  return ndx;
}



char get_varname()
{
  char ch;
  char varname[VAR_NAME];
   int pi, si = 0;

  pi = e_pos;
  ch = p_string[pi];

  while(isalnum(ch) != 0)
  {
    varname[si] = ch;
    si++;
    pi++;
    ch = p_string[pi];
  }
  varname[pi] = '\0';
  e_pos = pi;
  return varname;
}



int get_varvalue()
{
  char ch;
  char varname[VAR_NAME];
  int pi;
  int ndx=0;
  int ab_code=13, x=line_ndx;
  int value; 
  int I;

  strcpy(varname, get_varname());

  pi = e_pos;
  ch = p_string[pi];
  var_type = ch;

  if(ch == '#')
  {
    while((strcmp(dn_stack[ndx], varname) != 0) && (ndx < dmax_vars))
    {
      ndx++;
    }
 
    if(ndx == dmax_vars)
    {
      a_bort(ab_code, x);
    }
    value = dv_stack[ndx];
    _GetChar();
  }
  else
  {
    while((strcmp(in_stack[ndx], varname) != 0) && (ndx < imax_vars))
    {
      ndx++;
    }
 
    if(ndx == imax_vars)
    {
      a_bort(ab_code, x);
    }
    value = iv_stack[ndx];
  }
  return value;
}


void init_int()
{
   int ndx;

   ndx = imax_vars;
   imax_vars++;
}


void init_dbl()
{
   int ndx;

   ndx = dmax_vars;
   dmax_vars++;
}


void clr_vars()
{
   clr_int();

}


void clr_int()
{
   int ndx;

}


void init_str()
{
  int ndx;
  unsigned size;

  if(smax_vars == 0)
  {
    ndx = smax_vars;
    smax_vars++;
    size = smax_vars;
  }
  else
  {
    ndx = smax_vars;
    smax_vars++;
    size = smax_vars;
  }
}



void clr_str()
{
  int ndx;

  if(smax_vars > 0)
  {
    smax_vars = 0;
    free(sv_stack);
    free(sn_stack);
  }
}


int get_varndx(char *name) 
{

  char varname[VAR_NAME];
  int ndx=0, vflag=0, vi_pos=0;

  strcpy(varname, name);

  while((strcmp(sn_stack[ndx], varname) != 0) && (ndx < smax_vars))
  {
    if(vflag == 0)
    {
      if(sn_stack[ndx] == '\0')
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
      init_str();
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



int get_avalue()
{
  char ch, varname[VAR_NAME];
   int pi, si=0;
   int value = 0;


  pi = e_pos;
  ch = p_string[pi];
  if(isalpha(ch))
  {
    e_pos = pi;
    value = get_varvalue();
    pi = e_pos;
  }
  else
  {
    if((isdigit(ch)) || (IsAddop(ch))
    {
      if(IsAddop(ch))
      {
        varname[si] = ch;
 	 si++;
	 pi++;
	 ch = p_string[pi];
      }
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
  }
  pi = iswhite(pi);
  e_pos = pi;
  return value;
}



