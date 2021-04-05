/* ***************************************************
*  c2z : c2z_print.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */ 

/* *************************************************** 
*  Punch out FPRINTF conversion.                     *
* ************************************************** */
void c2_fprintf()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_print.c c2_fprintf");
        trace_rec_1();
     }

     char ch;
     char *p1, *p2;
     char field1[VAR_LGTH];
     char field1a[VAR_LGTH];
     char field2[VAR_LGTH];
     char field2a[VAR_LGTH];
     char field3[VAR_LGTH];
     char field3a[VAR_LGTH];
     char field4[VAR_LGTH];
     char field10[VAR_LGTH];

      int pi;
      int pi2;		
      int x = 0;
      int x2 = 0;
      int x3 = 0;
      int x4 = 0;
      int x5 = 0;
      int s = 0;
      int I = 0;
      int w_buf_ct = 0;
      int ret = 0;
      int ret1 = 0;

     check_semi();
		
     s = strlen(p_string);
     x = 0;
     x2 = 0;
     for(I = 0; I < s; I++)
     {
        ch = p_string[I];
	 if(ch == '\"')
	 {
	    x++;
	    x2 = I;
	 }
     }

     if(x != 2)
     {
        printf("c2_fprintf Missing Starting Quote\n");
        printf("c2_fprintf rct = %d p_string = %s",rct,p_string);
        c2_debug();
        exit(1);
     }

     s = strlen(p_string);
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
     while(ch != ',')
     {
        field1[pi2] = ch;
	 pi2++;
	 pi++;
	 ch = p_string[pi];
     } 
     field1[pi2] = '\0';

     for(I = 0; I < f_ct; I++)
     {
        ret = strcmp(field1,w_file[I].f_name);
	 if(ret == 0)
	 {
	    strcpy(field1a, w_file[I].f_cname);
	    w_buf_ct = w_file[I].f_buf_ct;
        }
     }

     p1 = strstr (p_string,"%s");
     p2 = strstr (p_string,"%d");

     if((!p1) && (!p2))		/* literal only */
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf literal");
						trace_rec_1();
					}

				strcat(a_string, "         LARL  R9,C370PB");
				snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf literal #1");
						trace_rec_3();
					}

				strcpy(field2,"L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(field2, wk_strg);
				for(x3 = 0; x3 < v_const; x3++)
					{
						ret = strcmp(field2, w_constant[x3].const_current);
						if(ret == 0)
							{
								strcat(field10, w_constant[x3].const_use);
							}
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field10);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf literal #2");
						trace_rec_3();
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field10, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								x4 =  lw_variable[I].lv_lgth;
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
										x4 = gw_variable[I].gv_lgth;
									}
							}

					}

				strcpy(a_string, "         MVC   C370PB");
				snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
				strcat(a_string, wk_strg);
				strcat(a_string, "(L'");
							
				strcpy(field2,"L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(field2, wk_strg);
				for(x3 = 0; x3 < v_const; x3++)
					{
						ret = strcmp(field2, w_constant[x3].const_current);
						if(ret == 0)
							{
								strcat(a_string, w_constant[x3].const_use);
								strcat(a_string, "),");
								strcat(a_string, w_constant[x3].const_use);
								strcpy(wk_remark, " fprintf  */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf literal #3");
										trace_rec_3();
									}
							}
					}

				strcpy(a_string, "         PUT    ");
				strcat(a_string, field1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf literal #4");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL   R9,C370PB");
				snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf literal #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL   R8,C370PB");
				snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf literal #6");
						trace_rec_3();
					}
		
				strcpy(field4,"C370PB");
				snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
				strcat(a_string, wk_strg);

				x3 = 0;
				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(field4,gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										x4 = gw_variable[I].gv_lgth;
									}
							}

					}

				strcpy(a_string, "         XC     ");
				strcat(a_string, "0(R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf literal #7");
						trace_rec_3();
					}

				strcpy(a_string, "*         MVC    ");
				strcat(a_string, "C370PB");
				snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
				strcat(a_string, wk_strg);
				strcat(a_string, "(132),=CL132' '");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf literal #8");
						trace_rec_3();
					}
										
				var_use[2]++;
				fprintf_lit = 1;
			}

		p1 = strstr(p_string,"%s");		
		if(p1)						
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf string");
						trace_rec_1();
					}

				pi = 0;
				ch = p_string[pi];
				while(ch != ',')
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
				pi2 = 0;
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

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field2, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(field2a, lw_variable[I].lv_cname);
								x5 = lw_variable[I].lv_lgth;
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
										strcpy(field2a,gw_variable[I].gv_cname);
										x5 = gw_variable[I].gv_lgth;
									}
							}

					}

				if(x3 == 0)
					{
						printf("c2z_print.c c2_fprintf field2 Not Found = %s\n",field2);
						printf("c2z_print.c c2_fprintf rct = %d p_string = %s\n",rct,p_string);
						c2_debug();
						exit(1);
					}

				x = 0;
				for(I=0; I < f_ct; I++)
					{
						ret = strcmp(field1,w_file[I].f_name);
						if(ret == 0)
							{
								strcpy(a_string, "         LARL  R9,C370PB");
								snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #1");
										trace_rec_3();
									}

								strcpy(field3,"L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(field3, wk_strg);

								for(x3 = 0; x3 < v_const; x3++)
									{
										ret = strcmp(field3, w_constant[x3].const_current);
										if(ret == 0)
											{
												strcpy(field3a, w_constant[x3].const_use);
												
											}
									}

								x3 = 0;
								for(I=0; I < lv_ct; I++)
									{
										ret = strcmp(field3a, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												x3 = 1;
												x4 = lw_variable[I].lv_lgth;
											}
									}

								if(x3 == 0)
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(field3a,gw_variable[I].gv_name);
												if(ret == 0)
													{
														x4 = gw_variable[I].gv_lgth;
														
													}
											}
									}
			
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field3a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #2");
										trace_rec_3();
									}

								strcpy(a_string, "         MVC   ");
								strcat(a_string, "0(");
								snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
								strcat(a_string,wk_strg);
								strcat(a_string, ",R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #3");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370PB");
								snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #4");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field2a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #5");
										trace_rec_3();
									}

								strcpy(a_string, "         MVC   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
								strcat(a_string,wk_strg);
								strcat(a_string, "(");
								snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
								strcat(a_string,wk_strg);
								strcat(a_string,",R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #6");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, field1a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #7");
										trace_rec_3();
									}

								strcpy(a_string, "         PUT   (R9)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #8");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370PB");
								snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
								strcat(a_string, wk_strg);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #9");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370B1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #10");
										trace_rec_3();
									}
								work_use_ct[52]++;
										
								strcpy(a_string, "         MVC   0(1,R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #11");
										trace_rec_3();
									}
			
								strcpy(a_string, "         MVC   1(131,R9),0(R9)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #12");
										trace_rec_3();
									}
							}	
					}	
			}


		p2 = strstr(p_string,"%d");		
		if(p2)
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf numeric");
						trace_rec_1();
					}

				s = strlen(p_string);
				pi = 0;
				ch = p_string[pi];
				while(ch != ',')
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
				while(ch == ' ')
					{
						pi++;
					}
				pi2 = 0;

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
										strcpy(field2, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;
									}
							}
					}

				for(I=0; I < f_ct; I++)
					{
						ret = strcmp(field1,w_file[I].f_name);
						if(ret == 0)
							{
								snprintf(wk_strg, sizeof(wk_strg), "%d", w_file[I].f_buf_ct);
							}
					}

				strcpy(a_string, "         MVC   C370PB");
				strcat(a_string, wk_strg);
				strcpy(field3,"L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(field3, wk_strg);

				for(x3 = 0; x3 < v_const; x3++)
					{
						ret = strcmp(field3, w_constant[x3].const_current);
						if(ret == 0)
							{
								strcat(a_string, "(L'");
								strcat(a_string, w_constant[x3].const_use);
								strcat(a_string, "),");
								strcat(a_string, w_constant[x3].const_use);
								strcat(a_string,"\n");
								fputs(a_string, cc370);
								var_use[1]++;
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_fprintf string #13");
										trace_rec_3();
									}
	
 							}
					}

				x3 = 0;
				for(x3 = 0; x3 < lv_ct; x3++)
					{
						ret = strcmp(field2, lw_variable[x3].lv_name);
						ret1 = strcmp(sv_func, lw_variable[x3].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(field2a, lw_variable[x3].lv_cname);
							}
					}

				if(x3 == 0)
					{
						for(x3 = 0; x3 < gv_ct; x3++)
							{
								ret = strcmp(field2, gw_variable[x3].gv_cname);
								if(ret == 0)
									{
										strcpy(field2a, gw_variable[x3].gv_cname);
									}
							}
					}
		
				strcpy(a_string, "         UNPK  C370AZNE,");
				strcat(a_string, c_wkname);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf string #14");
						trace_rec_3();
					}

				strcpy(a_string, "         MVZ   C370AZNE+L'C370AZNE-1(1),=X'F0'");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf string #15");
						trace_rec_3();
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						if(rct == lw_variable[I].lv_rct)
							{
								x2 = lw_variable[I].lv_lgth;
								break;
							}
					}
	
				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								if(rct == gw_variable[I].gv_rct)
									{
										x2 = gw_variable[I].gv_lgth;
										break;
									}
							}
					}

				for(I=0; I < f_ct; I++)
					{
						ret = strcmp(w_file[I].f_cname, output_file);
						if(ret == 0)
							{
								strcpy(a_string, "         MVC   C370PB");
								snprintf(wk_strg, sizeof(wk_strg), "%d", w_file[I].f_buf_ct);
								strcat(a_string, wk_strg);
							}
					}		
					
				snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
				strcat(a_string,"+");
				strcat(a_string, wk_strg);
				strcat(a_string, "(L'C370AZNE),C370AZNE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf string #16");
						trace_rec_3();
					}

				strcpy(a_string, "         BRASL R9,PUTFILE");
				strcpy(wk_remark, " putfile  */");
				write_remark(); 
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf string #17");
						trace_rec_3();
					}

				strcpy(a_string, "*");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_fprintf string #18");
						trace_rec_3();
					}

				fprintf_flag = 1;
			}	
	}


/* *************************************************** 
*  Punch out PRINTF conversion.                      *
* ************************************************** */
void c2_printf()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_print.c c2_printf");
				trace_rec_1();
			}

		char ch;
		char *p1, *p2, *p3;

		int x = 0;
		int I = 0;
		int s = 0;
		int x20 = 0;
		int x21 = 0;
		int x22 = 0;
		int x23 = 0;
		int x24 = 0;
		int ret = 0;
		int printf_type = 0;

		char tfield8[VAR_LGTH];
		char tfield9[VAR_LGTH];
		char tfield10[VAR_LGTH];

		tfield8[0] = '\0';
		tfield9[0] = '\0';
		tfield10[0] = '\0';

		printf_convert = 0;

		check_semi();

		s = strlen(p_string);
		x = 0;
		for(I = 0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '\"')
					{
						x++;
					}
			}

		if(fprintf_flag != 1)		
			{
				p1 = strstr(p_string,"%s");
				p2 = strstr(p_string,"%d");
				p3 = strstr(p_string,"%f");

				if(p1)
					{
						printf_type = 1;
						c2_printf_string();
						return;
					}

				if(p2)
					{
						printf_type = 2;
						c2_printf_numeric();
						return;
					}

				if(p3)
					{
						printf_type = 3;
						c2_printf_float();
						return;
					}

				x20 = 0;
				x21 = 0;
				x22 = 0;
				x23 = 0;
				x24 = 0;
				p3 = strstr(p_string, "%");
				if(p3)
					x20 = 1; 	

				if(x20 == 1)
					{
						s = strlen(p_string);
						for(I=0; I < s; I++)
							{
								ch = p_string[I];
								if(ch == '%')
									{
										x21 = 1;	
										x22 = I;
										break;
									}	

							}
					}

				if(x21 == 1)
					{
						x22++;
						tfield8[0] = p_string[x22];	
						tfield8[1] = '\0';
						ret = strcmp(".", tfield8);
						if(ret == 0)
							{
								strcpy(tfield9,tfield8);		
								tfield8[0] = '\0';
								x22++;
								tfield10[0] = p_string[x22];
								tfield10[1] = '\0';
								x23 = 1;
							}
						else
							{
								x22++;
								tfield9[0] = p_string[x22];
								tfield9[1] = '\0';
								x22++;
								tfield10[0] = p_string[x22];
								tfield10[1] = '\0';
								x23 = 1;
							}

					}

				if(x23 == 1)			/* format printf %.2d	*/
					{
						s = atoi(tfield10);
						c2_printf_dec_only(s);
						return;
					}

				if(x24 == 1)			/* format printf %4.2d	*/
					{
						printf("c2z_printf.c c2_printf E-139 x24 NOT CODED\n");
						c2_error();
					}

				if(printf_type == 0)
					{
						c2_printf_literal();
						return;
					}
			}
	}				


void c2_printf_literal()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_print.c c2_printf_literal");
				trace_rec_1();
			}

		int x3 = 0;
		int x4 = 0;
		int v = 0;
		int I = 0;
		int ret = 0;
		int ret1 = 0;

		char field1[VAR_LGTH];
	
		if(z390 == 1)
			{
				strcpy(field1,"L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(field1, wk_strg);

				for(x3 = 0; x3 < v_const; x3++)
					{
						ret = strcmp(field1, w_constant[x3].const_current);
						if(ret == 0)
							{
								strcpy(wk_strg, w_constant[x3].const_use);

								x4 = 0;
								if(lv_ct > 0)
									{
										for(v = 0; v < lv_ct; v++)
											{
												ret = strcmp(wk_strg, lw_variable[v].lv_name);
												ret1 = strcmp(sv_func, lw_variable[v].lv_func);
												if((ret == 0) && (ret1 == 0))
													{				
														x4 = 1;
														lw_variable[I].lv_use_ct++;
													}
											}
									}

								strcpy(wk_strg, w_constant[x3].const_use);

								if(x4 == 0)
									{
										if(gv_ct > 0)
											{
												for(v = 0; v < gv_ct; v++)
													{
														ret = strcmp(wk_strg, gw_variable[v].gv_name);
														if(ret == 0)
															{				
																x4 = 1;
																gw_variable[I].gv_use_ct++;
															}
													}
											}
									}
							}
					}

				strcpy(a_string, "         MVC2  ");
				strcat(a_string, "C370WTOB,");
				strcat(a_string, wk_strg);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_literal #6");
						trace_rec_3();
					}
	
				strcpy(a_string, "         BRASL C370PRTR,WTOALPHA");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_literal #7");
						trace_rec_3();
					}
			}

		printf_convert = 1;
							
	}

void c2_printf_numeric()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_print.c c2_printf_numeric");
				trace_rec_1();
			}

		char ch;
		char *p5, *p6, *p7;
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field4[VAR_LGTH];
		char field4a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field7a[VAR_LGTH];
		char field8[VAR_LGTH];
		char field9[VAR_LGTH];
		char field10[VAR_LGTH];
		char field11[VAR_LGTH];
		char field11a[VAR_LGTH];
		char field12[VAR_LGTH];
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield6a[VAR_LGTH];

		int pi;
		int pi2;
		int x3 = 0;
		int x4 = 0;
		int x5 = 0;
              int x15 = 0;
		int x90 = 0;
		int v = 0;
		int prf1 = 0;
		int prf2 = 0;
		int prf5 = 0;
		int prf6 = 0;
		int prf7 = 0;
		int prf10 = 0;
		int I = 0;
		int ret = 0;
		int ret1 = 0;
		int ret2 = 0;

		int fd1_define = 0;

		pi = 0;
		ch = p_string[pi];
		while(ch != '"')
			{
				pi++;
				ch = p_string[pi];
			} 

		prf1 = pi;		
		pi = 0;
		ch = p_string[pi];
		while(ch != '%')
			{
				pi++;
				ch = p_string[pi];
			} 
			
		prf2 = pi;		
		if (prf1 < prf2)		
			{
				pi = 0;
				while(ch != '"')		
					{
						pi++;
						ch = p_string[pi];
					} 
								
				pi++;
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

				prf6 = 0;
				p5 = strstr(field2, "[");
				p6 = strstr(field2, "]");
				p7 = strstr(field2, ".");
				if((p5) && (p6) && (!p7))	
					{
						prf6 = 1;		
					}
	
				if((p5) && (p6) && (p7))	
					{
						prf6 = 2;		
					}

				if(prf6 == 1)		
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_printf.c c2_printf %d ARRAY");
								trace_rec_1();
							}

						strcpy(field12,field1);

						pi2 = 0;
						prf7 = 0;
						ch = field2[prf7];
						while(ch != '[')
							{
								field4[pi2] = ch;
								pi2++;
								prf7++;
								ch = field2[prf7];
							}
						field4[prf7] = '\0';

						prf10 = 0;
						for(I=0; I < lv_ct; I++)
							{
								prf5 = strcmp(field4, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((prf5 == 0) && (ret1 == 0))	
									{
										prf10 = 1;
										strcpy(field4a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
									}
							}

						if(prf10 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										prf5 = strcmp(field4, gw_variable[I].gv_name);
										if(prf5 == 0)
											{
												prf10 = 1;
												strcpy(field4a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
											}
									}
							}

						if(prf10 == 0)
							{
								printf("c2z_print.c c2_printf_numeric E-290 field4 Not Found = %s\n",field4);
								c2_error();
							}

						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(field4a, gw_variable[I].gv_cname);
										if(ret == 0)
											{
												strcpy(field5,gw_variable[I].gv_dsect);
												strcpy(field6,gw_variable[I].gv_label);
												strcpy(field7,gw_variable[I].gv_table);
												strcpy(field8,gw_variable[I].gv_aname);
												strcpy(field9,gw_variable[I].gv_sv_reg);
												strcpy(field10,gw_variable[I].gv_wk_reg);
												strcpy(field11,gw_variable[I].gv_wk_strg);
												gw_variable[I].gv_flag = 1;
											}
									}
							}

						strcpy(field12,field4);
						
						strcpy(a_string, "         LARL  R9,C370NWK3");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #1");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #2");
								trace_rec_3();
							}

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #3");
								trace_rec_3();
							}

						strcpy(a_string, "         JLE   ");
						strcat(a_string, "AR");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "L");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #4");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK3");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #5");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #6");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #7");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R6,");
						strcat(a_string, field7);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #8");
								trace_rec_3();
							}

						strcpy(a_string, "AR");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "L");
						check_length();
						strcat(a_string, "DS    0H");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #9");
								trace_rec_3();
							}

						strcpy(field11,"L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(field11, wk_strg);

						for(x3 = 0; x3 < v_const; x3++)
							{
								ret = strcmp(field11, w_constant[x3].const_current);
								if(ret == 0)
									{
										strcpy(a_string, "         LARL  R9,C370WTOB");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #10");
												trace_rec_3();
											}

										strcpy(a_string, "         LARL  R8,");
										strcat(a_string, w_constant[x3].const_use);
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #11");
												trace_rec_3();
											}		

										strcpy(field11, w_constant[x3].const_use);

										x3 = 0;
										for(I=0; I < lv_ct; I++)
											{
												ret = strcmp(field11, lw_variable[I].lv_name);
												ret1 = strcmp(sv_func, lw_variable[I].lv_func);
												if((ret == 0) && (ret1 == 0))
													{
														x3 = 1;
														x15 = lw_variable[I].lv_lgth;
													}
											}

										if(x3 == 0)
											{
												for(I=0; I < gv_ct; I++)
													{
														ret = strcmp(field11, gw_variable[I].gv_name);
														if(ret == 0)
															{
																x3 = 1;
																x15 = gw_variable[I].gv_lgth;   
															}
													}
											}

										strcpy(a_string, "         MVC   ");
										strcat(a_string, "0(");
										snprintf(wk_strg, sizeof(wk_strg), "%d", x15);
										strcat(a_string, wk_strg);
										strcat(a_string, ",R9),0(R8)");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #12");
												trace_rec_3();
											}

										break;
									}
							}

						x3 = 0;	
						x4 = 0;
						strcpy(field7, wk_strg);
						for(I=0; I < lv_ct; I++)
							{
										ret = strcmp(field7, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												x3 = 1;
												x4 = lw_variable[I].lv_lgth;
											}
									}

								if(x3 == 0)
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(field7, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x4 = gw_variable[I].gv_lgth;   
													}
											}
									}

						pi2 = 0;
						prf7++;
						ch = field2[prf7];
						while(ch != ']') 
							{
								field7[pi2] = ch;
								pi2++;
								prf7++;
								ch = field2[prf7];
							}
						field7[pi2] = '\0';

						prf10 = 0;
						for(I=0; I < lv_ct; I++)
							{
								prf5 = strcmp(field7, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((prf5 == 0) && (ret1 == 0))
									{
										prf10 = 1;
										strcpy(field7a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
									}
							}

						if(prf10 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										prf5 = strcmp(field7, gw_variable[I].gv_name);
										if(prf5 == 0)
											{
												prf10 = 1;
												strcpy(field7a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
											}
									}
							}

						if(prf10 == 0)
							{
								printf("c2z_print.c c2_printf_numeric E-291 field7 Not Found = %s\n",field7);
								c2_error();
							}

						prf2 = 0;
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field11, lw_variable[v].lv_name);
								if(ret == 0)
									{
										strcpy(field11a, lw_variable[v].lv_cname);
									}
							}

						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field11, gw_variable[v].gv_name);
								if(ret == 0)
									{
										strcpy(field11a, gw_variable[v].gv_cname);
									}
							}

						strcpy(a_string, "         LARL  R9,C370LPCT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #13");
								trace_rec_3();
							}
						work_use_ct[73]++;

						strcpy(a_string, "         LARL  R8,C370ZERO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #14");
								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #15");
								trace_rec_3();
							}

						strcpy(a_string, "         JLNE  ");
						strcat(a_string, "PR");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "L");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #16");
								trace_rec_3();
							}
						
						strcpy(a_string, "         LARL  R9,C370LPCT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #17");
								trace_rec_3();
							}
						work_use_ct[73]++;

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #18");
								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #19");
								trace_rec_3();
							}

						strcpy(a_string, "PR");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "L");
						check_length();
						strcat(a_string, "DS    0H");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #20");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK2");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #21");
								trace_rec_3();
							}
						work_use_ct[50]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #22");
								trace_rec_3();
							}

						strcpy(a_string, "         LA    ");
						strcat(a_string, "R6,");
						strcat(a_string, field6);
						strcat(a_string, "(R0,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #23");
								trace_rec_3();
							}

						strcpy(print_array_name, field10);
						strcpy(print_array_table, field7);

						strcpy(a_string, "         LARL  R9,C370EDN");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #24");
								trace_rec_3();
							}
						work_use_ct[51]++;

						strcpy(a_string, "         LARL  R8,C370NWK2");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #25");
								trace_rec_3();
							}
						work_use_ct[50]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #26");
								trace_rec_3();
							}

						strcpy(a_string, "         BRASL C370PRTR,WTOIMVC");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #27");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370WTOB");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #28");
								trace_rec_3();
							}
						
						strcpy(a_string, "         LARL  R8,C370L10");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #29");
								trace_rec_3();
							}
						work_use_ct[71]++;

						if(gv_ct > 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(field1,gw_variable[I].gv_name);
										if(ret == 0)
											{
												x4 = gw_variable[I].gv_lgth;   
											}
									}
							}

						strcpy(a_string, "         MVC   ");
						snprintf(wk_strg, sizeof(wk_strg), "%d", x15);
						strcat(a_string, wk_strg);
						strcat(a_string, "(8,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #30");
								trace_rec_3();
							}

						strcpy(a_string, "         BRASL C370PRTR,WTOALPHA");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #31");
								trace_rec_3();
							}
						
						prt_array = 1;
						tot_wto++;
					}

				if(prf6 == 0)
					{
						prf10 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(field2, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										prf10 = 1;
										strcpy(field2a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
										ret2 = strcmp("I",lw_variable[I].lv_type);
										if(ret2 == 0)
											{
												fd1_define = 1;	/* Integer	*/
											}
										else
											{
												fd1_define = 2;	/* Double	*/
											}
									}
							}

						if(prf10 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										prf5 = strcmp(field2, gw_variable[I].gv_name);
										if(prf5 == 0)
											{
												prf10 = 1;
												strcpy(field2a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												ret2 = strcmp("I",gw_variable[I].gv_type);
												if(ret2 == 0)
													{
														fd1_define = 1;	/* Integer	*/
													}
												else
													{
														fd1_define = 2;	/* Double	*/
													}
											}
									}
							}

						if(prf10 == 0)
							{
								printf("c2z_print.c c2_printf Integer E-292 field2 Not Found = %s\n",field2);
								c2_error();
							}

						if((z390 == 1) && (fd1_define == 1))		
							{
								strcpy(a_string, "         LARL  R9,C370DEC");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Integer #25");
										trace_rec_3();
									}
								work_use_ct[67]++;

								strcpy(a_string, "         LARL  R8,C370ZERO");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Integer #26");
										trace_rec_3();
									}
								work_use_ct[32]++;

								strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Integer #27");
										trace_rec_3();
									}
								
								strcpy(field1,"L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(field1, wk_strg);

								for(x3 = 0; x3 < v_const; x3++)
									{
										ret = strcmp(field1, w_constant[x3].const_current);
										if(ret == 0)
											{

												strcpy(a_string, "         LARL  R9,");
												strcat(a_string, w_constant[x3].const_use);
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_print.c c2_printf %d Integer #28");
														trace_rec_3();
													}
												strcpy(field12, w_constant[x3].const_use);

												strcpy(a_string, "         LARL  R8,C370WTOB");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_print.c c2_printf %d Integer #29");
														trace_rec_3();
													}

												strcpy(wk_strg, w_constant[x3].const_use);

												x4 = 0;
												if(lv_ct > 0)
													{
														for(v = 0; v < lv_ct; v++)
															{
																ret = strcmp(wk_strg, lw_variable[v].lv_name);
																ret1 = strcmp(sv_func, lw_variable[v].lv_func);
																if((ret == 0) && (ret1 == 0))
																	{				
																		x4 = 1;
																		x5 = lw_variable[v].lv_lgth;
																		lw_variable[I].lv_use_ct++;
																	}
															}
													}

												strcpy(wk_strg, w_constant[x3].const_use);
												if(x4 == 0)
													{
														if(gv_ct > 0)
															{
																for(v = 0; v < gv_ct; v++)
																	{
																		ret = strcmp(wk_strg, gw_variable[v].gv_name);
																		if(ret == 0)
																			{				
																				x4 = 1;
																				x5 = gw_variable[v].gv_lgth;
																				gw_variable[v].gv_use_ct++;
																			}
																	}
															}
													}

												snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
												strcpy(a_string, "         MVC   0(");
												strcat(a_string, wk_strg);
												strcat(a_string, ",R8),0(R9)");
												strcpy(wk_remark, " printf   */");
												write_remark();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_print.c c2_printf %d Integer #30");
														trace_rec_3();
													}

												break;
											}
									}

								x3 = 0;	
                                                        strcpy(sv_print_lit,"L");
								strcat(sv_print_lit,wk_strg);

								x3 = 0;
								if(x3 == 0)		
									{
										for(v = 0; v < lv_ct; v++)
											{
												ret = strcmp(field2, lw_variable[v].lv_name);
												ret1 = strcmp(sv_func, lw_variable[v].lv_func);
												if((ret == 0)  && (ret1 == 0))
													{
														x3 = 1;
														strcpy(field2a, lw_variable[v].lv_cname);
														lw_variable[v].lv_use_ct++;
													}
											}
									}

								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(field2, gw_variable[v].gv_name);
										if(ret == 0)
											{
												x3 = 1;
												strcpy(field2a, gw_variable[v].gv_cname);
											}
									}

								x4 = 0;
								if(gv_ct > 0)
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(sv_print_lit, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x4 = gw_variable[I].gv_lgth;   
													}
											}
									}
								
								strcpy(a_string, "         LARL  R9,C370EDN");	
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Integer #31");
										trace_rec_3();
									}
								work_use_ct[51]++;

								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field2a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Integer #32");
										trace_rec_3();
									}

								strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Integer #33");
										trace_rec_3();
									}

								strcpy(a_string, "         BRASL C370PRTR,WTOIMVC");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Integer #34");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370WTOB");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Integer #35");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370L10");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Integer #36");
										trace_rec_3();
									}
								work_use_ct[71]++;

								strcpy(a_string, "         MVC   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
								strcat(a_string, wk_strg);
								strcat(a_string, "(10,R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Integer #37");
										trace_rec_3();
									}

								strcpy(a_string, "         BRASL C370PRTR,WTOALPHA");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Integer #38");
										trace_rec_3();
									}
								
								tot_wto++;
							}


						if((z390 == 1) && (fd1_define == 2))		
							{
								strcpy(field1,"L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(field1, wk_strg);

								for(x3 = 0; x3 < v_const; x3++)
									{
										ret = strcmp(field1, w_constant[x3].const_current);
										if(ret == 0)
											{
												strcpy(a_string, "         LARL  R9,");
												strcat(a_string, w_constant[x3].const_use);
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2_printf %d Double #39 ");
														trace_rec_3();
													}

												strcpy(a_string, "         LARL  R8,C370WTOB");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2_printf %d Double #40 ");
														trace_rec_3();
													}

												strcpy(wk_strg, w_constant[x3].const_use);

												x4 = 0;
												if(lv_ct > 0)
													{
														for(v = 0; v < lv_ct; v++)
															{
																ret = strcmp(wk_strg, lw_variable[v].lv_name);
																ret1 = strcmp(sv_func, lw_variable[v].lv_func);
																if((ret == 0) && (ret1 == 0))
																	{				
																		x4 = 1;
																		x5 = lw_variable[v].lv_lgth;
																		lw_variable[I].lv_use_ct++;
																	}
															}
													}

												strcpy(wk_strg, w_constant[x3].const_use);

												if(x4 == 0)
													{
														if(gv_ct > 0)
															{
																for(v = 0; v < gv_ct; v++)
																	{
																		ret = strcmp(wk_strg, gw_variable[v].gv_name);
																		if(ret == 0)
																			{				
																				x4 = 1;
																				x5 = gw_variable[v].gv_lgth;
																				gw_variable[I].gv_use_ct++;
																			}
																	}
															}
													}

												snprintf(wk_strg, sizeof(wk_strg), "%d", x5);

												strcpy(a_string, "         MVC   0(");
												strcat(a_string, wk_strg);
												strcat(a_string, ",R8),0(R9)");
												strcpy(wk_remark, " printf   */");
												write_remark();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2_printf %d Double #41 ");
														trace_rec_3();
													}
												break;
											}
									}

								x3 = 0;	
                                                        strcpy(sv_print_lit,"L");
								strcat(sv_print_lit,wk_strg);

								x3 = 0;
								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(field2, gw_variable[v].gv_name);
										if(ret == 0)
											{
												x3 = 1;
												strcpy(field2a, gw_variable[v].gv_cname);
											}
									}

								if(x3 == 0)		
									{
										for(v = 0; v < lv_ct; v++)
											{
												ret = strcmp(field2, lw_variable[v].lv_name);
												ret1 = strcmp(sv_func, lw_variable[v].lv_func);
												if((ret == 0)  && (ret1 == 0))
													{
														x3 = 1;
														strcpy(field2a, lw_variable[v].lv_cname);
														lw_variable[v].lv_use_ct++;
													}
											}
									}

								x4 = 0;
								if(gv_ct > 0)
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(sv_print_lit, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x4 = gw_variable[I].gv_lgth;   
													}
											}
									}

								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, field2a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_printf %d Double #42 ");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370U");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_printf %d Double #42 ");
										trace_rec_3();
									}
								work_use_ct[48]++;

								strcpy(a_string, "         CVD   R9,0(4,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_printf %d Double #43 ");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370TDW4");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_printf %d Double #42 ");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R7,C370EDW4");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_printf %d Double #42 ");
										trace_rec_3();
									}

								strcpy(a_string, "         MVC    0(4,R8),0(R7)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_printf %d Double #42 ");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370TDW4");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_printf %d Double #42 ");
										trace_rec_3();
									}

								strcpy(a_string, "        ED     0(4,R8),4(R9)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_printf %d Double #42 ");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370WTOB");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_printf %d Double #45 ");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370TDW4");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_printf %d Double #46 ");
										trace_rec_3();
									}
								work_use_ct[56]++;
								
								strcpy(a_string, "         MVC   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
								strcat(a_string, wk_strg);
								strcat(a_string, "(10,R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_printf %d Double #48 ");
										trace_rec_3();
									}

								strcpy(a_string, "         BRASL C370PRTR,WTOALPHA");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2_printf %d Double #49 ");
										trace_rec_3();
									}
								
								tot_wto++;
							}
					}

				if(prf6 == 2)
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct");
								trace_rec_1();
							}

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
								if(ch != '.')
									{
										tfield3[pi2] = ch;
										pi2++;
									}
								pi++;
								ch = p_string[pi];
							}
						tfield3[pi2] = '\0';

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
								printf("c2z_print.c c2_print_numeric Structure E-286 tfield1 Not Found = %s\n",tfield1);
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
								printf("c2z_print.c c2_print_numeric E-287 Structure tfield2 Not Found = %s\n",tfield2);
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
										x90 = w_struc[I].st_disp;
									}
							}

						if(x3 == 0)
							{
								printf("c2z_print.c c2_print_numeric E-288 Structure tfield1 Not Found = %s\n",tfield1);
								printf("c2z_print.c c2_print_numeric Structure tfield3 Not Found = %s\n",tfield3);
								c2_error();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #1");
 								trace_rec_3();
							}
						work_use_ct[49]++;

						strcpy(a_string, "         LARL  R8,C370ZERO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #2");
 								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #3");
 								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R6,");
                            		strcat(a_string, tfield1a);
						strcat(a_string, "T");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #4");
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
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #5");
 								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #6");
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
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #7");
 								trace_rec_3();
							}
				
						strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #8");
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
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #9");
 								trace_rec_3();
							}

						strcpy(a_string, "         LA    R6,");
						strcat(a_string, tfield6a);
						strcat(a_string, "L");
						strcat(a_string, "(R0,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #10");
 								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370NWK1");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #11");
 								trace_rec_3();
							}
						work_use_ct[49]++;

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #12");
 								trace_rec_3();
							}
				
						strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #13");
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
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #14");
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
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #15");
 								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370EDN");	
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #16");
								trace_rec_3();
							}
						work_use_ct[51]++;

						snprintf(wk_strg, sizeof(wk_strg), "%d", x90);
						strcpy(a_string,"         ZAP   ");
						strcat(a_string, "0(6,R9),");
						strcat(a_string, wk_strg);
						strcat(a_string, "(6,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #17");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370DEC");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #19");
								trace_rec_3();
							}
						work_use_ct[67]++;

						strcpy(a_string, "         LARL  R8,C370ZERO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #20");
								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #21");
								trace_rec_3();
							}
								
						strcpy(field1,"L");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(field1, wk_strg);

						for(x3 = 0; x3 < v_const; x3++)
							{
								ret = strcmp(field1, w_constant[x3].const_current);
								if(ret == 0)
									{
										strcpy(a_string, "         LARL  R9,");
										strcat(a_string, w_constant[x3].const_use);
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #22");
												trace_rec_3();
											}
										strcpy(field12, w_constant[x3].const_use);

										strcpy(a_string, "         LARL  R8,C370WTOB");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #23");
												trace_rec_3();
											}

										strcpy(wk_strg, w_constant[x3].const_use);

										x4 = 0;
										if(lv_ct > 0)
											{
												for(v = 0; v < lv_ct; v++)
													{
														ret = strcmp(wk_strg, lw_variable[v].lv_name);
														ret1 = strcmp(sv_func, lw_variable[v].lv_func);
														if((ret == 0) && (ret1 == 0))
															{				
																x4 = 1;
																x5 = lw_variable[v].lv_lgth;
																lw_variable[I].lv_use_ct++;
															}
													}
											}

										strcpy(wk_strg, w_constant[x3].const_use);
										if(x4 == 0)
											{
												if(gv_ct > 0)
													{
														for(v = 0; v < gv_ct; v++)
															{
																ret = strcmp(wk_strg, gw_variable[v].gv_name);
																if(ret == 0)
																	{				
																		x4 = 1;
																		x5 = gw_variable[v].gv_lgth;
																		gw_variable[v].gv_use_ct++;
																	}
															}
													}
											}

										snprintf(wk_strg, sizeof(wk_strg), "%d", x5);

										strcpy(a_string, "         MVC   0(");
										strcat(a_string, wk_strg);
										strcat(a_string, ",R8),0(R9)");
										strcpy(wk_remark, " printf   */");
										write_remark();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #24");
												trace_rec_3();
											}
										break;
									}
							}
	
						strcpy(a_string, "         BRASL C370PRTR,WTOIMVC");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #28");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370WTOB");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #29");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R8,C370L10");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #30");
								trace_rec_3();
							}
						work_use_ct[71]++;

						strcpy(a_string, "         MVC   ");
						snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
						strcat(a_string, wk_strg);
						strcat(a_string, "(10,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #31");
								trace_rec_3();
							}

						strcpy(a_string, "         BRASL C370PRTR,WTOALPHA");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_print_numeric Struct #32");
								trace_rec_3();
							}
						tot_wto++;
					}
			}
	}


void c2_printf_string()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_print.c c2_printf_string");
				trace_rec_1();
			}

		char ch;
		char *p6, *p7, *p8;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field1b[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field4[VAR_LGTH];
		char field5[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field8[VAR_LGTH];
		char field9[VAR_LGTH];
		char field10[VAR_LGTH];
		char field11[VAR_LGTH];
		char field11a[VAR_LGTH];
		char field12[VAR_LGTH];

		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];
		char tfield22[VAR_LGTH];
		char tfield22a[VAR_LGTH];

		int pi;
		int pi2;
		int x1 = 0;
 		int x2 = 0;
 		int x3 = 0;
		int x5 = 0;
		int x9 = 0;
		int x11 = 0;
		int x95 = 0;
		int v = 0;
		int prf1 = 0;
		int prf3 = 0;
		int pf1 = 0;
		int I = 0;
		int ret = 0;
		int ret1 = 0;
		int xc = 0;
		
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
						field2[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		field2[pi2] = '\0';

		strcpy(field1,"L");
		snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
		strcat(field1, wk_strg);
		x3 = 0;
		for(x3 = 0; x3 < v_const; x3++)
			{
				ret = strcmp(field1, w_constant[x3].const_current);
				if(ret == 0)
					{
						strcpy(field1, w_constant[x3].const_use);
						break;
					}
			}

		x5 = 0;
		for(I=0; I < lv_ct; I++)
			{
				ret = strcmp(field1, lw_variable[I].lv_name);									
				ret1 = strcmp(sv_func, lw_variable[I].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						x5 = 1;
						x1 = lw_variable[I].lv_lgth;
						lw_variable[I].lv_use_ct++;
					}
			}

		if(x5 == 0)
			{
				for(I=0; I < gv_ct; I++)
					{
						ret = strcmp(field1,gw_variable[I].gv_name);
						if(ret == 0)
							{
								x5 = 1;
								x1 = gw_variable[I].gv_lgth;
								gw_variable[I].gv_use_ct++;
							}
					}
			}
	
		strcpy(a_string, "         LARL  R9,C370WTOB");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_print.c c2_printf_string #1");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,");
		strcat(a_string, w_constant[x3].const_use);
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_print.c c2_printf_string #2");
				trace_rec_3();
			}

		strcpy(a_string, "         MVC   ");
		strcat(a_string, "0(");
		snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
		strcat(a_string, wk_strg);
		strcat(a_string, ",R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_print.c c2_printf_string #3");
				trace_rec_3();
			}
			
		p6 = strstr(p_string, "[");
		p7 = strstr(p_string, "]");
		p8 = strstr(p_string, ".");

		if((!p6) && (!p7) && (!p8))		
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_string NO []");
						trace_rec_1();
					}

/*
printf("c2z_print.c field1 = %s\n",field1);
printf("c2z_print.c field2 = %s\n",field2);
printf("c2z_print.c sv_func = %s\n",sv_func);
printf("c2z_print.c lv_ct = %d\n",lv_ct);
printf("c2z_print.c I = %d\n",I);
*/

				x9 = 0;
				pf1 = 0;
				for(I=0; I < lv_ct; I++)
					{
printf("lv_name = %s\n",lw_variable[I].lv_name);
						ret = strcmp(field2, lw_variable[I].lv_name);									
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								pf1 = 1;
								strcpy(field2a, lw_variable[I].lv_cname);
								lw_variable[I].lv_use_ct++;
								x9 = lw_variable[I].lv_current_lgth;
								x11 = lw_variable[I].lv_lgth;
								break;
							}
					}
					
				if(pf1 == 0)
					{
						for(I=0; I <= gv_ct; I++)
							{
								ret = strcmp(field2,gw_variable[I].gv_name);
								if(ret == 0)
									{
										pf1 = 1;
										strcpy(field2a, gw_variable[I].gv_cname);
										gw_variable[I].gv_use_ct++;
										x9 = gw_variable[I].gv_current_lgth;
										x11 = gw_variable[I].gv_lgth;
									}
							}
					}

printf("c2z_print.c field2a = %s\n",field2a);

				if(pf1 == 0)
					{
						printf("c2z_print.c c2_printf NO [] E-289 Missing field after format statement\n");
						c2_error();
					}

				if(x9 == 0)
					{
						x9 = x11;
					}
				
				strcpy(a_string, "         LARL  R9,C370WTOB");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_string NO [] #1");
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
						strcpy(trace_1, "c2z_print.c c2_printf_string NO [] #2");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
				strcat(a_string, wk_strg);
				strcat(a_string, "(");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x11);
				strcat(a_string, wk_strg);
				strcat(a_string, ",R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_string NO [] #3");
						trace_rec_3();
					}

				strcpy(a_string, "         BRASL C370PRTR,WTOALPHA");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_string NO [] #4");
						trace_rec_3();
					}

				tot_wto++;
			}

		if((p6) && (p7) && (!p8))
			{		
				pi = 0;
				while(ch != '"')		
					{
						pi++;
						ch = p_string[pi];
					} 
									
				pi++;
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
						if(ch == ',')
							{
								x2 = 1;
							}
						if(x2 == 0)
							{
								if(ch != ' ')
									{
										field1[pi2] = ch;
										pi2++;
									}
							}
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

				p6 = strstr(field1, "[");
				p7 = strstr(field1, "]");
										
				prt_array = 0;
				
				if((p6) && (p7))		
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf_string []");
								trace_rec_1();
							}

						pi2 = 0;
						ch = field1[prf1];
						while(ch != '[')
							{
								field1a[pi2] = ch;
								pi2++;
								prf1++;
								ch = field1[prf1];
							}
						field1a[pi2] = '\0';

						pi2 = 0;
                        			prf1++;
						ch = field1[prf1];
						while(ch != ']')
							{
								tfield22[pi2] = ch;
								pi2++;
								prf1++;
								ch = field1[prf1];
							}
						tfield22[pi2] = '\0';

						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(field1a, gw_variable[I].gv_name);
										if(ret == 0)
											{
												strcpy(field1b, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												strcpy(field4, gw_variable[I].gv_type);
											}
									}
							}

						ret = strcmp(field4, "A");
						if(ret == 0)				
							{
								if(gv_ct > 0)
									{
										for(I = 0; I < gv_ct; I++)
											{
												ret = strcmp(field1b, gw_variable[I].gv_cname);
												if(ret == 0)
													{
														strcpy(field5,gw_variable[I].gv_dsect);
														strcpy(field6,gw_variable[I].gv_label);
														strcpy(field7,gw_variable[I].gv_table);
														strcpy(field8,gw_variable[I].gv_aname);
														strcpy(field9,gw_variable[I].gv_sv_reg);
														strcpy(field10,gw_variable[I].gv_wk_reg);
														strcpy(field11,gw_variable[I].gv_wk_strg);
														xc = gw_variable[I].gv_column;
														gw_variable[I].gv_flag = 1;
													}
											}
									}

								prf3 = 0;
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(field11, lw_variable[v].lv_name);
										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												prf3 = 1;
												strcpy(field11a, lw_variable[v].lv_cname);
											       x9 = lw_variable[v].lv_lgth;
											}
									}

								prf3 = 0;
								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(field11, gw_variable[v].gv_name);
										if(ret == 0)
											{
												prf3 = 1;
												strcpy(field11a, gw_variable[v].gv_cname);
												x9 = gw_variable[v].gv_lgth;
											}
									}

								strcpy(a_string, "         LARL  R9,C370LPCT");
								src_line();
								var_use[1]++;
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #1");
										trace_rec_3();
									}
								work_use_ct[73]++;

								strcpy(a_string, "         LARL  R8,C370ZERO");								
								src_line();
								var_use[1]++;
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #2");
										trace_rec_3();
									}
	
								strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
								src_line();
								var_use[1]++;
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #3");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370LPCT");
								src_line();
								var_use[1]++;
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #4");
										trace_rec_3();
									}
								work_use_ct[73]++;

								strcpy(a_string, "         LARL  R8,C370ONE");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #5");
										trace_rec_3();
									}
	
								strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #6");
										trace_rec_3();
									}
								
								strcpy(a_string, "         LARL  R6,");
								strcat(a_string, field7);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #7");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370NWK1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #8");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370ZERO");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #9");
										trace_rec_3();
									}

								strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
								src_line();
								var_use[1]++;
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #10");
										trace_rec_3();
									}

								strcpy(a_string, "PR");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, wk_strg);
								strcat(a_string, "A");
								check_length();
								strcat(a_string, "DS    0H");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #11");
										trace_rec_3();
									}

								prf3 = 0;
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(tfield22, lw_variable[v].lv_name);
										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												prf3 = 1;
												strcpy(tfield22a, lw_variable[v].lv_cname);
											       x9 = lw_variable[v].lv_lgth;
											}
									}

								prf3 = 0;
								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(tfield22, gw_variable[v].gv_name);
										if(ret == 0)
											{
												prf3 = 1;
												strcpy(tfield22a, gw_variable[v].gv_cname);
												x9 = gw_variable[v].gv_lgth;
											}
									}

								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, tfield22a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, tfield22);
								strcat(wk_remark, " */");
								write_remark();
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #12");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370NWK1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #13");
										trace_rec_3();
									}

								strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #14");
										trace_rec_3();
									}

								strcpy(a_string, "         JLE   PR");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, wk_strg);
								strcat(a_string, "E");
								src_line();
								var_use[1]++;
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #15");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370NWK1");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #16");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370ONE");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #17");
										trace_rec_3();
									}

								strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #18");
										trace_rec_3();
									}

								strcpy(a_string,"         LA    R6,");
								strcat(a_string,field6);
								strcat(a_string, "(R0,R6)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #19");
										trace_rec_3();
									}

								strcpy(a_string, "         JLU   PR");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, wk_strg);
								strcat(a_string, "A");
								src_line();
								var_use[1]++;
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #20");
										trace_rec_3();
									}

								strcpy(a_string, "PR");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(a_string, wk_strg);
								strcat(a_string, "E");
								check_length();
								strcat(a_string, "DS    0H");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #21");
										trace_rec_3();
									}

								strcpy(print_array_name, field10);
								strcpy(print_array_table, field7);

								if(gv_ct > 0)
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(field12, gw_variable[I].gv_name);
											}
									}
					
								strcpy(a_string, "         LARL  R9,C370WTOB");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #22");
										trace_rec_3();
									}
								
								strcpy(a_string, "         MVC   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
								strcat(a_string, wk_strg);
								strcat(a_string, "(");
								snprintf(wk_strg, sizeof(wk_strg), "%d", xc);
								strcat(a_string, wk_strg);
								strcat(a_string, ",R9),0(R6)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #23");
										trace_rec_3();
									}
							
								strcpy(a_string, "         BRASL C370PRTR,WTOALPHA");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_string [] #24");
										trace_rec_3();
									}

								prt_array = 1;
								tot_wto++;
							}
			
						ret = strcmp(field4, "C");
						if(ret == 0)				
							{
								printf("c2z_print.c c2_print E-280 string charater processing\n");
								c2_error();
							}
					}
				return;
			}
	

		if((p6) && (p7) && (p8))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_string.c c2_printf_string Structure");
						trace_rec_1();
					}

				char tfield6a[VAR_LGTH];
				
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
						if(ch != '.')
							{
								tfield3[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				tfield3[pi2] = '\0';

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
						printf("c2z_printf.c c2_printf_string Structure E-281 tfield1 Not Found = %s\n",tfield1);
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
						printf("c2z_printf.c c2_printf_string Structure E-282 tfield2 Not Found = %s\n",tfield2);
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
								x9 = w_struc[I].st_field_lgth;
								x95 = w_struc[I].st_disp;
							}
					}

				if(x3 == 0)
					{
						printf("c2z_printf.c c2_printf_string Structure E-283 tfield1 Not Found = %s\n",tfield1);
						c2_error();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #1");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #2");
 						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #3");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R6,");
                            strcat(a_string, tfield1a);
				strcat(a_string, "T");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #4");
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
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #5");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #6");
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
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #7");
 						trace_rec_3();
					}
				
				strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #8");
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
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #9");
 						trace_rec_3();
					}

				strcpy(a_string, "         LA    R6,");
				strcat(a_string, tfield6a);
				strcat(a_string, "L");
				strcat(a_string, "(R0,R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #10");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #11");
 						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #12");
 						trace_rec_3();
					}
				
				strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #13");
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
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #14");
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
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #15");
 						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370WTOB");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #18");
						trace_rec_3();
					}

				strcpy(a_string, "         MVC   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
				strcat(a_string, wk_strg);
				strcat(a_string, "(");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
				strcat(a_string, wk_strg);
				strcat(a_string, ",R9),");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x95);
				strcat(a_string, wk_strg);
				strcat(a_string, "(R6)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #20");
						trace_rec_3();
					}

				strcpy(a_string, "         BRASL C370PRTR,WTOALPHA");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_printf.c c2_printf_string Struc #21");
						trace_rec_3();
					}
			}			
	}


void c2_snprintf(void)
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_print.c c2_snprintf");
				trace_rec_1();
			}

		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield3[VAR_LGTH];
		char tfield3a[VAR_LGTH];

		int pi;
		int pi2;
		int v;
		int ret;
		int ret1;
		int x3;
		
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
		while(ch != ',')
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
		
		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch !=  ')')
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

		x3 = 0;
		for(v = 0; v < lv_ct; v++)
			{
				ret = strcmp(tfield1, lw_variable[v].lv_name);
				ret1 = strcmp(sv_func, lw_variable[v].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						x3 = 1;
						strcpy(tfield1a, lw_variable[v].lv_cname);
					}
			}
			
		if(x3 == 0)
			{
				for(v = 0; v < gv_ct; v++)
					{
						ret = strcmp(tfield1, gw_variable[v].gv_name);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(tfield1a, gw_variable[v].gv_cname);
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_print.c c2_snprintf E-284 tfield1 Not Found = %s\n",tfield1);
				c2_error();
			}

		x3 = 0;
		for(v = 0; v < lv_ct; v++)
			{
				ret = strcmp(tfield3, lw_variable[v].lv_name);
				ret1 = strcmp(sv_func, lw_variable[v].lv_func);
				if((ret == 0) && (ret1 == 0))
					{
						x3 = 1;
						strcpy(tfield3a, lw_variable[v].lv_cname);
					}
			}
			
		if(x3 == 0)
			{
				for(v = 0; v < gv_ct; v++)
					{
						ret = strcmp(tfield3, gw_variable[v].gv_name);
						if(ret == 0)
							{
								x3 = 1;
								strcpy(tfield3a, gw_variable[v].gv_cname);
							}
					}
			}

		if(x3 == 0)
			{
				printf("c2z_print.c c2_snprintf E-285 tfield3 Not Found = %s\n",tfield3);
				c2_error();
			}

	       strcpy(a_string, "         LARL  R9,C370EDN");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_printf.c c2z_print.c c2_snprintf #1");
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
				strcpy(trace_1, "c2z_printf.c c2z_print.c c2_snprintf #2");
				trace_rec_3();
			}

		strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_printf.c c2z_print.c c2_snprintf #3");
				trace_rec_3();
			}

		strcpy(a_string, "        BRASL C370PRTR,WTOIMVC");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_printf.c c2z_print.c c2_snprintf #4");
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
				strcpy(trace_1, "c2z_printf.c c2z_print.c c2_snprintf #5");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370L8");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_printf.c c2z_print.c c2_snprintf #6");
				trace_rec_3();
			}

		strcpy(a_string, "         MVC  0(8,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_printf.c c2z_print.c c2_snprintf #7");
				trace_rec_3();
			}
	}


void c2_printf_dec_only(int dec)
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_print.c c2_printf_dec_only");
				trace_rec_1();
			}

		char ch;
		char *p5, *p6;
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field4[VAR_LGTH];
		char field4a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field7a[VAR_LGTH];
		char field8[VAR_LGTH];
		char field9[VAR_LGTH];
		char field10[VAR_LGTH];
		char field11[VAR_LGTH];
		char field11a[VAR_LGTH];
		char field12[VAR_LGTH];

		int pi;
		int pi2;
		int x3 = 0;
		int x4 = 0;
		int x5 = 0;
              int x15 = 0;
		int v = 0;
		int prf1 = 0;
		int prf2 = 0;
		int prf5 = 0;
		int prf6 = 0;
		int prf7 = 0;
		int prf10 = 0;
		int I = 0;
		int ret = 0;
		int ret1 = 0;
		
		int fd1_define = 0;

		pi = 0;
		ch = p_string[pi];
		while(ch != '"')
			{
				pi++;
				ch = p_string[pi];
			} 

		prf1 = pi;		
		pi = 0;
		ch = p_string[pi];
		while(ch != '%')
			{
				pi++;
				ch = p_string[pi];
			} 
			
		prf2 = pi;		
											
		if (prf1 < prf2)		/* means literal comes first */
			{
				pi = 0;
				while(ch != '"')		/* 1st " */
					{
						pi++;
						ch = p_string[pi];
					} 
								
				pi++;
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

				
				prf6 = 0;
				p5 = strchr(field2, '[');
				p6 = strchr(field2, ']');
				if((p5) && (p6))	/* array printing		*/
					{
						prf6 = 1;		
					}

				if(prf6 == 1)		/* array processing		*/
					{
						if(trace_flag == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY ");
								trace_rec_1();
							}

						strcpy(field12,field1);

						if(z390 == 1)
							{
								strcpy(field11,"L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(field11, wk_strg);

								for(x3 = 0; x3 < v_const; x3++)
									{
										ret = strcmp(field11, w_constant[x3].const_current);
										if(ret == 0)
											{
												strcpy(a_string, "         LARL  R9,C370WTOB");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #1");
														trace_rec_3();
													}

												strcpy(a_string, "         LARL  R8,");
												strcat(a_string, w_constant[x3].const_use);
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #2");
														trace_rec_3();
													}

												strcpy(field11, w_constant[x3].const_use);

												x3 = 0;
												for(I=0; I < lv_ct; I++)
													{
														ret = strcmp(field11, lw_variable[I].lv_name);
														ret1 = strcmp(sv_func, lw_variable[I].lv_func);
														if((ret == 0) && (ret1 == 0))
															{
																x3 = 1;
																x15 = lw_variable[I].lv_lgth;
															}
													}

												if(x3 == 0)
													{
														for(I=0; I < gv_ct; I++)
															{
																ret = strcmp(field11, gw_variable[I].gv_name);
																if(ret == 0)
																	{
																		x3 = 1;
																		x15 = gw_variable[I].gv_lgth;   
																	}
															}
													}

												strcpy(a_string, "         MVC   ");
												strcat(a_string, "0(");
												snprintf(wk_strg, sizeof(wk_strg), "%d", x15);
												strcat(a_string, wk_strg);
												strcat(a_string, ",R9),0(R8)");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #3");
														trace_rec_3();
													}

												break;
											}
									}

								x3 = 0;	
								x4 = 0;
									
								strcpy(field7, wk_strg);
								for(I=0; I < lv_ct; I++)
									{
										ret = strcmp(field7, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												x3 = 1;
												x4 = lw_variable[I].lv_lgth;
											}
									}

								if(x3 == 0)
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(field7, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x4 = gw_variable[I].gv_lgth;   
													}
											}
									}

							}	

						pi2 = 0;
						prf7 = 0;
						ch = field2[prf7];
						while(ch != '[')
							{
								field4[pi2] = ch;
								pi2++;
								prf7++;
								ch = field2[prf7];
							}
						field4[prf7] = '\0';

						prf10 = 0;
						for(I=0; I < lv_ct; I++)
							{
								prf5 = strcmp(field4, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((prf5 == 0) && (ret1 == 0))	
									{
										prf10 = 1;
										strcpy(field4a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
									}
							}

						if(prf10 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										prf5 = strcmp(field4, gw_variable[I].gv_name);
										if(prf5 == 0)
											{
												prf10 = 1;
												strcpy(field4a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
											}
									}
							}

						if(prf10 == 0)
							{
								printf("c2z_print.c c2_printf_dec_only E-142 field4 Not Found = %s\n",field4);
								c2_error();
							}

						pi2 = 0;
						prf7++;
						ch = field2[prf7];
						while(ch != ']') 
							{
								field7[pi2] = ch;
								pi2++;
								prf7++;
								ch = field2[prf7];
							}
						field7[pi2] = '\0';

						prf10 = 0;
						for(I=0; I < lv_ct; I++)
							{
								prf5 = strcmp(field7, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((prf5 == 0) && (ret1 == 0))
									{
										prf10 = 1;
										strcpy(field7a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
									}
							}

						if(prf10 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										prf5 = strcmp(field7, gw_variable[I].gv_name);
										if(prf5 == 0)
											{
												prf10 = 1;
												strcpy(field7a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
											}
									}
							}

						if(prf10 == 0)
							{
								printf("c2z_print.c c2_printf_dec_only E-141 field7 Not Found = %s\n",field7);
								c2_error();
							}

						if(gv_ct > 0)
							{
								for(I = 0; I < gv_ct; I++)
									{
										ret = strcmp(field4a, gw_variable[I].gv_cname);
										if(ret == 0)
											{
												strcpy(field5,gw_variable[I].gv_dsect);
												strcpy(field6,gw_variable[I].gv_label);
												strcpy(field7,gw_variable[I].gv_table);
												strcpy(field8,gw_variable[I].gv_aname);
												strcpy(field9,gw_variable[I].gv_sv_reg);
												strcpy(field10,gw_variable[I].gv_wk_reg);
												strcpy(field11,gw_variable[I].gv_wk_strg);
												gw_variable[I].gv_flag = 1;
											}
									}
							}

						strcpy(field12,field4);

						prf2 = 0;
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field11, lw_variable[v].lv_name);
								if(ret == 0)
									{
										strcpy(field11a, lw_variable[v].lv_cname);
									}
							}

						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field11, gw_variable[v].gv_name);
								if(ret == 0)
									{
										strcpy(field11a, gw_variable[v].gv_cname);
									}
							}

						strcpy(a_string, "         LARL  R9,C370LPCT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #4");
								trace_rec_3();
							}
						work_use_ct[73]++;

						strcpy(a_string, "         LARL  R8,C370ZERO");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #5");
								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         CP    0(6,R9),0(2,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #6");
								trace_rec_3();
							}

						strcpy(a_string, "         JLNE  ");
						strcat(a_string, "PR");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "L");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #7");
								trace_rec_3();
							}
						
						strcpy(a_string, "         LARL  R6,");
						strcat(a_string, field7);
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #10");
								trace_rec_3();
							}

						strcpy(field2, field12);
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
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #11");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370LPCT");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #12 ");
								trace_rec_3();
							}
						work_use_ct[73]++;

						strcpy(a_string, "         LARL  R8,C370ONE");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #13 ");
								trace_rec_3();
							}
						work_use_ct[32]++;

						strcpy(a_string, "         AP    0(6,R9),0(2,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #14 ");
								trace_rec_3();
							}

						strcpy(a_string, "PR");
						snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
						strcat(a_string, wk_strg);
						strcat(a_string, "L");
						check_length();
						strcat(a_string, "DS    0H");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #15 ");
								trace_rec_3();
							}
	
						strcpy(a_string, "         LARL  R9,C370NWK2");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #16 ");
								trace_rec_3();
							}
						work_use_ct[50]++;
						
						strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #17 ");
								trace_rec_3();
							}

						strcpy(a_string, "         LA     R6,");
						strcat(a_string, field6);
                                          strcat(a_string, "(R0,R6)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #18 ");
								trace_rec_3();
							}
													
						strcpy(print_array_name, field10);
						strcpy(print_array_table, field7);

						strcpy(a_string, "         LARL  R9,C370EDN");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #20 ");
								trace_rec_3();
							}
						work_use_ct[51]++;

						strcpy(a_string, "         LARL  R8,C370NWK2");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #21 ");
								trace_rec_3();
							}
						work_use_ct[50]++;

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #22 ");
								trace_rec_3();
							}

						strcpy(a_string, "         BRASL C370PRTR,WTOIMVC");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #23 ");
								trace_rec_3();
							}

						strcpy(a_string, "         LARL  R9,C370WTOB");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #24 ");
								trace_rec_3();
							}
						
						strcpy(a_string, "         LARL  R8,C370L8");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #25 ");
								trace_rec_3();
							}
						work_use_ct[9]++;

						if(gv_ct > 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										ret = strcmp(field1,gw_variable[I].gv_name);
										if(ret == 0)
											{
												x4 = gw_variable[I].gv_lgth;   
											}
									}
							}

						strcpy(a_string, "         MVC   ");
						snprintf(wk_strg, sizeof(wk_strg), "%d", x15);
						strcat(a_string, wk_strg);
						strcat(a_string, "(8,R9),0(R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #26 ");
								trace_rec_3();
							}

						strcpy(a_string, "         BRASL C370PRTR,WTOALPHA");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #27 ");
								trace_rec_3();
							}
						
						prt_array = 1;
						tot_wto++;

					}

				if(prf6 == 0)
					{
						prf10 = 0;
						for(I=0; I < lv_ct; I++)
							{
								ret = strcmp(field2, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										prf10 = 1;
										strcpy(field2a, lw_variable[I].lv_cname);
										lw_variable[I].lv_use_ct++;
										fd1_define = lw_variable[I].lv_id;
										break;
									}
							}

						if(prf10 == 0)
							{
								for(I=0; I < gv_ct; I++)
									{
										prf5 = strcmp(field2, gw_variable[I].gv_name);
										if(prf5 == 0)
											{
												prf10 = 1;
												strcpy(field2a, gw_variable[I].gv_cname);
												gw_variable[I].gv_use_ct++;
												fd1_define = gw_variable[I].gv_id;
												break;
											}
									}
							}

						if(prf10 == 0)
							{
								printf("c2z_print.c c2_printf E-140 field2 Not Found = %s\n",field2);
								c2_error();
							}

						if(fd1_define == 1)		/* Integer	*/
							{
								strcpy(field1,"L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(field1, wk_strg);

								for(x3 = 0; x3 < v_const; x3++)
									{
										ret = strcmp(field1, w_constant[x3].const_current);
										if(ret == 0)
											{
												strcpy(a_string, "         LARL  R9,");
												strcat(a_string, w_constant[x3].const_use);

												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_print.c c2_printf %d  #1");
														trace_rec_3();
													}

												strcpy(a_string, "         LARL  R8,C370WTOB");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #2");
														trace_rec_3();
													}

												strcpy(wk_strg, w_constant[x3].const_use);

												x4 = 0;
												if(lv_ct > 0)
													{
														for(v = 0; v < lv_ct; v++)
															{
																ret = strcmp(wk_strg, lw_variable[v].lv_name);
																ret1 = strcmp(sv_func, lw_variable[v].lv_func);
																if((ret == 0) && (ret1 == 0))
																	{				
																		x4 = 1;
																		x5 = lw_variable[v].lv_lgth;
																		lw_variable[I].lv_use_ct++;
																	}
															}
													}

												strcpy(wk_strg, w_constant[x3].const_use);

												if(x4 == 0)
													{
														if(gv_ct > 0)
															{
																for(v = 0; v < gv_ct; v++)
																	{
																		ret = strcmp(wk_strg, gw_variable[v].gv_name);
																		if(ret == 0)
																			{				
																				x4 = 1;
																				x5 = gw_variable[v].gv_lgth;
																				gw_variable[I].gv_use_ct++;
																			}
																	}
															}
													}

												snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
												strcpy(a_string, "         MVC   0(");
												strcat(a_string, wk_strg);
												strcat(a_string, ",R8),0(R9)");
												strcpy(wk_remark, " printf   */");
												write_remark();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #3");
														trace_rec_3();
													}
												break;
											}
									}

								strcpy(a_string, "         LARL  R9,C370DEC");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #4");
										trace_rec_3();
									}
								work_use_ct[67]++;

								if(dec == 1)
									{
										strcpy(a_string, "         LARL  R8,C370ONE");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #5");
												trace_rec_3();
											}
									}

								if(dec == 2)
									{
										strcpy(a_string, "         LARL  R8,C370TWO");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #6");
												trace_rec_3();
											}
									}

								if(dec == 3)
									{
										strcpy(a_string, "         LARL  R8,C370THR");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #7");
												trace_rec_3();
											}
									}

								if(dec == 4)
									{
										strcpy(a_string, "         LARL  R8,C370FOUR");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #8");
												trace_rec_3();
											}
									}

								if(dec == 5)
									{
										strcpy(a_string, "         LARL  R8,C370FIVE");
										src_line();
										if(punch_code == 1)
											{
												strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #9");
												trace_rec_3();
											}
									}

								strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #10");
										trace_rec_3();
									}

								x3 = 0;	
                                                        strcpy(sv_print_lit,"L");
								strcat(sv_print_lit,wk_strg);

								x3 = 0;
								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(field2, gw_variable[v].gv_name);
										if(ret == 0)
											{
												x3 = 1;
												strcpy(field2a, gw_variable[v].gv_cname);
											}
									}

								if(x3 == 0)		/* lookup in local variable	*/
									{
										for(v = 0; v < lv_ct; v++)
											{
												ret = strcmp(field2, lw_variable[v].lv_name);
												ret1 = strcmp(sv_func, lw_variable[v].lv_func);
												if((ret == 0)  && (ret1 == 0))
													{
														x3 = 1;
														strcpy(field2a, lw_variable[v].lv_cname);
														lw_variable[v].lv_use_ct++;
													}
											}
									}

								x4 = 0;
								if(gv_ct > 0)
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(sv_print_lit, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x4 = gw_variable[I].gv_lgth;   
													}
											}
									}
								
								strcpy(a_string, "         LARL  R9,C370EDN");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #11");
										trace_rec_3();
									}
								work_use_ct[51]++;

								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field2a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, field2);
								strcat(wk_remark, " */ ");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #12");
										trace_rec_3();
									}

								strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #13");
										trace_rec_3();
									}

								strcpy(a_string, "         BRASL C370PRTR,WTOIMVC");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #14");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370WTOB");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #15");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370L10");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #16");
										trace_rec_3();
									}
								work_use_ct[71]++;

								strcpy(a_string, "         MVC   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
								strcat(a_string, wk_strg);
								strcat(a_string, "(10,R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #17");
										trace_rec_3();
									}

								strcpy(a_string, "         BRASL C370PRTR,WTOALPHA");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #18");
										trace_rec_3();
									}
								
								tot_wto++;
							}

						if((z390 == 1) && (fd1_define == 2))		/* Double	*/
							{
								strcpy(field1,"L");
								snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
								strcat(field1, wk_strg);

								for(x3 = 0; x3 < v_const; x3++)
									{
										ret = strcmp(field1, w_constant[x3].const_current);
										if(ret == 0)
											{
												strcpy(a_string, "         LARL  R9,");
												strcat(a_string, w_constant[x3].const_use);
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_print.c c2_printf %d Double #143");
														trace_rec_3();
													}

												strcpy(a_string, "         LARL  R8,C370WTOB");
												src_line();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_print.c c2_printf %d Double #144");
														trace_rec_3();
													}

												strcpy(wk_strg, w_constant[x3].const_use);

												x4 = 0;
												if(lv_ct > 0)
													{
														for(v = 0; v < lv_ct; v++)
															{
																ret = strcmp(wk_strg, lw_variable[v].lv_name);
																ret1 = strcmp(sv_func, lw_variable[v].lv_func);
																if((ret == 0) && (ret1 == 0))
																	{				
																		x4 = 1;
																		x5 = lw_variable[v].lv_lgth;
																		lw_variable[I].lv_use_ct++;
																	}

															}
													}

												strcpy(wk_strg, w_constant[x3].const_use);

												if(x4 == 0)
													{
														if(gv_ct > 0)
															{
																for(v = 0; v < gv_ct; v++)
																	{
																		ret = strcmp(wk_strg, gw_variable[v].gv_name);
																		if(ret == 0)
																			{				
																				x4 = 1;
																				x5 = gw_variable[v].gv_lgth;
																				gw_variable[I].gv_use_ct++;
																			}
																	}
															}
													}

												snprintf(wk_strg, sizeof(wk_strg), "%d", x5);

												strcpy(a_string, "         MVC   0(");
												strcat(a_string, wk_strg);
												strcat(a_string, ",R8),0(R9)");
												strcpy(wk_remark, " printf   */");
												write_remark();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_print.c c2_printf %d Double #145");
														trace_rec_3();
													}
												break;
											}
									}

								x3 = 0;	
                                                        strcpy(sv_print_lit,"L");
								strcat(sv_print_lit,wk_strg);

								x3 = 0;
								for(v = 0; v < gv_ct; v++)
									{
										ret = strcmp(field2, gw_variable[v].gv_name);
										if(ret == 0)
											{
												x3 = 1;
												strcpy(field2a, gw_variable[v].gv_cname);
											}
									}

								if(x3 == 0)		
									{
										for(v = 0; v < lv_ct; v++)
											{
												ret = strcmp(field2, lw_variable[v].lv_name);
												ret1 = strcmp(sv_func, lw_variable[v].lv_func);
												if((ret == 0)  && (ret1 == 0))
													{
														x3 = 1;
														strcpy(field2a, lw_variable[v].lv_cname);
														lw_variable[v].lv_use_ct++;
													}
											}
									}

								x4 = 0;
								if(gv_ct > 0)
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(sv_print_lit, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x4 = gw_variable[I].gv_lgth;   
													}
											}
									}

								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, field2a);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Double #146");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370U");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Double #147");
										trace_rec_3();
									}
								work_use_ct[48]++;

								strcpy(a_string, "         CVD   R9,0(4,R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Double #148");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370TDW4");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Double #149");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R7,C370EDW4");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Double #150");
										trace_rec_3();
									}

								strcpy(a_string, "         MVC    0(4,R8),0(R7)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Double #151");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370TDW4");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Double #152");
										trace_rec_3();
									}

								strcpy(a_string, "        ED     0(4,R8),4(R9)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Double #153");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R9,C370WTOB");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Double #154");
										trace_rec_3();
									}

								strcpy(a_string, "         LARL  R8,C370TDW4");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Double #155");
										trace_rec_3();
									}
								work_use_ct[56]++;

								strcpy(a_string, "         MVC   ");
								snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
								strcat(a_string, wk_strg);
								strcat(a_string, "(10,R9),0(R8)");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Double #156");
										trace_rec_3();
									}

								strcpy(a_string, "         BRASL C370PRTR,WTOALPHA");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf %d Double #157");
										trace_rec_3();
									}
								
								tot_wto++;
							}
					}
			}
	}

void c2_printf_float()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_print.c c2_printf_float");
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field12[VAR_LGTH];
		
		int pi;
		int pi2;
		int prf1 = 0;
		int prf2 = 0;
		int ret = 0;
		int ret1 = 0;
		int I = 0;
		int x3 = 0;
		int x4 = 0;
		int x5 = 0;
		int v = 0;
			
		pi = 0;
		ch = p_string[pi];
		while(ch != '"')
			{
				pi++;
				ch = p_string[pi];
			} 

		prf1 = pi;		
		pi = 0;
		ch = p_string[pi];
		while(ch != '%')
			{
				pi++;
				ch = p_string[pi];
			} 
			
		prf2 = pi;		
		if (prf1 < prf2)		
			{
				pi = 0;
				while(ch != '"')		
					{
						pi++;
						ch = p_string[pi];
					} 
								
				pi++;
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
								break;
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
												break;
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_print.c c2_printf E-200 Integer field2 Not Found = %s\n",field2);
								c2_error();
							}
					}

				strcpy(a_string, "         LARL  R9,C370DEC");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_float #1");
						trace_rec_3();
					}
				work_use_ct[67]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_float #2");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_float #3");
						trace_rec_3();
					}
								
				strcpy(field1,"L");
				snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
				strcat(field1, wk_strg);

				for(x3 = 0; x3 < v_const; x3++)
					{
						ret = strcmp(field1, w_constant[x3].const_current);
						if(ret == 0)
							{
								strcpy(a_string, "         LARL  R9,");
								strcat(a_string, w_constant[x3].const_use);
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_float #4");
										trace_rec_3();
									}

								strcpy(field12, w_constant[x3].const_use);

								strcpy(a_string, "         LARL  R8,C370WTOB");
								src_line();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_float #5");
										trace_rec_3();
									}

								strcpy(wk_strg, w_constant[x3].const_use);

								x4 = 0;
								if(lv_ct > 0)
									{
										for(v = 0; v < lv_ct; v++)
											{
												ret = strcmp(wk_strg, lw_variable[v].lv_name);
												ret1 = strcmp(sv_func, lw_variable[v].lv_func);
												if((ret == 0) && (ret1 == 0))
													{				
														x4 = 1;
														x5 = lw_variable[v].lv_lgth;
														lw_variable[I].lv_use_ct++;
													}
											}
									}

								strcpy(wk_strg, w_constant[x3].const_use);
								if(x4 == 0)
									{
										if(gv_ct > 0)
											{
												for(v = 0; v < gv_ct; v++)
													{
														ret = strcmp(wk_strg, gw_variable[v].gv_name);
														if(ret == 0)
															{				
																x4 = 1;
																x5 = gw_variable[v].gv_lgth;
																gw_variable[v].gv_use_ct++;
															}
													}
											}
									}

								snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
								strcpy(a_string, "         MVC   0(");
								strcat(a_string, wk_strg);
								strcat(a_string, ",R8),0(R9)");
								strcpy(wk_remark, " printf   */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_print.c c2_printf_float #6");
										trace_rec_3();
									}
								break;
							}
					}

				x3 = 0;	
                            strcpy(sv_print_lit,"L");
				strcat(sv_print_lit,wk_strg);

				x3 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field2, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0)  && (ret1 == 0))
							{
								x3 = 1;
								strcpy(field2a, lw_variable[v].lv_cname);
								lw_variable[v].lv_use_ct++;
							}
					}
					
				if(x3 == 0)		
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field2, gw_variable[v].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(field2a, gw_variable[v].gv_cname);
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_print.c c2_printf_float E-201 field2 Not Found = %s\n",field2);
						c2_error();
					}

				x4 = 0;
				if(gv_ct > 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(sv_print_lit, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x4 = gw_variable[I].gv_lgth;   
									}
							}
					}
					
				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field2a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, field2);
				strcat(wk_remark, " */ ");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_float #7");
						trace_rec_3();
					}

				strcpy(a_string, "         L     R9,0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_float #8");
						trace_rec_3();
					}

				strcpy(a_string, "         BRASL C370PRTR,WTOFMVC");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_float #9");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370WTOB");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_float #10");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370L10");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_float #11");
						trace_rec_3();
					}
				work_use_ct[71]++;

				strcpy(a_string, "         MVC   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
				strcat(a_string, wk_strg);
				strcat(a_string, "(10,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_float #12");
						trace_rec_3();
					}

				strcpy(a_string, "         BRASL C370PRTR,WTOALPHA");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_print.c c2_printf_float #13");
						trace_rec_3();
					}
								
				tot_wto++;
			}
	}



