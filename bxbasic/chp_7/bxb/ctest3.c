
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

      char a[20];
      char b[20];
      char c[20];
      char d[20];

      int x;
      int I;
      int t;
      int ndx;
      int gv_ct;

#define MAX_VARS            25
#define VAR_NAME            16
#define BUFSIZE             64

      int iv_stack[MAX_VARS];
     char in_stack[MAX_VARS][VAR_NAME];

struct variables 						
	{
		 int gv_rct;
		char gv_name[VAR_NAME];
		char gv_cname[VAR_NAME];
		char gv_type[2];
		 int gv_lgth;
		 int gv_current_lgth;
	       char gv_value[VAR_NAME];
		 int gv_init;
		char gv_literal[BUFSIZE];
		 int gv_use_ct;
		char gv_dsect[VAR_NAME];
		 int gv_row;
		 int gv_column;
		char gv_label[VAR_NAME];
	 	char gv_table[VAR_NAME];
		char gv_aname[VAR_NAME];
		char gv_sv_reg[VAR_NAME];
		char gv_wk_reg[VAR_NAME];
		char gv_wk_strg[VAR_NAME];
		 int gv_flag;
	};

    struct variables         *gw_variable;                  

	 
int main(int argc, char *argv[])
{

  printf("Hello Z390 World - ctest3\n");

  ndx = 1;
  iv_stack[ndx] = 345;
  t = iv_stack[ndx];
  printf("t = %d\n",t);
  printf(" \n");
 
  for(I=0; I < 4; I++)
  { 
    printf("iv_stack = %d\n",iv_stack[I]); 
  }
  printf(" \n");

  ndx = 1;
  strcpy(in_stack[ndx], "abc");
  strcpy(a, "tuvwxyz");
  ndx = 2;
  strcpy(in_stack[ndx], a);

  for(I=0; I < 4; I++)
  {
    printf("in_stack = %s\n"),in_stack[I]);
  }
  printf(" \n");

  gv_ct = 0;

  t = 23;
  gw_variable[gv_ct].gv_rct = t;
 
  t = 673;
  gw_variable[gv_ct].gv_lgth = t;
  gv_ct++;


  for(I=0; I < 3; I++)
  {
    printf("gw_variable[I].gv_rct = %d\n",gw_variable[I].gv_rct);
    printf("gw_variable[I].gv_lgth = %d\n",gw_variable[I].gv_lgth);
  }

  gv_ct = 0;
  x = gw_variable[gv_ct].gv_lgth;
  printf("x = %d\n",x);

		
		
  printf("End of ctest3\n");
		
}


