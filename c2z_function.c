/* ***************************************************
*  c2z : c2z_function.c                              *
*                                                    *
*  next error - function-007                         *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out B back from function                    *
* ************************************************** */
void c2_func_end() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_function.c c2_func_end");
    trace_rec_1();
  }

  int I = 0;
  int v1 = 0;
  int ret = 0;

  char tfield1a[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];

  if (fn_ct > 0) {
    for (I = 0; I < fn_ct; I++) 
    {
      ret = strcmp(sv_func, w_function[I].fn_name);
      if (ret == 0) 
      {
        strcpy(tfield5a, w_function[I].fn_loop);
      }
    }
  }

  for (v1 = 0; v1 < gv_ct; v1++) 
  {
    ret = strcmp("A", gw_variable[v1].gv_type);
    if (ret == 0) 
    {
      strcpy(ar_field6, gw_variable[v1].gv_label);
      strcpy(ar_field7, gw_variable[v1].gv_table);
      strcpy(ar_field8, gw_variable[v1].gv_aname);
      strcpy(ar_field9, gw_variable[v1].gv_sv_reg);
      strcpy(ar_field10, gw_variable[v1].gv_wk_reg);
      strcpy(ar_field11, gw_variable[v1].gv_wk_strg);
    }
  }

  if (return_on == 0) 
  {
    strcpy(a_string, "         PR");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #1");
      trace_rec_3();
    }
  }

  if ((return_on == 1) && (return_ct != 0)) 
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield5a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #2");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #3");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #4");
      trace_rec_3();
    }

    strcpy(a_string, "         JNE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #6");
      trace_rec_3();
    }

    strcpy(a_string, "         L     C370LNK,0(,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #7");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #8");
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
      strcpy(trace_1, "c2z_function.c #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield5a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370TWO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #11");
      trace_rec_3();
    }
    work_use_ct[34]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #12");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #13");
      trace_rec_3();
    }

    strcpy(a_string, "         L     C370LNK,0(,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #14");
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
      strcpy(trace_1, "c2z_function.c #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield5a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #16");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #17");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #18");
      trace_rec_3();
    }

    strcpy(a_string, "         BR    C370LNK");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #19");
      trace_rec_3();
    }
  }

  inside_void = 0;
  return_on = 0;
  return_ct = 0;
  convert = 1;
}

/* ***************************************************
*  Punch out function call                           *
* ************************************************** */
void c2_func_call() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_function.c c2_func_call START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];
  char field8[VAR_LGTH];
  char field8a[VAR_LGTH];

  int pi;
  int pi2;
  int comma_ct = 0;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int x100;
  int I = 0;
  int s = 0;
  int v = 0;
  int fd2_type = 0;
  int fd2a_type = 0;
  int fd4a_type = 0;
  int if_convert = 0;
  int wk_pass_1 = 0;
  int size = 0;

  int fd7_type = 0;
  int fd8_type = 0;
  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;

  char wk_sv_func[VAR_LGTH];
  char org_sv_func[VAR_LGTH];

  char *p, *p2, *p6;

  field1a[0] = '\0';

  s = 0;
  x4 = 0;
  x5 = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == ';') 
    {
      break;
    }
    if (ch == ',')
    {
      comma_ct++;
    }
    if (ch == ' ') 
    {
      x4++;
    }
    if (ch == '{') 
    {
      x5++;
    }
    if (ch == '}') 
    {
      x5++;
    }
  }

  s--;

  if ((x4 + x5) == s) 
  {
    return;
  }

  p = strstr(p_string, "else");
  if (p) 
  {
    return;
  }

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != '(') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

 strcpy(wk_sv_func, field1);

  x3 = 0;
  if (fn_ct > 0) 
  {
    for (I = 0; I < fn_ct; I++) 
    {
      ret = strcmp(field1, w_function[I].fn_name);
      if (ret == 0) 
      {
        strcpy(field1a, w_function[I].fn_cname);
        x3 = 1;
      }
    }
  }

  if (comma_ct == 1) 
  {
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
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

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != ' ') 
      {
        field3[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    if (fn_ct > 0) 
    {
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(field1, w_function[I].fn_name);
        if (ret == 0) 
        {
          strcpy(field1a, w_function[I].fn_cname);
          strcpy(field7, w_function[I].fn_fd1);
          strcpy(field8, w_function[I].fn_fd2);
        }
      }
    }

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
          gw_variable[v].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_function.c c2_func_call function-001 field2 Not Found = %s\n",field2);
      printf("c2z_function.c c2_func_call rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

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
          gw_variable[v].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_function.c c2_func_call function-002 field3 Not Found = %s\n",field3);
      printf("c2z_function.c c2_func_call rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    v = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field7, lw_variable[v].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field7a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        ret2 = strcmp("C", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd7_type = 1;
        } 
        else 
        {
          fd7_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field7, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field7a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
          ret2 = strcmp("C", gw_variable[v].gv_type);
          if (ret2 == 0) 
          {
            fd7_type = 1;
          } 
          else 
          {
            fd7_type = 2;
          }
        }
      }
    }

    x3 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field8, lw_variable[v].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field8a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        ret2 = strcmp("C", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd8_type = 1;
        } 
        else 
        {
          fd8_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field8, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field8a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
          ret2 = strcmp("C", gw_variable[v].gv_type);
          if (ret2 == 0) 
          {
            fd8_type = 1;
          } 
          else 
          {
            fd8_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_function.c c2_func_call function-003 field8 Not Found %s\n", field8);
      printf("c2z_function.c c2_func_call rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd7_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field7a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field7);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #20");
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
        strcpy(trace_1, "c2z_function.c #21");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC2  ");
      strcat(a_string, field7a);
      strcat(a_string, ",");
      strcat(a_string, field2a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #22");
        trace_rec_3();
      }
    }

    if (fd7_type == 2) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field7a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field7);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #23");
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
        strcpy(trace_1, "c2z_function.c #24");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #25");
        trace_rec_3();
      }
    }

    if (fd8_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field8a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field8);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #26");
        trace_rec_3();
      }
    
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #27");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC2   ");
      strcat(a_string, field8a);
      strcat(a_string, ",");
      strcat(a_string, field3a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #28");
        trace_rec_3();
      }
    }

    if (fd8_type == 2) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field8a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field8);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #29");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #30");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #31");
        trace_rec_3();
      }
    }
  } /* END OF if(comma_ct == 1)		*/

  if (comma_ct == 2) 
  {
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
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

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch != ' ') 
      {
        field3[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != ' ') 
      {
        field4[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field4[pi2] = '\0';

    convert = 1;
    return;
  }

  if ((comma_ct == 0) && (if_convert == 0)) 
  {
    if_convert = 0;
    p6 = strstr(p_string, "()");
    if (p6) 
    {
      if_convert = 1;
    }

    if (if_convert == 1) 
    {
      x3 = 0;
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(field1, w_function[I].fn_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field1a, w_function[I].fn_cname);
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_function.c c2_func_call comma_ct == 0 function-004 field1 Not Found field1 = %s\n",field1);
        printf("c2z_function.c c2_func_call rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R15,");
      strcat(a_string, field1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #32");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #33");
        trace_rec_3();
      }

      convert = 1;
      return;
    }

    if (if_convert == 0) 
    {
      strcpy(wk_sv_func, field1);
      pi2 = 0;
      x2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ';') 
      {
        if (ch != ' ') 
        {
          if (x2 == 0) 
          {
            if (isalpha(ch)) 
            {
              fd2_type = 1;
              x2 = 1;
            }
            if (isdigit(ch)) 
            {
              fd2_type = 1;
              x2 = 1;
            }
          }
          field2[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      field2[pi2] = '\0';

      if (field2[pi2 - 1] == ')') 
      {
        field2[pi2 - 1] = '\0';
      }

      s = strlen(field2);

      if (s != 0) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2_func_call ARGV ");
          trace_rec_1();
        }

        p2 = strstr(field2, "argv");
        if (!p2) 
        {
          if (fn_ct > 0) 
          {
            for (I = 0; I < fn_ct; I++) 
            {
              ret = strcmp(field1, w_function[I].fn_name);
              if (ret == 0) 
              {
                strcpy(field3, w_function[I].fn_fd1);
                wk_pass_1 = w_function[I].fn_pass_1;
              }
            }
          }

          x3 = 0;
          v = 0;
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(field3, lw_variable[v].lv_name);
            ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
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
                gw_variable[v].gv_use_ct++;
              }
            }
          }

          if (x3 == 0) 
          {
            c_name++;
            snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
            strcpy(field3a, "C37F");
            strcat(field3a, wk_strg);
            x4 = strlen(field3a);
            field3a[x4] = '\0';

            if (global_st == 0) 
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
              strcpy(gw_variable[gv_ct].gv_cname, field3a);
              strcpy(gw_variable[gv_ct].gv_name, field3);
              if (wk_pass_1 == 1) 
              {
                printf("\nc2_func_call function-005 wk_pass_1 NOT CODED\n");
                printf("c2_func_call rct = %d p_string = %s", rct, p_string);
                erct++;
                convert = 1;
                return;
              }

              if (wk_pass_1 == 2) 
              {
                strcpy(gw_variable[gv_ct].gv_type, "C");
                gw_variable[gv_ct].gv_id = 3;
              }
              gw_variable[gv_ct].gv_lgth = 0;
              gw_variable[gv_ct].gv_current_lgth = 0;
              strcpy(gw_variable[gv_ct].gv_value, null_field);
              gw_variable[gv_ct].gv_init = 0;
              strcpy(gw_variable[gv_ct].gv_literal, null_field);
              gw_variable[gv_ct].gv_use_ct = 0;
              gw_variable[gv_ct].gv_dec = 0;
              gv_ct++;
            }

            if (global_st == 1) 
            {
              printf("\nc2z_function.c c2_func_call comma = 0 function-006 NOT CODED\n");
              printf("c2z_function.c c2_func_call rct = %d p_string = %s", rct,p_string);
              erct++;
              convert = 1;
              return;
            }
          }
        }
      }

      s = strlen(field1);

      if (fd2_type == 0) 					/* special character	*/
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_function.c c2_func_call subroutine #10");
          trace_rec_1();
        }

        x2 = 0;
        for (I = 0; I < char_ct; I++) 
        {
          if ((w_charlit[I].clit_rct == rct) && (w_charlit[I].clit_uct == 1)) 
          {
            x2 = 1;
            strcpy(field2, w_charlit[I].clit_cname);
            x3 = w_charlit[I].clit_lgth;
          }
        }

        if (x2 == 0)
        {
          return;
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field3a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field3);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_function.c #34");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field2);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field2);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_function.c #35");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   0(");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
        strcat(a_string, wk_strg);
        strcat(a_string, ",R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_function.c #36");
          trace_rec_3();
        }

        x3 = 0;
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(field1, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field1a, w_function[I].fn_cname);
          }
        }

        if (x3 == 0) 
        {
          printf("c2z_function.c c2_func_call comma_ct == 0 function-007 field1 Not Found = %s\n",field1);
          printf("c2z_function.c c2_func_call rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }
      }

      if (fd2_type == 1) 
      {
        x100 = 0;
        x3 = 0;
        v = 0;
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field2, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(field2a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            x100 = lw_variable[v].lv_current_lgth;
            ret2 = strcmp("I", lw_variable[v].lv_type);
            if (ret2 == 0) 
            {
              fd2a_type = 1;
            } 
            else 
            {
              fd2a_type = 2;
            }
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
              gw_variable[v].gv_use_ct++;
              x100 = gw_variable[v].gv_current_lgth;
              ret2 = strcmp("I", gw_variable[v].gv_type);
              if (ret2 == 0) 
              {
                fd2a_type = 1;
              } 
              else 
              {
                fd2a_type = 2;
              }
            }
          }
        }

        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(wk_sv_func, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field4, w_function[I].fn_fd1);
          }
        }

        x3 = 0;
        v = 0;
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field4, lw_variable[v].lv_name);
          ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(field4a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            ret2 = strcmp("I", lw_variable[v].lv_type);
            if (ret2 == 0) 
            {
              fd4a_type = 1;
            } 
            else 
            {
              fd4a_type = 2;
            }
          }
        }

        if ((fd2a_type == 1) && (fd4a_type == 1)) 
        {
          strcpy(a_string, "         LARL  R9,");
          strcat(a_string, field4a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, field4);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_function.c #37");
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
            strcpy(trace_1, "c2z_function.c #38");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_function.c #39");
            trace_rec_3();
          }
        }

        if ((fd2a_type == 2) && (fd4a_type == 2)) 
        {
          strcpy(a_string, "         LARL  R9,");
          strcat(a_string, field4a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, field4);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_function.c #40");
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
            strcpy(trace_1, "c2z_function.c #41");
            trace_rec_3();
          }

          snprintf(wk_strg, sizeof(wk_strg), "%d", x100);
          strcpy(a_string, "         MVC   0(");
          strcat(a_string, wk_strg);
          strcat(a_string, ",R9),0(R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_function.c #42");
            trace_rec_3();
          }
        }

        strcpy(a_string, "         LARL  R15,");
        strcat(a_string, field1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_function.c #43");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_function.c #44");
          trace_rec_3();
        }
      }

      if (fd2_type == 2) 
      {
        printf("\nc2_func_call comma = 0 fd2_type = 2 function-008 NOT FINISHED\n");
        printf("c2_func_call rct = %d p_string = %s\n",rct,p_string);
        erct++;
      }

      if_convert = 1;
      convert = 1;
      return;
    }
  }

  strcpy(org_sv_func, sv_func);

  s = strlen(field1a);
  if (s != 0) 
  {
      strcpy(a_string, "         LARL  R15,");
      strcat(a_string, field1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #45");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_function.c #46");
        trace_rec_3();
      }
  }

  strcpy(sv_func, org_sv_func);
  convert = 1;
}

/* ***************************************************
*  Punch out function user subroutine                *
* ************************************************** */
void c2_func_sub() 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_function.c c2_func_sub rct = %d L3 START\n", rct);
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_function.c func_sub START");
    trace_rec_1();
  }

  /* pgm_label(); */

  int comma_ct = 0;
  int I = 0;
  int s = 0;
  int pi;
  int pi2;
  int ret = 0;
  int no_variables = 0;
  int x80 = 0;

  char ch;
  char *p, *p1;
  char field2[VAR_LGTH];
  char ar_field4a[VAR_LGTH];
  char field2a[VAR_LGTH];

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    if (ch == ';') 
    {
      break;
    }
    ch = p_string[I];
    if (ch == ',')
      comma_ct++;
  }

  pi = 0;
  pi2 = 0;
  ch = p_string[pi];

  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  ch = p_string[pi];
  while (ch != ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != '(') 
  {
    if (ch != ' ') 
    {
      if (ch != '*') 
      {
        if(ch != ' ')
        {
          field2[pi2] = ch;
          pi2++;
        }
      }
    }
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  strcpy(sv_func, field2);

  ret = strcmp(field2, "main");
  if (ret == 0) 
  {
    strcpy(field2a, field2);
    inside_main = 1;
  }

  x80 = 0;
  if ((fn_ct > 0) && (ret != 0)) 
  {
    for (I = 0; I < fn_ct; I++) 
    {
      ret = strcmp(field2, w_function[I].fn_name);
      if (ret == 0) 
      {
        strcpy(field2a, w_function[I].fn_cname);
        strcpy(ar_field4a, w_function[I].fn_loop);
        strcpy(sv_func, field2);
        x80 = 1;
      }
    }
  }

  if(x80 == 1)
  {
    strcpy(a_string, field2a);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_function.c #47");
      trace_rec_3();
    }
  }

  if (x80 == 1) 
  {
    p = strstr(p_string, "()");
    if (p) 
    {
      no_variables = 1;
    }

    if (no_variables == 0) 					/* variables passed	*/
    {
      p1 = strstr(p_string, ",");
      if (p1) 
      {
        comma_ct = 1;
      }

      if (comma_ct == 0) 					/* at lease one variable	*/
      {
        pi++;
        ch = p_string[pi];
        while (ch != ' ') 
        {
          pi++;
          ch = p_string[pi];
        }

        pi++;
        ch = p_string[pi];
        while (ch != ')') 
        {
          pi++;
          ch = p_string[pi];
        }
      }
    }

    strcpy(ret_fn, sub_name);

    inside_fn = 1;
    inside_void = 2;
  }

  convert = 1;
}

/* ***************************************************
*  Scan function user subroutine                     *
* ************************************************** */
void c2_scan_func() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_function.c scan_func START");
    trace_rec_1();
  }

  int comma_ct = 0;
  int I = 0;
  int s = 0;
  int ret = 0;
  int pi;
  int pi2;
  inside_void = 2;

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  field1[0] = '\0';
  field2[0] = '\0';

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == ',')
    {
      comma_ct++;
    }
  }

  pi = 0;
  pi2 = 0;
  ch = p_string[pi];

  while (ch != ' ') 
  {
    if (ch != '_') 
    {
      field1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  if (pi2 >= 0) 				/* no blanks before key word function */
  {
    ret = strcmp(field1, "void");
    if (ret == 0) 
    {
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      while (ch != '(') 
      {
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field2[pi2] = '\0';
    }

    if (fn_ct > 0) 
    {
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(field2, w_function[I].fn_name);
        if (ret == 0) 
        {
          w_function[I].fn_start = rct;
        }
      }
    }

    ret = strcmp(field1, "int");
    if (ret == 0) {
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      while (ch != '(') 
      {
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field2[pi2] = '\0';
    }

    if (fn_ct > 0) 
    {
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(field2, w_function[I].fn_name);
        if (ret == 0) 
        {
          w_function[I].fn_start = rct;
        }
      }
    }
    strcpy(sv_func, field2);
  }
}


void c2_scan_sub() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_function.c c2_scan_sub START");
  }

  int pi;
  int pi2;
  int scn_1 = 0;
  int scn_2 = 0;
  int s = 0;
  int I = 0;
  int size = 0;
  int x10 = 0;
  int x4 = 0;
  int x5 = 0;
  int x7 = 0;
  int v = 0;

  char ch;
  char *p;
  char field1[VAR_LGTH];
  char tfield1[VAR_LGTH];
  char tfield2[VAR_LGTH];

  p = strstr(p_string, "/*");
  v = p_string - p;
  if (v < 0) 
  {
    v = 9999;
  }

  scn_1 = 0;

  if (scn_1 == 0) 
  {
    p = strstr(p_string, "default");
    if (p) 
    {
      scn_1 = 1;
    }
  }

  if (scn_1 == 0) 
  {
    p = strstr(p_string, "void");
    if (p) 
    {
      scn_1 = 1;
    }
  }

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == ';') 
    {
      break;
    }
    if (ch == '=') 
    {
      scn_1 = 1;
    }
  }

  p = strstr(p_string, "'='");
  if (p) 
  {
    scn_1 = 0;
  }

  p = strstr(p_string, "'");
  if (p) 
  {
    x10 = 1;
  }

  if (scn_1 == 0) 
  {
    s = strlen(p_string);
    s--;
    for (I = 0; I < s; I++) 
    {
      ch = p_string[I];
      if ((ch != ' ') || (ch != '\t') || (ch != '\n') || (ch != '\r') || (ch != '{') || (ch != '}')) 
      {
        scn_2 = 1;
      }
    }
  }

  s = 0;
  x4 = 0;
  x5 = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == ' ') 
    {
      x4++;
    }
    if (ch == '{') 
    {
      x5++;
      x7 = I;
    }
    if (ch == '}') 
    {
      x5++;
    }
  }

  s--;
  if ((x4 + x5) == s) 
  {
    return;
  }

  if ((x4 == 0) && (x5 == 1) && (s = x7 + x5)) 
  {
    convert = 1;
    return;
  }

  if ((x4 == 0) && (x5 == 0) && (s < 8)) 
  {
    return;
  }

  p = strstr(p_string, "else");
  if ((scn_1 == 0) && (scn_2 != 0)) 
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != '(') 
    {
      if ((ch != '\t') || (ch != '\n') || (ch != '\0') || (ch != '{') || (ch != '{') || (ch != ' ')) 
      {
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    s = strlen(field1);

    if (pi2 > 2) 			/* load function_start table 	*/
    {
      if (fns_ct == 0) 
      {
        size = 1;
        w_func_start = malloc(size * sizeof(struct func_start));
      } 
      else 
      {
        size = fns_ct + 1;
        w_func_start = realloc(w_func_start, size * sizeof(struct func_start));
      }

      w_func_start[fns_ct].fns_rct = rct;
      strcpy(w_func_start[fns_ct].fns_name, field1);
      fns_ct++;
    }

    if (x10 == 1) 
    {
      pi = 0;
      pi2 = 0;
      ch = p_string[pi];
      while (ch != '\'') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi++;
      ch = p_string[pi];
      while (ch != ';') 
      {
        if (ch != '\'') 
        {
          tfield2[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      pi2--;
      tfield2[pi2] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(tfield1, c_wkname);

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
      strcpy(w_charlit[char_ct].clit_cname, tfield1);
      strcpy(w_charlit[char_ct].clit_value, tfield2);
      w_charlit[char_ct].clit_lgth = 1;
      w_charlit[char_ct].clit_uct = 1;
      char_ct++;
    }
  }
  convert = 1;
}

void scan_func_name_1() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_function.c scan_func_name_1 START");
  }

   int size = 0;
   int pi;
   int pi2;
   int x1;
   int x4;
   int ret = 0;

  char ch;
  char *p, *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;

  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5a[VAR_LGTH];

  pi = 0;
  pi2 = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch != ' ') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  x1 = 0;
  ret = strcmp(field1, "char");
  if (ret == 0) 
  {
    x1 = 1;
  }

  ret = strcmp(field1, "int");
  if (ret == 0) 
  {
    x1 = 2;
  }

  ret = strcmp(field1, "void");
  if (ret == 0) 
  {
    x1 = 3;
  }

  ret = strcmp(field1, "double");
  if (ret == 0) 
  {
    x1 = 4;
  }

  ret = strcmp(field1, "long");
  if (ret == 0) 
  {
    x1 = 5;
  }

  convert = 0;
  field1[0] = '\0';

  p1 = strstr(p_string, ";");
  p2 = strchr(p_string, '(');
  p3 = strchr(p_string, ')');
  p7 = strstr(p_string, "(void)");

  if ((x1 == 4) && (p1) && (p2) && (p3)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_function.c scan_func_name_1 double");
      trace_rec_1();
    }

    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      if (ch != ' ') 
      {
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field1a, "C37F");
    strcat(field1a, wk_strg);
    x4 = strlen(field1a);
    field1a[x4] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field1a, "C37F");
    strcat(field1a, wk_strg);
    x4 = strlen(field1a);
    field1a[x4] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field4a, "C37F");
    strcat(field4a, wk_strg);
    x4 = strlen(field4a);
    field4a[x4] = '\0';

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
    strcpy(gw_variable[gv_ct].gv_cname, field4a);
    strcpy(gw_variable[gv_ct].gv_name, field4a);
    strcpy(gw_variable[gv_ct].gv_type, "F");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_id = 2;
    gv_ct++;

    if (fn_ct == 0) 
    {
      size = 1;
      w_function = malloc(size * sizeof(struct functions));
    } 
    else 
    {
      size = fn_ct + 1;
      w_function = realloc(w_function, size * sizeof(struct functions));
    }

    w_function[fn_ct].fn_rct = rct;
    strcpy(w_function[fn_ct].fn_name, field1);
    strcpy(w_function[fn_ct].fn_cname, field1a);
    strcpy(w_function[fn_ct].fn_loop, field4a);
    w_function[fn_ct].fn_level = 0;
    w_function[fn_ct].fn_return = 0;
    w_function[fn_ct].fn_start = 0;
    strcpy(w_function[fn_ct].fn_fd1, null_field);
    strcpy(w_function[fn_ct].fn_fd2, null_field);
    strcpy(w_function[fn_ct].fn_fd3, null_field);
    strcpy(w_function[fn_ct].fn_fd4, null_field);
    strcpy(w_function[fn_ct].fn_fd5, null_field);
    strcpy(w_function[fn_ct].fn_fd6, null_field);
    strcpy(w_function[fn_ct].fn_fd7, null_field);
    strcpy(w_function[fn_ct].fn_fd8, null_field);
    strcpy(w_function[fn_ct].fn_fd9, null_field);
    strcpy(w_function[fn_ct].fn_loop_use, null_field);
    w_function[fn_ct].fn_eof = 0;
    w_function[fn_ct].fn_pass_1 = 0;
    w_function[fn_ct].fn_pass_2 = 0;
    w_function[fn_ct].fn_pass_3 = 0;
    w_function[fn_ct].fn_pass_4 = 0;
    w_function[fn_ct].fn_pass_5 = 0;
    w_function[fn_ct].fn_pass_6 = 0;
    w_function[fn_ct].fn_pass_7 = 0;
    w_function[fn_ct].fn_pass_8 = 0;
    w_function[fn_ct].fn_pass_9 = 0;
    fn_ct++;

    convert = 1;
    return;
  }

  p1 = strstr(p_string, ";");
  p2 = strchr(p_string, '(');
  p3 = strchr(p_string, ')');
  p7 = strstr(p_string, "(void)");

  if ((x1 == 3) && (p1) && (p2) && (p3)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_function.c scan_func_name_1 VOID");
      trace_rec_1();
    }

    pi2 = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != '(') 
    {
      if (ch != ' ') 
      {
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field1a, "C37F");
    strcat(field1a, wk_strg);
    x4 = strlen(field1a);
    field1a[x4] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field4a, "C37F");
    strcat(field4a, wk_strg);
    x4 = strlen(field4a);
    field4a[x4] = '\0';

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
    strcpy(gw_variable[gv_ct].gv_cname, field4a);
    strcpy(gw_variable[gv_ct].gv_name, field4a);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_id = 2;
    gv_ct++;

    if (fn_ct == 0) 
    {
      size = 1;
      w_function = malloc(size * sizeof(struct functions));
    } 
    else 
    {
      size = fn_ct + 1;
      w_function = realloc(w_function, size * sizeof(struct functions));
    }

    w_function[fn_ct].fn_rct = rct;
    strcpy(w_function[fn_ct].fn_name, field1);
    strcpy(w_function[fn_ct].fn_cname, field1a);
    strcpy(w_function[fn_ct].fn_loop, field4a);
    w_function[fn_ct].fn_level = 0;
    w_function[fn_ct].fn_return = 0;
    w_function[fn_ct].fn_start = 0;
    strcpy(w_function[fn_ct].fn_fd1, null_field);
    strcpy(w_function[fn_ct].fn_fd2, null_field);
    strcpy(w_function[fn_ct].fn_fd3, null_field);
    strcpy(w_function[fn_ct].fn_fd4, null_field);
    strcpy(w_function[fn_ct].fn_fd5, null_field);
    strcpy(w_function[fn_ct].fn_fd6, null_field);
    strcpy(w_function[fn_ct].fn_fd7, null_field);
    strcpy(w_function[fn_ct].fn_fd8, null_field);
    strcpy(w_function[fn_ct].fn_fd9, null_field);
    strcpy(w_function[fn_ct].fn_loop_use, null_field);
    w_function[fn_ct].fn_eof = 0;
    w_function[fn_ct].fn_pass_1 = 0;
    w_function[fn_ct].fn_pass_2 = 0;
    w_function[fn_ct].fn_pass_3 = 0;
    w_function[fn_ct].fn_pass_4 = 0;
    w_function[fn_ct].fn_pass_5 = 0;
    w_function[fn_ct].fn_pass_6 = 0;
    w_function[fn_ct].fn_pass_7 = 0;
    w_function[fn_ct].fn_pass_8 = 0;
    w_function[fn_ct].fn_pass_9 = 0;
    fn_ct++;

    convert = 1;
    return;
  }

  p = strstr(p_string, "void");
  p1 = strstr(p_string, ";");
  p2 = strchr(p_string, '(');
  p3 = strchr(p_string, ')');
  p4 = strstr(p_string, "int");
  p5 = strstr(p_string, "print");
  p6 = strstr(p_string, "char");
  p7 = strstr(p_string, "(void)");
  if (!p7) 
  {
    p7 = strstr(p_string, "(double)");
  }

  if ((p7) && (p2) && (p3) && (p6)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_function.c #80 scan_func_name_1 CHAR - VOID");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != '(') 
    {
      if (ch != '*') 
      {
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    c_name++; /* function compiler name	*/
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field1a, "C37F");
    strcat(field1a, wk_strg);
    x4 = strlen(field1a);
    field1a[x4] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field4a, "C37F");
    strcat(field4a, wk_strg);
    x4 = strlen(field4a);
    field4a[x4] = '\0';

    if (fn_ct == 0) 
    {
      size = 1;
      w_function = malloc(size * sizeof(struct functions));
    } 
    else 
    {
      size = fn_ct + 1;
      w_function = realloc(w_function, size * sizeof(struct functions));
    }

    w_function[fn_ct].fn_rct = rct;
    strcpy(w_function[fn_ct].fn_name, field1);
    strcpy(w_function[fn_ct].fn_cname, field1a);
    strcpy(w_function[fn_ct].fn_loop, field4a);
    w_function[fn_ct].fn_level = 0;
    w_function[fn_ct].fn_return = 0;
    w_function[fn_ct].fn_start = 0;
    strcpy(w_function[fn_ct].fn_fd1, null_field);
    strcpy(w_function[fn_ct].fn_fd2, null_field);
    strcpy(w_function[fn_ct].fn_fd3, null_field);
    strcpy(w_function[fn_ct].fn_fd4, null_field);
    strcpy(w_function[fn_ct].fn_fd5, null_field);
    strcpy(w_function[fn_ct].fn_fd6, null_field);
    strcpy(w_function[fn_ct].fn_fd7, null_field);
    strcpy(w_function[fn_ct].fn_fd8, null_field);
    strcpy(w_function[fn_ct].fn_fd9, null_field);
    strcpy(w_function[fn_ct].fn_loop_use, field5a);
    w_function[fn_ct].fn_eof = 0;
    w_function[fn_ct].fn_pass_1 = 0;
    w_function[fn_ct].fn_pass_2 = 0;
    w_function[fn_ct].fn_pass_3 = 0;
    w_function[fn_ct].fn_pass_4 = 0;
    w_function[fn_ct].fn_pass_5 = 0;
    w_function[fn_ct].fn_pass_6 = 0;
    w_function[fn_ct].fn_pass_7 = 0;
    w_function[fn_ct].fn_pass_8 = 0;
    w_function[fn_ct].fn_pass_9 = 0;

    p8 = strstr(p_string, "(int");
    if (p8) 
    {
      w_function[fn_ct].fn_pass_1 = 1;
    }

    p8 = strstr(p_string, "int)");
    if (p8) 
    {
      w_function[fn_ct].fn_pass_2 = 1;
    }

    p8 = strstr(p_string, "(char");
    if (p8) 
    {
      w_function[fn_ct].fn_pass_1 = 2;
    }
    fn_ct++;

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
    strcpy(gw_variable[gv_ct].gv_cname, field4a);
    strcpy(gw_variable[gv_ct].gv_name, field4a);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_id = 1;
    gv_ct++;

    convert = 1;
    return;
  }

  p = strstr(p_string, "void");
  p1 = strstr(p_string, ";");
  p2 = strchr(p_string, '(');
  p3 = strchr(p_string, ')');
  p4 = strstr(p_string, "int");
  p5 = strstr(p_string, "print");
  p6 = strstr(p_string, "char");
  p7 = strstr(p_string, "(void)");
  p8 = strstr(p_string, "(*");

  /* int eval_string(char *lstr,char *rstr,int op) */

  if ((p) && (p1) && (p8)) 				/* void (*init_fn)();  */
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ')') 
    {
      if (ch != '(') 
      {
        if (ch != '*') 
        {
          field1[pi2] = ch;
          pi2++;
        }
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field1a, "C37F");
    strcat(field1a, wk_strg);
    x4 = strlen(field1a);
    field1a[x4] = '\0';

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
    strcpy(gw_variable[gv_ct].gv_cname, field1a);
    strcpy(gw_variable[gv_ct].gv_name, field1);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_id = 1;
    gv_ct++;

    convert = 1;
    return;
  }

  p = strstr(p_string, "void");
  p1 = strstr(p_string, ";");
  p2 = strchr(p_string, '(');
  p3 = strchr(p_string, ')');
  p4 = strstr(p_string, "int");
  p5 = strstr(p_string, "print");
  p6 = strstr(p_string, "char");
  p7 = strstr(p_string, "(void)");
  p8 = strstr(p_string, "(*");

  if ((p) && (p1) && (!p8) && (!p7)) 			/* void a_bort(int, int);		*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_function.c #82 scan_func_name_1 VOID 2 - int");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != '(') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    c_name++; 
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field1a, "C37F");
    strcat(field1a, wk_strg);
    x4 = strlen(field1a);
    field1a[x4] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field4a, "C37F");
    strcat(field4a, wk_strg);
    x4 = strlen(field4a);
    field4a[x4] = '\0';

    if (fn_ct == 0) 
    {
      size = 1;
      w_function = malloc(size * sizeof(struct functions));
    } 
    else 
    {
      size = fn_ct + 1;
      w_function = realloc(w_function, size * sizeof(struct functions));
    }

    w_function[fn_ct].fn_rct = rct;
    strcpy(w_function[fn_ct].fn_name, field1);
    strcpy(w_function[fn_ct].fn_cname, field1a);
    strcpy(w_function[fn_ct].fn_loop, field4a);
    w_function[fn_ct].fn_level = 0;
    w_function[fn_ct].fn_return = 0;
    w_function[fn_ct].fn_start = 0;
    strcpy(w_function[fn_ct].fn_fd1, null_field);
    strcpy(w_function[fn_ct].fn_fd2, null_field);
    strcpy(w_function[fn_ct].fn_fd3, null_field);
    strcpy(w_function[fn_ct].fn_fd4, null_field);
    strcpy(w_function[fn_ct].fn_fd5, null_field);
    strcpy(w_function[fn_ct].fn_fd6, null_field);
    strcpy(w_function[fn_ct].fn_fd7, null_field);
    strcpy(w_function[fn_ct].fn_fd8, null_field);
    strcpy(w_function[fn_ct].fn_fd9, null_field);
    strcpy(w_function[fn_ct].fn_loop_use, field5a);
    w_function[fn_ct].fn_eof = 0;
    w_function[fn_ct].fn_pass_1 = 0;
    w_function[fn_ct].fn_pass_2 = 0;
    w_function[fn_ct].fn_pass_3 = 0;
    w_function[fn_ct].fn_pass_4 = 0;
    w_function[fn_ct].fn_pass_5 = 0;
    w_function[fn_ct].fn_pass_6 = 0;
    w_function[fn_ct].fn_pass_7 = 0;
    w_function[fn_ct].fn_pass_8 = 0;
    w_function[fn_ct].fn_pass_9 = 0;

    p8 = strstr(p_string, "(int");
    if (p8) 
    {
      w_function[fn_ct].fn_pass_1 = 1;
    }

    p8 = strstr(p_string, "int)");
    if (p8) 
    {
      w_function[fn_ct].fn_pass_2 = 1;
    }

    p8 = strstr(p_string, "(char");
    if (p8) 
    {
      w_function[fn_ct].fn_pass_1 = 2;
    }
    fn_ct++;

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
    strcpy(gw_variable[gv_ct].gv_cname, field4a);
    strcpy(gw_variable[gv_ct].gv_name, field4a);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_id = 1;
    gv_ct++;

    convert = 1;
    return;
  }

  p = strstr(p_string, "void");
  p1 = strstr(p_string, ";");
  p2 = strchr(p_string, '(');
  p3 = strchr(p_string, ')');
  p4 = strstr(p_string, "int");
  p5 = strstr(p_string, "print");

  if ((p4) && (p2) && (p3) && (p1) && (!p5) && (convert == 0)) 	/* INT procedure INT get_upper(int, int);		*/
  {

    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_function.c #83 scan_func_name_1 INT 2 - int");
      trace_rec_1();
    }
   
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != '(') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    c_name++; 
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field1a, "C37F");
    strcat(field1a, wk_strg);
    x4 = strlen(field1a);
    field1a[x4] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field4a, "C37F");
    strcat(field4a, wk_strg);
    x4 = strlen(field4a);
    field4a[x4] = '\0';

    if (fn_ct == 0) 
    {
      size = 1;
      w_function = malloc(size * sizeof(struct functions));
    } 
    else 
    {
      size = fn_ct + 1;
      w_function = realloc(w_function, size * sizeof(struct functions));
    }

    w_function[fn_ct].fn_rct = rct;
    strcpy(w_function[fn_ct].fn_name, field1);
    strcpy(w_function[fn_ct].fn_cname, field1a);
    strcpy(w_function[fn_ct].fn_loop, field4a);
    w_function[fn_ct].fn_level = 0;
    w_function[fn_ct].fn_return = 0;
    w_function[fn_ct].fn_start = 0;
    strcpy(w_function[fn_ct].fn_fd1, null_field);
    strcpy(w_function[fn_ct].fn_fd2, null_field);
    strcpy(w_function[fn_ct].fn_fd3, null_field);
    strcpy(w_function[fn_ct].fn_fd4, null_field);
    strcpy(w_function[fn_ct].fn_fd5, null_field);
    strcpy(w_function[fn_ct].fn_fd6, null_field);
    strcpy(w_function[fn_ct].fn_fd7, null_field);
    strcpy(w_function[fn_ct].fn_fd8, null_field);
    strcpy(w_function[fn_ct].fn_fd9, null_field);
    strcpy(w_function[fn_ct].fn_loop_use, field5a);
    w_function[fn_ct].fn_eof = 0;
    w_function[fn_ct].fn_pass_1 = 0;
    w_function[fn_ct].fn_pass_2 = 0;
    w_function[fn_ct].fn_pass_3 = 0;
    w_function[fn_ct].fn_pass_4 = 0;
    w_function[fn_ct].fn_pass_5 = 0;
    w_function[fn_ct].fn_pass_6 = 0;
    w_function[fn_ct].fn_pass_7 = 0;
    w_function[fn_ct].fn_pass_8 = 0;
    w_function[fn_ct].fn_pass_9 = 0;

    p8 = strstr(p_string, "(int");
    if (p8) 
    {
      w_function[fn_ct].fn_pass_1 = 1;
    }

    p8 = strstr(p_string, "int)");
    if (p8) 
    {
      w_function[fn_ct].fn_pass_2 = 1;
    }

    p8 = strstr(p_string, "(char");
    if (p8) 
    {
      w_function[fn_ct].fn_pass_1 = 2;
    }
    fn_ct++;

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
    strcpy(gw_variable[gv_ct].gv_cname, field4a);
    strcpy(gw_variable[gv_ct].gv_name, field4a);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_id = 1;
    gv_ct++;

    convert = 1;
    return;
  }

  p = strstr(p_string, "void");
  p1 = strstr(p_string, ";");
  p2 = strchr(p_string, '(');
  p3 = strchr(p_string, ')');
  p4 = strstr(p_string, "int");
  p5 = strstr(p_string, "print");

  if ((p4) && (p2) && (p3) && (!p1) && (!p5) && (convert == 0)) 		/* INT procedure INT get_upper(int, int);	*/
  {
printf("c2z_function.c HERE #10 rct = %d p_string = %s",rct,p_string);
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_1.c #84 scan_func_name_1 INT #100");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != '(') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    c_name++; /* function compiler name	*/
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field1a, "C37F");
    strcat(field1a, wk_strg);
    x4 = strlen(field1a);
    field1a[x4] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field4a, "C37F");
    strcat(field4a, wk_strg);
    x4 = strlen(field4a);
    field4a[x4] = '\0';

    if (fn_ct == 0) 
    {
      size = 1;
      w_function = malloc(size * sizeof(struct functions));
    } 
    else 
    {
      size = fn_ct + 1;
      w_function = realloc(w_function, size * sizeof(struct functions));
    }

    w_function[fn_ct].fn_rct = rct;
    strcpy(w_function[fn_ct].fn_name, field1);
    strcpy(w_function[fn_ct].fn_cname, field1a);
    strcpy(w_function[fn_ct].fn_loop, field4a);
    w_function[fn_ct].fn_level = 0;
    w_function[fn_ct].fn_return = 0;
    w_function[fn_ct].fn_start = 0;
    strcpy(w_function[fn_ct].fn_fd1, null_field);
    strcpy(w_function[fn_ct].fn_fd2, null_field);
    strcpy(w_function[fn_ct].fn_fd3, null_field);
    strcpy(w_function[fn_ct].fn_fd4, null_field);
    strcpy(w_function[fn_ct].fn_fd5, null_field);
    strcpy(w_function[fn_ct].fn_fd6, null_field);
    strcpy(w_function[fn_ct].fn_fd7, null_field);
    strcpy(w_function[fn_ct].fn_fd8, null_field);
    strcpy(w_function[fn_ct].fn_fd9, null_field);
    strcpy(w_function[fn_ct].fn_loop_use, field5a);
    w_function[fn_ct].fn_eof = 0;
    w_function[fn_ct].fn_pass_1 = 0;
    w_function[fn_ct].fn_pass_2 = 0;
    w_function[fn_ct].fn_pass_3 = 0;
    w_function[fn_ct].fn_pass_4 = 0;
    w_function[fn_ct].fn_pass_5 = 0;
    w_function[fn_ct].fn_pass_6 = 0;
    w_function[fn_ct].fn_pass_7 = 0;
    w_function[fn_ct].fn_pass_8 = 0;
    w_function[fn_ct].fn_pass_9 = 0;

    p8 = strstr(p_string, "(int");
    if (p8) 
    {
      w_function[fn_ct].fn_pass_1 = 1;
    }

    p8 = strstr(p_string, "int)");
    if (p8) 
    {
      w_function[fn_ct].fn_pass_2 = 1;
    }

    p8 = strstr(p_string, "(char");
    if (p8) 
    {
      w_function[fn_ct].fn_pass_1 = 2;
    }

    fn_ct++;

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
    strcpy(gw_variable[gv_ct].gv_cname, field4a);
    strcpy(gw_variable[gv_ct].gv_name, field4a);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_id = 1;
    gv_ct++;

    convert = 1;
    return;
  }

  p = strstr(p_string, "void");
  p1 = strstr(p_string, ";");
  p2 = strchr(p_string, '(');
  p3 = strchr(p_string, ')');
  p4 = strstr(p_string, "int");
  p5 = strstr(p_string, "print");
  p6 = strstr(p_string, "char");
  p7 = strstr(p_string, "(void)");

  if ((p6) && (p2) && (p3) && (convert == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_function.c #85 scan_func_name_1 CHAR");
      trace_rec_1();
    }

    char ch;
    char *p, *p1;
    char field1[VAR_LGTH];
    char field2[VAR_LGTH];
    char field3[VAR_LGTH];
    char field3a[VAR_LGTH];
    char field4[VAR_LGTH];

    int pi;
    int pi2 = 0;
    int I = 0;
    int x3 = 0;
    int x4 = 0;
    int x5 = 0;
    int x6 = 0;
    int x7 = 0;
    int ret = 0;
    int ret1 = 0;
    int fd2_type = 0;
    int no_parameters = 0;
    int comma_ct = 0;
    int size = 0;
    int tot_comma = 0;
    int s = 0;

    p = strstr(p_string, "()");
    if (p) 
    {
      no_parameters = 1;
    }

    s = strlen(p_string);
    for (I = 0; I < s; I++) 
    {
      ch = p_string[I];
      if (ch == ',') 
      {
        tot_comma++;
      }
    }

    p1 = strstr(p_string, ",");
    if (p1) 
    {
      comma_ct = 1;
    } 
    else 
    {
      comma_ct = 0;
    }

    if (no_parameters == 1) 		/* no passed parameters	*/
    {
      pi = 0;
      ch = p_string[pi];
      while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != '(') 
      {
        if (ch != '*') 
        {
          field1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';

      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(field1, w_function[I].fn_name);
        if (ret == 0) 
        {
          w_function[I].fn_start = rct;
        }
      }

      strcpy(sv_func, field1);
      convert = 1;
    }

    if ((no_parameters == 0) && (comma_ct == 0)) 		/* one variable passed	*/
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_function.c #86 scan_func_name_1 p6 p2 p3 (1) var");
        trace_rec_1();
      }

      pi = 0;
      ch = p_string[pi];
      while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != '(') 
      {
        if (ch != '*') 
        {
          field1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';
      strcpy(sv_func, field1);

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field2[pi2] = '\0';

      p = strstr(field2, ";");
      if (p) 
      {
        convert = 1;
        return;
      }
      /*
               ret = strcmp("char", field2);
               if(ret == 0)
               {
                  fd2_type = 1;
               }
               else
               {
                  fd2_type = 2;
               }

               pi2 = 0;
               ch = p_string[pi];
               while(ch != ')')
               {
                  if(ch != ' ')
                  {
                     if(ch != '*')
                     {
                        field3[pi2] = ch;
                        pi2++;
                     }
                  }
                  pi++;
                  ch = p_string[pi];
               }
               field3[pi2] = '\0';
               s = strlen(field3);

      printf("c2z_function.c p2 p6 rct = %d #1 field3 = %s\n",rct, field3);
      */

      c_name++; /* function compiler name	*/
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(field1a, "C37F");
      strcat(field1a, wk_strg);
      x4 = strlen(field1a);
      field1a[x4] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(field4a, "C37F");
      strcat(field4a, wk_strg);
      x4 = strlen(field4a);
      field4a[x4] = '\0';

      if (fn_ct == 0) 
      {
        size = 1;
        w_function = malloc(size * sizeof(struct functions));
      } 
      else 
      {
        size = fn_ct + 1;
        w_function = realloc(w_function, size * sizeof(struct functions));
      }

      w_function[fn_ct].fn_rct = rct;
      strcpy(w_function[fn_ct].fn_name, field1);
      strcpy(w_function[fn_ct].fn_cname, field1a);
      strcpy(w_function[fn_ct].fn_loop, field4a);
      strcpy(w_function[fn_ct].fn_ret_var, null_field);
      w_function[fn_ct].fn_level = 0;
      w_function[fn_ct].fn_return = 0;
      w_function[fn_ct].fn_start = 0;
      strcpy(w_function[fn_ct].fn_fd1, null_field);
      strcpy(w_function[fn_ct].fn_fd2, null_field);
      strcpy(w_function[fn_ct].fn_fd3, null_field);
      strcpy(w_function[fn_ct].fn_fd4, null_field);
      strcpy(w_function[fn_ct].fn_fd5, null_field);
      strcpy(w_function[fn_ct].fn_fd6, null_field);
      strcpy(w_function[fn_ct].fn_fd7, null_field);
      strcpy(w_function[fn_ct].fn_fd8, null_field);
      strcpy(w_function[fn_ct].fn_fd9, null_field);
      strcpy(w_function[fn_ct].fn_loop_use, field5a);
      w_function[fn_ct].fn_eof = 0;
      w_function[fn_ct].fn_pass_1 = 0;
      w_function[fn_ct].fn_pass_2 = 0;
      w_function[fn_ct].fn_pass_3 = 0;
      w_function[fn_ct].fn_pass_4 = 0;
      w_function[fn_ct].fn_pass_5 = 0;
      w_function[fn_ct].fn_pass_6 = 0;
      w_function[fn_ct].fn_pass_7 = 0;
      w_function[fn_ct].fn_pass_8 = 0;
      w_function[fn_ct].fn_pass_9 = 0;
      fn_ct++;

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
      strcpy(gw_variable[gv_ct].gv_cname, field4a);
      strcpy(gw_variable[gv_ct].gv_name, field4a);
      strcpy(gw_variable[gv_ct].gv_type, "I");
      gw_variable[gv_ct].gv_lgth = 0;
      gw_variable[gv_ct].gv_current_lgth = 0;
      strcpy(gw_variable[gv_ct].gv_value, null_field);
      gw_variable[gv_ct].gv_init = 0;
      strcpy(gw_variable[gv_ct].gv_literal, null_field);
      gw_variable[gv_ct].gv_use_ct = 0;
      gw_variable[gv_ct].gv_dec = 0;
      gw_variable[gv_ct].gv_id = 1;
      gv_ct++;

      p1 = strstr(field3, "[");
      if (p1) 
      {
        x5 = 1;
      }

      if (x5 == 1) 
      {
        pi = 0;
        pi2 = 0;
        ch = field3[pi];
        while (ch != '[') 
        {
          if (ch != '*') 
          {
            field3a[pi2] = ch;
            pi2++;
          }
          pi++;
          ch = field3[pi];
        }
        field3a[pi2] = '\0';

        pi2 = 0;
        pi++;
        ch = field3[pi];
        while (ch != ']') 
        {
          field4[pi2] = ch;
          pi2++;
          pi++;
          ch = field3[pi];
        }
        field4[pi2] = '\0';
        strcpy(field3, field3a);
      }

      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(field1, w_function[I].fn_name);
        if (ret == 0) 
        {
          w_function[I].fn_start = rct;
          strcpy(w_function[I].fn_fd1, field3);
        }
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
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
          }
        }
      }

      if (x3 == 0) 
      {
        if (x5 == 1) 
        {
          x6 = 0;
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(field4, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x6 = 1;
              x7 = lw_variable[I].lv_lgth;
            }
          }

          if (x6 == 0) 
          {
            for (I = 0; I < gv_ct; I++) 
            {
              ret = strcmp(field4, gw_variable[I].gv_name);
              if (ret == 0) 
              {
                x6 = 1;
                x7 = gw_variable[I].gv_lgth;
              }
            }
          }
        }

        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        x4 = strlen(c_wkname);
        c_wkname[x4] = '\0';
        strcpy(field3a, c_wkname);

        if (global_st == 0) 
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
          strcpy(gw_variable[gv_ct].gv_cname, field3a);
          strcpy(gw_variable[gv_ct].gv_name, field3);
          if (fd2_type == 1) 
          {
            strcpy(gw_variable[gv_ct].gv_type, "C");
            if (x5 == 1) 
            {
              gw_variable[gv_ct].gv_lgth = x7;
              gw_variable[gv_ct].gv_current_lgth = x7;
            } 
            else 
            {
              gw_variable[gv_ct].gv_lgth = 1;
              gw_variable[gv_ct].gv_current_lgth = 0;
            }

            strcpy(gw_variable[gv_ct].gv_value, null_field);
            gw_variable[gv_ct].gv_init = 0;
            strcpy(gw_variable[gv_ct].gv_literal, null_field);
            gw_variable[gv_ct].gv_use_ct = 0;
            strcpy(gw_variable[gv_ct].gv_dsect, null_field);
            gw_variable[gv_ct].gv_row = 0;
            gw_variable[gv_ct].gv_column = 0;
            strcpy(gw_variable[gv_ct].gv_dsect, null_field);
            strcpy(gw_variable[gv_ct].gv_label, null_field);
            strcpy(gw_variable[gv_ct].gv_aname, null_field);
            strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
            strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
            strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
            gw_variable[gv_ct].gv_dec = 0;
            gw_variable[gv_ct].gv_id = 3;
            gv_ct++;
          }

          if (fd2_type == 2) 
          {
            strcpy(gw_variable[gv_ct].gv_type, "I");
            gw_variable[gv_ct].gv_lgth = 0;
            gw_variable[gv_ct].gv_current_lgth = 0;
            strcpy(gw_variable[gv_ct].gv_value, "0");
            gw_variable[gv_ct].gv_init = 0;
            strcpy(gw_variable[gv_ct].gv_literal, null_field);
            gw_variable[gv_ct].gv_use_ct = 0;
            strcpy(gw_variable[gv_ct].gv_dsect, null_field);
            gw_variable[gv_ct].gv_row = 0;
            gw_variable[gv_ct].gv_column = 0;
            strcpy(gw_variable[gv_ct].gv_dsect, null_field);
            strcpy(gw_variable[gv_ct].gv_label, null_field);
            strcpy(gw_variable[gv_ct].gv_aname, null_field);
            strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
            strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
            strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
            gw_variable[gv_ct].gv_dec = 0;
            gw_variable[gv_ct].gv_id = 1;
            gv_ct++;
          }
        }

        if (global_st == 1) 
        {
          if (lv_ct == 0) 
          {
            size = 1;
            lw_variable = malloc(size * sizeof(struct var));
          } 
          else 
          {
            size = lv_ct + 1;
            lw_variable = realloc(lw_variable, size * sizeof(struct var));
          }

          lw_variable[lv_ct].lv_rct = rct;
          strcpy(lw_variable[lv_ct].lv_cname, field3a);
          strcpy(lw_variable[lv_ct].lv_name, field3);
          if (fd2_type == 1) 
          {
            strcpy(lw_variable[lv_ct].lv_type, "C");
            if (x5 == 1) 
            {
              lw_variable[lv_ct].lv_lgth = x7;
              lw_variable[lv_ct].lv_current_lgth = x7;
            } 
            else 
            {
              lw_variable[lv_ct].lv_lgth = 1;
              lw_variable[lv_ct].lv_current_lgth = 0;
            }

            strcpy(lw_variable[lv_ct].lv_value, null_field);
            lw_variable[lv_ct].lv_init = 0;
            strcpy(lw_variable[lv_ct].lv_literal, null_field);
            strcpy(lw_variable[lv_ct].lv_func, sv_func);
            lw_variable[lv_ct].lv_use_ct = 0;
            lw_variable[lv_ct].lv_dec = 0;
            lw_variable[lv_ct].lv_id = 3;
            lv_ct++;
          }

          if (fd2_type == 2) 
          {
            strcpy(lw_variable[lv_ct].lv_type, "I");
            lw_variable[lv_ct].lv_lgth = 0;
            strcpy(lw_variable[lv_ct].lv_value, "0");
            lw_variable[lv_ct].lv_current_lgth = 0;
            lw_variable[lv_ct].lv_init = 0;
            strcpy(lw_variable[lv_ct].lv_literal, null_field);
            strcpy(lw_variable[lv_ct].lv_func, sv_func);
            lw_variable[lv_ct].lv_use_ct = 0;
            lw_variable[lv_ct].lv_dec = 0;
            lw_variable[lv_ct].lv_id = 1;
            lv_ct++;
          }
        }
      }
    }

    convert = 1;
  }

  if ((x1 == 5) && (p1) && (p2) && (p3)) 			/*   long function  	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_function.c scan_func_name_1 #79");
      trace_rec_1();
    }

    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      if (ch != ' ') 
      {
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field1a, "C37F");
    strcat(field1a, wk_strg);
    x4 = strlen(field1a);
    field1a[x4] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field4a, "C37F");
    strcat(field4a, wk_strg);
    x4 = strlen(field4a);
    field4a[x4] = '\0';

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
    strcpy(gw_variable[gv_ct].gv_cname, field4a);
    strcpy(gw_variable[gv_ct].gv_name, field4a);
    strcpy(gw_variable[gv_ct].gv_type, "F");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_id = 2;
    gv_ct++;

    if (fn_ct == 0) 
    {
      size = 1;
      w_function = malloc(size * sizeof(struct functions));
    } 
    else 
    {
      size = fn_ct + 1;
      w_function = realloc(w_function, size * sizeof(struct functions));
    }

    w_function[fn_ct].fn_rct = rct;
    strcpy(w_function[fn_ct].fn_name, field1);
    strcpy(w_function[fn_ct].fn_cname, field1a);
    strcpy(w_function[fn_ct].fn_loop, field4a);
    strcpy(w_function[fn_ct].fn_ret_var, null_field);
    w_function[fn_ct].fn_level = 0;
    w_function[fn_ct].fn_return = 0;
    w_function[fn_ct].fn_start = 0;
    strcpy(w_function[fn_ct].fn_fd1, null_field);
    strcpy(w_function[fn_ct].fn_fd2, null_field);
    strcpy(w_function[fn_ct].fn_fd3, null_field);
    strcpy(w_function[fn_ct].fn_fd4, null_field);
    strcpy(w_function[fn_ct].fn_fd5, null_field);
    strcpy(w_function[fn_ct].fn_fd6, null_field);
    strcpy(w_function[fn_ct].fn_fd7, null_field);
    strcpy(w_function[fn_ct].fn_fd8, null_field);
    strcpy(w_function[fn_ct].fn_fd9, null_field);
    strcpy(w_function[fn_ct].fn_loop_use, null_field);
    w_function[fn_ct].fn_eof = 0;
    w_function[fn_ct].fn_pass_1 = 0;
    w_function[fn_ct].fn_pass_2 = 0;
    w_function[fn_ct].fn_pass_3 = 0;
    w_function[fn_ct].fn_pass_4 = 0;
    w_function[fn_ct].fn_pass_5 = 0;
    w_function[fn_ct].fn_pass_6 = 0;
    w_function[fn_ct].fn_pass_7 = 0;
    w_function[fn_ct].fn_pass_8 = 0;
    w_function[fn_ct].fn_pass_9 = 0;
    fn_ct++;

    convert = 1;
    return;
  }
}
