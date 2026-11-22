/* ***************************************************
*  c2z : c2z_malloc.c :                              *
*                                                    *
*  next error - malloc-003                           *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* ***************************************************
*  Scan for malloc                                   *
* ************************************************** */
void c2_scan_malloc() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_malloc.c c2_scan_malloc");
    trace_rec_1();
  }

  char ch;
  char *p5, *p6;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];

  int x3 = 0;
  int I = 0;
  int pi = 0;
  int pi2;
  int ret = 0;
  int ret1 = 0;

  p5 = strstr(p_string, "[");
  p6 = strstr(p_string, "]");

  if ((!p5) && (!p6)) 
  {
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
      if (ch != '=') 
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    x3 = 0;
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
      if (ch != '=') 
      {
        tfield2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    x3 = 0;
    if (gv_ct > 0) 
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
  }

  if ((p5) && (p6)) 				/* [] on the left of = 	*/
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }
    pi2 = 0;

    while (ch != '[') 
    {
      if (ch != '=') 
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

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
      if (ch != '=') 
      {
        tfield2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    x3 = 0;
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

    if (x3 == 0) 
    {
      printf("\nc2z_malloc.c c2_scan_malloc malloc-001 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_malloc.c c2_scan_malloc rct = %d,p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

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
          strcpy(tfield2a, lw_variable[I].lv_cname);
          strcpy(tfield3, lw_variable[I].lv_value);
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
            strcpy(tfield2a, gw_variable[I].gv_cname);
            strcpy(tfield3, gw_variable[I].gv_value);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_malloc.c c2_scan_malloc malloc-002 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_malloc.c c2_scan_malloc rct = %d,p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1a, gw_variable[I].gv_cname);
        if (ret == 0) 
        {
          gw_variable[I].gv_lgth = atoi(tfield3);
          gw_variable[I].gv_column = atoi(tfield3);
        }
      }
    }

    convert = 1;
  }
}
