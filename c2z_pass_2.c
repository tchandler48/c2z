/* ***************************************************
*  c2z : c2z_pass_2.c :                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

void scan_func_name_3()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c func_name_3");
				trace_rec_1();
			}
	
		int pi;
		int pi2;
		int x4 = 0;
		int ret = 0;

		char ch;
		char *p, *p1, *p2, *p3, *p4, *p5;
		char field1[VAR_LGTH];
		
		field1[0] = '\0';

		p = strstr(p_string, "void");
		p1 = strstr(p_string, ";");
		p2 = strchr(p_string, '(');
		p3 = strchr(p_string, ')');
		p4 = strstr(p_string, "int");
		p5 = strstr(p_string, "print");

		if((p) && (!p1) && (!p5) && (p3))
			{
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

				for(x4 = 0; x4 < fn_ct; x4++)
					{
						ret = strcmp(field1, w_function[x4].fn_name);
						if(ret == 0)
							{
								w_function[x4].fn_start = rct;
							}
					}
									
				convert = 1;
			}

		p = strstr(p_string, "void");
		p1 = strstr(p_string, ";");
		p2 = strchr(p_string, '(');
		p3 = strchr(p_string, ')');
		p4 = strstr(p_string, "int");
		p5 = strstr(p_string, "print");

		if((p2) && (p3) && (p4) && (!p1) && (convert == 0) && (!p5))	/* INT procedure INT get_upper(int, int);		*/
			{
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

				for(x4 = 0; x4 < fn_ct; x4++)
					{
						ret = strcmp(field1, w_function[x4].fn_name);
						if(ret == 0)
							{
								w_function[x4].fn_start = rct;
							}
					}

				convert = 1;
			}

	}


void scan_func_name_2()			/* VOID A_BORT(INT CODE, INT LINE_NDX	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c scan _func_name_2");
				trace_rec_1();
			}

		int I = 0;
		int comma_ct = 0;
		int size = 0;
		int x3 = 0;
		int x4 = 0;
		int pi;
		int pi2;
		int ret = 0;
		int ret1 = 0;

		char ch;
		char *p, *p1, *p2;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
              char tfield2[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield5[VAR_LGTH];
		
		char tfield3a[VAR_LGTH];

		p = strchr(p_string, ',');
		if(p)
			{
				comma_ct = 1;
			}

		pi = 0;
		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		while(ch != ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != '(')
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
		while(ch != ' ')
			{
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		
		p1 = strstr(tfield2,"int");
		if(p1)			/* next variable is INT	*/
			{
				pi++;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}
				pi2 = 0;
				ch = p_string[pi];
				if(comma_ct != 0)
					{
						while(ch != ',')
							{
								tfield3[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
					}

				if(comma_ct == 0)
					{
						while(ch != ')')
							{
								tfield3[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
					}
				tfield3[pi2] = '\0';

				if(comma_ct != 0)
					{
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
								pi2++;
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
						ch = p_string[pi];
						while(ch != ')')
							{
								tfield5[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						tfield5[pi2] = '\0';
					}

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				x4 = strlen(c_wkname);
				c_wkname[x4] = '\0';
				strcpy(tfield3a, c_wkname);
				
				x3 = 0;
				if(lv_ct > 0)
					{
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(tfield3, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										strcpy(tfield3a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
										x3 = 1;
									}
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield3, gw_variable[I].gv_name);
								if(ret == 0)
									{
										strcpy(tfield3a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;
										x3 = 1;
									}
							}
					}

				if((global_st == 0) && (x3 == 0))
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
						strcpy(gw_variable[gv_ct].gv_cname, tfield3a);	
      						strcpy(gw_variable[gv_ct].gv_name, tfield3);  	
						strcpy(gw_variable[gv_ct].gv_type, "I");
						gw_variable[gv_ct].gv_lgth = 0;
						gw_variable[gv_ct].gv_current_lgth = 0;
						strcpy(gw_variable[gv_ct].gv_value, "0");
						gw_variable[gv_ct].gv_init = 0;
						strcpy(gw_variable[gv_ct].gv_literal,null_field);
						gw_variable[gv_ct].gv_use_ct = 0;
						strcpy(gw_variable[gv_ct].gv_dsect, null_field);
						gw_variable[gv_ct].gv_row = 0;
						gw_variable[gv_ct].gv_column = 0;
						strcpy(gw_variable[gv_ct].gv_dsect, null_field);
						strcpy(gw_variable[gv_ct].gv_label, null_field);
						strcpy(gw_variable[gv_ct].gv_aname, null_field);
						strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
						strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
						strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
						gw_variable[gv_ct].gv_dec = 0;
						gv_ct++;
						x3 = 1;
					}
					
				if((global_st == 1) && (x3 == 0))		
					{
						x3 = 0;
						if(lv_ct > 0)
							{
								for(I=0; I < lv_ct; I++)
									{
										ret = strcmp(tfield3, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												strcpy(tfield3a, lw_variable[I].lv_cname);
												lw_variable[I].lv_use_ct++;
												x3 = 1;
											}
									}
							}

						if(x3 == 0)
							{
								if(lv_ct == 0)
									{
										size = 1;
										lw_variable = malloc(size * sizeof(struct var));
									}
								else
									{
										size = lv_ct + 1;
										lw_variable = realloc(lw_variable, size * sizeof(struct var));
									}

								lw_variable[lv_ct].lv_rct = rct;
								strcpy(lw_variable[lv_ct].lv_cname, tfield3a);	
      								strcpy(lw_variable[lv_ct].lv_name, tfield3);  	
								strcpy(lw_variable[lv_ct].lv_type, "I");
								lw_variable[lv_ct].lv_lgth = 0;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}
				
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				x4 = strlen(c_wkname);
				c_wkname[x4] = '\0';
				strcpy(tfield1a, c_wkname);
					
				x3 = 0;
				if(lv_ct > 0)
					{
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(tfield1, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										strcpy(tfield1a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
										x3 = 1;
									}
							}
					}

				if(x3 == 00)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										strcpy(tfield1a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;
										x3 = 1;
									}
							}
					}

				if((global_st == 0) && (x3 == 0))
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
						strcpy(gw_variable[gv_ct].gv_cname, tfield1a);	
      						strcpy(gw_variable[gv_ct].gv_name, tfield1);  	
						strcpy(gw_variable[gv_ct].gv_type, "I");
						gw_variable[gv_ct].gv_lgth = 0;
						gw_variable[gv_ct].gv_current_lgth = 0;
						strcpy(gw_variable[gv_ct].gv_value, "0");
						gw_variable[gv_ct].gv_init = 0;
						strcpy(gw_variable[gv_ct].gv_literal,null_field);
						gw_variable[gv_ct].gv_use_ct = 0;
						strcpy(gw_variable[gv_ct].gv_dsect, null_field);
						gw_variable[gv_ct].gv_row = 0;
						gw_variable[gv_ct].gv_column = 0;
						strcpy(gw_variable[gv_ct].gv_dsect, null_field);
						strcpy(gw_variable[gv_ct].gv_label, null_field);
						strcpy(gw_variable[gv_ct].gv_aname, null_field);
						strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
						strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
						strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
						gw_variable[gv_ct].gv_dec = 0;
						gv_ct++;
						x3 = 1;
					}
				
				if((global_st == 1) && (x3 == 0))		
					{
						x3 = 0;
						if(lv_ct > 0)
							{
								for(I=0; I < lv_ct; I++)
									{
										ret = strcmp(tfield1, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												strcpy(tfield1a, lw_variable[I].lv_cname);
												lw_variable[I].lv_use_ct++;
												x3 = 1;
											}
									}
							}

						if(x3 == 0)
							{
								if(lv_ct == 0)
									{
										size = 1;
										lw_variable = malloc(size * sizeof(struct var));
									}
								else
									{
										size = lv_ct + 1;
										lw_variable = realloc(lw_variable, size * sizeof(struct var));
									}

								lw_variable[lv_ct].lv_rct = rct;
								strcpy(lw_variable[lv_ct].lv_cname, tfield1a);	
      								strcpy(lw_variable[lv_ct].lv_name, tfield1);  	
								strcpy(lw_variable[lv_ct].lv_type, "I");
								lw_variable[lv_ct].lv_lgth = 0;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				x3 = 0;
				if(fn_ct > 0)
					{
						for(I = 0; I < fn_ct; I++)
							{
								ret = strcmp(tfield1, w_function[I].fn_name);
								if(ret == 0)
									{
										x3 = 1;
										if(comma_ct != 0)
											{
												strcpy(w_function[I].fn_fd1,tfield3);
												strcpy(w_function[I].fn_fd2,tfield5);
												w_function[I].fn_start = rct;

											}
										if(comma_ct == 0)
											{
												strcpy(w_function[I].fn_fd1,tfield3);
												w_function[I].fn_start = rct;

											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_pass_2.c c2_int_3 Function Error\n");
						printf("c2z_pass_2.c rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
			}	

		if(!p1)			
			{
				p2 = strstr(p_string, "()");
				if(p2)			
					{
						pi = 0;
						ch = p_string[pi];
						while(ch == ' ')
							{
								pi++;
								ch = p_string[pi];
							}

						while(ch != ' ')
							{
								pi++;
								ch = p_string[pi];
							}

						pi2 = 0;
						pi++;
						ch = p_string[pi];
						while(ch != '(')
							{
								tfield1[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						tfield1[pi2] = '\0';
					}
			}	
	
		convert = 1;
	}


/* *************************************************** 
*  RETURN capture return variable                    *
* ************************************************** */
void c2_ret_2()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_ret_2");
				trace_rec_1();
			}

		int I = 0;
		int ret = 0;
		int pi;
		int pi2;

		char ch;
		char *p1;
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];

		field2[0] = '\0';

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
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field1[pi2] = '\0';
		
		p1 = strstr(field1,";");
		if(!p1)
			{
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ';')
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
				for(I = 0;  I < fn_ct; I++)
					{
						ret = strcmp(sv_func, w_function[I].fn_name);
						if(ret == 0)
							{
								strcpy(field1, w_function[I].fn_sv_reg_1);
								strcpy(w_function[I].fn_ret_var, field2);
							}
					}
			}

	}

void c2_math_literal()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_math_literal");
				trace_rec_1();
			}

		check_semi(); 

		char ch;
		char *p, *p2, *p8, *p9;

		int pi;
		int x = 0;
		int x1 = 0;
		int x2 = 0;
		int x20 = 0;
		int op_1 = 0;
		int L1 = 0;
		int R1 = 0;
		int L2 = 0;
		int R2 = 0;
		int I = 0;
		int s = 0;
		int x90 = 0;
		int math_plus = 0;
		int math_minus = 0;
		int math_mult	= 0;
		int math_div 	= 0;
		int math = 0;
		int math1 = 0;

		p = strstr (p_string, "=");
		if(p)
			{
				p2 = strstr(p_string, "-1");
				if(p2)
					math1 = 1;

				x20 = 0;
				p2 = strstr(p_string, "[(");
				if(p2)
					{
						x20 = 1;
					}


				math = 0;

				s = strlen(p_string);
				for(I=0; I < s; I++)
					{
						ch = p_string[I];
						if(ch == '+')
							{
								math_plus++;
								math = 1;
							}

						if((ch == '-') && (math1 == 0))
							{
								math_minus++;
								math = 1;
							}

						if(ch == '*')
							{
								math_mult++;
								math = 1;
							}

						if(ch == '/')
							{
								math_div++;
								math = 1;
							}

						if((math == 1) && (x20 == 0))
							{
								c2_math_literal_99(); 
								return;
							}
					}
			}

		op_1 = 1;
		
		p8 = strchr(p_string, '(');
		p9 = strchr(p_string, ')');
			
		x = 0;
		x2 = 0;
		L1 = 0;
		R1 = 0;
		L2 = 0;
		R2 = 0;
		I = 0;

		s = strlen(p_string);
		pi = 0;
		ch = p_string[pi];
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if((ch != '=') && (x2 != 1) && (x != 1))
					{
						if(ch == '[')
							{
								L1++;
								x2 = 0;
							}
					}

				if(ch == '=')
					{
						x = 1;
						x1 = I;
						break;
					}
								
				if((x == 0) && (ch != ';'))
					{
						if(ch == '[')
							{
								R1++;
							}
					}
			}

		x2 = 0;
		for(I=x1; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '[')
					{
						L2++;
					}
				if(ch == ']')
					{
						R2++;
					}
			}

		x90 = 0;
		p = strstr(p_string, "]++;");
		if(p)
			{
				x90 = 1;
			}

		p = strstr(p_string, "]--;");
		if(p)
			{
				x90 = 1;
			}

		if(x90 == 1)
			{
				c2_math_literal_8();
				convert = 1;
				return;
			}

		if((op_1 == 1) && (L1 == 0) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9))			
			{
				c2_math_literal_1(); 
				convert = 1;
				return;
			}

		if((op_1 == 1) && (L1 == 0) && (R1 == 0) && (L2 == 1) && (R2 == 1) && (!p8) && (!p9))		
			{
				c2_math_literal_6();
				return;
			}

		if((op_1 == 1) && (L1 == 1) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9))		
			{
				/* printf("c2_math_literal #3\n");
				printf("c2_math_literal_3 rct = %d p_string = %s",rct,p_string); */
				return;
			} 

		if((op_1 == 1) && (L1 > 1) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9))		
			{
				/* printf("c2_math_literal #4\n");
				printf("c2_math_literal_4 rct = %d p_string = %s",rct,p_string); */
				return;
			} 

		if((op_1 == 1) && (L1 == 1) && (R1 == 1) && (L2 == 0) && (R2 == 0) && (p8) && (p9) && (x20 == 1))		
			{
				c2_pass2_math_51(); 
				return;
			} 

		if((op_1 == 1) && (L1 == 1) &&(L2 == 0) && (R2 == 0) && (p8) && (p9))					
			{
				/* printf("c2_math_literal #5\n");
				printf("c2_math_literal_5 rct = %d p_string = %s",rct,p_string); */
				return;
			}

		if((op_1 == 1) && (p8) && (p9) && (L1 == 0) && (R1 == 0) && (math == 0))
			{
				/* printf("c2_math_literal #6\n");
				printf("c2_math_literal_6 rct = %d p_string = %s",rct,p_string); */
				return;
			}

		if((L1 > 0) && (R1 > 0) && (L2 > 0) && (R2 > 0))								
			{
				c2_math_literal_7();
				convert = 1;
				return;
			}
		
 	}		

void c2_math_literal_1()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_math_literal_1");
				trace_rec_1();
			}

		check_semi();
 
		char ch;
		char *p1;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3b[VAR_LGTH];
		char tfield21[VAR_LGTH];

		int fd2_type = 0;
		int pi;
		int pi2;
		int x2 = 0;
		int x3 = 0;
		int x4 = 0;
		int x5 = 0;
		int x70 = 0;
		int x71 = 0;
		int x98 = 0;
		int x99 = 0;
		int I = 0;
		int s = 0;
		int s1 = 0;
		int rct1 = 0;
		int ret = 0;
		int size = 0;
		int fd1_id = 0;
		
		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t') || (ch == '{'))
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		x2 = 0;
		x3 = 0;
		while((ch != ' ') && (x3 == 0)) 
			{
				if(ch == '=')
					{
						x3 = 1;
					}
				else
					{
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
			} 
		tfield1[pi2] = '\0';

		x2 = 0;
		x3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(tfield1, lw_variable[I].lv_name);
				x2 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0)  && (x2 == 0)) 
					{
						x3 = 1;		
						strcpy(tfield1a, lw_variable[I].lv_cname);
						fd1_id = lw_variable[I].lv_id;
						break;	
					}
			}

		if(x3 == 0)
			{
				x3 = 0;
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(tfield1, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x3 = 1;		
								strcpy(tfield1a, gw_variable[I].gv_cname);
								fd1_id = gw_variable[I].gv_id;
								break;	
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_pass_2.c c2_math_literal_1 E-154 tfield1 Not Found = %s\n",tfield1);
				c2_error();
			}

		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			} 

		while(ch != '=')
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
		x5 = 0;
		x4 = 0;
		x2 = 0;
		x3 = 0; 
		s = strlen(p_string);
		while((ch != '[') && (pi < s) && (ch != ';'))
			{
				if((isdigit(ch)) && (x3 == 0))
					{
						fd2_type = 2;
						x3 = 1;
					}

				if((isalpha(ch)) && (x3 == 0))
					{
						fd2_type = 1;
						x3 = 1;
					}

				if(ch == '\'')
					{
						x4 = 1;
						x4++;
					}

				if(x4 > 0)
					{
						if(ch == ' ')
							{
								x5++;
							}
					}
				tfield2[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			} 
		tfield2[pi2] = '\0';

		s = strlen(tfield2);

		if((fd2_type == 2) && (fd1_id == 1))
			{
				if(x4 == 0) 		/* if field2 is A literal	*/
					{
						s = strlen(tfield2);
						x99 = 0;
						x98 = 0;
						p1 = strstr(tfield2,"-");
						if(p1)
							{
								x99 = 1;
							}

						p1 = strstr(tfield2,".");
						if(p1)
							{
								x98 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, tfield2);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												tfield2[pi2] = ch;
												pi2++;
											}
									}
								tfield2[pi2] = '\0';
							}

						if(x98 == 1)
							{
								strcpy(tfield3b, tfield2);
								x70 = 0;
								x71 = 0;
								pi2 = 0;
								tfield2[pi2] = '0';
								pi2++;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(x70 == 1)
											{
												x71++;
											}
										if(ch != '.')
											{
												tfield2[pi2] = ch;
												pi2++;
											}
										if(ch == '.')
											{
												x70 = 1;
											}
									}
								tfield2[pi2] = '\0';
								if(x71 > 0)
									x71--;
							}

						if(x99 == 1)
							{
								strcpy(tfield2a, "-");
								strcat(tfield2a, tfield2);
							}
						else
							{
								strcpy(tfield2a, tfield2);
							}
						
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield1a, c_wkname);

						rct1 = rct;
						strcpy(tfield21,tfield1a);
						for(I=0; I < lit_ct; I++)
							{
								ret = strcmp(w_literal[I].lit_value, tfield2a);
								if(ret == 0)
									{
										rct1 = w_literal[I].lit_rct;
										break;
									}
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
						strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, tfield1a);	
      						strcpy(w_literal[lit_ct].lit_value, tfield2a);
						strcpy(w_literal[lit_ct].lit_use_cname, tfield21);  
						w_literal[lit_ct].lit_uct = 1;	
						w_literal[lit_ct].lit_dec = x71; 
						w_literal[lit_ct].lit_type = 1;                
						lit_ct++;
						convert = 1;
					}
			}

		if((fd2_type == 2) && (fd1_id == 2))
			{
				s = strlen(tfield2);
				x99 = 0;
				x98 = 0;
				p1 = strstr(tfield2,"-");
				if(p1)
					{
						x99 = 1;
					}

				p1 = strstr(tfield2,".");
				if(p1)
					{
						x98 = 1;
					}

				s1 = s + 1;
				x70 = 0;
				x71 = 0;
				pi2 = 0;
				if(x98 == 1)
					{
						strcpy(tfield3b, tfield2);
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(x70 == 1)
									{
										x71++;
									}
								tfield2[pi2] = ch;
								pi2++;
								if(ch == '.')
									{
										x70 = 1;
									}
								tfield2[pi2] = '\0';
							}
						if(x71 > 0)
							x71--; 
					}
				
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield1a, c_wkname);

				rct1 = rct;
				strcpy(tfield21,tfield1a);
				
				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
				strcpy(w_literal[lit_ct].lit_name, null_field);
				strcpy(w_literal[lit_ct].lit_cname, tfield1a);	
      				strcpy(w_literal[lit_ct].lit_value, tfield2);
				strcpy(w_literal[lit_ct].lit_use_cname, tfield21);  
				w_literal[lit_ct].lit_uct = 1;	
				w_literal[lit_ct].lit_dec = x71;   
				w_literal[lit_ct].lit_type = 2;          
				lit_ct++;
			}

		convert = 1;
	}

void c2_pass2_math_51()		/* [] left of =   token[pi] = ch  or token[(pi+1)] = ch;   	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_51");
				trace_rec_1();
			}

		char *p, *p1;
		char ch; 
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field5[VAR_LGTH];
		char field5a[VAR_LGTH];
		
		char tfield3b[VAR_LGTH];
		char tfield21[VAR_LGTH];

		int pi;
		int pi2;
		int x2 = 0;
		int x3 = 0;
		int x99 = 0;
		int m5_3 = 0;
		int m5_6 = 0;
		int m5fd2_type = 0;
		int I = 0;
		int s = 0;
		int s1 = 0;
		int size = 0;
		int rct1 = 0;
		int ret = 0;
		int ret1 = 0;

		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t') || (ch == '{'))
			{
				pi++;
				ch = p_string[pi];
			}
						
		pi2 = 0;
		while(ch != '[')
			{
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			} 
		field1[pi2] = '\0';

		m5_3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(field1, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						m5_3 = 1;		
						strcpy(field1a, lw_variable[I].lv_cname);	
					}
			}

		if(m5_3 == 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						m5_6 = strcmp(field1,gw_variable[I].gv_name);

						if(m5_6 == 0)
							{
								m5_3 = 1;		
								strcpy(field1a, gw_variable[I].gv_cname);	
							}
					}
			}

		if(m5_3 == 0)
			{
				printf("c2z_pass_2.c c2_math_51 E-232 field1 Not Found = %s\n",field1);
				c2_error();
			}

		pi++;
		pi++;
		ch = p_string[pi];
		pi2 = 0;
		x2 = 0;
		while(isalnum(ch))
			{
				if(x2 == 0)
					{
						if (isalpha(ch))	
							{
    								m5fd2_type = 2;
								x2 = 1;
							} 
						if (isdigit(ch)) 	
							{
    								m5fd2_type = 1;
								x2 = 1;
							}
					}
				field2[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field2[pi2] = '\0';

		if(m5fd2_type == 2)
			{
				m5_3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field2, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								m5_3 = 1;		
								strcpy(field2a, lw_variable[I].lv_cname);	
							}
					}

				if(m5_3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								m5_6 = strcmp(field2, gw_variable[I].gv_name);
								if(m5_6 == 0)
									{
										m5_3 = 1;		
										strcpy(field2a, gw_variable[I].gv_cname);		
									}
							}
					}

				if(m5_3 == 0)
					{
						printf("c2z_pass_2.c c2_math_51 E-233 field12 Not Found = %s\n",field2);
						c2_error();
					}
			}

		while(!isalnum(ch))
			{
				pi++;
				ch = p_string[pi];
			}
		
		pi2 = 0;
		while(isdigit(ch))
			{
				field5[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field5[pi2] = '\0';

		while(ch != '=')
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
		s = strlen(p_string);
		while((pi < s) && (ch != ';'))
			{
				field3[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			} 
		field3[pi2] = '\0';

		x3 = 0;
		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '[')
					x3++;
				if(ch == ']')
					x3++;
			}

		p = strstr(field3, "'\0'");
		if((p) && (x3 == 2))		
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_math_5 field3");
						trace_rec_1();
					}

				m5_3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field1,lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								m5_3 = 1;		
							}
					}

				if(m5_3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								m5_6 = strcmp(field1, gw_variable[I].gv_name);
								if(m5_6 == 0)
									{
										m5_3 = 1;		
									}
							}
					}

				if(m5_3 == 0)
					{		
						printf("c2z_pass_2.c c2_math_51 E-231 field1 Not Found = %s\n",field1);
						c2_error();
					}

			}

		s = strlen(field5);
		x99 = 0;
		p1 = strstr(field5,"-");
		if(p1)
			{
				x99 = 1;
			}

		s1 = s + 1;
		if(x99 == 1)
			{
				strcpy(tfield3b, field5);
				pi2 = 0;
				for(I=0; I < s1; I++)
					{
						ch = tfield3b[I];
						if(ch != '-')
							{
								field5[pi2] = ch;
								pi2++;
							}
					}
				field5[pi2] = '\0';
			}

		if(s == 1)
			{
				strcpy(field5a,"000000");
				strcat(field5a, field5);
			}

		if(s == 2)
			{
				if(x99 == 0)
					{	
						strcpy(field5a,"00000");
						strcat(field5a, field5);
					}
				else
					{
						strcpy(field5a,"-00000");
						strcat(field5a, field5);
					}
			}

		if(s == 3)
			{
				if(x99 == 0)
					{
						strcpy(field5a,"0000");
						strcat(field5a, field5);
					}
				else
					{
						strcpy(field5a,"-0000");
						strcat(field5a, field5);
					}
			}

		if(s == 4)
			{
				if(x99 == 0)
					{
						strcpy(field5a,"000");
						strcat(field5a, field5);
					}
				else
					{
						strcpy(field5a,"-000");
						strcat(field5a, field5);					}
			}

		if(s == 5)
			{
				if(x99 == 0)
					{
						strcpy(field5a,"00");
						strcat(field5a, field5);
					}
				else
					{
						strcpy(field5a,"-00");
						strcat(field5a, field5);
					}
			}

		if(s == 6)
			{
				if(x99 == 0)
					{
						strcpy(field5a,"0");
						strcat(field5a, field5);
					}
				else
					{
						strcpy(field5a,"-0");
						strcat(field5a, field5);
					}
			}

		if(s == 7)
			{
				if(x99 == 0)
					{
						strcpy(field5a,field5);
					}
				else
					{
						printf("c2z_pass_2.c c2_pass2_math_51 E-234 Negative Number Error\n");
						c2_error();
					}
			}

		if(s > 7)
			{
				printf("c2z_pass_2.c c2_pass2_math_51 E-236 Length ERROR\n");		
				c2_error();
			}

		c_name++;
		snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
		strcpy(c_wkname, "C37F");
		strcat(c_wkname, wk_strg);
		s1 = strlen(c_wkname);
		c_wkname[s1] = '\0';
		strcpy(field2, c_wkname);

		rct1 = rct;
		strcpy(tfield21, field2);
		for(I=0; I < lit_ct; I++)
			{
				ret = strcmp(w_literal[I].lit_value, field5a);
				if(ret == 0)
					{
								rct1 = w_literal[I].lit_rct;
								strcpy(tfield21, w_literal[I].lit_cname);
								break;
					}
			}

		if(lit_ct == 0)
			{
				size = 1;
				w_literal = malloc(size * sizeof(struct literal));
			}
		else
			{
				size = lit_ct + 1;
				w_literal = realloc(w_literal, size * sizeof(struct literal));
			}

		w_literal[lit_ct].lit_rct = rct;
		w_literal[lit_ct].lit_use_rct = rct1;
		strcpy(w_literal[lit_ct].lit_name, null_field);
		strcpy(w_literal[lit_ct].lit_cname, field2);	
      		strcpy(w_literal[lit_ct].lit_value, field5a); 
		strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 
		w_literal[lit_ct].lit_uct = 2;
		w_literal[lit_ct].lit_dec = 0;
		w_literal[lit_ct].lit_type = 1;	             
		lit_ct++;
	}

void c2_math_literal_99()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_math_literal_99");
				trace_rec_1();
			}

		check_semi(); 

		int s = 0;
		int s1 = 0;
		int s2 = 0;
		int pi2 = 0;
		int x2 = 0;
		int x4 = 0;
		int x70 = 0;
		int x71 = 0;
		int x80 = 0;
		int x98 = 0;
		int x99 = 0;
		int rct1 = 0;
		int I = 0;
		int pi;
		int size = 0;
		int fd3_type = 0;
		int fd5_type = 0;
		int fd7_type = 0;
 		int fd9_type = 0;
		int fd11_type = 0;
		int start_parm = 0;
		int start_parm_3 = 0;
												
		char sv_result[VAR_LGTH];
		char ch, *p1;	
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field5a[VAR_LGTH];
		char field7[VAR_LGTH];
		char field7a[VAR_LGTH];
		char field9[VAR_LGTH];
		char field9a[VAR_LGTH];
		char field11[VAR_LGTH];
		char field11a[VAR_LGTH];
		char tfield3b[VAR_LGTH];
		char tfield21[VAR_LGTH];

		s2 = strlen(p_string);
		s2--;
		s2--;

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
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field1[pi2] = '\0';

		strcpy(sv_result, field1);

		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		while(ch != ' ')
			{
				field2[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field2[pi2] = '\0';

		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		x2 = 0;
		pi2 = 0;
		while(ch != ' ')
			{
				if(x2 == 0)
					{
						if (isalpha(ch))	
							{
    								fd3_type = 2;
								x2 = 1;
							} 
						if (isdigit(ch)) 	
							{
    								fd3_type = 1;
								x2 = 1;
							}
					}
				if(ch == '(')
					{
						start_parm = 1;
						break;
					}
				else
					{
						field3[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		field3[pi2] = '\0';

		if(start_parm_3 == 1)
			{
				x2 = 0;
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						
						if(x2 == 0)
							{
								if (isalpha(ch))	
									{
    										fd3_type = 2;
										x2 = 1;
									} 

								if (isdigit(ch)) 	
									{
    										fd3_type = 1;
										x2 = 1;
									}
							}

						if(ch == '-')
							{
								break;
							}

						if(ch == '+')
							{
								break;
							}

						if(ch == '*')
							{
								break;
							}

						if(ch == '/')
							{
								break;
							}

						if(ch != ';')
							{
								field3[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
			}
		field3[pi2] = '\0';

		if(fd3_type == 1)
			{
				s = strlen(field3);
				x99 = 0;
				p1 = strstr(field3,"-");
				if(p1)
					{
						x99 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, field3);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										field3[pi2] = ch;
										pi2++;
									}
							}
						field3[pi2] = '\0';
					}

				if(x99 == 0)
					{
						strcpy(field3a, field3);
					}
				else
					{
						strcpy(field3a,"-");
						strcat(field3a, field3);
					}

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s1 = strlen(c_wkname);
				c_wkname[s1] = '\0';
				strcpy(field2, c_wkname);
				
				rct1 = rct;
				strcpy(tfield21, field2);
				
				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
				strcpy(w_literal[lit_ct].lit_name, null_field);
				strcpy(w_literal[lit_ct].lit_cname, field2);	
      				strcpy(w_literal[lit_ct].lit_value, field3a); 
				strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 
				w_literal[lit_ct].lit_uct = 1;	
				w_literal[lit_ct].lit_dec = 0; 
				w_literal[lit_ct].lit_type = 1;	      	            
				lit_ct++;
			}

		ch = p_string[pi];
		while(ch == ' ') 
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

		x80 = 0;
		x4 = 0;
		x2 = 0;
		pi2 = 0;
		s2++;
		while(pi < s2)
			{
				if(ch == ';')
					{
						x80 = 1;
						break;
					}

				if(x2 == 0)
					{
						if (isalpha(ch))	
							{
    								fd5_type = 2;
								x2 = 1;
							} 

						if (isdigit(ch)) 	
							{
    								fd5_type = 1;
								x2 = 1;
							}

						if((ch == '(') && (x2 == 0))
							{
								start_parm = 1;
							}
					}
				
				if((ch == ')') && (start_parm == 1))
					{
						ch = p_string[pi+1];
						if(ch == ';')
							{
								pi = s;
								break;
							}
					}

				if(ch != ' ') 
					{
						field5[pi2] = ch;
						pi2++;
					}
				else
					{
						break;
					}
				pi++;
				ch = p_string[pi];
				x4 = 1;
			}
		field5[pi2] = '\0';
		field5a[0] = '\0';
		
		if(start_parm == 1)
			{
				x4 = 0;
				pi2 = 0;
				ch = field5[x4];
				while(ch != '\0')
					{
						if(ch != '(')
							{
								field5a[pi2] = ch;
								pi2++;
							}
						x4++;
						ch = field5[x4];
					}
				field5a[pi2] = '\0';
				strcpy(field5,field5a);
			}

		if(fd5_type == 1)
			{
				s = strlen(field5);
				x99 = 0;
				p1 = strstr(field5,"-");
				if(p1)
					{
						x99 = 1;
					}

				p1 = strstr(field5,".");
				if(p1)
					{
						x98 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, field5);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										field5[pi2] = ch;
										pi2++;
									}
							}
						field5[pi2] = '\0';
					}

				if(x98 == 1)
					{
						strcpy(tfield3b, field5);
						x70 = 0;
						x71 = 0;
						pi2 = 0;
						field5[pi2] = '0';
						pi2++;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(x70 == 1)
									{
										x71++;
									}
								if(ch != '.')
									{
										field5[pi2] = ch;
										pi2++;
									}
								if(ch == '.')
									{
										x70 = 1;
									}
							}
						field5[pi2] = '\0';
						if(x71 > 0)
							x71--;
					}


				if(x99 == 0)
					{
						strcpy(field5a, field5);
					}
				else
					{
						strcpy(field5a,"-");
						strcat(field5a, field5);
					}
	
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s1 = strlen(c_wkname);
				c_wkname[s1] = '\0';
				strcpy(field2, c_wkname);

				rct1 = rct;
				strcpy(tfield21,field2);
								
				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
				strcpy(w_literal[lit_ct].lit_name, null_field);
                            strcpy(w_literal[lit_ct].lit_cname, field2);	
      				strcpy(w_literal[lit_ct].lit_value, field5a); 
				strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 	
				w_literal[lit_ct].lit_uct = 2;  
				w_literal[lit_ct].lit_dec = x71;   
				w_literal[lit_ct].lit_type = 1;	              
				lit_ct++;
			}

		if(x80 == 1)
			return;

		pi++;
		ch = p_string[pi];
		while(ch == ' ')
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

		x4 = 0;
		x2 = 0;
		pi2 = 0;
		while((pi < s2) && (ch != ' '))
			{
				if(x2 == 0)
					{
						if (isalpha(ch))	
							{
    								fd7_type = 2;
								x2 = 1;
							} 

						if (isdigit(ch)) 	
							{
    								fd7_type = 1;
								x2 = 1;
							}

						if((ch == '(') && (x2 == 0))
							{
								start_parm = 1;
							}
					}
				
				if((ch == ')') && (start_parm == 1))
					{
						ch = p_string[pi+1];
						if(ch == ';')
							{
								pi = s;
								break;
							}
					}

				if((ch == '(') && (x4 == 1))
					{
						
					}

				if(ch != ';')
					{
						field7[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
				x4 = 1;
			}
		field7[pi2] = '\0';

		field7a[0] = '\0';
		if(start_parm == 1)
			{
				x4 = 0;
				pi2 = 0;
				ch = field5[x4];
				while(ch != '\0')
					{
						if(ch != '(')
							{
								field5a[pi2] = ch;
								pi2++;
							}
						x4++;
						ch = field5[x4];
					}
				field5a[pi2] = '\0';
				strcpy(field5,field5a);
			}

		if(fd7_type == 1)
			{
				s = strlen(field7);
				x99 = 0;
				p1 = strstr(field7,"-");
				if(p1)
					{
						x99 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, field7);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										field7[pi2] = ch;
										pi2++;
									}
							}
						field7[pi2] = '\0';
					}

				if(x99 == 0)
					{	
						strcpy(field7a, field7);
					}
				else
					{
						strcpy(field7a,"-");
						strcat(field7a, field7);
					}

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s1 = strlen(c_wkname);
				c_wkname[s1] = '\0';
				strcpy(field2, c_wkname);
				rct1 = rct;
				strcpy(tfield21,field2);
								
				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
				strcpy(w_literal[lit_ct].lit_name, field2);
                            strcpy(w_literal[lit_ct].lit_cname, field2);	
      				strcpy(w_literal[lit_ct].lit_value, field7a); 
				strcpy(w_literal[lit_ct].lit_use_cname, tfield21);
				w_literal[lit_ct].lit_uct = 3; 
				w_literal[lit_ct].lit_dec = 0;
				w_literal[lit_ct].lit_type = 1;	      	             
				lit_ct++;
			}

		pi++;
		ch = p_string[pi];
		while(ch == ' ')
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

		x4 = 0;
		x2 = 0;
		pi2 = 0;
		while((pi < s2) && (ch != ' '))
			{
				if(x2 == 0)
					{
						if (isalpha(ch))	
							{
    								fd9_type = 2;
								x2 = 1;
							} 

						if (isdigit(ch)) 	
							{
    								fd9_type = 1;
								x2 = 1;
							}

						if((ch == '(') && (x2 == 0))
							{
								start_parm = 1;
							}
					}
				
				if((ch == ')') && (start_parm == 1))
					{
						ch = p_string[pi+1];
						if(ch == ';')
							{
								pi = s;
								break;
							}
					}

				if((ch == '(') && (x4 == 1))
					{
						
					}

				if(ch != ';')
					{
						field9[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
				x4 = 1;
			}
		field9[pi2] = '\0';

		if(start_parm == 1)
			{
				x4 = 0;
				pi2 = 0;
				ch = field5[x4];
				while(ch != '\0')
					{
						if(ch != '(')
							{
								field5a[pi2] = ch;
								pi2++;
							}
						x4++;
						ch = field5[x4];
					}
				field5a[pi2] = '\0';
				strcpy(field5,field5a);
			}
		
		if(fd9_type == 1)
			{
				s = strlen(field9);
				x99 = 0;
				p1 = strstr(field9,"-");
				if(p1)
					{
						x99 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, field9);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										field9[pi2] = ch;
										pi2++;
									}
							}
						field9[pi2] = '\0';
					}

				if(x99 == 0)
					{
						strcpy(field9a, field9);
					}
				else
					{
						strcpy(field9a,"-");
						strcat(field9a, field9);
					}

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s1 = strlen(c_wkname);
				c_wkname[s1] = '\0';
				strcpy(field2, c_wkname);

				rct1 = rct;
				strcpy(tfield21,field2);
				
				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
				strcpy(w_literal[lit_ct].lit_name, null_field);
                            strcpy(w_literal[lit_ct].lit_cname, field2);	
      				strcpy(w_literal[lit_ct].lit_value, field9a);
				strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 
				w_literal[lit_ct].lit_uct = 4; 
				w_literal[lit_ct].lit_dec = 0;
				w_literal[lit_ct].lit_type = 1;	      	             
				lit_ct++;
			}

		pi++;
		ch = p_string[pi];
		while(ch == ' ')
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

		x4 = 0;
		x2 = 0;
		pi2 = 0;
		while((pi < s2) && (ch != ' '))
			{
				if(x2 == 0)
					{
						if (isalpha(ch))	
							{
    								fd11_type = 2;
								x2 = 1;
							}
 
						if (isdigit(ch)) 	
							{
    								fd11_type = 1;
								x2 = 1;
							}

						if((ch == '(') && (x2 == 0))
							{
								start_parm = 1;
							}
					}
				
				if((ch == ')') && (start_parm == 1))
					{
						ch = p_string[pi+1];
						if(ch == ';')
							{
								pi = s;
								break;
							}
					}

				if((ch == '(') && (x4 == 1))
					{
						
					}

				if(ch != ';')
					{
						field11[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
				x4 = 1;
			}
		field11[pi2] = '\0';

		if(start_parm == 1)
			{
				x4 = 0;
				pi2 = 0;
				ch = field5[x4];
				while(ch != '\0')
					{
						if(ch != '(')
							{
								field5a[pi2] = ch;
								pi2++;
							}
						x4++;
						ch = field5[x4];
					}
				field5a[pi2] = '\0';
				strcpy(field5,field5a);
			}

		if(fd11_type == 1)
			{
				s = strlen(field11);
				x99 = 0;
				p1 = strstr(field11,"-");
				if(p1)
					{
						x99 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, field11);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										field11[pi2] = ch;
										pi2++;
									}
							}
						field11[pi2] = '\0';
					}

				if(x99 == 0)
					{	
						strcpy(field11a, field11);
					}
				else
					{
						strcpy(field11a,"-");
						strcat(field11a, field11);
					}

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s1 = strlen(c_wkname);
				c_wkname[s1] = '\0';
				strcpy(field2, c_wkname);

				rct1 = rct;
				strcpy(tfield21,field2);
				
				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
				strcpy(w_literal[lit_ct].lit_name, null_field);
                            strcpy(w_literal[lit_ct].lit_cname, field2);	
      				strcpy(w_literal[lit_ct].lit_value, field11a); 
				strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 
				w_literal[lit_ct].lit_uct = 5;
				w_literal[lit_ct].lit_dec = 0;
				w_literal[lit_ct].lit_type = 1;	      		             
				lit_ct++;
			}
	}


void c2_pass2_sc1()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_sc1");
	 trace_rec_1();
     }
		
     char ch;
     char *p, *p1;
     char tfield1[VAR_LGTH];
     char tfield1a[VAR_LGTH];
     char tfield2[VAR_LGTH];
     char tfield2a[VAR_LGTH];
     char tfield3[VAR_LGTH];
     char tfield3a[VAR_LGTH];
     char tfield3b[VAR_LGTH];
     char tfield5[VAR_LGTH];
     char tfield5a[VAR_LGTH];
     char tfield21[VAR_LGTH];
		
     inside_for = 1;
     for_opr = 0;
	
      int pi;
      int pi2;
      int x2 = 0;
      int x3 = 0;
      int x10 = 0;
      int x99 = 0;
      int I = 0;
      int s = 0;
      int s1 = 0;
      int size = 0;
      int ret = 0;
      int ret1 = 0;
      int ret2 = 0;
      int rct1 = 0;

      int fd2_type = 0;
      int fd5_type = 0;
				
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
     if(ch == ';')
     {
        goto skip_for_1;
     }

     while(ch != '=')
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

     x10 = 0;
     p = strstr(tfield1, ";");
     if(p)
     {
        x10 = 1;
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
		   printf("c2z_pass_2.c c2_pass2_sc1 tfield1 Not Numeric = %s\n",tfield1);
		   printf("c2z_pass_2.c c2_pass2_sc1 rct = %d p_string = %s",rct,p_string);
		   c2_debug();
		   exit(1);
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
		      printf("c2z_pass_2.c c2_pass2_sc1 tfield1 Not Numeric = %s\n",tfield1);
		      printf("c2z_pass_2.c c2_pass2_sc1 rct = %d p_string = %s",rct,p_string);
		      c2_debug();
		      exit(1);
		   }	
		}
	    }		
	 }

        if(x3 == 0)
	 {
	    printf("c2z_pass_2.c c2_pass2_sc1 tfield1 Not Found = %s\n",tfield1);
	    printf("c2z_pass_2.c c2_pass2_sc1 rct = %d p_string = %s",rct,p_string);
	    c2_debug();
	    exit(1);
	 }
     }

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



		if(fd2_type == 2)
			{
				ret = strcmp("0",tfield2);
				if(ret != 0)
					{
						s = strlen(tfield2);
						x99 = 0;
						p1 = strstr(tfield2,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, tfield2);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												tfield2[pi2] = ch;
												pi2++;
											}
									}
								tfield2[pi2] = '\0';
							}

						if(x99 == 0)
							{	
								strcpy(tfield2a, tfield2);
							}
						else
							{
								strcpy(tfield2a,"-");
								strcat(tfield2a, tfield2);
							}

						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield1a, c_wkname);

						rct1 = rct;
						strcpy(tfield21, tfield1a);
						for(I=0; I < lit_ct; I++)
							{
								ret = strcmp(w_literal[I].lit_value, tfield2a);
								if(ret == 0)
									{
										x10 = 1;
										rct1 = w_literal[I].lit_rct;
										strcpy(tfield21, w_literal[I].lit_cname);
										break;
									}
							}
				
						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
						strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, tfield1a);
						strcpy(w_literal[lit_ct].lit_value, tfield2a); 
						strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 
						w_literal[lit_ct].lit_uct = 1;
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      	             
						lit_ct++;
					}
			}
skip_for_1:

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
								printf("c2z_pass_2.c c2_pass2_sc1 tfield3 Not Numeric %s\n",tfield3);
								printf("c2z_pass_2.c c2_pass2_sc1 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
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
										printf("c2z_pass_2.c c2_pass2_sc1 tfield3 Not Numberic = %s\n",tfield3);
										printf("c2z_pass_2.c c2_pass2_sc1 rct = %d p_string = %s",rct,p_string);
										c2_debug();
										exit(1);
									}	
								x3 = 1;		
								strcpy(tfield3a, gw_variable[I].gv_cname);
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_pass_2.c c2_pass2_sc1 tfield3 Not Found = %s\n",tfield3);
				printf("c2z_pass_2.c c2_pass2_sc1 rct = %d p_string = %s",rct,p_string);
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

		pi2 = 0;
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
		
		if(fd5_type == 2)
			{
				s = strlen(tfield5);
				x99 = 0;
				p1 = strstr(tfield5,"-");
				if(p1)
					{
						x99 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, tfield5);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										tfield5[pi2] = ch;
										pi2++;
									}
							}
						tfield5[pi2] = '\0';
					}

				if(x99 == 0)
					{
						strcpy(tfield5a, tfield5);
					}
				else
					{
						strcpy(tfield5a,"-");
						strcat(tfield5a, tfield5);
					}

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield3a, c_wkname);

				rct1 = rct;
				strcpy(tfield21, tfield3a);
				for(I=0; I < lit_ct; I++)
					{
						ret = strcmp(w_literal[I].lit_value, tfield2a);
						if(ret == 0)
							{
								x10 = 1;
								rct1 = w_literal[I].lit_rct;
								strcpy(tfield21, w_literal[I].lit_cname);
								break;
							}
					}
				
				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
				strcpy(w_literal[lit_ct].lit_name, null_field);
				strcpy(w_literal[lit_ct].lit_cname, tfield3a);
				strcpy(w_literal[lit_ct].lit_value, tfield5a);
				strcpy(w_literal[lit_ct].lit_use_cname,tfield21); 
				w_literal[lit_ct].lit_uct = 1; 
				w_literal[lit_ct].lit_dec = 0;
				w_literal[lit_ct].lit_type = 1;	      	             
				lit_ct++;
			}
	}

void c2_pass2_sc2()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_sc2");
				trace_rec_1();
			}

		char ch;
		char *p;
              char *p1;

		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
									
		tfield1a[0] = '\0';
		
		int pi;
		int pi2;
		int size = 0;
		int x3 = 0;						
		int s = 0;
		int I = 0;
		int ret = 0;
		int ret1 = 0;
		int x4 = 0;
		int x5 = 0;
		int x6 = 0;
              int array_found = 0;

              p1 = strstr(p_string, "[");
              if(p1)
              {
                 array_found = 1;
              }

          
	       if(array_found == 0)
              {	
		p = strstr(p_string, "\"");		
		if(p)				
			{
				pi = 0;
				ch = p_string[pi];
				while(ch != ',')
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
				w_charlit[char_ct].clit_type = 3;
				w_charlit[char_ct].clit_lgth = x3; 
				w_charlit[char_ct].clit_uct = 1;	             
				char_ct++;
			}

		
		if(!p)				/* field cat		strcat(a,b);	*/
			{
				s = strlen(p_string);
				pi = 0;
				pi2 = 0;
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
				while(ch != ')')
					{
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1,lw_variable[I].lv_name);
						ret1 = strcmp(sv_func,lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(tfield1a,lw_variable[I].lv_cname);
								x6 = lw_variable[I].lv_lgth;
 							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1,gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(tfield1a,gw_variable[I].gv_cname);
										x6 = gw_variable[I].gv_current_lgth;
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_pass_2.c c2_pass2_sc2 tfield1 Not Found = %s\n",tfield1);
						printf("c2z_pass_2.c c2_pass2_sc2 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield2,lw_variable[I].lv_name);
						ret1 = strcmp(sv_func,lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(tfield2a,lw_variable[I].lv_cname);
								x5 = lw_variable[I].lv_lgth;
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
										strcpy(tfield2a,gw_variable[I].gv_cname);
										x5 = gw_variable[I].gv_current_lgth;
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_pass_2.c c2_pass2_sc2 tfield2 Not Found = %s\n",tfield2);
						printf("c2z_pass_2.c c2_pass2_sc2 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
				
				x4 = x5 + x6;

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1,lw_variable[I].lv_name);
						ret1 = strcmp(sv_func,lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								lw_variable[I].lv_current_lgth = x4;
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1,gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										gw_variable[I].gv_current_lgth = x4;
									}
							}
					}
			}
             }

             if(array_found == 1)
             {
                 printf("c2_pass_2.c c2_strcat_sc2 NOT FINISHED\n");
                 /* 
                   c2_debug();
                   exit(0);
                 */
             }

		convert = 1;
	}


void c2_pass2_if()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_if");
	 trace_rec_1();
     }

     char ch;
     char *p1;
     char *p2;
     char *p3;
     char *p4;
     char *p5;
     char *p6;
     char *p7;
     char *p8;
     char *p9;
     char tfield1[VAR_LGTH];
     char tfield1a[VAR_LGTH];

     tfield1a[0] = '\0';
		
     int pi;
     int pi2;
     if_convert = 0;
     int s = 0;
     int I = 0;
     int ret = 0;
     int bracket_ct = 0;
     int if_complex = 0;

     if_opr = 0;
     inside_if1 = 1;
     convert = 0;

     s = strlen(p_string);
     for(I = 0; I < s; I++)
     {
        ch = p_string[I];
	 if(ch == '[')
	    bracket_ct++;
	 if(ch == ']')
	    bracket_ct++;
     }

     p = strstr(p_string, "(!");
     if(p)
     {
         convert = 1;
         return;
     }
	
     if((if_opr == 0) && (convert == 0))
     {
				p8 = strstr(p_string, "strchr");
				if(p8)
					{
						if_opr = 15;					
					}
			}
				
		if((if_opr == 0) && (convert == 0))
			{
				p8 = strstr(p_string, "strcmp");
				if(p8)
					{
						if_opr = 10;
					}
			}

		if((if_opr == 0)  && (convert == 0))
			{
				p8 = strstr(p_string, "eof");
				if(p8)
					{
						if_opr = 9;
					}
			}

		if((if_opr == 0) && (convert == 0))
			{
				p8 = strstr(p_string, "isalpha");
				if(p8)
					{
						if_opr = 8;
					}
			}

		if((if_opr == 0) && (convert == 0))
			{
				p7 = strstr(p_string, "isdigit");
				if(p7)
					{
						if_opr = 7;
					}
			}
		
		if((if_opr == 0) && (convert == 0))
			{
				p7 = strstr(p_string, "isupper");
				if(p7)
					{
						if_opr = 22;
					}
			}

		if((if_opr == 0) && (convert == 0))
			{
				p7 = strstr(p_string, "isalnum");
				if(p7)
					{
						if_opr = 23;
					}
			}

     p9 = strstr(p_string, "&&");
     if(p9)
     {
        if_complex = 1;
     }

     p9 = strstr(p_string, "||");
     if(p9)
     {
        if_complex = 1;
     }

     if((if_opr == 0) && (if_complex == 1) && (convert == 0))
     {
        if_opr = 20;
        c2_pass2_if_13(); 
        if_convert = 1;
        return;
     }

		if((if_opr == 0) && (convert == 0))
			{
				p6 = strstr(p_string, "<=");
				if(p6)
					{
						if_opr = 6;
					}
			}

		if((if_opr == 0)  && (convert == 0))
			{
				p5 = strstr(p_string, ">=");
				if(p5)
					{
						if_opr = 5;
					}
			}

		if((if_opr == 0) && (convert == 0))
			{
				p4 = strstr(p_string, "<");
				if(p4)
					{
						if_opr = 4;
					}
			}

		if((if_opr == 0) && (convert == 0))
			{
				p3 = strstr(p_string, ">");
				if(p3)
					{
						if_opr = 1;
					}
			}

		if((if_opr == 0) && (convert == 0))
			{
				p2 = strstr(p_string, "!=");
				if(p2)
					{
						if_opr = 2;
					}
			}

		if((if_opr == 0) && (convert == 0))
			{
				p1 = strstr(p_string, "==");
				if(p1)
					{
						if_opr = 1;
					}
			}

		if((if_opr == 22) && (if_convert == 0))
			{	
				/* if_case_22(); */
				if_convert = 1;
				return;
			}

		if((if_opr == 23) && (if_convert == 0))
			{	
				/* if_case_23(); */
				if_convert = 1;
				return;
			}

		if((if_opr == 15) && (if_convert == 0))
			{	
				c2_pass2_if_15(); 
				if_convert = 1;
				return;
			}

		if((if_opr == 1) && (if_convert == 0) && (bracket_ct == 0))
			{	
				c2_pass2_if_1();
				if_convert = 1;
			}

		if((if_opr == 2) && (if_convert == 0))
			{	
				c2_pass2_if_2(); 
				if_convert = 1;
			}

		if((if_opr == 3) && (if_convert == 0))
			{	
				/* if_case_3(); */
				if_convert = 1;
			}
	
		if((if_opr == 4) && (if_convert == 0) && (convert == 0))
			{	
				c2_pass2_if_4(); 
				if_convert = 1;
			}
		
		if((if_opr == 5) && (if_convert == 0))
			{
				c2_pass2_if_1();
				if_convert = 1;
			}

		if((if_opr == 6) && (if_convert == 0))
			{	
				/* if_case_6(); */
				if_convert = 1;
			}

		if((if_opr == 7) && (if_convert == 0))
			{	
				/* if_case_7(); */
				if_convert = 1;
			}

		if((if_opr == 8) && (if_convert == 0))
			{	
				/* if_case_8(); */
				if_convert = 1;
			}

		if((if_opr == 9) && (if_convert == 0))
			{	
				/* if_case_9(); */
				if_convert = 1;
			}

		if((if_opr == 10) && (if_convert == 0))
			{	
				c2_pass2_if_10();
				if_convert = 1;
			}

		if(if_convert == 0)
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
				while(ch != '(')
					{
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				for(I=0; I < fn_ct; I++)
					{
						ret = strcmp(tfield1, w_function[I].fn_name);
						if(ret == 0)
							{
								strcpy(tfield1a, w_function[I].fn_cname);
								if_opr = 12;
							}
					}
			}

		if((if_opr == 12) && (if_convert == 0))
			{	
				/* if_case_12(); */
				if_convert = 1;
			}

		convert = 1;
	}	

void c2_pass2_if_1()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_1");
        trace_rec_1();
     }

     char ch;
     char *p, *p1, *p5;
     char field1[VAR_LGTH];
     char field1a[VAR_LGTH];
     char field2[VAR_LGTH];
     char field2a[VAR_LGTH];
     char field3a[VAR_LGTH];
     char tfield3b[VAR_LGTH];
     char tfield21[VAR_LGTH];

      int pi;
      int pi2;
      int I = 0;
      int if_comma = 0;
      int if_complex = 0;
      int if_blank = 0;
      int if_quote = 0;
      int if_convert = 0;
      int fd1_type = 0;
      int fd2_type = 0;
      int x = 0;
      int x2 = 0;
      int x3 = 0;
      int x4 = 0;
      int x5 = 0;
      int x99 = 0;
      int s = 0;
      int s1 = 0;
      int size = 0;
      int rct1 = 0;
      int ret = 0;
      int ret1 = 0;

     convert = 0;

     p = strstr(p_string, "&&");
     if(p)
     {
        if_complex = 1;
     }

     p = strstr(p_string, "||");
     if(p)
     {
        if_complex = 1;
     }



		if(if_complex == 0)			
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_1 simple");
						trace_rec_1();
					}

				pi = 0;
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}
				
				pi2 = 0;
				x3 = 0;
				x2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						if((ch == '_') && (x3 == 0))
							{
								x3 = 1;
							}

						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										fd1_type = 1;
										x2 = 1;
									} 
								if (isalpha(ch))	
									{
										fd1_type = 2;
										x2 = 1;
									}
							}
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

				x3 = 0;
				x4 = 0;
				x5 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(field1a, lw_variable[I].lv_cname);
								lw_variable[I].lv_use_ct++;
								x5 = strcmp("I",lw_variable[I].lv_type);
								if(x5 == 0)
									x4 = 1;
								x5 = strcmp("C",lw_variable[I].lv_type);
								if(x5 == 0)
									x4 = 2;
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
										gw_variable[I].gv_use_ct++;
										x5 = strcmp("I",gw_variable[I].gv_type);
										if(x5 == 0)
											x4 = 1;
										x5 = strcmp("C",gw_variable[I].gv_type);
										if(x5 == 0)
											x4 = 2;
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_pass_2.c if_case_1 E-256 field1 Not Found = %s\n",field1);
						c2_error();
					}
				
				pi++;
				ch = p_string[pi];
				while(ch == ' ')						
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

				x2 = 0;           
				pi2 = 0;
				while(ch != ')')
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
						field2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field2[pi2] = '\0';

				if_comma = 0;
				if_blank = 0;

				p5 = strstr(field2, " ");
				if(p5)
					{
						if_blank = 1;
					}
				
				p5 = strstr(field2,",");
				if(p5)
					{
						if_comma = 1;
					}

				p5 = strstr(field2, ";");
				if(p5)
					{		
						if_comma = 2;
					}

				p5 = strchr(field2, '\'');
				if(p5)
					{
						if_quote = 1;
						fd2_type = 1;
					}

				strcpy(field2a, field2);

				if((if_comma == 0) && (if_blank == 0) && (fd2_type == 2) && (if_quote == 0))
					{
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
										x = strcmp(lw_variable[I].lv_type, "I");
										if(x == 0)
											{
												fd1_type = 2;
											}
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
												x = strcmp(gw_variable[I].gv_type, "I");
												if(x == 0)
													{
														fd2_type = 2;
													}
											}
									}
							}

						/*
						if(x3 == 0)
							{
								printf("if_case_1 E-257 field2 Not Found = %s\n",field2);
								c2_error();
								printf("if_case_1 field2 = %s\n",field2);
								printf("if_case_1 field2a = %s\n",field2a);
							}
						*/
					}

				if((if_comma == 0) && (fd2_type == 2) && (if_convert == 0))
					{
						if_convert = 1;
						return;
					}

				if((if_comma == 0) && (fd2_type == 1) && (convert == 0))
					{
						if((fd1_type == 2) && (fd2_type == 1) && (x4 == 2))
							{
								x3 = strlen(field2);
								c_name++;
								snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
								strcpy(c_wkname, "C37F");
								strcat(c_wkname, wk_strg);
								s = strlen(c_wkname);
								c_wkname[s] = '\0';
								strcpy(field3a, c_wkname);
				
								s = strlen(field2);

								pi2 = 0;
								for(I=0; I < s; I++)
									{
										ch = field2[I];
										if(ch != '\'')
											{
												if(ch != '\\')
													{
														field2a[pi2] = ch;
														pi2++;
													}
											}
									}
								field2a[pi2] = '\0';

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
								strcpy(w_charlit[char_ct].clit_cname, field3a);	
      								strcpy(w_charlit[char_ct].clit_value, field2a); 
								w_charlit[char_ct].clit_type = 3;
								w_charlit[char_ct].clit_lgth = x3;
								w_charlit[char_ct].clit_uct = 1; 	             
								char_ct++;
								return;
							}

						if((fd1_type == 2) && (fd2_type == 1) && (x4 == 1))
							{
								c_name++;
								snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
								strcpy(c_wkname, "C37F");
								strcat(c_wkname, wk_strg);
								s = strlen(c_wkname);
								c_wkname[s] = '\0';
								strcpy(field1a, c_wkname);

								s = strlen(field2);
								x99 = 0;
								p1 = strstr(field2,"-");
								if(p1)
									{
										x99 = 1;
									}

								s1 = s + 1;
								if(x99 == 1)
									{
										strcpy(tfield3b, field2);
										pi2 = 0;
										for(I=0; I < s1; I++)
											{
												ch = tfield3b[I];
												if(ch != '-')
													{
														field2[pi2] = ch;
														pi2++;
													}
											}
										field2[pi2] = '\0';
									}

								if(x99 == 0)
									{	
										strcpy(field2a, field2);
									}
								else
									{
										strcpy(field2a,"-");
										strcat(field2a, field2);
									}

								rct1 = rct;
								strcpy(tfield21, field1a);
								for(I=0; I < lit_ct; I++)
									{
										ret = strcmp(w_literal[I].lit_value, field2a);
										if(ret == 0)
											{
												rct1 = w_literal[I].lit_rct;
												strcpy(tfield21, w_literal[I].lit_cname);
												break;
											}
									}

								if(lit_ct == 0)
									{
										size = 1;
										w_literal = malloc(size * sizeof(struct literal));
									}
								else
									{
										size = lit_ct + 1;
										w_literal = realloc(w_literal, size * sizeof(struct literal));
									}

								w_literal[lit_ct].lit_rct = rct;
								w_literal[lit_ct].lit_use_rct = rct1;
                                         			strcpy(w_literal[lit_ct].lit_name, null_field);
								strcpy(w_literal[lit_ct].lit_cname, field1a);	
      								strcpy(w_literal[lit_ct].lit_value, field2a);  
								strcpy(w_literal[lit_ct].lit_use_cname, tfield21);
								w_literal[lit_ct].lit_uct = 1;	
								w_literal[lit_ct].lit_dec = 0;
								w_literal[lit_ct].lit_type = 1;	                   
								lit_ct++;
							}

						if_convert = 1;
					}

				if((if_comma == 0) && (fd2_type == 1) && (if_quote == 0) && (if_convert == 0))
					{
						printf("c2_pass_2.c if_case_1 #1 Not Coded\n");
						printf("c2_pass_2.c rct = %d p_string = %s",rct,p_string);
						c2_debug();
						if_convert = 1;
						return;
					}

				if((if_comma == 1) && (if_blank == 0) && (fd2_type == 1) && (if_convert == 0))
					{
						printf("c2_pass_2.c if_case_1 #2 Not Coded\n");
						printf("c2_pass_2.c rct = %d p_string = %s",rct,p_string);
						c2_debug();
						if_convert = 1;
						return;
					}

				if((if_comma == 1) && (if_blank == 0) && (if_convert == 0))
					{
						printf("c2_pass_2.c if_case_1 #3 Not Coded\n");
						printf("c2_pass_2.c rct = %d p_string = %s",rct,p_string);
						c2_debug();
						if_convert = 1;
						return;
					}
			}	

		if((if_complex == 1) && (if_convert == 0))		/* complex if statement	*/
			{
				printf("c2_pass_2.c if_case_1 #4 Not Coded\n");
				printf("c2_pass_2.c rct = %d p_string = %s",rct,p_string);
				c2_debug();
				if_convert = 1;
				convert = 1;
				return;
			}	

		convert = 1;				
	}

void c2_pass2_if_2()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2");
				trace_rec_1();
			}

		char ch, *p1;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char tfield3b[VAR_LGTH];
		char field4[VAR_LGTH];
		char field4a[VAR_LGTH];
		char tfield21[VAR_LGTH];

		char ar_field5[VAR_LGTH];
		char ar_field6[VAR_LGTH];
		char ar_field7[VAR_LGTH];
		char ar_field8[VAR_LGTH];
		char ar_field9[VAR_LGTH];
		char ar_field10[VAR_LGTH];
		char ar_field11[VAR_LGTH];

		int pi;
		int pi2;
		int I = 0;
		int x = 0;
		int x2 = 0;
		int x3 = 0;
		int x99 = 0;
		int s = 0;
		int s1 = 0;
		int size = 0;
		int if_complex = 0;
		int if_bracket = 0;
		int rct1 = 0;
		int x10 = 0;

		int fd1_type = 0;
		int fd2_type = 0;
		int fd4_type = 0;

		int ret = 0;
		int ret1 = 0;

		char *p;

		p = strstr(p_string, "&&");
		if(p)
			{
				if_complex = 1;
			}

		p = strstr(p_string, "||");
		if(p)
			{
				if_complex = 1;
			}

		if(if_complex == 0)		
			{
				p = strstr(p_string, "[");
				if(p)
					{
						if_bracket = 1;
					}

				if(if_bracket == 1)
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_pass_2.c if_case_2 if_bracket = 1");
								trace_rec_1();
							}

						pi = 0;
						ch = p_string[pi];
						while(ch != '(')
							{
								pi++;
								ch = p_string[pi];
							}

						pi2 = 0;
						x3 = 0;
						x2 = 0;
						pi++;
						ch = p_string[pi];
						while(ch != '[')
							{
								if(x2 == 0)
									{
										if (isdigit(ch)) 	
											{
												fd1_type = 1;
												x2 = 1;
											} 

										if (isalpha(ch))	
											{
												fd1_type = 2;
												x2 = 1;
											}
									}
								field1[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						field1[pi2] = '\0';

						pi2 = 0;
						x3 = 0;
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
								field2[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						field2[pi2] = '\0';

						pi++;
						ch = p_string[pi];
						while(ch == ' ')
							{
								pi++;
								ch = p_string[pi];
							}

						pi2 = 0;
						x3 = 0;
						x2 = 0;
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
						x3 = 0;
						x2 = 0;
						while(ch != ')')
							{
								if(x2 == 0)
									{
										if (isdigit(ch)) 	
											{
												fd4_type = 1;
												x2 = 1;
											} 

										if (isalpha(ch))	
											{
												fd4_type = 2;
												x2 = 1;
											}
									}
								field4[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						field4[pi2] = '\0';

						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(field1, gw_variable[I].gv_name);
								ret1 = strcmp("G", gw_variable[I].gv_type);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;
										strcpy(field1a, gw_variable[I].gv_cname);
										strcpy(ar_field5, gw_variable[I].gv_dsect);
										strcpy(ar_field6, gw_variable[I].gv_label);
										strcpy(ar_field7, gw_variable[I].gv_table);
										strcpy(ar_field8, gw_variable[I].gv_aname);
										strcpy(ar_field9, gw_variable[I].gv_sv_reg);
										strcpy(ar_field10, gw_variable[I].gv_wk_reg);
										strcpy(ar_field11, gw_variable[I].gv_wk_strg);
										gw_variable[I].gv_use_ct++;
										/* var_type[0] = 'G';
										var_type[1] = '\0' */;
									}
							}
						
						if(x3 == 0)
							{
								for(I=0; I < m_struc_ct; I++)
									{
										ret = strcmp(field1, w_struc[I].st_wname);
										if(ret == 0)
											{
												x3 = 1;
												break;
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_pass_2.c c2_pass2_if_2 bracket = 1 field1 Not Found = %s\n",field1); 
								printf("c2z_pass_2.c c2_pass2_if_2 bracket = 1 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
							}

						if(fd2_type == 2)
							{
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
											}
									}

								if(x3 == 0)
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(field2,gw_variable[I].gv_name);
												if(ret == 0)
													{
														x3 = 1;
														strcpy(field2a, gw_variable[I].gv_cname);
														gw_variable[I].gv_use_ct++;
													}
											}
									}

								if(x3 == 0)
									{
										printf("c2z_pass_2.c c2_pass2_if_2 bracket = 1 field2 Not Found = %s\n",field2); 
										printf("c2z_pass_2.c c2_pass2_if_2 bracket = 1 rct = %d p_string = %s",rct,p_string);
										c2_debug();
										exit(1);
									}
							}

						if(fd4_type == 2)
							{
								x3 = 0;
								for(I=0; I < lv_ct; I++)
									{
										ret = strcmp(field4, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												x3 = 1;
												strcpy(field4a, lw_variable[I].lv_cname);
												lw_variable[I].lv_use_ct++;
											}
									}

								if(x3 == 0)
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(field4,gw_variable[I].gv_name);
												if(ret == 0)
													{
														x3 = 1;
														strcpy(field4a, gw_variable[I].gv_cname);
														gw_variable[I].gv_use_ct++;
													}
											}
									}

								if(x3 == 0)
									{
										for(I=0; I < m_struc_ct; I++)
											{
												ret = strcmp(field4, w_struc[I].st_wname);
												if(ret == 0)
													{
														x3 = 1;
														break;
													}
											}
									}

								if(x3 == 0)
									{
										printf("c2z_pass_2.c c2_pass2_if_2 bracket = 1 field4 Not Found = %s\n",field4); 
										printf("c2_pass2_if_2 bracket = 1 rct = %d p_string = %s",rct,p_string);
										printf("c2_pass2_if_2 field4 = %s\n", field1);
										exit(1); 
									}

							}

						if((fd2_type == 2) && (fd4_type == 1))
							{
								c_name++;
								snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
								strcpy(c_wkname, "C37F");
								strcat(c_wkname, wk_strg);
								s = strlen(c_wkname);
								c_wkname[s] = '\0';
						
								s = strlen(field4);
								x99 = 0;
								p1 = strstr(field4,"-");
								if(p1)
									{
										x99 = 1;
									}

								s1 = s + 1;
								if(x99 == 1)
									{
										strcpy(tfield3b, field4);
										pi2 = 0;
										for(I=0; I < s1; I++)
											{
												ch = tfield3b[I];
												if(ch != '-')
													{
														field4[pi2] = ch;
														pi2++;
													}
											}
										field4[pi2] = '\0';
									}

								if(x99 == 0)
									{	
										strcpy(field4a, field4);
									}
								else
									{
										strcpy(field4a,"-");
										strcat(field4a, field4);
									}

								rct1 = rct;
								strcpy(tfield21,c_wkname);
								for(I=0; I < lit_ct; I++)
									{
										ret = strcmp(w_literal[I].lit_value, field4a);
										if(ret == 0)
											{
												x10 = 1;
												rct1 = w_literal[I].lit_rct;
												strcpy(tfield21, w_literal[I].lit_cname);
												break;
											}
									}
	
								if(lit_ct == 0)
									{
										size = 1;
										w_literal = malloc(size * sizeof(struct literal));
									}
								else
									{
										size = lit_ct + 1;
										w_literal = realloc(w_literal, size * sizeof(struct literal));
									}

								w_literal[lit_ct].lit_rct = rct;
								w_literal[lit_ct].lit_use_rct = rct1;
                                        	 		strcpy(w_literal[lit_ct].lit_name, null_field);
								strcpy(w_literal[lit_ct].lit_cname, c_wkname);	
      								strcpy(w_literal[lit_ct].lit_value, field4a);  
								strcpy(w_literal[lit_ct].lit_use_cname, tfield21);
								w_literal[lit_ct].lit_uct = 1;
								w_literal[lit_ct].lit_dec = 0;
								w_literal[lit_ct].lit_type = 1;	      	             
								lit_ct++;

								convert = 1;
							}
					}

				if(if_bracket == 0)
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_pass_2.c if_case_2 if_bracket = 0");
								trace_rec_1();
							}

						pi = 0;
						ch = p_string[pi];
						while(ch != '(')
							{
								pi++;
								ch = p_string[pi];
							}

						pi2 = 0;
						x3 = 0;
						x2 = 0;
						pi++;
						ch = p_string[pi];
						while(ch != ' ')
							{
								if(x2 == 0)
									{
										if (isdigit(ch)) 	
											{
												fd1_type = 1;
												x2 = 1;
											}
 
										if (isalpha(ch))	
											{
												fd1_type = 2;
												x2 = 1;
											}
									}
								field1[pi2] = ch;
								pi2++;
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
										lw_variable[I].lv_use_ct++;
										x = strcmp(lw_variable[I].lv_type, "I");
										if(x == 0)
											{
												fd1_type = 2;
											}
									}
							}

						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(gw_variable[I].gv_name, field1);
										if(ret == 0)
											{
												x3 = 1;
												strcpy(field1a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												x = strcmp(gw_variable[I].gv_type, "I");
												if(x == 0)
													{
														fd1_type = 2;
													}
												else
													{
														fd1_type = 1;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_pass_2.c if_pass2_case_2 E-159 field1 Not Found = %s\n",field1);
								c2_error();
							}

						pi++;
						ch = p_string[pi];
						while(ch == ' ')						
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

						x2 = 0;           
						pi2 = 0;
						while(ch != ')')
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
								field2[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						field2[pi2] = '\0';

						x10 = 0;
						p = strstr(field2, "'");
						if(p)
							{
								x10 = 1;
							}
							
						if((fd2_type == 2) && (x10 == 0))
							{
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
												x = strcmp(lw_variable[I].lv_type, "I");
												if(x == 0)
													{
														fd1_type = 2;
													}
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
														x = strcmp(gw_variable[I].gv_type, "I");
														if(x == 0)
															{
																fd2_type = 2;
															}
													}
											}
									}		

								if(x3 == 0)
									{
										printf("c2z_pass_2.c if_pass2_case_2 field2 Not Found = %s\n",field2);
										printf("c2z_pass_2.c if_pass2_case_2 rct = %d p_string = %s",rct,p_string);
										c2_debug();
										exit(1);
									}
							}

				if((fd1_type == 2) && (fd2_type == 0))
					{						
						pi = 1;
						pi2 = 0;
						ch = field2[pi];
						while(ch != '\'')
							{
								field2a[pi2] = ch;
								pi2++;
								pi++;
								ch = field2[pi];
							}
						field2a[pi2] = '\0';

						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(field2, c_wkname);
				
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
						w_charlit[char_ct].clit_type = 3;
						strcpy(w_charlit[char_ct].clit_cname, field2);	
      						strcpy(w_charlit[char_ct].clit_value, field2a); 
						w_charlit[char_ct].clit_lgth = 1; 
						w_charlit[char_ct].clit_uct = 1;	             
						char_ct++;
					}

				if((fd1_type == 2) && (fd2_type == 2) && (x10 == 1))
					{
						pi = 1;
						pi2 = 0;
						ch = field2[pi];
						while(ch != '\'')
							{
								field2a[pi2] = ch;
								pi2++;
								pi++;
								ch = field2[pi];
							}
						field2a[pi2] = '\0';

						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(field2, c_wkname);
				
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
						w_charlit[char_ct].clit_type = 3;
						strcpy(w_charlit[char_ct].clit_cname, field2);	
      						strcpy(w_charlit[char_ct].clit_value, field2a); 
						w_charlit[char_ct].clit_lgth = 1; 
						w_charlit[char_ct].clit_uct = 1;	             
						char_ct++;
					}

				convert = 1;

				return;
			}

			}	

		if(if_complex == 1)
			{
				return;
			}

		convert = 1;

	}

void c2_pass2_if_10()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_10_strcmp");
				trace_rec_1();
			}

		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];

		int pi;
		int pi2;
		int if_1 = 0;
		int if_2 = 0;
		int if_4 = 0;
		int I = 0;
              int x3 = 0;
              int s = 0;
              int size = 0;

		int ret = 0;
		int ret1 = 0;
				
		pi = 0;
		ch = p_string[pi];
		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			}

		pi++;
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
                            if(ch != '\"')
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

		if_1 = 0;
		pi2 = 0;
		while(ch != ')')
			{
				if(ch == '\"')
					{
						if_1 = 1;
					}
				if(ch != '\"')
					{
						tfield2[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		tfield2[pi2] = '\0';

		if(if_1 == 1)		
			{
				if_4 = 0;
				if(lv_ct > 0)
					{
						for(I = 0; I < lv_ct; I++)
							{
								ret = strcmp(tfield1, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										if_4 = 1;
										strcpy(tfield1a, lw_variable[I].lv_cname);
									}
							}
					}
			
				if(if_4 == 0)
					{
						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										if_2 = strcmp(tfield1, gw_variable[I].gv_name);
										if(if_2 == 0)
											{
												if_4 = 1;
												strcpy(tfield1a, gw_variable[I].gv_cname);
											}
									}
							}
					}

				if(if_4 == 0)
					{
						printf("c2z_pass_2.c c2_pass2_if_10_strcmp tfield1 Not Found = %s\n",tfield1);
						printf("c2z_pass_2.c c2_pass2_if_10_strcmp rct = %d p_string = %s\n",rct,p_string);
						c2_debug();
						exit(1);
					}

				x3 = strlen(tfield2);
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield2a, c_wkname);
				
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
				w_charlit[char_ct].clit_type = 3;
				strcpy(w_charlit[char_ct].clit_cname, tfield2a);	
      				strcpy(w_charlit[char_ct].clit_value, tfield2); 
				w_charlit[char_ct].clit_lgth = x3; 
				w_charlit[char_ct].clit_uct = 1;	             
				char_ct++;

				convert = 1;
			}	

		if(if_1 == 0)		
			{
				x3 = strlen(tfield1);
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
				w_charlit[char_ct].clit_type = 3;
				strcpy(w_charlit[char_ct].clit_cname, tfield1a);	
      				strcpy(w_charlit[char_ct].clit_value, tfield1); 
				w_charlit[char_ct].clit_lgth = x3; 
				w_charlit[char_ct].clit_uct = 1;	             
				char_ct++;

				convert = 1;
			}

	}

void c2_pass2_if_13()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_case_13");
        trace_rec_1();
     }

     char ch;
     char *p;
     char *p1;
     char *p3;
     char *p4;
     char *p5;
     char *p6;

     char field1[VAR_LGTH];
     char field1a[VAR_LGTH];
     char field2[VAR_LGTH];
     char field3[VAR_LGTH];
     char field3a[VAR_LGTH];
     char field4[VAR_LGTH];
     char field4a[VAR_LGTH];
     char field4w[VAR_LGTH];
     char field5[VAR_LGTH];
     char field6[VAR_LGTH];
     char field6a[VAR_LGTH];
     char field10[VAR_LGTH];
     char field11[VAR_LGTH];
     char tfield3b[VAR_LGTH];
     char tfield21[VAR_LGTH];

      int fd3_type = 0;
      int fd6_type = 0;
      int fd10_type = 0;
      int fd11_type = 0;
      int pi;
      int pi2;
      int I = 0;
      int x2 = 0;
      int x3 = 0;
      int x4 = 0;
      int x80 = 0;
      int x99 = 0;
      int s = 0;
      int s1 = 0;
      int size = 0;
      int rct1 = 0;
      int spec_char = 0;
      int spec_char_2 = 0;
      int fd1_var = 0;
      int fd3_var = 0;
      int fd4_var = 0;
      int fd6_var = 0;
      int ret = 0;
      int ret1 = 0;
      int complex_if = 0;
      int operand_1 = 0;
      int operand_2 = 0;

      p4 = strstr(p_string, "&&");
      if(p4)
         complex_if = 1;

      p4 = strstr(p_string, "||");
      if(p4)
         complex_if = 2;

     if((complex_if == 1) || (complex_if == 2))
     {
        if(trace_flag == 1)
        {
           strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_13 complex");
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
        ch = p_string[pi];
        while(ch != '(')
        {
           pi++;
           ch = p_string[pi];
        }

        pi2 = 0;
        pi++;
        ch = p_string[pi];
        while(ch != ' ')
        {
           if(ch == ')')
           {
              pi++;
              break;
           }
           field1[pi2] = ch;
           pi2++;
           pi++;
           ch = p_string[pi];
        }
        field1[pi2] = '\0';

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
           field2[pi2] = ch;
           pi2++;
           pi++;
           ch = p_string[pi];
        }
        field2[pi2] = '\0';

        ch = p_string[pi];
        while(ch == ' ')
        {
           pi++;
           ch = p_string[pi];
        }

        x2 = 0;
        pi2 = 0;
        ch = p_string[pi];
        while(ch != ')')
        {
           if(ch == '(')
           {
              goto ZL99;
           }
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
           field3[pi2] = ch;
           pi2++;
ZL99:
           pi++;
           ch = p_string[pi];
        }
        field3[pi2] = '\0';

        p3 = strstr(field2, "&&");
        if(p3)
        {
printf("c2z_pass_2_if_13 field1 = %s\n",field1);
printf("c2z_pass_2_if_13 field2 = %s\n",field2);
printf("c2z_pass_2_if_13 field3 = %s\n",field3);





           convert = 1;
           return;
        }




				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						field4[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field4[pi2] = '\0';

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
						field5[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field5[pi2] = '\0';

				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				x2 = 0;
				pi2 = 0;
				ch = p_string[pi];
				while(ch != ')')
					{
						if(x2 == 0)
							{
								if (isalpha(ch))	
									{
										fd6_type = 1;
										x2 = 1;
									}
 
								if (isdigit(ch)) 	
									{
										fd6_type = 2;
										x2 = 1;
									}
							}
						if(ch != '\\')
						 	{
								field6[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				field6[pi2] = '\0';

				operand_1 = 0;
				if(operand_1 == 0)
					{
						p = strstr(field2, "==");
						if(p)
							operand_1 = 1;
					}

				if(operand_1 == 0)
					{
						p = strstr(field2, "!=");
						if(p)
							operand_1 = 2;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(field2, "<=");
						if(p)
							operand_1 = 3;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(field2, ">=");
						if(p)
							operand_1 = 4;
					}

				if(operand_1 == 0)
					{
						p = strstr(field2, "=");
						if(p)
							operand_1 = 5;
					}

				if(operand_1 == 0)
					{
						p = strstr(field2, "<");
						if(p)
							operand_1 = 6;
					}

				if(operand_1 == 0)
					{
						p = strstr(field2, ">");
						if(p)
							operand_1 = 7;
					}
		
				operand_2 = 0;
				if(operand_2 == 0)
					{
						p = strstr(field5, "==");
						if(p)
							operand_2 = 1;
					}

				if(operand_2 == 0)
					{
						p = strstr(field5, "!=");
						if(p)
							operand_2 = 2;
					}
				
				if(operand_2 == 0)
					{
						p = strstr(field5, "<=");
						if(p)
							operand_2 = 3;
					}
				
				if(operand_2 == 0)
					{
						p = strstr(field5, ">=");
						if(p)
							operand_2 = 4;
					}

				if(operand_2 == 0)
					{
						p = strstr(field5, "=");
						if(p)
							operand_2 = 5;
					}

				if(operand_2 == 0)
					{
						p = strstr(field5, "<");
						if(p)
							operand_2 = 6;
					}

				if(operand_2 == 0)
					{
						p = strstr(field5, ">");
						if(p)
							operand_2 = 7;
					}

				x80 = 0;
				p5 = strstr(field1, "[");
				if(p5)
					x80 = 1;

				if(x80 == 0)
					{

						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(field1, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0)) 
									{
										x3 = 1;
										strcpy(field1a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
										ret1 = strcmp("I",lw_variable[I].lv_type);
										if(ret1 == 0)
											{
												fd1_var = 1;
											}
										ret1 = strcmp("C",lw_variable[I].lv_type);
										if(ret1 == 0)
											{
												fd1_var = 2;
											}
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
												gw_variable[I].gv_use_ct++;
												ret1 = strcmp("I",gw_variable[I].gv_type);
												if(ret1 == 0)
													{
														fd1_var = 1;
													}
												ret1 = strcmp("C",gw_variable[I].gv_type);
												if(ret1 == 0)
													{
														fd1_var = 2;
													}
												ret1 = strcmp("G",gw_variable[I].gv_type);
												if(ret1 == 0)
													{
														fd1_var = 3;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_pass_2.c c2_pass2_if_13 E-143 field1 Not Found = %s\n",field1); 
								c2_error();
							}
					}

				if(x80 == 1)
					{
						x2 = 0;
						pi2 = 0;
						pi = 0;
						ch = field1[pi];
						while(ch != '[')
							{
								if(x2 == 0)
									{
										if (isalpha(ch))	
											{
												fd10_type = 1;
												x2 = 1;
											} 

										if (isdigit(ch)) 	
											{
												fd10_type = 2;
												x2 = 1;
											}
									}
								field10[pi2] = ch;
								pi2++;
								pi++;
								ch = field1[pi];
							}
						field10[pi2] = '\0';

						x2 = 0;
						pi2 = 0;
						pi++;
						ch = field1[pi];
						while(ch != ']')
							{
								if(x2 == 0)
									{
										if (isalpha(ch))	
											{
												fd11_type = 1;
												x2 = 1;
											} 

										if (isdigit(ch)) 	
											{
												fd11_type = 2;
												x2 = 1;
											}
									}
								field11[pi2] = ch;
								pi2++;
								pi++;
								ch = field1[pi];
							}
						field11[pi2] = '\0';

						if(fd10_type == 2)
							{
								printf("c2z_pass_2.c c2_pass2_if_13 E-151 Literal Not coded = %s\n",field10);
								c2_error();
							}
						if(fd11_type == 2)
							{
								printf("c2z_pass_2.c c2_pass2_if_13 E-152 Literal Not coded = %s\n",field11);
								c2_error();
							}
					}

				spec_char = 0;
				p6 = strstr(field3, "'"); 
				if(p6)
					{
						spec_char = 1;
					}

				if((fd3_type == 2) && (spec_char == 0))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(field1a, c_wkname);

						s = strlen(field3);
						x99 = 0;
						p1 = strstr(field3,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, field3);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												field3[pi2] = ch;
												pi2++;
											}
									}
								field3[pi2] = '\0';
							}

						if(x99 == 0)
							{
								strcpy(field3a, field3);
							}
						else
							{
								strcpy(field3a,"-");
								strcat(field3a, field3);
							}

						rct1 = rct;
						strcpy(tfield21, field1a);
						for(I=0; I < lit_ct; I++)
							{
								ret = strcmp(w_literal[I].lit_value, field3a);
								if(ret == 0)
									{
										rct1 = w_literal[I].lit_rct;
										strcpy(tfield21, w_literal[I].lit_cname);
										break;
									}
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
                                          strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, field1a);	
      						strcpy(w_literal[lit_ct].lit_value, field3a); 
						strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 
						w_literal[lit_ct].lit_uct = 1;
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      	             
						lit_ct++;

						return;
					}

				if((fd3_type == 1) && (spec_char == 0))
					{
						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(field3, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0)) 
									{
										x3 = 1;
										strcpy(field3a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
										ret1 = strcmp("I",lw_variable[I].lv_type);
										if(ret1 == 0)
											{
												fd3_var = 1;
											}
										else
											{
												fd3_var = 2;
											}
									}
							}
			
						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(field3, gw_variable[I].gv_name);
										if(ret == 0) 
											{
												x3 = 1;
												strcpy(field3a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												ret1 = strcmp("I",gw_variable[I].gv_type);
												if(ret1 == 0)
													{
														fd3_var = 1;
													}
												else
													{
														fd3_var = 2;
													}
											}
									}
							}
						
						if(x3 == 0)
							{
								printf("c2z_pass_2.c c2_pass2_if_13 E-146 field3 Not Found = %s\n",field3);
								c2_error(); 
							}
					}

				p3 = strchr(p_string, '[');
                            if(!p3) 
					{
						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(field4, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0)) 
									{
										x3 = 1;
										strcpy(field4a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
										ret1 = strcmp("I",lw_variable[I].lv_type);
										if(ret1 == 0)
											{
												fd4_var = 1;
											}
										else
											{
												fd4_var = 2;
											}
									}
							}
			
						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(field4, gw_variable[I].gv_name);
										if(ret == 0) 
											{
												x3 = 1;
												strcpy(field4a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												ret1 = strcmp("I",gw_variable[I].gv_type);
												if(ret1 == 0)
													{
														fd4_var = 1;
													}
												else
													{
														fd4_var = 2;
													}
											}
									}
							}
					}
				else
					{
						strcpy(field4w, field1);

						pi2 = 0;
						x4++;
						ch = field4[x4];
						while(ch != ']')
							{
								x4++;
								ch = field4[x4];
							}
												
						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(field4w, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0)) 
									{
										x3 = 1;
										strcpy(field4a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
										ret1 = strcmp("I",lw_variable[I].lv_type);
										if(ret1 == 0)
											{
												fd4_var = 1;
											}
										else
											{
												fd4_var = 2;
											}
									}
							}
			
						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(field4w, gw_variable[I].gv_name);
										if(ret == 0) 
											{
												x3 = 1;
												strcpy(field4a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												ret1 = strcmp("I",gw_variable[I].gv_type);
												if(ret1 == 0)
													{
														fd4_var = 1;
													}
												else
													{
														fd4_var = 2;
													}
											}
									}
							}
						
						if(x3 == 0)
							{
								for(I=0; I < fn_ct; I++)
									{
										ret = strcmp(field1, w_function[I].fn_name);
										if(ret == 0)
											{
												x3 = 1;
												strcpy(field1a, w_function[I].fn_cname);
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_pass_2.c pass2_if_case_13 E-147 field4w Not Found = %s\n",field4w);
						c2_error();
					}

				spec_char_2 = 0;
				p6 = strstr(field6, "'"); 
				if(p6)
					{
						spec_char_2 = 1;
					}

				if(fd6_type == 2)
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						
						s = strlen(field6);
						x99 = 0;
						p1 = strstr(field6,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, field6);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												field6[pi2] = ch;
												pi2++;
											}
									}
								field6[pi2] = '\0';
							}

						if(x99 == 0)
							{	
								strcpy(field6a, field6);
							}
						else
							{
								strcpy(field6a,"-");
								strcat(field6a, field6);
							}

						rct1 = rct;
						strcpy(tfield21, c_wkname);
						for(I=0; I < lit_ct; I++)
							{
								ret = strcmp(w_literal[I].lit_value, field6a);
								if(ret == 0)
									{
										rct1 = w_literal[I].lit_rct;
										strcpy(tfield21, w_literal[I].lit_cname);
										break;
									}
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
                                          strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, c_wkname);	
      						strcpy(w_literal[lit_ct].lit_value, field6a);
						strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 
						w_literal[lit_ct].lit_uct = 1; 
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      	             
						lit_ct++;

						convert = 1;
						return;
					}

				if((spec_char_2 == 0) && (fd6_type == 1))
					{
						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(field6, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0)) 
									{
										x3 = 1;
										strcpy(field6a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
										ret1 = strcmp("I",lw_variable[I].lv_type);
										if(ret1 == 0)
											{
												fd6_var = 1;
											}
										else
											{
												fd6_var = 2;
											}
									}
							}
			
						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(field6, gw_variable[I].gv_name);
										if(ret == 0)
											{
												x3 = 1;
												strcpy(field6a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												ret1 = strcmp("I",gw_variable[I].gv_type);
												if(ret1 == 0)
													{
														fd6_var = 1;
													}
												else
													{
														fd6_var = 2;
													}
											}							
									}
							}

						if(x3 == 0)
							{
								printf("c2z_pass_2.c c2_pass2_if_case_13 E-150 field6 Not Found = %s\n",field6); 
								c2_error();
							}
					}

				if((fd1_var == 2) && (fd3_var == 0))
					{
						if(spec_char == 1)
							{
								x3 = strlen(field3);
								c_name++;
								snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
								strcpy(c_wkname, "C37F");
								strcat(c_wkname, wk_strg);
								s = strlen(c_wkname);
								c_wkname[s] = '\0';
								strcpy(field1a, c_wkname);
				
								s = strlen(field3);
								pi2 = 0;
								for(I=0; I < s; I++)
									{
										ch = field3[I];
										if(ch != '\'')
											{
												field3a[pi2] = ch;
												pi2++;
											}

									}
								field3a[pi2] = '\0';

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
								strcpy(w_charlit[char_ct].clit_cname, field1a);	
      								strcpy(w_charlit[char_ct].clit_value, field3a); 
								w_charlit[char_ct].clit_type = 3;
								w_charlit[char_ct].clit_lgth = x3; 
								w_charlit[char_ct].clit_uct = 1;	             
								char_ct++;
							}

						if(spec_char == 0)
							{
								x3 = strlen(field3);
								c_name++;
								snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
								strcpy(c_wkname, "C37F");
								strcat(c_wkname, wk_strg);
								s = strlen(c_wkname);
								c_wkname[s] = '\0';
								strcpy(field1a, c_wkname);

								s = strlen(field3);
								pi2 = 0;
								for(I=0; I < s; I++)
									{
										ch = field3[I];
										if(ch != '\'')
											{
												field3a[pi2] = ch;
												pi2++;
											}
									}
								field3a[pi2] = '\0';
					
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
								w_charlit[char_ct].clit_type = 3;
								strcpy(w_charlit[char_ct].clit_cname, field1a);	
      								strcpy(w_charlit[char_ct].clit_value, field3a); 
								w_charlit[char_ct].clit_lgth = x3;
								w_charlit[char_ct].clit_uct = 1; 	             
								char_ct++;
							}
					}
				
				if((fd4_var == 2) && (fd6_var == 2))
					{
						if(spec_char == 0)
							{
								strcpy(a_string, "         CLC   ");
								strcat(a_string, field4a);
								strcat(a_string, ",");
								strcat(a_string, field6a);
								src_line();
								if(punch_code == 1)
									trace_rec_3();
							}

						if(spec_char == 1)
							{
								strcpy(a_string, "         CLI   ");
								strcat(a_string, field4a);
								strcat(a_string, ",C");
								strcat(a_string, field6);
								src_line();
								if(punch_code == 1)
									trace_rec_3();
							}
					}
					
				if((fd4_var == 2) && (fd6_var == 0))
					{
						if(spec_char == 1)
							{
								x3 = strlen(field6);
								c_name++;
								snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
								strcpy(c_wkname, "C37F");
								strcat(c_wkname, wk_strg);
								s = strlen(c_wkname);
								c_wkname[s] = '\0';
								strcpy(field4a, c_wkname);

								s = strlen(field6);
								pi2 = 0;
								for(I=0; I < s; I++)
									{
										ch = field6[I];
										if(ch != '\'')
											{
												field6a[pi2] = ch;
												pi2++;
											}
									}
								field6a[pi2] = '\0';
				
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
  								w_charlit[char_ct].clit_type = 3;
								strcpy(w_charlit[char_ct].clit_cname, field4a);	
      								strcpy(w_charlit[char_ct].clit_value, field6a); 
								w_charlit[char_ct].clit_lgth = x3; 
								w_charlit[char_ct].clit_uct = 2;	             
								char_ct++;
							}
					}
			}

		convert = 1;
		if_convert = 1;

	}

void c2_pass2_whl()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_whl");
        trace_rec_1();
     }

		char ch;
		char *p;
		char tfield1[VAR_LGTH];

		int pi;
		int pi2;
		int I = 0;
		int s = 0;
		int x3 = 0;
		int ret = 0;
		int while_isupper = 0;
		int while_not_equal = 0;
		int while_feof = 0;
		int while_isdigit = 0;
		int while_math = 0;
		int while_test = 0;
				
		while_convert = 0;				
		while_opr = 0;
		
		while_parser_code = 0;
		inside_while = 1;

		s = strlen(p_string);
		for(I = 0; I < s; I++)
			{
				ch = p_string[I];
				p = strstr(p_string,"&&");
				if((p) && (while_test == 0))
					{
						/* while_complex = 1; */
					}

				p = strstr(p_string, "strcmp");
				if((p) && (while_test == 0))
					{
						while_opr = 13;
						while_test = 1;
					}

				p = strstr(p_string, "isalnum");
				if((p) && (while_test == 0))
					{
						while_opr = 12;
						while_test = 1;
					}

				p = strstr(p_string, "isspace");
				if((p) && (while_test == 0))
					{
						while_opr = 11;
						while_test = 1;
					}

				p = strstr(p_string, "isupper");
				if((p) && (while_test == 0))
					{
						while_isupper = 1;
						while_test = 1;
					}
				
				p = strstr(p_string, "isalpha");
				if((p) && (while_test == 0))
					{
						while_opr = 8;
						while_test = 1;
					}

				p = strstr(p_string, "feof");
				if((p) && (while_test == 0))
					{
						while_feof = 1;
						while_opr = 9;
						while_test = 1;
					}

				p = strstr(p_string, "isdigit");
				if((p) && (while_test == 0))
					{
						while_isdigit = 1;
						while_opr = 7;
						while_test = 1;
					}

                            p = strstr(p_string, "fgets");
				if((p) && (while_test == 0))
					{
						while_opr = 50;
						while_test = 1;
					}

				p = strstr(p_string, "==");
				if((p) && (while_test == 0))
					{
						while_opr = 99;
						while_test = 1;
					}

				p = strstr(p_string, "!=");
				if((p) && (while_test == 0))
					{
						while_not_equal = 1;
						while_test = 1;
					}

				p = strstr(p_string, "<=");
				if((p) && (while_test == 0))
					{
						while_opr = 6;
						while_test = 1;
					}
		
				p = strstr(p_string, ">=");
				if((p) && (while_test == 0))
					{
						while_opr = 5;
						while_test = 1;
					}
				
				p = strstr(p_string, "<");
				if((p) && (while_test == 0))
					{
						while_math = 4;
						while_test = 1;
					}
			
				p = strstr(p_string, "<");
				if((p) && (while_test == 0))
					{
						while_opr = 4;
						while_test = 1;
					}
			
				p = strstr(p_string, ">");
				if((p) && (while_test == 0))
					{
						while_opr = 3;
						while_test = 1;
					}
			}
 
             if(while_test == 0)
             {
                convert = 0;
                return;
    	      }

             if((while_opr == 50) && (while_convert == 0))			/* fgets			*/
			{
				c2_pass2_fgets(); 
				return;
			}
		

		if((while_isupper == 1) && (while_convert == 0))			/* isupper			*/
			{
				/* c2_while_10(); */
				return;
			}

		 if((while_not_equal == 1) && (while_convert == 0))		/* while((ch != '\"') 	*/
			{
				c2_pass2_whl_2();
				return;
			}

		if((while_opr == 99) && (while_convert == 0))			/* while(ch == 1		*/
			{
				c2_pass2_whl_1();
				return;
			} 

		if((while_feof == 1)  && (while_convert == 0))			/* feof 			*/
			{
				/* c2_while_9(); */
				return;
			}	

		if((while_isdigit == 1)  &&  (while_convert == 0))		/* isdigit			*/
			{
				c2_pass2_whl_7();
				return;
			}	

		if((while_math == 4)  && (while_convert == 0))			/* <	 			*/
			{
				/* c2_whl_4(); */
				return;
			}

		if((while_opr == 5)  && (while_convert == 0))			/* >=	 			*/
			{
				c2_pass2_whl_5(); 
				return;
			}

		if((while_opr == 8) && (while_convert == 0))			/* isalpha			*/
			{
				/* c2_whl_8(); */
				return;
			}

		if((while_opr == 11) && (while_convert == 0))			/* isspace			*/
			{
				/* c2_whl_11(); */
				return;
			}

		if((while_opr == 12) && (while_convert == 0))			/* isalnum			*/
			{
				/* c2_whl_12(); */
				return;
			}

		if((while_opr == 13) && (while_convert == 0))			/* STRCMP			*/
			{
				c2_pass2_whl_13(); 
				return;
			}

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
		while(ch != '(')
			{
				tfield1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield1[pi2] = '\0';

		x3 = 0;
		for(I=0; I < fn_ct; I++)
			{
				ret = strcmp(tfield1, w_function[I].fn_name);
				if(ret == 0)
					{
						x3 = 1;
					}
			}

		if(x3 == 1)
			{
					/* c2_while_14(); */
					return;
			}

		if(while_convert == 0)
			{
					/* c2_while_15(); */
					return;
			}
	}


void c2_pass2_whl_1()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_whl_1");
				trace_rec_1();
			}

		int fd3_type = 0;
		int pi;
		int pi2;
		int x2 = 0;
		int x99 = 0;
		int s = 0;
		int s1 = 0;
		int size = 0;
		int rct1 = 0;
		int I = 0;
		int ret = 0;
		
		char ch, *p1;
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield3b[VAR_LGTH];
		char tfield21[VAR_LGTH];

		pi = 0;
		ch = p_string[pi];
		while(ch != '(') 
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

		ch = p_string[pi];
		while(ch != ' ')
			{
				
				pi++;
				ch = p_string[pi];
			}
		
		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		x2 = 0;
		pi2 = 0;
		ch = p_string[pi];
		while(ch != ')')
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
				pi++;
				ch = p_string[pi];
			}
		tfield3[pi2] = '\0';

		if(fd3_type == 1)
			{
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield2a, c_wkname);
						
				s = strlen(tfield3);
				x99 = 0;
				p1 = strstr(tfield3,"-");
				if(p1)
					{
						x99 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, tfield3);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										tfield3[pi2] = ch;
										pi2++;
									}
							}
						tfield3[pi2] = '\0';
					}

				if(x99 == 0)
					{	
						strcpy(tfield3a, tfield3);
					}
				else
					{
						strcpy(tfield3a,"-");
						strcat(tfield3a, tfield3);
					}

				rct1 = rct;
				strcpy(tfield21, tfield2a);
				for(I=0; I < lit_ct; I++)
					{
						ret = strcmp(w_literal[I].lit_value, tfield3a);
						if(ret == 0)
							{
								rct1 = w_literal[I].lit_rct;
								strcpy(tfield21, w_literal[I].lit_cname);
								break;
							}
					}

				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
                          	strcpy(w_literal[lit_ct].lit_name, null_field);
				strcpy(w_literal[lit_ct].lit_cname, tfield2a);	
      				strcpy(w_literal[lit_ct].lit_value, tfield3a);  
				strcpy(w_literal[lit_ct].lit_use_cname, tfield21);
				w_literal[lit_ct].lit_uct = 1;
				w_literal[lit_ct].lit_dec = 0;
				w_literal[lit_ct].lit_type = 1;	      	             
				lit_ct++;

			}
		while_convert = 1;
		convert = 1;
	}

void c2_pass2_whl_2()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_whl_2");
				trace_rec_1();
			}

		char *p, *p1;
		char ch;

		char tfield1[VAR_LGTH];
 		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
	 	char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield3b[VAR_LGTH];
		char tfield4a[VAR_LGTH];
		char tfield5[VAR_LGTH];
		char tfield5a[VAR_LGTH];
		char tfield7[VAR_LGTH];
		char tfield7a[VAR_LGTH];
		char tfield21[VAR_LGTH];
		char tfield10[VAR_LGTH]; 

		int pi;
		int pi2;
		int I = 0;
		int s;
		int s1 = 0;
		int s9 = 0;
		int size;
		int x2 = 0;
		int x99 = 0;
		int wh_3 = 0;
		int wh_4 = 0;
		int wh_5 = 0;
		int wh_8 = 0;
		int wh_9 = 0;
		int rct1 = 0;
		int x5 = 0;
		int v = 0;
		int ret = 0;
		int ret1 = 0;
		int operand_1 = 0;
		int var_ci_1 = 0;
		int var_ci_3 = 0;
		int whfd3_type = 0;
		int whfd5_type = 0;
		int cd3_type = 0;
		int fd3_type = 0;
		int fd7_type = 0;
		int while_complex = 0;

		p = strstr(p_string,"&&");
		if(p)
			{
				while_complex = 1;
			}

		p = strstr(p_string, "||");
		if(p)
			{		
				while_complex = 1;
			}

		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '&')
					{
						x5++;
					}
			}

		if(while_complex == 0)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_pass2_whl_2 simple");
						trace_rec_1();
					}

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
				while(ch != ' ')
					{
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				wh_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield1, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(tfield1a, lw_variable[v].lv_cname);
										lw_variable[I].lv_use_ct++;
										wh_5 = strcmp("I",lw_variable[v].lv_type);
										if(wh_5 == 0)
											{
												var_ci_1 = 1;
											}
										wh_5 = strcmp("C",lw_variable[v].lv_type);
										if(wh_5 == 0)
											{
												var_ci_1 = 2;
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										wh_4 = strcmp(tfield1, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(tfield1a, gw_variable[v].gv_cname);
												gw_variable[I].gv_use_ct++;
												wh_5 = strcmp("I",gw_variable[v].gv_type);
												if(wh_5 == 0)
													{
														var_ci_1 = 1;
													}
												wh_5 = strcmp("C",gw_variable[v].gv_type);
												if(wh_5 == 0)
													{
														var_ci_1 = 2;
													}
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_pass_2.c while_case_2 E-249 complex = 0 tfield1 Not Found = %s\n",tfield1);
						c2_error();
					}

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				x2 = 0;
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ')')
					{
						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										whfd3_type = 1;
										cd3_type = 1;
										x2 = 1;
									} 

								if (isalpha(ch))	
									{
										whfd3_type = 2;
										cd3_type = 2;
										x2 = 1;
									}
							}
						if(ch != '\\')
							{
								tfield3[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield3[pi2] = '\0';

				p = strstr(tfield3,"\'");
				if(p)
					{
						pi2 = 0;
						pi = 1;
						ch = tfield3[pi];
						while(ch != '\'')
							{
                                                        if(ch != '\\')
									{
										tfield3a[pi2] = ch;
										pi2++;
									}
								pi++;
								ch = tfield3[pi];
							}
						tfield3a[pi2] = '\0';
	
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield4a, c_wkname);
		
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
  						w_charlit[char_ct].clit_type = 3;
						strcpy(w_charlit[char_ct].clit_cname, tfield4a);	
      						strcpy(w_charlit[char_ct].clit_value, tfield3a); 
						w_charlit[char_ct].clit_lgth = 1; 
						w_charlit[char_ct].clit_uct = 1;	             
						char_ct++;
	
						return;
					}
				
				if(cd3_type == 1)
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield2a, c_wkname);
						
						s = strlen(tfield3);
						x99 = 0;
						p1 = strstr(tfield3,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, tfield3);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												tfield3[pi2] = ch;
												pi2++;
											}
									}
								tfield3[pi2] = '\0';
							}

						if(x99 == 0)
							{	
								strcpy(tfield3a, tfield3);
							}
						else
							{
								strcpy(tfield3a,"-");
								strcat(tfield3a, tfield3);
							}

						rct1 = rct;
						strcpy(tfield21, tfield2a);
						for(I=0; I < lit_ct; I++)
							{
								ret = strcmp(w_literal[I].lit_value, tfield3a);
								if(ret == 0)
									{
										rct1 = w_literal[I].lit_rct;
										strcpy(tfield21, w_literal[I].lit_cname);
										break;
									}
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
                                          strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, tfield2a);	
      						strcpy(w_literal[lit_ct].lit_value, tfield3a); 
						strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 
						w_literal[lit_ct].lit_uct = 1;
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      	             
						lit_ct++;
					
						return;
					}

				if(whfd3_type == 1)
					var_ci_3 = 3;
				
				wh_8 = 0;
				p = strstr(tfield3,"\"");
				if(p)
					wh_8 = 1;

				p = strstr(tfield3,"'\0'");
				if(p)
					wh_9 = 1;

				wh_3 = 0;
				if((wh_8 != 1) && (lv_ct > 0) && (whfd3_type != 1))
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield3, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(tfield3a, lw_variable[v].lv_cname);
										lw_variable[I].lv_use_ct++;
										wh_5 = strcmp("I",lw_variable[v].lv_type);
										if(wh_5 == 0)
											{
												var_ci_3 = 1;
											}
										wh_5 = strcmp("C",lw_variable[v].lv_type);
										if(wh_5 == 0)
											{
												var_ci_3 = 2;
											}
									}
							}
					}

				if((wh_3 == 0) && (wh_8 != 1) && (whfd3_type != 1))
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										wh_4 = strcmp(tfield3, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(tfield3a, gw_variable[v].gv_cname);
												gw_variable[I].gv_use_ct++;
												wh_5 = strcmp("I",gw_variable[v].gv_type);
												if(wh_5 == 0)
													{
														var_ci_3 = 1;
													}
												wh_5 = strcmp("C",gw_variable[v].gv_type);
												if(wh_5 == 0)
													{
														var_ci_3 = 2;
													}
											}
									}
							}
					}

				if((wh_3 == 0) && (wh_8 != 1) && (whfd3_type != 1))
					{
						printf("c2z_pass_2.c while_case_2 E-247 complex = 0 tfield3 Not Found = %s\n",tfield3);
						c2_error();
					}

				operand_1 = 0;
				if(operand_1 == 0)
					{
						p = strstr(tfield2, "==");
						if(p)
							operand_1 = 1;
					}

				if(operand_1 == 0)
					{
						p = strstr(tfield2, "!=");
						if(p)
							operand_1 = 2;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(tfield2, "<=");
						if(p)
							operand_1 = 3;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(tfield2, ">=");
						if(p)
							operand_1 = 4;
					}

				if(operand_1 == 0)
					{
						p = strstr(tfield2, "=");
						if(p)
							operand_1 = 5;
					}

				if(operand_1 == 0)
					{
						p = strstr(tfield2, "<");
						if(p)
							operand_1 = 6;
					}

				if(operand_1 == 0)
					{
						p = strstr(tfield2, ">");
						if(p)
							operand_1 = 7;
					}
									
				if(wh_8 == 1)		/*  quote in compare	*/
					{
						
					}

				if(wh_9 == 1)		/* end of line `	*/
					{
											
					}

				if((var_ci_1 == 2) && (var_ci_3 == 2))		
					{
						return;
					}

				if((var_ci_1 == 1) && (var_ci_3 == 3))
					{
						if(whfd3_type == 1)
							{
								c_name++;
								snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
								strcpy(c_wkname, "C37F");
								strcat(c_wkname, wk_strg);
								s = strlen(c_wkname);
								c_wkname[s] = '\0';
								strcpy(tfield2a, c_wkname);
						
								s = strlen(tfield3);
								x99 = 0;
								p1 = strstr(tfield3,"-");
								if(p1)
									{
										x99 = 1;
									}

								s1 = s + 1;
								if(x99 == 1)
									{
										strcpy(tfield3b, tfield3);
										pi2 = 0;
										for(I=0; I < s1; I++)
											{
												ch = tfield3b[I];
												if(ch != '-')
													{
														tfield3[pi2] = ch;
														pi2++;
													}		
											}
										tfield3[pi2] = '\0';
									}

								if(x99 == 0)
									{
										strcpy(tfield3a, tfield3);
									}
								else
									{
										strcpy(tfield3a,"-");
										strcat(tfield3a, tfield3);
									}

								rct1 = rct;
								strcpy(tfield21, tfield2a);
								for(I=0; I < lit_ct; I++)
									{
										ret = strcmp(w_literal[I].lit_value, tfield3a);
										if(ret == 0)
											{
												rct1 = w_literal[I].lit_rct;
												strcpy(tfield21, w_literal[I].lit_cname);
												break;
											}

									}

								if(lit_ct == 0)
									{
										size = 1;
										w_literal = malloc(size * sizeof(struct literal));
									}
								else
									{
										size = lit_ct + 1;
										w_literal = realloc(w_literal, size * sizeof(struct literal));
									}

								w_literal[lit_ct].lit_rct = rct;
								w_literal[lit_ct].lit_use_rct = rct1;
                                          		strcpy(w_literal[lit_ct].lit_name, null_field);
								strcpy(w_literal[lit_ct].lit_cname, tfield2a);	
      								strcpy(w_literal[lit_ct].lit_value, tfield3a); 
								strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 
								w_literal[lit_ct].lit_uct = 1;	
								w_literal[lit_ct].lit_dec = 0;  
								w_literal[lit_ct].lit_type = 1;	                 
								lit_ct++;
							}
						else
							{
								printf("c2z_pass_2.c c2_while_2 R-348 complex = 0 ci_1 = 1 & ci_3 = 1 NOT CODED\n");
								c2_error();
							}
					}
			}

		if((while_complex == 1) && (x5 != 4))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_pass2_whl_2 == 1");
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
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}
			
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				while(ch != ' ')
					{
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				c2_white();
			
				x2 = 0;
				pi2 = 0;
				while(ch != ')')
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
								if(ch != '\\')
									{
										tfield3[pi2] = ch;
										pi2++;
									}
							}
						pi++;
						ch = p_string[pi];
					}
				tfield3[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				c2_white();

				while(ch != ' ')
					{
						pi++;
						ch = p_string[pi];
					}
				
				pi++;
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}

				x2 = 0;
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										whfd5_type = 1;
										x2 = 1;
									}
 
								if (isalpha(ch))	
									{
										whfd5_type = 2;
										x2 = 1;
									}
							}
						tfield5[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield5[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				c2_white();
				
				while(ch != ' ')
					{
						pi++;
						ch = p_string[pi];
					}
				
				pi++;
				ch = p_string[pi];
				c2_white();
				
				x2 = 0;
				pi2 = 0;
				while(ch != ')')
					{
						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										fd7_type = 1;
										x2 = 1;
									}
 
								if (isalpha(ch))	
									{
										fd7_type = 2;
										x2 = 1;
									}
							}
						tfield7[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield7[pi2] = '\0';
				
				wh_3 = 0;
				wh_5 = 0;
				var_ci_1 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield1, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(tfield1a, lw_variable[v].lv_cname);
										lw_variable[v].lv_use_ct++;
										wh_5 = strcmp("I",lw_variable[v].lv_type);
										if(wh_5 == 0)
											{
												var_ci_1 = 1;
											}
										wh_5 = strcmp("C",lw_variable[v].lv_type);
										if(wh_5 == 0)
											{
												var_ci_1 = 2;
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										wh_4 = strcmp(tfield1, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(tfield1a, gw_variable[v].gv_cname);
												wh_5 = strcmp("I",gw_variable[v].gv_type);
												if(wh_5 == 0)
													{
														var_ci_1 = 1;
													}
												wh_5 = strcmp("C",gw_variable[v].gv_type);
												if(wh_5 == 0)
													{
														var_ci_1 = 2;
													}
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_pass_2.c while_case_2 == 1 E-249 x5 != 4 tfield1 Not Found = %s\n",tfield1);
						c2_error();
					}

				if(fd3_type == 2)
					{
						wh_3 = 0;
						if(lv_ct > 0)
							{
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(tfield3, lw_variable[v].lv_name);
										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if((ret == 0) && (ret1 == 0))
											{				
												wh_3 = 1;
												strcpy(tfield3a, lw_variable[v].lv_cname);
												lw_variable[v].lv_use_ct++;
												wh_5 = strcmp("I",lw_variable[v].lv_type);
												if(wh_5 == 0)
													{
														var_ci_3 = 1;
													}
												wh_5 = strcmp("C",lw_variable[v].lv_type);
												if(wh_5 == 0)
													{
														var_ci_3 = 2;
													}
											}
									}
							}

						if(wh_3 == 0)
							{
								if(gv_ct > 0)
									{
										for(v = 0; v < gv_ct; v++)
											{
												wh_4 = strcmp(tfield3, gw_variable[v].gv_name);
												if(wh_4 == 0)
													{				
														wh_3 = 1;
														strcpy(tfield3a, gw_variable[v].gv_cname);
														gw_variable[v].gv_use_ct++;
														wh_5 = strcmp("I",gw_variable[v].gv_type);
														if(wh_5 == 0)
															{
																var_ci_3 = 1;
															}
														wh_5 = strcmp("C",gw_variable[v].gv_type);
														if(wh_5 == 0)
															{
																var_ci_3 = 2;
															}
													}
											}
									}
							}

						if(wh_3 == 0)
							{
								printf("c2z_pass_2.c while_case_2 == 1 x5 E-250 != 4 tfield3 Not Found = %s\n",tfield3);
								c2_error();
							}
					}

				if(fd3_type == 0)
					{
						pi = 0;
						pi2 = 0;
						pi++;
						ch = tfield3[pi];
						while(ch != '\'')
							{
								tfield3a[pi2] = ch;
								pi2++;
								pi++;
								ch = tfield3[pi];
							}
						tfield3a[pi2] = '\0';

						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield3b, c_wkname);
		
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
  						w_charlit[char_ct].clit_type = 3;
						strcpy(w_charlit[char_ct].clit_cname, tfield3b);	
      						strcpy(w_charlit[char_ct].clit_value, tfield3a); 
						w_charlit[char_ct].clit_lgth = 1; 
						w_charlit[char_ct].clit_uct = 1;	             
						char_ct++;
					}

				if(fd3_type == 1)
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield2a, c_wkname);
						
						s9 = strlen(tfield3);
						x99 = 0;
						p1 = strstr(tfield3,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s9 + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, tfield3);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												tfield3[pi2] = ch;
												pi2++;
											}		
									}
								tfield3[pi2] = '\0';
							}

						if(x99 == 0)
							{
								strcpy(tfield3a, tfield3);
							}
						else
							{
								strcpy(tfield3a,"-");
								strcat(tfield3a, tfield3);
							}

						rct1 = rct;
						strcpy(tfield21, tfield2a);


						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
                                          strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, tfield2a);	
      						strcpy(w_literal[lit_ct].lit_value, tfield3a); 
						strcpy(w_literal[lit_ct].lit_use_cname, tfield21);
						w_literal[lit_ct].lit_uct = 1; 
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      	             
						lit_ct++;

					}

				if(whfd5_type == 2)
					{
						wh_3 = 0;
						if(lv_ct > 0)
							{
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(tfield5, lw_variable[v].lv_name);
										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if((ret == 0) && (ret1 == 0))
											{				
												wh_3 = 1;
												strcpy(tfield5a, lw_variable[v].lv_cname);
												lw_variable[v].lv_use_ct++;
											}
									}
							}

						if(wh_3 == 0)
							{
								if(gv_ct > 0)
									{
										for(v = 0; v < gv_ct; v++)
											{
												wh_4 = strcmp(tfield5, gw_variable[v].gv_name);
												if(wh_4 == 0)
													{				
														wh_3 = 1;
														strcpy(tfield5a, gw_variable[v].gv_cname);
														gw_variable[v].gv_use_ct++;
													}
											}
									}
							}

						if(wh_3 == 0)
							{
								printf("c2z_pass_2.c while_case_2 == 1 E- 251 tfield5 Not Found = %s\n",tfield3);
								c2_error();
							}
					}

				if(fd7_type == 2)
					{
						wh_3 = 0;
						if(lv_ct > 0)
							{
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(tfield7, lw_variable[v].lv_name);
										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if((ret == 0) && (ret1 == 0))
											{				
												wh_3 = 1;
												strcpy(tfield7a, lw_variable[v].lv_cname);
												lw_variable[v].lv_use_ct++;
											}
									}
							}

						if(wh_3 == 0)
							{
								if(gv_ct > 0)
									{
										for(v = 0; v < gv_ct; v++)
											{
												wh_4 = strcmp(tfield7, gw_variable[v].gv_name);
												if(wh_4 == 0)
													{				
														wh_3 = 1;
														strcpy(tfield7a, gw_variable[v].gv_cname);
														gw_variable[v].gv_use_ct++;
													}
											}
									}
							}

						if(wh_3 == 0)
							{
								printf("c2z_pass_2.c c2_while_2 E-252 x5 != 4 tfield7 Not Found = %s\n",tfield7);
								c2_error();
							}
					}

				if(fd7_type == 1)
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield2a, c_wkname);
						
						s9 = strlen(tfield7);
						x99 = 0;
						p1 = strstr(tfield7,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s9 + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, tfield7);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												tfield7[pi2] = ch;
												pi2++;
											}		
									}
								tfield7[pi2] = '\0';
							}

						if(x99 == 0)
							{
								strcpy(tfield7a, tfield7);
							}
						else
							{
								strcpy(tfield7a,"-");
								strcat(tfield7a, tfield7);
							}

						rct1 = rct;
						strcpy(tfield21, tfield5a);


						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
                                          strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, tfield2a);	
      						strcpy(w_literal[lit_ct].lit_value, tfield7a); 
						strcpy(w_literal[lit_ct].lit_use_cname, tfield21);
						w_literal[lit_ct].lit_uct = 2; 
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      	             
						lit_ct++;
					}

				while_convert = 1;
				convert = 1;
			}	

		if((while_complex == 1) && (x5 == 4))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2_pass2_whl_2 x5 = 4 complex = 2");
						trace_rec_1();
					}

				char ch;

				int fd3_type = 0;
				int fd7_type = 0;
				int fd10_type = 0;
				int pi;
				int pi2;

				pi = 0;
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}

				pi++;
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}
			
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				while(ch != ' ')
					{
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				c2_white();
			
				pi2 = 0;
				while(ch != ')')
					{
						if(ch != ' ')
							{
								if(x2 == 0)
									{
										if (isdigit(ch)) 	
											{
												fd3_type = 1;
											} 

										if (isalpha(ch))	
											{
												fd3_type = 2;
											}
									}
								tfield3[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield3[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				c2_white();

				while(ch != ' ')
					{
						pi++;
						ch = p_string[pi];
					}
				
				pi++;
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}

				x2 = 0;
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										whfd5_type = 1;
										x2 = 1;
									}
 
								if (isalpha(ch))	
									{
										whfd5_type = 2;
										x2 = 1;
									}
							}
						tfield5[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield5[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				c2_white();
				
				while(ch != ' ')
					{
						pi++;
						ch = p_string[pi];
					}
				
				pi++;
				ch = p_string[pi];
				c2_white();
				
				x2 = 0;
				pi2 = 0;
				while(ch != ')')
					{
						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										fd7_type = 1;
									} 

								if (isalpha(ch))	
									{
										fd7_type = 2;
									}
							}
						tfield7[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield7[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}

				x2 = 0;
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										x2 = 1;
									} 

								if (isalpha(ch))	
									{
										x2 = 2;
									}
							}
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				
				pi++;
				ch = p_string[pi];
				c2_white();
				
				pi2 = 0;
				while(ch != ' ')
					{
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				
				pi++;
				ch = p_string[pi];
				c2_white();
				
				x2 = 0;
				pi2 = 0;
				while(ch != ')')
					{
						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										fd10_type = 1;
									} 

								if (isalpha(ch))	
									{
										fd10_type = 2;
									}
							}
						tfield10[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield10[pi2] = '\0';

				if(fd3_type == 1)
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield2a, c_wkname);
						
						s = strlen(tfield3);
						x99 = 0;
						p1 = strstr(tfield3,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, tfield3);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												tfield3[pi2] = ch;
												pi2++;
											}		
									}
								tfield3[pi2] = '\0';
							}

						if(x99 == 0)
							{
								strcpy(tfield3a, tfield3);
							}
						else
							{
								strcpy(tfield3a,"-");
								strcat(tfield3a, tfield3);
							}
	
						rct1 = rct;
						strcpy(tfield21, tfield2a);
						for(I=0; I < lit_ct; I++)
							{
								ret = strcmp(w_literal[I].lit_value, tfield3a);
								if(ret == 0)
									{
										rct1 = w_literal[I].lit_rct;
										strcpy(tfield21, w_literal[I].lit_cname);
										break;
									}
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
                                          strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, tfield2a);	
      						strcpy(w_literal[lit_ct].lit_value, tfield3a); 
						strcpy(w_literal[lit_ct].lit_use_cname, tfield21);
						w_literal[lit_ct].lit_uct = 1; 
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      	             
						lit_ct++;
					}
				
				if(fd7_type == 1)
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield2a, c_wkname);
						strcpy(tfield3, tfield7);

						s = strlen(tfield3);
						x99 = 0;
						p1 = strstr(tfield3,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, tfield3);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												tfield3[pi2] = ch;
												pi2++;
											}		
									}
								tfield3[pi2] = '\0';
							}

						if(x99 == 0)
							{
								strcpy(tfield3a, tfield3);
							}
						else
							{
								strcpy(tfield3a,"-");
								strcat(tfield3a, tfield3);
							}

						rct1 = rct;
						strcpy(tfield21, tfield2a);
						for(I=0; I < lit_ct; I++)
							{
								ret = strcmp(w_literal[I].lit_value, tfield3a);
								if(ret == 0)
									{
										rct1 = w_literal[I].lit_rct;
										strcpy(tfield21, w_literal[I].lit_cname);
										break;
									}
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
                                          strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, tfield2a);	
      						strcpy(w_literal[lit_ct].lit_value, tfield3a); 
						strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 
						w_literal[lit_ct].lit_uct = 1;	
						w_literal[lit_ct].lit_dec = 0; 
						w_literal[lit_ct].lit_type = 1;	                  
						lit_ct++;
					}

				if(fd10_type == 1)
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield2a, c_wkname);
						strcpy(tfield3, tfield10);

						s = strlen(tfield3);
						x99 = 0;
						p1 = strstr(tfield3,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, tfield3);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												tfield3[pi2] = ch;
												pi2++;
											}		
									}
								tfield3[pi2] = '\0';
							}

						if(x99 == 0)
							{	
								strcpy(tfield3a, tfield3);
							}
						else
							{
								strcpy(tfield3a,"-");
								strcat(tfield3a, tfield3);
							}

						rct1 = rct;
						strcpy(tfield21, tfield2a);
						for(I=0; I < lit_ct; I++)
							{
								ret = strcmp(w_literal[I].lit_value, tfield3a);
								if(ret == 0)
									{
										rct1 = w_literal[I].lit_rct;
										strcpy(tfield21, w_literal[I].lit_cname);
										break;
									}
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
                                          strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, tfield2a);	
      						strcpy(w_literal[lit_ct].lit_value, tfield3a); 
						strcpy(w_literal[lit_ct].lit_use_cname, tfield21);
						w_literal[lit_ct].lit_uct = 1; 
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      		             
						lit_ct++;
					}
			}

		while_convert = 1;
		convert = 1;

	}

void c2_pass2_whl_5()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_whl_5");
				trace_rec_1();
			}

		int fd3_type = 0;
		int pi;
		int pi2;
		int x2 = 0;
		int x99 = 0;
		int s = 0;
		int s1 = 0;
		int size = 0;
		int rct1 = 0;
		int I = 0;
		int ret = 0;
		
		char ch, *p1;
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield3b[VAR_LGTH];
		char tfield21[VAR_LGTH];

		pi = 0;
		ch = p_string[pi];
		while(ch != '=') 
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

		if(fd3_type == 1)
			{
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield2a, c_wkname);
						
				s = strlen(tfield3);
				x99 = 0;
				p1 = strstr(tfield3,"-");
				if(p1)
					{
						x99 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, tfield3);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										tfield3[pi2] = ch;
										pi2++;
									}		
							}
						tfield3[pi2] = '\0';
					}

				if(x99 == 0)
					{	
						strcpy(tfield3a, tfield3);
					}
				else
					{
						strcpy(tfield3a,"-");
						strcat(tfield3a, tfield3);
					}
	
				rct1 = rct;
				strcpy(tfield21, tfield2a);
				for(I=0; I < lit_ct; I++)
					{
						ret = strcmp(w_literal[I].lit_value, tfield3a);
						if(ret == 0)
							{
								rct1 = w_literal[I].lit_rct;
								strcpy(tfield21, w_literal[I].lit_cname);
								break;
							}

					}

				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
                          	strcpy(w_literal[lit_ct].lit_name, null_field);
				strcpy(w_literal[lit_ct].lit_cname, tfield2a);	
      				strcpy(w_literal[lit_ct].lit_value, tfield3a);  
				strcpy(w_literal[lit_ct].lit_use_cname, tfield21);	
				w_literal[lit_ct].lit_uct = 1;  
				w_literal[lit_ct].lit_dec = 0; 
				w_literal[lit_ct].lit_type = 1;	      	          
				lit_ct++;

			}
		while_convert = 1;
		convert = 1;
	}

void c2_pass2_math()
	{
		check_semi(); 

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_math");
				trace_rec_1();
			}

		char ch;
		char *p, *p2, *p8, *p9;
			
		int pi;
		int x = 0;
		int x1 = 0;
		int x2 = 0;
		int op_1 = 0;
		int L1 = 0;
		int R1 = 0;
		int L2 = 0;
		int R2 = 0;
		int I = 0;
		int s = 0;
		int math_plus = 0;
		int math_minus = 0;
		int math_mult	= 0;
		int math_div 	= 0;
		int math = 0;
		int math1 = 0;

		p = strstr (p_string, "=");
		if(p)
			{
				p2 = strstr(p_string, "-1");
				if(p2)
					math1 = 1;
				math = 0;
				s = strlen(p_string);
				
				for(I=0; I < s; I++)
					{
						ch = p_string[I];
						if(ch == '+')
							{
								math_plus++;
								math = 1;
							}

						if((ch == '-') && (math1 == 0))
							{
								math_minus++;
								math = 1;
							}

						if(ch == '*')
							{
								math_mult++;
								math = 1;
							}

						if(ch == '/')
							{
								math_div++;
								math = 1;
							}

						if(math == 1)
							{
								/* c2_math_99(); */
								return;
							}
					}
			}

		op_1 = 1;
		
		p8 = strchr(p_string, '(');
		p9 = strchr(p_string, ')');
			
		s = strlen(p_string);
		pi = 0;
		x = 0;
		x2 = 0;
		L1 = 0;
		R1 = 0;
		L2 = 0;
		R2 = 0;
		I = 0;

		ch = p_string[pi];
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if((ch != '=') && (x2 != 1) && (x != 1))
					{
								if(ch == '[')
									{
										L1++;
										x2 = 0;
									}
							}

						if(ch == '=')
							{
								x = 1;
								x1 = I;
								break;
							}
								
						if((x == 1) && (ch != ';'))
							{
								if(ch == '[')
									{
										R1++;
									}
							}
					}

				x2 = 0;
				for(I=x1; I < s; I++)
					{
						ch = p_string[I];
						if(ch == '[')
							{
								L2++;
							}
						if(ch == ']')
							{
								R2++;
							}
					}

				if((op_1 == 1) && (L1 == 0) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9))		
					{
						c2_pass2_math_1(); 
						return;
					}

				if((op_1 == 1) && (L1 == 0) && (R1 == 0) && (L2 == 1) && (R2 == 1) && (!p8) && (!p9))		
					{
						/* c2_math_2(); */
						return;
					}

				if((op_1 == 1) && (L1 == 1) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9))		
					{
						c2_pass2_math_5();
						convert = 1;
						return; 
       				} 

				if((op_1 == 1) && (L1 > 1) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9))		/* in_stack[ndx][0] = '\0'			*/
					{
						/* c2_math_9(); */ 
						return;
					} 

				if((op_1 == 1) && (L1 == 1) &&(L2 == 0) && (R2 == 0) && (p8) && (p9))					/* iv_stack[ndx] = rdp_set();		*/
					{
						/* c2_math_7(); */
						return;
					}

				if((op_1 == 1) && (p8) && (p9) && (L1 == 0) && (R1 == 0) && (math == 0))
					{
						/* c2_math_6(); */
						return;
					}

				if((L1 > 0) && (R1 > 0) && (L2 > 0) && (R2 > 0))								/* byte_array[x] = temp_byte[z]);		*/
					{
						/* c2_math_98(); */
						return;
					}
	}


void c2_pass2_math_1()		/*  single  x = 7 */ 
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_1");
				trace_rec_1();
			}

		check_semi(); 	

		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
					
		int fd2_type = 0;
		int pi;
		int pi2;
		int x3 = 0;
		int x4 = 0;
		int x5 = 0;
		int I = 0;
		int s = 0;
              int size = 0;
		int ret = 0;
		int ret1 = 0;
				
		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t') || (ch == '{'))
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		
		x3 = 0;
		while((ch != ' ') && (x3 == 0)) 
			{
				if(ch == '=')
					{
						x3 = 1;
					}
				else
					{
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
			} 
		tfield1[pi2] = '\0';

		x3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(tfield1, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0)  && (ret1 == 0)) 
					{
						x3 = 1;		
						strcpy(tfield1a, lw_variable[I].lv_cname);
						break;
					}
			}

		if(x3 == 0)
			{
				x3 = 0;
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(tfield1, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x3 = 1;		
								strcpy(tfield1a, gw_variable[I].gv_cname);
								break;
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_pass_2.c c2_pass2_math_1 E-172 tfield1 Not Found = %s\n",tfield1);
				c2_error();
			}

		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}
 
		while(ch != '=')
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

		x5 = 0;
		x4 = 0;
		x3 = 0; 
		s = strlen(p_string);
		while((ch != '[') && (pi < s) && (ch != ';'))
			{
				if((isdigit(ch)) && (x3 == 0))
					{
						fd2_type = 2;
						x3 = 1;
					}

				if((isalpha(ch)) && (x3 == 0))
					{
						fd2_type = 1;
						x3 = 1;
					}

				if(ch == '\'')
					{
						x4 = 1;
						x4++;
					}

				if(x4 > 0)
					{
						if(ch == ' ')
							{
								x5++;
							}
					}
				pi++;
				ch = p_string[pi];
			} 

		if((x4 == 0) && (fd2_type != 2))		/* if field2 is NOT a literal	*/
			{
				math_convert = 1;
				convert = 1;
				return;
			}

		if((x4 == 2) && (x5 == 1) && (fd2_type == 0))		/* if field2 equals ' '	*/
			{
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_1 #14");
						trace_rec_3();
					}

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
  				w_charlit[char_ct].clit_type = 3;
				strcpy(w_charlit[char_ct].clit_cname, tfield1a);	
      				strcpy(w_charlit[char_ct].clit_value, " "); 
				w_charlit[char_ct].clit_lgth = 1; 
				w_charlit[char_ct].clit_uct = 1;	
				             
				char_ct++;
				convert = 1;
				return;
			}

		convert = 1;
	}	


void c2_pass2_math_5()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_5");
        trace_rec_1();
     }

     char ch;
     char *p;
     char *p1;
     char *p2;
     char *p3;
     char field1[VAR_LGTH];
     char field1a[VAR_LGTH];
     char field2[VAR_LGTH];
     char field2a[VAR_LGTH];
     char field3[VAR_LGTH];
     char field3a[VAR_LGTH];
     char field4a[VAR_LGTH];
     char tfield3b[VAR_LGTH];
     char tfield21[VAR_LGTH];


      int pi;
      int pi2;
      int x = 0;
      int x2 = 0;
      int x3 = 0;
      int x99 = 0;
      int m5_3 = 0;
      int m5_6 = 0;
      int m5_7 = 0;
      int m5fd1_type = 0;
      int m5fd2_type = 0;
      int m5fd3_type = 0;
      int I = 0;
      int s = 0;
      int s1 = 0;
      int size = 0;
      int rct1 = 0;



		
		int ret = 0;
		int ret1 = 0;

		p1 = strstr(p_string, "[");
		p2 = strstr(p_string, "]");
		p3 = strstr(p_string, ".");
		
		if((!p1) && (!p2) && (!p3))
			{
				pi = 0;
				ch = p_string[pi];
				while((ch == ' ') || (ch == '\t') || (ch == '{'))
					{
						pi++;
						ch = p_string[pi];
					}
						
				pi2 = 0;
				m5fd1_type = 0;

				while(ch != '[')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					} 
				field1[pi2] = '\0';

				m5_3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								m5_3 = 1;		
								strcpy(field1a, lw_variable[I].lv_cname);	
								m5_7 = strcmp(lw_variable[I].lv_type, "I");
								if(m5_7 == 0)
				 					{
										m5fd1_type = 2;
									}
										
								m5_7 = strcmp(lw_variable[I].lv_type, "C");
								if(m5_7 == 0)
				 					{
										m5fd1_type = 1;
									}
							}
					}

				if(m5_3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								m5_6 = strcmp(field1,gw_variable[I].gv_name);
								if(m5_6 == 0)
									{
										m5_3 = 1;		
										strcpy(field1a, gw_variable[I].gv_cname);	
										m5_7 = strcmp(gw_variable[I].gv_type, "I");
										if(m5_7 == 0)
				 							{
												m5fd1_type = 2;
											}
										
										m5_7 = strcmp(gw_variable[I].gv_type, "C");
										if(m5_7 == 0)
				 							{
												m5fd1_type = 1;
											}
			 
										m5_7 = strcmp(gw_variable[I].gv_type, "G");
										if(m5_7 == 0)
											{
												m5fd1_type = 3;									}
											}
									}
							}

						if(m5_3 == 0)
							{
								printf("c2z_pass_2.c c2_pass2_math_5 E-253 field1 Not Found = %s\n",field1);
								c2_error();
							}

						pi++;
						ch = p_string[pi];
						pi2 = 0;
						x2 = 0;
						while(ch != ']')
							{
								if(x2 == 0)
									{
										if (isalpha(ch))	
											{
    												m5fd2_type = 2;
												x2 = 1;
											}
 
										if (isdigit(ch)) 	
											{
    												m5fd2_type = 1;
												x2 = 1;
											}
							}
						field2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field2[pi2] = '\0';

				if(m5fd2_type == 2)
					{
						m5_3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(field2, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										m5_3 = 1;		
										strcpy(field2a, lw_variable[I].lv_cname);	
										m5_7 = strcmp(lw_variable[I].lv_type, "I");
										if(m5_7 == 0)
				 							{
										
											}
										
										m5_7 = strcmp(lw_variable[I].lv_type, "C");
										if(m5_7 == 0)
				 							{
										
											}
									}
							}

						if(m5_3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										m5_6 = strcmp(field2, gw_variable[I].gv_name);
										if(m5_6 == 0)
											{
												m5_3 = 1;		
												strcpy(field2a, gw_variable[I].gv_cname);		
												m5_7 = strcmp(gw_variable[I].gv_type, "I");
											}
									}
							}

						if(m5_3 == 0)
							{
								printf("c2z_pass_2.c c2_pass2_math_5 E-254 field2 Not Found = %s\n",field2);
								c2_error();
							}
					}

				while(ch != '=')
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
			
				x2 = 0;					
				pi2 = 0;
				s = strlen(p_string);
				while((pi < s) && (ch != ';'))
					{
						if(x2 == 0)
							{
								if (isalpha(ch))	
									{
    										m5fd3_type = 2;
										x2 = 1;
									} 

								if (isdigit(ch)) 	
									{
    										m5fd3_type = 1;
										x2 = 1;
									}
							}
						field3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					} 
				field3[pi2] = '\0';

		x3 = 0;
		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '[')
					x3++;
				if(ch == ']')
					x3++;
			}

		x = 99;
		p = strstr(field3, "'\0'");

		if((p) && (x3 == 2) && (m5fd3_type != 0))		
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_5 field3");
						trace_rec_1();
					}

				m5_3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field1,lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								m5_3 = 1;		
							}
					}

				if(m5_3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								m5_6 = strcmp(field1, gw_variable[I].gv_name);
								if(m5_6 == 0)
									{
										m5_3 = 1;		
									}
							}
					}

				if(m5_3 == 0)
					{		
						printf("c2z_pass_2.c c2_pass2_math_5 E-254 field3 Not Found = %s\n",field3);
						c2_error();
					}

				ret = strcmp("0",field2);
				if((ret == 0) && (x != 99))
					{
						
						
					}
				else
					{
						if((m5fd3_type == 2) && (x != 99))
							{
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_pass_2.c c2_math_5 E-255 field3 type == 2 ");
										c2_error();
									}
							}
					}

				convert = 1;
			}

		if((m5fd2_type == 1) && (convert == 0))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_math_5 field2 type == 1");
						trace_rec_1();
					}
					
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(field2a, c_wkname);
						
				s = strlen(field2);
				x99 = 0;
				p1 = strstr(field2,"-");
				if(p1)
					{
						x99 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, field2);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										field2[pi2] = ch;
										pi2++;
									}		
							}
						field2[pi2] = '\0';
					}

				if(x99 == 0)
					{
						strcpy(tfield21, field2);
					}
				else
					{
						strcpy(tfield21,"-");
						strcat(tfield21, field2);
					}

				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				rct1 = rct;
						
				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
                    		strcpy(w_literal[lit_ct].lit_name, null_field);
				strcpy(w_literal[lit_ct].lit_cname, field2a);	
				strcpy(w_literal[lit_ct].lit_value, tfield21); 
				strcpy(w_literal[lit_ct].lit_use_cname, field2a); 
				w_literal[lit_ct].lit_uct = 1;
				w_literal[lit_ct].lit_dec = 0;
				w_literal[lit_ct].lit_type = 1;	      		
				lit_ct++;
			}

		if((m5fd3_type == 1) && (convert == 0))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_math_5 field3 type == 1");
						trace_rec_1();
					}
					
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(field1a, c_wkname);
				strcpy(tfield21, field1a);			
			
				s = strlen(field3);
				x99 = 0;
				p1 = strstr(field3,"-");
				if(p1)
					{
						x99 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, field3);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										field3[pi2] = ch;
										pi2++;
									}		
							}
						field3[pi2] = '\0';
					}

				if(x99 == 0)
					{	
						strcpy(field3a, field3);
					}
				else
					{
						strcpy(field3a,"-");
						strcat(field3a, field3);
					}
				
				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				rct1 = rct;
				
				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
                    		strcpy(w_literal[lit_ct].lit_name, null_field);
				strcpy(w_literal[lit_ct].lit_cname, field1a);	
				strcpy(w_literal[lit_ct].lit_value, field3a); 
				strcpy(w_literal[lit_ct].lit_use_cname, field1a); 
				w_literal[lit_ct].lit_uct = 1;
				w_literal[lit_ct].lit_dec = 0;
				w_literal[lit_ct].lit_type = 1;	      	             
				lit_ct++;
							
				convert = 1;
			}

		if((m5fd1_type == 1) && (m5fd3_type == 0) && (convert == 0))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_math_5 field3 literal");
						trace_rec_1();
					}

				x = 1;
				pi2 = 0;
				ch = field3[x];
				while(ch != '\'')
					{
						field4a[pi2] = ch;
						pi2++;
						x++;
						ch = field3[x];
					}
				field4a[pi2] = '\0';

				strcpy(field3, field4a);
					
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(field3a, c_wkname);
				
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
  				w_charlit[char_ct].clit_type = 3;
				strcpy(w_charlit[char_ct].clit_cname, field3a);	
      				strcpy(w_charlit[char_ct].clit_value, field3); 
				w_charlit[char_ct].clit_lgth = 1; 	
				w_charlit[char_ct].clit_uct = 1;  
				char_ct++;
			}
				
		x = 99;

		if((!p) && (convert == 0) && (x != 99))		/* not a literal 		*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_math_5 field3 numeric");
						trace_rec_1();
					}
					
				m5_3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								m5_3 = 1;		/* found variable */	
								x3 = strcmp("I", lw_variable[I].lv_type);
							}
					}

				if(m5_3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								m5_6 = strcmp(field1, gw_variable[I].gv_name);
								if(m5_6 == 0)
									{
										m5_3 = 1;		/* found variable */	
										x3 = strcmp("I", gw_variable[I].gv_type);
										
									}
							}
					}

				if(m5_3 == 0)
					{
						printf("c2z_pass_2.c c2_math_5 E-160 field1 Not Found = %s\n",field1);
						c2_error();
					}

				if(m5fd3_type == 2)
					{
						m5_3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(field3, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										m5_3 = 1;		/* found variable */	
										strcpy(field3a, lw_variable[I].lv_cname);	
									}
							}

						if(m5_3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										m5_6 = strcmp(field3, gw_variable[I].gv_name);
										if(m5_6 == 0)
											{
												m5_3 = 1;		/* found variable */	
												strcpy(field3a, gw_variable[I].gv_cname);	

											}
									}
							}

						if(m5_3 == 0)
							{
								printf("c2z_pass_2.c c2_math_5 E-161 field3 Not Found = %s\n",field3);
								c2_error();
							}
					}
				else
					{

						strcpy(field3a, field3);
					}

				if(m5fd1_type != 3)	
					{
						if(m5fd2_type == 1)
							{
								strcpy(a_string, "*         ZAP   C370U,=P'");
								strcat(a_string, field2);
								strcat(a_string, "'");
								strcpy(wk_remark," a[x] = ch ");
								write_remark();
								if(punch_code == 1)
									trace_rec_3();
								work_use_ct[48]++;

							}

						strcpy(a_string, "         LARL  R9,C370U");
						src_line();
						if(punch_code == 1)
							trace_rec_3();
						work_use_ct[48]++;

						strcpy(a_string, "         LARL  R9,C370L8");
						src_line();
						if(punch_code == 1)
							trace_rec_3();
						work_use_ct[9]++;

						strcpy(a_string, "         PACK  ");
						strcat(a_string, "0(8,R9),0(8,R8)");
						strcpy(wk_remark," a[x] = ch ");
						write_remark();
						if(punch_code == 1)
							trace_rec_3();

						strcpy(a_string, "         LARL  R9,C370U");
						src_line();
						if(punch_code == 1)
							trace_rec_3();
						work_use_ct[48]++;

						strcpy(a_string, "         CVB   R2,0(7,R9)");
						src_line();
						if(punch_code == 1)
							trace_rec_3();
						work_use_ct[48]++;

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field1a);
						src_line();
						if(punch_code == 1)
							trace_rec_3();
	
						strcpy(a_string, "         LR    R1,R9");
						src_line();
						if(punch_code == 1)
							trace_rec_3();

						strcpy(a_string, "         AR    R1,R2");
						src_line();
						if(punch_code == 1)
							trace_rec_3();
						
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field3a);
						src_line();
						if(punch_code == 1)
							trace_rec_3();

						strcpy(a_string, "         MVC   0(");
						strcat(a_string, "R9,R1),");
						strcat(a_string, "0(R8)");
						src_line();
						if(punch_code == 1)
							trace_rec_3();

						math_convert = 1;
					}	


				if(m5fd1_type == 3)		/* array processing		*/
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_pass_2.c  c2_math_5 array");
								trace_rec_1();
							}
						return;
					}
				}
			}	

     if((p1) && (p2) && (!p3))
     {
        pi = 0;
        ch = p_string[pi];
        while((ch == ' ') || (ch == '\t') || (ch == '{'))
        {
           pi++;
           ch = p_string[pi];
        }

        pi2 = 0;
        m5fd1_type = 0;

        while(ch != '[')
        {
           field1[pi2] = ch;
           pi2++;
           pi++;
           ch = p_string[pi];
        }
        field1[pi2] = '\0';

        m5_3 = 0;
        for(I=0; I < lv_ct; I++)
        {
           ret = strcmp(field1, lw_variable[I].lv_name);
           ret1 = strcmp(sv_func, lw_variable[I].lv_func);
           if((ret == 0) && (ret1 == 0))
           {
              m5_3 = 1;
              strcpy(field1a, lw_variable[I].lv_cname);
              m5_7 = strcmp(lw_variable[I].lv_type, "I");
              if(m5_7 == 0)
              {
                 m5fd1_type = 2;
              }

              m5_7 = strcmp(lw_variable[I].lv_type, "C");
              if(m5_7 == 0)
              {
                 m5fd1_type = 1;
              }
           }
        }

        if(m5_3 == 0)
        {
           for(I=0; I < gv_ct; I++)
           {
              m5_6 = strcmp(field1,gw_variable[I].gv_name);
              if(m5_6 == 0)
              {
                 m5_3 = 1;
                 strcpy(field1a, gw_variable[I].gv_cname);
                 m5_7 = strcmp(gw_variable[I].gv_type, "I");
                 if(m5_7 == 0)
                 {
                    m5fd1_type = 2;
                 }

                 m5_7 = strcmp(gw_variable[I].gv_type, "C");
                 if(m5_7 == 0)
                 {
                    m5fd1_type = 1;
                 }
                 m5_7 = strcmp(gw_variable[I].gv_type, "G");
                 if(m5_7 == 0)
                 {
                    m5fd1_type = 3;
                 }
              }
           }
        }

        if(m5_3 == 0)
        {
           printf("c2z_pass_2.c c2_pass2_math_5 E-162 field1 Not Found = %s\n",field1);
           c2_error();
        }

        pi++;
        ch = p_string[pi];
        pi2 = 0;
        x2 = 0;
        while(ch != ']')
        {
           if(x2 == 0)
           {
              if(isalpha(ch))
              {
                 m5fd2_type = 2;
                 x2 = 1;
              }
              if (isdigit(ch))
              {
                 m5fd2_type = 1;
                 x2 = 1;
              }
           }
           field2[pi2] = ch;
           pi2++;
           pi++;
           ch = p_string[pi];
        }
        field2[pi2] = '\0';

        if(m5fd2_type == 2)
        {
           m5_3 = 0;
           for(I=0; I < lv_ct; I++)
           {
              ret = strcmp(field2, lw_variable[I].lv_name);
              ret1 = strcmp(sv_func, lw_variable[I].lv_func);
              if((ret == 0) && (ret1 == 0))
              {
                 m5_3 = 1;
                 strcpy(field2a, lw_variable[I].lv_cname);
                 m5_7 = strcmp(lw_variable[I].lv_type, "I");
                 if(m5_7 == 0)
                 {

                 }
                 m5_7 = strcmp(lw_variable[I].lv_type, "C");
                 if(m5_7 == 0)
                 {

                 }
              }
           }

           if(m5_3 == 0)
           {
              for(I=0; I < gv_ct; I++)
              {
										m5_6 = strcmp(field2, gw_variable[I].gv_name);
										if(m5_6 == 0)
											{
												m5_3 = 1;		
												strcpy(field2a, gw_variable[I].gv_cname);		
												m5_7 = strcmp(gw_variable[I].gv_type, "I");
										
											}
									}
							}

						if(m5_3 == 0)
							{
								printf("c2z_pass_2.c c2_pass2_math_5 E-163 field2 Not Found = %s\n",field2);
								c2_error();
							}
					}

				while(ch != '=')
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
			
				x2 = 0;					
				pi2 = 0;
				s = strlen(p_string);
				while((pi < s) && (ch != ';'))
					{
						if(x2 == 0)
							{
								if (isalpha(ch))	
									{
    										m5fd3_type = 2;
										x2 = 1;
									} 

								if (isdigit(ch)) 	
									{
    										m5fd3_type = 1;
										x2 = 1;
									}
							}
						field3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					} 
				field3[pi2] = '\0';

				if((m5fd1_type == 3) && (m5fd2_type == 1) && (m5fd3_type == 1) && (convert == 0))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(field1a, c_wkname);
						
						s = strlen(field2);
						x99 = 0;
						p1 = strstr(field2,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, field2);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												field2[pi2] = ch;
												pi2++;
											}		
									}
								field2[pi2] = '\0';
							}

						if(x99 == 0)
							{	
								strcpy(field2a, field2);
							}
						else
							{
								strcpy(field2a,"-");
								strcat(field2a, field2);
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						rct1 = rct;
			
						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
                    				strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, field1a);	
						strcpy(w_literal[lit_ct].lit_value, field2a); 
						strcpy(w_literal[lit_ct].lit_use_cname, field1a); 
						w_literal[lit_ct].lit_uct = 1;
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      	             
						lit_ct++;
						
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(field1a, c_wkname);
						
						s = strlen(field3);
						x99 = 0;
						p1 = strstr(field3,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, field3);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												field3[pi2] = ch;
												pi2++;
											}		
									}
								field3[pi2] = '\0';
							}

						if(x99 == 0)
							{	
								strcpy(field3a, field3);
							}
						else
							{
								strcpy(field3a,"-");
								strcat(field3a, field3);
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						rct1 = rct;
				
						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
                    				strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, field1a);	
						strcpy(w_literal[lit_ct].lit_value, field3a); 
						strcpy(w_literal[lit_ct].lit_use_cname, field1a);
						w_literal[lit_ct].lit_uct = 2;	
						w_literal[lit_ct].lit_dec = 0; 
						w_literal[lit_ct].lit_type = 1;	      	             
						lit_ct++;
							
						convert = 1;
					}
		
				if((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 1) && (convert == 0))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(field1a, c_wkname);

						s = strlen(field3);
						x99 = 0;
						p1 = strstr(field3,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, field3);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												field3[pi2] = ch;
												pi2++;
											}		
									}
								field3[pi2] = '\0';
							}

						if(x99 == 0)
							{	
								strcpy(field3a, field3);
							}
						else
							{
								strcpy(field3a,"-");
								strcat(field3a, field3);
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						rct1 = rct;
				
						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
                    				strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, field1a);	
						strcpy(w_literal[lit_ct].lit_value, field3a); 
						strcpy(w_literal[lit_ct].lit_use_cname, field1a); 
						w_literal[lit_ct].lit_uct = 1;
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      		             
						lit_ct++;
						convert = 1;
					}
			}

		convert = 1;
	}


/* *************************************************** 
*  c2_pass2_if_15    strchr                          *
* ************************************************** */
void c2_pass2_if_15()		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_15 ");
				trace_rec_1();
			}
	
		int pi;
		int pi2;
		int s;
		int s1;
		int size;

		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		
		pi = 0; 
		ch = p_string[pi];
		while(ch != '\"')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != '\"')
			{
				tfield1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield1[pi2] = '\0';

		s1 = strlen(tfield1);

		if(s1 == 1)
			{
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
  				w_charlit[char_ct].clit_type = 3;
				strcpy(w_charlit[char_ct].clit_cname, tfield1a);	
      				strcpy(w_charlit[char_ct].clit_value, tfield1); 
				w_charlit[char_ct].clit_lgth = 1; 
				w_charlit[char_ct].clit_uct = 1;	             
				char_ct++;
			}

		if(s1 == 2)
			{
				tfield2[0] = tfield1[0];
				tfield2[1] = '\0';
				tfield3[0] = tfield1[1];
				tfield3[1] = '\0';

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield2a, c_wkname);
		
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
  				w_charlit[char_ct].clit_type = 3;
				strcpy(w_charlit[char_ct].clit_cname, tfield2a);	
      				strcpy(w_charlit[char_ct].clit_value, tfield2); 
				w_charlit[char_ct].clit_lgth = 1; 
				w_charlit[char_ct].clit_uct = 1;	             
				char_ct++;

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield3a, c_wkname);
		
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
  				w_charlit[char_ct].clit_type = 3;
				strcpy(w_charlit[char_ct].clit_cname, tfield3a);	
      				strcpy(w_charlit[char_ct].clit_value, tfield3); 
				w_charlit[char_ct].clit_lgth = 1; 
				w_charlit[char_ct].clit_uct = 1;	             
				char_ct++;

			}

		if(s1 > 2)
			{
				printf("c2z_pass_2.c c2_pass2_if_15 E-255 length error s1 = %d\n",s1);
				c2_error();
			}

		convert = 1;
	}


/* *************************************************** 
*  c2_pass2_strrev    strrev                         *
* ************************************************** */
void c2_pass2_strrev()		
	{

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_strrev");
				trace_rec_1();
			}

	}


/* *************************************************** 
*  c2_pass2_if_4                                     *
* ************************************************** */
void c2_pass2_if_4()		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_4");
				trace_rec_1();
			}

		char ch, *p1;
		char *p4;
              char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3b[VAR_LGTH];
		char tfield21[VAR_LGTH];

		int fd2_type = 0;
		int pi;
		int pi2;
		int I = 0;
		int x = 0;
		int x2 = 0;
		int x3 = 0;
		int x99 = 0;
		int s = 0;
		int s1 = 0;
		int size = 0;
		int rct1 = 0;
		int ret = 0;
		int ret1 = 0;
		int complex_if = 0;
				
		p4 = strstr(p_string, "&&");
		if(p4)
			complex_if = 1;
	
		p4 = strstr(p_string, "||");
		if(p4)
			complex_if = 2;

		if(complex_if == 0)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_4 complex_if == 0");
						trace_rec_1();
					}

				pi = 0;
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				x3 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
					{
						if((ch == '_') && (x3 == 0))
							{
								x3 = 1;
							}
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0)) 
							{
								x3 = 1;
								strcpy(tfield1a, lw_variable[I].lv_cname);
								lw_variable[I].lv_use_ct++;
								
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(gw_variable[I].gv_name, tfield1);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(tfield1a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;
										
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_pass_2.c E-256 tfield1 Not Found = %s\n",tfield1);
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
						pi2++;
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

				x2 = 0;           
				pi2 = 0;
				while(ch != ')')
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

				if(fd2_type == 2)
					{
						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(tfield2, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;
										strcpy(tfield2a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
									}
							}

						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(tfield2, gw_variable[I].gv_name);
										if(ret == 0)
											{
												x3 = 1;
												strcpy(tfield2a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												x = strcmp(gw_variable[I].gv_type, "I");
												if(x == 0)
													{
														fd2_type = 2;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_pass_2.c c2_pass2_if_4 tfield2 Not Found = %s\n",tfield2);
								printf("c2z_pass_2.c c2_pass2_if_4 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
							}
					}

				if(fd2_type == 1)
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield1a, c_wkname);
						strcpy(tfield21, tfield1a);

						s = strlen(tfield2);
						x99 = 0;
						p1 = strstr(tfield2,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, tfield2);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												tfield2[pi2] = ch;
												pi2++;
											}		
									}
								tfield2[pi2] = '\0';
							}

						if(x99 == 0)
							{
								strcpy(tfield2a, tfield2);
							}
						else
							{
								strcpy(tfield2a,"-");
								strcat(tfield2a, tfield2);
							}

						rct1 = rct;
						for(I=0; I < lit_ct; I++)
							{
								ret = strcmp(w_literal[I].lit_value, tfield2a);
								if(ret == 0)
									{
										rct1 = w_literal[I].lit_rct;
										strcpy(tfield21, w_literal[I].lit_cname);
										break;
									}
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
              				strcpy(w_literal[lit_ct].lit_cname, tfield1a);	
      						strcpy(w_literal[lit_ct].lit_value, tfield2a); 
						strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 
						w_literal[lit_ct].lit_uct = 1;
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      		             
						lit_ct++;
							
						convert = 1;
					}
			}
	}


/* *************************************************** 
*  c2_math_literal_6                                 *
* ************************************************** */
void c2_math_literal_6()		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_math_literal_6");
				trace_rec_1();
			}

		char ch, *p1;
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3b[VAR_LGTH];
		char tfield4[VAR_LGTH];

		int pi;
		int pi2;
		int x2;
		int x99 = 0;
		int s;
		int s1 = 0;
		int rct1;
		int I;
		int ret;
		int size;
		int fd2_type = 0;

		pi = 0;
		ch = p_string[pi];
		while(ch != '[')
			{
				pi++;
				ch = p_string[pi];
			}

		x2 = 0;
		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ']') 
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
				pi++;
				ch = p_string[pi];
			}
		tfield2[pi2] = '\0';

		if(fd2_type != 2)
			{
				return;
			}

		c_name++;
		snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
		strcpy(c_wkname, "C37F");
		strcat(c_wkname, wk_strg);
		s = strlen(c_wkname);
		c_wkname[s] = '\0';
		strcpy(tfield1a, c_wkname);
		
		s = strlen(tfield2);
		x99 = 0;
		p1 = strstr(tfield2,"-");
		if(p1)
			{
				x99 = 1;
			}

		s1 = s + 1;
		if(x99 == 1)
			{
				strcpy(tfield3b, tfield2);
				pi2 = 0;
				for(I=0; I < s1; I++)
					{
						ch = tfield3b[I];
						if(ch != '-')
							{
								tfield2[pi2] = ch;
								pi2++;
							}		
					}
				tfield2[pi2] = '\0';
			}

		if(x99 == 0)
			{	
				strcpy(tfield2a, tfield2);
			}
		else
			{
				strcpy(tfield2a,"-");
				strcat(tfield2a, tfield2);
			}
	
		rct1 = rct;
		for(I=0; I < lit_ct; I++)
			{
				ret = strcmp(w_literal[I].lit_value, tfield2a);
				if(ret == 0)
					{
						rct1 = w_literal[I].lit_rct;
						strcpy(tfield4, w_literal[I].lit_cname);
						break;
					}
			}

		if(lit_ct == 0)
			{
				size = 1;
				w_literal = malloc(size * sizeof(struct literal));
			}
		else
			{
				size = lit_ct + 1;
				w_literal = realloc(w_literal, size * sizeof(struct literal));
			}

		w_literal[lit_ct].lit_rct = rct;
		w_literal[lit_ct].lit_use_rct = rct1;
              strcpy(w_literal[lit_ct].lit_name, null_field);
		strcpy(w_literal[lit_ct].lit_cname, tfield1a);	
      		strcpy(w_literal[lit_ct].lit_value, tfield2a); 
		strcpy(w_literal[lit_ct].lit_use_cname, tfield4); 
		w_literal[lit_ct].lit_uct = 1;	
		w_literal[lit_ct].lit_dec = 0;
		w_literal[lit_ct].lit_type = 1;	      	             
		lit_ct++;
							
		convert = 1;
	}


void c2_math_literal_7()			/* in_stack[i] = iv_stack[3];	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_math_literal_7");
				trace_rec_1();
			}

		check_semi(); 

		int pi;
		int x2;
		int pi2;
		int x3;
		int x99 = 0;
		int I;
		int s;
		int s1 = 0;
		int rct1;
		int ret;
		int ret1;
		int size;
		int fd2_type = 0;
		int fd4_type = 0;
		
		char ch, *p1;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield2b[VAR_LGTH];
              char tfield2c[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield3b[VAR_LGTH];
		char tfield4[VAR_LGTH];
		char tfield4a[VAR_LGTH];
		char tfield4b[VAR_LGTH];
		char tfield4c[VAR_LGTH];
		
		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

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

		x2 = 0;
		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ']') 
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

		pi++;
		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		ch = p_string[pi];
		while(ch != '[') 
			{
				tfield3[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield3[pi2] = '\0';

		x2 = 0;
		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ']') 
			{
				if(x2 == 0)
					{
						if (isalpha(ch))	
							{
    								fd4_type = 1;
								x2 = 1;
							} 

						if (isdigit(ch)) 	
							{
    								fd4_type = 2;
								x2 = 1;
							}
					}
				tfield4[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield4[pi2] = '\0';

		x3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(tfield1, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						x3 = 1;
						strcpy(tfield1a, lw_variable[I].lv_cname);
						lw_variable[I].lv_use_ct++;
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
								gw_variable[I].gv_use_ct++;
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2_pass_2.c c2_math_literal_7 rct = %d p_string = %s",rct,p_string);
				printf("c2_pass_2.c c2_math_literal_7 tfield1 NOT FOUND = %s\n",tfield1);
				c2_debug();
				exit(1);
			}

		x3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(tfield3, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						x3 = 1;
						strcpy(tfield3a, lw_variable[I].lv_cname);
						lw_variable[I].lv_use_ct++;
					}
			}

		if(x3 == 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(tfield3, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(tfield3a, gw_variable[I].gv_cname);
								gw_variable[I].gv_use_ct++;
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2_pass_2.c c2_math_literal_7 rct = %d p_string = %s",rct,p_string);
				printf("c2_pass_2.c c2_math_literal_7 tfield3 NOT FOUND = %s\n",tfield3);
				c2_debug();
				exit(1);
			}

		if(fd2_type == 2) 
			{
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield2a, c_wkname);
		
				s = strlen(tfield2);
				x99 = 0;
				p1 = strstr(tfield2,"-");
				if(p1)
					{
						x99 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, tfield2);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										tfield2[pi2] = ch;
										pi2++;
									}		
							}
						tfield2[pi2] = '\0';
					}

				if(x99 == 0)
					{
						strcpy(tfield2b, tfield2);
					}
				else
					{
						strcpy(tfield2b,"-");
						strcat(tfield2b, tfield2);
					}

				strcpy(tfield2c, tfield2a);
				rct1 = rct;
				for(I=0; I < lit_ct; I++)
					{
						ret = strcmp(tfield2b, w_literal[I].lit_value);
						if(ret == 0)
							{
								rct1 = w_literal[I].lit_rct;
								strcpy(tfield2c, w_literal[I].lit_cname);
								break;
							}
					}

				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
              		strcpy(w_literal[lit_ct].lit_name, null_field);
				strcpy(w_literal[lit_ct].lit_cname, tfield2a);	
      				strcpy(w_literal[lit_ct].lit_value, tfield2b); 
				strcpy(w_literal[lit_ct].lit_use_cname, tfield2c); 
				w_literal[lit_ct].lit_uct = 1;
				w_literal[lit_ct].lit_dec = 0;
				w_literal[lit_ct].lit_type = 1;	      	             
				lit_ct++;
			}

  
		if(fd4_type == 2)
			{
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield4a, c_wkname);
		
				s = strlen(tfield4);
				x99 = 0;
				p1 = strstr(tfield4,"-");
				if(p1)
					{
						x99 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, tfield4);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										tfield4[pi2] = ch;
										pi2++;
									}		
							}
						tfield4[pi2] = '\0';
					}

				if(x99 == 0)
					{
						strcpy(tfield4b, tfield4);
					}
				else
					{
						strcpy(tfield4b,"-");
						strcat(tfield4b, tfield4);
					}

				rct1 = rct;
				for(I=0; I < lit_ct; I++)
					{
						ret = strcmp(tfield4b, w_literal[I].lit_value);
						if(ret == 0)
							{
								rct1 = w_literal[I].lit_rct;
								strcpy(tfield4c, w_literal[I].lit_cname);
								break;
							}
					}

				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
              		strcpy(w_literal[lit_ct].lit_name, null_field);
				strcpy(w_literal[lit_ct].lit_cname, tfield4a);	
      				strcpy(w_literal[lit_ct].lit_value, tfield4b); 
				strcpy(w_literal[lit_ct].lit_use_cname, tfield4c); 
				w_literal[lit_ct].lit_uct = 1;	
				w_literal[lit_ct].lit_dec = 0; 
				w_literal[lit_ct].lit_type = 1;	                  
				lit_ct++;
			}

		convert = 1;
	}


void c2_math_literal_8()			/* in_stack[12]++;  or in_stack[12]--;	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_math_literal_8");
				trace_rec_1();
			}

		check_semi();

		int pi;
		int pi2;
		int x2;
		int x99 = 0;
		int s;
		int s1 = 0;
		int I;
		int rct1;
		int ret;
		int size;
		int fd1_type = 0;

		char ch, *p1;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield1b[VAR_LGTH];
		char tfield1c[VAR_LGTH];
		char tfield3b[VAR_LGTH];

		pi = 0;
		ch = p_string[pi];
		while(ch != '[')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		x2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ']') 
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
				pi++;
				ch = p_string[pi];
			}
		tfield1[pi2] = '\0';

		if(fd1_type == 2)
			{
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield1a, c_wkname);
		
				s = strlen(tfield1);
				x99 = 0;
				p1 = strstr(tfield1,"-");
				if(p1)
					{
						x99 = 1;
					}

				s1 = s + 1;
				if(x99 == 1)
					{
						strcpy(tfield3b, tfield1);
						pi2 = 0;
						for(I=0; I < s1; I++)
							{
								ch = tfield3b[I];
								if(ch != '-')
									{
										tfield1[pi2] = ch;
										pi2++;
									}		
							}
						tfield1[pi2] = '\0';
					}

				if(x99 == 0)
					{
						strcpy(tfield1b, tfield1);
					}
				else
					{
						strcpy(tfield1b,"-");
						strcat(tfield1b, tfield1);
					}

				rct1 = rct;
				for(I=0; I < lit_ct; I++)
					{
						ret = strcmp(tfield1b, w_literal[I].lit_value);
						if(ret == 0)
							{
								rct1 = w_literal[I].lit_rct;
								strcpy(tfield1c, w_literal[I].lit_cname);
								break;
							}
					}

				if(lit_ct == 0)
					{
						size = 1;
						w_literal = malloc(size * sizeof(struct literal));
					}
				else
					{
						size = lit_ct + 1;
						w_literal = realloc(w_literal, size * sizeof(struct literal));
					}

				w_literal[lit_ct].lit_rct = rct;
				w_literal[lit_ct].lit_use_rct = rct1;
              		strcpy(w_literal[lit_ct].lit_name, null_field);
				strcpy(w_literal[lit_ct].lit_cname, tfield1a);	
      				strcpy(w_literal[lit_ct].lit_value, tfield1b); 
				strcpy(w_literal[lit_ct].lit_use_cname, tfield1c); 
				w_literal[lit_ct].lit_uct = 1;
				w_literal[lit_ct].lit_dec = 0;
				w_literal[lit_ct].lit_type = 1;	      	             
				lit_ct++;
			}

		convert = 1;
	}

void c2_pass2_whl_7()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_whl_7");
				trace_rec_1();
			}

		char ch;
		char *p, *p1;
		char wk_sv_func[32];

		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field5a[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field7a[VAR_LGTH];
		char field7b[VAR_LGTH];
		char field7c[VAR_LGTH];

		char tfield3b[VAR_LGTH];

		int pi;
		int pi2;
		int x2 = 0;
		int x3 = 0;
		int x99 = 0;
		int I = 0;
		int v = 0;
		int while_complex = 0;
		int whfd3_type = 0;
		int whfd7_type = 0;
		int operand_1 = 0;
		int operand_3 = 0;
		int wh_3 = 0;
		int wh_4 = 0;
		int short_while = 0;
		int ret = 0;
		int ret1 = 0;
		int s = 0;
		int s1 = 0;
		int rct1 = 0;
		int size = 0;

		var_use[10]++;

		p = strstr(p_string, "&&");
		if(p)
			{
				while_complex = 1;
			}

		if(while_complex == 0)
			{
				p = strstr(p_string, "||");
				if(p)
					{
						while_complex = 1;
					}
			}

		if(while_complex == 0)
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
				while(ch != '(')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

				strcpy(wk_sv_func, field1);

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

				pi++;
				ch = p_string[pi];
				if(ch == ')')
					{
						short_while = 1;
					}

				if(short_while == 1)
					{
						return;

					}		

				if(short_while == 0)
					{
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
								field3[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						field3[pi2] = '\0';

						pi++;
						ch = p_string[pi];
						while(ch == ' ')
							{
								pi++;
								ch = p_string[pi];
							}
						
						while(ch != ')')
							{
								pi++;
								ch = p_string[pi];
							}
						
						operand_1 = 0;
						if(operand_1 == 0)
							{
								p = strstr(field3, "==");
								if(p)
									operand_1 = 1;
							}

						if(operand_1 == 0)
							{
								p = strstr(field3, "!=");
								if(p)
									operand_1 = 2;
							}
				
						if(operand_1 == 0)
							{
								p = strstr(field3, "<=");
								if(p)
									operand_1 = 3;
							}
				
						if(operand_1 == 0)
							{
								p = strstr(field3, ">=");
								if(p)
									operand_1 = 4;
							}

						if(operand_1 == 0)
							{
								p = strstr(field3, "=");
								if(p)
									operand_1 = 5;
							}

						if(operand_1 == 0)
							{
								p = strstr(field3, "<");
								if(p)
									operand_1 = 6;
							}

						if(operand_1 == 0)
							{
								p = strstr(field3, ">");
								if(p)
									operand_1 = 7;
							}

						x3 = 0;
						x2 = 0;
						if(lv_ct > 0)
							{
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(field2, lw_variable[v].lv_name);
										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if((ret == 0) && (ret1 == 0))
											{				
												x3 = 1;
												strcpy(field2a, lw_variable[v].lv_cname);
												lw_variable[v].lv_use_ct++;
											}
									}
							}

						if(x3 == 0)
							{
								x2 = 0;
								if(gv_ct > 0)
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
							}

						if(x3 == 0)
							{
								printf("while_case_7 complex = 0 short_while = 0 Error Message #51\n");
								printf("c2z_pass_2.c while_case_7 complex = 0 short_while = 0 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
							}

						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_pass_2.c c2_while_7 Short ");
								trace_rec_1();
							}
						
						if(wh_ct > 0)
							{
								for(I=0; I < wh_ct; I++)
									{
										if(w_while_table[I].wh_rct == rct)
											{
												snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
											}
									}
							}

						while_convert = 1;		
						convert = 1;
					}		
			}

		if(while_complex == 1)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1");
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
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}

				pi++;
				ch = p_string[pi];
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
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}
				while(ch != ' ')
					{
						if(ch != ' ')
							{
								field2[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
					}
				field2[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				x2 = 0;
				while(ch != ')')
					{
						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										whfd3_type = 1;
										x2 = 1;
									} 

								if (isalpha(ch))	
									{
										whfd3_type = 2;
										x2 = 1;
									}
							}
						field3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field3[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

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
						field5[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field5[pi2] = '\0';

				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				ch = p_string[pi];
				while(ch !=  ' ')
					{
						field6[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field6[pi2] = '\0';

				x2 = 0;
				pi2 = 0;
				ch = p_string[pi];
				while(ch !=  ')')
					{
						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										whfd7_type = 1;
										x2 = 1;
									} 

								if (isalpha(ch))	
									{
										whfd7_type = 2;
										x2 = 1;
									}
							}
						if(ch != ' ')
							{
								field7[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				field7[pi2] = '\0';

				if(whfd7_type == 2)
					{
						return;
					}  

				if(whfd7_type == 1)
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(field7a, c_wkname);
		
						s = strlen(field7);
						x99 = 0;
						p1 = strstr(field7,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, field7);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												field7[pi2] = ch;
												pi2++;
											}		
									}
								field7[pi2] = '\0';
							}

						if(x99 == 0)
							{	
								strcpy(field7b, field7);
							}
						else
							{
								strcpy(field7b,"-");
								strcat(field7b, field7);
							}

						rct1 = rct;
						for(I=0; I < lit_ct; I++)
							{
								ret = strcmp(field7b, w_literal[I].lit_value);
								if(ret == 0)
									{
										rct1 = w_literal[I].lit_rct;
										strcpy(field7c, w_literal[I].lit_cname);
										break;
									}
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
              				strcpy(w_literal[lit_ct].lit_name, field5);
						strcpy(w_literal[lit_ct].lit_cname, field7a);	
      						strcpy(w_literal[lit_ct].lit_value, field7b); 
						strcpy(w_literal[lit_ct].lit_use_cname, field7c);
						w_literal[lit_ct].lit_uct = 1; 
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      	             
						lit_ct++;

						return;
					}

				wh_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field1, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(field1a, lw_variable[v].lv_cname);
									}
							}
					}

				if(wh_3 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										wh_4 = strcmp(field1, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(field1a, gw_variable[v].gv_cname);
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_pass_2.c while_case_7 field1 Not Found = %s\n",field1);
						printf("c2z_pass_2.c while_case_7 rct = %d p_string = %s\n",rct,p_string);
						c2_debug();
						exit(1);
					}

				operand_1 = 0;
				if(operand_1 == 0)
					{
						p = strstr(field2, "==");
						if(p)
							operand_1 = 1;
					}

				if(operand_1 == 0)
					{
						p = strstr(field2, "!=");
						if(p)
							operand_1 = 2;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(field2, "<=");
						if(p)
							operand_1 = 3;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(field2, ">=");
						if(p)
							operand_1 = 4;
					}

				if(operand_1 == 0)
					{
						p = strstr(field2, "=");
						if(p)
							operand_1 = 5;
					}

				if(operand_1 == 0)
					{
						p = strstr(field2, "<");
						if(p)
							operand_1 = 6;
					}

				if(operand_1 == 0)
					{
						p = strstr(field2, ">");
						if(p)
							operand_1 = 7;
					}

				if(whfd3_type == 1)
					{
						strcpy(field3a, field3);
					}

				if(whfd3_type == 2)
					{
						wh_3 = 0;
						if(lv_ct > 0)
							{
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(field3, lw_variable[v].lv_name);
										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if((ret == 0) && (ret1 == 0))
											{				
												wh_3 = 1;
												strcpy(field3a, lw_variable[v].lv_cname);
											}
									}
							}

						if(wh_3 == 0)
							{
								if(gv_ct > 0)
									{
										for(v = 0; v < gv_ct; v++)
											{
												wh_4 = strcmp(field3, gw_variable[v].gv_name);
												if(wh_4 == 0)
													{				
														wh_3 = 1;
														strcpy(field3a, gw_variable[v].gv_cname);
													}
											}
									}
							}

						if(wh_3 == 0)
							{
								printf("c2z_pass_2.c while_case_7 field3 Not Found = %s\n",field3);
								printf("c2z_pass_2.c while_case_7 rct = %d p_string = %s\n",rct,p_string);
								c2_debug();
								exit(1);
							}
					}

				wh_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field5, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(field5a, lw_variable[v].lv_cname);
									}
							}
					}

				if(wh_3 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										wh_4 = strcmp(field5, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(field5a, gw_variable[v].gv_cname);
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_pass_2.c while_case_7 field5 Not Found = %s\n",field5);
						printf("c2z_pass_2.c while_case_7 rct = %d p_string = %s\n",rct,p_string);
						exit(1);
					}

				operand_3 = 0;
				if(operand_3 == 0)
					{
						p = strstr(field6, "==");
						if(p)
							operand_3 = 1;
					}

				if(operand_3 == 0)
					{
						p = strstr(field6, "!=");
						if(p)
							operand_3 = 2;
					}
				
				if(operand_3 == 0)
					{
						p = strstr(field6, "<=");
						if(p)
							operand_3 = 3;
					}
				
				if(operand_3 == 0)
					{
						p = strstr(field6, ">=");
						if(p)
							operand_3 = 4;
					}

				if(operand_3 == 0)
					{
						p = strstr(field6, "=");
						if(p)
							operand_3 = 5;
					}

				if(operand_3 == 0)
					{
						p = strstr(field6, "<");
						if(p)
							operand_3 = 6;
					}

				if(operand_3 == 0)
					{
						p = strstr(field6, ">");
						if(p)
							operand_3 = 7;
					}

				if(whfd7_type == 2)
					{
						wh_3 = 0;
						if(lv_ct > 0)
							{
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(field7, lw_variable[v].lv_name);
										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if((ret == 0) && (ret1 == 0))
											{				
												wh_3 = 1;
												strcpy(field7a, lw_variable[v].lv_cname);
											}
									}
							}

						if(wh_3 == 0)
							{
								if(gv_ct > 0)
									{
										for(v = 0; v < gv_ct; v++)
											{
												wh_4 = strcmp(field7, gw_variable[v].gv_name);
												if(wh_4 == 0)
													{				
														wh_3 = 1;
														strcpy(field7a, gw_variable[v].gv_cname);
													}
											}
									}
							}
 
						if(wh_3 == 0)
							{
								printf("c2z_pass_2.c while_case_7 field7 Not Found = %s\n",field7);
								printf("c2z_pass_2.c while_case_7 rct = %d p_string = %s\n",rct,p_string);
								c2_debug();
								exit(1);
							}
					}		

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				check_length();
				strcat(a_string, "DS    0H");
				strcpy(wk_remark," while    */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #2");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #3");
						trace_rec_3();
					}
				var_use[1]++;
				work_use_ct[2]++;
				
				strcpy(a_string, "         BRASL C370LNK,ISDIGIT");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #4");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370ISDG");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #5");
						trace_rec_3();
					}
 
				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #6");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         CP    0(4,R9),0(4,R8)");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #7");
						trace_rec_3();
					}
				work_use_ct[31]++;

				if(operand_1 == 1)
					{
						strcpy(a_string, "         JNE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						var_use[1]++;
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #8");
								trace_rec_3();
							}
					}

				if(operand_1 == 2)
					{
						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						var_use[1]++;
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #9");
								trace_rec_3();
							}
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, field5a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #10");
						trace_rec_3();
					}
				var_use[1]++;

				if(whfd7_type == 1)
					{
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #11");
								trace_rec_3();
							}
						var_use[1]++;

					}

				if(whfd7_type == 2)
					{
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field7a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #12");
								trace_rec_3();
							}
						var_use[1]++;
					}

				strcpy(a_string, "         CP    0(4,R9),0(4,R8)");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #13");
						trace_rec_3();
					}

				if(operand_3 == 3)
					{
						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						var_use[1]++;
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #14");
								trace_rec_3();
							}

						strcpy(a_string, "         JLL   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						var_use[1]++;
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #15");
								trace_rec_3();
							}
					}

				if(operand_3 == 6)
					{
						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						var_use[1]++;
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #16");
								trace_rec_3();
							}

						strcpy(a_string, "         JLH   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						var_use[1]++;
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #17");
								trace_rec_3();
							}
		     			}

				while_convert = 1;                        
				convert = 1;
			}	

	}


void c2_pass2_whl_13()		  /* STRCMP	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_2.c c2_pass2_whl_13");
				trace_rec_1();
			}

		char *p, *p1;			
		char ch;

		int pi;
		int pi2;
		int while_complex = 0;
		int whfd5_type = 0;
		int x2 = 0;
		int x99 = 0;
		int s = 0;
		int s1 = 0;
		int rct1 = 0;
		int size = 0;
		int I = 0;

		char field5[VAR_LGTH];
		char field5a[VAR_LGTH];
		char field5b[VAR_LGTH];
		char field5c[VAR_LGTH];
		
		char tfield3b[VAR_LGTH];

		int ret = 0;
		
		p = strstr(p_string,"&&");
		if(p)
			{
				while_complex = 1;
			}

		if(while_complex == 0)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_2.c c2_while_13 complex = 0 ");
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
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}
			
				pi++;
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}

				pi++;
				ch = p_string[pi];
				while(ch != '[')
					{
						pi++;
						ch = p_string[pi];
					}
				
				pi++;
				ch = p_string[pi];
				while(ch != ']')
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

				pi++;
				ch = p_string[pi];
				while(ch != ')')
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

				x2 = 0;
				pi2 = 0;
				while(ch != ')')
					{
						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										whfd5_type = 1;
										x2 = 1;
									}
 
								if (isalpha(ch))	
									{
										whfd5_type = 2;
										x2 = 1;
									}
							}

						field5[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field5[pi2] = '\0';

				if(whfd5_type == 1)
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(field5a, c_wkname);
		
						s = strlen(field5);
						x99 = 0;
						p1 = strstr(field5,"-");
						if(p1)
							{
								x99 = 1;
							}

						s1 = s + 1;
						if(x99 == 1)
							{
								strcpy(tfield3b, field5);
								pi2 = 0;
								for(I=0; I < s1; I++)
									{
										ch = tfield3b[I];
										if(ch != '-')
											{
												field5[pi2] = ch;
												pi2++;
											}		
									}
								field5[pi2] = '\0';
							}

						if(x99 == 0)
							{
								strcpy(field5b, field5);
							}
						else
							{
								strcpy(field5b,"-");
								strcat(field5b, field5);
							}

						rct1 = rct;
						for(I=0; I < lit_ct; I++)
							{
								ret = strcmp(field5b, w_literal[I].lit_value);
								if(ret == 0)
									{
										rct1 = w_literal[I].lit_rct;
										strcpy(field5c, w_literal[I].lit_cname);
										break;
									}
							}

						if(lit_ct == 0)
							{
								size = 1;
								w_literal = malloc(size * sizeof(struct literal));
							}
						else
							{
								size = lit_ct + 1;
								w_literal = realloc(w_literal, size * sizeof(struct literal));
							}

						w_literal[lit_ct].lit_rct = rct;
						w_literal[lit_ct].lit_use_rct = rct1;
              				strcpy(w_literal[lit_ct].lit_name, null_field);
						strcpy(w_literal[lit_ct].lit_cname, field5a);	
      						strcpy(w_literal[lit_ct].lit_value, field5b); 
						strcpy(w_literal[lit_ct].lit_use_cname, field5c); 
						w_literal[lit_ct].lit_uct = 1;
						w_literal[lit_ct].lit_dec = 0;
						w_literal[lit_ct].lit_type = 1;	      	             
						lit_ct++;
					}
			}		
	}


void c2_pass2_fgets()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_fgets");
        trace_rec_1();
     }

     convert = 1;
}







	