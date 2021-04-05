/* ***************************************************
*  c2z : c2z_sizeof.c :                              *
*                                                    *
*  next error - sizeof-010                           *
*  Copyright TCCS (c) 2015 - 20208                   *
**************************************************** */

/* ***************************************************
*  Punch out SIZEOF                                  *
* ************************************************** */
void c2_sizeof() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_sizeof.c c2_sizeof");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2a[VAR_LGTH];

  int x = 0;
  int x3 = 0;
  int x4 = 0;
  int pi;
  int pi2;
  int I = 0;
  int ret = 0;
  int end_of_string = 0;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
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
  if (lv_ct > 0) 
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }
  }

  if (x == 0) 
  {
    if (gv_ct > 0) 
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
  }

  if (x3 == 0) 
  {
    printf("\nc2z_sizeof.c c2_sizeof sizeof-001 field1 Not Found = %s\n", field1);
    printf("c2z_sizeof.c c2_sizeof rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi++;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  end_of_string = 0;
  pi++;
  pi2 = 0;
  ch = p_string[pi];
  while ((ch != ')') && (end_of_string == 0)) 
  {
    if (ch == '[') 
    {
      end_of_string = 1;
    }

    if (end_of_string == 0) 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  field2[pi2] = '\0';

  x4 = 0;
  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(field2a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
        x4 = 1;
      }
    }
  }

  if (x4 == 0) 
  {
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        if (ret == 0) 
        {
          strcpy(field2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x4 = 1;
        }
      }
    }
  }

  I = 0;
  x3 = 0;
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(field2, gw_variable[I].gv_name);
    if (ret == 0) 
    {
      x3 = 1;
      break;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_sizeof.c c2_sizeof sizeof-002 field2 Not Found = %s\n", field2);
    printf("c2z_sizeof.c c2_sizeof rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  ret = strcmp(gw_variable[I].gv_type, "C");
  if (ret != 0) 
  {
    printf("\nc2z_sizeof.c c2_aizeof sizeof-003 field2 Not Character = %s\n", field2);
    printf("c2z_sizeof.c c2_sizeof rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2a, gw_variable[I].gv_cname);
      if (ret == 0) 
      {
        x3 = 1;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_sizeof.c c2_sizeof sizeof-004 field2 Not Found = %s\n", field2);
    printf("c2z_sizeof.c c2_sizeof rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "SZ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", tot_sizeof);
  strcat(a_string, wk_strg);
  strcat(a_string, "0");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_sizeof.c c2_sizeof #1");
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
    strcpy(trace_1, "c2z_sizeof.c c2_sizeof #15");
    trace_rec_3();
  }

/*
  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(field2a, c_wkname);

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
  strcpy(w_mathlit[math_lit_ct].lit_cname, field2a);
  snprintf(wk_strg, sizeof(wk_strg), "%d", x10);
  strcpy(w_mathlit[math_lit_ct].lit_value, wk_strg);
  strcpy(w_mathlit[math_lit_ct].lit_use_cname, field2a);
  w_mathlit[math_lit_ct].lit_uct = 1;
  w_mathlit[math_lit_ct].lit_dec = 0;
  math_lit_ct++;
*/

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field2a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_sizeof.c c2_sizeof #3");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_sizeof.c c2_sizeof #4");
    trace_rec_3();
  }

  convert = 1;
}

/* ***************************************************
*  Pass2 SIZEOF                                      *
* ************************************************** */
void c2_pass2_sizeof() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_szieof.c c2_pass2_sizeof START");
    trace_rec_1();
  }

  char ch;

  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3a[VAR_LGTH];
  char tfield21[VAR_LGTH];

  int pi;
  int pi2;
  int x = 0;
  int x2 = 0;
  int x3 = 0;
  int s = 0;
  int I = 0;
  int ret = 0;
  int end_of_string = 0;

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

  x2 = 0;
  x3 = 0;
  if (lv_ct > 0) 
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }
  }

  if (x == 0) 				/* check the global gw_variable table */
  {
    if (gv_ct > 0) 
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
  }

  if (x3 == 0) 
  {
    printf("\nc2z_sizeof.c c2_pass2_sizeof sizeof-005 field1 Not Found = %s\n", field1);
    printf("c2z_sizeof.c c2_pass2_sizeof rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi++;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  end_of_string = 0;
  pi++;
  pi2 = 0;
  ch = p_string[pi];
  while ((ch != ')') && (end_of_string == 0)) 
  {
    if (ch == '[') 
    {
      end_of_string = 1;
    }
    if (end_of_string == 0) 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  field2[pi2] = '\0';

  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if (ret == 0) {
        strcpy(field2a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  I = 0;
  x3 = 0;
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(field2, gw_variable[I].gv_name);
    if (ret == 0) 
    {
      x3 = 1;
      break;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_sizeof.c c2_pass2_sizeof sizeof-006 field2 Not Found = %s\n", field2);
    printf("c2z_sizeof.c c2_pass2_sizeof rct = %d p_string = %s", rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  ret = strcmp(gw_variable[I].gv_type, "C");
  if (ret != 0) 
  {
    printf("c2z_sizeof.c c2_pass2_sizeof sizeof-007 field2 Not Character = %s\n", field2);
    printf("c2z_sizeof.c c2_pass2_sizeof rct = %d p_string = %s", rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2a, gw_variable[I].gv_cname);
      if (ret == 0) 
      {
        x3 = 1;
        x2 = gw_variable[I].gv_lgth;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_sizeof.c c2_pass2_sizeof sizeof-008 field2 Not Found = %s\n", field2);
    printf("c2z_sizeof.c c2_pass2_sizeof rct = %d p_string = %s", rct,p_string);
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
  strcpy(field3a, c_wkname);
  strcpy(tfield21, field3a);

  snprintf(field2, sizeof(wk_strg), "%d", x2);
  s = strlen(field2);

  if (s == 1) 
  {
    strcpy(field2a, "000000");
    strcat(field2a, field2);
  }

  if (s == 2) 
  {
    strcpy(field2a, "00000");
    strcat(field2a, field2);
  }

  if (s == 3) 
  {
    strcpy(field2a, "0000");
    strcat(field2a, field2);
  }

  if (s == 4) 
  {
    strcpy(field2a, "000");
    strcat(field2a, field2);
  }

  if (s == 5) 
  {
    strcpy(field2a, "00");
    strcat(field2a, field2);
  }

  if (s == 6) 
  {
    strcpy(field2a, "0");
    strcat(field2, field2);
  }

  if (s == 7) 
  {
    strcpy(field2a, field2);
  }

  if (s > 7) 
  {
    printf("\nc2z_sizeof.c c2_pass2_sizeof sizeof-009 Length ERROR\n");
    printf("c2z_sizeof.c c2_pass2_sizeof rct = %d p_string = %s", rct,p_string);
    erct++;
    convert = 1;
    return;
  }

/*
  rct1 = rct;
  for (I = 0; I < math_lit_ct; I++) 
  {
    ret = strcmp(w_mathlit[I].lit_value, field2a);
    if (ret == 0) 
    {
      rct1 = w_mathlit[I].lit_rct;
      strcpy(tfield21, w_mathlit[I].lit_cname);
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
  w_mathlit[math_lit_ct].lit_use_rct = rct1;
  strcpy(w_mathlit[math_lit_ct].lit_name, null_field);
  strcpy(w_mathlit[math_lit_ct].lit_cname, field3a);
  strcpy(w_mathlit[math_lit_ct].lit_value, field2a);
  strcpy(w_mathlit[math_lit_ct].lit_use_cname, tfield21);
  w_mathlit[math_lit_ct].lit_uct = 1;
  w_mathlit[math_lit_ct].lit_dec = 0;
  math_lit_ct++;
*/
  convert = 1;

  return;
}
