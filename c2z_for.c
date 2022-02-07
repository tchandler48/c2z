/* ***************************************************
*  c2z : c2Z_for.c :                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
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
  int pi3;
  int pi4;
  int pi5;
  int pi6;
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
  int fd6_type = 0;
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
      strcpy(trace_1, "c2z_for.c #1");
      trace_rec_3();
    }
    work_use_ct[73]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #3");
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
      strcpy(trace_1, "c2z_for.c #4");
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
        strcpy(trace_1, "c2z_for.c #5");
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
          strcpy(trace_1, "c2z_for.c #6");
          trace_rec_3();
        }
        x = 1;
      } 
      work_use_ct[32]++;
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #7");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #8");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #9");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #10");
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
      strcpy(trace_1, "c2z_for.c #12");
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
    if (ch == ')') 
    {
      break;
    }
    tfield5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield5[pi2] = '\0';

  pi3 = 0;
  p = strstr(tfield5, "+");
  if(p)
  {
    pi3 = 1;
  }
  p = strstr(tfield5, "-");
  if(p)
  {
    pi3 = 2;
  }

  if(pi3 != 0)
  {
    pi4 = 0;
    pi5 = 0;
    pi6 = 0;

    ch = tfield5[pi4];
    while(ch != ' ')
    {
      if(ch == '+')
      {
        break;
      }
      if(pi5 == 0)
      {
        tfield5a[pi6] = ch;
        pi6++;
        pi4++;
        ch = tfield5[pi4];
      }
    }
    tfield5a[pi4] = '\0';

    pi6 = 0;
    pi4++;
    ch = tfield5[pi4];
    while(ch != ' ')
    {
      tfield7[pi6] = ch;
      pi6++;
      pi4++;
      ch = tfield5[pi4];
    }
    tfield7[pi4] = '\0';
    strcpy(tfield5, tfield5a);
  }

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

/*
    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for E-62 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
*/
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

  fd6_type = 0;
  x20 = 0;
  pi2 = 0;
  x2 = 0;
  while (ch != ')') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd6_type = 1;
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        fd6_type = 2;
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

/*
printf("\nc2z_for.c #1 rct = %d p_string = %s",rct,p_string);
printf("c2z_for.c #1 tfield1 = %s fd1_type = %d\n",tfield1,fd1_type);
printf("c2z_for.c #2 tfield2 = %s fd2_type = %d\n",tfield2,fd2_type);
printf("c2z_for.c #3 tfield3 = %s fd3_type = %d\n",tfield3,fd3_type);
printf("c2z_for.c #4 tfield4 = %s\n",tfield4);
printf("c2z_for.c #5 tfield5 = %s fd5_type = %d\n",tfield5,fd5_type);
printf("c2z_for.c #6 tfield6 = %s fd6_type = %d\n",tfield6,fd6_type);
printf("c2z_for.c #7 tfield7 = %s\n",tfield7);
*/
 
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
        strcpy(trace_1, "c2z_for.c #13");
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
        strcpy(trace_1, "c2z_for.c #14");
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
        strcpy(trace_1, "c2z_for.c #15");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    ");
    strcat(a_string, tfield1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #16");
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
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #11");
      trace_rec_3();
    }

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
        strcpy(trace_1, "c2z_for.c #17");
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
        strcpy(trace_1, "c2z_for.c #18");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #19");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #20");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #21");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #22");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #23");
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
        strcpy(trace_1, "c2z_for.c #24");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #25");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #26");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #27");
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
        strcpy(trace_1, "c2z_for.c #28");
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
        strcpy(trace_1, "c2z_for.c #29");
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
           strcpy(trace_1, "c2z_for.c #30");
           trace_rec_3();
        }
      }

      strcpy(a_string, "         LA     R5,");
      strcat(a_string, tfield6);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #31");
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
              strcpy(trace_1, "c2z_for.c #32");
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
      strcpy(trace_1, "c2z_for.c #33");
      trace_rec_3();
    }

    strcpy(a_string, "         JLL   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #34");
      trace_rec_3();
    }
  }

  strcpy(sv_for_incr, tfield6a);

  if (for_opr == 6)
  {
/*
    if (x11 == 0)
    {

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #35");
        trace_rec_3();
      }
      strcpy(sv_for_incr, tfield6a);
    }
*/

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
        strcpy(trace_1, "c2z_for.c #36");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #37");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #38");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #39");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #40");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #41");
        trace_rec_3();
      }

      x = 1;
    }

 

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #42");
        trace_rec_3();
      }
    }

    if (fd5_type == 1) 
    {
        if(pi3 == 0)
        {
          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, tfield5a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield5);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #42a");
            trace_rec_3();
          }
        }

        if(pi3 == 1)
        {
          strcpy(a_string, "         LAEY  R5,");
          strcat(a_string, tfield7);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield7);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #42b");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #42b");
            trace_rec_3();
          }

          strcpy(a_string, "         CVD   R5,0(R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #42c");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R6,C370NWK5");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #42d");
            trace_rec_3();
          }
          work_use_ct[95]++;

          strcpy(a_string, "         LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #42e");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R6),0(8,R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #42f");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, tfield5a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield5);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #42g");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R7,C370NWK5");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #42h");
            trace_rec_3();
          }

          strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #42i");
            trace_rec_3();
          }


/*
3  191    c2z_math.c #26                           LAEY  R5,0                            0                    0001267
3  191    c2z_math.c #27                           LARL  R7,C370U                                                 0001268
3  191    c2z_math.c #28                           CVD   R5,0(R7)                                                 0001269
3  191    c2z_math.c #29                           LARL  R8,C370NWK1                                              0001270
3  191    c2z_math.c #30                           LARL  R7,C370U                                                 0001271
3  191    c2z_math.c #31                           ZAP   0(6,R8),0(8,R7)                                          0001272
*/

        }
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
      strcpy(trace_1, "c2z_for.c #43");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield6a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #44");
      trace_rec_3();
    }

    if(fd5_type == 2)
    {
      strcpy(a_string, "         LARL  R8,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #45");
        trace_rec_3();
      }
    }

    if(fd5_type == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #46");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #47");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #48");
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

