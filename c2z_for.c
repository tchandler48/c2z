/* ***************************************************
*  c2z : c2Z_for.c :                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out FOR statement                           *
* ************************************************** */
void c2_for(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_for.c c2_for START");
    trace_rec_1();
  }

  char ch;
  char *p, *p6;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];

  inside_for = 1;
  for_opr = 0;

  tfield1[0] = '\0';
  tfield2[0] = '\0';
  tfield3[0] = '\0';
  tfield4[0] = '\0';
  tfield5[0] = '\0';
  tfield6[0] = '\0';

  tfield1a[0] = '\0';
  tfield3a[0] = '\0';
  tfield5a[0] = '\0';
  tfield6a[0] = '\0';

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int I = 0;
  int x = 0;
  int v = 0;
  int x10 = 0;
  int x11 = 0;
  int x20 = 0;
  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
  int fd1_type = 0;
  int fd2_type = 0;
  int fd3_type = 0;
  int fd5_type = 0;
  int fd7_type = 0;

  pi = 0;
  ch = p_string[pi];

  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  x10 = 0;
  p = strstr(p_string, "(;");
  if (p) 
  {
    x10 = 1;
  }

  if (x10 == 0)
  {
    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '=') 
    {
      if (ch != ' ') 
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd1_type = 1;
            x2 = 1;
          }

          if (isdigit(ch)) 
          {
            fd1_type = 2;
            x2 = 1;
          }
        }
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        ret2 = strcmp(lw_variable[I].lv_type, "I");
        if (ret2 != 0) 
        {
          printf("\nc2z_for.c c2_for E-54 tfield1 Not Numeric %s\n", tfield1);
          printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          ret1 = strcmp(gw_variable[I].gv_type, "I");
          if (ret1 != 0) 
          {
            printf("\nc2z_for.c c2_for E-55 tfield1 Not Numeric %s\n", tfield1);
            printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for E-56 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

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
            fd2_type = 2;
            x2 = 1;
          }
        }
        tfield2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';
    inside_for = 1;

    strcpy(a_string, "         LARL  R9,C370LPCT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #1");
      trace_rec_3();
    }
    work_use_ct[73]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #3");
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
      strcpy(trace_1, "c2z_for.c c2_for #4");
      trace_rec_3();
    }
 
    if (fd2_type == 1) 
    {
      x3 = 0;
      x2 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          ret2 = strcmp("I", lw_variable[I].lv_type);
          if (ret2 != 0) 
          {
            printf("\nc2z_for.c c2_for E-60 tfield2 Not Numeric %s\n", tfield2);
            printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }
          x3 = 1;
          strcpy(tfield2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
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
            ret1 = strcmp(gw_variable[I].gv_type, "I");
            if (ret1 != 0) 
            {
              printf("\nc2z_for.c c2_for E-61 tfield2 Not Numeric %s\n", tfield2);
              printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
              erct++;
              convert = 1;
              return;
            }
            x3 = 1;
            strcpy(tfield2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_for.c c2_for E-62 tfield5 Not Found = %s\n", tfield5);
        printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
  
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #5");
        trace_rec_3();
      }
    }

    if (fd2_type == 2) 
    {
      ret = strcmp("0", tfield2);
      if (ret == 0) 
      {
        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_for.c c2_for #6");
          trace_rec_3();
        }
        x = 1;
      } 
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #8");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #9");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #10");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #11");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #12");
      trace_rec_3();
    }
  }
  strcpy(sv_for_return, "L");
  strcat(sv_for_return, wk_strg);


  /* ************************************************
   * for(; From <= Final; From += Inc)              *
   ************************************************ */
  if (x10 == 1)
  {
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c for #13");
      trace_rec_3();
    }

    inside_for = 1;
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  while (ch != ' ') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd3_type = 1;
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        fd3_type = 2;
        x2 = 1;
      }
    }
    if (ch == '<') 
    {
      goto skip_for_1;
    }
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
skip_for_1:
  tfield3[pi2] = '\0';

  x3 = 0;
  x2 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield3, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      ret2 = strcmp("I", lw_variable[I].lv_type);
      if (ret2 != 0) 
      {
        printf("\nc2z_for.c c2_for E-57 tfield3 Not Numeric %s\n", tfield3);
        printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
      x3 = 1;
      strcpy(tfield3a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        ret1 = strcmp("I", gw_variable[I].gv_type);
        if (ret1 != 0) {
          printf("\nc2z_for.c c2_for E-58 tfield3 Not Numeric %s\n", tfield3);
          printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
        x3 = 1;
        strcpy(tfield3a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_for.c c2_for E-59 tfield3 Not Found = %s\n", tfield3);
    printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
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
    if (ch != ';') 
    {
      tfield4[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

  for_opr = 0;
  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "<=");
    if (p6) 
    {
      for_opr = 6;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, ">=");
    if (p6) 
    {
      for_opr = 5;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "<");
    if (p6) 
    {
      for_opr = 4;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, ">");
    if (p6) 
    {
      for_opr = 3;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "!=");
    if (p6) 
    {
      for_opr = 2;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "==");
    if (p6) 
    {
      for_opr = 1;
    }
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  fd5_type = 0;
  pi2 = 0;
  x2 = 0;
  while (ch != ';') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd5_type = 1;
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
        fd5_type = 2;
        x2 = 1;
      }
    }

    if (ch != '+') 
    {
      if (ch != ')') 
      {
        tfield5[pi2] = ch;
        pi2++;
      }
    }

    if (ch == ')') 
    {
      break;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield5[pi2] = '\0';

  x3 = 0;
  if (fd5_type == 1) 
  {
    x2 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield5, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if (ret2 != 0) 
        {
          printf("\nc2z_for.c c2_for E-60 tfield5 Not Numeric %s\n", tfield5);
          printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
        x3 = 1;
        strcpy(tfield5a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield5, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          ret1 = strcmp(gw_variable[I].gv_type, "I");
          if (ret1 != 0) 
          {
            printf("\nc2z_for.c c2_for E-61 tfield5 Not Numeric %s\n", tfield5);
            printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }
          x3 = 1;
          strcpy(tfield5a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for E-62 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (ch == ')') 
  {
    goto skip_for_2;
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x20 = 0;
  pi2 = 0;
  x2 = 0;
  while (ch != ')') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        x2 = 1;
      }
    }

    if (ch == ',') 
    {
      x20 = 1;
      break;
    }

    if (ch == ' ') 
    {
      break;
    }

    if (ch != ' ') 
    {
      if (ch != '+') 
      {
        if (ch != '-') 
        {
          tfield6[pi2] = ch;
          pi2++;
        }
      }
    }
    pi++;
    ch = p_string[pi];
  }
  tfield6[pi2] = '\0';

  if (x20 == 1)   /* for(ii=0; ii < count; ii++, left++)  */
  {
    for_2nd_ct = 0;

    pi2 = 0;
    fd7_type = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '+') 
    {
      if(ch != ' ')
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd7_type = 1;
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
            fd7_type = 2;
            x2 = 1;
          }
        }
        tfield7[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield7[pi2] = '\0';

    x3 = 0;
    x2 = 0; 
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield7, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        ret2 = strcmp(lw_variable[I].lv_type, "I");
        if (ret2 != 0) 
        {  
          printf("\nc2z_for.c c2_for E-63 tfield7 Not Numeric %s\n", tfield7);
          printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
        x3 = 1;
        strcpy(tfield7a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        for_2nd_ct = 1;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield7, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          ret1 = strcmp("I", gw_variable[I].gv_type);
          if (ret1 != 0) 
          {
            printf("\nc2z_for.c c2_for E-164 tfield7 Not Numeric %s\n", tfield7);
            printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1; 
            return;
          }
          x3 = 1;
          strcpy(tfield7a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          for_2nd_ct = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for E-165 tfield7 Not Found = %s\n", tfield7);
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_rct) 
      {
        strcpy(w_for_table[v].for_rt_field2, tfield7a);
      }
    }
  }

  x3 = 0;
  x2 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield6, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      ret2 = strcmp(lw_variable[I].lv_type, "I");
      if (ret2 != 0) 
      {
        printf("\nc2z_for.c c2_for E-63 tfield6 Not Numeric %s\n", tfield3);
        printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
      x3 = 1;
      strcpy(tfield6a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield6, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        ret1 = strcmp("I", gw_variable[I].gv_type);
        if (ret1 != 0) 
        {
          printf("\nc2z_for.c c2_for E-64 tfield6 Not Numeric %s\n", tfield6);
          printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
        x3 = 1;
        strcpy(tfield6a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_for.c c2_for E-65 tfield6 Not Found = %s\n", tfield6);
    printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  v = 0;
  for (v = 0; v < for_ct; v++) 
  {
    if (rct == w_for_table[v].for_rct) 
    {
      strcpy(w_for_table[v].for_rt_field, tfield6a);
    }
  }


skip_for_2:

  x11 = 0;
  p = strstr(p_string, "+=");
  if (p) 
  {
    x11 = 1;
  }

  if (x11 == 1) 
  {
    pi++;
    ch = p_string[pi];
    while(ch != ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    fd7_type = 0;
    pi2 = 0;
    x2 = 0;
   
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd7_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
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

    x3 = 0;
    if (fd7_type == 1) 
    {
      x2 = 0;
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield7, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          ret2 = strcmp("I", lw_variable[I].lv_type);
          if (ret2 != 0) 
          {
            printf("\nc2z_for.c c2_for E-60 tfield7 Not Numeric %s\n", tfield7);
            printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }
          x3 = 1;
          strcpy(tfield7a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        x3 = 0;
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield7, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            ret1 = strcmp(gw_variable[I].gv_type, "I");
            if (ret1 != 0) 
            {
              printf("\nc2z_for.c c2_for E-61 tfield7 Not Numeric %s\n", tfield7);
              printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
              erct++;
              convert = 1;
              return;
            }
            x3 = 1;
            strcpy(tfield7a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_for.c c2_for E-62 tfield7 Not Found = %s\n", tfield7);
        printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }
  }
 
  if (for_opr == 1) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for subroutine #4");
      trace_rec_1();
    }

    if (fd1_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */ ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c for #14");
        trace_rec_3();
      }
    }

    if (fd1_type == 2) 
    {
      printf("\nc2z_for.c c2_for E-66 fd1_type == 2 NOT Coded\n");
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd2_type == 1) 
    {
      printf("\nc2z_for.c c2_for E-67 fd1_type == 1 NOT Coded\n");
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd2_type == 2) 
    {
      x = 0;

      strcpy(a_string, "         LA     R5,");
      strcat(a_string, tfield2);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c for #15");
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
        strcpy(trace_1, "c2z_for.c for #16");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    ");
    strcat(a_string, tfield1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c for #17");
      trace_rec_3();
    }

    strcpy(a_string, "         JNE   ");
    strcat(a_string, while_tag);
    strcat(a_string, "E");
  }

  if (for_opr == 2) 
  {
    strcpy(a_string, "         JLE   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
  }

  if (for_opr == 3) 
  {
    printf("\nc2z_for.c c2_for E-68 for_opr == 3 NOT CODED\n");
    printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (for_opr == 4) 
  {
    if (fd3_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c for #18");
        trace_rec_3();
      }
      strcpy(sv_for_incr, tfield3a);
    }

    if (fd5_type == 2) 
    {
      x = 0;

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield5);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c for #19");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c for #20");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c for #21");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c for #22");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c for #23");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c for #24");
        trace_rec_3();
      }

      x = 1;
    }

    if (fd5_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #25");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #26");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #27");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #28");
      trace_rec_3();
    }
  }

  if (for_opr == 5) 
  {
    if (fd3_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #29");
        trace_rec_3();
      }
    }

    if (fd5_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #30");
        trace_rec_3();
      }
    }

    if (fd5_type == 2) 
    {
      x = 0;
      ret = strcmp("0", tfield5);
      if(ret == 0)
      {
        strcpy(tfield5a,"C370ZERO");
        x = 1;
      }

      if(x == 0)
      {
        ret = strcmp("1", tfield5);
        if(ret == 0)
        {
          strcpy(tfield5a,"C370ONE");
          x = 1;
        }
      }

      if(x == 1)
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, tfield5a);
        src_line();
        if (puncde == 1) 
        {
           strcpy(trace_1, "c2z_for.c c2_for #30");
           trace_rec_3();
        }
      }

      strcpy(a_string, "         LA     R5,");
      strcat(a_string, tfield6);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #31");
        trace_rec_3();
      }

/*      if(x == 0)
      {
        for (I = 0; I < math_lit_ct; I++) 
        {
          if ((rct == w_mathlit[I].lit_rct) && (w_mathlit[I].lit_uct == 1)) 
          {
            strcpy(a_string, "         LARL  R8,");
            strcat(a_string, w_mathlit[I].lit_cname);
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_for.c c2_for #32");
              trace_rec_3();
            }
            x = 1;
          }
        }
      }
*/
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #31");
      trace_rec_3();
    }

    strcpy(a_string, "         JLL   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #32");
      trace_rec_3();
    }
  }

  if (for_opr == 6)
  {
    if (x11 == 0)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #36");
        trace_rec_3();
      }
      strcpy(sv_for_incr, tfield3a);
    }

    if (fd5_type == 2) 
    {
      x = 0;

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield5);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #37");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #38");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #39");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #40");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #41");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #42");
        trace_rec_3();
      }

      x = 1;
    }

    if (fd5_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c c2_for #43");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #44");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c c2_for #45");
      trace_rec_3();
    }
  }

  x3 = 0;
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(tfield1a, gw_variable[I].gv_cname);
    if (ret == 0) 
    {
      x3 = 1;
      gw_variable[I].gv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1a, lw_variable[I].lv_cname);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        lw_variable[I].lv_use_ct++;
      }
    }
  }

  x3 = 0;
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(tfield3a, gw_variable[I].gv_cname);
    if (ret == 0) 
    {
      gw_variable[I].gv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield3a, lw_variable[I].lv_cname);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        lw_variable[I].lv_use_ct++;
      }
    }
  }

  x3 = 0;
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(tfield6a, gw_variable[I].gv_cname);
    if (ret == 0) 
    {
      gw_variable[I].gv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield6a, lw_variable[I].lv_cname);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        lw_variable[I].lv_use_ct++;
      }
    }
  }
}

