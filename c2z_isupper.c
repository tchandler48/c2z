/* ***************************************************
*  c2z : c2z_isupper.c :                             *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

void c2_isupper() 
{
  int s = 0;
  int x3 = 0;
  int v = 0;
  int size = 0;
  int ret = 0;

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';

  x3 = 0;
  for (v = 0; v < gv_ct; v++) 
  {
    ret = strcmp("ISUPPER", gw_variable[v].gv_name);
    if (ret == 0)
    {
      x3 = 1;
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct == 0) 
    {
      size = 1;
      gw_variable = malloc(size * sizeof(struct variables));
    } 
    else 
    {
      size = gv_ct + 1;
      gw_variable = realloc(gw_variable, size * sizeof(struct variables));
    }

    gw_variable[gv_ct].gv_rct = rct;
    strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
    strcpy(gw_variable[gv_ct].gv_name, "ISUPPER");
    strcpy(gw_variable[gv_ct].gv_type, "F");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gv_ct++;
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c");
    trace_rec_3();
  }

  strcpy(a_string, "ISUPPER  DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #2");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370ISAL");
  strcpy(wk_remark, " C370ISAL */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  strcpy(wk_remark, " C370ZERO */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #4");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #6");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #7");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #8");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #9");
    trace_rec_3();
  }
  strcpy(a_string, "*  Start test for TSTUC ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,27");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #10");
    trace_rec_3();
  }

  strcpy(a_string, "ISU01    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #11");
    trace_rec_3();
  }

/*  test tstuc */

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #12");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #13");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R7),2(4,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #14");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #15");
    trace_rec_3();
  }

  strcpy(a_string, "         CVB   R4,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #16");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,TSTUC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #17");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R7,(R4))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #18");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,C370L2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #19");
    trace_rec_3();
  }

  strcpy(a_string, "         STC   R0,0(0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #20");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R9),0(R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #21");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ISU03");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #22");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #23");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #24");
    trace_rec_3();
  }
 
  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #25");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R5,ISU01");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #26");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ISU99");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #27");
    trace_rec_3();
  }

  strcpy(a_string, "ISU03    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #28");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370ISAL");
  strcpy(wk_remark, " C370ISAL */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #29");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  strcpy(wk_remark, " C370ONE */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #30");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #31");
    trace_rec_3();
  }

  strcpy(a_string, "ISU99    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #32");
    trace_rec_3();
  }

  strcpy(a_string, "         PR");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c isupper #33");
    trace_rec_3();
  }
}


void c2_toupper()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_isupper.c c2_toupper START");
    trace_rec_1();
  }
printf("c2z_isupper.c c2_toupper rct = %d p_string = %s",rct,p_string);

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  
   int pi;
   int pi2;
   int x3;
   int x500;
   int ret;
   int ret1;
   int v;

  pi = 0;
  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ')')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';
printf("c2z_isupper.c c2_toupper field1 = %s\n",field1);

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        strcpy(field1a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        x500 = lw_variable[v].lv_current_lgth;
        x3 = 1;
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field1, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          strcpy(field1a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
          x500 = gw_variable[v].gv_current_lgth;
          x3 = 1;
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_isupper.c c2_toupper E-057 field1 Not Found = %s\n", field1);
    printf("c2z_isupper.c c2_toupper rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }
printf("c2z_isupper.c c2_toupper field1a = %s lgth = %d\n",field1a,x500);

  if(x500 == 1)
  { 
     strcpy(a_string, "         LARL  R9,C370NWK1");
     strcat(wk_remark, " max loop 27 */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #1");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         LARL  R8,C370ZERO");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #2");
       trace_rec_3();
     }
     work_use_ct[32]++;
  
     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #3");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370NWK2");
     strcat(wk_remark, " current index  */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #4");
       trace_rec_3();
     }
     work_use_ct[50]++;

     strcpy(a_string, "         LARL  R8,C370ZERO");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #5");
       trace_rec_3();
     }
     work_use_ct[32]++;
   
     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #6");
       trace_rec_3();
     }

     strcpy(a_string, "         LAEY  R5,26");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #7");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #8");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         CVD   R5,0(R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #9");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #9");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         LARL  R7,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #10");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #11");
       trace_rec_3();
     }

     strcpy(a_string, "L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "A");
     check_length();
     strcat(a_string, "DS    0H");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #12");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #13");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         LARL  R8,C370NWK2");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #14");
       trace_rec_3();
     }
     work_use_ct[49]++; 

     strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #15");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #16");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         CVB   R5,0(R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #17");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370TLC");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #18");
       trace_rec_3();
     }

     strcpy(a_string, "         IC    R0,0(R8,(R5))");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #19");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370L1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #20");
       trace_rec_3();
     }
     work_use_ct[2]++;

     strcpy(a_string, "         STC   R0,0(0,R9)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #21");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,");
     strcat(a_string, field1a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field1);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #22");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370L1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #23");
       trace_rec_3();
     }
     work_use_ct[2]++;

     strcpy(a_string, "         CLC   0(1,R9),0(R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #24");
       trace_rec_3();
     }

     strcpy(a_string, "         JLE   L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "E");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #25");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370NWK2");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #26");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         LARL  R8,C370ONE");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #27");
       trace_rec_3();
     }

     strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #28");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370NWK2");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #29");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #30");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #31");
       trace_rec_3();
     }

     strcpy(a_string, "         JLL   L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "A");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #32");
       trace_rec_3();
     }

     strcpy(a_string, "         JLE   L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "A");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #33");
       trace_rec_3();
     }

     strcpy(a_string, "         JLU   L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "F");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #32");
       trace_rec_3();
     }

     strcpy(a_string, "L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "E");
     check_length();
     strcat(a_string, "DS    0H");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #33");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #34");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         LARL  R8,C370NWK2");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #35");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #36");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #37");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         CVB   R5,0(R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #38");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370TUC");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #39");
       trace_rec_3();
     }

     strcpy(a_string, "         IC    R0,0(R8,(R5))");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #40");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370L1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #41");
       trace_rec_3();
     }
     work_use_ct[2]++;

     strcpy(a_string, "         STC   R0,0(0,R9)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #42");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,");
     strcat(a_string, field1a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field1);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #43");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370L1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #44");
       trace_rec_3();
     }
     work_use_ct[2]++;

     strcpy(a_string, "         MVC   0(1,R9),0(R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #45");
       trace_rec_3();
     }

     strcpy(a_string, "L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "F");
     check_length();
     strcat(a_string, "DS    0H");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_isupper.c c2_toupper #46");
       trace_rec_3();
     }
   }

  convert = 1;
  return;
}
