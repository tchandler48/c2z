/* ***************************************************
*  c2z : c2z_isupper.c :                             *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */

void c2_isupper()
	{
		int s = 0;
		int x3 = 0;
		int v = 0;
		int size = 0;
		int ret = 0;

		c_name++;
		snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
		strcpy(c_wkname, "C37F");
		strcat(c_wkname, wk_strg);
		s = strlen(c_wkname);
		c_wkname[s] = '\0';
				
		x3 = 0;
		for(v = 0; v < gv_ct; v++)
			{
				ret = strcmp("ISUPPER", gw_variable[v].gv_name);
				if(ret == 0)
					x3 = 1;
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
      				strcpy(gw_variable[gv_ct].gv_name, "ISUPPER");  	             
				strcpy(gw_variable[gv_ct].gv_type, "F");
				gw_variable[gv_ct].gv_lgth = 0;
				gw_variable[gv_ct].gv_current_lgth = 0;
				strcpy(gw_variable[gv_ct].gv_value, null_field);
				gw_variable[gv_ct].gv_init = 0;
				strcpy(gw_variable[gv_ct].gv_literal,null_field);
				gw_variable[gv_ct].gv_use_ct = 0;
				gw_variable[gv_ct].gv_dec = 0;
				gv_ct++;
			}
				
		strcpy(a_string, "*");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #1");
				trace_rec_3();
			}

		strcpy(a_string, "ISUPPER  DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #2");
				trace_rec_3();
			}
				
		strcpy(a_string, "         LARL  R9,C370ISRG");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #3");
				trace_rec_3();
			}
		var_use[11]++;
		
		strcpy(a_string, "         ST    C370LNK,0(R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #4");
				trace_rec_3();
			}
		work_use_ct[61]++;

		strcpy(a_string, "         LARL  R9,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #5");
				trace_rec_3();
			}
		work_use_ct[59]++;

		strcpy(a_string, "         LARL  R8,C370UCA");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #6");
				trace_rec_3();
			}
		work_use_ct[35]++;

		strcpy(a_string, "         MVC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #7");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #8");
				trace_rec_3();
			}
		work_use_ct[2]++;

		strcpy(a_string, "         LARL  R8,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #9");
				trace_rec_3();
			}
		work_use_ct[59]++;

		strcpy(a_string, "         CLC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #10");
				trace_rec_3();
			}
		work_use_ct[59]++;

		strcpy(a_string, "         JLE   ISU01");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #11");
				trace_rec_3();
			}

		strcpy(a_string, "         JLH   ISU01");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #12");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   ISU02");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #13");
				trace_rec_3();
			}

		strcpy(a_string, "ISU01    DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #14");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #15");
				trace_rec_3();
			}
		work_use_ct[59]++;

		strcpy(a_string, "         LARL  R8,C370UCZ");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #16");
				trace_rec_3();
			}
		work_use_ct[59]++;
		work_use_ct[36]++;

		strcpy(a_string, "         MVC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #17");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #18");
				trace_rec_3();
			}
		work_use_ct[2]++;

		strcpy(a_string, "         LARL  R8,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #19");
				trace_rec_3();
			}
		work_use_ct[59]++;

		strcpy(a_string, "         CLC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #20");
				trace_rec_3();
			}
		
		strcpy(a_string, "         JLE   ISU03");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #21");
				trace_rec_3();
			}

		strcpy(a_string, "         JLL   ISU03");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #22");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   ISU02");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #23");
				trace_rec_3();
			}

		strcpy(a_string, "ISU03    DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #24");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370ISAL");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #25");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370ONE");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #26");
				trace_rec_3();
			}
		work_use_ct[33]++;

		strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #27");
				trace_rec_3();
			}
				
		strcpy(a_string, "         JLU   ISU04");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #28");
				trace_rec_3();
			}

		strcpy(a_string, "ISU02    DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #29");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370ISAL");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #30");
				trace_rec_3();
			}
	
		strcpy(a_string, "         LARL  R8,C370ZERO");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #31");
				trace_rec_3();
			}
		work_use_ct[32]++;

		strcpy(a_string, "        ZAP   0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #32");
				trace_rec_3();
			}
		work_use_ct[1]++;

		strcpy(a_string, "ISU04    DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #33");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370ISRG");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #34");
				trace_rec_3();
			}
		
		strcpy(a_string, "         L     C370LNK,0(,R9)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #35");
				trace_rec_3();
			}

		strcpy(a_string, "         BR    C370LNK");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isupper.c c2_isupper #36");
				trace_rec_3();
			}

	}


