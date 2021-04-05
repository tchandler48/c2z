/* ***************************************************
*  c2z : c2z_while.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* *************************************************** 
*  Punch out WHILE statement                         *
* ************************************************** */
void c2_while(void)
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_while.c c2_while");
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
      int x5 = 0;
      int ret = 0;
      int while_test = 0;
    
     while_convert = 0;
     while_opr = 0;
     while_parser_code = 0;
     inside_while = 1;

     s = strlen(p_string);
     for(I=0; I < s; I++)
     {
        ch = p_string[I];
        if(ch == '&')
        {
           x5++;
        }
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
				while_opr = 10;
				while_test = 1;
			}
				
		p = strstr(p_string, "feof");
		if((p) && (while_test == 0))
			{
				while_opr = 9;
				while_test = 1;
			}
	
		p = strstr(p_string, "isalpha");
		if((p) && (while_test == 0))
			{
				while_opr = 8;
				while_test = 1;
			}

		p = strstr(p_string, "isdigit");
		if((p) && (while_test == 0))
			{
				while_opr = 7;
				while_test = 1;
			}

		p = strstr(p_string, "fgets");
		if((p) && (while_test == 0))
			{
				while_opr = 50;
				while_test = 1;
			}

		p = strstr(p_string,"&&");
		if((p) && (while_test == 0))
			{
				while_opr = 98;
				while_test = 1;
			}

		p = strstr(p_string,"||");
		if((p) && (while_test == 0))
			{
				while_opr = 98;
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
				while_opr = 4;
				while_test = 1;
			}
				
		p = strstr(p_string, ">");
		if((p) && (while_test == 0))
			{
				while_opr = 3;
				while_test = 1;
			}
		
		p = strstr(p_string, "!=");
		if((p) && (while_test == 0))
			{
				while_opr = 1;
				while_test = 1;
			}
			
		p = strstr(p_string, "==");
		if((p) && (while_test == 0))
			{
				while_opr = 99;
				while_test = 1;
			}

		 if((while_opr == 99) && (while_convert == 0))		/* while((ch == 1) 		*/
			{
				c2_while_1();
				return;
			} 

		 if((while_opr == 1) && (while_convert == 0))		/* while((ch != '\"') 	*/
			{
				c2_while_2();
				return;
			} 

		if((while_opr == 3) && (while_convert == 0))		/* >	 			*/
			{
				printf("c2z_while.c c2_while E-202 while_opr == 3 Not Coded\n");
				c2_error();
			}

		if((while_opr == 4) && (while_convert == 0))		/* <	 */
			{
				c2_while_4();
				return;
			}

		if((while_opr == 5) && (while_convert == 0) && (while_opr != 98))		/* >=	 */
			{
				c2_while_5();
				return;
			}

		if((while_opr == 6) && (while_convert == 0))		/* <=	 */
			{
				printf("c2z_while.c c2_while E-203 while_opr == 6 Not Coded\n");
				c2_error();
			}

		if((while_opr == 7) && (while_convert == 0))	/* isdigit	*/
			{
				c2_while_7();
				return;
			}	

		if((while_opr == 8) && (while_convert == 0))		/* isalpha	*/
			{
				c2_while_8();
				return;
			}

		if((while_opr == 9)  && (while_convert == 0))		/* feof 	*/
			{
				c2_while_9();
				return;
			}

		if((while_opr == 10) && (while_convert == 0))		/* isupper	*/
			{
				c2_while_10();
				return;
			}	

		if((while_opr == 11) && (while_convert == 0))		/* isspace	*/
			{
				c2_while_11();
				return;
			}

		if((while_opr == 12) && (while_convert == 0))		/* isalnum	*/
			{
				c2_while_12();
				return;
			}

		if((while_opr == 13) && (while_convert == 0))		/* STRCMP	*/
			{
				c2_while_13();
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
				c2_while_14();
				return;
			}

		if((while_opr == 98) && (x5 != 4))
			{
				c2_while_15(); 
				return;
			}

		if((while_opr == 98) && (x5 == 4))
			{
				c2_while_16(); 
				return;
			}
	}	


void c2_while_1()		 /* == */
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_1");
				trace_rec_1();
			}

		int fd1_type = 0;
		int fd3_type = 0;
		int pi;
		int pi2;
		int x2 = 0;
		int x3 = 0;
		int v = 0;
		int I = 0;
		int ret = 0;
		int ret1 = 0;
		int ret2 = 0;

		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];

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

		x3 = 0;
		if(lv_ct > 0)
			{
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(tfield1, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{				
								x3 = 1;
								strcpy(tfield1a, lw_variable[v].lv_cname);
								lw_variable[I].lv_use_ct++;
								ret2 = strcmp("I",lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd1_type = 1;
									}
								ret2 = strcmp("C",lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd1_type = 2;
									}
							}
					}
			}

		if(x3 == 0)
			{
				if(gv_ct > 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(tfield1, gw_variable[v].gv_name);
								if(ret == 0)
									{				
										x3 = 1;
										strcpy(tfield1a, gw_variable[v].gv_cname);
										gw_variable[I].gv_use_ct++;
										ret2 = strcmp("I",gw_variable[v].gv_type);
										if(ret2 == 0)
											{
												fd1_type = 1;
											}
										ret2 = strcmp("C",gw_variable[v].gv_type);
										if(ret2 == 0)
											{
												fd1_type = 2;
											}
									}
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_while.c while_case_1 E-184 tfield1 Not Found = %s\n",tfield1);
				c2_error();
			}

		if(fd3_type == 2)
			{
				x3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield3, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										x3 = 1;
										strcpy(tfield3a, lw_variable[v].lv_cname);
										lw_variable[I].lv_use_ct++;
										ret2 = strcmp("I",lw_variable[v].lv_type);
										if(ret2 == 0)
											{
												fd3_type = 1;
											}
										ret2 = strcmp("C",lw_variable[v].lv_type);
										if(ret2 == 0)
											{
												fd3_type = 2;
											}
									}
							}
					}

				if(x3 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(tfield3, gw_variable[v].gv_name);
										if(ret == 0)
											{				
												x3 = 1;
												strcpy(tfield3a, gw_variable[v].gv_cname);
												gw_variable[I].gv_use_ct++;
												ret2 = strcmp("I",gw_variable[v].gv_type);
												if(ret2 == 0)
													{
														fd3_type = 1;
													}
												ret2 = strcmp("C",gw_variable[v].gv_type);
												if(ret2 == 0)
													{
														fd3_type = 2;
													}
											}
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_while.c while_case_1 E-185 tfield3 Not Found = %s\n",tfield3);
						c2_error();
					}
			}
		
		strcpy(a_string, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcat(a_string, wk_strg);
		check_length();
		strcat(a_string, "DS    0H");
		strcpy(wk_remark, " while-2 */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_1 #1");
				trace_rec_3();
			}
		strcpy(sv_while, wk_strg);

		strcpy(a_string, "         LARL  R9,");
		strcat(a_string, tfield1a);
		strcpy(wk_remark, " ");
		strcat(wk_remark, tfield1);
		strcat(wk_remark, " */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_1 #2");
				trace_rec_3();
			}

		if(fd3_type == 1)
			{
				for(I=0; I < lit_ct; I++)
					{
						if(w_literal[I].lit_rct == rct)
							{
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string,  w_literal[I].lit_use_cname);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_1 #3");
										trace_rec_3();
									}
								break;
							}
					}
			}

		if(fd3_type == 2)
			{
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield3a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield3);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_1 #4");
						trace_rec_3();
					}
			}
	
		if((fd1_type == 1) && (fd3_type == 1))
			{
				strcpy(a_string,"         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_1 #5");
						trace_rec_3();
					}			
			}

		if((fd1_type == 2) && (fd3_type == 2))
			{
				strcpy(a_string,"         CLC   0(R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_1 #6");
						trace_rec_3();
					}			
			}

		strcpy(a_string, "         JNE   L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcat(a_string, wk_strg);
		strcat(a_string,"E");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_1 #7 ");
				trace_rec_3();
			}

		while_convert = 1;
		convert = 1;
	}


void c2_while_2()		 
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_2");
				trace_rec_1();
			}

		char ch;
		char *p, *p1;
		char tfield1[VAR_LGTH];
 		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
	 	char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield5[VAR_LGTH];
		char tfield5a[VAR_LGTH];
		char tfield6[VAR_LGTH];
		char tfield7[VAR_LGTH];
		char tfield7a[VAR_LGTH];

		int pi;
		int pi2;
		int I = 0;
		int x2 = 0;
		int wh_3 = 0;
		int wh_4 = 0;
		int wh_5 = 0;
		int wh_8 = 0;
		int wh_9 = 0;
		int wh_10 = 0;
		int v = 0;
             	int x20 = 0;
		int ret = 0;
		int ret1 = 0;
		int operand_1 = 0;
		int operand_2 = 0;
		int var_ci_1 = 0;
		int var_ci_3 = 0;
		int var_ci_err1 = 0;
		int whfd3_type = 0;
		int whfd5_type = 0;
		int while_complex = 0;
		int cd3_type = 0;

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

		if(while_complex == 0)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_2 simple");
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
						printf("c2z_while.c while_case_2 E-186 simple tfield1 Not Found = %s\n",tfield1);
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
				cd3_type = 0;
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

				if(whfd3_type == 1)
					var_ci_3 = 3;

				p = strstr(tfield3,"\'");
				if(p)
					wh_10 = 1;

				wh_8 = 0;
				p = strstr(tfield3,"\"");
				if(p)
					wh_8 = 1;

				p = strstr(tfield3,"'\0'");
				if(p)
					wh_9 = 1;

				wh_3 = 0;
				if((wh_8 != 1) && (lv_ct > 0) && (whfd3_type != 1) && (wh_10 != 1))
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

				if((wh_3 == 0) && (wh_8 != 1) && (whfd3_type != 1) && (wh_10 != 1))
					{
						printf("c2z_while.c while_case_2 E-187 complex = 0 tfield3 Not Found = %s\n",tfield3);
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

				var_ci_err1 = 0;
				
				strcpy(a_string, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				check_length();
				strcat(a_string, "DS    0H");
				strcpy(wk_remark, " while-2 */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_2 simple #1");
						trace_rec_3();
					}
				strcpy(sv_while, wk_strg);
					
				if(wh_8 == 1)		
					{
						var_ci_err1 = 1;
					}

				x20 = 0;
				if(wh_9 == 1)		/* end of line `	*/
					{
						if(whfd3_type != 0)
							{
								p1 = strstr(p_string, "'\0'");
								if(p1) 
									{
										x20 = 1;
									}
							}
						
						if(x20 == 0)
							{
								for(I=0; I < char_ct; I++)
									{
										if(rct == w_charlit[I].clit_rct)
											{
												strcpy(a_string, "         LARL  R9,");
												strcat(a_string, w_charlit[I].clit_cname);
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2_while_2 simple = 0 #4");
														trace_rec_3();
													}
											}
									}
							}

						if(x20 == 1)
							{
								strcpy(a_string, "         LARL  R9,C370EOF");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_2 simple #5");
										trace_rec_3();
									}
							}
							
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield1a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_2 simple #6");
								trace_rec_3();
							}

						strcpy(a_string, "         CLC   0(1,R9),0(R8)");
						src_line();
    						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_2 simple #7");
								trace_rec_3();
							}

						var_ci_err1 = 1;
					}

				if((var_ci_1 == 2) && (var_ci_3 == 2))		
					{
						strcpy(a_string, "*         CLC   ");
						strcat(a_string, tfield1a);
						strcat(a_string, ",");
						strcat(a_string, tfield3a);
						src_line();
						var_ci_err1 = 1;
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_2 simple #8");
								trace_rec_3();
							}
					}

				if((var_ci_1 == 1) && (var_ci_3 == 3))
					{
						if(whfd3_type == 1)
							{
								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, tfield1a);
                                                        strcpy(wk_remark, " ");
								strcat(wk_remark, tfield1);
								strcat(wk_remark, " */");
								write_remark();
								var_ci_err1 = 1;
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_2 simple #9");
										trace_rec_3();
									}
	
								if(cd3_type != 1)
									{
										strcpy(a_string, "         LARL  R8,C370ZERO");
										src_line();
										var_ci_err1 = 1;
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_while.c c2_while_2 simple #10a");
												trace_rec_3();
											}
										work_use_ct[32]++;
									}

								if(cd3_type == 1)
									{
										for(I=0; I <= lit_ct; I++)
											{
												if(rct == w_literal[I].lit_rct)
													{
														strcpy(tfield3a, w_literal[I].lit_use_cname);	
														break;				
													} 
											}

										strcpy(a_string, "         LARL  R8,");
										strcat(a_string, tfield3a);
										src_line();
										var_ci_err1 = 1;
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_while.c c2_while_2 simple #10b");
												trace_rec_3();
											}
									}

								strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
								src_line();
								var_ci_err1 = 1;
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_2 simple #11");
										trace_rec_3();
									}
							}
						else
							{
								printf("c2z_while.c c2_while_2 E-188 simple ci_1 = 1 & ci_3 = 1 NOT CODED\n");
								c2_error();
							}
					}
	
				if(var_ci_err1 == 0)
					{
						printf("c2z_while.c c2_while_2 E-189 complex = 0 COMPARISON ERROR\n");
						c2_error();
					}
		
				if(operand_1 == 1)		/* ==	*/
					{
						printf("c2z_while.c c2_while_2 E-190 complex = 0operand_1 == Error#1\n");
						c2_error();
					}
				
				if(operand_1 == 2)		/* !=	*/
					{
						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						check_length();
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_2 complex = 0 #12");
								trace_rec_3();
							}
					}

				if(operand_1 == 3)		/* <=	*/
					{
						printf("c2z_while.c c2_while_2 E-191 complex = 0 operand_1 <= Error#3\n");
						c2_error();
					}

				if(operand_1 == 4)		/* >=	*/
					{
						printf("c2z_while.c c2_while_2 E-192 complex = 0 operand_1 >= Error#4\n");
						c2_error();
					}

				if(operand_1 == 5)		/* =	*/
					{
						printf("c2z_while.c c2_while_2 E-194 complex = 0 operand_1 = Error#5\n");
						c2_error();
					}

				if(operand_1 == 6)		/* <	*/
					{
						printf("c2z_while.c c2_while_2 E-195 complex = 0 operand_1 < Error#6\n");
						c2_error();
					}

				if(operand_1 == 7)		/* >	*/
					{
						printf("c2z_while.c c2_while_2 E-196 complex = 0 operand_1 > Error#7\n");
						c2_error();
					}
			}

		if(while_complex == 1)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_2 complex = 1");
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
			
				pi2 = 0;
				while(ch != ')')
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
				
				pi2 = 0;
				while(ch != ' ')
					{
						tfield6[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield6[pi2] = '\0';

				pi++;
				ch = p_string[pi];
				c2_white();
				
				pi2 = 0;
				while(ch != ')')
					{
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
						printf("c2z_while.c while_case_2 E-204 tfield1 Not Found = %s\n",tfield1);
						c2_error();
					}

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
						printf("c2z_while.c while_case_2 E-205 tfield3 Not Found = %s\n",tfield3);
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
								printf("c2z_while.c while_case_2 E-206 tfield5 Not Found = %s\n",tfield5);
								c2_error();
							}
					}

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
						printf("c2z_while.c c2_while_2 E-207 tfield7 Not Found = %s\n",tfield7);
						c2_error();
					}

				operand_2 = 0;
				if(operand_2 == 0)
					{
						p = strstr(tfield6, "==");
						if(p)
							operand_2 = 1;
					}

				if(operand_2 == 0)
					{
						p = strstr(tfield6, "!=");
						if(p)
							operand_2 = 2;
					}
				
				if(operand_2 == 0)
					{
						p = strstr(tfield6, "<=");
						if(p)
							operand_2 = 3;
					}
				
				if(operand_2 == 0)
					{
						p = strstr(tfield6, ">=");
						if(p)
							operand_2 = 4;
					}

				if(operand_2 == 0)
					{
						p = strstr(tfield6, "=");
						if(p)
							operand_2 = 5;
					}

				if(operand_2 == 0)
					{
						p = strstr(tfield6, "<");
						if(p)
							operand_2 = 6;
					}

				if(operand_2 == 0)
					{
						p = strstr(tfield6, ">");
						if(p)
							operand_2 = 7;
					}

				var_ci_err1 = 0;

				strcpy(a_string, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				check_length();
				strcat(a_string, "DS    0H");
				strcpy(wk_remark, " while-2*/");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_2 complex = 1 #1");
						trace_rec_3();
					}
		
				if((var_ci_1 == 2) && (var_ci_3 == 2))		/*  quote in compare	*/
					{

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield1a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_2 complex = 1 #2");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield3a);
						src_line();
						var_ci_err1 = 1;
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_2 complex = 1 #3");
								trace_rec_3();
							}

						strcpy(a_string, "         CLC   0(1,R9),0(R8)");
						src_line();
						var_ci_err1 = 1;
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_2 complex = 1 #4");
								trace_rec_3();
							}
					}

				if((var_ci_1 == 1) && (var_ci_3 == 1))
					{
						printf("c2z_while.c c2_while_2 E-208 ci_1 = 1 & ci_3 = 1 NOT CODED\n");
						c2_error();
					}
	
				if(var_ci_err1 == 0)
					{
						printf("c2z_while.c c2_while_2 E-209 COMPARISON ERROR\n");
						c2_error();
					}
		
				if(operand_1 == 1)		/* ==	*/
					{
						printf("c2z_while.c c2_while_2 E-210 operand_1 == Error#1\n");
						c2_error();
					}
				
				if(operand_1 == 2)		/* !=	*/
					{
						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						check_length();
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_2 complex = 1 #5");
								trace_rec_3();
							}
						
					}

				if(operand_1 == 3)		/* <=	*/
					{
						printf("c2z_while.c c2_while_2 E-211 operand_1 <= Error#3\n");
						c2_error();
					}

				if(operand_1 == 4)		/* >=	*/
					{
						printf("c2z_while.c c2_while_2 E-212 operand_1 >= Error#4\n");
						c2_error();
					}

				if(operand_1 == 5)		/* =	*/
					{
						printf("c2z_while.c c2_while_2 E-213 operand_1 = Error#5\n");
						c2_error();
					}

				if(operand_1 == 6)		/* <	*/
					{
						printf("c2z_while.c c2_while_2 E-214 operand_1 < Error#6\n");
						c2_error();
					}

				if(operand_1 == 7)		/* >	*/
					{
						printf("c2z_while.c c2_while_2 E-215 operand_1 > Error#7\n");
						c2_error();
					}
			}	

		while_convert = 1;
		convert = 1;
	}
					

void c2_while_3()		  /* > */
	{
		printf("c2z_while.c c2_while_3 E-216 NOT CODED\n");
		c2_error();
				
		convert = 1;
	}


void c2_while_4()		  /* < */
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_4");
				trace_rec_1();
			}

		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];

		int pi;
		int pi2;
		int wh_2 = 0;
		int wh_3 = 0;
		int wh_4 = 0;
		int v = 0;
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
		wh_2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ' ')
			{
				tfield1[pi2] = ch;
				pi2++;
				if(wh_2 == 0)
					{
						if (isalpha(ch))	
							{
								wh_2 = 1;
							} 

						if (isdigit(ch)) 	
							{
								wh_2 = 1;
							}
					}
				pi++;
				ch = p_string[pi];
			}
		tfield1[pi2] = '\0';

		pi++;
		ch = p_string[pi];
		while(ch != '<')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		wh_2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ')')
			{
				if(ch != ' ')
					{
						if(wh_2 == 0)
							{
								if (isalpha(ch))	
									{
										wh_2 = 1;
									}
 
								if (isdigit(ch)) 	
									{
										wh_2 = 1;
									}
							}
						tfield2[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		tfield2[pi2] = '\0';

		wh_3 = 0;
		wh_2 = 0;
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
							}
					}
			}

		if(wh_3 == 0)
			{
				wh_2 = 0;
				if(gv_ct > 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								wh_4 = strcmp(tfield1, gw_variable[v].gv_name);
								if(wh_4 == 0)
									{				
										wh_3 = 1;
										strcpy(tfield1a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
									}
							}
					}
			}

		if(wh_3 == 0)
			{
				printf("c2z_while.c while_case_4 E-217 tfield1 Not Found = %s\n",tfield1);
				c2_error();
			}

		wh_3 = 0;
		wh_2 = 0;
		if(lv_ct > 0)
			{
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(tfield2, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{				
								wh_3 = 1;
								strcpy(tfield2a, lw_variable[v].lv_cname);
								lw_variable[v].lv_use_ct++;
							}
					}
			}

		if(wh_3 == 0)
			{
				wh_2 = 0;
				if(gv_ct > 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								wh_4 = strcmp(tfield2, gw_variable[v].gv_name);
								if(wh_4 == 0)
									{				
										wh_3 = 1;
										strcpy(tfield2a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
									}
							}
					}
			}

		if(wh_3 == 0)
			{
				printf("c2z_while.c while_case_4 E-218 tfield2 Not Found = %s\n",tfield2);
				c2_error();
			}

		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcpy(a_string, "L");
		strcat(a_string, wk_strg);
		strcpy(while_tag, a_string);
		check_length();
		strcat(a_string, "DS    0H");
		strcpy(wk_remark," while    */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_4 #1");
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
				strcpy(trace_1, "c2z_while.c c2_while_4 #2");
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
				strcpy(trace_1, "c2z_while.c c2_while_4 #3");
				trace_rec_3();
			}

		strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_4 #4");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcat(a_string, "L");
		strcat(a_string, wk_strg);
		strcat(a_string, "E");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_4 #5");
				trace_rec_3();
			}

		strcpy(a_string, "         JLH   ");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcat(a_string, "L");
		strcat(a_string, wk_strg);
		strcat(a_string, "E");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_4 #6");
				trace_rec_3();
			}

		while_convert = 1;
		convert = 1;
	}


void c2_while_5()		 /* >= */	 
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_5");
				trace_rec_1();
			}

		char ch;
		char *p;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield3a[VAR_LGTH];

		int pi;
		int pi2;
		int ret;
		int ret1;
		int I = 0;
		int x2 = 0;
		int x3 = 0;
		int v = 0;
		int fd1_type = 0;
		int fd3_type = 0;
		int operand_1 = 0;

		pi = 0;
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
						if (isalpha(ch))	
							{
								x2 = 1;
								fd1_type = 1;
							} 

						if (isdigit(ch)) 	
							{
								x2 = 1;
								fd1_type = 2;
							}
					}
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

		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		x2 = 0;
		while(ch != ')')
			{
				if(x2 == 0)
					{
						if (isalpha(ch))	
							{
								x2 = 1;
								fd3_type = 1;
							}
 
						if (isdigit(ch)) 	
							{
								x2 = 1;
								fd3_type = 2;
							}
					}
				pi++;
				ch = p_string[pi];
			}
		
		x3 = 0;
		if(fd1_type == 1)
			{
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield1, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										x3 = 1;
										strcpy(tfield1a, lw_variable[v].lv_cname);
										lw_variable[v].lv_use_ct++;
									}
							}
					}

				if(x3 == 0)
					{
						x3 = 0;
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(tfield1, gw_variable[v].gv_name);
										if(ret == 0)
											{				
												x3 = 1;
												strcpy(tfield1a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
											}
									}
							}
					}
			
				if(x3 == 0)
					{
						printf("c2z_while.c while_case_5 E-219 tfield1 fd1_type == 1 Not Found = %s\n",tfield1);
						c2_error();
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcpy(while_tag, a_string);
				check_length();
				strcat(a_string, "DS    0H");
				strcpy(wk_remark," while    */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_5 #1");
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
						strcpy(trace_1, "c2z_while.c c2_while_5 #2 ");
						trace_rec_3();
					}
			}

		if(fd1_type == 2)
			{
				printf("c2z_while.c while_case_5 E-220 fd1_type == 2 Not Coded\n");
				c2_error();
			}

		if(fd3_type == 1)
			{
				printf("c2z_while.c while_case_5 E-221 fd3_type == 1 Not Coded\n");
				c2_error();
			}
		
		if(fd3_type == 2)
			{
				for(I=0; I < lit_ct; I++)
					{
						if(rct == w_literal[I].lit_rct)
							{
								strcpy(tfield3a, w_literal[I].lit_use_cname);	
								break;				
							} 
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield3a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_5 #3");
						trace_rec_3();
					}
			}

		if((fd1_type == 1) && (fd3_type == 2))
			{
				strcpy(a_string, "         CP     0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_5 #4");
						trace_rec_3();
					}
			}

		if((fd1_type == 1) && (fd3_type == 1))
			{
				printf("c2z_while.c while_case_5 E-222 fd1_type == 1 & fd3_type == 1 Not Coded\n");
				c2_error();
			}

		if((fd1_type == 2) && (fd3_type == 1))
			{
				printf("c2z_while.c while_case_5 E-223 fd1_type == 2 & fd3_type == 1 Not Coded\n");
				c2_error();
			}

		if((fd1_type == 2) && (fd3_type == 2))
			{
				printf("c2z_while.c while_case_5 E-224 fd1_type == 2 & fd3_type == 2 Not Coded\n");
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

		if(operand_1 == 1)		/* ==	*/
			{
				printf("c2z_while.c c2_while_5 E-225 operand_1 == Error#1\n");
				c2_error();
			}

		if(operand_1 == 2)		/* ==	*/
			{
				printf("c2z_while.c c2_while_5 E-226 operand_1 == Error#1\n");
				c2_error();
			}
												
		if(operand_1 == 3)		/* <=	*/
			{
				printf("c2z_while.c c2_while_5 E-227 operand_1 <= Error#3\n")
;				c2_error();
			}

		if(operand_1 == 4)		/* >=	*/
			{
				strcpy(a_string, "         JLL   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_5 #5");
						trace_rec_3();
					}
			}

		if(operand_1 == 5)		/* =	*/
			{
				printf("c2z_while.c c2_while_5 E-228 operand_1 = Error#5\n");
				c2_error();
			}

		if(operand_1 == 6)		/* <	*/
			{
				printf("c2z_while.c c2_while_5 E-229 operand_1 < Error#6\n");
				c2_error();
			}

		if(operand_1 == 7)		/* <	*/
			{
				printf("c2z_while.c c2_while_5 e_230 operand_1 < Error#7\n");
				c2_error();
			}

		while_convert = 1;  
		
		convert = 1;
	}


void c2_while_6()		/* <= */  
	{
	   	while_convert = 1; 	
		printf("c2z_while.c c2_E-473 while_6 ERROR ERROR\n");
		c2_error();
	}


void c2_while_7()		 /* isdigit */	
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_7");
				trace_rec_1();
			}

		char ch;
		char *p, *wkp;
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

		int pi;
		int pi2;
		int x2 = 0;
		int x3 = 0;
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
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcpy(while_tag, a_string);
						check_length();
						strcat(a_string, "DS    0H");
						strcpy(wk_remark," while    */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 #1");
								trace_rec_3();
							}

						wkp = strstr(p_string,"!");
						if(wkp)				
							{
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 NOT = ");
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
								while(ch != ')')
									{
										field1[pi2] = ch;
										pi2++;
										pi++;
										ch = p_string[pi];
									}
								field1[pi2] = '\0';
		
								strcpy(a_string, "         LARL  R9,C370L1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 #2");
										trace_rec_3();
									}
									
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field1);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 #3");
										trace_rec_3();
									}
	
								strcpy(a_string, "         MVC   0(1,R9),0(R8)");
								strcpy(wk_remark, " isdigit  */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 #4");
										trace_rec_3();
									}
								work_use_ct[2]++;

								strcpy(a_string, "         BRASL C370LNK,ISDIGIT");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 #5");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370ISDG");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 #6");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370ONE");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 #7");
										trace_rec_3();
									}

								strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 #8");
										trace_rec_3();
									}
								work_use_ct[31]++;

								strcpy(a_string, "         JLE   ");
								strcat(a_string, o_string);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 #9");
										trace_rec_3();
									}
							}

						if(!wkp)				/* equal test       */
							{
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 EQUAL");
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
								while(ch != ')')
									{
										field3[pi2] = ch;
										pi2++;
										pi++;
										ch = p_string[pi];
									}
								field3[pi2] = '\0';

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
										x2 = 0;
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
										printf("c2z_while.c while_case_7 E-330 field3 Not Found = %s\n",field3);
										c2_error();
									}

								strcpy(a_string, "         LARL  R9,C370L1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 EQUAL #1");
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
										strcpy(trace_1, "c2z_while.c c2_while_7 EQUAL #2");
										trace_rec_3();
									}
								work_use_ct[2]++;

								strcpy(a_string, "         MVC   0(1,R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 EQUAL #3");
										trace_rec_3();
									}

								strcpy(a_string, "         BRASL C370LNK,ISDIGIT");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 EQUAL #4");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370ISDG");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 EQUAL #5");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370ONE");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 EQUAL #6");
										trace_rec_3();
									}

								strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 EQUAL #7");
										trace_rec_3();
									}
								work_use_ct[31]++;

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

								strcpy(a_string, "         JNE   ");
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								strcat(a_string, "E");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_7 EQUAL #8");
										trace_rec_3();
									}
							}
			
						while_convert = 1;		
						convert = 1;
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
								printf("c2z_while.c while_case_7 complex = 0 E_331 short_while = 0 field2 Not Found = %s\n",field2);
								c2_error();
							}

						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcpy(while_tag, a_string);
						check_length();
						strcat(a_string, "DS    0H");
						strcpy(wk_remark," while    */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 Short #1");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370L1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 Short #2");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field2a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field2);
						strcat(wk_remark, " */ ");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 Short #3");
								trace_rec_3();
							}

						strcpy(a_string, "         MVC   0(1,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 Short #4");
								trace_rec_3();
							}
						work_use_ct[2]++;

						strcpy(a_string, "         BRASL C370LNK,ISDIGIT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 Short #5");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370ISDG");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 Short #6");
								trace_rec_3();
							}
	
						strcpy(a_string, "         LARL  R8,C370ZERO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 Short #7");
								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 Short #8");
								trace_rec_3();
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

						strcpy(a_string, "         JLE   ");
						strcat(a_string, "L");
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 Short #9");
								trace_rec_3();
							}
		
						while_convert = 1;		
						convert = 1;
					}		
			}

		if(while_complex == 1)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1");
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
						printf("c2z_while.c while_case_7 E-332 field1 Not Found = %s\n",field1);
						c2_error();
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
								printf("c2z_while.c while_case_7 E-333 field3 Not Found = %s\n",field3);
								c2_error();
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
						printf("c2z_while.c while_case_7 E-334 field5 Not Found = %s\n",field5);
						c2_error();
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
								printf("c2z_while.c while_case_7 E-335 field7 Not Found = %s\n",field7);
								c2_error();
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
						strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #2");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #3");
						trace_rec_3();
					}
				var_use[1]++;
				work_use_ct[2]++;

				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #4");
						trace_rec_3();
					}
				
				strcpy(a_string, "         BRASL C370LNK,ISDIGIT");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370ISDG");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #6");
						trace_rec_3();
					}
 
				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #7");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #8");
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
								strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #9");
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
								strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #10");
								trace_rec_3();
							}
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, field5a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #11");
						trace_rec_3();
					}
				var_use[1]++;

				if(whfd7_type == 1)
					{
						for(I=0; I < lit_ct; I++)
							{
								if(rct == w_literal[I].lit_rct)
									{
										strcpy(field7a, w_literal[I].lit_use_cname);	
										break;
									} 
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field7a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #12");
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
								strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #13");
								trace_rec_3();
							}
						var_use[1]++;
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #14");
						trace_rec_3();
					}

				if(operand_3 == 3)
					{
						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #15");
								trace_rec_3();
							}

						strcpy(a_string, "         JLH   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #16");
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
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #17");
								trace_rec_3();
							}

						strcpy(a_string, "         JLH   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1 #18");
								trace_rec_3();
							}
		     			}

				while_convert = 1;                        
				convert = 1;
			}	
	}


void c2_while_8()		 /* isalpha */	
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_8");
				trace_rec_1();
			}

		char ch;
		char *p, *wkp;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field5a[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field7a[VAR_LGTH];

		int pi;
		int pi2;
		int while_complex = 0;
		int whfd3_type = 0;
		int x2 = 0;
		int v = 0;
		int operand_1 = 0;
		int operand_3 = 0;
		int wh_3 = 0;
		int wh_4 = 0;
		int ret = 0;
		int ret1 = 0;
	
		var_use[9]++;
			
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
				wkp = strstr(p_string,"!");
				if(wkp)				/* not equal test ! */
					{
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
						while(ch != ')')
							{
								field1[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						field1[pi2] = '\0';

						strcpy(a_string, "         LARL  R9,C370L1A");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #1");
								trace_rec_3();
							}
						work_use_ct[59]++;

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field1);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #2");
								trace_rec_3();
							}

						strcpy(a_string, "         MVC   0(1,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #3");
								trace_rec_3();
							}

						strcpy(a_string, "         BRASL C370LNK,ISALPHA");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #4");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370ISAL");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #5");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #6");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #7");
								trace_rec_3();
							}
						work_use_ct[1]++;

						strcpy(a_string, "         JLE   ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #8");
								trace_rec_3();
							}
					}

				if(!wkp)				/* equal test       */
					{
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
						while(ch != ')')
							{
								field1[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						field1[pi2] = '\0';

						strcpy(a_string, "         LARL  R9,C370L1A");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #9");
								trace_rec_3();
							}
						work_use_ct[59]++;

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field1);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #10");
								trace_rec_3();
							}

						strcpy(a_string, "         MVC   0(1,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #11");
								trace_rec_3();
							}
						
						strcpy(a_string, "         BRASL C370LNK,ISALPHA");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #12");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370ISAL");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #13");
								trace_rec_3();
							}
	
						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #14");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #15");
								trace_rec_3();
							}
						
						strcpy(a_string, "         JLNE  ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #16");
								trace_rec_3();
							}
					}
			
				while_convert = 1;		                             
				convert = 1;
			}

		if(while_complex == 1)
			{
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

				pi2 = 0;
				ch = p_string[pi];
				while(ch !=  ')')
					{
						if(ch != ' ')
							{
								field7[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				field7[pi2] = '\0';

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
						printf("c2z_while.c while_case_8 E-326 field1 Not Found = %s\n",field1);
						c2_error();
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
								printf("c2z_while.c while_case_8 E-327 field3 Not Found = %s\n",field3);
								c2_error();
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
						printf("c2z_while.c while_case_8 E-328 field5 Not Found = %s\n",field5);
						c2_error();
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
						printf("c2z_while.c while_case_8 E-329 field7 Not Found = %s\n",field7);
						c2_error();
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
						strcpy(trace_1, "c2z_while.c c2_while_8 #30");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_8 #31");
						trace_rec_3();
					}
				work_use_ct[2]++;

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_8 #32");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_8 #33");
						trace_rec_3();
					}

				strcpy(a_string, "         BRASL C370LNK,ISALPHA");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_8 #34");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370ISAL");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_8 #35");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_8 #36");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_8 #37");
						trace_rec_3();
					}
				work_use_ct[1]++;
	
				if(operand_1 == 1)
					{
						strcpy(a_string, "         JLNE  L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #38");
								trace_rec_3();
							}
					}
				
				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, field5a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field5);
				strcat(wk_remark, " */");
                            write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_8 #39");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field7a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field7);
				strcat(wk_remark, " */");
                            write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_8 #40");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_8 #41");
						trace_rec_3();
					}
	
				if(operand_3 == 6)
					{
						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #42");
								trace_rec_3();
							}

						strcpy(a_string, "         JLH   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_8 #43");
								trace_rec_3();
							}
		     			}

				while_convert = 1;                        
				convert = 1;
			}	
	}


void c2_while_9()			
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_9");
				trace_rec_1();
			}

		char ch;
		char *p8;
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];

		int pi;
		int pi2;
		int x3 = 0;
		int I = 0;
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
		while(ch != '(')
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
		while(ch != ')')
			{
				field2[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field2[pi2] = '\0';
					
		x3 = 0;
		for(I = 0; I < lv_ct; I++)
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
				for(I = 0; I < gv_ct; I++)
					{
						ret = strcmp(field2, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(field2a, gw_variable[I].gv_cname);
							}
					}
			}
			
		p8 = strstr(field1, "!");
		if(p8)				
			{
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				check_length();
				strcat(a_string, "DS    0H");
				strcpy(wk_remark," while    */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_9 #1");
						trace_rec_3();
					}
			}
		else
			{
				printf("c2z_while.c c2_while_9 E-474 WHILE case 9 NO ! in FEOF\n");
				c2_error();
			}

		while_convert = 1;
		convert = 1;
	}


void c2_while_10()			
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_10");
				trace_rec_1();
			}

		char ch;
		char *p, *p1;

		int pi;
		int pi2;
		int wh_2 = 0;
		int wh_3 = 0;
		int wh_4 = 0;
		int whfd3_type = 0;
		int while_complex = 0;
		int while_simple = 0;
		int operand_1 = 0;
		int operand_3 = 0;
		int x2 = 0;
		int v = 0;
		int ret = 0;
		int ret1 = 0;

		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field5a[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field7a[VAR_LGTH];
		
		var_use[20]++; 
		
		p = strstr(p_string,"&&");
		if(p)
			{
				while_complex = 1;
			}
		
		if(while_complex == 0)		/* non complex isupper	*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_10 while_complex = 0");
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
				while(ch != ')')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

				while_simple = 0;
				p1 = strstr(p_string, "==");
				if(p1)
					{
						while_simple = 0;
					}
				else	
					{
						while_simple = 1;
					}
				
				if(while_simple == 0)	/* continue down p_string		*/
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0");
								trace_rec_1();
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
								field2[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						field2[pi2] = '\0';

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

						wh_3 = 0;
						wh_2 = 0;
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
								wh_2 = 0;
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
								printf("c2z_while.c while_case_10 E-319 field1 Not Found = %s\n",field1);
								c2_error();
							}

						if(whfd3_type == 2)		
							{
								wh_3 = 0;
								wh_2 = 0;
								if(lv_ct > 0)
									{
										for(v = 0; v < lv_ct; v++)
											{
												wh_4 = strcmp(field3, lw_variable[v].lv_name);
												wh_2 = strcmp(sv_func, lw_variable[v].lv_func);
												if((wh_4 == 0) && (wh_2 == 0)) 
													{				
														wh_3 = 1;
														strcpy(field3a, lw_variable[v].lv_cname);
													}
											}
									}

								if(wh_3 == 0)
									{
										wh_2 = 0;
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
										printf("c2z_while.c while_case_10 E-320 field3 Not Found = %s\n",field3);
										c2_error();
									}

							}	

						if(whfd3_type == 1)		/* field3 is numeric literal	*/
							{
								strcpy(field3a, field3);
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

						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						check_length();
						strcat(a_string, "DS    0H");
						strcpy(wk_remark," while    */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #1");
								trace_rec_3();
							}
	
						strcpy(a_string, "         LARL  R9,C370L1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #2");
								trace_rec_3();
							}
	
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field1a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #3");
								trace_rec_3();
							}

						strcpy(a_string, "         MVC   0(1,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #4");
								trace_rec_3();
							}

						strcpy(a_string, "         BRASL C370LNK,ISUPPER");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #5");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370ISAL");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #6");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #7");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #8");
								trace_rec_3();
							}

						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #9");
								trace_rec_3();
							}
					}	

				if(while_simple == 1)		/* while(isupper(ch))	*/
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple");
								trace_rec_1();
							}

						wh_3 = 0;
						wh_2 = 0;
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
								wh_2 = 0;
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
								printf("c2z_while.c while_case_10 E-321 field1 Not Found = %s\n",field1);
								c2_error();
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
								strcpy(trace_1, "c2z_while.c c2_while_10 simple #1");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370L1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple #2");
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
								strcpy(trace_1, "c2z_while.c c2_while_10 simple #3");
								trace_rec_3();
							}

						strcpy(a_string, "         MVC   0(1,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple #4");
								trace_rec_3();
							}

						strcpy(a_string, "         BRASL C370LNK,ISUPPER");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_whiel.c c2_while_10 simple #5");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370ISAL");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple #6");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple #7");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple #8");
								trace_rec_3();
							}
	
						strcpy(a_string, "         JNE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 simple #9");
								trace_rec_3();
							}
					}		
			}	

		if(while_complex == 1)	/* start of complex isupper		*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1");
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

				ch = p_string[pi];
				while(ch ==  ' ')
					{
						field6[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				ch = p_string[pi];
				while(ch !=  ')')
					{
						field7[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field7[pi2] = '\0';

				wh_3 = 0;
				wh_2 = 0;
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
						wh_2 = 0;
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
						printf("c2z_while.c while_case_10 E-322 field1 Not Found = %s\n",field1);
						c2_error();
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
						wh_2 = 0;
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
								wh_2 = 0;
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
								printf("c2z_while.c while_case_10 E-323 field3 Not Found = %s\n",field3);
								c2_error();
							}
					}

				wh_3 = 0;
				wh_2 = 0;
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
						wh_2 = 0;
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
						printf("c2z_while.c while_case_10 E-324 field5 Not Found = %s\n",field5);
						c2_error();
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

				wh_3 = 0;
				wh_2 = 0;
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
						wh_2 = 0;
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
						printf("c2z_while.c while_case_10 E-325 field7 Not Found = %s\n",field7);
						c2_error();
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
						strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #2");
						trace_rec_3();
					}
	
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #4");
						trace_rec_3();
					}
	
				strcpy(a_string, "         BRASL C370LNK,ISUPPER");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370ISAL");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #6");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #7");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #8");
						trace_rec_3();
					}
				work_use_ct[1]++;
	
				if(operand_1 == 1)
					{
						strcpy(a_string, "         JNE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #9");
								trace_rec_3();
							}
					}

				strcpy(a_string, "         LARL  R9,");
                            strcat(a_string, field5a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field5);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #10");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,");
                            strcat(a_string, field7a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field7);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #11");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #12");
						trace_rec_3();
					}

				if(operand_3 == 6)
					{
						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #13");
								trace_rec_3();
							}

						strcpy(a_string, "         JLH   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #14");
								trace_rec_3();
							}
		     			}

				while_convert = 1;                        
				convert = 1;
			}	
	}


void c2_while_11()		  /* isspace	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_11");
				trace_rec_1();
			}

		var_use[11]++;

		char *p;
		char ch;
		
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
								
		int pi;
		int pi2;
		int while_complex = 0;
		int v = 0;
		int wh_3 = 0;
		int wh_4 = 0;
		int ret = 0;
		int ret1 = 0;

		p = strstr(p_string,"&&");
		if(p)
			{
				while_complex = 1;
			}
		
		if(while_complex == 0)		/* non complex isspace	*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0");
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
				while(ch != ')')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

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
						printf("c2z_while.c while_case_11 E-475 field1 Not Found = %s\n",field1);
						c2_error();
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
						strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #2");
						trace_rec_3();
					}
				work_use_ct[2]++;

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #4");
						trace_rec_3();
					}
  
				strcpy(a_string, "         BRASL C370LNK,ISSPACE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370ISAL");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #6");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #7");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #8");
						trace_rec_3();
					}

				strcpy(a_string, "         JLNE  L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #8");
						trace_rec_3();
					}
			}		
	}

void c2_while_12()		  /* ISALNUM	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_12");
				trace_rec_1();
			}

		var_use[12]++;

		char *p;
		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		
		int pi;
		int pi2;
		int while_complex = 0;
		int wh_3 = 0;
		int wh_4 = 0;
		int x = 0;
		int s = 0;
		int I = 0;
		int v = 0;
		int ret = 0;
		int ret1 = 0;

		p = strstr(p_string,"&&");
		if(p)
			{
				while_complex = 1;
			}

		if(while_complex == 0)		/* non complex isalnum	*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_while.c while_12 complex = 0");
						trace_rec_1();
					}

				x = 0;
				s = strlen(p_string);
				for(I=0; I < s; I++)
					{
						ch = p_string[I];
						if(ch == '(')
							{
								x++;
							}
					}

				if(x == 2)
					{
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
						while(ch != ')')
							{
								field1[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						field1[pi2] = '\0';
					}

				if(x == 3)
					{
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
						printf("c2z_while.c while_case_12 E-309 field1 Not Found = %s\n",field1);
						c2_error();
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
						strcpy(trace_1, "c2z_while.c while_12 complex = 0 #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c while_12 complex = 0 #2");
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
						strcpy(trace_1, "c2z_while.c while_12 complex = 0 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c while_12 complex = 0 #4");
						trace_rec_3();
					}

				strcpy(a_string, "         BRASL C370LNK,ISALNUM");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c while_12 complex = 0 #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370ISAL");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c while_12 complex = 0 #6");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c while_12 complex = 0 #7");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c while_12 complex = 0 #8");
						trace_rec_3();
					}

				strcpy(a_string, "         JNE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c while_12 complex = 0 #9");
						trace_rec_3();
					}
			}		
	}


void c2_while_13()		  /* STRCMP	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_13");
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
		char field4[VAR_LGTH];
		char field5[VAR_LGTH];
		char field5a[VAR_LGTH];
		char field6[VAR_LGTH];
		char field6a[VAR_LGTH];
		char field7[VAR_LGTH];	
		char field7a[VAR_LGTH];
		char field8[VAR_LGTH];
		char field8a[VAR_LGTH];
		char field11[VAR_LGTH];

		int pi;
		int pi2;
		int while_complex = 0;
		int whfd5_type = 0;
		int wh_3 = 0;
		int wh_4 = 0;
		int x2 = 0;
		int v = 0;
		int array_flag = 0;
		int I;

		char ar_field5[VAR_LGTH];
		char ar_field6[VAR_LGTH];
		char ar_field7[VAR_LGTH];
		char ar_field8[VAR_LGTH];
		char ar_field9[VAR_LGTH];
		char ar_field10[VAR_LGTH];
		char ar_field11[VAR_LGTH];

		char ar_field11a[VAR_LGTH];

		int operand_1 = 0;
		int operand_2 = 0;
		int ret = 0;
		int ret1 = 0;

		p = strstr(p_string,"&&");
		if(p)
			{
				while_complex = 1;
			}

		if(while_complex == 0)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_13 complex = 0");
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
				while(ch != ',')
					{
						pi++;
						ch = p_string[pi];
					}

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
						field4[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field4[pi2] = '\0';

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

				wh_3 = 0;
				array_flag = 0;
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
										lw_variable[v].lv_use_ct++;
										ret = strcmp(lw_variable[v].lv_type, "A");
										if(ret == 0)
											{
												array_flag = 1;
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
										wh_4 = strcmp(field1, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(field1a, gw_variable[v].gv_cname);
												ret = strcmp(gw_variable[v].gv_type, "A");
												if(ret == 0)
													{
														strcpy(ar_field5, gw_variable[v].gv_dsect);
														strcpy(ar_field6, gw_variable[v].gv_label);
														strcpy(ar_field7, gw_variable[v].gv_table);
														strcpy(ar_field8, gw_variable[v].gv_aname);
														strcpy(ar_field9, gw_variable[v].gv_sv_reg);
														strcpy(ar_field10, gw_variable[v].gv_wk_reg);
														strcpy(ar_field11, gw_variable[v].gv_wk_strg);
														gw_variable[v].gv_flag = 1;
														gw_variable[v].gv_use_ct++;
														array_flag = 1;
													}
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_13 field1 Not Found = %s\n",field1);
						printf("c2z_while.c while_case_13 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				wh_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field2, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(field2a, lw_variable[v].lv_cname);
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
										wh_4 = strcmp(field2, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(field2a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_13 field2 Not Found =b%s\n",field2);
						printf("c2z_while.c while_case_13 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

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
										wh_4 = strcmp(field3, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(field3a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
 											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_13 field3 Not Found = %s\n",field3);
						printf("c2z_while.c while_case_13 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				operand_1 = 0;
				if(operand_1 == 0)
					{
						p = strstr(field4, "==");
						if(p)
							operand_1 = 1;
					}

				if(operand_1 == 0)
					{
						p = strstr(field4, "!=");
						if(p)
							operand_1 = 2;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(field4, "<=");
						if(p)
							operand_1 = 3;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(field4, ">=");
						if(p)
							operand_1 = 4;
					}

				if(operand_1 == 0)
					{
						p = strstr(field4, "=");
						if(p)
							operand_1 = 5;
					}

				if(operand_1 == 0)
					{
						p = strstr(field4, "<");
						if(p)
							operand_1 = 6;
					}

				if(operand_1 == 0)
					{
						p = strstr(field4, ">");
						if(p)
							operand_1 = 7;
					}

				if(whfd5_type == 1)
					{
						for(I=0; I < lit_ct; I++)
							{
								if(rct == w_literal[I].lit_rct)
									{
										strcpy(field7a, w_literal[I].lit_use_cname);	
										break;
									} 
							}
					}
	 
				printf("c2z_while.c c2_while_13 E-433 while_complex = 0 Code Not Written\n");
				c2_error();
			}		

		if(while_complex == 1)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1");
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
				while(ch != ',')
					{
						pi++;
						ch = p_string[pi];
					}

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
						field4[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field4[pi2] = '\0';

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
						if(ch == '<')
							{
								goto lskip_1;
							}
						field6[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				lskip_1:
				field6[pi2] = '\0'; 

				pi2 = 0;
				field7[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
				field7[pi2] = '\0';

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
								field8[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				field8[pi2] = '\0';

				wh_3 = 0;
				array_flag = 0;
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
										lw_variable[v].lv_use_ct++;
										ret = strcmp(lw_variable[v].lv_type, "A");
										if(ret == 0)
											{
												array_flag = 1;
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
										wh_4 = strcmp(field1, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(field1a, gw_variable[v].gv_cname);
												ret = strcmp(gw_variable[v].gv_type, "A");
												if(ret == 0)
													{
														strcpy(ar_field5, gw_variable[v].gv_dsect);
														strcpy(ar_field6, gw_variable[v].gv_label);
														strcpy(ar_field7, gw_variable[v].gv_table);
														strcpy(ar_field8, gw_variable[v].gv_aname);
														strcpy(ar_field9, gw_variable[v].gv_sv_reg);
														strcpy(ar_field10, gw_variable[v].gv_wk_reg);
														strcpy(ar_field11, gw_variable[v].gv_wk_strg);
														gw_variable[v].gv_flag = 1;
														gw_variable[v].gv_use_ct++;
														array_flag = 1;
													}
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_13 E-434 field1 Not Found = %s\n",field1);
						c2_error();
					}

				wh_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field2, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(field2a, lw_variable[v].lv_cname);
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
										wh_4 = strcmp(field2, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(field2a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_13 E-435 field2 Not Found = %s\n",field2);
						c2_error();
					}

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
										wh_4 = strcmp(field3, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(field3a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
 											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_13 E-436 field3 Not Found = %s\n",field3);
						c2_error();
					}

				operand_1 = 0;
				if(operand_1 == 0)
					{
						p = strstr(field4, "==");
						if(p)
							operand_1 = 1;
					}

				if(operand_1 == 0)
					{
						p = strstr(field4, "!=");
						if(p)
							operand_1 = 2;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(field4, "<=");
						if(p)
							operand_1 = 3;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(field4, ">=");
						if(p)
							operand_1 = 4;
					}

				if(operand_1 == 0)
					{
						p = strstr(field4, "=");
						if(p)
							operand_1 = 5;
					}

				if(operand_1 == 0)
					{
						p = strstr(field4, "<");
						if(p)
							operand_1 = 6;
					}

				if(operand_1 == 0)
					{
						p = strstr(field4, ">");
						if(p)
							operand_1 = 7;
					}

				if(whfd5_type == 2)
					{
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
												wh_4 = strcmp(field5, gw_variable[v].gv_name);
												if(wh_4 == 0)
													{				
														wh_3 = 1;
														strcpy(field5a, gw_variable[v].gv_cname);
														gw_variable[v].gv_use_ct++;
													}
											}
									}
							}

						if(wh_3 == 0)
							{
								printf("c2z_while.c while_case_13 E-437 field5 Not Found = %s\n",field5);
								c2_error();
							}
					}

				wh_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field6, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(field6a, lw_variable[v].lv_cname);
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
										wh_4 = strcmp(field6, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(field6a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_13 E-438 field6 Not Found = %s\n",field6);
						c2_error();
					}

				operand_2 = 0;
				if(operand_2 == 0)
					{
						p = strstr(field7, "==");
						if(p)
							operand_2 = 1;
					}

				if(operand_2 == 0)
					{
						p = strstr(field7, "!=");
						if(p)
							operand_2 = 2;
					}
				
				if(operand_2 == 0)
					{
						p = strstr(field7, "<=");
						if(p)
							operand_2 = 3;
					}
				
				if(operand_2 == 0)
					{
						p = strstr(field7, ">=");
						if(p)
							operand_2 = 4;
					}

				if(operand_2 == 0)
					{
						p = strstr(field7, "=");
						if(p)
							operand_2 = 5;
					}

				if(operand_2 == 0)
					{
						p = strstr(field7, "<");
						if(p)
							operand_2 = 6;
					}

				if(operand_2 == 0)
					{
						p = strstr(field7, ">");
						if(p)
							operand_2 = 7;
					}

				wh_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field8, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(field8a, lw_variable[v].lv_cname);
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
										wh_4 = strcmp(field8, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(field8a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_13 E-439 field8 Not Found = %s\n",field8);
						c2_error();
					}

				wh_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(ar_field11, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(ar_field11a, lw_variable[v].lv_cname);
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
										wh_4 = strcmp(ar_field11, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(ar_field11a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_13 E-440 field11 Not Found = %s\n",field11);
						c2_error();
					}

				if(array_flag == 0)			/*  character field		*/
					{
						printf("c2z_while.c c2_while_13 E-441 while(strcmp needs to be coded\n");
						c2_error();
					}		


				if(array_flag == 1)			/*  array fieldd		*/
					{
						strcpy(a_string, "         LARL  R6,");
						strcat(a_string, ar_field7);
                                      	strcpy(wk_remark, " ");
						strcat(wk_remark, field1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #2");
								trace_rec_3();
							}
						
						strcpy(a_string, "         LARL  R9,C370LPCT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #3");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370ZERO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #4");
								trace_rec_3();
							}
					
						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #5");
								trace_rec_3();
							}
	
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcpy(start_while, a_string);
						check_length();
						strcat(a_string, "DS    0H");
						strcpy(wk_remark," while    */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #6");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field2a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field2);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #7");
								trace_rec_3();
							}
	
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field8a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field8);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #8");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #9");
								trace_rec_3();
							}

						strcpy(a_string, "         JLH   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #10");
								trace_rec_3();
							}

						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "E");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #11");
								trace_rec_3();
							}

						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcpy(start_while, a_string);
						strcat(a_string, "B");
						check_length();
						strcat(a_string, "DS    0H");
						strcpy(wk_remark," while    */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #12");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field3a);
                                          strcpy(wk_remark, " ");
						strcat(wk_remark, field3);
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #13");
								trace_rec_3();
							}
						var_use[1]++;
 
						strcpy(a_string, "         CLC   0(3,R9),0(R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #14");
								trace_rec_3();
							}
						
						if(operand_1 == 2)		/* !=	*/
							{
								strcpy(a_string, "         JLE   L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, wk_strg);
								strcat(a_string, "E");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_13 complex == 1 #15");
										trace_rec_3();
									}
							}

						if(operand_1 == 1)		/* ==	*/
							{
								printf("c2z_while.c c2_while_13 E-442 operand_1 == Error#1\n");
								c2_error();
							}

						if(operand_1 == 3)		/* <=	*/
							{
								printf("c2z_while.c c2_while_13 E-443 operand_1 <= Error#3\n");
								c2_error();
							}

						if(operand_1 == 4)		/* >=	*/
							{
								printf("c2z_while.c c2_while_13 E-444 operand_1 >= Error#4\n");
								c2_error();
							}

						if(operand_1 == 5)		/* =	*/
							{
								printf("c2z_while.c c2_while_13 E-445 operand_1 = Error#5\n");
								c2_error();
							}

						if(operand_1 == 6)		/* <	*/
							{
								printf("c2z_while.c c2_while_13 E-446 operand_1 < Error#6\n");
								c2_error();
							}

						if(operand_1 == 7)		/* >	*/
							{
								printf("c2z_while.c c2_while_13 E-447 operand_1 > Error#7\n");
								c2_error();
							}

						if(operand_2 == 1)		/* ==	*/
							{
								printf("c2z_while.c c2_while_13 E-448 operand_2 == Error#1\n");
								c2_error();
							}

						if(operand_2 == 2)		/* !=	*/
							{
								printf("c2z_while.c c2_while_13 E-449 operand_2 != Error#3\n");
								c2_error();
							}
						
						if(operand_2 == 3)		/* <=	*/
							{
								printf("c2z_while.c c2_while_13 E-450 operand_2 <= Error#3\n");
								c2_error();
							}

						if(operand_2 == 4)		/* >=	*/
							{
								printf("c2z_while.c c2_while_13 E-451 operand_2 >= Error#4\n");
								c2_error();
							}

						if(operand_2 == 5)		/* =	*/
							{
								printf("c2z_while.c c2_while_13 E-452 operand_2 = Error#5\n");
								c2_error();
							}

						if(operand_2 == 6)		/* <	*/
							{
								printf("c2z_while.c c2_while_13 E-453 operand_2 = Error#6\n");
								c2_error();
							}

						if(operand_2 == 7)		/* >	*/
							{
								printf("c2z_while.c c2_while_13 E-454 operand_2 > Error#7\n");
								c2_error();
							}
					}		
			}		
	}


void c2_while_14()		/* user function		*/			
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_14");
				trace_rec_1();
			}
		
		char *p;
		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield4a[VAR_LGTH];
		char tfield11[VAR_LGTH];
		char tfield11a[VAR_LGTH];
		char wk_sv_func[VAR_LGTH];

		int pi;
		int pi2;
		int I = 0;
		int v = 0;
		int wh_3 = 0;
		int wh_4 = 0;
		int while_complex = 0;
		int ret = 0;
		int ret1 = 0;
		int ret2 = 0;
		int fd2_type = 0;
		int fd3_type = 0;
		int fd4_type = 0;
		int fd11_type = 0;

		p = strstr(p_string, "&&");
		if(p)
			{
				while_complex = 1;
			}

		p = strstr(p_string, "||");
		if(p)
			{
				while_complex = 1;
			}

		if(while_complex == 0)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_14 complex == 0");
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
				while(ch != '(')
					{
						tfield1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';
				strcpy(wk_sv_func, tfield1);

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ')')
					{
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				wh_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield2, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(tfield2a, lw_variable[v].lv_cname);
										lw_variable[v].lv_use_ct++;
										ret2 = strcmp("C", lw_variable[v].lv_type);
										if(ret2 == 0)
											{
												fd2_type = 1;
											}
										else
											{
												fd2_type = 2;
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
										wh_4 = strcmp(tfield2, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(tfield2a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
												ret2 = strcmp("C", gw_variable[v].gv_type);
												if(ret2 == 0)
													{
														fd2_type = 1;
													}
												else
													{
														fd2_type = 2;
													}
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_14 E-468 tfield2 Not Found = %s\n",tfield2);
						c2_error();
					}

				wh_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield2, lw_variable[v].lv_name);
								ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(tfield4a, lw_variable[v].lv_cname);
										lw_variable[v].lv_use_ct++;
										ret2 = strcmp("C", lw_variable[v].lv_type);
										if(ret2 == 0)
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

				if(wh_3 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										wh_4 = strcmp(tfield2, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(tfield4a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
												ret2 = strcmp("C", gw_variable[v].gv_type);
												if(ret2 == 0)
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
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_14 E-469 tfield2 Not Found = %s\n",tfield2);
						c2_error();
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcpy(start_while, a_string);
				check_length();
				strcat(a_string, "DS    0H");
				strcpy(wk_remark," while    */");
				write_remark();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_14 #1");
						trace_rec_3();
					}

				if((fd2_type == 1) && (fd4_type == 1))
					{ 
						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield4a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{	
								strcpy(trace_1, "c2z_while.c c2_while_14 #2");
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
								strcpy(trace_1, "c2z_while.c c2_while_14 #3");
								trace_rec_3();
							}

						strcpy(a_string, "         MVC   0(1,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{	
								strcpy(trace_1, "c2z_while.c c2_while_14 #4");
								trace_rec_3();
							}
					}

				if((fd3_type == 2) && (fd4_type == 2))
					{

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield4a);
						src_line();
						if(punch_code == 1)
							{	
								strcpy(trace_1, "c2z_while.c c2_while_14 #5");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield2a);
						src_line();
						if(punch_code == 1)
							{	
								strcpy(trace_1, "c2z_while.c c2_while_14 #6");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{	
								strcpy(trace_1, "c2z_while.c c2_while_14 #7");
								trace_rec_3();
							}
					}

				for(I=0; I < fn_ct; I++)
					{
						ret = strcmp(tfield1, w_function[I].fn_name);
						if(ret == 0)
							{
								strcpy(tfield1a, w_function[I].fn_cname);
								strcpy(tfield11, w_function[I].fn_ret_var);
							}
					}

				strcpy(a_string, "         BRASL C370LNK,");
				strcat(a_string, tfield1a);
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_14 #8");
						trace_rec_3();
					}

				wh_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield11, lw_variable[v].lv_name);
								ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(tfield11a, lw_variable[v].lv_cname);
										lw_variable[v].lv_use_ct++;
										ret2 = strcmp("C", lw_variable[v].lv_type);
										if(ret2 == 0)
											{
												fd11_type = 1;
											}
										else
											{
												fd11_type = 2;
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
										wh_4 = strcmp(tfield11, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(tfield11a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
												ret2 = strcmp("C", gw_variable[v].gv_type);
												if(ret2 == 0)
													{
														fd11_type = 1;
													}
												else
													{
														fd11_type = 2;
													}
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_14 E-470 tfield11 Not Found = %s\n",tfield11);
						c2_error();
					}

				if(fd11_type == 2)
					{
						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield11a);
						src_line();
						if(punch_code == 1)
							{	
								strcpy(trace_1, "c2z_while.c c2_while_14 #9");
								trace_rec_3();
							}
						
						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{	
								strcpy(trace_1, "c2z_while.c c2_while_14 #10");
								trace_rec_3();
							}
						
						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{	
								strcpy(trace_1, "c2z_while.c c2_while_14 #11");
								trace_rec_3();
							}
					}

				if(fd11_type == 1)
					{
						printf("c2z_while.c c2_while_14 E-471 fd2_type == 1 NOT CODED\n");
						c2_error();
					}

				strcpy(a_string, "         JLNE  L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_14 #12");
						trace_rec_3();
					}
			}

		if(while_complex == 1)
			{
				printf("c2z_while.c c2_while_14 E-472 user sub complex NOT CODED\n");
				c2_error();
			}
	}

 
void c2_while_15()		/* complex non function		*/			
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_15");
				trace_rec_1();
			}

		int pi = 0;
		int pi2 = 0;
		int x2 = 0;

		int ret = 0;
		int ret1 = 0;
		int ret2 = 0;
		int fd1_type = 0;
		int fd1_var = 0;
		int fd3_type = 0;
		int fd5_var = 0;
		int fd7_type = 0;
		int fd7_var = 0;
		int operand_1 = 0;
		int operand_2 = 0;
		int wh_3 = 0;
		int wh_4 = 0;
		int v = 0;
		int I = 0;

		char *p;
		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield5[VAR_LGTH]; 
		char tfield5a[VAR_LGTH];
		char tfield6[VAR_LGTH];
		char tfield7[VAR_LGTH];
		char tfield7a[VAR_LGTH];

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
				tfield5[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield5[pi2] = '\0';

		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		x2 = 0;
		pi2 = 0;
		ch = p_string[pi];
		while(ch != ' ')
			{
				tfield6[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield6[pi2] = '\0';

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

		operand_2 = 0;
		if(operand_2 == 0)
			{
				p = strstr(tfield6, "==");
				if(p)
					operand_2 = 1;
			}

		if(operand_2 == 0)
			{
				p = strstr(tfield6, "!=");
				if(p)
					operand_2 = 2;
			}
				
		if(operand_2 == 0)
			{
				p = strstr(tfield6, "<=");
				if(p)
					operand_2 = 3;
			}
				
		if(operand_2 == 0)
			{
				p = strstr(tfield6, ">=");
				if(p)
					operand_2 = 4;
			}

		if(operand_2 == 0)
			{
				p = strstr(tfield6, "=");
				if(p)
					operand_2 = 5;
			}

		if(operand_2 == 0)
			{
				p = strstr(tfield6, "<");
				if(p)
					operand_2 = 6;
			}

		if(operand_2 == 0)
			{
				p = strstr(tfield6, ">");
				if(p)
					operand_2 = 7;
			}

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
								lw_variable[v].lv_use_ct++;
								ret2 = strcmp("I",lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd1_var = 1;
									}
								ret2 = strcmp("C",lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd1_var = 2;
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
										gw_variable[v].gv_use_ct++;
										ret2 = strcmp("I",gw_variable[v].gv_type);
										if(ret2 == 0)
											{
												fd1_var = 1;
											}
										ret2 = strcmp("C",gw_variable[v].gv_type);
										if(ret2 == 0)
											{
												fd1_var = 2;
											}
									}
							}
					}
			}

		if(wh_3 == 0)
			{
				printf("c2z_while.c while_case_15 TFIELD1 Not Found %s\n",tfield1);
				printf("c2z_while.c while_case_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
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
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_15 TFIELD3 Not Found %s\n",tfield3);
						printf("c2z_while.c while_case_15 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
			}

		if(fd3_type == 1)
			{
printf("c2z_while.c while_case_15 Inside fd3_type == 1\n");


			}


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
								ret2 = strcmp("I",lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd5_var = 1;
									}
								ret2 = strcmp("C",lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd5_var = 2;
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
				printf("c2z_while.c while_case_15 TFIELD5 Not Found %s\n",tfield5);
				printf("c2z_while.c while_case_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
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
										ret2 = strcmp("I",lw_variable[v].lv_type);
										if(ret2 == 0)
											{
												fd7_var = 1;
											}
										ret2 = strcmp("C",lw_variable[v].lv_type);
										if(ret2 == 0)
											{
												fd7_var = 2;
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
										wh_4 = strcmp(tfield7, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(tfield7a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
												ret2 = strcmp("I",gw_variable[v].gv_type);
												if(ret2 == 0)
													{
														fd7_var = 1;
													}
												ret2 = strcmp("C",gw_variable[v].gv_type);
												if(ret2 == 0)
													{
														fd7_var = 2;
													}
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_15 tfield7 Not Found %s\n",tfield7);
						printf("c2z_while.c while_case_15 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
			}

		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcpy(a_string, "L");
		strcat(a_string, wk_strg);
		strcpy(start_while, a_string);
		check_length();
		strcat(a_string, "DS    0H");
		strcpy(wk_remark," while    */");
		write_remark();
		if(punch_code == 1)
			{	
				strcpy(trace_1, "c2z_while.c c2_while_15 #1");
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
				strcpy(trace_1, "c2z_while.c c2_while_15 #2");
				trace_rec_3();
			}

		if(fd3_type == 2)
			{
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield3a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield3);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_15 #3");
						trace_rec_3();
					}
			} 

		if(fd3_type == 1)
			{
				for(I=0; I < lit_ct; I++)
					{
						if((rct == w_literal[I].lit_rct) && (w_literal[I].lit_uct == 1))
							{
								break;
							} 
					}
				
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, w_literal[I].lit_cname);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_15 #4");
						trace_rec_3();
					}
			}

		if(fd3_type == 0)
			{
				for(I=0; I < char_ct; I++)
					{
						if((rct == w_charlit[I].clit_rct) && (w_charlit[I].clit_uct == 1))
							{
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, w_charlit[I].clit_cname);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_while.c c2_while_15 #5");
										trace_rec_3();
									}
								break;
							}
					}
			}

		if((fd1_type == 1) && (fd3_type == 1))
			{
				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_15 #6");
						trace_rec_3();
					}
			}

		if((fd1_var == 2) && (fd3_type == 2))
			{
				strcpy(a_string, "         CLC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_15 #7");
						trace_rec_3();
					}
			}

		if((fd1_var == 2) && (fd3_type == 0))
			{
				strcpy(a_string, "         CLC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_15 #8");
						trace_rec_3();
					}
			}

		if(operand_1 == 1)		/* ==	*/
			{
				printf("c2z_while.c c2_while_15 operand_1 == Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_1 == 2)		/* !=	*/
			{
				strcpy(a_string, "         JLE   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_15 #9");
						trace_rec_3();
					}
			}

		if(operand_1 == 3)		/* <=	*/
			{
				printf("c2z_while.c c2_while_15 operand_1 <= Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_1 == 4)		/* >=	*/
			{
				printf("c2z_while.c c2_while_15 operand_1 >= Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_1 == 6)		/* <	*/
			{
				printf("c2z_while.c c2_while_15 operand_1 <  Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_1 == 7)		/* ><	*/
			{
				printf("c2z_while.c c2_while_15 operand_1 >  Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		strcpy(a_string, "         LARL  R9,");
		strcat(a_string, tfield5a);
		strcpy(wk_remark, " ");
		strcat(wk_remark, tfield5);
		strcat(wk_remark, " */");
		write_remark();
		if(punch_code == 1)
			{	
				strcpy(trace_1, "c2z_while.c c2_while_15 #10");
				trace_rec_3();
			}
		
		if(fd7_type == 2)
			{
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield7a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield7);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_15 #11");
						trace_rec_3();
					}
			}

		if(fd7_type == 1)
			{
				for(I=0; I < lit_ct; I++)
					{
						if((rct == w_literal[I].lit_rct) && (w_literal[I].lit_uct == 2))
							{
								break;
							} 
					}
				
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, w_literal[I].lit_cname);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_while.c c2_while_15 #12");
						trace_rec_3();
					}
			}

		if((fd5_var == 1) && (fd7_var == 1))
			{
				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_15 #13");
						trace_rec_3();
					}
			}

		if(operand_2 == 1)		/* ==	*/
			{
				printf("c2z_while.c c2_while_15 operand_2 == Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_2 == 2)		/* !=	*/
			{
				strcpy(a_string, "         JLE   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_15 #14");
						trace_rec_3();
					}
			}

		if(operand_2 == 3)		/* <=	*/
			{
				printf("c2z_while.c c2_while_15 operand_2 <= Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_2 == 4)		/* >=	*/
			{
				printf("c2z_while.c c2_while_15 operand_2 >= Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_2 == 6)		/* <	*/
			{

				strcpy(a_string, "         JLE   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_15 #15");
						trace_rec_3();
					}
				
				strcpy(a_string, "         JLH   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_15 #16");
						trace_rec_3();
					}
	
			}

		if(operand_2 == 7)		/* ><	*/
			{
				printf("c2z_while.c c2_while_15 operand_2 >  Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		convert = 1;
		
	}


void c2_while_16()		/* complex non function with 2 groups of &&		*/			
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_while.c c2_while_16 ");
				trace_rec_1();
			}

		int pi = 0;
		int pi2 = 0;
		int x2 = 0;

		int ret = 0;
		int ret1 = 0;
		int ret2 = 0;
		int I = 0;
		int fd1_type = 0;
		int fd3_type = 0;
		int fd5_type = 0;
		int fd7_type = 0;
		int fd9_type = 0;
		int fd11_type = 0;
		int cd3_type = 0;
		int cd7_type = 0;
		int cd11_type = 0;
		int operand_1 = 0;
		int operand_2 = 0;
		int operand_3 = 0;
		int wh_3 = 0;
		int wh_4 = 0;
		int v = 0;
		int x20 = 0;

		char *p;
		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield5[VAR_LGTH];
		char tfield5a[VAR_LGTH];
		char tfield6[VAR_LGTH];
		char tfield7[VAR_LGTH];
		char tfield7a[VAR_LGTH];
		char tfield9[VAR_LGTH];
		char tfield9a[VAR_LGTH];
		char tfield10[VAR_LGTH];
		char tfield11[VAR_LGTH];
		char tfield11a[VAR_LGTH];
		char tfield21a[VAR_LGTH];

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
								cd3_type = 1;
								x2 = 1;
							}
 
						if (isalpha(ch))	
							{
								fd3_type = 2;
								cd3_type = 2;
								x2 = 1;
							}
					}
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

		ch = p_string[pi];
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

		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ' ')
			{
				tfield5[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield5[pi2] = '\0';

		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}

		x2 = 0;
		pi2 = 0;
		ch = p_string[pi];
		while(ch != ' ')
			{
				tfield6[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield6[pi2] = '\0';

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
				if(x2 == 0)
					{
						if (isdigit(ch)) 	
							{
								fd7_type = 1;
								cd7_type = 1;
								x2 = 1;
							}
 
						if (isalpha(ch))	
							{
								fd7_type = 2;
								cd7_type = 2;
								x2 = 1;
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
				tfield9[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield9[pi2] = '\0';

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
				tfield10[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield10[pi2] = '\0';

		pi2 = 0;
		ch = p_string[pi];
		while(ch != ')')
			{
				if(ch != ' ')
					{
						if(x2 == 0)
							{
								if (isdigit(ch)) 	
									{
										fd11_type = 1;
										cd11_type = 1;
										x2 = 1;
									}
 
								if (isalpha(ch))	
									{
										fd11_type = 2;
										cd11_type = 2;
										x2 = 1;
									}
							}
						tfield11[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		tfield11[pi2] = '\0';

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

		operand_2 = 0;
		if(operand_2 == 0)
			{
				p = strstr(tfield6, "==");
				if(p)
					operand_2 = 1;
			}

		if(operand_2 == 0)
			{
				p = strstr(tfield6, "!=");
				if(p)
					operand_2 = 2;
			}
				
		if(operand_2 == 0)
			{
				p = strstr(tfield6, "<=");
				if(p)
					operand_2 = 3;
			}
				
		if(operand_2 == 0)
			{
				p = strstr(tfield6, ">=");
				if(p)
					operand_2 = 4;
			}

		if(operand_2 == 0)
			{
				p = strstr(tfield6, "=");
				if(p)
					operand_2 = 5;
			}

		if(operand_2 == 0)
			{
				p = strstr(tfield6, "<");
				if(p)
					operand_2 = 6;
			}

		if(operand_2 == 0)
			{
				p = strstr(tfield6, ">");
				if(p)
					operand_2 = 7;
			}

		operand_3 = 0;
		if(operand_3 == 0)
			{
				p = strstr(tfield10, "==");
				if(p)
					operand_3 = 1;
			}

		if(operand_3 == 0)
			{
				p = strstr(tfield10, "!=");
				if(p)
					operand_3 = 2;
			}
				
		if(operand_3 == 0)
			{
				p = strstr(tfield10, "<=");
				if(p)
					operand_3 = 3;
			}
				
		if(operand_3 == 0)
			{
				p = strstr(tfield10, ">=");
				if(p)
					operand_3 = 4;
			}

		if(operand_3 == 0)
			{
				p = strstr(tfield10, "=");
				if(p)
					operand_3 = 5;
			}

		if(operand_3 == 0)
			{
				p = strstr(tfield10, "<");
				if(p)
					operand_3 = 6;
			}

		if(operand_3 == 0)
			{
				p = strstr(tfield10, ">");
				if(p)
					operand_3 = 7;
			}

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
								lw_variable[v].lv_use_ct++;
								ret2 = strcmp("I",lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd1_type = 1;
									}
								ret2 = strcmp("C",lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd1_type = 2;
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
										gw_variable[v].gv_use_ct++;
										ret2 = strcmp("I",gw_variable[v].gv_type);
										if(ret2 == 0)
											{
												fd1_type = 1;
											}
										ret2 = strcmp("C",gw_variable[v].gv_type);
										if(ret2 == 0)
											{
												fd1_type = 2;
											}
									}
							}
					}
			}

		if(wh_3 == 0)
			{
				printf("c2z_while.c while_case_15 tfield1 Not Found %s\n",tfield1);
				printf("c2z_while.c while_case_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(cd3_type != 1)
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
										ret2 = strcmp("I",lw_variable[v].lv_type);
										if(ret2 == 0)
											{
												fd3_type = 1;
											}
										ret2 = strcmp("C",lw_variable[v].lv_type);
										if(ret2 == 0)
											{
												fd3_type = 2;
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
												ret2 = strcmp("I",gw_variable[v].gv_type);
												if(ret2 == 0)
													{
														fd3_type = 1;
													}
												ret2 = strcmp("C",gw_variable[v].gv_type);
												if(ret2 == 0)
													{
														fd3_type = 2;
													}
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_15 tfield5 Not Found %s\n",tfield3);
						printf("c2z_while.c while_case_15 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
			}

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
								ret2 = strcmp("I",lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd5_type = 1;
									}
								ret2 = strcmp("C",lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd5_type = 2;
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
								wh_4 = strcmp(tfield5, gw_variable[v].gv_name);
								if(wh_4 == 0)
									{				
										wh_3 = 1;
										strcpy(tfield5a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
										ret2 = strcmp("I",gw_variable[v].gv_type);
										if(ret2 == 0)
											{
												fd5_type = 1;
											}
										ret2 = strcmp("C",gw_variable[v].gv_type);
										if(ret2 == 0)
											{
												fd5_type = 2;
											}
									}
							}
					}
			}

		if(wh_3 == 0)
			{
				printf("c2z_while.c while_case_15 tfield5 Not Found %s\n",tfield5);
				printf("c2z_while.c while_case_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(cd7_type != 1)
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
										ret2 = strcmp("I",lw_variable[v].lv_type);
										if(ret2 == 0)
											{
												fd7_type = 1;
											}
										ret2 = strcmp("C",lw_variable[v].lv_type);
										if(ret2 == 0)
											{
												fd7_type = 2;
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
										wh_4 = strcmp(tfield7, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(tfield7a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
												ret2 = strcmp("I",gw_variable[v].gv_type);
												if(ret2 == 0)
													{
														fd7_type = 1;
													}
												ret2 = strcmp("C",gw_variable[v].gv_type);
												if(ret2 == 0)
													{
														fd7_type = 2;
													}
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_15 tfield7 Not Found %s\n",tfield7);
						printf("c2z_while.c while_case_15 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
			}

		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcpy(a_string, "L");
		strcat(a_string, wk_strg);
		strcpy(start_while, a_string);
		check_length();
		strcat(a_string, "DS    0H");
		strcpy(wk_remark," while    */");
		write_remark();
		if(punch_code == 1)
			{	
				strcpy(trace_1, "c2z_while.c c2_while_16 #1");
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
				strcpy(trace_1, "c2z_while.c c2_while_16 #2");
				trace_rec_3();
			}
		
		if(cd3_type != 1)
			{
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield3a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield3);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #3a");
						trace_rec_3();
					}
			}

		x20 = 0;
		if(cd3_type == 1)
			{
				for(I=0; I < lit_ct; I++)
					{
						if(rct == w_literal[I].lit_rct)
							{
								x20++;
								if(x20 == 1)
									{
										strcpy(tfield21a, w_literal[I].lit_use_cname);	
										break;
									}				
							} 
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield21a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield21a);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #3b");
						trace_rec_3();
					}

				fd3_type = 1;

			}


		if((fd1_type == 1) && (fd3_type == 1))
			{
				strcpy(a_string, "         CP    0(4,R9),0(4,R8)");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #3");
						trace_rec_3();
					}
			}

		if((fd1_type == 2) && (fd3_type == 2))
			{
				strcpy(a_string, "         CLC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #4");
						trace_rec_3();
					}
			}

		if(operand_1 == 1)		/* ==	*/
			{
				printf("c2z_while.c c2_while_15 operand_1 == Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_1 == 2)		/* !=	*/
			{
				strcpy(a_string, "         JLE   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #6");
						trace_rec_3();
					}
			}

		if(operand_1 == 3)		/* <=	*/
			{
				printf("c2z_while.c c2_while_15 operand_1 <= Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_1 == 4)		/* >=	*/
			{
				printf("c2z_while.c c2_while_15 operand_1 >= Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_1 == 6)		/* <	*/
			{
				printf("c2z_while.c c2_while_15 operand_1 <  Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_1 == 7)		/* ><	*/
			{
				printf("c2z_while.c c2_while_15 operand_1 >  Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		strcpy(a_string, "         LARL  R9,");
		strcat(a_string, tfield5a);
		strcpy(wk_remark, " ");
		strcat(wk_remark, tfield5);
		strcat(wk_remark, " */");
		write_remark();
		if(punch_code == 1)
			{	
				strcpy(trace_1, "c2z_while.c c2_while_16 #11");
				trace_rec_3();
			}
		
		if(cd7_type != 1)
			{
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield7a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield7);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #12a");
						trace_rec_3();
					}
			}
		x20 = 0;
		if(cd7_type == 1)
			{
				for(I=0; I < lit_ct; I++)
					{
						if(rct == w_literal[I].lit_rct)
							{
								x20++;
								if(x20 == 2)
									{
										strcpy(tfield21a, w_literal[I].lit_use_cname);	
										break;	
									}			
							} 
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield21a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield21a);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #12b");
						trace_rec_3();
					}

				fd7_type = 1;

			}

		if((fd5_type == 1) && (fd7_type == 1))
			{
				strcpy(a_string, "         CP    0(4,R9),0(4,R8)");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #13");
						trace_rec_3();
					}
			}

		if(operand_2 == 1)		/* ==	*/
			{
				printf("c2z_while.c c2_while_15 operand_2 == Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_2 == 2)		/* !=	*/
			{
				strcpy(a_string, "         JLE   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 # ");
						trace_rec_3();
					}
			}

		if(operand_2 == 3)		/* <=	*/
			{
				printf("c2z_while.c c2_while_15 operand_2 <= Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_2 == 4)		/* >=	*/
			{
				printf("c2z_while.c c2_while_15 operand_2 >= Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_2 == 6)		/* <	*/
			{
				strcpy(a_string, "         JLE   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #18 ");
						trace_rec_3();
					}
				
				strcpy(a_string, "         JLH   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #19 ");
						trace_rec_3();
					}
	
			}

		if(operand_2 == 7)		/* ><	*/
			{
				printf("c2z_while.c c2_while_15 operand_2 >  Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		wh_3 = 0;
		if(lv_ct > 0)
			{
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(tfield9, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{				
								wh_3 = 1;
								strcpy(tfield9a, lw_variable[v].lv_cname);
								lw_variable[v].lv_use_ct++;
								ret2 = strcmp("I",lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd9_type = 1;
									}
								ret2 = strcmp("C",lw_variable[v].lv_type);
								if(ret2 == 0)
									{
										fd9_type = 2;
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
								wh_4 = strcmp(tfield9, gw_variable[v].gv_name);
								if(wh_4 == 0)
									{				
										wh_3 = 1;
										strcpy(tfield9a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
										ret2 = strcmp("I",gw_variable[v].gv_type);
										if(ret2 == 0)
											{
												fd5_type = 1;
											}
										ret2 = strcmp("C",gw_variable[v].gv_type);
										if(ret2 == 0)
											{
												fd5_type = 2;
											}
									}
							}
					}
			}

		if(wh_3 == 0)
			{
				printf("c2z_while.c while_case_15 tfield9 Not Found %s\n",tfield9);
				printf("c2z_while.c while_case_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(cd11_type != 1)
			{
				wh_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield11, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										wh_3 = 1;
										strcpy(tfield11a, lw_variable[v].lv_cname);
										lw_variable[v].lv_use_ct++;
										ret2 = strcmp("I",lw_variable[v].lv_type);
										if(ret2 == 0)
											{
												fd7_type = 1;
											}
										ret2 = strcmp("C",lw_variable[v].lv_type);
										if(ret2 == 0)
											{
												fd7_type = 2;
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
										wh_4 = strcmp(tfield11, gw_variable[v].gv_name);
										if(wh_4 == 0)
											{				
												wh_3 = 1;
												strcpy(tfield11a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
												ret2 = strcmp("I",gw_variable[v].gv_type);
												if(ret2 == 0)
													{
														fd11_type = 1;
													}
												ret2 = strcmp("C",gw_variable[v].gv_type);
												if(ret2 == 0)
													{
														fd11_type = 2;
													}
											}
									}
							}
					}

				if(wh_3 == 0)
					{
						printf("c2z_while.c while_case_15 tfield11 Not Found %s\n",tfield11);
						printf("c2z_while.c while_case_15 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}
			}

		strcpy(a_string, "         LARL  R9,");
		strcat(a_string, tfield9a);
		strcpy(wk_remark, " ");
		strcat(wk_remark, tfield9);
		strcat(wk_remark, " */");
		write_remark();
		if(punch_code == 1)
			{	
				strcpy(trace_1, "c2z_while.c c2_while_16 #20");
				trace_rec_3();
			}
		
		if(cd11_type != 1)
			{
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield11a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield11);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #21a");
						trace_rec_3();
					}
			}

		x20 = 0;
		if(cd7_type == 1)
			{
				for(I=0; I < lit_ct; I++)
					{
						if(rct == w_literal[I].lit_rct)
							{
								x20++;
								if(x20 == 3)
									{
										strcpy(tfield21a, w_literal[I].lit_use_cname);	
										break;	
									}			
							} 
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield21a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield21a);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #21b");
						trace_rec_3();
					}

				fd11_type = 1;
			}

		if((fd9_type == 1) && (fd11_type == 1))
			{
				strcpy(a_string, "         CP    ");
				strcat(a_string, "0(4,R9),0(4,R8)");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #22");
						trace_rec_3();
					}
			}

		if(operand_2 == 1)		/* ==	*/
			{
				printf("c2z_while.c c2_while_15 operand_2 == Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_2 == 2)		/* !=	*/
			{
				strcpy(a_string, "         JLE   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 # 24");
						trace_rec_3();
					}
			}

		if(operand_2 == 3)		/* <=	*/
			{
				printf("c2z_while.c c2_while_15 operand_2 <= Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_2 == 4)		/* >=	*/
			{
				printf("c2z_while.c c2_while_15 operand_2 >= Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if(operand_2 == 6)		/* <	*/
			{

				strcpy(a_string, "         JLE   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #27 ");
						trace_rec_3();
					}
				
				strcpy(a_string, "         JLH   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_while.c c2_while_16 #28 ");
						trace_rec_3();
					}
	
			}

		if(operand_2 == 7)		/* ><	*/
			{
				printf("c2z_while.c c2_while_15 operand_2 >  Not Coded\n");
				printf("c2z_while.c c2_while_15 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		convert = 1;
		
	}
