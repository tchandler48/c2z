/* ***************************************************
*  c2z : c2z_fopen.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Scan test for FOPEN                               *
* ************************************************** */
void c2_scan_fopen(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_fopen.c c2_scan_fopen START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int I = 0;
  int s = 0;
  int v = 0;
  int ret = 0;
  int size = 0;

  s = strlen(p_string);
  pi = 0;
  ch = p_string[pi];
  pi++;
  while ((ch == ' ') || (ch == '\t')) 
  {
    ch = p_string[pi];
    pi++;
  }

  pi2 = 0;
  pi--;
  while (ch != ' ') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  strcpy(c_output_file, field1);

  while (ch != '"') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != '"') 
  {
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  x2 = 0;
  for (I = 0; I < f_ct; I++) 
  {
    ret = strcmp(field1, w_file[I].f_name);
    if (ret == 0) 
    {
      x2 = 1;
    }
  }

  if (x2 == 0) 
  {
    if (f_ct == 0) 
    {
      size = 1;
      w_file = malloc(size * sizeof(struct files));
    } 
    else 
    {
      size = f_ct + 1;
      w_file = realloc(w_file, size * sizeof(struct files));
    }
    w_file[f_ct].f_rct = rct;
    strcpy(w_file[f_ct].f_cname, field1);
    strcpy(w_file[f_ct].f_name, field1);
    strcpy(w_file[f_ct].f_type, "P");
    w_file[f_ct].f_buf_ct = size;
    strcpy(w_file[f_ct].f_perm, "  ");
    ret = strcmp("r", field2);
    if (ret == 0) 
    {
      strcpy(w_file[f_ct].f_perm, "I");
    }
    ret = strcmp("w", field2);
    if (ret == 0) 
    {
      strcpy(w_file[f_ct].f_perm, "O");
    }
    f_ct++;

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(field1a, "C37F");
    strcat(field1a, wk_strg);
    s = strlen(field1a);
    field1a[s] = '\0';

    x3 = 0;
    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(field1, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
      }
    }

    if (x3 == 0) 
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
      strcpy(gw_variable[gv_ct].gv_value, null_field);
      gw_variable[gv_ct].gv_dec = 0;
      gv_ct++;
    }
  }
}

/* ***************************************************
*  Punch out OPEN based on FOPEN                     *
* ************************************************** */
void c2_open() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_fopen.c c2_open START");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int ret = 0;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ' ') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  for (I = 0; I < f_ct; I++) 
  {
    ret = strcmp(tfield1, w_file[I].f_name);
    if (ret == 0) 
    {
      strcpy(a_string, "         LARL  R15,C370OPN");
      snprintf(wk_strg, sizeof(wk_strg), "%d", w_file[I].f_buf_ct);
      strcat(a_string, wk_strg);
      src_line();
      if(puncde == 1)
      {
        strcpy(trace_1, "c2z_fopen.c #1");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if(puncde == 1)
      {
        strcpy(trace_1, "c2z_fopen.c #2");
        trace_rec_3();
      }
    }
  }
}
