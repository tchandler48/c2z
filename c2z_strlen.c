/* ***************************************************
*  c2z : c2z_strlen.c :                              *
*                                                    *
*  next error - strlen-011                           *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out STRLEN                                  *
* ************************************************** */
void c2_strlen() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c c2_strlen START");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];;
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield7a[VAR_LGTH];
  char tfield8[VAR_LGTH];
  char tfield8a[VAR_LGTH];

  char ar_field5[12];
  char ar_field6[12];
  char ar_field7[12];
  char ar_field8[12];
  char ar_field9[12];
  char ar_field10[12];
  char ar_field11[12];

  int pi;
  int pi2;
  int strl_1 = 0;
  int strl_3 = 0;
  int x2 = 0;
  int x3 = 0;
  int I = 0;
  int s = 0;
  int x80 = 0;
  int x81 = 0;
  int x82 = 0;
  int x91 = 0;
  int x92 = 0;
  int x99 = 0;
  int fd3_type = 0;

  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
  int end_of_string = 0;
  int array_found = 0;

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

  if((x80 == 1) && (x81 == 1) && (x82 == 0))			 /* len = strlen(sv_stack[ndx]); */
  {
     pi = 0;
     ch = p_string[pi];
     while((ch == ' ') || (ch == '\t') || (ch == '{'))
     {
       pi++;
       ch = p_string[pi];
     }

     pi2 = 0;
     ch = p_string[pi];
     while(ch != ' ')
     {
       tfield1[pi2] = ch;
       pi2++;
       pi++;
       ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

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
       tfield2[pi2] = ch;
       pi2++;
       pi++;
       ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    fd3_type = 0;
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

    x3 = 0;
    if (lv_ct > 0) 
    {
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
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (strl_1 == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strlen.c array E-001 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_strlen.c array rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, gw_variable[I].gv_cname);
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

    x3 = 0;
    if (lv_ct > 0) 
    {
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
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield3, gw_variable[I].gv_name);
          if (strl_1 == 0) 
          {
            x3 = 1;
            strcpy(tfield3a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strlen.c array E-003 tfield3 Not Found = %s\n", tfield3);
      printf("c2z_strlen.c array rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #2");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #3");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #5");
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
      strcpy(trace_1, "c2z_strlen.c #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #7");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strlen.c #8");
        trace_rec_3();
      }
    }

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield3);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strlen.c #9");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strlen.c #10");
        trace_rec_3();
      }
 
      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strlen.c #11");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK3");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strlen.c #12");
        trace_rec_3();
      }
      work_use_ct[78]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strlen.c #13");
        trace_rec_3();
      }
 
      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strlen.c #14");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #15");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #16");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #18");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #19");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #20");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #21");
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
       strcpy(trace_1, "c2z_strlen.c #22");
       trace_rec_3();
     }

     strcpy(tfield8, "s_holder");
     x3 = 0;
     if (lv_ct > 0) 
     {
       for (I = 0; I < lv_ct; I++) 
       {
         ret = strcmp(tfield8, lw_variable[I].lv_name);
         ret1 = strcmp(sv_func, lw_variable[I].lv_func);
         if ((ret == 0) && (ret1 == 0)) 
         {
           x3 = 1;
           strcpy(tfield8a, lw_variable[I].lv_cname);
           lw_variable[I].lv_use_ct++;
         }
       }
     }

     if (x3 == 0) 
     {
       if (gv_ct > 0) 
       {
         for (I = 0; I < gv_ct; I++) 
         {
           ret = strcmp(tfield8, gw_variable[I].gv_name);
           if (strl_1 == 0) 
           {
             x3 = 1;
             strcpy(tfield8a, gw_variable[I].gv_cname);
             gw_variable[I].gv_use_ct++;
           }
         }
       }
     }

     if (x3 == 0) 
     {
       printf("\nc2z_strlen.c array E-006 tfield8 Not Found = %s\n", tfield8);
       printf("c2z_strlen.c array rct = %d p_string = %s", rct, p_string);
       erct++;
       convert = 1;
       return;
     }

     strcpy(a_string, "         LARL  R9,");
     strcat(a_string, tfield8a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, tfield8);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #23");
       trace_rec_3();
     }

     x99 = 31;
     strcpy(a_string, "         MVC   ");
     strcat(a_string, "0(");
     snprintf(wk_strg, sizeof(wk_strg), "%d", x99); 
     strcat(a_string, wk_strg);
     strcat(a_string, ",R9)");
     strcat(a_string, ",");
     strcat(a_string, "0(R6)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #24");
       trace_rec_3();
     }

     strcpy(a_string, "         LAEY  R5,0");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #25");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R7,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #26");
       trace_rec_3();
     }

     strcpy(a_string, "         CVD   R5,0(R7)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #27");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #28");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R7,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #29");
       trace_rec_3();
     }

     strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #30");
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
       strcpy(trace_1, "c2z_strlen.c #31");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #32");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         LARL  R8,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #33");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #34");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #35");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         CVB   R5,0(R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #36");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,");
     strcat(a_string, tfield8a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, tfield8);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #37");
       trace_rec_3();
     }

     strcpy(a_string, "         IC    R0,0(R8,(R5))");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #38");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370L1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #39");
       trace_rec_3();
     }
     work_use_ct[2]++;

     strcpy(a_string, "         STC   R0,0(0,R9)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #40");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370L1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #41");
       trace_rec_3();
     }
     work_use_ct[2]++;

     strcpy(a_string, "         LARL  R8,C370EOF");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #42");
       trace_rec_3();
     }
     work_use_ct[74]++;
   
     strcpy(a_string, "         CLC   0(1,R9),0(R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #43");
       trace_rec_3();
     }

     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcpy(a_string, "         JLE   ");
     strcat(a_string, "L");
     strcat(a_string, wk_strg);
     strcat(a_string, "D");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #44");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #45");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         LARL  R8,C370ONE");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_strlen.c #46");
       trace_rec_3();
     }

     strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #47");
       trace_rec_3();
     }

     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcpy(a_string, "         JLU   ");
     strcat(a_string, "L");
     strcat(a_string, wk_strg);
     strcat(a_string, "C");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #48");
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
       strcpy(trace_1, "c2z_strlen.c #49");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,");
     strcat(a_string, tfield1a);
     strcpy(wk_remark, " ");
     strcpy(wk_remark, tfield1);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #50");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #51");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_strlen.c #52");
       trace_rec_3();
     }
  
    convert = 1;
    return;
  }
 

  if((x80 == 1) && (x81 == 1) && (x82 == 1))      		 /* s = strlen(gw_variable[gv_ct].gv_name); */
  {
     pi = 0;
     ch = p_string[pi];
     while((ch == ' ') || (ch == '\t') || (ch == '{'))
     {
       pi++;
       ch = p_string[pi];
     }

     pi2 = 0;
     ch = p_string[pi];
     while(ch != ' ')
     {
       tfield1[pi2] = ch;
       pi2++;
       pi++;
       ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

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
       tfield2[pi2] = ch;
       pi2++;
       pi++;
       ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != ']')
    {
       tfield3[pi2] = ch;
       pi2++;
       pi++;
       ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    pi2 = 0;
    pi++;
    pi++;
    ch = p_string[pi];
    while(ch != ')')
    {
       tfield4[pi2] = ch;
       pi2++;
       pi++;
       ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #61");
      trace_rec_3();
    }
    work_use_ct[49]++;
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #62");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #63");
      trace_rec_3();
    }

    strl_3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strl_3 = 1;
          strcpy(tfield2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (strl_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          strl_1 = strcmp(tfield2, gw_variable[I].gv_name);
          if (strl_1 == 0) 
          {
            strl_3 = 1;
            strcpy(tfield2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (strl_3 == 0) 
    {
      printf("\nc2z_strlen.c c2_strlen strlen-001 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_strlen.c c2_strlen rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, tfield2a);
    strcat(a_string, "T");
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #64");
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
      strcpy(trace_1, "c2z_strlen.c #65");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #66");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strl_3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strl_3 = 1;
          strcpy(tfield3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (strl_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          strl_1 = strcmp(tfield3, gw_variable[I].gv_name);
          if (strl_1 == 0) 
          {
            strl_3 = 1;
            strcpy(tfield3a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (strl_3 == 0) 
    {
      printf("\nc2z_strlen.c c2_strlen strlen-002 tfield3 Not Found = %s\n", tfield3);
      printf("c2z_strlen.c c2_strlen rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

 
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #67");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #68");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #69");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #70");
      trace_rec_3();
    }
    work_use_ct[49]++;
 
    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #71");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #72");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, tfield2a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #73");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #74");
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
      strcpy(trace_1, "c2z_strlen.c #75");
      trace_rec_3();
    }

    x91 = 0;
    x3 = 0;
    for (I = 0; I < m_struc_ct; I++) 
    {
      ret = strcmp(tfield2, w_struc[I].st_wname);
      ret1 = strcmp(tfield4,w_struc[I].st_field_name);
      if ((ret == 0) && (ret1 == 0))
      {
        x3 = 1;
        strcpy(tfield2a, w_struc[I].st_cwname);
        strcpy(tfield6a, w_struc[I].st_field_cname);
        strcpy(tfield7a, w_struc[I].st_type);
        x91 = w_struc[I].st_disp;
        x92 = w_struc[I].st_field_lgth;
        break;
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield6a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #76");
      trace_rec_3();
    }
   
    strcpy(a_string, "         MVC   0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x92);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x91);
    strcat(a_string, wk_strg);
    strcat(a_string, "(R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #77");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x92);
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #78");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R4,1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #79");
      trace_rec_3();
    }

    strcpy(a_string, "         SR    R5,R4");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #80");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #81");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #82");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #83");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #84");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #85");
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
      strcpy(trace_1, "c2z_strlen.c #86");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #87");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #88");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #89");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #90");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R5,0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #91");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield6a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #92");
      trace_rec_3();
    }

    strcpy(a_string, "         IC    R0,0(R8,(R5))");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #93");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #94");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         STC   R0,0(0,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #95");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #96");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #97");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #98");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "          JLNE  ");
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #99");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #100");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #101");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #102");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #103");
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
      strcpy(trace_1, "c2z_strlen.c #104");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #105");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #106");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #107");
      trace_rec_3();
    }

    strl_3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strl_3 = 1;
          strcpy(tfield1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (strl_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          strl_1 = strcmp(tfield1, gw_variable[I].gv_name);
          if (strl_1 == 0) 
          {
            strl_3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (strl_3 == 0) 
    {
      printf("\nc2z_strlen.c c2_strlen strlen-003 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_strlen.c c2_strlen rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #108");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #109");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #110");
      trace_rec_3();
    }

    convert = 1;
    return;
  }


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
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  strl_3 = 0;
  if (lv_ct > 0) 
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        strl_3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }
  }

  if (strl_3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        strl_1 = strcmp(tfield1, gw_variable[I].gv_name);
        if (strl_1 == 0) 
        {
          strl_3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }
  }

  if (strl_3 == 0) 
  {
    printf("\nc2z_strlen.c c2_strlen strlen-004 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_strlen.c c2_strlen rct = %d p_string = %s", rct, p_string);
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
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield2[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield2, lw_variable[I].lv_name);
    ret2 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret2 == 0)) 
    {
      x3 = 1;
      strcpy(tfield2a, lw_variable[I].lv_cname);
      ret2 = strcmp("A", lw_variable[I].lv_type);
      if (ret2 == 0) 
      {
        array_found = 1;
      }
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
        ret2 = strcmp("A", gw_variable[I].gv_type);
        if (ret2 == 0) 
        {
          array_found = 1;
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strlen.c c2_strlen strlen-005 tfield2 Not Found = %s\n", tfield2);
    printf("c2z_strlen.c c2_strlen rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (array_found == 0) 
  {
    tot_sizeof++;
    x3 = 0;
    x2 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        x2 = lw_variable[I].lv_lgth;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        break;
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
          x2 = gw_variable[I].gv_lgth;
          strcpy(tfield2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strlen.c c2_strlen strlen-006 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_strlen.c c2_strlen rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #114");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcpy(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #115");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #116");
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
      strcpy(trace_1, "c2z_strlen.c #117");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #118");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #119");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #120");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #121");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R5,0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #122");
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
      strcpy(trace_1, "c2z_strlen.c #123");
      trace_rec_3();
    }

    strcpy(a_string, "         IC    R0,0(R8,(R5))");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #124");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #125");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         STC   R0,0(0,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #126");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #127");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #128");
      trace_rec_3();
    }
    work_use_ct[74]++;
   
    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #129");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #130");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #131");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #132");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #133");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #134");
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
      strcpy(trace_1, "c2z_strlen.c #135");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #136");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #137");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strlen.c #138");
      trace_rec_3();
    }
  }

  if (array_found == 1) 
  {
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']')
    {
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';
  }

  convert = 1;
  return;
}

void c2_strlen_punch() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c c2_strlen_punch");
    trace_rec_1();
  }

  int v = 0;
  int wh_4 = 0;
  int I = 0;

  char field1a[VAR_LGTH];

  if (gv_ct > 0) 
  {
    for (v = 0; v < gv_ct; v++) 
    {
      wh_4 = strcmp("STRLEN", gw_variable[v].gv_name);
      if (wh_4 == 0) 
      {
        strcpy(field1a, gw_variable[v].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #140");
    trace_rec_3();
  }

  strcpy(a_string, "STRLEN   DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #141");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370LNK");
  strcpy(wk_remark, " addr C370LNK */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #142");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field1a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, "STRLEN cname */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #143");
    trace_rec_3();
  }

  strcpy(a_string, "         ST    R9,0(R8)");
  strcpy(wk_remark, " store ret */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #144");
    trace_rec_3();
  }

  strcpy(a_string, "SZ10     DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #145");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #146");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #147");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #148");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   SZ199");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #149");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #150");
    trace_rec_3();
  }
  work_use_ct[47]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #151");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #152");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #153");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(7,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #154");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #155");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         IC    R0,0(R9,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #156");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #157");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #158");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #159");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R8,C370PER");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #160");
    trace_rec_3();
  }
  work_use_ct[61]++;

  strcpy(a_string, "         CLC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #161");
    trace_rec_3();
  }

  strcpy(a_string, "         JE    ");
  strcat(a_string, "SZ199");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #162");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #163");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_strlen.c #164");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #165");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   SZ10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #166");
    trace_rec_3();
  }

  strcpy(a_string, "SZ199");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #167");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #168");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_strlen.c #169");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #170");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #171");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #172");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #173");
    trace_rec_3();
  }

  strcpy(a_string, "         BR    C370LNK");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c #174");
    trace_rec_3();
  }
}

void c2_strlen_pass2() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strlen.c c2_strlen_pass2");
    trace_rec_1();
  }

  char ch, *p1;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3b[VAR_LGTH];

  int pi;
  int pi2;
  int strl_1 = 0;
  int strl_3 = 0;
  int x3 = 0;
  int x99 = 0;
  int I = 0;
  int s = 0;
  int s1 = 0;
  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
  int end_of_string = 0;
  int array_found = 0;

  pi = 0;
  ch = p_string[pi];
  check_blank();

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
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  strl_3 = 0;
  if (lv_ct > 0) 
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        strl_3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }
  }

  if (strl_3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        strl_1 = strcmp(tfield1, gw_variable[I].gv_name);
        if (strl_1 == 0) 
        {
          strl_3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }
  }

  if (strl_3 == 0) 
  {
    printf("\nc2z_pass_2.c c2_strlen strlen-007 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_pass_2.c c2_strlen rct = %d p_string = %s\n",rct,p_string);
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
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield2[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield2, lw_variable[I].lv_name);
    ret2 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret2 == 0)) 
    {
      x3 = 1;
      strcpy(tfield2a, lw_variable[I].lv_cname);
      ret2 = strcmp("A", lw_variable[I].lv_type);
      if (ret2 == 0) 
      {
        array_found = 1;
      }
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
        ret2 = strcmp("A", gw_variable[I].gv_type);
        if (ret2 == 0) 
        {
          array_found = 1;
        }
      }
    }
  }


  if (x3 == 0) 
  {
    printf("\nc2z_pass_2.c c2_strlen strlen-008 tfield2 Not Found = %s\n", tfield2);
    printf("c2z_pass_2.c c2_strlen rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }


  if (array_found == 0) 
  {
    tot_sizeof++;
    x3 = 0;
    s = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        s = lw_variable[I].lv_lgth;
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
          s = gw_variable[I].gv_lgth;
        }
      }
    }


    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_strlen strlen-009 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_pass_2.c c2_strlen rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }


    snprintf(wk_strg, sizeof(wk_strg), "%d", s);
    strcpy(tfield2, wk_strg);

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

  if (array_found == 1) 
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

    pi = 0;
    ch = p_string[pi];
    check_blank();

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
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    strl_3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++)
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strl_3 = 1;
          strcpy(tfield1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (strl_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          strl_1 = strcmp(tfield1, gw_variable[I].gv_name);
          if (strl_1 == 0) 
          {
            strl_3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (strl_3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_strlen strlen-010 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_pass_2.c c2_strlen rct = %d p_string = %s\n",rct,p_string);
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
        tfield2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield2[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret2 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret2 == 0)) 
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
      printf("\nc2z_pass_2.c c2_strlen strlen-011 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_pass_2.c c2_strlen rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      /* tfield3[pi2] = ch; */
      pi++;
      pi2++;
      ch = p_string[pi];
    }
    /* tfield3[pi2] = '\0'; */

    convert = 1;
  }
}
