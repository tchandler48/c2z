/* ***************************************************
*  c2z : c2z_return.c :                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */

/* *************************************************** 
*  Punch out RETRUN code                             *
* ************************************************** */
void c2_return()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_return.c c2_return");
				trace_rec_1();
			}

		char ch;
		char *p1;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
           	char tfield2a[VAR_LGTH];
		char tfield5a[VAR_LGTH];
		
		int pi;
		int pi2;
		int I = 0;
		int ret = 0;

		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		
		while(ch != ' ') 
			{
				tfield1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield1[pi2] = '\0';
		
		p1 = strstr(tfield1,";");
		if(!p1)
			{
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ';')
					{
						/* tfield2[pi2] = ch;
						pi2++; */
						pi++;
						ch = p_string[pi];
					}
			}

		if(fn_ct > 0)
			{
				for(I = 0;  I < fn_ct; I++)
					{
						ret = strcmp(sv_func, w_function[I].fn_name);
						if(ret == 0)
							{
								strcpy(tfield1a, w_function[I].fn_sv_reg_1);
								strcpy(tfield2a, w_function[I].fn_sv_reg_2);
								strcpy(tfield5a, w_function[I].fn_loop);
							}
					}
			}

		ret = strcmp("main",sv_func);
	
		if(ret != 0)
			{
				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield5a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #2");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #3");
						trace_rec_3();
					}

				strcpy(a_string, "         JLNE  L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #4");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #5");
						trace_rec_3();
					}

				strcpy(a_string, "         L     C370LNK,0(,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #6");
						trace_rec_3();
					}

				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "D");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #7");
						trace_rec_3();
					}

				strcpy(a_string, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				check_length();
				strcat(a_string, "DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #8");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield5a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #9");
						trace_rec_3();
					}
	
				strcpy(a_string, "         LARL  R8,C370TWO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #10");
						trace_rec_3();
					}
				work_use_ct[34]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #11");
						trace_rec_3();
					}

				strcpy(a_string, "         JNE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "D");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #12");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield2a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #13");
						trace_rec_3();
					}

				strcpy(a_string, "         L     C370LNK,0(,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #14");
						trace_rec_3();
					}

				strcpy(a_string, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "D");
				check_length();
				strcat(a_string, "DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #15");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield5a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #16");
						trace_rec_3();
					}
	
				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #17");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #18");
						trace_rec_3();
					}

				strcpy(a_string, "         BR    C370LNK");
				strcpy(wk_remark," sub rtn  */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_return.c c2_return #19");
						trace_rec_3();
					}

				return_on = 1;
			}

		convert = 1;
	}

