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
    work_use_ct[77]++;

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

    if (x5 == 0) {
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

    strcpy(a_string, "         LARL  R8,C370ECB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #6");
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
      strcpy(trace_1, "c2z_scanf.c #7");
      trace_rec_3();
    }

    strcpy(a_string, "         WAIT   ECB=(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_scanf.c #8");
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
    convert = 1;
    return;
  }
}
