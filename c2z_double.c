/* ***************************************************
*  c2z : c2_double.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */

/* *************************************************** 
*  Scan test for DOUBLE                              *
**************************************************** */
void c2_double()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2_double");
				trace_rec_1();
			}

		int I = 0;
		int s = 0;
		int size = 0;
		int pi;
		int pi2;
		
		char ch;
		char *p, *p1, *p2;
		char tfield1[VAR_LGTH];
		char tfield1a[VAR_LGTH];
				
		p1 = strstr(p_string,"print");
		p2 = strstr(p_string,"main");
		p = strstr(p_string,"double");		

		if((p) && (!p1) && (!p2))
			{	
				tot_double++;
				pi = 0;
				s = strlen(p_string);	
				ch = p_string[pi];
				pi++;
						
				while((ch == ' ') || (ch == '\t'))		
					{
						ch = p_string[pi];
						pi++;	
					}

				while(ch != ' ')
					{
						ch = p_string[pi];
						pi++;
					}	

				skip = 0;
				pi2 = 0;
				ch = p_string[pi];
				for(I=pi; I < s; I++)
					{
						if((ch != ';') && (ch != ' ') && (skip != 1))
							{
								tfield1[pi2] = ch;
								pi2++;
								pi++;
								ch = p_string[pi];
							}
						else
							{
								skip = 1;
							}
					}
				tfield1[pi2] = '\0';

				if(ch != ';')
					skip = 1;

				if(skip == 1)
					{
						for(I=pi; I < s; I++)
							{
								if(ch != '=')
									{
										pi++;
										ch = p_string[pi];
									}
							}
										
						for(I=pi; I < s; I++)
							{
								if(ch == ' ')
									{
										pi++;
										ch = p_string[pi];
									}
							}
										
						pi++;
						ch = p_string[pi];
						while(ch != ';')
							{
								pi++;
								ch = p_string[pi];
							}
					}
					
					c_name++;
					snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
					strcpy(c_wkname, "C37F");
					strcat(c_wkname, wk_strg);
					s = strlen(c_wkname);
					c_wkname[s] = '\0';
					strcpy(tfield1a,c_wkname);
					
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
					strcpy(gw_variable[gv_ct].gv_type, "D");
					gw_variable[gv_ct].gv_lgth = 0;
					gw_variable[gv_ct].gv_dec = 0;
					gv_ct++;

					convert = 1;
				}	
	}
	
