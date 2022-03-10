 
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
     double *dv_stack;
       char **dn_stack;
        int dmax_vars = 0;

       char **sv_stack;
       char **sn_stack;
        int smax_vars = 0;
	
/*	bxbasic.c	*/
       void pgm_parser(void);
       void get_token(void);
       void parser(void);
       void go_to(void);

/*	error.c	*/
	void a_bort(int, int);

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

       void program_array(void);

/*	output.c	*/
       void beep(void);
       void cls(void);
       void get_prnstring(void);
       void get_prnvar(void);
       void locate(void);
       char get_vartype(void);
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


/*	utility.c	*/
       int get_upper(int, int);
       int get_alpha(int, int);
       int get_digit(int, int);
       int iswhite(int);
      void clr_arrays(void);
       int iswhiter(int);


/*	variable.c	*/
      void parse_let(void);
       int get_varvalue(void);
      char get_varname(void);
       int get_intndx(char *);
       int get_dblndx(char *);
       int get_varndx(char *);
      void strng_assgn(int);

      void clr_vars(void);
      void clr_int(void);
      void clr_dbl(void);

      void init_int(void);
      void init_dbl(void);
      void init_str(void);


#include "error.c"
#include "input.c"
#include "output.c"
#include "rdparser.c"
#include "utility.c"
#include "variable.c"


int main(int argc, char *argv[])
{	
  int I;

  printf("BXBasic Intepreter\n");
  line_cnt(argv);
  pgm_parser();
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
      clr_vars();
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

    case -1:
      break;

    default:
      a_bort(ab_code, x);
      break;
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
    xtest = strncmp(go_to_label, temp_label[pi],x9);
    if(pi == nrows)
    {
       a_bort(ab_code, x);
    }
  }
 
  pi--;
  line_ndx = pi;
}


