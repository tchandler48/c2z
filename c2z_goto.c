/* ***************************************************
*  c2z : c2z_goto.c                                  *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */

/* *************************************************** 
*  Punch out goto statement                          *
* ************************************************** */
void c2_goto()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_goto.c c2_goto");
				trace_rec_1();
			}

		char ch;

		int pi;
		int pi2;

		pi = 0;
		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		while(ch == '\t')
			{
				pi++;
				ch = p_string[pi];
			}

		while(ch != ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		while(ch != ';')
			{
				wk_string[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}

		wk_string[pi2] = '\0';
		strcpy(a_string,"         JLU   ");
		strcat(a_string, wk_string);
		strcpy(wk_remark, " goto     */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_goto.c c2_goto #1");
				trace_rec_3();
			}

		strcpy(a_string, "*");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_goto.c c2_goto #2");
				trace_rec_3();
			}

		convert = 1;
			
	}


/* ************************************************** 
*  Punch out goto label statement                   *
* ************************************************* */
void c2_goto_label()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_goto.c c2_goto_label");
				trace_rec_1();
			}

		char ch;

		int pi;
		int pi2;

		pi = 0;
		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		while(ch == '\t')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		while(ch != ':')
			{
				wk_string[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}

		strcpy(a_string, wk_string);
		check_length();
		strcat(a_string, "DS     0H");
		strcpy(wk_remark," goto lable */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_goto.c c2_goto_label #1");
				trace_rec_3();
			}
						
		convert = 1;
	}

