/* ***************************************************
*  c2z : c2z_strstr.c :                              *
*                                                    *
*  next error - strstr-006                           *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out STRSTR                                  *
* ************************************************** */
void c2_strstr() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr START");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield5a[VAR_LGTH];

  int pi = 0;
  int pi2 = 0;
  int s2 = 0;
  int x21 = 0;
  int x3 = 0;
  int x80 = 0;
  int x100;
  int I = 0;
  int ret = 0;
  int s = 0;

  x100 = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[') 
    {
      x80++;
    }
    if(ch == '[')
    {
      x100++;
    }
    if(ch == ']')
    {
      x100++;
    }
  }

  if(x100 == 4)
  {
    c2_strstr_41();
    convert = 1;
    return;
  }

  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ' ') 
  {
    if (ch != '*') 
    {
      tfield1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';
  s2 = strlen(tfield1);

  /*  p = strstr(argv[2], "-d"); */

  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    if (ch != ' ') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield2[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch != '\"') 
  {
    pi++;
    ch = p_string[pi];
  }

  x21 = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    x21 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x21 == 0)) 
    {
      x3 = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    x3 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield1a, gw_variable[I].gv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strstr.c c2_strstr strstr-001 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x21 = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield2, lw_variable[I].lv_name);
    x21 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x21 == 0)) 
    {
      x3 = 1;
      strcpy(tfield2a, lw_variable[I].lv_cname);
      s2 = lw_variable[I].lv_lgth;
    }
  }

  if (x3 == 0) 
  {
    x3 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield2a, gw_variable[I].gv_cname);
        s2 = gw_variable[I].gv_lgth;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("c2z_strstr.c c2_strstr strstr-002 tfield2 Not Found = %s\n", tfield2);
    printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
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
    strcpy(trace_1, "c2z_strstr.c c2_strstr #1");
    trace_rec_3();
  }
 
  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #2");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R7,");
  snprintf(wk_strg, sizeof(wk_strg), "%d", s2);
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #2");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #3");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #4");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #6");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #7");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #9");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #10");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, tfield2a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield2);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #11");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,");
  strcat(a_string, "0(R8,");
  strcat(a_string, "(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #12");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #13");
    trace_rec_3();
  }

  strcpy(a_string, "         STC   R0,");
  strcat(a_string, "0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #14");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #15");
    trace_rec_3();
  }
  work_use_ct[74]++;

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #16");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #17");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #18");
    trace_rec_3();
  }

  for (I = 0; I < char_ct; I++) 
  {
    if (w_charlit[I].clit_rct == rct) 
    {
      strcpy(tfield5a, w_charlit[I].clit_cname);
    }
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield5a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #19");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #20");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #21");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #22");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #23");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #24");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #25");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         JCT   R7,");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #26");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #27");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield1a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #28");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #29");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #30");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #31");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #32");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield1a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #33");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #34");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #35");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #36");
    trace_rec_3();
  }
}

void c2_strstr_scan() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr_scan START");
    trace_rec_1();
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr_scan subroutine #100");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield4a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];

  int pi = 0;
  int pi2 = 0;
  int x2 = 0;
  int x3 = 0;
  int x21 = 0;
  int x80 = 0;
  int x81 = 0;
  int x100 = 0;
  int I = 0;
  int ret = 0;
  int s = 0;
  int size = 0;
/*
  int fd3_type;
  int fd4_type;
*/
  int fd5_type;

  x80 = 999;
  x100 = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if(ch == ',')
    {
      x81 = I;
    }
    if (ch == '[') 
    {
      x80 = I;
    }
    if(ch == '[')
    {
      x100++;
    }
    if(ch == ']')
    {
      x100++;
    }
  }

  if((x81 < x80) && (x100 == 0))
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_strstr.c c2_strstr_scan subroutine #101");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      if (ch != '*') 
      {
        tfield1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield1[pi2] = '\0';

    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch != ' ') 
      {
        tfield2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield2[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch != '\"') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '\"') 
    {
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strstr.c c2_strstr_scan strstr-003 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strstr.c c2_strstr_scan strstr-004 tfield2 Not Found = %s\n",tfield2);
      printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = strlen(tfield3);
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield3a, c_wkname);

    if (char_ct == 0) 
    {
      size = 1;
      w_charlit = malloc(size * sizeof(struct charlit));
    } 
    else 
    {
      size = char_ct + 1;
      w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
    }

    w_charlit[char_ct].clit_rct = rct;
    strcpy(w_charlit[char_ct].clit_cname, tfield3a);
    strcpy(w_charlit[char_ct].clit_value, tfield3);
    w_charlit[char_ct].clit_type = 3;
    w_charlit[char_ct].clit_lgth = x3;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;
  }

  if((x80 < x81) && (x100 == 0))
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_strstr.c c2_strstr_scan subroutine #200");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      if (ch != '*') 
      {
        tfield1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield1[pi2] = '\0';
printf("c2z_strstr.c c2z_strstr_scan rct = %d p_string = %s",rct,p_string);
printf("c2z_strstr.c c2z_strstr_scan tfield1 = %s\n",tfield1);

    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if (ch != ' ') 
      {
        tfield2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield2[pi2] = '\0';
printf("c2z_strstr.c c2z_strstr_scan tfield2 = %s\n",tfield2);

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if (ch != ' ') 
      {
        tfield3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield3[pi2] = '\0';
printf("c2z_strstr.c c2z_strstr_scan tfield3 = %s\n",tfield3);

    printf("\nc2z_strstr.c c2_strstr_scan strstr-005 NEED TO FINISH\n");
    printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }



  if((x80 < x81) && (x100 == 4))
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_strstr.c c2_strstr_scan subroutine #400");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      if (ch != '*') 
      {
        tfield1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield1[pi2] = '\0';

    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if (ch != ' ') 
      {
        tfield2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield2[pi2] = '\0';

    pi2 = 0;
    x2 = 0;
/*    fd3_type = 0; */
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if (ch != ' ') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
        /*    fd3_type = 1; */
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
       /*     fd3_type = 2; */
            x2 = 1;
          }
        }
        tfield3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield3[pi2] = '\0';

    pi2 = 0;
    x2 = 0;
/*    fd4_type = 0; */
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if (ch != '[') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
         /*   fd4_type = 1; */
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
        /*    fd4_type = 2; */
            x2 = 1;
          }
        }
        tfield4[pi2] = ch;
        pi2++;
      } 
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

    pi++;
    pi++;
    ch = p_string[pi];
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    x2 = 0;
    fd5_type = 0;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          fd5_type = 1;
          x2 = 1;
        }
        if (isalpha(ch)) 
        {
          fd5_type = 2;
          x2 = 1;
        }
      }
      tfield5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield5[pi2] = '\0';

    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strstr.c c2_strstr_scan E-103 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
 
    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strstr.c c2_strstr_scan E-104 tfield2 Not Found = %s\n",tfield2);
      printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield3, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield3a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield3, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield3a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strstr.c c2_strstr_scan E-105 tfield3 Not Found = %s\n",tfield3);
      printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield4, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield4a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield4a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strstr.c c2_strstr_scan E-6 tfield4 Not Found = %s\n",tfield4);
      printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if(fd5_type == 0)
    {

      x2 = 0;
      pi = 1;
      ch = tfield5[pi];
      while(ch != '\"')
      {
        tfield5a[x2] = ch;
        x2++;
        pi++;
        ch = tfield5[pi];
      }
      tfield5a[x2] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';

      if (char_ct == 0) 
      {
        size = 1;
        w_charlit = malloc(size * sizeof(struct charlit));
      } 
      else 
      {
        size = char_ct + 1;
        w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
      }

      w_charlit[char_ct].clit_rct = rct;
      strcpy(w_charlit[char_ct].clit_cname, c_wkname);
      strcpy(w_charlit[char_ct].clit_value, tfield5a);
      w_charlit[char_ct].clit_type = 3;
      s = strlen(tfield5a);
      w_charlit[char_ct].clit_lgth = s;
      w_charlit[char_ct].clit_uct = 1;
      char_ct++;
    }
  }
}



void c2_strstr_41()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr_41 START");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield4a[VAR_LGTH];
/*  char tfield5[VAR_LGTH]; */
/*  char tfield5a[VAR_LGTH]; */

  int pi = 0;
  int pi2 = 0;
  int x2 = 0;
  int x3 = 0;
  int x21 = 0;

/*  int x80 = 0;
  int x81 = 0;
  int x100 = 0;
  int x101 = 0;
  int x102 = 0; 
*/

  int I = 0;
  int ret = 0;

/*  int s = 0;
  int s2 = 0;
  int size = 0;
  int ret1;
  int ret2;
  int v; 
*/

/*
  int fd3_type;
  int fd4_type;
  int fd5_type;
*/

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ' ') 
  {
    if (ch != '*') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield1[pi2] = '\0';

  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != '[') 
  {
    if (ch != ' ') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield2[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
/*  fd3_type = 0; */
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if (ch != ' ') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
     /*     fd3_type = 1; */
          x2 = 1;
        }
        if (isalpha(ch)) 
        {
  /*        fd3_type = 2; */
          x2 = 1;
        }
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield3[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
/*  fd4_type = 0; */
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if (ch != '[') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
   /*       fd4_type = 1; */
          x2 = 1;
        }
        if (isalpha(ch)) 
        {
   /*       fd4_type = 2; */
          x2 = 1;
        }
      }
      tfield4[pi2] = ch;
      pi2++;
    } 
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

  pi++;
  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
/*  fd5_type = 0; */
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (x2 == 0) 
    {
      if (isdigit(ch)) 
      {
/*        fd5_type = 1; */
        x2 = 1;
      }
      if (isalpha(ch)) 
      {
/*        fd5_type = 2; */
        x2 = 1;
      }
    }
  /*  tfield5[pi2] = ch; */
    pi2++;
    pi++;
    ch = p_string[pi];
  }
 /* tfield5[pi2] = '\0'; */

  x21 = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    x21 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x21 == 0)) 
    {
      x3 = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    x3 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield1a, gw_variable[I].gv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strstr.c c2_strstr_scan E-203 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }
 
  x21 = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield2, lw_variable[I].lv_name);
    x21 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x21 == 0)) 
    {
      x3 = 1;
      strcpy(tfield2a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    x3 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield2a, gw_variable[I].gv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strstr.c c2_strstr_scan E-204 tfield2 Not Found = %s\n",tfield2);
    printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x21 = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield3, lw_variable[I].lv_name);
    x21 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x21 == 0)) 
    {
      x3 = 1;
      strcpy(tfield3a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    x3 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield3a, gw_variable[I].gv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strstr.c c2_strstr_scan E-205 tfield3 Not Found = %s\n",tfield3);
    printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x21 = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield4, lw_variable[I].lv_name);
    x21 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x21 == 0)) 
    {
      x3 = 1;
      strcpy(tfield4a,lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    x3 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield4, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield4a, gw_variable[I].gv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strstr.c c2_strstr_scan E-206 tfield4 Not Found = %s\n",tfield4);
    printf("c2z_strstr.c c2_strstr rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

/*  if(fd5_type == 0)
  {
    x2 = 0;
    pi = 1;
    ch = tfield5[pi];
    while(ch != '\"')
    {
      tfield5a[x2] = ch;
      x2++;
      pi++;
      ch = tfield5[pi];
    }
    tfield5a[x2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

    if (char_ct == 0) 
    {
      size = 1;
      w_charlit = malloc(size * sizeof(struct charlit));
    } 
    else 
    {
      size = char_ct + 1;
      w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
    }

    w_charlit[char_ct].clit_rct = rct;
    strcpy(w_charlit[char_ct].clit_cname, c_wkname);
    strcpy(w_charlit[char_ct].clit_value, tfield5a);
    w_charlit[char_ct].clit_type = 3;
    s = strlen(tfield5a);
    w_charlit[char_ct].clit_lgth = s;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;
  }
*/

  strcpy(a_string, "         LARL  R9,C370MATH");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_str_41 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, tfield3a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_str_41 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_str_41 #3");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_str_41 #4");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, tfield4a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield4);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_str_41 #5");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_str_41 #6");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R9,C370MATH");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_str_41 #7");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_str_41 #8");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_str_41 #9");
    trace_rec_3();
  }

/*
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #6");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #7");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #9");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #10");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, tfield2a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield2);
  
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #11");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,");
  strcat(a_string, "0(R8,");
  strcat(a_string, "(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #12");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #13");
    trace_rec_3();
  }

  strcpy(a_string, "         STC   R0,");
  strcat(a_string, "0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #14");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #15");
    trace_rec_3();
  }
  work_use_ct[74]++;

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #16");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #17");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #18");
    trace_rec_3();
  }

  for (I = 0; I < char_ct; I++) 
  {
    if (w_charlit[I].clit_rct == rct) 
    {
      strcpy(tfield5a, w_charlit[I].clit_cname);
    }
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield5a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #19");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #20");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #21");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #22");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #23");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #24");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #25");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         JCT   R7,");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #26");
    trace_rec_3();
  }
*/


  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #27");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield1a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #28");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #29");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #30");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #31");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #32");
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
    strcpy(trace_1, "c2z_strstr.c c2_strstr #33");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #34");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #35");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_strstr #36");
    trace_rec_3();
  }





}

