/* ***************************************************
*  c2z  : c2z_char.c :                               *
*                                                    *
*  next error - char-004                             *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Scan test for CHAR                                *
* ************************************************** */
void c2_char() 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_char.c c2_char rct = %d START", rct);
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_char.c #1 ");
    trace_rec_1();
  }

  tot_char++;

  int convert = 0;
  int pi;
  int pi2;
  int I;
  int II = 0;
  int u1 = 0;
  int x = 0;
  int x100;
  
  int y0 = 0;
  int y1 = 0;
  int y2 = 0;
  int op_2 = 0;
  int op_3 = 0;
  int op_4 = 0;
  int op_5 = 0;
  int op_6 = 0;
  int op_7 = 0;
  int op_8 = 0;
  int op_9 = 0;
  int s = 0;
  int v = 0;

  op_2 = 1;

  char ch;
  char *p3, *p4, *p6, *p7, *p8, *p9, *p10;
  char field1[VAR_LGTH];

  char wk_fd1[VAR_LGTH];
  char wk_fd2[VAR_LGTH];
  char wk_fd3[VAR_LGTH];
  char wk_fd4[VAR_LGTH];
  char wk_fd5[VAR_LGTH];
  char wk_fd6[VAR_LGTH];
  char wk_fd7[VAR_LGTH];
  char wk_fd8[VAR_LGTH];
  char wk_fd9[VAR_LGTH];
  char wk_fd10[VAR_LGTH];

  wk_fd1[0] = '\0';
  wk_fd2[0] = '\0';
  wk_fd3[0] = '\0';
  wk_fd4[0] = '\0';
  wk_fd5[0] = '\0';
  wk_fd6[0] = '\0';
  wk_fd7[0] = '\0';
  wk_fd8[0] = '\0';
  wk_fd9[0] = '\0';
  wk_fd10[0] = '\0';
  wk_fdwk[0] = '\0';

  p9 = strstr(p_string, "(");
  p10 = strstr(p_string, ")");

  p8 = strstr(p_string, "(");
  s = p8 - p_string;
  p8 = strstr(p_string, ";");
  v = p8 - p_string;
  if (v < 0) 
  {
    v = 9999;
  }

  if ((p9) && (p10) && (s < v))
  {
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
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  p3 = strstr(field1, "static");
  if (p3) 
  {
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  field1[pi2] = '\0';

  op_code = 0;
  p8 = strstr(field1, "char");

  if ((p8) && (op_code != 1)) 
  {
    op_code = 2;
  }
  /* ***********************************
  *  op_code                           *
  *	1	= 	VOID              *
  *	2	=	CHAR              *
  * ********************************** */
  if (op_code == 2) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_char.c c2_char CHAR #2");
      trace_rec_1();
    }

    x100 = 0;
    s = strlen(p_string);
    for(I = 0; I < s; I++)
    {
      if(p_string[I] == '[')
      {
        x100++;
      }
      if(p_string[I] == ']')
      {
        x100++;
      }
    }

    if(x100 == 6)	/* char xyz[ ][ ][ ]  */
    {
      c2_char_41();
      convert = 1;
      return;
    }

    pi2 = 0;
    x = 0;
    while ((ch != ';') && (x == 0)) 
    {
      while ((ch != ',') && (x == 0)) 
      {
        if (ch == ';') 
        {
          x = 1;
        } 
        else 
        {
          if (ch != ' ') 
          {
            wk_fdwk[pi2] = ch;
            pi2++;
          }
          pi++;
          ch = p_string[pi];
        }
      }

      wk_fdwk[pi2] = '\0';

      if (u1 == 0) 
      {
        strcpy(wk_fd1, wk_fdwk);
      }

      if (u1 == 1) 
      {
        strcpy(wk_fd2, wk_fdwk);
      }

      if (u1 == 2) 
      {
        strcpy(wk_fd3, wk_fdwk);
      }

      if (u1 == 3) 
      {
        strcpy(wk_fd4, wk_fdwk);
      }

      if (u1 == 4) 
      {
        strcpy(wk_fd5, wk_fdwk);
      }

      if (u1 == 5) 
      {
        strcpy(wk_fd6, wk_fdwk);
      }

      if (u1 == 6) 
      {
        strcpy(wk_fd7, wk_fdwk);
      }

      if (u1 == 7) 
      {
        strcpy(wk_fd8, wk_fdwk);
      }

      if (u1 == 8) 
      {
        strcpy(wk_fd9, wk_fdwk);
      }
  
      if (u1 == 9) 
      {
        strcpy(wk_fd10, wk_fdwk);
      }

      u1++;
      if (x == 0) 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
    }

    for (II = 0; II < u1; II++) 
    {
      if (II == 0) 
      {
        strcpy(wk_fdwk, wk_fd1);
      }

      if (II == 1) 
      {
        strcpy(wk_fdwk, wk_fd2);
      }

      if (II == 2) 
      {
        strcpy(wk_fdwk, wk_fd3);
      }

      if (II == 3) 
      {
        strcpy(wk_fdwk, wk_fd4);
      }

      if (II == 4) 
      {
        strcpy(wk_fdwk, wk_fd5);
      }

      if (II == 5) 
      {
        strcpy(wk_fdwk, wk_fd6);
      }

      if (II == 6) 
      {
        strcpy(wk_fdwk, wk_fd7);
      }

      if (II == 7) 
      {
        strcpy(wk_fdwk, wk_fd8);
      }

      if (II == 8) 
      {
        strcpy(wk_fdwk, wk_fd9);
      }

      if (II == 9) 
      {
        strcpy(wk_fdwk, wk_fd10);
      }

      op_3 = 0;
      op_4 = 0;
      op_5 = 0;
      op_6 = 0;
      op_7 = 0;
      op_8 = 0;
      op_9 = 0;

      p3 = strstr(wk_fdwk, ",");
      if (p3) 
      {
        op_3 = 1;
      }

      p4 = strstr(wk_fdwk, "=");
      if (p4) 
      {
        op_4 = 1;
      }

      y2 = 0;
      y0 = strlen(wk_fdwk);
      for (y1 = 0; y1 < y0; y1++) 
      {
        ch = wk_fdwk[y1];
        if (ch == '[')
        {
          y2++;
        }

        if (ch == ']')
        {
          y2++;
        }
      }

      if (y2 == 2) 
      {
        op_5 = 1;
      }

      if (y2 == 4) 
      {
        op_9 = 1;
      }

      p6 = strstr(wk_fdwk, "**");
      if (p6) 
      {
        op_6 = 1;
      }

      p7 = strstr(wk_fdwk, "*");
      if ((p7) && (!p6)) 
      {
        op_7 = 1;
      }

      p8 = strstr(wk_fdwk, "void");
      if (p8) 
      {
        op_8 = 1;
      }

      if ((op_2 == 1) && (op_3 == 0) && (op_4 == 1) && (op_5 == 0) && (op_6 == 0) && (op_7 == 0) && (op_8 == 0) && (convert == 0)) 
      {
        c2_char_1();
      }

      if ((convert == 0) && (op_5 == 1) && (op_8 == 0) && (convert == 0)) 
      {
        c2_char_1();
      }

      if ((op_2 == 1) && (op_3 == 0) && (op_4 == 0) && (op_5 == 0) && (op_6 == 0) && (op_7 == 0) && (op_8 == 0) && (op_9 == 0) && (convert == 0)) 
      {
        c2_char_2();
      }

      if ((op_2 == 1) && (op_6 == 1) && (op_8 == 0) && (convert == 0)) 
      {
        c2_char_3();
      }

      if ((op_2 == 1) && (op_7 == 1) && (op_8 == 0) && (convert == 0)) 
      {
        c2_char_4();
      }

      if ((op_2 == 1) && (op_5 == 1) && (op_7 == 1) && (op_8 == 1) && (convert == 0)) 
      {
        c2_char_5();
      }

      if ((op_2 == 1) && (op_3 == 1) && (op_5 == 1) && (convert == 0)) 
      {
        c2_char_6();
      }

      if ((op_9 == 1) && (convert == 0)) 			/* char in_stack[max_var][var_name];	*/
      {
        c2_char_9();
      }
    }
  }

  convert = 1;
}

/* ******************************
*  char xstring[10];            *
*  char pstring[BUFSIZE]        *
* ***************************** */
void c2_char_1() 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_char.c c2_char_1 rct = %d START", rct);
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_char.c c2_char_1 START");
    trace_rec_1();
  }

  int fd1_type = 0;
  int fd2_type = 0;
  int pi;
  int pi2;
  int I = 0;
  int s = 0;
  int x3 = 0;
  int size = 0;
  int ret = 0;
  int ret1 = 0;
  int sd_wklg = 0;
  int x4;

  char ch;
  char *p, *p1, *p2, *p4;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3a[VAR_LGTH];

  pi = 0;
  pi2 = 0;
  convert = 0;

  p = strstr(wk_fdwk, "'");
  if (p) 
  {
    ch = wk_fdwk[pi];
    while (ch != '=') 
    {
      if (ch != ' ') 
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = wk_fdwk[pi];
    }
    tfield1[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield1a, c_wkname);
  
    pi++;
    ch = wk_fdwk[pi];
    while (ch != '\'') 
    {
      pi++;
      ch = wk_fdwk[pi];
    }

    pi2 = 0;
    pi++;
    pi++;
    ch = wk_fdwk[pi];
    tfield2[pi2] = ch;
    pi2++;
    tfield2[pi2] = '\0';
    strcpy(tfield2a, tfield2);

    x3 = 0;
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

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      if (global_st == 0) 
      {
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
        strcpy(gw_variable[gv_ct].gv_cname, tfield1a);
        strcpy(gw_variable[gv_ct].gv_name, tfield1);
        strcpy(gw_variable[gv_ct].gv_type, "C");
        s = atoi(tfield3a);
        gw_variable[gv_ct].gv_lgth = s;
        gw_variable[gv_ct].gv_current_lgth = 0;
        strcpy(gw_variable[gv_ct].gv_value, null_field);
        strcpy(gw_variable[gv_ct].gv_literal, null_field);
        gw_variable[gv_ct].gv_init = 0;
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
        gw_variable[gv_ct].gv_dec = 0;
        gw_variable[gv_ct].gv_id = 3;
        gv_ct++;
        convert = 1;
      }

      if (global_st == 1) 
      {
        if (lv_ct == 0) 
        {
          size = 1;
          lw_variable = malloc(size * sizeof(struct var));
        } 
        else 
        {
          size = lv_ct + 1;
          lw_variable = realloc(lw_variable, size * sizeof(struct var));
        }
        lw_variable[lv_ct].lv_rct = rct;
        strcpy(lw_variable[lv_ct].lv_cname, tfield1a);
        strcpy(lw_variable[lv_ct].lv_name, tfield1);
        strcpy(lw_variable[lv_ct].lv_type, "C");
        s = atoi(tfield3a);
        lw_variable[lv_ct].lv_lgth = s;
        lw_variable[lv_ct].lv_current_lgth = s;
        strcpy(lw_variable[lv_ct].lv_value, tfield2);
        lw_variable[lv_ct].lv_use_ct = 0;
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 3;
        lv_ct++;
        convert = 1;
      }
    }

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield1a, c_wkname);
      
    if (char_ct == 0) 
    {
      size = 1;
      w_charlit = malloc(size * sizeof(struct charlit));
    } 
    else 
    {
      size = char_ct + 1;
      w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
    }

    w_charlit[char_ct].clit_rct = rct;
    strcpy(w_charlit[char_ct].clit_cname, tfield1a);
    strcpy(w_charlit[char_ct].clit_value, tfield2);
    w_charlit[char_ct].clit_type = 3;
    w_charlit[char_ct].clit_lgth = x3;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;
  }

  if (!p) 
  {
    p4 = strstr(wk_fdwk, "=");
    if(p4) 
    {
      pi = 0;
      pi2 = 0;
      ch = wk_fdwk[pi];
      while (ch != '=') 
      {
        if (ch != ' ') 
        {
          tfield1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = wk_fdwk[pi];
      }
      tfield1[pi2] = '\0';

      x3 = 0;
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

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(tfield1a, c_wkname);
      
        if (global_st == 0) 
        {
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
          strcpy(gw_variable[gv_ct].gv_cname, tfield1a);
          strcpy(gw_variable[gv_ct].gv_name, tfield1);
          strcpy(gw_variable[gv_ct].gv_type, "C");
          gw_variable[gv_ct].gv_lgth = s;
          gw_variable[gv_ct].gv_current_lgth = 2;
          strcpy(gw_variable[gv_ct].gv_value, null_field);
          strcpy(gw_variable[gv_ct].gv_literal, null_field);
          gw_variable[gv_ct].gv_init = 0;
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
          gw_variable[gv_ct].gv_dec = 0;
          gw_variable[gv_ct].gv_id = 3;
          gv_ct++;
          convert = 1;
        }

        if (global_st == 1) 
        {
          if (lv_ct == 0) 
          {
            size = 1;
            lw_variable = malloc(size * sizeof(struct var));
          } 
          else 
          {
            size = lv_ct + 1;
            lw_variable = realloc(lw_variable, size * sizeof(struct var));
          }
          lw_variable[lv_ct].lv_rct = rct;
          strcpy(lw_variable[lv_ct].lv_cname, tfield1a);
          strcpy(lw_variable[lv_ct].lv_name, tfield1);
          strcpy(lw_variable[lv_ct].lv_type, "C");
          lw_variable[lv_ct].lv_lgth = 2;
          lw_variable[lv_ct].lv_current_lgth = 2;
          strcpy(lw_variable[lv_ct].lv_value, null_field);
          lw_variable[lv_ct].lv_use_ct = 0;
          strcpy(lw_variable[lv_ct].lv_func, sv_func);
          lw_variable[lv_ct].lv_dec = 0;
          lw_variable[lv_ct].lv_id = 3;
          lv_ct++;
          convert = 1;
        }
        return;
      }

      pi2 = 0;
      pi++;
      ch = wk_fdwk[pi];
      while (ch != ' ') 
      {
        tfield2[pi2] = ch;
        pi2++;
        pi++;
        ch = wk_fdwk[pi];
      }
      tfield2[pi2] = '\0';

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
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
        if (global_st == 0) 
        {
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
          strcpy(gw_variable[gv_ct].gv_cname, tfield2a);
          strcpy(gw_variable[gv_ct].gv_name, tfield2);
          strcpy(gw_variable[gv_ct].gv_type, "C");
          s = atoi(tfield3a);
          gw_variable[gv_ct].gv_lgth = s;
          gw_variable[gv_ct].gv_current_lgth = s;
          strcpy(gw_variable[gv_ct].gv_value, null_field);
          strcpy(gw_variable[gv_ct].gv_literal, null_field);
          gw_variable[gv_ct].gv_init = 0;
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
          gw_variable[gv_ct].gv_dec = 0;
          gw_variable[gv_ct].gv_id = 3;
          gv_ct++;
          convert = 1;
        }

        if (global_st == 1) 
        {
          if (lv_ct == 0) 
          {
            size = 1;
            lw_variable = malloc(size * sizeof(struct var));
          } 
          else 
          {
            size = lv_ct + 1;
            lw_variable = realloc(lw_variable, size * sizeof(struct var));
          }
          lw_variable[lv_ct].lv_rct = rct;
          strcpy(lw_variable[lv_ct].lv_cname, tfield2a);
          strcpy(lw_variable[lv_ct].lv_name, tfield2);
          strcpy(lw_variable[lv_ct].lv_type, "C");
          s = atoi(tfield3a);
          lw_variable[lv_ct].lv_lgth = s;
          lw_variable[lv_ct].lv_current_lgth = s;
          strcpy(lw_variable[lv_ct].lv_value, null_field);
          lw_variable[lv_ct].lv_use_ct = 0;
          strcpy(lw_variable[lv_ct].lv_func, sv_func);
          lw_variable[lv_ct].lv_dec = 0;
          lw_variable[lv_ct].lv_id = 3;
          lv_ct++;
          convert = 1;
        }
      }
      convert = 1;
    }

    if (!p4) 
    {
      ch = wk_fdwk[pi];
      while (ch != '[') 
      {
        if (ch != ' ') 
        {
          tfield1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = wk_fdwk[pi];
      }
      tfield1[pi2] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(tfield1a, c_wkname);
   
      skip = 0;
      if (ch == '[') 
      {
        skip = 1;
      }

      x3 = 0;
      pi2 = 0;
      if (skip == 1) 
      {
        x3 = 0;
        pi++;
        ch = wk_fdwk[pi];
        while (ch != ']') 
        {
          if (x3 == 0) 
          {
            if (isdigit(ch)) 
            {
              fd2_type = 1;
              x3 = 1;
            }
            if (isalpha(ch)) 
            {
              fd2_type = 2;
              x3 = 1;
            }
          }
          tfield2[pi2] = ch;
          pi2++;
          pi++;
          ch = wk_fdwk[pi];
        }
      }
      tfield2[pi2] = '\0';

      s = strlen(tfield2);

      if ((fd2_type == 2) && (s != 0)) 
      {
        x3 = 0;
        if (lv_ct > 0) 
        {
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(tfield2, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x3 = 1;
              strcpy(tfield3a, lw_variable[I].lv_value);
              strcpy(tfield2a, lw_variable[I].lv_cname);
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
              ret = strcmp(tfield2, gw_variable[I].gv_name);
              if (ret == 0) 
              {
                x3 = 1;
                strcpy(tfield3a, gw_variable[I].gv_value);
                strcpy(tfield2a, gw_variable[I].gv_cname);
                gw_variable[I].gv_use_ct++;
              }
            }
          }
        }

        if (x3 == 0) 
        {
          printf("\nc2z_char.c c2_char_1 [ ] char-001 tfield2 Not Found = %s\n",tfield2);
          printf("c2z_char.c c2_char_1 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

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
              if (ret == 0) 
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
          if (global_st == 0) 
          {
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
            strcpy(gw_variable[gv_ct].gv_cname, tfield1a);
            strcpy(gw_variable[gv_ct].gv_name, tfield1);
            strcpy(gw_variable[gv_ct].gv_type, "C");
            s = atoi(tfield3a);
            gw_variable[gv_ct].gv_lgth = s;
            gw_variable[gv_ct].gv_current_lgth = s;
            strcpy(gw_variable[gv_ct].gv_value, null_field);
            strcpy(gw_variable[gv_ct].gv_literal, null_field);
            gw_variable[gv_ct].gv_init = 0;
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
            gw_variable[gv_ct].gv_dec = 0;
            gw_variable[gv_ct].gv_id = 1;
            gv_ct++;
          }

          if (global_st == 1) 
          {
            if (lv_ct == 0) 
            {
              size = 1;
              lw_variable = malloc(size * sizeof(struct var));
            } 
            else 
            {
              size = lv_ct + 1;
              lw_variable = realloc(lw_variable, size * sizeof(struct var));
            }

            lw_variable[lv_ct].lv_rct = rct;
            strcpy(lw_variable[lv_ct].lv_cname, tfield1a);
            strcpy(lw_variable[lv_ct].lv_name, tfield1);
            strcpy(lw_variable[lv_ct].lv_type, "C");
            s = atoi(tfield3a);
            lw_variable[lv_ct].lv_lgth = s;
            lw_variable[lv_ct].lv_current_lgth = s;
            strcpy(lw_variable[lv_ct].lv_value, null_field);
            lw_variable[lv_ct].lv_use_ct = 0;
            strcpy(lw_variable[lv_ct].lv_func, sv_func);
            strcpy(lw_variable[lv_ct].lv_literal, null_field);
            lw_variable[lv_ct].lv_dec = 0;
            lw_variable[lv_ct].lv_id = 1;
            lv_ct++;
          }
          convert = 1;
          return;
        }
      }

      if ((fd1_type == 2) && (s != 0)) 
      {
        x3 = 0;
        if (lv_ct > 0) 
        {
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(tfield2, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x3 = 1;
              strcpy(tfield3a, lw_variable[I].lv_value);
              strcpy(tfield2a, lw_variable[I].lv_cname);
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
              ret = strcmp(tfield2, gw_variable[I].gv_name);
              if (ret == 0) 
              {
                x3 = 1;
                strcpy(tfield3a, gw_variable[I].gv_value);
                strcpy(tfield2a, gw_variable[I].gv_cname);
                gw_variable[I].gv_use_ct++;
              }
            }
          }
        }

        if (x3 == 0) 
        {
          printf("\nc2z_char.c c2_char_1 [ ] char-002 tfield2 Not Found = %s\n",tfield2);
          printf("c2z_char.c c2_char_1 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

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
              if (ret == 0) 
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
          if (global_st == 0) 
          {
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
            strcpy(gw_variable[gv_ct].gv_cname, tfield1a);
            strcpy(gw_variable[gv_ct].gv_name, tfield1);
            strcpy(gw_variable[gv_ct].gv_type, "C");
            s = atoi(tfield2);
            gw_variable[gv_ct].gv_lgth = s;
            gw_variable[gv_ct].gv_current_lgth = s;
            strcpy(gw_variable[gv_ct].gv_value, tfield2);
            strcpy(gw_variable[gv_ct].gv_literal, null_field);
            gw_variable[gv_ct].gv_init = 0;
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
            gw_variable[gv_ct].gv_dec = 0;
            gw_variable[gv_ct].gv_id = 3;
            gv_ct++;
          }

          if (global_st == 1) 
          {
            if (lv_ct == 0) 
            {
              size = 1;
              lw_variable = malloc(size * sizeof(struct var));
            } 
            else 
            {
              size = lv_ct + 1;
              lw_variable = realloc(lw_variable, size * sizeof(struct var));
            }

            lw_variable[lv_ct].lv_rct = rct;
            strcpy(lw_variable[lv_ct].lv_cname, tfield1a);
            strcpy(lw_variable[lv_ct].lv_name, tfield1);
            strcpy(lw_variable[lv_ct].lv_type, "C");
            s = atoi(tfield2);
            lw_variable[lv_ct].lv_lgth = s;
            lw_variable[lv_ct].lv_current_lgth = s;
            strcpy(lw_variable[lv_ct].lv_value, tfield2);
            lw_variable[lv_ct].lv_use_ct = 0;
            strcpy(lw_variable[lv_ct].lv_func, sv_func);
            strcpy(lw_variable[lv_ct].lv_literal, null_field);
            lw_variable[lv_ct].lv_dec = 0;
            lw_variable[lv_ct].lv_id = 3;
            lv_ct++;
          }
          convert = 1;
          return;
        }
      }

      if ((fd1_type == 0) && (convert == 0) && (s == 0)) 		/* dynamic char array init */
      {
        sd_wklg = 0;
        p1 = strstr(p_string, ";");
        p2 = strstr(p_string, "\"");
        if ((!p1) && (p2)) 
        {
          printf("c2z_char.c c2_char_1 !p1 & p2 NEED TO CODE\n");
        }

        if ((p1) && (p2))
        {
          pi = 0;
          ch = p_string[pi];
          while (ch != '\"') 
          {
            pi++;
            ch = p_string[pi];
          }

          pi2 = 0;
          pi++;
          ch = p_string[pi];
          while (ch != '\"') 
          {
            strtmp[pi2] = ch;
            pi2++;
            sd_wklg++;
            pi++;
            ch = p_string[pi];
          }
          strtmp[pi2] = '\0';

          /* ******************************************************************
          *  Optimize LXX table                                               *
          * ***************************************************************** */

          c_name++;
          snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
          strcpy(c_wkname, "C37F");
          strcat(c_wkname, wk_strg);
          x4 = strlen(c_wkname);
          c_wkname[x4] = '\0';
          strcpy(tfield1a, c_wkname);

          x3 = 0;

          if (cary_ct == 0) 
          {
            size = 1;
            w_carry = malloc(size * sizeof(struct carry));
          } 
          else 
          {
            size = cary_ct + 1;
            w_carry = realloc(w_carry, size * sizeof(struct carry));
          }
          w_carry[cary_ct].carry_rct = rct;
          strcpy(w_carry[cary_ct].carry_name, tfield1);
          strcpy(w_carry[cary_ct].carry_cname, tfield1a);
          w_carry[cary_ct].carry_ct = sd_wklg;
          w_carry[cary_ct].carry_use_ct = 0;
          strcpy(w_carry[cary_ct].carry_literal, strtmp);

          cary_ct++;

          /* ******************************************************************
          *  update the struct with literal                                   *
          * ***************************************************************** */
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
          strcpy(gw_variable[gv_ct].gv_cname, tfield1a);
          strcpy(gw_variable[gv_ct].gv_name, tfield1);
          strcpy(gw_variable[gv_ct].gv_type, "R");
          gw_variable[gv_ct].gv_lgth = sd_wklg;
          strcpy(gw_variable[gv_ct].gv_literal, null_field);
          gw_variable[gv_ct].gv_dec = 0;
          gv_ct++;

          convert = 1;
        }
      }

      s = strlen(tfield2);

      if ((fd2_type == 1) && (convert == 0)) 
      {
        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(tfield1a, c_wkname);
      
        if (global_st == 0) 
        {
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
          strcpy(gw_variable[gv_ct].gv_cname, tfield1a);
          strcpy(gw_variable[gv_ct].gv_name, tfield1);
          strcpy(gw_variable[gv_ct].gv_type, "C");
          s = atoi(tfield2);
          gw_variable[gv_ct].gv_lgth = s;
          strcpy(gw_variable[gv_ct].gv_value, tfield2);
          strcpy(gw_variable[gv_ct].gv_literal, null_field);
          gw_variable[gv_ct].gv_init = 0;
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
          gw_variable[gv_ct].gv_dec = 0;
          gw_variable[gv_ct].gv_id = 3;
          gv_ct++;

          convert = 1;
        }

        if (global_st == 1) 
        {
          if (lv_ct == 0) 
          {
            size = 1;
            lw_variable = malloc(size * sizeof(struct var));
          } 
          else 
          {
            size = lv_ct + 1;
            lw_variable = realloc(lw_variable, size * sizeof(struct var));
          }

          lw_variable[lv_ct].lv_rct = rct;
          strcpy(lw_variable[lv_ct].lv_cname, tfield1a);
          strcpy(lw_variable[lv_ct].lv_name, tfield1);
          strcpy(lw_variable[lv_ct].lv_type, "C");
          s = atoi(tfield2);
          lw_variable[lv_ct].lv_lgth = s;
          strcpy(lw_variable[lv_ct].lv_value, tfield2);
          lw_variable[lv_ct].lv_use_ct = 0;
          strcpy(lw_variable[lv_ct].lv_func, sv_func);
          lw_variable[lv_ct].lv_dec = 0;
          lw_variable[lv_ct].lv_id = 3;
          lv_ct++;

          convert = 1;
        }
        return;
      }
    }
  }
}

/* ******************************
*  char ch;                     *
* ***************************** */
void c2_char_2() 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_char.c c2_char_2 START");
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_char.c c2_char_2 START");
    strcat(trace_1, wk_fdwk);
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  int pi;
  int pi2;
  int y0 = 0;
  int y1 = 0;
  int y2 = 0;
  int y5 = 0;
  int s = 0;
  int size = 0;
  int I;

  s = strlen(wk_fdwk);

  pi2 = 0;
  pi = 0;
  ch = wk_fdwk[pi];
  for(I=0; I < s; I++)
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = wk_fdwk[pi];
  }
  field1[pi2] = '\0';

  y0 = 0;
  for (y1 = 0; y1 < lv_ct; y1++) 
  {
    y2 = strcmp(field1, lw_variable[y1].lv_name);
    y5 = strcmp(sv_func, lw_variable[y1].lv_func);
    if ((y2 == 0) && (y5 == 0)) 
    {
      y0 = 1;
      strcpy(field1a, lw_variable[y1].lv_value);
    }
  }

  if (y0 == 0) 
  {
    for (y1 = 0; y1 < gv_ct; y1++) 
    {
      y2 = strcmp(field1, gw_variable[y1].gv_name);
      if (y2 == 0) 
      {
        y0 = 1;
        strcpy(field1a, gw_variable[y1].gv_value);
      }
    }
  }

  if (y0 == 0) 
  {
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(field1a, c_wkname);

    if (global_st == 0) 
    {
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
      strcpy(gw_variable[gv_ct].gv_cname, field1a);
      strcpy(gw_variable[gv_ct].gv_name, field1);
      strcpy(gw_variable[gv_ct].gv_type, "C");
      s = 1;
      gw_variable[gv_ct].gv_lgth = s;
      strcpy(gw_variable[gv_ct].gv_value, null_field);
      strcpy(gw_variable[gv_ct].gv_literal, null_field);
      gw_variable[gv_ct].gv_init = 0;
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
      gw_variable[gv_ct].gv_flag = 0;
      gw_variable[gv_ct].gv_dec = 0;
      gv_ct++;
    }

    if (global_st == 1) 
    {
      if (lv_ct == 0) 
      {
        size = 1;
        lw_variable = malloc(size * sizeof(struct var));
      } 
      else 
      {
        size = lv_ct + 1;
        lw_variable = realloc(lw_variable, size * sizeof(struct var));
      }

      lw_variable[lv_ct].lv_rct = rct;
      strcpy(lw_variable[lv_ct].lv_cname, field1a);
      strcpy(lw_variable[lv_ct].lv_name, field1);
      strcpy(lw_variable[lv_ct].lv_type, "C");
      lw_variable[lv_ct].lv_lgth = 1;
      strcpy(lw_variable[lv_ct].lv_value, null_field);
      lw_variable[lv_ct].lv_use_ct = 0;
      strcpy(lw_variable[lv_ct].lv_func, sv_func);
      strcpy(lw_variable[lv_ct].lv_literal, null_field);
      lw_variable[lv_ct].lv_dec = 0;
      lw_variable[lv_ct].lv_id = 3;
      lv_ct++;
    }
  }
}

/* ******************************
*  char **array                 *
* ***************************** */
void c2_char_3() 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_char.c c2_char_3 rct = %d START", rct);
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_char.c c2_char_3");
    trace_rec_1();
  }

  tot_malloc++;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  int pi;
  int pi2;
  int s = 0;
  int size = 0;
  int I = 0;

  pi = 0;
  ch = wk_fdwk[pi];
  pi2 = 0;
  s = strlen(wk_fdwk);
  for (I = 0; I < s; I++) 
  {
    if (ch != '*') 
    {
      field1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = wk_fdwk[pi];
  }
  field1[pi2] = '\0';

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(field1a, c_wkname);

  if (global_st == 0) 
  {
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
    
    tot_malloc++;

    gw_variable[gv_ct].gv_rct = rct;
    strcpy(gw_variable[gv_ct].gv_cname, field1a);
    strcpy(gw_variable[gv_ct].gv_name, field1);
    strcpy(gw_variable[gv_ct].gv_type, "A");
    gw_variable[gv_ct].gv_init = 0;
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_flag = 0;
    gw_variable[gv_ct].gv_row = 10;
    gw_variable[gv_ct].gv_column = 25;

    gw_variable[gv_ct].gv_lgth = 32;

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "T");
    strcpy(gw_variable[gv_ct].gv_table, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "N");
    strcpy(gw_variable[gv_ct].gv_dsect, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "L");
    strcpy(gw_variable[gv_ct].gv_label, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "R");
    strcpy(gw_variable[gv_ct].gv_sv_reg, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "X");
    strcpy(gw_variable[gv_ct].gv_wk_reg, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "W");
    strcpy(gw_variable[gv_ct].gv_wk_strg, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "A");
    strcpy(gw_variable[gv_ct].gv_aname, wk_string);

    gw_variable[gv_ct].gv_flag = 0;
   
   /*  gw_variable[gv_ct].gv_column = 32;
    gw_variable[gv_ct].gv_row = 250; */

    gv_ct++;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

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
    strcpy(gw_variable[gv_ct].gv_name, wk_string);
    strcpy(gw_variable[gv_ct].gv_type, "B");
    gw_variable[gv_ct].gv_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_init = 0;
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
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_flag = 0;
    gv_ct++;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

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
    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "W");

    gw_variable[gv_ct].gv_rct = rct;
    strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
    strcpy(gw_variable[gv_ct].gv_name, wk_string);
    strcpy(gw_variable[gv_ct].gv_type, "C");
    gw_variable[gv_ct].gv_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_init = 0;
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
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_flag = 0;
    gv_ct++;
  }

  convert = 1;
}

/* ******************************
*  char *ch;                    *
* ***************************** */
void c2_char_4() 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_char.c c2_char_4 START");
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_char.c scan c2_char_4 START");
    trace_rec_1();
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_char.c scan c2_char_4 subroutine #1");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];

  int pi;
  int pi2;
  int s = 0;
  int size = 0;
  int x80 = 0;

  x80 = 0;
  pi2 = 0;
  pi = 0;
  s = strlen(wk_fdwk);
  ch = wk_fdwk[pi];
  while (pi < s) 
  {
    if (ch == '=') 
    {
      x80 = 1;
      break;
    }

    if (ch != '*') 
    {
      field1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = wk_fdwk[pi];
  }
  field1[pi2] = '\0';

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(field1a, c_wkname);

  if (global_st == 0) 
  {
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
    strcpy(gw_variable[gv_ct].gv_cname, field1a);
    strcpy(gw_variable[gv_ct].gv_name, field1);
    strcpy(gw_variable[gv_ct].gv_type, "C");
    gw_variable[gv_ct].gv_lgth = 32;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_init = 0;
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
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_id = 1;
    gv_ct++;
  }

  if (global_st == 1) 
  {
    if (lv_ct == 0) 
    {
      size = 1;
      lw_variable = malloc(size * sizeof(struct var));
    } 
    else 
    {
      size = lv_ct + 1;
      lw_variable = realloc(lw_variable, size * sizeof(struct var));
    }

    lw_variable[lv_ct].lv_rct = rct;
    strcpy(lw_variable[lv_ct].lv_cname, field1a);
    strcpy(lw_variable[lv_ct].lv_name, field1);
    strcpy(lw_variable[lv_ct].lv_type, "C");
    lw_variable[lv_ct].lv_lgth = 32;
    strcpy(lw_variable[lv_ct].lv_value, null_field);
    lw_variable[lv_ct].lv_use_ct = 0;
    strcpy(lw_variable[lv_ct].lv_func, sv_func);
    lw_variable[lv_ct].lv_dec = 0;
    lw_variable[lv_ct].lv_id = 1;
    lv_ct++;
  }

  if (x80 == 0) 
  {
    convert = 1;
    return;
  }

  if (x80 == 1) 
  {

    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_char.c scan c2_char_4 subroutine #2");
      trace_rec_1();
    }

    pi = 0;
    ch = wk_fdwk[pi];
    while (ch != '=') 
    {
      pi++;
      ch = wk_fdwk[pi];
    }

    pi2 = 0;
    pi++;
    ch = wk_fdwk[pi];
    while (ch != ' ') 
    {
      if(ch != '"')
      {
        field2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = wk_fdwk[pi];
    }
    field2[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

    if (char_ct == 0) 
    {
      size = 1;
      w_charlit = malloc(size * sizeof(struct charlit));
    } 
    else 
    {
      size = char_ct + 1;
      w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
    }

    w_charlit[char_ct].clit_rct = rct;
    strcpy(w_charlit[char_ct].clit_cname, c_wkname);
    strcpy(w_charlit[char_ct].clit_value, field2);
    w_charlit[char_ct].clit_type = 3;
    s = strlen(field2);
    w_charlit[char_ct].clit_lgth = s;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;

    convert = 1;
    return;
  }
}

void c2_char_5() 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_char.c c2_char_35rct = %d START", rct);
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "scan c2_char_5 ");
    trace_rec_1();
  }

  convert = 1;
  exit(1);
}

void c2_char_6() 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_char.c c2_char_6 rct = %d START", rct);
  }

  if (traceflg == 1)   
  {
    strcpy(trace_1, "scan c2_char_6 ");
    trace_rec_1();
  }

  convert = 1;
  exit(1);
}

void c2_char_9() 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_char.c c2_char_9 START");
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_char.c c2_char_9 START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5a[VAR_LGTH];

  int y0 = 0;
  int y1 = 0;
  int y2 = 0;
  int y5 = 0;
  int pi;
  int pi2;
  int I = 0;
  int s = 0;
  int x3 = 0;
  int size = 0;
  int fd2_type = 0;
  int fd3_type = 0;

  tot_malloc++;

  pi = 0;
  ch = wk_fdwk[pi];
  while (ch == ' ') 
  {
    ch = wk_fdwk[pi];
    pi++;
  }

  pi2 = 0;
  ch = wk_fdwk[pi];
  while (ch != '[') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = wk_fdwk[pi];
  }
  field1[pi2] = '\0';

  pi2 = 0;
  x3 = 0;
  pi++;
  ch = wk_fdwk[pi];
  while (ch != ']') 
  {
    if (x3 == 0) 
    {
      if (isdigit(ch)) 
      {
        fd2_type = 1;
        x3 = 1;
      }

      if (isalpha(ch)) 
      {
        fd2_type = 2;
        x3 = 1;
      }
    }
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = wk_fdwk[pi];
  }
  field2[pi2] = '\0';

  x3 = 0;
  pi2 = 0;
  pi++;
  pi++;
  ch = wk_fdwk[pi];
  while (ch != ']') 
  {
    if (x3 == 0) 
    {
      if (isdigit(ch)) 
      {
        fd3_type = 1;
        x3 = 1;
      }

      if (isalpha(ch)) 
      {
        fd3_type = 2;
        x3 = 1;
      }
    }
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = wk_fdwk[pi];
  }
  field3[pi2] = '\0';

  y0 = 0;
  if (lv_ct > 0) 
  {
    for (y1 = 0; y1 < lv_ct; y1++) 
    {
      y2 = strcmp(field1, lw_variable[y1].lv_name);
      y5 = strcmp(sv_func, lw_variable[y1].lv_func);
      if ((y2 == 0) && (y5 == 0)) 
      {
        y0 = 1;
        strcpy(field1a, lw_variable[y1].lv_cname);
        lw_variable[y1].lv_use_ct++;
      }
    }
  }

  if (y0 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (y1 = 0; y1 < gv_ct; y1++) 
      {
        y2 = strcmp(field1, gw_variable[I].gv_name);
        if (y2 == 0) 
        {
          y0 = 1;
          strcpy(field1a, gw_variable[y1].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }
  }

  y0 = 0;
  if (fd2_type == 2) 
  {
    if (lv_ct > 0) 
    {
      for (y1 = 0; y1 < lv_ct; y1++) 
      {
        y2 = strcmp(field2, lw_variable[y1].lv_name);
        y5 = strcmp(sv_func, lw_variable[y1].lv_func);
        if ((y2 == 0) && (y5 == 0)) 
        {
          y0 = 1;
          strcpy(field2a, lw_variable[y1].lv_cname);
          lw_variable[y1].lv_use_ct++;
        }
      }
    }

    if (y0 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (y1 = 0; y1 < gv_ct; y1++) 
        {
          y2 = strcmp(field2, gw_variable[y1].gv_name);
          if (y2 == 0) 
          {
            y0 = 1;
            strcpy(field2a, gw_variable[y1].gv_cname);
            gw_variable[y1].gv_use_ct++;
          }
        }
      }
    }
  }

  y0 = 0;
  if (fd3_type == 2) 
  {
    if (lv_ct > 0) 
    {
      for (y1 = 0; y1 < lv_ct; y1++) 
      {
        y2 = strcmp(field3, lw_variable[y1].lv_name);
        y5 = strcmp(sv_func, lw_variable[y1].lv_func);
        if ((y2 == 0) && (y5 == 0)) 
        {
          y0 = 1;
          strcpy(field3a, lw_variable[y1].lv_cname);
          lw_variable[y1].lv_use_ct++;
        }
      }
    }

    if (y0 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (y1 = 0; y1 < gv_ct; y1++) 
        {
          y2 = strcmp(field3, gw_variable[y1].gv_name);
          if (y2 == 0) 
          {
            y0 = 1;
            strcpy(field3a, gw_variable[y1].gv_cname);
            gw_variable[y1].gv_use_ct++;
          }
        }
      }
    }
  }

  if ((fd2_type == 1) || (fd3_type == 1)) 
  {
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(field1a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, field1a);
    strcpy(gw_variable[gv_ct].gv_name, field1);
    strcpy(gw_variable[gv_ct].gv_type, "A");
    gw_variable[gv_ct].gv_init = 0;
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "T");
    strcpy(gw_variable[gv_ct].gv_table, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "N");
    strcpy(gw_variable[gv_ct].gv_dsect, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "L");
    strcpy(gw_variable[gv_ct].gv_label, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "R");
    strcpy(gw_variable[gv_ct].gv_sv_reg, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "X");
    strcpy(gw_variable[gv_ct].gv_wk_reg, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "W");
    strcpy(gw_variable[gv_ct].gv_wk_strg, wk_string);

    gw_variable[gv_ct].gv_row = atoi(field2);
   
    gw_variable[gv_ct].gv_column = atoi(field3);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "A");
    strcpy(gw_variable[gv_ct].gv_aname, wk_string);
    gw_variable[gv_ct].gv_lgth = atoi(field3);
    gw_variable[gv_ct].gv_flag = 0;
    gv_ct++;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

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
    strcpy(gw_variable[gv_ct].gv_name, wk_string);
    strcpy(gw_variable[gv_ct].gv_type, "B");
    gw_variable[gv_ct].gv_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_init = 0;
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
    gw_variable[gv_ct].gv_dec = 0;
    gv_ct++;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

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
    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "W");

    gw_variable[gv_ct].gv_rct = rct;
    strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
    strcpy(gw_variable[gv_ct].gv_name, wk_string);
    strcpy(gw_variable[gv_ct].gv_type, "C");
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_init = 0;
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;

    y0 = atoi(field3);
    gw_variable[gv_ct].gv_column = y0;
    y0 = atoi(field3);
    gw_variable[gv_ct].gv_lgth = y0;

    strcpy(gw_variable[gv_ct].gv_dsect, null_field);
    gw_variable[gv_ct].gv_row = 0;
    strcpy(gw_variable[gv_ct].gv_label, null_field);
    strcpy(gw_variable[gv_ct].gv_table, null_field);
    strcpy(gw_variable[gv_ct].gv_aname, null_field);
    strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
    strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
    strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
    gv_ct++;

    convert = 1;
    return;
  }

  if ((fd2_type == 2) || (fd3_type == 2)) 
  {
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(field1a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, field1a);
    strcpy(gw_variable[gv_ct].gv_name, field1);
    strcpy(gw_variable[gv_ct].gv_type, "A");
    gw_variable[gv_ct].gv_init = 0;
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "T");
    strcpy(gw_variable[gv_ct].gv_table, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "N");
    strcpy(gw_variable[gv_ct].gv_dsect, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "L");
    strcpy(gw_variable[gv_ct].gv_label, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "R");
    strcpy(gw_variable[gv_ct].gv_sv_reg, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "X");
    strcpy(gw_variable[gv_ct].gv_wk_reg, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "W");
    strcpy(gw_variable[gv_ct].gv_wk_strg, wk_string);

    y0 = 0;
    if (gv_ct > 0) 
    {
      for (y1 = 0; y1 < gv_ct; y1++) 
      {
        y2 = strcmp(field2, gw_variable[y1].gv_name);
        if (y2 == 0) 
        {
          strcpy(field4a, gw_variable[y1].gv_value);
        }
      }
    }
    gw_variable[gv_ct].gv_row = atoi(field4a);

    y0 = 0;
    if (gv_ct > 0) 
    {
      for (y1 = 0; y1 < gv_ct; y1++) 
      {
        y2 = strcmp(field3, gw_variable[y1].gv_name);
        if (y2 == 0) 
        {
          strcpy(field5a, gw_variable[y1].gv_value);
        }
      }
    }
    gw_variable[gv_ct].gv_column = atoi(field5a);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "A");
    strcpy(gw_variable[gv_ct].gv_aname, wk_string);
    gw_variable[gv_ct].gv_lgth = atoi(field5a);
    gw_variable[gv_ct].gv_flag = 0;
    gv_ct++;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

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
    strcpy(gw_variable[gv_ct].gv_name, wk_string);
    strcpy(gw_variable[gv_ct].gv_type, "B");
    gw_variable[gv_ct].gv_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_init = 0;
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
    gw_variable[gv_ct].gv_dec = 0;
    gv_ct++;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

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
    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "W");

    gw_variable[gv_ct].gv_rct = rct;
    strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
    strcpy(gw_variable[gv_ct].gv_name, wk_string);
    strcpy(gw_variable[gv_ct].gv_type, "C");
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_init = 0;
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    if (fd3_type == 2) 
    {
      y0 = atoi(field5a);
      gw_variable[gv_ct].gv_column = y0;
      y0 = atoi(field5a);
      gw_variable[gv_ct].gv_lgth = y0;
    }
    strcpy(gw_variable[gv_ct].gv_dsect, null_field);
    gw_variable[gv_ct].gv_row = 0;
    strcpy(gw_variable[gv_ct].gv_label, null_field);
    strcpy(gw_variable[gv_ct].gv_table, null_field);
    strcpy(gw_variable[gv_ct].gv_aname, null_field);
    strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
    strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
    strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
    gv_ct++;

    convert = 1;
    return;
  }
}


/* ***************************************************
*  Scan test for CHAR                                *
* ************************************************** */
void c2_char_punch() 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_char.c c2_char_punch rct = %d START", rct);
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_char.c punch START");
    trace_rec_1();
  }

  int pi;
  int pi2;
  int x3;
  int x99;
  int I;
  int ret;
  int ret1;
  int comma;
  int v;

  char ch, *p1;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];

  x3 = 0;
  v = strlen(p_string);
  for(I=0; I < v; I++)
  {
    ch = p_string[I];
    if(ch == '[')
    {
      x3++;
    }
    if(ch == ']')
    {
      x3++;
    }
  }

  if(x3 == 4)
  {
    convert = 1;
    return;
  }
  
  if(x3 == 6)
  {
    convert = 1;
    return;
  }

  pi = 0;
  ch = p_string[pi];
  while((ch == ' ') || (ch == '\t') || (ch == '{'))
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';
  
  comma = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ';')
  {
    if(ch == ',')
    {
       comma = 1;
       break;
    }
    if(ch == '[')
    {
      break;
    }
    if(ch != '*')
    {
      field1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  p1 = strstr(p_string, "=");
 
  if(!p1)
  {
    x99 = 0;
    x3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strcpy(field1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x99 = lw_variable[I].lv_lgth;
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(field1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x99 = gw_variable[I].gv_lgth;
          x3 = 1;
        }
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_char.c #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_char.c #2");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_char.c #3");
      trace_rec_3();
    }

    if(x99 != 1)
    {
      x99--;
      snprintf(wk_strg, sizeof(wk_strg), "%d", x99);
      strcpy(a_string, "         MVC   1(");
      strcat(a_string, wk_strg);
      strcat(a_string, ",R9),0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_char.c #4");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_char.c #5");
      trace_rec_3();
    }
    work_use_ct[74]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_char.c #6");
      trace_rec_3();
    }
  }

  if(p1)
  {
    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t') || (ch == '{'))
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != ' ')
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    comma = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != '=')
    {
      if(ch == ',')
      {
         comma = 1;
         break;
      }
      if(ch == '[')
      {
        break;
      }
      if(ch != '*')
      {
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field1a, lw_variable[v].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field1a, gw_variable[v].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_char.c c2_case_punch_1 char-003 field1 Not Found = %s\n", field1);
      printf("c2z_char.c c2_case_punch_1 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_char.c #7");
      trace_rec_3();
    }

    for (I = 0; I < char_ct; I++) 
    {
      ret = w_charlit[I].clit_rct;
      if (rct == ret) 
      {
        strcpy(field2a, w_charlit[I].clit_cname);
        x99 = w_charlit[I].clit_lgth;
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_char.c #8");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x99);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_char.c #9");
      trace_rec_3();
    }
    convert = 1;
  }

  if(comma == 1)
  {
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != ';')
    {
      if(ch == ',')
      {
        comma = 2;
        break;
      }
      if(ch == '[')
      {
        break;
      }
      if(ch != ' ')
      {
        field2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';
 
    x99 = 0;
    x3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strcpy(field2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x99 = lw_variable[I].lv_lgth;
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(field2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x99 = gw_variable[I].gv_lgth;
          x3 = 1;
        }
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_char.c #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_char.c #11");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_char.c #12");
      trace_rec_3();
    }

    if(x99 != 1)
    {
      x99--;
      snprintf(wk_strg, sizeof(wk_strg), "%d", x99);
      strcpy(a_string, "         MVC   1(");
      strcat(a_string, wk_strg);
      strcat(a_string, ",R9),0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_char.c #13");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_char.c #14");
      trace_rec_3();
    }
    work_use_ct[74]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_char.c #15");
      trace_rec_3();
    }
  }
}



/* ******************************
*  char array[ ][ ][ ]          *
* ***************************** */
void c2_char_41() 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_char.c c2_char_41 rct = %d START", rct);
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_char.c c2_char_41");
    trace_rec_1();
  }

   int pi;
   int x1;
   int x2;
   int x3;
   int x101;
   int x102;
   int x103;
   int ret;
   int ret1;
   int s;
   int size;
   int v;
   int fd2_type;
   int fd3_type;
   int fd4_type;

  char ch;
  char wk_name[VAR_LGTH];
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  while(ch != ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  x1 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != '[')
  {
    field1[x1] = ch;
    x1++;
    pi++;
    ch = p_string[pi];
  }
  field1[x1] = '\0';

  x1 = 0;   
  x2 = 0;
  fd2_type = 0;
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
    field2[x1] = ch;
    x1++;
    pi++;
    ch = p_string[pi];
  }
  field2[x1] = '\0';

  x1 = 0;   
  x2 = 0;
  fd3_type = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    if(ch != '[')
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
      field3[x1] = ch;
      x1++;
    }
    pi++;
    ch = p_string[pi];
  }
  field3[x1] = '\0';

  x1 = 0;   
  x2 = 0;
  fd4_type = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
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
      field4[x1] = ch;
      x1++;
    }
    pi++;
    ch = p_string[pi];
  }
  field4[x1] = '\0';

printf("\nc2z_char.c char_41 rct = %d p_string = %s",rct,p_string);
printf("c2z_char.c char_41 field1 = %s\n",field1);
printf("c2z_char.c char_41 field2 = %s\n",field2);
printf("c2z_char.c char_41 field3 = %s\n",field3);
printf("c2z_char.c char_41 field4 = %s\n",field4);


  x3 = 0;
  for (v = 0; v < lv_ct; v++) 
  {
    ret = strcmp(field1, lw_variable[v].lv_name);
    ret1 = strcmp(sv_func, lw_variable[v].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
    }
  }

  if (x3 == 0) 
  {
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(field1, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
      }
    }
  }

  if(x3 == 1)
  {
    printf("\nc2z_char.c c2_char_41 E-301 field1 Duplicate Field1 = %s\n", field1);
    printf("c2z_char.c c2_char_41 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if(fd2_type == 2)
  {
    x3 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field2, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        strcpy(field2a, lw_variable[v].lv_value);
        x3 = 1;
      }
    }

    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          strcpy(field2a, gw_variable[v].gv_value);
          x3 = 1;
        }
      }
    }

    if(x3 == 0)
    {
      printf("\nc2z_char.c c2_char_41 E-302 field2 Not Found field2 = %s\n", field2);
      printf("c2z_char.c c2_char_41 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd3_type == 2)
  {
    x3 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field3, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        strcpy(field3a, lw_variable[v].lv_value);
        x3 = 1;
      }
    }

    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field3, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          strcpy(field3a, gw_variable[v].gv_value);
          x3 = 1;
        }
      }
    }

    if(x3 == 0)
    {
      printf("\nc2z_char.c c2_char_41 E-303 field3 Not Found field3 = %s\n", field3);
      printf("c2z_char.c c2_char_41 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd4_type == 2)
  {
    x3 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field4, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        strcpy(field4a, lw_variable[v].lv_value);
        x3 = 1;
      }
    }

    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field4, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          strcpy(field4a, gw_variable[v].gv_value);
          x3 = 1;
        }
      }
    }

    if(x3 == 0)
    {
      printf("\nc2z_char.c c2_char_41 E-304 field4 Not Found field3 = %s\n", field4);
      printf("c2z_char.c c2_char_41 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (global_st == 0) 
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", st_col);
    strcpy(wk_name, "C37FCL");
    strcat(wk_name, wk_strg);
    s = strlen(wk_name);
    wk_name[s] = '\0';

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
    strcpy(gw_variable[gv_ct].gv_name, wk_name);
    strcpy(gw_variable[gv_ct].gv_cname, wk_name);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    if(fd3_type == 1)
    {
      x102 = atoi(field3);
      snprintf(wk_strg, sizeof(wk_strg), "%d", x102);
      strcpy(gw_variable[gv_ct].gv_value, wk_strg);
    }
    if(fd3_type == 2)
    {
      strcpy(gw_variable[gv_ct].gv_value, field3a);
    }
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    strcpy(gw_variable[gv_ct].gv_dsect, null_field);
    gw_variable[gv_ct].gv_row = 0;
    gw_variable[gv_ct].gv_column = x102;
    strcpy(gw_variable[gv_ct].gv_label, null_field);
    strcpy(gw_variable[gv_ct].gv_table, null_field);
    strcpy(gw_variable[gv_ct].gv_aname, null_field);
    strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
    strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
    strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
    gw_variable[gv_ct].gv_flag = 0;
    gw_variable[gv_ct].gv_dec = 0;
    gw_variable[gv_ct].gv_id = 1;
    gv_ct++;
    st_col++;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(field1a, c_wkname);

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
    strcpy(gw_variable[gv_ct].gv_cname, field1a);
    strcpy(gw_variable[gv_ct].gv_name, field1);
    strcpy(gw_variable[gv_ct].gv_type, "A");
    gw_variable[gv_ct].gv_init = 0;
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    strcpy(gw_variable[gv_ct].gv_st_col, wk_name);

    if((fd2_type == 1) && (fd3_type == 1))
    {
      x101 = atoi(field2);
      gw_variable[gv_ct].gv_row = x101;
      x102 = atoi(field3);
      gw_variable[gv_ct].gv_column = x102;
    }

    if((fd2_type == 2) && (fd3_type == 2))
    {
      x101 = atoi(field2a);
      gw_variable[gv_ct].gv_row = x101;
      x102 = atoi(field3a);
      gw_variable[gv_ct].gv_column = x102;
    }

    if(fd4_type == 1)
    {
      x103 = atoi(field4);
      gw_variable[gv_ct].gv_lgth = x103;
printf("#100 c2z_char.c printf_str4 #1 field4 = %s x103 = %d\n",field4,x103);
    }

    if(fd4_type == 2)
    {
      x103 = atoi(field4a);
      gw_variable[gv_ct].gv_lgth = x103;
printf("#100 c2z_char.c printf_str4 #2 field4 = %s x103 = %d\n",field4,x103);

    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_arr);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "T");
    strcpy(gw_variable[gv_ct].gv_table, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_arr);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "N");
    strcpy(gw_variable[gv_ct].gv_dsect, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_arr);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "L");
    strcpy(gw_variable[gv_ct].gv_label, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_arr);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "R");
    strcpy(gw_variable[gv_ct].gv_sv_reg, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_arr);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "X");
    strcpy(gw_variable[gv_ct].gv_wk_reg, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_arr);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "W");
    strcpy(gw_variable[gv_ct].gv_wk_strg, wk_string);

    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_arr);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "A");
    strcpy(gw_variable[gv_ct].gv_aname, wk_string);

    gv_ct++;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

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
    strcpy(gw_variable[gv_ct].gv_name, wk_string);
    strcpy(gw_variable[gv_ct].gv_type, "B");
    gw_variable[gv_ct].gv_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_init = 0;
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
    gw_variable[gv_ct].gv_dec = 0;
    gv_ct++;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

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
    snprintf(wk_strg, sizeof(wk_strg), "%d", tot_arr);
    strcpy(wk_string, "A37");
    strcat(wk_string, wk_strg);
    strcat(wk_string, "W");

    gw_variable[gv_ct].gv_rct = rct;
    strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
    strcpy(gw_variable[gv_ct].gv_name, wk_string);
    strcpy(gw_variable[gv_ct].gv_type, "C");
    gw_variable[gv_ct].gv_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_init = 0;
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
    gw_variable[gv_ct].gv_dec = 0;
    gv_ct++;
    tot_arr++;
    tot_malloc++;

  }
  convert = 1;
}

