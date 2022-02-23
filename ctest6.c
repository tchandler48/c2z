 
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
      char c[20];
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

  struct variables         *gw_variable;                  



	
int main(int argc, char *argv[])
	{
		printf("Hello Z390 World ctest6\n");
		
              strcpy(a, "123456");
              printf("a = %s\n",a);

              strcpy(b, "abcdefghi");
              printf("b = %s\n",b);

              strcat(a,b);
              printf("a = %s\n",a);

              t = 0;
              strcpy(in_stack[t], "123456");
              printf("in_stack[t] = %s\n",in_stack[t]);
              printf("Here #1\n");
              strcat(in_stack[t], b);

              printf("Here #2\n");
              t = 1;
              strcat(in_stack[t], "zyxwtu");
              
              printf("Here #3\n");
         /*     strcat(in_stack[2], b); */
            
              printf("Here #4\n"); 
         /*     strcat(in_stack[3], "yefrtyu"); */
             

              x = 5;
		for(I=0; I < x; I++)
			{
				printf("in_stack = %s\n", in_stack[I]);
			}
		
              printf("HERE #5\n");

              t = 0;
              strcpy(gw_variable[t].gv_name, "123456");
              printf("gv_name #a = %s\n",gw_variable[t].gv_name);
              gv_ct = 1;
              strcat(gw_variable[gv_ct].gv_name, b);
              printf("gv_name #b = %s\n",gw_variable[gv_ct].gv_name);

              x = 5;
              for(I=0; I < x; I++)
              {
                printf("gv_name = %s\n",gw_variable[I].gv_name);
              }


	}
  
