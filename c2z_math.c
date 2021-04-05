/* ***************************************************
*  c2z : c2z_math.c :                                *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */

/* ****************************************************************************
*      Math functions ( =, +, -, *, / ) MUST BE LAST CALL IN PARSER           *
* *************************************************************************** */

void c2_math()
	{
		check_semi(); 

		char *p, *p2, *p8, *p9;
		char ch;
		
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
					{
						math1 = 1;
					}

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
								c2_math_99();
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

		if((op_1 == 1) && (L1 == 0) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9))		
			{
				c2_math_1();
				return;
			}

		if((op_1 == 1) && (L1 == 0) && (R1 == 0) && (L2 == 1) && (R2 == 1) && (!p8) && (!p9))		
			{
				c2_math_2();
				return;
			}

		if((op_1 == 1) && (L1 == 1) && (R1 == 1) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9))		
			{
				c2_math_5();
				return;
			} 

		if((op_1 == 1) && (L1 == 1) && (R1 == 1) && (L2 == 0) && (R2 == 0) && (p8) && (p9) && (x20 == 1))		
			{
				c2_math_51();
				return;
			} 

		if((op_1 == 1) && (L1 > 1) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9))		
			{
				c2_math_9(); 
				return;
			} 

		if((op_1 == 1) && (L1 == 1) &&(L2 == 0) && (R2 == 0) && (p8) && (p9) && (x20 == 0))			
			{
				c2_math_7();
				return;
			}

		if((op_1 == 1) && (p8) && (p9) && (L1 == 0) && (R1 == 0) && (math == 0))
			{
				c2_math_6();
				return;
			}

		if((L1 > 0) && (R1 > 0) && (L2 > 0) && (R2 > 0))								
			{
				c2_math_98();
				return;
			}
 	}		


/* ************************************
*   x = 7;                            *
************************************* */
void c2_math_1()		
	{
		check_semi(); 

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_1");
				trace_rec_1();
			}

		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];

		int pi;
		int pi2;
		int fd1_id = 0;
		int fd2_id = 0;
		int fd2_type = 0;
		int x2 = 0;
		int x3 = 0;
		int x4 = 0;
		int x5 = 0;
		int x9 = 0;
		int I = 0;
		int s = 0;
		int ret = 0;
		int ret1 = 0;

		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t') || (ch == '{'))
			{
				pi++;
				ch = p_string[pi];
			}

		x2 = 0;
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
				printf("c2z_math.c c2_math_1 E-182 tfield1 Not Found = %s\n",tfield1);
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

		if((x4 == 2) && (x5 == 1) && (fd2_type == 0))		
			{

				for(I=0; I < char_ct; I++)
					{

						if(w_charlit[I].clit_rct == rct)
							{
								strcpy(tfield2a, w_charlit[I].clit_cname);
                                                      	x3 = w_charlit[I].clit_lgth;
							}
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1);
				strcat(wk_remark, " */");
				write_remark();
                           	if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_1 #21");
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
						strcpy(trace_1, "c2z_math.c c2_math_1 #22");
						trace_rec_3();
					}

				if(fd1_id == 3)
					{
						strcpy(a_string, "         MVC   0(1,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_1 #23");
								trace_rec_3();
							}
					}

				if(fd1_id == 2)
					{
						printf("c2z_math.c c2_math_1 fd1_id = 2 NOT CODED\n");
						c2_error();
					}

				convert = 1;

				return;
			}

		if((x4 == 0) && (fd2_type != 2))		
			{
				x2 = 0;
				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield2, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield2a, lw_variable[I].lv_cname);
								fd2_id = lw_variable[I].lv_id;
								break;
							}
					}
								
				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield2, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;		/* found variable */
										strcpy(tfield2a, gw_variable[I].gv_cname);
										fd2_id = gw_variable[I].gv_id;
										break;
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_1 E-183 tfield2 Not Found = %s\n",tfield2);
						c2_error();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
                            strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_1 #1");
						trace_rec_3();
					}

				if(fd2_type == 2)
					{
						ret = strcmp("0",tfield2);
						if(ret == 0)
							{
								strcpy(a_string, "         LARL  R8,C370ONE");
								strcpy(wk_remark, " C370ONE */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_1 #2");
										trace_rec_3();
									}
								work_use_ct[33]++;
							}
					}

				if(fd2_type == 1)
					{
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield2a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield2);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_1 #3");
								trace_rec_3();
							}
					}

				if((fd1_id == 1) && (fd2_id == 1))
					{
						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						strcpy(wk_remark," ");
						strcat(wk_remark, tfield1);
						strcat(wk_remark, " */ ");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_1 #4");
								trace_rec_3();
							}
					}

				if((fd1_id == 2) && (fd2_id == 2))
					{
						strcpy(a_string, "         LD    R2,0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_1 #5");
								trace_rec_3();
							}

						strcpy(a_string, "         STD   R2,0(R9)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_1 #6");
								trace_rec_3();
							}
					}

				math_convert = 1;
			}

		if((x4 == 0) && (fd2_type == 2))		
			{
				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_1 #7");
						trace_rec_3();
					}	
				
				for(I=0; I < lit_ct; I++)
					{
						if((w_literal[I].lit_rct == rct) && (w_literal[I].lit_uct == 1))
							{
							       x9 = w_literal[I].lit_use_rct;
							}
					}
					
				for(I=0; I < lit_ct; I++)
					{
						if(w_literal[I].lit_rct == x9)
							{
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string,  w_literal[I].lit_use_cname);
								strcpy(wk_remark, " Literal */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_1 #8");
										trace_rec_3();
									}
								break;
							}
					}
			
				if(fd1_id == 1)
					{
						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_1 #9");
								trace_rec_3();
							}
					}

				if(fd1_id == 2)
					{
						strcpy(a_string, "         LD    R2,0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_1 #10");
								trace_rec_3();
							}

						strcpy(a_string, "         STD   R2,0(R9)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_1 #11");
								trace_rec_3();
							}
					}
			}

		convert = 1;
	}	


/* ************************************
*   ch = p_string[pi]       101       *
************************************* */
void c2_math_2()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_2");
				trace_rec_1();
			}

		char ch;
		char wk_sv_func[VAR_LGTH];
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field4[VAR_LGTH];
		char field4a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field5a[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field8[VAR_LGTH];
		char field9[VAR_LGTH];
		char field10[VAR_LGTH];
		char field10a[VAR_LGTH];
		char field11[VAR_LGTH];

		int pi;
		int pi2;
		int fd1_type = 0;
		int fd2_type = 0;
		int x2 = 0;
		int x3 = 0;
		int x5 = 0;
		int x10 = 0;
		int ret = 0;
		int ret1 = 0;
		int mth2_1 = 0;
		int I = 0;
		int s = 0;
		int math_char = 0;
		int math_array = 0;

		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t') || (ch == '{'))
			{
				pi++;
				ch = p_string[pi];
			}
						
		x2 = 0;
		pi2 = 0;
		fd1_type = 0;
		while(ch != ' ')
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
						x3 = 1;		/* found variable */	
						strcpy(field1a, lw_variable[I].lv_cname);
						lw_variable[I].lv_use_ct++;	
						ret1 = strcmp("I",lw_variable[I].lv_type);
						if(ret1 == 0)
		 					{
								fd1_type = 2;
							}
									
						ret = strcmp("C",lw_variable[I].lv_type);
						if(ret == 0)
		 					{
								fd1_type = 1;
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
								ret = strcmp("I",gw_variable[I].gv_type);
								if(ret == 0)
				 					{
										fd1_type = 2;
									}
											
								ret = strcmp("C",gw_variable[I].gv_type);
								if(ret == 0)
				 					{
										fd1_type = 1;
									}
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_math.c c2_math_2 E-421 field1 Not FOund = %s\n",field1);
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
		x2 = 0;
		s = strlen(p_string);
		while((ch != '[') && (pi < s) && (ch != ';'))
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
						ret = strcmp("I",lw_variable[I].lv_type);
						if(ret == 0)
							{
								fd2_type = 2;
							}
						ret = strcmp("C",lw_variable[I].lv_type);
						if(ret == 0)
							{
								fd2_type = 1;
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
								ret1 = strcmp("I", gw_variable[I].gv_type);
								if(ret1 == 0)
									{
										fd2_type = 2;
									}
								ret1 = strcmp("C", gw_variable[I].gv_type);
								if(ret1 == 0)
									{
										fd2_type = 1;
									}
								ret1 = strcmp("G", gw_variable[I].gv_type);
								if(ret1 == 0)
									{
										fd2_type = 3;
									}
								ret1 = strcmp("A", gw_variable[I].gv_type);
								if(ret1 == 0)
									{
										fd2_type = 4;
									}
							}
					}
			}

		pi2 = 0;
		if(ch == '[')
			{
				x2 = 0;
				pi++;
				ch = p_string[pi];
				while((ch != ']') && (pi < s) && (ch != ';'))
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
						field3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field3[pi2] = '\0';
			}

		if((fd1_type  == 1) && (fd2_type == 2))		/* cx = xxstring[0] */
			{
				x5 = 0;
 				if(lv_ct > 0)
					{
						for(I = 0; I < lv_ct; I++)
							{
								ret = strcmp(field2, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{	
										x5 = 1;
										strcpy(field4, lw_variable[I].lv_type);
									}
							}
					}
				
				if(x5 == 0)
					{
						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(field2, gw_variable[I].gv_name);
										if(ret == 0)
											{
												x5 = 1;
												strcpy(field4, gw_variable[I].gv_type);
											}
									}
							}
					}

				if(x5 == 0)
					{
						printf("c2z_math.c c2_math_2 E-422 field4 Not Found = %s\n",field4);
						c2_error();
					}

				mth2_1 = strcmp(field4, "C");
				if(mth2_1 == 0)
					{
						math_char = 1;
					}
				mth2_1 = strcmp(field4, "A");
				if(mth2_1 == 0)
					{
						math_array = 1;
					}

				if(math_char == 1)		
					{
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcat(a_string, "A");
						check_length();
						strcat(a_string, "DS    0H");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #70 ");
 								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370U");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #71 ");
 								trace_rec_3();
							}
						work_use_ct[9]++;

						for(I=0; I < lit_ct; I++)
							{
								if((w_literal[I].lit_rct == rct) && (w_literal[I].lit_uct == 1))
									{
										strcpy(field10a,w_literal[I].lit_use_cname);	
									}
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field10a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field10a);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #72 ");
 								trace_rec_3();
							}
		
						strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #73 ");
 								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370U");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #74 ");
 								trace_rec_3();
							}
						work_use_ct[48]++;

						strcpy(a_string, "         CVB   R5,0(4,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #75 ");
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
								strcpy(trace_1, "c2z_math.c c2_math_2 #76 ");
 								trace_rec_3();
							}

						strcpy(a_string, "         IC    R0,");
						strcat(a_string, "0(R8,");
						strcat(a_string, "(R5))");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #77 ");
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
								strcpy(trace_1, "c2z_math.c c2_math_2 #78 ");
 								trace_rec_3();
							}

						strcpy(a_string, "         STC   R0,");
						strcat(a_string, "0(0,R9)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #79 ");
 								trace_rec_3();
							}
					}	

 				if(math_array == 1)		/* extract character from a array field  			*/
					{
						printf("c2z_math.c c2_math_2 E-423 math_array == 1 ERROR\n");
						c2_error();
					}	
				
				math_convert = 1;
				return;
			}

		if((fd1_type  == 1) && (fd2_type == 1))		/* x = ct  punch out */
			{
				x5 = 0;
 				if(lv_ct > 0)
					{
						for(I = 0; I < lv_ct; I++)
							{
								ret = strcmp(field3, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{	
										x5 = 1;
										strcpy(field3a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
									}
							}
					}

				if(x5 == 0)
					{
						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(field3, gw_variable[I].gv_name);
										if(ret == 0)
											{
												x5 = 1;
												strcpy(field3a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
											}
									}
							}
					}

				if(x5 == 0)
					{
						printf("c2z_math.c c2_math_2 E-424 field3 Not Found = %s\n",field3);
						c2_error();
					}

				x5 = 0;
 				if(lv_ct > 0)
					{
						for(I = 0; I < lv_ct; I++)
							{
								ret = strcmp(field2, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{	
										x5 = 1;
										strcpy(field4, lw_variable[I].lv_type);
									}
							}
					}
				
				if(x5 == 0)
					{
						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(field2, gw_variable[I].gv_name);
										if(ret == 0)
											{
												x5 = 1;
												strcpy(field4, gw_variable[I].gv_type);
											}
									}
							}
					}

				if(x5 == 0)
					{
						printf("c2z_math.c c2_math_2 E-425 field4 not found = %s\n",field4);
						c2_error();
					}

				mth2_1 = strcmp(field4, "C");
				if(mth2_1 == 0)
					{
						math_char = 1;
					}

				mth2_1 = strcmp(field4, "A");
				if(mth2_1 == 0)
					{
						math_array = 1;
					}

				if(math_char == 1)		
					{
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcat(a_string, "A");
						check_length();
						strcat(a_string, "DS    0H");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #8 ");
 								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370U");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #10 ");
 								trace_rec_3();
							}
						work_use_ct[9]++;

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field3a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field3);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #11 ");
 								trace_rec_3();
							}
		
						strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #12 ");
 								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370U");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #13 ");
 								trace_rec_3();
							}
						work_use_ct[48]++;

						strcpy(a_string, "         CVB   R5,0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #14 ");
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
								strcpy(trace_1, "c2z_math.c c2_math_2 #16 ");
 								trace_rec_3();
							}

						strcpy(a_string, "         IC    R0,");
						strcat(a_string, "0(R8,");
						strcat(a_string, "(R5))");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #17 ");
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
								strcpy(trace_1, "c2z_math.c c2_math_2 #18 ");
 								trace_rec_3();
							}

						strcpy(a_string, "         STC   R0,");
						strcat(a_string, "0(0,R9)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 #19 ");
 								trace_rec_3();
							}
					}	

 				if(math_array == 1)		/* extract character from a array field  			*/
					{

						printf("c2z_math.c c2_math_2 E-426 math_array == 1 ERROR\n");
						c2_error();
					}	
				
				math_convert = 1;
			}	

		if((fd1_type == 2) && (fd2_type == 1))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1");
						trace_rec_1();
					}

				pi = 0;
				ch = p_string[pi];
				while(ch != '[')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ']') 
					{
						field3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field3[pi2] = '\0';

				x5 = 0;
 				if(lv_ct > 0)
					{
						for(I = 0; I < lv_ct; I++)
							{
								ret = strcmp(field3, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{	
										x5 = 1;
										strcpy(field3a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
									}
							}
					}
				
				if(x5 == 0)
					{
						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(field3, gw_variable[I].gv_name);
										if(ret == 0)
											{
												x5 = 1;
												strcpy(field3a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
											}
									}
							}
					}

				if(x5 == 0)
					{
						printf("c2z_math.c c2_math_2 2 & 1 E-298 field3 not found = %s\n",field3);
						c2_error();
					}

				x10 = 0;
				if(gv_ct > 0)
					{
						field7[0] = '\0';
						field8[0] = '\0';
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(field2, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x10 = 1;
										strcpy(field5, gw_variable[I].gv_dsect);
										strcpy(field6, gw_variable[I].gv_label);
										strcpy(field7, gw_variable[I].gv_table);
										strcpy(field8, gw_variable[I].gv_aname);
										strcpy(field9, gw_variable[I].gv_sv_reg);
										strcpy(field10, gw_variable[I].gv_wk_reg);
										strcpy(field11, gw_variable[I].gv_wk_strg);
									}
							}
					}

				if(x10 == 1)
					{
						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #1");
								trace_rec_3();
							}
						work_use_ct[49]++;

						strcpy(a_string, "         LARL  R8,C370ZERO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #2");
								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #3");
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
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #5");
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
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #6");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #7");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
                           		 	strcat(a_string, field3a);
                            		strcpy(wk_remark, " ");
                            		strcat(wk_remark, field3);
                            		strcat(wk_remark, " */");
                            		write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #8");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #9");
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
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #10");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #11");
								trace_rec_3();
							}
						work_use_ct[49]++;
	
						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #12");
								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #13");
								trace_rec_3();
							}

						strcpy(a_string, "         LA    R6,");
						strcat(a_string, field6);
						strcat(a_string, "(R0,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #14");
								trace_rec_3();
							}

						strcpy(a_string, "         JLU   ");
						strcat(a_string, "L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
						strcat(a_string, wk_strg);
						strcat(a_string, "G");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #15");
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
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #16");
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
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #17");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #18");
								trace_rec_3();
							}
					}

				if(x10 == 0)
					{
						if(fn_ct > 0)
							{
								x3 = 0;
								for(I=0; I < fn_ct; I++)
									{
										ret = strcmp(field2, w_function[I].fn_name);
										if(ret == 0)
											{
												x3 = 1;
												strcpy(field2a, w_function[I].fn_cname);
												strcpy(field4, w_function[I].fn_ret_var);
											}
									}	
							}

						if(x3 == 0)
							{
								printf("c2z_math.c c2_math_2 E-299 field2 function Not Found\n");
								c2_error();
							}

						strcpy(wk_sv_func, field2);
						strcpy(field5,field3);

						x5 = 0;
 						if(lv_ct > 0)
							{
								for(I = 0; I < lv_ct; I++)
									{
										ret = strcmp(field5, lw_variable[I].lv_name);
										ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{	
												x5 = 1;
												strcpy(field5a, lw_variable[I].lv_cname);
												lw_variable[I].lv_use_ct++;
											}
									}
							}
				
						if(x5 == 0)
							{
								if(gv_ct > 0)
									{
										for(I = 0; I < gv_ct; I++)
											{
												ret = strcmp(field5, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x5 = 1;
														strcpy(field5a, gw_variable[I].gv_cname);
														gw_variable[I].gv_use_ct++;
													}
											}
									}
							}

						if(x5 == 0)
							{
								printf("c2z_math.c c2_math_2 2 & 1 E-300 field3 Not Found = %s\n",field3);
								c2_error();
							}

						x5 = 0;
 						if(lv_ct > 0)
							{
								for(I = 0; I < lv_ct; I++)
									{
										ret = strcmp(field1, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{	
												x5 = 1;
												strcpy(field1a, lw_variable[I].lv_cname);
												lw_variable[I].lv_use_ct++;
											}
									}
							}
				
						if(x5 == 0)
							{
								if(gv_ct > 0)
									{
										for(I = 0; I < gv_ct; I++)
											{
												ret = strcmp(field1, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x5 = 1;
														strcpy(field1a, gw_variable[I].gv_cname);
														gw_variable[I].gv_use_ct++;
													}
											}
									}
							}

						if(x5 == 0)
							{
								printf("c2z_math.c c2_math_2 2 & 1 E-301 field1 Not Found = %s\n",field1);
								c2_error();
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field5a);
                            		strcpy(wk_remark, " ");
						strcat(wk_remark, field5);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #19");
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
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #20");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #21");
								trace_rec_3();
							}

						strcpy(a_string, "         BRASL C370LNK,");
						strcat(a_string,field2a);
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #22");
								trace_rec_3();
							}

						x5 = 0;
 						if(lv_ct > 0)
							{
								for(I = 0; I < lv_ct; I++)
									{
										ret = strcmp(field4, lw_variable[I].lv_name);
										ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{	
												x5 = 1;
												strcpy(field4a, lw_variable[I].lv_cname);
												lw_variable[I].lv_use_ct++;
											}
									}
							}
				
						if(x5 == 0)
							{
								if(gv_ct > 0)
									{
										for(I = 0; I < gv_ct; I++)
											{
												ret = strcmp(field4, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x5 = 1;
														strcpy(field4a, gw_variable[I].gv_cname);
														gw_variable[I].gv_use_ct++;
													}
											}
									}
							}

						if(x5 == 0)
							{
								printf("c2z_math.c c2_math_2 2 & 1 E-302 field4 Not Found = %s\n",field4);
								c2_error();
							}

						x5 = 0;
 						if(lv_ct > 0)
							{
								for(I = 0; I < lv_ct; I++)
									{
										ret = strcmp(field1, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{	
												x5 = 1;
												strcpy(field1a, lw_variable[I].lv_cname);
												lw_variable[I].lv_use_ct++;
											}
									}
							}

						if(x5 == 0)
							{
								if(gv_ct > 0)
									{
										for(I = 0; I < gv_ct; I++)
											{
												ret = strcmp(field1, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x5 = 1;
														strcpy(field1a, gw_variable[I].gv_cname);
														gw_variable[I].gv_use_ct++;
													}
											}
									}
							}

						if(x5 == 0)
							{
								printf("c2_math_2 2 & 1 E-303 field1 Not Found = %s\n",field1);
								c2_error();
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field1a);
                            		strcpy(wk_remark, " ");
						strcat(wk_remark, field1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #23");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field4a);
                            		strcpy(wk_remark, " ");
						strcat(wk_remark, field4);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #24");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #21");
								trace_rec_3();
							}
					}
			}

		if((fd1_type == 2) && (fd2_type == 3))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2");
						trace_rec_1();
					}
				
				pi = 0;
				ch = p_string[pi];
				while(ch != '[')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ']') 
					{
						field3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field3[pi2] = '\0';

				x5 = 0;
 				if(lv_ct > 0)
					{
						for(I = 0; I < lv_ct; I++)
							{
								ret = strcmp(field3, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{	
										x5 = 1;
										strcpy(field3a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
									}
							}
					}
				
				if(x5 == 0)
					{
						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(field3, gw_variable[I].gv_name);
										if(ret == 0)
											{
												x5 = 1;
												strcpy(field3a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
											}
									}
							}
					}

				if(x5 == 0)
					{
						printf("c2z_math.c c2_math_2 E-304 field3 Not found = %s\n",field3);
						c2_error();
					}

				if(gv_ct > 0)
					{
						field7[0] = '\0';
						field8[0] = '\0';
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(field2, gw_variable[I].gv_name);
								if(ret == 0)
									{
										strcpy(field5, gw_variable[I].gv_dsect);
										strcpy(field6, gw_variable[I].gv_label);
										strcpy(field7, gw_variable[I].gv_table);
										strcpy(field8, gw_variable[I].gv_aname);
										strcpy(field9, gw_variable[I].gv_sv_reg);
										strcpy(field10, gw_variable[I].gv_wk_reg);
										strcpy(field11, gw_variable[I].gv_wk_strg);
									}
							}
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #1");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #2");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R6,");
				strcat(a_string, field7);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #5");
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
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #6");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #7");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,");
                            strcat(a_string, field3a);
                            strcpy(wk_remark, " ");
                            strcat(wk_remark, field3);
                            strcat(wk_remark, " */");
                            write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #8");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #9");
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
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #10");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #11");
						trace_rec_3();
					}
				work_use_ct[49]++;
	
				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #12");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #13");
						trace_rec_3();
					}

				strcpy(a_string, "         LA    R6,");
				strcat(a_string, field6);
				strcat(a_string, "(R0,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #14");
						trace_rec_3();
					}

				strcpy(a_string, "         JLU   ");
				strcat(a_string, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
				strcat(a_string, wk_strg);
				strcat(a_string, "G");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #15");
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
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #16");
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
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #17");
						trace_rec_3();
					}

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #18");
						trace_rec_3();
					}
			}

		if((fd1_type == 1) && (fd2_type == 3))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2");
						trace_rec_1();
					}

				pi = 0;
				ch = p_string[pi];
				while(ch != '[')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ']') 
					{
						field3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field3[pi2] = '\0';

				x5 = 0;
 				if(lv_ct > 0)
					{
						for(I = 0; I < lv_ct; I++)
							{
								ret = strcmp(field3, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{	
										x5 = 1;
										strcpy(field3a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
									}
							}
					}
				
				if(x5 == 0)
					{
						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(field3, gw_variable[I].gv_name);
										if(ret == 0)
											{
												x5 = 1;
												strcpy(field3a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
											}
									}
							}
					}

				if(x5 == 0)
					{
						printf("c2z_math.c c2_math_2 E-305 field3 Not Found = %s\n",field3);
						c2_error();
					}

				if(gv_ct > 0)
					{
						field7[0] = '\0';
						field8[0] = '\0';
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(field2, gw_variable[I].gv_name);
								if(ret == 0)
									{
										strcpy(field5, gw_variable[I].gv_dsect);
										strcpy(field6, gw_variable[I].gv_label);
										strcpy(field7, gw_variable[I].gv_table);
										strcpy(field8, gw_variable[I].gv_aname);
										strcpy(field9, gw_variable[I].gv_sv_reg);
										strcpy(field10, gw_variable[I].gv_wk_reg);
										strcpy(field11, gw_variable[I].gv_wk_strg);
									}
							}
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #1");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #2");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R6,");
				strcat(a_string, field7);
				strcpy(wk_remark," ");
				strcat(wk_remark, field2);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #5");
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
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #6");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #7");
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
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #8");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #9");
						trace_rec_3();
					}
	
				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
				strcat(a_string, wk_strg);
				strcat(a_string, "H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #10");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #11");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #12");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #13");
						trace_rec_3();
					}

				strcpy(a_string, "         LA    R6,");
				strcat(a_string, field6);
				strcat(a_string, "(R0,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #14");
						trace_rec_3();
					}

				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
				strcat(a_string, wk_strg);
				strcat(a_string, "G");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #15");
						trace_rec_3();
					}

				strcpy(a_string, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
				strcat(a_string, wk_strg);
				strcat(a_string, "H");
				check_length();
				strcat(a_string, "DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #16");
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
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #17");
						trace_rec_3();
					}
	
				strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #18");
						trace_rec_3();
					}
			}
	}


void c2_math_5()		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_5");
				trace_rec_1();
			}

		char *p1, *p2, *p3;
		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield5[VAR_LGTH];
		char tfield5a[VAR_LGTH];
		char tfield6a[VAR_LGTH];

		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field8[VAR_LGTH];
		char field9[VAR_LGTH];
		char field10[VAR_LGTH];
		char field11[VAR_LGTH];

		int pi;
		int pi2;
		int x2 = 0;
		int x3 = 0;
		int x80 = 0;
		int m5_3 = 0;
		int m5_6 = 0;
		int m5_7 = 0;
		int m5fd1_type = 0;
		int m5fd2_type = 0;
		int m5fd3_type = 0;
		int I = 0;
		int s = 0;
		int ret = 0;
		int ret1 = 0;

		p1 = strstr(p_string, "[");
		p2 = strstr(p_string, "]");
		p3 = strstr(p_string, ".");

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
												m5fd1_type = 3;									}
									}
							}
					}

				if(m5_3 == 0)
					{
						printf("c2z_math.c c2_math_5 E-310 field1 Not Found = %s\n",field1);
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
								if(isdigit(ch)) 	
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
								printf("c2z_math.c c2_math_5 E-311 field2 Not Found = %s\n",field2);
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

				if(m5fd3_type == 2)
					{
						m5_3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(field3, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										m5_3 = 1;		
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
												m5_3 = 1;		
												strcpy(field3a, gw_variable[I].gv_cname);
											}
									}
							}

						if(m5_3 == 0)
							{		
								printf("c2z_math.c c2_math_5 E-312 field3 Not Found = %s\n",field3);
								c2_error();
							}
					}

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

				if((m5fd1_type == 1) && (m5fd2_type == 2) && (m5fd3_type == 1))
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5");
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
								printf("c2z_math.c c2_math_5 E-313 field1 Not Found = %s\n",field1);
								c2_error();
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
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #10");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370U");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #16");
								trace_rec_3();
							}
						work_use_ct[48]++;

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field2a);
                                         strcpy(wk_remark, " ");
						strcat(wk_remark, field2);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #17");
								trace_rec_3();
							}
						work_use_ct[49]++;

						strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #18");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370U");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #19");
								trace_rec_3();
							}
						work_use_ct[48]++;

						strcpy(a_string, "         CVB   R2,0(R9)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #20");
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
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #21");
								trace_rec_3();
							}

						strcpy(a_string, "         LR    R1,R9");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #22");
								trace_rec_3();
							}

						strcpy(a_string, "         AR    R1,R2"); 
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #23");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370EOF");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #24");
								trace_rec_3();
							}
						work_use_ct[61]++;

						strcpy(a_string, "         MVC   0(R9,R1),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #25");
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
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #26");
								trace_rec_3();
							}

						convert = 1;
							
					}
			}

		if((m5fd1_type == 1) && (m5fd2_type == 2) && (m5fd3_type == 2))
			{
				strcpy(a_string, "         LARL  R9,C370U");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #54");
						trace_rec_3();
					}
				work_use_ct[48]++;
						
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field2a);
				strcpy(wk_remark," ");
				strcat(wk_remark, field2);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #55");
						trace_rec_3();
					}
								
				strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
				strcpy(wk_remark," a[x] = ch ");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #56");
						trace_rec_3();
					}
							
				strcpy(a_string, "         LARL  R9,C370U");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #57");
						trace_rec_3();
					}
				work_use_ct[48]++;

				strcpy(a_string, "         CVB   R2,0(R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #58");
						trace_rec_3();
					}
				work_use_ct[48]++;

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, field1a);
                            strcpy(wk_remark, " ");
                            strcat(wk_remark, field1);
 				strcat(wk_remark, " */");
 				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #59");
						trace_rec_3();
					}
							
				strcpy(a_string, "         LR    R1,R9");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #60");
						trace_rec_3();
					}

				strcpy(a_string, "         AR    R1,R2");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #61");
						trace_rec_3();
					}
						
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field3a);
       			strcpy(wk_remark, " ");
				strcat(wk_remark, field3);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #62");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 #63");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   0(");
				strcat(a_string, "R9,R1),");
				strcat(a_string, "0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #64");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK2");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #65");
						trace_rec_3();
					}
				work_use_ct[50]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #66");
						trace_rec_3();
					}
					
				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #67");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 #68");
						trace_rec_3();
					}

				math_convert = 1;
			}

		if((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 2))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array");
						trace_rec_1();
					}
						
				if(gv_ct > 0)
					{
						field7[0] = '\0';
						field8[0] = '\0';
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(field1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										strcpy(field5, gw_variable[I].gv_dsect);
										strcpy(field6, gw_variable[I].gv_label);
										strcpy(field7, gw_variable[I].gv_table);
										strcpy(field8, gw_variable[I].gv_aname);
										strcpy(field9, gw_variable[I].gv_sv_reg);
										strcpy(field10, gw_variable[I].gv_wk_reg);
										strcpy(field11, gw_variable[I].gv_wk_strg);
									}
							}
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math_c c2_math_5 array #1");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #2");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #3");
						trace_rec_3();
					}
		
				strcpy(a_string, "         LARL  R6,");
                            strcat(a_string, field7);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #4");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 array #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #6");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 array #7");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #8");
						trace_rec_3();
					}

				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
				strcat(a_string, wk_strg);
				strcat(a_string, "H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #9");
						trace_rec_3();
					}

				strcpy(a_string, "         LA    R6,");
				strcat(a_string, field6);
				strcat(a_string, "(R0,R6)");
				strcpy(wk_remark, " ");
				strcat(wk_remark, field6);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #10");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #11");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #12");
						trace_rec_3();
					}

				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #13");
						trace_rec_3();
					}

				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
				strcat(a_string, wk_strg);
				strcat(a_string, "G");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #14");
						trace_rec_3();
					}

				strcpy(a_string, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
				strcat(a_string, wk_strg);
				strcat(a_string, "H");
				check_length();
				strcat(a_string, "DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #15");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, field3a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field3);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #16");
						trace_rec_3();
					}
	
				strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 array #17");
						trace_rec_3();
					}

				convert = 1;
			}

		if((m5fd1_type == 3) && (m5fd2_type == 1) && (m5fd3_type == 1))
			{
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(field1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										strcpy(field5, gw_variable[I].gv_dsect);
										strcpy(field6, gw_variable[I].gv_label);
										strcpy(field7, gw_variable[I].gv_table);
										strcpy(field8, gw_variable[I].gv_aname);
										strcpy(field9, gw_variable[I].gv_sv_reg);
										strcpy(field10, gw_variable[I].gv_wk_reg);
										strcpy(field11, gw_variable[I].gv_wk_strg);
									}
							}
					}

				for(I=0; I < lit_ct; I++)
					{
						if((w_literal[I].lit_rct == rct) && (w_literal[I].lit_uct == 1))
							{
								strcpy(field2a,w_literal[I].lit_use_cname);	
							}
					}

				for(I=0; I < lit_ct; I++)
					{
						if((w_literal[I].lit_rct == rct) && (w_literal[I].lit_uct == 2))
							{
								strcpy(field3a,w_literal[I].lit_use_cname);	
							}
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math_c c2_math_5 #100");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #101");
 						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #102");
 						trace_rec_3();
					}
		
				strcpy(a_string, "         LARL  R6,");
                            strcat(a_string, field7);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #103");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 #104");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math_c c2_math_5 #105");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,");
                            strcat(a_string, field2a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #106");
 						trace_rec_3();
					}
 
				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #107");
 						trace_rec_3();
					}

				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
				strcat(a_string, wk_strg);
				strcat(a_string, "B");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #108");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math_c c2_math_5 #109");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #110");
 						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #111");
 						trace_rec_3();
					}

				strcpy(a_string, "         LA    R6,");
				strcat(a_string, field6);
				strcat(a_string, "(R0,R6)");
				strcpy(wk_remark, " ");
				strcat(wk_remark, field6);
				strcat(wk_remark, " */");
				write_remark();
 				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #112");
 						trace_rec_3();
					}

				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #113");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 #114");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
                            strcat(a_string, field3a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #115");
 						trace_rec_3();
					}

				strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #116");
 						trace_rec_3();
					}

				convert = 1;
			}

		if((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 1))
			{
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(field1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										strcpy(field5, gw_variable[I].gv_dsect);
										strcpy(field6, gw_variable[I].gv_label);
										strcpy(field7, gw_variable[I].gv_table);
										strcpy(field8, gw_variable[I].gv_aname);
										strcpy(field9, gw_variable[I].gv_sv_reg);
										strcpy(field10, gw_variable[I].gv_wk_reg);
										strcpy(field11, gw_variable[I].gv_wk_strg);
									}
							}
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field2, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(field2a, lw_variable[I].lv_cname);	
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
									}
							}
					}
			
				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_5 E-314 field2 Not Found = %s\n",field2);
						c2_error();
					}

				for(I=0; I < lit_ct; I++)
					{
						if((w_literal[I].lit_rct == rct) && (w_literal[I].lit_uct == 1))
							{

								strcpy(field3a,w_literal[I].lit_use_cname);	
							}
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math_c c2_math_5 #200");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #201");
 						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #202");
 						trace_rec_3();
					}
		
				strcpy(a_string, "         LARL  R6,");
                            strcat(a_string, field7);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #203");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 #204");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math_c c2_math_5 #205");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,");
                            strcat(a_string, field2a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #206");
 						trace_rec_3();
					}
 
				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #207");
 						trace_rec_3();
					}

				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
				strcat(a_string, wk_strg);
				strcat(a_string, "B");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #208");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math_c c2_math_5 #209");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #210");
 						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #211");
 						trace_rec_3();
					}

				strcpy(a_string, "         LA    R6,");
				strcat(a_string, field6);
				strcat(a_string, "(R0,R6)");
				strcpy(wk_remark, " ");
				strcat(wk_remark, field6);
				strcat(wk_remark, " */");
				write_remark();
 				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #212");
 						trace_rec_3();
					}

				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #213");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 #214");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
                            strcat(a_string, field3a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #215");
 						trace_rec_3();
					}
					
				strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 #216");
 						trace_rec_3();
					}

				convert = 1;

			}

		if((p1) && (p2) && (p3))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Structure");
						trace_rec_1();
					}

				pi = 0;
				ch = p_string[pi];
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}
				
				pi2 = 0;
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
				while(ch != ' ')
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
								break;
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2z_math_5 Structure E-315 tfield1 Not Found = %s\n",tfield1);
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
						printf("c2z_math.c c2_math_5 E-316 tfield2 Not Found = %s\n",tfield2);
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
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2z_math_5 Structure E-317 tfield1 Not Found = %s\n",tfield1);
						printf("c2z_math.c c2z_math_5 Structure tfield3 Not Found = %s\n",tfield3);
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
									}
							}
					}
			
				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_5 E-318 tfield5 Not Found = %s\n",tfield5);
						c2_error();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #1");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #2");
 						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #3");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R6,");
                            strcat(a_string, tfield1a);
				strcat(a_string, "T");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #4");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #5");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #6");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #7");
 						trace_rec_3();
					}
				
				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #8");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #9");
 						trace_rec_3();
					}

				strcpy(a_string, "         LA    R6,");
				strcat(a_string, tfield6a);
				strcat(a_string, "L");
				strcat(a_string, "(R0,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #10");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #11");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #12");
 						trace_rec_3();
					}
				
				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #13");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #14");
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
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #15");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield5a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #16");
 						trace_rec_3();
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
				strcpy(a_string,"         ZAP   ");
				strcat(a_string, wk_strg);
				strcat(a_string, "(6,R6),0(6,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 Struc #17");
						trace_rec_3();
					}
			}

		convert = 1;
	}

void c2_math_51()		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_51");
				trace_rec_1();
			}

		char *p;
		char ch;

		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field8[VAR_LGTH];
		char field9[VAR_LGTH];
		char field10[VAR_LGTH];
		char field10a[VAR_LGTH];
		char field11[VAR_LGTH];

		int pi;
		int pi2;
		int x2 = 0;
		int x3 = 0;
		int m5_3 = 0;
		int m5_6 = 0;
		int m5_7 = 0;
		int m5_10 = 0;
		int m5fd1_type = 0;
		int m5fd2_type = 0;
		int m5fd3_type = 0;
		int I = 0;
		int s = 0;
		int v = 0;
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
				printf("c2z_math.c c2_math_51 field1 Not Found = %s\n",field1);
				printf("c2z_math.c c2_math_51 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
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
						printf("c2z_math.c c2_math_51 field2Not Found = %s\n",field2);
						printf("c2z_math.c c2_math_51 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
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
		
		p = strstr(field3, "'\0'");
		if((p) && (x3 == 2))		
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_51 field3 ");
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
								m5_10 = lw_variable[I].lv_lgth;
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
										m5_10 = gw_variable[I].gv_lgth;
									}
							}
					}

				if(m5_3 == 0)
					{		
						printf("c2z_math.c c2_math_51 field1 Not Found = %s\n",field1);
						printf("c2z_math.c c2_math_51 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				ret = strcmp("0",field2);
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
								strcpy(trace_1, "c2z_math.c c2_math_51 #1");
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
								strcpy(trace_1, "c2z_math.c c2_math_51 #2");
								trace_rec_3();
							}

						strcpy(a_string, "         XC    ");
						strcat(a_string, "0(");
						snprintf(wk_strg, sizeof(wk_strg), "%d", m5_10);
						strcat(a_string, wk_strg);
						strcat(a_string, ",R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_51 #3");
								trace_rec_3();
							}
						
					}
			
				else
					{
						if(m5fd3_type == 2)
							{

								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2");
										trace_rec_1();
									}

								strcpy(a_string, "         LARL  R9,C370L1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #4");
										trace_rec_3();
									}
								work_use_ct[2]++;

								strcpy(a_string, "         LARL  R8,C370B8");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #5");
										trace_rec_3();
									}
								work_use_ct[52]++;

								strcpy(a_string, "         MVC   ");
								strcat(a_string, "0(R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #6");
										trace_rec_3();
									}
								
								strcpy(a_string, "*         MVC   C370L1,=CL1' '");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #7");
										trace_rec_3();
									}
								
								strcpy(a_string, "         LARL  R9,C370NWK1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #8");
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
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #9");
										trace_rec_3();
									}

								strcpy(a_string, "         ZAP   ");
								strcat(a_string, "0(4,R9),0(4,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #10");
										trace_rec_3();
									}

								for(I=0; I < lit_ct; I++)
									{
										if((w_literal[I].lit_rct == rct) && (w_literal[I].lit_uct == 1))
											{
												strcpy(field10a,w_literal[I].lit_use_cname);	

											}

									}

								strcpy(a_string, "         LARL  R9,C370NWK2");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #11");
										trace_rec_3();
									}
								work_use_ct[50]++;

								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field10a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, field10);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #12");
										trace_rec_3();
									}

								strcpy(a_string, "         ZAP   ");
								strcat(a_string, "0(4,R9),0(4,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #13");
										trace_rec_3();
									}
	
								strcpy(a_string, "         LARL  R9,C370NWK2");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #14");
										trace_rec_3();
									}
								work_use_ct[50]++;

								for(I=0; I < lit_ct; I++)
									{
										if((rct == w_literal[I].lit_rct) && (w_literal[I].lit_uct == 1))
											{
												strcpy(a_string, "         LARL  R8,");
												strcat(a_string, w_literal[I].lit_use_cname);
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #15");
														trace_rec_3();
													}

												
											}
									}

								strcpy(a_string, "         ZAP   ");
								strcat(a_string, "0(4,R9),0(4,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #16");
										trace_rec_3();
									}
								work_use_ct[50]++;

								strcpy(a_string, "L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
								strcat(a_string, wk_strg);
								strcat(a_string, "A");
								check_length();
								strcat(a_string, "DS    0H");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #17");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370NWK1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #18");
										trace_rec_3();
									}
								work_use_ct[49]++;

								strcpy(a_string, "         LARL  R8,C370NWK2");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #19");
										trace_rec_3();
									}
								work_use_ct[50]++;

								strcpy(a_string, "         CP    ");
								strcat(a_string, "0(4,R9),0(4,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #20");
										trace_rec_3();
									}

								strcpy(a_string, "         JLH   L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
								strcat(a_string, wk_strg);
								strcat(a_string, "E");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #21");
										trace_rec_3();
									}
			
								strcpy(a_string, "*         LARL  R9,C370U");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #22");
										trace_rec_3();
									}
								work_use_ct[48]++;

								strcpy(a_string, "         LARL  R8,C370NWK1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #23");
										trace_rec_3();
									}
								work_use_ct[49]++;

								strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #24");
										trace_rec_3();
									}
								
								strcpy(a_string, "         LARL  R9,C370U");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #25");
										trace_rec_3();
									}
								work_use_ct[48]++;

								strcpy(a_string, "*         CVB   R2,0(7,R9)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #26");
										trace_rec_3();
									}
						
								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, field1a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #27");
										trace_rec_3();
									}

								strcpy(a_string, "         LA    R1,R9");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #28");
										trace_rec_3();
									}

								strcpy(a_string, "          AR   R1,R2"); 
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #29");
										trace_rec_3();
									}

								strcpy(a_string, "*         MVI   0(R1),C' '");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #30");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370NWK1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #31");
										trace_rec_3();
									}
								work_use_ct[49]++;

								strcpy(a_string, "         LARL  R9,C370ONE");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #32");
										trace_rec_3();
									}
								work_use_ct[32]++;

								strcpy(a_string, "         AP    0(4,R9),0(4,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #33");
										trace_rec_3();
									}

								strcpy(a_string, "         JLU   L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
								strcat(a_string, wk_strg);
								strcat(a_string, "A");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #34");
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
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #35");
										trace_rec_3();
									}

								convert = 1;
							}

						if(m5fd3_type == 1)
							{
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1");
										trace_rec_1();
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
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #15");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370U");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #16");
										trace_rec_3();
									}
								work_use_ct[48]++;

								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field2a);
                                                        strcpy(wk_remark, " ");
								strcat(wk_remark, field2);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #17");
										trace_rec_3();
									}
								work_use_ct[49]++;

								strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #18");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370U");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #19");
										trace_rec_3();
									}
								work_use_ct[48]++;

								strcpy(a_string, "         CVB   R2,0(4,R9)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #20");
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
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #21");
										trace_rec_3();
									}

								strcpy(a_string, "         LR    R1,R9");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #22");
										trace_rec_3();
									}

								strcpy(a_string, "         AR    R1,R2"); 
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #23");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370B8");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #24");
										trace_rec_3();
									}
								work_use_ct[61]++;

								strcpy(a_string, "         MVC   0(R9,R1),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #25");
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
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #26");
										trace_rec_3();
									}

								convert = 1;
							}
					}

				if((m5fd1_type == 1) && (m5fd3_type == 0))	/* p_string[loc] = '&'	*/
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal ");
								trace_rec_1();
							}
						
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field2a);
						strcpy(wk_remark," ");
						strcat(wk_remark, field2);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #1");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370U");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #1");
								trace_rec_3();
							}
						work_use_ct[48]++;
						
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field2a);
						strcpy(wk_remark," ");
						strcat(wk_remark, field2);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #2");
								trace_rec_3();
							}
								
						strcpy(a_string, "         ZAP   ");
						strcat(a_string, "0(8,R9),0(4,R8)");
						strcpy(wk_remark," a[x] = ch ");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #3");
								trace_rec_3();
							}
						
						strcpy(a_string, "         LARL  R9,C370U");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #5");
								trace_rec_3();
							}
						work_use_ct[48]++;

						strcpy(a_string, "         CVB   R2,0(4,R9)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #6");
								trace_rec_3();
							}
						work_use_ct[48]++;

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field1a);
                                         strcpy(wk_remark, " ");
                                         strcat(wk_remark, field1);
 						strcat(wk_remark, " */");
 						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #7");
								trace_rec_3();
							}
							
						strcpy(a_string, "         LR    R1,R9");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #8");
								trace_rec_3();
							}

						strcpy(a_string, "         AR    R1,R2");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #9");
								trace_rec_3();
							}
						
						for(I=0; I < char_ct; I++)
							{
								if(w_charlit[I].clit_rct == rct)
									{
										strcpy(field3a, w_charlit[I].clit_cname);
                                                 		     	x3 = w_charlit[I].clit_lgth;
									}
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field3a);
                  				strcpy(wk_remark, " ");
						strcat(wk_remark, field3);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #10");
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
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #11");
								trace_rec_3();
							}

						strcpy(a_string, "         MVC   0(");
						strcat(a_string, "R9,R1),");
						strcat(a_string, "0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #12");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK2");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #13");
								trace_rec_3();
							}
						work_use_ct[50]++;

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #14");
								trace_rec_3();
							}
					
						strcpy(a_string, "         AP    0(4,R9),0(4,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #15");
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
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #16");
								trace_rec_3();
							}

						math_convert = 1;

					}

				convert = 1;
			}

		if((!p) && (convert == 0))		/* not a literal 		*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric ");
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
						printf("c2z_math.c c2_math_5 field1 Not Found = %s\n",field1);
						printf("c2z_math.c c2_math_5 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
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
								printf("c2z_math.c c2_math_5 field3 Not Found = %s\n",field3);
								printf("c2z_math.c c2_math_5 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
							}
					}
				else
					{
						strcpy(field3a, field3);
					}

				if(m5fd1_type != 3)	
					{
						if(m5fd2_type != 1)
							{
								strcpy(a_string, "         LARL  R9,C370U");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #1");
										trace_rec_3();
									}
								work_use_ct[48]++;
						
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field2a);
								strcpy(wk_remark," ");
								strcat(wk_remark, field2);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #2");
										trace_rec_3();
									}
								
								strcpy(a_string, "         ZAP   ");
								strcat(a_string, "0(8,R9),0(4,R8)");
								strcpy(wk_remark," a[x] = ch ");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #3");
										trace_rec_3();
									}
							}

						strcpy(a_string, "         LARL  R9,C370U");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #4");
								trace_rec_3();
							}
						work_use_ct[48]++;

						strcpy(a_string, "         CVB   R2,0(4,R9)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #5");
								trace_rec_3();
							}
						work_use_ct[48]++;

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field1a);
                                         strcpy(wk_remark, " ");
                                         strcat(wk_remark, field1);
 						strcat(wk_remark, " */");
 						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #6");
								trace_rec_3();
							}
							
						strcpy(a_string, "         LR    R1,R9");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #7");
								trace_rec_3();
							}

						strcpy(a_string, "         AR    R1,R2");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #8");
								trace_rec_3();
							}
						
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field3a);
                  				strcpy(wk_remark, " ");
						strcat(wk_remark, field3);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_nath.c c2_math_5 field3 numeric #9");
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
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #10");
								trace_rec_3();
							}

						strcpy(a_string, "         MVC   0(");
						strcat(a_string, "R9,R1),");
						strcat(a_string, "0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #11");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK2");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #12");
								trace_rec_3();
							}
						work_use_ct[50]++;

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #13");
								trace_rec_3();
							}
					
						strcpy(a_string, "         AP    0(4,R9),0(4,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #14");
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
								strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #15");
								trace_rec_3();
							}

						math_convert = 1;
					}	


				if(m5fd1_type == 3)		/* array processing		*/
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array");
								trace_rec_1();
							}

						if(gv_ct > 0)
							{
								field7[0] = '\0';
								field8[0] = '\0';
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(field1, gw_variable[I].gv_name);
										if(ret == 0)
											{
												strcpy(field5, gw_variable[I].gv_dsect);
												strcpy(field6, gw_variable[I].gv_label);
												strcpy(field7, gw_variable[I].gv_table);
												strcpy(field8, gw_variable[I].gv_aname);
												strcpy(field9, gw_variable[I].gv_sv_reg);
												strcpy(field10, gw_variable[I].gv_wk_reg);
												strcpy(field11, gw_variable[I].gv_wk_strg);
											}
									}
							
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array #1");
 								trace_rec_3();
							}
						work_use_ct[49]++;

						strcpy(a_string, "         LARL  R8,C370ZERO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array #2");
 								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         ZAP   ");
						strcat(a_string, "0(4,R9),0(4,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array #3");
 								trace_rec_3();
							}
						
						strcpy(a_string, "         LARL  R6,");
						strcat(a_string, field7);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array #4");
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
								strcpy(trace_1, "c2z_math.c c2_math_5 array #5");
 								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array #6");
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
								strcpy(trace_1, "c2z_math.c c2_math_5 array #8");
 								trace_rec_3();
							}

						strcpy(a_string, "         CP    ");
						strcat(a_string, "0(4,R9),0(4,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array #8");
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
								strcpy(trace_1, "c2z_math.c c2_math_5 array #9");
 								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array #10");
 								trace_rec_3();
							}
						work_use_ct[49]++;

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array #11");
 								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         AP    ");
						strcat(a_string, "0(4,R9),0(4,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array #12");
 								trace_rec_3();
							}

						strcpy(a_string, "         LA    R6,");
						strcat(a_string, field6);
						strcat(a_string, "(R0,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array #13");
 								trace_rec_3();
							}

						strcpy(a_string, "         JLU   ");
						strcat(a_string, "L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
						strcat(a_string, wk_strg);
						strcat(a_string, "G");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array #14");
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
								strcpy(trace_1, "c2z_math.c c2_math_5 array #15");
 								trace_rec_3();
							}

						if(m5fd3_type == 1)
							{
								for(v=0; v < lit_ct; v++)
									{
										if((rct == w_literal[v].lit_rct) && (w_literal[v].lit_uct == 1)) 
											{
												strcpy(a_string, "         LARL  R8,");
												strcat(a_string, w_literal[v].lit_use_cname);
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_math.c c2_math_5 array #16");
 														trace_rec_3();
													}
											}
									}
							}
						else
							{
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field3a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, field3);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_5 array #16");
 										trace_rec_3();
									}
							}

						strcpy(a_string, "         ZAP   ");
						strcat(a_string, "0(4,R6),0(4,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_5 array #17");
 								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R6,");
						strcat(a_string, field7);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math_c c2_math_5 array #18");
 								trace_rec_3();
							}
					}		
			}	

		convert = 1;
	}


void c2_math_6()		/* procedure call	pi = get_upper(pi,stlen);	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_6");
				trace_rec_1();
			}

		char ch;
		char *p6;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield4[VAR_LGTH];
		char tfield4a[VAR_LGTH];
		char tfield5[VAR_LGTH];
		char tfield5a[VAR_LGTH];
		char tfield6[VAR_LGTH];
		char tfield6a[VAR_LGTH];
		char tfield7[VAR_LGTH];
		char tfield7a[VAR_LGTH];
		char tfield21[VAR_LGTH];
		char tfield21a[VAR_LGTH];
		char tfield22[VAR_LGTH];
		char tfield22a[VAR_LGTH];
		char tfield23[VAR_LGTH];
		char tfield23a[VAR_LGTH];
		
		int pi;
		int pi2;
		int blank_ct = 0;
		int I = 0;
		int x3 = 0;
		int x6 = 0;
		int s = 0;
		int tot_comma = 0;
		int fd1_type = 0;
		int fd3_type = 0;
		int fd4_type = 0;
		int fd5_type = 0;
		int fd6_type = 0;
		int fd21_type = 0;
		int fd22_type = 0;
		int fd23_type = 0;
		int ret = 0;
		int ret1 = 0;
		int ret2 = 0;
				
		char wk_sv_func[VAR_LGTH];

		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == ',')
					{
						tot_comma++;
					}
			}

		blank_ct = 0;
		p6 = strstr(p_string, "()");
		if(p6)
			{
				blank_ct = 1;
			}
			
		if(tot_comma == 0) 
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_6 comma = 0");
						trace_rec_1();
					}

				pi = 0;
				ch = p_string[pi];
				while((ch == ' ') || (ch == '\t') || (ch == '{'))
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
				while(ch != '(')
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
						tfield3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield3[pi2] = '\0';

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		/* found variable */	
								strcpy(tfield1a, lw_variable[I].lv_cname);
								ret = strcmp("I",lw_variable[I].lv_type);
								if(ret == 0)		/* numeric	*/
									{
										fd1_type = 1;
									}
								else
									{		/* alphanumeric	*/
										fd1_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield1, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield1a, gw_variable[I].gv_cname);
										ret = strcmp("I",gw_variable[I].gv_type);
										if(ret == 0)		/* numeric	*/
											{
												fd1_type = 1;
											}
										else
										{		/* alphanumeric	*/
												fd1_type = 2;
										}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 tfield1 Not Found = %s\n",tfield1);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				if(fn_ct > 0)
					{
						x3 = 0;
						for(I=0; I < fn_ct; I++)
							{
								ret = strcmp(tfield2, w_function[I].fn_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(tfield2a, w_function[I].fn_cname);
										strcpy(tfield3, w_function[I].fn_ret_var);
									}
							}	
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 tfield2 (function) Not Found = %s\n",tfield2);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				strcpy(wk_sv_func, tfield2);

				s = strlen(tfield3);

				if(s != 0)
					{
						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(tfield3, lw_variable[I].lv_name);
								ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;		/* found variable */	
										strcpy(tfield3a, lw_variable[I].lv_cname);
										ret = strcmp("I",lw_variable[I].lv_type);
										if(ret == 0)
											{
												fd3_type = 1;
											}
										else
											{
												fd3_type = 2;
											}
									}
							}

						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										x6 = strcmp(tfield3, gw_variable[I].gv_name);
										if(x6 == 0)
											{
												x3 = 1;		/* found variable */	
												strcpy(tfield3a, gw_variable[I].gv_cname);
												ret = strcmp("I",gw_variable[I].gv_type);
												if(ret == 0)
													{
														fd3_type = 1;
													}
												else
													{
														fd3_type = 2;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_math.c c2_math_6 #2 tfield3 Not Found = %s\n",tfield3);
								printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1); 
							}
					}

				if((tot_comma == 0) && (blank_ct == 1))		/*  boolx = sboolterm();	*/
					{
						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield3a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield3);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 zero var #1");
								trace_rec_3();
							}
 
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield1a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 zero var #2");
								trace_rec_3();
							}
	
						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 zero var #3");
								trace_rec_3();
							}

						strcpy(a_string, "         BRASL C370LNK,");
						strcat(a_string,tfield2a);
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 zero var #5");
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
								strcpy(trace_1, "c2z_math.c c2_math_6 zero var #6");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield3a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield3);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 zero var #7");
								trace_rec_3();
							}

						strcpy(a_string,"         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 zero var #8");
								trace_rec_3();
							}
					}

				if((tot_comma == 0) && (blank_ct == 0) && (convert == 0)) 		/* means at least one passed field	*/
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 one var");
								trace_rec_1();
							}

						pi = 0;
						ch = p_string[pi];
						while((ch == ' ') || (ch == '\t') || (ch == '{'))
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

						pi2 = 0;
						while(ch != '(')
							{
								tfield2[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						tfield2[pi2] = '\0';

						if(fn_ct > 0)
							{
								x3 = 0;
								for(I=0; I < fn_ct; I++)
									{
										ret = strcmp(tfield2, w_function[I].fn_name);
										if(ret == 0)
											{
												x3 = 1;
												strcpy(tfield2a, w_function[I].fn_cname);
												strcpy(tfield4, w_function[I].fn_ret_var);
												strcpy(tfield6, w_function[I].fn_fd1);
												strcpy(wk_sv_func, tfield2);
											}
									}	
							}

						pi2 = 0;
						pi++;
						ch = p_string[pi];
						while(ch != ')')
							{
								tfield3[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						tfield3[pi2] = '\0';

						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(tfield1, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;		
										strcpy(tfield1a, lw_variable[I].lv_cname);
										ret = strcmp("I",lw_variable[I].lv_type);
										if(ret == 0)		
											{
												fd1_type = 1;
											}
										else
											{		
												fd1_type = 2;
											}
									}
							}

						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										x6 = strcmp(tfield1, gw_variable[I].gv_name);
										if(x6 == 0)
											{
												x3 = 1;		
												strcpy(tfield1a, gw_variable[I].gv_cname);
												ret = strcmp("I",gw_variable[I].gv_type);
												if(ret == 0)		
													{
														fd1_type = 1;
													}
												else
													{		
														fd1_type = 2;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_math.c c2_math_6 ONE VAR tfield1 Not Found = %s\n",tfield1);
								printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
							}

						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(tfield4, lw_variable[I].lv_name);
								ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;		
										strcpy(tfield4a, lw_variable[I].lv_cname);
										ret = strcmp("I",lw_variable[I].lv_type);
										if(ret == 0)		
											{
												fd1_type = 1;
											}
										else
											{		
												fd1_type = 2;
											}
									}
							}

						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										x6 = strcmp(tfield4, gw_variable[I].gv_name);
										if(x6 == 0)
											{
												x3 = 1;		
												strcpy(tfield4a, gw_variable[I].gv_cname);
												ret = strcmp("I",gw_variable[I].gv_type);
												if(ret == 0)		
													{
														fd1_type = 1;
													}
												else
													{		
														fd1_type = 2;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_math.c c2_math_6 ONE VAR ERROR tfield4 Not Found = %s\n",tfield4);
								printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
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
										ret = strcmp("I",lw_variable[I].lv_type);
										if(ret == 0)		
											{
												fd3_type = 1;
											}
										else
											{		
												fd3_type = 2;
											}
									}
							}

						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										x6 = strcmp(tfield3, gw_variable[I].gv_name);
										if(x6 == 0)
											{
												x3 = 1;		
												strcpy(tfield3a, gw_variable[I].gv_cname);
												ret = strcmp("I",gw_variable[I].gv_type);
												if(ret == 0)		
													{
														fd3_type = 1;
													}
												else
													{		
														fd3_type = 2;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_math.c c2_math_6 ONE VAR ERROR tfield3 Not Found = %s\n",tfield1);
								printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
							}
									
						x3 = 0;		
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(tfield3, lw_variable[I].lv_name);
								ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;		
										strcpy(tfield5a, lw_variable[I].lv_cname);
										ret = strcmp("I",lw_variable[I].lv_type);
										if(ret == 0)		
											{
												fd5_type = 1;
											}
										else
											{		
												fd5_type = 2;
											}
									}
							}

						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										x6 = strcmp(tfield3, gw_variable[I].gv_name);
										if(x6 == 0)
											{
												x3 = 1;		
												strcpy(tfield5a, gw_variable[I].gv_cname);
												ret = strcmp("I",gw_variable[I].gv_type);
												if(ret == 0)		
													{
														fd5_type = 1;
													}
												else
													{		
														fd5_type = 2;
													}
											}
									}
							}

						x3 = 0;		
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(tfield6, lw_variable[I].lv_name);
								ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;		
										strcpy(tfield6a, lw_variable[I].lv_cname);
										ret = strcmp("I",lw_variable[I].lv_type);
										if(ret == 0)		
											{
												fd6_type = 1;
											}
										else
											{		
												fd6_type = 2;
											}
									}
							}

						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										x6 = strcmp(tfield6, gw_variable[I].gv_name);
										if(x6 == 0)
											{
												x3 = 1;		
												strcpy(tfield6a, gw_variable[I].gv_cname);
												ret = strcmp("I",gw_variable[I].gv_type);
												if(ret == 0)		
													{
														fd6_type = 1;
													}
												else
													{		
														fd6_type = 2;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_math.c c2_math_6 ONE VAR ERROR tfield5 Not Found = %s\n",tfield5);
								printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
							}
		
						if((fd3_type == 1) && (fd5_type == 1))	/* both variable are numeric	*/
							{
								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, tfield5a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, tfield3);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_6 one var #1");
										trace_rec_3();
									}
						
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, tfield3a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, tfield3);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_6 one var #2");
										trace_rec_3();
									}

								strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_6 one var #3");
										trace_rec_3();
									}

								strcpy(a_string, "         BRASL C370LNK,");
								strcat(a_string,tfield2a);
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_6 one var #4");
										trace_rec_3();
									}
							}

						if((fd3_type == 2) && (fd5_type == 2))	/* both variable are character	*/
							{
								strcpy(a_string, "         MVC2  ");
								strcat(a_string, tfield6a);
								strcat(a_string, ",");
								strcat(a_string, tfield3a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_6 one var #7");
										trace_rec_3();
									}

								strcpy(a_string, "         BRASL C370LNK,");
								strcat(a_string,tfield2a);
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_6 one var #8");
										trace_rec_3();
									}
							}

						if((fd3_type == 1) && (fd5_type == 1))	/* both variable are numeric	*/
							{
								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, tfield1a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, tfield1);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_6 one var #9");
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
										strcpy(trace_1, "c2z_math.c c2_math_6 one var #10");
										trace_rec_3();
									}

								strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_6 one var #11");
										trace_rec_3();
									}
							}

						if((fd3_type == 2) && (fd5_type == 2))	/* both variable are characters	*/
							{
								strcpy(a_string, "         MVC2  ");
								strcat(a_string, tfield1a);
								strcat(a_string, ",");
								strcat(a_string, tfield4a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_6 one var #14");
										trace_rec_3();
									}
							}

						convert = 1;
					}
			}

		if((tot_comma == 1) && (blank_ct == 0) && (convert == 0)) 		/* means at least two passed fields	*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_6 two var");
						trace_rec_1();
					}

				pi = 0;
				ch = p_string[pi];
				while((ch == ' ') || (ch == '\t'))
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				while(ch != '=')
					{
						if(ch != ' ')
							{
								if(ch != '{')
									{
										tfield1[pi2] = ch;
										pi2++;
									}
							}
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

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
				while(ch != '(')
					{
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';
				strcpy(wk_sv_func, tfield2);

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ',')
					{
						tfield4[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield4[pi2] = '\0';
				strcpy(tfield6, tfield4);

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
						tfield5[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield5[pi2] = '\0';
				strcpy(tfield7, tfield5);

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield1a, lw_variable[I].lv_cname);
								ret2 = strcmp("I",lw_variable[I].lv_type);
								if(ret2 == 0)		
									{
										fd1_type = 1;
									}
								else
									{		
										fd1_type = 2;
									}
								break;
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield1, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield1a, gw_variable[I].gv_cname);
										ret2 = strcmp("I",gw_variable[I].gv_type);
										if(ret2 == 0)		
											{
												fd1_type = 1;
											}
										else
											{		
												fd1_type = 2;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #0 tfield1 Not Found = %s\n",tfield1);
						printf("c2z_math.c c2_math_6 #0 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield4, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield4a, lw_variable[I].lv_cname);
								ret = strcmp("I",lw_variable[I].lv_type);
								if(ret == 0)		
									{
										fd4_type = 1;
									}
								else
									{		
										fd4_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield4, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield4a, gw_variable[I].gv_cname);
										ret = strcmp("I",gw_variable[I].gv_type);
										if(ret == 0)		
											{
												fd4_type = 1;
											}
										else
											{		
												fd4_type = 2;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #0 tfield4 Not Found = %s\n",tfield4);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
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
								ret = strcmp("I",lw_variable[I].lv_type);
								if(ret == 0)		
									{
										fd5_type = 1;
									}
								else
									{		
										fd5_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield5, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield5a, gw_variable[I].gv_cname);
										ret = strcmp("I",gw_variable[I].gv_type);
										if(ret == 0)		
											{
												fd5_type = 1;
											}
										else
											{		
												fd5_type = 2;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #0 tfield5 Not Found = %s\n",tfield5);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				if(fn_ct > 0)
					{
						x3 = 0;
						for(I=0; I < fn_ct; I++)
							{
								ret = strcmp(tfield2, w_function[I].fn_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(tfield2a, w_function[I].fn_cname);
										strcpy(tfield3, w_function[I].fn_ret_var);
										strcpy(wk_sv_func, tfield2);
										strcpy(tfield6, w_function[I].fn_fd1);
										strcpy(tfield7, w_function[I].fn_fd2);
									}
							}	
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #1 tfield2 function Not Found \n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
				
				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield6, lw_variable[I].lv_name);
						ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield6a, lw_variable[I].lv_cname);
								ret = strcmp("I",lw_variable[I].lv_type);
								if(ret == 0)
									{
										fd6_type = 1;
									}
								else
									{
										fd6_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield6, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield6a, gw_variable[I].gv_cname);
										ret = strcmp("I",gw_variable[I].gv_type);
										if(ret == 0)
											{
												fd6_type = 1;
											}
										else
											{
												fd6_type = 2;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #2 tfield6 Not Found = %s\n",tfield6);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1); 
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield7, lw_variable[I].lv_name);
						ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield7a, lw_variable[I].lv_cname);
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield7, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield7a, gw_variable[I].gv_cname);
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 tfield7 Not Found = %s\n",tfield7);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1); 
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield6a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_6 two var #1");
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
						strcpy(trace_1, "c2z_math.c c2_math_6 two var #2");
						trace_rec_3();
					}
	
				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_6 two var #3");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield7a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield7);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_6 two var #4");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield5a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield5);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_6 two var #5");
						trace_rec_3();
					}

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_6 two var #6");
						trace_rec_3();
					}
				
				strcpy(a_string, "         BRASL C370LNK,");
				strcat(a_string,tfield2a);
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_6 two var #7");
						trace_rec_3();
					}

				if((fd1_type == 1) && (fd3_type == 0))
					{
						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(tfield1, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;		
										strcpy(tfield1a, lw_variable[I].lv_cname);
									}
							}

						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										x6 = strcmp(tfield1, gw_variable[I].gv_name);
										if(x6 == 0)
											{
												x3 = 1;		
												strcpy(tfield1a, gw_variable[I].gv_cname);
											}
									}
							}

						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(tfield3, lw_variable[I].lv_name);
								ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;		
										strcpy(tfield3a, lw_variable[I].lv_cname);
									}
							}

						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										x6 = strcmp(tfield3, gw_variable[I].gv_name);
										if(x6 == 0)
											{
												x3 = 1;		
												strcpy(tfield4a, gw_variable[I].gv_cname);
											}
									}
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield1a);
						strcpy(wk_remark," ");
						strcat(wk_remark, tfield1);
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 two var #8");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield3a);
						strcpy(wk_remark," ");
						strcat(wk_remark, tfield3);
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 two var #9");
								trace_rec_3();
							}

						strcpy(a_string,"         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 two var #10");
								trace_rec_3();
							}
						convert = 1;
					}			

				if((fd1_type == 1) && (fd3_type == 1))
					{
						strcpy(a_string,"         ZAP   ");
						strcat(a_string, tfield1a);
						strcat(a_string, ",");
						strcat(a_string, tfield3a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 two var #11");
								trace_rec_3();
							}
						convert = 1;
					}			

				if((fd1_type == 2) && (fd3_type == 2))
					{
						printf("c2z_math.c c2_math_6  fd1 & fd3 type == 2 NEED TO BE CODED\n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				if((fd1_type == 1) && (fd3_type == 2))
					{
						printf("c2z_math.c c2_math_6 #1 field1 & field3 MISMATCH ERROR\n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				if((fd1_type == 2) && (fd3_type == 1))
					{
						printf("c2z_math.c c2_math_6 #2 field1 & field3 MISMATCH ERROR\n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				convert = 1;
			}		

		if((tot_comma == 2) && (convert == 0)) 		/* means at least three passed fields	*/
			{
				{
					strcpy(trace_1, "c2z_math.c c2_math_6 three var");
					trace_rec_1();
				}

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
				while(ch != '(')
					{
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';
				strcpy(wk_sv_func, tfield2);

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ',')
					{
						tfield4[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield4[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				pi2 = 0;
				while(ch != ',')
					{
						if(ch != ' ')
							{
								tfield5[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield5[pi2] = '\0';

				pi2 = 0;
				while(ch != ')')
					{
						if(ch != ',')
							{
								if(ch != ' ')
									{
										tfield6[pi2] = ch;
										pi2++;
									}
							}
						pi++;
						ch = p_string[pi];
					}
				tfield6[pi2] = '\0';

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield1a, lw_variable[I].lv_cname);
								ret = strcmp("I",lw_variable[I].lv_type);
								if(ret == 0)		
									{
										fd1_type = 1;
									}
								else
									{		
										fd1_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield1, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield1a, gw_variable[I].gv_cname);
										ret = strcmp("I",gw_variable[I].gv_type);
										if(ret == 0)		
											{
												fd1_type = 1;
											}
										else
											{		
												fd1_type = 2;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #0 tfield1 Not Found = %s\n",tfield1);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield4, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield4a, lw_variable[I].lv_cname);
								ret = strcmp("I",lw_variable[I].lv_type);
								if(ret == 0)		
									{
										fd4_type = 1;
									}
								else
									{		
										fd4_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield4, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield4a, gw_variable[I].gv_cname);
										ret = strcmp("I",gw_variable[I].gv_type);
										if(ret == 0)		
											{
												fd4_type = 1;
											}
										else
											{		
												fd4_type = 2;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #0 tfield4 Not Found = %s\n",tfield4);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
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
								ret = strcmp("I",lw_variable[I].lv_type);
								if(ret == 0)		
									{
										fd5_type = 1;
									}
								else
									{		
										fd5_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield5, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield5a, gw_variable[I].gv_cname);
										ret = strcmp("I",gw_variable[I].gv_type);
										if(ret == 0)		
											{
												fd5_type = 1;
											}
										else
											{		
												fd5_type = 2;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #0 tfield5 Not Found = %s\n",tfield5);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield6, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield6a, lw_variable[I].lv_cname);
								ret = strcmp("I",lw_variable[I].lv_type);
								if(ret == 0)		
									{
										fd6_type = 1;
									}
								else
									{		
										fd6_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield6, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield6a, gw_variable[I].gv_cname);
										ret = strcmp("I",gw_variable[I].gv_type);
										if(ret == 0)		
											{
												fd6_type = 1;
											}
										else
											{		
												fd6_type = 2;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #0 tfield6 Not Found = %s\n",tfield6);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				if(fn_ct > 0)
					{
						x3 = 0;
						for(I=0; I < fn_ct; I++)
							{
								ret = strcmp(tfield2, w_function[I].fn_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(tfield2a, w_function[I].fn_cname);
										strcpy(tfield3, w_function[I].fn_ret_var);
										strcpy(wk_sv_func, tfield2);
									}
							}	
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #1 tfield2 function Not Found \n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				if(fn_ct > 0)
					{
						x3 = 0;
						for(I=0; I < fn_ct; I++)
							{
								ret = strcmp(wk_sv_func, w_function[I].fn_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(tfield21, w_function[I].fn_fd1);
										strcpy(tfield22, w_function[I].fn_fd2);
										strcpy(tfield23, w_function[I].fn_fd3);
									}
							}	
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #1 tfield2 function Not Found \n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield21, lw_variable[I].lv_name);
						ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield21a, lw_variable[I].lv_cname);
								ret = strcmp("I",lw_variable[I].lv_type);
								if(ret == 0)		
									{
										fd21_type = 1;
									}
								else
									{		
										fd21_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield21, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield21a, gw_variable[I].gv_cname);
										ret = strcmp("I",gw_variable[I].gv_type);
										if(ret == 0)		
											{
												fd21_type = 1;
											}
										else
											{		
												fd21_type = 2;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #0 tfield21 Not Found = %s\n",tfield21);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				if((fd4_type == 1) && (fd21_type == 1))		/* integer to integer	*/
					{
						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield21a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield21);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 three var #1");
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
								strcpy(trace_1, "c2z_math.c c2_math_6 three var #2");
								trace_rec_3();
							}
	
						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 three var #3");
								trace_rec_3();
							}
					}

				if((fd4_type == 1) && (fd21_type == 2))		/* integer to char ERROR	*/
					{
						printf("c2z_math.c c2_math_6 comma = 2 Numeric to Char move ERROR\n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				if((fd4_type == 2) && (fd21_type == 1))		/* char to integer ERROR	*/
					{
						printf("c2z_math.c c2_math_6 comma = 2 Char to Numeric move ERROR\n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
		
				if((fd4_type == 2) && (fd21_type == 2))		/* char to char		*/
					{
						strcpy(a_string, "         MVC2  ");
						strcat(a_string, tfield21a);
						strcat(a_string, ",");
 						strcat(a_string, tfield4a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 three var #4");
								trace_rec_3();
							}
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield22, lw_variable[I].lv_name);
						ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield22a, lw_variable[I].lv_cname);
								ret = strcmp("I",lw_variable[I].lv_type);
								if(ret == 0)		
									{
										fd22_type = 1;
									}
								else
									{		
										fd22_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield22, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield22a, gw_variable[I].gv_cname);
										ret = strcmp("I",gw_variable[I].gv_type);
										if(ret == 0)		
											{
												fd22_type = 1;
											}
										else
											{		
												fd22_type = 2;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #0 tfield22 Not Found = %s\n",tfield22);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				if((fd5_type == 1) && (fd22_type == 1))		/* integer to integer	*/
					{
						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield22a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield22);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 three var #5");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield5a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield5);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 three var #6");
								trace_rec_3();
							}
							
						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 three var #7");
								trace_rec_3();
							}
					}

				if((fd5_type == 1) && (fd22_type == 2))		/* integer to char ERROR	*/
					{
						printf("c2z_math.c c2_math_6 comma = 2 Numeric to Char move ERROR\n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				if((fd5_type == 2) && (fd22_type == 1))		/* char to integer ERROR	*/
					{
						printf("c2z_math.c c2_math_6 comma = 2 Char to Numeric move ERROR\n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
		
				if((fd5_type == 2) && (fd22_type == 2))		/* char to char		*/
					{
						strcpy(a_string, "         MVC2  ");
						strcat(a_string, tfield22a);
						strcat(a_string, ",");
 						strcat(a_string, tfield5a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #12");
								trace_rec_3();
							}
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield23, lw_variable[I].lv_name);
						ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;		
								strcpy(tfield23a, lw_variable[I].lv_cname);
								ret = strcmp("I",lw_variable[I].lv_type);
								if(ret == 0)		
									{
										fd23_type = 1;
									}
								else
									{		
										fd23_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								x6 = strcmp(tfield23, gw_variable[I].gv_name);
								if(x6 == 0)
									{
										x3 = 1;		
										strcpy(tfield23a, gw_variable[I].gv_cname);
										ret = strcmp("I",gw_variable[I].gv_type);
										if(ret == 0)		
											{
												fd23_type = 1;
											}
										else
											{		
												fd23_type = 2;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_6 #0 tfield23 Not Found = %s\n",tfield23);
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				if((fd6_type == 1) && (fd23_type == 1))		/* integer to integer	*/
					{
						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield23a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield6);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #13");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield6a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield6);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #14");
								trace_rec_3();
							}
	
						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #15");
								trace_rec_3();
							}
					}

				if((fd6_type == 1) && (fd23_type == 2))		/* integer to char ERROR	*/
					{
						printf("c2z_math.c c2_math_6 comma = 2 Numeric to Char move ERROR\n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				if((fd6_type == 2) && (fd23_type == 1))		/* char to integer ERROR	*/
					{
						printf("c2z_math.c c2_math_6 comma = 2 Char to Numeric move ERROR\n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
		
				if((fd6_type == 2) && (fd23_type == 2))		/* char to char		*/
					{
						printf("c2z_math.c c2_math_6 comma = 2 Char to Char move NOT CODED\n");
						printf("c2z_math.c c2_math_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				strcpy(a_string, "         BRASL C370LNK,");
				strcat(a_string,tfield2a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield2);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #16");
						trace_rec_3();
					}

				if((fd1_type == 1) && (fd3_type == 1))
					{
						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(tfield1, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;		
										strcpy(tfield1a, lw_variable[I].lv_cname);
									}
							}

						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										x6 = strcmp(tfield1, gw_variable[I].gv_name);
										if(x6 == 0)
											{
												x3 = 1;		
												strcpy(tfield1a, gw_variable[I].gv_cname);
											}
									}
							}

						x3 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(tfield3, lw_variable[I].lv_name);
								ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;		
										strcpy(tfield3a, lw_variable[I].lv_cname);
									}
							}

						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										x6 = strcmp(tfield3, gw_variable[I].gv_name);
										if(x6 == 0)
											{
												x3 = 1;		
												strcpy(tfield4a, gw_variable[I].gv_cname);
											}
									}
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield1a);
						strcpy(wk_remark," ");
						strcat(wk_remark, tfield1);
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #17");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield3a);
						strcpy(wk_remark," ");
						strcat(wk_remark, tfield3);
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #18");
								trace_rec_3();
							}

						strcpy(a_string,"         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #19");
								trace_rec_3();
							}
						
					}			

				if((fd1_type == 2) && (fd3_type == 2))
					{
						printf("c2z_math.c c2_math_6 E-455 fd1 & fd3 type == 2 NEED TO BE CODED\n");
						c2_error();
					}

				if((fd1_type == 1) && (fd3_type == 2))
					{
						printf("c2z_math.c c2_math_6 E-456 field1 & field3 MISMATCH ERROR\n");
						c2_error();
					}

				if((fd1_type == 2) && (fd3_type == 1))
					{
						printf("c2z_math.c c2_math_6 E-457 field1 & field3 MISMATCH ERROR\n");
						c2_error();
					}

				convert = 1;

			}		
	}


void c2_math_7()		/* array equal calling subroutine		iv_stack[ndx] = rdp_set()  	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7");
				trace_rec_1();
			}
		
		int pi;
		int pi2 = 0;
		int x3 = 0;
              int x4 = 0;
		int x6 = 0;
		int I = 0;
              int v = 0;
		int ret = 0;
		int ret1 = 0;

		char ch;
		char ar_field5[12];
		char ar_field6[12];
		char ar_field7[12];
		char ar_field8[12];
		char ar_field9[12];
		char ar_field10[12];
		char ar_field11[12];
		char wk_sv_func[32];

		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field4[VAR_LGTH];
		char field4a[VAR_LGTH];
		char field8a[VAR_LGTH];

		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))

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

		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ']')
			{
				field2[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field2[pi2] = '\0';

		pi++;
		ch = p_string[pi];
		while(ch != '=')

			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != '(')
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

		strcpy(wk_sv_func, field3);

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
						x6 = strcmp(field1, gw_variable[I].gv_name);
						if(x6 == 0)
							{
								x3 = 1;		
								strcpy(field1a, gw_variable[I].gv_cname);	
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_math.c c2_math_7 E-352 field1 Not Found = %s\n",field1);
				c2_error();
			}

		x3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(field2, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						x3 = 1;		
						strcpy(field2a, lw_variable[I].lv_cname);
					}
			}

		if(x3 == 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						x6 = strcmp(field2, gw_variable[I].gv_name);
						if(x6 == 0)
							{
								x3 = 1;		
								strcpy(field2a, gw_variable[I].gv_cname);	
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_math.c c2_math_7 E-353 field2 Not Found = %s\n",field2);
				c2_error();
			}

		x3 = 0;
		for(I=0; I < fn_ct; I++)
			{
				x6 = strcmp(field3, w_function[I].fn_name);
				if(x6 == 0)
					{
						x3 = 1;		
						strcpy(field3a, w_function[I].fn_cname);
						strcpy(field4, w_function[I].fn_ret_var);
					}
			}

		if(x3 == 0)
			{
				printf("c2z_math.c c2_math_7 E-354 field3 function Not Found = %s\n",field3);
				c2_error();
			}

		strcpy(a_string, "         BRASL C370LNK,");
		strcat(a_string,field3a);
		strcpy(wk_remark, " branch   */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #1");
				trace_rec_3();
			}
	
		x3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(field4, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						x3 = 1;		
						strcpy(field8a, lw_variable[I].lv_cname);
					}
			}

		if(x3 == 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						x6 = strcmp(field4, gw_variable[I].gv_name);
						if(x6 == 0)
							{
								x3 = 1;		
								strcpy(field8a, gw_variable[I].gv_cname);
							}
					}
			}

		x3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(field4, lw_variable[I].lv_name);
				ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						x3 = 1;		
						strcpy(field4a, lw_variable[I].lv_cname);
					}
			}

		if(x3 == 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						x6 = strcmp(field4, gw_variable[I].gv_name);
						if(x6 == 0)
							{
								x3 = 1;		
								strcpy(field4a, gw_variable[I].gv_cname);
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_math.c c2_math_7 E-355 field4 Not Found = %s\n",field4);
				c2_error();
			}

		strcpy(a_string, "         LARL  R9,C370NWK2");		/*  store return value back into call sub	*/
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #2");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,");		/* return value from called sub 	*/
		strcat(a_string, field4a);
              strcpy(wk_remark, " ");
		strcat(wk_remark, field4);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #3");
				trace_rec_3();
			}

		strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #4");
				trace_rec_3();
			}

		if(gv_ct > 0)
			{
				for(I = 0; I < gv_ct; I++)
					{
						ret = strcmp(field1, gw_variable[I].gv_name);
						if(ret == 0)
							{
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

		strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #5");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         LARL  R8,C370ZERO");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #6");
				trace_rec_3();
			}
		work_use_ct[32]++;

		strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #7");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R6,");
		strcat(a_string, ar_field7);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #8");
				trace_rec_3();
			}
	
		strcpy(field2, field1);
		strcat(field2, "_rows");

		for(v = 0; v < gv_ct; v++)
			{
				ret = strcmp(field2, gw_variable[v].gv_name);
				if(ret == 0)
					{
						x3 = 1;
						x4 = gw_variable[v].gv_lgth;
					}
			}

		strcpy(a_string, "         LA    R5,");
		snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
		strcat(a_string, wk_strg);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #9");
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
				strcpy(trace_1, "c2z_math.c c2_math_7 #10");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #11");
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
				strcpy(trace_1, "c2z_math.c c2_math_7 #12");
				trace_rec_3();
			}

		strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #13");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #14");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #17");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         LARL  R8,C370ONE");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #18");
				trace_rec_3();
			}
		work_use_ct[33]++;

		strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #19");
				trace_rec_3();
			}

	       strcpy(a_string, "         LA    R6,");
              strcat(a_string, ar_field6);
              strcat(a_string, "(R0,R6)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #20");
				trace_rec_3();
			}

		strcpy(a_string, "         JCTG  R5,");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "G");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #21");
				trace_rec_3();
			}
			
		strcpy(a_string, "         JLU   ");
		strcat(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "F");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #22");
				trace_rec_3();
			}

		strcpy(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
		strcat(a_string, wk_strg);
		strcat(a_string, "H");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #23");
				trace_rec_3();
			}

		x3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(field4, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						x3 = 1;		
						strcpy(field8a, lw_variable[I].lv_cname);
					}
			}

		strcpy(a_string, "         LARL  R9,C370NWK2");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #24");
				trace_rec_3();
			}

		strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_7 #25");
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
				strcpy(trace_1, "c2z_math.c c2_math_7 #26");
				trace_rec_3();
			}

		convert = 1;

	}


void c2_math_9()		/* in_stack[ndx][0] = '\0'		*/
	{

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_9");
				trace_rec_1();
			}
		
		char ch;
	       char fr_type[2];
		char ar_field5[32];
		char ar_field6[32];
		char ar_field7[32];
		char ar_field8[32];
		char ar_field9[32];
		char ar_field10[32];
		char ar_field11[32];

		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field11[VAR_LGTH];
		char field11a[VAR_LGTH];
		
		int pi;
		int pi2;
		int fr_1 = 0;
		int fr_2 = 0;
		int fr_3 = 0;
		int I = 0;
		int v = 0;
		int x2 = 0;
		int ret = 0;
		int ret1 = 0;
		int fd3_type = 0;

		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
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

		fr_3 = 0;
		if(lv_ct > 0)
			{
				for(I = 0; I < lv_ct; I++)
					{
						ret = strcmp(field1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0)) 
							{
								fr_3 = 1;
								strcpy(field1a, lw_variable[I].lv_cname);
								lw_variable[I].lv_use_ct++;
								strcpy(fr_type, lw_variable[I].lv_type);

							}
					}
			}

		if(fr_3 == 0)
			{
				if(gv_ct > 0)
					{
						
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(field1, gw_variable[I].gv_name);
								if(ret == 0) 
									{
										fr_3 = 1;
										strcpy(field1a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;
										strcpy(fr_type, gw_variable[I].gv_type);
									}
							}
					}
			}

		fr_2 = strcmp(fr_type,"A");
		if(fr_2 == 0)
			{
				fr_1 = 3;
				
			}	
			
		fr_2 = strcmp(fr_type,"G");
		if(fr_2 == 0)
			{
				fr_1 = 4;
			}

		fr_2 = strcmp(fr_type,"D");
		if(fr_2 == 0)
			{
				fr_1 = 5;
				printf("c2z_math.c c2_math_9 E-279 fr_2 type not coded\n");
				c2_error();
			}
		
		if(fr_1 == 3)			/* Array A clear	*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_9 array-char");
						trace_rec_1();
					}

				fr_3 = 0;
				if(gv_ct > 0)
					{
						
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(field1, gw_variable[I].gv_name);
								if(ret == 0) 
									{
										fr_3 = 1;
										strcpy(field1a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;
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
				
				fr_3 = 0;
				fr_2 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field11, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								fr_3 = 1;
								strcpy(field11a, lw_variable[v].lv_cname);
							}
					}

				if(fr_3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field11, gw_variable[v].gv_name);
								if(ret == 0)
									{
										fr_3 = 1;
										strcpy(field11a, gw_variable[v].gv_cname);
									}
							}
					}

				if(fr_3 == 0)
					{
						printf("c2z_math.c c2_math_9 E-278 field11 Not Found = %s\n",field11);
						c2_error();
					}

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ']')
					{
						field2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field2[pi2] = '\0';

				x2 = 0;
				pi2 = 0;
				pi++;
				pi++;
				ch = p_string[pi];
				while(ch != ']')
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
						field3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field3[pi2] = '\0';

				fr_3 = 0;
				fr_2 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field2, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								fr_3 = 1;
								strcpy(field2a, lw_variable[v].lv_cname);
							}
					}

				if(fr_3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field2, gw_variable[v].gv_name);
								if(ret == 0)
									{
										fr_3 = 1;
										strcpy(field2a, gw_variable[v].gv_cname);
									}
							}
					}

				if(fr_3 == 0)
					{
						printf("c2z_math.c c2_math_9 E-277 field2 Not Found = %s\n",field2);
						c2_error();
					}

				if(fd3_type == 2)
					{
						fr_3 = 0;
						fr_2 = 0;
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field3, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										fr_3 = 1;
										strcpy(field3a, lw_variable[v].lv_cname);
									}
							}

						if(fr_3 == 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(field3, gw_variable[v].gv_name);
										if(ret == 0)
											{
												fr_3 = 1;
												strcpy(field3a, gw_variable[v].gv_cname);
											}
									}
							}

						if(fr_3 == 0)
							{
								printf("c2z_math.c c2_math_9 E-276 field3 Not Found = %s\n",field3);
								c2_error();
							}

					}
				else
					{
						strcpy(field3a, field3);
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
	
				while(ch != ';')
					{
						pi++;
						ch = p_string[pi];
					}
				
				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_9 #1");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R9,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_9 #2");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         ZAP   0(4,R9),0(4,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_9 #3");
						trace_rec_3();
					}
 
				strcpy(a_string, "         ZAP   C370NWK2,");
				strcat(a_string, field2a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_9 #4");
						trace_rec_3();
					}
				work_use_ct[50]++;

				strcpy(a_string, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				check_length();
				strcat(a_string, "DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_9 #5");
						trace_rec_3();
					}

				printf("c2z_math.c c2_math_9 E-275 NOT CODED\n");
				c2_error();
			}

		if(fr_1 == 4)			/* Array G clear	*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_9 array_numeric");
						trace_rec_1();
					}

				fr_3 = 0;
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(field1, gw_variable[I].gv_name);
								if(ret == 0) 
									{
										fr_3 = 1;
										strcpy(field1a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;
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

				fr_3 = 0;
				fr_2 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field11, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								fr_3 = 1;
								strcpy(field11a, lw_variable[v].lv_cname);
							}
					}

				if(fr_3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field11, gw_variable[v].gv_name);
								if(ret == 0)
									{
										fr_3 = 1;
										strcpy(field11a, gw_variable[v].gv_cname);
									}
							}
					}

				if(fr_3 == 0)
					{
						printf("c2z_math.c c2_math_9 E-274 field11 Not Found = %s\n",field11);
						c2_error();
					}

				printf("c2z_math.c c2_math_9 E-273 NOT CODED\n");
				c2_error();
			}

		convert = 1;

	}


void c2_math_99()
	{
		if(trace_flag == 1)		
			{
				strcpy(trace_1, "c2z.math.c c2_math_99");
				trace_rec_1();
			}

		int pi;
		int s = 0;
		int I = 0;
		int pi2 = 0;
		int x2 = 0;
		int x3 = 0;
		int x4 = 0;
		int x5 = 0;
		int x10 = 0;
		int x11 = 0;
		int x12 = 0;
		int v = 0;
		int ret = 0;
		int ret1 = 0;
		int eol = 0;
		int fd1I_type = 0;
		int fd3_type = 0;
		int fd5_type = 0;
		int fd7_type = 0;
		int fd9_type = 0;
		int fd11_type = 0;
		int start_parm = 0;
		int stop_parm = 0;
		int start_parm_3 = 0;
		int operand_1 = 0;
		int operand_2 = 0;
		int operand_3 = 0;
		int operand_4 = 0;
				
		char ch;
		char sv_result[VAR_LGTH];
		char sv_result_cname[VAR_LGTH];
		
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field1I[VAR_LGTH];
		char field1Ia[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field4[VAR_LGTH];
		char field5[VAR_LGTH];
		char field5a[VAR_LGTH];
		char field5b[VAR_LGTH];
		char field5c[VAR_LGTH];
		char field5d[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field7a[VAR_LGTH];
		char field8[VAR_LGTH];
		char field9[VAR_LGTH];
		char field9a[VAR_LGTH];
		char field10[VAR_LGTH];
		char field11[VAR_LGTH];
		char field11a[VAR_LGTH];

		char wk_sv_func[VAR_LGTH];

		char *p;

		p = strstr(p_string, "char");
		if(p)
			{
				return;
			}
		
		s = strlen(p_string);
		s--;
		s--;

		pi = 0;
		ch = p_string[pi];
		for(I = 0; I < s; I++)
			{
				if(ch == '[')
					{
						x10 = I;
					}
				if(ch == ']')
					{
						x11 = I;
					}
				if(ch == '=')
					{
						x12 = I;
					}
				pi++;
				ch = p_string[pi];
			}

		s = strlen(p_string);
		s--;
		s--;

		pi = 0;
		ch = p_string[pi];
		for(I = 0; I < s; I++)
			{
				if(ch == '[')
					{
						x10 = I;
					}
				if(ch == ']')
					{
						x11 = I;
					}
				if(ch == '=')
					{
						x12 = I;
					}
				pi++;
				ch = p_string[pi];
			}

		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}
		
		pi2 = 0;
		if((x10 == 0) && (x11 == 0))
			{
				while(ch != ' ')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';
				strcpy(sv_result, field1);
			}
	
		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}
		
		pi2 = 0;
		if((x10 == 0) && (x11 == 0))
			{
				while(ch != ' ')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';
				strcpy(sv_result, field1);
			}

		field1I[0] = '\0';
		if((x10 != 0) && (x11 != 0) && (x12 > x11))
			{
				while(ch != '[')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';
				strcpy(sv_result, field1);
				x2 = 0;
				pi++;
				ch = p_string[pi];
				pi2 = 0;
				while(ch != ']')
					{
						if(x2 == 0)
							{
								if (isalpha(ch))	
									{
    										fd1I_type = 2;
										x2 = 1;
									} 
								if (isdigit(ch)) 	
									{
    										fd1I_type = 1;
										x2 = 1;
									}
							}
						field1I[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1I[pi2] = '\0';
				pi++;
			}
		
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
						start_parm_3 = 1;
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
						field3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
			}
		field3[pi2] = '\0';

		strcpy(a_string, "         LARL  R9,C370MTOT");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_99 #1");
				trace_rec_3();
			}
		work_use_ct[11]++;

		strcpy(a_string, "         LARL  R8,C370ZERO");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_99 #2");
				trace_rec_3();
			}
		work_use_ct[32]++;
		
		strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_99 #3");
				trace_rec_3();
			}
		
		strcpy(a_string, "         LARL  R9,C370PTOT");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_99 #4");
				trace_rec_3();
			}
 		work_use_ct[17]++;

		strcpy(a_string, "         LARL  R8,C370ZERO");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_99 #5");
				trace_rec_3();
			}
		work_use_ct[32]++;
		
		strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_99 #6");
				trace_rec_3();
			}

		if(fd3_type == 1)
			{
				if(start_parm_3 == 0)
					{

						strcpy(a_string, "         LARL  R9,C370M89");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #7");
								trace_rec_3();
							}
						work_use_ct[12]++;

						for(v=0; v < lit_ct; v++)
							{
								if((rct == w_literal[v].lit_rct) && (w_literal[v].lit_uct == 1))
									{
										strcpy(a_string, "         LARL  R8,");
										strcat(a_string, w_literal[v].lit_use_cname);
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_99 #8");
												trace_rec_3();
											}
									}
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #9");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370MTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #10");
								trace_rec_3();
							}
						work_use_ct[11]++;

						strcpy(a_string, "         LARL  R8,C370M89");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #11");
								trace_rec_3();
							}
						work_use_ct[12]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #12");
								trace_rec_3();
							}
					}
			}

		if(fd3_type == 2)
			{
				x3 = 0;
				x2 = 0;
				if(lv_ct > 0)
					{
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
					}

				if(x3 == 0)
					{
						if(gv_ct > 0)
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
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_99 E-272 field3 Not Found = %s\n",field3);
						c2_error();
					}

				if(start_parm_3 == 0)
					{
						strcpy(a_string, "         LARL  R9,C370M89");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #13");
								trace_rec_3();
							}
						work_use_ct[12]++;

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field3a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field3);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #14");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #15");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370MTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #16");
								trace_rec_3();
							}
						work_use_ct[11]++;

						strcpy(a_string, "         LARL  R8,C370M89");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #17");
								trace_rec_3();
							}
						work_use_ct[12]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #18");
								trace_rec_3();
							}
					}

				if(start_parm == 1)
					{
						strcpy(a_string, "         LARL  R9,C370PT1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #19");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field3a);
						strcpy(wk_remark," ");
						strcat(wk_remark, field3);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #20");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #21");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370PTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #22");
								trace_rec_3();
							}
						work_use_ct[17]++;

						strcpy(a_string, "         LARL  R8,C370PT1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #23");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #24");
								trace_rec_3();
							}
						work_use_ct[11]++;
						work_use_ct[18]++;
					}
			}

		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		field4[pi2] = ch;
		pi2++;
		field4[pi2] = '\0';

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
		while((pi < s) && (ch != ' '))
			{
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
								stop_parm = 1;
								pi = s;
								break;
							}
						
					}

				if((ch == '(') && (x4 == 1))
					{
						
					}

				if(ch != ';')
					{
						field5[pi2] = ch;
						pi2++;
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

		if(pi == s)
			{
				eol = 1;
			}

		operand_1 = 0;
		if(operand_1 == 0)
			{
				p = strstr(field4, "+");
				if(p)
					operand_1 = 1;
			}

		if(operand_1 == 0)
			{
				p = strstr(field4, "-");
				if(p)
					operand_1 = 2;
			}
				
		if(operand_1 == 0)
			{
				p = strstr(field4, "*");
				if(p)
					operand_1 = 3;
			}

		if(operand_1 == 0)
			{
				p = strstr(field4, "/");
				if(p)
					operand_1 = 4;
			}

		if((fd5_type == 1) && (start_parm == 0))
			{
				for(v=0; v < lit_ct; v++)
					{
						if((rct == w_literal[v].lit_rct) && (w_literal[v].lit_uct == 2))
							{
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, w_literal[v].lit_use_cname);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_99 #25");
										trace_rec_3();
									}
								break;
							}
					}

				strcpy(a_string, "         LARL  R9,C370M98");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #26");
						trace_rec_3();
					}
				work_use_ct[13]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #27");
						trace_rec_3();
					}
			} 

		if((fd5_type == 1) && (start_parm == 1))
			{
				strcpy(a_string, "         LARL  R9,C370PT2");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #28");
						trace_rec_3();
					}
				work_use_ct[19]++;

				for(v=0; v < lit_ct; v++)
					{
						if((rct == w_literal[v].lit_rct) && (w_literal[v].lit_uct == 2))
							{
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, w_literal[v].lit_use_cname);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_99 #29");
										trace_rec_3();
									}					
							}
					}
				
				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #30");
						trace_rec_3();
					}
				work_use_ct[19]++;
			}

		if(fd5_type == 2)
			{
				x4 = 0;
				p = strstr(field5, "()");
				if(p)
					x4 = 1;		

				if(x4 == 1)			
					{	
						pi2 = 0;	
						x5 = 0;
						ch = field5[x5];
						while(ch != '(')
							{
								field5b[pi2] = ch;
								pi2++;
								x5++;
								ch = field5[x5];
							}
						field5b[pi2] = '\0';
 
						x3 = 0;
						for(v=0; v < fn_ct; v++)
							{
								ret = strcmp(field5b, w_function[v].fn_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(field5c, w_function[v].fn_cname);
										strcpy(field5d, w_function[v].fn_ret_var);
									}
							}

						strcpy(wk_sv_func, field5b);

						if(stop_parm == 1)
							{
								start_parm = 0;
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field5c);
						strcpy(wk_remark," ");
						strcat(wk_remark, field5c);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #31");
								trace_rec_3();
							}

						strcpy(a_string, "         BRASL C370LNK,");
						strcat(a_string, field5c);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #32");
								trace_rec_3();
							}

						x3 = 0;
						x2 = 0;
						if(lv_ct > 0)
							{
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(field5d, lw_variable[v].lv_name);
										ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
										if((ret == 0) && (ret1 == 0))
											{				
												x3 = 1;
												strcpy(field5a, lw_variable[v].lv_cname);
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
												ret = strcmp(field5d, gw_variable[v].gv_name);
												if(ret == 0)
													{				
														x3 = 1;
														strcpy(field5a, gw_variable[v].gv_cname);
														gw_variable[v].gv_use_ct++;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_math.c c2_math_99 E-271 field5d Not Found = %s\n",field5a);
								c2_error();
							}
					}	

				if(x4 == 0)
					{
						x3 = 0;
						x2 = 0;
						if(lv_ct > 0)
							{
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(field5, lw_variable[v].lv_name);
										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if((ret == 0) && (ret1 == 0))
											{				
												x3 = 1;
												strcpy(field5a, lw_variable[v].lv_cname);
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
												ret = strcmp(field5, gw_variable[v].gv_name);
												if(ret == 0)
													{				
														x3 = 1;
														strcpy(field5a, gw_variable[v].gv_cname);
														gw_variable[v].gv_use_ct++;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_math.c c2_math_99 E-270 field5 Not Found = %s\n",field5);
								c2_error();
							}
					}

				if(start_parm == 0)
					{
						strcpy(a_string, "         LARL  R9,C370M98");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #33");
								trace_rec_3();
							}
						work_use_ct[13]++;

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field5a);
						strcpy(wk_remark, " ");
                                  		strcat(wk_remark, field5);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #34");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #35");
								trace_rec_3();
							}
					}

				if(start_parm == 1)
					{
						strcpy(a_string, "         LARL  R9,C370PT2");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #36");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field5a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #37");
								trace_rec_3();
							}

						strcpy(a_string, "        ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #38");
								trace_rec_3();
							}
						work_use_ct[19]++;
					}
			}

		
				x3 = 0;
				x2 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(sv_result, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										x3 = 1;
										strcpy(sv_result_cname, lw_variable[v].lv_cname);
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
										ret = strcmp(sv_result, gw_variable[v].gv_name);
										if(ret == 0)
											{				
												x3 = 1;
												strcpy(sv_result_cname, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_99 E-269 sv_result Not Found = %s\n",sv_result);
						c2_error();
					}

		if(operand_1 == 1)
			{
				/* if(start_parm_5 == 0) */
				if(start_parm == 0)
					{
						strcpy(a_string, "         LARL  R9,C370MTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #39");
								trace_rec_3();
							}
						work_use_ct[11]++;

						strcpy(a_string, "         LARL  R8,C370M98");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #40");
								trace_rec_3();
							}
						work_use_ct[13]++;

						strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #41");
								trace_rec_3();
							}
					}
				
				if(start_parm == 1)
					{
						strcpy(a_string, "         LARL  R9,C370PTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #42");
								trace_rec_3();
							}
						work_use_ct[17]++;

						strcpy(a_string, "         LARL  R8,C370PT2");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #43");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #44");
								trace_rec_3();
							}
					}
			}
	
		if(operand_1 == 2)
			{
				if((start_parm == 0) && (stop_parm == 0))
					{
						strcpy(a_string, "         LARL  R9,C370MTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #45");
								trace_rec_3();
							}
						work_use_ct[11]++;

						strcpy(a_string, "         LARL  R8,C370M89");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #46");
								trace_rec_3();
							}
						work_use_ct[12]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #47");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370MTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #48");
								trace_rec_3();
							}
						work_use_ct[11]++;

						strcpy(a_string, "         LARL  R8,C370M98");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #49");
								trace_rec_3();
							}
						work_use_ct[13]++;

						strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #50");
								trace_rec_3();
							}
					}

				if((start_parm == 1) &&  (stop_parm == 1))
					{
						strcpy(a_string, "         LARL  R9,C370PTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #51");
								trace_rec_3();
							}
						work_use_ct[17]++;

						strcpy(a_string, "         LARL  R8,C370PT1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #52");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #53");
								trace_rec_3();
							}
						
						strcpy(a_string, "         LARL  R9,C370PTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #54");
								trace_rec_3();
							}
						work_use_ct[17]++;

						strcpy(a_string, "         LARL  R8,C370PT2");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #55");
								trace_rec_3();
							}

						strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #56");
								trace_rec_3();
							}
						work_use_ct[11]++;
						work_use_ct[13]++;
					} 
			}

		if(operand_1 == 3)
			{
				strcpy(a_string, "         LARL  R9,C370MTOT");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_math.c c2_math_99 #57");
						trace_rec_3();
					}
				work_use_ct[11]++;

				strcpy(a_string, "         LARL  R8,C370M89");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #58");
						trace_rec_3();
					}
				work_use_ct[12]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #59");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370MTOT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #60");
						trace_rec_3();
					}
				work_use_ct[11]++;

				strcpy(a_string, "         LARL  R8,C370M98");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #61");
						trace_rec_3();
					}
				work_use_ct[13]++;

				strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #62");
						trace_rec_3();
					}
			}

		if(operand_1 == 4)
			{
				strcpy(a_string, "         LARL  R9,C370DEND");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #63");
						trace_rec_3();
					}
				work_use_ct[40]++;

				strcpy(a_string, "         LARL  R8,C370M89");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #64");
						trace_rec_3();
					}
				work_use_ct[12]++;

				strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #65");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370ISOR");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #66");
						trace_rec_3();
					}
				work_use_ct[43]++;

				strcpy(a_string, "         LARL  R8,C370M98");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #67");
						trace_rec_3();
					}
				work_use_ct[13]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #68");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370DEND");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #69");
						trace_rec_3();
					}
				work_use_ct[40]++;

				strcpy(a_string, "         LARL  R8,C370ISOR");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #70");
						trace_rec_3();
					}
				work_use_ct[43]++;

				strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #71");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370MTOT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #72");
						trace_rec_3();
					}
				work_use_ct[11]++;

				strcpy(a_string, "         LARL  R8,C370IENT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #73");
						trace_rec_3();
					}
				work_use_ct[41]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(1,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #74");
						trace_rec_3();
					}
			}	

		if(eol == 1)
			{
				if((start_parm == 0) && (stop_parm == 0))
					{
						if((x10 == 0) && (x11 == 0))	/* no subscript left of the = sign	*/
							{
								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, sv_result_cname);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_99 #75");
										trace_rec_3();
									}
							}

						if((x10 > 0) && (x11 > 0) && (x11 < x12))  /* iv_stack{} = subscript field 1 */
							{
								if(fd1I_type == 1)		/* literal	*/
									{

									}

								if(fd1I_type == 2)		/* variable	*/
									{
										x3 = 0;
										if(lv_ct > 0)
											{
												for(v = 0; v < lv_ct; v++)
													{
														ret = strcmp(field1I, lw_variable[v].lv_name);
														ret1 = strcmp(sv_func, lw_variable[v].lv_func);
														if((ret == 0) && (ret1 == 0))
															{				
																x3 = 1;
																strcpy(field1Ia, lw_variable[v].lv_cname);
																lw_variable[v].lv_use_ct++;
															}
													}
											}

										if(x3 == 0)
											{
												if(gv_ct > 0)
													{
														for(v = 0; v < gv_ct; v++)
															{
																ret = strcmp(field1I, gw_variable[v].gv_name);
																if(ret == 0)
																	{				
																		x3 = 1;
																		strcpy(field1Ia, gw_variable[v].gv_cname);
																		gw_variable[v].gv_use_ct++;
																	}
															}
													}
											}

										if(x3 == 0)
											{
												printf("c2z_math.c c2_math_99 E-268 field1Ia Not Found = %s\n",field1Ia);
												c2_error();
											}

										x3 = 0;
										if(lv_ct > 0)
											{
												for(v = 0; v < lv_ct; v++)
													{
														ret = strcmp(field1, lw_variable[v].lv_func);
														if((ret == 0) && (ret1 == 0))
															{				
																x3 = 1;
																strcpy(field1a, lw_variable[v].lv_cname);
																lw_variable[v].lv_use_ct++;
																
															}
													}
											}

										if(x3 == 0)
											{
												if(gv_ct > 0)
													{
														for(v = 0; v < gv_ct; v++)
															{
																ret = strcmp(field1, gw_variable[v].gv_name);
																if(ret == 0)
																	{				
																		x3 = 1;
																		strcpy(field1a, gw_variable[v].gv_cname);
																		gw_variable[v].gv_use_ct++;
																		strcpy(field5, gw_variable[v].gv_dsect);
																		strcpy(field6, gw_variable[v].gv_label);
																		strcpy(field7, gw_variable[v].gv_table);
																		strcpy(field8, gw_variable[v].gv_aname);
																		strcpy(field9, gw_variable[v].gv_sv_reg);
																		strcpy(field10, gw_variable[v].gv_wk_reg);
																		strcpy(field11, gw_variable[v].gv_wk_strg);
																	}
															}
													}
											}

										if(x3 == 0)
											{
												printf("c2z_math.c c2_math_99 E-267 field1a Not Found = %s\n",field1a);
												c2_error();
											}

										strcpy(a_string, "         LARL  R9,C370NWK1");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math_c c2_math_99 #76");
 												trace_rec_3();
											}
										work_use_ct[49]++;

										strcpy(a_string, "         LARL  R8,C370ZERO");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_99 #77");
 												trace_rec_3();
											}
										work_use_ct[32]++;

										strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_99 #78");
 												trace_rec_3();
											}
		
										strcpy(a_string, "         LARL  R9,");
                            						strcat(a_string, field7);
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_99 #79");
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
												strcpy(trace_1, "c2z_math.c c2_math_99 #80");
 												trace_rec_3();
											}

										strcpy(a_string, "         LARL  R8,C370NWK1");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_99 #81");
 												trace_rec_3();
											}
										work_use_ct[49]++;

										if(fd1I_type == 2)		/* variable */
											{
												strcpy(a_string, "         LARL  R7,");
												strcat(a_string, field1Ia);
                            								strcpy(wk_remark, " ");
                                  								strcat(wk_remark, field1I);
												strcat(wk_remark, " */");
												write_remark();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_math.c c2_math_99 #82");
 														trace_rec_3();
													}
											}

										strcpy(a_string, "         CP    0(6,R8),0(6,R7)");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_99 #83");
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
												strcpy(trace_1, "c2z_math.c c2_math_99 #84");
 												trace_rec_3();
											}

										strcpy(a_string, "         LARL  R8,C370NWK1");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_99 #85");
 												trace_rec_3();
											}
										work_use_ct[49]++;

										strcpy(a_string, "         LARL  R7,C370ONE");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_99 #86");
 												trace_rec_3();
											}
										work_use_ct[32]++;

										strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_99 #87");
 												trace_rec_3();
											}

										strcpy(a_string, "         LA    R9,");
										strcat(a_string, field6);
										strcat(a_string, "(R0,R9)");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_99 #88");
 												trace_rec_3();
											}

										strcpy(a_string, "         JLU   ");
										strcat(a_string, "L");
										snprintf(wk_strg, sizeof(wk_strg), "%d", rct);				
										strcat(a_string, wk_strg);
										strcat(a_string, "G");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_99 #89");
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
												strcpy(trace_1, "c2z_math.c c2_math_99 #90");
 												trace_rec_3();
											}
									}
							}

						strcpy(a_string, "         LARL  R8,C370MTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #91");
								trace_rec_3();
							}
						work_use_ct[11]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #92");
								trace_rec_3();
							}
					}

				if((start_parm == 1) && (stop_parm == 1))
					{
						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, sv_result_cname);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #93");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, "C370PTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #94");
								trace_rec_3();
							}
						work_use_ct[17]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #95");
								trace_rec_3();
							}
						work_use_ct[11]++;

						start_parm = 0;
						stop_parm = 0;
					}

				return;	
			}
			
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		while(ch != ' ')
			{
				field6[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field6[pi2] = '\0';
		
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		x2 = 0;
		pi2 = 0;
		while((pi < s) && (ch != ' '))
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
					}
				if(ch == '(')
					{
						start_parm = 1;
					}
				if(ch == ')')
					{
						stop_parm = 1;
					}
				if((ch != '(') && (ch != ')'))
					{
						field7[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		field7[pi2] = '\0';
	

/*  here now */

	
		if(pi == s)
			{
				eol = 1;
			}

		if(fd7_type == 1)
			{
				if(start_parm == 0)
					{
						strcpy(a_string, "         LARL  R9,C370MT3");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #96");
								trace_rec_3();
							}
						work_use_ct[14]++;

						for(v=0; v < lit_ct; v++)
							{
								if((rct == w_literal[v].lit_rct) && (w_literal[v].lit_uct == 3))
									{
										strcpy(a_string, "         LARL  R8,");
										strcat(a_string, w_literal[v].lit_use_cname);
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_99 #97");
												trace_rec_3();
											}
										break;
									}
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #98");
								trace_rec_3();
							}
					}

				if(start_parm == 1)
					{
						strcpy(a_string, "         LARL  R9,C370PT3");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #99");
								trace_rec_3();
							}
						work_use_ct[20]++;

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field7);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #100");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #101");
								trace_rec_3();
							}
						work_use_ct[20]++;
					}
			}

		if(fd3_type == 2)
			{
				x3 = 0;
				x2 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field7, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										x3 = 1;
										strcpy(field7a, lw_variable[v].lv_cname);
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
										ret = strcmp(field7, gw_variable[v].gv_name);
										if(ret == 0)
											{				
												x3 = 1;
												strcpy(field7a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_99 E-266 field7 Not Found = %s\n",field7);
						c2_error();
					}

				if(start_parm == 0)
					{
						strcpy(a_string, "         LARL  R9,C370MT3");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #101");
								trace_rec_3();
							}
						work_use_ct[14]++;

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field7a);
                                          strcpy(wk_remark, " ");
						strcpy(wk_remark, field7);
						strcpy(wk_remark, " */");
                                          write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #102");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #103");	
								trace_rec_3();
							}
						work_use_ct[14]++;
					}

				if(start_parm == 1)
					{
						strcpy(a_string, "         LARL  R9,C370PT3");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #104");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field7a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #105");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #106");
								trace_rec_3();
							}
						work_use_ct[20]++;
					}
			}
				
		operand_2 = 0;
		if(operand_2 == 0)
			{
				p = strstr(field6, "+");
				if(p)
					operand_2 = 1;
			}

		if(operand_2 == 0)
			{
				p = strstr(field6, "-");
				if(p)
					operand_2 = 2;
			}
				
		if(operand_2 == 0)
			{
				p = strstr(field6, "*");
				if(p)
					operand_2 = 3;
			}

		if(operand_2 == 0)
			{
				p = strstr(field6, "/");
				if(p)
					operand_2 = 4;
			}

		if(operand_2 == 1)
			{
				strcpy(a_string, "         LARL  R9,C370MTOT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #107");
						trace_rec_3();
					}
				work_use_ct[11]++;

				strcpy(a_string, "         LARL  R8,C370MT3");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #108");
						trace_rec_3();
					}
				work_use_ct[14]++;

				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #109");
						trace_rec_3();
					}
			}
	
		if(operand_2 == 2)
			{
				strcpy(a_string, "         LARL  R9,C370MTOT");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_math.c c2_math_99 #110");
						trace_rec_3();
					}
				work_use_ct[11]++;

				strcpy(a_string, "         LARL  R9,C370MT3");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #111");
						trace_rec_3();
					}
				work_use_ct[14]++;

				strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #112");
						trace_rec_3();
					}
			}

		if(operand_2 == 3)
			{
				if((start_parm == 0) && (stop_parm == 0))
					{
						strcpy(a_string, "         LARL  R9,C370MTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #113");
								trace_rec_3();
							}
						work_use_ct[11]++;

						strcpy(a_string, "         LARL  R8,C370MT3");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #114");
								trace_rec_3();
							}
						work_use_ct[14]++;

						strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #115");
								trace_rec_3();
							}
					}

				if(stop_parm == 1)
					{
						strcpy(a_string, "         LARL  R9,C370PTOT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #116");
								trace_rec_3();
							}
						work_use_ct[11]++;

						strcpy(a_string, "         LARL  R9,C370PT3");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #117");
								trace_rec_3();
							}
						work_use_ct[14]++;

						strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_99 #118");
								trace_rec_3();
							}
						work_use_ct[17]++;
						work_use_ct[20]++;
						
						if(operand_1 == 1)
							{
								strcpy(a_string, "         LARL  R9,C370MTOT");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_99 #119");
										trace_rec_3();
									}
								work_use_ct[11]++;

								strcpy(a_string, "         LARL  R8,C370PTOT");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_99 #120");
										trace_rec_3();
									}
								work_use_ct[17]++;

								strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_99 #121");
										trace_rec_3();
									}
							}
						
						start_parm = 0;
						stop_parm = 0;
						start_parm_3 = 0;
					}
			}

		if(operand_2 == 4)
			{
				printf("c2z_math.c c2_math_99 E-265 operand_1 = 4 NOT CODED\n");
				c2_error();
			}	
				
		if(eol == 1)
			{
				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, sv_result_cname);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #122");
						trace_rec_3();
					}
				
				strcpy(a_string, "         LARL  R8,C370MTOT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #123");
						trace_rec_3();
					}
				work_use_ct[11]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #124");
						trace_rec_3();
					}			
				return;	
			}

		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		while(ch != ' ')
			{
				field8[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field8[pi2] = '\0';
						
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		x2 = 0;
		pi2 = 0;
		while((pi < s) && (ch != ' '))
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
					}
				field9[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field9[pi2] = '\0';
		
		if(pi == s)
			{
				eol = 1;
			}

		if(fd9_type == 1)
			{
				strcpy(a_string, "         LARL  R9,C370MT4");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #125");
						trace_rec_3();
					}
				work_use_ct[15]++;

				for(v=0; v < lit_ct; v++)
					{
						if((rct == w_literal[v].lit_rct) && (w_literal[v].lit_uct == 4))
							{
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, w_literal[v].lit_use_cname);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_99 #126");
										trace_rec_3();
									}
								break;
							}
					}

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #127");
						trace_rec_3();
					}
			}

		if(fd3_type == 2)
			{
				x3 = 0;
				x2 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field9, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										x3 = 1;
										strcpy(field9a, lw_variable[v].lv_cname);
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
										ret = strcmp(field9, gw_variable[v].gv_name);
										if(ret == 0)
											{				
												x3 = 1;
												strcpy(field9a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_99 E-264 field9 Not Found = %s\n",field9);
						c2_error();
					}

				strcpy(a_string, "         LARL  R9,C370MT4");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #128");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field9a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #129");
						trace_rec_3();
					}

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #130");
						trace_rec_3();
					}
				work_use_ct[15]++;
			}

		operand_3 = 0;
		if(operand_3 == 0)
			{
				p = strstr(field8, "+");
				if(p)
					operand_3 = 1;
			}

		if(operand_3 == 0)
			{
				p = strstr(field8, "-");
				if(p)
					operand_3 = 2;
			}
				
		if(operand_3 == 0)
			{
				p = strstr(field8, "*");
				if(p)
					operand_3 = 3;
			}

		if(operand_3 == 0)
			{
				p = strstr(field8, "/");
				if(p)
					operand_3 = 4;
			}

		if(operand_3 == 1)
			{
				strcpy(a_string, "         LARL  R9,C370MTOT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #131");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370MT4");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #132");
						trace_rec_3();
					}

				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #133");
						trace_rec_3();
					}

				work_use_ct[11]++;
				work_use_ct[15]++;
			}
	
		if(operand_3 == 2)
			{
				strcpy(a_string, "         LARL  R9,C370MTOT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #134");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370MT4");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #135");
						trace_rec_3();
					}

				strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #136");
						trace_rec_3();
					}
				work_use_ct[11]++;
				work_use_ct[15]++;
			}

		if(operand_3 == 3)
			{
				strcpy(a_string, "         LARL  R9,C370MTOT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #137");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370MT4");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #138");
						trace_rec_3();
					}

				strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #139");
						trace_rec_3();
					}
				work_use_ct[11]++;
				work_use_ct[15]++;
			}

		if(operand_3 == 4)
			{
				printf("c2z_math.c c2_math_99 E-263 operand_3 = 4 NOT CODED\n");
				c2_error();
			}	

		if(eol == 1)
			{
				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, sv_result_cname);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #140");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370MTOT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #141");
						trace_rec_3();
					}

				strcpy(a_string, "        ZAP   0(6,R9),0(6,R8)");
				src_line();
				strcat(a_string, "\n");
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #142");
						trace_rec_3();
					}
	
				strcpy(a_string, "*        ZAP   ");
				strcat(a_string, sv_result_cname);
				strcat(a_string, ",");
				strcat(a_string, "C370MTOT");
				src_line();
				strcat(a_string, "\n");
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #143");
						trace_rec_3();
					}
				work_use_ct[11]++;
				
				return;	
			}

		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		while(ch != ' ')
			{
				field10[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field10[pi2] = '\0';
						
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		x2 = 0;
		pi2 = 0;
		while((pi < s) && (ch != ' '))
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
					}
				field11[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field11[pi2] = '\0';
		
		if(pi == s)
			{
				eol = 1;
			}

		if(fd11_type == 1)
			{
				strcpy(a_string, "         LARL  R9,C370MT5");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #144");
						trace_rec_3();
					}
				work_use_ct[16]++;

				for(v=0; v < lit_ct; v++)
					{
						if((rct == w_literal[v].lit_rct) && (w_literal[v].lit_uct == 5))
							{
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, w_literal[v].lit_use_cname);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_99 #145");
										trace_rec_3();
									}
								break;
							}
					}

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #146");
						trace_rec_3();
					}
			}

		if(fd3_type == 2)
			{
				x3 = 0;
				x2 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field11, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										x3 = 1;
										strcpy(field11a, lw_variable[v].lv_cname);
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
										ret = strcmp(field11, gw_variable[v].gv_name);
										if(ret == 0)
											{				
												x3 = 1;
												strcpy(field11a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_math.c c2_math_99 E-262 field11 Not Found = %s\n",field11);
						c2_error();
					}

				strcpy(a_string, "         LARL  R9,C370MT5");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #147");
						trace_rec_3();
					}
				work_use_ct[16]++;
			
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field11a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field11);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #148");
						trace_rec_3();
					}

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #149");
						trace_rec_3();
					}
			}

		operand_4 = 0;
		if(operand_4 == 0)
			{
				p = strstr(field10, "+");
				if(p)
					operand_4 = 1;
			}

		if(operand_4 == 0)
			{
				p = strstr(field10, "-");
				if(p)
					operand_4 = 2;
			}
				
		if(operand_4 == 0)
			{
				p = strstr(field10, "*");
				if(p)
					operand_4 = 3;
			}

		if(operand_4 == 0)
			{
				p = strstr(field10, "/");
				if(p)
					operand_4 = 4;
			}

		if(operand_4 == 1)
			{
				strcpy(a_string, "         LARL  R9,C370MTOT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #150");
						trace_rec_3();
					}
				work_use_ct[11]++;

				strcpy(a_string, "         LARL  R8,C370MT5");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #151");
						trace_rec_3();
					}
				work_use_ct[16]++;

				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #152");
						trace_rec_3();
					}					
			}
	
		if(operand_4 == 2)
			{
				strcpy(a_string, "         LARL  R9,C370MTOT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #153");
						trace_rec_3();
					}
				work_use_ct[11]++;

				strcpy(a_string, "         LARL  R8,C370MT5");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #154");
						trace_rec_3();
					}
				work_use_ct[16]++;

				strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #155");
						trace_rec_3();
					}
			}

		if(operand_4 == 3)
			{
				strcpy(a_string, "         LARL  R9,C370MTOT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #156");
						trace_rec_3();
					}
				work_use_ct[11]++;

				strcpy(a_string, "         LARL  R8,C370MT5");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #157");
						trace_rec_3();
					}
				work_use_ct[16]++;

				strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #158");
						trace_rec_3();
					}
			}

		if(operand_4 == 4)
			{
				printf("c2z_math.c c2_math_99 E-261 operand_4 = 4 NOT CODED\n");
				c2_error();
			}	

		if(eol == 1)
			{
				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, sv_result_cname);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #159");
						trace_rec_3();
					}
				work_use_ct[11]++;

				strcpy(a_string, "         LARL  R8,C370MTOT");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #160");
						trace_rec_3();
					}
				work_use_ct[16]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_99 #161");
						trace_rec_3();
					}
				work_use_ct[11]++;
				
				return;	
			}

		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		while(ch != ' ')
			{
				pi++;
				ch = p_string[pi];
			}
				
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		while((pi < s) && (ch != ' '))
			{
				pi++;
				ch = p_string[pi];
			}
				
		if(pi == s)
			{
				eol = 1;
			}
	}


/* ***************************************************** 
*  Punch xxx[] = yyy[]                                 *
* **************************************************** */
void c2_math_98()
	{
		check_semi(); 

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_math.c c2_math_98");
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field4[VAR_LGTH];
		char field4a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field8[VAR_LGTH];
		char field9[VAR_LGTH];
		char field10[VAR_LGTH];
		char ar_field5[VAR_LGTH];
		char ar_field6[VAR_LGTH];
		char ar_field7[VAR_LGTH];
		char ar_field8[VAR_LGTH];
		char ar_field9[VAR_LGTH];
		char ar_field10[VAR_LGTH];
		
		int pi;
		int pi2;
		int x2 = 0;
		int x9 = 0;
		int m5_3 = 0;
		int m5_6 = 0;
		int m5_7 = 0;
		int m5fd1_type = 0;
		int m5fd2_type = 0;
		int m5fd3_type = 0;
		int m5fd4_type = 0;
		int I = 0;
		int s = 0;
		int v = 0;
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
								m5fd1_type = 1;
							}
										
						m5_7 = strcmp(lw_variable[I].lv_type, "C");
						if(m5_7 == 0)
				 			{
								m5fd1_type = 2;
							}

						m5_7 = strcmp(lw_variable[I].lv_type, "G");
						if(m5_7 == 0)
							{
								m5fd1_type = 3;
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
										m5fd1_type = 1;
									}
										
								m5_7 = strcmp(gw_variable[I].gv_type, "C");
								if(m5_7 == 0)
				 					{
										m5fd1_type = 2;
									}
			
								m5_7 = strcmp(gw_variable[I].gv_type, "G");
								if(m5_7 == 0)
									{
										m5fd1_type = 3;
									}
								
								strcpy(field5, gw_variable[I].gv_dsect);
								strcpy(field6, gw_variable[I].gv_label);
								strcpy(field7, gw_variable[I].gv_table);
								strcpy(field8, gw_variable[I].gv_aname);
								strcpy(field9, gw_variable[I].gv_sv_reg);
								strcpy(field10, gw_variable[I].gv_wk_reg);
							}
					}
			}

		if(m5_3 == 0)
			{
				printf("c2z_math.c c2_math_98 E-260 field1 Not Found = %s\n",field1);
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
		while((pi < s) && (ch != '['))
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

		m5_3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(field3, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						m5_3 = 1;		
						strcpy(field3a, lw_variable[I].lv_cname);	
						m5_7 = strcmp(lw_variable[I].lv_type, "I");
								if(m5_7 == 0)
				 					{
										m5fd3_type = 1;	
									}
										
								m5_7 = strcmp(lw_variable[I].lv_type, "C");
								if(m5_7 == 0)
				 					{
										m5fd3_type = 2;
									}
								m5_7 = strcmp(lw_variable[I].lv_type, "G");
								if(m5_7 == 0)
									{
										m5fd3_type = 3;
									}
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
										m5_7 = strcmp(gw_variable[I].gv_type, "I");
										strcpy(ar_field5, gw_variable[I].gv_dsect);
										strcpy(ar_field6, gw_variable[I].gv_label);
										strcpy(ar_field7, gw_variable[I].gv_table);
										strcpy(ar_field8, gw_variable[I].gv_aname);
										strcpy(ar_field9, gw_variable[I].gv_sv_reg);
										strcpy(ar_field10, gw_variable[I].gv_wk_reg);
									}
							}
					}

				if(m5_3 == 0)
					{
						printf("c2z_math.c c2_math_98 E-259 field3 Not Found = %s\n",field3);
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
    								m5fd4_type = 2;
								x2 = 1;
							}
 
						if (isdigit(ch)) 	
							{
    								m5fd4_type = 1;
								x2 = 1;
							}
					}
				field4[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field4[pi2] = '\0';
		field4a[0] = '\0';

		if(m5fd4_type == 2)
			{
				m5_3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field4, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								m5_3 = 1;		
								strcpy(field4a, lw_variable[I].lv_cname);	
							}
					}
				
				if(m5_3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								m5_6 = strcmp(field4, gw_variable[I].gv_name);
								if(m5_6 == 0)
									{
										m5_3 = 1;		
										strcpy(field4a, gw_variable[I].gv_cname);		
									}
							}
					}

				if(m5_3 == 0)
					{
						printf("c2z_math.c c2_math_98 E-258 field4 Not Found = %s\n",field4);
						c2_error();
					}
			}


 		if((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 2) && (m5fd4_type == 2))
			{
				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #1");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #2");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R6,");
				strcat(a_string, field7);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #4");
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
						strcpy(trace_1, "c2z_math.c c2_math_98 #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #6");
						trace_rec_3();
					}
				work_use_ct[49]++;

				if(m5fd2_type == 1)		/* numeric literal	*/
					{
						for(v=0; v < lit_ct; v++)
							{
								if((rct == w_literal[v].lit_rct) && (w_literal[v].lit_uct == 1))
									{
										x9 = w_literal[v].lit_use_rct;
										break;
									}
							}

						for(v=0; v < lit_ct; v++)
							{
								if((rct == w_literal[v].lit_rct) && (w_literal[v].lit_uct == 2))
									{
										strcpy(a_string, "         LARL  R8,");
										strcat(a_string, w_literal[v].lit_use_cname);
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_98 #7");
												trace_rec_3();
											}
										break;
									}
							}
					}

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
								printf("c2z_math.c c2_math_98 E-257 field2 Not Found = %s\n",field2);
								c2_error();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field2a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field2);
						strcat(wk_remark, " */ ");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_98 #8");
								trace_rec_3();
							}
					}			
			
				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #9");
						trace_rec_3();
					}

				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #10");
						trace_rec_3();
					}

				strcpy(a_string, "         LA    R6,");
				strcat(a_string, field6);
				strcat(a_string, "(R0,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #11");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #12");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #13");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #14");
						trace_rec_3();
					}
						
				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #15");
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
						strcpy(trace_1, "c2z_math.c c2_math_98 #16");
						trace_rec_3();
					}
	
				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #17");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #18");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #19");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R5,");
				strcat(a_string, ar_field7);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field3);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #20");
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
						strcpy(trace_1, "c2z_math.c c2_math_98 #21");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #22");
						trace_rec_3();
					}
				work_use_ct[49]++;

				if((m5fd4_type == 1) && (m5fd2_type == 1))
					{
						for(v=0; v < lit_ct; v++)
							{
								if(rct == w_literal[v].lit_rct)
									{
										x9 = w_literal[v].lit_use_rct;
									}
							}
					}

				for(v=0; v < lit_ct; v++)
					{
						if(x9 == w_literal[v].lit_rct)
							{
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, w_literal[v].lit_use_cname);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_math.c c2_math_98 #23");
										trace_rec_3();
									}
								break;
							}
					}
			

				if((m5fd4_type == 1) && (m5fd2_type == 2))
					{
						for(v=0; v < lit_ct; v++)
							{
								if(rct == w_literal[v].lit_rct)
									{
										x9 = w_literal[v].lit_use_rct;
										break;
									}
							}

						for(v=0; v < lit_ct; v++)
							{
								if(x9 == w_literal[v].lit_rct)
									{
										strcpy(a_string, "         LARL  R8,");
										strcat(a_string, w_literal[v].lit_use_cname);
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_math.c c2_math_98 #24");
												trace_rec_3();
											}
										break;
									}
							}
					}

				if((m5fd4_type == 2) && (m5fd2_type == 1))
					{
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field4a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field4);
						strcat(wk_remark, " */ ");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_98 #25");
								trace_rec_3();
							}
					}

				if((m5fd4_type == 2) && (m5fd2_type == 2))
					{
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field4a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field4);
						strcat(wk_remark, " */ ");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_math.c c2_math_98 #26");
								trace_rec_3();
							}
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #27");
						trace_rec_3();
					}

				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "C");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #28");
						trace_rec_3();
					}

				strcpy(a_string, "         LA    R5,");
				strcat(a_string, field6);
				strcat(a_string, "(R0,R5)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #29");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #30");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 _99");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #32");
						trace_rec_3();
					}
						
				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "B");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #33");
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
						strcpy(trace_1, "c2z_math.c c2_math_98 #34");
						trace_rec_3();
					}
	
				strcpy(a_string, "         ZAP   0(6,R6),0(6,R5)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_math.c c2_math_98 #35");
						trace_rec_3();
					}

				convert = 1;
			}


		if((m5fd1_type == 2) && (m5fd2_type == 2) && (m5fd3_type == 2) && (m5fd4_type == 2))
			{

				field2a[0] = '\0';
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
						printf("c2z_math.c c2_math_98 E-300 field2 Not Found = %s\n",field2);
						c2_error();
					}

				field4a[0] = '\0';
				m5_3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field4, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								m5_3 = 1;		
								strcpy(field4a, lw_variable[I].lv_cname);	
							}
					}
				
				if(m5_3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								m5_6 = strcmp(field4, gw_variable[I].gv_name);
								if(m5_6 == 0)
									{
										m5_3 = 1;		
										strcpy(field4a, gw_variable[I].gv_cname);		
									}
							}
					}

				if(m5_3 == 0)
					{
						printf("c2z_math.c c2_math_98 E-300 field4 Not Found = %s\n",field4);
						c2_error();
					}
			



printf("\nc2z_math.c c2_math_98 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c c2_math_98 field1 = %s\n",field1);
printf("c2z_math.c c2_math_98 field1a = %s\n",field1a);
printf("c2z_math.c c2_math_98 m5fd1_type = %d\n",m5fd1_type);
printf("c2z_math.c c2_math_98 field2 = %s\n",field2);
printf("c2z_math.c c2_math_98 field2a = %s\n",field2a);
printf("c2z_math.c c2_math_98 m5fd2_type = %d\n",m5fd2_type);
printf("c2z_math.c c2_math_98 field3 = %s\n",field3);
printf("c2z_math.c c2_math_98 field3a = %s\n",field3a);
printf("c2z_math.c c2_math_98 m5fd3_type = %d\n",m5fd3_type);
printf("c2z_math.c c2_math_98 field4 = %s\n",field4);
printf("c2z_math.c c2_math_98 field4a = %s\n",field4a);
printf("c2z_math.c c2_math_98 m5fd4_type = %d\n",m5fd4_type);

				convert = 1;
			}

	}




