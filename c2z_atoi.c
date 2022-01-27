/* ***************************************************
*  c2z : c2z_atoi.c :                                *
*                                                    *
*  next error - atoi-006                             *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out atoi                                    *
* ************************************************** */
void c2_atoi(void) 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_atoi.c c2_atoi rct = %d START\n", rct);
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.atoi.c c2_atoi START");
    trace_rec_1();
  }

  int pi;
  int pi2;
  int x2;
  int x3 = 0;
  int x9 = 0;
  int x30 = 0;
  int x31 = 0;
  int I = 0;
  int s = 0;
  int ret = 0;
  int ret1 = 0;
  int fd2_type = 0;
  int fd3_type = 0;
  int fd4_type = 0;

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
  char ar_field12[VAR_LGTH];

  use_atoi++;

  x30 = 0;

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

/* ***************************************************************
 *      x30 [		x31 ]					         *
 *       0		 0		x = atoi(abc)                 *
 *	  1		 1		array1[x] = atoi(abc)         *
 *       2            2            spreadsheet[x][y] = atoi(abc) *
 * ************************************************************* */

/*
printf("\nc2z_atoi.c rct = %d p_string = %s",rct,p_string);
printf("c2z_atoi.c x30 = %d x31 = %d\n",x30,x31);
*/

  if((x30 == 1) && (x31 == 1))
  {
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

    x2 = 0;
    fd3_type = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
     if(x2 == 0) 
      {
        if(isdigit(ch)) 
        {
   	   fd3_type = 2;
          x2 = 1;
        }
        if(isalpha(ch)) 
        {
	   fd3_type = 1;
          x2 = 1;
        }
      }

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
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-003 field1 Not Found = %s\n", field1);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
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
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_atoi.c c2_atoi atoi-004 field2 Not Found = %s\n", field2);
        printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
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
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-005 field3 Not Found = %s\n", field3);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #1");
      trace_rec_3();
    }
    work_use_ct[9]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #2");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #3");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   1(7,R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #5");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #6");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #7");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   1(7,R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #8");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #9");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #10");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #11");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #12");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #13");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         LARL  R7,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #14");
      trace_rec_3();
    }
    work_use_ct[74]++;

    /* x9 = 0; */
    strcpy(a_string, "         CLC   0(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #15");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #16");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #17");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #18");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   1(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #19");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #20");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   1(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #21");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #22");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   2(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #23");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #24");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   2(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #25");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #26");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   3(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #27");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #28");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   3(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #29");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #30");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   4(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #31");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_ato1.c #32");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   4(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #33");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #34");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   5(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #35");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #36");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   5(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #37");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #38");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   6(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #39");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #40");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   6(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #41");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #42");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   7(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #43");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "X");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #43a");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   7(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #44");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "X");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #45");
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
      strcpy(trace_1, "c2z_atoi.c #46");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #47");
      trace_rec_3();
    }
    work_use_ct[9]++;

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1)
    {
      strcpy(trace_1, "c2z_atoi.c #48");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   7(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #49");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #50");
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
      strcpy(trace_1, "c2z_atoi.c #51");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #52");
      trace_rec_3();
    }
    work_use_ct[9]++;

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #53");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   6(2,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #54");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #55");
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
      strcpy(trace_1, "c2z_atoi.c #56");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #57");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #58");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   5(3,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #59");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #60");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #61");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #62");
      trace_rec_3();
    }
    work_use_ct[9]++;

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #63");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   4(4,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #64");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #65");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #66");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #67");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #68");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   3(5,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #69");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #70");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #71");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #72");
      trace_rec_3();
    }
    work_use_ct[9]++;

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #73");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   2(6,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #74");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #75");
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
      strcpy(trace_1, "c2z_atoi.c #76");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #77");
      trace_rec_3();
    }
    work_use_ct[9]++;

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #78");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   1(7,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #79");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #80");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "X");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #81");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #82");
      trace_rec_3();
    }
    work_use_ct[9]++;

    strcpy(a_string, "         LARL  R8,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #83");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         MVC   0(8,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #84");
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
      strcpy(trace_1, "c2z_atoi.c #85");
      trace_rec_3();
    }

  if(strcmp(ar_field12, "G") == 0)
  {
      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #86");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #87");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #88");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, ar_field7);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #89");
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
        strcpy(trace_1, "c2z_atoi.c #90");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #91");
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
          strcpy(trace_1, "c2z_atoi.c #92");
          trace_rec_3();
        }
        work_use_ct[50]++;
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
          strcpy(trace_1, "c2z_atoi.c #92a");
          trace_rec_3();
        }
      
        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atoi.c #92b");
          trace_rec_3();
        }

        strcpy(a_string, "         CVD   R5,0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atoi.c #92c");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atoi.c #92d");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atoi.c #92e");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R7),0(8,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atoi.c #92f");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_atoi.c #92g");
          trace_rec_3();
        }
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #93");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "BB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #94");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #95");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #96");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #97");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, ar_field6);
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #98");
        trace_rec_3();
      }
 
      strcpy(a_string, "         JLU   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "AA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #99");
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
        strcpy(trace_1, "c2z_atoi.c #100");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370L8");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #101");
        trace_rec_3();
      }
      work_use_ct[8]++;

      snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
      strcpy(a_string, "         PACK  0(6,R6),0(7,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_atoi.c #102");
        trace_rec_3();
      }

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
      strcpy(trace_1, "c2z_atoi.c #103");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #104");
      trace_rec_3();
    }
    work_use_ct[8]++;

    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcpy(a_string, "         PACK  0(6,R9),0(7,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #105");
      trace_rec_3();
    }

    convert = 1;
    return;
  }


  if((x30 == 0) && (x31 == 0))		/* x = atoi(abc) */
  {
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
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-001 field1 Not Found = %s\n", field1);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
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
        x9 = lw_variable[I].lv_lgth;
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
        }
      }
    }

    pi2 = 0;
    pi = 0;
    ch = field2[pi];

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-002 field2 Not Found = %s\n", field2);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
   
    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #110");
      trace_rec_3();
    }
    work_use_ct[9]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #111");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #112");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   1(7,R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #113");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #114");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #115");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #116");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   1(7,R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #117");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #118");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #119");
      trace_rec_3();
    }

 /*   if(x9 > 8)
    {
      x9 = 8;
    } */

    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #120");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #121");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #122");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         LARL  R7,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #123");
      trace_rec_3();
    }
    work_use_ct[74]++;

  /*  x9 = 0; */
    strcpy(a_string, "         CLC   0(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #124");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #125");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #126");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #127");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   1(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #128");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #129");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   1(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #130");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #131");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   2(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #132");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #133");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   2(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #134");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #135");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   3(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #136");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #137");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   3(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #138");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #139");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   4(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #140");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_ato1.c #141");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   4(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #142");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #143");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   5(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #144");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #145");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   5(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #146");
      trace_rec_3();
    }

  strcpy(a_string, "         JLE   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "F");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #147");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   6(1,R9),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #148");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "G");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #149");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   6(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #150");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "G");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #151");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   7(1,R9),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #152");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "X");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #153");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   7(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #154");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "X");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #155");
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
    strcpy(trace_1, "c2z_atoi.c #156");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #157");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_atoi.c #158");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   7(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #159");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #160");
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
    strcpy(trace_1, "c2z_atoi.c #161");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #162");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #163");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   6(2,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #164");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #165");
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
    strcpy(trace_1, "c2z_atoi.c #166");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #167");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #168");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   5(3,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #169");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #170");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "D");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #171");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #172");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #173");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   4(4,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #174");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #175");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #176");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #177");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #178");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   3(5,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #179");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #180");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "F");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #181");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #182");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #183");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   2(6,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #184");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #185");
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
    strcpy(trace_1, "c2z_atoi.c #186");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #187");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #188");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   1(7,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #189");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #190");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "X");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #191");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #192");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #193");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   0(8,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #194");
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
    strcpy(trace_1, "c2z_atoi.c #195");
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
      strcpy(trace_1, "c2z_atoi.c #196");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #197");
      trace_rec_3();
    }
    work_use_ct[9]++;

    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcpy(a_string, "         PACK  0(6,R9),0(7,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #198");
      trace_rec_3();
    }
    convert = 1;
    return;
  }
  

  if((x30 == 2) && (x31 == 2))		/* spreadsheet[x][y] = atoi(abc) */
  {
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
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-001 field1 Not Found = %s\n", field1);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x2 = 0;
    pi2 = 0;
    fd2_type = 0;
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
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-002 field2 Not Found = %s\n", field2);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x2 = 0;
    pi2 = 0;
    fd3_type = 0;
    pi++;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if(x2 == 0) 
      {
        if(isdigit(ch)) 
        {
   	   fd3_type = 2;
          x2 = 1;
        }
        if(isalpha(ch)) 
        {
	   fd3_type = 1;
          x2 = 1;
        }
      }
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
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-303 field3 Not Found = %s\n", field3);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    while(ch != '(')
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    fd4_type = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if(x2 == 0) 
      {
        if(isdigit(ch)) 
        {
   	   fd4_type = 2;
          x2 = 1;
        }
        if(isalpha(ch)) 
        {
	   fd4_type = 1;
          x2 = 1;
        }
      }
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
        x9 = lw_variable[I].lv_lgth;
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
          x9 = gw_variable[I].gv_lgth;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_atoi.c c2_atoi atoi-304 field4 Not Found = %s\n", field4);
      printf("c2z_atoi.c c2_atoi rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #300");
      trace_rec_3();
    }
    work_use_ct[9]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #301");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #302");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   1(7,R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #303");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #304");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #305");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #306");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   1(7,R9),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #307");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #308");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #309");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #310");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L8A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #311");
      trace_rec_3();
    }
    work_use_ct[8]++;

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #312");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         LARL  R7,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #313");
      trace_rec_3();
    }
    work_use_ct[74]++;

  /*  x9 = 0; */
    strcpy(a_string, "         CLC   0(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #314");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #315");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #316");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #317");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   1(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #318");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #319");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   1(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #320");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #321");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   2(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #322");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #323");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   2(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #324");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #325");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   3(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #326");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #327");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   3(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #328");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #329");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   4(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #330");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_ato1.c #331");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   4(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #332");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #333");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   5(1,R9),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #334");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #335");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   5(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #336");
      trace_rec_3();
    }

  strcpy(a_string, "         JLE   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "F");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #337");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   6(1,R9),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #338");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "G");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #339");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   6(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #340");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "G");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #341");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   7(1,R9),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #342");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "X");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #343");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   7(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #344");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "X");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #345");
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
    strcpy(trace_1, "c2z_atoi.c #346");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #347");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1)
  {
    strcpy(trace_1, "c2z_atoi.c #348");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   7(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #349");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #350");
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
    strcpy(trace_1, "c2z_atoi.c #351");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #352");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #353");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   6(2,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #354");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #355");
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
    strcpy(trace_1, "c2z_atoi.c #356");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #357");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #358");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   5(3,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #359");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #360");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "D");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #361");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #362");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #363");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   4(4,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #364");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #365");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #366");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #367");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #368");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   3(5,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #369");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #370");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "F");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #371");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #372");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #373");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   2(6,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #374");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #375");
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
    strcpy(trace_1, "c2z_atoi.c #376");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #377");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #378");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   1(7,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #379");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #380");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "X");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #381");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L8");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #382");
    trace_rec_3();
  }
  work_use_ct[9]++;

  strcpy(a_string, "         LARL  R8,C370L8A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #383");
    trace_rec_3();
  }
  work_use_ct[8]++;

  strcpy(a_string, "         MVC   0(8,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #384");
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
    strcpy(trace_1, "c2z_atoi.c #385");
    trace_rec_3();
  }

     strcpy(a_string, "*         LARL  R9,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #386");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #387");
      trace_rec_3();
    }
    work_use_ct[95]++;

    strcpy(a_string, "         LARL  R8,C370L8");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #387");
      trace_rec_3();
    }
    work_use_ct[9]++;

    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcpy(a_string, "         PACK  0(6,R9),0(7,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #388");
      trace_rec_3();
    }

    strcpy(a_string, "* now find index value *");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #389");
      trace_rec_3();
    }

/*  find displacement in array  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #390");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #391");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #392");
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
      strcpy(trace_1, "c2z_atoi.c #393");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #394");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #395");
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
      strcpy(trace_1, "c2z_atoi.c #396");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #397");
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
      strcpy(trace_1, "c2z_atoi.c #398");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #399");
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
      strcpy(trace_1, "c2z_atoi.c #400");
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
      strcpy(trace_1, "c2z_atoi.c #401");
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
      strcpy(trace_1, "c2z_atoi.c #402");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R5,26");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #403");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #404");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #405");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #406");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #407");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #408");
      trace_rec_3();
    }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #409");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #410");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #411");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #412");
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
      strcpy(trace_1, "c2z_atoi.c #413");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #414");
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
      strcpy(trace_1, "c2z_atoi.c #415");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #416");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #417");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #418");
      trace_rec_3();
    }


    if (gv_ct > 0) 
    {
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(field1, gw_variable[I].gv_name);
         if (ret == 0) 
         {
           x2 = 1;
           strcpy(field1a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
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

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #419");
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
      strcpy(trace_1, "c2z_atoi.c #420");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #421");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #422");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #423");
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
      strcpy(trace_1, "c2z_atoi.c #424");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #425");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #426");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_atoi.c #427");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #428");
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
    strcpy(trace_1, "c2z_atoi.c #429");
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
    strcpy(trace_1, "c2z_atoi.c #430");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #431");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         ZAP   ");
  strcat(a_string, "0(6,R6),");
  strcat(a_string, "0(6,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_atoi.c #432");
    trace_rec_3();
  }

  }
  convert = 1;
  return;

}

