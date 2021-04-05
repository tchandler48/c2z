/* ***************************************************
*  c2z : c2z_if.c :                                  *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* *************************************************** 
*  Punch out IF statement                            *
* ************************************************** */
void c2_if(void)
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_if.c c2_if");
        trace_rec_1();
     }

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
      int x97 = 0;
      int x98 = 0;
      int x99 = 0;

     if_opr = 0;
     inside_if1 = 1;
     convert = 0;

     s = strlen(p_string);
     for(I=0; I < s; I++)
     {
        ch = p_string[I];
        if(ch == '(')
           x98++;
        if(ch == ')')
            x98++;
      }

      p = strstr(p_string, "==");
      if(p)
         x99 = 1;
      p = strstr(p_string, "!=");
      if(p)
         x99 = 1;

		p = strstr(p_string, "<");
		if(p)
			x99 = 1;
		p = strstr(p_string, ">");
		if(p)
			x99 = 1;
		p = strstr(p_string, "&&");
		if(p)
			x97 = 1;
		p = strstr(p_string, "||");
		if(p)
			x97 = 1;

		if((x98 == 2) && (x99 == 0) && (x97 == 0))
			{
				if_case_24();
				convert = 1;
			}

		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '[')
					bracket_ct++;
				if(ch == ']')
					bracket_ct++;
			}

		if((bracket_ct == 4) && (convert == 0))
			{
				if_case_11();
				convert = 1;
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

		if((if_opr == 0) && (convert == 0))
			{
				p7 = strstr(p_string, "strchr");
				if(p7)
					{
						if_opr = 30;
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

		if((if_opr == 30) && (if_convert == 0))
			{	
				if_case_30();
				if_convert = 1;
				return;
			}

		if((if_opr == 22) && (if_convert == 0))
			{	
				if_case_22();
				if_convert = 1;
				return;
			}

		if((if_opr == 23) && (if_convert == 0))
			{	
				if_case_23();
				if_convert = 1;
				return;
			}
	
		if((if_opr == 1) && (if_convert == 0) && (bracket_ct == 0))
			{	
				if_case_1();
				if_convert = 1;
			}

		if((if_opr == 2) && (if_convert == 0))
			{	
				if_case_2();
				if_convert = 1;
			}

		if((if_opr == 3) && (if_convert == 0))
			{	
				if_case_3();
				if_convert = 1;
			}
	
		if((if_opr == 4) && (if_convert == 0) && (convert == 0))
			{	
				if_case_4();
				if_convert = 1;
			}
		
		if((if_opr == 5) && (if_convert == 0))
			{
				if_case_1();
				if_convert = 1;
			}

		if((if_opr == 6) && (if_convert == 0))
			{	
				if_case_6();
				if_convert = 1;
			}

		if((if_opr == 7) && (if_convert == 0))
			{	
				if_case_7();
				if_convert = 1;
			}

		if((if_opr == 8) && (if_convert == 0))
			{	
				if_case_8();
				if_convert = 1;
			}

		if((if_opr == 9) && (if_convert == 0))
			{	
				if_case_9();
				if_convert = 1;
			}

		if((if_opr == 10) && (if_convert == 0))
			{	
				if_case_10();
				if_convert = 1;
			}

		if((if_opr == 20) && (if_convert == 0))
			{
				if_case_13();
				if_convert = 1;
				convert = 1;
				return;
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
				if_case_12();
				if_convert = 1;
			}

		convert = 1;
			
	}


/* *************************************************** 
*  if_case_1                                         *
* ************************************************** */
void if_case_1()		 
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_1");
				trace_rec_1();
			}

		char *p, *p2, *p5, *p8;
		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field5[VAR_LGTH];
		char field5a[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];

		int pi;
		int pi2;
		int I = 0;
		int if_comma = 0;
		int if_complex = 0;
		int if_blank = 0;
		int if_quote = 0;
		int if_convert = 0;
		int if_and = 0;
		int if_or = 0;

		int fd1_type = 0;
		int fd2_type = 0;
              int operand_1 = 0;
		
		int x = 0;
		int x2 = 0;
		int x3 = 0;
		int x4 = 0;
		int x5 = 0;
		int x6 = 0;

		int ret = 0;
		int ret1 = 0;
		
		p = strstr(p_string, "&&");
		if(p)
			{
				if_complex = 1;
				if_and = 1;
				
			}

		p = strstr(p_string, "||");
		if(p)
			{
				if_complex = 1;
				if_or = 1;
				
			}

		if(if_complex == 0)			
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_1 simple");
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
						printf("c2z_if.c if_case_1 E-84 field1 Not Found = %s\n",field1);
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
				ch = p_string[pi];
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
												x6 = 1;
											}
										else
											{
												x6 = 2;
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
								printf("c2z_if.c if_case_1 E-85 field2 Not Found = %s\n",field2);
								c2_error();
							} 
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

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcpy(o_string, a_string);

				if((if_comma == 0) && (fd2_type == 2) && (if_convert == 0))
					{
						if(fd2_type == 1)
							{
								strcpy(a_string,"*         CLC   ");
							}
						
						if(fd2_type == 1)
							{
								strcat(a_string, "=P'");
								strcat(a_string, field2);
								strcat(a_string, "'");
							}

						if(fd2_type == 2)
							{
								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, field1a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, field1);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_1_simple #1");
										trace_rec_3();
									}

								p8 = strstr(field2,"NULL");
								if(p8)
									{
										strcpy(a_string, "         LARL  R8,NULL");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_if.c if_case_1_simple #2 ");
												trace_rec_3();
											}
									}
								else
									{
										strcpy(a_string, "         LARL  R8,");
										strcat(a_string, field2a);
										strcpy(wk_remark, " ");
										strcat(wk_remark, field2);
										strcat(wk_remark, " */");
										write_remark();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_if.c if_case_1_simple #3 ");
												trace_rec_3();
											}
									}
							
								if((x4 != 2) && (x6 != 2))
									{
										strcpy(a_string,"         CP    0(6,R9),0(6,R8)");
									}

								if((x4 == 2) && (x6 == 2))
									{
										strcpy(a_string,"         CLC   0(1,R9),0(R8)");
									}
							}

						strcpy(wk_remark, " IF ==    */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "if_case_1_simple #4 ");
								trace_rec_3();
							}
						
						if_convert = 1;
					}

				if((if_comma == 0) && (fd2_type == 1) && (convert == 0))
					{

						if((fd1_type == 2) && (fd2_type == 1) && (x4 == 2))
							{
								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, field1a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, field1);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "if_case_1_simple #8 ");
										trace_rec_3();
									}
							}

						if((fd1_type == 2) && (fd2_type == 1) && (x4 == 1))
							{
								strcpy(a_string,"         LARL  R9,");
								strcat(a_string, field1a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, field1);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "if_case_1_simple #9 ");
										trace_rec_3();
									}
							}
						
						strcat(a_string,",");

						if(fd2_type == 2)
							{
								p8 = strstr(field2,"null");
								if(p8)
									{
										strcat(a_string, "=P'-1'");
									}
							}

						if((fd1_type == 2) && (fd2_type == 1) && (x4 == 2))
							{
								for(I=0; I < char_ct; I++)
									{
										if(w_charlit[I].clit_rct == rct)
											{
												strcpy(field2a, w_charlit[I].clit_cname);
                                                      					x3 = w_charlit[I].clit_lgth;
											}
									}

								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field2a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, field2);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "if_case_1_simple #10");
										trace_rec_3();
									}

								strcpy(a_string, "         CLC   0(1,R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "if_case_1_simple #11 ");
										trace_rec_3();
									}
							}

						if((fd1_type == 2) && (fd2_type == 1) && (x4 == 1))
							{
								for(I=0; I < lit_ct; I++)
									{
										if(rct == w_literal[I].lit_rct)
											{
												strcpy(field2a, w_literal[I].lit_use_cname);
											} 
									}

								strcpy(a_string,"         LARL  R8,");
								strcat(a_string, field2a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, field2);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "if_case_1_simple #12 ");
										trace_rec_3();
									}

								strcpy(a_string,"         CP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "if_case_1_simple #13 ");
										trace_rec_3();
									}
							}

						if_convert = 1;
					}

				if((if_comma == 0) && (fd2_type == 1) && (if_quote == 0) && (if_convert == 0))
					{
						strcpy(a_string,"         CP    ");
						if(fd1_type == 2)
							{
								strcat(a_string, field1a);
							}

						strcat(a_string,",");
						if(fd2_type == 2)
							{
								p8 = strstr(field2,"null");
								if(p8)
									{
										strcat(a_string, "=P'-1'");
									}
								else
									{
										strcat(a_string, field2a);
									}
							}

						if(fd2_type == 1)
							{
								strcat(a_string, "=P'");
								strcat(a_string, field2);
								strcat(a_string, "'");
							}

						strcpy(wk_remark, " IF ==    */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "if_case_1_simple #15 ");
								trace_rec_3();
							}

						if_convert = 1;
					}

				if((if_comma == 1) && (if_blank == 0) && (fd2_type == 1) && (if_convert == 0))
					{
						strcpy(a_string, "         CLC   ");
						strcat(a_string, "=C");
						strcat(a_string, field2);
						strcat(a_string, ",");
						strcat(a_string, field1a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "if_case_1_simple #17 ");
								trace_rec_3();
							}

						if_convert = 1;
					}

				if((if_comma == 1) && (if_blank == 0) && (if_convert == 0))
					{
						strcpy(a_string, "         CLC   ");
						strcat(a_string, "=C");
						strcat(a_string, field2);
						strcat(a_string, ",");
						strcat(a_string, field1a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "if_case_1_simple #19 ");
								trace_rec_3();
							}

						if_convert = 1;
					}

				if(operand_1 == 1)		/* ==	*/
					{
						strcpy(a_string, "         JLNE  ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "if_case_1_simple #5 ");
								trace_rec_3();
							}
					}

				if(operand_1 == 2)		/* ==	*/
					{
						printf("c2_while_5 E-86 operand_1 == Error#1\n");
						c2_error();
					}
												
				if(operand_1 == 3)		/* <=	*/
					{
						printf("c2_while_5 E-87 operand_1 <= Error#3\n");
						c2_error();
					}

				if(operand_1 == 4)		/* >=	*/
					{
						strcpy(a_string, "         JLL   ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2_if_case_1 #5");
								trace_rec_3();
							}
					}

				if(operand_1 == 5)		/* =	*/
					{
						printf("c2_while_5 E-88 operand_1 = Error#5\n");
						c2_error();
					}

				if(operand_1 == 6)		/* <	*/
					{
						printf("c2_while_5 E-89 operand_1 < Error#6\n");
						c2_error();
					}

				if(operand_1 == 7)		/* >	*/
					{
						strcpy(a_string, "         JLL   ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "if_case_1_simple #6 ");
								trace_rec_3();
							}
							
						strcpy(a_string, "         JLE   ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "if_case_1_simple #7 ");
								trace_rec_3();
							}
					}
			}	

		if((if_complex == 1) && (if_convert == 0))		
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_1 complex");
						trace_rec_1();
					}

				int operand_1 = 0;
				int operand_2 = 0;

				int if_2 = 0;
				int if_3 = 0;
				int if_4 = 0;

				int if_fd1_type = 0;
				
				int if_literal_1 = 0;
				int if_literal_2 = 0;

				int v = 0;

				pi = 0;
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}

				pi++;
				pi++;
				ch = p_string[pi];
				pi2 = 0;
				if_2 = 0;
				while(ch != ' ')
					{
						if(if_2 == 0)
							{
								if (isdigit(ch)) 	
									{
										if_fd1_type = 1;
										if_2 = 1;
									} 

								if (isalpha(ch))	
									{
										if_fd1_type = 2;
										if_2 = 1;
									}
							}
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

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
				while(ch == '(')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				if_2 = 0;
				while(ch != ' ')
					{
						field5[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field5[pi2] = '\0';

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
						field6[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field6[pi2] = '\0';

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
						field7[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field7[pi2] = '\0';

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
						p = strstr(field6, "==");
						if(p)
							operand_2 = 1;
					}

				if(operand_2 == 0)
					{
						p = strstr(field6, "!=");
						if(p)
							operand_2 = 2;
					}
				
				if(operand_2 == 0)
					{
						p = strstr(field6, "<=");
						if(p)
							operand_2 = 3;
					}
				
				if(operand_2 == 0)
					{
						p = strstr(field6, ">=");
						if(p)
							operand_2 = 4;
					}

				if(operand_2 == 0)
					{
						p = strstr(field6, "=");
						if(p)
							operand_2 = 5;
					}

				if(operand_2 == 0)
					{
						p = strstr(field6, "<");
						if(p)
							operand_2 = 6;
					}

				if(operand_2 == 0)
					{
						p = strstr(field6, ">");
						if(p)
							operand_2 = 7;
					}

				if_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								if_4 = strcmp(field1, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((if_4 == 0) && (ret1 == 0))
									{				
										if_3 = 1;
										strcpy(field1a, lw_variable[v].lv_cname);
										lw_variable[v].lv_use_ct++;
									}
							}
					}

				if(if_3 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										if_4 = strcmp(field1, gw_variable[v].gv_name);
										if(if_4 == 0)
											{				
												if_3 = 1;
												strcpy(field1a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
											}
									}
							}
					}

				if(if_3 == 0)
					{
						printf("c2z_if.c if_case_1 E-90 COMPLEX field1 Not Found = %s\n",field1);
						c2_error();
					}

				if_3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								if_4 = strcmp(field5, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((if_4 == 0) && (ret1 == 0))
									{				
										if_3 = 1;
										strcpy(field5a, lw_variable[v].lv_cname);
										lw_variable[v].lv_use_ct++;
									}
							}
					}

				if(if_3 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										if_4 = strcmp(field5, gw_variable[v].gv_name);
										if(if_4 == 0)
											{				
												if_3 = 1;
												strcpy(field5a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
											}
									}
							}
					}

				if(if_3 == 0)
					{
						printf("c2z_if.c if_case_1 E-91 COMPLEX field5 Not Found = %s\n",field5);
						c2_error();
					}

				p2 = strchr(field3, '\'');
				if(p2)
					{
						if_literal_1 = 1;
					}
				else
					{
						if_literal_1 = 2;
						printf("if_case_1 E-91 complex field3 ERROR FIX\n");
						c2_error();
					}
				
				p2 = strchr(field7, '\'');
				if(p2)
					{
						if_literal_2 = 1;
					}
				else
					{
						if_literal_2 = 2;
						printf("if_case_1 E-92 complex field7 ERROR FIX\n");
						c2_error();
					}

				if(if_fd1_type == 1)
					{
						printf("if_case_1 E-93 complex if_fd1_type == 1 ERROR\n");
						c2_error();
					}

				if(if_fd1_type == 2)
					{
						strcpy(a_string, "         CLC   ");
						strcat(a_string, field1a);
						strcat(a_string, ",");
						
						if(if_literal_1 == 1)
							{
								strcat(a_string, "=CL1");
								strcat(a_string, field3);
							}

						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_1 complex #1");
								trace_rec_3();
							}

						if(if_literal_1 == 2)
							{
								printf("c2z_if.c c2_if_case_1 E-94 complex punch error on if_literal_1\n");
								c2_error();
							}
						
						if((operand_1 == 1) && (if_or == 1))		/* ==	*/
							{
								strcpy(a_string, "         JLE   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								strcat(a_string, "B");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_1 complex #2");
										trace_rec_3();
									}

								strcpy(a_string, "         CLC   ");
								strcat(a_string, field5a);
								strcat(a_string, ",");
								if(if_literal_2 == 1)
									{
										strcat(a_string, "=CL1");
										strcat(a_string, field7);
									}

								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_1 complex #3");
										trace_rec_3();
									}
								
								strcpy(a_string, "         JLE   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								strcat(a_string, "B");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_1 complex #4");
										trace_rec_3();
									}

								strcpy(a_string, "         JLU   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_1 complex #5");
										trace_rec_3();
									}

								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcpy(a_string, "L");
								strcat(a_string, wk_strg);
								strcat(a_string,"B");
								check_length();
								strcat(a_string, "DS     0H");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_1 complex #6");
										trace_rec_3();
									}
							}

						if((operand_1 == 1) && (if_and == 1))
							{
								printf("c2z_if.c if_case_1 E-95 complex operand_1 == 1 && if_and == 1 NOT CODED\n");
								c2_error();
							}
						
						if(operand_1 == 2)		/* <=	*/
							{
								printf("c2z_if.c if_case_1 E-96 complex operand_1 <= Error#2\n");
								c2_error();
							}

						if(operand_1 == 3)		/* <=	*/
							{
								printf("c2z_if.c if_case_1 E-97 complex operand_1 <= Error#3\n");
								c2_error();
							}

						if(operand_1 == 4)		/* >=	*/
							{
								printf("c2z_if.c if_case_1 E-98 complex operand_1 <= Error#4\n");
								c2_error();
							}

						if(operand_1 == 5)		/* =	*/
							{
								printf("c2z_if.c if_case_1 E-99 complex operand_1 <= Error#5\n");
								c2_error();
							}

						if(operand_1 == 6)		/* <	*/
							{
								printf("c2z_if.c if_case_1 E-100 complex operand_1 <= Error#6\n");
								c2_error();
							}

						if(operand_1 == 7)		/* >	*/
							{
								printf("c2z_if.c if_case_1 E-101 complex operand_1 <= Error#7\n");
								c2_error();
							}
					}
			}	

		convert = 1;				
	}


/* *************************************************** 
*  if_case_2                                         *
* ************************************************** */
void if_case_2()		 /* != */	 
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_2");
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field4[VAR_LGTH];
		char field4a[VAR_LGTH];

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
		int x10 = 0;
		int if_complex = 0;
		int if_bracket = 0;

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
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1");
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
									}
							}
						
						if(x3 == 0)
							{
								printf("c2z_if.c if_case_2 bracket = 1 E-102 field1 Not Found = %s\n",field1); 
								c2_error();
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
										printf("if_case_2 bracket = 1 E-103 field2 Not Found = %s\n",field2);
										c2_error(); 
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
										printf("c2z_if.c if_case_2 bracket = 1 E-104 field4 Not Found = %s\n",field4); 
										c2_error();
									}
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #1");
								trace_rec_3();
							}
						work_use_ct[49]++;

						strcpy(a_string, "         LARL  R8,C370ZERO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #2");
								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #3");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R6,");
						strcat(a_string, ar_field7);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #11");
								trace_rec_3();
							}

						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcpy(start_while, a_string);
						strcat(a_string, "B");
						check_length();
						strcat(a_string, "DS    0H");
						strcpy(wk_remark," if    */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #12");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #13");
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
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #14");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #15");
								trace_rec_3();
							}
						
						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "F");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #16");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #17");
								trace_rec_3();
							}
						work_use_ct[49]++;

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #18");
								trace_rec_3();
							}

						strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #19");
								trace_rec_3();
							}
			
						strcpy(a_string, "         LA    R6,");
						strcat(a_string, ar_field6);
						strcat(a_string, "(R0,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #20");
								trace_rec_3();
							}

						strcpy(a_string, "         JLU   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "B");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #21");
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
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #22");
								trace_rec_3();
							}

						for(I=0; I < lit_ct; I++)
							{
								if(rct == w_literal[I].lit_rct)
									{
										strcpy(field2a, w_literal[I].lit_use_cname);
									} 
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field2a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #23");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #24");
								trace_rec_3();
							}

						strcpy(a_string, "         JLE   L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 1 #25");
								trace_rec_3();
							}
					}

				if(if_bracket == 0)
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 0");
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
								printf("c2z_if.c if_case_2 E-105 field1 Not Found = %s\n",field1);
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

						p = strstr(field2, "'");
						if(p)
							{
								x10 = 1;
							}

						if((fd2_type == 2) && (x10 ==0))
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
										printf("c2z_if.c if_case_2 E-106 field2 Not Found = %s\n",field2);
										c2_error();
									}
							}

						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcpy(o_string, a_string);
						check_length();
						strcat(a_string, "DS     0H");

						if(fd1_type == 1)
							{
								strcpy(a_string,"*         CP    ");
								strcat(a_string, field1a);
							}
						
						if((fd1_type == 2) && (fd2_type == 0) && (x10 == 0))
							{
								for(I=0; I < char_ct; I++)
									{
										if(w_charlit[I].clit_rct == rct)
											{
												strcpy(field2a, w_charlit[I].clit_cname);
                                         							x3 = w_charlit[I].clit_lgth;
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
										strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 0 #20");
										trace_rec_3();
									}

						
 								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field2a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 0 #21");
										trace_rec_3();
									}

								strcpy(a_string, "         CLC   0(");
								snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
								strcat(a_string, wk_strg);
								strcat(a_string, ",R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 0 #22");
										trace_rec_3();
									}
							}
						
						if((fd1_type == 2) && (x10 == 1))
							{
								for(I=0; I < char_ct; I++)
									{
										if(w_charlit[I].clit_rct == rct)
											{
												strcpy(field2a, w_charlit[I].clit_cname);
                                         							x3 = w_charlit[I].clit_lgth;
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
										strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 0 #20");
										trace_rec_3();
									}

						
 								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field2a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 0 #21");
										trace_rec_3();
									}

								strcpy(a_string, "         CLC   0(");
								snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
								strcat(a_string, wk_strg);
								strcat(a_string, ",R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 0 #22");
										trace_rec_3();
									}
							}

						if((fd1_type == 2) && (fd2_type == 2))
							{
								
								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, field1a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, field1);
								strcat(wk_remark, " */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 0 #23");
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
										strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 0 #24");
										trace_rec_3();
									}

								strcpy(a_string, "         CLC   0(");
								snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
								strcat(a_string, wk_strg);
								strcat(a_string, ",R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 0 #25");
										trace_rec_3();
									}
							}

						strcpy(a_string, "         JLE   ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_2 if_bracket = 0 #23");
								trace_rec_3();
							}
					}
			}	

		if(if_complex == 1)
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
				while(ch != ' ')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

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

				printf("if_case_2 complex == 1 E-107 NEED TO FINISH Second Half\n");
				c2_error();

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcpy(o_string, a_string);
				check_length();
				strcat(a_string, "DS     0H");

				if(fd1_type == 2)
					{
						strcpy(a_string,"*         CP    ");
						strcat(a_string, field1a);
					}

				if(fd1_type == 1)
					{
						strcpy(a_string,"*         CLC   ");
						strcat(a_string, field1a);
					}

				strcat(a_string,",");
				if(fd2_type == 2)
					{
						strcat(a_string, field2a);
					}

				if(fd2_type == 1)
					{
						strcat(a_string, "=P'");
						strcat(a_string, field2);
						strcat(a_string, "'");
					}
				strcpy(wk_remark, " IF !=    */");
				write_remark();
				if(punch_code == 1)
					trace_rec_3();

				strcpy(a_string, "*         JLE   ");
				strcat(a_string, o_string);
				src_line();
				if(punch_code == 1)
					trace_rec_3();
			}

		convert = 1;

	}


/* *************************************************** 
*  if_case_3                                         *
* ************************************************** */
void if_case_3()		 /* >  */	
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_3");
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];

		int pi;
		int pi2;
		int fd1_type = 0;
		int fd2_type = 0;
		int I = 0;
		int x = 0;
		int x2 = 0;
		int x3 = 0;
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
		x3 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ' ')
			{
				if((ch == '_') && (x3 == 0))
					{
						x3 = 1;
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
				printf("c2z_if.c if_case_3 E-108 field1 Not Found = %s\n",field1);
				c2_error();
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
				printf("c2z_if.c if_case_3 E-109 field1 Not Found = %s\n",field1);
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
				printf("c2z_if.c if_case_3 E-110 field2 Not Found = %s\n",field2);
				c2_error();
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

		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcpy(a_string, "L");
		strcat(a_string, wk_strg);
		strcpy(o_string, a_string);
		check_length();
		strcat(a_string, "EQU    *");

		if(fd1_type == 2)
			{
				strcpy(a_string,"         CP    ");
				strcat(a_string, field1);
			}
		if(fd1_type == 1)
			{
				printf("c2z_if.c if_case_3 E-111 fd1_type == 1 NOT coded\n");
				c2_error();
			}

		strcat(a_string,",");
		if(fd2_type == 2)
			{
				strcat(a_string, field2);
			}
		if(fd2_type == 1)
			{
				strcat(a_string, "=P'");
				strcat(a_string, field2);
				strcat(a_string, "'");
			}

		strcpy(wk_remark, " IF !=    */");
		write_remark();
		if(punch_code == 1)
			trace_rec_3();

			strcpy(a_string, "         JLH   ");
		strcat(a_string, o_string);
		src_line();
		if(punch_code == 1)
			trace_rec_3();
	}


/* *************************************************** 
*  if_case_4                                         *
* ************************************************** */
void if_case_4()		 /* <  */	
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_4");
				trace_rec_1();
			}

		char *p, *p4;
		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field4[VAR_LGTH];
		char field4a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field6[VAR_LGTH];
		char field6a[VAR_LGTH];
		
		int pi;
		int pi2;
		int fd1_type = 0;
		int fd2_type = 0;
		int I = 0;
		int x = 0;
		int x2 = 0;
		int x3 = 0;
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
						strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 1");
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

				pi2 = 0;
				ch = p_string[pi];
				while(ch != ')')
					{
						field3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field3[pi2] = '\0';

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

				pi2 = 0;
				ch = p_string[pi];
				while(ch != ')')
					{
						field6[pi2] = ch;
						pi2++;
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
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_4 E-112 field1 Not Found = %s\n",field1);
						c2_error();
					}

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
								ret = strcmp(field4, gw_variable[I].gv_name);
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
						printf("c2z_if.c if_case_4 E-113 field4 Not Found = %s\n",field4);
						c2_error();
					}

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
									}							
							}
					}

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_4 E-114 field6 Not Found = %s\n",field6);
						c2_error();
					}
				
				strcpy(a_string, "         CLC   ");
				strcat(a_string, "=C'");
				strcat(a_string, "\"");
				strcat(a_string, "'");
				strcat(a_string, ",");
				strcat(a_string, field1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_4 #1");
						trace_rec_3();
					}

				if(operand_1 == 1)
					{
						printf("c2z_if.c if_case_4 E-115 operand_1 == 1 NOT CODED\n");
						c2_error();
					}

				if(operand_1 == 2)
					{
						strcpy(a_string, "         JLE   ");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, "L");
						strcat(a_string, wk_strg);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_4 #2");
								trace_rec_3();
							}
					}

				if(operand_1 == 3)
					{
						printf("c2z_if.c if_case_4 E-116 operand_1 == 3 NOT CODED\n");
						c2_error();
					}
				
				if(operand_1 == 4)
					{
						printf("c2z_if.c if_case_4 E-119 operand_1 == 4 NOT CODED\n");
						c2_error();
					}

				if(operand_1 == 5)
					{
						printf("c2z_if.c if_case_4 E-120 operand_1 == 5 NOT CODED\n");
						c2_error();
					}

				if(operand_1 == 6)
					{
						printf("c2z_if.c if_case_4 E-121 operand_1 == 6 NOT CODED\n");
						c2_error();
					}

				if(operand_1 == 7)
					{
						printf("c2z_if.c if_case_4 E-122 operand_1 == 7 NOT CODED\n");
						c2_error();
					}

				strcpy(a_string, "         LARL  R9");
				strcat(a_string, field4a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_4 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8");
				strcat(a_string, field6a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_4 #4");
						trace_rec_3();
					}
	
				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_4 #5");
						trace_rec_3();
					}

				if(operand_2 == 1)
					{
						printf("c2z_if.c if_case_4 E-123 operand_2 == 1 NOT CODED\n");
						c2_error();
					}

				if(operand_2 == 2)
					{
						printf("c2z_if.c if_case_4 E-124 operand_2 == 2 NOT CODED\n");
						c2_error();
					}

				if(operand_2 == 3)
					{
						printf("c2z_if.c if_case_4 E-125 operand_2 == 3 NOT CODED\n");
						c2_error();
					}
				
				if(operand_2 == 4)
					{
						printf("c2z_if.c if_case_4 E-126 operand_2 == 4 NOT CODED\n");
						c2_error();
					}

				if(operand_2 == 5)
					{
						printf("c2z_if.c if_case_4 E-127 operand_2 == 5 NOT CODED\n");
						c2_error();
					}
	
				if(operand_2 == 6)
					{
						strcpy(a_string, "         JLE   ");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, "L");
						strcat(a_string, wk_strg);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_4 #6");
								trace_rec_3();
							}

						strcpy(a_string, "         JLH   ");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, "L");
						strcat(a_string, wk_strg);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_4 #7");
								trace_rec_3();
							}
					}

				if(operand_2 == 7)
					{
						printf("c2z_if.c if_case_4 E-128 operand_2 == 7 NOT CODED\n");
						c2_error();
					}

			}

		if(complex_if == 0)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0");
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
						printf("c2z_if.c if_case_4 E-129 field1 Not Found = %s\n",field1);
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
								printf("c2z_if.c if_case_4 E-130 field2 Not Found = %s\n",field2);
								c2_error();
							}
					
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

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcpy(o_string, a_string);
				check_length();
				strcat(a_string, "EQU    *");

				if(fd1_type == 2)
					{
						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field1a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #1");
								trace_rec_3();
							}
					}

				if(fd1_type == 1)
					{
						printf("c2z_if.c if_case_4 fd1_type == 1 NOT Coded\n");
						printf("c2z_if.c if_case_4 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				strcat(a_string,",");
				if(fd2_type == 2)
					{
						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field2a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field2);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #2");
								trace_rec_3();
							}
	
						strcpy(a_string,"         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #3");
								trace_rec_3();
							}
					}

				if(fd2_type == 1)
					{
						for(I=0; I < lit_ct; I++)
							{
								if(rct == w_literal[I].lit_rct)
									{
										strcpy(field2a, w_literal[I].lit_use_cname);
									} 
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, field2a);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #4");
								trace_rec_3();
							}

						strcpy(a_string,"         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #5");
								trace_rec_3();
							}
					}

				if(operand_1 == 1)			/* ==	*/
					{
						strcpy(a_string, "         JNE  ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #6");
								trace_rec_3();
							}
					} 

				if(operand_1 == 2)			/* !=	*/
					{
						strcpy(a_string, "         JLE  ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #7");
								trace_rec_3();
							}
					}

				if(operand_1 == 3)			/* <=	*/
					{
						printf("c2z_if.c if_case_4 complex = 0 E-131 operand_1 == 3 NOT CODED\n");
						c2_error();
					}

				if(operand_1 == 4)			/* >=	*/
					{
						printf("c2z_if.c if_case_4 complex = 0 E-132 operand_1 == 4 NOT CODED\n");
						c2_error();
					}

				if(operand_1 == 5)			/* =	*/
					{
						printf("c2z_if.c if_case_4 complex = 0 E-133 operand_1 == 5 NOT CODED\n");
						c2_error();
					}

				if(operand_1 == 6)			/* <	*/
					{
						strcpy(a_string, "         JLE   ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #8");
								trace_rec_3();
							}

						strcpy(a_string, "         JLH   ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #9");
								trace_rec_3();
							}
					}

				if(operand_1 == 7)			/* >	*/
					{
						printf("c2z_if.c if_case_4 complex = 0 E-134 operand_1 == 7 NOT CODED\n");
						c2_error();
					}
			}
	}


/* *************************************************** 
*  if_case_6                                         *
* ************************************************** */
void if_case_6()		 /* <=  */	
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_6");
				trace_rec_1();
			}

		char *p;
		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field4[VAR_LGTH];
		char field4a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field5a[VAR_LGTH];
		char field6[VAR_LGTH];
		char field6a[VAR_LGTH];

		int pi;
		int pi2;
		int fd1_type = 0;
		int fd2_type = 0;
		int I = 0;
		int if_10 = 0;
		int x = 0;
		int x2 = 0;
		int x3 = 0;
		int ret = 0;
		int ret1 = 0;
		
		p = strstr(p_string, "&&");		
		if(p)
			if_10 = 1;

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
				if(ch != '(')
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
				printf("c2z_if_c if_case_6 E-135 field1 Not Found = %s\n",field1);
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

		if(fd2_type == 1)
			{
				strcpy(field2a, field2);
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
						printf("c2z_if.c if_case_6 E-136 field2 Not Found = %s\n",field2);
						c2_error();
					}
			}

		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcpy(a_string, "L");
		strcat(a_string, wk_strg);
		strcpy(o_string, a_string);
		check_length();
		strcat(a_string, "EQU    *");

		if(fd1_type == 2)
			{
				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, field1a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_6 #1");
						trace_rec_3();
					}
			}

		if(fd1_type == 1)
			{
				printf("c2z_if.c if_case_6 E-137 fd1_type == 1 NOT Coded\n");
				c2_error();
			}

		if(fd2_type == 2)
			{
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field2a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field2);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_6 #2");
						trace_rec_3();
					}

				strcpy(a_string,"         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_6 #3");
						trace_rec_3();
					}
			}

		if(fd2_type == 1)
			{
			
				strcat(a_string, "=P'");
				strcat(a_string, field2a);
				strcat(a_string, "'");
			}
		
		strcpy(a_string, "         JLH   ");
		strcat(a_string, o_string);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_6 #4");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ");
		strcat(a_string, o_string);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_6 #5");
				trace_rec_3();
			}

		if(if_10 == 1)	/* combined statement	*/
			{
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
						field4[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field4[pi2] = '\0';
				
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(field4, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(field4a, gw_variable[I].gv_cname);
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

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_6 E-138 field4 Not Found = %s\n",field4);
						c2_error();
					}

				pi++;
				ch = p_string[pi];
				pi2 = 0;
				while(ch != ' ')
					{
						field5[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}	
				field5[pi2] = '\0';
				strcpy(field5a, null_field);
				
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
						field6[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}	
				field6[pi2] = '\0';

				x3 = 0;
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(field6, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(field6a, gw_variable[I].gv_cname);
								gw_variable[I].gv_use_ct++;
								x = strcmp(gw_variable[I].gv_type, "I");
								if(x == 0)
									{
										fd1_type = 2;
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_6 field6 Not Found = %s\n",field6);
						printf("c2z_if.c if_case_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
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
						printf("c2z_if.c if_case_6 field6 Not Found = %s\n",field6);
						printf("c2z_if.c if_case_6 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				ret = strcmp("<", field5);
				if(ret == 0)				
					{
						if(fd2_type == 2)
							{
								strcpy(a_string,"         CP    ");
								strcat(a_string, field4a);
							}

						if(fd2_type == 1)
							{
								printf("c2z_if.c if_case_6 fd2_type == 1 NOT Coded\n");
								printf("c2z_if.c if_case_6 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
							}

						strcat(a_string,",");
						if(fd2_type == 2)
							{
								strcat(a_string, field6a);
							}

						if(fd2_type == 1)
							{
								strcat(a_string, "=P'");
								strcat(a_string, field6a);
								strcat(a_string, "'");
							}
						strcpy(wk_remark, " IF !=    */");
						write_remark();
						if(punch_code == 1)
			 				{
								strcpy(trace_1, "c2z_if.c if_case_6 #6");
								trace_rec_3();
							}

						strcpy(a_string, "         JNL   ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
			 				{
								strcpy(trace_1, "c2z_if.c if_case_6 #7");
								trace_rec_3();
							}
					}
			}		
	}


/* *************************************************** 
*  if_case_7                                         *
* ************************************************** */
void if_case_7()		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_7");
				trace_rec_1();
			}

		char *p, *p7;
		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		
		char wk_sv_func[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield4[VAR_LGTH];
		char tfield4a[VAR_LGTH];
		char tfield5[VAR_LGTH];
		char tfield5a[VAR_LGTH];
		char tfield11[VAR_LGTH];
		char tfield11a[VAR_LGTH];

		int pi;
		int pi2;
		int fd11_type = 0;
		int operand_1 = 0;
		int I = 0;
		int x3 = 0;
		int v = 0;
		int if_complex = 0;
		int if_short = 0;
		int if_negative = 0;
		int ret = 0;
		int ret1 = 0;
		int ret2 = 0;

		var_use[10]++;

		p = strstr(p_string, "&&");
		if(p)
			if_complex = 1;

		p = strstr(p_string, "||");
		if(p)
			if_complex = 1;

		if(if_complex == 0)		
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_7 complex = 0");
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

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0)  && (ret1 == 0))
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
						printf("c2z_if.c if_case_7 E-458 field1 Not Found = %s\n",field1);
						c2_error();
					}

				pi++;
				ch = p_string[pi];
				if(ch == ')')
					{
						if_short = 1;
					}

				if(if_short == 1)		
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 Short");
								trace_rec_1();
							}
						
						p7 = strstr(p_string, "!isdigit");
						if(p7)
							if_negative = 1;

						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcpy(o_string, a_string);
						check_length();
						strcat(a_string, "DS     0H");

						if(if_negative == 0)
							{
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #1");
										trace_rec_1();
									}

								strcpy(a_string, "         LARL  R9,C370L1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #1");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field1a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, field1);
								strcat(wk_remark, " */");
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #2");
										trace_rec_3();
									}

								strcpy(a_string, "         MVC   0(1,R9),0(R8)");
								strcpy(wk_remark, " isdigit  */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #3");
										trace_rec_3();
									}
								work_use_ct[2]++;
							}

						if(if_negative == 1)
							{
								strcpy(a_string, "         LARL  R9,C370L1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #4");
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
										strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #5");
										trace_rec_3();
									}

								strcpy(a_string, "         MVC   0(1,R9),0(R8)");
								strcpy(wk_remark, " isdigit  */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #6");
										trace_rec_3();
									}
								work_use_ct[2]++;
							}

						strcpy(a_string, "         BRASL C370LNK,ISDIGIT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #7");
								trace_rec_3();
							}
	
						strcpy(a_string, "         LARL  R9,C370ISDG");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #8");
								trace_rec_3();
							}
	
						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #9");
								trace_rec_3();
							}
						work_use_ct[33]++;

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #10");
								trace_rec_3();
							}
						work_use_ct[31]++;

						if(if_negative == 1)
							{
								strcpy(a_string, "         JLE   ");
								strcat(a_string, o_string);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #12");
										trace_rec_3();
									}
							}
						
						if(if_negative == 0)
							{
								strcpy(a_string, "         JNE   ");
								strcat(a_string, o_string);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 comp = 0 neg = 0 #13");
										trace_rec_3();
									}
							}
					}


				if(if_short == 0)		
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 if-short = 0");
								trace_rec_1();
							}
						
						pi2 = 0;
						pi++;
						ch = p_string[pi];
						while(ch != ' ')
							{
								field2[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						field2[pi2] = '\0';

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

						while(ch != ')')
							{
								pi++;
								ch = p_string[pi];
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

						if(operand_1 == 1)			
							{
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcpy(a_string, "L");
								strcat(a_string, wk_strg);
								strcpy(o_string, a_string);
								check_length();
								strcat(a_string, "DS     0H");

								strcpy(a_string, "         LARL  R9,C370L1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #1");
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
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #2");
										trace_rec_3();
									}

								strcpy(a_string, "         MVC   0(1,R9),0(R8)");
								strcpy(wk_remark, " isdigit  */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #3");
										trace_rec_3();
									}
								work_use_ct[2]++;

								strcpy(a_string, "         BRASL C370LNK,ISDIGIT");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #4");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370ISDG");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #5");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370ONE");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #6");
										trace_rec_3();
									}
								work_use_ct[33]++;

								strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #7");
										trace_rec_3();
									}
								work_use_ct[31]++;

								strcpy(a_string, "         JLE   ");
								strcat(a_string, o_string);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #8");
										trace_rec_3();
									}
							}		

						if(operand_1 == 2)		
							{
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcpy(a_string, "L");
								strcat(a_string, wk_strg);
								strcpy(o_string, a_string);
								check_length();
								strcat(a_string, "DS     0H");

								strcpy(a_string, "         LARL  R9,C370L1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #9");
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
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #10");
										trace_rec_3();
									}

								strcpy(a_string, "         MVC   0(1,R9),0(R8)");
								strcpy(wk_remark, " isdigit  */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #11");
										trace_rec_3();
									}
								work_use_ct[2]++;

								strcpy(a_string, "         BRASL C370LNK,ISDIGIT");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #12");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370ISDG");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #13");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370ONE");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #14");
										trace_rec_3();
									}
								work_use_ct[33]++;

								strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #15");
										trace_rec_3();
									}

								strcpy(a_string, "         JLE   ");
								strcat(a_string, o_string);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_7 complex = 0 short #16");
										trace_rec_3();
									}
							}		

						if(operand_1 == 3)
							{
								printf("c2z_if.c if_case_7 E-459 NON-Short operand_1 = 3 NOT CODED\n");
								c2_error();
							}

						if(operand_1 == 4)
							{
								printf("c2z_if.c if_case_7 E-460 NON-Short operand_1 = 4 NOT CODED\n");
								c2_error();
							}

						if(operand_1 == 5)
							{
								printf("c2z_if.c if_case_7 E-461 NON-Short operand_1 = 5 NOT CODED\n");
								c2_error();
							}

						if(operand_1 == 6)
							{
								printf("c2z_if.c if_case_7 E-462 NON-Short operand_1 = 6 NOT CODED\n");
								c2_error();
							}

						if(operand_1 == 7)
							{
								printf("c2z_if.c if_case_7 E-463 NON-Short operand_1 = 7 NOT CODED\n");
								c2_error();
							}
					}
				
				return;
			}	

		if(if_complex == 1)		
			{
				pi = 0;
				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}

				pi++;
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
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				pi++;
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
						tfield4[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield4[pi2] = '\0';

				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ')')
					{
						tfield5[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield5[pi2] = '\0';

				x3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield2, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;
										strcpy(tfield2a, lw_variable[v].lv_cname);
									}

							}
					}

				if(x3 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(tfield2, gw_variable[v].gv_name);
										if(ret == 0)
											{				
												x3 = 1;
												strcpy(tfield2a, gw_variable[v].gv_cname);
											}
									}
							}
					}
			
				if(x3 == 0)
					{
						printf("c2z_if.c if_case_7 complex == 1 E-464 tfield2 Not Found = %s\n",tfield2);
						c2_error();
					}

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #1");
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
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #2");
						trace_rec_3();
					}
				var_use[1]++;
				work_use_ct[2]++;

				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #3");
						trace_rec_3();
					}
				
				strcpy(a_string, "         BRASL C370LNK,ISDIGIT");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #4");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370ISDG");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #6");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #7");
						trace_rec_3();
					}
				work_use_ct[31]++;

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "         JLE   L");
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #8");
						trace_rec_3();
					}

				x3 = 0;
				for(I=0; I < fn_ct; I++)
					{
						ret = strcmp(tfield4, w_function[I].fn_name);
						if(ret == 0)
							{
								strcpy(tfield4a, w_function[I].fn_cname);
								strcpy(tfield11, w_function[I].fn_ret_var);
								strcpy(wk_sv_func, tfield4);
							}
					}
			
				x3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield5, lw_variable[v].lv_name);
								ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;
										strcpy(tfield5a, lw_variable[v].lv_cname);
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

				if(x3 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(tfield5, gw_variable[v].gv_name);
										if(ret == 0)
											{		
												x3 = 1;
												strcpy(tfield5a, gw_variable[v].gv_cname);
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
					}		
				
				if(x3 == 0)
					{
						printf("c2z_if.c if_case_7 complex == 1 E-465 tfield5 Not Found = %s\n",tfield5);
						c2_error();
					}

				strcpy(a_string, "         LARL  R9,");	
				strcat(a_string, tfield5a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield5);
				strcat(wk_remark, " */ ");
				write_remark();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #9");
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
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #10");
						trace_rec_3();
					}
	
				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #11");
						trace_rec_3();
					}
					
				strcpy(a_string, "         BRASL C370LNK,");
				strcat(a_string, tfield4a);
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #12");
						trace_rec_3();
					}

				x3 = 0;
				if(lv_ct > 0)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(tfield11, lw_variable[v].lv_name);
								ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{				
										x3 = 1;
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

			if(x3 == 0)
					{
						if(gv_ct > 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(tfield11, gw_variable[v].gv_name);
										if(ret == 0)
											{				
												x3 = 1;
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

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_7 complex == 1 E-466 tfield11 Not Found = %s\n",tfield11);
						c2_error();
					}

				if(fd11_type == 2)
					{
						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield11a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield11);
						strcat(wk_remark, " */ ");
						write_remark();
						if(punch_code == 1)
							{	
								strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #13");
								trace_rec_3();
							}
						
						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{	
								strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #14");
								trace_rec_3();
							}
						
						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{	
								strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #15");
								trace_rec_3();
							}
					}

				if(fd11_type == 1)
					{
						printf("c2z_while.c c2_while_14 E-467 fd2_type == 1 NOT CODED\n");
						c2_error();
					}

				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				src_line();
				if(punch_code == 1)
					{	
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #16");
						trace_rec_3();
					}
			
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "         JLU   L");
				strcat(a_string, wk_strg);
				src_line();
				var_use[1]++;
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #17");
						trace_rec_3();
					}
			
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				check_length();
				strcat(a_string, "DS    0H");
				strcpy(wk_remark," while    */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_7 complex == 1 #18");
						trace_rec_3();
					}
			}
	}


/* *************************************************** 
*  if_case_8                                         *
* ************************************************** */
void if_case_8()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_8 isalpha");
				trace_rec_1();
			}

		char *p4, *wkp;
		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];

		int pi;
		int pi2;
		int I = 0;
		int x3 = 0;
		int complex_if = 0;
		int ret = 0;
		int ret1 = 0;
		
		p4 = strstr(p_string, "&&");
		if(p4)
			complex_if = 1;

		p4 = strstr(p_string, "||");
		if(p4)
			complex_if = 2;

		if(complex_if == 0)			
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
				x3 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ')')
					{
						if((ch == '_') && (x3 == 0))
							{
								x3 = 1;
							}
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';
				
				pi++;
				ch = p_string[pi];
				
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
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2c_if.c c2_case_8 E-306 field1 Not Found = %s\n",field1);
						c2_error();
					}

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_8 isalpha #1");
						trace_rec_3();
					}
				work_use_ct[59]++;

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field1a);
                            strcpy(wk_remark, " ");
				strcat(wk_remark, field1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_8 isalpha #2");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_8 isalpha #3");
						trace_rec_3();
					}

				strcpy(a_string, "         BRASL C370LNK,ISALPHA");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_8 isalpha #4");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370ISAL");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_8 isalpha #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_8 isalpha #6");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_8 isalpha #7");
						trace_rec_3();
					}

				strcpy(a_string, "         JLNE  ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_8 isalpha #8");
						trace_rec_3();
					}
			}	

		if(complex_if == 1)
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
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_8 isalpha E-307 field1 Not Found = %s\n",field1);
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

				pi2 = 0;
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
						if((ret == 0) && (ret == 0))
							{
								x3 = 1;
								strcpy(field2a, lw_variable[I].lv_cname);
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
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_8 E-308 Field2 Not Found = %s\n",field2);
						c2_error();
					}

				var_use[9]++;
		
				wkp = strstr(p_string,"!");
				if(wkp)				
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

						strcpy(a_string, "         MVC   C370L1A,");
						strcat(a_string, field1);
						strcpy(wk_remark, " isalpha  */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_8 isalpha #9");
								trace_rec_3();
							}
						work_use_ct[59]++;

						strcpy(a_string, "         BRASL C370LNK,ISALPHA");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_8 isalpha #10");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370ISAL");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_8 isalpha #11");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_8 isalpha #12");
								trace_rec_3();
							}
						work_use_ct[33]++;

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_8 isalpha #13");
								trace_rec_3();
							}

						strcpy(a_string, "         JLE   ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_8 isalpha #14");
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

						strcpy(a_string, "         MVC   C370L1A,");
						strcat(a_string, field1);
						strcpy(wk_remark, " isalpha  */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_8 isalpha #15");
								trace_rec_3();
							}
						work_use_ct[59]++;

						strcpy(a_string, "         BRASL C370LNK,ISALPHA");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_8 isalpha #16");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370ISAL");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_8 isalpha #17");
								trace_rec_3();
							}
	
						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_8 isalpha #18");
								trace_rec_3();
							}
						work_use_ct[33]++;

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_8 isalpha #19");
								trace_rec_3();
							}

						strcpy(a_string, "         JNE   ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_8 isalpha #20");
								trace_rec_3();
							}
					}
			}
	}



/* *************************************************** 
*  if_case_9                                         *
* ************************************************** */
void if_case_9()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_9");
				trace_rec_1();
			}

		char *p8;
		char ch;
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];

		int pi;
		int pi2;
		int I = 0;
		int ret = 0;
		int ret1 = 0;
		int x3 = 0;
				
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
								strcpy(field2a, gw_variable[I].gv_cname);
							}
					}
			}
					
		p8 = strstr(field1, "!");
		if(p8)				
			{
						
			}
		else
			{
				printf("IF case 9 NO ! in FEOF\n");
				exit(1);
			}
						
	}


/* *************************************************** 
*  if_case_10                                        *
* ************************************************** */
void if_case_10()		/* if(strcmp(token, "END") == 0)	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_10 strcmp");
				trace_rec_1();
			}

		int pi;
		int pi2;
		int if_1 = 0;
		int if_2 = 0;
		int if_4 = 0;
		int I = 0;
              int x3 = 0;
		int ret = 0;
		int ret1 = 0;
		int operand_1 = 0;

		char *p;
		char ch;
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];

		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
						
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
						pi2++;
					}
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
		while(ch != ' ')
			{
				tfield3[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield3[pi2] = '\0';

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
						printf("c2z_if.c c2_if_10 if_1 = 1 tfield1 Not Found = %s\n",tfield1);
						printf("c2z_if.c c2_if_10 if_1 = 1 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				p = strstr(tfield3, "==");
				if(p)
					operand_1 = 1;

				p = strstr(tfield3, "!=");
				if(p)
					operand_1 = 2;

				for(I=0; I < char_ct; I++)
					{
						if(w_charlit[I].clit_rct == rct)
							{
								strcpy(tfield2a, w_charlit[I].clit_cname);
                                         			x3 = w_charlit[I].clit_lgth;
							}
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield2a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_10 strcmp #1");
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
						strcpy(trace_1, "c2z_if.c if_case_10 strcmp #2");
						trace_rec_3();
					}

				strcpy(a_string, "         CLC   0(");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
				strcat(a_string, wk_strg);
				strcat(a_string, ",R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_10 strcmp #3");
						trace_rec_3();
					}

				if(operand_1 == 1)
					{
						strcpy(a_string, "         JNE   ");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, "L");
						strcat(a_string, wk_strg);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_10 strcmp #4");
								trace_rec_3();
							}
					}

				if(operand_1 == 2)
					{
						strcpy(a_string, "         JE    ");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, "L");
						strcat(a_string, wk_strg);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_10 strcmp #5");
								trace_rec_3();
							}
					}

				convert = 1;
			}
	

		if(if_1 == 0)		/* literal for strcmp field1  	*/
			{
				if_4 = 0;
				if(lv_ct > 0)
					{
						for(I = 0; I < lv_ct; I++)
							{
								ret = strcmp(field2, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										if_4 = 1;
										strcpy(field2a, lw_variable[I].lv_cname);
									}
							}
					}
			
				if(if_4 == 0)
					{
						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										if_2 = strcmp(field2, gw_variable[I].gv_name);
										if(if_2 == 0)
											{
												if_4 = 1;
												strcpy(field2a, gw_variable[I].gv_cname);
											}
									}
							}
					}

				if(if_4 == 0)
					{
						printf("c2z_if.c c2_if_10 if_1 = 0 field2 Not Found = %s\n",field2);
						printf("c2z_if.c c2_if_10 if_1 = 0 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				for(I=0; I < char_ct; I++)
					{
						if(w_charlit[I].clit_rct == rct)
							{
								strcpy(field1a, w_charlit[I].clit_cname);
                                         			x3 = w_charlit[I].clit_lgth;
							}
					}

 				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, field2a);
                            strcpy(wk_remark, " ");
				strcat(wk_remark, field2);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_10 strcmp #10");
						trace_rec_3();
					}
	
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_10 strcmp #11");
						trace_rec_3();
					}

				strcpy(a_string, "         CLC   0(");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
				strcat(a_string, wk_strg);
				strcat(a_string, ",R8),0(R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_10 strcmp #12");
						trace_rec_3();
					}

				strcpy(a_string, "         JNE   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, "L");
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_10 strcmp #13");
						trace_rec_3();
					}

				convert = 1;

			}
	}


/* *************************************************** 
*  Punch out DEFAULT in CASE                         *
* ************************************************** */
void c2_case_default(void)
	{
		if(if_case == 1)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_if.c c2_case_default");
						trace_rec_1();
					}

				/* generate sv_case_break */
				strcpy(save_case_break, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(save_case_break, wk_strg);
				strcat(save_case_break, "E");
			}
	}
	

/* *************************************************** 
*  Punch out SWITCH END statement                    *
* ************************************************** */
void c2_case_end(void)
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c c2_case_end");
				trace_rec_1();
			}

		strcpy(a_string, sw_tag);
		check_length();
		strcat(a_string, "DS    0H");
		strcpy(wk_remark, " end case */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_if.c c2_case_end #1");
				trace_rec_3();
			}

		if_case = 0;
		convert = 1;
	}

/* *************************************************** 
*  Punch out SWITCH statement                        *
* ************************************************** */
void c2_switch(void)
	{		
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c c2_switch");
				trace_rec_1();
			}

		if_case = 0;

		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];

		int pi;
		int pi2;
		int x3 = 0;
		int x4 = 0;
		int I = 0;
		int ret = 0;
		int ret1 = 0;
		int size = 0;

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
		while(ch != ')')
			{
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field1[pi2] = '\0';

		c_name++;
		snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
		strcpy(c_wkname, "C37F");
		strcat(c_wkname, wk_strg);
		x4 = strlen(c_wkname);
		c_wkname[x4] = '\0';
		strcpy(field1a, c_wkname);
						
		x3 = 0;
		if(gv_ct > 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(field1, gw_variable[I].gv_name);
						if(ret == 0)
							{
								strcpy(field1a, gw_variable[I].gv_cname);
								x3 = 1;
							}
					}
			}

		if(x3 == 0)
			{
				if(lv_ct > 0)
					{
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(field1, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										strcpy(field1a, lw_variable[I].lv_cname);
										x3 = 1;
									}
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
				strcpy(gw_variable[gv_ct].gv_cname, field1a);	
				strcpy(gw_variable[gv_ct].gv_name, field1);  	
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
					
		if((global_st == 1) && (x3 == 0))		/* local variable	*/
			{
				x3 = 0;
				if(lv_ct > 0)
					{
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(field1, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										strcpy(field1a, lw_variable[I].lv_cname);
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
						strcpy(lw_variable[lv_ct].lv_cname, field1a);	
						strcpy(lw_variable[lv_ct].lv_name, field1);  	
						strcpy(lw_variable[lv_ct].lv_type, "I");
						lw_variable[lv_ct].lv_lgth = 0;
						strcpy(lw_variable[lv_ct].lv_value, "0");
						lw_variable[lv_ct].lv_current_lgth = 0;
						lw_variable[lv_ct].lv_init = 0;
						strcpy(lw_variable[lv_ct].lv_literal,null_field);
						lw_variable[lv_ct].lv_use_ct = 0;
						lv_ct++;
					}
			}

		/*  save switch field value */
		strcpy(sw_field, field1a);

		/*  save rct for end of case label */
		strcpy(sw_tag, "L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcat(sw_tag, wk_strg);
		strcat(sw_tag,"E");

		if_case = 1;
	}


/* *************************************************** 
*  Punch out if(in_stack[ndx][0] == '\0'             *
* ************************************************** */
void if_case_11()			/*	if(in_stack[ndx][0] == '\0' 	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_11");
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
		char field4a[VAR_LGTH];
		char field9a[VAR_LGTH];
		char field11[VAR_LGTH];

		int pi;
		int pi2;
		int fd3_type = 0;
		int if_complex = 0;
		int I = 0;
		int x2 = 0;
		int x3 = 0;

		char tfield1[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield8[VAR_LGTH];
						
		char ar_field5[32];
		char ar_field6[32];
		char ar_field7[32];
		char ar_field8[32];
		char ar_field9[32];
		char ar_field10[32];
		char ar_field11[32];
		char ar_field11a[32];

		int operand_1 = 0;
		int operand_2 = 0;
		int ret = 0;
		int ret1 = 0;
		int fd4_type = 0;
		int fd9_type = 0;

		p = strstr(p_string, "&&");
		if(p)
			{
				if_complex = 1;
			}

		p = strstr(p_string, "||");
		if(p)
			{
				if_complex = 2;
			}

		if(if_complex == 0)		
			{
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
				while(ch != '[')
					{
						if((ch == '_') && (x3 == 0))
							{
								x3 = 1;
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

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_11 complex == 0 field1 Not Found = %s\n",field1);
						printf("c2z_if.c if_case_11 complex == 0 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
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
										x2 = 1;
									}
 
								if (isdigit(ch)) 	
									{
										x2 = 1;
									}
							}
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
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_11 complex == 0 field2 Not Found = %s\n",field2);
						printf("c2z_if.c if_case_11 complex == 0 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				pi2 = 0;
				x2 = 0;
				pi++;
				pi++;
				ch = p_string[pi];
				while(ch != ']')
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
						field3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field3[pi2] = '\0';

				if(fd3_type == 1)		/* character field value	*/
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
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_if.c if_case_11 complex == 0 field3 Not Found = %s\n",field3);
								printf("c2z_if.c if_case_11 complex == 0 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
							}
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(ar_field11, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(ar_field11a, lw_variable[I].lv_cname);
								lw_variable[I].lv_use_ct++;
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(ar_field11, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(ar_field11a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_11 complex == 0 field11 Not Found = %s\n",field11);
						printf("c2z_if.c if_case_11 complex == 0 rct = %d p_string = %s",rct,p_string);
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
				ch = p_string[pi];
				while(ch != ' ')
					{
						field4[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field4[pi2] = '\0';

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

				ch = p_string[pi];
				while(ch != '\'')
					{
						pi++;
						ch = p_string[pi];
					}
				
				ch = p_string[pi];
				while(ch != ')')
					{
						pi++;
						ch = p_string[pi];
					}
				
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 complex = 0");
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "M");
				check_length();
				strcat(a_string, "DS    0H");
				strcpy(wk_remark," if       */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 complex = 0 #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370B1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 complex = 0 #2");
						trace_rec_3();
					}

				strcpy(a_string, "         CLC   0(1,R6),0(R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 complex = 0 #3");
						trace_rec_3();
					}
 
				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 complex = 0 #4");
						trace_rec_3();
					}

				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 complex = 0 #6");
						trace_rec_3();
					}

				if(operand_1 == 2)		/* !=	*/
					{
						printf("c2z_if.c if_case_11 operand_1 == 2 Not Coded\n");
						printf("c2z_if.c if_cass_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);	
					}
						
				if(operand_1 == 3)		/* <=	*/
					{
						printf("c2z_if.c if_case_11 operand_1 == 3 Not Coded\n");
						printf("c2z_if.c if_cass_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);	
					}

				if(operand_1 == 4)		/* >=	*/
					{
						printf("c2z_if.c if_case_11 operand_1 == 4 Not Coded\n");
						printf("c2z_if.c if_cass_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);	
					}

				if(operand_1 == 5)		/* =	*/
					{
						printf("c2z_if.c if_case_11 operand_1 == 5 Not Coded\n");
						printf("c2z_if.c if_cass_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);	
					}

				if(operand_1 == 6)		/* <	*/
					{
						printf("c2z_if.c if_case_11 operand_1 == 6 Not Coded\n");
						printf("c2z_if.c if_cass_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);	
					}

				if(operand_1 == 7)		/* >	*/
					{
						printf("c2z_if.c if_case_11 operand_1 == 7 Not Coded\n");
						printf("c2z_if.c if_cass_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);	
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcat(a_string, "E");
				check_length();
				strcat(a_string, "DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 complex = 0 #7");
						trace_rec_3();
					}
			}	

		if(if_complex == 1)
			{
				printf("c2z_if.c if_case_11 while_complex == 1 NOT Coded\n");
				printf("c2z_fi.c if_case_11 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}
				
		if(if_complex == 2)
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

				x2 = 0;
				while(ch != ')')
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
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				while(ch != ' ')
					{
						tfield8[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				tfield8[pi2] = '\0';

				x2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ')')
					{
						if(ch != ' ')
							{
								if(x2 == 0)
									{
										if (isalpha(ch))	
											{
												fd9_type = 1;
												x2 = 1;
											}
 
										if (isdigit(ch)) 	
											{
												fd9_type = 2;
												x2 = 1;
											}
									}
							}
						pi++;
						ch = p_string[pi];
					}
				
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(tfield1, gw_variable[I].gv_name);
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
							}
					}
						
				if(x3 == 0)
					{
						printf("c2z_if.c if_case_11 tfield1 Not Found = %s\n",tfield1);
						printf("c2z_if.c if_case_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #1");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #2");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(4,R9),0(4,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #3");
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
						strcpy(trace_1, "c2z_if.c if_case_11 #4");
						trace_rec_3();
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcpy(start_while, a_string);
				strcat(a_string, "B");
				check_length();
				strcat(a_string, "DS    0H");
				strcpy(wk_remark," if    */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #6");
						trace_rec_3();
					}
				work_use_ct[49]++;

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
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_11 tfield2 Not Found = %s\n",tfield2);
						printf("c2z_if.c if_case_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield2a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield2);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #7");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(4,R9),0(4,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #8");
						trace_rec_3();
					}
						
				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "F");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #9");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #10");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #11");
						trace_rec_3();
					}

				strcpy(a_string, "         AP    0(4,R9),0(4,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #12");
						trace_rec_3();
					}
			
				strcpy(a_string, "         LA    R6,");
				strcat(a_string, ar_field6);
				strcat(a_string, "(R0,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #13");
						trace_rec_3();
					}

				strcpy(a_string, "         JLU   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "B");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #14");
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
						strcpy(trace_1, "c2z_if.c if_case_11 #15");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #16");
						trace_rec_3();
					}

				strcpy(a_string, "         ZAP   0(4,R9),0(4,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #17");
						trace_rec_3();
					}

				operand_1 = 0;
				if(operand_1 == 0)
					{
						p = strstr(tfield3, "==");
						if(p)
							operand_1 = 1;
					}

				if(operand_1 == 0)
					{
						p = strstr(tfield3, "!=");
						if(p)
							operand_1 = 2;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(tfield3, "<=");
						if(p)
							operand_1 = 3;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(tfield3, ">=");
						if(p)
							operand_1 = 4;
					}

				if(operand_1 == 0)
					{
						p = strstr(tfield3, "=");
						if(p)
							operand_1 = 5;
					}

				if(operand_1 == 0)
					{
						p = strstr(tfield3, "<");
						if(p)
							operand_1 = 6;
					}

				if(operand_1 == 0)
					{
						p = strstr(tfield3, ">");
						if(p)
							operand_1 = 7;
					}

				if(operand_1 == 1)		/* ==	*/
					{

						if(if_complex == 1)
							{
								printf("c2z_if.c if_case_11 operand == 1 & if_complex == 1 NOT CODED\n");
								printf("c2z_if.c if_case_11 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
							}

						if(if_complex == 2)
							{
								if(fd4_type == 1)
									{
										printf("c2z_if.c if_case_11 if_complex == 2 operand_1 == 1 fd4_type == 1 NOT CODED\n");
										printf("c2z_if.c if_case_11 rct = %d p_string = %s",rct,p_string);
										c2_debug();
										exit(1);
									}

								if(fd4_type == 2)
									{
										for(I=0; I < lit_ct; I++)
											{
												if(rct == w_literal[I].lit_rct)
													{
														strcpy(field4a, w_literal[I].lit_use_cname);
														break;
													} 
											}
									}

								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field4a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_11 #18");
										trace_rec_3();
									}

								strcpy(a_string, "         CP    0(4,R9),0(4,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_11 #19");
										trace_rec_3();
									}

								strcpy(a_string, "         JLE   L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, wk_strg);
								strcat(a_string, "T");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_11 #20");
										trace_rec_3();
									}
							}						
					}

				if(operand_1 == 2)		/* !=	*/
					{
						printf("c2z_if.c if_case_11 operand_1 == 2 Not Coded\n");
						printf("c2z_if.c if_cass_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);	
					}
						
				if(operand_1 == 3)		/* <=	*/
					{
						printf("c2z_if.c if_case_11 operand_1 == 3 Not Coded\n");
						printf("c2z_if.c if_cass_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);	
					}

				if(operand_1 == 4)		/* >=	*/
					{
						printf("c2z_if.c if_case_11 operand_1 == 4 Not Coded\n");
						printf("c2z_if.c if_cass_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);	
					}

				if(operand_1 == 5)		/* =	*/
					{
						printf("c2z_if.c if_case_11 operand_1 == 5 Not Coded\n");
						printf("c2z_if.c if_cass_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);	
					}

				if(operand_1 == 6)		/* <	*/
					{
						printf("c2z_if.c if_case_11 operand_1 == 6 Not Coded\n");
						printf("c2z_if.c if_cass_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);	
					}

				if(operand_1 == 7)		/* >	*/
					{
						printf("c2z_if.c if_case_11 operand_1 == 7 Not Coded\n");
						printf("c2z_if.c if_cass_11 rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);	
					}

				operand_2 = 0;
				if(operand_2 == 0)
					{
						p = strstr(tfield8, "==");
						if(p)
							operand_2 = 1;
					}

				if(operand_2 == 0)
					{
						p = strstr(tfield8, "!=");
						if(p)
							operand_2 = 2;
					}
				
				if(operand_2 == 0)
					{
						p = strstr(tfield8, "<=");
						if(p)
							operand_2 = 3;
					}
				
				if(operand_2 == 0)
					{
						p = strstr(tfield8, ">=");
						if(p)
							operand_2 = 4;
					}

				if(operand_2 == 0)
					{
						p = strstr(tfield8, "=");
						if(p)
							operand_2 = 5;
					}

				if(operand_2 == 0)
					{
						p = strstr(tfield8, "<");
						if(p)
							operand_2 = 6;
					}

				if(operand_2 == 0)
					{
						p = strstr(tfield8, ">");
						if(p)
							operand_2 = 7;
					}

				if(operand_2 == 1)		/* ==	*/
					{

						if(if_complex == 1)
							{
								printf("c2z_if.c if_case_11 operand_2 == 1 & if_complex == 1 NOT CODED\n");
								printf("c2z_if.c if_case_11 rct = %d p_string = %s",rct,p_string);
								c2_debug();
								exit(1);
							}

						if(if_complex == 2)
							{
								if(fd9_type == 1)
									{
										printf("c2z_if.c if_case_11 if_complex == 2 operand_1 == 1 fd4_type == 1 NOT CODED\n");
										printf("c2z_if.c if_case_11 rct = %d p_string = %s",rct,p_string);
										c2_debug();
										exit(1);
									}

								if(fd9_type == 2)
									{
										if(fd9_type == 1)
											{
												printf("c2z_if.c if_case_11 fd9_type == 1 NOT CODED\n");
												printf("c2z_if.c if_case_11 rct = %d p_string = %s",rct,p_string);
												c2_debug();
												exit(1);
											}
									}

								if(fd9_type == 2)
									{
										x3 = 0;
										for(I=0; I < lit_ct; I++)
											{
												if(rct == w_literal[I].lit_rct)
													{
														x3++;
														if(x3 == 2)
															{
																strcpy(field9a, w_literal[I].lit_use_cname);
																break;
															}
													} 
											}
					
										strcpy(a_string, "         LARL  R8,");
										strcat(a_string, field9a);
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_if.c if_case_11 #21");
												trace_rec_3();
											}
									}
					
								strcpy(a_string, "         CP    0(4,R9),0(4,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_11 #22");
										trace_rec_3();
									}

								strcpy(a_string, "         JLE   L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, wk_strg);
								strcat(a_string, "T");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_11 #23");
										trace_rec_3();
									}

								strcpy(a_string, "         JLU   L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_11 #23");
										trace_rec_3();
									}
							}
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcpy(start_while, a_string);
				strcat(a_string, "T");
				check_length();
				strcat(a_string, "DS    0H");
				strcpy(wk_remark," if    */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_11 #15");
						trace_rec_3();
					}
			}
	}


/* *************************************************** 
*  Punch out if(isaddop(ch) user function            *
* ************************************************** */
void if_case_12()			/*	if(isaddop(ch)) 	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_12");
				trace_rec_1();
			}

		int pi;
		int pi2;
		int I = 0;
		int x3 = 0;
		int ret = 0;
		int ret1 = 0;
		int ret2 = 0;
		int fd3_type = 0;

		char ch;
		char wk_sv_func[VAR_LGTH];
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield4a[VAR_LGTH];

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

		x3 = 0;
		if(lv_ct > 0)
			{
				for(I = 0; I < lv_ct; I++)
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
			}
		
		if(x3 == 0)
			{
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(tfield2, gw_variable[I].gv_name);
								if(ret == 0)
									{				
										x3 = 1;
										strcpy(tfield2a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;
									}
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_if.c if_case_12 tfield2 Not Found = %s\n",tfield2);
				printf("c2z_if.c if_case_12 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		x3 = 0;
		if(lv_ct > 0)
			{
				for(I = 0; I < lv_ct; I++)
					{
						ret = strcmp(tfield2, lw_variable[I].lv_name);
						ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{				
								x3 = 1;
								strcpy(tfield4a, lw_variable[I].lv_cname);
								lw_variable[I].lv_use_ct++;
							}
					}
			}
		
		if(x3 == 0)
			{
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(tfield2, gw_variable[I].gv_name);
								if(ret == 0)
									{				
										x3 = 1;
										strcpy(tfield4a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;
									}
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_if.c if_case_12 tfield4a Not Found = %s\n",tfield4a);
				printf("c2z_if.c if_case_12 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1); 
			}

		strcpy(a_string, "         LARL  R9,");
		strcat(a_string, tfield4a);
		strcpy(wk_remark, " ");
		strcat(wk_remark, tfield2);
		strcat(wk_remark, " */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_12 #1");
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
				strcpy(trace_1, "c2z_if.c if_case_12 #2");
				trace_rec_3();
			}
		
		strcpy(a_string, "         MVC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_12 #3");
				trace_rec_3();
			}
		
		for(I=0; I < fn_ct; I++)
			{
				ret = strcmp(tfield1, w_function[I].fn_name);
				if(ret == 0)
					{
						strcpy(tfield1a, w_function[I].fn_cname);
					}
			}

		strcpy(a_string, "         BRASL C370LNK,");
		strcat(a_string,tfield1a);
		strcpy(wk_remark, " if branch */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_12 #4");
				trace_rec_3();
			}
		
		for(I=0; I < fn_ct; I++)
			{
				ret = strcmp(tfield1, w_function[I].fn_name);
				if(ret == 0)
					{
						strcpy(tfield3, w_function[I].fn_ret_var);
						strcpy(wk_sv_func, tfield1);
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
						lw_variable[I].lv_use_ct++;
						ret2 = strcmp("I", lw_variable[I].lv_type);
						if(ret2 == 0)
							{
								fd3_type = 1;
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
								x3 = 1;
								strcpy(tfield3a, gw_variable[I].gv_cname);
								gw_variable[I].gv_use_ct++;
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_if.c if_case_12 tfield3 Not Found = %s\n",tfield3);
				printf("c2z_if.c if_case_12 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1); 
			}

		if(fd3_type == 1)		/* integer variable		*/
			{

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield3a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield3);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_12 #5");
						trace_rec_3();
					}
				
				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_12 #6");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_12 #7");
						trace_rec_3();
					}
				
				strcpy(a_string, "        JNE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_12 #8");
						trace_rec_3();
					}
			}

		if(fd3_type == 2)		/* character variable	*/
			{
				printf("c2z_if.c if_case_12 Character variable NOT CODED\n");
				printf("c2z_if.c if_case_12 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}
	}


void if_case_13()			
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_13");
				trace_rec_1();
			}

		char *p;
		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield4[VAR_LGTH];
		char tfield4a[VAR_LGTH];
		char tfield5[VAR_LGTH];
		char tfield6[VAR_LGTH];
		char tfield6a[VAR_LGTH];
				
		char ar_field5[VAR_LGTH];
		char ar_field6[VAR_LGTH];
		char ar_field7[VAR_LGTH];
		char ar_field8[VAR_LGTH];
		char ar_field9[VAR_LGTH];;
		char ar_field10[VAR_LGTH];
		char ar_field11[VAR_LGTH];

		int fd1_type = 0;
		int fd2_type = 0;
		int fd3_type = 0;
		int fd4_type = 0;
		int fd5_type = 0;
		int fd6_type = 0;
		int fd7_type = 0;

		int I;
		int s;
		int pi = 0;
		int pi2 = 0;
		int x2 = 0;
		int x3 = 0;
		int x20 = 0;
		int x21 = 0;
		int x22 = 0;
		int x80 = 0;
		int x81 = 0;
		int ret = 0;
		int ret1 = 0;
		int ret2 = 0;
		int operand_1 = 0;
		int operand_2 = 0;

		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '[')
					{
						x80 = I;
					}

				if(ch == '&')
					{
						x81 = I;
					}

				if(ch == '|')
					{
						x81 = I;
					}
			}

		if(x80 == 0)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_13 x80 = 0");
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

				ch = p_string[pi];
				while(ch != '(')
					{
						pi++;
						ch = p_string[pi];
					}

				pi2 = 0;
				x2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ' ')
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
								tfield6[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield6[pi2] = '\0';

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
						p = strstr(tfield5, "==");
						if(p)
							operand_2 = 1;
					}

				if(operand_2 == 0)
					{
						p = strstr(tfield5, "!=");
						if(p)
							operand_2 = 2;
					}
				
				if(operand_2 == 0)
					{
						p = strstr(tfield5, "<");
						if(p)
							operand_2 = 6;
					}

				if(operand_2 == 0)
					{
						p = strstr(tfield5, ">");
						if(p)
							operand_2 = 7;
					}
				if(operand_2 == 0)
					{
						p = strstr(tfield5, "<=");
						if(p)
							operand_2 = 3;
					}
				
				if(operand_2 == 0)
					{
						p = strstr(tfield5, ">=");
						if(p)
							operand_2 = 4;
					}

				if(operand_2 == 0)
					{
						p = strstr(tfield5, "=");
						if(p)
							operand_2 = 5;
					}

				if((fd1_type == 1) && (fd3_type == 0) && (fd4_type == 1) && (fd6_type == 1))
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
								printf("c2z_if.c if_case_13 E-379 x80 tfield1 Not Found = %s\n",tfield1);
								c2_error(); 
							}

						x21 = 0;
						if(fd3_type == 0)
							{
								for(I=0; I < lit_ct; I++)
									{
										if((w_charlit[I].clit_rct == rct) && (x21 == 0))
											{
												x21 = 1;
												strcpy(tfield3a, w_charlit[I].clit_cname);
                                                      					x3 = w_charlit[I].clit_lgth;
											}
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
								strcpy(trace_1, "c2z_if.c if_case_13 #1");
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
								strcpy(trace_1, "c2z_if.c if_case_13 #2");
								trace_rec_3();
							}

						strcpy(a_string, "         CLC   0(1,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 #3");
								trace_rec_3();
							}

						if(operand_1 == 1)
							{
								strcpy(a_string, "         JLNE  ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #4");
										trace_rec_3();
									}
							}

						if(operand_1 == 2)
							{
								strcpy(a_string, "         JLE   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #5");
										trace_rec_3();
									}
							}

						if(operand_1 == 3) 
							{
								strcpy(a_string, "         JLH   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #6");
										trace_rec_3();
									}
							}

						if(operand_1 == 4) 
							{
								printf("c2z_if.c if_case_13 E-380 operand (4) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}

						if(operand_1 == 5) 
							{
								printf("c2z_if.c if_case_13 E-381 operand (5) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}

						if(operand_1 == 6) 
							{
								printf("c2z_if.c if_case_13 E-382 operand (6) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}

						if(operand_1 == 7) 
							{
								printf("c2z_if.c if_case_13 E-383 operand (7) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
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
										lw_variable[I].lv_use_ct++;
										ret2 = strcmp("I", lw_variable[I].lv_type);
										if(ret2 == 0)
											{
												x20 = 1;
											}
										ret2 = strcmp("C", lw_variable[I].lv_type);
										if(ret2 == 0)
											{
												x20 = 2;
											}
									}
							}
					
						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(tfield4, gw_variable[I].gv_name);
										if(ret == 0) 
											{
												x3 = 1;
												strcpy(tfield4a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												ret2 = strcmp("I", gw_variable[I].gv_type);
												if(ret2 == 0)
													{
														x20 = 1;
													}
												ret2 = strcmp("C", gw_variable[I].gv_type);
												if(ret2 == 0)
													{
														x20 = 2;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_if.c if_case_13 x80 E-384 tfield4 Not Found = %s\n",tfield4); 
								c2_error();
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
										lw_variable[I].lv_use_ct++;
										ret2 = strcmp("I", lw_variable[I].lv_type);
										if(ret2 == 0)
											{
												x22 = 1;
											}
										ret2 = strcmp("C", lw_variable[I].lv_type);
										if(ret2 == 0)
											{
												x22 = 2;
											}
									}
							}
					
						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(tfield6, gw_variable[I].gv_name);
										if(ret == 0) 
											{
												x3 = 1;
												strcpy(tfield1a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												ret2 = strcmp("I", gw_variable[I].gv_type);
												if(ret2 == 0)
													{
														x22 = 1;
													}
												ret2 = strcmp("C", gw_variable[I].gv_type);
												if(ret2 == 0)
													{
														x22 = 2;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_if.c if_case_13 x80 E-385 tfield6 Not Found = %s\n",tfield6);
								c2_error(); 
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield4a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield4);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 #7");
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
								strcpy(trace_1, "c2z_if.c if_case_13 #8");
								trace_rec_3();
							}

						if((x20 == 1) && (x22 == 1))
							{
								strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #9");
										trace_rec_3();
									}
							}

						if((x20 == 2) && (x22 == 2))
							{
								strcpy(a_string, "         CLC   0(1,R9),0(R8)");
								src_line();
								if(punch_code == 1)									{
										strcpy(trace_1, "c2z_if.c if_case_13 #10");
										trace_rec_3();
									}
							}

						if(operand_2 == 1)
							{
								strcpy(a_string, "         JLNE  ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #11");
										trace_rec_3();
									}
							}

						if(operand_2 == 2)
							{
								printf("c2z_if.c if_case_13 E-386 operand (2) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						if(operand_2 == 3)
							{
								strcpy(a_string, "         JLH   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #12");
										trace_rec_3();
									}
							}

						if(operand_2 == 4) 
							{
								printf("c2z_if.c if_case_13 E-387 operand(4)  NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						if(operand_2 == 5) 
							{
								printf("c2z_if.c if_case_13 E-388 operand (5) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}
					
						if(operand_2 == 6) 
							{
								strcpy(a_string, "         JLH   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #13");
										trace_rec_3();
									}
							}

						if(operand_2 == 7) 
							{
								printf("c2z_if.c if_case_13 E-389 operand (7) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}
					}

				if((fd1_type == 1) && (fd3_type == 2) && (fd4_type == 1) && (fd6_type == 1))
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
								printf("c2z_if.c if_case_13 E-390 x80 tfield1 Not Found = %s\n",tfield1); 
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
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield1a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 #14");
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
								strcpy(trace_1, "c2z_if.c if_case_13 #15");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 #16");
								trace_rec_3();
							}

						if(operand_1 == 1) 
							{
								printf("c2z_if.c if_case_13 E-391 operand (1) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}

						if(operand_1 == 2) 
							{
								printf("c2z_if.c if_case_13 E-392 operand (2) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}

						if(operand_1 == 3) 
							{
								strcpy(a_string, "         JLH   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #17");
										trace_rec_3();
									}
							}

						if(operand_1 == 4) 
							{
								printf("c2z_if.c if_case_13 E-393 operand (4) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}

						if(operand_1 == 5) 
							{
								printf("c2z_if.c if_case_13 E-394 operand (5) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}

						if(operand_1 == 6) 
							{
								printf("c2z_if.c if_case_13 E-395 operand (6) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}

						if(operand_1 == 7)
							{
								strcpy(a_string, "         JLL   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #18");
										trace_rec_3();
									}
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
										lw_variable[I].lv_use_ct++;
										ret2 = strcmp("I", lw_variable[I].lv_type);
										if(ret2 == 0)
											{
												x20 = 1;
											}
										ret2 = strcmp("C", lw_variable[I].lv_type);
										if(ret2 == 0)
											{
												x20 = 2;
											}
									}
							}
					
						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(tfield4, gw_variable[I].gv_name);
										if(ret == 0) 
											{
												x3 = 1;
												strcpy(tfield4a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												ret2 = strcmp("I", gw_variable[I].gv_type);
												if(ret2 == 0)
													{
														x20 = 1;
													}
												ret2 = strcmp("C", gw_variable[I].gv_type);
												if(ret2 == 0)
													{
														x20 = 2;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_if.c if_case_13 x80 E-396 tfield4 Not Found = %s\n",tfield4); 
								c2_error();
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
										lw_variable[I].lv_use_ct++;
										ret2 = strcmp("I", lw_variable[I].lv_type);
										if(ret2 == 0)
											{
												x22 = 1;
											}
										ret2 = strcmp("C", lw_variable[I].lv_type);
										if(ret2 == 0)
											{
												x22 = 2;
											}
									}
							}
					
						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(tfield6, gw_variable[I].gv_name);
										if(ret == 0) 
											{
												x3 = 1;
												strcpy(tfield1a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												ret2 = strcmp("I", gw_variable[I].gv_type);
												if(ret2 == 0)
													{
														x22 = 1;
													}
												ret2 = strcmp("C", gw_variable[I].gv_type);
												if(ret2 == 0)
													{
														x22 = 2;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_if.c if_case_13 x80 E-397 tfield6 Not Found = %s\n",tfield6); 
								c2_error();
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield4a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield4);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 #19");
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
								strcpy(trace_1, "c2z_if.c if_case_13 #20");
								trace_rec_3();
							}

						if((x20 == 1) && (x22 == 1))
							{
								strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #21");
										trace_rec_3();
									}
							}

						if(operand_2 == 1) 
							{
								printf("c2z_if.c if_case_13 E-398 operand (1) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						if(operand_2 == 2) 
							{
								printf("c2z_if.c if_case_13 E-399 operand (2) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						if(operand_2 == 3) 
							{
								printf("c2z_if.c if_case_13 E-400 operand (3) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						if(operand_2 == 4) 
							{
								printf("c2z_if.c if_case_13 E-401 operand (4) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						if(operand_2 == 5) 
							{
								printf("c2z_if.c if_case_13 E-402 operand (5) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						if(operand_2 == 6)
							{
								strcpy(a_string, "         JLH   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #22");
										trace_rec_3();
									}
							}

						if(operand_2 == 7) 
							{
								printf("c2z_if.c if_case_13 E-403 operand (7) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}
					}

				if((fd1_type == 1) && (fd3_type == 0) && (fd4_type == 1) && (fd6_type == 0))
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
								printf("c2z_if.c if_case_13 x80 E-404 tfield1 Not Found = %s\n",tfield1); 
								c2_error();
							}

						x21 = 0;
						if(fd3_type == 0)
							{
								for(I=0; I < lit_ct; I++)
									{
										if((w_charlit[I].clit_rct == rct) && (x21 == 0))
											{
												x21 = 1;
												strcpy(tfield3a, w_charlit[I].clit_cname);
                                                      					x3 = w_charlit[I].clit_lgth;
											}
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
								strcpy(trace_1, "c2z_if.c if_case_13 #23");
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
								strcpy(trace_1, "c2z_if.c if_case_13 #24");
								trace_rec_3();
							}

						strcpy(a_string, "         CLC   0(1,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 #25");
								trace_rec_3();
							}

						if(operand_1 == 1)
							{
								strcpy(a_string, "         JLE   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								strcat(a_string, "C");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #26");
										trace_rec_3();
									}
							}

						if(operand_1 == 2)
							{
								printf("c2z_if.c if_case_13 E-405 operand (2) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}
						
						if(operand_1 == 3)
							{
								printf("c2z_if.c if_case_13 E-406 operand (3) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}

						if(operand_1 == 4)
							{
								printf("c2z_if.c if_case_13 E-407 operand (4) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}

						if(operand_1 == 5)
							{
								printf("c2z_if.c if_case_13 E-408 operand (5) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}

						if(operand_1 == 6)
							{
								printf("c2z_if.c if_case_13 E-409 operand (6) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
							}

						if(operand_1 == 7)
							{
								printf("c2z_if.c if_case_13 E-410 operand (7) NOT CODED operand_1 = %d\n",operand_1);
								c2_error();
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
										lw_variable[I].lv_use_ct++;
									}
							}
					
						if(x3 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(tfield4, gw_variable[I].gv_name);
										if(ret == 0) 
											{
												x3 = 1;
												strcpy(tfield4a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_if.c if_case_13 x80 E-411 tfield4 Not Found = %s\n",tfield4); 
								c2_error();
							}

						if(fd6_type == 0)
							{
								for(I=0; I < lit_ct; I++)
									{
										if(w_charlit[I].clit_rct == rct)
											{
												if(x21 == 2)
													{
														strcpy(tfield6a, w_charlit[I].clit_cname);
                                                      							x3 = w_charlit[I].clit_lgth;
													}
												x21++;
											}
									}
							}

						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, tfield4a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield4);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 #27");
								trace_rec_3();
							}

						if(fd6_type == 0)
							{
								for(I=0; I < lit_ct; I++)
									{
										if((w_charlit[I].clit_rct == rct) && (w_charlit[I].clit_uct == 2))
											{
												strcpy(tfield6a, w_charlit[I].clit_cname);
                                                      				}
									}
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield6a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield6);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 #28");
								trace_rec_3();
							}

						strcpy(a_string, "         CLC   0(1,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 #29");
								trace_rec_3();
							}

						if(operand_2 == 1)
							{
								strcpy(a_string, "         JLE   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, "L");
								strcat(a_string, wk_strg);
								strcat(a_string, "C");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_if.c if_case_13 #30");
										trace_rec_3();
									}
							}

						if(operand_2 == 2)
							{
								printf("c2z_if.c if_case_13 E-412 operand (2) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						if(operand_2 == 3)
							{
								printf("c2z_if.c if_case_13 E-413 operand (3) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						if(operand_2 == 4)
							{
								printf("c2z_if.c if_case_13 E-414 operand (4) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						if(operand_2 == 5)
							{
								printf("c2z_if.c if_case_13 E-415 operand (5) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						if(operand_2 == 6)
							{
								printf("c2z_if.c if_case_13 E-416 operand (6) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						if(operand_2 == 7)
							{
								printf("c2z_if.c if_case_13 E-417 operand (7) NOT CODED operand_2 = %d\n",operand_2);
								c2_error();
							}

						strcpy(a_string, "         JLNE  ");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, "L");
						strcat(a_string, wk_strg);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 #31");
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
								strcpy(trace_1, "c2z_if.c if_case_13 #32");
								trace_rec_3();
							}
					}

				convert = 1;
				return;
			}

		if((x80 > 0) && (x80 < x81))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_13 x81");
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

				x2 = 0;
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != '[')
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

				pi2 = 0;
				x2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ')')
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
				ch = p_string[pi];
				while(ch != ')')
					{
						if(x2 == 0)
							{
								if (isalpha(ch))	
									{
										fd7_type = 1;
										x2 = 1;
									} 

								if (isdigit(ch)) 	
									{
										fd7_type = 2;
										x2 = 1;
									}
							}
						pi++;
						ch = p_string[pi];
					}
				
				operand_1 = 0;
				if(operand_1 == 0)
					{
						p = strstr(tfield3, "==");
						if(p)
							operand_1 = 1;
					}

				if(operand_1 == 0)
					{
						p = strstr(tfield3, "!=");
						if(p)
							operand_1 = 2;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(tfield3, "<=");
						if(p)
							operand_1 = 3;
					}
				
				if(operand_1 == 0)
					{
						p = strstr(tfield3, ">=");
						if(p)
							operand_1 = 4;
					}

				if(operand_1 == 0)
					{
						p = strstr(tfield3, "=");
						if(p)
							operand_1 = 5;
					}

				if(operand_1 == 0)
					{
						p = strstr(tfield3, "<");
						if(p)
							operand_1 = 6;
					}

				if(operand_1 == 0)
					{
						p = strstr(tfield3, ">");
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

				if((fd1_type == 1) && (fd2_type == 1) && (fd4_type == 2) && (fd5_type == 1) && (fd7_type == 1))
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

						if(x3 == 0)
							{
								printf("c2z_if.c if_case_13 x81 E-418 tfield4 Not Found = %s\n",tfield4); 
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
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_if.c if_case_13 x81 E-419 tfield2 Not Found = %s\n",tfield2); 
								c2_error();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #31");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370ZERO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #32");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #33");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R6,");
						strcat(a_string, ar_field7);
						strcpy(wk_remark, " ");
						strcat(wk_remark, ar_field7);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #34");
								trace_rec_3();
							}

						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcat(a_string, "A");
						check_length();
						strcat(a_string, "DS    0H");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #35");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #36");
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
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #37");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #38");
								trace_rec_3();
							}

						strcpy(a_string, "         JLE   ");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, "L");
						strcat(a_string, wk_strg);
						strcat(a_string, "B");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #39");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #40");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #41");
								trace_rec_3();
							}

						strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #42");
								trace_rec_3();
							}

 						strcpy(a_string, "         LA    R6,");
						strcat(a_string, ar_field6);
						strcat(a_string, "(R0,R6)");
						src_line();
			   			if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #43");
								trace_rec_3();
							}

						strcpy(a_string, "         JLU   ");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, "L");
						strcat(a_string, wk_strg);
						strcat(a_string, "A");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #44");
								trace_rec_3();
							}

						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcpy(a_string, "L");
						strcat(a_string, wk_strg);
						strcat(a_string, "B");
						check_length();
						strcat(a_string, "DS    0H");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_13 x81 #45");
								trace_rec_3();
							}
					}

				convert = 1;
				return;
			}
	}


/* *************************************************** 
*  if_case_22                                        *
* ************************************************** */
void if_case_22()		 
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_22");
				trace_rec_1();
			}

		char ch;
		char *p, *p1;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field4[VAR_LGTH];

		int pi;
		int pi2;
		int fd1_type = 0;
		int fd2_type = 0;
		int fd3_type = 0;
		int I = 0;
		int x2 = 0;
		int x3 = 0;
		int if_complex = 0;
		int if_math = 0;
		int operand_1 = 0;
		int ret = 0;
		int ret1 = 0;

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

		p1 = strstr(p_string, "==");
		if(p1)
			{
				if_math = 1;
			}

		p1 = strstr(p_string, "!=");
		if(p1)
			{
				if_math = 1;
			}

		p1 = strstr(p_string, "<=");
		if(p1)
			{
				if_math = 1;
			}

		p1 = strstr(p_string, ">=");
		if(p1)
			{
				if_math = 1;
			}

		p1 = strstr(p_string, "<");
		if(p1)
			{
				if_math = 1;
			}

		p1 = strstr(p_string, ">");
		if(p1)
			{
				if_math = 1;
			}

		if((if_complex == 0) && (if_math == 0))	
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0");
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

				x2 = 0;
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ')')
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
								x3 = 1;
								strcpy(field1a, lw_variable[I].lv_cname);
								lw_variable[I].lv_use_ct++;
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
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_22 Complex = 0 Math = 0 E- 259 field1 Not Found = %s\n",field1);
						c2_error();
					}

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0 #1");
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
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0 #2");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0 #4");
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
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0 #5");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0 #6");
						trace_rec_3();
					}

				strcpy(a_string, "         BRASL C370LNK,ISUPPER");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0 #8");
						trace_rec_3();
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcpy(o_string, a_string);
				check_length();
				strcat(a_string, "DS     0H");

				strcpy(a_string,"         LARL  R9,C370ISAL");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0 #9");
						trace_rec_3();
					}

				strcpy(a_string,"         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0 #10");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string,"         CP    0(6,R9),0(6,R8)");
				strcpy(wk_remark, " IF !=    */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0 #11");
						trace_rec_3();
					}

				strcpy(a_string, "         JLE   ");
				strcat(a_string, o_string);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0 #12");
						trace_rec_3();
					}
				var_use[20]++;

				convert = 1;
			}

		if((if_complex == 0)	&& (if_math == 1) && (convert == 0))	
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 1");
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

				x2 = 0;
				pi2 = 0;
				pi++;
				ch = p_string[pi];
				while(ch != ')')
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
								x3 = 1;
								strcpy(field1a, lw_variable[I].lv_cname);
								lw_variable[I].lv_use_ct++;
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
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_22 E-360 field1 Not Found = %s\n",field1);
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
										fd3_type = 1;
										x2 = 1;
									} 

								if (isalpha(ch))	
									{
										fd3_type = 2;
										x2 = 1;
									}
							}
						field3[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field3[pi2] = '\0';

				if(fd3_type == 2)
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
											}
									}
							}		

						if(x3 == 0)
							{
								printf("c2z_if.c if_case_22 E-361 field3 Not Found = %s\n",field4);
								c2_error();
							}
					}

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 1 #1");
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
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 1 #2");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2s_if.c if_case_22 comp = 0 math = 1 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         BRASL C370LNK,ISUPPER");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 1 #4");
						trace_rec_3();
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
				strcpy(o_string, a_string);
				check_length();
				strcat(a_string, "DS     0H");

				strcpy(a_string,"         LARL  R9,C370ISAL");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 1 #5");
						trace_rec_3();
					}

				strcpy(a_string,"         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 1 #6");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string,"         CP    0(6,R9),0(6,R8)");
				strcpy(wk_remark, " IF !=    */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 1 #7");
						trace_rec_3();
					}

				if(operand_1 == 1)
					{
						printf("c2z_if.c if_case_22 E-362 Complex = 0 == NOT CODED\n");
						c2_error();
					}

				if(operand_1 == 2)
					{		
						strcpy(a_string, "         JLE   ");
						strcat(a_string, o_string);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 1 #8");
								trace_rec_3();
							}
					}

				if(operand_1 == 3)
					{
						printf("c2z_if.c if_case_22 E-363 Complex = 0 <= NOT CODED\n");
						c2_error();
					}

				if(operand_1 == 4)
					{
						printf("c2z_if.c if_case_22 E-364 Complex = 0 >= NOT CODED\n");
						c2_error();
					}

				if(operand_1 == 6)
					{
						printf("c2z_if.c if_case_22 E-365 Complex = 0 < NOT CODED\n");
						c2_error();
					}

				if(operand_1 == 7)
					{
						printf("c2z_if.c if_case_22 E-366 Complex = 0 > NOT CODED\n");
						c2_error();
					}
				var_use[20]++;
			}	

		if(if_complex == 1)
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
				while(ch != ' ')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

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

				printf("if_case_2 complex == 1 E-458 NEED TO FINISH Second Half\n");
				c2_error();
				
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcpy(o_string, a_string);
				check_length();
				strcat(a_string, "DS     0H");

				if(fd1_type == 2)
					{
						strcpy(a_string,"*         CP    ");
						strcat(a_string, field1a);
					}
				if(fd1_type == 1)
					{
						strcpy(a_string,"*         CLC   ");
						strcat(a_string, field1a);
					}

				strcat(a_string,",");
				if(fd2_type == 2)
					{
						strcat(a_string, field2a);
					}
				if(fd2_type == 1)
					{
						strcat(a_string, "=P'");
						strcat(a_string, field2);
						strcat(a_string, "'");
					}
				strcpy(wk_remark, " IF !=    */");
				write_remark();
				if(punch_code == 1)
					trace_rec_3();
			}

		if_convert = 1;
		convert = 1;
	}


/* *************************************************** 
*  if_case_23    isalnum                             *
* ************************************************** */
void if_case_23()		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_23");
				trace_rec_1();
			}

		char ch;
		char *p, *p1;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];

		int pi;
		int pi2;
		int if_complex = 0;
		int if_short = 0;
		int x3 = 0;
		int I = 0;
		int ret = 0;
		int ret1 = 0;

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

		p1 = strstr(p_string, "))");
		if(p1)
			{
				if_short = 1;
			}

		if((if_complex == 0) && (if_short == 1))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_23 0 / 0");
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
									}
							}
					}		

				if(x3 == 0)
					{
						printf("c2z_if.c if_case_23 E-376 field1 Not Found = %s\n",field1);
						c2_error();
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcpy(a_string, "L");
				strcat(a_string, wk_strg);
				strcpy(o_string, a_string);
				check_length();
				strcat(a_string, "DS     0H");

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #1");
						trace_rec_3();
					}
				work_use_ct[2]++;

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field1a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #2");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         BRASL C370LNK,ISALNUM");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #4");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370ISAL");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #5");
						trace_rec_3();
					}
				work_use_ct[1]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #6");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #7");
						trace_rec_3();
					}

				strcpy(a_string, "         JNE    ");
				strcat(a_string, o_string);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #8");
						trace_rec_3();
					}

				convert = 1;
				if_convert = 1;
			}


		if((if_complex == 0) && (if_short == 0))
			{
				printf("c2z_if.c if_case_23 E-377 complex == 0 short == 0 NOT CODED\n");
				c2_error();
			}

		if(if_complex == 1)
			{
				printf("c2z_if.c if_case_23 E-378 complex == 1 NOT CODED\n");
				c2_error();
			}

		convert = 1;
		if_convert = 1;
	}


/* *************************************************** 
*  if_case_24    logical if                          *
* ************************************************** */
void if_case_24()		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_24 logical");
				trace_rec_1();
			}

		char *p;
		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield3[VAR_LGTH];

		int pi;
		int pi2;
		int x3;
		int I;
		int si;
		int ret;
		int ret1;
		int x10 = 0;

		pi = 0;
		ch = p_string[pi];
		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		while(ch != ')')
			{
				if(ch != '(')
					{
						tfield1[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		tfield1[pi2] = '\0';

		p = strstr(tfield1, "!");
		if(p)
			{
				pi = 0;
				ch = tfield1[pi];
				while(ch != '!')
					{
						pi++;
						ch = tfield1[pi];	
					}
				si = 0;
				pi++;
				ch = tfield1[pi];
				while(ch != ' ')
					{
						tfield3[si] = ch;
						si++;
						pi++;
						ch = tfield1[pi];
					}
				tfield3[si] = '\0';

				strcpy(tfield1, tfield3);
				x10 = 1;
			}

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
						ret = strcmp(tfield1, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x3 = 1;		
								strcpy(tfield1a, gw_variable[I].gv_cname);
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_if.c c2_if_case_24 E-170 tfield1 Not Found = %s\n",tfield1);
				c2_error();
			}

		if(x10 == 0)
			{
				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_24 logical #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_24 logical #2");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_24 logical #3");
						trace_rec_3();
					}

				strcpy(a_string, "         JLNE  L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_24 logical #4");
						trace_rec_3();
					}

				convert = 1;
			}

		if(x10 == 1)
			{
				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_24 logical #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_24 logical #2");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_24 logical #3");
						trace_rec_3();
					}

				strcpy(a_string, "         JLNE  L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_24 logical #4");
						trace_rec_3();
					}

				convert = 1;
			}

	}


/* *************************************************** 
*  if_case_30    strchr                              *
* ************************************************** */
void if_case_30()		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_if.c if_case_30 strchr");
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];

		int pi;
		int pi2;
		int x3 = 0;
		int I = 0;
		int ret = 0;
		int ret1 = 0;
		int s = 0;
		int x10 = 0;

		use_strchr++;

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
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field1[pi2] = '\0';

		s = strlen(field1);
		s = s - 2;

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
						field2[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		field2[pi2] = '\0';

		I = 0;
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
						ret = strcmp(field2, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x3 = 1;		
								strcpy(field2a, gw_variable[I].gv_cname);
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_if.c c2_if_case_30 E-171 field2 Not Found = %s\n",field2);
				c2_error();
			}

		if(s == 1)
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
										strcpy(trace_1, "c2z_if.c if_case_30 strchr #1");
										trace_rec_3();
									}
								break;
							}
					}
				
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field2a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field2);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #2");
						trace_rec_3();
					}
	
				strcpy(a_string, "         CLC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #3");
						trace_rec_3();
					}

				strcpy(a_string, "         JLNE  L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #4");
						trace_rec_3();
					}
			}
	
		if(s == 2)
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
										strcpy(trace_1, "c2z_if.c if_case_30 strchr #5");
										trace_rec_3();
									}
								break;
							}
					}
				
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field2a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field2);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #6");
						trace_rec_3();
					}
	
				strcpy(a_string, "         CLC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #7");
						trace_rec_3();
					}

				strcpy(a_string, "         JLNE  L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "A");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #8");
						trace_rec_3();
					}

				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "B");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #9");
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
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #10");
						trace_rec_3();
					}

				x10 = 0;
				for(I=0; I < char_ct; I++)
					{
						if(rct == w_charlit[I].clit_rct)
							{
								x10++;
								if(x10 == 2)
									{
										strcpy(a_string, "         LARL  R9,");
										strcat(a_string, w_charlit[I].clit_cname);
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_if.c if_case_30 strchr #11");
												trace_rec_3();
											}
										break;
									}
							}
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field2a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field2);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #12");
						trace_rec_3();
					}
	
				strcpy(a_string, "         CLC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #13");
						trace_rec_3();
					}

				strcpy(a_string, "         JLNE  L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #14");
						trace_rec_3();
					}

				strcpy(a_string, "         JLE   L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "B");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #15");
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
						strcpy(trace_1, "c2z_if.c if_case_30 strchr #16");
						trace_rec_3();
					}
			}

		if(s > 2)
			{
				printf("c2z_if.c c2_if_case_30 s > 2 E-171 Not Coded\n");
				c2_error();
			}

		convert = 1;
	}

