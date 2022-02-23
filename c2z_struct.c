/* ***************************************************
*  c2z : c2z_struct.c :                              *
*                                                    *
*  next error - struct-009                           *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */
void c2z_struct(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_struct.c c2z_struct");
    trace_rec_1();
  }

  if (debug_lv >= 3) 
  {
    printf("c2z_struct.c c2_struct rct = %d START\n", rct);
  }

  char *p, *p2, *p3, *p4, *p6, *p7;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield8a[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield9a[VAR_LGTH];

  int pi;
  int pi2;
  int s = 0;
  int v = 0;
  int z3 = 0;
  int ret1 = 0;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x20 = 0;
  int x80 = 0;
  int x90 = 0;
  int size = 0;
  int I = 0;
  int ret = 0;
  int fd5_type = 0;

  if (debug_lv >= 3) 
  {
    printf("c2z_struct.c c2_struct rct = %d subroutine #1\n", rct);
  }

  pi = 0;
  ch = p_string[pi];
  while (ch == ' ') 
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
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ' ') 
  {
    if (ch == '[') 
    {
      break;
    }
    if (ch != '\n') 
    {
      if (ch != '\t') 
      {
        tfield2[pi2] = ch;
        pi2++;
      }
    }
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  p2 = strstr(p_string, ";");
  if (p2) 
  {
    goto struct_1;
  }

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  x4 = strlen(c_wkname);
  c_wkname[x4] = '\0';
  strcpy(tfield2a, c_wkname);

  if (m_struc_ct == 0) 
  {
    size = 1;
    w_struc = malloc(size * sizeof(struct m_struc));
  } 
  else 
  {
    size = m_struc_ct + 1;
    w_struc = realloc(w_struc, size * sizeof(struct m_struc));
  }

  w_struc[m_struc_ct].st_rct = rct;
  strcpy(w_struc[m_struc_ct].st_name, tfield2);
  strcpy(w_struc[m_struc_ct].st_id, "M");
  w_struc[m_struc_ct].st_disp = 0;
  strcpy(w_struc[m_struc_ct].st_wname, tfield2);
  strcpy(w_struc[m_struc_ct].st_cname, tfield2a);
  strcpy(w_struc[m_struc_ct].st_cwname, tfield2a);
  strcpy(w_struc[m_struc_ct].st_func, null_field);
  strcpy(w_struc[m_struc_ct].st_type, null_field);
  strcpy(w_struc[m_struc_ct].st_field_name, null_field);
  strcpy(w_struc[m_struc_ct].st_field_cname, null_field);
  w_struc[m_struc_ct].st_field_lgth = 0;
  strcpy(w_struc[m_struc_ct].st_field_value, null_field);
  m_struc_ct++;

  strcpy(tfield99,tfield2a);
  
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
  strcpy(gw_variable[gv_ct].gv_name, tfield2);
  strcpy(gw_variable[gv_ct].gv_type, "M");
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

  strcpy(gw_variable[gv_ct].gv_table, tfield2a);
  strcat(gw_variable[gv_ct].gv_table, "T");

  strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
  strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
  strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
  gw_variable[gv_ct].gv_dec = 0;
  gv_ct++;

  goto struct_2;

/*
  char gv_label[VAR_LGTH];
  char gv_table[VAR_LGTH];
  char gv_aname[VAR_LGTH];
  char gv_sv_reg[VAR_LGTH];
  char gv_wk_reg[VAR_LGTH];
  char gv_wk_strg[VAR_LGTH];
*/

/* *********************************************************
*  parse the following: struct variables    *gw_variables  *
* ******************************************************** */
struct_1:

  if (debug_lv >= 3) 
  {
    printf("c2z_struct.c c2_struct rct = %d subroutine #2\n", rct);
  }

  x2 = 0;
  p2 = strstr(p_string, "/*");

  p3 = strstr(p_string, "*");
  if (p3) 
  {
    x2 = p3 - p_string;
  }

  ch = p_string[pi];
  while (ch != '*') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ';') 
  {
    tfield5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield5[pi2] = '\0';

  p = strstr(tfield5, "[");
  if (p) 
  {
    if (debug_lv >= 3) 
    {
      printf("c2z_struct.c c2_struct rct = %d subroutine #3\n", rct);
    }

    pi2 = 0;
    pi = 0;
    ch = tfield5[pi];
    while (ch != '[') 
    {
      tfield9[pi2] = ch;
      pi2++;
      pi++;
      ch = tfield5[pi];
    }
    tfield9[pi2] = '\0';

    pi++;
    ch = tfield5[pi];
    while (ch != ']') 
    {
      pi++;
      ch = tfield5[pi];
    }

    strcpy(tfield5, tfield9);

    tot_malloc++;
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield9a, c_wkname);

    if (global_st == 0) 		/*	global variable	*/
    {
      z3 = 0;
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(tfield9, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          z3 = 1;
        }
      }

      if (z3 == 0) 
      {
        if (debug_lv >= 3) 
        {
          printf("c2z_struct.c c2_struct rct = %d subroutine #4\n", rct);
        }

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
        strcpy(gw_variable[gv_ct].gv_cname, tfield9a);
        strcpy(gw_variable[gv_ct].gv_name, tfield9);
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
  if(!p)
  {
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    x4 = strlen(c_wkname);
    c_wkname[x4] = '\0';
  
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
    strcpy(gw_variable[gv_ct].gv_name, tfield5);
    strcpy(gw_variable[gv_ct].gv_type, "M");
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
    gv_ct++;;
    convert = 1;
  }
  
  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  x4 = strlen(c_wkname);
  c_wkname[x4] = '\0';
  strcpy(tfield8a, c_wkname);

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(tfield2, w_struc[I].st_name);
    if (ret == 0) 
    {
      x3 = 1;
      strcpy(w_struc[I].st_wname, tfield5);
      strcpy(w_struc[I].st_cwname, tfield8a);
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_struct.c c2_struc struct-001 tfield2 Not Found = %s\n", tfield2);
    printf("c2z_struct.c c2_struc rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  convert = 1;
  return;

/* **************************************************
*  detail records for structures			   *
*************************************************** */
struct_2:

  if (debug_lv >= 3) 
  {
    printf("c2z_struct.c c2_struct rct = %d subroutine #5\n", rct);
  }

  fgets(p_string, 255, pgm);
  rct++;

  if (debug_lv >= 1) 
  {
    printf("\nc2z.c Pass 2 struct rct = %d L1 p_string = %s", rct, p_string);
  }

  p7 = strstr(p_string, "};");
  if (p7) 
  {
    goto struct_3;
  }

  p6 = strstr(p_string, "{");
  if (p6) 
  {
    goto struct_2;
  }

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  for (I = 0; I < 4; I++) 
  {
    ch = p_string[pi];
    tfield1[pi2] = ch;
    pi2++;
    pi++;
  }
  tfield1[pi2] = '\0';

  x80 = 0;

  ret = strcmp(tfield1, "char");
  if (ret == 0) 
  {
    x80 = 1;
  }

  p= strstr(tfield1, "int");
  if (p) 
  {
    x80 = 2;
  }

  ret = strcmp(tfield1, "long");
  if (ret == 0) 
  {
    x80 = 3;
  }

  ret = strcmp(tfield1, "floa");
  if (ret == 0) 
  {
    x80 = 4;
  }

  ret = strcmp(tfield1, "doub");
  if (ret == 0) 
  {
    x80 = 5;
  }

  ret = strcmp(tfield1, "FILE");
  if (ret == 0) 
  {
    x80 = 6;
  }

  ret = strcmp(tfield1, "sa_f");
  if (ret == 0) 
  {
    x80 = 8;
  }

  ret = strcmp(tfield1, "uint");
  if (ret == 0) 
  {
    x80 = 9;
  }

  ret = strcmp(tfield1, "in_p");
  if (ret == 0) 
  {
    x80 = 9;
  }

  ret = strcmp(tfield1, "stru");
  if (ret == 0) 
  {
    x80 = 10;
  }

  ret = strcmp(tfield1, "unsi");
  if (ret == 0) 
  {
    x80 = 11;
  }

  if(x80 == 0)
  {
    goto struct_2;
  }

  if (x80 == 2) 			/* int	*/
  {
    if (debug_lv >= 3) 
    {
      printf("c2z_struct.c c2_struct rct = %d subroutine #6\n", rct);
    }

    p2 = strstr(p_string, "[");
    p3 = strstr(p_string, "]");

    pi = 0;
    ch = p_string[pi];
    while (ch != 'i') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    if ((!p2) && (!p3)) 
    {
      if (debug_lv >= 3) 
      {
        printf("c2z_struct.c c2_struct rct = %d subroutine #7\n", rct);
      }

      pi2 = 0;
      while (ch != ';') 
      {
        tfield4[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(tfield8a, c_wkname);

      if (m_struc_ct == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = m_struc_ct + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }

      w_struc[m_struc_ct].st_rct = rct;
      strcpy(w_struc[m_struc_ct].st_id, "N");
      w_struc[m_struc_ct].st_disp = x90;
      strcpy(w_struc[m_struc_ct].st_name, tfield2);
      strcpy(w_struc[m_struc_ct].st_wname, tfield2);
      strcpy(w_struc[m_struc_ct].st_cname, tfield99);
      strcpy(w_struc[m_struc_ct].st_cwname, null_field);
      strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
      strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      strcpy(w_struc[m_struc_ct].st_func, null_field);
      strcpy(w_struc[m_struc_ct].st_type, "I");
      w_struc[m_struc_ct].st_field_lgth = 6;
      strcpy(w_struc[m_struc_ct].st_field_value, null_field);
      m_struc_ct++;
      x90 = x90 + 6;
    }

    if ((p2) && (p3)) 
    {
      if (debug_lv >= 3) 
      {
        printf("c2z_struct.c c2_struct rct = %d subroutine #17\n", rct);
      }

      pi2 = 0;
      while (ch != '[') 
      {
        tfield4[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ']') 
      {
        tfield5[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield5[pi2] = '\0';

      s = atoi(tfield5);

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(tfield8a, c_wkname);

      if (m_struc_ct == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = m_struc_ct + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }

      w_struc[m_struc_ct].st_rct = rct;
      strcpy(w_struc[m_struc_ct].st_id, "N");
      w_struc[m_struc_ct].st_disp = (x90 + (s * 6));
      strcpy(w_struc[m_struc_ct].st_name, tfield2);
      strcpy(w_struc[m_struc_ct].st_wname, tfield2);
      strcpy(w_struc[m_struc_ct].st_cname, tfield99);
      strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
      strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      strcpy(w_struc[m_struc_ct].st_func, null_field);
      strcpy(w_struc[m_struc_ct].st_type, "I");
      w_struc[m_struc_ct].st_field_lgth = 6;
      strcpy(w_struc[m_struc_ct].st_field_value, null_field);
      m_struc_ct++;

      convert = 1;

      x90 = x90 + (s * 6);
    }
  }

  if (x80 == 1) 				/* char	*/
  {
    if (debug_lv >= 3) 
    {
      printf("c2z_struct.c c2_struct rct = %d subroutine #8\n", rct);
    }

    pi = 0;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    p2 = strstr(p_string, "[");
    p3 = strstr(p_string, "]");
    p4 = strstr(p_string, "**");

    if ((!p2) && (!p3) && (!p4)) 
    {
      pi2 = 0;
      while (ch != ';') 
      {
        if(ch != '*')
        {
          tfield4[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(tfield8a, c_wkname);

      if (m_struc_ct == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = m_struc_ct + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }

      w_struc[m_struc_ct].st_rct = rct;
      strcpy(w_struc[m_struc_ct].st_id, "N");
      w_struc[m_struc_ct].st_disp = x90;
      strcpy(w_struc[m_struc_ct].st_name, tfield2);
      strcpy(w_struc[m_struc_ct].st_wname, tfield2);
      strcpy(w_struc[m_struc_ct].st_cname, tfield99);
      strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
      strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      strcpy(w_struc[m_struc_ct].st_func, null_field);
      strcpy(w_struc[m_struc_ct].st_type, "C");
      x20 = 32;
      w_struc[m_struc_ct].st_field_lgth = x20;
      w_struc[m_struc_ct].st_field_cur_lgth = x20;
      strcpy(w_struc[m_struc_ct].st_field_value, null_field);
      m_struc_ct++;
      x90 = x90 + x20;
    }

    if ((p2) && (p3) && (!p4)) 
    {
      if (debug_lv >= 3) 
      {
        printf("c2z_struct.c c2_struct rct = %d subroutine #9\n", rct);
      }

      pi2 = 0;
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

      while (ch != '[') 
      {
        if(ch != ' ')
        {
          if(ch != '*')
          {
            tfield4[pi2] = ch;
            pi2++;
          }
        }
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';

      pi2 = 0;
      x2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ']') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            fd5_type = 1;
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
            fd5_type = 2;
            x2 = 1;
          }
        }
        if(ch != '*')
        {
          tfield5[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield5[pi2] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(tfield8a, c_wkname);

      if (m_struc_ct == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = m_struc_ct + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }

      w_struc[m_struc_ct].st_rct = rct;
      strcpy(w_struc[m_struc_ct].st_id, "N");
      w_struc[m_struc_ct].st_disp = x90;
      strcpy(w_struc[m_struc_ct].st_name, tfield2);
      strcpy(w_struc[m_struc_ct].st_wname, tfield2);
      strcpy(w_struc[m_struc_ct].st_cname, tfield99);
      strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
      strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      strcpy(w_struc[m_struc_ct].st_func, null_field);
      strcpy(w_struc[m_struc_ct].st_type, "C");
      if (fd5_type == 1) 
      {
        w_struc[m_struc_ct].st_field_lgth = atoi(tfield5);
        x20 = atoi(tfield5);
        w_struc[m_struc_ct].st_field_cur_lgth = atoi(tfield5);
      }

      if (fd5_type == 2) 
      {
        if (debug_lv >= 3) 
        {
          printf("c2z_struct.c c2_struct rct = %d subroutine #10\n", rct);
        }

        x3 = 0;
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield5, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            x20 = atoi(lw_variable[v].lv_value);
          }
        }

        if (x3 == 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(tfield5, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
              x20 = atoi(gw_variable[v].gv_value);
            }
          }
        }
        w_struc[m_struc_ct].st_field_lgth = x20;
        w_struc[m_struc_ct].st_field_cur_lgth = x20;
      }

      strcpy(w_struc[m_struc_ct].st_field_value, null_field);
      m_struc_ct++;
      x90 = x90 + x20;
    }

    if (p4) 
    {
      if (debug_lv >= 3) 
      {
        printf("c2z_struct.c c2_struct rct = %d subroutine #10\n", rct);
      }

      pi = 0;
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

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        if (ch == ';') 
        {
          break;
        }
        if (ch != '*') 
        {
          tfield1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield1[pi2] = '\0';

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

        snprintf(wk_strg, sizeof(wk_strg), "%d", tot_malloc);
        strcpy(wk_string, "A37");
        strcat(wk_string, wk_strg);
        strcat(wk_string, "A");
        strcpy(gw_variable[gv_ct].gv_aname, wk_string);

        gw_variable[gv_ct].gv_flag = 0;
        gw_variable[gv_ct].gv_lgth = 0;

        gw_variable[gv_ct].gv_column = 32;
        gw_variable[gv_ct].gv_row = 100;

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

      if (m_struc_ct == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = m_struc_ct + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }

      w_struc[m_struc_ct].st_rct = rct;
      strcpy(w_struc[m_struc_ct].st_id, "N");
      w_struc[m_struc_ct].st_disp = x90;
      strcpy(w_struc[m_struc_ct].st_name, tfield2);
      strcpy(w_struc[m_struc_ct].st_wname, tfield2);
      strcpy(w_struc[m_struc_ct].st_cname, tfield99);
      strcpy(w_struc[m_struc_ct].st_field_name, tfield1);
      strcpy(w_struc[m_struc_ct].st_field_cname, tfield1a);
      strcpy(w_struc[m_struc_ct].st_func, null_field);
      strcpy(w_struc[m_struc_ct].st_type, "C");

      /*
               if(fd5_type == 1)
               {
                  w_struc[m_struc_ct].st_field_lgth = atoi(tfield5);
                  x20 = atoi(tfield5);
                  w_struc[m_struc_ct].st_field_cur_lgth = atoi(tfield5);
               }

               if(fd5_type == 2)
               {
                  x3 = 0;
                  for(v = 0; v < lv_ct; v++)
                  {
                     ret = strcmp(tfield5, lw_variable[v].lv_name);
                     ret1 = strcmp(sv_func, lw_variable[v].lv_func);
                     if((ret == 0) && (ret1 == 0))
                     {
                        x3 = 1;
                        x20 = atoi(lw_variable[v].lv_value);
                     }
                  }

                  if(x3 == 0)
                  {
                     for(v = 0; v < gv_ct; v++)
                     {
                        ret = strcmp(tfield5, gw_variable[v].gv_name);
                        if(ret == 0)
                        {
                           x3 = 1;
                           x20 = atoi(gw_variable[v].gv_value);
                        }
                     }
                  }
      */
      x20 = 250 * 33;
      w_struc[m_struc_ct].st_field_lgth = x20;
      w_struc[m_struc_ct].st_field_cur_lgth = x20;

      strcpy(w_struc[m_struc_ct].st_field_value, null_field);
      m_struc_ct++;
      x90 = x90 + x20;
    }
  }

  if (x80 == 3) 				/*	long	*/
  {
    if (debug_lv >= 3) 
    {
      printf("c2z_struct.c c2_struct rct = %d subroutine #11\n", rct);
    }

    p2 = strstr(p_string, "[");
    p3 = strstr(p_string, "]");

    pi = 0;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    if ((!p2) && (!p3)) 
    {
      if (debug_lv >= 3) 
      {
        printf("c2z_struct.c c2_struct rct = %d subroutine #12\n", rct);
      }

      pi2 = 0;
      while (ch != ';') 
      {
        if(ch != '*')
        {
          tfield4[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(tfield8a, c_wkname);

      if (m_struc_ct == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = m_struc_ct + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }

      w_struc[m_struc_ct].st_rct = rct;
      strcpy(w_struc[m_struc_ct].st_id, "N");
      w_struc[m_struc_ct].st_disp = x90;
      strcpy(w_struc[m_struc_ct].st_name, tfield2);
      strcpy(w_struc[m_struc_ct].st_wname, tfield2);
      strcpy(w_struc[m_struc_ct].st_cname, tfield99);
      strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
      strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      strcpy(w_struc[m_struc_ct].st_func, null_field);
      strcpy(w_struc[m_struc_ct].st_type, "I");
      w_struc[m_struc_ct].st_field_lgth = 0;
      strcpy(w_struc[m_struc_ct].st_field_value, null_field);
      m_struc_ct++;
      x90 = x90 + 6;
    }

    if ((p2) && (p3)) 
    {
      printf("\nc2z_struct.c c2_struc (long) struct-002 NEED TO CODE [] \n");
      printf("c2z_struct.c c2_struc rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (x80 == 4) 				/* float	*/
  {
    if (debug_lv >= 3) 
    {
      printf("c2z_struct.c c2_struct rct = %d subroutine #13\n", rct);
    }

    p2 = strstr(p_string, "[");
    p3 = strstr(p_string, "]");

    pi = 0;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    if ((!p2) && (!p3)) 
    {
      if (debug_lv >= 3) 
      {
        printf("c2z_struct.c c2_struct rct = %d subroutine #14\n", rct);
      }

      pi2 = 0;
      while (ch != ';') 
      {
        if(ch != '*')
        {
          tfield4[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(tfield8a, c_wkname);

      if (m_struc_ct == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = m_struc_ct + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }

      w_struc[m_struc_ct].st_rct = rct;
      strcpy(w_struc[m_struc_ct].st_id, "N");
      w_struc[m_struc_ct].st_disp = x90;
      strcpy(w_struc[m_struc_ct].st_name, tfield2);
      strcpy(w_struc[m_struc_ct].st_wname, tfield2);
      strcpy(w_struc[m_struc_ct].st_cname, tfield99);
      strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
      strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      strcpy(w_struc[m_struc_ct].st_func, null_field);
      strcpy(w_struc[m_struc_ct].st_type, "I");
      w_struc[m_struc_ct].st_field_lgth = 0;
      strcpy(w_struc[m_struc_ct].st_field_value, null_field);
      m_struc_ct++;
      x90 = x90 + 6;
    }

    if ((p2) && (p3)) 
    {
      printf("\nc2z_struct.c c2_struc (floaat) struct-003 NEED TO CODE [] \n");
      printf("c2z_struct.c c2_struc rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (x80 == 5) 				/* double	*/
  {
    if (debug_lv >= 3) 
    {
      printf("c2z_struct.c c2_struct rct = %d subroutine #15\n", rct);
    }

    p2 = strstr(p_string, "[");
    p3 = strstr(p_string, "]");

    pi = 0;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    if ((!p2) && (!p3)) 
    {
      if (debug_lv >= 3) 
      {
        printf("c2z_struct.c c2_struct rct = %d subroutine #16\n", rct);
      }

      pi2 = 0;
      while (ch != ';') 
      {
        if(ch != '*')
        {
          tfield4[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(tfield8a, c_wkname);

      if (m_struc_ct == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = m_struc_ct + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }

      w_struc[m_struc_ct].st_rct = rct;
      strcpy(w_struc[m_struc_ct].st_id, "N");
      w_struc[m_struc_ct].st_disp = x90;
      strcpy(w_struc[m_struc_ct].st_name, tfield2);
      strcpy(w_struc[m_struc_ct].st_wname, tfield2);
      strcpy(w_struc[m_struc_ct].st_cname, tfield99);
      strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
      strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      strcpy(w_struc[m_struc_ct].st_func, null_field);
      strcpy(w_struc[m_struc_ct].st_type, "I");
      w_struc[m_struc_ct].st_field_lgth = 0;
      strcpy(w_struc[m_struc_ct].st_field_value, null_field);
      m_struc_ct++;
      x90 = x90 + 6;
    }

    if ((p2) && (p3)) 
    {
      printf("\nc2z_struct.c c2_struc (double) struct-004 NEED TO CODE [] \n");
      printf("c2z_struct.c c2_struc rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (x80 == 6) 			/* FILE */
  {
    if (debug_lv >= 3) 
    {
      printf("c2z_struct.c c2_struct rct = %d subroutine #17\n", rct);
    }

    p2 = strstr(p_string, "[");
    p3 = strstr(p_string, "]");

    pi = 0;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

      pi2 = 0;
      while (ch != ' ') 
      {
        if(ch != '*')
        {
          tfield4[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';


    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    if ((!p2) && (!p3)) 
    {
      if (debug_lv >= 3) 
      {
        printf("c2z_struct.c c2_struct rct = %d subroutine #7\n", rct);
      }

      pi2 = 0;
      while (ch != ';') 
      {
        if(ch != '*')
        {
          tfield4[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(tfield8a, c_wkname);

      if (m_struc_ct == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = m_struc_ct + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }

      w_struc[m_struc_ct].st_rct = rct;
      strcpy(w_struc[m_struc_ct].st_id, "N");
      w_struc[m_struc_ct].st_disp = x90;
      strcpy(w_struc[m_struc_ct].st_name, tfield2);
      strcpy(w_struc[m_struc_ct].st_wname, tfield2);
      strcpy(w_struc[m_struc_ct].st_cname, tfield99);
      strcpy(w_struc[m_struc_ct].st_cwname, null_field);
      strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
      strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      strcpy(w_struc[m_struc_ct].st_func, null_field);
      strcpy(w_struc[m_struc_ct].st_type, "I");
      w_struc[m_struc_ct].st_field_lgth = 6;
      strcpy(w_struc[m_struc_ct].st_field_value, null_field);
      m_struc_ct++;
      x90 = x90 + 6;
    }

    if ((p2) && (p3)) 
    {
      if (debug_lv >= 3) 
      {
        printf("c2z_struct.c c2_struct rct = %d subroutine #17\n", rct);
      }

      pi2 = 0;
      while (ch != '[') 
      {
        tfield4[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ']') 
      {
        tfield5[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield5[pi2] = '\0';

      s = atoi(tfield5);

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(tfield8a, c_wkname);

      if (m_struc_ct == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = m_struc_ct + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }

      w_struc[m_struc_ct].st_rct = rct;
      strcpy(w_struc[m_struc_ct].st_id, "N");
      w_struc[m_struc_ct].st_disp = (x90 + (s * 6));
      strcpy(w_struc[m_struc_ct].st_name, tfield2);
      strcpy(w_struc[m_struc_ct].st_wname, tfield2);
      strcpy(w_struc[m_struc_ct].st_cname, tfield99);
      strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
      strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      strcpy(w_struc[m_struc_ct].st_func, null_field);
      strcpy(w_struc[m_struc_ct].st_type, "I");
      w_struc[m_struc_ct].st_field_lgth = 6;
      strcpy(w_struc[m_struc_ct].st_field_value, null_field);
      m_struc_ct++;

      convert = 1;

      x90 = x90 + (s * 6);
    }
  }


  if (x80 == 8)		/* sa_family_t	*/ 
  {
    if (debug_lv >= 3) 
    {
      printf("c2z_struct.c c2_struct rct = %d subroutine #18\n", rct);
    }

    printf("\nc2z_struct.c c2_struc (sa_familty_t) struct-005 NEED TO CODE  \n");
    printf("c2z_struct.c c2_struc rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }


  if (x80 == 9) 			/* uint8	*/
  {
    if (debug_lv >= 3) 
    {
      printf("c2z_struct.c c2_struct rct = %d subroutine #9\n", rct);
    }

    p2 = strstr(p_string, "[");
    p3 = strstr(p_string, "]");

    pi = 0;
    ch = p_string[pi];
    while (ch != 'i') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    if ((!p2) && (!p3)) 
    {
      if (debug_lv >= 3) 
      {
        printf("c2z_struct.c c2_struct rct = %d subroutine #7\n", rct);
      }

      pi2 = 0;
      while (ch != ';') 
      {
        tfield4[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(tfield8a, c_wkname);

      if (m_struc_ct == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = m_struc_ct + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }

      w_struc[m_struc_ct].st_rct = rct;
      strcpy(w_struc[m_struc_ct].st_id, "N");
      w_struc[m_struc_ct].st_disp = x90;
      strcpy(w_struc[m_struc_ct].st_name, tfield2);
      strcpy(w_struc[m_struc_ct].st_wname, tfield2);
      strcpy(w_struc[m_struc_ct].st_cname, tfield99);
      strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
      strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      strcpy(w_struc[m_struc_ct].st_func, null_field);
      strcpy(w_struc[m_struc_ct].st_type, "I");
      w_struc[m_struc_ct].st_field_lgth = 6;
      strcpy(w_struc[m_struc_ct].st_field_value, null_field);
      m_struc_ct++;
      x90 = x90 + 6;
    }

    if ((p2) && (p3)) 
    {
      if (debug_lv >= 3) 
      {
        printf("c2z_struct.c c2_struct rct = %d subroutine #17\n", rct);
      }

      pi2 = 0;
      while (ch != '[') 
      {
        tfield4[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ']') 
      {
        tfield5[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield5[pi2] = '\0';

      s = atoi(tfield5);

      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(tfield8a, c_wkname);

      if (m_struc_ct == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = m_struc_ct + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }

      w_struc[m_struc_ct].st_rct = rct;
      strcpy(w_struc[m_struc_ct].st_id, "N");
      w_struc[m_struc_ct].st_disp = (x90 + (s * 6));
      strcpy(w_struc[m_struc_ct].st_name, tfield2);
      strcpy(w_struc[m_struc_ct].st_wname, tfield2);
      strcpy(w_struc[m_struc_ct].st_cname, tfield99);
      strcpy(w_struc[m_struc_ct].st_field_name, tfield4);
      strcpy(w_struc[m_struc_ct].st_field_cname, tfield8a);
      strcpy(w_struc[m_struc_ct].st_func, null_field);
      strcpy(w_struc[m_struc_ct].st_type, "I");
      w_struc[m_struc_ct].st_field_lgth = 6;
      strcpy(w_struc[m_struc_ct].st_field_value, null_field);
      m_struc_ct++;

      x90 = x90 + (s * 6);
    }
  }

  if (x80 == 10)		/* in_port	*/ 
  {
    if (debug_lv >= 3) 
    {
      printf("c2z_struct.c c2_struct rct = %d subroutine #19\n", rct);
    }

    printf("\nc2z_struct.c c2_struc (in_port) struct-006 NEED TO CODE \n");
    printf("c2z_struct.c c2_struc rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (x80 == 11)		/* struct	*/ 
  {
    if (debug_lv >= 3) 
    {
      printf("c2z_struct.c c2_struct rct = %d subroutine #19\n", rct);
    }

    printf("\nc2z_struct.c c2_struc (struct) struct-007NEED TO CODE \n");
    printf("c2z_struct.c c2_struc rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (x80 == 12)		/* unsigned 	*/ 
  {
    if (debug_lv >= 3) 
    {
      printf("c2z_struct.c c2_struct rct = %d subroutine #19\n", rct);
    }

    printf("\nc2z_struct.c c2_struc (unsigned) struct-008 NEED TO CODE \n");
    printf("c2z_struct.c c2_struc rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }



  goto struct_2;

struct_3:

  if (debug_lv >= 3) 
  {
    printf("c2z_struct.c c2_struct rct = %d subroutine #18\n", rct);
  }

  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(tfield2, w_struc[I].st_name);
    ret1 = strcmp(w_struc[I].st_id, "M");
    if ((ret == 0) && (ret1 == 0)) 
    {
      w_struc[I].st_field_lgth = x90;
    }
  }

  convert = 1;
  return;
}

void c2_struct_3() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_struct.c c2_struct_3 START");
    trace_rec_1();
  }

  if (debug_lv >= 3) 
  {
    printf("c2z_struct.c c2_struct_3 rct = %d START\n", rct);
  }

  char *p7;

  p7 = strstr(p_string, ";");
  if (p7) 
  {
    return;
  }

struct_10:

  fgets(p_string, 255, pgm);
  rct++;

  p7 = strstr(p_string, "};");
  if (p7) 
  {
    return;
  }
  goto struct_10;
}



void c2_struct_4() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_struct.c c2_struct_4 START");
    trace_rec_1();
  }

  if (debug_lv >= 3) 
  {
    printf("c2z_struct.c c2_struct_4 rct = %d START\n", rct);
  }

  int pi = 0;
  int pi2 = 0;
  int p99 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int size = 0;
  int x4 = 0;
  int eol = 0;

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field4a[VAR_LGTH];

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

  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while(ch != ' ') 
  {
    if(ch == '[')
    {
      eol = 1;
      break;
    }
    if(ch == ';')
    {
       eol = 1;
       break;
    }
    if(ch != '*')
    {
      field2[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  if(eol == 1)
  {
    for (I = 0; I < m_struc_ct; I++) 
    {
      ret = strcmp(field1, w_struc[I].st_name);
      if(ret == 0)
      {
         strcpy(w_struc[I].st_name, field2);
      }
    }

    for(I = 0; I < gv_ct; I++)
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if(ret == 0)
      {
         strcpy(gw_variable[I].gv_name, field2);
      }
    }

    convert = 1;
    return;
  }

  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while(ch != ';')
  {
    if(ch != '*')
    {
      field3[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  p99 = m_struc_ct;

  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(field2, w_struc[I].st_name);
    ret1 = strcmp("M", w_struc[I].st_id);
    if((ret == 0) && (ret1 == 0))
    {
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(field2a, c_wkname);

      if (p99 == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = p99 + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }
    
      w_struc[p99].st_rct = rct;
      strcpy(w_struc[p99].st_name, field2);
      strcpy(w_struc[p99].st_id, "M");
      w_struc[p99].st_disp = 0;
      strcpy(w_struc[p99].st_wname, field3);
      strcpy(w_struc[p99].st_cname, field2a);
      strcpy(w_struc[p99].st_cwname, field2a);
      strcpy(w_struc[p99].st_func, null_field);
      strcpy(w_struc[p99].st_type, null_field);
      strcpy(w_struc[p99].st_field_name, null_field);
      strcpy(w_struc[p99].st_field_cname, null_field);
      w_struc[p99].st_field_lgth = w_struc[I].st_field_lgth;
      strcpy(w_struc[p99].st_field_value, null_field);
      p99++;

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
      strcpy(gw_variable[gv_ct].gv_name, field3);
      strcpy(gw_variable[gv_ct].gv_type, "M");
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
    }

    ret = strcmp(field2, w_struc[I].st_name);
    ret1 = strcmp("N", w_struc[I].st_id);
    if((ret == 0) && (ret1 == 0))
    {
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      x4 = strlen(c_wkname);
      c_wkname[x4] = '\0';
      strcpy(field4a, c_wkname);

      if (p99 == 0) 
      {
        size = 1;
        w_struc = malloc(size * sizeof(struct m_struc));
      } 
      else 
      {
        size = p99 + 1;
        w_struc = realloc(w_struc, size * sizeof(struct m_struc));
      }
    
      w_struc[p99].st_rct = rct;
      strcpy(w_struc[p99].st_name, field2);
      strcpy(w_struc[p99].st_id, "N");
      w_struc[p99].st_disp = 0;
      strcpy(w_struc[p99].st_wname, field3);
      strcpy(w_struc[p99].st_cname, field2a);
      strcpy(w_struc[p99].st_cwname, field2a);
      strcpy(w_struc[p99].st_func, null_field);
      strcpy(w_struc[p99].st_type, w_struc[I].st_type);
      strcpy(w_struc[p99].st_field_name, w_struc[I].st_field_name);
      strcpy(w_struc[p99].st_field_cname, field4a);
      w_struc[p99].st_field_lgth = w_struc[I].st_field_lgth;
      strcpy(w_struc[p99].st_field_value, null_field);
      w_struc[p99].st_disp = w_struc[I].st_disp;
      p99++;
    }
  }  /* END OF FOR */

  m_struc_ct = p99;
  convert = 1;
}


