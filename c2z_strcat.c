/* ***************************************************
*  c2z : c2z_strcat.c :                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out STRCAT                                  *
* ************************************************** */
void c2_strcat(void)
	{
		char ch;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3[VAR_LGTH];
			
		int pi;
		int pi2;			
		int x2 = 0;
		int x3 = 0;
		int x5 = 0;
		int x6 = 0;
		int x7 = 0;
		int I = 0;
		int ret = 0;
		int ret1 = 0;

		check_semi(); 

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

		if(ch == '"')
			{	
				for(I=0; I < char_ct; I++)
					{
						if(w_charlit[I].clit_rct == rct)
							{
								strcpy(tfield3, w_charlit[I].clit_value);
								strcpy(tfield2a, w_charlit[I].clit_cname);
                                                      	x5 = w_charlit[I].clit_lgth;
							}
					}

				x3 = 0;
				x2 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(tfield1a, lw_variable[I].lv_cname);
								x2 = lw_variable[I].lv_current_lgth;
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
										strcpy(tfield1a, gw_variable[I].gv_cname);
										x2 = gw_variable[I].gv_current_lgth;
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2z_strcat.c c2_strcat E-356 tfield1 Not Found = %s\n",tfield1);
						c2_error();
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcat.c c2_strcat #100");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, tfield2a);
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_strcat.c c2_strcat #101");
						trace_rec_3();
					}

				strcpy(a_string, "        MVC   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
				strcat(a_string, wk_strg);
				strcat(a_string, "(");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
                            strcat(a_string, wk_strg);
				strcat(a_string, ",R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_string.c c2_strcat #102");
						trace_rec_3();
					}
			} 
		else
			{	
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
						printf("c2z_strcat.c c2_strcat E-357 tfield1 Not Found = %s\n",tfield1);
						c2_error();
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
						printf("c2z_strcat.c c2_strcat E-358 tfield2 Not Found = %s\n",tfield2);
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
						strcpy(trace_1, "c2z_strcat.c c2_strcat #300");
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
						strcpy(trace_1, "c2z_strcat.c c2_strcat #301");
						trace_rec_3();
					}

				strcpy(a_string, "        MVC   ");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
				strcat(a_string, wk_strg);
				strcat(a_string, "(");
				snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
                            strcat(a_string, wk_strg);
				strcat(a_string, ",R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_string.c c2_strcat #302");
						trace_rec_3();
					}

				x7 = x5 + x6;
				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(tfield1,lw_variable[I].lv_name);
						ret1 = strcmp(sv_func,lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								lw_variable[I].lv_current_lgth = x7;
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
										gw_variable[I].gv_current_lgth = x7;
									}
							}
					}

				convert = 1;
			}	
		
	}	
