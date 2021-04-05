/* ***************************************************
*  c2z : c2z_fgets.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* *************************************************** 
*  Punch out FGETS                                   *
* ************************************************** */
void c2_fgets()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets");
				trace_rec_1();
			}
		
		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];

		int pi;
		int pi2;
		int I = 0;
		int f1 = 0;
		int f2 = 0;
		int f2a = 0;
		int f3 = 0;
		int ret = 0;
		int x2 = 0;
		int x4 = 0;
		int x5 = 0;
		int x6 = 0;

		int fd2_type = 0;

		check_semi(); 

		pi = 0;
		ch = p_string[pi];
		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			}
				
		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ',')
			{
				
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field1[pi2] = '\0';

		f3 = 0;
		for(f1=0; f1 < gv_ct; f1++)
			{
				f2 = strcmp(field1, gw_variable[f1].gv_name);
				if(f2 == 0)
					{
						strcpy(field1a, gw_variable[f1].gv_cname);
						x6 = gw_variable[f1].gv_lgth;
						f3 = 1;		
					}
			}

		if(f3 != 1)		
			{
				printf("c2z_fgets.c c2_files E-40 field1 Not Found = %s\n",field1);
				c2_error();
			}

		pi++;
		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		x2 = 0;
		while(ch != ',')
			{
				if(ch != '_')
					{
						if(x2 == 0)
							{
								if(isdigit(ch))		
									{
										x2 = 1;
										fd2_type = 1;
									}
								if(isalpha(ch))
									{
										x2 = 1;
										fd2_type = 2;
									}
							}
						field2[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		field2[pi2] = '\0';

		if(fd2_type == 2)
			{
				f3 = 0;
				for(f1=0; f1 < lv_ct; f1++)
					{
						f2 = strcmp(field2, lw_variable[f1].lv_name);
						f2a = strcmp(sv_func, lw_variable[f1].lv_func);
						if((f2 == 0) && (f2a == 0))
							{
								x5 =  lw_variable[f1].lv_lgth;
								strcpy(field2a, lw_variable[f1].lv_value);
								f3 = 1;		
							}
					}

				if(f3 == 0)
					{
						for(f1=0; f1 < gv_ct; f1++)
							{
								f2 = strcmp(field2, gw_variable[f1].gv_name);
								if(f2 == 0)
									{
										x5 =  gw_variable[f1].gv_lgth;
										strcpy(field2a, gw_variable[f1].gv_cname);
										f3 = 1;			
									}
							}
					}

				if(f3 == 0)		
					{
						printf("c2z_fgets.c c2_files E-41 field2 Not Found = %s\n",field2);
						c2_error();
					}
			}

		f3 = 0;
		for(f1=0; f1 < gv_ct; f1++)
			{
				f2 = strcmp(field1, gw_variable[f1].gv_name);
				if(f2 == 0)
					{
						gw_variable[f1].gv_lgth = x5-1;
						gw_variable[f1].gv_current_lgth = x5-1;
						f3 = 1;		
					}
			}

		pi++;
		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		while(ch != ')')
			{
				field3[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field3[pi2] = '\0';

		for(f1=0; f1 < fn_ct; f1++)
			{
				f2 = strcmp(field3, w_file[f1].f_name);
				if(f2 == 0)
					{
						strcpy(field3a, w_file[f1].f_cname);
					}
			}

		strcpy(a_string, "         LARL  R9,");
		strcat(a_string, field3);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #1");
				trace_rec_3();
			}

		strcpy(a_string, "         GET   (R9)");
		strcpy(wk_remark, " fgets    */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #2");
				trace_rec_3();
			}

		x4 = 0;
		for(I=0; I < f_ct; I++)
			{
				x4 = w_file[I].f_buf_ct;
				ret = strcmp(field3, w_file[I].f_name);
				if(ret == 0)
					{

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field1a);
                                          strcpy(wk_remark, " ");
						strcat(wk_remark, field1);
						strcat(wk_remark, " */");
                                          write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_fgets.c c2_fgets #3");
								trace_rec_3();
							}
	
						strcpy(a_string, "         LARL  R8,C370PB");
						snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
						strcat(a_string, wk_strg);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_fgets.c c2_fgets #4");
								trace_rec_3();
							}

						strcpy(a_string, "         MVC   ");
						strcat(a_string, "0(");
						snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
						strcat(a_string, wk_strg);
						strcat(a_string, ",R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_fgets.c c2_fgets #5");
								trace_rec_3();
							}
					}
			}

		strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #6");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         LARL  R8,");
		strcat(a_string, field2a);
              strcpy(wk_remark, " ");
              strcat(wk_remark, field2);
              strcat(wk_remark, " */");
              write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #7");
				trace_rec_3();
			}

		strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #8");
				trace_rec_3();
			}

		strcpy(a_string, "L");
		strcat(a_string, wk_strg);
		strcat(a_string, "A");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #9");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #10");
				trace_rec_3();
			}
		work_use_ct[48]++;

		strcpy(a_string, "         LARL  R8,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #11");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #12");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #13");
 				trace_rec_3();
			}
		work_use_ct[48]++;

		strcpy(a_string, "         CVB   R5,0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #14");
 				trace_rec_3();
			}

		strcpy(a_string, "         AHI   ");
		strcat(a_string, "R5,-1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #15");
				trace_rec_3();
			}
				
		strcpy(a_string, "         LARL  R8,");
		strcat(a_string, field1a);
		strcpy(wk_remark, " ");
		strcat(wk_remark, field1);
		strcat(wk_remark, " */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #16");
 				trace_rec_3();
			}

		strcpy(a_string, "         IC    R0,");
		strcat(a_string, "0(R8,");
		strcat(a_string, "(R5))");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #17");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #18");
				trace_rec_3();
			}
		work_use_ct[2]++;

		strcpy(a_string, "         STC   R0,");
		strcat(a_string, "0(0,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #19");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #20");
				trace_rec_3();
			}
		work_use_ct[2]++;

		strcpy(a_string, "         LARL  R8,C370B1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #21");
				trace_rec_3();
			}
		work_use_ct[52]++;

		strcpy(a_string, "         CLC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #22");
				trace_rec_3();
			}

		strcpy(a_string, "         JLNE  L");
		strcat(a_string, wk_strg);
		strcat(a_string, "B");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #23");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #24");
				trace_rec_3();
			}
	
		strcpy(a_string, "         LARL  R8,C370ONE");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #25");
				trace_rec_3();
			}
		work_use_ct[33]++;

		strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #26");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   L");
		strcat(a_string, wk_strg);
		strcat(a_string, "A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #27");
				trace_rec_3();
			}

		strcpy(a_string, "L");
		strcat(a_string, wk_strg);
		strcat(a_string, "B");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #28");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #29 ");
 				trace_rec_3();
			}
		work_use_ct[48]++;

		strcpy(a_string, "         LARL  R8,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #30");
				trace_rec_3();
			}
	
		strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #31");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #32");
 				trace_rec_3();
			}
		work_use_ct[48]++;

		strcpy(a_string, "         CVB   R2,0(R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #33");
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
				strcpy(trace_1, "c2z_fgets.c c2_fgets #34");
 				trace_rec_3();
			}
	
		strcpy(a_string, "         LR    R1,R9");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #35");
 				trace_rec_3();
			}

		strcpy(a_string, "         AR    R1,R2");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #36");
 				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370EOF");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #37");
				trace_rec_3();
			}

		strcpy(a_string,"         MVC   0(R9");
		strcat(a_string, ",R1),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_fgets #38");
				trace_rec_3();
			}

		convert = 1;
	}


/* *************************************************** 
*  Scan for FGETS                                    *
* ************************************************** */
void c2_scan_sc4()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_fgets.c c2_scan_sc4");
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];

		int pi;
		int pi2;
		int x3 = 0;
		int I = 0;
		int ret = 0;
		
		check_semi(); 

		pi = 0;
		ch = p_string[pi];
		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			}
				
		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ',')
			{
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field1[pi2] = '\0';

		if(gv_ct > 0)
			{
				for(I = 0; I < gv_ct; I++)
					{
						ret = strcmp(field1, gw_variable[I].gv_name);
						if(ret == 0)
							{
								strcpy(field1a, gw_variable[I].gv_cname);
							}
					}
			}

		I = 0;
		x3 = 0;
		for(I=0; I < gv_ct; I++)
			{
				ret = strcmp(field1, gw_variable[I].gv_name);
				if(ret == 0)
					{
						x3 = 1;		
					}
			}

		if(x3 != 1)		
			{
				printf("c2z_fgets.c c2_files E-42 field1 Not Found = %s\n",field1);
				c2_error();
			}

		pi++;
		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		while(ch != ',')
			{
				if(ch != '_')
					{
						field2[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		field2[pi2] = '\0';

		if(gv_ct > 0)
			{
				for(I = 0; I < gv_ct; I++)
					{
						ret = strcmp(field2, gw_variable[I].gv_name);
						if(ret == 0)
							{
								strcpy(field2a, gw_variable[I].gv_cname);
							}
					}
			}

		pi++;
		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		while(ch != ')')
			{
				field3[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field3[pi2] = '\0';

		if(gv_ct > 0)
			{
				for(I = 0; I < gv_ct; I++)
					{

						ret = strcmp(field3, gw_variable[I].gv_name);
						if(ret == 0)
							{
								strcpy(field3a, gw_variable[I].gv_cname);
							}
					}
			}

		x3 = 0;
		for(I=0; I < f_ct; I++)
			{

				ret = strcmp(field3, w_file[I].f_name);
				if(ret == 0)
					{
						strcpy(w_file[I].f_type,"D");
						strcpy(w_file[I].f_perm, "I");
						strcpy(w_file[I].f_rec_lgth, field2);
						x3 = 1;
					}
			}

		if(x3 != 1)
			{
				printf("c2z_fgets.c c2_scan_sc4 E-43 Field3 Not Found in Function table = %s\n",field3);
				c2_error();
			}
	}

