/* ***************************************************
*  c2z : c2z_strchr.c :                              *
*                                                    *
*  next error = strchr-005                           *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* ***************************************************
*  Punch out STRCHR                                  *
* ************************************************** */
void c2_strchr() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr");
    trace_rec_1();
  }

  char ch;
  char *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3a[VAR_LGTH];

  int pi;
  int pi2;
  int x3 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;

  pi = 0;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ' ') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  I = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
    }
  }

  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(tfield1, gw_variable[I].gv_name);
    if (ret == 0) 
    {
      x3 = 1;
      strcpy(tfield1a, gw_variable[I].gv_cname);
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_string.c c2_strchr strchr-001 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_string.c c2_strchr rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi++;
  ch = p_string[pi];
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
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  I = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield2, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(tfield2a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield2a, gw_variable[I].gv_cname);
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_string.c c2_strchr strchr-002 tfield2 Not Found = %s\n", tfield2);
    printf("c2z_string.c c2_strchr rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  use_strchr++;

  p = strstr(p_string, "\'");
  if (p) 
  {
    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(tfield3a, w_charlit[I].clit_cname);
        x3 = w_charlit[I].clit_lgth;
      }
    }

    strcpy(a_string, "         LARL  R9,C370L1A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_string.c c2_strchr #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_string.c c2_strchr #2");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_string.c c2_strchr #3");
      trace_rec_3();
    }
    work_use_ct[59]++;
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #4");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #5");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(4,R9),0(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #6");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcpy(sv_for_return, a_string);
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #7");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #8");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #9");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         AP    0(4,R9),0(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #10");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #11");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #12");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #14");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #15");
    trace_rec_3();
  }

  strcpy(a_string, "         AHI   R5,-1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #16");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield2a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #17");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,R9");
  strcat(a_string, "(R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #18");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #19");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #20");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   C370L1A,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #21");
    trace_rec_3();
  }
  work_use_ct[74]++;

  strcpy(a_string, "         JLE   ");
  strcat(a_string, sv_for_return);
  strcat(a_string, "F");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #22");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   C370L1,C370L1A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #23");
    trace_rec_3();
  }
  work_use_ct[59]++;

  strcpy(a_string, "         JLE   ");
  strcat(a_string, sv_for_return);
  strcat(a_string, "E");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #24");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, sv_for_return);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #25");
    trace_rec_3();
  }

  strcpy(a_string, sv_for_return);
  strcat(a_string, "E");
  ;
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #26");
    trace_rec_3();
  }

  /* 0 = not found */
  /* 1 = found     */

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield1a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #27");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #28");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(4,R9),0(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #29");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, sv_for_return);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #30");
    trace_rec_3();
  }

  strcpy(a_string, sv_for_return);
  strcat(a_string, "F");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #31");
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
    strcpy(trace_1, "c2z_string.c c2_strchr #32");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #33");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(4,R9),0(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #34");
    trace_rec_3();
  }

  strcpy(a_string, sv_for_return);
  strcat(a_string, "Z");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #35");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr #36");
    trace_rec_3();
  }
}

/* ***************************************************
*  Scan pass 2 STRCHR                                *
* ************************************************** */
void c2_strchr_scan() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_strchr_scan");
    trace_rec_1();
  }

  char ch;
  char *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];

  int pi;
  int pi2;
  int x3 = 0;
  int x5 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int s;
  int size;

  pi = 0;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ' ') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  I = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
    }
  }

  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(tfield1, gw_variable[I].gv_name);
    if (ret == 0) 
    {
      x3 = 1;
      strcpy(tfield1a, gw_variable[I].gv_cname);
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_string.c c2_strchr strchr-003 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_string.c c2_strchr rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi++;
  ch = p_string[pi];
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
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  I = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield2, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(tfield2a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield2a, gw_variable[I].gv_cname);
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_string.c c2_strchr strchr-004 tfield2 Not Found = %s\n", tfield2);
    printf("c2z_string.c c2_strchr rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  x5 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (ch != '\'') 
    {
      if (ch != ' ') 
      {
        tfield3[pi2] = ch;
        pi2++;
        x5++;
      }
    }
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  p = strstr(p_string, "'");
  if (p) 
  {
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
    w_charlit[char_ct].clit_lgth = x5;
    w_charlit[char_ct].clit_type = 3;
    char_ct++;

    convert = 1;
  }
}
