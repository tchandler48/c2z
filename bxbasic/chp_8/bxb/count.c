#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

 
/* ------ declare constants ------ */
#define IOARRAY	99
#define PATH	      129
#define BUFSIZE     256

	char	p_string[BUFSIZE];
	 int	rct = 0;
	 int	t_rct = 0;
	 int   tpgm = 0;

/* ------ global vars ------------ */
    	FILE *c_input, *c_src;		/* these are the i/o file handles    	*/



int main(int argc, char *argv[])
{

  c_input = fopen("c2z.c", "r");
  rct = 0;
  while(1)
  {
    fgets(p_string, BUFSIZE, c_input);
    rct++;
    if( feof(c_input) )
    { 
      break ;
    }
  }
  fclose(c_input);
  printf("c2z.c =              %d\n",rct);
  t_rct = t_rct + rct;
  tpgm++;

  c_input = fopen("c2z_arth.c", "r");
  rct = 0;
  while(1)
  {
    fgets(p_string, BUFSIZE, c_input);
    rct++;
    if( feof(c_input) )
    { 
      break ;
    }
  }
  fclose(c_input);
  printf("c2z_arth.c =         %d\n",rct);
  t_rct = t_rct + rct;
  tpgm++;


  c_input = fopen("c2z_atof.c", "r");
  rct = 0;
  while(1)
  {
    fgets(p_string, BUFSIZE, c_input);
    rct++;
    if( feof(c_input) )
    { 
      break ;
    }
  }
  fclose(c_input);
  printf("c2z_atof.c =         %d\n",rct);
  t_rct = t_rct + rct;
  tpgm++;

  c_input = fopen("c2z_atoi.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_atoi,c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

              c_input = fopen("c2z_atol.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_atol.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_break.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_break.c =        %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_case.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_case.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_char.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_char.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_const.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_const.c =        %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_ctime.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_ctime.c =        %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_debug.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_debug.c =        %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_decr.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_decr.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_define.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_define.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_double.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_double.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_enum.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_enum.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;
	
		c_input = fopen("c2z_eoj.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_eoj.c =          %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_exit.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_exit.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;
	
		c_input = fopen("c2z_fclose.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_fclose.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_feof.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_feof.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_file.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_file.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_fgets.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_fgets.c =        %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_float.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_float.c =        %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;




		c_input = fopen("c2z_fopen.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_fopen.c =        %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_for.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_for.c =          %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_fputs.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_fputs.c =        %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_free.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_free.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_function.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_function.c =     %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_goto.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_goto.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_if.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_if.c =           %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_incr.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_incr =           %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_int.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_int.c =          %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_isalnum.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_isalnum.c =      %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_isalpha.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_isalpha.c =      %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_isdigit.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_isdigit.c =      %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_isspace.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_isspace.c =      %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_isupper.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_isupper.c =      %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_localtime.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_localtime.c =    %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_long.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_long.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

              c_input = fopen("c2z_main.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_main.c   =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_malloc.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_malloc.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;
	
		c_input = fopen("c2z_math.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_math.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_math_func.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_math_func.c =    %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_mem.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_mem.c =          %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_misc.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_misc.c =         %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_parameter.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_parameter.c =    %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_pass_2.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_pass_2.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_pass_3.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_pass_3.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_print.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_print.c =        %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;
 
		c_input = fopen("c2z_realloc.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_realloc.c =      %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_scanf.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_scanf.c =        %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_sizeof.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_sizeof.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_strcat.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_strcat.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_strchr.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_strchr.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_strcmp.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_strcmp.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_strcpy.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_strcpy.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_strlen.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_strlen.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_strrev.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_strrev.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_strset.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_strset.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_strstr.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_strstr.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_strncpy.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_strncpy.c =      %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_strrchr.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_strrchr.c =      %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_struct.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_struct.c =       %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;


		c_input = fopen("c2z_time.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		tpgm++;
		printf("c2z_time.c =         %d\n",rct);
		t_rct = t_rct + rct;


              c_input = fopen("c2z_u_short.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		tpgm++;
		printf("c2z_u_short.c  =     %d\n",rct);
		t_rct = t_rct + rct;

		c_input = fopen("c2z_unsigned.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		tpgm++;
		printf("c2z_unsigned.c =     %d\n",rct);
		t_rct = t_rct + rct;


		c_input = fopen("c2z_utility.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_utility.c =      %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		c_input = fopen("c2z_while.c", "r");
		rct = 0;
		while(1)
   			{
				fgets(p_string, BUFSIZE, c_input);
				rct++;
				if( feof(c_input) )
      					{ 
         					break ;
      					}
			}
		fclose(c_input);
		printf("c2z_while.c =        %d\n",rct);
		t_rct = t_rct + rct;
		tpgm++;

		printf("\nTotal records =     %d\n\n",t_rct);

		printf("Total Programs  =   %d\n",tpgm);
		

	}
