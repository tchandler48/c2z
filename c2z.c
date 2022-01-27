/* *************************************************************
*  c2z.c Parser                                                *
*  Copyright TCCS (c) 2015 - 2022                              *
* ************************************************************ */

/* *************************************************************
*  GENERAL NOTES                                               *
*									*
*  Dsect Arrarys MUST have the gw_variable[x].gv_flag to 1 so  *
*  	Dsect address reset will take place.                    *
*									*
* ************************************************************ */

#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------ declare constants ------ */
#define IOARRAY 99
#define PATH 129
#define BUFSIZE 128
#define VAR_LGTH 33

/*            c2z_arth.c           */
       double c2_math_start(void);
       double c2_Expression(void);


/* 	       c2z_atof.c		*/
	void c2_atof(void);
       void c2_atof_punch(void);


/* 	       c2z_atoi.c		*/
	void c2_atoi(void);


/* 	       c2z_atof.c		*/
	void c2_atof(void);
       void c2_atof_punch(void);

/* 	       c2z_atol.c		*/
	void c2_atol(void);
       void c2_atol_punch(void);

/*		c2z_case.c		*/
	void c2_case(void);	
	void c2_pass2_case(void);


/* 	       c2z_char.c		*/
	void c2_char(void);
	void c2_char_1(void);
	void c2_char_2(void);
	void c2_char_3(void);
	void c2_char_4(void);
	void c2_char_5(void);
	void c2_char_6(void);
	void c2_char_9(void);
       void c2_char_41(void);
       void c2_char_punch(void);


/*		c2z_const.c		*/
	void c2_const(void);


/*		c2z_ctime.c		*/
	void c2_ctime(void);
       void c2_time_t(void);
       void c2_time_t_punch(void);


/* 	       c2z_debug.c		*/
	void c2_debug(void);
	void c2_dump(void);
	void c2_print_files(void);


/*		c2z_decr.c		*/
	void c2_minus(void);


/*		c2z_define.c 		*/
	void c2_define(void);
	void c2_ifndef(void);
	void c2_endif(void);


/* 	       c2z_double.c		*/
	void c2_double(void);
       void c2_pass_2_double(void);
       void c2_double_punch(void);
       void c2_dbl_41(void);


/*		c2z_enum.c		*/
	void c2_enum_scan(void);


/*		c2z_exit.c		*/
	void c2_exit(void);


/*		c2z_fclose.c		*/
	void c2_close(void);


/*		c2z_feof.c		*/
	void c2_scan_feof(void);	 


/*		c2z_fgets.c		*/
	void c2_fgets(void);
	void c2_scan_fgets(void);


/* 	       c2z_file.c		*/
	void c2_file(void);
	void c2_puts(void);
	void c2_gets(void);
       void c2_file_remove(void);
       void c2_fgets_pass2(void);
       void c2_fgets_punch(void);
       void c2_getchar_pass2(void);
       void c2_getchar_punch(void);


/*		c2z_fopen.c		*/
	void c2_open(void);
	void c2_scan_fopen(void);	


/* 	       c2z_for.c		*/
	void c2_for(void);


/*		c2z_fputs.c		*/
	void c2_fputs(void);
	void c2_scan_fputs(void);

/* 	       c2z_free.c		*/
	void c2_free(void);


/* 	       c2z_function.c	*/
	void c2_func_call(void);	
	void c2_func_end(void);
	void c2_func_sub(void);
	void c2_scan_func(void);
	void c2_scan_sub(void);
       void scan_func_name_1(void);

/*		c2z_goto.c 		*/
	void c2_goto(void);
	void c2_goto_label(void);
       void c2_goto_scan(void);


/* 	       c2z_if.c		*/
	void c2_if(void);
	void c2_switch(void);
	void c2_case_end(void);
	void c2_break(void);
	void c2_case_default(void);
	void if_case_1(void);
	void if_case_2(void);
	void if_case_3(void);
	void if_case_4(void);
	void if_case_6(void);
	void if_case_7(void);
	void if_case_8(void);
	void if_case_9(void);
	void if_case_10(void);
	void if_case_11(void);
	void if_case_12(void);
	void if_case_13(void);
	void if_case_15(void);
	void if_case_22(void);
	void if_case_23(void);
       void if_case_24(void);
	void if_case_30(void);
       void if_case_40(void);
       void if_case_41(void);
       void if_case_42(void);
       void if_case_43(void);
       void if_case_44(void);
       void if_case_45(void);
       void if_case_46(void);
       void if_case_47(void);
       void if_case_48(void);
       void if_case_49(void);

       void if_case_51(void);
	void if_case_55(void);


/*		c2z_incr.c		*/
	void c2_plus(void);


/* 	       c2z_int.c		*/
	void c2_int(void);
	void c2_int_1(void);
	void c2_int_2(void);
	void c2_int_3(void);
      	void c2_int_5(void);
	void c2_int_6(void);
       void c2_int_41(void);
	void c2_int_punch(void);
	void c2_int_punch_1(void);
	void c2_int_punch_2(void);


/*            c2z_internet.c       */
       void c2_bind(void);
       void c2_listen(void);      
       void c2_send(void);


/*		c2z_isalpha.c		*/
	void c2_isalpha(void);


/*		c2z_isalnum.c		*/
	void c2_isalnum(void);


/*		c2z_isdigit.c		*/
	void c2_isdigit(void);

/*		c2z_isspace.c		*/
	void c2_isspace(void);


/*		c2z_isupper.c		*/
	void c2_isupper(void);
       void c2_toupper(void);


/*            c2z_main.c           */
       void c2_main(void);

	
/*		c2z_malloc.c 		*/
	void c2_scan_malloc(void);


/* 	       c2z_math.c		*/
	void c2_math(void);
	void c2_reg_math(void);
	void c2_math_1(void);
	void c2_math_2(void);
	void c2_math_5(void);
	void c2_math_51(void);
       void c2_math_52(void);
       void c2_math_58(void);
	void c2_math_6(void);
	void c2_math_7(void);
	void c2_math_8(void);
	void c2_math_9(void);
	void c2_math_add(void);
	void c2_math_sub(void);
	void c2_math_mult(void);
	void c2_math_div(void);
	void c2_math_98(void);
	void c2_math_99(void);
       void c2_math_100(void);
       void c2_math_600(void);
       void c2_math_601(void);
       void c2_math_603(void);
       void c2_math_700(void);
       void c2_math_800(void);
       void c2_math_820(void);
       void c2_math_830(void);


/*		c2z_math_parser.c	*/
	 int c2_math_parser();
	 int c2_math_00(void);
	 int c2_math_01(void);
	 int c2_math_02(void);
	 int c2_math_03(void);
	void c2_math_04(char);
	void c2_math_05(void);
	 int c2_math_06(void);
	 int c2_math_07(char);
	 int c2_msth_08(char);
	 int c2_math_09(char);
	void c2_math_10(void);


/* 	       c2z_math_func.c	*/
	void c2_cos_pass2(void);
       void c2_cos_punch(void);
       void c2_pow_pass2(void);
       void c2_pow_punch(void);
	void c2_rand_pass2(void);
       void c2_rand_punch(void);
	void c2_sin_pass2(void);
       void c2_sin_punch(void);
	void c2_sqrt_pass2(void);
       void c2_sqrt_punch(void);
	void c2_tan_pass2(void);
       void c2_tan_punch(void);

/* 	       c2z_mem.c		*/
	void c2_mempy(void);
	void c2_memmove(void);


/* 	       c2z_misc.c		*/
	void c2_regs(void);
	void c2_main(void);
	

/*            c2z_mparser.c        */
       void c2_mparser(void);


/* 	       c2z_paramaters.c	*/
	void c2_param_ct(void);
	void c2_param_ct_2(void);
	void c2_param_ct_3(void);
	void c2_param_ct_4(void);
	void c2_param_ct_5(void);
	void c2_param_ct_6(void);
	void c2_param_ct_7(void);
	void c2_param_ct_8(void);
	void c2_param_ct_9(void);
	void c2_param_ct_10(void);
	void c2_param_ct_11(void);


/* 	       c2z_pass_2.c		*/
	void scan_func_name_2(void);
	void scan_func_name_3(void);
	void c2_return_2(void);
	void c2_math_literal(void);
       void c2_math_literal_1(void);
	void c2_math_literal_6(void);
       void c2_math_literal_7(void);
	void c2_math_literal_8(void);
	void c2_math_literal_99(void);
      	void c2_strlen_pass2(void);
       void c2_pass2_for(void);
	void c2_pass2_strcat(void);
	void c2_pass2_if(void);
	void c2_pass2_if_1(void);
	void c2_pass2_if_2(void);
       void c2_pass2_if_4(void);
       void c2_pass2_if_7(void);
       void c2_pass2_if_10(void);
	void c2_pass2_if_13(void);
	void c2_pass2_if_15(void);
       void c2_pass2_if_55(void);
	void c2_pass2_while(void);
	void c2_pass2_while_1(void);
	void c2_pass2_while_2(void);
       void c2_pass2_while_4(void);
	void c2_pass2_while_5(void);
	void c2_pass2_while_7(void);
       void c2_pass2_while_8(void);
       void c2_pass2_while_11(void);
       void c2_pass2_while_12(void);
	void c2_pass2_while_13(void);
       void c2_pass2_while_14(void);
       void c2_pass2_while_33(void);
	void c2_pass2_math(void);
       void c2_pass2_math_1(void);
	void c2_pass2_math_5(void);
       void c2_pass2_math_6(void);
	void c2_pass2_math_51(void);
       void c2_pass2_math_99(void);
	void c2_pass2_strrev(void);
       void c2_pass2_math_600(void);
      

/* 	       c2z_pass_3.c		*/
       void c2_pass_3(void);

/*                                 */
	void c2_return(void);

/* 	       c2z_print.c		*/
       void c2_printf(void);
       void c2_printf_literal(void);
      
	void c2_printf_str1(void);
       void c2_printf_str2(void);
       void c2_printf_str3(void);

       void c2_printf_dec(void);
	void c2_printf_dec1(void);
	void c2_printf_dec2(void);



	void c2_fprintf(void);
	void c2_printf_numeric(void);
	void c2_printf_string(void);
	void c2_printf_dec_only(int);
	void c2_snprintf(void);
       void c2_printf_float(void);
       void c2_printf_literal(void);
       void c2_printf_2ds(void);
       void c2_printf_toupper(void);
       void c2_printf_array_string(void);
       void c2_sprintf(void);


/* 	       c2z_punch_macro.c	*/
	void c2_punch_eoj(void);
	void c2_isupper(void);


/* 	       c2z_realloc.c		*/
	void c2_scan_realloc(void);


/*		c2z_scanf.c		*/
	void c2_scanf(void);


/*		c2z_sizeof.c		*/
	void c2_sizeof(void);
	void c2_pass2_sizeof(void);


/*		c2z_strcat.c		*/
	void c2_strcat(void);


/*		c2z_strchr.c 		*/
	void c2_strchr(void);
	void c2_strchr_scan(void);


/* 	       c2z_strcmp.c		*/
	void c2_strcmp(void);
	void c2_strcmp_1(void);
	void c2_strcmp_2(void);
	void c2_strcmp_3(void);

/*		c2z_strncmp.c		*/
	void c2_strncmp_2(void);


/* 	       c2z_strcpy.c		*/
	void c2_strcpy(void);
	void c2_str_1(int,int);
	void c2_str_2(int,int);
	void c2_str_3(int,int);
	void c2_str_4(void);
	void c2_str_5(void);
       void c2_str_6(void);
       void c2_str_7(void);
       void c2_str_8(void);
       void c2_str_9(void);
       void c2_str_10(void);
       void c2_str_11(void);
       void c2_str_12(void);
       void c2_str_13(void);
	void c2_strcpy_pass2(void);
	void c2_pass2_strcpy_2(int,int);


/* 	       c2z_strlen.c		*/
	void c2_strlen(void);
	void c2_strlen_punch(void);

	
/* 	       c2z_strrev.c		*/
	void c2_strrev(void);


/* 	       c2z_strset.c		*/
	void c2_strset(void);


/* 	       c2z_strncpy.c		*/
	void c2_strncpy(void);


/* 	       c2z_strrchr.c		*/
	void c2_strrchr(void);


/*            c2z_strstr.c		*/
       void c2_strstr(void);
       void c2_strstr_scan(void);
       void c2_strstr_41(void);

 
/*		c2z_struct.c		*/
	void c2z_struct(void);
	void c2_struct_3(void);
       void c2_struct_4(void);


/* 	       c2z_time.c		*/
	void c2_ctime(void);
	void c2_time(void);
	void c2_compute_time(void);
	void c2_localtime(void);
       void c2_clock_pass2(void);
       void c2_clock_punch(void);


/*            c2z_u_short.c        */
       void c2_u_short(void);



/* 	       c2z_unsigned.c	*/
	void c2_unsigned(void);
       void c2_unsigned_punch(void);


/*            c2z_utility.c         */
	void write_remark();	
	void write_remark_long();
	void write_short(); 
	void write_variable(); 
	void check_blank(void);
	void check_length(void);
	void check_continuation(void);
	void change_case(void);
	void verbose(void);
	void trace_rec_1(void);
	void trace_rec_2(void);
	void trace_rec_3(void);
	void c2_white(void);
	void src_line(void);
       void c2_error(void);
       void c2_count_bracket(void);
       void c2_count_paren(void);
       void pgm_label(void);


/* 	       c2z_while.c		*/
	void c2_while(void);
	void c2_while_1(void);
	void c2_while_7(void);
	void c2_while_8(void);
	void c2_while_9(void);
	void c2_while_10(void);
	void c2_while_11(void);
	void c2_while_12(void);
	void c2_while_13(void);
	void c2_while_14(void);
	void c2_while_15(void);
	void c2_while_16(void);
       void c2_while_17(void);
       void c2_while_20(void);
			

/* ------ global vars ------------ */
FILE *pgm;
FILE *c_src;
FILE *cc370;
FILE *c_tmp;
FILE *c_h; 		                            /* these are the i/o file handles 		*/
char s_holder[BUFSIZE];   				/* xstring (print) data holder  		*/
char p_string[BUFSIZE];   				/* file input string  			*/
char a_string[BUFSIZE];   				/* file output string                 	*/
char o_string[BUFSIZE];   				/* original C code				*/
char wk_string[BUFSIZE];  				/* work string				*/
char x_string[BUFSIZE];   					
char save_case_break[12]; 				/* save field for storing case break	*/
char ch2;                 				/* work in lower-to-upper			*/
char trace_1[53];         				/* trace sub name				*/
char trace_2[2];          				/* trace pass indicator			*/
char print_array_name[VAR_LGTH]; 			/* print array name */
char print_array_table[VAR_LGTH]; 			/* print array table */
char while_array_name[VAR_LGTH]; 			/* while array name */
char while_array_table[VAR_LGTH]; 			/* while array table */
char sv_prt_string[80]; 				/* work string in print numeric		*/
char pgm_name[8];
char ret_fn[VAR_LGTH];
char tfield99[VAR_LGTH];
char for_2nd[VAR_LGTH];
char ptr_lgth[6];
char strtmp[128];
char c_output_file[24];
char c_wkname[24];
char start_while[12];
char sv_func[VAR_LGTH];
char sv_print_lit[VAR_LGTH];
char null_field[2];
char wk_fdwk[24];
char sub_name[24];
char wk_strg[8];     
char wk_remark[22];
char sv_if_branch[24];
char err_msg[242];
char while_tag[8];
char sw_field[12];
char sw_tag[12];
char sv_for_return[8];
char sv_for_incr[8];
char sv_while[VAR_LGTH];
char wk_file[VAR_LGTH];
char asm_file[VAR_LGTH];

char from_sv[24];

/* variables used for pointers into functions			*/
 int traceflg = 0; 					/* trace flag 0 = mo, 1 = yes		*/
 int puncde = 0;   					
 int gv_ct = 0;    					/* variable count - global			*/
 int lv_ct = 0;    					/* variable count - local			*/
 int f_ct = 0;     					/* variable count - file opens		*/
 int fn_ct = 0;    					/* variable count - function 		*/
 int main_set = 0;
 int debug = 1; 					/* Turn on debug 0 = No, 1 = Yes	       */
 int global_st = 0;
 int z390 = 0;           				/* s390 flag                              */
 int rct = 0;            				/* record count				*/
 int convert = 0;        				/* flag to indicate the line is convert   */
 int convert_ignore = 0; 				/* flag for comments & {} only		*/
 int if_convert = 0;     				/* if flag used in if_case routines	*/
 int return_on = 0;      				/* return flag				*/
 int return_ct = 0;      				/* count lines after return			*/
 int char_ct = 0;        				/* count for char_lit table			*/
 int func_x1 = 0;        				/* function count start			*/
 int func_x2 = 0;        				/* function count stop			*/
 int m_struc_ct = 0;     				/* m_struct counter				*/
 int def_it = 1;         				/* ifndef flag				*/
 int cary_ct = 0;
 int stru_ct = 0;
 int fake = 0;
 int k7 = 0;
 int k8 = 0;
 int k9 = 0;
 int debug_lv = 0;
 int math_lit_ct = 0;
 int param_l = 0;
 int param_r = 0;
 int for_ct = 0;
 int for_convert = 0;
 int for_level = 0;
 int bracket_convert = 0;
 int bad_rec_ct = 0;
 int free_loop = 0;
 int erct = 0;
 int e_pos = 0;
 int line_ndx = 0;
 int fd_test = 0;
 int st_col = 0;
 int quote_1 = 0;
 int quote_2 = 0;
 int quote_3 = 0;
 int for_2nd_ct = 0;
 
/* usage counters	*/
 int var_use[24];

/* *************************************************************
*  1	=	asmct			2	=	printf		*
*  3  	=      fprintf		4	=	branch		*
*  5	=	fopen			6	=	fclose		*
*  7	=	if			8	=	strcpy		*
*  9 	=	isalpha		*10	=	isdigit	*
*  11 =	isspace		12	=	isalnum	*
*  13 =	atoi			14	=	free		*
*  15 =	strcat			16	=	strlen		*
*  17 =	define	        	18	=	fgets		*
*  19 =	unsigned		20   	=	isupper	*
************************************************************** */

/* compiler generated fields usage counter			*/

int work_use_ct[110];

/* *************************************************************
*   1		=	C370ISAL	2	=	C370L1	       *
*   3 		=	C370L2		4	=	C370L3	       *
*   5 		=	C370L4		6	=	C370L5	       *
*   7		=	C370L6		8	=	C370L8A       *
*   9		=	C370L8		10	=	C370L80       *
*  11		=	C370MTOT	12	=	C370THR       *
*  13		=	C370FOUR     	14	=	C370MT3       *
*  15		=	C370MT4	16	=	C370MT5	*
*  17		=	C370PTOT	18	=	C370PT1	*
*  19		=	C370PT2	20	=	C370PT3	*
*  21		=	C370PT4	22	=	C370PT5	*
*  23  	=	C370CLCT	24	=      C370FIVE      *
*  25		=	C370EDW2	26	=	C370EDW3	*
*  27		=	C370EDW4	28	=	C370TDD2	*
*  29		=	C370PN2	30	=	C370PN3	*
*  31		=	C370DDW2     	32	= 	C370ZERO	*
*  33		=	C370ONE	34	=	C370TWO	*
*  35		=	C370UCA	36	=	C370UCZ	*
*  37		=	C370LCA	38	=	C370LCZ	*
*  39		=	C370MATH     	40	=	C370DEND	*
*  41		=	C370IENT	42	=	REMAINDER	*
*  43		=	C370ISOR	44	=	C370MLT1	*
*  45		=	C370MLT2	46	=	C370MLT3	*
*  47		=	C370D2DW    	48	=	C370U		*
*  49		=	C370NWK1	50	=	C370NWK2	*
*  51		=	C370EDN	52	=	C370B1 	*
*  53		=	C370B8		54	=	C370TDW2	*
*  55		=	C370TDW3	56	=	C370TDW4	*
*  57		=	C370N3		58	=	C370N5		*
*  59		=	C370L1A	60	=	C370TDD3     	*
*  61		=	C370D3DW     	62	=	C370LZER	*
*  63		=	C370LNIN	64	=	FW00XX004	*
*  65		=	C370NN3      	66	=	C370NN5      	*
*  67		=	C370DEC	68	=	C370TDW5     	*
*  69		= 	C370B10      	70	=	C370TDW7     	*
*  71 		=	C370L10	72	=	C370XXX	*
*  73		=	C370LPCT	74	=	C370EOF	*
*  75		=	C370PER	76	=	C370TDW9     	*
*  77		=	C370EDW5     	78	=	C370NWK3  	*
*  79		=	C370FONE	80	=      C370DIGT	*
*  81		=	C370COLN      82     =      C370NONE      *
*  83         =      C370EDW7      84     =      C370EDW9      *
*  85         =      C370DTTM	86	=	C370M001      *
*  89         =      C370M002      90     =      C370TUP       *
*  91         =      C370TLC                                   *
*  93		=	C370ECB	94	=	C370NWK4	*
*  95		=	C370NWK5	96	=	C370M003	*
*  97		=	C370M004	98	=	C370M005	*
*  99		=	C370QUOT	100	=	TSTUC		*
*  100		=	TSTLC		101	=	C370DDTE      *
*  102		=	C370DWRK					*
************************************************************* */

 int tot_localtime = 0;
 int tot_int = 0;
 int tot_char = 0;
 int tot_goto = 0;
 int tot_float = 0;
 int tot_arr = 1;
 int p_eol = 0;
 int p_ln_ct = 0;
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
 int p100 = 0;
 int p101 = 0;
 int p101d = 0;
 int p101s = 0;
 int p102 = 0;
 int p103 = 0;
 int p104 = 0;		/* toupper */

 int array_rows = 17; 				/* array row count			*/

/* used by if processing to detect end of if/else/while loop	*/
 int l_start[22];
 int l_type[22];
 int l_else[22];

 int if_level = 0;

char output_file[24];

 int array_clear = 0; 				/* flag to reset array address		*/
 int case_parm_ct = 0;
 int v_const = 0;
 int fld_ct = 0;           				/* field working count			*/
 int found_space = 0;       			/* used in field search			*/
 int found_space2 = 0;      			/* used in field search			*/
 int skip = 0;              			/* used in char routine			*/
 int inside_main = 0;       			/* work for main loop			*/
 int parm_ct = 0;           			/* count for } {				*/
 int end_asm = 0;           			/* flag for end of main processing		*/
 int bracket_ct = 0;        			/* used in c2_punch_2			*/
 int while_parser_code = 0; 			/* used by while parser			*/
 int fns_ct = 0;            			/* function_start table counter		*/
 int while_convert = 0;     			/* used in while to track processing	*/
 int print_array = 0;       			/* flag for array printing			*/
 int while_array = 0;       			/* flage for while array processing	*/

 int wif_ct = 0;
 int while_level = 0;
 int wh_ct = 0;

 int tot_sizeof = 0;
 int char_malloc = 0;
 int tot_malloc = 0;

 int left_parm = 0;
 int right_parm = 0;
 int op_code = 0;
 int equal_found = 0;

 int fclose_ct = 0;
 int buf_ct = 0;
 int function_ct = 0;  /*  can be removed */

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

 int switch_convert = 0;
 int switch_level = 0;
 int switch_ct = 0;

 int inside_for = 0;
 int for_opr = 0;
 int for_parm = 0;
 int console_flag = 0;
 int fprtf_flag = 0;
 int non_process = 0;
 int open_ct = 0;
 int end_input = 0;
 int use_atoi = 0;
 int use_mult = 0;
 int localtime_usect = 0;
 int loop_strcmp = 0;
 int i_ct = 0;
 int goto_label_ct = 0;
 int use_strchr = 0;
 int skip_read = 0;

struct defines 
{
  int d_rct;
  char d_name[VAR_LGTH];
  char d_value[VAR_LGTH];
};
struct defines *w_define;

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
  char gv_st_col[VAR_LGTH];
   int gv_flag;
   int gv_dec;
   int gv_id;
};
struct variables *gw_variable;

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
struct var *lw_variable;

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
struct files *w_file;

struct functions 
{
   int fn_rct;
  char fn_name[VAR_LGTH];
  char fn_cname[9];
  char fn_func[VAR_LGTH];
   int fn_start;
   int fn_return;
  char fn_loop[10];
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
  char fn_loop_use[12];
};
struct functions *w_function;

struct constant 
{
   int const_rct;
  char const_current[8];
  char const_use[8];
};
struct constant *w_constant;

struct include 
{
   int include_rct;
  char include_name[VAR_LGTH];
};
struct include *w_include;

struct if_table 
{
  int wif_rct;
  int wif_eof1;
  int wif_else1;
  int wif_eof2;
  int wif_level;
};
struct if_table *w_if_table;

struct while_table 
{
   int wh_rct;
   int wh_level;
   int wh_eof1;
  char wh_p_string[BUFSIZE];
};
struct while_table *w_while_table;

struct for_table 
{
   int for_rct;
   int for_level;
   int for_eof1;
  char for_rt_field[VAR_LGTH];
  char for_rt_field2[VAR_LGTH];
  char for_p_string[BUFSIZE];
};
struct for_table *w_for_table;

struct switch_table 
{
   int switch_rct;
   int switch_level;
   int switch_eof1;
  char switch_p_string[BUFSIZE];
};
struct switch_table *w_switch_table;

struct fclose_table 
{
  int cl_rct;
  int cl_buf_ct;
};
struct fclose_table *w_fclose_table;

struct func_start 
{
   int fns_rct;
  char fns_name[VAR_LGTH];
};
struct func_start *w_func_start;

struct charlit 
{ 
   int clit_rct;
  char clit_cname[VAR_LGTH];
  char clit_value[VAR_LGTH];
   int clit_lgth;
   int clit_type;
   int clit_uct;
};
struct charlit *w_charlit;

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
struct m_struc *w_struc;

struct carry 
{
   int carry_rct;
  char carry_name[VAR_LGTH];
  char carry_cname[VAR_LGTH];
   int carry_ct;
   int carry_lgth;
   int carry_use_ct;
  char carry_literal[150];
};
struct carry *w_carry;


struct goto_label 
{
   int goto_label_rct;
  char goto_org_lb[VAR_LGTH];
  char goto_label_1[VAR_LGTH];
};
struct goto_label *w_goto_label;


struct bad_rec 
{
   int bad_rct;
  char bad_string[BUFSIZE];
};
struct bad_rec *w_bad_rec;

/* ----- includes ---------------- */

#include "c2z_arth.c"
#include "c2z_atof.c"
#include "c2z_atoi.c"
#include "c2z_atol.c"
#include "c2z_break.c"
#include "c2z_case.c"
#include "c2z_char.c"
#include "c2z_const.c"
#include "c2z_ctime.c"
#include "c2z_debug.c"
#include "c2z_decr.c"
#include "c2z_define.c"
#include "c2z_double.c"
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
#include "c2z_internet.c"
#include "c2z_isalnum.c"
#include "c2z_isalpha.c"
#include "c2z_isdigit.c"
#include "c2z_isspace.c"
#include "c2z_isupper.c"
#include "c2z_localtime.c"
#include "c2z_long.c"
#include "c2z_main.c"
#include "c2z_malloc.c"
#include "c2z_math.c"
#include "c2z_math_func.c"
#include "c2z_mem.c"
#include "c2z_misc.c"
#include "c2z_parameter.c"
#include "c2z_pass_2.c"
#include "c2z_pass_3.c"
#include "c2z_print.c"
#include "c2z_realloc.c"
#include "c2z_return.c"
#include "c2z_scanf.c"
#include "c2z_sizeof.c"
#include "c2z_strcat.c"
#include "c2z_strchr.c"
#include "c2z_strcmp.c"
#include "c2z_strncmp.c"
#include "c2z_strcpy.c"
#include "c2z_strlen.c"
#include "c2z_strncpy.c"
#include "c2z_strrchr.c"
#include "c2z_strrev.c"
#include "c2z_strset.c"
#include "c2z_strstr.c"
#include "c2z_struct.c"
#include "c2z_time.c"
#include "c2z_u_short.c"
#include "c2z_unsigned.c"
#include "c2z_utility.c"
#include "c2z_while.c"

int main(int argc, char *argv[]) 
{
  char *p;
  char ch;
  char *p1;
  char *p2;
  char *p3;
  char *p4;
  char *p5;
  char *p6;
  char *p7;
  char *p8;
  char *p9;
  char *p10;
  char filename[VAR_LGTH];
  char asm_file_1[VAR_LGTH];
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
  int indx = 0;
  int mainflg = 0;
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
  int x40 = 0;
  int x42 = 0;
  int x43 = 0;
  int x44 = 0;
  int y0 = 0;
  int v1 = 0;
  int bk1 = 0;
  int bk2 = 0;
  int bk3 = 0;


  if (argc < 2) 
  {
    printf("\n ****** ERROR *******  NO INPUT FILE NAME ENTERED\n");
    exit(0);
  }

  if (argc > 2) 
  {
    p = strstr(argv[2], "-d");
    if (p) 
    {
      strcpy(tfield1, argv[2]);
      tfield1a[0] = tfield1[2];
      tfield1a[1] = '\0';
      debug_lv = atoi(tfield1a);
    }
  }

  for(s = 0; s < 110; s++)
  {
    work_use_ct[s] = 0;
  }
  
  traceflg = 1;
  puncde = 1;

  strcpy(wk_file, argv[1]);
  strcpy(pgm_name, wk_file);

  p = strstr(wk_file, "//");
  if (p) 
  {
    pi = 0;
    ch = wk_file[pi];
    while (ch != '/') 
    {
      pi++;
      ch = wk_file[pi];
    }
    pi2 = 0;
    s = strlen(wk_file);
    pi++;
    ch = wk_file[pi];
    while ((ch != ' ') && (pi < s)) 
    {
      pgm_name[pi2] = ch;
      pi2++;
      pi++;
      ch = wk_file[pi];
    }
    pgm_name[pi2] = '\0';

    strcpy(p_string, pgm_name);
    pi = 0;
    s = strlen(p_string);
    for (; pi < s; pi++) 
    {
      ch = p_string[pi];
      if ((ch >= 'a') && (ch <= 'z')) 
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
  if (!p) 
  {
    strcat(filename, ".c");
  }

  p = strstr(wk_file, ".c");
  if (p) 
  {
    pi = 0;
    s = strlen(wk_file);
    while (ch != '.') 
    {
      ch = wk_file[pi];
      asm_file[pi] = ch;
      pi++;
    }
    asm_file[pi] = '\0';
  }

  if (!p) 
  {
    strcpy(asm_file, wk_file);
  }

  z390 = 1;
  strcat(asm_file, ".MLC");
  strcpy(asm_file_1, asm_file);
  z390 = 1;
  
  printf("***********************************************\n");
  printf("*  c2z Starting Execution                     *\n");
  printf("*  Version 0.0.25 - 01/05/2022                *\n");
  printf("*  Copyright (C) TCCS 2015 - 2022             *\n");
  printf("*  c2z Z390 Pass 1 Started                    *\n");

  pgm = fopen(filename, "rb");
  if(pgm == NULL)
  {
    printf("\n\n***** ERROR *****  INPUT FILE NOT FOUND\n");
    exit(0);
  }
  c_tmp = fopen("tmp.c", "wb");

  strcpy(trcfile, wk_file);
  strcat(trcfile, ".TRC");
  c_src = fopen(trcfile, "w");

  i_ct = 0;
  rct = 0;
  while (1) 
  {
    fgets(p_string, BUFSIZE, pgm);
    rct++;

/* printf("c2z.c PASS 1 rct = %d p_string = %s",rct,p_string); */


    if (feof(pgm)) 
    {
      break;
    }

    p1 = strstr(p_string, "\"");
    ret = strncmp("#include", p_string, 8);
   
    if((ret == 0) && (p1)) 
    {
      pi = 0;
      ch = p_string[pi];
      while (ch != '"') 
      {
        pi++;
        ch = p_string[pi];
      }
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != '"') 
      {
        tfield1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield1[pi2] = '\0';

      y0 = 0;
      p8 = strstr(tfield1, ".h");
      if (p8) 
      {
        y0 = 1;
        c_h = fopen(tfield1, "r");
        while(fgets(p_string, BUFSIZE, c_h) != NULL) 
        {
          scan_func_name_1();
          fputs(p_string, c_tmp);
        }
        fclose(c_h);
      }

      if (y0 == 0) 
      {
        if (i_ct == 0) 
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
  if (i_ct > 0) 
  {
    for (I = 0; I < i_ct; I++) 
    {
      strcpy(tfield1, w_include[I].include_name);
      pgm = fopen(tfield1, "r");
      while (1) 
      {
        fgets(p_string, BUFSIZE, pgm);
/* printf("c2z.c Pass 1a p_string = %s",p_string); */
        rct++;
        if (feof(pgm)) 
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
    x40 = 0;
    x42 = 0;
    x43 = 0;
    p1 = strstr(p_string, "#include");

    if(p1)
    {
      y0 = 0;
      p8 = strstr(tfield1, ".h");
      if (p8) 
      {
        y0 = 1;
        c_h = fopen(tfield1, "r");
        while (fgets(p_string, BUFSIZE, c_h) != NULL) 
        {
          fputs(p_string, c_tmp);
        }
        fclose(c_h);
      }
    }

    if (!p1) 
    {
      pi = 0;
      ch = p_string[pi];
      while ((ch == ' ') || (ch == '\t')) 
      {
        pi++;
        ch = p_string[pi];
      }
      tfield1[0] = ch;
      pi++;
      ch = p_string[pi];
      tfield1[1] = ch;
      tfield1[2] = '\0';
      ret = strcmp(tfield1, "//"); 		/* // comment */
      if (ret == 0) 
      {
        x40 = 1;
      }
      ret = strcmp(tfield1, "/*"); 		/*  beginning of single comment line */
      if (ret == 0) 
      {
        x42 = 1;
        x44 = 1;
      }
      p10 = strstr(p_string, "*/"); 		/*  end of single comment line */
      if ((p10) && (x42 == 1)) 
      {
        x43 = 1;
        x44 = 0;
      }
      if ((x40 == 0) && (x42 == 0) && (x43 == 0) && (x44 != 1)) 
      {
        fputs(p_string, c_tmp);
      }
    }
  }
  fclose(pgm);
  fclose(c_tmp);
  rct = 0;
 
  printf("*  c2z Z390 Pass 2 Started                    *\n");

  pgm = fopen("srcformat.c", "r");

  rct = 0;
  strcpy(trace_2, "2");
  strcpy(trace_1, "c2z.c pass 2 start\n");

  while(!feof(pgm))
  {
    if(skip_read == 0)
    {
      if(fgets(p_string, 255,pgm) == NULL )
      {
         goto pass2_skip;
      }
     /* pgm = fgets(p_string, 266, pgm); */
      rct++;
    }

/*  printf("c2z Pass 2 rct = %d erct = %d p_string = %s\n",rct,erct,p_string); */ 
    convert = 0;
    fprtf_flag = 0;

    skip_read = 0;

    if (global_st == 0) 
    {
      sv_func[0] = '\0';
    }

    convert = 0;
    skip_read = 0;

    /* Scan for { }  */

    x = 0;
    x1 = 0;
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t')) 
    {
      pi++;
      ch = p_string[pi];
    }

    tfield1[0] = p_string[pi];
    tfield1[1] = '\0';

    ret = strcmp(tfield1, "{");
    if (ret == 0) 
    {
      x++;
    }

    ret = strcmp(tfield1, "}");
    if (ret == 0) 
    {
      x1++;
    }

    if ((x > 0) || (x1 > 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c Pass 2 { }");
        trace_rec_1();
      }
      c2_param_ct();
    }

    if(skip_read == 1)
    {
       goto pass2_skip;
    }

    /* ***************************************************************
    * Scan for MAIN in C program and set sv_funcTest for int or char *
    * ************************************************************** */
    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for Main\n", rct);
    }

    mainflg = 0;
    if (mainflg != 1) 
    {
      p8 = strstr(p_string, "int");
      s = p8 - p_string;
      p8 = strstr(p_string, "=");
      v = p8 - p_string;
      if (v < 0) 
      {
        v = 9999;
      }

      p = strstr(p_string, "main");
      p1 = strstr(p_string, "int");
      p2 = strstr(p_string, "_main");
      if ((p) && (p1) && (!p8) && (!p2)) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z.c pass 2 MAIN");
          trace_rec_1();
        }

        inside_main = 1;
        strcpy(sv_func, "main");
        c2_main();
        global_st = 1;
        mainflg = 1;
      }
    }


    /* ***************************************************************
    * Scan for malloc                                                *
    * ************************************************************** */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for malloc\n", rct);
    }

    p = strstr(p_string, "malloc");
    p1 = strstr(p_string, "#include");

    if ((p) && (!p1)) 
    {
      /* c2_scan_malloc(); */
      convert = 1;
    }


    /* ***************************************************************
    * Scan for realloc                                                *
    * ************************************************************** */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for realloc\n", rct);
    }

    p = strstr(p_string, "realloc");
    p1 = strstr(p_string, "#include");

    if ((p) && (!p1))
    {
      /* c2_scan_realloc();  */
      convert = 1;
    }



    /* ***************************************************************
     *  Scan for bind                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for bind\n", rct);
    }

    p = strstr(p_string, "bind");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 bind");
        trace_rec_1();
      }

      /* c2_bind();   */
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for listen                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for listen\n", rct);
    }

    p = strstr(p_string, "listen");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 listen");
        trace_rec_1();
      }

      /* c2_listen();   */
      convert = 1;
    }


    /* ***************************************************************
    * Scan for struct                                                *
    * ************************************************************** */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for struct\n", rct);
    }

    p = strstr(p_string, "struct");
    p1 = strstr(p_string, "_struct");
    p2 = strstr(p_string, "accept");
    p3 = strstr(p_string, ";");

    if ((p) && (!p1) && (!p2) && (!p3)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 struct #1");
        trace_rec_1();
      }
      c2z_struct();
      convert = 1;
    }

    if ((p) && (!p1) && (!p2) && (p3)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 struct #2");
        trace_rec_1();
      }
      c2_struct_4();     
      convert = 1;
    }


    /* ***************************************************************
    * Scan for prototypes                                            *
    * ************************************************************** */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for prototypes\n", rct);
    }

    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    x1 = 0;
    ret = strcmp(tfield1, "char");
    if (ret == 0) 
    {
      x1 = 1;
    }

    ret = strcmp(tfield1, "int");
    if (ret == 0) 
    {
      x1 = 2;
    }

    ret = strcmp(tfield1, "void");
    if (ret == 0) 
    {
      x1 = 3;
    }

    ret = strcmp(tfield1, "double");
    if (ret == 0) 
    {
      x1 = 4;
    }

    ret = strcmp(tfield1, "long");
    if (ret == 0) 
    {
      x1 = 5;
    }

    p1 = strstr(p_string, ";");
    p2 = strstr(p_string, "(void)");
    p3 = strstr(p_string, "[");
    p4 = strstr(p_string, "]");
    p5 = strstr(p_string, "(");
    p6 = strstr(p_string, ")");
    p7 = strstr(p_string, "printf");
    p8 = strstr(p_string, "=");

    if ((x1 == 1) && (p1) && (!p3) && (!p4) && (p5) && (p6) && (!p7) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 prototype (char) #101");
        trace_rec_1();
      }
      scan_func_name_1();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 2) && (p1) && (p5) && (p6) && (!p8) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 prototype (int) #102");
        trace_rec_1();
      }
      scan_func_name_1();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 3) && (p1) && (p5) && (p6) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 prototype (void) #103");
        trace_rec_1();
      }
      scan_func_name_1();
      convert = 1;
    }

    if (convert == 1)
      goto pass2_skip;

    if ((x1 == 4) && (p1) && (p5) && (p6) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 prototype (double) #104");
        trace_rec_1();
      }
      scan_func_name_1();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 5) && (p1) && (p5) && (p6)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 prototype (long) #105");
        trace_rec_1();
      }
      scan_func_name_1();
      convert = 1;
    }


    /* ***************************************************************
    * Scan for subroutines                                           *
    * ************************************************************** */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for subroutines\n", rct);
    }

    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    x1 = 0;
    ret = strcmp(tfield1, "char");
    if (ret == 0) 
    {
      x1 = 1;
    }

    ret = strcmp(tfield1, "int");
    if (ret == 0) 
    {
      x1 = 2;
    }

    ret = strcmp(tfield1, "void");
    if (ret == 0) 
    {
      x1 = 3;
    }

    ret = strcmp(tfield1, "double");
    if (ret == 0) 
    {
      x1 = 4;
    }

    ret = strcmp(tfield1, "long");
    if (ret == 0) 
    {
      x1 = 5;
    }

    p1 = strstr(p_string, ";");
    p3 = strstr(p_string, "[");
    p4 = strstr(p_string, "]");
    p5 = strstr(p_string, "(");
    p6 = strstr(p_string, ")");
    p7 = strstr(p_string, "printf");

    if ((x1 == 1) && (!p1) && (!p3) && (!p4) && (p5) && (p6) && (!p7) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 subroutine #200");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_int_3 #201\n", rct);
      }

      c2_int_3();
      convert = 1;
    }

    if (convert == 1)
      goto pass2_skip;

    if ((x1 == 2) && (!p1) && (p5) && (p6) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 subroutine #202");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_int_3 #202\n", rct);
      }

      c2_int_3();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 3) && (!p1) && (p5) && (p6) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 subroutine #203");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_int_3 #203\n", rct);
      }

      c2_int_3();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 4) && (!p1) && (p5) && (p6) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 subroutine #204");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_int_3 #204\n", rct);
      }

      c2_int_3();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 5) && (!p1) && (p5) && (p6)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 subroutine #205");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_int_3 #205\n", rct);
      }

      c2_int_3();
      convert = 1;
    }


    /* ***************************************************************
    * Scan for INT (NOT MAIN)                                        *
    * ************************************************************** */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for int (not MAIN)\n", rct);
    }

    s = strlen(p_string);
    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    for (I = 0; I < 3; I++) 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    ret = strcmp(tfield1, "sta");
    if (ret == 0) 
    {
      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      for (I = 0; I < 3; I++) 
      {
        tfield1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield1[pi2] = '\0';
    }

    ret = strcmp(tfield1, "int");
    if (ret == 0) 
    {
      p6 = strstr(p_string, ".");
      if (!p6) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z.c scan char c2_int START");
          trace_rec_1();
        }

        if (debug_lv >= 2) 
        {
          printf("c2z.c Pass 2 rct = %d c2_int #100\n", rct);
        }

        c2_int();
        convert = 1;
      }
    }

    ret = strcmp(tfield1, "cha");
    if (ret == 0) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c scan char c2_char START");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_char #100\n", rct);
      }

      c2_char();
      convert = 1;
    }


    /* ***************************************************************
    * Scan for size_t                                                *
    * ************************************************************** */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for size_t\n", rct);
    }

    p = strstr(p_string, "size_t");
    if(p)
    {

      convert = 1;
    }


    /* ***************************************************************
    * Scan for time_t                                                *
    * ************************************************************** */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for time_t\n",rct);
    }

    p = strstr(p_string, "time_t");
    if (p) 
    {
      if (debug_lv >= 2)  
      {
        printf("c2z.c Pass 2 rct = %d c2_time_t #100\n", rct);
      }

      c2_time_t();
      convert = 1;
    }


    /* ***************************************************************
    * Scan for u_short                                               *
    * ************************************************************** */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for u_short\n", rct);
    }

    p = strstr(p_string, "u_short");
    if(p)
    {
      c2_u_short();
      convert = 1;
    }


    /* ***************************************************************
    * Scan for while                                                 *
    * ************************************************************** */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for while\n", rct);
    }

    while_convert = 0;

    p = strstr(p_string, "while");
    p1 = strstr(p_string, "\"while");
    if ((p) && (!p1)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 while");
        trace_rec_1();
      }

      if(l_start[1] == 0)
      {
        l_start[1] = rct;
        l_type[1] = 2;
        while_convert = 1;
        while_level = 1;
        goto skip_loop_77;
      }

      if(l_start[2] == 0)
      {
        l_start[2] = rct;
        l_type[2] = 2;
        while_convert = 1;
        while_level = 2;
        goto skip_loop_77;
      }

      if(l_start[3] == 0)
      {
        l_start[3] = rct;
        l_type[3] = 2;
        while_convert = 1;
        while_level = 3;
        goto skip_loop_77;
      }

      if(l_start[4] == 0)
      {
        l_start[4] = rct;
        l_type[4] = 2;
        while_convert = 1;
        while_level = 4;
        goto skip_loop_77;
      }

      if(l_start[5] == 0)
      {
        l_start[5] = rct;
        l_type[5] = 2;
        while_convert = 1;
        while_level = 5;
        goto skip_loop_77;
      }

      if(l_start[6] == 0)
      {
        l_start[6] = rct;
        l_type[6] = 2;
        while_convert = 1;
        while_level = 6;
        goto skip_loop_77;
      }

      if(l_start[7] == 0)
      {
        l_start[7] = rct;
        l_type[7] = 2;
        while_convert = 1;
        while_level = 7;
        goto skip_loop_77;
      }

      if(l_start[8] == 0)
      {
        l_start[8] = rct;
        l_type[8] = 2;
        while_convert = 1;
        while_level = 8;
        goto skip_loop_77;
      }

      if(l_start[9] == 0)
      {
        l_start[9] = rct;
        l_type[9] = 2;
        while_convert = 1;
        while_level = 9;
        goto skip_loop_77;
      }

     if(l_start[10] == 0)
      {
        l_start[10] = rct;
        l_type[10] = 2;
        while_convert = 1;
        while_level = 10;
        goto skip_loop_77;
      }

      if(l_start[11] == 0)
      {
        l_start[11] = rct;
        l_type[11] = 2;
        while_convert = 1;
        while_level = 11;
        goto skip_loop_77;
      }

      if(l_start[12] == 0)
      {
        l_start[12] = rct;
        l_type[12] = 2;
        while_convert = 1;
        while_level = 12;
        goto skip_loop_77;
      }

      if(l_start[13] == 0)
      {
        l_start[13] = rct;
        l_type[13] = 2;
        while_convert = 1;
        while_level = 13;
        goto skip_loop_77;
      }

      if(l_start[14] == 0)
      {
        l_start[14] = rct;
        l_type[14] = 2;
        while_convert = 1;
        while_level = 14;
        goto skip_loop_77;
      }

      if(l_start[15] == 0)
      {
        l_start[15] = rct;
        l_type[15] = 2;
        while_convert = 1;
        while_level = 15;
        goto skip_loop_77;
      }

      if(l_start[16] == 0)
      {
        l_start[16] = rct;
        l_type[16] = 2;
        while_convert = 1;
        while_level = 16;
        goto skip_loop_77;
      }

      if(l_start[17] == 0)
      {
        l_start[17] = rct;
        l_type[17] = 2;
        while_convert = 1;
        while_level = 17;
        goto skip_loop_77;
      }

      if(l_start[18] == 0)
      {
        l_start[18] = rct;
        l_type[18] = 2;
        while_convert = 1;
        while_level = 18;
        goto skip_loop_77;
      }

      if(l_start[19] == 0)
      {
        l_start[19] = rct;
        l_type[19] = 2;
        while_convert = 1;
        while_level = 19;
        goto skip_loop_77;
      }

     if(l_start[20] == 0)
      {
        l_start[20] = rct;
        l_type[20] = 2;
        while_convert = 1;
        while_level = 20;
        goto skip_loop_77;
      }

   skip_loop_77:

      if (while_convert == 1) 
      {
        if (wh_ct == 0) 
        {
          size = 1;
          w_while_table = malloc(size * (sizeof(struct while_table)));
        } 
        else 
        {
          size = wh_ct + 1;
          w_while_table = realloc(w_while_table, (size * sizeof(struct while_table)));
        }

        w_while_table[wh_ct].wh_rct = rct;
        w_while_table[wh_ct].wh_level = while_level;
        w_while_table[wh_ct].wh_eof1 = 0;
        strcpy(w_while_table[wh_ct].wh_p_string, p_string);
        wh_ct++;
      }
      convert = 1;

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_pass2_while #100\n", rct);
      }

      c2_pass2_while();
    }

    /* ***************************************************************
    * Scan for switch                                                *
    * ************************************************************** */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for switch\n", rct);
    }

    switch_convert = 0;

    p = strstr(p_string, "switch");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 switch");
        trace_rec_1();
      }

      if(l_start[1] == 0)
      {
        l_start[1] = rct;
        l_type[1] = 4;
        switch_convert = 1;
        switch_level = 1;
        goto skip_switch_77;
      }

      if(l_start[2] == 0)
      {
        l_start[2] = rct;
        l_type[2] = 4;
        switch_convert = 1;
        switch_level = 2;
        goto skip_switch_77;
      }

      if(l_start[3] == 0)
      {
        l_start[3] = rct;
        l_type[3] = 4;
        switch_convert = 1;
        switch_level = 3;
        goto skip_switch_77;
      }

      if(l_start[4] == 0)
      {
        l_start[4] = rct;
        l_type[4] = 4;
        switch_convert = 1;
        switch_level = 4;
        goto skip_switch_77;
      }

      if(l_start[5] == 0)
      {
        l_start[5] = rct;
        l_type[5] = 4;
        switch_convert = 1;
        switch_level = 5;
        goto skip_switch_77;
      }

      if(l_start[6] == 0)
      {
        l_start[6] = rct;
        l_type[6] = 4;
        switch_convert = 1;
        switch_level = 6;
        goto skip_switch_77;
      }

      if(l_start[7] == 0)
      {
        l_start[7] = rct;
        l_type[7] = 4;
        switch_convert = 1;
        switch_level = 7;
        goto skip_switch_77;
      }

      if(l_start[8] == 0)
      {
        l_start[8] = rct;
        l_type[8] = 4;
        switch_convert = 1;
        switch_level = 8;
        goto skip_switch_77;
      }

      if(l_start[9] == 0)
      {
        l_start[9] = rct;
        l_type[9] = 4;
        switch_convert = 1;
        switch_level = 9;
        goto skip_switch_77;
      }

     if(l_start[10] == 0)
      {
        l_start[10] = rct;
        l_type[10] = 4;
        switch_convert = 1;
        switch_level = 10;
        goto skip_switch_77;
      }

      if(l_start[11] == 0)
      {
        l_start[11] = rct;
        l_type[11] = 4;
        switch_convert = 1;
        switch_level = 11;
        goto skip_switch_77;
      }

      if(l_start[12] == 0)
      {
        l_start[12] = rct;
        l_type[12] = 4;
        switch_convert = 1;
        switch_level = 12;
        goto skip_switch_77;
      }

      if(l_start[13] == 0)
      {
        l_start[13] = rct;
        l_type[13] = 4;
        switch_convert = 1;
        switch_level = 13;
        goto skip_switch_77;
      }

      if(l_start[14] == 0)
      {
        l_start[14] = rct;
        l_type[14] = 4;
        switch_convert = 1;
        switch_level = 14;
        goto skip_switch_77;
      }

      if(l_start[15] == 0)
      {
        l_start[15] = rct;
        l_type[15] = 4;
        switch_convert = 1;
        switch_level = 15;
        goto skip_switch_77;
      }

      if(l_start[16] == 0)
      {
        l_start[16] = rct;
        l_type[16] = 4;
        switch_convert = 1;
        switch_level = 16;
        goto skip_switch_77;
      }

      if(l_start[17] == 0)
      {
        l_start[17] = rct;
        l_type[17] = 4;
        switch_convert = 1;
        switch_level = 17;
        goto skip_switch_77;
      }

      if(l_start[18] == 0)
      {
        l_start[18] = rct;
        l_type[18] = 4;
        switch_convert = 1;
        switch_level = 18;
        goto skip_switch_77;
      }

      if(l_start[19] == 0)
      {
        l_start[19] = rct;
        l_type[19] = 4;
        switch_convert = 1;
        switch_level = 19;
        goto skip_switch_77;
      }

     if(l_start[20] == 0)
      {
        l_start[20] = rct;
        l_type[20] = 4;
        switch_convert = 1;
        switch_level = 20;
        goto skip_switch_77;
      }

   skip_switch_77:

      if (switch_convert == 1) 
      {
        if (switch_ct == 0) 
        {
          size = 1;
          w_switch_table = malloc(size * (sizeof(struct switch_table)));
        } 
        else 
        {
          size = switch_ct + 1;
          w_switch_table = realloc(w_switch_table, (size * sizeof(struct switch_table)));
        }

        w_switch_table[switch_ct].switch_rct = rct;
        w_switch_table[switch_ct].switch_level = switch_level;
        w_switch_table[switch_ct].switch_eof1 = 0;
        strcpy(w_switch_table[switch_ct].switch_p_string, p_string);
        switch_ct++;
      }
      convert = 1;

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_pass2_switch #100\n", rct);
      }
    }


    /* ***************************************************************
     * Scan for sprintf                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for sprintf\n", rct);
    }

    p = strstr(p_string, "sprintf");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 sprintf");
        trace_rec_1();
      }
      convert = 1;
    }



    /* ***************************************************************
     * Scan for fprintf                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for fprintf\n", rct);
    }

    p = strstr(p_string, "fprintf");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 fprintf");
        trace_rec_1();
      }

      s = strlen(p_string);
      pi = 0;
      pi2 = 0;
      strstart = 0;
      strstop = 0;
      strflag = 0;

      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      underline = 0;
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ',') 
      {
        if (ch == '_') 
        {
          underline = 1;
        }
        a_string[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      a_string[pi2] = '\0';

      if ((pi2 > 8) || (underline == 1)) 
      {
        if (f_ct > 0) 
        {
          for (I = 0; I < f_ct; I++) 
          {
            ret = strcmp(a_string, w_file[I].f_name);
            if (ret == 0) 
            {
              strcpy(a_string, w_file[I].f_cname);
              strcpy(w_file[I].f_type, "P");
            }
          }
        }
      }

      while (pi <= s) 
      {
        ch = p_string[pi];
        if (ch == '\"') 
        {
          if (strflag == 1) 
          {
            strstop = pi;
          }

          if (strflag == 0) 
          {
            strstart = pi; 			/* start of string */
            strflag = 1;
          }
        }
        pi++;
      }

/* copy from strstart to strstop into storage  */

      s = 0;
      x4 = 0;
      x2 = 0;
      if ((strstart > 0) & (strstop > 0)) 
      {
        strstart++;
        for (indx = strstart; indx < strstop; indx++) 
        {
          ch = p_string[indx];
          if (ch == '%') 
          {
            indx++;
            x2 = 1;
          }

          if ((ch != '\\') && (x2 == 0)) 
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

/* Optimize LXX table  */

      x3 = 0;
      if (gv_ct != 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          x2 = 0;
          ret = strcmp(gw_variable[I].gv_type, "L");
          if (ret == 0) 
          {
            strcpy(a_string, gw_variable[I].gv_literal);
            x = strcmp(a_string, strtmp);
            x3++;
            if (x == 0) 
            {
              strcpy(tfield1, gw_variable[I].gv_name);
              if (v_const == 0) 
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

        if (x2 != 1) 			
        {
          if (v_const == 0) 
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


/* update the struct with literal  */

      if (gv_ct == 0) 
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
      gw_variable[gv_ct].gv_current_lgth = x4;
      strcpy(gw_variable[gv_ct].gv_literal, strtmp);
      gw_variable[gv_ct].gv_dec = 0;
      gv_ct++;

      fprtf_flag = 1;
      convert = 1;
    }


    /* ***************************************************************
    *  Scan for printf                                               *
    * ************************************************************** */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for printf\n", rct);
    }

    x3 = 0;
    p = strstr(p_string, "printf");
    if (p) 
    {
      if (traceflg == 1) 
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
      while (pi <= y0) 
      {
        ch = p_string[pi];
        if (ch == '\"') 
        {
          if (strflag == 1) 
          {
            strstop = pi;
          }
          if (strflag == 0) 
          {
            strstart = pi;
            strflag = 1;
          }
        }
        pi++;
      }

/* copy from strstart to strstop into storage  */

      y0 = 0;
      x4 = 0;
      if ((strstart > 0) & (strstop > 0)) 
      {
        strstart++;
        for (indx = strstart; indx < strstop; indx++) 
        {
          ch = p_string[indx];
          if ((ch == '\\') || (ch == '%')) 
          {
            indx++;
            break;
          } 
          else 
          {
            if (ch != '(') 
            {
              strtmp[y0] = ch;
              y0++;
            }
            x4++;
          }
        }
        strtmp[y0] = '\0';
      }

      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c printf-strtmp");
        trace_rec_1();
      }

      y0 = 0;

/* Optimize LXX table  */

      x3 = 0;
      x1 = 0;
      x = 0;

      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          x2 = 0;
          ret = strcmp(gw_variable[I].gv_type, "L");
          if (ret == 0) 
          {
            strcpy(a_string, gw_variable[I].gv_literal);
            x = strcmp(a_string, strtmp);
            x3++;
            if (x == 0) 
            {
              x1 = 1;
              strcpy(tfield1, gw_variable[I].gv_name);
              if (v_const == 0) 
              {
                size = 1;
                w_constant = malloc(size * sizeof(struct constant));
              } 
              else 
              {
                size = v_const + 1;
                w_constant =
                    realloc(w_constant, size * sizeof(struct constant));
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

        if (x1 == 0) 		
        {
          if (v_const == 0) 
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

      if (gv_ct == 0) 
      {
        if (v_const == 0) 
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

        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z.c pass2 scan printf-strtmp #1");
          trace_rec_1();
        }
      }

/* update the struct with literal  */

      x1 = strlen(strtmp);

      if (x2 != 1) 
      {
        if (gv_ct == 0) 
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
        gw_variable[gv_ct].gv_current_lgth = x1;
        gw_variable[gv_ct].gv_dec = 0;
        gw_variable[gv_ct].gv_id = 5;
        gv_ct++;
        strcpy(strtmp, null_field);
      }

      convert = 1;
      y0 = strlen(p_string);
      strstop++;
      ch = p_string[strstop];
      if (ch == ',') 
      {
        x = 0;
        pi2 = 0;
        strstop++;
        ch = p_string[strstop];
        while (ch != ';') 
        {
          if (isdigit(ch)) 
          {
            pi2++;
            x = 1;
          }
          strstop++;
          ch = p_string[strstop];
        }
      }
    }


    /* ***************************************************************
     *  Scan for free                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for free\n", rct);
    }

    p = strstr(p_string, "free");
    if (p) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan free");
        trace_rec_1();
      }
    }


    /* ***************************************************************
     *  Scan for #define                                             *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for #define\n", rct);
    }

    p = strstr(p_string, "#define");
    if (p) 
    {
      if (def_it == 1) 
      {
        if (debug_lv >= 2) 
        {
          printf("c2z.c Pass 2 rct = %d c2_define #100\n", rct);
        }

        c2_define();
      }
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for #ifndef                                             *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for #ifndef\n", rct);
    }

    p = strstr(p_string, "#ifndef");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 #ifndef");
        trace_rec_1();
      }
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_ifndef #100\n", rct);
      }

      c2_ifndef();
      convert = 1;
    }

/* Scan for #endif  */

    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for #endif\n", rct);
    }

    p = strstr(p_string, "#endif");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 #endif");
        trace_rec_1();
      }
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_endif #100\n", rct);
      }

      c2_endif();
      convert = 1;
    }

/* Scan for user VOID FUNCTION code  */

    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for Void Function\n", rct);
    }

    s = strlen(p_string);
    if (s < 5) 
    {
      goto vf_convert;
    }

    int v_convert = 0;
    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    s = strlen(p_string);
    s--;

    if ((s == pi) || ((pi + 1) == s)) 
    {
      goto pass2_skip;
    }

    for (I = 0; I < s; I++) 
    {
      if (ch != ' ') 
      {
        if (ch != ';') 
        {
          tfield1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
        if (ch == '(')
        {
          break;
        }
        if (ch == ';')
        {
          break;
        }
      }
    }
    tfield1[pi2] = '\0';

    p8 = strstr(p_string, ";");
    v = p8 - p_string;
    if (v < 0) 
    {
      v = 9999;
    }

    p = strstr(p_string, "=");
    s = p - p_string;
    if (s < 0) 
    {
      s = 9999;
    }


    if ((p) && (s < v))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "#define");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "#ifndef");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "#endif");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "#include");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "++");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "--");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "accept");
    if ((p)  && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "atol");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "bind");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "bool");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "break");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "case");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "char");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "clock");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "const");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "cos");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "ctime");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "default");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "double");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "else");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "enum");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "exit");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "fclose");
    p1 = strstr(p_string, "_fclose");
    if ((p) && (!p1) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "fflush");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "fgetc");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "fgets");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "float");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "fopen");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "for");
    p1 = strstr(p_string, "_for");
    if ((p) && (!p1) && (v_convert == 0))
    {
      v_convert = 1;
    }

    s = strcmp(tfield1, "for");
    if ((s == 0) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "fprintf");
    if ((s == 0) && (v_convert == 0))
    {
      v_convert = 1;
    }

    s = strcmp(tfield1, "getchar");
    if ((s == 0) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "gets");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "goto");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p1 = strstr(p_string, "_if");
    p = strstr(p_string, "if");
    if ((p) && (!p1) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "int");
    p1 = strstr(p_string, "print");
    p2 = strstr(p_string, "fprintf");  
    p3 = strstr(p_string, "_int"); 
    if ((p) && (!p1) && (!p2) && (!p3) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "listen");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "localtime");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "long");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "pid_t");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "pow");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "sprintf");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "print");
    p1 = strstr(p_string, "_print");
    if ((p) && (!p1) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "pthread_create");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "rand");
    p1 = strstr(p_string, "_rand");
    if ((p) && (!p1) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "realloc");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "remove");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "scanf");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "send");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "size_t");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "sizeof");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "sin");
    if ((p) && (v_convert == 0))
    {
       v_convert = 1;
    }

    p = strstr(p_string, "sqrt");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "strcat");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "strchr");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "strcmp");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "strncmp");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "strcpy");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "strlen");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "strncpy");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "strrchr");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "strrev");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "strset");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "strstr");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "struct");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "switch");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "return");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "tan");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "time_t");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "toupper");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "unsigned");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "u_short");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "while");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "FILE");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    /* test for goto label */
    x = 0;
    s = strlen(p_string);
    for(x = 0; x < s; x++)
    {
      if(p_string[x] == ':')
      {
        v_convert = 1;
      }
    }

    if (v_convert == 0) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d L2 c2_scan_sub #100\n", rct);
      }
      c2_scan_sub();
    }

  vf_convert:


/* Scan for for   */

    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for for\n", rct);
    }

    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      if (ch != ';') 
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
      if (ch == '(')
      {
        break;
      }
      if (ch == ';')
      {
        break;
      }
    }
    tfield1[pi2] = '\0';

    s = strcmp(tfield1, "for");
    if (s == 0) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_pass2_for #100\n", rct);
      }

      for_convert = 0;
      if(l_start[1] == 0)
      {
        l_start[1] = rct;
        l_type[1] = 3;
        for_convert = 1;
        for_level = 1;
        goto skip_for_77;
      }

      if(l_start[2] == 0)
      {
        l_start[2] = rct;
        l_type[2] = 3;
        for_convert = 1;
        for_level = 2;
        goto skip_for_77;
      }

      if(l_start[3] == 0)
      {
        l_start[3] = rct;
        l_type[3] = 3;
        for_convert = 1;
        for_level = 3;
        goto skip_for_77;
      }

      if(l_start[4] == 0)
      {
        l_start[4] = rct;
        l_type[4] = 3;
        for_convert = 1;
        for_level = 4;
        goto skip_for_77;
      }

      if(l_start[5] == 0)
      {
        l_start[5] = rct;
        l_type[5] = 3;
        for_convert = 1;
        for_level = 5;
        goto skip_for_77;
      }

      if(l_start[6] == 0)
      {
        l_start[6] = rct;
        l_type[6] = 3;
        for_convert = 1;
        for_level = 6;
        goto skip_for_77;
      }

      if(l_start[7] == 0)
      {
        l_start[7] = rct;
        l_type[7] = 3;
        for_convert = 1;
        for_level = 7;
        goto skip_for_77;
      }

      if(l_start[8] == 0)
      {
        l_start[8] = rct;
        l_type[8] = 3;
        for_convert = 1;
        for_level = 8;
        goto skip_for_77;
      }


      if(l_start[9] == 0)
      {
        l_start[9] = rct;
        l_type[9] = 3;
        for_convert = 1;
        for_level = 9;
        goto skip_for_77;
      }

      if(l_start[10] == 0)
      {
        l_start[10] = rct;
        l_type[10] = 3;
        for_convert = 1;
        for_level = 10;
        goto skip_for_77;
      }

      if(l_start[11] == 0)
      {
        l_start[11] = rct;
        l_type[11] = 3;
        for_convert = 1;
        for_level = 11;
        goto skip_for_77;
      }

      if(l_start[12] == 0)
      {
        l_start[12] = rct;
        l_type[12] = 3;
        for_convert = 1;
        for_level = 12;
        goto skip_for_77;
      }

      if(l_start[13] == 0)
      {
        l_start[13] = rct;
        l_type[13] = 3;
        for_convert = 1;
        for_level = 13;
        goto skip_for_77;
      }

      if(l_start[14] == 0)
      {
        l_start[14] = rct;
        l_type[14] = 3;
        for_convert = 1;
        for_level = 14;
        goto skip_for_77;
      }

      if(l_start[15] == 0)
      {
        l_start[15] = rct;
        l_type[15] = 3;
        for_convert = 1;
        for_level = 15;
        goto skip_for_77;
      }

      if(l_start[16] == 0)
      {
        l_start[16] = rct;
        l_type[16] = 3;
        for_convert = 1;
        for_level = 16;
        goto skip_for_77;
      }

      if(l_start[17] == 0)
      {
        l_start[17] = rct;
        l_type[17] = 3;
        for_convert = 1;
        for_level = 17;
        goto skip_for_77;
      }

      if(l_start[18] == 0)
      {
        l_start[18] = rct;
        l_type[18] = 3;
        for_convert = 1;
        for_level = 18;
        goto skip_for_77;
      }

      if(l_start[19] == 0)
      {
        l_start[19] = rct;
        l_type[19] = 3;
        for_convert = 1;
        for_level = 19;
        goto skip_for_77;
      }

      if(l_start[20] == 0)
      {
        l_start[20] = rct;
        l_type[20] = 3;
        for_convert = 1;
        for_level = 20;
        goto skip_for_77;
      }

    skip_for_77:

      if (for_convert == 1) 
      {
        if (for_ct == 0) 
        {
          size = 1;
          w_for_table = malloc(size * (sizeof(struct for_table)));
        } 
        else 
        {
          size = for_ct + 1;
          w_for_table = realloc(w_for_table, (size * sizeof(struct for_table)));
        }

        w_for_table[for_ct].for_rct = rct;
        w_for_table[for_ct].for_level = for_level;
        w_for_table[for_ct].for_eof1 = 0;
        strcpy(w_for_table[for_ct].for_p_string, p_string);
        for_ct++;
      }

      c2_pass2_for();
      convert = 1;
    }

/* Scan for fflush  */

    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for fflush\n", rct);
    }

    p8 = strstr(p_string, "fflush");
    if(p8)
    {
      convert = 1;
    }


/*  Scan for if  */

    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for if\n", rct);
    }

    p8 = strstr(p_string, "if");
    if(p8)
    {
      p = strstr(p_string, "(");
      if(!p)
      {
        convert = 1;
        goto pass2_skip;
      }
    }

    p8 = strstr(p_string, "if");
    s = p8 - p_string;
    p8 = strstr(p_string, "/*");
    v = p8 - p_string;

    if (v < 0) 
    {
      v = 9999;
    }

    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    tfield1[0] = ch;
    pi++;
    ch = p_string[pi];
    tfield1[1] = ch;
    tfield1[2] = '\0';

    x1 = strcmp(tfield1, "el");
    x2 = strcmp(tfield1, "if");
    if ((x1 == 0) && (x2 != 0)) 
    {
      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }
      pi++;
      ch = p_string[pi];
      tfield1[0] = ch;
      pi++;
      ch = p_string[pi];
      tfield1[1] = ch;
      tfield1[2] = '\0';
      x2 = strcmp(tfield1, "if");
    }

    if (x2 == 0) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan IF");
        trace_rec_1();
      }

      if(l_start[1] == 0)
      {
        l_start[1] = rct;
        l_type[1] = 1;
        if_level = 1;
        goto if_loop_66;
      }

      if(l_start[2] == 0)
      {
        l_start[2] = rct;
        l_type[2] = 1;
        if_level = 2;
        goto if_loop_66;
      }

      if(l_start[3] == 0)
      {
        l_start[3] = rct;
        l_type[3] = 1;
        if_level = 3;
        goto if_loop_66;
      }

      if(l_start[4] == 0)
      {
        l_start[4] = rct;
        l_type[4] = 1;
        if_level = 4;
        goto if_loop_66;
      }

      if(l_start[5] == 0)
      {
        l_start[5] = rct;
        l_type[5] = 1;
        if_level = 5;
        goto if_loop_66;
      }

      if(l_start[6] == 0)
      {
        l_start[6] = rct;
        l_type[6] = 1;
        if_level = 6;
        goto if_loop_66;
      }

      if(l_start[7] == 0)
      {
        l_start[7] = rct;
        l_type[7] = 1;
        if_level = 7;
        goto if_loop_66;
      }

      if(l_start[8] == 0)
      {
        l_start[8] = rct;
        l_type[8] = 1;
        if_level = 8;
        goto if_loop_66;
      }

      if(l_start[9] == 0)
      {
        l_start[9] = rct;
        l_type[9] = 1;
        if_level = 9;
        goto if_loop_66;
      }

      if(l_start[10] == 0)
      {
        l_start[10] = rct;
        l_type[10] = 1;
        if_level = 10;
        goto if_loop_66;
      }

      if(l_start[11] == 0)
      {
        l_start[11] = rct;
        l_type[11] = 1;
        if_level = 11;
        goto if_loop_66;
      }

      if(l_start[12] == 0)
      {
        l_start[12] = rct;
        l_type[12] = 1;
        if_level = 12;
        goto if_loop_66;
      }

      if(l_start[13] == 0)
      {
        l_start[13] = rct;
        l_type[13] = 1;
        if_level = 13;
        goto if_loop_66;
      }

      if(l_start[14] == 0)
      {
        l_start[14] = rct;
        l_type[14] = 1;
        if_level = 14;
        goto if_loop_66;
      }

      if(l_start[15] == 0)
      {
        l_start[15] = rct;
        l_type[15] = 1;
        if_level = 15;
        goto if_loop_66;
      }

      if(l_start[16] == 0)
      {
        l_start[16] = rct;
        l_type[16] = 1;
        if_level = 16;
        goto if_loop_66;
      }

      if(l_start[17] == 0)
      {
        l_start[17] = rct;
        l_type[17] = 1;
        if_level = 17;
        goto if_loop_66;
      }

      if(l_start[18] == 0)
      {
        l_start[18] = rct;
        l_type[18] = 1;
        if_level = 18;
        goto if_loop_66;
      }

      if(l_start[19] == 0)
      {
        l_start[19] = rct;
        l_type[19] = 1;
        if_level = 19;
        goto if_loop_66;
      }

      if(l_start[20] == 0)
      {
        l_start[20] = rct;
        l_type[20] = 1;
        if_level = 20;
        goto if_loop_66;
      }

   if_loop_66:

      if (wif_ct == 0) 
      {
        size = 1;
        w_if_table = malloc(size * sizeof(struct if_table));
      }
      else 
      {
        size = (wif_ct + 1);
        w_if_table = realloc(w_if_table, (size * sizeof(struct if_table)));
      }

      w_if_table[wif_ct].wif_rct = rct;
      w_if_table[wif_ct].wif_level = if_level;
      w_if_table[wif_ct].wif_eof1 = 0;
      w_if_table[wif_ct].wif_else1 = 0;
      w_if_table[wif_ct].wif_eof2 = 0;
      wif_ct++;

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_pass2_if #100\n", rct);
      }

      c2_pass2_if();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for malloc (skip)                                       *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for malloc\n", rct);
    }

    p = strstr(p_string, "malloc");
    p1 = strstr(p_string, "#include");

    if ((p) && (!p1)) 
    {
      /* c2_scan_malloc();
      convert = 1; */
    }


    /* ***************************************************************
     *  Scan for remove                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for remove\n", rct);
    }

    p = strstr(p_string, "remove");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c scan remove");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_file_remove #100\n", rct);
      }

      c2_file_remove();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for break                                               *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for break\n", rct);
    }

    p = strstr(p_string, "break");
    if (p) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan break");
        trace_rec_1();
      }
    }


    /* ***************************************************************
     *  Scan for return                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for return\n", rct);
    }

    p = strstr(p_string, "return");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan return");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_return_2 #100\n", rct);
      }

      c2_return_2();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for exit                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for exit\n", rct);
    }

    p = strstr(p_string, "exit");
    if (p) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan exit");
        trace_rec_1();
      }
    }


    /* ***************************************************************
     *  Scan for ++                                                  *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for ++\n", rct);
    }

    p = strstr(p_string, "++;");
    if (p) {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan ++");
        trace_rec_1();
      }
    }


    /* ***************************************************************
     *  Scan for --                                                  *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for --\n", rct);
    }

    p = strstr(p_string, "--");
    if (p) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan --");
        trace_rec_1();
      }
    }


    /* ***************************************************************
     *  Scan for strcpy                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for strcpy\n", rct);
    }

    p = strstr(p_string, "strcpy");
    if (p) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass_2 scan strcpy");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_strcpy_pass2 #100\n", rct);
      }

      c2_strcpy_pass2();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for strcat                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for strcat\n", rct);
    }

    p = strstr(p_string, "strcat");
    if (p) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan strcat");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_strcat #100\n", rct);
      }

      c2_pass2_strcat();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for strstr                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for strstr\n", rct);
    }

    p = strstr(p_string, "strstr");
       
    if (p) 
    {
      convert = 1;
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_strstr #100\n", rct);
      }

      c2_strstr_scan();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for enum                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for enum\n", rct);
    }

    p = strstr(p_string, "enum");
    p1 = strstr(p_string, "()");

    if((p) && (!p1))
    {
      c2_enum_scan(); 
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for FILE                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for FILE\n", rct);
    }

    p = strstr(p_string, "FILE");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c scan FILE");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_file #100\n", rct);
      }

      c2_file();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for fopen                                               *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for fopen\n", rct);
    }

    p = strstr(p_string, "fopen");
    p1 = strstr(p_string, "fopen_");
    if ((p) && (!p1)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan fopen");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_fopen #100\n", rct);
      }

      c2_scan_fopen();
      open_ct++;
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for fclose                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for fclose\n", rct);
    }

    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      if (ch != ';') 
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
      if (ch == '(')
      {
        break;
      }
      if (ch == ';')
      {
        break;
      }
    }
    tfield1[pi2] = '\0';

    s = strcmp(tfield1, "fclose");
    if (s == 0) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan fclose");
        trace_rec_1();
      }

      open_ct--;
      s = strlen(p_string);
      pi = 0;
      pi2 = 0;
      ch = p_string[pi];

      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        tfield1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield1[pi2] = '\0';

      x = 0;
      if (f_ct > 0) 
      {
        for (I = 0; I < f_ct; I++) 
        {
          ret = strcmp(tfield1, w_file[I].f_name);
          if (ret == 0) 
          {
            x = w_file[I].f_buf_ct;
            strcpy(tfield2, w_file[I].f_perm);
          }
        }
      }

      if (x == 0) 
      {
        printf("c2z.c C2 SCAN FCLOSE ERROR! rct = %d tfield1 = %s!\n",rct,tfield1);
        /*  exit(1); */
      }

      if (fclose_ct == 0) 
      {
        size = 1;
        w_fclose_table = malloc(size * sizeof(struct fclose_table));
      } 
      else 
      {
        size = fclose_ct + 1;
        w_fclose_table = realloc(w_fclose_table, size * sizeof(struct fclose_table));
      }

      w_fclose_table[fclose_ct].cl_rct = rct;
      w_fclose_table[fclose_ct].cl_buf_ct = x;
      fclose_ct++;

      convert = 1;
    }


    /* ***************************************************************
     *  Scan for fgetc                                               *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for fgetc\n", rct);
    }

    p = strstr(p_string, "fgetc");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan fgetc");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_fgetc #100\n", rct);
      }

      c2_fgetc_pass2();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for fgets                                               *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for fgets\n", rct);
    }

    p = strstr(p_string, "fgets");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan fgets");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_fgets #100\n", rct);
      }

      c2_scan_fgets();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for gets                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for gets\n", rct);
    }

    p = strstr(p_string, "gets");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan gets");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_gets #100\n", rct);
      }
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for fputs                                               *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for fputs\n", rct);
    }

    p = strstr(p_string, "fputs");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan fputs");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_fputs #100\n", rct);
      }

      c2_scan_fputs();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for getchar                                             *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for getchar\n", rct);
    }

    p = strstr(p_string, "getchar");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan getchar");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_getchar_pass2 #100\n", rct);
      }

      c2_getchar_pass2();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for int main                                            *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for int MAIN\n", rct);
    }

    p = strstr(p_string, "int");
    p1 = strstr(p_string, "print");
    p2 = strstr(p_string, "main");
    p3 = strstr(p_string, "()");
    if ((p) && (!p1) && (p2)) 
    {
      if (!p3) 
      {
        /* 	c2_main(); */
      }
      convert = 1;
      global_st = 1;
    }


    /* ***************************************************************
     *  Scan for double                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for double\n", rct);
    }

    p1 = strstr(p_string, "print");
    p2 = strstr(p_string, "main");
    p = strstr(p_string, "double");
    p3 = strstr(p_string, "_double");

    v = p - p_string;
    p8 = strstr(p_string, "/*");
    s = p8 - p_string;
    if (s < 0) 
    {
      s = 9999;
    }

    if ((p) && (!p1) && (!p2) && (!p3) && (v < s)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan double");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_double #100\n", rct);
      }

      c2_double();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for float                                               *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for float\n", rct);
    }

    p8 = strstr(p_string, "float");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "float");
    if ((p) && (s < v)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_float #100\n", rct);
      }

      c2_float();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for lonh                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for long\n", rct);
    }

    p8 = strstr(p_string, "long");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "long");
    p7 = strstr(p_string, "_long");
    if ((p) && (!p7) && (s < v)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_long_pass2 #100\n", rct);
      }

      c2_long_pass2();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for cos                                               *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for cos\n", rct);
    }

    p8 = strstr(p_string, "cos");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "cos");
    if ((p) && (s < v)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_cos_pass2 #100\n", rct);
      }

      c2_cos_pass2();
      convert = 1;
    }

    /* ***************************************************************
     *  Scan for rand                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for rand\n", rct);
    }

    p8 = strstr(p_string, "rand");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "rand");
    if ((p) && (s < v)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_rand_pass2 #100\n", rct);
      }

      c2_rand_pass2();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for pw                                                  *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for pow\n", rct);
    }

    p8 = strstr(p_string, "pow");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "pow");
    if ((p) && (s < v)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_pow_pass2 #100\n", rct);
      }

      c2_pow_pass2();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for sin                                                 *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for sin\n", rct);
    }

    p8 = strstr(p_string, "sin");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "sin");
    if ((p) && (s < v)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_sin_pass2 #100\n", rct);
      }

      c2_sin_pass2();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for sqrt                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for sqrt\n", rct);
    }

    p8 = strstr(p_string, "sqrt");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "sqrt");
    if ((p) && (s < v)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_sqrt_pass2 #100\n", rct);
      }

      c2_sqrt_pass2();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for tan                                                 *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for tan\n", rct);
    }

    p8 = strstr(p_string, "tan");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "tan");
    if ((p) && (s < v)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_tan_pass2 #100\n", rct);
      }

      c2_tan_pass2();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for unsigned                                            *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for unsigned\n", rct);
    }

    p = strstr(p_string, "unsigned");
    if (p) 
    {
      if (debug_lv >= 2)  
      {
        printf("c2z.c Pass 2 rct = %d c2_unsigned #100\n", rct);
      }

      c2_unsigned();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for atof                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for atof\n", rct);
    }

    p = strstr(p_string, "atof");
    if (p) {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_atof #100\n", rct);
      }

      c2_atof();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for case                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for case\n", rct);
    }

    p = strstr(p_string, "case");
    p1 = strstr(p_string, "=");
    if ((p) && (!p1)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan case");
        trace_rec_1();
      }
      c2_pass2_case();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for strcmp                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for strcmp\n", rct);
    }

    p = strstr(p_string, "strcmp");
    if (p) 
    {
      p1 = strstr(p_string, "\"");
      if (p1) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z.c pass 2 scan strcmp");
          trace_rec_1();
        }

        pi = 0;
        ch = p_string[pi];
        while (ch != '"') 
        {
          pi++;
          ch = p_string[pi];
        }

        x3 = 0;
        pi2 = 0;
        pi++;
        ch = p_string[pi];
        while (ch != '"') 
        {
          a_string[pi2] = ch;
          pi2++;
          x3++;
          pi++;
          ch = p_string[pi];
        }
        a_string[pi2] = '\0';

/*  update the struct with literal  */

        if (gv_ct == 0) 
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


    /* ***************************************************************
     *  Scan for strncmp                                             *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for strcmp\n", rct);
    }

    p = strstr(p_string, "strncmp");
    if (p) 
    {
      p1 = strstr(p_string, "\"");
      if (p1) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z.c pass 2 scan strncmp");
          trace_rec_1();
        }

        pi = 0;
        ch = p_string[pi];
        while (ch != '"') 
        {
          pi++;
          ch = p_string[pi];
        }

        x3 = 0;
        pi2 = 0;
        pi++;
        ch = p_string[pi];
        while (ch != '"') 
        {
          a_string[pi2] = ch;
          pi2++;
          x3++;
          pi++;
          ch = p_string[pi];
        }
        a_string[pi2] = '\0';

/*  update the struct with literal  */

        if (gv_ct == 0) 
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


    /* ***************************************************************
     *  Scan for feof                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for feof\n", rct);
    }

    p = strstr(p_string, "feof");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan feof");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_scan_feof #100\n", rct);
      }

      c2_scan_feof();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for pid_t                                               *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for pid_t\n", rct);
    }

    p = strstr(p_string, "pid_t");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan pid_t");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_scan_pid_t #100\n", rct);
      }

      /* c2_scan_pid_t();   */
      convert = 1;
    }

    /* ***************************************************************
     *  Scan for accept                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for accept\n", rct);
    }

    p = strstr(p_string, "accept");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan accept");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_scan_accept #100\n", rct);
      }

      /* c2_scan_accept();   */
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for send                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for send\n", rct);
    }

    p = strstr(p_string, "send");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan send");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_scan_send #100\n", rct);
      }

      /* c2_scan_send();   */
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for strlen                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for strlen\n", rct);
    }

    p = strstr(p_string, "strlen");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan strlen");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_strlen_pass2 #100\n", rct);
      }

      c2_strlen_pass2();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for sizeof                                              *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for sizeof\n", rct);
    }

    p = strstr(p_string, "sizeof");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan sizeof");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_sizeof #100\n", rct);
      }

      c2_pass2_sizeof();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for GOTO                                                *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for goto\n", rct);
    }

    p = strstr(p_string, "goto");
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 2 scan goto");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_goto #100\n", rct);
      }

      /* c2_pass2_sizeof(); */
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for GOTO LABEL                                          *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for goto label\n", rct);
    }

    x = 0;
    s = strlen(p_string);
    for(x = 0; x < s; x++)
    {
      if(p_string[x] == ':')
      {
         goto_label_scan();
         convert = 1;
         break;
      }
    }


    /* ***************************************************************
     *  Scan for CLOCK                                               *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for clock\n", rct);
    }

    p = strstr(p_string, "clock");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_clock #100\n", rct);
      }

      c2_clock_pass2();
      convert = 1;
    }


    /* ***************************************************************
     *  Scan for TOUPPER                                             *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for toupper\n", rct);
    }

    p = strstr(p_string, "toupper");
    if (p) 
    {
      work_use_ct[90]++;
      convert = 1;
    }

    /* ***************************************************************
     *  Math literal  = MUST BE LAST CALL IN PARSER                  *
     * ************************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 2 rct = %d Scan for math literal\n", rct);
    }

    p8 = strstr(p_string, "=");
    s = p8 - p_string;
    p8 = strstr(p_string, "/*");
    v = p8 - p_string;

    if (v < 0) 
    {
      v = 9999;
    }


    p = strstr(p_string, "=");
    if ((p) && (s < v)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_math_literal #100\n", rct);
      }
      c2_math_literal();

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 2 rct = %d c2_pass2_math #100\n", rct);
      }

     /* c2_pass2_math(); */
      convert = 1;
    }

/* End of while loop for PASS 2  */

    pass2_skip:
    ch = '\0';

  } 		



/* Test for balanced fopen & fclose  */

/*   if (open_ct != 0) */ 
/*   {  */
/*     printf("Unbalanced fopen and fclose statements\n"); */
/*     printf("      Error at Line # - %d\n", rct); */
/*   }  */

  fclose(pgm);

  if (gv_ct == 0) 
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
  strcpy(gw_variable[gv_ct].gv_literal, null_field);
  gw_variable[gv_ct].gv_use_ct = 0;
  gw_variable[gv_ct].gv_dec = 0;
  gw_variable[gv_ct].gv_id = 1;
  gv_ct++;

/* End of Pass 2 - scan parser  */

  if(erct != 0)
  {
    printf("\nPass 2 Failed with %d errors.\n",erct);
/*    c2_debug();  */
/*    exit(1);  */
  }

  /* ************************************************************
  *  -- Code Generation - creating the xxxx.mlc file        *
  * *********************************************************** */

  printf("*  c2z Z390 Pass 3 Started                    *\n");

 
  cc370 = fopen(asm_file, "w"); 
  
  rct = 0;
  var_use[1] = 0;
  end_input = 0;
  global_st = 0;
  mainflg = 0;
  main_set = 0;
  inside_main = 0;
  erct = 0;

  /* ************************************************************
  *  Punch START Pass 3                                         *
  * *********************************************************** */

  c2_pass_3();

  rct = 0;
  end_asm = 1;
  else_active = 0;
  else_flag = 0;
  inside_for = 0;

  if (traceflg == 1) 
  {
    strcpy(trace_2, "\n");
    trace_1[0] = '\0';
    trace_rec_1();
    strcpy(trace_2, "3");
  }

  pgm = fopen("srcformat.c", "r");

  while (1) 
  {
    convert = 0;
    bracket_convert = 0;
    fprintf_lit = 0;
    math_convert = 0;
    fprtf_flag = 0;
    convert_ignore = 0;
    quote_1 = 0;
    quote_2 = 0;

    fgets(p_string, BUFSIZE, pgm);
    rct++;

    s = strlen(p_string);
    for(I = 0; I < s; I++)
    {
      if(p_string[I] == '\"')
      {
        if(p_string[I - 1] != '\\')
        {
          if(quote_1 == 0)
          {
            quote_1 = I;
          }
          else
          {
            quote_2 = I;
          }
        }
      }
    }


/* printf("c2z.c Pass 3 parm_ct = %d s = %d rct = %d erct = %d p_string = %s",parm_ct, s, rct,erct, p_string); */
 
    if (debug_lv >= 1) 
    {
      printf("\nc2z.c Pass 3 rct = %d L1 p_string = %s", rct, p_string);
    }

    if (feof(pgm)) 
    {
      break;
    }

    if (s < 2) 
    {
      goto end_pass3;
    }

    pgm_label(); 

    strcpy(o_string, p_string);
    if (feof(pgm)) 
    {
      end_input = 1;
    }

    p = strstr(p_string, "{");
    if (p) 
    {
      parm_ct++;
      end_asm = 0;
      bracket_convert = 1;
    }

    p = strstr(p_string, "}");
    if (p) 
    {
      parm_ct--;
      end_asm = 0;
      bracket_convert = 1;
    }

    if(parm_ct < 1)
    {
      parm_ct = 0;
    }


    /* **********************************************************
    *  FOR loop END                                             * 
    *  If inside_for == 1 & for_parm == 0, end if loop of the C *
    *  for loop has been reached.  Punch out branch   equ label *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch for loop end\n", rct);
    }

    if(for_2nd_ct == 1)
    {
      v = 0;
      for (v = 0; v < for_ct; v++) 
      {
        if (rct == w_for_table[v].for_eof1) 
        {
          strcpy(a_string, "         LARL  R9,");
          strcat(a_string, w_for_table[v].for_rt_field2);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z.c FOR/End #1");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R8,C370ONE");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z.c FOR/End #2");
            trace_rec_3();
          }

          strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z.c FOR/End #3");
            trace_rec_3();
          }
          for_2nd_ct = 0;
        }
      }
    }

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_eof1) 
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, w_for_table[v].for_rt_field);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z.c FOR/End #4");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z.c FOR/End #5");
          trace_rec_3();
        }

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z.c FOR/End #6");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", w_for_table[v].for_rct);
        strcpy(a_string, "         JLU   L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z.c FOR/End #7");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", w_for_table[v].for_rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z.c FOR/End #8");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370LPCT");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z.c FOR/End #9");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z.c FOR/End #10");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z.c FOR/End #11");
          trace_rec_3();
        }
        for_2nd_ct = 0;
        convert = 1;
        break;
      }
   }


    /* ***********************************************************
    *  test rct against wif_table eof1 & eof2                    *
    * ********************************************************** */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d L2 Punch wif_table eof1 & eof2 p_string = %s\n",rct, p_string);
    }

    p = strstr(p_string, "{");
    if (p) 
    {
      goto wif_skip;
    }

    p = strstr(p_string, "}");
    if (!p) 
    {
      goto wif_skip;
    }

    if (wif_ct > 0) 
    {

      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2.c IF End Label");
      }

      v = 0;
      for (v = 0; v < wif_ct; v++) 
      {
        if ((rct == w_if_table[v].wif_eof1) && (w_if_table[v].wif_else1 == 0)) 
        {
          strcpy(a_string, "L");
          snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[v].wif_rct);
          strcat(a_string, wk_strg);
          check_length();
          strcat(a_string, "DS    0H");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "Pass3 c2.c IF End #1");
            trace_rec_3();
          }

          if (return_on == 1) 
          {
            return_ct++;
          }
          convert = 1;
        }

        if ((rct == w_if_table[v].wif_eof1) && (w_if_table[v].wif_else1 != 0)) 
        {
          strcpy(a_string, "         JLU   ");
          strcat(a_string, "L");
          snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[v].wif_eof2);
          strcat(a_string, wk_strg);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "Pass3 c2.c IF End #2");
            trace_rec_3();
          }

          strcpy(a_string, "L");
          snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[v].wif_rct);
          strcat(a_string, wk_strg);
          check_length();
          strcat(a_string, "DS    0H");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "Pass3 c2.c IF End #3");
            trace_rec_3();
          }

          if (return_on == 1) 
          {
            return_ct++;
          }
          convert = 1;
        }

        if (rct == w_if_table[v].wif_eof2) 		/* punch out branch using eof2 */
        {
          strcpy(a_string, "L");
          snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[v].wif_eof2);
          strcat(a_string, wk_strg);
          check_length();
          strcat(a_string, "DS    0H");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "Pass3 c2.c IF End #4");
            trace_rec_3();
          }

          if (return_on == 1) 
          {
            return_ct++;
          }
          convert = 1;
        }
      }
    }

    if (wh_ct > 0) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c while end label");
        trace_rec_1();
      }

      for (v = 0; v < wh_ct; v++) 
      {
        if (rct == w_while_table[v].wh_eof1) 
        {
          for (v1 = 0; v1 < gv_ct; v1++) 
          {
            ret = strcmp("A", gw_variable[v1].gv_type);
            if (ret == 0) 
            {
              strcpy(ar_field6, gw_variable[v1].gv_label);
              strcpy(ar_field7, gw_variable[v1].gv_table);
              strcpy(ar_field8, gw_variable[v1].gv_aname);
              strcpy(ar_field9, gw_variable[v1].gv_sv_reg);
              strcpy(ar_field10, gw_variable[v1].gv_wk_reg);
              strcpy(ar_field11, gw_variable[v1].gv_wk_strg);
              convert = 1;

              if (gw_variable[v1].gv_flag > 0) 
              {
/*
                strcpy(a_string, "*         LAEY  R6,");
                strcat(a_string, ar_field6);
                strcat(a_string, "(R0,R6)");
                src_line();
                if (puncde == 1) 
                {
                  strcpy(trace_1, "c2z.c while End #1");
                  trace_rec_3();
                }
 */
                gw_variable[v1].gv_flag = 0;
                convert = 1;
              }
            }
          }

          strcpy(a_string, "         JLU   ");
          strcat(a_string, "L");
          snprintf(wk_strg, sizeof(wk_strg), "%d", w_while_table[v].wh_rct);
          strcpy(o_string, wk_strg);
          strcat(a_string, wk_strg);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z.c while End #2");
            trace_rec_3();
          }

          strcpy(a_string, "L");
          strcat(a_string, o_string);
          strcat(a_string, "E");
          check_length();
          strcat(a_string, "DS    0H");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z.c while End #3");
            trace_rec_3();
          }

          if (return_on == 1) 
          {
            return_ct++;
          }

          strcpy(a_string, "         LARL  R9,C370NWK2");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z.c while End #4");
            trace_rec_3();
          }
          work_use_ct[50]++;

          strcpy(a_string, "         LARL  R8,C370ZERO");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z.c while End #5");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z.c while End #6");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370LPCT");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z.c while End #7");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R8,C370ZERO");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z.c while End #8");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z.c while End #9");
            trace_rec_3();
          }
          work_use_ct[73]++;
          convert = 1;
        }
      }
    }

  wif_skip:


    /* **********************************************************
    *  Test for MAIN in C program and if found punch to to ASM  *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    } 

    mainflg = 0;
    if (mainflg != 1) 
    {
      p = strstr(p_string, "main");
      p1 = strstr(p_string, "int");
      if ((p) && (p1)) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z.c pass 3 punch MAIN");
          trace_rec_1();
        }

        inside_main = 1;
        strcpy(sv_func, "main");
        strcpy(from_sv, "main");
        global_st = 1;
        mainflg = 1;
        main_set = 1;

/*        strcpy(a_string, "         LARL  R1,C370HEAD");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z.c Heading #1");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R0,C370HL");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z.c Heading #2");
          trace_rec_3();
        }

        strcpy(a_string, "         TPUT  (R1),(R0),R");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z.c Heading #3");
          trace_rec_3();
        }
*/

        for (I = 0; I < gv_ct; I++) 
        {  
           x = strcmp("G", gw_variable[I].gv_type);
           if(x == 0)
           {
             strcpy(p_string, "    free(");
             strcat(p_string, gw_variable[I].gv_name); 
             strcat(p_string, ")\n");
             c2_free();
           }
           x = strcmp("A", gw_variable[I].gv_type);
           if(x == 0)
           {
             strcpy(p_string, "    free(");
             strcat(p_string, gw_variable[I].gv_name); 
             strcat(p_string, ")\n");
             c2_free();
           }
        }

        x = 0;
        for (I = 0; I < m_struc_ct; I++) 
        {
          ret = strcmp(w_struc[I].st_id, "M");
          if(ret == 0)
          {
            strcpy(p_string, "    free(");
            strcat(p_string, w_struc[I].st_name);
            strcat(p_string, ")\n");
            c2_free();
          }
       }

       convert = 1; 
      }
    }

   /* **********************************************************
    *  Test for fflush                                         *
    * ******************************************************** */
    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Test fflush\n", rct);
    }

    p = strstr(p_string, "fflush");
    if(p)
    {
      convert = 1;
    }


    /* **********************************************************
    *  Test for prototypes                                      *
    * ********************************************************* */
    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch prototypes\n", rct);
    }

    p = strstr(p_string, "void");
    p1 = strstr(p_string, ";");
    p2 = strstr(p_string, "int");
    p3 = strstr(p_string, "(");
    p4 = strstr(p_string, ")");
    p5 = strstr(p_string, "printf");

    if ((p) && (!p1) && (!p5) && (p3) && (p4)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 Prototype #1");
        trace_rec_1();
      }

      c2_func_sub();
      convert = 1;
    }

    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "void");
    p1 = strstr(p_string, ";");
    p2 = strstr(p_string, "int");
    p3 = strstr(p_string, "(");
    p4 = strstr(p_string, ")");
    p5 = strstr(p_string, "printf");
    p6 = strstr(p_string, "\"");
    p7 = strstr(p_string, "print");
    p8 = strstr(p_string, "while");
    p9 = strstr(p_string, "/*");

    v = p2 - p_string;
    s = p9 - p_string;

    if (v < 0) 
    {
      v = 9999;
    }

    if (s < 0) 
    {
      s = 9999;
    }

    if ((p2) && (p3) && (p4) && (!p1) && (v < s) && (!p5) && (!p6) && (!p7) && (!p8)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 Prototype #2");
        trace_rec_1();
      }
      c2_func_sub();
      convert = 1;
   
    }

    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "void");
    p1 = strstr(p_string, ";");
    p2 = strstr(p_string, "int");
    p3 = strstr(p_string, "(");
    p4 = strstr(p_string, ")");
    p5 = strstr(p_string, "printf");
  
    if ((p) && (p3) && (p4) && (!p5) && (convert == 0)) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 Prototype #3");
        trace_rec_1();
      }

      pi = 0;
      pi2 = 0;
      ch = p_string[pi];
      while ((ch == ' ') || (ch == '\t')) 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != '(') 
      {
        if (ch != ' ') 
        {
          tfield1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield1[pi2] = '\0';
      strcpy(sv_func, tfield1);
    }

    p = strstr(p_string, "void");
    p1 = strstr(p_string, ";");
    p2 = strstr(p_string, "int");
    p3 = strstr(p_string, "(");
    p4 = strstr(p_string, ")");
    p5 = strstr(p_string, "printf");

    if ((p) && (p3) && (p4) && (!p5) && (convert == 0)) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 Prototype #3");
        trace_rec_1();
      }

      pi = 0;
      pi2 = 0;
      ch = p_string[pi];
      while ((ch == ' ') || (ch == '\t')) 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != '(') 
      {
        if (ch != ' ') 
        {
          tfield1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield1[pi2] = '\0';
      strcpy(sv_func, tfield1);
    }

    p = strstr(p_string, "void");
    p1 = strstr(p_string, ";");
    p2 = strstr(p_string, "int");
    p3 = strstr(p_string, "(");
    p4 = strstr(p_string, ")");
    p5 = strstr(p_string, "printf");
    p6 = strstr(p_string, "(double");

    if ((p2) && (p3) && (p4) && (p6) && (!p5) && (convert == 0)) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 Prototype #3");
        trace_rec_1();
      }

      pi = 0;
      pi2 = 0;
      ch = p_string[pi];
      while ((ch == ' ') || (ch == '\t')) 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != '(') 
      {
        if (ch != ' ') 
        {
          tfield1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield1[pi2] = '\0';
      strcpy(sv_func, tfield1);
    }

    p = strstr(p_string, "void");
    p1 = strstr(p_string, ";");
    p2 = strstr(p_string, "char");
    p3 = strstr(p_string, "(");
    p4 = strstr(p_string, ")");
    p5 = strstr(p_string, "printf");
    p6 = strstr(p_string, "/*");
    p7 = strstr(p_string, "double");

    v = p6 - p_string;
    s = p2 - p_string;
    if (v < 0) 
    {
      v = 9999;
    }

    if ((p2) && (p3) && (p4) && (!p) && (!p1) && (!p5) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 Prototype #4");
        trace_rec_1();
      }
      c2_func_sub();
      convert = 1;
   
    }

/*   if ((p2) && (p3) && (p4) && (!p) && (p1) && (!p5) && (convert == 0) && (s < v)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 Prototype #4c");
        trace_rec_1();
      }
      c2_func_sub();
      convert = 1;
    }
*/

    p = strstr(p_string, "void");
    p1 = strstr(p_string, ";");
    p2 = strstr(p_string, "int");
    p3 = strstr(p_string, "(");
    p4 = strstr(p_string, ")");
    p5 = strstr(p_string, "printf");
    p6 = strstr(p_string, "while(");
    if(!p6)
    {
      p6 = strstr(p_string, "while (");
    }

    s = p2 - p_string;
    p8 = strstr(p_string, "/*");
    v = p8 - p_string;

    if (v < 0) 
    {
      v = 9999;
    }

    if ((!p6) && (p2) && (p3) && (p4) && (!p) && (!p1) && (!p5) && (s < v) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 Prototype #5");
        trace_rec_1();
      }
      c2_func_sub();
      convert = 1;
    }

    p = strstr(p_string, "double");
    p1 = strstr(p_string, ";");
    p3 = strstr(p_string, "(");
    p4 = strstr(p_string, ")");
    p5 = strstr(p_string, "/*");
    p6 = strstr(p_string, "char *");

    v = p5 - p_string;
    if (v < 0) 
    {
      v = 9999;
    }

    s = p - p_string;
    if (s < 0) 
    {
      s = 9999;
    }

    if ((p) && (p1) && (p3) && (p4) && (p6) && (s < v) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 Prototype #6");
        trace_rec_1();
      }
      c2_func_sub();
      convert = 1;
    }

    if ((p) && (p3) && (p4) && (p4) && (s < v) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 Prototype #6d");
        trace_rec_1();
      }
      c2_func_sub();
      convert = 1;
    }

    p = strstr(p_string, "long");
    p1 = strstr(p_string, ";");
    p3 = strstr(p_string, "(");
    p4 = strstr(p_string, ")");
    p5 = strstr(p_string, "/*");

    v = p5 - p_string;
    if (v < 0) 
    {
      v = 9999;
    }

    s = p - p_string;
    if (s < 0) 
    {
      s = 9999;
    }

    if ((p) && (!p1) && (p3) && (p4) && (s < v) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 Prototype #7");
        trace_rec_1();
      }
      c2_func_sub();
      convert = 1;
    }

    
    /* **********************************************************
    *  Punch #defines  (skip)                                   *
    * ********************************************************* */

    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch #define (SKIP)\n", rct);
    }

    p = strstr(p_string, "#define");
    if (p) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 #define");
        trace_rec_1();
        if (return_on == 1) 
        {
          return_ct++;
        }
      }
    }

    /* **********************************************************
    *  Punch #ifndef  (skip)                                    *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch #ifndef (SKIP)\n", rct);
    }

    p = strstr(p_string, "#ifndef");
    if (p) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 #ifndef");
        trace_rec_1();
        if (return_on == 1) 
        {
          return_ct++;
        }
      }
    }

    /* **********************************************************
    *  Punch #endif  (skip)                                     *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch #endif (SKIP)\n", rct);
    }

    p = strstr(p_string, "#endif");
    if (p) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 #endif");
        trace_rec_1();
        if (return_on == 1) 
        {
          return_ct++;
        }
      }
    }

    /* **********************************************************
    *  Punch #include  (skip)                                   *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch #include (SKIP)\n", rct);
    }

    p = strstr(p_string, "#include");
    if (p) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 test #include");
        trace_rec_1();
      }
    }

    /* **********************************************************
    *  Punch FILE  (skip)                                       * 
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch FILE (SKIP)\n", rct);
    }

    p = strstr(p_string, "FILE");
    if (p) {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 test file");
        trace_rec_1();
      }
    }


    /* **********************************************************
    *  Punch bind                                               *
    * ********************************************************* */

    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch bind\n", rct);
    }

    p = strstr(p_string, "bind");
    if (p)
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_bind #100\n", rct);
      }
      c2_bind();
      convert = 1;
    }


    /* **********************************************************
    *  Punch listen                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch listen\n", rct);
    }

    p = strstr(p_string, "listen");
    if (p)
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_listen #100\n", rct);
      }
      c2_listen();
      convert = 1;
    }


    /* **********************************************************
    *  Punch send                                               *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch send\n", rct);
    }

    p = strstr(p_string, "send");
    if (p)
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_send #100\n", rct);
      }
      c2_send();
      convert = 1;
    }


    /* **********************************************************
    * Punch struct                                              *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch struct\n", rct);
    }

    p = strstr(p_string, "struct");
    p1 = strstr(p_string, "localtime");
    if((p) && (!p1)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_struct #100\n", rct);
      }

      c2_struct_3();
      convert = 1;
    }

    /* **********************************************************
    * Punch remove                                              *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch remove\n", rct);
    }

    p = strstr(p_string, "remove");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_file_punch #100\n", rct);
      }

      c2_file_punch();
      convert = 1;
    }

    /* **********************************************************
    *  Punch malloc                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch malloc\n", rct);
    }

    p = strstr(p_string, "malloc");
    p1 = strstr(p_string, "#include");

    if ((p) && (!p1)) 
    {
      /* c2_scan_malloc(); */
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 test malloc");
        trace_rec_1();
      }

      convert = 1;
    }


    /* **********************************************************
    *  Test for realloc                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch realloc\n", rct);
    }

    p = strstr(p_string, "realloc");
    p1 = strstr(p_string, "#include");

    if ((p) && (!p1)) 
    {
      /* c2_scan_malloc(); */
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 test realloc");
        trace_rec_1();
      }
      convert = 1;
    }


    /* **********************************************************
    * Test for int or char                                      *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch int or char\n", rct);
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    for (I = 0; I < 5; I++) 
    {
      ch = p_string[pi];
      tfield1[pi2] = ch;
      pi2++;
      pi++;
    }
    tfield1[pi2] = '\0';

    x = 0;
    p = strstr(tfield1, "char");
    if (p) 
    {
      if (tfield1[4] == ' ') 
      {
        x = 1;
      }
    }

    if (x == 0) 
    {
      p = strstr(tfield1, "int");
      if (p) 
      {
        if (tfield1[3] == ' ') 
        {
          x = 1;
        }
      }
    }

    if (x == 0) 
    {
      goto int_end_pass;
    }

    p = strstr(p_string, "int");
    p1 = strstr(p_string, "char");
    p2 = strstr(p_string, "print");
    p3 = strstr(p_string, "void");
    p4 = strstr(p_string, "main");
    p5 = strstr(p_string, ";");
    p6 = strstr(p_string, "snprintf");
    p7 = strstr(p_string, "\"");
    p8 = strstr(p_string, "=");

    s = p - p_string;
    v = p8 - p_string;

    if (s < 0) 
    {
      s = 9999;
    }

    if (v < 0) 
    {
      v = 9999;
    }

    if ((p) && (!p2) && (!p3) && (!p4) && (!p6) && (!p7) && (s < v)) 
    {
      convert = 1;
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_int_punch #100\n", rct);
      }

      c2_int_punch();

      if (return_on == 1) 
      {
        return_ct++;
      }
    }

    if ((p1) && (!p)) 
    {
      convert = 1;
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_char_punch #100\n", rct);
      }

      c2_char_punch();

      if (return_on == 1) 
      {
        return_ct++;
      }
    }

    if (convert == 1) 
    {
      goto end_pass3;
    }

    if ((p) && (!p2) && (!p4) && (p3) && (!p5) && (!p6) && (!p7)) 
    {
      convert = 1;
    }

    if (convert == 1) 
    {
      goto end_pass3;
    }

    if ((p1) && (!p3) && (!p4) && (!p7)) 
    {
      convert = 1;
    }

    if (convert == 1) 
    {
      goto end_pass3;
    }

    if ((p1) && (!p3) && (!p4) && (p7)) 
    {
      convert = 1;
    }

    int_end_pass:


    /* **********************************************************
    *  Punch case                                               *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch case\n", rct);
    }

    quote_3 = 0;
    p = strstr(p_string, "case");
    v = p - p_string;
    if((quote_1 != 0) && (quote_2 != 0))
    {
      if((v > quote_1) && (v < quote_2))	/*  case enclosed inside of quotes NO PROCESS */
      {
        printf("c2z.c rct = %d p_string = %s",rct,p_string);
        printf("c2z.c NOT PROCESSED\n");
        quote_3 = 1;
      }
    }

    if((p) && (quote_3 == 0)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_case #100\n", rct);
      }

      c2_case();
      tot_case++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch case default                                       *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch default\n", rct);
    }

    p = strstr(p_string, "default");
    if ((p) && (if_case == 1)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 test default");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_default #100\n", rct);
      }

      c2_case_default();
      tot_case++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch break                                              *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch break\n", rct);
    }

    p = strstr(p_string, "break");
    if ((p) && (if_case == 1)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_break #100\n", rct);
      }

      c2_break();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }



    /* **********************************************************
    *  Punch for                                                *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch for \n", rct);
    }


    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    ch = p_string[pi];
    for (I = 0; I < 4; I++) 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    x = 0;
    p = strstr(p_string, "for");
    if(p)
    {
      x = 1;
    }

    p1 = strstr(p_string, "for(");
    if(p1)
    {
      x = 1;
    }

    p2 = strstr(p_string, "for()");
    if(p2)
    {
      x = 0;
    }

    s = p - p_string;
    if (s < 0)
    {
      s = 9999;
    }

    p8 = strstr(p_string, "/*");
    v = p8 - p_string;

    if (v < 0) 
    {
      v = 9999;
    }

    p4 = strstr(p_string, "_");
    x3 = p4 - p_string;
    if(x3 < 0)
    {
       x3 = 9999;
    }

    p5 = strstr(p_string, "fornxt");
    
    if ((x == 1) && (s < v) && (s < x3) && (!p5))
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_for #100\n", rct);
      }

      c2_for();


      convert = 1;


      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch IF statement                                       *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch if\n", rct);
    }

    p = strstr(p_string, "if");
    p1 = strstr(p_string, "pthread_create");
    if((p) && (p1))
    {
      convert = 1;
    }

    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "if");
    p3 = strstr(p_string, "strcmp");
    p1 = strstr(p_string, "int");
    p2 = strstr(p_string, "(");
    p4 = strstr(p_string, "_if");
    p5 = strstr(p_string, "\"");  
    p6 = strstr(p_string, "=");

    x = p6 - p_string;
    if(x < 0)
    {
      x = 9999;
    }
    
    s = p - p_string;
    if((p) && (x < s))
    {
      goto skip_for_99;
    }
   
    p8 = strstr(p_string, "/*");
    v = p8 - p_string;
    if (v < 0) 
    {
      v = 9999;
    }

    x = p5 - p_string;
    if (x < 0) 
    {
      x = 9999;
    }

    if ((p) && (p2) && (!p4) && (s < v) && (s < x)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_if #100\n", rct);
      }

      c2_if();
      var_use[7]++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }

    if (convert == 1) 
    {
      goto end_pass3;
    }

    if ((p) && (p2) && (!p1) && (!p4) && (!p5) && (convert == 0) && (s < v)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 test if #1");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_if #101\n", rct);
      }

      c2_if();
      var_use[7]++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }

    if (convert == 1) 
    {
      goto end_pass3;
    }

    if ((p) && (p2) && (p3) && (convert == 0) && (!p5) && (s < v)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_if #102\n", rct);
      }

      c2_if();
      var_use[7]++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }

    skip_for_99:


    /* **********************************************************
    *  Punch sprintf                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch sprintf\n", rct);
    }

    p = strstr(p_string, "sprintf");
    p1 = strstr(p_string, "snprintf");
    if ((p) && (!p1)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_sprintf #100\n", rct);
      }

      c2_sprintf();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }



    /* **********************************************************
    *  Punch fprintf                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch fprintf\n", rct);
    }

    p = strstr(p_string, "fprintf");
    p1 = strstr(p_string, "snprintf");
    if ((p) && (!p1)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_fprintf #100\n", rct);
      }

      c2_fprintf();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch printf                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch printf\n", rct);
    }

    p = strstr(p_string, "printf");
    p1 = strstr(p_string, "snprintf");
    printf_convert = 0;
    if ((p) && (!p1) && (fprtf_flag != 1)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_printf #100\n", rct);
      }

      c2_printf();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch snprintf                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch snprintf\n", rct);
    }

    p1 = strstr(p_string, "snprintf");
    if (p1) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_snprintf #100\n", rct);
      }

      c2_snprintf();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch scanf                                              *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch scanf\n", rct);
    }

    p1 = strstr(p_string, "scanf");
    if (p1) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 test scanf");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_scanf #100\n", rct);
      }

      c2_scanf();
      convert = 1;
    }


    /* **********************************************************
    *  Punch return                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch return\n", rct);
    }

    p = strstr(p_string, "return");
    if (p) 
    {
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "Punch RETURN");
        trace_rec_1();
      }

      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_return #100\n", rct);
      }

      c2_return();
    }


    /* **********************************************************
    *  Punch switch                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch switch\n", rct);
    }

    p = strstr(p_string, "switch");
    if (p) {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_switch #100\n", rct);
      }

      c2_switch();
      tot_switch++;
      convert = 1;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "Punch SWITCH");
        trace_rec_1();
      }

      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch fclose                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch fclose\n", rct);
    }

    p = strstr(p_string, "fclose");
    p1 = strstr(p_string, "_fclose");
    if ((p) && (!p1)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_fclose #100\n", rct);
      }

      c2_close();
      var_use[6]++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch close                                              *
    * ********************************************************* */
/*
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch close\n", rct);
    }

    p = strstr(p_string, "close");
    if (p)
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_close #100\n", rct);
      }

      convert = 1;
    }
*/


    /* **********************************************************
    *  Punch free                                               *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch free\n", rct);
    }

    p = strstr(p_string, "free");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_free #100\n", rct);
      }

      c2_free();
      var_use[14]++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* ***********************************************************
    *  Punch pthread                                             *
    * ********************************************************** */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch pthread\n", rct);
    }

    p = strstr(p_string, "pthread");
    if (p) 
    {
      convert = 1;
    }



    /* **********************************************************
    *   Switch label punch out                                  *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d L2 Punch Switch loop\n", rct);
    }

    if (switch_ct > 0)
    {
      if (debug_lv >= 3) 
      {
        printf("c2z.c Pass 3 rct = %d L3 Switch Loop \n", rct);
      }
  
      v = 0;
      for (v = 0; v < switch_ct; v++) 
      {
        if (rct == w_switch_table[v].switch_eof1)
        {
          c2_case_end();
          if (return_on == 1) 
          {
            return_ct++;
          }
          convert = 1;
        }
      }
    }


    /* **********************************************************
    *  Punch back from function                                 *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d inside_void = %d parm_ct = %d Punch back from function\n", rct,inside_void, parm_ct);
    }

    p = strstr(p_string, "}");
    if ((p) && (inside_void == 2) && (parm_ct == 0)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_func_end #100\n", rct);
      }

      c2_func_end();
      convert = 1;
      inside_void = 0;
    }


    /* **********************************************************
    *  Punch user VOID FUNCTION code                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch void function\n", rct);
    }

    if (fns_ct > 0) 
    {
      for (I = 0; I < fns_ct; I++) 
      {
        if (rct == w_func_start[I].fns_rct) 
        {
          if (debug_lv >= 2) 
          {
            printf("c2z.c Pass 3 rct = %d c2_func_call #100\n", rct);
          }

          c2_func_call();
          convert = 1;
          if (return_on == 1) 
          {
            return_ct++;
          }
          break;
        }
      }
    }

    /* **********************************************************
    *  test for { & }                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch { }\n", rct);
    }

    if(convert == 0)
    {
      x1 = 0;
      x2 = 0;

      s = strlen(p_string);
      for (I = 0; I < s; I++) 
      {
        ch = p_string[I];
        if (ch == '{') 
        {
          x1++;
        }

        if (ch == '}') 
        {
          x2++;
        }
      }

      if ((x1 > 0) || (x2 > 0)) 
      {
        if (inside_void == 2) 
        {
          function_ct = function_ct + x1;
          function_ct = function_ct - x2;
          if (traceflg == 1) 
          {
            strcpy(trace_1, "c2z.c pass 3 test function_ct ");
            trace_rec_1();
          }
         
          s = strlen(p_string);
          for (I = 0; I < s; I++) 
          {
            ch = p_string[I];
            if (ch == '{') 
            {
              bk1++;
            }

            if ((ch == ' ') || (ch == '\n') || (ch == '\0')) 
            {
              bk2++;
            }
          }

          if (bk1 > 0) 
          {
            bk3 = bk1 + bk2;
            s--;
            if (s == bk3) 
            {
              /* convert = 1; */
            }
          }

          bk1 = 0;
          bk2 = 0;
          bk3 = 0;
          s = strlen(p_string);
          for (I = 0; I < s; I++) 
          {
            ch = p_string[I];
            if (ch == '}') 
            {
              bk1++;
            }

            if ((ch == ' ') || (ch == '\n') || (ch == '\0')) 
            {
              bk2++;
            }
          }

          if (bk1 > 0) 
          {
            bk3 = bk1 + bk2;
            s--;
            if (s == bk3) 
            {
              /* convert = 1; */
            }
          }
        }
      }

      if (if_case == 1) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z.c pass 3 test if_case { }");
          trace_rec_1();
        }

        case_parm_ct = case_parm_ct + x1;
        case_parm_ct = case_parm_ct - x2;

        s = strlen(p_string);
        for (I = 0; I < s; I++) 
        {
          ch = p_string[I];
          if (ch == '{') 
          {
            bk1++;
          }
          if ((ch == ' ') || (ch == '\n') || (ch == '\0')) 
          {
            bk2++;
          }
        }

        if (bk1 > 0) 
        {
          bk3 = bk1 + bk2;
          s--;
          if (s == bk3) 
          {
            /* convert = 1; */
          }
        }

        bk1 = 0;
        bk2 = 0;
        bk3 = 0;
        s = strlen(p_string);
        for (I = 0; I < s; I++) 
        {
          ch = p_string[I];
          if (ch == '}') 
          {
            bk1++;
          }
          if ((ch == ' ') || (ch == '\n') || (ch == '\0')) 
          {
            bk2++;
          }
        }

        if (bk1 > 0) 
        {
          bk3 = bk1 + bk2;
          s--;
          if (s == bk3) 
          {
            /*	convert = 1; */
          }
        }
      }
    }


    /* ***********************************************************
    *  Punch float                                               *
    * ********************************************************** */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch float\n", rct);
    }

    p = strstr(p_string, "float");
    if (p) 
    {
      convert = 1;
    }


    /* ***********************************************************
    *  Punch u_short                                             *
    * ********************************************************** */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch u_short\n", rct);
    }

    p = strstr(p_string, "u_short");
    if (p) 
    {
      convert = 1;
    }


    /* **********************************************************
    *  Punch cos                                                *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch cos\n", rct);
    }

    p = strstr(p_string, "cos");
    if (p) 
    {
      c2_cos_punch();
      convert = 1;
    }


    /* **********************************************************
    *  Punch pow                                                *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch pow\n", rct);
    }

    p = strstr(p_string, "pow");
    if (p) 
    {
      c2_pow_punch();
      convert = 1;
    }


    /* **********************************************************
    *  Punch rand                                               *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch rand\n", rct);
    }

    p = strstr(p_string, "rand");
    p1 = strstr(p_string, "_rand");
    if ((p) && (!p1)) 
    {
      c2_rand_punch();
      convert = 1;
    }


    /* **********************************************************
    *  Punch sin                                                *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch sin\n", rct);
    }

    p = strstr(p_string, "sin");
    if (p) 
    {
      c2_sin_punch();
      convert = 1;
    }


    /* **********************************************************
    *  Punch sqrt                                               *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch sqrt\n", rct);
    }

    p = strstr(p_string, "sqrt");
    if (p) 
    {
      c2_sqrt_punch();
      convert = 1;
    }


    /* **********************************************************
    *  Punch tan                                                *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch tan\n", rct);
    }

    p = strstr(p_string, "tan");
    if (p) 
    {
      c2_tan_punch();
      convert = 1;
    }


    /* **********************************************************
    *  Punch long                                               *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch long\n", rct);
    }

    p = strstr(p_string, "long");
    if (p) 
    {
      convert = 1;
    }


    /* **********************************************************
    *  Punch unsigned                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch unsigned\n", rct);
    }

    p = strstr(p_string, "unsigned");
    if (p) 
    {
      c2_unsigned_punch();
      convert = 1;
    }


    /* **********************************************************
    *  Punch strcat                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch strcat\n", rct);
    }

    p = strstr(p_string, "strcat");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_strcat #100\n", rct);
      }

      c2_strcat();
      var_use[14]++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch strlen                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch strlen\n", rct);
    }

    p = strstr(p_string, "strlen");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_strlen #100\n", rct);
      }

      c2_strlen();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch strstr                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch strstr\n", rct);
    }

    p = strstr(p_string, "strstr");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_strlen #100\n", rct);
      }

      c2_strstr();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch memcpy                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch memcpy\n", rct);
    }

    p = strstr(p_string, "memcpy");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_memcpy #100\n", rct);
      }

      c2_memcpy();
      tot_memcpy++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch memmove                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch memmove\n", rct);
    }

    p = strstr(p_string, "memmove");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_memmove #100\n", rct);
      }

      c2_memmove();
      tot_memmove++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch strcpy                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch strcpy\n", rct);
    }

    p = strstr(p_string, "strcpy");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_strcpy #100\n", rct);
      }

      c2_strcpy();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch while                                              *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch while\n", rct);
    }

    p = strstr(p_string, "while");
    p1 = strchr(p_string, '"');
    p2 = strstr(p_string, "while_");
    if ((p) && (!p2)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_while #100\n", rct);
      }

      c2_while();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch strchr                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch strchr\n", rct);
    }

    p = strstr(p_string, "strchr");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_while #100\n", rct);
      }

      c2_strchr();
      tot_strchr++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch strcmp                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch strcmp\n", rct);
    }

    p = strstr(p_string, "strcmp");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_while #100\n", rct);
      }

      c2_strcmp();
      tot_strcmp++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch strncmp                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch strncmp\n", rct);
    }

    p = strstr(p_string, "strncmp");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_while #100\n", rct);
      }

      c2_strncmp_2();
      tot_strcmp++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch sizeof                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch sizeof\n", rct);
    }

    p = strstr(p_string, "sizeof");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_sizeof #100\n", rct);
      }

      tot_sizeof++;
      c2_sizeof();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch ++ statement                                       *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch ++\n", rct);
    }

    p = strstr(p_string, "++");
    p1 = strstr(p_string, "printf");
    if ((p) && (!p1)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_plus #100\n", rct);
      }

      c2_plus();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch -- statement                                       *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch --\n", rct);
    }

    p = strstr(p_string, "--");
    s = p - p_string;
    p8 = strstr(p_string, "/*");
    v = p8 - p_string;
    if (v < 0) 
    {
      v = 9999;
    }

    if ((p) && (s < v)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_minus #100\n", rct);
      }

      c2_minus();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out goto statement                                 *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch goto\n", rct);
    }

    p2 = strstr(p_string, "/*");

    v = p2 - p_string;
    if (v < 0) 
    {
      v = 9999;
    }

    p = strstr(p_string, "goto");
    p1 = strstr(p_string, "goto_");

    s = p - p_string;
    if (s < 0) 
    {
      s = 9999;
    }

    if(s > v)
    {
      goto skip_goto;
    }

    if ((p) && (!p1)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_goto #100\n", rct);
      }

      c2_goto();
      tot_goto++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out goto label statement                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch goto label\n", rct);
    }

    p = strstr(p_string, ":");
    p1 = strstr(p_string, "'");
    p2 = strstr(p_string, "/*");

    v = p - p_string;
    if (v < 0) 
    {
      v = 9999;
    }

    s = p2 - p_string;
    if (s < 0) 
    {
      s = 9999;
    }

    if ((p) && (!p1) && (v < s)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_goto_label #100\n", rct);
      }

      c2_goto_label();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }

    skip_goto:


    /* **********************************************************
    *  Punch out feof                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch feof\n", rct);
    }

    p = strstr(p_string, "feof");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_eof #100\n", rct);
      }

      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out fopen                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch fopen\n", rct);
    }

    p = strstr(p_string, "fopen");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_goto_open #100\n", rct);
      }

      c2_open();
      var_use[5]++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out fgetc                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch fgetc\n", rct);
    }

    p = strstr(p_string, "fgetc");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_fgetc #100\n", rct);
      }

      c2_fgetc_punch();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out fgets                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch fgets\n", rct);
    }

    p = strstr(p_string, "fgets");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_fgets #100\n", rct);
      }

      c2_fgets();
      var_use[18]++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out gets                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch gets\n", rct);
    }

    p = strstr(p_string, "gets");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_gets #100\n", rct);
      }

      c2_gets();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out fputs                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch fputs\n", rct);
    }

    p = strstr(p_string, "fputs");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_fputs #100\n", rct);
      }

      c2_fputs();
      tot_fputs++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out getchar                                        *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch getchar\n", rct);
    }

    p = strstr(p_string, "getchar");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_getchar_punch #100\n", rct);
      }

      c2_getchar_punch();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out atoi                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch atoi\n", rct);
    }

    p = strstr(p_string, "atoi");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_atoi #100\n", rct);
      }

      c2_atoi();
      var_use[13]++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out atof                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch atof\n", rct);
    }

    p = strstr(p_string, "atof");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_atof_punch #100\n", rct);
      }

      c2_atof_punch();
      var_use[13]++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out atol                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch atol\n", rct);
    }

    p = strstr(p_string, "atol");
    if (p) {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_atof_punch #100\n", rct);
      }

      c2_atol_punch();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out double                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch double\n", rct);
    }

    p = strstr(p_string, "double");
    p1 = strstr(p_string, "/*");
    v = p_string - p;
    s = p_string - p1;

    if (v < 0) 
    {
      v = 9999;
    }

    if (s < 0) 
    {
      s = 9999;
    }

    if ((p) && (v < s)) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_double_punch #100\n", rct);
      }

      c2_double_punch();
     
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out strncpy                                        *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch strncpy\n", rct);
    }

    p = strstr(p_string, "strnccpy");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_strncpy #100\n", rct);
      }

      c2_strncpy();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out strset                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch strset\n", rct);
    }

    p = strstr(p_string, "strset");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_strset #100\n", rct);
      }

      c2_strset();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch strrev                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch strrev\n", rct);
    }

    p = strstr(p_string, "strrev");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_strrev #100\n", rct);
      }

      c2_strrev();
      convert = 1;
    }


    /* **********************************************************
    *  Punch out LOCALTIME     MUST BEFORE TIME                 *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch localtime\n", rct);
    }

    p = strstr(p_string, "localtime");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_localtime #100\n", rct);
      }

      c2_localtime();
      tot_localtime++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out CTIME                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch ctime\n", rct);
    }

    p = strstr(p_string, "ctime");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_ctime #100\n", rct);
      }

      c2_ctime();
      tot_localtime++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out time_t                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch time_t\n", rct);
    }

    p = strstr(p_string, "time_t");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_time_t #100\n", rct);
      }

      c2_time_t_punch();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out TIME                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch time\n", rct);
    }

    p = strstr(p_string, "time");
    if (p) 
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_time #100\n", rct);
      }

      c2_time();
      tot_time++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch clock                                              *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch clock\n", rct);
    }

    p = strstr(p_string, "clock");
    if (p) 
    {
      c2_clock_punch();
      convert = 1;
    }


    /* **********************************************************
    *  Punch out exit                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch exit\n", rct);
    }

    p1 = strstr(p_string, ";");
    p = strstr(p_string, "exit");

    v = p_string - p;
    s = p_string - p1;

    if(v < 0)
    {
      v = 9999;
    }
 
    if(s < 0)
    {
      s = 9999;
    }

    if (p)  
    {
      if (debug_lv >= 2) 
      {
        printf("c2z.c Pass 3 rct = %d c2_exit #100\n", rct);
      }

      c2_exit();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out function start                                 *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch void function\n", rct);
    }

    p = strstr(p_string, "void");
    p1 = strstr(p_string, "(");

    if ((p) && (p1)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c Function Start");
        trace_rec_1();
      }

      /* convert = 1; */
    }


    /* **********************************************************
    *  Punch out function call                                  *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch function call\n", rct);
    }

    for (I = 0; I < fns_ct; I++) 
    {
      if ((rct == w_func_start[I].fns_rct) && (convert == 0)) 
      {
        if (debug_lv >= 2) 
        {
          printf("c2z.c Pass 3 rct = %d c2_exit #100\n", rct);
        }

        c2_func_call();
        convert = 1;
        if (return_on == 1) 
        {
          return_ct++;
        }
        break;
      }
    }


    /* **********************************************************
    *  Punch out toupper                                        *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch toupper\n", rct);
    }

    p = strstr(p_string, "toupper");
  
    if (p) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c toupper Start");
        trace_rec_1();
      }
   
      c2_toupper();
      work_use_ct[90]++;
      convert = 1; 
    }



    /* **********************************************************
    *      Math functions ( =, +, -, *, / ) MUST BE LAST CALL   * 
    *              	         IN PARSER EXECPT FOR REMARK CHECK *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch math functions\n", rct);
    }

    if (convert == 0) 
    {
      p = strstr(p_string, "=");
      p1 = strstr(p_string, "/*");

      v = p - p_string;
      if (v < 0) 
      {
        v = 9999;
      }

      s = p1 - p_string;
      if (s < 0) 
      {
        s = 9999;
      }

      x = 0;
      p1 = strstr(p_string, "+");
      if(p1)
      {
        x++;
      }

      p1 = strstr(p_string, "-");
      if(p1)
      {
        x++;
      }

      p1 = strstr(p_string, "*");
      if(p1)
      {
        x++;
      }

      p1 = strstr(p_string, "/");
      if(p1)
      {
        x++;
      }

      if((p) && (v < s) && (x > 0) && (convert == 0)) 
      {
        if (debug_lv >= 2) 
        {
          printf("c2z.c Pass 3 rct = %d c2_math #100\n", rct);
        }
 
        c2_math();   
     
        convert = 1;
        if (return_on == 1) 
        {
          return_ct++;
        }
      }

      if((p) && (v < s) && (x == 0) && (convert == 0)) 
      {
        if (debug_lv >= 2) 
        {
          printf("c2z.c Pass 3 rct = %d c2_math #100\n", rct);
        }
        c2_math(); 
        convert = 1;
        if (return_on == 1) 
        {
          return_ct++;
        }

       /* c2_math_start(); */

      }

    }

    /* ************************************************************************
    *  If inside_main == 0 & parm_ct == 0, then the end of main loop of the C *
    *  program has been reached.  Punch out the end statement and all defines *
    *  before processing an functions that may be defined.                    *
    * *********************************************************************** */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (debug_lv >= 2) 
    {
      printf("c2z.c Pass 3 rct = %d Punch end of main loop\n", rct);
    }

    if (parm_ct < 0)
    {
      parm_ct = 0;
    }
  
    if ((convert == 0) && (inside_main == 1) && (parm_ct == 0)) 
    {
      inside_main = 0;

      strcpy(a_string, "C370EXIT DS    0H");
      src_line();
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 punch C370EXIT");
        trace_rec_3();
      }

      strcpy(a_string, "         SUBEXIT");
      src_line();
      var_use[1]++;
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z.c pass 3 punch subexit");
        trace_rec_3();
      }

      strcpy(a_string, "*");
      src_line();
      var_use[1]++;
      inside_main = 0;

      convert = 1;
    }



  /* ************************************************************
  *      end of while loop for Pass 3, punching out ASM code    *
  * *********************************************************** */

  end_pass3:

    if (end_input == 1) 
    {
      break;
    }

    if((convert == 0) && (bracket_convert == 0))
    {
       if (bad_rec_ct == 0) 
       {
         size = 1;
         w_bad_rec = malloc(size * sizeof(struct bad_rec));
       } 
       else 
       {
         size = bad_rec_ct + 1;
         w_bad_rec = realloc(w_bad_rec, size * sizeof(struct bad_rec));
       }

       w_bad_rec[bad_rec_ct].bad_rct = rct;
       strcpy(w_bad_rec[bad_rec_ct].bad_string, p_string);
       bad_rec_ct++;
    }

  }

  /**************************************************************
  *      Call c2_eoj to punch out end-of-program code.        
  * *********************************************************** */

  if (debug_lv >= 2) 
  {
    printf("c2z.c Pass 3 rct = %d Punch eoj code\n", rct);
  }

  c2_eoj();

  if(erct != 0)
  {
    printf("\nPass 3 FAILED with %d erros.\n\n",erct);
  }

  exit(0);
}
