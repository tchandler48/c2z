/* ***************************************************
*  c2z : c2z_scanf.c :                               *
*                                                    *
*  next error scanf-004                              *
*  Copyright TCCS (c) 2015 - 2020                    *
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
  char msg1[23]; 
  int pi;
  int pi2;
  int I = 0;
  int x = 0;
  int x1 = 0;
  int x5 = 0;
  int x6 = 0;
  int x9 = 0;
  int ret = 0;
  int ret1 = 0;

  strcpy(msg1, "c2z_scanf.c c2_scanf ");
  msg1[23] = '\0';


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
      strcpy(trace_1, msg1);
      strcat(trace_1, "#1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ECB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#2");
      trace_rec_3();
    }
    work_use_ct[86]++;

    strcpy(a_string, "         WTOR  '?',(R9),");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
    strcat(a_string, wk_strg);
    strcat(a_string, ",(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#3");
      trace_rec_3();
    }

    strcpy(a_string, "         WAIT   ECB=(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #4");
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

    strcpy(a_string, "         LARL  R11,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R10,");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOINP");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #7");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #8");
      trace_rec_3();
    }

/*
R1 = contains number of bytes read
*/
    strcpy(a_string, "         LR    R5,R1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #10");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #11");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #12");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #13");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #14");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #16");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #18");
      trace_rec_3();
    }

    strcpy(a_string, "         CVB   R2,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #18");
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
      strcpy(trace_1, "c2z_scanf.c c2_scanf #19");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R1,R9");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #20");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R1,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #20");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #21");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R9,R1),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #22");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  if (x1 == 3) 
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
      printf("\nc2z_scanf.c c2_scanf scanf-013 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_scanf.c c2_scanf rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#100");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#101");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#102");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   1(7,R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#103");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R11,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#104");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R10,7");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#105");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOINP");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#106");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#107");
      trace_rec_3();
    }

/*
R1 = contains number of bytes read
*/
    strcpy(a_string, "         LR    R5,R1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#108");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#109");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#110");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #111");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #112");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #113");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #114");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #115");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #116");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #117");
      trace_rec_3();
    }

    strcpy(a_string, "         CVB   R2,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #118");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #119");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R1,R9");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #120");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R1,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #121");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #122");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R9,R1),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #123");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #124");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #125");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #126");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   1(7,R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #127");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #128");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R7,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #129");
      trace_rec_3();
    }
    work_use_ct[74]++;

    x9 = 0;
    strcpy(a_string, "         CLC   0(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #130");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #131");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #132");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #133");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   1(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #134");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #135");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   1(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #136");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #137");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   2(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #138");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #139");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   2(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #140");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #141");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   3(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #142");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #143");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   3(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #144");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, msg1);
      strcat(trace_1, "#145");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   4(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #146");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #147");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   4(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #148");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #149");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   5(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #150");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #151");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   5(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #152");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #153");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   6(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #154");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #155");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   6(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #156");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "G");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #157");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   7(1,R9),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #158");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "X");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #159");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   7(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #160");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "X");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #161");
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
    strcpy(trace_1, "c2z_scanf.c c2_scanf #162");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #163");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #164");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   7(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #165");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #166");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #167");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #168");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #169");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   6(2,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #170");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #171");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #172");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #173");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #174");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   5(3,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #175");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #176");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "D");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #177");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #178");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #179");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   4(4,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #180");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #181");
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
    strcpy(trace_1, "c2z_scanf.c c2_scanf #182");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #183");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #184");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   3(5,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #185");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #186");
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
    strcpy(trace_1, "c2z_scanf.c c2_scanf #187");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #188");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #189");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   2(6,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #190");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #191");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "G");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #192");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #193");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #194");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   1(7,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #195");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #196");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "X");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #197");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #198");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #199");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   0(8,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #200");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_scanf.c c2_scanf #201");
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
      strcpy(trace_1, "c2z_scanf.c c2_scanf #202");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #203");
      trace_rec_3();
    }
    work_use_ct[8]++;

    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcpy(a_string, "         PACK  0(6,R9),0(7,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c c2_scanf #204");
      trace_rec_3();
    }

    convert = 1;
    return;
  }
}
