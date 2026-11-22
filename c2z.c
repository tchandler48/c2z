/* *************************************************************
*  c2z.c Parser                                                *
*  Copyright TCCS (c) 2015 - 2026                              *
* ************************************************************ */

/* *************************************************************
*  GENERAL NOTES -                                             *
*							       *
*  Dsect Arrarys MUST have the gw_variable[x].gv_flag to 1 so  *
*  	Dsect address reset will take place.                   *
*							       *
* ************************************************************ */

#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*            c2z_arth.c                */
       void c2z_math_startxx(void);


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
        void c2_char_10(void);
        void c2_char_punch(void);


/*		c2z_const.c		*/
	void c2_const(void);


/*		c2z_ctime.c		*/
	void c2_date(void);
        void c2_time(void);
 

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


/*             c2z_fs.c                 */
        void c2_fs_1(void);
        void c2_fs_2(void);
        void c2_fs_3(void);
        void c2_fs_4(void); 
        void c2_fs_5(void);


/* 	       c2z_function.c           */
	void c2_func_call(void);	
	void c2_func_end(void);
	void c2_func_sub(void);
	void c2_scan_func(void);
	void c2_scan_sub(void);
        void scan_func_name_1(void);

/*		c2z_goto.c 		*/
	void c2_goto(void);
	void c2_goto_label(void);
        void c2_goto_pass2(); 
        void c2_goto_pass2_label(); 



/* 	       c2z_if.c                 */
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


/*		c2z_incr.c		*/
	void c2_plus(void);


/* 	       c2z_int.c		*/
	void c2_int(void);
	void c2_int_1(void);
	void c2_int_2(void);
	void c2_int_3(void);
	void c2_int_5(void);
	void c2_int_6(void);
        void c2_int_10(void);
	void c2_int_punch(void);
	void c2_int_punch_1(void);
	void c2_int_punch_2(void);

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


/*            c2z_main.c                */
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
        void c2_math_100(void);


/*              c2z_mthst.c            */
        void c2_math_start(void);
        void c2_math_rdp(void);
        void c2_RDO001(void);		/* Expression */



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


/* 	       c2z_math_func.c          */
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
	

/*            c2z_mparser.c             */
        void c2_mparser(void);


/* 	       c2z_paramaters.c         */
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
        void c2_pass2_if_6(void);
        void c2_pass2_if_7(void);
        void c2_pass2_if_10(void);
	void c2_pass2_if_13(void);
	void c2_pass2_if_15(void);
	void c2_pass2_while(void);
	void c2_pass2_while_1(void);
	void c2_pass2_while_2(void);
        void c2_pass2_while_4(void);
	void c2_pass2_while_5(void);
        void c2_pass2_while_7a(void);
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
      

/* 	       c2z_pass_3.c		*/
        void c2_pass_3(void);

/*                                      */
	void c2_return(void);

/* 	       c2z_print.c		*/
	void c2_fprintf(void);
	void c2_printf(void);
        void c2_printf_literal(void);
	void c2_printf_numeric(void);
	void c2_printf_string(void);
	void c2_printf_dec_only(int);
	void c2_snprintf(void);
        void c2_printf_float(void);


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


/*		c2z_struct.c		*/
	void c2z_struct(void);
	void c2_struct_3(void);
        void c2_struct_4(void);


/* 	       c2z_unsigned.c           */
	void c2_unsigned(void);
        void c2_unsigned_punch(void);


/*            c2z_utility.c             */
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


/* 	       c2z_while.c		*/
	void c2_while(void);
	void c2_while_1(void);
	void c2_while_2(void);
	void c2_while_3(void);
	void c2_while_4(void);
	void c2_while_5(void);
	void c2_while_6(void);
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
        void c2_while_20(void);

/* 	       math processing           */

       void c2_rdp_main(void);
        int Term(void);
        int Factor(void);
       void _GetChar(void);
       void Match(char);
        int Is_White(char);
       void SkipWhite(void);
        int GetNum(void);
        int IsAddop(char);
        int IsMultop(char);
        int get_varvalue(void);


/* ------ SYSTEM CONSTANTS ------- */
#define IOARRAY	        99
#define PATH		129
#define BUFSIZE	        80
#define VAR_LGTH	64        /* lGth of field/procedure names */
#define IBMSZ           9         /* size of IBM 370 fields */

#define ARRAY_SIZE      30        /* # of array rcds */


/* ------ STRUCTURE COUNTERS ----- */
 int lit_ct = 0;                  /* variable count - w_char_lit */
 int f_ct = 0;                    /* variable count - w_file opens */
 int fn_ct = 0;                   /* variable count - w_function */
 int fs_field_ct = 0;             /* variable count - w_fs_field */
 int fs_aid_ct = 0;               /* varialbe count - w_fs_aid */
 int fs_map_ct = 0;               /* variable count - w_fs_map */
 int w_gtolabel_ct = 0;
 int gv_ct = 0;                   /* variable count - gw_variable */
 int lv_ct = 0;                   /* variable count - lw_variable */
 int m_struc_ct = 0;              /* m_struct counter */
 int v_const = 0;                 /* variable count - w_constant */
 int T32_ct = 0;


 int arry_sz = 30;                /* array records total */



/* ------ FILE POINTERS ---------- */
FILE *c_h; 
FILE *c_src;                      /* generated source file */
FILE *c_tmp;
FILE *cc370;                      /* asm output file */
FILE *err;                        /* generated error message file */
FILE *pgm;
FILE *src_cp;                     /* copy source file into ASM file */
FILE *src_out;                    /* output of source file copy */
FILE *c_nc;                       /* not sure may remove as used in fs */


/* ------ global INT vars -------- */
int convert = 0;                  /* flag converted line */
int rct = 0;                      /* record count */
int wh_ct_1 = 0;
int wh_ct_2 = 0;
int wh_ct_3 = 0;
int wh_ct_4 = 0;
int wh_ct_5 = 0;
int wh_ct_6 = 0;
int wh_ct_7 = 0;
int wh_ct_8 = 0;
int wh_ct_9 = 0;
int wh_ct_10 = 0;

int if_ct_1 = 0;
int if_ct_2 = 0;
int if_ct_3 = 0;
int if_ct_4 = 0;
int if_ct_5 = 0;
int if_ct_6 = 0;
int if_ct_7 = 0;
int if_ct_8 = 0;
int if_ct_9 = 0;
int if_ct_10 = 0;

int sv_ct = 0;			  /* sv r14 return ct  */
int tcxyz = 0;

/*  full screen (fs) */
  int fsaid_ct = 0;
  int w_lgth = 0;
  int T3270_ct = 0;
  int scr_loop_ct = 0;
 char T3270[1922][5];


/* ------ global CHAR vars ------- */
char a_string[BUFSIZE];           /* file output string */
char p_string[BUFSIZE];           /* file input string */
char start_whle[12];
char sv_func[VAR_LGTH];           /* save the func var is in */
char wh_lb_1[12];
char wh_lb_2[12];
char wh_lb_3[12];
char wh_lb_4[12];
char wh_lb_5[12];
char wh_lb_6[12];
char wh_lb_7[12];
char wh_lb_8[12];
char wh_lb_9[12];
char wh_lb_10[12];

char start_lb_1[12];
char start_lb_2[12];
char start_lb_3[12];
char start_lb_4[12];
char start_lb_5[12];
char start_lb_6[12];
char start_lb_7[12];
char start_lb_8[12];
char start_lb_9[12];
char start_lb_10[12];

char if_lb_1[12];
char if_lb_2[12];
char if_lb_3[12];
char if_lb_4[12];
char if_lb_5[12];
char if_lb_6[12];
char if_lb_7[12];
char if_lb_8[12];
char if_lb_9[12];
char if_lb_10[12];

char if_end_1[12];
char if_end_2[12];

char t_holder[VAR_LGTH];

char o_string[12];

/* remove after conversion */
 int traceflg = 0; 					
 int puncde = 0;   	
 int debug_lv = 0;
/* end of removal          */



/* ------ global array/structures- */
      int *iv_stack;
     char **in_stack;



/* ------ global vars ------------ */
char s_holder[BUFSIZE];   				/* xstring (print) data holder  		*/
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
char strtmp[128];
char c_output_file[24];
char c_wkname[24];
char sv_print_lit[VAR_LGTH];
char null_field[2];
char wk_fdwk[24];
char sub_name[24];
char wk_strg[8];     /* [24] */
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
char output_file[24];
char from_sv[24];

/* variables used for pointers into functions			*/
				
 int main_set = 0;
 int global_st = 0;
 int convert_ignore = 0; 				/* flag for comments & {} only		*/
 int if_convert = 0;     				/* if flag used in if_case routines	*/
 int return_on = 0;      				/* return flag				*/
 int return_ct = 0;      				/* count lines after return			*/
 int func_x1 = 0;        				/* function count start			*/
 int func_x2 = 0;        				/* function count stop			*/
 int def_it = 1;         				/* ifndef flag				*/
 int cary_ct = 0;
 int stru_ct = 0;
 int fake = 0;
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
 char ptr_lgth[6];
 int e_pos = 0;
 int line_ndx = 0;
 int x1001 = 0;
 
/* usage counters	*/
 int var_use[24];
/* **************************************************************
*  1	=	asmct			2	=	printf	*
*  3  	=       fprintf			4	=	branch	*
*  5	=	fopen			6	=	fclose	*
*  7	=	if			8	=	strcpy	*
*  9 	=	isalpha			10	=	isdigit	*
*  11 	=	isspace			12	=	isalnum	*
*  13 	=	atoi			14	=	free	*
*  15 	=	strcat			16	=	strlen	*
*  17 	=	define	        	18	=	fgets	*
*  19 	=	unsigned		20   	=	isupper	*
*  21   =       rdparser                                        *
*************************************************************** */

/* compiler generated fields usage counter */

int work_use_ct[88];
/* ****************************************************************
*   1		=	C370ISAL	2	=	C370L1    *
*   3 		=	C370L2		4	=	C370L3    *
*   5 		=	C370L4		6	=	C370L5	  *
*   7		=	C370L6		8	=	C370L8A   *
*   9		=	C370L8		10	=	C370L80   *
*  11		=	C370MTOT	12	=	C370THR   *
*  13		=	C370FOUR     	14	=	C370MT3   *
*  15		=	C370MT4		16	=	C370MT5	  *
*  17		=	C370PTOT	18	=	C370PT1	  *
*  19		=	C370PT2		20	=	C370PT3	  *
*  21		=	C370PT4		22	=	C370PT5	  *
*  23  		=	C370CLCT	24	=       C370FIVE  *
*  25		=	C370EDW2	26      =       C370RET   *
*  27	        =       DATE            28	=	TIME      *
*  29		=	SAVEAREA	30	=	C370DTIM  *
*  31		=	C370PTIM	32	=	C370ZERO  *
*  33		=	C370ONE		34	=	C370TWO	  *
*  35		=	C370UCA		36	=	C370UCZ	  *
*  37		=	C370LCA		38	=	C370LCZ	  *
*  39		=	C370MATH     	40	=	C370DEND  *
*  41		=	C370IENT	42	=	REMAINDER *
*  43		=	C370ISOR	44	=	C370MLT1  *
*  45		=	C370MLT2	46	=	C370MLT3  *
*  47		=	C370TWRK	48	=	C370U	  *
*  49		=	C370NWK1	50	=	C370NWK2  *
*  51     	=			52	=	C370B1 	  *
*  53		=	C370B8		54	=	C370L10	  *
*  55					56	                  *
*  57					58			  *
*  59		=	C370L1A		60	=	C370TDD3  *
*  61		=	C370D3DW     	62	=	WKAR1     *
*  63		=	C370LNIN	64	=	FW00XX004 *
*  65		=	C370NN3      	66	=	MLF001    *
*  67		=	MLF002		68	=	MLF003    *
*  69		=	MLF004		70	=	MLF005    *
*  71 		                        72	=	C370XXX	  *
*  73		=	C370LPCT	74	=	C370EOF	  *
*  75		=	C370PER		76	     	          *
*  77			    		78	=	C370NWK3  *
*  79		=	C370FONE	80	=       C370DIGT  *
*  81		=	C370COLN      	82      =       C370NONE  *
*  83         	      			84                        *
*  85         	=       C370DTTM      	86      =       C370ECB   *
***************************************************************** */

 int tot_localtime = 0;
 int tot_int = 0;
 int tot_char = 0;
 int tot_goto = 0;
 int tot_float = 0;

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
 int strx30 = 0;


 int array_rows = 17; 				/* array row count			*/

/* used by if processing to detect end of if/else/while loop	*/
 int l_start[22];
 int l_type[22];
 int l_else[22];


 int if_level = 0;
 int array_clear = 0; 				/* flag to reset array address		*/
 int case_parm_ct = 0;
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
 int if_ct = 0, c_name = 0;
 int if_opr = 0;
 int if_active = 0;
 int else_active = 0;
 int if_else_ct = 0;
 int else_flag = 0;
 int void_ct = 0, math_case = 0, comma_found = 0;
 int inside_void = 0;
 int fprintf_lit = 0;
 int math_convert = 0;
 int printf_convert = 0;
 int atoi_pass = 0;
 int branch_done = 0;
 int sv_if_else_rec = 0;
 int sv_else_ct = 0, end_strg = 0;
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
 int fprintf_flag = 0;
 int non_process = 0;
 int open_ct = 0, end_input = 0;
 int use_atoi = 0, use_mult = 0, localtime_usect = 0;
 int loop_strcmp = 0, i_ct = 0;
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
  char gv_cname[IBMSZ];
  char gv_type[2];
   int gv_lgth;
   int gv_current_lgth;
  char gv_value[VAR_LGTH];
   int gv_init;
  char gv_literal[BUFSIZE];
   int gv_use_ct;
  char gv_dsect[IBMSZ];    /* A371T */
   int gv_row;
   int gv_column;
  char gv_label[IBMSZ];
  char gv_table[IBMSZ];    
  char gv_aname[IBMSZ];
  char gv_sv_reg[IBMSZ];
  char gv_wk_reg[IBMSZ];
  char gv_wk_strg[IBMSZ];  /* A371N */
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

struct fs_map
{
    int fs_rct;
   char fs_name[VAR_LGTH];
   char fs_cname[VAR_LGTH];
   char fs_map_func[VAR_LGTH];
};
struct fs_map *w_fs_map;


struct fs_field
{
   int fs_fd_rct;
  char fs_fd_map[VAR_LGTH];
  char fs_fd_name[VAR_LGTH];
  char fs_fd_cname[VAR_LGTH];
  char fs_fd_io[2];
  char fs_fd_type[2];
  char fs_fd_field[VAR_LGTH];  
   int fs_fd_row;		   
   int fs_fd_col;
   int fs_fd_lgth;		   
  char fs_fd_color[VAR_LGTH];
  char fs_fd_address[5];
  char fs_fd_attr[3];
  char fs_fd_func[VAR_LGTH];
};
struct fs_field *w_fs_field;

struct fs_scr_field
{
   char fs_scr_map[VAR_LGTH];
   char fs_scr_name[VAR_LGTH];
   char fs_scr_cname[VAR_LGTH];
};
struct fs_scr_field *w_fs_scr_field;

struct fs_fsaid
{
   char fs_fsaid_map[VAR_LGTH];
   char fs_fsaid_attr[VAR_LGTH];
   char fs_fsaid_label[VAR_LGTH];
};
struct fs_fsaid *w_fs_fsaid;


struct gto_label 
{
   int gto_label_rct;
  char gto_org_lb[VAR_LGTH];
  char gto_label_1[VAR_LGTH];
};
struct gto_label *w_gto_label;


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
#include "c2z_fs.c"
#include "c2z_function.c"
#include "c2z_goto.c"
#include "c2z_if.c"
#include "c2z_incr.c"
#include "c2z_int.c"
#include "c2z_isalnum.c"
#include "c2z_isspace.c"
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
#include "c2z_rdparser.c"
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
#include "c2z_unsigned.c"
#include "c2z_utility.c"
#include "c2z_while.c"

int main(int argc, char *argv[]) 
{
  char *p;
  char *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10;
  char ch;
  char filename[VAR_LGTH];
  char asm_file_1[VAR_LGTH];
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
  int bk1 = 0;
  int bk2 = 0;
  int bk3 = 0;
  
  if (argc > 2) 
  {
    p = strstr(argv[2], "-d");
    if (p) 
    {
      strcpy(tfield1, argv[2]);
      tfield1a[0] = tfield1[2];
      tfield1a[1] = '\0';
    }
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

  strcat(asm_file, ".MLC");
  strcpy(asm_file_1, asm_file);
   
  printf("***********************************************\n");
  printf("*  c2z Starting Execution                     *\n");
  printf("*  Version 0.1.00 - 11/01/2026                *\n");
  printf("*  Copyright (C) TCCS 2015 - 2026             *\n");
  printf("*  c2z Z390 Pass 1 Started                    *\n");

  pgm = fopen(filename, "rb");
  c_tmp = fopen("tmp.c", "wb");

  strcpy(trcfile, wk_file);
  strcat(trcfile, ".TRC");
  c_src = fopen(trcfile, "w");

  i_ct = 0;
  rct = 0;
  while (1) 
  {
    fgets(p_string, BUFSIZE, pgm);

/* printf("c2z.c Pass 1 rct = %d p_string = %s",rct,p_string); */

    rct++;

    if (feof(pgm)) 
    {
      break;
    }

    p1 = strstr(p_string, "\"");
    ret = strncmp("#include", p_string, 8);
    if ((ret == 0) && (p1)) 
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
        while (fgets(p_string, BUFSIZE, c_h) != NULL) 
        {
          scan_func_name_1(); 
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
    if (skip_read == 0) 
    { 
      fgets(p_string, BUFSIZE, pgm); 
      rct++;
    }  

/* printf("c2z Pass 2 rct = %d erct = %d p_string = %s\n",rct,erct,p_string); */

    x1001 = strlen(p_string);

    convert = 0;
    fprintf_flag = 0;

    skip_read = 0;

    if (global_st == 0) 
    {
      sv_func[0] = '\0';
    }

    convert = 0;
    skip_read = 0;

    /* **********************************************************
    *  Scan for { }                                             *
    * ********************************************************* */
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
      strcpy(trace_1, "c2z.c Pass 2 { }");
      trace_rec_1();
      c2_param_ct();
    }

    if(skip_read == 1)
    {
       goto pass2_skip;
    }


    /* **********************************************************
    *  Scan for MAIN in C program and set sv_func               *
    * ********************************************************* */
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
   
        strcpy(trace_1, "c2z pass 2 MAIN");
        trace_rec_1();
        inside_main = 1;
        strcpy(sv_func, "main");
        c2_main();
        global_st = 1;
        mainflg = 1;
      }
    }


    /* **********************************************************
    *  Scan for malloc                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "malloc");
    p1 = strstr(p_string, "#include");

    if ((p) && (!p1)) 
    {
      /* c2_scan_malloc(); */
      convert = 1;
    }


    /* **********************************************************
    *  Scan for realloc                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "realloc");
    p1 = strstr(p_string, "#include");

    if ((p) && (!p1)) {
      /* c2_scan_realloc();  */
      convert = 1;
    }


    /* **********************************************************
    *  Scan for struct                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "struct");
    p1 = strstr(p_string, "_struct");
    p2 = strstr(p_string, "accept");
    p3 = strstr(p_string, ";");

    if ((p) && (!p1) && (!p2) && (!p3)) 
    {
      strcpy(trace_1, "c2z.c pass 2 struct #1");
      trace_rec_1();
      c2z_struct();
      convert = 1;
    }

    if ((p) && (!p1) && (!p2) && (p3)) 
    {
      strcpy(trace_1, "c2z.c pass 2 struct #2");
      trace_rec_1();
      c2_struct_4();     
      convert = 1;
    }


    /* **********************************************************
    *  Scan for prototypes                                      *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
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
      strcpy(trace_1, "c2z pass_2 prototype (char) #101");
      trace_rec_1();
      scan_func_name_1();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 2) && (p1) && (p5) && (p6) && (!p8) && (convert == 0)) 
    {
      strcpy(trace_1, "c2z pass_2 prototype (int) #102");
      trace_rec_1();
      scan_func_name_1();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 3) && (p1) && (p5) && (p6) && (convert == 0)) 
    {
      strcpy(trace_1, "c2z pass_2 prototype (void) #103");
      trace_rec_1();
      scan_func_name_1();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 4) && (p1) && (p5) && (p6) && (convert == 0)) 
    {
      strcpy(trace_1, "c2z pass_2 prototype (double) #104");
      trace_rec_1();
      scan_func_name_1();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 5) && (p1) && (p5) && (p6)) 
    {
      strcpy(trace_1, "c2z pass_2 prototype (long) #105");
      trace_rec_1();
      scan_func_name_1();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for subroutines                                     *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
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
      strcpy(trace_1, "c2z pass_2 subroutine #200");
      trace_rec_1();
      c2_int_3();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 2) && (!p1) && (p5) && (p6) && (convert == 0)) 
    {
      strcpy(trace_1, "c2z pass_2 subroutine #202");
      trace_rec_1();
      c2_int_3();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 3) && (!p1) && (p5) && (p6) && (convert == 0)) 
    {
      strcpy(trace_1, "c2z pass_2 subroutine #203");
      trace_rec_1();
      c2_int_3();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 4) && (!p1) && (p5) && (p6) && (convert == 0)) 
    {
      strcpy(trace_1, "c2z pass_2 subroutine #204");
      trace_rec_1();
      c2_int_3();
      convert = 1;
    }

    if (convert == 1)
    {
      goto pass2_skip;
    }

    if ((x1 == 5) && (!p1) && (p5) && (p6)) 
    {
      strcpy(trace_1, "c2z pass_2 subroutine #205");
      trace_rec_1();
      c2_int_3();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for INT (NOT MAIN)                                  *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
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
        strcpy(trace_1, "c2z scan char c2_int START");
        trace_rec_1();
        c2_int();
        convert = 1;
      }
    }

    ret = strcmp(tfield1, "cha");
    if (ret == 0) 
    {
      strcpy(trace_1, "c2z scan char c2_char START");
      trace_rec_1();
      c2_char();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for size_t                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "size_t");
    if(p)
    {
      convert = 1;
    }


    /* **********************************************************
    *  Scan for while                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    while_convert = 0;

    p = strstr(p_string, "while");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 while");
      trace_rec_1();
      
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

      c2_pass2_while();
    }


    /* **********************************************************
    *  Scan for switch                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    switch_convert = 0;

    p = strstr(p_string, "switch");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 switch");
      trace_rec_1();
      
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

     }


    /* **********************************************************
    *  Scan for fprintf                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "fprintf");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 fprintf");
      trace_rec_1();
      
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


      /* ********************************************************
      *  copy from strstart to strstop into storage             *
      * ******************************************************* */
      s = 0;
      x4 = 0;
      x2 = 0;
      if ((strstart > 0) & (strstop > 0)) 
      {
        strstart++;
        for (indx = strstart; indx < strstop; indx++) 
        {
          ch = p_string[indx];
          /* *******************************************************************
          *  Test of c format charater '\' if, found do not copy and then      *
          *  skip the next character.  ex (print\n). Drop the \n as it is      *
          *  c formating string.                                               *
          * ****************************************************************** */

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


      /* ********************************************************
      *  Optimize LXX table                                     *
      * ******************************************************* */
/*
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
*/

      /* ********************************************************
      *  update the struct with literal                         *
      * ******************************************************* */
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
      gw_variable[gv_ct].gv_dec = 0;
      gv_ct++;

      fprintf_flag = 1;
      convert = 1;
    }


    /* **********************************************************
    *  Scan for printf                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    x3 = 0;
    p = strstr(p_string, "printf");
    if (p) 
    {
      strcpy(trace_1, "c2z scan printf");
      trace_rec_1();
      
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


      /* ********************************************************
      *  copy from strstart to strstop into storage             *
      * ******************************************************* */
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
      
      y0 = 0;

      /* ********************************************************
      *  update the struct with literal                         *
      * ******************************************************* */
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
      gw_variable[gv_ct].gv_dec = 0;
      gw_variable[gv_ct].gv_id = 5;
      gv_ct++;
      strcpy(strtmp, null_field);
    
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


    /* **********************************************************
    *  Scan for free                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "free");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z pass 2 scan free");
      trace_rec_1();
    }



    /* **********************************************************
    *  Scan for goto label  :                                   *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, ":");
    p1 = strstr(p_string, "case");
    p2 = strstr(p_string, "default:");
    p3 = strstr(p_string, "':");
    if((p) && (!p1) && (!p2) && (!p3)) 
    {
       c2_goto_pass2_label();
       convert = 1;
    }


    /* **********************************************************
    *  Scan for #define                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "#define");
    if (p) 
    {
      if (def_it == 1) 
      {
        c2_define();
      }
      convert = 1;
    }


    /* **********************************************************
    *  Scan for #ifndef                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "#ifndef");
    if (p) 
    {
      strcpy(trace_1, "c2z pass_2 #ifndef");
      trace_rec_1();
      c2_ifndef();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for #endif                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "#endif");
    if (p) 
    {
      strcpy(trace_1, "c2z pass_2 #endif");
      trace_rec_1();
      c2_endif();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for user VOID FUNCTION code                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
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

    p = strstr(p_string, "date");
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

    p = strstr(p_string, "puts");
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

    p = strstr(p_string, "time");
    if ((p) && (v_convert == 0))
    {
      v_convert = 1;
    }

    p = strstr(p_string, "tolower");
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

    if (v_convert == 0) 
    {
       c2_scan_sub();
    }

  vf_convert:


    /* **********************************************************
    *  Scan for enum                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "enum");
    if (p) 
    {
      c2_enum_scan();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for for                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
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


    /* **********************************************************
    *  Scan for if                                              *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p8 = strstr(p_string, "if");
    s = p8 - p_string;
    p8 = strstr(p_string, "/*");
    v = p8 - p_string;

    if (v < 0) 
    {
      v = 9999;
    }

    p = strstr(p_string, "_if");
    if(p)
    {
      goto if_loop_67;
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
      strcpy(trace_1, "c2.c pass 2 scan IF");
      trace_rec_1();
      
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

      c2_pass2_if();

    if_loop_67:
      convert = 1;
    }


    /* **********************************************************
    *  Scan for malloc  (skip)                                  *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "malloc");
    p1 = strstr(p_string, "#include");

    if ((p) && (!p1)) 
    {
      /* c2_scan_malloc();
      convert = 1; */
    }


    /* **********************************************************
    *  Scan for remove                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "remove");
    if (p) 
    {
      strcpy(trace_1, "c2z scan remove");
      trace_rec_1();
      c2_file_remove();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for break                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "break");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z pass 2 scan break");
      trace_rec_1();
    }


    /* **********************************************************
    *  Scan for return                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "return;");
    if(p)
    {
      convert = 1;
    }

    p = strstr(p_string, "return ");
    if((p)  && (convert == 0))
    {
      strcpy(trace_1, "c2z pass 2 scan return");
      trace_rec_1();
      c2_return_2();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for exit                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "exit");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z pass 2 scan exit");
      trace_rec_1();
    }



    /* **********************************************************
    *  Scan for tolower                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "tolower");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z pass 2 tolower");
      trace_rec_1();
    }


    /* **********************************************************
    *  Scan for toupper                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "toupper");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z pass 2 toupper");
      trace_rec_1();
    }


    /* **********************************************************
    *  Scan for ++                                              *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "++;");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z pass 2 scan ++");
      trace_rec_1();
    }


    /* **********************************************************
    *  Scan for --                                              *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "--");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z pass 2 scan --");
      trace_rec_1();
    }


    /* **********************************************************
    *  Scan for strcpy                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "strcpy");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z pass_2 scan strcpy");
      trace_rec_1();
      c2_strcpy_pass2();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for strcat                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "strcat");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z pass 2 scan strcat");
      trace_rec_1();
      c2_pass2_strcat();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for strstr                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "strstr");
    if (p) 
    {
      convert = 1;
      printf("c2z Pass 2 rct = %d c2_strstr #100\n", rct);
      c2_strstr_scan();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for FILE                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "FILE");
    if (p) 
    {
      strcpy(trace_1, "c2z scan FILE");
      trace_rec_1();
      c2_file();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for fopen                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "fopen");
    p1 = strstr(p_string, "fopen_");
    if ((p) && (!p1)) 
    {
      strcpy(trace_1, "c2z pass 2 scan fopen");
      trace_rec_1();
      c2_scan_fopen();
      open_ct++;
      convert = 1;
    }


    /* **********************************************************
    *  Scan for fclose                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
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
      strcpy(trace_1, "c2z pass 2 scan fclose");
      trace_rec_1();
      
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
        printf("c2z.c C2 SCAN FCLOSE ERROR!!\n");
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


    /* **********************************************************
    *  Scan for fgetc                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "fgetc");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 scan fgetc");
      trace_rec_1();
      c2_fgetc_pass2();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for fgets                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "fgets");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 scan fgets");
      trace_rec_1();
      c2_scan_fgets();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for fputs                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "fputs");
    if (p)
    {
      strcpy(trace_1, "c2.c pass 2 scan fputs");
      trace_rec_1();
      c2_scan_fputs();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for getchar                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "getchar");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 scan getchar");
      trace_rec_1();
      c2_getchar_pass2();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for int main                                        *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
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


    /* **********************************************************
    *  Scan for double                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
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
      strcpy(trace_1, "c2z pass 2 scan double");
      trace_rec_1();
      c2_double();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for float                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p8 = strstr(p_string, "float");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "float");
    if ((p) && (s < v)) 
    {
     c2_float();
      convert = 1;
    }


   /* ***********************************************************
    *  Scan for long                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p8 = strstr(p_string, "long");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "long");
    p7 = strstr(p_string, "_long");
    if ((p) && (!p7) && (s < v)) 
    {
      c2_long_pass2();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for cos                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p8 = strstr(p_string, "cos");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "cos");
    if ((p) && (s < v)) 
    {
      c2_cos_pass2();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for rand                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p8 = strstr(p_string, "rand");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "rand");
    if ((p) && (s < v)) 
    {
      c2_rand_pass2();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for pow                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p8 = strstr(p_string, "pow");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "pow");
    if ((p) && (s < v)) 
    {
      c2_pow_pass2();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for sin                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p8 = strstr(p_string, "sin");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "sin");
    if ((p) && (s < v)) 
    {
      c2_sin_pass2();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for sqrt                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p8 = strstr(p_string, "sqrt");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "sqrt");
    if ((p) && (s < v)) 
    {
      c2_sqrt_pass2();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for tan                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p8 = strstr(p_string, "tan");
    s = p8 - p_string;
    p7 = strstr(p_string, ";");
    v = p7 - p_string;

    p = strstr(p_string, "tan");
    if ((p) && (s < v)) 
    {
      c2_tan_pass2();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for unsigned                                        *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "unsigned");
    if (p) 
    {
      c2_unsigned();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for atof                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "atof");
    if (p)
    {
      c2_atof();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for case                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "case");
    p1 = strstr(p_string, "=");
    if ((p) && (!p1)) 
    {
      strcpy(trace_1, "c2z pass 2 scan case");
      trace_rec_1();
      c2_pass2_case();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for strcmp                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "strcmp");
    if (p) 
    {
      p1 = strstr(p_string, "\"");
      if (p1) 
      {
        strcpy(trace_1, "c2z pass 2 scan strcmp");
        trace_rec_1();
        
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


        /* ******************************************************
        *  update the struct with literal                       *
        * ***************************************************** */
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


    /* **********************************************************
    *  Scan for feof                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "feof");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 scan feof");
      trace_rec_1();
      c2_scan_feof();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for pid_t                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "pid_t");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 scan pid_t");
      trace_rec_1();
      /* c2_scan_pid_t();   */
      convert = 1;
    }


    /* **********************************************************
    *  Scan for accept                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "accept");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 scan accept");
      trace_rec_1();
      /* c2_scan_accept();   */
      convert = 1;
    }


    /* **********************************************************
    *  Scan for send                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "send");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 scan send");
      trace_rec_1();
      /* c2_scan_send();   */
      convert = 1;
    }


    /* **********************************************************
    *  Scan for pthread_create                                  *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "pthread_create");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 scan pthread_create");
      trace_rec_1();
      /* c2_scan_pthread_create();   */
      convert = 1;
    }


    /* **********************************************************
    *  Scan for strlen                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "strlen");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 scan strlen");
      trace_rec_1();
      c2_strlen_pass2();
      convert = 1;
    }

    /* **********************************************************
    *  Scan for sizeof                                          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "sizeof");
    if (p) 
    {
      strcpy(trace_1, "c2z pass 2 scan sizeof");
      trace_rec_1();
      c2_pass2_sizeof();
      convert = 1;
    }


    /* **********************************************************
    *  Scan for clock                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "clock");
    if (p) 
    {
        convert = 1;
    }


    /* **********************************************************
    *  Scan for goto                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
    }

    p = strstr(p_string, "goto");
    if (p) 
    {
       c2_goto_pass2(); 
       convert = 1;
    }


    /* **********************************************************
    *      Math literal  = MUST BE LAST CALL IN PARSER          *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto pass2_skip;
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

      c2_math_literal();


      c2_pass2_math();
      convert = 1;
    }


  /* ************************************************************
  *  End of while loop for PASS 2                               *
  * *********************************************************** */

    pass2_skip:
    ch = '\0';

  } 			/* end of first while */



  /* ************************************************************
  *  Test for balanced fopen & fclose                           *
  * *********************************************************** */

/*
  if (open_ct != 0) 
  {
    printf("Unbalanced fopen and fclose statements\n");
    printf("      Error at Line # - %d\n", rct);
   }
*/

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

  /* ************************************************************
  *  End of Pass 2 - scan parser                                *
  * *********************************************************** */

  if(erct != 0)
  {
    printf("\nPass 2 Failed with %d errors.\n",erct);
/*    c2_debug();
    exit(1);  */
  }

  /* ************************************************************
  *  -- Code Generation - creating the xxxx.mlc file        *
  * *********************************************************** */

  printf("*  c2z Z390 Pass 3 Started                    *\n");

  pgm = fopen("srcformat.c", "r");
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

/*
  if (traceflg == 1) 
  {
    strcpy(trace_2, "\n");
    trace_1[0] = '\0';
    trace_rec_1();
    strcpy(trace_2, "3");
  }
*/

  while (1) 
  {
    convert = 0;
    bracket_convert = 0;
    fprintf_lit = 0;
    math_convert = 0;
    fprintf_flag = 0;
    convert_ignore = 0;
    fgets(p_string, BUFSIZE, pgm);
    rct++;

/* printf("c2z pass 3 rct = %d p_string = %s",rct,p_string); */

    if (feof(pgm)) 
    {
      break;
    }

    s = strlen(p_string);

    if (s == 1) 
    {
      goto end_pass3;
    }

/*    strcpy(o_string, p_string); */
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
        strcpy(trace_1, "c2z pass 3 punch MAIN");
        trace_rec_1();
        
        inside_main = 1;
        strcpy(sv_func, "main");
        strcpy(from_sv, "main");
        global_st = 1;
        mainflg = 1;
        main_set = 1;

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
            strcat(p_string, w_struc[I].st_cwname);
            strcat(p_string, ")\n");
            c2_free();
          }
       }

       convert = 1; 
      }
    }



   /* ***********************************************************
    *  Punch tolower                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "tolower");
    if (p) 
    {
      pi2 = 0;
      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }
 
      pi2 = 0;
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
printf("c2z_lower tfield1 = %s\n",tfield1);


     x3 = 0;
     for(I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(tfield1, lw_variable[I].lv_name);
       if (ret == 0)
       {
         x3 = 1;
         strcpy(tfield1a, lw_variable[I].lv_cname);
         x1 = lw_variable[I].lv_lgth;
         lw_variable[I].lv_use_ct++;
       }
     }

     if(x3 == 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(tfield1, gw_variable[I].gv_name);
         if (ret == 0) 
         {
            x3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            x1 = gw_variable[I].gv_lgth;
            gw_variable[I].gv_use_ct++;
         }
       }
     }

     if (x3 == 0) 
     {
        printf("\nc2z #002 tfield1 Not Found = %s\n", tfield1);
        printf("c2zi rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
      }

      strcpy(a_string, "         LARL  R1,");
      strcat(a_string, tfield1a);
      strcat(a_string, " ");
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      strcpy(trace_1, "c2z pass 3 TOLOWER #1");
      trace_rec_3();

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      strcat(a_string, "     DS    0H");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #2");
      trace_rec_3();

      strcpy(a_string, "         ICM   R2,B'0001',0(R1)");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #3");
      trace_rec_3();

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "         JZ    L");
      strcat(a_string, wk_strg);
      strcat(a_string, "Z");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #4");
      trace_rec_3();

      strcpy(a_string, "* Check Block 1: 'A' (X'C1') through 'I' (X'C9')");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #5");
      trace_rec_3();

      strcpy(a_string, "         CHI   R2,X'C1'           Compare with 'A'");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #6");
      trace_rec_3();

      strcpy(a_string, "         JL    L14B   If lower than 'A', skip");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #7");
      trace_rec_3();

      strcpy(a_string, "         CHI   R2,X'C9'");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #8");
      trace_rec_3();

      strcpy(a_string, "         JH    L14B");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #9");
      trace_rec_3();

      strcpy(a_string, "         J     L14C");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #10");
      trace_rec_3();

      strcpy(a_string, "* Check Block 2: 'J' (X'D1') through 'R' (X'D9')");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #11");
      trace_rec_3();

      strcpy(a_string, "         CHI   R2,X'D1'           Compare with 'J'");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #11");
      trace_rec_3();

      strcpy(a_string, "         JL    L14B   lower than 'J' skip");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #12");
      trace_rec_3();

      strcpy(a_string, "         CHI   R2,X'D9'           Compare with 'Z'");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #13");
      trace_rec_3();

      strcpy(a_string, "         JH    L14C    If 'J' through 'R', convert");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #14");
      trace_rec_3();

      strcpy(a_string, "* Check Block 3: 'S' (X'E2') through 'Z' (X'E9')");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #15");
      trace_rec_3();

      strcpy(a_string, "         CHI   R2,X'E2'         Compare with 'S'");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #16");
      trace_rec_3();

      strcpy(a_string, "         JL    L14B");         
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #17");
      trace_rec_3();

      strcpy(a_string, "         CHI   R2,X'E9'");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #18");
      trace_rec_3();

      strcpy(a_string, "         JH    L14B");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #19");
      trace_rec_3();

      strcpy(a_string, "L14C     DS    0H");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #20");
      trace_rec_3();

      strcpy(a_string, "         NILF  R2,X'000000BF'");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #21");
      trace_rec_3();

      strcpy(a_string, "         STC   R2,0(R1)");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #22");
      trace_rec_3();

      strcpy(a_string, "L14B     DS    0H");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #23");
      trace_rec_3();

      strcpy(a_string, "         LA    R1,1(,R1)");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #24");
      trace_rec_3();

      strcpy(a_string, "         J     L14A");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #25");
      trace_rec_3();

      strcpy(a_string, "L14Z     DS    0H");
      src_line();
      strcpy(trace_1, "c2z pass 3 TOLOWER #26");
      trace_rec_3();

      convert = 1;
    }


   /* ***********************************************************
    *  Punch toupper                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "toupper");
    if (p) 
    {
      pi2 = 0;
      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }
 
      pi2 = 0;
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

     x3 = 0;
     for(I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(tfield1, lw_variable[I].lv_name);
       if (ret == 0)
       {
         x3 = 1;
         strcpy(tfield1a, lw_variable[I].lv_cname);
         x1 = lw_variable[I].lv_lgth;
         lw_variable[I].lv_use_ct++;
       }
     }

     if(x3 == 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(tfield1, gw_variable[I].gv_name);
         if (ret == 0) 
         {
            x3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            x1 = gw_variable[I].gv_lgth;
            gw_variable[I].gv_use_ct++;
         }
       }
     }

     if (x3 == 0) 
     {
        printf("\nc2z    #001 tfield1 Not Found = %s\n", tfield1);
        printf("c2zi rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
      }

      strcpy(a_string, "         LARL  R2,");
      strcat(a_string, tfield1a);
      strcat(a_string, " ");
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      strcpy(trace_1, "c2z pass 3 toupper #1");
      trace_rec_3();

      snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
      strcpy(a_string, "         LHI   R3,");
      strcat(a_string, wk_strg);
      src_line();
      strcpy(trace_1, "c2z pass 3 toupper #2");
      trace_rec_3();

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "F");
      strcat(a_string, "     OI    0(R2),X'40'");
      src_line();
      strcpy(trace_1, "c2z pass 3 toupper #3");
      trace_rec_3();

      snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
      strcpy(a_string, "         LA    R2,1(,R2)");
      src_line();
      strcpy(trace_1, "c2z pass 3 toupper #4");
      trace_rec_3();

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "         BRCT  R3,L");
      strcat(a_string, wk_strg);
      strcat(a_string, "F");
      src_line();
      strcpy(trace_1, "c2z pass 3 toupper #5");
      trace_rec_3();

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "Z");
      strcat(a_string, "     DS    0H");
      src_line();
      strcpy(trace_1, "c2z pass 3 toupper #6");
      trace_rec_3();
      convert = 1;
    }


    /* **********************************************************
    *  Test for prototypes                                      *
    *********************************************************** */
    p = strstr(p_string, "void");
    p1 = strstr(p_string, ";");
    p2 = strstr(p_string, "int");
    p3 = strstr(p_string, "(");
    p4 = strstr(p_string, ")");
    p5 = strstr(p_string, "printf");

    if ((p) && (!p1) && (!p5) && (p3) && (p4)) 
    {
      strcpy(trace_1, "c2z pass 3 Prototype #1");
      trace_rec_1();
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
      strcpy(trace_1, "c2z pass 3 Prototype #2");
      trace_rec_1();
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
      strcpy(trace_1, "c2z pass 3 Prototype #3");
      trace_rec_1();
      
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
      strcpy(trace_1, "c2z pass 3 Prototype #4");
      trace_rec_1();
      c2_func_sub();
      convert = 1;
   
    }

/*   if ((p2) && (p3) && (p4) && (!p) && (p1) && (!p5) && (convert == 0) && (s < v)) 
    {
      strcpy(trace_1, "c2z pass 3 Prototype #4c");
      trace_rec_1();
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
      strcpy(trace_1, "c2z pass 3 Prototype #5");
      trace_rec_1();
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
      strcpy(trace_1, "c2z pass 3 Prototype #6");
      trace_rec_1();
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
      strcpy(trace_1, "c2z pass 3 Prototype #7");
      trace_rec_1();
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

    p = strstr(p_string, "#define");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z.c pass 3 #define");
      trace_rec_1();
      return_ct++;
    }


    /* **********************************************************
    *  Punch #ifndef  (skip)                                    *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "#ifndef");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z pass 3 #ifndef");
      trace_rec_1();
      if (return_on == 1) 
      {
          return_ct++;
      }
    }


    /* **********************************************************
    *  Punch #endif  (skip)                                     *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "#endif");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z.c pass 3 #endif");
      trace_rec_1();
   
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch #include  (skip)                                   *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "#include");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z pass 3 test #include");
      trace_rec_1();
    }


    /* **********************************************************
    *  Punch FILE  (skip)                                       * 
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "FILE");
    if (p) 
    {
      convert = 1;
      strcpy(trace_1, "c2z pass 3 test file");
      trace_rec_1();
    }


    /* **********************************************************
    * Punch struct                                              *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "struct");
    if (p) 
    {
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

    p = strstr(p_string, "remove");
    if (p) 
    {
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

    p = strstr(p_string, "malloc");
    p1 = strstr(p_string, "#include");

    if ((p) && (!p1)) 
    {
      /* c2_scan_malloc(); */
      strcpy(trace_1, "c2z pass 3 test malloc");
      trace_rec_1();
      convert = 1;
    }


    /* **********************************************************
    *  Test for realloc                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "realloc");
    p1 = strstr(p_string, "#include");

    if ((p) && (!p1)) 
    {
      /* c2_scan_malloc(); */
      strcpy(trace_1, "c2z pass 3 test realloc");
      trace_rec_1();
      convert = 1;
    }


    /* **********************************************************
    * Test for int or char                                      *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
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
      c2_int_punch();

      if (return_on == 1) 
      {
        return_ct++;
      }
    }

    if ((p1) && (!p)) 
    {
      convert = 1;
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

    p = strstr(p_string, "case");
    if (p) 
    {
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

    p = strstr(p_string, "default");
    if ((p) && (if_case == 1)) 
    {
      strcpy(trace_1, "c2z pass 3 test default");
      trace_rec_1();
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

    p = strstr(p_string, "break");
    if ((p) && (if_case == 1)) 
    {
      c2_break();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
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

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_eof1) 
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, sv_for_incr);
        strcpy(wk_remark, " ");
        strcat(wk_remark, sv_for_incr);
        strcat(wk_remark, " */");
        write_remark();
        strcpy(trace_1, "c2z FOR/End Loop #1");
        trace_rec_3();
        
        strcpy(a_string, "         LARL  R7,C370ONE");
        strcpy(wk_remark, " C370ONE */");
        write_remark();
        strcpy(trace_1, "c2z FOR/End Loop #2");
        trace_rec_3();
        work_use_ct[33]++;
        
        strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
        src_line();
        strcpy(trace_1, "c2z FOR/End Loop #3");
        trace_rec_3();
        
        strcpy(a_string, "         JLU   ");
        strcat(a_string, sv_for_return);
        src_line();
        strcpy(trace_1, "c2z FOR/End Loop #4");
        trace_rec_3();
        
        strcpy(a_string, sv_for_return);
        strcat(a_string, "E");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        strcpy(trace_1, "c2z FOR/End Loop #5");
        trace_rec_3();
        
        convert = 1;
      }
    }


    /* **********************************************************
    *  Punch for                                                *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
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
      c2_for();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  test for { & }                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
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

          strcpy(trace_1, "c2z pass 3 test function_ct ");
          trace_rec_1();
               
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
        strcpy(trace_1, "c2z pass 3 test if_case { }");
        trace_rec_1();
        
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


    /* **********************************************************
    *  Punch IF statement                                       *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
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
      strcpy(trace_1, "c2z pass 3 test if #1");
      trace_rec_1();
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
    *  Punch fprintf                                            *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "fprintf");
    p1 = strstr(p_string, "snprintf");
    if ((p) && (!p1)) 
    {
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

    p = strstr(p_string, "printf");
    p1 = strstr(p_string, "snprintf");
    printf_convert = 0;
    if ((p) && (!p1) && (fprintf_flag != 1)) 
    {
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

    p1 = strstr(p_string, "snprintf");
    if (p1) 
    {
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

    p1 = strstr(p_string, "scanf");
    if (p1) 
    {
      strcpy(trace_1, "c2z pass 3 test scanf");
      trace_rec_1();
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

    p = strstr(p_string, "return");
    if (p) 
    {
      convert = 1;
      c2_return();
    }


    /* **********************************************************
    *  Punch switch                                             *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "switch");
    if (p)
    {
      c2_switch();
      tot_switch++;
      convert = 1;
      strcpy(trace_1, "c2z Punch SWITCH");
      trace_rec_1();
      
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

    p = strstr(p_string, "fclose");
    p1 = strstr(p_string, "_fclose");
    if ((p) && (!p1)) 
    {
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
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "close");
    if (p)
    {
       convert = 1;
    }


    /* **********************************************************
    *  Punch free                                               *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "free");
    if (p) 
    {
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

    p = strstr(p_string, "pthread");
    if (p) 
    {
      convert = 1;
    }


    /* ************************************************************************
    *  If inside_main == 0 & parm_ct == 0, then the end of main loop of the C *
    *  program has been reached.  Punch out the end statement and all defines *
    *  before processing an functions that may be defined.                    *
    * *********************************************************************** */
    if (parm_ct < 0)
    {
      parm_ct = 0;
    }

    if (convert == 1) 
    {
      goto end_pass3;
    }
    
    if ((convert == 0) && (inside_main == 1) && (parm_ct == 0)) 
    {
      inside_main = 0;

      strcpy(a_string, "C370EXIT DS    0H");
      src_line();
      strcpy(trace_1, "c2z pass 3 punch C370EXIT #1");
      trace_rec_3();

      strcpy(a_string, "         LARL  R11,INBUF");
      src_line();
      strcpy(trace_1, "c2z pass 3 punch TGET #2");
      trace_rec_3();
      work_use_ct[51]++;

      strcpy(a_string, "         LHI   R10,L'INBUF");
      src_line();
      strcpy(trace_1, "c2z pass 3 punch TGET #3");
      trace_rec_3();
      work_use_ct[51]++;

      strcpy(a_string, "         LR    R1,R11");
      src_line();
      strcpy(trace_1, "c2z pass 3 punch TGET #4");
      trace_rec_3();

      strcpy(a_string, "         OILH  R1,X'8000'");
      src_line();
      strcpy(trace_1, "c2z pass 3 punch TGET #5");
      trace_rec_3();

      strcpy(a_string, "         LR    R0,R10");
      src_line();
      strcpy(trace_1, "c2z pass 3 punch TGET #6");
      trace_rec_3();

      strcpy(a_string, "         SVC   93");
      src_line();
      strcpy(trace_1, "c2z pass 3 punch TGET #7");
      trace_rec_3();

      strcpy(a_string, "         SUBEXIT");
      src_line();
      strcpy(trace_1, "c2z pass 3 punch SUBEXIT #1");
      trace_rec_3();
  
      strcpy(a_string, "*");
      src_line();
      strcpy(trace_1, "c2z pass 3 punch SUBEXIT #2");
      trace_rec_3();
 
      inside_main = 0;
      convert = 1;
    }


    /* ***********************************************************
    *  test rct against wif_table eof1 & eof2                    *
    * ********************************************************** */
    if (convert == 1) 
    {
      goto end_pass3;
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
      if(if_ct_10 == 1)
      {
        strcpy(a_string, if_lb_10);
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        strcpy(trace_1, "c2z if end label-10 #3-10");
        trace_rec_3();
        if_lb_10[0] = '\0';
        if_ct_10 = 0;
        goto end_if_exit;
      }

      if(if_ct_9 == 1)
      {
        strcpy(a_string, if_lb_9);
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        strcpy(trace_1, "c2z if end label-9 #3-9");
        trace_rec_3();
        if_lb_9[0] = '\0';
        if_ct_9 = 0;
        goto end_if_exit;
      }

      if(if_ct_8 == 1)
      {
        strcpy(a_string, if_lb_8);
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        strcpy(trace_1, "c2z if end label-8 #3-8");
        trace_rec_3();
        if_lb_8[0] = '\0';
        if_ct_8 = 0;
        goto end_if_exit;
      }

      if(if_ct_7 == 1)
      {
        strcpy(a_string, if_lb_7);
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        strcpy(trace_1, "c2z if end label-7 #3-7");
        trace_rec_3();
        if_lb_7[0] = '\0';
        if_ct_7 = 0;
        goto end_if_exit;
      }

      if(if_ct_6 == 1)
      {
        strcpy(a_string, if_lb_6);
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        strcpy(trace_1, "c2z if end label-6 #3-6");
        trace_rec_3();
        if_lb_6[0] = '\0';
        if_ct_6 = 0;
        goto end_if_exit;
      }

      if(if_ct_5 == 1)
      {
        strcpy(a_string, if_lb_5);
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        strcpy(trace_1, "c2z if end label-5 #3-5");
        trace_rec_3();
        if_lb_5[0] = '\0';
        if_ct_5 = 0;
        goto end_if_exit;
      }

      if(if_ct_4 == 1)
      {
        strcpy(a_string, if_lb_4);
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        strcpy(trace_1, "c2z if end label-4 #3-4");
        trace_rec_3();
        if_ct_4 = 0;
        if_lb_4[0] = '\0';
        goto end_if_exit;
      }

      if(if_ct_3 == 1)
      {
        strcpy(a_string, if_lb_3);
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        strcpy(trace_1, "c2z if end label-3 #3-3");
        trace_rec_3();
        if_ct_3 = 0;
        if_lb_3[0] = '\0';
        goto end_if_exit;
      }

      if(if_ct_2 == 1)
      {

         strcpy(a_string, if_lb_2);
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        strcpy(trace_1, "c2z if end label-2 #3-2a");
        trace_rec_3();
        if_ct_2 = 0;
        if_lb_2[0] = '\0';
        goto end_if_exit;
      }

      if(if_ct_1 == 1)
      {
        strcpy(a_string, if_lb_1);
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        strcpy(trace_1, "c2z if end label-1 #3-1");
        trace_rec_3();
        if_ct_1 = 0;
        if_lb_1[0] = '\0';
      }

 end_if_exit:

    }

    if (wh_ct > 0) 
    {
      for (v = 0; v < wh_ct; v++) 
      {
        if (rct == w_while_table[v].wh_eof1) 
        {
          if(wh_ct_10 == 1)
          {
             strcpy(a_string, "         J     ");
             strcat(a_string, start_lb_10);
             src_line();
             strcpy(trace_1, "c2z while end label-10 #41-b");
             trace_rec_3();
             start_lb_10[0] = '\0';

             strcpy(a_string, wh_lb_10);
             check_length();
             strcat(a_string, "DS    0H");
             src_line();
             strcpy(trace_1, "c2z while end label-10 #41-a");
             trace_rec_3();
             wh_ct_10 = 0;
             wh_lb_10[0] = '\0';
             goto end_while_exit;
          }

          if(wh_ct_9 == 1)
          {
             strcpy(a_string, "         J     ");
             strcat(a_string, start_lb_9);
             src_line();
             strcpy(trace_1, "c2z while end label-9 #41-b");
             trace_rec_3();
             start_lb_9[0] = '\0';

             strcpy(a_string, wh_lb_9);
             check_length();
             strcat(a_string, "DS    0H");
             src_line();
             strcpy(trace_1, "c2z while end label-9 #41-a");
             trace_rec_3();
             wh_ct_9 = 0;
             wh_lb_9[0] = '\0';
             goto end_while_exit;
          }

          if(wh_ct_8 == 1)
          {
             strcpy(a_string, "         J     ");
             strcat(a_string, start_lb_8);
             src_line();
             strcpy(trace_1, "c2z while end label-8 #41-b");
             trace_rec_3();
             start_lb_8[0] = '\0';

             strcpy(a_string, wh_lb_8);
             check_length();
             strcat(a_string, "DS    0H");
             src_line();
             strcpy(trace_1, "c2z while end label-8 #41-a");
             trace_rec_3();
             wh_ct_8 = 0;
             wh_lb_8[0] = '\0';
             goto end_while_exit;
          }

          if(wh_ct_7 == 1)
          {
             strcpy(a_string, "         J     ");
             strcat(a_string, start_lb_7);
             src_line();
             strcpy(trace_1, "c2z while end label-7 #41-b");
             trace_rec_3();
             start_lb_7[0] = '\0';

             strcpy(a_string, wh_lb_7);
             check_length();
             strcat(a_string, "DS    0H");
             src_line();
             strcpy(trace_1, "c2z while end label-7 #41-a");
             trace_rec_3();
             wh_ct_7 = 0;
             wh_lb_7[0] = '\0';
             goto end_while_exit;
          }

          if(wh_ct_6 == 1)
          {
             strcpy(a_string, "         J     ");
             strcat(a_string, start_lb_6);
             src_line();
             strcpy(trace_1, "c2z while end label-6 #41-b");
             trace_rec_3();
             start_lb_6[0] = '\0';

             strcpy(a_string, wh_lb_6);
             check_length();
             strcat(a_string, "DS    0H");
             src_line();
             strcpy(trace_1, "c2z while end label-6 #41-a");
             trace_rec_3();
             wh_ct_6 = 0;
             wh_lb_6[0] = '\0';
             goto end_while_exit;
          }

          if(wh_ct_5 == 1)
          {
             strcpy(a_string, "         J     ");
             strcat(a_string, start_lb_5);
             src_line();
             strcpy(trace_1, "c2z while end label-5 #41-b");
             trace_rec_3();
             start_lb_5[0] = '\0';

             strcpy(a_string, wh_lb_5);
             check_length();
             strcat(a_string, "DS    0H");
             src_line();
             strcpy(trace_1, "c2z while end label-5 #41-a");
             trace_rec_3();
             wh_ct_5 = 0;
             wh_lb_5[0] = '\0';
             goto end_while_exit;
          }

          if(wh_ct_4 == 1)
          {
             strcpy(a_string, "         J     ");
             strcat(a_string, start_lb_4);
             src_line();
             strcpy(trace_1, "c2z while end label-4 #41-b");
             trace_rec_3();
             start_lb_4[0] = '\0';

             strcpy(a_string, wh_lb_4);
             check_length();
             strcat(a_string, "DS    0H");
             src_line();
             strcpy(trace_1, "c2z while end label-4 #41-a");
             trace_rec_3();
             wh_ct_4 = 0;
             wh_lb_4[0] = '\0';
             goto end_while_exit;
          }

          if(wh_ct_3 == 1)
          {
             strcpy(a_string, "         J     ");
             strcat(a_string, start_lb_3);
             src_line();
             strcpy(trace_1, "c2z while end label-3 #41-b");
             trace_rec_3();
             start_lb_3[0] = '\0';

             strcpy(a_string, wh_lb_3);
             check_length();
             strcat(a_string, "DS    0H");
             src_line();
             strcpy(trace_1, "c2z while end label-3 #41-a");
             trace_rec_3();
             wh_ct_3 = 0;
             wh_lb_3[0] = '\0';
             goto end_while_exit;
          }

          if(wh_ct_2 == 1)
          {
             strcpy(a_string, "         J     ");
             strcat(a_string, start_lb_2);
             src_line();
             strcpy(trace_1, "c2z while end label-2 #41-b");
             trace_rec_3();
             start_lb_2[0] = '\0';
          
             strcpy(a_string, wh_lb_2);
             check_length();
             strcat(a_string, "DS    0H");
             src_line();
             strcpy(trace_1, "c2z while end label-2 #41-a");
             trace_rec_3();
             wh_ct_2 = 0;
             wh_lb_2[0] = '\0';
             goto end_while_exit;
          }

          if(wh_ct_1 == 1)
          {
             strcpy(a_string, "         J     ");
             strcat(a_string, start_lb_1);
             src_line();
             strcpy(trace_1, "c2z while end label-1 #41-b");
             trace_rec_3();
             start_lb_1[0] = '\0';
   
             strcpy(a_string, wh_lb_1);
             check_length();
             strcat(a_string, "DS    0H");
             src_line();
             strcpy(trace_1, "c2z while end label-1 #41-a");
             trace_rec_3();
             wh_ct_1 = 0;
             wh_lb_1[0] = '\0';
          }

 end_while_exit:
 
        }
      }
    }

 wif_skip:

    if (return_on == 1) 
    {
        return_ct++;
    }


    /* **********************************************************
    *   Switch label punch out                                  *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    if (switch_ct > 0)
    {
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
    *  Punch B back from function                               *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "}");
    if ((p) && (inside_void == 2) && (parm_ct == 0)) 
    {
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

    if (fns_ct > 0) 
    {
      for (I = 0; I < fns_ct; I++) 
      {
        if (rct == w_func_start[I].fns_rct) 
        {
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


    /* ***********************************************************
    *  Punch float                                               *
    * ********************************************************** */
    if (convert == 1) 
    {
      goto end_pass3;
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

    p = strstr(p_string, "long");
    p1 = strstr(p_string, "(long)");
    if ((p) && (!p1)) 
    {
      c2_long();
      convert = 1;
    }


    /* **********************************************************
    *  Punch unsigned                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
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

    p = strstr(p_string, "strcat");
    if (p) 
    {
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

    p = strstr(p_string, "strlen");
    if (p) 
    {
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

    p = strstr(p_string, "strstr");
    if (p) 
    {
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

    p = strstr(p_string, "memcpy");
    if (p) 
    {
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

    p = strstr(p_string, "memmove");
    if (p) 
    {
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

    p = strstr(p_string, "strcpy");
    if (p) 
    {
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

    p = strstr(p_string, "while");
    p1 = strchr(p_string, '"');
    p2 = strstr(p_string, "while_");
    if ((p) && (!p2)) 
    {
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

    p = strstr(p_string, "strchr");
    if (p) 
    {
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

    p = strstr(p_string, "strcmp");
    if (p) 
    {
      c2_strcmp();
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

    p = strstr(p_string, "sizeof");
    if (p) 
    {
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

    p = strstr(p_string, "++");
    p1 = strstr(p_string, "printf");
    if ((p) && (!p1)) 
    {
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

    p = strstr(p_string, "feof");
    if (p) 
    {
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

    p = strstr(p_string, "fopen");
    if (p) 
    {
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

    p = strstr(p_string, "fgetc");
    if (p) 
    {
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

    p = strstr(p_string, "fgets");
    if (p) 
    {
      c2_fgets();
      var_use[18]++;
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

    p = strstr(p_string, "fputs");
    if (p) 
    {
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

    p = strstr(p_string, "getchar");
    if (p) 
    {
      c2_getchar_punch();
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

    p = strstr(p_string, "gets");
    if (p) 
    {
      c2_gets();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out puts                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "puts");
    if (p) 
    {
      c2_puts();
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

    p = strstr(p_string, "atoi");
    if (p) 
    {
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

    p = strstr(p_string, "atof");
    if (p) 
    {
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

    p = strstr(p_string, "atol");
    if (p) 
    {
      c2_atol_punch();
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }
\

    /* **********************************************************
    *  Punch out double                                         *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
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

    p = strstr(p_string, "strncpy");
    if (p) 
    {
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

    p = strstr(p_string, "strset");
    if (p) 
    {
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

    p = strstr(p_string, "strrev");
    if (p) 
    {
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

    p = strstr(p_string, "localtime");
    if (p) 
    {
      c2_localtime();
      tot_localtime++;
      convert = 1;
      if (return_on == 1) 
      {
        return_ct++;
      }
    }


    /* **********************************************************
    *  Punch out DATE                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    p = strstr(p_string, "date");
    if (p) 
    {
      c2_date();
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

    p = strstr(p_string, "time");
    if (p) 
    {
      c2_time();
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

    p = strstr(p_string, "clock");
    if (p) 
    {
     
      convert = 1;
    }


    /* **********************************************************
    *  Punch out exit                                           *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
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

    if ((p) && (v < s))  
    {
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

    p = strstr(p_string, "void");
    p1 = strstr(p_string, "(");

    if ((p) && (p1)) 
    {
      strcpy(trace_1, "c2z Function Start");
      trace_rec_1();
      
      /* convert = 1; */
    }


    /* **********************************************************
    *  Punch out function call                                  *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
    }

    for (I = 0; I < fns_ct; I++) 
    {
      if ((rct == w_func_start[I].fns_rct) && (convert == 0)) 
      {
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
    *      Math functions ( =, +, -, *, / ) MUST BE LAST CALL   * 
    *              	         IN PARSER EXECPT FOR REMARK CHECK *
    * ********************************************************* */
    if (convert == 1) 
    {
      goto end_pass3;
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
       /* c2_math();   */
        c2z_math_start(); 
        convert = 1;
        if (return_on == 1) 
        {
          return_ct++;
        }
      }


      if((p) && (!p1) && (x == 0))
      {
        c2_math(); 
        convert = 1;
      }
/*
      if((p) && (p1) && (x > 0) && (convert == 0)) 
      {
        var_use[21]++;

        strcpy(a_string, "         BRAS  R14,RDP_MAIN");
        src_line();
        strcpy(trace_1, "c2z_eoj rdp_main #1");
        trace_rec_3();
        convert = 1;
        if (return_on == 1) 
        {
          return_ct++;
        }
      }
*/
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

  c2_eoj();

  if(erct != 0)
  {
    printf("\nPass 3 FAILED with %d errors.\n\n",erct);
  }




  exit(0);
}
