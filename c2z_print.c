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
   int x93 = 0;
   int x94 = 0;
   int I;
   int x90 = 0;
   int ptr_type = 0;
   int str1 = 0;
   int bkl = 0;
   int bkr = 0;
   int pi;
   int fd_percent = 0;

  printf_convert = 0;

  s = strlen(p_string);
  p102 = 0;

  str1 = 0;
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
        str1 = I;
      }
      x94++;
    }
    if(ch == '[')
    {
      if(str1 != 0)
      {
        bkl++;
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
      if(str1 != 0)
      {
        x93++;
      }
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

 
 
/* ************************************************************************ */
/*       BKL         BKR       x93(.)    x90(q)	type                              */ 
/*       0     ,     0          0     	        0	c2_printf_literal  (only)  */
/*       0     ,     0          0		        2     c2_printf_dec              */
/*       0     ,     2          0		        1     c2_printf_str1             */
/*       0     ,     0          0		        1     c2_printf_str2             */
/*	  0     ,     2          1                 1	c2_printf_str3	      */
/*       0     ,     2          0		        2     c2_printf_dec1                                                      */
/*       2     ,     2          0         2       2     c2_printf_dec2   printf("spreadsheet = %d\n",spreadsheet[i9][jj]);  */
/*       0     ,     4          0                 1     c2_printf_str4   printf("%18s src = %s\n",src[i9][jj]);             */
/*       1     ,     1          1                 2     c2_printf_dec5   printf("k gv_lgth = %d\n",gw_variable[3].gv_lgth); */
/*       1     ,     1          0         2       2     c2_printf_dec6   printf("#g iv_stack = %d\n",iv_stack[2];           */
/*       1     ,     1          1         2       1     c2_printf_str5   printf("gv_name = %s\n",gw_variable[x].gv_name);   */
/*       1     ,     1          0         2       1     c2_printf_str6   printf("#g sv_stack = %s\n",sv_stack[2];           */

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

    if((ptr_type == 2) && (bkl == 2) && (bkr == 2) && (x90 == 2) && (x93 == 0))
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

    if((ptr_type == 2) && (bkl == 1) && (bkr == 1) && (x90 == 2) && (x93 == 1))
    {
      c2_printf_dec5();
      convert = 1;
      return;
    }

			/* printf("#g iv_stack = %d\n",iv_stack[2]; */ 
    if((ptr_type == 2) && (bkl == 1) && (bkr == 1) && (x90 == 2) && (x93 == 0))
    {
      c2_printf_dec6();
      convert = 1;
      return;
    }

    if((ptr_type == 1) && (bkl == 1) && (bkr == 1) && (x90 == 2) && (x93 == 1))
    {
      c2_printf_str5();
      convert = 1;
      return;
    }

			/* printf("#g sv_stack = %s\n",sv_stack[2]; */ 
    if((ptr_type == 1) && (bkl == 1) && (bkr == 1) && (x90 == 2) && (x93 == 0))
    {
      c2_printf_str6();
      convert = 1;
      return;
    }



printf("\nc2z_print.c ERROR NOT MATCH FOUND rct = %d p_string = %s",rct,p_string);
printf("c2z_print.c       [    bkl = %d\n",bkl);
printf("c2z_print.c       ]    bkr = %d\n",bkr);
printf("c2z_print.c   quote    x90 = %d\n",x90);
printf("c2z_print.c       .    x93 = %d\n",x93);
printf("c2z_print.c    type    prt_type = %d\n",ptr_type);
printf("c2z_print.c    p102    p102 = %d\n",p102);

}


void c2_printf_dec()		/* NEW */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_print.c c2_printf_dec");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char prt_lit[VAR_LGTH];

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

   if(x3 == 0)
   {
     printf("c2z_print.c c2_print_dec field2 NOT FOUND = %s\n",field2);
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
             lw_variable[v].lv_use_ct++;
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
      strcpy(trace_1, "c2z_print.c #4");
      trace_rec_3();
    }
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #5");
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
    strcpy(trace_1, "c2z_print.c #6");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #7");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #8");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #9");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #10");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #11");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, prt_lit);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #12");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #14");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #15");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #16");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #17");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #18");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #19");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
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

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #22");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #23");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #24");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #25");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #26");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #27");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #28");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #29");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #30");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #31");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #32");
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
    strcpy(trace_1, "c2z_print.c #33");
    trace_rec_3();
  }

  strcpy(a_string, "*  start moving alpha field now that literal is moved");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #34");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #35");
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
     strcpy(trace_1, "c2z_print.c #36");
     trace_rec_3();
   }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #37");
    trace_rec_3();
  }
   
  strcpy(a_string, "         LARL  R15,WTOIMVC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #38");
    trace_rec_3();
  }

  strcpy(a_string, "         BAKR  0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #39");
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
    strcpy(trace_1, "c2z_print.c #63");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #64");
    trace_rec_3();
  }

  strcpy(a_string, "*         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #65");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #66");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #67");
    trace_rec_3();
  }
  work_use_ct[49]++;

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

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #70");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #71");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #72");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #73");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #74");
    trace_rec_3();
  }

printf("c2z_print.c #75 rct = %d p102 = %d\n",rct,p102);
  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #75");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #76");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #77");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #78");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #79");
      trace_rec_3();
    }
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
    strcpy(trace_1, "c2z_print.c #100");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #101");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #102");
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
      strcpy(trace_1, "c2z_print.c #103");
      trace_rec_3();
    }
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #104");
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
    strcpy(trace_1, "c2z_print.c #105");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #106");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #107");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #108");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #109");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #110");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, prt_lit);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #111");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #112");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #113");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #114");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #115");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #116");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #117");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #118");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #119");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #120");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #121");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #122");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #123");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #124");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #125");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #126");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #127");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #128");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #129");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #130");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #131");
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
    strcpy(trace_1, "c2z_print.c #132");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #133");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #134");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #135");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #136");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #137");
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
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field4[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field11[VAR_LGTH];

   int I;
   int pi;
   int pi2;
   int s;
   int x1;
   int x2;
   int x3;
   int x5;
   int v;
   int ret;
   int ret1;
   int fd2_type;
   int fd3_type = 0;

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
          gw_variable[I].gv_flag = 1;
        }
      }
    }
      
    for(v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field2, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if((ret == 0) && (ret1 == 0)) 
      {
        strcpy(field2a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
      }
    }

    for(v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(field2, gw_variable[v].gv_name);
      if(ret == 0) 
      {
        strcpy(field2a, gw_variable[v].gv_cname);
        gw_variable[v].gv_use_ct++;
      }
    }
  }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #201");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #202");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #203");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    var_use[1]++;
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #204");
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
      strcpy(trace_1, "c2z_print.c #205");
      trace_rec_3();
    }

    if(fd3_type == 2) 
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #206");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #207");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #208");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #209");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #210");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #211");
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
        strcpy(trace_1, "c2z_print.c #212");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #213");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #214");
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
      strcpy(trace_1, "c2z_print.c #215");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #216");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #217");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #218");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #219");
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
      strcpy(trace_1, "c2z_print.c #220");
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
      strcpy(trace_1, "c2z_print.c #221");
      trace_rec_3();
    }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #222");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #223");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #224");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #225");
    trace_rec_3();
  }
  work_use_ct[10]++;

  strcpy(a_string, "         MVC   0(80,R9),0(R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #226");
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
    strcpy(trace_1, "c2z_print.c #227");
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
    strcpy(trace_1, "c2z_print.c #228");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #229");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #230");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #231");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #232");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #233");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field1);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #234");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #235");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #236");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #237");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #238");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #239");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #240");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #241");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #242");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #243");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #244");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #245");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #246");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #247");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #248");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #249");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #250");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #251");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #252");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #253");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #254");
    trace_rec_3();
  }

  strcpy(a_string, "*  start moving alpha field now that literal is moved");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #255");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #256");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #257");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #258");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R4,80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #259");
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
    strcpy(trace_1, "c2z_print.c #260");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #261");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #262");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #263");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #264");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #265");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #266");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #267");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #268");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #269");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #270");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #271");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #272");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #273");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #274");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #275");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #276");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #277");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #278");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #279");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #280");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #281");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #282");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #283");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #284");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #285");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #286");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #287");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #288");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #289");
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
    strcpy(trace_1, "c2z_print.c #290");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #291");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #292");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #293");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #294");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #295");
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
  char field1[VAR_LGTH];
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

   int pi;
   int pi2;
   int I;
   int x1;
   int x2;
   int x3;
   int x5;
   int ret;
   int ret1;
   int v;
   int fd3_type = 0;

    pi = 0;
    pi++;
    while (ch != ',') 
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

/*
printf("\nc2z_print.c dec1 rct = %d p_string = %s",rct,p_string);
printf("c2z_print.c dec1 field1 = %s\n",field1);
printf("c2z_print.c dec1 field2 = %s\n",field2);
printf("c2z_print.c dec1 field4 = %s\n",field4);
*/
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
          gw_variable[I].gv_flag = 1;
        }
      }
    }
  }

/*
printf("c2z_print.c dec1 field5 = %s\n",field5);
printf("c2z_print.c dec1 field6 = %s\n",field6);
printf("c2z_print.c dec1 field7 = %s\n",field7);
*/
      
    for(v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field3, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if((ret == 0) && (ret1 == 0)) 
      {
        strcpy(field3a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
      }
    }

    for(v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(field3, gw_variable[v].gv_name);
      if(ret == 0) 
      {
        strcpy(field3a, gw_variable[v].gv_cname);
        gw_variable[v].gv_use_ct++;
      }
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #301");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #302");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #303");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    var_use[1]++;
    if(puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #304");
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
      strcpy(trace_1, "c2z_print.c #305");
      trace_rec_3();
    }

    if(fd3_type == 2) 
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #306");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #307");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if(puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #308");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #309");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #310");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #311");
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
        strcpy(trace_1, "c2z_print.c #312");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #313");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #314");
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
      strcpy(trace_1, "c2z_print.c #315");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #316");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #317");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #318");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #319");
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
      strcpy(trace_1, "c2z_print.c #320");
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
      strcpy(trace_1, "c2z_print.c #321");
      trace_rec_3();
    }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #322");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #323");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #324");
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
    strcpy(trace_1, "c2z_print.c #325");
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
    strcpy(trace_1, "c2z_print.c #326");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #327");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #328");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #329");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #330");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #331");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field1);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #332");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #333");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #334");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #335");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #336");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #337");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #338");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #339");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #340");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #341");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #342");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #343");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #344");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #345");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #346");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #347");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #348");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #349");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #350");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #351");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #352");
    trace_rec_3();
  }

  strcpy(a_string, "*  start moving alpha field now that literal is moved");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #353");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #354");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #355");
    trace_rec_3();
  }
   
  strcpy(a_string, "         LARL  R15,WTOIMVC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #356");
    trace_rec_3();
  }

  strcpy(a_string, "         BAKR  0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #357");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #358");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #359");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #360");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R4,10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #361");
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
    strcpy(trace_1, "c2z_print.c #362");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #363");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #364");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #365");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #366");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #367");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #368");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #369");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #370");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #371");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #372");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #373");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #374");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #375");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #376");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #377");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #378");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #379");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #380");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #381");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #382");
    trace_rec_3();
  }

  strcpy(a_string, "*         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #383");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #384");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #385");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #386");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #387");
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
    strcpy(trace_1, "c2z_print.c #388");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #389");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #390");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #391");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #392");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #393");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #394");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #395");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #396");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #397");
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
   int x10;
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
  x1 = 0;
  x5 = 0;
  for (x3 = 0; x3 < v_const; x3++) 
  {
    ret = strcmp(field1, w_constant[x3].const_current);
    if (ret == 0) 
    {
      strcpy(field1, w_constant[x3].const_use);
      x3 = 1;
      break;
    }
  }

  if(x3 == 0)
  {
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
        x3 = 1;
        break;
      }
    }
  }

  if(x3 == 0)
  {
    x5 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x5 = 1;
        x1 = gw_variable[I].gv_lgth;
        gw_variable[I].gv_use_ct++;
        x3 = 1;
        break;
      }
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
        break;
      }
    }
  }

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
      x10 = lw_variable[I].lv_lgth;
      if((x9 == 0) && (x10 != 0))
      {
         x9 = x10;
      }
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
	 x10 = gw_variable[I].gv_lgth;
        if((x9 == 0) && (x10 != 0))
        {
           x9 = x10;
        }
        break;
      }
    }
  }

  if (pf1 == 0) 
  {
    printf("\nc2z_print.c str2 printf-009 Missing field after format statement\n");
    printf("c2z_print.c str2 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #401");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #402");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #403");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", x1);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #404");
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
    strcpy(trace_1, "c2z_print.c #405");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #406");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #407");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #408");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #409");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #410");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field1);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #411");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #412");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #413");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #414");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #415");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #416");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #417");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #418");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #419");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #420");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #421");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #422");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #423");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #424");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #425");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #426");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #427");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #428");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #429");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #430");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #431");
    trace_rec_3();
  }

  strcpy(a_string, "*  start moving alpha field now that literal is moved");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #432");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #433");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #434");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #435");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x9);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #436");
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
    strcpy(trace_1, "c2z_print.c #437");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #438");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #439");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #440");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #441");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #442");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field2a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #443");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #444");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #445");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #446");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #447");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #448");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #449");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #450");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #451");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #452");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #453");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #454");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #455");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #456");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #457");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #458");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #459");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #460");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #461");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #462");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #463");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #464");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #465");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #466");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #467");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #468");
      trace_rec_3();
    }
  }
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

     si = 0;
     pi++;
     ch = p_string[pi];
     while(ch != ',')
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
       if(ch != ' ')
       {
         field3[si] = ch;
         si++;
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
       printf("\nc2z_print.c c2_snprintf printf-009 Missing field after format statement\n");
       printf("c2z_print.c c2_snprintf rct = %d p_string = %s\n",rct,p_string);
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
       printf("\nc2z_print.c c2_snprintf printf-009 Missing field after format statement\n");
       printf("c2z_print.c c2_snprintf rct = %d p_string = %s\n",rct,p_string);
       erct++;
       convert = 1;
       return;
     }
 
     strcpy(a_string, "         LARL  R9,C370EDN");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #500");
       trace_rec_3();
     }
 
     strcpy(a_string, "         LARL  R8,");
     strcat(a_string, field3a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field3);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #501");
       trace_rec_3();
     }

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #502");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R15,WTOIMVC");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #503");
       trace_rec_3();
     }
 
     strcpy(a_string, "         BAKR  0,R15");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #504");
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
       strcpy(trace_1, "c2z_print.c #505");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370L10");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #506");
       trace_rec_3();
     }
 
     strcpy(a_string, "         MVC   0(10,R9),0(R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #507");
       trace_rec_3();
     }

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

     for (I = 0; I < gv_ct; I++) 
     {
       ret = strcmp(field1, gw_variable[I].gv_name);
       if (ret == 0) 
       {
         strcpy(field1a, gw_variable[I].gv_cname);
         strcpy(ar_field5, gw_variable[I].gv_dsect);
         strcpy(ar_field6, gw_variable[I].gv_label);
         strcpy(ar_field7, gw_variable[I].gv_table);
         strcpy(ar_field8, gw_variable[I].gv_aname);
       }
     }

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
       printf("\nc2z_print.c c2_snprintf printf-009 Missing field after format statement\n");
       printf("c2z_print.c c2_snprintf rct = %d p_string = %s\n",rct,p_string);
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
       printf("\nc2z_print.c c2_snprintf printf-009 Missing field after format statement\n");
       printf("c2z_print.c c2_snprintf rct = %d p_string = %s\n",rct,p_string);
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
       printf("\nc2z_print.c c2_snprintf printf-009 Missing field after format statement\n");
       printf("c2z_print.c c2_snprintf rct = %d p_string = %s\n",rct,p_string);
       erct++;
       convert = 1;
       return;
     }

/*
printf("\nc2z_print.c case_803 rct = %d p_string = %s",rct,p_string);
printf("c2z_print.c case_803 field1 = %s\n",field1);
printf("c2z_print.c case_803 field2 = %s\n",field2);
printf("c2z_print.c case_803 field3 = %s\n",field3);
printf("c2z_print.c case_803 field4 = %s\n",field4);
printf("c2z_print.c case_803 field5 = %s\n",field5);
*/

/*  find displacement in array  */

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #508");
       trace_rec_3();
     }
     work_use_ct[49]++;

     strcpy(a_string, "         LARL  R8,C370ZERO");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #509");
       trace_rec_3();
     }
     work_use_ct[32]++;

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #510");
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
       strcpy(trace_1, "c2z_print.c #511");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370ZERO");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #512");
       trace_rec_3();
     }
     work_use_ct[32]++;

     strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #513");
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
       strcpy(trace_1, "c2z_print.c #514");
       trace_rec_3();
     }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #515");
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
       strcpy(trace_1, "c2z_print.c #516");
       trace_rec_3();
     }

     strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #517");
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
       strcpy(trace_1, "c2z_print.c #518");
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
       strcpy(trace_1, "c2z_print.c #519");
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
       strcpy(trace_1, "c2z_print.c #520");
       trace_rec_3();
     }

     strcpy(a_string, "         LAEY  R5,26");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #521");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R7,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #522");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         CVD   R5,0(R7)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #523");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370NWK2");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #524");
       trace_rec_3();
     }
     work_use_ct[50]++;

     strcpy(a_string, "         LARL  R7,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #525");
       trace_rec_3();
     }
     work_use_ct[48]++;

     strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #526");
       trace_rec_3();
     }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #527");
       trace_rec_3();
     }
     work_use_ct[50]++;

     strcpy(a_string, "         LARL  R8,C370NWK2");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #528");
       trace_rec_3();
     }
     work_use_ct[50]++;

     strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #529");
       trace_rec_3();
     }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #530");
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
       strcpy(trace_1, "c2z_print.c #531");
       trace_rec_3();
     }

     strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #532");
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
       strcpy(trace_1, "c2z_print.c #533");
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
         strcpy(trace_1, "c2z_print.c #534");
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
       strcpy(trace_1, "c2z_print.c #535");
       trace_rec_3();
     }

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #536");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R15,WTOIMVC");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #537");
       trace_rec_3();
     }

     strcpy(a_string, "         BAKR  0,R15");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_print.c #538");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370L10");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #539");
       trace_rec_3();
     }

     strcpy(a_string, "         MVC   0(R6),0(R8)");
     src_line();
     if (puncde == 1) 
     { 
       strcpy(trace_1, "c2z_print.c #540");
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
         strcpy(trace_1, "c2z_print.c #541");
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
         strcpy(trace_1, "c2z_print.c #542");
         trace_rec_3();
       }

       strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
       src_line();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #543");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R15,WTOIMVC");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_print.c #544");
         trace_rec_3();
       }

       strcpy(a_string, "         BAKR  0,R15");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_print.c #545");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R8,C370L10");
       src_line();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #546");
         trace_rec_3();
       }

       strcpy(a_string, "         MVC   0(10,R6),0(R8)");
       src_line();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #547");
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
       printf("\nc2z_print.c c2_snprintf printf-009 Missing field after format statement\n");
       printf("c2z_print.c c2_snprintf rct = %d p_string = %s\n",rct,p_string);
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
       printf("\nc2z_print.c c2_snprintf printf-009 Missing field after format statement\n");
       printf("c2z_print.c c2_snprintf rct = %d p_string = %s\n",rct,p_string);
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
         strcpy(trace_1, "c2z_print.c #548");
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
         strcpy(trace_1, "c2z_print.c #549");
         trace_rec_3();
       }

       strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
       src_line();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #550");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R15,WTOIMVC");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_print.c #551");
         trace_rec_3();
       }

       strcpy(a_string, "         BAKR  0,R15");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_print.c #552");
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
         strcpy(trace_1, "c2z_print.c #553");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R8,C370L10");
       src_line();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #554");
         trace_rec_3();
       }

       strcpy(a_string, "         MVC  0(R9),0(R8)");
       src_line();
       if (puncde == 1) 
       { 
         strcpy(trace_1, "c2z_print.c #555");
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
    strcpy(trace_1, "c2z_print.c #600");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, w_constant[x3].const_use);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #601");
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
    strcpy(trace_1, "c2z_print.c #602");
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
    pi2++;
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ')')
  {
    if(ch != '.')
    {
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
 

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
      printf("\nc2z_print.c c2_printf_str3 printf-012 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_print.c c2_printf_str3 rct = %d p_string = %s", rct,p_string);
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
      printf("\nc2z_print.c c2_printf_str3 printf-013 tfield2 Not Found = %s\n",tfield2);
      printf("c2z_print.c c2_printf_str3 rct = %d p_string = %s", rct,p_string);
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
      printf("\nc2z_print.c c2_printf_str3 printf-014 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_print.c c2_printf_str3 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #603");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #604");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #605");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "T");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #606");
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
      strcpy(trace_1, "c2z_printf.c #607");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #608");
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
      strcpy(trace_1, "c2z_printf.c #609");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #610");
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
      strcpy(trace_1, "c2z_printf.c #611");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, tfield6a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #612");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #613");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #614");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #615");
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
      strcpy(trace_1, "c2z_printf.c #616");
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
      strcpy(trace_1, "c2z_printf.c #617");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R2,");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #618");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R3,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #619");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R0,R3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #620");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370WTOB");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #621");
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
      strcpy(trace_1, "c2z_printf.c #622");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #623");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_printf.c #624");
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
   int fd2_type;
   int fd3_type;
   int x2;
   int x3;
   int x4;
   int x5;
   int ret;
   int ret1;
   int x21;
   int x101;
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

  while(isdigit(ch))
  {
    if(ch == 'd')
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
  pi2 = 0;
  while(ch != '[')
  {
    if(ch != ',')
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
      printf("\nc2z_printf.c c2_printf_dec2 E-604 field2 Not Found = %s\n",field2);
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
      printf("\nc2z_printf.c c2_printf_dec2 E-604 field3 Not Found = %s\n",field3);
      printf("c2z_printf.c c2_printf_dec2 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

/*
printf("\nc2z_print.c dec2 rct = %d p_string = %s",rct,p_string);
printf("c2z_print.c dec2 field1 = %s\n",field1);
printf("c2z_print.c dec2 field2 = %s fd2_type = %d\n",field2,fd2_type);
printf("c2z_print.c dec2 field3 = %s fd3_type = %d\n",field3,fd3_type);
printf("c2z_print.c dec2 field6 = %s\n",field6);
*/

/*  find displacement in array  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #700");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #701");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #702");
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
        strcpy(trace_1, "c2z_print.c #703");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #704");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #705");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #706");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #707");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #708");
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
        strcpy(trace_1, "c2z_print.c #709");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #710");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #711");
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
      strcpy(trace_1, "c2z_print.c #712");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #713");
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
        strcpy(trace_1, "c2z_print.c #714");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #715");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #716");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #717");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #718");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #719");
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
        strcpy(trace_1, "c2z_print.c #720");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #721");
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
      strcpy(trace_1, "c2z_print.c #722");
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
      strcpy(trace_1, "c2z_print.c #723");
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
        strcpy(trace_1, "c2z_print.c #724");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #725");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #726");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #727");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #728");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #729");
        trace_rec_3();
      }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #730");
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
        strcpy(trace_1, "c2z_print.c #731");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #732");
        trace_rec_3();
      }
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
           x101 = gw_variable[I].gv_column;
           break;
         }
       }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string,wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #733");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #734");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #735");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #736");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #737");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #738");
      trace_rec_3();
    }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #739");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #740");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #741");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #742");
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
        strcpy(trace_1, "c2z_print.c #743");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #744");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #745");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #746");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #747");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #748");
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
        strcpy(trace_1, "c2z_print.c #749");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #750");
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
      strcpy(trace_1, "c2z_print.c #751");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #752");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #753");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #754");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #755");
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
      strcpy(trace_1, "c2z_print.c #756");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #757");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #758");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #759");
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
      strcpy(trace_1, "c2z_print.c #760");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #761");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #762");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #763");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #764");
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
    strcpy(trace_1, "c2z_print.c #765");
    trace_rec_3();
  }

  strcpy(a_string, "* found location in 2d array ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #766");
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
    strcpy(trace_1, "c2z_print.c #767");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #768");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #769");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #770");
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
      strcpy(trace_1, "c2z_print.c #771");
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
      strcpy(trace_1, "c2z_print.c #772");
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
    strcpy(trace_1, "c2z_print.c #773");
    trace_rec_3();
  }
  work_use_ct[10]++;

  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcpy(a_string, "         MVC   0(");
  strcat(a_string, wk_strg);
  strcat(a_string, ",R7),0(R6)");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #774");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #775");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #776");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #777");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #778");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #779");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #780");
    trace_rec_3();
  }

  
  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #781");
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
    strcpy(trace_1, "c2z_print.c #782");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #783");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #784");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #785");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #786");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #787");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #788");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #789");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #790");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #791");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #792");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #793");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #794");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "N");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #795");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #796");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #797");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #798");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "M");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #799");
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
    strcpy(trace_1, "c2z_print.c #800");
    trace_rec_3();
  }
 
  strcpy(a_string, "*  C370NWK3 contains # of characters to be printed");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #801");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,");
  strcat(a_string, field6);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #802");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #803");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVD   R5,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #804");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #805");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #806");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #807");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #808");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #809");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #810");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #811");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #812");
    trace_rec_3();
  }

  strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #813");
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
    strcpy(trace_1, "c2z_print.c #814");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #815");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #816");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #817");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #818");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #819");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #820");
    trace_rec_3();
  }
 
  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #821");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #822");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #823");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #824");
    trace_rec_3();
  }
  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #825");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #826");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #27");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #828");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #829");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #830");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #831");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #833");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #834");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "O");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #835");
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
    strcpy(trace_1, "c2z_print.c #836");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #837");
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
    strcpy(trace_1, "c2z_print.c #838");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #839");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #840");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #841");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #842");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #843");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field12);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #844");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #845");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #846");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #847");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #848");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #849");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #850");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #851");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #852");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #853");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #854");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #855");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #856");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #857");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #858");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #859");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #860");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #861");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #862");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #863");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #864");
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
    strcpy(trace_1, "c2z_print.c #865");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #866");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #867");
    trace_rec_3();
  }
   
  strcpy(a_string, "         LARL  R15,WTOIMVC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #868");
    trace_rec_3();
  }

  strcpy(a_string, "         BAKR  0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #869");
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
    strcpy(trace_1, "c2z_print.c #870");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #871");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #872");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #873");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R4,10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #874");
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
    strcpy(trace_1, "c2z_print.c #875");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #876");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #877");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #878");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #879");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #880");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #881");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #882");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #883");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #884");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #885");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #886");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #887");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #888");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #889");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #890");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #891");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #892");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #893");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #894");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #895");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "P");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #896");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #897");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #898");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #899");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #900");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "P");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #901");
    trace_rec_3();
  }


  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #902");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #903");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #904");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "J");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #905");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "K");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #906");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #907");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #908");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #909");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #910");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #911");
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
   int fd2_type;
   int fd3_type;
   int x2;
   int x3;
   int x4;
   int x5;
   int ret;
   int ret1;
   int x21;
   int x101;
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
  pi2 = 0;
  while(ch != '[')
  {
    if(ch != ',')
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
      printf("\nc2z_printf.c c2_printf_str4 E-604 field3 Not Found = %s\n",field3);
      printf("c2z_printf.c c2_printf_str4 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

/*
printf("\nc2z_print.c str4 rct = %d p_string = %s",rct,p_string);
printf("c2z_print.c str4 field1 = %s\n",field1);
*/

/*  find displacement in array  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1000");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1001");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1002");
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
        strcpy(trace_1, "c2z_print.c #1003");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1004");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1005");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1006");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1007");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1008");
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
        strcpy(trace_1, "c2z_print.c #1009");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1010");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1011");
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
      strcpy(trace_1, "c2z_print.c #1012");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1013");
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
        strcpy(trace_1, "c2z_print.c #1014");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1015");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1016");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1017");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1018");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1019");
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
        strcpy(trace_1, "c2z_print.c #1020");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1021");
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
      strcpy(trace_1, "c2z_print.c #1022");
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
      strcpy(trace_1, "c2z_print.c #1023");
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
        strcpy(trace_1, "c2z_print.c #1024");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1025");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1026");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1027");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1028");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1029");
        trace_rec_3();
      }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1030");
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
        strcpy(trace_1, "c2z_print.c #1031");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1032");
        trace_rec_3();
      }
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
           x101 = gw_variable[I].gv_column;
           break;
         }
       }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string,wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1033");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1034");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1035");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1036");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1037");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1038");
      trace_rec_3();
    }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1039");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1040");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1041");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1042");
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
        strcpy(trace_1, "c2z_print.c #1043");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1044");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1045");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1046");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1047");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #1048");
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
        strcpy(trace_1, "c2z_print.c #1049");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1050");
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
      strcpy(trace_1, "c2z_print.c #1051");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1052");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1053");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1054");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1055");
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
      strcpy(trace_1, "c2z_print.c #1056");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1057");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1058");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1059");
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
      strcpy(trace_1, "c2z_print.c #1060");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1061");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1062");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1063");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1064");
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
    strcpy(trace_1, "c2z_print.c #1065");
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
    strcpy(trace_1, "c2z_print.c #1066");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1067");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1068");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1069");
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
      strcpy(trace_1, "c2z_print.c #1070");
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
      strcpy(trace_1, "c2z_print.c #1071");
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
    strcpy(trace_1, "c2z_print.c #1072");
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
    strcpy(trace_1, "c2z_print.c #1073");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1074");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1075");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1076");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1077");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1078");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1079");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1080");
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
    strcpy(trace_1, "c2z_print.c #1081");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1082");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1083");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1084");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1085");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1086");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1087");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1088");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1089");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1090");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1091");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1092");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1093");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "N");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1094");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1095");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1096");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1097");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "M");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1098");
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
    strcpy(trace_1, "c2z_print.c #1099");
    trace_rec_3();
  }
 
  strcpy(a_string, "*  C370NWK3 contains # of characters to be printed");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1100");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,");
  strcat(a_string, field6);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1101");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1102");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVD   R5,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1103");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1104");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1105");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1106");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1107");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1108");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1109");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1110");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1111");
    trace_rec_3();
  }

  strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1112");
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
    strcpy(trace_1, "c2z_print.c #1113");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1114");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1115");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1116");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1117");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1118");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1119");
    trace_rec_3();
  }
 
  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1120");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1121");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1122");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1123");
    trace_rec_3();
  }
  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1124");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1125");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1126");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1127");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1128");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1129");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1130");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1131");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1132");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "O");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1133");
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
    strcpy(trace_1, "c2z_print.c #1134");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1135");
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
    strcpy(trace_1, "c2z_print.c #1136");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1137");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1138");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1139");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1140");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1141");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field12);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1142");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1143");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1144");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1145");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1146");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1147");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1148");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1149");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1150");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1151");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1152");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1153");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1154");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1155");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1156");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1157");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1158");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1159");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1160");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1161");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1162");
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
    strcpy(trace_1, "c2z_print.c #1163");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1164");
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
    strcpy(trace_1, "c2z_print.c #1165");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1166");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1167");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1168");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1169");
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
    strcpy(trace_1, "c2z_print.c #1170");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1171");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1172");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1173");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1174");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1175");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1176");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1177");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1178");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1179");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1180");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1181");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1182");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1183");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1184");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1185");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1186");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1187");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1188");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1189");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1190");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "K");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1191");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1192");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1193");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1194");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1195");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1196");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1197");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1198");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "J");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1199");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "K");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1200");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1201");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1202");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1203");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1204");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1205");
      trace_rec_3();
    }
  }
  convert = 1;
}


void c2_printf_dec5()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_printf_dec5 Structure");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield7a[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield12[VAR_LGTH];
  char tfield13[VAR_LGTH];
  char prt_lit[VAR_LGTH];

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int x80 = 0;
  int x87 = 0;
  int x103 = 0;
  int m5fd2_type = 0;
  int m5fd5_type = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int p102;
  int s;
  int v;


  p102 = 0;

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    if((p_string[I] == '\\') && (p_string[I+1] == 'n'))
    {
      p102++;
    }
  }

  strcpy(tfield10, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(tfield10, wk_strg);

  for (x3 = 0; x3 < v_const; x3++) 
  {
    ret = strcmp(tfield10, w_constant[x3].const_current);
    if (ret == 0) 
    {
      strcpy(prt_lit, w_constant[x3].const_use);

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
            }
          }
        }
      }
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
  while (ch != '[') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  m5fd2_type = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
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

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(tfield1, w_struc[I].st_name);
    ret1 = strcmp(tfield3,w_struc[I].st_field_name);
    if ((ret == 0) && (ret1 == 0))
    {
      x3 = 1;
      strcpy(tfield1a, w_struc[I].st_cname);
      strcpy(tfield6a, w_struc[I].st_field_cname);
      strcpy(tfield7a, w_struc[I].st_type);
      break;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_print.c c2z_printf_dec5 Structure math-029 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_print.c c2_printf_dec5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if(m5fd2_type == 2)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
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
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_print.c c2_print_dec5 math-030 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_printf.c c2_print_dec5 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
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
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_print.c c2z_print_dec5 Structure math-031 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_print.c c2z_print_dec5 Structure tfield3 Not Found = %s\n",tfield3);
    printf("c2z_print.c c2_print_dec5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if ((x87 == 0) && (m5fd5_type == 2))
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield5, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield5a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield5, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield5a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_print.c c2_print_dec5 math-032 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_print.c c2_print_dec5 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }
  
  if ((x87 == 0) && (m5fd5_type == 1))
  {
    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #50a");
      trace_rec_3();
    }
    work_use_ct[78]++;

   strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1300");
      trace_rec_3();
    }
    work_use_ct[32]++;

   strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1301");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield5);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1302");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1303");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1304");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1305");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1306");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1307");
      trace_rec_3();
    }
  }

  if(m5fd5_type == 2)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
         x3 = 1;
         strcpy(tfield2a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
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
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_dec5 math-033 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_math.c c2_math_dec5 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1308");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1309");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1310");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, tfield1a);
  strcat(a_string, "T");
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1311");
    trace_rec_3();
  }

  if(m5fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1312");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1313");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1314");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1315");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1316");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1317");
      trace_rec_3();
    }
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
    strcpy(trace_1, "c2z_math.c #1318");
    trace_rec_3();
  }


  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1319");
    trace_rec_3();
  }
  work_use_ct[49]++;

  if(m5fd2_type == 1)
  {
    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1320");
      trace_rec_3();
    }
    work_use_ct[50]++;
  }

  if(m5fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1321");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1322");
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
    strcpy(trace_1, "c2z_math.c #1323");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1324");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1325");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1326");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, tfield1a);
  strcat(a_string, "L");
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1327");
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
    strcpy(trace_1, "c2z_math.c #1328");
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
    strcpy(trace_1, "c2z_math.c #1329");
    trace_rec_3();
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
      x80 = w_struc[I].st_disp;
    }
  }

  if (x3 == 0) 
  {
    printf("/nc2z_math.c c2z_math_str5 math-034 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_math.c c2z_math_str5 tfield3 Not Found = %s\n",tfield3);
    printf("c2z_math.c c2_math_str5 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if(m5fd5_type == 1)
  {
    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1330");
      trace_rec_3();
    }
    work_use_ct[78]++;
  }

  if(m5fd5_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, "*/");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1331");
      trace_rec_3();
    }
  }


  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print_c #1332");
    trace_rec_3();
  }
  
  strcpy(a_string, "         ZAP   0(6,R9),");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
  strcat(a_string, wk_strg);
  strcat(a_string, "(6,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1333");
    trace_rec_3();
  }

  strcpy(a_string, "* found location in 2d array ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1334");
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
    strcpy(trace_1, "c2z_print.c #1335");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1336");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1337");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1338");
    trace_rec_3();
  }

  strcpy(tfield13, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(tfield13, wk_strg);

  for (x3 = 0; x3 < v_const; x3++) 
  {
    ret = strcmp(tfield13, w_constant[x3].const_current);
    if (ret == 0) 
    {
      strcpy(tfield12, w_constant[x3].const_use);
      x4 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield12, lw_variable[v].lv_name);
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
            ret = strcmp(tfield12, gw_variable[v].gv_name);
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
      strcpy(trace_1, "c2z_print.c #1339");
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
      strcpy(trace_1, "c2z_print.c #1340");
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
    strcpy(trace_1, "c2z_print.c #1341");
    trace_rec_3();
  }
  work_use_ct[10]++;

  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcpy(a_string, "         MVC   0(");
  strcat(a_string, wk_strg);
  strcat(a_string, ",R7),0(R6)");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1342");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1343");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1344");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1345");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1346");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1347");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1348");
    trace_rec_3();
  }

  
  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1349");
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
    strcpy(trace_1, "c2z_print.c #1350");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1351");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1352");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1353");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1354");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1355");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1356");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1357");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1358");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1359");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1360");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1361");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1362");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "N");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1363");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1364");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1365");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1366");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "M");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1367");
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
    strcpy(trace_1, "c2z_print.c #1368");
    trace_rec_3();
  }
 
  strcpy(a_string, "*  C370NWK3 contains # of characters to be printed");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1369");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,");
  strcat(a_string, tfield6);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1370");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1371");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVD   R5,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1372");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1373");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1374");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1375");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1376");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1377");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1378");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1379");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1380");
    trace_rec_3();
  }

  strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1381");
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
    strcpy(trace_1, "c2z_print.c #1382");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1383");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1384");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1385");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1386");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1387");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1388");
    trace_rec_3();
  }
 
  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1389");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1390");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1391");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1392");
    trace_rec_3();
  }
  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1393");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1394");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1395");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1396");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1397");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1398");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1399");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1400");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1401");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "O");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1402");
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
    strcpy(trace_1, "c2z_print.c #1403");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1404");
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
    strcpy(trace_1, "c2z_print.c #1405");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1406");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1407");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1408");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1409");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1410");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, tfield12);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1411");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1412");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1413");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1414");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1415");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1416");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1417");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1418");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1419");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1420");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1421");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1422");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1423");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1424");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1425");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1426");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1427");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1428");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1429");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1430");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1431");
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
    strcpy(trace_1, "c2z_print.c #1432");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R15,WTOIMVC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1433");
    trace_rec_3();
  }

  strcpy(a_string, "         BAKR  0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1434");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1435");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1436");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1437");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1438");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R4,10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1439");
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
    strcpy(trace_1, "c2z_print.c #1440");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1441");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1442");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1443");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1444");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1445");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1446");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1447");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1448");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1449");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1450");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1451");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1452");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1453");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1454");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1455");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1456");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1457");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1458");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1459");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1460");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "P");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1461");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1462");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1463");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1464");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1465");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "P");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1466");
    trace_rec_3();
  }


  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1467");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1468");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1469");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "J");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1470");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "K");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1471");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1472");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1473");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1474");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1475");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1476");
      trace_rec_3();
    }
  }
}



void c2_printf_dec6()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.printf.c c2_printf_dec6 START");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield8[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield11[VAR_LGTH];
  char tfield12[VAR_LGTH];
  char tfield13[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int x2 = 0;
  int x103 = 0;
  int fd2_type = 0;
  int ret = 0;
  int ret1 = 0;
  int x3;
  int x4;
  int x5;
  int v;

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
    if(ch != ' ')
    {
      tfield1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  x2 = 0;
  fd2_type = 0;
  pi++;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if (x2 == 0) 
    {
      if ((isdigit(ch)) && (x2 == 0)) 
      {
        fd2_type = 2;
        x2 = 1;
      }
      if ((isalpha(ch)) && (x2 == 0)) 
      {
        fd2_type = 1;
        x2 = 1;
      }
    }
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';
 
  if(fd2_type == 1)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
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
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_printf.c c2_printf_dec6 E-002 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_printf.c c2_printf_dec6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(tfield5, gw_variable[I].gv_dsect);
        strcpy(tfield6, gw_variable[I].gv_label);
        strcpy(tfield7, gw_variable[I].gv_table);
        strcpy(tfield8, gw_variable[I].gv_aname);
        strcpy(tfield9, gw_variable[I].gv_sv_reg);
        strcpy(tfield10, gw_variable[I].gv_wk_reg);
        strcpy(tfield11, gw_variable[I].gv_wk_strg);
      }
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print_c #1500");
    trace_rec_3();
  }
  work_use_ct[49]++;
  
  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1501");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1502");
    trace_rec_3();
  }

  if(fd2_type == 2)
  {
    for_loop_ct++;
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1503");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1504");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1505");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", for_loop_ct);
    strcpy(a_string, "         LARL  R9,C370R");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1506");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1507");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1508");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, tfield7);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1509");
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
    strcpy(trace_1, "c2z_print.c #1510");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print_c #1511");
    trace_rec_3();
  }
  work_use_ct[49]++;

  if(fd2_type == 2)
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", for_loop_ct);
    strcpy(a_string, "         LARL  R8,C370R");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1512");
      trace_rec_3();
    }
  }

  if (fd2_type == 1) 			/* variable */
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, "*/");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1513");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1514");
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
    strcpy(trace_1, "c2z_print.c #1515");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print_c #1516");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1517");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1518");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, tfield6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1519");
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
    strcpy(trace_1, "c2z_print.c #1520");
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
    strcpy(trace_1, "c2z_print.c #1521");
    trace_rec_3();
  }

  strcpy(a_string, "* found location in 2d array ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1522");
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
    strcpy(trace_1, "c2z_print.c #1523");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1524");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1525");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1526");
    trace_rec_3();
  }

  strcpy(tfield13, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(tfield13, wk_strg);

  for (x3 = 0; x3 < v_const; x3++) 
  {
    ret = strcmp(tfield13, w_constant[x3].const_current);
    if (ret == 0) 
    {
      strcpy(tfield12, w_constant[x3].const_use);
      x4 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield12, lw_variable[v].lv_name);
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
            ret = strcmp(tfield12, gw_variable[v].gv_name);
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
      strcpy(trace_1, "c2z_print.c #1527");
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
      strcpy(trace_1, "c2z_print.c #1528");
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
    strcpy(trace_1, "c2z_print.c #1529");
    trace_rec_3();
  }
  work_use_ct[10]++;

  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcpy(a_string, "         MVC   0(");
  strcat(a_string, wk_strg);
  strcat(a_string, ",R7),0(R6)");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1530");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1531");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1532");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1533");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1534");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1535");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1536");
    trace_rec_3();
  }

  
  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1537");
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
    strcpy(trace_1, "c2z_print.c #1538");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1539");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1540");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1541");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1542");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1543");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1544");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1545");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1546");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1547");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1548");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1549");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1550");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "N");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1551");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1552");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1553");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1554");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "M");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1555");
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
    strcpy(trace_1, "c2z_print.c #1556");
    trace_rec_3();
  }
 
  strcpy(a_string, "*  C370NWK3 contains # of characters to be printed");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1557");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,");
  strcat(a_string, tfield6);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1558");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1559");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVD   R5,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1560");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1561");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1562");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1563");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1564");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1565");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1566");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1567");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1568");
    trace_rec_3();
  }

  strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1569");
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
    strcpy(trace_1, "c2z_print.c #1570");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1571");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1572");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1573");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1574");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1575");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1576");
    trace_rec_3();
  }
 
  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1577");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1578");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1579");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1580");
    trace_rec_3();
  }
  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1581");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1582");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1583");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1584");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1585");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1586");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1587");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1588");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1589");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "O");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1590");
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
    strcpy(trace_1, "c2z_print.c #1591");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1592");
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
    strcpy(trace_1, "c2z_print.c #1593");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1594");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1595");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1596");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1597");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1598");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, tfield12);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1599");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1600");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1601");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1602");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1603");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1604");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1605");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1606");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1607");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1608");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1609");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1610");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1611");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1612");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1613");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1614");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1615");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1616");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1617");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1618");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1619");
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
    strcpy(trace_1, "c2z_print.c #1620");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1621");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1622");
    trace_rec_3();
  }
   
  strcpy(a_string, "         LARL  R15,WTOIMVC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1623");
    trace_rec_3();
  }

  strcpy(a_string, "         BAKR  0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1624");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1625");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1626");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1627");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1628");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R4,10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1629");
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
    strcpy(trace_1, "c2z_print.c #1630");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1631");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1632");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1633");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1634");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1635");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L10");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1636");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1637");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1638");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1639");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1640");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1641");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1642");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1643");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1644");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1645");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1646");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1647");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1648");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1649");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1650");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "P");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1651");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1652");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1653");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1654");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1655");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "P");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1656");
    trace_rec_3();
  }


  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1657");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1658");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1659");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "J");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1660");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "K");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1661");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1662");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1663");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1664");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1665");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1666");
      trace_rec_3();
    }
  }
}



void c2_printf_str5()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.printf.c c2_printf_str5 START");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield8[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield11[VAR_LGTH];
  char tfield12[VAR_LGTH];
  char tfield13[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int x2 = 0;
  int x103 = 0;
  int fd2_type = 0;
  int ret = 0;
  int ret1 = 0;
  int x3;
  int x4;
  int x5;
  int x80;
  int x81;
  int v;
  int s;

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    if((p_string[I] == '\\') && (p_string[I + 1] == 'n'))
    {
      p102 = 1;
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
  while (ch != '[') 
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

  x2 = 0;
  fd2_type = 0;
  pi++;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if (x2 == 0) 
    {
      if ((isdigit(ch)) && (x2 == 0)) 
      {
        fd2_type = 2;
        x2 = 1;
      }
      if ((isalpha(ch)) && (x2 == 0)) 
      {
        fd2_type = 1;
        x2 = 1;
      }
    }
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  pi2 = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if(ch != ' ')
    {
      tfield3[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  if(fd2_type == 1)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
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
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_printf.c c2_printf_dec6 E-002 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_printf.c c2_printf_dec6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(tfield1a, gw_variable[I].gv_cname);
        strcpy(tfield5, gw_variable[I].gv_dsect);
        strcpy(tfield6, gw_variable[I].gv_label);
        strcpy(tfield7, gw_variable[I].gv_table);
        strcpy(tfield8, gw_variable[I].gv_aname);
        strcpy(tfield9, gw_variable[I].gv_sv_reg);
        strcpy(tfield10, gw_variable[I].gv_wk_reg);
        strcpy(tfield11, gw_variable[I].gv_wk_strg);
        break;
      }
    }
  }

/*
printf("\nc2z_print.c c2_math_str5 rct = %d p_string = %s",rct,p_string);
printf("c2z_print.c c2_math_str5 gv_type = %s\n",gw_variable[I].gv_type);
printf("c2z_print.c c2_math_str5 tfield1 = %s\n",tfield1);
printf("c2z_print.c c2_math_str5 tfield1a = %s\n",tfield1a);
printf("c2z_print.c c2_math_str5 tfield5 = %s\n",tfield5);
printf("c2z_print.c c2_math_str5 tfield6 = %s\n",tfield6);
printf("c2z_print.c c2_math_str5 tfield7 = %s\n",tfield7);
printf("c2z_print.c c2_math_str5 tfield8 = %s\n",tfield8);
printf("c2z_print.c c2_math_str5 tfield9 = %s\n",tfield9);
printf("c2z_print.c c2_math_str5 tfield10 = %s\n",tfield10);
printf("c2z_print.c c2_math_str5 tfield11 = %s\n",tfield11);
*/

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(tfield1, w_struc[I].st_wname);
    ret1 = strcmp(tfield3, w_struc[I].st_field_name);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(tfield3a, w_struc[I].st_field_cname);
      x80 = w_struc[I].st_disp; 
      x81 = w_struc[I].st_field_lgth;
      break;
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_printf_c #1700");
    trace_rec_3();
  }
  work_use_ct[49]++;
  
  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1701");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1702");
    trace_rec_3();
  }

  if(fd2_type == 2)
  {
    for_loop_ct++;
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1703");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1704");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1705");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", for_loop_ct);
    strcpy(a_string, "         LARL  R9,C370R");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1706");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1707");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1708");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, tfield1a);
  strcat(a_string, "T");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1709");
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
    strcpy(trace_1, "c2z_print.c #1710");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print_c #1711");
    trace_rec_3();
  }
  work_use_ct[49]++;

  if(fd2_type == 2)
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", for_loop_ct);
    strcpy(a_string, "         LARL  R8,C370R");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1712");
      trace_rec_3();
    }
  }

  if (fd2_type == 1) 			/* variable */
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, "*/");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1713");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1714");
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
    strcpy(trace_1, "c2z_print.c #1715");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print_c #1716");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1717");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1718");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, tfield1a);
  strcat(a_string, "L");
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1719");
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
    strcpy(trace_1, "c2z_print.c #1720");
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
    strcpy(trace_1, "c2z_print.c #1721");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print_c #1722");
    trace_rec_3();
  }
  
/*  snprintf(wk_strg, sizeof(wk_strg), "%d", x80); */
  strcpy(a_string, "         MVC   0");
 /* strcat(a_string, wk_strg); */
  snprintf(wk_strg, sizeof(wk_strg), "%d", x81);
  strcat(a_string, "(");
  strcat(a_string, wk_strg);
  strcat(a_string, ",R9),0(R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print_c #1723");
    trace_rec_3();
  }

  strcpy(a_string, "* found location in 2d array ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1724");
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
    strcpy(trace_1, "c2z_print.c #1725");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1726");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1727");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1728");
    trace_rec_3();
  }

  strcpy(tfield13, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(tfield13, wk_strg);

  for (x3 = 0; x3 < v_const; x3++) 
  {
    ret = strcmp(tfield13, w_constant[x3].const_current);
    if (ret == 0) 
    {
      strcpy(tfield12, w_constant[x3].const_use);
      x4 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield12, lw_variable[v].lv_name);
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
            ret = strcmp(tfield12, gw_variable[v].gv_name);
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
      strcpy(trace_1, "c2z_print.c #1729");
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
      strcpy(trace_1, "c2z_print.c #1730");
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
    strcpy(trace_1, "c2z_print.c #1731");
    trace_rec_3();
  }
  work_use_ct[10]++;

  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcpy(a_string, "         MVC   0(");
  strcat(a_string, wk_strg);
  strcat(a_string, ",R7),0(R6)");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1732");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1733");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1734");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1735");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1736");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1737");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1738");
    trace_rec_3();
  }
  
  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1739");
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
    strcpy(trace_1, "c2z_print.c #1740");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1741");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1742");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1743");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1744");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1745");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1746");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1747");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1748");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1749");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1750");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1751");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1752");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "N");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1753");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1754");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1755");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1756");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "M");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1757");
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
    strcpy(trace_1, "c2z_print.c #1758");
    trace_rec_3();
  }
 
  strcpy(a_string, "*  C370NWK3 contains # of characters to be printed");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1759");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,");
  strcat(a_string, tfield6);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1760");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1761");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVD   R5,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1762");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1763");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1764");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1765");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1766");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1767");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1768");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1769");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1770");
    trace_rec_3();
  }

  strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1771");
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
    strcpy(trace_1, "c2z_print.c #1772");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1773");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1774");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1775");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1776");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1777");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1778");
    trace_rec_3();
  }
 
  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1779");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1780");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1781");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1782");
    trace_rec_3();
  }
  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1783");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1784");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1785");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1786");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1787");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1788");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1789");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1790");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1791");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "O");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1792");
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
    strcpy(trace_1, "c2z_print.c #1793");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1794");
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
    strcpy(trace_1, "c2z_print.c #1795");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1796");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1797");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1798");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1799");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1800");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, tfield12);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1801");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1802");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1803");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1804");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1805");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1806");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1807");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1808");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1809");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1810");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1811");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1812");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1813");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1814");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1815");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1816");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1817");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1818");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1819");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1820");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1821");
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
    strcpy(trace_1, "c2z_print.c #1822");
    trace_rec_3();
  }

  strcpy(a_string, "*         LARL  R9,C370EDN");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1823");
    trace_rec_3();
  }

  strcpy(a_string, "*         ZAP   0(6,R9),0(6,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1824");
    trace_rec_3();
  }
   
  strcpy(a_string, "*         LARL  R15,WTOIMVC");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1825");
    trace_rec_3();
  }

  strcpy(a_string, "*         BAKR  0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1826");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1827");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1828");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1829");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1830");
    trace_rec_3();
  }

  strcpy(a_string, "*         LARL  R9,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1831");
    trace_rec_3();
  }
  work_use_ct[10]++;

  strcpy(a_string, "*         LARL  R8,");
  strcat(a_string, tfield3a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1832");
    trace_rec_3();
  }

  strcpy(a_string, "*         MVC  0(16,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1833");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", x81);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string,wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1834");
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
    strcpy(trace_1, "c2z_print.c #1835");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1836");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1837");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1838");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1839");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1840");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1841");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1842");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1843");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1844");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1845");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1846");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1847");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1848");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1849");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1850");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1851");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1852");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1853");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1854");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1855");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "P");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1856");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1857");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1858");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1859");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1860");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "P");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1861");
    trace_rec_3();
  }


  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1862");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1863");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1864");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "J");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1865");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "K");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1866");
    trace_rec_3();
  }

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1867");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1868");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1869");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1870");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1871");
      trace_rec_3();
    }
  }
}


void c2_printf_str6()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.printf.c c2_printf_str6 START");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield8[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield11[VAR_LGTH];
  char tfield12[VAR_LGTH];
  char tfield13[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int x2 = 0;
  int x103 = 0;
  int fd2_type = 0;
  int ret = 0;
  int ret1 = 0;
  int x3;
  int x4;
  int x5;
  int s;
  int v;

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    if((p_string[I] == '\\') && (p_string[I + 1] == 'n'))
    {
      p102 = 1;
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
  while (ch != '[') 
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

  x2 = 0;
  fd2_type = 0;
  pi++;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if (x2 == 0) 
    {
      if ((isdigit(ch)) && (x2 == 0)) 
      {
        fd2_type = 2;
        x2 = 1;
      }
      if ((isalpha(ch)) && (x2 == 0)) 
      {
        fd2_type = 1;
        x2 = 1;
      }
    }
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';
 
  if(fd2_type == 1)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
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
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_printf.c c2_printf_str6 E-002 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_printf.c c2_printf_str6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(tfield5, gw_variable[I].gv_dsect);
        strcpy(tfield6, gw_variable[I].gv_label);
        strcpy(tfield7, gw_variable[I].gv_table);
        strcpy(tfield8, gw_variable[I].gv_aname);
        strcpy(tfield9, gw_variable[I].gv_sv_reg);
        strcpy(tfield10, gw_variable[I].gv_wk_reg);
        strcpy(tfield11, gw_variable[I].gv_wk_strg);
      }
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print_c #1900");
    trace_rec_3();
  }
  work_use_ct[49]++;
  
  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1901");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1902");
    trace_rec_3();
  }

  if(fd2_type == 2)
  {
    for_loop_ct++;
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1903");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1904");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1905");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", for_loop_ct);
    strcpy(a_string, "         LARL  R9,C370R");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1906");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1907");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1908");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, tfield7);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1909");
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
    strcpy(trace_1, "c2z_print.c #1910");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print_c #1911");
    trace_rec_3();
  }
  work_use_ct[49]++;

  if(fd2_type == 2)
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", for_loop_ct);
    strcpy(a_string, "         LARL  R8,C370R");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1912");
      trace_rec_3();
    }
  }

  if (fd2_type == 1) 			/* variable */
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, "*/");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #1913");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1914");
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
    strcpy(trace_1, "c2z_print.c #1915");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print_c #1916");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1917");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1918");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, tfield6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1919");
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
    strcpy(trace_1, "c2z_print.c #1920");
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
    strcpy(trace_1, "c2z_print.c #1921");
    trace_rec_3();
  }

  strcpy(a_string, "* found location in 2d array ");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1922");
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
    strcpy(trace_1, "c2z_print.c #1923");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1924");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1925");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1926");
    trace_rec_3();
  }

  strcpy(tfield13, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(tfield13, wk_strg);

  for (x3 = 0; x3 < v_const; x3++) 
  {
    ret = strcmp(tfield13, w_constant[x3].const_current);
    if (ret == 0) 
    {
      strcpy(tfield12, w_constant[x3].const_use);
      x4 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield12, lw_variable[v].lv_name);
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
            ret = strcmp(tfield12, gw_variable[v].gv_name);
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
      strcpy(trace_1, "c2z_print.c #1927");
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
      strcpy(trace_1, "c2z_print.c #1928");
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
    strcpy(trace_1, "c2z_print.c #1929");
    trace_rec_3();
  }
  work_use_ct[10]++;

  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcpy(a_string, "         MVC   0(");
  strcat(a_string, wk_strg);
  strcat(a_string, ",R7),0(R6)");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1930");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1931");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1932");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1933");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1934");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1935");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1936");
    trace_rec_3();
  }
  
  snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1937");
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
    strcpy(trace_1, "c2z_print.c #1938");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1939");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1940");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1941");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1942");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1943");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1944");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1945");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1946");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1947");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1948");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370EOF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1949");
    trace_rec_3();
  }

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1950");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "N");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1951");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1952");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1953");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1954");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "M");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1955");
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
    strcpy(trace_1, "c2z_print.c #1956");
    trace_rec_3();
  }
 
  strcpy(a_string, "*  C370NWK3 contains # of characters to be printed");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1957");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,");
  strcat(a_string, tfield6);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1958");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1959");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVD   R5,0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1960");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1961");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1962");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1963");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1964");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1965");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1966");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1967");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1968");
    trace_rec_3();
  }

  strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1969");
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
    strcpy(trace_1, "c2z_print.c #1970");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1971");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1972");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1973");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1974");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1975");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1976");
    trace_rec_3();
  }
 
  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1977");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1978");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1979");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1980");
    trace_rec_3();
  }
  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1981");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1982");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1983");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1984");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1985");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1986");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1987");
    trace_rec_3();
  }
  work_use_ct[95]++;

  strcpy(a_string, "         LARL  R8,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1988");
    trace_rec_3();
  }
  work_use_ct[94]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1989");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "O");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1990");
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
    strcpy(trace_1, "c2z_print.c #1991");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(ptr_lgth), "%d", x5);
  strcpy(a_string, "         LAEY  R4,");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1992");
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
    strcpy(trace_1, "c2z_print.c #1993");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1994");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1995");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1996");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1997");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1998");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, tfield12);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #1999");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2000");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2001");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2002");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2003");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2004");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2005");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2006");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2007");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2008");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2009");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2010");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2011");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2012");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2013");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2014");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2015");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2016");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2017");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2018");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2019");
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
    strcpy(trace_1, "c2z_print.c #2020");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2021");
    trace_rec_3();
  }
  work_use_ct[10]++;

  strcpy(a_string, "         MVC   0(32,R9),0(R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2022");
    trace_rec_3();
  }
   
  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2023");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2024");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2025");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2026");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R4,80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2027");
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
    strcpy(trace_1, "c2z_print.c #2028");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2029");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2030");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2031");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2032");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2033");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L80");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2034");
    trace_rec_3();
  }
  work_use_ct[10]++;

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2035");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2036");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2037");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2038");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2039");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2040");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2041");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2042");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370WTOB");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2043");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2044");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2045");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2046");
    trace_rec_3();
  }
  work_use_ct[2]++;

  strcpy(a_string, "         LARL  R7,C370B1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2047");
    trace_rec_3();
  }
  work_use_ct[52]++;

  strcpy(a_string, "         CLC   0(1,R8),0(R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2048");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "P");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2049");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2050");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370PBUF");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2051");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2052");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2053");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "P");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2054");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2055");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2056");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2057");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R4,L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "J");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2058");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "K");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if(puncde == 1) 
  {
    strcpy(trace_1, "c2z_print.c #2059");
    trace_rec_3();
  }

printf("c2z_print.c #2059 rct = %d p102 = %d\n",rct,p102);

  if(p102 == 1)
  {
    strcpy(a_string, "         LARL  R15,WTOALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2060");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2061");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370PBUF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2062");
      trace_rec_3();
    }
 
    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2063");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_print.c #2064");
      trace_rec_3();
    }
  }
}


/*  place holders */

void c2_printf_numeric() 
{

}


void c2_printf_string() 
{

}



void c2_fprintf()
{
}


void c2_snprintf()
{
   printf("c2z_print.c c2_snprintf NEEDS to be CONVERTED\n");
}











