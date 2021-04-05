/* ***************************************************
*  c2z  : c2z_isdigit.c :                            *
*                                                    *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */
void c2_isdigit(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit");
    trace_rec_1();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1)
  {
    trace_rec_3();
  }

  strcpy(a_string, "ISDIGIT  DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #1");
    trace_rec_3();
  }
  var_use[10]++;

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #4");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         LARL  R8,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "czz_isdigit.c c2_isdigit #5");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #6");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ISN02");
  strcpy(wk_remark, " Blank Char */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #7");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #8");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         LARL  R8,C370LZER");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #9");
    trace_rec_3();
  }
  work_use_ct[62]++;

  strcpy(a_string, "         MVC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #10");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #11");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R8,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #12");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #13");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ISN01");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #14");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   ISN01");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #15");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ISN02");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #16");
    trace_rec_3();
  }

  strcpy(a_string, "ISN01    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #17");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #18");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         LARL  R8,C370LNIN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #19");
    trace_rec_3();
  }
  work_use_ct[63]++;

  strcpy(a_string, "         MVC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #20");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #21");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R8,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #22");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         CLC   R9,R8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #23");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ISN03");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #24");
    trace_rec_3();
  }

  strcpy(a_string, "         JLL   ISN03");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #25");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ISN02");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #26");
    trace_rec_3();
  }

  strcpy(a_string, "ISN03    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #27");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370DIGT");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #28");
    trace_rec_3();
  }
  work_use_ct[80]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #29");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #30");
    trace_rec_3();
  }
  work_use_ct[31]++;

  strcpy(a_string, "         JLU   ISN04");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #31");
    trace_rec_3();
  }

  strcpy(a_string, "ISN02    DS    0H");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #32");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370DIGT");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #33");
    trace_rec_3();
  }
  work_use_ct[80]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #34");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #35");
    trace_rec_3();
  }
  work_use_ct[31]++;

  strcpy(a_string, "ISN04    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #36");
    trace_rec_3();
  }

  strcpy(a_string, "         PR");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isdigit.c c2_isdigit #39");
    trace_rec_3();
  }
}
