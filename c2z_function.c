/* ***************************************************
*  c2z : c2z_function.c                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */

/* *************************************************** 
*  Punch out B back from function                    *
* ************************************************** */
void c2_func_end()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_end");
				trace_rec_1();
			}

		int I = 0;
		int v1 = 0;
		int ret = 0;

		char tfield1a[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield5a[VAR_LGTH];
		char ar_field6[VAR_LGTH];
		char ar_field7[VAR_LGTH];
		char ar_field8[VAR_LGTH];
		char ar_field9[VAR_LGTH];
		char ar_field10[VAR_LGTH];
		char ar_field11[VAR_LGTH];

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
		
		for(v1 = 0; v1 < gv_ct; v1++)
			{
				ret = strcmp("A", gw_variable[v1].gv_type);
				if(ret == 0)
					{
						strcpy(ar_field6, gw_variable[v1].gv_label);
						strcpy(ar_field7, gw_variable[v1].gv_table);
						strcpy(ar_field8, gw_variable[v1].gv_aname);
						strcpy(ar_field9, gw_variable[v1].gv_sv_reg);
						strcpy(ar_field10, gw_variable[v1].gv_wk_reg);
						strcpy(ar_field11, gw_variable[v1].gv_wk_strg);
					}
			}

		if(return_on == 0)
			{

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield5a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield5a);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #2");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ONE");
				strcpy(wk_remark, " C370ONE */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #3");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #4");
						trace_rec_3();
					}

				strcpy(a_string, "         JNE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1a);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #6");
						trace_rec_3();
					}

				strcpy(a_string, "         L     C370LNK,0(,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #7");
						trace_rec_3();
					}

				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "D");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #8");
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
						strcpy(trace_1, "c2z_function.c c2_func_end #9");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield5a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #10");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370TWO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #11");
						trace_rec_3();
					}
				work_use_ct[34]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #12");
						trace_rec_3();
					}

				strcpy(a_string, "         JNE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "D");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #13");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield2a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #14");
						trace_rec_3();
					}

				strcpy(a_string, "         L     C370LNK,0(,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #15");
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
						strcpy(trace_1, "c2z_function.c c2_func_end #16");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield5a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #17");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #18");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #19");
						trace_rec_3();
					}

				strcpy(a_string, "         BR    C370LNK");
				strcpy(wk_remark," sub rtn  */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #20");
						trace_rec_3();
					}
			}

		if((return_on == 1) && (return_ct != 0))
			{
				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield5a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield5a);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #21");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #22");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #23");
						trace_rec_3();
					}

				strcpy(a_string, "         JNE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #24");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
                            strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1a);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #25");
						trace_rec_3();
					}

				strcpy(a_string, "         L     C370LNK,0(,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #26");
						trace_rec_3();
					}

				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "D");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #27");
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
						strcpy(trace_1, "c2z_function.c c2_func_end #28");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield5a);
                            strcpy(wk_remark, " ");
				strcat(wk_remark, tfield5a);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #29");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370TWO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #30");
						trace_rec_3();
					}
				work_use_ct[34]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #31");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield2a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #33");
						trace_rec_3();
					}

				strcpy(a_string, "         L     C370LNK,0(,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #34");
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
						strcpy(trace_1, "c2z_function.c c2_func_end #35");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield5a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield5a);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #36");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #37");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #38");
						trace_rec_3();
					}

				strcpy(a_string, "         BR    C370LNK");
				strcpy(wk_remark," sub rtn  */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_func_end #39");
						trace_rec_3();
					}
			}

		inside_void = 0;
		return_on = 0;
		return_ct = 0;
		convert = 1;

	}		


/* ***************************************************
*  Punch out function call                           *
* ************************************************** */
void c2_func_call()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_call");
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];;
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field4[VAR_LGTH];
		char field4a[VAR_LGTH];
		char field7[VAR_LGTH];
		char field7a[VAR_LGTH];
		char field8[VAR_LGTH];
		char field8a[VAR_LGTH];
		
		int pi;
		int pi2;
		int comma_ct = 0;
		int x2 = 0;
		int x3 = 0;
		int x4 = 0;
		int x5 = 0;
		int I = 0;
		int s = 0;
		int v = 0;
		int fd2_type = 0;
             	int fd2a_type = 0;
		int fd4a_type = 0;
		int if_convert = 0;
		int wk_pass_1 = 0;
		int size = 0;

		int fd7_type = 0;
		int fd8_type = 0;
		int ret = 0;
		int ret1 = 0;
		int ret2 = 0;

		char wk_sv_func[VAR_LGTH];
		char org_sv_func[VAR_LGTH];

		char *p, *p2, *p6;

		field1a[0] = '\0';

		s = 0;
		x4 = 0;
		x5 = 0;
		s = strlen(p_string);
		for(I = 0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == ',')
					comma_ct++;
				if(ch == ' ')
					{
						x4++;
					}
				if(ch == '{')
					{
						x5++;
					}
				if(ch == '}')
					{
						x5++;
					}
			}
			
		s--;

		if((x4 + x5) == s)
			{
				return;
			}

		p = strstr(p_string, "else");
		if(p)
			{
				return;
			}

		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t') || (ch == '{'))
			{
				pi++;
				ch = p_string[pi];
			} 
				
		pi2 = 0;
		while(ch != '(')
			{
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field1[pi2] = '\0';

		strcpy(wk_sv_func, field1);

		if(fn_ct > 0)
			{
				for(I = 0;  I < fn_ct; I++)
					{
						ret = strcmp(field1, w_function[I].fn_name);
						if(ret == 0)
							{
								strcpy(field1a, w_function[I].fn_cname);
							}
					}
			}

		if(comma_ct > 0)
			{
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ',') 
					{
						if(ch != ' ')
							{
								field2[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				field2[pi2] = '\0';

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ')')
					{
						if(ch != ' ')
							{
								field3[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				field3[pi2] = '\0';

				if(fn_ct > 0)
					{
						for(I = 0;  I < fn_ct; I++)
							{
								ret = strcmp(field1, w_function[I].fn_name);
								if(ret == 0)
									{
										strcpy(field1a, w_function[I].fn_cname);
										strcpy(field7, w_function[I].fn_fd1);
										strcpy(field8, w_function[I].fn_fd2);
									}
							}
					}

				x3 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field2, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);

						if((ret == 0)  && (ret1 == 0))
							{
								x3 = 1;
								strcpy(field2a, lw_variable[v].lv_cname);
								lw_variable[v].lv_use_ct++;
							}
					}

				if(x3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field2, gw_variable[v].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(field2a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_function.c c2_func_call E-78 field2 Not Found = %s\n",field2);
						c2_error();
					}

				x3 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field3, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(field3a, lw_variable[v].lv_cname);
								lw_variable[v].lv_use_ct++;
							}
					}

				if(x3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field3, gw_variable[v].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(field3a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
									}
							}
					}
	
				if(x3 == 0)
					{
						printf("c2z_function.c c2_func_call E-79 field3 Not Found = %s\n",field3);
						c2_error();
					}

				x3 = 0;
				v = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field7, lw_variable[v].lv_name);
						ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(field7a, lw_variable[v].lv_cname);
								lw_variable[v].lv_use_ct++;
								ret2 = strcmp("C", lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd7_type = 1;
									}
								else
									{
										fd7_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field7, gw_variable[v].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(field7a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
										ret2 = strcmp("C", gw_variable[v].gv_type);
										if(ret2 == 0)
											{
												fd7_type = 1;
											}
										else
											{
												fd7_type = 2;
											}
									}
							}
					}

				x3 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field8, lw_variable[v].lv_name);
						ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(field8a, lw_variable[v].lv_cname);
								lw_variable[v].lv_use_ct++;
								ret2 = strcmp("C", lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd8_type = 1;
									}
								else
									{
										fd8_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field8, gw_variable[v].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(field8a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
										ret2 = strcmp("C", gw_variable[v].gv_type);
										if(ret2 == 0)
											{
												fd8_type = 1;
											}
										else
											{
												fd8_type = 2;
											}

									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_function.c c2_func_call E-80 field8 Not Found %s\n",field8);
						c2_error();
					}

				if(fd7_type == 1) 
					{
						strcpy(a_string, "         MVC   ");
						strcat(a_string, field7a);
						strcat(a_string, ",");
						strcat(a_string, field2a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_function.c c2_func_call #1");
								trace_rec_3();
							}
					}
					
				if(fd7_type == 2)
					{
						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field7a);
						strcpy(wk_remark, " ");
						strcpy(wk_remark, field7);
						strcpy(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_function.c c2_func_call #2");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field2a);
						strcpy(wk_remark, " ");
						strcpy(wk_remark, field2);
						strcpy(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_function.c c2_func_call #3");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_function.c c2_func_call #4");
								trace_rec_3();
							}
					}

				if(fd8_type == 1)
					{
						strcpy(a_string, "         MVC   ");
						strcat(a_string, field8a);
						strcat(a_string, ",");
						strcat(a_string, field3a);
						strcpy(wk_remark, " ");
						strcpy(wk_remark, field8);
						strcpy(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_function.c c2_func_call #5");
								trace_rec_3();
							}
					}

				if(fd8_type == 2)
					{
						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field8a);
						strcpy(wk_remark, " ");
						strcpy(wk_remark, field8);
						strcpy(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_function.c c2_func_call #6");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field3a);
						strcpy(wk_remark, " ");
						strcpy(wk_remark, field3);
						strcpy(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_function.c c2_func_call #7");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_function.c c2_func_call #8");
								trace_rec_3();
							}
					}
			}	

		if((comma_ct == 0) && (if_convert == 0))		
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2_func_call comma = 0");
						trace_rec_1();
					}

				if_convert = 0;
				p6 = strstr(p_string, "()");
				if(p6)
					{
						if_convert = 1;
					}

				if(if_convert == 1)
					{
						x3 = 0;
						for(I=0; I < fn_ct; I++)
							{
								ret = strcmp(field1, w_function[I].fn_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(field1a, w_function[I].fn_cname);
									}
							}

						if(x3 == 0)
							{
								printf("c2_func_call comma_ct == 0 E-81 FUNCTION FIELD1 NOT FOUND\n");
								c2_error();
							}
			
						convert = 1;
					}

				if(if_convert == 0)
					{
						strcpy(wk_sv_func, field1);

						pi2 = 0;
						x2 = 0;
						pi++;
						ch = p_string[pi];
						while(ch != ';')
							{
								if(ch != ' ')
									{
										if(x2 == 0)
											{
												if (isalpha(ch))	
													{
														fd2_type = 1;
														x2 = 1;
													} 
												if (isdigit(ch)) 	
													{
														fd2_type = 1;
														x2 = 1;
													}
											}
										field2[pi2] = ch;
										pi2++;
									}
								pi++;
								ch = p_string[pi];
							}
						field2[pi2] = '\0';

						if(field2[pi2 - 1] == ')')
							{
								field2[pi2 - 1] = '\0';
							}

						s = strlen(field2);

						if(s != 0)
							{
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_func_call ARGV ");
										trace_rec_1();
									}

								p2 = strstr(field2, "argv");
								if(!p2)		
									{	
										if(fn_ct > 0)
											{
												for(I = 0;  I < fn_ct; I++)
													{
														ret = strcmp(field1, w_function[I].fn_name);
														if(ret == 0)
															{
																strcpy(field3, w_function[I].fn_fd1);
																wk_pass_1 = w_function[I].fn_pass_1;
															}
													}
											}

										x3 = 0;
										v = 0;
										for(v = 0; v < lv_ct; v++)
											{
												ret = strcmp(field3, lw_variable[v].lv_name);
 												ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
												if((ret == 0)  && (ret1 == 0))
													{
														x3 = 1;
														strcpy(field3a, lw_variable[v].lv_cname);
														lw_variable[v].lv_use_ct++;
													}
											}

										if(x3 == 0)
											{
												for(v = 0; v < gv_ct; v++)
													{
														ret = strcmp(field3, gw_variable[v].gv_name);
														if(ret == 0)
															{
																x3 = 1;
																strcpy(field3a, gw_variable[v].gv_cname);
																gw_variable[v].gv_use_ct++;
															}
													}
											}

										if(x3 == 0)
											{
												c_name++;
												snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
												strcpy(field3a, "C37F");
												strcat(field3a, wk_strg);
												x4 = strlen(field3a);
												field3a[x4] = '\0';
	
												if(global_st == 0)
													{
														if(gv_ct == 0)
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
														strcpy(gw_variable[gv_ct].gv_cname, field3a);	
														strcpy(gw_variable[gv_ct].gv_name, field3); 
														if(wk_pass_1 == 1)
															{
																printf("c2_func_call E-80 wk_pass_1 NOT CODED\n");
																printf("c2_func_call rct = %d p_string = %s",rct,p_string);
																exit(1);
															}
														if(wk_pass_1 == 2)
															{ 	             
																strcpy(gw_variable[gv_ct].gv_type, "C");
																gw_variable[gv_ct].gv_id = 3;
															}
														gw_variable[gv_ct].gv_lgth = 0;
														gw_variable[gv_ct].gv_current_lgth = 0;
														strcpy(gw_variable[gv_ct].gv_value, null_field);
														gw_variable[gv_ct].gv_init = 0;
														strcpy(gw_variable[gv_ct].gv_literal,null_field);
														gw_variable[gv_ct].gv_use_ct = 0;
														gw_variable[gv_ct].gv_dec = 0;
														gv_ct++;
													}

												if(global_st == 1)
													{
														printf("c2_func_call comma = 0 E-82 NOT CODED\n");
														c2_error();
													}
											}
									}
							}

						s = strlen(field1);

						if(fd2_type == 0)		/* special character	*/
							{
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_func_call fd2_type = 0 #10");
										trace_rec_1();
									}

								x2 = 0;
								for(I=0; I < char_ct; I++)
									{
										if((w_charlit[I].clit_rct == rct) && (w_charlit[I].clit_uct == 1))
											{
												x2 = 1;
												strcpy(field2, w_charlit[I].clit_cname);
                                                      					x3 = w_charlit[I].clit_lgth;
											}
									}

								if(x2 == 0)
									return;

								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, field3a);
                            				strcpy(wk_remark, " ");
								strcat(wk_remark, field3);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_func_call fd2_type = 0 #11");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field2);
								src_line();
                            				if(punch_code == 1)
									{
										strcpy(trace_1, "c2_func_call fd2_type = 0 #12");
										trace_rec_3();
									}

								strcpy(a_string, "         MVC   0(");
								snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
								strcat(a_string, wk_strg);
								strcat(a_string, ",R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_func_call fd2_type = 0 #13");
										trace_rec_3();
									}

								x3 = 0;
								for(I=0; I < fn_ct; I++)
									{
										ret = strcmp(field1, w_function[I].fn_name);
										if(ret == 0)
											{
												x3 = 1;
												strcpy(field1a, w_function[I].fn_cname);
											}
									}

								if(x3 == 0)
									{
										printf("c2z_function.c c2_func_call comma_ct == 0 E-83 field1 Not Found = %s\n",field1);
										c2_error();
									}
							}

						if(fd2_type == 1)
							{
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_func_call fd2_type = 1 #1");
										trace_rec_1();
									}

								x3 = 0;
								v = 0;
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(field2, lw_variable[v].lv_name);
 										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if((ret == 0)  && (ret1 == 0))
											{
												x3 = 1;
												strcpy(field2a, lw_variable[v].lv_cname);
												lw_variable[v].lv_use_ct++;
												ret2 = strcmp("I", lw_variable[v].lv_type);
												if(ret2 == 0)
													{
														fd2a_type = 1;
													}
												else
													{
														fd2a_type = 2;
													}
											}
									}

								if(x3 == 0)
									{
										for(v = 0; v < gv_ct; v++)
											{
												ret = strcmp(field2, gw_variable[v].gv_name);
												if(ret == 0)
													{
														x3 = 1;
														strcpy(field2a, gw_variable[v].gv_cname);
														gw_variable[v].gv_use_ct++;
														ret2 = strcmp("I", gw_variable[v].gv_type);
														if(ret2 == 0)
															{
																fd2a_type = 1;
															}
														else
															{
																fd2a_type = 2;
															}
													}
											}
									}

								for(I=0; I < fn_ct; I++)
									{
										ret = strcmp(wk_sv_func, w_function[I].fn_name);
										if(ret == 0)
											{
												x3 = 1;
												strcpy(field4, w_function[I].fn_fd1);
											}
									}

								x3 = 0;
								v = 0;
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(field4, lw_variable[v].lv_name);
 										ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
										if((ret == 0)  && (ret1 == 0))
											{
												x3 = 1;
												strcpy(field4a, lw_variable[v].lv_cname);
												lw_variable[v].lv_use_ct++;
												ret2 = strcmp("I", lw_variable[v].lv_type);
												if(ret2 == 0)
													{
														fd4a_type = 1;
													}
												else
													{
														fd4a_type = 2;
													}

											}
									}

								if((fd2a_type == 1) && (fd4a_type == 1))
									{
										strcpy(a_string, "         LARL  R9,");
										strcat(a_string, field4a);
										strcpy(wk_remark, " ");
										strcat(wk_remark, field4);
										strcat(wk_remark, " */");
										write_remark();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2_func_call fd2_type = 1 #2");
												trace_rec_3();
											}

										strcpy(a_string, "         LARL  R8,");
										strcat(a_string, field2a);
										strcpy(wk_remark, " ");
										strcat(wk_remark, field2);
										strcat(wk_remark, " */");
										write_remark();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2_func_call fd2_type = 1 #3");
												trace_rec_3();
											}

										strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2_func_call fd2_type = 1 #4");
												trace_rec_3();
											}
									}

								if((fd2a_type == 2) && (fd4a_type == 2))
									{

										strcpy(a_string, "         LARL  R9,");
										strcat(a_string, field4a);
										strcpy(wk_remark, " ");
										strcat(wk_remark, field4);
										strcat(wk_remark, " */");
										write_remark();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2_func_call fd2_type = 1 #5");
												trace_rec_3();
											}

										strcpy(a_string, "         LARL  R8,");
										strcat(a_string, field2a);
										strcpy(wk_remark, " ");
										strcat(wk_remark, field2);
										strcat(wk_remark, " */");
										write_remark();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2_func_call fd2_type = 1 #6");
												trace_rec_3();
											}

										snprintf(wk_strg, sizeof(wk_strg), "%d", fd2_type);

										strcpy(a_string, "         MVC   0(");
										strcat(a_string, wk_strg);
										strcat(a_string, ",R9),0(R8)");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2_func_call fd2_type = 1 #7");
												trace_rec_3();
											}
									}
							}
	
						if(fd2_type == 2)
							{
								printf("c2_func_call comma = 0 fd2_type = 2 NOT FINISHED\n");
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_func_call fd2_type = 2 ");
										trace_rec_1();
									}
							}

						if_convert = 1;
					}
			}		

		strcpy(org_sv_func, sv_func);

		s = strlen(field1a);
		if(s != 0)
			{
				strcpy(a_string, "         BRASL C370LNK,");
				strcat(a_string,field1a);
				strcpy(wk_remark, " branch   */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_func_call #99");
						trace_rec_3();
					}
			}

		strcpy(sv_func, org_sv_func);

		convert = 1;
	}


/* ***************************************************
*  Punch out function user subroutine                *
* ************************************************** */
void c2_func_sub()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub");
				trace_rec_1();
			}

		int comma_ct = 0;
		inside_void = 2;
		int I = 0;
		int s = 0;
		int pi;
		int pi2;
		int ret = 0;
		int no_variables = 0;

		char ch;
		char *p, *p1;
		char field2[VAR_LGTH];
		
		char ar_field1a[VAR_LGTH];
		char ar_field2a[VAR_LGTH];
		char ar_field4a[VAR_LGTH];
		char wk_sv_func[VAR_LGTH];
		char field2a[VAR_LGTH];
		
		s = strlen(p_string);
		for(I = 0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == ',')
					comma_ct++;
			}

		pi = 0;
		pi2 = 0;
		ch = p_string[pi];
			
		while(ch != ' ')
			{
				pi++;
				ch = p_string[pi];
			}
		
		if(pi2 >= 0)		
			{
				ret = 0;
				if(ret == 0)
					{
						while(ch == ' ')
							{
								pi++;
								ch = p_string[pi];
							}	
												
						pi2 = 0;
						while(ch != '(')
							{
								field2[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						field2[pi2] = '\0';
						strcpy(wk_sv_func, sv_func);
						strcpy(sv_func, field2); 
					}
			} 

		if(fn_ct > 0)
			{
				for(I = 0; I < fn_ct; I++)
					{
						ret = strcmp(field2, w_function[I].fn_name);
						if(ret == 0)
							{
								strcpy(field2a, w_function[I].fn_cname);
								strcpy(ar_field1a, w_function[I].fn_sv_reg_1);
								strcpy(ar_field2a, w_function[I].fn_sv_reg_2);
								strcpy(ar_field4a, w_function[I].fn_loop);
							}
					}
			}

		strcpy(a_string, "*");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #1");
				trace_rec_3();
			}

		strcpy(a_string,field2a);
		check_length();
		strcat(a_string, "DS    0H");
		strcpy(wk_remark," ");
		strcat(wk_remark, field2);
		strcat(wk_remark, " */"); 
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #2");
				trace_rec_3();
			}
		
		strcpy(a_string, "         LARL  R9,");
		strcat(a_string, ar_field4a);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #4");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370ONE");
		strcpy(wk_remark, " ");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #5");
				trace_rec_3();
			}
		work_use_ct[33]++;

		strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #6");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,");
		strcat(a_string, ar_field4a);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #7");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370ONE");
		strcpy(wk_remark, " ");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #8");
				trace_rec_3();
			}
		work_use_ct[33]++;

		strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #9");
				trace_rec_3();
			}

		strcpy(a_string, "         JLNE  L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcat(a_string, wk_strg);
		strcat(a_string, "A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #10");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,");
		strcat(a_string, ar_field1a);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #11");
				trace_rec_3();
			}

		strcpy(a_string, "         ST    C370LNK,0(,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #12");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcat(a_string, wk_strg);
		strcat(a_string, "D");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #13");
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
				strcpy(trace_1, "c2z_function.c c2_func_sub #14");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,");
		strcat(a_string, ar_field4a);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #15");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370TWO");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #16");
				trace_rec_3();
			}
		work_use_ct[34]++;

		strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #17");
				trace_rec_3();
			}

		strcpy(a_string, "         JLNE  L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcat(a_string, wk_strg);
		strcat(a_string, "D");
		src_line();
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #18");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,");
		strcat(a_string, ar_field2a);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #19");
				trace_rec_3();
			}

		strcpy(a_string, "         ST    C370LNK,0(,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #20");
				trace_rec_3();
			}

		strcpy(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcat(a_string, wk_strg);
		strcat(a_string, "D");
		check_length();
		strcat(a_string, "DS    0H");
		strcpy(wk_remark, " sub start */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_func_sub #21");
				trace_rec_3();
			}

		p = strstr(p_string, "()");
		if(p)
			{
				no_variables = 1;
			}

		if(no_variables == 0)		/* variables passed	*/
			{
				p1 = strstr(p_string, ",");
				if(p1)
					{
						comma_ct = 1;
					}

				if(comma_ct == 0)		/* at lease one variable	*/
					{
						pi++;
						ch = p_string[pi];
						while(ch != ' ')
							{
								pi++;
								ch = p_string[pi];
							}
						
						pi++;
						ch = p_string[pi];
						while(ch != ')')
							{
								pi++;
								ch = p_string[pi];
							}
					}	
			}		

		strcpy(ret_fn, sub_name);
			
		inside_fn = 1;
		inside_void = 2;

		convert = 1;
	}	


/* ***************************************************
*  Scan function user subroutine                     *
* ************************************************** */
void c2_scan_func()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_scan_func");
				trace_rec_1();
			}

		int comma_ct = 0;
		int I = 0;
		int s = 0;
		int ret = 0;
		int pi;
		int pi2;
		inside_void = 2;

		char ch;
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];
		field1[0] = '\0';
		field2[0] = '\0';
		
		s = strlen(p_string);
		for(I = 0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == ',')
					comma_ct++;
			}

		pi = 0;
		pi2 = 0;
		ch = p_string[pi];
			
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
		
		if(pi2 >= 0)		/* no blanks before key word function */
			{
				ret = strcmp(field1, "void");
				if(ret == 0)
					{
						while(ch == ' ')
							{
								pi++;
								ch = p_string[pi];
							}	
												
						pi2 = 0;
						while(ch != '(')
							{
								field2[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						
						field2[pi2] = '\0';
					}

				if(fn_ct > 0)
					{
						for(I = 0; I < fn_ct; I++)
							{
								ret = strcmp(field2, w_function[I].fn_name);
								if(ret == 0)
									{
										w_function[I].fn_start = rct;
									}
							}
					}
			
				ret = strcmp(field1, "INT");
				if(ret == 0)
					{
						while(ch == ' ')
							{
								pi++;
								ch = p_string[pi];
							}	
												
						pi2 = 0;
						while(ch != '(')
							{
								field2[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						
						field2[pi2] = '\0';
					}

				if(fn_ct > 0)
					{
						for(I = 0; I < fn_ct; I++)
							{
								ret = strcmp(field2, w_function[I].fn_name);
								if(ret == 0)
									{
										w_function[I].fn_start = rct;
									}
							}
					}
				strcpy(sv_func, field2);
			}
	}


void c2_scan_sub()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_function.c c2_scan_sub");
			}

		int pi;
		int pi2;
		int scn_1 = 0;
		int scn_2 = 0;
		int s = 0;
		int I = 0;
		int size = 0;
		int x10 = 0;
		int x4 = 0;
		int x5 = 0;

		char ch;
		char *p, *p1;
		char field1[VAR_LGTH];
		char tfield1[VAR_LGTH];
              char tfield2[VAR_LGTH];

		p = strstr(p_string, "/*");
		p1 = strstr(p_string, "*/");
		if((p) && (p1)) 
			{
				scn_1 = 1;
			}

		if(scn_1 == 0)
			{
				p = strstr(p_string,"default");
				if(p)
					{
						scn_1 = 1;
					}
			}

		if(scn_1 == 0)
			{
				p = strstr(p_string,"void");
				if(p)
					{
						scn_1 = 1;
					}
			}

		if(scn_1 == 0)
			{
				p = strstr(p_string, "=");
				if(p)
					{
						scn_1 = 1;
					}
			}

		p = strstr(p_string, "'='");
		if(p)
			{
				scn_1 = 0;
			}

		p = strstr(p_string, "'");
		if(p)
			{
				x10 = 1;
			}

		if(scn_1 == 0)
			{
				s = strlen(p_string);
				s--;
				for(I = 0; I < s; I++)
					{
						ch = p_string[I];
						if((ch != ' ') || (ch != '\t') || (ch != '\n') || (ch != '\r') || (ch != '{') || (ch != '}')) 
						  	{ 
								scn_2 = 1;
							}
					}
			}

		s = 0;
		x4 = 0;
		x5 = 0;
		s = strlen(p_string);
		for(I = 0; I < s; I++)
			{
				ch = p_string[I];
				
				if(ch == ' ')
					{
						x4++;
					}
				if(ch == '{')
					{
						x5++;
					}
				if(ch == '}')
					{
						x5++;
					}
			}
			
		s--;

		if((x4 + x5) == s)
			{
				return;
			}
		if((x4 == 0) && (x5 == 1) && (s < 5))
			{
				return;
			}
		if((x4 == 0) && (x5 == 0) && (s < 8))
			{
				return;
			}

		p = strstr(p_string, "else");

		if((scn_1 == 0) && (scn_2 != 0))
			{
				pi = 0;
				ch = p_string[pi];
				while((ch == ' ') || (ch == '\t') || (ch == '{'))
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				while(ch != '(')
					{
						if((ch != '\t') || (ch != '\n') || (ch != '\0') || (ch != '{') || (ch != '{') || (ch != ' '))
							{
								field1[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';
				s = strlen(field1);

				if(pi2 > 2)		/* load function_start table 	*/
					{
						if(fns_ct == 0)
							{
								size = 1;
								w_func_start = malloc(size * sizeof(struct func_start));
							}
						else
							{
								size = fns_ct + 1;
								w_func_start = realloc(w_func_start, size * sizeof(struct func_start));
							}

						w_func_start[fns_ct].fns_rct = rct;
						strcpy(w_func_start[fns_ct].fns_name, field1);	
      						fns_ct++;
					}

				if(x10 == 1)
					{

						pi = 0;
						pi2 = 0;
						ch = p_string[pi];
						while(ch != '\'')
							{
								pi++;
								ch = p_string[pi];
							}
						
						pi++;
						ch = p_string[pi];
						while(ch != ')')
							{
								if(ch != '\'')
									{
										tfield2[pi2] = ch;
										pi2++;
									}
								pi++;
								ch = p_string[pi];
							}
						tfield2[pi2] = '\0';


						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield1, c_wkname);
				
						if(char_ct == 0)
							{
								size = 1;
								w_charlit = malloc(size * sizeof(struct charlit));
							}
						else
							{
								size = char_ct + 1;
								w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
							}

						w_charlit[char_ct].clit_rct = rct;
						strcpy(w_charlit[char_ct].clit_cname, tfield1);	
      						strcpy(w_charlit[char_ct].clit_value, tfield2); 
						w_charlit[char_ct].clit_lgth = 1; 	 
						w_charlit[char_ct].clit_uct = 1;            
						char_ct++;
					}
			}
	}

void scan_func_name_1()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_function.c c2_scan_func_name_1");
     }

      int size = 0;
      int pi;
      int pi2;
      int x4;

     char ch;
     char *p;
     char *p1;
     char *p2;
     char *p3;
     char *p4;
     char *p5;
     char *p6;
     char *p7;
     char *p8;

     char field1[VAR_LGTH];
     char field1a[VAR_LGTH];
     char field2a[VAR_LGTH];
     char field3a[VAR_LGTH];
     char field4a[VAR_LGTH];
     char field5a[VAR_LGTH];

     convert = 0;
     field1[0] = '\0';

     p = strstr(p_string, "void");
     p1 = strstr(p_string, ";");
     p2 = strchr(p_string, '(');
     p3 = strchr(p_string, ')');
     p4 = strstr(p_string, "int");
     p5 = strstr(p_string, "print");
     p6 = strstr(p_string, "char");
     p7 = strstr(p_string, "(void)");

     if((p7) && (p2) && (p3) && (p6))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_scan_sub CHAR - VOID");
					}

				pi = 0;
				ch = p_string[pi];
				while((ch == ' ') || (ch == '\t')) 
					{
						pi++;
						ch = p_string[pi];
					}
								
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi++;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}
						
				pi2 = 0;
				while(ch != '(')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

				c_name++;			/* function compiler name	*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field1a, "C37F");
				strcat(field1a, wk_strg);
				x4 = strlen(field1a);
				field1a[x4] = '\0';

				c_name++;			
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field2a, "C37F");
				strcat(field2a, wk_strg);
				x4 = strlen(field2a);
				field2a[x4] = '\0';

				c_name++;			
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field3a, "C37F");
				strcat(field3a, wk_strg);
				x4 = strlen(field3a);
				field3a[x4] = '\0';

				c_name++;			
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field4a, "C37F");
				strcat(field4a, wk_strg);
				x4 = strlen(field4a);
				field4a[x4] = '\0';

				if(fn_ct == 0)
					{
						size = 1;
						w_function = malloc(size * sizeof(struct functions));
					}
				else
					{
						size = fn_ct + 1;
						w_function = realloc(w_function, size * sizeof(struct functions));
					}

				w_function[fn_ct].fn_rct = rct;	
      				strcpy(w_function[fn_ct].fn_name, field1);
				strcpy(w_function[fn_ct].fn_cname, field1a);
				strcpy(w_function[fn_ct].fn_sv_reg_1, field2a);
				strcpy(w_function[fn_ct].fn_sv_reg_2, field3a);
				strcpy(w_function[fn_ct].fn_loop, field4a);
				w_function[fn_ct].fn_level = 0;
                          	w_function[fn_ct].fn_return = 0; 
				strcpy(w_function[fn_ct].fn_fd1, null_field);
				strcpy(w_function[fn_ct].fn_fd2, null_field);
				strcpy(w_function[fn_ct].fn_fd3, null_field);
				strcpy(w_function[fn_ct].fn_fd4, null_field);
				strcpy(w_function[fn_ct].fn_fd5, null_field);
				strcpy(w_function[fn_ct].fn_fd6, null_field);
				strcpy(w_function[fn_ct].fn_fd7, null_field);
				strcpy(w_function[fn_ct].fn_fd8, null_field);
				strcpy(w_function[fn_ct].fn_fd9, null_field);
				strcpy(w_function[fn_ct].fn_loop_use,field5a);
				w_function[fn_ct].fn_eof = 0; 
				w_function[fn_ct].fn_pass_1 = 0;
				w_function[fn_ct].fn_pass_2 = 0;
				w_function[fn_ct].fn_pass_3 = 0;
				w_function[fn_ct].fn_pass_4 = 0;
				w_function[fn_ct].fn_pass_5 = 0;
				w_function[fn_ct].fn_pass_6 = 0;
				w_function[fn_ct].fn_pass_7 = 0;
				w_function[fn_ct].fn_pass_8 = 0;
				w_function[fn_ct].fn_pass_9 = 0;

				p8 = strstr(p_string, "(int");
				if(p8)
					{
					 	w_function[fn_ct].fn_pass_1 = 1;
					}
				
				p8 = strstr(p_string, "int)");
				if(p8)
					{
						w_function[fn_ct].fn_pass_2 = 1;
					}	
				
				p8 = strstr(p_string, "(char");
				if(p8)
					{
						w_function[fn_ct].fn_pass_1 = 2;
					}
	
				fn_ct++;
 				
	
				if(gv_ct == 0)
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
				strcpy(gw_variable[gv_ct].gv_cname, field2a);	
				strcpy(gw_variable[gv_ct].gv_name, field2a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

				if(gv_ct == 0)
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
				strcpy(gw_variable[gv_ct].gv_cname, field3a);	
				strcpy(gw_variable[gv_ct].gv_name, field3a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

				if(gv_ct == 0)
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
				strcpy(gw_variable[gv_ct].gv_cname, field4a);	
				strcpy(gw_variable[gv_ct].gv_name, field4a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "I");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 1;
				gv_ct++;

				convert = 1;

				return;
			}

		if((p) && (p1)) 	/* void a_bort(int, int);		*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_scan_sub VOID 2 - int");
					}

				pi = 0;
				ch = p_string[pi];
				while((ch == ' ') || (ch == '\t')) 
					{
						pi++;
						ch = p_string[pi];
					}
								
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi++;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}
						
				pi2 = 0;
				while(ch != '(')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

				c_name++;			/* function compiler name	*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field1a, "C37F");
				strcat(field1a, wk_strg);
				x4 = strlen(field1a);
				field1a[x4] = '\0';

				c_name++;			
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field2a, "C37F");
				strcat(field2a, wk_strg);
				x4 = strlen(field2a);
				field2a[x4] = '\0';

				c_name++;			
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field3a, "C37F");
				strcat(field3a, wk_strg);
				x4 = strlen(field3a);
				field3a[x4] = '\0';

				c_name++;			
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field4a, "C37F");
				strcat(field4a, wk_strg);
				x4 = strlen(field4a);
				field4a[x4] = '\0';

				if(fn_ct == 0)
					{
						size = 1;
						w_function = malloc(size * sizeof(struct functions));
					}
				else
					{
						size = fn_ct + 1;
						w_function = realloc(w_function, size * sizeof(struct functions));
					}

				w_function[fn_ct].fn_rct = rct;	
      				strcpy(w_function[fn_ct].fn_name, field1);
				strcpy(w_function[fn_ct].fn_cname, field1a);
				strcpy(w_function[fn_ct].fn_sv_reg_1, field2a);
				strcpy(w_function[fn_ct].fn_sv_reg_2, field3a);
				strcpy(w_function[fn_ct].fn_loop, field4a);
				w_function[fn_ct].fn_level = 0;
                          	w_function[fn_ct].fn_return = 0; 
				strcpy(w_function[fn_ct].fn_fd1, null_field);
				strcpy(w_function[fn_ct].fn_fd2, null_field);
				strcpy(w_function[fn_ct].fn_fd3, null_field);
				strcpy(w_function[fn_ct].fn_fd4, null_field);
				strcpy(w_function[fn_ct].fn_fd5, null_field);
				strcpy(w_function[fn_ct].fn_fd6, null_field);
				strcpy(w_function[fn_ct].fn_fd7, null_field);
				strcpy(w_function[fn_ct].fn_fd8, null_field);
				strcpy(w_function[fn_ct].fn_fd9, null_field);
				strcpy(w_function[fn_ct].fn_loop_use,field5a);
				w_function[fn_ct].fn_eof = 0; 
				w_function[fn_ct].fn_pass_1 = 0;
				w_function[fn_ct].fn_pass_2 = 0;
				w_function[fn_ct].fn_pass_3 = 0;
				w_function[fn_ct].fn_pass_4 = 0;
				w_function[fn_ct].fn_pass_5 = 0;
				w_function[fn_ct].fn_pass_6 = 0;
				w_function[fn_ct].fn_pass_7 = 0;
				w_function[fn_ct].fn_pass_8 = 0;
				w_function[fn_ct].fn_pass_9 = 0;

				p8 = strstr(p_string, "(int");
				if(p8)
					{
					 	w_function[fn_ct].fn_pass_1 = 1;
					}
				
				p8 = strstr(p_string, "int)");
				if(p8)
					{
						w_function[fn_ct].fn_pass_2 = 1;
					}	
				
				p8 = strstr(p_string, "(char");
				if(p8)
					{
						w_function[fn_ct].fn_pass_1 = 2;
					}
	
				fn_ct++;

				if(gv_ct == 0)
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
				strcpy(gw_variable[gv_ct].gv_cname, field2a);	
				strcpy(gw_variable[gv_ct].gv_name, field2a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

				if(gv_ct == 0)
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
				strcpy(gw_variable[gv_ct].gv_cname, field3a);	
				strcpy(gw_variable[gv_ct].gv_name, field3a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

				if(gv_ct == 0)
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
				strcpy(gw_variable[gv_ct].gv_cname, field4a);	
				strcpy(gw_variable[gv_ct].gv_name, field4a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "I");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 1;
				gv_ct++;

				convert = 1;
			}

		p = strstr(p_string, "void");
		p1 = strstr(p_string, ";");
		p2 = strchr(p_string, '(');
		p3 = strchr(p_string, ')');
		p4 = strstr(p_string, "int");
		p5 = strstr(p_string, "print");

		if((p4) && (p2) && (p3) && (p1) && (!p5) && (convert == 0)) 	/* INT procedure INT get_upper(int, int);		*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_1.c c2_scan_sub INT 2 - int");
					}

				pi = 0;
				ch = p_string[pi];
				while((ch == ' ') || (ch == '\t'))
					{
						pi++;
						ch = p_string[pi];
					}
								
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi++;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}
								
				pi2 = 0;
				while(ch != '(')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

				c_name++;			/* function compiler name	*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field1a, "C37F");
				strcat(field1a, wk_strg);
				x4 = strlen(field1a);
				field1a[x4] = '\0';

				c_name++;			
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field2a, "C37F");
				strcat(field2a, wk_strg);
				x4 = strlen(field2a);
				field2a[x4] = '\0';

				c_name++;			
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field3a, "C37F");
				strcat(field3a, wk_strg);
				x4 = strlen(field3a);
				field3a[x4] = '\0';

				c_name++;			
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field4a, "C37F");
				strcat(field4a, wk_strg);
				x4 = strlen(field4a);
				field4a[x4] = '\0';

				if(fn_ct == 0)
					{
						size = 1;
						w_function = malloc(size * sizeof(struct functions));
					}
				else
					{
						size = fn_ct + 1;
						w_function = realloc(w_function, size * sizeof(struct functions));
					}

				w_function[fn_ct].fn_rct = rct;	
      				strcpy(w_function[fn_ct].fn_name, field1);
				strcpy(w_function[fn_ct].fn_cname, field1a);
				strcpy(w_function[fn_ct].fn_sv_reg_1, field2a);
				strcpy(w_function[fn_ct].fn_sv_reg_2, field3a);
				strcpy(w_function[fn_ct].fn_loop, field4a);
				w_function[fn_ct].fn_level = 0;
				w_function[fn_ct].fn_return = 0; 
				strcpy(w_function[fn_ct].fn_fd1, null_field);
				strcpy(w_function[fn_ct].fn_fd2, null_field);
				strcpy(w_function[fn_ct].fn_fd3, null_field);
				strcpy(w_function[fn_ct].fn_fd4, null_field);
				strcpy(w_function[fn_ct].fn_fd5, null_field);
				strcpy(w_function[fn_ct].fn_fd6, null_field);
				strcpy(w_function[fn_ct].fn_fd7, null_field);
				strcpy(w_function[fn_ct].fn_fd8, null_field);
				strcpy(w_function[fn_ct].fn_fd9, null_field);
				strcpy(w_function[fn_ct].fn_loop_use,field5a);
				w_function[fn_ct].fn_eof = 0; 
				w_function[fn_ct].fn_pass_1 = 0;
				w_function[fn_ct].fn_pass_2 = 0;
				w_function[fn_ct].fn_pass_3 = 0;
				w_function[fn_ct].fn_pass_4 = 0;
				w_function[fn_ct].fn_pass_5 = 0;
				w_function[fn_ct].fn_pass_6 = 0;
				w_function[fn_ct].fn_pass_7 = 0;
				w_function[fn_ct].fn_pass_8 = 0;
				w_function[fn_ct].fn_pass_9 = 0;

				p8 = strstr(p_string, "(int");
				if(p8)
					{
					 	w_function[fn_ct].fn_pass_1 = 1;
					}
				
				p8 = strstr(p_string, "int)");
				if(p8)
					{
						w_function[fn_ct].fn_pass_2 = 1;
					}	
				
				p8 = strstr(p_string, "(char");
				if(p8)
					{
						w_function[fn_ct].fn_pass_1 = 2;
					}
				
				fn_ct++;

				if(gv_ct == 0)
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
				strcpy(gw_variable[gv_ct].gv_cname, field2a);	
				strcpy(gw_variable[gv_ct].gv_name, field2a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

				if(gv_ct == 0)
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
				strcpy(gw_variable[gv_ct].gv_cname, field3a);	
				strcpy(gw_variable[gv_ct].gv_name, field3a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

				if(gv_ct == 0)
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
				strcpy(gw_variable[gv_ct].gv_cname, field4a);	
				strcpy(gw_variable[gv_ct].gv_name, field4a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "I");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 1;
				gv_ct++;

				convert = 1;
			}

		if((p7) && (p2) && (p3) && (p))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_function.c c2_scan_sub CHAR - VOID");
					}

				pi = 0;
				ch = p_string[pi];
				while((ch == ' ') || (ch == '\t')) 
					{
						pi++;
						ch = p_string[pi];
					}
								
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi++;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}
						
				pi2 = 0;
				while(ch != '(')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

				c_name++;			/* function compiler name	*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field1a, "C37F");
				strcat(field1a, wk_strg);
				x4 = strlen(field1a);
				field1a[x4] = '\0';

				c_name++;			
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field2a, "C37F");
				strcat(field2a, wk_strg);
				x4 = strlen(field2a);
				field2a[x4] = '\0';

				c_name++;			
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field3a, "C37F");
				strcat(field3a, wk_strg);
				x4 = strlen(field3a);
				field3a[x4] = '\0';

				c_name++;			
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field4a, "C37F");
				strcat(field4a, wk_strg);
				x4 = strlen(field4a);
				field4a[x4] = '\0';

				if(fn_ct == 0)
					{
						size = 1;
						w_function = malloc(size * sizeof(struct functions));
					}
				else
					{
						size = fn_ct + 1;
						w_function = realloc(w_function, size * sizeof(struct functions));
					}

				w_function[fn_ct].fn_rct = rct;	
      				strcpy(w_function[fn_ct].fn_name, field1);
				strcpy(w_function[fn_ct].fn_cname, field1a);
				strcpy(w_function[fn_ct].fn_sv_reg_1, field2a);
				strcpy(w_function[fn_ct].fn_sv_reg_2, field3a);
				strcpy(w_function[fn_ct].fn_loop, field4a);
				w_function[fn_ct].fn_level = 0;
                          	w_function[fn_ct].fn_return = 0; 
				strcpy(w_function[fn_ct].fn_fd1, null_field);
				strcpy(w_function[fn_ct].fn_fd2, null_field);
				strcpy(w_function[fn_ct].fn_fd3, null_field);
				strcpy(w_function[fn_ct].fn_fd4, null_field);
				strcpy(w_function[fn_ct].fn_fd5, null_field);
				strcpy(w_function[fn_ct].fn_fd6, null_field);
				strcpy(w_function[fn_ct].fn_fd7, null_field);
				strcpy(w_function[fn_ct].fn_fd8, null_field);
				strcpy(w_function[fn_ct].fn_fd9, null_field);
				strcpy(w_function[fn_ct].fn_loop_use,field5a);
				w_function[fn_ct].fn_eof = 0; 
				w_function[fn_ct].fn_pass_1 = 0;
				w_function[fn_ct].fn_pass_2 = 0;
				w_function[fn_ct].fn_pass_3 = 0;
				w_function[fn_ct].fn_pass_4 = 0;
				w_function[fn_ct].fn_pass_5 = 0;
				w_function[fn_ct].fn_pass_6 = 0;
				w_function[fn_ct].fn_pass_7 = 0;
				w_function[fn_ct].fn_pass_8 = 0;
				w_function[fn_ct].fn_pass_9 = 0;

				p8 = strstr(p_string, "(int");
				if(p8)
					{
					 	w_function[fn_ct].fn_pass_1 = 1;
					}
				
				p8 = strstr(p_string, "int)");
				if(p8)
					{
						w_function[fn_ct].fn_pass_2 = 1;
					}	
				
				p8 = strstr(p_string, "(char");
				if(p8)
					{
						w_function[fn_ct].fn_pass_1 = 2;
					}
	
				fn_ct++;
 				
	
				if(gv_ct == 0)
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
				strcpy(gw_variable[gv_ct].gv_cname, field2a);	
				strcpy(gw_variable[gv_ct].gv_name, field2a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

				if(gv_ct == 0)
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
				strcpy(gw_variable[gv_ct].gv_cname, field3a);	
				strcpy(gw_variable[gv_ct].gv_name, field3a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

				if(gv_ct == 0)
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
				strcpy(gw_variable[gv_ct].gv_cname, field4a);	
				strcpy(gw_variable[gv_ct].gv_name, field4a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "I");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 1;
				gv_ct++;

				convert = 1;

				return;
			}

	}






