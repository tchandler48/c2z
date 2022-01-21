/* ***************************************************
*  c2z : c2_isaplha.c                                *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out isalpha                                 *
* ************************************************** */
void c2_isalpha() 
{
  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #1");
    trace_rec_3();
  }

  strcpy(a_string, "ISALPHA  DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #2");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370ISAL");
  strcpy(wk_remark, " C370ISAL */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #3");
    trace_rec_3();
  }
  work_use_ct[1]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  strcpy(wk_remark, " C370ZERO */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #4");
    trace_rec_3();
  }
  work_use_ct[32]++;
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #6");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #7");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R7,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #8");
    trace_rec_3();
  }
  work_use_ct[32]++;
 
  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #9");
    trace_rec_3();
  }
  strcpy(a_string, "*  Start test for TSTUC ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,26");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #10");
    trace_rec_3();
  }

  strcpy(a_string, "ISA01    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #11");
    trace_rec_3();
  }

/*  test tstuc */

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #12");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R6,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #13");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R7),2(4,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #14");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #15");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R4,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #16");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,TSTUC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #17");
    trace_rec_3();
  }
  work_use_ct[100]++;

  strcpy(a_string, "         IC    R0,0(R7,(R4))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #18");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,C370L2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #19");
    trace_rec_3();
  }
  work_use_ct[3]++;

  strcpy(a_string, "         STC   R0,0(0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #20");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R9),0(R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #21");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ISA03");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #22");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #23");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #24");
    trace_rec_3();
  }
  work_use_ct[33]++;
 
  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #25");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R5,ISA01");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #26");
    trace_rec_3();
  }

  strcpy(a_string, "*  Start test for TSTLC ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #27");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R7,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #28");
    trace_rec_3();
  }
  work_use_ct[32]++;
 
  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #29");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,26");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #30");
    trace_rec_3();
  }

  strcpy(a_string, "ISA02    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #31");
    trace_rec_3();
  }

/*  test tstlc */
  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #32");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R6,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #33");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R7),2(4,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #34");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #35");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R4,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #36");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,TSTLC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #37");
    trace_rec_3();
  }
  work_use_ct[100]++;

  strcpy(a_string, "         IC    R0,0(R7,(R4))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #38");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,C370L2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #39");
    trace_rec_3();
  }
  work_use_ct[3]++;

  strcpy(a_string, "         STC   R0,0(0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #40");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R9),0(R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #41");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ISA03");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #42");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #43");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #44");
    trace_rec_3();
  }
  work_use_ct[33]++;
 
  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #45");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R5,ISA02");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #46");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ISA99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #47");
    trace_rec_3();
  }

  strcpy(a_string, "ISA03    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #48");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370ISAL");
  strcpy(wk_remark, " C370ISAL */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #49");
    trace_rec_3();
  }
  work_use_ct[1]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  strcpy(wk_remark, " C370ONE */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #50");
    trace_rec_3();
  }
  work_use_ct[33]++;
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #51");
    trace_rec_3();
  }

  strcpy(a_string, "ISA99    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #52");
    trace_rec_3();
  }

  strcpy(a_string, "         PR");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c isalpha #53");
    trace_rec_3();
  }
}
