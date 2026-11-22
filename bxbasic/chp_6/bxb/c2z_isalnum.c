/* ***************************************************
*  c2z  : c2z_isalnum.c :                            *
*                                                    *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

void c2_isalnum() 
{
  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #1");
    trace_rec_3();
  }

  strcpy(a_string, "ISALNUM  DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #2");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #6");
    trace_rec_3();
  }
  work_use_ct[74]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #7");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ALN06");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370XXX");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #6");
    trace_rec_3();
  }
  work_use_ct[72]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #7");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ALN06");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #9");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #10");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #11");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ALN06");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #12");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370PER");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #14");
    trace_rec_3();
  }
  work_use_ct[75]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #15");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ALN06");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #16");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #17");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370COLN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #18");
    trace_rec_3();
  }
  work_use_ct[81]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #19");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ALN06");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #20");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #21");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         LARL  R8,C370UCA");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #22");
    trace_rec_3();
  }
  work_use_ct[35]++;

  strcpy(a_string, "         MVC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #23");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #24");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R8,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #25");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #26");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         JLE   ALN01");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #27");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   ALN01");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #28");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ALN02");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #29");
    trace_rec_3();
  }

  strcpy(a_string, "ALN01    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #30");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #31");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         LARL  R8,C370UCZ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #32");
    trace_rec_3();
  }
  work_use_ct[36]++;

  strcpy(a_string, "         MVC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #33");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #34");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R9,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #35");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #36");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         JLE   ALN03");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #37");
    trace_rec_3();
  }

  strcpy(a_string, "         JLL   ALN03");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #38");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ALN02");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #39");
    trace_rec_3();
  }

  strcpy(a_string, "ALN03    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #40");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370ISAL");
  strcpy(wk_remark, " C370ISAL */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #41");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  strcpy(wk_remark, " C370ONE */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #42");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #43");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ALN04");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #44");
    trace_rec_3();
  }

  strcpy(a_string, "ALN02    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #45");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #46");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         LARL  R8,C370LCA");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #47");
    trace_rec_3();
  }
  work_use_ct[37]++;

  strcpy(a_string, "         MVC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #48");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #49");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R9,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #50");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #51");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         JLE   ALN05");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #52");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   ALN05");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #53");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ALN06");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #54");
    trace_rec_3();
  }

  strcpy(a_string, "ALN05    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #55");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #56");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         LARL  R8,C370LCZ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #57");
    trace_rec_3();
  }
  work_use_ct[38]++;

  strcpy(a_string, "         MVC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #58");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #59");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R9,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #60");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #61");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         JLE   ALN03");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #62");
    trace_rec_3();
  }

  strcpy(a_string, "         JLL   ALN03");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #63");
    trace_rec_3();
  }

  strcpy(a_string, "ALN06    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #64");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370ISAL");
  strcpy(wk_remark, " C370ISAL */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #65");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  strcpy(wk_remark, " C370ZERO */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #66");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #67");
    trace_rec_3();
  }

  strcpy(a_string, "ALN04    DS    0H");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #68");
    trace_rec_3();
  }

  strcpy(a_string, "         PR");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isalnum.c c2_isalnum #71");
    trace_rec_3();
  }
}
