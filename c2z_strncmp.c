/* ***************************************************
*  c2z : c2Z_strncmp.c :                             *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */


void c2_strncmp_2() 					/*  x = strncmp(field1,field2[xx],nn)		*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strncmp.c c2_strncmp_2");
    trace_rec_1();
  }

   int pi;
   int x2;
   int pi2;
   int fd1_type;
   int fd2_type;
   int fd4_type;
   int fd5_type;
   int I;
   int ret;
   int ret1;
   int x1;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field2b[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field11[VAR_LGTH];
  char field12[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
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
  while (ch != ',') 
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

  x2 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != '[') 
  {
    if(ch != ' ')
    {
      field3[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  x2 = 0;
  pi2 = 0;
  while (ch != ']') 
  {
    if(ch != '[')
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
      field4[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';

  x2 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if(ch != ',')
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
    }
    pi++;
    ch = p_string[pi];
  }
  field5[pi2] = '\0';

  if ((fd1_type == 2) && (fd2_type == 2)) 
  {
    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_stnrcmp.c c2_strncmp_2 strcmp-012 field1 Not Found = %s\n", field1);
      printf("c2z_strncmp.c c2_strncmp_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        strcpy(field2b, lw_variable[I].lv_type);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          strcpy(field2b, gw_variable[I].gv_type);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strncmp.c c2_strncmp_2 strcmp-013 field2 Not Found = %s\n", field2);
      printf("c2z_strncmp.c c2_strncmp_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  x1 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field3, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x1 = 1;
      strcpy(field3a, lw_variable[I].lv_cname);
    }
  }

  if (x1 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x1 = 1;
        strcpy(field3a, gw_variable[I].gv_cname);
      }
    }
  }
  
  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field3a, gw_variable[I].gv_cname);
      if (ret == 0) 
      {
          strcpy(field6, gw_variable[I].gv_dsect);
          strcpy(field7, gw_variable[I].gv_label);
          strcpy(field8, gw_variable[I].gv_table);
          strcpy(field9, gw_variable[I].gv_aname);
          strcpy(field10, gw_variable[I].gv_sv_reg);
          strcpy(field11, gw_variable[I].gv_wk_reg);
          strcpy(field12, gw_variable[I].gv_wk_strg);
          gw_variable[I].gv_flag = 1;
      }
    }
  }


  if (fd4_type == 2) 
  {
    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field4a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(field4a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strncmp.c c2_strncmp_2 strcmp-015 field4 Not Found = %s\n", field4);
      printf("c2z_strncmp.c c2_strncmp_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (fd5_type == 2) 
  {
    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field5, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field5a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field5, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(field5a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strncmp.c c2_strncmp_2 strcmp-015 field4 Not Found = %s\n", field5);
      printf("c2z_strncmp.c c2_strncmp_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }


   array_clear = 1;

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #2");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #3");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #4");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #5");
      trace_rec_3();
    }


    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field8);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #6");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #7");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #8");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #9");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #10");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #11");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #12");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #13");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #14");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field7);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #15");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #16");
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
      strcpy(trace_1, "c2z_strncmp.c #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #18");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #19");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #20");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "H");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #21");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #22");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #23");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #24");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " #1 ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #25");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #26");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #27");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "I");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #28");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #29");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #30");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #31");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " #2 ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #32");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #33");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #34");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "J");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #35");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #36");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #37");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #38");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " #3 ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #39");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #40");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #41");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "K");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #42");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #43");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #44");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #45");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " #4 ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #46");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #47");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #48");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "L");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #49");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #50");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #51");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #52");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " #5 ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #53");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #54");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #55");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "M");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #56");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #57");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #58");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #59");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " #5 ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #60");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #61");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #62");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "N");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #63");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #64");
      trace_rec_3();
    }

    strcpy(a_string, "L");		/* 1 */
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "I");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #65");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " #1 ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #66");
      trace_rec_3();
    }


    strcpy(a_string, "         CLC   0(1,R7),0(R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #67");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #68");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #69");
      trace_rec_3();
    }

    strcpy(a_string, "L");		/* 1 */
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "J");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #70");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " #2 ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #71");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(2,R7),0(R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #72");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #73");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #74");
      trace_rec_3();
    }

    strcpy(a_string, "L");		/* 1 */
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "K");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #75");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " #3 ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #76");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(3,R7),0(R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #77");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #78");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #79");
      trace_rec_3();
    }

    strcpy(a_string, "L");		/* 1 */
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "L");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #80");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " #4 ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #81");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(4,R7),0(R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #82");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #83");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #84");
      trace_rec_3();
    }

    strcpy(a_string, "L");		/* 1 */
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "M");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #85");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " #5 ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #86");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(5,R7),0(R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #87");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #88");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #89");
      trace_rec_3();
    }

    strcpy(a_string, "L");		/* 1 */
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "N");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #90");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " #5 ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #91");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(6,R7),0(R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #92");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #93");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #94");
      trace_rec_3();
    }


    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #95");
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
      strcpy(trace_1, "c2z_strncmp.c #96");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #97");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncmp.c #98");
      trace_rec_3();
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
      strcpy(trace_1, "c2z_strncmp.c #99");
      trace_rec_3();
    }

    while_array = 1;
    strcpy(while_array_name, field10);
    strcpy(while_array_table, field7);

    convert = 1;
}

