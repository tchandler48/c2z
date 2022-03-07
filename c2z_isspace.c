/* ***************************************************
*  c2z : c2_isspace.c :                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch isspace                                     *
* ************************************************** */
void c2_isspace() 
{
  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #1");
    trace_rec_3();
  }

  strcpy(a_string, "ISSPACE  DS    0H");
  src_line();
  if (puncde == 1) {
    strcpy(trace_1, "c2z_isspace.c #2");
    trace_rec_3();
  }

  strcpy(a_string, "IS10     DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #4");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #5");
    trace_rec_3();
  }
  work_use_ct[74]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #6");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   IS190");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #7");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #9");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #10");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   IS190");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #11");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370ISAL");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #12");
    trace_rec_3();
  }
  work_use_ct[1]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #13");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #14");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   IS199");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #15");
    trace_rec_3();
  }

  strcpy(a_string, "IS190");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #16");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370ISAL");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #17");
    trace_rec_3();
  }
  work_use_ct[1]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #18");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #19");
    trace_rec_3();
  }

  strcpy(a_string, "IS199");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #20");
    trace_rec_3();
  }

  strcpy(a_string, "         PR");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isspace.c #21");
    trace_rec_3();
  }
}
