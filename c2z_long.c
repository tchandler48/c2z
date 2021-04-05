/* ***************************************************
*  c2z  : c2z_long.c                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* ***************************************************
*  Punch out LONG                                    *
* ************************************************** */
void c2_long() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_long.c c2_long START");
    trace_rec_1();
  }

  convert = 1;
}

void c2_long_pass2() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_long.c c2_long_pass2 START");
    trace_rec_1();
  }

  char ch, *p, *p1;
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];

  int pi = 0;
  int pi2 = 0;
  int pi3 = 0;
  int x3 = 0;
  int x4 = 0;
  int x8 = 0;
  int I = 0;
  int s = 0;
  int ret = 0;
  int ret1 = 0;
  int size = 0;
  int comma_ct = 0;

  comma_ct = 0;

  p = strstr(p_string, ",");
  if (p) 
  {
    comma_ct = 1;
  }
  pi = 0;
  pi2 = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch != ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  if (comma_ct == 0) 
  {
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ';') 
    {
      if (ch != '*') 
      {
        if(ch != ' ')
        {
          field2[pi2] = ch;
          pi2++;
        }
      }
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';
 

    p1 = strstr(field2, "(long)");
    if(p1)
    {
      pi3 = 0;
      pi2 = 0;
      s = strlen(field2);
      ch = field2[pi3];
      while(ch != ')')
      {
        pi3++;
        ch = field2[pi3];
      }
      pi3++;
      ch = field2[pi3];
      while(pi3 < s)
      {
        if(ch != '(')
        {
          if(ch != ')')
          {
            field2a[pi2] = ch;
            pi2++;
          }
        }
        pi3++;
        ch = field2[pi3];
      }
      field2a[pi2] = '\0';
      strcpy(field2, field2a);
    }
  }

  if (comma_ct == 1) 
  {
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if (ch != '*') 
      {
        field2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ';') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

  }
  
  if (comma_ct == 0) 
  {
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    x4 = strlen(c_wkname);
    c_wkname[x4] = '\0';
    strcpy(field2a, c_wkname);

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
          x3 = 1;
        }
      }
    }


    if ((global_st == 0) && (x3 == 0)) 
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
      strcpy(gw_variable[gv_ct].gv_cname, field2a);
      strcpy(gw_variable[gv_ct].gv_name, field2);
      strcpy(gw_variable[gv_ct].gv_type, "I");
      gw_variable[gv_ct].gv_lgth = 0;
      gw_variable[gv_ct].gv_current_lgth = 0;
      strcpy(gw_variable[gv_ct].gv_value, "0");
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
      x3 = 1;
    }

    if ((global_st == 1) && (x3 == 0)) 
    {

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
            x3 = 1;
          }
        }
      }

      if (x3 == 0) 
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
        strcpy(lw_variable[lv_ct].lv_cname, field2a);
        strcpy(lw_variable[lv_ct].lv_name, field2);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        lw_variable[lv_ct].lv_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, "0");
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_init = 0;
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        lw_variable[lv_ct].lv_use_ct = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lv_ct++;
        x8++;
      }
    }
  }

  if (comma_ct == 1) 
  {
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    x4 = strlen(c_wkname);
    c_wkname[x4] = '\0';
    strcpy(field2a, c_wkname);

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
          x3 = 1;
        }
      }
    }

    if ((global_st == 0) && (x3 == 0)) 
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
      strcpy(gw_variable[gv_ct].gv_cname, field2a);
      strcpy(gw_variable[gv_ct].gv_name, field2);
      strcpy(gw_variable[gv_ct].gv_type, "I");
      gw_variable[gv_ct].gv_lgth = 0;
      gw_variable[gv_ct].gv_current_lgth = 0;
      strcpy(gw_variable[gv_ct].gv_value, "0");
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
      x3 = 1;
    }

    if ((global_st == 1) && (x3 == 0)) 
    {

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
            x3 = 1;
          }
        }
      }

      if (x3 == 0) 
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
        strcpy(lw_variable[lv_ct].lv_cname, field2a);
        strcpy(lw_variable[lv_ct].lv_name, field2);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        lw_variable[lv_ct].lv_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, "0");
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_init = 0;
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        lw_variable[lv_ct].lv_use_ct = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lv_ct++;
        x8++;
      }
    }

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    x4 = strlen(c_wkname);
    c_wkname[x4] = '\0';
    strcpy(field3a, c_wkname);

    x3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strcpy(field3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field3, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(field3a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x3 = 1;
        }
      }
    }

    if ((global_st == 0) && (x3 == 0)) 
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
      strcpy(gw_variable[gv_ct].gv_cname, field3a);
      strcpy(gw_variable[gv_ct].gv_name, field3);
      strcpy(gw_variable[gv_ct].gv_type, "I");
      gw_variable[gv_ct].gv_lgth = 0;
      gw_variable[gv_ct].gv_current_lgth = 0;
      strcpy(gw_variable[gv_ct].gv_value, "0");
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
      x3 = 1;
    }

    if ((global_st == 1) && (x3 == 0)) 
    {

      x3 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field3, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            strcpy(field3a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
            x3 = 1;
          }
        }
      }

      if (x3 == 0) 
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
        strcpy(lw_variable[lv_ct].lv_cname, field3a);
        strcpy(lw_variable[lv_ct].lv_name, field3);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        lw_variable[lv_ct].lv_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, "0");
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_init = 0;
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        lw_variable[lv_ct].lv_use_ct = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lv_ct++;
        x8++;
      }
    }
  }
  convert = 1;
}
