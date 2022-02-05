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
   int x93 = 0;
   int x93a = 0;
   int x94 = 0;
   int x94a = 0;
   int I;
   int x90 = 0;
   int x100;
   int ptr_type = 0;
   int str1 = 0;
   int str2 = 0;
   int bkl = 0;
   int bkr = 0;
   int pi;
   int fd_percent = 0;

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
      if(str1 != 0)
      {
        bkr++;
      }
    }
    if(ch == ']')
    {
      if(str1 != 0)
      {
        bkr++;
      }
    }
    if (ch == '\"') 
    {
      x90++;
    }
    if(ch == '.')
    {
      if(x93 == 0)
      {
        x93a = I;
      }
      x93++;
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
 

      if(ptr_type == 0)
      {
        fd_percent = 0;
        s = strlen(p_string);
        pi = 0;
        ch = p_string[pi];
        while(pi < s)
        {
          if(ch == '%')
          {
            fd_percent = 1;
          }
          if(fd_percent == 1)
          {
            if(ch == 's')
            {
              ptr_type = 1;
              break;
            }
            if(ch == 'd')
            {
              ptr_type = 2;
              break;
            }
            if(ch == 'f')
            {
              ptr_type = 3;
              break;
            }
          }
          pi++;
          ch = p_string[pi];
        }
      }
    }

 
/*
printf("\nc2z_print.c #99 ptr_type = %d rct = %d p_string = %s\n",ptr_type,rct,p_string);
*/

 
/* ************************************************************************ */
/*       BKL         BKR       x90(.)	type                              */ 
/*       0     ,     0          0     	 0	c2_printf_literal  (only)  */
/*       0     ,     0          0		 2     c2_printf_dec              */
/*       0     ,     2          0		 1     c2_printf_str1             */
/*       0     ,     0          0		 1     c2_printf_str2             */
/*	  0     ,     2          1          1	c2_printf_str3	      */
/*       0     ,     2          0		 2     c2_printf_dec1             */
/*       0     ,     4          -          2     c2_printf_dec2             */
/*       0     ,     4          0          1     c2_printf_str4             */
/*                                            				      */
/*  Literal only     ptr_type = 0             				      */
/*  String           ptr_type = 1             				      */
/*  Decimal          ptr_type = 2             				      */
/*  Float            ptr_type = 3             				      */ 
/* ************************************************************************ */


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

    if((ptr_type == 1) && (bkl == 0) && (bkr == 2) && (x90 == 2) && (x93 == 0))
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

    if((ptr_type == 2) && (bkl == 0) && (bkr == 4) && (x90 == 2))
    {
      c2_printf_dec2();
      convert = 1;
      return;
    }

    if((ptr_type == 1) && (bkl == 0) && (bkr == 0) && (x90 == 2))
    {
      c2_printf_str2();
      convert = 1;
      return;
    }

    if((ptr_type == 1) && (bkl == 0) && (bkr == 2) && (x90 == 2) && (x93 == 1))
    {
      c2_printf_str3();
      convert = 1;
      return;
    }

    if((ptr_type == 1) && (bkl == 0) && (bkr == 4) && (x90 == 2))
    {
      c2_printf_str4();
      convert = 1;
      return;
    }


printf("\nc2z_print.c ERROR NOT MATCH FOUND rct = %d p_string = %s",rct,p_string);
printf("c2z_print.c #1 rct = %d p_string = %s",rct,p_string);
printf("c2z_print.c #1 ptr_type = %d bkl = %d bkr = %d x90 = %d x93 = %d \n",ptr_type,bkl,bkr,x90,x93);

}


void c2_printf_dec()		/* NEW */
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
  char prt_lit[VAR_LGTH];

   int prf1;
   int prf2;
   int prf6;
   int pi;
   int pi2;
   int I;
   int x1;
   int x3;
   int x4;
   int x5;
   int x9;
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

   strcpy(field1, "L");
   snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
   strcat(field1, wk_strg);

   for (x3 = 0; x3 < v_const; x3++) 
   {
     ret = strcmp(field1, w_constant[x3].const_current);
     if (ret == 0) 
     {
       strcpy(prt_lit, w_constant[x3].const_use);
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

       strcpy(prt_lit, w_constant[x3].const_use);
       if (x4 == 0) 
       {
         if (gv_ct > 0) 
         {
           for (v = 0; v < gv_ct; v++) 
           {
             ret = strcmp(prt_lit, gw_variable[v].gv_name);
             if (ret == 0) 
             {
               x4 = 1;
               x5 = gw_variable[v].gv_lgth;
               gw_variable[v].gv_use_ct++;
             }
           }
         }
       }
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

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1");
    trace_rec_3();
  }
  work_use_ct[49]++;

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

  if(x5 == 0)		/* K */
  {
    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "T");
    check_length();
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2843a");
      trace_rec_3();
    }
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #7");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #9");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #10");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #11");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #12");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, prt_lit);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #14");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #15");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #16");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #17");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #18");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #19");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #20");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #21");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #22");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #23");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #24");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #25");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #26");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #27");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #28");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #29");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #30");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #31");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #32");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #33");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #34");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "T");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2871");
    trace_rec_3();
  }

  strcpy(a_string, "*  start moving alpha field now that literal is moved");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #35");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #36");
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
     strcpy(trace_1, "c2z_print.c #37");
     trace_rec_3();
   }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #38");
    trace_rec_3();
  }
   
  strcpy(a_string, "         LARL  R15,WTOIMVC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #39");
    trace_rec_3();
  }

  strcpy(a_string, "         BAKR  0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #xxx");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #40");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #41");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #42");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R4,10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #43");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #44");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #45");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #46");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #47");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #48");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #49");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #50");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #51");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #52");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #53");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #54");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #55");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #56");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #57");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #58");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #59");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #60");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #61");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #62");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #62a");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #62b");
    trace_rec_3();
  }

  strcpy(a_string, "*         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #62c");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #63");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #64");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #65");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #66");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #70a");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #67");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #68");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #69");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #70");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #71");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #72");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #73");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #74");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #75");
      trace_rec_3();
    }
  }

}



void c2_printf_decxxx()		/* remove after all dec printf processed */
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
  char prt_lit[VAR_LGTH];

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
      strcpy(prt_lit, w_constant[x3].const_use);

      x5 = 0;
      x4 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(prt_lit, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x4 = 1;
            lw_variable[v].lv_use_ct++;
            x5 = lw_variable[v].lv_lgth;
          }
        }
      }

      strcpy(prt_lit, w_constant[x3].const_use);
      if (x4 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(prt_lit, gw_variable[v].gv_name);
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



  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #21");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #22");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #23");
    trace_rec_3();
  }

  if(x5 == 0)		/* K */
  {
    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "T");
    check_length();
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2843a");
      trace_rec_3();
    }
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #24");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #25");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #26");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #27");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #28");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #29");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #30");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, prt_lit);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #31");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #32");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #33");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #34");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #35");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #36");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #37");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #38");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #39");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #40");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #41");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #42");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #43");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #44");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #45");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #46");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #47");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #48");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #49");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #50");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #51");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "T");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #51a");
    trace_rec_3();
  }


  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #52");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #53");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #54");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #55");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #56");
      trace_rec_3();
    }
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

printf("\nc2z_printf.c str1 rct = %d p_string = %s",rct,p_string);

  char ch;
  char *p6;
  char *p7;
  char *p8;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field1b[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
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
   int fd3_type;

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

  pi = 0;
  while (ch != ',') 
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
    if(ch != ' ')
    {
      field1[pi2] = ch;
      pi2++;
    }
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
  }

printf("c2z_printf.c str1 field1 = %s\n",field1);
printf("c2z_printf.c str1 field2 = %s fd2_type = %d\n",field2,fd2_type);

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #601");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #602");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #603");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    var_use[1]++;
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #604");
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
      strcpy(trace_1, "c2z_print.c #605");
      trace_rec_3();
    }

    if(fd3_type == 2) 
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #606");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #607");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #608");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #609");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #610");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #611");
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
        strcpy(trace_1, "c2z_print.c #612");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #613");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #614");
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
      strcpy(trace_1, "c2z_print.c #615");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #616");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #617");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #618");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #619");
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
      strcpy(trace_1, "c2z_print.c #620");
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
      strcpy(trace_1, "c2z_print.c #621");
      trace_rec_3();
    }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #622");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #623");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #624");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #624a");
    trace_rec_3();
  }
  work_use_ct[10]++;

  strcpy(a_string, "         MVC   0(80,R9),0(R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #624b");
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

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x1);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #625");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #626");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #627");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #628");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #629");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #630");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #631");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field1);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #632");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #633");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #634");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #635");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #636");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #637");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #638");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #639");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #640");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #641");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #642");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #643");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #644");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #645");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #646");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #647");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #648");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #649");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #650");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #651");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #652");
    trace_rec_3();
  }

  strcpy(a_string, "*  start moving alpha field now that literal is moved");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #653");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #649");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #650");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #651");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R4,80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #654");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #655");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #656");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #657");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #658");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #659");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #660");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #661");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #662");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #663");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #664");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #665");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #666");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #667");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #668");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #669");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #670");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #671");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #672");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #673");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #674");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #675");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #676");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #677");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #678");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #679");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #680");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #682");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #683");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #684");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #685");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #681");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #686");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #687");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #688");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #689");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #690");
      trace_rec_3();
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
   int fd3_type = 0;
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
    x2 = 0;
    fd2_type = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if (ch != ' ') 
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
      }
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';
 
    pi2 = 0;
    x2 = 0;
    fd3_type = 0;
    pi++;
    ch = p_string[pi];
    while(ch != ']')
    {
      if(x2 == 0) 
      {
        if(isdigit(ch)) 
        {
   	   fd3_type = 2;
          x2 = 1;
        }
        if(isalpha(ch)) 
        {
	   fd3_type = 1;
          x2 = 1;
        }
      }
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

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
      strcpy(trace_1, "c2z_print.c #501");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #502");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #503");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    var_use[1]++;
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #504");
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
      strcpy(trace_1, "c2z_print.c #505");
      trace_rec_3();
    }

    if(fd3_type == 2) 
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #506");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #507");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #508");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #509");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #510");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #511");
        trace_rec_3();
      }
    }



    if (fd3_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #512");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #513");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #514");
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
      strcpy(trace_1, "c2z_print.c #515");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #516");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #517");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #518");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #519");
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
      strcpy(trace_1, "c2z_print.c #520");
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
      strcpy(trace_1, "c2z_print.c #521");
      trace_rec_3();
    }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #522");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #523");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #524");
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

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x1);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #525");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #526");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #527");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #528");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #529");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #530");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #531");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field1);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #532");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #533");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #534");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #535");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #536");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #537");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #538");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #539");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #540");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #541");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #542");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #543");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #544");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #545");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #546");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #547");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #548");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #549");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #550");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #551");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #552");
    trace_rec_3();
  }

  strcpy(a_string, "*  start moving alpha field now that literal is moved");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #553");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #554");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #555");
    trace_rec_3();
  }
   
  strcpy(a_string, "         LARL  R15,WTOIMVC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #556");
    trace_rec_3();
  }

  strcpy(a_string, "         BAKR  0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #557");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #558");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #559");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #560");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R4,10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #561");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #562");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #563");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #564");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #565");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #566");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #567");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #568");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #569");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #570");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #571");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #572");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #573");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #574");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #575");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #576");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #577");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #578");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #579");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #580");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #581");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #582");
    trace_rec_3();
  }

  strcpy(a_string, "*         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #583");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #584");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #585");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #586");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #587");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #588");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #589");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #590");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #591");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #592");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #593");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #594");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #595");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #596");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #597");
      trace_rec_3();
    }
  }
}


void c2_printf_str2()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_str2");
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
      x9 = lw_variable[I].lv_current_lgth;
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
        x9 = gw_variable[I].gv_current_lgth;
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



  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1");
    trace_rec_3();
  }
  work_use_ct[49]++;

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

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x1);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #7");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #9");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #10");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #11");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #12");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,L");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #14");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #15");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #16");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #17");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #18");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #19");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #20");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #21");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #22");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #23");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #24");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #25");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #26");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #27");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #28");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #29");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #30");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #31");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #32");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #33");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #34");
    trace_rec_3();
  }

  strcpy(a_string, "*  start moving alpha field now that literal is moved");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #xxx");
    trace_rec_3();
  }


  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #xxx");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #xxx");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #xxx");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x9);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #xxx");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #xxx");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #9");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #10");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #11");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #12");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field2a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #14");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #15");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #16");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #17");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #18");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #19");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #20");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #21");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #22");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #23");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #24");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #25");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #26");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #27");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #28");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #29");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #30");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #31");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #32");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #33");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #34");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #35");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #36");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #37");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #38");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #39");
      trace_rec_3();
    }
  }



/*
  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #200");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, w_constant[x3].const_use);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #201");
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
    strcpy(trace_1, "c2z_print.c #202");
    trace_rec_3();
  }
  p_ln_ct = p_ln_ct + x1;



  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #203");
    trace_rec_3();
  }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #204");
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
      strcpy(trace_1, "c2z_print.c #205");
      trace_rec_3();
    }
    p_ln_ct = p_ln_ct + x9;

*/




/*
    if(p102 == 1)
    {
      strcpy(a_string, "         LARL  R15,WTOALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #206");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #207");
        trace_rec_3();
      }
      p_ln_ct = 0;
    }
*/
}


void c2_sprintf(void)
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_sprintf");
    trace_rec_1();
  }

  char *p;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];

   int pi;
   int si;
   int bk_ct = 0;
   int len;
   int I;
   int ret;
   int ret1;
   int pf1;
   int prf3;
   int x3;
   int is_dec;

   bk_ct = 0;
   len = strlen(p_string);
   for(I = 0; I < len; I++)
   {
     ch = p_string[I];
     if(ch == '[')
     {
       bk_ct++;
     }
     if(ch == ']')
     {
       bk_ct++;
     }
   }

   if(bk_ct == 2)
   {
     convert = 1;
     return;
   }

   if(bk_ct == 4)
   {
     pi = 0;
     ch = p_string[pi];
     while(ch != '(')
     {
       pi++;
       ch = p_string[pi];
     }

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != '[')
     {
       field1[si] = ch;
       si++;
       pi++;
       ch = p_string[pi];
     }
     field1[si] = '\0';

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != ']')
     {
       field2[si] = ch;
       si++;
       pi++;
       ch = p_string[pi];
     }
     field2[si] = '\0';

     si = 0;
     pi++;
     pi++;
     ch = p_string[pi];
     while(ch != ']')
     {
       field3[si] = ch;
       si++;
       pi++;
       ch = p_string[pi];
     }
     field3[si] = '\0';

     pi++;
     ch = p_string[pi];
     while(ch != '\"')
     {
       pi++;
       ch = p_string[pi];
     }

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != '\"')
     {
       field4[si] = ch;
       si++;
       pi++;
       ch = p_string[pi];
     }
     field4[si] = '\0';

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != ')')
     {
       if(ch != ',')
       {
         if(ch != ' ')
         {
           field5[si] = ch;
           si++;
         }
       }
       pi++;
       ch = p_string[pi];
     }
     field5[si] = '\0';

     x3 = 0;
     for (I = 0; I < gv_ct; I++) 
     {
       ret = strcmp(field1, gw_variable[I].gv_name);
       if (ret == 0) 
       {
         x3 = 1;
         strcpy(field1a, gw_variable[I].gv_cname);
         strcpy(ar_field5, gw_variable[I].gv_dsect);
         strcpy(ar_field6, gw_variable[I].gv_label);
         strcpy(ar_field7, gw_variable[I].gv_table);
         strcpy(ar_field8, gw_variable[I].gv_aname);
       }
     }

     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field2, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         pf1 = 1;
         strcpy(field2a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
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
     
     pf1 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field3, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         pf1 = 1;
         strcpy(field3a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
         break;
       }
     }

     if (pf1 == 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         prf3 = strcmp(field3, gw_variable[I].gv_name);
         if (prf3 == 0) 
         {
           pf1 = 1;
           strcpy(field3a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
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

     pf1 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field5, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         pf1 = 1;
         strcpy(field5a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
         break;
       }
     }

     if (pf1 == 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         prf3 = strcmp(field5, gw_variable[I].gv_name);
         if (prf3 == 0) 
         {
           pf1 = 1;
           strcpy(field5a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
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

/*  find displacement in array  */

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #800");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         LARL  R8,C370ZERO");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #801");
       trace_rec_3();
     }
     work_use_ct[32]++;

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #802");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,");
     strcat(a_string, field2a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field2);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #803");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370ZERO");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #804");
       trace_rec_3();
     }
     work_use_ct[32]++;

     strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #805");
       trace_rec_3();
     }

     strcpy(a_string, "         JLNE  ");
     strcat(a_string, "L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "A");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #806");
       trace_rec_3();
     }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #807");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         LARL  R8,");
     strcat(a_string, field2a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field2);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #808");
       trace_rec_3();
     }

     strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #809");
       trace_rec_3();
     }

     strcpy(a_string, "         JLU   ");
     strcat(a_string, "L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "E");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #810");
       trace_rec_3();
     }

/* ROW IS GREATER THAN ZERO  */
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcpy(a_string, "L");
     strcat(a_string, wk_strg);
     strcat(a_string, "A");
     check_length();
     strcat(a_string, "DS    0H");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #811");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,");
     strcat(a_string, field2a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field2);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #812");
       trace_rec_3();
     }

     strcpy(a_string, "         LAEY  R5,26");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #813");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R7,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #814");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         CVD   R5,0(R7)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #815");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370NWK2");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #816");
       trace_rec_3();
     }
     work_use_ct[50]++;

     strcpy(a_string, "         LARL  R7,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #817");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #818");
       trace_rec_3();
     }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #819");
       trace_rec_3();
     }
     work_use_ct[50]++;

     strcpy(a_string, "         LARL  R8,C370NWK2");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #820");
       trace_rec_3();
     }
     work_use_ct[50]++;

     strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #821");
       trace_rec_3();
     }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #822");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         LARL  R8,");
     strcat(a_string, field3a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field3);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #823");
       trace_rec_3();
     }

     strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #824");
       trace_rec_3();
     }

/* END OF ROUTINE C370NWK1 CONTAINS DISPLAYMENT */
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcpy(a_string, "L");
     strcat(a_string, wk_strg);
     strcat(a_string, "E");
     check_length();
     strcat(a_string, "DS    0H");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #825");
       trace_rec_3();
     }

     is_dec = 0;
     p = strstr(field4, "%d");
     if(p)
     {
       is_dec = 1;
     }

     p = strstr(field4, "%.2f");
     if(p)
     {
       is_dec = 2;
     }

     if(is_dec == 1)
     {

       strcpy(a_string, "         LARL  R9,C370EDN");
        src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_print.c #826");
         trace_rec_3();
       }
     work_use_ct[51]++;

     strcpy(a_string, "         LARL  R8,");
     strcat(a_string, field5a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field5);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #901");
       trace_rec_3();
     }

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #902");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R15,WTOIMVC");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #903");
       trace_rec_3();
     }

     strcpy(a_string, "         BAKR  0,R15");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #904");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370L10");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #905");
       trace_rec_3();
     }

     strcpy(a_string, "         MVC   0(R6),0(R8)");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #905");
       trace_rec_3();
     }

       convert = 1;
       return;
     }

     if(is_dec == 2)
     {

     strcpy(a_string, "         LARL  R9,C370EDN");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #826");
       trace_rec_3();
     }
     work_use_ct[51]++;

     strcpy(a_string, "         LARL  R8,");
     strcat(a_string, field5a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field5);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #901");
       trace_rec_3();
     }

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #902");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R15,WTOIMVC");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #903");
       trace_rec_3();
     }

     strcpy(a_string, "         BAKR  0,R15");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #904");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370L10");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #905");
       trace_rec_3();
     }

     strcpy(a_string, "         MVC   0(R6),0(R8)");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #906");
       trace_rec_3();
     }

     convert = 1;
     return;
     }
   }


   if(bk_ct == 0)
   {

     pi = 0;
     ch = p_string[pi];
     while(ch != '(')
     {
       pi++;
       ch = p_string[pi];
     }

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != ',')
     {
       field1[si] = ch;
       si++;
       pi++;
       ch = p_string[pi];
     }
     field1[si] = '\0';

     pi++;
     ch = p_string[pi];
     while(ch != '\"')
     {
       pi++;
       ch = p_string[pi];
     }

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != '\"')
     {
       field2[si] = ch;
       si++;
       pi++;
       ch = p_string[pi];
     }
     field2[si] = '\0';

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != ')')
     {
       if(ch != ',')
       {
         if(ch != ' ')
         {
           field3[si] = ch;
           si++;
         }
       }
       pi++;
       ch = p_string[pi];
     }
     field3[si] = '\0';

     pf1 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field1, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         pf1 = 1;
         strcpy(field1a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
         break;
       }
     }

     if (pf1 == 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         prf3 = strcmp(field1, gw_variable[I].gv_name);
         if (prf3 == 0) 
         {
           pf1 = 1;
           strcpy(field1a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
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


     pf1 = 0;
     for (I = 0; I < lv_ct; I++) 
     {
       ret = strcmp(field3, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         pf1 = 1;
         strcpy(field3a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
         break;
       }
     }

     if (pf1 == 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         prf3 = strcmp(field3, gw_variable[I].gv_name);
         if (prf3 == 0) 
         {
           pf1 = 1;
           strcpy(field3a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
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

     is_dec = 0;
     p = strstr(field4, "%d");
     if(p)
     {
       is_dec = 1;
     }

     p = strstr(field4, "%.2f");
     if(p)
     {
       is_dec = 2;
     }

     if(is_dec == 1)
     {
       strcpy(a_string, "         LARL  R9,C370EDN");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_print.c #826");
         trace_rec_3();
       }
       work_use_ct[51]++;

       strcpy(a_string, "         LARL  R8,");
       strcat(a_string, field5a);
       strcpy(wk_remark, " ");
       strcat(wk_remark, field5);
       strcat(wk_remark, " */");
       write_remark();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #901");
         trace_rec_3();
       }

       strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
       src_line();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #902");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R15,WTOIMVC");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_print.c #903");
         trace_rec_3();
       }

       strcpy(a_string, "         BAKR  0,R15");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_print.c #904");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R9,");
       strcat(a_string, field1a);
       strcpy(wk_remark, " ");
       strcat(wk_remark, field1);
       strcat(wk_remark, " */");
       write_remark();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #905");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R8,C370L10");
       src_line();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #905");
         trace_rec_3();
       }

       strcpy(a_string, "         MVC  0(R9),0(R8)");
       src_line();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #906");
         trace_rec_3();
       }
   
       convert = 1;
       return;
     }

    if(is_dec == 2)
    {
printf("c2z_print.c springf no brackets is_dec 2 NOT CODED\n");    
      convert = 1;
      return;
    }



    convert = 1;
    return;
  }
}



void c2_printf_str3()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_str3");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];

  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield6a[VAR_LGTH];

   int x1;
   int x3;
   int x5;
   int ret;
   int ret1;
   int I;
   int pi;
   int pi2;
   int s;
   int x9;
   int x95;
   int fd2_type = 0;

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
    strcpy(trace_1, "c2z_print.c #300");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, w_constant[x3].const_use);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #301");
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
    strcpy(trace_1, "c2z_print.c #302");
    trace_rec_3();
  }
  p_ln_ct = p_ln_ct + x1;

  pi = 0;
  ch = p_string[pi];
  while(ch != ',')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != '[') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  x3 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if ((isdigit(ch)) && (x3 == 0)) 
    {
      fd2_type = 2;
      x3 = 1;
    }
    if ((isalpha(ch)) && (x3 == 0)) 
    {
      fd2_type = 1;
      x3 = 1;
    }
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ')')
  {
    if(ch != '.')
    {
      field3[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(field1, w_struc[I].st_name);
    if(ret == 0)
    {
       x3 = 1;
       strcpy(field1a, w_struc[I].st_cname);
       break;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_print.c c2_str_3 print-059 tfield1 Not Found = %s\n", field1);
    printf("c2z_print.c c2_str_3 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
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
    while (ch != '[') 
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
    while (ch != ']') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != '.') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < m_struc_ct; I++) 
    {
      ret = strcmp(tfield1, w_struc[I].st_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield1a, w_struc[I].st_cname);
        strcpy(tfield6a, w_struc[I].st_cname);
        break;
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_print.c c2_printf_string Structure printf-012 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_print.c c2_printf_string rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_print.c c2_printf_string Structure printf-013 tfield2 Not Found = %s\n",tfield2);
      printf("c2z_print.c c2_printf_string rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < m_struc_ct; I++) 
    {
      ret = strcmp(tfield1, w_struc[I].st_name);
      ret1 = strcmp(tfield3, w_struc[I].st_field_name);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield3a, w_struc[I].st_field_cname);
        x9 = w_struc[I].st_field_lgth;
        x95 = w_struc[I].st_disp;
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_print.c c2_printf_string Structure printf-014 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_print.c c2_printf_string rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #303");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #304");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #305");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "T");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #306");
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
      strcpy(trace_1, "c2z_printf.c #307");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #308");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #309");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #310");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #311");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, tfield6a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #312");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #313");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #314");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #315");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #316");
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
      strcpy(trace_1, "c2z_printf.c #317");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R2,");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #318");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R3,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #319");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R0,R3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #320");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #321");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x95);
    strcat(a_string, wk_strg);
    strcat(a_string, "(R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #322");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #323");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #324");
      trace_rec_3();
    }
    p_ln_ct = 0;

}


void c2_printf_dec2()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_printf.c c2_printf_dec2");
    trace_rec_1();
  }

   int pi;
   int pi2;
   int fd1_type;
   int fd2_type;
   int fd3_type;
   int fd5_type;
   int x2;
   int x3;
   int x4;
   int x5;
   int ret;
   int ret1;
   int x21;
   int x100;
   int x101;
   int x102;
   int I;
   int v;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field12[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];
  char ar_field12[VAR_LGTH];

  char prt_lit[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while(ch != ',')
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  fd1_type = 0;
  pi2 = 0;
  while(ch != '[')
  {
    if(ch != ',')
    {
      if (x2 == 0) 
      {
        if(ch == '\'')
        {
          fd1_type = 0;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd1_type = 1;
          x2 = 1;
        }
        if (isalpha(ch)) 
        {
          fd1_type = 2;
          x2 = 1;
        }
      }
      field1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  fd2_type = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    if (x2 == 0) 
    {
      if(ch == '\'')
      {
        fd2_type = 0;
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        fd2_type = 1;
        x2 = 1;
      }
      if (isalpha(ch)) 
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

  pi2 = 0;
  x2 = 0;
  fd3_type = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    if (x2 == 0) 
    {
      if(ch == '\'')
      {
        fd3_type = 0;
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        fd3_type = 1;
        x2 = 1;
      }
      if (isalpha(ch)) 
      {
        fd3_type = 2;
        x2 = 1;
      }
    }
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while(ch != ' ')
  {
    field4[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';

  strcpy(field4, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(field4, wk_strg);

  for (x3 = 0; x3 < v_const; x3++) 
  {
    ret = strcmp(field4, w_constant[x3].const_current);
    if (ret == 0) 
    {
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
      strcpy(prt_lit, w_constant[x3].const_use);

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
    }
  }

printf("\nc2z_print.c dec2 rct = %d p_string = %s",rct,p_string);
printf("c2z_print.c dec2 field1 = %s\n",field1);
printf("c2z_print.c dec2 field2 = %s fd2_type = %d\n",field2,fd2_type);
printf("c2z_print.c dec2 field3 = %s fd3_type = %d\n",field3,fd3_type);
printf("c2z_print.c dec2 field4 = %s x5 = %d\n",field4,x5);
printf("c2z_print.c dec2 wk_strg = %s\n",wk_strg);

  x3 = 0;
  if (x3 == 0) 
  {
    x3 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field1a, gw_variable[I].gv_cname);
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
        x102 = gw_variable[I].gv_column;
      }
    }
  }

  if(fd2_type == 2)
  {
    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        x100 = lw_variable[I].lv_lgth;
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_printf.c c2_printf_dec2 E-604a field2 Not Found = %s\n",field2);
      printf("c2z_printf.c c2_printf_dec2 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd3_type == 2)
  {
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
        x100 = lw_variable[I].lv_lgth;
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_printf.c c2_printf_dec E-604b field3 Not Found = %s\n",field3);
      printf("c2z_printf.c c2_printf_dec2 rct = %d p_string = %s\n",rct,p_string);
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
        x100 = lw_variable[I].lv_lgth;
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_printf.c c2_printf_dec2 E-604c field5 Not Found = %s\n",field5);
      printf("c2z_printf.c c2_printf_dec2 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3100");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3101");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3102");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3103");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "U");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3104");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3105");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3106");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3107");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3108");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3109");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, prt_lit);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3110");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3111");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3112");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3113");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3114");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3115");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3116");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3117");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3118");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3119");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3120");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3121");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3122");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3123");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3124");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3125");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3126");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3127");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3128");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3129");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3130");
    trace_rec_3();
  }

/*  find displacement in array  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3131");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3132");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3133");
      trace_rec_3();
    }

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3134");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3135");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3136");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3137");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3138");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3139");
        trace_rec_3();
      }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3140");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3141");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3142");
      trace_rec_3();
    }

    strcpy(a_string, "         JLNE  ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3143");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3144");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3145");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3146");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3147");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3148");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3149");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3150");
        trace_rec_3();
      }
    }

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3151");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3152");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3153");
      trace_rec_3();
    }

/* ROW IS GREATER THAN ZERO  */
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3154");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3155");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R5,26");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3156");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3157");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3158");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3159");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3160");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3161");
      trace_rec_3();
    }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3162");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3163");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3164");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3165");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3166");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3167");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3168");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3169");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3170");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3171");
        trace_rec_3();
      }
    }

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #3172");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3173");
      trace_rec_3();
    }

/* END OF ROUTINE C370NWK1 CONTAINS DISPLAYMENT */
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3174");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3175");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3176");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3177");
      trace_rec_3();
    }

    if (gv_ct > 0) 
    {
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(field1, gw_variable[I].gv_name);
         if (ret == 0) 
         {
           x2 = 1;
           strcpy(field1a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
           strcpy(ar_field5, gw_variable[I].gv_dsect);
           strcpy(ar_field6, gw_variable[I].gv_label);
           strcpy(ar_field7, gw_variable[I].gv_table);
           strcpy(ar_field8, gw_variable[I].gv_aname);
           strcpy(ar_field9, gw_variable[I].gv_sv_reg);
           strcpy(ar_field10, gw_variable[I].gv_wk_reg);
           strcpy(ar_field11, gw_variable[I].gv_wk_strg);
         }
       }
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3178");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3179");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3180");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3181");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3182");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3183");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3184");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3185");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3186");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3187");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "F");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3188");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "G");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3189");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3190");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3191");
    trace_rec_3();
  }
   
  strcpy(a_string, "         LARL  R15,WTOIMVC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3192");
    trace_rec_3();
  }

  strcpy(a_string, "         BAKR  0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3193");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3194");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3195");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3196");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R4,10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3197");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3198");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3199");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3200");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3201");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3202");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3203");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3204");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3205");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3206");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3207");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3208");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3209");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3210");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3211");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3212");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3213");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3214");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3215");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3216");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3217");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3218");
    trace_rec_3();
  }

  strcpy(a_string, "*         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "M");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3219");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3220");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3221");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3222");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3223");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "M");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3224");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3225");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3226");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3227");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3228");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3229");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3230");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3231");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3232");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3233");
      trace_rec_3();
    }
  }

  convert = 1;

}



void c2_printf_str4()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_printf.c c2_printf_str4");
    trace_rec_1();
  }

   int pi;
   int pi2;
   int fd1_type;
   int fd2_type;
   int fd3_type;
   int fd5_type;
   int x2;
   int x3;
   int x4;
   int x5;
   int ret;
   int ret1;
   int x21;
   int x100;
   int x101;
   int x102;
   int x103;
   int I;
   int v;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field12[VAR_LGTH];
  char field13[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];
  char ar_field12[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while(ch != '"')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x103 = 0;
  pi++;
  pi++; 
  ch = p_string[pi];

  while(isdigit(ch))
  {
    if(ch == 's')
    {
      break;
    }
    field6[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
    x103++;
  }
  field6[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch != ',')
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  fd1_type = 0;
  pi2 = 0;
  while(ch != '[')
  {
    if(ch != ',')
    {
      if (x2 == 0) 
      {
        if(ch == '\'')
        {
          fd1_type = 0;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd1_type = 1;
          x2 = 1;
        }
        if (isalpha(ch)) 
        {
          fd1_type = 2;
          x2 = 1;
        }
      }
      field1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  fd2_type = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    if (x2 == 0) 
    {
      if(ch == '\'')
      {
        fd2_type = 0;
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        fd2_type = 1;
        x2 = 1;
      }
      if (isalpha(ch)) 
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

  pi2 = 0;
  x2 = 0;
  fd3_type = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    if (x2 == 0) 
    {
      if(ch == '\'')
      {
        fd3_type = 0;
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        fd3_type = 1;
        x2 = 1;
      }
      if (isalpha(ch)) 
      {
        fd3_type = 2;
        x2 = 1;
      }
    }
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  x3 = 0;
  if (x3 == 0) 
  {
    x3 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field1a, gw_variable[I].gv_cname);
        strcpy(ar_field5, gw_variable[I].gv_dsect);
        strcpy(ar_field6, gw_variable[I].gv_label);
        strcpy(ar_field7, gw_variable[I].gv_table);
        strcpy(ar_field8, gw_variable[I].gv_aname);
        strcpy(ar_field9, gw_variable[I].gv_sv_reg);
        strcpy(ar_field10, gw_variable[I].gv_wk_reg);
        strcpy(ar_field11, gw_variable[I].gv_wk_strg);
        strcpy(ar_field12, gw_variable[I].gv_st_col);
        x101 = gw_variable[I].gv_lgth;
        x102 = gw_variable[I].gv_column;
      }
    }
  }

  if(fd2_type == 2)
  {
    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        x100 = lw_variable[I].lv_lgth;
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_printf.c c2_printf_str4 E-604 field2 Not Found = %s\n",field2);
      printf("c2z_printf.c c2_printf_str4 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd3_type == 2)
  {
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
        x100 = lw_variable[I].lv_lgth;
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_printf.c c2_printf_603 E-604 field3 Not Found = %s\n",field3);
      printf("c2z_printf.c c2_printf_603 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

/*  find displacement in array  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2800");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2801");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2802");
      trace_rec_3();
    }

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2803");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2804");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2805");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2806");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2807");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2808");
        trace_rec_3();
      }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2809");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2810");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2811");
      trace_rec_3();
    }

    strcpy(a_string, "         JLNE  ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2812");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2813");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2814");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2815");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2816");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2817");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2818");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2819");
        trace_rec_3();
      }
    }

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2820");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2821");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2822");
      trace_rec_3();
    }

/* ROW IS GREATER THAN ZERO  */
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2823");
      trace_rec_3();
    }

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2824");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2825");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2826");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2827");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2828");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2829");
        trace_rec_3();
      }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2830");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2831");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2832");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LAEY  R5,26");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2833");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2834");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2835");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2836");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2837");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2838");
      trace_rec_3();
    }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2839");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2840");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2841");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2842");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2843");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2844");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2845");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2846");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2847");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2848");
        trace_rec_3();
      }
    }

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #2849");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2850");
      trace_rec_3();
    }

/* END OF ROUTINE C370NWK1 CONTAINS DISPLAYMENT */
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2851");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2852");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2853");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2854");
      trace_rec_3();
    }

    if (gv_ct > 0) 
    {
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(field1, gw_variable[I].gv_name);
         if (ret == 0) 
         {
           x2 = 1;
           strcpy(field1a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
           strcpy(ar_field5, gw_variable[I].gv_dsect);
           strcpy(ar_field6, gw_variable[I].gv_label);
           strcpy(ar_field7, gw_variable[I].gv_table);
           strcpy(ar_field8, gw_variable[I].gv_aname);
           strcpy(ar_field9, gw_variable[I].gv_sv_reg);
           strcpy(ar_field10, gw_variable[I].gv_wk_reg);
           strcpy(ar_field11, gw_variable[I].gv_wk_strg);
         }
       }
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2855");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2856");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2857");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2858");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2859");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2860");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2861");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2862");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2863");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2864");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "F");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2865");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "G");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2866");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2867");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2868");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2869");
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
      strcpy(field12, w_constant[x3].const_use);

      /* strcpy(wk_strg, w_constant[x3].const_use); */
      x4 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field12, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x4 = 1;
            x5 = lw_variable[v].lv_lgth;
            lw_variable[I].lv_use_ct++;
          }
        }
      }

      if (x4 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(field12, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              x4 = 1;
              x5 = gw_variable[v].gv_lgth;
              gw_variable[v].gv_use_ct++;
            } 
          }
        }
      }
    }
  }


  if((x5 == 0) && (x103 == 0))	
  {
    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "T");
    check_length();
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2870");
      trace_rec_3();
    }
  }

  if((x5 == 0) && (x103 == 0))
  {
    goto skip_print_zero;
  }

  if((x5 != 0) && (x103 == 0))
  {
    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "U");
    check_length();
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2871");
      trace_rec_3();
    }
  }

  if((x5 != 0) && (x103 == 0))
  {
    goto skip_print_one;
  }

  strcpy(a_string, "         LARL  R7,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2872");
    trace_rec_3();
  }
  work_use_ct[10]++;

  snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
  strcpy(a_string, "         MVC   0(");
  strcat(a_string, wk_strg);
  strcat(a_string, ",R7),0(R6)");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2873");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2874");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2875");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2876");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2877");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2878");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2879");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2880");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "M");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2881");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2882");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2883");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2884");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2885");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2886");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2887");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2888");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2889");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2890");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2891");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2892");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2893");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "N");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2894");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2895");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2896");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2897");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "M");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2898");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "N");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2899");
    trace_rec_3();
  }
 
  strcpy(a_string, "*  C370NWK3 contains # of characters to be printed");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2900");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,");
  strcat(a_string, field6);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2901");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2902");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVD   R5,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2903");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2904");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2905");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2906");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2907");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2908");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2909");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2910");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2911");
    trace_rec_3();
  }

  strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2912");
    trace_rec_3();
  }

 
  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "O");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2913");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2914");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2915");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2916");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2917");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2918");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2919");
    trace_rec_3();
  }
 
  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2920");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2921");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2922");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2923");
    trace_rec_3();
  }
  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2924");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2925");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2926");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2927");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2928");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2929");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2930");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2931");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2932");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "O");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2933");
    trace_rec_3();
  }

 

  goto skip_print_zero;	/* end of printf("%18s", sheet[x][y])  */


  skip_print_one:

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "U");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2934");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2935");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "H");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2936");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2937");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2938");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2939");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2940");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2941");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field12);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2942");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2943");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2944");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2945");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2946");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2947");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2948");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2949");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2950");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2951");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2952");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2953");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2954");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2955");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2956");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2957");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2958");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2959");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2960");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2961");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2962");
    trace_rec_3();
  }

  skip_print_zero:

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "T");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2963");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2964");
    trace_rec_3();
  }
  work_use_ct[10]++;

  snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
  strcpy(a_string, "         MVC   0(");
  strcat(a_string, wk_strg);
  strcat(a_string, ",R9),0(R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2965");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2966");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2967");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2968");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2969");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "J");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2970");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2971");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2972");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2973");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2974");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2975");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2976");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2977");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2978");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2979");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2981");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2982");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2983");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2984");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2985");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2986");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2987");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2988");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2989");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2990");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2991");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "K");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2992");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2993");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2994");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2995");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2996");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2997");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2998");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2999");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "J");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3000");
    trace_rec_3();
  }

  print_end:

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "K");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #3001");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3002");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3003");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3004");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3005");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #3006");
      trace_rec_3();
    }
  }

  convert = 1;
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


void c2_fprintf()
{
}


void c2_snprintf()
{
}











