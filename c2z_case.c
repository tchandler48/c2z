/* ***************************************************
*  c2z : c2z_case.c :                                *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */

/* *************************************************** 
*  Punch out CASE statement                          *
* ************************************************** */
void c2_case(void)
	{	
		if_case = 0;
			
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_case.c c2_case");
				trace_rec_1();
			}

		char ch;
		char *p1;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];

		int fd1_type = 0;
		int pi;
		int pi2;
		int x = 0;
		int I = 0;
						
		if_case = 1;
		pi = 0;
		ch = p_string[pi];	
		p1 = strstr(p_string, "{");
		if(p1)
			{
				while(ch != '{')
					{
						pi++;
						ch = p_string[pi];
					}
				pi++;
				ch = p_string[pi];
			}
				
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
		fd1_type = 0;
		x = 0;
		while(ch != ':')
			{
				if(ch == '\'')
					{
						x = 2;
						fd1_type = 0;
					}

				if((isdigit(ch)) && (x == 0))
					{
						fd1_type = 1;
						x = 1;
					}

				if((isalpha(ch)) && (x == 0))
					{
						fd1_type = 2;
						x = 1;
					}
						
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field1[pi2] = '\0';

		if(fd1_type == 1)		
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_case fd1_type == 1");
						trace_rec_1();
					}

				strcpy(save_case_break, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(save_case_break, wk_strg);
				strcat(save_case_break, "E");

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, sw_field);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_case fd1_type == 1 #1");
						trace_rec_3();
					}

				for(I=0; I < lit_ct; I++)
					{
						if(rct == w_literal[I].lit_rct)
							{
								strcpy(field1a, w_literal[I].lit_use_cname);
							} 
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field1a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_case fd1_type == 1 #2");
						trace_rec_3();
					}

				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_case fd1_type == 1 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         JNE   ");
				strcat(a_string, save_case_break);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_case fd1_type == 1 #4");
						trace_rec_3();
					}
 			}

		if(fd1_type == 2)		
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_case fd1_type == 2");
						trace_rec_1();
					}

				/* generate sv_case_break */
				strcpy(save_case_break, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(save_case_break, wk_strg);
				strcat(save_case_break, "E"); 

				
				strcpy(a_string, "*         CLC    ");

				strcpy(wk_remark, " case     */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_case fd1_type == 2 #1");
						trace_rec_3();
					}

				printf("c2z_case.c c2_case E-3 fd1_type == 2 NOT FINISHED\n");
				c2_error();
			}

		if(fd1_type == 0)		/* special character  */
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_case fd1_type == 0");
						trace_rec_1();
					}

				strcpy(save_case_break, "L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(save_case_break, wk_strg);
				strcat(save_case_break, "E");

				for(I=0; I < char_ct; I++)
					{
						if(w_charlit[I].clit_rct == rct)
							{
								strcpy(field1, w_charlit[I].clit_cname);
                                         		}
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, sw_field);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_case fd1_type == 0 #1");
						trace_rec_3();
					}
						
				for(I=0; I < char_ct; I++)
					{
						if(w_charlit[I].clit_rct == rct)
							{
								strcpy(field1, w_charlit[I].clit_cname);
                                         		}
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field1);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_case fd1_type == 0 #2");
						trace_rec_3();
					}
							
				strcpy(a_string, "         CLC   0(1,R8),0(R9)");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_case fd1_type == 0 #3");
						trace_rec_3();
					}

				strcpy(a_string, "         JLNE  ");
				strcat(a_string, save_case_break);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_case fd1_type == 0 #4");
						trace_rec_3();
					}
			}
	}
	

void c2_pass2_case()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_case.c c2_pass2_case");
				trace_rec_1();
			}

		int pi;
		int pi2;
		int x = 0;
		int x99 = 0;
		int s = 0;
		int s1 = 0;
		int size = 0;
		int rct1 = 0;
		int I = 0;
		int fd1_type = 0;

		char *p, *p1;
		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield3b[VAR_LGTH];
		char tfield21[VAR_LGTH];

		tfield1a[0] = '\0';

		pi = 0;
		ch = p_string[pi];
		p = strstr(p_string, "{");
		if(p)
			{
				while(ch != '{')
					{
						pi++;
						ch = p_string[pi];
					}
				pi++;
				ch = p_string[pi];
			}
			
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
		fd1_type = 0;
		x = 0;
		while(ch != ':')
			{
				if((isdigit(ch)) && (x == 0))
					{
						fd1_type = 1;
						x = 1;
					}

				if((isalpha(ch)) && (x == 0))
					{
						fd1_type = 2;
						x = 1;
					}
	
				tfield1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield1[pi2] = '\0';

		if(fd1_type == 1)		
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_pass2_case fd1_type == 1");
						trace_rec_1();
					}

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield3a, c_wkname);
				strcpy(tfield21, tfield3a);

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
						strcpy(tfield1a, tfield1);
					}
				else
					{
						strcpy(tfield1a,"-");
						strcat(tfield1a, tfield1);
					}

				rct1 = rct;
				
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
      				strcpy(w_literal[lit_ct].lit_value, tfield1a);  
				strcpy(w_literal[lit_ct].lit_use_cname, tfield3a);
				w_literal[lit_ct].lit_uct = 1;
				w_literal[lit_ct].lit_dec = 0;
				w_literal[lit_ct].lit_type = 1;
				lit_ct++;
							
				convert = 1;

			}

		if(fd1_type == 2)		
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_pass2_case fd1_type == 2");
						trace_rec_1();
					}
				return;
			}

		if(fd1_type == 0)		
			{

				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_case.c c2_pass2_case fd1_type == 0");
						trace_rec_1();
					}

				pi2 = 0;
				ch = tfield1[1];
				tfield3[0] = ch;
				tfield3[1] = '\0';

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
      				strcpy(w_charlit[char_ct].clit_value, tfield3); 
				w_charlit[char_ct].clit_lgth = 1; 	 
				w_charlit[char_ct].clit_uct = 1; 
				char_ct++;
			}
			
		convert = 1;
	}


