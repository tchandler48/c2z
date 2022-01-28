/* ***************************************************
*  c2z : c2z_pass_2.c :                              *
*                                                    *
*  next error - pass2-062                            *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

void scan_func_name_3() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c func_name_3 START");
    trace_rec_1();
  }

  int pi;
  int pi2;
  int x4 = 0;
  int ret = 0;

  char ch;
  char *p, *p1, *p2, *p3, *p4, *p5;
  char field1[VAR_LGTH];

  field1[0] = '\0';

  p = strstr(p_string, "void");
  p1 = strstr(p_string, ";");
  p2 = strchr(p_string, '(');
  p3 = strchr(p_string, ')');
  p4 = strstr(p_string, "int");
  p5 = strstr(p_string, "print");

  if ((p) && (!p1) && (!p5) && (p3)) 
  {
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

    for (x4 = 0; x4 < fn_ct; x4++) 
    {
      ret = strcmp(field1, w_function[x4].fn_name);
      if (ret == 0) 
      {
        w_function[x4].fn_start = rct;
      }
    }

    convert = 1;
  }

  p = strstr(p_string, "void");
  p1 = strstr(p_string, ";");
  p2 = strchr(p_string, '(');
  p3 = strchr(p_string, ')');
  p4 = strstr(p_string, "int");
  p5 = strstr(p_string, "print");

  if ((p2) && (p3) && (p4) && (!p1) && (convert == 0) && (!p5)) 		/* INT procedure INT get_upper(int, int);		*/
  {
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

    for (x4 = 0; x4 < fn_ct; x4++) 
    {
      ret = strcmp(field1, w_function[x4].fn_name);
      if (ret == 0) 
      {
        w_function[x4].fn_start = rct;
      }
    }

    convert = 1;
  }
}

void scan_func_name_2() 				/* VOID A_BORT(INT CODE, INT LINE_NDX	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c scan _func_name_2");
    trace_rec_1();
  }

  int I = 0;
  int comma_ct = 0;
  int size = 0;
  int x3 = 0;
  int x4 = 0;
  int pi;
  int pi2;
  int ret = 0;
  int ret1 = 0;

  char ch;
  char *p, *p1, *p2;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield5[VAR_LGTH];

  char tfield3a[VAR_LGTH];

  p = strchr(p_string, ',');
  if (p) 
  {
    comma_ct = 1;
  }

  pi = 0;
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
  while (ch != ' ') 
  {
    pi2++;
    pi++;
    ch = p_string[pi];
  }

  p1 = strstr(tfield2, "int");
  if (p1) 			/* next variable is INT	*/
  {
    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }
    pi2 = 0;
    ch = p_string[pi];
    if (comma_ct != 0) 
    {
      while (ch != ',') 
      {
        tfield3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }

    if (comma_ct == 0) 
    {
      while (ch != ')') 
      {
        tfield3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield3[pi2] = '\0';

    if (comma_ct != 0) 
    {
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

      pi2 = 0;
      ch = p_string[pi];
      while (ch != ')') 
      {
        tfield5[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield5[pi2] = '\0';
    }

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    x4 = strlen(c_wkname);
    c_wkname[x4] = '\0';
    strcpy(tfield3a, c_wkname);

    x3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strcpy(tfield3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield3, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(tfield3a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x3 = 1;
        }
      }
    }

    if ((global_st == 0) && (x3 == 0)) 
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
      strcpy(gw_variable[gv_ct].gv_cname, tfield3a);
      strcpy(gw_variable[gv_ct].gv_name, tfield3);
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
      gv_ct++;
      x3 = 1;
    }

    if ((global_st == 1) && (x3 == 0)) 
    {
      x3 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(tfield3, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            strcpy(tfield3a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
            x3 = 1;
          }
        }
      }

      if (x3 == 0) 
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
        strcpy(lw_variable[lv_ct].lv_cname, tfield3a);
        strcpy(lw_variable[lv_ct].lv_name, tfield3);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        lw_variable[lv_ct].lv_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, "0");
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_init = 0;
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        lw_variable[lv_ct].lv_use_ct = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lv_ct++;
      }
    }

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    x4 = strlen(c_wkname);
    c_wkname[x4] = '\0';
    strcpy(tfield1a, c_wkname);

    x3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strcpy(tfield1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x3 = 1;
        }
      }
    }

    if (x3 == 00) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x3 = 1;
        }
      }
    }

    if ((global_st == 0) && (x3 == 0)) 
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
      strcpy(gw_variable[gv_ct].gv_cname, tfield1a);
      strcpy(gw_variable[gv_ct].gv_name, tfield1);
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
      gv_ct++;
      x3 = 1;
    }

    if ((global_st == 1) && (x3 == 0)) 
    {
      x3 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(tfield1, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            strcpy(tfield1a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
            x3 = 1;
          }
        }
      }

      if (x3 == 0) 
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
        strcpy(lw_variable[lv_ct].lv_cname, tfield1a);
        strcpy(lw_variable[lv_ct].lv_name, tfield1);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        lw_variable[lv_ct].lv_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, "0");
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_init = 0;
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        lw_variable[lv_ct].lv_use_ct = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lv_ct++;
      }
    }

    x3 = 0;
    if (fn_ct > 0) 
    {
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(tfield1, w_function[I].fn_name);
        if (ret == 0) 
        {
          x3 = 1;
          if (comma_ct != 0) 
          {
            strcpy(w_function[I].fn_fd1, tfield3);
            strcpy(w_function[I].fn_fd2, tfield5);
            w_function[I].fn_start = rct;
          }
          if (comma_ct == 0) 
          {
            strcpy(w_function[I].fn_fd1, tfield3);
            w_function[I].fn_start = rct;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_int_3 pass2-001 Function Error\n");
      printf("c2z_pass_2.c rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (!p1) 
  {
    p2 = strstr(p_string, "()");
    if (p2) 
    {
      pi = 0;
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
    }
  }

  convert = 1;
}

/* ***************************************************
*  RETURN capture return variable                    *
* ************************************************** */
void c2_return_2() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_return_2 START");
    trace_rec_1();
  }

  int I = 0;
  int ret = 0;
  int pi;
  int pi2;
  int x3 = 0;

  char ch;
  char *p1;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];

  field2[0] = '\0';

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    if(ch == ';')
    {
      break;
    }
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  p1 = strstr(field1, ";");
  if (!p1) 
  {
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ';') 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    x3 = 0;
    if (fn_ct > 0) 
    {
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(sv_func, w_function[I].fn_name);
        if (ret == 0) 
        {
          strcpy(w_function[I].fn_ret_var, field2);
          x3 = 1;
        }
      }
    }
 
  }


  convert = 1;
}


void c2_math_literal() 
{
  char ch;
  char *p, *p2, *p8, *p9;
  char field1[VAR_LGTH];

  int pi;
  int pi2;
  int x = 0;
  int x1 = 0;
  int x2 = 0;
  int x20 = 0;
  int op_1 = 0;
  int L1 = 0;
  int R1 = 0;
  int L2 = 0;
  int R2 = 0;
  int I = 0;
  int s = 0;
  int x90 = 0;
  int size = 0;
  int math_plus = 0;
  int math_minus = 0;
  int math_mult = 0;
  int math_div = 0;
  int math = 0;
  int math1 = 0;
  int x501 = 0;
  int x501L1 = 0;
  int x501L2 = 0;
  int x501R1 = 0;
  int x501R2 = 0;

  x90 = 0;
  s = strlen(p_string);
  for(I = 0; I < s; I++)
  {
    if(p_string[I] == '=')
    {
      x501 = I;
    }
    if(p_string[I] == '[')
    {
      if(x501 == 0)
      {
        x501L1++;
      }
      else
      {
        x501L2++;
      }
      x90++;
    }
    if(p_string[I] == ']')
    { 
      if(x501 == 0)
      {
        x501R1++;
      }
      else
      {
        x501R2++;
      }
      x90++;
    }
  }


  if((x501L1 == 1) && (x501R1 == 1) && (x501L2 == 2) && (x501R2 == 2))
  {
     c2_count_paren();
     convert = 1;
     return;
  }

  if(x90 == 6)
  {
    c2_pass2_math_600();
    convert = 1;
    return;
  }

  p2 = strstr(p_string, "('");
  if (p2) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_math_literal subroutine #63");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while(ch != '\'')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != '\'')
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

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
    strcpy(w_charlit[char_ct].clit_value, field1);
    w_charlit[char_ct].clit_type = 3;
    s = strlen(field1);
    w_charlit[char_ct].clit_lgth = s;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;

    convert = 1;
    return;
  }

  p = strstr(p_string, "=");
  if (p) 
  {
    p2 = strstr(p_string, "-1");
    if (p2)
      math1 = 1;

    x20 = 0;
    p2 = strstr(p_string, "[(");
    if (p2) 
    {
      x20 = 1;
    }

    math = 0;

    s = strlen(p_string);
    for (I = 0; I < s; I++) 
    {
      ch = p_string[I];
      if (ch == '+') 
      {
        math_plus++;
        math = 1;
      }

      if ((ch == '-') && (math1 == 0)) 
      {
        math_minus++;
        math = 1;
      }

      if (ch == '*') 
      {
        math_mult++;
        math = 1;
      }

      if (ch == '/') 
      {
        math_div++;
        math = 1;
      }

      if(math == 0)
      {
         p = strstr(p_string, "'");
         if(p)
         {
            math = 1;
         }
      }

      if ((math == 1) && (x20 == 0)) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_pass_2.c c2_math_literal_99 BRANCH");
          trace_rec_1();
        }

        c2_math_literal_99();
        return;
      }
    }
  }

  op_1 = 1;

  p8 = strchr(p_string, '(');
  p9 = strchr(p_string, ')');

  x = 0;
  x2 = 0;
  L1 = 0;
  R1 = 0;
  L2 = 0;
  R2 = 0;
  I = 0;

  s = strlen(p_string);
  pi = 0;
  ch = p_string[pi];
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if ((ch != '=') && (x2 != 1) && (x != 1)) 
    {
      if (ch == '[') 
      {
        L1++;
        x2 = 0;
      }
    }

    if (ch == '=') 
    {
      x = 1;
      x1 = I;
      break;
    }

    if ((x == 0) && (ch != ';')) 
    {
      if (ch == '[') 
      {
        R1++;
      }
    }
  }

  x2 = 0;
  for (I = x1; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[') 
    {
      L2++;
    }
    if (ch == ']') 
    {
      R2++;
    }
  }

  x90 = 0;
  p = strstr(p_string, "]++;");
  if (p) 
  {
    x90 = 1;
  }

  p = strstr(p_string, "]--;");
  if (p) 
  {
    x90 = 1;
  }

  if (x90 == 1) 
  {
    c2_math_literal_8();
    convert = 1;
    return;
  }

  if ((op_1 == 1) && (L1 == 0) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9)) 
  {
    c2_math_literal_1();
    convert = 1;
    return;
  }

  if ((op_1 == 1) && (L1 == 0) && (R1 == 0) && (L2 == 1) && (R2 == 1) && (!p8) && (!p9)) 
  {
    c2_math_literal_6();
    return;
  }

  if ((op_1 == 1) && (L1 == 1) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9)) 
  {
    printf("c2_math_math_lit_3 rct = %d p_string = %s",rct,p_string);
    erct++;
    return;
  }

  if ((op_1 == 1) && (L1 > 1) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9)) 
  {
    printf("c2_math_math_lit_4 rct = %d p_string = %s",rct,p_string); 
    erct++;
    return;
  }

  if ((op_1 == 1) && (L1 == 1) && (R1 == 1) && (L2 == 0) && (R2 == 0) && (p8) && (p9) && (x20 == 1)) 
  {
    c2_pass2_math_51();
    return;
  }

  if ((op_1 == 1) && (L1 == 1) && (L2 == 0) && (R2 == 0) && (p8) && (p9)) 
  {
    /* printf("c2_math_math_lit_5 rct = %d p_string = %s",rct,p_string); 
    erct++; */
    convert = 1;
    return;
  }

  if ((op_1 == 1) && (p8) && (p9) && (L1 == 0) && (R1 == 0) && (math == 0)) 
  {
 /*   printf("c2_math_math_lit_6 rct = %d p_string = %s",rct,p_string); 
    erct++; */
    convert = 1;
    return;
  }

  if ((L1 > 0) && (R1 > 0) && (L2 > 0) && (R2 > 0)) 
  {
    c2_math_literal_7();
    convert = 1;
    return;
  }
}

void c2_math_literal_1() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_math_literal_1");
    trace_rec_1();
  }

  char ch;
  char *p1;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield3b[VAR_LGTH];

  int fd2_type = 0;
  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int x70 = 0;
  int x71 = 0;
  int x98 = 0;
  int x99 = 0;
  int I = 0;
  int s = 0;
  int s1 = 0;
  int ret = 0;
  int fd1_id = 0;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  x3 = 0;
  while ((ch != ' ') && (x3 == 0)) 
  {
    if (ch == '=') 
    {
      x3 = 1;
    } 
    else 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield1[pi2] = '\0';

  x2 = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    x2 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x2 == 0)) 
    {
      x3 = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
      fd1_id = lw_variable[I].lv_id;
      break;
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
        fd1_id = gw_variable[I].gv_id;
        break;
      }
    }
  }

  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch != '=') 
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
  x5 = 0;
  x4 = 0;
  x2 = 0;
  x3 = 0;
  s = strlen(p_string);
  while ((ch != '[') && (pi < s) && (ch != ';')) 
  {
    if ((isdigit(ch)) && (x3 == 0)) 
    {
      fd2_type = 2;
      x3 = 1;
    }

    if ((isalpha(ch)) && (x3 == 0)) 
    {
      fd2_type = 1;
      x3 = 1;
    }

    if (ch == '\'') 
    {
      x4 = 1;
      x4++;
    }

    if (x4 > 0) 
    {
      if (ch == ' ') 
      {
        x5++;
      }
    }
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  s = strlen(tfield2);

  if ((fd2_type == 2) && (fd1_id == 1)) 
  {
    if (x4 == 0) 					/* if field2 is A math_lit	*/
    {
      s = strlen(tfield2);
      x99 = 0;
      x98 = 0;
      p1 = strstr(tfield2, "-");
      if (p1) 
      {
        x99 = 1;
      }

      p1 = strstr(tfield2, ".");
      if (p1) 
      {
        x98 = 1;
      }

      s1 = s + 1;
      if (x99 == 1) 
      {
        strcpy(tfield3b, tfield2);
        pi2 = 0;
        for (I = 0; I < s1; I++) 
        {
          ch = tfield3b[I];
          if (ch != '-') 
          {
            tfield2[pi2] = ch;
            pi2++;
          }
        }
        tfield2[pi2] = '\0';
      }

      if (x98 == 1) 
      {
        strcpy(tfield3b, tfield2);
        x70 = 0;
        x71 = 0;
        pi2 = 0;
        tfield2[pi2] = '0';
        pi2++;
        for (I = 0; I < s1; I++) 
        {
          ch = tfield3b[I];
          if (x70 == 1) 
          {
            x71++;
          }
          if (ch != '.') 
          {
            tfield2[pi2] = ch;
            pi2++;
          }
          if (ch == '.') 
          {
            x70 = 1;
          }
        }
        tfield2[pi2] = '\0';
        if (x71 > 0)
        {
          x71--;
        }
      }
      convert = 1;
    }
  }

  if ((fd2_type == 2) && (fd1_id == 2) && (convert == 0)) 
  {
    s = strlen(tfield2);
    x99 = 0;
    x98 = 0;
    p1 = strstr(tfield2, "-");
    if (p1) 
    {
      x99 = 1;
    }

    p1 = strstr(tfield2, ".");
    if (p1) 
    {
      x98 = 1;
    }

    s1 = s + 1;
    x70 = 0;
    x71 = 0;
    pi2 = 0;
    if (x98 == 1) 
    {
      strcpy(tfield3b, tfield2);
      for (I = 0; I < s1; I++) 
      {
        ch = tfield3b[I];
        if (x70 == 1) 
        {
          x71++;
        }
        tfield2[pi2] = ch;
        pi2++;
        if (ch == '.') 
        {
          x70 = 1;
        }
        tfield2[pi2] = '\0';
      }
      if (x71 > 0)
      {
        x71--;
      }
    }
  }
  convert = 1;
}

void c2_pass2_math_51() 		/* [] left of =   token[pi] = ch  or token[(pi+1)] = ch; */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_51 START");
    trace_rec_1();
  }

  char *p, *p1;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field5[VAR_LGTH];
  char tfield3b[VAR_LGTH];
  
  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x99 = 0;
  int m5_3 = 0;
  int m5_6 = 0;
  int m5fd2_type = 0;
  int I = 0;
  int s = 0;
  int s1 = 0;
  int size = 0;
  int ret = 0;
  int ret1 = 0;

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

  m5_3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      m5_3 = 1;
      strcpy(field1a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
    }
  }

  if (m5_3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      m5_6 = strcmp(field1, gw_variable[I].gv_name);
      if (m5_6 == 0) 
      {
        m5_3 = 1;
        strcpy(field1a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (m5_3 == 0) 
  {
    printf("\nc2z_pass_2.c c2_pass2_math_51 pass2-003 field1 Not Found = %s\n",field1);
    printf("c2z_pass_2.c c2_pass2_math_51 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi++;
  pi++;
  ch = p_string[pi];
  pi2 = 0;
  x2 = 0;
  while (isalnum(ch)) 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        m5fd2_type = 2;
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        m5fd2_type = 1;
        x2 = 1;
      }
    }
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  if (m5fd2_type == 2) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_51 subroutine #1");
      trace_rec_1();
    }

    m5_3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        m5_3 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (m5_3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        m5_6 = strcmp(field2, gw_variable[I].gv_name);
        if (m5_6 == 0) 
        {
          m5_3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_pass2_math_51 pass2-004 field12 Not Found = %s\n",field2);
      printf("c2z_pass_2.c c2_pass2_math_51 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  while (!isalnum(ch)) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (isdigit(ch)) 
  {
    field5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field5[pi2] = '\0';

  while (ch != '=') 
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
  s = strlen(p_string);
  while ((pi < s) && (ch != ';')) 
  {
    if (ch != '\'') 
    {
      field3[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s1 = strlen(c_wkname);
  c_wkname[s1] = '\0';

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
  strcpy(w_charlit[char_ct].clit_value, field3);
  w_charlit[char_ct].clit_type = 3;
  s = strlen(field3);
  w_charlit[char_ct].clit_lgth = s;
  w_charlit[char_ct].clit_uct = 1;
  char_ct++;

  x3 = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[')
    {
      x3++;
    }
    if (ch == ']')
    {
      x3++;
    }
  }

  p = strstr(field3, "'\0'");
  if ((p) && (x3 == 2)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_51 subroutine #2");
      trace_rec_1();
    }

    m5_3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        m5_3 = 1;
      }
    }

    if (m5_3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        m5_6 = strcmp(field1, gw_variable[I].gv_name);
        if (m5_6 == 0) 
        {
          m5_3 = 1;
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_pass2_math_51 pass2-005 field1 Not Found = %s\n",field1);
      printf("c2z_pass_2.c c2_pass2_math_51 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  s = strlen(field5);
  x99 = 0;
  p1 = strstr(field5, "-");
  if (p1) 
  {
    x99 = 1;
  }

  s1 = s + 1;
  if (x99 == 1) 
  {
    strcpy(tfield3b, field5);
    pi2 = 0;
    for (I = 0; I < s1; I++) 
    {
      ch = tfield3b[I];
      if (ch != '-') 
      {
        field5[pi2] = ch;
        pi2++;
      }
    }
    field5[pi2] = '\0';
  }
  convert = 1;
}

void c2_math_literal_99() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_math_math_lit_99 START");
    trace_rec_1();
  }

  int s = 0;
  int s1 = 0;
  int s2 = 0;
  int pi2 = 0;
  int x2 = 0;
  int x4 = 0;
  int x70 = 0;
  int x71 = 0;
  int x80 = 0;
  int x98 = 0;
  int x99 = 0;
  int I = 0;
  int pi;
  int size = 0;
  int fd3_type = 0;
  int fd5_type = 0;
  int fd7_type = 0;
  int fd11_type = 0;
  int start_parm = 0;

  char sv_result[VAR_LGTH];
  char ch, *p, *p1;
  char field1[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field7[VAR_LGTH];
  char field11[VAR_LGTH];
  char tfield3b[VAR_LGTH];

  s2 = strlen(p_string);
  s2--;
  s2--;

  pi = 0;
  ch = p_string[pi];
  while ((ch == '{') || (ch == ' ') || (ch == '\t')) 
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

  strcpy(sv_result, field1);

  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch != ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
  {
    pi++;
    ch = p_string[pi];
  }

  fd3_type = 0;
  x2 = 0;
  pi2 = 0;
  while (ch != ' ') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd3_type = 2;
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        fd3_type = 1;
        x2 = 1;
      }
    }
    if (ch == '(') 
    {
      start_parm = 1;
      break;
    } 
    else 
    {
      if (ch == ';') 
      {
        break;
      }
      if (ch != ';') 
      {
        field3[pi2] = ch;
        pi2++;
      }
    }
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';
  p = strstr(field3, "'");
  if (p) 
  {
    fd3_type = 0;
  }

  if (start_parm == 1) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_math_math_lit_99 subroutine #1");
      trace_rec_1();
    }

    fd3_type = 0;
    x2 = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      if ((ch == '-') || (ch == '+') || (ch == '*') || (ch == '/')) 
      {
        pi++;
        ch = p_string[pi];
        while (ch == ' ') 
        {
          pi++;
          ch = p_string[pi];
        }
        field3[pi2] = '\0';
        goto label_99;
      }
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

  label_99:

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if ((ch == '-') || (ch == '+') || (ch == '*') || (ch == '/')) 
      {
        pi++;
        ch = p_string[pi];
      }

      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd5_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd5_type = 1;
          x2 = 1;
        }
      }
      if (ch != ' ') 
      {
        field5[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';

    convert = 1;
    return;
  }

  if (fd3_type == 1) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_math_math_lit_99 subroutine #2");
      trace_rec_1();
    }

    s = strlen(field3);
    x99 = 0;
    p1 = strstr(field3, "-");
    if (p1) 
    {
      x99 = 1;
    }

    s1 = s + 1;
    if (x99 == 1) 
    {
      strcpy(tfield3b, field3);
      pi2 = 0;
      for (I = 0; I < s1; I++) 
      {
        ch = tfield3b[I];
        if (ch != '-') 
        {
          if (ch != ';') 
          {
            field3[pi2] = ch;
            pi2++;
          }
        }
      }
      field3[pi2] = '\0';
    }
  } 				/* END OF       if(fd3_type == 1)		*/

  if (fd3_type == 0) 			/*  quote char              */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_math_math_lit_99 subroutine #3");
      trace_rec_1();
    }

    s = strlen(field3);
    pi2 = 0;
    for (I = 0; I < s; I++) 
    {
      ch = field3[I];
      if (ch != '\'') 
      {
        field3a[pi2] = ch;
        pi2++;
      }
    }
    field3a[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s1 = strlen(c_wkname);
    c_wkname[s1] = '\0';
    strcpy(field3, c_wkname);

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
    strcpy(w_charlit[char_ct].clit_cname, field3);
    strcpy(w_charlit[char_ct].clit_value, field3a);
    w_charlit[char_ct].clit_type = 3;
    s = strlen(field3a);
    w_charlit[char_ct].clit_lgth = s;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;

    convert = 1;
    return;

  } 		/* END OF       if(fd3_type == 0)		*/

  if (fd3_type == 2) 			/*  numeric math_lit 3rd position */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_math_math_lit_99 subroutine #4");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '=') 
    {
      pi++;
      ch = p_string[pi];
    }

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

    pi2 = 0;
    while (ch != ' ') 
    {
      if (ch == '[') 
      {
        goto lit_99_2;
        field3[pi2] = '\0';
      }
      if (ch == ';') 
      {
        convert = 1;
        return;
      }
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    s = strlen(p_string);

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

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

  lit_99_2:

    fd5_type = 0;
    x2 = 0;
    pi2 = 0;
    while (ch != ';') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd5_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd5_type = 1;
          x2 = 1;
        }
      }
      field5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';

    convert = 1;
    return;
  }

  while ((ch == ' ') || (ch == '\t')) 
  {
    pi++;
    ch = p_string[pi];
  }

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

  x80 = 0;
  x4 = 0;
  x2 = 0;
  pi2 = 0;
  s2++;
  while (pi < s2) 
  {
    if (ch == ';') 
    {
      x80 = 1;
      break;
    }

    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd5_type = 2;
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
        fd5_type = 1;
        x2 = 1;
      }

      if ((ch == '(') && (x2 == 0)) 
      {
        start_parm = 1;
      }
    }

    if ((ch == ')') && (start_parm == 1)) 
    {
      ch = p_string[pi + 1];
      if (ch == ';') 
      {
        pi = s;
        break;
      }
    }

    if (ch != ' ') 
    {
      field5[pi2] = ch;
      pi2++;
    } 
    else 
    {
      break;
    }
    pi++;
    ch = p_string[pi];
    x4 = 1;
  }
  field5[pi2] = '\0';
  field5a[0] = '\0';

  if (ch == ';') 
  {
    convert = 1;
    return;
  }

  if (start_parm == 1) 
  {
    x4 = 0;
    pi2 = 0;
    ch = field5[x4];
    while (ch != '\0') 
    {
      if (ch != '(') 
      {
        field5a[pi2] = ch;
        pi2++;
      }
      x4++;
      ch = field5[x4];
    }
    field5a[pi2] = '\0';
    strcpy(field5, field5a);
  }

  if (fd5_type == 1) 
  {
    s = strlen(field5);
    x99 = 0;
    p1 = strstr(field5, "-");
    if (p1) 
    {
      x99 = 1;
    }

    p1 = strstr(field5, ".");
    if (p1) 
    {
      x98 = 1;
    }

    s1 = s + 1;
    if (x99 == 1) 
    {
      strcpy(tfield3b, field5);
      pi2 = 0;
      for (I = 0; I < s1; I++) 
      {
        ch = tfield3b[I];
        if (ch != '-') 
        {
          field5[pi2] = ch;
          pi2++;
        }
      }
      field5[pi2] = '\0';
    }

    if (x98 == 1) 
    {
      strcpy(tfield3b, field5);
      x70 = 0;
      x71 = 0;
      pi2 = 0;
      field5[pi2] = '0';
      pi2++;
      for (I = 0; I < s1; I++) 
      {
        ch = tfield3b[I];
        if (x70 == 1) 
        {
          x71++;
        }
        if (ch != '.') 
        {
          field5[pi2] = ch;
          pi2++;
        }
        if (ch == '.') 
        {
          x70 = 1;
        }
      }
      field5[pi2] = '\0';
      if (x71 > 0)
      {
        x71--;
      }
    }
  }

  if (x80 == 1)
  {
    return;
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

  x4 = 0;
  x2 = 0;
  pi2 = 0;
  while ((pi < s2) && (ch != ' ')) 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd7_type = 2;
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
        fd7_type = 1;
        x2 = 1;
      }

      if ((ch == '(') && (x2 == 0)) 
      {
        start_parm = 1;
      }
    }

    if ((ch == ')') && (start_parm == 1)) 
    {
      ch = p_string[pi + 1];
      if (ch == ';') 
      {
        pi = s;
        break;
      }
    }

    if ((ch == '(') && (x4 == 1)) 
    {
    }

    if (ch != ';') 
    {
      field7[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
    x4 = 1;
  }
  field7[pi2] = '\0';

 
  if (start_parm == 1) 
  {
    x4 = 0;
    pi2 = 0;
    ch = field5[x4];
    while (ch != '\0') 
    {
      if (ch != '(') 
      {
        field5a[pi2] = ch;
        pi2++;
      }
      x4++;
      ch = field5[x4];
    }
    field5a[pi2] = '\0';
    strcpy(field5, field5a);
  }

  if (fd7_type == 1) 
  {
    s = strlen(field7);
    x99 = 0;
    p1 = strstr(field7, "-");
    if (p1) 
    {
      x99 = 1;
    }

    s1 = s + 1;
    if (x99 == 1) 
    {
      strcpy(tfield3b, field7);
      pi2 = 0;
      for (I = 0; I < s1; I++) 
      {
        ch = tfield3b[I];
        if (ch != '-') 
        {
          field7[pi2] = ch;
          pi2++;
        }
      }
      field7[pi2] = '\0';
    }
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

  x4 = 0;
  x2 = 0;
  pi2 = 0;
  while ((pi < s2) && (ch != ' ')) 
  {
    if ((ch == '(') && (x2 == 0)) 
    {
      start_parm = 1;
    }
   

    if ((ch == ')') && (start_parm == 1)) 
    {
      ch = p_string[pi + 1];
      if (ch == ';') 
      {
        pi = s;
        break;
      }
    }

    pi++;
    ch = p_string[pi];
    x4 = 1;
  }

  if (start_parm == 1) 
  {
    x4 = 0;
    pi2 = 0;
    ch = field5[x4];
    while (ch != '\0') 
    {
      if (ch != '(') 
      {
        field5a[pi2] = ch;
        pi2++;
      }
      x4++;
      ch = field5[x4];
    }
    field5a[pi2] = '\0';
    strcpy(field5, field5a);
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

  x4 = 0;
  x2 = 0;
  pi2 = 0;
  while ((pi < s2) && (ch != ' ')) 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd11_type = 2;
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
        fd11_type = 1;
        x2 = 1;
      }

      if ((ch == '(') && (x2 == 0)) 
      {
        start_parm = 1;
      }
    }

    if ((ch == ')') && (start_parm == 1)) 
    {
      ch = p_string[pi + 1];
      if (ch == ';') 
      {
        pi = s;
        break;
      }
    }

    if ((ch == '(') && (x4 == 1)) 
    {
    }

    if (ch != ';') 
    {
      field11[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
    x4 = 1;
  }
  field11[pi2] = '\0';

  if (start_parm == 1) 
  {
    x4 = 0;
    pi2 = 0;
    ch = field5[x4];
    while (ch != '\0') 
    {
      if (ch != '(') 
      {
        field5a[pi2] = ch;
        pi2++;
      }
      x4++;
      ch = field5[x4];
    }
    field5a[pi2] = '\0';
    strcpy(field5, field5a);
  }

  if (fd11_type == 1) 
  {
    s = strlen(field11);
    x99 = 0;
    p1 = strstr(field11, "-");
    if (p1) 
    {
      x99 = 1;
    }

    s1 = s + 1;
    if (x99 == 1) 
    {
      strcpy(tfield3b, field11);
      pi2 = 0;
      for (I = 0; I < s1; I++) 
      {
        ch = tfield3b[I];
        if (ch != '-') 
        {
          field11[pi2] = ch;
          pi2++;
        }
      }
      field11[pi2] = '\0';
    }
  }

  if (fd3_type == 0) 
  {
    pi = 0;
    pi2 = 0;
    s = strlen(field3);
    ch = field3[pi];
    while (pi < s) 
    {
      if (ch != '\'') 
      {
        field3a[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = field3[pi];
    }
    field3a[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(field3, c_wkname);

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
    strcpy(w_charlit[char_ct].clit_cname, field3);
    strcpy(w_charlit[char_ct].clit_value, field3a);
    w_charlit[char_ct].clit_type = 3;
    s = strlen(field3a);
    w_charlit[char_ct].clit_lgth = s;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;
  }
}

void c2_pass2_for() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_for START");
    trace_rec_1();
  }

  char ch;
  char *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];

  inside_for = 1;
  for_opr = 0;

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x11 = 0;
  int x80 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
  int fd2_type = 0;

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
  while (ch != '=') 
  {
    if (ch == ';') 
    {
      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }
      goto skip_for_3;
    }
    if (ch != ' ') 
    {
      tfield1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  x11 = 0;
  p = strstr(tfield1, ";");
  if (p) 
  {
    x11 = 1;
  }

  if (x11 == 0) 
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        ret2 = strcmp(lw_variable[I].lv_type, "I");
        if (ret2 != 0) 
        {
          printf("\nc2z_pass_2.c c2_pass2_for pass2-006 tfield1 Not Numeric = %s\n",tfield1);
          printf("c2z_pass_2.c c2_pass2_for rct = %d p_string = %s", rct,p_string);
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
          ret1 = strcmp(gw_variable[I].gv_type, "I");
          if (ret1 != 0) 
          {
            printf("\nc2z_pass_2.c c2_pass2_for pass2-007 tfield1 Not Numeric = %s\n",tfield1);
            printf("c2z_pass_2.c c2_pass2_for rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_pass_2 for pass2-008 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_pass_2.c c2_pass_2 for rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    fd2_type = 0;
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

    if (fd2_type == 2) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_for subroutine #1 START");
        trace_rec_1();
      }

      x80 = 0;
      ret = strcmp("0", tfield2);
      if(ret == 0)
      {
        x80 = 1;
      }

      if(x80 == 0)
      {
        ret = strcmp("1", tfield2);
        if(ret == 0)
        {
          x80 = 1;
        }
      }
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

  skip_for_3:

    pi2 = 0;
    while (ch != ' ') 
    {
      if (ch == '<') 
      {
        goto skip_for_4;
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    
  skip_for_4:

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
          printf("\nc2z_pass_2.c c2_pass2_for pass2-009 tfield3 Not Numeric %s\n", tfield3);
          printf("c2z_pass_2.c c2_pass2_for rct = %d p_string = %s", rct,p_string);
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
          if (ret1 != 0) 
          {
            printf("\nc2z_pass_2.c c2_pass2_for pass2-010 tfield3 Not Numberic = %s\n",tfield3);
            printf("c2z_pass_2.c c2_pass2_for rct = %d p_string = %s", rct,p_string);
            erct++;
            convert = 1;
            return;
          }
          x3 = 1;
          strcpy(tfield3a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_pass2_for pass2-019 tfield3 Not Found = %s\n", tfield3);
      printf("c2z_pass_2.c c2_pass2_for rct = %d p_string = %s", rct, p_string);
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
  }
}

void c2_pass2_strcat() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_strcat START");
    trace_rec_1();
  }

  char ch;
  char *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  tfield1a[0] = '\0';

  int pi;
  int pi2;
  int size = 0;
  int x3 = 0;
  int s = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int x80;

  x80 = 0;
  s = strlen(p_string);
  for(I=0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '\"')
    {
      x80++;
    }
  }

  if(x80 == 0)
  {
    convert = 1;
    return;
  }

  p = strstr(p_string, "\"");
  if (p) 
  {
    pi = 0;
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
      ch = p_string[pi];
    }

    if (ch == '"') 
    {
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != '"') 
      {
        tfield2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield2[pi2] = '\0';

    x3 = strlen(tfield2);
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield1a, c_wkname);

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
    strcpy(w_charlit[char_ct].clit_cname, tfield1a);
    strcpy(w_charlit[char_ct].clit_value, tfield2);
    w_charlit[char_ct].clit_type = 3;
    w_charlit[char_ct].clit_lgth = x3;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;
  }

  if (!p) /* field cat		strcat(a,b);	*/
  {
    s = strlen(p_string);
    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

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
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ')') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

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
         
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_strcat pass2-020 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_pass_2.c c2_strcat rct = %d p_string = %s", rct, p_string);
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
        lw_variable[I].lv_use_ct++;
     
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
          gw_variable[I].gv_use_ct++;
        
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_strcat pass2-021 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_pass_2.c c2_strcat rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }
  convert = 1;
}

void c2_pass2_if() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_if");
    trace_rec_1();
  }

  char ch;
  char *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9;

  int pi;
  if_convert = 0;
  int s = 0;
  int I = 0;
  int bracket_ct = 0;
  int if_complex = 0;

  if_opr = 0;
  convert = 0;

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[')
    {
      bracket_ct++;
    }
    if (ch == ']')
    {
      bracket_ct++;
    }
  }

 if ((if_opr == 0) && (convert == 0)) 
  {
    p8 = strstr(p_string, "pthread_create");
    if (p8) 
    {
      if_opr = 35;
      convert = 1;
      return;
    }
  }

  if((if_opr == 0) && (convert == 0))
  {
    p8 = strstr(p_string, "fgets");
    if(p8)
    {
      if_opr = 55;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p8 = strstr(p_string, "strchr");
    if (p8) 
    {
      if_opr = 15;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p8 = strstr(p_string, "strcmp");
    if (p8) 
    {
      if_opr = 10;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p8 = strstr(p_string, "eof");
    if (p8) 
    {
      if_opr = 9;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p8 = strstr(p_string, "isalpha");
    if (p8) 
    {
      if_opr = 8;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p7 = strstr(p_string, "isdigit");
    if (p7) 
    {
      if_opr = 7;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p7 = strstr(p_string, "isupper");
    if (p7) 
    {
      if_opr = 22;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p7 = strstr(p_string, "isalnum");
    if (p7) 
    {
      if_opr = 23;
    }
  }

  p9 = strstr(p_string, "&&");
  if (p9) 
  {
    if_complex = 1;
  }

  p9 = strstr(p_string, "||");
  if (p9) 
  {
    if_complex = 1;
  }

  if ((if_opr == 0) && (if_complex == 1) && (convert == 0)) 
  {
    if_opr = 20;
    c2_pass2_if_13();
    if_convert = 1;
    return;
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p6 = strstr(p_string, "<=");
    if (p6) 
    {
      if_opr = 6;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p5 = strstr(p_string, ">=");
    if (p5) 
    {
      if_opr = 5;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p4 = strstr(p_string, "<");
    if (p4) 
    {
      if_opr = 4;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p3 = strstr(p_string, ">");
    if (p3) 
    {
      if_opr = 1;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p2 = strstr(p_string, "!=");
    if (p2) 
    {
      if_opr = 1;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p1 = strstr(p_string, "==");
    if (p1) 
    {
      if_opr = 1;
    }
  }

/* ***************************************************
 *  branch based on if_opr                           *
 *************************************************** */

  if((if_opr == 55) && (if_convert == 0))
  {
    c2_pass2_if_55();
    if_convert = 1;
    return;
  }


  if ((if_opr == 22) && (if_convert == 0)) 
  {
    /* if_case_22(); */
    if_convert = 1;
    return;
  }

  if ((if_opr == 23) && (if_convert == 0)) 
  {
    /* if_case_23(); */
    if_convert = 1;
    return;
  }

  if ((if_opr == 15) && (if_convert == 0)) 
  {
    c2_pass2_if_15();
    if_convert = 1;
    return;
  }

  if ((if_opr == 1) && (if_convert == 0) && (bracket_ct == 0)) 	/* NO [] in p_string */
  {
    c2_pass2_if_1();
    if_convert = 1;
  }

  if ((if_opr == 2) && (if_convert == 0)) 
  {
    c2_pass2_if_2();
    if_convert = 1;
  }

  if ((if_opr == 3) && (if_convert == 0)) 
  {
    /* if_case_3(); */
    if_convert = 1;
  }

  if ((if_opr == 4) && (if_convert == 0) && (convert == 0)) 
  {
    c2_pass2_if_4();
    if_convert = 1;
  }

  if ((if_opr == 5) && (if_convert == 0)) 
  {
    c2_pass2_if_1();
    if_convert = 1;
  }

  if ((if_opr == 6) && (if_convert == 0)) 
  {
    /* if_case_6(); */
    if_convert = 1;
  }

  if ((if_opr == 7) && (if_convert == 0)) 
  {
    c2_pass2_if_7();
    if_convert = 1;
  }

  if ((if_opr == 8) && (if_convert == 0)) 
  {
    /* if_case_8(); */
    if_convert = 1;
  }

  if ((if_opr == 9) && (if_convert == 0)) 
  {
    /* if_case_9(); */
    if_convert = 1;
  }

  if ((if_opr == 10) && (if_convert == 0)) 
  {
    c2_pass2_if_10();
    if_convert = 1;
  }

  if ((if_opr == 1) && (if_convert == 0) && (bracket_ct == 2)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c Step #15");
      trace_rec_1();
    }

    pi = 0;
    s = strlen(p_string);
    convert = 1;
    if_convert = 1;
  }

  if ((if_convert == 0) && (bracket_ct == 0)) 			/*  if(p) 	*/
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
    while (ch != ')') 
    {
      pi++;
      ch = p_string[pi];
    }
    
    convert = 1;
    if_convert = 1;
  }

  if ((if_opr == 12) && (if_convert == 0)) 
  {
    /* if_case_12(); */
    if_convert = 1;
  }

  convert = 1;
}

void c2_pass2_if_1() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_1 START");
    trace_rec_1();
  }

  char ch;
  char *p, *p5;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3a[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int if_comma = 0;
  int if_complex = 0;
  int if_blank = 0;
  int if_quote = 0;
  int if_convert = 0;

  int fd1_type = 0;
  int fd2_type = 0;

  int x = 0;
  int x2 = 0;
  int x3 = 0;
  int s = 0;
  int size = 0;
  int lbrack = 0;
  int rbrack = 0;
  int ret1 = 0;
  int ret = 0;

  convert = 0;
 
  p = strstr(p_string, "&&");
  if (p) 
  {
    if_complex = 1;
  }

  p = strstr(p_string, "||");
  if (p) 
  {
    if_complex = 1;
  }

  p = strstr(p_string, "')'");
  if(p)
  {
    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    x3 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      if ((ch == '_') && (x3 == 0)) 
      {
        x3 = 1;
      }

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
      if (ch != '(') 
      {
        field1[pi2] = ch;
        pi2++;
      }
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
      printf("\2c2z_pass_2.c c2_pass2_if_1 pass2-022 field1 Not Found = %s\n",field1);
      printf("c2z_pass_2.c c2_pass2_if_1 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
      printf("c2z_pass_2.c c2_pass2_if_1 #99 FIX THIS CODE\n");
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

    fd2_type = 0;
    x2 = 0;
    x3 = 0;
    pi2 = 0;
    while (ch != '\n') 
    {
      if(ch == '\'')
      {
        x3++;
      }
      if (x2 == 0) 
      {
        if ((ch == '\'') && (x2 == 0)) 
        {
          fd2_type = 0;
          x2 = 1;
        }
        if ((isdigit(ch)) && (x2 == 0)) 
        {
          fd2_type = 1;
          x2 = 1;
        }
        if ((isalpha(ch)) && (x2 == 0)) 
        {
          fd2_type = 2;
          x2 = 1;
        }
      }
      if(x3 == 2)
      {
        break;
      }
      if(ch != '\'')
      {
        field2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    if (global_st == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
        }
      }

      if (x3 == 0) 
      {
        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(field1a, c_wkname);

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
        strcpy(gw_variable[gv_ct].gv_type, "C");
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
        gv_ct++;
      }
    } 			/* END OF if(global_st == 0) */

    if (global_st == 1) 
    {
      x3 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field1, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
          }
        }
      }

      if (x3 == 0) 
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
        strcpy(lw_variable[lv_ct].lv_cname, field1a);
        strcpy(lw_variable[lv_ct].lv_name, field1);
        strcpy(lw_variable[lv_ct].lv_type, "C");
        lw_variable[lv_ct].lv_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, "0");
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_init = 0;
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        lw_variable[lv_ct].lv_use_ct = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lv_ct++;
      }
    } 				/* END OF if(global_st == 1) */

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(field1a, c_wkname);
    s = strlen(field2);
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
     strcpy(w_charlit[char_ct].clit_cname, field1a);
     strcpy(w_charlit[char_ct].clit_value, field2);
     w_charlit[char_ct].clit_type = 3;
     w_charlit[char_ct].clit_lgth = 1;
     w_charlit[char_ct].clit_uct = 1;
     char_ct++;

     convert = 1;
     return;
   }

  if (if_complex == 0) 
  {
    lbrack = 0;
    rbrack = 0;
    s = strlen(p_string);
    for (I = 0; I < s; I++) 
    {
      ch = p_string[I];
      if (ch == '[') 
      {
        lbrack++;
      }
      if (ch == ']') 
      {
        rbrack++;
      }
    }

    if ((lbrack == 0) && (rbrack == 0)) 
    {
      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      x3 = 0;
      x2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        if ((ch == '_') && (x3 == 0)) 
        {
          x3 = 1;
        }

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
        if (ch != '(') 
        {
          field1[pi2] = ch;
          pi2++;
        }
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
        printf("\2c2z_pass_2.c c2_pass2_if_1 pass2-022 field1 Not Found = %s\n",field1);
        printf("c2z_pass_2.c c2_pass2_if_1 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
        printf("c2z_pass_2.c c2_pass2_if_1 #99 FIX THIS CODE\n");
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

      fd2_type = 0;
      x2 = 0;
      pi2 = 0;
      while (ch != ')') 
      {
        if (x2 == 0) 
        {
          if ((ch == '\'') && (x2 == 0)) 
          {
            fd2_type = 0;
            x2 = 1;
          }
          if ((isdigit(ch)) && (x2 == 0)) 
          {
            fd2_type = 1;
            x2 = 1;
          }
          if ((isalpha(ch)) && (x2 == 0)) 
          {
            fd2_type = 2;
            x2 = 1;
          }
        }
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field2[pi2] = '\0';

      if_comma = 0;
      if_blank = 0;
      if_quote = 0;

      p5 = strstr(field2, " ");
      if (p5) 
      {
        if_blank = 1;
      }

      p5 = strstr(field2, ",");
      if (p5) 
      {
        if_comma = 1;
      }

      p5 = strstr(field2, ";");
      if (p5) 
      {
        if_comma = 2;
      }

      p5 = strchr(field2, '\'');
      if (p5) 
      {
        if_quote = 1;
        fd2_type = 1;
      }

      strcpy(field2a, field2);

      if((fd2_type == 1) && (if_blank == 1) && (if_comma == 0) && (if_quote == 1))
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_1 subroutine #16 START");
          trace_rec_1();
        }

        if (global_st == 0) 
        {
          x3 = 0;
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field1, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
            }
          }

          if (x3 == 0) 
          {
            c_name++;
            snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
            strcpy(c_wkname, "C37F");
            strcat(c_wkname, wk_strg);
            s = strlen(c_wkname);
            c_wkname[s] = '\0';
            strcpy(field1a, c_wkname);

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
            strcpy(gw_variable[gv_ct].gv_type, "C");
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
            gv_ct++;
          }
        } 			/* END OF if(global_st == 0) */

        if (global_st == 1) 
        {
          x3 = 0;
          if (lv_ct > 0) 
          {
            for (I = 0; I < lv_ct; I++) 
            {
              ret = strcmp(field1, lw_variable[I].lv_name);
              ret1 = strcmp(sv_func, lw_variable[I].lv_func);
              if ((ret == 0) && (ret1 == 0)) 
              {
                x3 = 1;
              }
            }
          }

          if (x3 == 0) 
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
            strcpy(lw_variable[lv_ct].lv_cname, field1a);
            strcpy(lw_variable[lv_ct].lv_name, field1);
            strcpy(lw_variable[lv_ct].lv_type, "C");
            lw_variable[lv_ct].lv_lgth = 0;
            strcpy(lw_variable[lv_ct].lv_value, "0");
            lw_variable[lv_ct].lv_current_lgth = 0;
            lw_variable[lv_ct].lv_init = 0;
            strcpy(lw_variable[lv_ct].lv_literal, null_field);
            lw_variable[lv_ct].lv_use_ct = 0;
            lw_variable[lv_ct].lv_dec = 0;
            lv_ct++;
          }
        } 				/* END OF if(global_st == 1) */

        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(field1a, c_wkname);
        s = strlen(field2);

        if (s == 3)
        {
          field2a[0] = field2[1];
          field2a[1] = '\0';
          x3 = strlen(field2a);
        }

        if(s == 4)
        {
          field2a[0] = field2[2];
          field2a[1] = '\0';
          strcpy(field2, field2a);
          x3 = strlen(field2a);
        }

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
        strcpy(w_charlit[char_ct].clit_cname, field1a);
        strcpy(w_charlit[char_ct].clit_value, field2a);
        w_charlit[char_ct].clit_type = 3;
        w_charlit[char_ct].clit_lgth = x3;
        w_charlit[char_ct].clit_uct = 1;
        char_ct++;
        convert = 1;
        return;
      }

      }

      if ((if_comma == 0) && (if_blank == 0) && (fd2_type == 2) && (if_quote == 0)) 
      {
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
            x = strcmp(lw_variable[I].lv_type, "I");
            if (x == 0) 
            {
              fd1_type = 2;
            }
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
              x = strcmp(gw_variable[I].gv_type, "I");
              if (x == 0) 
              {
                fd2_type = 2;
              }
            }
          }
        }
      }

      if ((if_comma == 0) && (fd2_type == 2) && (if_convert == 0)) 
      {
        if_convert = 1;
        return;
      }

      if ((if_comma == 0) && (fd2_type == 0) && (convert == 0)) 
      {
        if (fd2_type == 0) 
        {
          c_name++;
          snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
          strcpy(c_wkname, "C37F");
          strcat(c_wkname, wk_strg);
          s = strlen(c_wkname);
          c_wkname[s] = '\0';
          strcpy(field3a, c_wkname);
          s = strlen(field2);

          if (s == 3) 
          {
            field2a[0] = field2[1];
            field2a[1] = '\0';
            x3 = strlen(field2a);
          }

          if(s == 4)
          {
            field2a[0] = field2[2];
            field2a[1] = '\0';
            strcpy(field2, field2a);
            x3 = strlen(field2a);
          }


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
          strcpy(w_charlit[char_ct].clit_cname, field3a);
          strcpy(w_charlit[char_ct].clit_value, field2a);
          w_charlit[char_ct].clit_type = 3;
          w_charlit[char_ct].clit_lgth = x3;
          w_charlit[char_ct].clit_uct = 1;
          char_ct++;
          return;
        }
      }

      if ((if_comma == 0) && (fd2_type == 1) && (if_blank == 0) && (if_quote == 1) && (convert == 0)) 
      {
        if (global_st == 0) 
        {
          x3 = 0;
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field1, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
            }
          }

          if (x3 == 0) 
          {
            c_name++;
            snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
            strcpy(c_wkname, "C37F");
            strcat(c_wkname, wk_strg);
            s = strlen(c_wkname);
            c_wkname[s] = '\0';
            strcpy(field1a, c_wkname);

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
            gv_ct++;
          }
        } 			/* END OF if(global_st == 0) */

        if (global_st == 1) 
        {
          c_name++;
          snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
          strcpy(c_wkname, "C37F");
          strcat(c_wkname, wk_strg);
          s = strlen(c_wkname);
          c_wkname[s] = '\0';
          strcpy(field1a, c_wkname);
 
          x3 = 0;
          if (lv_ct > 0) 
          {
            for (I = 0; I < lv_ct; I++) 
            {
              ret = strcmp(field1, lw_variable[I].lv_name);
              ret1 = strcmp(sv_func, lw_variable[I].lv_func);
              if ((ret == 0) && (ret1 == 0)) 
              {
                x3 = 1;
              }
            }
          }

          if (x3 == 0) 
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
            strcpy(lw_variable[lv_ct].lv_cname, field1a);
            strcpy(lw_variable[lv_ct].lv_name, field1);
            strcpy(lw_variable[lv_ct].lv_type, "I");
            lw_variable[lv_ct].lv_lgth = 0;
            strcpy(lw_variable[lv_ct].lv_value, "0");
            lw_variable[lv_ct].lv_current_lgth = 0;
            lw_variable[lv_ct].lv_init = 0;
            strcpy(lw_variable[lv_ct].lv_literal, null_field);
            lw_variable[lv_ct].lv_use_ct = 0;
            lw_variable[lv_ct].lv_dec = 0;
            lv_ct++;
          }
        } 				/* END OF if(global_st == 1) */

        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(field3a, c_wkname);
        s = strlen(field2);

        if (s == 3)
        {
          field2a[0] = field2[1];
          field2a[1] = '\0';
          x3 = strlen(field2a);
        }

        if(s == 4)
        {
          field2a[0] = field2[2];
          field2a[1] = '\0';
          strcpy(field2, field2a);
          x3 = strlen(field2a);
        }

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
        strcpy(w_charlit[char_ct].clit_cname, field3a);
        strcpy(w_charlit[char_ct].clit_value, field2a);
        w_charlit[char_ct].clit_type = 3;
        w_charlit[char_ct].clit_lgth = x3;
        w_charlit[char_ct].clit_uct = 1;
        char_ct++;
        convert = 1;
        return;
      }
    }

    if ((if_comma == 0) && (fd2_type == 1) && (if_quote == 0) && (if_convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_1 subroutine #7 START");
        trace_rec_1();
      }
      if_convert = 1;
    }

    if ((if_comma == 0) && (fd2_type == 1) && (if_quote == 0) && (if_convert == 0)) 
    {
      printf("\nc2_pass_2.c if_case_1 pass2-023 #1 Not Coded\n");
      printf("c2_pass_2.c rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      if_convert = 1;
      return;
    }

    if ((if_comma == 1) || (if_comma == 2)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_1 subroutine #8 START");
        trace_rec_1();
      }

      if ((if_blank == 0) && (fd2_type == 1)) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_1 subroutine #9 START");
          trace_rec_1();
        }

        if ((fd1_type == 2) && (fd2_type == 1)) 
        {
          if (traceflg == 1) 
          {
            strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_1 subroutine #10 START");
            trace_rec_1();
          }

          x3 = strlen(field2);
          c_name++;
          snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
          strcpy(c_wkname, "C37F");
          strcat(c_wkname, wk_strg);
          s = strlen(c_wkname);
          c_wkname[s] = '\0';
          strcpy(field3a, c_wkname);
          s = strlen(field2);

          pi2 = 0;
          for (I = 0; I < s; I++) 
          {
            ch = field2[I];
            if (ch != '\'') 
            {
              if (ch != '\\') 
              {
                field2a[pi2] = ch;
                pi2++;
              }
            }
          }
          field2a[pi2] = '\0';

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
          strcpy(w_charlit[char_ct].clit_cname, field3a);
          strcpy(w_charlit[char_ct].clit_value, field2a);
          w_charlit[char_ct].clit_type = 3;
          w_charlit[char_ct].clit_lgth = x3;
          w_charlit[char_ct].clit_uct = 1;
          char_ct++;
        }
        if_convert = 1;
        return;
      }
    }

    if ((if_comma == 1) && (if_blank == 0) && (if_convert == 0)) 
    {
      printf("\nc2_pass_2.c if_case_1 #3 pass2-024 Not Coded\n");
      printf("c2_pass_2.c rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      if_convert = 1;
      return;
    }

    if ((if_complex == 0) && (lbrack > 0) && (rbrack > 0)) 
    {
      printf("\nc2_pass_2.c if_case_1 #3 pass2-025 Not Coded\n");
      printf("c2_pass_2.c rct = %d p_string = %s", rct, p_string);
      erct++;
      if_convert = 1;
      convert = 1;
      return;
    }

  if ((if_complex == 1) && (if_convert == 0)) 				/* complex if statement	*/
  {
    printf("\nc2_pass_2.c if_case_1 #4 pass2-026 Not Coded\n");
    printf("c2_pass_2.c rct = %d p_string = %s", rct, p_string);
    erct++;
    if_convert = 1;
    convert = 1;
    return;
  }
}


void c2_pass2_if_2() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 START");
    trace_rec_1();
  }

  char ch, *p2, *p5;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];

  int pi;
  int pi2;
  int pi3;
  int I = 0;
  int x = 0;
  int x2 = 0;
  int x3 = 0;
  int x10 = 0;
  int x10a = 0;
  int x11a = 0;
  int x88 = 0;
  int x98 = 0;
  int if_complex = 0;
  int if_bracket = 0;
  int v = 0;
  int s = 0;
  int size = 0;

  int fd1_type = 0;
  int fd2_type = 0;
  int fd4_type = 0;
  int fd5_type = 0;
  int fd6_type = 0;

  int ret = 0;
  int ret1 = 0;

  char *p;

  p = strstr(p_string, "&&");
  if (p) {
    if_complex = 1;
  }

  p = strstr(p_string, "||");
  if (p) {
    if_complex = 1;
  }

  if (if_complex == 0) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 NoComplex");
      trace_rec_1();
    }

    p = strstr(p_string, "[");
    if (p) 
    {
      if_bracket = 1;
    }

    if (if_bracket == 1) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_pass_2_if_2 bracket = 1");
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
      x3 = 0;
      x2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != '[') 
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
        field1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';

      pi2 = 0;
      x3 = 0;
      x2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ']') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            fd2_type = 1;
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
            fd2_type = 2;
            x2 = 1;
          }
        }
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field2[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      if (ch == '.') 
      {
        x98 = 1;
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
          field3[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field3[pi2] = '\0';
      }

      p5 = strstr(field3, "[");
      if (p5) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 subroutine #10");
          trace_rec_1();
        }

        pi3 = 0;
        pi2 = 0;
        ch = field3[pi3];
        while (ch != '[') 
        {
          pi3++;
          ch = field3[pi3];
        }

        x2 = 0;
        pi3++;
        ch = field3[pi3];
        while (ch != ']') 
        {
          if (x2 == 0) 
          {
            if (isdigit(ch)) 
            {
              fd6_type = 1;
              x2 = 1;
            }
            if (isalpha(ch)) 
            {
              fd6_type = 2;
              x2 = 1;
            }
          }
          field6[pi2] = ch;
          pi2++;
          pi3++;
          ch = field3[pi3];
        }
        field6[pi2] = '\0';
      }

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

      pi2 = 0;
      x3 = 0;
      x2 = 0;
      fd5_type = 0;
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
        field5[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field5[pi2] = '\0';

      p5 = strstr(field5, "'");
      if (p5) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 subroutine #11");
          trace_rec_1();
        }

        pi2 = 0;
        s = strlen(field5);
        for (I = 0; I < s; I++) 
        {
          ch = field5[I];
          if (ch != '\'') 
          {
            field5a[pi2] = ch;
            pi2++;
          }
        }
        field5a[pi2] = '\0';
        
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
        strcpy(w_charlit[char_ct].clit_value, field5a);
        w_charlit[char_ct].clit_type = 3;
        s = strlen(field5a);
        w_charlit[char_ct].clit_lgth = s;
        w_charlit[char_ct].clit_uct = 1;
        char_ct++;

        convert = 1;
        return;
      }

      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        ret1 = strcmp("G", gw_variable[I].gv_type);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
          strcpy(ar_field5, gw_variable[I].gv_dsect);
          strcpy(ar_field6, gw_variable[I].gv_label);
          strcpy(ar_field7, gw_variable[I].gv_table);
          strcpy(ar_field8, gw_variable[I].gv_aname);
          strcpy(ar_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar_field11, gw_variable[I].gv_wk_strg);
          gw_variable[I].gv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < m_struc_ct; I++) 
        {
          ret = strcmp(field1, w_struc[I].st_wname);
          if (ret == 0) 
          {
            x3 = 1;
            break;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_pass_2.c c2_pass2_if_2 bracket = 1 pass2-027 field1 Not Found = %s\n",field1);
        printf("c2z_pass_2.c c2_pass2_if_2 bracket = 1 rct = %d p_string = %s",rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (fd2_type == 2) 
      {
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
            }
          }
        }

        if (x3 == 0) 
        {
          printf("\nc2z_pass_2.c c2_pass2_if_2 bracket = 1 pass2-028 field2 Not Found = %s\n",field2);
          printf("c2z_pass_2.c c2_pass2_if_2 bracket = 1 rct = %d p_string = %s",rct, p_string);
          erct++;
          convert = 1;
          return;
        }
      }

      if (x98 == 1) 				/* structure field if x98 == 1 */
      {
        v = strlen(p_string);
        x10 = 0;
        x10a = 1;
        x11a = 1;
        pi = 0;
        ch = p_string[pi];
        for (I = 0; I < v; I++) 
        {
          if (ch == '[') 
          {
            x10 = I;
            x10a++;
          }
          if (ch == ']') 
          {
            x11a++;
          }
          pi++;
          ch = p_string[pi];
        }

        /* printf("c2z_pass_2.c c2_pass2_if_2 #77 rct = %d x10 = %d x10a = %d
         * x11 = %d x11a = %d x12 = %d x13 = %d x14 = %d x15 = %d x16 =
         * %d\n",rct,x10,x10a,x11,x11a,x12,x13,x14,x15,x16); */

        if ((x10a == 4) && (x11a == 4)) 
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

          pi2 = 0;
          pi++;
          ch = p_string[pi];
          while (ch != '[') 
          {
            if (ch != '.') 
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
          while (ch != ']') 
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
          ch = p_string[pi];
          while (ch != ' ') 
          {
            field5[pi2] = ch;
            pi2++;
            pi++;
            ch = p_string[pi];
          }
          field5[pi2] = '\0';

          pi++;
          ch = p_string[pi];
          while (ch == ' ') 
          {
            pi++;
            ch = p_string[pi];
          }

          pi2 = 0;
          x2 = 0;
          ch = p_string[pi];
          while (ch != ')') 
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

            field6[pi2] = ch;
            pi2++;
            pi++;
            ch = p_string[pi];
          }
          field6[pi2] = '\0';

          if (fd4_type == 1) 
          {
            if (traceflg == 1) 
            {
              strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 subroutine #30");
              trace_rec_1();
            }
          }

          if (fd6_type == 0) 
          {
            if (traceflg == 1) 
            {
              strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 subroutine #13");
              trace_rec_1();
            }

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
            strcpy(w_charlit[char_ct].clit_value, field6);
            w_charlit[char_ct].clit_type = 3;
            w_charlit[char_ct].clit_lgth = 3;
            w_charlit[char_ct].clit_uct = 1;
            char_ct++;
          }
          convert = 1;
          return;
        }

        if ((x10a == 2) && (x11a == 2)) 
        {
          if (traceflg == 1) 
          {
            strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 subroutine #14");
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

          pi2 = 0;
          pi++;
          ch = p_string[pi];
          while (ch != ' ') 
          {
            if (ch != '.') 
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
          ch = p_string[pi];
          while (ch != ' ') 
          {
            field5[pi2] = ch;
            pi2++;
            pi++;
            ch = p_string[pi];
          }
          field5[pi2] = '\0';

          pi++;
          ch = p_string[pi];
          while (ch == ' ') 
          {
            pi++;
            ch = p_string[pi];
          }

          pi2 = 0;
          x2 = 0;
          ch = p_string[pi];
          while (ch != ')') 
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

            field6[pi2] = ch;
            pi2++;
            pi++;
            ch = p_string[pi];
          }
          field6[pi2] = '\0';

          if (fd6_type == 0) 
          {
            if (traceflg == 1) 
            {
              strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 subroutine #15");
              trace_rec_1();
            }

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
            strcpy(w_charlit[char_ct].clit_value, field6);
            w_charlit[char_ct].clit_type = 3;
            w_charlit[char_ct].clit_lgth = 3;
            w_charlit[char_ct].clit_uct = 1;
            char_ct++;
          }
          convert = 1;
          return;
        }
      }

      if (fd5_type == 2) 
      {
        p2 = strstr(field5, "\'");
        if (p2) 
        {
          if (traceflg == 1) 
          {
            strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 subroutine #16");
            trace_rec_1();
          }

          x88 = 1;
          pi2 = 0;
          pi = 0;
          pi++;
          ch = field5[pi];
          while (ch != '\'') 
          {
            field5a[pi2] = ch;
            pi2++;
            pi++;
            ch = field5[pi];
          }
          field5a[pi2] = '\0';
          pi2--;

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
          strcpy(w_charlit[char_ct].clit_value, field5a);
          w_charlit[char_ct].clit_type = 3;
          w_charlit[char_ct].clit_lgth = pi2;
          w_charlit[char_ct].clit_uct = 1;
          char_ct++;
          return;
        }
      }

      if ((fd5_type == 2) && (x88 == 0)) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 subroutine #17");
          trace_rec_1();
        }

        ret = strcmp(field5, "NULL");
        if (ret == 0) 
        {
          convert = 1;
          return;
        }

        x3 = 0;
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field5, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(field5a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
        }

        if (x3 == 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field5, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
              strcpy(field5a, gw_variable[I].gv_cname);
              gw_variable[I].gv_use_ct++;
            }
          }
        }

        if (x3 == 0) 
        {
          for (I = 0; I < m_struc_ct; I++) 
          {
            ret = strcmp(field5, w_struc[I].st_wname);
            if (ret == 0) 
            {
              x3 = 1;
              break;
            }
          }
        }

        if (x3 == 0) 
        {
          printf("\nc2z_pass_2.c c2_pass2_if_2 bracket = 1 pass2-028 field5 Not Found = %s\n",field5);
          printf("c2_pass2_if_2 bracket = 1 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
      }
    }

    if (if_bracket == 0) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 subroutine #23");
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
      x3 = 0;
      x2 = 0;
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
          x = strcmp(lw_variable[I].lv_type, "I");
          if (x == 0) 
          {
            fd1_type = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(gw_variable[I].gv_name, field1);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            x = strcmp(gw_variable[I].gv_type, "I");
            if (x == 0) 
            {
              fd1_type = 2;
            } 
            else 
            {
              fd1_type = 1;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_pass_2.c if_pass2_case_2 pass2-029 field1 Not Found = %s\n",field1);
        printf("c2z_pass_2.c if_pass2_case_2 rct = %d p_string = %s", rct,p_string);
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
              fd2_type = 1;
              x2 = 1;
            }

            if (isalpha(ch)) 
            {
              fd2_type = 2;
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

      x10 = 0;
      p = strstr(field2, "'");
      if (p) 
      {
        x10 = 1;
      }

      if ((fd2_type == 2) && (x10 == 0)) 
      {
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
            x = strcmp(lw_variable[I].lv_type, "I");
            if (x == 0) 
            {
              fd1_type = 2;
            }
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
              x = strcmp(gw_variable[I].gv_type, "I");
              if (x == 0) 
              {
                fd2_type = 2;
              }
            }
          }
        }

        if (x3 == 0) 
        {
          printf("\nc2z_pass_2.c if_pass2_case_2 pass2-030 field2 Not Found = %s\n",field2);
          printf("c2z_pass_2.c if_pass2_case_2 #1 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }
      }

      if ((fd1_type == 2) && (fd2_type == 0)) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 subroutine #19");
          trace_rec_1();
        }

        pi = 1;
        pi2 = 0;
        ch = field2[pi];
        while (ch != '\'') 
        {
          field2a[pi2] = ch;
          pi2++;
          pi++;
          ch = field2[pi];
        }
        field2a[pi2] = '\0';

        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(field2, c_wkname);

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
        w_charlit[char_ct].clit_type = 3;
        strcpy(w_charlit[char_ct].clit_cname, field2);
        strcpy(w_charlit[char_ct].clit_value, field2a);
        w_charlit[char_ct].clit_lgth = 1;
        w_charlit[char_ct].clit_uct = 1;
        char_ct++;
      }

      if ((fd1_type == 2) && (fd2_type == 2) && (x10 == 1)) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_2 subroutine #20");
          trace_rec_1();
        }

        pi = 1;
        pi2 = 0;
        ch = field2[pi];
        while (ch != '\'') 
        {
          field2a[pi2] = ch;
          pi2++;
          pi++;
          ch = field2[pi];
        }
        field2a[pi2] = '\0';

        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(field2, c_wkname);

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
        w_charlit[char_ct].clit_type = 3;
        strcpy(w_charlit[char_ct].clit_cname, field2);
        strcpy(w_charlit[char_ct].clit_value, field2a);
        w_charlit[char_ct].clit_lgth = 1;
        w_charlit[char_ct].clit_uct = 1;
        char_ct++;
        convert = 1;
      }
    }
  }

  if (if_complex == 1) 
  {
    printf("\nc2z_pass_2.c c2_pass2_if_2 pass2-031 NOT CODED\n");
    printf("c2z_pass_2.c c2_pass2_if_2 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  convert = 1;
}

void c2_pass2_if_7()
{
  char *p;
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  int s = 0;
  int size = 0;

  p = strstr(p_string, ".");
  if(p)
  {
      strcpy(tfield2, ".");
     
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(tfield2a, c_wkname);

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, tfield2a);
      strcpy(w_charlit[char_ct].clit_value, tfield2);
      w_charlit[char_ct].clit_lgth = 1;
      w_charlit[char_ct].clit_uct = 1;
      char_ct++;

      convert = 1;
      return;
  }
}


void c2_pass2_if_10() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_10_strcmp");
    trace_rec_1();
  }

  char ch, *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3b[VAR_LGTH];
 
  int pi;
  int pi2;
  int if_1 = 0;
  int if_2 = 0;
  int if_4 = 0;
  int I = 0;
  int x2 = 0;
  int x3 = 0;
  int x12 = 0;
  int s = 0;
  int size = 0;
  int ret = 0;
  int ret1 = 0;
  int x10 = 0;
  int fd2_type = 0;
  int fd4_type = 0;
  int fd6_type = 0;
  int w_uct = 0;

  p = strstr(p_string, ";");
  if (p) 
  {
    x10 = 1;
  }

  if (x10 == 0) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_10 subroutine #1");
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
    while (ch != ',') 
    {
      if (ch != '\"') 
      {
        tfield1[pi2] = ch;
        pi2++;
      }
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

    if_1 = 0;
    pi2 = 0;
    while (ch != ')') 
    {
      if (ch == '\"') 
      {
        if_1 = 1;
      }

      if (ch != '\"') 
      {
        tfield2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    if (if_1 == 1) 
    {
      if_4 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(tfield1, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            if_4 = 1;
            strcpy(tfield1a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
        }
      }

      if (if_4 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            if_2 = strcmp(tfield1, gw_variable[I].gv_name);
            if (if_2 == 0) 
            {
              if_4 = 1;
              strcpy(tfield1a, gw_variable[I].gv_cname);
              gw_variable[I].gv_use_ct++;
            }
          }
        }
      }

      if (if_4 == 0) 
      {
        printf("\nc2z_pass_2.c c2_pass2_if_10_strcmp pass2-032 tfield1 Not Found = %s\n",tfield1);
        printf("c2z_pass_2.c c2_pass2_if_10_strcmp rct = %d p_string = %s\n",rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x3 = strlen(tfield2);
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(tfield2a, c_wkname);

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, tfield2a);
      strcpy(w_charlit[char_ct].clit_value, tfield2);
      w_charlit[char_ct].clit_lgth = x3;
      w_charlit[char_ct].clit_uct = 1;
      char_ct++;

      s = strlen(p_string);

      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        pi++;
        ch = p_string[pi];
      }

      if (pi + 2 < s) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_10 subroutine #2");
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
        while (isalnum(ch)) 
        {
          tfield3[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        tfield3[pi2] = '\0';

        pi2 = 0;
        while (ch != ';') 
        {
          if (ch != '=') 
          {
            /*  tfield3a[pi2] = ch; */
            pi2++;
          }
          pi++;
          ch = p_string[pi];
        }
        /* tfield3a[pi2] = '\0'; */

        x3 = strlen(tfield2);
        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(tfield3b, c_wkname);

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
        w_charlit[char_ct].clit_type = 3;
        strcpy(w_charlit[char_ct].clit_cname, tfield3b);
        strcpy(w_charlit[char_ct].clit_value, tfield3);
        w_charlit[char_ct].clit_lgth = x3;
        w_charlit[char_ct].clit_uct = 2;
        char_ct++;
      }
    
      if_convert = 1;
      convert = 1;
      return;
    }

    if (if_1 == 0) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_10 subroutine #3");
        trace_rec_1();
      }

      x3 = strlen(tfield1);
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(tfield1a, c_wkname);

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, tfield1a);
      strcpy(w_charlit[char_ct].clit_value, tfield1);
      w_charlit[char_ct].clit_lgth = x3;
      w_charlit[char_ct].clit_uct = 1;
      char_ct++;

      convert = 1;
      if_convert = 1;
    }
  }

  if (x10 == 1) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_10 subroutine #4");
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
    while (ch != ',') 
   {
      tfield1[pi2] = ch;
      pi2++;
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
      }
    }

    if (x3 == 0) {
      for (I = 0; I < gv_ct; I++) {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_pass2_if_10_strcmp x10 == 1 pass2-033 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_pass_2.c c2_pass2_if_10_strcmp x10 == 1 rct = %d p_string = %s",rct, p_string);
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

    x12 = 0;
    x2 = 0;
    fd2_type = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (x12 == 0) 
      {
        if (ch == '"') 
        {
          x12 = 1;
        }
      }

      if (ch != '"') 
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

    if ((fd2_type == 1) && (x12 == 0)) 
    {
      printf("\nc2z_pass_2.c c2_pass2_if_10_strcmp x10 == 1 pass2-034 fd2_type == 1 && x12 == 0 NOT CODED\n");
      printf("c2z_pass_2.c c2_pass2_if_10_strcmp x10 == 1 rct = %d p_string = %s",rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd2_type == 2) && (x12 == 0)) 
    {
      printf("\nc2z_pass_2.c c2_pass2_if_10_strcmp x10 == 1 pass2-035 fd2_type == 2 && x12 == 0 NOT CODED\n");
      printf("c2z_pass_2.c c2_pass2_if_10_strcmp x10 == 1 rct = %d p_string = %s",rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (x12 == 1) 
    {
      w_uct++;
      x3 = strlen(tfield2);
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(tfield2a, c_wkname);

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, tfield2a);
      strcpy(w_charlit[char_ct].clit_value, tfield2);
      w_charlit[char_ct].clit_lgth = x3;
      w_charlit[char_ct].clit_uct = w_uct;
      char_ct++;
    }

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
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    fd4_type = 0;
    ch = p_string[pi];
    while (ch != ')') 
    {
      pi++;
      ch = p_string[pi];
    }
   
    if (fd4_type == 1) 
    {
      printf("\nc2z_pass_2.c c2_pass2_if_10_strcmp x10 == 1 pass2-036 fd4_type == 1 && x12 == 0 NOT CODED\n");
      printf("c2z_pass_2.c c2_pass2_if_10_strcmp x10 == 1 rct = %d p_string = %s",rct, p_string);
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

    ch = p_string[pi];
    while (ch != '=') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    fd6_type = 0;
    ch = p_string[pi];
    while (ch != ';') 
    {
      pi++;
      ch = p_string[pi];
    }
  
    if (fd6_type == 1) 
    {
      printf("\nc2z_pass_2.c c2_pass2_if_10_strcmp x10 == 1 pass2-037 fd6_type == 1 && x12 == 0 NOT CODED\n");
      printf("c2z_pass_2.c c2_pass2_if_10_strcmp x10 == 1 rct = %d p_string = %s",rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }
  convert = 1;
}

void c2_pass2_if_13() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_case_13 START");
    trace_rec_1();
  }

  char ch;
  char *p, *p3, *p4, *p5, *p6;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field4w[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field6a[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field11[VAR_LGTH];

  int fd3_type = 0;
  int fd6_type = 0;
  int fd10_type = 0;
  int fd11_type = 0;
  int pi;
  int pi2;
  int I = 0;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x80 = 0;
  int x85 = 0;
  int x90;
  int x100;
/*  int x100L; */
  int s = 0;
  int size = 0;
  int spec_char = 0;
  int spec_char_2 = 0;
  int fd1_var = 0;
  int fd3_var = 0;
  int fd4_var = 0;
  int fd6_var = 0;
  int ret = 0;
  int ret1 = 0;
  int complex_if = 0;
  int operand_1 = 0;
  int operand_2 = 0;
  int lbrack = 0;
  int rbrack = 0;

  c2_count_paren();

  p4 = strstr(p_string, "&&");
  if (p4)
  {
    complex_if = 1;
  }

  p4 = strstr(p_string, "||");
  if (p4)
  {
    complex_if = 1;
  }

  x85 = 0;
  lbrack = 0;
  rbrack = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[') 
    {
      lbrack++;
    }
    if (ch == ']') 
    {
      rbrack++;
    }
    if (ch == '(') 
    {
      x85++;
    }
    if (ch == ')') 
    {
      x85++;
    }
  }

  x100 = 0;
/*  x100L = 0; */
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[') 
    {
      x100++;
    }
    if (ch == ']') 
    {
      x100++;
 /*     x100L = I; */
    }
  }
   
  p = strstr(p_string, "&&");
  if (p) 
  {
    x3 = p - p_string;
  }

  p = strstr(p_string, "||");
  if (p) 
  {
    x3 = p - p_string;
  }

  p = strstr(p_string, "[");
  x2 = p - p_string;

  if ((complex_if == 1) && (lbrack == 0) && (rbrack == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c if_13 complex no[]");
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
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      if(ch == ')')
      {
        pi++;
        break;
      }
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    p = strstr(field1, "!");
    if(p)
    {
      convert = 1;
      return;
    }

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
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    x90 = 0;
    p = strstr(p_string, "&&");
    if(p)
    {
       x90 = 1;
    }

    p = strstr(p_string, "||");
    if(p)
    {
       x90 = 1;
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
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

if_13_skip1:

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
      field4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field4[pi2] = '\0';

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
      field5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';

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
      if (ch != '\\') 
      {
        field6[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field6[pi2] = '\0';

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

    operand_2 = 0;
    if (operand_2 == 0) 
    {
      p = strstr(field5, "==");
      if (p)
      {
        operand_2 = 1;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, "!=");
      if (p)
      {
        operand_2 = 2;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, "<=");
      if (p)
      {
        operand_2 = 3;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, ">=");
      if (p)
      {
        operand_2 = 4;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, "=");
      if (p)
      {
        operand_2 = 5;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, "<");
      if (p)
      {
        operand_2 = 6;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, ">");
      if (p)
      {
        operand_2 = 7;
      }
    }

    x80 = 0;
    p5 = strstr(field1, "[");
    if (p5)
    {
      x80 = 1;
    }

    if (x80 == 0) 
    {
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
          ret1 = strcmp("I", lw_variable[I].lv_type);
          if (ret1 == 0) 
          {
            fd1_var = 1;
          }
          ret1 = strcmp("C", lw_variable[I].lv_type);
          if (ret1 == 0) 
          {
            fd1_var = 2;
          }
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
            ret1 = strcmp("I", gw_variable[I].gv_type);
            if (ret1 == 0) 
            {
              fd1_var = 1;
            }
            ret1 = strcmp("C", gw_variable[I].gv_type);
            if (ret1 == 0) 
            {
              fd1_var = 2;
            }
            ret1 = strcmp("G", gw_variable[I].gv_type);
            if (ret1 == 0) 
            {
              fd1_var = 3;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_pass_2.c c2_pass2_if_13 pass2-038 field1 Not Found = %s\n",field1);
        printf("c2z_pass_2.c if_pass2_if_13 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if (x80 == 1) 
    {
      x2 = 0;
      pi2 = 0;
      pi = 0;
      ch = field1[pi];
      while (ch != '[') 
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd10_type = 1;
            x2 = 1;
          }

          if (isdigit(ch)) 
          {
            fd10_type = 2;
            x2 = 1;
          }
        }
        field10[pi2] = ch;
        pi2++;
        pi++;
        ch = field1[pi];
      }
      field10[pi2] = '\0';

      x2 = 0;
      pi2 = 0;
      pi++;
      ch = field1[pi];
      while (ch != ']') 
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd11_type = 1;
            x2 = 1;
          }

          if (isdigit(ch)) 
          {
            fd11_type = 2;
            x2 = 1;
          }
        }
        field11[pi2] = ch;
        pi2++;
        pi++;
        ch = field1[pi];
      }
      field11[pi2] = '\0';

      if (fd10_type == 2) 
      {
        printf("\nc2z_pass_2.c c2_pass2_if_13 pass2-039 math_lit Not coded = %s\n",field10);
        printf("c2z_pass_2.c if_pass2_if_13 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      if (fd11_type == 2) 
      {
        printf("\nc2z_pass_2.c c2_pass2_if_13 pass2-040 math_lit Not coded = %s\n",field11);
        printf("c2z_pass_2.c if_pass2_if_13 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    spec_char = 0;
    p6 = strstr(field3, "'");
    if (p6) 
    {
      spec_char = 1;
    }

    if ((fd3_type == 2) && (spec_char == 0)) 
    {
      return;
    }


    if((fd3_type == 0) && (fd6_type == 0) && (x90 == 1) && (spec_char == 1))		/* if((ch == '+') || (ch == '-'))  */
    {
      pi2 = 0;
      x3 = strlen(field3);
      for(I = 0; I < x3; I++)
      {
        ch = field3[I];
        if(ch != '\'')
        {
          field3a[pi2] = ch;
          pi2++;
        }
      }
      field3a[pi2] = '\0';

      strcpy(field3,field3a);
    
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(field3a, c_wkname);

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, field3a);
      strcpy(w_charlit[char_ct].clit_value, field3);
      w_charlit[char_ct].clit_lgth = pi2;
      w_charlit[char_ct].clit_uct = 1;
      char_ct++;

      pi2 = 0;
      x3 = strlen(field6);
      for(I = 0; I < x3; I++)
      {
        ch = field6[I];
        if(ch != '\'')
        {
          field6a[pi2] = ch;
          pi2++;
        }
      }
      field6a[pi2] = '\0';

      strcpy(field6,field6a);
    
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(field6a, c_wkname);

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, field6a);
      strcpy(w_charlit[char_ct].clit_value, field6);
      w_charlit[char_ct].clit_lgth = pi2;
      w_charlit[char_ct].clit_uct = 2;
      char_ct++;

      convert = 1;
      return;
    }

    if((fd3_type == 0) && (fd6_type == 2) && (x90 == 1) && (spec_char == 1))  /* if((ch == '$') && (process == 1)) */
    {
      pi2 = 0;
      x3 = strlen(field3);
      for(I = 0; I < x3; I++)
      {
        ch = field3[I];
        if(ch != '\'')
        {
          field3a[pi2] = ch;
          pi2++;
        }
      }
      field3a[pi2] = '\0';

      strcpy(field3,field3a);
    
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(field3a, c_wkname);

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, field3a);
      strcpy(w_charlit[char_ct].clit_value, field3);
      w_charlit[char_ct].clit_lgth = pi2;
      w_charlit[char_ct].clit_uct = 1;
      char_ct++;

      convert = 1;
      return;
    }


    if ((fd3_type == 1) && (spec_char == 0)) 
    {
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
          ret1 = strcmp("I", lw_variable[I].lv_type);
          if (ret1 == 0) 
          {
            fd3_var = 1;
          } 
          else 
          {
            fd3_var = 2;
          }
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
            ret1 = strcmp("I", gw_variable[I].gv_type);
            if (ret1 == 0) 
            {
              fd3_var = 1;
            } 
            else 
            {
              fd3_var = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_pass_2.c c2_pass2_if_13 pass2-041 field3 Not Found = %s\n",field3);
        printf("c2z_pass_2.c if_pass2_if_13 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    p3 = strchr(p_string, '[');
    if (!p3) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field4, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field4a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret1 = strcmp("I", lw_variable[I].lv_type);
          if (ret1 == 0) 
          {
            fd4_var = 1;
          } 
          else 
          {
            fd4_var = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field4, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field4a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret1 = strcmp("I", gw_variable[I].gv_type);
            if (ret1 == 0) 
            {
              fd4_var = 1;
            } 
            else 
            {
              fd4_var = 2;
            }
          }
        }
      }
    } 
    else 
    {
      strcpy(field4w, field1);
      pi2 = 0;
      x4++;
      ch = field4[x4];
      while (ch != ']') 
      {
        x4++;
        ch = field4[x4];
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field4w, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field4a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret1 = strcmp("I", lw_variable[I].lv_type);
          if (ret1 == 0) 
          {
            fd4_var = 1;
          } 
          else 
          {
            fd4_var = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field4w, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field4a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret1 = strcmp("I", gw_variable[I].gv_type);
            if (ret1 == 0) 
            {
              fd4_var = 1;
            } 
            else 
            {
              fd4_var = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(field1, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field1a, w_function[I].fn_cname);
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c pass2_if_case_13 pass2-042 field4w Not Found = %s\n",field4w);
      printf("c2z_pass_2.c if_pass2_if_13 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    spec_char_2 = 0;
    p6 = strstr(field6, "'");
    if (p6) 
    {
      spec_char_2 = 1;
    }

    if (fd6_type == 2) 
    {
      convert = 1;
      return;
    }

    if ((spec_char_2 == 0) && (fd6_type == 1)) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field6, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field6a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret1 = strcmp("I", lw_variable[I].lv_type);
          if (ret1 == 0) 
          {
            fd6_var = 1;
          } 
          else 
          {
            fd6_var = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field6, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field6a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret1 = strcmp("I", gw_variable[I].gv_type);
            if (ret1 == 0) 
            {
              fd6_var = 1;
            } 
            else 
            {
              fd6_var = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_pass_2.c c2_pass2_if_13 pass2-043 field6 Not Found = %s\n",field6);
        printf("c2z_pass_2.c if_pass2_if_13 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if ((fd1_var == 2) && (fd3_var == 0)) 
    {
      if (spec_char == 1) 
      {
        x3 = strlen(field3);
        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(field1a, c_wkname);

        s = strlen(field3);
        if(s == 4)
        {
          field3a[0] = field3[2];
          field3a[1] = '\0';
        }

        if(s == 3)
        {
          field3a[0] = field3[1];
          field3a[1] = '\0';
        }

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
        strcpy(w_charlit[char_ct].clit_cname, field1a);
        strcpy(w_charlit[char_ct].clit_value, field3a);
        w_charlit[char_ct].clit_type = 3;
        w_charlit[char_ct].clit_lgth = 1;
        w_charlit[char_ct].clit_uct = 1;
        char_ct++;
      }

      if (spec_char == 0) 
      {
        x3 = strlen(field3);
        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(field1a, c_wkname);

        s = strlen(field3);
        pi2 = 0;
        for (I = 0; I < s; I++) 
        {
          ch = field3[I];
          if (ch != '\'') 
          {
            field3a[pi2] = ch;
            pi2++;
          }
        }
        field3a[pi2] = '\0';

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
        w_charlit[char_ct].clit_type = 3;
        strcpy(w_charlit[char_ct].clit_cname, field1a);
        strcpy(w_charlit[char_ct].clit_value, field3a);
        w_charlit[char_ct].clit_lgth = 1;
        w_charlit[char_ct].clit_uct = 1;
        char_ct++;
      }
    }

    if ((fd4_var == 2) && (fd6_var == 2)) 
    {
      if (spec_char == 0) 
      {
        strcpy(a_string, "         CLC   ");
        strcat(a_string, field4a);
        strcat(a_string, ",");
        strcat(a_string, field6a);
        src_line();
        if (puncde == 1)
          trace_rec_3();
      }

      if (spec_char == 1) {
        strcpy(a_string, "         CLI   ");
        strcat(a_string, field4a);
        strcat(a_string, ",C");
        strcat(a_string, field6);
        src_line();
        if (puncde == 1)
          trace_rec_3();
      }
    }

    if ((fd4_var == 2) && (fd6_var == 0)) 
    {
      if (spec_char == 1) 
      {
        x3 = strlen(field6);
        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(field4a, c_wkname);

        s = strlen(field6);
        pi2 = 0;
        for (I = 0; I < s; I++) 
        {
          ch = field6[I];
          if (ch != '\'') 
          {
            field6a[pi2] = ch;
            pi2++;
          }
        }
        field6a[pi2] = '\0';

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
        w_charlit[char_ct].clit_type = 3;
        strcpy(w_charlit[char_ct].clit_cname, field4a);
        strcpy(w_charlit[char_ct].clit_value, field6a);
        w_charlit[char_ct].clit_lgth = 1;
        w_charlit[char_ct].clit_uct = 2;
        char_ct++;
      }
    }
    convert = 1;
    if_convert = 1;
  }

/* printf("c2z_pass_2.c rct = %d lbrack = %d rbrack = %d x2 = %d x3 = %d\n",rct,lbrack,rbrack,x2,x3); */


  if ((complex_if == 1) && (lbrack > 0) && (rbrack > 0) && (x2 < x3)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c if_13 complex []");
      trace_rec_1();
    }

    convert = 1;
    return;

    char ch;

    int pi;
    int pi2 = 0;
    int x2 = 0;

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if (ch != '(') 
      {
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if(ch != '*')
      {
        field2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != ' ')
    {
      field3[pi2] = ch;
      pi2++;
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
    while (ch != ')') 
    {
      if (isalnum(ch)) 
      {
        if(ch != '*')
        {
          field4[pi2] = ch;
          pi2++;
        }
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
    while(ch != ' ')
    {
      field5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
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
      if(ch != '*')
      {
        field6[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field6[pi2] = '\0';

    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
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
      if(ch != '*')
      {
        pi2++;
      }
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
      pi2++;
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
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
      if(ch != '*')
      {
        field9[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field9[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

    s = strlen(field4);

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, c_wkname);
    strcpy(w_charlit[char_ct].clit_value, field4);
    w_charlit[char_ct].clit_lgth = s;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

    s = strlen(field9);

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, c_wkname);
    strcpy(w_charlit[char_ct].clit_value, field9);
    w_charlit[char_ct].clit_lgth = s;
    w_charlit[char_ct].clit_uct = 2;
    char_ct++;
  }
  convert = 1;
  return;
}



void c2_pass2_while() 
{

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_while #1 START");
    trace_rec_1();
  }

  char ch;
  char *p, *p1;
  char tfield1[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int s = 0;
  int x3 = 0;
  int ret = 0;
  int while_isupper = 0;
  int while_not_equal = 0;
  int while_feof = 0;
  int while_isdigit = 0;
  int while_math = 0;
  int while_test = 0;
  int q100 = 0;
  int q101 = 0;

  while_convert = 0;
  while_opr = 0;

  while_parser_code = 0;
  inside_while = 1;

  p1 = strstr(p_string, "(1)");
  if(p1)
  {
    convert = 1;
    return;
  } 

  s = strlen(p_string);
  for(I = 0; I < s; I++)
  {
    if(p_string[I] == '(')
    {
      q100++;
    }
    if(p_string[I] == ')')
    {
      q100++;
    }
    if(p_string[I] == '[')
    {
      q101++;
    }
    if(p_string[I] == ']')
    {
      q101++;
    }
  }

  if((q100 == 8) && (q101 == 2))
  {
    convert = 1;
    return;
  }

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];

    p = strstr(p_string, "read");
    if ((p) && (while_test == 0)) 
    {
      while_opr = 43;
      while_test = 1;
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
      while_opr = 33;
      while_test = 1;
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
      while_isupper = 1;
      while_test = 1;
    }

    p = strstr(p_string, "isalpha");
    if ((p) && (while_test == 0)) 
    {
      while_opr = 8;
      while_test = 1;
    }

    p = strstr(p_string, "feof");
    if ((p) && (while_test == 0)) 
    {
      while_feof = 1;
      while_opr = 9;
      while_test = 1;
    }

    p = strstr(p_string, "isdigit");
    if ((p) && (while_test == 0)) 
    {
      while_isdigit = 1;
      while_opr = 7;
      while_test = 1;
    }

    p = strstr(p_string, "==");
    if ((p) && (while_test == 0)) 
    {
      while_opr = 99;
      while_test = 1;
    }

    p = strstr(p_string, "!=");
    if ((p) && (while_test == 0)) 
    {
      while_not_equal = 1;
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
      while_math = 4;
      while_test = 1;
    }

    p = strstr(p_string, ">");
    if ((p) && (while_test == 0)) 
    {
      while_math = 5;
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
  }

  if ((while_isupper == 1) && (while_convert == 0)) 			/* isupper */
  {
    x3 = 0;
    s = strlen(p_string);
    for (I = 0; I < s; I++) 
    {
      if (isdigit(ch)) 
      {
        x3 = 1;
      }
    }
    if (x3 == 0) 
    {
      convert = 1;
      return;
    }

    printf("\nc2z_pass_2.c c2_pass2_while NOCODE #1 (isupper) \n");
    printf("c2z_pass_2.c c2_pass2_while rct = %d p_string = %s", rct, p_string);
    /* c2_while_10(); */
    erct++;
    convert = 1;
    return;
  }

  if ((while_not_equal == 1) && (while_convert == 0)) 		/* while((ch != '\"') 	*/
  {
    c2_pass2_while_2();
    return;
  }

  if ((while_opr == 99) && (while_convert == 0)) 		/* while(ch == 1		*/
  {
    c2_pass2_while_1();
    return;
  }

  if ((while_feof == 1) && (while_convert == 0)) 		/* feof 	*/
  {
    /* c2_while_9(); */
    convert = 1;
    return;
  }

  if ((while_isdigit == 1) && (while_convert == 0)) 		/* isdigit	*/
  {
    c2_pass2_while_7();
    return;
  }

  if ((while_math == 5) && (while_convert == 0)) 		/* >		*/
  {
  
    c2_pass2_while_4();
    convert = 1;
    return;
  }

  if ((while_opr == 5) && (while_convert == 0)) 			/* >=	 	*/
  {
    c2_pass2_while_5();
    return;
  }

  if ((while_opr == 8) && (while_convert == 0)) 			/* isalpha	*/
  {
    c2_pass2_while_8();
    convert = 1;
    return;
  }

  if ((while_opr == 11) && (while_convert == 0)) 		/* isspace	*/
  {
    c2_pass2_while_11();
    return;
  }

  if ((while_opr == 12) && (while_convert == 0)) 		/* isalnum	*/
  {
    c2_pass2_while_12();
    return;
  }

  if ((while_opr == 13) && (while_convert == 0)) 		/* STRCMP	*/
  {
    c2_pass2_while_13();
    return;
  }

  if ((while_opr == 33) && (while_convert == 0)) 		/* strchr	*/
  {
    c2_pass2_while_33();
    return;
  }

  if ((while_opr == 6) && (while_convert == 0))
  {
    convert = 1;
    return;
  }

  if ((while_math == 4) && (while_convert == 0)) 		
  {
    c2_pass2_while_4();
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
    c2_pass2_while_14();
    convert = 1;
    return;
  }

  if (while_convert == 0) 
  {
    /* c2_while_15(); */
    printf("c2z_pass_2.c c2_while_15 NOT CODED\n");
    printf("c2z_pass_2.c rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }
}

void c2_pass2_while_1() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_1 START");
    trace_rec_1();
  }

  int fd3_type = 0;
  int pi;
  int pi2;
  int x2 = 0;
  int s = 0;
  int size = 0;
  int I = 0;
  int x20 = 0;

  char ch, *p;
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];\
  
  s = strlen(p_string);
  x20 = 0;
  for(I = 0; I < s; I++)
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
  }


  if(x20 == 4)
  {

    convert = 1;
    return;
  }

  inside_while = 1;

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
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

  fd3_type = 0;
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

  p = strstr(tfield3, "'");
  if (p) 
  {
    fd3_type = 0;
  }

  if (fd3_type == 1) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_1 subroutine #1");
      trace_rec_1();
    }
    while_convert = 1;
    convert = 1;
  }

  if (fd3_type == 2) 
  {
    convert = 1;
    return;
  }

  if (fd3_type == 0) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_1 subroutine #2");
      trace_rec_1();
    }

    s = strlen(tfield3);
    pi2 = 0;
    for (I = 0; I < s; I++) 
    {
      ch = tfield3[I];
      if (ch != '\'') 
      {
        tfield3a[pi2] = ch;
        pi2++;
      }
    }
    tfield3a[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

    s = strlen(tfield3a);

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, c_wkname);
    strcpy(w_charlit[char_ct].clit_value, tfield3a);
    w_charlit[char_ct].clit_lgth = s;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;

    while_convert = 1;
    convert = 1;
  }
}

void c2_pass2_while_2() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_2 START");
    trace_rec_1();
  }

  char *p, *p2;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield3b[VAR_LGTH];
  char tfield4a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];
  char tfield7b[VAR_LGTH];
  char tfield8[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int s;
  int x = 0;
  int size;
  int x2 = 0;
  int x80 = 0;
  int wh_3 = 0;
  int wh_4 = 0;
  int wh_5 = 0;
  int wh_8 = 0;
  int wh_9 = 0;
  int x5 = 0;
  int v = 0;
  int ret = 0;
  int ret1 = 0;
  int operand_1 = 0;
  int var_ci_1 = 0;
  int var_ci_3 = 0;
  int whfd3_type = 0;
  int whfd5_type = 0;
  int cd3_type = 0;
  int fd3_type = 0;
  int fd7_type = 0;
  int while_complex = 0;

  p = strstr(p_string,"fgets");
  if(p)
  {
     convert = 1;
     return;
  } 

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

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '&') 
    {
      x5++;
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
    while (ch != ' ') 
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
    while (ch != ' ') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    x = 0;
    p = strstr(p_string, "\'");
    if(p)
    {
      x = p - p_string;
    }

    if (x > 0) 
    {
      pi2 = 0;
      pi = x;
      ch = p_string[pi];
      tfield3[pi2] = ch;
      pi2++;
    }

    whfd3_type = 0;
    x80 = 0;
    x2 = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != '\n')
    {
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

      if (ch == '\'')
      {
        x80 = 1;    
      }
      if (ch == '\"')
      {
        x80 = 1;
      }
  
      if (ch != '\'') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
      if(ch == ')')
      {
        break;
      }
    }
    tfield3[pi2] = '\0';
 
    s = strlen(tfield3);
    for(I=0; I < s; I++)
    {
      if(tfield3[I] == '\\')
      {
         if(tfield3[I+1] == '0')
         {
           x80 = 0;
           break;
         }
       }
    }

    if(x80 == 1)
    {
      pi2 = 0;
      s = strlen(tfield3);
      for(I=0; I < s; I++)
      {
        if(tfield3[I] != '\\')
        {
           tfield3a[pi2] = tfield3[I];
           pi2++;
        }
      }
      tfield3a[pi2] = '\0';
      strcpy(tfield3,tfield3a);
    }


    if(x80 == 1)
    {

      strcpy(tfield3a,tfield3);
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(tfield4a, c_wkname);

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, tfield4a);
      strcpy(w_charlit[char_ct].clit_value, tfield3a);
      w_charlit[char_ct].clit_lgth = 1;
      w_charlit[char_ct].clit_uct = 1;
      char_ct++;
      convert = 1;
      return;
    } 
      

    if ((cd3_type == 1) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_2 subroutine #2");
        trace_rec_1();
      }
      convert = 1;
    }

    if ((whfd3_type == 1) && (convert == 0))
    {
      var_ci_3 = 3;
    }

    wh_8 = 0;
    wh_9 = 0;
    p = strstr(tfield3, "\"");
    if (p)
    {
      wh_8 = 1;
    }

    p = strstr(tfield3, "\0");
    if (p)
    {
      wh_9 = 1;
    }

    p = strstr(tfield3, "\n");
    if (p)
    {
      wh_9 = 1;
    }

    wh_3 = 0;
    if ((wh_8 != 1) && (wh_9 != 1) && (lv_ct > 0) && (whfd3_type != 1)) 
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

    if ((wh_3 == 0) && (wh_8 != 1) && (wh_9 != 1) && (whfd3_type != 1)) 
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

    if ((wh_3 == 0) && (wh_8 != 1) && (wh_9 != 1) && (whfd3_type != 1)) 
    {
      printf("\nc2z_pass_2.c while_case_2 pass2-012 complex = 0 tfield3 Not Found = %s\n",tfield3);
      printf("c2z_pass_2.c while_case_2 rct = %d p_string = %s", rct, p_string);
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

    if (wh_8 == 1) 
    {
    }

    if (wh_9 == 1) 
    {
    }

    if ((var_ci_1 == 2) && (var_ci_3 == 2)) 
    {
      return;
    }
  }

  if ((while_complex == 1) && (x5 != 4)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_2 subroutine #4");
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
 
    fd3_type = 0;
    x2 = 0;
    pi2 = 0;
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
      if(ch == '\'')
      {
         
         pi++;
         ch = p_string[pi];
         while(ch != '\'')
         {
            tfield3[pi2] = ch;
            pi2++;
            pi++;
            ch = p_string[pi];
         }
      }
      else
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

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    c2_white();

    x2 = 0;
    pi2 = 0;
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
      printf("\nc2z_pass_2.c while_case_2 == 1 pass2-013 x5 != 4 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_pass_2.c while_case_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd3_type == 2) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_2 subroutine #5");
        trace_rec_1();
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
        printf("\nc2z_pass_2.c while_case_2 == 1 x5 pass2-014 != 4 tfield3 Not Found = %s\n",tfield3);
        printf("c2z_pass_2.c while_case_2 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if (fd3_type == 0) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_2 subroutine #6");
        trace_rec_1();
      }

      tfield3a[0] = tfield3[1];
      tfield3a[1] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(tfield3b, c_wkname);

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, tfield3b);
      strcpy(w_charlit[char_ct].clit_value, tfield3a);
      w_charlit[char_ct].clit_lgth = 1;
      w_charlit[char_ct].clit_uct = 1;
      char_ct++;
    }

    if (whfd5_type == 2) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_2 subroutine #8");
        trace_rec_1();
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
        printf("\nc2z_pass_2.c while_case_2 == 1 pass2-015 tfield5 Not Found = %s\n",tfield3);
        printf("c2z_pass_2.c while_case_2 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if (fd7_type == 2) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_2 subroutine #9");
        trace_rec_1();
      }

      p2 = strstr(tfield7, "\'");
      if (p2) 
      {
        pi = 0;
        pi2 = 0;
        pi++;
        ch = tfield7[pi];
        while (ch != '\'') 
        {
          tfield7a[pi2] = ch;
          pi2++;
          pi++;
          ch = tfield7[pi];
        }
        tfield7a[pi2] = '\0';

        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(tfield7b, c_wkname);

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
        w_charlit[char_ct].clit_type = 3;
        strcpy(w_charlit[char_ct].clit_cname, tfield7b);
        strcpy(w_charlit[char_ct].clit_value, tfield7a);
        w_charlit[char_ct].clit_lgth = 1;
        w_charlit[char_ct].clit_uct = 1;
        char_ct++;
      }

      if (!p2) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_2 subroutine #10");
          trace_rec_1();
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
          printf("\nc2z_pass_2.c c2_while_2 pass2-016 x5 != 4 tfield7 Not Found = %s\n",tfield7);
          printf("c2z_pass_2.c c2_while_2 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }
      }
    }

    while_convert = 1;
    convert = 1;
    return;
  }



  if ((while_complex == 1) && (x5 == 4)) 
  {

    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_2 subroutine #12");
      trace_rec_1();
    }

    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2_pass2_while_2 x5 = 4 complex = 2");
      trace_rec_1();
    }

    char ch;

    int pi;
    int pi2;

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
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            fd3_type = 1;
          }

          if (isalpha(ch)) 
          {
            fd3_type = 2;
          }
        }
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

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    c2_white();

    x2 = 0;
    pi2 = 0;
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          fd7_type = 1;
        }

        if (isalpha(ch)) 
        {
          fd7_type = 2;
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
          x2 = 2;
        }
      }
      pi2++;
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    c2_white();

    pi2 = 0;
    while (ch != ' ') 
    {
      pi2++;
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          x2 = 2;
        }
      }
      tfield8[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield8[pi2] = '\0';

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, c_wkname);
    strcpy(w_charlit[char_ct].clit_value, tfield3);
    w_charlit[char_ct].clit_lgth = 2;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, c_wkname);
    strcpy(w_charlit[char_ct].clit_value, tfield7);
    w_charlit[char_ct].clit_lgth = 2;
    w_charlit[char_ct].clit_uct = 2;
    char_ct++;

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, c_wkname);
    strcpy(w_charlit[char_ct].clit_value, tfield8);
    w_charlit[char_ct].clit_lgth = 2;
    w_charlit[char_ct].clit_uct = 3;
    char_ct++;
  }

  while_convert = 1;
  convert = 1;
  return;
}

void c2_pass2_while_5() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_5");
    trace_rec_1();
  }

  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while (ch != '=') 
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
 
  while_convert = 1;
  convert = 1;
  return;
}

void c2_pass2_math() 
{
  
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_math START");
    trace_rec_1();
  }

  char ch;
  char *p, *p2, *p8, *p9;

  int pi;
  int x = 0;
  int x1 = 0;
  int x2 = 0;
  int op_1 = 0;
  int L1 = 0;
  int R1 = 0;
  int L2 = 0;
  int R2 = 0;
  int I = 0;
  int s = 0;
  int math_plus = 0;
  int math_minus = 0;
  int math_mult = 0;
  int math_div = 0;
  int math = 0;
  int math1 = 0;

  p = strstr(p_string, "=");
  if (p) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_math subroutine #1");
      trace_rec_1();
    }

    p2 = strstr(p_string, "-1");
    if (p2)
    {
      math1 = 1;
    }

    math = 0;
    s = strlen(p_string);

    for (I = 0; I < s; I++) 
    {
      ch = p_string[I];
      if (ch == '+') 
      {
        math_plus++;
        math = 1;
      }

      if ((ch == '-') && (math1 == 0)) 
      {
        math_minus++;
        math = 1;
      }

      if (ch == '*') 
      {
        math_mult++;
        math = 1;
      }

      if (ch == '/') 
      {
        math_div++;
        math = 1;
      }

      if (math == 1) {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_pass_2.c c2_math_99 BRANCH");
          trace_rec_1();
        }

        c2_pass2_math_99();
        convert = 1;
        return;
      }
    }
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_math subroutine #2");
    trace_rec_1();
  }

  op_1 = 1;

  p8 = strchr(p_string, '(');
  p9 = strchr(p_string, ')');

  s = strlen(p_string);
  pi = 0;
  x = 0;
  x2 = 0;
  L1 = 0;
  R1 = 0;
  L2 = 0;
  R2 = 0;
  I = 0;

  ch = p_string[pi];
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if ((ch != '=') && (x2 != 1) && (x != 1)) 
    {
      if (ch == '[') 
      {
        L1++;
        x2 = 0;
      }
    }

    if (ch == '=') 
    {
      x = 1;
      x1 = I;
      break;
    }

    if ((x == 1) && (ch != ';')) 
    {
      if (ch == '[') 
      {
        R1++;
      }
    }
  }

  x2 = 0;
  for (I = x1; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[') 
    {
      L2++;
    }
    if (ch == ']') 
    {
      R2++;
    }
  }

  if ((op_1 == 1) && (L1 == 0) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_math1 Branch");
      trace_rec_1();
    }

    c2_pass2_math_1();
    return;
  }

  if ((op_1 == 1) && (L1 == 0) && (R1 == 0) && (L2 == 1) && (R2 == 1) && (!p8) && (!p9)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_math2 SKIP");
      trace_rec_1();
    }

    /* c2_math_2(); */
    return;
  }

  if ((op_1 == 1) && (L1 == 1) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_5 Branch");
      trace_rec_1();
    }

    c2_pass2_math_5();
    convert = 1;
    return;
  }

  if ((op_1 == 1) && (L1 > 1) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9)) 		/* in_stack[ndx][0] = '\0'  */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_math_9 SKIP");
      trace_rec_1();
    }

    /* c2_math_9(); */
    return;
  }

  if ((op_1 == 1) && (L1 == 1) && (L2 == 0) && (R2 == 0) && (p8) && (p9)) 		/* iv_stack[ndx] = rdp_set();	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_math_7 SKIP");
      trace_rec_1();
    }

    /* c2_math_7(); */
    return;
  }

  if ((op_1 == 1) && (p8) && (p9) && (L1 == 0) && (R1 == 0) && (math == 0)) 			/*   Match('='); */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_6 BRANCH");
      trace_rec_1();
    }

    c2_pass2_math_6();
    return;
  }

  if ((L1 > 0) && (R1 > 0) && (L2 > 0) && (R2 > 0)) 			/* byte_array[x] = temp_byte[z]);   */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_math_98 SKIP");
      trace_rec_1();
    }

    /* c2_math_98(); */
    return;
  }
}

void c2_pass2_math_1() 			/*  single  x = 7 */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_1 START #1");
    trace_rec_1();
  }

  char ch, *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  int fd2_type = 0;
  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int I = 0;
  int s = 0;
  int size = 0;
  int ret = 0;
  int ret1 = 0;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x3 = 0;
  while ((ch != ' ') && (x3 == 0)) 
  {
    if (ch == '=') 
    {
      x3 = 1;
    } 
    else 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
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
      break;
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
        gw_variable[I].gv_use_ct++;
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_pass_2.c c2_pass2_math_1 pass2-017 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_pass_2.c c2_pass2_math_1 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch != '=') 
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

  x2 = 0;
  pi2 = 0;
  while (ch != ';') 
  {
    if (x2 == 0) 
    {
      if (isdigit(ch)) 
      {
        fd2_type = 1;
        x2 = 1;
      }
      if (isalpha(ch)) 
      {
        fd2_type = 2;
        x2 = 1;
      }
    }
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  if ((x4 == 0) && (fd2_type == 1)) 		/* if field2 is a numeric math_lit	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_1 START #2");
      trace_rec_1();
    }

    p = strstr(tfield2, "\'");
    if(p)
    {
      pi2 = 0;
      s = strlen(tfield2);
      for(I=0; I < s; I++)
      {
        ch = tfield2[I];
        if(ch != '\'')
        {
          tfield2a[pi2] = ch;
          pi2++;
        }
      }
      tfield2a[pi2] = '\0';

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, c_wkname);
      strcpy(w_charlit[char_ct].clit_value, tfield2a);
      w_charlit[char_ct].clit_lgth = 1;
      w_charlit[char_ct].clit_uct = 1;
      char_ct++;

      convert = 1;
      return;
    }

    convert = 1;
    return;
  }

  if ((x4 == 2) && (x5 == 1) && (fd2_type == 0)) 		/* if field2 equals ' '	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_1 START");
      trace_rec_1();
    }

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield1a, c_wkname);

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

    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, tfield1a);
    strcpy(w_charlit[char_ct].clit_value, " ");
    w_charlit[char_ct].clit_lgth = 1;
    w_charlit[char_ct].clit_uct = 1;
  }

  convert = 1;
  return;
}

void c2_pass2_math_5()  
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_5 START");
    trace_rec_1();
  }

  char ch;
  char *p, *p1, *p2, *p3;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4a[VAR_LGTH];
  char tfield3b[VAR_LGTH];

  int pi;
  int pi2;
  int x = 0;
  int x2 = 0;
  int x3 = 0;
  int x99 = 0;
  int m5_3 = 0;
  int m5_6 = 0;
  int m5_7 = 0;

  int m5fd1_type = 0;
  int m5fd2_type = 0;
  int m5fd3_type = 0;

  int I = 0;
  int s = 0;
  int s1 = 0;
  int size = 0;
  int ret = 0;
  int ret1 = 0;

  p1 = strstr(p_string, "[");
  p2 = strstr(p_string, "]");
  p3 = strstr(p_string, ".");

  if ((!p1) && (!p2) && (!p3)) 
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    m5fd1_type = 0;

    while (ch != '[') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    m5_3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        m5_3 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        m5_7 = strcmp(lw_variable[I].lv_type, "I");
        if (m5_7 == 0) 
        {
          m5fd1_type = 2;
        }

        m5_7 = strcmp(lw_variable[I].lv_type, "C");
        if (m5_7 == 0) 
        {
          m5fd1_type = 1;
        }
      }
    }

    if (m5_3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        m5_6 = strcmp(field1, gw_variable[I].gv_name);
        if (m5_6 == 0) 
        {
          m5_3 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          m5_7 = strcmp(gw_variable[I].gv_type, "I");
          if (m5_7 == 0) 
          {
            m5fd1_type = 2;
          }

          m5_7 = strcmp(gw_variable[I].gv_type, "C");
          if (m5_7 == 0) 
          {
            m5fd1_type = 1;
          }

          m5_7 = strcmp(gw_variable[I].gv_type, "G");
          if (m5_7 == 0) 
          {
            m5fd1_type = 3;
          }
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_pass2_math_5 pass2-044 field1 Not Found = %s\n",field1);
      printf("c2z_pass_2.c c2_pass2_math_5 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    x2 = 0;
    while (ch != ']') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          m5fd2_type = 2;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          m5fd2_type = 1;
          x2 = 1;
        }
      }
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    if (m5fd2_type == 2) 
    {
      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1;
          strcpy(field2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          m5_7 = strcmp(lw_variable[I].lv_type, "I");
          if (m5_7 == 0) 
          {
          }

          m5_7 = strcmp(lw_variable[I].lv_type, "C");
          if (m5_7 == 0) 
          {
          }
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field2, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            m5_7 = strcmp(gw_variable[I].gv_type, "I");
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("\nc2z_pass_2.c c2_pass2_math_5 pass2-045 field2 Not Found = %s\n",field2);
        printf("c2z_pass_2.c c2_pass2_math_5 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    while (ch != '=') 
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

    x2 = 0;
    pi2 = 0;
    s = strlen(p_string);
    while ((pi < s) && (ch != ';')) 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          m5fd3_type = 2;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          m5fd3_type = 1;
          x2 = 1;
        }
      }
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    x3 = 0;
    s = strlen(p_string);
    for (I = 0; I < s; I++) 
    {
      ch = p_string[I];
      if (ch == '[')
      {
        x3++;
      }
      if (ch == ']')
      {
        x3++;
      }
    }

    x = 99;
    p = strstr(field3, "'\0'");

    if ((p) && (x3 == 2) && (m5fd3_type != 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_5 field3");
        trace_rec_1();
      }

      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1;
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field1, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1;
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("\nc2z_pass_2.c c2_pass2_math_5 pass2-046 field3 Not Found = %s\n",field3);
        printf("c2z_pass_2.c c2_pass2_math_5 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      ret = strcmp("0", field2);
      if ((ret == 0) && (x != 99)) 
      {

      } 
      else 
      {
        if ((m5fd3_type == 2) && (x != 99)) 
        {
          printf("\nc2z_pass_2.c c2_math_5 pass2-047 field3 type == 2 ");
          printf("c2z_pass_2.c c2_math_5 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }
      }

      convert = 1;
    }

    if ((m5fd2_type == 1) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_math_5 field2 type == 1");
        trace_rec_1();
      }

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(field2a, c_wkname);

      s = strlen(field2);
      x99 = 0;
      p1 = strstr(field2, "-");
      if (p1) 
      {
        x99 = 1;
      }

      s1 = s + 1;
      if (x99 == 1) 
      {
        strcpy(tfield3b, field2);
        pi2 = 0;
        for (I = 0; I < s1; I++) 
        {
          ch = tfield3b[I];
          if (ch != '-') 
          {
            field2[pi2] = ch;
            pi2++;
          }
        }
        field2[pi2] = '\0';
      }
    }

    if ((m5fd3_type == 1) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_math_5 field3 type == 1");
        trace_rec_1();
      }

      convert = 1;
    }

    if ((m5fd1_type == 1) && (m5fd3_type == 0) && (convert == 0)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_math_5 field3 math_lit");
        trace_rec_1();
      }

      x = 1;
      pi2 = 0;
      ch = field3[x];
      while (ch != '\'') 
      {
        field4a[pi2] = ch;
        pi2++;
        x++;
        ch = field3[x];
      }
      field4a[pi2] = '\0';

      strcpy(field3, field4a);

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(field3a, c_wkname);

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, field3a);
      strcpy(w_charlit[char_ct].clit_value, field3);
      w_charlit[char_ct].clit_lgth = 1;
      w_charlit[char_ct].clit_uct = 1;
      char_ct++;
    }

    x = 99;

    if ((!p) && (convert == 0) && (x != 99)) 				/* not a math_lit 		*/
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_math_5 field3 numeric");
        trace_rec_1();
      }

      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1; 
          x3 = strcmp("I", lw_variable[I].lv_type);
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field1, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1; 
            x3 = strcmp("I", gw_variable[I].gv_type);
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("\nc2z_pass_2.c c2_math_5 pass2-048 field1 Not Found = %s\n", field1);
        printf("c2z_pass_2.c c2_math_5 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (m5fd3_type == 2) 
      {
        m5_3 = 0;
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field3, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            m5_3 = 1; 
            strcpy(field3a, lw_variable[I].lv_cname);
          }
        }

        if (m5_3 == 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            m5_6 = strcmp(field3, gw_variable[I].gv_name);
            if (m5_6 == 0) 
            {
              m5_3 = 1; 
              strcpy(field3a, gw_variable[I].gv_cname);
            }
          }
        }

        if (m5_3 == 0) 
        {
          printf("\nc2z_pass_2.c c2_math_5 pass2-049 field3 Not Found = %s\n",field3);
          printf("c2z_pass_2.c c2_math_5 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }
      } 
      else 
      {
        strcpy(field3a, field3);
      }

      if (m5fd1_type != 3) 
      {
        if (m5fd2_type == 1) 
        {
          strcpy(a_string, "*         ZAP   C370U,=P'");
          strcat(a_string, field2);
          strcat(a_string, "'");
          strcpy(wk_remark, " a[x] = ch ");
          write_remark();
          if (puncde == 1)
          {
            trace_rec_3();
          }
          work_use_ct[48]++;
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1)
        {
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         LARL  R9,C370L8");
        src_line();
        if (puncde == 1)
        {
          trace_rec_3();
        }
        work_use_ct[9]++;

        strcpy(a_string, "         PACK  ");
        strcat(a_string, "0(8,R9),0(8,R8)");
        strcpy(wk_remark, " a[x] = ch ");
        write_remark();
        if (puncde == 1)
        {
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1)
        {
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVB   R2,0(7,R9)");
        src_line();
        if (puncde == 1)
        {
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1a);
        src_line();
        if (puncde == 1)
        {
          trace_rec_3();
        }

        strcpy(a_string, "         LR    R1,R9");
        src_line();
        if (puncde == 1)
        {
          trace_rec_3();
        }

        strcpy(a_string, "         AR    R1,R2");
        src_line();
        if (puncde == 1)
        {
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field3a);
        src_line();
        if (puncde == 1)
        {
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   0(");
        strcat(a_string, "R9,R1),");
        strcat(a_string, "0(R8)");
        src_line();
        if (puncde == 1)
        {
          trace_rec_3();
        }

        math_convert = 1;
      }

      if (m5fd1_type == 3) /* array processing		*/
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_pass_2.c  c2_math_5 array");
          trace_rec_1();
        }
        return;
      }
    }
  }

  if ((p1) && (p2) && (!p3)) 
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    m5fd1_type = 0;

    while (ch != '[') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    m5_3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        m5_3 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        m5_7 = strcmp(lw_variable[I].lv_type, "I");
        if (m5_7 == 0) 
        {
          m5fd1_type = 2;
        }

        m5_7 = strcmp(lw_variable[I].lv_type, "C");
        if (m5_7 == 0) 
        {
          m5fd1_type = 1;
        }
      }
    }

    if (m5_3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        m5_6 = strcmp(field1, gw_variable[I].gv_name);
        if (m5_6 == 0) 
        {
          m5_3 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          m5_7 = strcmp(gw_variable[I].gv_type, "I");
          if (m5_7 == 0) 
          {
            m5fd1_type = 2;
          }

          m5_7 = strcmp(gw_variable[I].gv_type, "C");
          if (m5_7 == 0) 
          {
            m5fd1_type = 1;
          }

          m5_7 = strcmp(gw_variable[I].gv_type, "G");
          if (m5_7 == 0) 
          {
            m5fd1_type = 3;
          }
        }
      }
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    x2 = 0;
    while (ch != ']') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          m5fd2_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          m5fd2_type = 1;
          x2 = 1;
        }
      }
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';


    if (m5fd2_type == 2) 
    {
      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1;
          strcpy(field2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field2, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            m5_7 = strcmp(gw_variable[I].gv_type, "I");
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("\nc2z_pass_2.c c2_pass2_math_5 pass2-050 field2 Not Found = %s\n",field2);
        printf("c2z_pass_2.c c2_pass2_math_5 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    while (ch != '=') 
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

    x2 = 0;
    pi2 = 0;
    s = strlen(p_string);
    while ((pi < s) && (ch != ';')) 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          m5fd3_type = 2;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          m5fd3_type = 1;
          x2 = 1;
        }
      }
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    if ((m5fd1_type == 3) && (m5fd2_type == 1) && (m5fd3_type == 1) && (convert == 0)) 
    {
      convert = 1;
    }

    if ((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 1) && (convert == 0)) 
    {
      convert = 1;
    }

    if ((m5fd1_type == 1) && (m5fd2_type == 1) && (m5fd3_type == 1) && (convert == 0))
    {
      x = 1;
      pi2 = 0;
      ch = field3[x];
      while (ch != '\'') 
      {
        field4a[pi2] = ch;
        pi2++;
        x++;
        ch = field3[x];
      }
      field4a[pi2] = '\0';

      strcpy(field3, field4a);

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(field3a, c_wkname);

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, field3a);
      strcpy(w_charlit[char_ct].clit_value, field3);
      w_charlit[char_ct].clit_lgth = 1;
      w_charlit[char_ct].clit_uct = 2;
      char_ct++;
    }
  }
  convert = 1;
}

/* ***************************************************
*  c2_pass2_if_15    strchr                          *
* ************************************************** */
void c2_pass2_if_15() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_15 #1");
    trace_rec_1();
  }

  int pi;
  int pi2;
  int s;
  int s1;
  int s2;
  int size;

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while (ch != '"') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != '"') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  s2 = 0;
  s1 = strlen(tfield1);

  if (s2 < s1) 					/* 0 */
  {
    tfield2[0] = tfield1[0];
    tfield2[1] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield1a, c_wkname);

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, tfield1a);
    strcpy(w_charlit[char_ct].clit_value, tfield2);
    w_charlit[char_ct].clit_lgth = 1;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;
    convert = 1;
    s2++;
  }

  if (s2 < s1) 				/* 1 */
  {

    tfield2[0] = tfield1[1];
    tfield2[1] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield2a, c_wkname);

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, tfield2a);
    strcpy(w_charlit[char_ct].clit_value, tfield2);
    w_charlit[char_ct].clit_lgth = 1;
    w_charlit[char_ct].clit_uct = 2;
    char_ct++;
    convert = 1;
    s2++;
  }

  if (s2 < s1) /* 2 */
  {

    tfield2[0] = tfield1[2];
    tfield2[1] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield2a, c_wkname);

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, tfield2a);
    strcpy(w_charlit[char_ct].clit_value, tfield2);
    w_charlit[char_ct].clit_lgth = 1;
    w_charlit[char_ct].clit_uct = 3;
    char_ct++;
    convert = 1;
    s2++;
  }

  if (s2 < s1) /* 3 */
  {

    tfield2[0] = tfield1[3];
    tfield2[1] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield2a, c_wkname);

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, tfield2a);
    strcpy(w_charlit[char_ct].clit_value, tfield2);
    w_charlit[char_ct].clit_lgth = 1;
    w_charlit[char_ct].clit_uct = 4;
    char_ct++;
    convert = 1;
    s2++;
  }

  if (s2 < s1) /* 4 */
  {

    tfield2[0] = tfield1[4];
    tfield2[1] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield2a, c_wkname);

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, tfield2a);
    strcpy(w_charlit[char_ct].clit_value, tfield2);
    w_charlit[char_ct].clit_lgth = 1;
    w_charlit[char_ct].clit_uct = 5;
    char_ct++;
    convert = 1;
    s2++;
  }

  if (s2 < s1) /* 5 */
  {

    tfield2[0] = tfield1[5];
    tfield2[1] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield2a, c_wkname);

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, tfield2a);
    strcpy(w_charlit[char_ct].clit_value, tfield2);
    w_charlit[char_ct].clit_lgth = 1;
    w_charlit[char_ct].clit_uct = 6;
    char_ct++;
    convert = 1;
    s2++;
  }

  if (s2 < s1) /* 6 */
  {

    tfield2[0] = tfield1[6];
    tfield2[1] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield2a, c_wkname);

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, tfield2a);
    strcpy(w_charlit[char_ct].clit_value, tfield2);
    w_charlit[char_ct].clit_lgth = 1;
    w_charlit[char_ct].clit_uct = 7;
    char_ct++;
    convert = 1;
    s2++;
  }

  if (convert == 0) 
  {
    printf("\nc2z_pass_2.c c2_pass2_if_15 pass2-051 length error s1 = %d\n", s1);
    printf("c2z_pass_2.c c2_pass2_if_15 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }
}

/* ***************************************************
*  c2_pass2_strrev    strrev                         *
* ************************************************** */
void c2_pass2_strrev() 
{

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_strrev");
    trace_rec_1();
  }
  convert = 1;
}

/* ***************************************************
*  c2_pass2_if_4                                     *
* ************************************************** */
void c2_pass2_if_4() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_4");
    trace_rec_1();
  }

  char ch;
  char *p4;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
 
  int fd2_type = 0;
  int pi;
  int pi2;
  int I = 0;
  int x = 0;
  int x2 = 0;
  int x3 = 0;
  int s = 0;
  int ret = 0;
  int ret1 = 0;
  int complex_if = 0;
  int size = 0;

  c2_count_paren();

  p4 = strstr(p_string, "&&");
  if (p4)
  {
    complex_if = 1;
  }

  p4 = strstr(p_string, "||");
  if (p4)
  {
    complex_if = 2;
  }

  if (complex_if == 0) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_4 complex_if == 0");
      trace_rec_1();
    }

    x = 0;
    s = strlen(p_string);
    for(I=0; I < s; I++)
    {
      ch = p_string[I];
      if(ch == '(')
      {
        x++;
      }
      if(ch == ')')
      {
        x++;
      }
    }

    if(x == 4)		/* if (pipe(cgi_output) < 0) */
    {
      c2_count_paren();
      convert = 1;
      return;
    }
    
    if(x == 6)		/* if ((pid = fork()) < 0) */
    {
      c2_count_paren();
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
    x3 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      if ((ch == '_') && (x3 == 0)) 
      {
        x3 = 1;
      }
      tfield1[pi2] = ch;
      pi2++;
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
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(gw_variable[I].gv_name, tfield1);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_pass2_if_4 pass2-052 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_pass_2.c c2_pass2_if_4 rct = %d p_string = %s", rct,p_string);
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
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          fd2_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          fd2_type = 2;
          x2 = 1;
        }
      }
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    if (fd2_type == 0)
    {
      tfield2a[0] = tfield2[1];
      tfield2a[1] = '\0';

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
      w_charlit[char_ct].clit_type = 3;
      strcpy(w_charlit[char_ct].clit_cname, c_wkname);
      strcpy(w_charlit[char_ct].clit_value, tfield2a);
      s = strlen(tfield2a);
      w_charlit[char_ct].clit_lgth = s;
      w_charlit[char_ct].clit_uct = 1;
      char_ct++;

      convert = 1;
      return;
    }


    if (fd2_type == 2) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
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
            gw_variable[I].gv_use_ct++;
            x = strcmp(gw_variable[I].gv_type, "I");
            if (x == 0) 
            {
              fd2_type = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_pass_2.c c2_pass2_if_4 pass2-053 tfield2 Not Found = %s\n", tfield2);
        printf("c2z_pass_2.c c2_pass2_if_4 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if (fd2_type == 1) 
    {
      convert = 1;
    }
  }
}

/* ***************************************************
*  c2_math_math_lit_6                                 *
* ************************************************** */
void c2_math_literal_6() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_math_math_lit_6");
    trace_rec_1();
  }

  char ch, *p1;
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield3b[VAR_LGTH];
 

  int pi;
  int pi2;
  int x2;
  int x99 = 0;
  int s;
  int s1 = 0;
  int I;
  int fd2_type = 0;

  pi = 0;
  ch = p_string[pi];
  while (ch != '[') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
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
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  if (fd2_type != 2) 
  {
    return;
  }

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(tfield1a, c_wkname);

  s = strlen(tfield2);
  x99 = 0;
  p1 = strstr(tfield2, "-");
  if (p1) 
  {
    x99 = 1;
  }

  s1 = s + 1;
  if (x99 == 1) 
  {
    strcpy(tfield3b, tfield2);
    pi2 = 0;
    for (I = 0; I < s1; I++) 
    {
      ch = tfield3b[I];
      if (ch != '-') 
      {
        tfield2[pi2] = ch;
        pi2++;
      }
    }
    tfield2[pi2] = '\0';
  }

/*
  if (x99 == 0) 
  {
    strcpy(tfield2a, tfield2);
  } 
  else 
  {
    strcpy(tfield2a, "-");
    strcat(tfield2a, tfield2);
  }

  for (I = 0; I < math_lit_ct; I++) 
  {
    ret = strcmp(w_mathlit[I].lit_value, tfield2a);
    if (ret == 0) 
    {
      strcpy(tfield4, w_mathlit[I].lit_cname);
      break;
    }
  }

  if (math_lit_ct == 0) 
  {
    size = 1;
    w_mathlit = malloc(size * sizeof(struct math_lit));
  } 
  else 
  {
    size = math_lit_ct + 1;
    w_mathlit = realloc(w_mathlit, size * sizeof(struct math_lit));
  }

  w_mathlit[math_lit_ct].lit_rct = rct;
  w_mathlit[math_lit_ct].lit_use_rct = rct;
  strcpy(w_mathlit[math_lit_ct].lit_name, null_field);
  strcpy(w_mathlit[math_lit_ct].lit_cname, tfield1a);
  strcpy(w_mathlit[math_lit_ct].lit_value, tfield2a);
  strcpy(w_mathlit[math_lit_ct].lit_use_cname, tfield4);
  w_mathlit[math_lit_ct].lit_uct = 1;
  w_mathlit[math_lit_ct].lit_dec = 0;
  w_mathlit[math_lit_ct].lit_type = 1;
  math_lit_ct++;
*/
  convert = 1;
}

void c2_math_literal_7() /* in_stack[i] = iv_stack[3];	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_math_math_lit_7");
    trace_rec_1();
  }

  int pi;
  int x2;
  int pi2;
  int x3;
  int x99 = 0;
  int I;
  int s;
  int s1 = 0;
  int ret;
  int ret1;
  int fd2_type = 0;

  char ch, *p1;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield3b[VAR_LGTH];

  convert = 1;
  return;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while (ch != '[') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  x2 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
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

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while (ch != '[') 
  {
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
   pi++;
    ch = p_string[pi];
  }

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
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2_pass_2.c c2_math_math_lit_7 pass2-054 rct = %d p_string = %s", rct, p_string);
    printf("c2_pass_2.c c2_math_math_lit_7 tfield1 NOT FOUND = %s\n", tfield1);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield3, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
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
        x3 = 1;
        strcpy(tfield3a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2_pass_2.c c2_math_math_lit_7 pass2-055 rct = %d p_string = %s", rct, p_string);
    printf("c2_pass_2.c c2_math_math_lit_7 tfield3 NOT FOUND = %s\n", tfield3);
    erct++;
    convert = 1;
    return;
  }

  if (fd2_type == 2) 
  {
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield2a, c_wkname);

    s = strlen(tfield2);
    x99 = 0;
    p1 = strstr(tfield2, "-");
    if (p1) 
    {
      x99 = 1;
    }

    s1 = s + 1;
    if (x99 == 1) 
    {
      strcpy(tfield3b, tfield2);
      pi2 = 0;
      for (I = 0; I < s1; I++) 
      {
        ch = tfield3b[I];
        if (ch != '-') 
        {
          tfield2[pi2] = ch;
          pi2++;
        }
      }
      tfield2[pi2] = '\0';
    }
  }

  convert = 1;
}

void c2_math_literal_8()			 /* in_stack[12]++;  or in_stack[12]--;	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_math_math_lit_8");
    trace_rec_1();
  }

 
  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while (ch != '[') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}

void c2_pass2_while_7() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_7");
    trace_rec_1();
  }

  char ch;
  char *p, *p1;
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

  char tfield3b[VAR_LGTH];

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x99 = 0;
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
  int s = 0;
  int s1 = 0;

  var_use[10]++;

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
      return;
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
        printf("\nc2z_pass_2.c while_case_7 pass2-056 complex = 0 short_while = 0 Error Message #51\n");
        printf("c2z_pass_2.c while_case_7 complex = 0 short_while = 0 rct = %d p_string = %s",rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_while_7 Short ");
        trace_rec_1();
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

      while_convert = 1;
      convert = 1;
    }
  }

  if (while_complex == 1) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1");
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

    if (whfd7_type == 2) 
    {
      return;
    }

    if (whfd7_type == 1) 
    {
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(field7a, c_wkname);

      s = strlen(field7);
      x99 = 0;
      p1 = strstr(field7, "-");
      if (p1) 
      {
        x99 = 1;
      }

      s1 = s + 1;
      if (x99 == 1) 
      {
        strcpy(tfield3b, field7);
        pi2 = 0;
        for (I = 0; I < s1; I++) 
        {
          ch = tfield3b[I];
          if (ch != '-') 
          {
            field7[pi2] = ch;
            pi2++;
          }
        }
        field7[pi2] = '\0';
      }

/*
      if (x99 == 0) 
      {
        strcpy(field7b, field7);
      } 
      else 
      {
        strcpy(field7b, "-");
        strcat(field7b, field7);
      }

      for (I = 0; I < math_lit_ct; I++) 
      {
        ret = strcmp(field7b, w_mathlit[I].lit_value);
        if (ret == 0) 
        {
          strcpy(field7c, w_mathlit[I].lit_cname);
          break;
        }
      }
*/
      return;
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
      printf("\nc2z_pass_2.c while_case_7 pass2-057 field1 Not Found = %s\n", field1);
      printf("c2z_pass_2.c while_case_7 rct = %d p_string = %s\n", rct,p_string);
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
        printf("\nc2z_pass_2.c while_case_7 pass2-058 field3 Not Found = %s\n", field3);
        printf("c2z_pass_2.c while_case_7 rct = %d p_string = %s\n", rct, p_string);
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
      printf("\nc2z_pass_2.c while_case_7 pass2-059 field5 Not Found = %s\n", field5);
      printf("c2z_pass_2.c while_case_7 rct = %d p_string = %s\n", rct, p_string);
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
        printf("\nc2z_pass_2.c while_case_7 pass2-060 field7 Not Found = %s\n", field7);
        printf("c2z_pass_2.c while_case_7 rct = %d p_string = %s\n", rct, p_string);
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
      strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #3");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         LARL  R15,ISDIGIT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370ISDG");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #6");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(4,R9),0(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #7");
      trace_rec_3();
    }
    work_use_ct[31]++;

    if (operand_1 == 1) {
      strcpy(a_string, "         JNE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #8");
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
        strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #9");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field5a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #10");
      trace_rec_3();
    }

    if (whfd7_type == 1) 
    {
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #11");
        trace_rec_3();
      }
    }

    if (whfd7_type == 2) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field7a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #12");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(4,R9),0(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #13");
      trace_rec_3();
    }

    if (operand_3 == 3) 
    {
      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #14");
        trace_rec_3();
      }

      strcpy(a_string, "         JLL   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #15");
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
        strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #16");
        trace_rec_3();
      }

      strcpy(a_string, "         JLH   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_while_7 complex == 1 #17");
        trace_rec_3();
      }
    }

    while_convert = 1;
    convert = 1;
  }
}

void c2_pass2_while_13() 				/* STRCMP	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_13 START");
    trace_rec_1();
  }

  char *p, *p1;
  char ch;

  int pi = 0;
  int pi2;
  int while_complex = 0;
  int whfd10_type = 0;
  int x2 = 0;
  int x20 = 0;
  int x21 = 0;
  int x22 = 0;
  int x99 = 0;
  int s = 0;
  int s1 = 0;
  int I = 0;
  int ret = 0;
  int wh_3 = 0;
  int wh_4 = 0;
  int v = 0;
  int ret1 = 0;

  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field10[VAR_LGTH];
  char field10a[VAR_LGTH];
  char field10b[VAR_LGTH];

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
      x21++;
    }
    if(ch == '[')
    {
      x22++;
    }
    if(ch == ']')
    {
      x22++;
    }
  }

  p = strstr(p_string, "&&");
  if (p) 
  {
    while_complex = 1;
  }

  if (while_complex == 0) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_while_13 subroutine #1");
      trace_rec_1();
    }

    p1 = strstr(field1, "strcmp");
    if (p1) /*  strcmp comes 1st */
    {
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
          pi2++;
        }
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

      x2 = 0;
      while (ch != ')') 
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
      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }
    
      pi++;
      ch = p_string[pi];

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
    }
  }

  if ((while_complex == 1) && (x20 == 4) && (x21 == 4) && (x22 == 2))
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_while_13 subroutine #2");
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

    p1 = strstr(field1, "strcmp");
    if (p1) 
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

      wh_3 = 0;
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          wh_4 = strcmp(field2, gw_variable[v].gv_name);
          if (wh_4 == 0) 
          {
            wh_3 = 1;
            strcpy(field2a, gw_variable[v].gv_type);
          }
        }
      }

      if (wh_3 == 0) 
      {
        if (lv_ct > 0) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(field2, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              wh_3 = 1;
              strcpy(field2a, lw_variable[v].lv_type);
            }
          }
        }
      }

      if (wh_3 == 0) 
      {
        for (I = 0; I < m_struc_ct; I++) 
        {
          ret = strcmp(field2, w_struc[I].st_name);
          if (ret == 0) 
          {
            wh_3 = 1;
            strcpy(field2a, "S");
          }
        }
      }

      if (wh_3 == 0) 
      {
        printf("\nc2z_pass_2.c while_case_13 pass2-019 field2 Not Found = %s\n", field2);
        printf("c2z_pass_2.c while_case_13 rct = %d p_string = %s\n", rct,p_string);
        erct++; 
        convert = 1;
        return;
      }

      pi++;
      ch = p_string[pi];
      while (ch != ']') 
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

      while (ch != ')') 
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

      x2 = 0;
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

      ch = p_string[pi];
      while (ch != ')') 
      {
        pi++;
        ch = p_string[pi];
      }
     
     convert = 1;
    } 				/* END OF  p1 = strstr(field1, "strcmp"); */

    if ((!p1) && (x20 < 4) && (x21 < s))		/*  field1 not equal to strcmp  */
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_pass_2.c c2_while_13 subroutine #3");
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

      while (ch != ')') 
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

      while (ch != '(') 
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
      while (ch != ')') 
      {
        pi++;
        ch = p_string[pi];
      }
    
      pi++;
      ch = p_string[pi];
      if(ch == ')')
      {
        convert = 1;
        return;
      }

      pi++;
      ch = p_string[pi];
      while (ch != ']') 
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

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if (ch != ' ') 
        {
          if (x2 == 0) 
          {
            if (isdigit(ch)) 
            {
              whfd10_type = 1;
              x2 = 1;
            }
            if (isalpha(ch)) 
            {
              whfd10_type = 2;
              x2 = 1;
            }
          }
          field10[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      field10[pi2] = '\0';

      if (whfd10_type == 1) 
      {
        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(field10a, c_wkname);

        s = strlen(field10);
        x99 = 0;
        p1 = strstr(field10, "-");
        if (p1) 
        {
          x99 = 1;
        }

        s1 = s + 1;
        if (x99 == 1) 
        {
          strcpy(field10b, field10);
          pi2 = 0;
          for (I = 0; I < s1; I++) 
          {
            ch = field10b[I];
            if (ch != '-') 
            {
              field10[pi2] = ch;
              pi2++;
            }
          }
          field10[pi2] = '\0';
        }

      }
    }


    if((!p1) && (x20 == 4) && (x21 == 2))
    {
printf("c2z_pass_2.c while_13 INSIDE !p1 x20=4 x21=2 rct = %d p_string = %s",rct,p_string);

    }
  }
}

void c2_pass2_while_4() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_4");
    trace_rec_1();
  }

  char ch, *p;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];

  int pi;
  int pi2;
  int x3;
  int v;
  int ret;
  int ret1;
  int do_math = 0;

  pi = 0;
  x3 = strlen(p_string);
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{') || (ch != '(')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  if (ch == ' ') 
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
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (ch != '(') 
    {
      field2[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  do_math = 0;
  p = strstr(field2, "+");
  if (p)
  {
    do_math = 1;
  }

  p = strstr(field2, "-");
  if (p)
  {
    do_math = 1;
  }

  p = strstr(field2, "*");
  if (p)
  {
    do_math = 1;
  }

  p = strstr(field2, "/");
  if (p)
  {
    do_math = 1;
  }

  if (do_math == 1) 
  {
    pi = 0;
    pi2 = 0;
    ch = field2[pi];
    while (ch != ' ') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = field2[pi];
    }
    field3[pi2] = '\0';

    strcpy(field2, field3);
  }

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field1, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_pass_2.c while_pass2_while_4 pass2-020 field1 Not Found = %s\n", field1);
    printf("c2z_pass_2.c while_pass2_while_4 rct = %d p_string = %s\n", rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field2, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_pass_2.c while_pass2_while_4 pass2-061 field2 Not Found = %s\n", field2);
    printf("c2z_pass_2.c while_pass2_while_4 rct = %d p_string = %s\n", rct,p_string);
    erct++;
    convert = 1;
    return;
  }
}

void c2_pass2_while_12() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_12 START");
    trace_rec_1();
  }

  convert = 1;
}

void c2_pass2_while_11() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_11 START");
    trace_rec_1();
  }

  char ch;
 
  int pi;
  int whfd1_type = 0;

  pi = 0;
  ch = p_string[pi];
  while (ch != ')') 
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

  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    pi++;
    ch = p_string[pi];
  }

  if (whfd1_type == 1) 
  {
/*
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(field1a, c_wkname);

    if (math_lit_ct == 0) 
    {
      size = 1;
      w_mathlit = malloc(size * sizeof(struct math_lit));
    } 
    else 
    {
      size = math_lit_ct + 1;
      w_mathlit = realloc(w_mathlit, size * sizeof(struct math_lit));
    }

    w_mathlit[math_lit_ct].lit_rct = rct;
    w_mathlit[math_lit_ct].lit_use_rct = rct;
    strcpy(w_mathlit[math_lit_ct].lit_name, null_field);
    strcpy(w_mathlit[math_lit_ct].lit_cname, field1a);
    strcpy(w_mathlit[math_lit_ct].lit_value, field1);
    strcpy(w_mathlit[math_lit_ct].lit_use_cname, field1a);
    w_mathlit[math_lit_ct].lit_uct = 1;
    w_mathlit[math_lit_ct].lit_dec = 0;
    w_mathlit[math_lit_ct].lit_type = 1;
    math_lit_ct++;
*/
    convert = 1;
  }

  if (whfd1_type == 2) 
  {
    printf("\nc2z_pass_2.c c2_pass2_while_11 whfd1_type == 2 NEED TO CODE\n");
    erct++;
    convert = 1;
    return;
  }
}

void c2_pass2_while_8() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_8 #1");
    trace_rec_1();
  }

  char ch;
 
  int pi = 0;
  int pi2 = 0;
  int fd3_type = 0;

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

  pi2 = 0;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    pi2++;
    pi++;
    ch = p_string[pi];
  }

  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  if (fd3_type == 1) 
  {
    convert = 1;
  }
}

void c2_pass2_while_33() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_33 START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];

  int pi;
  int pi2;
  int x90;
  int size = 0;
  int s = 0;

  pi = 0;
  ch = p_string[pi];
  while (ch != '"') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  field1[pi2] = ch;
  pi2++;
  field1[pi2] = '\0';

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
  w_charlit[char_ct].clit_type = 3;
  strcpy(w_charlit[char_ct].clit_cname, c_wkname);
  strcpy(w_charlit[char_ct].clit_value, field1);
  s = strlen(field1);
  w_charlit[char_ct].clit_lgth = s;
  w_charlit[char_ct].clit_uct = 1;
  char_ct++;
  
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  field1[pi2] = ch;
  pi2++;
  field1[pi2] = '\0';

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
  w_charlit[char_ct].clit_type = 3;
  strcpy(w_charlit[char_ct].clit_cname, c_wkname);
  strcpy(w_charlit[char_ct].clit_value, field1);
  s = strlen(field1);
  w_charlit[char_ct].clit_lgth = s;
  w_charlit[char_ct].clit_uct = 2;
  char_ct++;

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  if(ch == '"')
  {
    goto end_lit;
  }


end_lit:

  convert = 1;
}

void c2_pass2_math_6() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_6 START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];

  int pi = 0;
  int pi2 = 0;
  int s = 0;
  int size = 0;
  int x80 = 0;
  int I;

  x80 = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == ';') 
    {
      break;
    }

    if (ch == '\'') 
    {
      x80++;
    }

    if (ch == '"') 
    {
      x80++;
    }

    if (isdigit(ch)) 
    {
      x80++;
    }

  }

  if (x80 == 0) 
  {
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
  while (ch != ')') 
  {
    if (ch != '\'') 
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
  w_charlit[char_ct].clit_type = 3;
  strcpy(w_charlit[char_ct].clit_cname, c_wkname);
  strcpy(w_charlit[char_ct].clit_value, field1);
  s = strlen(field1);
  w_charlit[char_ct].clit_lgth = s;
  w_charlit[char_ct].clit_uct = 1;
  char_ct++;

  convert = 1;
}

void c2_pass2_math_99() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_99 START");
    trace_rec_1();
  }

  char ch;
  char *p, *p1, *p2, *p3, *p4;
  char tfield1[VAR_LGTH];
  char tfield3[VAR_LGTH];

  int pi = 0;
  int pi2 = 0;
  int s = 0;
  int size = 0;
  int x3 = 0;
  int x80 = 1;
  int v = 0;
  int ret = 0;
  int ret1 = 0;
  

  p = strstr(p_string, "('");
  p1 = strstr(p_string, "-1");
  p2 = strstr(p_string, "=");

  if (p) {
    pi = 0;
    ch = p_string[pi];
    while (ch != '\'') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '\'') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

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
    w_charlit[char_ct].clit_type = 3;
    strcpy(w_charlit[char_ct].clit_cname, c_wkname);
    strcpy(w_charlit[char_ct].clit_value, tfield1);
    s = strlen(tfield1);
    w_charlit[char_ct].clit_lgth = s;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;

    convert = 1;
  }

  if ((p1) && (convert == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_99 subroutine #2");
      trace_rec_1();
    }
    
    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t') || (ch == '{'))
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != ' ')
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
 
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
 
    pi2 = 0;
    while(ch != ';')
    {
      tfield3[pi2] = ch;
      pi2++;
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
        }
      }
    }

    if (x3 == 0) 
    {
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';

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
        strcpy(gw_variable[gv_ct].gv_name, tfield1);
        strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
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
        strcpy(gw_variable[gv_ct].gv_label, null_field);
        strcpy(gw_variable[gv_ct].gv_table, null_field);
        strcpy(gw_variable[gv_ct].gv_aname, null_field);
        strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
        gw_variable[gv_ct].gv_flag = 0;
        gw_variable[gv_ct].gv_dec = 0;
        gw_variable[gv_ct].gv_id = 1;
        gv_ct++;
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
        strcpy(lw_variable[lv_ct].lv_cname, c_wkname);
        strcpy(lw_variable[lv_ct].lv_name, tfield1);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        lw_variable[lv_ct].lv_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, "0");
        lw_variable[lv_ct].lv_use_ct = 0;
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 1;
        lw_variable[lv_ct].lv_init = 0;
        lv_ct++;
      }
    }

    x80 = 1;
    x80 = strcmp("-1", tfield3);

    if(x80 == 0)
    {
      convert = 1;
      return;
    }

    p3 = strstr(p_string, "1");
    if(p3)
    {
      convert = 1;
      return;
    }

  }

  if ((p2) && (!p) && (convert == 0)) 
  {

    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_pass_2.c c2_pass2_math_99 subroutine #2");
      trace_rec_1();
    }
    
    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t') || (ch == '{'))
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != ' ')
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';


    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
 
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
 
    pi2 = 0;
    while(ch != ';')
    {
      tfield3[pi2] = ch;
      pi2++;
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
        }
      }
    }

    if (x3 == 0) 
    {

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';

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
        strcpy(gw_variable[gv_ct].gv_name, tfield1);
        strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
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
        strcpy(gw_variable[gv_ct].gv_label, null_field);
        strcpy(gw_variable[gv_ct].gv_table, null_field);
        strcpy(gw_variable[gv_ct].gv_aname, null_field);
        strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
        gw_variable[gv_ct].gv_flag = 0;
        gw_variable[gv_ct].gv_dec = 0;
        gw_variable[gv_ct].gv_id = 1;
        gv_ct++;
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
        strcpy(lw_variable[lv_ct].lv_cname, c_wkname);
        strcpy(lw_variable[lv_ct].lv_name, tfield1);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        lw_variable[lv_ct].lv_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, "0");
        lw_variable[lv_ct].lv_use_ct = 0;
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 1;
        lw_variable[lv_ct].lv_init = 0;
        lv_ct++;
      }
    }

    p4 = strstr("-1",tfield3);
    if(p4)
    {
      convert = 1;
      return;
    }

    x80 = 0;
    ret = strcmp("0",tfield3);
    if(ret == 0)
    {
       x80 = 1;
    }
     
    if(x80 == 0)
    {
      ret = strcmp("1",tfield3);
      if(ret == 0)
      {
        x80 = 1;
      }
    }

    if(x80 == 1)
    {
      convert = 1;
      return;
    }

  }
}


void c2_pass2_while_14() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_while_14 START");
    trace_rec_1();
  }

  convert = 1;
  return;
}


void c2_pass2_math_600()
{
 if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_pass2_math_600 START");
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
  int I = 0;
  int ret = 0;
  int s = 0;
  int size = 0;
  int fd2_type;
  int fd3_type;
  int fd4_type;
  int fd5_type;

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
    if (ch != '*') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield1[pi2] = '\0';

  pi2 = 0;
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
          fd2_type = 1;
          x2 = 1;
        }
        if (isalpha(ch)) 
        {
          fd2_type = 2;
          x2 = 1;
        }
      }

      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield2[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  pi++;
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
  }
  tfield3[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  fd4_type = 0;
  pi++;
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
  while (ch != ';') 
  {
    if (x2 == 0) 
    {
      if (ch == '\'')
      {
        fd5_type = 0;
        x2 = 1;
      }
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
    printf("\nc2z_pass_2.c c2_pass2_600 E-603 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_pass_2.c c2_pass2_600 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }
 
  if(fd2_type == 2)
  {
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
      printf("\nc2z_pass_2.c c2_pass2_600 E-604 tfield2 Not Found = %s\n",tfield2);
      printf("c2z_pass_2.c c2_pass2_600 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd3_type == 2)
  {
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
      printf("\nc2z_pass_2.c c2_pass2_600 E-605 tfield3 Not Found = %s\n",tfield3);
      printf("c2z_pass_2.c c2_pass2_600 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd4_type == 2)
  {
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
      printf("\nc2z_pass_2.c c2_pass2_600 E-606 tfield4 Not Found = %s\n",tfield4);
      printf("c2z_pass_2.c c2_pass2_600 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd4_type == 1)
  {
    strcpy(tfield4a, tfield4);
  }

  if(fd5_type == 2)
  {
    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield5, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield5a,lw_variable[I].lv_cname);
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
          x3 = 1;
          strcpy(tfield5a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_pass2_600 E-607 tfield5 Not Found = %s\n",tfield5);
      printf("c2z_pass_2.c c2_pass2_600 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd5_type == 1)
  {
    strcpy(tfield5a, tfield5);
  }

  if(fd5_type == 0)
  {
    pi = 1;
    x2 = 0;
    ch = tfield5[pi];
    while(ch != '\'')
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

  convert = 1;
  return;
}

void c2_pass2_if_55()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_pass2_if_55");
    trace_rec_1();
  }

printf("c2z_pass_2.c c2_pass2_if_55 START\n");

  convert = 1;
  return;
}



