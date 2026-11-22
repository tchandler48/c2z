/* ***************************************************
*  c2z : c2z_strcat.c :                              *
*                                                    *
*  next error  strcat-008                            *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* ***************************************************
*  Punch out STRCAT                                  *
* ************************************************** */
void c2_strcat(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcat.c c2_strcat START");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];

  char ar_field5[12];
  char ar_field6[12];
  char ar_field7[12];
  char ar_field8[12];
  char ar_field9[12];
  char ar_field10[12];
  char ar_field11[12];

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x5 = 0;
  int x80 = 0;
  int x81 = 0;
  int x82 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int s = 0;
  int size = 0;
  int fd2_type = 0;

  x80 = 0;
  x81 = 0;
  x82 = 0;
  s = strlen(p_string);
  for(I = 0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '[')
    {
      x80++;
    }
    if(ch == ']')
    {
      x81++;
    }
    if(ch == '.')
    {
      x82++;
    }
  }

  if((x80 == 1) && (x81 == 1) && (x82 == 1))		/*	strcat(gw_variable[gv_ct].gv_name, "123456"); */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat {]. START");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while(ch != '(')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != '[')
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
    while(ch != ']')
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    pi2 = 0;
    pi++;
    pi++;
    ch = p_string[pi];
    while(ch != ',')
    {
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    x3 = 0;
    x2 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        x2 = lw_variable[I].lv_current_lgth;
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
          x2 = gw_variable[I].gv_current_lgth;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcat.c c2_strcat strcat-001 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_string.c c2_strcat rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    x2 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        x2 = lw_variable[I].lv_current_lgth;
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
          x2 = gw_variable[I].gv_current_lgth;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcat.c c2_strcat strcat-002 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_string.c c2_strcat rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "T");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #4");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #6");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #7");
      trace_rec_3();
    }
  
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #8");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #10");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #11");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #12");
      trace_rec_3();
    }
        
    strcpy(a_string, "         LA    R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "L(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #13");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #14");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Struc #15");
      trace_rec_3();
    }

    convert = 1;
    return;
  }


  if((x80 == 1) && (x81 == 1) && (x82 == 0))		/*	  strcat(in_stack[t], b);	 */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array START");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while(ch != '(')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != '[')
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
    while(ch != ']')
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

    pi2 = 0;
    pi++;
    pi++;
    ch = p_string[pi];
    while(ch != ')')
    {
      if(ch != ' ')
      {
        tfield3[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    x3 = 0;
    x2 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        x2 = lw_variable[I].lv_current_lgth;
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
          x2 = gw_variable[I].gv_current_lgth;
          strcpy(ar_field5, gw_variable[I].gv_dsect);
          strcpy(ar_field6, gw_variable[I].gv_label);
          strcpy(ar_field7, gw_variable[I].gv_table);
          strcpy(ar_field8, gw_variable[I].gv_aname);
          strcpy(ar_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar_field11, gw_variable[I].gv_wk_strg);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcat.c c2_strcat strcat-003 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_string.c c2_strcat rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

/*
printf("c2z_strcat.c rct = %d ar_field5 = %s\n",rct,ar_field5);
printf("c2z_strcat.c rct = %d ar_field6 = %s\n",rct,ar_field6);
printf("c2z_strcat.c rct = %d ar_field7 = %s\n",rct,ar_field7);
printf("c2z_strcat.c rct = %d ar_field8 = %s\n",rct,ar_field8);
printf("c2z_strcat.c rct = %d ar_field9 = %s\n",rct,ar_field9);
printf("c2z_strcat.c rct = %d ar_field10 = %s\n",rct,ar_field10);
printf("c2z_strcat.c rct = %d ar_field11 = %s\n",rct,ar_field11);
*/

    if(fd2_type == 1)
    {

    }

    if(fd2_type == 2)
    {
      x3 = 0;
      x2 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield2a, lw_variable[I].lv_cname);
          x2 = lw_variable[I].lv_current_lgth;
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
            x2 = gw_variable[I].gv_current_lgth;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_strcat.c c2_strcat strcat-004 tfield2 Not Found = %s\n", tfield2);
        printf("c2z_string.c c2_strcat rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #4");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #6");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LARL  R5,");
      strcat(a_string, tfield2);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c c2_strcat Array #7");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c c2_strcat Array #8");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c c2_strcat Array #9");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c c2_strcat Array #10");
       trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c c2_strcat Array #11");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c c2_strcat Array #12");
        trace_rec_3();
      }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c c2_strcat Array #13");
        trace_rec_3();
      }
    }
  
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #14");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #16");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #17");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #18");
      trace_rec_3();
    }
        
    strcpy(a_string, "         LA    R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");     
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #19");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #20");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat Array #21");
      trace_rec_3();
    }

printf("c2z_strcat.c  FINISH THIS CODE\n");
printf("c2z_strcat.c  rct = %d p_string = %s",rct,p_string);

    convert = 1;
    return;
  }



  pi = 0;
  pi2 = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
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

  if (ch == '"') 
  {
    /* this is a literal Search clit table */
    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(tfield3, w_charlit[I].clit_value);
        strcpy(tfield2a, w_charlit[I].clit_cname);
        x5 = w_charlit[I].clit_lgth;
      }
    }

    x3 = 0;
    x2 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        x2 = lw_variable[I].lv_current_lgth;
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
          x2 = gw_variable[I].gv_current_lgth;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcat.c c2_strcat strcat-005 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_string.c c2_strcat rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_string.c c2_strcat #100");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_string.c c2_strcat #101");
      trace_rec_3();
    }

    strcpy(a_string, "        MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_string.c c2_strcat #102");
      trace_rec_3();
    }
  } 
  else 
  {
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
       /* x2 = lw_variable[I].lv_lgth; */
        x2 = lw_variable[I].lv_current_lgth;
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
          x2 = gw_variable[I].gv_current_lgth;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcat.c c2_strcat strcat-006 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_string.c c2_strcat rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x2++;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        x5 = lw_variable[I].lv_lgth;
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
          x5 = gw_variable[I].gv_lgth;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcat.c c2_strcat strcat-007 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_string.c c2_strcat rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, "C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    x2--;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield3a, c_wkname);

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
      strcpy(gw_variable[gv_ct].gv_name, tfield3a);
      strcpy(gw_variable[gv_ct].gv_type, "I");
      gw_variable[gv_ct].gv_lgth = x2;
      gw_variable[gv_ct].gv_current_lgth = 0;
      snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
      strcpy(gw_variable[gv_ct].gv_value, wk_strg);
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

      strcpy(tfield3,tfield3a);

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield3);
    strcpy(wk_remark, " lgth of fld */ ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #2");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #3");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #5");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #6");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #7");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #8");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R5,0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #9");
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
      strcpy(trace_1, "c2z_strcat.c c2_strcat #10");
      trace_rec_3();
    }

    strcpy(a_string, "         IC    R0,0(R8,(R5))");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #11");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #12");
      trace_rec_3();
    }

    strcpy(a_string, "         STC   R0,0(0,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #13");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #14");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #15");
      trace_rec_3();
    }
    work_use_ct[74]++;

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #16");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "         JLNE  ");
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #18");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #19");
      trace_rec_3();
    }

    strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #20");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "          JLU  ");
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #21");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #22");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #23");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #24");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c c2_strcat #25");
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
      strcpy(trace_1, "c2z_strcat.c c2_strcat #26");
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
      strcpy(trace_1, "c2z_strcat.c c2_strcat #27");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_string.c c2_strcat #28");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        lw_variable[I].lv_lgth = x2 + x5;
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
          gw_variable[I].gv_lgth = x2 + x5;
        }
      }
    }
  }
  convert = 1;
}
