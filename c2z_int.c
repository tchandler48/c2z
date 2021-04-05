/* ***************************************************
*  c2z : c2z_int.c :                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* *************************************************** 
*  Scan test for INT                                 *
* ************************************************** */
void c2_int()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_int.c c2_int");
				trace_rec_1();
			}

		 int pi;
		 int pi2;
		 int II = 0;
		 int u1 = 0;
		 int x = 0;
		 int arr_flag = 0;

		char ch;
		char *p1, *p4, *p5,*p6, *p8, *p9, *p10, *p11;
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

		p10 = strstr(field1,"void");
		if(p10)
			{
				op_code = 1;
			}

		p10 = strstr(field1,"int");
		if((p10) && (op_code != 1))
			{
				op_code = 2;
				
			}


/* ***********************************
*  op_code                           * 
*	1	= 	VOID            *
*	2	=	INT             *
* ********************************** */	
		p6 = strstr(p_string, "(");
		p9 = strchr(p_string, ')');

		char* pos = strstr(p_string, "/*");
		
		/*
		if(pos)
			printf("found the string at position: %d\n", pos - p_string);
		
		*/

		char* pos1 = strstr(p_string, "*");
		
		/*
		if(pos1)
			printf("found the string at position: %d\n", pos - p_string);
		*/

		arr_flag = 0;
		p1 = strstr(p_string,"*");
		if(p1)
			{
                           if(pos1 < pos)
					arr_flag = 1;
			}

		if((op_code == 2) && (p6) && (p9) && (convert == 0) && (arr_flag == 0))
			{
				c2_int_3();
			}

		if((op_code == 2) && (convert == 0) && (arr_flag == 0))	/* INT NO VOID	*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_int.c pass 2 int processing");
						trace_rec_1();
					}

				pi2 = 0;
				x = 0;

				p6 = strstr(p_string, "(");
				p9 = strchr(p_string, ')');
								
				if((!p6) && (!p9))
					{
				
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

								p4 = strstr(wk_fdwk, "=");
								p8 = strchr(wk_fdwk, '[');
								p5 = strchr(wk_fdwk, ']');
								p11 = strstr(wk_fdwk, "=");

								convert = 0;
								
								if((!p4) && (!p11) && (!p8) && (!p5) && (convert == 0) && (arr_flag == 0))
									{
										c2_int_1();		/* single variable ie   INT NROWS;		*/
										convert = 1;
									}
								
								if(p11)
									{
										c2_int_2();		/* INT NCOLUMNS=[BUFSIZE]			*/
										convert = 1;
									}

								if((!p4) && (p8) && (p5) && (convert == 0) && (arr_flag == 0))	/* int iv_stack[MAX_VALUE]	*/
									{
										c2_int_5();
										convert = 1;
									}

							}
					}	
			}

		if((op_code == 2) && (arr_flag == 1) && (convert == 0))		
			{
				c2_int_6();
				convert = 1;
			}

		if((op_code == 1) && (convert == 0) && (arr_flag == 0))			/* VOID A_BORT(INT CODE< INT LINE_NDX	*/
			{
				 c2_int_3();	
				convert = 1;					
			}
					
	}	

void c2_int_1()			/* single variable ie   INT NROWS;		*/
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_int.c pass 2 c2_int_1");
        strcat(trace_1, wk_fdwk);
        trace_rec_1();
     }

      int pi;
      int pi2;
      int s = 0;
      int x3 = 0;
      int v = 0;
      int size = 0;
      int ret = 0;
      int ret1 = 0;

     char ch;
     char *p8;
     char field1[VAR_LGTH];
     char field1a[VAR_LGTH];

     equal_found = 0;
     p8 = strstr(wk_fdwk,"=");
     if(p8)
     {
        equal_found = 1;
     }

     if(equal_found == 0)
     {
        pi = 0;
        pi2 = 0;
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
     }



		if(equal_found == 1)
			{
				pi = 0;
				pi2 = 0;
				ch = wk_fdwk[pi];
				while(ch != '=')
					{
						if(ch != ' ')
							{
								field1[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = wk_fdwk[pi];
					}
				field1[pi2] = '\0';
			}
		
		c_name++;
		snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
		strcpy(c_wkname, "C37F");
		strcat(c_wkname, wk_strg);
		s = strlen(c_wkname);
		c_wkname[s] = '\0';
		strcpy(field1a, c_wkname);

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
						strcpy(gw_variable[gv_ct].gv_cname, field1a);	
      						strcpy(gw_variable[gv_ct].gv_name, field1);  	             
						strcpy(gw_variable[gv_ct].gv_type, "I");
						gw_variable[gv_ct].gv_lgth = 0;
						gw_variable[gv_ct].gv_current_lgth = 0;
						strcpy(gw_variable[gv_ct].gv_value, "0");
						gw_variable[gv_ct].gv_init = 0;
						strcpy(gw_variable[gv_ct].gv_literal,null_field);
						gw_variable[gv_ct].gv_use_ct = 0;
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
						strcpy(lw_variable[lv_ct].lv_value, "0");
						lw_variable[lv_ct].lv_use_ct = 0;
						strcpy(lw_variable[lv_ct].lv_func, sv_func);
						lw_variable[lv_ct].lv_current_lgth = 0;
						lw_variable[lv_ct].lv_dec = 0;
						lw_variable[lv_ct].lv_id = 1;
						lv_ct++;
					}
			}
			
		convert = 1;
	}


/* ********************************************
*  c2_int_2                                   *
* ******************************************* */
void c2_int_2()				/* INT NCOLUMNS=BUFSIZE	or AB_CODE = 1  or X=LINE_NDX	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_int.c c2_int_2");
				trace_rec_1();
			}

		check_semi();

		int fd2_type = 0;
		int x3 = 0;
		int x99 = 0;
		int s = 0;
		int v = 0;
		int rct1 = 0;
		int I = 0;
		int fd_found = 0;
		int z3 = 0;
		int size = 0;
		int s1 = 0;
		int ret = 0;
		int ret1 = 0;
		int pi;
		int pi2;

		char ch,*p1;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];
		char tfield3b[VAR_LGTH];
		char tfield21[VAR_LGTH];
		
		pi2 = 0;
		pi = 0;
		ch = wk_fdwk[pi];
		while(ch != '=')
			{
				if(ch != ' ')
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

		pi2 = 0;
		fd_found = 0;
		pi++; 
		ch = wk_fdwk[pi];
		while(ch != '\0')
			{
				if(fd_found == 0)
					{
						if(isdigit(ch))
							{
								fd2_type = 1;
								fd_found = 1;
							}
						if(isalpha(ch))
							{
								fd2_type = 2;
								fd_found = 1;
							}
					}
				if(ch != '[') 
					{
						if(ch != ']')
							{
								field2[pi2] = ch;
								pi2++;
							}
					}
				
				pi++;
				ch = wk_fdwk[pi];
			}
		field2[pi2] = '\0';

		if(fd2_type == 1)		/* field2 is numeric ex:  234 */
			{
				x3 = 0;
				if(global_st == 1)
					{
						for(v = 0; v < lv_ct; v++)
							{
								ret = strcmp(field1, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
										x3 = 1;
									}
							}
					}
					
				if((x3 == 0) && (global_st == 0))
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field1, gw_variable[v].gv_name);
								if(ret == 0)
									{
										x3 = 1;
									}
							}
					}

				if(x3 == 0)
					{
						if(global_st == 0)
							{
								s = strlen(field2);
								x99 = 0;
								p1 = strstr(field2,"-");
								if(p1)
									{
										x99 = 1;
									}

								s1 = s + 1;
								if(x99 == 1)
									{
										strcpy(tfield3b, field2);
										pi2 = 0;
										for(I=0; I < s1; I++)
											{
												ch = tfield3b[I];
												if(ch != '-')
													{
														field2[pi2] = ch;
														pi2++;
													}		
											}
										field2[pi2] = '\0';
									}

								if(x99 == 0)
									{	
										strcpy(field2a, field2);
									}
								else
									{
										strcpy(field2a,"-");
										strcat(field2a, field2);
									}
								
								c_name++;
								snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
								strcpy(c_wkname, "C37F");
								strcat(c_wkname, wk_strg);
								s = strlen(c_wkname);
								c_wkname[s] = '\0';
								strcpy(field1a, c_wkname);

								rct1 = rct;
								strcpy(tfield21,field1a);
								for(I=0; I < lit_ct; I++)
									{
										ret = strcmp(field2a, w_literal[I].lit_value);
										if(ret == 0)
											{
												strcpy(tfield21,w_literal[I].lit_cname);
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
                                                       	strcpy(w_literal[lit_ct].lit_name, field1);
								strcpy(w_literal[lit_ct].lit_cname, field1a);	
      								strcpy(w_literal[lit_ct].lit_value, field2a); 
 	             						strcpy(w_literal[lit_ct].lit_use_cname, tfield21);
								w_literal[lit_ct].lit_uct = 1;
								w_literal[lit_ct].lit_dec = 0;
								w_literal[lit_ct].lit_type = 1;
								lit_ct++;

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
								strcpy(gw_variable[gv_ct].gv_type, "I");
								gw_variable[gv_ct].gv_lgth = 0;
								gw_variable[gv_ct].gv_current_lgth = 0;
								strcpy(gw_variable[gv_ct].gv_value, field2a);
								gw_variable[gv_ct].gv_init = 0;
								strcpy(gw_variable[gv_ct].gv_literal, null_field);
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
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_use_ct = 0;
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_dec = 0;
								lw_variable[lv_ct].lv_id = 1;
								lv_ct++;

								s = strlen(field2);
								x99 = 0;
								p1 = strstr(field2,"-");
								if(p1)
									{
										x99 = 1;
									}

								s1 = s + 1;
								if(x99 == 1)
									{
										strcpy(tfield3b, field2);
										pi2 = 0;
										for(I=0; I < s1; I++)
											{
												ch = tfield3b[I];
												if(ch != '-')
													{
														field2[pi2] = ch;
														pi2++;
													}		
											}
										field2[pi2] = '\0';
									}

								if(x99 == 0)
									{
										strcpy(field2a, field2);
									}
								else
									{
										strcpy(field2a,"-");
										strcat(field2a, field2);
									}
									
								c_name++;
								snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
								strcpy(c_wkname, "C37F");
								strcat(c_wkname, wk_strg);
								s = strlen(c_wkname);
								c_wkname[s] = '\0';
								strcpy(field1a, c_wkname);

								rct1 = rct;
								strcpy(tfield21,field1a);
								for(I=0; I < lit_ct; I++)
									{
										ret = strcmp(w_literal[I].lit_value, field2a);
										if(ret == 0)
											{
												strcpy(tfield21,w_literal[I].lit_cname);
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
                                                       	strcpy(w_literal[lit_ct].lit_name, field1);
								strcpy(w_literal[lit_ct].lit_cname, field1a);	
      								strcpy(w_literal[lit_ct].lit_value, field2a); 
 	             						strcpy(w_literal[lit_ct].lit_use_cname, tfield21);
								w_literal[lit_ct].lit_uct = 1;
								w_literal[lit_ct].lit_dec = 0;
								w_literal[lit_ct].lit_type = 1;
								lit_ct++;
							}	
					}	

				convert = 1;
			}	
		
		if((fd2_type == 2) && (convert == 0))		/* field2 is alpha ex:  BUFSIZE  */
			{
				z3 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field2, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								z3 = 1;
								strcpy(field2a, lw_variable[v].lv_value);
							}
					}
					
				if(z3 == 0) 
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field2, gw_variable[v].gv_name);
								if(ret == 0)
									{
										z3 = 1;
										strcpy(field2a, gw_variable[v].gv_value);
									}
							}
					}

				if((z3 == 1) && (global_st == 0))
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
						strcpy(gw_variable[gv_ct].gv_value, field2a);
						gw_variable[gv_ct].gv_init = 0;
						strcpy(gw_variable[gv_ct].gv_literal, null_field);
						gw_variable[gv_ct].gv_use_ct = 0;
						gw_variable[gv_ct].gv_dec = 0;
						gw_variable[gv_ct].gv_id = 1;
						gv_ct++;
					}

				if((z3 == 1) && (global_st == 1))
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
						strcpy(lw_variable[lv_ct].lv_func, sv_func);
						lw_variable[lv_ct].lv_use_ct = 0;
						lw_variable[lv_ct].lv_dec = 0;
						lw_variable[lv_ct].lv_id = 1;
						lv_ct++;
					}

				if(z3 == 0)
					{
						printf("c2z_int.c c2_int_2 E-198 field2 Not Found = %s\n",field2);
						c2_error();
					}	
			}	

		convert = 1;

	}


void c2_int_3()				/* (VOID) or (INT) A_BORT(INT CODE, INT LINE_NDX	*/
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_int c2_int_3");
        trace_rec_1();
     }

     char ch;
     char *p;
     char *p1;
     char field1[VAR_LGTH];
     char field2[VAR_LGTH];
     char field3[VAR_LGTH];
     char field3a[VAR_LGTH];
     char field4[VAR_LGTH];
     char field4a[VAR_LGTH];
		char field5[VAR_LGTH];
		char field5a[VAR_LGTH];
		char field6[VAR_LGTH];
		char field7[VAR_LGTH];
		char field7a[VAR_LGTH];
		char field9[VAR_LGTH];
		char field9a[VAR_LGTH];
		char field11[VAR_LGTH];
		char field11a[VAR_LGTH];
		char field12[VAR_LGTH];

		int pi;
		int pi2 = 0;
		int I = 0;
		int x3 = 0;
		int x4 = 0;
		int x5 = 0;
		int x6 = 0;
		int x7 = 0;
		int ret = 0;
		int ret1 = 0;
		int fd2_type = 0;
		int fd5_type = 0;
		int fd7_type = 0;
		int fd9_type = 0;
		int fd11_type = 0;

		int no_parameters = 0;
		int comma_ct = 0;
		int size = 0;
		int tot_comma = 0;
		int s = 0;

		p = strstr(p_string, "()");
		if(p)
			{
				no_parameters = 1;
			}

		s = strlen(p_string);
		for(I=0; I < s; I++)
			{	
				ch = p_string[I];
				if(ch == ',')
					{
						tot_comma++;
					}
			}

		p1 = strstr(p_string, ",");
		if(p1)
			{
				comma_ct = 1;
			}
		else
			{
				comma_ct = 0;
			}

		if(no_parameters == 1)				/* no passed parameters	*/
			{
				pi = 0;
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
printf("c2z_int.c int_3 field1 = %s\n",field1);

				for(I = 0; I < fn_ct; I++)
					{
						ret = strcmp(field1, w_function[I].fn_name);
						if(ret == 0)
							{
								w_function[I].fn_start = rct;
							}
					}

				strcpy(sv_func, field1);
				convert = 1;
			}

		if((no_parameters == 0) && (comma_ct == 0))	/* one variable passed	*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_int.c c2_int_3 (1) var");
						trace_rec_1();
					}

				pi = 0;
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
		/* 		strcpy(sv_func, field1); */


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

				ret = strcmp("char", field2);
				if(ret == 0)
					{
						fd2_type = 1;		
					}
				else
					{
						fd2_type = 2;		
					}

				pi2 = 0;
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

				p1 = strstr(field3, "[");
				if(p1)
					{
						x5 = 1;
					}

				if(x5 == 1)
					{
						pi = 0;
						pi2 = 0;
						ch = field3[pi];
						while(ch != '[')
							{
								if(ch != '*')
									{
										field3a[pi2] = ch;
										pi2++;
									}
								pi++;
								ch = field3[pi];
							}
						field3a[pi2] = '\0';

						pi2 = 0;
						pi++;
						ch = field3[pi];
						while(ch != ']')
							{
								field4[pi2] = ch;
								pi2++;
								pi++;
								ch = field3[pi];
							}
						field4[pi2] = '\0';
						strcpy(field3, field3a);
					}

				for(I = 0; I < fn_ct; I++)
					{
						ret = strcmp(field1, w_function[I].fn_name);
						if(ret == 0)
							{
								w_function[I].fn_start = rct;
								strcpy(w_function[I].fn_fd1,field3);
							}
					}

				/* strcpy(sv_func, field1); */

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field3, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
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
									}
							}
					}

				if(x3 == 0)
					{
						if(x5 == 1)
							{
								x6 = 0;
								for(I=0; I < lv_ct; I++)
									{
										ret = strcmp(field4, lw_variable[I].lv_name);
										ret1 = strcmp(sv_func, lw_variable[I].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												x6 = 1;
												x7 = lw_variable[I].lv_lgth;
											}
									}

								if(x6 == 0)
									{
										for(I=0; I < gv_ct; I++)
											{
												ret = strcmp(field4, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x6 = 1;
														x7 = gw_variable[I].gv_lgth;
													}
											}
									}

								if(x6 == 0)
									{

									}
							}

						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field3a, c_wkname);

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
								strcpy(gw_variable[gv_ct].gv_cname, field3a);	
      								strcpy(gw_variable[gv_ct].gv_name, field3);
								if(fd2_type == 1)
									{
										strcpy(gw_variable[gv_ct].gv_type, "C");
										if(x5 == 1)
											{
												gw_variable[gv_ct].gv_lgth = x7;
												gw_variable[gv_ct].gv_current_lgth = x7;
											}
										else
											{
												gw_variable[gv_ct].gv_lgth = 1;
												gw_variable[gv_ct].gv_current_lgth = 0;
											}
										
										strcpy(gw_variable[gv_ct].gv_value, null_field);
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
										gw_variable[gv_ct].gv_id = 3;
										gv_ct++;
									}  

								if(fd2_type == 2)
									{	
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
										gw_variable[gv_ct].gv_id = 1;
										gv_ct++;
									}
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
								strcpy(lw_variable[lv_ct].lv_cname, field3a);	
      								strcpy(lw_variable[lv_ct].lv_name, field3); 
								if(fd2_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
										if(x5 == 1)
											{
												lw_variable[lv_ct].lv_lgth = x7;
												lw_variable[lv_ct].lv_current_lgth = x7;
											}
										else
											{
												lw_variable[lv_ct].lv_lgth = 1;
												lw_variable[lv_ct].lv_current_lgth = 0;
											}

										strcpy(lw_variable[lv_ct].lv_value, null_field);
										lw_variable[lv_ct].lv_init = 0;
										strcpy(lw_variable[lv_ct].lv_literal,null_field);
										strcpy(lw_variable[lv_ct].lv_func, sv_func);
										lw_variable[lv_ct].lv_use_ct = 0;
										lw_variable[lv_ct].lv_dec = 0;
										lw_variable[lv_ct].lv_id = 3;
										lv_ct++;
									}  

								if(fd2_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
										lw_variable[lv_ct].lv_lgth = 0;
										strcpy(lw_variable[lv_ct].lv_value, "0");
										lw_variable[lv_ct].lv_current_lgth = 0;
										lw_variable[lv_ct].lv_init = 0;
										strcpy(lw_variable[lv_ct].lv_literal,null_field);
										strcpy(lw_variable[lv_ct].lv_func, sv_func);
										lw_variable[lv_ct].lv_use_ct = 0;
										lw_variable[lv_ct].lv_dec = 0;
										lw_variable[lv_ct].lv_id = 1;
										lv_ct++;
									}
							}
					}

				convert = 1;
			}

		if((no_parameters == 0) && (tot_comma == 1))	/* two variables passed	*/
			{
				pi = 0;
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
				while(ch != ' ')
					{
						field2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field2[pi2] = '\0';

				ret = strcmp("char", field2);
				if(ret == 0)
					{
						fd2_type = 1;		
					}
				else
					{
						fd2_type = 2;		
					}

				pi2 = 0;
				ch = p_string[pi];
				while(ch != ',')
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

				pi2 = 0;
				while(ch != ')')
					{
						if(ch != ' ')
							{
								field4[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				field4[pi2] = '\0';

				for(I = 0; I < fn_ct; I++)
					{
						ret = strcmp(field1, w_function[I].fn_name);
						if(ret == 0)
							{
								w_function[I].fn_start = rct;
								strcpy(w_function[I].fn_fd1,field3);
								strcpy(w_function[I].fn_fd2,field4);
							}
					}

				strcpy(sv_func, field1);

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field3, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
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
									}
							}
					}

				ret = strcmp("char", field5);
				if(ret == 0)
					{
						fd5_type = 1;		
					}
				else
					{
						fd5_type = 2;		
					}

				if(x3 == 0)
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field3a, c_wkname);

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
								strcpy(gw_variable[gv_ct].gv_cname, field3a);	
      								strcpy(gw_variable[gv_ct].gv_name, field3);  	
								if(fd2_type == 1)
									{
										strcpy(gw_variable[gv_ct].gv_type, "C");
										gw_variable[gv_ct].gv_lgth = 1;
										gw_variable[gv_ct].gv_current_lgth = 0;
										strcpy(gw_variable[gv_ct].gv_value, null_field);
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
										gw_variable[gv_ct].gv_id = 3;
										gv_ct++;
									}  

								if(fd2_type == 2)
									{	
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
										gw_variable[gv_ct].gv_id = 1;
										gv_ct++;
									}
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
								strcpy(lw_variable[lv_ct].lv_cname, field3a);	
      								strcpy(lw_variable[lv_ct].lv_name, field3); 
								if(fd2_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
										lw_variable[lv_ct].lv_id = 3;
									}  
								if(fd2_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
										lw_variable[lv_ct].lv_id = 1;
									}
 								lw_variable[lv_ct].lv_lgth = 0;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field4, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
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
									}
							}
					}

				if(x3 == 0)
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field4a, c_wkname);

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
								strcpy(gw_variable[gv_ct].gv_cname, field4a);	
      								strcpy(gw_variable[gv_ct].gv_name, field4);  	
								if(fd5_type == 1)
									{
										strcpy(gw_variable[gv_ct].gv_type, "C");
										gw_variable[gv_ct].gv_id = 3;
									}  
								if(fd5_type == 2)
									{	
										strcpy(gw_variable[gv_ct].gv_type, "I");
										gw_variable[gv_ct].gv_id = 1;
									}
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
								strcpy(lw_variable[lv_ct].lv_cname, field4a);	
      								strcpy(lw_variable[lv_ct].lv_name, field4);  	
								if(fd5_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
										lw_variable[lv_ct].lv_id = 3;
									}  
								if(fd5_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
										lw_variable[lv_ct].lv_id = 1;
									}
								lw_variable[lv_ct].lv_lgth = 0;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				convert = 1;
			}

		if((no_parameters == 0) && (tot_comma == 2))	
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_int.c pass 2 c2_int_3 (3) var");
						trace_rec_1();
					}

				pi = 0;
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
				while(ch != ' ')
					{
						field2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field2[pi2] = '\0';

				ret = strcmp("char", field2);
				if(ret == 0)
					{
						fd2_type = 1;		
					}
				else
					{
						fd2_type = 2;		
					}

				pi2 = 0;
				ch = p_string[pi];
				while(ch != ',')
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

				pi2 = 0;
				while(ch != ',')	
					{
						if(ch != ' ')
							{
								field5[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				field5[pi2] = '\0';

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
						if(ch != ',')
							{
								field6[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				field6[pi2] = '\0';

				pi2 = 0;
				while(ch != ')')
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

				strcpy(sv_func, field1);

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field3, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
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
									}
							}
					}

				ret = strcmp("char", field2);
				if(ret == 0)
					{
						fd2_type = 1;		
					}
				else
					{
						fd2_type = 2;		
					}

				if((x3 == 0) && (fd2_type == 2))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field3a, c_wkname);

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
								strcpy(gw_variable[gv_ct].gv_cname, field3a);	
      								strcpy(gw_variable[gv_ct].gv_name, field3);  	
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
								strcpy(lw_variable[lv_ct].lv_cname, field3a);	
      								strcpy(lw_variable[lv_ct].lv_name, field3); 
								if(fd2_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
										lw_variable[lv_ct].lv_id = 3;
									}  
								if(fd2_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
										lw_variable[lv_ct].lv_id = 1;
									}
 								lw_variable[lv_ct].lv_lgth = 0;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				if((x3 == 0) && (fd2_type == 1))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field3a, c_wkname);

						x4 = 1;

						p = strstr(p_string, "[");
						if(p)
							{
								pi2 = 0;
								pi = 0;
								ch = field3[pi];
								while(ch != '[')
									{
										field11[pi2] = ch;
										pi2++;
										pi++;
										ch = field3[pi];
									}
								field11[pi2] = '\0';

								pi2 = 0;
								pi++;
								ch = field3[pi];
								while(ch != ']')
									{
										field12[pi2] = ch;
										pi2++;
										pi++;
										ch = field3[pi];
									}
								field12[pi2] = '\0';

								strcpy(field3, field11);

								x3 = 0;
								for(I=0; I < lv_ct; I++)
									{
										ret = strcmp(field12, lw_variable[I].lv_name);
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
												ret = strcmp(field12, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x3 = 1;
														x4 = gw_variable[I].gv_lgth;
													}
											}
									}

								if(x3 == 0)
									{
										printf("c2z_int.c c2_int_3 E-199 field12 Not Found = %s\n",field12);
										c2_error();
									}
							}

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
								strcpy(gw_variable[gv_ct].gv_cname, field3a);	
      								strcpy(gw_variable[gv_ct].gv_name, field3);  	
								strcpy(gw_variable[gv_ct].gv_type, "C");
								gw_variable[gv_ct].gv_lgth = x4;
								gw_variable[gv_ct].gv_current_lgth = 0;
								strcpy(gw_variable[gv_ct].gv_value, null_field);
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
								strcpy(lw_variable[lv_ct].lv_cname, field3a);	
      								strcpy(lw_variable[lv_ct].lv_name, field3); 
								strcpy(lw_variable[lv_ct].lv_type, "C");
								lw_variable[lv_ct].lv_lgth = x4;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field5, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(field5, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
									}
							}
					}

				ret = strcmp("char", field4);
				if(ret == 0)
					{
						fd5_type = 1;		/* char field	*/
					}
				else
					{
						fd5_type = 2;		/* int field	*/
					}

				if((x3 == 0) && (fd5_type == 2))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field5a, c_wkname);

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
								strcpy(gw_variable[gv_ct].gv_cname, field5a);	
      								strcpy(gw_variable[gv_ct].gv_name, field5);  	
								if(fd5_type == 1)
									{
										strcpy(gw_variable[gv_ct].gv_type, "C");
									}  
								if(fd5_type == 2)
									{	
										strcpy(gw_variable[gv_ct].gv_type, "I");
									}
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
								strcpy(lw_variable[lv_ct].lv_cname, field5a);	
      								strcpy(lw_variable[lv_ct].lv_name, field5);  	
								if(fd5_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
									}  
								if(fd5_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
									}
								lw_variable[lv_ct].lv_lgth = 0;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}


				if((x3 == 0) && (fd5_type == 1))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field5a, c_wkname);

						x4 = 1;

						p = strstr(p_string, "[");
						if(p)
							{

								pi2 = 0;
								pi = 0;
								ch = field5[pi];
								while(ch != '[')
									{
										field11[pi2] = ch;
										pi2++;
										pi++;
										ch = field5[pi];
									}
								field11[pi2] = '\0';

								pi2 = 0;
								pi++;
								ch = field5[pi];
								while(ch != ']')
									{
										field12[pi2] = ch;
										pi2++;
										pi++;
										ch = field5[pi];
									}
								field12[pi2] = '\0';

								strcpy(field5, field11);

								x3 = 0;
								for(I=0; I < lv_ct; I++)
									{
										ret = strcmp(field12, lw_variable[I].lv_name);
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
												ret = strcmp(field12, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x3 = 1;
														x4 = gw_variable[I].gv_lgth;
													}
											}
									}

								if(x3 == 0)
									{
										printf("c2_int_3 FIELD12 Not Found = %s\n",field12);
										printf("c2_int_3 rct = %d p_string = %s",rct,p_string);
										exit(1);
									}
							}

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
								strcpy(gw_variable[gv_ct].gv_cname, field5a);	
      								strcpy(gw_variable[gv_ct].gv_name, field5);  	
								if(fd5_type == 1)
									{
										strcpy(gw_variable[gv_ct].gv_type, "C");
									}  
								if(fd5_type == 2)
									{	
										strcpy(gw_variable[gv_ct].gv_type, "I");
									}
								gw_variable[gv_ct].gv_lgth = 0;
								gw_variable[gv_ct].gv_current_lgth = x4;
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
								strcpy(lw_variable[lv_ct].lv_cname, field5a);	
      								strcpy(lw_variable[lv_ct].lv_name, field5);  	
								if(fd5_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
									}  
								if(fd5_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
									}
								lw_variable[lv_ct].lv_lgth = x4;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field7, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(field7, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
									}
							}
					}

				ret = strcmp("char", field6);
				if(ret == 0)
					{
						fd7_type = 1;		/* char field	*/
					}
				else
					{
						fd7_type = 2;		/* int field	*/
					}

				if((x3 == 0) && (fd7_type == 2))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field7a, c_wkname);

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
								strcpy(gw_variable[gv_ct].gv_cname, field7a);	
      								strcpy(gw_variable[gv_ct].gv_name, field7);  	
								if(fd7_type == 1)
									{
										strcpy(gw_variable[gv_ct].gv_type, "C");
									}  
								if(fd7_type == 2)
									{	
										strcpy(gw_variable[gv_ct].gv_type, "I");
									}
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
								strcpy(lw_variable[lv_ct].lv_cname, field7a);	
      								strcpy(lw_variable[lv_ct].lv_name, field7);  	
								if(fd7_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
									}  
								if(fd7_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
									}
								lw_variable[lv_ct].lv_lgth = 0;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				for(I = 0; I < fn_ct; I++)
					{
						ret = strcmp(field1, w_function[I].fn_name);
						if(ret == 0)
							{
								w_function[I].fn_start = rct;
								strcpy(w_function[I].fn_fd1,field3);
								strcpy(w_function[I].fn_fd2,field5);
								strcpy(w_function[I].fn_fd3,field7);
							}
					}

				convert = 1;
			}

		if((no_parameters == 0) && (tot_comma == 3))	/* four variables passed	*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_int.c pass 2 c2_int_3 (4) var");
						trace_rec_1();
					}

				printf("c2z_int.c c2_int_3 four variables NOT CODED\n");
				printf("c2z_int.c c2_int_3 rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		if((no_parameters == 0) && (tot_comma == 4))	/* five variables passed	*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_int.c pass 2 c2_int_3 (5) var");
						trace_rec_1();
					}

				pi = 0;
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
				while(ch != ' ')
					{
						field2[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field2[pi2] = '\0';

				ret = strcmp("char", field2);
				if(ret == 0)
					{
						fd2_type = 1;		
					}
				else
					{
						fd2_type = 2;		
					}

				pi2 = 0;
				ch = p_string[pi];
				while(ch != ',')
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

				pi2 = 0;
				while(ch != ',')
					{
						if(ch != ' ')
							{
								field5[pi2] = ch;
								pi2++;
							}
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

				pi2 = 0;
				while(ch != ',')
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
				
				pi2 = 0;
				while(ch != ',')
					{
						if(ch != ' ')
							{
								field9[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				field9[pi2] = '\0';

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
				
				pi2 = 0;
				while(ch != ')')
					{
						if(ch != ' ')
							{
								field11[pi2] = ch;
								pi2++;
							}
						pi++;
						ch = p_string[pi];
					}
				field11[pi2] = '\0';

				strcpy(sv_func, field1);

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field3, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
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
									}
							}
					}

				ret = strcmp("char", field2);
				if(ret == 0)
					{
						fd2_type = 1;		
					}
				else
					{
						fd2_type = 2;		
					}

				if((x3 == 0) && (fd2_type == 2))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field3a, c_wkname);

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
								strcpy(gw_variable[gv_ct].gv_cname, field3a);	
      								strcpy(gw_variable[gv_ct].gv_name, field3);  	
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
								strcpy(lw_variable[lv_ct].lv_cname, field3a);	
      								strcpy(lw_variable[lv_ct].lv_name, field3); 
								if(fd2_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
									}  
								if(fd2_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
									}
 								lw_variable[lv_ct].lv_lgth = 0;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				if((x3 == 0) && (fd2_type == 1))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field3a, c_wkname);

						x4 = 1;

						p = strstr(p_string, "[");
						if(p)
							{
								pi2 = 0;
								pi = 0;
								ch = field3[pi];
								while(ch != '[')
									{
										field11[pi2] = ch;
										pi2++;
										pi++;
										ch = field3[pi];
									}
								field11[pi2] = '\0';

								pi2 = 0;
								pi++;
								ch = field3[pi];
								while(ch != ']')
									{
										field12[pi2] = ch;
										pi2++;
										pi++;
										ch = field3[pi];
									}
								field12[pi2] = '\0';

								strcpy(field3, field11);

								x3 = 0;
								for(I=0; I < lv_ct; I++)
									{
										ret = strcmp(field12, lw_variable[I].lv_name);
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
												ret = strcmp(field12, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x3 = 1;
														x4 = gw_variable[I].gv_lgth;
													}
											}
									}

								if(x3 == 0)
									{
										printf("c2_int_3 FIELD12 Not Found = %s\n",field12);
										printf("c2_int_3 rct = %d p_string = %s",rct,p_string);
										exit(1);
									}
							}

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
								strcpy(gw_variable[gv_ct].gv_cname, field3a);	
      								strcpy(gw_variable[gv_ct].gv_name, field3);  	
								strcpy(gw_variable[gv_ct].gv_type, "C");
								gw_variable[gv_ct].gv_lgth = x4;
								gw_variable[gv_ct].gv_current_lgth = 0;
								strcpy(gw_variable[gv_ct].gv_value, null_field);
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
								strcpy(lw_variable[lv_ct].lv_cname, field3a);	
      								strcpy(lw_variable[lv_ct].lv_name, field3); 
								strcpy(lw_variable[lv_ct].lv_type, "C");
								lw_variable[lv_ct].lv_lgth = x4;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field5, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(field5, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
									}
							}
					}

				ret = strcmp("char", field4);
				if(ret == 0)
					{
						fd5_type = 1;		/* char field	*/
					}
				else
					{
						fd5_type = 2;		/* int field	*/
					}

				if((x3 == 0) && (fd5_type == 2))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field5a, c_wkname);

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
								strcpy(gw_variable[gv_ct].gv_cname, field5a);	
      								strcpy(gw_variable[gv_ct].gv_name, field5);  	
								if(fd5_type == 1)
									{
										strcpy(gw_variable[gv_ct].gv_type, "C");
									}  
								if(fd5_type == 2)
									{	
										strcpy(gw_variable[gv_ct].gv_type, "I");
									}
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
								strcpy(lw_variable[lv_ct].lv_cname, field5a);	
      								strcpy(lw_variable[lv_ct].lv_name, field5);  	
								if(fd5_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
									}  
								if(fd5_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
									}
								lw_variable[lv_ct].lv_lgth = 0;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				if((x3 == 0) && (fd5_type == 1))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field5a, c_wkname);

						x4 = 1;

						p = strstr(p_string, "[");
						if(p)
							{

								pi2 = 0;
								pi = 0;
								ch = field5[pi];
								while(ch != '[')
									{
										field11[pi2] = ch;
										pi2++;
										pi++;
										ch = field5[pi];
									}
								field11[pi2] = '\0';

								pi2 = 0;
								pi++;
								ch = field5[pi];
								while(ch != ']')
									{
										field12[pi2] = ch;
										pi2++;
										pi++;
										ch = field5[pi];
									}
								field12[pi2] = '\0';

								strcpy(field5, field11);

								x3 = 0;
								for(I=0; I < lv_ct; I++)
									{
										ret = strcmp(field12, lw_variable[I].lv_name);
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
												ret = strcmp(field12, gw_variable[I].gv_name);
												if(ret == 0)
													{
														x3 = 1;
														x4 = gw_variable[I].gv_lgth;
													}
											}
									}

								if(x3 == 0)
									{
										printf("c2z_int.c c2_int_3 field12 Not Found = %s\n",field12);
										printf("c2z_int.c c2_int_3 rct = %d p_string = %s",rct,p_string);
										c2_debug();
										exit(1);
									}
							}

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
								strcpy(gw_variable[gv_ct].gv_cname, field5a);	
      								strcpy(gw_variable[gv_ct].gv_name, field5);  	
								if(fd5_type == 1)
									{
										strcpy(gw_variable[gv_ct].gv_type, "C");
									}  
								if(fd5_type == 2)
									{	
										strcpy(gw_variable[gv_ct].gv_type, "I");
									}
								gw_variable[gv_ct].gv_lgth = 0;
								gw_variable[gv_ct].gv_current_lgth = x4;
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
								strcpy(lw_variable[lv_ct].lv_cname, field5a);	
      								strcpy(lw_variable[lv_ct].lv_name, field5);  	
								if(fd5_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
									}  
								if(fd5_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
									}
								lw_variable[lv_ct].lv_lgth = x4;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field7, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(field7, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
									}
							}
					}

				ret = strcmp("char", field6);
				if(ret == 0)
					{
						fd7_type = 1;		
					}
				else
					{
						fd7_type = 2;		
					}

				if((x3 == 0) && (fd7_type == 2))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field7a, c_wkname);

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
								strcpy(gw_variable[gv_ct].gv_cname, field7a);	
      								strcpy(gw_variable[gv_ct].gv_name, field7);  	
								if(fd7_type == 1)
									{
										strcpy(gw_variable[gv_ct].gv_type, "C");
									}  
								if(fd7_type == 2)
									{	
										strcpy(gw_variable[gv_ct].gv_type, "I");
									}
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
								strcpy(lw_variable[lv_ct].lv_cname, field7a);	
      								strcpy(lw_variable[lv_ct].lv_name, field7);  	
								if(fd7_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
									}  
								if(fd7_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
									}
								lw_variable[lv_ct].lv_lgth = 0;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field9, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
							}
					}

				if(x3 == 0)
					{
						for(I=0; I < gv_ct; I++)
							{
								ret = strcmp(field9, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
									}
							}
					}

				ret = strcmp("char", field6);
				if(ret == 0)
					{
						fd9_type = 1;		
					}
				else
					{
						fd9_type = 2;		
					}

				if((x3 == 0) && (fd9_type == 2))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field9a, c_wkname);

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
								strcpy(gw_variable[gv_ct].gv_cname, field9a);	
      								strcpy(gw_variable[gv_ct].gv_name, field9);  	
								if(fd9_type == 1)
									{
										strcpy(gw_variable[gv_ct].gv_type, "C");
									}  
								if(fd9_type == 2)
									{	
										strcpy(gw_variable[gv_ct].gv_type, "I");
									}
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
								strcpy(lw_variable[lv_ct].lv_cname, field9a);	
      								strcpy(lw_variable[lv_ct].lv_name, field9);  	
								if(fd9_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
									}  
								if(fd9_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
									}
								lw_variable[lv_ct].lv_lgth = 0;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				x3 = 0;
				for(I=0; I < lv_ct; I++)
					{
						ret = strcmp(field11, lw_variable[I].lv_name);
						ret1 = strcmp(sv_func, lw_variable[I].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
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
									}
							}
					}

				ret = strcmp("char", field6);
				if(ret == 0)
					{
						fd11_type = 1;		
					}
				else
					{
						fd11_type = 2;		
					}

				if((x3 == 0) && (fd9_type == 2))
					{
						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(field11a, c_wkname);

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
								strcpy(gw_variable[gv_ct].gv_cname, field11a);	
      								strcpy(gw_variable[gv_ct].gv_name, field11);  	
								if(fd11_type == 1)
									{
										strcpy(gw_variable[gv_ct].gv_type, "C");
									}  
								if(fd11_type == 2)
									{	
										strcpy(gw_variable[gv_ct].gv_type, "I");
									}
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
								strcpy(lw_variable[lv_ct].lv_cname, field11a);	
      								strcpy(lw_variable[lv_ct].lv_name, field11);  	
								if(fd11_type == 1)
									{
										strcpy(lw_variable[lv_ct].lv_type, "C");
									}  
								if(fd11_type == 2)
									{	
										strcpy(lw_variable[lv_ct].lv_type, "I");
									}
								lw_variable[lv_ct].lv_lgth = 0;
								strcpy(lw_variable[lv_ct].lv_value, "0");
								lw_variable[lv_ct].lv_current_lgth = 0;
								lw_variable[lv_ct].lv_init = 0;
								strcpy(lw_variable[lv_ct].lv_literal,null_field);
								strcpy(lw_variable[lv_ct].lv_func, sv_func);
								lw_variable[lv_ct].lv_use_ct = 0;
								lw_variable[lv_ct].lv_dec = 0;
								lv_ct++;
							}
					}

				for(I = 0; I < fn_ct; I++)
					{
						ret = strcmp(field1, w_function[I].fn_name);
						if(ret == 0)
							{
								w_function[I].fn_start = rct;
								strcpy(w_function[I].fn_fd1,field3);
								strcpy(w_function[I].fn_fd2,field5);
								strcpy(w_function[I].fn_fd3,field7);
								strcpy(w_function[I].fn_fd4,field9);
								strcpy(w_function[I].fn_fd5,field11);

							}
					}

				convert = 1;
			}

	}


void c2_int_4()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_int.c c2_int_4");
				trace_rec_1();
			}

		char ch;
		char tfield1[VAR_LGTH];

		int pi;
		int pi2;
		int I = 0;
		int x3 = 0;
		int s = 0;
		int size = 0;
		int ret = 0;
		int ret1 = 0;

		pi = 0;
		ch = p_string[pi];
		while(ch != '(')
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
		while(ch != ',')
			{
				tfield1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield1[pi2] = '\0';

		c_name++;
		snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
		strcpy(c_wkname, "FD");
		strcat(c_wkname, wk_strg);
		s = strlen(c_wkname);
		c_wkname[s] = '\0';

		if(global_st == 0)		/* global variable	*/
			{
				x3 = 0;
				if(gv_ct > 0)
					{
						for(I = 0; I < gv_ct; I++)
							{
								ret  = strcmp(tfield1, gw_variable[I].gv_name);
								if(ret == 0)
									{
										x3 = 1;
									}
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
						strcpy(gw_variable[gv_ct].gv_cname, c_wkname);	
						strcpy(gw_variable[gv_ct].gv_name, tfield1);  	             
						strcpy(gw_variable[gv_ct].gv_type, "I");
						gw_variable[gv_ct].gv_lgth = 0;
						gw_variable[gv_ct].gv_current_lgth = 0;
						strcpy(gw_variable[gv_ct].gv_value, null_field);
						gw_variable[gv_ct].gv_init = 0;
						strcpy(gw_variable[gv_ct].gv_literal, null_field);
						gw_variable[gv_ct].gv_use_ct = 0;
						gw_variable[gv_ct].gv_dec = 0;
						gv_ct++;
					}
			}

		if(global_st == 1)		/* locsl variable	*/
			{
				x3 = 0;
				if(lv_ct > 0)
					{
						for(I = 0; I < lv_ct; I++)
							{
								ret  = strcmp(tfield1, lw_variable[I].lv_name);
								ret1 = strcmp(sv_func, lw_variable[I].lv_func);
								if((ret == 0) && (ret1 == 0))
									{
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
						strcpy(lw_variable[lv_ct].lv_cname, c_wkname);	
						strcpy(lw_variable[lv_ct].lv_name, tfield1);  	             
						strcpy(lw_variable[lv_ct].lv_type, "I");
						lw_variable[lv_ct].lv_lgth = 0;
						lw_variable[lv_ct].lv_current_lgth = 0;
						strcpy(lw_variable[lv_ct].lv_value, null_field);
						lw_variable[lv_ct].lv_init = 0;
						strcpy(lw_variable[lv_ct].lv_literal, null_field);
						strcpy(lw_variable[lv_ct].lv_func, sv_func);
						lw_variable[lv_ct].lv_use_ct = 0;
						lw_variable[lv_ct].lv_dec = 0;
						lv_ct++;
					}
			}

		convert = 1;
	 				
	}

void c2_int_5()			/*  INT IV_STACK[MAX_VALUE]	 int iv_stack[5]	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_int.c c2_int_5");
				trace_rec_1();
			}

		char ch;
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];

		int fd2_type = 0;
		int pi;
		int pi2;
		int x3 = 0;
		int s = 0;
		int v = 0;
		int fd_found = 0;
		int z3 = 0;
		int size = 0;
		int ret = 0;
		int ret1 = 0;
		
		tot_malloc++;
		
		pi2 = 0;
		pi = 0;
		ch = wk_fdwk[pi];
		while(ch != '[')
			{
				if(ch != ' ')
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

		pi2 = 0;
		fd_found = 0;
		pi++; 
		ch = wk_fdwk[pi];
		while(ch != '\0')
			{
				if(fd_found == 0)
					{
						if(isdigit(ch))
							{
								fd2_type = 1;
								fd_found = 1;
							}
						if(isalpha(ch))
							{
								fd2_type = 2;
								fd_found = 1;
							}
					}
				if(ch != '[') 
					{
						if(ch != ']')
							{
								field2[pi2] = ch;
								pi2++;
							}
					}
				
				pi++;
				ch = wk_fdwk[pi];
			}
		field2[pi2] = '\0';

		if(fd2_type == 1)		/* field2 is numeric ex:  234 */
			{
				x3 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field1, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
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
								strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
								strcpy(gw_variable[gv_ct].gv_name, field1);  	             
								strcpy(gw_variable[gv_ct].gv_type, "G");
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

								/* number of rows in the **array		*/
								gw_variable[gv_ct].gv_row = atoi(field2); 
				
								snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
								strcpy(wk_string, "A37");
								strcat(wk_string, wk_strg);
								strcat(wk_string, "A");
								strcpy(gw_variable[gv_ct].gv_aname,wk_string);
								gv_ct++;

								c_name++;
								snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
								strcpy(c_wkname, "C37F");
								strcat(c_wkname, wk_strg);
								s = strlen(c_wkname);
								c_wkname[s] = '\0';

								/* add this wk_string to w_variable as type = B */
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
								gv_ct++;
							}
					}	

				convert = 1;

			}	

		if(fd2_type == 2)		/* field2 is alpha ex:  [BUFSIZE]  */
			{
				z3 = 0;
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field2, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								z3 = 1;
								strcpy(field2a, lw_variable[v].lv_value);
								lw_variable[v].lv_use_ct++;	
							}
					}
	
				if(z3 == 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field2, gw_variable[v].gv_name);
								if(ret == 0)
									{
										z3 = 1;
										strcpy(field2a, gw_variable[v].gv_value);
										gw_variable[v].gv_use_ct++;
									}
							}
					}

				if(z3 == 0)
					{
						printf("error in c2_int_2\n");
						exit(1);
					}
		
				if(global_st == 0)		/*	global variable	*/
					{
						z3 = 0;
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field1, gw_variable[v].gv_name);
								if(ret == 0)
									{
										z3 = 1;
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
								strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
								strcpy(gw_variable[gv_ct].gv_name, field1);  	             
								strcpy(gw_variable[gv_ct].gv_type, "G");
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

								/* number of rows in the **array		*/
								gw_variable[gv_ct].gv_row = atoi(field2a); 
				
								snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
								strcpy(wk_string, "A37");
								strcat(wk_string, wk_strg);
								strcat(wk_string, "A");
								strcpy(gw_variable[gv_ct].gv_aname,wk_string);
								gv_ct++;

								c_name++;
								snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
								strcpy(c_wkname, "C37F");
								strcat(c_wkname, wk_strg);
								s = strlen(c_wkname);
								c_wkname[s] = '\0';

								/* add this wk_string to w_variable as type = B */
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
								gv_ct++;
							}
					}	
			}	
	}

/* *************************************************** 
*  Punch out int during Pass 3                       *
* ************************************************** */
void c2_int_punch()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_int.c c2_int_punch");
				trace_rec_1();
			}

		int x = 0;
		int pi;
		int pi2;

		char ch;
		char *p3, *p5, *p6, *p8;		

		p3 = strstr(p_string,",");
		p6 = strstr(p_string, "(");
						 				
		int II = 0;
		int u1 = 0;

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

		bracket_ct = 0;
					
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
		p8 = strstr(field1,"void");
		if(p8)
			{
				op_code = 1;
			}

		p8 = strstr(field1,"int");
		if((p8) && (op_code != 1))
			{
				op_code = 2;
			}

/* ***********************************
*  op_code                           * 
*	1	= 	VOID            *
*	2	=	INT             *
* ********************************** */	

		p3 = strchr(p_string, ')');
		p6 = strchr(p_string, '(');

		if((!p3) && (!p6) && (op_code == 2))
			{
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
											}
										pi++;
										ch = p_string[pi];
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

						p5 = strstr(wk_fdwk,"[");
						if(p5)
							{
								bracket_ct = 1;
								c2_int_punch_2();
							}
						else
							{
								c2_int_punch_1();
							}
					}
	}
						
	
void c2_int_punch_1()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_int.c c2_int_punch_1");
				trace_rec_1();
			}

		int x2 = 0;
		int x3 = 0;
		int v = 0;
		int ret = 0;
		int ret1 = 0;
		int fd2_type = 0;
		int pi;
		int pi2;

		char ch;
		char *p8;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];

		equal_found = 0;
		p8 = strstr(wk_fdwk,"=");
		if(p8)
			{
				equal_found = 1;
			}

		if(equal_found == 0)
			{
				pi = 0;
				pi2 = 0;
				ch = wk_fdwk[pi];
				while(ch != '\0')
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
						printf("c2_int_punch_1 tfield1 Not Found = %s\n",tfield1);
						printf("c2_int_punch_1 rct = %d p_string = %s",rct,p_string);	
						c2_debug();		
						exit(1); 
					}

				strcpy(a_string, "         LARL  R9,");
				strcat(a_string, tfield1a);
				strcpy(wk_remark, " ");
				strcat(wk_remark, tfield1);
				strcat(wk_remark, " */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_int.c c2_int_punch_1 #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,C370ZERO");
				strcpy(wk_remark, " C370ZERO */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_int.c c2_int_punch_1 #2");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_int.c c2_int_punch_1 #3");
						trace_rec_3();
					}

				convert = 1;

			}

		if(equal_found == 1)
			{
				pi = 0;
				pi2 = 0;
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

				x2 = 0;
				pi2 = 0;
				pi++;
				ch = wk_fdwk[pi];
				while(ch != '\0')
					{
						if(x2 == 0)
							{
								if(isdigit(ch))
									{
										fd2_type = 1;
										x2 = 1;
									}
								if(isalpha(ch))
									{
										fd2_type = 2;
										x2 = 1;
									}
							}
						tfield2[pi2] = ch;
						pi2++;
						pi++;
						ch = wk_fdwk[pi];
					}
				tfield2[pi2] = '\0';

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
						printf("c2_int_punch_1 E-243 tfield1 Not Found = %s\n",tfield1);
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
						strcpy(trace_1, "c2z_int.c c2_int_punch_1 #4");
						trace_rec_3();
					}

				if(fd2_type == 2)
					{
						x3 = 0;
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

						if(x3 == 0)
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

						if(x3 == 0)
							{		
								printf("c2_int_punch_1 E-244 tfield2 Not Found = %s\n",tfield2);
								c2_error();
							}

						strcpy(a_string, "         LARL  R8,");
						strcat(a_string, tfield2a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, tfield2);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_int.c c2_int_punch_1 #5");
								trace_rec_3();
							}
						work_use_ct[32]++;
					}

				if(fd2_type == 1)
					{
						for(v=0; v < lit_ct; v++)
							{
								if((rct == w_literal[v].lit_rct) && (w_literal[v].lit_uct == 1))
									{
										ret = strcmp(tfield1, w_literal[v].lit_name);
										if(ret == 0)
											{
												strcpy(a_string, "         LARL  R8,");
												strcat(a_string, w_literal[v].lit_use_cname);
												strcpy(wk_remark, " ");
												strcat(wk_remark, w_literal[v].lit_name);
												strcat(wk_remark, " */");
												write_remark();
												if(punch_code == 1)
													{
														strcpy(trace_1, "c2z_int.c c2_int_punch_1 #6");
														trace_rec_3();
													}
												work_use_ct[32]++;
												break;
											}
									}
							}
					}

				strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2z_int.c c2_int_punch_1 #7");
						trace_rec_3();
					}

				convert = 1;
			}
	}


void c2_int_punch_2()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_int.c c2_int_punch_2");
				trace_rec_1();
			}

		char ch;

		 int pi;
		 int pi2;
		 int fd2_type = 0;
		 int wk_type1 = 0;
		 int wk_type3 = 0;
		 int ret = 0;
		 int ret1 = 0;
		 int x3 = 0;
		 int v = 0;
		 int I = 0;

		int fd_found = 0;
				
		char wk_store2[10];
		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2[VAR_LGTH];
		char field2a[VAR_LGTH];

		pi2 = 0;
		pi = 0;
		ch = wk_fdwk[pi];
		while(ch != '[')
			{
				if(ch != ' ')
					{
						field1[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = wk_fdwk[pi];
			}
		field1[pi2] = '\0';	

		x3 = 0;
		if(lv_ct > 0)
			{
				for(v = 0; v < lv_ct; v++)
					{
						ret = strcmp(field1, lw_variable[v].lv_name);
						ret1 = strcmp(sv_func, lw_variable[v].lv_func);
						if((ret == 0) && (ret1 == 0))
							{
								x3 = 1;
								strcpy(field1a, lw_variable[v].lv_cname);
								lw_variable[v].lv_use_ct++;
							}
					}
			}

		if(x3 == 0)
			{
				if(gv_ct > 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field1, gw_variable[v].gv_name);
								if(ret == 0)
									{
										x3 = 1;
										strcpy(field1a, gw_variable[v].gv_cname);
										gw_variable[v].gv_use_ct++;
									}
							}
					}
			}

		pi2 = 0;
		fd_found = 0;
		pi++;
		ch = wk_fdwk[pi];
		while(ch != ']')
			{
				if(fd_found == 0)
					{
						if(isdigit(ch))
							{
								fd2_type = 1;
								fd_found = 1;
							}
						if(isalpha(ch))
							{
								fd2_type = 2;
								fd_found = 1;
							}
					}

				field2[pi2] = ch;
				pi2++;
				pi++;
				ch = wk_fdwk[pi];
			}
		field2[pi2] = '\0';

		if(fd2_type == 1)		/* field2 is numeric ex:  234 */
			{
				x3 = 0;
				
				ret = strcmp("0",field2);
				if(ret != 0)
					{
						for(I=0; I < lit_ct; I++)
							{
								if((rct == w_literal[I].lit_rct) && (w_literal[I].lit_uct == 1))
									{
										ret = strcmp(field1, w_literal[I].lit_name);
										if(ret == 0)
											{
												strcpy(field2a, w_literal[I].lit_cname);
											} 
									}
							}
					}

				if(bracket_ct == 0)
					{
						strcpy(a_string, "         LARL  R9,");
						strcat(a_string, field1a);
						strcpy(wk_remark, " ");
						strcat(wk_remark, field1);
						strcat(wk_remark, " */");
						write_remark();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_int.c pass 3 c2_int_punch_2 #1");
								trace_rec_3();
							}
								
						ret = strcmp("0",field2);
						if(ret == 0)
							{
								strcpy(field2a, "C370ZERO");
								strcpy(a_string, "         LARL  R8,");
								strcat(a_string, field2a);
								strcpy(wk_remark, " ");
								strcat(wk_remark, "C370ZERO */");
								write_remark();
								if(punch_code == 1)
									{
										strcpy(trace_1, "c2z_int.c pass 3 c2_int_punch_2 #2");
										trace_rec_3();
									}
								work_use_ct[32]++;

							}
						else
							{
								x3 = 0;
								for(I=0; I < lit_ct; I++)
									{
										if((rct == w_literal[I].lit_rct) && (w_literal[I].lit_uct == 1))
											{
												x3 = 1;
												strcpy(field2a, w_literal[I].lit_use_cname);
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
										strcpy(trace_1, "c2z_int.c pass 3 c2_int_punch_2 #3");
										trace_rec_3();
									}
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_int.c pass 3 c2_int_punch_2 #4");
								trace_rec_3();
							}
					}			
								
				convert = 1;

			}	
	
		if(fd2_type == 2)		/* field2 is alpha ex:  BUFSIZE */
			{
				if(bracket_ct != 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field2, gw_variable[v].gv_name);
								if(ret == 0)
									{
										strcpy(wk_store2, gw_variable[v].gv_value);
									}
							}
														
			 			for(v = 0; v < gv_ct; v++)
							{
								ret = strcmp(field1, gw_variable[v].gv_name);
								if(ret == 0)
									{
										x3 = 1;
									}
							}
						convert = 1;
					}

				if(bracket_ct == 0)
					{
						wk_type3 = 0;
						for(v = 0; v < lv_ct; v++)
							{
								wk_type1 = strcmp(field2, lw_variable[v].lv_name);
								ret1 = strcmp(sv_func, lw_variable[v].lv_func);
								if((wk_type1 == 0) && (ret1 == 0))
									{
										strcpy(field2a, lw_variable[v].lv_cname);
										lw_variable[v].lv_use_ct++;
										wk_type3 = 1;
									}
							}

						if(wk_type3 == 0)
							{
								for(v = 0; v < gv_ct; v++)
									{
										wk_type1 = strcmp(field2, gw_variable[v].gv_name);
										if(wk_type1 == 0)
											{
												strcpy(field2a, gw_variable[v].gv_cname);
												gw_variable[v].gv_use_ct++;
												wk_type3 = 1;
											}
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
								strcpy(trace_1, "c2z_int.c pass 3 c2_int_punch_2 #5");
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
								strcpy(trace_1, "c2z_int.c pass 3 c2_int_punch_2 #6");
								trace_rec_3();
							}

						strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
						src_line();
						if(punch_code == 1)
							{
								strcpy(trace_1, "c2z_int.c pass 3 c2_int_punch_2 #8");
								trace_rec_3();
							}
					}
			}	
			
		convert = 1;
		
	}



void c2_int_6()		/*  int *temp_byte;	*/
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_int.c 2 c2_int_6 ");
				trace_rec_1();
			}

		char ch;
		char tfield1[VAR_LGTH];
		char tfield2[VAR_LGTH];
		char tfield2a[VAR_LGTH];

		int s = 0;
		int v = 0;
		int z3 = 0;
		int size = 0;
		int pi;
		int pi2;		
		int ret = 0;
				
		tfield2a[0] = '\0';

		tot_malloc++;
		
		pi = 0;
		ch = p_string[pi];
		while((ch == ' ') || (ch == '\t'))
			{
				pi++;
				ch = p_string[pi];
			}

		pi2 = 0;
		ch = p_string[pi];
		while(ch != ' ')
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
		while(ch != ';')
			{
				if(ch != '*')
					{
						tfield2[pi2] = ch;
						pi2++;
					}
				pi++;
				ch = p_string[pi];
			}
		tfield2[pi2] = '\0';

		c_name++;
		snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
		strcpy(c_wkname, "C37F");
		strcat(c_wkname, wk_strg);
		s = strlen(c_wkname);
		c_wkname[s] = '\0';
		strcpy(tfield2a, c_wkname);

		if(global_st == 0)		/*	global variable	*/
			{
				z3 = 0;
				for(v = 0; v < gv_ct; v++)
					{
						ret = strcmp(tfield1, gw_variable[v].gv_name);
						if(ret == 0)
							{
								z3 = 1;
							}
					}
						
				if(z3 == 0)
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
						strcpy(gw_variable[gv_ct].gv_cname, tfield2a);
						strcpy(gw_variable[gv_ct].gv_name, tfield2);  	             
						strcpy(gw_variable[gv_ct].gv_type, "G");
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

						/* number of rows in the **array		*/
						gw_variable[gv_ct].gv_row = array_rows; 
				
						snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
						strcpy(wk_string, "A37");
						strcat(wk_string, wk_strg);
						strcat(wk_string, "A");
						strcpy(gw_variable[gv_ct].gv_aname,wk_string);

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
						gv_ct++;

						convert = 1;
					}

			}	

	}
		

