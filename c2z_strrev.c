/* ***************************************************
*  c2z : c2z_strrev.c :                              *
*                                                    *
*  next error - strrev-003                           *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* ***************************************************
*  Punch out STRREV                                  *
* ************************************************** */
void c2_strrev(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strrev.c c2_strrev");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  int pi = 0;
  int pi2;
  int x1;
  int I;
  int ret;
  int ret1;
  int x11;

  pi2 = 0;
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

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (ch != ' ') 
    {
      tfield2[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  x1 = 0;
  for (I = 0; I < lv_ct; I++) {
  
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x1 = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
    }
  }

  if (x1 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x1 = 1;
        strcpy(tfield1a, gw_variable[I].gv_cname);
      }
    }
  }

  if (x1 == 0) 
  {
    printf("\nc2z_strrev.c c2_strrev strrev-001 tfield1 not Found %s\n", tfield1);
    printf("c2z_strrev.c c2_strrev rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x1 = 0;
  x11 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield2, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x1 = 1;
      strcpy(tfield2a, lw_variable[I].lv_cname);
      x11 = lw_variable[I].lv_current_lgth;
    }
  }

  if (x1 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x1 = 1;
        strcpy(tfield2a, gw_variable[I].gv_cname);
        x11 = gw_variable[I].gv_current_lgth;
      }
    }
  }

  if (x1 == 0) 
  {
    printf("\nc2z_strrev.c c2_strrev strrev-002 tfield2 Not Found %s\n", tfield2);
    printf("c2z_strrev.c c2_strrev rct = %d p_string = %s\n",rct,p_string);
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
    strcpy(trace_1, "c2z_strrev.c c2_strrev #1");
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
    strcpy(trace_1, "c2z_strrev.c c2_strrev #2");
    trace_rec_3();
  }

  strcpy(a_string, "         MVCIN ");
  strcat(a_string, "0(");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x11);
  strcat(a_string, wk_strg);
  strcat(a_string, ",R9),");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x11 - 1);
  strcat(a_string, wk_strg);
  strcat(a_string, "(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strrev.c c2_strrev #3");
    trace_rec_3();
  }

  x1 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x1 = 1;
      lw_variable[I].lv_current_lgth = x11;
    }
  }

  if (x1 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x1 = 1;
        gw_variable[I].gv_current_lgth = x11;
      }
    }
  }

  convert = 1;
}
