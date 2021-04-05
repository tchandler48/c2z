/* ***************************************************
*  c2z : c2z_strlen.c :                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out STRLEN                                  *
* ************************************************** */
void c2_strlen()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen");
				trace_rec_1();
			}

		check_semi(); 

		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];

		int pi;
		int pi2;
		int strl_1 = 0;
		int strl_3 = 0;
		int x2 = 0;
		int x3 = 0;
		int I = 0;
		int ret = 0;
		int ret1 = 0;	
		int ret2 = 0;
		int end_of_string = 0;
		int array_found = 0;

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

		strl_3 = 0;
 		if(lv_ct > 0)
			{
				for(I = 0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								strl_3 = 1;
								strcpy(tfield1a, lw_variable[I].lv_cname);
							}
					}
			}

		if(strl_3 == 0)
			{
 				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								strl_1 = strcmp(tfield1, gw_variable[I].gv_name);
								if(strl_1 == 0)
									{
										strl_3 = 1;
										strcpy(tfield1a, gw_variable[I].gv_cname);
									}
							}
					}
			}

		if(strl_3 == 0)
			{
				printf("c2z_strlen.c c2_strlen E-245 tfield1 Not Found = %s\n",tfield1);
				c2_error();
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
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
			} 
		tfield2[pi2] = '\0';

		x3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(tfield2, lw_variable[I].lv_name);
				ret2 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret2 == 0))
					{
						x3 = 1;		/* found variable */
						strcpy(tfield2a, lw_variable[I].lv_cname);
						ret2 = strcmp("A", lw_variable[I].lv_type);
						if(ret2 == 0)
							{
								array_found = 1;
							}	
					}
			}

		if(x3 == 0)
			{
				for(I = 0; I < gv_ct; I++)
					{
						ret = strcmp(tfield2, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(tfield2a, gw_variable[I].gv_cname);
								ret2 = strcmp("A", gw_variable[I].gv_type);
								if(ret2 == 0)
									{
										array_found = 1;
									}
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_strlen.c c2_strlen E-246 tfield2 Not Found = %s\n",tfield2);
				c2_error();
			}

		if(array_found == 0)
			{
				tot_sizeof++;
				x3 = 0;		
				x2 = 0;
				for(I = 0; I < lv_ct; I++)
					{
						ret = strcmp(tfield2, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0)  && (ret1 == 0))
							{
								x3 = 1;
								x2 = lw_variable[I].lv_current_lgth;
								strcpy(tfield2a, lw_variable[I].lv_cname);
							}
					}

				if(x3 == 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(tfield2, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										x2 = gw_variable[I].gv_current_lgth;
										strcpy(tfield2a, gw_variable[I].gv_cname);
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_strlen.c c2_strlen E-247 tfield2 Not Found = %s\n",tfield2);
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
						strcpy(trace_1, "c2z_strlen.c c2_strlen #1");
						trace_rec_3();
					}
						
				for(I=0; I < lit_ct; I++)
					{
						if(w_literal[I].lit_rct == rct)
							{
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string,  w_literal[I].lit_use_cname);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_strlen.c c2_strlen #2");
										trace_rec_3();
									}
								break;
							}
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strlen.c c2_strlen #3");
						trace_rec_3();
					}

				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1a,gw_variable[I].gv_cname);
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
								ret = strcmp(tfield2a,gw_variable[I].gv_cname);
								if(ret == 0)
									{
										gw_variable[I].gv_use_ct++;
									}
							}
					}
			}

		if(array_found == 1)
			{
				printf("c2z_strlen.c c2_strlen E-248 array processing NOT FINISHED\n");
				c2_error();
			}

		convert = 1;
	}

void c2_strlen_punch()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch");
				trace_rec_1();
			}

		int v = 0;
		int wh_4 = 0;
		int I = 0;

		char field1a[VAR_LGTH];
				
		if(gv_ct > 0)
			{
				for(v = 0; v < gv_ct; v++)
					{
						wh_4 = strcmp("STRLEN", gw_variable[v].gv_name);
						if(wh_4 == 0)
							{				
								strcpy(field1a, gw_variable[v].gv_cname);
								gw_variable[I].gv_use_ct++;
							}
					}
			}

		strcpy(a_string, "*");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #1");
				trace_rec_3();
			}

		strcpy(a_string, "STRLEN   DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #2");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370LNK");
              strcpy(wk_remark, " addr C370LNK */");
              write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #3");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,");
		strcat(a_string, field1a);
              strcpy(wk_remark, " ");
		strcat(wk_remark, "STRLEN cname */");
              write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #4");
				trace_rec_3();
			}

		strcpy(a_string, "         ST    R9,0(R8)");
		strcpy(wk_remark, " store ret */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #5");
				trace_rec_3();
			}

		strcpy(a_string, "SZ10     DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #6");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #7");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         LARL  R8,C370ZERO");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #8");
				trace_rec_3();
			}
		work_use_ct[32]++;

		strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #9");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   SZ199");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #10");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #11");
				trace_rec_3();
			}
		work_use_ct[47]++;

		strcpy(a_string, "         LARL  R8,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #12");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #13");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #14");
				trace_rec_3();
			}
		work_use_ct[48]++;

		strcpy(a_string, "         CVB   R5,0(7,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #15");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L80");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #16");
				trace_rec_3();
			}
		work_use_ct[48]++;

		strcpy(a_string, "         IC    R0,0(R9,(R5))");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #17");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #18");
				trace_rec_3();
			}
		work_use_ct[2]++;

		strcpy(a_string, "         STC   R0,0(0,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #19");
				trace_rec_3();
			}
	
		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #20");
				trace_rec_3();
			}
		work_use_ct[2]++;

		strcpy(a_string, "         LARL  R8,C370PER");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #21");
				trace_rec_3();
			}
		work_use_ct[61]++;

		strcpy(a_string, "         CLC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #22");
				trace_rec_3();
			}
				
		strcpy(a_string, "         JE    ");
		strcat(a_string, "SZ199");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #23");
				trace_rec_3();
			}
    
		strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #24");
				trace_rec_3();
			}
		work_use_ct[49]++;
	
		strcpy(a_string, "         LARL  R8,C370ONE");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #25");
				trace_rec_3();
			}
		work_use_ct[33]++;

		strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #26");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   SZ10");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #27");
				trace_rec_3();
			}

		strcpy(a_string, "SZ199");
		check_length();
		strcat(a_string, "DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #28");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #29");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         LARL  R8,C370ONE");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #30");
				trace_rec_3();
			}
		work_use_ct[33]++;

		strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #31");
				trace_rec_3();
			}

		strcpy(a_string, "         BR    C370LNK");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_strlen.c c2_strlen_punch #32");
				trace_rec_3();
			}
	}


void c2_strlen_pass2()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_strlen.c c2_strlen_pass2");
        trace_rec_1();
     }

     check_semi();

     char *p;
     char *p1;
     char ch;
     char tfield1[VAR_LGTH];
     char tfield1a[VAR_LGTH];
     char tfield2[VAR_LGTH];
     char tfield2a[VAR_LGTH];
     char tfield3b[VAR_LGTH];
     char tfield21[VAR_LGTH];

      int pi;
      int pi2;
      int strl_1 = 0;
      int strl_3 = 0;
      int x3 = 0;
      int x99 = 0;
      int I = 0;
      int s = 0;
      int s1 = 0;
      int size = 0;
      int rct1 = 0;
      int ret = 0;
      int ret1 = 0;
      int ret2 = 0;
      int end_of_string = 0;
      int array_found = 0;

     pi = 0;
     ch = p_string[pi];
     check_blank();

     p = strstr(p_string, "[");
     if(p)
     {
        array_found = 1;
     }

     if(array_found == 0)
     {
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

printf("c2z_strlen c2_pass2_strlen rct = %d p_string = %s",rct,p_string);
printf("c2z_strlen c2_pass2_strlen tfield1 = %s\n",tfield1);

        strl_3 = 0;
        if(lv_ct > 0)
        {
           for(I = 0; I < lv_ct; I++)
           {
              ret = strcmp(tfield1, lw_variable[I].lv_name);
              ret1 = strcmp(sv_func, lw_variable[I].lv_func);
              if((ret == 0) && (ret1 == 0))
              {
                 strl_3 = 1;
                 strcpy(tfield1a, lw_variable[I].lv_cname);
              }
           }
        }

        if(strl_3 == 0)
        {
           if(gv_ct > 0)
           {
              for(I = 0; I < gv_ct; I++)
              {
                 strl_1 = strcmp(tfield1, gw_variable[I].gv_name);
                 if(strl_1 == 0)
                 {
                    strl_3 = 1;
                    strcpy(tfield1a, gw_variable[I].gv_cname);
                 }
              }
           }
        }

        if(strl_3 == 0)
        {
           printf("c2z_strlen.c c2_strlen_pass2 E-176 tfield1 Not Found = %s\n",tfield1);
           c2_debug();
           exit(0);
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
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
			} 
		tfield2[pi2] = '\0';
printf("c2z_strlen c2_pass2_strlen tfield2 = %s\n",tfield2);

		
		x3 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(tfield2, lw_variable[I].lv_name);
				ret2 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret2 == 0))
					{
						x3 = 1;		
						strcpy(tfield2a, lw_variable[I].lv_cname);
						ret2 = strcmp("A", lw_variable[I].lv_type);
						if(ret2 == 0)
							{
								array_found = 1;
							}	
					}
			}

		if(x3 == 0)
			{
				for(I = 0; I < gv_ct; I++)
					{
						ret = strcmp(tfield2, gw_variable[I].gv_name);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(tfield2a, gw_variable[I].gv_cname);
								ret2 = strcmp("A", gw_variable[I].gv_type);
								if(ret2 == 0)
									{
										array_found = 1;
									}
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_pass_2.c c2_strlen E-177 tfield2 Not Found = %s\n",tfield2);
				c2_debug();
                            exit(0);
			}

		if(array_found == 0)
			{
				tot_sizeof++;
				x3 = 0;		
				s = 0;
				for(I = 0; I < lv_ct; I++)
					{
						ret = strcmp(tfield2, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0)  && (ret1 == 0))
							{
								x3 = 1;
								s = lw_variable[I].lv_current_lgth;
							}
					}

				if(x3 == 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(tfield2, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										s = gw_variable[I].gv_current_lgth;
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_pass_2.c c2_strlen E-178 tfield2 Not Found = %s\n",tfield2);
						c2_error();
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d", s);
				strcpy(tfield2, wk_strg);

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

     if(array_found == 1)
     {




        printf("c2z_pass_2.c c2_strlen E181 array processing NOT FINISHED\n");
      /*  c2_debug();
        exit(0); */
     }
     convert = 1;
}






