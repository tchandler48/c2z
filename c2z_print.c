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

  strcpy(a_string, "         LARL  R8,L");
  strcat(a_string, wk_strg);
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
    strcpy(trace_1, "c2z_print.c #60");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, w_constant[x3].const_use);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #61");
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
    strcpy(trace_1, "c2z_print.c #62");
    trace_rec_3();
  }

  p_ln_ct = p_ln_ct + x1;

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

  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  fd5_type = 0;
  ch = p_string[pi];
  while(ch != ';')
  {
    if (x2 == 0) 
    {
      if(ch == '\'')
      {
        fd5_type = 0;
        x2 = 1;
      }
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

/*  find displacement in array  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1800");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1801");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1802");
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
      strcpy(trace_1, "c2z_printf.c #1803");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1804");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1805");
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
      strcpy(trace_1, "c2z_printf.c #1806");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1807");
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
      strcpy(trace_1, "c2z_printf.c #1808");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1809");
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
      strcpy(trace_1, "c2z_printf.c #1810");
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
      strcpy(trace_1, "c2z_printf.c #1811");
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
      strcpy(trace_1, "c2z_printf.c #1812");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R5,26");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1813");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1814");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1815");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1816");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1817");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1818");
      trace_rec_3();
    }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1819");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1820");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1821");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1822");
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
      strcpy(trace_1, "c2z_printf.c #1823");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1824");
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
      strcpy(trace_1, "c2z_printf.c #1825");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1826");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1827");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1828");
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
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1829");
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
      strcpy(trace_1, "c2z_printf.c #1830");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1831");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1832");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1833");
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
      strcpy(trace_1, "c2z_printf.c #1834");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1835");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1836");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #1837");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_printf.c #1838");
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
    strcpy(trace_1, "c2z_printf.c #1839");
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
    strcpy(trace_1, "c2z_printf.c #1840");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_printf.c #1841");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   ");
  strcat(a_string, "0(6,R9),");
  strcat(a_string, "0(6,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_printf.c #1842");
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
        strcpy(trace_1, "c2z_printf.c #1843");
        trace_rec_3();
      }
      strcpy(field12, w_constant[x3].const_use);

      strcpy(a_string, "         LARL  R8,C370WTOB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_printf.c #1844");
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
            break;
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
              break;
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
        strcpy(trace_1, "c2z_printf.c #1845");
        trace_rec_3();
      }
      p_ln_ct = p_ln_ct + x5; 
      break;
    }
  }

   strcpy(a_string, "         LARL  R15,WTOIMVC");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_printf.c #1846");
     trace_rec_3();
   }

   strcpy(a_string, "         BAKR  0,R15");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_printf.c #1847");
     trace_rec_3();
   }

   strcpy(a_string, "         LARL  R9,C370WTOB");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_printf.c #1848");
     trace_rec_3();
   }

   strcpy(a_string, "         LARL  R8,C370L10");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_printf.c #1849");
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
     strcpy(trace_1, "c2z_printf.c #1850");
     trace_rec_3();
   }
   p_ln_ct = p_ln_ct + 10; 

   if(p102 == 1)
   {
     strcpy(a_string, "         LARL  R15,WTOALPHA");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_printf.c #1851");
       trace_rec_3();
     }

     strcpy(a_string, "         BAKR  0,R15");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_printf.c #1852");
       trace_rec_3();
     }
     p_ln_ct = 0;
   }


/*
3  25     c2z_print.c #10                          LARL  R15,WTOIMVC                                              0000280
3  25     c2z_print.c #11                          BAKR  0,R15                                                    0000281
3  25     c2z_print.c #12                          LARL  R9,C370WTOB                                              0000282
3  25     c2z_print.c #13                          LARL  R8,C370L10                                               0000283
3  25     c2z_print.c #14                          MVC   7(10,R9),0(R8)                                           0000284
3  25     c2z_print.c #15                          LARL  R15,WTOALPHA                                             0000285
3  25     c2z_print.c #16                          BAKR  0,R15                                                    0000286
*/


  convert = 1;





}



void c2_printf_str4()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_printf.c c2_printf_str4");
    trace_rec_1();
  }

printf("\n#100 c2z_printf.c printf_str4 rct = %d p_string = %s",rct,p_string);
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
  while(ch != '"')
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
printf("#100 c2z_print.c printf_str4 field6 = %s x103 = %d\n",field6,x103);

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
printf("#100 c2z_print.c printf_str4 field1 = %s\n",field1);

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
printf("#100 c2z_print.c printf_str4 field2 = %s\n",field2);

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
printf("#100 c2z_print.c printf_str4 field3 = %s\n",field3);

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
      strcpy(trace_1, "c2z_printf.c #2800");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2801");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2802");
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
      strcpy(trace_1, "c2z_printf.c #2803");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2804");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2805");
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
      strcpy(trace_1, "c2z_printf.c #2806");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2807");
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
      strcpy(trace_1, "c2z_printf.c #2808");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2809");
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
      strcpy(trace_1, "c2z_printf.c #2810");
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
      strcpy(trace_1, "c2z_printf.c #2811");
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
      strcpy(trace_1, "c2z_printf.c #2812");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R5,26");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2813");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2814");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2815");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2816");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2817");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2818");
      trace_rec_3();
    }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2819");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2820");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2821");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2822");
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
      strcpy(trace_1, "c2z_printf.c #2823");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2824");
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
      strcpy(trace_1, "c2z_printf.c #2825");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2826");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2827");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2828");
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
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2829");
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
      strcpy(trace_1, "c2z_printf.c #2830");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2831");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2832");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2833");
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
      strcpy(trace_1, "c2z_printf.c #2834");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2835");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2836");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #2837");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_printf.c #2838");
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
    strcpy(trace_1, "c2z_printf.c #2839");
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
    strcpy(trace_1, "c2z_printf.c #2840");
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
        strcpy(trace_1, "c2z_printf.c #2841");
        trace_rec_3();
      }
      strcpy(field12, w_constant[x3].const_use);

      strcpy(a_string, "         LARL  R8,C370WTOB");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_printf.c #2842");
        trace_rec_3();
      }

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

   /*   strcpy(wk_strg, w_constant[x3].const_use); */
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

printf("#100 c2z_print.c #2843 field12 = %s x5 = %d p_ln_ct = %d\n",field12,x5,p_ln_ct);
      snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct); 
      strcpy(a_string, "         MVC   ");
      strcat(a_string, wk_strg); 
      strcat(a_string,"(");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
printf("#100 c2z_print.c #2843 wk_strg = %s\n",wk_strg);
      strcat(a_string, wk_strg);
      strcat(a_string, ",R8),0(R9)");
      strcpy(wk_remark, " printf   */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_printf.c #2843");
        trace_rec_3();
      }
      p_ln_ct = p_ln_ct + x5; 
      break;
    }
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_printf.c #2844");
     trace_rec_3();
   }

   strcpy(a_string, "         MVC   ");
   snprintf(wk_strg, sizeof(wk_strg), "%d", p_ln_ct); 
   strcat(a_string, wk_strg); 
   strcat(a_string, "(32,R9),0(R6)");
   src_line();
   if (puncde == 1) 
   {
     strcpy(trace_1, "c2z_printf.c #2845");
     trace_rec_3();
   }
   p_ln_ct = p_ln_ct + 10; 

   if(p102 == 1)
   {
     strcpy(a_string, "         LARL  R15,WTOALPHA");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_printf.c #2846");
       trace_rec_3();
     }

     strcpy(a_string, "         BAKR  0,R15");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_printf.c #2847");
       trace_rec_3();
     }
     p_ln_ct = 0;
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











