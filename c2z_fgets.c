/* ***************************************************
*  c2z : c2z_fgets.c :                               *
*                                                    *
*  next error fgets-005                              *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out FGETS                                   *
* ************************************************** */
void c2_fgets() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c c2_fgets START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int f1 = 0;
  int f2 = 0;
  int f2a = 0;
  int f3 = 0;
  int ret = 0;
  int x2 = 0;
  int x4 = 0;
  int x6 = 0;
  int size = 0;
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
  while (ch != ',') 
  {

    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  f3 = 0;
  for (f1 = 0; f1 < lv_ct; f1++) 
  {
    f2 = strcmp(field1, lw_variable[f1].lv_name);
    f2a = strcmp(sv_func, lw_variable[f1].lv_func);
    if ((f2 == 0) && (f2a == 0)) 
    {
      strcpy(field1a, lw_variable[f1].lv_value);
      f3 = 1;
      break;
    }
  }

  if(f3 == 0)
  {
    for (f1 = 0; f1 < gv_ct; f1++) 
    {
      f2 = strcmp(field1, gw_variable[f1].gv_name);
      if (f2 == 0) 
      {
        strcpy(field1a, gw_variable[f1].gv_cname);
        x6 = gw_variable[f1].gv_lgth;
        f3 = 1;
        break;
      }
    }
  }

  if (f3 == 0) 
  {
    printf("\nc2z_fgets.c c2_fgets fgets-001 field1 Not Found = %s\n", field1);
    printf("c2z_fgets.c c2_fgets rct = %d p_string = %s", rct, p_string);
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
  x2 = 0;
  while (ch != ',') 
  {
    if (ch != '_') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          x2 = 1;
          fd2_type = 1;
        }
        if (isalpha(ch)) 
        {
          x2 = 1;
          fd2_type = 2;
        }
      }
      field2[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  if (fd2_type == 2) 
  {
    f3 = 0;
    for (f1 = 0; f1 < lv_ct; f1++) 
    {
      f2 = strcmp(field2, lw_variable[f1].lv_name);
      f2a = strcmp(sv_func, lw_variable[f1].lv_func);
      if ((f2 == 0) && (f2a == 0)) 
      {
        strcpy(field2a, lw_variable[f1].lv_value);
        f3 = 1;
        break;
      }
    }

    if (f3 == 0) 
    {
      for (f1 = 0; f1 < gv_ct; f1++) 
      {
        f2 = strcmp(field2, gw_variable[f1].gv_name);
        if (f2 == 0) 
        {
          strcpy(field2a, gw_variable[f1].gv_cname);
          f3 = 1;
          break;
        }
      }
    }

    if (f3 == 0) 
    {
      printf("\nc2z_fgets.c c2_files fgets-002 field2 Not Found = %s\n", field2);
      printf("c2z_fgets.c c2_files rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  f3 = 0;
  for (f1 = 0; f1 < gv_ct; f1++) 
  {
    f2 = strcmp(field1, gw_variable[f1].gv_name);
    if (f2 == 0) 
    {
      gw_variable[f1].gv_lgth = x6 - 1;
      gw_variable[f1].gv_current_lgth = x6 - 1;
      f3 = 1;
      break;
    }
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
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  for (f1 = 0; f1 < fn_ct; f1++) 
  {
    f2 = strcmp(field3, w_file[f1].f_name);
    if (f2 == 0) 
    {
      strcpy(field3a, w_file[f1].f_cname);
      break;
    }
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, field3);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #1");
    trace_rec_3();
  }

  strcpy(a_string, "         GET   (R9)");
  strcpy(wk_remark, " fgets    */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #2");
    trace_rec_3();
  }

  x4 = 0;
  for (I = 0; I < f_ct; I++) 
  {
    x4 = w_file[I].f_buf_ct;
    ret = strcmp(field3, w_file[I].f_name);
    if (ret == 0) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #3");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370PB");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #4");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   ");
      strcat(a_string, "0(");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
      strcat(a_string, wk_strg);
      strcat(a_string, ",R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #5");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #6");
        trace_rec_3();
      }
      work_use_ct[49]++;

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';

      snprintf(wk_strg, sizeof(wk_strg), "%d", x6); 

      size = 0;
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
      strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
      strcpy(gw_variable[gv_ct].gv_name, c_wkname);
      strcpy(gw_variable[gv_ct].gv_type, "I");
      gw_variable[gv_ct].gv_lgth = 0;
      gw_variable[gv_ct].gv_current_lgth = 0;
      strcpy(gw_variable[gv_ct].gv_value, wk_strg);
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

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, c_wkname);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #7");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #8");
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
        strcpy(trace_1, "c2z_fgets.c #9");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #10");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #11");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #12");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #13");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #14");
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
        strcpy(trace_1, "c2z_fgets.c #15");
        trace_rec_3();
      }

      strcpy(a_string, "         IC    R0,0(R8,(R5))");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #16");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #17");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         STC   R0,0(0,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #18");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #19");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         LARL  R8,C370B1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #20");
        trace_rec_3();
      }
      work_use_ct[52]++;

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #21");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "         JLNE  L");
      strcat(a_string, wk_strg);
      strcat(a_string, "B");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #22");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #23");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #24");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #25");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "         JLU    L");
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #26");
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
        strcpy(trace_1, "c2z_fgets.c #27");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #28");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #29");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #30");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #31");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #32");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #33");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #34");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #35");
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
        strcpy(trace_1, "c2z_fgets.c #36");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R9");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #37");
        trace_rec_3();
      }

      strcpy(a_string, "         AR    R1,R2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #37");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #38");
        trace_rec_3();
      }
      work_use_ct[74]++;

      strcpy(a_string, "         MVC   0(1,R1),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_fgets.c #39");
        trace_rec_3();
      }
    }
  }

  convert = 1;
}

/* ***************************************************
*  Scan for FGETS                                    *
* ************************************************** */
void c2_scan_fgets() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c c2_scan_fgets START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];

  int pi;
  int pi2;
  int x3 = 0;
  int I = 0;
  int f2 = 0;
  int f2a = 0;
  int ret = 0;

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

  x3 = 0;
  if(lv_ct > 0)
  {
    for (I = 0; I < lv_ct; I++) 
    {
      f2 = strcmp(field1, lw_variable[I].lv_name);
      f2a = strcmp(sv_func, lw_variable[I].lv_func);
      if ((f2 == 0) && (f2a == 0)) 
      {
        strcpy(field1a, lw_variable[I].lv_value);
        x3 = 1;
      }
    }
  }

  if(x3 == 0)
  {
    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(field1a, gw_variable[I].gv_cname);
          x3 = 1;
        }
      }
    }
  }

  if (x3 == 0)
  {
    printf("\nc2z_fgets.c c2_scan_fgets fgets-003 field1 Not Found = %s\n", field1);
    printf("c2z_fgets.c c2_scan_fgets rct = %d p_string = %s", rct, p_string);
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
  while (ch != ',') 
  {
    if (ch != '_') 
    {
      field2[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(field2a, gw_variable[I].gv_cname);
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

  pi2 = 0;
  while (ch != ')') 
  {
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  x3 = 0;
  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(field3a, gw_variable[I].gv_cname);
        x3 = 1;
      }
    }
  }

  for (I = 0; I < f_ct; I++) 
  {
    ret = strcmp(field3, w_file[I].f_name);
    if (ret == 0) 
    {
      strcpy(w_file[I].f_type, "D");
      strcpy(w_file[I].f_perm, "I");
      strcpy(w_file[I].f_rec_lgth, field2);
      x3 = 1;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_fgets.c c2_scan_fgets fgets-004 Field3 Not Found in file table = %s\n",field3);
    printf("c2z_fgets.c c2_files rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }
}


/* ***************************************************
*  Punch out GETS                                    *
* ************************************************** */
void c2_gets() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c c2_gets START");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int x = 0;
  int x5 = 0;
  int x6 = 0;
  int x7 = 0;
  int ret = 0;
  int ret1 = 0;

  x = 1;
  
  if (x == 0) 
  {
    printf("\nc2z_scanf.c c2_scanf scanf-001 ERROR Invalid edit code\n");
    printf("c2z_scanf.c c2_scanf rct = %d p_string = %s", rct, p_string);
    erct++;
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
    if (ch != ' ') 
    {
      tfield1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  x5 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x5 = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
      x6 = lw_variable[I].lv_lgth;
      x7 = x6;
    }
  }

  if (x5 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x5 = 1;
        strcpy(tfield1a, gw_variable[I].gv_cname);
        x6 = gw_variable[I].gv_lgth;
        x7 = x6;
      }
    }
  }

  if (x5 == 0) 
  {
    printf("\nc2z_scanf.c c2_scanf scanf-003 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_scanf.c c2_scanf rct = %d p_string = %s", rct, p_string);
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
    strcpy(trace_1, "c2z_fgets.c #40");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #41");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #42");
    trace_rec_3();
  }

  x7--;
  snprintf(wk_strg, sizeof(wk_strg), "%d", x7);
  strcpy(a_string, "         MVC   1(");
  strcat(a_string,wk_strg);
  strcat(a_string, ",R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #43");
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
    strcpy(trace_1, "c2z_fgets.c #44");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ECB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #45");
    trace_rec_3();
  }
  work_use_ct[93]++;

  strcpy(a_string, "         WTOR  '?',(R9),");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
  strcat(a_string, wk_strg);
  strcat(a_string, ",(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #46");
    trace_rec_3();
  }

  strcpy(a_string, "         WAIT   ECB=(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #47");
    trace_rec_3();
  }

/* LAEY  R5,50  */
  snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
  strcpy(a_string, "         LAEY   R5,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #48");
    trace_rec_3();
  }

/* LARL  R7,C370U */
  strcpy(a_string, "         LARL   R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #49");
    trace_rec_3();
  }
  work_use_ct[48]++;

/*  CVD   R5,0(R7) */
  strcpy(a_string, "         CVD    R5,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #50");
    trace_rec_3();
  }

/* LARL  R8,C370NWK2  */ 
  strcpy(a_string, "         LARL   R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #51");
    trace_rec_3();
  }
  work_use_ct[50]++;

/* LARL  R7,C370U */
  strcpy(a_string, "         LARL   R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #52");
    trace_rec_3();
  }
  work_use_ct[48]++;

/* ZAP   0(6,R8),0(8,R7)   */
  strcpy(a_string, "         ZAP    0(6,R8),0(8,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #53");
    trace_rec_3();
  }

/*  L14A     DS    0H  */
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS     0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #54");
    trace_rec_3();
  }

/* LARL  R9,C370U   */
  strcpy(a_string, "         LARL   R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #55");
    trace_rec_3();
  }
  work_use_ct[48]++;

/*  LARL  R8,C370NWK2  */
  strcpy(a_string, "         LARL   R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #56");
    trace_rec_3();
  }
  work_use_ct[50]++;

/* ZAP   0(8,R9),2(4,R8) */
  strcpy(a_string, "         ZAP    0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #57");
    trace_rec_3();
  }

/* LARL  R8,C370U   */
  strcpy(a_string, "         LARL   R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #58");
    trace_rec_3();
  }
  work_use_ct[48]++;

/* CVB   R5,0(R8)  */
  strcpy(a_string, "         CVB    R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #59");
    trace_rec_3();
  }

/*  LARL  R8,C37F2  */
  strcpy(a_string, "         LARL   R9,");
  strcat(a_string, tfield1a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #60");
    trace_rec_3();
  }

/* IC    R0,0(R8,R5) */
  strcpy(a_string, "         IC     R0,0(R8,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #61");
    trace_rec_3();
  }

/* LARL  R9,C370L1 */
  strcpy(a_string, "         LARL   R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #62");
    trace_rec_3();
  }
  work_use_ct[2]++;

/* STC   R0,0(0,R9) */
  strcpy(a_string, "         STC    R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #63");
    trace_rec_3();
  }

/* LARL  R8,C370B1 */
  strcpy(a_string, "         LARL   R8,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #64");
    trace_rec_3();
  }
  work_use_ct[52]++;

/* CLC   0(1,R9),0(R8) */
  strcpy(a_string, "         CLC    0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #65");
    trace_rec_3();
  }

/*  JLNE  L14B */
  strcpy(a_string, "         JLNE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #66");
    trace_rec_3();
  }

/* LARL  R9,C370NWK2  */
  strcpy(a_string, "         LARL   R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #67");
    trace_rec_3();
  }
  work_use_ct[50]++;

/* LARL  R8,C370ONE   */
  strcpy(a_string, "         LARL   R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #68");
    trace_rec_3();
  }
  work_use_ct[33]++;

/* SP    0(6,R9),0(6,R8) */
  strcpy(a_string, "         SP     0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #69");
    trace_rec_3();
  }

/* JLU   L14A */
  strcpy(a_string, "         JLU    L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #70");
    trace_rec_3();
  }

/* L14B     DS    0H  */
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS     0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #71");
    trace_rec_3();
  }

/*  LARL  R9,C370U   */
  strcpy(a_string, "         LARL   R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #72");
    trace_rec_3();
  }
  work_use_ct[48]++;

/* LARL  R8,C370NWK2 */
  strcpy(a_string, "         LARL   R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #73");
    trace_rec_3();
  }
  work_use_ct[50]++;

/* ZAP   0(8,R9),2(4,R8) */
  strcpy(a_string, "         ZAP    0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #74");
    trace_rec_3();
  }

/* LARL  R9,C370U */
  strcpy(a_string, "         LARL   R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #75");
    trace_rec_3();
  }
  work_use_ct[48]++;

/* CVB   R2,0(R9) */
  strcpy(a_string, "         CVB    R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #76");
    trace_rec_3();
  }

/* LARL  R9,C37F2 */
  strcpy(a_string, "         LARL   R9,");
  strcat(a_string, tfield1a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #77");
    trace_rec_3();
  }

/* LR    R1,R9 */ 
  strcpy(a_string, "         LR     R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #78");
    trace_rec_3();
  }

/* AR    R1,R2   */
  strcpy(a_string, "         AR     R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #79");
    trace_rec_3();
  }

/* LARL  R8,C370EOF  */
  strcpy(a_string, "         LARL   R8,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #80");
    trace_rec_3();
  }

/* MVC   0(1,R1),0(R8) */
  strcpy(a_string, "         MVC    0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fgets.c #81");
    trace_rec_3();
  }

  convert = 1;
  return;
}





