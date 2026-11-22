
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


/*     Ifendif.c        */
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


/*	error.c 	*/
	void a_bort(int,int);


/*	input.c	*/
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


/*	loop.c		*/
	void do_loop(void);
	void do_next(void);
	 int get_From(void);
	 int get_To(void);
	 int get_Step(void);
	 int get_avalue(void);
	

/*	output.c	*/
	void beep(void);
	void cls(void);
	void get_prnstring(void);
	void get_prnvar(void);
       void get_strvar(void);
       char get_vartype(void);


/*     rdparser.c    */
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


/*     strings.c     */
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


/* 	utility.c	*/
	 int get_upper(int,int);
	 int get_alpha(int,int);
	 int get_digit(int,int);
	 int iswhite(int);
        int clr_arrays(void);
       void clr_str(void);
        int iswhiter(int);
	

/*	variable.c 	*/
	void parse_let(void);
        int get_varvalue(void);
       void clr_int(void);
        int get_intndx(char *);
       int get_varndx(char *);
       void strng_assgn(int);
       char *get_varname(void);


#include "Ifendif.c"
#include "error.c"
#include "input.c"
#include "loops.c"
#include "output.c"
#include "rdparser.c"
#include "strings.c"
#include "utility.c"
#include "variable.c"


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

  

