/* ***************************************************
*  c2z : c2z_break.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */ 

/* *************************************************** 
*  Punch out BREAK statement                         *
* ************************************************** */
void c2_break(void)
	{
		strcpy(a_string, "         JLU   ");
		strcat(a_string, sw_tag);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_break.c c2_break #1");
				trace_rec_3();
			}

		strcpy(a_string, save_case_break); 
		/* strcpy(a_string, sw_tag); */
		check_length();
		strcat(a_string, "DS    0H");
		strcpy(wk_remark, " c break  ");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_break.c c2_break #2");
				trace_rec_3();
			}

		convert = 1;
	}

