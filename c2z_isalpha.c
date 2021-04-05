/* ***************************************************
*  c2z : c2_isaplha.c                                *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */

/* *************************************************** 
*  Punch out isalpha                                 *
* ************************************************** */
void c2_isalpha()
	{
		strcpy(a_string, "*");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #1");
				trace_rec_3();
			}

		strcpy(a_string, "ISALPHA  DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #2");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #3");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370UCA");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #4");
				trace_rec_3();
			}
		work_use_ct[35]++;

              strcpy(a_string, "         MVC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #5");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #6");
				trace_rec_3();
			}
		work_use_ct[59]++;

		strcpy(a_string, "         LARL  R8,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #7");
				trace_rec_3();
			}

		strcpy(a_string, "         CLC   ");
		strcat(a_string, "0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #8");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ISA01");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #9");
				trace_rec_3();
			}

		strcpy(a_string, "         JLH   ISA01");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #10");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   ISA02");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #11");
				trace_rec_3();
			}

		strcpy(a_string, "ISA01    DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #12");
				trace_rec_3();
			}
	
		strcpy(a_string, "         LARL  R9,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #13");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370UCZ");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #14");
				trace_rec_3();
			}
		work_use_ct[36]++;

 		strcpy(a_string, "         MVC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #15");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #16");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #17");
				trace_rec_3();
			}

		strcpy(a_string, "         CLC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #18");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ISA03");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #19");
				trace_rec_3();
			}

		strcpy(a_string, "         JLL   ISA03");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #20");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   ISA02");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #21");
				trace_rec_3();
			}

		strcpy(a_string, "ISA03    DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #22");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370ISAL");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #23");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370ONE");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #24");
				trace_rec_3();
			}
		work_use_ct[33]++;

		strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #25");
				trace_rec_3();
			}
				
		strcpy(a_string, "         JLU   ISA04");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #26");
				trace_rec_3();
			}

		strcpy(a_string, "ISA02    DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #27");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #28");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370LCA");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #29");
				trace_rec_3();
			}
		work_use_ct[37]++;

 		strcpy(a_string, "         MVC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #30");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #31");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #32");
				trace_rec_3();
			}

		strcpy(a_string, "         CLC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #33");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ISA05");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #34");
				trace_rec_3();
			}

		strcpy(a_string, "         JLH   ISA05");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #35");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   ISA06");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #36");
				trace_rec_3();
			}

		strcpy(a_string, "ISA05    DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #37");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #38");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370LCZ");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #39");
				trace_rec_3();
			}
		work_use_ct[38]++;

 		strcpy(a_string, "         MVC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #40");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370L1");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #41");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370L1A");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #42");
				trace_rec_3();
			}

		strcpy(a_string, "         CLC   0(1,R9),0(R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #43");
				trace_rec_3();
			}

		strcpy(a_string, "         JLE   ISA03");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #44");
				trace_rec_3();
			}

		strcpy(a_string, "         JLL   ISA03");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #45");
				trace_rec_3();
			}

		strcpy(a_string, "         JLU   ISA06");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #46");
				trace_rec_3();
			}

		strcpy(a_string, "ISA06    DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #47");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R9,C370ISAL");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #48");
				trace_rec_3();
			}

		strcpy(a_string, "         LARL  R8,C370ZERO");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #49");
				trace_rec_3();
			}
		work_use_ct[32]++;

		strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #50");
				trace_rec_3();
			}
		
		strcpy(a_string, "ISA04    DS    0H");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #51");
				trace_rec_3();
			}

		strcpy(a_string, "         BR    C370LNK");
		src_line();
		if(punch_code == 1)
			{
				strcpy(trace_1, "c2z_isalpha.c c2_isalpha #52");
				trace_rec_3();
			}
	}
