/* ***************************************************
*  c2z  : c2z_float.c                                *
*                                                    *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* ***************************************************
*  Punch out FLOAT                                    *
* ************************************************** */
void c2_float() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_doublec 2 c2_float START");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  int s = 0;
  int v = 0;
  int z3 = 0;
  int size = 0;
  int pi;
  int pi2;
  int ret = 0;

  tfield2a[0] = '\0';

  tot_malloc++;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while (ch != ' ') 
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

  if (global_st == 0) /*	global variable	*/
  {
    z3 = 0;
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(tfield1, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        z3 = 1;
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

      convert = 1;
    }
  }
}
