
      char a[20];
      char b[20];
      char c[20];
      char d[20];
      char etest[20];

      int x;
      int I;
      int t;
      int s;
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

struct variables       *gw_variable;

int main(int argc, char *argv[])
{

  printf("Hello Z390 World - ctest4\n");

  free(gw_variable);

  ndx = 1;
  iv_stack[ndx] = 345;
  t = iv_stack[ndx];
  printf("#1 t = %d\n",t);
  printf(" \n");
 
  for(I=0; I < 4; I++)
  { 
    printf("#2 iv_stack = %d\n",iv_stack[I]); 
  }
  printf(" \n");

  ndx = 1;
  strcpy(in_stack[ndx], "abc");
  strcpy(etest, "tuvwxyz");
  printf("etest = %s\n",etest);
  ndx = 2;
  strcpy(in_stack[ndx], etest);
  s = strlen(etest);
  printf("etest lgth = %d\n",s);

  for(I=0; I < 4; I++)
  {
    printf("#3 in_stack = %s\n"),in_stack[I]);
  }
  printf(" \n");

  strcpy(a,"123456");
  printf("#4 a = %s\n",a);
  s = strlen(a);
  printf("#5 lgth a = %d\n",s);

  gv_ct = 0;
  strcpy(gw_variable[gv_ct].gv_name,"abcdefghi");

  gv_ct = 1;
  strcpy(gw_variable[gv_ct].gv_name, a);
  printf("#5a a - gv_name = %s\n",gw_variable[gv_ct].gv_name);

  gv_ct = 2;
  I = 0;
  strcpy(gw_variable[gv_ct].gv_name, gw_variable[I].gv_name);

  gv_ct = 0;
  printf("#6 gv_name = %s\n",gw_variable[gv_ct].gv_name);
  s = strlen(gw_variable[gv_ct].gv_name);
  printf("#7 s 9 gv_name = %d\n",s);
  gv_ct = 2;
  strcpy(gw_variable[gv_ct].gv_name, etest);

  for(I=0; I < 4; I++)
  {
    printf("#8 gv_name = %s\n"),gw_variable[I].gv_name);
  }
  printf(" \n");

  printf("End of ctest4\n");
		
}


