/* ***************************************************
*  c2  : c2z_macro.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out SIZEOF                                  *
* ************************************************** */
void c2_sizeof()
{
  if(trace_flag == 1)
  {
    strcpy(trace_1, "c2z_macro.c c2_sizeof");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3a[VAR_LGTH];

   int x = 0;
   int x3 = 0;
   int pi;
   int pi2;
   int I = 0;
   int ret = 0;
   int end_of_string = 0;

  /*  move down to first non-blank */
  pi = 0;
  ch = p_string[pi];
  while((ch == ' ') || (ch == '\t'))
  {
    pi++;
    ch = p_string[pi];
  }

  /* now at first non-blank, should be c keyword */
  /* loop thru to 1st blank after field name     */
  pi2 = 0;
  while(ch != ' ')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  } 
  field1[pi2] = '\0';

  /*  get v_cname from w_variable               */
  /*  check lw_variable 1st                     */
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
    printf("sizeof ERROR MESSAGE\n");
    exit(1);
  }

		/* now skip down to 1st ( */
		pi++;
		ch = p_string[pi];
		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			} 

		/* should be at string variable to check */
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

		/*  get v_cname from w_variable               */
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

		/* Now check to see if field2 has been defined */
		/* and is a string field.                      */
		I = 0;
		x3 = 0;
		for(I=0; I < gv_ct; I++)
			{
				ret = strcmp(field2,gw_variable[I].gv_name);
				if(ret == 0)
					{
						x3 = 1;		/* found variable */
						break;
					}
			}

		if(x3 == 0)
			{
				printf("c2_scan_malloc FIEDL2 Not Found = %s\n",field2);
				printf("c2_scan_malloc rct = %d p_string = %s",rct,p_string);
				exit(1);
			}
											
		ret = strcmp(gw_variable[I].gv_type, "C");
		if(ret != 0)
			{
				printf("c2_scan_malloc FIEDL2 Not Character = %s\n",field2);
				printf("c2_scan_malloc rct = %d p_string = %s",rct,p_string);
				exit(1);
			}

		/* look up field2a from w_variable to get v_lgth */
		x3 = 0;		/* found variable x == 0 not found, x == 1 found */
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
				printf("Error variable not found \n");
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
				strcpy(trace_1, "c2z_macro.c c2_sizeof #1");
				trace_rec_3();
			}

	       strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #2");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         LARL  R8,C370ZERO");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #3");
				trace_rec_3();
			}
		work_use_ct[32]++;
	
		strcpy(a_string, "         CP    ");
		strcat(a_string, "0(4,R9),0(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #4");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   SZ");
		snprintf(wk_strg, sizeof(wk_strg), "%d", tot_sizeof);
		strcat(a_string, wk_strg);
		strcat(a_string, "99");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #5");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L8");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #6");
				trace_rec_3();
			}
		
		strcpy(a_string, "         LARL  R8,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #7");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         UNPK  0(8,R9),0(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #8");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #9");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370L8");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #10");
				trace_rec_3();
			}

		strcpy(a_string, "         PACK  0(8,r9),0(8,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #11");
				trace_rec_3();
			}
		
		strcpy(a_string, "         LARL  R9,C370U");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #12");
				trace_rec_3();
			}

		strcpy(a_string, "         CVB   R5,0(7,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #13");
				trace_rec_3();
			}
		work_use_ct[48]++;

		strcpy(a_string, "         AHI   R5,-1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #14");
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
				strcpy(trace_1, "c2z_macro.c c2_sizeof #15");
				trace_rec_3();
			}

		strcpy(a_string, "         IC    R0,");
		strcat(a_string, "0(R9,(R5))");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #16");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #17");
				trace_rec_3();
			}
	
		strcpy(a_string, "         STC   R0,0(0,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #18");
				trace_rec_3();
			}
		work_use_ct[2]++;

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #19");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #20");
				trace_rec_3();
			}

		strcpy(a_string, "         CLC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #21");
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
				strcpy(trace_1, "c2z_macro.c c2_sizeof #22");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #23");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         LARL  R8,C370ONE");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #24");
				trace_rec_3();
			}
		work_use_ct[33]++;

		strcpy(a_string, "         SP    0(4,R9),0(4,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #25");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   SZ");
		snprintf(wk_strg, sizeof(wk_strg), "%d", tot_sizeof);
		strcat(a_string, wk_strg);
		strcat(a_string, "0");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #26");
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
				strcpy(trace_1, "c2z_macro.c c2_sizeof #27");
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
				strcpy(trace_1, "c2z_macro.c c2_sizeof #28");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         LARL  R8,C370NWK1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #29");
				trace_rec_3();
			}
		work_use_ct[49]++;

		strcpy(a_string, "         ZAP   ");
		strcat(a_string, "0(4,R9),0(4,R8)");
		strcpy(wk_remark, " end size */");
		write_remark();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_sizeof #30");
				trace_rec_3();
			}
		work_use_ct[49]++;

		/* use field1a to update v_use_ct */
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


		/* use field2a to update v_use_ct */
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
*  Scan for malloc                                   *
* ************************************************** */
void c2_scan_malloc()
	{

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_scan_malloc");
				trace_rec_1();
			}

		char ch;
		char *p5, *p6;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		
		int x3 = 0;
		int I = 0;
		int pi;
		int pi2;
		int ret = 0;
		int ret1 = 0;

		/* check_semi(); */

		p5 = strstr(p_string, "[");
		p6 = strstr(p_string, "]");

		if((!p5) && (!p6))		/* no [] on the left of = 	*/
			{
				/*  move down to first non-blank */
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
						if(ch != '=')
							{
								tfield1[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				/* check tfield1 in w_variable for type=A and cname */
				x3 = 0;
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
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
						if(ch != '=')
							{
								tfield2[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				/* check tfield2 in w_variable for cname */
				x3 = 0;
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
			}	/* end of !p5 && !p6 */


		if((p5) && (p6))		/* [] on the left of = 	*/
			{
				/*  move down to first non-blank */
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
						if(ch != '=')
							{
								tfield1[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

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
						if(ch != '=')
							{
								tfield2[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				/* check tfield1 in w_variable for type=A and cname */
				x3 = 0;
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
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
						printf("C2_SCAN_MALLOC [] Error #1 rct = %d,p_string = %s", rct,p_string);
					} 

				/* check tfield2 in lw_variable for compiler name	*/
				
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
										strcpy(tfield3, lw_variable[I].lv_value);
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
												strcpy(tfield3, gw_variable[I].gv_value);
												gw_variable[I].gv_use_ct++;
											}
									}
							}
					}


				if(x3 == 0)
					{
						printf("c2_scan_malloc [] Error #2 rct = %d,p_string = %s", rct,p_string);
					} 


				/* now look up field1a in gw_variable to updatge */
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1a, gw_variable[I].gv_cname);
								if(ret == 0)
									{
										gw_variable[I].gv_lgth = atoi(tfield3);
										gw_variable[I].gv_column = atoi(tfield3);
									}
							}
					}

				convert = 1;
			}
	}



/* ***************************************************
*  Scan for realloc                                  *
* ************************************************** */
void c2_scan_realloc()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_scan_realloc");
				trace_rec_1();
			}

		char ch;
		char *p5, *p6;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		
		int x3 = 0;
		int I = 0;
		int pi;
		int pi2;
		int ret = 0;
		int ret1 = 0;

		/* check_semi(); */

		p5 = strstr(p_string, "[");
		p6 = strstr(p_string, "]");

		if((!p5) && (!p6))		
			{
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
						if(ch != '=')
							{
								tfield1[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

				x3 = 0;
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
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
						if(ch != '=')
							{
								tfield2[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				x3 = 0;
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


		if((p5) && (p6))		
			{
				/*  move down to first non-blank */
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
						if(ch != '=')
							{
								tfield1[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield1[pi2] = '\0';

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
						if(ch != '=')
							{
								tfield2[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield2[pi2] = '\0';

				/* check tfield1 in w_variable for type=A and cname */
				x3 = 0;
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
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
						printf("C2_SCAN_REALLOC [] Error #1 rct = %d,p_string = %s", rct,p_string);
					} 

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
										strcpy(tfield3, lw_variable[I].lv_value);
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
												strcpy(tfield3, gw_variable[I].gv_value);
												gw_variable[I].gv_use_ct++;
											}
									}
							}
					}


				if(x3 == 0)
					{
						printf("c2_scan_realloc [] Error #2 rct = %d,p_string = %s", rct,p_string);
					} 

				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1a, gw_variable[I].gv_cname);
								if(ret == 0)
									{
										gw_variable[I].gv_lgth = atoi(tfield3);
										gw_variable[I].gv_column = atoi(tfield3);
									}
							}
					}

				convert = 1;
			}
	}



/* ***************************************************
*  Punch out FREE                                    *
* ************************************************** */
void c2_free()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_macro.c c2_free");
			}

		int ret = 0;
		int ret1 = 0;
		int ret2 = 0;
		int pi;
		int pi2;
		int fr_1 = 0;
		int fr_2 = 0;
		int fr_3 = 0;
		int x1 = 0;
		int x2 = 0;
		
		char ch;
	       char fr_type[2];
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield11a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield4[VAR_LGTH];
		char tfield4a[VAR_LGTH];

		char ar_field5[VAR_LGTH];
		char ar_field6[VAR_LGTH];
		char ar_field7[VAR_LGTH];
		char ar_field8[VAR_LGTH];
		char ar_field9[VAR_LGTH];
		char ar_field10[VAR_LGTH];
		char ar_field11[VAR_LGTH];
		
		int I = 0;
		int v = 0;
		int x4 = 0;
		int x5 = 0;
		int xr = 0;
		int xc = 0;
		int x80 = 0;
		int x81 = 0;
		int x98 = 0;
		
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
				tfield1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield1[pi2] = '\0';

		fr_3 = 0;
		if(lv_ct > 0)
			{
				for(I = 0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0)) 
							{
								fr_3 = 1;
								strcpy(tfield1a, lw_variable[I].lv_cname);
								lw_variable[I].lv_use_ct++;
								strcpy(fr_type, lw_variable[I].lv_type);
								x2 = lw_variable[I].lv_lgth;
							}
					}
			}

		if(fr_3 == 0)
			{
				if(gv_ct > 0)
					{
						
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1, gw_variable[I].gv_name);
								if(ret == 0) 
									{
										fr_3 = 1;
										strcpy(tfield1a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;
										strcpy(fr_type, gw_variable[I].gv_type);
										xr = gw_variable[I].gv_row;
										xc = gw_variable[I].gv_column;
										x2 = gw_variable[I].gv_lgth;
									}
							}
					}
			}

		if(fr_3 == 0)
			{
				for(I=0; I < m_struc_ct; I++)
					{
						ret = strcmp(tfield1, w_struc[I].st_wname);
						if(ret == 0)
							{
								fr_3 = 1;
								fr_1 = 6;
								break;
							}
					}
			}
		
		if(fr_3 == 0)
			{
				printf("c2z_macro.c c2_free tfield1 Not Found %s\n",tfield1);
				printf("c2z_macro.c c2_free rct = %d,p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			} 

		fr_2 = strcmp(fr_type,"C");
		if(fr_2 == 0)
			{
				fr_1 = 1;
			}

		fr_2 = strcmp(fr_type,"I");
		if(fr_2 == 0)
			{
				fr_1 = 2;
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
				printf("c2_free type  not coded\n");
			}

		if(fr_1 == 1) 		/* clear character	*/
			{

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free char #1");
						trace_rec_3();
					}
	
				strcpy(a_string, "         LARL  R8,C370B1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free char #2");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free char #3");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   1(");
				x2 = x2 - 1;
				snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
				strcat(a_string, wk_strg);
				strcat(a_string, ",R9),0(R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free char #4");
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
						strcpy(trace_1, "c2z_macro.c c2_free char #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370EOF");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free char #6");
						trace_rec_3();
					}
				work_use_ct[74]++;

				strcpy(a_string, "         MVC   ");
                            strcat(a_string, "0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free char #7");
						trace_rec_3();
					}
				
			}

		if(fr_1 == 2)			/* integer clear	*/
			{
				strcpy(a_string, "*         LARL  R9,");
				strcat(a_string, tfield1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free char #4");
						trace_rec_3();
					}

				strcpy(a_string, "*         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free char #5");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "*         ZAP   ");
				strcat(a_string, "0(4,R9),0(4,R8)");
				strcpy(wk_remark, " free    */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free char #6");
						trace_rec_3();
					}
			}

		if(fr_1 == 3)			/* Array A clear	*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-char");
						trace_rec_1();
					}

				fr_3 = 0;
				if(gv_ct > 0)
					{
						
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1, gw_variable[I].gv_name);
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
										x1 = gw_variable[I].gv_row;
										x2 = gw_variable[I].gv_column;
										
									}
							}
					}


				/*  look up field11 in lw_variable */
				fr_3 = 0;
				fr_2 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(ar_field11, lw_variable[v].lv_name);
						if(ret == 0)
							{
								fr_3 = 1;
								strcpy(tfield11a, lw_variable[v].lv_cname);
							}
					}

				/*  look up field11 in lw_variable */
				if(fr_3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(ar_field11, gw_variable[v].gv_name);
								if(ret == 0)
									{
										fr_3 = 1;
										strcpy(tfield11a, gw_variable[v].gv_cname);
									}
							}
					}

				if(fr_3 == 0)
					{
						printf("c2z_free.c c2_free ar_field11 Not Found = %s\n",ar_field11);
						printf("c2z_free.c c2_free rct = %d p_string = %s",rct,p_string);
						exit(1);
					}

				strcpy(a_string, "FR");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				check_length();
				strcat(a_string, "DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-char #1");
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
						strcpy(trace_1, "c2z_macro.c c2_free array-char #3");
						trace_rec_3();
					}

				strcpy(a_string, "         LA    R5,");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-char #4");
						trace_rec_3();
					}

				strcpy(a_string, "FR");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "L");
				check_length();
				strcat(a_string, "DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-char #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370B1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-char #6");
						trace_rec_3();
					}
				work_use_ct[52]++;

				strcpy(a_string,"         MVC   0(1,R6),0(R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-char #7");
						trace_rec_3();
					}

				x2--;
				snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
				strcpy(a_string,"         MVC   1(");
				strcat(a_string, wk_strg);
				strcat(a_string, ",R6),0(R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-char #8");
						trace_rec_3();
					}

				strcpy(a_string,"         LA    R6,");
				strcat(a_string,ar_field6);
				strcat(a_string, "(R0,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_marco.c c2_free array-char #9");
						trace_rec_3();
					}

				strcpy(a_string, "        JCT   R5,");
				strcat(a_string, "FR");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "L");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-char #10");
						trace_rec_3();
					}
			}

		if(fr_1 == 4)			/* Array G clear	*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric");
						trace_rec_1();
					}

				fr_3 = 0;
				if(gv_ct > 0)
					{
						
						for(I = 0; I < gv_ct; I++)
							{
								ret = strcmp(tfield1, gw_variable[I].gv_name);
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
						ret = strcmp(ar_field11, lw_variable[v].lv_name);
						if(ret == 0)
							{
								fr_3 = 1;
								strcpy(field11a, lw_variable[v].lv_cname);
							}
					}

				if(fr_3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(ar_field11, gw_variable[v].gv_name);
								if(ret == 0)
									{
										fr_3 = 1;
										strcpy(field11a, gw_variable[v].gv_cname);
									}
							}
					}

				if(fr_3 == 0)
					{
						printf("c2z_macro.c c2_free ar_field11 Not Found %s\n",ar_field11);
						printf("c2z_macro.c c2_free rct = %d p_string = %s",rct,p_string);
						exit(1);
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric #1");
						trace_rec_3();
					}
				work_use_ct[49]++;


				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric #2");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(4,R9),0(4,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric #3");
						trace_rec_3();
					}

				strcpy(a_string, "FR");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				check_length();
				strcat(a_string, "DS    0H");
				strcpy(wk_remark, " ");
				strcat(wk_remark, "free */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric #4");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R6,");
				strcat(a_string, ar_field7);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric #5");
						trace_rec_3();
					}

				strcpy(field2, field1);
				strcat(field2, "_rows");

				/*  get the number of rows	*/

				for(v = 0; v < gv_ct; v++)
					{
						ret = strcmp(field2, gw_variable[v].gv_name);
						if(ret == 0)
							{
								x4 = gw_variable[v].gv_lgth;
							}
					}

				strcpy(a_string, "         LA    R5,");
				snprintf(wk_strg, sizeof(wk_strg), "%d", xr);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric #6");
						trace_rec_3();
					}

				strcpy(a_string, "FR");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "L");
				check_length();
				strcat(a_string, "DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric #7");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric #8");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         ZAP   ");
				strcat(a_string, "0(4,R6),0(4,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric #9");
						trace_rec_3();
					}

				strcpy(a_string,"        LA    R6,");
				strcat(a_string,ar_field6);
				strcat(a_string, "(R0,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric #10");
						trace_rec_3();
					}

				strcpy(a_string, "         JCT   R5,");
				strcat(a_string, "FR");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				strcat(a_string, "L");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric #11");
						trace_rec_3();
					}

				strcpy(a_string, "*");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free array-numeric #12");
						trace_rec_3();
					}
			}

		if(fr_1 == 5)			/* double clear	*/
			{

			}
		
		if(fr_1 == 6)			/* Structure		*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free structure");
						trace_rec_1();
					}

				fr_3 = 0;
				for(I = 0; I < m_struc_ct; I++)
					{
						ret = strcmp(tfield1, w_struc[I].st_wname);
						if(ret == 0) 
							{
								fr_3 = 1;
								strcpy(tfield2, w_struc[I].st_name);
								strcpy(tfield1a, w_struc[I].st_cwname);
								strcpy(tfield4a, w_struc[I].st_cname);
								break;
							}
					}

				strcat(tfield1a, "T");
				strcat(tfield4a, "L");

				strcpy(tfield3,tfield2);
				strcat(tfield3, "_max_ct");
		
				fr_3 = 0;
				fr_2 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(tfield3, lw_variable[v].lv_name);
						if(ret == 0)
							{
								fr_3 = 1;
								strcpy(tfield3a, lw_variable[v].lv_value);
							}
					}

				if(fr_3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(tfield3, gw_variable[v].gv_name);
								if(ret == 0)
									{
										fr_3 = 1;
										strcpy(tfield3a, gw_variable[v].gv_value);
									}
							}
					}

				if(fr_3 == 0)
					{
						printf("c2z_free.c c2_free tfield3 Not Found = %s\n",tfield3);
						printf("c2z_free.c c2_free rct = %d p_string = %s",rct,p_string);
						c2_debug();
						exit(1);
					}

				x98 = atoi(tfield3a);

				strcpy(a_string, "         LARL  R6,");
				strcat(a_string, tfield1a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free Struc #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LA    R5,");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x98);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free Struc #2");
						trace_rec_3();
					}

				strcpy(a_string, "FR");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				check_length();
				strcat(a_string, "DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free Struc #3");
						trace_rec_3();
					}

				fr_3 = 0;
				for(I = 0; I < m_struc_ct; I++)
					{
						ret = strcmp(tfield1, w_struc[I].st_wname);
						ret1 = strcmp(w_struc[I].st_id, "N");
						if((ret == 0)  && (ret1 == 0))
							{
								x80 = w_struc[I].st_disp;
								x81 = w_struc[I].st_field_lgth;

								ret2 = strcmp(w_struc[I].st_type, "C");
								if(ret2 == 0)
									{
										strcpy(a_string, "         LARL  R9,C370B1");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_macro.c c2_free Struc #4");
												trace_rec_3();
											}
										work_use_ct[52]++;

										snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
										strcpy(a_string,"         MVC   ");
										strcat(a_string, wk_strg);
										strcat(a_string, "(1,R6),0(R9)");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_macro.c c2_free Struc #5");
												trace_rec_3();
											}

										x80++;
										snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
										strcpy(a_string,"         MVC   ");
										strcat(a_string, wk_strg);
										strcat(a_string, "(");
										snprintf(wk_strg, sizeof(wk_strg), "%d", x81);
										strcat(a_string, wk_strg);
										x80--;
										strcat(a_string, ",R6),");
										snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
										strcat(a_string, wk_strg); 
										strcat(a_string, "(R6)");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_macro.c c2_free Struc #6");
												trace_rec_3();
											}
									}
								ret2 = strcmp(w_struc[I].st_type, "I");
								if(ret2 == 0)
									{
										strcpy(a_string, "         LARL  R9,C370ZERO");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_macro.c c2_free Struc #7");
												trace_rec_3();
											}

										snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
										strcpy(a_string,"         ZAP   ");
										strcat(a_string, wk_strg);
										strcat(a_string, "(4,R6),0(4,R9)");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_macro.c c2_free Struc #8");
												trace_rec_3();
											}
									}
							}
					}

				strcpy(a_string,"         LA    R6,");
				strcat(a_string, tfield4a);
				strcat(a_string, "(R0,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_marco.c c2_free Struct #9");
						trace_rec_3();
					}

				strcpy(a_string, "         JCT   R5,");
				strcat(a_string, "FR");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_macro.c c2_free Struc #10");
						trace_rec_3();
					}
			}

		convert = 1;
	}



