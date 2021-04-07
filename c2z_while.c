/* ***************************************************
*  c2z : c2z_while.c :                               *
*                                                    *
*  next error while-187                              *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out WHILE statement                         *
* ************************************************** */
void c2_while(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while START");
    trace_rec_1();
  }

  pgm_label();

  char ch;
  char *p;
  char tfield1[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int s = 0;
  int x3 = 0;
  int x5 = 0;
  int ret = 0;
  int while_test = 0;

  while_convert = 0;
  while_opr = 0;
  while_parser_code = 0;
  inside_while = 1;

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '&') 
    {
      x5++;
    }
  }

  p = strstr(p_string, "strcmp");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 13;
    while_test = 1;
  }

  p = strstr(p_string, "strchr");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 20;
    while_test = 1;
    c2_while_20();
    convert = 1;
    return;
  }

  p = strstr(p_string, "isalnum");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 12;
    while_test = 1;
  }

  p = strstr(p_string, "isspace");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 11;
    while_test = 1;
  }

  p = strstr(p_string, "isupper");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 10;
    while_test = 1;
  }

  p = strstr(p_string, "feof");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 9;
    while_test = 1;
  }

  p = strstr(p_string, "isalpha");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 8;
    while_test = 1;
  }

  p = strstr(p_string, "isdigit");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 7;
    while_test = 1;
  }

  p = strstr(p_string, "&&");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 98;
    while_test = 1;
  }

  p = strstr(p_string, "||");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 98;
    while_test = 1;
  }

  p = strstr(p_string, "<=");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 6;
    while_test = 1;
  }

  p = strstr(p_string, ">=");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 5;
    while_test = 1;
  }

  p = strstr(p_string, "<");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 4;
    while_test = 1;
  }

  p = strstr(p_string, ">");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 3;
    while_test = 1;
  }

  p = strstr(p_string, "!=");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 1;
    while_test = 1;
  }

  p = strstr(p_string, "==");
  if ((p) && (while_test == 0)) 
  {
    while_opr = 99;
    while_test = 1;
  }

  if ((while_opr == 99) && (while_convert == 0)) 	/* while((ch == 1) */
  {
    c2_while_1();
    return;
  }

  if ((while_opr == 1) && (while_convert == 0)) 		/* while((ch != '\"') 	*/
  {
    c2_while_2();
    return;
  }

  if ((while_opr == 3) && (while_convert == 0)) 		/* > */
  {
    printf("c2z_while.c c2_while E-202 while_opr == 3 Not Coded\n");
    return;
  }

  if ((while_opr == 4) && (while_convert == 0)) 		/* <	 */
  {
    c2_while_4();
    return;
  }

  if ((while_opr == 5) && (while_convert == 0) && (while_opr != 98)) /* >=	 */
  {
    c2_while_5();
    return;
  }

  if ((while_opr == 6) && (while_convert == 0)) 		/* <=	 */
  {
    printf("\nc2z_while.c c2_while while-001 while_opr == 6 Not Coded\n");
    printf("c2z_while.c c2_while rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if ((while_opr == 7) && (while_convert == 0)) 		/* isdigit	*/
  {
    c2_while_7();
    return;
  }

  if ((while_opr == 8) && (while_convert == 0)) 		/* isalpha	*/
  {
    c2_while_8();
    return;
  }

  if ((while_opr == 9) && (while_convert == 0)) /* feof 	*/
  {
    c2_while_9();
    return;
  }

  if ((while_opr == 10) && (while_convert == 0)) /* isupper	*/
  {
    c2_while_10();
    return;
  }

  if ((while_opr == 11) && (while_convert == 0)) /* isspace	*/
  {
    c2_while_11();
    return;
  }

  if ((while_opr == 12) && (while_convert == 0)) /* isalnum	*/
  {
    c2_while_12();
    return;
  }

  if ((while_opr == 13) && (while_convert == 0)) /* strcmp	*/
  {
    c2_while_13();
    return;
  }

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
  while (ch != '(') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < fn_ct; I++) 
  {
    ret = strcmp(tfield1, w_function[I].fn_name);
    if (ret == 0) 
    {
      x3 = 1;
    }
  }

  if (x3 == 1) 
  {
    c2_while_14();
    return;
  }

  if ((while_opr == 98) && (x5 != 4)) 
  {
    c2_while_15();
    return;
  }

  if ((while_opr == 98) && (x5 == 4)) 
  {
    c2_while_16();
    return;
  }
}

void c2_while_1() 					/* == */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_1 START");
    trace_rec_1();
  }

  int fd1_type = 0;
  int fd3_type = 0;
  int pi;
  int pi2;
  int s = 0;
  int x2 = 0;
  int x3 = 0;
  int x10 = 0;
  int x11 = 0;
  int x12 = 0;
  int x13 = 0;
  int x14 = 0;
  int x16 = 0;
  int x20 = 0;
  int x80 = 0;
  int x90 = 0;
  int v = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
 
  char ch, *p, *p1;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield11[VAR_LGTH];
  char tfield11a[VAR_LGTH];
  char wk_sv_func[VAR_LGTH];

  s = strlen(p_string);
  s--;
  s--;

  p = strstr(p_string, "/*");
  v = p - p_string;

  if (v < 0) 
  {
    v = s;
  }

  v = s;

  x20 = 0;
  pi = 0;
  ch = p_string[pi];
  for (I = 0; I < v; I++) 
  {
    if (ch == '[') 
    {
      x10 = I;
    }

    if (ch == ']') 
    {
      x11 = I;
    }

    if (ch == '=') 
    {
      x12 = I;
    }

    if (ch == '(') 
    {
      x13 = I;
      x20++;
    }

    if (ch == ')') 
    {
      x14 = I;
      x20++;
    }

    pi++;
    ch = p_string[pi];
  }

  x16 = 0;
  p1 = strstr(p_string, "==");
  if (p1) 
  {
    x16 = 1;
  }


  if ((x16 == 1) && (x20 == 4) && (x13 > 0) && (x14 > 0)) 
  {
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
    while (ch != '(') 
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
    while (ch != ')') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
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

    x2 = 0;
    pi2 = 0;
    while (ch != ')') 
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

        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
     
    x3 = 0;
    fd1_type = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[v].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd1_type = 1;
          }
          ret2 = strcmp("C", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd1_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[v].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd1_type = 1;
            }
            ret2 = strcmp("C", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd1_type = 2;
            }
          }
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(tfield1, w_function[I].fn_name);
        if (ret == 0) 
        {
          strcpy(tfield1a, w_function[I].fn_cname);
          strcpy(tfield11, w_function[I].fn_ret_var);
          strcpy(wk_sv_func, tfield1);
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_while.c c2_while_1 while-002 x20 = 4 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_while.c c2_while_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield2, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield2a, lw_variable[v].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_while.c c2_while_1 while-003 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_while.c c2_while_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield2, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield2a, gw_variable[v].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_while.c c2_while_1 while-004 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_while.c c2_while_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(tfield5, tfield2);
    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield5, lw_variable[v].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield5a, lw_variable[v].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_while.c c2_while_1 while-005 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_while.c c2_while_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield5, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield5a, gw_variable[v].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_while.c c2_while_1 while-006 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_while.c c2_while_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while-2 */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #100");
      trace_rec_3();
    }
    strcpy(sv_while, wk_strg);

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #101");
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
      strcpy(trace_1, "c2z_while.c c2_while_1 #101");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #102");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #103");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #103A");
      trace_rec_3();
    }

    /* tfield11 compare to tfield2 */

    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield11, lw_variable[v].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield11a, lw_variable[v].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield11, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield11a, gw_variable[v].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[v].gv_type);
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_while.c c2_while_1 while-007 tfield11 Not Found = %s\n",tfield11);
      printf("c2z_while.c c2_while_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield11a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield11);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #104");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #105");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #106");
      trace_rec_3();
    }

    strcpy(a_string, "         JNE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #107");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  if ((x16 == 1) && (x20 == 2) && (x13 > 0) && (x14 > 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 subroutine #10");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    fd1_type = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          fd1_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          fd1_type = 2;
          x2 = 1;
        }
      }
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    x2 = 0;
    fd3_type = 0;
    pi2 = 0;
    while (ch != ')') 
    {
      if (ch != ' ') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            fd3_type = 1;
            x2 = 1;
          }

          if (isalpha(ch)) 
          {
            fd3_type = 2;
            x2 = 1;
          }
        }
        tfield3[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    x3 = 0;
    fd1_type = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[v].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[v].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_while.c c2_while_1 while-008 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_while.c c2_while_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if(fd3_type == 2)
    {
      x3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield3, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(tfield3a, lw_variable[v].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(tfield3, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
              strcpy(tfield3a, gw_variable[v].gv_cname);
              gw_variable[I].gv_use_ct++;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_while.c c2_while_1 while-009 tfield3 Not Found = %s\n", tfield3);
        printf("c2z_while.c c2_while_1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    x90 = 0;
    p = strstr(tfield3, "'");
    if(p)
    {
      x90 = 1;
    } 
   
    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while-1 */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #800");
      trace_rec_3();
    }
    strcpy(sv_while, wk_strg);

    if(x90 == 0)
    {
      x80 = 0;
      ret = strcmp("0",tfield3);
      if(ret == 0)
      {
        strcpy(tfield3a, "C370ZERO");
        x80 = 1;
      }

      if(x80 == 0)
      {
        ret = strcmp("1",tfield3);
        if(ret == 0)
        {
          strcpy(tfield3a, "C370ONE");
          x80 = 1;
        }
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #801");
      trace_rec_3();
    }

    if(x90 == 1)
    {
      for (I = 0; I < char_ct; I++) 
      {
        ret = w_charlit[I].clit_rct;
        if (rct == ret) 
        {
          strcpy(tfield3a, w_charlit[I].clit_cname);
        }
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #802");
      trace_rec_3();
    }

    if(x90 == 1)
    {
      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #803");
        trace_rec_3();
      }

      strcpy(a_string, "         JLNE  L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      check_length();
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #804");
        trace_rec_3();
      }
    }
    convert = 1;
    return;
  }

  if ((x10 == 0) && (x11 == 0) && (x13 < x12) && (x20 == 0)) 		/* while(ch == ' ')  */
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    s = 0;
    pi2 = 0;
    while (ch != ')') 
    {
      if (s == 0) 
      {
        if (isdigit(ch)) 
        {
          s = 3;
        }

        if (isalpha(ch)) 
        {
          s = 4;
        }
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while-1 */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #400");
      trace_rec_3();
    }
    strcpy(sv_while, wk_strg);

    x3 = 0;
    fd1_type = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[v].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[v].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_while.c c2_while_1 while-010 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_while.c c2_while_1 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_while.c c2_while_1 #401");
      trace_rec_3();
    }

    p = strstr(tfield3, "'");
    if(p)
    {
      s = 1;
    }

    if(s == 1)
    {
      strcpy(tfield3a, "C370B1");
      work_use_ct[52]++;
    }

    p = strstr(tfield3, "0");
    if(p)
    {
      s = 2;
    }

    if(s == 2)
    {
      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #402");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #403");
        trace_rec_3();
      }
    }

    if(s == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #404");
        trace_rec_3();
      }

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #405");
        trace_rec_3();
      }
    }

    if(s == 3)
    {
      strcpy(a_string, "         LA    R5,");
      strcat(a_string, tfield3);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #406");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #407");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #408");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #409");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #410");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #411");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #412");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_1 #413");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         JLNE  L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    check_length();
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #414");
      trace_rec_3();
    }
    convert = 1;
    return;
  }

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
  while (ch != ' ') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
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

  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (x2 == 0) 
    {
      if (isdigit(ch)) 
      {
        fd3_type = 1;
        x2 = 1;
      }

      if (isalpha(ch)) 
      {
        fd3_type = 2;
        x2 = 1;
      }
    }
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[v].lv_cname);
        lw_variable[I].lv_use_ct++;
        ret2 = strcmp("I", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd1_type = 1;
        }
        ret2 = strcmp("C", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd1_type = 2;
        }
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(tfield1, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[v].gv_cname);
          gw_variable[I].gv_use_ct++;
          ret2 = strcmp("I", gw_variable[v].gv_type);
          if (ret2 == 0) 
          {
            fd1_type = 1;
          }
          ret2 = strcmp("C", gw_variable[v].gv_type);
          if (ret2 == 0) 
          {
            fd1_type = 2;
          }
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_while.c c2_while_1 while-011 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_while.c c2_while_1 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (fd3_type == 2) 
  {
    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield3, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield3a, lw_variable[v].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd3_type = 1;
          }
          ret2 = strcmp("C", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd3_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield3, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield3a, gw_variable[v].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd3_type = 1;
            }
            ret2 = strcmp("C", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd3_type = 2;
            }
          }
        }
      }
    }

    if (x3 == 0) 
     {
      printf("\nc2z_while.c while_case_1 while-012 tfield3 Not Found = %s\n",tfield3);
      printf("c2z_while.c c2_while_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  check_length();
  strcat(a_string, "DS    0H");
  strcpy(wk_remark, " while-2 */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_1 #1");
    trace_rec_3();
  }
  strcpy(sv_while, wk_strg);

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield1a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_1 #2");
    trace_rec_3();
  }

  if (fd3_type == 1) 
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield3);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #7");
      trace_rec_3();
    }
  }

  if (fd3_type == 2) 
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #8");
      trace_rec_3();
    }
  }

  if ((fd1_type == 1) && (fd3_type == 1)) 
  {
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #9");
      trace_rec_3();
    }
  }

  if ((fd1_type == 2) && (fd3_type == 2)) 
  {
    strcpy(a_string, "         CLC   0(R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_1 #10");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         JNE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_1 #11");
    trace_rec_3();
  }

  while_convert = 1;
  convert = 1;
  return;
}


void c2_while_2() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_2 START");
    trace_rec_1();
  }

  char ch;
  char *p, *p1;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int x2 = 0;
  int wh_3 = 0;
  int wh_4 = 0;
  int wh_5 = 0;
  int wh_8 = 0;
  int wh_9 = 0;
  int wh_10 = 0;
  int v = 0;
  int x20 = 0;
  int ret = 0;
  int ret1 = 0;
  int operand_1 = 0;
  int operand_2 = 0;
  int var_ci_1 = 0;
  int var_ci_3 = 0;
  int var_ci_err1 = 0;
  int whfd3_type = 0;
  int whfd5_type = 0;
  int while_complex = 0;
  int cd3_type = 0;

  p = strstr(p_string, "&&");
  if (p) 
  {
    while_complex = 1;
  }

  p = strstr(p_string, "||");
  if (p) 
  {
    while_complex = 1;
  }

  if (while_complex == 0) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_2 simple");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
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
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield1a, lw_variable[v].lv_cname);
          lw_variable[I].lv_use_ct++;
          wh_5 = strcmp("I", lw_variable[v].lv_type);
          if (wh_5 == 0) 
          {
            var_ci_1 = 1;
          }
          wh_5 = strcmp("C", lw_variable[v].lv_type);
          if (wh_5 == 0) 
          {
            var_ci_1 = 2;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield1, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield1a, gw_variable[v].gv_cname);
            gw_variable[I].gv_use_ct++;
            wh_5 = strcmp("I", gw_variable[v].gv_type);
            if (wh_5 == 0) 
            {
              var_ci_1 = 1;
            }
            wh_5 = strcmp("C", gw_variable[v].gv_type);
            if (wh_5 == 0) 
            {
              var_ci_1 = 2;
            }
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_2 while-013 simple tfield1 Not Found = %s\n",tfield1);
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    x2 = 0;
    cd3_type = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch == '\'')
      {
        cd3_type = 3;
      }

      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          whfd3_type = 1;
          cd3_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          whfd3_type = 2;
          cd3_type = 2;
          x2 = 1;
        }
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    if (whfd3_type == 1)
    {
      var_ci_3 = 3;
    }

    if ((whfd3_type == 1) && (var_ci_3 == 3) && (cd3_type == 3)) 
    {
      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      check_length();
      strcat(a_string, "DS    0H");
      strcpy(wk_remark, " while-2 */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #250");
        trace_rec_3();
      }
      strcpy(sv_while, wk_strg);

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #251");
        trace_rec_3();
      }

     p = strstr(tfield3, "\0");

     if(p)
     {
       strcpy(a_string, "         LARL  R8,C370EOF");
       src_line();
       if (puncde == 1) 
       {
          strcpy(trace_1, "c2z_while.c c2_while_2 #252a");
          trace_rec_3();
       }
       work_use_ct[74]++;
     }

     if((whfd3_type == 1) && (!p))
     {
       for (I = 0; I < char_ct; I++) 
       {
         if (rct == w_charlit[I].clit_rct) 
         {
           strcpy(a_string, "         LARL  R8,");
           strcat(a_string, w_charlit[I].clit_cname);
           src_line();
           if (puncde == 1) 
           {
             strcpy(trace_1, "c2z_while.c c2_while_2 #252c");
             trace_rec_3();
           }
         }
       }
     }

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      var_ci_err1 = 1;
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #253");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      check_length();
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #254");
        trace_rec_3();
      }
      convert = 1;
      return;
    }

    if ((whfd3_type == 1) && (var_ci_3 == 3) && (cd3_type != 3)) 
    {
      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      check_length();
      strcat(a_string, "DS    0H");
      strcpy(wk_remark, " while-2 */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #50");
        trace_rec_3();
      }
      strcpy(sv_while, wk_strg);

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #51");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield3);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #52");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #53");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #54");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #55");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #56");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #57");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 #58");
        trace_rec_3();
      }

 
      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "!=");
        if (p)
        {
          operand_1 = 2;
        }
      }

      if (operand_1 == 2) 
      {
        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        check_length();
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_2 #94");
          trace_rec_3();
        }
      }
      convert = 1;
      return;
    }

    p = strstr(tfield3, "\'");
    if (p)
    {
      wh_10 = 1;
    }

    wh_8 = 0;
    p = strstr(tfield3, "\"");
    if (p)
    {
      wh_8 = 1;
    }

    p = strstr(tfield3, "'\0'");
    if (p)
    {
      wh_9 = 1;
    }

    wh_3 = 0;
    if ((wh_8 != 1) && (lv_ct > 0) && (whfd3_type != 1) && (wh_10 != 1)) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield3, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield3a, lw_variable[v].lv_cname);
          lw_variable[I].lv_use_ct++;
          wh_5 = strcmp("I", lw_variable[v].lv_type);
          if (wh_5 == 0) 
          {
            var_ci_3 = 1;
          }
          wh_5 = strcmp("C", lw_variable[v].lv_type);
          if (wh_5 == 0) 
          {
            var_ci_3 = 2;
          }
        }
      }
    }

    if ((wh_3 == 0) && (wh_8 != 1) && (whfd3_type != 1)) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield3, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield3a, gw_variable[v].gv_cname);
            gw_variable[I].gv_use_ct++;
            wh_5 = strcmp("I", gw_variable[v].gv_type);
            if (wh_5 == 0) 
            {
              var_ci_3 = 1;
            }
            wh_5 = strcmp("C", gw_variable[v].gv_type);
            if (wh_5 == 0) 
            {
              var_ci_3 = 2;
            }
          }
        }
      }
    }

    if ((wh_3 == 0) && (wh_8 != 1) && (whfd3_type != 1) && (wh_10 != 1)) 
    {
      printf("\nc2z_while.c while_case_2 while-014 complex = 0 tfield3 Not Found = %s\n",tfield3);
      printf("c2z_while.c c2_while_case_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(tfield2, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield2, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield2, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield2, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield2, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield2, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield2, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    var_ci_err1 = 0;

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while-2 */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_2 simple #1");
      trace_rec_3();
    }
    strcpy(sv_while, wk_strg);

    if (wh_8 == 1) 
    {
      var_ci_err1 = 1;
    }

    x20 = 0;
    if (wh_9 == 1) 				/* end of line `	*/
    {
      if (whfd3_type != 0) 
      {
        p1 = strstr(p_string, "'\0'");
        if (p1) 
        {
          x20 = 1;
        }
      }

      if (x20 == 0) 
      {
        for (I = 0; I < char_ct; I++) 
        {
          if (rct == w_charlit[I].clit_rct) 
          {
            strcpy(a_string, "         LARL  R9,");
            strcat(a_string, w_charlit[I].clit_cname);
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2_while_2 simple = 0 #4");
              trace_rec_3();
            }
          }
        }
      }

      if (x20 == 1) 
      {
        strcpy(a_string, "         LARL  R9,C370EOF");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_2 simple #5");
          trace_rec_3();
        }
        work_use_ct[74]++;
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 simple #6");
        trace_rec_3();
      }

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 simple #7");
        trace_rec_3();
      }

      var_ci_err1 = 1;
    }

    if ((var_ci_1 == 2) && (var_ci_3 == 2)) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 simple #9");
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
        strcpy(trace_1, "c2z_while.c c2_while_2 simple #9");
        trace_rec_3();
      }

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 simple #8");
        trace_rec_3();
      }
    }

    if ((var_ci_1 == 1) && (var_ci_3 == 3)) 
    {
      if (whfd3_type == 1) 
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield1);
        strcat(wk_remark, " */");
        write_remark();
        var_ci_err1 = 1;
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_2 simple #9");
          trace_rec_3();
        }

        if (cd3_type != 1) 
        {
          strcpy(a_string, "         LARL  R8,C370ZERO");
          src_line();
          var_ci_err1 = 1;
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_2 simple #10");
            trace_rec_3();
          }
          work_use_ct[32]++;
        }

        if (cd3_type == 1) 
        {

          strcpy(a_string, "          LA    R5,");
          strcat(a_string, tfield3);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_2 simple #11");
            trace_rec_3();
          }

          strcpy(a_string, "          LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_2 simple #11");
            trace_rec_3();
          }

          strcpy(a_string, "          CVD   R5,0(R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_2 simple #11");
            trace_rec_3();
          }

          strcpy(a_string, "          LARL  R8,C370NWK2");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_2 simple #11");
            trace_rec_3();
          }

          strcpy(a_string, "          LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_2 simple #11");
            trace_rec_3();
          }

          strcpy(a_string, "          ZAP   0(6,R8),0(8,R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_2 simple #11");
            trace_rec_3();
          }
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        var_ci_err1 = 1;
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_2 simple #12");
          trace_rec_3();
        }
      }
      else 
      {
        printf("\nc2z_while.c c2_while_2 while-015 simple ci_1 = 1 & ci_3 = 1 NOT CODED\n");
        printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if (operand_1 == 1) 				/* ==	*/
    {
      printf("\nc2z_while.c c2_while_2 while-016 complex = 0operand_1 == Error#1\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 2) 				/* !=	*/
    {
      strcpy(a_string, "        JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      check_length();
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 simple #13");
        trace_rec_3();
      }
    }

    if (operand_1 == 3) 				/* <=	*/
    {
      printf("\nc2z_while.c c2_while_2 while-017 complex = 0 operand_1 <= Error#3\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 4) 				/* >=	*/
    {
      printf("\nc2z_while.c c2_while_2 while-018 complex = 0 operand_1 >= Error#4\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 5)				 /* =	*/
    {
      printf("\nc2z_while.c c2_while_2 while-019 complex = 0 operand_1 = Error#5\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 6) 				/* <	*/
    {
      printf("\nc2z_while.c c2_while_2 while-020 complex = 0 operand_1 < Error#6\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 7) 				/* >	*/
    {
      printf("\nc2z_while.c c2_while_2 while-021 complex = 0 operand_1 > Error#7\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    convert = 1;
    return;
  }

  if (while_complex == 1) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_2 complex = 1");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
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
    while (ch != ' ') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    c2_white();

    pi2 = 0;
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

    pi++;
    ch = p_string[pi];
    c2_white();

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          whfd5_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          whfd5_type = 2;
          x2 = 1;
        }
      }
      tfield5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield5[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    c2_white();

    pi2 = 0;
    while (ch != ' ') 
    {
      tfield6[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield6[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    c2_white();

    pi2 = 0;
    while (ch != ')') 
    {
      tfield7[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield7[pi2] = '\0';

    wh_3 = 0;
    wh_5 = 0;
    var_ci_1 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield1a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          wh_5 = strcmp("I", lw_variable[v].lv_type);
          if (wh_5 == 0) 
          {
            var_ci_1 = 1;
          }
          wh_5 = strcmp("C", lw_variable[v].lv_type);
          if (wh_5 == 0) 
          {
            var_ci_1 = 2;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield1, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield1a, gw_variable[v].gv_cname);
            wh_5 = strcmp("I", gw_variable[v].gv_type);
            if (wh_5 == 0) 
            {
              var_ci_1 = 1;
            }
            wh_5 = strcmp("C", gw_variable[v].gv_type);
            if (wh_5 == 0) 
            {
              var_ci_1 = 2;
            }
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c while_case_2 while-022 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield3, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield3a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          wh_5 = strcmp("I", lw_variable[v].lv_type);
          if (wh_5 == 0) 
          {
            var_ci_3 = 1;
          }
          wh_5 = strcmp("C", lw_variable[v].lv_type);
          if (wh_5 == 0) 
          {
            var_ci_3 = 2;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield3, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield3a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            wh_5 = strcmp("I", gw_variable[v].gv_type);
            if (wh_5 == 0) 
            {
              var_ci_3 = 1;
            }
            wh_5 = strcmp("C", gw_variable[v].gv_type);
            if (wh_5 == 0) 
            {
              var_ci_3 = 2;
            }
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c while_case_2 while-023 tfield3 Not Found = %s\n",tfield3);
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(tfield2, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield2, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield2, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield2, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield2, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield2, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield2, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    if (whfd5_type == 2) 
    {
      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield5, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield5a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield5, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield5a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c while_case_2 while-024 tfield5 Not Found = %s\n",tfield5);
        printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield7, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield7a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield7, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield7a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_2 while-027 tfield7 Not Found = %s\n", tfield7);
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++; 
      convert = 1;
      return;
    }

    operand_2 = 0;
    if (operand_2 == 0) 
    {
      p = strstr(tfield6, "==");
      if (p)
      {
        operand_2 = 1;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield6, "!=");
      if (p)
      {
        operand_2 = 2;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield6, "<=");
      if (p)
      {
        operand_2 = 3;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield6, ">=");
      if (p)
      {
        operand_2 = 4;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield6, "=");
      if (p)
      {
        operand_2 = 5;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield6, "<");
      if (p)
      {
        operand_2 = 6;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield6, ">");
      if (p)
      {
        operand_2 = 7;
      }
    }

    var_ci_err1 = 0;

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while-2*/");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_2 complex = 1 #1");
      trace_rec_3();
    }

    if ((var_ci_1 == 2) && (var_ci_3 == 2)) 		/*  quote in compare	*/
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 complex = 1 #2");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      src_line();
      var_ci_err1 = 1;
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 complex = 1 #3");
        trace_rec_3();
      }

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      var_ci_err1 = 1;
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 complex = 1 #4");
        trace_rec_3();
      }
    }

    if ((var_ci_1 == 1) && (var_ci_3 == 1)) 
    {
      printf("\nc2z_while.c c2_while_2 while-028 ci_1 = 1 & ci_3 = 1 NOT CODED\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (var_ci_err1 == 0) 
    {
      printf("\nc2z_while.c c2_while_2 while-029 COMPARISON ERROR\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 1)				 /* ==	*/
    {
      printf("\nc2z_while.c c2_while_2 while-030 operand_1 == Error#1\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 2) 				/* !=	*/
    {
      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      check_length();
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_2 complex = 1 #5");
        trace_rec_3();
      }
    }

    if (operand_1 == 3) 			/* <=	*/
    {
      printf("\nc2z_while.c c2_while_2 while-031 operand_1 <= Error#3\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 4) 			/* >=	*/
    {
      printf("\nc2z_while.c c2_while_2 while-032 operand_1 >= Error#4\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 5) 			/* =	*/
    {
      printf("\nc2z_while.c c2_while_2 while-033 operand_1 = Error#5\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 6) 			/* <	*/
    {
      printf("\nc2z_while.c c2_while_2 while-034 operand_1 < Error#6\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
   }

    if (operand_1 == 7) 			/* >	*/
    {
      printf("\nc2z_while.c c2_while_2 while-035 operand_1 > Error#7\n");
      printf("c2z_while.c c2_while_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  while_convert = 1;
  convert = 1;
}



void c2_while_3() /* > */
{
  printf("\nc2z_while.c c2_while_3 while-036 NOT CODED\n");
  printf("c2z_while.c c2_while_3 rct = %d p_string = %s", rct, p_string);
  erct++;
  convert = 1;
  return;
}


void c2_while_4()			 /* < */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_4 START");
    trace_rec_1();
  }

  char ch, *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];

  int pi;
  int pi2;
  int wh_3 = 0;
  int wh_4 = 0;
  int v = 0;
  int ret = 0;
  int ret1 = 0;
  int s = 0;
  int I = 0;
  int x10 = 0;
  int x11 = 0;
  int x12 = 0;
  int x13 = 0;
  int x14 = 0;
  int x80 = 0;

  s = strlen(p_string);
  s--;
  
  p = strstr(p_string, "/*");
  if(p)
  {
    v = p - p_string;
    if (v < 0) 
    {
      v = s;
    }
  }

  if(!p)
  {
     v = s;
  }

  pi = 0;
  ch = p_string[pi];
  for (I = 0; I < v; I++) 
  {
    if (ch == '[') 
    {
      x10 = I;
    }

    if (ch == ']') 
    {
      x11 = I;
    }

    if (ch == '=') 
    {
      x12 = I;
    }

    if (ch == '(') 
    {
      x13 = I;
    }

    if (ch == ')') 
    {
      x14 = I;
    }
    pi++;
    ch = p_string[pi];
  }

  if ((x10 == 0) && (x11 == 0) && (x12 == 0) && (x13 > 0) && (x14 > 0)) 
  {
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
    while (ch != '<') 
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

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    x80 = 0;
    pi2 = 0;
    while (ch != ')') 
    {
      if (ch == '(') 
      {
        x80 = 1;
        break;
      }
      if (ch != ' ') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    if (x80 == 1) 
    {
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ' ') 
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

      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }
     
/*
      for (I = 0; I < math_lit_ct; I++) 
      {
        ret = w_mathlit[I].lit_rct;
        if (rct == ret) 
        {
          strcpy(tfield5, w_mathlit[I].lit_use_cname);
          break;
        }
      }
*/
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcpy(while_tag, a_string);
      check_length();
      strcat(a_string, "DS    0H");
      strcpy(wk_remark, " while    */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_4 #10");
        trace_rec_3();
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield3, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield3a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield3, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield3a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_4 while-037 tfield3 Not Found = %s\n",tfield3);
        printf("c2z_while.c c2_while_4 rct = %d p_string = %s", rct, p_string);
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
        strcpy(trace_1, "c2z_while.c c2_while_4 #11");
        trace_rec_3();
      }

printf("FIX FIX  while_4 HERE\n");
printf("c2z_while.c while_4 rct = %d p_string = %s",rct,p_string);
printf("c2z_while.c while_4 tfield1 = %s\n",tfield1);
printf("c2z_while.c while_4 tfield3 = %s\n",tfield3);








 /*     for (I = 0; I < math_lit_ct; I++) 
      {
        ret = w_mathlit[I].lit_rct;
        if (rct == ret) 
        {
          strcpy(tfield5, w_mathlit[I].lit_use_cname);
          break;
        }
      }


      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_4 #12");
        trace_rec_3();
      }
*/

      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_4 #13");
        trace_rec_3();
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield1, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield1a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield1, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield1a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_4 while-038 tfield1 Not Found = %s\n",tfield1);
        printf("c2z_while.c c2_while_4 rct = %d p_string = %s", rct, p_string);
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
        strcpy(trace_1, "c2z_while.c c2_while_4 #14");
        trace_rec_3();
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield3, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield3a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield3, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield3a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_4 while-039 tfield3 Not Found = %s\n",tfield3);
        printf("c2z_while.c c2_while_4 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_4 #15");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_4 #16");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_4 #17");
        trace_rec_3();
      }

      strcpy(a_string, "         JLH   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_4 #18");
        trace_rec_3();
      }

      while_convert = 1;
      convert = 1;
      return;
    }

    if (x80 == 0) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_4 subroutine #3");
        trace_rec_1();
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield1, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield1a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield1, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield1a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_4 while-040 tfield1 Not Found = %s\n",tfield1);
        printf("c2z_while.c c2_while_4 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield3, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield3a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield3, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield3a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_4 while-041 tfield3 Not Found = %s\n",tfield3);
        printf("c2z_while.c c2_while_4 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcpy(while_tag, a_string);
      check_length();
      strcat(a_string, "DS    0H");
      strcpy(wk_remark, " while    */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_4 #1");
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
        strcpy(trace_1, "c2z_while.c c2_while_4 #2");
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
        strcpy(trace_1, "c2z_while.c c2_while_4 #3");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_4 #4");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_4 #5");
        trace_rec_3();
      }

      strcpy(a_string, "         JLH   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_4 #6");
        trace_rec_3();
      }

      inside_while = 1;
      while_convert = 1;
      convert = 1;
    }
  }
}

void c2_while_5() 				/* >= */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_5 START");
    trace_rec_1();
  }

  char ch;
  char *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield3[VAR_LGTH];

  int pi;
  int pi2;
  int ret;
  int ret1;
  int x2 = 0;
  int x3 = 0;
  int v = 0;
  int fd1_type = 0;
  int fd3_type = 0;
  int operand_1 = 0;

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        x2 = 1;
        fd1_type = 1;
      }

      if (isdigit(ch)) 
      {
        x2 = 1;
        fd1_type = 2;
      }
    }
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ' ') 
  {
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  while (ch != ')') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        x2 = 1;
        fd3_type = 1;
      }

      if (isdigit(ch)) 
      {
        x2 = 1;
        fd3_type = 2;
      }
    }
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  x3 = 0;
  if (fd1_type == 1) 
  {
    if (lv_ct > 0) 
    {
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
    }

    if (x3 == 0) 
    {
      x3 = 0;
      if (gv_ct > 0) 
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
    }

    if (x3 == 0) 
    {
      printf("\nc2z_while.c c2_while_5 while-042 tfield1 fd1_type == 1 Not Found = %s\n",tfield1);
      printf("c2z_while.c c2_while_5 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while    */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_5 #1");
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
      strcpy(trace_1, "c2z_while.c c2_while_5 #2 ");
      trace_rec_3();
    }
  }

  if (fd1_type == 2) 
  {
    printf("\nc2z_while.c c2_while_5 while-043 fd1_type == 2 Not Coded\n");
    printf("c2z_while.c c2_while_5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (fd3_type == 1) 
  {
    printf("\nc2z_while.c c2_while_5 while-044 fd3_type == 1 Not Coded\n");
    printf("c2z_while.c c2_while_5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (fd3_type == 2) 
  {
    strcpy(a_string, "         LA    R5,");
    strcat(a_string, tfield3);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_5 #3a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_5 #3b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_5 #3c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_5 #3d");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_5 #3e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_5 #3e");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_5 #3f");
      trace_rec_3();
    }
  }

  if ((fd1_type == 1) && (fd3_type == 2)) 
  {
    strcpy(a_string, "          CP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_5 #4");
      trace_rec_3();
    }
  }

  if ((fd1_type == 1) && (fd3_type == 1)) 
  {
    printf("\nc2z_while.c c2_while_5 while-045 fd1_type == 1 & fd3_type == 1 Not Coded\n");
    printf("c2z_while.c c2_while_5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if ((fd1_type == 2) && (fd3_type == 1)) 
  {
    printf("\nc2z_while.c c2_while_5 while-046 fd1_type == 2 & fd3_type == 1 Not Coded\n");
    printf("c2z_while.c c2_while_5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if ((fd1_type == 2) && (fd3_type == 2)) 
  {
    printf("\nc2z_while.c c2_while_5 while-047 fd1_type == 2 & fd3_type == 2 Not Coded\n");
    printf("c2z_while.c c2_while_5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  operand_1 = 0;
  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "==");
    if (p)
    {
      operand_1 = 1;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "!=");
    if (p)
    {
      operand_1 = 2;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "<=");
    if (p)
    {
      operand_1 = 3;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, ">=");
    if (p)
    {
      operand_1 = 4;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "=");
    if (p)
    {
      operand_1 = 5;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "<");
    if (p)
    {
      operand_1 = 6;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, ">");
    if (p)
    {
      operand_1 = 7;
    }
  }

  if (operand_1 == 1) 			/* ==	*/
  {
    printf("\nc2z_while.c c2_while_5 while-048 operand_1 == Error#1\n");
    printf("c2z_while.c c2_while_5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 2) 			/* ==	*/
  {
    printf("\nc2z_while.c c2_while_5 while-049 operand_1 == Error#1\n");
    printf("c2z_while.c c2_while_5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 3) 			/* <=	*/
  {
    printf("\nc2z_while.c c2_while_5 while-050 operand_1 <= Error#3\n");
    printf("c2z_while.c c2_while_5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 4) /* >=	*/
  {
    strcpy(a_string, "         JLL   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_5 #5");
      trace_rec_3();
    }
  }

  if (operand_1 == 5) 			/* =	*/
  {
    printf("\nc2z_while.c c2_while_5 while-051 operand_1 = Error#5\n");
    printf("c2z_while.c c2_while_5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 6) 			/* <	*/
  {
    printf("\nc2z_while.c c2_while_5 while-052 operand_1 < Error#6\n");
    printf("c2z_while.c c2_while_5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 7)			 /* <	*/
  {
    printf("\nc2z_while.c c2_while_5 ehile_053 operand_1 < Error#7\n");
    printf("c2z_while.c c2_while_5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  while_convert = 1;

  convert = 1;
}

void c2_while_6() 				/* <= */
{
  while_convert = 1;
  printf("\nc2z_while.c c2_while_6 while-054 while_6 ERROR ERROR\n");
  printf("c2z_while.c c2_while_6 rct = %d p_string = %s", rct, p_string);
  erct++;
  convert = 1;
  return;
}

void c2_while_7() 					/* isdigit */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_7");
    trace_rec_1();
  }

  char ch;
  char *p, *wkp;
  char wk_sv_func[32];
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int I = 0;
  int v = 0;
  int while_complex = 0;
  int whfd3_type = 0;
  int whfd7_type = 0;
  int operand_1 = 0;
  int operand_3 = 0;
  int wh_3 = 0;
  int wh_4 = 0;
  int short_while = 0;
  int ret = 0;
  int ret1 = 0;
  int zz = 0;
  int s = 0;

  var_use[10]++;

  zz = 0;
  s = strlen(p_string);

  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '&') 
    {
      zz++;
    }
    if (ch == '|') 
    {
      zz++;
    }
  }


/*  whle((isdigit(ch)) || (ch == '.') && (vi_pos <= 32)) */
/*         1       2    3  4  5   6   7     8     9 10   */
  if (zz == 4) 			
  {
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
    while (ch != '(') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    printf("\nc2z_while.c while_7  2 Complex statement ADD CODE\n");
    printf("c2z_while.c while_7 rct = %d p_string = %s\n",rct,p_string);


    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while    */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_7 #1");
      trace_rec_3();
    }




    convert = 1;
    return;
  }

  if (zz == 2) 			/* one set of && or ||  */
  {
    while_complex = 1;
  }

  if (while_complex == 0) 
  {
    p = strstr(p_string, "||");
    if (p) 
    {
      while_complex = 1;
    }
  }

  if (while_complex == 0) 
  {
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
    while (ch != '(') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    strcpy(wk_sv_func, field1);

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

    pi++;
    ch = p_string[pi];
    if (ch == ')') 
    {
      short_while = 1;
    }

    if (short_while == 1) 
    {
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcpy(while_tag, a_string);
      check_length();
      strcat(a_string, "DS    0H");
      strcpy(wk_remark, " while    */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 #1");
        trace_rec_3();
      }

      wkp = strstr(p_string, "!");
      if (wkp) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 NOT = ");
          trace_rec_1();
        }

        pi = 0;
        ch = p_string[pi];
        while (ch != '(') 
        {
          pi++;
          ch = p_string[pi];
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
        while (ch != ')') 
        {
          field1[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field1[pi2] = '\0';

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #2");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field1);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #3");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   0(1,R9),0(R8)");
        strcpy(wk_remark, " isdigit  */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #4");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         LARL  R15,ISDIGIT");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #5");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #5");
          trace_rec_3();
        }


        strcpy(a_string, "         LARL  R9,C370DIGT");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #6");
          trace_rec_3();
        }
        work_use_ct[80]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #7");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #8");
          trace_rec_3();
        }
        work_use_ct[31]++;

        strcpy(a_string, "         JLE   ");
        strcat(a_string, o_string);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #9");
          trace_rec_3();
        }
      }

      if (!wkp) 				/* equal test       */
      {
        pi = 0;
        ch = p_string[pi];
        while (ch != '(') 
        {
          pi++;
          ch = p_string[pi];
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
        while (ch != ')') 
        {
          field3[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field3[pi2] = '\0';

        x3 = 0;
        x2 = 0;
        if (lv_ct > 0) 
        {
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
        }

        if (x3 == 0) 
        {
          x2 = 0;
          if (gv_ct > 0) 
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
        }

        if (x3 == 0) 
        {
          printf("\nc2z_while.c c2_while_7 while-055 field3 Not Found = %s\n",field3);
          printf("c2z_while.c c2_while_7 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #300");
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
          strcpy(trace_1, "c2z_while.c c2_while_7 #301");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         MVC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #302");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R15,ISDIGIT");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #303");
          trace_rec_3();
        }
        var_use[10]++;

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #303");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370DIGT");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #304");
          trace_rec_3();
        }
        work_use_ct[80]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #305");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #306");
          trace_rec_3();
        }
        work_use_ct[31]++;

        if (wh_ct > 0) 
        {
          for (I = 0; I < wh_ct; I++) 
          {
            if (w_while_table[I].wh_rct == rct) 
            {
              snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
            }
          }
        }

        strcpy(a_string, "         JNE   ");
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_7 #307");
          trace_rec_3();
        }
      }

      while_convert = 1;
      convert = 1;
    }

    if (short_while == 0) 
    {
      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      while (ch != ' ') 
      {
        field3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field3[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != ')') 
      {
        pi++;
        ch = p_string[pi];
      }

      operand_1 = 0;
      if (operand_1 == 0) 
      {
        p = strstr(field3, "==");
        if (p)
        {
          operand_1 = 1;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field3, "!=");
        if (p)
        {
          operand_1 = 2;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field3, "<=");
        if (p)
        {
          operand_1 = 3;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field3, ">=");
        if (p)
        {
          operand_1 = 4;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field3, "=");
        if (p)
        {
          operand_1 = 5;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field3, "<");
        if (p)
        {
          operand_1 = 6;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field3, ">");
        if (p)
        {
          operand_1 = 7;
        }
      }

      x3 = 0;
      x2 = 0;
      if (lv_ct > 0) 
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

      if (x3 == 0) 
      {
        x2 = 0;
        if (gv_ct > 0) 
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
      }

      if (x3 == 0) 
      {
        printf("\nc2z_while.c c2_while_7 complex = 0 while-056 short_while = 0 field2 Not Found = %s\n",field2);
        printf("c2z_while.c c2_while_7 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcpy(while_tag, a_string);
      check_length();
      strcat(a_string, "DS    0H");
      strcpy(wk_remark, " while    */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 Short #1");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 Short #2");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */ ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 Short #3");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 Short #4");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         LARL  R15,ISDIGIT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 Short #5");
        trace_rec_3();
      }
      var_use[10]++;

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 Short #5");
        trace_rec_3();
      }
 
      strcpy(a_string, "         LARL  R9,C370DIGT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 Short #6");
        trace_rec_3();
      }
      work_use_ct[80]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 Short #7");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 Short #8");
        trace_rec_3();
      }

      if (wh_ct > 0) 
      {
        for (I = 0; I < wh_ct; I++) 
        {
          if (w_while_table[I].wh_rct == rct) 
          {
            snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
          }
        }
      }

      strcpy(a_string, "         JLE   ");
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 Short #9");
        trace_rec_3();
      }

      while_convert = 1;
      convert = 1;
    }
  } 				/* END of WHILE_COMPLEX == 0 */

  if (while_complex == 1) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_7 complex == 1");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
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
    while (ch != ')') 
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
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      if (ch != ' ') 
      {
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    field2[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    x2 = 0;
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          whfd3_type = 1;
          x2 = 1;
        }
        if (isalpha(ch)) 
        {
          whfd3_type = 2;
          x2 = 1;
        }
      }
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

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

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      field5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      field6[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field6[pi2] = '\0';

    x2 = 0;
    pi2 = 0;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          whfd7_type = 1;
          x2 = 1;
        }
        if (isalpha(ch)) 
        {
          whfd7_type = 2;
          x2 = 1;
        }
      }

      if (ch != ' ') 
      {
        field7[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field7[pi2] = '\0';

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field1a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field1, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field1a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_7 while-057 field1 Not Found = %s\n", field1);
      printf("c2z_while.c c2_while_7 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(field2, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    /*
    printf("\n rct = %d p_string = %s",rct,p_string);
    printf("c2z_while.c c2_while_7 field1 = %s\n",field1);
    printf("c2z_while.c c2_while_7 field2 = %s\n",field2);
    printf("c2z_while.c c2_while_7 field3 = %s\n",field3);
    printf("c2z_while.c c2_while_7 field5 = %s\n",field5);
    printf("c2z_while.c c2_while_7 field6 = %s\n",field6);
    printf("c2z_while.c c2_while_7 field7 = %s\n",field7);
    printf("c2z_while.c c2_while_7 whfd3_type = %d\n",whfd3_type);
    */

    if (whfd3_type == 1) 
    {
      strcpy(field3a, field3);
    }

    if (whfd3_type == 2) 
    {
      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field3, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field3a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field3, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field3a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_7 while-058 field3 Not Found = %s\n", field3);
        printf("c2z_while.c c2_while_7 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field5, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field5a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field5, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field5a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_7 while-059 field5 Not Found = %s\n", field5);
      printf("c2z_while.c c2_while_7 rct = %d p_string = %s", rct, p_string);
      convert = 1;
      erct++;
      return;
    }

    operand_3 = 0;
    if (operand_3 == 0) 
    {
      p = strstr(field6, "==");
      if (p)
      {
        operand_3 = 1;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, "!=");
      if (p)
      {
        operand_3 = 2;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, "<=");
      if (p)
      {
        operand_3 = 3;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, ">=");
      if (p)
      {
        operand_3 = 4;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, "=");
      if (p)
      {
        operand_3 = 5;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, "<");
      if (p)
      {
        operand_3 = 6;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, ">");
      if (p)
      {
        operand_3 = 7;
      }
    }

    if (whfd7_type == 2) 
    {
      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field7, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field7a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field7, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field7a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_7 while-060 field7 Not Found = %s\n", field7);
        printf("c2z_while.c c2_while_7 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while    */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_7 #200");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_7 #201");
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
      strcpy(trace_1, "c2z_while.c c2_while_7 #202");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_7 #203");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,ISDIGIT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_7 #204");
      trace_rec_3();
    }
    var_use[10]++;

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_7 #204");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370DIGT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_7 #205");
      trace_rec_3();
    }
    work_use_ct[80]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_7 #206");
      trace_rec_3();
    }
 
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_7 #207");
      trace_rec_3();
    }
    work_use_ct[31]++;

    if (operand_1 == 1) 
    {
      strcpy(a_string, "         JNE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 #208");
        trace_rec_3();
      }
    }

    if (operand_1 == 2) 
    {
      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 #209");
        trace_rec_3();
      }
    }

    strcpy(a_string, "*         LARL  R9,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_7 #210");
      trace_rec_3();
    }


    if (whfd7_type == 1) 
    {

printf("FIX FIX FIX\n");
printf("rct = %d p_string = %s",rct,p_string);

/*


      for (I = 0; I < math_lit_ct; I++) 
      {
        if (rct == w_mathlit[I].lit_rct) 
        {
          strcpy(field7a, w_mathlit[I].lit_use_cname);
          break;
        }
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field7a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field7);
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 #211");
        trace_rec_3();
      }
*/
    }

    if (whfd7_type == 2) 
    {
      strcpy(a_string, "*         LARL  R8,");
      strcat(a_string, field7a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field7);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 #212");
        trace_rec_3();
      }
    }

    strcpy(a_string, "*         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_7 #213");
      trace_rec_3();
    }

    if (operand_3 == 3) 
    {
      strcpy(a_string, "*         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 #214");
        trace_rec_3();
      }

      strcpy(a_string, "*         JLH   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 #215");
        trace_rec_3();
      }
    }

    if (operand_3 == 6) 
    {
      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 #216");
        trace_rec_3();
      }

      strcpy(a_string, "         JLH   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_7 #217");
        trace_rec_3();
      }
    }
    while_convert = 1;
    convert = 1;
  }
}

void c2_while_8() 			/* isalpha */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_8");
    trace_rec_1();
  }

  char ch;
  char *p, *wkp;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];
 
  int pi;
  int pi2;
  int while_complex = 0;
  int whfd3_type = 0;
  int x2 = 0;
  int x3 = 0;
  int v = 0;
  int operand_1 = 0;
  int operand_3 = 0;
  int wh_3 = 0;
  int wh_4 = 0;
  int ret = 0;
  int ret1 = 0;
  int I = 0;
  int s = 0;
  int L_par = 0;
  int R_par = 0;
  
  s = strlen(p_string);
  for(I = 0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '(')
    {
      L_par++;
    }
    if(ch == ')')
    {
      R_par++;
    }
  }

  if((L_par == 5) && (R_par == 5))
  {
    goto skip_while_85;
  }

  var_use[9]++;

  p = strstr(p_string, "&&");
  if (p) 
  {
    while_complex = 1;
  }

  if (while_complex == 0) 
  {
    p = strstr(p_string, "||");
    if (p) 
    {
      while_complex = 1;
    }
  }

  if (while_complex == 0) 
  {
    wkp = strstr(p_string, "!");
    if (wkp) 				/* not equal test ! */
    {
      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
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
      while (ch != ')') 
      {
        field1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';

      strcpy(a_string, "         LARL  R9,C370L1A");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #1");
        trace_rec_3();
      }
      work_use_ct[59]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field1);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #2");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #3");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R15,ISALPHA"); 
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #4");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #4");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISAL");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #5");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #6");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #7");
        trace_rec_3();
      }
      work_use_ct[1]++;

      strcpy(a_string, "         JLE   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #8");
        trace_rec_3();
      }
    }

    if (!wkp) 				/* equal test       */
    {
      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
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
      while (ch != ')') 
      {
        field1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';

      strcpy(a_string, "         LARL  R9,C370L1A");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #9");
        trace_rec_3();
      }
      work_use_ct[59]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field1);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #10");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #11");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R15,ISALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #16");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #17");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISAL");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #13");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #14");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #15");
        trace_rec_3();
      }

      strcpy(a_string, "         JLNE  ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #16");
        trace_rec_3();
      }
    }

    while_convert = 1;
    convert = 1;
  }

  if (while_complex == 1) 
  {
    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
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
    while (ch != ')') 
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
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      if (ch != ' ') 
      {
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    field2[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    x2 = 0;
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          whfd3_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          whfd3_type = 2;
          x2 = 1;
        }
      }
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

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

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      field5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      field6[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field6[pi2] = '\0';

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != ' ') 
      {
        field7[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field7[pi2] = '\0';

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field1a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field1, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field1a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_8 while-061 field1 Not Found = %s\n", field1);
      printf("c2z_while.c c2_while_8 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(field2, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    if (whfd3_type == 1) 
    {
      strcpy(field3a, field3);
    }

    if (whfd3_type == 2) 
    {
      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field3, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field3a, lw_variable[v].lv_cname);
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field3, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field3a, gw_variable[v].gv_cname);
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("c2z_while.c while_case_8 while-062 field3 Not Found = %s\n",field3);
        c2_error();
      }
    }

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field5, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field5a, lw_variable[v].lv_cname);
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field5, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field5a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_8 while-063 field5 Not Found = %s\n", field5);
      printf("c2z_while.c c2_while_7 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    operand_3 = 0;
    if (operand_3 == 0) 
    {
      p = strstr(field6, "==");
      if (p)
      {
        operand_3 = 1;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, "!=");
      if (p)
      {
        operand_3 = 2;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, "<=");
      if (p)
      {
        operand_3 = 3;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, ">=");
      if (p)
      {
        operand_3 = 4;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, "=");
      if (p)
      {
        operand_3 = 5;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, "<");
      if (p)
      {
        operand_3 = 6;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, ">");
      if (p)
      {
        operand_3 = 7;
      }
    }

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field7, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field7a, lw_variable[v].lv_cname);
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field7, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field7a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_8 while-064 field7 Not Found = %s\n", field7);
      printf("c2z_while.c c2_while_8 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while    */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_8 #30");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_8 #31");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_8 #32");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_8 #33");
      trace_rec_3();
    }

      strcpy(a_string, "         LARL  R15,ISALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #16");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #17");
        trace_rec_3();
      }

    strcpy(a_string, "         LARL  R9,C370ISAL");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_8 #35");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_8 #36");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_8 #37");
      trace_rec_3();
    }
    work_use_ct[1]++;

    if (operand_1 == 1) 
    {
      strcpy(a_string, "         JLNE  L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #38");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_8 #39");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field7a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field7);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_8 #40");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_8 #41");
      trace_rec_3();
    }

    if (operand_3 == 6) 
    {
      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #42");
        trace_rec_3();
      }

      strcpy(a_string, "         JLH   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 #43");
        trace_rec_3();
      }
    }

    while_convert = 1;
    convert = 1;
    return;
  }

  skip_while_85:

  pi = 0;
  ch = p_string[pi];
  while(ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  } 

  pi++;
  pi++;

  pi2 = 0;
  ch = p_string[pi];
  while(ch != ' ')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while(ch != ' ')
  {
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while(ch != ')')
  {
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  operand_1 = 0;
  if (operand_1 == 0) 
  {
    p = strstr(field2, "==");
    if (p)
    {
      operand_1 = 1;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, "!=");
    if (p)
    {
      operand_1 = 2;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, "<=");
    if (p)
    {
      operand_1 = 3;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, ">=");
    if (p)
    {
      operand_1 = 4;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, "=");
    if (p)
    {
      operand_1 = 5;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, "<");
    if (p)
    {
      operand_1 = 6;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, ">");
    if (p)
    {
      operand_1 = 7;
    }
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  check_length();
  strcat(a_string, "DS    0H");
  strcpy(wk_remark, " while    */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_85 #1");
    trace_rec_3();
  }
 
  inside_while = 1;

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
        printf("\nc2z_while.c c2_while_85 while-065 field1 Not Found = %s\n", field1);
        printf("c2z_while.c c2_while_85 rct = %d p_string = %s", rct, p_string);
        erct++;
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
    strcpy(trace_1, "c2z_while.c c2_while_85 #2");
    trace_rec_3();
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
      lw_variable[I].lv_use_ct++;
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
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
        printf("\nc2z_while.c c2_while_85 while-066 field3 Not Found = %s\n", field3);
        printf("c2z_while.c c2_while_85 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field3a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_8 (5) #3");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_8 (5) #4");
    trace_rec_3();
  }


  if (operand_1 == 1) 			/* ==	*/
  {
    printf("\nc2z_while.c c2_while_8 (5) while-067 operand_1 == Error#1\n");
    printf("c2z_while.c c2_while_8 (5) rct = %d p_string = %s", rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 2) 			/* !=	*/
  {
      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_8 (5) #5");
        trace_rec_3();
      }
  }

  if (operand_1 == 3) 		/* <=	*/
  {
    printf("\nc2z_while.c c2_while_8 (5) while-068 operand_1 <= Error#3\n");
    printf("c2z_while.c c2_while_8 (5) rct = %d p_string = %s", rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 4) 		/* >=	*/
  { 
    printf("\nc2z_while.c c2_while_8 (5) while-069 operand_1 >= Error#4\n");
    printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 5) 		/* =	*/
  {
    printf("\nc2z_while.c c2_while_8 (5) while-070 operand_1 = Error#5\n");
    printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 6) 		 /* <  */
  {
    printf("\nc2z_while.c c2_while_8 (5) while-071 operand_1 < Error#6\n");
    printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 7) /* >	*/
  {
     printf("\nc2z_while.c c2_while_8 (5) while-072 operand_1 > Error#7\n");
     printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
     erct++;
     convert = 1;
     return;
  }

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while(ch != '(')
  {
    if(ch != ' ')
    {
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while(ch != '(')
  {
    if(ch != ' ')
    {
      field5[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field5[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ')')
  {
    if(ch != ' ')
    {
      field6[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field6[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while(ch != ' ')
  {
    if(ch != ' ')
    {
      field7[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field7[pi2] = '\0';

  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while(ch != ')')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while(ch != ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while(ch != ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  ch = p_string[pi];
  while(ch != ' ')
  {
    pi++;
    ch = p_string[pi];
  }
 
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  ch = p_string[pi];
  while(ch != ')')
  {
    pi++;
    ch = p_string[pi];
  }
}

void c2_while_9() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_9 START");
    trace_rec_1();
  }

  char ch;
  /* char field1[VAR_LGTH]; */
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];

  int pi;
  int pi2;
  int x3 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;

  inside_while = 1;

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
  while (ch != '(') 
  {
    /* field1[pi2] = ch; */
    pi2++;
    pi++;
    ch = p_string[pi];
  }
 /* field1[pi2] = '\0'; */

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

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while    */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_9 #1");
      trace_rec_3();
    }

  while_convert = 1;
  convert = 1;
}

void c2_while_10() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_10");
    trace_rec_1();
  }

  char ch;
  char *p, *p1;

  int pi;
  int pi2;
  int wh_2 = 0;
  int wh_3 = 0;
  int wh_4 = 0;
  int whfd3_type = 0;
  int while_complex = 0;
  int while_simple = 0;
  int operand_1 = 0;
  int operand_3 = 0;
  int x2 = 0;
  int v = 0;
  int ret = 0;
  int ret1 = 0;

  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];

  var_use[20]++;

  p = strstr(p_string, "&&");
  if (p) 
  {
    while_complex = 1;
  }

  if (while_complex == 0) 			/* non complex isupper	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 while_complex = 0");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
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
    while (ch != ')') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    while_simple = 0;
    p1 = strstr(p_string, "==");
    if (p1) 
    {
      while_simple = 0;
    } 
    else 
    {
      while_simple = 1;
    }

    if (while_simple == 0) 				/* continue down p_string		*/
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0");
        trace_rec_1();
      }

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      while (ch != ' ') 
      {
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field2[pi2] = '\0';

      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi2 = 0;
      while (ch != ')') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            whfd3_type = 1;
            x2 = 1;
          }

          if (isalpha(ch)) 
          {
            whfd3_type = 2;
            x2 = 1;
          }
        }
        field3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field3[pi2] = '\0';

      wh_3 = 0;
      wh_2 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field1, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field1a, lw_variable[v].lv_cname);
          }
        }
      }

      if (wh_3 == 0) 
      {
        wh_2 = 0;
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field1, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field1a, gw_variable[v].gv_cname);
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_10 while-073 field1 Not Found = %s\n", field1);
        printf("c2z_while.c c2_while_10 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (whfd3_type == 2) 
      {
        wh_3 = 0;
        wh_2 = 0;
        if (lv_ct > 0) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            wh_4 = strcmp(field3, lw_variable[v].lv_name);
            wh_2 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((wh_4 == 0) && (wh_2 == 0)) 
            {
              wh_3 = 1;
              strcpy(field3a, lw_variable[v].lv_cname);
            }
          }
        }

        if (wh_3 == 0) 
        {
          wh_2 = 0;
          if (gv_ct > 0) 
          {
            for (v = 0; v < gv_ct; v++) 
            {
              wh_4 = strcmp(field3, gw_variable[v].gv_name);
              if (wh_4 == 0) 
              {
                wh_3 = 1;
                strcpy(field3a, gw_variable[v].gv_cname);
              }
            }
          }
        }

        if (wh_3 == 0) 
        {
          printf("\nc2z_while.c c2_while_10 while-074 field3 Not Found = %s\n",field3);
          printf("c2z_while.c c2_while_10 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }
      }

      if (whfd3_type == 1) 			/* field3 is numeric literal	*/
      {
        strcpy(field3a, field3);
      }

      operand_1 = 0;
      if (operand_1 == 0) 
      {
        p = strstr(field2, "==");
        if (p)
        {
          operand_1 = 1;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, "!=");
        if (p)
        {
          operand_1 = 2;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, "<=");
        if (p)
        {
          operand_1 = 3;  
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, ">=");
        if (p)
        {
          operand_1 = 4;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, "=");
        if (p)
        {
          operand_1 = 5;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, "<");
        if (p)
        {
          operand_1 = 6;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, ">");
        if (p)
        {
          operand_1 = 7;
        }
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      check_length();
      strcat(a_string, "DS    0H");
      strcpy(wk_remark, " while    */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #1");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #2");
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
        strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #3");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #4");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R15,ISUPPER");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #5");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #5");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISAL");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #6");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #7");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #8");
        trace_rec_3();
      }

      strcpy(a_string, "         JLNE  L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple = 0 #9");
        trace_rec_3();
      }
    }

    if (while_simple == 1) /* while(isupper(ch))	*/
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple");
        trace_rec_1();
      }

      wh_3 = 0;
      wh_2 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field1, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field1a, lw_variable[v].lv_cname);
          }
        }
      }

      if (wh_3 == 0) 
      {
        wh_2 = 0;
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field1, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field1a, gw_variable[v].gv_cname);
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_10 while-075 field1 Not Found = %s\n", field1);
        printf("c2z_while.c c2_while_10 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      check_length();
      strcat(a_string, "DS    0H");
      strcpy(wk_remark, " while    */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple #1");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple #2");
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
        strcpy(trace_1, "c2z_while.c c2_while_10 simple #3");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple #4");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R15,ISUPPER");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_whiel.c c2_while_10 simple #5");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_whiel.c c2_while_10 simple #5");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISAL");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple #6");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple #7");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple #8");
        trace_rec_3();
      }

      strcpy(a_string, "         JNE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 simple #9");
        trace_rec_3();
      }
    }
  }

  if (while_complex == 1) 					/* start of complex isupper		*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
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
    while (ch != ')') 
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
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      if (ch != ' ') 
      {
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    field2[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    x2 = 0;
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          whfd3_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          whfd3_type = 2;
          x2 = 1;
        }
      }
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

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

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      field5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      field6[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field6[pi2] = '\0';

    ch = p_string[pi];
    while (ch == ' ') 
    {
      field6[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ')') 
    {
      field7[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field7[pi2] = '\0';

    wh_3 = 0;
    wh_2 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field1a, lw_variable[v].lv_cname);
        }
      }
    }

    if (wh_3 == 0) 
    {
      wh_2 = 0;
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field1, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field1a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_10 while-076 field1 Not Found = %s\n", field1);
      printf("c2z_while.c c2_while_10 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(field2, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    if (whfd3_type == 1) 
    {
      strcpy(field3a, field3);
    }

    if (whfd3_type == 2) {
      wh_3 = 0;
      wh_2 = 0;
      if (lv_ct > 0) {
        for (v = 0; v < lv_ct; v++) {
          ret = strcmp(field3, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) {
            wh_3 = 1;
            strcpy(field3a, lw_variable[v].lv_cname);
          }
        }
      }

      if (wh_3 == 0) 
      {
        wh_2 = 0;
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field3, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field3a, gw_variable[v].gv_cname);
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_10 while-077 field3 Not Found = %s\n", field3);
        printf("c2z_while.c c2_while_10 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    wh_3 = 0;
    wh_2 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field5, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field5a, lw_variable[v].lv_cname);
        }
      }
    }

    if (wh_3 == 0) 
    {
      wh_2 = 0;
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field5, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field5a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_10 while-078 field5 Not Found = %s\n", field5);
      printf("c2z_while.c c2_while_10 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    operand_3 = 0;
    if (operand_3 == 0) 
    {
      p = strstr(field6, "==");
      if (p)
      {
        operand_3 = 1;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, "!=");
      if (p)
      {
        operand_3 = 2;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, "<=");
      if (p)
      {
        operand_3 = 3;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, ">=");
      if (p)
      {
        operand_3 = 4;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, "=");
      if (p)
      {
        operand_3 = 5;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, "<");
      if (p)
      {
        operand_3 = 6;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field6, ">");
      if (p)
      {
        operand_3 = 7;
      }
    }

    wh_3 = 0;
    wh_2 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field7, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field7a, lw_variable[v].lv_cname);
        }
      }
    }

    if (wh_3 == 0) 
    {
      wh_2 = 0;
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field7, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field7a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_10 while-079 field7 Not Found = %s\n", field7);
      printf("c2z_while.c c2_while_10 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while    */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,ISUPPER");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370ISAL");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #7");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #8");
      trace_rec_3();
    }
    work_use_ct[1]++;

    if (operand_1 == 1) 
    {
      strcpy(a_string, "         JNE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #9");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field7a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field7);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #11");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #12");
      trace_rec_3();
    }

    if (operand_3 == 6) 
    {
      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #13");
        trace_rec_3();
      }

      strcpy(a_string, "         JLH   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_10 complex = 1 #14");
        trace_rec_3();
      }
    }

    while_convert = 1;
    convert = 1;
  }
}

void c2_while_11() 			/* isspace	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_11");
    trace_rec_1();
  }

  var_use[11]++;

  char *p;
  char ch;

  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  int pi;
  int pi2;
  int while_complex = 0;
  int v = 0;
  int wh_3 = 0;
  int wh_4 = 0;
  int ret = 0;
  int ret1 = 0;
  
  p = strstr(p_string, "&&");
  if (p) 
  {
    while_complex = 1;
  }

  if (while_complex == 0) 				/* non complex isspace	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
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
    while (ch != ')') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field1a, lw_variable[v].lv_cname);
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field1, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field1a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_11 while-080 field1 Not Found = %s\n", field1);
      printf("c2z_while.c c2_while_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while    */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #2");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,ISSPACE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370ISAL");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #7");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_11 complex = 0 #8");
      trace_rec_3();
    }
  }
}

void c2_while_12() 					/* ISALNUM	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_12");
    trace_rec_1();
  }

  var_use[12]++;

  char *p;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  int pi;
  int pi2;
  int while_complex = 0;
  int wh_3 = 0;
  int wh_4 = 0;
  int x = 0;
  int s = 0;
  int I = 0;
  int v = 0;
  int ret = 0;
  int ret1 = 0;

  p = strstr(p_string, "&&");
  if (p) 
  {
    while_complex = 1;
  }

  if (while_complex == 0) 				/* non complex isalnum	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_while.c while_12 complex = 0");
      trace_rec_1();
    }

    x = 0;
    s = strlen(p_string);
    for (I = 0; I < s; I++) 
    {
      ch = p_string[I];
      if (ch == '(') 
      {
        x++;
      }
    }

    if (x == 2) 
    {
      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
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
      while (ch != ')') 
      {
        field1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';
    }

    if (x == 3) 
    {
      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi++;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
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
      while (ch != ')') 
      {
        field1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';
    }

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field1a, lw_variable[v].lv_cname);
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field1, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field1a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_12 while-081 field1 Not Found = %s\n", field1);
      printf("c2z_while.c c2_while_121 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while    */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c while_12 complex = 0 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c while_12 complex = 0 #2");
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
      strcpy(trace_1, "c2z_while.c while_12 complex = 0 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c while_12 complex = 0 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,ISALNUM");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c while_12 complex = 0 #5");
      trace_rec_3();
    }
 
    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c while_12 complex = 0 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370ISAL");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c while_12 complex = 0 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c while_12 complex = 0 #7");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c while_12 complex = 0 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         JNE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c while_12 complex = 0 #9");
      trace_rec_3();
    }
  }
}

void c2_while_13() 			/* STRCMP	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_13 START");
    trace_rec_1();
  }

  char *p;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field2b[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field6a[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];
  char field8[VAR_LGTH];
  char field8a[VAR_LGTH];
  char field9[VAR_LGTH];
  char field9a[VAR_LGTH];
  char field10[VAR_LGTH];
  char field10a[VAR_LGTH];

  int pi;
  int pi2;
  int while_complex = 0;
  int whfd5_type = 0;
  int wh_3 = 0;
  int wh_4 = 0;
  int x2 = 0;
  int x10a = 0;
  int x11a = 0;
  int x16a = 0;
  int x17 = 0;
  int x18 = 0;
  int x20 = 0;
  int x21 = 0;
  int x33 = 0;
  int x34 = 0;
  int x40 = 0;
  int x41 = 0;
  int v = 0;
  int array_flag = 0;
  int I;
  int s;
  int operand_1 = 0;
  int operand_2 = 0;
  int ret = 0;
  int ret1 = 0;

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];

  p = strstr(p_string, "&&");
  if (p) 
  {
    while_complex = 1;
  }

  if (while_complex == 0) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_13 subroutine #1");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
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
        field3[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      field4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field4[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          whfd5_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          whfd5_type = 2;
          x2 = 1;
        }
      }
      pi2++;
      pi++;
      ch = p_string[pi];
    }

    wh_3 = 0;
    array_flag = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field1a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          ret = strcmp(lw_variable[v].lv_type, "A");
          if (ret == 0) 
          {
            array_flag = 1;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field1, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field1a, gw_variable[v].gv_cname);
            ret = strcmp(gw_variable[v].gv_type, "A");
            if (ret == 0) 
            {
              strcpy(ar_field5, gw_variable[v].gv_dsect);
              strcpy(ar_field6, gw_variable[v].gv_label);
              strcpy(ar_field7, gw_variable[v].gv_table);
              strcpy(ar_field8, gw_variable[v].gv_aname);
              strcpy(ar_field10, gw_variable[v].gv_wk_reg);
              strcpy(ar_field11, gw_variable[v].gv_wk_strg);
              gw_variable[v].gv_flag = 1;
              gw_variable[v].gv_use_ct++;
              array_flag = 1;
            }
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_13 while-082 field1 Not Found = %s\n", field1);
      printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field2, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field2a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field2, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field2a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_13 while-083 field2 Not Found =b%s\n", field2);
      printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field3, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(field3a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field3, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field3a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_13 while-084 field3 Not Found = %s\n", field3);
      printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(field4, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
     {
      p = strstr(field4, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    if (whfd5_type == 1) 
    {
/*
      for (I = 0; I < math_lit_ct; I++) 
      {
        if (rct == w_mathlit[I].lit_rct) 
        {
          strcpy(field7a, w_mathlit[I].lit_use_cname);
          break;
        }
      }
*/

printf("FIX FIX FIX \n");
printf("rct = %d p_string = %s",rct,p_string);

    }


    printf("\nc2z_while.c c2_while_13 while-085 while_complex = 0 Code Not Written\n");
    printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (while_complex == 1) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_13 subroutine #20");
      trace_rec_1();
    }

    v = strlen(p_string);
    x10a = 1;
    x11a = 1;
    x16a = 0;
    x20 = 0;
    x21 = 0;
    pi = 0;
    ch = p_string[pi];
    for (I = 0; I < v; I++) 
    {
      if (ch == '[') 
      {
       x10a++;
      }

      if (ch == ']') 
      {
        x11a++;
      }

      if (ch == '.') 
      {
        x16a++;
      }

      pi++;
      ch = p_string[pi];
    }

    p = strstr(p_string, "strcmp");
    x17 = p - p_string;
    p = strstr(p_string, "&&");
    x18 = p - p_string;
    p = strstr(p_string, ",");
    x40 = p - p_string;
    p = strstr(p_string, "[");
    x41 = p - p_string;

    if (x17 < x18) 				/* strcmp on left side of && */
    {
      x20 = 0;
      x21 = 0;
      s = strlen(p_string);
      for(I=0; I < s; I++)
      {
        ch = p_string[I];
        if(ch == '(')
        {
          x20++;
        }
        if(ch == '[')
        {
          x21++;
        }
      }


     if((x20 == 4) && (x21 == 1) && (x41 > x40))   
     {
        pi = 0;
        ch = p_string[pi];
        while (ch != '(') 
        {
          pi++;
          ch = p_string[pi];
        }

        pi++;
        ch = p_string[pi];
        while (ch != '(') 
        {
          pi++;
          ch = p_string[pi];
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
          field1[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field1[pi2] = '\0';

        pi2 = 0;
        pi++;
        ch = p_string[pi];
        while (ch != '[') 
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
        while (ch != ']') 
        {
          if(ch != ' ')
          {
            if(ch != ',')
            {
              field3[pi2] = ch;
              pi2++;
            }
          }
          pi++;
          ch = p_string[pi];
        }
        field3[pi2] = '\0';

        pi++;
        pi++;
       
        pi2 = 0;
        ch = p_string[pi];
        while (ch != ')') 
        {
          field4[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field4[pi2] = '\0';

        pi++;
        ch = p_string[pi];
        while(ch == ' ')
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        while (ch != ' ') 
        {
          field5[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field5[pi2] = '\0';

        while(ch == ' ')
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        while (ch != ')') 
        {
          field6[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field6[pi2] = '\0';

        pi++;
        ch = p_string[pi];
        while(ch == ' ')
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        while (ch != ' ') 
        {
          field7[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field7[pi2] = '\0';

        while(ch != '(')
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        pi++;
        ch = p_string[pi];
        while (ch != ' ') 
        {
          field8[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field8[pi2] = '\0';

       while(ch == ' ')
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        while (ch != ' ') 
        {
          field9[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field9[pi2] = '\0';

        while(ch == ' ')
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        while (ch != ')') 
        {
          field10[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field10[pi2] = '\0';

        operand_1 = 0;
        if (operand_1 == 0) 
        {
          p = strstr(field5, "==");
          if (p)
          {
            operand_1 = 1;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field5, "!=");
          if (p)
          {
            operand_1 = 2;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field5, "<=");
          if (p)
          {
            operand_1 = 3;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field5, ">=");
          if (p)
          {
            operand_1 = 4;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field5, "=");
          if (p)
          {
            operand_1 = 5;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field5, "<");
          if (p)
          {
            operand_1 = 6;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field5, ">");
          if (p)
          {
            operand_1 = 7;
          }
        }

        operand_2 = 0;
        if (operand_1 == 0) 
        {
          p = strstr(field9, "==");
          if (p)
          {
            operand_2 = 1;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field9, "!=");
          if (p)
          {
            operand_2 = 2;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field9, "<=");
          if (p)
          {
            operand_2 = 3;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field9, ">=");
          if (p)
          {
            operand_2 = 4;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field9, "=");
          if (p)
          {
            operand_2 = 5;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field9, "<");
          if (p)
          {
            operand_2 = 6;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field9, ">");
          if (p)
          {
            operand_2 = 7;
          }
        }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field1, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field1a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field1, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field1a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_13 while-178 field1 Not Found = %s\n", field1);
        printf("c2z_while.c c2_while_13 x20 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      wh_3 = 0;
      for (I = 0; I < m_struc_ct; I++) 
      {
        ret = strcmp(field2,w_struc[I].st_name);
        if(ret == 0)
        {
          strcpy(field2a, w_struc[I].st_cname);
          wh_3 = 1;
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c while_case_13 while-179 field2 Not Found = %s\n",field2);
        printf("c2z_while.c while_case_13 x20 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field3, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field3a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field3, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field3a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_13 while-180 field3 Not Found = %s\n", field3);
        printf("c2z_while.c c2_while_13 x20 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field10, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field10a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field10, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field10a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_13 while-181 field10 Not Found = %s\n", field10);
        printf("c2z_while.c c2_while_13 x20 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field8, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field8a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field8, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field8a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_13 while-182 field8 Not Found = %s\n", field8);
        printf("c2z_while.c c2_while_13 x20 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_13 #900");
        trace_rec_3();
      }

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #901");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #902");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, field2a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field2);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #903");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcpy(start_while, a_string);
        check_length();
        strcat(a_string, "DS    0H");
        strcpy(wk_remark, " while    */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #904");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field3a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field3);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #905");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #906");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #907");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #908");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #909");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #910");
          trace_rec_3();
        }

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #911");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, field2a);
        strcat(a_string, "L");
        strcat(a_string, "(R0,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #912");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #913");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "F");
        strcpy(start_while, a_string);
        check_length();
        strcat(a_string, "DS    0H");
        strcpy(wk_remark, " while    */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #914");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #915");
          trace_rec_3();
        }

        strcpy(a_string, "         CLC   0(3,R9),0(R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #916");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #917");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field8a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field8);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #918");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field10a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field10);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #919");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #920");
          trace_rec_3();
        }

        if (operand_1 == 1) 			/* ==	*/
        {
          printf("\nc2z_while.c c2_while_13 while-090 operand_1 == Error#1\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 3) 			/* <=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-091 operand_1 <= Error#3\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 4) 			/* >=	*/
        {
          printf("c2z_while.c c2_while_13 while-092 operand_1 >= Error#4\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 5) 				/* =	*/
        {
          printf("\nc2z_while.c c2_while_13 while-093 operand_1 = Error#5\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 6) 				/* <	*/
        {
          printf("\nc2z_while.c c2_while_13 while-094 operand_1 < Error#6\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 7) 				/* >	*/
        {
          strcpy(a_string, "         JLE   L");
          snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
          strcat(a_string, wk_strg);
          strcat(a_string, "E");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_13 #921");
            trace_rec_3();
          }

          strcpy(a_string, "         JLH   L");
          snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
          strcat(a_string, wk_strg);
          strcat(a_string, "E");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_13 #921");
            trace_rec_3();
          }
        }

        if (operand_2 == 1) 				/* ==	*/
        {
          printf("\nc2z_while.c c2_while_13 while-096 operand_2 == Error#1\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 2) 				/* !=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-097 operand_2 != Error#3\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 3) 				/* <=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-098 operand_2 <= Error#3\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 4) 				/* >=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-099 operand_2 >= Error#4\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 5) 				/* =	*/
        {
          printf("\nc2z_while.c c2_while_13 while-100 operand_2 = Error#5\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

       convert = 1;
       return;
     }


      if((x20 == 4) && (x21 == 1) && (x41 < x40))      /* while((strcmp(sn_stack[ndx],varname) != 0) && (ndx < MAX_VARS)) */
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 subroutine #22");
          trace_rec_1();
        }

        pi = 0;
        ch = p_string[pi];
        while (ch != '(') 
        {
          pi++;
          ch = p_string[pi];
        }

        pi++;
        ch = p_string[pi];
        while (ch != '(') 
        {
          pi++;
          ch = p_string[pi];
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
          if(ch != ' ')
          {
            if(ch != ',')
            {
              field3[pi2] = ch;
              pi2++;
            }
          }
          pi++;
          ch = p_string[pi];
        }
        field3[pi2] = '\0';

        pi++;
        ch = p_string[pi];
        while(ch == ' ')
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        ch = p_string[pi];
        while (ch != ' ') 
        {
          field4[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field4[pi2] = '\0';

        ch = p_string[pi];
        while(ch == ' ')
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        ch = p_string[pi];
        while (ch != ')') 
        {
          pi2++;
          pi++;
          ch = p_string[pi];
        }

        pi++;
        ch = p_string[pi];
        while(ch != '(')
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        pi++;
        ch = p_string[pi];
        while (ch != ' ') 
        {
          field7[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field7[pi2] = '\0';

        ch = p_string[pi];
        while(ch == ' ')
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        ch = p_string[pi];
        while (ch != ' ') 
        {
          field8[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field8[pi2] = '\0';

        pi2 = 0;
        ch = p_string[pi];
        while (ch != ')') 
        {
          if(ch != ' ')
          {
            field9[pi2] = ch;
            pi2++;
          }
          pi++;
          ch = p_string[pi];
        }
        field9[pi2] = '\0';

        operand_1 = 0;
        if (operand_1 == 0) 
        {
          p = strstr(field4, "==");
          if (p)
          {
            operand_1 = 1;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field4, "!=");
          if (p)
          {
            operand_1 = 2;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field4, "<=");
          if (p)
          {
            operand_1 = 3;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field4, ">=");
          if (p)
          {
            operand_1 = 4;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field4, "=");
          if (p)
          {
            operand_1 = 5;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field4, "<");
          if (p)
          {
            operand_1 = 6;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field4, ">");
          if (p)
          {
            operand_1 = 7;
          }
        }

        operand_2 = 0;
        if (operand_1 == 0) 
        {
          p = strstr(field8, "==");
          if (p)
          {
            operand_2 = 1;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field8, "!=");
          if (p)
          {
            operand_2 = 2;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field8, "<=");
          if (p)
          {
            operand_2 = 3;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field8, ">=");
          if (p)
          {
            operand_2 = 4;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field8, "=");
          if (p)
          {
            operand_2 = 5;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field8, "<");
          if (p)
          {
            operand_2 = 6;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field8, ">");
          if (p)
          {
            operand_2 = 7;
          }
        }

      wh_3 = 0;
      array_flag = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field1, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field1a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            ret = strcmp(lw_variable[v].lv_type, "A");
            if (ret == 0) 
            {
              array_flag = 1;
              strcpy(ar_field5, gw_variable[v].gv_dsect);
              strcpy(ar_field6, gw_variable[v].gv_label);
              strcpy(ar_field7, gw_variable[v].gv_table);
              strcpy(ar_field8, gw_variable[v].gv_aname);
              strcpy(ar_field9, gw_variable[v].gv_sv_reg);
              strcpy(ar_field10, gw_variable[v].gv_wk_reg);
              strcpy(ar_field11, gw_variable[v].gv_wk_strg);
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field1, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field1a, gw_variable[v].gv_cname);
              ret = strcmp(gw_variable[v].gv_type, "A");
              if (ret == 0) 
              {
                array_flag = 1;
                strcpy(ar_field5, gw_variable[v].gv_dsect);
                strcpy(ar_field6, gw_variable[v].gv_label);
                strcpy(ar_field7, gw_variable[v].gv_table);
                strcpy(ar_field8, gw_variable[v].gv_aname);
                strcpy(ar_field9, gw_variable[v].gv_sv_reg);
                strcpy(ar_field10, gw_variable[v].gv_wk_reg);
                strcpy(ar_field11, gw_variable[v].gv_wk_strg);
                gw_variable[v].gv_flag = 1;
              }
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c while_case_13 while-086 x20 field1 Not Found = %s\n",field1);
        printf("c2z_while.c while_case_13 x20 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field2, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field2a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field2, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field2a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_13 while-087 x20 field2 Not Found = %s\n", field2);
        printf("c2z_while.c c2_while_13 x20 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field3, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field3a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field3, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field3a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_13 while-088 x20 field3 Not Found = %s\n", field3);
        printf("c2z_while.c c2_while_13 x20 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field9, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field9a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field9, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field9a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_13 while-089 x20 field9 Not Found = %s\n", field9);
        printf("c2z_while.c c2_while_13 x20 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #900");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #901");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #902");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R6,");
        strcat(a_string, ar_field7);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #903");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcpy(start_while, a_string);
        check_length();
        strcat(a_string, "DS    0H");
        strcpy(wk_remark, " while    */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #904");
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
          strcpy(trace_1, "c2z_while.c c2_while_13 #905");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field9a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field9);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #906");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #907");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #908");
          trace_rec_3();
        }
 
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "F");
        strcpy(start_while, a_string);
        check_length();
        strcat(a_string, "DS    0H");
        strcpy(wk_remark, " while    */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #909");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field3a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field3);
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #910");
          trace_rec_3();
        }

        strcpy(a_string, "         CLC   0(3,R9),0(R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #911");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #912");
          trace_rec_3();
        }

        if (operand_1 == 1) 			/* ==	*/
        {
          printf("\nc2z_while.c c2_while_13 while-090 operand_1 == Error#1\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 3) 			/* <=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-091 operand_1 <= Error#3\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 4) 			/* >=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-092 operand_1 >= Error#4\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 5) 				/* =	*/
        {
          printf("\nc2z_while.c c2_while_13 while-093 operand_1 = Error#5\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 6) 				/* <	*/
        {
          printf("\nc2z_while.c c2_while_13 while-094 operand_1 < Error#6\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 7) 				/* >	*/
        {
          printf("\nc2z_while.c c2_while_13 while-095 operand_1 > Error#7\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 1) 				/* ==	*/
        {
          printf("\nc2z_while.c c2_while_13 while-096 operand_2 == Error#1\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 2) 				/* !=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-097 operand_2 != Error#3\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 3) 				/* <=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-098 operand_2 <= Error#3\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 4) 				/* >=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-099 operand_2 >= Error#4\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 5) 				/* =	*/
        {
          printf("\nc2z_while.c c2_while_13 while-100 operand_2 = Error#5\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        convert = 1;
        return;
        
      }

      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_13 subroutine #21");
        trace_rec_1();
      }

      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi++;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
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
        if(ch != ',')
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
        if (ch != '.') 
        {
          field4[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      field4[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        pi2++;
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

      x2 = 0;
      pi2 = 0;
      while (ch != ')') 
      {
       
        field6[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field6[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        if (ch != '(') 
        {
          field7[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      field7[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        field8[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field8[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi2 = 0;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if (ch != '(') 
        {
          field9[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      field9[pi2] = '\0';
      wh_3 = 0;
      array_flag = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field1, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field1a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            ret = strcmp(lw_variable[v].lv_type, "A");
            if (ret == 0) 
            {
              array_flag = 1;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field1, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field1a, gw_variable[v].gv_cname);
            }
          }
        }
      }


      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c while_case_13 while-101 field1 Not Found = %s\n",field1);
        printf("c2z_while.c while_case_13 #500 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field2, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field2a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field2, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field2a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        for (I = 0; I < m_struc_ct; I++) 
        {
          ret = strcmp(field2, w_struc[I].st_wname);
          if (ret == 0) 
          {
            wh_3 = 1;
            strcpy(field2a, w_struc[I].st_cwname);
            strcpy(field2b, w_struc[I].st_cname);
            array_flag = 1;
            break;
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_13 while-102 field2 Not Found = %s\n", field2);
        printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (array_flag == 1) 
      {
        wh_3 = 0;
        if (lv_ct > 0) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(field3, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              wh_3 = 1;
              strcpy(field3a, lw_variable[v].lv_cname);
              lw_variable[v].lv_use_ct++;
            }
          }
        }

        if (wh_3 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (v = 0; v < gv_ct; v++) 
            {
              wh_4 = strcmp(field3, gw_variable[v].gv_name);
              if (wh_4 == 0) 
              {
                wh_3 = 1;
                strcpy(field5a, gw_variable[v].gv_cname);
                gw_variable[v].gv_use_ct++;
              }
            }
          }
        }

        if (wh_3 == 0) 
        {
          printf("\nc2z_while.c c2_while_13 while-103 field3 Not Found = %s\n",field3);
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        operand_1 = 0;
        if (operand_1 == 0) 
        {
          p = strstr(field4, "==");
          if (p)
          {
            operand_1 = 1;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field4, "!=");
          if (p)
          {
            operand_1 = 2;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field4, "<=");
          if (p)
          {
            operand_1 = 3;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field4, ">=");
          if (p)
          {
            operand_1 = 4;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field4, "=");
          if (p)
          {
            operand_1 = 5;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field4, "<");
          if (p)
          {
            operand_1 = 6;
          }
        }

        if (operand_1 == 0) 
        {
          p = strstr(field4, ">");
          if (p)
          {
            operand_1 = 7;
          }
        }

        wh_3 = 0;
        if (lv_ct > 0) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(field7, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              wh_3 = 1;
              strcpy(field7a, lw_variable[v].lv_cname);
              lw_variable[v].lv_use_ct++;
            }
          }
        }

        if (wh_3 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (v = 0; v < gv_ct; v++) 
            {
              wh_4 = strcmp(field7, gw_variable[v].gv_name);
              if (wh_4 == 0) 
              {
                wh_3 = 1;
                strcpy(field7a, gw_variable[v].gv_cname);
                gw_variable[v].gv_use_ct++;
              }
            }
          }
        }

        if (wh_3 == 0) 
        {
          printf("\nc2z_while.c c2_while_13 while-104 field7 Not Found = %s\n",field7);
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        wh_3 = 0;
        if (lv_ct > 0) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(field9, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              wh_3 = 1;
              strcpy(field9a, lw_variable[v].lv_cname);
              lw_variable[v].lv_use_ct++;
            }
          }
        }

        if (wh_3 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (v = 0; v < gv_ct; v++) 
            {
              wh_4 = strcmp(field9, gw_variable[v].gv_name);
              if (wh_4 == 0) 
              {
                wh_3 = 1;
                strcpy(field9a, gw_variable[v].gv_cname);
                gw_variable[v].gv_use_ct++;
              }
            }
          }
        }

        if (wh_3 == 0) 
        {
          printf("\nc2z_while.c c2_while_13 while-105 field9 Not Found = %s\n",field9);
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        operand_2 = 0;
        if (operand_2 == 0) 
        {
          p = strstr(field7, "==");
          if (p)
          {
            operand_2 = 1;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field7, "!=");
          if (p)
          {
            operand_2 = 2;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field7, "<=");
          if (p)
          {
            operand_2 = 3;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field7, ">=");
          if (p)
          {
            operand_2 = 4;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field7, "=");
          if (p)
          {
            operand_2 = 5;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field7, "<");
          if (p)
          {
            operand_2 = 6;
          }
        }

        if (operand_2 == 0) 
        {
          p = strstr(field7, ">");
          if (p)
          {
            operand_2 = 7;
          }
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #300");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #301");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #302");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R6,");
        strcat(a_string, ar_field7);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #303");
          trace_rec_3();
        }

        strcpy(a_string, "         LA    ");
        strcat(a_string, "R6,");
        strcat(a_string, ar_field6);
        strcat(a_string, "(R0,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #304");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcpy(start_while, a_string);
        check_length();
        strcat(a_string, "DS    0H");
        strcpy(wk_remark, " while    */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #305");
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
          strcpy(trace_1, "c2z_while.c c2_while_13 #306");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #307");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #308");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "F");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #309");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #310");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #311");
          trace_rec_3();
        }

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #312");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #313");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "F");
        strcpy(start_while, a_string);
        check_length();
        strcat(a_string, "DS    0H");
        strcpy(wk_remark, " while    */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #314");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field3a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field3);
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #315");
          trace_rec_3();
        }

        strcpy(a_string, "         CLC   0(3,R9),0(R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #316");
          trace_rec_3();
        }

        strcpy(a_string, "         JLNE  L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #317");
          trace_rec_3();
        }

        if (operand_1 == 1) 			/* ==	*/
        {
          printf("\nc2z_while.c c2_while_13 while-106 operand_1 == Error#1\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 3) 			/* <=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-107 operand_1 <= Error#3\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 4) 			/* >=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-108 operand_1 >= Error#4\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 5) 				/* =	*/
        {
          printf("\nc2z_while.c c2_while_13 while-109 operand_1 = Error#5\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 6) 				/* <	*/
        {
          printf("\nc2z_while.c c2_while_13 while-110 operand_1 < Error#6\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_1 == 7) 				/* >	*/
        {
          printf("\nc2z_while.c c2_while_13 while-111 operand_1 > Error#7\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 1) 				/* ==	*/
        {
          printf("\nc2z_while.c c2_while_13 while-112 operand_2 == Error#1\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 2) 				/* !=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-113 operand_2 != Error#3\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 3) 				/* <=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-114 operand_2 <= Error#3\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 4) 				/* >=	*/
        {
          printf("\nc2z_while.c c2_while_13 while-115 operand_2 >= Error#4\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 5) 				/* =	*/
        {
          printf("\nc2z_while.c c2_while_13 while-116 operand_2 = Error#5\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        if (operand_2 == 6)					 /* <	*/
        {
          strcpy(a_string, "         LARL  R9,");
          strcat(a_string, field6a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, field6);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_13 #318");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, field8a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, field8);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_13 #319");
            trace_rec_3();
          }

          strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_13 #320");
            trace_rec_3();
          }

          strcpy(a_string, "         JLH   L");
          snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
          strcat(a_string, wk_strg);
          strcat(a_string, "E");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_while.c c2_while_13 #321");
            trace_rec_3();
          }
        }

        if (operand_2 == 7) 				/* >	*/
        {
          printf("\nc2z_while.c c2_while_13 while-117 operand_2 > Error#7\n");
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }
      }
    }

    if (x17 > x18) 						/* strcmp on right side of && */
    {
      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi++;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      /* now determine type of variables then strcmp or strcmp then variables    */
      /*   while((ndx < imax_vars) && (strcmp(in_stack[ndx], varname) != 0))  or */
      /*   while((strcmp(in_stack[ndx], varname) != 0) && (ndx < imax_vars))     */

      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
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
      while (ch != ' ') 
      {
        if (ch == '(') 
        {
          break;
        }
        field1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
      field2[pi2] = '\0';

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
        field3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field3[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      while (ch != ' ') 
      {
        if (ch == '(') 
        {
          break;
        }
        field4[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field4[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      x33 = 0;
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != '(') 
      {
        if (ch == '[') 
        {
          x33 = 1;
          break;
        }
        pi2++;
        pi++;
        ch = p_string[pi];
      }
 
      if (x33 == 1)
      {
        goto skip_while_13;
      }

      x34 = 0;
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != '[') 
      {
        if (ch == ',') 
        {
          break;
        }
        field6[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field6[pi2] = '\0';
      x34 = 1;

    skip_while_13:

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ']') 
      {
        if (ch == '[') 
        {
          break;
        }
        if (ch != ' ') 
        {
          field7[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      field7[pi2] = '\0';

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if (ch == ']') 
        {
          pi++;
          break;
        }
        if (ch != ',') 
        {
          if (ch != ' ') 
          {
            if (ch != '.') 
            {
              field8[pi2] = ch;
              pi2++;
            }
          }
        }
        pi++;
        ch = p_string[pi];
      }
      field8[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      while (ch != ' ') 
      {
        field9[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field9[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != ')') 
      {
        pi++;
        ch = p_string[pi];
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field1, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field1a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field1, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field1a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_13 while-118 field1 Not Found = %s\n", field1);
        printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field3, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field3a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field3, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field3a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_13 while-119 field3 Not Found = %s\n", field3);
        printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (x34 == 1) 
      {
        wh_3 = 0;
        array_flag = 0;
        if (lv_ct > 0) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(field6, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              wh_3 = 1;
              strcpy(field6a, lw_variable[v].lv_cname);
              lw_variable[v].lv_use_ct++;
              ret = strcmp(lw_variable[v].lv_type, "A");
              if (ret == 0) 
              {
                array_flag = 1;
              }
            }
          }
        }

        if (wh_3 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (v = 0; v < gv_ct; v++) 
            {
              wh_4 = strcmp(field6, gw_variable[v].gv_name);
              if (wh_4 == 0) 
              {
                wh_3 = 1;
                strcpy(field6a, gw_variable[v].gv_cname);
                ret = strcmp(gw_variable[v].gv_type, "A");
                if (ret == 0) 
                {
                  strcpy(ar_field5, gw_variable[v].gv_dsect);
                  strcpy(ar_field6, gw_variable[v].gv_label);
                  strcpy(ar_field7, gw_variable[v].gv_table);
                  strcpy(ar_field8, gw_variable[v].gv_aname);
                  strcpy(ar_field9, gw_variable[v].gv_sv_reg);
                  strcpy(ar_field10, gw_variable[v].gv_wk_reg);
                  strcpy(ar_field11, gw_variable[v].gv_wk_strg);
                  gw_variable[v].gv_flag = 1;
                  gw_variable[v].gv_use_ct++;
                  array_flag = 1;
                }
              }
            }
          }
        }

        if (wh_3 == 0) 
        {
          printf("\nc2z_while.c c2_while_13 while-120 field6 Not Found = %s\n",field6);
          printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }
      }

      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field8, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field8a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field8, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field8a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_13 while-121 field8 Not Found = %s\n", field8);
        printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (array_flag == 1) /*  array field		*/
      {
        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, ar_field7);
        strcpy(wk_remark, " ");
        strcat(wk_remark, ar_field7);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #200");
          trace_rec_3();
        }
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcpy(while_tag, a_string);
      check_length();
      strcat(a_string, "DS    0H");
      strcpy(wk_remark, " while    */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_13 #201");
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
        strcpy(trace_1, "c2z_while.c c2_while_13 #202");
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
        strcpy(trace_1, "c2z_while.c c2_while_13 #203");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_13 #204");
        trace_rec_3();
      }

      operand_1 = 0;
      if (operand_1 == 0) 
      {
        p = strstr(field2, "==");
        if (p)
        {
          operand_1 = 1;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, "!=");
        if (p)
        {
          operand_1 = 2;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, "<=");
        if (p)
        {
          operand_1 = 3;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, ">=");
        if (p)
        {
          operand_1 = 4;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, "=");
        if (p)
        {
          operand_1 = 5;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, "<");
        if (p)
        {
          operand_1 = 6;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, ">");
        if (p)
        {
          operand_1 = 7;
        }
      }

      if (operand_1 == 1) 					/* ==	*/
      {
        printf("\nc2z_while.c c2_while_13 while-122 operand_1 NOT CODED #204\n");
        printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 2) 					/* !=	*/
      {
        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #205");
          trace_rec_3();
        }
      }

      if (operand_1 == 3) 					/* <=	*/
      {
        printf("\nc2z_while.c c2_while_13 while-123 operand_1 NOT CODED #206\n");
        printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 4) 					/* >=	*/
      {
        printf("\nc2z_while.c c2_while_13 while-124 operand_1 NOT CODED #207\n");
        printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 5) 					/* =	*/
      {
        printf("\nc2z_while.c c2_while_13 while-125 operand_1 NOT CODED #208\n");
        printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 6) 					/* <	*/
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #206");
          trace_rec_3();
        }

        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #207");
          trace_rec_3();
        }
      }

      if (operand_1 == 7) 					/* >	*/
      {
        printf("\nc2z_while.c c2_while_13 while-126 operand_1 NOT CODED #211\n");
        printf("c2z_while.c c2_while_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (array_flag == 1) 					/*  array field		*/
      {
        strcpy(a_string, "         LARL  R9,C370LPCT");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #208");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1)  
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #209");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #210");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "G");
        strcpy(start_while, a_string);
        check_length();
        strcat(a_string, "DS    0H");
        strcpy(wk_remark, " while    */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #211");
          trace_rec_3();
        }

        wh_3 = 0;
        if (lv_ct > 0) 
        {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field8, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(field8a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(field8, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(field8a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
      }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field8a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field8);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #212");
          trace_rec_3();
        }

        strcpy(a_string, "         CLC   0(3,R9),0(R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #213");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #214");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370LPCT");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #215");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #216");
          trace_rec_3();
        }

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #217");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "F");
        strcpy(start_while, a_string);
        check_length();
        strcat(a_string, "DS    0H");
        strcpy(wk_remark, " while    */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_13 #218");
          trace_rec_3();
        }
      }
    }
  }
  convert = 1;
  return;
}

void c2_while_14() 				/* user function		*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_14");
    trace_rec_1();
  }

  char *p;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];
  char tfield8[VAR_LGTH];
  char tfield8a[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield10a[VAR_LGTH];
  char tfield11[VAR_LGTH];
  char tfield11a[VAR_LGTH];
  char wk_sv_func[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int v = 0;
  int wh_3 = 0;
  int wh_4 = 0;
  int while_complex = 0;
  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
  int fd2_type = 0;
  int fd3_type = 0;
  int fd4_type = 0;
  int fd7_type = 0;
  int fd10_type = 0;
  int fd1t = 0;
  int fd3t = 0;
  int fd5t = 0;
  int fd7t = 0;
  int fd8t = 0;
  int fd10t = 0;
  int fd11_type = 0;
  int operand_1 = 0;
  int operand_2 = 0;
  int operand_3 = 0;
  int x20;
  int x21;
  int x22;
  int s;
  int x2 = 0;
  int x101 = 0;
  int x102 = 0;

  p = strstr(p_string, "&&");
  if (p) 
  {
    while_complex = 1;
  }

  p = strstr(p_string, "||");
  if (p) 
  {
    while_complex = 1;
  }

  if (while_complex == 0) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_14 #1");
      trace_rec_1();
    }

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
    while (ch != '(') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';
    strcpy(wk_sv_func, tfield1);

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield2, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield2a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          ret2 = strcmp("C", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd2_type = 1;
          } 
          else 
          {
            fd2_type = 2;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield2, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield2a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            ret2 = strcmp("C", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd2_type = 1;
            } 
            else 
            {
              fd2_type = 2;
            }
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_14 while-127 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield2, lw_variable[v].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield4a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          ret2 = strcmp("C", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd4_type = 1;
          } 
          else 
          {
            fd4_type = 2;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield2, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield4a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            ret2 = strcmp("C", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd4_type = 1;
            } 
            else 
            {
              fd4_type = 2;
            }
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_14 while-128 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(start_while, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    strcpy(wk_remark, " while    */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_14 #4");
      trace_rec_3();
    }

    if ((fd2_type == 1) && (fd4_type == 1)) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield4a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #5");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #6");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #4");
        trace_rec_3();
      }
    }

    if ((fd3_type == 2) && (fd4_type == 2)) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield4a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #5");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield2a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #6");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #7");
        trace_rec_3();
      }
    }

    for (I = 0; I < fn_ct; I++) 
    {
      ret = strcmp(tfield1, w_function[I].fn_name);
      if (ret == 0) 
      {
        strcpy(tfield1a, w_function[I].fn_cname);
        strcpy(tfield11, w_function[I].fn_ret_var);
      }
    }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_14 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_14 #8");
      trace_rec_3();
    }

    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield11, lw_variable[v].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield11a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          ret2 = strcmp("C", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd11_type = 1;
          } 
          else 
          {
            fd11_type = 2;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield11, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield11a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            ret2 = strcmp("C", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd11_type = 1;
            } 
            else 
            {
              fd11_type = 2;
            }
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_14 while-129 tfield11 Not Found = %s\n",tfield11);
      printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd11_type == 2) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield11a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #9");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #10");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #11");
        trace_rec_3();
      }
    }

    if (fd11_type == 1) 
    {
      printf("\nc2z_while.c c2_while_14 while-130 fd2_type == 1 NOT CODED\n");
      printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         JLNE  L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_14 #12");
      trace_rec_3();
    }
  }

  if (while_complex == 1) 
  {
    x20 = 0;
    x21 = 0;
    x22 = 0;
    s = strlen(p_string);
    for(I=0; I < s; I++)
    {
      ch = p_string[I];
      if(ch == '(')
      {
        x20++;
      }
      if(ch == ')')
      {
        x20++;
      }
      if(ch == '[')
      {
        x21++;
      }
      if(ch == ']')
      {
        x21++;
      }
      if(ch == '.')
      {
        x22++;
      }
    }

    if((x20 == 6) && (x21 == 0) && (x22 == 0))	/* while(ch != quote) && (pi < stlen))  */
    {
      pi = 0;
      pi2 = 0;
      ch = p_string[pi];

      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ' ') 
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
        if (ch != '(') 
        {
          tfield1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield1[pi2] = '\0';

      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        tfield2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield2[pi2] = '\0';

      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi2 = 0;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            fd3_type = 1;
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
            fd3_type = 2;
            x2 = 1;
          }
        }
        tfield3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield3[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi2 = 0;
      ch = p_string[pi];
      while (ch != ' ') 
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

        if (ch != '(') 
        {
          tfield5[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield5[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        tfield6[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield6[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi2 = 0;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            fd7_type = 1;
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
            fd7_type = 2;
            x2 = 1;
          }
        }

        tfield7[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield7[pi2] = '\0';

      fd1t = 0;
      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield1, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield1a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            ret2 = strcmp("C", lw_variable[v].lv_type);
            if (ret2 == 0) 
            {
              fd1t = 1;
            } 
            else 
            {
              fd1t = 2;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield1, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield1a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
              ret2 = strcmp("C", gw_variable[v].gv_type);
              if (ret2 == 0) 
              {
                fd1t = 1;
              } 
              else 
              {
                fd1t = 2;
              }
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_14 while-131 tfield1 Not Found = %s\n", tfield1);
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      fd3t = 0;
      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield3, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield3a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            ret2 = strcmp("C", lw_variable[v].lv_type);
            if (ret2 == 0) 
            {
              fd3t = 1;
            } 
            else 
            {
              fd3t = 2;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        fd3t = 0;
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield3, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield3a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
              ret2 = strcmp("C", gw_variable[v].gv_type);
              if (ret2 == 0) 
              {
                fd3t = 1;
              } 
              else 
              {
                fd3t = 2;
              }
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c while_case_14 while-132 tfield3 Not Found = %s\n",tfield3);
        printf("c2z_while.c while_case_14 rct = %d p_string = %s\n",rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      wh_3 = 0;
      fd5t = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield5, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield5a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            ret2 = strcmp("C", lw_variable[v].lv_type);
              if (ret2 == 0) 
              {
                fd5t = 1;
              } 
              else 
              {
                fd5t = 2;
              }
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield5, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield5a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
              ret2 = strcmp("C", gw_variable[v].gv_type);
              if (ret2 == 0) 
              {
                fd5t = 1;
              } 
              else 
              {
                fd5t = 2;
              }
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_14 while-133 tfield5 Not Found = %s\n", tfield5);
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      fd7t = 0;
      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield7, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield7a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            ret2 = strcmp("C", lw_variable[v].lv_type);
            if (ret2 == 0) 
            {
              fd7t = 1;
            } 
            else 
            {
              fd7t = 2;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield7, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield7a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
              ret2 = strcmp("C", gw_variable[v].gv_type);
              if (ret2 == 0) 
              {
                fd7t = 1;
              } 
              else 
              {
                fd7t = 2;
              }
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_14 while-134 tfield7 Not Found = %s\n", tfield7);
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      operand_1 = 0;
      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "==");
        if (p)
        {
          operand_1 = 1;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "!=");
        if (p)
        {
          operand_1 = 2;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "<=");
        if (p)
        {
          operand_1 = 3;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, ">=");
        if (p)
        {
          operand_1 = 4;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "=");
        if (p)
        {
          operand_1 = 5;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "<");
        if (p)
        {
          operand_1 = 6;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, ">");
        if (p)
        {
          operand_1 = 7;
        }
      }

      operand_2 = 0;
      if (operand_2 == 0)  
      {
        p = strstr(tfield6, "==");
        if (p)
        {
          operand_2 = 1;
        }
      }
 
      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "!=");
        if (p)
        {
          operand_2 = 2;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "<=");
        if (p)
        {
          operand_2 = 3;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, ">=");
        if (p)
        {
          operand_2 = 4;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "=");
        if (p)
        {
          operand_2 = 5;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "<");
        if (p)
        {
          operand_2 = 6;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, ">");
        if (p)
        {
          operand_2 = 7;
        }
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcpy(start_while, a_string);
      check_length();
      strcat(a_string, "DS    0H");
      strcpy(wk_remark, " while    */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_15 #199");
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
        strcpy(trace_1, "c2z_while.c c2_while_14 #200");
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
        strcpy(trace_1, "c2z_while.c c2_while_14 #201");
        trace_rec_3();
      }

      if((fd1t == 2) && (fd3t == 2))
      {
        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #202");
          trace_rec_3();
        }
      }

      if(operand_1 == 2)
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #203");
          trace_rec_3();
        }
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #204");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield7a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield7);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #205");
        trace_rec_3();
      }

      if((fd5t == 2) && (fd7t == 2))
      {
        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #206");
          trace_rec_3();
        }
      }

      if(operand_2 == 6)
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #207");
          trace_rec_3();
        }

        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #208");
          trace_rec_3();
        }
      }

      convert = 1;
      return;
    }		/* end of x20 == 6 */
  

    if((x20 == 8) && (x21 == 0) && (x22 == 0))	/* while((tok != 14) && (tok != 15) && (tok != 16))	*/
    {
      pi = 0;
      pi2 = 0;
      ch = p_string[pi];

      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ' ') 
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
        if (ch != '(') 
        {
          tfield1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield1[pi2] = '\0';

      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        tfield2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield2[pi2] = '\0';

      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi2 = 0;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            fd3_type = 1;
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
            fd3_type = 2;
            x2 = 1;
          }
        }
        tfield3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield3[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi2 = 0;
      ch = p_string[pi];
      while (ch != ' ') 
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

        if (ch != '(') 
        {
          tfield5[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield5[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        tfield6[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield6[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi2 = 0;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            fd7_type = 1;
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
            fd7_type = 2;
            x2 = 1;
          }
        }

        tfield7[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield7[pi2] = '\0';

      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ' ') 
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

        tfield8[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield8[pi2] = '\0';

      pi2 = 0;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        pi2++;
        pi++;
        ch = p_string[pi];
      }

      pi++;
      ch = p_string[pi];
      while(ch == ' ')
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        tfield11[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield11[pi2] = '\0';

      while(ch == ' ')
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi2 = 0;
      fd10_type = 0;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            fd10_type = 1;
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
            fd10_type = 2;
            x2 = 1;
          }
        }

        tfield10[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield10[pi2] = '\0';

      fd1t = 0;
      wh_3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield1, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield1a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            ret2 = strcmp("C", lw_variable[v].lv_type);
            if (ret2 == 0) 
            {
              fd1t = 1;
            } 
            else 
            {
              fd1t = 2;
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield1, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield1a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
              ret2 = strcmp("C", gw_variable[v].gv_type);
              if (ret2 == 0) 
              {
                fd1t = 1;
              } 
              else 
              {
                fd1t = 2;
              }
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_14 while-170 tfield1 Not Found = %s\n", tfield1);
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

 
      if(fd3_type == 1)
      {
         wh_3 = 0;
         for (I = 0; I < char_ct; I++) 
         {
           if((rct == w_charlit[I].clit_rct) && (w_charlit[I].clit_uct == 1)) 
           {
             strcpy(tfield3a, w_charlit[I].clit_cname);
             x101 = w_charlit[I].clit_lgth;
             wh_3 = 1;
             break;
           }
         }
         if (wh_3 == 0) 
         {
           printf("\nc2z_while.c c2_while_14 while-175 tfield3 Not Found = %s\n", tfield3);
           printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
           erct++;
           convert = 1;
           return;
         }
       }
     
      if(fd3_type == 2)
      {
        fd3t = 0;
        wh_3 = 0;
        if (lv_ct > 0) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(tfield3, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              wh_3 = 1;
              strcpy(tfield3a, lw_variable[v].lv_cname);
              lw_variable[v].lv_use_ct++;
              ret2 = strcmp("C", lw_variable[v].lv_type);
              if (ret2 == 0) 
              {
                fd3t = 1;
              } 
              else 
              {
                fd3t = 2;
              }
            }
          }
        }

        if (wh_3 == 0) 
        {
          fd3t = 0;
          if (gv_ct > 0) 
          {
            for (v = 0; v < gv_ct; v++) 
            {
              wh_4 = strcmp(tfield3, gw_variable[v].gv_name);
              if (wh_4 == 0) 
              {
                wh_3 = 1;
                strcpy(tfield3a, gw_variable[v].gv_cname);
                gw_variable[v].gv_use_ct++;
                ret2 = strcmp("C", gw_variable[v].gv_type);
                if (ret2 == 0) 
                {
                  fd3t = 1;
                } 
                else 
                {
                  fd3t = 2;
                }
              }
            }
          }
        }

        if (wh_3 == 0) 
        {
          printf("\nc2z_while.c while_case_14 while-171 tfield3 Not Found = %s\n",tfield3);
          printf("c2z_while.c while_case_14 rct = %d p_string = %s\n",rct,p_string);
          erct++;
          convert = 1;
          return;
        }
      }

      wh_3 = 0;
      fd5t = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield5, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield5a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            ret2 = strcmp("C", lw_variable[v].lv_type);
              if (ret2 == 0) 
              {
                fd5t = 1;
              } 
              else 
              {
                fd5t = 2;
              }
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield5, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield5a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
              ret2 = strcmp("C", gw_variable[v].gv_type);
              if (ret2 == 0) 
              {
                fd5t = 1;
              } 
              else 
              {
                fd5t = 2;
              }
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_14 while-172 tfield5 Not Found = %s\n", tfield5);
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if(fd7_type == 1)
      {
         wh_3 = 0;
         for (I = 0; I < char_ct; I++) 
         {
           if((rct == w_charlit[I].clit_rct) && (w_charlit[I].clit_uct == 2)) 
           {
             strcpy(tfield7a, w_charlit[I].clit_cname);
             x102 = w_charlit[I].clit_lgth;
             wh_3 = 1;
             break;
           }
         }

         if (wh_3 == 0) 
         {
           printf("\nc2z_while.c c2_while_14 while-176 tfield7 Not Found = %s\n", tfield7);
           printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
           erct++;
           convert = 1;
           return;
         }
      }

      if(fd7_type == 2)
      {
        fd7t = 0;
        wh_3 = 0;
        if (lv_ct > 0) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(tfield7, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              wh_3 = 1;
              strcpy(tfield7a, lw_variable[v].lv_cname);
              lw_variable[v].lv_use_ct++;
              ret2 = strcmp("C", lw_variable[v].lv_type);
              if (ret2 == 0) 
              {
                fd7t = 1;
              } 
              else 
              {
                fd7t = 2;
              }
            }
          }
        }

        if (wh_3 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (v = 0; v < gv_ct; v++) 
            {
              wh_4 = strcmp(tfield7, gw_variable[v].gv_name);
              if (wh_4 == 0) 
              {
                wh_3 = 1;
                strcpy(tfield7a, gw_variable[v].gv_cname);
                gw_variable[v].gv_use_ct++;
                ret2 = strcmp("C", gw_variable[v].gv_type);
                if (ret2 == 0) 
                {
                  fd7t = 1;
                } 
                else 
                {
                  fd7t = 2;
                }
              }
            }
          }
        }

        if (wh_3 == 0) 
        {
          printf("\nc2z_while.c c2_while_14 while-173 tfield7 Not Found = %s\n", tfield7);
          printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
      }

      wh_3 = 0;
      fd8t = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield8, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            wh_3 = 1;
            strcpy(tfield8a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            ret2 = strcmp("C", lw_variable[v].lv_type);
              if (ret2 == 0) 
              {
                fd8t = 1;
              } 
              else 
              {
                fd8t = 2;
              }
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            wh_4 = strcmp(tfield8, gw_variable[v].gv_name);
            if (wh_4 == 0) 
            {
              wh_3 = 1;
              strcpy(tfield8a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
              ret2 = strcmp("C", gw_variable[v].gv_type);
              if (ret2 == 0) 
              {
                fd8t = 1;
              } 
              else 
              {
                fd8t = 2;
              }
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_while.c c2_while_14 while-179 tfield8 Not Found = %s\n", tfield8);
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if(fd10_type == 1)
      {
         wh_3 = 0;
         for (I = 0; I < char_ct; I++) 
         {
           if((rct == w_charlit[I].clit_rct) && (w_charlit[I].clit_uct == 3)) 
           {
             strcpy(tfield10a, w_charlit[I].clit_cname);
             wh_3 = 1;
             break;
           }
         }

           if (wh_3 == 0) 
           {
             printf("\nc2z_while.c c2_while_14 while-177 tfield7 Not Found = %s\n", tfield10);
             printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
             erct++;
             convert = 1;
             return;
           }
      }

      if(fd10_type == 2)
      {
        fd10t = 0;
        wh_3 = 0;
        if (lv_ct > 0) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(tfield10, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              wh_3 = 1;
              strcpy(tfield10a, lw_variable[v].lv_cname);
              lw_variable[v].lv_use_ct++;
              ret2 = strcmp("C", lw_variable[v].lv_type);
              if (ret2 == 0) 
              {
                fd10t = 1;
              } 
              else 
              {
                fd10t = 2;
              }
            }
          }
        }

        if (wh_3 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (v = 0; v < gv_ct; v++) 
            {
              wh_4 = strcmp(tfield10, gw_variable[v].gv_name);
              if (wh_4 == 0) 
              {
                wh_3 = 1;
                strcpy(tfield10a, gw_variable[v].gv_cname);
                gw_variable[v].gv_use_ct++;
                ret2 = strcmp("C", gw_variable[v].gv_type);
                if (ret2 == 0) 
                {
                  fd10t = 1;
                } 
                else 
                {
                  fd10t = 2;
                }
              }
            }
          }
        }

        if (wh_3 == 0) 
        {
          printf("\nc2z_while.c c2_while_14 while-178 tfield10 Not Found = %s\n", tfield10);
          printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
      }

      operand_1 = 0;
      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "==");
        if (p)
        {
          operand_1 = 1;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "!=");
        if (p)
        {
          operand_1 = 2;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "<=");
        if (p)
        {
          operand_1 = 3;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, ">=");
        if (p)
        {
          operand_1 = 4;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "=");
        if (p)
        {
          operand_1 = 5;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "<");
        if (p)
        {
          operand_1 = 6;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, ">");
        if (p)
        {
          operand_1 = 7;
        }
      }

      operand_2 = 0;
      if (operand_2 == 0)  
      {
        p = strstr(tfield6, "==");
        if (p)
        {
          operand_2 = 1;
        }
      }
 
      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "!=");
        if (p)
        {
          operand_2 = 2;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "<=");
        if (p)
        {
          operand_2 = 3;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, ">=");
        if (p)
        {
          operand_2 = 4;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "=");
        if (p)
        {
          operand_2 = 5;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "<");
        if (p)
        {
          operand_2 = 6;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, ">");
        if (p)
        {
          operand_2 = 7;
        }
      }

      operand_3 = 0;
      if (operand_3 == 0)  
      {
        p = strstr(tfield11, "==");
        if (p)
        {
          operand_3 = 1;
        }
      }
 
      if (operand_3 == 0) 
      {
        p = strstr(tfield11, "!=");
        if (p)
        {
          operand_3 = 2;
        }
      }

      if (operand_3 == 0) 
      {
        p = strstr(tfield11, "<=");
        if (p)
        {
          operand_3 = 3;
        }
      }

      if (operand_3 == 0) 
      {
        p = strstr(tfield11, ">=");
        if (p)
        {
          operand_3 = 4;
        }
      }

      if (operand_3 == 0) 
      {
        p = strstr(tfield11, "=");
        if (p)
        {
          operand_3 = 5;
        }
      }

      if (operand_3 == 0) 
      {
        p = strstr(tfield11, "<");
        if (p)
        {
          operand_3 = 6;
        }
      }

      if (operand_3 == 0) 
      {
        p = strstr(tfield11, ">");
        if (p)
        {
          operand_3 = 7;
        }
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcpy(start_while, a_string);
      check_length();
      strcat(a_string, "DS    0H");
      strcpy(wk_remark, " while    */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_15 #200");
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
        strcpy(trace_1, "c2z_while.c c2_while_14 #201");
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
        strcpy(trace_1, "c2z_while.c c2_while_14 #202");
        trace_rec_3();
      }

      if((fd1t == 2) && (fd3t == 2))
      {
        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #203");
          trace_rec_3();
        }
      }

      if((fd1t == 2) && (fd3t == 1))
      {
        strcpy(a_string, "         CLC   0(");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
        strcat(a_string, wk_strg);
        strcat(a_string, ",R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #204");
          trace_rec_3();
        }
      }

      if (operand_1 == 1) 				/* ==	*/
      {
        printf("\nc2z_while.c c2_while_14 while-180 operand_1 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if(operand_2 == 2)				/* != */
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #205");
          trace_rec_3();
        }
      }

      if (operand_1 == 3) 				/* <=	*/
      {
        printf("\nc2z_while.c c2_while_14 while-181 operand_1 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 4) 				/* >=	*/
      {
        printf("\nc2z_while.c c2_while_14 while-182 operand_1 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 5) 				/* 	*/
      {
        printf("\nc2z_while.c c2_while_14 while-183 operand_1 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 6) 				/* < */
      {
        printf("\nc2z_while.c c2_while_14 while-184 operand_1 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 7) 				/* > */
      {
        printf("\nc2z_while.c c2_while_14 while-185 operand_1 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #206");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield7a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield7);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #207");
        trace_rec_3();
      }

      if((fd5t == 2) && (fd7t == 2))
      {
        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #208");
          trace_rec_3();
        }
      }

      if((fd5t == 2) && (fd7t == 1))
      {
        strcpy(a_string, "         CLC   0(");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x102);
        strcat(a_string, wk_strg);
        strcat(a_string, ",R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #209");
          trace_rec_3();
        }
      }

      if (operand_2 == 1) 				/* ==	*/
      {
        printf("\nc2z_while.c c2_while_14 while-186 operand_2 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if(operand_2 == 2)				/* != */
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #208");
          trace_rec_3();
        }
      }

      if (operand_2 == 3) 				/* <=	*/
      {
        printf("\nc2z_while.c c2_while_14 while-181 operand_2 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 4) 				/* >=	*/
      {
        printf("\nc2z_while.c c2_while_14 while-182 operand_2 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 5) 				/* 	*/
      {
        printf("\nc2z_while.c c2_while_14 while-183 operand_2 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 6) 				/* < */
      {
        printf("\nc2z_while.c c2_while_14 while-184 operand_2 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 7) 				/* > */
      {
        printf("\nc2z_while.c c2_while_14 while-185 operand_2 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }


      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield8a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield8);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #209");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield10a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield10);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_while.c c2_while_14 #210");
        trace_rec_3();
      }

      if((fd8t == 2) && (fd10t == 2))
      {
        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #211");
          trace_rec_3();
        }
      }

      if((fd8t == 2) && (fd10t == 1))
      {
        strcpy(a_string, "         CLC   0(");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x102);
        strcat(a_string, wk_strg);
        strcat(a_string, ",R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #212");
          trace_rec_3();
        }
      }

      if (operand_3 == 1) 				/* ==	*/
      {
        printf("\nc2z_while.c c2_while_14 while-187 operand_3 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if(operand_2 == 2)				/* != */
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_14 #213");
          trace_rec_3();
        }
      }

      if (operand_2 == 3) 				/* <=	*/
      {
        printf("\nc2z_while.c c2_while_14 while-188 operand_3 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 4) 				/* >=	*/
      {
        printf("\nc2z_while.c c2_while_14 while-189 operand_3 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 5) 				/* 	*/
      {
        printf("\nc2z_while.c c2_while_14 while-190 operand_3 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 6) 				/* < */
      {
        printf("\nc2z_while.c c2_while_14 while-191 operand_3 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 7) 				/* > */
      {
        printf("\nc2z_while.c c2_while_14 while-192 operand_3 == Not Coded\n");
        printf("c2z_while.c c2_while_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      convert = 1;
      return;
    }         /* end of x20 == 8     */
  }		/* end of complex == 1 */
}		/* end of while_14     */



void c2_while_15() 					/* complex non function		*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_15");
    trace_rec_1();
  }

  int pi = 0;
  int pi2 = 0;
  int x2 = 0;

  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
  int fd1_type = 0;
  int fd1_var = 0;
  int fd3_type = 0;
  int fd5_var = 0;
  int fd7_type = 0;
  int fd7_var = 0;
  int operand_1 = 0;
  int operand_2 = 0;
  int wh_3 = 0;
  int wh_4 = 0;
  int v = 0;
  int I = 0;

  char *p;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
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
  while (ch != ' ') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (x2 == 0) 
    {
      if (isdigit(ch)) 
      {
        fd3_type = 1;
        x2 = 1;
      }
      if (isalpha(ch)) 
      {
        fd3_type = 2;
        x2 = 1;
      }
    }
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
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
  while (ch != ' ') 
  {
    tfield5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield5[pi2] = '\0';

  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    tfield6[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield6[pi2] = '\0';

  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (x2 == 0) 
    {
      if (isdigit(ch)) 
      {
        fd7_type = 1;
        x2 = 1;
      }
      if (isalpha(ch)) 
      {
        fd7_type = 2;
        x2 = 1;
      }
    }
    tfield7[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield7[pi2] = '\0';

  operand_1 = 0;
  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "==");
    if (p)
    {
      operand_1 = 1;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "!=");
    if (p)
    {
      operand_1 = 2;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "<=");
    if (p)
    {
      operand_1 = 3;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, ">=");
    if (p)
    {
      operand_1 = 4;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "=");
    if (p)
    {
      operand_1 = 5;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "<");
    if (p)
    {
      operand_1 = 6;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, ">");
    if (p)
    {
      operand_1 = 7;
    }
  }

  operand_2 = 0;
  if (operand_2 == 0) 
  {
    p = strstr(tfield6, "==");
    if (p)
    {
      operand_2 = 1;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(tfield6, "!=");
    if (p)
    {
      operand_2 = 2;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(tfield6, "<=");
    if (p)
    {
      operand_2 = 3;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(tfield6, ">=");
    if (p)
    {
      operand_2 = 4;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(tfield6, "=");
    if (p)
    {
      operand_2 = 5;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(tfield6, "<");
    if (p)
    {
      operand_2 = 6;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(tfield6, ">");
    if (p)
    {
      operand_2 = 7;
    }
  }

  wh_3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        wh_3 = 1;
        strcpy(tfield1a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        ret2 = strcmp("I", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd1_var = 1;
        }
        ret2 = strcmp("C", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd1_var = 2;
        }
      }
    }
  }

  if (wh_3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        wh_4 = strcmp(tfield1, gw_variable[v].gv_name);
        if (wh_4 == 0) 
        {
          wh_3 = 1;
          strcpy(tfield1a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
          ret2 = strcmp("I", gw_variable[v].gv_type);
          if (ret2 == 0) 
          {
            fd1_var = 1;
          }
          ret2 = strcmp("C", gw_variable[v].gv_type);
          if (ret2 == 0) 
          {
            fd1_var = 2;
          }
        }
      }
    }
  }

  if (wh_3 == 0) 
  {
    printf("\nc2z_while.c c2_while_15 while-136 tfield1 Not Found %s\n", tfield1);
    printf("c2z_while.c c2_while_15 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (fd3_type == 2) 
  {
    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield3, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield3a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield3, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield3a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_15 while-137 tfield3 Not Found %s\n", tfield3);
      printf("c2z_while.c c2_while_15 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  wh_3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield5, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        wh_3 = 1;
        strcpy(tfield5a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        ret2 = strcmp("I", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd5_var = 1;
        }
        ret2 = strcmp("C", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd5_var = 2;
        }
      }
    }
  }

  if (wh_3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        wh_4 = strcmp(tfield5, gw_variable[v].gv_name);
        if (wh_4 == 0) 
        {
          wh_3 = 1;
          strcpy(tfield5a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
        }
      }
    }
  }

  if (wh_3 == 0) 
  {
    printf("\nc2z_while.c c2_while_15 while-138 tfield5 Not Found %s\n", tfield5);
    printf("c2z_while.c c2_while_15 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (fd7_type == 2) 
  {
    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield7, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield7a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd7_var = 1;
          }
          ret2 = strcmp("C", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd7_var = 2;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield7, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield7a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd7_var = 1;
            }
            ret2 = strcmp("C", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd7_var = 2;
            }
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c c2_while_15 while-139 tfield7 Not Found %s\n", tfield7);
      printf("c2z_while.c c2_while_15 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcpy(start_while, a_string);
  check_length();
  strcat(a_string, "DS    0H");
  strcpy(wk_remark, " while    */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_15 #1");
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
    strcpy(trace_1, "c2z_while.c c2_while_15 #2");
    trace_rec_3();
  }

  if (fd3_type == 2) 
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_15 #3");
      trace_rec_3();
    }
  }

  if (fd3_type == 1) 
  {





/*
    for (I = 0; I < math_lit_ct; I++) 
    {
      if ((rct == w_mathlit[I].lit_rct) && (w_mathlit[I].lit_uct == 1)) 
      {
        break;
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, w_mathlit[I].lit_cname);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_15 #4");
      trace_rec_3();
    }
*/
printf("FIX FIX FIX\n");
printf("rct = %d p_string = %s",rct,p_string);


  }

  if (fd3_type == 0) 
  {
    for (I = 0; I < char_ct; I++) 
    {
      if ((rct == w_charlit[I].clit_rct) && (w_charlit[I].clit_uct == 1)) 
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, w_charlit[I].clit_cname);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_while.c c2_while_15 #5");
          trace_rec_3();
        }
        break;
      }
    }
  }

  if ((fd1_type == 1) && (fd3_type == 1)) 
  {
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_15 #6");
      trace_rec_3();
    }
  }

  if ((fd1_var == 2) && (fd3_type == 2)) 
  {
    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_15 #7");
      trace_rec_3();
    }
  }

  if ((fd1_var == 2) && (fd3_type == 0)) 
  {
    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_15 #8");
      trace_rec_3();
    }
  }

  if (operand_1 == 1) 				/* ==	*/
  {
    printf("\nc2z_while.c c2_while_15 while-140 operand_1 == Not Coded\n");
    printf("c2z_while.c c2_while_15 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 2) 				/* !=	*/
  {
    strcpy(a_string, "         JLE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_15 #9");
      trace_rec_3();
    }
  }

  if (operand_1 == 3) 				/* <=	*/
  {
    printf("\nc2z_while.c c2_while_15 while-141 operand_1 <= Not Coded\n");
    printf("c2z_while.c c2_while_15 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 4) 				/* >=	*/
  {
    printf("\nc2z_while.c c2_while_15 while-142 operand_1 >= Not Coded\n");
    printf("c2z_while.c c2_while_15 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 6) 				/* <	*/
  {
    printf("\nc2z_while.c c2_while_15 while-143 operand_1 <  Not Coded\n");
    printf("c2z_while.c c2_while_15 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 7) 				/* ><	*/
  {
    printf("\nc2z_while.c c2_while_15 while-144 operand_1 >  Not Coded\n");
    printf("c2z_while.c c2_while_15 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield5a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield5);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_15 #10");
    trace_rec_3();
  }

  if (fd7_type == 2) 
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield7a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield7);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_15 #11");
      trace_rec_3();
    }
  }

  if (fd7_type == 1) 
  {
/*
    for (I = 0; I < math_lit_ct; I++) 
    {
      if ((rct == w_mathlit[I].lit_rct) && (w_mathlit[I].lit_uct == 2)) 
      {
        break;
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, w_mathlit[I].lit_cname);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_15 #12");
      trace_rec_3();
    }
*/

printf("FIX FIX FIX\n");
printf("rct = %d p_string = %s",rct,p_string);

  }

  if ((fd5_var == 1) && (fd7_var == 1)) 
  {
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_15 #13");
      trace_rec_3();
    }
  }

  if (operand_2 == 1) 				/* ==	*/
  {
    printf("\nc2z_while.c c2_while_15 while-145 operand_2 == Not Coded\n");
    printf("c2z_while.c c2_while_15 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_2 == 2) 				/* !=	*/
  {
    strcpy(a_string, "         JLE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_15 #14");
      trace_rec_3();
    }
  }

  if (operand_2 == 3) 				/* <=	*/
  {
    printf("c2z_while.c c2_while_15 while-146 operand_2 <= Not Coded\n");
    c2_error();
  }

  if (operand_2 == 4)				 /* >=	*/
  {
    printf("c2z_while.c c2_while_15 while-147 operand_2 >= Not Coded\n");
    c2_error();
  }

  if (operand_2 == 6) 				/* <	*/
  {
    strcpy(a_string, "         JLE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_15 #15");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_15 #16");
      trace_rec_3();
    }
  }

  if (operand_2 == 7) 					/* ><	*/
  {
    printf("c2z_while.c c2_while_15 while-148 operand_2 >  Not Coded\n");
    c2_error();
  }

  convert = 1;
}

void c2_while_16() 				/* complex non function with 2 groups of &&		*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_16 START");
    trace_rec_1();
  }

  int pi = 0;
  int pi2 = 0;
  int x2 = 0;

  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
  int fd1_type = 0;
  int fd3_type = 0;
  int fd5_type = 0;
  int fd7_type = 0;
  int fd9_type = 0;
  int fd11_type = 0;
  int cd3_type = 0;
  int cd7_type = 0;
  int cd11_type = 0;
  int operand_1 = 0;
  int operand_2 = 0;
  int operand_3 = 0;
  int wh_3 = 0;
  int wh_4 = 0;
  int v = 0;

  char *p;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield9a[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield11[VAR_LGTH];
  char tfield11a[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
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
  while (ch != ' ') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (x2 == 0) 
    {
      if (isdigit(ch)) 
      {
        fd3_type = 1;
        cd3_type = 1;
        x2 = 1;
      }

      if (isalpha(ch)) 
      {
        fd3_type = 2;
        cd3_type = 2;
        x2 = 1;
      }
    }
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
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
  while (ch != ' ') 
  {
    tfield5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield5[pi2] = '\0';

  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    tfield6[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield6[pi2] = '\0';

  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (x2 == 0) {
      if (isdigit(ch)) 
      {
        fd7_type = 1;
        cd7_type = 1;
        x2 = 1;
      }

      if (isalpha(ch)) 
      {
        fd7_type = 2;
        cd7_type = 2;
        x2 = 1;
      }
    }
    tfield7[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield7[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
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

  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    tfield9[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield9[pi2] = '\0';

  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    tfield10[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield10[pi2] = '\0';

  pi2 = 0;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (ch != ' ') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          fd11_type = 1;
          cd11_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          fd11_type = 2;
          cd11_type = 2;
          x2 = 1;
        }
      }
      tfield11[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield11[pi2] = '\0';

  operand_1 = 0;
  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "==");
    if (p)
    {
      operand_1 = 1;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "!=");
    if (p)
    {
      operand_1 = 2;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "<=");
    if (p)
    {
      operand_1 = 3;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, ">=");
    if (p)
    {
      operand_1 = 4;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "=");
    if (p)
    {
      operand_1 = 5;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, "<");
    if (p)
    {
      operand_1 = 6;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield2, ">");
    if (p)
    {
      operand_1 = 7;
    }
  }

  operand_2 = 0;
  if (operand_2 == 0) 
  {
    p = strstr(tfield6, "==");
    if (p)
    {
      operand_2 = 1;
    }
  }

  if (operand_2 == 0) {
    p = strstr(tfield6, "!=");
    if (p)
      operand_2 = 2;
  }

  if (operand_2 == 0) 
  {
    p = strstr(tfield6, "<=");
    if (p)
    {
      operand_2 = 3;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(tfield6, ">=");
    if (p)
    {
      operand_2 = 4;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(tfield6, "=");
    if (p)
    {
      operand_2 = 5;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(tfield6, "<");
    if (p)
    {
      operand_2 = 6;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(tfield6, ">");
    if (p)
    {
      operand_2 = 7;
    }
  }

  operand_3 = 0;
  if (operand_3 == 0) 
  {
    p = strstr(tfield10, "==");
    if (p)
    {
      operand_3 = 1;
    }
  }

  if (operand_3 == 0) 
  {
    p = strstr(tfield10, "!=");
    if (p)
    {
      operand_3 = 2;
    }
  }

  if (operand_3 == 0) 
  {
    p = strstr(tfield10, "<=");
    if (p)
    {
      operand_3 = 3;
    }
  }

  if (operand_3 == 0) 
  {
    p = strstr(tfield10, ">=");
    if (p)
    {
      operand_3 = 4;
    }
  }

  if (operand_3 == 0) 
  {
    p = strstr(tfield10, "=");
    if (p)
    {
      operand_3 = 5;
    }
  }

  if (operand_3 == 0) 
  {
    p = strstr(tfield10, "<");
    if (p)
    {
      operand_3 = 6;
    }
  }

  if (operand_3 == 0) 
  {
    p = strstr(tfield10, ">");
    if (p)
    {
      operand_3 = 7;
    }
  }

  wh_3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        wh_3 = 1;
        strcpy(tfield1a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        ret2 = strcmp("I", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd1_type = 1;
        }
        ret2 = strcmp("C", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd1_type = 2;
        }
      }
    }
  }

  if (wh_3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        wh_4 = strcmp(tfield1, gw_variable[v].gv_name);
        if (wh_4 == 0) 
        {
          wh_3 = 1;
          strcpy(tfield1a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
          ret2 = strcmp("I", gw_variable[v].gv_type);
          if (ret2 == 0) 
          {
            fd1_type = 1;
          }
          ret2 = strcmp("C", gw_variable[v].gv_type);
          if (ret2 == 0) 
          {
            fd1_type = 2;
          }
        }
      }
    }
  }

  if (wh_3 == 0) 
  {
    printf("\nc2z_while.c while_case_16 while-149 tfield1 Not Found %s\n", tfield1);
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (cd3_type != 1) 
  {
    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield3, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield3a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd3_type = 1;
          }
          ret2 = strcmp("C", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd3_type = 2;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield3, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield3a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd3_type = 1;
            }
            ret2 = strcmp("C", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd3_type = 2;
            }
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c while_case_16 while-150 tfield5 Not Found %s\n", tfield3);
      printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  wh_3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield5, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        wh_3 = 1;
        strcpy(tfield5a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        ret2 = strcmp("I", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd5_type = 1;
        }
        ret2 = strcmp("C", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd5_type = 2;
        }
      }
    }
  }

  if (wh_3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        wh_4 = strcmp(tfield5, gw_variable[v].gv_name);
        if (wh_4 == 0) 
        {
          wh_3 = 1;
          strcpy(tfield5a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
          ret2 = strcmp("I", gw_variable[v].gv_type);
          if (ret2 == 0) 
          {
            fd5_type = 1;
          }
          ret2 = strcmp("C", gw_variable[v].gv_type);
          if (ret2 == 0) 
          {
            fd5_type = 2;
          }
        }
      }
    }
  }

  if (wh_3 == 0) 
  {
    printf("\nc2z_while.c while_case_15 while-151 tfield5 Not Found %s\n", tfield5);
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (cd7_type != 1) 
  {
    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield7, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield7a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd7_type = 1;
          }
          ret2 = strcmp("C", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd7_type = 2;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield7, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield7a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd7_type = 1;
            }
            ret2 = strcmp("C", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd7_type = 2;
            }
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c while_case_15 while-152 tfield7 Not Found %s\n", tfield7);
      printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcpy(start_while, a_string);
  check_length();
  strcat(a_string, "DS    0H");
  strcpy(wk_remark, " while    */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_16 #1");
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
    strcpy(trace_1, "c2z_while.c c2_while_16 #2");
    trace_rec_3();
  }

  if (cd3_type != 1) 
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #3");
      trace_rec_3();
    }
  }

  if (cd3_type == 1) 
  {
    strcpy(a_string, "         LA    R5,");
    strcat(a_string, tfield3);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #5");
      trace_rec_3();
    }
  
    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #7");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #9");
      trace_rec_3();
    }
    fd3_type = 1;
  }

  if ((fd1_type == 1) && (fd3_type == 1)) 
  {
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #10");
      trace_rec_3();
    }
  }

  if ((fd1_type == 2) && (fd3_type == 2)) 
  {
    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #11");
      trace_rec_3();
    }
  }

  if (operand_1 == 1) 				/* ==	*/
  {
    printf("\nc2z_while.c c2_while_15 while-153 operand_1 == Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 2) 				/* !=	*/
  {
    strcpy(a_string, "         JLE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #12");
      trace_rec_3();
    }
  }

  if (operand_1 == 3) 				/* <=	*/
  {
    printf("\nc2z_while.c c2_while_15 while-154 operand_1 <= Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 4) 				/* >=	*/
  {
    printf("\nc2z_while.c c2_while_15 while-155 operand_1 >= Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 6) 				/* <	*/
  {
    printf("\nc2z_while.c c2_while_15 while-156 operand_1 <  Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 7) 				/* ><	*/
  {
    printf("\nc2z_while.c c2_while_15 while-157 operand_1 >  Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++; 
    convert = 1;
    return;
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield5a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_16 #13");
    trace_rec_3();
  }

  if (cd7_type != 1) 
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield7a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #14");
      trace_rec_3();
    }
  }

  if (cd7_type == 1) 
  {
    strcpy(a_string, "         LA    R5,");
    strcat(a_string, tfield7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #16");
      trace_rec_3();
    }
  
    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #18");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #19");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #20");
      trace_rec_3();
    }
    fd7_type = 1;
  }

  if ((fd5_type == 1) && (fd7_type == 1)) 
  {
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #21");
      trace_rec_3();
    }
  }

  if (operand_2 == 1) 				/* ==	*/
  {
    printf("\nc2z_while.c c2_while_15 while-158 operand_2 == Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_2 == 2) 				/* !=	*/
  {
    strcpy(a_string, "         JLE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #22");
      trace_rec_3();
    }
  }

  if (operand_2 == 3) 				/* <=	*/
  {
    printf("\nc2z_while.c c2_while_15 while-159 operand_2 <= Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_2 == 4) 				/* >=	*/
  {
    printf("\nc2z_while.c c2_while_15 while-160 operand_2 >= Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_2 == 6) 				/* <	*/
  {
    strcpy(a_string, "         JLE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #23");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #24");
      trace_rec_3();
    }
  }

  if (operand_2 == 7) 				/* ><	*/
  {
    printf("\nc2z_while.c c2_while_15 while-161 operand_2 >  Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  wh_3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield9, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        wh_3 = 1;
        strcpy(tfield9a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        ret2 = strcmp("I", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd9_type = 1;
        }
        ret2 = strcmp("C", lw_variable[v].lv_type);
        if (ret2 == 0) 
        {
          fd9_type = 2;
        }
      }
    }
  }

  if (wh_3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        wh_4 = strcmp(tfield9, gw_variable[v].gv_name);
        if (wh_4 == 0) 
        {
          wh_3 = 1;
          strcpy(tfield9a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
          ret2 = strcmp("I", gw_variable[v].gv_type);
          if (ret2 == 0) 
          {
            fd5_type = 1;
          }
          ret2 = strcmp("C", gw_variable[v].gv_type);
          if (ret2 == 0) 
          {
            fd5_type = 2;
          }
        }
      }
    }
  }

  if (wh_3 == 0) 
  {
    printf("\nc2z_while.c while_case_15 while-162 tfield9 Not Found %s\n", tfield9);
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (cd11_type != 1) 
  {
    wh_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield11, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          wh_3 = 1;
          strcpy(tfield11a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd7_type = 1;
          }
          ret2 = strcmp("C", lw_variable[v].lv_type);
          if (ret2 == 0) 
          {
            fd7_type = 2;
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(tfield11, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(tfield11a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd11_type = 1;
            }
            ret2 = strcmp("C", gw_variable[v].gv_type);
            if (ret2 == 0) 
            {
              fd11_type = 2;
            }
          }
        }
      }
    }

    if (wh_3 == 0) 
    {
      printf("\nc2z_while.c while_case_15 while-163 tfield11 Not Found %s\n",tfield11);
      printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield9a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_16 #25");
    trace_rec_3();
  }

  if (cd11_type != 1) 
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield11a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #26");
      trace_rec_3();
    }
  }

  if (cd7_type == 1) 
  {
    strcpy(a_string, "         LA    R5,");
    strcat(a_string, tfield11);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #25");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #26");
      trace_rec_3();
    }
  
    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #27");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #28");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #29");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #30");
      trace_rec_3();
    }
    fd11_type = 1;
  }

  if ((fd9_type == 1) && (fd11_type == 1)) 
  {
    strcpy(a_string, "         CP    ");
    strcat(a_string, "0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #31");
      trace_rec_3();
    }
  }

  if (operand_2 == 1) 					/* ==	*/
  {
    printf("\nc2z_while.c c2_while_15 while-164 operand_2 == Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_2 == 2) 					/* !=	*/
  {
    strcpy(a_string, "         JLE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #32");
      trace_rec_3();
    }
  }

  if (operand_2 == 3) 					/* <=	*/
  {
    printf("\nc2z_while.c c2_while_15 while-165 operand_2 <= Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_2 == 4) 					/* >=	*/
  {
    printf("\nc2z_while.c c2_while_15 while-166 operand_2 >= Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_2 == 6) 					/* <	*/
  {
    strcpy(a_string, "         JLE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #33");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_while.c c2_while_16 #34");
      trace_rec_3();
    }
  }

  if (operand_2 == 7) 					/* ><	*/
  {
    printf("\nc2z_while.c c2_while_15 while-167 operand_2 >  Not Coded\n");
    printf("c2z_while.c while_case_16 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  convert = 1;
  return;
}

void c2_while_20() 				/* complex with strchr			*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_while.c c2_while_20 START");
    trace_rec_1();
  }

  printf("\nc2z_while.c c2_while_20 while-168 rct = %d p_string = %s", rct, p_string);
  printf("c2z_while.c c2_while_20 FIX THIS CODE\n");
  erct++;
  convert = 1;
  return;
}
