/* ***************************************************
*  c2z : c2z_u_short.c :                             *
*                                                    *
*  next error - u_short-001                          *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

void c2_u_short()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.U-short.c c2_u_short START");
    trace_rec_1();
  }

   int pi;
   int pi2;
   int I;
   int ret;
   int ret1;
   int x3;
   int size;
   int s;

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];


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
printf("c2z.u_short.c c2_u_short rct = %d field1 = %s\n",rct,field1);


  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';
printf("c2z.u_short.c c2_u_short rct = %d field2 = %s\n",rct,field2);

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
    strcpy(field2a, c_wkname);

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
      strcpy(gw_variable[gv_ct].gv_name, field2);
      strcpy(gw_variable[gv_ct].gv_cname, field2a);
      strcpy(gw_variable[gv_ct].gv_type, "U");
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
      strcpy(lw_variable[lv_ct].lv_cname, field2a);
      strcpy(lw_variable[lv_ct].lv_name, field2);
      strcpy(lw_variable[lv_ct].lv_type, "U");
      lw_variable[lv_ct].lv_lgth = 0;
      strcpy(lw_variable[lv_ct].lv_value, null_field);
      lw_variable[lv_ct].lv_use_ct = 0;
      strcpy(lw_variable[lv_ct].lv_func, sv_func);
      strcpy(lw_variable[lv_ct].lv_literal, null_field);
      lw_variable[lv_ct].lv_current_lgth = 0;
      lw_variable[lv_ct].lv_dec = 0;
      lw_variable[lv_ct].lv_id = 1;
      lw_variable[lv_ct].lv_init = 0;
      lv_ct++;
    }
  }
  convert = 1;
}


