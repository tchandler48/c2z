/* ***************************************************
*  c2z : c2_pass_1.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* *************************************************** 
*  Scan for FUNCTION                                 *
* ************************************************** */
void scan_func_name_1()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_pass_1.c c2_scan_func_name_1");
			}

		int size = 0;
		int pi;
		int pi2;
		int x4;

		char ch;
		char *p, *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;

		char field1[VAR_LGTH];
		char field1a[VAR_LGTH];
		char field2a[VAR_LGTH];
		char field3a[VAR_LGTH];
		char field4a[VAR_LGTH];
		char field5a[VAR_LGTH];
		
		convert = 0;
		field1[0] = '\0';

		p = strstr(p_string, "void");
		p1 = strstr(p_string, ";");
		p2 = strchr(p_string, '(');
		p3 = strchr(p_string, ')');
		p4 = strstr(p_string, "int");
		p5 = strstr(p_string, "print");
		p6 = strstr(p_string, "char");
		p7 = strstr(p_string, "(void)");
		
		if((p7) && (p2) && (p3) && (p6))
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_1.c c2_scan_sub CHAR - VOID");
					}

				pi = 0;
				ch = p_string[pi];
				while((ch == ' ') || (ch == '\t')) 
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
				while(ch != '(')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

				c_name++;			/* function compiler name	*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field1a, "C37F");
				strcat(field1a, wk_strg);
				x4 = strlen(field1a);
				field1a[x4] = '\0';

				c_name++;			/* function sv_reg_1		*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field2a, "C37F");
				strcat(field2a, wk_strg);
				x4 = strlen(field2a);
				field2a[x4] = '\0';

				c_name++;			/* function sv_reg_2		*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field3a, "C37F");
				strcat(field3a, wk_strg);
				x4 = strlen(field3a);
				field3a[x4] = '\0';

				c_name++;			/* function fn_loop		*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field4a, "C37F");
				strcat(field4a, wk_strg);
				x4 = strlen(field4a);
				field4a[x4] = '\0';

				if(fn_ct == 0)
					{
						size = 1;
						w_function = malloc(size * sizeof(struct functions));
					}
				else
					{
						size = fn_ct + 1;
						w_function = realloc(w_function, size * sizeof(struct functions));
					}

				w_function[fn_ct].fn_rct = rct;	
      				strcpy(w_function[fn_ct].fn_name, field1);
				strcpy(w_function[fn_ct].fn_cname, field1a);
				strcpy(w_function[fn_ct].fn_sv_reg_1, field2a);
				strcpy(w_function[fn_ct].fn_sv_reg_2, field3a);
				strcpy(w_function[fn_ct].fn_loop, field4a);
				w_function[fn_ct].fn_level = 0;
                          	w_function[fn_ct].fn_return = 0; 
				strcpy(w_function[fn_ct].fn_fd1, null_field);
				strcpy(w_function[fn_ct].fn_fd2, null_field);
				strcpy(w_function[fn_ct].fn_fd3, null_field);
				strcpy(w_function[fn_ct].fn_fd4, null_field);
				strcpy(w_function[fn_ct].fn_fd5, null_field);
				strcpy(w_function[fn_ct].fn_fd6, null_field);
				strcpy(w_function[fn_ct].fn_fd7, null_field);
				strcpy(w_function[fn_ct].fn_fd8, null_field);
				strcpy(w_function[fn_ct].fn_fd9, null_field);
				strcpy(w_function[fn_ct].fn_loop_use,field5a);
				w_function[fn_ct].fn_eof = 0; 
				w_function[fn_ct].fn_pass_1 = 0;
				w_function[fn_ct].fn_pass_2 = 0;
				w_function[fn_ct].fn_pass_3 = 0;
				w_function[fn_ct].fn_pass_4 = 0;
				w_function[fn_ct].fn_pass_5 = 0;
				w_function[fn_ct].fn_pass_6 = 0;
				w_function[fn_ct].fn_pass_7 = 0;
				w_function[fn_ct].fn_pass_8 = 0;
				w_function[fn_ct].fn_pass_9 = 0;

				p8 = strstr(p_string, "(int");
				if(p8)
					{
					 	w_function[fn_ct].fn_pass_1 = 1;
					}
				
				p8 = strstr(p_string, "int)");
				if(p8)
					{
						w_function[fn_ct].fn_pass_2 = 1;
					}	
				
				p8 = strstr(p_string, "(char");
				if(p8)
					{
						w_function[fn_ct].fn_pass_1 = 2;
					}
	
				fn_ct++;
 					
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
				strcpy(gw_variable[gv_ct].gv_cname, field2a);	
				strcpy(gw_variable[gv_ct].gv_name, field2a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

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
				strcpy(gw_variable[gv_ct].gv_name, field3a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

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
				strcpy(gw_variable[gv_ct].gv_name, field4a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "I");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 1;
				gv_ct++;

				convert = 1;

				return;
			}

		if((p) && (p1)) 	/* void a_bort(int, int);		*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_1.c c2_scan_sub VOID 2 - int");
					}

				pi = 0;
				ch = p_string[pi];
				while((ch == ' ') || (ch == '\t')) 
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
				while(ch != '(')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

				c_name++;			/* function compiler name	*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field1a, "C37F");
				strcat(field1a, wk_strg);
				x4 = strlen(field1a);
				field1a[x4] = '\0';

				c_name++;			/* function sv_reg_1		*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field2a, "C37F");
				strcat(field2a, wk_strg);
				x4 = strlen(field2a);
				field2a[x4] = '\0';

				c_name++;			/* function sv_reg_2		*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field3a, "C37F");
				strcat(field3a, wk_strg);
				x4 = strlen(field3a);
				field3a[x4] = '\0';

				c_name++;			/* function fn_loop		*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field4a, "C37F");
				strcat(field4a, wk_strg);
				x4 = strlen(field4a);
				field4a[x4] = '\0';

				if(fn_ct == 0)
					{
						size = 1;
						w_function = malloc(size * sizeof(struct functions));
					}
				else
					{
						size = fn_ct + 1;
						w_function = realloc(w_function, size * sizeof(struct functions));
					}

				w_function[fn_ct].fn_rct = rct;	
      				strcpy(w_function[fn_ct].fn_name, field1);
				strcpy(w_function[fn_ct].fn_cname, field1a);
				strcpy(w_function[fn_ct].fn_sv_reg_1, field2a);
				strcpy(w_function[fn_ct].fn_sv_reg_2, field3a);
				strcpy(w_function[fn_ct].fn_loop, field4a);
				w_function[fn_ct].fn_level = 0;
                          	w_function[fn_ct].fn_return = 0; 
				strcpy(w_function[fn_ct].fn_fd1, null_field);
				strcpy(w_function[fn_ct].fn_fd2, null_field);
				strcpy(w_function[fn_ct].fn_fd3, null_field);
				strcpy(w_function[fn_ct].fn_fd4, null_field);
				strcpy(w_function[fn_ct].fn_fd5, null_field);
				strcpy(w_function[fn_ct].fn_fd6, null_field);
				strcpy(w_function[fn_ct].fn_fd7, null_field);
				strcpy(w_function[fn_ct].fn_fd8, null_field);
				strcpy(w_function[fn_ct].fn_fd9, null_field);
				strcpy(w_function[fn_ct].fn_loop_use,field5a);
				w_function[fn_ct].fn_eof = 0; 
				w_function[fn_ct].fn_pass_1 = 0;
				w_function[fn_ct].fn_pass_2 = 0;
				w_function[fn_ct].fn_pass_3 = 0;
				w_function[fn_ct].fn_pass_4 = 0;
				w_function[fn_ct].fn_pass_5 = 0;
				w_function[fn_ct].fn_pass_6 = 0;
				w_function[fn_ct].fn_pass_7 = 0;
				w_function[fn_ct].fn_pass_8 = 0;
				w_function[fn_ct].fn_pass_9 = 0;

				p8 = strstr(p_string, "(int");
				if(p8)
					{
					 	w_function[fn_ct].fn_pass_1 = 1;
					}
				
				p8 = strstr(p_string, "int)");
				if(p8)
					{
						w_function[fn_ct].fn_pass_2 = 1;
					}	
				
				p8 = strstr(p_string, "(char");
				if(p8)
					{
						w_function[fn_ct].fn_pass_1 = 2;
					}
	
				fn_ct++;
 
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
				strcpy(gw_variable[gv_ct].gv_cname, field2a);	
				strcpy(gw_variable[gv_ct].gv_name, field2a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

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
				strcpy(gw_variable[gv_ct].gv_name, field3a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

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
				strcpy(gw_variable[gv_ct].gv_name, field4a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "I");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 1;
				gv_ct++;

				convert = 1;
			}

		p = strstr(p_string, "void");
		p1 = strstr(p_string, ";");
		p2 = strchr(p_string, '(');
		p3 = strchr(p_string, ')');
		p4 = strstr(p_string, "int");
		p5 = strstr(p_string, "print");

		if((p4) && (p2) && (p3) && (p1) && (!p5) && (convert == 0)) 	/* INT procedure INT get_upper(int, int);		*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2z_pass_1.c c2_scan_sub INT 2 - int");
					}

				pi = 0;
				ch = p_string[pi];
				while((ch == ' ') || (ch == '\t'))
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
				while(ch != '(')
					{
						field1[pi2] = ch;
						pi2++;
						pi++;
						ch = p_string[pi];
					}
				field1[pi2] = '\0';

				c_name++;			/* function compiler name	*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field1a, "C37F");
				strcat(field1a, wk_strg);
				x4 = strlen(field1a);
				field1a[x4] = '\0';

				c_name++;			/* function sv_reg_1		*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field2a, "C37F");
				strcat(field2a, wk_strg);
				x4 = strlen(field2a);
				field2a[x4] = '\0';

				c_name++;			/* function sv_reg_2		*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field3a, "C37F");
				strcat(field3a, wk_strg);
				x4 = strlen(field3a);
				field3a[x4] = '\0';

				c_name++;			/* function fn_loop		*/
				snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
				strcpy(field4a, "C37F");
				strcat(field4a, wk_strg);
				x4 = strlen(field4a);
				field4a[x4] = '\0';

				if(fn_ct == 0)
					{
						size = 1;
						w_function = malloc(size * sizeof(struct functions));
					}
				else
					{
						size = fn_ct + 1;
						w_function = realloc(w_function, size * sizeof(struct functions));
					}

				w_function[fn_ct].fn_rct = rct;	
      				strcpy(w_function[fn_ct].fn_name, field1);
				strcpy(w_function[fn_ct].fn_cname, field1a);
				strcpy(w_function[fn_ct].fn_sv_reg_1, field2a);
				strcpy(w_function[fn_ct].fn_sv_reg_2, field3a);
				strcpy(w_function[fn_ct].fn_loop, field4a);
				w_function[fn_ct].fn_level = 0;
				w_function[fn_ct].fn_return = 0; 
				strcpy(w_function[fn_ct].fn_fd1, null_field);
				strcpy(w_function[fn_ct].fn_fd2, null_field);
				strcpy(w_function[fn_ct].fn_fd3, null_field);
				strcpy(w_function[fn_ct].fn_fd4, null_field);
				strcpy(w_function[fn_ct].fn_fd5, null_field);
				strcpy(w_function[fn_ct].fn_fd6, null_field);
				strcpy(w_function[fn_ct].fn_fd7, null_field);
				strcpy(w_function[fn_ct].fn_fd8, null_field);
				strcpy(w_function[fn_ct].fn_fd9, null_field);
				strcpy(w_function[fn_ct].fn_loop_use,field5a);
				w_function[fn_ct].fn_eof = 0; 
				w_function[fn_ct].fn_pass_1 = 0;
				w_function[fn_ct].fn_pass_2 = 0;
				w_function[fn_ct].fn_pass_3 = 0;
				w_function[fn_ct].fn_pass_4 = 0;
				w_function[fn_ct].fn_pass_5 = 0;
				w_function[fn_ct].fn_pass_6 = 0;
				w_function[fn_ct].fn_pass_7 = 0;
				w_function[fn_ct].fn_pass_8 = 0;
				w_function[fn_ct].fn_pass_9 = 0;

				p8 = strstr(p_string, "(int");
				if(p8)
					{
					 	w_function[fn_ct].fn_pass_1 = 1;
					}
				
				p8 = strstr(p_string, "int)");
				if(p8)
					{
						w_function[fn_ct].fn_pass_2 = 1;
					}	
				
				p8 = strstr(p_string, "(char");
				if(p8)
					{
						w_function[fn_ct].fn_pass_1 = 2;
					}
				
				fn_ct++;
				
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
				strcpy(gw_variable[gv_ct].gv_cname, field2a);	
				strcpy(gw_variable[gv_ct].gv_name, field2a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

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
				strcpy(gw_variable[gv_ct].gv_name, field3a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 2;
				gv_ct++;

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
				strcpy(gw_variable[gv_ct].gv_name, field4a);  	             
				strcpy(gw_variable[gv_ct].gv_type, "I");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gw_variable[gv_ct].gv_id = 1;
				gv_ct++;

				convert = 1;
			}
	}



