
#define BUFSIZE             78
#define LINE_NUM            6
#define TOKEN_LEN           21
#define MAX_VARS            100
#define VAR_NAME            32
#define LLEN                33
#define TOKEN_LEN           21

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
	

	void a_bort(int, int);
       void line_cnt(char *argv[]);
       void program_array(void);
       void pgm_parser(void);
       void get_token(void);
       void parser(void);
       void xstring_array(void);
       void get_prnstring(void);
       void go_to(void);



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

printf("line_ndx = %d\n",line_ndx);

  while(line_ndx < nrows)
  {
    s_pos = 0;
    e_pos = 0;
    get_token();

    parser();
    line_ndx++;
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
  while(!feof(f_in))
  {
      fgets(p_string, BUFSIZE, f_in);
      if(!feof(f_in))
      {
        line_counter++;
      }
  }
  fclose(f_in);
  nrows=line_counter;
}


void program_array()
{
  int ii;
  int jj;
  int len;
  int pi;
  int pi2;
  int I;
  char ch;
  char ln_holder[6];

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
  for(I = 0; I < 6; I++)
  {
    printf("array1 = %s\n",array1[I]);
  }

  for(I = 0; I < 6; I++)
  {
    printf("array2 = %s\n",array2[I]);
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
  printf("get_token p_string = %s\n",p_string);
  stlen = strlen(p_string);  
  printf("get_token stlen = %d\n",stlen);
  ch = p_string[pi];
  printf("get_token b4 isuuper ch = %s\n",ch);

  while((!isupper(ch)) && (pi < stlen))
  {
    pi++;
    ch = p_string[pi];
    printf("get_token inside isupp\n");
  }

  printf("get_token pi = %d\n",pi);
  if(pi == stlen)
  {
printf("get_token ab error\n");
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
  printf("get_token token = %s\n",token);
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

}

void xstring_array()
{
  char ch;
  int pi=0;
  int si=0;
  int ab_code;
  int stlen;
  int x=line_ndx;

  stlen = strlen(p_string);
  ch = p_string[pi];
  while((ch != '\"') && (pi < stlen))
  {
    pi++;
    ch = p_string[pi];
  }
  s_pos = pi;
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
    ab_code=5;
    a_bort(ab_code,x);
  }
  if(pi >= stlen)
  { 
    ab_code=6;
    a_bort(ab_code,x);
  }
  si++;
}

void get_prnstring()
{
  char ch;
  int pi = s_pos;
  int si = 0;;
  char holder[BUFSIZE];

  pi++;
  ch = p_string[pi];
  while(ch != '\"')
  {
    holder[si] = ch;
    si++; 
    pi++;
    ch = p_string[pi];
  }
  holder[si] = '\0';
  strcpy(xstring, holder);
  pi++;
  ch = p_string[pi];
  
  printf(" %s",xstring);
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
     printf("Case 9 Error\n");
     break;

   case 10:
     printf("Case 10 Error\n");
     break;

   case 11:
     printf("Case 11 Error\n");
     break;

   case 12:
     printf("Case 12 Error\n");
     break;

   case 13:
     printf("Case 13 Error\n");
     break;

   default:
     printf("Program aborted, undefined error.");
     break;
  }
  exit(1);
}



