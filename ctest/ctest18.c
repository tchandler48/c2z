 
#define MAX_VARS     12
#define VAR_NAM      16
#define VAR_NAME     16
 	
	int t;
	int x;
	int y;
	int z;
	int I;
       int M;
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

  int spreadsheet[99][26] = 0;

	
int main(int argc, char *argv[])
	{
		printf("Hello Z390 World ctest18\n");
		
              a = 123;
              printf("#1 a = %d\n",a);
              a++;
              printf("#2 a = %d\n",a);

              iv_stack[2] = 987;
              printf("#1 iv_stack = %d\n",iv_stack[2]);
              iv_stack[2]++;
              printf("#2 iv_stack = %d\n",iv_stack[2]);

              z = 2;
              iv_stack[z] = 555;
              printf("#3 iv_stack = %d\n",iv_stack[z]);
              iv_stack[z]++;
              printf("#4 iv_stack = %d\n",iv_stack[z]);

              z = 5;
              iv_stack[z] = 444;
              printf("#5 iv_stack = %d\n",iv_stack[z]);
              iv_stack[z]--;
              printf("#6 iv_stack = %d\n",iv_stack[z]);

              spreadsheet[3][8] = 768;
              printf("#a spreadsheet = %d\n",spreadsheet[3][8]);
              spreadsheet[3][8]++;       
		printf("#b spreadsheet = %d\n",spreadsheet[3][8]);

              x = 2;
              y = 10;
              spreadsheet[x][y] = 432;
              printf("#c spreadsheet = %d\n",spreadsheet[x][y]);
              spreadsheet[x][y]++;       
		printf("#d spreadsheet = %d\n",spreadsheet[x][y]);

              x = 1;
              y = 5;
              spreadsheet[x][y] = 209;
              printf("#e spreadsheet = %d\n",spreadsheet[x][y]);
              spreadsheet[x][y]--;       
		printf("#f spreadsheet = %d\n",spreadsheet[x][y]);

              spreadsheet[8][8] = 898;
              printf("#g spreadsheet = %d\n",spreadsheet[8][8]);
              spreadsheet[8][8]--;       
		printf("#h spreadsheet = %d\n",spreadsheet[8][8]);

              strcpy(gw_variable[0].gv_name, "tomc");

              printf("gv_name #0 = %s\n",gw_variable[0].gv_name);

              strcpy(gw_variable[1].gv_name, "stephanie");
              strcpy(gw_variable[2].gv_name, "joe");

              x = 5;
              for(M = 0; M < x; M++)
              {
                printf("gv_name = %s\n",gw_variable[M].gv_name);
              }

              x = 5;
		for(I=0; I < x; I++)
		{
		   printf("I = %d\n",I);
		}
     
              gw_variable[4].gv_lgth = 395;
              printf("gv_lgth = %d\n",gw_variable[4].gv_lgth);

              x = 0;
              strcpy(gw_variable[x].gv_name, "tomc");

              printf("gv_name #1 = %s\n",gw_variable[x].gv_name);


	}
  
