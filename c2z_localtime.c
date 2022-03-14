/* ***************************************************
*  c2z  : c2z_localtime.c :                          *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  localtime                                         *
* ************************************************** */

void c2_localtime_time() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_localtime.c c2_localtime_time START");
    trace_rec_1();
  }

  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];

  int x3;
  int I;
  int ret;

  x3 = 0;
  strcpy(tfield1,"tm");
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(tfield1, w_struc[I].st_name);
    if(ret == 0)
    {
       x3 = 1;
       strcpy(tfield1a, w_struc[I].st_cname);
       break;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_localtime.c c2_localtime E-059 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_localtime.c c2_localtime rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "         LARL  R9,C370TIME");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_localtime.c #1");
    trace_rec_3();
  }

  strcpy(a_string, "         TIME  TS,C370TIME");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_localtime.c #2");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_localtime.c #3");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_localtime.c #4");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_localtime.c #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, tfield1a);
  strcat(a_string, "T");
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_localtime.c #6");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_localtime.c #7");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370TIME");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_localtime.c #8");
    trace_rec_3();
  }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, "17(2,R6),5(R9)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, " tm_mon");
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #9");
      trace_rec_3();
    }
    
    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #10");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   19(1,R6),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #11");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, "14(2,R6),8(R9)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, " tm_mday");
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #12");
      trace_rec_3();
    }
    
    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #13");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   16(1,R6),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #14");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, "20(4,R6),0(R9)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, " tm_year");
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #15");
      trace_rec_3();
    }
    
    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #16");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   24(1,R6),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #17");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, "11(2,R6),11(R9)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, " tm_hour");
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #18");
      trace_rec_3();
    }
    
    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #19");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   13(1,R6),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #20");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, "8(2,R6),14(R9)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, " tm_min");
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #21");
      trace_rec_3();
    }
    
    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #22");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   10(1,R6),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #23");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, "5(2,R6),17(R9)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, " tm_sec");
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #24");
      trace_rec_3();
    }
    
    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #25");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   7(1,R6),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_localtime.c #26");
      trace_rec_3();
    }

    convert = 1;
    return;
}
