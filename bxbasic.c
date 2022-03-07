 
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
       char **array2;
	char t_holder[20];
	char s_holder[BUFSIZE];
       char token[TOKEN_LEN];
       char xstring[BUFSIZE];
	 int nrows;
 	 int ncolumns = BUFSIZE;
	 int line_ndx;
	 int s_pos, e_pos;

        int *iv_stack;
       char **in_stack;
        int imax_vars = 0;
	
/*	bxbasic.c	*/
       void pgm_parser(void);
       void get_token(void);
       void parser(void);
       void xstring_array(void);
       void go_to(void);

/*	error.c	*/
	void a_bort(int, int);

/* 	input.c	*/
       void line_cnt(char *argv[]);
       void program_array(void);

/*	output.c	*/
      void get_prnstring(void);
      void get_prnvar(void);
      void locate(void);
      void beep(void);
      void cls(void);

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

/*	variable.c	*/
      void parse_let(void);
       int get_varvalue(void);
      void init_int(void);
      void clr_int(void);


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
  program_array();
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
  char ch;
  int pi=0;
  int ti=0;
  int ab_code = 3;
  int stlen;
  int x=line_ndx;

  strcpy(p_string, array1[line_ndx]);
  stlen = strlen(p_string);  
  pi = get_upper(pi, stlen);
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
  int ab_code = 4;
  int x = line_ndx;
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

  if(strcmp(token, "CLEAR") == 0)
  {
    clr_int();
    process = 1;
  }

  if(strcmp(token, "LOCATE") == 0)
  {
     locate();
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
  int pi = 0;
  int si = 0;
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
    ab_code = 9;
    a_bort(ab_code, x);
  }
  else
  {
    pi++;
    ch = p_string[pi];
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
    si++;
  }
}


void go_to()
{
  char ch;
  char gtl_holder[VAR_NAME];
  int pi = 0;
  int lh = 0;
  int ab_code;
  int xtest;
  int stlen;
  int x = line_ndx;
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

