/* ***************************************************
*  c2z  : c2z_char.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* *************************************************** 
*  Scan test for CHAR                                *
* ************************************************** */
void c2_falph()
{
printf("c2_falph START rct = %d p_string = %s",rct,p_string);

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_char.c c2_falph");
				trace_rec_1();
			}

		tot_char++;

		int convert = 0;
		int pi;
		int pi2; 
		int II = 0;
		int u1 = 0;
		int x = 0;
		int y0 = 0;
		int y1 = 0;
		int y2 = 0;
		int op_2 = 0;
		int op_3 = 0;
		int op_4 = 0;
		int op_5 = 0;
		int op_6 = 0;
		int op_7 = 0;
		int op_8 = 0;
		int op_9 = 0;

		op_2 = 1;

		char ch;
		char *p3, *p4, *p6, *p7, *p8, *p9, *p10;
		char field1[VAR_LGTH];

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

		p9 = strstr(p_string, "(");
		p10 = strstr(p_string, ")");
		if((p9) && (p10))
			return;

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
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		field1[pi2] = '\0';

		op_code = 0;
		p8 = strstr(field1,"char");
		
		if((p8) && (op_code != 1))
			{
				op_code = 2;
				
			}


/* ***********************************
*  op_code                           * 
*	1	= 	VOID            *
*	2	=	CHAR            *
* ********************************** */	
		if(op_code == 2)	
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_char.c c2_falph CHAR");
						trace_rec_1();
					}

				pi2 = 0;
				x = 0;   
				
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
												wk_fdwk[pi2] = ch;
												pi2++;
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
						
						op_3 = 0;
						op_4 = 0;
						op_5 = 0;
						op_6 = 0;
						op_7 = 0;
						op_8 = 0;
						op_9 = 0;

						p3 = strstr(wk_fdwk,",");
						if(p3)
							{
								op_3 = 1;
							}

						p4 = strstr(wk_fdwk, "=");
						if(p4)
							{
								op_4 = 1;
							}

						y2 = 0;
						y0 = strlen(wk_fdwk);
						for(y1=0; y1 < y0; y1++)
							{
								ch = wk_fdwk[y1];
								if(ch == '[')
									y2++;
								if(ch == ']')
									y2++;
							}

						if(y2 == 2)
							{
								op_5 = 1;
							}

						if(y2 == 4)
							{
								op_9 = 1;
							}

						p6 = strstr(wk_fdwk, "**");
						if(p6)
							{
								op_6 = 1;
							}
		
						p7 = strstr(wk_fdwk, "*");
						if((p7) && (!p6))
							{
								op_7 = 1;
							}

						p8 = strstr(wk_fdwk, "void");
						if(p8)
							{
								op_8 = 1;
							}

						if((op_2 == 1) && (op_3 == 0) && (op_4 == 1) && (op_5 == 0) && (op_6 == 0) && (op_7 == 0) && (op_8 == 0) && (convert == 0))
							{
								c2_falph_1();
								
							}

						if((convert == 0) && (op_5 == 1) && (op_8 == 0) && (convert == 0))
							{
								c2_falph_1();
							}

						if((op_2 == 1) && (op_3 == 0) && (op_4 == 0) && (op_5 == 0) && (op_6 == 0) && (op_7 == 0) && (op_8 == 0) && (op_9 == 0) && (convert == 0))
							{
								c2_falph_2();
								
							}

						if((op_2 == 1) && (op_6 == 1) && (op_8 == 0) && (convert == 0))
							{
								c2_falph_3();
								
							}

						if((op_2 == 1) && (op_7 == 1) && (op_8 == 0) && (convert == 0))
							{
								c2_falph_4();
								
							}

						if((op_2 == 1) && (op_5 == 1) && (op_7 == 1) && (op_8 == 1) && (convert == 0))
							{
								c2_falph_5();
								
							}

						if((op_2 == 1) && (op_3 == 1) && (op_5 == 1) && (convert == 0))
							{
								c2_falph_6();
								
							}
						
						if((op_9 == 1) && (convert == 0))		/* char in_stack[max_var][var_name];	*/
							{
								c2_falph_9();
							}
					}
			}

		convert = 1;	
	}	


/* ******************************
*  char xstring[10];            *
*  char pstring[BUFSIZE]        *
* ***************************** */	
void c2_falph_1()
	{
		check_semi(); 

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_char.c c2_falph_1");
				trace_rec_1();
			}

		int fd1_type = 0;
		int pi;
		int pi2;
		int I = 0;
		int s = 0;
		int x3 = 0;
		int size = 0;
		int ret = 0;
		int ret1 = 0;

		char ch;
		char *p;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];
		char tfield3a[VAR_LGTH];

		pi = 0;
		pi2 = 0;
		convert = 0;
		
		p = strstr(wk_fdwk, "'");
		if(p)
			{
				ch = wk_fdwk[pi];
				while(ch != '=')
					{
						if(ch != ' ')
							{
								tfield1[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = wk_fdwk[pi];
					}
				tfield1[pi2] = '\0';

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield1a, c_wkname);
		
				pi++;
				ch = wk_fdwk[pi];
				while(ch != '\'')
					{
						pi++;
						ch = wk_fdwk[pi];
					}

				pi2 = 0;
				pi++;
				pi++;
				ch = wk_fdwk[pi];
				tfield2[pi2] = ch;
				pi2++;
				tfield2[pi2] = '\0';
				strcpy(tfield2a, tfield2); 

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
								s = atoi(tfield3a);
								gw_variable[gv_ct].gv_lgth = s;
								gw_variable[gv_ct].gv_current_lgth = s;	
								strcpy(gw_variable[gv_ct].gv_value, null_field);
								strcpy(gw_variable[gv_ct].gv_literal,null_field);
								gw_variable[gv_ct].gv_init = 0;
								gw_variable[gv_ct].gv_use_ct = 0;
								strcpy(gw_variable[gv_ct].gv_dsect, null_field);
								gw_variable[gv_ct].gv_row = 0;
								gw_variable[gv_ct].gv_column = 0;
								strcpy(gw_variable[gv_ct].gv_label, null_field);
								strcpy(gw_variable[gv_ct].gv_table, null_field);
								strcpy(gw_variable[gv_ct].gv_aname, null_field);
								strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
								strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
								strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
								gw_variable[gv_ct].gv_dec = 0;
								gw_variable[gv_ct].gv_id = 3;
								gv_ct++;
								
								convert = 1;
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
								strcpy(lw_variable[lv_ct].lv_type, "C");
								s = atoi(tfield3a);
								lw_variable[lv_ct].lv_lgth = s;
								lw_variable[lv_ct].lv_current_lgth = s;	
								strcpy(lw_variable[lv_ct].lv_value, tfield2);
								lw_variable[lv_ct].lv_use_ct = 0;
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_dec = 0;
								lw_variable[lv_ct].lv_id = 3;
								lv_ct++;
								
								convert = 1;
							}
					}
			}

		if(!p)
			{
				ch = wk_fdwk[pi];
				while(ch != '[')
					{
						if(ch != ' ')
							{
								tfield1[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = wk_fdwk[pi];
					}
				tfield1[pi2] = '\0';

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(tfield1a, c_wkname);
		
				skip = 0;
				if(ch == '[')
					{
						skip = 1;
					}

				x3 = 0;
				pi2 = 0;
				if(skip == 1)
					{
						x3 = 0;
						pi++;
						ch = wk_fdwk[pi];
						while(ch != ']')
							{
								if(x3 == 0)
									{
										if(isdigit(ch))
											{
												fd1_type = 1;
												x3 = 1;
											}

										if(isalpha(ch))
											{
												fd1_type = 2;
												x3 = 1;
											}
									}
								tfield2[pi2] = ch;
								pi2++;
								pi++;
								ch = wk_fdwk[pi];
							}
					}
				tfield2[pi2] = '\0';

				if(fd1_type == 2)	
					{
						x3 = 0;
						if(lv_ct > 0)
							{
								for(I=0; I < lv_ct; I++)
									{
										ret = strcmp(tfield2, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												x3 = 1;
												strcpy(tfield3a, lw_variable[I].lv_value);
												strcpy(tfield2a, lw_variable[I].lv_cname);
												lw_variable[I].lv_use_ct++;
											}
									}
							}
										
						if(x3 == 0)
							{
								if(gv_ct > 0)
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(tfield2, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x3 = 1;
														strcpy(tfield3a, gw_variable[I].gv_value);
														strcpy(tfield2a, gw_variable[I].gv_cname);
														gw_variable[I].gv_use_ct++;
													}
											}
									}
							}

						if(x3 == 0)
							{
								printf("c2z_char.c c2_falph_1 [ ] E-6 tfield2 Not Found = %s\n",tfield2);
								c2_error();
							}

						x3 = 0;
						if(lv_ct > 0)
							{
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
							}
										
						if(x3 == 0)
							{
								if(gv_ct > 0)
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
										s = atoi(tfield3a);
										gw_variable[gv_ct].gv_lgth = s;
										gw_variable[gv_ct].gv_current_lgth = s;	
										strcpy(gw_variable[gv_ct].gv_value, null_field);
										strcpy(gw_variable[gv_ct].gv_literal,null_field);
										gw_variable[gv_ct].gv_init = 0;
										gw_variable[gv_ct].gv_use_ct = 0;
										strcpy(gw_variable[gv_ct].gv_dsect, null_field);
										gw_variable[gv_ct].gv_row = 0;
										gw_variable[gv_ct].gv_column = 0;
										strcpy(gw_variable[gv_ct].gv_label, null_field);
										strcpy(gw_variable[gv_ct].gv_table, null_field);
										strcpy(gw_variable[gv_ct].gv_aname, null_field);
										strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
										strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
										strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
										gw_variable[gv_ct].gv_dec = 0;
										gw_variable[gv_ct].gv_id = 3;
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
										strcpy(lw_variable[lv_ct].lv_type, "C");
										s = atoi(tfield3a);
										lw_variable[lv_ct].lv_lgth = s;
										lw_variable[lv_ct].lv_current_lgth = s;
										strcpy(lw_variable[lv_ct].lv_value, null_field);
										lw_variable[lv_ct].lv_use_ct = 0;
										strcpy(lw_variable[lv_ct].lv_func, sv_func);
										strcpy(lw_variable[lv_ct].lv_literal, null_field);
										lw_variable[lv_ct].lv_dec = 0;
										lw_variable[lv_ct].lv_id = 3;
										lv_ct++;
									}

								convert = 1;
							}
					}

				if((fd1_type == 1) && (convert == 0))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						s = strlen(c_wkname);
						c_wkname[s] = '\0';
						strcpy(tfield1a,c_wkname);
						
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
								s = atoi(tfield2);
								gw_variable[gv_ct].gv_lgth = s;	
								strcpy(gw_variable[gv_ct].gv_value, null_field);
								strcpy(gw_variable[gv_ct].gv_literal,null_field);
								gw_variable[gv_ct].gv_init = 0;
								gw_variable[gv_ct].gv_use_ct = 0;
								strcpy(gw_variable[gv_ct].gv_dsect, null_field);
								gw_variable[gv_ct].gv_row = 0;
								gw_variable[gv_ct].gv_column = 0;
								strcpy(gw_variable[gv_ct].gv_label, null_field);
								strcpy(gw_variable[gv_ct].gv_table, null_field);
								strcpy(gw_variable[gv_ct].gv_aname, null_field);
								strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
								strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
								strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
								gw_variable[gv_ct].gv_dec = 0;
								gw_variable[gv_ct].gv_id = 3;
								gv_ct++;
											
								convert = 1;
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
								strcpy(lw_variable[lv_ct].lv_type, "C");
								s = atoi(tfield2);
								lw_variable[lv_ct].lv_lgth = s;
								strcpy(lw_variable[lv_ct].lv_value, null_field);
								lw_variable[lv_ct].lv_use_ct = 0;
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_dec = 0;
								lw_variable[lv_ct].lv_id = 3;
								lv_ct++;

								convert = 1;
							}
					}
			}
	}


/* ******************************
*  char ch;                     *
* ***************************** */
void c2_falph_2()		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_char.c c2_falph_2");
				strcat(trace_1, wk_fdwk);
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];

		int pi;
		int pi2;
		int y0 = 0;
		int y1 = 0;
		int y2 = 0;
		int y5 = 0;
		int s = 0;
		int size = 0;
				
		pi = 0;
		ch = wk_fdwk[pi];
		pi2 = 0;
		while(ch != ' ')
			{
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = wk_fdwk[pi];
			}
		field1[pi2] = '\0';

		y0 = 0;
		for(y1=0; y1 < lv_ct; y1++)
			{
				y2 = strcmp(field1, lw_variable[y1].lv_name);
				y5 = strcmp(sv_func, lw_variable[y1].lv_func);
				if((y2 == 0) && (y5 == 0))
					{
						y0 = 1;
						strcpy(field1a, lw_variable[y1].lv_value);
					}
			}

		if(y0 == 0)
			{
				for(y1=0; y1 < gv_ct; y1++)
					{
						y2 = strcmp(field1, gw_variable[y1].gv_name);
						if(y2 == 0)
							{
								y0 = 1;
								strcpy(field1a, gw_variable[y1].gv_value);
							}
					}
			}

		if(y0 == 0)
			{
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(field1a, c_wkname);
			
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
						strcpy(gw_variable[gv_ct].gv_cname, field1a);
						strcpy(gw_variable[gv_ct].gv_name, field1);  	             
						strcpy(gw_variable[gv_ct].gv_type, "C");
						s = 1;
						gw_variable[gv_ct].gv_lgth = s;
						strcpy(gw_variable[gv_ct].gv_value,null_field);
						strcpy(gw_variable[gv_ct].gv_literal,null_field);
						gw_variable[gv_ct].gv_init = 0;
						gw_variable[gv_ct].gv_use_ct = 0;
						strcpy(gw_variable[gv_ct].gv_dsect, null_field);
						gw_variable[gv_ct].gv_row = 0;
						gw_variable[gv_ct].gv_column = 0;
						strcpy(gw_variable[gv_ct].gv_label, null_field);
						strcpy(gw_variable[gv_ct].gv_table, null_field);
						strcpy(gw_variable[gv_ct].gv_aname, null_field);
						strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
						strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
						strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
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
						strcpy(lw_variable[lv_ct].lv_cname, field1a);
						strcpy(lw_variable[lv_ct].lv_name, field1);  	             
						strcpy(lw_variable[lv_ct].lv_type, "C");
						lw_variable[lv_ct].lv_lgth = 1;
						strcpy(lw_variable[lv_ct].lv_value, null_field);
						lw_variable[lv_ct].lv_use_ct = 0;
						strcpy(lw_variable[lv_ct].lv_func, sv_func);
						strcpy(lw_variable[lv_ct].lv_literal, null_field);
						lw_variable[lv_ct].lv_dec = 0;
						lw_variable[lv_ct].lv_id = 3;
						lv_ct++;
					}
			}
	}


/* ******************************
*  char **array                 *
* ***************************** */
void c2_falph_3()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_char.c c2_falph_3");
        trace_rec_1();
     }

     tot_malloc++;

     char ch;
     char field1[VAR_LGTH];
     char field1a[VAR_LGTH];
     char field10[VAR_LGTH];

      int pi;
      int pi2;
      int s = 0;
      int size = 0;
      int v = 0;
      int x3 = 0;
      int ret = 0;
      int ret1 = 0;

     pi = 0;
     ch = wk_fdwk[pi];
     while(ch == ' ')
     {
        ch = wk_fdwk[pi];
        pi++;
     }


		pi++;
		ch = wk_fdwk[pi];
		while(ch != '*')
			{
				ch = wk_fdwk[pi];
				pi++;	
			}

		pi2 = 0;
		pi++;
		ch = wk_fdwk[pi];
		while(ch != ' ') 
			{
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = wk_fdwk[pi];
			}
		field1[pi2] = '\0';

		c_name++;
		snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
		strcpy(c_wkname, "C37F");
		strcat(c_wkname, wk_strg);
		s = strlen(c_wkname);
		c_wkname[s] = '\0';
		strcpy(field1a, c_wkname);

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
				strcpy(gw_variable[gv_ct].gv_cname, field1a);
				strcpy(gw_variable[gv_ct].gv_name, field1);  	             
				strcpy(gw_variable[gv_ct].gv_type, "A");
				gw_variable[gv_ct].gv_init = 0;
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				
				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "T");
				strcpy(gw_variable[gv_ct].gv_table, wk_string);
				
				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "N");
				strcpy(gw_variable[gv_ct].gv_dsect,wk_string);

				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "L");
				strcpy(gw_variable[gv_ct].gv_label,wk_string);

				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "R");
				strcpy(gw_variable[gv_ct].gv_sv_reg,wk_string);

				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "X");
				strcpy(gw_variable[gv_ct].gv_wk_reg,wk_string);

				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "W");
				strcpy(gw_variable[gv_ct].gv_wk_strg,wk_string);
			
				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "A");
				strcpy(gw_variable[gv_ct].gv_aname,wk_string);

				gw_variable[gv_ct].gv_flag = 0;
				gw_variable[gv_ct].gv_lgth = 0;

 				strcpy(field10,field1);
				strcat(field10, "_width");

				x3 = 0;
				for(v = 0; v < gv_ct; v++)
					{
						ret = strcmp(field10, gw_variable[v].gv_name);
						if(ret == 0)
							{
								x3 = 1;
								gw_variable[gv_ct].gv_column = atoi(gw_variable[v].gv_value);
							}
					}
				
				if(x3 == 0)
					{
						printf("c2_falph_3 FIELD1 WIDTH NOT FOUND\n");
						printf("c2_falph_3 rct = %d p_string = %s",rct,p_string);
						exit(1);
					}

				strcpy(field10,field1);
				strcat(field10, "_rows");

				x3 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field10, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								gw_variable[gv_ct].gv_row = atoi(lw_variable[v].lv_value);
							}
					}

				if(x3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field10, gw_variable[v].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										gw_variable[gv_ct].gv_row = atoi(gw_variable[v].gv_value);
									}
							}
					}

				if(x3 == 0)
					{
						printf("c2_falph_3 FIELD1 ROWS NOT FOUND\n");
						printf("c2_falph_3 rct = %d p_string = %s",rct,p_string);
						exit(1);
					}

				gv_ct++;

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';

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
				strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
				strcpy(gw_variable[gv_ct].gv_name, wk_string);  	             
				strcpy(gw_variable[gv_ct].gv_type, "B");
				gw_variable[gv_ct].gv_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value,null_field);	
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_init = 0;
				gw_variable[gv_ct].gv_use_ct = 0;
				strcpy(gw_variable[gv_ct].gv_dsect, null_field);
				gw_variable[gv_ct].gv_row = 0;
				gw_variable[gv_ct].gv_column = 0;
				strcpy(gw_variable[gv_ct].gv_label, null_field);
				strcpy(gw_variable[gv_ct].gv_table, null_field);
				strcpy(gw_variable[gv_ct].gv_aname, null_field);
				strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
				strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
				strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
				gw_variable[gv_ct].gv_dec = 0;
				gv_ct++;

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';

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
				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "W");

				gw_variable[gv_ct].gv_rct = rct;
				strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
				strcpy(gw_variable[gv_ct].gv_name, wk_string);  	             
				strcpy(gw_variable[gv_ct].gv_type, "C");
				gw_variable[gv_ct].gv_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value,null_field);	
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_init = 0;
				gw_variable[gv_ct].gv_use_ct = 0;
				strcpy(gw_variable[gv_ct].gv_dsect, null_field);
				gw_variable[gv_ct].gv_row = 0;
				gw_variable[gv_ct].gv_column = 0;
				strcpy(gw_variable[gv_ct].gv_label, null_field);
				strcpy(gw_variable[gv_ct].gv_table, null_field);
				strcpy(gw_variable[gv_ct].gv_aname, null_field);
				strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
				strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
				strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
				gw_variable[gv_ct].gv_dec = 0;
				gv_ct++;
			}		

		convert = 1;
	}


/* ******************************
*  char *ch;                    *
* ***************************** */
void c2_falph_4()	
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_char.c scan c2_falph_4");
	 trace_rec_1();
     }

     char ch;
     char field1[VAR_LGTH];
     char field1a[VAR_LGTH];
 
      int pi;
      int pi2;
      int s = 0;
      int size = 0;
		 
     pi2 = 0;
     pi = 0;
     ch = wk_fdwk[pi];
     while(ch != '\0')
     {
        if(ch != '*')
        {
           field1[pi2] = ch;
           pi2++;
        }
 	 pi++;
	 ch = wk_fdwk[pi];
     }
     field1[pi2] = '\0';

     c_name++;
     snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
     strcpy(c_wkname, "C37F");
     strcat(c_wkname, wk_strg);
     s = strlen(c_wkname);
     c_wkname[s] = '\0';
     strcpy(field1a, c_wkname);
	
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
				strcpy(gw_variable[gv_ct].gv_cname,field1a);
				strcpy(gw_variable[gv_ct].gv_name, field1);  	             
				strcpy(gw_variable[gv_ct].gv_type, "I");
				gw_variable[gv_ct].gv_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value,null_field);	
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_init = 0;
				gw_variable[gv_ct].gv_use_ct = 0;
				strcpy(gw_variable[gv_ct].gv_dsect, null_field);
				gw_variable[gv_ct].gv_row = 0;
				gw_variable[gv_ct].gv_column = 0;
				strcpy(gw_variable[gv_ct].gv_label, null_field);
				strcpy(gw_variable[gv_ct].gv_table, null_field);
				strcpy(gw_variable[gv_ct].gv_aname, null_field);
				strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
				strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
				strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 1;
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
				strcpy(lw_variable[lv_ct].lv_cname, field1a);
				strcpy(lw_variable[lv_ct].lv_name, field1);  	             
				strcpy(lw_variable[lv_ct].lv_type, "I");
				lw_variable[lv_ct].lv_lgth = 0;
				strcpy(lw_variable[lv_ct].lv_value, null_field);
				lw_variable[lv_ct].lv_use_ct = 0;
				strcpy(lw_variable[lv_ct].lv_func, sv_func);
				lw_variable[lv_ct].lv_dec = 0;
				lw_variable[lv_ct].lv_id = 1;
				lv_ct++;
			}

		convert = 1;
	}

void c2_falph_5()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "scan c2_falph_5 ");
				trace_rec_1();
			}

		convert = 1;
		exit(1);
	}

void c2_falph_6()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "scan c2_falph_6 ");
				trace_rec_1();
			}

		convert = 1;
		exit(1);
	}

void c2_falph_9()		
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_char.c c2_falph_9");
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field4a[VAR_LGTH];
		char field5a[VAR_LGTH];

		int y0 = 0;
		int y1 = 0;
		int y2 = 0;
		int y5 = 0;
		int pi;
		int pi2;
		int I = 0;
		int s = 0;
		int x3 = 0;
		int size = 0;
		int fd2_type = 0;
		int fd3_type = 0;
		
		tot_malloc++;

		pi = 0;
		ch = wk_fdwk[pi];
		while(ch == ' ')		
			{
				ch = wk_fdwk[pi];
				pi++;	
			}
		
		pi2 = 0;
		ch = wk_fdwk[pi];
		while(ch != '[') 
			{
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = wk_fdwk[pi];
			}
		field1[pi2] = '\0';
		
		pi2 = 0;
		x3 = 0;
		pi++;
		ch = wk_fdwk[pi];
		while(ch != ']') 
			{
				if(x3 == 0)
					{
						if(isdigit(ch))
							{
								fd2_type = 1;
								x3 = 1;
							}

						if(isalpha(ch))
							{
								fd2_type = 2;
								x3 = 1;
							}
					}
				field2[pi2] = ch;
				pi2++;
				pi++;
				ch = wk_fdwk[pi];
			}
		field2[pi2] = '\0';

		x3 = 0;
		pi2 = 0;
		pi++;
		pi++;
		ch = wk_fdwk[pi];
		while(ch != ']') 
			{
				if(x3 == 0)
					{
						if(isdigit(ch))
							{
								fd3_type = 1;
								x3 = 1;
							}

						if(isalpha(ch))
							{
								fd3_type = 2;
								x3 = 1;
							}
					}
				field3[pi2] = ch;
				pi2++;
				pi++;
				ch = wk_fdwk[pi];
			}
		field3[pi2] = '\0';

		y0 = 0;
		if(lv_ct > 0)
			{
				for(y1=0; y1 < lv_ct; y1++)
					{
						y2 = strcmp(field1, lw_variable[y1].lv_name);
						y5 = strcmp(sv_func, lw_variable[y1].lv_func);
						if((y2 == 0) && (y5 == 0))
							{
								y0 = 1;
								strcpy(field1a, lw_variable[y1].lv_cname);
								lw_variable[y1].lv_use_ct++;
							}
					}
			}

		if(y0 == 0)
			{
				if(gv_ct > 0)
					{
						for(y1=0; y1 < gv_ct; y1++)
							{
								y2 = strcmp(field1, gw_variable[I].gv_name);
								if(y2 == 0)
									{
										y0 = 1;
										strcpy(field1a, gw_variable[y1].gv_cname);
										gw_variable[I].gv_use_ct++;
									}
							}
					}
			}

		y0 = 0;
		if(fd2_type == 2)
			{
				if(lv_ct > 0)
					{
						for(y1=0; y1 < lv_ct; y1++)
							{
								y2 = strcmp(field2, lw_variable[y1].lv_name);
								y5 = strcmp(sv_func, lw_variable[y1].lv_func);
								if((y2 == 0) && (y5 == 0))
									{
										y0 = 1;
										strcpy(field2a, lw_variable[y1].lv_cname);
										lw_variable[y1].lv_use_ct++;
									}
							}
					}

				if(y0 == 0)
					{
						if(gv_ct > 0)
							{
								for(y1=0; y1 < gv_ct; y1++)
									{
										y2 = strcmp(field2, gw_variable[y1].gv_name);
										if(y2 == 0)
											{
												y0 = 1;
												strcpy(field2a, gw_variable[y1].gv_cname);
												gw_variable[y1].gv_use_ct++;
											}
									}
							}
					}
			}

		y0 = 0;
		if(fd3_type == 2)
			{
				if(lv_ct > 0)
					{
						for(y1=0; y1 < lv_ct; y1++)
							{
								y2 = strcmp(field3, lw_variable[y1].lv_name);
								y5 = strcmp(sv_func, lw_variable[y1].lv_func);
								if((y2 == 0) && (y5 == 0))
									{
										y0 = 1;
										strcpy(field3a, lw_variable[y1].lv_cname);
										lw_variable[y1].lv_use_ct++;
									}
							}
					}

				if(y0 == 0)
					{
						if(gv_ct > 0)
							{
								for(y1=0; y1 < gv_ct; y1++)
									{
										y2 = strcmp(field3, gw_variable[y1].gv_name);
										if(y2 == 0)
											{
												y0 = 1;
												strcpy(field3a, gw_variable[y1].gv_cname);
												gw_variable[y1].gv_use_ct++;
											}
									}
							}
					}
			}

		if((fd2_type == 1) || (fd3_type == 1))
			{
				y0 = 1;
			}

		if(y0 == 1)
			{
				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';
				strcpy(field1a, c_wkname);
					
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
				strcpy(gw_variable[gv_ct].gv_type, "A");
				gw_variable[gv_ct].gv_init = 0;
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;

				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "T");
				strcpy(gw_variable[gv_ct].gv_table, wk_string);
				
				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "N");
				strcpy(gw_variable[gv_ct].gv_dsect,wk_string);

				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "L");
				strcpy(gw_variable[gv_ct].gv_label,wk_string);

				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "R");
				strcpy(gw_variable[gv_ct].gv_sv_reg,wk_string);

				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "X");
				strcpy(gw_variable[gv_ct].gv_wk_reg,wk_string);

				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "W");
				strcpy(gw_variable[gv_ct].gv_wk_strg,wk_string);

				if(fd2_type == 2)
					{
						y0 = 0;
						if(gv_ct > 0)
							{
								for(y1=0; y1 < gv_ct; y1++)
									{
										y2 = strcmp(field2, gw_variable[y1].gv_name);
										if(y2 == 0)
											{
												strcpy(field4a, gw_variable[y1].gv_value);
											}
									}
							}
						gw_variable[gv_ct].gv_row = atoi(field4a);
					}

				if(fd2_type == 1)
					{
 						gw_variable[gv_ct].gv_row = atoi(field2);
					}

				if(fd3_type == 2)
					{
						y0 = 0;
						if(gv_ct > 0)
							{
								for(y1=0; y1 < gv_ct; y1++)
									{
										y2 = strcmp(field3, gw_variable[y1].gv_name);
										if(y2 == 0)
											{
												strcpy(field5a, gw_variable[y1].gv_value);
											}
									}
							}
						gw_variable[gv_ct].gv_column = atoi(field5a); 
					}

				if(fd3_type == 1)
					{
						gw_variable[gv_ct].gv_column = atoi(field3); 
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "A");
				strcpy(gw_variable[gv_ct].gv_aname,wk_string);
                            if(fd3_type == 2)
					{
						gw_variable[gv_ct].gv_lgth = atoi(field5a);
					}
				if(fd3_type == 1)
					{
						gw_variable[gv_ct].gv_lgth = atoi(field3);
					}
				gw_variable[gv_ct].gv_flag = 0;
				gv_ct++;

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';

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
				strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
				strcpy(gw_variable[gv_ct].gv_name, wk_string);  	             
				strcpy(gw_variable[gv_ct].gv_type, "B");
				gw_variable[gv_ct].gv_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value,null_field);	
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_init = 0;
				gw_variable[gv_ct].gv_use_ct = 0;
				strcpy(gw_variable[gv_ct].gv_dsect, null_field);
				gw_variable[gv_ct].gv_row = 0;
				gw_variable[gv_ct].gv_column = 0;
				strcpy(gw_variable[gv_ct].gv_label, null_field);
				strcpy(gw_variable[gv_ct].gv_table, null_field);
				strcpy(gw_variable[gv_ct].gv_aname, null_field);
				strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
				strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
				strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
				gw_variable[gv_ct].gv_dec = 0;
				gv_ct++;

				c_name++;
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(c_wkname, "C37F");
				strcat(c_wkname, wk_strg);
				s = strlen(c_wkname);
				c_wkname[s] = '\0';

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
				snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
				strcpy(wk_string, "A37");
				strcat(wk_string, wk_strg);
				strcat(wk_string, "W");

				gw_variable[gv_ct].gv_rct = rct;
				strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
				strcpy(gw_variable[gv_ct].gv_name, wk_string);  	             
				strcpy(gw_variable[gv_ct].gv_type, "C");
				strcpy(gw_variable[gv_ct].gv_value,null_field);	
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_init = 0;
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				if(fd3_type == 2)
					{
						y0 = atoi(field5a);
						gw_variable[gv_ct].gv_column = y0;
						y0 = atoi(field5a);
						gw_variable[gv_ct].gv_lgth = y0;
					}
				if(fd3_type == 1)
					{
						y0 = atoi(field3);
						gw_variable[gv_ct].gv_column = y0;
						y0 = atoi(field3);
						gw_variable[gv_ct].gv_lgth = y0;
					}
				strcpy(gw_variable[gv_ct].gv_dsect, null_field);
				gw_variable[gv_ct].gv_row = 0;
				strcpy(gw_variable[gv_ct].gv_label, null_field);
				strcpy(gw_variable[gv_ct].gv_table, null_field);
				strcpy(gw_variable[gv_ct].gv_aname, null_field);
				strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
				strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
				strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
				gv_ct++;
			}

		convert = 1;

	}


