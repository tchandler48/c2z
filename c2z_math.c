/* ***************************************************
*  c2z : c2z_math.c :                                *
*                                                    *
*  next error math-139                               *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ****************************************************************************
*      Math functions ( =, +, -, *, / ) MUST BE LAST CALL IN PARSER           *
* *************************************************************************** */

void c2_math() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math START");
    trace_rec_1();
  }

  char *p, *p1, *p2, *p8, *p9;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field5[VAR_LGTH];

  int pi = 0;
  int pi2 = 0;
  int x = 0;
  int x1 = 0;
  int x2 = 0;
  int x3 = 0;
  int x20 = 0;
  int x72 = 0;
  int x73 = 0;
  int x100;
  int op_1 = 0;
  int L1 = 0;
  int R1 = 0;
  int L2 = 0;
  int R2 = 0;
  int I = 0;
  int s = 0;
  int ret = 0;
  int math_plus = 0;
  int math_minus = 0;
  int math_mult = 0;
  int math_div = 0;
  int math = 0;
  int math1 = 0;
  int l_bracket = 0;
  int x501 = 0;
  int x501L1 = 0;
  int x501R1 = 0;
  int x501L2 = 0;
  int x501R2 = 0;

  x100 = 0;
  
  s = strlen(p_string);
  for(I = 0; I < s; I++)
  {
    if(p_string[I] == '=')
    {
      x501 = I;
    }
    if(p_string[I] == '[')
    {
      if(x501 == 0)
      {
        x501L1++;
      }
      else
      {
        x501L2++;
      }
    }
    if(p_string[I] == ']')
    { 
      if(x501 == 0)
      {
        x501R1++;
      }
      else
      {
        x501R2++;
      }
    }
  }
/* printf("c2z_math.c x500 = %d x501L1 = %d x501R1 = %d x501L2 = %d x501R2 = %d\n",x500,x501L1,x501R1,x501L2,x501R2); */


  p1 = strstr(p_string, "->");
  if(p1)
  {
    c2_math_700();
    convert = 1;
    return;
  }

  if((x501L1 == 1) && (x501R1 == 1) && (x501L2 == 2) && (x501R2 == 2))
  {
printf("INSIDE L = 2 R = 4 \n");
   convert = 1;
   return;
  }


  if(x100 == 4)	/* Math 2 dim INT array */
  {
    c2_math_601();
    convert = 1;
    return;
  }

  if(x100 == 6)	/* Math 2 dim CHAR array */
  {
    c2_math_600();
    convert = 1;
    return;
  }

  p = strstr(p_string, "=");
  if (p) 
  {
    x20 = 0;
    p2 = strstr(p_string, "[(");
    if (p2) 
    {
      x20 = 1;
    }

    math = 0;
    s  = strlen(p_string);
    p2 = strstr(p_string, "-1");

    if (!p2) 
    {
      for (I = 0; I < s; I++) 
      {
        p1 = strstr(p_string, "/*");
        if (p1) 
        {
          break;
        }
        ch = p_string[I];
        if (ch == '+') 
        {
          math_plus++;
          math = 1;
        }

        if ((ch == '-') && (math1 == 0)) 
        {
          math_minus++;
          math = 1;
        }

        if (ch == '*') 
        {
          math_mult++;
          math = 1;
        }

        if (ch == '/') 
        {
          math_div++;
          math = 1;
        }
      }

      if ((math == 1) && (x20 == 0)) 
      {
        c2_math_99();
        return;
      }
    }

    if (p2) 
    {
      l_bracket = 0;
      p = strstr(p_string, "[");
      p1 = strstr(p_string, ";");

      s = p - p_string;
      x1 = p1 - p_string;

    
      if((p) && (s < x1))
      {
        l_bracket = 1;
      }

      if(l_bracket == 0)
      {
        pi = 0;
        ch = p_string[pi];
        while((ch == ' ') || (ch == '\t') || (ch == '{'))
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
        ch = p_string[pi];
        while(ch != ' ')
        {
          field1[pi2] = ch;
          pi2++;
          pi++;
          ch = p_string[pi];
        }
        field1[pi2] = '\0';

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
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field1, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
              strcpy(field1a, gw_variable[I].gv_cname);
              gw_variable[I].gv_use_ct++;
              break;
            }
          }
        }

        if (x3 == 0) 
        {
          printf("\nc2z_math.c c2_math math-001 field1 Not Found = %s\n", field1);
          printf("c2z_math.c c2_math rct = %d p_string = %s", rct, p_string);
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
          strcpy(trace_1, "c2z_math.c c2_math #80");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math #81");
          trace_rec_3();
        }
        work_use_ct[82]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math #82");
          trace_rec_3();
        }
       convert = 1;
       return;
      }

      if(l_bracket == 1)
      {

        pi = 0;
        ch = p_string[pi];
        while((ch == ' ') || (ch == '\t') || (ch == '{'))
        {
          pi++;
          ch = p_string[pi];
        }

        pi2 = 0;
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
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field1, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
              strcpy(field1a, gw_variable[I].gv_cname);
              strcpy(field5,gw_variable[I].gv_table);
              gw_variable[I].gv_use_ct++;
              break;
            }
          }
        }

        if (x3 == 0) 
        {
          printf("\nc2z_math.c c2_math math-002 field1 Not Found = %s\n", field1);
          printf("c2z_math.c c2_math rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

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
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field2, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
              strcpy(field2a, gw_variable[I].gv_cname);
              gw_variable[I].gv_use_ct++;
              break;
            }
          }
        }

        if (x3 == 0) 
        {
          printf("\nc2z_math.c c2_math math-003 field2 Not Found = %s\n", field2);
          printf("c2z_math.c c2_math rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field5);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field5);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math #90");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math #91");
          trace_rec_3();
        }
        work_use_ct[82]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math #92");
          trace_rec_3();
        }
        convert = 1;
        return;
      }
    }
  }

  op_1 = 1;

  p8 = strchr(p_string, '(');
  p9 = strchr(p_string, ')');

  s = strlen(p_string);
  pi = 0;
  x = 0;
  x2 = 0;
  L1 = 0;
  R1 = 0;
  L2 = 0;
  R2 = 0;
  I = 0;

  ch = p_string[pi];
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if ((ch != '=') && (x2 != 1) && (x != 1)) 
    {
      if (ch == '[') 
      {
        L1++;
        x2 = 0;
      }
    }

    if (ch == '=') 
    {
      x = 1;
      x1 = I;
      break;
    }

    if ((x == 0) && (ch != ';')) 
    {
      if (ch == '[') 
      {
        R1++;
      }
    }
  }

  x2 = 0;
  for (I = x1; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[') 
    {
      L2++;
    }

    if (ch == ']') 
    {
      R2++;
    }
  }


  x72 = 0;
  x73 = 0;
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    if (ch == ';') 
    {
      break;
    }
    ch = p_string[I];
    if (ch == '(') 
    {
      x72++;
    }
    if (ch == ')') 
    {
      x73++;
    }
  }

  p = strstr(p_string, "(double)");
  if(p)
  {
    x72--;
    x73--;
  }

/* printf("c2z_math.c c2_math #1 rct = %d op_1 = %d L1 = %d R1 = %d L2 = %d R2 = %d x72 = %d x73 = %d\n",rct,op_1,L1,R1,L2,R2,x72,x73); */


  if ((op_1 == 1) && (L1 == 0) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (!p8) && (!p9)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_1 BRANCH");
      trace_rec_1();
    }

    c2_math_1();
    return;
  }

  if ((op_1 == 1) && (L1 == 0) && (R1 == 0) && (L2 == 1) && (R2 == 1) && (x72 == 0) && (x73 == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 BRANCH");
      trace_rec_1();
    }

    c2_math_2(); 
    return;
  }

  if ((op_1 == 1) && (L1 == 1) && (R1 == 1) && (L2 == 0) && (R2 == 0) && (x72 == 0) && (x73 == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 BRANCH");
      trace_rec_1();
    }

    c2_math_5();
    return;
  }

/*
  if ((op_1 == 1) && (L1 == 1) && (R1 == 1) && (L2 == 0) && (R2 == 0) && (x72 == 1) && (x73 == 1)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_58 BRANCH");
      trace_rec_1();
    }

    c2_math_58();
    return;
  }
*/

if ((op_1 == 1) && (L1 == 2) && (R1 == 2) && (L2 == 0) && (R2 == 0) && (x72 == 0) && (x73 == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 BRANCH");
      trace_rec_1();
    }

    c2_math_52();
    return;
  }

  if ((op_1 == 1) && (L1 == 1) && (R1 == 1) && (L2 == 0) && (R2 == 0) && (x72 > 0) && (x73 > 0) && (x20 == 1)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_51 BRANCH");
      trace_rec_1();
    }

    c2_math_51();
    return;
  }

  if ((op_1 == 1) && (L1 > 1) && (R1 == 0) && (L2 == 0) && (R2 == 0) && (x72 == 0) && (x73 == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_9 BRANCH");
      trace_rec_1();
    }

    c2_math_9();
    return;
  }

  if ((op_1 == 1) && (L1 == 1) && (L2 == 0) && (R2 == 0) && (x72 > 0) && (x73 > 0) && (x20 == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 BRANCH");
      trace_rec_1();
    }

    c2_math_7();
    return;
  }

  if ((op_1 == 1) && (x72 > 0) && (x73 > 0) && (L1 == 0) && (R1 == 0) && (math == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 BRANCH");
      trace_rec_1();
    }

    c2_math_6();
    return;
  }

  if ((L1 > 0) && (R1 > 0) && (L2 > 0) && (R2 > 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 BRANCH");
      trace_rec_1();
    }

    c2_math_98();
    return;
  }
}

/* ************************************
*   x = 7;                            *
************************************* */
void c2_math_1() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_1 START");
    trace_rec_1();
  }

  char ch, *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  int pi;
  int pi2;
  int fd1_id = 0;
  int fd2_id = 0;
  int fd1_type = 0;
  int fd2_type = 0;
  int fd1_status = 0;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int x80 = 0;
  int I = 0;
  int s = 0;
  int ret = 0;
  int ret1 = 0;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  fd1_type = 0;
  x2 = 0;
  pi2 = 0;
  x3 = 0;
  while ((ch != ' ') && (x3 == 0)) 
  {
    if (ch == '=') 
    {
      x3 = 1;
    } 
    else 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd1_type = 1;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd1_type = 2;
          x2 = 1;
        }
      }
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield1[pi2] = '\0';

  ret = strcmp(tfield1, "unsigned");
  if (ret == 0) 
  {
    fd1_type = 0;
    x2 = 0;
    pi2 = 0;
    x3 = 0;
    pi++;
    ch = p_string[pi];
    while ((ch != ' ') && (x3 == 0)) 
    {
      if (ch == '=') 
      {
        x3 = 1;
      } 
      else 
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd1_type = 1;
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
            fd1_type = 2;
            x2 = 1;
          }
        }
        tfield1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield1[pi2] = '\0';
  }

  ret = strcmp(tfield1, "double");
  if (ret == 0) 
  {
    fd1_type = 0;
    x2 = 0;
    pi2 = 0;
    x3 = 0;
    pi++;
    ch = p_string[pi];
    while ((ch != ' ') && (x3 == 0)) 
    {
      if (ch == '=') 
      {
        x3 = 1;
      } 
      else 
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd1_type = 1;
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
            fd1_type = 2;
            x2 = 1;
          }
        }
        tfield1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
    }
    tfield1[pi2] = '\0';
  }

  fd1_status = 0;
  x2 = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    x2 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x2 == 0)) 
    {
      x3 = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
      fd1_id = lw_variable[I].lv_id;
      p = strstr(lw_variable[I].lv_type, "I");
      if(p)
      {
        fd1_status = 1;
      }
      p = strstr(lw_variable[I].lv_type, "C");
      if(p)
      {
        fd1_status = 2;
      }
      break;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield1a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
        fd1_id = gw_variable[I].gv_id;
        p = strstr(gw_variable[I].gv_type, "I");
        if(p)
        {
          fd1_status = 1;
        }
        p = strstr(gw_variable[I].gv_type, "C");
        if(p)
        {
          fd1_status = 2;
        }
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_math.c c2_math_1 math-005 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_math.c c2_math_1 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch != '=') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  fd2_type = 0;
  pi2 = 0;
  x5 = 0;
  x4 = 0;
  x2 = 0;
  x3 = 0;
  s = strlen(p_string);
  while ((ch != '[') && (pi < s) && (ch != ';')) 
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
    if (ch == '\'') 
    {
      x4 = 1;
      x4++;
    }
    if (x4 > 0) 
    {
      if (ch == ' ') 
      {
        x5++;
      }
    }
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  if ((x4 == 2) && (x5 == 1) && (fd2_type == 0)) 
  {
    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(tfield2a, w_charlit[I].clit_cname);
        x3 = w_charlit[I].clit_lgth;
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_1 #21");
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
      strcpy(trace_1, "c2z_math.c c2_math_1 #22");
      trace_rec_3();
    }

    if (fd1_id == 3) 
    {
      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #23");
        trace_rec_3();
      }
    }

    if (fd1_id == 2) 
    {
      printf("\nc2z_math.c c2_math_1 math-006 rct = %d fd1_id = 2 NOT CODED\n", rct);
      printf("c2z_math.c c2_math_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    convert = 1;
    return;
  }

  if ((x4 == 0) && (fd2_type != 2)) 
  {
    x2 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        fd2_id = lw_variable[I].lv_id;
        break;
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
          fd2_id = gw_variable[I].gv_id;
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      if (fn_ct > 0) 
      {
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(tfield2, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield2a, w_function[I].fn_cname);
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_1 math-007 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_math.c c2_math_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
    
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_1 #1");
      trace_rec_3();
    }
    
    if (fd2_type == 2) 
    {
      strcpy(a_string, "        LA    R5,");
      strcat(a_string, tfield2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #2");
        trace_rec_3();
      }

      strcpy(a_string, "        LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #3");
        trace_rec_3();
      }
      work_use_ct[48]++;
  
      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #4");
        trace_rec_3();
      }

      strcpy(a_string, "          LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #5");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #6");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "        ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #7");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_1 #8");
      trace_rec_3();
    }
 
    if ((fd1_type == 1) && (fd2_type == 1) && (fd1_status == 1)) 
    {
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #9");
        trace_rec_3();
      }
    }

    if(fd1_status == 2)
    {
      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #9");
        trace_rec_3();
      }
    }

    if ((fd1_id == 2) && (fd2_id == 2)) 
    {
      strcpy(a_string, "         LD    R2,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #10");
        trace_rec_3();
      }

      strcpy(a_string, "         STD   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #11");
        trace_rec_3();
      }
    }

    math_convert = 1;
  }

  if ((x4 == 0) && (x5 == 0) && (fd2_type == 2)) 
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_1 #12");
      trace_rec_3();
    }

    x80 = 0;

    if(x80 == 0)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #13");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #14");
        trace_rec_3();
      }
      work_use_ct[48]++;
  
      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #15");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #16");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #17");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #18");
        trace_rec_3();
      }
    }

    if ((fd1_type == 1)  && (fd2_type == 2))
    {
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #19");
        trace_rec_3();
      }
    }

    if ((fd1_type == 2) && (fd2_type == 2)) 
    {
      strcpy(a_string, "         LD    R2,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #20");
        trace_rec_3();
      }

      strcpy(a_string, "         STD   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_1 #21");
        trace_rec_3();
      }
    }
    convert = 1;
    return;
  }

  if ((x4 == 2) && (x5 == 0) && (fd2_type == 2)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_1 subroutine #4");
      trace_rec_1();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_1 #300");
      trace_rec_3();
    }

    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(tfield2a, w_charlit[I].clit_cname);
        x3 = w_charlit[I].clit_lgth;
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_1 #301");
      trace_rec_3();
    }
   
    strcpy(a_string, "         MVC   0(R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_1 #302");
      trace_rec_3();
    }
    convert = 1;
    return;
  }
}


/* ************************************
*   ch = p_string[pi]       101       *
************************************* */
void c2_math_2() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_2 START");
    trace_rec_1();
  }

  char ch;
  char wk_sv_func[VAR_LGTH];
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field2b[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field10a[VAR_LGTH];
  char field11[VAR_LGTH];

  int struct_fd = 0;
  int pi;
  int pi2;
  int fd1_type = 0;
  int fd2_type = 0;
  int fd3_type = 0;
  int x2 = 0;
  int x3 = 0;
  int x5 = 0;
  int x10 = 0;
  int x80 = 0;
  int x81 = 0;
  int ret = 0;
  int ret1 = 0;
  int mth2_1 = 0;
  int I = 0;
  int s = 0;
  int math_char = 0;
  int math_array = 0;
  int skip;
  int math_struct = 0;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  fd1_type = 0;
  while (ch != ' ') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd1_type = 1;
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
        fd1_type = 2;
        x2 = 1;
      }
    }
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1; 
      strcpy(field1a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
      ret1 = strcmp("I", lw_variable[I].lv_type);
      if (ret1 == 0) 
      {
        fd1_type = 2;
      }

      ret = strcmp("C", lw_variable[I].lv_type);
      if (ret == 0) 
      {
        fd1_type = 1;
      }
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field1a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
        ret = strcmp("I", gw_variable[I].gv_type);
        if (ret == 0) 
        {
          fd1_type = 2;
        }

        ret = strcmp("C", gw_variable[I].gv_type);
        if (ret == 0) 
        {
          fd1_type = 1;
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_math.c c2_math_2 math-008 field1 Not Found = %s\n", field1);
    printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch != '=') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  skip = 0;
  pi2 = 0;
  x2 = 0;
  s = strlen(p_string);
  while ((ch != '[') && (pi < s) && (ch != ';')) 
  {
    if(ch == '(')
    {
      skip = 1;
      goto skip_1;
    }
    if(ch == ')')
    {
      skip = 0;
      goto skip_1;
    }
    if(skip == 1)
    {
      goto skip_1;
    }
    if(ch != ' ')
    {
      field2[pi2] = ch;
      pi2++;
    }
  skip_1:
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
      ret = strcmp("I", lw_variable[I].lv_type);
      if (ret == 0) 
      {
        fd2_type = 2;
      }
      ret = strcmp("C", lw_variable[I].lv_type);
      if (ret == 0) 
      {
        fd2_type = 1;
      }
    }
  }

  math_struct = 0;
  if (x3 == 0) 
  {
    fd2_type = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        math_struct = 1;
        x3 = 1;
        strcpy(field2a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;

        ret1 = strcmp("C", gw_variable[I].gv_type);
        if (ret1 == 0) 
        {
          fd2_type = 1;
          break;
        }
        ret1 = strcmp("I", gw_variable[I].gv_type);
        if (ret1 == 0) 
        {
          fd2_type = 2;
          break;
        }
        ret1 = strcmp("G", gw_variable[I].gv_type);
        if (ret1 == 0) 
        {
          fd2_type = 3;
          break;
        }
        ret1 = strcmp("A", gw_variable[I].gv_type);
        if (ret1 == 0) 
        {
          fd2_type = 4;
          break;
        }
        ret1 = strcmp("M", gw_variable[I].gv_type);
        if (ret1 == 0) 
        {
          fd2_type = 5;
          break;
        }
      }
    }
  }

  x2 = 0;
  pi2 = 0;
  s = strlen(p_string);
  if (ch == '[') 
  {
    pi++;
    ch = p_string[pi];
    while ((ch != ']') && (pi < s) && (ch != ';')) 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd3_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
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
  }

  if ((fd1_type == 2) && (fd2_type == 5) && (math_struct == 1)) 			/* x = gw_variable[gv_ct].gv_lgth */
  {
    x81 = 0;
    s = strlen(p_string);
    for(I = 0; I < s; I++)
    {
      ch = p_string[I];
      if(ch == '[')
      {
        x81++;
      }
      if(ch == ']')
      {
        x81++;
      }
    }

    if(x81 == 2)
    {
      pi = 0;
      ch = p_string[pi];
      while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
      {
        pi++;
        ch = p_string[pi];
      }

      x2 = 0;
      pi2 = 0;
      fd1_type = 0;
      while (ch != ' ') 
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd1_type = 1;
            x2 = 1;
          }

          if (isdigit(ch)) 
          {
            fd1_type = 2;
            x2 = 1;
          }
        }
        field1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1; 
          strcpy(field1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret1 = strcmp("I", lw_variable[I].lv_type);
          if (ret1 == 0) 
          {
            fd1_type = 2;
          }

          ret = strcmp("C", lw_variable[I].lv_type);
          if (ret == 0) 
          {
            fd1_type = 1;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret = strcmp("I", gw_variable[I].gv_type);
            if (ret == 0) 
            {
              fd1_type = 2;
            }

            ret = strcmp("C", gw_variable[I].gv_type);
            if (ret == 0) 
            {
              fd1_type = 1;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_2 math-009 field1 Not FOund = %s\n", field1);
        printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != '=') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      skip = 0;
      pi2 = 0;
      x2 = 0;
      s = strlen(p_string);
      while ((ch != '[') && (pi < s) && (ch != ';')) 
      {
        if(ch == '(')
        {
          skip = 1;
          goto skip_10;
        }
        if(ch == ')')
        {
          skip = 0;
          goto skip_10;
        }
        if(skip == 1)
        {
          goto skip_10;
        }
        if(ch != ' ')
        {
          field2[pi2] = ch;
          pi2++;
        }
      skip_10:
        pi++;
        ch = p_string[pi];
      }
      field2[pi2] = '\0';
      strcpy(field2b,field2);

      x2 = 0;
      pi2 = 0;
      s = strlen(p_string);
      if (ch == '[') 
      {
        pi++;
        ch = p_string[pi];
        while ((ch != ']') && (pi < s) && (ch != ';')) 
        {
          if (x2 == 0) 
          {
            if (isalpha(ch)) 
            {
              fd3_type = 1;
              x2 = 1;
            }

            if (isdigit(ch)) 
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
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1; 
          strcpy(field3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field3, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field3a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_2 math-010 field3 Not FOund = %s\n", field3);
        printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      pi++;
      ch = p_string[pi];
      while(ch == '.')
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      ch = p_string[pi];
      while(ch != ';')
      {
        field4[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field4[pi2] = '\0';

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #1");
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
        strcpy(trace_1, "c2z_math.c c2_math_2 #2");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #3");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #4");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #5");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #6");
        trace_rec_3();
      }

      x3 = 0;
      for (I = 0; I < m_struc_ct; I++) 
      {
        ret = strcmp(field2, w_struc[I].st_wname);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, w_struc[I].st_cwname);
          break;
        }
      }

      strcpy(a_string, "         LARL  R6,");
      strcat(a_string, field2a);
      strcat(a_string, "T");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #7");
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
        strcpy(trace_1, "c2z_math.c c2_math_2 #8");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #9");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #10");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #11");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "B");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #12");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #13");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #14");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #15");
        trace_rec_3();
      }

      strcpy(field2,field2a);
      strcat(field2,"L");
      strcpy(a_string, "         LA    R6,");
      strcat(a_string, field2);
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #16");
        trace_rec_3();
      }
 
      strcpy(a_string, "         JLU   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #17");
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
        strcpy(trace_1, "c2z_math.c c2_math_2 #18");
        trace_rec_3();
      }

      x3 = 0;
      for (I = 0; I < m_struc_ct; I++) 
      {
        ret = strcmp(field2b, w_struc[I].st_wname);
        ret1 = strcmp(field4, w_struc[I].st_field_name);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          x80 = w_struc[I].st_disp;
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
        strcpy(trace_1, "c2z_math.c c2_math_2 #19");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
      strcat(a_string, wk_strg);
      strcat(a_string,"(6,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #20");
        trace_rec_3();
      }

      convert = 1;
    }

    if(x81 == 4)
    {

printf("c2z_math.c math_2 FIX FIX {} = []\n");

    }
  }

  if ((fd1_type == 1) && (fd2_type == 2)) 			/* cx = xxstring[0] */
  {
    x5 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x5 = 1;
          strcpy(field4, lw_variable[I].lv_type);
        }
      }
    }

    if (x5 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field2, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x5 = 1;
            strcpy(field4, gw_variable[I].gv_type);
          }
        }
      }
    }

    if (x5 == 0) 
    {
      printf("\nc2z_math.c c2_math_2 math-011 field4 Not Found = %s\n", field4);
      printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    mth2_1 = strcmp(field4, "C");
    if (mth2_1 == 0) 
    {
      math_char = 1;
    }
    mth2_1 = strcmp(field4, "A");
    if (mth2_1 == 0) 
    {
      math_array = 1;
    }

    if (math_char == 1) 
    {
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #70 ");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #71 ");
        trace_rec_3();
      }
      work_use_ct[9]++;

/*
      for (I = 0; I < math_lit_ct; I++) 
      {
        if ((w_mathlit[I].lit_rct == rct) && (w_mathlit[I].lit_uct == 1)) 
        {
          strcpy(field10a, w_mathlit[I].lit_use_cname);
        }
      }
*/

printf("FIX FIX FIX c2_math_2 #72\n");
printf("rct = %d p_string = %s",rct,p_string);



      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field10a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #72 ");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #73 ");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #74 ");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R5,0(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #75 ");
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
        strcpy(trace_1, "c2z_math.c c2_math_2 #76 ");
        trace_rec_3();
      }

      strcpy(a_string, "         IC    R0,");
      strcat(a_string, "0(R8,");
      strcat(a_string, "(R5))");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #77 ");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #78 ");
        trace_rec_3();
      }

      strcpy(a_string, "         STC   R0,");
      strcat(a_string, "0(0,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 #79 ");
        trace_rec_3();
      }
    }

    if (math_array == 1) 			/* extract character from a array field  */
    {
      printf("\nc2z_math.c c2_math_2 math-012 math_array == 1 ERROR\n");
      printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    math_convert = 1;
    return;
  }


  if (((fd1_type == 1) && (fd2_type == 1)) || ((fd1_type == 2) && (fd2_type == 1))) 			/* x = ct  punch out */
  {

    if((fd1_type == 1) && (fd2_type == 1))
    {
/*
printf("\nc2z_math.c math_2 #1 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c math_2 #1 field1 = %s fd1_type = %d\n",field1,fd1_type);
printf("c2z_math.c math_2 #1 field2 = %s fd2_type = %d\n",field2,fd2_type);
printf("c2z_math.c maht_2 #1 field3 = %s fd3_type = %d\n",field3,fd3_type);
*/
      if(fd3_type == 1)
      {
        x5 = 0;
        if (lv_ct > 0) 
        {
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(field3, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x5 = 1;
              strcpy(field3a, lw_variable[I].lv_cname);
              lw_variable[I].lv_use_ct++;
            }
          }
        }

        if (x5 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (I = 0; I < gv_ct; I++) 
            {
              ret = strcmp(field3, gw_variable[I].gv_name);
              if (ret == 0) 
              {
                x5 = 1;
                strcpy(field3a, gw_variable[I].gv_cname);
                gw_variable[I].gv_use_ct++;
              }
            }
          }
        }

        if (x5 == 0) 
        {
          printf("\nc2z_math.c c2_math_2 math-013 field3 Not Found = %s\n", field3);
          printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
      }

      if(fd3_type == 2)
      {
        strcpy(a_string, "         LAEY  R5,");
        strcat(a_string, field3);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field3);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #80");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #81");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVD   R5,0(R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #82");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
          src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #83");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #84");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #85");
          trace_rec_3();
        }
        strcpy(field3a,"C370NWK1");
      }

      x5 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field2, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x5 = 1;
            strcpy(field4, lw_variable[I].lv_type);
          }
        }
      }

      if (x5 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field2, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x5 = 1;
              strcpy(field4, gw_variable[I].gv_type);
            }
          }
        }
      }

      if (x5 == 0) 
      {
        printf("\nc2z_math.c c2_math_2 math-014 field4 not found = %s\n", field4);
        printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      math_char = 0;
      mth2_1 = strcmp(field4, "C");
      if (mth2_1 == 0) 
      {
        math_char = 1;
      }

      mth2_1 = strcmp(field4, "A");
      if (mth2_1 == 0) 
      {
        math_array = 1;
      }
      else
      {
        math_char = 1;
      }



      if (math_char == 1) 
      {
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "A");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #86");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #87");
          trace_rec_3();
        }
        work_use_ct[9]++;

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field3a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field3);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #88");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #89");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #90");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVB   R5,0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #91");
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
          strcpy(trace_1, "c2z_math.c c2_math_2 #92");
          trace_rec_3();
        }

        strcpy(a_string, "         IC    R0,");
        strcat(a_string, "0(R8,");
        strcat(a_string, "(R5))");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #93");
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
          strcpy(trace_1, "c2z_math.c c2_math_2 #94");
          trace_rec_3();
        }

        strcpy(a_string, "         STC   R0,");
        strcat(a_string, "0(0,R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #95");
          trace_rec_3();
        }
      }

      if (math_array == 1) 			/* extract character from a array field  */
      {
        printf("\nc2z_math.c c2_math_2 math-015 math_array == 1 ERROR\n");
        printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      math_convert = 1;
      convert = 1;
      return;
    }
  }

  if((fd1_type == 2) && (fd2_type == 1))
  {
/*
printf("\nc2z_math.c math_2 #2 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c math_2 #2 field1 = %s fd1_type = %d\n",field1,fd1_type);
printf("c2z_math.c math_2 #2 field2 = %s fd2_type = %d\n",field2,fd2_type);
printf("c2z_math.c maht_2 #2 field3 = %s fd3_type = %d\n",field3,fd3_type);
*/
      if(fd3_type == 1)
      {
        x5 = 0;
        if (lv_ct > 0) 
        {
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(field3, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x5 = 1;
              strcpy(field3a, lw_variable[I].lv_cname);
              lw_variable[I].lv_use_ct++;
            }
          }
        }

        if (x5 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (I = 0; I < gv_ct; I++) 
            {
              ret = strcmp(field3, gw_variable[I].gv_name);
              if (ret == 0) 
              {
                x5 = 1;
                strcpy(field3a, gw_variable[I].gv_cname);
                gw_variable[I].gv_use_ct++;
              }
            }
          }
        }

        if (x5 == 0) 
        {
          printf("\nc2z_math.c c2_math_2 math-013 field3 Not Found = %s\n", field3);
          printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
      }

      if(fd3_type == 2)
      {
        strcpy(a_string, "         LAEY  R5,");
        strcat(a_string, field3);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field3);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #80n");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #81n");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVD   R5,0(R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #82n");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
          src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #83n");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #84n");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #85n");
          trace_rec_3();
        }
        strcpy(field3a,"C370NWK1");
      }

      x5 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field2, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x5 = 1;
            strcpy(field4, lw_variable[I].lv_type);
          }
        }
      }

      if (x5 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field2, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x5 = 1;
              strcpy(field4, gw_variable[I].gv_type);
            }
          }
        }
      }

      if (x5 == 0) 
      {
        printf("\nc2z_math.c c2_math_2 math-014 field4 not found = %s\n", field4);
        printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      math_char = 0;
      mth2_1 = strcmp(field4, "C");
      if (mth2_1 == 0) 
      {
        math_char = 1;
      }

      mth2_1 = strcmp(field4, "A");
      if (mth2_1 == 0) 
      {
        math_array = 1;
      }
      else
      {
        math_char = 1;
      }

        strcpy(a_string, "         LAEY  R8,");
        strcat(a_string, field1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #xxx");
          trace_rec_3();
        }


      if (math_char == 1) 
      {
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "A");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #86n");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #87n");
          trace_rec_3();
        }
        work_use_ct[9]++;

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field3a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field3);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #88n");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #89n");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #90n");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVB   R5,0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #91n");
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
          strcpy(trace_1, "c2z_math.c c2_math_2 #92n");
          trace_rec_3();
        }

        strcpy(a_string, "         IC    R0,");
        strcat(a_string, "0(R8,");
        strcat(a_string, "(R5))");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #93n");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370M02");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #94n");
          trace_rec_3();
        }
        work_use_ct[89]++;

        strcpy(a_string, "         STC   R0,");
        strcat(a_string, "0(0,R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #95n");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R5,");
        strcat(a_string, "C370M02");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #96n");
          trace_rec_3();
        }
        work_use_ct[89]++;

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #97n");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVD   R5,0(R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #98n");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #99n");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #100n");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #101n");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #102n");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R8),0(6,R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_2 #103n");
          trace_rec_3();
        }
      }

    math_convert = 1;
    convert = 1;
    return;
  }

  if ((fd1_type == 2) && (fd2_type == 1) && (math_convert == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '[') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    x5 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x5 = 1;
          strcpy(field3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (x5 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field3, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x5 = 1;
            strcpy(field3a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (x5 == 0) 
    {
      printf("\nc2z_math.c c2_math_2 2 & 1 math-016 field3 not found = %s\n",field3);
      printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x10 = 0;
    if (gv_ct > 0) 
    {
      field7[0] = '\0';
      field8[0] = '\0';
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x10 = 1;
          strcpy(field5, gw_variable[I].gv_dsect);
          strcpy(field6, gw_variable[I].gv_label);
          strcpy(field7, gw_variable[I].gv_table);
          strcpy(field8, gw_variable[I].gv_aname);
          strcpy(field9, gw_variable[I].gv_sv_reg);
          strcpy(field10, gw_variable[I].gv_wk_reg);
          strcpy(field11, gw_variable[I].gv_wk_strg);
        }
      }
    }

    if (x10 == 1) 
    {
      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #1");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #2");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #3");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R6,");
      strcat(a_string, field7);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #5");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "G");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #6");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #7");
        trace_rec_3();
      }

      x5 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field3, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x5 = 1;
            strcpy(field3a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
        }
      }

      if (x5 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field3, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x5 = 1;
              strcpy(field3a, gw_variable[I].gv_cname);
              gw_variable[I].gv_use_ct++;
            }
          }
        }
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field3a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #8");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #9");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   ");
      strcat(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "F");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #10");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #11");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #12");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #13");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, field6);
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #14");
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
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #15");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "F");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #16");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #17");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #18");
        trace_rec_3();
      }
    }

    if (x10 == 0) 
    {
      if (fn_ct > 0) 
      {
        x3 = 0;
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(field2, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field2a, w_function[I].fn_cname);
            strcpy(field4, w_function[I].fn_ret_var);
            strcpy(wk_sv_func, field2);
            strcpy(field5, field3);
          }
        }
      }

      if (x3 == 0) 
      {
        struct_fd = 0;
        for (I = 0; I < m_struc_ct; I++) 
        {
          ret = strcmp(field2, w_struc[I].st_wname);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field2a, w_struc[I].st_cwname);
            strcpy(field5, field3);
            struct_fd = 1;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_2 math-017 field2 function Not Found\n");
        printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x5 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field5, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x5 = 1;
            strcpy(field5a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
        }
      }

      if (x5 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field5, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x5 = 1;
              strcpy(field5a, gw_variable[I].gv_cname);
              gw_variable[I].gv_use_ct++;
            }
          }
        }
      }

      if (x5 == 0) 
      {
        printf("\nc2z_math.c c2_math_2 2 & 1 math-018 field3 Not Found = %s\n",field3);
        printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x5 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field1, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x5 = 1;
            strcpy(field1a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
        }
      }

      if (x5 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field1, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x5 = 1;
              strcpy(field1a, gw_variable[I].gv_cname);
              gw_variable[I].gv_use_ct++;
            }
          }
        }
      }

      if (x5 == 0) 
      {
        printf("\nc2z_math.c c2_math_2 2 & 1 math-019 field1 Not Found = %s\n",field1);
        printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field5a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #19");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #20");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #21");
        trace_rec_3();
      }

      strcpy(a_string, "         BRASL C370LNK,");
      strcat(a_string, field2a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #22");
        trace_rec_3();
      }

      if (struct_fd == 0) 
      {
        x5 = 0;
        if (lv_ct > 0) 
        {
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(field4, lw_variable[I].lv_name);
            ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x5 = 1;
              strcpy(field4a, lw_variable[I].lv_cname);
              lw_variable[I].lv_use_ct++;
            }
          }
        }

        if (x5 == 0) 
        {
          if (gv_ct > 0) 
          {
            for (I = 0; I < gv_ct; I++) 
            {
              ret = strcmp(field4, gw_variable[I].gv_name);
              if (ret == 0) 
              {
                x5 = 1;
                strcpy(field4a, gw_variable[I].gv_cname);
                gw_variable[I].gv_use_ct++;
              }
            }
          }
        }

        if (x5 == 0) 
        {
          printf("\nc2z_math.c c2_math_2 2 & 1 math-020 field4 Not Found = %s\n",field4);
          printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
      }

      x5 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field1, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x5 = 1;
            strcpy(field1a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
        }
      }

      if (x5 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field1, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x5 = 1;
              strcpy(field1a, gw_variable[I].gv_cname);
              gw_variable[I].gv_use_ct++;
            }
          }
        }
      }

      if (x5 == 0) 
      {
        printf("\nc2_math_2 2 & 1 math-021 field1 Not Found = %s\n", field1);
        printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #23");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field4a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #24");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_2 2 & 1 #21");
        trace_rec_3();
      }
    }
  }

  if ((fd1_type == 2) && (fd2_type == 3)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2");
      trace_rec_1();
    }
/*
    pi = 0;
    ch = p_string[pi];
    while (ch != '[') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    x5 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x5 = 1;
          strcpy(field3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (x5 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field3, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x5 = 1;
            strcpy(field3a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (x5 == 0) 
    {
      printf("\nc2z_math.c c2_math_2 math-022 field3 Not found = %s\n", field3);
      printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
*/

    if (gv_ct > 0) 
    {
      field7[0] = '\0';
      field8[0] = '\0';
      for (I = 0; I < gv_ct; I++) 
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
        }
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #5");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #7");
      trace_rec_3();
    }

      x5 = 0;
      if (lv_ct > 0) 
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field3, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x5 = 1;
            strcpy(field3a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
        }
      }

      if (x5 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field3, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              x5 = 1;
              strcpy(field3a, gw_variable[I].gv_cname);
              gw_variable[I].gv_use_ct++;
            }
          }
        }
      }


    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #9");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #11");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #12");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #13");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #14");
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
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #15");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #16");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #17");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 2 & 2 #18");
      trace_rec_3();
    }
  }

  if ((fd1_type == 1) && (fd2_type == 3)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '[') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    x5 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x5 = 1;
          strcpy(field3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (x5 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field3, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x5 = 1;
            strcpy(field3a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (x5 == 0) 
    {
      printf("\nc2z_math.c c2_math_2 math-023 field3 Not Found = %s\n", field3);
      printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (gv_ct > 0) 
    {
      field7[0] = '\0';
      field8[0] = '\0';
      for (I = 0; I < gv_ct; I++) 
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
        }
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #5");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #7");
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
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #9");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #11");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #12");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #13");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1)
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #14");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #15");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "H");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #16");
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
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #17");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_2 1 & 2 #18");
      trace_rec_3();
    }
  }
}



void c2_math_5() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_5");
    trace_rec_1();
  }

  char *p1, *p2, *p3;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield7a[VAR_LGTH];

  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
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
  char field11[VAR_LGTH];

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x10 = 0;
  int x80 = 0;
  int x87 = 0;
  int m5_3 = 0;
  int m5_6 = 0;
  int m5_7 = 0;
  int m5fd1_type = 0;
  int m5fd2_type = 0;
  int m5fd3_type = 0;
  int m5fd5_type = 0;
  int I = 0;
  int s = 0;
  int ret = 0;
  int ret1 = 0;

  /* pgm_label(); */

  p1 = strstr(p_string, "[");
  p2 = strstr(p_string, "]");
  p3 = strstr(p_string, ".");

  if ((p1) && (p2) && (!p3)) 
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    m5fd1_type = 0;
    ch = p_string[pi];
    while (ch != '[') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    m5_3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        m5_3 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        m5_7 = strcmp(lw_variable[I].lv_type, "I");
        if (m5_7 == 0) 
        {
          m5fd1_type = 2;
        }

        m5_7 = strcmp(lw_variable[I].lv_type, "C");
        if (m5_7 == 0) 
        {
          m5fd1_type = 1;
        }
      }
    }

    if (m5_3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        m5_6 = strcmp(field1, gw_variable[I].gv_name);
        if (m5_6 == 0) 
        {
          m5_3 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          m5_7 = strcmp(gw_variable[I].gv_type, "I");
          if (m5_7 == 0) 
          {
            m5fd1_type = 2;
          }

          m5_7 = strcmp(gw_variable[I].gv_type, "C");
          if (m5_7 == 0) 
          {
            m5fd1_type = 1;
          }

          m5_7 = strcmp(gw_variable[I].gv_type, "G");
          if (m5_7 == 0) 
          {
            m5fd1_type = 3;
          }
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("\nc2z_math.c c2_math_5 math-024 field1 Not Found = %s\n", field1);
      printf("c2z_math.c c2_math_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    x2 = 0;
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
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    if (m5fd2_type == 2) 
    {
      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1;
          strcpy(field2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          m5_7 = strcmp(lw_variable[I].lv_type, "I");
          if (m5_7 == 0) 
          {
          }

          m5_7 = strcmp(lw_variable[I].lv_type, "C");
          if (m5_7 == 0) 
          {
          }
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field2, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            m5_7 = strcmp(gw_variable[I].gv_type, "I");
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("\nc2z_math.c c2_math_5 math-025 field2 Not Found = %s\n", field2);
        printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    while (ch != '=') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    x10 = 0;
    x2 = 0;
    pi2 = 0;
    while (ch != ';') 
    {
      if (ch == '\'') 
      {
        x10 = 1;
      }

      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          m5fd3_type = 2;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          m5fd3_type = 1;
          x2 = 1;
        }
      }
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    if ((m5fd3_type == 2) && (x10 == 0)) 
    {
      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1;
          strcpy(field3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field3, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1;
            strcpy(field3a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("\nc2z_math.c c2_math_5 math-026 field3 Not Found = %s\n", field3);
        printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if (x10 == 1) 
    {
      for (I = 0; I < char_ct; I++) 
      {
        if (w_charlit[I].clit_rct == rct) 
        {
          strcpy(field3a, w_charlit[I].clit_cname);
          x3 = w_charlit[I].clit_lgth;
        }
      }
    }

    if(x10 == 0)
    {
      x80 = 0;
      ret = strcmp("0", field3);
      if(ret == 0)
      {
        strcpy(field3a, "C370ZERO");
        x80 = 1;
      }

      if(x80 == 0)
      {
        ret = strcmp("1", field3);
        if(ret == 0)
        {
          strcpy(field3a, "C370ONE");
          x80 = 1;
        }
      }
    }

    x3 = 0;
    s = strlen(p_string);
    for (I = 0; I < s; I++) 
    {
      ch = p_string[I];
      if (ch == '[')
      {
        x3++;
      }

      if (ch == ']')
      {
        x3++;
      }
    }

    if ((m5fd1_type == 1) && (m5fd2_type == 2) && (m5fd3_type == 1)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5");
        trace_rec_1();
      }

      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1;
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field1, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1;
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("\nc2z_math.c c2_math_5 math-027 field1 Not Found = %s\n", field1);
        printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
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
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #10");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #16");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #17");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #18");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #19");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #20");
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
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #21");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R9");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #22");
        trace_rec_3();
      }

      strcpy(a_string, "         AR    R1,R2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #23");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #24");
        trace_rec_3();
      }
      work_use_ct[74]++;

      strcpy(a_string, "         MVC   0(R9,R1),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #25");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #26");
        trace_rec_3();
      }

      convert = 1;
      return;
    }
  }

  if ((m5fd1_type == 1) && (m5fd2_type == 2) && (m5fd3_type == 2)) 
  {
    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #4");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    strcpy(wk_remark, " a[x] = ch ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #7");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R2,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #8");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R1,R9");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R1,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #11");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #12");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #13");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(");
    strcat(a_string, "R9,R1),");
    strcat(a_string, "0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #14");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #15");
      trace_rec_3();
    }

    math_convert = 1;
  }

  if ((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 2)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array");
      trace_rec_1();
    }

    if (gv_ct > 0) 
    {
      field7[0] = '\0';
      field8[0] = '\0';
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
          strcpy(field11, gw_variable[I].gv_wk_strg);
        }
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 array #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #4");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #6");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 array #7");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #8");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, field6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1)
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #11");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #12");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #13");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #14");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "H");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #15");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 array #16");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 array #17");
      trace_rec_3();
    }

    convert = 1;
  }

  if ((m5fd1_type == 3) && (m5fd2_type == 1) && (m5fd3_type == 1)) 
  {
    if (gv_ct > 0) {
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
          strcpy(field11, gw_variable[I].gv_wk_strg);
        }
      }
    }

/*
    for (I = 0; I < math_lit_ct; I++) 
    {
      if ((w_mathlit[I].lit_rct == rct) && (w_mathlit[I].lit_uct == 1)) 
      {
        strcpy(field2a, w_mathlit[I].lit_use_cname);
      }
    }

    for (I = 0; I < math_lit_ct; I++) 
    {
      if ((w_mathlit[I].lit_rct == rct) && (w_mathlit[I].lit_uct == 2)) 
      {
        strcpy(field3a, w_mathlit[I].lit_use_cname);
      }
    }
*/

printf("FIX FIX FIX c2_math_5 #100\n");
printf("rct = %d p_string = %s",rct,p_string);



    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #100");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #101");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #102");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #103");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #104");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #105");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #106");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #107");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #108");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #109");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #110");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #111");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, field6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #112");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #113");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #114");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #115");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #116");
      trace_rec_3();
    }

    convert = 1;
  }

  if ((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 1)) 
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
          strcpy(field11, gw_variable[I].gv_wk_strg);
        }
      }
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
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
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_5 math-028 field2 Not Found = %s\n", field2);
      printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if(x80 == 0)
    {
      strcpy(a_string, "         LA    R5,");
      strcat(a_string, field3);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c c2_math_5 #200");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c c2_math_5 #201");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c c2_math_5 #202");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c c2_math_5 #203");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c c2_math_5 #204");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c c2_math_5 #205");
        trace_rec_3();
      }

      strcpy(field3a, "C370NWK2");
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #206");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #207");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #208");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #209");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #210");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #211");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #212");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #213");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #214");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #215");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #216");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #217");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, field6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #218");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #219");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #220");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #221");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #222");
      trace_rec_3();
    }

    convert = 1;
    return;
  }


  if ((m5fd1_type == 3) && (m5fd2_type == 1) && (m5fd3_type == 2)) 
  {

printf("FIX THIS rct = %d p_string = %s",rct,p_string);
printf("rct = %d field1 = %s\n",rct,field1);
printf("rct = %d field2 = %s\n",rct,field2);
printf("rct = %d field3 = %s\n",rct,field3);

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
          strcpy(field11, gw_variable[I].gv_wk_strg);
        }
      }
    }

    strcpy(a_string, "         LA    R5,");
    strcat(a_string, field2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #900");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #901");
      trace_rec_3();
    }

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c c2_math_5 #902");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c c2_math_5 #903");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c c2_math_5 #904");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c c2_math_5 #905");
        trace_rec_3();
      }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #906");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #907");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #908");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #909");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #910");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #911");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #912");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #913");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #914");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #915");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #916");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #917");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, field6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #918");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #819");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #920");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #921");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #922");
      trace_rec_3();
    }
        
    convert = 1;
    return;
  }

  if ((m5fd1_type == 0) && (m5fd2_type == 2) && (m5fd3_type == 0)) 
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
          strcpy(field11, gw_variable[I].gv_wk_strg);
        }
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #706");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #707");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #708");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #709");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #710");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #711");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #712");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #713");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #714");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_5 #715");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #716");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #717");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, field6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #718");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #719");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 #720");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #721");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R6),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 #722");
      trace_rec_3();
    }

    convert = 1;
    return;
  }



  if ((p1) && (p2) && (p3)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 Structure");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
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
    while (ch != ' ') 
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

    x2 = 0;
    x87 = 0;
    pi2 = 0;
    while (ch != ';') 
    {
      if (ch == '\'') 
      {
        x87 = 1;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          m5fd5_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          m5fd5_type = 1;
          x2 = 1;
        }
      }
      if(ch != '\'')
      {
        tfield5[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield5[pi2] = '\0';

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
      printf("\nc2z_math.c c2z_math_5 Structure math-029 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_5 math-030 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
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
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2z_math_5 Structure math-031 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_math.c c2z_math_5 Structure tfield3 Not Found = %s\n",tfield3);
      printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
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
        printf("\nc2z_math.c c2_math_5 math-032 tfield5 Not Found = %s\n", tfield5);
        printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if ((x87 == 0) && (m5fd5_type == 1))
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield5);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 Struc #1");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 Struc #1");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 Struc #1");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK3");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 Struc #1");
        trace_rec_3();
      }
      work_use_ct[78]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 Struc #1");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 Struc #1");
        trace_rec_3();
      }

      strcpy(tfield5a,"C370NWK3");
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
      printf("\nc2z_math.c c2_math_5 math-033 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #3");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #4");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #6");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #7");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #8");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #10");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #11");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #12");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, tfield1a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #13");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #14");
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
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #15");
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
      printf("/nc2z_math.c c2z_math_5 Structure math-034 tfield1 Not Found = %s\n",tfield1);
      printf("c2z_math.c c2z_math_5 Structure tfield3 Not Found = %s\n",tfield3);
      printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #16");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
    strcat(a_string, wk_strg);
    strcat(a_string, "(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 Struc #17");
      trace_rec_3();
    }
  }

  convert = 1;
}


void c2_math_51() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_51");
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
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field10a[VAR_LGTH];
  char field11[VAR_LGTH];

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int m5_3 = 0;
  int m5_6 = 0;
  int m5_7 = 0;
  int m5_10 = 0;
  int m5fd1_type = 0;
  int m5fd2_type = 0;
  int m5fd3_type = 0;
  int I = 0;
  int s = 0;
  int ret = 0;
  int ret1 = 0;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  m5fd1_type = 0;

  while (ch != '[') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  m5_3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      m5_3 = 1;
      strcpy(field1a, lw_variable[I].lv_cname);
      m5_7 = strcmp(lw_variable[I].lv_type, "I");
      if (m5_7 == 0) 
      {
        m5fd1_type = 2;
      }

      m5_7 = strcmp(lw_variable[I].lv_type, "C");
      if (m5_7 == 0) 
      {
        m5fd1_type = 1;
      }
    }
  }

  if (m5_3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      m5_6 = strcmp(field1, gw_variable[I].gv_name);

      if (m5_6 == 0) 
      {
        m5_3 = 1;
        strcpy(field1a, gw_variable[I].gv_cname);
        m5_7 = strcmp(gw_variable[I].gv_type, "I");
        if (m5_7 == 0) 
        {
          m5fd1_type = 2;
        }

        m5_7 = strcmp(gw_variable[I].gv_type, "C");
        if (m5_7 == 0) 
        {
          m5fd1_type = 1;
        }

        m5_7 = strcmp(gw_variable[I].gv_type, "G");
        if (m5_7 == 0) 
        {
          m5fd1_type = 3;
        }
      }
    }
  }

  if (m5_3 == 0) 
  {
    printf("\nc2z_math.c c2_math_51 math-035 field1 Not Found = %s\n", field1);
    printf("c2z_math.c c2_math_51 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi++;
  pi++;
  ch = p_string[pi];
  pi2 = 0;
  x2 = 0;
  while (isalnum(ch)) 
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
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  if (m5fd2_type == 2) 
  {
    m5_3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        m5_3 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        m5_7 = strcmp(lw_variable[I].lv_type, "I");
        if (m5_7 == 0) 
        {
        }

        m5_7 = strcmp(lw_variable[I].lv_type, "C");
        if (m5_7 == 0) 
        {
        }
      }
    }

    if (m5_3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        m5_6 = strcmp(field2, gw_variable[I].gv_name);
        if (m5_6 == 0) 
        {
          m5_3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          m5_7 = strcmp(gw_variable[I].gv_type, "I");
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("c2z_math.c c2_math_51 math-036 field2 Not Found = %s\n", field2);
      printf("c2z_math.c c2_math_51 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  while (!isalnum(ch)) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (isdigit(ch)) 
  {
    field5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field5[pi2] = '\0';

  while (ch != '=') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  s = strlen(p_string);
  while ((pi < s) && (ch != ';')) 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        m5fd3_type = 2;
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        m5fd3_type = 1;
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
  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[')
    {
      x3++;
    }
    if (ch == ']')
    {
      x3++;
    }
  }

  p = strstr(field3, "'\0'");
  if ((p) && (x3 == 2)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_51 field3 ");
      trace_rec_1();
    }

    m5_3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        m5_3 = 1;
        m5_10 = lw_variable[I].lv_lgth;
      }
    }

    if (m5_3 == 0) {
      for (I = 0; I < gv_ct; I++) 
      {
        m5_6 = strcmp(field1, gw_variable[I].gv_name);
        if (m5_6 == 0) 
        {
          m5_3 = 1;
          m5_10 = gw_variable[I].gv_lgth;
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("c2z_math.c c2_math_51 math-037 field1 Not Found = %s\n", field1);
      printf("c2z_math.c c2_math_51 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    ret = strcmp("0", field2);
    if (ret == 0) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_51 #1");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_51 #2");
        trace_rec_3();
      }

      strcpy(a_string, "         XC    ");
      strcat(a_string, "0(");
      snprintf(wk_strg, sizeof(wk_strg), "%d", m5_10);
      strcat(a_string, wk_strg);
      strcat(a_string, ",R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_51 #3");
        trace_rec_3();
      }

    }

    else 
    {
      if (m5fd3_type == 2) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2");
          trace_rec_1();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #4");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         LARL  R8,C370B8");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #5");
          trace_rec_3();
        }
        work_use_ct[52]++;

        strcpy(a_string, "         MVC   ");
        strcat(a_string, "0(R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #6");
          trace_rec_3();
        }

        strcpy(a_string, "*         MVC   C370L1,=CL1' '");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #7");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #8");
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
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #9");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   ");
        strcat(a_string, "0(4,R9),0(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #10");
          trace_rec_3();
        }

/*
        for (I = 0; I < math_lit_ct; I++) 
        {
          if ((w_mathlit[I].lit_rct == rct) && (w_mathlit[I].lit_uct == 1)) 
          {
            strcpy(field10a, w_mathlit[I].lit_use_cname);
          }
        }
*/

printf("FIX FIX FIX c2_math_51 field3 type 2 #11\n");
printf("rct = %d p_string = %s",rct,p_string);


        strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #11");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field10a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field10);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #12");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   ");
        strcat(a_string, "0(4,R9),0(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #13");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #14");
          trace_rec_3();
        }
        work_use_ct[50]++;

/*
        for (I = 0; I < math_lit_ct; I++) 
        {
          if ((rct == w_mathlit[I].lit_rct) && (w_mathlit[I].lit_uct == 1)) 
          {
            strcpy(a_string, "         LARL  R8,");
            strcat(a_string, w_mathlit[I].lit_use_cname);
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #15");
              trace_rec_3();
            }
          }
        }
*/

printf("FIX FIX FIX c2_math_51 field3 type = 3 #15\n");
printf("rct = %d p_string = %s",rct,p_string);


        strcpy(a_string, "         ZAP   ");
        strcat(a_string, "0(4,R9),0(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #16");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "A");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #17");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #18");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_51 field3 type == 2 #19");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         CP    ");
        strcat(a_string, "0(4,R9),0(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #20");
          trace_rec_3();
        }

        strcpy(a_string, "         JLH   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #21");
          trace_rec_3();
        }

        strcpy(a_string, "*         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #22");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #23");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #24");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #25");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "*         CVB   R2,0(7,R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #26");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #27");
          trace_rec_3();
        }

        strcpy(a_string, "         LA    R1,R9");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #28");
          trace_rec_3();
        }

        strcpy(a_string, "          AR   R1,R2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #29");
          trace_rec_3();
        }

        strcpy(a_string, "*         MVI   0(R1),C' '");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #30");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #31");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R9,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #32");
          trace_rec_3();
        }
        work_use_ct[32]++;

        strcpy(a_string, "         AP    0(4,R9),0(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #33");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "A");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #34");
          trace_rec_3();
        }

        strcpy(a_string, "L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 2 #35");
          trace_rec_3();
        }

        convert = 1;
      }

      if (m5fd3_type == 1) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1");
          trace_rec_1();
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
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #15");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #16");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field2a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field2);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #17");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #18");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #19");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVB   R2,0(4,R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #20");
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
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #21");
          trace_rec_3();
        }

        strcpy(a_string, "         LR    R1,R9");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #22");
          trace_rec_3();
        }

        strcpy(a_string, "         AR    R1,R2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #23");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370B8");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #24");
          trace_rec_3();
        }
        work_use_ct[53]++;

        strcpy(a_string, "         MVC   0(R9,R1),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #25");
          trace_rec_3();
        }

        strcpy(a_string, "L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "E");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 type == 1 #26");
          trace_rec_3();
        }

        convert = 1;
      }
    }

    if ((m5fd1_type == 1) && (m5fd3_type == 0)) 			/* p_string[loc] = '&'	*/
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal ");
        trace_rec_1();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #1");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #1");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #2");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   ");
      strcat(a_string, "0(8,R9),0(4,R8)");
      strcpy(wk_remark, " a[x] = ch ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #3");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #5");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R2,0(4,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #6");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #7");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R9");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #8");
        trace_rec_3();
      }

      strcpy(a_string, "         AR    R1,R2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #9");
        trace_rec_3();
      }

      for (I = 0; I < char_ct; I++) 
      {
        if (w_charlit[I].clit_rct == rct) 
        {
          strcpy(field3a, w_charlit[I].clit_cname);
          x3 = w_charlit[I].clit_lgth;
        }
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #10");
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
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #11");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   0(");
      strcat(a_string, "R9,R1),");
      strcat(a_string, "0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #12");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #13");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #14");
        trace_rec_3();
      }

      strcpy(a_string, "         AP    0(4,R9),0(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #15");
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
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 literal #16");
        trace_rec_3();
      }

      math_convert = 1;
    }

    convert = 1;
  }

  if ((!p) && (convert == 0)) 		/* not a literal 		*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric ");
      trace_rec_1();
    }

    m5_3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        m5_3 = 1;
        x3 = strcmp("I", lw_variable[I].lv_type);
      }
    }

    if (m5_3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        m5_6 = strcmp(field1, gw_variable[I].gv_name);
        if (m5_6 == 0)
        {
          m5_3 = 1; 
          x3 = strcmp("I", gw_variable[I].gv_type);
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("c2z_math.c c2_math_5 math-038 field1 Not Found = %s\n", field1);
      printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (m5fd3_type == 2) 
    {
      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1; 
          strcpy(field3a, lw_variable[I].lv_cname);
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field3, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1; 
            strcpy(field3a, gw_variable[I].gv_cname);
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("c2z_math.c c2_math_5 math-039 field3 Not Found = %s\n", field3);
        printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
      else 
      {
        strcpy(field3a, field3);
      }
    }

    if (m5fd1_type != 3) 
    {
      if (m5fd2_type != 1) 
      {
        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #1");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field2a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field2);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #2");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   ");
        strcat(a_string, "0(8,R9),0(4,R8)");
        strcpy(wk_remark, " a[x] = ch ");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #3");
          trace_rec_3();
        }
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #4");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R2,0(4,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #5");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #6");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R9");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #7");
        trace_rec_3();
      }

      strcpy(a_string, "         AR    R1,R2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #8");
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
        strcpy(trace_1, "c2z_nath.c c2_math_5 field3 numeric #9");
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
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #10");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   0(");
      strcat(a_string, "R9,R1),");
      strcat(a_string, "0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #11");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #12");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #13");
        trace_rec_3();
      }

      strcpy(a_string, "         AP    0(4,R9),0(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #14");
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
        strcpy(trace_1, "c2z_math.c c2_math_5 field3 numeric #15");
        trace_rec_3();
      }

      math_convert = 1;
    }

    if (m5fd1_type == 3) 			/* array processing		*/
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array");
        trace_rec_1();
      }

      if (gv_ct > 0) 
      {
        field7[0] = '\0';
        field8[0] = '\0';
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
            strcpy(field11, gw_variable[I].gv_wk_strg);
          }
        }
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #1");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #2");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   ");
      strcat(a_string, "0(4,R9),0(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #3");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R6,");
      strcat(a_string, field7);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #4");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "G");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #5");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #6");
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
        strcpy(trace_1, "c2z_math.c c2_math_5 array #8");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    ");
      strcat(a_string, "0(4,R9),0(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #8");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   ");
      strcat(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "F");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #9");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #10");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #11");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         AP    ");
      strcat(a_string, "0(4,R9),0(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #12");
        trace_rec_3();
      }

      strcpy(a_string, "         LA    R6,");
      strcat(a_string, field6);
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #13");
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
        strcpy(trace_1, "c2z_math.c c2_math_5 array #14");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "F");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #15");
        trace_rec_3();
      }

      if (m5fd3_type == 1) 
      {
/*
        for (v = 0; v < math_lit_ct; v++) 
        {
          if ((rct == w_mathlit[v].lit_rct) && (w_mathlit[v].lit_uct == 1)) 
          {
            strcpy(a_string, "         LARL  R8,");
            strcat(a_string, w_mathlit[v].lit_use_cname);
            src_line();
            if (puncde == 1) 
            {
              strcpy(trace_1, "c2z_math.c c2_math_5 array #16");
              trace_rec_3();
            }
          }
        }
      } 
      else 
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field3a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field3);
       
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_5 array #16");
          trace_rec_3();
        }
*/

printf("FIX FIX FIX c2_math_5 array #16\n");
printf("rct = %d p_string = %s",rct,p_string);

      }

      strcpy(a_string, "         ZAP   ");
      strcat(a_string, "0(4,R6),0(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_5 array #17");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R6,");
      strcat(a_string, field7);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c c2_math_5 array #18");
        trace_rec_3();
      }
    }
  }

  convert = 1;
}

void c2_math_6() 		/* procedure call	pi = get_upper(pi,stlen);	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_6 START");
    trace_rec_1();
  }

  char ch;
  char *p, *p1, *p2, *p6;
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
  char tfield6[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];
  char tfield8[VAR_LGTH];
  char tfield8a[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield9a[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield10a[VAR_LGTH];
  char tfield21[VAR_LGTH];
  char tfield21a[VAR_LGTH];
  char tfield22[VAR_LGTH];
  char tfield22a[VAR_LGTH];
  char tfield23[VAR_LGTH];
  char tfield23a[VAR_LGTH];
  char wk_sv_func[VAR_LGTH];

  int pi;
  int pi2;
  int pi3;
  int blank_ct = 0;
  int I = 0;
  int x2 = 0;
  int x3 = 0;
  int x6 = 0;
  int x10 = 0;
  int x11 = 0;
  int x12 = 0;
  int x13 = 0;
  int x14 = 0;
  int x15 = 0;
  int x80 = 0;
  int x85 = 0;
  int x88 = 0;
  int x97 = 0;
  int x98 = 0;
  int s = 0;
  int tot_comma = 0;
  int fd1_type = 0;
  int fd3_type = 0;
  int fd4_type = 0;
  int fd5_type = 0;
  int fd6_type = 0;
  int fd21_type = 0;
  int fd22_type = 0;
  int fd23_type = 0;
  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
  int eol = 0;

  s = strlen(p_string);
  pi = 0;
  ch = p_string[pi];
  for (I = 0; I < s; I++) 
  {
    if (ch == ';') 
    {
      break;
    }

    if (ch == '[') 
    {
      x10 = I;
    }

    if (ch == ']') 
    {
      x11 = I;
    }

    if (ch == '=') 
    {
      x12 = I;
    }

    if (ch == '(') 
    {
      x13 = I;
    }

    if (ch == ')') 
    {
      x14 = I;
    }

    if (ch == ',') 
    {
      x15 = I;
      x85++;
    }

    pi++;
    ch = p_string[pi];
  }

/*
printf("c2z_math.c c2_math rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c c2_math rct = %d x10 = %d x11 = %d x12 = %d x13 = %d x14 = %d x15 = %d x85 = %d\n",rct,x10,x11,x12,x13,x14,x15,x85); 
*/

  if ((x10 == 0) && (x11 == 0) && (x13 < x12) && (x14 > x12) && (x15 == 0)) 
  {
    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != '(') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(tfield2, w_charlit[I].clit_cname);
        x3 = w_charlit[I].clit_lgth;
      }
    }

    if (fn_ct > 0) 
    {
      x3 = 0;
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(tfield1, w_function[I].fn_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, w_function[I].fn_cname);
          strcpy(tfield3, w_function[I].fn_ret_var);
          strcpy(tfield4, w_function[I].fn_fd1);
          strcpy(wk_sv_func, tfield1);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-040 tfield1 (function) Not Found = %s\n",tfield1);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield4, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield4a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        s = lw_variable[I].lv_lgth;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield4, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield4a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          s = gw_variable[I].gv_lgth;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-041 #80 tfield4 Not Found = %s\n", tfield4);
      printf("c2z_math.c c2_math_6 #80 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #80");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #81");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", s);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #82");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #83");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #83");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  if ((x10 == 0) && (x11 == 0) && (x12 < x13) && (x15 == 0) && (convert == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 subroutine #1");
      trace_rec_1();
    }

    x98 = 0;
    pi = 0;
    pi2 = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      if (ch == '=') 
      {
        break;
      }
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    if (ch == '=') 
    {
      goto math_skip_6;
    }

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

  math_skip_6:

    pi2 = 0;
    while (ch != ' ') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    p1 = strstr(p_string, "(int)");
    if (p1) 
    {
      while (ch != ')') 
      {
        pi++;
        ch = p_string[pi];
      }
      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }
    }

    eol = 0;
    pi2 = 0;
    while (ch != '(') 
    {
      if (ch == ';') 
      {
       eol = 1;
       break;
      }
      if (ch != ';') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    if (eol == 1)
    {  
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {  
        for (I = 0; I < gv_ct; I++) 
        {
          x6 = strcmp(tfield1, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
             x3 = 1;
             strcpy(tfield1a, gw_variable[I].gv_cname);
             gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_6 math-042 eol = 1 tfield1 Not Found = %s\n", tfield1);
        printf("c2z_math.c c2_math_6 eol = 1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {  
        for (I = 0; I < gv_ct; I++) 
        {
          x6 = strcmp(tfield3, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
             x3 = 1;
             strcpy(tfield3a, gw_variable[I].gv_cname);
             gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_6 math-043 eol = 1 tfield3 Not Found = %s\n", tfield3);
        printf("c2z_math.c c2_math_6 eol = 1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 eol #1");
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
        strcpy(trace_1, "c2z_math.c c2_math_6 eol #2");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 eol #3");
        trace_rec_3();
      }

      convert = 1;
      return;
    }

    s = strlen(tfield3);
    x88 = 0;

    if (s == 0) 			/* idx = (len-1); tfield3 = (len-1) */
    {
      x88 = 1;
      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        tfield3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield3[pi2] = '\0';

      p2 = strstr(tfield3, "+");
      if(p2)
      {
        pi3 = 0;
        pi2 = 0;
        ch = tfield3[pi3];
        while(ch != ' ')
        {
          tfield9[pi2] = ch;
          pi2++;
          pi3++;
          ch = tfield3[pi3];
        }
        tfield9[pi2] = '\0';

        while(ch != '+')
        {
          pi3++;
          ch = tfield3[pi3];
        }

        s = strlen(tfield3);
        pi2 = 0;
        pi3++;
        ch = tfield3[pi3];
        while(pi3 < s)
        {
          if(ch != ' ')
          {
            tfield10[pi2] = ch;
            pi2++;
          }
          pi3++;
          ch = tfield3[pi3];
        }
        tfield10[pi2] = '\0';

        x3 = 0;
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(tfield1, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(tfield1a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
        }

        if (x3 == 0) 
        {  
          for (I = 0; I < gv_ct; I++) 
          {
            x6 = strcmp(tfield1, gw_variable[I].gv_name);
            if (x6 == 0) 
            {
               x3 = 1;
               strcpy(tfield1a, gw_variable[I].gv_cname);
               gw_variable[I].gv_use_ct++;
            }
          }
        }

        if (x3 == 0) 
        {
          printf("\nc2z_math.c c2_math_6 math-044 #66 tfield1 Not Found = %s\n", tfield1);
          printf("c2z_math.c c2_math_6 #66 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        x3 = 0;
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(tfield9, lw_variable[I].lv_name);
          ret1 = strcmp(sv_func, lw_variable[I].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(tfield9a, lw_variable[I].lv_cname);
            lw_variable[I].lv_use_ct++;
          }
        }

        if (x3 == 0) 
        {  
          for (I = 0; I < gv_ct; I++) 
          {
            x6 = strcmp(tfield9, gw_variable[I].gv_name);
            if (x6 == 0) 
            {
               x3 = 1;
               strcpy(tfield1a, gw_variable[I].gv_cname);
               gw_variable[I].gv_use_ct++;
            }
          }
        }

        if (x3 == 0) 
        {
          printf("\nc2z_math.c c2_math_6 math-045 #67 tfield9 Not Found = %s\n", tfield9);
          printf("c2z_math.c c2_math_6 #67 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield9a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield9);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 #66");
          trace_rec_3();
        }

        x80 = 0;
        ret = strcmp("0", tfield10);
        if(ret == 0)
        {
           strcpy(tfield10a, "C370ZERO");
           x80 = 1;
        }

        if(x80 == 0)
        {
          ret = strcmp("1",tfield10);
          if(ret == 0)
          {
            strcpy(tfield10a, "C370ONE");
            x80 = 1;
          }
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, tfield10a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield10);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 #67");
          trace_rec_3();
        }

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 #68");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 #69");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, tfield9a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield9);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 #70");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 #71");
          trace_rec_3();
        }

        convert = 1;
        return;
      }
    }

    x98 = 0;
    p = strstr(tfield3, "{");
    if (p) 
    {
      x98 = 1;
    }

    p = strstr(tfield3, "}");
    if (p) 
    {
      x98 = 1;
    }

    if (x98 == 0) 
    {
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if(ch == ';')
        {
          break;
        }
        if(ch != ' ')
        {
          tfield4[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield4[pi2] = '\0';
    }

    if (x98 == 1) 
    {
      strcpy(wk_sv_func, tfield3);
      pi = 0;
      pi2 = 0;
      ch = tfield3[pi];
      while (ch != '(') 
      {
        tfield3a[pi2] = ch;
        pi2++;
        pi++;
        ch = tfield3[pi];
      }
      tfield3a[pi2] = '\0';
      strcpy(tfield3, tfield3a);
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield1, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-046 #1 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_6 #1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((x98 == 0) && (x88 != 1)) 
    {
      if (fn_ct > 0) 
      {
        x3 = 0;
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(tfield3, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield3a, w_function[I].fn_cname);
            strcpy(tfield5, w_function[I].fn_ret_var);
            strcpy(tfield6, w_function[I].fn_fd1);
            strcpy(wk_sv_func, tfield3);
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_6 math-047 tfield3 (function) Not Found = %s\n",tfield3);
        printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      s = strlen(tfield5);

      if(s != 0)
      {
        x3 = 0;
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(tfield5, lw_variable[I].lv_name);
          ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
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
            x6 = strcmp(tfield5, gw_variable[I].gv_name);
            if (x6 == 0) 
            {
              x3 = 1;
              strcpy(tfield5a, gw_variable[I].gv_cname);
              gw_variable[I].gv_use_ct++;
            }
          }
        }

       if (x3 == 0) 
        {
          printf("\nc2z_math.c c2_math_6 math-048 tfield5 Not Found = %s\n", tfield5);
          printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
      }
    }

    if (x88 != 1) 
    {
      if (fn_ct > 0) 
      {
        x3 = 0;
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(tfield3, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield3a, w_function[I].fn_cname);
            strcpy(tfield5, w_function[I].fn_ret_var);
            strcpy(tfield6, w_function[I].fn_fd1);
            strcpy(wk_sv_func, tfield3);
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_6 math-049 tfield3 (function) Not Found = %s\n",tfield3);
        printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield5, lw_variable[I].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
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
          x6 = strcmp(tfield5, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
            x3 = 1;
            strcpy(tfield5a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_6 math-050 tfield5 Not Found = %s\n", tfield5);
        printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    fd4_type = 0;
    if (x98 == 1) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield4, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield4a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          p = strstr(lw_variable[I].lv_type, "C");
          if(p)
          {
            fd4_type = 1;
          }
           p = strstr(lw_variable[I].lv_type, "I");
           if(p)
           {
             fd4_type = 2;
           }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          x6 = strcmp(tfield4, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
            x3 = 1;
            strcpy(tfield4a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            p = strstr(gw_variable[I].gv_type, "C");
            if(p)
            {
              fd4_type = 1;
            }
            p = strstr(gw_variable[I].gv_type, "I");
            if(p)
            {
              fd4_type = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_6 math-051 #45 rct = %d tfield4 Not Found = %s\n",rct, tfield4);
        printf("c2z_math.c c2_math_6 #45 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }


    x97 = 0;
    if(x98 == 0)
    {
      p = strstr(tfield3,"char");
      if(p)
      {
         x97 = 1;
      }
    }

    if(x97 == 1)
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield4, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield4a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          x6 = strcmp(tfield4, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
            x3 = 1;
            strcpy(tfield4a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_6 math-052 #45 rct = %d tfield4 Not Found = %s\n",rct, tfield4);
        printf("c2z_math.c c2_math_6 #45 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 #970");
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
        strcpy(trace_1, "c2z_math.c c2_math_6 #971");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 #972");
        trace_rec_3();
      }

      convert = 1;
      return;
    }

    if (x98 != 1) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield4, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield4a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          p = strstr(lw_variable[I].lv_type, "C");
          if(p)
          {
            fd4_type = 1;
            s = lw_variable[I].lv_lgth;
          }
           p = strstr(lw_variable[I].lv_type, "I");
           if(p)
           {
             fd4_type = 2;
           }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          x6 = strcmp(tfield4, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
            x3 = 1;
            strcpy(tfield4a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            p = strstr(gw_variable[I].gv_type, "C");
            if(p)
            {
              fd4_type = 1;
              s = gw_variable[I].gv_lgth;
            }
            p = strstr(gw_variable[I].gv_type, "I");
            if(p)
            {
              fd4_type = 2;
            }
          }
        }
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield6, lw_variable[I].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield6a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          x6 = strcmp(tfield6, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
            x3 = 1;
            strcpy(tfield6a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if(fd4_type == 2)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield6a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield6);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 #100i");
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
          strcpy(trace_1, "c2z_math.c c2_math_6 #101i");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 #102i");
          trace_rec_3();
        }
      }
  
      if(fd4_type == 1)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield6a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield6);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 #100c");
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
          strcpy(trace_1, "c2z_math.c c2_math_6 #101c");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", s);
        strcpy(a_string, "         MVC   0(");
        strcat(a_string, wk_strg);
        strcat(a_string, ",R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 #102c");
          trace_rec_3();
        }
      }
    }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #306");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #306");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        p = strstr(lw_variable[I].lv_type, "C");
        if(p)
        {
          fd1_type = 1;
          s = lw_variable[I].lv_lgth;
        }
        p = strstr(lw_variable[I].lv_type, "I");
        if(p)
        {
          fd1_type = 2;
        }
        p = strstr(lw_variable[I].lv_type, "D");
        if(p)
        {
          fd1_type = 2;
        }
        p = strstr(lw_variable[I].lv_type, "L");
        if(p)
        {
          fd1_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield1, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          p = strstr(gw_variable[I].gv_type, "C");
          if(p)
          {
            fd1_type = 1;
            s = gw_variable[I].gv_lgth;
          }
          p = strstr(gw_variable[I].gv_type, "I");
          if(p)
          {
            fd1_type = 2;
          }
          p = strstr(gw_variable[I].gv_type, "D");
          if(p)
          {
            fd1_type = 2;
          }
          p = strstr(gw_variable[I].gv_type, "L");
          if(p)
          {
            fd1_type = 2;
          }
        }
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #104");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #105");
      trace_rec_3();
    }

    if(fd1_type == 1)
    {
      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 #106");
        trace_rec_3();
      }
    }

    if(fd1_type == 2)
    {
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 #107");
        trace_rec_3();
      }
    }

    convert = 1;
    return;
  }

  if ((x10 == 0) && (x11 == 0) && (x12 < x13) && (x14 > 0) && (x85 == 1) && (convert == 0)) 	/* pi = get_upper(pi, len); */
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != '(') 
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
    while (ch != ',') 
    {
      if (ch != ' ') 
      {
        tfield4[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != ' ') 
      {
        tfield5[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield5[pi2] = '\0';

    if (fn_ct > 0) 
    {
      x3 = 0;
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(tfield3, w_function[I].fn_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield3a, w_function[I].fn_cname);
          strcpy(tfield6, w_function[I].fn_ret_var);
          strcpy(tfield7, w_function[I].fn_fd1);
          strcpy(tfield8, w_function[I].fn_fd2);
          strcpy(wk_sv_func, tfield3);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-053 tfield3 (function) Not Found = %s\n",tfield3);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield1, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-054 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield7, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield7a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield7, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield7a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-055 tfield7 Not Found = %s\n", tfield7);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield7a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield7);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #300");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #301");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #302");
      trace_rec_3();
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
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield5, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield5a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-056 tfield5 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield8, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield8a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) {
        x6 = strcmp(tfield8, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield8a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-057 tfield8 Not Found = %s\n", tfield8);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield8a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield8);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #303");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #304");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #305");
      trace_rec_3();
    }

 /*   strcpy(a_string, "         BRASL C370LNK,");
    strcat(a_string, tfield3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #306");
      trace_rec_3();
    }
*/

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #306");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #306");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield6, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield6a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield6, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield6a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-058 #100 tfield6 Not Found = %s\n", tfield6);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #307");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield6a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #308");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #309");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  if ((x10 == 0) && (x11 == 0) && (x12 < x13) && (x14 > 0) && (x85 == 2) && (convert == 0)) 		/* pi = get_upper(pi, len, op); */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 subroutine #150");
      trace_rec_1();
    }

    x98 = 1;
    convert = 1;
  }

  if ((x98 == 0) && (convert == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 subroutine #10");
      trace_rec_1();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #170");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield4a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #171");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R9),(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #172");
      trace_rec_3();
    }

    strcpy(a_string, "         BRASL C370LNK,");
    strcat(a_string, tfield3a);
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #173");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #174");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield6a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #175");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R9),(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 #176");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  /*  end of 1st section of math_6 */

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == ';') 
    {
      break;
    }
    if (ch == ',') 
    {
      tot_comma++;
    }
  }

  blank_ct = 0;
  p6 = strstr(p_string, "()");
  if (p6) 
  {
    blank_ct = 1;
  }

  if (tot_comma == 0) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 subroutine #2");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while (ch != ' ') 
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
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != '(') 
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
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1; 
        strcpy(tfield1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield1, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-059 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fn_ct > 0) 
    {
      x3 = 0;
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(tfield2, w_function[I].fn_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, w_function[I].fn_cname);
          strcpy(tfield3, w_function[I].fn_ret_var);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-060 tfield2 (function) Not Found = %s\n",tfield2);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(wk_sv_func, tfield2);
    s = strlen(tfield3);

    if (s != 0) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield6, lw_variable[I].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield6a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          x6 = strcmp(tfield6, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
            x3 = 1; 
            strcpy(tfield6a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_6 math-061 tfield6 Not Found = %s\n", tfield6);
        printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if ((tot_comma == 0) && (blank_ct == 1) && (convert == 0)) 		/*  boolx = sboolterm();	*/
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 subroutine #2");
        trace_rec_1();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 #1");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 #2");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 #3");
        trace_rec_3();
      }

      strcpy(a_string, "         BRASL C370LNK,");
      strcat(a_string, tfield2a);
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 #4");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 #5");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield6a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield6);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 #6");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 #7");
        trace_rec_3();
      }
    }

    if ((tot_comma == 0) && (blank_ct == 0) && (convert == 0)) 		/* means at least one passed field	*/
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 one var");
        trace_rec_1();
      }

      pi = 0;
      ch = p_string[pi];
      while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      while (ch != ' ') 
      {
        tfield1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield1[pi2] = '\0';

      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      ch = p_string[pi];
      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      while (ch != '(') 
      {
        tfield2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield2[pi2] = '\0';

      if (fn_ct > 0) 
      {
        x3 = 0;
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(tfield2, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield2a, w_function[I].fn_cname);
            strcpy(tfield4, w_function[I].fn_ret_var);
            strcpy(tfield6, w_function[I].fn_fd1);
            strcpy(wk_sv_func, tfield2);
          }
        }
      }

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        tfield3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield3[pi2] = '\0';

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield3a, lw_variable[I].lv_cname);
          ret = strcmp("I", lw_variable[I].lv_type);
          if (ret == 0) 
          {
            fd3_type = 1;
          } 
          else 
          {
            fd3_type = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          x6 = strcmp(tfield3, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
            x3 = 1;
            strcpy(tfield3a, gw_variable[I].gv_cname);
            ret = strcmp("I", gw_variable[I].gv_type);
            if (ret == 0) 
            {
              fd3_type = 1;
            } 
            else 
            {
              fd3_type = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_6 math-062 ONE VAR ERROR tfield3 Not Found = %s\n",tfield1);
        printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if ((fd3_type == 1) && (fd5_type == 1)) 		/* both variable are numeric	*/
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield5a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield3);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 one var #1");
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
          strcpy(trace_1, "c2z_math.c c2_math_6 one var #2");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 one var #3");
          trace_rec_3();
        }

        strcpy(a_string, "         BRASL C370LNK,");
        strcat(a_string, tfield2a);
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 one var #4");
          trace_rec_3();
        }
      }

      if ((fd3_type == 2) && (fd5_type == 2)) 		/* both variable are character	*/
      {
        strcpy(a_string, "         MVC2  ");
        strcat(a_string, tfield6a);
        strcat(a_string, ",");
        strcat(a_string, tfield3a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 one var #7");
          trace_rec_3();
        }

        strcpy(a_string, "         BRASL C370LNK,");
        strcat(a_string, tfield2a);
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 one var #8");
          trace_rec_3();
        }
      }

      if ((fd3_type == 1) && (fd5_type == 1)) 		/* both variable are numeric	*/
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 one var #9");
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
          strcpy(trace_1, "c2z_math.c c2_math_6 one var #10");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 one var #11");
          trace_rec_3();
        }
      }

      if ((fd3_type == 2) && (fd5_type == 2)) 		/* both variable are characters	*/
      {
        strcpy(a_string, "         MVC2  ");
        strcat(a_string, tfield1a);
        strcat(a_string, ",");
        strcat(a_string, tfield4a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_6 one var #14");
          trace_rec_3();
        }
      }

      convert = 1;
      return;
    }
  }

  if ((tot_comma == 1) && (blank_ct == 0) && (convert == 0)) 		/* means at least two passed fields	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 two var");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != '=') 
    {
      if (ch != ' ') 
      {
        if (ch != '{') 
        {
          tfield1[pi2] = ch;
          pi2++;
        }
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != '(') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';
    strcpy(wk_sv_func, tfield2);

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
      tfield4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';
    strcpy(tfield6, tfield4);

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
      tfield5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield5[pi2] = '\0';
    strcpy(tfield7, tfield5);

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if (ret2 == 0) 
        {
          fd1_type = 1;
        } 
        else 
        {
          fd1_type = 2;
        }
        break;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield1, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          ret2 = strcmp("I", gw_variable[I].gv_type);
          if (ret2 == 0) 
          {
            fd1_type = 1;
          } 
          else 
          {
            fd1_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-063 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield4a, lw_variable[I].lv_cname);
        ret = strcmp("I", lw_variable[I].lv_type);
        if (ret == 0) 
        {
          fd4_type = 1;
        } 
        else 
        {
          fd4_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield4, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield4a, gw_variable[I].gv_cname);
          ret = strcmp("I", gw_variable[I].gv_type);
          if (ret == 0) 
          {
            fd4_type = 1;
          } 
          else 
          {
            fd4_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-064 tfield4 Not Found = %s\n", tfield4);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
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
        ret = strcmp("I", lw_variable[I].lv_type);
        if (ret == 0) 
        {
          fd5_type = 1;
        } 
        else 
        {
          fd5_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield5, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield5a, gw_variable[I].gv_cname);
          ret = strcmp("I", gw_variable[I].gv_type);
          if (ret == 0) 
          {
            fd5_type = 1;
          } 
          else 
          {
            fd5_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-065 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fn_ct > 0) 
    {
      x3 = 0;
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(tfield2, w_function[I].fn_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, w_function[I].fn_cname);
          strcpy(tfield3, w_function[I].fn_ret_var);
          strcpy(wk_sv_func, tfield2);
          strcpy(tfield6, w_function[I].fn_fd1);
          strcpy(tfield7, w_function[I].fn_fd2);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-066 tfield2 function Not Found \n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield6, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield6a, lw_variable[I].lv_cname);
        ret = strcmp("I", lw_variable[I].lv_type);
        if (ret == 0) 
        {
          fd6_type = 1;
        } 
        else 
        {
          fd6_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield6, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield6a, gw_variable[I].gv_cname);
          ret = strcmp("I", gw_variable[I].gv_type);
          if (ret == 0) 
          {
            fd6_type = 1;
          } 
          else 
          {
            fd6_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-067 tfield6 Not Found = %s\n", tfield6);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield7, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield7a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield7, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield7a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-068 tfield7 Not Found = %s\n", tfield7);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield6a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 two var #1");
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
      strcpy(trace_1, "c2z_math.c c2_math_6 two var #2");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 two var #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield7a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield7);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 two var #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 two var #5");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 two var #6");
      trace_rec_3();
    }

    strcpy(a_string, "         BRASL C370LNK,");
    strcat(a_string, tfield2a);
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 two var #7");
      trace_rec_3();
    }

    if ((fd1_type == 1) && (fd3_type == 0)) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[I].lv_cname);
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          x6 = strcmp(tfield1, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
          }
        }
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield3, lw_variable[I].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield3a, lw_variable[I].lv_cname);
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          x6 = strcmp(tfield3, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
            x3 = 1;
            strcpy(tfield4a, gw_variable[I].gv_cname);
          }
        }
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 two var #8");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 two var #9");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 two var #10");
        trace_rec_3();
      }
      convert = 1;
    }

    if ((fd1_type == 1) && (fd3_type == 1)) 
    {
      strcpy(a_string, "         ZAP   ");
      strcat(a_string, tfield1a);
      strcat(a_string, ",");
      strcat(a_string, tfield3a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 two var #11");
        trace_rec_3();
      }
      convert = 1;
    }

    if ((fd1_type == 2) && (fd3_type == 2)) 
    {
      printf("\nc2z_math.c c2_math_6 math-069 fd1 & fd3 type == 2 NEED TO BE CODED\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd1_type == 1) && (fd3_type == 2)) 
    {
      printf("\nc2z_math.c c2_math_6 math-070 field1 & field3 MISMATCH ERROR\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd1_type == 2) && (fd3_type == 1)) 
    {
      printf("\nc2z_math.c c2_math_6 math-071 field1 & field3 MISMATCH ERROR\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    convert = 1;
  }

  if ((tot_comma == 2) && (convert == 0)) 		/* means at least three passed fields	*/
  {
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 three var START");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t')) 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    fd1_type = 0;
    pi2 = 0;
    while (ch != ' ') 
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
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != '(') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';
    strcpy(wk_sv_func, tfield2);

    x2 = 0;
    fd4_type = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ',') 
    {
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
      tfield4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

    x2 = 0;
    fd5_type = 0;
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while (ch != ',') 
    {
      if (ch != ' ') 
      {
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

        tfield5[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield5[pi2] = '\0';

    pi2 = 0;
    while (ch != ')') 
    {
      if (ch != ',') 
      {
        if (ch != ' ') 
        {
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
          tfield6[pi2] = ch;
          pi2++;
        }
      }
      pi++;
      ch = p_string[pi];
    }
    tfield6[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield1, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-072 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield4a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield4, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield4a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-073 tfield4 Not Found = %s\n", tfield4);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
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
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield5, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield5a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-074 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield6, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield6a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield6, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield6a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-075 tfield6 Not Found = %s\n", tfield6);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fn_ct > 0) 
    {
      x3 = 0;
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(tfield2, w_function[I].fn_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, w_function[I].fn_cname);
          strcpy(tfield3, w_function[I].fn_ret_var);
          strcpy(wk_sv_func, tfield2);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-076 tfield2 function Not Found \n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fn_ct > 0) 
    {
      x3 = 0;
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(wk_sv_func, w_function[I].fn_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield21, w_function[I].fn_fd1);
          strcpy(tfield22, w_function[I].fn_fd2);
          strcpy(tfield23, w_function[I].fn_fd3);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-077 tfield2 function Not Found \n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield21, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield21a, lw_variable[I].lv_cname);
        ret = strcmp("I", lw_variable[I].lv_type);
        if (ret == 0) 
        {
          fd21_type = 1;
        } 
        else 
        {
          fd21_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield21, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield21a, gw_variable[I].gv_cname);
          ret = strcmp("I", gw_variable[I].gv_type);
          if (ret == 0) 
          {
            fd21_type = 1;
          } 
          else 
          {
            fd21_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-078 tfield21 Not Found = %s\n", tfield21);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd4_type == 1) && (fd21_type == 1)) /* integer to integer	*/
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield21a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield21);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 three var #1");
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
        strcpy(trace_1, "c2z_math.c c2_math_6 three var #2");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 three var #3");
        trace_rec_3();
      }
    }

    if ((fd4_type == 1) && (fd21_type == 2)) /* integer to char ERROR	*/
    {
      printf("\nc2z_math.c c2_math_6 math-079 comma = 2 Numeric to Char move ERROR\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd4_type == 2) && (fd21_type == 1)) /* char to integer ERROR	*/
    {
      printf("\nc2z_math.c c2_math_6 math-080 comma = 2 Char to Numeric move ERROR\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd4_type == 2) && (fd21_type == 2)) /* char to char		*/
    {
      strcpy(a_string, "         MVC2  ");
      strcat(a_string, tfield21a);
      strcat(a_string, ",");
      strcat(a_string, tfield4a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 three var #4");
        trace_rec_3();
      }
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield22, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield22a, lw_variable[I].lv_cname);
        ret = strcmp("I", lw_variable[I].lv_type);
        if (ret == 0) 
        {
          fd22_type = 1;
        } 
        else 
        {
          fd22_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield22, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield22a, gw_variable[I].gv_cname);
          ret = strcmp("I", gw_variable[I].gv_type);
          if (ret == 0) 
          {
            fd22_type = 1;
          } 
          else 
          {
            fd22_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-081 tfield22 Not Found = %s\n", tfield22);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd5_type == 1) && (fd22_type == 1)) 		/* integer to integer	*/
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield22a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield22);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 three var #5");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 three var #6");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 three var #7");
        trace_rec_3();
      }
    }

    if ((fd5_type == 1) && (fd22_type == 2)) 		/* integer to char ERROR	*/
    {
      printf("\nc2z_math.c c2_math_6 math-082 comma = 2 Numeric to Char move ERROR\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd5_type == 2) && (fd22_type == 1)) 		/* char to integer ERROR	*/
    {
      printf("\nc2z_math.c c2_math_6 math-083 comma = 2 Char to Numeric move ERROR\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd5_type == 2) && (fd22_type == 2)) 		/* char to char		*/
    {
      strcpy(a_string, "         MVC2  ");
      strcat(a_string, tfield22a);
      strcat(a_string, ",");
      strcat(a_string, tfield5a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #12");
        trace_rec_3();
      }
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield23, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield23a, lw_variable[I].lv_cname);
        ret = strcmp("I", lw_variable[I].lv_type);
        if (ret == 0) 
        {
          fd23_type = 1;
        } 
        else 
        {
          fd23_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield23, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield23a, gw_variable[I].gv_cname);
          ret = strcmp("I", gw_variable[I].gv_type);
          if (ret == 0) 
          {
            fd23_type = 1;
          } 
          else 
          {
            fd23_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_6 math-084 tfield23 Not Found = %s\n", tfield23);
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd6_type == 1) && (fd23_type == 1)) 		/* integer to integer	*/
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield23a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield6);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #13");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield6a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield6);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #14");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #15");
        trace_rec_3();
      }
    }

    if ((fd6_type == 1) && (fd23_type == 2)) 		/* integer to char ERROR	*/
    {
      printf("\nc2z_math.c c2_math_6 math-085 comma = 2 Numeric to Char move ERROR\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd6_type == 2) && (fd23_type == 1)) 		/* char to integer ERROR	*/
    {
      printf("\nc2z_math.c c2_math_6 math-086 comma = 2 Char to Numeric move ERROR\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd6_type == 2) && (fd23_type == 2)) 		/* char to char		*/
    {
      printf("\nc2z_math.c c2_math_6 math-087 comma = 2 Char to Char move NOT CODED\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         BRASL C370LNK,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #16");
      trace_rec_3();
    }

    if ((fd1_type == 1) && (fd3_type == 1)) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[I].lv_cname);
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          x6 = strcmp(tfield1, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
          }
        }
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield3, lw_variable[I].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield3a, lw_variable[I].lv_cname);
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          x6 = strcmp(tfield3, gw_variable[I].gv_name);
          if (x6 == 0) 
          {
            x3 = 1;
            strcpy(tfield4a, gw_variable[I].gv_cname);
          }
        }
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #17");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #18");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_6 comma = 2 #19");
        trace_rec_3();
      }
    }

    if ((fd1_type == 2) && (fd3_type == 2)) 
    {
      printf("\nc2z_math.c c2_math_6 math-088 fd1 & fd3 type == 2 NEED TO BE CODED\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd1_type == 1) && (fd3_type == 2)) 
    {
      printf("\nc2z_math.c c2_math_6 math-089 field1 & field3 MISMATCH ERROR\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd1_type == 2) && (fd3_type == 1)) 
    {
      printf("\nc2z_math.c c2_math_6 math-090 field1 & field3 MISMATCH ERROR\n");
      printf("c2z_math.c c2_math_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    convert = 1;
  }
}

void c2_math_7() 		/* array equal calling subroutine iv_stack[ndx] = rdp_set()  	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_7 START");
    trace_rec_1();
  }

  int pi;
  int pi1 = 0;
  int pi2 = 0;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x6 = 0;
  int x10 = 0;
  int I = 0;
  int v = 0;
  int ret = 0;
  int ret1 = 0;
  int fd2_type = 0;

  char ch, *p;
  char ar_field5[12];
  char ar_field6[12];
  char ar_field7[12];
  char ar_field8[12];
  char ar_field9[12];
  char ar_field10[12];
  char ar_field11[12];
  char wk_sv_func[32];
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field8a[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
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
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
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

  pi++;
  ch = p_string[pi];
  while (ch != '=') 
  {
    pi++;
    ch = p_string[pi];
  }

  /*  dv_stack[ndx] = rdp_start(); */
  /*  fv_stack[ndx] = (float) rdp_start(); */
  /*  lv_stack[ndx] = (long) rdp_start(); */
  /*  iv_stack[ndx] = (int) rdp_start(); */

  pi2 = 0;
  pi++;
  pi1 = pi;
  ch = p_string[pi];
  p = strstr(p_string, "(float)");
  if (!p) 
  {
    p = strstr(p_string, "(long)");
  }
  if (!p) 
  {
    p = strstr(p_string, "(int)");
  }

  if (!p) 
  {
    while (ch != '(') 
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
    x10 = 0;
  }

  if (p) 
  {
    pi = pi1;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != '(') 
      {
        if (ch != ' ') 
        {
          field3[pi2] = ch;
          pi2++;
        }
      }
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';
    x10 = 1;

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != '(') 
      {
        if (ch != ' ') 
        {
          field3[pi2] = ch;
          pi2++;
        }
      }
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';
  }

  strcpy(wk_sv_func, field3);

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field1a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      x6 = strcmp(field1, gw_variable[I].gv_name);
      if (x6 == 0) 
      {
        x3 = 1;
        strcpy(field1a, gw_variable[I].gv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    printf("c2z_math.c c2_math_7 math-091 field1 Not Found = %s\n", field1);
    printf("c2z_math.c c2_math_7 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }



  if (fd2_type == 1) 
  {
/*
    for (v = 0; v < math_lit_ct; v++) 
    {
      if ((rct == w_mathlit[v].lit_rct) && (w_mathlit[v].lit_uct == 1)) 
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, w_mathlit[v].lit_use_cname);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_7 #11");
          trace_rec_3();
        }
      }
    }
*/

printf("FIX FIX FIX c2_math_7 #11\n");
printf("rct = %d p_string = %s",rct,p_string);

  }

  if (fd2_type == 2) 
  {
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
        x6 = strcmp(field2, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("c2z_math.c c2_math_7 math-092 field2 Not Found = %s\n", field2);
      printf("c2z_math.c c2_math_7 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }


  if (x10 == 0) 						/*  function	*/
  {
    x3 = 0;
    for (I = 0; I < fn_ct; I++) 
    {
      x6 = strcmp(field3, w_function[I].fn_name);
      if (x6 == 0) 
      {
        x3 = 1;
        strcpy(field3a, w_function[I].fn_cname);
        strcpy(field4, w_function[I].fn_ret_var);
      }
    }

    if (x3 == 0) 
    {
      printf("c2z_math.c c2_math_7 math-093 field3 function Not Found = %s\n",field3);
      printf("c2z_math.c c2_math_7 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " branch   */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #1");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field8a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(field4, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(field8a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field4a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(field4, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(field4a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("c2z_math.c c2_math_7 math-094 field4 Not Found = %s\n", field4);
      printf("c2z_math.c c2_math_7 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK2"); /*  store return value back into call sub	*/
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #2");
      trace_rec_3();
    }

    strcpy(a_string,"         LARL  R8,"); 			/* return value from called sub 	*/
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #4");
      trace_rec_3();
    }

    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
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

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #5");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #6");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #7");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #8");
      trace_rec_3();
    }

    strcpy(field2, field1);
    strcat(field2, "_rows");

    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(field2, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        x4 = gw_variable[v].gv_lgth;
      }
    }
    x4 = 250;

    strcpy(a_string, "         LA    R5,");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #9");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #11");
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
      strcpy(trace_1, "c2z_math.c c2_math_7 #12");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #13");
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
      strcpy(trace_1, "c2z_math.c c2_math_7 #14");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #17");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #18");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #19");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #20");
      trace_rec_3();
    }

    strcpy(a_string, "         JCTG  R5,");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #21");
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
      strcpy(trace_1, "c2z_math.c c2_math_7 #22");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "H");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #23");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field8a, lw_variable[I].lv_cname);
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #24");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #25");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #26");
      trace_rec_3();
    }

    convert = 1;
  }

  if (x10 == 1) 
  {
    x3 = 0;
    for (I = 0; I < fn_ct; I++) 
    {
      x6 = strcmp(field3, w_function[I].fn_name);
      if (x6 == 0) 
      {
        x3 = 1;
        strcpy(field3a, w_function[I].fn_cname);
        strcpy(field4, w_function[I].fn_ret_var);
      }
    }

    if (x3 == 0) 
    {
      printf("c2z_math.c c2_math_7 math-095 field3 function Not Found = %s\n",field3);
      printf("c2z_math.c c2_math_7 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, field3a);
    strcpy(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #2");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field8a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(field4, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(field8a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field4a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(field4, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(field4a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("c2z_math.c c2_math_7 math-096 field4 Not Found = %s\n", field4);
      printf("c2z_math.c c2_math_7 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK2"); /*  store return value back into call sub	*/
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #3");
      trace_rec_3();
    }

    strcpy(a_string,"         LARL  R8,"); 			/* return value from called sub 	*/
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #5");
      trace_rec_3();
    }

    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
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

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #6");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #7");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #9");
      trace_rec_3();
    }

    strcpy(field2, field1);
    strcat(field2, "_rows");

    for (v = 0; v < gv_ct; v++) 
    {
      ret = strcmp(field2, gw_variable[v].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        x4 = gw_variable[v].gv_lgth;
      }
    }
    x4 = 250;

    strcpy(a_string, "         LA    R5,");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #10");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #11");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #12");
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
      strcpy(trace_1, "c2z_math.c c2_math_7 #13");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #14");
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
      strcpy(trace_1, "c2z_math.c c2_math_7 #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #16");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #17");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #18");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #19");
      trace_rec_3();
    }

    strcpy(a_string, "         JCTG  R5,");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #20");
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
      strcpy(trace_1, "c2z_math.c c2_math_7 #21");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "H");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #22");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field8a, lw_variable[I].lv_cname);
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #23");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #24");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_7 #25");
      trace_rec_3();
    }

    convert = 1;
  }
}

void c2_math_9() 				/* in_stack[ndx][0] = '\0'		*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_9");
    trace_rec_1();
  }

  char ch;
  char fr_type[2];
  char ar_field5[32];
  char ar_field6[32];
  char ar_field7[32];
  char ar_field8[32];
  char ar_field9[32];
  char ar_field10[32];
  char ar_field11[32];

  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field11[VAR_LGTH];
  char field11a[VAR_LGTH];

  int pi;
  int pi2;
  int fr_1 = 0;
  int fr_2 = 0;
  int fr_3 = 0;
  int I = 0;
  int v = 0;
  int x2 = 0;
  int ret = 0;
  int ret1 = 0;
  int fd3_type = 0;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != '[') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  fr_3 = 0;
  if (lv_ct > 0) 
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        fr_3 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        strcpy(fr_type, lw_variable[I].lv_type);
      }
    }
  }

  if (fr_3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          fr_3 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          strcpy(fr_type, gw_variable[I].gv_type);
        }
      }
    }
  }

  fr_2 = strcmp(fr_type, "A");
  if (fr_2 == 0) 
  {
    fr_1 = 3;
  }

  fr_2 = strcmp(fr_type, "G");
  if (fr_2 == 0) 
  {
    fr_1 = 4;
  }

  fr_2 = strcmp(fr_type, "D");
  if (fr_2 == 0) 
  {
    fr_1 = 5;
    printf("c2z_math.c c2_math_9 math-097 fr_2 type not coded\n");
    printf("c2z_math.c c2_math_9 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (fr_1 == 3) 				/* Array A clear	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_9 array-char");
      trace_rec_1();
    }

    fr_3 = 0;
    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          fr_3 = 1;
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

    fr_3 = 0;
    fr_2 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field11, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        fr_3 = 1;
        strcpy(field11a, lw_variable[v].lv_cname);
      }
    }

    if (fr_3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field11, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          fr_3 = 1;
          strcpy(field11a, gw_variable[v].gv_cname);
        }
      }
    }

    if (fr_3 == 0) 
    {
      printf("c2z_math.c c2_math_9 math-098 field11 Not Found = %s\n", field11);
      printf("c2z_math.c c2_math_9 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi2 = 0;
    pi++;
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
    pi2 = 0;
    pi++;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
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
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    fr_3 = 0;
    fr_2 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field2, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        fr_3 = 1;
        strcpy(field2a, lw_variable[v].lv_cname);
      }
    }

    if (fr_3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field2, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          fr_3 = 1;
          strcpy(field2a, gw_variable[v].gv_cname);
        }
      }
    }

    if (fr_3 == 0) 
    {
      printf("c2z_math.c c2_math_9 math-099 field2 Not Found = %s\n", field2);
      printf("c2z_math.c c2_math_9 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd3_type == 2) 
    {
      fr_3 = 0;
      fr_2 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field3, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          fr_3 = 1;
          strcpy(field3a, lw_variable[v].lv_cname);
        }
      }

      if (fr_3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field3, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            fr_3 = 1;
            strcpy(field3a, gw_variable[v].gv_cname);
          }
        }
      }

      if (fr_3 == 0) 
      {
        printf("c2z_math.c c2_math_9 math-100 field3 Not Found = %s\n", field3);
        printf("c2z_math.c c2_math_9 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

    } 
    else 
    {
      strcpy(field3a, field3);
    }

    pi++;
    ch = p_string[pi];
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

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ';') 
    {
      pi++;
      ch = p_string[pi];
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_9 #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R9,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_9 #2");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         ZAP   0(4,R9),0(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_9 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   C370NWK2,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_9 #4");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_9 #5");
      trace_rec_3();
    }

    printf("c2z_math.c c2_math_9 math-101 NOT CODED\n");
    printf("c2z_math.c c2_math_9 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }
 
  if (fr_1 == 4) 				/* Array G clear	*/
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_9 array_numeric");
      trace_rec_1();
    } 

    fr_3 = 0;
    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          fr_3 = 1;
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

    fr_3 = 0;
    fr_2 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field11, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        fr_3 = 1;
        strcpy(field11a, lw_variable[v].lv_cname);
      }
    }

    if (fr_3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field11, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          fr_3 = 1;
          strcpy(field11a, gw_variable[v].gv_cname);
        }
      }
    }

    if (fr_3 == 0) 
    {
      printf("c2z_math.c c2_math_9 math-102 field11 Not Found = %s\n", field11);
      printf("c2z_math.c c2_math_9 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    printf("c2z_math.c c2_math_9 math-103 NOT CODED\n");
    printf("c2z_math.c c2_math_9 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  convert = 1;
}

void c2_math_99() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.math.c c2_math_99 #1 START");
    trace_rec_1();
  }

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
  int fd3_type = 0;
  int fd3m_type = 0;
  int fd5_type = 0;
  int fd7_type = 0;
  int fd9_type = 0;
  int fd11_type = 0;
  int fd13_type = 0;
  int operand_1 = 0;
  int operand_2 = 0;
  int operand_3 = 0;
  int operand_4 = 0;
  int operand_5 = 0;

  char ch;
  char *p15,*p16;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field1b[VAR_LGTH];
  char field1m[VAR_LGTH];
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
        printf("\nc2z_math.c c2_math_99 math-137 += field1 Not Found = %s\n", field1);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #904");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #905");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #906");
        trace_rec_3();
      }

      strcpy(a_string, "         LA    R5,");
      strcat(a_string, field3);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #907");
        trace_rec_3();
      }
       
      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #908");
        trace_rec_3();
      }
      work_use_ct[48]++;
 
      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #909");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #910");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #911");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #912");
        trace_rec_3();
      }
       
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #913");
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
        strcpy(trace_1, "c2z_math.c c2_math_99 #914");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #915");
        trace_rec_3();
      }

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #916");
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
        strcpy(trace_1, "c2z_math.c c2_math_99 #900");
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
        strcpy(trace_1, "c2z_math.c c2_math_99 #901");
        trace_rec_3();
      }

      if(x70 == 1)
      {
        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 #902");
          trace_rec_3();
        }
      }

      if(x71 == 1)
      {
        strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 #902");
          trace_rec_3();
        }
      }
      convert = 1;
      return;
    }
  }

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

/**************************
*   one  math function    *
************************* */
  if((x30 == 1) && (convert == 0))			
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z.math.c c2_math_99 x30 = 1 START");
      trace_rec_1();
    }

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

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
    
    pi2 = 0;
    while(ch != ' ')
    {
      field4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field4[pi2] = '\0';

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

    /****************************************************
    *  Clear out C370MATH Stores working answer         *
    *************************************************** */
    strcpy(a_string, "         LARL  R9,C370MATH");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #1");
      trace_rec_3();
    }
    work_use_ct[39]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #3");
      trace_rec_3();
    }

    /****************************************************
    *  1st var alpha variable                           *
    *************************************************** */
    if(fd3_type == 2)			/* alpha field	*/
    {
      p15 = strstr(field3, "[");
      p16 = strstr(field3, "]");

      if((p15) && (p16))
      {
        pi1 = 0;
        pi2 = 0;
        ch = field3[pi1];
        while(ch != '[')
        {
          pi1++;
          ch = field3[pi1];
        }

        fd3m_type = 0;
        x2 = 0;
        pi1++;
        ch = field3[pi1];
        while(ch != ']')
        {
          if (x2 == 0) 
          {
            if (isalpha(ch)) 
            {
              fd3m_type = 2;
              x2 = 1;
            }
            if (isdigit(ch)) 
            {
              fd3m_type = 1;
              x2 = 1;
            }
          }
          field3m[pi2] = ch;
          pi2++;
          pi1++;
          ch = field3[pi1];
        }
        field3m[pi2] = '\0';

        if(fd3m_type == 1)
        {
          strcpy(a_string, "         LA    R5,");
          strcat(a_string, field3m);
          strcpy(wk_remark, " ");
          strcat(wk_remark, field3m);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #4");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #5");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         CVD   R5,0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #6");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370NWK3");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #7");
            trace_rec_3();
          }
          work_use_ct[78]++;

          strcpy(a_string, "         LARL  R8,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #8");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #9");
            trace_rec_3();
          }
        }

        if(fd3m_type == 2)
        {
          x3 = 0;
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(field3m, lw_variable[v].lv_name);
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
               ret = strcmp(field3m, gw_variable[v].gv_name);
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
            printf("\nc2z_math.c c2_math_99 math-106 x30-1 field3m Not Found = %s\n", field3m);
            printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }

          strcpy(a_string, "         LARL  R9,C370NWK3");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #10");
            trace_rec_3();
          }
          work_use_ct[78]++;

          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, field3a);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #11");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #12");
            trace_rec_3();
          }
        }

        x2 = 0;
        pi1 = 0;
        pi2 = 0;
        ch = field3[pi1];
        while(ch != '[')
        {
          field3b[pi2] = ch;
          pi2++;
          pi1++;
          ch = field3[pi1];
        }
        field3b[pi2] = '\0';
      
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field3b, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              strcpy(ar_field5, gw_variable[I].gv_dsect);
              strcpy(ar_field6, gw_variable[I].gv_label);
              strcpy(ar_field7, gw_variable[I].gv_table);
              strcpy(ar_field8, gw_variable[I].gv_aname);
              strcpy(ar_field9, gw_variable[I].gv_sv_reg);
              strcpy(ar_field10, gw_variable[I].gv_wk_reg);
              x2 = gw_variable[I].gv_lgth;
            }
          }
        }
/*  
printf("c2z_math.c math_99 ar_field5 = %s\n",ar_field5);
printf("c2z_math.c math_99 ar_field6 = %s\n",ar_field6);
printf("c2z_math.c math_99 ar_field7 = %s\n",ar_field7);
printf("c2z_math.c math_99 ar_field8 = %s\n",ar_field8);
printf("c2z_math.c math_99 ar_field9 = %s\n",ar_field9);
printf("c2z_math.c math_99 ar_field10 = %s\n",ar_field10);
*/


        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #13");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #14");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #15");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R6,");
        strcat(a_string, ar_field7);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #16");
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
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #17");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #18");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370NWK3");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #19");
          trace_rec_3();
        }
        work_use_ct[78]++;

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #20");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #21");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #22");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #23");
          trace_rec_3();
        }
        work_use_ct[78]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #24");
          trace_rec_3();
        }

        strcpy(a_string, "         LA    R6,");
        strcat(a_string, ar_field6);
        strcat(a_string, "(R0,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #25");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "T");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #26");
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
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #27");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370MATH");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #28");
          trace_rec_3();
        }
        work_use_ct[39]++;

         strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #29");
          trace_rec_3();
        }
      }

      if((!p15) && (!p16))
      {
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
          printf("\nc2z_math.c c2_math_99 math-107 x30-2 field3 Not Found = %s\n", field3);
          printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
    
        strcpy(a_string, "         LARL  R9,C370MATH");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #30");
          trace_rec_3();
        }
        work_use_ct[39]++;

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field3a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field3);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #31");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #32");
          trace_rec_3();
        }
      }
    }

    /****************************************************
    *  1st var numeric literal                          *
    *************************************************** */
    if(fd3_type == 1)
    {
      strcpy(a_string, "         LA    R5,");
      strcat(a_string, field3);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #33");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #34");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #35");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #36");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #37");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #38");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #39");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #40");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #41");
        trace_rec_3();
      }

      strcpy(a_string,"*");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-1 #42");
        trace_rec_3();
      }
    }


    /****************************************************
    *  1st operand test and define                      *
    *************************************************** */
    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(field4, "+");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "-");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "*");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "/");
      if (p)
      {
        operand_1 = 4;
      }
    }

    x31 = 0;
    p1 = strstr(field5, "()");
    if(p1)
    {
      x31 = 1;
    }

    /****************************************************
    *  2nd var function variable                        *
    *************************************************** */

    p15 = strstr(field5, "[");
    p16 = strstr(field5, "]");

    if((p15) && (p16))
    {
        pi1 = 0;
        pi2 = 0;
        ch = field5[pi1];
        while(ch != '[')
        {
          pi1++;
          ch = field5[pi1];
        }

        fd3m_type = 0;
        x2 = 0;
        pi1++;
        ch = field5[pi1];
        while(ch != ']')
        {
          if (x2 == 0) 
          {
            if (isalpha(ch)) 
            {
              fd3m_type = 2;
              x2 = 1;
            }
            if (isdigit(ch)) 
            {
              fd3m_type = 1;
              x2 = 1;
            }
          }
          field5m[pi2] = ch;
          pi2++;
          pi1++;
          ch = field5[pi1];
        }
        field5m[pi2] = '\0';

        if(fd3m_type == 1)
        {
          strcpy(a_string, "         LAEY  R5,");
          strcat(a_string, field5m);
          strcpy(wk_remark, " ");
          strcat(wk_remark, field5m);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #4");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #5");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         CVD   R5,0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #6");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370NWK3");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #7");
            trace_rec_3();
          }
          work_use_ct[78]++;

          strcpy(a_string, "         LARL  R8,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #8");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #9");
            trace_rec_3();
          }
        }

        if(fd3m_type == 2)
        {
          x3 = 0;
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(field5m, lw_variable[v].lv_name);
            ret1 = strcmp(sv_func, lw_variable[v].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x3 = 1;
              strcpy(field5a, lw_variable[v].lv_cname);
              lw_variable[v].lv_use_ct++;
            }
          }
  
          if (x3 == 0) 
          {
            for (v = 0; v < gv_ct; v++) 
            {
               ret = strcmp(field5m, gw_variable[v].gv_name);
               if (ret == 0) 
               {
                 x3 = 1;
                 strcpy(field5a, gw_variable[v].gv_cname);
                 gw_variable[v].gv_use_ct++;
               }
            }
          }

          if (x3 == 0) 
          {
            printf("\nc2z_math.c c2_math_99 math-108 x30-1 field5m Not Found = %s\n", field5m);
            printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }

          strcpy(a_string, "         LARL  R9,C370NWK3");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #10");
            trace_rec_3();
          }
          work_use_ct[78]++;

          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, field5a);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #11");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #12");
            trace_rec_3();
          }
        }

        x2 = 0;
        pi1 = 0;
        pi2 = 0;
        ch = field5[pi1];
        while(ch != '[')
        {
          field5b[pi2] = ch;
          pi2++;
          pi1++;
          ch = field5[pi1];
        }
        field5b[pi2] = '\0';
      
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field5b, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              strcpy(ar_field5, gw_variable[I].gv_dsect);
              strcpy(ar_field6, gw_variable[I].gv_label);
              strcpy(ar_field7, gw_variable[I].gv_table);
              strcpy(ar_field8, gw_variable[I].gv_aname);
              strcpy(ar_field9, gw_variable[I].gv_sv_reg);
              strcpy(ar_field10, gw_variable[I].gv_wk_reg);
              x2 = gw_variable[I].gv_lgth;
            }
          }
        }

/* 
printf("c2z_math.c math_99 ar_field5 = %s\n",ar_field5);
printf("c2z_math.c math_99 ar_field6 = %s\n",ar_field6);
printf("c2z_math.c math_99 ar_field7 = %s\n",ar_field7);
printf("c2z_math.c math_99 ar_field8 = %s\n",ar_field8);
printf("c2z_math.c math_99 ar_field9 = %s\n",ar_field9);
printf("c2z_math.c math_99 ar_field10 = %s\n",ar_field10);
*/

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #13");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #14");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #15");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, ar_field7);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #16");
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
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #17");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #18");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370NWK3");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #19");
          trace_rec_3();
        }
        work_use_ct[78]++;

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #20");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "W");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #21");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #22");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #23");
          trace_rec_3();
        }
        work_use_ct[78]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #24");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, ar_field6);
        strcat(a_string, "(R0,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #25");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "V");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #26");
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
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #27");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #28");
          trace_rec_3();
        }
        work_use_ct[50]++;

         strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #29");
          trace_rec_3();
        }
    }


    if((x31 == 1) && (fd5_type == 2) && (!p15) && (!p16))
    {
      pi2 = 0;
      pi = 0;
      ch = field5[pi];
      while(ch != '(')
      {
        field5a[pi2] = ch;
        pi2++;
        pi++;
        ch = field5[pi];
      }
      field5a[pi2] = '\0';
      strcpy(field5,field5a);
      strcpy(wk_sv_func, field5a);

      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field5, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field5a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field5, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field5a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0)
      {
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(field5, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field5a, w_function[I].fn_cname);
            strcpy(field6, w_function[I].fn_ret_var);
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_99 math-109 field5 Not Found = %s\n", field5);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R15,");
      strcat(a_string, field5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #17");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #18");
        trace_rec_3();
      }

      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field6, lw_variable[v].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
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
        printf("\nc2z_math.c c2_math_99 math-110 field6 Not Found = %s\n", field6);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #19");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field6a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field6);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #20");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #20a");
        trace_rec_3();
      }

    }


    /****************************************************
    *  2nd var math literal                             *
    *************************************************** */
    if(fd5_type == 1)
    {
      strcpy(a_string, "         LA    R5,");
      strcat(a_string, field5);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #21");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #22");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #23");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #24");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #25");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R7),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #26");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #27");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #28");
        trace_rec_3();
      }
      work_use_ct[50]++;

    }


    /****************************************************
    *  2nd var variable - not function                  *
    *************************************************** */
    if((fd5_type == 2) && (x31 == 0) && (!p15) && (!p16))
    {
      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field5, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field5a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field5, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field5a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_99 math-111 field5 Not Found = %s\n", field5);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #29");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-2 #30");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var_2  #30a");
        trace_rec_3();
      }

    }


    /****************************************************
    *  1st operand_1 math operation                     *
    *************************************************** */
    if(operand_1 == 1)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1 #31");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1 #31a");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1 #31b");
        trace_rec_3();
      }
    }
 
    if(operand_1 == 2)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1 #32");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1 #32a");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1 #32c");
        trace_rec_3();
      }
    }
  
    if(operand_1 == 3)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1 #33");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1 #33a");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         MP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1 #33b");
        trace_rec_3();
      }
    }

    if(operand_1 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1  #34");
        trace_rec_3();
      }
      work_use_ct[40]++;
     
      strcpy(a_string, "         LARL  R8,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1  #35");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1  #36");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1  #37");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1  #38");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1  #39");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1  #40");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1  #41");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1  #42");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1  #43");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370IENT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1  #44");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(1,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-1  #45");
        trace_rec_3();
      }
    }


    if(eol == 1)
    {
      goto end_of_math;
    }


    /****************************************************
    *  2nd operand                                      *
    *************************************************** */
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
    
    s = strlen(p_string);
    s--;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ') 
    {
      field6[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field6[pi2] = '\0';

    /****************************************************
    *  2nd operand test and define                      *
    *************************************************** */
    operand_2 = 0;
    if (operand_2 == 0) 
    {
      p = strstr(field6, "+");
      if (p)
      {
        operand_2 = 1;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field6, "-");
      if (p)
      {
        operand_2 = 2;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field6, "*");
      if (p)
      {
        operand_2 = 3;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field6, "/");
      if (p)
      {
        operand_2 = 4;
      }
    }

    /****************************************************
    *  3rd  math field                                  *
    *************************************************** */
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    s = strlen(p_string);
    s--;
    eol = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ') 
    {
      if(ch == ';')
      {
        eol = 2;
        break;
      }
      if(pi >= s)
      {
        break;
      }

      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd7_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd7_type = 1;
          x2 = 1;
        }
      }
      field7[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field7[pi2] = '\0';

    x31 = 0;
    p1 = strstr(field7, "()");
    if(p1)
    {
      x31 = 1;
    }

    /****************************************************
    *  3rd var math literal                             *
    *************************************************** */
    if((fd7_type == 1) && (x31 == 0))
    {
      strcpy(a_string, "         LA    R5,");
      strcat(a_string, field7);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #46");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #47");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #48");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #49");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #50");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #51");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #52");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #53");
        trace_rec_3();
      }
      work_use_ct[50]++;
    }


    /****************************************************
    *  3nd var function variable                        *
    *************************************************** */
    if((x31 == 1) && (fd7_type == 2))
    {
      pi2 = 0;
      pi = 0;
      ch = field7[pi];
      while(ch != '(')
      {
        field7a[pi2] = ch;
        pi2++;
        pi++;
        ch = field7[pi];
      }
      field7a[pi2] = '\0';
      strcpy(field7,field7a);
      strcpy(wk_sv_func, field7a);

      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field7, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field7a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field7, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field7a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0)
      {
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(field7, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field7a, w_function[I].fn_cname);
            strcpy(field8, w_function[I].fn_ret_var);
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_99 math-112 field7 Not Found = %s\n", field7);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R15,");
      strcat(a_string, field7a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #54");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #55");
        trace_rec_3();
      }

      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field8, lw_variable[v].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
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
        printf("\nc2z_math.c c2_math_99 math-113 field8 Not Found = %s\n", field8);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #56");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field8a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field8);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #57");
        trace_rec_3();
      }
    }


    /****************************************************
    *  2nd var variable - not function                  *
    *************************************************** */
    if((fd7_type == 2) && (x31 == 0))
    {
      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field7, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field7a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field7, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field7a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_99 math-114 field7 Not Found = %s\n", field7);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #58");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field7a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-3 #59");
        trace_rec_3();
      }
    }

    /****************************************************
    *  2nd operand_2 math operation                     *
    *************************************************** */
    if(operand_2 == 1)
    {
      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #60");
        trace_rec_3();
      }
    }
 
    if(operand_2 == 2)
    {
      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #61");
        trace_rec_3();
      }
    }
  
    if(operand_2 == 3)
    {
      strcpy(a_string, "         MP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #62");
        trace_rec_3();
      }
    }

    if(operand_2 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #63");
        trace_rec_3();
      }
      work_use_ct[40]++;
     
      strcpy(a_string, "         LARL  R8,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #64");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #65");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #66");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #67");
        trace_rec_3();
      }
      
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #68");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #70");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #71");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #72");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #73");
        trace_rec_3();
      }
      work_use_ct[39]++;
   
      strcpy(a_string, "         LARL  R9,C370IENT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #74");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(1,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-2  #75");
        trace_rec_3();
      }
    }

    if(eol == 2)
    {
      goto end_of_math;
    }

    /****************************************************
    *  3rd operand                                      *
    *************************************************** */
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
    
    s = strlen(p_string);
    s--;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ') 
    {
      field8[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field8[pi2] = '\0';

    /****************************************************
    *  3rd operand test and define                      *
    *************************************************** */
    operand_3 = 0;
    if (operand_3 == 0) 
    {
      p = strstr(field8, "+");
      if (p)
      {
        operand_3 = 1;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field8, "-");
      if (p)
      {
        operand_3 = 2;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field8, "*");
      if (p)
      {
        operand_3 = 3;
      }
    }

    if (operand_3 == 0) 
    {
      p = strstr(field3, "/");
      if (p)
      {
        operand_3 = 4;
      }
    }

    /****************************************************
    *  4th  math field                                  *
    *************************************************** */
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    s = strlen(p_string);
    s--;
    eol = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ') 
    {
      if(ch == ';')
      {
        eol = 3;
        break;
      }
      if(pi >= s)
      {
        break;
      }

      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd9_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd9_type = 1;
          x2 = 1;
        }
      }
      field9[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field9[pi2] = '\0';

    x31 = 0;
    p1 = strstr(field9, "()");
    if(p1)
    {
      x31 = 1;
    }

    /****************************************************
    *  4th math literal                                 *
    *************************************************** */
    if((fd9_type == 1) && (x31 == 0))
    {
      strcpy(a_string, "         LA    R5,");
      strcat(a_string, field9);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #76");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #77");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #78");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #79");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #80");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #81");
        trace_rec_3();
      }
 
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #82");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #83");
        trace_rec_3();
      }
      work_use_ct[50]++;
    }


    /****************************************************
    *  4th var function variable                        *
    *************************************************** */
    if((x31 == 1) && (fd9_type == 2))
    {
      pi2 = 0;
      pi = 0;
      ch = field7[pi];
      while(ch != '(')
      {
        field9a[pi2] = ch;
        pi2++;
        pi++;
        ch = field9[pi];
      }
      field9a[pi2] = '\0';
      strcpy(field9,field7a);
      strcpy(wk_sv_func, field9a);

      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field9, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field9a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field9, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field9a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0)
      {
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(field9, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field9a, w_function[I].fn_cname);
            strcpy(field10, w_function[I].fn_ret_var);
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_99 math-115 field9 Not Found = %s\n", field9);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R15,");
      strcat(a_string, field9a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #84");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #85");
        trace_rec_3();
      }

      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field10, lw_variable[v].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
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
        printf("\nc2z_math.c c2_math_99 math-116 field10 Not Found = %s\n", field10);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #86");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field10a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field10);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #87");
        trace_rec_3();
      }
    }


    /****************************************************
    *  4th var variable - not function                  *
    *************************************************** */
    if((fd9_type == 2) && (x31 == 0))
    {
      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field9, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field9a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field9, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field9a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_99 math-117 fieldd9 Not Found = %s\n", field9);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #88");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field9a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Var-4 #89");
        trace_rec_3();
      }
    }

    /****************************************************
    *  3rd operand_3 math operation                     *
    *************************************************** */
    if(operand_3 == 1)
    {
      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-3  #90");
        trace_rec_3();
      }
    }
 
    if(operand_3 == 2)
    {
      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-3  #91");
        trace_rec_3();
      }
    }
  
    if(operand_3 == 3)
    {
      strcpy(a_string, "         MP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-3  #92");
        trace_rec_3();
      }
    }

    if(operand_3 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 Op-3  #93");
        trace_rec_3();
      }
      work_use_ct[40]++;
     
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field6a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field6);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #30");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #31");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #32");
        trace_rec_3();
      }
      work_use_ct[43]++;

/*        strcpy(a_string, "         LARL  R8,C370M98");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 #33");
          trace_rec_3();
        }
        work_use_ct[13]++;
*/
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #34");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #35");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #36");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #37");
        trace_rec_3();
      }
    }

    if(eol == 3)
    {
      goto end_of_math;
    }

    /****************************************************
    *  4rd operand                                      *
    *************************************************** */
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
    
    s = strlen(p_string);
    s--;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ') 
    {
      field10[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field10[pi2] = '\0';

    /****************************************************
    *  4th operand test and define                      *
    *************************************************** */
    operand_4 = 0;
    if (operand_4 == 0) 
    {
      p = strstr(field10, "+");
      if (p)
      {
        operand_4 = 1;
      }
    }

    if (operand_4 == 0) 
    {
      p = strstr(field10, "-");
      if (p)
      {
        operand_4 = 2;
      }
    }

    if (operand_4 == 0) 
    {
      p = strstr(field10, "*");
      if (p)
      {
        operand_4 = 3;
      }
    }

    if (operand_4 == 0) 
    {
      p = strstr(field10, "/");
      if (p)
      {
        operand_4 = 4;
      }
    }

    /****************************************************
    *  5th  math field                                  *
    *************************************************** */
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    s = strlen(p_string);
    s--;
    eol = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ') 
    {
      if(ch == ';')
      {
        eol = 3;
        break;
      }
      if(pi >= s)
      {
        break;
      }

      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd11_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd11_type = 1;
          x2 = 1;
        }
      }
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';

    x31 = 0;
    p1 = strstr(field11, "()");
    if(p1)
    {
      x31 = 1;
    }

    /****************************************************
    *  5th math literal                                 *
    *************************************************** */
    if((fd11_type == 1) && (x31 == 0))
    {
      strcpy(a_string, "         LA    R5,");
      strcat(a_string, field11);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #18");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #19");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #20");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #21");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #22");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #23");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #24");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #25");
        trace_rec_3();
      }
      work_use_ct[50]++;
    }


    /****************************************************
    *  5th var function variable                        *
    *************************************************** */
    if((x31 == 1) && (fd11_type == 2))
    {
      pi2 = 0;
      pi = 0;
      ch = field11[pi];
      while(ch != '(')
      {
        field11a[pi2] = ch;
        pi2++;
        pi++;
        ch = field11[pi];
      }
      field11a[pi2] = '\0';
      strcpy(field11,field11a);
      strcpy(wk_sv_func, field11a);

      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field11, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field11a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field11, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field11a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0)
      {
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(field11, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field11a, w_function[I].fn_cname);
            strcpy(field12, w_function[I].fn_ret_var);
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_99 math-118 field11 Not Found = %s\n", field11);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R15,");
      strcat(a_string, field11a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #14");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #15");
        trace_rec_3();
      }

      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field12, lw_variable[v].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field12a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field12, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field12a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

     if (x3 == 0) 
     {
        printf("\nc2z_math.c c2_math_99 math-119 field12 Not Found = %s\n", field12);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #16");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field12a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field12);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #17");
        trace_rec_3();
      }
    }


    /****************************************************
    *  2nd var variable - not function                  *
    *************************************************** */
    if((fd11_type == 2) && (x31 == 0))
    {
      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field11, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field11a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field11, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field11a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_99 math-120 field11 Not Found = %s\n", field11);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #24");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field11a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #25");
        trace_rec_3();
      }
    }

    /****************************************************
    *  3rd operand_4 math operation                     *
    *************************************************** */
    if(operand_3 == 1)
    {
      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #26");
        trace_rec_3();
      }
    }
 
    if(operand_4 == 2)
    {
      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #27");
        trace_rec_3();
      }
    }
  
    if(operand_4 == 3)
    {
      strcpy(a_string, "         MP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #28");
        trace_rec_3();
      }
    }

    if(operand_4 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #29");
        trace_rec_3();
      }
      work_use_ct[40]++;
     
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field6a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field6);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #30");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #31");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #32");
        trace_rec_3();
      }
      work_use_ct[43]++;

/*        strcpy(a_string, "         LARL  R8,C370M98");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 #33");
          trace_rec_3();
        }
        work_use_ct[13]++;
*/
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #34");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #35");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #36");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #37");
        trace_rec_3();
      }
    }

    if(eol == 3)
    {
      goto end_of_math;
    }



    /****************************************************
    *  5rd operand                                      *
    *************************************************** */
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
    
    s = strlen(p_string);
    s--;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ') 
    {
      field12[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field12[pi2] = '\0';

    /****************************************************
    *  5th operand test and define                      *
    *************************************************** */
    operand_5 = 0;
    if (operand_5 == 0) 
    {
      p = strstr(field12, "+");
      if (p)
      {
        operand_5 = 1;
      }
    }

    if (operand_5 == 0) 
    {
      p = strstr(field12, "-");
      if (p)
      {
        operand_5 = 2;
      }
    }

    if (operand_5 == 0) 
    {
      p = strstr(field12, "*");
      if (p)
      {
        operand_5 = 3;
      }
    }

    if (operand_5 == 0) 
    {
      p = strstr(field12, "/");
      if (p)
      {
        operand_5 = 4;
      }
    }

    /****************************************************
    *  6th  math field                                  *
    *************************************************** */
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    s = strlen(p_string);
    s--;
    eol = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ') 
    {
      if(ch == ';')
      {
        eol = 4;
        break;
      }
      if(pi >= s)
      {
        break;
      }

      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd13_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd13_type = 1;
          x2 = 1;
        }
      }
      field13[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field13[pi2] = '\0';

    x31 = 0;
    p1 = strstr(field13, "()");
    if(p1)
    {
      x31 = 1;
    }

    /****************************************************
    *  6th math literal                                 *
    *************************************************** */
    if((fd11_type == 1) && (x31 == 0))
    {
      strcpy(a_string, "         LA    R5,");
      strcat(a_string, field13);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #18");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #19");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #20");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #21");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #22");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #23");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #24");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #25");
        trace_rec_3();
      }
      work_use_ct[50]++;
    }


    /****************************************************
    *  6th var function variable                        *
    *************************************************** */
    if((x31 == 1) && (fd13_type == 2))
    {
      pi2 = 0;
      pi = 0;
      ch = field13[pi];
      while(ch != '(')
      {
        field13a[pi2] = ch;
        pi2++;
        pi++;
        ch = field13[pi];
      }
      field13a[pi2] = '\0';
      strcpy(field13,field13a);
      strcpy(wk_sv_func, field13a);

      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field13, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field13a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field13, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field13a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0)
      {
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(field13, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field13a, w_function[I].fn_cname);
            strcpy(field14, w_function[I].fn_ret_var);
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_99 math-121 field13 Not Found = %s\n", field13);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R15,");
      strcat(a_string, field13a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #14");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #15");
        trace_rec_3();
      }

      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field14, lw_variable[v].lv_name);
        ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field14a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field14, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field14a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

     if (x3 == 0) 
     {
        printf("\nc2z_math.c c2_math_99 math-122 field14 Not Found = %s\n", field14);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #16");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field14a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field14);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #17");
        trace_rec_3();
      }
    }


    /****************************************************
    *  6nd var variable - not function                  *
    *************************************************** */
    if((fd13_type == 2) && (x31 == 0))
    {
      x3 = 0;
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(field13, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field13a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
  
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(field13, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field13a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_99 math-123 field13 Not Found = %s\n", field13);
        printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #24");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field13a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #25");
        trace_rec_3();
      }
    }

    /****************************************************
    *  5rd operand_5 math operation                     *
    *************************************************** */
    if(operand_5 == 1)
    {
      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #26");
        trace_rec_3();
      }
    }
 
    if(operand_5 == 2)
    {
      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #27");
        trace_rec_3();
      }
    }
  
    if(operand_5 == 3)
    {
      strcpy(a_string, "         MP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #28");
        trace_rec_3();
      }
    }

    if(operand_5 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #29");
        trace_rec_3();
      }
      work_use_ct[40]++;
     
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field6a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field6);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #30");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 x30 #31");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #32");
        trace_rec_3();
      }
      work_use_ct[43]++;

/*        strcpy(a_string, "         LARL  R8,C370M98");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 #33");
          trace_rec_3();
        }
        work_use_ct[13]++;
*/
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #34");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #35");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #36");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 #37");
        trace_rec_3();
      }
    }

    if(eol == 4)
    {
      goto end_of_math;
    }



   end_of_math:

    /****************************************************
    *  store C370NWK1 into result variable - field1     *
    *************************************************** */

    p15 = strstr(field1, "[");
    p16 = strstr(field1, "]");

    if((p15) && (p16))
    {
        pi1 = 0;
        pi2 = 0;
        ch = field1[pi1];
        while(ch != '[')
        {
          field1b[pi2] = ch;
          pi2++;
          pi1++;
          ch = field1[pi1];
        }
        field1b[pi2] = '\0';

        fd3m_type = 0;
        pi2 = 0;
        x2 = 0;
        pi1++;
        ch = field1[pi1];
        while(ch != ']')
        {
          if (x2 == 0) 
          {
            if (isalpha(ch)) 
            {
              fd3m_type = 2;
              x2 = 1;
            }
            if (isdigit(ch)) 
            {
              fd3m_type = 1;
              x2 = 1;
            }
          }
          field1m[pi2] = ch;
          pi2++;
          pi1++;
          ch = field1[pi1];
        }
        field1m[pi2] = '\0';

        if(fd3m_type == 1)
        {
          strcpy(a_string, "         LA    R5,");
          strcat(a_string, field1m);
          strcpy(wk_remark, " ");
          strcat(wk_remark, field1m);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 END #1");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 END #2");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         CVD   R5,0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 END #3");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370NWK3");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 END #4");
            trace_rec_3();
          }
          work_use_ct[78]++;

          strcpy(a_string, "         LARL  R8,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 END #5");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 END #6");
            trace_rec_3();
          }
        }

        if(fd3m_type == 2)
        {

          x3 = 0;
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(field1m, lw_variable[v].lv_name);
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
               ret = strcmp(field1m, gw_variable[v].gv_name);
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
            printf("\nc2z_math.c c2_math_99 math-124 x30-1 field1m Not Found = %s\n", field1m);
            printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }

          strcpy(a_string, "         LARL  R9,C370NWK3");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 END #7");
            trace_rec_3();
          }
          work_use_ct[78]++;

          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, field1a);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 END #8");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_99 END #9");
            trace_rec_3();
          }
        }

        x2 = 0;
        pi1 = 0;
        pi2 = 0;
        ch = field3[pi1];
        while(ch != '[')
        {
          field3b[pi2] = ch;
          pi2++;
          pi1++;
          ch = field3[pi1];
        }
        field3b[pi2] = '\0';
      
        if (gv_ct > 0) 
        {
          for (I = 0; I < gv_ct; I++) 
          {
            ret = strcmp(field1b, gw_variable[I].gv_name);
            if (ret == 0) 
            {
              strcpy(ar_field5, gw_variable[I].gv_dsect);
              strcpy(ar_field6, gw_variable[I].gv_label);
              strcpy(ar_field7, gw_variable[I].gv_table);
              strcpy(ar_field8, gw_variable[I].gv_aname);
              strcpy(ar_field9, gw_variable[I].gv_sv_reg);
              strcpy(ar_field10, gw_variable[I].gv_wk_reg);
              x2 = gw_variable[I].gv_lgth;
            }
          }
        }
 
/* 
printf("c2z_math.c math_99 ar_field5 = %s\n",ar_field5);
printf("c2z_math.c math_99 ar_field6 = %s\n",ar_field6);
printf("c2z_math.c math_99 ar_field7 = %s\n",ar_field7);
printf("c2z_math.c math_99 ar_field8 = %s\n",ar_field8);
printf("c2z_math.c math_99 ar_field9 = %s\n",ar_field9);
printf("c2z_math.c math_99 ar_field10 = %s\n",ar_field10);
*/

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #10");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #11");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #12");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R6,");
        strcat(a_string, ar_field7);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #13");
          trace_rec_3();
        }

        strcpy(a_string, "L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "R");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #14");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #15");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370NWK3");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #16");
          trace_rec_3();
        }
        work_use_ct[78]++;

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #17");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "S");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #18");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #19");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #20");
          trace_rec_3();
        }

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #21");
          trace_rec_3();
        }

        strcpy(a_string, "         LA    R6,");
        strcat(a_string, ar_field6);
        strcat(a_string, "(R0,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #22");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "R");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #23");
          trace_rec_3();
        }

        strcpy(a_string, "L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "S");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #24");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370MATH");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #25");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R6),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_99 END #26");
          trace_rec_3();
        } 

      convert = 1;
      return;
    }


    if((!p15) && (!p16))
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_99 END #90");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370MATH");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_99 END #91");
      trace_rec_3();
    }
    work_use_ct[39]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_99 END #92");
      trace_rec_3();
    }

    convert = 1;
    return;

  }
}



/* *****************************************************
*  Punch xxx[] = yyy[]                                 *
* **************************************************** */
void c2_math_98() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_98 START");
    trace_rec_1();
  }

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
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];

  int pi;
  int pi2;
  int x2 = 0;
  int m5_3 = 0;
  int m5_6 = 0;
  int m5_7 = 0;
  int m5fd1_type = 0;
  int m5fd2_type = 0;
  int m5fd3_type = 0;
  int m5fd4_type = 0;
  int I = 0;
  int s = 0;
  int ret = 0;
  int ret1 = 0;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  m5fd1_type = 0;

  while (ch != '[') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  m5_3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      m5_3 = 1;
      strcpy(field1a, lw_variable[I].lv_cname);
      m5_7 = strcmp(lw_variable[I].lv_type, "I");
      if (m5_7 == 0) 
      {
        m5fd1_type = 1;
      }

      m5_7 = strcmp(lw_variable[I].lv_type, "C");
      if (m5_7 == 0) 
      {
        m5fd1_type = 2;
      }

      m5_7 = strcmp(lw_variable[I].lv_type, "G");
      if (m5_7 == 0) 
      {
        m5fd1_type = 3;
      }
    }
  }

  if (m5_3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      m5_6 = strcmp(field1, gw_variable[I].gv_name);
      if (m5_6 == 0) 
      {
        m5_3 = 1;
        strcpy(field1a, gw_variable[I].gv_cname);
        m5_7 = strcmp(gw_variable[I].gv_type, "I");
        if (m5_7 == 0) 
        {
          m5fd1_type = 1;
        }

        m5_7 = strcmp(gw_variable[I].gv_type, "C");
        if (m5_7 == 0) 
        {
          m5fd1_type = 2;
        }

        m5_7 = strcmp(gw_variable[I].gv_type, "G");
        if (m5_7 == 0) 
        {
          m5fd1_type = 3;
        }

        strcpy(field5, gw_variable[I].gv_dsect);
        strcpy(field6, gw_variable[I].gv_label);
        strcpy(field7, gw_variable[I].gv_table);
        strcpy(field8, gw_variable[I].gv_aname);
        strcpy(field9, gw_variable[I].gv_sv_reg);
        strcpy(field10, gw_variable[I].gv_wk_reg);
      }
    }
  }

  if (m5_3 == 0) 
  {
    printf("\nc2z_math.c c2_math_98 math-125 field1 Not Found = %s\n", field1);
    printf("c2z_math.c c2_math_99 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi++;
  ch = p_string[pi];
  pi2 = 0;
  x2 = 0;
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
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  while (ch != '=') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  s = strlen(p_string);
  while ((pi < s) && (ch != '[')) 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        m5fd3_type = 2;
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        m5fd3_type = 1;
        x2 = 1;
      }
    }
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  m5_3 = 0;
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(field3, gw_variable[I].gv_name);
    if (ret == 0) 
    {
      m5_3 = 1;
      strcpy(field3a, gw_variable[I].gv_cname);
      m5_7 = strcmp(gw_variable[I].gv_type, "I");
      if (m5_7 == 0) 
      {
        m5fd3_type = 1;
      }

      m5_7 = strcmp(gw_variable[I].gv_type, "C");
      if (m5_7 == 0) 
      {
        m5fd3_type = 2;
      }

      m5_7 = strcmp(gw_variable[I].gv_type, "G");
      if (m5_7 == 0) 
      {
        m5fd3_type = 3;
      }

      strcpy(ar_field5, gw_variable[I].gv_dsect);
      strcpy(ar_field6, gw_variable[I].gv_label);
      strcpy(ar_field7, gw_variable[I].gv_table);
      strcpy(ar_field8, gw_variable[I].gv_aname);
      strcpy(ar_field9, gw_variable[I].gv_sv_reg);
      strcpy(ar_field10, gw_variable[I].gv_wk_reg);
    }
  }

  if (m5_3 == 0) 
  {
    printf("\nc2z_math.c c2_math_98 math-126 field3 Not Found = %s\n", field3);
    printf("c2z_math.c c2_math_98 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi++;
  ch = p_string[pi];
  pi2 = 0;
  x2 = 0;
  while (ch != ']') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        m5fd4_type = 2;
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        m5fd4_type = 1;
        x2 = 1;
      }
    }
    field4[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';
  field4a[0] = '\0';

  if (m5fd4_type == 2) 
  {
    m5_3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        m5_3 = 1;
        strcpy(field4a, lw_variable[I].lv_cname);
      }
    }

    if (m5_3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        m5_6 = strcmp(field4, gw_variable[I].gv_name);
        if (m5_6 == 0) 
        {
          m5_3 = 1;
          strcpy(field4a, gw_variable[I].gv_cname);
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("\nc2z_math.c c2_math_98 math-127 field4 Not Found = %s\n", field4);
      printf("c2z_math.c c2_math_98 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if ((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 3) && (m5fd4_type == 2)) 
  {
    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #4");
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
      strcpy(trace_1, "c2z_math.c c2_math_98 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #6");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if (m5fd2_type == 1) 			/* numeric literal	*/
    {
/*
      for (v = 0; v < math_lit_ct; v++) 
      {
        if ((rct == w_mathlit[v].lit_rct) && (w_mathlit[v].lit_uct == 1)) 
        {
          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, w_mathlit[v].lit_use_cname);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_98 #7a");
            trace_rec_3();
          }
          x9 = w_mathlit[v].lit_use_rct;
          break;
        }
      }

      for (v = 0; v < math_lit_ct; v++) 
      {
        if ((rct == w_mathlit[v].lit_rct) && (w_mathlit[v].lit_uct == 2)) 
        {
          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, w_mathlit[v].lit_use_cname);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_98 #7b");
            trace_rec_3();
          }
          break;
        }
      }
*/
    }

    if (m5fd2_type == 2) 			/* alpha field	*/
    {
      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1;
          strcpy(field2a, lw_variable[I].lv_cname);
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field2, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("\nc2z_math.c c2_math_98 math-128 field2 Not Found = %s\n", field2);
        printf("c2z_math.c c2_math_98 rct = %d p_string = %s", rct, p_string);
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
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_98 #7");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #11");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #12");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #13");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #14");
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
      strcpy(trace_1, "c2z_math.c c2_math_98 #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #16");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #17");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #18");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R5,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #19");
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
      strcpy(trace_1, "c2z_math.c c2_math_98 #20");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #21");
      trace_rec_3();
    }
    work_use_ct[49]++;

/*
    if ((m5fd4_type == 1) && (m5fd2_type == 1)) 
    {
      for (v = 0; v < math_lit_ct; v++) 
      {
        if (rct == w_mathlit[v].lit_rct) 
        {
          x9 = w_mathlit[v].lit_use_rct;
        }
      }
    }

    for (v = 0; v < math_lit_ct; v++) 
    {
      if (x9 == w_mathlit[v].lit_rct) 
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, w_mathlit[v].lit_use_cname);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_98 #22");
          trace_rec_3();
        }
        break;
      }
    }
*/

    if (m5fd4_type == 2) 			/* alpha field	*/
    {
      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field4, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1;
          strcpy(field4a, lw_variable[I].lv_cname);
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field4, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1;
            strcpy(field4a, gw_variable[I].gv_cname);
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("\nc2z_math.c c2_math_98 math-129 field4 Not Found = %s\n", field4);
        printf("c2z_math.c c2_math_98 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field4a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field4);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_98 #22");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #23");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #24");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R5,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #25");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #26");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #27");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #28");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #29");
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
      strcpy(trace_1, "c2z_math.c c2_math_98 #30");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #31");
      trace_rec_3();
    }

    convert = 1;
  }

  if ((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 3) && (m5fd4_type == 1)) 
  {
    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #50");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #51");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #52");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #53");
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
      strcpy(trace_1, "c2z_math.c c2_math_98 #54");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #55");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if (m5fd2_type == 1) 				/* numeric literal	*/
    {
/*
      for (v = 0; v < math_lit_ct; v++) 
      {
        if ((rct == w_mathlit[v].lit_rct) && (w_mathlit[v].lit_uct == 1)) 
        {
          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, w_mathlit[v].lit_use_cname);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_98 #56a");
            trace_rec_3();
          }
          x9 = w_mathlit[v].lit_use_rct;
          break;
        }
      }
      for (v = 0; v < math_lit_ct; v++) 
      {
        if ((rct == w_mathlit[v].lit_rct) && (w_mathlit[v].lit_uct == 2)) 
        {
          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, w_mathlit[v].lit_use_cname);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_98 #56b");
            trace_rec_3();
          }
          break;
        }
      }
*/

printf("FIX FIX FIX c2_math_98 #56b\n");
printf("rct = %d p_string = %s",rct,p_string);

    }

    if (m5fd2_type == 2) 
    {
      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1;
          strcpy(field2a, lw_variable[I].lv_cname);
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field2, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("\nc2z_math.c c2_math_98 math-130 field2 Not Found = %s\n", field2);
        printf("c2z_math.c c2_math_98 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */ ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_98 #57");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #58");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #59");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #60");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #61");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #62");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #63");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #64");
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
      strcpy(trace_1, "c2z_math.c c2_math_98 #65");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #66");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #67");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #68");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R5,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #69");
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
      strcpy(trace_1, "c2z_math.c c2_math_98 #70");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #71");
      trace_rec_3();
    }
    work_use_ct[49]++;

/*
    if ((m5fd4_type == 1) && (m5fd2_type == 1)) 
    {
      for (v = 0; v < math_lit_ct; v++) 
      {
        if (rct == w_mathlit[v].lit_rct) 
        {
          x9 = w_mathlit[v].lit_use_rct;
        }
      }
    }

    for (v = 0; v < math_lit_ct; v++) 
    {
      if (x9 == w_mathlit[v].lit_rct) 
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, w_mathlit[v].lit_use_cname);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c c2_math_98 #72");
          trace_rec_3();
        }
        break;
      }
    }


    if ((m5fd4_type == 1) && (m5fd2_type == 2)) 
    {
      for (v = 0; v < math_lit_ct; v++) 
      {
        if (rct == w_mathlit[v].lit_rct) 
        {
          x9 = w_mathlit[v].lit_use_rct;
          break;
        }
      }

      for (v = 0; v < math_lit_ct; v++) 
      {
        if (x9 == w_mathlit[v].lit_rct) 
        {
          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, w_mathlit[v].lit_use_cname);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c c2_math_98 #73");
            trace_rec_3();
          }
          break;
        }
      }
    }
*/

printf("FIX FIX FIX c2_math_98 #73\n");
printf("rct = %d p_string = %s",rct,p_string);


    if ((m5fd4_type == 2) && (m5fd2_type == 1)) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field4a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field4);
      strcat(wk_remark, " */ ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_98 #74");
        trace_rec_3();
      }
    }

    if ((m5fd4_type == 2) && (m5fd2_type == 2))
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field4a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field4);
      strcat(wk_remark, " */ ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_98 #75");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #76");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #77");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R5,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #78");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #79");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #80");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #81");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #82");
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
      strcpy(trace_1, "c2z_math.c c2_math_98 #83");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_98 #84");
      trace_rec_3();
    }

    convert = 1;
  }

  if ((m5fd1_type == 2) && (m5fd2_type == 2) && (m5fd3_type == 2) && (m5fd4_type == 2)) 
  {

  }

}


void c2_math_52() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_52 START");
    trace_rec_1();
  }

  char *p1, *p2, *p3;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield6a[VAR_LGTH];

  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
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
  char field11[VAR_LGTH];

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x10 = 0;
  int x80 = 0;
  int x87 = 0;
  int m5_3 = 0;
  int m5_6 = 0;
  int m5_7 = 0;
  int m5fd1_type = 0;
  int m5fd2_type = 0;
  int m5fd3_type = 0;
  int I = 0;
  int s = 0;
  int ret = 0;
  int ret1 = 0;

  p1 = strstr(p_string, "[");
  p2 = strstr(p_string, "]");
  p3 = strstr(p_string, ".");

  if ((p1) && (p2) && (!p3)) 
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    m5fd1_type = 0;
    while (ch != '[') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    m5_3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        m5_3 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        m5_7 = strcmp(lw_variable[I].lv_type, "I");
        if (m5_7 == 0) 
        {
          m5fd1_type = 2;
        }

        m5_7 = strcmp(lw_variable[I].lv_type, "C");
        if (m5_7 == 0) 
        {
          m5fd1_type = 1;
        }
      }
    }

    if (m5_3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        m5_6 = strcmp(field1, gw_variable[I].gv_name);
        if (m5_6 == 0) 
        {
          m5_3 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          m5_7 = strcmp(gw_variable[I].gv_type, "I");
          if (m5_7 == 0) 
          {
            m5fd1_type = 2;
          }

          m5_7 = strcmp(gw_variable[I].gv_type, "C");
          if (m5_7 == 0) 
          {
            m5fd1_type = 1;
          }

          m5_7 = strcmp(gw_variable[I].gv_type, "G");
          if (m5_7 == 0) 
          {
            m5fd1_type = 3;
          }
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("\nc2z_math.c c2_math_52 math-132 field1 Not Found = %s\n", field1);
      printf("c2z_math.c c2_math_52 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    x2 = 0;
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
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    if (m5fd2_type == 2)
    {    
      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1;
          strcpy(field2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          m5_7 = strcmp(lw_variable[I].lv_type, "I");
          if (m5_7 == 0) 
          {
          }

          m5_7 = strcmp(lw_variable[I].lv_type, "C");
          if (m5_7 == 0) 
          {
          }
        }
      }
    }

    if (m5_3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        m5_6 = strcmp(field2, gw_variable[I].gv_name);
        if (m5_6 == 0) 
        {
          m5_3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          m5_7 = strcmp(gw_variable[I].gv_type, "I");
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("\nc2z_math.c c2_math_52 math-133 field2 Not Found = %s\n", field2);
      printf("c2z_math.c c2_math_52 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

    while (ch != '=') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    x10 = 0;
    x2 = 0;
    pi2 = 0;
    s = strlen(p_string);
    while ((pi < s) && (ch != ';')) 
    {
      if (ch == '\'') 
      {
        x10 = 1;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          m5fd3_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          m5fd3_type = 1;
          x2 = 1;
        }
      }
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    if ((m5fd3_type == 2) && (x10 == 0)) 
    {
      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1;
          strcpy(field3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field3, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1;
            strcpy(field3a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("\nc2z_math.c c2_math_52 math-134 field3 Not Found = %s\n", field3);
        printf("c2z_math.c c2_math_52 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if (x10 == 0)
    {
        x2 = 0;
        ret = strcmp("0", field3);
        if(ret == 0)
        {
          strcpy(field3a, "C370ZERO");
          x2 = 1;
        }

        if(x2 == 0)
        {
          ret = strcmp("1", field3);
          if(ret == 0)
          {
            strcpy(field3a, "C370ONE");
            x2 = 1;
          }
        }
    }

    if (x10 == 1) 
    {
      for (I = 0; I < char_ct; I++) 
      {
        if (w_charlit[I].clit_rct == rct) 
        {
          strcpy(field3a, w_charlit[I].clit_cname);
          x3 = w_charlit[I].clit_lgth;
        }
      }
    }

    x3 = 0;
    s = strlen(p_string);
    for (I = 0; I < s; I++) 
    {
      ch = p_string[I];
      if (ch == '[')
      {
        x3++;
      }
      if (ch == ']')
      {
        x3++;
      }
    }

    if ((m5fd1_type == 1) && (m5fd2_type == 2) && (m5fd3_type == 1)) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 subroutine #1");
        trace_rec_1();
      }

      m5_3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          m5_3 = 1;
        }
      }

      if (m5_3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          m5_6 = strcmp(field1, gw_variable[I].gv_name);
          if (m5_6 == 0) 
          {
            m5_3 = 1;
          }
        }
      }

      if (m5_3 == 0) 
      {
        printf("\nc2z_math.c c2_math_52 math-135 field1 Not Found = %s\n", field1);
        printf("c2z_math.c c2_math_52 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
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
        strcpy(trace_1, "c2z_math.c c2_math_52 field3 type == 1 #10");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 field3 type == 1 #16");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 field3 type == 1 #17");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 field3 type == 1 #18");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 field3 type == 1 #19");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 field3 type == 1 #20");
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
        strcpy(trace_1, "c2z_math.c c2_math_52 field3 type == 1 #21");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R9");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 field3 type == 1 #22");
        trace_rec_3();
      }

      strcpy(a_string, "         AR    R1,R2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 field3 type == 1 #23");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 field3 type == 1 #24");
        trace_rec_3();
      }
      work_use_ct[74]++;

      strcpy(a_string, "         MVC   0(R9,R1),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 field3 type == 1 #25");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "E");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 field3 type == 1 #26");
        trace_rec_3();
      }

      convert = 1;
    }
 

  if ((m5fd1_type == 1) && (m5fd2_type == 2) && (m5fd3_type == 2)) 
  {
    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #4");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    strcpy(wk_remark, " a[x] = ch ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #7");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R2,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #8");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R1,R9");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R1,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #11");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 #12");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 #13");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(");
    strcat(a_string, "R9,R1),");
    strcat(a_string, "0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #14");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 #15");
      trace_rec_3();
    }

    math_convert = 1;
  }

  if ((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 2)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array");
      trace_rec_1();
    }

    if (gv_ct > 0) 
    {
      field7[0] = '\0';
      field8[0] = '\0';
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
          strcpy(field11, gw_variable[I].gv_wk_strg);
        }
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_52 array #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, field6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #10");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #6");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 array #7");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #8");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, field6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #11");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #12");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #13");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #14");
      trace_rec_3();
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "H");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #15");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 array #16");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 array #17");
      trace_rec_3();
    }

    convert = 1;
  }

  if ((m5fd1_type == 3) && (m5fd2_type == 1) && (m5fd3_type == 1)) 
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
          strcpy(field11, gw_variable[I].gv_wk_strg);
        }
      }
    }

/*
    for (I = 0; I < math_lit_ct; I++) 
    {
      if ((w_mathlit[I].lit_rct == rct) && (w_mathlit[I].lit_uct == 1)) 
      {
        strcpy(field2a, w_mathlit[I].lit_use_cname);
      }
    }

    for (I = 0; I < math_lit_ct; I++) 
    {
      if ((w_mathlit[I].lit_rct == rct) && (w_mathlit[I].lit_uct == 2)) 
      {
        strcpy(field3a, w_mathlit[I].lit_use_cname);
      }
    }
*/

printf("FIX FIX FIX c2_math_52\n");
printf("rct = %d p_string = %s",rct,p_string);


    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_52 #100");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #101");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #102");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #103");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 #104");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1)
    {
      strcpy(trace_1, "c2z_math_c c2_math_52 #105");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #106");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #107");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #108");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_52 #109");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #110");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #111");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, field6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #112");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) {
      strcpy(trace_1, "c2z_math.c c2_math_5 #113");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 #114");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #115");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #116");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  if ((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 1)) 
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
          strcpy(field11, gw_variable[I].gv_wk_strg);
        }
      }
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
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
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_52 math-136 field2 Not Found = %s\n", field2);
      printf("c2z_math.c c2_math_52 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_52 #200");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #201");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #202");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #203");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 #204");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_52 #205");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 #206");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #207");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #208");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c c2_math_52 #209");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #210");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #211");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, field6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #212");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 #213");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 #214");
      trace_rec_3();
    }

    if(m5fd3_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      strcat(a_string, "(R0,R6)");
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 #230");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 #231");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 #232");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 #233");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 #234");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 #235");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R6),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_52 #216");
        trace_rec_3();
      }
    }

    convert = 1;
    return;
  }

  if ((p1) && (p2) && (p3)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 Structure");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
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
    while (ch != '[') 
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

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if (ch != '.') 
      {
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
 
    x87 = 0;
    p1 = strstr(p_string, "\'");
    if(p1)
    {

      while (ch != '\'') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      while (ch != ';') 
      {
        if (ch == '\'')
        {
          x87 = 1;
        }
        if (ch != '\'') 
        {
          tfield5[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield5[pi2] = '\0';
    }

    if(!p1)
    {
      pi++;
      ch = p_string[pi];
      while(ch == ' ')
      {
        pi++;
        ch = p_string[pi];
      }

      pi++;
      ch = p_string[pi];
      while(ch == ' ')
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      while (ch != ';') 
      {
        if (ch != '\'') 
        {
          tfield5[pi2] = ch;
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
      tfield5[pi2] = '\0';
    }

    x3 = 0;
    for (I = 0; I < m_struc_ct; I++) 
    {
      ret = strcmp(tfield1, w_struc[I].st_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield1a, w_struc[I].st_cwname);
        strcpy(tfield6a, w_struc[I].st_cname);
        break;
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2z_math_5 Structure math-137 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_52 math-138 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_math.c c2_math_52 rct = %d p_string = %s", rct, p_string);
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
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2z_math_5 Structure math-139 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2z_math_5 Structure tfield3 Not Found = %s\n", tfield3);
      printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (x87 == 0) 
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
        printf("\nc2z_math.c c2_math_5 math-140 tfield5 Not Found = %s\n", tfield5);
        printf("c2z_math.c c2_math_5 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #4");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #6");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #7");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #8");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
            strcat(a_string, tfield6a);
            strcat(a_string, "L");
            strcat(a_string, "(R0,R6)");
            src_line();
            if(puncde == 1)
                    {
                            strcpy(trace_1, "c2z_math.c c2_math_5 Struc #10");
                            trace_rec_3();
                    }
    

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #11");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #12");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #13");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #14");
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
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #15");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
    strcpy(a_string, "         ZAP   ");
    strcat(a_string, wk_strg);
    strcat(a_string, "(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_52 Struc #17");
      trace_rec_3();
    } 
  }

  convert = 1;
}



void c2_math_58() 			/*  s_holder[0] = (int)xxxchar;  iv_stack[ndx] = rdp_main(); */
{

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_58 START");
    trace_rec_1();
  }

  int pi = 0;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while((ch == ' ') || (ch == '\t') || (ch == '{'))
  {
    pi++;
    ch = p_string[pi];
  }


  convert = 1;
  return;
}


void c2_math_600()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_math_600 START");
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

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];
  char ar_field12[VAR_LGTH];

  int pi = 0;
  int pi2 = 0;
  int x2 = 0;
  int x3 = 0;
  int x21 = 0;
  int x100 = 0;
  int I = 0;
  int ret = 0;
  int fd2_type;
  int fd3_type;
  int fd4_type;
  int fd5_type;
  int sv_type;
  int x101;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != '[') 
  {
    if (ch != '*') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield1[pi2] = '\0';

  pi2 = 0;
  fd2_type = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if (ch != ' ') 
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
  }
  tfield2[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  fd3_type = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
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
      pi++;
      ch = p_string[pi];
    }
  }
  tfield3[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  fd4_type = 0;
  pi++;
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
      tfield4[pi2] = ch;
      pi2++;
    } 
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

  pi++;
  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
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
  while (ch != ';') 
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
    tfield5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield5[pi2] = '\0';

  x21 = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    x21 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x21 == 0)) 
    {
      x3 = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    x101 = 0;
    x3 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield1a, gw_variable[I].gv_cname);
        strcpy(ar_field5, gw_variable[I].gv_dsect);
        strcpy(ar_field6, gw_variable[I].gv_label);
        strcpy(ar_field7, gw_variable[I].gv_table);
        strcpy(ar_field8, gw_variable[I].gv_aname);
        strcpy(ar_field9, gw_variable[I].gv_sv_reg);
        strcpy(ar_field10, gw_variable[I].gv_wk_reg);
        strcpy(ar_field11, gw_variable[I].gv_wk_strg);
        strcpy(ar_field12, gw_variable[I].gv_st_col);
        x101 = gw_variable[I].gv_lgth;

        p = strstr(gw_variable[I].gv_type, "A");
        if(p)
        {
          sv_type = 2;
        }

        p = strstr(gw_variable[I].gv_type, "G");
        if(p)
        {
          sv_type = 1;
        }

        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_pass_2.c c2_pass2_600 E-603 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_pass_2.c c2_pass2_600 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }
 
  if(fd2_type == 2)
  {
    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        x100 = lw_variable[I].lv_lgth;
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, gw_variable[I].gv_cname);
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_pass2_600 E-604 tfield2 Not Found = %s\n",tfield2);
      printf("c2z_pass_2.c c2_pass2_600 rct = %d p_string = %s\n",rct,p_string);
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
      ret = strcmp(tfield3, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield3a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield3, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield3a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_pass2_600 E-605 tfield3 Not Found = %s\n",tfield3);
      printf("c2z_pass_2.c c2_pass2_600 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd4_type == 2)
  {
    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield4, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield4a,lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield4a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_pass_2.c c2_pass2_600 E-606 tfield4 Not Found = %s\n",tfield4);
      printf("c2z_pass_2.c c2_pass2_600 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd4_type == 1)
  {
    strcpy(tfield4a, tfield4);
  }

  if(fd5_type == 2)
  {
    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield5, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield5a,lw_variable[I].lv_cname);
        x100 = lw_variable[I].lv_lgth;
        break;
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield5, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield5a, gw_variable[I].gv_cname);
          x100 = gw_variable[I].gv_current_lgth;
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_600 E-607 tfield5 Not Found = %s\n",tfield5);
      printf("c2z_math.c c2_math_600 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd5_type == 1)
  {
    strcpy(tfield5a, tfield5);
  }

  if(fd5_type == 0)
  {
    pi = 1;
    x2 = 0;
    ch = tfield5[pi];
    while(ch != '\'')
    {
      tfield5a[x2] = ch;
      x2++;
      pi++;
      ch = tfield5[pi];
    }
    tfield5a[x2] = '\0';
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #3");
    trace_rec_3();
  }

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #4a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #4b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #4c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #4d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #4e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #4f");
      trace_rec_3();
    }
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_600 #4g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #5");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #6");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #7");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #9");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #10");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #11");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #12");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #13");
    trace_rec_3();
  }

  if(fd3_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");   
    strcat(a_string, tfield3);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #14a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R4,C370U");  
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #14b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R4)"); 
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #14c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #14d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R4,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #14e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R7),0(8,R4)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #14f");
      trace_rec_3();
    }
  }

  if(fd3_type == 2)
  {
    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_600 #14g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R5,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #15");
    trace_rec_3();
  }
 
  strcpy(a_string, "         AP    0(6,R7),0(6,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #16");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #17");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #18");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #19");
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
    strcpy(trace_1, "c2z_math.c c2_math_600 #20");
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
    strcpy(trace_1, "c2z_math.c c2_math_600 #21");
    trace_rec_3();
  }

  if(fd3_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield3);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #22a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #22b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #22c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #22d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #22e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #22f");
      trace_rec_3();
    }
  }

  if(fd3_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_600 #22g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #23");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #24");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #25");
    trace_rec_3();
  }

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #26a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #26b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #26c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #26d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #26e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #26f");
      trace_rec_3();
    }
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);           /* tfield3a */
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);		/* tfield3 */
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_600 #26g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #27");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #28");
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
    strcpy(trace_1, "c2z_math.c c2_math_600 #29");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #30");
    trace_rec_3();
  }

  if(fd3_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield3);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #31a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #31b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #31c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #31d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #31e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #31f");
      trace_rec_3();
    }
  }

  if(fd3_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_600 #31");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #32");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #33");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #34");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #35");
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
    strcpy(trace_1, "c2z_math.c c2_math_600 #36");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #37");
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
    strcpy(trace_1, "c2z_math.c c2_math_600 #38");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #39");
    trace_rec_3();
  }

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #40a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #40b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #40c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #40d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #40e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #40f");
      trace_rec_3();
    }
  }

  if(fd3_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_600 #40g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #41");
    trace_rec_3();
  }

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #42a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #42b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #42c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #42d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #42e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #42f");
      trace_rec_3();
    }
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_600 #42g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #43");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #44");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #45");
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
    strcpy(trace_1, "c2z_math.c c2_math_600 #46");
    trace_rec_3();
  }

/*  C370NWK1 contains pointer to array element */

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #47");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #48");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #49");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, ar_field7);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #50");
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
    strcpy(trace_1, "c2z_math.c c2_math_600 #51");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #52");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #53");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #54");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #55");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #56");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #57");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #58");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #59");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #60");
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
    strcpy(trace_1, "c2z_math.c c2_math_600 #61");
    trace_rec_3();
  }

  if(fd5_type == 0)	/* literal */
  {
    for(I = 0; I < char_ct; I++)
    {
      if(rct == w_charlit[I].clit_rct)
      {
        x100 = w_charlit[I].clit_lgth;
        break;
      }
    }

    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, w_charlit[I].clit_cname);
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #62");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x100);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #63");
      trace_rec_3();
    }
  }

  if(fd5_type == 1)
  {
    if(sv_type == 1)
    {
      strcpy(a_string, "         LARL  R5,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_600 #64");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_600 #65");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_600 #66");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK3");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_600 #67");
        trace_rec_3();
      }
      work_use_ct[78]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_600 #68");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_600 #69");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R6),0(6,R8)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_600 #70");
        trace_rec_3();
      }
    }
  }

  if(fd5_type == 2)
  {
    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, tfield5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #71");
      trace_rec_3();
    }

    if(sv_type == 1)
    {
      strcpy(a_string, "         ZAP   0(6,R6),0(6,R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_600 #72");
        trace_rec_3();
      }
    }  

    if(sv_type == 2)
    {
      strcpy(a_string, "         MVC   ");
      strcat(a_string, "0");
      strcat(a_string, "(");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
      strcat(a_string, wk_strg);
      strcat(a_string, ",R6),0(R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_600 #73");
        trace_rec_3();
      }
    }
  }
}

void c2_math_601()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strstr.c c2_math_601 START");
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
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];
  char ar_field12[VAR_LGTH];

  int pi = 0;
  int pi2 = 0;
  int x2 = 0;
  int x3 = 0;
  int x21 = 0;
  int x100 = 0;
  int I = 0;
  int ret = 0;
  int fd2_type;
  int fd3_type;
  int fd5_type;
  int sv_type;
  int x101;
  int x110;

  x110 = 0;
  x2 = strlen(p_string);
  for(I = 0; I < x2; I++)
  {
    if(p_string[I] == '{')
    {
      x110++;
    }
    if(p_string[I] == ']')
    {
      x110++;
    }
  }
  /* **************************************************
   * wk_row[ ] = cellnum[ ];
   * ************************************************ */
  if(x110 == 2)
  {
/* printf("c2z_math.c math_601 INSIDE x110 = 2\n"); */


    convert = 1;
    return;
  }
  
  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
/*
  ch = p_string[pi];
  while (ch != ' ') 
  {

    if (ch != '*') 
    {
      tfield0[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield0[pi2] = '\0';
printf("c2z_math.c math_601 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c math_601 tfield0 = %s\n", tfield0);
*/
printf("c2z_math.c math_601 rct = %d p_string = %s",rct,p_string);

/*  pi++; */
  ch = p_string[pi];
  while (ch != '[') 
  {
    if (ch != '*') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  tfield1[pi2] = '\0';
printf("c2z_math.c math_601 tfield1 = %s\n",tfield1);

  pi2 = 0;
  fd2_type = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if (ch != ' ') 
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
  }
  tfield2[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  fd3_type = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
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
      pi++;
      ch = p_string[pi];
    }
  }
  tfield3[pi2] = '\0';

  pi++;
  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
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
  while (ch != ';') 
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
    tfield5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield5[pi2] = '\0';

  x21 = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    x21 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x21 == 0)) 
    {
      x3 = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    x101 = 0;
    x3 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield1a, gw_variable[I].gv_cname);
        strcpy(ar_field5, gw_variable[I].gv_dsect);
        strcpy(ar_field6, gw_variable[I].gv_label);
        strcpy(ar_field7, gw_variable[I].gv_table);
        strcpy(ar_field8, gw_variable[I].gv_aname);
        strcpy(ar_field9, gw_variable[I].gv_sv_reg);
        strcpy(ar_field10, gw_variable[I].gv_wk_reg);
        strcpy(ar_field11, gw_variable[I].gv_wk_strg);
        strcpy(ar_field12, gw_variable[I].gv_st_col);
        x101 = 6;
 
        p = strstr(gw_variable[I].gv_type, "A");
        if(p)
        {
          sv_type = 2;
        }

        p = strstr(gw_variable[I].gv_type, "G");
        if(p)
        {
          sv_type = 1;
        }

        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_math.c math_601 E-603 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_math.c math_601 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  if(fd2_type == 1)
  {
    strcpy(tfield2a, tfield2);
  }
 
  if(fd2_type == 2)
  {
    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        x100 = lw_variable[I].lv_lgth;
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, gw_variable[I].gv_cname);
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c math_601 E-604 tfield2 Not Found = %s\n",tfield2);
      printf("c2z_math.c math_601 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd3_type == 1)
  {
    strcpy(tfield3a,tfield3);
  }

  if(fd3_type == 2)
  {
    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield3, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield3a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield3, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield3a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c math_601 E-605 tfield3 Not Found = %s\n",tfield3);
      printf("c2z_math.c math_601 rct = %d p_string = %s\n",rct,p_string);
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
      ret = strcmp(tfield5, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(tfield5a,lw_variable[I].lv_cname);
        x100 = lw_variable[I].lv_lgth;
        break;
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield5, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield5a, gw_variable[I].gv_cname);
          x100 = gw_variable[I].gv_current_lgth;
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_601 E-607 tfield5 Not Found = %s\n",tfield5);
      printf("c2z_math.c c2_math_601 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd5_type == 1)
  {
    strcpy(tfield5a, tfield5);
  }

  if(fd5_type == 0)
  {
    pi = 1;
    x2 = 0;
    ch = tfield5[pi];
    while(ch != '\'')
    {
      tfield5a[x2] = ch;
      x2++;
      pi++;
      ch = tfield5[pi];
    }
    tfield5a[x2] = '\0';
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #3");
    trace_rec_3();
  }

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #4a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #4b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #4c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #4d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #4e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #4f");
      trace_rec_3();
    }
  }
  
  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_601 #4g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #5");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #6");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #7");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #9");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #10");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #11");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #12");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #13");
    trace_rec_3();
  }

  if(fd3_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield3);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #14a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #14b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #14c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #14d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #14e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #14f");
      trace_rec_3();
    }
  }

  if(fd3_type == 2)
  {
    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_601 #14g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R5,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #15");
    trace_rec_3();
  }
 
  strcpy(a_string, "         AP    0(6,R7),0(6,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #16");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_600 #17");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #18");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #19");
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
    strcpy(trace_1, "c2z_math.c c2_math_601 #20");
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
    strcpy(trace_1, "c2z_math.c c2_math_601 #21");
    trace_rec_3();
  }

  if(fd3_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield3);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #22a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #22b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #22c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #22d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #22e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #22f");
      trace_rec_3();
    }
  }

  if(fd3_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_601 #22g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #23");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #24");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #25");
    trace_rec_3();
  }

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #26a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #26b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #26c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #26d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #26e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #26f");
      trace_rec_3();
    }
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_601 #26g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #27");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #28");
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
    strcpy(trace_1, "c2z_math.c c2_math_601 #29");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #30");
    trace_rec_3();
  }

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #31a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #31b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #31c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #31d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #31e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #31f");
      trace_rec_3();
    }
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_601 #31g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #32");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #33");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #34");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #35");
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
    strcpy(trace_1, "c2z_math.c c2_math_601 #36");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #37");
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
    strcpy(trace_1, "c2z_math.c c2_math_601 #38");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #39");
    trace_rec_3();
  }

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #40a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #40b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #40c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #40d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #40e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #40f");
      trace_rec_3();
    }
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_601 #40g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #41");
    trace_rec_3();
  }

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #42a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #42b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #42c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #42d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #42e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #42f");
      trace_rec_3();
    }
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_601 #42g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #43");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #44");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #45");
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
    strcpy(trace_1, "c2z_math.c c2_math_601 #46");
    trace_rec_3();
  }

/*  C370NWK1 contains pointer to array element */

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #47");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #48");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #49");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, ar_field7);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #50");
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
    strcpy(trace_1, "c2z_math.c c2_math_601 #51");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #52");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #53");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #54");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #55");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #56");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #57");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #58");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #59");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_601 #60");
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
    strcpy(trace_1, "c2z_math.c c2_math_601 #61");
    trace_rec_3();
  }

  if(fd5_type == 0)	/* literal */
  {
    for(I = 0; I < char_ct; I++)
    {
      if(rct == w_charlit[I].clit_rct)
      {
        x100 = w_charlit[I].clit_lgth;
        break;
      }
    }

    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, w_charlit[I].clit_cname);
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #62");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x100);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_601 #63");
      trace_rec_3();
    }
  }

  if(fd5_type == 1)
  {
    if(sv_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_601 #64");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_601 #65");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_601 #66");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK3");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_601 #67");
        trace_rec_3();
      }
      work_use_ct[78]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_601 #68");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_601 #69");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R6),0(6,R8)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_601 #70");
        trace_rec_3();
      }
    }
  }

  if(fd5_type == 2)
  {
    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, tfield5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_600 #71");
      trace_rec_3();
    }

    if(sv_type == 1)
    {
      strcpy(a_string, "         ZAP   0(6,R6),0(6,R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_600 #72");
        trace_rec_3();
      }
    }  

    if(sv_type == 2)
    {
      strcpy(a_string, "         MVC   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x100); 
      strcat(a_string, wk_strg); 
      strcat(a_string, "(");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x101);
      strcat(a_string, wk_strg);
      strcat(a_string, ",R6),0(R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c c2_math_600 #73");
        trace_rec_3();
      }
    }
  }
}


void c2_math_700()
{
 if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_700 START");
    trace_rec_1();
  }

  char *p;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

   int pi;
   int pi2;
   int x3;
   int I;
   int ret;
   int ret1;

  p = strstr(p_string, "tm_mday");
  if(p)
  {
    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t'))
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != ' ')
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field1a,lw_variable[I].lv_cname);
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_700 E-701 field1 Not Found = %s\n",field1);
      printf("c2z_math.c c2_math_700 rct = %d p_string = %s\n",rct,p_string);
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
      strcpy(trace_1, "c2z_math.c c2_math_700 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370TIME");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #11");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(2,R9),8(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #12");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #11");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   2(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #12");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        lw_variable[I].lv_current_lgth = 2;
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
          gw_variable[I].gv_current_lgth = 2;
          break;
        }
      }
    }
    return;
  }

  p = strstr(p_string, "tm_mon");
  if(p)
  {
    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t'))
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != ' ')
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field1a,lw_variable[I].lv_cname);
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_700 E-701 field1 Not Found = %s\n",field1);
      printf("c2z_math.c c2_math_700 rct = %d p_string = %s\n",rct,p_string);
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
      strcpy(trace_1, "c2z_math.c c2_math_700 #20");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370TIME");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #21");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(2,R9),5(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #22");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        lw_variable[I].lv_current_lgth = 2;
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
          gw_variable[I].gv_current_lgth = 2;
          break;
        }
      }
    }
    return;
  }

  p = strstr(p_string, "tm_year");
  if(p)
  {
    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t'))
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != ' ')
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field1a,lw_variable[I].lv_cname);
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_700 E-703 field1 Not Found = %s\n",field1);
      printf("c2z_math.c c2_math_700 rct = %d p_string = %s\n",rct,p_string);
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
      strcpy(trace_1, "c2z_math.c c2_math_700 #30");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370TIME");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #31");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(2,R9),5(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #32");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        lw_variable[I].lv_current_lgth = 4;
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
          gw_variable[I].gv_current_lgth = 4;
          break;
        }
      }
    }
    return;
  }

  p = strstr(p_string, "tm_hour");
  if(p)
  {
    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t'))
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != ' ')
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field1a,lw_variable[I].lv_cname);
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_700 E-703 field1 Not Found = %s\n",field1);
      printf("c2z_math.c c2_math_700 rct = %d p_string = %s\n",rct,p_string);
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
      strcpy(trace_1, "c2z_math.c c2_math_700 #40");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370TIME");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #41");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(2,R9),11(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #42");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        lw_variable[I].lv_current_lgth = 2;
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
          gw_variable[I].gv_current_lgth = 2;
          break;
        }
      }
    }
    return;
  }

  p = strstr(p_string, "tm_min");
  if(p)
  {
    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t'))
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != ' ')
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field1a,lw_variable[I].lv_cname);
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_700 E-703 field1 Not Found = %s\n",field1);
      printf("c2z_math.c c2_math_700 rct = %d p_string = %s\n",rct,p_string);
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
      strcpy(trace_1, "c2z_math.c c2_math_700 #30");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370TIME");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #31");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(2,R9),14(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #32");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        lw_variable[I].lv_current_lgth = 2;
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
          gw_variable[I].gv_current_lgth = 2;
          break;
        }
      }
    }
    return;
  }

  p = strstr(p_string, "tm_sec");
  if(p)
  {
    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t'))
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != ' ')
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field1a,lw_variable[I].lv_cname);
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_700 E-703 field1 Not Found = %s\n",field1);
      printf("c2z_math.c c2_math_700 rct = %d p_string = %s\n",rct,p_string);
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
      strcpy(trace_1, "c2z_math.c c2_math_700 #30");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370TIME");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #31");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(2,R9),17(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c c2_math_700 #32");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        lw_variable[I].lv_current_lgth = 2;
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
          gw_variable[I].gv_current_lgth = 2;
          break;
        }
      }
    }
    return;
  }
}


