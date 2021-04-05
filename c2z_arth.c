
int c2z_math_start()
{
  int pi;
  int pi1 = 0;
  int s = 0;
  int I = 0;
  int pi2 = 0;
  int x2 = 0;
  int x3 = 0;
  int x30 = 0;
  int x31 = 0;
  int v;
  int eol = 0;
  int x70 = 0;
  int x71 = 0;

  int ret = 0;
  int ret1 = 0;
  int fd1_type = 0;
  int fd2_type = 0;
  int fd3_type = 0;
  int fd4_type = 0;
  int fd5_type = 0;
  int fd6_type = 0;
  int fd7_type = 0;
  int fd9_type = 0;
  int fd11_type = 0;
  int fd13_type = 0;
  int operand_1 = 0;
  int operand_2 = 0;
  int operand_3 = 0;
  int operand_4 = 0;
  int operand_5 = 0;
  int eol1 = 0;
  int eol2 = 0;

  char ch;
  char *p15,*p16;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field1b[VAR_LGTH];
  char field1m[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field3b[VAR_LGTH];
  char field3m[VAR_LGTH];
  char field4[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field5b[VAR_LGTH];
  char field5m[VAR_LGTH];
  char field6[VAR_LGTH];
  char field6a[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];
  char field8[VAR_LGTH];
  char field8a[VAR_LGTH];
  char field9[VAR_LGTH];
  char field9a[VAR_LGTH];
  char field10[VAR_LGTH];
  char field10a[VAR_LGTH];
  char field11[VAR_LGTH];
  char field11a[VAR_LGTH];
  char field12[VAR_LGTH];
  char field12a[VAR_LGTH];
  char field13[VAR_LGTH];
  char field13a[VAR_LGTH];
  char field14[VAR_LGTH];
  char field14a[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];

  char wk_sv_func[VAR_LGTH];

  char *p, *p1;

  p = strstr(p_string, "char");
  if (p) 
  {
    return;
  }

  x70 = 0;
  x71 = 0;
  p = strstr(p_string, "+=");	/* offset += param;  or offset += 2;  */
  if(p)
  {
    x70 = 1;
  }
  p = strstr(p_string, "*=");	/* offset += param;  or offset += 2;  */
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
        printf("\nc2z_arth.c c2_math_start math-001 += field1 Not Found = %s\n", field1);
        printf("c2z_arth.c c2_math_start rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #001");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #002");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #003");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #004");
        trace_rec_3();
      }
       
      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #005");
        trace_rec_3();
      }
      work_use_ct[48]++;
 
      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #006");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #007");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #008");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #009");
        trace_rec_3();
      }
       
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #010");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      strcpy(wk_remark," ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #011");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #012");
        trace_rec_3();
      }

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #013");
        trace_rec_3();
      }

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
        printf("\nc2z_math.c c2_math_99 math-135 += field1 Not Found = %s\n", field1);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
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
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #014");
        trace_rec_3();
      }
    
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
        printf("\nc2z_math.c c2_math_99 math-136 += field1 Not Found = %s\n", field3);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
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
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_arth.c c2_math_start #015");
        trace_rec_3();
      }

      if(x70 == 1)
      {
        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #016");
          trace_rec_3();
        }
      }

      if(x71 == 1)
      {
        strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_arth.c c2_math_start #017");
          trace_rec_3();
        }
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

    pi++;
    ch = p_string[pi];
  }


printf("c2z.arth.c  #0  rct = %d p_string = %s\n",rct,p_string);

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
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';
printf("c2z_arth.c #1  rct = %d field1 = %s\n",rct,field1);

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
printf("c2z_arth.c #2  rct = %d fd2_type = %d field2 = %s\n",rct,fd2_type,field2);

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
printf("c2z_arth.c #3  rct = %d field3 = %s\n",rct,field3);

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
printf("c2z_arth.c #4  rct = %d fd4_type = %d field4 = %s\n",rct,fd4_type,field4);

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
printf("c2z_arth.c #5  rct = %d field5 = %s\n",rct,field5);

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
printf("c2z_arth.c #6  rct = %d fd6_type = %d field6 = %s\n",rct,fd6_type,field6);

    if(eol2 == 1)
    {
       goto eolmath_1;
    }















    eolmath_1:
printf("c2z_arth.c #99 rct = %d eol1 = %d\n",rct,eol1);
printf("c2z_arth.c #99 rct = %d eol2 = %d\n",rct,eol2);

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
    
    s = strlen(p_string);
    fd5_type = 0;
    s--;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ') 
    {
      if(ch == ';')
      {
        eol = 1;
        break;
      }
      if(pi >= s)
      {
        break;
      }
      if(fd5_type == 1)
      {
        if(ch == ')')
        {
          break;
        }
      }
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd5_type = 2;
            x2 = 1;
          }
          if (isdigit(ch)) 
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

    p15 = strstr(field1,"[");
    p16 = strstr(field1, "]");


    if((!p15) && (!p16))
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
        printf("\nc2z_math.c c2_math_99 math-105 x30-1 field1 Not Found = %s\n", field1);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }



































  convert = 1;
  return;
}
