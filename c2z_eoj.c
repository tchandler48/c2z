/* ***************************************************
*  c2z : c2z_eoj.c :                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out EOJ code                                *
* ************************************************** */
void c2_eoj() 
{
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field4[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char w_address[5];

  int v = 0;
  int x = 0;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int x7 = 0;
  int x10 = 0;
  int ret = 0;
  int ret1 = 0;
  int I = 0;
  int II = 0;
  int s = 0;
  int p_ct = 0;
  int x99 = 0;

  if(zgui == 0)
  {
    strcpy(a_string, "*");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c wtoalpha #0");
      trace_rec_3();
    }

    strcpy(a_string, "WTOALPHA DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c wtoalpha #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c wtoalpha #2");
      trace_rec_3();
    }

    strcpy(a_string, "         WTO   MF=(E,0(R9))");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c wtoalpha #2");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c wtoalpha #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370WTOB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c wtoalpha #5");
      trace_rec_3();
    }

    strcpy(a_string, "         XC    0(132,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c wtoalpha #6");
      trace_rec_3();
    }

    strcpy(a_string, "         PR");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c wtoalpha #7");
      trace_rec_3();
    }
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoalpha #8");
    trace_rec_3();
  }

  /* ****************************************************
  *                                                     *
  *  WTOMVC Integer Numeric edit routine                *
  *                                                     *
  * *************************************************** */

  strcpy(a_string, "WTOIMVC  DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #2");
    trace_rec_3();
  }
  work_use_ct[71]++;

  strcpy(a_string, "         LARL  R8,C370B10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #3");
    trace_rec_3();
  }
  work_use_ct[69]++;

  strcpy(a_string, "         MVC   0(10,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #4");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #5");
    trace_rec_3();
  }
  work_use_ct[51]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #6");
    trace_rec_3();
  }
  work_use_ct[57]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #7");
    trace_rec_3();
  }

  strcpy(a_string, "         JLL   PNN10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #9");
    trace_rec_3();
  }
  work_use_ct[51]++;

  strcpy(a_string, "         LARL  R8,C370N3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #10");
    trace_rec_3();
  }
  work_use_ct[57]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #11");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   PRT2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #12");
    trace_rec_3();
  }

  strcpy(a_string, "PRT10    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtiomvc #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R5,C370DEC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #14");
    trace_rec_3();
  }
  work_use_ct[67]++;

  strcpy(a_string, "         LARL  R4,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #15");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         CP    0(6,R5),0(6,R4)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #16");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   DEC1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #17");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PN2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #18");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #19");
    trace_rec_3();
  }
  work_use_ct[51]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #20");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDW2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #21");
    trace_rec_3();
  }
  work_use_ct[54]++;

  strcpy(a_string, "         LARL  R8,C370EDW2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #22");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(4,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #23");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDW2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #24");
    trace_rec_3();
  }
  work_use_ct[54]++;

  strcpy(a_string, "         LARL  R8,C370PN2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #25");
    trace_rec_3();
  }

  strcpy(a_string, "         ED    0(4,R9),4(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtiomvc #26");
    trace_rec_3();
  }
  work_use_ct[25]++;
  work_use_ct[29]++;

  strcpy(a_string, "         LARL  R9,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #27");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370TDW2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #28");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(4,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #29");
    trace_rec_3();
  }
  work_use_ct[9]++;
  work_use_ct[25]++;

  strcpy(a_string, "         JLU   PRT99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #30");
    trace_rec_3();
  }

  strcpy(a_string, "DEC1     DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #31");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PN2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #32");
    trace_rec_3();
  }
  work_use_ct[29]++;

  strcpy(a_string, "         LARL  R8,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #33");
    trace_rec_3();
  }
  work_use_ct[51]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #34");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370DEC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #35");
    trace_rec_3();
  }
  work_use_ct[67]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #36");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #37");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   DEC11");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #38");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370DEC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #39");
    trace_rec_3();
  }
  work_use_ct[67]++;

  strcpy(a_string, "         LARL  R8,C370TWO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #40");
    trace_rec_3();
  }
  work_use_ct[34]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #41");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   DEC12");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #42");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370DEC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #43");
    trace_rec_3();
  }
  work_use_ct[67]++;

  strcpy(a_string, "         LARL  R8,C370THR");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #44");
    trace_rec_3();
  }
  work_use_ct[12]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #45");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   DEC13");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #46");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370DEC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #47");
    trace_rec_3();
  }
  work_use_ct[67]++;

  strcpy(a_string, "         LARL  R8,C370FOUR");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #48");
    trace_rec_3();
  }
  work_use_ct[13]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #49");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   DEC14");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #50");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370DEC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #51");
    trace_rec_3();
  }
  work_use_ct[67]++;

  strcpy(a_string, "         LARL  R8,C370FIVE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #52");
    trace_rec_3();
  }
  work_use_ct[24]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #53");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   DEC15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #54");
    trace_rec_3();
  }

  strcpy(a_string, "DEC11    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #55");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDD2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #56");
    trace_rec_3();
  }
  work_use_ct[28]++;

  strcpy(a_string, "         LARL  R8,C370DDW2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #57");
    trace_rec_3();
  }
  work_use_ct[31]++;

  strcpy(a_string, "         MVC   0(5,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #58");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDD2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #59");
    trace_rec_3();
  }
  work_use_ct[28]++;

  strcpy(a_string, "         LARL  R8,C370PN2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #60");
    trace_rec_3();
  }

  strcpy(a_string, "         ED    0(5,R9),4(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #61");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #62");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370TDD2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #63");
    trace_rec_3();
  }
  work_use_ct[28]++;

  strcpy(a_string, "         MVC   0(5,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #64");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   PRT99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #65");
    trace_rec_3();
  }

  strcpy(a_string, "DEC12    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #66");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDD2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #67");
    trace_rec_3();
  }
  work_use_ct[28]++;

  strcpy(a_string, "         LARL  R8,C370D2DW");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #68");
    trace_rec_3();
  }
  work_use_ct[47]++;

  strcpy(a_string, "         MVC   0(5,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #69");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDD2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #70");
    trace_rec_3();
  }
  work_use_ct[28]++;

  strcpy(a_string, "         LARL  R8,C370PN2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #71");
    trace_rec_3();
  }

  strcpy(a_string, "         ED    0(6,R9),4(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #72");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #73");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370TDD2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #74");
    trace_rec_3();
  }
  work_use_ct[28]++;

  strcpy(a_string, "         MVC   0(5,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #75");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   PRT99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #76");
    trace_rec_3();
  }

  strcpy(a_string, "DEC13    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #77");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDD3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #78");
    trace_rec_3();
  }
  work_use_ct[60]++;

  strcpy(a_string, "         LARL  R8,C370D3DW");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #79");
    trace_rec_3();
  }
  work_use_ct[61]++;

  strcpy(a_string, "         MVC   0(6,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #80");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDD3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #81");
    trace_rec_3();
  }
  work_use_ct[60]++;

  strcpy(a_string, "         LARL  R8,C370PN2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #82");
    trace_rec_3();
  }

  strcpy(a_string, "         ED    0(6,R9),3(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #83");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #84");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370TDD3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #141");
    trace_rec_3();
  }
  work_use_ct[60]++;

  strcpy(a_string, "         MVC   0(6,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #141");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   PRT99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #142");
    trace_rec_3();
  }

  strcpy(a_string, "DEC14    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #153");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   PRT99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #157");
    trace_rec_3();
  }

  strcpy(a_string, "DEC15    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #158");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   PRT99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #162");
    trace_rec_3();
  }

  strcpy(a_string, "PRT2     DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #31");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #32");
    trace_rec_3();
  }
  work_use_ct[51]++;

  strcpy(a_string, "         LARL  R8,C370N5");
  src_line();
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #33");
    trace_rec_3();
  }
  work_use_ct[58]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "cz2_eoj.c wtoimvc #34");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   PRT30");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #35");
    trace_rec_3();
  }

  strcpy(a_string, "PRT20    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #36");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PN3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #37");
    trace_rec_3();
  }
  work_use_ct[30]++;

  strcpy(a_string, "         LARL  R8,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #38");
    trace_rec_3();
  }
  work_use_ct[51]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #39");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDW3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #36");
    trace_rec_3();
  }
  work_use_ct[55]++;

  strcpy(a_string, "         LARL  R8,C370EDW3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #40");
    trace_rec_3();
  }
  work_use_ct[26]++;

  strcpy(a_string, "         MVC   0(6,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #41");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDW3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #42");
    trace_rec_3();
  }
  work_use_ct[55]++;

  strcpy(a_string, "         LARL  R8,C370PN3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #43");
    trace_rec_3();
  }
  work_use_ct[30]++;

  strcpy(a_string, "         ED    0(6,R9),3(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #44");
    trace_rec_3();
  }
  work_use_ct[25]++;
  work_use_ct[29]++;

  strcpy(a_string, "         LARL  R9,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #45");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370TDW3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #46");
    trace_rec_3();
  }
  work_use_ct[55]++;

  strcpy(a_string, "         MVC   0(6,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #47");
    trace_rec_3();
  }
  work_use_ct[9]++;
  work_use_ct[25]++;

  strcpy(a_string, "         JLU   PRT99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #48");
    trace_rec_3();
  }

  strcpy(a_string, "PRT30    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #49");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDW4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #50");
    trace_rec_3();
  }
  work_use_ct[56]++;

  strcpy(a_string, "         LARL  R8,C370EDW4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #51");
    trace_rec_3();
  }
  work_use_ct[27]++;

  strcpy(a_string, "         MVC   0(10,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #52");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDW4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #53");
    trace_rec_3();
  }
  work_use_ct[56]++;

  strcpy(a_string, "         LARL  R8,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #54");
    trace_rec_3();
  }
  work_use_ct[51]++;

  strcpy(a_string, "         ED    0(9,R9),2(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #55");
    trace_rec_3();
  }
  work_use_ct[25]++;
  work_use_ct[29]++;

  strcpy(a_string, "         LARL  R9,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #56");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370TDW4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtiomvc #57");
    trace_rec_3();
  }
  work_use_ct[56]++;

  strcpy(a_string, "         MVC   0(9,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #58");
    trace_rec_3();
  }
  work_use_ct[9]++;
  work_use_ct[25]++;

  strcpy(a_string, "         JLU   PRT99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #59");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #60");
    trace_rec_3();
  }

  strcpy(a_string, "PNN10    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #61");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NN3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #62");
    trace_rec_3();
  }
  work_use_ct[65]++;

  strcpy(a_string, "         LARL  R8,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #63");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #64");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   PNN20");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #65");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PN2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #66");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #67");
    trace_rec_3();
  }
  work_use_ct[51]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #68");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDW5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #69");
    trace_rec_3();
  }
  work_use_ct[68]++;

  strcpy(a_string, "         LARL  R8,C370EDW5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #70");
    trace_rec_3();
  }
  work_use_ct[77]++;

  strcpy(a_string, "         MVC   0(5,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #71");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDW5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #72");
    trace_rec_3();
  }
  work_use_ct[68]++;

  strcpy(a_string, "         LARL  R8,C370PN2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #73");
    trace_rec_3();
  }

  strcpy(a_string, "         ED    0(5,R9),4(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #74");
    trace_rec_3();
  }
  work_use_ct[25]++;
  work_use_ct[29]++;

  strcpy(a_string, "         LARL  R9,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #75");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370TDW5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #76");
    trace_rec_3();
  }
  work_use_ct[68]++;

  strcpy(a_string, "         MVC   0(5,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #77");
    trace_rec_3();
  }
  work_use_ct[9]++;
  work_use_ct[25]++;

  strcpy(a_string, "         JLU   PRT99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #78");
    trace_rec_3();
  }

  strcpy(a_string, "PNN20    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #79");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NN5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #80");
    trace_rec_3();
  }
  work_use_ct[66]++;

  strcpy(a_string, "         LARL  R8,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #81");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #82");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   PNN30");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #83");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PN2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #84");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #85");
    trace_rec_3();
  }
  work_use_ct[51]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #86");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDW7");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #87");
    trace_rec_3();
  }
  work_use_ct[70]++;

  strcpy(a_string, "         LARL  R8,C370EDW7");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #88");
    trace_rec_3();
  }
  work_use_ct[83]++;

  strcpy(a_string, "         MVC   0(7,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #89");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDW7");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #90");
    trace_rec_3();
  }
  work_use_ct[70]++;

  strcpy(a_string, "         LARL  R8,C370PN2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #91");
    trace_rec_3();
  }

  strcpy(a_string, "         ED    0(7,R9),3(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #92");
    trace_rec_3();
  }
  work_use_ct[25]++;
  work_use_ct[29]++;

  strcpy(a_string, "         LARL  R9,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #93");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370TDW7");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #94");
    trace_rec_3();
  }
  work_use_ct[70]++;

  strcpy(a_string, "         MVC   0(7,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #95");
    trace_rec_3();
  }
  work_use_ct[9]++;
  work_use_ct[25]++;

  strcpy(a_string, "         JLU   PRT99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #96");
    trace_rec_3();
  }

  strcpy(a_string, "PNN30    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #97");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PN2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #98");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #99");
    trace_rec_3();
  }
  work_use_ct[51]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #100");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDW9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #101");
    trace_rec_3();
  }
  work_use_ct[76]++;

  strcpy(a_string, "         LARL  R8,C370EDW9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #102");
    trace_rec_3();
  }
  work_use_ct[84]++;

  strcpy(a_string, "         MVC   0(9,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #103");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TDW9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #104");
    trace_rec_3();
  }
  work_use_ct[76]++;

  strcpy(a_string, "         LARL  R8,C370PN2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #105");
    trace_rec_3();
  }

  strcpy(a_string, "         ED    0(8,R9),2(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #106");
    trace_rec_3();
  }
  work_use_ct[25]++;
  work_use_ct[29]++;

  strcpy(a_string, "         LARL  R9,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #107");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370TDW9");
  src_line();
  if (puncde == 1) {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #108");
    trace_rec_3();
  }
  work_use_ct[76]++;

  strcpy(a_string, "         MVC   0(9,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #109");
    trace_rec_3();
  }
  work_use_ct[9]++;
  work_use_ct[25]++;

  strcpy(a_string, "         JLU   PRT99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #110");
    trace_rec_3();
  }

  strcpy(a_string, "PRT99    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #111");
    trace_rec_3();
  }

  strcpy(a_string, "         PR");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c wtoimvc #112");
    trace_rec_3();
  }

  if (var_use[9] > 0) 
  {
    c2_isalpha();
  }

  if (var_use[10] > 0) 
  {
    c2_isdigit();
  }

  if (var_use[11] > 0) 
  {
    c2_isspace();
  }

  if (var_use[12] > 0) 
  {
    c2_isalnum();
  }


  if (var_use[16] > 0) 
  {
    c2_strlen_punch();
  }

  if (var_use[20] > 0) 
  {
    c2_isupper();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c");
    trace_rec_3();
  }

  if(fs_field_ct > 0)
  {
    for(II = 0; II < fs_field_ct; II++)
    {
/*
      printf("\nfs_fd_rct = %d\n",w_fs_field[II].fs_fd_rct);
      printf("fs_fd_map = %s\n",w_fs_field[II].fs_fd_map);
      printf("fs_fd_color = %s\n",w_fs_field[II].fs_fd_color);
*/

    }
  }
  
  x99 = 1;
  if(fs_map_ct > 0)
  {
    x3 = 0;
    I = 0;
    for (; I < fs_map_ct; I++) 
    {
      p_ct = 0;
      strcpy(a_string, w_fs_map[I].fs_name);
      strcat(a_string, "O");
      check_length();
      strcat(a_string, " DS    0C");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #9000");
        trace_rec_3();
      }

      strcpy(a_string, "          DC    X'27'");
      strcpy(wk_remark, " ");
      strcat(wk_remark, "ESCAPE CHAR");
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #9001");
        trace_rec_3();
      }

      strcpy(a_string, "          DC    X'F5'");
      strcpy(wk_remark, " ");
      strcat(wk_remark, "ERASE/WRITE");
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #9002");
        trace_rec_3();
      }

      strcpy(a_string, "          DC    X'C3'");
      strcpy(wk_remark, " ");
      strcat(wk_remark, "WCC");
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #9003");
        trace_rec_3();
      }

      while(p_ct < fs_field_ct)
      {
        x7 = 0;
        ret =  strcmp(w_fs_field[p_ct].fs_fd_map, w_fs_map[I].fs_name);
        if(ret == 0)
        {
           strcpy(tfield4, w_fs_field[p_ct].fs_fd_field);
           strcpy(w_address, w_fs_field[p_ct].fs_fd_address);
           x7 = 1;
/*
printf("\n #3 rct = %d fs_fd_map = %s fs_name = %s\n",rct,w_fs_field[s].fs_fd_map, w_fs_map[I].fs_name);
printf(" #4 p_ct = %d I = %d x7 = %d tfield4 = %s w_address = %s\n",p_ct,I,x7,tfield4,w_address);
*/
        }
       
        if(x7 == 1)
        {
          strcpy(a_string, "          DC    X'11");
          strcat(a_string, w_address);
          strcat(a_string, "'");
          strcpy(wk_remark, " ");
          strcat(wk_remark, "SBA");
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_eoj.c #9004");
            trace_rec_3();
          }

          strcpy(a_string, "          DC    X'1DF0'");
          strcpy(wk_remark, " ");
          strcat(wk_remark, "BASIC = PROTECTED");
          strcat(wk_remark, " ");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_eoj.c #9005");
            trace_rec_3();
          }
  
          strcpy(a_string, "          DC    X'2841F2'");
          strcpy(wk_remark, " ");
          strcat(wk_remark, "REVERSE");
          strcat(wk_remark, " ");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_eoj.c #9006"); 
            trace_rec_3();
          }

          ret = strcmp(w_fs_field[p_ct].fs_fd_color, "DEFAULT");
          if(ret == 0)
          {
            strcpy(a_string, "          DC    X'284200'");
            strcpy(wk_remark, " ");
            strcat(wk_remark, "DEFAULT");
            strcat(wk_remark, " ");
            write_remark();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_eoj.c #9007");
              trace_rec_3();
            }
          }

          ret = strcmp(w_fs_field[p_ct].fs_fd_color, "BLUE");
          if(ret == 0)
          {
            strcpy(a_string, "          DC    X'2842F1'");
            strcpy(wk_remark, " ");
            strcat(wk_remark, "BLUE");
            strcat(wk_remark, " ");
            write_remark();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_eoj.c #9008");
              trace_rec_3();
            }
          }

          ret = strcmp(w_fs_field[p_ct].fs_fd_color, "RED");
          if(ret == 0)
          {
            strcpy(a_string, "          DC    X'2842F2'");
            strcpy(wk_remark, " ");
            strcat(wk_remark, "RED");
            strcat(wk_remark, " ");
            write_remark();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_eoj.c #9009");
              trace_rec_3();
            }
          }

          ret = strcmp(w_fs_field[p_ct].fs_fd_color, "PINK");
          if(ret == 0)
          {
            strcpy(a_string, "          DC    X'2842F3'");
            strcpy(wk_remark, " ");
            strcat(wk_remark, "PINK");
            strcat(wk_remark, "*/ ");
            write_remark();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_eoj.c #9010");
              trace_rec_3();
            }
          }

          ret = strcmp(w_fs_field[p_ct].fs_fd_color, "GREEN");
          if(ret == 0)
          {
            strcpy(a_string, "          DC    X'2842F4'");
            strcpy(wk_remark, " ");
            strcat(wk_remark, "GREEN");
            strcat(wk_remark, "*/ ");
            write_remark();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_eoj.c #9011");
              trace_rec_3();
            }
          }

          ret = strcmp(w_fs_field[p_ct].fs_fd_color, "TURQUOISE");
          if(ret == 0)
          {
            strcpy(a_string, "          DC    X'2842F5'");
            strcpy(wk_remark, " ");
            strcat(wk_remark, "TURQUOISE");
            strcat(wk_remark, " ");
            write_remark();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_eoj.c #9012");
              trace_rec_3();
            }
          }

          ret = strcmp(w_fs_field[p_ct].fs_fd_color, "YELLOW");
          if(ret == 0)
          {
            strcpy(a_string, "          DC    X'2842F6'");
            strcpy(wk_remark, " ");
            strcat(wk_remark, "YELLOW");
            strcat(wk_remark, " ");
            write_remark();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_eoj.c #9013");
              trace_rec_3();
            }
          }

          ret = strcmp(w_fs_field[p_ct].fs_fd_color, "WHITE");
          if(ret == 0)
          {
            strcpy(a_string, "          DC    X'2842F7'");
            strcpy(wk_remark, " ");
            strcat(wk_remark, "WHITE");
            strcat(wk_remark, " ");
            write_remark();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_eoj.c #9014");
              trace_rec_3();
            }
          }

          ret = strcmp(w_fs_field[p_ct].fs_fd_type, "L");
          if(ret == 0)
          {
            strcpy(a_string, "          DC    C'");
            strcat(a_string, w_fs_field[p_ct].fs_fd_field);
            strcat(a_string, "'");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_eoj.c #9015");
              trace_rec_3();
            }
          }

          ret = strcmp(w_fs_field[p_ct].fs_fd_type, "V");
          if(ret == 0)
          {
            strcpy(field1, w_fs_field[p_ct].fs_fd_field);
/*
struct fs_scr_field
{
   char fs_scr_name[VAR_LGTH];
   char fs_scr_cname[VAR_LGTH];
};
struct fs_scr_field *w_fs_scr_field;
*/
 
            for(v = 0; v < T3270_ct; v++)
            {
              ret = strcmp(field1, w_fs_scr_field[v].fs_scr_name);
              if(ret == 0)
              {
                strcpy(field4, w_fs_scr_field[v].fs_scr_cname);
              }
            }

            strcpy(field1, w_fs_field[p_ct].fs_fd_field);
            x3 = 0;
            for (v = 0; v < lv_ct; v++) 
            {
               ret = strcmp(field1, lw_variable[v].lv_name);
               ret1 = strcmp(sv_func, lw_variable[v].lv_func);
               if ((ret == 0) && (ret1 == 0)) 
               {
                  strcpy(field1a, lw_variable[v].lv_cname);
                  x5 = lw_variable[v].lv_current_lgth;
                  x3 = 1;
                  break;
               }
            }

            if (x3 == 0) 
            {
               for (v = 0; v < gv_ct; v++) 
               {
                  ret = strcmp(field1, gw_variable[v].gv_name);
                  if (ret == 0) 
                  {
                     strcpy(field1a, gw_variable[v].gv_cname);
                     x5 = gw_variable[v].gv_current_lgth;
                     x3 = 1;
                     break;
                  }
               }
            }

            if(x99 > 1)
            {
               strcpy(a_string, "          DC    CL' '");
               src_line();
               if (puncde == 1) 
               {
                 strcpy(trace_1, "c2z_eoj.c #9017");
                 trace_rec_3();
               }
            }
            x99++; 
           
            strcpy(a_string, field4);
            check_length();
            strcat(a_string, " DC    CL");
            snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
            strcat(a_string, wk_strg);
            strcat(a_string, "' '");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_eoj.c #9016");
              trace_rec_3();
            }
          }

          strcpy(a_string, "          DC    X'1DF0'");
          strcpy(wk_remark, " ");
          strcat(wk_remark, "SF END FIELD)");
          strcat(wk_remark, " ");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_eoj.c #9017");
            trace_rec_3();
          }
        }
        x7 = 0;
        p_ct++;
      }

      strcpy(a_string, w_fs_map[I].fs_name);
      strcat(a_string, "OL ");
      check_length();
      strcat(a_string, " EQU   *-");
      strcat(a_string, w_fs_map[I].fs_name);
      strcat(a_string, "O");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #9018");
        trace_rec_3();
      }

      strcpy(a_string, "*");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c");
        trace_rec_3();
      }

      strcpy(a_string, w_fs_map[I].fs_name);
      strcat(a_string, "I");
      check_length();
      strcat(a_string, " DS    XL128");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c");
        trace_rec_3();
      }
     
      strcpy(a_string, w_fs_map[I].fs_name);
      strcat(a_string, "IL ");
      check_length();
      strcat(a_string, " EQU   *-");
      strcat(a_string, w_fs_map[I].fs_name);
      strcat(a_string, "I");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c");
        trace_rec_3();
      }

     strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c");
    trace_rec_3();
  }

    }
  }

  
  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c");
    trace_rec_3();
  }

  strcpy(a_string, "* Character Literals ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #2");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #3");
    trace_rec_3();
  }

  strcpy(a_string, "         DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #6");
    trace_rec_3();
  }

  for (I = 0; I < char_ct; I++) 
  {

    s = strlen(w_charlit[I].clit_value);
    if(s == 0)
    {
      strcpy(w_charlit[I].clit_value, " ");
    }

    strcpy(a_string, w_charlit[I].clit_cname);
    check_length();
    strcat(a_string, "DC    C'");
    strcat(a_string, w_charlit[I].clit_value);
    strcat(a_string, "'");
    s = strlen(a_string);
    x = 40 - s;
    for (x4 = 0; x4 < x; x4++) 
    {
      strcat(a_string, " ");
    }
    strcat(a_string, "/* ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_charlit[I].clit_rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "  */");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #5");
      trace_rec_3();
    }

    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #6");
      trace_rec_3();
    }
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c");
    trace_rec_3();
  }

  strcpy(a_string, "*  Gobal Numeric Variables");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #7");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c");
    trace_rec_3();
  }

  for (I = 0; I < gv_ct; I++) 
  {
    convert = 0;
    ret = strcmp(gw_variable[I].gv_type, "I");
    if (ret == 0) 
    {
      strcpy(wk_strg, gw_variable[I].gv_cname);
      strcpy(field1, gw_variable[I].gv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();
      strcat(a_string, "DC    ");
      x = atoi(gw_variable[I].gv_value);
      if (x == 0) 
      {
        strcat(a_string, "PL6'0'");
      } 
      else 
      {
        strcat(a_string, "PL6'");
        strcat(a_string, gw_variable[I].gv_value);
        strcat(a_string, "'");
      }
      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, gw_variable[I].gv_name);
      strcat(a_string, "  */");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #8");
        trace_rec_3();
      }
    }
  }

  for (I = 0; I < gv_ct; I++) 
  {
    convert = 0;
    ret = strcmp(gw_variable[I].gv_type, "U");
    if (ret == 0) 
    {
      strcpy(wk_strg, gw_variable[I].gv_cname);
      strcpy(field1, gw_variable[I].gv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();
      strcat(a_string, "DC    ");
      x = atoi(gw_variable[I].gv_value);
      if (x == 0) 
      {
        strcat(a_string, "PL6'0'");
      } 
      else 
      {
        strcat(a_string, "PL6'");
        strcat(a_string, gw_variable[I].gv_value);
        strcat(a_string, "'");
      }
      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, gw_variable[I].gv_name);
      strcat(a_string, "  */");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #8");
        trace_rec_3();
      }
    }
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #9");
    trace_rec_3();
  }

  strcpy(a_string, "* Global Character Variables ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #10");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #11");
    trace_rec_3();
  }

  strcpy(a_string, "         DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #12");
    trace_rec_3();
  }

  for (I = 0; I < gv_ct; I++) 
  {
    convert = 0;
    x = 0;
    x2 = 0;
    x4 = 0;
    ret = strcmp(gw_variable[I].gv_type, "L");
    if (ret == 0) 
    {
      for (x3 = 0; x3 < v_const; x3++) 
      {
        strcpy(wk_strg, gw_variable[I].gv_name);
        strcpy(field1, gw_variable[I].gv_name);
        strcpy(a_string, wk_strg);
        check_length();
        /*  see if field1 is in w_constant */
        x2 = strcmp(field1, w_constant[x3].const_current);
        if (x2 == 0) 
        {
          x4 = 1;
          x = strcmp(field1, w_constant[x3].const_use);
          if (x == 0) 
          {
            x10 = strlen(gw_variable[I].gv_literal);
            strcat(a_string, "DC    ");
            strcat(a_string, "C");
            strcat(a_string, "'");
            if (x10 == 0) 
            {
              strcat(a_string, " ");
            }

            if (x10 != 0) 
            {
              strcat(a_string, gw_variable[I].gv_literal);
            }

            strcat(a_string, "'");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_eoj.c #13");
              trace_rec_3();
            }

            x5 = gw_variable[I].gv_lgth;
            x5++;

            strcpy(a_string, "         DS    0H");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_eoj.c #14");
              trace_rec_3();
            }
            break;
          }
        }
      }

      if (x4 != 1) 
      {
        strcpy(a_string, gw_variable[I].gv_name);
        check_length();
        strcat(a_string, "DC    ");
        strcat(a_string, "C");
        strcat(a_string, "'");
        strcat(a_string, gw_variable[I].gv_literal);
        strcat(a_string, "'");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_eoj.c #15");
          trace_rec_3();
        }

        x5 = gw_variable[I].gv_lgth;
        x5++;

        strcpy(a_string, "         DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_eoj.c #16");
          trace_rec_3();
        }
      }
    }
  }

  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp("A", gw_variable[I].gv_type);
    if (ret == 0) 
    {
      k8 = gw_variable[I].gv_row;
      k9 = gw_variable[I].gv_column;
      k7 = k8 * k9;
     /* k7 = 90; */

      strcpy(a_string, gw_variable[I].gv_table);
      check_length();
      strcat(a_string, "DS    ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", k7);
      strcat(a_string, wk_strg);
      strcat(a_string, "CL(");
      strcat(a_string, gw_variable[I].gv_label);
      strcat(a_string, ")");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #17");
        trace_rec_3();
      }

      strcpy(a_string, "*");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #18");
        trace_rec_3();
      }

      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();
      strcat(a_string, "DS    ");
      strcat(a_string, "PL6'0'");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #19");
        trace_rec_3();
      }
    }
  }

  for (I = 0; I < gv_ct; I++) 
  {
    convert = 0;
    ret = strcmp(gw_variable[I].gv_type, "G");
    if ((ret == 0) && (convert == 0)) 
    {
      strcpy(a_string, "         DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #20");
        trace_rec_3();
      }

      strcpy(field1, gw_variable[I].gv_name);
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field1, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          k8 = gw_variable[v].gv_row;
          k9 = gw_variable[v].gv_column;
          k7 = k8 * k9;
        }
      }

      strcpy(a_string, gw_variable[I].gv_table);
      check_length();
      strcat(a_string, "DC    ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", k7);
      strcat(a_string, wk_strg);
      strcat(a_string, "PL6'0'");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #21");
        trace_rec_3();
      }

      strcpy(a_string, "*");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #22");
        trace_rec_3();
      }
    }
  }

  for (I = 0; I < m_struc_ct; I++) 
  {
    convert = 0;
    x3 = 0;
    ret = strcmp(w_struc[I].st_id, "M");
    if ((ret == 0) && (convert == 0)) 
    {
      strcpy(tfield9, w_struc[I].st_name);
      strcat(tfield9, "_max_ct");
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield9, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            x2 = atoi(gw_variable[v].gv_value);
          }
        }
      }

      strcpy(a_string, "         DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #23");
        trace_rec_3();
      }

      x2 = 25;
      strcpy(a_string, w_struc[I].st_cwname);
      strcat(a_string, "T");
      check_length();
      strcat(a_string, "DS    ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
      strcat(a_string, wk_strg);
      strcat(a_string, "CL(");
      strcpy(tfield2, w_struc[I].st_cwname);
      strcat(tfield2, "L");
      strcat(a_string, tfield2);
      strcat(a_string, ")");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #24");
        trace_rec_3();
      }
    }
  }

  strcpy(a_string, "         DS    0H");
  src_line();
  if (puncde == 1) 
  {
     strcpy(trace_1, "c2z_eoj.c #25");
     trace_rec_3();
  }

  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp("D", gw_variable[I].gv_type);
    if (ret == 0) 
    {
      strcpy(wk_strg, gw_variable[I].gv_cname);
      strcpy(field1, gw_variable[I].gv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();
      strcat(a_string, "DS    ");
      x = strlen(gw_variable[I].gv_value);

      strcat(a_string, "PL6'0'");
     
      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, gw_variable[I].gv_name);
      strcat(a_string, "  */");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #26");
        trace_rec_3();
      }

      strcpy(a_string, "         DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #27");
        trace_rec_3();
      }
    }
  }

  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp("D", lw_variable[I].lv_type);
    if (ret == 0) 
    {
      strcpy(wk_strg, lw_variable[I].lv_cname);
      strcpy(field1, lw_variable[I].lv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, lw_variable[I].lv_cname);
      check_length();
      strcat(a_string, "DS    ");
      x = strlen(lw_variable[I].lv_value);

      strcat(a_string, "PL6'0'");
     
      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, lw_variable[I].lv_name);
      strcat(a_string, "  */");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #28");
        trace_rec_3();
      }

      strcpy(a_string, "         DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #29");
        trace_rec_3();
      }
    }
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #30");
    trace_rec_3();
  }

  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(gw_variable[I].gv_type, "F");
    if (ret == 0) 
    {
      strcpy(wk_strg, gw_variable[I].gv_cname);
      strcpy(field1, gw_variable[I].gv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();

      strcat(a_string, "DS    ");
      x = strlen(gw_variable[I].gv_value);
      if (x == 0) 
      {
        strcat(a_string, "F'0'");
      }
      else 
      {
        strcat(a_string, "F'");
        strcat(a_string, gw_variable[I].gv_value);
        strcat(a_string, "'");
      }

      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, gw_variable[I].gv_name);
      strcat(a_string, "  */");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #31");
        trace_rec_3();
      }

      convert = 1;
    }
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #32");
    trace_rec_3();
  }

  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(gw_variable[I].gv_type, "C");
    if (ret == 0) 
    {

      strcpy(wk_strg, gw_variable[I].gv_cname);
      strcpy(field1, gw_variable[I].gv_cname);
      strcpy(a_string, field1);
      check_length();
      strcat(a_string, "DC    ");
      strcat(a_string, "CL");

      ret1 = strcmp("p_string",gw_variable[I].gv_name);
      if(ret1 == 0)
      {
        gw_variable[I].gv_lgth = 100;
        gw_variable[I].gv_current_lgth = 0;
      }

      if (gw_variable[I].gv_lgth == 0) 
      {
        gw_variable[I].gv_lgth = 1;
      }
      snprintf(wk_strg, sizeof(wk_strg), "%d", gw_variable[I].gv_lgth);
      strcat(a_string, wk_strg);

      /* check for value field to see if char is being set	*/

      strcat(a_string, "' '"); 

      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }

      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #33");
        trace_rec_3();
      }

      if (gw_variable[I].gv_lgth % 2 == 0) 
      {
      } 
      else 
      {
        strcpy(a_string, "         DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_eoj.c #34");
          trace_rec_3();
        }
      }

      convert = 1;
    }
  }

  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(gw_variable[I].gv_type, "X");
    if (ret == 0) 
    {
      strcpy(wk_strg, gw_variable[I].gv_cname);
      strcpy(field1, gw_variable[I].gv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();

      strcat(a_string, "DC    ");
      strcat(a_string, "X'");
      strcat(a_string, gw_variable[I].gv_value);
      strcat(a_string, "'");

      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      src_line();
      if (puncde == 1)
      {
        trace_rec_3();
      }
    }
  }

  for (I = 0; I < m_struc_ct; I++) 
  {
    x3 = 0;
    ret = strcmp(w_struc[I].st_id, "N");
    if (ret == 0)
    {
      ret1 = strcmp(w_struc[I].st_type, "I");
      if(ret1 == 0)
      {

        strcpy(a_string, "         DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_eoj.c #35");
          trace_rec_3();
        }

        strcpy(a_string, w_struc[I].st_field_cname);
        check_length();
        strcat(a_string, "DC    PL6'0'");
        strcpy(wk_remark, " ");
        strcat(wk_remark, w_struc[I].st_field_name);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_eoj.c #36");
          trace_rec_3();
        }
      }

      ret1 = strcmp(w_struc[I].st_type, "C");
      if(ret1 == 0)
      {
        strcpy(a_string, "         DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_eoj.c #37");
          trace_rec_3();
        }

        strcpy(a_string, w_struc[I].st_field_cname);
        check_length();
        strcat(a_string, "DC    CL");
        snprintf(wk_strg, sizeof(wk_strg), "%d", w_struc[I].st_field_lgth);
        strcat(a_string, wk_strg);
        strcat(a_string, "' '");
        strcpy(wk_remark, " ");
        strcat(wk_remark, w_struc[I].st_field_name);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_eoj.c #38");
          trace_rec_3();
        }
      }
    }
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_eoj.c #39");
    trace_rec_3();
  }

  strcpy(a_string, "* Local Numeric Variables ");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_eoj.c #40");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_eoj.c #41");
    trace_rec_3();
  }

  strcpy(a_string, "         DS    0H");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_eoj.c #42");
    trace_rec_3();
  }

  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(lw_variable[I].lv_type, "I");
    if (ret == 0) 
    {
      strcpy(a_string, "         DS    0H");
      src_line();
      if (puncde == 1)
      {
        strcpy(trace_1, "c2z_eoj.c #43");
        trace_rec_3();
      }

/*
      strcpy(wk_strg, lw_variable[I].lv_cname);
      strcpy(field1, lw_variable[I].lv_cname);
      strcpy(a_string, wk_strg); 
      s = strlen(wk_strg);
*/
      strcpy(a_string, lw_variable[I].lv_cname);
      check_length();
      strcat(a_string, "DC    ");
      x = atoi(lw_variable[I].lv_value);
      if (x == 0) 
      {
        strcat(a_string, "PL6'0'");
      } 
      else 
      {
        strcat(a_string, "PL6'");
        strcat(a_string, lw_variable[I].lv_value);
        strcat(a_string, "'");
      }

      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, lw_variable[I].lv_name);
      strcat(a_string, "  - ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", lw_variable[I].lv_rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "  */");
      src_line();
      if (puncde == 1)
      {
        strcpy(trace_1, "c2z_eoj.c #44");
        trace_rec_3();
      }
    }
  }

  strcpy(a_string, "         DS    0H");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_eoj.c #45");
    trace_rec_3();
  }

  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(lw_variable[I].lv_type, "U");
    if (ret == 0) 
    {
      strcpy(a_string, "         DS    0H");
      src_line();
      if (puncde == 1)
      {
        strcpy(trace_1, "c2z_eoj.c #46");
        trace_rec_3();
      }
 
      strcpy(wk_strg, lw_variable[I].lv_cname);
      strcpy(field1, lw_variable[I].lv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, lw_variable[I].lv_cname);
      check_length();

      strcat(a_string, "DC    ");
      x = atoi(lw_variable[I].lv_value);
      if (x == 0) 
      {
        strcat(a_string, "PL6'0'");
      } 
      else 
      {
        strcat(a_string, "PL6'");
        strcat(a_string, lw_variable[I].lv_value);
        strcat(a_string, "'");
      }

      s = strlen(a_string);
      x = 33 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, gw_variable[I].gv_name);
      strcat(a_string, "  - ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", gw_variable[I].gv_rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "  */");
      src_line();
      if (puncde == 1)
      {
        strcpy(trace_1, "c2z_eoj.c #47");
        trace_rec_3();
      }
    }
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_eoj.c");
    trace_rec_3();
  }

  strcpy(a_string, "* Local Character Variables");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_eoj.c #48");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_eoj.c");
    trace_rec_3();
  }

  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(lw_variable[I].lv_type, "C");
    if (ret == 0) 
    {
      strcpy(wk_strg, lw_variable[I].lv_cname);
      strcpy(field1, lw_variable[I].lv_cname);
      strcpy(a_string, field1);
      check_length();

      strcat(a_string, "DC    ");
      strcat(a_string, "CL");
      if (lw_variable[I].lv_lgth == 0) 
      {
        lw_variable[I].lv_lgth = 1;
      }
      snprintf(wk_strg, sizeof(wk_strg), "%d", lw_variable[I].lv_lgth);
      strcat(a_string, wk_strg);

      ret1 = strcmp(" ", lw_variable[I].lv_value);
      if (ret1 != 0) 
      {
        strcat(a_string, "'");
        strcat(a_string, lw_variable[I].lv_value);
        strcat(a_string, " '");
      }

      s = strlen(a_string);
      x = 33 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, lw_variable[I].lv_name);
      strcat(a_string, "  - ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", lw_variable[I].lv_rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "  */");
      src_line();
      if (puncde == 1)
      {
        strcpy(trace_1, "c2z_eoj.c #49");
        trace_rec_3();
      }

      if (lw_variable[I].lv_lgth % 2 == 0) 
      {
      }
      else 
      {
        strcpy(a_string, "         DS    0H");
        src_line();
        if (puncde == 1)
        {
          strcpy(trace_1, "c2z_eoj.c #50");
          trace_rec_3();
        }
      }
    }
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_eoj.c #51");
    trace_rec_3();
  }

  strcpy(a_string, "*  Parser Vars");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_eoj.c #52");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_eoj.c #53");
    trace_rec_3();
  }

  strcpy(a_string, "         LTORG");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #54");
    trace_rec_3();
  }

  if (work_use_ct[1] > 0)		/* C370ISAL */ 		
  {
    strcpy(a_string, "         DS    0H");	
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #55");
      trace_rec_3();
    }

    strcpy(a_string, "C370ISAL DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #56");
      trace_rec_3();
    }
  }

  if (work_use_ct[2] > 0)		/* C370L1	*/ 		
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #57");
      trace_rec_3();
    }

    strcpy(a_string, "C370L1   DC    C' '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #58");
      trace_rec_3();
    }
  }

  if (work_use_ct[3] > 0)		/* C370L2	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #59");
      trace_rec_3();
    }

    strcpy(a_string, "C370L2   DC    C' '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #60");
      trace_rec_3();
    }
  }

  if (work_use_ct[4] > 0)		/* C370L3	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #61");
      trace_rec_3();
    }

    strcpy(a_string, "*C370L3   DC    C'   '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #62");
      trace_rec_3();
    }
  }

  if (work_use_ct[5] > 0)		/* C370L4	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #63");
      trace_rec_3();
    }

    strcpy(a_string, "*C370L4   DC    C'    '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #64");
      trace_rec_3();
    }
  }

  if (work_use_ct[6] > 0)		/* C370L5	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #65");
      trace_rec_3();
    }

    strcpy(a_string, "*C370L5   DC    C'     '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #66");
      trace_rec_3();
    }
  }

  if (work_use_ct[7] > 0)		/* C370L6	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #67");
      trace_rec_3();
    }

    strcpy(a_string, "*C370L6   DC    C'      '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #68");
      trace_rec_3();
    }
  }

  if (work_use_ct[8] > 0)		/* C370L8A	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #69");
      trace_rec_3();
    }

    strcpy(a_string, "C370L8A  DC    C'        '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #70");
      trace_rec_3();
    }
  }

  if (work_use_ct[9] > 0)		/* C370L8	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #71");
      trace_rec_3();
    }

    strcpy(a_string, "C370L8   DC    C'        '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #72");
      trace_rec_3();
    }
  }

  if (work_use_ct[10] > 0)		/* C370L80	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #73");
      trace_rec_3();
    }

    strcpy(a_string, "C370L80  DC    CL80' '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #74");
      trace_rec_3();
    }
  }

  if (work_use_ct[11] > 0)		/* C370MTOT	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #75");
      trace_rec_3();
    }

    strcpy(a_string, "C370MTOT DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #76");
      trace_rec_3();
    }
  }

  if (work_use_ct[12] > 0)		/* C370THR	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #77");
      trace_rec_3();
    }

    strcpy(a_string, "C370THR  DC    PL6'3'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #78");
      trace_rec_3();
    }
  }

  if (work_use_ct[13] > 0)		/* C370FOUR	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #79");
      trace_rec_3();
    }

    strcpy(a_string, "C370FOUR DC    PL6'4'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #80");
      trace_rec_3();
    }
  }

  if (work_use_ct[14] > 0)		/* C370MT3	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #81");
      trace_rec_3();
    }

    strcpy(a_string, "C370MT3  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #82");
      trace_rec_3();
    }
  }

  if (work_use_ct[15] > 0)		/* C370MT4	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #83");
      trace_rec_3();
    }

    strcpy(a_string, "C370MT4  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #84");
      trace_rec_3();
    }
  }

  if (work_use_ct[16] > 0)		/* C370MT5	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #85");
      trace_rec_3();
    }

    strcpy(a_string, "C370MT5  DC    PL6'0'");  
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #86");
      trace_rec_3();
    }
  }

  if (work_use_ct[17] > 0)		/* C370PTOT	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #87");
      trace_rec_3();
    }

    strcpy(a_string, "C370PTOT DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #88");
      trace_rec_3();
    }
  }

  if (work_use_ct[18] > 0)		/* C370PT1 */ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #89");
      trace_rec_3();
    }

    strcpy(a_string, "C370PT1  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #90");
      trace_rec_3();
    }
  }

  if (work_use_ct[19] > 0)		/* C370PT2	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #91");
      trace_rec_3();
    }

    strcpy(a_string, "C370PT2  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #92");
      trace_rec_3();
    }
  }

  if (work_use_ct[20] > 0)		/* C370PT3	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #93");
      trace_rec_3();
    }

    strcpy(a_string, "C370PT3  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #94");
      trace_rec_3();
    }
  }

  if (work_use_ct[21] > 0)		/* C370PT4	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #95");
      trace_rec_3();
    }

    strcpy(a_string, "C370PT4  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #96");
      trace_rec_3();
    }
  }

  if (work_use_ct[22] > 0)		/* C370PT5	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #97");
      trace_rec_3();
    }

    strcpy(a_string, "C370PT5  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #98");
      trace_rec_3();
    }
  }

  if (work_use_ct[23] > 0)		/* C370CLCT 	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #99");
      trace_rec_3();
    }

    strcpy(a_string, "*C370CLCT DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #100");
      trace_rec_3();
    }
  }

  if (work_use_ct[24] > 0)		/* C370FIVE	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #101");
      trace_rec_3();
    }

    strcpy(a_string, "C370FIVE DC    PL6'5'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #102");
      trace_rec_3();
    }
  }

  if (work_use_ct[25] > 0)		/* C370EDW2	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #103");
      trace_rec_3();
    }

    strcpy(a_string, "C370EDW2 DC    X'40202120'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #104");
      trace_rec_3();
    }
  }

  if (work_use_ct[26] > 0)		/* C370EDW3	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #105");
      trace_rec_3();
    }

    strcpy(a_string, "C370EDW3 DC    X'402020202120'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #106");
      trace_rec_3();
    }
  }

  if (work_use_ct[27] > 0)		/* C370EDW4	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #107");
      trace_rec_3();
    }

    strcpy(a_string, "C370EDW4 DC    X'4020202020202120'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #108");
      trace_rec_3();
    }
  }

  if (work_use_ct[28] > 0)		/* C370TDD2	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #109");
      trace_rec_3();
    }

    strcpy(a_string, "C370TDD2 DS    C'     '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #110");
      trace_rec_3();
    }
  }

  if (work_use_ct[29] > 0)		/* C370PN2	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #111");
      trace_rec_3();
    }

    strcpy(a_string, "C370PN2  DS    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #112");
      trace_rec_3();
    }
  }

  if (work_use_ct[30] > 0)		/* C370PN3	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #113");
      trace_rec_3();
    }

    strcpy(a_string, "C370PN3  DS    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #114");
      trace_rec_3();
    }
  }

  if (work_use_ct[31] > 0)		/* C370DDW2	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #115");
      trace_rec_3();
    }

    strcpy(a_string, "C370DDW2 DC    X'4021204B20'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #116");
      trace_rec_3();
    }
  }

  if (work_use_ct[32] > 0)		/* C370ZERO	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #117");
      trace_rec_3();
    }

    strcpy(a_string, "C370ZERO DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #118");
      trace_rec_3();
    }
  }

  if (work_use_ct[33] > 0)		/* C370ONE	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #119");
      trace_rec_3();
    }

    strcpy(a_string, "C370ONE  DC    PL6'1'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #120");
      trace_rec_3();
    }
  }

  if (work_use_ct[34] > 0)		/* C370TWO	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #121");
      trace_rec_3();
    }

    strcpy(a_string, "C370TWO  DC    PL6'2'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #122");
      trace_rec_3();
    }
  }

  if (work_use_ct[35] > 0)		/* C370UCA  NOT USED */ 
  {
       /* reserve #123 & #124 */
  }

  if (work_use_ct[36] > 0)		/* C370UCZ  NOT USED */ 
  {
	/* reserve #125 & #126 */

  }

  if (work_use_ct[37] > 0)		/* C370LCA  NOT USED */ 
  {
	/* reserve #127 & #128 */
  }

  if (work_use_ct[38] > 0)		/* C370LCZ  NOT USED */ 
  {
	/* reserve #129 & #130 */
  }

  if (work_use_ct[39] > 0)		/* C370MATH	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #131");
      trace_rec_3();
    }

    strcpy(a_string, "C370MATH DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #132");
      trace_rec_3();
    }
  }

  if (work_use_ct[40] > 0)		/* C370DEND	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #133");
      trace_rec_3();
    }

    strcpy(a_string, "C370DEND DS    0CL13");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #134");
      trace_rec_3();
    }

    strcpy(a_string, "C370IENT DS    PL7");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #135");
      trace_rec_3();
    }
   
    strcpy(a_string, "REMAINDR DS    PL6");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #136");
      trace_rec_3();
    }
  }

  if (work_use_ct[41] > 0)		/* C370IENT	*/ 
  {
	/*  reserve #137 & #138 */
  }

  if (work_use_ct[42] > 0)		/* REMAINDER	*/ 
  {
	/*  reserve #139 & #140 */

  }

  if (work_use_ct[43] > 0)		/* C370ISOR	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #141");
      trace_rec_3();
    }

    strcpy(a_string, "C370ISOR DS    PL6");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #142");
      trace_rec_3();
    }
  }

  if (work_use_ct[44] > 0)		/* C370MLT1	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #143");
      trace_rec_3();
    }

    strcpy(a_string, "C370MLT1 DS    PL8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #144");
      trace_rec_3();
    }
  }

  if (work_use_ct[45] > 0)		/* C370MLT2	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #145");
      trace_rec_3();
    }

    strcpy(a_string, "C370MLT2 DS    PL8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #146");
      trace_rec_3();
    }
  }

  if (work_use_ct[46] > 0)		/* C370MLT3	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj. c #147");
      trace_rec_3();
    }

    strcpy(a_string, "C370MLT3 DS    PL8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #148");
      trace_rec_3();
    }
  }

  if (work_use_ct[47] > 0)		/* C370D2DW	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #149");
      trace_rec_3();
    }

    strcpy(a_string, "C370D2DW DC    X'40214B2020'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #150");
      trace_rec_3();
    }
  }

  if (work_use_ct[48] > 0)		/* C370U	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #151");
      trace_rec_3();
    }

    strcpy(a_string, "C370U    DS    D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #152");
      trace_rec_3();
    }
  }

    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #153");
      trace_rec_3();
    }

    strcpy(a_string, "C370PBUF DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #154");
      trace_rec_3();
    }


  if (work_use_ct[49] > 0)		/* C370NWK1	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #155");
      trace_rec_3();
    }

    strcpy(a_string, "C370NWK1 DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #156");
      trace_rec_3();
    }
  }

  if (work_use_ct[50] > 0)		/* C370NWK2	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #157");
      trace_rec_3();
    }

    strcpy(a_string, "C370NWK2 DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #158");
      trace_rec_3();
    }
  }

  if (work_use_ct[51] > 0)		/* C370EDN	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #159");
      trace_rec_3();
    }

    strcpy(a_string, "C370EDN  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #160");
      trace_rec_3();
    }
  }

  if(work_use_ct[52] > 0)		/* C370B1	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #161");
      trace_rec_3();
    }

    strcpy(a_string, "C370B1   DC    C' '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #162");
      trace_rec_3();
    }
  }

  if (work_use_ct[53] > 0)		/* C370B8	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #163");
      trace_rec_3();
    }

    strcpy(a_string, "C370B8   DC    C'        '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #164");
      trace_rec_3();
    }
  }

  if (work_use_ct[54] > 0)		/* C370TDW2	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #165");
      trace_rec_3();
    }

    strcpy(a_string, "C370TDW2 DS    C'    '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #166");
      trace_rec_3();
    }
  }

  if (work_use_ct[55] > 0)		/* C370TDW3	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #167");
      trace_rec_3();
    }

    strcpy(a_string, "C370TDW3 DS    C'      '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #168");
      trace_rec_3();
    }
  }

  if (work_use_ct[56] > 0)		/* C370TDW4	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #169");
      trace_rec_3();
    }
  
    strcpy(a_string, "C370TDW4 DS    C'        '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #170");
      trace_rec_3();
    }
  }

  if (work_use_ct[57] > 0)		/* C370N3	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #171");
      trace_rec_3();
    }

    strcpy(a_string, "C370N3   DC    PL6'999'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #172");
      trace_rec_3();
    }
  }

  if (work_use_ct[58] > 0)		/* C370N5	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #173");
      trace_rec_3();
    }

    strcpy(a_string, "C370N5   DC    PL6'99999'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #174");
      trace_rec_3();
    }
  }

  if (work_use_ct[59] > 0)		/* C370L1A	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #175");
      trace_rec_3();
    }

    strcpy(a_string, "C370L1A  DC    C' '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #176");
      trace_rec_3();
    }
  }

/*  STOP HERE */

  if (work_use_ct[60] > 0)		/* C370TDD3	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #177");
      trace_rec_3();
    }

    strcpy(a_string, "C370TDD3 DC    C'      '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #178");
      trace_rec_3();
    }
  }

  if (work_use_ct[61] > 0)		/* C370D3DW	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #179");
      trace_rec_3();
    }

    strcpy(a_string, "C370D3DW DC    X'21204B202020'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #180");
      trace_rec_3();
    }
  }

  if (work_use_ct[62] > 0)		/* C370LZER	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #181");
      trace_rec_3();
    }

    strcpy(a_string, "C370LZER DC    C'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #182");
      trace_rec_3();
    }
  }

  if (work_use_ct[63] > 0)		/* C370LNIN	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #183");
      trace_rec_3();
    }

    strcpy(a_string, "C370LNIN DC    C'9'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #184");
      trace_rec_3();
    }
  }

  if (work_use_ct[64] > 0)		/* NOT USED	*/ 
  {
		/* reserve #185 / #186 */
  }

  if (work_use_ct[65] > 0)		/* C370NN3	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #187");
      trace_rec_3();
    }

    strcpy(a_string, "C370NN3  DC    PL6'-999'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #188");
      trace_rec_3();
    }
  }

  if (work_use_ct[66] > 0)		/* C370NN5	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #189");
      trace_rec_3();
    }

    strcpy(a_string, "C370NN5  DC    PL6'-99999'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #190");
      trace_rec_3();
    }
  }

  if (work_use_ct[67] > 0)		/* C370DEC	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #191");
      trace_rec_3();
    }

    strcpy(a_string, "C370DEC  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #192");
      trace_rec_3();
    }
  }

  if (work_use_ct[68] > 0)		/* C370TDW5	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #193");
      trace_rec_3();
    }

    strcpy(a_string, "C370TDW5 DC    C'     '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #194");
      trace_rec_3();
    }
  }

  if (work_use_ct[69] > 0)		/* C370B10	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #195");
      trace_rec_3();
    }

    strcpy(a_string, "C370B10  DC    C'          '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #196");
      trace_rec_3();
    }
  }

  if (work_use_ct[70] > 0)		/* C370TDW7	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #197");
      trace_rec_3();
    }

    strcpy(a_string, "C370TDW7 DS    C'       '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #198");
      trace_rec_3();
    }
  }

  if (work_use_ct[71] > 0)		/* C370L10	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #199");
      trace_rec_3();
    }

    strcpy(a_string, "C370L10  DS    CL10");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #200");
      trace_rec_3();
    }
  }

  if (work_use_ct[72] > 0)		/* C370XXX	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #201");
      trace_rec_3();
    }

    strcpy(a_string, "C370XXX  DC    C''''");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #202");
      trace_rec_3();
    }
  }

  if (work_use_ct[73] > 0)		/* C370LPCT	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #203");
      trace_rec_3();
    }

    strcpy(a_string, "C370LPCT DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #204");
      trace_rec_3();
    }
  }

  if (work_use_ct[74] > 0)		/* C370EOF	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #205");
      trace_rec_3();
    }

    strcpy(a_string, "C370EOF  DC    X'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #206");
      trace_rec_3();
    }
  }

  if (work_use_ct[75] > 0)		/* C370PER	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #207");
      trace_rec_3();
    }

    strcpy(a_string, "C370PER  DC    C'.'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #208");
      trace_rec_3();
    }
  }

  if (work_use_ct[76] > 0)		/* C370TDW9	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #209");
      trace_rec_3();
    }

    strcpy(a_string, "C370TDW9 DS    C'         '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #210");
      trace_rec_3();
    }
  }

  if (work_use_ct[77] > 0)		/* C370EDW5	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #211");
      trace_rec_3();
    }

    strcpy(a_string, "C370EDW5 DC    X'4020212060'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #212");
      trace_rec_3();
    }
  }

  if (work_use_ct[78] > 0)		/* C370NWK3	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #213");
      trace_rec_3();
    }

    strcpy(a_string, "C370NWK3 DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #214");
      trace_rec_3();
    }
  }

  if (work_use_ct[79] > 0)		/* C370FONE	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #215");
      trace_rec_3();
    }

    strcpy(a_string, "C370FONE DC    F'1'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #216");
      trace_rec_3();
    }
  }

  if (work_use_ct[80] > 0)		/* C370DIGT	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #217");
      trace_rec_3();
    }

    strcpy(a_string, "C370DIGT DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #218");
      trace_rec_3();
    }
  }

  if (work_use_ct[81] > 0)		/* C370COLN	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #219");
      trace_rec_3();
    }

    strcpy(a_string, "C370COLN DC    C':'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #220");
      trace_rec_3();
    }
  }

  if (work_use_ct[82] > 0)		/* C370NONE	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #221");
      trace_rec_3();
    }

    strcpy(a_string, "C370NONE DC    PL6'-1'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #222");
      trace_rec_3();
    }
  }

  if (work_use_ct[83] > 0)		/* C370EDW7	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #223");
      trace_rec_3();
    }

    strcpy(a_string, "C370EDW7 DC    X'40202020212060'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #224");
      trace_rec_3();
    }
  }

  if (work_use_ct[84] > 0)		/* C370EDW9	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #225");
      trace_rec_3();
    }

    strcpy(a_string, "C370EDW9 DC    X'402020202020212060'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #226");
      trace_rec_3();
    }
  }

  if (work_use_ct[85] > 0)		/* C370DTTM	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #227");
      trace_rec_3();
    }

    strcpy(a_string, "C370DTTM DC    XL16'00'"); 
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #228");
      trace_rec_3();
    }
  }

  if (work_use_ct[86] > 0)		/* C370M001	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #229");
      trace_rec_3();
    }

    strcpy(a_string, "C37M001  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #230");
      trace_rec_3();
    }
  }

  if (work_use_ct[89] > 0)		/* C370M002	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #231");
      trace_rec_3();
    }

    strcpy(a_string, "C37M002  DC    CL1' '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #232");
      trace_rec_3();
    }
  }

  if (work_use_ct[90] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #233");
      trace_rec_3();
    }

    strcpy(a_string, "C370TUC  DC    C'ABCDEFGHIJKLMNOPQRSTUVWXYZ'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #234");
      trace_rec_3();
    }

    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #235");
      trace_rec_3();
    }

    strcpy(a_string, "C370TLC  DC    C'abcdefghijklmnopqrstuvwxyz'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #236");
      trace_rec_3();
    }
  }

  if (work_use_ct[93] > 0)		/* C370ECB	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #237");
      trace_rec_3();
    }

    strcpy(a_string, "C370ECB  DC    F'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #238");
      trace_rec_3();
    }
  }

  if (work_use_ct[94] > 0)		/* C370NWK4	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #239");
      trace_rec_3();
    }

    strcpy(a_string, "C370NWK4 DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #240");
      trace_rec_3();
    }
  }

  if (work_use_ct[95] > 0)		/* C370NWK5	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #241");
      trace_rec_3();
    }

    strcpy(a_string, "C370NWK5 DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #242");
      trace_rec_3();
    }
  }

  if (work_use_ct[96] > 0)		/* C370M003	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #243");
      trace_rec_3();
    }

    strcpy(a_string, "C37M003  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #244");
      trace_rec_3();
    }
  }

  if (work_use_ct[97] > 0)		/* C370M004	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #245");
      trace_rec_3();
    }

    strcpy(a_string, "C37M004  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #246");
      trace_rec_3();
    }
  }

  if (work_use_ct[98] > 0)		/* C370M005	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #247");
      trace_rec_3();
    }

    strcpy(a_string, "C37M005  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #248");
      trace_rec_3();
    }
  }

  if (work_use_ct[99] > 0)		/* C370QUOT	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #249");
      trace_rec_3();
    }

    strcpy(a_string, "C370QUOT DC    X'\''");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #250");
      trace_rec_3();
    }
  }

  if (work_use_ct[100] > 0)		/* TSTUC TSTLC	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #251");
      trace_rec_3();
    }

    strcpy(a_string, "TSTUC    DC    C'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #252");
      trace_rec_3();
    }

    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #253");
      trace_rec_3();
    }

    strcpy(a_string, "TSTLC    DC    C'abcdefghijklmnopqrstuvwxyz0123456789'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #254");
      trace_rec_3();
    }
  } 

  if (work_use_ct[101] > 0)		/* C370DDTE	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #255");
      trace_rec_3();
    }

    strcpy(a_string, "C370DDTE DC    C'MM/DD/YY'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #256");
      trace_rec_3();
    }
  }

  if (work_use_ct[102] > 0)		/* C370DWRK	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #257");
      trace_rec_3();
    }

    strcpy(a_string, "C370DWRK DC    XL9'00'"); 
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #258");
      trace_rec_3();
    }
  }

  if (work_use_ct[103] > 0)		/* C370DATE	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #259");
      trace_rec_3();
    }

    strcpy(a_string, "C370DATE DC    CL29' '"); 
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #260");
      trace_rec_3();
    }
  }

  if (work_use_ct[104] > 0)		/* C370NCVT	*/ 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #261");
      trace_rec_3();
    }

    strcpy(a_string, "C370NCVT  DC    PL6'0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #262");
      trace_rec_3();
    }
  }

  if(for_loop_ct > 0)
  {
    for(I = 1; I <= for_loop_ct; I++)
    {
      strcpy(a_string, "         DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #263");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", I);
      strcpy(a_string, "C370R");
      strcat(a_string, wk_strg);
      check_length();
      strcat(a_string, "DC    PL6'0'");
      write_short();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #264");
        trace_rec_3();
      }
    }
  }

  if(tot_localtime > 0)
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #265");
      trace_rec_3();
    }

    strcpy(a_string, "C370TIME DC    CL29' '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #266");
      trace_rec_3();
    }
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #267");
    trace_rec_3();
  }

  strcpy(a_string, "         DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #268");
    trace_rec_3();
  }

  strcpy(a_string, "C370WTO  DC    AL2(C370WTOE-*,0)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #269");
    trace_rec_3();
  }

  strcpy(a_string, "C370WTOB DC    CL132' '");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #270");
    trace_rec_3();
  }

  strcpy(a_string, "C370WTOE EQU   *");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #271");
    trace_rec_3();
  }

  strcpy(a_string, "C370WTOL EQU   *-C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #272");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #273");
    trace_rec_3();
  }

  for (I = 0; I < cary_ct; I++) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #274");
      trace_rec_3();
    }

    strcpy(a_string, w_carry[I].carry_cname);
    check_length();
    strcat(a_string, "DC    ");
    strcat(a_string, "C'");
    strcat(a_string, w_carry[I].carry_literal);
    strcat(a_string, "'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #275");
      trace_rec_3();
    }
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #276");
    trace_rec_3();
  }

  for (I = 0; I < gv_ct; I++) 
  {
    convert = 0;
    ret = strcmp(gw_variable[I].gv_type, "A");
    if ((ret == 0) && (convert == 0)) 
    {
      strcpy(a_string, gw_variable[I].gv_dsect);
      check_length();
      strcat(a_string, "DSECT");
      strcpy(wk_remark, " ");
      strcpy(wk_remark, gw_variable[I].gv_name);
      strcpy(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #277");
        trace_rec_3();
      }

      strcpy(a_string, gw_variable[I].gv_aname);
      check_length();
      strcat(a_string, "DS    CL");
      snprintf(wk_strg, sizeof(wk_strg), "%d", gw_variable[I].gv_lgth);
      strcat(a_string, wk_strg);
      strcat(a_string, "' '");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #278");
        trace_rec_3();
      }

      strcpy(a_string, gw_variable[I].gv_label);
      check_length();
      strcat(a_string, "EQU   *-");
      strcat(a_string, gw_variable[I].gv_dsect);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #279");
        trace_rec_3();
      }

      strcpy(a_string, "         DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #280");
        trace_rec_3();
      }

      strcpy(a_string, "*");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #281");
        trace_rec_3();
      }
    }
  }

  for (I = 0; I < gv_ct; I++) 
  {
    convert = 0;
    ret = strcmp(gw_variable[I].gv_type, "G");
    if ((ret == 0) && (convert == 0)) 
    {
      strcpy(a_string, gw_variable[I].gv_dsect);
      check_length();
      strcat(a_string, "DSECT");
      strcpy(wk_remark, " ");
      strcpy(wk_remark, gw_variable[I].gv_name);
      strcpy(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #282");
        trace_rec_3();
      }

      strcpy(a_string, gw_variable[I].gv_aname);
      check_length();
      strcat(a_string, "DS    PL6'0'");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #283");
        trace_rec_3();
      }

      strcpy(a_string, gw_variable[I].gv_label);
      check_length();
      strcat(a_string, "EQU   *-");
      strcat(a_string, gw_variable[I].gv_dsect);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #284");
        trace_rec_3();
      }

      if (gw_variable[I].gv_column % 2 == 0) 
      {
      } else {
        strcpy(a_string, "         DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_eoj.c #285");
          trace_rec_3();
        }
      }

      strcpy(a_string, "*");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #286");
        trace_rec_3();
      }
    }
  }

  x = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    convert = 0;
    ret = strcmp(w_struc[I].st_id, "M");
    if ((ret == 0) && (convert == 0)) 
    {
      if (x != 0) {
        strcpy(tfield3, tfield2);
        strcat(tfield3, "L");
        strcpy(a_string, tfield3);
        check_length();
        strcat(a_string, "EQU   *-");
        strcat(a_string, tfield2);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_eoj.c #287");
          trace_rec_3();
        }

        strcpy(a_string, "*");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_eoj.c #288");
          trace_rec_3();
        }
      }

      x++;
      strcpy(a_string, w_struc[I].st_cwname);
      strcpy(tfield2, w_struc[I].st_cwname);
      check_length();
      strcat(a_string, "DSECT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_eoj.c #289");
        trace_rec_3();
      }
    }

    ret = strcmp(w_struc[I].st_id, "N");
    if (ret == 0) 
    {
      ret1 = strcmp(w_struc[I].st_type, "I");
      if (ret1 == 0) 
      {
        stru_ct++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", stru_ct);
        strcpy(c_wkname, "ST");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(tfield6, c_wkname);

        strcpy(a_string, tfield6);
        check_length();
        strcat(a_string, "DS    PL6'0'");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_eoj.c #290");
          trace_rec_3();
        }
      }

      ret1 = strcmp(w_struc[I].st_type, "C");
      if (ret1 == 0) 
      {
        stru_ct++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", stru_ct);
        strcpy(c_wkname, "ST");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(tfield6, c_wkname);

        strcpy(a_string, tfield6);
        check_length();
        strcat(a_string, "DS    CL");
        snprintf(wk_strg, sizeof(wk_strg), "%d", w_struc[I].st_field_lgth);
        strcat(a_string, wk_strg);
        strcat(a_string, "' '");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_eoj.c #291");
          trace_rec_3();
        }
      }
    }
  }

  if (x > 0) 
  {
    strcpy(tfield3, tfield2);
    strcat(tfield3, "L");
    strcpy(a_string, tfield3);
    check_length();
    strcat(a_string, "EQU   *-");
    strcat(a_string, tfield2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #292");
      trace_rec_3();
    }

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_eoj.c #293");
      trace_rec_3();
    }
  }

  /* *************************************************
  *  Punch out ASM end statement                     *
  * ************************************************ */
  strcpy(a_string, "         END");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_eoj.c #294");
    trace_rec_3();
  }

  /* ************************************************
  *  Close all files used by the parser.            *
  * *********************************************** */
  fclose(pgm);
  fclose(cc370);

  x4 = 0;
  strcpy(a_string, "*  c2z Complete - C Lines of code - ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  s = strlen(a_string);
  if (s < 46) 
  {
    for (v = s; v < 46; v++) 
    {
      strcat(a_string, " ");
    }
  }
  strcat(a_string, "*");
  printf("%s\n", a_string);

  strcpy(a_string, "*               MLC Lines of code - ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", var_use[1]);
  strcat(a_string, wk_strg);
  s = strlen(a_string);
  if (s < 46) 
  {
    for (v = s; v < 46; v++) 
    {
      strcat(a_string, " ");
    }
  }
  strcat(a_string, "*");
  printf("%s\n", a_string);

  strcpy(a_string, "*               Global Variables  - ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", gv_ct);
  strcat(a_string, wk_strg);
  s = strlen(a_string);
  if (s < 46) 
  {
    for (v = s; v < 46; v++) 
    {
      strcat(a_string, " ");
    }
  }
  strcat(a_string, "*");
  printf("%s\n", a_string);

  strcpy(a_string, "*               Local Variables   - ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", lv_ct);
  strcat(a_string, wk_strg);
  s = strlen(a_string);
  if (s < 46) 
  {
    for (v = s; v < 46; v++) 
    {
      strcat(a_string, " ");
    }
  }
  strcat(a_string, "*");
  printf("%s\n", a_string);

  strcpy(a_string, "*               Character Literal - ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", char_ct);
  strcat(a_string, wk_strg);
  s = strlen(a_string);
  if (s < 46) 
  {
    for (v = s; v < 46; v++) 
    {
      strcat(a_string, " ");
    }
  }
  strcat(a_string, "*");
  printf("%s\n", a_string);

  x3 = 0;
  strcpy(a_string, "*               Unused Global Var - ");
  for(I = 0; I < gv_ct; I++)
  {
    if(gw_variable[I].gv_use_ct == 0)
    {
      x3++;
    }
  }
  snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
  strcat(a_string, wk_strg);
  s = strlen(a_string);
  if (s < 46) 
  {
    for (v = s; v < 46; v++) 
    {
      strcat(a_string, " ");
    }
  }
  strcat(a_string, "*");
  printf("%s\n", a_string);

  x3 = 0;
  strcpy(a_string, "*               Unused Local Var  - ");
  for(I = 0; I < lv_ct; I++)
  {
    if(lw_variable[I].lv_use_ct == 0)
    {
      x3++;
    }
  }
  snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
  strcat(a_string, wk_strg);
  s = strlen(a_string);
  if (s < 46) 
  {
    for (v = s; v < 46; v++) 
    {
      strcat(a_string, " ");
    }
  }
  strcat(a_string, "*");
  printf("%s\n", a_string);

  printf("*\t\t\t\t\t      *\n");
  printf("*\t  C\t\t c2z\t\t      *\n");
  printf("*\tFiles\t\tFiles\t\t      *\n");
  for (I = 0; I < f_ct; I++) 
  {
    printf("*\t%s \t\t%s\t\t      *\n", w_file[I].f_name, w_file[I].f_cname);
  }

  printf("***********************************************\n");

  /* ********************************************************
  *  if debug is turned on print out the various structs.   *
  *  debug == 1  (on)                                       *
  *  debug == 0  (off)                                      *
  * ******************************************************* */

  if (debug == 1) 
  {
    c2_debug();
  }
}


/*
STREAM   DS    0C
         DC    X'27'       ESCAPE CHAR
         DC    X'F5'       ERASE/WRITE
         DC    X'C3'       WCC
         DC    X'114BF0'   SBA
         DC    X'2903'     SFE (Three Attribute Pairs To Follow)     
         DC    X'C0F0'     ATTR #1 (BASIC = PROTECTED)
         DC    X'41F2'     ATTR #2 (HIGHLIGHTING = REVERSE)
         DC    X'42F6'     ATTR #3 (COLOR = YELLOW)
         DC    C'HELLO, WORLD!'
         DC    X'1DF0'     SF (PROTECTED / END PREV FIELD)
STREAMLN EQU   *-STREAM
*/
