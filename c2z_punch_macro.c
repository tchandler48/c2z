/* ***************************************************
*  c2  : c2_punch_macro.c :                          *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */


/* ***************************************************
*  Punch eoj macors                                  *
* ************************************************** */
void c2_punch_eoj()
	{

		int wh_4 = 0;
		int I = 0;


	

/* **************************************
*  punch out isspace if var_use[16]     *
* ************************************* */

		if(var_use[16] > 0)			/* strlen		*/
			{
				if(trace_flag == 1)
					{
						strcpy(trace_1, "c2_punch_eoj strlen");
						trace_rec_1();
					}

				int v = 0;
				
				/*  test for tfield1 compiler name	*/
								
				if(gv_ct > 0)
					{
						for(v = 0; v < gv_ct; v++)
							{
								wh_4 = strcmp("STRLEN", gw_variable[v].gv_name);
								if(wh_4 == 0)
									{				
										strcpy(field1a, gw_variable[v].gv_cname);
										gw_variable[I].gv_use_ct++;
									}
							}
					}

				strcpy(a_string, "*");
				src_line();
				if(punch_code == 1)
					trace_rec_3();

				strcpy(a_string, "STRLEN   DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #1");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370LNK");
                            strcpy(wk_remark, " addr C370LNK */");
                            write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #2");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R8,");
				strcat(a_string, field1a);
                            strcpy(wk_remark, " ");
				strcat(wk_remark, "STRLEN cname */");
                            write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #3");
						trace_rec_3();
					}

				strcpy(a_string, "         ST    ");
                            strcat(a_string, "R9,0(R8)");
				strcpy(wk_remark, " store ret */");
				write_remark();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #4");
						trace_rec_3();
					}

				strcpy(a_string, "SZ10     DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #5");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #6");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ZERO");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #7");
						trace_rec_3();
					}
				work_use_ct[32]++;

				strcpy(a_string, "         CP    0(4,R9),0(4,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #8");
						trace_rec_3();
					}

				strcpy(a_string, "         JLE   SZ199");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #9");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370U");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #11");
						trace_rec_3();
					}
				work_use_ct[47]++;

				strcpy(a_string, "         LARL  R8,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #12");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #13");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370U");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #14");
						trace_rec_3();
					}
				work_use_ct[48]++;

				strcpy(a_string, "         CVB   R5,0(7,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #15");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370L80");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #17");
						trace_rec_3();
					}
				work_use_ct[48]++;

				strcpy(a_string, "         IC    R0,0(R9,(R5))");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #18");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #19");
						trace_rec_3();
					}
				work_use_ct[2]++;

				strcpy(a_string, "         STC   R0,0(0,R9)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #20");
						trace_rec_3();
					}
	
				strcpy(a_string, "         LARL  R9,C370L1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #21");
						trace_rec_3();
					}
				work_use_ct[2]++;

				strcpy(a_string, "         LARL  R8,C370PER");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #22");
						trace_rec_3();
					}
				work_use_ct[61]++;

				strcpy(a_string, "         CLC   0(1,R9),0(R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #23");
						trace_rec_3();
					}
				
				strcpy(a_string, "         JE    ");
				strcat(a_string, "SZ199");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #24");
						trace_rec_3();
					}
    
				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #25");
						trace_rec_3();
					}
				work_use_ct[49]++;
	
				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #26");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         SP    0(4,R9),0(4,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #27");
						trace_rec_3();
					}

				strcpy(a_string, "         JLU   SZ10");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #28");
						trace_rec_3();
					}

				strcpy(a_string, "SZ199");
				check_length();
				strcat(a_string, "DS    0H");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #29");
						trace_rec_3();
					}

				strcpy(a_string, "         LARL  R9,C370NWK1");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #30");
						trace_rec_3();
					}
				work_use_ct[49]++;

				strcpy(a_string, "         LARL  R8,C370ONE");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #31");
						trace_rec_3();
					}
				work_use_ct[33]++;

				strcpy(a_string, "         SP    0(4,R9),0(4,R8)");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #32");
						trace_rec_3();
					}

				strcpy(a_string, "         BR    C370LNK");
				src_line();
				if(punch_code == 1)
					{
						strcpy(trace_1, "c2_punch_macro strlen #33");
						trace_rec_3();
					}
			
			}


	}	/* end of c2_punch_macro	*/


	