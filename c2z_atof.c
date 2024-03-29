/* ***************************************************
*  c2z : c2z_atof.c :                                *
*                                                    *
*  next error - atoi-006                             *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out atoi                                    *
* ************************************************** */
void c2_atof(void) 
{
   int I = 0;
   int s = 0;
   int x30 = 0;
   int x31 = 0;

  char ch;

  x30 = 0;
  x31 = 0;
  s = strlen(p_string);
  for(I=0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '[')
    {
      x30++;
    }
    if(ch == ']')
    {
       x31++;
    }
  }

/*
printf("\nc2z_atof.c rct = %d p_string = %s",rct,p_string);
printf("c2z_atof.c x30 = %d\n",x30);
printf("c2z_atof.c x31 = %d\n",x31);
*/

  /* ***************************************************************
   *   x30    x31                                                  *
   *    [      ]                                                   *     
   *    0      0    c2_atof_00   x = atoi(abc)                     *
   *    1      1    c2_atof_11   array1[x] = atoi(abc)             *
   *    2      2    c2_atof_22   spreadsheet[x][y] = atoi(abc)     *
   *************************************************************** */

  if((x30 == 0) && (x31 == 0))
  {
     c2_atof_00();
     convert = 1;
     return;
  }

  if((x30 == 1) && (x31 == 1))
  {
     c2_atof_11();
     convert = 1;
     return;
  }

  if((x30 == 2) && (x31 == 2))
  {
     c2_atof_22();
     convert = 1;
     return;
  }
}



void c2_atof_11()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.atof.c c2_atof_11 START");
    trace_rec_1();
  }

  int pi;
  int pi2;
  int x2;
  int x3 = 0;
  int x9 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int fd2_type = 0;

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];
  char ar_field12[VAR_LGTH];

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

  x2 = 0;
  fd2_type = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if(x2 == 0) 
    {
      if(isdigit(ch)) 
      {
        fd2_type = 2;
        x2 = 1;
      }
      if(isalpha(ch)) 
      {
	 fd2_type = 1;
        x2 = 1;
      }
    }
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

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
  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(ar_field5, gw_variable[I].gv_dsect);
        strcpy(ar_field6, gw_variable[I].gv_label);
        strcpy(ar_field7, gw_variable[I].gv_table);
        strcpy(ar_field8, gw_variable[I].gv_aname);
        strcpy(ar_field9, gw_variable[I].gv_sv_reg);
        strcpy(ar_field10, gw_variable[I].gv_wk_reg);
        strcpy(ar_field11, gw_variable[I].gv_wk_strg);
        strcpy(ar_field12, gw_variable[I].gv_type);
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_atoi.c c2_atoi_11 atoi-003 field1 Not Found = %s\n", field1);
    printf("c2z_atoi.c c2_atoi_11 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if(fd2_type == 1)
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
        x9 = lw_variable[I].lv_current_lgth;
        break;
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
          x9 = gw_variable[I].gv_current_lgth;
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi_11 atoi-004 field2 Not Found = %s\n", field2);
      printf("c2z_atoi.c c2_atoi_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
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
      strcpy(field3a, lw_variable[I].lv_cname);
      x9 = lw_variable[I].lv_current_lgth;
      break;
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
        x9 = gw_variable[I].gv_current_lgth;
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_atof.c c2_atof_11 atoi-005 field3 Not Found = %s\n", field3);
    printf("c2z_atof.c c2_atof_11 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atof.c #1100");
    trace_rec_3();
  }

  if(strcmp(ar_field12, "G") == 0)
  {
      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1101");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1102");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1103");
        trace_rec_3();
      }

      if(fd2_type == 2)
      {
        strcpy(a_string, "         LAEY  R5,");
        strcat(a_string, field2);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field2);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atof.c #1104");
          trace_rec_3();
        }
      
        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atof.c #1105");
          trace_rec_3();
        }

        strcpy(a_string, "         CVD   R5,0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atof.c #1106");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atof.c #1107");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atof.c #1108");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R7),0(8,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atof.c #1109");
          trace_rec_3();
        }
      }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, ar_field7);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1110");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "AA");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1111");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1112");
        trace_rec_3();
      }
      work_use_ct[49]++;

      if(fd2_type == 1)
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field2a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field2);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atof.c #1113");
          trace_rec_3();
        }
        work_use_ct[50]++;
      }

      if(fd2_type == 2)
      {
        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atof.c #1114");
          trace_rec_3();
        }
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1115");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "BB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1116");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1117");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1118");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1119");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, ar_field6);
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1120");
        trace_rec_3();
      }
 
      strcpy(a_string, "         JLU   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "AA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1121");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "BB");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1122");
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
        strcpy(trace_1, "c2z_atof.c #1123");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
      strcpy(a_string, "         PACK  0(6,R6),0(");
      strcat(a_string,wk_strg);
      strcat(a_string, ",R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atof.c #1124");
        trace_rec_3();
      }

    convert = 1;
    return;
  }
}



void c2_atof_00()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.atof.c c2_atof_00 START");
    trace_rec_1();
  }

  int pi;
  int pi2;
  int x3 = 0;
  int x9 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];

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
      break;
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
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_atof.c c2_atof_00 atof-001 field1 Not Found = %s\n", field1);
    printf("c2z_atof.c c2_atof_00 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

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
      x9 = lw_variable[I].lv_current_lgth;
      break;
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
        x9 = gw_variable[I].gv_current_lgth;
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_atof.c c2_atof_00 atoi-002 field2 Not Found = %s\n", field2);
    printf("c2z_atof.c c2_atof_00 rct = %d p_string = %s", rct, p_string);
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
    strcpy(trace_1, "c2z_atof.c #1");
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
    strcpy(trace_1, "c2z_atof.c #2");
    trace_rec_3();
  }

  if(x9 > 6)
  {
    x9 = 6;
  }
  snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
  strcpy(a_string, "         PACK  0(6,R9),0(");
  strcat(a_string, wk_strg);
  strcat(a_string, ",R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atof.c #3");
    trace_rec_3();
  }
}

  
void c2_atof_22()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.atof.c c2_atof_22 START");
    trace_rec_1();
  }
  int pi;
  int pi2;
  int x3 = 0;
  int x9 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];

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
        break;
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
          strcpy(ar_field5, gw_variable[I].gv_dsect);
          strcpy(ar_field6, gw_variable[I].gv_label);
          strcpy(ar_field7, gw_variable[I].gv_table);
          strcpy(ar_field8, gw_variable[I].gv_aname);
          strcpy(ar_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar_field11, gw_variable[I].gv_wk_strg);
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atof.c c2_atof_022 atoi-001 field1 Not Found = %s\n", field1);
      printf("c2z_atof.c c2_atof_022 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

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
        x9 = lw_variable[I].lv_lgth;
        break;
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
          x9 = gw_variable[I].gv_lgth;
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atof.c c2_atof_022 atoi-002 field2 Not Found = %s\n", field2);
      printf("c2z_atof.c c2_atof_022 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi2 = 0;
    pi++;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

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
        x9 = lw_variable[I].lv_lgth;
        break;
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
          x9 = gw_variable[I].gv_lgth;
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atof.c c2_atof_022 atof-303 field3 Not Found = %s\n", field3);
      printf("c2z_atof.c c2_atof_022 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    while(ch != '(')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      field4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field4[pi2] = '\0';

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
        x9 = lw_variable[I].lv_current_lgth;
        break;
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
          x9 = gw_variable[I].gv_current_lgth;
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atof.c c2_atof_022 atof-304 field4 Not Found = %s\n", field4);
      printf("c2z_atof.c c2_atof_022 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }


  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atof.c #385");
    trace_rec_3();
  }

   strcpy(a_string, "         LARL  R9,C370NCVT");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_atof.c #387");
     trace_rec_3();
   }
   work_use_ct[104]++;
  
   strcpy(a_string, "         LARL  R8,");
   strcat(a_string, field4a);
   strcpy(wk_remark, " ");
   strcat(wk_remark, field4);
   strcat(wk_remark, " */");
   write_remark();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_atof.c #386");
     trace_rec_3();
   }

   if(x9 > 6)
   {
     x9 = 6;
   }
   
   snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
   strcpy(a_string, "         PACK  0(6,R9),0(");
   strcat(a_string, wk_strg);
   strcat(a_string, ",R8)");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_atof.c #388");
     trace_rec_3();
   }

    strcpy(a_string, "* now find index value *");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #389");
      trace_rec_3();
    }

/*  find displacement in array  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #390");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #391");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #392");
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
      strcpy(trace_1, "c2z_atof.c #393");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #394");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #395");
      trace_rec_3();
    }

    strcpy(a_string, "         JLNE  ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "M");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #396");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #397");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #398");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #399");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "R");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #400");
      trace_rec_3();
    }

/* ROW IS GREATER THAN ZERO  */
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "M");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #401");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #402a");
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
      strcpy(trace_1, "c2z_atof.c #402b");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #402c");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R5,26");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #403");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #404");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #405");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #406");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #407");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #408");
      trace_rec_3();
    }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #409");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #410");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #411");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #412");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #413");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #414");
      trace_rec_3();
    }

/* END OF ROUTINE C370NWK1 CONTAINS DISPLAYMENT */
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "R");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #415");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #416");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #417");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #418");
      trace_rec_3();
    }

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
           strcpy(ar_field5, gw_variable[I].gv_dsect);
           strcpy(ar_field6, gw_variable[I].gv_label);
           strcpy(ar_field7, gw_variable[I].gv_table);
           strcpy(ar_field8, gw_variable[I].gv_aname);
           strcpy(ar_field9, gw_variable[I].gv_sv_reg);
           strcpy(ar_field10, gw_variable[I].gv_wk_reg);
           strcpy(ar_field11, gw_variable[I].gv_wk_strg);
           break;
         }
       }
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #419");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "S");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #420");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #421");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #422");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #423");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "T");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #424");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #425");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #426");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atof.c #427");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atof.c #428");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "S");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atof.c #429");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "T");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atof.c #430");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NCVT");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atof.c #431");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         ZAP   ");
  strcat(a_string, "0(6,R6),");
  strcat(a_string, "0(6,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atof.c #432");
    trace_rec_3();
  }
}

