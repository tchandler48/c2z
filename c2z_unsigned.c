/* ***************************************************
*  c2z  : c2z_unsigned.c                             *
*                                                    *
*  next error - unsigned-005                         *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Scan test for unsigned                            *
**************************************************** */
void c2_unsigned() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_unsigned.c c2_unsigned START");
    trace_rec_1();
  }

  int s = 0;
  int size = 0;
  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x22 = 0;
  int x23 = 0;
  int x24 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int m5fd1_type = 0;
  int m5fd2_type = 0;

  char ch, *p;
  char tfield1[VAR_LGTH];
  char tfield2[VAR_LGTH];

  var_use[19]++;
  pi = 0;
  s = strlen(p_string);
  ch = p_string[pi];
  pi++;
  while ((ch == '{') || (ch == ' ') || (ch == '\t')) 
  {
    ch = p_string[pi];
    pi++;
  }

  while (ch != ' ') 
  {
    ch = p_string[pi];
    pi++;
  }

  p = strstr(p_string, "=");

  if (!p) 				/*  no equal sign   */
  {
    x23 = 0;
    x22 = 0;
    s = strlen(p_string);
    for (I = 0; I < s; I++) 
    {
      ch = p_string[I];
      if (ch == ',') 
      {
        x22++;
      }
    }

    if (x22 == 0) 
    {
      x23 = 0;
      pi2 = 0;
      ch = p_string[pi];
      while (ch != ';') 
      {
        if(ch != ' ')
        {
          tfield1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield1[pi2] = '\0';
      x23++;
    }

    if (x22 == 1) 
    {
      x23 = 0;
      pi2 = 0;
      ch = p_string[pi];
      while (ch != ',') 
      {
        if(ch != ' ')
        {
          tfield1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield1[pi2] = '\0';
      x23++;

      x24 = 0;
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ';') 
      {
        if (ch != ' ') 
        {
          tfield2[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield2[pi2] = '\0';
      x24++;
    }

    if (x23 == 1) 
    {
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';

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
        strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
        strcpy(gw_variable[gv_ct].gv_name, tfield1);
        strcpy(gw_variable[gv_ct].gv_type, "I");
        gw_variable[gv_ct].gv_lgth = 0;
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
        strcpy(lw_variable[lv_ct].lv_cname, c_wkname);
        strcpy(lw_variable[lv_ct].lv_name, tfield1);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        lw_variable[lv_ct].lv_lgth = 0;
        lw_variable[lv_ct].lv_use_ct = 0;
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 1;
        lv_ct++;
      }
      convert = 1;
    }

    if (x24 == 1) 
    {
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';

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
        strcpy(gw_variable[gv_ct].gv_cname, c_wkname);
        strcpy(gw_variable[gv_ct].gv_name, tfield2);
        strcpy(gw_variable[gv_ct].gv_type, "I");
        gw_variable[gv_ct].gv_lgth = 0;
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
        strcpy(lw_variable[lv_ct].lv_cname, c_wkname);
        strcpy(lw_variable[lv_ct].lv_name, tfield2);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        lw_variable[lv_ct].lv_lgth = 0;
        lw_variable[lv_ct].lv_use_ct = 0;
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 1;
        lv_ct++;
      }
      convert = 1;
    }
  }

  if (p) 				/* equal signed  */
  {
    x2 = 0;
    pi2 = 0;
    ch = p_string[pi];
    while (ch != '=') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          m5fd1_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          m5fd1_type = 1;
          x2 = 1;
        }
      }
      if(ch != ' ')
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    pi2 = 0;
    x2 = 0;
    ch = p_string[pi];
    while (ch != ';') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          m5fd2_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          m5fd2_type = 1;
          x2 = 1;
        }
      }
      if (ch != '=') 
      {
        if(ch != ' ')
        {
          tfield2[pi2] = ch;
          pi2++;
        }
      }
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    p = strstr(tfield2, "(unsigned)");
    if(p)
    {
      convert = 1;
      return;
    }

    if (m5fd1_type == 1) 
    {
      printf("\nc2z_unsigned.c c2_unsigned unsigned-001 m5fd1_type == 1 NEED TO CODE\n");
      printf("c2z_unsigned.c c2_unsigned rct = %d p_string = %s",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if (m5fd1_type == 2) 
    {
      if (global_st == 0) 
      {
        x3 = 0;
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
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
          strcpy(gw_variable[gv_ct].gv_name, tfield1);
          strcpy(gw_variable[gv_ct].gv_type, "I");
          gw_variable[gv_ct].gv_lgth = 0;
          gw_variable[gv_ct].gv_dec = 0;
          gw_variable[gv_ct].gv_id = 1;
          gv_ct++;
        }
      } /* if((global_st == 0)  */

      if (global_st == 1) 
      {
        x3 = 0;
        if (lv_ct > 0) 
        {
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(tfield1, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x3 = 1;
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
          strcpy(lw_variable[lv_ct].lv_cname, c_wkname);
          strcpy(lw_variable[lv_ct].lv_name, tfield1);
          strcpy(lw_variable[lv_ct].lv_type, "I");
          lw_variable[lv_ct].lv_lgth = 0;
          lw_variable[lv_ct].lv_use_ct = 0;
          strcpy(lw_variable[lv_ct].lv_func, sv_func);
          lw_variable[lv_ct].lv_current_lgth = 0;
          lw_variable[lv_ct].lv_dec = 0;
          lw_variable[lv_ct].lv_id = 1;
          lv_ct++;
          convert = 1;
        }
      } 			/* if((global_st == 1)  */
    }   		/* if(m5fd1_type == 2) */

    if (m5fd2_type == 1) 
    {
      convert = 1;
      return;
    }

    if (global_st == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++)
      {
        ret = strcmp(tfield2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
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
        strcpy(gw_variable[gv_ct].gv_name, tfield1);
        strcpy(gw_variable[gv_ct].gv_type, "I");
        gw_variable[gv_ct].gv_lgth = 0;
        gw_variable[gv_ct].gv_dec = 0;
        gw_variable[gv_ct].gv_id = 1;
        gv_ct++;
      }
    } 			/* if((global_st == 0)  */

    if (global_st == 1) 
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
            x3 = 1;
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
        strcpy(lw_variable[lv_ct].lv_cname, c_wkname);
        strcpy(lw_variable[lv_ct].lv_name, tfield2);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        lw_variable[lv_ct].lv_lgth = 0;
        lw_variable[lv_ct].lv_use_ct = 0;
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 1;
        lv_ct++;
        convert = 1;
      }
    } 				/* if((global_st == 1)  */
  }   			/* if(m5fd1_type == 2) */
}



void c2_unsigned_punch() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_unsigned.c c2_unsigned_punch START");
    trace_rec_1();
  }

  char ch;
  char *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];

  int pi;
  int pi2;
  int I;
  int ret;
  int ret1;
  int x3;
  int x2;
  int fd2_type = 0;
  int s;
  int x20;
  int x21;

  x20 = 0;
  x21 = 0;
  s = strlen(p_string);
  for(I=0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '=')
    {
      x20 = I;
    }
    if(ch == '(')
    {
      x21 = I;
    }
  }
  
  p = strstr(p_string, "=");

  if((p) && (x21 > x20))
  {
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

    while(ch != ')')
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    fd2_type = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != ';')
    {
      if (ch != ' ')
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
        field2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    x3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strcpy(field1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(field1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_unsigned.c c2_unsigned unsigned-012 field1 = %s NOT Found\n",field1);
      printf("c2z_unsigned.c c2_unsigned rct = %d p_string = %s",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

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

    if (x3 == 0) 
    {
      printf("\nc2z_unsigned.c c2_unsigned unsigned-013 field2 = %s NOT Found\n",field2);
      printf("c2z_unsigned.c c2_unsigned rct = %d p_string = %s",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_unsigned.c #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_unsigned.c #2");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_unsigned.c #3");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  if((p) && (x21 == 0))
  {
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
    while(ch != '=')
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x2 = 0;
    fd2_type = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != ';')
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
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    x3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strcpy(field1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(field1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_unsigned.c c2_unsigned unsigned-002 field1 = %s NOT Found\n",field1);
      printf("c2z_unsigned.c c2_unsigned rct = %d p_string = %s",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if(fd2_type == 1)
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

      if (x3 == 0) 
      {
        printf("\nc2z_unsigned.c c2_unsigned unsigned-003 field2 = %s NOT Found\n",field2);
        printf("c2z_unsigned.c c2_unsigned rct = %d p_string = %s",rct,p_string);
        erct++;
        convert = 1;
        return;
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
      strcpy(trace_1, "c2z_unsigned.c #4");
      trace_rec_3();
    }

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_unsigned.c #5");
        trace_rec_3();
       }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LARL  R5,");
      strcat(a_string, field2);
      strcpy(wk_remark, " ");
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_unsigned.c #6");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_unsigned.c #7");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_unsigned.c #8");
        trace_rec_3();
      }
 
      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_unsigned.c #9");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_unsigned.c #10");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_unsigned.c #11");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_unsigned.c #12");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  if(!p)
  {
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
    while(ch != ';')
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x3 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strcpy(field1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(field1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_unsigned.c c2_unsigned unsigned-004 field1 = %s NOT Found\n",field1);
      printf("c2z_unsigned.c c2_unsigned rct = %d p_string = %s",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_unsigned.c #13");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_unsigned.c #14");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_unsigned.c #15");
      trace_rec_3();
    }

    convert = 1;
    return;
  }
}




