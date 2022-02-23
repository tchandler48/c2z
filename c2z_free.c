/* ***************************************************
*  c2z : c2z_free.c :                                *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out FREE                                    *
* ************************************************** */
void c2_free() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_free.c c2_free START");
  }

  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
  int pi;
  int pi2;
  int fr_1 = 0;
  int fr_2 = 0;
  int fr_3 = 0;
  int x1 = 0;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;

  char ch, *p;
  char field1a[VAR_LGTH];
  char field11a[VAR_LGTH];

  char fr_type[2];
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield11a[VAR_LGTH];
  char tfield4a[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];

  int I = 0;
  int v = 0;
  int xr = 0;
  int x80 = 0;
  int x81 = 0;

  free_loop++;

  p = strstr(p_string, "[");

  if (!p) 
  {
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
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    fr_3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          fr_3 = 1;
          strcpy(tfield1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          strcpy(fr_type, lw_variable[I].lv_type);
          x2 = lw_variable[I].lv_lgth;
        }
      }
    }

    if (fr_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            fr_3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            strcpy(fr_type, gw_variable[I].gv_type);
            xr = gw_variable[I].gv_row;
            x2 = gw_variable[I].gv_lgth;
          }
        }
      }
    }

    if (fr_3 == 0) 
    {
      for (I = 0; I < m_struc_ct; I++) 
      {
        ret = strcmp(tfield1, w_struc[I].st_name);
        if (ret == 0) 
        {
          fr_3 = 1;
          fr_1 = 6;
          strcpy(fr_type,"M");
          strcpy(tfield1a, w_struc[I].st_cname);
          break;
        }
      }
    }

    if (fr_3 == 0) 
    {
      printf("\nc2z_free.c c2_free free-003 tfield1 Not Found %s\n", tfield1);
      printf("c2z_free.c c2_free rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    fr_2 = strcmp(fr_type, "C");
    if (fr_2 == 0) 
    {
      fr_1 = 1;
    }

    fr_2 = strcmp(fr_type, "I");
    if (fr_2 == 0) 
    {
      fr_1 = 2;
    }

    fr_2 = strcmp(fr_type, "A");
    if (fr_2 == 0) 
    {
      fr_1 = 3;
    }

    fr_2 = strcmp(fr_type, "G");
    if (fr_2 == 0) 
    {
      fr_1 = 4;
    }

    fr_2 = strcmp(fr_type, "D");
    if (fr_2 == 0) 
    {
      fr_1 = 5;
      printf("c2_free type  not coded\n");
    }

    fr_2 = strcmp(fr_type, "M");
    if (fr_2 == 0) 
    {
      fr_1 = 6;
    }

    if (fr_1 == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #1");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370B1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #2");
        trace_rec_3();
      }
      work_use_ct[52]++;

      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #3");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #4");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #5");
        trace_rec_3();
      }
      work_use_ct[74]++;

      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #6");
        trace_rec_3();
      }
    }

    if (fr_1 == 2) 				/* integer clear	*/
    {
      strcpy(a_string, "*         LARL  R9,");
      strcat(a_string, tfield1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #7");
        trace_rec_3();
      }

      strcpy(a_string, "*         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #8");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "*         ZAP   0(6,R9),0(6,R8)");
      strcpy(wk_remark, " free    */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #9");
        trace_rec_3();
      }
    }

    if (fr_1 == 3) 				/* Array A clear	*/
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_free.c c2_free array-char");
        trace_rec_1();
      }

      fr_3 = 0;
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            fr_3 = 1;
            strcpy(field1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            strcpy(ar_field5, gw_variable[I].gv_dsect);
            strcpy(ar_field6, gw_variable[I].gv_label);
            strcpy(ar_field7, gw_variable[I].gv_table);
            strcpy(ar_field8, gw_variable[I].gv_aname);
            strcpy(ar_field9, gw_variable[I].gv_sv_reg);
            strcpy(ar_field10, gw_variable[I].gv_wk_reg);
            strcpy(ar_field11, gw_variable[I].gv_wk_strg);
            x1 = gw_variable[I].gv_row;
            x2 = gw_variable[I].gv_column;
            x3 = gw_variable[I].gv_lgth;
            break;
          }
        }
      }

      fr_3 = 0;
      fr_2 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(ar_field11, lw_variable[v].lv_name);
        if (ret == 0) 
        {
          fr_3 = 1;
          strcpy(tfield11a, lw_variable[v].lv_cname);
        }
      }

      if (fr_3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(ar_field11, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            fr_3 = 1;
            strcpy(tfield11a, gw_variable[v].gv_cname);
          }
        }
      }

      if (fr_3 == 0) 
      {
        printf("\nc2z_free.c c2_free free-004 ar_field11 Not Found = %s\n",ar_field11);
        printf("c2z_free.c c2_free rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "FR");
      snprintf(wk_strg, sizeof(wk_strg), "%d", free_loop);
      strcat(a_string, wk_strg);
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #10");
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
        strcpy(trace_1, "c2z_free.c #11");
        trace_rec_3();
      }

      x4 = x1 * x2;
      strcpy(a_string, "         LAEY  R5,");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #12");
        trace_rec_3();
      }

      strcpy(a_string, "FR");
      snprintf(wk_strg, sizeof(wk_strg), "%d", free_loop);
      strcat(a_string, wk_strg);
      strcat(a_string, "L");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #13");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370B1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #14");
        trace_rec_3();
      }
      work_use_ct[52]++;

      strcpy(a_string, "         MVC   0(1,R6),0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #15");
        trace_rec_3();
      }

      x2--;
      snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
      strcpy(a_string, "         MVC   1(");
      strcat(a_string, wk_strg);
      strcat(a_string, ",R6),0(R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #16");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #17");
        trace_rec_3();
      }
      work_use_ct[74]++;

      snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
      strcpy(a_string, "         MVC   ");
      strcat(a_string, "1(");
      strcat(a_string, wk_strg);
      strcat(a_string, ",R6),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #18");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, ar_field6);
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #19");
        trace_rec_3();
      }

      strcpy(a_string, "         JCT   R5,");
      strcat(a_string, "FR");
      snprintf(wk_strg, sizeof(wk_strg), "%d", free_loop);
      strcat(a_string, wk_strg);
      strcat(a_string, "L");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #20");
        trace_rec_3();
      }
    }

    if (fr_1 == 4) 					/* Array G clear	*/
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_free.c c2_free array_numeric");
        trace_rec_1();
      }

      fr_3 = 0;
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            fr_3 = 1;
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

      fr_3 = 0;
      fr_2 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(ar_field11, lw_variable[v].lv_name);
        if (ret == 0) 
        {
          fr_3 = 1;
          strcpy(field11a, lw_variable[v].lv_cname);
        }
      }

      if (fr_3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(ar_field11, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            fr_3 = 1;
            strcpy(field11a, gw_variable[v].gv_cname);
          }
        }
      }

      if (fr_3 == 0) 
      {
        printf("\nc2z_free.c c2_free free-005 ar_field11 Not Found %s\n", ar_field11);
        printf("c2z_free.c c2_free rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #21");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #22");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #23");
        trace_rec_3();
      }

      strcpy(a_string, "FR");
      snprintf(wk_strg, sizeof(wk_strg), "%d", free_loop);
      strcat(a_string, wk_strg);
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #24");
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
        strcpy(trace_1, "c2z_free.c #25");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R5,");
      snprintf(wk_strg, sizeof(wk_strg), "%d", xr);
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #26");
        trace_rec_3();
      }

      strcpy(a_string, "FR");
      snprintf(wk_strg, sizeof(wk_strg), "%d", free_loop);
      strcat(a_string, wk_strg);
      strcat(a_string, "L");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #27");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #28");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #29");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, ar_field6);
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #30");
        trace_rec_3();
      }

      strcpy(a_string, "         JCT   R5,");
      strcat(a_string, "FR");
      snprintf(wk_strg, sizeof(wk_strg), "%d", free_loop);
      strcat(a_string, wk_strg);
      strcat(a_string, "L");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #31");
        trace_rec_3();
      }

      strcpy(a_string, "*");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #32");
        trace_rec_3();
      }
    }

    if (fr_1 == 5) 					/* double clear	*/
    {
      printf("\nc2z_free c2_free free-006 double free Not Coded\n");
      printf("c2z_free.c c2_free rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fr_1 == 6) 					/* Structure		*/
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_free.c c2_free structure");
        trace_rec_1();
      }
      /* strcpy(tfield1a,tfield1); */
      
      strcpy(a_string, "         LARL  R6,");
      strcat(a_string, tfield1a);
      strcat(a_string, "T");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #33");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R5,25");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #34");
        trace_rec_3();
      }

      strcpy(a_string, "FR");
      snprintf(wk_strg, sizeof(wk_strg), "%d", free_loop);
      strcat(a_string, wk_strg);
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #35");
        trace_rec_3();
      }

      fr_3 = 0;
      for (I = 0; I < m_struc_ct; I++) 
      {
 
        ret = strcmp(tfield1, w_struc[I].st_wname);
        ret1 = strcmp(w_struc[I].st_id, "N"); 
        if ((ret == 0) && (ret1 == 0)) 
        {
          x80 = w_struc[I].st_disp;
          x81 = w_struc[I].st_field_lgth;
          strcpy(tfield4a, w_struc[I].st_cname);

          ret2 = strcmp(w_struc[I].st_type, "C");
          if (ret2 == 0) 
          {
            strcpy(a_string, "         LARL  R9,C370B1");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_free.c #36");
              trace_rec_3();
            }
            work_use_ct[52]++;

            snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
            strcpy(a_string, "         MVC   ");
            strcat(a_string, wk_strg);
            strcat(a_string, "(1,R6),0(R9)");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_free.c #37");
              trace_rec_3();
            }

            x80++;
            snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
            strcpy(a_string, "         MVC   ");
            strcat(a_string, wk_strg);
            strcat(a_string, "(");
            snprintf(wk_strg, sizeof(wk_strg), "%d", x81);
            strcat(a_string, wk_strg);
            x80--;
            strcat(a_string, ",R6),");
            snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
            strcat(a_string, wk_strg);
            strcat(a_string, "(R6)");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_free.c #38");
              trace_rec_3();
            }
          }

          ret2 = strcmp(w_struc[I].st_type, "I");
          if (ret2 == 0) 
          {
            strcpy(a_string, "         LARL  R9,C370ZERO");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_free.c #39");
              trace_rec_3();
            }

            snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
            strcpy(a_string, "         ZAP   ");
            strcat(a_string, wk_strg);
            strcat(a_string, "(6,R6),0(6,R9)");
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_free.c #40");
              trace_rec_3();
            }
          }
        }
      }

      strcat(tfield4a, "L");
      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, tfield1a);
      strcat(a_string, "L");
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #41");
        trace_rec_3();
      }

      strcpy(a_string, "         JCT   R5,");
      strcat(a_string, "FR");
      snprintf(wk_strg, sizeof(wk_strg), "%d", free_loop);
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_free.c #42");
        trace_rec_3();
      }
    }
    convert = 1;
    return;
  }

  if (p) 
  {
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
    while (ch != '[') 
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
    while (ch != ']') 
    {
      pi2++;
      pi++;
      ch = p_string[pi];
    }
 
    convert = 1;
  }
}
