/* ***************************************************
*  c2z : c2z_strcpy.c :                              *
*                                                    *
*  next error - strcpy-062                           *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out STRCPY                                  *
* ************************************************** */
void c2_strcpy(void) 
{
  char ch;

  int str1 = 0;
  int str2 = 0;
  int str14 = 0;
  int I = 0;
  int s = 0;
  int x90 = 0;
  int x91 = 0;
  int x91a = 0;
  int x92 = 0;
  int x93 = 0;
  int x93a = 0;
  int x94 = 0;
  int x94a = 0;
  int x94c = 0;
  int x94d = 0;
  int x95 = 0;
  int x96 = 0;
  int x97 = 0;

  str1 = 0;
  str2 = 0;

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '\"') 
    {
      x90++;
    }
    if(ch == '[')
    {
      if(x91 == 0)
      {
        x91a = I;
        str2 = I;
      }
      if(x94a == 0)
      {
        x94c++;
      }
      if(x94a > 0)
      {
      /*  x91b = I; */
        x94d++;
      }
      x91++;
    }
    if(ch == ']')
    {
      if(x94a == 0)
      {
        x94c++;
      }
      if(x94a > 0)
      {
        x94d++;
      }
      x91++;
    }
    if(ch == '.')
    {
      if(x93 == 0)
      {
        x93a = I;
      }
      x93++;
    }
    if(ch == ',')
    {
      if(x94 == 0)
      {
        x94a = I;
        str1 = I;
      }
      x94++;
    }
    if(ch == '(')
    {
      x95++;
    }
    if(ch == ')')
    {
      x96 ++;
    }
    if(ch == '\"')
    {
      x97++;
    }
   }

/*
 printf("\nc2z_strcpy.c #1 rct = %d p_string = %s",rct,p_string);
 printf("c2z_strcpy.c #1 x90 = %d x92 = %d x93 = %d x93a = %d  x94 = %d x94a = %d x95 = %d x96 = %d x97 = %d\n",x90,x92,x93,x93a,x94,x94a,x95,x96,x97);    
 printf("c2z_strcpy.c #1 x91 = %d x91a = %d x91b = %d x94a = %d x94c = %d x94d = %d\n",x91, x91a,x91b,x94a,x94c,x94d);
*/

  /*  c2_str_1				strcpy(cvalue, "123456");  				*/
  /*  c2_str_1                            strcpy(in_stack[t], "123456");			*/
  /*  c2_str_2 		 		strcpy(p_string, arrary1[line_ndx])		*/
  /*  c2_str_3                            strcpy(in_stack[t], varname);			*/
  /*  c2_str_4                            strcpy(a, cvalue);					*/
  /*  c2_str_5                            strcpy(in_stack[t], in_stack[1]);			*/
  /*  c2_str_6				strcpy(varname, get_varname());			*/
  /*  c2_str_7				strcpy(gw_variable[gv_ct].gv_name, varname);	*/
  /*  c2_str_8				strcpy(gw_variable[gv_ct].gv_name, "123456");	*/
  /*  c2_str_9                            strcpy(in_stack[x], gw_variable[gv_ct].gv_name);	*/
  /*  c2_str_10				strcpy(gw_variable[gv_ct].gv_name, in_stack[x]); */
  /*  c2_str_11				strcpy(gw_variable[gv_ct].gv_name, gw_variable[I].gv_name */
  /*  c2_str_12                           strcpy(row[x][y], input);                        */

  if((x90 == 2) && (x94 == 1) && (x91 == 0) && (x92 == 0) && (x93 == 0))
  {
    c2_str_1(str1, str14);
    convert = 1;
    return;
  }

  if((x90 == 2) && (x91 == 2) && (convert == 0))
  {
    c2_str_1(str1,str14);
    convert = 1;
    return;
  }

  if ((x90 == 0) && (x91 == 0) && (x92 == 0) && (x93 == 0) && (x94 == 1) && (x95 == 1) && (x96 == 1) && (convert == 0)) 
  {
    c2_str_4();
    convert = 1;
    return;
  }

  if ((x90 == 2) && (x91 == 1) && (x92 == 1) && (x93 == 0) && (x94 == 1) && (convert == 0)) 
  {
    c2_str_1(str1, str14); 
    convert = 1;
    return;
  }

  if ((x90 == 0) && (x91 == 2) && (x93 == 0) && (x94 == 1) && (x91a < x94a) && (convert == 0)) 
  {
    c2_str_3(str1, str2);
    convert = 1;
    return;
  }

  if((x94c == 4) && (x94d == 0) && (x95 == 1) && (x96 == 1) && (convert == 0))
  {
    c2_str_12();
    convert = 1;
    return;
  }

  if((x94c == 0) && (x94d == 4) && (x95 == 1) && (x96 == 1) && (convert == 0))
  {
    c2_str_13();
    convert = 1;
    return;
  }


  if ((x90 == 0) && (x91 == 4) && (x92 == 0) && (x93 == 0) && (x94 == 1) && (x97 == 0) && (convert == 0)) 
  {
    c2_str_5();
    convert = 1;
    return;
  }

  if ((x90 == 0) && (x91 == 2) && (x93 == 0) && (x94 == 1) && (x91a > x94a) && (convert == 0)) 
  {
    c2_str_2(str1, str2);
    convert = 1;
    return;
  }

  if ((x90 == 0) && (x91 == 0) && (x92 == 0) && (x93 == 0) && (x94 == 1) && (x95 == 2) && (x96 == 2) && (convert == 0)) 
  {
    c2_str_6();
    convert = 1;
    return;
  }

  if ((x90 == 0) && (x91 == 1) && (x92 == 1) && (x93 == 1) && (x94 == 1) && (x95 == 1) && (x96 == 1) && (convert == 0)) 
  {
    c2_str_7();
    convert = 1;
    return;
  }

  if ((x90 == 2) && (x91 == 1) && (x92 == 1) && (x93 == 1) && (x94 == 1) && (x95 == 1) && (x96 == 1) && (convert == 0)) 
  {
    c2_str_8();
    convert = 1;
    return;
  }

  if ((x90 == 0) && (x91 == 2) && (x92 == 2) && (x93 == 1) && (x94 == 1) && (x95 == 1) && (x96 == 1) && (x94a < x93a) && (convert == 0)) 
  {
    c2_str_9();
    convert = 1;
    return;
  }

  if ((x90 == 0) && (x91 == 2) && (x92 == 2) && (x93 == 1) && (x94 == 1) && (x95 == 1) && (x96 == 1) && (x94a > x93a) && (convert == 0)) 
  {
    c2_str_10();
    convert = 1;
    return;
  }

  if((x90 == 0) && (x91 == 2) && (x92 == 2) && (x93 == 2) && (x94 == 1) && (x95 == 1) && (x96 == 1) && (x97 == 0) && (convert == 0))
  {
    c2_str_11();
    convert = 1;
    return;
  }

  if((x97 == 2) && (x91 == 0) && (convert == 0))		/*  strcpy(xstring, "This is a test\n");  */
  {
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
      strcpy(trace_1, "c2z_strcpy.c #50");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field3);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #51");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(");
    strcat(a_string, p_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c #52");
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
    strcpy(trace_1, "c2z_strcpy.c str_1 START");
    trace_rec_1();
  }

  char ch;
  char *p1, *p2, *p3, *p4;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field1b[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field6a[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];

  int pi;
  int pi2;
  int v = 0;
  int ret = 0;
  int ret1 = 0;
  int str5 = 0;
  int x2 = 0;
  int x3 = 0;
  int x6 = 0;
  int x90 = 0;
  int x91 = 0;
  int I = 0;
  int str3 = 0;
  int s = 0;
  int TL = 0;
  int L1 = 0;
  int R1 = 0;
  int C1 = 0;
  int PD = 0;
  int PD1 = 0;

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
    pi++;
    ch = p_string[pi];
    while(ch != ']')
    {
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
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
      trace_rec_3();
    }
   
    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
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
      strcpy(trace_1, "c2z_strcpy.c str_1 #904");
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
      strcpy(trace_1, "c2z_strcpy.c str_1 #904");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
      trace_rec_3();
    }
    work_use_ct[49]++;

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

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
      trace_rec_3();
    }
   
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
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
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R9,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
      trace_rec_3();
    }

    strcpy(a_string, "         JLu   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "b");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #904");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field4a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #101");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #101");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  if ((p4) && (!p1) && (!p2)) 
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
      strcpy(trace_1, "c2z_strcpy.c str_1 #108");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #109");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_1 #110");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  if ((!p1) && (!p2) && (!p3) && (!p4)) 
  {
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_1 #1");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370B1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_1 #2");
        trace_rec_3();
      }
      work_use_ct[52]++;

      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_1 #3");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_1 #5");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_1 #6");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_1 #7");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_1 #8");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_1 #9");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_1 #10");
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
          printf("\nc2z_strcpy.c strcpy-006 c2_str_2 Undetermine \n");
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
      strcpy(trace_1, "c2z_strcpy.c c2z_strcpy.c c2_str_1 #300");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #301");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #302");
      trace_rec_3();
    }

    convert = 1;
  }

  if ((p1) && (p2) && (!p3) && (p4)) 
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
    ch = p_string[pi];
    while (ch != ']') 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

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
      printf("\nc2z_strcpy.c c2_str_1 strcpy-009 field2a Not Found %s\n", field2);
      printf("c2z_strcpy.c c2_str_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(field3a, w_charlit[I].clit_cname);
        x3 = w_charlit[I].clit_lgth;
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #900");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #901");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #902");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #903");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #904");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #905");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #906");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #907");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #908");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #909");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #910");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #911");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #912");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #913");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #914");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #915");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #916");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #917");
      trace_rec_3();
    }
    work_use_ct[74]++;

    snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
    strcpy(a_string, "         MVC   ");
    strcat(a_string, wk_strg);
    strcat(a_string, "(1,R6),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_1 #918");
      trace_rec_3();
    }

    convert = 1;
    return;
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

  int pi;
  int pi2;
  int v = 0;

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
  int x99 = 0;
  int fd3_type = 0;
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
        x99 = lw_variable[v].lv_lgth;
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
          x99 = gw_variable[v].gv_lgth;
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
      strcpy(trace_1, "c2z_strcpy.c str_2 #1");
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
            x99 = gw_variable[I].gv_lgth;
          }
        }
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c str_2 #2");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c str_2 #3");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c str_2 #4");
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
        strcpy(trace_1, "c2z_strcpy.c str_2 #5");
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
        strcpy(trace_1, "c2z_strcpy.c str_2 #6");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c str_2 #7");
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
          strcpy(trace_1, "c2z_strcpy.c str_2 #8");
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
          strcpy(trace_1, "c2z_strcpy.c str_2 #9");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_2 #10");
          trace_rec_3();
        }
 
        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_2 #11");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK3");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_2 #12");
          trace_rec_3();
        }
        work_use_ct[78]++;

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_2 #13");
          trace_rec_3();
        }
 
        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_2 #14");
          trace_rec_3();
        }
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c str_2 #9");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c str_2 #10");
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
        strcpy(trace_1, "c2z_strcpy.c str_2 #11");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c str_2 #12");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c str_2 #13");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c str_2 #14");
        trace_rec_3();
      }

      strcpy(a_string, "         JLU   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c str_2 #15");
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
        strcpy(trace_1, "c2z_strcpy.c str_2 #16");
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
        strcpy(trace_1, "c2z_strcpy.c str_2 #17");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   ");
      strcat(a_string, "0(");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x99);
      strcat(a_string, wk_strg);
      strcat(a_string, ",R9)");
      strcat(a_string, ",");
      strcat(a_string, "0(R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c str_2 #18");
        trace_rec_3();
      }
    }

    str9 = strcmp(field4, "C");
    if (str9 == 0) 
    {
      printf("\nc2z_strcpy.c c2_str_2 strcpy-013 code character Not Coded\n");
      printf("c2z_strcpy.c c2_str_2 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }
  convert = 1;
  return;
}


void c2_str_3(int str1, int str2) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c str_3 START");
    trace_rec_1();
  }

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
  int x99 = 0;
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
            strcpy(trace_1, "c2z_strcpy.c str_3 #1");
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
          strcpy(trace_1, "c2z_strcpy.c str_3 #2");
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
            strcpy(trace_1, "c2z_strcpy.c str_3 #3");
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
          strcpy(trace_1, "c2z_strcpy.c str_3 #4");
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
      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if (ch != ',') 
        {
          if (ch != ' ') 
          {
            tfield3[pi2] = ch;
            pi2++;
          }
        }
        pi++;
        ch = p_string[pi];
      }
      tfield3[pi2] = '\0';

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
              x99 = gw_variable[I].gv_lgth; 
            
            }
          }
        }

        p = strstr(tfield3, "'\0'");
        if (p) 
        {
          x6 = 1;
        }

        if (x6 == 0) 
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
            strcpy(trace_1, "c2z_strcpy.c str_3 #5a");
            trace_rec_3();
          }

          strcpy(a_string,"         LARL R9,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c str_3 #5b");
            trace_rec_3();
          }

          strcpy(a_string,"         CVD  R5,0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c str_3 #5c");
            trace_rec_3();
          }

          strcpy(a_string,"         LARL R9,C370NWK2");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c str_3 #5d");
            trace_rec_3();
          }

          strcpy(a_string,"         LARL R8,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c str_3 #5e");
            trace_rec_3();
          }

          strcpy(a_string,"         ZAP  0(6,R9),0(8,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_strcpy.c str_3 #5f");
            trace_rec_3();
          }
        }

        if (str6 == 0) 
        {
          printf("\nc2z_strcpy.c c2_str_3 strcpy-016 tfield3 Not Found = %s\n",tfield3);
          printf("c2z_strcpy.c c2_str_3 rct = %d p_string = %s",rct,p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_3 #6");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_3 #7");
          trace_rec_3();
        }
        work_use_ct[32]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_3 #8");
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
          strcpy(trace_1, "c2z_strcpy.c str_3 #9");
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
          strcpy(trace_1, "c2z_strcpy.c str_3 #10");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_3 #11");
          trace_rec_3();
        }

        if (fd2_type == 1) 
        {
          strcpy(a_string, "         LARL  R8,C370NWK2");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c str_3 #12a");
            trace_rec_3();
           }
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
            strcpy(trace_1, "c2z_strcpy.c str_3 #12b");
            trace_rec_3();
          }
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_3 #13");
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
          strcpy(trace_1, "c2z_strcpy.c str_3 #14");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_3 #15");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_3 #16");
          trace_rec_3();
        }

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_3 #17");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, tfield6);
        strcat(a_string, "(R0,R6)");
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_3 #18");
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
          strcpy(trace_1, "c2z_strcpy.c str_3 #19");
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
          strcpy(trace_1, "c2z_strcpy.c str_3 #20");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, tfield3a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield3);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_3 #21");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", x99);
        strcpy(a_string, "         MVC   0(");
        strcat(a_string, wk_strg);
        strcat(a_string, ",R6),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_strcpy.c str_3 #22");
          trace_rec_3();
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
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "T");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #4");
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
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #6");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #7");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #8");
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
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, tfield6a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #11");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #12");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #13");
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
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #14");
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
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield5a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #19");
      trace_rec_3();
    }
    work_use_ct[32]++;

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
      strcpy(trace_1, "c2z_strcpy.c str_3 Struc #22");
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
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield4[VAR_LGTH];

  int pi;
  int pi2;
  int v = 0;
  int I = 0;
/*  int x1 = 0; */
  int x2 = 0;
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
   /*     x1 = lw_variable[v].lv_current_lgth; */
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
      /*    x1 = gw_variable[v].gv_current_lgth; */
         /* gw_variable[v].gv_current_lgth = x1; take out ?? */
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
        x2 = lw_variable[v].lv_current_lgth;
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
          x2 = gw_variable[v].gv_current_lgth;
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


  if (x10 == 0) 
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_4 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_4 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC2  ");
    strcat(a_string, tfield1a);
    strcat(a_string, ",");
    strcat(a_string, tfield2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_4 #3");
      trace_rec_3();
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
          lw_variable[v].lv_current_lgth = x2;
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
            gw_variable[v].gv_current_lgth = x2;
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
  int x92 = 0;
  int x93 = 0;
  int x94 = 0;
  int x95 = 0;
  int x96 = 0;
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #5");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #7");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #9");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #11");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #12");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #13");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #14");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #15");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #16");
      trace_rec_3();
    }

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R5,");
    strcat(a_string, ar1_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #19");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #20");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #21");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #22");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #23");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #24");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield4a);
    src_line();
    if (puncde == 1) {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #25");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #26");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #27");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R5,");
    strcat(a_string, ar1_field6);
    strcat(a_string, "(R0,R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #28");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #29");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #30");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #31");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #32");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #33");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x11);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),0(R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 #34");
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
      x92 = 1;
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

    if (!p) 
    {
      x92 = 2;
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
        x92 = lw_variable[I].lv_lgth;
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #3");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #4");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #6");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #7");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #8");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #9");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #10");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #11");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #12");
        trace_rec_3();
      }
 
      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #13");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #14");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #16");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #18");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #19");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #20");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #21");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #22");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #23");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #24");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #25");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #26");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #27");
      trace_rec_3();
    }

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
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #28");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #29");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #30");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R4,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #31");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #32");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #33");
        trace_rec_3();
      }
 
      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #34");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #35");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #36");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, ar1_field6);
    strcat(a_string, "(R0,R5)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #37");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #38");
      trace_rec_3();
    }

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #39");
        trace_rec_3();
      }

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #40");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #41");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #42");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x95);
      strcat(a_string, wk_strg);
      strcat(a_string, "(");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x92);
      strcat(a_string, wk_strg);
      strcat(a_string, ",R6),");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
      strcat(a_string, wk_strg);
      strcat(a_string, "(R5)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_5 MULTI #43");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_6 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_6 #2");
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

    strcpy(a_string, "         MVC2  ");
    strcat(a_string, tfield1a);
    strcat(a_string, ",");
    strcat(a_string, tfield3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_6 #3");
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
    ret = strcmp(tfield1, w_struc[I].st_name);
    if(ret == 0)
    {
       x3 = 1;
       strcpy(tfield1a, w_struc[I].st_cname);
  /*     x92 = w_struc[I].st_field_lgth;
       x96 = w_struc[I].st_disp; */
       break;
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

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(tfield1, w_struc[I].st_name);
    ret1 = strcmp(tfield3, w_struc[I].st_field_name);
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #101");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #102");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #103");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #104");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #105");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #106");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #107");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #107a");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #107b");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #107c");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #107d");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #107e");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #107f");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #108");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #109");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #110");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #111");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #112");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #113");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #114");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #115");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #116");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #117");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #118");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #119");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #3");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #4");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #6");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #7");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #8");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #9");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #10");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #11");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #12");
        trace_rec_3();
      }
 
      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_7 #13");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #14");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #16");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #17");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #18");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #19");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #20");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #21");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #22");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_7 #23");
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

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #3");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #4");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #6");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_8 #7");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_8 #8");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_8 #9");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_8 #10");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_8 #11");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_8 #12");
        trace_rec_3();
      }
 
      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_8 #13");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #14");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #16");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #17");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #18");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #19");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #20");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #21");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #22");
      trace_rec_3();
    }

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
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #23");
      trace_rec_3();
    }
    
    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #24");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_8 #25");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #1");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #2");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R4,");
  strcat(a_string, ar_field7);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #4");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #6");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_9 #7");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_9 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_9 #9");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_9 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_9 #11");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_9 #12");
      trace_rec_3();
    }
 
    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_9 #13");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #14");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #15");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R4,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R4)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #16");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #17");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #18");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #19");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #20");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #21");
    trace_rec_3();
  }

/*  now get structure */

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #22");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #23");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #24");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #25");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #26");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #27");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_9 #28");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #29");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #30");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #31");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #32");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #33");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #34");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, field3a);
  strcat(a_string, "L");
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #35");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #36");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_9 #37");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_9 #38");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #101");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #102");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #103");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #104");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #105");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #106");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #107");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #108");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #109");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #110");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #111");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #112");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #113");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, field1a);
  strcat(a_string, "L");
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #114");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #115");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #116");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #117");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #118");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #119");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R4,");
    strcat(a_string, ar_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #120");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #121");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #122");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_10 #123");
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
        strcpy(trace_1, "c2z_strcpy.c c2_str_10 #124");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_10 #125");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_10 #126");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_10 #127");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_10 #128");
        trace_rec_3();
      }
 
      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c c2_str_10 #129");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #130");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #131");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R4,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R4)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #132");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #133");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #134");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #135");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #136");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #137");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_10 #138");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #101");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #102");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #103");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #104");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #105");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #106");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_11 #107");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #108");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #109");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #110");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #111");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #112");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #113");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, field1a);
  strcat(a_string, "L");
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #114");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #115");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #116");
    trace_rec_3();
  }

/* now to find the 2nd gw_variable */
  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #117");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #118");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #119");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #120");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #121");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #122");
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
      strcpy(trace_1, "c2z_strcpy.c c2_str_11 #123");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #124");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #125");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #126");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #127");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #128");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #129");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R5,");
  strcat(a_string, field1a);
  strcat(a_string, "L");
  strcat(a_string, "(R0,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #130");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #131");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_11 #132");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #133");
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
    strcpy(trace_1, "c2z_strcpy.c c2_str_10 #134");
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
    char_ct++;
  }

  convert = 1;
  return;
}


void c2_str_12()
{
printf("\nc2z_strcpy.c c2_str_12 INSIDE #12 rct = %d p_string = %s",rct,p_string);

    int pi;
    int pi2;
    int x2;
    int I;
    int ret;
    int ret1;
    int x100;
    int x101;

   char ch;
   char field1[VAR_LGTH];
   char field1a[VAR_LGTH];
   char field2[VAR_LGTH];
   char field2a[VAR_LGTH];
   char field3[VAR_LGTH];
   char field3a[VAR_LGTH];
   char field4[VAR_LGTH];
   char field4a[VAR_LGTH];

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
   pi++;
   ch = p_string[pi];
   while(ch != ']')
   {
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
   while(ch != ']')
   {
     field3[pi2] = ch;
     pi2++;
     pi++;
     ch = p_string[pi];
   }
   field3[pi2] = '\0';

   pi++;
   pi++;
   ch = p_string[pi];
   while(ch == ' ')
   {
     pi++;
     ch = p_string[pi];
   }

   pi2 = 0;
   while(ch != ')')
   {
     field4[pi2] = ch;
     pi2++;
     pi++;
     ch = p_string[pi];
   }
   field4[pi2] = '\0';

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
           x100 = gw_variable[I].gv_row;
           x101 = gw_variable[I].gv_column;
printf("rct = %d gv_row = %d\n",rct,gw_variable[I].gv_row);
printf("rct = %d gv_column = %d\n",rct,gw_variable[I].gv_column);
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
printf("c2z_strcpy.c c2_str_12 rct = %d field1 = %s field1a = %s\n",rct,field1,field1a);

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
printf("c2z_strcpy.c c2_str_12 rct = %d field2 = %s field2a = %s\n",rct,field2,field2a);

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
printf("c2z_strcpy.c c2_str_12 rct = %d field3 = %s field3a = %s\n",rct,field3,field3a);

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
           gw_variable[I].gv_use_ct++;
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
printf("c2z_strcpy.c c2_str_12 rct = %d field4 = %s field4a = %s\n",rct,field4,field4a);















   convert = 1;
   return;
}



void c2_str_13()
{
printf("\nc2z_strcpy.c c2_str_13 INSIDE #13 rct = %d p_string = %s",rct,p_string);

    int pi;
    int pi2;
    int x2;
    int I;
    int ret;
    int ret1;
    int x100;
    int x101;

   char ch;
   char field1[VAR_LGTH];
   char field1a[VAR_LGTH];
   char field2[VAR_LGTH];
   char field2a[VAR_LGTH];
   char field3[VAR_LGTH];
   char field3a[VAR_LGTH];
   char field4[VAR_LGTH];
   char field4a[VAR_LGTH];

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
   while(ch != ',')
   {
     field1[pi2] = ch;
     pi2++;
     pi++;
     ch = p_string[pi];
   }
   field1[pi2] = '\0';

   pi++;
   ch = p_string[pi];
   while(ch == ' ')
   {
     pi++;
     ch = p_string[pi];
   }

   pi2 = 0;
   while(ch != '[')
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
   while(ch != ']')
   {
     field3[pi2] = ch;
     pi2++;
     pi++;
     ch = p_string[pi];
   }
   field3[pi2] = '\0';

   pi2 = 0;
   pi++;
   pi++;
   ch = p_string[pi];
   while(ch != ']')
   {
     field4[pi2] = ch;
     pi2++;
     pi++;
     ch = p_string[pi];
   }
   field4[pi2] = '\0';

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
         }
       }
     }
   }

   if (x2 == 0) 
   {
     printf("\nc2z_strcpy.c c2_str_13 E-001 field1 Not Found = %s\n",field1);
     printf("c2z_strcpy.c c2_str_13 rct = %d p_string = %s\n",rct,p_string);
     erct++;
     convert = 1;
     return;
   }
printf("c2z_strcpy.c c2_str_13 rct = %d field1 = %s field1a = %s\n",rct,field1,field1a);

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
         ret = strcmp(field2, gw_variable[I].gv_name);
         if (ret == 0) 
         {
           x2 = 1;
           strcpy(field2a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
           x100 = gw_variable[I].gv_row;
           x101 = gw_variable[I].gv_column;
printf("rct = %d gv_row = %d\n",rct,gw_variable[I].gv_row);
printf("rct = %d gv_column = %d\n",rct,gw_variable[I].gv_column);
           break;
         }
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
printf("c2z_strcpy.c c2_str_13 rct = %d field2 = %s field2a = %s\n",rct,field2,field2a);

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
     printf("\nc2z_strcpy.c c2_str_13 E-003 field3 Not Found = %s\n",field3);
     printf("c2z_strcpy.c c2_str_13 rct = %d p_string = %s\n",rct,p_string);
     erct++;
     convert = 1;
     return;
   }
printf("c2z_strcpy.c c2_str_13 rct = %d field3 = %s field3a = %s\n",rct,field3,field3a);

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
           gw_variable[I].gv_use_ct++;
         }
       }
     }
   }

   if (x2 == 0) 
   {
     printf("\nc2z_strcpy.c c2_str_13 E-004 field4 Not Found = %s\n",field4);
     printf("c2z_strcpy.c c2_str_13 rct = %d p_string = %s\n",rct,p_string);
     erct++;
     convert = 1;
     return;
   }
printf("c2z_strcpy.c c2_str_13 rct = %d field4 = %s field4a = %s\n",rct,field4,field4a);





  convert = 1;
  return;
}

