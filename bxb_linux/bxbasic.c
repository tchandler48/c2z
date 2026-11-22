/* bxbasic.c : alpha version.13 */

/* --- declare headers --- */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

/* --- declare constants --- */
#define BUFSIZE     256
#define TOKEN_LEN	21
#define VAR_NAME	33
#define LLEN		33
#define IOARRAY	99
#define PATH	      129

/* ------ global vars ------------ */
    FILE *f_in, *f_out;      /* these are the i/o file handles    */
    char *prog_name;         /* program source-file name          */
    char p_string[BUFSIZE];  /* file input string                 */
    char **array1;           /* program array                     */
    char t_holder[20];       /* token data holder                 */
    char s_holder[BUFSIZE];  /* xstring (print) data holder       */
     int nrows;              /* numbers of lines in source file   */
     int ncolumns=BUFSIZE;   /* dimension for array1[][columns]   */
     int line_ndx;           /* current execution line            */
     int s_pos, e_pos;       /* pointers to start & end of token  */
    char xstring[BUFSIZE];   /* the print string                  */
    char **temp_prog;        /* temp program array                */
    char **temp_label;       /* temp label name array             */
     int *temp_byte;         /* temp byte code array              */
     int *byte_array;        /* byte code array                   */
    char **label_nam;        /* labels name array                 */
     int token;              /* token: current byte code          */
    char var_type;           /* current variable type             */
/**/
     int *iv_stack;          /* stack:integer variable values     */
    char **in_stack;         /* stack:integer variable names      */
     int imax_vars=0;        /* stack:integer variable counter    */
/**/
  double *dv_stack;          /* stack:double float values         */
    char **dn_stack;         /* stack:double float names          */
     int dmax_vars=0;        /* stack:double float counter        */
/**/
    long *lv_stack;          /* stack:long variable values        */
    char **ln_stack;         /* stack:long variable names         */
     int lmax_vars=0;        /* stack:long variable counter       */
/**/
   float *fv_stack;          /* stack:float variable values       */
    char **fn_stack;         /* stack:float variable names        */
     int fmax_vars=0;        /* stack:float variable counter      */
/**/
    char **nam_stack;        /* generic pointer to name stacks    */
     int max_vars;           /* variable for vars count           */
    void (*init_fn)();       /* generic function pointer          */
/**/
    char **sv_stack;         /* stack:string variable array       */
    char **sn_stack;         /* stack:string variable names       */
     int smax_vars=0;        /* stack:string variable counter     */
/**/
     int *gosub_stack;       /* Gosub: stack array                */
     int gs_ptr=-1;          /* Gosub: stack position pointer     */
/**/
     int fornxt_flg=0;       /* For/Next: global flag             */
    char func_type;          /* current function type             */
/**/
struct io_handles		 /* File: handles structure		   */
	{
		char path[PATH];
		char mode;
		FILE *fptr;
	};
struct io_handles fp[IOARRAY];	/* File: handles sturcture	   */
/**/		

/*--- Arrays --- */
struct string_array
	{
		char name[VAR_NAME];	/* string array name				*/
		char **elem;		/* array element pointers			*/
		int  dim;            /* number of dimensions			*/
		int  sub[10];		/* subscripts(2,3,4)				*/
	};

struct string_array *strArry;
	int sArryCnt=0;		/* array counter				*/

struct integer_array
	{
		char name[VAR_NAME];	/* integer array name			*/
		long *elem;		/* array element pointers			*/
		int  dim;		/* number of dimensions			*/
		int  sub[10];		/* subscripts(2,3,4)				*/
	};

struct integer_array *intArry;
	int iArryCnt=0;		/* array counter				*/

struct float_array
	{
		char name[VAR_NAME];	/* float array name				*/
		float *elem;		/* array element pointers			*/
		int  dim;		/* number of dimensions			*/
		int  sub[10];		/* subscripts(2,3,4)				*/
	};

struct float_array *fltArry;
	int fArryCnt=0;		/* array counter				*/

struct double_array
	{
		char name[VAR_NAME];	/* double array name				*/
		double *elem;		/* array element pointers			*/
		int  dim;		/* number of dimensions			*/
		int  sub[10];		/* subscripts(2,3,4)				*/
	};

struct double_array *dblArry;
	int dArryCnt=0;		/* array counter				*/

/*--- OBJECTS ---*/
	char **ObjIndx;		/* object/variables name index		*/
	 int **ObjType;		/* object/variables type specifier		*/
	 int ObjNdxCnt=0;		/* object/variables index count		*/

/*--- SUBs ---*/
	char **SubNameStack;
	char **paramStack;
	 int **PrmStackPtr;
	 int subCnt=0;
	 int paramCnt=0;
	 int StackPtr=0;
	 int StackSize=0;
	 int callFlag=0;
	 int thisSub;

/* ----- function prototypes ----- */
    void pgm_parser(void);
    void get_token(void);
    void parser(void);
    void go_to(void);
    void do_gosub(void);
    void do_return(void);


/* --- function includes --- */
#include "prototyp.h"
#include "error.c"
#include "utility.c"
#include "output.c"
#include "variable.c"
#include "input.c"
#include "rdparser.c"
#include "loops.c"
#include "ifendif.c"
#include "strings.c"
#include "getinput.c"
#include "fileio.c"


/* ----- begin program ------------- */

int main(int argc, char *argv[])
	{
		int x=0, ab_code=1;

		printf("Bxbasic Interpreter\n");
		if(argc != 6)
			{
				a_bort(ab_code, x);
			}
		strcpy(t_holder, argv[2]);
		line_cnt(argv);
		clr_iohandles();				/* clear I/O file handles */
		pgm_parser();

    		/* --- end of program --- */
		clr_arrays();
		return 0;
	}
/*-------------------------------*/

void pgm_parser()
{
    line_ndx = 0;
    while(line_ndx < nrows)
    {   s_pos = 0;
        e_pos = 0;
        get_token();
        parser();
        line_ndx++;
    }
}
/*-------------------------------*/

void get_token()
{
    strcpy(p_string, array1[line_ndx]);
    token = byte_array[line_ndx];
}
/*-------------------------------*/

void parser()
{   int ab_code=4, x=line_ndx;

    switch(token)
    {   case 1:		/* LET */
            parse_let();
            break;
        case 2:		/* CLEAR */
            clr_vars();
            break;
        case 3:		/* LOCATE */
            locate();
            break;
        case 4:		/* PRINT */
            parse_print();
            break;
        case 5:		/* GOTO */
            go_to();
            break;
        case 6:		/* BEEP */
            beep();
            break;
        case 7:		/* CLS */
            cls();
            break;
        case 8:		/* END */
            line_ndx = nrows;
            break;
        case 9:		/* GOSUB */
            do_gosub();
            break;
        case 10:	/* RETURN */
            do_return();
            break;
        case 11:	/* FOR */
            do_for();
            break;
        case 12:	/* NEXT */
            do_next();
            break;
        case 13:	/* IF */
            do_if();
            break;
        case 14:	/* ELSEIF */
            do_if();
            break;
        case 15:	/* ELSE */
            return;
            break;
        case 16:	/* ENDIF */
            return;
            break;
        case 17:	/* INPUT */
            get_input();
            break;
        case 18:	/* LINE INPUT */
            get_lninput();
            break;
		case 19:				/* OPEN */
			parse_open();
			break;
		case 20:				/* CLOSE */
			do_fclose();
			break;
		case 21:				/* WRITE */
			write_io();
			break;

	 case 29:                                /* COLOR  */
            color();
            break;
        case 30:                                /* RANDOM */
            do_random();
            break;

        case -1:	/* block label */
            break;
        default:
            a_bort(ab_code, x);
            break;
    }
}
/*-------------------------------*/

void go_to()
{   char ch;
    char goto_label[LLEN];
    int pi, si=0, ab_code=8;
    int xtest, stlen, x=line_ndx;

    pi = e_pos;
    pi = iswhite(pi);
    ch = p_string[pi];

    while(isalnum(ch))
    {   goto_label[si] = ch;
        pi++;
        si++;
        ch = p_string[pi];
    }
    goto_label[si] = '\0';             /* add string terminator */
    pi = -1;             /* now compare gtl_holder[] to array2[n] */
    xtest = -1;
    while(xtest != 0)
    {   pi++;
        if(pi == nrows)
        {   strcpy(t_holder, goto_label);
            a_bort(ab_code, x);        /* error, label not found */
        }
        xtest = strcmp(label_nam[pi], goto_label);
    }
    pi--;
    line_ndx = pi;             /* set line_ndx to the goto_line */
}
/*-------------------------------*/

void do_gosub()
{   unsigned size;

    gs_ptr++;
    if(gs_ptr == 0)
    {   size = 1;
        gosub_stack = malloc(size * sizeof(int));
    }
    else
    {   size = (gs_ptr + 1);
        gosub_stack = realloc(gosub_stack, size * sizeof(int));
    }
    gosub_stack[gs_ptr] = line_ndx;
    go_to();
}
/*------- end do_gosub ----------*/

void do_return()
{   unsigned size;

    if(gs_ptr < 0)                         /* return w/no "Gosub" */
    {   return;
    }
    else if(gs_ptr == 0)
    {   line_ndx = gosub_stack[gs_ptr];    /* restore line number */
        free(gosub_stack);
    }
    else
    {   line_ndx = gosub_stack[gs_ptr];    /* restore line number */
    }
    gs_ptr--;                      /* decrement stack pointer */
}
/*------- end do_return ----------*/

