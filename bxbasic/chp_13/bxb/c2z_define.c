/* ***************************************************
*  c2z  : c2z_define.c                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* ***************************************************
*  Scan for #DEFINE                                  *
* ************************************************** */
void c2_define() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_define.c c2_define START");
    trace_rec_1();
  }

  char ch, *p, *p2;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  int pi;
  int pi2;
  int s = 0;
  int x2 = 0;
  int x3 = 0;
  int x90 = 0;
  int v = 0;
  int size = 0;
  int left_bracket = 0;
  int ret = 0;
  int ret1 = 0;
  int fd2_type = 0;

  var_use[17]++;

  x90 = 0;
  p = strstr(p_string, "0x");
  if (p) 
  {
    x90 = 1;
  }

  if (x90 == 0) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_define.c c2_define x90 = 0");
      trace_rec_1();
    }

    pi = 0; 
    ch = p_string[pi];  
    while ((ch == ' ') || (ch == '\t') || (ch == '{'))
    {
      ch = p_string[pi];  
      pi++;
    }

    while(ch != ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      ch = p_string[pi];  
      pi++;
    }
    
    pi--;
    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ')
    {
      if (ch == '[') 
      {
        left_bracket = 1;
        break;
      }
      if (ch == '\t') 
      {
        break;
      }

      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    p2 = strstr(p_string, "\"");
    if(p2)
    {
      pi2 = 0;
      s = strlen(p_string);
      pi++;
      pi++;
      ch = p_string[pi];
      while ((pi < s) && (ch != '"')) 
      {
        if(ch == '"')
        {
          break;
        }
        if(ch != '\r')
        {
          if(ch != '\n')
          {
            tfield2[pi2] = ch;
            pi2++;
          }
        }
        pi++;
        ch = p_string[pi];
      }
      tfield2[pi2] = '\0';

      x3 = 0;
      if (global_st == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
          }
        }
      }

      if (x3 == 0) 
      {
        if (global_st == 1) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(tfield1, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x3 = 1;
            }
          }
        }
      }

      if(x3 == 0)
      {
        c_name++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
        strcpy(c_wkname, "C37F");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(tfield1a, c_wkname);
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
        strcpy(gw_variable[gv_ct].gv_name, tfield1);
        strcpy(gw_variable[gv_ct].gv_cname, tfield1a);
        strcpy(gw_variable[gv_ct].gv_type, "C");
        gw_variable[gv_ct].gv_lgth = atoi(tfield2);
        strcpy(gw_variable[gv_ct].gv_value, tfield2);
        strcpy(gw_variable[gv_ct].gv_literal, null_field);
        gw_variable[gv_ct].gv_dec = 0;
        gw_variable[gv_ct].gv_id = 1;
        gv_ct++;
      }

      if ((global_st == 1) && (x3 == 0)) 
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
        
        lw_variable[lv_ct].lv_lgth = atoi(tfield2);
        lw_variable[lv_ct].lv_current_lgth = atoi(tfield2);
        strcpy(lw_variable[lv_ct].lv_value, tfield2);
        lw_variable[lv_ct].lv_init = 0;
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        lw_variable[lv_ct].lv_use_ct = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 1;
        lv_ct++;
      }
    convert = 1;
    return;
    }    

    if (left_bracket == 0) 
    {
      while ((ch == ' ')  || (ch == '{'))
      {
        pi++;
        ch = p_string[pi];
      }
     
      x2 = 0;
      pi2 = 0;
      ch = p_string[pi];
      s = strlen(p_string);
      s--;
      while(pi < s)
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd2_type = 1;
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
            fd2_type = 2;
            x2 = 1;
          }
        }
        if(ch != '\t')
        {
          tfield2[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield2[pi2] = '\0';

      if(fd2_type == 2)
      {
        x3 = 0;
        if (global_st == 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(tfield1, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
            }
          }
        }

        if (x3 == 0) 
        {
          if (global_st == 1) 
          {
            for (v = 0; v < lv_ct; v++) 
            {
              ret = strcmp(tfield1, lw_variable[v].lv_name);
              ret1 = strcmp(sv_func, lw_variable[v].lv_func);
              if ((ret == 0) && (ret1 == 0)) 
              {
                x3 = 1;
              }
            }
          }
        }

        if(x3 == 0)
        {
          c_name++;
          snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
          strcpy(c_wkname, "C37F");
          strcat(c_wkname, wk_strg);
          s = strlen(c_wkname);
          c_wkname[s] = '\0';
          strcpy(tfield1a, c_wkname);

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
            strcpy(gw_variable[gv_ct].gv_name, tfield1);
            strcpy(gw_variable[gv_ct].gv_cname, tfield1a);
            strcpy(gw_variable[gv_ct].gv_type, "I");
            gw_variable[gv_ct].gv_lgth = 0;
            strcpy(gw_variable[gv_ct].gv_value, tfield2);
            strcpy(gw_variable[gv_ct].gv_literal, null_field);
            gw_variable[gv_ct].gv_use_ct = 0;
            gw_variable[gv_ct].gv_dec = 0;
            gw_variable[gv_ct].gv_id = 1;
            gv_ct++;
          }
        }

        if ((global_st == 1) && (x3 == 0)) 
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
          strcpy(lw_variable[lv_ct].lv_type, "I");
          lw_variable[lv_ct].lv_lgth = 0;
          lw_variable[lv_ct].lv_current_lgth = 0;
          strcpy(lw_variable[lv_ct].lv_value, tfield2);
          lw_variable[lv_ct].lv_init = 0;
          strcpy(lw_variable[lv_ct].lv_literal, null_field);
          strcpy(lw_variable[lv_ct].lv_func, sv_func);
          lw_variable[lv_ct].lv_use_ct = 0;
          lw_variable[lv_ct].lv_dec = 0;
          lw_variable[lv_ct].lv_id = 1;
          lv_ct++;
        }
      }
      convert = 1;
      return;
    }

    if (left_bracket == 1) 
    {
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ']') 
      {
        tfield2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield2[pi2] = '\0';

      x3 = 0;
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(tfield2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, gw_variable[v].gv_value);
        }
      }

      x3 = 0;
      if (global_st == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
          }
        }
      }

      if (x3 == 0) 
      {
        if (global_st == 1) 
        {
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(tfield1, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x3 = 1;
            }
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
        strcpy(gw_variable[gv_ct].gv_name, tfield1);
        strcpy(gw_variable[gv_ct].gv_cname, tfield1a);
        strcpy(gw_variable[gv_ct].gv_type, "I");
        gw_variable[gv_ct].gv_lgth = 0;
        strcpy(gw_variable[gv_ct].gv_value, tfield2);
        strcpy(gw_variable[gv_ct].gv_literal, null_field);
        gw_variable[gv_ct].gv_use_ct = 0;
        gw_variable[gv_ct].gv_dec = 0;
        gw_variable[gv_ct].gv_id = 1;
        gv_ct++;
      }

      if ((global_st == 1) && (x3 == 0)) 
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
        strcpy(lw_variable[lv_ct].lv_type, "I");
        lw_variable[lv_ct].lv_lgth = 0;
        lw_variable[lv_ct].lv_current_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, tfield2);
        lw_variable[lv_ct].lv_init = 0;
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        lw_variable[lv_ct].lv_use_ct = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 1;
        lv_ct++;
      }
    }
  }

  if (x90 == 1) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_define.c c2_define x90 = 1");
      trace_rec_1();
    }

    pi = 0;
    pi2 = 0;
    found_space = 0;
    found_space2 = 0;
    s = strlen(p_string);
    while (ch != ' ') 
    {
      ch = p_string[pi];
      if ((ch != ' ') && (found_space == 0)) 
      {

      } 
      else 
      {
        found_space = 1;
      }
      pi++;
    }

    ch = p_string[pi];
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
    while ((ch != ' ') && (pi < s) && (ch != '\t')) 
    {
      if (ch == '[') 
      {
        left_bracket = 1;
        break;
      }
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    while ((ch == ' ') || (ch == '\t')) 
    {
      pi++;
      ch = p_string[pi];
    }
    pi2 = 0;
    skip = 0;
    s = strlen(p_string);
    pi++;
    pi++;
    ch = p_string[pi];
    while ((ch != ' ') && (pi < s) && (skip != 1)) 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
      if (ch == '\n')
      {
        skip = 1;
      }
      if (ch == '\t')
      {
        skip = 1;
      }
    }
    tfield2[pi2] = '\0';

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
      strcpy(gw_variable[gv_ct].gv_name, tfield1);
      strcpy(gw_variable[gv_ct].gv_cname, tfield1a);
      strcpy(gw_variable[gv_ct].gv_type, "X");
      gw_variable[gv_ct].gv_lgth = 0;
      strcpy(gw_variable[gv_ct].gv_value, tfield2);
      strcpy(gw_variable[gv_ct].gv_literal, null_field);
      gw_variable[gv_ct].gv_dec = 0;
      gw_variable[gv_ct].gv_id = 4;
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
      strcpy(lw_variable[lv_ct].lv_type, "X");
      lw_variable[lv_ct].lv_lgth = 0;
      lw_variable[lv_ct].lv_current_lgth = 0;
      strcpy(lw_variable[lv_ct].lv_value, tfield2);
      lw_variable[lv_ct].lv_init = 0;
      strcpy(lw_variable[lv_ct].lv_literal, null_field);
      strcpy(lw_variable[lv_ct].lv_func, sv_func);
      lw_variable[lv_ct].lv_use_ct = 0;
      lw_variable[lv_ct].lv_dec = 0;
      lw_variable[lv_ct].lv_id = 4;
      lv_ct++;
    }
  }

  convert = 1;
}

void c2_ifndef(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_define.c c2_ifndef START");
    trace_rec_1();
  }

  char field2[VAR_LGTH];
  char ch;

  int pi = 0;
  int pi2 = 0;
  int ret = 0;
  int x3 = 0;
  int I = 0;
  int s;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch != ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ' ') 
  {
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  s = strlen(field2);
  field2[s - 1] = '\0';

  x3 = 0;
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcasecmp(field2, gw_variable[I].gv_name);
    if (ret == 0) 
    {
      gw_variable[I].gv_use_ct++;
      x3 = 1;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcasecmp(field2, lw_variable[I].lv_name);
      if (ret == 0) 
      {
        lw_variable[I].lv_use_ct++;
        x3 = 1;
      }
    }
  }

  if (x3 == 1) 
  {
    def_it = 2;
  }
  convert = 1;
}


void c2_endif(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_define.c c2_endif");
    trace_rec_1();
  }

  def_it = 1;
  convert = 1;
}
