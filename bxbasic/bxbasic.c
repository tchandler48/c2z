   
/*	bxbasic.c	*/

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

	
/*	bxbasic.c	*/
       void pgm_parser(void);
       void get_token(void);
       void parser(void);
       void xstring_array(void);
       void go_to(void);
       void do_gs(void);
       void do_ret(void);


/*	error.c	*/
	void a_bort(int, int);


/*	getinput.c	*/
       void get_input(void);
       void input_str(char *, int);
       void input_val(char *, int);
       void set_TabNl(char *);


/*     Ifendif.c	*/
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


/* 	input.c	*/
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


/*     loops.c	*/
      void do_loop(void);
      void do_next(void);
       int get_From(void);
       int get_To(void);
       int get_Step(void);


/*	output.c	*/
      void get_prnstring(void);
      void get_prnvar(void);
      void locate(void);
      void beep(void);
      void cls(void);
      void get_vartype(void);
      void get_strvar(void);


/*	rdparser.c	*/
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



/*	strings.c	*/
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


/*	utility.c	*/
       int get_upper(int, int);
       int get_alpha(int, int);
       int get_digit(int, int);
       int iswhite(int);
      void clr_arrays(void);
       int iswhiter(int);
       int find_strng(char *);

/*	variable.c	*/
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


#include "error.c"
#include "getinput.c"
#include "Ifendif.c"
#include "input.c"
#include "loops.c"
#include "output.c"
#include "rdparser.c"
#include "strings.c"
#include "utility.c"
#include "variable.c"


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
 /*     clr_vars(); */
      break;

    case 3:
      locate();
      break;

    case 4:
 /*     xstring_array(); */
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
 /* while(isalnum(ch)) */
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

