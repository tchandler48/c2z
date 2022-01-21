/* ***************************************************
*  c2z : c2z_print.c :                               *
*                                                    *
*  next error = print = 21                           *
*  Copyright TCCS (c) 2015 - 2022                    *
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

/*
  if((x != 2) || (x != 4)) 
  {
    printf("c2_fprintf Missing Starting Quote\n");
    printf("c2_fprintf rct = %d p_string = %s", rct, p_string);
    c2_debug();
    exit(1);
  }
*/

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
      strcpy(trace_1, "c2z_print.c #1");
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
      strcpy(trace_1, "c2z_print.c #2");
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
          strcpy(trace_1, "c2z_print.c #3");
          trace_rec_3();
        }
      }
    }

    strcpy(a_string, "         PUT    ");
    strcat(a_string, field1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL   R9,C370PB");
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL   R8,C370PB");
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #6");
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
      strcpy(trace_1, "c2z_print.c #7");
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
      strcpy(trace_1, "c2z_print.c #8");
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
          strcpy(trace_1, "c2z_print.c #9");
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
          strcpy(trace_1, "c2z_print.c #10");
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
          strcpy(trace_1, "c2z_print.c #11");
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
          strcpy(trace_1, "c2z_print.c #12");
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
          strcpy(trace_1, "c2z_print.c #13");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #14");
          trace_rec_3();
        }

        strcpy(a_string, "         PUT   (R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #15");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370PB");
        snprintf(wk_strg, sizeof(wk_strg), "%d", w_buf_ct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #16");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370B1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #17");
          trace_rec_3();
        }
        work_use_ct[52]++;

        strcpy(a_string, "         MVC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #18");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   1(131,R9),0(R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #19");
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

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
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
          strcpy(trace_1, "c2z_print.c #20");
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
      strcpy(trace_1, "c2z_print.c #21");
      trace_rec_3();
    }

    strcpy(a_string, "         MVZ   C370AZNE+L'C370AZNE-1(1),=X'F0'");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #22");
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
      strcpy(trace_1, "c2z_print.c #23");
      trace_rec_3();
    }

    strcpy(a_string, "         BRASL R9,PUTFILE");
    strcpy(wk_remark, " putfile  */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #24");
      trace_rec_3();
    }

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #25");
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
  int x105 = 0;
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
  p102 = 0;
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
    if((p_string[I] == '\\') && (p_string[I + 1] == 'n'))
    {
      p102 = 1;
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
          x105 = lw_variable[I].lv_lgth;
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
            x105 = gw_variable[I].gv_lgth;
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      strcpy(a_string, "         LARL  R9,C370WTOB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #30");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, w_constant[x3].const_use);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #31");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   ");
/*
      snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
      strcat(a_string, wk_strg); 
*/
      strcat(a_string, "0(");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x105);
      strcat(a_string, wk_strg);
      strcat(a_string, ",R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #32");
        trace_rec_3();
      }

/* 
     p_ln_ct = p_ln_ct + x105;
*/

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
    strcpy(trace_1, "c2z_print.c #33");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #34");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #35");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #36");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #37");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #38");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #39");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #40");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #41");
    trace_rec_3();
  }


  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #42");
    trace_rec_3();
  }
  work_use_ct[94]++;

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " ROW */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #43");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #44");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #45");
    trace_rec_3();
  }
  work_use_ct[95]++;

  if(fd5_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " COL */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #46");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #47");
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
      strcpy(trace_1, "c2z_print.c #48");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #49");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #50");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #51");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #52");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #53");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  strcpy(wk_remark, " row value */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #54");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #55");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #56");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #57");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #58");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #59");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #60");
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
      strcpy(trace_1, "c2z_print.c #61");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #62");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #63");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #64");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #65");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #66");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370NWK5");
    strcpy(wk_remark, " COL */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #67");
      trace_rec_3();
    }
    work_use_ct[95]++;
  }

  if(fd5_type == 2)
  {
    strcpy(a_string, "         LARL  R7,C370NWK5");
    strcpy(wk_remark, " COL */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #68");
      trace_rec_3();
    }
    work_use_ct[05]++;
  }

  strcpy(a_string, "         LARL  R5,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #69");
    trace_rec_3();
  }
  work_use_ct[33]++;
 
  strcpy(a_string, "         AP    0(6,R7),0(6,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #70");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #71");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #72");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #73");
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
    strcpy(trace_1, "c2z_print.c #74");
    trace_rec_3();
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R9,C370NWK4");
    strcpy(wk_remark, " ROW */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #75");
      trace_rec_3();
    }
    work_use_ct[94]++;
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #76");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #77");
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
    strcpy(trace_1, "c2z_print.c #78");
    trace_rec_3();
  }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #79");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #80");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #81");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #82");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #83");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #84");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK4");
    strcpy(wk_remark, " ROW */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #85");
      trace_rec_3();
    }
    work_use_ct[94]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #86");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #87");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #88");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #89");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #90");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R8,C370NWK5");
    strcpy(wk_remark, " COL */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #91");
      trace_rec_3();
    }
    work_use_ct[95]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #92");
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
    strcpy(trace_1, "c2z_print.c #93");
    trace_rec_3();
  }

/*  C370NWK1 contains pointer to array element */

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #94");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #95");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #96");
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
    strcpy(trace_1, "c2z_print.c #97");
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
    strcpy(trace_1, "c2z_print.c #98");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #99");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #100");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #101");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #102");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #103");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #104");
    trace_rec_3();
  }
  work_use_ct[31]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #105");
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
    strcpy(trace_1, "c2z_print.c #106");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #107");
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
    strcpy(trace_1, "c2z_print.c #108");
    trace_rec_3();
  }


/* src[i][j][0]   (string) */


  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_print.c #109");
    trace_rec_3();
  }
    
  strcpy(a_string, "         MVC   ");

/*
  snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
  strcat(a_string, wk_strg);
*/

  strcat(a_string, "0(");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
  strcat(a_string, wk_strg); 
  strcat(a_string, ",R9),0(R6)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_print.c #110");
    trace_rec_3();
  }

/*
  p_ln_ct = p_ln_ct + x101;
*/

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #111"); 
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #112");
      trace_rec_3();
    }

/*
    p_ln_ct = 0;
*/

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
      strcpy(trace_1, "c2z_print.c #120");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, w_constant[x3].const_use);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #121");
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
      strcpy(trace_1, "c2z_print.c #122");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcpy(a_string, "         LARL  R5,");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #123");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcpy(a_string, "         LAEY  R3,");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #124");
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
    strcpy(trace_1, "c2z_print.c #125");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #126");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #127");
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
      strcpy(trace_1, "c2z_print.c #128");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #129");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #130");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #131");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #132");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #133");
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
      strcpy(trace_1, "c2z_print.c #134");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #135");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #136");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #137");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #138");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #139");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #140");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #141");
    trace_rec_3();
  }
  work_use_ct[32]++;
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #142");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #143");
    trace_rec_3();
  }
  work_use_ct[50]++;

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
      strcpy(trace_1, "c2z_print.c #144");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #145");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #146");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #147");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #148");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #149");
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
      strcpy(trace_1, "c2z_print.c #150");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R5,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #151");
    trace_rec_3();
  }
  work_use_ct[33]++;
 
  strcpy(a_string, "         AP    0(6,R7),0(6,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #152");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #153");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #154");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #155");
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
    strcpy(trace_1, "c2z_print.c #156");
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
    strcpy(trace_1, "c2z_print.c #157");
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
      strcpy(trace_1, "c2z_print.c #158");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #159");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #160");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #161");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #162");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #163");
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
      strcpy(trace_1, "c2z_print.c #164");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #165");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #166");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #167");
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
      strcpy(trace_1, "c2z_print.c #168");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #169");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #170");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #171");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #172");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #173");
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
      strcpy(trace_1, "c2z_print.c #174");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #175");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #176");
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
    strcpy(trace_1, "c2z_print.c #177");
    trace_rec_3();
  }

  strcpy(a_string, "*         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #178");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "*         LARL  R8,");
  strcat(a_string, field4a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field4);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #179");
    trace_rec_3();
  }

  strcpy(a_string, "*         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #180");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "*         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #181");
    trace_rec_3();
  }

  strcpy(a_string, "*         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #182");
    trace_rec_3();
  }

  strcpy(a_string, "*         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #183");
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
    strcpy(trace_1, "c2z_print.c #184");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #185");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, ar_field12);
  strcpy(wk_remark, " ");
  strcat(wk_remark, ar_field12);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #186");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #187");
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
      strcpy(trace_1, "c2z_print.c #188");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #189");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #190");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #191");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #192");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #193");
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
      strcpy(trace_1, "c2z_print.c #194");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #195");
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
      strcpy(trace_1, "c2z_print.c #196");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #197");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #198");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #199");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #200");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #201");
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
      strcpy(trace_1, "c2z_print.c #202");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #203");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #204");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #205");
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
    strcpy(trace_1, "c2z_print.c #206");
    trace_rec_3();
  }

/*  C370NWK1 contains pointer to array element */

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #207");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #208");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #209");
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
    strcpy(trace_1, "c2z_print.c #210");
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
    strcpy(trace_1, "c2z_print.c #211");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #212");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #213");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #214");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #215");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #216");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #217");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #218");
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
    strcpy(trace_1, "c2z_print.c #219");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #220");
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
    strcpy(trace_1, "c2z_print.c #221");
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
        strcpy(trace_1, "c2z_print.c #222");
        trace_rec_3();
      }

      strcpy(a_string, "*         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_print.c #223");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "*         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_print.c #224");
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
      strcpy(trace_1, "c2z_print.c #225");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(80,R9),0(R6)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #226");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #227");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #228");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #229");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R2,1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #230");
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
      strcpy(trace_1, "c2z_print.c #231");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #232");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #233");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #234");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #235");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R5,0(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #236");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L80");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #237");
      trace_rec_3();
    }
    work_use_ct[10]++;

    strcpy(a_string, "         IC    R0,0(R8,(R5))");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #238");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #239");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         STC   R0,0(0,R9)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #240");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #241");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #242");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #243");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "M");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #244");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #245");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #246");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #247");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R3,R2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #248");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "L");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c 249");
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
      strcpy(trace_1, "c2z_print.c #250");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #251");
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
      strcpy(trace_1, "c2z_print.c #252");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R0,R3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #253");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #254");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #255");
      trace_rec_3();
    }

/*
    p_ln_ct = 0;
*/

  }


/* src[i][j][0]   (numeric) */
  if((fd4_type == 2) && (fd5_type == 2) && (printf_type == 2))		
  {
    strcpy(a_string, "         LARL  R9,C370EDN");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #260");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #261");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOIMVC");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #262");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #263");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #264");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L10");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #265");
      trace_rec_3();
    }
    work_use_ct[71]++;

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcat(a_string, wk_strg);
    strcat(a_string, "(10,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #266");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R2,10");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #267");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R3,R2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #268");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R0,R3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c 269");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #270");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #271");
      trace_rec_3();
    }

/*
    p_ln_ct = 0;
*/

  } 

  if((fd4_type == 1) && (fd5_type == 1))
  {
    strcpy(a_string, "         LARL  R9,C370EDN");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #272");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #273");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOIMVC");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #274");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #275");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #276");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L10");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #277");
      trace_rec_3();
    }
    work_use_ct[71]++;

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcat(a_string, wk_strg);
    strcat(a_string, "(10,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #278");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R2,10");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #279");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R3,R2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #280");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R0,R3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #281");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #282");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c #283");
      trace_rec_3();
    }

/*
    p_ln_ct = 0;
*/

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
    strcpy(trace_1, "c2z_print.c #290");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #291");
    trace_rec_3();
  }

/*
  snprintf(ptr_lgth, sizeof(ptr_lgth), "%d", p_ln_ct);
*/

  strcpy(a_string, "         MVC   ");

/*
  strcat(a_string, ptr_lgth);
*/

  strcat(a_string, "0(");
  snprintf(ptr_lgth, sizeof(ptr_lgth), "%d", x5);
  strcat(a_string,ptr_lgth);
  strcat(a_string, ",R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #292");
    trace_rec_3();
  }

  if(p102 == 0)
  {
 /*   p_ln_ct = p_ln_ct + x5; */
   
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #294");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #295");
      trace_rec_3();
    }

/*
    p_ln_ct = 0;
*/

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
    strcpy(trace_1, "c2z_print.c #300");
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
    strcpy(trace_1, "c2z_print.c #301");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #302");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R15,WTOIMVC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #303");
    trace_rec_3();
  }

  strcpy(a_string, "         BAKR  0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #304");
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
    strcpy(trace_1, "c2z_print.c #305");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #306");
    trace_rec_3();
  }
  work_use_ct[71]++;

  strcpy(a_string, "         MVC  0(8,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #307");
    trace_rec_3();
  }
}



void c2_sprintf(void)
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_sprintf START");
    trace_rec_1();
  }

  char *p;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];

   int pi;
   int si;
   int bk_ct = 0;
   int len;
   int I;
   int ret;
   int ret1;
   int pf1;
   int prf3;
   int x3;
   int is_dec;

   bk_ct = 0;
   len = strlen(p_string);
   for(I = 0; I < len; I++)
   {
     ch = p_string[I];
     if(ch == '[')
     {
       bk_ct++;
     }
     if(ch == ']')
     {
       bk_ct++;
     }
   }

   if(bk_ct == 2)
   {
     convert = 1;
     return;
   }

   if(bk_ct == 4)
   {
     pi = 0;
     ch = p_string[pi];
     while(ch != '(')
     {
       pi++;
       ch = p_string[pi];
     }

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != '[')
     {
       field1[si] = ch;
       si++;
       pi++;
       ch = p_string[pi];
     }
     field1[si] = '\0';

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != ']')
     {
       field2[si] = ch;
       si++;
       pi++;
       ch = p_string[pi];
     }
     field2[si] = '\0';

     si = 0;
     pi++;
     pi++;
     ch = p_string[pi];
     while(ch != ']')
     {
       field3[si] = ch;
       si++;
       pi++;
       ch = p_string[pi];
     }
     field3[si] = '\0';

     pi++;
     ch = p_string[pi];
     while(ch != '\"')
     {
       pi++;
       ch = p_string[pi];
     }

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != '\"')
     {
       field4[si] = ch;
       si++;
       pi++;
       ch = p_string[pi];
     }
     field4[si] = '\0';

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != ')')
     {
       if(ch != ',')
       {
         if(ch != ' ')
         {
           field5[si] = ch;
           si++;
         }
       }
       pi++;
       ch = p_string[pi];
     }
     field5[si] = '\0';

     x3 = 0;
     for (I = 0; I < gv_ct; I++) 
     {
       ret = strcmp(field1, gw_variable[I].gv_name);
       if (ret == 0) 
       {
         x3 = 1;
         strcpy(field1a, gw_variable[I].gv_cname);
         strcpy(ar_field5, gw_variable[I].gv_dsect);
         strcpy(ar_field6, gw_variable[I].gv_label);
         strcpy(ar_field7, gw_variable[I].gv_table);
         strcpy(ar_field8, gw_variable[I].gv_aname);
       }
     }

     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field2, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         pf1 = 1;
         strcpy(field2a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
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
     
     pf1 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field3, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         pf1 = 1;
         strcpy(field3a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
         break;
       }
     }

     if (pf1 == 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         prf3 = strcmp(field3, gw_variable[I].gv_name);
         if (prf3 == 0) 
         {
           pf1 = 1;
           strcpy(field3a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
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

     pf1 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field5, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         pf1 = 1;
         strcpy(field5a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
         break;
       }
     }

     if (pf1 == 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         prf3 = strcmp(field5, gw_variable[I].gv_name);
         if (prf3 == 0) 
         {
           pf1 = 1;
           strcpy(field5a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
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

/*  find displacement in array  */

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #800");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         LARL  R8,C370ZERO");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #801");
       trace_rec_3();
     }
     work_use_ct[32]++;

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #802");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,");
     strcat(a_string, field2a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field2);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #803");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370ZERO");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #804");
       trace_rec_3();
     }
     work_use_ct[32]++;

     strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #805");
       trace_rec_3();
     }

     strcpy(a_string, "         JLNE  ");
     strcat(a_string, "L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "A");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #806");
       trace_rec_3();
     }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #807");
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
       strcpy(trace_1, "c2z_print.c #808");
       trace_rec_3();
     }

     strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #809");
       trace_rec_3();
     }

     strcpy(a_string, "         JLU   ");
     strcat(a_string, "L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "E");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #810");
       trace_rec_3();
     }

/* ROW IS GREATER THAN ZERO  */
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcpy(a_string, "L");
     strcat(a_string, wk_strg);
     strcat(a_string, "A");
     check_length();
     strcat(a_string, "DS    0H");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #811");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,");
     strcat(a_string, field2a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field2);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #812");
       trace_rec_3();
     }

     strcpy(a_string, "         LAEY  R5,26");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #813");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R7,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #814");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         CVD   R5,0(R7)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #815");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370NWK2");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #816");
       trace_rec_3();
     }
     work_use_ct[50]++;

     strcpy(a_string, "         LARL  R7,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #817");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #818");
       trace_rec_3();
     }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #819");
       trace_rec_3();
     }
     work_use_ct[50]++;

     strcpy(a_string, "         LARL  R8,C370NWK2");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #820");
       trace_rec_3();
     }
     work_use_ct[50]++;

     strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #821");
       trace_rec_3();
     }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #822");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         LARL  R8,");
     strcat(a_string, field3a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field3);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #823");
       trace_rec_3();
     }

     strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #824");
       trace_rec_3();
     }

/* END OF ROUTINE C370NWK1 CONTAINS DISPLAYMENT */
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcpy(a_string, "L");
     strcat(a_string, wk_strg);
     strcat(a_string, "E");
     check_length();
     strcat(a_string, "DS    0H");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #825");
       trace_rec_3();
     }

     is_dec = 0;
     p = strstr(field4, "%d");
     if(p)
     {
       is_dec = 1;
     }

     p = strstr(field4, "%.2f");
     if(p)
     {
       is_dec = 2;
     }

     if(is_dec == 1)
     {
printf("c2z_print.c #2  inside is_dec = %d\n",is_dec);

     strcpy(a_string, "         LARL  R9,C370EDN");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #826");
       trace_rec_3();
     }
     work_use_ct[51]++;

     strcpy(a_string, "         LARL  R8,");
     strcat(a_string, field5a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field5);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #901");
       trace_rec_3();
     }

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #902");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R15,WTOIMVC");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #903");
       trace_rec_3();
     }

     strcpy(a_string, "         BAKR  0,R15");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #904");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370L10");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #905");
       trace_rec_3();
     }

     strcpy(a_string, "         MVC   0(R6),0(R8)");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #905");
       trace_rec_3();
     }

       convert = 1;
       return;
     }

     if(is_dec == 2)
     {

     strcpy(a_string, "         LARL  R9,C370EDN");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #826");
       trace_rec_3();
     }
     work_use_ct[51]++;

     strcpy(a_string, "         LARL  R8,");
     strcat(a_string, field5a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field5);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #901");
       trace_rec_3();
     }

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #902");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R15,WTOIMVC");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #903");
       trace_rec_3();
     }

     strcpy(a_string, "         BAKR  0,R15");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #904");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370L10");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #905");
       trace_rec_3();
     }

     strcpy(a_string, "         MVC   0(R6),0(R8)");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #906");
       trace_rec_3();
     }

     convert = 1;
     return;
     }
   }


   if(bk_ct == 0)
   {


printf("\nc2z_print.c sprintf bk = 0 rct = %d p_string = %s\n",rct,p_string);
     pi = 0;
     ch = p_string[pi];
     while(ch != '(')
     {
       pi++;
       ch = p_string[pi];
     }

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != ',')
     {
       field1[si] = ch;
       si++;
       pi++;
       ch = p_string[pi];
     }
     field1[si] = '\0';
printf("c2z_print.c field1 = %s\n",field1);

     pi++;
     ch = p_string[pi];
     while(ch != '\"')
     {
       pi++;
       ch = p_string[pi];
     }

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != '\"')
     {
       field2[si] = ch;
       si++;
       pi++;
       ch = p_string[pi];
     }
     field2[si] = '\0';
printf("c2z_print.c field2 = %s\n",field2);

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != ')')
     {
       if(ch != ',')
       {
         if(ch != ' ')
         {
           field3[si] = ch;
           si++;
         }
       }
       pi++;
       ch = p_string[pi];
     }
     field3[si] = '\0';
printf("c2z_print.c field3 = %s\n",field3);


     pf1 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field1, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         pf1 = 1;
         strcpy(field1a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
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


     pf1 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field3, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         pf1 = 1;
         strcpy(field3a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
         break;
       }
     }

     if (pf1 == 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         prf3 = strcmp(field3, gw_variable[I].gv_name);
         if (prf3 == 0) 
         {
           pf1 = 1;
           strcpy(field3a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
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

     is_dec = 0;
     p = strstr(field4, "%d");
     if(p)
     {
       is_dec = 1;
     }

     p = strstr(field4, "%.2f");
     if(p)
     {
       is_dec = 2;
     }

     if(is_dec == 1)
     {
       strcpy(a_string, "         LARL  R9,C370EDN");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_print.c #826");
         trace_rec_3();
       }
       work_use_ct[51]++;

       strcpy(a_string, "         LARL  R8,");
       strcat(a_string, field5a);
       strcpy(wk_remark, " ");
       strcat(wk_remark, field5);
       strcat(wk_remark, " */");
       write_remark();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #901");
         trace_rec_3();
       }

       strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
       src_line();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #902");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R15,WTOIMVC");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_print.c #903");
         trace_rec_3();
       }

       strcpy(a_string, "         BAKR  0,R15");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_print.c #904");
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
         strcpy(trace_1, "c2z_print.c #905");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R8,C370L10");
       src_line();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #905");
         trace_rec_3();
       }

       strcpy(a_string, "         MVC  0(R9),0(R8)");
       src_line();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #906");
         trace_rec_3();
       }
   
       convert = 1;
       return;
     }

    if(is_dec == 2)
    {
printf("c2z_print.c springf no brackets is_dec 2 NOT CODED\n");    
      convert = 1;
      return;
    }



    convert = 1;
    return;
  }
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
  p102++;

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
    strcpy(trace_1, "c2z_print.c #310");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, w_constant[x3].const_use);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #311");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0");
  strcat(a_string, "(");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
  strcat(a_string, wk_strg);
  strcat(a_string, ",R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #312");
    trace_rec_3();
  }

/*
  p_ln_ct = x1;
*/

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
        x9 = lw_variable[I].lv_lgth;
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
          x9 = gw_variable[I].gv_lgth;
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
      strcpy(trace_1, "c2z_print.c #313");
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
      strcpy(trace_1, "c2z_print.c #314");
      trace_rec_3();
    }

    x11 = (75 - x1);

    if(x9 > x11)
    {
       x9 = x11;
    }

    strcpy(a_string, "         MVC   ");

/*
    snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
    strcat(a_string, wk_strg);
*/

    strcat(a_string, "0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #315");
      trace_rec_3();
    }

    p102 = 1;

    if(p102 == 1)
    {
      strcpy(a_string, "         LARL  R15,WTOALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #316");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #317");
        trace_rec_3();
      }

/*
      p_ln_ct = 0;
*/

    }

    if(p102 == 0)
    {
 /*     p_ln_ct = p_ln_ct + x9; */
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
          strcpy(trace_1, "c2z_print.c #318");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #319");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #320");
          trace_rec_3();
        }
        work_use_ct[32]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        var_use[1]++;
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #321");
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
          strcpy(trace_1, "c2z_print.c #322");
          trace_rec_3();
        }

        if (fd22_type == 2) 
        {
          strcpy(a_string, "         LAEY  R5,");
          strcat(a_string, tfield22);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #323");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL R9,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #324");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         CVD  R5,0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #325");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL R9,C370NWK2");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #326");
            trace_rec_3();
          }
          work_use_ct[50]++;

          strcpy(a_string, "         LARL R8,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #327");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         ZAP  0(6,R9),0(8,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #328");
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
            strcpy(trace_1, "c2z_print.c #329");
            trace_rec_3();
          }
        }

        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #330");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #331");
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
          strcpy(trace_1, "c2z_print.c #332");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #333");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #334");
          trace_rec_3();
        }
        work_use_ct[33]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #335");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, field6);
        strcat(a_string, "(R0,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #336");
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
          strcpy(trace_1, "c2z_print.c #337");
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
          strcpy(trace_1, "c2z_print.c #338");
          trace_rec_3();
        }

        strcpy(print_array_name, field10);
        strcpy(print_array_table, field7);

        strcpy(a_string, "         LARL  R9,C370L80");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #339");
          trace_rec_3();
        }
        work_use_ct[10]++;
 
        strcpy(a_string, "         MVC   0(80,R9),0(R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #340");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #341");
          trace_rec_3();
        }
        work_use_ct[50]++;
 
        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #342");
          trace_rec_3();
        }
        work_use_ct[32]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #343");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R2,1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #344");
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
          strcpy(trace_1, "c2z_print.c #345");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #346");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #347");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #348");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #349");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVB   R5,0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #350");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370L80");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #351");
          trace_rec_3();
        }
        work_use_ct[10]++;
 
        strcpy(a_string, "         IC    R0,0(R8,(R5))");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #352");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #353");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         STC   R0,0(0,R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #354");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #355");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         LARL  R8,C370EOF");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #356");
          trace_rec_3();
        }
        work_use_ct[74]++;

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #357");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "M");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #358");
          trace_rec_3();
        }

         strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #359");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #360");
          trace_rec_3();
        }
        work_use_ct[33]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #361");
          trace_rec_3();
        }

        strcpy(a_string, "         AR    R3,R2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #362");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "L");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #363");
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
          strcpy(trace_1, "c2z_print.c #364");
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
          strcpy(trace_1, "c2z_print.c #365");
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
          strcpy(trace_1, "c2z_print.c #366");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R15,WTOALPHA");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #368");
          trace_rec_3();
        }
    
        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #369");
          trace_rec_3();
        }
  /*      p_ln_ct = 0; */
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
        strcpy(trace_1, "c2z_print.c #370");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #371");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #372");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #373");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #374");
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
        strcpy(trace_1, "c2z_print.c #375");
        trace_rec_3();
      }

      strcpy(a_string, "         IC    R0,0(R8,(R5))");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #376");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #377");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         STC   R0,0(0,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #378");
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
        strcpy(trace_1, "c2z_print.c #379");
        trace_rec_3();
      }
    
      strcpy(a_string, "         LARL  R8,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #380");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         MVC   ");

/*
      snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
      strcat(a_string, wk_strg);
*/

      strcat(a_string, "0(");
      strcat(a_string, "1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #381"); 
        trace_rec_3();
      }

    if(p102 == 1)
    {
      strcpy(a_string, "         LARL  R15,WTOALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #382");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #383");
        trace_rec_3();
      }
 /*     p_ln_ct = 0; */
    }

    if(p102 == 0)
    {
/*      p_ln_ct = p_ln_ct + x9; */
    }

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
      strcpy(trace_1, "c2z_printf.c #385");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #386");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #387");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "T");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #388");
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
      strcpy(trace_1, "c2z_printf.c #389");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #390");
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
      strcpy(trace_1, "c2z_printf.c #391");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #392");
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
      strcpy(trace_1, "c2z_printf.c #393");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, tfield6a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #394");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #395");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #396");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #397");
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
      strcpy(trace_1, "c2z_printf.c #398");
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
      strcpy(trace_1, "c2z_printf.c #399");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R2,");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #400");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R3,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #401");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R0,R3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #402");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #403");
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
      strcpy(trace_1, "c2z_printf.c #404");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #405");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #406");
      trace_rec_3();
    }
 /*   p_ln_ct = 0; */
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
              strcpy(trace_1, "c2z_print.c #411");
              trace_rec_3();
            }

            strcpy(a_string, "         LARL  R8,");
            strcat(a_string, w_constant[x3].const_use);
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_print.c #412");
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
              strcpy(trace_1, "c2z_print.c #413");
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
        strcpy(trace_1, "c2z_print.c #414");
        trace_rec_3();
      }
      work_use_ct[73]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #415");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         CP    0(6,R9),0(2,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #416");
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
        strcpy(trace_1, "c2z_print.c #417");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R6,");
      strcat(a_string, field7);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #418");
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
        strcpy(trace_1, "c2z_print.c #419");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370LPCT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #420");
        trace_rec_3();
      }
      work_use_ct[73]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #421");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         AP    0(6,R9),0(2,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #422");
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
        strcpy(trace_1, "c2z_print.c #423");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #424");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #425");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY   R6,");
      strcat(a_string, field6);
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #426");
        trace_rec_3();
      }

      strcpy(print_array_name, field10);
      strcpy(print_array_table, field7);

      strcpy(a_string, "         LARL  R9,C370EDN");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #427");
        trace_rec_3();
      }
      work_use_ct[51]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #428");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #429");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R15,WTOIMVC");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #430");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #431");
        trace_rec_3();
      }


      strcpy(a_string, "         LARL  R9,C370WTOB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #423");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370L8");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #424");
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
        strcpy(trace_1, "c2z_print.c #425");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R15,WTOALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #426");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #427 ");
        trace_rec_3();
      }
 /*     p_ln_ct = 0; */
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
              strcpy(trace_1, "c2z_print.c #430");
              trace_rec_3();
            }

            strcpy(a_string, "         LARL  R8,C370WTOB");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_print.c #431");
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
              strcpy(trace_1, "c2z_print.c #432");
              trace_rec_3();
            }
            break;
          }
        }

        strcpy(a_string, "         LARL  R9,C370DEC");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #433");
          trace_rec_3();
        }
        work_use_ct[67]++;

        if (dec == 1) 
        {
          strcpy(a_string, "         LARL  R8,C370ONE");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #434");
            trace_rec_3();
          }
          work_use_ct[33]++;
        }

        if (dec == 2) 
        {
          strcpy(a_string, "         LARL  R8,C370TWO");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #435");
            trace_rec_3();
          }
          work_use_ct[34]++;
        }

        if (dec == 3) 
        {
          strcpy(a_string, "         LARL  R8,C370THR");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #436");
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
            strcpy(trace_1, "c2z_print.c #437");
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
            strcpy(trace_1, "c2z_print.c #438");
            trace_rec_3();
          }
          work_use_ct[24]++;
        }

        strcpy(a_string, "         ZAP   0(2,R9),0(2,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #439");
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
          strcpy(trace_1, "c2z_print.c #440");
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
          strcpy(trace_1, "c2z_print.c #441");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #442");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R15,WTOIMVC");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #443");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #444");
          trace_rec_3();
        }


        strcpy(a_string, "         LARL  R9,C370WTOB");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #445");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370L10");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #446");
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
          strcpy(trace_1, "c2z_print.c #447");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R15,WTOALPHA");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #448");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #449");
          trace_rec_3();
        }
    /*    p_ln_ct = 0; */
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
              strcpy(trace_1, "c2z_print.c #450");
              trace_rec_3();
            }

            strcpy(a_string, "         LARL  R8,C370WTOB");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_print.c #451");
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
              strcpy(trace_1, "c2z_print.c 452");
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
          strcpy(trace_1, "c2z_print.c #453");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #454");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVD   R9,0(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #455");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370TDW4");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #456");
          trace_rec_3();
        }
        work_use_ct[56]++;

        strcpy(a_string, "         LARL  R7,C370EDW4");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #457");
          trace_rec_3();
        }
	 work_use_ct[27]++;

        strcpy(a_string, "         MVC    0(4,R8),0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #458");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370TDW4");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #459");
          trace_rec_3();
        }
        work_use_ct[56]++;

        strcpy(a_string, "        ED     0(4,R8),4(R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #460");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370WTOB");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #461");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370TDW4");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #462");
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
          strcpy(trace_1, "c2z_print.c #463");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R15,WTOALPHA");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #464");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #465");
          trace_rec_3();
        }
  /*      p_ln_ct = 0; */
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
      strcpy(trace_1, "c2z_print.c #470");
      trace_rec_3();
    }
    work_use_ct[67]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #471");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #472");
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
          strcpy(trace_1, "c2z_print.c #473");
          trace_rec_3();
        }

        strcpy(field12, w_constant[x3].const_use);

        strcpy(a_string, "         LARL  R8,C370WTOB");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #474");
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
          strcpy(trace_1, "c2z_print.c #475");
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
      strcpy(trace_1, "c2z_print.c #476");
      trace_rec_3();
    }

    strcpy(a_string, "         L     R9,0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #477");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOFMVC");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #478");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #479");
      trace_rec_3();
    }


    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #480");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L10");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #481");
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
      strcpy(trace_1, "c2z_print.c #482");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #483");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #484");
      trace_rec_3();
    }
 /*   p_ln_ct = 0; */
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
  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
 
  int pi;
  int pi2;
  int x1;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int x9;
  int x15 = 0;
  int x90 = 0;
  int x95;
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
        strcpy(trace_1, "c2z_print.c #490");
        trace_rec_3();
      }
      work_use_ct[67]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #491");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #492");
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
            strcpy(trace_1, "c2z_print.c #493");
            trace_rec_3();
          }
          strcpy(field12, w_constant[x3].const_use);

          strcpy(a_string, "         LARL  R8,C370WTOB");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #494");
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

  /*        snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct); */
          strcpy(a_string, "         MVC   ");
   /*       strcat(a_string, wk_strg); */
          strcat(a_string,"0(");
          snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
          strcat(a_string, wk_strg);
          strcat(a_string, ",R8),0(R9)");
          strcpy(wk_remark, " printf   */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #495");
            trace_rec_3();
          }
    /*      p_ln_ct = p_ln_ct + x5; */
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
        strcpy(trace_1, "c2z_print.c #496");
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
        strcpy(trace_1, "c2z_print.c #497");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #498");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R15,WTOIMVC");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #499");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #500");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370WTOB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #501");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370L10");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #502");
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
        strcpy(trace_1, "c2z_print.c #503");
        trace_rec_3();
      }
 /*     p_ln_ct = p_ln_ct + 10; */

      if(p102 == 1)
      {
        strcpy(a_string, "         LARL  R15,WTOALPHA");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #504");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #505");
          trace_rec_3();
        }
   /*     p_ln_ct = 0; */
      }

      tot_wto++;
    }
  }

  if(prf6 == 1)
  {
      printf("c2z_print.c c2_printf_numeric structure\n");

    pi = 0;
    ch = p_string[pi];
    while (ch != '\"') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '\"') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    x4 = 0;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if(ch != ',')
      {
        field2[x4] = ch;
        x4++;
      }
      pi++;
      ch = p_string[pi];
    }
    field2[x4] = '\0';

printf("c2z_print.c print struct field2 = %s\n",field2);

    x3 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field2a, gw_variable[I].gv_cname);
        strcpy(ar_field5, gw_variable[I].gv_dsect);
        strcpy(ar_field6, gw_variable[I].gv_label);
        strcpy(ar_field7, gw_variable[I].gv_table);
        strcpy(ar_field8, gw_variable[I].gv_aname);
      }
    }

    pi++;
    x4 = 0;
    ch = p_string[pi];
    while (ch != ']') 
    {
      field3[x4] = ch;
      x4++;
      pi++;
      ch = p_string[pi];
    }
    field3[x4] = '\0';

    x3 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field3, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field3a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field3, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field3a, gw_variable[v].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_print.c c2_printf struct printf-021 field2 Not Found = %s\n",field3);
      printf("c2z_print.c c2_printf struct rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
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
      strcpy(trace_1, "c2z_print.c #510");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, w_constant[x3].const_use);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #511");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0");
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #512");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #513");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #514");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #515");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, ar_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #516");
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
      strcpy(trace_1, "c2z_print.c #517");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #518");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #519");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #520");
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
      strcpy(trace_1, "c2z_print.c #521");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #522");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #523");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #524");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #525");
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
      strcpy(trace_1, "c2z_print.c #526");
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
      strcpy(trace_1, "c2z_print.c #527");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370EDN");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #528");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #529");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOIMVC");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #530");
      trace_rec_3();
    }
 
    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #531");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #532");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L10");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #533");
      trace_rec_3();
    }
    work_use_ct[71]++;

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcat(a_string, wk_strg); 
    strcat(a_string, "(10,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #534");
      trace_rec_3();
    }


    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #535");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #536");
      trace_rec_3();
    }
 /*   p_ln_ct = 0; */

    convert = 1;
  }
}

