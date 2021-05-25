/* ***************************************************
*  c2z : c2z_print.c :                               *
*                                                    *
*  next error = print = 21                           *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out FPRINTF conversion.                     *
* ************************************************** */
void c2_fprintf() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_fprintf");
    trace_rec_1();
  }

  char ch;
  char *p1, *p2;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field10[VAR_LGTH];

  int pi;
  int pi2;
  int x = 0;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int s = 0;
  int I = 0;
  int w_buf_ct = 0;
  int ret = 0;
  int ret1 = 0;

  s = strlen(p_string);
  x = 0;
  x2 = 0;
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '\"') 
    {
      x++;
      x2 = I;
    }
  }

  if (x != 2) 
  {
    printf("c2_fprintf Missing Starting Quote\n");
    printf("c2_fprintf rct = %d p_string = %s", rct, p_string);
    c2_debug();
    exit(1);
  }

  s = strlen(p_string);
  pi = 0;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  for (I = 0; I < f_ct; I++) 
  {
    ret = strcmp(field1, w_file[I].f_name);
    if (ret == 0) 
    {
      strcpy(field1a, w_file[I].f_cname);
      w_buf_ct = w_file[I].f_buf_ct;
    }
  }

  p1 = strstr(p_string, "%s");
  p2 = strstr(p_string, "%d");

  if ((!p1) && (!p2)) 					/* literal only */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf literal");
      trace_rec_1();
    }

    strcat(a_string, "         LARL  R9,C370PB");
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf literal #1");
      trace_rec_3();
    }

    strcpy(field2, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(field2, wk_strg);
    for (x3 = 0; x3 < v_const; x3++) 
    {
      ret = strcmp(field2, w_constant[x3].const_current);
      if (ret == 0) 
      {
        strcat(field10, w_constant[x3].const_use);
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field10);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf literal #2");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field10, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        x4 = lw_variable[I].lv_lgth;
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
          x4 = gw_variable[I].gv_lgth;
        }
      }
    }

    strcpy(a_string, "         MVC   C370PB");
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
    strcat(a_string, wk_strg);
    strcat(a_string, "(L'");

    strcpy(field2, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(field2, wk_strg);
    for (x3 = 0; x3 < v_const; x3++) 
    {
      ret = strcmp(field2, w_constant[x3].const_current);
      if (ret == 0) 
      {
        strcat(a_string, w_constant[x3].const_use);
        strcat(a_string, "),");
        strcat(a_string, w_constant[x3].const_use);
        strcpy(wk_remark, " fprintf  */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf literal #3");
          trace_rec_3();
        }
      }
    }

    strcpy(a_string, "         PUT    ");
    strcat(a_string, field1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf literal #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL   R9,C370PB");
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf literal #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL   R8,C370PB");
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf literal #6");
      trace_rec_3();
    }

    strcpy(field4, "C370PB");
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
    strcat(a_string, wk_strg);

    x3 = 0;
    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          x4 = gw_variable[I].gv_lgth;
        }
      }
    }

    strcpy(a_string, "         XC     ");
    strcat(a_string, "0(R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf literal #7");
      trace_rec_3();
    }

    strcpy(a_string, "*         MVC    ");
    strcat(a_string, "C370PB");
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
    strcat(a_string, wk_strg);
    strcat(a_string, "(132),=CL132' '");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf literal #8");
      trace_rec_3();
    }

    var_use[2]++;
    fprintf_lit = 1;
  }

  p1 = strstr(p_string, "%s");
  if (p1) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf string");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    pi2 = 0;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != ' ') 
      {
        field2[pi2] = ch;
        pi2++;
      }
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
        x5 = lw_variable[I].lv_lgth;
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
          x5 = gw_variable[I].gv_lgth;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_print.c c2_fprintf field2 print - 1 Not Found = %s\n", field2);
      printf("c2z_print.c c2_fprintf rct = %d p_string = %s\n", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x = 0;
    for (I = 0; I < f_ct; I++) 
    {
      ret = strcmp(field1, w_file[I].f_name);
      if (ret == 0) 
      {
        strcpy(a_string, "         LARL  R9,C370PB");
        snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #1");
          trace_rec_3();
        }

        strcpy(field3, "L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(field3, wk_strg);

        for (x3 = 0; x3 < v_const; x3++) 
        {
          ret = strcmp(field3, w_constant[x3].const_current);
          if (ret == 0) 
          {
            strcpy(field3a, w_constant[x3].const_use);
          }
        }

        x3 = 0;
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field3a, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            x4 = lw_variable[I].lv_lgth;
          }
        }

        if (x3 == 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field3a, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x4 = gw_variable[I].gv_lgth;
            }
          }
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field3a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #2");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   ");
        strcat(a_string, "0(");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
        strcat(a_string, wk_strg);
        strcat(a_string, ",R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #3");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370PB");
        snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #4");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field2a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #5");
          trace_rec_3();
        }

        x5 = 1;
        strcpy(a_string, "         MVC   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
        strcat(a_string, wk_strg);
        strcat(a_string, "(");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
        strcat(a_string, wk_strg);
        strcat(a_string, ",R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #6");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #7");
          trace_rec_3();
        }

        strcpy(a_string, "         PUT   (R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #8");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370PB");
        snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #9");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370B1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #10");
          trace_rec_3();
        }
        work_use_ct[52]++;

        strcpy(a_string, "         MVC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #11");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   1(131,R9),0(R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #12");
          trace_rec_3();
        }
      }
    }
  }

  p2 = strstr(p_string, "%d");
  if (p2) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf numeric");
      trace_rec_1();
    }

    s = strlen(p_string);
    pi = 0;
    ch = p_string[pi];
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
    }
    pi2 = 0;

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
      }
    }

    if (x3 == 0) {
      for (I = 0; I < gv_ct; I++) {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) {
          strcpy(field2, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    for (I = 0; I < f_ct; I++) 
    {
      ret = strcmp(field1, w_file[I].f_name);
      if (ret == 0) 
      {
        snprintf(wk_strg, sizeof(wk_strg), "%d", w_file[I].f_buf_ct);
      }
    }

    strcpy(a_string, "         MVC   C370PB");
    strcat(a_string, wk_strg);
    strcpy(field3, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(field3, wk_strg);

    for (x3 = 0; x3 < v_const; x3++) 
    {
      ret = strcmp(field3, w_constant[x3].const_current);
      if (ret == 0) 
      {
        strcat(a_string, "(L'");
        strcat(a_string, w_constant[x3].const_use);
        strcat(a_string, "),");
        strcat(a_string, w_constant[x3].const_use);
        strcat(a_string, "\n");
        fputs(a_string, cc370);
        var_use[1]++;
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_fprintf string #13");
          trace_rec_3();
        }
      }
    }

    x3 = 0;
    for (x3 = 0; x3 < lv_ct; x3++) 
    {
      ret = strcmp(field2, lw_variable[x3].lv_name);
      ret1 = strcmp(sv_func, lw_variable[x3].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[x3].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      for (x3 = 0; x3 < gv_ct; x3++) 
      {
        ret = strcmp(field2, gw_variable[x3].gv_cname);
        if (ret == 0) 
        {
          strcpy(field2a, gw_variable[x3].gv_cname);
        }
      }
    }

    strcpy(a_string, "         UNPK  C370AZNE,");
    strcat(a_string, c_wkname);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf string #14");
      trace_rec_3();
    }

    strcpy(a_string, "         MVZ   C370AZNE+L'C370AZNE-1(1),=X'F0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf string #15");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      if (rct == lw_variable[I].lv_rct) 
      {
        x2 = lw_variable[I].lv_lgth;
        break;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        if (rct == gw_variable[I].gv_rct) 
        {
          x2 = gw_variable[I].gv_lgth;
          break;
        }
      }
    }

    for (I = 0; I < f_ct; I++) 
    {
      ret = strcmp(w_file[I].f_cname, output_file);
      if (ret == 0) 
      {
        strcpy(a_string, "         MVC   C370PB");
        snprintf(wk_strg, sizeof(wk_strg), "%d", w_file[I].f_buf_ct);
        strcat(a_string, wk_strg);
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
    strcat(a_string, "+");
    strcat(a_string, wk_strg);
    strcat(a_string, "(L'C370AZNE),C370AZNE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf string #16");
      trace_rec_3();
    }

    strcpy(a_string, "         BRASL R9,PUTFILE");
    strcpy(wk_remark, " putfile  */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf string #17");
      trace_rec_3();
    }

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_fprintf string #18");
      trace_rec_3();
    }

    fprtf_flag = 1;
  }
}



/* ***************************************************
*  Punch out PRINTF conversion.                      *
* ************************************************** */
void c2_printf() 
{
  char ch;
  char *p1, *p2, *p3;

  int x = 0;
  int I = 0;
  int s = 0;
  int pi;
  int pi2;
  int x1;
  int x2;
  int x3;
  int x5;
  int x20 = 0;
  int x21 = 0;
  int x22 = 0;
  int x23 = 0;
  int x24 = 0;
  int x100 = 0;
  int x101 = 0;  
  int x102 = 0;  
  int ret = 0;
  int ret1 = 0;
  int printf_type = 0;
  int sv_type;
  int fd4_type;
  int fd5_type;
  int p102;

  char *p;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];
  char ar_field12[VAR_LGTH];

  char tfield8[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield10[VAR_LGTH];

  tfield8[0] = '\0';
  tfield9[0] = '\0';
  tfield10[0] = '\0';

  printf_convert = 0;

  s = strlen(p_string);
  x = 0;
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '\"') 
    {
      x++;
    }
    if(x >= 2)
    {
      if(ch == '[')
      {
        x100++;
      }
      if(ch == ']')
      {
        x100++;
      }
    }
  }

  if (fprtf_flag != 1) 
  {
    p1 = strstr(p_string, "%s");
    p2 = strstr(p_string, "%d");
    p3 = strstr(p_string, "%f");

    if(p1)
    {
      printf_type = 1;
    }
    if(p2)
    {
      printf_type = 2;
    }
    if(p3)
    {
      printf_type = 3;
    }

    if(x100 == 6) 	/* 2 dim print */
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
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }

      strcpy(field1, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(field1, wk_strg);
      x3 = 0;
      for (x3 = 0; x3 < v_const; x3++) 
      {
        ret = strcmp(field1, w_constant[x3].const_current);
        if (ret == 0) 
        {
          strcpy(field1, w_constant[x3].const_use);
          break;
        }
      }

      x5 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x5 = 1;
          x1 = lw_variable[I].lv_lgth;
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x5 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x5 = 1;
            x1 = gw_variable[I].gv_lgth;
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      strcpy(a_string, "         LARL  R9,C370WTOB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_600 #1");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, w_constant[x3].const_use);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_600 #2");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   ");
      strcat(a_string, "0(");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
      strcat(a_string, wk_strg);
      strcat(a_string, ",R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_600 #3");
        trace_rec_3();
      }
      p_ln_ct = p_ln_ct + x1;

      pi = 0;
      ch = p_string[pi];
      while(ch != '\"')
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while(ch != '\"')
      {
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field2[pi2] = '\0';

      p102 = 0;
 
      s = strlen(field2);
      for (I = 0; I < s; I++) 
      {
        if((field2[I] == '\\') && (field2[I+1] == 'n'))
        {
          p102++;
        }
      }  

      ch = p_string[pi];
      while(ch != ',')
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      x2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != '[') 
      {
        if(ch != ' ') 
        {
          if (x2 == 0) 
          {
            if (isdigit(ch)) 
            {
              x2 = 1;
            }
            if (isalpha(ch)) 
            {
              x2 = 1;
            }
          }
          field3[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
      }
      field3[pi2] = '\0';

      pi2 = 0;
      x2 = 0;
      fd4_type = 0;
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
              fd4_type = 1;
              x2 = 1;
            }
            if (isalpha(ch)) 
            {
              fd4_type = 2;
              x2 = 1;
            }
          }
          field4[pi2] = ch;
          pi2++;
       } 
       pi++;
       ch = p_string[pi];
     }
     field4[pi2] = '\0';

     pi2 = 0;
     x2 = 0;
     fd5_type = 0;
     pi++;
     pi++;
     ch = p_string[pi];
     while (ch != ']') 
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
       field5[pi2] = ch;
       pi2++;
       pi++;
       ch = p_string[pi];
     }
     field5[pi2] = '\0';
/*
printf("\nc2z_print.c printf_600 rct = %d p_string = %s",rct,p_string);
printf("c2z_print.c printf_600 field1 = %s\n",field1);
printf("c2z_print.c printf_600 field2 = %s p102 = %d\n",field2,p102);
printf("c2z_print.c printf_600 field3 = %s\n",field3); 
printf("c2z_print.c printf_600 field4 = %s fd4_type = %d\n",field4,fd4_type);
printf("c2z_print.c printf_600 field5 = %s fd5_type = %d\n",field5,fd5_type);
 */

     x21 = 0;
     x3 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field3, lw_variable[I].lv_name);
       x21 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (x21 == 0)) 
       {
         x3 = 1;
         strcpy(field3a, lw_variable[I].lv_cname);
       }
     }

     if (x3 == 0) 
     {
       x3 = 0;
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(field3, gw_variable[I].gv_name);
         if (ret == 0) 
         {
           x3 = 1;
           strcpy(field3a, gw_variable[I].gv_cname);
           strcpy(ar_field5, gw_variable[I].gv_dsect);
           strcpy(ar_field6, gw_variable[I].gv_label);
           strcpy(ar_field7, gw_variable[I].gv_table);
           strcpy(ar_field8, gw_variable[I].gv_aname);
           strcpy(ar_field9, gw_variable[I].gv_sv_reg);
           strcpy(ar_field10, gw_variable[I].gv_wk_reg);
           strcpy(ar_field11, gw_variable[I].gv_wk_strg);
           strcpy(ar_field12, gw_variable[I].gv_st_col);
           x101 = gw_variable[I].gv_lgth;
           x101 = x101 - 1;
           x102 = gw_variable[I].gv_column;
 
/*
printf("c2z_print.c printf_600 rct = %d gv_row = %d\n",rct,gw_variable[I].gv_row);
printf("c2z_print.c printf_600 rct = %d gv_column = %d\n",rct,gw_variable[I].gv_column);
printf("c2z_print.c printf_600 rct = %d x102 = %d\n",rct,x102);
*/

           p = strstr(gw_variable[I].gv_type, "A");
           if(p)
           {
             sv_type = 2;
           }

           p = strstr(gw_variable[I].gv_type, "G");
           if(p)
           {
             sv_type = 1;
           }

           break;
         }
       }
     }

     if (x3 == 0) 
     {
       printf("\nc2z_printf.c c2_printf_marray E-603 field3 Not Found = %s\n",field3);
       printf("c2z_printf.c c2_printf_marrayrct = %d p_string = %s\n",rct,p_string);
       erct++;
       convert = 1;
       return;
     }

     if(fd4_type == 2)
     {
       x21 = 0;
       x3 = 0;
       for (I = 0; I < lv_ct; I++) 
       {
         ret = strcmp(field4, lw_variable[I].lv_name);
         x21 = strcmp(sv_func, lw_variable[I].lv_func);
         if ((ret == 0) && (x21 == 0)) 
         {
           x3 = 1;
           strcpy(field4a, lw_variable[I].lv_cname);
           x100 = lw_variable[I].lv_lgth;
         }
       }

       if (x3 == 0) 
       {
         x3 = 0;
         for (I = 0; I < gv_ct; I++) 
         {
           ret = strcmp(field4, gw_variable[I].gv_name);
           if (ret == 0) 
           {
             x3 = 1;
             strcpy(field4a, gw_variable[I].gv_cname);
             break;
           }
         }
       }

       if (x3 == 0) 
       {
         printf("\nc2z_printf.c c2_printf_600 E-604 field4 Not Found = %s\n",field4);
         printf("c2z_printf.c c2_printf_600 rct = %d p_string = %s\n",rct,p_string);
         erct++;
         convert = 1;
         return;
       }
     }

     if(fd5_type == 2)
     {
       x21 = 0;
       x3 = 0;
       for (I = 0; I < lv_ct; I++) 
       {
         ret = strcmp(field5, lw_variable[I].lv_name);
         x21 = strcmp(sv_func, lw_variable[I].lv_func);
         if ((ret == 0) && (x21 == 0)) 
         {
           x3 = 1;
           strcpy(field5a, lw_variable[I].lv_cname);
         }
       }

       if (x3 == 0) 
       {
         x3 = 0;
         for (I = 0; I < gv_ct; I++) 
         {
           ret = strcmp(field5, gw_variable[I].gv_name);
           if (ret == 0) 
           {
             x3 = 1;
             strcpy(field5a, gw_variable[I].gv_cname);
           }
         }
       }

       if (x3 == 0) 
       {
         printf("\nc2z_printf.c c2_printf_600 E-605 field5 Not Found = %s\n",field5);
         printf("c2z_printf.c c2_printf_600 rct = %d p_string = %s\n",rct,p_string);
         erct++;
         convert = 1;
         return;
       }
  }

  if(fd4_type == 1)
  {
    strcpy(field4a, field4);
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #4");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #5");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #6");
    trace_rec_3();
  }

  if(fd4_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #7a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #7b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #7c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #7d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #7e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #7f");
      trace_rec_3();
    }
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " ROW */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c printf_600 #7g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #8");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #9");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #10");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #11");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #12");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #13");
    trace_rec_3();
  }


  if(fd5_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field5);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #14a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #14b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #14c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #14d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #14e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #14f");
      trace_rec_3();
    }
  }

  if(fd5_type == 2)
  {
    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " COL */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c printf_600 #14g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R5,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #15");
    trace_rec_3();
  }
 
  strcpy(a_string, "         AP    0(6,R7),0(6,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #16");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #17");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #18");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #19");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #20");
    trace_rec_3();
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " ROW */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c printf_600 #21");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #22");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #23");
    trace_rec_3();
  }

/* printf("c2z_print.c printf_600 #2 rct = %d x102 = %d\n",rct,x102); */

  snprintf(wk_strg, sizeof(wk_strg), "%d", x102);
  strcpy(a_string, "         LAEY  R5,");
  strcat(a_string, wk_strg);
  strcpy(wk_remark, " ");
  strcat(wk_remark, wk_strg);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_print.c printf_600 #24");
    trace_rec_3();
  }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #25");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #26");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #27");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #28");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #29");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #30");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " ROW */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c printf_600 #21");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #29");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #30");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #31");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #32");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #33");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " COL */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c printf_600 #34");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #35");
      trace_rec_3();
    }


  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #36");
    trace_rec_3();
  }

/*  C370NWK1 contains pointer to array element */

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #37");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #38");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #39");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, ar_field7);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #40");
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
    strcpy(trace_1, "c2z_print.c printf_600 #41");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #42");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #43");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #44");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #45");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #46");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #47");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #48");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #49");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_600 #50");
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
    strcpy(trace_1, "c2z_print.c printf_600 #51");
    trace_rec_3();
  }


/* src[i][j][0]   (string) */


  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_print.c printf_600 #100");
    trace_rec_3();
  }
    
  strcpy(a_string, "         MVC   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x100);
  strcat(a_string, wk_strg);
  strcat(a_string, "(");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
  strcat(a_string, wk_strg); 
  strcat(a_string, ",R9),0(R6)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_print.c printf_600 #101");
    trace_rec_3();
  }

  strcpy(a_string, "*         LR    R0,R3");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_print.c printf_600 #102");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #103"); 
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c printf_600 #104");
      trace_rec_3();
    }
    p_ln_ct = 0;
  }

  convert = 1;
  return;
  }

/* ********************************************************
 * printf(flag[x][y]);                                    *
 * ****************************************************** */
  if(x100 == 4) 		/*  numeric 2 dim array */
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
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }

    strcpy(field1, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(field1, wk_strg);
    x3 = 0;
    for (x3 = 0; x3 < v_const; x3++) 
    {
      ret = strcmp(field1, w_constant[x3].const_current);
      if (ret == 0) 
      {
        strcpy(field1, w_constant[x3].const_use);
        break;
      }
    }

    x5 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x5 = 1;
        x1 = lw_variable[I].lv_lgth;
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x5 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x5 = 1;
          x1 = gw_variable[I].gv_lgth;
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, w_constant[x3].const_use);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, "0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #3");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcpy(a_string, "         LARL  R5,");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #4");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcpy(a_string, "         LAEY  R3,");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #5");
      trace_rec_3();
    }

    pi = 0;
    ch = p_string[pi];
    while(ch != ',')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if(ch != ' ') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
            x2 = 1;
          }
        }
        field3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    field3[pi2] = '\0';

    pi2 = 0;
    x2 = 0;
    fd4_type = 0;
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
            fd4_type = 1;
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
            fd4_type = 2;
            x2 = 1;
          }
        }
        field4[pi2] = ch;
        pi2++;
     } 
     pi++;
     ch = p_string[pi];
   }
   field4[pi2] = '\0';

   pi2 = 0;
   x2 = 0;
   fd5_type = 0;
   pi++;
   pi++;
   ch = p_string[pi];
   while (ch != ']') 
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
     field5[pi2] = ch;
     pi2++;
     pi++;
     ch = p_string[pi];
   }
   field5[pi2] = '\0';

   x21 = 0;
   x3 = 0;
   for (I = 0; I < lv_ct; I++) 
   {
     ret = strcmp(field3, lw_variable[I].lv_name);
     x21 = strcmp(sv_func, lw_variable[I].lv_func);
     if ((ret == 0) && (x21 == 0)) 
     {
       x3 = 1;
       strcpy(field3a, lw_variable[I].lv_cname);
     }
   }

   if (x3 == 0) 
   {
     x3 = 0;
     for (I = 0; I < gv_ct; I++) 
     {
       ret = strcmp(field3, gw_variable[I].gv_name);
       if (ret == 0) 
       {
         x3 = 1;
         strcpy(field3a, gw_variable[I].gv_cname);
         strcpy(ar_field5, gw_variable[I].gv_dsect);
         strcpy(ar_field6, gw_variable[I].gv_label);
         strcpy(ar_field7, gw_variable[I].gv_table);
         strcpy(ar_field8, gw_variable[I].gv_aname);
         strcpy(ar_field9, gw_variable[I].gv_sv_reg);
         strcpy(ar_field10, gw_variable[I].gv_wk_reg);
         strcpy(ar_field11, gw_variable[I].gv_wk_strg);
         strcpy(ar_field12, gw_variable[I].gv_st_col);
         x101 = gw_variable[I].gv_lgth;
         x101 = x101 - 1;

         p = strstr(gw_variable[I].gv_type, "A");
         if(p)
         {
           sv_type = 2;
         }

         p = strstr(gw_variable[I].gv_type, "G");
         if(p)
         {
           sv_type = 1;
         }

         break;
       }
     }
   }

   if (x3 == 0) 
   {
     printf("\nc2z_printf.c c2_printf_601 E-603 field3 Not Found = %s\n",field3);
     printf("c2z_printf.c c2_printf_601 rct = %d p_string = %s\n",rct,p_string);
     erct++;
     convert = 1;
     return;
   }

   if(fd4_type == 2)
   {
     x21 = 0;
     x3 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field4, lw_variable[I].lv_name);
       x21 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (x21 == 0)) 
       {
         x3 = 1;
         strcpy(field4a, lw_variable[I].lv_cname);
         x100 = lw_variable[I].lv_lgth;
       }
     }

     if (x3 == 0) 
     {
       x3 = 0;
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(field4, gw_variable[I].gv_name);
         if (ret == 0) 
         {
           x3 = 1;
           strcpy(field4a, gw_variable[I].gv_cname);
           break;
         }
       }
     }

     if (x3 == 0) 
     {
       printf("\nc2z_printf.c c2_printf_601 E-604 field4 Not Found = %s\n",field4);
       printf("c2z_printf.c c2_printf_601 rct = %d p_string = %s\n",rct,p_string);
       erct++;
       convert = 1;
       return;
     }
   }

   if(fd5_type == 2)
   {
     x21 = 0;
     x3 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field5, lw_variable[I].lv_name);
       x21 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (x21 == 0)) 
       {
         x3 = 1;
         strcpy(field5a, lw_variable[I].lv_cname);
       }
     }

     if (x3 == 0) 
     {
       x3 = 0;
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(field5, gw_variable[I].gv_name);
         if (ret == 0) 
         {
           x3 = 1;
           strcpy(field5a, gw_variable[I].gv_cname);
         }
       }
     }

     if (x3 == 0) 
     {
       printf("\nc2z_printf.c c2_printf_601 E-605 field5 Not Found = %s\n",field5);
       printf("c2z_printf.c c2_printf_601 rct = %d p_string = %s\n",rct,p_string);
       erct++;
       convert = 1;
       return;
     }
  }

  if(fd4_type == 1)
  {
    strcpy(field4a, field4);
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #6");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #7");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #B");
    trace_rec_3();
  }

  if(fd4_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9f");
      trace_rec_3();
    }
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #10");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #11");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #12");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #14");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #15");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #16");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #17");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #18");
    trace_rec_3();
  }

  if(fd5_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field5);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19f");
      trace_rec_3();
    }
  }

  if(fd5_type == 2)
  {
    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R5,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #20");
    trace_rec_3();
  }
 
  strcpy(a_string, "         AP    0(6,R7),0(6,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #21");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #22");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #23");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #24");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #25");
    trace_rec_3();
  }
 
  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "U");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #26");
    trace_rec_3();
  }

  if(fd5_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field5);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27f");
      trace_rec_3();
    }
  }

  if(fd5_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #28");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #29");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #30");
    trace_rec_3();
  }

  if(fd4_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31f");
      trace_rec_3();
    }
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #32");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #33");
    trace_rec_3();
  }
 
  strcpy(a_string, "* L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "T");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #34");
    trace_rec_3();
  }

  strcpy(a_string, "*         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #35");
    trace_rec_3();
  }

  strcpy(a_string, "*         LARL  R8,");
  strcat(a_string, field4a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field4);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #36");
    trace_rec_3();
  }

  strcpy(a_string, "*         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #37");
    trace_rec_3();
  }

  strcpy(a_string, "*         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #38");
    trace_rec_3();
  }

  strcpy(a_string, "*         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #39");
    trace_rec_3();
  }

  strcpy(a_string, "*         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #40");
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
    strcpy(trace_1, "c2z_print.c c2_printf_601 #41");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #42");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, ar_field12);
  strcpy(wk_remark, " ");
  strcat(wk_remark, ar_field12);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #43");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #44");
    trace_rec_3();
  }

  if(fd4_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45f");
      trace_rec_3();
    }
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #46");
    trace_rec_3();
  }

  if(fd4_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47f");
      trace_rec_3();
    }
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #48");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #49");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #50");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #51");
    trace_rec_3();
  }

/*  C370NWK1 contains pointer to array element */

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #52");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #53");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #54");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, ar_field7);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #55");
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
    strcpy(trace_1, "c2z_print.c c2_printf_601 #56");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #57");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #58");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #59");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #60");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #61");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #62");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #63");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #64");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #65");
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
    strcpy(trace_1, "c2z_print.c c2_printf_601 #66");
    trace_rec_3();
  }

  if(fd5_type == 1)
  {
    if(sv_type == 1)
    {
      strcpy(a_string, "*         LARL  R5,");
      strcat(a_string, field5);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_print.c c2_printf_601 #67");
        trace_rec_3();
      }

      strcpy(a_string, "*         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_print.c c2_printf_601 #68");
        trace_rec_3();
      }

      strcpy(a_string, "*         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_print.c c2_printf_601 #69");
        trace_rec_3();
      }

      strcpy(a_string, "*         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_print.c c2_printf_601 #70");
        trace_rec_3();
      }

      strcpy(a_string, "*         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_print.c c2_printf_601 #71");
        trace_rec_3();
      }

      strcpy(a_string, "*         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_print.c c2_printf_601 #72");
        trace_rec_3();
      }

      strcpy(a_string, "*         ZAP   0(6,R6),0(6,R8)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_print.c c2_printf_601 #73");
        trace_rec_3();
      }
    }
  }

/* src[i][j][0]   (string) */
  if((fd4_type == 2) && (fd5_type == 2) && (printf_type == 1))		
  {
    strcpy(a_string, "         LARL  R9,C370L80");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #74");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(80,R9),0(R6)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #75");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #76");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #77");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #78");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R2,1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #79");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "L");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #80");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #81");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #82");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #83");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #84");
      trace_rec_3();
    }

    strcpy(a_string, "         CVB   R5,0(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #85");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L80");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #86");
      trace_rec_3();
    }
    work_use_ct[10]++;

    strcpy(a_string, "         IC    R0,0(R8,(R5))");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #87");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #88");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         STC   R0,0(0,R9)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #89");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #90");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #91");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #92");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "M");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #93");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #94");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #95");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #96");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R3,R2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #97");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "L");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #98");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "M");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #99");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #100");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x100);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
    strcat(a_string, wk_strg); 
    strcat(a_string, ",R9),0(R6)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #101");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R0,R3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #102");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #103");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #104");
      trace_rec_3();
    }
    p_ln_ct = 0;
  }


/* src[i][j][0]   (numeric) */
  if((fd4_type == 2) && (fd5_type == 2) && (printf_type == 2))		
  {
    strcpy(a_string, "         LARL  R9,C370EDN");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #105");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #106");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOIMVC");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #107");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #108");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #109");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L10");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #110");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcat(a_string, wk_strg);
    strcat(a_string, "(10,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #111");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R2,10");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #112");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R3,R2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #113");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R0,R3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #114");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #115");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #116");
      trace_rec_3();
    }
    p_ln_ct = 0;
  } 

  if((fd4_type == 1) && (fd5_type == 1))
  {
    strcpy(a_string, "         LARL  R9,C370EDN");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #120");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #121");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOIMVC");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #122");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #123");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #109");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L10");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #110");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcat(a_string, wk_strg);
    strcat(a_string, "(10,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #111");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R2,10");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #112");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R3,R2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #113");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R0,R3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #114");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #115");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #116");
      trace_rec_3();
    }
    p_ln_ct = 0;
  }
  convert = 1;
  return;

  }

/* ************************************************ */

    if (p1) 					/*  printf %s  */
    {
      printf_type = 1;
      c2_printf_string();
      convert = 1;
      return;
    }

    if (p2) 					/*  printf %d  */
    {
      printf_type = 2;
      c2_printf_numeric();
      convert = 1;
      return;
    }

    if (p3) 					/* printf %f  */
    {
      printf_type = 3;
      c2_printf_float();
      convert = 1;
      return;
    }

    x20 = 0;
    x21 = 0;
    x22 = 0;
    x23 = 0;
    x24 = 0;
    p3 = strstr(p_string, "%");
    if (p3)
    {
      x20 = 1;
    }

    if (x20 == 1) 
    {
      s = strlen(p_string);
      for (I = 0; I < s; I++) 
      {
        ch = p_string[I];
        if (ch == '%') 
        {
          x21 = 1;
          x22 = I;
          break;
        }
      }
    }

    if (x21 == 1) 
    {
      x22++;
      tfield8[0] = p_string[x22];
      tfield8[1] = '\0';
      ret = strcmp(".", tfield8);
      if (ret == 0) 
      {
        strcpy(tfield9, tfield8);
        tfield8[0] = '\0';
        x22++;
        tfield10[0] = p_string[x22];
        tfield10[1] = '\0';
        x23 = 1;
      } 
      else 
      {
        x22++;
        tfield9[0] = p_string[x22];
        tfield9[1] = '\0';
        x22++;
        tfield10[0] = p_string[x22];
        tfield10[1] = '\0';
        x23 = 1;
      }
    }

    if (x23 == 1) 					/* format printf %.2d	*/
    {
      s = atoi(tfield10);
      c2_printf_dec_only(s);
      return;
    }

    if (x24 == 1) 					/* format printf %4.2d	*/
    {
      printf("\nc2z_printf.c c2_printf print-002 x24 NOT CODED\n");
      printf("c2z_printf.c c2_printf rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (printf_type == 0) 
    {
      c2_printf_literal();
      return;
    }
  }
}



























void c2_printf_literal() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_literal");
    trace_rec_1();
  }

  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int v = 0;
  int I;
  int s;
  int ret = 0;
  int ret1 = 0;

  char field1[VAR_LGTH];

  p102 = 0;
 
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    if((p_string[I] == '\\') && (p_string[I+1] == 'n'))
    {
      p102++;
    }
  }  

  strcpy(field1, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(field1, wk_strg);

  for (x3 = 0; x3 < v_const; x3++) 
  {
    ret = strcmp(field1, w_constant[x3].const_current);
    if (ret == 0) 
    {
      strcpy(wk_strg, w_constant[x3].const_use);

      x5 = 0;
      x4 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(wk_strg, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x4 = 1;
            lw_variable[v].lv_use_ct++;
            x5 = lw_variable[v].lv_lgth;
          }
        }
      }

      strcpy(wk_strg, w_constant[x3].const_use);
      if (x4 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(wk_strg, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              x4 = 1;
              gw_variable[v].gv_use_ct++;
              x5 = gw_variable[v].gv_lgth;
            }
          }
        }
      }
    }
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_literal #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_literal #8");
    trace_rec_3();
  }

  snprintf(ptr_lgth, sizeof(ptr_lgth), "%d", p_ln_ct);
  strcpy(a_string, "         MVC   ");
  strcat(a_string, ptr_lgth);
  strcat(a_string, "(");
  snprintf(ptr_lgth, sizeof(ptr_lgth), "%d", x5);
  strcat(a_string,ptr_lgth);
  strcat(a_string, ",R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_literal #8");
    trace_rec_3();
  }

  if(p102 == 0)
  {
    p_ln_ct = p_ln_ct + x5;
   
  }

  if(p102 == 1)
  {
    strcpy(a_string, "*         LAEY  R0,");
    strcat(a_string, ptr_lgth);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c printf_literal #7");
      trace_rec_3();
    }
    
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c printf_literal #8");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c printf_literal #9");
      trace_rec_3();
    }
    p_ln_ct = 0;
  }
  
  printf_convert = 1;
}









void c2_snprintf(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_snprintf");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];

  int pi;
  int pi2;
  int v;
  int ret;
  int ret1;
  int x3;

  pi = 0;
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
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
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
      tfield3[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  x3 = 0;
  for (v = 0; v < lv_ct; v++) 
  {
    ret = strcmp(tfield1, lw_variable[v].lv_name);
    ret1 = strcmp(sv_func, lw_variable[v].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(tfield1a, lw_variable[v].lv_cname);
      lw_variable[v].lv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield1, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield1a, gw_variable[v].gv_cname);
        gw_variable[v].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_print.c c2_snprintf printf-015 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_print.c c2_snprintf rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (v = 0; v < lv_ct; v++) 
  {
    ret = strcmp(tfield3, lw_variable[v].lv_name);
    ret1 = strcmp(sv_func, lw_variable[v].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(tfield3a, lw_variable[v].lv_cname);
      lw_variable[v].lv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield3, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield3a, gw_variable[v].gv_cname);
        gw_variable[v].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_print.c c2_snprintf printf-016 tfield3 Not Found = %s\n", tfield3);
    printf("c2z_print.c c2_snprintf rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c snprintf #1");
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
    strcpy(trace_1, "c2z_print.c snprintf #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c snprintf #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R15,WTOIMVC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c snprintf #4");
    trace_rec_3();
  }

  strcpy(a_string, "         BAKR  0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c snprintf #4");
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
    strcpy(trace_1, "c2z_print.c snprintf #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c snprintf #6");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC  0(8,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c snprintf #7");
    trace_rec_3();
  }
}



void c2_sprintf(void)
{
printf("c2z_print.c c2_sprintf NEED TO CODE rct = %d p_string = %s\n",rct,p_string);

  convert = 1;
  return;
}


void c2_printf_string() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_string");
    trace_rec_1();
  }

  char ch;
  char *p6, *p7, *p8;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field1b[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field11[VAR_LGTH];
  char field11a[VAR_LGTH];
  char field12[VAR_LGTH];

  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield22[VAR_LGTH];
  char tfield22a[VAR_LGTH];

  int pi;
  int pi2;
  int x1 = 0;
  int x2 = 0;
  int x3 = 0;
  int x5 = 0;
  int x9 = 0;
  int x11 = 0;
  int x95 = 0;
  int v = 0;
  int prf1 = 0;
  int prf3 = 0;
  int pf1 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int xc = 0;
  int s;
  int fd22_type = 0;

  p102 = 0;
 
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    if((p_string[I] == '\\') && (p_string[I+1] == 'n'))
    {
      p102++;
    }
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
      field2[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  strcpy(field1, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(field1, wk_strg);
  x3 = 0;
  for (x3 = 0; x3 < v_const; x3++) 
  {
    ret = strcmp(field1, w_constant[x3].const_current);
    if (ret == 0) 
    {
      strcpy(field1, w_constant[x3].const_use);
      break;
    }
  }

  x5 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x5 = 1;
      x1 = lw_variable[I].lv_lgth;
      lw_variable[I].lv_use_ct++;
    }
  }

  if (x5 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x5 = 1;
        x1 = gw_variable[I].gv_lgth;
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_str #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, w_constant[x3].const_use);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_str #2");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
  strcat(a_string, wk_strg);
  strcat(a_string, "(");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
  strcat(a_string, wk_strg);
  strcat(a_string, ",R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c printf_str #3");
    trace_rec_3();
  }
  p_ln_ct = p_ln_ct + x1;

  p6 = strstr(p_string, "[");
  p7 = strstr(p_string, "]");
  p8 = strstr(p_string, ".");

  if ((!p6) && (!p7) && (!p8)) 
  {
    x11 = 0;
    x9 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        pf1 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        x9 = lw_variable[I].lv_current_lgth;
        break;
      }
    }

    if (pf1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        prf3 = strcmp(field2, gw_variable[I].gv_name);
        if (prf3 == 0) 
        {
          pf1 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x9 = gw_variable[I].gv_current_lgth;
        }
      }
    }

    if (pf1 == 0) 
    {
      printf("\nc2z_print.c c2_printf NO [] printf-009 Missing field after format statement\n");
      printf("c2z_print.c c2_printf rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c printf_str #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c printf_str #5");
      trace_rec_3();
    }

    x11 = (75 - x1);

    if(x9 > x11)
    {
       x9 = x11;
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c printf_str #6");
      trace_rec_3();
    }

    if(p102 == 1)
    {
      strcpy(a_string, "         LARL  R15,WTOALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #7");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #8");
        trace_rec_3();
      }
      p_ln_ct = 0;

    }

    if(p102 == 0)
    {
      p_ln_ct = p_ln_ct + x9;
    }
  }


/*  print out array[x] code  */
  if ((p6) && (p7) && (!p8)) 
  {
    pi = 0;
    while (ch != '"') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch == ',') 
      {
        x2 = 1;
      }
      if (x2 == 0) 
      {
        if (ch != ' ') 
        {
          field1[pi2] = ch;
          pi2++;
        }
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    p6 = strstr(field1, "[");
    p7 = strstr(field1, "]");

    print_array = 0;

    if ((p6) && (p7)) 
    {
      pi2 = 0;
      ch = field1[prf1];
      while (ch != '[') 
      {
        field1a[pi2] = ch;
        pi2++;
        prf1++;
        ch = field1[prf1];
      }
      field1a[pi2] = '\0';
      x3 = 0;
      pi2 = 0;
      prf1++;
      ch = field1[prf1];
      while (ch != ']') 
      {
        if ((isdigit(ch)) && (x3 == 0)) 
        {
          fd22_type = 2;
          x3 = 1;
        }
        if ((isalpha(ch)) && (x3 == 0)) 
        {
          fd22_type = 1;
          x3 = 1;
        }
        tfield22[pi2] = ch;
        pi2++;
        prf1++;
        ch = field1[prf1];
      }
      tfield22[pi2] = '\0';

      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field1a, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            strcpy(field1b, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            strcpy(field4, gw_variable[I].gv_type);
          }
        }
      }

      ret = strcmp(field4, "A");
      if (ret == 0) 
      {
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field1b, gw_variable[I].gv_cname);
            if (ret == 0) 
            {
              strcpy(field5, gw_variable[I].gv_dsect);
              strcpy(field6, gw_variable[I].gv_label);
              strcpy(field7, gw_variable[I].gv_table);
              strcpy(field8, gw_variable[I].gv_aname);
              strcpy(field9, gw_variable[I].gv_sv_reg);
              strcpy(field10, gw_variable[I].gv_wk_reg);
              strcpy(field11, gw_variable[I].gv_wk_strg);
              xc = gw_variable[I].gv_column;
              gw_variable[I].gv_flag = 1;
            }
          }
        }
      
        prf3 = 0;
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field11, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            prf3 = 1;
            strcpy(field11a, lw_variable[v].lv_cname);
            x9 = lw_variable[v].lv_lgth;
            lw_variable[v].lv_use_ct++;
          }
        }

        prf3 = 0;
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field11, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            prf3 = 1;
            strcpy(field11a, gw_variable[v].gv_cname);
            x9 = gw_variable[v].gv_lgth;
            gw_variable[v].gv_use_ct++;
          }
        }

        strcpy(a_string, "         LARL  R6,");
        strcat(a_string, field7);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #7");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #8");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #9");
          trace_rec_3();
        }
        work_use_ct[32]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        var_use[1]++;
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #10");
          trace_rec_3();
        }

        strcpy(a_string, "PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "A");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #11");
          trace_rec_3();
        }

        if (fd22_type == 2) 
        {
          strcpy(a_string, "         LAEY  R5,");
          strcat(a_string, tfield22);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12a");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL R9,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12b");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         CVD  R5,0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12c");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL R9,C370NWK2");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12d");
            trace_rec_3();
          }
          work_use_ct[50]++;

          strcpy(a_string, "         LARL R8,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12e");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         ZAP  0(6,R9),0(8,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12f");
            trace_rec_3();
          }
        }

        if (fd22_type == 1) 
        {
          prf3 = 0;
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(tfield22, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              prf3 = 1;
              strcpy(tfield22a, lw_variable[v].lv_cname);
              x9 = lw_variable[v].lv_lgth;
              lw_variable[v].lv_use_ct++;
            }
          }

          prf3 = 0;
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(tfield22, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              prf3 = 1;
              strcpy(tfield22a, gw_variable[v].gv_cname);
              x9 = gw_variable[v].gv_lgth;
              gw_variable[v].gv_use_ct++;
            }
          }

          strcpy(a_string, "         LARL  R9,");
          strcat(a_string, tfield22a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield22);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12g");
            trace_rec_3();
          }
        }

        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #13");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #14");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        var_use[1]++;
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #15");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #16");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #17");
          trace_rec_3();
        }
        work_use_ct[33]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #18");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, field6);
        strcat(a_string, "(R0,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #19");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "A");
        src_line();
        var_use[1]++;
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #20");
          trace_rec_3();
        }

        strcpy(a_string, "PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #21");
          trace_rec_3();
        }

        strcpy(print_array_name, field10);
        strcpy(print_array_table, field7);

        strcpy(a_string, "         LARL  R9,C370L80");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #22");
          trace_rec_3();
        }
        work_use_ct[10]++;
 
        strcpy(a_string, "         MVC   0(80,R9),0(R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #23");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #24");
          trace_rec_3();
        }
        work_use_ct[50]++;
 
        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #25");
          trace_rec_3();
        }
        work_use_ct[32]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #26");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R2,1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #27");
          trace_rec_3();
        }

        strcpy(a_string, "PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "L");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #28");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #29");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #30");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #31");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #32");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVB   R5,0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #33");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370L80");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #34");
          trace_rec_3();
        }
        work_use_ct[10]++;
 
        strcpy(a_string, "         IC    R0,0(R8,(R5))");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #35");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #36");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         STC   R0,0(0,R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #37");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #38");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         LARL  R8,C370EOF");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #39");
          trace_rec_3();
        }
        work_use_ct[74]++;

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #40");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "M");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #41");
          trace_rec_3();
        }

         strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #42");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #43");
          trace_rec_3();
        }
        work_use_ct[33]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #44");
          trace_rec_3();
        }

        strcpy(a_string, "         AR    R3,R2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #45");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "L");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #46");
          trace_rec_3();
        }

        strcpy(a_string, "PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "M");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #47");
          trace_rec_3();
        }

        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field12, gw_variable[I].gv_name);
          }
        }

        strcpy(a_string, "         LARL  R9,C370WTOB");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #48");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
        strcat(a_string, wk_strg);
        strcat(a_string, "(");
        snprintf(wk_strg, sizeof(wk_strg), "%d", xc);
        strcat(a_string, wk_strg);
        strcat(a_string, ",R9),0(R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #49");
          trace_rec_3();
        }

        strcpy(a_string, "         LR    R0,R3");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #50");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R15,WTOALPHA");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #51");
          trace_rec_3();
        }
    
        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #52");
          trace_rec_3();
        }
        p_ln_ct = 0;
        print_array = 1;
        tot_wto++;
      }
    }


    /* *****************************************************
     * this routine prints out individual characters in a  *
     * character string, NOT A DEFINED ARRAY               *
     * *************************************************** */
    ret = strcmp(field4, "C");
    if (ret == 0) 
    {
printf("c2z_print.c c2_print CHARACTER rct = %d p_string = %s", rct, p_string);

      strcpy(field10,field1);

      pi = 0;
      pi2 = 0;
      ch = field10[pi];
      while(ch != '[')
      {
        field1[pi2] = ch;
        pi2++;
        pi++;
        ch = field10[pi];
      }
      field1[pi2] = '\0';
printf("c2z_print.c rct = %d field1 = %s\n",rct,field1);

      pi++;
      pi2 = 0;
      ch = field10[pi];
      while(ch != ']')
      {
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = field10[pi];
      }
      field2[pi2] = '\0';
printf("c2z_print.c rct = %d field2 = %s\n",rct,field2);

      x11 = 0;
      x9 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          pf1 = 1;
          strcpy(field1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x9 = lw_variable[I].lv_current_lgth;
          break;
        }
      }

      if (pf1 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        { 
          prf3 = strcmp(field1, gw_variable[I].gv_name);
          if (prf3 == 0) 
          {
            pf1 = 1;
            strcpy(field1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            x9 = gw_variable[I].gv_current_lgth;
          }
        }
      }

      if (pf1 == 0) 
      {
        printf("\nc2z_print.c c2_printf field1 = %s Not Found\n",field1);
        printf("c2z_print.c c2_printf rct = %d p_string = %s\n",rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      x11 = 0;
      x9 = 0;
      pf1 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          pf1 = 1;
          strcpy(field2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x9 = lw_variable[I].lv_current_lgth;
          break;
        }
      }

      if (pf1 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        { 
          prf3 = strcmp(field2, gw_variable[I].gv_name);
          if (prf3 == 0) 
          {
            pf1 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            x9 = gw_variable[I].gv_current_lgth;
          }
        }
      }

      if (pf1 == 0) 
      {
        printf("\nc2z_print.c c2_printf field2 = %s Not Found\n",field2);
        printf("c2z_print.c c2_printf rct = %d p_string = %s\n",rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #400");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #401");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #402");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #403");
        trace_rec_3();
      }

      strcpy(a_string, "         CVB   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #404");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #405");
        trace_rec_3();
      }

      strcpy(a_string, "         IC    R0,0(R8,(R5))");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #406");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #407");
        trace_rec_3();
      }

      strcpy(a_string, "         STC   R0,0(0,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #408");
        trace_rec_3();
      }

      x11 = (75 - x1);

      if(x9 > x11)
      {
         x9 = x11;
      }

      strcpy(a_string, "         LARL  R9,C370WTOB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #409");
        trace_rec_3();
      }

      p_ln_ct++;

      strcpy(a_string, "         MVC   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
      strcat(a_string, wk_strg);
      strcat(a_string, "(");
      strcat(a_string, "1,R9),0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #409"); 
        trace_rec_3();
      }

    if(p102 == 1)
    {
      strcpy(a_string, "         LARL  R15,WTOALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #410");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf_str #411");
        trace_rec_3();
      }
      p_ln_ct = 0;
    }

    if(p102 == 0)
    {
      p_ln_ct = p_ln_ct + x9;
    }



/*
3  321    c2z_math.c math_2 START             ch = p_string[pi];
3  321    c2z_math.c math_2 #86           L321A    DS    0H                                                       0001188
3  321    c2z_math.c math_2 #87                    LARL  R9,C370U                                                 0001189
3  321    c2z_math.c math_2 #88                    LARL  R8,C37F261                      pi                       0001190
3  321    c2z_math.c math_2 #89                    ZAP   0(8,R9),2(4,R8)                                          0001191
3  321    c2z_math.c math_2 #90                    LARL  R8,C370U                                                 0001192
3  321    c2z_math.c math_2 #91                    CVB   R5,0(R8)                                                 0001193
3  321    c2z_math.c math_2 #92                    LARL  R8,C37F11                       p_string                 0001194
3  321    c2z_math.c math_2 #93                    IC    R0,0(R8,(R5))                                            0001195
3  321    c2z_math.c math_2 #94                    LARL  R9,C37F259                      ch                       0001196
3  321    c2z_math.c math_2 #95                    STC   R0,0(0,R9)                                               0001197
*/


        convert = 1;
        return;
      }
    
    convert = 1;
    return;
  }

  if ((p6) && (p7) && (p8)) 
  {
    char tfield6a[VAR_LGTH];

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
    while (ch != '[') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != '.') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < m_struc_ct; I++) 
    {
      ret = strcmp(tfield1, w_struc[I].st_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield1a, w_struc[I].st_cname);
        strcpy(tfield6a, w_struc[I].st_cname);
        break;
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_print.c c2_printf_string Structure printf-012 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_print.c c2_printf_string rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

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
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_print.c c2_printf_string Structure printf-013 tfield2 Not Found = %s\n",tfield2);
      printf("c2z_print.c c2_printf_string rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < m_struc_ct; I++) 
    {
      ret = strcmp(tfield1, w_struc[I].st_name);
      ret1 = strcmp(tfield3, w_struc[I].st_field_name);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield3a, w_struc[I].st_field_cname);
        x9 = w_struc[I].st_field_lgth;
        x95 = w_struc[I].st_disp;
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_print.c c2_printf_string Structure printf-014 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_print.c c2_printf_string rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "T");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #4");
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
      strcpy(trace_1, "c2z_printf.c string Struc #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #6");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #7");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #8");
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
      strcpy(trace_1, "c2z_printf.c string Struc #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, tfield6a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #11");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #12");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #13");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #14");
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
      strcpy(trace_1, "c2z_printf.c string Struc #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R2,");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #16");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R3,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R0,R3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #18");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #19");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x95);
    strcat(a_string, wk_strg);
    strcat(a_string, "(R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #20");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #21");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c string Struc #21");
      trace_rec_3();
    }
    p_ln_ct = 0;
  }
}




void c2_printf_dec_only(int dec) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_dec_only");
    trace_rec_1();
  }

  char ch;
  char *p5, *p6;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field11[VAR_LGTH];
  char field11a[VAR_LGTH];
  char field12[VAR_LGTH];

  int pi;
  int pi2;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int x15 = 0;
  int v = 0;
  int prf1 = 0;
  int prf2 = 0;
  int prf5 = 0;
  int prf6 = 0;
  int prf7 = 0;
  int prf10 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;

  int fd1_define = 0;

  pi = 0;
  ch = p_string[pi];
  while (ch != '"') 
  {
    pi++;
    ch = p_string[pi];
  }

  prf1 = pi;
  pi = 0;
  ch = p_string[pi];
  while (ch != '%') 
  {
    pi++;
    ch = p_string[pi];
  }

  prf2 = pi;

  if (prf1 < prf2) 						/* means literal comes first */
  {
    pi = 0;
    while (ch != '"') 					/* 1st " */
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
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
        field2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    prf6 = 0;
    p5 = strchr(field2, '[');
    p6 = strchr(field2, ']');
    if ((p5) && (p6)) 			/* array printing		*/
    {
      prf6 = 1;
    }

    if (prf6 == 1) 				/* array processing		*/
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY ");
        trace_rec_1();
      }

      strcpy(field12, field1);

      if (z390 == 1) 
      {
        strcpy(field11, "L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(field11, wk_strg);

        for (x3 = 0; x3 < v_const; x3++) 
        {
          ret = strcmp(field11, w_constant[x3].const_current);
          if (ret == 0) 
          {
            strcpy(a_string, "         LARL  R9,C370WTOB");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #1");
              trace_rec_3();
            }

            strcpy(a_string, "         LARL  R8,");
            strcat(a_string, w_constant[x3].const_use);
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #2");
              trace_rec_3();
            }

            strcpy(field11, w_constant[x3].const_use);

            x3 = 0;
            for (I = 0; I < lv_ct; I++) 
            {
              ret = strcmp(field11, lw_variable[I].lv_name);
              ret1 = strcmp(sv_func, lw_variable[I].lv_func);
              if ((ret == 0) && (ret1 == 0)) 
              {
                x3 = 1;
                x15 = lw_variable[I].lv_lgth;
              }
            }

            if (x3 == 0) 
            {
              for (I = 0; I < gv_ct; I++) 
              {
                ret = strcmp(field11, gw_variable[I].gv_name);
                if (ret == 0) 
                {
                  x3 = 1;
                  x15 = gw_variable[I].gv_lgth;
                }
              }
            }

            strcpy(a_string, "         MVC   ");
            strcat(a_string, "0(");
            snprintf(wk_strg, sizeof(wk_strg), "%d", x15);
            strcat(a_string, wk_strg);
            strcat(a_string, ",R9),0(R8)");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #3");
              trace_rec_3();
            }

            break;
          }
        }

        x3 = 0;
        x4 = 0;

        strcpy(field7, wk_strg);
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field7, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            x4 = lw_variable[I].lv_lgth;
          }
        }

        if (x3 == 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field7, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x4 = gw_variable[I].gv_lgth;
            }
          }
        }
      }

      pi2 = 0;
      prf7 = 0;
      ch = field2[prf7];
      while (ch != '[') 
      {
        field4[pi2] = ch;
        pi2++;
        prf7++;
        ch = field2[prf7];
      }
      field4[prf7] = '\0';

      prf10 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        prf5 = strcmp(field4, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((prf5 == 0) && (ret1 == 0)) 
        {
          prf10 = 1;
          strcpy(field4a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (prf10 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          prf5 = strcmp(field4, gw_variable[I].gv_name);
          if (prf5 == 0) 
          {
            prf10 = 1;
            strcpy(field4a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (prf10 == 0) 
      {
        printf("\nc2z_print.c c2_printf_dec_only printf-017 field4 Not Found = %s\n",field4);
        printf("c2z_print.c c2_printf_dec only rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      pi2 = 0;
      prf7++;
      ch = field2[prf7];
      while (ch != ']') 
      {
        field7[pi2] = ch;
        pi2++;
        prf7++;
        ch = field2[prf7];
      }
      field7[pi2] = '\0';

      prf10 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        prf5 = strcmp(field7, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((prf5 == 0) && (ret1 == 0)) 
        {
          prf10 = 1;
          strcpy(field7a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (prf10 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          prf5 = strcmp(field7, gw_variable[I].gv_name);
          if (prf5 == 0) 
          {
            prf10 = 1;
            strcpy(field7a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (prf10 == 0) 
      {
        printf("\nc2z_print.c c2_printf_dec_only printf-018 field7 Not Found = %s\n",field7);
        printf("c2z_print.c c2_printf_dec_only rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field4a, gw_variable[I].gv_cname);
          if (ret == 0) 
          {
            strcpy(field5, gw_variable[I].gv_dsect);
            strcpy(field6, gw_variable[I].gv_label);
            strcpy(field7, gw_variable[I].gv_table);
            strcpy(field8, gw_variable[I].gv_aname);
            strcpy(field9, gw_variable[I].gv_sv_reg);
            strcpy(field10, gw_variable[I].gv_wk_reg);
            strcpy(field11, gw_variable[I].gv_wk_strg);
            gw_variable[I].gv_flag = 1;
          }
        }
      }

      strcpy(field12, field4);

      prf2 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field11, lw_variable[v].lv_name);
        if (ret == 0) 
        {
          strcpy(field11a, lw_variable[v].lv_cname);
        }
      }

      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field11, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          strcpy(field11a, gw_variable[v].gv_cname);
        }
      }

      strcpy(a_string, "         LARL  R9,C370LPCT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #4");
        trace_rec_3();
      }
      work_use_ct[73]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #5");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         CP    0(6,R9),0(2,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #6");
        trace_rec_3();
      }

      strcpy(a_string, "         JLNE  ");
      strcat(a_string, "PR");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "L");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #7");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R6,");
      strcat(a_string, field7);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #10");
        trace_rec_3();
      }

      strcpy(field2, field12);
      strcat(field2, "_rows");

      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          x4 = gw_variable[v].gv_lgth;
        }
      }

      strcpy(a_string, "         LAEY  R5,");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #11");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370LPCT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #12 ");
        trace_rec_3();
      }
      work_use_ct[73]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #13 ");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         AP    0(6,R9),0(2,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #14 ");
        trace_rec_3();
      }

      strcpy(a_string, "PR");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "L");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #15 ");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #16 ");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #17 ");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY   R6,");
      strcat(a_string, field6);
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #18 ");
        trace_rec_3();
      }

      strcpy(print_array_name, field10);
      strcpy(print_array_table, field7);

      strcpy(a_string, "         LARL  R9,C370EDN");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #20 ");
        trace_rec_3();
      }
      work_use_ct[51]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #21 ");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #22 ");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R15,WTOIMVC");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #23 ");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #23 ");
        trace_rec_3();
      }


      strcpy(a_string, "         LARL  R9,C370WTOB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #24 ");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370L8");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #25 ");
        trace_rec_3();
      }
      work_use_ct[9]++;

      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x4 = gw_variable[I].gv_lgth;
          }
        }
      }

      strcpy(a_string, "         MVC   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x15);
      strcat(a_string, wk_strg);
      strcat(a_string, "(8,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #26 ");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R15,WTOALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #27 ");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d ARRAY #27 ");
        trace_rec_3();
      }
      p_ln_ct = 0;
      print_array = 1;
      tot_wto++;
    }

    if (prf6 == 0) 
    {
      prf10 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          prf10 = 1;
          strcpy(field2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          fd1_define = lw_variable[I].lv_id;
          break;
        }
      }

      if (prf10 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          prf5 = strcmp(field2, gw_variable[I].gv_name);
          if (prf5 == 0) 
          {
            prf10 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            fd1_define = gw_variable[I].gv_id;
            break;
          }
        }
      }

      if (prf10 == 0) 
      {
        printf("\nc2z_print.c c2_printf printf-019 field2 Not Found = %s\n", field2);
        printf("c2z_print.c c2_printf rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (fd1_define == 1) 					/* Integer	*/
      {
        strcpy(field1, "L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(field1, wk_strg);

        for (x3 = 0; x3 < v_const; x3++) 
        {
          ret = strcmp(field1, w_constant[x3].const_current);
          if (ret == 0) 
          {
            strcpy(a_string, "         LARL  R9,");
            strcat(a_string, w_constant[x3].const_use);
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_print.c c2_printf %d  #1");
              trace_rec_3();
            }

            strcpy(a_string, "         LARL  R8,C370WTOB");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #2");
              trace_rec_3();
            }

            strcpy(wk_strg, w_constant[x3].const_use);

            x4 = 0;
            if (lv_ct > 0) 
            {
              for (v = 0; v < lv_ct; v++) 
              {
                ret = strcmp(wk_strg, lw_variable[v].lv_name);
                ret1 = strcmp(sv_func, lw_variable[v].lv_func);
                if ((ret == 0) && (ret1 == 0)) 
                {
                  x4 = 1;
                  x5 = lw_variable[v].lv_lgth;
                  lw_variable[I].lv_use_ct++;
                }
              }
            }

            strcpy(wk_strg, w_constant[x3].const_use);

            if (x4 == 0) 
            {
              if (gv_ct > 0) 
              {
                for (v = 0; v < gv_ct; v++) 
                {
                  ret = strcmp(wk_strg, gw_variable[v].gv_name);
                  if (ret == 0) 
                  {
                    x4 = 1;
                    x5 = gw_variable[v].gv_lgth;
                    gw_variable[I].gv_use_ct++;
                  }
                }
              }
            }

            snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
            strcpy(a_string, "         MVC   0(");
            strcat(a_string, wk_strg);
            strcat(a_string, ",R8),0(R9)");
            strcpy(wk_remark, " printf   */");
            write_remark();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #3");
              trace_rec_3();
            }
            break;
          }
        }

        strcpy(a_string, "         LARL  R9,C370DEC");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #4");
          trace_rec_3();
        }
        work_use_ct[67]++;

        if (dec == 1) 
        {
          strcpy(a_string, "         LARL  R8,C370ONE");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #5");
            trace_rec_3();
          }
        }

        if (dec == 2) 
        {
          strcpy(a_string, "         LARL  R8,C370TWO");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #6");
            trace_rec_3();
          }
        }

        if (dec == 3) 
        {
          strcpy(a_string, "         LARL  R8,C370THR");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #7");
            trace_rec_3();
          }
          work_use_ct[12]++;
        }

        if (dec == 4) 
        {
          strcpy(a_string, "         LARL  R8,C370FOUR");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #8");
            trace_rec_3();
          }
          work_use_ct[13]++;
        }

        if (dec == 5) 
        {
          strcpy(a_string, "         LARL  R8,C370FIVE");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #9");
            trace_rec_3();
          }
          work_use_ct[24]++;
        }

        strcpy(a_string, "         ZAP   0(2,R9),0(2,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #10");
          trace_rec_3();
        }

        x3 = 0;
        strcpy(sv_print_lit, "L");
        strcat(sv_print_lit, wk_strg);

        x3 = 0;
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field2, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field2a, gw_variable[v].gv_cname);
          }
        }

        if (x3 == 0) 				/* lookup in local variable	*/
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(field2, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x3 = 1;
              strcpy(field2a, lw_variable[v].lv_cname);
              lw_variable[v].lv_use_ct++;
            }
          }
        }

        x4 = 0;
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(sv_print_lit, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x4 = gw_variable[I].gv_lgth;
            }
          }
        }

        strcpy(a_string, "         LARL  R9,C370EDN");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #11");
          trace_rec_3();
        }
        work_use_ct[51]++;

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field2a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field2);
        strcat(wk_remark, " */ ");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #12");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #13");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R15,WTOIMVC");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #14");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #14");
          trace_rec_3();
        }


        strcpy(a_string, "         LARL  R9,C370WTOB");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #15");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370L10");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #16");
          trace_rec_3();
        }
        work_use_ct[71]++;

        strcpy(a_string, "         MVC   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
        strcat(a_string, wk_strg);
        strcat(a_string, "(10,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #17");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R15,WTOALPHA");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #18");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Dec Only #18");
          trace_rec_3();
        }
        p_ln_ct = 0;
        tot_wto++;
      }

      if ((z390 == 1) && (fd1_define == 2)) 				/* Double	*/
      {
        strcpy(field1, "L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(field1, wk_strg);

        for (x3 = 0; x3 < v_const; x3++) 
        {
          ret = strcmp(field1, w_constant[x3].const_current);
          if (ret == 0) 
          {
            strcpy(a_string, "         LARL  R9,");
            strcat(a_string, w_constant[x3].const_use);
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_print.c c2_printf %d Double #143");
              trace_rec_3();
            }

            strcpy(a_string, "         LARL  R8,C370WTOB");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_print.c c2_printf %d Double #144");
              trace_rec_3();
            }

            strcpy(wk_strg, w_constant[x3].const_use);

            x4 = 0;
            if (lv_ct > 0) 
            {
              for (v = 0; v < lv_ct; v++) 
              {
                ret = strcmp(wk_strg, lw_variable[v].lv_name);
                ret1 = strcmp(sv_func, lw_variable[v].lv_func);
                if ((ret == 0) && (ret1 == 0)) 
                {
                  x4 = 1;
                  x5 = lw_variable[v].lv_lgth;
                  lw_variable[I].lv_use_ct++;
                }
              }
            }

            strcpy(wk_strg, w_constant[x3].const_use);

            if (x4 == 0) 
            {
              if (gv_ct > 0) 
              {
                for (v = 0; v < gv_ct; v++) 
                {
                  ret = strcmp(wk_strg, gw_variable[v].gv_name);
                  if (ret == 0) 
                  {
                    x4 = 1;
                    x5 = gw_variable[v].gv_lgth;
                    gw_variable[I].gv_use_ct++;
                  }
                }
              }
            }

            snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
            strcpy(a_string, "         MVC   0(");
            strcat(a_string, wk_strg);
            strcat(a_string, ",R8),0(R9)");
            strcpy(wk_remark, " printf   */");
            write_remark();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_print.c c2_printf %d Double #145");
              trace_rec_3();
            }
            break;
          }
        }

        x3 = 0;
        strcpy(sv_print_lit, "L");
        strcat(sv_print_lit, wk_strg);

        x3 = 0;
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field2, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field2a, gw_variable[v].gv_cname);
          }
        }

        if (x3 == 0) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(field2, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x3 = 1;
              strcpy(field2a, lw_variable[v].lv_cname);
              lw_variable[v].lv_use_ct++;
            }
          }
        }

        x4 = 0;
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(sv_print_lit, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x4 = gw_variable[I].gv_lgth;
            }
          }
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field2a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #146");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #147");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVD   R9,0(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #148");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370TDW4");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #149");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370EDW4");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #150");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC    0(4,R8),0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #151");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370TDW4");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #152");
          trace_rec_3();
        }

        strcpy(a_string, "        ED     0(4,R8),4(R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #153");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370WTOB");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #154");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370TDW4");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #155");
          trace_rec_3();
        }
        work_use_ct[56]++;

        strcpy(a_string, "         MVC   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
        strcat(a_string, wk_strg);
        strcat(a_string, "(10,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #156");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R15,WTOALPHA");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #157");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf %d Double #157");
          trace_rec_3();
        }
        p_ln_ct = 0;
        tot_wto++;
      }
    }
  }
}

void c2_printf_float() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_float");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field12[VAR_LGTH];

  int pi;
  int pi2;
  int prf1 = 0;
  int prf2 = 0;
  int ret = 0;
  int ret1 = 0;
  int I = 0;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int v = 0;

  pi = 0;
  ch = p_string[pi];
  while (ch != '"') 
  {
    pi++;
    ch = p_string[pi];
  }

  prf1 = pi;
  pi = 0;
  ch = p_string[pi];
  while (ch != '%') 
  {
    pi++;
    ch = p_string[pi];
  }

  prf2 = pi;
  if (prf1 < prf2) 
  {
    pi = 0;
    while (ch != '"') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
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
        field2[pi2] = ch;
        pi2++;
      }
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
        break;
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
            break;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_print.c c2_printf printf-020 Integer field2 Not Found = %s\n",field2);
        printf("c2z_print.c c2_printf rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    strcpy(a_string, "         LARL  R9,C370DEC");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_float #1");
      trace_rec_3();
    }
    work_use_ct[67]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_float #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_float #3");
      trace_rec_3();
    }

    strcpy(field1, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(field1, wk_strg);

    for (x3 = 0; x3 < v_const; x3++) 
    {
      ret = strcmp(field1, w_constant[x3].const_current);
      if (ret == 0) 
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, w_constant[x3].const_use);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_float #4");
          trace_rec_3();
        }

        strcpy(field12, w_constant[x3].const_use);

        strcpy(a_string, "         LARL  R8,C370WTOB");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_float #5");
          trace_rec_3();
        }

        strcpy(wk_strg, w_constant[x3].const_use);

        x4 = 0;
        if (lv_ct > 0) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(wk_strg, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x4 = 1;
              x5 = lw_variable[v].lv_lgth;
              lw_variable[I].lv_use_ct++;
            }
          }
        }

        strcpy(wk_strg, w_constant[x3].const_use);
        if (x4 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (v = 0; v < gv_ct; v++) 
            {
              ret = strcmp(wk_strg, gw_variable[v].gv_name);
              if (ret == 0) 
              {
                x4 = 1;
                x5 = gw_variable[v].gv_lgth;
                gw_variable[v].gv_use_ct++;
              }
            }
          }
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
        strcpy(a_string, "         MVC   0(");
        strcat(a_string, wk_strg);
        strcat(a_string, ",R8),0(R9)");
        strcpy(wk_remark, " printf   */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_float #6");
          trace_rec_3();
        }
        break;
      }
    }

    x3 = 0;
    strcpy(sv_print_lit, "L");
    strcat(sv_print_lit, wk_strg);

    x3 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field2, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[v].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_print.c c2_printf_float printf-021 field2 Not Found = %s\n",field2);
      printf("c2z_print.c c2_printf_float rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x4 = 0;
    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(sv_print_lit, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x4 = gw_variable[I].gv_lgth;
        }
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */ ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_float #7");
      trace_rec_3();
    }

    strcpy(a_string, "         L     R9,0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_float #8");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOFMVC");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_float #9");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_float #9");
      trace_rec_3();
    }


    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_float #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L10");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_float #11");
      trace_rec_3();
    }
    work_use_ct[71]++;

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
    strcat(a_string, wk_strg);
    strcat(a_string, "(10,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_float #12");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_float #13");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_float #13");
      trace_rec_3();
    }
    p_ln_ct = 0;
    tot_wto++;
  }
}





void c2_printf_numeric() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_numeric");
    trace_rec_1();
  }

  char ch;
  char *p5, *p6, *p7;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field11[VAR_LGTH];
  char field11a[VAR_LGTH];
  char field12[VAR_LGTH];
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield6a[VAR_LGTH];
 
  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int x15 = 0;
  int x90 = 0;
  int v = 0;
  int prf1 = 0;
  int prf2 = 0;
  int prf5 = 0;
  int prf6 = 0;
  int prf7 = 0;
  int prf10 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
  int m7fd_type = 0;
  int fd3_type = 0;

  int fd1_define = 0;

  pi = 0;
  ch = p_string[pi];
  while (ch != '"') 
  {
    pi++;
    ch = p_string[pi];
  }

  prf1 = pi;
  pi = 0;
  ch = p_string[pi];
  while (ch != '%') 
  {
    pi++;
    ch = p_string[pi];
  }

  prf2 = pi;

  if (prf1 < prf2)  
  {
    pi = 0;
    while (ch != '"') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
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
        field2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    prf6 = 0;
    p5 = strstr(p_string, "[");
    p6 = strstr(p_string, "]");
    p7 = strstr(p_string, ".");

    if ((p5) && (p6) && (!p7)) 
    {
      prf6 = 1;
    }

    if ((p5) && (p6) && (p7)) 
    {
      prf6 = 2;
    }

    if(prf6 == 0)	/* simple numeric */
    {
      int s;
      p102 = 0;

      s = strlen(p_string);
      for (I = 0; I < s; I++) 
      {
        if((p_string[I] == '\\') && (p_string[I+1] == 'n'))
        {
          p102++;
        }
      }  

      strcpy(a_string, "         LARL  R9,C370DEC");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf %d #40");
        trace_rec_3();
      }
      work_use_ct[67]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf %d #41");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf %d #42");
        trace_rec_3();
      }

      strcpy(field1, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(field1, wk_strg);

      for (x3 = 0; x3 < v_const; x3++) 
      {
        ret = strcmp(field1, w_constant[x3].const_current);
        if (ret == 0) 
        {
          strcpy(a_string, "         LARL  R9,");
          strcat(a_string, w_constant[x3].const_use);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c printf %d #43");
            trace_rec_3();
          }
          strcpy(field12, w_constant[x3].const_use);

          strcpy(a_string, "         LARL  R8,C370WTOB");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c printf %d #44");
            trace_rec_3();
          }

          strcpy(wk_strg, w_constant[x3].const_use);

          x4 = 0;
          if (lv_ct > 0) 
          {
            for (v = 0; v < lv_ct; v++) 
            {
              ret = strcmp(wk_strg, lw_variable[v].lv_name);
              ret1 = strcmp(sv_func, lw_variable[v].lv_func);
              if ((ret == 0) && (ret1 == 0)) 
              {
                x4 = 1;
                x5 = lw_variable[v].lv_lgth;
                lw_variable[I].lv_use_ct++;
              }
            }
          }

          strcpy(wk_strg, w_constant[x3].const_use);
          if (x4 == 0) 
          {
            if (gv_ct > 0) 
            {
              for (v = 0; v < gv_ct; v++) 
              {
                ret = strcmp(wk_strg, gw_variable[v].gv_name);
                if (ret == 0) 
                {
                  x4 = 1;
                  x5 = gw_variable[v].gv_lgth;
                  gw_variable[v].gv_use_ct++;
                }
              }
            }
          }

          snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
          strcpy(a_string, "         MVC   ");
          strcat(a_string, wk_strg);
          strcat(a_string,"(");
          snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
          strcat(a_string, wk_strg);
          strcat(a_string, ",R8),0(R9)");
          strcpy(wk_remark, " printf   */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c printf %d #45");
            trace_rec_3();
          }
          p_ln_ct = p_ln_ct + x5;
          break;
        }
      }

      x3 = 0;
      strcpy(sv_print_lit, "L");
      strcat(sv_print_lit, wk_strg);

      x3 = 0;
      if (x3 == 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field2, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(field2a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[v].gv_cname);
        }
      }

      x4 = 0;
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(sv_print_lit, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x4 = gw_variable[I].gv_lgth;
          }
        }
      }

      strcpy(a_string, "         LARL  R9,C370EDN");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf %d #47");
        trace_rec_3();
      }
      work_use_ct[51]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf %d #48");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf %d #49");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R15,WTOIMVC");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf %d #50");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf %d #51");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370WTOB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf %d #52");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370L10");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf %d #53");
        trace_rec_3();
      }
      work_use_ct[71]++;

      strcpy(a_string, "         MVC   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
      strcat(a_string, wk_strg);
      strcat(a_string, "(10,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c printf %d #54");
        trace_rec_3();
      }
      p_ln_ct = p_ln_ct + 10;

      if(p102 == 1)
      {
        strcpy(a_string, "         LARL  R15,WTOALPHA");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c printf %d #58");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c printf %d #59");
          trace_rec_3();
        }
        p_ln_ct = 0;
      }

      tot_wto++;
    }
  }


}










