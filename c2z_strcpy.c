/* ***************************************************
*  c2z : c2z_strcpy.c :                              *
*                                                    *
*  next error - strcpy-062                           *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out STRCPY                                  *
* ************************************************** */
void c2_strcpy(void) 
{

  char ch;

  int str1 = 0;
  int str2 = 0;
  int I = 0;
  int s = 0;
  int x90 = 0;
  int x91 = 0;
  int x92 = 0;
  int x93 = 0;
  int x93a = 0;
  int x94 = 0;
  int x94a = 0;
  int x95 = 0;
  int x96 = 0;
  int x97 = 0;
  int bkl = 0;
  int bkr = 0;

  str1 = 0;
  str2 = 0;

  s = strlen(p_string);
  for (I = 0; I <= s; I++) 
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
      if(str1 == 0)
      {
        bkl++;
      }
      else
      {
        bkr++;
      }
    }
    if(ch == ']')
    {
      if(str1 == 0)
      {
        bkl++;
      }
      else
      {
        bkr++;
      }
    }
    if(ch == '(')
    {
     
        x95++;
      
    }
    if(ch == ')')
    {
      
        x95 ++;
     
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

/* ************************************************************ */ 
/*  stcopy profile	                                           */
/*       bkl          bkr   x93  x95  x90                       */
/*       []    ,      []     .                                  */
/*       0     ,      0      0     2    2   c2_str_4            */
/*       0     ,      0      0     4    0   c2_str_6            */
/*       0     ,      4                                         */
/*       2     ,      0      0     2    0   c2_str_14           */
/*       2     ,      2                     c2_str_2            */
/*       2     ,      4                                         */
/*       4     ,      0      0     2    0   c2_str_12           */
/*       4     ,      2                                         */
/*       4     ,      4                                         */
/* ************************************************************ */

  /*  c2_str_1		NOT USED		strcpy(cvalue, "123456");  				*/
  /*  c2_str_2 		 		strcpy(p_string, arrary1[line_ndx])		*/
  /*  c2_str_4                            strcpy(a, cvalue);					*/
  /*                                      strcpy(a, "133");                                */
  /*  c2_str_5                            strcpy(in_stack[t], in_stack[1]);			*/
  /*  c2_str_6				strcpy(varname, get_varname());			*/
  /*  c2_str_7				strcpy(gw_variable[gv_ct].gv_name, varname);	*/
  /*  c2_str_8				strcpy(gw_variable[gv_ct].gv_name, "123456");	*/
  /*  c2_str_9                            strcpy(in_stack[x], gw_variable[gv_ct].gv_name);	*/
  /*  c2_str_10				strcpy(gw_variable[gv_ct].gv_name, in_stack[x]); */
  /*  c2_str_11				strcpy(gw_variable[gv_ct].gv_name, gw_variable[I].gv_name */
  /*  c2_str_12                           strcpy(row[x][y], input);                        */
  /*  c2_str_14                           strcpy(in_stack[t], varname);			*/

/*
if(rct == 955)
{
printf("\nc2z_strcpy.c str\n");
printf("c2z_strcpy.c rct = %d p_string = %s",rct,p_string);
printf("c2z_strcpy.c bkl [] = %d\n",bkl);
printf("c2z_strcpy.c bkr [] = %d\n",bkr);
printf("c2z_strcpy.c x95 () = %d\n",x95);
printf("c2z_strcpy.c x90 qu = %d\n",x90);
printf("c2z_strcpy.c x93 .  = %d\n",x93);
}
*/

/*  
  if((bkl == 2) && (bkr == 0) && (x90 == 2) && (x95 == 2) && (x93 == 0))
  {
    c2_str_1(str1, str14);
    convert = 1;
    return;
  }
*/

/*
  if((x90 == 2) && (bkl == 0) && (bkr == 0) && (convert == 0))
  {
    c2_str_1(str1,str14);
    convert = 1;
    return;
  }
*/

  if ((bkl == 0) && (bkr == 2) && (convert == 0)) 
  {
    c2_str_2(str1, str2);
    convert = 1;
    return;
  }


  if ((bkl == 2) && (bkr == 0) && (x95 == 2)  && (x93 == 0)) 
  {
    c2_str_3(str1, str2);
    convert = 1;
    return;
  }


  if ((bkl == 0) && (bkr == 0) && (x95 == 2)) 
  {
    c2_str_4();
    convert = 1;
    return;
  }


  if ((x95 == 2) && (bkl == 2) && (bkr == 2) && (x90 == 0) && (convert == 0)) 
  {
    c2_str_5();
    convert = 1;
    return;
  }

  if ((bkl == 0) && (bkr == 0) && (x95 == 4) && (convert == 0)) 
  {
    c2_str_6();
    convert = 1;
    return;
  }

		/* strcpy(gw_variable[gv_ct].gv_name, varname);	*/
  if ((x90 == 0) && (bkl == 2) && (bkr == 0) && (x93 == 1) && (convert == 0)) 
  {
    c2_str_7();
    convert = 1;
    return;
  }

			/* strcpy(gw_variable[gv_ct].gv_name, "123456");	*/
  if((bkl == 2) && (bkr == 0) && (x90 == 2) && (x95 == 2) && (x93 == 1))
  {
    c2_str_8();
    convert = 1;
    return;
  }


  if((bkl == 4) && (bkr == 0) && (x95 == 2) && (convert == 0))
  {
    c2_str_12();
    convert = 1;
    return;
  }


  if((bkl == 0) && (bkr == 4) && (x95 == 2) && (convert == 0))
  {
    c2_str_13();
    convert = 1;
    return;
  }


  if((bkl == 2) && (bkr == 0) && (x95 == 2) && (x93 == 0))
  {
    c2_str_14(); 
    convert = 1;
    return;
  }



printf("\nc2z_strcpy.c NOT MATCH FOUND\n");
printf("c2z_strcpy.c rct = %d p_string = %s",rct,p_string);
printf("c2z_strcpy.c bkl [] = %d\n",bkl);
printf("c2z_strcpy.c bkr [] = %d\n",bkr);
printf("c2z_strcpy.c x95 () = %d\n",x95);
printf("c2z_strcpy.c x90 qu = %d\n",x90);
printf("c2z_strcpy.c x93 .  = %d\n",x93);


/* **************** */


  if ((x90 == 0) && (x91 == 0) && (x92 == 0) && (x93 == 0) && (x94 == 1) && (x95 == 2) && (x96 == 2) && (convert == 0)) 
  {
printf("\nc2z_strcpy.c HERE #1 rct = %d p_string = %s\n",rct,p_string);
    c2_str_6();
    convert = 1;
    return;
  }


  if ((x90 == 0) && (x91 == 2) && (x92 == 2) && (x93 == 1) && (x94 == 1) && (x95 == 1) && (x96 == 1) && (x94a < x93a) && (convert == 0)) 
  {
printf("\nc2z_strcpy.c HERE #3 rct = %d p_string = %s\n",rct,p_string);

    c2_str_9();
    convert = 1;
    return;
  }

  if ((x90 == 0) && (x91 == 2) && (x92 == 2) && (x93 == 1) && (x94 == 1) && (x95 == 1) && (x96 == 1) && (x94a > x93a) && (convert == 0)) 
  {
printf("\nc2z_strcpy.c HERE #4 rct = %d p_string = %s\n",rct,p_string);

    c2_str_10();
    convert = 1;
    return;
  }

  if((x90 == 0) && (x91 == 2) && (x92 == 2) && (x93 == 2) && (x94 == 1) && (x95 == 1) && (x96 == 1) && (x97 == 0) && (convert == 0))
  {
printf("\nc2z_strcpy.c HERE #5 rct = %d p_string = %s\n",rct,p_string);

    c2_str_11();
    convert = 1;
    return;
  }

  if((x97 == 2) && (x91 == 0) && (convert == 0))		/*  strcpy(xstring, "This is a test\n");  */
  {
printf("\nc2z_strcpy.c HERE #6 rct = %d p_string = %s\n",rct,p_string);

    char field2[VAR_LGTH];
    char field2a[VAR_LGTH];
    char field3[VAR_LGTH];
    char p_strg[3];

    int pi;
    int pi2;
    int x3;
    int x4;
    int I;
    int v;
    int ret;
    int ret1;

    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t'))
    {
      pi++;
      ch = p_string[pi];
    }

    while(ch != '(')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != ',')
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    x4 = 0;
    for (I = 0; I < char_ct; I++) 
    {
      if(rct == w_charlit[I].clit_rct)
      {
        strcpy(field3, w_charlit[I].clit_cname);
        snprintf(p_strg, sizeof(p_strg), "%d", w_charlit[I].clit_lgth);
        x4 = 1;
        break;
      }
    }

    if (x4 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_1 strcpy-056 Literal NOT Found \n");
      printf("c2z_strcpy.c c2_str_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field2, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strcpy(field2a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field2, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            strcpy(field2a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            x3 = 1;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_1 strcpy-057 field2 Not Found = %s\n", field2);
      printf("c2z_strcpy.c c2_str_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field3);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #2");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(");
    strcat(a_string, p_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #3");
      trace_rec_3();
    }
  }

  convert = 1;
  return;
}


void c2_str_1(int str1, int str4) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c str_1 START xxxxx");
    trace_rec_1();
  }

  char ch;
  char *p1;
  char *p2;
  char *p3;
  char *p4;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field1b[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field6a[VAR_LGTH];
  char field7a[VAR_LGTH];
  
   int pi;
   int pi2;
   int ret;
   int ret1;
   int x2;
   int x3;
   int x6;
   int x90;
   int x91;
   int s;
   int I;
   int v;
   int str5;
   int TL;
   int L1;
   int R1;
   int C1;
   int PD;
   int PD1;
   int fd2_type = 0;

  s = strlen(p_string);
  for(I=0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '[')
    {
      TL++;
      L1++;
    }
    if(ch == ']')
    {
      TL++;
      R1++;
    }
    if(ch == ',')
    {
      C1 = I;
    }
    if(ch == '.')
    {
      if(PD == 0)
      {
        PD1 = I;
      }
      PD++;
    }
  } 

  p1 = strstr(p_string, "[");
  p2 = strstr(p_string, "]");
  p3 = strstr(p_string, ".");
  p4 = strstr(p_string, "\"");

  if((p4) && (TL == 2) && (PD1 < C1) && (PD != 0))			/*  strcpy(gw_variable[gv_ct].name, "12345")    */
  {

printf("c2z_strcpy.c HERE #1 rct = %d p_string = %s\n",rct,p_string);
    pi = 0;
    ch = p_string[pi];
    while(ch != '(')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != '[')
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
    while(ch != ']')
    {
      if (x2 == 0) 
      {
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
    pi++;
    pi++;
    ch = p_string[pi];
    while(ch != ',')
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    x91 = 0;
    x3 = 0;
    for (I = 0; I < m_struc_ct; I++) 
    {
      ret = strcmp(field1, w_struc[I].st_wname);
      ret1 = strcmp(field3,w_struc[I].st_field_name);
      if ((ret == 0) && (ret1 == 0))
      {
        x3 = 1;
        strcpy(field1a, w_struc[I].st_cwname);
        strcpy(field6a, w_struc[I].st_field_cname);
        strcpy(field7a, w_struc[I].st_type);
        x91 = w_struc[I].st_disp;
        break;
      }
    }

    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(field4a, w_charlit[I].clit_cname);
        x90 = w_charlit[I].clit_lgth;
        break;
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #10");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #11");
      trace_rec_3();
    }
   
    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #12");
      trace_rec_3();
    }

    str5 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strcpy(field1a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          str5 = 1;
        }
      }
    }

    if (str5 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            strcpy(field1a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            str5 = 1;
          }
        }
      }
    }

    if (str5 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_1 strcpy-002 field1 Not Found = %s\n", field1);
      printf("c2z_strcpy.c c2_str_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R6,");
    strcpy(field1b,field1a);
    strcat(field1b,"T");
    strcat(a_string, field1b);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #13");
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
      strcpy(trace_1, "c2z_strcpy.c #14");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #15");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd2_type == 2)
    {
      str5 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field2, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            strcpy(field2a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            str5 = 1;
          }
        }
      }

      if (str5 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(field2, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              strcpy(field2a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
              str5 = 1;
            }
          }
        }
      }

      if (str5 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_1 strcpy-003 field2 Not Found = %s\n", field2);
        printf("c2z_strcpy.c c2_str_1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LAEY  R8,");
      strcat(a_string, field2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #16");
        trace_rec_3();
      }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #16a");
        trace_rec_3();
      }
    }
   
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #17");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #18");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");  
    strcpy(field1b,field1a);
    strcat(field1b,"L");
    strcat(a_string, field1b);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #19");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #20");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R9,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #21");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #22");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #23");
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
      strcpy(trace_1, "c2z_strcpy.c #24");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field4a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #25");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x91);
    strcat(a_string, wk_strg);
    strcat(a_string,"(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x90);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #26");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  if ((p4) && (!p1) && (!p2)) 
  {
printf("c2z_strcpy.c HERE #2 rct = %d p_string = %s\n",rct,p_string);

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
    while (ch != ',') 
    {
      if (ch != ' ') 
      {
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(field2a, w_charlit[I].clit_cname);
        x3 = w_charlit[I].clit_lgth;
      }
    }

    str5 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strcpy(field1a, lw_variable[v].lv_cname);
          lw_variable[v].lv_current_lgth = x3;
          lw_variable[v].lv_use_ct++;
          str5 = 1;
          break;
        }
      }
    }

    if (str5 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            strcpy(field1a, gw_variable[v].gv_cname);
            gw_variable[v].gv_current_lgth = x3;
            gw_variable[v].gv_use_ct++;
            str5 = 1;
            break;
          }
        }
      }
    }

    if (str5 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_1 strcpy-004 field1 Not Found = %s\n", field1);
      printf("c2z_strcpy.c c2_str_1 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_strcpy.c #27");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #28");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #29");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  if ((!p1) && (!p2) && (!p3) && (!p4)) 
  {
printf("c2z_strcpy.c HERE #3 rct = %d p_string = %s\n",rct,p_string);

    if (str1 < str4) 
    {
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
      while (ch != ',') 
      {
        if (ch != ' ') 
        {
          field1[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';

      str5 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field1, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            strcpy(field1a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            str5 = 1;
          }
        }
      }

      if (str5 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(field1, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              strcpy(field1a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
              str5 = 1;
            }
          }
        }
      }

      if (str5 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_1 strcpy-005 field1 Not Found = %s\n", field1);
        printf("c2z_strcpy.c c2_str_1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      if (ch == '"') 
      {
        pi2 = 0;
        pi++;
        ch = p_string[pi];

        while (ch != '"') 
        {
          field2[pi2] = ch;
          pi2++;
          pi++;
          x6++;
          ch = p_string[pi];
          if (ch == '\n')
          {
            break;
          }
          if (ch == '\t')
          {
            break;
          }
        }
      }
      field2[pi2] = '\0';

      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x6 = gw_variable[I].gv_current_lgth;
        }
      }

      for (I = 0; I < char_ct; I++) 
      {
        if (w_charlit[I].clit_rct == rct) 
        {
          strcpy(field2a, w_charlit[I].clit_cname);
          x3 = w_charlit[I].clit_lgth;
        }
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #30");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370B1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #31");
        trace_rec_3();
      }
      work_use_ct[52]++;

      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #32");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #33");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #34");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   ");
      strcat(a_string, "0(");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
      strcat(a_string, wk_strg);
      strcat(a_string, ",R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #35");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #36");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #37");
        trace_rec_3();
      }
      work_use_ct[74]++;

      strcpy(a_string, "         MVC   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
      strcat(a_string, wk_strg);
      strcat(a_string, "(1");
      strcat(a_string, ",R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #38");
        trace_rec_3();
      }

      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          gw_variable[I].gv_current_lgth = x3;
        }
      }

      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(gw_variable[I].gv_name, field2);
        if (ret == 0) 
        {
          printf("\nc2z_strcpy.c strcpy-006 c2_str_1 Undetermine \n");
          printf("c2z_strcpy.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
      }
    }
  }

  if ((p1) && (p2) && (p3)) 
  {
printf("c2z_strcpy.c HERE #4 rct = %d p_string = %s\n",rct,p_string);

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
    while (ch != ',') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(field2a, w_charlit[I].clit_cname);
        x3 = w_charlit[I].clit_lgth;
      }
    }

    x2 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      x2 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x2 == 0)) 
      {
        x3 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        break;
      }
    }

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
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_1 strcpy-007 field1a Not Found %s\n", field1);
      printf("c2z_strcpy.c c2_str_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #39");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #40");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #41");
      trace_rec_3();
    }

    convert = 1;
  }


  convert = 1;
  return;
}


void c2_str_2(int str1,int str2) 		/* strcpy(p_string, arrary1{line_ndx]")	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c str_2 START");
    trace_rec_1();
  }

  char ch;
  char *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
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

  int str3 = 0;
  int str5 = 0;
  int str6 = 0;
  int str8 = 0;
  int str9 = 0;
  int I = 0;
  int x2 = 0;
  int fd3_type = 0;
  int ret = 0;
  int ret1 = 0;
  int pi;
  int pi2;
  int v = 0;
  int x500 = 0;
  int x501 = 0;
  int x502 = 0;

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
  while (ch != ',') 
  {
    if (ch != ' ') 
    {
      field1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  str5 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        strcpy(field1a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        str5 = 1;
      }
    }
  }

  if (str5 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        str6 = strcmp(field1, gw_variable[v].gv_name);
        if (str6 == 0) 
        {
          strcpy(field1a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
          str5 = 1;
        }
      }
    }
  }


  if (str5 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_2 strcpy-010 field1 Not Found %s\n", field1);
    printf("c2z_strcpy.c c2_str_2 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
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

  str5 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field2, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        strcpy(field2a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        str5 = 1;
      }
    }
  }

  if (str5 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        str6 = strcmp(field2, gw_variable[v].gv_name);
        if (str6 == 0) 
        {
          strcpy(field2a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
          str5 = 1;
        }
      }
    }
  }

  if (str5 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_2 strcpy-011 field2 Not Found %s\n", field2);
    printf("c2z_strcpy.c c2_str_2 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x2 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if (x2 == 0) 
    {
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

    if (ch != ' ') 
    {
      field3[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  p = strstr(field3, "tday");

  if(!p)
  {
     p = strstr(field3, "tmth");
  }

  if(!p)
  {
     p = strstr(field3, "tyear");
  }

  if(p)
  {
    strcpy(field3a, field3);
    strcpy(field3, "C370DATE");
  }

  if(!p)
  {
    if (fd3_type == 2) 
    {
      str5 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field3, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            strcpy(field3a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            str5 = 1;
          }
        }
      }

      if (str5 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            str6 = strcmp(field3, gw_variable[v].gv_name);
            if (str6 == 0) 
            {
              strcpy(field3a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
              str5 = 1;
            }
          }
        }
      }

      if (str5 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_2 strcpy-012 field3 Not Found %s\n", field3);
        printf("c2z_strcpy.c c2_str_2 rct = %d p_string = %s\n",rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }
  }

/*
printf("\nc2z_strcpy.c str_2 rct = %d p_string = %s",rct,p_string);
printf("c2z_strcpy.c str_2 field1 = %s x99 = %d\n",field1,x99);
printf("c2z_strcpy.c str_2 field2 = %s\n",field2);
printf("c2z_strcpy.c str_2 field3 = %s\n",field3);
*/

  str8 = strcmp(field3, "ARGV");
  if (str8 == 0) 				/* fixed system variable ARGV	*/
  {
    strcpy(a_string, "         MVC   ");
    strcat(a_string, field1a);
    strcat(a_string, ",");
    strcat(a_string, field2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #61");
      trace_rec_3();
    }
  }

  if (str8 != 0) 			/* not a system variable		*/
  {
    str2 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          str2 = 1;
          strcpy(field4, lw_variable[I].lv_type);
        }
      }
    }

    if (str2 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          str1 = strcmp(field2, gw_variable[I].gv_name);
          if (str1 == 0) 
          {
            strcpy(field4, gw_variable[I].gv_type);
          }
        }
      }
    }

    str3 = strcmp(field4, "A");
    if (str3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          str1 = strcmp(field2, gw_variable[I].gv_name);
          if (str1 == 0) 
          {
            strcpy(field5, gw_variable[I].gv_dsect);
            strcpy(field6, gw_variable[I].gv_label);
            strcpy(field7, gw_variable[I].gv_table);
            strcpy(field8, gw_variable[I].gv_aname);
            strcpy(field9, gw_variable[I].gv_sv_reg);
            strcpy(field10, gw_variable[I].gv_wk_reg);
          }
        }
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #62");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #63");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #64");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, field7);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #65");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #66");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #67");
        trace_rec_3();
      }
      work_use_ct[49]++;

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
          strcpy(trace_1, "c2z_strcpy.c #68");
          trace_rec_3();
        }
      }

      if(fd3_type == 1)
      {
        strcpy(a_string, "         LAEY  R5,");
        strcat(a_string, field3);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #69");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #70");
          trace_rec_3();
        }
 
        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #71");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK3");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #72");
          trace_rec_3();
        }
        work_use_ct[78]++;

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #73");
          trace_rec_3();
        }
 
        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #74");
          trace_rec_3();
        }
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #75");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #76");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, field6);
      strcat(a_string, "(R0,R6)");
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #77");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #78");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #79");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #80");
        trace_rec_3();
      }

      strcpy(a_string, "         JLU   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #81");
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
        strcpy(trace_1, "c2z_strcpy.c #82");
        trace_rec_3();
      }

      strcpy(a_string, "         LHI   R0,X'0'");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R6");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }


      strcpy(a_string, "         LARL  R2,");
      strcat(a_string, field1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #83");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R3,1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "T");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #142");
        trace_rec_3();
      }

      strcpy(a_string, "         MVST  R2,R1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }

      strcpy(a_string, "         JO    ");
      strcat(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "T");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #142");
        trace_rec_3();
      }

      strcpy(a_string, "         SR    R1,R3");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }
    }

    str9 = strcmp(field4, "C");
    if(str9 == 0)
    {
      x500 = 0;
      x501 = 0;
      x502 = 0;

      x500 = strcmp(field3a,"tday");

      if(x500 == 0)
      {
        strcpy(a_string, "         LARL  R5,8");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #200");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #201");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #202");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK5");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #203");
          trace_rec_3();
        }
        work_use_ct[95]++;

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #204");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #205");
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
          strcpy(trace_1, "c2z_strcpy.c #206");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370TIME");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #207");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   0(2,R9),8(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #208");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370EOF");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #209");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   2(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #210");
          trace_rec_3();
        }

        str2 = 0;
        if (lv_ct > 0) 
        {
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(field1, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              str2 = 1;
              lw_variable[I].lv_current_lgth = 2;
              break;
            }
          }
        }

        if (str2 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (I = 0; I < gv_ct; I++) 
            {
              str1 = strcmp(field1, gw_variable[I].gv_name);
              if (str1 == 0) 
              {
                gw_variable[I].gv_current_lgth = 2;
                break;
              }
            }
          }
        }
      }

      x501 = strcmp(field3a,"tmth");
      if(x501 == 0)
      {
        strcpy(a_string, "         LARL  R5,5");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #211");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #212");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #213");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK5");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #214");
          trace_rec_3();
        }
        work_use_ct[95]++;

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #215");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #216");
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
          strcpy(trace_1, "c2z_strcpy.c #217");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370TIME");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #218");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   0(2,R9),5(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #219");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370EOF");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #220");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   2(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #210");
          trace_rec_3();
        }

        str2 = 0;
        if (lv_ct > 0) 
        {
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(field1, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              str2 = 1;
              lw_variable[I].lv_current_lgth = 2;
              break;
            }
          }
        }

        if (str2 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (I = 0; I < gv_ct; I++) 
            {
              str1 = strcmp(field1, gw_variable[I].gv_name);
              if (str1 == 0) 
              {
                gw_variable[I].gv_current_lgth = 2;
                break;
              }
            }
          }
        }
      }

      x502 = strcmp(field3a,"tyear");
      if(x502 == 0)
      {
        strcpy(a_string, "         LARL  R5,0");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #221");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #222");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #223");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK5");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #224");
          trace_rec_3();
        }
        work_use_ct[95]++;

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #225");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #226");
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
          strcpy(trace_1, "c2z_strcpy.c #227");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370TIME");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #228");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   0(4,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #229");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370EOF");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #230");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   4(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #231");
          trace_rec_3();
        }

        str2 = 0;
        if (lv_ct > 0) 
        {
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(field1, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              str2 = 1;
              lw_variable[I].lv_current_lgth = 2;
              break;
            }
          }
        }

        if (str2 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (I = 0; I < gv_ct; I++) 
            {
              str1 = strcmp(field1, gw_variable[I].gv_name);
              if (str1 == 0) 
              {
                gw_variable[I].gv_current_lgth = 4;
                break;
              }
            }
          }
        }
      }
    }
  }
  convert = 1;
  return;
}


void c2_str_3(int str1, int str2) 
{
  char *p, *p1;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield1b[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield8[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield11[VAR_LGTH];

  tfield1a[0] = '\0';
  tfield2a[0] = '\0';

  int pi;
  int pi2;
  int str3 = 0;
  int str5 = 0;
  int str6 = 0;
  int str7 = 0;
  int v = 0;
  int x2 = 0;
  int x3 = 0;
  int x5 = 0;
  int x6 = 0;
  int I = 0;
  int s = 0;
  int ret = 0;
  int ret1 = 0;
  int x90 = 0;
  int x91 = 0;
  int x95 = 0;
  int x96 = 0;
  int fd2_type = 0;
  int fd3_type = 0;

  x90 = 0;
  x91 = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[') 
    {
      x90++;
    }
    if (ch == ']') 
    {
      x91++;
    }
  }

  p1 = strstr(p_string, ".");

  if ((x90 == 1) && (x91 == 1) && (!p1)) 
  {
    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    pi2 = 0;
    ch = p_string[pi];
    while (ch != '[') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    if (str1 < str2) 
    {
      str3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield1, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if (str5 == 0) 
          {
            strcpy(tfield1a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
            str7 = lw_variable[I].lv_lgth;
            str3 = 1;
          }
        }
      }

      if (str3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            str5 = strcmp(tfield1, gw_variable[v].gv_name);
            if (str5 == 0) 
            {
              strcpy(tfield1a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
              str7 = gw_variable[I].gv_lgth;
              str3 = 1;
            }
          }
        }
      }

      if (str3 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_3 strcpy-014 tfield1 Not Found = %s\n", tfield1);
        printf("c2z_strcpy.c c2_str_3 rct = %d p_string = %s",rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      if (ch == '"') 
      {
        pi2 = 0;
        pi++;
        ch = p_string[pi];

        while (ch != '"') 
        {
          tfield2[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
          if (ch == '\n')
          {
            break;
          }
          if (ch == '\t')
          {
            break;
          }
        }
        tfield2[pi2] = '\0';

        if (str7 != 0) 
        {
          strcpy(a_string, "*         MVC   ");
          strcat(a_string, tfield1);
          snprintf(wk_strg, sizeof(wk_strg), "%d", str7);
          strcat(a_string, "(");
          strcat(a_string, wk_strg);
          strcat(a_string, ")");
          strcat(a_string, ",");
          strcat(a_string, "=CL");
          strcat(a_string, wk_strg);
          strcat(a_string, "' '");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #90");
            trace_rec_3();
          }
        }

        strcpy(a_string, "*         MVC   ");
        strcat(a_string, tfield1a);
        strcat(a_string, ",=CL");
        s = strlen(tfield2);
        snprintf(wk_strg, sizeof(wk_strg), "%d", s);
        strcat(a_string, wk_strg);
        strcat(a_string, "'");
        strcat(a_string, tfield2);
        strcat(a_string, "'");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #91");
          trace_rec_3();
        }

        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            gw_variable[I].gv_current_lgth = s;
          }
        }
      } 
      else 
      {
        pi2 = 0;
        x3 = 0;
        while ((ch != ')') && (x3 == 0)) 
        {
          if (ch == '[') 
          {
            x3 = 1;
          }
          if (x3 == 0) 
          {
            tfield2[pi2] = ch;
            pi2++;
          }
          pi++;
          ch = p_string[pi];
        }
        tfield2[pi2] = '\0';

        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(tfield2, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              strcpy(tfield2a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }

        x5 = 0;
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x5 = gw_variable[I].gv_lgth;
          }
        }

        if (x5 != 0) 
        {
          strcpy(a_string, "*         MVC   ");
          strcat(a_string, tfield1a);
          snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
          strcat(a_string, "(");
          strcat(a_string, wk_strg);
          strcat(a_string, ")");
          strcat(a_string, ",");
          strcat(a_string, "=CL");
          strcat(a_string, wk_strg);
          strcat(a_string, "' '");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #92");
            trace_rec_3();
          }
        }

        strcpy(a_string, "*         MVC   ");
        strcat(a_string, tfield1a);
        strcat(a_string, "(L'");
        strcat(a_string, tfield2a);
        strcat(a_string, "),");
        strcat(a_string, tfield2a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #93");
          trace_rec_3();
        }

        if (x3 == 0) 
        {
          printf("\nc2z_strcpy.c c2_str_3 strcpy-015 ERROR in c2_strcpy\n");
          printf("c2z_strcpy.c c2_str_3 rct = %d p_string = %s\n",rct,p_string);
          erct++;
          convert = 1;
          return;
        }
      }
    }

    if (str1 > str2) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_3 s < s");
        trace_rec_1();
      }

      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi++;
      pi2 = 0;
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
        if (x2 == 0) 
        {
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
        tfield2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield2[pi2] = '\0';

      pi2 = 0;
      x2 = 0;
      fd3_type = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if (ch != ',') 
        {
          if (ch != ' ') 
          {

            if(ch == '"')
            {
               fd3_type = 0;
               x2 = 1;
            }
            if (x2 == 0) 
            {
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
            tfield3[pi2] = ch;
            pi2++;
          }
        }
        pi++;
        ch = p_string[pi];
      }
      tfield3[pi2] = '\0';

/*
printf("\nc2z_strcpy.c s < s rct = %d p_string = %s",rct,p_string);
printf("c2z_strcpy.c s < s tfield1 = %s\n",tfield1);
printf("c2z_strcpy.c s < s tfield2 = %s\n",tfield2);
printf("c2z_strcpy.c s < s tfield3 = %s fd3_type = %d\n",tfield3,fd3_type);
printf("c2z_strcpy.c s < s #1 x6 = %d\n",x6);
*/

      if(fd2_type == 1)
      {

      }

      if(fd2_type == 2)
      {
        str2 = 0;
        if (lv_ct > 0) 
        {
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(tfield2, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              str2 = 1;
              strcpy(tfield2a, lw_variable[I].lv_cname);
              lw_variable[I].lv_use_ct++;
            }
          }
        }

        if (str2 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (I = 0; I < gv_ct; I++) 
            {
              str1 = strcmp(tfield2, gw_variable[I].gv_name);
              if (str1 == 0) 
              {
                str2 = 1;
                strcpy(tfield2a, gw_variable[I].gv_cname);
                gw_variable[I].gv_use_ct++;
              }
            }
          }
        }
      }

      str2 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(tfield1, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            str2 = 1;
            strcpy(tfield1b, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
            strcpy(tfield4, lw_variable[I].lv_type);
          }
        }
      }

      if (str2 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            str1 = strcmp(tfield1, gw_variable[I].gv_name);
            if (str1 == 0) 
            {
              strcpy(tfield4, gw_variable[I].gv_type);
              strcpy(tfield1b, gw_variable[I].gv_cname);
              str2 = 1;
            }
          }
        }
      }

      str3 = strcmp(tfield4, "A");
      if (str3 == 0) 
      {
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
              gw_variable[I].gv_flag = 0;
            }
          }
        }

        x6 = 0;
        if(fd3_type == 1)
        {
          p = strstr(tfield3, "\0");
          if (p) 
          {
            x6 = 1;
          }
        }

/*
        if(fd3_type == 0)
        {
          p = strstr(tfield3, "\0");
          if (p) 
          {
            x6 = 1;
          }
        }
*/

    
        if((x6 == 0) && (fd3_type == 2)) 
        {
          str6 = 0;
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(tfield3, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              str6 = 1;
              strcpy(tfield3a, lw_variable[I].lv_cname);
              lw_variable[I].lv_use_ct++;
              x5 = lw_variable[I].lv_current_lgth;
              break;
            }
          }

          if (str6 == 0) 
          {
            for (I = 0; I < gv_ct; I++) 
            {
              ret = strcmp(tfield3, gw_variable[I].gv_name);
              if (ret == 0) 
              {
                str6 = 1;
                strcpy(tfield3a, gw_variable[I].gv_cname);
                gw_variable[I].gv_use_ct++;
                x5 = gw_variable[I].gv_current_lgth;
                break;
              }
            }
          }
        }

        if(fd2_type == 1)
        {
          strcpy(a_string, "         LA    R5,");
          strcat(a_string, tfield2);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #94");
            trace_rec_3();
          }

          strcpy(a_string,"         LARL  R9,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #95");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string,"         CVD   R5,0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #96");
            trace_rec_3();
          }

          strcpy(a_string,"         LARL  R9,C370NWK2");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #97");
            trace_rec_3();
          }
          work_use_ct[50]++;

          strcpy(a_string,"         LARL  R8,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #98");
            trace_rec_3();
          }

          strcpy(a_string,"         ZAP   0(6,R9),0(8,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #99");
            trace_rec_3();
          }
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #100");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #101");
          trace_rec_3();
        }
        work_use_ct[32]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #102");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, tfield7);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #103");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "B");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #104");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #105");
          trace_rec_3();
        }
        work_use_ct[49]++;

        if (fd2_type == 1) 
        {
          strcpy(a_string, "         LARL  R8,C370NWK2");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #106");
            trace_rec_3();
           }
           work_use_ct[50]++;
        }

        if (fd2_type == 2) 
        {
          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, tfield2a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield2);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #107");
            trace_rec_3();
          }
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #108");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "F");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #109");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #110");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #111");
          trace_rec_3();
        }
        work_use_ct[33]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #112");
          trace_rec_3();
        }

        strcpy(a_string, "         LA    R6,");
        strcat(a_string, tfield6);
        strcat(a_string, "(R0,R6)");
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #113");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "B");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c #114");
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
          strcpy(trace_1, "c2z_strcpy.c #115");
          trace_rec_3();
        }

        if((x6 == 0) && (fd3_type == 0))
        {
          for (I = 0; I < char_ct; I++) 
          {
            if(rct == w_charlit[I].clit_rct)
            {
              strcpy(tfield3, w_charlit[I].clit_cname);
              x5 = w_charlit[I].clit_lgth;
              snprintf(wk_strg, sizeof(wk_strg), "%d", w_charlit[I].clit_lgth);
              break;
            }
          }

          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, tfield3);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield3);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #116");
            trace_rec_3();
          }

          snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
          strcpy(a_string, "         MVC   0(");
          strcat(a_string, wk_strg);
          strcat(a_string, ",R6),0(R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #117");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R8,C370EOF");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #118");
            trace_rec_3();
          }
         
          snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
          strcpy(a_string, "         MVC   ");
          strcat(a_string, wk_strg);
          strcat(a_string, "(1,R6),0(R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #119");
            trace_rec_3();
          }

        }


        if((x6 == 0) && (fd3_type == 2))
        {
          strcpy(a_string, "         LARL  R9,");
          strcat(a_string, tfield3a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield3);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #120");
            trace_rec_3();
          }

          snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
          strcpy(a_string, "         MVC   0(");
          strcat(a_string, wk_strg);
          strcat(a_string, ",R6),0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #121");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370EOF");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #122");
            trace_rec_3();
          }

          snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
          strcpy(a_string, "         MVC   ");
          strcat(a_string, wk_strg);
          strcat(a_string, "(1,R6),0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #123");
            trace_rec_3();
          }
        }

        if(x6 == 1)
        {
          strcpy(a_string, "         LARL  R8,C370EOF");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #118");
            trace_rec_3();
          }
         
          strcpy(a_string, "         MVC   0(1");
          strcat(a_string, ",R6),0(R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c #119");
            trace_rec_3();
          }
        }
      }

      ret1 = strcmp(tfield2, "C");
      if (ret1 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(tfield1a, gw_variable[I].gv_cname);
            if (ret == 0) 
            {
              strcpy(tfield5, gw_variable[I].gv_dsect);
              strcpy(tfield6, gw_variable[I].gv_label);
              strcpy(tfield7, gw_variable[I].gv_table);
              strcpy(tfield8, gw_variable[I].gv_aname);
              strcpy(tfield9, gw_variable[I].gv_sv_reg);
              strcpy(tfield10, gw_variable[I].gv_wk_reg);
            }
          }
        }
      }
    }
  }

  if ((x90 == 2) && (x91 == 2) && (!p1)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_string.c c2_str_3 MULTI");
      trace_rec_1();
    }

    int pi;

    char ch;
    char tfield1[VAR_LGTH];
    char tfield1a[VAR_LGTH];

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
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if (x2 == 0) 
      {
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
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

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
      if (ch != ' ') 
      {
        if (x2 == 0) 
        {
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
        tfield3[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    str6 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        str6 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
      }
    }

    if (str6 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          str6 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          strcpy(tfield5, gw_variable[I].gv_dsect);
          strcpy(tfield6, gw_variable[I].gv_label);
          strcpy(tfield7, gw_variable[I].gv_table);
          strcpy(tfield8, gw_variable[I].gv_aname);
          strcpy(tfield9, gw_variable[I].gv_sv_reg);
          strcpy(tfield10, gw_variable[I].gv_wk_reg);
        }
      }
    }

    if (str6 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_3 strcpy-017 MULTI tfield1 Not Found = %s\n",tfield1);
      printf("c2z_strcpy.c c2_str_3 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd2_type == 2) 
    {
      str6 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          str6 = 1;
          strcpy(tfield2a, lw_variable[I].lv_cname);
        }
      }

      if (str6 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield2, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            str6 = 1;
            strcpy(tfield2a, gw_variable[I].gv_cname);
          }
        }
      }

      if (str6 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_3 strcpy-018 MULTI tfield2 Not Found = %s\n",tfield2);
        printf("c2z_strcpy.c c2_str_3 rct = %d p_string = %s\n",rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if (fd2_type == 1) 
    {
      printf("\nc2z_strcpy.c c2_str_3 strcpy-019 MULTI fd2_type == 1 NOT CODED\n");
      printf("c2z_strcpy.c c2_str_3 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd3_type == 2) 
     {
      str6 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) {
          str6 = 1;
          strcpy(tfield3a, lw_variable[I].lv_cname);
        }
      }

      if (str6 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield3, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            str6 = 1;
            strcpy(tfield3a, gw_variable[I].gv_cname);
          }
        }
      }

      if (str6 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_3 strcpy-020 MULTI tfield3 Not Found = %s\n",tfield3);
        printf("c2z_strcpy.c c2_str_3 rct = %d p_string = %s\n",rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if (fd3_type == 1) 
    {
      printf("\nc2z_strcpy.c c2_str_3 strcpy-021 MULTI fd3type == 1 NOT CODED\n");
      printf("c2z_strcpy.c c2_str_3 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if ((x90 == 1) && (x91 == 1) && (p1)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_3 Structure");
      trace_rec_1();
    }

    char tfield5a[VAR_LGTH];
    char tfield6a[VAR_LGTH];

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
    while (ch != ',') 
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

    pi2 = 0;
    while (ch != ' ') 
    {
      tfield4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ')') 
    {
      tfield5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield5[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < m_struc_ct; I++) 
    {
      ret = strcmp(tfield1, w_struc[I].st_wname);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield1a, w_struc[I].st_cwname);
        strcpy(tfield6a, w_struc[I].st_cname);
        x90 = w_struc[I].st_field_lgth;
        break;
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_3 Structure strcpy-022 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_strcpy.c c2_str_3 rct = %d p_string = %s\n",rct,p_string);
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
      printf("\nc2z_strcpy.c c2_str_3 strcpy-023 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_strcpy.c c2_str_3 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < m_struc_ct; I++) 
    {
      ret = strcmp(tfield1, w_struc[I].st_wname);
      ret1 = strcmp(tfield3, w_struc[I].st_field_name);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield3a, w_struc[I].st_field_cname);
        x91 = w_struc[I].st_field_lgth;
        x95 = w_struc[I].st_disp;
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_3 Structure strcpy-024 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_strcpy.c c2_str_3 Structure tfield3 Not Found = %s\n",tfield3);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield5, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield5a, lw_variable[I].lv_cname);
        x96 = lw_variable[I].lv_lgth;
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
          x96 = gw_variable[I].gv_lgth;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_3 strcpy-025 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_strcpy.c c2_str_3 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #118");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #119");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #120");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "T");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #121");
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
      strcpy(trace_1, "c2z_strcpy.c #122");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #123");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #124");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #125");
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
      strcpy(trace_1, "c2z_strcpy.c #126");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, tfield6a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #127");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #128");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #129");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #130");
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
      strcpy(trace_1, "c2z_strcpy.c #131");
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
      strcpy(trace_1, "c2z_strcpy.c #132");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield5a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c 133");
      trace_rec_3();
    }
    
    snprintf(wk_strg, sizeof(wk_strg), "%d", x95);
    strcpy(a_string, "         MVC   ");
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #134");
      trace_rec_3();
    }
  }

  convert = 1;
}

void c2_str_4() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_4");
    trace_rec_1();
  }

  char ch;
  char *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield4[VAR_LGTH];

  int pi;
  int pi2;
  int v = 0;
  int I = 0;
  int x5 = 0;
  int x6 = 0;
  int x10 = 0;

  tfield1a[0] = '\0';
  tfield2a[0] = '\0';

  int str3 = 0;
  int str4 = 0;

  int ret = 0;
  int ret1 = 0;

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
  while (ch != ',') 
  {
    if (ch != ' ') 
    {
      tfield1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';
  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;

  while (ch != ')') 
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

  x6 = 0;
  p = strstr(tfield2, "\"");
  if(p)
  {
    x6 = 1;
  }
  else
  {
    x6 = 2;
  }

  if(x6 == 1)
  {
    for (I = 0; I < char_ct; I++) 
    {
      if(rct == w_charlit[I].clit_rct)
      {
        strcpy(tfield2, w_charlit[I].clit_cname);
        x5 = w_charlit[I].clit_lgth;
        snprintf(wk_strg, sizeof(wk_strg), "%d", w_charlit[I].clit_lgth);
        break;
      }
    }
  }

  str3 = 0;
  str4 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        str3 = 1;
        strcpy(tfield1a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        break;
      }
    }
  }

  if (str3 == 0) 
  {
    str4 = 0;
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        str4 = strcmp(tfield1, gw_variable[v].gv_name);
        if (str4 == 0) 
        {
          str3 = 1;
          strcpy(tfield1a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
          break;
        }
      }
    }
  }

  if (str3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_4 strcpy-026 tfield1 Not Found %s\n", tfield1);
    printf("c2z_strcpy.c c2_str_4 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }


  if(x6 == 2)
  {
    str3 = 0;
    str4 = 0;
    x10 = 0;

    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield2, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          str3 = 1;
          strcpy(tfield2a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          break;
        }
      }
    }

    if (str3 == 0) 
    {
      str4 = 0;
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          str4 = strcmp(tfield2, gw_variable[v].gv_name);
          if (str4 == 0) 
          {
            str3 = 1;
            strcpy(tfield2a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            break;
          }
        }
      }
    }

    if (str3 == 0) 
    {
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(tfield2, w_function[I].fn_name);
        if (ret == 0) 
        {
          str3 = 1;
          x10 = 1;
          strcpy(tfield2a, w_function[I].fn_cname);
          strcpy(tfield4, w_function[I].fn_ret_var);
        }
      }
    }

    if (str3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_4 strcpy-027 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_strcpy.c c2_str_4 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }


  if (x10 == 0) 
  {
    if(!p)
    {
      strcpy(a_string, "         LHI   R0,X'0'");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #135");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R1,");
      strcat(a_string, tfield2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136");
        trace_rec_3();
      }
      strcpy(a_string, "         LARL  R2,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #137");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R3,1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #138");
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
        strcpy(trace_1, "c2z_strcpy.c #139");
        trace_rec_3();
      }

      strcpy(a_string, "         MVST  R2,R1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #140");
        trace_rec_3();
      }

      strcpy(a_string, "         JO    ");
      strcat(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #141");
        trace_rec_3();
      }

      strcpy(a_string, "         SR    R1,R3");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #142");
        trace_rec_3();
      }
    }

    if(p)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #143");
        trace_rec_3();
      }
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #144");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   0(");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
      strcat(a_string, wk_strg);
      strcat(a_string, ",R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #145");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #146");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
      strcat(a_string, wk_strg);
      strcat(a_string, "(1");
      strcat(a_string, ",R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #147");
        trace_rec_3();
      }
    }

    str3 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        str3 = 1;
        strcpy(tfield1a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        lw_variable[v].lv_current_lgth = x5;
        break;
      }
    }
 
    if (str3 == 0) 
    {
      str4 = 0;
     
        for (v = 0; v < gv_ct; v++) 
        {
          str4 = strcmp(tfield1, gw_variable[v].gv_name);
          if (str4 == 0) 
          {
            str3 = 1;
            strcpy(tfield1a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            gw_variable[v].gv_current_lgth = x5;
            break;
          }
        }
     
    }
  }

  convert = 1;
}

void c2_str_5() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_5");
    trace_rec_1();
  }

  char ch;
  char *p;

  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield4a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield12[VAR_LGTH];

  char ar_field5[12];
  char ar_field6[12];
  char ar_field7[12];
  char ar_field8[12];
  char ar_field9[12];
  char ar_field10[12];
  char ar_field11[12];

  char ar1_field5[12];
  char ar1_field6[12];
  char ar1_field7[12];
  char ar1_field8[12];
  char ar1_field9[12];
  char ar1_field10[12];
  char ar1_field11[12];

  int I = 0;
  int x1 = 0;
  int x2 = 0;
  int x11 = 0;
  int x90 = 0;
  int x91 = 0;
  int x93 = 0;
  int x94 = 0;
  int s = 0;
  int ret = 0;
  int ret1 = 0;
  int pi;
  int pi2;
  int fd2_type = 0;
  int fd5_type = 0;

  s = strlen(p_string);
  x90 = 0;
  x91 = 0;
  x93 = 0;
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[') 
    {
      x90++;
    }
    if (ch == ']') 
    {
      x91++;
    }
    if (ch == '.')
    {
      x93++;
    }
  }

  if ((x90 == 1) && (x91 == 1)) 
  {
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

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ';') 
    {
      tfield4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
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

    if (x1 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_5 strcpy-028 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_strcpy.c c2_str_5 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(tfield2a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_5 strcpy-029 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_strcpy.c c2_str_5 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield3, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(tfield3a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield3, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(tfield3a, gw_variable[I].gv_cname);
          strcpy(ar1_field5, gw_variable[I].gv_dsect);
          strcpy(ar1_field6, gw_variable[I].gv_label);
          strcpy(ar1_field7, gw_variable[I].gv_table);
          strcpy(ar1_field8, gw_variable[I].gv_aname);
          strcpy(ar1_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar1_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar1_field11, gw_variable[I].gv_wk_strg);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_5 strcpy-030 tfield3 Not Found = %s\n", tfield3);
      printf("c2z_strcpy.c c2_str_5 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(tfield4a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(tfield4a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_5 strcpyh-031 tfield4 Not Found = %s\n", tfield4);
      printf("c2z_strcpy.c c2_str_5 rct = %d p_string = %s",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(tfield12, tfield1);
    strcat(tfield12, "_width");

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield12, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield12, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_5 strcpy-032 tfield12 Not Found = %s\n", tfield12);
      printf("c2z_strcpy.c c2_str_5 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(tfield12, tfield3);
    strcat(tfield12, "_width");

    x1 = 0;
    for (I = 0; I < lv_ct; I++)
    {
      ret = strcmp(tfield12, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        x11 = lw_variable[I].lv_lgth;
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield12, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          x11 = gw_variable[I].gv_lgth;
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_5 strcpy-033 tfield12 Not Found = %s\n", tfield12);
      printf("c2z_strcpy.c c2_str_5 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #148");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #149");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #150");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #151");
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
      strcpy(trace_1, "c2z_strcpy.c #152");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #153");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #154");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #155");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #156");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #157");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #158");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #159");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #160");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #151");
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
      strcpy(trace_1, "c2z_strcpy.c #152");
      trace_rec_3();
    }

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #153");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R5,");
    strcat(a_string, ar1_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #154");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #155");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #156");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #157");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #158");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #159");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield4a);
    src_line();
    if (puncde == 1) {
      strcpy(trace_1, "c2z_strcpy.c #160");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #161");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #162");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R5,");
    strcat(a_string, ar1_field6);
    strcat(a_string, "(R0,R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #163");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #164");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #165");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #166");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #167");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #168");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x11);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),0(R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #169");
      trace_rec_3();
    }

    convert = 1;
  }

  if ((x90 == 2) && (x91 == 2) && (x93 == 0)) 		/*   strcpy(in_stack[2], in_stack[1];	*/
  {
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
    pi++;
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

    p = strstr(p_string, "\"");

    if (p) 
    {
      ch = p_string[pi];
      while (ch != '\"') 
      {
        pi++;
        ch = p_string[pi];
      }

      x94 = 0;
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != '\"') 
      {
        tfield4[pi2] = ch;
        x94++;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';
    }

    pi++;
    pi++;

    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if(ch != ' ')
      {
        tfield4[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != ']')
    {
        if (x2 == 0) 
        {
          if ((isdigit(ch)) && (x2 == 0)) 
          {
            fd5_type = 2;
            x2 = 1;
          }

          if ((isalpha(ch)) && (x2 == 0)) 
          {
            fd5_type = 1;
            x2 = 1;
          }
        }

      tfield5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield5[pi2] = '\0';

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        strcpy(tfield1a, lw_variable[I].lv_cname);
        x1 = 1;
        break;
      }
    }

    if(x1 == 0)
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(tfield1a, gw_variable[I].gv_cname);
          x1 = 1;
          strcpy(ar_field5, gw_variable[I].gv_dsect);
          strcpy(ar_field6, gw_variable[I].gv_label);
          strcpy(ar_field7, gw_variable[I].gv_table);
          strcpy(ar_field8, gw_variable[I].gv_aname);
          strcpy(ar_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar_field11, gw_variable[I].gv_wk_strg);

          break;
        }
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #170");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #171");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #172");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1); 
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #173");
      trace_rec_3();
    }

    if (fd2_type == 1) 
    {
      x1 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x1 = 1;
          strcpy(tfield2a, lw_variable[I].lv_cname);
        }
      }

      if (x1 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield2, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x1 = 1;
            strcpy(tfield2a, gw_variable[I].gv_cname);
          }
        }
      }

      if (x1 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_5 strcpy-034 tfield2 Not Found = %s\n", tfield2);
        printf("c2z_strcpy.c c2_str_5 rct = %d p_string = %s\n",rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #174");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if (fd2_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #175");
        trace_rec_3();
      }
    }


    if (fd2_type == 2) 
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield2);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #176");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #177");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #178");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #179");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #180");
        trace_rec_3();
      }
      work_use_ct[48]++;
 
      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #181");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #182");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcpy(start_while, a_string);
    strcat(a_string, "F");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #183");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #184");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #185");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #186");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #187");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #188");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(start_while, a_string);
    strcat(a_string, "F");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #189");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #190");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #191");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #192");
      trace_rec_3();
    }

    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield4, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(tfield4a, gw_variable[I].gv_cname);
        strcpy(ar1_field5, gw_variable[I].gv_dsect);
        strcpy(ar1_field6, gw_variable[I].gv_label);
        strcpy(ar1_field7, gw_variable[I].gv_table);
        strcpy(ar1_field8, gw_variable[I].gv_aname);
        strcpy(ar1_field9, gw_variable[I].gv_sv_reg);
        strcpy(ar1_field10, gw_variable[I].gv_wk_reg);
        strcpy(ar1_field11, gw_variable[I].gv_wk_strg);
        break;
      }
    }

    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, ar1_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #193");
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
      strcpy(trace_1, "c2z_strcpy.c #194");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #195");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if (fd5_type == 1) 
    {
      x1 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield5, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x1 = 1;
          strcpy(tfield5a, lw_variable[I].lv_cname);
        }
      }

      if (x1 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield5, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x1 = 1;
            strcpy(tfield5a, gw_variable[I].gv_cname);
          }
        }
      }

      if (x1 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_5 strcpy-035 tfield5 Not Found = %s\n", tfield5);
        printf("c2z_strcpy.c c2_str_5 rct = %d p_string = %s\n",rct,p_string);
        erct++;
        convert = 1;
        return;
      }
 
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #196");
        trace_rec_3();
      }
    }

    if (fd5_type == 2) 
    {
      strcpy(a_string, "         LARL  R4,");
      strcat(a_string, tfield5);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #197");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #198");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R4,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #199");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #200");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #201");
        trace_rec_3();
      }
      work_use_ct[48]++;
 
      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #202");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #203");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcpy(start_while, a_string);
    strcat(a_string, "N");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #204");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R5,");
    strcat(a_string, ar1_field6);
    strcat(a_string, "(R0,R5)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #205");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #206");
      trace_rec_3();
    }
    work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #207");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #208");
        trace_rec_3();
      }

      strcpy(a_string, "         JLU   ");
      strcat(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "M");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #209");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcpy(start_while, a_string);
      strcat(a_string, "N");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #210");
        trace_rec_3();
      }

      strcpy(a_string, "         LHI   R0,X'0'");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R2,R6");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R3,1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "T");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #142");
        trace_rec_3();
      }

      strcpy(a_string, "         MVST  R2,R1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }

      strcpy(a_string, "         JO    ");
      strcat(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "T");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #142");
        trace_rec_3();
      }

      strcpy(a_string, "         SR    R1,R3");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }

    convert = 1;
  }
}


void c2_str_6() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_str_6");
    trace_rec_1();
  }

  char ch;
  char *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char wk_sv_func[VAR_LGTH];

  int pi;
  int pi2 = 0;
  int I = 0;
  int x1 = 0;
  int ret = 0;
  int ret1 = 0;
  int no_parameters = 0;

  p = strstr(p_string, "()");
  if (p) 
  {
    no_parameters = 1;
  }

  if (no_parameters == 1) 
  {
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
    while (ch != ',') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    for (I = 0; I < fn_ct; I++) 
    {
      ret = strcmp(tfield2, w_function[I].fn_name);
      if (ret == 0) 
      {
        strcpy(wk_sv_func, tfield2);
        strcpy(tfield2a, w_function[I].fn_cname);
        strcpy(tfield3, w_function[I].fn_ret_var);
      }
    }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #212");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #213");
      trace_rec_3();
    }

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield3, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(tfield3a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield3, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(tfield3a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_6 strcpy-036 tfield3 Not Found = %s\n", tfield3);
      printf("c2z_strcpy.c c2_str_6 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_6 strcpy-037 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_strcpy.c c2_str_6 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

      strcpy(a_string, "         LHI   R0,X'0'");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R1,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }
      strcpy(a_string, "         LARL  R2,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136a");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R3,1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
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
        strcpy(trace_1, "c2z_strcpy.c #142");
        trace_rec_3();
      }

      strcpy(a_string, "         MVST  R2,R1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }

      strcpy(a_string, "         JO    ");
      strcat(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #142");
        trace_rec_3();
      }

      strcpy(a_string, "         SR    R1,R3");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #136b");
        trace_rec_3();
      }

    strcpy(a_string, "*         MVC2  ");
    strcat(a_string, tfield1a);
    strcat(a_string, ",");
    strcat(a_string, tfield3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #214");
      trace_rec_3();
    }
    convert = 1;
  }
}



void c2_str_7() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_str_7");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield4a[VAR_LGTH];

   int pi;
   int pi2;
   int I;
   int x3;
   int ret;
   int ret1;
   int x2;
   int x92;
   int x96;   
   int v;
   int s;
   int fd2_type = 0;
   int x20;
   int x21;
   int x22;

   x20 = 0;
   x21 = 0;
   x22 = 0;
   s = strlen(p_string);
   for(I = 0; I < s; I++)
   {
     ch = p_string[I];
     if(ch == '(')
     {
        x20++;
     }
     if(ch == ')')
     {
        x20++;
     }
     if(ch == '[')
     {  
        x21++;
     }
     if(ch == ']')
     {
        x21++;
     }
     if(ch == '.')
     {
        x22++;
     }
   }

   if((x20 == 2) && (x21 == 2) && (x22 == 1))
   {
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
     while (ch != '[') 
     {
       tfield1[pi2] = ch;
       pi2++;
       pi++;
       ch = p_string[pi];
     }
     tfield1[pi2] = '\0';

  x2 = 0;
  pi2 = 0;
  pi++;
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
  while (ch != ',') 
  {
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  pi++;
  ch = p_string[pi];

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if(ch != ' ')
    {
      tfield4[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(tfield1, w_struc[I].st_wname);
    ret1 = strcmp(tfield3, w_struc[I].st_field_name);
    if ((ret == 0) && (ret1 == 0)) 
    {
       x3 = 1;
       strcpy(tfield1a, w_struc[I].st_cwname);
       x92 = w_struc[I].st_field_lgth;
       x96 = w_struc[I].st_disp;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_7 strcpy-059 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_strcpy.c c2_str_7 tfield3 Not Found = %s\n",tfield3);
    printf("c2z_strcpy.c c2_str_7 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  if(fd2_type == 1)
  {
    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield2, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield2a, lw_variable[v].lv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield2, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield2a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_7 strcpy-060 tfield2 Not Found = %s\n",tfield2);
      printf("c2z_strcpy.c c2_str_7 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield4, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield4a, lw_variable[v].lv_cname);
        x92 = lw_variable[v].lv_current_lgth;
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(tfield4, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield4a, gw_variable[v].gv_cname);
          x92 = gw_variable[v].gv_current_lgth;
          break;

        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_7 strcpy-061 tfield4 Not Found = %s\n",tfield4);
    printf("c2z_strcpy.c c2_str_7 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
    erct++;
    convert = 1;
    return;
  }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #215");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #216");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #217");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "T");
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #218");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #219");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #220");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #221");
        trace_rec_3();
      }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield2);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #222");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #223");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #224");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #225");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #226");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #227");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #228");
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
      strcpy(trace_1, "c2z_strcpy.c #229");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #230");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #231");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #232");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #233");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #234");
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
      strcpy(trace_1, "c2z_strcpy.c #235");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #236");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #237");
      trace_rec_3();
    }
   
    x96--;
    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x92);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    strcat(a_string, "0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #238");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #239");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x96+x92);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    strcat(a_string, "1,R6),");
    strcat(a_string, "0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #240");
      trace_rec_3();
    }


/*
3  113    c2z_strcpy.c #283                        LARL  R8,C37F95                       123456               0002367
3  113    c2z_strcpy.c #284                        MVC   5(6,R6),0(R8)                                            0002368
3  113    c2z_strcpy.c #285                        LARL  R8,C370EOF                                               0002369
3  113    c2z_strcpy.c #286                        MVC   11(1,R6),0(R8)                                           0002370
*/

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #241");
      trace_rec_3();
    }



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
  while (ch != '[') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';
 
  x2 = 0;
  pi2 = 0;
  pi++;
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
  while (ch != ',') 
  {
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if(ch != ' ')
    {
      tfield4[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(tfield1, w_struc[I].st_name);
    ret1 = strcmp(tfield3, w_struc[I].st_field_name);
    if ((ret == 0) && (ret1 == 0)) 
    {
       x3 = 1;
       strcpy(tfield1a, w_struc[I].st_field_cname);
       x92 = w_struc[I].st_field_lgth;
       x96 = w_struc[I].st_disp;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_7 strcpy-038 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_strcpy.c c2_str_7 tfield3 Not Found = %s\n",tfield3);
    printf("c2z_strcpy.c c2_str_7 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield4, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield4a, lw_variable[v].lv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(tfield4, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield4a, gw_variable[v].gv_cname);
        }
      }
    }
  }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_7 strcpy-039 tfield4 Not Found = %s\n",tfield4);
      printf("c2z_strcpy.c c2_str_7 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
      erct++;
      convert = 1;
      return;
    }

    if(fd2_type == 1)
    {
      x3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield2, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(tfield2a, lw_variable[v].lv_cname);
          }
        }
      }

      if (x3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(tfield2, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
              strcpy(tfield2a, gw_variable[v].gv_cname);
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_7 strcpy-040 tfield2 Not Found = %s\n",tfield2);
        printf("c2z_strcpy.c c2_str_7 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
        erct++;
        convert = 1;
        return;
      }
    }


    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[v].lv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_7 strcpy-041 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_strcpy.c c2_str_7 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #240");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #241");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #242");
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
      strcpy(trace_1, "c2z_strcpy.c #243");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #244");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #245");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #246");
        trace_rec_3();
      }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LA    R5,");
      strcat(a_string, tfield2);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #247");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #248");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #249");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #250");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #251");
        trace_rec_3();
      }
      work_use_ct[48]++;
 
      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #252");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #253");
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
      strcpy(trace_1, "c2z_strcpy.c #254");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #255");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #256");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #257");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #258");
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
      strcpy(trace_1, "c2z_strcpy.c #259");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #260");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #261");
      trace_rec_3();
    }


    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x92);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    x96 = 0;
    snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
    strcat(a_string, wk_strg);
    strcat(a_string, "(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #261");
      trace_rec_3();
    }

  convert = 1;
}


void c2_str_8() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_str_8");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield4a[VAR_LGTH];

   int pi;
   int pi2;
   int I;
   int x3;
   int ret;
   int ret1;
   int x2;
   int x92;
   int x96;
   int v;
   int fd2_type = 0;

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
  while (ch != '[') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';
 
  x2 = 0;
  pi2 = 0;
  pi++;
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
  while (ch != ',') 
  {
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if(ch != '\"')
    {
      if(ch != ' ')
      {
        tfield4[pi2] = ch;
        pi2++;
      }
    }
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(tfield1, w_struc[I].st_wname);
    ret1 = strcmp(tfield3, w_struc[I].st_field_name);
    if ((ret == 0) && (ret1 == 0)) 
    {
       x3 = 1;
       strcpy(tfield1a, w_struc[I].st_cwname);
       x92 = w_struc[I].st_field_lgth;
       x96 = w_struc[I].st_disp;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_8 Structure strcpy-042 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_strcpy.c c2_str_8 Structure tfield3 Not Found = %s\n",tfield3);
    printf("c2z_strcpy.c c2_str_8 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  for (I = 0; I < char_ct; I++) 
  {
    if (w_charlit[I].clit_rct == rct) 
    {
      strcpy(tfield4a, w_charlit[I].clit_cname);
      x92 = w_charlit[I].clit_lgth;
      break;
    }
  }

  if(fd2_type == 1)
  {
      x3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield2, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(tfield2a, lw_variable[v].lv_cname);
          }
        }
      }

      if (x3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(tfield2, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
              strcpy(tfield2a, gw_variable[v].gv_cname);
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_8 strcpy-043 tfield2 Not Found = %s\n",tfield2);
        printf("c2z_strcpy.c c2_str_8 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
        erct++;
        convert = 1;
        return;
      }
    }


    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[v].lv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_8 strcpy-044 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_strcpy.c c2_str_8 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
      erct++;
      convert = 1;
      return;
    }

/*
printf("\nc2z_strcpy.c str_8 rct = %d p_string = %s",rct,p_string);
printf("c2z_strcpy.c str_8 tfield1 = %s\n",tfield1);
printf("c2z_strcpy.c str_8 tfield2 = %s\n",tfield2);
printf("c2z_strcpy.c str_8 tfield3 = %s\n",tfield3);
printf("c2z_strcpy.c str_8 tfield4 = %s tfield4a = %s\n",tfield4,tfield4a);
*/

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #262");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #263");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #264");
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
      strcpy(trace_1, "c2z_strcpy.c #265");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #266");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #267");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #268");
        trace_rec_3();
      }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LA    R5,");
      strcat(a_string, tfield2);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #269");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #270");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #271");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #272");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #273");
        trace_rec_3();
      }
      work_use_ct[48]++;
 
      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #274");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #275");
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
      strcpy(trace_1, "c2z_strcpy.c #276");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #277");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #278");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #279");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #280");
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
      strcpy(trace_1, "c2z_strcpy.c #281");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #282");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #283");
      trace_rec_3();
    }

    x96--;
    x3 = x96 + x92;
    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x92);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    x96 = 0;
    snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
    strcat(a_string, wk_strg);
    strcat(a_string, "(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #284");
      trace_rec_3();
    }
    
    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #285");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    strcat(a_string, "1,R6),");
    x96 = 0;
    snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
    strcat(a_string, wk_strg);
    strcat(a_string, "(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #286");
      trace_rec_3();
    }

  convert = 1;
  return;
}

/* copy into array from structure  - LEFT */
/* strcpy(in_stack[x], gw_variable[gv_ct].gv_name); */

void c2_str_9() 	 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_str_9");
    trace_rec_1(); 
  }
   int s;
   int I;
   int v;
   int x1;
   int x2;
   int x3;
   int x20;
   int x21;
   int x22;
   int x92;
 /*  int x96; */
   int pi;
   int pi2;
   int ret;
   int ret1;
   int fd2_type = 0;
/*   int fd4_type = 0; */

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

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];


  x20 = 0;
  x21 = 0;
  x22 = 0;

  s = strlen(p_string);

  for(I=0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '(')
    {
      x20++;
    }
    if(ch == ')')
    {
      x20++;
    }
    if(ch == '[')
    {
      x21++;
    }
    if(ch == ']')
    {
      x21++;
    }
    if(ch == '.')
    {
      x22++;
    }
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
  while (ch != '[') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  x2 = 0;
  pi2 = 0;
  fd2_type = 0;
  pi++;
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
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  pi2 = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while (ch != '[') 
  {
    if(ch != ' ')
    {
      field3[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if(ch != ' ')
    {
      if (x2 == 0) 
      {
        if ((isdigit(ch)) && (x2 == 0)) 
        {
      /*    fd4_type = 2; */
          x2 = 1;
        }

        if ((isalpha(ch)) && (x2 == 0)) 
        {
   /*       fd4_type = 1; */
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
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if(ch != '.')
    {
      field5[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field5[pi2] = '\0';

   x1 = 0;
    if(x1 == 0)
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(field1a, gw_variable[I].gv_cname);
          x92 = gw_variable[I].gv_lgth;
          x1 = 1;
          strcpy(ar_field5, gw_variable[I].gv_dsect);
          strcpy(ar_field6, gw_variable[I].gv_label);
          strcpy(ar_field7, gw_variable[I].gv_table);
          strcpy(ar_field8, gw_variable[I].gv_aname);
          strcpy(ar_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar_field11, gw_variable[I].gv_wk_strg);

          break;
        }
      }
    }

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field2, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[v].lv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[v].gv_cname);
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_9 strcpy-106 field2 Not Found = %s\n",field2);
    printf("c2z_strcpy.c c2_str_9 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(field3, w_struc[I].st_name);
    if(ret == 0)
    {
       x3 = 1;
       strcpy(field3a, w_struc[I].st_cname);
       break;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_10 strcpy-059 field1 Not Found = %s\n", field1);
    printf("c2z_strcpy.c c2_str_10 field3 Not Found = %s\n",field3);
    printf("c2z_strcpy.c c2_str_10 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(field3, w_struc[I].st_name);
    ret1 = strcmp(field5, w_struc[I].st_field_name);
    if((ret == 0) && (ret1 == 0))
    {
       x3 = 1;
       x92 = w_struc[I].st_field_lgth;
    /*   x96 = w_struc[I].st_disp; */
       break;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_9 strcpy-159 field3 Not Found = %s\n", field3);
    printf("c2z_strcpy.c c2_str_10 field5 Not Found = %s\n",field5);
    printf("c2z_strcpy.c c2_str_10 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field4, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field4a, lw_variable[v].lv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field4, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field4a, gw_variable[v].gv_cname);
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_9 strcpy-116 field4 Not Found = %s\n",field4);
    printf("c2z_strcpy.c c2_str_9 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
    erct++;
    convert = 1;
    return;
  }



/* strcpy(in_stack[x], gw_variable[gv_ct].gv_name); */

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #287");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #288");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #289");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R4,");
  strcat(a_string, ar_field7);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #290");
    trace_rec_3();
  }

  if (fd2_type == 1) 
  {
    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(field2, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_9 strcpy-104 field2 Not Found = %s\n", field2);
      printf("c2z_strcpy.c c2_str_5 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "D");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #291");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #292");
    trace_rec_3();
  }
  work_use_ct[49]++;

  if (fd2_type == 1) 
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #293");
      trace_rec_3();
    }
  }

  if (fd2_type == 2) 
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #294");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #295");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #296");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #297");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #298");
      trace_rec_3();
    }
    work_use_ct[48]++;
 
    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #299");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #300");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcpy(start_while, a_string);
  strcat(a_string, "F");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #301");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R4,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R4)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #302");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #303");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #304");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #305");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "D");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #306");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcpy(start_while, a_string);
  strcat(a_string, "F");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #307");
    trace_rec_3();
  }

/*  now get structure */

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #308");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #309");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #310");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, field3a);
  strcat(a_string, "T");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #311");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #312");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #313");
    trace_rec_3();
  }
  work_use_ct[49]++;

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #314");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #315");
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
    strcpy(trace_1, "c2z_strcpy.c #316");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #317");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #318");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #319");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #320");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, field3a);
  strcat(a_string, "L");
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #321");
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
    strcpy(trace_1, "c2z_strcpy.c #322");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #323");
    trace_rec_3();
  }

 /* MVC   0(16,R4),0(R6)   */

    strcpy(a_string, "         MVC   0");
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x92);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R4),");
  /*  x96 = 0;
    snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
    strcat(a_string, wk_strg); */
    strcat(a_string, "6(R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #324");
      trace_rec_3();
    }

  convert = 1;
  return;
}


/* strcpy(gw_variable[gv_ct].gv_name, in_stack[x]); */
/* copy into structure from array - RIGHT */
void c2_str_10() 	
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_str_10");
    trace_rec_1(); 
  }

   int s;
   int I;
   int v;
   int x1;
   int x2;
   int x3;
   int x20;
   int x21;
   int x22;
   int x92;
   int x96;
   int pi;
   int pi2;
   int ret;
   int ret1;
   int fd2_type = 0;
/*   int fd5_type = 0; */

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
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

  x20 = 0;
  x21 = 0;
  x22 = 0;
  s = strlen(p_string);

  for(I=0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '(')
    {
      x20++;
    }
    if(ch == ')')
    {
      x20++;
    }
    if(ch == '[')
    {
      x21++;
    }
    if(ch == ']')
    {
      x21++;
    }
    if(ch == '.')
    {
      x22++;
    }
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
  while (ch != '[') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';
 
  x2 = 0;
  pi2 = 0;
  fd2_type = 0;
  pi++;
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
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  pi2 = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
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

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != '[') 
  {
    if(ch != ' ')
    {
      if(ch != ',')
      {
        field4[pi2] = ch;
        pi2++;
      }
    }
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';

  x2 = 0;
  pi2 = 0;
 /* fd5_type = 0; */
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if (x2 == 0) 
    {
      if ((isdigit(ch)) && (x2 == 0)) 
      {
   /*     fd5_type = 2; */
        x2 = 1;
      }

      if ((isalpha(ch)) && (x2 == 0)) 
      {
  /*      fd5_type = 1; */
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
    printf("\nc2z_strcpy.c c2_str_10 strcpy-059 field1 Not Found = %s\n", field1);
    printf("c2z_strcpy.c c2_str_10 field3 Not Found = %s\n",field3);
    printf("c2z_strcpy.c c2_str_10 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(field1, w_struc[I].st_name);
    ret1 = strcmp(field3, w_struc[I].st_field_name);
    if((ret == 0) && (ret1 == 0))
    {
       x3 = 1;
       x92 = w_struc[I].st_field_lgth;
       x96 = w_struc[I].st_disp; 
       break;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_10 strcpy-059 field1 Not Found = %s\n", field1);
    printf("c2z_strcpy.c c2_str_10 field3 Not Found = %s\n",field3);
    printf("c2z_strcpy.c c2_str_10 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field2, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[v].lv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[v].gv_cname);
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_10 strcpy-060 field2 Not Found = %s\n",field2);
    printf("c2z_strcpy.c c2_str_10 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field4, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field4a, lw_variable[v].lv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field4, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field4a, gw_variable[v].gv_cname);
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_10 strcpy-061 field4 Not Found = %s\n",field4);
    printf("c2z_strcpy.c c2_str_10 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #325");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #326");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #327");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, field1a);
  strcat(a_string, "T");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #328");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #329");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #330");
    trace_rec_3();
  }
  work_use_ct[49]++;

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
      strcpy(trace_1, "c2z_strcpy.c #331");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #332");
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
    strcpy(trace_1, "c2z_strcpy.c #333");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #334");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #335");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #336");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #337");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, field1a);
  strcat(a_string, "L");
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #338");
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
    strcpy(trace_1, "c2z_strcpy.c #339");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #340");
    trace_rec_3();
  }

/* now to find the in_stack[x] - got gw_variable */

    x1 = 0;
    if(x1 == 0)
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(field4a, gw_variable[I].gv_cname);
          x92 = gw_variable[I].gv_lgth;
          x1 = 1;
          strcpy(ar_field5, gw_variable[I].gv_dsect);
          strcpy(ar_field6, gw_variable[I].gv_label);
          strcpy(ar_field7, gw_variable[I].gv_table);
          strcpy(ar_field8, gw_variable[I].gv_aname);
          strcpy(ar_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar_field11, gw_variable[I].gv_wk_strg);

          break;
        }
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #341");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #342");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c343");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R4,");
    strcat(a_string, ar_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #344");
      trace_rec_3();
    }

   if (fd2_type == 1) 
   {
      x1 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field5, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x1 = 1;
          strcpy(field5a, lw_variable[I].lv_cname);
        }
      }

      if (x1 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field5, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x1 = 1;
            strcpy(field5a, gw_variable[I].gv_cname);
          }
        }
      }

      if (x1 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_10 strcpy-084 field5 Not Found = %s\n", field5);
        printf("c2z_strcpy.c c2_str_5 rct = %d p_string = %s\n",rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #345");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #346");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if (fd2_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field5a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #347");
        trace_rec_3();
      }
    }

    if (fd2_type == 2) 
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field5);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #348");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #349");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #350");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #351");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #352");
        trace_rec_3();
      }
      work_use_ct[48]++;
 
      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #353");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #354");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcpy(start_while, a_string);
    strcat(a_string, "F");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #355");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R4,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R4)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #356");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #357");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #358");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #359");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #360");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(start_while, a_string);
    strcat(a_string, "F");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #361");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
    strcat(a_string, wk_strg);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x92);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    x96 = 0;
    snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
    strcat(a_string, wk_strg);
    strcat(a_string, "(R4)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #362");
      trace_rec_3();
    }

  convert = 1;
  return;
}



/*  strcpy(gw_variable[gv_ct].gv_name, gw_variable[I].gv_name); */
void c2_str_11()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_string.c c2_str_11");
    trace_rec_1(); 
  }

   int s;
   int I;
   int v;
   int x2;
   int x3;
   int x20;
   int x21;
   int x22;
   int x92;
   int x96;
   int x97;
   int pi;
   int pi2;
   int ret;
   int ret1;
   int fd2_type = 0;
   int fd5_type = 0;
 
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];

  x20 = 0;
  x21 = 0;
  x22 = 0;
  s = strlen(p_string);

  for(I=0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '(')
    {
      x20++;
    }
    if(ch == ')')
    {
      x20++;
    }
    if(ch == '[')
    {
      x21++;
    }
    if(ch == ']')
    {
      x21++;
    }
    if(ch == '.')
    {
      x22++;
    }
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
  while (ch != '[') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  x2 = 0;
  pi2 = 0;
  fd2_type = 0;
  pi++;
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
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  pi2 = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
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

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != '[') 
  {
    if(ch != ' ')
    {
      if(ch != ',')
      {
        field4[pi2] = ch;
        pi2++;
      }
    }
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';

  x2 = 0;
  pi2 = 0;
  fd5_type = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if (x2 == 0) 
    {
      if ((isdigit(ch)) && (x2 == 0)) 
      {
        fd5_type = 2;
        x2 = 1;
      }

      if ((isalpha(ch)) && (x2 == 0)) 
      {
        fd5_type = 1;
        x2 = 1;
      }
    }
    field5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field5[pi2] = '\0';

  pi2 = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if(ch != '.')
    {
      field6[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field6[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(field1, w_struc[I].st_name);
    if(ret == 0)
    {
       x3 = 1;
       strcpy(field1a, w_struc[I].st_cname);
  /*     x92 = w_struc[I].st_field_lgth;
       x96 = w_struc[I].st_disp; */
       break;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_11 strcpy-080 field1 Not Found = %s\n", field1);
    printf("c2z_strcpy.c c2_str_11 field3 Not Found = %s\n",field3);
    printf("c2z_strcpy.c c2_str_11 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(field1, w_struc[I].st_name);
    ret1 = strcmp(field3, w_struc[I].st_field_name);
    if((ret == 0) && (ret1 == 0))
    {
       x3 = 1;
       x92 = w_struc[I].st_field_lgth;
       x96 = w_struc[I].st_disp; 
       break;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_11 strcpy-081 field1 Not Found = %s\n", field1);
    printf("c2z_strcpy.c c2_str_11 field3 Not Found = %s\n",field3);
    printf("c2z_strcpy.c c2_str_11 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field2, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[v].lv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[v].gv_cname);
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_11 strcpy-082 field2 Not Found = %s\n",field2);
    printf("c2z_strcpy.c c2_str_11 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field4, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field4a, lw_variable[v].lv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field4, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field4a, gw_variable[v].gv_cname);
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_11 strcpy-083 field4 Not Found = %s\n",field4);
    printf("c2z_strcpy.c c2_str_11 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(field4, w_struc[I].st_name);
    ret1 = strcmp(field6, w_struc[I].st_field_name);
    if((ret == 0) && (ret1 == 0))
    {
       x3 = 1;
     /*  x93 = w_struc[I].st_field_lgth; */
       x97 = w_struc[I].st_disp; 
       break;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_strcpy.c c2_str_11 strcpy-084 field4 Not Found = %s\n", field4);
    printf("c2z_strcpy.c c2_str_11 field6 Not Found = %s\n",field6);
    printf("c2z_strcpy.c c2_str_11 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  if(fd5_type == 1)
  {
    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field5, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field5a, lw_variable[v].lv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field5, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field5a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_11 strcpy-085 field5 Not Found = %s\n",field5);
      printf("c2z_strcpy.c c2_str_11 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #363");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #364");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #365");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, field1a);
  strcat(a_string, "T");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #366");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #367");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #368");
    trace_rec_3();
  }
  work_use_ct[49]++;

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
      strcpy(trace_1, "c2z_strcpy.c #369");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #370");
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
    strcpy(trace_1, "c2z_strcpy.c #371");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #372");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #373");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #374");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #375");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, field1a);
  strcat(a_string, "L");
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #376");
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
    strcpy(trace_1, "c2z_strcpy.c #377");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #378");
    trace_rec_3();
  }

/* now to find the 2nd gw_variable */
  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #379");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #380");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #381");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R5,");
  strcat(a_string, field4a);
  strcat(a_string, "T");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field4);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #382");
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
    strcpy(trace_1, "c2z_strcpy.c #383");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #384");
    trace_rec_3();
  }
  work_use_ct[49]++;

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #385");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #386");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #387");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #388");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #389");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #390");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #391");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R5,");
  strcat(a_string, field1a);
  strcat(a_string, "L");
  strcat(a_string, "(R0,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #392");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "G");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #393");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "H");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #394");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
  strcat(a_string, wk_strg);
  strcat(a_string, "(");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x92);
  strcat(a_string, wk_strg);
  strcat(a_string, ",R6),");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x97);
  strcat(a_string, wk_strg);
  strcat(a_string, "(R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #395");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #396");
    trace_rec_3();
  }

  convert = 1;
  return;

}



void c2_strcpy_pass2(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_strcpy_pass2 START");
    trace_rec_1();
  }

  char ch;
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field5[VAR_LGTH];

  int pi;
  int pi2;
  int str1 = 0;
  int str2 = 0;
  int str3 = 0;
  int str4 = 0;
  int str12 = 0;
  int str13 = 0;
  int str14 = 0;
  int ret;
  int I = 0;
  int s = 0;
  int z = 0;
  int y = 0;
  int x2 = 0;
  int fd1_type = 0;
  int x3;
  int v;
  int ret1;
  int fd4_type = 0;

  s = strlen(p_string);
  str1 = 0; 				/* x */
  str2 = 0; 				/* x2 */
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '\"') 
    {
      str1++;
      str2 = I;
    }
  }

  if (str1 != 0) 
  {
    if ((str1 == 2) || (str1 == 4)) 
    {
    } 
    else 
    {
      printf("\nc2z_strcpy.c c2_strcpy_pass2 strcpy-050 UNBALANCED QUOTES\n");
      printf("c2z_strcpy.c c2_strcpy_pass2 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  s = strlen(p_string);
  pi = 0;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    pi++;
    ch = p_string[pi];
  }

  s = strlen(p_string);
  str1 = 0; 			/* comma */
  str2 = 0; 			/* [     */	
  str3 = 0; 			/* ]	  */
  str4 = 0; 			/* 1st " */

  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == ',') 
    {
      str1 = I;
      break;
    }
    if (ch == '[')
    {
      str2 = I;
    }

    if (ch == ']')
    {
      str3 = I;
    }

    if ((ch == '"') && (str4 == 0))
    {
      str4 = I;
    }
  }

  for (I = str1; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[')
    {
      str12 = I;
    }
    if (ch == ']')
    {
      str13 = I;
    }
    if ((ch == '"') && (str4 == 0))
    {
      str14 = I;
    }
  }

  convert = 0;

  if ((str1 < str14) && (convert == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_strcpy_pass2 subroutine #1");
      trace_rec_1();
    }

    c2_pass2_strcpy_2(str1, str14);
    convert = 1;
  }

  if ((str2 == 0) && (str3 == 0) && (str12 > 0) && (str13 > 0) && (convert == 0)) 			/* strcpy(p_string, arrary1{line_ndx])	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_strcpy_pass2 subroutine #2");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if (ch != ' ') 
      {
        field3[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
 
/*     
   pi++;
      ch = p_string[pi];
    }
  
    pi++;
    ch = p_string[pi];
    if (ch == ')') 
    {
      goto skip_1;
    }

    pi2 = 0;
    while (ch != ')') 
    {
*/
      if (ch != '.') 
      {
        field5[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';
/*
  skip_1:
*/
    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field2, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field2, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_strcpy_pass2 strcpy-051 field2 Not Found = %s\n",field2);
      printf("c2z_strcpy.c c2_strcpy_pass2 rct = %d sv_func = %s p_string = %s",rct, sv_func, p_string);
      erct++;
      convert = 1;
      return;
    }


    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field3, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field3, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < m_struc_ct; I++) 
      {
        ret = strcmp(field3, w_struc[I].st_wname);
        ret1 = strcmp(field5, w_struc[I].st_field_name);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field3a, w_struc[I].st_field_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_pass2_strcpy_2 strcpy-052 field3 Not Found = %s\n",field3);
      printf("c2z_strcpy.c c2_pass2_strcpy_2 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd4_type == 2) 
    {
/*
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';

      if (math_lit_ct == 0) 
      {
        size = 1;
        w_mathlit = malloc(size * sizeof(struct math_lit));
      } 
      else 
      {
        size = math_lit_ct + 1;
        w_mathlit = realloc(w_mathlit, size * sizeof(struct math_lit));
      }

      w_mathlit[math_lit_ct].lit_rct = rct;
      w_mathlit[math_lit_ct].lit_use_rct = rct;
      strcpy(w_mathlit[math_lit_ct].lit_name, null_field);
      strcpy(w_mathlit[math_lit_ct].lit_cname, c_wkname);
      strcpy(w_mathlit[math_lit_ct].lit_value, field4);
      strcpy(w_mathlit[math_lit_ct].lit_use_cname, c_wkname);
      w_mathlit[math_lit_ct].lit_uct = 1;
      w_mathlit[math_lit_ct].lit_dec = 0;
      w_mathlit[math_lit_ct].lit_type = 1;
      math_lit_ct++;
*/
    }
    convert = 1;
    return;
  }

  if ((str1 > str2) && (str2 > 0) && (str3 > 0) && (str12 == 0) && (str13 == 0) && (convert == 0)) 	/* strcpy(array1[ln], p_string);	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_strcpy_pass2 subroutine #3");
      trace_rec_1();
    }

    z = 0;
    y = 0;
    x2 = 0;
    pi = 0;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if (z == 1) 
      {
        if (x2 == 0) 
        {
          if ((isdigit(ch)) && (x2 == 0)) 
          {
            fd1_type = 2;
            x2 = 1;
          }

          if ((isalpha(ch)) && (x2 == 0)) 
          {
            fd1_type = 1;
            x2 = 1;
          }
        }
        y++;
      }
      if (ch == '[') 
      {
        z = 1;
      }
      pi++;
      ch = p_string[pi];
    }

    if (fd1_type == 2) 
    {
/*
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(field1a, c_wkname);

      if (math_lit_ct == 0) 
      {
        size = 1;
        w_mathlit = malloc(size * sizeof(struct math_lit));
      } 
      else 
      {
        size = math_lit_ct + 1;
        w_mathlit = realloc(w_mathlit, size * sizeof(struct math_lit));
      }

      w_mathlit[math_lit_ct].lit_rct = rct;
      w_mathlit[math_lit_ct].lit_use_rct = rct;
      strcpy(w_mathlit[math_lit_ct].lit_name, null_field);
      strcpy(w_mathlit[math_lit_ct].lit_cname, field1a);
      strcpy(w_mathlit[math_lit_ct].lit_value, field1);
      strcpy(w_mathlit[math_lit_ct].lit_use_cname, field1a);
      w_mathlit[math_lit_ct].lit_uct = 1;
      w_mathlit[math_lit_ct].lit_dec = 0;
      w_mathlit[math_lit_ct].lit_type = 1;
      math_lit_ct++;
*/
    }
    /* strcpy(array1[ln], "xxxxxxxxxx"); 	*/
    convert = 1;
  }

  if ((str2 > 0) && (str3 > 0) && (str12 > 0) && (str13 > 0) && (convert == 0)) 	/* strcpy array1[ln], array2[xy]);	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_strcpy_pass2 subroutine #4");
      trace_rec_1();
    }

    convert = 1;
    return;
  }
}

void c2_pass2_strcpy_2(int str1, int str4) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_pass2_strcpy_2 START");
    trace_rec_1();
  }

  int v = 0;
  int ret = 0;
  int ret1 = 0;
  int pi;
  int pi2;
  int x2 = 0;
  int I;
  int x10 = 0;
  int x11 = 0;

  char ch;
  char *p, *p1, *p2, *p3, *p4;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield4[VAR_LGTH];

  tfield1a[0] = '\0';

  int str5 = 0;
  int size = 0;
  int x3 = 0;
  int s = 0;

  p = strstr(p_string, "[");
  p1 = strstr(p_string, "]");
  p2 = strstr(p_string, ".");
  p3 = strstr(p_string, ";");
  p4 = strstr(p_string, "\"");

  x10 = p3 - p_string;
  x11 = p - p_string;
  if (x11 < 0) 
  {
  }
  /* x12 = p1 - p_string; */

  /* printf("c2z_strcpy.c c2_pass2_strcpy_2 str1 = %d str4 = %d x10 = %d x11 =  %d\n",str1,str4,x10,x11); */

  if ((str1 < str4) && (x10 < x11)) 
  {
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
    while (ch != ',') 
    {
      if (ch != ' ') 
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    str5 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          strcpy(tfield1a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
          str5 = 1;
        }
      }
    }

    if (str5 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            strcpy(tfield1a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
            str5 = 1;
          }
        }
      }
    }

    if (str5 == 0) 
    {
      printf("\nc2z_strcpy.c c2_pass2_strcpy_2 strcpy-053 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_strcpy.c c2_pass2_strcpy_2 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    if (ch == '"') 
    {
      pi2 = 0;
      pi++;
      ch = p_string[pi];

      while (ch != '"') 
      {
        tfield2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
        if (ch == '\n')
        {
          break;
        }
        if (ch == '\t')
        {
          break;
        }
      }
    }
    tfield2[pi2] = '\0';

    x3 = strlen(tfield2);

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield1a, c_wkname);

    if (char_ct == 0) 
    {
      size = 1;
      w_charlit = malloc(size * sizeof(struct charlit));
    } 
    else 
    {
      size = char_ct + 1;
      w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
    }

    w_charlit[char_ct].clit_rct = rct;
    strcpy(w_charlit[char_ct].clit_cname, tfield1a);
    strcpy(w_charlit[char_ct].clit_value, tfield2);
    w_charlit[char_ct].clit_lgth = x3;
    w_charlit[char_ct].clit_type = 3;
    char_ct++;

    x2 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x2 = 1;
          lw_variable[I].lv_current_lgth = x3;
        }
      }
    }

    if (x2 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x2 = 1;
            gw_variable[I].gv_current_lgth = x3;
          }
        }
      }
    }

    if (x2 == 0) 
    {
      printf("\nc2z_strcpy.c c2_pass2_strcpy_2 strcpy-054 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_strcpy.c c2_pass2_strcpy_2 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
    convert = 1;
  }

  if ((p) && (p1) && (p2) && (x11 < x10)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_pass2_strcpy subroutine #300");
      trace_rec_1();
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

    pi++;
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
      if (ch != '\"') 
      {
        if (ch != ' ') 
        {
          tfield4[pi2] = ch;
          pi2++;
        }
      }
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

    if (char_ct == 0) 
    {
      size = 1;
      w_charlit = malloc(size * sizeof(struct charlit));
    } 
    else 
    {
      size = char_ct + 1;
      w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
    }

    w_charlit[char_ct].clit_rct = rct;
    strcpy(w_charlit[char_ct].clit_cname, c_wkname);
    strcpy(w_charlit[char_ct].clit_value, tfield4);
    s = strlen(tfield4);
    w_charlit[char_ct].clit_type = 3;
    w_charlit[char_ct].clit_lgth = s;
    w_charlit[char_ct].clit_uct = 1;
    char_ct++;

    convert = 1;
  }

  if (p4) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_pass2_strcpy_2 subroutine 200");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
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
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';

    if (char_ct == 0) 
    {
      size = 1;
      w_charlit = malloc(size * sizeof(struct charlit));
    } 
    else 
    {
      size = char_ct + 1;
      w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
    }

    w_charlit[char_ct].clit_rct = rct;
    strcpy(w_charlit[char_ct].clit_cname, c_wkname);
    strcpy(w_charlit[char_ct].clit_value, tfield1);
    w_charlit[char_ct].clit_type = 3;
    w_charlit[char_ct].clit_lgth = pi2;
    w_charlit[char_ct].clit_uct = 1;
 }

  char_ct++;
  convert = 1;
  return;
}


void c2_str_12()
{
   if (traceflg == 1) 
   {
     strcpy(trace_1, "c2z_strcpy.c c2_str_12 START");
     trace_rec_1();
   }

    int pi;
    int pi2;
    int x3;
    int x2;
    int I;
    int ret;
    int ret1;
    int fd2_type;
    int fd3_type;
    int fd4_type;

   char ch;
   char *p;
   char field1[VAR_LGTH];
   char field1a[VAR_LGTH];
   char field2[VAR_LGTH];
   char field2a[VAR_LGTH];
   char field3[VAR_LGTH];
   char field3a[VAR_LGTH];
   char field4[VAR_LGTH];
   char field4a[VAR_LGTH];

   char ar_field5[VAR_LGTH];
   char ar_field6[VAR_LGTH];
   char ar_field7[VAR_LGTH];
   char ar_field8[VAR_LGTH];
   char ar_field9[VAR_LGTH];
   char ar_field10[VAR_LGTH];
   char ar_field11[VAR_LGTH];

   pi = 0;
   ch = p_string[pi];
   while(ch != '(')
   {
     pi++;
     ch = p_string[pi];
   }

   pi2 = 0;
   x2 = 0;
   pi++;
   ch = p_string[pi];
   while(ch != '[')
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
   while(ch != ']')
   {
      if (x2 == 0) 
      {
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

   x2 = 0;
   fd4_type = 0;
   pi++;
   pi++;
   ch = p_string[pi];
   while(ch == ' ')
   {
     pi++;
     ch = p_string[pi];
   }

   fd4_type = 0;
   p = strstr(p_string, "\"");
   if(p)
   {
     fd4_type = 3;
   }
   
   if(fd4_type != 3)
   {
     x2 = 0;
     pi2 = 0;
     while(ch != ')')
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
       pi++;
       ch = p_string[pi];
     }
     field4[pi2] = '\0';
   }

/*
printf("\nc2z_strcpy.c str_12 rct = %d p_string = %s",rct,p_string);
printf("c2z_strcpy.c field1 = %s\n",field1);
printf("c2z_strcpy.c field2 = %s fd2_type = %d\n",field2,fd2_type);
printf("c2z_strcpy.c field3 = %s fd3_type = %d\n",field3,fd3_type);
printf("c2z_strcpy.c field4 = %s fd4_type = %d\n",field4,fd4_type);
*/

   x2 = 0;
   if (lv_ct > 0) 
   {
     for (I = 0; I < lv_ct; I++) 
     {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x2 = 1;
          strcpy(field1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          break;
        }
     }
   }

   if (x2 == 0) 
   {
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
           break;
         }
       }
     }
   }

   if (x2 == 0) 
   {
     printf("\nc2z_strcpy.c c2_str_12 E-001 field1 Not Found = %s\n",field1);
     printf("c2z_strcpy.c c2_str_12 rct = %d p_string = %s\n",rct,p_string);
     erct++;
     convert = 1;
     return;
   }

   if(fd2_type == 2)
   {
     x2 = 0;
     if (lv_ct > 0) 
     {
       for (I = 0; I < lv_ct; I++) 
       {
          ret = strcmp(field2, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x2 = 1;
            strcpy(field2a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
       }
     }

     if (x2 == 0) 
     {
       if (gv_ct > 0) 
       {
         for (I = 0; I < gv_ct; I++) 
         {
           ret = strcmp(field2, gw_variable[I].gv_name);
           if (ret == 0) 
           {
             x2 = 1;
             strcpy(field2a, gw_variable[I].gv_cname);
             gw_variable[I].gv_use_ct++;
           }
         }
       }
     }

     if (x2 == 0) 
     {
       printf("\nc2z_strcpy.c c2_str_12 E-002 field2 Not Found = %s\n",field2);
       printf("c2z_strcpy.c c2_str_12 rct = %d p_string = %s\n",rct,p_string);
       erct++;
       convert = 1;
       return;
     }
   }

   if(fd3_type == 2)
   {
     x2 = 0;
     if (lv_ct > 0) 
     {
       for (I = 0; I < lv_ct; I++) 
       {
          ret = strcmp(field3, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x2 = 1;
            strcpy(field3a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
       }
     }

     if (x2 == 0) 
     {
       if (gv_ct > 0) 
       {
         for (I = 0; I < gv_ct; I++) 
         {
           ret = strcmp(field3, gw_variable[I].gv_name);
           if (ret == 0) 
           {
             x2 = 1;
             strcpy(field3a, gw_variable[I].gv_cname);
             gw_variable[I].gv_use_ct++;
           }
         }
       }
     }

     if (x2 == 0) 
     {
       printf("\nc2z_strcpy.c c2_str_12 E-003 field3 Not Found = %s\n",field3);
       printf("c2z_strcpy.c c2_str_12 rct = %d p_string = %s\n",rct,p_string);
       erct++;
       convert = 1;
       return;
     }
   }

   if(fd4_type != 3)
   {
     x2 = 0;
     if (lv_ct > 0) 
     {
       for (I = 0; I < lv_ct; I++) 
       {
          ret = strcmp(field4, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x2 = 1;
            strcpy(field4a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
            x3 = lw_variable[I].lv_current_lgth;
            break;
          }
       }
     }

     if (x2 == 0) 
     {
       if (gv_ct > 0) 
       {
         for (I = 0; I < gv_ct; I++) 
         {
           ret = strcmp(field4, gw_variable[I].gv_name);
           if (ret == 0) 
           {
             x2 = 1;
             strcpy(field4a, gw_variable[I].gv_cname);
             x3 = gw_variable[I].gv_current_lgth;
             break;
           }
         }
       }
     }

     if (x2 == 0) 
     {
       printf("\nc2z_strcpy.c c2_str_12 E-004 field4 Not Found = %s\n",field4);
       printf("c2z_strcpy.c c2_str_12 rct = %d p_string = %s\n",rct,p_string);
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
      strcpy(trace_1, "c2z_strcpy.c #800");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #801");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #802");
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
        strcpy(trace_1, "c2z_strcpy.c #803");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #804");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #805");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #806");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #807");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #808");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #809");
        trace_rec_3();
      }
      work_use_ct[50]++;


/*
3  66     c2z_strcpy.c #813                        LAEY  R5,26                                                    0001551
3  66     c2z_strcpy.c #814                        LARL  R7,C370U                                                 0001552
3  66     c2z_strcpy.c #815                        CVD   R5,0(R7)                                                 0001553
3  66     c2z_strcpy.c #816                        LARL  R8,C370NWK2                                              0001554
3  66     c2z_strcpy.c #817                        LARL  R7,C370U                                                 0001555
3  66     c2z_strcpy.c #818                        ZAP   0(6,R8),0(8,R7)                                          0001556
*/
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
        strcpy(trace_1, "c2z_strcpy.c #810");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #811");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #812");
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
      strcpy(trace_1, "c2z_strcpy.c #813");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #814");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #815");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #816");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #817");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #818");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #819");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #820");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #821");
        trace_rec_3();
      }
      work_use_ct[50]++;


/*
3  66     c2z_strcpy.c #813                        LAEY  R5,26                                                    0001551
3  66     c2z_strcpy.c #814                        LARL  R7,C370U                                                 0001552
3  66     c2z_strcpy.c #815                        CVD   R5,0(R7)                                                 0001553
3  66     c2z_strcpy.c #816                        LARL  R8,C370NWK2                                              0001554
3  66     c2z_strcpy.c #817                        LARL  R7,C370U                                                 0001555
3  66     c2z_strcpy.c #818                        ZAP   0(6,R8),0(8,R7)                                          0001556
*/
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
        strcpy(trace_1, "c2z_strcpy.c #822");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #823");
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
      strcpy(trace_1, "c2z_strcpy.c #824");
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
      strcpy(trace_1, "c2z_strcpy.c #825");
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
        strcpy(trace_1, "c2z_print.c #xxxx");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #xxxx");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #xxxx");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #xxxx");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #xxxx");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #xxxx");
        trace_rec_3();
      }

/*
3  163    c2z_print.c #2813                        LAEY  R5,26                                                    0001261
3  163    c2z_print.c #2814                        LARL  R7,C370U                                                 0001262
3  163    c2z_print.c #2815                        CVD   R5,0(R7)                                                 0001263
3  163    c2z_print.c #2816                        LARL  R8,C370NWK2                                              0001264
3  163    c2z_print.c #2817                        LARL  R7,C370U                                                 0001265
3  163    c2z_print.c #2818                        ZAP   0(6,R8),0(8,R7)                                          0001266
*/
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
        strcpy(trace_1, "c2z_strcpy.c #826");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LAEY  R5,26");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #827");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #828");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #829");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #830");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #831");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #832");
      trace_rec_3();
    }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #833");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #834");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #835");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #836");
      trace_rec_3();
    }
    work_use_ct[49]++;

   if(fd2_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #837");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #838");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #839");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #840");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #841");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #842");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #843");
        trace_rec_3();
      }
      work_use_ct[50]++;


/*
3  66     c2z_strcpy.c #813                        LAEY  R5,26                                                    0001551
3  66     c2z_strcpy.c #814                        LARL  R7,C370U                                                 0001552
3  66     c2z_strcpy.c #815                        CVD   R5,0(R7)                                                 0001553
3  66     c2z_strcpy.c #816                        LARL  R8,C370NWK2                                              0001554
3  66     c2z_strcpy.c #817                        LARL  R7,C370U                                                 0001555
3  66     c2z_strcpy.c #818                        ZAP   0(6,R8),0(8,R7)                                          0001556
*/
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
        strcpy(trace_1, "c2z_strcpy.c #844");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #845");
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
      strcpy(trace_1, "c2z_strcpy.c #846");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #847");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #848");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #849");
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
      strcpy(trace_1, "c2z_strcpy.c #850");
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
      strcpy(trace_1, "c2z_strcpy.c #851");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #852");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #853");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #854");
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
      strcpy(trace_1, "c2z_strcpy.c #855");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #856");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #857");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #858");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #859");
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
    strcpy(trace_1, "c2z_strcpy.c #860");
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
    strcpy(trace_1, "c2z_strcpy.c #861");
    trace_rec_3();
  }

  if(fd4_type != 3)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #862");
      trace_rec_3();
    }
  
    strcpy(a_string, "         MVC   ");
    strcat(a_string, "0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    strcat(a_string, "0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #863");
      trace_rec_3();
    }
  }

  if(fd4_type == 3)
  {
    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(field4a, w_charlit[I].clit_cname);
        x2 = w_charlit[I].clit_lgth;
        break;
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field4a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #864");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, "0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    strcat(a_string, "0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #865");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #865");
      trace_rec_3();
    }


    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
    strcat(a_string, wk_strg);
    strcat(a_string, "(1");
    strcat(a_string, ",R6),");
    strcat(a_string, "0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #865");
      trace_rec_3();
    }

  }

   convert = 1;
   return;
}


void c2_str_13()
{
   if (traceflg == 1) 
   {
     strcpy(trace_1, "c2z_strcpy.c c2_str_13 START");
     trace_rec_1();
   }

    int pi;
    int pi2;
    int x3;
    int x2;
    int I;
    int ret;
    int ret1;
    int x102;
    int fd2_type;
    int fd3_type;
    int fd4_type;

   char ch;
   char *p;
   char field1[VAR_LGTH];
   char field1a[VAR_LGTH];
   char field2[VAR_LGTH];
   char field2a[VAR_LGTH];
   char field3[VAR_LGTH];
   char field3a[VAR_LGTH];
   char field4[VAR_LGTH];
   char field4a[VAR_LGTH];

   char ar_field5[VAR_LGTH];
   char ar_field6[VAR_LGTH];
   char ar_field7[VAR_LGTH];
   char ar_field8[VAR_LGTH];
   char ar_field9[VAR_LGTH];
   char ar_field10[VAR_LGTH];
   char ar_field11[VAR_LGTH];

   pi = 0;
   ch = p_string[pi];
   while(ch != '(')
   {
     pi++;
     ch = p_string[pi];
   }

   pi2 = 0;
   x2 = 0;
   pi++;
   ch = p_string[pi];
   while(ch != ',')
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
   while(ch != '[')
   {
      if(ch != ' ')
      {
        if (x2 == 0) 
        {
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
      if(ch != ' ')
      {
        if (x2 == 0) 
        {
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
     }
     pi++;
     ch = p_string[pi];
   }
   field3[pi2] = '\0';

   x2 = 0;
   fd4_type = 0;
   pi++;
   pi++;
   ch = p_string[pi];
   while(ch == ' ')
   {
     pi++;
     ch = p_string[pi];
   }

   fd4_type = 0;
   p = strstr(p_string, "\"");
   if(p)
   {
     fd4_type = 3;
   }
   
   if(fd4_type != 3)
   {
     x2 = 0;
     pi2 = 0;
     while(ch != ']')
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
       pi++;
       ch = p_string[pi];
     }
     field4[pi2] = '\0';
   }

/*
printf("\nc2z_strcpy.c str_13 rct = %d p_string = %s",rct,p_string);
printf("c2z_strcpy.c #13 field1 = %s \n",field1);
printf("c2z_strcpy.c #13 field2 = %s fd2_type = %d\n",field2,fd2_type);
printf("c2z_strcpy.c #13 field3 = %s fd3_type = %d\n",field3,fd3_type);
printf("c2z_strcpy.c #13 field4 = %s fd4_type = %d\n",field4,fd4_type);
*/

   x2 = 0;
   if (lv_ct > 0) 
   {
     for (I = 0; I < lv_ct; I++) 
     {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x2 = 1;
          strcpy(field1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          break;
        }
     }
   }

   if (x2 == 0) 
   {
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
           break;
         }
       }
     }
   }

   if (x2 == 0) 
   {
     printf("\nc2z_strcpy.c c2_str_12 E-001 field1 Not Found = %s\n",field1);
     printf("c2z_strcpy.c c2_str_12 rct = %d p_string = %s\n",rct,p_string);
     erct++;
     convert = 1;
     return;
   }

   if(fd2_type == 2)
   {
     if (gv_ct > 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(field2, gw_variable[I].gv_name);
         if (ret == 0) 
         {
           x2 = 1;
           strcpy(field2a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
           strcpy(ar_field5, gw_variable[I].gv_dsect);
           strcpy(ar_field6, gw_variable[I].gv_label);
           strcpy(ar_field7, gw_variable[I].gv_table);
           strcpy(ar_field8, gw_variable[I].gv_aname);
           strcpy(ar_field9, gw_variable[I].gv_sv_reg);
           strcpy(ar_field10, gw_variable[I].gv_wk_reg);
           strcpy(ar_field11, gw_variable[I].gv_wk_strg);
           x102 = gw_variable[I].gv_column;
           break;
         }
       }
     }

     if (x2 == 0) 
     {
       printf("\nc2z_strcpy.c c2_str_13 E-002 field2 Not Found = %s\n",field2);
       printf("c2z_strcpy.c c2_str_13 rct = %d p_string = %s\n",rct,p_string);
       erct++;
       convert = 1;
       return;
     }
   }

   if(fd3_type == 2)
   {
     x2 = 0;
     if (lv_ct > 0) 
     {
       for (I = 0; I < lv_ct; I++) 
       {
          ret = strcmp(field3, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x2 = 1;
            strcpy(field3a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
       }
     }

     if (x2 == 0) 
     {
       if (gv_ct > 0) 
       {
         for (I = 0; I < gv_ct; I++) 
         {
           ret = strcmp(field3, gw_variable[I].gv_name);
           if (ret == 0) 
           {
             x2 = 1;
             strcpy(field3a, gw_variable[I].gv_cname);
             gw_variable[I].gv_use_ct++;
           }
         }
       }
     }

     if (x2 == 0) 
     {
       printf("\nc2z_strcpy.c c2_str_12 E-003 field3 Not Found = %s\n",field3);
       printf("c2z_strcpy.c c2_str_12 rct = %d p_string = %s\n",rct,p_string);
       erct++;
       convert = 1;
       return;
     }
   }

   if(fd4_type != 3)
   {
     x2 = 0;
     if (lv_ct > 0) 
     {
       for (I = 0; I < lv_ct; I++) 
       {
          ret = strcmp(field4, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x2 = 1;
            strcpy(field4a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
            x3 = lw_variable[I].lv_current_lgth;
            break;
          }
       }
     }

     if (x2 == 0) 
     {
       if (gv_ct > 0) 
       {
         for (I = 0; I < gv_ct; I++) 
         {
           ret = strcmp(field4, gw_variable[I].gv_name);
           if (ret == 0) 
           {
             x2 = 1;
             strcpy(field4a, gw_variable[I].gv_cname);
             x3 = gw_variable[I].gv_current_lgth;
             break;
           }
         }
       }
     }

     if (x2 == 0) 
     {
       printf("\nc2z_strcpy.c c2_str_12 E-004 field4 Not Found = %s\n",field4);
       printf("c2z_strcpy.c c2_str_12 rct = %d p_string = %s\n",rct,p_string);
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
      strcpy(trace_1, "c2z_strcpy.c #870");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #871");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #872");
      trace_rec_3();
    }

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
        strcpy(trace_1, "c2z_strcpy.c #873");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #874");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #875");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #876");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #877");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #878");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #879");
        trace_rec_3();
      }
      work_use_ct[50]++;
    }

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #880");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #881");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #882");
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
      strcpy(trace_1, "c2z_strcpy.c #883");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #884");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #885");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #886");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #887");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #888");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #889");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #890");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #891");
        trace_rec_3();
      }
      work_use_ct[50]++;
    }

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field4a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field4);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #892");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #893");
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
      strcpy(trace_1, "c2z_strcpy.c #894");
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
      strcpy(trace_1, "c2z_strcpy.c #895");
      trace_rec_3();
    }
  
    if(fd3_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #896");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #897");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #898");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #899");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #900");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_print.c #901");
        trace_rec_3();
      }
    }


    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #902");
        trace_rec_3();
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x102);
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #903");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #904");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #905");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NCVT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #906");
      trace_rec_3();
    }
    work_use_ct[104]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #907");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #908");
      trace_rec_3();
    }

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #909");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NCVT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #910");
      trace_rec_3();
    }
    work_use_ct[104]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #911");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #912");
      trace_rec_3();
    }
    work_use_ct[49]++;

   if(fd2_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #913");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #914");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #915");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #916");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #917");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #918");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #919");
        trace_rec_3();
      }
      work_use_ct[50]++;
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
        strcpy(trace_1, "c2z_strcpy.c #920");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #921");
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
      strcpy(trace_1, "c2z_strcpy.c #922");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #923");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #924");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #925");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #926");
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
      strcpy(trace_1, "c2z_strcpy.c #927");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #928");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #929");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #923");
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
      strcpy(trace_1, "c2z_strcpy.c #924");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #925");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #926");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #927");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c #928");
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
    strcpy(trace_1, "c2z_strcpy.c #929");
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
    strcpy(trace_1, "c2z_strcpy.c #930");
    trace_rec_3();
  }

  if(fd4_type != 3)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #931");
      trace_rec_3();
    }
  
    strcpy(a_string, "         MVC   ");
    strcat(a_string, "0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    strcat(a_string, "0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #932");
      trace_rec_3();
    }
  }

  if(fd4_type == 3)
  {
    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(field4a, w_charlit[I].clit_cname);
        x2 = w_charlit[I].clit_lgth;
        break;
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
      strcpy(trace_1, "c2z_strcpy.c #931");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R6),(R9)");
/*    strcat(a_string, "0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    strcat(a_string, "0(R9)");
*/
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #934");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #935");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
    strcat(a_string, wk_strg);
    strcat(a_string, "(1");
    strcat(a_string, ",R6),");
    strcat(a_string, "0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #936");
      trace_rec_3();
    }
  }

   convert = 1;
   return;
}



void c2_str_14()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c str_14 START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field1b[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  
   int pi;
   int pi2;
   int ret;
   int x2;
   int x3;
   int x4;
   int I;
   int str1;
   int str3;
   int fd2_type = 0;
   int fd3_type = 0;

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
    while (ch != '[') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x2 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      x2 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x2 == 0)) 
      {
        x3 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        break;
      }
    }

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
          strcpy(field1b, gw_variable[I].gv_type);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_1 strcpy-008 field1a Not Found %s\n", field1);
      printf("c2z_strcpy.c c2_str_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    str3 = 0;
    str3 = strcmp(field1b, "A");
    if (str3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          str1 = strcmp(field1, gw_variable[I].gv_name);
          if (str1 == 0) 
          {
            strcpy(field5, gw_variable[I].gv_dsect);
            strcpy(field6, gw_variable[I].gv_label);
            strcpy(field7, gw_variable[I].gv_table);
            strcpy(field8, gw_variable[I].gv_aname);
            strcpy(field9, gw_variable[I].gv_sv_reg);
            strcpy(field10, gw_variable[I].gv_wk_reg);
            x2 = gw_variable[I].gv_lgth;
          }
        }
      }
    }

    pi++;
    pi2 = 0;
    x2 = 0;
    fd2_type = 0;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if (x2 == 0) 
      {
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

    if(fd2_type == 2)
    {
      x2 = 0;
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        x2 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (x2 == 0)) 
        {
          x3 = 1;
          strcpy(field2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          break;
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
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_14 strcpy-009 field2a Not Found %s\n", field2);
        printf("c2z_strcpy.c c2_str_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    pi++;
    pi++;
    pi2 = 0;
    x2 = 0;
    fd3_type = 0;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if(ch != ' ')
      { 
        if (x2 == 0) 
        {
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
          if(fd3_type == 0)
          {
            x2 = 1;
          }
        }
        field3[pi2] = ch;
        pi2++;
      } 
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    if(fd3_type == 0)
    {
      for (I = 0; I < char_ct; I++) 
      {
        if (w_charlit[I].clit_rct == rct) 
        {
          strcpy(field3a, w_charlit[I].clit_cname);
          x4 = w_charlit[I].clit_lgth;
        }
      }
    }

    if(fd3_type == 1)
    {
      printf("c2z_strcpy.c str_14 fd1_type == 1 NOT CODED\n");
      printf("c2z_strcpy.c str_14 rct = %d p_string = %s\n",rct,p_string);
    }

    if(fd3_type == 2)
    {
      x2 = 0;
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        x2 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (x2 == 0)) 
        {
          x3 = 1;
          strcpy(field3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x4 = lw_variable[I].lv_current_lgth;
          break;
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
            x4 = gw_variable[I].gv_current_lgth;
            gw_variable[I].gv_use_ct++;
            break;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_strcpy.c c2_str_14 strcpy-009 field3 Not Found %s\n", field3);
        printf("c2z_strcpy.c c2_str_14 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }


    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #42");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #43");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #44");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #45");
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
        strcpy(trace_1, "c2z_strcpy.c #48a");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #48b");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #48c");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #48d");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #48e");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #48f");
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
      strcpy(trace_1, "c2z_strcpy.c #46");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #47");
      trace_rec_3();
    }

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #48g");
        trace_rec_3();
      }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #48h");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #49");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #50");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #51");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #52");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #53");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #54");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #55");
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
      strcpy(trace_1, "c2z_strcpy.c #56");
      trace_rec_3();
    }

    if(fd3_type == 0)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field3a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #57");
        trace_rec_3();
      }
    }

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field3a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #57");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         MVC   0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #58");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #59");
      trace_rec_3();
    }
    work_use_ct[74]++;

    snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
    strcpy(a_string, "         MVC   ");
    strcat(a_string, wk_strg);
    strcat(a_string, "(1,R6),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #60");
      trace_rec_3();
    }

    convert = 1;
}

