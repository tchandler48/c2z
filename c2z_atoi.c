/* ***************************************************
*  c2z : c2z_atoi.c :                                *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */

/* *************************************************** 
*  Punch out atoi                                    *
* ************************************************** */
void c2_atoi(void)
	{
		if(trace_flag == 1)		
			{
				strcpy(trace_1, "c2z.atoi.c c2_atoi");
				trace_rec_1();
			}

		int pi;
		int pi2;
		int x3 = 0;
		int x9 = 0;
		int I = 0;
		int ret = 0;	
		int ret1 = 0;

		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		
		use_atoi++;

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
				if(ch != '_')
					{
						field1[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		field1[pi2] = '\0';

		x3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(field1, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{	
						x3 = 1;
						strcpy(field1a, lw_variable[I].lv_cname);		
					}
			}
			
		if(x3 == 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(field1, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(field1a, gw_variable[I].gv_cname);	
							}
					}
			}
			
		if(x3 == 0)
			{
				printf("c2z_atoi.c c2_atoi E-1 field1 Not Found = %s\n",field1);
				c2_error();
			}

		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ')')
			{
				field2[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field2[pi2] = '\0';

		x3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(field2, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						x3 = 1;
						strcpy(field2a, lw_variable[I].lv_cname);		
						lw_variable[I].lv_use_ct++;
						x9 = lw_variable[I].lv_lgth;
					}
			}
			
		if(x3 == 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(field2, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(field2a, gw_variable[I].gv_cname);				
								gw_variable[I].gv_use_ct++;
								x9 = gw_variable[I].gv_lgth;
							}
					}
			}

		pi2 = 0;
		pi = 0;
		ch = field2[pi];
		
		if(x3 == 0)
			{
				printf("c2z_atoi.c c2_atoi E-2 field2 Not Found = %s\n",field2);
				c2_error();
			}

		if(x9 > 8)
			{
				x9 = 8;
			}

		strcpy(a_string, "         LARL  R9,C370L10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #1");
				trace_rec_3();
			}
			
		strcpy(a_string, "         LARL  R8,C370L10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #2");
				trace_rec_3();
			}

		strcpy(a_string, "         XC    0(10,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #3");
				trace_rec_3();
			}
	
		strcpy(a_string, "         LARL  R9,C370B10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #4");
				trace_rec_3();
			}
		work_use_ct[9]++;

		strcpy(a_string, "         LARL  R8,");
		strcat(a_string, field2a);
		strcpy(wk_remark, " ");
		strcat(wk_remark, field2);
		strcat(wk_remark, " */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #5");
				trace_rec_3();
			}

		snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
		strcpy(a_string, "         MVC   0(");
		strcat(a_string, wk_strg);
		strcat(a_string, ",R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #6");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370B10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #7");
				trace_rec_3();
			}
			
		strcpy(a_string, "         LARL  R8,C370EOF");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #8");
				trace_rec_3();
			}
		work_use_ct[52]++;
				
		x9 = 0;
		strcpy(a_string, "         CLC   1(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #9");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #10");
				trace_rec_3();
			}

		strcpy(a_string, "         CLC   2(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #11");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "B");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #12");
				trace_rec_3();
			}

		strcpy(a_string, "         CLC   3(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #13");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "C");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #14");
				trace_rec_3();
			}

		strcpy(a_string, "         CLC   4(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #15");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "D");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #16");
				trace_rec_3();
			}

		strcpy(a_string, "         CLC   5(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #17");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "E");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_ato1.c c2_atoi #18");
				trace_rec_3();
			}

		strcpy(a_string, "         CLC   6(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #19");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "F");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #20");
				trace_rec_3();
			}

		strcpy(a_string, "         CLC   7(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #21");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "G");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #22");
				trace_rec_3();
			}
		
		strcpy(a_string, "         CLC   8(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #23");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #24");
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
				strcpy(trace_1, "c2z_atoi.c c2_atoi #25");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #26");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370B10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #27");
				trace_rec_3();
			}

				
		strcpy(a_string, "         MVC   7(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #28");
				trace_rec_3();
			}
					
		strcpy(a_string, "         JLU   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "Z");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #29");
				trace_rec_3();
			}	

		strcpy(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "B");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #30");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #31");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370B10");
		src_line();
		if(punch_code == 1)		
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #32");
				trace_rec_3();
			}

		strcpy(a_string, "         MVC   6(2,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #33");
				trace_rec_3();
			}
					
		strcpy(a_string, "         JLU   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "Z");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #34");
				trace_rec_3();
			}	

		strcpy(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "C");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #35");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #36");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370B10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #37");
				trace_rec_3();
			}

		strcpy(a_string, "         MVC   5(3,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #38");
				trace_rec_3();
			}
				
		strcpy(a_string, "         JLU   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "Z");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #39");
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
				strcpy(trace_1, "c2z_atoi.c c2_atoi #40");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #41");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370B10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #42");
				trace_rec_3();
			}

		strcpy(a_string, "         MVC   4(4,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #43");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "Z");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #44");
				trace_rec_3();
			}

		strcpy(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "E");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #45");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #46");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370B10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #47");
				trace_rec_3();
			}

		strcpy(a_string, "         MVC   3(5,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #48");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "Z");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #49");
				trace_rec_3();
			}
	
		strcpy(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "F");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #50");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #51");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370B10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #52");
				trace_rec_3();
			}

		strcpy(a_string, "         MVC   2(6,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #53");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "Z");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #54");
				trace_rec_3();
			}

		strcpy(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "G");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #55");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #56");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370B10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #57");
				trace_rec_3();
			}

		strcpy(a_string, "         MVC   1(7,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #58");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "Z");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #59");
				trace_rec_3();
			}

/*
		strcpy(a_string, "         JLU   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "X");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #60");
				trace_rec_3();
			}
*/
	
		strcpy(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "H");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #60");
				trace_rec_3();
			}
		strcpy(a_string, "         LARL  R9,C370L10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #61");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370B10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #62");
				trace_rec_3();
			}

		strcpy(a_string, "         MVC   1(8,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #63");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "Z");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #64");
				trace_rec_3();
			}






				
		strcpy(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "Z");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #65");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,");
		strcat(a_string, field1a);
		strcpy(wk_remark, " ");
		strcat(wk_remark, field1);
		strcat(wk_remark, " */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #66");
				trace_rec_3();
			}
				
		strcpy(a_string, "         LARL  R8,C370L10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #67");
				trace_rec_3();
			}
		work_use_ct[8]++;
				
		/* snprintf(wk_strg, sizeof(wk_strg), "%d", x9); */
		strcpy(a_string, "         PACK  0(6,R9),0(8,R8)");
		src_line();
		if(punch_code == 1) 
			{
				strcpy(trace_1, "c2z_atoi.c c2_atoi #68");
				trace_rec_3();
			}
	}


