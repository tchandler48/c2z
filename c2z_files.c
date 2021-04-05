/* ***************************************************
*  c2z : c2z_files.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* *************************************************** 
*  Punch out OPEN based on FOPEN                     *
* ************************************************** */
void c2_open()
	{		
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_open");
				trace_rec_1();
			}

		char ch;
		char tfield1[VAR_LGTH];
		
		int pi;
		int pi2;
		int I = 0;
		int ret = 0;
		
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
				tfield1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			} 
		tfield1[pi2] = '\0';

		for(I=0; I < f_ct; I++)
			{
				ret = strcmp(tfield1, w_file[I].f_name);
				if(ret == 0)
					{

						strcpy(a_string, "         BRASL C370LNK,C370OPN");
						snprintf(wk_strg, sizeof(wk_strg), "%d",w_file[I].f_buf_ct);
						strcat(a_string,wk_strg);
						src_line();
						if(punch_code == 1)
							trace_rec_3();
					}
			}
	}


/* *************************************************** 
*  Punch out FCLOSE                                  *
* ************************************************** */
void c2_close()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_close");
				trace_rec_1();
			}

		int pi;
		int pi2;	
		int y0 = 0;
		int y1 = 0;
		
		char ch;
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];

		field1a[0] = '\0';

		check_semi(); 

		pi = 0;
		pi2 = 0;
		ch = p_string[pi];
		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			} 
 
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
				
		if(fclose_ct > 0)
			{
				for(y0=0; y0 < fclose_ct; y0++)
					{
						if(rct ==  w_fclose_table[y0].cl_rct)
							{
								strcpy(a_string, "L");
								snprintf(wk_strg, sizeof(wk_strg), "%d",rct);
								strcat(a_string, wk_strg);
								check_length();
								strcat(a_string, "DS    0H");
								strcpy(wk_remark, " fclose   */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_files.c c2_close #1");
										trace_rec_3();
									}
							}
					}
			}
		
		convert = 1;
	}
	

/* **************************************************************************** 
*  Scan test for FOPEN                                                        *
* *************************************************************************** */
void c2_scan_sc3(void)
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_scan_sc3");
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];

		int pi;
		int pi2;
		int x2 = 0;
		int x3 = 0;
		int I = 0;
		int s = 0;
		int v = 0;
		int ret = 0;
		int size = 0;
		
		check_semi();

		s = strlen(p_string);
		pi = 0;
		ch = p_string[pi];
		pi++;
		while((ch == ' ') || (ch == '\t')) 
			{
				ch = p_string[pi];
				pi++;	
			}

		pi2 = 0;
		pi--;
		while(ch != ' ')
			{
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			} 
		field1[pi2] = '\0';

		strcpy(c_output_file, field1);

		while(ch != '"')
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != '"')
			{
				field2[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field2[pi2] = '\0';

		x2 = 0;
		for(I = 0; I < f_ct; I++)
			{
				ret = strcmp(field1, w_file[I].f_name);
				if(ret == 0)
					{
						x2 = 1;	
					}
			}

		if(x2 == 0)		
			{		
				if(f_ct == 0)
					{
						size = 1;
						w_file = malloc(size * sizeof(struct files));
					}
				else
					{
						size = f_ct + 1;
						w_file = realloc(w_file, size * sizeof(struct files));
					}
				w_file[f_ct].f_rct = rct;	
				strcpy(w_file[f_ct].f_cname, field1);
		  		strcpy(w_file[f_ct].f_name, field1); 
				strcpy(w_file[f_ct].f_type, "P");
				w_file[f_ct].f_buf_ct = size; 
				strcpy(w_file[f_ct].f_perm, "  ");
				ret = strcmp("r",field2);
				if(ret == 0)
					{
						strcpy(w_file[f_ct].f_perm, "I");
					}
				ret = strcmp("w",field2);
				if(ret == 0)
					{
						strcpy(w_file[f_ct].f_perm, "O");	 
					}           
				f_ct++;

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field1a, "C37F");
				strcat(field1a, wk_strg);
				s = strlen(field1a);
				field1a[s] = '\0';

				x3 = 0;
				for(v = 0; v < gv_ct; v++)
					{            
						ret = strcmp(field1, gw_variable[v].gv_name);
						if(ret == 0)
							{
								x3 = 1;
							}
					}
								
				if(x3 == 0)
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
						strcpy(gw_variable[gv_ct].gv_value, null_field);
						gw_variable[gv_ct].gv_dec = 0;
						gv_ct++;
					}
			}
				
	}


/* *************************************************** 
*  Punch out FGETS                                   *
* ************************************************** */
void c2_fgets()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets");
				trace_rec_1();
			}
		
		char ch;

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
				printf("c2z_files.c c2_files E-44 field1 Not Found = %s\n",field1);
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
						printf("c2z_files.c c2_files E-45 field2 Not Found = %s\n",field2);
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
				strcpy(trace_1, "c2z_files.c c2_fgets #1");
				trace_rec_3();
			}

		strcpy(a_string, "         GET   (R9)");
		strcpy(wk_remark, " fgets    */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #2");
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
								strcpy(trace_1, "c2z_files.c c2_fgets #3");
								trace_rec_3();
							}
	
						strcpy(a_string, "         LARL  R8,C370PB");
						snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
						strcat(a_string, wk_strg);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_files.c c2_fgets #4");
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
								strcpy(trace_1, "c2z_files.c c2_fgets #5");
								trace_rec_3();
							}

					}
			}

		strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #6");
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
				strcpy(trace_1, "c2z_files.c c2_fgets #7");
				trace_rec_3();
			}

		strcpy(a_string, "         ZAP   0(4,R9),0(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #8");
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
				strcpy(trace_1, "c2z_files.c c2_fgets #9");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #10");
				trace_rec_3();
			}
		work_use_ct[48]++;

		strcpy(a_string, "         LARL  R8,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #11");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #12");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #13");
 				trace_rec_3();
			}
		work_use_ct[48]++;

		strcpy(a_string, "         CVB   R5,0(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #14");
 				trace_rec_3();
			}

		strcpy(a_string, "         AHI   ");
		strcat(a_string, "R5,-1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #15");
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
				strcpy(trace_1, "c2z_files.c c2_fgets #16");
 				trace_rec_3();
			}

		strcpy(a_string, "         IC    R0,");
		strcat(a_string, "0(R8,");
		strcat(a_string, "(R5))");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #17");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #18");
				trace_rec_3();
			}
		work_use_ct[2]++;

		strcpy(a_string, "         STC   R0,");
		strcat(a_string, "0(0,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #19");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #20");
				trace_rec_3();
			}
		work_use_ct[2]++;

		strcpy(a_string, "         LARL  R8,C370B1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #21");
				trace_rec_3();
			}
		work_use_ct[52]++;

		strcpy(a_string, "         CLC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #22");
				trace_rec_3();
			}

		strcpy(a_string, "         JLNE  L");
		strcat(a_string, wk_strg);
		strcat(a_string, "B");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #23");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #24");
				trace_rec_3();
			}
	
		strcpy(a_string, "         LARL  R8,C370ONE");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #25");
				trace_rec_3();
			}
		work_use_ct[33]++;

		strcpy(a_string, "         SP    0(4,R9),0(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #26");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   L");
		strcat(a_string, wk_strg);
		strcat(a_string, "A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #27");
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
				strcpy(trace_1, "c2z_files.c c2_fgets #28");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #29 ");
 				trace_rec_3();
			}
		work_use_ct[48]++;

		strcpy(a_string, "         LARL  R8,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #30");
				trace_rec_3();
			}
	
		strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #31");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #32");
 				trace_rec_3();
			}
		work_use_ct[48]++;

		strcpy(a_string, "         CVB   R2,0(4,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #33");
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
				strcpy(trace_1, "c2z_files.c c2_fgets #34");
 				trace_rec_3();
			}
	
		strcpy(a_string, "         LR    R1,R9");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #35");
 				trace_rec_3();
			}

		strcpy(a_string, "         AR    R1,R2");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #36");
 				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370EOF");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #37");
				trace_rec_3();
			}

		strcpy(a_string,"         MVC   0(R9,R1),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fgets #38");
				trace_rec_3();
			}

		convert = 1;
	}


/* *************************************************** 
*  Scan for FPUTS                                    *
* ************************************************** */
void c2_scan_fputs()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_scan_fputs");
				trace_rec_1();
			}

		char ch;

		int pi;
		int pi2;
		int x = 0;
		int x2 = 0;
		int I = 0;
		int rec_lgth = 0;
		int ret = 0;
		int ret1 = 0;
		
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

		x = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(field1, lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						x = 1;
						strcpy(field1a, lw_variable[I].lv_cname);	
						rec_lgth = lw_variable[I].lv_lgth;									
					}
			}

		if(x == 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(field1, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x = 1;
								strcpy(field1a, gw_variable[I].gv_cname);	
								rec_lgth = gw_variable[I].gv_lgth;									
							}
					}
			}

		if(x == 0)
			{
				printf("c2z_files.c c2_scan_fputs E-48 field1 Not Found = %s\n",field1);
				c2_error();
			}

		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch == ' ')
			{
				pi++;
				ch = p_string[pi];
			}
	
		while(ch != ')')
			{
				field2[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field2[pi2] = '\0';

		x2 = 0;
		if(f_ct > 0)
			{
				for(I=0; I < f_ct; I++)
					{
						ret = strcmp(field2, w_file[I].f_name);
						if(ret == 0)
							{
								strcpy(w_file[I].f_type, "D");
								strcpy(w_file[I].f_perm, "O");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rec_lgth);
								strcpy(w_file[I].f_rec_lgth, wk_strg);
								x2 = 1;
							}
					}
			}

		if(x2 == 0)
			{
				printf("c2z_files.c c2_scan_fputs E-49 field2 Not Found in File Table = %s\n",field2);
				c2_error();
			}
	}


/* *************************************************** 
*  Punch for FPUTS                                   *
* ************************************************** */
void c2_fputs()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_fputs");
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		
		int pi;
		int pi2;
		int I = 0;
		int x = 0;
		int x9 = 0;
		int ret = 0;
		int ret1 = 0;
				
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

		x = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(field1,lw_variable[I].lv_name);
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						x = 1;
						strcpy(field1a, lw_variable[I].lv_cname);
						x9 = lw_variable[I].lv_lgth;										
					}
			}

		if(x == 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(field1,gw_variable[I].gv_name);
						if(ret == 0)
							{
								x = 1;
								strcpy(field1a, gw_variable[I].gv_cname);	
								x9 = gw_variable[I].gv_lgth;									
							}
					}
			}

		if(x == 0)
			{
				printf("c2z_files.c c2_fputs E-50 field1 Not Found = %s\n",field1);
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
		while(ch != ')')
			{
				field2[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field2[pi2] = '\0';

		if(f_ct > 0)
			{
				for(I=0; I < f_ct; I++)
					{
						ret = strcmp(field2,w_file[I].f_name);
						if(ret == 0)
							{
								strcpy(a_string, "         LARL  R9,C370PB");
								snprintf(wk_strg, sizeof(wk_strg), "%d",w_file[I].f_buf_ct);
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									trace_rec_3();

								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field1a);
								src_line();
								if(punch_code == 1)
									trace_rec_3();

								strcpy(a_string, "         MVC   ");
								strcat(a_string, "0(");
								snprintf(wk_strg, sizeof(wk_strg), "%d",x9);
								strcat(a_string, wk_strg);
								strcat(a_string, ",R9),0(R8)");
								src_line();
								if(punch_code == 1)
									trace_rec_3();
							}
					}
			}

		strcpy(a_string, "         PUT   ");
		strcat(a_string, field2);
		strcpy(wk_remark, " fputs    */");
		write_remark();
		if(punch_code == 1)
			trace_rec_3();

	}


/* *************************************************** 
*  Scan for FEOF                                     *
* ************************************************** */
void c2_scan_feof()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2_scan_feof ");
				trace_rec_1();
			}

	}


/* *************************************************** 
*  Punch out SCANF                                   *
* ************************************************** */
void c2_scanf()
	{	
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_scanf");
				trace_rec_1();
			}
		
		check_semi(); 

		char *p;
		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];

		int pi;
		int pi2;
		int I = 0;
		int x = 0;
		int x1 = 0;
		int x5 = 0;
		int x6 = 0;
		int ret = 0;
		int ret1 = 0;

		p = strstr(p_string, "%c");
		if(p)
			{
				x = 1;
				x1 = 1;
			}

		p = strstr(p_string, "%s");
		if(p)
			{
				x = 1;
				x1 = 2;
			}

		p = strstr(p_string, "%d");
		if(p)
			{
				x = 1;
				x1 = 3;
			}

		if(x == 0)
			{
				printf("c2z_files.c c2_scanf E-51 Invalid edit code\n");
				c2_error();
			}

		if(x1 == 1)			
			{
				pi = 0;
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
								tfield1[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				x5 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1,lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x5 = 1;
								strcpy(tfield1a, lw_variable[I].lv_cname);
								
							}
					}

				if(x5 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1,gw_variable[I].gv_name);
								if(ret == 0)
									{
										x5 = 1;
										strcpy(tfield1a, gw_variable[I].gv_cname);
										
									}
							}
					}			

				if(x5 == 0)
					{
						printf("c2z_files.c c2_scanf E-52 tfield1 Not Found = %s\n",tfield1);
						c2_error();
					}

				x6 = 1;

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_files.c c2_scanf #1");
						trace_rec_3();
					}
												
				strcpy(a_string, "         LARL  R8,C370ECB");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_files.c c2_scanf #2");
						trace_rec_3();
					}
				work_use_ct[77]++;

				strcpy(a_string, "         WTOR  '?',(R9),");
				snprintf(wk_strg, sizeof(wk_strg), "%d",x6);
				strcat(a_string, wk_strg);
				strcat(a_string, ",(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_files.c c2_scanf #3");
						trace_rec_3();
					}

				strcpy(a_string, "         WAIT   ECB=(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_files.c c2_scanf #4");
						trace_rec_3();
					}

				x5 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1,lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x5 = 1;
								lw_variable[I].lv_current_lgth = x6;
							}
					}

				if(x5 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1,gw_variable[I].gv_name);
								if(ret == 0)
									{
										x5 = 1;
										gw_variable[I].gv_current_lgth = x6;
									}
							}
					}			


				convert = 1;
				return;
			}

		if(x1 == 2)			
			{

				pi = 0;
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
								tfield1[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				x5 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1,lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x5 = 1;
								strcpy(tfield1a, lw_variable[I].lv_cname);
								x6 = lw_variable[I].lv_lgth;
							}
					}

				if(x5 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1,gw_variable[I].gv_name);
								if(ret == 0)
									{
										x5 = 1;
										strcpy(tfield1a, gw_variable[I].gv_cname);
										x6 = gw_variable[I].gv_lgth;	
									}
							}
					}			

				if(x5 == 0)
					{
						printf("c2z_files.c c2_scanf E-53 tfield1 Not Found = %s\n",tfield1);
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
						strcpy(trace_1, "c2z_files.c c2_scanf #5");
						trace_rec_3();
					}
												
				strcpy(a_string, "         LARL  R8,C370ECB");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_files.c c2_scanf #6");
						trace_rec_3();
					}
				work_use_ct[77]++;

				strcpy(a_string, "         WTOR  '?',(R9),");
				snprintf(wk_strg, sizeof(wk_strg), "%d",x6);
				strcat(a_string, wk_strg);
				strcat(a_string, ",(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_files.c c2_scanf #7");
						trace_rec_3();
					}

				strcpy(a_string, "         WAIT   ECB=(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_files.c c2_scanf #8");
						trace_rec_3();
					}

				x5 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1,lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x5 = 1;
								lw_variable[I].lv_current_lgth = x6;
							}
					}

				if(x5 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1,gw_variable[I].gv_name);
								if(ret == 0)
									{
										x5 = 1;
										gw_variable[I].gv_current_lgth = x6;
									}
							}
					}			


				convert = 1;
				return;
			}

		if(x1 == 3)			
			{

				convert = 1;
				return;
			}
	}


/* *************************************************** 
*  Scan for FILE                                     *
* ************************************************** */
void c2_file()
	{	
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_files.c c2_file");
				trace_rec_1();
			}
		
		check_semi(); 

		int x;
		int pi;
		int pi2;
		int u1;
		int II;
		int x10 = 0;
		int s;
		int x3;
		int v;
		int ret;
		int ret1;
		int size;

		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];

		char wk_fd1[VAR_LGTH];
		char wk_fd2[VAR_LGTH];
		char wk_fd3[VAR_LGTH];
		char wk_fd4[VAR_LGTH];
		char wk_fd5[VAR_LGTH];
		char wk_fd6[VAR_LGTH];
		char wk_fd7[VAR_LGTH];
		char wk_fd8[VAR_LGTH];
		char wk_fd9[VAR_LGTH];
		char wk_fd10[VAR_LGTH];
		char wk_work[VAR_LGTH];
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];

		wk_fd1[0] = '\0';
		wk_fd2[0] = '\0';
		wk_fd3[0] = '\0';
		wk_fd4[0] = '\0';
		wk_fd5[0] = '\0';
		wk_fd6[0] = '\0';
		wk_fd7[0] = '\0';
		wk_fd8[0] = '\0';
		wk_fd9[0] = '\0';
		wk_fd10[0] = '\0';
		wk_fdwk[0] = '\0';

		pi = 0;
		ch = p_string[pi];
		while(ch != 'E')
			{
				pi++;
				ch = p_string[pi];
			}

		u1 = 0;
		x = 0;
		pi++;
		pi2 = 0;
		ch = p_string[pi];
		while((ch != ';') && (x == 0))
			{
				while((ch != ',')  && (x == 0))
					{
						if(ch == ';')
							{
								x = 1;
							}
						else
							{
								if(ch != ' ')
									{
										if(ch != '*')
											{
												wk_fdwk[pi2] = ch;
												pi2++;
											}
									}
								pi++;
								ch = p_string[pi];
							}
					}
				wk_fdwk[pi2] = '\0';

				if(u1 == 0)
					{
						strcpy(wk_fd1, wk_fdwk);
					}
				if(u1 == 1)
					{
						strcpy(wk_fd2, wk_fdwk);
					}
				if(u1 == 2)
					{
						strcpy(wk_fd3, wk_fdwk);
					}	
				if(u1 == 3)
					{
						strcpy(wk_fd4, wk_fdwk);
					}
				if(u1 == 4)
					{
						strcpy(wk_fd5, wk_fdwk);
					}
				if(u1 == 5)
					{
						strcpy(wk_fd6, wk_fdwk);
					}
				if(u1 == 6)
					{
						strcpy(wk_fd7, wk_fdwk);
					}
				if(u1 == 7)
					{
						strcpy(wk_fd8, wk_fdwk);
					}
				if(u1 == 8)
					{
						strcpy(wk_fd9, wk_fdwk);
					}
				if(u1 == 9)
					{
						strcpy(wk_fd10, wk_fdwk);
					}

				u1++;
				if(x == 0)
					{
						pi++;
						ch = p_string[pi];
					}
				
				pi2 = 0;
			}	

		for(II = 0; II < u1; II++)
			{
				if(II == 0)
					{
						strcpy(wk_fdwk, wk_fd1);
					}
				if(II == 1)
					{
						strcpy(wk_fdwk, wk_fd2);
					}
				if(II == 2)
					{
						strcpy(wk_fdwk, wk_fd3);
					}
				if(II == 3)
					{
						strcpy(wk_fdwk, wk_fd4);
					}
				if(II == 4)
					{
						strcpy(wk_fdwk, wk_fd5);
					}
				if(II == 5)
					{
						strcpy(wk_fdwk, wk_fd6);
					}
				if(II == 6)
					{
						strcpy(wk_fdwk, wk_fd7);
					}
				if(II == 7)
					{
						strcpy(wk_fdwk, wk_fd8);
					}
				if(II == 8)
					{
						strcpy(wk_fdwk, wk_fd9);
					}
				if(II == 9)
					{
						strcpy(wk_fdwk, wk_fd10);
					}
			}

		for(x10=0; x10 < II; x10++)
			{
				if(x10 == 0)
					{
						strcpy(wk_work, wk_fd1);
						strcpy(tfield1, wk_fd1);
					}
				if(x10 == 1)
					{
						strcpy(wk_work, wk_fd2);
						strcpy(tfield1, wk_fd2);
					}

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield1a, c_wkname);

				x3 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field1, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(field1a, lw_variable[v].lv_cname);
							}
					}

				if(x3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field1, gw_variable[v].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(field1a, gw_variable[v].gv_cname);
									}
							}
					}

				if(x3 == 0)
					{
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
								strcpy(gw_variable[gv_ct].gv_cname, tfield1a);	
      								strcpy(gw_variable[gv_ct].gv_name, tfield1);  	             
								strcpy(gw_variable[gv_ct].gv_type, "C");
								gw_variable[gv_ct].gv_lgth = 32;
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
								strcpy(lw_variable[lv_ct].lv_type, "CV");
								lw_variable[lv_ct].lv_lgth = 32;	
								strcpy(lw_variable[lv_ct].lv_value, null_field);
								lw_variable[lv_ct].lv_use_ct = 0;
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}
			}
	}


