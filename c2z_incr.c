/* ***************************************************
*  c2z : c2z_incr.c :                                *
*                                                    *
*  next error - incr-002                             *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch ++ statement                                *
* ************************************************** */
void c2_plus() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.incr.c plus #1 START");
    trace_rec_1();
  }

  /* pgm_label(); */

  char *p, *p1, *p2, *p3;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];

  char tfield1[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield8[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield11[VAR_LGTH];

  int pi;
  int pi2;
  int pl1 = 0;
  int pl3 = 0;
  int I = 0;
  int x2 = 0;
  int fd2_type = 0;
  int ret = 0;
  int ret1 = 0;

  p = strstr(p_string, "++");
  p1 = strstr(p_string, "printf");
  p2 = strstr(p_string, "[");
  p3 = strstr(p_string, "]");
  if ((p) && (!p1) && (!p2) && (!p3)) 
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != '+') 
    {
      if(ch != ' ')
      {
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    pl1 = 0;
    pl3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          pl1 = 1;
          strcpy(field1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          lw_variable[I].lv_current_lgth++;
        }
      }
    }

    if (pl1 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          pl3 = strcmp(field1, gw_variable[I].gv_name);
          if (pl3 == 0) 
          {
            pl1 = 1;
            strcpy(field1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            gw_variable[I].gv_current_lgth++;
          }
        }
      }
    }

    if (pl1 == 0) 
    {
      printf("\nc2z_incr.c c2_plus incr-001 field1 Not Found = %s sv_func = %s\n", field1,sv_func);
      printf("c2z_incr.c c2_plus rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_incr.c #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #2");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #3");
      trace_rec_3();
    }
    convert = 1;
    return;
  }

  if ((p) && (!p1) && (p2) && (p3)) /*  int array[x]++;	*/
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if(ch != ' ')
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    fd2_type = 0;
    pi++;
    pi2 = 0;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if (x2 == 0) 
      {
        if ((isdigit(ch)) && (x2 == 0)) 
        {
          fd2_type = 2;
          x2 = 1;
        }
        if ((isalpha(ch)) && (x2 == 0)) 
        {
          fd2_type = 1;
          x2 = 1;
        }
      }
      pi2++;
      pi++;
      ch = p_string[pi];
    }

    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(tfield5, gw_variable[I].gv_dsect);
          strcpy(tfield6, gw_variable[I].gv_label);
          strcpy(tfield7, gw_variable[I].gv_table);
          strcpy(tfield8, gw_variable[I].gv_aname);
          strcpy(tfield9, gw_variable[I].gv_sv_reg);
          strcpy(tfield10, gw_variable[I].gv_wk_reg);
          strcpy(tfield11, gw_variable[I].gv_wk_strg);
        }
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr_c #4");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #7");
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
      strcpy(trace_1, "c2z_incr.c #8");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #9");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if (fd2_type == 2) 			/* literal  */
    {
/*
      for (v = 0; v < math_lit_ct; v++) 
      {
        if ((rct == w_mathlit[v].lit_rct) && (w_mathlit[v].lit_uct == 1)) 
        {
          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, w_mathlit[v].lit_use_cname);
          break;
        }
      }
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #10");
        trace_rec_3();
      }
*/

printf("FIX FIX FIX c2_plus_array #7\n");
printf("rct = %d p_string = %s",rct,p_string);

    }

    if (fd2_type == 1) 			/* variable */
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #11");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #12");
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
      strcpy(trace_1, "c2z_incr.c #13");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #14");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #15");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #16");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #17");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #18");
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
      strcpy(trace_1, "c2z_incr.c #19");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #20");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         AP    0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #21");
      trace_rec_3();
    }
    convert = 1;
    return;
  }
}
