/* ***************************************************
*  c2z : c2z_strcpy.c :                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */
    
/* ***************************************************
*  Punch out STRCPY                                  *
* ************************************************** */
void c2_strcpy(void)
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_strcpy.c c2_strcpy");
				trace_rec_1();
			}

		char *strg_srch;
		char ch;
		
		int pi;
		int str1 = 0;
		int str2 = 0;
		int str3 = 0;
		int str4 = 0;
		int str5 = 0;
		int str6 = 0;
		int str12 = 0;
		int str13 = 0;
		int str14 = 0;
	
		int I = 0;
		int s = 0;

		strg_srch = strrchr(p_string, ';');
		if(strg_srch == NULL)
			{
				printf("c2z_strcpy.c c2_strcpy Missing semi-colon at End of Line\n");
				printf("c2z_strcpy.c c2_strcpy rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}
		
		s = strlen(p_string);
		str1 = 0;	/* x */
		str2 = 0;	/* x2 */
		for(I = 0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '\"')
					{
						str1++;
						str2 = I;
					}
			}

		if(str1 != 0)
			{
				if(str1 != 2)
					{
						printf("c2z_strcpy.c c2_strcpy UNBALANCED QUOTES\n");
						printf("c2z_strcpy.c c2_strcpy rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1); 
					}
			}

		s = strlen(p_string);
		pi = 0;
		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}
 
		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			} 
		pi++;
		ch = p_string[pi];
		while(ch != ',')
			{
				pi++;
				ch = p_string[pi];
			}
		
		s = strlen(p_string);
		str1 = 0;	/* comma */
		str2 = 0;	/* [     */
		str3 = 0;	/* ]	  */
		str4 = 0;	/* 1st " */
		
		for(I = 0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == ',')
					{
						str1 = I;
						break;
					}
				if(ch == '[')
					str2 = I;
				if(ch == ']')
					str3 = I;
				if((ch == '"') && (str4 == 0))
					str4 = I;
			}

		for(I = str1; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '[')
					str12 = I;
				if(ch == ']')
					str13 = I;
				if((ch == '"') && (str4 == 0))
					str14 = I;
				if((str1 > 0) && (ch == '('))
					{
						str5 = I;
					}
				if((str1 > 0) && (ch == ')'))
					{
						/* str6 = I; */
					}
			}
	
		convert = 0;

		if((str1 < str14) && (convert == 0))								
			{
				c2_str_1(str1,str14);
				convert = 1;
			}

		if((str2 == 0) && (str3 == 0) && (str12 > 0) && (str13 > 0) && (convert == 0))		
			{
				c2_str_2(str1,str2);
				convert = 1;
			}

		if((str1 > str2) && (str2 > 0) && (str3 > 0) && (str12 == 0) && (str13 == 0) && (convert == 0))		
			{														
				c2_str_3(str1,str2);
				convert = 1;
			}

		if((str1 > 0) && (str2 == 0) && (str3 == 0) && (str4 == 0) && (str5 == 0) && (str6 == 0) && (convert == 0))	
			{
				c2_str_4();
				convert = 1;
			}

		if((str2 > 0) && (str3 > 0) && (str12 > 0) && (str13 > 0) && (convert == 0))			
			{
				c2_str_5();
				convert = 1;
			}

		if((str1 > 0) && (str2 == 0) && (str3 == 0) && (str4 == 0) && (str5 > str1) && (convert == 0))	
			{
				c2_str_6(); 
				convert = 1;
			}
	}


void c2_str_1(int str1, int str4)		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_strcpy.c c2_str_1");
				trace_rec_1();
			}

		char ch;
		char *p1, *p2, *p3;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		
		int pi;
		int pi2;
		int v = 0;
		int ret = 0;
		int ret1 = 0;
		int str5 = 0;
	       int x3 = 0;				
		int x6 = 0;
		int I = 0;

		p1 = strstr(p_string, "[");
		p2 = strstr(p_string, "]");
		p3 = strstr(p_string, ".");

		if((!p1) && (!p2) && (!p3))
			{
				if(str1 < str4)		
					{
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
								if(ch != ' ')
									{
										field1[pi2] = ch;
										pi2++;
									}
								pi++;
								ch = p_string[pi];
							}
						field1[pi2] = '\0';

						str5 = 0;
						if(lv_ct > 0)
							{
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(field1, lw_variable[v].lv_name);
										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												strcpy(field1a, lw_variable[v].lv_cname);
												lw_variable[v].lv_use_ct++;
												str5 = 1;
											}		
									}
							}	

						if(str5 == 0)
							{
								if(gv_ct > 0)
									{
										for(v = 0; v < gv_ct; v++)
											{
												ret = strcmp(field1, gw_variable[v].gv_name);
												if(ret == 0)
													{
														strcpy(field1a, gw_variable[v].gv_cname);
														gw_variable[v].gv_use_ct++;
														str5 = 1;
													}		
											}
									}
							}

						if(str5 == 0)
							{
								printf("c2z_strcpy c2_str_1 field1 Not Found = %s\n",field1);
								printf("c2z_strcpy c2_str_1 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
							}	

						pi++;
						ch = p_string[pi];
						while(ch == ' ')
							{
								pi++;
								ch = p_string[pi];
							}

						if(ch == '"')
							{	
								pi2 = 0;
								pi++;
								ch = p_string[pi];
										
								while(ch != '"')
									{
										field2[pi2] = ch;
										pi2++;
										pi++;
										x6++;
										ch = p_string[pi];
										if(ch == '\n')
											break;
										if(ch == '\t')
											break;
									}		
							}
						field2[pi2] = '\0';
printf("c2_strcpy field2 = %s p_string = %s",field2,p_string);


						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(field1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x6 = gw_variable[I].gv_current_lgth;
									}
							}

						if(x6 != 0)
							{
								for(I=0; I < char_ct; I++)
									{
										if(w_charlit[I].clit_rct == rct)
											{
												strcpy(field2a, w_charlit[I].clit_cname);
                                                      					x3 = w_charlit[I].clit_lgth;
											}
									}
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field1a);
                           		 	strcpy(wk_remark, " ");
						strcat(wk_remark, field1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_1 #1");
								trace_rec_3();
							}
	
						strcpy(a_string, "         LARL  R8,C370B1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_1 #2");
								trace_rec_3();
							}
						work_use_ct[52]++;

						strcpy(a_string, "         MVC   0(1,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_1 #3");
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
								strcpy(trace_1, "c2z_strcpy.c c2_str_1 #5");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field2a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_1 #6");
								trace_rec_3();
							}
				
						strcpy(a_string,"         MVC   ");
						strcat(a_string,"0(");
						snprintf(wk_strg, sizeof(wk_strg), "%d", x3);	
						strcat(a_string, wk_strg);
						strcat(a_string, ",R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_1 #7");
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
								strcpy(trace_1, "c2z_strcpy.c c2_str_1 #8");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370EOF");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_1 #9");
								trace_rec_3();
							}
				
						strcpy(a_string,"         MVC   ");
						snprintf(wk_strg, sizeof(wk_strg), "%d", x3);	
						strcat(a_string, wk_strg);
						strcat(a_string,"(1");
						strcat(a_string, ",R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_1 #10");
								trace_rec_3();
							}

						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(field1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										gw_variable[I].gv_current_lgth = x3;
                                                    
									}
							}
				
				/*		for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(gw_variable[I].gv_name, field2);
								if(ret == 0)
									{
										printf("c2z_strcpy.c E-419 c2_str_2 Undetermine \n");
										c2_error();
									}
							}
                            */
					}
			}

		if((p1) && (p2) && (p3))
			{
				printf("c2z_strcpy.c c2_str_1 E-420 NOT CODED \n");
				c2_error();
			}	

		convert = 1;

	}	
	

void c2_str_2(int str1, int str2)		/* strcpy(p_string, arrary1{line_ndx]")	*/ 
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_strcpy.c c2_str_2");
				trace_rec_1();
			}

		char ch;

		int pi;
		int pi2;
		int v = 0;
				
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field4[VAR_LGTH];
		char field5[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field8[VAR_LGTH];
		char field9[VAR_LGTH];
		char field10[VAR_LGTH];

		int str3 = 0;
		int str5 = 0;
		int str6 = 0;
		int str8 = 0;
		int str9 = 0;
		int I = 0;
		int x2 = 0;
             	int fd3_type = 0;
		int ret = 0;
		int ret1 = 0;

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
				if(ch != ' ')
					{
						field1[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		field1[pi2] = '\0';
		
		str5 = 0;
		if(lv_ct > 0)
			{
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field1, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								strcpy(field1a, lw_variable[v].lv_cname);
								lw_variable[v].lv_use_ct++;
                                                       	str5 = 1;
							}		
					}
			}	

		if(str5 == 0)
			{
				if(gv_ct > 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								str6 = strcmp(field1, gw_variable[v].gv_name);
								if(str6 == 0)
									{
										strcpy(field1a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
                                                                    	str5 = 1;
									}		
							}
					}
			}

		if(str5 == 0)
			{
				printf("c2z_strcpy.c c2_str_2 E-295 field1a Not Found %s\n",field1);
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
		while(ch != '[')
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

		str5 = 0;
		if(lv_ct > 0)
			{
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field2, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								strcpy(field2a, lw_variable[v].lv_cname);
								lw_variable[v].lv_use_ct++;
								str5 = 1;
							}		
					}
			}	

		if(str5 == 0)
			{
				if(gv_ct > 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								str6 = strcmp(field2, gw_variable[v].gv_name);
								if(str6 == 0)
									{
										strcpy(field2a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
										str5 = 1;
									}		
							}
					}
			}

		if(str5 == 0)
			{
				printf("c2z_strcpy.c c2_str_2 E-296 field2 Not Found %s\n",field2);
				c2_error();
			}	

		x2 = 0;
		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ']')
			{
				if(x2 == 0)
					{
						if (isdigit(ch)) 	
							{
								fd3_type = 1;
								x2 = 1;
							} 

						if (isalpha(ch))	
							{
								fd3_type = 2;
								x2 = 1;
							}
					}

				if(ch != ' ')
					{
						field3[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		field3[pi2] = '\0';

		if(fd3_type == 2)
			{
				str5 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field3, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0)) 
									{
										strcpy(field3a, lw_variable[v].lv_cname);
										lw_variable[v].lv_use_ct++;
										str5 = 1;
									}		
							}
					}	

				if(str5 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										str6 = strcmp(field3, gw_variable[v].gv_name);
										if(str6 == 0)
											{
												strcpy(field3a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
												str5 = 1;
											}		
									}
							}
					}

				if(str5 == 0)
					{
						printf("c2z_strcpy.c c2_str_2 E-297 field3 Not Found %s\n",field3);
						c2_error();
					}
			}	

		str8 = strcmp(field3,"ARGV");
		if(str8 == 0)		/* fixed system variable ARGV	*/
			{
				strcpy(a_string,"         MVC   ");
				strcat(a_string, field1a);
				strcat(a_string,",");
				strcat(a_string, field2);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_2 #1");
						trace_rec_3();
					}
			}

		if(str8 != 0)		/* not a system variable		*/
			{
				str2 = 0;
				if(lv_ct > 0)
					{
						for(I = 0; I < lv_ct; I++)
							{
								ret = strcmp(field2, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										str2 = 1;
										strcpy(field4, lw_variable[I].lv_type);
									}
							}
					}

				if(str2 == 0)
					{
						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										str1 = strcmp(field2, gw_variable[I].gv_name);
										if(str1 == 0)
											{
												strcpy(field4, gw_variable[I].gv_type);
											}
									}
							}
					}

				str3 = strcmp(field4, "A");
				if(str3 == 0)
					{
						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										str1 = strcmp(field2, gw_variable[I].gv_name);
										if(str1 == 0)
											{
												strcpy(field5, gw_variable[I].gv_dsect);
												strcpy(field6, gw_variable[I].gv_label);
												strcpy(field7, gw_variable[I].gv_table);
												strcpy(field8, gw_variable[I].gv_aname);
												strcpy(field9, gw_variable[I].gv_sv_reg);
												strcpy(field10, gw_variable[I].gv_wk_reg);
												x2 = gw_variable[I].gv_lgth;
											}
									}
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #2");
								trace_rec_3();
							}
						work_use_ct[49]++;

						strcpy(a_string, "         LARL  R8,C370ZERO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #3");
								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #4");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R6,");
						strcat(a_string, field7);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field2);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #5");
								trace_rec_3();
							}

						strcpy(a_string, "L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						check_length();
						strcat(a_string, "DS    0H");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #6");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #7");
								trace_rec_3();
							}
						work_use_ct[49]++;

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field3a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field3);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #8");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
					       if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #9");
								trace_rec_3();
							}

						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "A");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #10");
								trace_rec_3();
							}

						strcpy(a_string, "         LA    R6,");
						strcat(a_string, field6);
						strcat(a_string, "(R0,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #11");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #12");
								trace_rec_3();
							}
						work_use_ct[49]++;

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #13");
								trace_rec_3();
							}
						work_use_ct[33]++;

						strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #14");
								trace_rec_3();
							}
						
						strcpy(a_string, "         JLU   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #15");
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
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #16");
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
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #17");
								trace_rec_3();
							}

						strcpy(a_string, "         MVC   ");
						strcat(a_string, "0(");
						snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
						strcat(a_string, wk_strg);
						strcat(a_string, ",R9)");
						strcat(a_string, ",");
						strcat(a_string, "0(R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_2 #18");
								trace_rec_3();
							}
					}	

				str9 = strcmp(field4,"C");
				if(str9 == 0)
					{
						/* printf("c2z_strcpy.c c2_str_2 E-298 code character Not Coded\n");
						c2_error(); */
					}
			}	

		convert = 1;		
	}


void c2_str_3(int str1, int str2)		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_strcpy.c c2_str_3");
				trace_rec_1();
			}

		char *p, *p1;
		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield1b[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH]; 
		char tfield4[VAR_LGTH];
		char tfield5[VAR_LGTH];
		char tfield6[VAR_LGTH];
		char tfield7[VAR_LGTH];
		char tfield8[VAR_LGTH];
		char tfield9[VAR_LGTH];
		char tfield10[VAR_LGTH];
		char tfield11[VAR_LGTH];
					
		tfield1a[0] = '\0';
		tfield2a[0] = '\0';

		int pi;
		int pi2;
		int str3 = 0;
		int str5 = 0;
		int str6 = 0;
		int str7 = 0;
		int v = 0;
		int x2 = 0;				
		int x3 = 0;
		int x5 = 0;
		int x6 = 0;
		int x99 = 0;
		int I = 0;
		int s = 0;
		int ret = 0;
		int ret1 = 0;
   		int x90 = 0;
		int x91 = 0;
		int x95 = 0;
		int x96 = 0;
		int fd2_type = 0;
		int fd3_type = 0;

		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '[')
					{
						x90++;
					}
				if(ch == ']')
					{
						x91++;
					}
			}

		p1 = strstr(p_string, ".");

		if((x90 == 1) && (x91 == 1) && (!p1))		
			{
				pi = 0;
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}
		
				pi++;
				pi2 = 0;
				ch = p_string[pi];
				while(ch != '[')
					{
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				if(str1 < str2)		
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s");
								trace_rec_1();
							}

						str3 = 0;
						if(lv_ct > 0)
							{
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(tfield1, lw_variable[v].lv_name);
										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if(str5 == 0)
											{
												strcpy(tfield1a, lw_variable[v].lv_cname);
												lw_variable[v].lv_use_ct++;
												str7 = lw_variable[I].lv_lgth;
												str3 = 1;
											}		
									}
							}	
				
						if(str3 == 0)
							{
								if(gv_ct > 0)
									{
										for(v = 0; v < gv_ct; v++)
											{
												str5 = strcmp(tfield1, gw_variable[v].gv_name);
												if(str5 == 0)
													{
														strcpy(tfield1a, gw_variable[v].gv_cname);
														gw_variable[v].gv_use_ct++;
														str7 = gw_variable[I].gv_lgth;
														str3 = 1;
													}		
											}
									}
							}	

						if(str3 == 0)		
							{
								printf("c2z_strcpy.c c2_str_3 E-340 tfield1 Not Found = %s\n",tfield1);
								c2_error();
							}		

						pi++;
						ch = p_string[pi];
						while(ch == ' ')
							{
								pi++;
								ch = p_string[pi];
							}

						if(ch == '"')
							{	
								pi2 = 0;
								pi++;
								ch = p_string[pi];
										
								while(ch != '"')
									{
										tfield2[pi2] = ch;
										pi2++;
										pi++;
										ch = p_string[pi];
										if(ch == '\n')
											break;
										if(ch == '\t')
											break;
									}
								tfield2[pi2] = '\0';

								if(str7 != 0)
									{
										strcpy(a_string, "*         MVC   ");
										strcat(a_string, tfield1);
										snprintf(wk_strg, sizeof(wk_strg), "%d", str7);
										strcat(a_string, "(");
										strcat(a_string, wk_strg);
										strcat(a_string, ")");
										strcat(a_string, ",");
										strcat(a_string, "=CL");
										strcat(a_string, wk_strg);
										strcat(a_string, "' '");
										strcpy(wk_remark, " strcpy   */");
										write_remark();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_strcpy.c c2_str_3 #1");
												trace_rec_3();
											}
									}

								strcpy(a_string,"*         MVC   ");
								strcat(a_string, tfield1a);
								strcat(a_string,",=CL");
								s = strlen(tfield2);
								snprintf(wk_strg, sizeof(wk_strg), "%d", s);
								strcat(a_string,wk_strg);
								strcat(a_string, "'");
								strcat(a_string, tfield2);
								strcat(a_string, "'");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 #2");
										trace_rec_3();
									}

								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(tfield1, gw_variable[I].gv_name);
										if(ret == 0)
											{
												gw_variable[I].gv_current_lgth = s;
											}
									}
							} 
						else
							{
								pi2 = 0;
								x3 = 0;
								while((ch != ')') && (x3 == 0))
									{
										if(ch == '[')
											{
												x3 = 1;
											}
										if(x3 == 0)
											{
												tfield2[pi2] = ch;
												pi2++;
											}
										pi++;
										ch = p_string[pi];
									}
								tfield2[pi2] = '\0';

								if(gv_ct > 0)
									{
										for(v = 0; v < gv_ct; v++)
											{
												ret = strcmp(tfield2, gw_variable[v].gv_name);
												if(ret == 0)
													{
														strcpy(tfield2a, gw_variable[v].gv_cname);
														gw_variable[v].gv_use_ct++;
													}		
											}
									}	

								x5 = 0;
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(tfield1, gw_variable[I].gv_name);
										if(ret == 0)
											{
												x5 = gw_variable[I].gv_lgth;
											}
									}
						
								if(x5 != 0)
									{
										strcpy(a_string, "*         MVC   ");
										strcat(a_string, tfield1a);
										snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
										strcat(a_string, "(");
										strcat(a_string, wk_strg);
										strcat(a_string, ")");
										strcat(a_string, ",");
										strcat(a_string, "=CL");
										strcat(a_string, wk_strg);
										strcat(a_string, "' '");
										strcpy(wk_remark, " strcpy   */");
										write_remark();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_strcpy.c c2_str_3 #3");
												trace_rec_3();
											}
									}

								strcpy(a_string,"*         MVC   ");
								strcat(a_string, tfield1a);
								strcat(a_string,"(L'");
								strcat(a_string, tfield2a);
								strcat(a_string, "),");
								strcat(a_string, tfield2a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 #4");
										trace_rec_3();
									}
						
								if(x3 == 0)
									{
										printf("c2z_strcpy.c c2_str_3 E-341 ERROR in c2_strcpy\n");
										c2_error();
									}
							}
					}	

				if(str1 > str2)		
					{	
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s");
								trace_rec_1();
							}

						pi = 0;
						ch = p_string[pi];
						while(ch != '(')
							{
								pi++;
								ch = p_string[pi];
							}
		
						pi++;
						pi2 = 0;
						ch = p_string[pi];
						while(ch != '[')
							{
								tfield1[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						tfield1[pi2] = '\0';

						pi2 = 0;
						pi++;
						ch = p_string[pi];
						while(ch != ']')
							{
								tfield2[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						tfield2[pi2] = '\0';

						pi2 = 0;
						pi++;
						ch = p_string[pi];
						while(ch != ')')
							{
								if(ch != ',')
									{
										if(ch != ' ')
											{
												tfield3[pi2] = ch;
												pi2++;
											}
									}
								pi++;
								ch = p_string[pi];
							}
						tfield3[pi2] = '\0';

						str2 = 0;
						if(lv_ct > 0)
							{
								for(I = 0; I < lv_ct; I++)
									{
										ret = strcmp(tfield2, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												str2 = 1;
												strcpy(tfield2a, lw_variable[I].lv_cname);
												lw_variable[I].lv_use_ct++;
											}
									}
							}

						if(str2 == 0)
							{
								if(gv_ct > 0)
									{
										for(I = 0; I < gv_ct; I++)
											{
												str1 = strcmp(tfield2, gw_variable[I].gv_name);
												if(str1 == 0)
													{
														str2 = 1;
														strcpy(tfield2a, gw_variable[I].gv_cname);
													}
											}
									}
							}

						str2 = 0;
						if(lv_ct > 0)
							{
								for(I = 0; I < lv_ct; I++)
									{
										ret = strcmp(tfield1, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0)) 
											{
												str2 = 1;
												strcpy(tfield1b, lw_variable[I].lv_cname);
												lw_variable[I].lv_use_ct++;
												strcpy(tfield4, lw_variable[I].lv_type);
											}
									}
							}

						if(str2 == 0)
							{
								if(gv_ct > 0)
									{
										for(I = 0; I < gv_ct; I++)
											{
												str1 = strcmp(tfield1, gw_variable[I].gv_name);
												if(str1 == 0)
													{
														strcpy(tfield4, gw_variable[I].gv_type);
														strcpy(tfield1b, gw_variable[I].gv_cname);
													}
											}
									}
							}

						str3 = strcmp(tfield4, "A");
						if(str3 == 0)
							{
								if(gv_ct > 0)
									{
										for(I = 0; I < gv_ct; I++)
											{
												ret = strcmp(tfield1, gw_variable[I].gv_name);
												if(ret == 0)
													{
														strcpy(tfield5, gw_variable[I].gv_dsect);
														strcpy(tfield6, gw_variable[I].gv_label);
														strcpy(tfield7, gw_variable[I].gv_table);
														strcpy(tfield8, gw_variable[I].gv_aname);
														strcpy(tfield9, gw_variable[I].gv_sv_reg);
														strcpy(tfield10, gw_variable[I].gv_wk_reg);
														strcpy(tfield11, gw_variable[I].gv_wk_strg);
														gw_variable[I].gv_flag = 0;
														x99 = gw_variable[I].gv_lgth;
													}
											}
							
									}

								p = strstr(tfield3, "'\0'");
								if(p)
									{
										x6 = 1;
									}

								if(x6 == 0)
									{
										str6 = 0;
										for(I = 0; I < lv_ct; I++)
											{
												ret = strcmp(tfield3, lw_variable[I].lv_name);
												ret1 = strcmp(sv_func, lw_variable[I].lv_func);
												if((ret == 0) && (ret1 == 0))
													{
														str6 = 1;
														strcpy(tfield3a, lw_variable[I].lv_cname);
													}
											}

										if(str6 == 0)
											{
												for(I = 0; I < gv_ct; I++)
													{
														ret = strcmp(tfield3, gw_variable[I].gv_name);
														if(ret == 0)
															{
																str6 = 1;
																strcpy(tfield3a, gw_variable[I].gv_cname);
															}
													}
											}
									}

								if(str6 == 0)
									{
										printf("c2z_strcpy.c c2_str_3 E-342 tfield3 Not Found = %s\n",tfield3);
										c2_error();
									}
							
								strcpy(a_string, "         LARL  R9,C370NWK1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #6");
										trace_rec_3();
									}
								work_use_ct[49]++;

								strcpy(a_string, "         LARL  R8,C370ZERO");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #7");
										trace_rec_3();
									}
								work_use_ct[32]++;

								strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #8");
										trace_rec_3();
									}
	
								strcpy(a_string, "         LARL  R6,");
								strcat(a_string, tfield7);
								strcpy(wk_remark, " ");
								strcat(wk_remark, tfield1);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #9");
										trace_rec_3();
									}

								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcpy(a_string, "L");
								strcat(a_string, wk_strg);
								strcat(a_string, "B");
								check_length();
								strcat(a_string, "DS    0H");
								strcpy(wk_remark," str_3    */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #10");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370NWK1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #11");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,");
                                         			strcat(a_string, tfield2a);
                                         	 		strcpy(wk_remark, " ");
								strcat(wk_remark, tfield2);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #12");
										trace_rec_3();
									}

								strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #13");
										trace_rec_3();
									}

								strcpy(a_string,"         JLE   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								strcat(a_string, "F");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #14");
										trace_rec_3();
									}
								
								strcpy(a_string, "         LARL  R9,C370NWK1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #15");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370ONE");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #16");
										trace_rec_3();
									}

								strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #17");
										trace_rec_3();
									}

								strcpy(a_string,"         LA    R6,");
								strcat(a_string,tfield6);
								strcat(a_string, "(R0,R6)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #18");
										trace_rec_3();
									}

								strcpy(a_string,"         JLU   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								strcat(a_string, "B");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #19");
										trace_rec_3();
									}

								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcpy(a_string, "L");
								strcat(a_string, wk_strg);
								strcat(a_string, "F");
								check_length();
								strcat(a_string, "DS    0H");
								strcpy(wk_remark," str_3    */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #20");
										trace_rec_3();
									}

								strcpy(a_string,"         LARL R8,");
								strcat(a_string, tfield3a);
                                          		strcpy(wk_remark, " ");
								strcat(wk_remark, tfield3);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #21");
										trace_rec_3();
									}

								snprintf(wk_strg, sizeof(wk_strg), "%d", x99);
								strcpy(a_string,"         MVC   0(");
								strcat(a_string, wk_strg);
								strcat(a_string, ",R6),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s #22");
										trace_rec_3();
									}
							}	

						ret1 = strcmp(tfield2, "C");
						if(ret1 == 0)
							{
								if(gv_ct > 0)
									{
										for(I = 0; I < gv_ct; I++)
											{
												ret = strcmp(tfield1a, gw_variable[I].gv_cname);
												if(ret == 0)
													{
														strcpy(tfield5, gw_variable[I].gv_dsect);
														strcpy(tfield6, gw_variable[I].gv_label);
														strcpy(tfield7, gw_variable[I].gv_table);
														strcpy(tfield8, gw_variable[I].gv_aname);
														strcpy(tfield9, gw_variable[I].gv_sv_reg);
														strcpy(tfield10,gw_variable[I].gv_wk_reg);
													}
											}
									}
							}	
					}	
			}

		if((x90 == 2) && (x91 == 2) && (!p1))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_string.c c2_str_3 MULTI");
						trace_rec_1();
					}

				int pi;

				char ch;
				char tfield1[VAR_LGTH];
				char tfield1a[VAR_LGTH];

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
				while(ch != '[')
					{
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				pi2 = 0;
				x2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ']')
					{
						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										fd2_type = 1;
										x2 = 1;
									} 

								if (isalpha(ch))	
									{
										fd2_type = 2;
										x2 = 1;
									}
							}
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				while(ch != ',')
					{
						pi++;
						ch = p_string[pi];
					}

				x2 = 0;
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ')')
					{
						if(ch != ' ')
							{
								if(x2 == 0)
									{
										if (isdigit(ch)) 	
											{
												fd3_type = 1;
												x2 = 1;
											} 

										if (isalpha(ch))	
											{
												fd3_type = 2;
												x2 = 1;
											}
									}
								tfield3[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield3[pi2] = '\0';

				str6 = 0;
				for(I = 0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								str6 = 1;
								strcpy(tfield1a, lw_variable[I].lv_cname);
							}
					}

				if(str6 == 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										str6 = 1;
										strcpy(tfield1a, gw_variable[I].gv_cname);
										strcpy(tfield5, gw_variable[I].gv_dsect);
										strcpy(tfield6, gw_variable[I].gv_label);
										strcpy(tfield7, gw_variable[I].gv_table);
										strcpy(tfield8, gw_variable[I].gv_aname);
										strcpy(tfield9, gw_variable[I].gv_sv_reg);
										strcpy(tfield10,gw_variable[I].gv_wk_reg);
									}
							}
					}
									
				if(str6 == 0)
					{
						printf("c2z_strcpy.c c2_str_3 E-343 MULTI tfield1 Not Found = %s\n",tfield1);
						c2_error();
					}
					
				if(fd2_type == 2)			
					{
						str6 = 0;
						for(I = 0; I < lv_ct; I++)
							{
								ret = strcmp(tfield2, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										str6 = 1;
										strcpy(tfield2a, lw_variable[I].lv_cname);
									}
							}

						if(str6 == 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(tfield2, gw_variable[I].gv_name);
										if(ret == 0)
											{
												str6 = 1;
												strcpy(tfield2a, gw_variable[I].gv_cname);
											}
									}
							}
									
						if(str6 == 0)
							{
								printf("c2z_strcpy.c c2_str_3 E-344 MULTI tfield2 Not Found = %s\n",tfield2);
								c2_error();
							}
					}

				if(fd2_type == 1)			
					{
						printf("c2z_strcpy.c c2_str_3 E-345 MULTI fd2_type == 1 NOT CODED\n");
						c2_error();
					}

				if(fd3_type == 2)			
					{
						str6 = 0;
						for(I = 0; I < lv_ct; I++)
							{
								ret = strcmp(tfield3, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										str6 = 1;
										strcpy(tfield3a, lw_variable[I].lv_cname);
									}
							}

						if(str6 == 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(tfield3, gw_variable[I].gv_name);
										if(ret == 0)
											{
												str6 = 1;
												strcpy(tfield3a, gw_variable[I].gv_cname);
											}
									}
							}
									
						if(str6 == 0)
							{
								printf("c2z_strcpy.c c2_str_3 E-346 MULTI tfield3 Not Found = %s\n",tfield3);
								c2_error();
							}
					}

				if(fd3_type == 1)			
					{
						printf("c2z_strcpy.c c2_str_3 E-347 MULTI fd3type == 1 NOT CODED\n");
						c2_error();
					}

			}

		if((x90 == 1) && (x91 == 1) && (p1))		
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Structure");
						trace_rec_1();
					}

				char tfield5a[VAR_LGTH];
				char tfield6a[VAR_LGTH];
				
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
				while(ch != '[')
					{
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ']')
					{
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ',')
					{
						if(ch != '.')
							{
								tfield3[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield3[pi2] = '\0';

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

				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				while(ch != ')')
					{
						tfield5[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield5[pi2] = '\0';

				x3 = 0;
				for(I=0; I < m_struc_ct; I++)
					{
						ret = strcmp(tfield1, w_struc[I].st_wname);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(tfield1a, w_struc[I].st_cwname);
								strcpy(tfield6a, w_struc[I].st_cname);
								x90 = w_struc[I].st_field_lgth;
								break;
							}
					}

				if(x3 == 0)
					{
						printf("c2z_strcpy.c c2_str_3 Structure E-348 tfield1 Not Found = %s\n",tfield1);
						c2_error();
					}
				
				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield2, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield2a, lw_variable[I].lv_cname);	
							}
					}
		
				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield2,gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;		
										strcpy(tfield2a, gw_variable[I].gv_cname);	
									}
							}
					}
			
				if(x3 == 0)
					{
						printf("c2z_strcpy.c c2_str_3 E-349 tfield2 Not Found = %s\n",tfield2);
						c2_error();
					}


				x3 = 0;
				for(I=0; I < m_struc_ct; I++)
					{
						ret = strcmp(tfield1, w_struc[I].st_wname);
						ret1 = strcmp(tfield3, w_struc[I].st_field_name);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(tfield3a, w_struc[I].st_field_cname);
								x91 = w_struc[I].st_field_lgth;
								x95 = w_struc[I].st_disp;
							}
					}

				if(x3 == 0)
					{
						printf("c2z_strcpy.c c2_str_3 Structure E-350 tfield1 Not Found = %s\n",tfield1);
						printf("c2z_strcpy.c c2_str_3 Structure tfield3 Not Found = %s\n",tfield3);
						c2_error();
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield5, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield5a, lw_variable[I].lv_cname);
								x96 = lw_variable[I].lv_current_lgth;	
							}
					}
		
				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield5,gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;		
										strcpy(tfield5a, gw_variable[I].gv_cname);
										x96 = gw_variable[I].gv_current_lgth;	
									}
							}
					}
			
				if(x3 == 0)
					{
						printf("c2z_strcpy.c c2_str_3 E-351 tfield5 Not Found = %s\n",tfield5);
						c2_error();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #1");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #2");
 						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #3");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R6,");
                            strcat(a_string, tfield1a);
				strcat(a_string, "T");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #4");
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
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #5");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #6");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield2a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield2);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #7");
 						trace_rec_3();
					}
				
				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #8");
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
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #9");
 						trace_rec_3();
					}

				strcpy(a_string, "         LA    R6,");
				strcat(a_string, tfield6a);
				strcat(a_string, "L");
				strcat(a_string, "(R0,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #10");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #11");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #12");
 						trace_rec_3();
					}
				
				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #13");
 						trace_rec_3();
					}

				strcpy(a_string, "         JLU   ");
				strcat(a_string, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #14");
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
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #15");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield5a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield5);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #19");
 						trace_rec_3();
					}
				work_use_ct[32]++;

				snprintf(wk_strg, sizeof(wk_strg), "%d", x95);
				strcpy(a_string, "         MVC   ");
				strcat(a_string, wk_strg);
				strcat(a_string, "(");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
				strcat(a_string, wk_strg);
				strcat(a_string, ",R6),0(R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_3 Struc #22");
 						trace_rec_3();
					}
			}

		convert = 1;
	}


void c2_str_4()			
	{
		check_semi(); 

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_strcpy.c c2_str_4");
				trace_rec_1();
			}

		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield4[VAR_LGTH];
			
		int pi;
		int pi2;
		int v = 0;
		int I = 0;
		int x1 = 0;
		int x10 = 0;
				
		tfield1a[0] = '\0';
		tfield2a[0] = '\0';

		int str3 = 0;
		int str4 = 0;

		int ret = 0;
		int ret1 = 0;
				
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
				if(ch != ' ')
					{
						tfield1[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		tfield1[pi2] = '\0';

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
				if(ch != ' ')
					{
						tfield2[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		tfield2[pi2] = '\0';

		str3 = 0;
		str4 = 0;
		
		if(lv_ct > 0)				
			{
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(tfield1, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{				
								str3 = 1;
								strcpy(tfield1a, lw_variable[v].lv_cname);
								lw_variable[v].lv_use_ct++;
								x1 = lw_variable[v].lv_lgth;
							}
					}
			}

		if(str3 == 0)
			{
				str4 = 0;
				if(gv_ct > 0)		
					{
						for(v = 0; v < gv_ct; v++)
							{
								str4 = strcmp(tfield1, gw_variable[v].gv_name);
								if(str4 == 0)
									{				
										str3 = 1;
										strcpy(tfield1a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
										x1 = gw_variable[v].gv_lgth;
										gw_variable[v].gv_current_lgth = x1;
									}
							}
					}
			}

		if(str3 == 0)
			{
				printf("c2z_strcpy.c c2_str_4 tfield1 Not Found %s\n",tfield1);
				printf("c2z_strcpy.c c2_str_4 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		str3 = 0;
		str4 = 0;
		x10 = 0;

		if(lv_ct > 0)
			{
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(tfield2, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{				
								str3 = 1;
								strcpy(tfield2a, lw_variable[v].lv_cname);
								lw_variable[v].lv_use_ct++;
							}
					}
			}

		if(str3 == 0)
			{
				str4 = 0;
				if(gv_ct > 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								str4 = strcmp(tfield2, gw_variable[v].gv_name);
								if(str4 == 0)
									{				
										str3 = 1;
										strcpy(tfield2a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
									}
							}
					}
			}

		if(str3 == 0)
			{
				for(I=0; I < fn_ct; I++)
					{
						ret = strcmp(tfield2, w_function[I].fn_name);
						if(ret == 0)
							{
								str3 = 1;
								x10 = 1;
								strcpy(tfield2a, w_function[I].fn_cname);
								strcpy(tfield4, w_function[I].fn_ret_var);
							}
					}
			}

		if(str3 == 0)
			{
				printf("c2z_strcpy.c c2_str_4 tfield2 Not Found = %s\n",tfield2);
				printf("c2z_strcpy.c c2_str_4 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(x10 == 0)
			{
				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_4 #1");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,");
             		 	strcat(a_string, tfield2a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_4 #2");
 						trace_rec_3();
					}

 				strcpy(a_string, "         MVC   0(");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
				strcat(a_string, wk_strg);
				strcat(a_string, ",R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_4 #3");
 						trace_rec_3();
					}
			}

		if(x10 == 1)
			{

			}
			
		convert = 1;		
	}

void c2_str_5()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_strcpy.c c2_str_5");
				trace_rec_1();
			}

		char ch;
		char *p;

		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield4[VAR_LGTH];
		char tfield4a[VAR_LGTH];
		char tfield12[VAR_LGTH];

		char ar_field5[12];
		char ar_field6[12];
		char ar_field7[12];
		char ar_field8[12];
		char ar_field9[12];
		char ar_field10[12];
		char ar_field11[12];

		char ar1_field5[12];
		char ar1_field6[12];
		char ar1_field7[12];
		char ar1_field8[12];
		char ar1_field9[12];
		char ar1_field10[12];
		char ar1_field11[12];

		int I = 0;
		int x1 = 0;
		int x2 = 0;
		int x11 = 0;
		int x90 = 0;
		int x91 = 0;
		int x92 = 0;
		int x94 = 0;
		int s = 0;
		int ret = 0;
		int ret1 = 0;
		int pi;
		int pi2;
		int fd2_type = 0;
		int fd4_type = 0;

		check_semi(); 

		s = strlen(p_string);
		x90 = 0;
		x91 = 0;
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '[')
					{
						x90++;
					}
				if(ch == ']')
					{
						x91++;
					}
			}

		if((x90 == 1) && (x91 == 1))
			{
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
				while(ch != '[')
					{
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ']')
					{
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				ch = p_string[pi];
				while(ch != ' ')
					{
						tfield3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield3[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				ch = p_string[pi];
				while(ch != ';')
					{
						tfield4[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield4[pi2] = '\0';

				for(I=0; I < lv_ct; I++)		
					{
						ret = strcmp(tfield1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x1 = 1;
								strcpy(tfield1a, lw_variable[I].lv_cname);
							}
					}

				if(x1 == 0)				
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x1 = 1;
										strcpy(tfield1a, gw_variable[I].gv_cname);
										strcpy(ar_field5, gw_variable[I].gv_dsect);
										strcpy(ar_field6, gw_variable[I].gv_label);
										strcpy(ar_field7, gw_variable[I].gv_table);
										strcpy(ar_field8, gw_variable[I].gv_aname);
										strcpy(ar_field9, gw_variable[I].gv_sv_reg);
										strcpy(ar_field10, gw_variable[I].gv_wk_reg);
										strcpy(ar_field11, gw_variable[I].gv_wk_strg);
									}
							}
					}

				if(x1 == 0)
					{
						printf("c2z_strcpy.c c2_str_5 E-367 tfield1 Not Found = %s\n",tfield1);
						c2_error();
					}

				x1 = 0;
				for(I=0; I < lv_ct; I++)		
					{
						ret = strcmp(tfield2, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x1 = 1;
								strcpy(tfield2a, lw_variable[I].lv_cname);
							}
					}

				if(x1 == 0)				
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield2, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x1 = 1;
										strcpy(tfield2a, gw_variable[I].gv_cname);
									}
							}
					}

				if(x1 == 0)
					{
						printf("c2z_strcpy.c c2_str_5 E-368 tfield2 Not Found = %s\n",tfield2);
						c2_error();
					}

				x1 = 0;
				for(I=0; I < lv_ct; I++)		
					{
						ret = strcmp(tfield3, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x1 = 1;
								strcpy(tfield3a, lw_variable[I].lv_cname);
							}
					}		

				if(x1 == 0)				
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield3, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x1 = 1;
										strcpy(tfield3a, gw_variable[I].gv_cname);
										strcpy(ar1_field5, gw_variable[I].gv_dsect);
										strcpy(ar1_field6, gw_variable[I].gv_label);
										strcpy(ar1_field7, gw_variable[I].gv_table);
										strcpy(ar1_field8, gw_variable[I].gv_aname);
										strcpy(ar1_field9, gw_variable[I].gv_sv_reg);
										strcpy(ar1_field10, gw_variable[I].gv_wk_reg);
										strcpy(ar1_field11, gw_variable[I].gv_wk_strg);
									}
							}
					}

				if(x1 == 0)
					{
						printf("c2z_strcpy.c c2_str_5 E-369 tfield3 Not Found = %s\n",tfield3);
						c2_error();
					}

				x1 = 0;
				for(I=0; I < lv_ct; I++)		
					{
						ret = strcmp(tfield4, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x1 = 1;
								strcpy(tfield4a, lw_variable[I].lv_cname);
							}
					}

				if(x1 == 0)				
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield4, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x1 = 1;
										strcpy(tfield4a, gw_variable[I].gv_cname);
									}
							}
					}

				if(x1 == 0)
					{
						printf("c2z_strcpy.c c2_str_5 E-370 tfield4 Not Found = %s\n",tfield4);
						c2_error();
					}

				strcpy(tfield12, tfield1);
				strcat(tfield12, "_width");

				x1 = 0;
				for(I=0; I < lv_ct; I++)		
					{
						ret = strcmp(tfield12, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x1 = 1;
							}
					}

				if(x1 == 0)				
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield12, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x1 = 1;
									}
							}
					}

				if(x1 == 0)
					{
						printf("c2z_strcpy.c c2_str_5 E-371 tfield12 Not Found = %s\n",tfield12);
						c2_error();
					}

				strcpy(tfield12, tfield3);
				strcat(tfield12, "_width");

				x1 = 0;
				for(I=0; I < lv_ct; I++)		
					{
						ret = strcmp(tfield12, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x1 = 1;
								x11 = lw_variable[I].lv_lgth;
							}
					}

				if(x1 == 0)				
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield12, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x1 = 1;
										x11 = gw_variable[I].gv_lgth;
									}
							}
					}

				if(x1 == 0)
					{
						printf("c2z_strcpy.c c2_str_5 E-372 tfield12 Not Found = %s\n",tfield12);
						c2_error();
					}

				strcpy(a_string, "         LARL  R6,");
				strcat(a_string, ar_field7);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #2");
						trace_rec_3();
					}
		
				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #4");
						trace_rec_3();
					}

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #5");
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
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #6");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #7");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield2a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield2);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #8");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #9");
						trace_rec_3();
					}

				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "B");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #10");
						trace_rec_3();
					}

				strcpy(a_string, "         LA    R6,");
				strcat(a_string, ar_field6);
				strcat(a_string, "(R0,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #11");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #12");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #13");
						trace_rec_3();
					}

				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #14");
						trace_rec_3();
					}

				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #15");
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
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #16");
						trace_rec_3();
					}

				strcpy(a_string, "*");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #17");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R5,");
				strcat(a_string, ar1_field7);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield3);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #19");
						trace_rec_3();
					}
		
				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #20");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #21");
						trace_rec_3();
					}

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #22");
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
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #23");
						trace_rec_3();
					}
		
				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #24");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield4a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield4);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #25");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #26");
						trace_rec_3();
					}

				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "D");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #27");
						trace_rec_3();
					}

				strcpy(a_string, "         LA    R5,");
				strcat(a_string, ar1_field6);
				strcat(a_string, "(R0,R5)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #28");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #29");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #30");
						trace_rec_3();
					}

				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #31");
						trace_rec_3();
					}

				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "C");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #32");
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
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #33");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   0(");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x11);
				strcat(a_string, wk_strg);
				strcat(a_string, ",R6),0(R5)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 #34");
						trace_rec_3();
					}

				convert = 1;
			}

		if((x90 == 2) && (x91 == 2))
			{
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
				while(ch != '[')
					{
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				pi2 = 0;
				x2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ']')
					{
						if(x2 == 0)
							{
								if((isdigit(ch)) && (x2 == 0))
									{
										fd2_type = 2;
										x2 = 1;
									}

								if((isalpha(ch)) && (x2 == 0))
									{
										fd2_type = 1;
										x2 = 1;
									}
							}
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';
  
				p = strstr(p_string, "\"");
			
				if(p)			
					{
						x92 = 1;
						ch = p_string[pi];
						while(ch != '\"')
							{
								pi++;
								ch = p_string[pi];
							}

						x94 = 0;
						pi2 = 0;
						pi++;
						ch = p_string[pi];
						while(ch != '\"')
							{
								tfield4[pi2] = ch;
								x94++;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						tfield4[pi2] = '\0';
					}

				if(!p)			
					{
						x92 = 2;
					}

				pi++;
				pi++;
				pi2 = 0;
				ch = p_string[pi];
				while(ch != '[')
					{
						if(ch != ' ')
							{
								tfield3[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield3[pi2] = '\0';
  
				pi2 = 0;
				x2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ']')
					{
						if(x2 == 0)
							{
								if((isdigit(ch)) && (x2 == 0))
									{
										fd4_type = 2;
										x2 = 1;
									}

								if((isalpha(ch)) && (x2 == 0))
									{
										fd4_type = 1;
										x2 = 1;
									}
							}
						tfield4[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield4[pi2] = '\0';
 
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(tfield1, gw_variable[I].gv_name);
						if(ret == 0)
							{
								strcpy(tfield1a, gw_variable[I].gv_cname);
								strcpy(ar_field5, gw_variable[I].gv_dsect);
								strcpy(ar_field6, gw_variable[I].gv_label);
								strcpy(ar_field7, gw_variable[I].gv_table);
								strcpy(ar_field8, gw_variable[I].gv_aname);
								strcpy(ar_field9, gw_variable[I].gv_sv_reg);
								strcpy(ar_field10, gw_variable[I].gv_wk_reg);
								strcpy(ar_field11, gw_variable[I].gv_wk_strg);
								x92 = gw_variable[I].gv_lgth;
							}
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #2");
						trace_rec_3();
					}

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #3");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R6,");
				strcat(a_string, ar_field7);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #4");
						trace_rec_3();
					}

				if(fd2_type == 1)
					{
						x1 = 0;
						for(I=0; I < lv_ct; I++)		
							{
								ret = strcmp(tfield2, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x1 = 1;
										strcpy(tfield2a, lw_variable[I].lv_cname);
									}
							}

						if(x1 == 0)				
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(tfield2, gw_variable[I].gv_name);
										if(ret == 0)
											{
												x1 = 1;
												strcpy(tfield2a, gw_variable[I].gv_cname);
											}
									}
							}

						if(x1 == 0)
							{
								printf("c2z_strcpy.c c2_str_5 E-373 tfield2 Not Found = %s\n",tfield2);
								c2_error();
							}

						strcpy(a_string, "L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						check_length();
						strcat(a_string, "DS    0H");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #6");
								trace_rec_3();
							}
					
						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #7");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield2a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield2);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #8");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #9");
								trace_rec_3();
							}

						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcpy(start_while, a_string);
						strcat(a_string, "F");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #10");
								trace_rec_3();
							}
						
						strcpy(a_string, "         LA    R6,");
						strcat(a_string, ar_field6);
						strcat(a_string, "(R0,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #11");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #12");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #13");
								trace_rec_3();
							}

						strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #14");
								trace_rec_3();
							}

						strcpy(a_string, "         JLU   ");
						strcat(a_string, "L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #15");
								trace_rec_3();
							}

						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcpy(start_while, a_string);
						strcat(a_string, "F");
						check_length();
						strcat(a_string, "DS    0H");
						strcpy(wk_remark," if    */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #16");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #17");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370ZERO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #18");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #19");
								trace_rec_3();
							}
						
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield3, gw_variable[I].gv_name);
								if(ret == 0)
									{
										strcpy(tfield3a, gw_variable[I].gv_cname);
										strcpy(ar_field5, gw_variable[I].gv_dsect);
										strcpy(ar_field6, gw_variable[I].gv_label);
										strcpy(ar_field7, gw_variable[I].gv_table);
										strcpy(ar_field8, gw_variable[I].gv_aname);
										strcpy(ar_field9, gw_variable[I].gv_sv_reg);
										strcpy(ar_field10, gw_variable[I].gv_wk_reg);
										strcpy(ar_field11, gw_variable[I].gv_wk_strg);
									}
							}

						strcpy(a_string, "         LARL  R5,");
						strcat(a_string, ar_field7);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield3);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #20");
								trace_rec_3();
							}

						if(fd4_type == 1)
							{
								x1 = 0;
								for(I=0; I < lv_ct; I++)		
									{
										ret = strcmp(tfield4, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												x1 = 1;
												strcpy(tfield4a, lw_variable[I].lv_cname);
											}
									}

								if(x1 == 0)				
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(tfield4, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x1 = 1;
														strcpy(tfield2a, gw_variable[I].gv_cname);
													}
											}
									}

								if(x1 == 0)
									{
										printf("c2z_strcpy.c c2_str_5 E-374 tfield4 Not Found = %s\n",tfield4);
										c2_error();
									}
							}

						strcpy(a_string, "L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "M");
						check_length();
						strcat(a_string, "DS    0H");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #21");
								trace_rec_3();
							}
					
						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #22");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield4a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield4);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #23");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #24");
								trace_rec_3();
							}

						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcpy(start_while, a_string);
						strcat(a_string, "N");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #25");
								trace_rec_3();
							}
						
						strcpy(a_string, "         LA    R5,");
						strcat(a_string, ar_field6);
						strcat(a_string, "(R0,R5)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #26");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #27");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #28");
								trace_rec_3();
							}

						strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #29");
								trace_rec_3();
							}

						strcpy(a_string, "         JLU   ");
						strcat(a_string, "L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "M");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #30");
								trace_rec_3();
							}

						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcpy(start_while, a_string);
						strcat(a_string, "N");
						check_length();
						strcat(a_string, "DS    0H");
						strcpy(wk_remark," if    */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #31");
								trace_rec_3();
							}

						strcpy(a_string, "         MVC   0(");
						snprintf(wk_strg, sizeof(wk_strg), "%d", x92);
						strcat(a_string, wk_strg);
						strcat(a_string, ",R6),0(R5)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #33");
								trace_rec_3();
							}
					}

				if(fd2_type == 2)
					{
						printf("c2z_strcpy.c c2_str_5 E-375 MULTI fd2_type == 1 NOT CODED\n");
						c2_error();
					}

				convert = 1;
			}
	}


void c2_str_6()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_string.c c2_str_6");
        trace_rec_1();
     }

printf("c2_str_6 rct = %d p_string = %s",rct,p_string);

     char ch;
     char *p;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char wk_sv_func[VAR_LGTH];

		int pi;
		int pi2 = 0;
		int I = 0;
		int x1 = 0;
		int ret = 0;
		int ret1 = 0;
		
		int no_parameters = 0;
		
		p = strstr(p_string, "()");
		if(p)
			{
				no_parameters = 1;
			}
		
		if(no_parameters == 1)				
			{
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
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				ch = p_string[pi];
				while(ch != '(')
					{
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				for(I = 0; I < fn_ct; I++)
					{
						ret = strcmp(tfield2, w_function[I].fn_name);
						if(ret == 0)
							{
								strcpy(wk_sv_func, tfield2);
								strcpy(tfield2a, w_function[I].fn_cname);
								strcpy(tfield3, w_function[I].fn_ret_var);
							}
					}

				strcpy(a_string, "         BRASL C370LNK,");
				strcat(a_string, tfield2a);
                            strcpy(wk_remark, " ");
				strcat(wk_remark, tfield2);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_6 #1");
						trace_rec_3();
					}

				x1 = 0;
				for(I=0; I < lv_ct; I++)		
					{
						ret = strcmp(tfield3, lw_variable[I].lv_name);
						ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x1 = 1;
								strcpy(tfield3a, lw_variable[I].lv_cname);
							}
					}

				if(x1 == 0)				
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield3, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x1 = 1;
										strcpy(tfield3a, gw_variable[I].gv_cname);
									}
							}
					}

				if(x1 == 0)
					{
						printf("c2z_strcpy.c c2_str_6 tfield3 Not Found = %s\n",tfield3);
						printf("c2z_strcpy.c c2_str_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				x1 = 0;
				for(I=0; I < lv_ct; I++)		
					{
						ret = strcmp(tfield1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x1 = 1;
								strcpy(tfield1a, lw_variable[I].lv_cname);
							}
					}

				if(x1 == 0)				
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x1 = 1;
										strcpy(tfield1a, gw_variable[I].gv_cname);
									}
							}
					}

				if(x1 == 0)
					{
						printf("c2z_strcpy.c c2_str_6 tfield1 Not Found = %s\n",tfield1);
						printf("c2z_strcpy.c c2_str_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
	
				strcpy(a_string, "         MVC2  ");
				strcat(a_string, tfield1a);
				strcat(a_string, ",");
				strcat(a_string, tfield3a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcpy.c c2_str_6 #2");
						trace_rec_3();
					}

				convert = 1;
			}
	}


void c2_strcpy_pass2(void)
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_strcpy.c c2_strcpy_pass2");
				trace_rec_1();
			}

		char ch;

		int pi;
		int str1 = 0;
		int str2 = 0;
		int str3 = 0;
		int str4 = 0;
		int str12 = 0;
		int str13 = 0;
		int str14 = 0;
	
		int I = 0;
		int s = 0;

		s = strlen(p_string);
		str1 = 0;	/* x */
		str2 = 0;	/* x2 */
		for(I = 0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '\"')
					{
						str1++;
						str2 = I;
					}
			}

		if(str1 != 0)
			{
				if(str1 != 2)
					{
						printf("c2z_strcpy.c c2_strcpy_pass2 UNBALANCED QUOTES\n");
						printf("c2z_strcpy.c c2_strcpy_pass2 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1); 
					}
			}

		s = strlen(p_string);
		pi = 0;
		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}
 
		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			} 
		pi++;
		ch = p_string[pi];

		while(ch != ',')
			{
				pi++;
				ch = p_string[pi];
			}
		
		s = strlen(p_string);
		str1 = 0;	/* comma */
		str2 = 0;	/* [     */
		str3 = 0;	/* ]	  */
		str4 = 0;	/* 1st " */
		
		for(I = 0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == ',')
					{
						str1 = I;
						break;
					}
				if(ch == '[')
					str2 = I;
				if(ch == ']')
					str3 = I;
				if((ch == '"') && (str4 == 0))
					str4 = I;
			}

		for(I = str1; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '[')
					str12 = I;
				if(ch == ']')
					str13 = I;
				if((ch == '"') && (str4 == 0))
					str14 = I;
			}
	
		convert = 0;

		if((str1 < str14) && (convert == 0))								
			{
				c2_pass2_strcpy_2(str1,str14);
				convert = 1;
			}

		if((str2 == 0) && (str3 == 0) && (str12 > 0) && (str13 > 0) && (convert == 0))		/* strcpy(p_string, arrary1{line_ndx])	*/ 
			{
				convert = 1;
			}

		if((str1 > str2) && (str2 > 0) && (str3 > 0) && (str12 == 0) && (str13 == 0) && (convert == 0))		/* strcpy(array1[ln], p_string);		*/ 
			{														/* strcpy(array1[ln], "xxxxxxxxxx"); 	*/
				convert = 1;
			}

		if((str2 > 0) && (str3 > 0) && (str12 > 0) && (str13 > 0) && (convert == 0))			/* strcpy array1[ln], array2[xy]);		*/
			{
				convert = 1;
			}
	}


void c2_pass2_strcpy_2(int str1, int str4)
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_strcpy.c c2_pass2_strcpy_2");
				trace_rec_1();
			}

		int v = 0;
		int ret = 0;
		int ret1 = 0;
		int pi;
		int pi2;
		int x2 = 0;
		int I;

		char ch;
		char *p, *p1, *p2;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
									
		tfield1a[0] = '\0';
		
		int str5 = 0;
		int size = 0;
		int x3 = 0;	
		int s = 0;

		p = strstr(p_string, "[");
		p1 = strstr(p_string, "]");
		p2 = strstr(p_string, ".");

		if((str1 < str4) && (!p1) && (!p2) && (!p2))		
			{
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
						if(ch != ' ')
							{
								tfield1[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				str5 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield1, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										strcpy(tfield1a, lw_variable[v].lv_cname);
										lw_variable[v].lv_use_ct++;
										str5 = 1;
									}		
							}
					}	

				if(str5 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(tfield1, gw_variable[v].gv_name);
										if(ret == 0)
											{
												strcpy(tfield1a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
												str5 = 1;
											}		
									}
							}
					}

				if(str5 == 0)
					{
						printf("c2z_strcpy.c c2_pass2_strcpy_2 tfield1 Not Found = %s\n",tfield1);
						printf("c2z_strcpy.c c2_pass2_strcpy_2 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}	

				pi++;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				if(ch == '"')
					{	
						pi2 = 0;
						pi++;
						ch = p_string[pi];
										
						while(ch != '"')
							{
								tfield2[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
								if(ch == '\n')
									break;
								if(ch == '\t')
									break;
							}
					}
				tfield2[pi2] = '\0';

				x3 = strlen(tfield2);

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield1a, c_wkname);
				
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
				strcpy(w_charlit[char_ct].clit_cname, tfield1a);	
      				strcpy(w_charlit[char_ct].clit_value, tfield2); 
				w_charlit[char_ct].clit_lgth = x3; 
				w_charlit[char_ct].clit_type = 3;	             
				char_ct++;

				x2 = 0;
 				if(lv_ct > 0)
					{
						for(I = 0; I < lv_ct; I++)
							{
								ret = strcmp(tfield1, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x2 = 1;
										lw_variable[I].lv_current_lgth = x3;
									}
							}
					}

				if(x2 == 0)
					{
 						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(tfield1, gw_variable[I].gv_name);
										if(ret == 0)
											{
												x2 = 1;
												gw_variable[I].gv_current_lgth = x3;
											}
									}
							}
					}

				if(x2 == 0)
					{
						printf("c2z_strcpy.c c2_pass2_strcpy_2 tfield1 Not Found = %s\n",tfield1);
						printf("c2z_strcpy.c c2_pass2_strcpy_2 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
			}

		if((p) && (p1) && (p2))
			{
				printf("c2z_strcpy.c c2_pass2_strcpy_2 NOT CODED \n");
				printf("c2z_strcpy.c c2_pass2_strcpy_2 rct = %d p_string = %s",rct,p_string);
			/*	c2_debug();
				exit(1); */
			}	

		convert = 1;
	}

