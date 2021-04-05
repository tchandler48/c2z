/* ***************************************************
*  c2z  : c2z_unsigned.c                             *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */

/* *************************************************** 
*  Scan test for unsigned                            *
**************************************************** */
void c2_unsigned()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_unsigned.c c2_unsigned");
				trace_rec_1();
			}

		int I = 0;
		int s = 0;
		int size = 0;
		int pi;
		int pi2;
		
		char ch;
		char tfield1[VAR_LGTH];
		
		var_use[19]++;
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

		c_name++;
		snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
		strcpy(c_wkname, "C37F");
		strcat(c_wkname, wk_strg);
		s = strlen(c_wkname);
		c_wkname[s] = '\0';
		
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
	      			strcpy(gw_variable[gv_ct].gv_name, tfield1);  	             
				strcpy(gw_variable[gv_ct].gv_type, "I");
				gw_variable[gv_ct].gv_lgth = 0;
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
				strcpy(lw_variable[lv_ct].lv_cname, c_wkname);
				strcpy(lw_variable[lv_ct].lv_name,tfield1);  	             
				strcpy(lw_variable[lv_ct].lv_type, "I");
				lw_variable[lv_ct].lv_lgth = 0;	
				lw_variable[lv_ct].lv_use_ct = 0;
				strcpy(lw_variable[lv_ct].lv_func, sv_func);
				lw_variable[lv_ct].lv_current_lgth = 0;
				lw_variable[lv_ct].lv_dec = 0;
				lw_variable[lv_ct].lv_id = 1;
				lv_ct++;
			}

		convert = 1;

	}
	
