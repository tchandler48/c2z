/* ***************************************************
*  c2z : c2z_main.c :                                *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Scan for c2_main                                  *
* ************************************************** */
void c2_main() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_main.c c2_main");
    trace_rec_1();
  }

  char ch;
  char *p1;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];

  int pi;
  int pi2;
  int underline = 0;
  int I = 0;
  int s = 0;
  int x3 = 0;
  int ret = 0;
  int size = 0;

  p1 = strstr(p_string, "()");
  if(p1)
  {
     convert = 1;
     return;
  }

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
  while (ch != ' ') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  underline = 0;
  p1 = strstr(field1, "int");
  if (p1)
  {
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      if ((ch == '_') && (underline = 0)) 
      {
        underline = 1;
      }
      if (ch != ' ') 
      {
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';
  }

  s = strlen(field1);

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(c_wkname, field1);

  x3 = 0;
  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
      }
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
    strcpy(gw_variable[gv_ct].gv_name, field1);
    strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_dec = 0;
    gv_ct++;
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch != ' ')
  {
    if ((ch == '_') && (underline = 0)) 
    {
      underline = 1;
    }

    if (ch != ' ') 
    {
      field2[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  underline = 0;
  p1 = strstr(field2, "char");
  if (p1) 
  {
    pi2 = 0;
    underline = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if ((ch == '_') && (underline = 0)) 
      {
        underline = 1;
      }
      if (ch != '*') 
      {
        field2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';
  }

  s = strlen(field2);
  if ((s > 8) || (underline == 1)) 
  {
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
  } 
  else 
  {
    strcpy(c_wkname, field2);
  }

  x3 = 0;
  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if (ret == 0)
      {
        x3 = 1;
      }
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
    strcpy(gw_variable[gv_ct].gv_name, field2);
    strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
    strcpy(gw_variable[gv_ct].gv_type, "C");
    gw_variable[gv_ct].gv_lgth = 32;
    strcpy(gw_variable[gv_ct].gv_value, null_field);
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_dec = 0;
    gv_ct++;
  }

  convert = 1;
}
