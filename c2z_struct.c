/* ***************************************************
*  c2z : c2z_struct.c :                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

void c2z_struct(void)
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_struct.c c2z_struct");
	 trace_rec_1();
     }

     char *p2, *p3, *p4, *p5, *p6, *p7;
     char ch;
     char tfield2[VAR_LGTH];
     char tfield2a[VAR_LGTH];
     char tfield4[VAR_LGTH];
     char tfield5[VAR_LGTH];
     char tfield8a[VAR_LGTH];
		
      int pi;
      int pi2;
      int v = 0;
      int ret1 = 0;
      int x2 = 0;
      int x3 = 0;
      int x4 = 0;
      int x20 = 0;
      int x90 = 0;
      int size = 0;
      int I = 0;
      int ret = 0;
      int fd5_type = 0;
printf("c2z_struct rct = %d p_string = %s",rct,p_string);
		
 /*     p7 = strstr(p_string, "*");
      if(p7)
      {
         convert = 1;
         return;
      } */

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
		
      ch = p_string[pi];
      while(ch == ' ')
      {
         pi++;
         ch = p_string[pi];
      }

      x2 = strlen(p_string);
      pi2 = 0;
      while(isalnum(ch))   
      {
        
         tfield2[pi2] = ch;
         pi2++;
         pi++;
         ch = p_string[pi];
         if(ch == '_')
         {
            tfield2[pi2] = ch;
            pi2++;
            pi++;
            ch = p_string[pi];
         }
      }
      tfield2[pi2] = '\0';
printf("c2z_struc #1 tfield2 = %s\n",tfield2);

		p2 = strstr(p_string, ";");
		if(p2)
			{
				goto struct_1;
			}

		c_name++;
		snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
		strcpy(c_wkname, "C37F");
		strcat(c_wkname, wk_strg);
		x4 = strlen(c_wkname);
		c_wkname[x4] = '\0';
		strcpy(tfield2a, c_wkname);

		if(m_struc_ct == 0)
			{
				size = 1;
				w_struc = malloc(size * sizeof(struct m_struc));
			}
		else
			{
				size = m_struc_ct + 1;
				w_struc = realloc(w_struc, size * sizeof(struct m_struc));
			}

		w_struc[m_struc_ct].st_rct = rct;
		strcpy(w_struc[m_struc_ct].st_name, tfield2);
		strcpy(w_struc[m_struc_ct].st_id, "M");	
		w_struc[m_struc_ct].st_disp = 0;
      		strcpy(w_struc[m_struc_ct].st_wname, tfield2);  
		strcpy(w_struc[m_struc_ct].st_cname, tfield2a);
		strcpy(w_struc[m_struc_ct].st_cwname, null_field);	
      		strcpy(w_struc[m_struc_ct].st_func, null_field);  
		strcpy(w_struc[m_struc_ct].st_type, null_field);
		strcpy(w_struc[m_struc_ct].st_field_name, null_field);
		strcpy(w_struc[m_struc_ct].st_field_cname, null_field);
              w_struc[m_struc_ct].st_field_lgth = 0;	
      		strcpy(w_struc[m_struc_ct].st_field_value, null_field);  
		m_struc_ct++;

		goto struct_2;

/* *********************************************************
*  parse the following: struct variables    *gw_variables  *
* ******************************************************** */
		struct_1:

		x2 = 0;
		p2 = strstr(p_string, "/*");
		
		p3 = strstr(p_string, "*");
		if(p3)
			{
				x2 = p3 - p_string;
			}

		ch = p_string[pi];
		while(ch != '*')
			{
				pi++; 
				ch = p_string[pi];
			}

		pi2 = 0;
		pi++;
		ch = p_string[pi];
		while(ch != ';')
			{
				tfield5[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			}
		tfield5[pi2] = '\0';

		c_name++;
		snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
		strcpy(c_wkname, "C37F");
		strcat(c_wkname, wk_strg);
		x4 = strlen(c_wkname);
		c_wkname[x4] = '\0';
		strcpy(tfield8a, c_wkname);

		x3 = 0;
		for(I=0; I < m_struc_ct; I++)
			{
				ret = strcmp(tfield2, w_struc[I].st_name);
				if(ret == 0)
					{
						x3 = 1;
						strcpy(w_struc[I].st_wname, tfield5); 
						strcpy(w_struc[I].st_cwname, tfield8a);
					}
			}

		if(x3 == 0)
			{
				printf("c2z_struct.c c2_struc tfield2 Not Found = %s\n",tfield2);
				printf("c2z_struct.c c2_struc rct = %d p_string = %s\n",rct,p_string);
				c2_debug();
				exit(1);
			}

		convert = 1;
		return;
				
/* **************************************************
*  detail records for structures			  *
*************************************************** */			
		struct_2:


		fgets(p_string, 255, pgm); 
		rct++;

		p7 = strstr(p_string, "};");
		if(p7)
			{
				goto struct_3;
			}

		p6 = strstr(p_string, "{");
		if(p6)
			{	
				goto struct_2;
			}

		p5 = strstr(p_string, "int");
		p4 = strstr(p_string, "char");

		if(p5)
			{
				p2 = strstr(p_string, "[");
				p3 = strstr(p_string, "]");
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
				
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				if((!p2) && (!p3))
					{
						pi2 = 0;
						while(ch != ';')
							{
								tfield4[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						tfield4[pi2] = '\0';

						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(tfield8a, c_wkname);

						if(m_struc_ct == 0)
							{
								size = 1;
								w_struc = malloc(size * sizeof(struct m_struc));
							}
						else
							{
								size = m_struc_ct + 1;
								w_struc = realloc(w_struc, size * sizeof(struct m_struc));
							}

						w_struc[m_struc_ct].st_rct = rct;
						strcpy(w_struc[m_struc_ct].st_id, "N");
						w_struc[m_struc_ct].st_disp = x90;
						strcpy(w_struc[m_struc_ct].st_name, tfield2);	
      						strcpy(w_struc[m_struc_ct].st_wname, tfield2);  
						strcpy(w_struc[m_struc_ct].st_cname, tfield2a);	
                                          strcpy(w_struc[m_struc_ct].st_cwname, null_field);	
						strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
						strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      						strcpy(w_struc[m_struc_ct].st_func, null_field);  
						strcpy(w_struc[m_struc_ct].st_type, "I");
						w_struc[m_struc_ct].st_field_lgth = 0;	
      						strcpy(w_struc[m_struc_ct].st_field_value, null_field);  
						m_struc_ct++;

						x90 = x90 + 4;
					}
			}

		if(p4)
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
				
				while(ch == ' ')
					{
						pi++;
						ch = p_string[pi];
					}

				p2 = strstr(p_string, "[");
				p3 = strstr(p_string, "]");
				if((!p2) && (!p3))
					{
						pi2 = 0;
						while(ch != ';')
							{
								tfield4[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						tfield4[pi2] = '\0';
					}

				if((p2) && (p3))
					{
						pi2 = 0;
						while(ch != '[')
							{
								tfield4[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						tfield4[pi2] = '\0';

						pi2 = 0;
						x2 = 0;
						pi++;
						ch = p_string[pi];
						while(ch != ']')
							{
								if(x2 == 0)
									{
										if(isdigit(ch))
											{
												fd5_type = 1;
												x2 = 1;
											}

										if(isalpha(ch))
											{
												fd5_type = 2;
												x2 = 1;
											}
									}
								tfield5[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						tfield5[pi2] = '\0';

						c_name++;
						snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
						strcpy(c_wkname, "C37F");
						strcat(c_wkname, wk_strg);
						x4 = strlen(c_wkname);
						c_wkname[x4] = '\0';
						strcpy(tfield8a, c_wkname);

						if(m_struc_ct == 0)
							{
								size = 1;
								w_struc = malloc(size * sizeof(struct m_struc));
							}
						else
							{
								size = m_struc_ct + 1;
								w_struc = realloc(w_struc, size * sizeof(struct m_struc));
							}

						w_struc[m_struc_ct].st_rct = rct;
						strcpy(w_struc[m_struc_ct].st_id, "N");
						w_struc[m_struc_ct].st_disp = x90;
						strcpy(w_struc[m_struc_ct].st_name, tfield2);	
      						strcpy(w_struc[m_struc_ct].st_wname, tfield2);  
						strcpy(w_struc[m_struc_ct].st_cname, tfield2a);	
                                          strcpy(w_struc[m_struc_ct].st_cwname, null_field);	
						strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
						strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      						strcpy(w_struc[m_struc_ct].st_func, null_field);  
						strcpy(w_struc[m_struc_ct].st_type, "C");
						if(fd5_type == 1)
							{
								w_struc[m_struc_ct].st_field_lgth = atoi(tfield5);
								x20 = atoi(tfield5);
								w_struc[m_struc_ct].st_field_cur_lgth = atoi(tfield5);
							}

						if(fd5_type == 2)
							{
								x3 = 0;
								for(v = 0; v < lv_ct; v++)
									{
										ret = strcmp(tfield5, lw_variable[v].lv_name);
										ret1 = strcmp(sv_func, lw_variable[v].lv_func);
										if((ret == 0) && (ret1 == 0))
											{
												x3 = 1;
												x20 = atoi(lw_variable[v].lv_value);
											}
									}

								if(x3 == 0)
									{
										for(v = 0; v < gv_ct; v++)
											{
												ret = strcmp(tfield5, gw_variable[v].gv_name);
												if(ret == 0)
													{
														x3 = 1;
														x20 = atoi(gw_variable[v].gv_value);
													}
											}
									}

								w_struc[m_struc_ct].st_field_lgth = x20;
								w_struc[m_struc_ct].st_field_cur_lgth = x20;
							}
	
      						strcpy(w_struc[m_struc_ct].st_field_value, null_field);  
						m_struc_ct++;

						x90 = x90 + x20;
					}
			}

		goto struct_2;

		struct_3:

		for(I=0; I < m_struc_ct; I++)
			{
				ret = strcmp(tfield2, w_struc[I].st_name);
				ret1 = strcmp(w_struc[I].st_id, "M");
				if((ret == 0) && (ret1 == 0))
					{
						w_struc[I].st_field_lgth = x90;
					}
			}

		convert = 1;
				
		return;
	}


void c2_struct_3(void)
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_struct.c c2_struct_3");
				trace_rec_1();
			}

		char *p7;
		
		p7 = strstr(p_string, ";");
		if(p7)
			{
				return;
			}

		struct_10:

		fgets(p_string, 255, pgm); 
		rct++;

		p7 = strstr(p_string, "};");
		if(p7)
			{
				return;
			}
		goto struct_10;
	}

