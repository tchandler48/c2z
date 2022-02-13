/* ***************************************************
*  c2z : c2z_scanf.c :                               *
*                                                    *
*  next error scanf-004                              *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out SCANF                                   *
* ************************************************** */
void c2_scanf() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf");
    trace_rec_1();
  }

  char *p;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int x = 0;
  int x1 = 0;
  int x5 = 0;
  int x6 = 0;
  int ret = 0;
  int ret1 = 0;

  p = strstr(p_string, "%c");
  if (p) 
  {
    x = 1;
    x1 = 1;
  }

  p = strstr(p_string, "%s");
  if (p) 
  {
    x = 1;
    x1 = 2;
  }

  p = strstr(p_string, "%d");
  if (p) 
  {
    x = 1;
    x1 = 3;
  }

  if (x == 0) 
  {
    printf("\nc2z_scanf.c c2_scanf scanf-001 ERROR Invalid edit code\n");
    printf("c2z_scanf.c c2_scanf rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (x1 == 1) 
  {
    pi = 0;
    ch = p_string[pi];
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != ' ') 
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    x5 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x5 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
      }
    }

    if (x5 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x5 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x5 == 0) 
    {
      printf("\nc2z_scanf.c c2_scanf scanf-002 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_scanf.c c2_scanf rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x6 = 1;

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ECB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #2");
      trace_rec_3();
    }
    work_use_ct[93]++;

    strcpy(a_string, "         WTOR  '?',(R9),");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
    strcat(a_string, wk_strg);
    strcat(a_string, ",(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #3");
      trace_rec_3();
    }

    strcpy(a_string, "         WAIT   ECB=(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #4");
      trace_rec_3();
    }

    x5 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x5 = 1;
        lw_variable[I].lv_current_lgth = x6;
      }
    }

    if (x5 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x5 = 1;
          gw_variable[I].gv_current_lgth = x6;
        }
      }
    }

    convert = 1;
    return;
  }

  if (x1 == 2) 
  {
    pi = 0;
    ch = p_string[pi];
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != ' ') 
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    x5 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x5 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        x6 = lw_variable[I].lv_lgth;
      }
    }

    if (x5 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x5 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          x6 = gw_variable[I].gv_lgth;
        }
      }
    }

    if (x5 == 0) 
    {
      printf("\nc2z_scanf.c c2_scanf scanf-003 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_scanf.c c2_scanf rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #6");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #7");
      trace_rec_3();
    }

    x6--;
    snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
    strcpy(a_string, "         MVC   1(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #8");
      trace_rec_3();
    }
    x6++;

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ECB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #10");
      trace_rec_3();
    }
    work_use_ct[93]++;

    strcpy(a_string, "         WTOR  '?',(R9),");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
    strcat(a_string, wk_strg);
    strcat(a_string, ",(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #11");
      trace_rec_3();
    }

    strcpy(a_string, "         WAIT  ECB=(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #12");
      trace_rec_3();
    }

    strcpy(a_string, "         SR    R5,R5");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #13");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #14");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #15");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #16");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #17");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #18");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #19");
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
      strcpy(trace_1, "c2z_scanf.c #20");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #21");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #22");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #23");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #24");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R5,0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #25");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #26");
      trace_rec_3();
    }

    strcpy(a_string, "         IC    R0,0(R8,R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #27");
      trace_rec_3();
    }

                                  
    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #28");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         STC   R0,0(0,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #29");
      trace_rec_3();
    }
                                            
    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #30");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #31");
      trace_rec_3();
    }

    strcpy(a_string, "         JLNE  L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #32");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #33");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #34");
      trace_rec_3();
    }
    work_use_ct[79]++;

    strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #35");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #36");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #37");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #38");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #39");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #40");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #41");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R2,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #42");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #43");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R1,R9");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #44");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R1,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #45");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #46");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R1),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #47");
      trace_rec_3();
    }

    x5 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x5 = 1;
        lw_variable[I].lv_current_lgth = x6;
      }
    }

    if (x5 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) {
          x5 = 1;
          gw_variable[I].gv_current_lgth = x6;
        }
      }
    }

    convert = 1;
    return;
  }

  if (x1 == 3) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != ' ') 
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    x5 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x5 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        x6 = lw_variable[I].lv_lgth;
      }
    }

    if (x5 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x5 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          x6 = gw_variable[I].gv_lgth;
        }
      }
    }

    if (x5 == 0) 
    {
      printf("\nc2z_scanf.c c2_scanf scanf-003 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_scanf.c c2_scanf rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #48");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ECB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #49");
      trace_rec_3();
    }
    work_use_ct[77]++;

    strcpy(a_string, "         WTOR  '?',(R9),");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
    strcat(a_string, wk_strg);
    strcat(a_string, ",(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #40");
      trace_rec_3();
    }

    strcpy(a_string, "         WAIT   ECB=(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #51");
      trace_rec_3();
    }

    x5 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x5 = 1;
        lw_variable[I].lv_current_lgth = x6;
      }
    }

    if (x5 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) {
          x5 = 1;
          gw_variable[I].gv_current_lgth = x6;
        }
      }
    }

    convert = 1;
    return;
  }
}
