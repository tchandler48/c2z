 
#define MAX_VARS     12
#define VAR_NAM      16
#define VAR_NAME     16
	
	int t;
	int x;
	int y;
	int z;
	int I;
       int imax_vars=0;
      char varname[VAR_NAM];
       int ndx;
       int ivalue;
      char cvalue[7];
      char in_stack[MAX_VARS][VAR_NAM];
       int iv_stack[MAX_VARS];
      char a[20];
      char b[20];
      char p_string[75];
       int gv_ct;


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

struct variables    *gw_variable;
	
int main(int argc, char *argv[])
	{
		printf("Hello Z390 World ctest5\n");
		
              strcpy(a, "123456");
              printf("a = %s\n",a);

              strcpy(b, a);
              printf("b = %s\n",b);

              t = 0;
              strcpy(in_stack[t], "123456");
              printf("in_stack[t] = %s\n",in_stack[t]);

              strcpy(varname, "abcdefg");
              printf("varname = %s\n",varname);
 
              t = 1;
              strcpy(in_stack[t], varname);
              printf("in_stack[t] = %s\n",in_stack[t]);

              strcpy(in_stack[1], varname);
              printf("in_stack[1] = %s\n",in_stack[1]);

              strcpy(p_string, in_stack[1]);
              printf("p_string #1 = %s\n",p_string);

              t = 1;
              strcpy(p_string, in_stack[t]);
              printf("p_string #2 = %s\n",p_string); 

              t = 1;  
              x = 2;
              strcpy(in_stack[x], in_stack[t]);
              printf("in_stack[x] = %s\n",in_stack[x]);

              t = 3;
              strcpy(in_stack[3], in_stack[x]);
              printf("in_stack[3] = %s\n",in_stack[t]);


              gv_ct = 1;
              strcpy(gw_variable[gv_ct].gv_name, varname);
              strcpy(gw_variable[3].gv_name, varname);

           
              x = 5;
		for(I=0; I < x; I++)
			{
				printf("in_stack = %s\n", in_stack[I]);
			}
		printf(" \n");


              x = 5;
              for(I=0; I < x; I++)
              {
                printf("gv_name = %s\n",gw_variable[I].gv_name);
              }


	}
  
