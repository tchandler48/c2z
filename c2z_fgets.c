/* ***************************************************
*  c2z : c2z_fgets.c :                               *
*                                                    *
*  next error fgets-005                              *
*  Copyright TCCS (c) 2015 - 2026                    *
**************************************************** */

/* ***************************************************
*  Punch out FGETS                                   *
* ************************************************** */
void c2_fgets() 
{
  strcpy(trace_1, "c2z_fgets c2_fgets START");
  trace_rec_1();
  
  char ch;
  char *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
/*  char sv_while_tag[12]; */

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
  int x5 = 0;
  int x6 = 0;
  int size = 0;
  int fd2_type = 0;
  int ret1 = 0;

  p = strstr(p_string, "stdin");

  if(p)
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
    while (ch != ',') 
    {
      if (ch != ' ') 
      {
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x5 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x5 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        x6 = lw_variable[I].lv_lgth;
      }
    }

    if (x5 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x5 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
          x6 = gw_variable[I].gv_lgth;
        }
      }
    }

    if (x5 == 0) 
    {
      printf("\nc2z_fgets.c c2_fgets fgets-1003 field1 Not Found = %s\n", field1);
      printf("c2z_fgets.c c2_fgets rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch != ' ') 
      {
        field2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    x5 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x5 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        x6 = atoi(lw_variable[I].lv_value);
      }
    }

    if (x5 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x5 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          x6 = atoi(gw_variable[I].gv_value);
        }
      }
    }

    if (x5 == 0) 
    {
      printf("\nc2z_fgets.c c2_fgets fgets-1003 field2 Not Found = %s\n", field2);
      printf("c2z_fgets.c c2_fgets rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R11,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #5");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
    strcpy(a_string, "         LAEY  R10,");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOINP");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #7");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #8");
      trace_rec_3();
    }

/*
R1 = contains number of bytes read
*/
    strcpy(a_string, "         LR    R5,R1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #10");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #11");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #12");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #13");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #14");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #16");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #18");
      trace_rec_3();
    }

    strcpy(a_string, "         CVB   R2,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #18");
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
      strcpy(trace_1, "c2z_fgets.c c2_fgets #19");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R1,R9");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #20");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R1,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #20");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #21");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R9,R1),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_fgets.c c2_fgets #22");
      trace_rec_3();
    }

    convert = 1;
    return;
  }


  if(!p)
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
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field3);
    src_line();
    strcpy(trace_1, "c2z_fgets c2_fgets #101");
    trace_rec_3();
    
    strcpy(a_string, "         GET   (R9)");
    strcpy(wk_remark, " fgets    */");
    write_remark();
    strcpy(trace_1, "c2z_fgets c2_fgets #102");
    trace_rec_3();
    
    x4 = 0;
    for (I = 0; I < f_ct; I++) 
    {
      x4 = w_file[I].f_buf_ct;
      ret = strcmp(field3, w_file[I].f_name);
      if (ret == 0) 
      {
        strcpy(a_string, "         MVC2  ");
        strcat(a_string, field1a);
        strcat(a_string, ",");
        strcat(a_string, "C370PB");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
        strcat(a_string, wk_strg);
        src_line();
        strcpy(trace_1, "c2z_fgets c2_fgets #103");
        trace_rec_3();

        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        x4 = strlen(c_wkname);
        c_wkname[x4] = '\0';

        snprintf(wk_strg, sizeof(wk_strg), "%d", x6);
   
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
        strcpy(gw_variable[gv_ct].gv_dsect, null_field);
        strcpy(gw_variable[gv_ct].gv_label, null_field);
        strcpy(gw_variable[gv_ct].gv_aname, null_field);
        strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
        gw_variable[gv_ct].gv_dec = 0;
        gv_ct++;

/*
        strcpy(a_string, "         LARL  R3,");
        strcat(a_string, field1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " ");
        write_remark();
        strcpy(trace_1, "c2z_fgets c2_fgets #104");
        trace_rec_3();
      
        strcpy(a_string, "         LHI   R4,L'");
        strcat(a_string, field1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " ");
        write_remark();
        strcpy(trace_1, "c2z_fgets c2_fgets #105");
        trace_rec_3();

        strcpy(a_string, "         AR    R3,R4");
        src_line();
        strcpy(trace_1, "c2z_fgets c2_fgets #106");
        trace_rec_3();

        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "A");
        check_length();
        strcat(a_string, "BCTR  R3,0");
        src_line();
        strcpy(trace_1, "c2z_fgets c2_fgets #107");
        trace_rec_3();

        strcpy(a_string, "         CLI   0(R3),X'40'");
        src_line();
        strcpy(trace_1, "c2z_fgets c2_fgets #108");
        trace_rec_3();

        strcpy(a_string, "         JE    L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "Z");
        src_line();
        strcpy(trace_1, "c2z_fgets c2_fgets #109");
        trace_rec_3();

        if(wh_ct_1 == 0)
        {
          strcpy(wh_lb_1, "L");
          strcat(wh_lb_1, wk_strg);
          strcat(wh_lb_1, "Z");
          strcpy(start_lb_1,while_tag);
          wh_ct_1 = 1;
          goto fg_end4;
        }

      if(wh_ct_2 == 0)
      {
        strcpy(wh_lb_2, "L");
        strcat(wh_lb_2, wk_strg);
        strcat(wh_lb_2, "Z");
        strcpy(start_lb_2,while_tag);
        wh_ct_2 = 1;
        goto fg_end4;
      }

      if(wh_ct_3 == 0)
      {
        strcpy(wh_lb_3, "L");
        strcat(wh_lb_3, wk_strg);
        strcat(wh_lb_3, "Z");
        strcpy(start_lb_3,while_tag);
        wh_ct_3 = 1;
        goto fg_end4;
      }

      if(wh_ct_4 == 0)
      {
        strcpy(wh_lb_4, "L");
        strcat(wh_lb_4, wk_strg);
        strcat(wh_lb_4, "Z");
        strcpy(start_lb_4,while_tag);
        wh_ct_4 = 1;
        goto fg_end4;
      }

      if(wh_ct_5 == 0)
      {
        strcpy(wh_lb_5, "L");
        strcat(wh_lb_5, wk_strg);
        strcat(wh_lb_5, "Z");
        strcpy(start_lb_2,while_tag);
        wh_ct_5 = 1;
        goto fg_end4;
      }

fg_end4:

        strcpy(a_string, "         LARL  R6,L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "A");
        src_line();
        strcpy(trace_1, "c2z_fgets c2_fgets #110");
        trace_rec_3();

        strcpy(a_string, "         BCT   R4,0(,R6)");
        src_line();
        strcpy(trace_1, "c2z_fgets c2_fgets #110");
        trace_rec_3();

        strcpy(a_string, "         XR    R3,R3");
        src_line();
        strcpy(trace_1, "c2z_fgets c2_fgets #111");
        trace_rec_3();
*/
      }
    }
  }

  convert = 1;
  return;
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
  char *p;
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

  p = strstr(p_string, "stdin");

  if(p)
  {
    convert = 1;
    return;
  }
  
  if(!p)
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
}
