/* ***************************************************
*  c2z : c2z_print.c :                               *
*                                                    *
*  next error = print = 21                           *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out PRINTF conversion.                      *
* ************************************************** */
void c2_printf() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf");
    trace_rec_1();
  }

  char *p;

   int s = 0;
   int I = 0;

  p100 = 0;
  p101 = 0;
  p101d = 0;
  p101s = 0;
  p102 = 0;
  p103 = 0;
  p104 = 0;		/* toupper */
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    if (p_string[I] == '\"') 
    {
      p100++;
    }
    if(p_string[I] == '%')
    {
      p101++;
      if(p_string[I+1] == 's')
      {
        p101s++;
      }
      if(p_string[I+1] == 'd')
      {
        p101d++;
      }
      if(p_string[I+1] == 'c')
      {
        p101s++;
      }
      if(isdigit(p_string[I+1]))
      {
printf("c2z_testprint.c INSIDE #1 isdigit\n");
      }
      if(isdigit(p_string[I+2]))
      {
printf("c2z_testprint.c INSIDE #2 isdigit\n");
      }
      if(p_string[I+3] == 's')
      {
printf("c2z_testprint.c INSIDE #3 format s\n");
        p101s++;
      }
    }
    if((p_string[I] == '\\') && (p_string[I+1] == 'n'))
    {
      p102++;
    }
    if(p_string[I] == '[')
    {
      p103++;
    }
    if(p_string[I] == ']')
    {
      p103++;
    }
  }

  p = strstr(p_string, "toupper");
  if(p)
  {
    p104++;
  }

/*
 printf("c2z_testprint.c rct = %d p_string = %s",rct,p_string);
 printf("c2z_testprint.c p_ln_ct = %d p100 = %d p101 = %d p101d = %d p101s = %d p102 = %d p103 = %d\n",p_ln_ct, p100,p101,p101d,p101s,p102,p103); 
*/
  if (p100 != 2) 
  {
    printf("c2_fprintf Missing Starting Quote\n");
    printf("c2_fprintf rct = %d p_string = %s", rct, p_string);
    c2_debug();
    exit(1);
  }

  

  /* **********************************************************************************
   * p101 = 0  p102 = 2  p103 = 0	 	             Literal ONLY                   *
   * p101 = 1  p101 = 1  p101s = 1 p102 = 2  p103 = 0  Simple %s ONLY                 *
   * p101 = 1  p101s = 1 p103 = 6                      2ds alpha array                *
   * p100 = 2  p101 = 1  p101d = 1 p101s = 0 p103 = 0  Simple %d ONLY                 *
   * p100 = 2  p101 = 1  p101s = 1 p103 = 2            array[x]                       *
   * p100 = 2  p101s = 1 p104 = 1                      toupper                        *
   * ******************************************************************************** */

  if((p101 == 1) && (p101s == 1) && (p103 == 6))
  {
    c2_printf_2ds();
    convert = 1;
    return;
  }

  if((p100 == 2) && (p101 == 1) && (p101s == 1) && (p103 == 2))		/* array[x]  */
  {
    c2_printf_array_string();
    convert = 1;
    return;
  }

  if((p100 == 2) && (p101s == 1) && (p104 == 1))		/* toupper */
  {
    c2_printf_toupper();
    convert = 1;
    return;
  }

  /*  the next three must be LAST in the list */
  if((p100 == 2) && (p101 == 0) && (p103 == 0))		/* literal only */
  {
    c2_printf_literal();
    convert = 1;
    return;
  }

  if((p100 == 2) && (p101 == 1) && (p101s == 1) && (p103 == 0))	/* simple string */
  {
    c2_printf_string();
    convert = 1;
    return;
  }

  if((p100 == 2) && (p101 == 1) && (p101d == 1) && (p101s == 0) && (p103 == 0))	/* simple numeric */
  {
    c2_printf_numeric();
    convert = 1;
    return;
  }
  return;
} 


/* ****************************************************
 *   printf("     ");  Literal Only                   *
 * ************************************************** */
void c2_printf_literal()
{
   if (traceflg == 1) 
   {
     strcpy(trace_1, "c2z_print.c c2_print_literal");
     trace_rec_1();
   }

   char field1[VAR_LGTH];
   char pwk_strg[VAR_LGTH];
   char wk_strg[VAR_LGTH];

    int ret = 0;
    int ret1 = 0;
    int v = 0;
    int x3 = 0;
    int x4 = 0;
    int x5 = 0;
   
   strcpy(field1, "L");
   snprintf(pwk_strg, sizeof(pwk_strg), "%d", rct);
   strcat(field1, pwk_strg);

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

   strcpy(a_string, "         LARL  R9,C370WTOB");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c c2_printf_literal #1");
     trace_rec_3();
   }

   strcpy(a_string, "         LARL  R8,");
   strcat(a_string, wk_strg);
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c c2_printf_literal #2");
     trace_rec_3();
   }

   snprintf(pwk_strg, sizeof(p_ln_ct), "%d", p_ln_ct);
   strcpy(a_string, "         MVC   ");
   strcat(a_string,pwk_strg);
   strcat(a_string, "(");
   snprintf(pwk_strg, sizeof(pwk_strg), "%d", x5);
   strcat(a_string, pwk_strg);
   strcat(a_string, ",R9),0(R8)");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c c2_printf_literal #3");
     trace_rec_3();
   }

   p_ln_ct = p_ln_ct + x5;

   if(p102 != 0)
   { 
     snprintf(pwk_strg, sizeof(p_ln_ct), "%d", p_ln_ct);
     strcpy(a_string, "         LAEY  R0,");
     strcat(a_string, pwk_strg);
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c c2_printf_literal #4");
       trace_rec_3();
     }
      
     strcpy(a_string, "         LARL  R15,WTOALPHA");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c c2_printf_literal #5");
       trace_rec_3();
     }

     strcpy(a_string, "         BAKR  0,R15");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c c2_printf_literal #6");
       trace_rec_3();
     }
     p_ln_ct = 0;
   }
 
   printf_convert = 1;
   convert = 1;
   return;
}



void c2_snprintf()
{

  convert = 1;
  return;
}


void c2_fprintf()
{

  convert = 1;
  return;
}


/* ****************************************************
 *   printf("test = %s",test);  Simple %s             *
 * ************************************************** */
void c2_printf_string() 
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

  char pwk_strg[VAR_LGTH];

  int pi;
  int pi2;
  int x3 = 0;
  int x5 = 0;
  int prf3 = 0;
  int pf1 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;

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

  for (x3 = 0; x3 < v_const; x3++) 
  {
    ret = strcmp(field1, w_constant[x3].const_current);
    if (ret == 0) 
    {
      strcpy(field1, w_constant[x3].const_use);
    }
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_str #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field1);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_str #2");
    trace_rec_3();
  }
  snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
  strcpy(a_string, "         MVC   ");
  strcat(a_string, wk_strg);
  strcat(a_string, "(");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcat(a_string, wk_strg);
  strcat(a_string, ",R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_str #3");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcpy(a_string, "         LARL  R5,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_str #4");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcpy(a_string, "         LAEY  R3,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_str #5");
    trace_rec_3();
  }

   p_ln_ct = p_ln_ct + x5;
 
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
       x5 = lw_variable[I].lv_current_lgth;
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
         x5 = gw_variable[I].gv_current_lgth;
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

   x5 = 0;
   x3 = 0;
   for (I = 0; I < lv_ct; I++) 
   {
     ret = strcmp(field2, lw_variable[I].lv_name);
     ret1 = strcmp(sv_func, lw_variable[I].lv_func);
     if ((ret == 0) && (ret1 == 0)) 
     {
       x3 = 1;
       strcpy(field2a, lw_variable[I].lv_cname);
       x5 = lw_variable[I].lv_lgth;
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
         x5 = gw_variable[I].gv_lgth;
         gw_variable[I].gv_use_ct++;
       }
     }
   }

   if (x3 == 0) 
   {
     printf("\nc2z_print.c c2_printf_string printf-010 tfield2 Not Found = %s\n", field2);
     printf("c2z_print.c c2_printf_string rct = %d p_string = %s", rct, p_string);
     erct++;
     convert = 1;
     return;
   }

   strcpy(a_string, "         LARL  R9,C370WTOB");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c c2_printf_str #6");
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
     strcpy(trace_1, "c2z_print.c c2_printf_str #7");
     trace_rec_3();
   }

   x3 = x5 + p_ln_ct;
   if(x3 > 78)
   {
     x5 = 78 - p_ln_ct;
   }
  
   snprintf(pwk_strg, sizeof(p_ln_ct), "%d", p_ln_ct);
   strcpy(a_string, "         MVC   ");
   strcat(a_string,pwk_strg);
   strcat(a_string, "(");
   snprintf(pwk_strg, sizeof(pwk_strg), "%d", x5);
   strcat(a_string, pwk_strg);
   strcat(a_string, ",R9),0(R8)");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_print.c c2_printf_str #8");
     trace_rec_3();
   }

   /* p_ln_ct = p_ln_ct + x5;
   p_ln_ct++; */

/*   if(p102 != 0)
   { 
*/
     snprintf(pwk_strg, sizeof(p_ln_ct), "%d", p_ln_ct);
     strcpy(a_string, "         LAEY  R0,");
     strcat(a_string, pwk_strg);
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c c2_printf_str #9");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R15,WTOALPHA");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c c2_printf_str #10");
       trace_rec_3();
     }

     strcpy(a_string, "         BAKR  0,R15");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c c2_printf_str #11");
       trace_rec_3();
     }
     p_ln_ct = 0;
 /*  } */
}


/* ****************************************************
 *   printf("test = %s",src[i][j][0]   (string)       *
 * ************************************************** */
void c2_printf_2ds()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_2ds");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];
  char ar_field12[VAR_LGTH];

   int pi;
   int pi2;
   int I;
   int x1;
   int x2;
   int x3;
   int x5;
   int x21;
   int ret;
   int ret1;
   int x100 = 0;
   int x101 = 0;
   int fd4_type = 0;
   int fd5_type = 0;

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
      pi2++;
    }
    pi++;
    ch = p_string[pi];
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

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_2ds #1");
    trace_rec_3();
  }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, w_constant[x3].const_use);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, "0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #3");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcpy(a_string, "         LARL  R5,");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #4");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcpy(a_string, "         LAEY  R3,");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #5");
      trace_rec_3();
    }

    pi = 0;
    ch = p_string[pi];
    while(ch != ',')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if(ch != ' ') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
            x2 = 1;
          }
        }
        field3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    field3[pi2] = '\0';

    pi2 = 0;
    x2 = 0;
    fd4_type = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if (ch != '[') 
      {
        if (x2 == 0) 
        {
          if (isdigit(ch)) 
          {
            fd4_type = 1;
            x2 = 1;
          }
          if (isalpha(ch)) 
          {
            fd4_type = 2;
            x2 = 1;
          }
        }
        field4[pi2] = ch;
        pi2++;
     } 
     pi++;
     ch = p_string[pi];
   }
   field4[pi2] = '\0';

   pi2 = 0;
   x2 = 0;
   fd5_type = 0;
   pi++;
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
     field5[pi2] = ch;
     pi2++;
     pi++;
     ch = p_string[pi];
   }
   field5[pi2] = '\0';

   x21 = 0;
   x3 = 0;
   for (I = 0; I < lv_ct; I++) 
   {
     ret = strcmp(field3, lw_variable[I].lv_name);
     x21 = strcmp(sv_func, lw_variable[I].lv_func);
     if ((ret == 0) && (x21 == 0)) 
     {
       x3 = 1;
       strcpy(field3a, lw_variable[I].lv_cname);
     }
   }

   if (x3 == 0) 
   {
     x3 = 0;
     for (I = 0; I < gv_ct; I++) 
     {
       ret = strcmp(field3, gw_variable[I].gv_name);
       if (ret == 0) 
       {
         x3 = 1;
         strcpy(field3a, gw_variable[I].gv_cname);
         strcpy(ar_field5, gw_variable[I].gv_dsect);
         strcpy(ar_field6, gw_variable[I].gv_label);
         strcpy(ar_field7, gw_variable[I].gv_table);
         strcpy(ar_field8, gw_variable[I].gv_aname);
         strcpy(ar_field9, gw_variable[I].gv_sv_reg);
         strcpy(ar_field10, gw_variable[I].gv_wk_reg);
         strcpy(ar_field11, gw_variable[I].gv_wk_strg);
         strcpy(ar_field12, gw_variable[I].gv_st_col);
         x101 = gw_variable[I].gv_lgth;
         x101 = x101 - 1;
         break;
       }
     }
   }

   if (x3 == 0) 
   {
     printf("\nc2z_printf.c c2_printf_601 E-603 field3 Not Found = %s\n",field3);
     printf("c2z_printf.c c2_printf_601 rct = %d p_string = %s\n",rct,p_string);
     erct++;
     convert = 1;
     return;
   }

   if(fd4_type == 2)
   {
     x21 = 0;
     x3 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field4, lw_variable[I].lv_name);
       x21 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (x21 == 0)) 
       {
         x3 = 1;
         strcpy(field4a, lw_variable[I].lv_cname);
         x100 = lw_variable[I].lv_lgth;
       }
     }

     if (x3 == 0) 
     {
       x3 = 0;
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(field4, gw_variable[I].gv_name);
         if (ret == 0) 
         {
           x3 = 1;
           strcpy(field4a, gw_variable[I].gv_cname);
           break;
         }
       }
     }

     if (x3 == 0) 
     {
       printf("\nc2z_printf.c c2_printf_601 E-604 field4 Not Found = %s\n",field4);
       printf("c2z_printf.c c2_printf_601 rct = %d p_string = %s\n",rct,p_string);
       erct++;
       convert = 1;
       return;
     }
   }

   if(fd5_type == 2)
   {
     x21 = 0;
     x3 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field5, lw_variable[I].lv_name);
       x21 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (x21 == 0)) 
       {
         x3 = 1;
         strcpy(field5a, lw_variable[I].lv_cname);
       }
     }

     if (x3 == 0) 
     {
       x3 = 0;
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(field5, gw_variable[I].gv_name);
         if (ret == 0) 
         {
           x3 = 1;
           strcpy(field5a, gw_variable[I].gv_cname);
         }
       }
     }

     if (x3 == 0) 
     {
       printf("\nc2z_printf.c c2_printf_601 E-605 field5 Not Found = %s\n",field5);
       printf("c2z_printf.c c2_printf_601 rct = %d p_string = %s\n",rct,p_string);
       erct++;
       convert = 1;
       return;
     }
  }

  if(fd4_type == 1)
  {
    strcpy(field4a, field4);
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #6");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #7");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #B");
    trace_rec_3();
  }

  if(fd4_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9f");
      trace_rec_3();
    }
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #9g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #10");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #11");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #12");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #14");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #15");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #16");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #17");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #18");
    trace_rec_3();
  }

  if(fd5_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field5);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19f");
      trace_rec_3();
    }
  }

  if(fd5_type == 2)
  {
    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #19g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R5,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #20");
    trace_rec_3();
  }
 
  strcpy(a_string, "         AP    0(6,R7),0(6,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #21");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #22");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #23");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #24");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #25");
    trace_rec_3();
  }
 
  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "U");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #26");
    trace_rec_3();
  }

  if(fd5_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field5);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27f");
      trace_rec_3();
    }
  }

  if(fd5_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #27");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #28");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #29");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #30");
    trace_rec_3();
  }

  if(fd4_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31f");
      trace_rec_3();
    }
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #31g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #32");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #33");
    trace_rec_3();
  }
 
  strcpy(a_string, "* L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "T");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #34");
    trace_rec_3();
  }

  strcpy(a_string, "*         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #35");
    trace_rec_3();
  }

  strcpy(a_string, "*         LARL  R8,");
  strcat(a_string, field4a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field4);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #36");
    trace_rec_3();
  }

  strcpy(a_string, "*         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #37");
    trace_rec_3();
  }

  strcpy(a_string, "*         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #38");
    trace_rec_3();
  }

  strcpy(a_string, "*         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #39");
    trace_rec_3();
  }

  strcpy(a_string, "*         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #40");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #41");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #42");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, ar_field12);
  strcpy(wk_remark, " ");
  strcat(wk_remark, ar_field12);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #43");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #44");
    trace_rec_3();
  }

  if(fd4_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45f");
      trace_rec_3();
    }
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #45g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #46");
    trace_rec_3();
  }

  if(fd4_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47f");
      trace_rec_3();
    }
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #47");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #48");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #49");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #50");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #51");
    trace_rec_3();
  }

/*  C370NWK1 contains pointer to array element */

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #52");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #53");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #54");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, ar_field7);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #55");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #56");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #57");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #58");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #59");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #60");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #61");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #62");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #63");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #64");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #65");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_601 #66");
    trace_rec_3();
  }


  strcpy(a_string, "         LARL  R9,C370L80");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_print.c c2_printf_2ds #1");
    trace_rec_3();
  }

    strcpy(a_string, "         MVC   0(80,R9),0(R6)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #75");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #76");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #77");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #78");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R2,1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #79");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "L");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #80");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #81");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #82");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #83");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #84");
      trace_rec_3();
    }

    strcpy(a_string, "         CVB   R5,0(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #85");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L80");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #86");
      trace_rec_3();
    }
    work_use_ct[10]++;

    strcpy(a_string, "         IC    R0,0(R8,(R5))");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #87");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #88");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         STC   R0,0(0,R9)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #89");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #90");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #91");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #92");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "M");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #93");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #94");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #95");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #96");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R3,R2");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #97");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "L");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #98");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "M");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf_601 #99");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #100");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x100);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
    strcat(a_string, wk_strg); 
    strcat(a_string, ",R9),0(R6)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #101");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R0,R3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #102");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #103");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_print.c c2_printf_601 #104");
      trace_rec_3();
    }
}


void c2_printf_numeric() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_numeric");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field12[VAR_LGTH];
  
  int pi;
  int pi2;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int v = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;

  pi = 0;
  ch = p_string[pi];
  while (ch != '"') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi = 0;
  ch = p_string[pi];
  while (ch != '%') 
  {
    pi++;
    ch = p_string[pi];
  }

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
    printf("\nc2z_print.c c2_printf Numeric printf-005 field2 Not Found = %s\n",field2);
    printf("c2z_print.c c2_printf rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "         LARL  R9,C370DEC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf %d #40");
    trace_rec_3();
  }
  work_use_ct[67]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf %d #41");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf %d #42");
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
        strcpy(trace_1, "c2z_print.c c2_printf %d #43");
        trace_rec_3();
      }
      strcpy(field12, w_constant[x3].const_use);

      strcpy(a_string, "         LARL  R8,C370WTOB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d #44");
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
      strcat(a_string, "(");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
      strcat(a_string, wk_strg);
      strcat(a_string, ",R8),0(R9)");
      strcpy(wk_remark, " printf   */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d #45");
        trace_rec_3();
      }
      p_ln_ct = p_ln_ct + x5;
 

      snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
      strcpy(a_string, "         LAEY  R3,");
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c c2_printf %d #46");
        trace_rec_3();
      }

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
    strcpy(trace_1, "c2z_print.c c2_printf %d #47");
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
    strcpy(trace_1, "c2z_print.c c2_printf %d #48");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf %d #49");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R15,WTOIMVC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf %d #50");
    trace_rec_3();
  }

  strcpy(a_string, "         BAKR  0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf %d #51");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf %d #52");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf %d #53");
    trace_rec_3();
  }
  work_use_ct[71]++;

  snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct);
  strcpy(a_string, "         MVC   ");
  strcat(a_string, wk_strg);
  strcat(a_string, "(");
  strcat(a_string, "10,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
     strcpy(trace_1, "c2z_print.c c2_printf %d #54");
     trace_rec_3();
  }
  p_ln_ct = p_ln_ct + x5;
  p_ln_ct++;

  if(p_ln_ct != 0)
  {
    strcpy(a_string, "         LAEY  R2,10");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf %d #55");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R3,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf %d #56");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R0,R3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf %d #57");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf %d #58");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c c2_printf %d #59");
      trace_rec_3();
    }
    p_ln_ct = 0;
  }
  convert = 1;
  return;
}


void c2_printf_toupper()
{
   if (traceflg == 1) 
   {
     strcpy(trace_1, "c2z_print.c c2_print_toupper");
     trace_rec_1();
   }
printf("c2z_printf.c c2_print_touuper rct = %d p_string = %s",rct,p_string);

   convert = 1;
   return;
}


void c2_printf_array_string()
{
   if (traceflg == 1) 
   {
     strcpy(trace_1, "c2z_print.c c2_print_array_string");
     trace_rec_1();
   }

   char ch;
   char field1[VAR_LGTH];
   char field1a[VAR_LGTH];
   char field1b[VAR_LGTH];
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

    int pi;
    int pi2;
    int x1 = 0;
    int x2;
    int x3;
    int x9;
    int xc;
    int prf1 = 0;
    int prf3;
    int ret;
    int ret1;
    int I;
    int v;
    int fd22_type;

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

    print_array = 0;

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
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #7");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #8");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #9");
          trace_rec_3();
        }
        work_use_ct[32]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        var_use[1]++;
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #10");
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
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #11");
          trace_rec_3();
        }

        if (fd22_type == 2) 
        {
          strcpy(a_string, "         LAEY  R5,");
          strcat(a_string, tfield22);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12a");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL R9,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12b");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         CVD  R5,0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12c");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL R9,C370NWK2");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12d");
            trace_rec_3();
          }
          work_use_ct[50]++;

          strcpy(a_string, "         LARL R8,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12e");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         ZAP  0(6,R9),0(8,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12f");
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
            strcpy(trace_1, "c2z_print.c c2_printf_str[] #12g");
            trace_rec_3();
          }
        }

        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #13");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #14");
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
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #15");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #16");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #17");
          trace_rec_3();
        }
        work_use_ct[33]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #18");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, field6);
        strcat(a_string, "(R0,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #19");
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
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #20");
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
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #21");
          trace_rec_3();
        }

        strcpy(print_array_name, field10);
        strcpy(print_array_table, field7);

        strcpy(a_string, "         LARL  R9,C370L80");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #22");
          trace_rec_3();
        }
        work_use_ct[10]++;
 
        strcpy(a_string, "         MVC   0(80,R9),0(R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #23");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #24");
          trace_rec_3();
        }
        work_use_ct[50]++;
 
        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #25");
          trace_rec_3();
        }
        work_use_ct[32]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #26");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R2,1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #27");
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
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #28");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #29");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #30");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #31");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #32");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVB   R5,0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #33");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370L80");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #34");
          trace_rec_3();
        }
        work_use_ct[10]++;
 
        strcpy(a_string, "         IC    R0,0(R8,(R5))");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #35");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #36");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         STC   R0,0(0,R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #37");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #38");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         LARL  R8,C370EOF");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #39");
          trace_rec_3();
        }
        work_use_ct[74]++;

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #40");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "M");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #41");
          trace_rec_3();
        }

         strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #42");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #43");
          trace_rec_3();
        }
        work_use_ct[33]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #44");
          trace_rec_3();
        }

        strcpy(a_string, "         AR    R3,R2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #45");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   PR");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "L");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #46");
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
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #47");
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
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #48");
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
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #49");
          trace_rec_3();
        }

        strcpy(a_string, "         LR    R0,R3");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #50");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R15,WTOALPHA");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #51");
          trace_rec_3();
        }
    
        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_print.c c2_printf_str[] #52");
          trace_rec_3();
        }

        p_ln_ct = 0;
        print_array = 1;
        tot_wto++;
      }

      
    }
    return;
}


