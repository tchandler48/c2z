/* ***************************************************
*  c2z  : c2z_isalnum.c :                            *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

void c2_isalnum() 
{
  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #1");
    trace_rec_3();
  }

  strcpy(a_string, "ISALNUM  DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #2");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370ISAL");
  strcpy(wk_remark, " C370ISAL */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  strcpy(wk_remark, " C370ZERO */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #4");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #6");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #7");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #8");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #9");
    trace_rec_3();
  }
  strcpy(a_string, "*  Start test for TSTUC ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,37");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #10");
    trace_rec_3();
  }

  strcpy(a_string, "ALN01    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #11");
    trace_rec_3();
  }

/*  test tstuc */

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #12");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #13");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R7),2(4,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #14");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #15");
    trace_rec_3();
  }

  strcpy(a_string, "         CVB   R4,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #16");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,TSTUC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #17");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R7,(R4))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #18");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,C370L2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #19");
    trace_rec_3();
  }

  strcpy(a_string, "         STC   R0,0(0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #20");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R9),0(R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #21");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ALN03");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #22");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #23");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #24");
    trace_rec_3();
  }
 
  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #25");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R5,ALN01");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #26");
    trace_rec_3();
  }

  strcpy(a_string, "*  Start test for TSTLC ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #27");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #28");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #29");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #29a");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,37");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #30");
    trace_rec_3();
  }

  strcpy(a_string, "ALN02    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #31");
    trace_rec_3();
  }

/*  test tstlc */
  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #32");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #33");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R7),2(4,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #34");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #35");
    trace_rec_3();
  }

  strcpy(a_string, "         CVB   R4,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #36");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,TSTLC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #37");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R7,(R4))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #38");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,C370L2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #39");
    trace_rec_3();
  }

  strcpy(a_string, "         STC   R0,0(0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #40");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R9),0(R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #41");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ALN03");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #42");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #43");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #44");
    trace_rec_3();
  }
 
  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #45");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R5,ALN02");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #46");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ALN99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #47");
    trace_rec_3();
  }

  strcpy(a_string, "ALN03    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #48");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370ISAL");
  strcpy(wk_remark, " C370ISAL */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #49");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  strcpy(wk_remark, " C370ONE */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #50");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #51");
    trace_rec_3();
  }

  strcpy(a_string, "ALN99    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #52");
    trace_rec_3();
  }

  strcpy(a_string, "         PR");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c isalnum #53");
    trace_rec_3();
  }
}
