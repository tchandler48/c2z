/* ***************************************************
*  c2z : c2_double.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Scan test for DOUBLE                              *
**************************************************** */
void c2_double() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_double.c 2 c2_double START");
    trace_rec_1();
  }

  char ch, *p, *p1, *p2;
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];

  int s = 0;
  int v = 0;
  int z3 = 0;
  int x3 = 0;
  int x10 = 0;
  int x11 = 0;
  int x100 = 0;
  int fd3_type = 0;
  int size = 0;
  int pi;
  int pi2;
  int ret = 0;
  int I = 0;
  int ret1 = 0;

  p = strstr(p_string, "(double)");
  if(p)
  {
    convert = 1;
    return;
  }

  tfield2a[0] = '\0';

  tot_malloc++;

  x10 = 0;
  x100 = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == ';') 
    {
      break;
    }
    if (ch == ',') 
    {
      x10++;
    }
    if(ch == '[')
    {
      x100++;
    }
    if(ch == ']')
    {
      x100++;
    }
    if (isdigit(ch) == 1) 
    {
      x11++;
    }
  }

  if(x100 == 4)
  {
    c2_dbl_41();
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
  ch = p_string[pi];
  while (ch != ' ') 
  {
/*    tfield1[pi2] = ch;
    pi2++; */
    pi++;
    ch = p_string[pi];
  }
/*  tfield1[pi2] = '\0'; */

  p = strstr(p_string, "=");
  p1 = strstr(p_string, "*");

  if ((!p) && (!p1)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_double.c 2 c2_double subroutine #1 START");
      trace_rec_1();
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    if (x10 == 0) {
      while (ch != ';') 
      {
        if (ch != '*') 
        {
          tfield2[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield2[pi2] = '\0';
    }

    if (x10 == 1) 
    {
      while (ch != ',') 
      {
        if (ch != '*') 
        {
          tfield2[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield2[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      pi2 = 0;
      while (ch != ';') 
      {
        if (ch != '*') 
        {
          if (ch != ' ') 
          {
            tfield3[pi2] = ch;
            pi2++;
          }
        }
        pi++;
        ch = p_string[pi];
      }
      tfield3[pi2] = '\0';
    }

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield2a, c_wkname);

    if (global_st == 0) /*				global variable	*/
    {
      z3 = 0;
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(tfield2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          z3 = 1;
          break;
        }
      }

      if (z3 == 0) 
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
        strcpy(gw_variable[gv_ct].gv_type, "I");
        gw_variable[gv_ct].gv_lgth = 0;
        gw_variable[gv_ct].gv_current_lgth = 0;
        strcpy(gw_variable[gv_ct].gv_value, null_field);
        gw_variable[gv_ct].gv_init = 0;
        strcpy(gw_variable[gv_ct].gv_literal, null_field);
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
        strcpy(gw_variable[gv_ct].gv_st_col, null_field);
        gw_variable[gv_ct].gv_flag = 0;
        gw_variable[gv_ct].gv_dec = 0;
        gw_variable[gv_ct].gv_id = 2;
        gv_ct++;


      }
    }		 /* global_st == 0   */

    if (global_st == 1) 			/*	local variable	*/
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
            strcpy(tfield2a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
            x3 = 1;
            break;
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
        strcpy(lw_variable[lv_ct].lv_cname, tfield2a);
        strcpy(lw_variable[lv_ct].lv_name, tfield2);
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        lw_variable[lv_ct].lv_lgth = 0;
        lw_variable[lv_ct].lv_current_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, "0");
        lw_variable[lv_ct].lv_init = 0;
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        lw_variable[lv_ct].lv_use_ct = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 2;
        lv_ct++;
      }
    } 			/* global_st == 1 */

    if (x10 == 1) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_double.c 2 c2_double subroutine #2 START");
        trace_rec_1();
      }

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(tfield3a, c_wkname);

      if (global_st == 0) 				/*	global variable	*/
      {
        z3 = 0;
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield3, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            z3 = 1;
            break;
          }
        }

        if (z3 == 0) 
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
          strcpy(gw_variable[gv_ct].gv_cname, tfield3a);
          strcpy(gw_variable[gv_ct].gv_name, tfield3);
          strcpy(gw_variable[gv_ct].gv_type, "I");
          gw_variable[gv_ct].gv_lgth = 0;
          gw_variable[gv_ct].gv_current_lgth = 0;
          strcpy(gw_variable[gv_ct].gv_value, null_field);
          gw_variable[gv_ct].gv_init = 0;
          strcpy(gw_variable[gv_ct].gv_literal, null_field);
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
          strcpy(gw_variable[gv_ct].gv_st_col, null_field);
          gw_variable[gv_ct].gv_flag = 0;
          gw_variable[gv_ct].gv_dec = 0;
          gw_variable[gv_ct].gv_id = 2;
        }
      } 			/* global_st == 0   */

      if (global_st == 1) 			/*	local variable	*/
      {
        x3 = 0;
        if (lv_ct > 0) 
        {
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(tfield3, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              strcpy(tfield3a, lw_variable[I].lv_cname);
              lw_variable[I].lv_use_ct++;
              x3 = 1;
              break;
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
          strcpy(lw_variable[lv_ct].lv_cname, tfield3a);
          strcpy(lw_variable[lv_ct].lv_name, tfield3);
          strcpy(lw_variable[lv_ct].lv_type, "I");
          strcpy(lw_variable[lv_ct].lv_func, sv_func);
          lw_variable[lv_ct].lv_lgth = 0;
          strcpy(lw_variable[lv_ct].lv_value, "0");
          lw_variable[lv_ct].lv_current_lgth = 0;
          lw_variable[lv_ct].lv_init = 0;
          strcpy(lw_variable[lv_ct].lv_literal, null_field);
          lw_variable[lv_ct].lv_use_ct = 0;
          lw_variable[lv_ct].lv_dec = 0;
          lw_variable[lv_ct].lv_id = 2;
          lv_ct++;
        }
      } 				/* global_st == 1 */
    }

    convert = 1;
    return;
  }

  if (p1) 				/* double array */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_double.c 2 c2_double subroutine #3 START");
      trace_rec_1();
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ';') 
    {
      if (ch != '*') 
      {
        tfield2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield2a, c_wkname);

    if (global_st == 0) 			/*	global variable	*/
    {
      z3 = 0;
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(tfield2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          z3 = 1;
          break;
        }
      }

      if (z3 == 0) 
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
        strcpy(gw_variable[gv_ct].gv_type, "G");
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

        /* number of rows in the **array		*/
        gw_variable[gv_ct].gv_row = 250;

        snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
        strcpy(wk_string, "A37");
        strcat(wk_string, wk_strg);
        strcat(wk_string, "A");
        strcpy(gw_variable[gv_ct].gv_aname, wk_string);
	 gw_variable[gv_ct].gv_id = 4;

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
        gw_variable[gv_ct].gv_id = 0;
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
        strcpy(gw_variable[gv_ct].gv_type, "I");
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
        gw_variable[gv_ct].gv_id = 0;
        gv_ct++;

        convert = 1;
      }
    }
  }

  if (p)			 /* Equal Sign */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_double.c 2 c2_double subroutine #4 START");
      trace_rec_1();
    }

    p2 = strstr(p_string, "(double)");
    if (p2) 
    {
      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      x3 = 0;
      fd3_type = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ';') 
      {
        if ((isdigit(ch)) && (x3 == 0)) 
        {
          fd3_type = 2;
          x3 = 1;
        }
        if ((isalpha(ch)) && (x3 == 0)) 
        {
          fd3_type = 1;
          x3 = 1;
        }
        tfield3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield3[pi2] = '\0';

      convert = 1;
      return;
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '=') 
    {
      if (ch != ' ') 
      {
        if (ch != '*') 
        {
          tfield2[pi2] = ch;
          pi2++;
        }
      }
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    pi2 = 0;
    x3 = 0;
    fd3_type = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ';') 
    {
      if ((isdigit(ch)) && (x3 == 0)) 
      {
        fd3_type = 2;
        x3 = 1;
      }
      if ((isalpha(ch)) && (x3 == 0)) 
      {
        fd3_type = 1;
        x3 = 1;
      }
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    if (fd3_type == 0) 
    {
      printf("c2z_double.c c2_double fd3_type == 0 NOT CODED\n");
    }

    if (fd3_type == 1) 
    {
      printf("c2z_double.c c2_double fd3_type == 1 NOT CODED\n");
    }

    if (fd3_type == 2) 
    {
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(tfield2a, c_wkname);

      if (global_st == 0) 			/*	global variable	*/
      {
        z3 = 0;
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield2, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            z3 = 1;
            break;
          }
        }

        if (z3 == 0) 
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
          strcpy(gw_variable[gv_ct].gv_type, "I");
          gw_variable[gv_ct].gv_lgth = 0;
          gw_variable[gv_ct].gv_current_lgth = 0;
          strcpy(gw_variable[gv_ct].gv_value, null_field);
          gw_variable[gv_ct].gv_init = 0;
          strcpy(gw_variable[gv_ct].gv_literal, null_field);
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
          gw_variable[gv_ct].gv_id = 1;
          gv_ct++;
        }
      } 			/* global_st == 0   */

      if (global_st == 1) 		/*	local variable	*/
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
              strcpy(tfield2a, lw_variable[I].lv_cname);
              lw_variable[I].lv_use_ct++;
              x3 = 1;
              break;
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
          strcpy(lw_variable[lv_ct].lv_cname, tfield2a);
          strcpy(lw_variable[lv_ct].lv_name, tfield2);
          strcpy(lw_variable[lv_ct].lv_type, "I");
          strcpy(lw_variable[lv_ct].lv_func, sv_func);
          lw_variable[lv_ct].lv_lgth = 0;
          strcpy(lw_variable[lv_ct].lv_value, "0");
          lw_variable[lv_ct].lv_current_lgth = 0;
          lw_variable[lv_ct].lv_init = 0;
          strcpy(lw_variable[lv_ct].lv_literal, null_field);
          lw_variable[lv_ct].lv_use_ct = 0;
          lw_variable[lv_ct].lv_dec = 0;
          lw_variable[lv_ct].lv_id = 1;
          lv_ct++;
        }
      } 			/* global_st == 1 */
    }

    convert = 1;
    return;
  }
}


void c2_pass_2_double() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_doublec 2 c2_pass_2_double START");
    trace_rec_1();
  }

  char ch;
  char field2[VAR_LGTH];

  int pi = 0;
  int pi2 = 0;

  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch != ' ') 
  {
    pi2++;
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != '(') 
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
  strcpy(sv_func, field2);

  convert = 1;
}


void c2_double_punch() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_double.c c2_double_punch START");
    trace_rec_1();
  }

  int pi;
  int pi2;
  int x3;
  int I;
  int ret;
  int x2;
  int x10;
  int x11;
  int x100;
  int s;

  char ch, *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  x10 = 0;
  x100 = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == ';') 
    {
      break;
    }
    if (ch == ',') 
    {
      x10++;
    }
    if(ch == '[')
    {
      x100++;
    }
    if(ch == ']')
    {
      x100++;
    }
    if (isdigit(ch) == 1) 
    {
      x11++;
    }
  }

  if(x100 == 4)
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

  while(ch != ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ' ')
  {
    if(ch == ';')
    {
      break;   
    }
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  p = strstr(field1, "*");
  if(p)
  {
    convert = 1;
    return;
  }

  p = strstr(field1, "=");
  if(p)
  {
    convert = 0;
    return;
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    x2 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x2 == 0)) 
    {
      x3 = 1;
      strcpy(field1a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
      break;
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
        break;
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
    strcpy(trace_1, "c2z_double.c c2_double_punch #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_double.c c2_double_punch #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_double.c c2_double_punch #3");
    trace_rec_3();
  }
}


void c2_dbl_41()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_int.c 2 c2_dbl_41 START");
    trace_rec_1();
  }

   int pi;
   int x1;
   int x2;
   int x3;
   int x101;
   int x102;
   int ret;
   int ret1;
   int s;
   int size;
   int v;
   int fd2_type;
   int fd3_type;

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char wk_name[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while((ch == ' ') || (ch == '\t'))
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

  x3 = 0;
  for (v = 0; v < lv_ct; v++) 
  {
    ret = strcmp(field1, lw_variable[v].lv_name);
    ret1 = strcmp(sv_func, lw_variable[v].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      break;
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
        break;
      }
    }
  }

  if (x3 == 1) 
  {
    printf("\nc2z_double.c c2_dbl_41 E-003 field1 Duplicate field1 Found = %s\n", field1);
    printf("c2z_double.c c2_dbl_41 rct = %d p_string = %s", rct, p_string);
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
        break;
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_double.c c2_dbl_41 E-001 field2 Not Found = %s\n", field2);
      printf("c2z_double.c c2_dbl_41 rct = %d p_string = %s", rct, p_string);
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
        break;
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_double.c c2_dbl_41 E-002 field3 Not Found = %s\n", field3);
      printf("c2z_double.c c2_dbl_41 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  tot_malloc++;

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
    gw_variable[gv_ct].gv_column = 0;
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
    strcpy(gw_variable[gv_ct].gv_name, field1);
    strcpy(gw_variable[gv_ct].gv_type, "G");
    gw_variable[gv_ct].gv_init = 0;
    gw_variable[gv_ct].gv_use_ct = 0;
    gw_variable[gv_ct].gv_dec = 0;
    strcpy(gw_variable[gv_ct].gv_st_col, wk_name);

    if((fd2_type == 1) && (fd3_type == 1))
    {
      x101 = atoi(field2);
      x102 = atoi(field3);
      gw_variable[gv_ct].gv_row = x101;
      gw_variable[gv_ct].gv_column = x102;
    }

    if((fd2_type == 2) && (fd3_type == 2))
    {
      x101 = atoi(field2a);
      x102 = atoi(field3a);
      gw_variable[gv_ct].gv_row = x101;
      gw_variable[gv_ct].gv_column = x102;
    }

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
    gw_variable[gv_ct].gv_id = 4;
    gv_ct++;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

    /* add this wk_string to w_variable as type = B */
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
    strcpy(gw_variable[gv_ct].gv_type, "I");
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

  }
  convert = 1;
}


