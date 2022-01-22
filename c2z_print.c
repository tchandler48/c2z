/* ***************************************************
*  c2z : c2z_print.c :                               *
*                                                    *
*  next error = print = 21                           *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

void c2_printf()
{

  char ch;
  char *p1;
  char *p2;
  char *p3;

   int s;
   int x;
   int I;
   int x100;
   int ptr_type;

  printf_convert = 0;

  s = strlen(p_string);
  x = 0;
  p102 = 0;
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '\"') 
    {
      x++;
    }
    if(x >= 2)
    {
      if(ch == '[')
      {
        x100++;
      }
      if(ch == ']')
      {
        x100++;
      }
    }
    if((p_string[I] == '\\') && (p_string[I + 1] == 'n'))
    {
      p102 = 1;
    }
  }

  if (fprtf_flag != 1) 
  {
      p1 = strstr(p_string, "%s");
      p2 = strstr(p_string, "%d");
      p3 = strstr(p_string, "%f");

      ptr_type = 0;
      if(p1)
      {
        ptr_type = 1;
      }
      if(p2)
      {
        ptr_type = 2;
      }
      if(p3)
      {
        ptr_type = 3;
      }
    }

    if((ptr_type == 0) && (x == 2))
    {
      c2_printf_literal();
      convert = 1;
      return;
    }

    if((ptr_type == 1) && (x == 2))
    {
      c2_printf_string();
      convert = 1;
      return;
    }

    if((ptr_type == 2) && (x == 2))
    {
      c2_printf_numeric();
      convert = 1;
      return;
    }
}



/*  place holders */

void c2_sprintf()
{
}

void c2_fprintf()
{
}


void c2_snprintf()
{
}


void c2_printf_literal() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_literal");
    trace_rec_1();
  }

  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int v = 0;
  int I;
  int s;
  int ret = 0;
  int ret1 = 0;

  char field1[VAR_LGTH];

  p102 = 0;

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    if((p_string[I] == '\\') && (p_string[I+1] == 'n'))
    {
      p102++;
    }
  }

  strcpy(field1, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(field1, wk_strg);

  for (x3 = 0; x3 < v_const; x3++) 
  {
    ret = strcmp(field1, w_constant[x3].const_current);
    if (ret == 0) 
    {
      strcpy(wk_strg, w_constant[x3].const_use);

      x5 = 0;
      x4 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(wk_strg, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x4 = 1;
            lw_variable[v].lv_use_ct++;
            x5 = lw_variable[v].lv_lgth;
          }
        }
      }

      strcpy(wk_strg, w_constant[x3].const_use);
      if (x4 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(wk_strg, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              x4 = 1;
              gw_variable[v].gv_use_ct++;
              x5 = gw_variable[v].gv_lgth;
            }
          }
        }
      }
    }
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #290");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #291");
    trace_rec_3();
  }


  strcpy(a_string, "         MVC   ");
  snprintf(ptr_lgth, sizeof(ptr_lgth), "%d", p_ln_ct);
  strcat(a_string, ptr_lgth);
  strcat(a_string, "(");
  snprintf(ptr_lgth, sizeof(ptr_lgth), "%d", x5);
  strcat(a_string,ptr_lgth);
  strcat(a_string, ",R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #292");
    trace_rec_3();
  }

  if(p102 == 0)
  {
    p_ln_ct = p_ln_ct + x5;
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #294");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #295");
      trace_rec_3();
    }
    p_ln_ct = 0;
  }
  
  printf_convert = 1;
}



void c2_printf_numeric() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_numeric");
    trace_rec_1();
  }

  char ch;
  char *p5;
  char *p6;
  char *p7;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field12[VAR_LGTH];

   int prf1;
   int prf2;
   int prf6;
   int pi;
   int pi2;
   int I;
   int x3;
   int x4;
   int x5;
   int ret;
   int ret1;
   int v;

  pi = 0;
  ch = p_string[pi];
  while (ch != '"') 
  {
    pi++;
    ch = p_string[pi];
  }

  prf1 = pi;
  pi = 0;
  ch = p_string[pi];
  while (ch != '%') 
  {
    pi++;
    ch = p_string[pi];
  }

  prf2 = pi;

  if (prf1 < prf2)  
  {
    pi = 0;
    while (ch != '"') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
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

    prf6 = 0;
    p5 = strstr(p_string, "[");
    p6 = strstr(p_string, "]");
    p7 = strstr(p_string, ".");

    if ((p5) && (p6) && (!p7)) 
    {
      prf6 = 1;
    }

    if ((p5) && (p6) && (p7)) 
    {
      prf6 = 2;
    }

    if(prf6 == 0)	/* simple numeric */
    {
      int s;
      p102 = 0;

      s = strlen(p_string);
      for (I = 0; I < s; I++) 
      {
        if((p_string[I] == '\\') && (p_string[I+1] == 'n'))
        {
          p102++;
        }
      }  

      strcpy(a_string, "         LARL  R9,C370DEC");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #490");
        trace_rec_3();
      }
      work_use_ct[67]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #491");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #492");
        trace_rec_3();
      }

      strcpy(field1, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(field1, wk_strg);

      for (x3 = 0; x3 < v_const; x3++) 
      {
        ret = strcmp(field1, w_constant[x3].const_current);
        if (ret == 0) 
        {
          strcpy(a_string, "         LARL  R9,");
          strcat(a_string, w_constant[x3].const_use);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #493");
            trace_rec_3();
          }
          strcpy(field12, w_constant[x3].const_use);

          strcpy(a_string, "         LARL  R8,C370WTOB");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #494");
            trace_rec_3();
          }

          strcpy(wk_strg, w_constant[x3].const_use);

          x4 = 0;
          if (lv_ct > 0) 
          {
            for (v = 0; v < lv_ct; v++) 
            {
              ret = strcmp(wk_strg, lw_variable[v].lv_name);
              ret1 = strcmp(sv_func, lw_variable[v].lv_func);
              if ((ret == 0) && (ret1 == 0)) 
              {
                x4 = 1;
                x5 = lw_variable[v].lv_lgth;
                lw_variable[I].lv_use_ct++;
              }
            }
          }

          strcpy(wk_strg, w_constant[x3].const_use);
          if (x4 == 0) 
          {
            if (gv_ct > 0) 
            {
              for (v = 0; v < gv_ct; v++) 
              {
                ret = strcmp(wk_strg, gw_variable[v].gv_name);
                if (ret == 0) 
                {
                  x4 = 1;
                  x5 = gw_variable[v].gv_lgth;
                  gw_variable[v].gv_use_ct++;
                }
              }
            }
          }

          snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct); 
          strcpy(a_string, "         MVC   ");
          strcat(a_string, wk_strg); 
          strcat(a_string,"(");
          snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
          strcat(a_string, wk_strg);
          strcat(a_string, ",R8),0(R9)");
          strcpy(wk_remark, " printf   */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #495");
            trace_rec_3();
          }
          p_ln_ct = p_ln_ct + x5; 
          break;
        }
      }

      x3 = 0;
      strcpy(sv_print_lit, "L");
      strcat(sv_print_lit, wk_strg);

      x3 = 0;
      if (x3 == 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field2, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(field2a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
      }

      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[v].gv_cname);
        }
      }

      x4 = 0;
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(sv_print_lit, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x4 = gw_variable[I].gv_lgth;
          }
        }
      }

      strcpy(a_string, "         LARL  R9,C370EDN");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #496");
        trace_rec_3();
      }
      work_use_ct[51]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #497");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #498");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R15,WTOIMVC");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #499");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #500");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370WTOB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #501");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370L10");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #502");
        trace_rec_3();
      }
      work_use_ct[71]++;

      strcpy(a_string, "         MVC   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct); 
      strcat(a_string, wk_strg); 
      strcat(a_string, "(10,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #503");
        trace_rec_3();
      }
      p_ln_ct = p_ln_ct + 10; 
    
      if(p102 == 1)
      {
        strcpy(a_string, "         LARL  R15,WTOALPHA");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #504");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #505");
          trace_rec_3();
        }
        p_ln_ct = 0; 
      }

      tot_wto++;
    }
  }
}


void c2_printf_string() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_string");
    trace_rec_1();
  }

  char ch;
  char *p6;
  char *p7;
  char *p8;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field1b[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field11[VAR_LGTH];
  char field11a[VAR_LGTH];
  char field12[VAR_LGTH];
  char tfield22[VAR_LGTH];
  char tfield22a[VAR_LGTH];

   int I;
   int pi;
   int pi2;
   int s;
   int x1;
   int x2;
   int x3;
   int x5;
   int x9;
   int x11;
   int xc;
   int v;
   int ret;
   int ret1;
   int pf1;
   int prf1;
   int prf3;
   int fd22_type;

  p102 = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    if((p_string[I] == '\\') && (p_string[I+1] == 'n'))
    {
      p102++;
    }
  } 

  pi = 0;
  ch = p_string[pi];
  while (ch != ',') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
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

  strcpy(field1, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(field1, wk_strg);
  x3 = 0;
  for (x3 = 0; x3 < v_const; x3++) 
  {
    ret = strcmp(field1, w_constant[x3].const_current);
    if (ret == 0) 
    {
      strcpy(field1, w_constant[x3].const_use);
      break;
    }
  }

  x5 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x5 = 1;
      x1 = lw_variable[I].lv_lgth;
      lw_variable[I].lv_use_ct++;
    }
  }

  if (x5 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x5 = 1;
        x1 = gw_variable[I].gv_lgth;
        gw_variable[I].gv_use_ct++;
      }
    }
  }


  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #310");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, w_constant[x3].const_use);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #311");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct); 
  strcat(a_string, wk_strg); 
  strcat(a_string, "(");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
  strcat(a_string, wk_strg);
  strcat(a_string, ",R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #312");
    trace_rec_3();
  }

  p_ln_ct = p_ln_ct + x1;

  p6 = strstr(p_string, "[");
  p7 = strstr(p_string, "]");
  p8 = strstr(p_string, ".");

  if ((!p6) && (!p7) && (!p8)) 
  {
    x11 = 0;
    x9 = 0;
    pf1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        pf1 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        x9 = lw_variable[I].lv_lgth;
        break;
      }
    }

    if (pf1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        prf3 = strcmp(field2, gw_variable[I].gv_name);
        if (prf3 == 0) 
        {
          pf1 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x9 = gw_variable[I].gv_lgth;
        }
      }
    }

    if (pf1 == 0) 
    {
      printf("\nc2z_print.c c2_printf NO [] printf-009 Missing field after format statement\n");
      printf("c2z_print.c c2_printf rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #313");
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
      strcpy(trace_1, "c2z_print.c #314");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #315");
      trace_rec_3();
    }
    p_ln_ct = p_ln_ct + x9;

 
    if(p102 == 1)
    {
      strcpy(a_string, "         LARL  R15,WTOALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #316");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #317");
        trace_rec_3();
      }
      p_ln_ct = 0;
    }
  }

/*  print out array[x] code  */
  if ((p6) && (p7) && (!p8)) 
  {
    pi = 0;
    while (ch != '"') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch == ',') 
      {
        x2 = 1;
      }
      if (x2 == 0) 
      {
        if (ch != ' ') 
        {
          field1[pi2] = ch;
          pi2++;
        }
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    p6 = strstr(field1, "[");
    p7 = strstr(field1, "]");

    print_array = 0;

    if ((p6) && (p7)) 
    {
      pi2 = 0;
      ch = field1[prf1];
      while (ch != '[') 
      {
        field1a[pi2] = ch;
        pi2++;
        prf1++;
        ch = field1[prf1];
      }
      field1a[pi2] = '\0';
      x3 = 0;
      pi2 = 0;
      prf1++;
      ch = field1[prf1];
      while (ch != ']') 
      {
        if ((isdigit(ch)) && (x3 == 0)) 
        {
          fd22_type = 2;
          x3 = 1;
        }
        if ((isalpha(ch)) && (x3 == 0)) 
        {
          fd22_type = 1;
          x3 = 1;
        }
        tfield22[pi2] = ch;
        pi2++;
        prf1++;
        ch = field1[prf1];
      }
      tfield22[pi2] = '\0';

      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field1a, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            strcpy(field1b, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            strcpy(field4, gw_variable[I].gv_type);
          }
        }
      }

      ret = strcmp(field4, "A");
      if (ret == 0) 
      {
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field1b, gw_variable[I].gv_cname);
            if (ret == 0) 
            {
              strcpy(field5, gw_variable[I].gv_dsect);
              strcpy(field6, gw_variable[I].gv_label);
              strcpy(field7, gw_variable[I].gv_table);
              strcpy(field8, gw_variable[I].gv_aname);
              strcpy(field9, gw_variable[I].gv_sv_reg);
              strcpy(field10, gw_variable[I].gv_wk_reg);
              strcpy(field11, gw_variable[I].gv_wk_strg);
              xc = gw_variable[I].gv_column;
              gw_variable[I].gv_flag = 1;
            }
          }
        }
      
        prf3 = 0;
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field11, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            prf3 = 1;
            strcpy(field11a, lw_variable[v].lv_cname);
            x9 = lw_variable[v].lv_lgth;
            lw_variable[v].lv_use_ct++;
          }
        }

        prf3 = 0;
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field11, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            prf3 = 1;
            strcpy(field11a, gw_variable[v].gv_cname);
            x9 = gw_variable[v].gv_lgth;
            gw_variable[v].gv_use_ct++;
          }
        }

        strcpy(a_string, "         LARL  R6,");
        strcat(a_string, field7);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #318");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #319");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #320");
          trace_rec_3();
        }
        work_use_ct[32]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        var_use[1]++;
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #321");
          trace_rec_3();
        }

        strcpy(a_string, "PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "A");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #322");
          trace_rec_3();
        }

        if (fd22_type == 2) 
        {
          strcpy(a_string, "         LAEY  R5,");
          strcat(a_string, tfield22);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #323");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL R9,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #324");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         CVD  R5,0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #325");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL R9,C370NWK2");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #326");
            trace_rec_3();
          }
          work_use_ct[50]++;

          strcpy(a_string, "         LARL R8,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #327");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         ZAP  0(6,R9),0(8,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #328");
            trace_rec_3();
          }
        }

        if (fd22_type == 1) 
        {
          prf3 = 0;
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(tfield22, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              prf3 = 1;
              strcpy(tfield22a, lw_variable[v].lv_cname);
              x9 = lw_variable[v].lv_lgth;
              lw_variable[v].lv_use_ct++;
            }
          }

          prf3 = 0;
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(tfield22, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              prf3 = 1;
              strcpy(tfield22a, gw_variable[v].gv_cname);
              x9 = gw_variable[v].gv_lgth;
              gw_variable[v].gv_use_ct++;
            }
          }

          strcpy(a_string, "         LARL  R9,");
          strcat(a_string, tfield22a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield22);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #329");
            trace_rec_3();
          }
        }

        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #330");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #331");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        var_use[1]++;
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #332");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #333");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #334");
          trace_rec_3();
        }
        work_use_ct[33]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #335");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, field6);
        strcat(a_string, "(R0,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #336");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "A");
        src_line();
        var_use[1]++;
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #337");
          trace_rec_3();
        }

        strcpy(a_string, "PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #338");
          trace_rec_3();
        }

        strcpy(print_array_name, field10);
        strcpy(print_array_table, field7);

        strcpy(a_string, "         LARL  R9,C370L80");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #339");
          trace_rec_3();
        }
        work_use_ct[10]++;
 
        strcpy(a_string, "         MVC   0(80,R9),0(R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #340");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #341");
          trace_rec_3();
        }
        work_use_ct[50]++;
 
        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #342");
          trace_rec_3();
        }
        work_use_ct[32]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #343");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R2,1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #344");
          trace_rec_3();
        }

        strcpy(a_string, "PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "L");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #345");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #346");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #347");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #348");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #349");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVB   R5,0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #350");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370L80");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #351");
          trace_rec_3();
        }
        work_use_ct[10]++;
 
        strcpy(a_string, "         IC    R0,0(R8,(R5))");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #352");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #353");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         STC   R0,0(0,R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #354");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #355");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         LARL  R8,C370EOF");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #356");
          trace_rec_3();
        }
        work_use_ct[74]++;

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #357");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "M");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #358");
          trace_rec_3();
        }

         strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #359");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #360");
          trace_rec_3();
        }
        work_use_ct[33]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #361");
          trace_rec_3();
        }

        strcpy(a_string, "         AR    R3,R2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #362");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "L");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #363");
          trace_rec_3();
        }

        strcpy(a_string, "PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "M");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #364");
          trace_rec_3();
        }

        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field12, gw_variable[I].gv_name);
          }
        }

        strcpy(a_string, "         LARL  R9,C370WTOB");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #365");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
        strcat(a_string, wk_strg);
        strcat(a_string, "(");
        snprintf(wk_strg, sizeof(wk_strg), "%d", xc);
        strcat(a_string, wk_strg);
        strcat(a_string, ",R9),0(R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #366");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R15,WTOALPHA");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #368");
          trace_rec_3();
        }
    
        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #369");
          trace_rec_3();
        }
        p_ln_ct = 0; 
        print_array = 1;
        tot_wto++;
      }
    }
  }

}













