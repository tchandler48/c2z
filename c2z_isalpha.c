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
    strcpy(trace_1, "c2z_isalpha.c #1");
    trace_rec_3();
  }

  strcpy(a_string, "ISALPHA  DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #2");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370ISAL");
  strcpy(wk_remark, " C370ISAL */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #3");
    trace_rec_3();
  }
  work_use_ct[1]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  strcpy(wk_remark, " C370ZERO */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #4");
    trace_rec_3();
  }
  work_use_ct[32]++;
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #6");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #7");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R7,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #8");
    trace_rec_3();
  }
  work_use_ct[32]++;
 
  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #9");
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
    strcpy(trace_1, "c2z_isalpha.c #10");
    trace_rec_3();
  }

  strcpy(a_string, "ISA01    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #11");
    trace_rec_3();
  }

/*  test tstuc */

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #12");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R6,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #13");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R7),2(4,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #14");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #15");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R4,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #16");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,TSTUC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #17");
    trace_rec_3();
  }
  work_use_ct[100]++;

  strcpy(a_string, "         IC    R0,0(R7,(R4))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #18");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,C370L2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #19");
    trace_rec_3();
  }
  work_use_ct[3]++;

  strcpy(a_string, "         STC   R0,0(0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #20");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R9),0(R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #21");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ISA03");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #22");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #23");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #24");
    trace_rec_3();
  }
  work_use_ct[33]++;
 
  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #25");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R5,ISA01");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #26");
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
    strcpy(trace_1, "c2z_isalpha.c #27");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R7,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #28");
    trace_rec_3();
  }
  work_use_ct[32]++;
 
  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #29");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,26");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #30");
    trace_rec_3();
  }

  strcpy(a_string, "ISA02    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #31");
    trace_rec_3();
  }

/*  test tstlc */
  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #32");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R6,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #33");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R7),2(4,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #34");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #35");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R4,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #36");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,TSTLC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #37");
    trace_rec_3();
  }
  work_use_ct[100]++;

  strcpy(a_string, "         IC    R0,0(R7,(R4))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #38");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,C370L2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #39");
    trace_rec_3();
  }
  work_use_ct[3]++;

  strcpy(a_string, "         STC   R0,0(0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #40");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R9),0(R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #41");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ISA03");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #42");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #43");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #44");
    trace_rec_3();
  }
  work_use_ct[33]++;
 
  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #45");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R5,ISA02");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #46");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ISA99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #47");
    trace_rec_3();
  }

  strcpy(a_string, "ISA03    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #48");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370ISAL");
  strcpy(wk_remark, " C370ISAL */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #49");
    trace_rec_3();
  }
  work_use_ct[1]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  strcpy(wk_remark, " C370ONE */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #50");
    trace_rec_3();
  }
  work_use_ct[33]++;
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #51");
    trace_rec_3();
  }

  strcpy(a_string, "ISA99    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #52");
    trace_rec_3();
  }

  strcpy(a_string, "         PR");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalpha.c #53");
    trace_rec_3();
  }
}
