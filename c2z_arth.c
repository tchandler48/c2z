/* *************************************************************
*  c2z.arth Math Parser                                        *
*  Copyright TCCS (c) 2015 - 2021                              *
* ************************************************************ */

void c2z_math_start()
{
printf("\nc2z_math_start rct = %d p_string = %s\n",rct,p_string);
  int pi;
  int s = 0;
  int I = 0;
  int pi2 = 0;
  int x2 = 0;
  int x3 = 0;
/*  int x30 = 0; */
  int v;
/*  int eol = 0; */
  int x70 = 0;
  int x71 = 0;

  int ret = 0;
  int ret1 = 0;
  int fd1_type = 0;
/*  int fd2_type = 0; */
  int fd3_type = 0;
  int fd4_type = 0;
  int fd5_type = 0;
/*  int fd6_type = 0; */
  int eol1 = 0;
  int eol2 = 0;

  char ch;
  char *p15,*p16;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
/*  char field2[VAR_LGTH]; */
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
/*  char field5[VAR_LGTH]; */
/*  char field6[VAR_LGTH]; */
  char *p;

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

printf("c2z_arth.c HERE #1\n");
  s = strlen(p_string);
  s--;
  s--;

  pi = 0;
  ch = p_string[pi];
  for (I = 0; I < s; I++) 
  {
    if (ch == '+')
    {
   /*   x30 = 1; */
    }
 
    if (ch == '-')
    {
   /*   x30 = 1; */
    }

    if (ch == '*')
    {
  /*    x30 = 1; */
    }

    if (ch == '/')
    {
  /*    x30 = 1; */
    }
    pi++;
    ch = p_string[pi];
  }
printf("c2z_arth.c HERE #2\n");

  pi = 0;
  ch = p_string[pi];
    while((ch == ' ') || (ch == '{'))
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
printf("c2z_arth.c field1 %s\n",field1);

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
 /*     field2[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  /*  field2[pi2] = '\0';
printf("c2z_arth.c field2 = %s\n"); */

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
printf("c2z_arth.c field3 = %s\n",field3);

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
printf("c2z_arth.c field4 = %s fd4_type = %d\n",field4,fd4_type);

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
 /*     field5[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
/*    field5[pi2] = '\0'; */

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
   /*       fd6_type = 2; */
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
  /*        fd6_type = 1; */
          x2 = 1;
        }
      }
 /*     field6[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
/*    field6[pi2] = '\0'; */
    if(eol2 == 1)
    {
       goto eolmath_1;
    }

    eolmath_1:

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
       /* eol = 1; */
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
   /*   field5[pi2] = ch; */
      pi2++;
      pi++;
      ch = p_string[pi];
    }
 /*   field5[pi2] = '\0'; */

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
