/* ***************************************************
*  c2z : c2z_file.c :                                *
*                                                    *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* ***************************************************
*  Scan for FILE                                     *
* ************************************************** */
void c2_file() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_file.c c2_file START");
    trace_rec_1();
  }

  int x;
  int pi;
  int pi2;
  int u1;
  int II;
  int x10 = 0;
  int s;
  int x3;
  int v;
  int ret;
  int ret1;
  int size;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

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
  char wk_work[VAR_LGTH];
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];

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

  pi = 0;
  ch = p_string[pi];
  while (ch != 'E') 
  {
    pi++;
    ch = p_string[pi];
  }

  u1 = 0;
  x = 0;
  pi++;
  pi2 = 0;
  ch = p_string[pi];
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
          if (ch != '*') 
          {
            wk_fdwk[pi2] = ch;
            pi2++;
          }
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
  }

  for (x10 = 0; x10 < II; x10++) 
  {
    if (x10 == 0) 
    {
      strcpy(wk_work, wk_fd1);
      strcpy(tfield1, wk_fd1);
    }
    if (x10 == 1) 
    {
      strcpy(wk_work, wk_fd2);
      strcpy(tfield1, wk_fd2);
    }

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield1a, c_wkname);

    x3 = 0;
    for (v = 0; v < lv_ct; v++) {
      ret = strcmp(field1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) {
        x3 = 1;
        strcpy(field1a, lw_variable[v].lv_cname);
      }
    }

    if (x3 == 0) {
      for (v = 0; v < gv_ct; v++) {
        ret = strcmp(field1, gw_variable[v].gv_name);
        if (ret == 0) {
          x3 = 1;
          strcpy(field1a, gw_variable[v].gv_cname);
        }
      }
    }

    if (x3 == 0) {
      if (global_st == 0) {
        if (gv_ct == 0) {
          size = 1;
          gw_variable = malloc(size * sizeof(struct variables));
        } else {
          size = gv_ct + 1;
          gw_variable = realloc(gw_variable, size * sizeof(struct variables));
        }

        gw_variable[gv_ct].gv_rct = rct;
        strcpy(gw_variable[gv_ct].gv_cname, tfield1a);
        strcpy(gw_variable[gv_ct].gv_name, tfield1);
        strcpy(gw_variable[gv_ct].gv_type, "C");
        gw_variable[gv_ct].gv_lgth = 32;
        gw_variable[gv_ct].gv_current_lgth = 0;
        strcpy(gw_variable[gv_ct].gv_value, null_field);
        gw_variable[gv_ct].gv_init = 0;
        strcpy(gw_variable[gv_ct].gv_literal, null_field);
        gw_variable[gv_ct].gv_use_ct = 0;
        gw_variable[gv_ct].gv_dec = 0;
        gv_ct++;
      }

      if (global_st == 1) {
        if (lv_ct == 0) {
          size = 1;
          lw_variable = malloc(size * sizeof(struct var));
        } else {
          size = lv_ct + 1;
          lw_variable = realloc(lw_variable, size * sizeof(struct var));
        }

        lw_variable[lv_ct].lv_rct = rct;
        strcpy(lw_variable[lv_ct].lv_cname, tfield1a);
        strcpy(lw_variable[lv_ct].lv_name, tfield1);
        strcpy(lw_variable[lv_ct].lv_type, "C");
        lw_variable[lv_ct].lv_lgth = 32;
        strcpy(lw_variable[lv_ct].lv_value, null_field);
        lw_variable[lv_ct].lv_use_ct = 0;
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lv_ct++;
      }
    }
  }
}

/* ***************************************************
*  Scan for remove                                   *
* ************************************************** */
void c2_file_remove() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_file.c c2_file_remove START");
    trace_rec_1();
  }

  char ch, *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];

  int pi = 0;
  int pi2 = 0;
  int x3 = 0;
  int v = 0;
  int ret = 0;
  int ret1 = 0;
  int size = 0;
  int s = 0;
  int I = 0;

  pi = 0;
  pi2 = 0;
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

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(field1a, c_wkname);

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
      strcpy(gw_variable[gv_ct].gv_cname, field1a);
      strcpy(gw_variable[gv_ct].gv_name, field1);
      strcpy(gw_variable[gv_ct].gv_type, "I");
      gw_variable[gv_ct].gv_lgth = 0;
      gw_variable[gv_ct].gv_current_lgth = 0;
      strcpy(gw_variable[gv_ct].gv_value, null_field);
      gw_variable[gv_ct].gv_init = 0;
      strcpy(gw_variable[gv_ct].gv_literal, null_field);
      gw_variable[gv_ct].gv_use_ct = 0;
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
      strcpy(lw_variable[lv_ct].lv_type, "I");
      lw_variable[lv_ct].lv_lgth = 0;
      strcpy(lw_variable[lv_ct].lv_value, null_field);
      lw_variable[lv_ct].lv_use_ct = 0;
      strcpy(lw_variable[lv_ct].lv_func, sv_func);
      lw_variable[lv_ct].lv_current_lgth = 0;
      lw_variable[lv_ct].lv_dec = 0;
      lv_ct++;
    }
  }

  p = strstr(field2, "\"");

  if (!p) 
  {
    printf("\nc2z_file.c c2_file_remove !p NEEDS TO BE CODED\n");
    erct++;
    convert = 1;
    return;
  }

  if (p) 
  {
    pi = 0;
    pi2 = 0;
    s = strlen(field2);
    for (I = 0; I < s; I++) 
    {
      ch = field2[I];
      if (ch != '\"') 
      {
        field3[pi2] = ch;
        pi2++;
      }
    }
    field3[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

    s = strlen(field3);
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
    strcpy(w_charlit[char_ct].clit_value, field3);
    w_charlit[char_ct].clit_type = 3;
    w_charlit[char_ct].clit_lgth = s;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;

    convert = 1;
  }
}

/* ***************************************************
*  Punch out remove                                  *
* ************************************************** */
void c2_file_punch() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_file.c c2_file_punch START");
    trace_rec_1();
  }

  convert = 1;
}

/* ***************************************************
*  Scan for fgetc                                    *
* ************************************************** */
void c2_fgetc_pass2() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_file.c c2_fgetc_pass2 START");
    trace_rec_1();
  }

/*
  printf("\nc2z_file.c c2_fgetc_pass2 NEED TO CODE\n");
  printf("c2z_file.c c2_fgetc_pass2 rct = %d p_string = %s", rct, p_string);
  erct++;
*/
  convert = 1;
  return;
}

/* ***************************************************
*  Punch for fgetc                                   *
* ************************************************** */
void c2_fgetc_punch() 
{

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_file.c c2_fgetc_punch START");
    trace_rec_1();
  }

  convert = 1;
}

/* ***************************************************
*  Scan for getchar                                  *
* ************************************************** */
void c2_getchar_pass2() 
{
/*
  printf("\nc2z_file.c c2_getchar_pass2 rct = %d p_string = %s", rct, p_string);
  printf("c2z_file.c c2_getchar_pass2 NEED TO CODE\n");
*/
  if (traceflg == 1) 
  {
    strcpy(trace_1, "\nc2z_file.c c2_getchar_pass2 START");
    trace_rec_1();
  }
  convert = 1;
  return;
}

/* ***************************************************
*  Punch for getchar                                 *
* ************************************************** */
void c2_getchar_punch() 
{

/*
  printf("\nc2z_file.c c2_getchar_punch rct = %d p_string = %s", rct, p_string);
  printf("c2z_file.c c2_getchar_punch NEED TO CODE\n");

*/
  if (traceflg == 1) 
  {
    strcpy(trace_1, "\nc2z_file.c c2_getchar_punch START");
    trace_rec_1();
  }
  convert = 1;
  return;
}
