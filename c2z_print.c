/* ***************************************************
*  c2z : c2z_print.c :                               *
*                                                    *
*  next error = print = 21                           *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

void c2_printf()
{
printf("\nc2z_print.c rct = %d p_string = %s\n",rct,p_string);
  char ch;
  char *p1;
  char *p2;
  char *p3;

   int s;
   int x;
   int x94;
   int x94a;
   int I;
   int x90;
   int x100;
   int ptr_type;
   int str1;
   int str2;
   int bkl;
   int bkr;

  printf_convert = 0;

  s = strlen(p_string);
  x = 0;
  p102 = 0;

  str1 = 0;
  str2 = 0;
  bkl = 0;
  bkr = 0;
  x90 = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if(ch == ',')
    {
      if(x94 == 0)
      {
        x94a = I;
        str1 = I;
      }
      x94++;
    }
    if(ch == '[')
    {
      if(str1 > 0)
      {
        bkr++;
      }
    }
    if(ch == ']')
    {
      if(str1 > 0)
      {
        bkr++;
      }
    }
    if (ch == '\"') 
    {
      x90++;
    }
  }

  for (I = 0; I < s; I++) 
  {
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

printf("c2z_print.c ptr_type = %d bkr = %d x90 = %d \n",ptr_type,bkr,x90);

/* ************************************************************* */
/*       []          []        type                              */ 
/*       0     ,     0          0     c2_printf_literal  (only)  */
/*       0           0          2     c2_printf_dec              */
/*       0     ,     2          1     c2_printf_str1             */
/*       0     ,     0          1     c2_printf_str2             */
/*       0     ,     2          2     c2_printf_dec1             */
/*                                            */
/*  Literal only     ptr_type = 0             */
/*  String           ptr_type = 1             */
/*  Decimal          ptr_type = 2             */
/*  Float            ptr_type = 3             */ 
/* ****************************************** */


    if((ptr_type == 0) && (bkl == 0) && (bkr == 0) && (x90 == 2))
    {
      c2_printf_literal();
      convert = 1;
      return;
    }

 
    if((ptr_type == 2) && (bkl == 0) && (bkr == 0) && (x90 == 2))
    {
      c2_printf_dec();
      convert = 1;
      return;
    }

    if((ptr_type == 1) && (bkl == 0) && (bkr == 2) && (x90 == 2))
    {
      c2_printf_str1();
      convert = 1;
      return;
    }

    if((ptr_type == 2) && (bkl == 0) && (bkr == 2) && (x90 == 2))
    {
      c2_printf_dec1();
      convert = 1;
      return;
    }

    if((ptr_type == 1) && (bkl == 0) && (bkr == 0) && (x90 == 2))
    {
      c2_printf_str2();
      convert = 1;
      return;
    }

}


void c2_printf_dec()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_dec");
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
   int s;
   int v;
   int p102;

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
     strcpy(trace_1, "c2z_print.c #1");
     trace_rec_3();
   }
   work_use_ct[67]++;

   strcpy(a_string, "         LARL  R8,C370ZERO");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c #2");
     trace_rec_3();
   }
   work_use_ct[32]++;

   strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c #3");
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
         strcpy(trace_1, "c2z_print.c #4");
         trace_rec_3();
       }
       strcpy(field12, w_constant[x3].const_use);

       strcpy(a_string, "         LARL  R8,C370WTOB");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_print.c #5");
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
         strcpy(trace_1, "c2z_print.c #6");
         trace_rec_3();
       }
       p_ln_ct = p_ln_ct + x5; 
       break;
     }
   }

   strcpy(a_string, "         LARL  R9,C370EDN");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c #7");
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
     strcpy(trace_1, "c2z_print.c #8");
     trace_rec_3();
   }

   strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c #9");
     trace_rec_3();
   }

   strcpy(a_string, "         LARL  R15,WTOIMVC");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c #10");
     trace_rec_3();
   }

   strcpy(a_string, "         BAKR  0,R15");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c #11");
     trace_rec_3();
   }

   strcpy(a_string, "         LARL  R9,C370WTOB");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c #12");
     trace_rec_3();
   }

   strcpy(a_string, "         LARL  R8,C370L10");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c #13");
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
     strcpy(trace_1, "c2z_print.c #14");
     trace_rec_3();
   }
   p_ln_ct = p_ln_ct + 10; 

   if(p102 == 1)
   {
     strcpy(a_string, "         LARL  R15,WTOALPHA");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #15");
       trace_rec_3();
     }

     strcpy(a_string, "         BAKR  0,R15");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #16");
       trace_rec_3();
     }
     p_ln_ct = 0;
   }
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
    strcpy(trace_1, "c2z_print.c #20");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #21");
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
    strcpy(trace_1, "c2z_print.c #22");
    trace_rec_3();
  }

  if(p102 == 0)
  {

    strcpy(a_string, "         LARL  R8,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #23");
      trace_rec_3();
    }
    work_use_ct[52]++;

    p_ln_ct = p_ln_ct + x5;
    strcpy(a_string, "         MVC   ");
    snprintf(ptr_lgth, sizeof(ptr_lgth), "%d", p_ln_ct);
    strcat(a_string, ptr_lgth);
    strcat(a_string, "(");
    strcat(a_string, "1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #24");
      trace_rec_3();
    }
    p_ln_ct++;
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #25");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #26");
      trace_rec_3();
    }
    p_ln_ct = 0;
  }
  
  printf_convert = 1;
}


void c2_printf_str1(void)
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_str1");
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
   int fd2_type;

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
  while (ch != ']') 
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
    strcpy(trace_1, "c2z_print.c #30");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, w_constant[x3].const_use);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #31");
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
    strcpy(trace_1, "c2z_print.c #32");
    trace_rec_3();
  }

  p_ln_ct = p_ln_ct + x1;

  pi = 0;
  while (ch != '"') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != '[') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  fd2_type = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if(x2 == 0) 
    {
      if(isdigit(ch)) 
      {
   	 fd2_type = 2;
        x2 = 1;
      }
      if(isalpha(ch)) 
      {
	 fd2_type = 1;
        x2 = 1;
      }
    }
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  print_array = 0;

  if(gv_ct > 0) 
  {
    for(I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if(ret == 0) 
      {
        strcpy(field1a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
        strcpy(field4, gw_variable[I].gv_type);
      }
    }
  }

  ret = strcmp(field4, "A");
  if(ret == 0) 
  {
    if(gv_ct > 0) 
    {
      for(I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
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
    for(v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field2, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if((ret == 0) && (ret1 == 0)) 
      {
        prf3 = 1;
        strcpy(field2a, lw_variable[v].lv_cname);
        x9 = lw_variable[v].lv_lgth;
        lw_variable[v].lv_use_ct++;
      }
    }

    prf3 = 0;
    for(v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(field2, gw_variable[v].gv_name);
      if(ret == 0) 
      {
        prf3 = 1;
        strcpy(field2a, gw_variable[v].gv_cname);
        x9 = gw_variable[v].gv_lgth;
        gw_variable[v].gv_use_ct++;
      }
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #33");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #34");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #35");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    var_use[1]++;
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #36");
      trace_rec_3();
    }

    strcpy(a_string, "PR");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #37");
      trace_rec_3();
    }

    if(fd2_type == 2) 
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field2);
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #38");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #39");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #40");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #41");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #42");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #43");
        trace_rec_3();
      }
    }

    if (fd2_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #44");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #45");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #46");
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
      strcpy(trace_1, "c2z_print.c #47");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #48");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #49");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #50");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #51");
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
      strcpy(trace_1, "c2z_print.c #52");
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
      strcpy(trace_1, "c2z_print.c #53");
      trace_rec_3();
    }

    strcpy(print_array_name, field10);
    strcpy(print_array_table, field7);

    strcpy(a_string, "         LARL  R9,C370L80");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #54");
      trace_rec_3();
    }
    work_use_ct[10]++;
 
        strcpy(a_string, "         MVC   0(80,R9),0(R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #55");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #56");
          trace_rec_3();
        }
        work_use_ct[50]++;
 
        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #57");
          trace_rec_3();
        }
        work_use_ct[32]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #58");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R2,1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #59");
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
          strcpy(trace_1, "c2z_print.c #60");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #61");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #62");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #63");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #64");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVB   R5,0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #65");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370L80");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #66");
          trace_rec_3();
        }
        work_use_ct[10]++;
 
        strcpy(a_string, "         IC    R0,0(R8,(R5))");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #67");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #68");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         STC   R0,0(0,R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #69");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #70");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         LARL  R8,C370EOF");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #71");
          trace_rec_3();
        }
        work_use_ct[74]++;

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #72");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "M");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #73");
          trace_rec_3();
        }

         strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #74");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #75");
          trace_rec_3();
        }
        work_use_ct[33]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #76");
          trace_rec_3();
        }

        strcpy(a_string, "         AR    R3,R2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #77");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "L");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #78");
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
          strcpy(trace_1, "c2z_print.c #79");
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
          strcpy(trace_1, "c2z_print.c #80");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
        strcat(a_string, wk_strg);
        strcat(a_string, "(");
        snprintf(wk_strg, sizeof(wk_strg), "%d", xc);
        strcat(a_string, wk_strg);
        strcat(a_string, ",R9),0(R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c #81");
          trace_rec_3();
        }
        p_ln_ct = p_ln_ct + xc;

        if(p102 == 1)
        {
          strcpy(a_string, "         LARL  R15,WTOALPHA");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #82");
            trace_rec_3();
          }
    
          strcpy(a_string, "         BAKR  0,R15");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c #83");
            trace_rec_3();
          }
          p_ln_ct = 0; 
          print_array = 1;
          tot_wto++;
        }
     }
}


void c2_printf_dec1()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_dec1");
    trace_rec_1();
  }

  char ch;
  char *p5;
  char *p6;
  char *p7;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field12[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field11[VAR_LGTH];

   int prf1;
   int prf2;
   int prf6;
   int pi;
   int pi2;
   int I;
   int x1;
   int x2;
   int x3;
   int x4;
   int x5;
   int x9;
   int ret;
   int ret1;
   int v;
   int fd2_type = 0;
   int xc;
   int prf3;


    pi = 0;
    pi++;
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
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
 
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != ']')
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #100");
    trace_rec_3();
  }

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

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, w_constant[x3].const_use);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #101");
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
    strcpy(trace_1, "c2z_print.c #102");
    trace_rec_3();
  }

  p_ln_ct = p_ln_ct + x1;

  print_array = 0;

  if(gv_ct > 0) 
  {
    for(I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if(ret == 0) 
      {
        strcpy(field2a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
        strcpy(field4, gw_variable[I].gv_type);
      }
    }
  }


  ret = strcmp(field4, "G");
  if(ret == 0) 
  {
    if(gv_ct > 0) 
    {
      for(I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
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
  }
      
    prf3 = 0;
    for(v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field3, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if((ret == 0) && (ret1 == 0)) 
      {
        prf3 = 1;
        strcpy(field3a, lw_variable[v].lv_cname);
        x9 = lw_variable[v].lv_lgth;
        lw_variable[v].lv_use_ct++;
      }
    }

    prf3 = 0;
    for(v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(field3, gw_variable[v].gv_name);
      if(ret == 0) 
      {
        prf3 = 1;
        strcpy(field3a, gw_variable[v].gv_cname);
        x9 = gw_variable[v].gv_lgth;
        gw_variable[v].gv_use_ct++;
      }
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #103");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #104");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #105");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    var_use[1]++;
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #106");
      trace_rec_3();
    }

    strcpy(a_string, "PR");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #107");
      trace_rec_3();
    }

    if(fd2_type == 2) 
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field2);
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #108");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #109");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #110");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #111");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #112");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #113");
        trace_rec_3();
      }
    }

    if (fd2_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #114");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #115");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #116");
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
      strcpy(trace_1, "c2z_print.c #117");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #118");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #119");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #120");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #121");
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
      strcpy(trace_1, "c2z_print.c #122");
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
      strcpy(trace_1, "c2z_print.c #123");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370EDN");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #124");
        trace_rec_3();
      }
      work_use_ct[51]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #125");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R15,WTOIMVC");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #126");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #127");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370WTOB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #128");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370L10");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #129");
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
        strcpy(trace_1, "c2z_print.c #130");
        trace_rec_3();
      }
      p_ln_ct = p_ln_ct + 10; 

    if(p102 == 1)
    {
      strcpy(a_string, "         LARL  R15,WTOALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #131");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #132");
        trace_rec_3();
      }
      p_ln_ct = 0;
    }

}


void c2_printf_str2()
{
if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_string");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];

   int pi;
   int pi2;
   int s;
   int x1;
   int x3;
   int x5;
   int x9;
   int x11;
   int I;
   int ret;
   int ret1;
   int pf1;
   int prf3;

/*
  char ch;
  char *p6, *p7, *p8;
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

  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield22[VAR_LGTH];
  char tfield22a[VAR_LGTH];

  int pi;
  int pi2;
  int x1 = 0;
  int x2 = 0;
  int x3 = 0;
  int x5 = 0;
  int x9 = 0;
  int x11 = 0;
  int x95 = 0;
  int v = 0;
  int prf1 = 0;
  int prf3 = 0;
  int pf1 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int xc = 0;
  int s;
  int fd22_type = 0;
*/

  p102 = 0;
 
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    if((p_string[I] == '\\') && (p_string[I+1] == 'n'))
    {
      p102++;
    }
  } 
  p102++;

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

  strcpy(a_string, "         MVC   0");
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

/*
  p_ln_ct = x1;
*/


    x11 = 0;
    x9 = 0;
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

    x11 = (75 - x1);

    if(x9 > x11)
    {
       x9 = x11;
    }

    strcpy(a_string, "         MVC   ");

/*
    snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
    strcat(a_string, wk_strg);
*/

    strcat(a_string, "0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #315");
      trace_rec_3();
    }

    p102 = 1;

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

/*
      p_ln_ct = 0;
*/

    }

    if(p102 == 0)
    {
 /*     p_ln_ct = p_ln_ct + x9; */
    }
  



}



void c2_printf_numeric() 
{

}


void c2_printf_string() 
{

}

/*
    if((ptr_type == 2) && (bkl == 0) && (bkr == 0) && (x90 == 2))
    {
      c2_printf_numeric();
      convert = 1;
      return;
    }
*/



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











