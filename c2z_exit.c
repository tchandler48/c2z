/* ***************************************************
*  c2z  : c2z_exit.c                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */

/* *************************************************** 
*  Punch out EXIT                                    *
* ************************************************** */
void c2_exit()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_exit.c c2_exit");
				trace_rec_1();
			}
		
		strcpy(a_string, "         JLU   C370EXIT");
		strcpy(wk_remark, " exit     */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_exit.c c2_exit #1");
				trace_rec_3();
			}
	}




