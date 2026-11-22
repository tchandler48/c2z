 
#define MAX_VARS     12
#define VAR_NAME     16
#define BUFSIZE      70
	
	int t;
	int x;
	int y;
	int z;
	int I;
       int imax_vars=0;
      char ch;
      char varname[VAR_NAME];
       int ndx;
       int ivalue;
      char cvalue[7];
      char in_stack[MAX_VARS][VAR_NAME];
       int iv_stack[MAX_VARS];
      char a[20];
      char b[20];
      char c[20];
      char p_string[75];
       int gv_ct;
       int xyz = 70;
       int age = 0;


struct variables 						
	{
		 int gv_rct;
              char ch;
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
		printf("Hello Z390 World ctest8\n");

              if(ch == ':')
              {
                printf("HERE #1 ch == :\n");
              }

		if(ch != ':')
              {
                printf("HERE #2 ch != :\n");
              }

              gv_ct = 2;
              if(gv_ct < 3)
              {
                printf("Here #3 gv_ct < 3\n");
              }

              gv_ct = 7;
              if(gv_ct < 3)
              {
                printf("Here #4 gv_ct < 7\n");
              }

              gv_ct = 2;
              if(gv_ct > 3)
              { 
                printf("Here #5 gv_ct > 3\n");
              }

              gv_ct = 7;
              if(gv_ct > 3)
              {
                printf("Here #6 gv_ct > 7\n");
              }

              strcpy(ch, "#");
              if((ch == '+') || (ch == '-'))
              {
                printf("Here #7 ch = %s\n",ch);
              }
              
              printf("Enter your name = \n");
              scanf(%s,a);             

              strcpy(b, "ghijklmno");
              printf("b = %s\n",b);

              printf("A = %s\n",a);

		printf("Enter 2nd in = \n");
              fgets(p_string, xyz, stdin);
              printf("p_string = %s\n",p_string);

              printf("Enter c = \n");
		gets(c);
 		printf("c = %s\n",c);

              printf("this is puts cmd\n");
              puts(c);

              printf("Enter your age\n");
              scanf(%d,age);
              printf("your age is = %d\n",age);

	}
  
