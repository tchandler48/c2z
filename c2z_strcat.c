/* ***************************************************
*  c2z : c2z_strcat.c :                              *
*                                                    *
*  next error  strcat-008                            *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out STRCAT                                  *
* ************************************************** */
void c2_strcat(void) 
{
  char ch;
  char *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield4a[VAR_LGTH];

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
  int x96 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int s = 0;
  int fd2_type = 0;
  int fd3_type = 0;
  int fd4_type = 0;

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
      strcpy(trace_1, "c2z_strcat.c c2_strcat struct START");
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

    pi2 = 0;
    x2 = 0;
    fd4_type = 0;
    pi++;
    pi++;
    ch = p_string[pi];
    while(ch != ')')
    {
      if (x2 == 0) 
      {
        if (ch == '\"')
        {
          fd4_type = 3;
          x2 = 1;
        }
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
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

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

    if(fd4_type == 2)
    {
      x3 = 0;
      x2 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield4, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield4a, lw_variable[I].lv_cname);
          x2 = lw_variable[I].lv_current_lgth;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield4, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield4a, gw_variable[I].gv_cname);
            x2 = gw_variable[I].gv_current_lgth;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_strcat.c c2_strcat strcat-002 tfield4 Not Found = %s\n", tfield4);
        printf("c2z_string.c c2_strcat rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    x3 = 0;
    for (I = 0; I < m_struc_ct; I++) 
    {
      ret = strcmp(tfield1, w_struc[I].st_wname);
      ret1 = strcmp(tfield3, w_struc[I].st_field_name);
      if ((ret == 0) && (ret1 == 0)) 
      {
         x3 = 1;
         strcpy(tfield3a, w_struc[I].st_field_cname);
         x96 = w_struc[I].st_disp;
         break;
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_strcat strcat-042 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_strcpy.c c2_strcat tfield3 Not Found = %s\n",tfield3);
      printf("c2z_strcpy.c c2_strcat rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1000");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1001");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1002");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "T");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1003");
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
      strcpy(trace_1, "c2z_strcat.c #1004");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1005");
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
      strcpy(trace_1, "c2z_strcat.c #1006");
      trace_rec_3();
    }
  
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1007");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1008");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1009");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1010");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1011");
      trace_rec_3();
    }
        
    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "L(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1012");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1013");
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
      strcpy(trace_1, "c2z_strcat.c #1014");
      trace_rec_3();
    }
  
    strcpy(a_string, "* found location in 2d array ");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1015");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NCVT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #1016");
      trace_rec_3();
    }
    work_use_ct[104]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1017");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1018");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R6,");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
      strcat(a_string, wk_strg);
      strcat(a_string, "(R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1019");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "C");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1020");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1021");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1022");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1023");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1024");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1025");
        trace_rec_3();
      }

      strcpy(a_string, "         IC    R0,0(R6,(R5))");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1026");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1027");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         STC   R0,0(0,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1028");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1029");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1030");
        trace_rec_3();
      }

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1031");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "D");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1032");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1033");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1034");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1035");
        trace_rec_3();
      }

      strcpy(a_string, "         JLU   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "C");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1036");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "D");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1037");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1038");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1039");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1040");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1041");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1042");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1043");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1044");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1045");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1046");
        trace_rec_3();
      }

      if(fd4_type == 2)
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, tfield4a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield4);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcat.c #1047a");
          trace_rec_3();
        }
      }

      if(fd4_type == 3)
      {
        for (x3 = 0; x3 < char_ct; x3++) 
        {  
          if(rct == w_charlit[x3].clit_rct)
          {
             snprintf(wk_strg, sizeof(wk_strg), "%d", w_charlit[x3].clit_lgth);
             strcpy(a_string, "         LARL  R8,");
             strcat(a_string, w_charlit[x3].clit_cname);
             src_line();
             if (puncde == 1) 
             {
               strcpy(trace_1, "c2z_strcat.c #1047b");
               trace_rec_3();
             }
           }
        }
      }  

      strcpy(a_string, "         IC    R0,0(R8,(R5))");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1048");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1049");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         STC   R0,0(0,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1050");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1051");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1052");
        trace_rec_3();
      }

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1053");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "F");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1054");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1055");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1056");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1057");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1058");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1059");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R6");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1060");
        trace_rec_3();
      }

      strcpy(a_string, "         AR    R1,R2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1061");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1062");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         MVC   0(1,R1),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1063");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1064");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1065");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1066");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1067");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1068");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1069");
        trace_rec_3();
      }

      strcpy(a_string, "         JLU   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1070");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "F");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1071");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1072");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1073");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1074");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1075");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1076");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R6");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1077");
        trace_rec_3();
      }

      strcpy(a_string, "         AR    R1,R2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1078");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1079");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         MVC   0(1,R1),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #1080");
        trace_rec_3();
      }
   

    if(fd3_type == 1)
    {
printf("c2z_strcat.c  FINISH THIS CODE\n");
printf("c2z_strcat.c  rct = %d p_string = %s",rct,p_string);
printf("c2z_strcat.c tfield3 = %s tfield3a = %s\n",tfield3,tfield3a);
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
    x2 = 0;
    fd3_type = 0;
    pi++;
    pi++;
    ch = p_string[pi];
    while(ch != ')')
    {
      if(ch != ' ')
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
      }
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    p = strstr(tfield3, "\"");
    if(p)
    {
      fd3_type = 0;
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

/*
printf("\nc2z_strcat.c #20 rct = %d p_string = %s",rct,p_string);
printf("c2z_strcat.c #20 tfield1 = %s\n",tfield1);
printf("c2z_strcat.c #20 tfield2 = %s\n",tfield2);
printf("c2z_strcat.c #20 tfield3 = %s\n",tfield3);
*/

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #20");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #21");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #22");
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
      strcpy(trace_1, "c2z_strcat.c #23");
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
      strcpy(trace_1, "c2z_strcat.c #24");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #25");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield2);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #26");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #27");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #28");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #29");
       trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #30");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #31");
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
        strcpy(trace_1, "c2z_strcat.c #32");
        trace_rec_3();
      }
    }
  
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #33");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #34");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #35");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #36");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #37");
      trace_rec_3();
    }
        
    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");     
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #38");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #39");
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
      strcpy(trace_1, "c2z_strcat.c #40");
      trace_rec_3();
    }

    if(fd3_type == 2)
    {
      x3 = 0;
      x2 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield3a, lw_variable[I].lv_cname);
          x2 = lw_variable[I].lv_current_lgth;
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
            x2 = gw_variable[I].gv_current_lgth;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_strcat.c c2_strcat strcat-004 tfield3 Not Found = %s\n", tfield3);
        printf("c2z_string.c c2_strcat rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #41");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #42");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #43");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "C");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #44");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #45");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #46");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #47");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #48");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #49");
        trace_rec_3();
      }

      strcpy(a_string, "         IC    R0,0(R6,(R5))");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #50");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #51");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         STC   R0,0(0,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #52");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #53");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #54");
        trace_rec_3();
      }

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #55");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "D");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #56");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #57");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #58");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #59");
        trace_rec_3();
      }

      strcpy(a_string, "         JLU   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "C");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #60");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "D");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #61");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #62");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #63");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #64");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #65");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #66");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #67");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #68");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #69");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #70");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #71");
        trace_rec_3();
      }

      strcpy(a_string, "         IC    R0,0(R8,(R5))");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #72");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #73");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         STC   R0,0(0,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #74");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #75");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #76");
        trace_rec_3();
      }

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #77");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "F");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #78");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #79");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #80");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #81");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #82");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #83");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R6");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #84");
        trace_rec_3();
      }

      strcpy(a_string, "         AR    R1,R2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #85");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #86");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         MVC   0(1,R1),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #87");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #88");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #89");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #90");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #91");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #92");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #93");
        trace_rec_3();
      }

      strcpy(a_string, "         JLU   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #94");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "F");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #95");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #96");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #97");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #98");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #99");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #100");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R6");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #101");
        trace_rec_3();
      }

      strcpy(a_string, "         AR    R1,R2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #102");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #103");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         MVC   0(1,R1),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #104");
        trace_rec_3();
      }
    }

    if(fd3_type == 0)
    {
      for (x3 = 0; x3 < char_ct; x3++) 
      {  
        if(rct == w_charlit[x3].clit_rct)
        {
           snprintf(wk_strg, sizeof(wk_strg), "%d", w_charlit[x3].clit_lgth);
           strcpy(a_string, "         LARL  R9,");
           strcat(a_string, w_charlit[x3].clit_cname);
           src_line();
           if (puncde == 1) 
           {
             strcpy(trace_1, "c2z_strcat.c #43");
             trace_rec_3();
           }
         }
      }

      strcpy(a_string, "         MVC   0(");
      strcat(a_string, wk_strg);
      strcat(a_string, ",R6),0(R9)"); 
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcat.c #44");
        trace_rec_3();
      }
    }


    if(fd3_type == 1)
    {
printf("c2z_strcat.c  FINISH THIS CODE\n");
printf("c2z_strcat.c  rct = %d p_string = %s",rct,p_string);
printf("c2z_strcat.c tfield3 = %s tfield3a = %s\n",tfield3,tfield3a);
    }


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
        x2 = w_charlit[I].clit_lgth;
      }
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
        x5 = lw_variable[I].lv_current_lgth;
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
          x5 = gw_variable[I].gv_current_lgth;
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
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_string.c #50");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_string.c #51");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_string.c #52");
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
        strcpy(tfield1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_current_lgth = x2 + x5;
        break;
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
          gw_variable[I].gv_current_lgth = x2 + x5;
          break;
        }
      }
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
        x5 = lw_variable[I].lv_current_lgth;
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
          x5 = gw_variable[I].gv_current_lgth;
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
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcat.c #53");
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
      strcpy(trace_1, "c2z_strcat.c #54");
      trace_rec_3();
    }

    x2--;
  
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
      strcpy(trace_1, "c2z_string.c #55");
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
        lw_variable[I].lv_current_lgth = x2 + x5;
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
          gw_variable[I].gv_current_lgth = x2 + x5;
        }
      }
    }
  }
  convert = 1;
}
