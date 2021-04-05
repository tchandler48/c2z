/* ****************************************************************************
*  c2z.c Parser                                                               *
*  Copyright TCCS (c) 2015 - 2021                                             *
* *************************************************************************** */

/* ****************************************************************************
*  GENERAL NOTES	 								 *
*											 *
*  Dsect Arrarys MUST have the gw_variable[x].gv_flag to 1 so			 *
*  	Dsect address reset will take place.					 *
*											 *
* *************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
 
#define IOARRAY	99
#define PATH	      129
#define BUFSIZE     248
#define VAR_LGTH     32

     char *p; 
     char *p1;
     char *p2;
     char *p3;
     char *p4;
     char *p5;
     char *p6;
     char *p7;
     char *p8;
     char *p10;

     FILE *pgm;
     FILE *c_src;
     FILE *cc370;
     FILE *c_tmp;
     FILE *c_h;    
     char s_holder[BUFSIZE];    
     char p_string[BUFSIZE];    
     char a_string[BUFSIZE];    
     char o_string[BUFSIZE];    
     char wk_string[BUFSIZE];   
     char x_string[BUFSIZE];
     char save_case_break[12];  
     char ch2;            
     char trace_1[50];          
     char trace_2[2];           
     char print_array_name[VAR_LGTH];     
     char print_array_table[VAR_LGTH];    
     char while_array_name[VAR_LGTH];     
     char while_array_table[VAR_LGTH];    
     char sv_prt_string[80];     
     char pgm_name[8];
     char ret_fn[VAR_LGTH];
     char temp_fld[6];

     char strtmp[128];
     char c_output_file[24];
     char c_wkname[24];
     char start_while[12];
     char sv_func[VAR_LGTH];
     char sv_print_lit[VAR_LGTH];
     char null_field[2];
     char wk_fdwk[24];;
     char sub_name[24];
     char wk_strg[24];
     char wk_remark[22];
     char sv_if_branch[24];
     char err_msg[242];
     char while_tag[8];	
     char sw_field[12];
     char sw_tag[12];
     char sv_for_return[8];
     char sv_for_incr[8];
     char sv_while[VAR_LGTH];
     char from_sv[24];
	
      int trace_flag = 0;
      int punch_code = 0;
      int gv_ct = 0;
      int lv_ct = 0;
      int f_ct = 0;
      int fn_ct = 0;
      int debug = 1;
      int global_st = 0;
      int z390 = 0;
      int rct = 0;
      int convert = 0;
      int convert_ignore = 0;
      int if_convert = 0;
      int return_on = 0;
      int return_ct = 0;
      int lit_ct = 0;
      int char_ct = 0;
      int func_x1 = 0;
      int func_x2 = 0;
      int m_struc_ct = 0;
      int stru_ct = 0;

      int var_use[24];

      int work_use_ct[82];

      int tot_localtime = 0;
      int tot_int = 0;
      int tot_char = 0;
      int tot_goto = 0;

      int set_mn = 0;
      int tot_for = 0;
      int tot_while = 0;
      int tot_strchr = 0;
      int tot_strcmp = 0;
      int tot_time = 0;
      int tot_fputs = 0;
      int tot_divide = 0;
      int tot_wto = 0;
      int tot_strncpy = 0;
      int tot_memcpy = 0;
      int tot_double = 0;
      int tot_memmove = 0;
      int tot_case = 0;
      int tot_switch = 0;
      int array_rows = 17;
      int inside_if1 = 0;
      int inside_if2 = 0;
      int inside_if3 = 0;
      int inside_if4 = 0;
      int inside_if5 = 0;
      int inside_if6 = 0;
      int inside_if7 = 0;
      int inside_if8 = 0;
      int inside_if9 = 0;   
      int inside_if10 = 0;
      int if_start1 = 0;
      int if_start2 = 0;
      int if_start3 = 0;
      int if_start4 = 0;
      int if_start5 = 0;
      int if_start6 = 0;
      int if_start7 = 0;
      int if_start8 = 0;
      int if_start9 = 0;
      int if_start10 = 0;
      int if_else_flag1 = 0;
      int if_else_flag2 = 0;
      int if_else_flag3 = 0;
      int if_else_flag4 = 0;
      int if_else_flag5 = 0;
      int if_else_flag6 = 0;
      int if_else_flag7 = 0;
      int if_else_flag8 = 0;
      int if_else_flag9 = 0;
      int if_else_flag10 = 0;
      int if_level = 0;

      int inside_wh1 = 0;
      int inside_wh2 = 0;
      int inside_wh3 = 0;
      int inside_wh4 = 0;
      int inside_wh5 = 0;
      int inside_wh6 = 0;
      int inside_wh7 = 0;
      int inside_wh8 = 0;
      int inside_wh9 = 0;
      int inside_wh10 = 0;
      int while_start1 = 0;
      int while_start2 = 0;
      int while_start3 = 0;
      int while_start4 = 0;
      int while_start5 = 0;
      int while_start6 = 0;
      int while_start7 = 0;
      int while_start8 = 0;
      int while_start9 = 0;
      int while_start10 = 0;

     char output_file[24];
	
      int array_clear = 0;
      int case_parm_ct = 0;
      int v_const = 0;
      int fld_ct = 0;
      int found_space = 0;
      int found_space2 = 0;
      int skip = 0;
      int inside_mn = 0;
      int parm_ct = 0;
      int end_asm = 0;
/* stop here cr */
					
      int bracket_ct = 0;					
      int while_parser_code = 0;				
      int fns_ct = 0;					
      int while_convert = 0;				
      int prt_array = 0;				
      int while_array = 0;				

      int if_parm1 = 0;
      int if_parm2 = 0;
      int if_parm3 = 0;
      int if_parm4 = 0;
      int if_parm5 = 0;
      int if_parm6 = 0;
      int if_parm7 = 0;
      int if_parm8 = 0;
      int if_parm9 = 0;
      int if_parm10 = 0;
      int wif_ct = 0;
	 
      int while_level = 0;
      int wh_ct = 0;
      int while_parm1 = 0;
      int while_parm2 = 0;
      int while_parm3 = 0;
      int while_parm4 = 0;
      int while_parm5 = 0;
      int while_parm6 = 0;
      int while_parm7 = 0;
      int while_parm8 = 0;
      int while_parm9 = 0;
      int while_parm10 = 0;
	 
      int tot_sizeof = 0;
      int char_malloc = 0;   
      int tot_malloc = 0;				

      int left_parm = 0;
      int right_parm = 0;
      int op_code = 0;
      int equal_found = 0;

      int fclose_ct = 0;
      int buf_ct = 0;
      int function_ct = 0;;
      int if_case = 0;	
      int inside_fn = 0;
      int if_ct = 0;
      int c_name = 0;
      int if_opr = 0;
      int if_active = 0;
      int else_active = 0;
      int if_else_ct = 0;
      int else_flag = 0;
      int void_ct = 0;
      int math_case = 0;
      int comma_found = 0;
      int inside_void = 0;
      int fprintf_lit = 0;
      int math_convert = 0;
      int printf_convert = 0;
      int atoi_pass = 0; 
      int branch_done = 0;
      int sv_if_else_rec = 0;
      int sv_else_ct = 0;
      int end_strg = 0;
      int ab_code = 0;
      int inside_while = 0;
      int while_opr = 0;
      int while_parm = 0;
	
      int inside_for = 0;
      int for_opr = 0;
      int for_parm = 0;
      int console_flag = 0;
      int fprintf_flag = 0;
      int non_process = 0;
      int open_ct = 0;
      int end_input = 0;
      int use_atoi = 0;
      int use_mult = 0;
      int localtime_usect = 0;
      int loop_strcmp = 0;
      int i_ct = 0;;
      int continuation_comment = 0;
      int use_strchr = 0;
      int skip_read = 0;

struct defines
{
      int d_rct;
     char d_name[VAR_LGTH];
     char d_value[VAR_LGTH];
};
struct defines     *w_define;

struct variables
{
      int gv_rct;
     char gv_name[VAR_LGTH];
     char gv_cname[9];
     char gv_type[2];
      int gv_lgth;
      int gv_current_lgth;
     char gv_value[VAR_LGTH];
      int gv_init;
     char gv_literal[BUFSIZE];
      int gv_use_ct;
     char gv_dsect[VAR_LGTH];
      int gv_row;
      int gv_column;
     char gv_label[VAR_LGTH];
     char gv_table[VAR_LGTH];
     char gv_aname[VAR_LGTH];
     char gv_sv_reg[VAR_LGTH];
     char gv_wk_reg[VAR_LGTH];
     char gv_wk_strg[VAR_LGTH];
      int gv_flag;
      int gv_dec;
      int gv_id;
};
struct variables     *gw_variable;


struct var
{
      int lv_rct;
     char lv_name[VAR_LGTH];
     char lv_cname[9];
     char lv_func[VAR_LGTH];
     char lv_type[2];
      int lv_lgth;
      int lv_current_lgth;
     char lv_value[VAR_LGTH];
      int lv_init;
     char lv_literal[BUFSIZE];
      int lv_use_ct;
      int lv_dec;
      int lv_id;
	};
struct var     *lw_variable;   		


struct files
{
      int f_rct;
     char f_name[VAR_LGTH];
     char f_cname[VAR_LGTH];
     char f_type[2];
      int f_buf_ct;
     char f_perm[2];
     char f_rec_lgth[5];
     char f_label[32];
     char f_eof[VAR_LGTH];
};
struct files     *w_file;  


struct functions 					
	{      
		 int fn_rct;
		char fn_name[VAR_LGTH];
		char fn_cname[8];
		char fn_func[VAR_LGTH];
		 int fn_start;
		 int fn_return;
		char fn_sv_reg_1[8];
		char fn_sv_reg_2[8];
		char fn_sv_reg_3[8];
		char fn_loop[8];
		char fn_fd1[VAR_LGTH];
		char fn_fd2[VAR_LGTH];
		char fn_fd3[VAR_LGTH];
		char fn_fd4[VAR_LGTH];
		char fn_fd5[VAR_LGTH];
		char fn_fd6[VAR_LGTH];
		char fn_fd7[VAR_LGTH];
		char fn_fd8[VAR_LGTH];
		char fn_fd9[VAR_LGTH];
		 int fn_level;
		 int fn_eof;
		char fn_ret_var[VAR_LGTH];
		 int fn_pass_1;
		 int fn_pass_2;
		 int fn_pass_3;
		 int fn_pass_4;
		 int fn_pass_5;
		 int fn_pass_6;
		 int fn_pass_7;
		 int fn_pass_8;
		 int fn_pass_9;
		char fn_loop_use[10];
	};
struct functions         *w_function;                  


struct constant						
	{
		int const_rct;
	      char const_current[8];
	      char const_use[8];
	};
struct constant	    *w_constant;			

struct include						
	{
		int include_rct;
	      char include_name[VAR_LGTH];
	};
struct include	    *w_include;				


struct if_table						
	{
		int wif_rct;
	       int wif_eof1;
	       int wif_else;
	 	int wif_eof2;
		int wif_level;
	       char wif_p_string[80];
	};
struct if_table	    *w_if_table;			
 

struct while_table						
	{
		int wh_rct;
		int wh_level;
	       int wh_eof1;
	      char wh_p_string[80];
	};
struct while_table	    *w_while_table;			


struct fclose_table						
	{
		int cl_rct;
		int cl_buf_ct;
	};
struct fclose_table	    *w_fclose_table;			

struct func_start						
	{
		int fns_rct;
	      char fns_name[VAR_LGTH];
	};
struct func_start	    *w_func_start;			


struct literal						
	{
		int lit_rct;
	       int lit_use_rct;
             char lit_name[VAR_LGTH];
	      char lit_cname[VAR_LGTH];
	      char lit_value[VAR_LGTH];
	      char lit_use_cname[VAR_LGTH];
	       int lit_dec;
		int lit_uct;
	       int lit_type;
	};
struct literal	    *w_literal;			

struct charlit						
	{
		int clit_rct;
	      char clit_cname[VAR_LGTH];
	      char clit_value[VAR_LGTH];
		int clit_lgth;
	       int clit_type;
		int clit_uct;
	};
struct charlit	    *w_charlit;	


struct m_struc                  
	{
		 int st_rct;
		char st_id[2];
		 int st_disp;
		char st_name[VAR_LGTH];
		char st_cname[VAR_LGTH];	
		char st_wname[VAR_LGTH];
		char st_cwname[VAR_LGTH];
		char st_func[VAR_LGTH];
		char st_type[2];
		char st_field_name[VAR_LGTH];
		char st_field_cname[VAR_LGTH];
		 int st_field_lgth;
		 int st_field_cur_lgth;
		char st_field_value[BUFSIZE];
	};
struct m_struc	    *w_struc;	

       /*  debug flags */
     int prt_ln = 1;


#include "prototyp.h"
#include "c2z_atoi.c"
#include "c2z_break.c"
#include "c2z_case.c"
#include "c2z_char.c"
#include "c2z_const.c"
#include "c2z_ctime.c"
#include "c2z_debug.c"
#include "c2z_decr.c"
#include "c2z_define.c"
#include "c2z_enum.c"
#include "c2z_eoj.c"
#include "c2z_exit.c"
#include "c2z_fclose.c"
#include "c2z_feof.c"
#include "c2z_fgets.c"
#include "c2z_file.c"
#include "c2z_float.c"
#include "c2z_fopen.c"
#include "c2z_for.c"
#include "c2z_fputs.c"
#include "c2z_free.c"
#include "c2z_function.c"
#include "c2z_goto.c"
#include "c2z_if.c"
#include "c2z_incr.c"
#include "c2z_int.c"
#include "c2z_isalnum.c"
#include "c2z_isalpha.c"
#include "c2z_isdigit.c"
#include "c2z_isspace.c"
#include "c2z_isupper.c"
#include "c2z_localtime.c"
#include "c2z_long.c"
#include "c2z_malloc.c"
#include "c2z_math.c"
#include "c2z_mem.c"
#include "c2z_misc.c"
#include "c2z_parameter.c"
#include "c2z_pass_2.c"
#include "c2z_print.c"
#include "c2z_realloc.c"
#include "c2z_return.c"
#include "c2z_scanf.c"
#include "c2z_sizeof.c"
#include "c2z_strcat.c"
#include "c2z_strchr.c"
#include "c2z_strcmp.c"
#include "c2z_strcpy.c"
#include "c2z_strlen.c"
#include "c2z_strncpy.c"
#include "c2z_strrchr.c"
#include "c2z_strrev.c"
#include "c2z_strset.c"
#include "c2z_strstr.c"
#include "c2z_struct.c"
#include "c2z_time.c"
#include "c2z_unsigned.c"
#include "c2z_utility.c"
#include "c2z_while.c"

int main(int argc, char *argv[])
{
    char ch;
 
    char filename[VAR_LGTH];
    char wk_file[VAR_LGTH];
    char asm_file[VAR_LGTH];
    char ar_field6[VAR_LGTH];
    char ar_field7[VAR_LGTH];
    char ar_field8[VAR_LGTH];
    char ar_field9[VAR_LGTH];
    char ar_field10[VAR_LGTH];
    char ar_field11[VAR_LGTH];
    char tfield1[VAR_LGTH];
    char tfield1a[VAR_LGTH];
    char tfield2[VAR_LGTH];
    char trcfile[VAR_LGTH];

    null_field[0] = '\0';

     int pi = 0;
     int pi2 = 0;
     int fd1_type = 0;
     int indx = 0;
     int mnflg = 0;
     int size;
     int underline = 0;
     int ret = 0;
     int strstart = 0;
     int strstop = 0;
     int strflag = 0;
     int I = 0;
     int s = 0;
     int v = 0;
     int x = 0;
     int x1 = 0;
     int x2 = 0;
     int x3 = 0;
     int x4 = 0;
     int x5 = 0;
     int x6 = 0;
     int x20 = 0;
     int x21 = 0;
     int x90 = 0;
     int x91 = 0;
     unsigned x10 = 0;
     int y0 = 0;
     int v1 = 0;
     int y1 = 0;
     int ret1 = 0;
				 
     trace_flag = 1;		
     punch_code = 1;		

     strcpy(wk_file, argv[1]);
     strcpy(pgm_name, wk_file);
			
     p = strstr(wk_file, "/");
     if(p)
     {
        pi = 0;
        ch = wk_file[pi];
        while(ch != '/')
        {
           pi++;
           ch = wk_file[pi];
        }
        pi2 = 0;
        s = strlen(wk_file);
        pi++;
        ch = wk_file[pi];
        while((ch != ' ') && (pi < s))
        {
           pgm_name[pi2] = ch;
           pi2++;
           pi++;
           ch = wk_file[pi];
        }
        pgm_name[pi2] = '\0';
			
        /* Convert lower case to upper case for the entire p_string */
        strcpy(p_string, pgm_name);
        pi = 0;
        s = strlen(p_string);
        for(; pi < s; pi++)
        {
           ch = p_string[pi];
           if((ch >= 'a') && (ch <= 'z'))
           {
              ch2 = ('A' + ch - 'a');
           }
           else
           {
              ch2 = ch;
           }
           a_string[pi] = ch2;
        }
        a_string[pi] = '\0';
        strcpy(pgm_name, a_string);
     }

     strcpy(filename, wk_file);
     p = strstr(wk_file, ".c");
     if(!p)
     {
        strcat(filename, ".c");
     }

     p = strstr(wk_file, ".c");
     if(p)
     {
        pi = 0;
        s = strlen(wk_file);
        while(ch != '.')
        {
           ch = wk_file[pi];
           asm_file[pi] = ch;
           pi++;
        }
        asm_file[pi] = '\0';
     }

     if(!p)
     {
        strcpy(asm_file, wk_file);
     }

     if(argc == 3)
     {
        ret = strcmp(argv[2], "z390");
        if(ret == 0)
        {
           z390 = 1;
        }
     }

     if(argc == 2)
     {
        z390 = 1;
     }

     if(z390 == 1)
     {
        strcat(asm_file, ".MLC");
     }

     printf("***********************************************\n");
     printf("*  c2z Starting Execution                     *\n");
     printf("*  Version 0.0.21 - 04/01/2021                *\n");
     printf("*  Copyright (C) TCCS 2015 - 2021             *\n");
     printf("*  c2z Z390 Pass 1 Started                    *\n");


/* Pass 1 - reformat C source code */

     pgm = fopen(filename, "rb");
     c_tmp = fopen("tmp.c", "wb");
		
     strcpy(trcfile, wk_file);
     strcat(trcfile, ".TRC");
     c_src = fopen(trcfile, "w");

     i_ct = 0;
     rct = 0;

     while(1)
     {
        fgets(p_string, BUFSIZE, pgm);
        rct++;
        if(feof(pgm))
        {
           break;
        }

        p1 = strstr (p_string, "\"");
        ret = strncmp("#include", p_string, 8);
        if((ret == 0) && (p1))
        {
           pi = 0;
           ch = p_string[pi];
           while(ch != '"')
           {
              pi++;
              ch = p_string[pi];
           }

           pi2 = 0;
           pi++;
           ch = p_string[pi];
           while(ch != '"')
           {
              tfield1[pi2] = ch;
              pi2++;
              pi++;
              ch = p_string[pi];
           }
           tfield1[pi2] = '\0';

           y0 = 0;
           p8 = strstr(tfield1,".h");
           if(p8)
           {
              y0 = 1;
              c_h = fopen(tfield1, "r");
              while (fgets(p_string, BUFSIZE, c_h) != NULL)
              {
                 scan_func_name_1();
              }
              fclose(c_h);
           }

           if(y0 == 0)
           {
              if(i_ct == 0)
              {
                 size = 1;
                 w_include = malloc(size * sizeof(struct include));
              }
              else
              {
                 size = i_ct + 1;
                 w_include = realloc(w_include, size * sizeof(struct include));
              }

              w_include[i_ct].include_rct = rct;
              strcpy(w_include[i_ct].include_name, tfield1);
              i_ct++;
           }
        }
        fputs(p_string, c_tmp);
     }

     fclose(pgm);

     if(i_ct > 0)
     {
        for(I=0; I < i_ct; I++)
        {
           strcpy(tfield1, w_include[I].include_name);
           pgm = fopen(tfield1, "r");
           while(1)
           {
              fgets(p_string, BUFSIZE, pgm);
              rct++;
              if(feof(pgm))
              {
                 break;
              }
              fputs(p_string, c_tmp);
           }
           fputs(p_string, c_tmp);
           fclose(pgm);
        }
     }
     fclose(c_tmp);

     pgm = fopen("tmp.c", "rb");
     c_tmp = fopen("srcformat.c", "wb");

     rct = 0;
     while (fgets(p_string, BUFSIZE, pgm) != NULL)
     {
        rct++;

        convert = 0;
        pi = 0;
        x2 = 0;
        p1 = strstr(p_string, "#include");
        if(!p1)
        {
           p = strstr(p_string, "/*");
           if(p)
           {
              p10 = strstr(p_string, "/*");
              x10 = p10 - p_string;
              if(x10 < 6)
              {
                 convert = 1;
                 x2 = 1;
              }
           }




                    if(convert == 0)
                    {
                       s = strlen(p_string);
                       for(I=0; I < s; I++)
                       {
                          ch = p_string[I];
                          if((ch == ' ') && (convert == 0))
                          {
                             a_string[pi] = ch;
                             pi++;
                             convert = 1;
                          }

                          if((ch == '#') && (convert == 0))
                          {
                             a_string[pi] = ch;
                             pi++;
                             convert = 1;
                             x2 = 1;
                          }

                          if((ch == '*') && (convert == 0))
                          {
                             a_string[pi] = ch;
                             pi++;
                             convert = 1;
                             x2 = 1;
                          }

                          if((ch == '_') && (convert == 0))
                          {
                             a_string[pi] = ch;
                             pi++;
                             convert = 1;
                             x2 = 1;
                          }

                          if((ch == '(') && (convert == 0))
                          {
                             a_string[pi] = ch;
                             pi++;
                             convert = 1;
                             x2 = 1;
                          }

                          if((ch == ')') && (convert == 0))
                          {
                             a_string[pi] = ch;
                             pi++;
                             convert = 1;
                             x2 = 1;
                          }

                          if((ch == '{') && (convert == 0))
                          {
                             a_string[pi] = ch;
                             pi++;
                             convert = 1;
                             x2 = 1;
                          }

                          if((ch == '}') && (convert == 0))
                          {
                             a_string[pi] = ch;
                             pi++;
                             convert = 1;
                             x2 = 1;
                          }

                          if((ch == '\t') && (convert == 0))
                          {
                             if((pi >= 48) && (convert == 0))
                             {
                                x1 = 54 - pi;
                                convert = 1;
                             }
                             if((pi >= 42) && (convert == 0))
                             {
                                x1 = 48 - pi;
                                convert = 1;
                             }
                             if((pi >= 36) && (convert == 0))
                             {
                                x1 = 42 - pi;
                                convert = 1;
                             }
                             if((pi >= 30) && (convert == 0))
                             {
                                x1 = 36 - pi;
                                convert = 1;
                             }
                             if((pi >= 24) && (convert == 0))
                             {
                                x1 = 30 - pi;
                                convert = 1;
                             }
                             if((pi >= 18) && (convert == 0))
                             {
                                x1 = 24 - pi;
                                convert = 1;
                             }
                             if((pi >= 12) && (convert == 0))
                             {
                                x1 = 18 - pi;
                                convert = 1;
                             }
                             if((pi >= 6) && (convert == 0))
                             {
                                x1 = 12 - pi;
                                convert = 1;
                             }
                             if((pi >= 0) && (convert == 0))
                             {
                                x1 = 6 - pi;
                                convert = 1;
                             }

                             for(x=0; x < x1; x++)
                             {
                                a_string[pi] = ' ';
                                pi++;
                                convert = 1;
                             }
                          }

                          if((isprint(ch)) && (convert == 0))
                          {
                             a_string[pi] = ch;
                             pi++;
                             convert = 1;
                             x2 = 1;
                          }

                          convert = 0;
                       }

                       if(x2 == 1)
                       {
                          a_string[pi] = '\n';
                          pi++;
                          a_string[pi] = '\0';
                          fputs(a_string, c_tmp);
                       }
                       else
                       {

                       }
                    }
                 }
              }

              fclose(pgm);
              fclose(c_tmp);
              rct = 0;

/* Pass 2 - scan parser  */
		
     printf("*  c2z Z390 Pass 2 Started                    *\n");
				
     pgm = fopen("srcformat.c", "r");

     rct = 0;
     strcpy(trace_2, "2");
     strcpy(trace_1, "c2z.c pass 2 start\n");
		
     while(1)
     {
        convert = 0;
        fprintf_flag = 0;

        if(skip_read == 0)
        {
           fgets(p_string, 255, pgm);
           rct++;
           if(prt_ln == 1)
           {
              printf("c2z_MAIN if = %d while = %d rct = %d p_string = %s",if_level,while_level,rct,p_string);
           }
        }

if(rct > 46)
{
  c2_debug();
  exit(0);
}


        if(feof(pgm))
        {
           break;
        }

        if(global_st == 0)
        {
           sv_func[0] = '\0';
        }

        convert = 0;
        skip_read = 0;

        ret = strncmp("#", p_string, 1);
        if(ret == 0)
        {
           goto skip_continue_1;
        }

        ret = strncmp("struct", p_string, 6);
        if(ret == 0)
        {
           goto skip_continue_1;
        }

skip_continue_1:

/* Scan for { } */

        x = 0;
        x1 = 0;
        s = strlen(p_string);

        for(I=0; I < s; I++)
        {
           ch = p_string[I];
           if(ch == '{')
              x++;
           if(ch == '}')
              x1++;
        }

        if((x > 0) || (x1 > 0))
           c2_param_ct();

/* Scan for MAIN in C program and set sv_func */

        if((convert == 0)  && (continuation_comment == 0))
        {
           mnflg = 0;

           if(mnflg != 1)
           {
              p = strstr (p_string,"main");
              if(p)
              {
                 if(trace_flag == 1)
                 {
                    strcpy(trace_1, "scan for MAIN ");
                    trace_rec_1();
                 }

                 inside_mn = 1;
                 strcpy(sv_func, "main");
                 global_st = 1;
                 mnflg = 1;
              }
           }
        }

/* Scan for STRSTR   c2_strstr_scan(); */

        if((convert == 0)  && (continuation_comment == 0)) 
	 {
 	    p = strstr (p_string,"strstr");		
  	    if(p)
  	    {
	       convert = 1;
            
           }
        }


/* Scan for ENUM   c2_enum_scan(); */

        if((convert == 0) && (continuation_comment == 0))
        {
           p = strstr (p_string, "enum");
           if(p)
           {
          
              convert = 1;
           }
        }


/* Scan for MALLOC  */

        if((convert == 0) && (continuation_comment == 0))
        {
           p = strstr (p_string, "malloc");
           p1 = strstr (p_string, "#include");

           if((p) && (!p1))
           {
              c2_scan_malloc();
              convert = 1;
           }
        }


/* Scan for REALLOC    */

        if((convert == 0) && (continuation_comment == 0))
        {
           p = strstr (p_string, "realloc");
           p1 = strstr(p_string, "#include");

           if((p) && (!p1))
           {
              c2_scan_realloc();
              convert = 1;
           }
        }


/* Scan for STRNCMP */

        if((convert == 0) && (continuation_comment == 0))
        {
           p = strstr(p_string, "strncmp");
           if(p)
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z.c pass 2 scan strncmp");
                 trace_rec_1();
              }
              convert = 1;
           }
        }


/* Scan for STRUCT   */

        if((convert == 0)  && (continuation_comment == 0))
        {
	    p = strstr(p_string, "struct");
	    p1 = strstr(p_string, "_struct");
	    if((p) && (!p1))
	    {
	       c2z_struct();
	       convert = 1; 
	    }
	 }


/* Scan for WHILE statement  */

        if((convert == 0)  && (continuation_comment == 0))
        {
           p = strstr(p_string,"while");
           p1 = strstr(p_string, ";");
           p2 = strstr(p_string, "if");

           if((p) && (!p1) && (!p2))
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z.c pass 2 scan while");
                 trace_rec_1();
              }

              while_convert = 0;
              while_level++;
              if((while_level == 1) && (while_convert == 0))
              {
                 inside_wh1 = 1;
                 while_start1 = rct;
                 while_convert = 1;
              }

              if((while_level == 2) && (while_convert == 0))
              {
                 inside_wh2 = 1;
                 while_start2 = rct;
                 while_convert = 1;
              }

              if((while_level == 3) && (while_convert == 0))
              {
                 inside_wh3 = 1;
                 while_start3 = rct;
                 while_convert = 1;
              }

              if((while_level == 4) && (while_convert == 0))
              {
                 inside_wh4 = 1;
                 while_start4 = rct;
                 while_convert = 1;
              }

              if((while_level == 5) && (while_convert == 0))
              {
                 inside_wh5 = 1;
                 while_start5 = rct;
                 while_convert = 1;
              }

              if((while_level == 6)  && (while_convert == 0))
              {
                 inside_wh6 = 1;
                 while_start6 = rct;
                 while_convert = 1;
              }

              if((while_level == 7)  && (while_convert == 0))
              {
                 inside_wh7 = 1;
                 while_start7 = rct;
                 while_convert = 1;
              }

              if((while_level == 8) && (while_convert == 0))
              {
                 inside_wh8 = 1;
                 while_start8 = rct;
                 while_convert = 1;
              }

              if((while_level == 9) && (while_convert == 0))
              {
                 inside_wh9 = 1;
                 while_start9 = rct;
                 while_convert = 1;
              }

              if((while_level == 10) && (while_convert == 0))
              {
                 inside_wh10 = 1;
                 while_start10 = rct;
                 while_convert = 1;
              }

              if(while_level > 10)
              {
                 printf("C2_while Complex error - while_level > 10\n");
                 c2_debug();
                 exit(1);
              }

              if(while_convert == 1)
              {
                 if(wh_ct == 0)
                 {
                    size = 1;
                    w_while_table = malloc(size * sizeof(struct while_table));
                 }
                 else
                 {
                    size = wh_ct + 1;
                    w_while_table = realloc(w_while_table, size * sizeof(struct while_table));
                 }
                 w_while_table[wh_ct].wh_rct = rct;
                 w_while_table[wh_ct].wh_level = while_level;
                 strcpy(w_while_table[wh_ct].wh_p_string,p_string);
                 wh_ct++;
              }

              c2_pass2_whl(); 
              convert = 1;
           }
        }


/* Scan for FUNCTION  */

        if((convert == 0) && (continuation_comment == 0))
        {
           p = strstr(p_string, "void");
           p1 = strstr(p_string, ";");
           p2 = strchr(p_string, '(');
           p3 = strchr(p_string, ')');
           p4 = strstr(p_string, "int");
           p5 = strstr(p_string, "print");
           p6 = strstr(p_string, "char");
           p7 = strstr(p_string, "void_");
           p8 = strstr(p_string, "_void");

           if((p) && (p1) && (!p6) && (!p7) && (!p8))    /* void a_bort(int, int); */
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z.c pass 2 scan_func_name_1 #1");
                 trace_rec_1();
                 scan_func_name_1();
                 convert = 1;
              }
           }

           if((p) && (p1) && (p6) && (!p7) && (!p8) && (convert == 0))    /* void line_ct(char *argv[1]); */
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z.c pass 2 scan_func_name_1 #2");
                 trace_rec_1();
                 scan_func_name_1();
                 convert = 1;
              }
           }

           p = strstr(p_string, "void");
           p1 = strstr(p_string, ";");
           p2 = strchr(p_string, '(');
           p3 = strchr(p_string, ')');
           p4 = strstr(p_string, "int");
           p5 = strstr(p_string, "print");
           p6 = strstr(p_string, "char");

           if((p4) && (p2) && (p3) && (p1) && (!p5) && (convert == 0))
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z.c pass 2 scan_func_name_1 #3");
                 trace_rec_1();
                 scan_func_name_1();
                 convert = 1;
              }
           }
        }

/* Scan test for FPRINTF */

        if((convert == 0) && (continuation_comment == 0))
        {
           p = strstr (p_string,"fprintf");
           p1 = strstr(p_string, "int");
           if((p) && (!p1))
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z.c pass 2 scan fprintf");
                 trace_rec_1();
              }
              s = strlen(p_string);
              pi = 0;
              pi2 = 0;
              strstart = 0;
              strstop = 0;
              strflag = 0;
              while(ch != '(')
              {
                 pi++;
                 ch = p_string[pi];
              }

              /* now find print file name */
              underline = 0;
              pi2 = 0;
              pi++;
              ch = p_string[pi];
              while(ch != ',')
              {
                 if(ch == '_')
                 {
                    underline = 1;
                 }
                 a_string[pi2] = ch;
                 pi2++;
                 pi++;
                 ch = p_string[pi];
              }
              a_string[pi2] = '\0';

              if((pi2 > 8) || (underline == 1))
              {
                 if(f_ct > 0)
                 {
                    for(I=0; I < f_ct; I++)
                    {
                       ret = strcmp(a_string, w_file[I].f_name);
                       if(ret == 0)
                       {
                          strcpy(a_string, w_file[I].f_cname);
                          strcpy(w_file[I].f_type, "P");
                       }
                    }
                 }
              }

              while(pi <= s)
              {
                 ch = p_string[pi];
                 if(ch == '\"')
                 {
                    if(strflag == 1)
                    {
                       strstop = pi;
                    }
                    if(strflag == 0)
                    {
                       strstart = pi;
                       strflag = 1;
                    }
                 }
                 pi++;
              }

              /* copy from strstart to strstop into storage */
              s = 0;
              x4 = 0;
              x2 = 0;
              if((strstart > 0) && (strstop > 0))
              {
                 strstart++;
                 for(indx = strstart; indx < strstop; indx++)
                 {
                    ch = p_string[indx];
                    /* *******************************************************************
                     *  Test of c format charater '\' if, found do not copy and then     *
                     *  skip the next character.  ex (print\n). Drop the \n as it is     *
                     *  c formating string.                                              *
                     * ***************************************************************** */
                     if(ch == '%')
                     {
                        indx++;
                        x2 = 1;
                     }

                     if((ch != '\\') && (x2 == 0))
                     {
                        strtmp[s] = ch;
                        s++;
                        x4++;
                     }
                     else
                     {
                        indx++;
                        indx++;
                     }
                     x2 = 0;
                  }
                  strtmp[s] = '\0';
               }

               /* ******************************************************************
                *  Optimize LXX table                                              *
                * **************************************************************** */
               x3 = 0;
               if(gv_ct != 0)
               {
                  for(I=0; I < gv_ct; I++)
                  {
                     x2 = 0;
                     ret = strcmp(gw_variable[I].gv_type, "L");
                     if(ret == 0)
                     {
                        strcpy(a_string, gw_variable[I].gv_literal);
                        x = strcmp(a_string, strtmp);
                        x3++;
                        if(x == 0)
                        {
                           strcpy(tfield1, gw_variable[I].gv_name);
                           if(v_const == 0)
                           {
                              size = 1;
                              w_constant = malloc(size * sizeof(struct constant));
                           }
                           else
                           {
                              size = v_const + 1;
                              w_constant = realloc(w_constant, size * sizeof(struct constant));
                           }
                           w_constant[v_const].const_rct = rct;
                           strcpy(wk_string, "L");
                           snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
                           strcat(wk_string, wk_strg);
                           strcpy(w_constant[v_const].const_current, wk_string);
                           strcpy(w_constant[v_const].const_use, tfield1);
                           v_const++;
                           x2 = 1;
                           break;
                        }
                     }
                  }

                  if(x2 != 1)
                  {
                     if(v_const == 0)
                     {
                        size = 1;
                        w_constant = malloc(size * sizeof(struct constant));
                     }
                     else
                     {
                        size = v_const + 1;
                        w_constant = realloc(w_constant, size * sizeof(struct constant));
                     }
                     w_constant[v_const].const_rct = rct;
                     strcpy(wk_string, "L");
                     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
                     strcat(wk_string, wk_strg);
                     strcpy(w_constant[v_const].const_current, wk_string);
                     strcpy(w_constant[v_const].const_use, wk_string);
                     v_const++;
                  }
               }

               /* ******************************************************************
                *  update the struct with literal                                  *
                * **************************************************************** */
               if(gv_ct == 0)
               {
                  size = 1;
                  gw_variable = malloc(size * sizeof(struct variables));
               }
               else
               {
                  size = gv_ct + 1;
                  gw_variable = realloc(gw_variable, size * sizeof(struct variables));
               }
               strcpy(wk_string, "L");
               snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
               strcat(wk_string, wk_strg);
               gw_variable[gv_ct].gv_rct = rct;
               strcpy(gw_variable[gv_ct].gv_name, wk_string);
               strcpy(gw_variable[gv_ct].gv_type, "L");
               gw_variable[gv_ct].gv_lgth = x4;
               strcpy(gw_variable[gv_ct].gv_literal, strtmp);
               gw_variable[gv_ct].gv_dec = 0;
               gv_ct++;
               fprintf_flag = 1;
               convert = 1;
           }
        }	


/* Scan test for PRINTF  */

        if((convert == 0) && (continuation_comment == 0))
        {
           x3 = 0;
           p = strstr (p_string,"printf");
           p1 = strstr(p_string, "int");
           if((p) && (p1))
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z.c scan printf");
                 trace_rec_1();
              }

              y0 = 0;
              y0 = strlen(p_string);
              pi = 0;
              strstart = 0;
              strstop = 0;
              strflag = 0;
              while(pi <= y0)
              {
                 ch = p_string[pi];
                 if(ch == '\"')
                 {
                    if(strflag == 1)
                    {
                       strstop = pi;
                    }

                    if(strflag == 0)
                    {
                       strstart = pi;
                       strflag = 1;
                    }
                 }
                 pi++;
           }

           /* ***************************************************************
            *  copy from strstart to strstop into storage                   *
            * ************************************************************* */

           y0 = 0;
           x4 = 0;
           if((strstart > 0) && (strstop > 0))
           {
              strstart++;
              for(indx = strstart; indx < strstop; indx++)
              {
                 ch = p_string[indx];
                 if((ch == '\\') || (ch == '%'))
                 {
                    indx++;
                    break;
                 }
                 else
                 {
                    strtmp[y0] = ch;
                    y0++;
                    x4++;
                 }
              } 
              strtmp[y0] = '\0';
           }

           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c printf-strtmp");
              trace_rec_1();
           }

           y0 = 0;

           /* ******************************************************************
            *  Optimize LXX table                                              *
            * **************************************************************** */

           x3 = 0;
           x1 = 0;
           x = 0;

           if(gv_ct > 0)
           {
              for(I=0; I < gv_ct; I++)
              {
                 x2 = 0;
                 ret = strcmp(gw_variable[I].gv_type, "L");
                 if(ret == 0)
                 {
                    strcpy(a_string, gw_variable[I].gv_literal);
                    x = strcmp(a_string, strtmp);
                    x3++;
                    if(x == 0)
                    {
                       x1 = 1;
                       strcpy(tfield1, gw_variable[I].gv_name);
                       if(v_const == 0)
                       {
                          size = 1;
                          w_constant = malloc(size * sizeof(struct constant));
                       }
                       else
                       {
                          size = v_const + 1;
                          w_constant = realloc(w_constant, size * sizeof(struct constant));
                       }
                       w_constant[v_const].const_rct = rct;
                       strcpy(wk_string, "L");
                       snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
                       strcat(wk_string, wk_strg);
                       strcpy(w_constant[v_const].const_current, wk_string);
                       strcpy(w_constant[v_const].const_use, tfield1);
                       v_const++;
                       x2 = 1;
                       break;
                    }
                 }
              }

              if(x1 == 0)
              {
                 if(v_const == 0)
                 {
                    size = 1;
                    w_constant = malloc(size * sizeof(struct constant));
                 }
                 else
                 {
                    size = v_const + 1;
                    w_constant = realloc(w_constant, size * sizeof(struct constant));
                 }
                 w_constant[v_const].const_rct = rct;
                 strcpy(wk_file, "L");
                 snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
                 strcat(wk_file, wk_strg);
                 strcpy(w_constant[v_const].const_current, wk_file);
                 strcpy(w_constant[v_const].const_use, wk_file);
                 v_const++;
              }
           }

           if(gv_ct == 0)
           {
              if(v_const == 0)
              {
                 size = 1;
                 w_constant = malloc(size * sizeof(struct constant));
              }
              else
              {
                 size = v_const + 1;
                 w_constant = realloc(w_constant, size * sizeof(struct constant));
              }
              w_constant[v_const].const_rct = rct;
              strcpy(wk_file, "L");
              snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
              strcat(wk_file, wk_strg);
              strcpy(w_constant[v_const].const_current, wk_file);
              strcpy(w_constant[v_const].const_use, wk_file);
              v_const++;

              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z.c pass2 scan printf-strtmp 1st");
                 trace_rec_1();
              }
           }

           /* ********************************************************
            *  update the struct with literal                        *
            * ****************************************************** */
           if(x2 != 1)
           {
              if(gv_ct == 0)
              {
                 size = 1;
                 gw_variable = malloc(size * sizeof(struct variables));
              }
              else
              {
                 size = gv_ct + 1;
                 gw_variable = realloc(gw_variable, size * sizeof(struct variables));
              }
              strcpy(wk_string, "L");
              snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
              strcat(wk_string, wk_strg);
              gw_variable[gv_ct].gv_rct = rct;
              strcpy(gw_variable[gv_ct].gv_name, wk_string);
              strcpy(gw_variable[gv_ct].gv_type, "L");
              gw_variable[gv_ct].gv_lgth = x4;
              strcpy(gw_variable[gv_ct].gv_literal, strtmp);
              gw_variable[gv_ct].gv_dec = 0;
              gw_variable[gv_ct].gv_id = 5;
              gv_ct++;
              strcpy(strtmp, null_field);
           }
           convert = 1;
        }
     }		


/* Scan for FREE   */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr(p_string,"free");
        if(p)
        {
           convert = 1;
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan free");
              trace_rec_1();
           }
        }
     }


/* Scan for #DEFINE   */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr (p_string,"#define");
        if(p)
        {
           c2_define();
           convert = 1;
        }
     }


/* Scan for prototypes   */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr(p_string, "void");
        p1 = strstr(p_string, ";");
        p2 = strstr(p_string, "int");
        p3 = strstr(p_string, "(");
        p4 = strstr(p_string, ")");
        p5 = strstr(p_string, "printf");
        p6 = strstr(p_string, "char");
        p7 = strstr(p_string, "()");

        if((p6) && (!p5) && (p7))
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass_2 char");
              trace_rec_1();
           }
           c2_str_6();
           convert = 1;
        }

        p = strstr(p_string, "void");
        p1 = strstr(p_string, ";");
        p2 = strstr(p_string, "int");
        p3 = strstr(p_string, "(");
        p4 = strstr(p_string, ")");
        p5 = strstr(p_string, "printf");
        p6 = strstr(p_string, "char");
        p7 = strstr(p_string, "()");

        if((p) && (!p1) && (!p5) && (p3) && (p4))
        {
           convert = 1;
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass_2 scan void");
              trace_rec_1();
           }
           c2_int_3();
        }

        p = strstr(p_string, "void");
        p1 = strstr(p_string, ";");
        p2 = strstr(p_string, "int");
        p3 = strstr(p_string, "(");
        p4 = strstr(p_string, ")");
        p5 = strstr(p_string, "printf");
        p6 = strstr(p_string, "char");
        p7 = strstr(p_string, "()");

        if((p2) && (p3) && (p4) && (!p1) && (!p5) && (convert == 0))
        {
           convert = 1;
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass2 scan int");
              trace_rec_1();
           }
           c2_int_3();
        }
     }

/* Scan for user VOID FUNCTION code   */
     if((convert == 0)  && (continuation_comment== 0))
     {
        int v_convert = 0;

        p = strstr(p_string, "/*");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "#define");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "#include");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "++");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "--");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "break");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "case");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "char");
        p1 = strstr(p_string, "_char");
        if((p) && (!p1))
        {
           v_convert = 1;
        }
        p = strstr(p_string, "const");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "default");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "double");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "else");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "enum");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "exit");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "fclose");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "fgets");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "float");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "fopen");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "for");
        if(p)
        {
           v_convert = 1;
        }
        p1 = strstr(p_string, "_if");
        p = strstr(p_string, "if");
        if((p) && (!p1))
        {
           v_convert = 1;
        }
        p = strstr(p_string, "goto");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "int");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "long");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "print");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "realloc");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "scanf");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "sizeof");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "strcat");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "strchr");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "strcmp");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "strcpy");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "strlen");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "strncpy");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "strncmp");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "strrchr");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "strrev");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "strset");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "strstr");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "struct");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "switch");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "return");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "unsigned");
        if(p)
        {
           v_convert = 1;
        }
        p = strstr(p_string, "while");
        if(p)
        {
           v_convert = 1;
        }
	 p = strstr(p_string, "FILE");
        if(p)
        {
           v_convert = 1;
        }
        if(v_convert == 0)
        {
           c2_scan_sub();
        }
     }


/* Scan for INT (NOT MAIN)   */
     if((convert == 0) && (continuation_comment == 0))
     {
        p = strstr(p_string, "int");
        p1 = strstr(p_string,"print");
        p2 = strstr(p_string, "main");
        p3 = strstr(p_string, "void");
        p4 = strstr(p_string, "char");
        p5 = strstr(p_string, ";");
        p6 = strstr(p_string, "strcpy");

        if((p) && (!p1) && (!p2))
        {
           c2_int();
           convert = 1;
           goto skip_remark;
        }

        if((p4) && (!p6) && (convert == 0))
        {
printf("c2z_main rct = %d p_string = %s",rct,p_string);
           c2_falph(); 
           convert = 1;
           goto skip_remark;
        }
     }


/* Scan for FOR  */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr(p_string,"for");
        p1 = strstr(p_string, "\"");
        if((p) && (!p1))
        {
           c2_pass2_sc1();
        }
     }

/* Scan for MALLOC  (skip)  */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr (p_string, "malloc");
        p1 = strstr(p_string, "#include");

        if((p) && (!p1))
        {
           convert = 1; 
        }
     }


/* Scan for FILE   */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr (p_string,"FILE");
        if(p)
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c scan FILE");
              trace_rec_1();
           }
           c2_file();
           convert = 1;
        }
     }


/* Scan for BREAK  */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr (p_string,"break");
        if(p)
        {
           convert = 1;
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan break");
              trace_rec_1();
           }
        }
     }


/* Scan for RETURN   */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr (p_string,"return");
        if(p)
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan return");
              trace_rec_1();
           }
           c2_ret_2();
           convert = 1;
        }
     }	


/* Scan for EXIT  */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr (p_string,"exit");
        if(p)
        {
           convert = 1;
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan exit");
              trace_rec_1();
           }
        }
     }


/* Scan for ++  */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr (p_string,"++;");
        if(p)
        {
           convert = 1;
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan ++");
              trace_rec_1();
           }
        }
     }


/* Scan for --  */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr (p_string,"--");
        if(p)
        {
           convert = 1;
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan --");
              trace_rec_1();
           }
        }
     }


/* Scan for STRCAT   */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr (p_string,"strcat");
        if(p)
        {
           convert = 1;
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan sc2");
              trace_rec_1();
           }
           c2_pass2_sc2();
        }
     }


/* Scan for FOPEN   */
     if((convert == 0)  &&  (continuation_comment == 0))
     {
        p = strstr(p_string,"fopen");
        if(p)
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan fopen");
              trace_rec_1();
           }
           c2_scan_sc3();
           convert = 1;
        }
     }


/* Scan for FCLOSE   */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr(p_string,"fclose");
        if(p)
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan fclose");
              trace_rec_1();
           }
           convert = 1;
        }
     }


/* Scan for FGETS  */

     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr(p_string,"fgets");
        if(p)
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan fgets");
              trace_rec_1();
           }
         /*  c2_scan_sc4(); */
           convert = 1;
        }
     }


/* Scan for FPUTS  */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr(p_string,"fputs");
        if(p)
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan fputs");
              trace_rec_1();
           }
           /* c2_scan_fputs(); */
           convert = 1;
        }
     }


/* Scan for INT MAIN   */
     if((convert == 0) && (continuation_comment == 0))
     {
        p = strstr(p_string, "int");
        p1 = strstr(p_string,"print");
        p2 = strstr(p_string, "main");
        p3 = strstr(p_string, "()");

        if((p) && (!p1) && (p2))
        {
           if(!p3)
           {
              c2_main();
           }
           convert = 1;
           global_st = 1;
        }
     }


/* Scan for DOUBLE  */
     if((convert == 0) && (continuation_comment == 0))
     {
        p1 = strstr(p_string,"print");
        p2 = strstr(p_string,"main");
        p = strstr(p_string,"double");

        if(global_st == 0)
        {
           if((p) && (!p1) && (!p2))
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z.c pass 2 scan float");
                 trace_rec_1();
              }
              convert = 1;
              /* c2_float(); */
           }
        }
     }

/* Scan for float  */
     if((convert == 0) && (continuation_comment == 0))
     {
        p = strstr(p_string,"float");
        if(p)
        {
           convert = 1;
           /* c2_float(); */
        }
     }


/* Scan for unsigned  */
     if((convert == 0) && (continuation_comment == 0))
     {
        p = strstr(p_string,"unsigned");
        if(p)
        {
           convert = 1;
           c2_unsigned();
        }
     }


/* Scan for CASE   */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr(p_string,"case");
        if(p)
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan case");
              trace_rec_1();
           }
           convert = 1;
           /* c2_pass2_case(); */
        }
    }


/* SCAN for IF   */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p1 = strstr(p_string, "_if");
        p = strstr(p_string,"if");		
  	 if((p) && (!p1)) 
  	 {
           if(trace_flag == 1)
	    {  
              sprintf(temp_fld, "%d",if_level);
	       strcpy(trace_1, "c2z.c pass 2 scan IF LVL = ");
              strcat(trace_1, temp_fld);
		trace_rec_1();
	    }

		if_level++;
		if(if_level == 1)
		{
  		   inside_if1 = 1;
		   if_start1 = rct;
		}
		if(if_level == 2)
		{
		   inside_if2 = 1;
		   if_start2 = rct;
		}
		if(if_level == 3)
		{
		   inside_if3 = 1;
		   if_start3 = rct;
		}
		if(if_level == 4)
		{
		   inside_if4 = 1;
		   if_start4 = rct;
		}
		if(if_level == 5)
		{
		   inside_if5 = 1;
		   if_start5 = rct;
		}
		if(if_level == 6)
		{
		   inside_if6 = 1;
		   if_start6 = rct;
		}
		if(if_level == 7)
		{
		   inside_if7 = 1;
		   if_start7 = rct;
		}
		if(if_level == 8)
		{
		   inside_if8 = 1;
		   if_start8 = rct;
		}
		if(if_level == 9)
		{
		   inside_if9 = 1;
		   if_start9 = rct;
		}
		if(if_level == 10)
		{
		   inside_if10 = 1;
		   if_start10 = rct;
		}
              if(if_level > 10)
		{
		   printf("c2_pass IF complex error \n");	
                 c2_debug();				
		   exit(1);
		}
		if(wif_ct == 0)
		{
  		   size = 1;
		   w_if_table = malloc(size * sizeof(struct if_table));
		}
		else
		{
		   size = wif_ct + 1;
		   w_if_table = realloc(w_if_table, size * sizeof(struct if_table));
		}
		w_if_table[wif_ct].wif_rct = rct;
		w_if_table[wif_ct].wif_level = if_level;
		strcpy(w_if_table[wif_ct].wif_p_string, p_string);
		wif_ct++;
		c2_pass2_if();

		convert = 1;
  	    }
	 }


/* Scan for STRCPY  */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr (p_string,"strcpy");
        if(p)
        {
           convert = 1;
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan strcpy");
              trace_rec_1();
           }
           c2_strcpy_pass2();
        }
     }


/* Scan for STRCMP   */
     if((convert == 0) && (continuation_comment == 0))
     {
        p = strstr (p_string,"strcmp");
        if(p)
        {
           p1 = strstr(p_string, "\"");
           if(p1)
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z.c pass 2 scan strcmp");
                 trace_rec_1();
              }
              pi = 0;
              ch = p_string[pi];
              while(ch != '"')
              {
                 pi++;
                 ch = p_string[pi];
              }
              x3 = 0;
              pi2 = 0;
              pi++;
              ch = p_string[pi];
              while(ch != '"')
              {
                 a_string[pi2] = ch;
                 pi2++;
                 x3++;
                 pi++;
                 ch = p_string[pi];
              }
              a_string[pi2] = '\0';

              /* ******************************************************************
               *  update the struct with literal                                  *
               * **************************************************************** */
              if(gv_ct == 0)
              {
                 size = 1;
                 gw_variable = malloc(size * sizeof(struct variables));
              }
              else
              {
                 size = gv_ct + 1;
                 gw_variable = realloc(gw_variable, size * sizeof(struct variables));
              }
              strcpy(wk_string, "L");
              snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
              strcat(wk_string, wk_strg);
              gw_variable[gv_ct].gv_rct = rct;
              strcpy(gw_variable[gv_ct].gv_name, wk_string);
              strcpy(gw_variable[gv_ct].gv_type, "L");
              gw_variable[gv_ct].gv_lgth = x3;
              strcpy(gw_variable[gv_ct].gv_literal, a_string);
              gw_variable[gv_ct].gv_dec = 0;
              gv_ct++;
              convert = 1;
           }
        }
     }


/* Scan for FEOF   */
     if((convert == 0)  && (continuation_comment == 0))
     {
        p = strstr(p_string,"feof");
        if(p)
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan feof");
              trace_rec_1();
           }
           c2_scan_feof();
           convert = 1;
        }
     }


/* Scan for STRLEN   */
     if((convert == 0) && (continuation_comment == 0))
     {
        p = strstr(p_string,"strlen");
        if(p)
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan strlen");
              trace_rec_1();
           }
           c2_strlen_pass2();
           convert = 1;
        }
     }


/* Scan for sizeof   */
     if((convert == 0) && (continuation_comment == 0))
     {
        p = strstr(p_string,"sizeof");
        if(p)
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan sizeof");
              trace_rec_1();
           }
           c2_pass2_sizeof();
           convert = 1;
        }
     }
 


/* Scan for GOTO   */

     if((convert == 0) && (continuation_comment == 0))
     {
        p = strstr(p_string, "goto");
        if(p)
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z.c pass 2 scan goto");
              trace_rec_1();
           }
           convert = 1;
        }
    }


/* Math literal  = MUST BE LAST CALL IN PARSER  */
    if((convert == 0) && (continuation_comment == 0))
    {
       p = strstr (p_string, "=");
       if(p)
       {
          c2_math_literal();
          c2_pass2_math();
          convert = 1;
       }
     }


/* End of while loop for PASS 2   */
skip_remark:
     convert = 0; 
     p_string[0] = '\0';
   }		

			
/* Test for balanced fopen & fclose   */
     if(open_ct != 0)
     {
        printf("Unbalanced fopen and fclose statements\n");
        printf("      Error at Line # - %d\n", rct);
        fclose(pgm);
        exit(0);
     }

     fclose(pgm);

     if(gv_ct == 0)
     {
        size = 1;
        gw_variable = malloc(size * sizeof(struct variables));
     }
     else
     {
        size = gv_ct + 1;
        gw_variable = realloc(gw_variable, size * sizeof(struct variables));
     }
     gw_variable[gv_ct].gv_rct = rct;
     strcpy(gw_variable[gv_ct].gv_cname, "NULL");
     strcpy(gw_variable[gv_ct].gv_name, "NULL");
     strcpy(gw_variable[gv_ct].gv_type, "I");
     gw_variable[gv_ct].gv_lgth = 0;
     gw_variable[gv_ct].gv_current_lgth = 0;
     strcpy(gw_variable[gv_ct].gv_value, "-1");
     gw_variable[gv_ct].gv_init = 0;
     strcpy(gw_variable[gv_ct].gv_literal,null_field);
     gw_variable[gv_ct].gv_use_ct = 0;
     gw_variable[gv_ct].gv_dec = 0;
     gw_variable[gv_ct].gv_id = 1;
     gv_ct++;

/* End of Pass 2 - scan parser  */

/* PASS 3 Code Generation - creating the xxxx.mlc file  */

     printf("*  c2z Z390 Pass 3 Started                    *\n");
     pgm = fopen("srcformat.c", "r");
     cc370 = fopen(asm_file, "w");

     rct = 0;
     var_use[1] = 0;
     continuation_comment = 0;
     end_input = 0;
     global_st = 0;
     mnflg = 0;
     set_mn = 0;
     inside_mn = 0;


/* Punch START   */
     strcpy(a_string, "*");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #1");
        trace_rec_3();
     }

     strcpy(a_string, "*  This program was generated by c2z parser.");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #2");
        trace_rec_3();
     }

     strcpy(a_string, "*  Generated code is for the z390 MLC.");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #3");
        trace_rec_3();
     }

     strcpy(a_string, "*  Copyright (c) TCCS 2015 - 2021");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #4");
        trace_rec_3();
     }

     strcpy(a_string, "*");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #6");
        trace_rec_3();
     }

     strcpy(a_string, "BNO       OPSYN  JNO");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #7");
        trace_rec_3();
     }

     strcpy(a_string, "BAL       OPSYN  JAS");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #8");
        trace_rec_3();
     }

     strcpy(a_string, "*");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #9");
        trace_rec_3();
     }

     strcpy(a_string, "          MACRO");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #10");
        trace_rec_3();
     }

     strcpy(a_string, "&N        SUBENTRY");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #11");
        trace_rec_3();
     }

     strcpy(a_string, "&N        CSECT");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #12");
        trace_rec_3();
     }

     strcpy(a_string, "          STM    14,12,12(13)");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #13");
        trace_rec_3();
     }

     strcpy(a_string, "          JAS    15,CONTINUE");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #14");
        trace_rec_3();
     }

     strcpy(a_string, "          DC     18F'0'");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #15");
        trace_rec_3();
     }

     strcpy(a_string, "          DC     CL8'&N'");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #16");
        trace_rec_3();
     }

     strcpy(a_string, "          DC     CL8'&SYSDATE'");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #17");
        trace_rec_3();
     }

     strcpy(a_string, "          DC     CL8'&SYSTIME'");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #18");
        trace_rec_3();
     }

     strcpy(a_string, "CONTINUE  DS     0H");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #19");
        trace_rec_3();
     }

     strcpy(a_string, "          ST     15,8(13)");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #20");
        trace_rec_3();
     }

     strcpy(a_string, "          ST     13,4(15)");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #21");
        trace_rec_3();
     }

     strcpy(a_string, "          LR     13,15");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #22");
        trace_rec_3();
     }

     strcpy(a_string, "          USING  &N+8,13");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #23");
        trace_rec_3();
     }

     strcpy(a_string, "          MEND");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #24");
        trace_rec_3();
     }

     strcpy(a_string, "*");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #25");
        trace_rec_3();
     }

     strcpy(a_string, "          MACRO");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #26");
        trace_rec_3();
     }

     strcpy(a_string, "          SUBEXIT");
     src_line();
     if(punch_code == 1)
     {
        strcpy(trace_1, "c2z.c pass 3 generated #27");
        trace_rec_3();
     }


						
						strcpy(a_string, "          LA     15,0");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #28");
								trace_rec_3();
							}

						strcpy(a_string, "          L      13,4(,13)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #29");
								trace_rec_3();
							}

						strcpy(a_string, "          L      14,12(,13)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #30");
								trace_rec_3();
							}

						strcpy(a_string, "          LM     2,12,28(13)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #31");
								trace_rec_3();
							}

						strcpy(a_string, "          BR     14");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #32");
								trace_rec_3();
							}

						strcpy(a_string, "          MEND");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #33");
								trace_rec_3();
							}

						strcpy(a_string, "*");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #34");
								trace_rec_3();
							}

						x3 = 0;
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(gw_variable[v].gv_name, "argc");
								if(ret == 0)
									x3 = 1;
							}
					
						if(x3 == 0)
							{
								if(gv_ct == 0)
									{
										size = 1;
										gw_variable = malloc(size * sizeof(struct variables));
									}
								else
									{
										size = gv_ct + 1;
										gw_variable = realloc(gw_variable, size * sizeof(struct variables));
									}

								gw_variable[gv_ct].gv_rct = rct;
								strcpy(gw_variable[gv_ct].gv_cname, "argc");	
      								strcpy(gw_variable[gv_ct].gv_name, "argc");  	             
								strcpy(gw_variable[gv_ct].gv_type, "I");
								gw_variable[gv_ct].gv_lgth = 0;
								strcpy(gw_variable[gv_ct].gv_value, null_field);
								gw_variable[gv_ct].gv_dec = 0;
								gw_variable[gv_ct].gv_id = 1;
								gv_ct++;
							}

						x3 = 0;
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(gw_variable[v].gv_name, "argv");
								if(ret == 0)
									x3 = 1;
							}
								
						tfield2[0] = '\0';
						if(x3 == 0)
							{
								if(gv_ct == 0)
									{
										size = 1;
										gw_variable = malloc(size * sizeof(struct variables));
									}
								else
									{
										size = gv_ct + 1;
										gw_variable = realloc(gw_variable, size * sizeof(struct variables));
									}

								gw_variable[gv_ct].gv_rct = rct;
								strcpy(gw_variable[gv_ct].gv_cname, "argv");	
      								strcpy(gw_variable[gv_ct].gv_name, "argv");  	             
								strcpy(gw_variable[gv_ct].gv_type, "C");
								gw_variable[gv_ct].gv_lgth = 32;
								strcpy(gw_variable[gv_ct].gv_value, "32");
								gw_variable[gv_ct].gv_dec = 0;
								gw_variable[gv_ct].gv_id = 3;
								gv_ct++;
							}
						
						strcpy(a_string, "*  This is a modified MVC2 macro.  Modified for baseless code");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #35");
								trace_rec_3();
							}
	
						strcpy(a_string, "*  Modified by TCCS 2016");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #36");
								trace_rec_3();
							}

						strcpy(a_string,"*  Performs a MVC operation, using Source Length NOT Target Length");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #37");
								trace_rec_3();
							}

						strcpy(a_string, "*");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #38");
								trace_rec_3();
							}

						strcpy(a_string, "          MACRO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #39");
								trace_rec_3();
							}

						strcpy(a_string, "&LAB      MVC2   &TARGET,&SOURCE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #40");
								trace_rec_3();
							}

						strcpy(a_string, "&LAB      LARL   R8,&SOURCE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #41");
								trace_rec_3();
							}

						strcpy(a_string, "          LARL   R9,&TARGET");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #42");
								trace_rec_3();
							}

						strcpy(a_string, "          MVC    0(L'&SOURCE,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #43");
								trace_rec_3();
							}

						strcpy(a_string, "          MEND");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #44");
								trace_rec_3();
							}

						strcpy(a_string, "*");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #45");
								trace_rec_3();
							}

						strcpy(a_string, "*  This is a modified MVC2 macro.  baseless code");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #46");
								trace_rec_3();
							}

						strcpy(a_string, "*  Modified by TCCS 2016");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #47");
								trace_rec_3();
							}
	
						strcpy(a_string,"*  Performs a MVC operation, using Source Length NOT Target Length");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #48");
								trace_rec_3();
							}

						strcpy(a_string, "*");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #49");
								trace_rec_3();
							}

						strcpy(a_string, "          MACRO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #50");
								trace_rec_3();
							}

						strcpy(a_string, "&LAB      MVC3   &SOURCE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #51");
								trace_rec_3();
							}

						strcpy(a_string, "&LAB      LARL   R8,&SOURCE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #52");
								trace_rec_3();
							}

						strcpy(a_string, "          MVC    0(L'&SOURCE,R6),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #53");
								trace_rec_3();
							}
		
						strcpy(a_string, "          MEND");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #54");
								trace_rec_3();
							}

						strcpy(a_string, "*");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 generated #55");
								trace_rec_3();
							}
	
						strcpy(a_string, pgm_name);
						s = strlen(pgm_name);
						check_length();
						strcat(a_string,"SUBENTRY");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #56");
								trace_rec_3();
							}

						strcpy(a_string, "         JLU   START");
						strcpy(wk_remark, " R5 parm lg */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #57");
								trace_rec_3();
							}

						strcpy(a_string,"*********************************************************");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #58");
								trace_rec_3();
							}

						strcpy(a_string,"*  open/close macro code goes here                      *");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #59");
								trace_rec_3();
							}

						strcpy(a_string,"*********************************************************");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #60");
								trace_rec_3();
							}
			
						if(z390 == 1)
							{
								for(I=0; I < f_ct; I++)
									{
										ret = strcmp(w_file[I].f_type, "P");
										if(ret == 0)
											{
												x4 = w_file[I].f_buf_ct;

												strcpy(a_string, "C370OPN");
												snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
												strcat(a_string, wk_strg);
												check_length();
												strcat(a_string, "DS    0H");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #1");
														trace_rec_3(); 
													}

												strcpy(a_string, "         OPEN  (");
												strcat(a_string, w_file[I].f_cname);
												x = strcmp(w_file[I].f_perm, "I");
												if(x == 0)
													{
														strcat(a_string, ",(INPUT))");
													}
												x = strcmp(w_file[I].f_perm, "O");
												if(x == 0)
													{
														strcat(a_string, ",(OUTPUT))");
													}

												strcpy(wk_remark, " open     */");
												write_remark();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #2");
														trace_rec_3(); 
													}

												strcpy(a_string, "         LARL  R9,C370PB");
												snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
												strcat(a_string, wk_strg);
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #3");
														trace_rec_3(); 
													}
 
												strcpy(a_string, "         LARL  R8,C370B1");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #4");
														trace_rec_3(); 
													}
												work_use_ct[52]++;
										
												strcpy(a_string, "         MVC   0(1,R9),0(R8)");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #5");
														trace_rec_3(); 
													}
			
												strcpy(a_string, "         MVC   1(131,R9),0(R9)");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #6");
														trace_rec_3(); 
													}

												strcpy(a_string, "         BR    R10");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #7");
														trace_rec_3(); 
													}

											}

										strcpy(tfield1, w_file[I].f_rec_lgth);

										ch = tfield1[0];
										if(isdigit(ch))
											fd1_type = 1;
										if(isalpha(ch))
											fd1_type = 2;

										if(fd1_type == 2)
											{
												if(gv_ct > 0)
													{
														for(x2 = 0; x2 < gv_ct; x2++)
															{
																ret = strcmp(tfield1, gw_variable[x2].gv_name);
																if(ret == 0)
																	{
																		strcpy(tfield1, gw_variable[x2].gv_value);
																	}
															}
													}
											}

										ret = strcmp(w_file[I].f_type, "D");
										if(ret == 0)
											{
												x4 = w_file[I].f_buf_ct;

												strcpy(a_string, "C370OPN");
												snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
												strcat(a_string, wk_strg);
												check_length();
												strcat(a_string, "DS    0H");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #8");
														trace_rec_3(); 
													}

												strcpy(a_string, "         OPEN  (");
												strcat(a_string, w_file[I].f_cname);
												x = strcmp(w_file[I].f_perm, "I");
												if(x == 0)
													{
														strcat(a_string, ",(INPUT))");
													}
												x = strcmp(w_file[I].f_perm, "O");
												if(x == 0)
													{
														strcat(a_string, ",(OUTPUT))");
													}

												strcpy(wk_remark, " open     */");
												write_remark();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #9");
														trace_rec_3(); 
													}

												strcpy(a_string, "         LARL  R9,C370PB");
												snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
												strcat(a_string, wk_strg);
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #10");
														trace_rec_3(); 
													}

												strcpy(a_string, "         LARL  R8,C370PB");
												snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
												strcat(a_string, wk_strg);
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #11");
														trace_rec_3(); 
													}

												x3 = atoi(tfield1);

												strcpy(a_string, "         XC    ");
												strcat(a_string, "0(");
												snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
												strcat(a_string, wk_strg);
												strcat(a_string, ",R9),0(R8)");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #11");
														trace_rec_3(); 
													}

												strcpy(a_string, "         BR    R10");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 fopen #12");
														trace_rec_3(); 
													}
											}
									}
							}  			

						
			
					
						strcpy(a_string, "*");
						src_line();

						y1 = 0;			
						if(f_ct > 0)
							{
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z.c fclose");
									}

								for(I=0; I < f_ct; I++)
									{

										strcpy(a_string,"C370EF");
										snprintf(wk_strg, sizeof(wk_strg), "%d",w_file[I].f_buf_ct);
										y1 = w_file[I].f_buf_ct; 
										strcat(a_string, wk_strg);
										check_length();
										strcat(a_string, "DS    0H");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z.c fclose #1");
												trace_rec_3();
											}

										x3 = w_file[I].f_buf_ct;

										strcpy(tfield1a, w_file[I].f_cname);
										strcpy(a_string, "         CLOSE ");
										strcat(a_string, tfield1a);
										strcpy(wk_remark, " fclose   */ ");
										write_remark();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z.c fclose #2");
												trace_rec_3();
											}
					
										for(y0 = 0; y0 < fclose_ct; y0++)
											{
												/* compare file_buf_ct vs fclose_table_buf_ct MUST MATCH */

												if(y1 == w_fclose_table[y0].cl_buf_ct)
													{
														/* match branch back to program */
														strcpy(a_string, "         JLU   L");
														snprintf(wk_strg, sizeof(wk_strg), "%d",w_fclose_table[y0].cl_rct);
														strcat(a_string, wk_strg);
														src_line();
														if(punch_code == 1)
															{
																strcpy(trace_1, "c2z.c fclose #11");
																trace_rec_3();
															}

														strcpy(a_string, "CL");
														snprintf(wk_strg, sizeof(wk_strg), "%d",y0);
														strcat(a_string, wk_strg);
														strcat(a_string, "0");
														check_length();
														strcat(a_string, "DS    0H");
														src_line();
														if(punch_code == 1)
															{
																strcpy(trace_1, "cz2.c fclose #12");
																trace_rec_3();
															}
													}
											}

										strcpy(a_string, "         JLU   C370EXIT");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z.c fclose #13");
												trace_rec_3();
											}
									}
							} 				

						strcpy(a_string, "*");
						src_line();
						
						strcpy(a_string, "C370END  DS    0H");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c Generated #35");
								trace_rec_3();
							}

						strcpy(a_string, "         SUBEXIT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c Generated #36");
								trace_rec_3();
							}
						
						strcpy(a_string, "******************************************************************");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c Generated #37");
								trace_rec_3();
							}

						strcpy(a_string, "*                                                                *");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c Generated #38");
								trace_rec_3();
							}

						strcpy(a_string, "* STATIC STORAGE AREA FOR CSECT - NO BASE REG REQUIRED.          *");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c Generated #39");
								trace_rec_3();
							}

						strcpy(a_string, "*                               - LARL ADDRESSING IS USED        *");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c Generated #40");
								trace_rec_3();
							}

						strcpy(a_string, "*                                                                *");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c Generated #41");
								trace_rec_3();
							}

						strcpy(a_string, "******************************************************************");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c Generated #42");
								trace_rec_3();
							}

						if(z390 == 1)
							{
								for(I=0; I < f_ct; I++)
									{
										strcpy(tfield1, w_file[I].f_cname);
										ret = strcmp(w_file[I].f_type, "P");
										if(ret == 0)
											{
												snprintf(wk_strg, sizeof(wk_strg), "%d", w_file[I].f_buf_ct);
												strcpy(a_string, "C370PB");
												strcat(a_string, wk_strg);
												check_length();
												strcat(a_string, "DC    CL132' '"); 
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #1");
														trace_rec_3();
													}

												strcpy(a_string, tfield1);
												check_length();
						strcat(a_string, "DCB   DSORG=PS,                                               x");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #2");
														trace_rec_3();
													}

												ret1 = strcmp("O",w_file[I].f_perm);
												if(ret1 != 0)
													{
														strcpy(a_string, "               EODAD=");
														strcat(a_string,"C370EF");
														snprintf(wk_strg, sizeof(wk_strg), "%d", w_file[I].f_buf_ct);
														strcat(a_string, wk_strg);
														strcat(a_string, ",                                          x");
														src_line();
														if(punch_code == 1)
															{
																strcpy(trace_1, "c2z.c buffer define #3");
																trace_rec_3();
															}
													}

					strcpy(a_string, "               RECFM=FT,                                               x");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #4");
														trace_rec_3();
													}

							strcpy(a_string, "               MACRF=PM,                                               x");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #5");
														trace_rec_3();
													}

							strcpy(a_string, "               SYNAD=0,                                                x");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #6");
														trace_rec_3();
													}

							strcpy(a_string, "               BLKSIZE=132,                                            x");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #7");
														trace_rec_3();
													}

							strcpy(a_string, "               LRECL=132,                                              x");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #8");
														trace_rec_3();
													}

												strcpy(a_string, "               RECORD=C370PB");
												snprintf(wk_strg, sizeof(wk_strg), "%d", w_file[I].f_buf_ct);
												strcat(a_string, wk_strg);
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #9");
														trace_rec_3();
													}

												strcpy(a_string, "*");
												src_line();
										
											}

										ret = strcmp(w_file[I].f_type, "D");
										if(ret == 0)
											{
												snprintf(wk_strg, sizeof(wk_strg), "%d", w_file[I].f_buf_ct);
												strcpy(a_string, "C370PB");
												strcat(a_string, wk_strg);
												check_length();
												strcat(a_string, "DC    CL"); 
												strcpy(tfield2, w_file[I].f_rec_lgth);
												ch = tfield2[0];

												if(isdigit(ch))
													{
														fd1_type = 1;
														x4 = atoi(w_file[I].f_rec_lgth);
													}

												if(isalpha(ch))
													fd1_type = 2;
											
												if(fd1_type == 2)		/* variable name get value from w_variable */
													{
														if(gv_ct > 0)
															{
																for(x2 = 0; x2 < gv_ct; x2++)
														 			{
																		ret = strcmp(tfield2, gw_variable[x2].gv_name);
																		if(ret == 0)
																			{
																				strcpy(wk_string, gw_variable[x2].gv_value);
																				x4 = atoi(gw_variable[x2].gv_value);
																			}
																	}
															}
													}
												snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
												strcat(a_string, wk_strg);
												strcat(a_string, "' '"); 
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #10");
														trace_rec_3();
													}
			
												strcpy(a_string, tfield1);
												check_length();
							strcat(a_string, "DCB   DSORG=PS,                                               x");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #11");
														trace_rec_3();
													}

												strcpy(a_string, "               EODAD=C370EF");
												/* get file buf_ct number */
												snprintf(wk_strg, sizeof(wk_strg), "%d", w_file[I].f_buf_ct);
												strcat(a_string, wk_strg);
												strcat(a_string, ",                                          x");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #12");
														trace_rec_3();
													}
			
							strcpy(a_string, "               RECFM=FT,                                               x");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #13");
														trace_rec_3();
													}

								strcpy(a_string, "               DDNAME=");
												strcat(a_string,tfield1);
												strcat(a_string, ",");
												check_continuation();
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #14");
														trace_rec_3();
													}
		
								strcpy(a_string, "               MACRF=PM,                                               x");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #15");
														trace_rec_3();
													}

								strcpy(a_string, "               SYNAD=0,                                                x");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #16");
														trace_rec_3();
													}

												strcpy(a_string, "               BLKSIZE=");
												snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
												strcat(a_string, wk_strg);
												strcat(a_string, ",");
												check_continuation();
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #17");
														trace_rec_3();
													}

												strcpy(a_string, "               LRECL=");
												snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
												strcat(a_string, wk_strg);
												strcat(a_string, ",");
												check_continuation();
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #18");
														trace_rec_3();
													}

												strcpy(a_string, "               RECORD=C370PB");
												snprintf(wk_strg, sizeof(wk_strg), "%d", w_file[I].f_buf_ct);
												strcat(a_string, wk_strg);
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #19");
														trace_rec_3();
													}

												strcpy(a_string, "*");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z.c buffer define #20");
														trace_rec_3();
													}
											}
									}
							}  

						

						/* *********************************************************** 
						* Punch out variable definitions.                            *
						*  w_variable[I}.v_type = C (char) are punched as CL         *
						*  w_variable[I].v_type = I (int) are punched ast PL4'0'     *
						* ********************************************************** */

						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';

						if(gv_ct == 0)
							{
								size = 1;
								gw_variable = malloc(size * sizeof(struct variables));
							}
						else
							{
								size = gv_ct + 1;
								gw_variable = realloc(gw_variable, size * sizeof(struct variables));
							}

						gw_variable[gv_ct].gv_rct = rct;
						strcpy(gw_variable[gv_ct].gv_cname, c_wkname);	
						strcpy(gw_variable[gv_ct].gv_name, "STRLEN");  	             
						strcpy(gw_variable[gv_ct].gv_type, "F"); 
						gw_variable[gv_ct].gv_lgth = 0;
						gw_variable[gv_ct].gv_current_lgth = 0;
						strcpy(gw_variable[gv_ct].gv_value, null_field);
						gw_variable[gv_ct].gv_init = 0;
						strcpy(gw_variable[gv_ct].gv_literal,null_field);
						gw_variable[gv_ct].gv_use_ct = 0;
						gw_variable[gv_ct].gv_dec = 0;
						gw_variable[gv_ct].gv_id = 2;
						gv_ct++;	
					
						strcpy(a_string, "******************************************************************");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #43");
								trace_rec_3();
							}
	
						strcpy(a_string, "*                                                                *");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #44");
								trace_rec_3();
							}

						strcpy(a_string, "* CODE AREA FOR CSECT -DOESN'T REQUIRE BASE REGISTER COVERAGE    *");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #45");
								trace_rec_3();
							}

						strcpy(a_string, "*                     -USE RELATIVE BRANCHES HERE                *");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #46");
								trace_rec_3();
							}

						strcpy(a_string, "*                     -DON'T CODE LITERALS HERE                  *");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #47");
								trace_rec_3();
							}

						strcpy(a_string, "*                                                                *");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #48");
								trace_rec_3();
							}

						strcpy(a_string, "******************************************************************");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #49");
								trace_rec_3();
							}

						strcpy(a_string, "START    DS    0H");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 Generated #50");
								trace_rec_3();
							}


/* **************************************************************************** 
*  Convert source c file all to UPPER Case.                                   *
* *************************************************************************** */

				rct = 0;
				end_asm = 1;
				else_active = 0;
				else_flag = 0;
 				inside_for = 0;

				if(trace_flag == 1)
					{
						strcpy(trace_2, "\n");
						trace_1[0] = '\0';
						trace_rec_1();
						strcpy(trace_2, "3");
					}

				while(1)
   					{

						convert = 0;
						fprintf_lit = 0;
						math_convert = 0;
						fprintf_flag = 0;
						convert_ignore = 0;

						fgets(p_string, BUFSIZE, pgm);
						rct++;

/* printf("Pass 3 rct = %d p_string = %s",rct,p_string); */

						strcpy(o_string, p_string);
				
      						if( feof(pgm) )
      							{ 
         							end_input = 1;
								
      							}

						p = strstr (p_string,"{");		
  						if(p)
							{
								parm_ct++;
								end_asm = 0;
								
							}
						p = strstr (p_string, "}");
  						if(p)
							{
								parm_ct--;
								end_asm = 0;
								
							}

						
/* ****************************************************************************
*  Test for prototypes  (skip)                                                *
* *************************************************************************** */
						p = strstr(p_string, "void");
						p1 = strstr(p_string, ";"); 
						p2 = strstr(p_string, "int");
						p3 = strstr(p_string, "(");
						p4 = strstr(p_string, ")");
						p5 = strstr(p_string, "printf");

						if((p) && (p1) && (!p5))
							{
								convert = 1;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z.c pass 3 test void");
										trace_rec_1();
										
									}
							}

						p = strstr(p_string, "void");
						p1 = strstr(p_string, ";"); 
						p2 = strstr(p_string, "int");
						p3 = strstr(p_string, "(");
						p4 = strstr(p_string, ")");
						p5 = strstr(p_string, "printf");
						p6 = strstr(p_string, "\"");
						if((p2) && (p3) && (p4) && (p1) && (convert == 0) && (!p5) && (!p6))
							{
								convert = 1;
								if(trace_flag == 1)
									{

										strcpy(trace_1, "c2z.c pass 3 test int");
										trace_rec_1();
									}

							}

/* ****************************************************************************
*  Test for #defines  (skip)                                                  *
* *************************************************************************** */
						p = strstr (p_string, "#define");
						
						if(p)
							{
								convert = 1;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z.c pass 3 test #define");
										trace_rec_1();
										if(return_on == 1)
											{
												return_ct++;
											}
									}

							}

/* ****************************************************************************
*  Test for #include  (skip)                                                  *
* *************************************************************************** */
						p = strstr (p_string, "#include");
						
						if(p)
							{
								convert = 1;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z.c pass 3 test #include");
										trace_rec_1();
									}

							}

/* ****************************************************************************
*  Test for FILE  (skip)                                                      *
* *************************************************************************** */
						p = strstr (p_string, "FILE");
						
						if(p)
							{
								convert = 1;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z.c pass 3 test file");
										trace_rec_1();
									}

							}

/* **************************************************************************** 
*  TEST for { }							    	        *
* *************************************************************************** */
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z.c pass 3 test blank line ");
								trace_rec_1();
							}

						int rt2 = 0;
						int rt3 = 0;
						int rt4 = 0;
						int rt5 = 0;
						int rt6 = 0;
												
						p = strstr(p_string,"{");
						p1 = strstr(p_string, "}");
						
						if((p) || (p1))
							{
								convert_ignore = 1;
								convert = 0;
								rt3 = strlen(p_string);
								for(rt2 = 0; rt2 < rt3; rt2++)
									{
										ch = p_string[rt2];
										if(ch == '{')
											{
												rt4++;
											}
										if(ch == '}')
											{
												rt5++;
											}
										if((ch == ' ') || (ch == '\t') || (ch == '\0') || (ch == '\n'))
											{
												rt6++;
											}
									}
							}
				

/* *****************************************************************
* Test for STRUCT                                                  *
* **************************************************************** */
				if((convert == 0)  && (continuation_comment == 0))
					{
						p = strstr (p_string, "struct");
						if(p)
							{
								c2_struct_3(); 
								convert = 1; 
							}
					}
						
/* ****************************************************************************
*  Test for MALLOC                                                            *
* *************************************************************************** */
						p = strstr (p_string, "malloc");
						p1 = strstr(p_string, "#include");
						
						if((p) && (!p1))
							{
								/* c2_scan_malloc(); */
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z.c pass 3 test malloc");
										trace_rec_1();
									}

								convert = 1; 
							}

/* ****************************************************************************
*  Test for remarks in source code                                            *
* *************************************************************************** */
						if(convert == 0)
							{
								p = strstr (p_string, "/*");
								p1 = strstr (p_string, "*/");

								if((continuation_comment == 1) && (!p1) && (!p2))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2z.c pass 3 test remarks #1");
												trace_rec_1();
											}

										strcpy(a_string, "*  ");
										strcat(a_string, p_string);
										src_line();
										convert = 1;
									}

								if((p) && (p1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2z.c pass 3 test remarks #2");
												trace_rec_1();
											}

										strcpy(a_string, "*  ");
										strcat(a_string, p_string);
										src_line();
										convert = 1;
									}

								if((p) && (!p1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2z.c pass 3 test #4");
												trace_rec_1();
											}

										strcpy(a_string, "*  ");
										strcat(a_string, p_string);
										src_line();
										continuation_comment = 1;
										convert = 1;
									}
	
								if((!p) && (p1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2z.c pass 3 test remarks");
												trace_rec_1();
											}

										strcpy(a_string, "*  ");
										strcat(a_string, p_string);
										src_line();
										continuation_comment = 0;
										convert = 1;
									}
							}


/* ****************************************************************************
*  test for { & }                                                             *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								x1 = 0;
								x2 = 0; 
								int bk1 = 0;
								int bk2 = 0;
								int bk3 = 0;

								s = strlen(p_string);
								for(I = 0; I < s; I++)
									{
										ch = p_string[I];
										if(ch == '{')
											{
												x1++;
											}
										if(ch == '}')
											{
												x2++;
											}
									}

								if((x1 > 0) || (x2 > 0))
									{
										if(inside_void == 2)
											{
												function_ct = function_ct + x1;
												function_ct = function_ct - x2;
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 test function_ct ");
														trace_rec_1();
													}

												/*  test for only  (		*/
												s = strlen(p_string);
												for(I = 0; I < s; I++)
													{
														ch = p_string[I];
														if(ch == '{')
															{
																bk1++;
															}
														if((ch == ' ') || (ch == '\n') || (ch == '\0'))
															{
																bk2++;
															}
													}
												if(bk1 > 0)
													{
														bk3 = bk1 + bk2;
														s--;
														if(s ==  bk3)
															{
																/* convert = 1; */
															}
													}

												bk1 = 0;
												bk2 = 0;
												bk3 = 0;
												s = strlen(p_string);
												for(I = 0; I < s; I++)
													{
														ch = p_string[I];
														if(ch == '}')
															{
																bk1++;
															}
														if((ch == ' ') || (ch == '\n') || (ch == '\0'))
															{
																bk2++;
															}
													}

												if(bk1 > 0)
													{
														bk3 = bk1 + bk2;
														s--;
														if(s ==  bk3)
															{
																/* convert = 1; */
															}

													}
											}
									}	
										
								if(inside_for == 1)
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2z.c pass 3 test inside for { }");
												trace_rec_1();
											}

										for_parm = for_parm + x1;
										for_parm = for_parm - x2;

										s = strlen(p_string);
										for(I = 0; I < s; I++)
											{
												ch = p_string[I];
												if(ch == '{')
													{
														bk1++;
													}
												if((ch == ' ') || (ch == '\n') || (ch == '\0'))
													{
														bk2++;
													}
											}

										if(bk1 > 0)
											{
												bk3 = bk1 + bk2;
												s--;
												if(s ==  bk3)
													{
													/* 	convert = 1; */
													}
											}

										bk1 = 0;
										bk2 = 0;
										bk3 = 0;
										s = strlen(p_string);
										for(I = 0; I < s; I++)
											{
												ch = p_string[I];
												if(ch == '}')
													{
														bk1++;
													}
												if((ch == ' ') || (ch == '\n') || (ch == '\0'))
													{
														bk2++;
													}
											}

										if(bk1 > 0)
											{
												bk3 = bk1 + bk2;
												s--;
												if(s ==  bk3)
													{
														/* convert = 1; */
													}

											}

									}

								if(if_case == 1)
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2z.c pass 3 test if_case { }");
												trace_rec_1();
											}

										case_parm_ct = case_parm_ct + x1;
										case_parm_ct = case_parm_ct - x2;
										
										s = strlen(p_string);
										for(I = 0; I < s; I++)
											{
												ch = p_string[I];
												if(ch == '{')
													{
														bk1++;
													}
												if((ch == ' ') || (ch == '\n') || (ch == '\0'))
													{
														bk2++;
													}
											}

										if(bk1 > 0)
											{
												bk3 = bk1 + bk2;
												s--;
												if(s ==  bk3)
													{
														/* convert = 1; */
													}
											}

										bk1 = 0;
										bk2 = 0;
										bk3 = 0;
										s = strlen(p_string);
										for(I = 0; I < s; I++)
											{
												ch = p_string[I];
												if(ch == '}')
													{
														bk1++;
													}
												if((ch == ' ') || (ch == '\n') || (ch == '\0'))
													{
														bk2++;
													}
											}

										if(bk1 > 0)
											{
												bk3 = bk1 + bk2;
												s--;
												if(s ==  bk3)
													{
													/*	convert = 1; */
													}

											}

									}

								if(inside_mn == 1)
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2z.c pass 3 test main { }");
												trace_rec_1();
											}

										parm_ct = parm_ct + x1;
										parm_ct = parm_ct - x2;

										s = strlen(p_string);
										for(I = 0; I < s; I++)
											{
												ch = p_string[I];
												if(ch == '{')
													{
														bk1++;
													}
												if((ch == ' ') || (ch == '\n') || (ch == '\0'))
													{
														bk2++;
													}
											}

										if(bk1 > 0)
											{
												bk3 = bk1 + bk2;
												s--;
												if(s ==  bk3)
													{
														/* convert = 1; */
													}
											}

										bk1 = 0;
										bk2 = 0;
										bk3 = 0;
										s = strlen(p_string);
										for(I = 0; I < s; I++)
											{
												ch = p_string[I];
												if(ch == '}')
													{
														bk1++;
													}
												if((ch == ' ') || (ch == '\n') || (ch == '\0'))
													{
														bk2++;
													}
											}

										if(bk1 > 0)
											{
												bk3 = bk1 + bk2;
												
											}
									}
							}


/* ****************************************************************************
* Test for int or char                                                        *
* *************************************************************************** */
						p = strstr(p_string, "int");
						p1 = strstr(p_string, "char");
						p2 = strstr(p_string, "print");
						p3 = strstr(p_string, "void");
						p4 = strstr(p_string, "main");
						p5 = strstr(p_string, ";");
						p6 = strstr(p_string, "snprintf");
						p7 = strstr(p_string, "\"");

						if((p) && (!p2) && (!p3) && (!p4) && (!p6) && (!p7))
							{

								convert = 1;
								c2_int_punch();
								if(return_on == 1)
									{
										return_ct++;
									}

							}

						if((p) && (!p2) && (!p4) && (p3) && (!p5) && (!p6) && (!p7))
							{
								convert = 1;
								
							}

						if((p1) && (!p3) && (!p4) && (!p7))
							{
								convert = 1;
							}
		

/* **************************************************************************** 
*  Test for MAIN in C program and if found punch to to ASM file               *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								mnflg = 0;
								if(mnflg != 1)
									{
										p = strstr (p_string,"main");		
  										if(p)
  											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2z.c pass 3 punch main MAIN");
														trace_rec_1();
													}

												inside_mn = 1;
												strcpy(sv_func, "main");
												strcpy(from_sv, "main");
												global_st = 1;

												mnflg = 1;
												set_mn = 1;

												convert = 1;
											}
									}	
							}


/* **************************************************************************** 
*  Punch IF statement                                                         *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr(p_string, "if");
								p3 = strstr(p_string, "strcmp");
								p1 = strstr(p_string, "int");
								p2 = strstr(p_string, "(");
								p4 = strstr(p_string, "_if");
								p5 = strstr(p_string, "\"");

								if((p) && (p2) && (!p1) && (!p4) && (convert == 0))
									{
										c2_if();
										var_use[7]++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
								
								if((p) && (p2) && (!p1) && (!p4) && (!p5) && (convert == 0))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2z.c pass 3 test if #1");
												trace_rec_1();
											}
										c2_if();
										var_use[7]++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}

								if((p) && (p2) && (p3) && (convert == 0) && (!p5))
									{
										c2_if();
										var_use[7]++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}

							}

/* **************************************************************************** 
*  Punch FPRINTF                                                              *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"fprintf");
								p1 = strstr(p_string, "snprintf");
								if((p) && (!p1)) 			
  									{
										c2_fprintf();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}

/* **************************************************************************** 
*  Punch PRINTF                                                               *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr(p_string,"printf");
								p1 = strstr(p_string, "snprintf");
								printf_convert = 0;
  								if((p) && (!p1) && (fprintf_flag != 1))		
									{
										c2_printf();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}


/* **************************************************************************** 
*  Punch SNPRINTF                                                             *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p1 = strstr(p_string, "snprintf");
								if(p1)		
									{
										c2_snprintf();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}


/* **************************************************************************** 
*  Punch SCANF                                                                *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p1 = strstr(p_string, "scanf");
								if(p1)
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2z.c pass 3 test scanf");
												trace_rec_1();
											}
										c2_scanf();
										convert = 1;
									}

							}


/* ***************************************************************************
*  Punch CASE                                                                *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"case");		
  								if(p) 		
									{
										c2_case();
										tot_case++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}

/* ***************************************************************************
*  Punch CASE DEFAULT                                                        *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"default");
  								if((p) && (if_case == 1)) 		
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2z.c pass 3 test default");
												trace_rec_1();
											}
										c2_case_default();
										tot_case++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}

/* ***************************************************************************
*  Punch BREAK                                                               *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"break");		
  								if((p) && (if_case == 1)) 		
									{
										c2_break();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}

/* ***************************************************************************
*  Punch RETURN                                                              *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"return");		
  								if(p) 		
									{
										convert = 1;
										if(trace_flag == 1)
											{
												strcpy(trace_1, "Punch RETURN");
												trace_rec_1();
											}

										c2_return();
									}
							}

/* ***************************************************************************
*  Punch SWITCH                                                              *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"switch");		
  								if(p) 		
									{
										c2_switch();
										tot_switch++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}

/* **************************************************************************** 
*  Punch FCLOSE                                                               *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"fclose");		
  								if(p) 		
									{
										c2_close();
										var_use[6]++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}


/* **************************************************************************** 
*  Punch FREE                                                                 *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr(p_string,"free");		
  								if(p) 
									{
										c2_free();
										var_use[14]++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}


/* **************************************************************************** 
*  If inside_main == 0 & parm_ct == 0, then the end of main loop of the C     *
*  program has been reached.  Punch out the end statement and all defines     *
*  before processing an functions that may be defined.                        *
* *************************************************************************** */
						if(parm_ct < 0)
							parm_ct = 0;


						if((convert == 0) && (continuation_comment == 0) && (inside_mn == 1) && (parm_ct == 0)) 
							{
								inside_mn = 0;

								strcpy(a_string, "C370EXIT DS    0H");
								src_line();
								var_use[1]++;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z.c pass 3 punch C370EXIT");
										trace_rec_3();
									}
										
								strcpy(a_string, "         SUBEXIT");
								src_line(); 
								var_use[1]++;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z.c pass 3 punch subexit");
										trace_rec_3();
									}

								strcpy(a_string, "*");
								src_line(); 
								var_use[1]++;
	
								convert = 1;
							}

		
/* ****************************************************************************
*  test rct against wif_table eof1 & eof2                                     * 
* *************************************************************************** */
						if((convert == 0) && (continuation_comment == 0))
							{
								if(wif_ct > 0)
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2.c IF End Label");
											}
 
										v = 0;
										for(v = 0; v < wif_ct; v++)
											{
												if((rct == w_if_table[v].wif_eof1) && (w_if_table[v].wif_else == 0))
													{
														/* if they match punch out equ label */
														strcpy(a_string, "L");
														snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[v].wif_rct);
														strcat(a_string, wk_strg);
														check_length();
														strcat(a_string,"DS    0H");
														strcpy(wk_remark, " if end   */");
														write_remark();
														if(punch_code == 1)
															{
																strcpy(trace_1, "Pass3 c2.c IF End Label #1");
																trace_rec_3();
															}

														if(return_on == 1)
															{
																return_ct++;
															}

													}

												if((rct == w_if_table[v].wif_eof1) && (w_if_table[v].wif_else != 0))
													{
														/* if they match punch out branch */
														strcpy(a_string, "         JLU   ");
														strcat(a_string, "L");
														snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[v].wif_eof2);
														strcat(a_string, wk_strg);
														src_line();
														if(punch_code == 1)
															{
																strcpy(trace_1, "Pass3 c2.c IF End Label #2");
																trace_rec_3();
															}

														strcpy(a_string, "L");
														snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[v].wif_rct);
														strcat(a_string, wk_strg);
														check_length();
														strcat(a_string,"DS    0H");
														strcpy(wk_remark, " else     */");
														write_remark();
														if(punch_code == 1)
															{
																strcpy(trace_1, "Pass3 c2.c IF End Label #3");
																trace_rec_3();
															}
														if(return_on == 1)
															{
																return_ct++;
															}

													}

												if(rct == w_if_table[v].wif_eof2)		/* punch out branch using eof2 */
													{
														/* if they match punch out equ label */
														strcpy(a_string, "L");
														snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[v].wif_eof2);
														strcat(a_string, wk_strg);
														check_length();
														strcat(a_string,"DS    0H");
														strcpy(wk_remark, " if end   */");
														write_remark();
														if(punch_code == 1)
															{
																strcpy(trace_1, "Pass3 c2.c IF End Label #4");
																trace_rec_3();
															}

														if(return_on == 1)
															{
																return_ct++;
															}
		
													}
											}
									}	

								if(wh_ct > 0)
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2z.c while end label");
												trace_rec_1();
											}

											for(v = 0; v < wh_ct; v++)
												{
													if(rct == w_while_table[v].wh_eof1)		
														{
															for(v1 = 0; v1 < gv_ct; v1++)
																{
																	ret = strcmp("A", gw_variable[v1].gv_type);
																	if(ret == 0)
																		{
																			strcpy(ar_field6, gw_variable[v1].gv_label);
																			strcpy(ar_field7, gw_variable[v1].gv_table);
																			strcpy(ar_field8, gw_variable[v1].gv_aname);
																			strcpy(ar_field9, gw_variable[v1].gv_sv_reg);
																			strcpy(ar_field10, gw_variable[v1].gv_wk_reg);
																			strcpy(ar_field11, gw_variable[v1].gv_wk_strg);

																			if(gw_variable[v1].gv_flag > 0)
																				{
																					strcpy(a_string, "         LA    R6,");
																					strcat(a_string, ar_field6);
																					strcat(a_string, "(R0,R6)");
																					src_line();
																					if(punch_code == 1)
																						{
																							strcpy(trace_1, "c2z.c WHILE End Label #1");
																								trace_rec_3();
																						}
																					
																					gw_variable[v1].gv_flag = 0;
																				}	
																		}
																}
															
															strcpy(a_string, "         JLU   ");
															strcat(a_string, "L");
															snprintf(wk_strg, sizeof(wk_strg), "%d", w_while_table[v].wh_rct);
															strcpy(o_string, wk_strg);
															strcat(a_string, wk_strg);
															strcpy(wk_remark, " while br */");
															write_remark();
															if(punch_code == 1)
																{
																	strcpy(trace_1, "c2z.c while end label #2");
																	trace_rec_3();
																}
															
															strcpy(a_string, "L");
															strcat(a_string, o_string);
															strcat(a_string,"E");
															check_length();
															strcat(a_string,"DS    0H");
															strcpy(wk_remark, " end wh   */");
															write_remark();
															if(punch_code == 1)
																{
																	strcpy(trace_1, "c2z.c while end label #3");
																	trace_rec_3();
																}

															if(return_on == 1)
																{
																	return_ct++;
																}

															strcpy(a_string, "         LARL  R9,C370NWK2");
															src_line();
															if(punch_code == 1)
																{
																	strcpy(trace_1, "c2z.c while end label #4");
																	trace_rec_3();
																}
															work_use_ct[50]++;

															strcpy(a_string, "         LARL  R8,C370ZERO");
															src_line();
															if(punch_code == 1)
																{
																	strcpy(trace_1, "c2z.c while end label #5");
																	trace_rec_3();
																}

															strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
															src_line();
															if(punch_code == 1)
																{
																	strcpy(trace_1, "c2z.c while end label #6");
																	trace_rec_3();
																}

															strcpy(a_string, "         LARL  R9,C370LPCT");
															src_line();
															if(punch_code == 1)
																{
																	strcpy(trace_1, "c2z.c while end label #7");
																	trace_rec_3();
																}

															strcpy(a_string, "         LARL  R8,C370ZERO");
															src_line();
															if(punch_code == 1)
																{
																	strcpy(trace_1, "c2z.c while end label #8");
																	trace_rec_3();
																}

															strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
															src_line();
															if(punch_code == 1)
																{
																	strcpy(trace_1, "c2z.c while end label #9");
																	trace_rec_3();
																}
															work_use_ct[73]++;
														}
												}
									}	

							}				

/* ****************************************************************************
*   if_case == 1 && case_parm_ct == 0  end of case loop                       *
*   punch out end of case loop                                                *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment== 0))
							{
								if((if_case == 1) && (case_parm_ct == 0))
									{
										c2_case_end();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}


/* **************************************************************************** 
*  Punch B back from function                                                 *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string, "}");
								if((p) && (inside_void == 2) && (function_ct == 0)) 
									{
										c2_func_end();
										convert = 1;
										inside_void = 0;
									}
							}
				

/* **************************************************************************** 
*  Punch user VOID FUNCTION code                                              *
* *************************************************************************** */
						if(fn_ct > 0)
							{
								for(I = 0; I < fn_ct; I++)
									{
										if(rct == w_function[I].fn_start)
											{
												c2_func_sub();
												convert = 1;
												if(return_on == 1)
													{
														return_ct++;
													}

												break;
											}
									}
							}
								
					
/* **************************************************************************** 
*  FOR loop END                                                               *
*  If inside_for == 1 & for_parm == 0, then the end of if loop of the C       *
*  for loop has been reached.  Punch out branch back and equ label            *
* *************************************************************************** */
						if((convert == 0) && (continuation_comment == 0))
							{
								if((inside_for == 1) && (for_parm == 0))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2.c FOR/End Loop");
												trace_rec_1();
											}

										strcpy(a_string, "         LARL  R9,");
										strcat(a_string, sv_for_incr);
										strcpy(wk_remark," ");
										strcat(wk_remark, sv_for_incr);
										strcat(wk_remark, " */");
										write_remark();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z.c FOR/End Loop #1");
												trace_rec_3();
											}

										strcpy(a_string, "         LARL  R8,C370ONE");
										strcpy(wk_remark, " C370ONE */");
										write_remark();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z.c FOR/End Loop #2");
												trace_rec_3();
											}

										strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z.c FOR/End Loop #3");
												trace_rec_3();
											}

										strcpy(a_string, "         JLU   ");
										strcat(a_string, sv_for_return);
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z.c FOR/End Loop #4");
												trace_rec_3();
											}

										strcpy(a_string, sv_for_return);
										strcat(a_string, "E");
										check_length();
										strcat(a_string, "DS    0H");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z.c FOR/End Loop #5");
												trace_rec_3();
											}
										
										strcpy(a_string, "         LARL  R9,C370LPCT");
										src_line();
									       if(punch_code == 1)
											{
												strcpy(trace_1, "c2z.c FOR/End Loop #6");
												trace_rec_3();
											}

										strcpy(a_string, "         LARL  R8,C370ZERO");
										strcpy(wk_remark, " C370ONE */");
										write_remark();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z.c FOR/End Loop #7");
												trace_rec_3();
											}

										strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z.c FOR/End Loop #8");
												trace_rec_3();
											}

										inside_for = 0;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}

/* **************************************************************************** 
*  Punch FOR                                                                  *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string, "for");
								if(p)
									{
										c2_for();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}

				

/* ***************************************************************************
*  Punch STRCAT                                                              *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"strcat");		
  								if(p) 		
									{
										c2_strcat();
										var_use[14]++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}

/* ***************************************************************************
*  Punch STRLEN                                                              *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"strlen");		
  								if(p) 		
									{
										c2_strlen();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}


/* ***************************************************************************
*  Punch STRCHR                                                              *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"strchr");		
  								if(p) 		
									{
										c2_strchr();
										tot_strchr++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}


/* ***************************************************************************
*  Punch STRSTR                                                              *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"strstr");		
  								if(p) 		
									{
										c2_strstr();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}


/* ***************************************************************************
*  Punch MEMCPY                                                              *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"memcpy");		
  								if(p) 		
									{
										c2_memcpy();
										tot_memcpy++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}


/* ***************************************************************************
*  Punch MEMMOVE                                                             *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"memmove");		
  								if(p) 		
									{
										c2_memmove();
										tot_memmove++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}



/* ***************************************************************************
*  Punch STRCPY                                                              *
* ************************************************************************** */

						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"strcpy");		
  								if(p) 		
									{
										c2_strcpy();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}




/* **************************************************************************** 
*  Punch WHILE                                                                *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string, "while");
								p1 = strchr(p_string, '"');
								if(p) 
									{
										c2_while();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}

									}
							}

/* ***************************************************************************
*  Punch STRCMP                                                              *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr(p_string,"strcmp");
								if(p)		
									{
										c2_strcmp();
										tot_strcmp++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}


/* ***************************************************************************
*  Punch SIZEOF                                                              *
* ************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr(p_string, "sizeof");
						
								if(p)
									{
										tot_sizeof++;
										c2_sizeof();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}


/* **************************************************************************** 
*  Punch ++ statement                                                         *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string, "++");
								p1 = strstr(p_string, "printf");
								if((p) && (!p1))
									{
										c2_plus();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}


/* **************************************************************************** 
*  Punch -- statement                                                         *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string, "--");
								if(p)
									{
										c2_minus();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}



/* **************************************************************************** 
*  Punch out goto statement                                                   *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string, "goto");
								if(p)
									{
										c2_goto();
										tot_goto++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}


/* **************************************************************************** 
*  Punch out goto label statement                                             *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0) && (if_case == 0))
							{
								p = strstr (p_string, ":");
								if(p)
									{
										c2_goto_label();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}


	
/* **************************************************************************** 
*  Punch out FOPEN                                                            *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"fopen");		
  								if(p)				
  									{
										c2_open();
										var_use[5]++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}

										
/* **************************************************************************** 
*  Punch out FGETS                                                            *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"fgets");		
  								if(p)				
  									{
										c2_fgets();
										var_use[18]++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}


										
/* **************************************************************************** 
*  Punch out FPUTS                                                            *
* *************************************************************************** */

						if((convert == 0)  && (continuation_comment == 0))
							{
								p = strstr (p_string,"fputs");		
  								if(p)				
  									{
										c2_fputs();
										tot_fputs++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}


/* **************************************************************************** 
*  Punch out ATOI                                                             *
* *************************************************************************** */
					if((convert == 0)  && (continuation_comment == 0)) 
							{	
								p = strstr (p_string,"atoi");		
  								if(p)				
  									{
										c2_atoi();
										var_use[13]++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}


/* **************************************************************************** 
*  Punch out STRNCPY                                                          *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0)) 
							{	
								p = strstr (p_string,"strnccpy");		
  								if(p)				
  									{
										c2_strncpy();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}


/* **************************************************************************** 
*  Punch out STRSET                                                           *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0)) 
							{	
								p = strstr (p_string,"strset");		
  								if(p)				
  									{
										c2_strset();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}

/* **************************************************************************** 
*  Punch STRREV                                                           *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0)) 
							{	
								p = strstr (p_string,"strrev");		
  								if(p)				
  									{
										c2_strrev();
										convert = 1;
									}
							}

/* **************************************************************************** 
*  Punch out LOCALTIME     MUST BEFORE TIME                                   *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0)) 
							{	
								p = strstr (p_string,"localtime");		
  								if(p)				
  									{
										c2_localtime();
										tot_localtime++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}


/* **************************************************************************** 
*  Punch out CTIME                                                            *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0)) 
							{	
								p = strstr (p_string,"ctime");		
  								if(p)				
  									{
										c2_ctime();
										tot_localtime++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}


/* **************************************************************************** 
*  Punch out TIME                                                             *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0)) 
							{	
								p = strstr (p_string,"time");		
  								if(p)				
  									{
										c2_time();
										tot_time++;
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}


/* **************************************************************************** 
*  Punch out EXIT                                                             *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0)) 
							{	
								p = strstr (p_string,"exit");		
  								if(p)				
  									{
										c2_exit();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}

/* **************************************************************************** 
*  Punch out FUNCTION START                                                   *
* *************************************************************************** */
						if((convert == 0)  && (continuation_comment == 0)) 
							{	
								p = strstr (p_string,"void");
								p1 = strstr(p_string, "(");
		
  								if((p) && (p1))				
  									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2z.c Function Start");
												trace_rec_1();
											}

										/* convert = 1; */
									}
							}
							
		
/* ***************************************************************************
*  Punch out function call                                                   *
* ************************************************************************** */
					if((convert == 0) && (continuation_comment == 0))
							{
						
								for(I=0; I < fns_ct; I++)
									{
										if((rct == w_func_start[I].fns_rct) && (convert == 0))
											{
												c2_func_call(); 
												convert = 1;
												if(return_on == 1)
													{
														return_ct++;
													}

												break;		
											}
									}
							}

/* ****************************************************************************
*      Math functions ( =, +, -, *, / ) MUST BE LAST CALL IN PARSER           *
*              			     EXECPT FOR REMARK CHECK               *
* *************************************************************************** */
						if((convert == 0) && (continuation_comment == 0))
							{
								p = strstr (p_string, "=");
								p1 = strstr (p_string, "enum");
								if((p) && (!p1))
									{

										c2_math();
										convert = 1;
										if(return_on == 1)
											{
												return_ct++;
											}
									}
							}

	
/* ****************************************************************************
*      end of while loop for Pass 3, punching out ASM code                    *
* *************************************************************************** */

						if(end_input == 1)
							{
								 break; 
							}

					}  


/******************************************************************************
*      Call c2_eoj to punch out end-of-program code.                          *
* *************************************************************************** */
	
			c2_eoj();

		exit(0);
			
	}	

