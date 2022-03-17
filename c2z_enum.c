/* ***************************************************
*  c2z : c2_enum.c :                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Scan test for ENUM                                *
**************************************************** */
void c2_enum_scan() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_enum.c c2_enum_scan");
    trace_rec_1();
  }

  char *p1;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield3b[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield4a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];
  char tfield8[VAR_LGTH];
  char tfield8a[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield9a[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield10a[VAR_LGTH];
  char tfield11[VAR_LGTH];
  char tfield11a[VAR_LGTH];
  char tfield12[VAR_LGTH];
  char tfield12a[VAR_LGTH];

  int I = 0;
  int pi;
  int pi2;
  int x2 = 0;
  int x2e = 0;
  int x4 = 0;
  int x4e = 0;
  int x5 = 0;
  int x5e = 0;
  int x6 = 0;
  int x6e = 0;
  int x7 = 0;
  int x7e = 0;
  int x8 = 0;
  int x8e = 0;
  int x9 = 0;
  int x9e = 0;
  int x10 = 0;
  int x10e = 0;
  int x11 = 0;
  int x11e = 0;
  int x12 = 0;
  int x99 = 0;
  int xf = 0;

  int v = 0;
  int var_ct = 0;
  int ret = 0;
  int ret1 = 0;
  int s = 0;
  int s1 = 0;
  int size = 0;

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

  while (ch != '{') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    if (ch == '=') 
    {
      x2 = 1;
      break;
    }
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  if (x2 == 0) 
  {
    snprintf(tfield3, sizeof(wk_strg), "%d", var_ct);
  }

  if (x2 == 1) 
  {
    x2e = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch == ')') 
      {
        x2e = 1;
        break;
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';
    var_ct = atoi(tfield3);
  }

  if (global_st == 0) 
  {
    xf = 0;
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield1, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        xf = 1;
        break;
      }
    }
  }

  if (global_st == 1) 
  {
    xf = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        xf = 1;
        break;
      }
    }
  }

  if (xf == 1) 
  {
    printf("\nc2z_enum.c c2z_enum_scan enum-001 tfield1 Already Defined = %s\n",tfield1);
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  s = strlen(tfield3);
  x99 = 0;
  p1 = strstr(tfield3, "-");
  if (p1) 
  {
    x99 = 1;
  }

  s1 = s + 1;
  if (x99 == 1) 
  {
    strcpy(tfield3b, tfield3);
    pi2 = 0;
    for (I = 0; I < s1; I++) 
    {
      ch = tfield3b[I];
      if (ch != '-') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
    }
    tfield3[pi2] = '\0';
  }

  if (s == 1) 
  {
    strcpy(tfield3a, "000000");
    strcat(tfield3a, tfield3);
  }

  if (s == 2) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 3) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 4) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 5) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 6) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 7) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, tfield3);
    } 
    else 
    {
      printf("\nc2z_enum.c c2_enum_scan enum-002 Negative Conversion Error\n");
      printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (s > 7) 
  {
    printf("\nc2z_enum.c c2_enum_scan enum-003 Length ERROR\n");
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(tfield2a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, tfield2a);
    strcpy(gw_variable[gv_ct].gv_name, tfield2);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, tfield3a);
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
    strcpy(gw_variable[gv_ct].gv_st_col, null_field);
    gw_variable[gv_ct].gv_flag = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_id = 0;
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
    strcpy(lw_variable[lv_ct].lv_cname, tfield2a);
    strcpy(lw_variable[lv_ct].lv_name, tfield2);
    strcpy(lw_variable[lv_ct].lv_type, "I");
    lw_variable[lv_ct].lv_lgth = 0;
    lw_variable[lv_ct].lv_current_lgth = 0;
    strcpy(lw_variable[lv_ct].lv_value, tfield3a);
    lw_variable[lv_ct].lv_use_ct = 0;
    strcpy(lw_variable[lv_ct].lv_func, sv_func);
    lw_variable[lv_ct].lv_current_lgth = 0;
    lw_variable[lv_ct].lv_init = 0;
    lw_variable[lv_ct].lv_dec = 0;
    lw_variable[lv_ct].lv_id = 0;
    lv_ct++;
  }

  if (x2e == 1) 
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

  x4e = 0;
  x4 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    if (ch == ')') 
    {
      x4e = 1;
      break;
    }
    if (ch == '=') 
    {
      x4 = 1;
      break;
    }
    if (ch != ' ') 
    {
      tfield4[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

  if (x4 == 0) 
  {
    var_ct++;
    snprintf(tfield3, sizeof(wk_strg), "%d", var_ct);
  }

  if (global_st == 0) 
  {
    xf = 0;
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield4, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        xf = 1;
        break;
      }
    }
  }

  if (global_st == 1) 
  {
    xf = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield4, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        xf = 1;
        break;
      }
    }
  }

  if (xf == 1) 
  {
    printf("\nc2z_enum.c c2z_enum_scan enum-004 tfield4 Already Defined = %s\n",tfield4);
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  s = strlen(tfield3);
  x99 = 0;
  p1 = strstr(tfield3, "-");
  if (p1) 
  {
    x99 = 1;
  }

  s1 = s + 1;
  if (x99 == 1) 
  {
    strcpy(tfield3b, tfield3);
    pi2 = 0;
    for (I = 0; I < s1; I++) 
    {
      ch = tfield3b[I];
      if (ch != '-') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
    }
    tfield3[pi2] = '\0';
  }

  if (s == 1) 
  {
    strcpy(tfield3a, "000000");
    strcat(tfield3a, tfield3);
  }

  if (s == 2) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 3) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 4) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 5) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 6) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 7) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, tfield3);
    } 
    else 
    {
      printf("\nc2z_enum.c c2_enum_scan enum-005 Negative Conversion Error\n");
      printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (s > 7) 
  {
    printf("\nc2z_enum.c c2_enum_scan enum-006 Length ERROR\n");
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(tfield4a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, tfield4a);
    strcpy(gw_variable[gv_ct].gv_name, tfield4);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, tfield3a);
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
    strcpy(gw_variable[gv_ct].gv_st_col, null_field);
    gw_variable[gv_ct].gv_flag = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_id = 0;
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
    strcpy(lw_variable[lv_ct].lv_cname, tfield4a);
    strcpy(lw_variable[lv_ct].lv_name, tfield4);
    strcpy(lw_variable[lv_ct].lv_type, "I");
    lw_variable[lv_ct].lv_lgth = 0;
    strcpy(lw_variable[lv_ct].lv_value, tfield3a);
    lw_variable[lv_ct].lv_use_ct = 0;
    strcpy(lw_variable[lv_ct].lv_func, sv_func);
    lw_variable[lv_ct].lv_current_lgth = 0;
    lw_variable[lv_ct].lv_dec = 0;
    lw_variable[lv_ct].lv_id = 0;
    lv_ct++;
  }

  if (x4e == 1) 
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

  x5e = 0;
  x5 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    if (ch == ')') 
    {
      x5e = 1;
      break;
    }
    if (ch == '=') 
    {
      x5 = 1;
      break;
    }
    if (ch != ' ') 
    {
      tfield5[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield5[pi2] = '\0';

  if (x5 == 0) 
  {
    var_ct++;
    snprintf(tfield3, sizeof(wk_strg), "%d", var_ct);
  }

  if (x5 == 1) 
  {
    x5e = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch == ')') 
      {
        x5e = 1;
        break;
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';
    var_ct = atoi(tfield3);
  }

  if (global_st == 0) 
  {
    xf = 0;
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield5, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        xf = 1;
        break;
      }
    }
  }

  if (global_st == 1) 
  {
    xf = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield5, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        xf = 1;
        break;
      }
    }
  }

  if (xf == 1) 
  {
    printf("\nc2z_enum.c c2z_enum_scan enum-007 tfield4 Already Defined = %s\n",tfield5);
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  s = strlen(tfield3);
  x99 = 0;
  p1 = strstr(tfield3, "-");
  if (p1) 
  {
    x99 = 1;
  }

  s1 = s + 1;
  if (x99 == 1) 
  {
    strcpy(tfield3b, tfield3);
    pi2 = 0;
    for (I = 0; I < s1; I++) 
    {
      ch = tfield3b[I];
      if (ch != '-') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
    }
    tfield3[pi2] = '\0';
  }

  if (s == 1) 
  {
    strcpy(tfield3a, "000000");
    strcat(tfield3a, tfield3);
  }

  if (s == 2) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 3) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 4) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 5) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 6) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 7) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, tfield3);
    } 
    else 
    {
      printf("\nc2z_enum.c c2_enum_scan enum-008 Negative Conversion Error\n");
      printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (s > 7) 
  {
    printf("\nc2z_enum.c c2_enum_scan enum-009 Length ERROR\n");
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

/*  STOP HERE CHECKING LW & GW & BREAK */


  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(tfield5a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, tfield5a);
    strcpy(gw_variable[gv_ct].gv_name, tfield5);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, tfield3a);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
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
    strcpy(lw_variable[lv_ct].lv_cname, tfield5a);
    strcpy(lw_variable[lv_ct].lv_name, tfield5);
    strcpy(lw_variable[lv_ct].lv_type, "I");
    lw_variable[lv_ct].lv_lgth = 0;
    strcpy(lw_variable[lv_ct].lv_value, tfield3a);
    lw_variable[lv_ct].lv_use_ct = 0;
    strcpy(lw_variable[lv_ct].lv_func, sv_func);
    lw_variable[lv_ct].lv_current_lgth = 0;
    lw_variable[lv_ct].lv_dec = 0;
    lv_ct++;
  }

  if (x5e == 1) 
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

  x6e = 0;
  x6 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    if (ch == '}') 
    {
      x6e = 1;
      break;
    }
    if (ch == '=') 
    {
      x6 = 1;
      break;
    }
    if (ch != ' ') 
    {
      tfield6[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield6[pi2] = '\0';

  if (x6 == 0) 
  {
    var_ct++;
    snprintf(tfield3, sizeof(wk_strg), "%d", var_ct);
  }

  if (x6 == 1) 
  {
    x6e = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch == ')') 
      {
        x6e = 1;
        break;
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';
    var_ct = atoi(tfield3);
  }

  if (global_st == 0) 
  {
    xf = 0;
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield6, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        xf = 1;
      }
    }
  }

  if (global_st == 1) 
  {
    xf = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield6, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        xf = 1;
      }
    }
  }

  if (xf == 1) 
  {
    printf("\nc2z_enum.c c2z_enum_scan enum-010 tfield6 Already Defined = %s\n",tfield6);
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  s = strlen(tfield3);
  x99 = 0;
  p1 = strstr(tfield3, "-");
  if (p1) 
  {
    x99 = 1;
  }

  s1 = s + 1;
  if (x99 == 1) 
  {
    strcpy(tfield3b, tfield3);
    pi2 = 0;
    for (I = 0; I < s1; I++) 
    {
      ch = tfield3b[I];
      if (ch != '-') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
    }
    tfield3[pi2] = '\0';
  }

  if (s == 1) 
  {
    strcpy(tfield3a, "000000");
    strcat(tfield3a, tfield3);
  }

  if (s == 2) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 3) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 4) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 5) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 6) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 7) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, tfield3);
    } 
    else 
    {
      printf("\nc2z_enum.c c2_enum_scan enum-011 Negative Conversion Error\n");
      printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (s > 7) 
  {
    printf("\nc2z_enum.c c2_enum_scan enum-012 Length ERROR\n");
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(tfield6a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, tfield6a);
    strcpy(gw_variable[gv_ct].gv_name, tfield6);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, tfield3a);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
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
    strcpy(lw_variable[lv_ct].lv_cname, tfield6a);
    strcpy(lw_variable[lv_ct].lv_name, tfield6);
    strcpy(lw_variable[lv_ct].lv_type, "I");
    lw_variable[lv_ct].lv_lgth = 0;
    strcpy(lw_variable[lv_ct].lv_value, tfield3a);
    lw_variable[lv_ct].lv_use_ct = 0;
    strcpy(lw_variable[lv_ct].lv_func, sv_func);
    lw_variable[lv_ct].lv_current_lgth = 0;
    lw_variable[lv_ct].lv_dec = 0;
    lv_ct++;
  }

  if (x6e == 1) 
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

  x7e = 0;
  x7 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    if (ch == '}') 
    {
      x7e = 1;
      break;
    }
    if (ch == '=') 
    {
      x7 = 1;
      break;
    }
    if (ch != ' ') 
    {
      tfield7[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield7[pi2] = '\0';

  if (x7 == 0) 
  {
    var_ct++;
    snprintf(tfield3, sizeof(wk_strg), "%d", var_ct);
  }

  if (x7 == 1) 
  {
    x7e = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch == ')') 
      {
        x7e = 1;
        break;
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';
    var_ct = atoi(tfield3);
  }

  if (global_st == 0) 
  {
    xf = 0;
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield7, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        xf = 1;
      }
    }
  }

  if (global_st == 1) 
  {
    xf = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield7, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        xf = 1;
      }
    }
  }

  if (xf == 1) 
  {
    printf("\nc2z_enum.c c2z_enum_scan enum-013 tfield7 Already Defined = %s\n",tfield7);
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  s = strlen(tfield3);
  x99 = 0;
  p1 = strstr(tfield3, "-");
  if (p1) 
  {
    x99 = 1;
  }

  s1 = s + 1;
  if (x99 == 1) 
  {
    strcpy(tfield3b, tfield3);
    pi2 = 0;
    for (I = 0; I < s1; I++) 
    {
      ch = tfield3b[I];
      if (ch != '-') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
    }
    tfield3[pi2] = '\0';
  }

  if (s == 1) 
  {
    strcpy(tfield3a, "000000");
    strcat(tfield3a, tfield3);
  }

  if (s == 2) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 3) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 4) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 5) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 6) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 7) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, tfield3);
    } 
    else 
    {
      printf("\nc2z_enum.c c2_enum_scan enum-014 Negative Conversion Error\n");
      printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (s > 7) 
  {
    printf("\nc2z_enum.c c2_enum_scan enum-015 Length ERROR\n");
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(tfield7a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, tfield7a);
    strcpy(gw_variable[gv_ct].gv_name, tfield7);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, tfield3a);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
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
    strcpy(lw_variable[lv_ct].lv_cname, tfield7a);
    strcpy(lw_variable[lv_ct].lv_name, tfield7);
    strcpy(lw_variable[lv_ct].lv_type, "I");
    lw_variable[lv_ct].lv_lgth = 0;
    strcpy(lw_variable[lv_ct].lv_value, tfield3a);
    lw_variable[lv_ct].lv_use_ct = 0;
    strcpy(lw_variable[lv_ct].lv_func, sv_func);
    lw_variable[lv_ct].lv_current_lgth = 0;
    lw_variable[lv_ct].lv_dec = 0;
    lv_ct++;
  }

  if (x7e == 1) 
  {
    convert = 1;
    return;
  }

  x8e = 0;
  x8 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    if (ch == '}') 
    {
      x8e = 1;
      break;
    }
    if (ch == '=') 
    {
      x8 = 1;
      break;
    }
    if (ch != ' ') 
    {
      tfield8[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield8[pi2] = '\0';

  if (x8 == 0) 
  {
    var_ct++;
    snprintf(tfield3, sizeof(wk_strg), "%d", var_ct);
  }

  if (x8 == 1) 
  {
    x8e = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch == ')') 
      {
        x8e = 1;
        break;
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';
    var_ct = atoi(tfield3);
  }

  if (global_st == 0) 
  {
    xf = 0;
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield8, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        xf = 1;
      }
    }
  }

  if (global_st == 1) 
  {
    xf = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield8, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        xf = 1;
      }
    }
  }

  if (xf == 1) 
  {
    printf("\nc2z_enum.c c2z_enum_scan enum-015 tfield8 Already Defined = %s\n",tfield8);
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  s = strlen(tfield3);
  x99 = 0;
  p1 = strstr(tfield3, "-");
  if (p1) 
  {
    x99 = 1;
  }

  s1 = s + 1;
  if (x99 == 1) 
  {
    strcpy(tfield3b, tfield3);
    pi2 = 0;
    for (I = 0; I < s1; I++) 
    {
      ch = tfield3b[I];
      if (ch != '-') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
    }
    tfield3[pi2] = '\0';
  }

  if (s == 1) 
  {
    strcpy(tfield3a, "000000");
    strcat(tfield3a, tfield3);
  }

  if (s == 2) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 3) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 4) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 5) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 6) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 7) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, tfield3);
    } 
    else 
    {
      printf("\nc2z_enum.c c2_enum_scan enum-016 Negative Conversion Error\n");
      printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (s > 7) 
  {
    printf("\nc2z_enum.c c2_enum_scan enum-017 Length ERROR\n");
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(tfield8a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, tfield8a);
    strcpy(gw_variable[gv_ct].gv_name, tfield8);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, tfield3a);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
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
    strcpy(lw_variable[lv_ct].lv_cname, tfield8a);
    strcpy(lw_variable[lv_ct].lv_name, tfield8);
    strcpy(lw_variable[lv_ct].lv_type, "I");
    lw_variable[lv_ct].lv_lgth = 0;
    strcpy(lw_variable[lv_ct].lv_value, tfield3a);
    lw_variable[lv_ct].lv_use_ct = 0;
    strcpy(lw_variable[lv_ct].lv_func, sv_func);
    lw_variable[lv_ct].lv_current_lgth = 0;
    lw_variable[lv_ct].lv_dec = 0;
    lv_ct++;
  }

  if (x8e == 1) 
  {
    convert = 1;
    return;
  }

  x9e = 0;
  x9 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    if (ch == '}') 
    {
      x9e = 1;
      break;
    }
    if (ch == '=') 
    {
      x9 = 1;
      break;
    }
    if (ch != ' ') 
    {
      tfield9[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield9[pi2] = '\0';

  if (x9 == 0) 
  {
    var_ct++;
    snprintf(tfield3, sizeof(wk_strg), "%d", var_ct);
  }

  if (x9 == 1) 
  {
    x9e = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch == ')') 
      {
        x9e = 1;
        break;
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';
    var_ct = atoi(tfield3);
  }

  if (global_st == 0) 
  {
    xf = 0;
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield9, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        xf = 1;
      }
    }
  }

  if (global_st == 1) 
  {
    xf = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield9, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        xf = 1;
      }
    }
  }

  if (xf == 1) 
  {
    printf("\nc2z_enum.c c2z_enum_scan enum-018 tfield9 Already Defined = %s\n",tfield9);
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  s = strlen(tfield3);
  x99 = 0;
  p1 = strstr(tfield3, "-");
  if (p1) 
  {
    x99 = 1;
  }

  s1 = s + 1;
  if (x99 == 1) 
  {
    strcpy(tfield3b, tfield3);
    pi2 = 0;
    for (I = 0; I < s1; I++) 
    {
      ch = tfield3b[I];
      if (ch != '-') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
    }
    tfield3[pi2] = '\0';
  }

  if (s == 1) 
  {
    strcpy(tfield3a, "000000");
    strcat(tfield3a, tfield3);
  }

  if (s == 2) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 3) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 4) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 5) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 6) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 7) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, tfield3);
    } 
    else 
    {
      printf("\nc2z_enum.c c2_enum_scan enum-018 Negative Conversion Error\n");
      printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (s > 7) 
  {
    printf("\nc2z_enum.c c2_enum_scan enum-019 Length ERROR\n");
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(tfield9a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, tfield9a);
    strcpy(gw_variable[gv_ct].gv_name, tfield9);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, tfield3a);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
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
    strcpy(lw_variable[lv_ct].lv_cname, tfield9a);
    strcpy(lw_variable[lv_ct].lv_name, tfield9);
    strcpy(lw_variable[lv_ct].lv_type, "I");
    lw_variable[lv_ct].lv_lgth = 0;
    strcpy(lw_variable[lv_ct].lv_value, tfield3a);
    lw_variable[lv_ct].lv_use_ct = 0;
    strcpy(lw_variable[lv_ct].lv_func, sv_func);
    lw_variable[lv_ct].lv_current_lgth = 0;
    lw_variable[lv_ct].lv_dec = 0;
    lv_ct++;
  }

  if (x9e == 1) 
  {
    convert = 1;
    return;
  }

  x10e = 0;
  x10 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    if (ch == '}') 
    {
      x10e = 1;
      break;
    }
    if (ch == '=') 
    {
      x10 = 1;
      break;
    }
    if (ch != ' ') 
    {
      tfield10[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield10[pi2] = '\0';

  if (x10 == 0) 
  {
    var_ct++;
    snprintf(tfield3, sizeof(wk_strg), "%d", var_ct);
  }

  if (x10 == 1) 
  {
    x10e = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch == ')') 
      {
        x10e = 1;
        break;
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';
    var_ct = atoi(tfield3);
  }

  if (global_st == 0) 
  {
    xf = 0;
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield10, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        xf = 1;
      }
    }
  }

  if (global_st == 1) 
  {
    xf = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield10, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        xf = 1;
      }
    }
  }

  if (xf == 1) 
  {
    printf("\nc2z_enum.c c2z_enum_scan enum-020 tfield10 Already Defined = %s\n",tfield10);
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  s = strlen(tfield3);
  x99 = 0;
  p1 = strstr(tfield3, "-");
  if (p1) 
  {
    x99 = 1;
  }

  s1 = s + 1;
  if (x99 == 1) 
  {
    strcpy(tfield3b, tfield3);
    pi2 = 0;
    for (I = 0; I < s1; I++) 
    {
      ch = tfield3b[I];
      if (ch != '-') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
    }
    tfield3[pi2] = '\0';
  }

  if (s == 1) 
  {
    strcpy(tfield3a, "000000");
    strcat(tfield3a, tfield3);
  }

  if (s == 2) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 3) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 4) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 5) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 6) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 7) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, tfield3);
    } 
    else 
    {
      printf("\nc2z_enum.c c2_enum_scan enum-021 Negative Conversion Error\n");
      printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (s > 7) 
  {
    printf("\nc2z_enum.c c2_enum_scan enum-022 Length ERROR\n");
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(tfield10a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, tfield10a);
    strcpy(gw_variable[gv_ct].gv_name, tfield10);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, tfield3a);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
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
    strcpy(lw_variable[lv_ct].lv_cname, tfield10a);
    strcpy(lw_variable[lv_ct].lv_name, tfield10);
    strcpy(lw_variable[lv_ct].lv_type, "I");
    lw_variable[lv_ct].lv_lgth = 0;
    strcpy(lw_variable[lv_ct].lv_value, tfield3a);
    lw_variable[lv_ct].lv_use_ct = 0;
    strcpy(lw_variable[lv_ct].lv_func, sv_func);
    lw_variable[lv_ct].lv_current_lgth = 0;
    lw_variable[lv_ct].lv_dec = 0;
    lv_ct++;
  }

  if (x10e == 1) 
  {
    convert = 1;
    return;
  }

  x11e = 0;
  x11 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    if (ch == '}') 
    {
      x11e = 1;
      break;
    }
    if (ch == '=') 
    {
      x11 = 1;
      break;
    }
    if (ch != ' ') 
    {
      tfield11[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield11[pi2] = '\0';

  if (x11 == 0) 
  {
    var_ct++;
    snprintf(tfield3, sizeof(wk_strg), "%d", var_ct);
  }

  if (x11 == 1) 
  {
    x11e = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch == ')') 
      {
        x11e = 1;
        break;
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';
    var_ct = atoi(tfield3);
  }

  if (global_st == 0) 
  {
    xf = 0;
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield11, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        xf = 1;
      }
    }
  }

  if (global_st == 1) 
  {
    xf = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield11, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        xf = 1;
      }
    }
  }

  if (xf == 1) 
  {
    printf("\nc2z_enum.c c2z_enum_scan enum-023 tfield11 Already Defined = %s\n",tfield11);
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  s = strlen(tfield3);
  x99 = 0;
  p1 = strstr(tfield3, "-");
  if (p1) 
  {
    x99 = 1;
  }

  s1 = s + 1;
  if (x99 == 1) 
  {
    strcpy(tfield3b, tfield3);
    pi2 = 0;
    for (I = 0; I < s1; I++) 
    {
      ch = tfield3b[I];
      if (ch != '-') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
    }
    tfield3[pi2] = '\0';
  }

  if (s == 1) 
  {
    strcpy(tfield3a, "000000");
    strcat(tfield3a, tfield3);
  }

  if (s == 2) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 3) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 4) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 5) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 6) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 7) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, tfield3);
    } 
    else 
    {
      printf("\nc2z_enum.c c2_enum_scan enum-024 Negative Conversion Error\n");
      printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (s > 7) 
  {
    printf("\nc2z_enum.c c2_enum_scan enum-025 Length ERROR\n");
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(tfield11a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, tfield11a);
    strcpy(gw_variable[gv_ct].gv_name, tfield11);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, tfield3a);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
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
    strcpy(lw_variable[lv_ct].lv_cname, tfield11a);
    strcpy(lw_variable[lv_ct].lv_name, tfield11);
    strcpy(lw_variable[lv_ct].lv_type, "I");
    lw_variable[lv_ct].lv_lgth = 0;
    strcpy(lw_variable[lv_ct].lv_value, tfield3a);
    lw_variable[lv_ct].lv_use_ct = 0;
    strcpy(lw_variable[lv_ct].lv_func, sv_func);
    lw_variable[lv_ct].lv_current_lgth = 0;
    lw_variable[lv_ct].lv_dec = 0;
    lv_ct++;
  }

  if (x11e == 1) 
  {
    convert = 1;
    return;
  }

  x12 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    if (ch == '}') 
    {
      break;
    }
    if (ch == '=') 
    {
      x12 = 1;
      break;
    }
    if (ch != ' ') 
    {
      tfield12[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield12[pi2] = '\0';

  if (x12 == 0) 
  {
    var_ct++;
    snprintf(tfield3, sizeof(wk_strg), "%d", var_ct);
  }

  if (x12 == 1) 
  {
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch == ')') 
      {
        break;
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';
    var_ct = atoi(tfield3);
  }

  if (global_st == 0) 
  {
    xf = 0;
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield12, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        xf = 1;
      }
    }
  }

  if (global_st == 1) 
  {
    xf = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield12, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        xf = 1;
      }
    }
  }

  if (xf == 1) 
  {
    printf("\nc2z_enum.c c2z_enum_scan enum-026 tfield12 Already Defined = %s\n",tfield12);
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  s = strlen(tfield3);
  x99 = 0;
  p1 = strstr(tfield3, "-");
  if (p1) 
  {
    x99 = 1;
  }

  s1 = s + 1;
  if (x99 == 1) 
  {
    strcpy(tfield3b, tfield3);
    pi2 = 0;
    for (I = 0; I < s1; I++) 
    {
      ch = tfield3b[I];
      if (ch != '-') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
    }
    tfield3[pi2] = '\0';
  }

  if (s == 1) 
  {
    strcpy(tfield3a, "000000");
    strcat(tfield3a, tfield3);
  }

  if (s == 2) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 3) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 4) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "000");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-000");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 5) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "00");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-00");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 6) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, "0");
      strcat(tfield3a, tfield3);
    } 
    else 
    {
      strcpy(tfield3a, "-0");
      strcat(tfield3a, tfield3);
    }
  }

  if (s == 7) 
  {
    if (x99 == 0) 
    {
      strcpy(tfield3a, tfield3);
    } 
    else 
    {
      printf("\nc2z_enum.c c2_enum_scan enum-027 Negative Conversion Error\n");
      printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (s > 7) 
  {
    printf("\nc2z_enum.c c2_enum_scan enum-028 Length ERROR\n");
    printf("c2z_enum.c c2z_enum rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(tfield12a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, tfield12a);
    strcpy(gw_variable[gv_ct].gv_name, tfield12);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, tfield3a);
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
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
    strcpy(lw_variable[lv_ct].lv_cname, tfield12a);
    strcpy(lw_variable[lv_ct].lv_name, tfield12);
    strcpy(lw_variable[lv_ct].lv_type, "I");
    lw_variable[lv_ct].lv_lgth = 0;
    strcpy(lw_variable[lv_ct].lv_value, tfield3a);
    lw_variable[lv_ct].lv_use_ct = 0;
    strcpy(lw_variable[lv_ct].lv_func, sv_func);
    lw_variable[lv_ct].lv_current_lgth = 0;
    lw_variable[lv_ct].lv_dec = 0;
    lv_ct++;
  }

  if (x11e == 1) 
  {
    convert = 1;
    return;
  }

  convert = 1;
}
