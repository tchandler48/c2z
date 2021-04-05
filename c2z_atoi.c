/* ***************************************************
*  c2z : c2z_atoi.c :                                *
*                                                    *
*  next error - atoi-006                             *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* ***************************************************
*  Punch out atoi                                    *
* ************************************************** */
void c2_atoi(void) 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_atoi.c c2_atoi rct = %d START\n", rct);
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.atoi.c c2_atoi START");
    trace_rec_1();
  }

  int pi;
  int pi2;
  int x3 = 0;
  int x9 = 0;
  int x30 = 0;
  int x31 = 0;
  int I = 0;
  int s = 0;
  int ret = 0;
  int ret1 = 0;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];
  char ar_field12[VAR_LGTH];

  use_atoi++;

  x30 = 0;
  x31 = 0;
  s = strlen(p_string);
  for(I=0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '[')
    {
      x30++;
    }
    if(ch == ']')
    {
       x31++;
    }
  }

  if((x30 == 0) && (x31 == 0))
  {
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
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-001 field1 Not Found = %s\n", field1);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        x9 = lw_variable[I].lv_lgth;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x9 = gw_variable[I].gv_lgth;
        }
      }
    }

    pi2 = 0;
    pi = 0;
    ch = field2[pi];

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-002 field2 Not Found = %s\n", field2);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if((x30 == 1) && (x31 == 1))
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != '[') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    x3 = 0;
    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(ar_field5, gw_variable[I].gv_dsect);
          strcpy(ar_field6, gw_variable[I].gv_label);
          strcpy(ar_field7, gw_variable[I].gv_table);
          strcpy(ar_field8, gw_variable[I].gv_aname);
          strcpy(ar_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar_field11, gw_variable[I].gv_wk_strg);
          strcpy(ar_field12, gw_variable[I].gv_type);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-003 field1 Not Found = %s\n", field1);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-004 field2 Not Found = %s\n", field2);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }


    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field3, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field3a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field3, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field3a, gw_variable[I].gv_cname);
          x9 = gw_variable[I].gv_lgth;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-005 field3 Not Found = %s\n", field3);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if(x9 > 8)
    {
      x9 = 8;
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #300");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #301");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #302");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   1(7,R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #303");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #304");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #305");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #306");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   1(7,R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #307");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #308");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #309");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #310");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #311");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #312");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         LARL  R7,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #313");
      trace_rec_3();
    }
    work_use_ct[74]++;

    x9 = 0;
    strcpy(a_string, "         CLC   0(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #314");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #315");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #316");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #317");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   1(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #318");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #319");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   1(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #320");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #321");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   2(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #322");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #323");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   2(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #324");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #325");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   3(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #326");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #327");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   3(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #328");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #329");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   4(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #330");
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
      strcpy(trace_1, "c2z_ato1.c c2_atoi #331");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   4(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #332");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #333");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   5(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #334");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #335");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   5(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #336");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #337");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   6(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #338");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #339");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   6(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #340");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #341");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   7(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #342");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #343");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   7(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #344");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #345");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #346");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #347");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1)
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #348");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   7(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #349");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #350");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #351");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #352");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #353");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   6(2,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #354");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #355");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #356");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #357");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #358");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   5(3,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #359");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #360");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #361");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #362");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #363");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   4(4,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #364");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #365");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #366");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #367");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #368");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   3(5,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #369");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #370");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #371");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #372");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #373");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   2(6,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #374");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #375");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #376");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #377");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #378");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   1(7,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #379");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #380");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #381");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #382");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #383");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   0(8,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #384");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #385");
      trace_rec_3();
    }

  if(strcmp(ar_field12, "G") == 0)
  {
      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #386");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #387");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #388");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, ar_field7);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #389");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "AA");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #390");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #391");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #392");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #393");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "BB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #394");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #395");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #396");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #397");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, ar_field6);
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #398");
        trace_rec_3();
      }
 
      strcpy(a_string, "         JLU   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "AA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #399");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "BB");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #400");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370L8");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #401");
        trace_rec_3();
      }
      work_use_ct[8]++;

      snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
      strcpy(a_string, "         PACK  0(6,R6),0(7,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c c2_atoi #402");
        trace_rec_3();
      }

    convert = 1;
    return;
  }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #403");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #404");
      trace_rec_3();
    }
    work_use_ct[8]++;

    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcpy(a_string, "         PACK  0(6,R9),0(7,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #405");
      trace_rec_3();
    }

    convert = 1;
    return;
  }


  if((x30 == 0) && (x31 == 0))
  {

    x9 = 8;
  
    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #4");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #5");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   1(7,R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #7");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #8");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #5");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   1(7,R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #10");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #11");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #12");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #13");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #14");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         LARL  R7,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #15");
      trace_rec_3();
    }
    work_use_ct[74]++;

    x9 = 0;
    strcpy(a_string, "         CLC   0(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #16");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #17");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #18");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #19");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   1(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #20");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #21");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   1(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #22");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #23");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   2(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #24");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #25");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   2(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #26");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #27");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   3(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #28");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #29");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   3(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #30");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #31");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   4(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #32");
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
      strcpy(trace_1, "c2z_ato1.c c2_atoi #33");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   4(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #34");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #35");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   5(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #36");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #37");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   5(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #38");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #39");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   6(1,R9),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #40");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #41");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   6(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #42");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #43");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   7(1,R9),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #44");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #45");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   7(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #46");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #47");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #48");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #49");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #50");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   7(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #51");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #52");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #53");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #54");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #55");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   6(2,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #56");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #57");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #58");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #59");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #60");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   5(3,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #61");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #62");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #63");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #64");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #65");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   4(4,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #66");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #67");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #68");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #69");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #70");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   3(5,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #71");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #72");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #73");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #74");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #75");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   2(6,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #76");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #77");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #78");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #79");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #80");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   1(7,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #81");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #82");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #83");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #84");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #85");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   0(8,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c c2_atoi #86");
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
    strcpy(trace_1, "c2z_atoi.c c2_atoi #87");
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
      strcpy(trace_1, "c2z_atoi.c c2_atoi #88");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #89");
      trace_rec_3();
    }
    work_use_ct[8]++;

    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcpy(a_string, "         PACK  0(6,R9),0(7,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c c2_atoi #90");
      trace_rec_3();
    }
  }
  convert = 1;
  return;

}
