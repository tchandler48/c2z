  
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
      char d[20];
      char e[20];
      char f[20];
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

              strcpy(b, "abcdef");
              printf("b = %s\n",b);

              strcat(a,b);
              printf("a = %s\n",a);

              t = 0;
              printf("Here #1\n");
              strcpy(in_stack[t], "123456");
              printf("in_stack[t] 1 = %s\n",in_stack[t]);
              strcat(in_stack[t], b);
              printf("in_stack[t] 2 = %s\n",in_stack[t]);

              printf("Here #2\n");
              t = 1;
              strcpy(c, "123456");
              printf("c 3 = %s\n",c);
              strcpy(in_stack[t], c);
              printf("in_stack[t] 4 = %s\n",in_stack[t]);
              strcpy(d,"zyxutv");
              printf("d 5 = %s\n",d);
              strcat(in_stack[t], d);
              printf("in_stack[t] 6 = %s\n",in_stack[t]);

              printf("Here #3\n");
              strcpy(in_stack[2], "Uncle Sam");
              printf("in_stack[2] 7 = %s\n",in_stack[2]);
              strcat(in_stack[2], b);
              printf("in_stack[2] 8 = %s\n",in_stack[2]);

              printf("Here #4\n");
              strcpy(e, "sam c");
              printf("e 9 = %s\n",e);
              strcpy(in_stack[3],e);
              printf("in_stack[3] 9 = %s\n",in_stack[3]);
              strcpy(f, "76ab54");
              printf("f 10 = %s\n",f);
		strcat(in_stack[3], "76ab54");
              printf("in_stack[3] 11 = %s\n",in_stack[3]);

              printf("Here #5\n");
              x = 5;
		for(I=0; I < x; I++)
		{
		  printf("in_stack = %s\n", in_stack[I]);
		}

              printf("Here #6\n");
              gv_ct = 1;
              strcpy(gw_variable[gv_ct].gv_name, "123456");
              printf("gv_name #a = %s\n",gw_variable[gv_ct].gv_name);
              printf("b       #b = %s\n",b);
              strcat(gw_variable[gv_ct].gv_name, b);
              printf("gv_name #c = %s\n",gw_variable[gv_ct].gv_name);

              printf("Here #7\n");
              gv_ct = 2;
              strcpy(gw_variable[gv_ct].gv_name, b);
              printf("b       #d = %s\n",b);
              printf("gv_name #e = %s\n",gw_variable[gv_ct].gv_name);
              strcat(gw_variable[gv_ct].gv_name, "123456");
              printf("gv_name #f = %s\n",gw_variable[gv_ct].gv_name);


              printf("Here #8\n");
              x = 5;
              for(I=0; I < x; I++)
              {
                printf("gv_name = %s\n",gw_variable[I].gv_name);
              }
     }
		
       
  
