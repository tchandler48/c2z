/* ***************************************************
*  c2z  : c2z_fputs.c :                              *
*                                                    *
*  next error - fputs-004                            *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* ***************************************************
*  Scan for FPUTS                                    *
* ************************************************** */
void c2_scan_fputs() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_fputs.c c2_scan_fputs");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];

  int pi;
  int pi2;
  int x = 0;
  int x2 = 0;
  int I = 0;
  int rec_lgth = 0;
  int ret = 0;
  int ret1 = 0;

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
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  x = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x = 1;
      strcpy(field1a, lw_variable[I].lv_cname);
      rec_lgth = lw_variable[I].lv_lgth;
    }
  }

  if (x == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x = 1;
        strcpy(field1a, gw_variable[I].gv_cname);
        rec_lgth = gw_variable[I].gv_lgth;
      }
    }
  }

  if (x == 0) 
  {
    printf("\nc2z_fputs.c c2_scan_fputs fputs-001 field1 Not Found = %s\n", field1);
    printf("c2z_fputs.c c2_scan_fputs rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch != ')') 
  {
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  x2 = 0;
  if (f_ct > 0) 
  {
    for (I = 0; I < f_ct; I++) 
    {
      ret = strcmp(field2, w_file[I].f_name);
      if (ret == 0) 
      {
        strcpy(w_file[I].f_type, "D");
        strcpy(w_file[I].f_perm, "O");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rec_lgth);
        strcpy(w_file[I].f_rec_lgth, wk_strg);
        x2 = 1;
      }
    }
  }

  if (x2 == 0) 
  {
    printf("\nc2z_fputs.c c2_scan_fputs fputs-002 FIELD2 Not Found in File Table = %s\n",field2);
    printf("c2z_fputs.c c2_scan_fputs rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }
}


/* ***************************************************
*  Punch for FPUTS                                   *
* ************************************************** */
void c2_fputs() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_fputs.c c2_fputs");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int x = 0;
  int x9 = 0;
  int ret = 0;
  int ret1 = 0;

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
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  x = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x = 1;
      strcpy(field1a, lw_variable[I].lv_cname);
      x9 = lw_variable[I].lv_lgth;
    }
  }

  if (x == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x = 1;
        strcpy(field1a, gw_variable[I].gv_cname);
        x9 = gw_variable[I].gv_lgth;
      }
    }
  }

  if (x == 0) 
  {
    printf("\nc2z_fputs.c c2_fputs fputs-003 field1 Not Found = %s\n", field1);
    printf("c2z_fputs.c c2_fputs rct = %d p_string = %s", rct, p_string);
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
  while (ch != ')') 
  {
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  if (f_ct > 0) 
  {
    for (I = 0; I < f_ct; I++) 
    {
      ret = strcmp(field2, w_file[I].f_name);
      if (ret == 0) 
      {
        strcpy(a_string, "         LARL  R9,C370PB");
        snprintf(wk_strg, sizeof(wk_strg), "%d", w_file[I].f_buf_ct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_fputs.c c2_fputs #1");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field1a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_fputs.c c2_fputs #2");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   ");
        strcat(a_string, "0(");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
        strcat(a_string, wk_strg);
        strcat(a_string, ",R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_fputs.c c2_fputs #3");
          trace_rec_3();
        }
      }
    }
  }

  strcpy(a_string, "         PUT   ");
  strcat(a_string, field2);
  strcpy(wk_remark, " fputs    */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fputs.c c2_fputs #4");
    trace_rec_3();
  }
}
