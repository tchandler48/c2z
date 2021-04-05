/* ***************************************************
*  c2z : c2Z_for.c :                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* *************************************************** 
*  Punch out FOR statement                           *
* ************************************************** */
void c2_for(void)
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_for.c c2_for");
				trace_rec_1();
			}

		char ch;
		char *p, *p1, *p2, *p3, *p4, *p5, *p6;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield4[VAR_LGTH];
		char tfield5[VAR_LGTH];
		char tfield5a[VAR_LGTH];
		char tfield6[VAR_LGTH];
		char tfield6a[VAR_LGTH];
		
		inside_for = 1;
		for_opr = 0;
		
		tfield1[0] = '\0';
		tfield3[0] = '\0';
		tfield4[0] = '\0';
		tfield6[0] = '\0';
		
		tfield1a[0] = '\0';
		tfield3a[0] = '\0';
		tfield6a[0] = '\0';
		
		int pi;
		int pi2;
		int x2 = 0;
		int x3 = 0;
		int I = 0;
		int x = 0;
		int x10 = 0;
		int x11 = 0;
		int ret = 0;
		int ret1 = 0;
		int ret2 = 0;
		int fd1_type = 0;
		int fd2_type = 0;
		int fd3_type = 0;
		int fd5_type = 0;
				
		pi = 0;
		ch = p_string[pi];
								
		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			}

		x10 = 0;
		p = strstr(p_string, "(;");
		if(p)
			{
				x10 = 1;
			}

		if(x10 == 0)
			{
				pi2 = 0;
				x2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != '=')
					{
						if(ch != ' ')
							{
								if(x2 == 0)
									{
										if (isalpha(ch))	
											{
												fd1_type = 1;
												x2 = 1;
											}
 
										if (isdigit(ch)) 	
											{
												fd1_type = 2;
												x2 = 1;
											}
									}
	
								tfield1[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';
			}
		
		if(x10 == 0)
			{
				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0)  && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield1a, lw_variable[I].lv_cname);
								ret2 = strcmp(lw_variable[I].lv_type, "I");
								if(ret2 != 0)
									{
										printf("c2z_for.c c2_for E-54 tfield1 Not Numeric %s\n",tfield1);
										c2_error();
									}	
							}
					}
		
				if(x3 == 0)
					{	
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;		
										strcpy(tfield1a, gw_variable[I].gv_cname);
										ret1 = strcmp(gw_variable[I].gv_type, "I");
										if(ret1 != 0)
											{
												printf("c2z_for.c c2_for E-55 tfield1 Not Numeric %s\n",tfield1);
												c2_error();
											}	
									}
							}		
					}

				if(x3 == 0)
					{
						printf("c2z_for.c c2_for E-56 tfield1 Not Found = %s\n",tfield1);
						c2_error();
					}
			}

		if(x10 == 0)
			{
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
												fd2_type = 2;
												x2 = 1;
											}
									}
								tfield2[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';
			}
	
		if(x10 == 0)
			{
				strcpy(a_string, "         LARL  R9,C370LPCT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_for.c c2_for #1");
						trace_rec_3();
					}
				work_use_ct[73]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_for.c c2_for #2");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_for.c c2_for #3");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
              		strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1);
				strcat(wk_remark, " */");
	       		write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_for.c c2_for #4");
						trace_rec_3();
					}

				if(fd2_type == 1)
					{
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield1a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_for.c c2_for #5");
								trace_rec_3();
							}
					}

				if(fd2_type == 2)
					{

						ret = strcmp("0", tfield2);
						if(ret == 0)
							{
								strcpy(a_string, "         LARL  R8,C370ZERO");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_for.c c2_for #6");
										trace_rec_3();
									}
								x = 1;
							}
						else
							{
								x = 0;
								for(I=0; I < lit_ct; I++)
									{
										if((rct == w_literal[I].lit_rct) && (w_literal[I].lit_uct == 1))
											{
												ret = strcmp(tfield1, w_literal[I].lit_name);
												if((ret == 0) && (x == 0))
													{
														strcpy(a_string, "         LARL  R8,");
														strcat(a_string, w_literal[I].lit_cname);
														src_line();
       													if(punch_code == 1)
															{
																strcpy(trace_1, "c2z_for.c c2_for #7");
																trace_rec_3();
															}
														x = 1;
													}
											}
									}
							}
					}

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_for.c c2_for #8");
						trace_rec_3();
					}
			}
		
		strcpy(a_string, "         LARL  R9,C370NWK3");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_for.c c2_for #9");
				trace_rec_3();
			}
		work_use_ct[78]++;

		strcpy(a_string, "         LARL  R8,C370ZERO");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_for.c c2_for #10");
				trace_rec_3();
			}

		strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_for.c c2_for #11");
				trace_rec_3();
			}

		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcpy(a_string, "L");
		strcat(a_string, wk_strg);
		strcpy(while_tag, a_string);
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_for.c c2_for #12");
				trace_rec_3();
			}

		strcpy(sv_for_return, "L");
		strcat(sv_for_return, wk_strg);

		if(x10 == 1)
			{
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						pi++;
						ch = p_string[pi];
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
		x2 = 0;
		while(ch != ' ')
			{
				if(x2 == 0)
					{
						if (isalpha(ch))	
							{
								fd3_type = 1;
								x2 = 1;
							} 
						if (isdigit(ch)) 	
							{
								fd3_type = 2;
								x2 = 1;
							}
					}
				tfield3[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield3[pi2] = '\0';

		x3 = 0;
		x2 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(tfield3, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						ret2 = strcmp("I", lw_variable[I].lv_type);
						if(ret2 != 0)
							{
								printf("c2z_for.c c2_for E-57 tfield3 Not Numeric %s\n",tfield3);
								c2_error();
							}	
						x3 = 1;		
						strcpy(tfield3a, lw_variable[I].lv_cname);
					}
			}

		if(x3 == 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(tfield3, gw_variable[I].gv_name);
						if(ret == 0)
							{
								ret1 = strcmp("I", gw_variable[I].gv_type);
								if(ret1 != 0)
									{
										printf("c2z_for.c c2_for E-58 tfield3 Not Numeric %s\n",tfield3);
										c2_error();
									}	
								x3 = 1;		
								strcpy(tfield3a, gw_variable[I].gv_cname);
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_for.c c2_for E-59 tfield3 Not Found = %s\n",tfield3);
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
		while(ch != ' ')
			{
				tfield4[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield4[pi2] = '\0';

		if(for_opr == 0)
			{
				p6 = strstr(tfield4, "<=");
				if(p6)
					{
						for_opr = 6;
					}
			}

		if(for_opr == 0)
			{
				p5 = strstr(tfield4, ">=");
				if(p5)
					{
						for_opr = 5;
					}
			}

		if(for_opr == 0)
			{
				p4 = strstr(tfield4, "<");
				if(p4)
					{
						for_opr = 4;
					}
			}

		if(for_opr == 0)
			{
				p3 = strstr(tfield4, ">");
				if(p3)
					{
						for_opr = 3;
					}
			}

		if(for_opr == 0)
			{
				p2 = strstr(tfield4, "!=");
				if(p2)
					{
						for_opr = 2;
					}
			}

		if(for_opr == 0)
			{
				p1 = strstr(tfield4, "==");
				if(p1)
					{
						for_opr = 1;
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
		x2 = 0;
		while(ch != ';')
			{
				if(x2 == 0)
					{
						if (isalpha(ch))	
							{
								fd5_type = 1;
								x2 = 1;
							} 

						if (isdigit(ch)) 	
							{
								fd5_type = 2;
								x2 = 1;
							}
					}
				tfield5[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield5[pi2] = '\0';

		x3 = 0;
		if(fd5_type == 1)
			{
				x2 = 0;
				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield5, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								ret2 = strcmp("I", lw_variable[I].lv_type);
								if(ret2 != 0)
									{
										printf("c2z_for.c c2_for E-60 tfield5 Not Numeric %s\n",tfield5);
										c2_error();
									}	
								x3 = 1;		
								strcpy(tfield5a, lw_variable[I].lv_cname);
							}
					}						
				
				if(x3 == 0)
					{
						x3 = 0;
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield5, gw_variable[I].gv_name);
								if(ret == 0)
									{
										ret1 = strcmp(gw_variable[I].gv_type, "I");
										if(ret1 != 0)
											{
												printf("c2z_for.c c2_for E-61 tfield5 Not Numeric %s\n",tfield5);
												c2_error();
											}	
										x3 = 1;		
										strcpy(tfield5a, gw_variable[I].gv_cname);
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_for.c c2_for E-62 tfield5 Not Found = %s\n",tfield5);
						c2_error();
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
		x2 = 0;
		while(ch != '+')
			{
				if(x2 == 0)
					{
						if (isalpha(ch))	
							{
								x2 = 1;
							} 

						if (isdigit(ch)) 	
							{
								x2 = 1;
							}
					}
				if(ch != ' ')
					{
						tfield6[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		tfield6[pi2] = '\0';

		x3 = 0;
		x2 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(tfield6, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0)) 
					{
						ret2 = strcmp(lw_variable[I].lv_type, "I");
						if(ret2 != 0)
							{
								printf("c2z_for.c c2_for E-63 tfield6 Not Numeric %s\n",tfield3);
								c2_error();
							}	
						x3 = 1;		
						strcpy(tfield6a, lw_variable[I].lv_cname);
					}
			}
			
		if(x3 == 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(tfield6, gw_variable[I].gv_name);
						if(ret == 0)
							{
								ret1 = strcmp("I",gw_variable[I].gv_type);
								if(ret1 != 0)
									{
										printf("c2z_for.c c2_for E-64 tfield6 Not Numeric %s\n",tfield6);
										c2_error();
									}	
								x3 = 1;		
								strcpy(tfield6a, gw_variable[I].gv_cname);
							}
					}
			}	

		if(x3 == 0)
			{
				printf("c2z_for.c c2_for E-65 tfield4 Not Found = %s\n",tfield4);
				c2_error();
			}

		x11 = 0;
		p = strstr(p_string, "+=");
		if(p)
			{
				x11 = 1;
			}

		if(x11 == 1)
			{
				pi++;
				pi++;
				ch = p_string[pi];
				while(ch != ')')
					{
						pi++;
						ch = p_string[pi];
					}
			}
		strcpy(sv_for_incr, tfield6a);

		if(for_opr == 1)			
			{    
								
				if(fd1_type == 1)
					{	
						strcpy(a_string,"         LARL  R9,");
						strcat(a_string,tfield1a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_for.c c2_for #13");
								trace_rec_3();
							}
						
					}
				if(fd1_type == 2)
					{
						printf("c2z_for.c c2_for E-66 fd1_type == 2 NOT Coded\n");
						c2_error();
					}
				
				if(fd2_type == 1)
					{
						printf("c2z_for.c c2_for E-67 fd1_type == 1 NOT Coded\n");
						c2_error();
					}

				if(fd2_type == 2)
					{
						x = 0;
						for(I=0; I < lit_ct; I++)
							{
								if((rct == w_literal[I].lit_rct) && (w_literal[I].lit_uct == 1))
									{
										ret = strcmp(tfield1, w_literal[I].lit_name);
										if(ret == 0) 
											{
												if(x == 1)
													{
														strcpy(a_string, "         LARL  R8,");
														strcat(a_string, w_literal[I].lit_cname);
														src_line();
       													if(punch_code == 1)
															{
																strcpy(trace_1, "c2z_for.c c2_for #14");
																trace_rec_3();
															}
													}
												x = 1;
											}
									}
							}

						strcpy(a_string,"         LARL  R8,");
						strcat(a_string,tfield1a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_for.c c2_for #15");
								trace_rec_3();
							}
					}

				strcpy(a_string,"         CP    ");
				strcat(a_string, tfield1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_for.c c2_for #16");
						trace_rec_3();
					}

				strcpy(a_string, "         JNE   ");
				strcat(a_string, while_tag);
				strcat(a_string,"E");
			}

		if(for_opr == 2)
			{
				strcpy(a_string, "         JLE   ");
				strcat(a_string, sv_for_return);
				strcat(a_string, "E");
			}

		if(for_opr == 3)
			{
				printf("c2z_for.c c2_for E-68 for_opr == 3 NOT CODED\n");
				c2_error();
			}

		if(for_opr == 4)			
			{   
				if(fd3_type == 1)
					{
						strcpy(a_string,"         LARL  R9,");
						strcat(a_string,tfield3a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield3);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_for.c c2_for #15");
								trace_rec_3();
							}
					}

				if(fd5_type == 2)
					{
						x = 0;
						for(I=0; I < lit_ct; I++)
							{
								if((rct == w_literal[I].lit_rct) && (w_literal[I].lit_uct == 1))
									{
										strcpy(a_string, "         LARL  R8,");
										strcat(a_string, w_literal[I].lit_cname);
										src_line();
       									if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_for.c c2_for #16");
												trace_rec_3();
											}
										x = 1;
									}
							}
					}

				if(fd5_type == 1)
					{
						strcpy(a_string,"         LARL  R8,");
						strcat(a_string,tfield5a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield5);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_for.c c2_for #17");
								trace_rec_3();
							}
					}

				strcpy(a_string,"         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_for.c c2_for #18");
						trace_rec_3();
					}

				strcpy(a_string, "         JLH   ");
				strcat(a_string, sv_for_return);
				strcat(a_string,"E");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_for.c c2_for #19");
						trace_rec_3();
					}

				strcpy(a_string, "         JLE   ");
				strcat(a_string, sv_for_return);
				strcat(a_string,"E");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_for.c c2_for #20");
						trace_rec_3();
					}
			}

		if(for_opr == 5)
			{
				if(fd3_type == 1)
					{
						strcpy(a_string,"         LARL  R9,");
						strcat(a_string,tfield3a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield3);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_for.c c2_for #21");
								trace_rec_3();
							}
					}

				if(fd5_type == 2)
					{
						x = 0;
						for(I=0; I < lit_ct; I++)
							{
								if((rct == w_literal[I].lit_rct) && (w_literal[I].lit_uct == 1))
									{
										strcpy(a_string, "         LARL  R8,");
										strcat(a_string, w_literal[I].lit_cname);
										src_line();
       									if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_for.c c2_for #22");
												trace_rec_3();
											}
										x = 1;
									}
							}
					}

				if(fd5_type == 1)
					{
						strcpy(a_string,"         LARL  R8,");
						strcat(a_string,tfield5a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield5);
						strcat(wk_remark, " ");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_for.c c2_for #23");
								trace_rec_3();
							}
					}

				strcpy(a_string,"         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_for.c c2_for #24");
						trace_rec_3();
					}

				strcpy(a_string, "         JLL   ");
				strcat(a_string, sv_for_return);
				strcat(a_string,"E");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_for.c c2_for #25");
						trace_rec_3();
					}
			}
	
		if(for_opr == 6)
			{
				if(x11 == 0)
					{
						printf("c2z_for.c c2_for E-69 for_opr == 6 && x11 == 0 NOT CODED\n");
						c2_error();
					}

				if(x11 == 1)
					{
						if(fd3_type == 1)
							{
								strcpy(a_string,"         LARL  R9,");
								strcat(a_string,tfield3a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, tfield3);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_for #22");
										trace_rec_3();
									}
							}

						if(fd5_type == 2)
							{
								x = 0;
								for(I=0; I < lit_ct; I++)
									{
										if((rct == w_literal[I].lit_rct) && (w_literal[I].lit_uct == 1))
											{
										
												strcpy(a_string, "         LARL  R8,");
												strcat(a_string, w_literal[I].lit_cname);
												src_line();
       											if(punch_code == 1)
													{
														strcpy(trace_1, "c2_for #23");
														trace_rec_3();
													}
												x = 1;
											}
									}
							}

						if(fd5_type == 1)
							{
								strcpy(a_string,"         LARL  R8,");
								strcat(a_string,tfield5a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, tfield5);
								strcat(wk_remark, " ");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_for #24");
										trace_rec_3();
									}
							}

						strcpy(a_string,"         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2_for #25");
								trace_rec_3();
							}

						strcpy(a_string, "         JLH   ");
						strcat(a_string, sv_for_return);
						strcat(a_string,"E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2_for #26");
								trace_rec_3();
							}
					}
			}

		x3 = 0;
		for(I = 0; I < gv_ct; I++)
			{
				ret = strcmp(tfield1a, gw_variable[I].gv_cname);
				if(ret == 0)
					{
						x3 = 1;
						gw_variable[I].gv_use_ct++;
					}
			}

		if(x3 == 0)
			{
				for(I = 0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1a, lw_variable[I].lv_cname);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								lw_variable[I].lv_use_ct++;
							}
					}
			}

		x3 = 0;
		for(I = 0; I < gv_ct; I++)
			{
				ret = strcmp(tfield3a, gw_variable[I].gv_cname);
				if(ret == 0)
					{
						gw_variable[I].gv_use_ct++;
					}
			}
		
		if(x3 == 0)
			{
				for(I = 0; I < lv_ct; I++)
					{
						ret = strcmp(tfield3a, lw_variable[I].lv_cname);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								lw_variable[I].lv_use_ct++;
							}
					}
			}

		x3 = 0;
		for(I = 0; I < gv_ct; I++)
			{
				ret = strcmp(tfield6a, gw_variable[I].gv_cname);
				if(ret == 0)
					{
						gw_variable[I].gv_use_ct++;
					}
			}
		
		if(x3 == 0)
			{
				for(I = 0; I < lv_ct; I++)
					{
						ret = strcmp(tfield6a, lw_variable[I].lv_cname);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								lw_variable[I].lv_use_ct++;
							}
					}
			}

	}						
