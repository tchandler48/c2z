/* ***************************************************
*  c2z : c2z_arth.c :                                *
*                                                    *
*  Copyright TCCS (c) 2019 - 2026                    *
**************************************************** */

void c2z_math_start()
{
  int pi;
  int s = 0;
  int I = 0;
  int pi2 = 0;
  int x2 = 0;
  int x3 = 0;
  int v;
  int x30 = 0;
  int x31 = 0;
  int x32 = 0;
  int x70 = 0;
  int x71 = 0;
  int x73 = 0;
  int x99 = 0;
  int pi3 = 0;
  int pi4 = 0;
  int x55 = 0;

  int ret = 0;
  int ret1 = 0;
  int fd1_type = 0;
  int fd2_type = 0;
  int fd3_type = 0;
  int fd4_type = 0;
  int fd6_type = 0;
  int fd8_type = 0;
  int fd10_type = 0;
/* int fd12_type = 0; */
/* int fd14_type = 0; */
/* int fd16_type = 0; */
/* int fd18_type = 0; */
/* int fd20_type = 0; */
  int operand_1 = 0;
  int operand_2 = 0;
  int operand_3 = 0;
  int operand_4 = 0;
  int eol1 = 0;
  int eol2 = 0;
  int eol3 = 0;
  int eol4 = 0;
  int eol5 = 0;
  int eol6 = 0;
  int eol7 = 0;
  int eol8 = 0;
 
  char ch;
  char *p, *p10;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field4b[VAR_LGTH];
  char field4c[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field6a[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field8a[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field10a[VAR_LGTH];
/*  char field11[VAR_LGTH]; */
/*  char field12[VAR_LGTH]; */
/*  char field13[VAR_LGTH]; */
/*  char field14[VAR_LGTH]; */
/*  char field15[VAR_LGTH]; */
/*  char field16[VAR_LGTH]; */
/*  char field17[VAR_LGTH]; */
/*  char field18[VAR_LGTH]; */
/*  char field19[VAR_LGTH]; */
/*  char field20[VAR_LGTH]; */

  char wk_sv_func[VAR_LGTH];

  p = strstr(p_string, "char");
  if (p) 
  {
    return;
  }

  x70 = 0;
  x71 = 0;
  p = strstr(p_string, "+=");	/* offset += param; offset += 2;  */
  if(p)
  {
    x70 = 1;
  }
  p = strstr(p_string, "*=");	/* offset += param; offset += 2;  */
  if(p)
  {
    x71 = 1;
  }

  if((x70 == 1) || (x71 == 1))
  {
    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t') || (ch == '{'))
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      if (x2 == 0) 
      {
          if (isalpha(ch)) 
          {
            fd1_type = 2;
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
            fd1_type = 1;
            x2 = 1;
          }
      }
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
    
    while(ch != ' ')
    {
      pi++;
      ch = p_string[pi];
    }
  
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
    
    x2 = 0;
    pi2 = 0;
    while(ch != ';')
    {
      if(ch != '(')
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd3_type = 2;
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
            fd3_type = 1;
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

    if((fd1_type == 2) && (fd3_type == 1))
    {
      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field1a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field1a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_arth c2_math_start 001 field1 = %s\n", field1);
        printf("c2z_arth rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #001");
      trace_rec_3();
      
      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #002");
      trace_rec_3();
      
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #003");
      trace_rec_3();
      
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #004");
      trace_rec_3();
             
      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #005");
      trace_rec_3();
      work_use_ct[48]++;
 
      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #006");
      trace_rec_3();
      
      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #007");
      trace_rec_3();
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #008");
      trace_rec_3();
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #009");
      trace_rec_3();
             
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #010");
      trace_rec_3();
      
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      strcpy(wk_remark," ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      strcpy(trace_1, "c2z_arth c2_math_start #011");
      trace_rec_3();
      
      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #012");
      trace_rec_3();
      
      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #013");
      trace_rec_3();
      
      convert = 1;
      return;
    }


    if((fd1_type == 2) && (fd3_type == 2))
    {
      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field1a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field1a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_arth c2_math_start 002 field1 = %s\n", field1);
        printf("c2z_arth rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      strcpy(wk_remark," ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      strcpy(trace_1, "c2z_arth c2_math_start #014");
      trace_rec_3();
          
      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field3, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field3a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field3, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field3a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_arth c2_math_start 003 field1 = %s\n", field3);
        printf("c2z_arth rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field3a);
      strcpy(wk_remark," ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      strcpy(trace_1, "c2z_arth c2_math_start #015");
      trace_rec_3();
      
      if(x70 == 1)
      {
        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        strcpy(trace_1, "c2z_arth c2_math_start #016");
        trace_rec_3();
      }

      if(x71 == 1)
      {
        strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
        src_line();
        strcpy(trace_1, "c2z_arth c2_math_start #017");
        trace_rec_3();
      }
      convert = 1;
      return;
    }
  }

/*  x = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;                 */
/*  1   2   3   4   5   6   7   8   9   10  11     field names  */
/*           ;   ;   ;   ;   ;   ;   ;   ;    ;    eol fields   */
/*           1   2   3   4   5   6   7   8    9                 */

/*  extract field names and eol count                           */


  s = strlen(p_string);
  s--;
  s--;
  
  x31 = 0;
  x32 = 0;
  pi = 0;
  ch = p_string[pi];
  for (I = 0; I < s; I++) 
  {
    if (ch == '+')
    {
      x30 = 1;
    }
 
    if (ch == '-')
    {
      x30 = 1;
    }

    if (ch == '*')
    {
      x30 = 1;
    }

    if (ch == '/')
    {
      x30 = 1;
    }
    if (ch == '[')
    {
      x31++;
    }
    if (ch == ']')
    {
      x31++;
    }
    if (ch == '(')
    {
      x32++;
    }
    if (ch == ')')
    {
      x32++;
    }

    pi++;
    ch = p_string[pi];
  }

  if((x30 == 1) && (x31 == 2) && (x32 == 2))
  {
    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t'))
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
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
    pi++;
    ch = p_string[pi];
    while(ch != ' ')
    {
       field2[pi2] = ch;
       pi2++;
       pi++;
       ch = p_string[pi];
    }
    field2[pi2] = '\0';

    while(ch == ' ')
    {
       pi++;
       ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while(ch != ' ')
    {
       field3[pi2] = ch;
       pi2++;
       pi++;
       ch = p_string[pi];
    }
    field3[pi2] = '\0';

    while(ch == ' ')
    {
       pi++;
       ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while(ch != ')')
    {
       field4[pi2] = ch;
       pi2++;
       pi++;
       ch = p_string[pi];
    }
    field4[pi2] = '\0';

    while(ch != '=')
    {
       pi++;
       ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != ';')
    {
       if(ch != ' ')
       {
         field5[pi2] = ch;
         pi2++;
       }
       pi++;
       ch = p_string[pi];
    }
    field5[pi2] = '\0';

    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    strcpy(trace_1, "c2z_arth #700");
    trace_rec_3();
    
    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    strcpy(trace_1, "c2z_arth #701");
    trace_rec_3();
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    strcpy(trace_1, "c2z_arth #702");
    trace_rec_3();
    
    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    strcpy(trace_1, "c2z_arth #703");
    trace_rec_3();
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    strcpy(trace_1, "c2z_arth #704");
    trace_rec_3();
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    strcpy(trace_1, "c2z_arth #705");
    trace_rec_3();
    
    x3 = 0;
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
  
    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_arth 700 field2 = %s\n", field2);
      printf("c2z_arth rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    strcpy(trace_1, "c2z_arth #706");
    trace_rec_3();
    
    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    strcpy(trace_1, "c2z_arth #707");
    trace_rec_3();
    work_use_ct[49]++;

    strcpy(a_string, "         AP    0(6,R9),0(8,R8)");
    src_line();
    strcpy(trace_1, "c2z_arth #708");
    trace_rec_3();
    
    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    strcpy(trace_1, "c2z_arth #709");
    trace_rec_3();
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    strcpy(trace_1, "c2z_arth #710");
    trace_rec_3();
    
    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    strcpy(wk_remark, " a[x] = ch ");
    write_remark();
    strcpy(trace_1, "c2z_arth #711");
    trace_rec_3();
    
    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    strcpy(trace_1, "c2z_arth #712");
    trace_rec_3();
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R2,0(R9)");
    src_line();
    strcpy(trace_1, "c2z_arth #713");
    trace_rec_3();
    work_use_ct[48]++;

    x3 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field1a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
      }
    }
  
    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field1, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field1a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_arth 714 field1 = %s\n", field1);
      printf("c2z_arth rct = %d p_string = %s", rct, p_string);
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
    strcpy(trace_1, "c2z_arth #714");
    trace_rec_3();
    
    strcpy(a_string, "         LR    R1,R9");
    src_line();
    strcpy(trace_1, "c2z_arth #715");
    trace_rec_3();
    
    strcpy(a_string, "         AR    R1,R2");
    src_line();
    strcpy(trace_1, "c2z_arth #716");
    trace_rec_3();
    
    x55 = 0;
    p10 = strstr(field5, "''");
    if(p10)
    {
      x55 = 1;
      strcpy(a_string, "         LARL  R8,C370B1");
      src_line();
      strcpy(trace_1, "c2z_arth #717");
      trace_rec_3();
    }

    p10 = strstr(field5, "\0");
    if((p10) && (x55 == 0))
    {
      strcpy(a_string, "         LARL  R8,C370NONE");
      src_line();
      strcpy(trace_1, "c2z_arth #718");
      trace_rec_3();
    }
    
    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    strcpy(trace_1, "c2z_arth #719");
    trace_rec_3();
    
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, "R9,R1),");
    strcat(a_string, "0(R8)");
    src_line();
    strcpy(trace_1, "c2z_arth #720");
    trace_rec_3();
    
    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    strcpy(trace_1, "c2z_arth #721");
    trace_rec_3();
    
    convert = 1;
    return;
  }


  pi = 0;
  ch = p_string[pi];
    while((ch == ' ') || (ch == '\t') || (ch == '{'))
    {
      pi++;
      ch = p_string[pi];
    }

    fd1_type = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd1_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd1_type = 1;
          x2 = 1;
        }
      }
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';


    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    while(ch != ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
    
    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd2_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
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

    p = strstr(field2, "-1");
    if(p)			
    {
      s = 0;
      I = 0;
      x73 = 0;
      s = strlen(p_string);
      for(I=0; I < s; I++)
      {
        ch = p_string[I];
        if(ch == '[')
        {
          x73++;
        }
        if(ch == ']')
        {
          x73++;
        }
      }


      if(x73 == 2)		
      {
        pi = 0;
        ch = p_string[pi];
        while((ch == ' ') || (ch == '\t'))
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
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

        pi++;
        ch = p_string[pi];
        while(ch == ' ')
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        while(ch != ' ')
        {
          field3[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field3[pi2] = '\0';

        while(ch == ' ')
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        while(ch != ';')
        {
          field4[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field4[pi2] = '\0';

        p = strstr(field4, "-1");
        if(p)
        {
          strcpy(a_string, "         LARL  R9,C370NWK1");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #800");
          trace_rec_3();
          work_use_ct[39]++;

          strcpy(a_string, "         LARL  R8,C370ZERO");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #801");
          trace_rec_3();
          
          strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #802");
          trace_rec_3();
          
          x3 = 0;
          if (x3 == 0) 
          {
            if (gv_ct > 0) 
            {
              for (I = 0; I < gv_ct; I++) 
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
                  x2 = gw_variable[I].gv_lgth;
                  x3 = 1;
                }
              }
            }
          }

          if (x3 == 0) 
          {
            printf("\nc2z_arth c2_arth 009 field1a = %s\n", field1);
            printf("c2z_arth rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }

          strcpy(a_string, "         LARL  R6,");
          strcat(a_string, field7);
          strcpy(wk_remark, " ");
          strcat(wk_remark, field1);
          strcat(wk_remark, " */");
          write_remark();
          strcpy(trace_1, "c2z_arth c2_math_start #803");
          trace_rec_3();
          
          strcpy(a_string, "L");
          snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
          strcat(a_string, wk_strg);
          strcat(a_string, "A");
          check_length();
          strcat(a_string, "DS    0H");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #804");
          trace_rec_3();
          
          strcpy(a_string, "         LARL  R9,C370NWK1");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #805");
          trace_rec_3();
          work_use_ct[39]++;

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
            printf("\nc2z_arth c2_arth field2 = %s\n", field2);
            printf("c2z_arth rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }

          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, field2a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, field2);
          strcat(wk_remark, " */");
          write_remark();
          strcpy(trace_1, "c2z_arth c2_math_start #806");
          trace_rec_3();
          
          strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #807");
          trace_rec_3();
          
          strcpy(a_string, "         JLE   L");
          snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
          strcat(a_string, wk_strg);
          strcat(a_string, "B");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #808");
          trace_rec_3();
          
          strcpy(a_string, "         LARL  R9,C370NWK1");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #809");
          trace_rec_3();
          work_use_ct[39]++;

          strcpy(a_string, "         LARL  R8,C370ONE");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #810");
          trace_rec_3();
          
          strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #811");
          trace_rec_3();
          
          strcpy(a_string, "         LA    R6,");  
          strcat(a_string, field6);
          strcat(a_string, "(R0,R6)");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #812");
          trace_rec_3();
          
          strcpy(a_string, "         JLU   L");
          snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
          strcat(a_string, wk_strg);
          strcat(a_string, "A");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #813");
          trace_rec_3();
          
          strcpy(a_string, "L");
          snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
          strcat(a_string, wk_strg);
          strcat(a_string, "B");
          check_length();
          strcat(a_string, "DS    0H");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #814");
          trace_rec_3();
          
          strcpy(a_string, "         LARL  R9,C370NONE");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #815");
          trace_rec_3();
          
          strcpy(a_string, "         MVC   ");
          strcat(a_string,"0(");
          strcat(a_string, "2,R6),0(R9)");
          src_line();
          strcpy(trace_1, "c2z_arth c2_math_start #816");
          trace_rec_3();
          
          convert = 1;
          return;
        }

        if(!p)
        {
          printf("c2z_arch x73 ERROR NOT CODED\n");
          printf("c2z_arth rct = %d p_string = %s",rct,p_string);
          erct++;
          convert = 1;
          return;
        }
     }

      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field1a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field1, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field1a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
 
      if (x3 == 0) 
      {
        printf("\nc2z_arth c2_math_start 004 field1 = %s\n", field1);
        printf("c2z_arth.c rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      strcpy(wk_remark," ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      strcpy(trace_1, "c2z_arth c2_math_start #015");
      trace_rec_3();
      
      strcpy(a_string, "         LARL  R8,C370NONE");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #016");
      trace_rec_3();
      
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #017");
      trace_rec_3();
      
      convert = 1;
      return;
    }

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
    
    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      if(ch == ';')
      {
        eol1 = 1;
        break;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd4_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd4_type = 1;
          x2 = 1;
        }
      }
      field4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field4[pi2] = '\0';

    if(eol1 == 1)
    {
       goto eolmath_1;
    }

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
    
    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      field5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    eol2 = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      if(ch == ';')
      {
        eol2 = 1;
        break;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd6_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd6_type = 1;
          x2 = 1;
        }
      }
      field6[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field6[pi2] = '\0';

    if(eol2 == 1)
    {
       goto eolmath_1;
    }

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      field7[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field7[pi2] = '\0';

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    eol3 = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      if(ch == ';')
      {
        eol3 = 1;
        break;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd8_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd8_type = 1;
          x2 = 1;
        }
      }
      field8[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field8[pi2] = '\0';

    if(eol3 == 1)
    {
       goto eolmath_1;
    }

   while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      field9[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field9[pi2] = '\0';

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    eol4 = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      if(ch == ';')
      {
        eol4 = 1;
        break;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd10_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd10_type = 1;
          x2 = 1;
        }
      }
      field10[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field10[pi2] = '\0';

    if(eol4 == 1)
    {
       goto eolmath_1;
    }

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
 /*     field11[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
 /*   field11[pi2] = '\0'; */

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    eol5 = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      if(ch == ';')
      {
        eol5 = 1;
        break;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
   /*       fd12_type = 2; */
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
   /*       fd12_type = 1; */
          x2 = 1;
        }
      }
 /*     field12[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
 /*   field12[pi2] = '\0'; */

    if(eol5 == 1)
    {
       goto eolmath_1;
    }

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
 /*     field13[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
/*    field13[pi2] = '\0'; */

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    eol6 = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      if(ch == ';')
      {
        eol6 = 1;
        break;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
      /*    fd14_type = 2; */
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
     /*     fd14_type = 1; */
          x2 = 1;
        }
      }
  /*    field14[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  /*  field14[pi2] = '\0'; */

    if(eol6 == 1)
    {
       goto eolmath_1;
    }

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
  /*    field15[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
 /*   field15[pi2] = '\0'; */

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    eol7 = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      if(ch == ';')
      {
        eol7 = 1;
        break;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
     /*     fd16_type = 2; */
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
     /*     fd16_type = 1; */
          x2 = 1;
        }
      }
 /*     field16[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
 /*   field16[pi2] = '\0'; */

    if(eol7 == 1)
    {
       goto eolmath_1;
    }

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
 /*     field17[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
 /*   field17[pi2] = '\0'; */

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    eol8 = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      if(ch == ';')
      {
        eol8 = 1;
        break;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
     /*     fd18_type = 2; */
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
     /*     fd18_type = 1; */
          x2 = 1;
        }
      }
  /*    field18[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  /*  field18[pi2] = '\0'; */

    if(eol8 == 1)
    {
       goto eolmath_1;
    }

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
 /*     field19[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
 /*   field19[pi2] = '\0'; */

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      if(ch == ';')
      {
        break;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
     /*     fd20_type = 2; */
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
     /*     fd20_type = 1; */
          x2 = 1;
        }
      }
  /*    field20[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
 /*   field20[pi2] = '\0'; */

    if(eol8 == 1)
    {
       goto eolmath_1;
    }

    eolmath_1:

/*
printf("c2z_arth.c #99 rct = %d eol1 = %d\n",rct,eol1);
printf("c2z_arth.c #99 rct = %d eol2 = %d\n",rct,eol2);
printf("c2z_arth.c #99 rct = %d eol3 = %d\n",rct,eol3);
printf("c2z_arth.c #99 rct = %d eol4 = %d\n",rct,eol4);
printf("c2z_arth.c #99 rct = %d eol5 = %d\n",rct,eol5);
printf("c2z_arth.c #99 rct = %d eol6 = %d\n",rct,eol6);
printf("c2z_arth.c #99 rct = %d eol7 = %d\n",rct,eol7);
printf("c2z_arth.c #99 rct = %d eol8 = %d\n",rct,eol8);
printf("c2z_arth.c #99 rct = %d eol9 = %d\n",rct,eol9);
*/

    /****************************************************
    *  Clear out C370MATH Stores working answer         *
    *************************************************** */
    strcpy(a_string, "         LARL  R9,C370MATH");
    src_line();
    strcpy(trace_1, "c2z_arth c2_math_start #100");
    trace_rec_3();
    work_use_ct[39]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    strcpy(trace_1, "c2z_arth c2_math_start #101");
    trace_rec_3();
    
    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    strcpy(trace_1, "c2z_arth c2_math_start #102");
    trace_rec_3();
     
    if(fd2_type == 1)
    {
       strcpy(a_string, "         LAEY  R5,");
       strcat(a_string, field2);
       strcpy(wk_remark, " ");
       strcat(wk_remark, field2);
       strcat(wk_remark, " */");
       write_remark();
       strcpy(trace_1, "c2z_arth c2_math_start #103");
       trace_rec_3();
       
       strcpy(a_string, "         LARL  R9,C370U");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #104");
       trace_rec_3();
       work_use_ct[48]++;

       strcpy(a_string, "         CVD   R5,0(R9)");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #105");
       trace_rec_3();
       
       strcpy(a_string, "         LARL  R9,C370NWK1");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #106");
       trace_rec_3();
       work_use_ct[49]++;

       strcpy(a_string, "         LARL  R8,C370U");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #107");
       trace_rec_3();
       work_use_ct[48]++;

       strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #108");
       trace_rec_3();
       
       strcpy(a_string, "         LARL  R9,C370MATH");
       src_line();
       strcpy(trace_1, "c2z_arth.c c2_math_start #109");
       trace_rec_3();
       work_use_ct[39]++;

       strcpy(a_string, "         LARL  R8,C370NWK1");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #110");
       trace_rec_3();
       work_use_ct[49]++;

       strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #111");
       trace_rec_3();
    }

    if(fd2_type == 2)
    {
      x3 = 0;
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
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field2, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field2a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
 
      if (x3 == 0) 
      {
        printf("\nc2z_arth c2_math_start #003 field2 = %s\n", field2);
        printf("c2z_arth c2_math_start rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
 
       strcpy(a_string, "         LARL  R9,C370MATH");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #112");
       trace_rec_3();
       work_use_ct[39]++;

       strcpy(a_string, "         LARL  R8,");
       strcat(a_string, field2a);
       strcpy(wk_remark, " ");
       strcat(wk_remark, field2);
       strcat(wk_remark, " */");
       write_remark();
       strcpy(trace_1, "c2z_arth c2_math_start #113");
       trace_rec_3();
       
       strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #114");
       trace_rec_3();
    }
    
    if (operand_1 == 0) 
    {
       p = strstr(field3, "+");
       if (p)
       {
         operand_1 = 1;
       }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "-");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "*");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "/");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if(fd4_type == 1)
    {
       strcpy(a_string, "         LAEY  R5,");
       strcat(a_string, field4);
       strcpy(wk_remark, " ");
       strcat(wk_remark, field4);
       strcat(wk_remark, " */");
       write_remark();
       strcpy(trace_1, "c2z_arth c2_math_start #115");
       trace_rec_3();
       
       strcpy(a_string, "         LARL  R9,C370U");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #116");
       trace_rec_3();
       work_use_ct[48]++;

       strcpy(a_string, "         CVD   R5,0(R9)");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #117");
       trace_rec_3();
       
       strcpy(a_string, "         LARL  R8,C370NWK1");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #118");
       trace_rec_3();
       work_use_ct[49]++;

       strcpy(a_string, "         LARL  R7,C370U");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #119");
       trace_rec_3();
       work_use_ct[48]++;

       strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #120");
       trace_rec_3();
    }

    if(fd4_type == 2)
    {
      p = strstr(field4,"()");
      if(p)
      {
        x99 = 0;
        pi3 = 0;
        pi4 = 0;
        ch = field4[pi3];
        while(ch != '(')
        {
          field4a[pi4] = ch;
          pi4++;
          pi3++;
          ch = field4[pi3];
        }
        field4a[pi4] = '\0';
        strcpy(field4, field4a);
        x99 = 1;
      }

      if(x99 == 0)
      {
        x3 = 0;
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field4, lw_variable[v].lv_name);
          ret1 = strcmp(sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(field4a, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
  
        if (x3 == 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(field4, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
              strcpy(field4a, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }
 
        if (x3 == 0) 
        {
          printf("\nc2z_arth c2_math_start #004 field4 = %s\n", field4);
          printf("c2z_arth c2_math_start rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
      }
 
      if(x99 == 0)
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field4a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field4);
        strcat(wk_remark, " */");
        write_remark();
        strcpy(trace_1, "c2z_arth c2_math_start #121");
        trace_rec_3();
      }

      if(x99 == 1)
      {
        x3 = 0;
        if (fn_ct > 0) 
        {
          for (I = 0; I < fn_ct; I++) 
          {
            ret = strcmp(field4, w_function[I].fn_name);
            if (ret == 0) 
            {
              strcpy(field4a, w_function[I].fn_cname);
              strcpy(field4b, w_function[I].fn_ret_var);
              x3 = 1;
              strcpy(wk_sv_func, field4);
            }
          }
        }

        strcpy(a_string, "         LARL  R15,");
        strcat(a_string, field4a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field4);
        strcat(wk_remark, " */");
        write_remark();
        strcpy(trace_1, "c2z_arth c2_math_start #122");
        trace_rec_3();
        
        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        strcpy(trace_1, "c2z_arth c2_math_start #123");
        trace_rec_3();
        
        x3 = 0;
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(field4b, lw_variable[v].lv_name);
          ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(field4c, lw_variable[v].lv_cname);
            lw_variable[v].lv_use_ct++;
          }
        }
  
        if (x3 == 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(field4b, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
              strcpy(field4c, gw_variable[v].gv_cname);
              gw_variable[v].gv_use_ct++;
            }
          }
        }

        if (x3 == 0) 
        {
          printf("\nc2z_arth c2_math_start #204 field4b = %s\n", field4b);
          printf("c2z_arth c2_math_start rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
      }
    }

    if(operand_1 == 1)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #124");
      trace_rec_3();
      work_use_ct[39]++;

      if(fd2_type == 1) 
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        strcpy(trace_1, "c2z_arth c2_math_start #125");
        trace_rec_3();
        work_use_ct[49]++;
      }

      if(fd4_type == 2) 
      {
         if(x99 == 0)
         {
           strcpy(a_string, "         LARL  R8,");
           strcat(a_string, field4a);
           strcpy(wk_remark, " ");
           strcat(wk_remark, field4);
           strcat(wk_remark, " */");
           write_remark();
           strcpy(trace_1, "c2z_arth c2_math_start #126");
           trace_rec_3();
         }
  
         if(x99 == 1)
         {
             strcpy(a_string, "         LARL  R8,");
             strcat(a_string, field4c);
             strcpy(wk_remark, " ");
             strcat(wk_remark, field4b);
             strcat(wk_remark, " */");
             write_remark();
             strcpy(trace_1, "c2z_arth c2_math_start #127");
             trace_rec_3();
          }
      }

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #128");
      trace_rec_3();
    }

    if(operand_1 == 2)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #129");
      trace_rec_3();
      work_use_ct[39]++;

      if(fd4_type == 1)
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        strcpy(trace_1, "c2z_arth c2_math_start #130");
        trace_rec_3();
        work_use_ct[49]++;
      }

      if(fd4_type == 2)
      {
         if(x99 == 0)
         {
           strcpy(a_string, "         LARL  R8,");
           strcat(a_string, field4a);
           strcpy(wk_remark, " ");
           strcat(wk_remark, field4);
           strcat(wk_remark, " */");
           write_remark();
           strcpy(trace_1, "c2z_arth c2_math_start #131");
           trace_rec_3();
         }

         if(x99 == 1)
         {
            strcpy(a_string, "         LARL  R8,");
            strcat(a_string, field4c);
            strcpy(wk_remark, " ");
            strcat(wk_remark, field4b);
            strcat(wk_remark, " */");
            write_remark();
            strcpy(trace_1, "c2z_arth c2_math_start #132");
            trace_rec_3();
         }
       }

       strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #133");
       trace_rec_3();
    }

    if(operand_1 == 3)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #134");
      trace_rec_3();
      work_use_ct[39]++;

      if(fd2_type == 1)
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        strcpy(trace_1, "c2z_arth c2_math_start #135");
        trace_rec_3();
        work_use_ct[49]++;
      }

      if(fd4_type == 2)
      {
         if(x99 == 0)
         {
           strcpy(a_string, "         LARL  R8,");
           strcat(a_string, field4a);
           strcpy(wk_remark, " ");
           strcat(wk_remark, field4);
           strcat(wk_remark, " */");
           write_remark();
           strcpy(trace_1, "c2z_arth c2_math_start #136");
           trace_rec_3();
         }

         if(x99 == 1)
         {
            strcpy(a_string, "         LARL  R8,");
            strcat(a_string, field4c);
            strcpy(wk_remark, " ");
            strcat(wk_remark, field4b);
            strcat(wk_remark, " */");
            write_remark();
            strcpy(trace_1, "c2z_arth c2_math_start #137");
            trace_rec_3();
         }
      }

      strcpy(a_string, "         MP    0(9,R9),0(6,R8)");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #138");
      trace_rec_3();
    }

    if(operand_1 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #139");
      trace_rec_3();
      work_use_ct[40]++;
     
      strcpy(a_string, "         LARL  R8,C370MATH");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #140");
      trace_rec_3();
      work_use_ct[39]++;

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #141");
      trace_rec_3();
      
      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #142");
      trace_rec_3();
      work_use_ct[43]++;

      if(fd2_type == 1) 
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        strcpy(trace_1, "c2z_arth c2_math_start #143");
        trace_rec_3();
        work_use_ct[49]++;
      }

      if(fd2_type == 2)
      {
         if(x99 == 0)
         {
           strcpy(a_string, "         LARL  R8,");
           strcat(a_string, field4a);
           strcpy(wk_remark, " ");
           strcat(wk_remark, field4);
           strcat(wk_remark, " */");
           write_remark();
           strcpy(trace_1, "c2z_arth c2_math_start #144");
           trace_rec_3();
         }

         if(x99 == 1)
         {
            strcpy(a_string, "         LARL  R8,");
            strcat(a_string, field4c);
            strcpy(wk_remark, " ");
            strcat(wk_remark, field4b);
            strcat(wk_remark, " */");
            write_remark();
            strcpy(trace_1, "c2z_arth c2_math_start #145");
            trace_rec_3();
         }
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #146");
      trace_rec_3();
      
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #147");
      trace_rec_3();
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #148");
      trace_rec_3();
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #149");
      trace_rec_3();
      
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #150");
      trace_rec_3();
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370IENT");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #151");
      trace_rec_3();
      work_use_ct[43]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(1,R8)");
      src_line();
      strcpy(trace_1, "c2z_arth c2_math_start #152");
      trace_rec_3();
    }

    if(eol1 == 1)
    {
       goto eol_finish;
    }

    operand_2 = 0;
    if (operand_2 == 0) 
    {
       p = strstr(field5, "+");
       if (p)
       {
         operand_2 = 1;
       }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, "-");
      if (p)
      {
        operand_2 = 2;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, "*");
      if (p)
      {
        operand_2 = 3;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, "/");
      if (p)
      {
        operand_2 = 4;
      }
    }

    if(fd6_type == 1)
    {
       strcpy(a_string, "         LAEY  R5,");
       strcat(a_string, field6);
       strcpy(wk_remark, " ");
       strcat(wk_remark, field6);
       strcat(wk_remark, " */");
       write_remark();
       strcpy(trace_1, "c2z_arth c2_math_start #153");
       trace_rec_3();
       
       strcpy(a_string, "         LARL  R9,C370U");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #154");
       trace_rec_3();
       work_use_ct[48]++;

       strcpy(a_string, "         CVD   R5,0(R9)");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #155");
       trace_rec_3();
       
       strcpy(a_string, "         LARL  R9,C370NWK1");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #156");
       trace_rec_3();
       work_use_ct[49]++;

       strcpy(a_string, "         LARL  R8,C370U");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #157");
       trace_rec_3();
       work_use_ct[48]++;

       strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
       src_line();
       strcpy(trace_1, "c2z_arth c2_math_start #158");
       trace_rec_3();
    }

    if(fd6_type == 2)
    {
      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field6, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field6a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field6, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field6a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
 
      if (x3 == 0) 
      {
        printf("\nc2z_arth c2_math_start #005 field6 = %s\n", field6);
        printf("c2z_arth c2_math_start rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
 
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field6a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field6);
      strcat(wk_remark, " */");
      write_remark();
      strcpy(trace_1, "c2z_arth c2_math_start #159");
      trace_rec_3();
    }

    if(operand_2 == 1)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth c2_math_start #160");
        trace_rec_3();
      }
      work_use_ct[39]++;

      if(fd6_type == 1) 
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth c2_math_start #161");
          trace_rec_3();
        }
        work_use_ct[49]++;
      }

      if(fd6_type == 2) 
      {
         strcpy(a_string, "         LARL  R8,");
         strcat(a_string, field6a);
         strcpy(wk_remark, " ");
         strcat(wk_remark, field6);
         strcat(wk_remark, " */");
         write_remark();
         if (puncde == 1) 
         {
           strcpy(trace_1, "c2z_arth.c c2_math_start #162");
           trace_rec_3();
        }
      }

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
         strcpy(trace_1, "c2z_arth.c c2_math_start #163");
         trace_rec_3();
      }
    }

    if(operand_2 == 2)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #164");
        trace_rec_3();
      }
      work_use_ct[39]++;

      if(fd6_type == 1)
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #165");
          trace_rec_3();
        }
        work_use_ct[49]++;
      }

      if(fd6_type == 2)
      {
         strcpy(a_string, "         LARL  R8,");
         strcat(a_string, field6a);
         strcpy(wk_remark, " ");
         strcat(wk_remark, field6);
         strcat(wk_remark, " */");
         write_remark();
         if (puncde == 1) 
         {
           strcpy(trace_1, "c2z_arth.c c2_math_start #166");
           trace_rec_3();
         }
       }

       strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
       src_line();
       if (puncde == 1) 
       {
           strcpy(trace_1, "c2z_arth.c c2_math_start #167");
           trace_rec_3();
       }
    }

    if(operand_2 == 3)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #168");
        trace_rec_3();
      }
      work_use_ct[39]++;

      if(fd6_type == 1)
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #169");
          trace_rec_3();
        }
        work_use_ct[49]++;
      }

      strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
         strcpy(trace_1, "c2z_arth.c c2_math_start #170");
         trace_rec_3();
      }
    }

    if(operand_2 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #171");
        trace_rec_3();
      }
      work_use_ct[40]++;
     
      strcpy(a_string, "         LARL  R8,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #172");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #173");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #174");
        trace_rec_3();
      }
      work_use_ct[43]++;

      if(fd6_type == 1) 
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #175");
          trace_rec_3();
        }
        work_use_ct[49]++;
      }

      if(fd6_type == 2)
      {
         strcpy(a_string, "         LARL  R8,");
         strcat(a_string, field6a);
         strcpy(wk_remark, " ");
         strcat(wk_remark, field6);
         strcat(wk_remark, " */");
         write_remark();
         if (puncde == 1) 
         {
           strcpy(trace_1, "c2z_arth.c c2_math_start #176");
           trace_rec_3();
        }
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #177");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #178");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #179");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #180");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #181");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370IENT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #182");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(1,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #183");
        trace_rec_3();
      }
    }

    if(eol2 == 1)
    {
       goto eol_finish;
    }

    operand_3 = 0;
    if (operand_3 == 0) 
    {
       p = strstr(field7, "+");
       if (p)
       {
         operand_3 = 1;
       }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field7, "-");
      if (p)
      {
        operand_3 = 2;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field7, "*");
      if (p)
      {
        operand_3 = 3;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field7, "/");
      if (p)
      {
        operand_3 = 4;
      }
    }

    if(fd8_type == 1)
    {
       strcpy(a_string, "         LAEY  R5,");
       strcat(a_string, field8);
       strcpy(wk_remark, " ");
       strcat(wk_remark, field8);
       strcat(wk_remark, " */");
       write_remark();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_arth.c c2_math_start #184");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R9,C370U");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_arth.c c2_math_start #185");
         trace_rec_3();
       }
       work_use_ct[48]++;

       strcpy(a_string, "         CVD   R5,0(R9)");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_arth.c c2_math_start #186");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R9,C370NWK1");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_arth.c c2_math_start #187");
         trace_rec_3();
       }
       work_use_ct[49]++;

       strcpy(a_string, "         LARL  R8,C370U");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_arth.c c2_math_start #188");
         trace_rec_3();
       }
       work_use_ct[48]++;

       strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_arth.c c2_math_start #189");
         trace_rec_3();
       }
    }

    if(fd8_type == 2)
    {
      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field8, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field8a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field8, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field8a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
 
      if (x3 == 0) 
      {
        printf("\nc2z_arth.c c2_math_start arth-005 field8 Not Found = %s\n", field8);
        printf("c2z_arth.c c2_math_start rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
 
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field8a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field8);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #190");
        trace_rec_3();
      }
    }

    if(operand_3 == 1)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #191");
        trace_rec_3();
      }
      work_use_ct[39]++;

      if(fd8_type == 1) 
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #192");
          trace_rec_3();
        }
        work_use_ct[49]++;
      }

      if(fd8_type == 2) 
      {
         strcpy(a_string, "         LARL  R8,");
         strcat(a_string, field8a);
         strcpy(wk_remark, " ");
         strcat(wk_remark, field8);
         strcat(wk_remark, " */");
         write_remark();
         if (puncde == 1) 
         {
           strcpy(trace_1, "c2z_arth.c c2_math_start #193");
           trace_rec_3();
        }
      }

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
         strcpy(trace_1, "c2z_arth.c c2_math_start #194");
         trace_rec_3();
      }
    }

    if(operand_3 == 2)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #195");
        trace_rec_3();
      }
      work_use_ct[39]++;

      if(fd8_type == 1)
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #196");
          trace_rec_3();
        }
        work_use_ct[49]++;
      }

      if(fd8_type == 2)
      {
         strcpy(a_string, "         LARL  R8,");
         strcat(a_string, field8a);
         strcpy(wk_remark, " ");
         strcat(wk_remark, field8);
         strcat(wk_remark, " */");
         write_remark();
         if (puncde == 1) 
         {
           strcpy(trace_1, "c2z_arth.c c2_math_start #197");
           trace_rec_3();
         }
       }

       strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
       src_line();
       if (puncde == 1) 
       {
           strcpy(trace_1, "c2z_arth.c c2_math_start #198");
           trace_rec_3();
       }
    }

    if(operand_3 == 3)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #199");
        trace_rec_3();
      }
      work_use_ct[39]++;

      if(fd8_type == 1)
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #200");
          trace_rec_3();
        }
        work_use_ct[49]++;
      }

      strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
         strcpy(trace_1, "c2z_arth.c c2_math_start #201");
         trace_rec_3();
      }
    }

    if(operand_3 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #202");
        trace_rec_3();
      }
      work_use_ct[40]++;
     
      strcpy(a_string, "         LARL  R8,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #203");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #204");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #205");
        trace_rec_3();
      }
      work_use_ct[43]++;

      if(fd8_type == 1) 
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #206");
          trace_rec_3();
        }
        work_use_ct[49]++;
      }

      if(fd8_type == 2)
      {
         strcpy(a_string, "         LARL  R8,");
         strcat(a_string, field8a);
         strcpy(wk_remark, " ");
         strcat(wk_remark, field8);
         strcat(wk_remark, " */");
         write_remark();
         if (puncde == 1) 
         {
           strcpy(trace_1, "c2z_arth.c c2_math_start #207");
           trace_rec_3();
        }
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #208");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #209");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #210");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #211");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #212");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370IENT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #213");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(1,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #214");
        trace_rec_3();
      }
    }

    if(eol3 == 1)
    {
       goto eol_finish;
    }

    operand_4 = 0;
    if (operand_4 == 0) 
    {
       p = strstr(field9, "+");
       if (p)
       {
         operand_4 = 1;
       }
    }

    if (operand_4 == 0) 
    {
      p = strstr(field9, "-");
      if (p)
      {
        operand_4 = 2;
      }
    }

    if (operand_4 == 0) 
    {
      p = strstr(field9, "*");
      if (p)
      {
        operand_4 = 3;
      }
    }

    if (operand_4 == 0) 
    {
      p = strstr(field9, "/");
      if (p)
      {
        operand_4 = 4;
      }
    }

    if(fd10_type == 1)
    {
       strcpy(a_string, "         LAEY  R5,");
       strcat(a_string, field10);
       strcpy(wk_remark, " ");
       strcat(wk_remark, field10);
       strcat(wk_remark, " */");
       write_remark();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_arth.c c2_math_start #215");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R9,C370U");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_arth.c c2_math_start #216");
         trace_rec_3();
       }
       work_use_ct[48]++;

       strcpy(a_string, "         CVD   R5,0(R9)");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_arth.c c2_math_start #217");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R9,C370NWK1");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_arth.c c2_math_start #218");
         trace_rec_3();
       }
       work_use_ct[49]++;

       strcpy(a_string, "         LARL  R8,C370U");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_arth.c c2_math_start #219");
         trace_rec_3();
       }
       work_use_ct[48]++;

       strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_arth.c c2_math_start #220");
         trace_rec_3();
       }
    }

    if(fd10_type == 2)
    {
      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field10, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field10a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field10, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field10a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
 
      if (x3 == 0) 
      {
        printf("\nc2z_arth.c c2_math_start arth-005 field10 Not Found = %s\n", field10);
        printf("c2z_arth.c c2_math_start rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
 
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field10a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field10);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #122");
        trace_rec_3();
      }
    }

    if(operand_4 == 1)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #123");
        trace_rec_3();
      }
      work_use_ct[39]++;

      if(fd10_type == 1) 
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #124");
          trace_rec_3();
        }
        work_use_ct[49]++;
      }

      if(fd10_type == 2) 
      {
         strcpy(a_string, "         LARL  R8,");
         strcat(a_string, field10a);
         strcpy(wk_remark, " ");
         strcat(wk_remark, field10);
         strcat(wk_remark, " */");
         write_remark();
         if (puncde == 1) 
         {
           strcpy(trace_1, "c2z_arth.c c2_math_start #125");
           trace_rec_3();
        }
      }

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
         strcpy(trace_1, "c2z_arth.c c2_math_start #126");
         trace_rec_3();
      }
    }

    if(operand_4 == 2)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #127");
        trace_rec_3();
      }
      work_use_ct[39]++;

      if(fd10_type == 1)
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #128");
          trace_rec_3();
        }
        work_use_ct[49]++;
      }

      if(fd10_type == 2)
      {
         strcpy(a_string, "         LARL  R8,");
         strcat(a_string, field10a);
         strcpy(wk_remark, " ");
         strcat(wk_remark, field10);
         strcat(wk_remark, " */");
         write_remark();
         if (puncde == 1) 
         {
           strcpy(trace_1, "c2z_arth.c c2_math_start #125");
           trace_rec_3();
         }
       }

       strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
       src_line();
       if (puncde == 1) 
       {
           strcpy(trace_1, "c2z_arth.c c2_math_start #129");
           trace_rec_3();
       }
    }

    if(operand_4 == 3)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #130");
        trace_rec_3();
      }
      work_use_ct[39]++;

      if(fd10_type == 1)
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #131");
          trace_rec_3();
        }
        work_use_ct[49]++;
      }

      strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
         strcpy(trace_1, "c2z_arth.c c2_math_start #132");
         trace_rec_3();
      }
    }

    if(operand_4 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #133");
        trace_rec_3();
      }
      work_use_ct[40]++;
     
      strcpy(a_string, "         LARL  R8,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #134");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #135");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #136");
        trace_rec_3();
      }
      work_use_ct[43]++;

      if(fd10_type == 1) 
      {
        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #137");
          trace_rec_3();
        }
        work_use_ct[49]++;
      }

      if(fd10_type == 2)
      {
         strcpy(a_string, "         LARL  R8,");
         strcat(a_string, field10a);
         strcpy(wk_remark, " ");
         strcat(wk_remark, field10);
         strcat(wk_remark, " */");
         write_remark();
         if (puncde == 1) 
         {
           strcpy(trace_1, "c2z_arth.c c2_math_start #125");
           trace_rec_3();
        }
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #138");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #140");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #140");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #141");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #142");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370IENT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #143");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(1,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #144");
        trace_rec_3();
      }
    }

    if(eol4 == 1)
    {
       goto eol_finish;
    }























printf("error error\n");

    eol_finish:

    x3 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field1a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
      }
    }
  
    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field1, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field1a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
        }
      }
    }
 
    if (x3 == 0) 
    {
      printf("\nc2z_arth c2_math_start #002 field1 = %s\n", field1);
      printf("c2z_arth c2_math_start rct = %d p_string = %s", rct, p_string);
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
    strcpy(trace_1, "c2z_arth c2_math_start #900");
    trace_rec_3();
    
    strcpy(a_string, "         LARL  R8,C370MATH");
    src_line();
    strcpy(trace_1, "c2z_arth c2_math_start #901");
    trace_rec_3();
    work_use_ct[39]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    strcpy(trace_1, "c2z_arth c2_math_start #902");
    trace_rec_3();
    
  convert = 1;
  return;
}
