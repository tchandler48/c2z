  
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
              printf("Testing ctest8\n");
              
              strcpy(varname, "abcdef");

              gv_ct = 1;
              strcpy(gw_variable[gv_ct].gv_name, varname);
              strcpy(gw_variable[3].gv_name, varname);

              gv_ct = 2;
              strcpy(gw_variable[gv_ct].gv_name, "123456");
              strcpy(gw_variable[4].gv_name, "123456");

              x = 4;
              strcpy(in_stack[x], gw_variable[gv_ct].gv_name);

              gv_ct = 0;
              strcpy(gw_variable[gv_ct].gv_name, in_stack[x]);

              x = 5;
              for(I=0; I < x; I++)
              {
                printf("gv_name = %s\n",gw_variable[I].gv_name);
              }


	}
  
