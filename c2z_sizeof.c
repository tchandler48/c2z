/* ***************************************************
*  c2z : c2z_sizeof.c :                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */

/* ***************************************************
*  Punch out SIZEOF                                  *
* ************************************************** */
void c2_sizeof()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof");
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2a[VAR_LGTH];
	       /* char field3a[VAR_LGTH]; */

		int x = 0;
		int x3 = 0;
		int pi;
		int pi2;
		int I = 0;
		int ret = 0;
		int end_of_string = 0;

		check_semi(); 

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

		x3 = 0;
		if(lv_ct > 0)
			{
				for(I = 0; I < lv_ct; I++)
					{
						ret = strcmp(field1, lw_variable[I].lv_name);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(field1a, lw_variable[I].lv_cname);
								lw_variable[I].lv_use_ct++;
							}
					}
			}

		if(x == 0)		
			{
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(field1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(field1a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;									}
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_sizeof.c c2_sizeof field1 Not Found = %s\n",field1);
				printf("c2z_sizeof.c c2_sizeof rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		pi++;
		ch = p_string[pi];
		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			} 

		end_of_string = 0;
		pi++;
		pi2 = 0;
		ch = p_string[pi];
		while((ch != ')') && (end_of_string == 0))
			{
				if(ch == '[')
					{
						end_of_string = 1;
					}
				if(end_of_string == 0)
					{
						field2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
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
								gw_variable[I].gv_use_ct++;
							}
					}
			}

		I = 0;
		x3 = 0;
		for(I=0; I < gv_ct; I++)
			{
				ret = strcmp(field2,gw_variable[I].gv_name);
				if(ret == 0)
					{
						x3 = 1;		
						break;
					}
			}

		if(x3 == 0)
			{
				printf("c2z_sizeof.c c2_sizeof field2 Not Found = %s\n",field2);
				printf("c2z_sizeof.c c2_sizeof rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}
											
		ret = strcmp(gw_variable[I].gv_type, "C");
		if(ret != 0)
			{
				printf("c2z_sizeof.c c2_aizeof field2 Not Character = %s\n",field2);
				printf("c2z_sizeof.c c2_sizeof rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		x3 = 0;		
		if(gv_ct > 0)
			{
				for(I = 0; I < gv_ct; I++)
					{
						ret = strcmp(field2a, gw_variable[I].gv_cname);
						if(ret == 0)
							{
								x3 = 1;
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_sizeof.c c2_sizeof field2 Not Found = %s\n",field2);
				printf("c2z_sizeof.c c2_sizeof rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}
	
		strcpy(a_string, "SZ");
		snprintf(wk_strg, sizeof(wk_strg), "%d", tot_sizeof);
		strcat(a_string, wk_strg);
		strcat(a_string, "0");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #1");
				trace_rec_3();
			}

	       strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #2");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         LARL  R8,C370ZERO");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #3");
				trace_rec_3();
			}
		work_use_ct[32]++;
	
		strcpy(a_string, "         CP    ");
		strcat(a_string, "0(4,R9),0(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #4");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   SZ");
		snprintf(wk_strg, sizeof(wk_strg), "%d", tot_sizeof);
		strcat(a_string, wk_strg);
		strcat(a_string, "99");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #5");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L8");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #6");
				trace_rec_3();
			}
		
		strcpy(a_string, "         LARL  R8,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #7");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         UNPK  0(8,R9),0(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #8");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #9");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370L8");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #10");
				trace_rec_3();
			}

		strcpy(a_string, "         PACK  0(8,r9),0(8,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #11");
				trace_rec_3();
			}
		
		strcpy(a_string, "         LARL  R9,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #12");
				trace_rec_3();
			}

		strcpy(a_string, "         CVB   R5,0(7,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #13");
				trace_rec_3();
			}
		work_use_ct[48]++;

		strcpy(a_string, "         AHI   R5,-1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #14");
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
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #15");
				trace_rec_3();
			}

		strcpy(a_string, "         IC    R0,");
		strcat(a_string, "0(R9,(R5))");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #16");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #17");
				trace_rec_3();
			}
	
		strcpy(a_string, "         STC   R0,0(0,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #18");
				trace_rec_3();
			}
		work_use_ct[2]++;

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #19");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #20");
				trace_rec_3();
			}

		strcpy(a_string, "         CLC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #21");
				trace_rec_3();
			}
		work_use_ct[2]++;
		work_use_ct[59]++;

		strcpy(a_string, "         JNE   ");
		strcat(a_string, "SZ");
		snprintf(wk_strg, sizeof(wk_strg), "%d", tot_sizeof);
		strcat(a_string, wk_strg);
		strcat(a_string, "99");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #22");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #23");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         LARL  R8,C370ONE");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #24");
				trace_rec_3();
			}
		work_use_ct[33]++;

		strcpy(a_string, "         SP    0(4,R9),0(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #25");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   SZ");
		snprintf(wk_strg, sizeof(wk_strg), "%d", tot_sizeof);
		strcat(a_string, wk_strg);
		strcat(a_string, "0");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #26");
				trace_rec_3();
			}

		strcpy(a_string, "SZ");
		snprintf(wk_strg, sizeof(wk_strg), "%d", tot_sizeof);
		strcat(a_string, wk_strg);
		strcat(a_string, "99");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #27");
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
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #28");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         LARL  R8,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #29");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         ZAP   ");
		strcat(a_string, "0(4,R9),0(4,R8)");
		strcpy(wk_remark, " end size */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_sizeof.c c2_sizeof #30");
				trace_rec_3();
			}
		work_use_ct[49]++;

		if(gv_ct > 0)
			{
				for(I = 0; I < gv_ct; I++)
					{
						ret = strcmp(field1a,gw_variable[I].gv_cname);
						if(ret == 0)
							{
								gw_variable[I].gv_use_ct++;
							}
					}
			}

		if(gv_ct > 0)
			{
				for(I = 0; I < gv_ct; I++)
					{
						ret = strcmp(field2a,gw_variable[I].gv_cname);
						if(ret == 0)
							{
								gw_variable[I].gv_use_ct++;
							}
					}
			}
		
		convert = 1;
	}

/* ***************************************************
*  Pass2 SIZEOF                                      *
* ************************************************** */
void c2_pass2_sizeof()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_szieof.c c2_pass2_sizeof");
				trace_rec_1();
			}

		char ch;
		
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3a[VAR_LGTH];
		char tfield21[VAR_LGTH];

		int pi;
		int pi2;
		int x = 0;
		int x2 = 0;
		int x3 = 0;
		int s = 0;
		int size = 0;
		int rct1 = 0;
		int I = 0;
		int ret = 0;
		int end_of_string = 0;

		check_semi(); 

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

		x2 = 0;
		x3 = 0;
		if(lv_ct > 0)
			{
				for(I = 0; I < lv_ct; I++)
					{
						ret = strcmp(field1, lw_variable[I].lv_name);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(field1a, lw_variable[I].lv_cname);
								lw_variable[I].lv_use_ct++;
							}
					}
			}

		if(x == 0)		/* check the global gw_variable table */
			{
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(field1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(field1a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;									}
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_sizeof.c c2_pass2_sizeof field1 Not Found = %s\n",field1);
				printf("c2z_sizeof.c c2_pass2_sizeof rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		pi++;
		ch = p_string[pi];
		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			} 

		end_of_string = 0;
		pi++;
		pi2 = 0;
		ch = p_string[pi];
		while((ch != ')') && (end_of_string == 0))
			{
				if(ch == '[')
					{
						end_of_string = 1;
					}
				if(end_of_string == 0)
					{
						field2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
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
								gw_variable[I].gv_use_ct++;
							}
					}
			}

		I = 0;
		x3 = 0;
		for(I=0; I < gv_ct; I++)
			{
				ret = strcmp(field2, gw_variable[I].gv_name);
				if(ret == 0)
					{
						x3 = 1;		
						break;
					}
			}

		if(x3 == 0)
			{
				printf("c2z_sizeof.c c2_pass2_sizeof field2 Not Found = %s\n",field2);
				printf("c2z_sizeof.c c2_pass2_sizeof rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}
											
		ret = strcmp(gw_variable[I].gv_type, "C");
		if(ret != 0)
			{
				printf("c2z_sizeof.c c2_pass2_sizeof field2 Not Character = %s\n",field2);
				printf("c2z_sizeof.c c2_pass2_sizeof rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}
		
		x3 = 0;		
		if(gv_ct > 0)
			{
				for(I = 0; I < gv_ct; I++)
					{
						ret = strcmp(field2a, gw_variable[I].gv_cname);
						if(ret == 0)
							{
								x3 = 1;
								x2 = gw_variable[I].gv_lgth;
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_sizeof.c c2_pass2_sizeof field2 Not Found = %s\n",field2);
				printf("c2z_sizeof.c c2_pass2_sizeof rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		c_name++;
		snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
		strcpy(c_wkname, "C37F");
		strcat(c_wkname, wk_strg);
		s = strlen(c_wkname);
		c_wkname[s] = '\0';
		strcpy(field3a, c_wkname);
		strcpy(tfield21, field3a);

		snprintf(field2, sizeof(wk_strg), "%d", x2);
		s = strlen(field2);

		if(s == 1)
			{
				strcpy(field2a,"000000");
				strcat(field2a, field2);
			}

		if(s == 2)
			{	
				strcpy(field2a,"00000");
				strcat(field2a, field2);
			}

		if(s == 3)
			{
				strcpy(field2a,"0000");
				strcat(field2a, field2);
			}

		if(s == 4)
			{
				strcpy(field2a,"000");
				strcat(field2a, field2);
			}

		if(s == 5)
			{
				strcpy(field2a,"00");
				strcat(field2a, field2);
			}

		if(s == 6)
			{
				strcpy(field2a,"0");
				strcat(field2, field2);
			}

		if(s == 7)
			{
				strcpy(field2a,field2);
			}

		if(s > 7)
			{
				printf("c2z_sizeof.c c2_pass2_sizeof Length ERROR\n");
				printf("c2z_sizeof.c c2_pass2_sizeof rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		rct1 = rct;
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
		strcpy(w_literal[lit_ct].lit_cname, field3a);	
      		strcpy(w_literal[lit_ct].lit_value, field2a); 
		strcpy(w_literal[lit_ct].lit_use_cname, tfield21); 
		w_literal[lit_ct].lit_uct = 1;
		w_literal[lit_ct].lit_dec = 0;	             
		lit_ct++;
							
		convert = 1;

		return;
	}


