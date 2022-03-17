/* ***************************************************
*  c2z : c2z_math.c :                                *
*                                                    *
*  next error math-139                               *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ****************************************************************************
*      Math functions ( =, +, -, *, / ) MUST BE LAST CALL IN PARSER           *
* *************************************************************************** */

void c2_math() 
{
  char *p, *p1, *p2;
  char ch;
  char ch1[1];
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
  int x501P1 = 0;
  int x502P = 0;
  int x502m = 0;
  int x502e = 0;

  x100 = 0;
  x501 = 0;
  x501L1 = 0;
  x501R1 = 0;
  x501L2 = 0;
  x501R2 = 0;
  x501P1 = 0;
  x502P = 0;
  x502e = 0;
  x502m = 0;

  s = strlen(p_string);
  for(I = 0; I < s; I++)
  {
    if(p_string[I] == '=')
    {
      x501 = I;
      x502e++;
    }
    if(p_string[I] == '(')
    {
      x502P++;
    }
    if(p_string[I] == ')')
    {
      x502P++;
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
    if(p_string[I] == '.')
    {
      x501P1++;
    }
    if(p_string[I] == '+')
    {
      if(p_string[I + 1] != '\'')
      {
        x502m++;
      }
    }
    if(p_string[I] == '-')
    {
      if(p_string[I + 1] == ' ')
      {
        x502m++;
      }
    }
    if(p_string[I] == '*')
    {
      x502m++;
    }
    if(p_string[I] == '/')
    {
      x502m++;
    }
  }

  pi = 0;
  pi2 = 0;
  ch = p_string[pi];
  while((ch == ' ') || (ch == '\t'))
  {
     pi++;
     ch = p_string[pi];
  }

  while(ch != '[')
  {
    if(ch == ' ')
    {
      break;
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
    x2 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x2 == 0)) 
    {
      x3 = 1;
      strcpy(field1a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
      strcpy(ch1,lw_variable[I].lv_type);
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
        strcpy(ch1, gw_variable[I].gv_type);
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_math.c c2_math math-000 field1 Not Found = %s\n", field1);
    printf("c2z_math.c c2_math rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }
/* printf("\nc2z_math.c math_000 ch1 = %s x502m = %d\n",ch1,x502m); */


  /* *************************************************************************************************************
   * x501L1 x501R1 x501L2 x501R2 x501P1 x502m  x502P  ch                                                         *
   *    0      0      0      0      0             0    I   c2_math_500   a = 7;                                  *
   *    1      1      0      0      1      0      0        c2_math_501   gw_variable[2].gv_rct;                  *
   *    2      2      0      0      0             0        c2_math_502   spreadsheet[x][z] = y;                  *
   *    1      1      0      0      0             0        c2_math_503   iv_stack[2] = 444;                      *
   *    0      0      1      1      0             0        c2_math_504   ch = p_string[pi];                      *
   *    0      0      0      0      0      0     >0        c2_math_505-1 xyz = iswhite();                        *
   *                                                                                -2 ndx = getindx(varname);   *
   *                                                                                -3 a = getnum(a,b);          *
   *                                                                                   b = getalpha(x,y,x);      * 
   *    1      1      2      2      0             0     c2_math-506   s_holder[ii] = sv_stack[n][m]);            *
   *    1      1      1      1      0             0     c2_math_507   p_string[x] = prog_name[y];                *
   *    0      0      0      0      0      >0     0     c2_math_508   line_ndx = start + 1;                      *
   *                                                    c2_math_509                                              *
   *    0      0      0      0      0      1      2     c2_             value = value / factor();                *
   * *********************************************************************************************************** */ 

/*
if(rct == 333)
{
 printf("c2z_math.c rct = %d p_string = %s",rct,p_string);
 printf("c2z_math.c x501L1 = %d\n",x501L1);
 printf("c2z_math.c x501R1 = %d\n",x501R1);
 printf("c2z_math.c x501L2 = %d\n",x501L2);
 printf("c2z_math.c x501R2 = %d\n",x501R2);
 printf("c2z_math.c x501P1 = %d\n",x501P1); 
 printf("c2z_math.c x501   = %d\n",x501);
 printf("c2z_math.c x502P  = %d\n",x502P);
 printf("c2z_math.c x502m  = %d\n",x502m);
 printf("c2z_math.c x502e  = %d\n",x502e);
}
*/

			/*  a = 7  */
  if((x501L1 == 0) && (x501R1 == 0) && (x501L2 == 0) && (x501R2 == 0) && (x501P1 == 0) && (x502P == 0) && (x502m == 0))
  {
     c2_math_500();
     convert = 1;
     return;
  }

  if((x501L1 == 1) && (x501R1 == 1) && (x501L2 == 0) && (x501R2 == 0) && (x501P1 == 1) && (x502P == 0))
  {
     c2_math_501();
     convert = 1;
     return;
  }

			/* spreadsheet[x][z] = y */
  if((x501L1 == 2) && (x501R1 == 2) && (x501L2 == 0) && (x501R2 == 0) && (x501P1 == 0))	
  {
    c2_math_502();
    convert = 1;
    return;
  }
			/*  (array)  iv_stack[2] = 444;  (char) test[I] = ch;   */
  if((x501L1 == 1) && (x501R1 == 1) && (x501L2 == 0) && (x501R2 == 0) && (x501P1 == 0) && (x502P == 0))
  {
     pi = 0;
     pi2 = 0;
     ch = p_string[pi];
     while((ch == ' ') || (ch == '\t'))
     {
        pi++;
        ch = p_string[pi];
     }

     while(ch != '[')
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
         strcpy(ch1,lw_variable[I].lv_type);
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
           strcpy(ch1, gw_variable[I].gv_type);
           break;
         }
       }
     }

     if (x3 == 0) 
     {
       printf("\nc2z_math.c c2_math math-000 field1 Not Found = %s\n", field1);
       printf("c2z_math.c c2_math rct = %d p_string = %s", rct, p_string);
       erct++;
       convert = 1;
       return;
     }

     x3 = 0;
     x3 = strcmp(ch1,"C");		/*	 char field  */
     if(x3 == 0)
     {
       c2_math_511();
       convert = 1;
       return;
     }

     c2_math_503();			/* array char field */
     convert = 1;
     return;
  }

			/* ch = p_string[pi];	*/
  if((x501L1 == 0) && (x501R1 == 0) && (x501L2 == 1) && (x501R2 == 1) && (x501P1 == 0) && (x502m == 0))
  {
     c2_math_504();
     convert = 1;
     return;
  }

			/*  ndx = get_intndx(varname);  */
  if((x501L1 == 0) && (x501R1 == 0) && (x501L2 == 0) && (x501R2 == 0) && (x501P1 == 0) && (x502P > 0) && (x502m == 0))
  {
     c2_math_505();
     convert = 1;
     return;
  }

			/* s_holder[i] = sv_stack[x][y];	*/
  if((x501L1 == 1) && (x501R1 == 1) && (x501L2 == 2) && (x501R2 == 2) && (x501P1 == 0) && (x502P == 0))
  {
     c2_math_506();
     convert = 1;
     return;
  }

			/* p_string[I] = prog_name[z];	*/
  if((x501L1 == 1) && (x501R1 == 1) && (x501L2 == 1) && (x501R2 == 1) && (x501P1 == 0) && (x502P == 0))
  {
     c2_math_507();
     convert = 1;
     return;
  }

			/*  a = b + 7  */

  if((x501L1 == 0) && (x501R1 == 0) && (x501L2 == 0) && (x501R2 == 0) && (x501P1 == 0) && (x502P == 0) && (x502m > 0))
  {
     c2_math_99();
     convert = 1;
     return;
  }


  if((x501L1 == 1) && (x501R1 == 1) && (x501L2 == 0) && (x501R2 == 0) && (x501P1 == 0) && (x502P > 0))
  {
     c2_math_509(); 
     convert = 1;
     return;
  }

			/* value = value / factor();		*/
  if((x501L1 == 0) && (x501R1 == 0) && (x501L2 == 0) && (x501R2 == 0) && (x501P1 == 0) && (x502P > 0) && (x502m > 0))
  {
     c2_math_510(); 
     convert = 1;
     return;
  }


  p1 = strstr(p_string, "->");
  if(p1)
  {
    c2_math_700();
    convert = 1;
    return;
  }

  if((x501L1 == 0) && (x501R1 == 0) && (x501L2 == 2) && (x501R2 == 2))
  {
    c2_math_920();
    convert = 1;
    return;
  }


  if((x501L1 == 3) && (x501R1 == 3) && (x501L2 == 0) && (x501R2 == 0))
  {
    c2_math_830();
    convert = 1;
    return;
  }

  if((x501L1 == 3) && (x501R1 == 3) && (x501L2 == 1) && (x501R2 == 1))
  {
printf("\nc2z_math.c BEORE c2_math_820\n");

    c2_math_820();
    convert = 1;
    return;
  }

  if(x100 == 6)	/* Math 2 dim CHAR array    */
  {
printf("\nc2z_math.c BEORE c2_math_800\n");

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
        convert = 1;
        return;
      }
    }



 printf("\nc2z_math.c NO NATCH\n");
 printf("c2z_math.c rct = %d p_string = %s",rct,p_string);
 printf("c2z_math.c x501L1 = %d\n",x501L1);
 printf("c2z_math.c x501R1 = %d\n",x501R1);
 printf("c2z_math.c x501L2 = %d\n",x501L2);
 printf("c2z_math.c x501R2 = %d\n",x501R2);
 printf("c2z_math.c x501P1 = %d\n",x501P1); 
 printf("c2z_math.c x501   = %d\n",x501);
 printf("c2z_math.c x502P  = %d\n",x502P);
 printf("c2z_math.c x502m  = %d\n",x502m);


printf("\nc2z_math.c BEORE FALL THROUGH HERE #xxxxx\n");


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
          strcpy(trace_1, "c2z_math.c #1");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #2");
          trace_rec_3();
        }
        work_use_ct[82]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #3");
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
          strcpy(trace_1, "c2z_math.c #4");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #5");
          trace_rec_3();
        }
        work_use_ct[82]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #6");
          trace_rec_3();
        }
        convert = 1;
        return;
      }
    }
  }

 

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


  if ((op_1 == 1) && (L1 == 1) && (R1 == 1) && (L2 == 0) && (R2 == 0) && (x72 == 0) && (x73 == 0)) 
  {
    c2_math_5();
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

}


/* ************************************
*   ch = p_string[pi]       101       *
************************************* */
void c2_math_2() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_2 START");
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
        strcpy(trace_1, "c2z_math.c #40");
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
        strcpy(trace_1, "c2z_math.c #41");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #42");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #43");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #44");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #45");
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
        strcpy(trace_1, "c2z_math.c #46");
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
        strcpy(trace_1, "c2z_math.c #47");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #48");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #49");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #50");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "B");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #51");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #52");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #53");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #54");
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
        strcpy(trace_1, "c2z_math.c #55");
        trace_rec_3();
      }
 
      strcpy(a_string, "         JLU   L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #56");
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
        strcpy(trace_1, "c2z_math.c #57");
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
        strcpy(trace_1, "c2z_math.c #58");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
      strcat(a_string, wk_strg);
      strcat(a_string,"(6,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #59");
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
        strcpy(trace_1, "c2z_math.c #60 ");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #61 ");
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
        strcpy(trace_1, "c2z_math.c #62 ");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(8,R9),0(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #63 ");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #64 ");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R5,0(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #65 ");
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
        strcpy(trace_1, "c2z_math.c #66 ");
        trace_rec_3();
      }

      strcpy(a_string, "         IC    R0,");
      strcat(a_string, "0(R8,");
      strcat(a_string, "(R5))");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #67 ");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #68 ");
        trace_rec_3();
      }

      strcpy(a_string, "         STC   R0,");
      strcat(a_string, "0(0,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #69");
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
          strcpy(trace_1, "c2z_math.c #86");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #87");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVD   R5,0(R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #88");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #89");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #90");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #91");
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
          strcpy(trace_1, "c2z_math.c #92");
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
          strcpy(trace_1, "c2z_math.c #93");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #94");
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
          strcpy(trace_1, "c2z_math.c #95");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #96");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #97");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVB   R5,0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #98");
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
          strcpy(trace_1, "c2z_math.c #99");
          trace_rec_3();
        }

        strcpy(a_string, "         IC    R0,");
        strcat(a_string, "0(R8,");
        strcat(a_string, "(R5))");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #100");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370M02");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #101");
          trace_rec_3();
        }
        work_use_ct[89]++;

        strcpy(a_string, "         STC   R0,");
        strcat(a_string, "0(0,R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #102");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R5,");
        strcat(a_string, "C370M02");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #103");
          trace_rec_3();
        }
        work_use_ct[89]++;

        strcpy(a_string, "         LARL  R9,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #104");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVD   R5,0(R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #105");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #106");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #107");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #108");
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
          strcpy(trace_1, "c2z_math.c #109");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R8),0(6,R9)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #110");
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
        strcpy(trace_1, "c2z_math.c #111");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #112");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #113");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R6,");
      strcat(a_string, field7);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #114");
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
        strcpy(trace_1, "c2z_math.c #115");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #116");
        trace_rec_3();
      }
      work_use_ct[49]++;

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
        strcpy(trace_1, "c2z_math.c #117");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #118");
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
        strcpy(trace_1, "c2z_math.c  #119");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #120");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #121");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #122");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, field6);
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #123");
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
        strcpy(trace_1, "c2z_math.c #124");
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
        strcpy(trace_1, "c2z_math.c #125");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #126");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #127");
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
        strcpy(trace_1, "c2z_math.c #128");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #129");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #130");
        trace_rec_3();
      }

      strcpy(a_string, "         BRASL C370LNK,");
      strcat(a_string, field2a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #131");
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
        strcpy(trace_1, "c2z_math.c #132");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field4a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #133");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #134");
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
      strcpy(trace_1, "c2z_math.c #135");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #136");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #137");
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
      strcpy(trace_1, "c2z_math.c #138");
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
      strcpy(trace_1, "c2z_math.c #139");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #140");
      trace_rec_3();
    }
    work_use_ct[49]++;

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
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #141");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #142");
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
      strcpy(trace_1, "c2z_math.c #143");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #144");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #145");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #146");
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
      strcpy(trace_1, "c2z_math.c #147");
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
      strcpy(trace_1, "c2z_math.c #148");
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
      strcpy(trace_1, "c2z_math.c #149");
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
      strcpy(trace_1, "c2z_math.c #150");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #151");
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
      strcpy(trace_1, "c2z_math.c #152");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #153");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #154");
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
      strcpy(trace_1, "c2z_math.c #155");
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
      strcpy(trace_1, "c2z_math.c #156");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #157");
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
      strcpy(trace_1, "c2z_math.c #158");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #159");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #160");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #161");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #162");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #163");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1)
    {
      strcpy(trace_1, "c2z_math.c #164");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #165");
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
      strcpy(trace_1, "c2z_math.c #166");
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
      strcpy(trace_1, "c2z_math.c #167");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #168");
      trace_rec_3();
    }
  }
}



void c2_math_5() 
{

  char *p1, *p2, *p3;
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
  char field11[VAR_LGTH];

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x10 = 0;
  int x80 = 0;
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
        strcpy(trace_1, "c2z_math.c #169");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #170");
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
        strcpy(trace_1, "c2z_math.c #171");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #172");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #173");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #174");
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
        strcpy(trace_1, "c2z_math.c #175");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R9");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #176");
        trace_rec_3();
      }

      strcpy(a_string, "         AR    R1,R2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #177");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #178");
        trace_rec_3();
      }
      work_use_ct[74]++;

      strcpy(a_string, "         MVC   0(1,R1),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #179");
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
        strcpy(trace_1, "c2z_math.c #180");
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
      strcpy(trace_1, "c2z_math.c #181");
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
      strcpy(trace_1, "c2z_math.c #182");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    strcpy(wk_remark, " a[x] = ch ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #183");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #184");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R2,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #185");
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
      strcpy(trace_1, "c2z_math.c #186");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R1,R9");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #187");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R1,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #188");
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
      strcpy(trace_1, "c2z_math.c #189");
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
      strcpy(trace_1, "c2z_math.c #190");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(");
    strcat(a_string, "1,R1),");
    strcat(a_string, "0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #191");
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
      strcpy(trace_1, "c2z_math.c #192");
      trace_rec_3();
    }

    math_convert = 1;
  }

  if ((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 2)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_5 array");
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
      strcpy(trace_1, "c2z_math_c #193");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #194");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #195");
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
      strcpy(trace_1, "c2z_math.c #196");
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
      strcpy(trace_1, "c2z_math.c #197");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #198");
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
      strcpy(trace_1, "c2z_math.c #199");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #200");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #201");
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
      strcpy(trace_1, "c2z_math.c #202");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1)
    {
      strcpy(trace_1, "c2z_math.c #203");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #204");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #205");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #206");
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
      strcpy(trace_1, "c2z_math.c #207");
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
      strcpy(trace_1, "c2z_math.c #208");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #209");
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

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #210");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #211");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #212");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #213");
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
      strcpy(trace_1, "c2z_math.c #214");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #215");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(m5fd2_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #215a");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #215b");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #215c");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #215d");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #215e");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #215e");
        trace_rec_3();
      }
    }

    if(m5fd2_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #216");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #217");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #218");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #219");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #220");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #221");
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
      strcpy(trace_1, "c2z_math.c #222");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #223");
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
      strcpy(trace_1, "c2z_math.c #224");
      trace_rec_3();
    }

    if(m5fd3_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #215a");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #215b");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #215c");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #215d");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #215e");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #215e");
        trace_rec_3();
      }
    }

    if(m5fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #225");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #226");
      trace_rec_3();
    }

    convert = 1;
  }


  if ((m5fd1_type == 3) && (m5fd2_type == 1) && (m5fd3_type == 2)) 
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

    strcpy(a_string, "         LA    R5,");
    strcat(a_string, field2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #250");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #251");
      trace_rec_3();
    }
    work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #252");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #253");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #254");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #255");
        trace_rec_3();
      }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #256");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #257");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #258");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #259");
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
      strcpy(trace_1, "c2z_math.c #260");
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
      strcpy(trace_1, "c2z_math_c math_5 #706");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_5 #707");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_5 #708");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_5 #709");
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
      strcpy(trace_1, "c2z_math.c math_5 #710");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c math_5 #711");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_5 #712");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_5 #713");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_5 #714");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c math_5 #715");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_5 #716");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_5 #717");
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
      strcpy(trace_1, "c2z_math.c math_5 #718");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_5 #719");
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
      strcpy(trace_1, "c2z_math.c math_5 #720");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_5 #721");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R6),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_5 #722");
      trace_rec_3();
    }

    convert = 1;
    return;
  }

  if ((m5fd1_type == 1) && (m5fd2_type == 2) && (m5fd3_type == 0)) 
  {
      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #xx169");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #xx170");
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
        strcpy(trace_1, "c2z_math.c #xx171");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #xx172");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #xx173");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVB   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #xx174");
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
        strcpy(trace_1, "c2z_math.c #xx175");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R1,R9");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #xx176");
        trace_rec_3();
      }

      strcpy(a_string, "         AR    R1,R2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #xx177");
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
        strcpy(trace_1, "c2z_math.c #xx178");
        trace_rec_3();
      }

      strcpy(a_string, "         MVC   0(1,R1),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #xx179");
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
        strcpy(trace_1, "c2z_math.c #xx180");
        trace_rec_3();
      }

    convert = 1;
    return;
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
      strcpy(trace_1, "c2z_math.c #429");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R9,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #430");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         ZAP   0(4,R9),0(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #431");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   C370NWK2,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #432");
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
      strcpy(trace_1, "c2z_math.c #433");
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
        strcpy(trace_1, "c2z_math.c #434");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #435");
        trace_rec_3();
      }
      work_use_ct[32]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #436");
        trace_rec_3();
      }

      strcpy(a_string, "         LA    R5,");
      strcat(a_string, field3);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #437");
        trace_rec_3();
      }
       
      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #438");
        trace_rec_3();
      }
      work_use_ct[48]++;
 
      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #439");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #440");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #441");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #442");
        trace_rec_3();
      }
       
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #443");
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
        strcpy(trace_1, "c2z_math.c #444");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #445");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #446");
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
        strcpy(trace_1, "c2z_math.c #447");
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
        strcpy(trace_1, "c2z_math.c #448");
        trace_rec_3();
      }

      if(x70 == 1)
      {
        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #449");
          trace_rec_3();
        }
      }

      if(x71 == 1)
      {
        strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #450");
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
        if(ch != ';')
        {
          field3[pi2] = ch;
          pi2++;
        }
        if(ch == ';')
        {
          break;
        }
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
      strcpy(trace_1, "c2z_math.c #451");
      trace_rec_3();
    }
    work_use_ct[39]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #452");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #453");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370ISOR");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #454");
      trace_rec_3();
    }
    work_use_ct[43]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #455");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #456");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370DEND");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #457");
      trace_rec_3();
    }
    work_use_ct[40]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #458");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #459");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #460");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #461");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #462");
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
            strcpy(trace_1, "c2z_math.c #463");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #464");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         CVD   R5,0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #465");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370NWK3");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #466");
            trace_rec_3();
          }
          work_use_ct[78]++;

          strcpy(a_string, "         LARL  R8,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #467");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #468");
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
            strcpy(trace_1, "c2z_math.c #469");
            trace_rec_3();
          }
          work_use_ct[78]++;

          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, field3a);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #470");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #471");
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
          strcpy(trace_1, "c2z_math.c #472");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #473");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #474");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R6,");
        strcat(a_string, ar_field7);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #475");
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
          strcpy(trace_1, "c2z_math.c #476");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #477");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370NWK3");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #478");
          trace_rec_3();
        }
        work_use_ct[78]++;

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #480");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #481");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #482");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #483");
          trace_rec_3();
        }
        work_use_ct[78]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #484");
          trace_rec_3();
        }

        strcpy(a_string, "         LA    R6,");
        strcat(a_string, ar_field6);
        strcat(a_string, "(R0,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #485");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "T");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #486");
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
          strcpy(trace_1, "c2z_math.c #487");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370MATH");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #488");
          trace_rec_3();
        }
        work_use_ct[39]++;

         strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #489");
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
          strcpy(trace_1, "c2z_math.c #490");
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
          strcpy(trace_1, "c2z_math.c #491");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #492");
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
        strcpy(trace_1, "c2z_math.c #493");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #494");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #495");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #496");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #497");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #498");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #499");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #500");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #501");
        trace_rec_3();
      }

      strcpy(a_string,"*");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #502");
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
            strcpy(trace_1, "c2z_math.c #503");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #504");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         CVD   R5,0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #505");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370NWK3");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #506");
            trace_rec_3();
          }
          work_use_ct[78]++;

          strcpy(a_string, "         LARL  R8,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #507");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #508");
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
            strcpy(trace_1, "c2z_math.c #509");
            trace_rec_3();
          }
          work_use_ct[78]++;

          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, field5a);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #510");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #511");
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
          strcpy(trace_1, "c2z_math.c #512");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #513");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #514");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, ar_field7);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #515");
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
          strcpy(trace_1, "c2z_math.c #516");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #517");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370NWK3");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #518");
          trace_rec_3();
        }
        work_use_ct[78]++;

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #519");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "W");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #520");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #521");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #522");
          trace_rec_3();
        }
        work_use_ct[78]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #523");
          trace_rec_3();
        }

        strcpy(a_string, "         LAEY  R6,");
        strcat(a_string, ar_field6);
        strcat(a_string, "(R0,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #524");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "V");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #525");
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
          strcpy(trace_1, "c2z_math.c #526");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #527");
          trace_rec_3();
        }
        work_use_ct[50]++;

         strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #528");
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
        strcpy(trace_1, "c2z_math.c #529");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #530");
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
        strcpy(trace_1, "c2z_math.c #531");
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
        strcpy(trace_1, "c2z_math.c #532");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #533");
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
        strcpy(trace_1, "c2z_math.c #534");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #535");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #536");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #537");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #538");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R7),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #539");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #540");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #541");
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
        strcpy(trace_1, "c2z_math.c #542");
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
        strcpy(trace_1, "c2z_math.c #543");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #544");
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
        strcpy(trace_1, "c2z_math.c #545");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #546");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #547");
        trace_rec_3();
      }
    }
 
    if(operand_1 == 2)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #548");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #549");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #550");
        trace_rec_3();
      }
    }
  
    if(operand_1 == 3)
    {
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #551");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #552");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #553");
        trace_rec_3();
      }
    }

    if(operand_1 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #554");
        trace_rec_3();
      }
      work_use_ct[40]++;
     
      strcpy(a_string, "         LARL  R8,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #555");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #556");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #557");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #558");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #559");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #560");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #561");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #562");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #563");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370IENT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #564");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(1,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #565");
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
        strcpy(trace_1, "c2z_math.c #565");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #566");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #567");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #568");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #569");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #570");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #571");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #572");
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
        strcpy(trace_1, "c2z_math.c #573");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #574");
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
        strcpy(trace_1, "c2z_math.c #575");
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
        strcpy(trace_1, "c2z_math.c #576");
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
        strcpy(trace_1, "c2z_math.c #577");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field7a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #778");
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
        strcpy(trace_1, "c2z_math.c #579");
        trace_rec_3();
      }
    }
 
    if(operand_2 == 2)
    {
      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #580");
        trace_rec_3();
      }
    }
  
    if(operand_2 == 3)
    {
      strcpy(a_string, "         MP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #581");
        trace_rec_3();
      }
    }

    if(operand_2 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #582");
        trace_rec_3();
      }
      work_use_ct[40]++;
     
      strcpy(a_string, "         LARL  R8,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #583");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #584");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #585");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #586");
        trace_rec_3();
      }
      work_use_ct[50]++;
      
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #587");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #588");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #589");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #590");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #591");
        trace_rec_3();
      }
      work_use_ct[39]++;
   
      strcpy(a_string, "         LARL  R9,C370IENT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #592");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(1,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #593");
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
        strcpy(trace_1, "c2z_math.c #594");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #595");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #596");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #597");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #598");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #599");
        trace_rec_3();
      }
 
      strcpy(a_string, "         LARL  R9,C370MATH");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #600");
        trace_rec_3();
      }
      work_use_ct[39]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #601");
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
        strcpy(trace_1, "c2z_math.c #602");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #603");
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
        strcpy(trace_1, "c2z_math.c #604");
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
        strcpy(trace_1, "c2z_math.c #605");
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
        strcpy(trace_1, "c2z_math.c #606");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field9a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #607");
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
        strcpy(trace_1, "c2z_math.c #608");
        trace_rec_3();
      }
    }
 
    if(operand_3 == 2)
    {
      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #609");
        trace_rec_3();
      }
    }
  
    if(operand_3 == 3)
    {
      strcpy(a_string, "         MP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #610");
        trace_rec_3();
      }
    }

    if(operand_3 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #611");
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
        strcpy(trace_1, "c2z_math.c #612");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #613");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #614");
        trace_rec_3();
      }
      work_use_ct[43]++;

/*        strcpy(a_string, "         LARL  R8,C370M98");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #615");
          trace_rec_3();
        }
        work_use_ct[13]++;
*/
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #616");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #617");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #618");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #619");
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
        strcpy(trace_1, "c2z_math.c #620");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #621");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #622");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #623");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #624");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #625");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #626");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #627");
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
        strcpy(trace_1, "c2z_math.c #628");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #629");
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
        strcpy(trace_1, "c2z_math.c #630");
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
        strcpy(trace_1, "c2z_math.c #631");
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
        strcpy(trace_1, "c2z_math.c #632");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field11a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #633");
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
        strcpy(trace_1, "c2z_math.c #634");
        trace_rec_3();
      }
    }
 
    if(operand_4 == 2)
    {
      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #635");
        trace_rec_3();
      }
    }
  
    if(operand_4 == 3)
    {
      strcpy(a_string, "         MP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #636");
        trace_rec_3();
      }
    }

    if(operand_4 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #637");
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
        strcpy(trace_1, "c2z_math.c #638");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #639");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #640");
        trace_rec_3();
      }
      work_use_ct[43]++;

/*        strcpy(a_string, "         LARL  R8,C370M98");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #641");
          trace_rec_3();
        }
        work_use_ct[13]++;
*/
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #642");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #643");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #644");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #645");
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
        strcpy(trace_1, "c2z_math.c #646");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #647");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #648");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #649");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #650");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #651");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #652");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #653");
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
        strcpy(trace_1, "c2z_math.c #654");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #655");
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
        strcpy(trace_1, "c2z_math.c #656");
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
        strcpy(trace_1, "c2z_math.c #657");
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
        strcpy(trace_1, "c2z_math.c #658");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field13a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #659");
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
        strcpy(trace_1, "c2z_math.c #660");
        trace_rec_3();
      }
    }
 
    if(operand_5 == 2)
    {
      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #661");
        trace_rec_3();
      }
    }
  
    if(operand_5 == 3)
    {
      strcpy(a_string, "         MP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #662");
        trace_rec_3();
      }
    }

    if(operand_5 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #663");
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
        strcpy(trace_1, "c2z_math.c #664");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #665");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #666");
        trace_rec_3();
      }
      work_use_ct[43]++;

/*        strcpy(a_string, "         LARL  R8,C370M98");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #667");
          trace_rec_3();
        }
        work_use_ct[13]++;
*/
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #668");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #669");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,C370ISOR");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #670");
        trace_rec_3();
      }
      work_use_ct[43]++;

      strcpy(a_string, "         DP    0(7,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #671");
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
            strcpy(trace_1, "c2z_math.c #672");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #673");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         CVD   R5,0(R9)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #674");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R9,C370NWK3");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #675");
            trace_rec_3();
          }
          work_use_ct[78]++;

          strcpy(a_string, "         LARL  R8,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #676");
            trace_rec_3();
          }
          work_use_ct[48]++;

          strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #677");
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
            strcpy(trace_1, "c2z_math.c #678");
            trace_rec_3();
          }
          work_use_ct[78]++;

          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, field1a);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #679");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_math.c #680");
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
          strcpy(trace_1, "c2z_math.c #681");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #682");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #683");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R6,");
        strcat(a_string, ar_field7);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #684");
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
          strcpy(trace_1, "c2z_math.c #685");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #686");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370NWK3");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #687");
          trace_rec_3();
        }
        work_use_ct[78]++;

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #688");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "S");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #689");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #690");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #691");
          trace_rec_3();
        }

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #692");
          trace_rec_3();
        }

        strcpy(a_string, "         LA    R6,");
        strcat(a_string, ar_field6);
        strcat(a_string, "(R0,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #693");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "R");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #694");
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
          strcpy(trace_1, "c2z_math.c #695");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370MATH");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #696");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R6),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #697");
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
        strcpy(trace_1, "c2z_math.c #698");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370MATH");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #699");
      trace_rec_3();
    }
    work_use_ct[39]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #700");
      trace_rec_3();
    }

    convert = 1;
    return;

  }
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
    strcpy(trace_1, "c2z_math.c #868");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #869");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #870");
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
      strcpy(trace_1, "c2z_math.c #871");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #872");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #873");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #874");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #875");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #876");
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
      strcpy(trace_1, "c2z_math.c #877");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #878");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #879");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #880");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #881");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #882");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #883");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #884");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #885");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #886");
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
      strcpy(trace_1, "c2z_math.c 887");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R4,C370U");  
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #888");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R4)"); 
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #889");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #890");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R4,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #891");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R7),0(8,R4)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #892");
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
      strcpy(trace_1, "c2z_math.c #893");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R5,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #894");
    trace_rec_3();
  }
 
  strcpy(a_string, "         AP    0(6,R7),0(6,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #895");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #896");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #897");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #898");
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
    strcpy(trace_1, "c2z_math.c #899");
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
    strcpy(trace_1, "c2z_math.c #900");
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
      strcpy(trace_1, "c2z_math.c #901");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #902");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #903");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #904");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #905");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #906");
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
      strcpy(trace_1, "c2z_math.c #907");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #908");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #909");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #910");
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
      strcpy(trace_1, "c2z_math.c #911");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #912");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #913");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #914");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #915");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #916");
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
      strcpy(trace_1, "c2z_math.c #917");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #918");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #919");
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
    strcpy(trace_1, "c2z_math.c #920");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #921");
    trace_rec_3();
  }
  work_use_ct[49]++;

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
      strcpy(trace_1, "c2z_math.c #922");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #923");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #924");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #925");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #926");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #927");
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
      strcpy(trace_1, "c2z_math.c #928");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #929");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #930");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #931");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #932");
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
    strcpy(trace_1, "c2z_math.c #933");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c 934");
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
    strcpy(trace_1, "c2z_math.c #935");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #936");
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
      strcpy(trace_1, "c2z_math.c #937");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #938");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #939");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #940");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #941");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #942");
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
      strcpy(trace_1, "c2z_math.c #943");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #944");
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
      strcpy(trace_1, "c2z_math.c #945");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #946");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #947");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #948");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #949");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #950");
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
      strcpy(trace_1, "c2z_math.c #951");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #952");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #953");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #954");
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
    strcpy(trace_1, "c2z_math.c #955");
    trace_rec_3();
  }

/*  C370NWK1 contains pointer to array element */

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #956");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #957");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #958");
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
    strcpy(trace_1, "c2z_math.c #959");
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
    strcpy(trace_1, "c2z_math.c #960");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #960");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #961");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #962");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #963");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #964");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #965");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #966");
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
    strcpy(trace_1, "c2z_math.c #967");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #968");
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
    strcpy(trace_1, "c2z_math.c #969");
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
      strcpy(trace_1, "c2z_math.c #970");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x100);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #971");
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
        strcpy(trace_1, "c2z_math.c #972");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #973");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #974");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK3");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #975");
        trace_rec_3();
      }
      work_use_ct[78]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #976");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #977");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R6),0(6,R8)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #978");
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
      strcpy(trace_1, "c2z_math.c #979");
      trace_rec_3();
    }

    if(sv_type == 1)
    {
      strcpy(a_string, "         ZAP   0(6,R6),0(6,R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #980");
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
        strcpy(trace_1, "c2z_math.c #981");
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
    strcpy(trace_1, "c2z_math.c #982");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #983");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #984");
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
      strcpy(trace_1, "c2z_math.c #985");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #986");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #987");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #988");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #989");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #990");
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
      strcpy(trace_1, "c2z_math.c #991");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #992");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #993");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #994");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #995");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #996");
    trace_rec_3();
  }
  work_use_ct[32]++;
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #997");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #998");
    trace_rec_3();
  }
  work_use_ct[50]++;

  strcpy(a_string, "         LARL  R7,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #999");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1000");
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
      strcpy(trace_1, "c2z_math.c #1001");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1002");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1003");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1004");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1005");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1004");
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
      strcpy(trace_1, "c2z_math.c #1005");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R5,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1006");
    trace_rec_3();
  }
  work_use_ct[33]++;
 
  strcpy(a_string, "         AP    0(6,R7),0(6,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1007");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1008");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1009");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1010");
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
    strcpy(trace_1, "c2z_math.c #1011");
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
    strcpy(trace_1, "c2z_math.c #1012");
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
      strcpy(trace_1, "c2z_math.c #1013");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1014");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1015");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1016");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1017");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1018");
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
      strcpy(trace_1, "c2z_math.c #1019");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1020");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1021");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "Z");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1022");
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
      strcpy(trace_1, "c2z_math.c #1023");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1024");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1025");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1026");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1027");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1028");
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
      strcpy(trace_1, "c2z_math.c #1029");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1030");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1031");
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
    strcpy(trace_1, "c2z_math.c #1032");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1033");
    trace_rec_3();
  }
  work_use_ct[49]++;

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
      strcpy(trace_1, "c2z_math.c #1034");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1035");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1036");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1037");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1038");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1039");
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
      strcpy(trace_1, "c2z_math.c #1040");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1041");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1042");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1043");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1044");
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
    strcpy(trace_1, "c2z_math.c #1045");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1046");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, ar_field12);
  strcpy(wk_remark, " ");
  strcat(wk_remark, ar_field12);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1047");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1048");
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
      strcpy(trace_1, "c2z_math.c #1049");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1050");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1051");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1052");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1053");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1054");
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
      strcpy(trace_1, "c2z_math.c #1055");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1056");
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
      strcpy(trace_1, "c2z_math.c #1057");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1058");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1059");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1060");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1061");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1062");
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
      strcpy(trace_1, "c2z_math.c #1063");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R7,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1064");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1065");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1066");
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
    strcpy(trace_1, "c2z_math.c #1067");
    trace_rec_3();
  }

/*  C370NWK1 contains pointer to array element */

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1068");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1069");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1070");
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
    strcpy(trace_1, "c2z_math.c #1071");
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
    strcpy(trace_1, "c2z_math.c #1072");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1073");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1074");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1075");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1076");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1077");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1078");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1079");
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
    strcpy(trace_1, "c2z_math.c #1080");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1081");
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
    strcpy(trace_1, "c2z_math.c #1082");
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
      strcpy(trace_1, "c2z_math.c #1083");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x100);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1084");
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
        strcpy(trace_1, "c2z_math.c #1085");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #1086");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #1087");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK3");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #1088");
        trace_rec_3();
      }
      work_use_ct[78]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #1089");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #1090");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R6),0(6,R8)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #1091");
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
      strcpy(trace_1, "c2z_math.c #1092");
      trace_rec_3();
    }

    if(sv_type == 1)
    {
      strcpy(a_string, "         ZAP   0(6,R6),0(6,R7)");
      src_line();
      if (puncde == 1) 
      { 
        strcpy(trace_1, "c2z_math.c #1093");
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
        strcpy(trace_1, "c2z_math.c #1094");
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
      strcpy(trace_1, "c2z_math.c #1095");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370TIME");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1096");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(2,R9),5(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1097");
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
      strcpy(trace_1, "c2z_math.c #1098");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370TIME");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1099");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(2,R9),5(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1100");
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
      strcpy(trace_1, "c2z_math.c #1101");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370TIME");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1102");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(2,R9),11(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1103");
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
      strcpy(trace_1, "c2z_math.c #1104");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370TIME");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1105");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(2,R9),14(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1106");
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
      strcpy(trace_1, "c2z_math.c #1107");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370TIME");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1108");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(2,R9),17(R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1109");
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




void c2_math_830()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_830 START");
    trace_rec_1();
  }

   int pi;
   int pi2;
   int x2 = 0;
   int x3;
   int x21;
   int x101;
   int I;
   int ret;

   int fd2_type;
   int fd3_type;

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
  ch = p_string[pi];
  while(ch != ';')
  {
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
    ret = strcmp(field1, lw_variable[I].lv_name);
    x21 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x21 == 0)) 
    {
       x3 = 1;
       strcpy(field1a, lw_variable[I].lv_cname);
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
      printf("\nc2z_printf.c c2_printf_600 E-604 field4 Not Found = %s\n",field4);
      printf("c2z_printf.c c2_printf_600 rct = %d p_string = %s\n",rct,p_string);
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
      printf("\nc2z_printf.c c2_printf_600 E-604 field3 Not Found = %s\n",field3);
      printf("c2z_printf.c c2_printf_600 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

/*
printf("c2z_math.c math_830 rct = %d fd1_type = %d field1 = %s field1a = %s\n",rct,fd1_type,field1,field1a);
printf("c2z_math.c math_830 rct = %d fd2_type = %d field2 = %s field2a = %s\n",rct,fd2_type,field2,field2a);
printf("c2z_math.c math_830 rct = %d fd3_type = %d field3 = %s field3a = %s\n",rct,fd3_type,field3,field3a);
printf("c2z_math.c math_830 rct = %d fd4_type = %d field4 = %s \n",rct,fd4_type,field4);
printf("c2z_math.c math_830 rct = %d fd5_type = %d field5 = %s \n",rct,fd5_type,field5);
*/

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, ar_field7);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1140");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1141");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1142");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1143");
    trace_rec_3();
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " ROW */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1144");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1145");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1146");
      trace_rec_3();
    }

    strcpy(a_string, "         JLNE  L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1147");
      trace_rec_3();
    }

/* loop thru increating the row(i) 26 times then bump up one */

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1148");
      trace_rec_3();
    }
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
      strcpy(trace_1, "c2z_math.c #1149");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1150");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1151");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1152");
      trace_rec_3();
    }
    work_use_ct[94]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1153");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #1154");
      trace_rec_3();
    }
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " COL */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1155");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1156");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1157");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "T");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #1158");
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
    strcpy(trace_1, "c2z_math.c #1159");
    trace_rec_3();
  }


  if(fd3_type == 2)
  {
    strcpy(a_string, "         LARL  R5,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " COL */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1160");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #22");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R5,");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "D");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #23");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "T");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #24");
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
    strcpy(trace_1, "c2z_math.c math_830 #25");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #26");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #27");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #28");
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
    strcpy(trace_1, "c2z_math.c math_830 #29");
    trace_rec_3();
  }
  
  strcpy(a_string, "         LARL  R5,26");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #30");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #31");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R5,");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #32");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #33");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #34");
    trace_rec_3();
  }
 
  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #35");
    trace_rec_3();
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " ROW */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_830 #36");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #37");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #38");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #39");
    trace_rec_3();
  }

 if(fd3_type == 2)
  {
    strcpy(a_string, "         LARL  R5,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " COL */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_830 #40");
      trace_rec_3();
    }
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
    strcpy(trace_1, "c2z_math.c math_830 #41");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #42");
    trace_rec_3();
  }

  strcpy(a_string, "         JCT   R5,");
  strcat(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "F");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #43");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "T");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #44");
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
    strcpy(trace_1, "c2z_math.c math_830 #45");
    trace_rec_3();
  }

  p = strstr(field5, "\0");
 
  if(p)
  {
    strcpy(a_string, "         LARL  R7,C370EOF");
    src_line();

    strcpy(a_string, "         MVC   ");
    strcat(a_string, "0(");
    strcat(a_string, "1,R6),0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_830 #46b");
      trace_rec_3();
    }
  }
 
  if(!p)
  {
    strcpy(a_string, "         LARL  R7,");
    strcat(a_string, field5);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_830 #46c");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, "0(");
    strcat(a_string, "1,R6),0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_830 #46d");
      trace_rec_3();
    }
  }
    

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_830 #48");
    trace_rec_3();
  }


  convert = 1;
  return;
}


void c2_math_820()
{

printf("\nc2_math_820 rct = %d p_string = %s",rct,p_string);

   int pi;
   int pi2;
   int x2 = 0;
   int x21;
   int x3;
   int I;
   int ret;
   int x102;
   int x101;

   int fd1_type;
   int fd2_type;
   int fd3_type;
   int fd5_type;
   int fd6_type;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field6a[VAR_LGTH];

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
  while((ch == ' ') || (ch == '\t'))
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  fd1_type = 0;
  pi2 = 0;
  while(ch != '[')
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
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while(ch  == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while(ch  == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  fd5_type = 0;
  ch = p_string[pi];
  while(ch != '[')
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
printf("c2z_math.c math_820 rct = %d fd5_type = %d field5 = %s\n",rct,fd5_type,field5);

  pi2 = 0;
  x2 = 0;
  fd6_type = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    if (x2 == 0) 
    {
      if(ch == '\'')
      {
        fd6_type = 0;
        x2 = 1;
      }
      if (isdigit(ch)) 
      {
        fd6_type = 1;
        x2 = 1;
      }
      if (isalpha(ch)) 
      {
        fd6_type = 2;
        x2 = 1;
      }
    }
    field6[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field6[pi2] = '\0';

  x21 = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    x21 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x21 == 0)) 
    {
      x3 = 1;
      strcpy(field1a, lw_variable[I].lv_cname);
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
printf("c2z_math.c math_820 rct = %d fd1_type = %d field1 = %s field1a = %s fd1_type = %d\n",rct,fd1_type,field1,field1a,fd1_type);

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
      printf("\nc2z_printf.c c2_printf_600 E-604 field2 Not Found = %s\n",field2);
      printf("c2z_printf.c c2_printf_600 rct = %d p_string = %s\n",rct,p_string);
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
      printf("\nc2z_printf.c c2_printf_600 E-604 field3 Not Found = %s\n",field3);
      printf("c2z_printf.c c2_printf_600 rct = %d p_string = %s\n",rct,p_string);
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_printf.c c2_printf_600 E-604 field5 Not Found = %s\n",field5);
      printf("c2z_printf.c c2_printf_600 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd6_type == 2)
  {
    x21 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field6, lw_variable[I].lv_name);
      x21 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x21 == 0)) 
      {
        x3 = 1;
        strcpy(field6a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      x3 = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field6, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field6a, gw_variable[I].gv_cname);
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_printf.c c2_printf_600 E-604 field6 Not Found = %s\n",field6);
      printf("c2z_printf.c c2_printf_600 rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
printf("c2z_math.c math_820 rct = %d fd6_type = %d field6 = %s field6a = %s\n",rct,fd6_type,field6,field6a);

  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK5");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #3");
    trace_rec_3();
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R9,C370NWK4");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_820 #1");
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
      strcpy(trace_1, "c2z_math.c math_820 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_820 #3");
      trace_rec_3();
    }
  }

  if(fd3_type == 2)
  {
    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_820 #1");
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
      strcpy(trace_1, "c2z_math.c math_820 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_820 #3");
      trace_rec_3();
    }
  }

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field2);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, "  ROW */");
    write_remark();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_820 #4a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_820 #4b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_820 #4c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK4");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_820 #4d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_820 #4e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_820 #4f");
      trace_rec_3();
    }
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R9,C370NWK4");
    strcpy(wk_remark, " ROW */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_820 #4g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #5");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #6");
    trace_rec_3();
  }

  strcpy(a_string, "         JLNE  L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "V");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #7");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #9");
    trace_rec_3();
  }
 
  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #10");
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
      strcpy(trace_1, "c2z_math.c math_820 #11a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1)
    { 
      strcpy(trace_1, "c2z_math.c math_820 #11b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_820 #11c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK5");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_820 #11d");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_820 #11e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_820 #11f");
      trace_rec_3();
    }
  }

  if(fd3_type == 2)
  {
    strcpy(a_string, "         LARL  R7,C370NWK5");
    strcpy(wk_remark, " COL */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_820 #11g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R5,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #12");
    trace_rec_3();
  }
 
  strcpy(a_string, "         AP    0(6,R7),0(6,R5)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  strcpy(wk_remark, " ");
  strcat(wk_remark, " Point to element */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #14");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R7)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #15");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "W");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #16");
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
    strcpy(trace_1, "c2z_math.c math_820 #17");
    trace_rec_3();
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R9,C370NWK4");
    strcpy(wk_remark, " ROW */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_820 #18");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    strcpy(wk_remark, " Add 1 to row */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_820 #19");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_820 #20");
      trace_rec_3();
    }
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", x102);
  strcpy(a_string, "         LAEY  R5,");
  strcat(a_string, wk_strg);
  strcpy(wk_remark, " ");
  strcat(wk_remark, wk_strg);
  strcat(wk_remark, " # of COL */");
  write_remark();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c math_820 #21");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c math_820 #22");
    trace_rec_3();
  }

  strcpy(a_string, "         CVD   R5,0(R7)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c math_820 #23");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c math_820 #24");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R7,C370U");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c math_820 #25");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c math_820 #26");
    trace_rec_3();
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_820 #27");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK4");
    strcpy(wk_remark, " ROW */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_820 #28");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c math_820 #29");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c math_820 #30");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK3");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c math_820 #31");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c math_820 #32");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c math_820 #33");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK5");
  strcpy(wk_remark, " COL */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #34");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c math_820 #35");
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
    strcpy(trace_1, "c2z_math.c math_820 #36");
    trace_rec_3();
  }

/*  C370NWK1 contains pointer to array element */

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #37");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #38");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #39");
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
    strcpy(trace_1, "c2z_math.c math_820 #40");
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
    strcpy(trace_1, "c2z_math.c math_820 #41");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #42");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #43");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #44");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #45");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #46");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #47");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #48");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #49");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #50");
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
    strcpy(trace_1, "c2z_math.c math_820 #51");
    trace_rec_3();
  }

/*  R6 points to matrix element */

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #46");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #47");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #48");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK4");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #46");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #52");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field6a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field6);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #53");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #54");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #55");
    trace_rec_3();
  }

  strcpy(a_string, "         CVB   R5,0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #56");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field5a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field5);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #57");
    trace_rec_3();
  }

  strcpy(a_string, "         IC    R0,0(R8,(R5))");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #58");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370L1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #59");
    trace_rec_3();
  }

  strcpy(a_string, "         STC   R0,0(0,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #60");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R6),0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_820 #61");
    trace_rec_3();
  }

  convert = 1;
  return;
}




void c2_math_920(void)
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_920");
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

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];

   int pi;
   int pi2;
   int x2;
   int fd3_type = 0;
   int fd4_type = 0;
   int I;
   int x3;
   int x21;
   int x100;
   int x102;
   int ret;

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

   ch = p_string[pi];
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
   
   pi++;
   pi2 = 0;
   fd3_type = 0;
   x2 = 0;
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

   pi++;
   pi++;
   pi2 = 0;
   fd4_type = 0;
   x2 = 0;
   ch = p_string[pi];
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

   x3 = 0;
   for (I = 0; I < lv_ct; I++) 
   {
     ret = strcmp(field1, lw_variable[I].lv_name);
     x21 = strcmp(sv_func, lw_variable[I].lv_func);
     if ((ret == 0) && (x21 == 0)) 
     {
       x3 = 1;
       strcpy(field1a, lw_variable[I].lv_cname);
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
     printf("\nc2z_math.c math_920 E-604 field1 Not Found = %s\n",field1);
     printf("c2z_math.c math_920 rct = %d p_string = %s\n",rct,p_string);
     erct++;
     convert = 1;
     return;
   }

   x3 = 0;
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

   if(fd3_type == 2)
   {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        x21 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (x21 == 0)) 
        {
           x3 = 1;
           strcpy(field3a, lw_variable[I].lv_cname);
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
               break;
            }
         }
      }

      if (x3 == 0) 
      {
         printf("\nc2z_math.c math_920 E-604 field3 Not Found = %s\n",field3);
         printf("c2z_math.c math_920 rct = %d p_string = %s\n",rct,p_string);
         erct++;
         convert = 1;
         return;
      }
   }

   if(fd4_type == 2)
   {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field4, lw_variable[I].lv_name);
        x21 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (x21 == 0)) 
        {
           x3 = 1;
           strcpy(field4a, lw_variable[I].lv_cname);
           break;
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
         printf("\nc2z_math.c math_920 E-604 field4 Not Found = %s\n",field4);
         printf("c2z_math.c math_920 rct = %d p_string = %s\n",rct,p_string);
         erct++;
         convert = 1;
         return;
      }
   }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92001");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92002");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92003");
      trace_rec_3();
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
        strcpy(trace_1, "c2z_math.c #92004");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92005");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92006");
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
      strcpy(trace_1, "c2z_math.c #92007");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92008");
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
        strcpy(trace_1, "c2z_math.c #92009");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #92010");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #92011");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #92012");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #92013");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #92014");
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
        strcpy(trace_1, "c2z_math.c #92015");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92016");
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
      strcpy(trace_1, "c2z_math.c #92017");
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
      strcpy(trace_1, "c2z_math.c #92018");
      trace_rec_3();
    }


    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #92019");
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
        strcpy(trace_1, "c2z_math.c #92020");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #92021");
        trace_rec_3();
      }
    }

   
    snprintf(wk_strg, sizeof(wk_strg), "%d", x102);
     strcpy(a_string, "         LAEY  R5,");
     strcat(a_string, wk_strg);
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_math.c #92022");
       trace_rec_3();
     }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92023");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92024");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92025");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92026");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92027");
      trace_rec_3();
    }

   
/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92028");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92029");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92030");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92031");
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
        strcpy(trace_1, "c2z_math.c #92032");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #92033");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #92034");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #92035");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #92036");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #92037");
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
        strcpy(trace_1, "c2z_math.c #92038");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92039");
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
      strcpy(trace_1, "c2z_math.c #92040");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92041");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92042");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92043");
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
      strcpy(trace_1, "c2z_math.c #92044");
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
      strcpy(trace_1, "c2z_math.c #92045");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92046");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92047");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92048");
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
      strcpy(trace_1, "c2z_math.c #92049");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92050");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92051");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92052");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #92053");
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
    strcpy(trace_1, "c2z_math.c #92054");
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
    strcpy(trace_1, "c2z_math.c #92055");
    trace_rec_3();
  }

  if(fd4_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field4);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92056");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92057");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92058");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92059");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92060");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92061");
      trace_rec_3();
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
      strcpy(trace_1, "c2z_math.c #92062");
      trace_rec_3();
    }
 

  if(fd4_type != 0)
  {
    strcpy(a_string, "         ZAP   ");
    strcat(a_string, "0(6,R9),");
    strcat(a_string, "0(6,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92063");
      trace_rec_3();
    }
  }

  if(fd4_type == 0)
  {
    for(I = 0; I < char_ct; I++)
    {
      if(rct == w_charlit[I].clit_rct)
      {
        x100 = w_charlit[I].clit_lgth;
        break;
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, w_charlit[I].clit_cname);
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #92064");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x100);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    strcat(a_string, "0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92065");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92066");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x100);
    strcpy(a_string, "         MVC   ");
    strcat(a_string, wk_strg);
    strcat(a_string,"(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    strcat(a_string, "0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #92067");
      trace_rec_3();
    }
  }

/*
printf("\nc2z_math.c math_920 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c math_920 field1 = %s field1a = %s\n",field1,field1a);
printf("c2z_math.c math_920 field2 = %s field2a = %s\n",field2,field2a);
printf("c2z_math.c math_920 field3 = %s field3a = %s fd3_type = %d\n",field3,field3a,fd3_type);
printf("c2z_math.c math_920 field4 = %s field4a = %s fd4_type = %d\n",field4,field4a,fd4_type);
*/

  convert = 1;
}




/* ************************************
*   x = 7;                            *
************************************* */
void c2_math_500() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_500 START");
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
    printf("\nc2z_math.c c2_math_500 math-005 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_math.c c2_math_500 rct = %d p_string = %s", rct, p_string);
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

  if ((x4 == 2) && (x5 == 0) && (fd2_type == 0)) 
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
      strcpy(trace_1, "c2z_math.c #1");
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
      strcpy(trace_1, "c2z_math.c #2");
      trace_rec_3();
    }

    if (fd2_type == 0) 
    {
      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #3");
        trace_rec_3();
      }
    }

    if (fd1_id == 2) 
    {
      printf("\nc2z_math.c c2_math_500 math-006 rct = %d fd1_id = 2 NOT CODED\n", rct);
      printf("c2z_math.c c2_math_500 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_500 math-007 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_math.c c2_math_500 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #4");
      trace_rec_3();
    }
    
    if (fd2_type == 2) 
    {
      strcpy(a_string, "        LAEY  R5,");
      strcat(a_string, tfield2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #5");
        trace_rec_3();
      }

      strcpy(a_string, "        LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #6");
        trace_rec_3();
      }
      work_use_ct[48]++;
  
      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #7");
        trace_rec_3();
      }

      strcpy(a_string, "          LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #8");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #9");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "        ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #10");
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
      strcpy(trace_1, "c2z_math.c #11");
      trace_rec_3();
    }
 
    if ((fd1_type == 1) && (fd2_type == 1) && (fd1_status == 1)) 
    {
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #12");
        trace_rec_3();
      }
    }

    if(fd1_status == 2)
    {
      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #13");
        trace_rec_3();
      }
    }

    if ((fd1_id == 2) && (fd2_id == 2)) 
    {
      strcpy(a_string, "         LD    R2,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #14");
        trace_rec_3();
      }

      strcpy(a_string, "         STD   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #15");
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
      strcpy(trace_1, "c2z_math.c #16");
      trace_rec_3();
    }

    x80 = 0;

    p = strstr(tfield2, "-1");
    if(p)
    {
       strcpy(a_string, "         LARL  R8,NULL");	/* NULL = -1 */
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_math.c #16a");
         trace_rec_3();
       }

       strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_math.c #16b");
         trace_rec_3();
       }
       return;
    }

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
          strcpy(trace_1, "c2z_math.c #17");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #18");
          trace_rec_3();
        }
        work_use_ct[48]++;
  
        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #19");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #20");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #21");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #22");
          trace_rec_3();
        }
      
    }

    if ((fd1_type == 1)  && (fd2_type == 2))
    {
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #23");
        trace_rec_3();
      }
    }

    if ((fd1_type == 2) && (fd2_type == 2)) 
    {
      strcpy(a_string, "         LD    R2,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #24");
        trace_rec_3();
      }

      strcpy(a_string, "         STD   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #25");
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
      strcpy(trace_1, "c2z_math.c #26");
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
      strcpy(trace_1, "c2z_math.c #27");
      trace_rec_3();
    }
   
    strcpy(a_string, "         MVC   0(R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #28");
      trace_rec_3();
    }
    convert = 1;
    return;
  }
}


void c2_math_501()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_501 Structure");
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
  char tfield6a[VAR_LGTH];
  char tfield7a[VAR_LGTH];

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x80 = 0;
  int x87 = 0;
  int m5fd2_type = 0;
  int m5fd5_type = 0;
  int I = 0;
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

printf("\nc2z_math.c math_501 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c math_501 tfield1 = %s\n",tfield1);
printf("c2z_math.c math_501 tfield2 = %s\n",tfield2);
printf("c2z_math.c math_501 tfield3 = %s\n",tfield3);
printf("c2z_math.c math_501 tfield5 = %s m5fd5_type = %d\n",tfield5,m5fd5_type);

  x3 = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    ret = strcmp(tfield1, w_struc[I].st_wname);
    ret1 = strcmp(tfield3,w_struc[I].st_field_name);
    if ((ret == 0) && (ret1 == 0))
    {
      x3 = 1;
      strcpy(tfield1a, w_struc[I].st_cwname);
      strcpy(tfield6a, w_struc[I].st_field_cname);
      strcpy(tfield7a, w_struc[I].st_type);
      break;
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_math.c c2z_math_501 Structure math-029 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_math.c c2_math_501 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_501 math-030 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_math.c c2_math_501 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
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
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_math.c c2z_math_501 Structure math-031 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_math.c c2z_math_501 Structure tfield3 Not Found = %s\n",tfield3);
    printf("c2z_math.c c2_math_501 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_501 math-032 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_math.c c2_math_501 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #50");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #51");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #52");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield5);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #53");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #54");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #55");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #56");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #57");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #58");
      trace_rec_3();
    }
    strcpy(tfield5a,"C370NWK3");
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
      printf("\nc2z_math.c c2_math_501 math-033 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_math.c c2_math_501 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #59");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #60");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #61");
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
    strcpy(trace_1, "c2z_math.c #62");
    trace_rec_3();
  }

  if(m5fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #63");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #64");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #65");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #66");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #67");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #68");
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
    strcpy(trace_1, "c2z_math.c #69");
    trace_rec_3();
  }


  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #70");
    trace_rec_3();
  }
  work_use_ct[49]++;

  if(m5fd2_type == 1)
  {
    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #71");
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
      strcpy(trace_1, "c2z_math.c #72");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #73");
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
    strcpy(trace_1, "c2z_math.c #74");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #75");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #76");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #77");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, tfield1a);
  strcat(a_string, "L");
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #78");
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
    strcpy(trace_1, "c2z_math.c #79");
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
    strcpy(trace_1, "c2z_math.c #80");
    trace_rec_3();
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
      x80 = w_struc[I].st_disp;
    }
  }

  if (x3 == 0) 
  {
    printf("/nc2z_math.c c2z_math_501 Structure math-034 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_math.c c2z_math_501 Structure tfield3 Not Found = %s\n",tfield3);
    printf("c2z_math.c c2_math_501 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #81");
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
    strcat(wk_remark, " ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #82");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         ZAP   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
  strcat(a_string, wk_strg);
  strcat(a_string, "(6,R6),0(6,R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #83");
    trace_rec_3();
  }
}


			
void c2_math_502()		/* spreadsheet[x][z] = y */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_502");
    trace_rec_1();
  }

   int pi;
   int pi2;
   int fd2_type;
   int fd3_type;
   int fd5_type;
   int x2;
   int x3;
   int ret;
   int x21;
   int x100;
   int x101;
   int x102;
   int I;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
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

  pi = 0;
  ch = p_string[pi];
  while((ch == ' ') || (ch == '\t'))
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
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

  ch = p_string[pi];
  while(ch != ' ')
  {
    pi++;
    ch = p_string[pi];
  }

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

/*
printf("\nc2z_math.c #1800 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c #1800 field1 = %s\n",field1);
printf("c2z_math.c #1800 field2 = %s fd2_type = %d\n",field2,fd2_type);
printf("c2z_math.c #1800 field3 = %s fd3_type = %d\n",field3,fd3_type);
printf("c2z_math.c #1800 field5 = %s fd5_type = %d\n",field5,fd5_type);
*/

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
      printf("\nc2z_math.c c2_math_502 E-604 field2 Not Found = %s\n",field2);
      printf("c2z_math.c c2_math_502 rct = %d p_string = %s\n",rct,p_string);
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
      printf("\nc2z_math.c c2_math_502 E-604 field3 Not Found = %s\n",field3);
      printf("c2z_math.c c2_math_502 rct = %d p_string = %s\n",rct,p_string);
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
      printf("\nc2z_math.c c2_math_502 E-604 field5 Not Found = %s\n",field5);
      printf("c2z_math.c c2_math_502 rct = %d p_string = %s\n",rct,p_string);
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
      strcpy(trace_1, "c2z_math.c #100");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #101");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #102");
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
        strcpy(trace_1, "c2z_math.c #103");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #104");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #105");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #106");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #107");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #108");
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
        strcpy(trace_1, "c2z_math.c #109");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #110");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #111");
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
      strcpy(trace_1, "c2z_math.c #112");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #113");
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
        strcpy(trace_1, "c2z_math.c #114");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #115");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #116");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #117");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #118");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #119");
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
        strcpy(trace_1, "c2z_math.c #120");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #121");
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
      strcpy(trace_1, "c2z_math.c #122");
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
      strcpy(trace_1, "c2z_math.c #123");
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
        strcpy(trace_1, "c2z_math.c #124");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #125");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #126");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #127");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #128");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #129");
        trace_rec_3();
      }
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #130");
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
        strcpy(trace_1, "c2z_math.c #130a");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #131");
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
          x102 = gw_variable[I].gv_column;
          break;
        }
      }
    }

    
    snprintf(wk_strg, sizeof(wk_strg), "%d", x102);
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #132");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #133");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #134");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #135");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #136");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #137");
      trace_rec_3();
    }
  

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #138");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #139");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #140");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #141");
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
        strcpy(trace_1, "c2z_math.c #142");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #143");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #144");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #145");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #146");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #147");
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
        strcpy(trace_1, "c2z_math.c #148");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #149");
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
      strcpy(trace_1, "c2z_math.c #150");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #151");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #152");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #153");
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
      strcpy(trace_1, "c2z_math.c #154");
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
      strcpy(trace_1, "c2z_math.c #155");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #156");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #157");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #158");
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
      strcpy(trace_1, "c2z_math.c #159");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #160");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #161");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #162");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #163");
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
    strcpy(trace_1, "c2z_math.c #164");
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
    strcpy(trace_1, "c2z_math.c #165");
    trace_rec_3();
  }

  if(fd5_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field5);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #165");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #167");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #168");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NCVT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #169");
      trace_rec_3();
    }
    work_use_ct[104]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #170");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #171");
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
      strcpy(trace_1, "c2z_math.c #172");
      trace_rec_3();
    }
  }

  if(fd5_type != 0)
  {
    strcpy(a_string, "         ZAP   ");
    strcat(a_string, "0(6,R6),");
    strcat(a_string, "0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #173");
      trace_rec_3();
    }
  }
 
  if(fd5_type == 0)
  {
    for(I = 0; I < char_ct; I++)
    {
      if(rct == w_charlit[I].clit_rct)
      {
        x100 = w_charlit[I].clit_lgth;
        break;
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, w_charlit[I].clit_cname);
    src_line();
    if (puncde == 1) 
    { 
      strcpy(trace_1, "c2z_math.c #176");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x100);
    strcpy(a_string, "         MVC   0(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    strcat(a_string, "0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #177");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #178");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", x100);
    strcpy(a_string, "         MVC   ");
    strcat(a_string, wk_strg);
    strcat(a_string,"(");
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    strcat(a_string, "0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #179");
      trace_rec_3();
    }
  }
}



void c2_math_503()			/*  array iv_stack[2] = 444;   */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_503");
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
  int x4 = 0;
  int x10 = 0;
  int x80 = 0;
  int m5_3 = 0;
  int m5_6 = 0;
  int m5fd2_type = 0;
  int m5fd3_type = 0;
  int I = 0;
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
      }
    }
  }

  if (m5_3 == 0) 
  {
    printf("\nc2z_math.c c2_math_503 math-024 field1 Not Found = %s\n", field1);
    printf("c2z_math.c c2_math_503 rct = %d p_string = %s", rct, p_string);
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
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("\nc2z_math.c c2_math_503 math-025 field2 Not Found = %s\n", field2);
      printf("c2z_math.c c2_math_503 rct = %d p_string = %s", rct, p_string);
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
      m5fd3_type = 0;
      x2 = 1;
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
      printf("\nc2z_math.c c2_math_503 math-026 field3 Not Found = %s\n", field3);
      printf("c2z_math.c c2_math_503 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

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

  if(m5fd2_type == 2)
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
      printf("\nc2z_math.c c2_math_503 math-028 field2 Not Found = %s\n", field2);
      printf("c2z_math.c c2_math_503 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

/*
printf("\nc2z_math.c math_503 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c math_503 field1 = %s\n",field1);
printf("c2z_math.c math_503 field2 = %s m5fd2_type = %d\n",field2,m5fd2_type);
printf("c2z_math.c math_503 field3 = %s m5fd3_type = %d\n",field3,m5fd3_type);
*/

  if(x80 == 0)
  {
    x4 = 0;
    if(m5fd3_type == 1)
    {
      p = strstr(field3, "-1");
      if(p)
      {
        x4 = 1;
      }
    }

    if((m5fd3_type == 0) && (x4 == 0))
    {
      p = strstr(field3, "0'");
      if(p)
      {
         strcpy(a_string, "         LARL  R7,C370EOF");
         src_line();
         if (puncde == 1) 
         {
           strcpy(trace_1, "c2z_math_c #200");
           trace_rec_3();
         }
      }
    }

    if((m5fd3_type == 1) && (x4 == 0))
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #200a");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #201");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #202");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #203");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #204");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #205");
        trace_rec_3();
      }
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_c #206");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #207");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #208");
    trace_rec_3();
  }

  if(m5fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #209");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #210");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #211");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #212");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #213");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #214");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, field7);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #215");
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
    strcpy(trace_1, "c2z_math.c #216");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_c #217");
    trace_rec_3();
  }
  work_use_ct[49]++;

  if(m5fd2_type == 1)
  {
    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #218");
      trace_rec_3();
    }
    work_use_ct[78]++;
  }

  if(m5fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #219");
      trace_rec_3();
   }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #220");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #221");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_c #222");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #223");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #224");
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
    strcpy(trace_1, "c2z_math.c #225");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #226");
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
    strcpy(trace_1, "c2z_math.c #227");
    trace_rec_3();
  }

  if(m5fd3_type == 0)
  {
    strcpy(a_string, "         MVC   0(1,R6),0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #227a");
      trace_rec_3();
    }
  }

  if((m5fd3_type == 1) && (x4 == 0))
  {
    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #228");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #229");
      trace_rec_3();
    }
  }

  if((m5fd3_type == 1) && (x4 == 1))
  {
    strcpy(a_string, "         LARL  R9,NULL");   /* NULL = -1 */
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #230");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #231");
      trace_rec_3();
    }
  }

  if(m5fd3_type == 2)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #232");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #233");
      trace_rec_3();
    }
  }
}



/* ************************************
*   ch = p_string[pi]                 *
************************************* */
void c2_math_504() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c math_504 START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];

  char tfield5[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield8[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield11[VAR_LGTH];

  int pi;
  int pi2;
  int fd1_type = 0;
  int fd2_type = 0;
  int fd3_type = 0;
  int x2 = 0;
  int x3 = 0;
  int x5 = 0;
  int ret = 0;
  int ret1 = 0;
  int I = 0;
  int s = 0;
  int math_char = 0;
  int skip;
 
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
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_math.c c2_math_504 math-008 field1 Not Found = %s\n", field1);
    printf("c2z_math.c c2_math_504 rct = %d p_string = %s", rct, p_string);
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

  math_char = 0;
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

  if (x3 == 0) 
  {
    fd2_type = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field2a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;

        ret1 = strcmp("C", gw_variable[I].gv_type);
        if (ret1 == 0) 
        {
          math_char = 1;
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
          math_char = 2;
          fd2_type = 3;
          break;
        }
        ret1 = strcmp("A", gw_variable[I].gv_type);
        if (ret1 == 0) 
        {
          math_char = 4;
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

  if(math_char == 0)
  {
    math_char = 1;
  }

  if(fd2_type == 3)
  {
    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
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

/*
printf("\nc2z_math.c math_504 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c math_504 field1 = %s field1a = %s fd1_type = %d\n",field1,field1a,fd1_type);
printf("c2z_math.c math_504 field2 = %s fd2_type = %d math_char = %d\n",field2,fd2_type,math_char);
printf("c2z_math.c math_504 field3 = %s fd3_type = %d\n",field3,fd3_type);
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
      printf("\nc2z_math.c c2_math_504 math-013 field3 Not Found = %s\n", field3);
      printf("c2z_math.c c2_math_504 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #300");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #301");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #302");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #303");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #304");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #305");
      trace_rec_3();
    }
    strcpy(field3a,"C370NWK1");
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
      strcpy(trace_1, "c2z_math.c #306");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #307");
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
      strcpy(trace_1, "c2z_math.c #308");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #309");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #310");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R5,0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #311");
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
      strcpy(trace_1, "c2z_math.c #312");
      trace_rec_3();
    }

    strcpy(a_string, "         IC    R0,");
    strcat(a_string, "0(R8,");
    strcat(a_string, "(R5))");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #313");
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
      strcpy(trace_1, "c2z_math.c #314");
      trace_rec_3();
    }

    strcpy(a_string, "         STC   R0,");
    strcat(a_string, "0(0,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #315");
      trace_rec_3();
    }
  }
  
  if (math_char == 4) 			/* extract character from a array field  */
  {
    printf("\nc2z_math.c c2_math_504 math-015 math_char == 4 ERROR\n");
    printf("c2z_math.c c2_math_504 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (math_char == 2) 
  {
    if(fd3_type == 2)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #316");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #317");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #318");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #319");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #320");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #321");
        trace_rec_3();
      }
      strcpy(field3a, "C370NWK2");
    }
 
    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #322");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #323");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #324");
      trace_rec_3();
    }

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field2);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #325");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #326");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #327");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK3");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #328");
        trace_rec_3();
      }
      work_use_ct[50]++;

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #329");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #330");
        trace_rec_3();
      }
      strcpy(field3a, "C370NWK2");
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, tfield7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #331");
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
      strcpy(trace_1, "c2z_math.c #332");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #333");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R8,C370NWK3");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #334");
        trace_rec_3();
      }
      work_use_ct[78]++;
    }

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #335");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #336");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #337");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #338");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #339");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #340");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, tfield6);
    strcat(a_string, "(R0,R6)");
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #341");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #342");
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
      strcpy(trace_1, "c2z_math.c #343");
      trace_rec_3();
    }

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R9,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #344");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #345");
        trace_rec_3();
      }
    }

    if(fd1_type == 2)
    {
      printf("c2z.math.c math_504 fd1_type == 1 NOT CODED\n");
      printf("c2z.math.c math_504 rct = %d p_string = %s\n",rct,p_string);
    }

    if(fd1_type == 1)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #346");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #347");
        trace_rec_3();
      }
    }
  }
}



void c2_math_505()		/* procedure call	pi = get_upper(pi,stlen);	*/
{
  char ch;
  char *p;
  char *p1;
  char *p2;
  char *p6;
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
  int fd7_type = 0;
  int fd8_type = 0;
  int fd9_type = 0;
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


  p = strstr(p_string, "()");		/* ch = iswhite();   */
  if(p)
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_505 Proc #1");
      trace_rec_1();
    }

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
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

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
    while(ch != ' ')
    {
      if(ch == '(')
      {
        break;
      }

      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

/*
printf("\nc2z_math.c math_505 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c math_505 tfield1 = %s\n",tfield1);
printf("c2z_math.c math_505 tfield2 = %s\n",tfield2);
*/

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
          strcpy(tfield4, w_function[I].fn_fd1); 
          strcpy(wk_sv_func, tfield2); 
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_505 E-900 tfield2 (function) Not Found = %s\n",tfield2);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #400");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #401");
      trace_rec_3();
    }

    fd1_type = 0;
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
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if (ret2 == 0) 
        {
          fd1_type = 1;	/* numeric */
        } 
        ret2 = strcmp("C", lw_variable[I].lv_type);
        if (ret2 == 0) 
        {
          fd1_type = 2;	/* char    */
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
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if (ret2 == 0) 
          {
            fd1_type = 1;	/* numeric */  
          } 
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if (ret2 == 0) 
          {
            fd1_type = 2;	/* char    */
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_505 E-901 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    fd3_type = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield3, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield3a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if (ret2 == 0) 
        {
          fd3_type = 1;	/* numeric */
        } 
        ret2 = strcmp("C", lw_variable[I].lv_type);
        if (ret2 == 0) 
        {
          fd3_type = 2;	/* char    */
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
          gw_variable[I].gv_use_ct++;
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if (ret2 == 0) 
          {
            fd3_type = 1;	/* numeric */  
          } 
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if (ret2 == 0) 
          {
            fd3_type = 2;	/* char    */
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_505 E-902 tfield3 Not Found = %s\n", tfield3);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #402");
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
      strcpy(trace_1, "c2z_math.c #403");
      trace_rec_3();
    }

    if((fd1_type == 1) && (fd3_type == 1))
    {
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #404");
        trace_rec_3();
      }
    }

    if((fd1_type == 2) && (fd3_type == 2))
    {
      strcpy(a_string, "         MVC2  ");
      strcat(a_string, tfield1a);
      strcat(a_string, ",");
      strcat(a_string, tfield3a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #405");
        trace_rec_3();
      }
    }

    if((fd1_type == 1) && (fd3_type == 2))
    {
      printf("c2z_math.c c2_math_505 Return Variable Mis_Match E-986\n");
      printf("rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if((fd1_type == 2) && (fd3_type == 1))
    {
      printf("c2z_math.c c2_math_505 Return Variable Mis_Match E-987\n");
      printf("rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }
    convert = 1;
    return;
  }

	/*  Match('=');             */
  if ((x10 == 0) && (x11 == 0) && (x13 < x12) && (x14 > x12) && (x15 == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_505 Proc #2");
      trace_rec_1();
    }

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
      printf("\nc2z_math.c c2_math_505 math-040 tfield1 (function) Not Found = %s\n",tfield1);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-041 #80 tfield4 Not Found = %s\n", tfield4);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c math_6 #406");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_6 #407");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1");
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_6 #408");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_6 #409");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c math_6 #410");
      trace_rec_3();
    }
    return;
  }


	/* nnx = get_intndx(varname);   */
  if ((x10 == 0) && (x11 == 0) && (x12 < x13) && (x15 == 0) && (convert == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_505 Proc #3");
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
        printf("\nc2z_math.c c2_math_505 math-042 eol = 1 tfield1 Not Found = %s\n", tfield1);
        printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
        printf("\nc2z_math.c c2_math_505 math-043 eol = 1 tfield3 Not Found = %s\n", tfield3);
        printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
        strcpy(trace_1, "c2z_math.c #411");
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
        strcpy(trace_1, "c2z_math.c #412");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #413");
        trace_rec_3();
      }
     return;
    }

    s = strlen(tfield3);
    x88 = 0;

    if (s == 0) 			/* idx = (len-1); tfield3 = (len-1) */
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_505 Proc #4");
        trace_rec_1();
      }

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
          printf("\nc2z_math.c c2_math_505 math-044 #66 tfield1 Not Found = %s\n", tfield1);
          printf("c2z_math.c c2_math_505 #66 rct = %d p_string = %s", rct, p_string);
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
          printf("\nc2z_math.c c2_math_505 math-045 #67 tfield9 Not Found = %s\n", tfield9);
          printf("c2z_math.c c2_math_505 #67 rct = %d p_string = %s", rct, p_string);
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
          strcpy(trace_1, "c2z_math.c #414");
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
          strcpy(trace_1, "c2z_math.c #415");
          trace_rec_3();
        }

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #416");
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
          strcpy(trace_1, "c2z_math.c #417");
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
          strcpy(trace_1, "c2z_math.c #418");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #419");
          trace_rec_3();
        }
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
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_505 Proc #5");
        trace_rec_1();
      }

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
      printf("\nc2z_math.c c2_math_505 math-046 #1 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_505 #1 rct = %d p_string = %s", rct, p_string);
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
        printf("\nc2z_math.c c2_math_505 math-047 tfield3 (function) Not Found = %s\n",tfield3);
        printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
          printf("\nc2z_math.c c2_math_505 math-048 tfield5 Not Found = %s\n", tfield5);
          printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
        printf("\nc2z_math.c c2_math_505 math-049 tfield3 (function) Not Found = %s\n",tfield3);
        printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
        printf("\nc2z_math.c c2_math_505 math-050 tfield5 Not Found = %s\n", tfield5);
        printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
        printf("\nc2z_math.c c2_math_505 math-051 #45 rct = %d tfield4 Not Found = %s\n",rct, tfield4);
        printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct,p_string);
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
        printf("\nc2z_math.c c2_math_505 math-052 #45 rct = %d tfield4 Not Found = %s\n",rct, tfield4);
        printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct,p_string);
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
        strcpy(trace_1, "c2z_math.c #420");
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
        strcpy(trace_1, "c2z_math.c #421");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #422");
        trace_rec_3();
      }
      return;
    }

    fd4_type = 0;
    if (x98 != 1) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_math.c c2_math_505 Proc #6");
        trace_rec_1();
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
        fd4_type = 0;
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
          strcpy(trace_1, "c2z_math.c #423");
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
          strcpy(trace_1, "c2z_math.c #424");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #425");
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
          strcpy(trace_1, "c2z_math.c #426");
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
          strcpy(trace_1, "c2z_math.c #427");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC2  ");
        strcat(a_string, tfield6a);
        strcat(a_string, ",");
        strcat(a_string, tfield4a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #428");
          trace_rec_3();
        }
      }
    }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #429");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #430");
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
      strcpy(trace_1, "c2z_math.c #431");
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
      strcpy(trace_1, "c2z_math.c #432");
      trace_rec_3();
    }

    if(fd1_type == 1)
    {
      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #433");
        trace_rec_3();
      }
    }

    if(fd1_type == 2)
    {
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #434");
        trace_rec_3();
      }
    }

    convert = 1;
    return;
  }

  if ((x10 == 0) && (x11 == 0) && (x12 < x13) && (x14 > 0) && (x85 == 1) && (convert == 0)) 	/* pi = get_upper(pi, len); */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_505 Proc #7");
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
      printf("\nc2z_math.c c2_math_505 math-053 tfield3 (function) Not Found = %s\n",tfield3);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-054 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-055 tfield7 Not Found = %s\n", tfield7);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #435");
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
      strcpy(trace_1, "c2z_math.c #436");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #437");
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
      printf("\nc2z_math.c c2_math_505 math-056 tfield5 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-057 tfield8 Not Found = %s\n", tfield8);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #438");
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
      strcpy(trace_1, "c2z_math.c #439");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #440");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield3a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #441");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #442");
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
      printf("\nc2z_math.c c2_math_505 math-058 #100 tfield6 Not Found = %s\n", tfield6);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #443");
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
      strcpy(trace_1, "c2z_math.c #444");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #445");
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
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

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

    pi2 = 0;
    while(ch != '(')
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
    while(ch != ',')
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
    while(ch != ',')
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
    pi++;
    ch = p_string[pi];
    while(ch != ')')
    {
      if(ch != ' ')
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
        ret = strcmp(tfield2, w_function[I].fn_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, w_function[I].fn_cname);
          strcpy(tfield9, w_function[I].fn_ret_var);
          strcpy(tfield6, w_function[I].fn_fd1);
          strcpy(tfield7, w_function[I].fn_fd2);
          strcpy(tfield8, w_function[I].fn_fd3);
          strcpy(wk_sv_func, tfield2);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_505 E-151 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    fd3_type = 0;
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
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if(ret2 == 0)
        {
          fd3_type = 1;
        }
        ret2 = strcmp("C", lw_variable[I].lv_type);
        if(ret2 == 0)
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
          gw_variable[I].gv_use_ct++;
          ret2 = strcmp("I", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd3_type = 1;
          }
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd3_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_505 E-152 tfield3 Not Found = %s\n", tfield3);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    fd4_type = 0;
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
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if(ret2 == 0)
        {
          fd4_type = 1;
        }
        ret2 = strcmp("C", lw_variable[I].lv_type);
        if(ret2 == 0)
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
          ret2 = strcmp("I", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd4_type = 1;
          }
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd4_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_505 E-153 tfield4 Not Found = %s\n", tfield4);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    fd5_type = 0;
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
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if(ret2 == 0)
        {
          fd5_type = 1;
        }
        ret2 = strcmp("C", lw_variable[I].lv_type);
        if(ret2 == 0)
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
          gw_variable[I].gv_use_ct++;
          ret2 = strcmp("I", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd5_type = 1;
          }
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd5_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_505 E-154 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    fd6_type = 0;
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
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if(ret2 == 0)
        {
          fd6_type = 1;
        }
        ret2 = strcmp("C", lw_variable[I].lv_type);
        if(ret2 == 0)
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
          gw_variable[I].gv_use_ct++;
          ret2 = strcmp("I", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd6_type = 1;
          }
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd6_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_505 E-155 tfield6 Not Found = %s\n", tfield6);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    fd7_type = 0;
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
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if(ret2 == 0)
        {
          fd7_type = 1;
        }
        ret2 = strcmp("C", lw_variable[I].lv_type);
        if(ret2 == 0)
        {
          fd7_type = 2;
        }
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
          ret2 = strcmp("I", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd7_type = 1;
          }
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd7_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_505 E-156 tfield7 Not Found = %s\n", tfield7);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    fd8_type = 0;
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
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if(ret2 == 0)
        {
          fd8_type = 1;
        }
        ret2 = strcmp("C", lw_variable[I].lv_type);
        if(ret2 == 0)
        {
          fd8_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield8, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield8a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          ret2 = strcmp("I", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd8_type = 1;
          }
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd8_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_505 E-157 tfield8 Not Found = %s\n", tfield8);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }


    if((fd3_type == 1) && (fd6_type == 1))
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield6a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield6);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #450");
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
        strcpy(trace_1, "c2z_math.c #451");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #452");
        trace_rec_3();
      }
    }

    if((fd3_type == 2) && (fd6_type == 2))
    {
      strcpy(a_string, "         LHI   R0,X'0'");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #453");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R1,");
      strcat(a_string, tfield6a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield6);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #454");
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
        strcpy(trace_1, "c2z_strcpy.c #455");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R3,1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #456");
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
        strcpy(trace_1, "c2z_strcpy.c #457");
        trace_rec_3();
      }

      strcpy(a_string, "         MVST  R2,R1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #458");
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
        strcpy(trace_1, "c2z_strcpy.c #459");
        trace_rec_3();
      }

      strcpy(a_string, "         SR    R1,R3");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #456");
        trace_rec_3();
      }
    }

 
    if((fd4_type == 1) && (fd7_type == 1))
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield7a);
      strcpy(wk_remark, " "); 
      strcat(wk_remark, tfield7);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #457");
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
        strcpy(trace_1, "c2z_math.c #458");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #459");
        trace_rec_3();
      }
    }

    if((fd4_type == 2) && (fd7_type == 2))
    {
      strcpy(a_string, "         LHI   R0,X'0'");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #460");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R1,");
      strcat(a_string, tfield7a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield7);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #461");
        trace_rec_3();
      }
      strcpy(a_string, "         LARL  R2,");
      strcat(a_string, tfield4a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield4);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #462");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R3,1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #463");
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
        strcpy(trace_1, "c2z_strcpy.c #464");
        trace_rec_3();
      }

      strcpy(a_string, "         MVST  R2,R1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #465");
        trace_rec_3();
      }

      strcpy(a_string, "         JO    ");
      strcat(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "B");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #466");
        trace_rec_3();
      }

      strcpy(a_string, "         SR    R1,R3");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #467");
        trace_rec_3();
      }
    }

    if((fd5_type == 1) && (fd8_type == 1))
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield8a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield8);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #468");
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
        strcpy(trace_1, "c2z_math.c #469");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #470");
        trace_rec_3();
      }
    }

    if((fd5_type == 2) && (fd8_type == 2))
    {

      strcpy(a_string, "         LHI   R0,X'0'");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #471");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R1,");
      strcat(a_string, tfield8a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield8);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #472");
        trace_rec_3();
      }
      strcpy(a_string, "         LARL  R2,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #473");
        trace_rec_3();
      }

      strcpy(a_string, "         LR    R3,1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #474");
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
        strcpy(trace_1, "c2z_strcpy.c #475");
        trace_rec_3();
      }

      strcpy(a_string, "         MVST  R2,R1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #476");
        trace_rec_3();
      }

      strcpy(a_string, "         JO    ");
      strcat(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "C");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #477");
        trace_rec_3();
      }

      strcpy(a_string, "         SR    R1,R3");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strcpy.c #478");
        trace_rec_3();
      }
    }

    x3 = 0;
    for (I = 0; I < fn_ct; I++) 
    {
      ret = strcmp(tfield2, w_function[I].fn_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield2a, w_function[I].fn_cname);
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c math_505 #170 Not Found tfield2 = %s\n",tfield2);
      printf("c2z_math.c  math_505 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #479");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #480");
      trace_rec_3();
    }

    fd1_type = 0;
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
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if(ret2 == 0)
        {
          fd1_type = 1;
        }
        ret2 = strcmp("C", lw_variable[I].lv_type);
        if(ret2 == 0)
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
          ret2 = strcmp("I", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd1_type = 1;
          }
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd1_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_505 E-158 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    fd9_type = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield9, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield9a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if(ret2 == 0)
        {
          fd9_type = 1;
        }
        ret2 = strcmp("C", lw_variable[I].lv_type);
        if(ret2 == 0)
        {
          fd9_type = 2;
        }
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
          strcpy(tfield9a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          ret2 = strcmp("I", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd9_type = 1;
          }
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if(ret2 == 0)
          {
            fd9_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_505 E-159 tfield9 Not Found = %s\n", tfield9);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #481");
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
      strcpy(trace_1, "c2z_math.c #482");
      trace_rec_3();
    }

    if((fd1_type == 1) && (fd9_type == 1))
    {
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #483");
        trace_rec_3();
      }
    }

    if((fd1_type == 2) && (fd9_type == 2))
    {
      strcpy(a_string, "         MVC2  ");
      strcat(a_string, tfield8a);
      strcat(a_string, ",");
      strcat(a_string, tfield5a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #484");
        trace_rec_3();
      }
    }

    convert = 1;
    return;
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
      strcpy(trace_1, "c2z_math.c #485");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield4a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #486");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R9),(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #487");
      trace_rec_3();
    }

    strcpy(a_string, "         BRASL C370LNK,");
    strcat(a_string, tfield3a);
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #488");
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
      strcpy(trace_1, "c2z_math.c #489");
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
      strcpy(trace_1, "c2z_math.c #490");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R9),(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #491");
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
      printf("\nc2z_math.c c2_math_505 math-059 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-060 tfield2 (function) Not Found = %s\n",tfield2);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
        printf("\nc2z_math.c c2_math_505 math-061 tfield6 Not Found = %s\n", tfield6);
        printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
        strcpy(trace_1, "c2z_math.c #475");
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
        strcpy(trace_1, "c2z_math.c #476");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #477");
        trace_rec_3();
      }

      strcpy(a_string, "         BRASL C370LNK,");
      strcat(a_string, tfield2a);
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #478");
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
        strcpy(trace_1, "c2z_math.c #479");
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
        strcpy(trace_1, "c2z_math.c #480");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #481");
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
        printf("\nc2z_math.c c2_math_505 math-062 ONE VAR ERROR tfield3 Not Found = %s\n",tfield1);
        printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
          strcpy(trace_1, "c2z_math.c #482");
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
          strcpy(trace_1, "c2z_math.c #483");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #484");
          trace_rec_3();
        }

        strcpy(a_string, "         BRASL C370LNK,");
        strcat(a_string, tfield2a);
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #485");
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
          strcpy(trace_1, "c2z_math.c #486");
          trace_rec_3();
        }

        strcpy(a_string, "         BRASL C370LNK,");
        strcat(a_string, tfield2a);
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #487");
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
          strcpy(trace_1, "c2z_math.c #488");
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
          strcpy(trace_1, "c2z_math.c #489");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #490");
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
          strcpy(trace_1, "c2z_math.c #491");
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
      printf("\nc2z_math.c c2_math_505 math-063 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-064 tfield4 Not Found = %s\n", tfield4);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-065 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-066 tfield2 function Not Found \n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-067 tfield6 Not Found = %s\n", tfield6);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-068 tfield7 Not Found = %s\n", tfield7);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield6a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #492");
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
      strcpy(trace_1, "c2z_math.c #493");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #494");
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
      strcpy(trace_1, "c2z_math.c #495");
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
      strcpy(trace_1, "c2z_math.c #496");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #497");
      trace_rec_3();
    }

    strcpy(a_string, "         BRASL C370LNK,");
    strcat(a_string, tfield2a);
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #498");
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
        strcpy(trace_1, "c2z_math.c #499");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #500");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #501");
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
        strcpy(trace_1, "c2z_math.c #502");
        trace_rec_3();
      }
      convert = 1;
    }

    if ((fd1_type == 2) && (fd3_type == 2)) 
    {
      printf("\nc2z_math.c c2_math_505 math-069 fd1 & fd3 type == 2 NEED TO BE CODED\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd1_type == 1) && (fd3_type == 2)) 
    {
      printf("\nc2z_math.c c2_math_505 math-070 field1 & field3 MISMATCH ERROR\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd1_type == 2) && (fd3_type == 1)) 
    {
      printf("\nc2z_math.c c2_math_505 math-071 field1 & field3 MISMATCH ERROR\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-072 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-073 tfield4 Not Found = %s\n", tfield4);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-074 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-075 tfield6 Not Found = %s\n", tfield6);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-076 tfield2 function Not Found \n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-077 tfield2 function Not Found \n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_505 math-078 tfield21 Not Found = %s\n", tfield21);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
        strcpy(trace_1, "c2z_math.c #503");
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
        strcpy(trace_1, "c2z_math.c #504");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #505");
        trace_rec_3();
      }
    }

    if ((fd4_type == 1) && (fd21_type == 2)) /* integer to char ERROR	*/
    {
      printf("\nc2z_math.c c2_math_505 math-079 comma = 2 Numeric to Char move ERROR\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd4_type == 2) && (fd21_type == 1)) /* char to integer ERROR	*/
    {
      printf("\nc2z_math.c c2_math_505 math-080 comma = 2 Char to Numeric move ERROR\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
        strcpy(trace_1, "c2z_math.c #506");
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
      printf("\nc2z_math.c c2_math_505 math-081 tfield22 Not Found = %s\n", tfield22);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
        strcpy(trace_1, "c2z_math.c #507");
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
        strcpy(trace_1, "c2z_math.c #508");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #509");
        trace_rec_3();
      }
    }

    if ((fd5_type == 1) && (fd22_type == 2)) 		/* integer to char ERROR	*/
    {
      printf("\nc2z_math.c c2_math_505 math-082 comma = 2 Numeric to Char move ERROR\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd5_type == 2) && (fd22_type == 1)) 		/* char to integer ERROR	*/
    {
      printf("\nc2z_math.c c2_math_505 math-083 comma = 2 Char to Numeric move ERROR\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
        strcpy(trace_1, "c2z_math.c #510");
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
      printf("\nc2z_math.c c2_math_505 math-084 tfield23 Not Found = %s\n", tfield23);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
        strcpy(trace_1, "c2z_math.c #511");
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
        strcpy(trace_1, "c2z_math.c #512");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #513");
        trace_rec_3();
      }
    }

    if ((fd6_type == 1) && (fd23_type == 2)) 		/* integer to char ERROR	*/
    {
      printf("\nc2z_math.c c2_math_505 math-085 comma = 2 Numeric to Char move ERROR\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd6_type == 2) && (fd23_type == 1)) 		/* char to integer ERROR	*/
    {
      printf("\nc2z_math.c c2_math_505 math-086 comma = 2 Char to Numeric move ERROR\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd6_type == 2) && (fd23_type == 2)) 		/* char to char		*/
    {
      printf("\nc2z_math.c c2_math_505 math-087 comma = 2 Char to Char move NOT CODED\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #514");
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
        strcpy(trace_1, "c2z_math.c #515");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #516");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #517");
        trace_rec_3();
      }
    }

    if ((fd1_type == 2) && (fd3_type == 2)) 
    {
      printf("\nc2z_math.c c2_math_505 math-088 fd1 & fd3 type == 2 NEED TO BE CODED\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd1_type == 1) && (fd3_type == 2)) 
    {
      printf("\nc2z_math.c c2_math_505 math-089 field1 & field3 MISMATCH ERROR\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if ((fd1_type == 2) && (fd3_type == 1)) 
    {
      printf("\nc2z_math.c c2_math_505 math-090 field1 & field3 MISMATCH ERROR\n");
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }
}



void c2_math_506()			/* s_holder[i] = sv_stack[x][y];	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_506 START");
    trace_rec_1();
  }

   int pi;
   int pi2;
   int x3;
   int I;
   int ret;
   int ret1;

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
  while((ch == ' ') || (ch== '\t'))
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
  while(ch != '=')
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
  while(ch != '[')
  {
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  pi2 = 0;
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

  pi2 = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    field5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field5[pi2] = '\0';

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
    printf("\nc2z_math.c c2_math_506 E-801 field1 Not Found = %s\n",field1);
    printf("c2z_math.c c2_math_506 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field2, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field2a,lw_variable[I].lv_cname);
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
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_math.c c2_math_506 E-802 field2 Not Found = %s\n",field2);
    printf("c2z_math.c c2_math_506 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field3, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field3a,lw_variable[I].lv_cname);
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
        strcpy(ar_field5, gw_variable[I].gv_dsect);
        strcpy(ar_field6, gw_variable[I].gv_label);
        strcpy(ar_field7, gw_variable[I].gv_table);
        strcpy(ar_field8, gw_variable[I].gv_aname);
        strcpy(ar_field9, gw_variable[I].gv_sv_reg);
        strcpy(ar_field10, gw_variable[I].gv_wk_reg);
        strcpy(ar_field11, gw_variable[I].gv_wk_strg);
        strcpy(ar_field12, gw_variable[I].gv_st_col);
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_math.c c2_math_506 E-803 field3 Not Found = %s\n",field3);
    printf("c2z_math.c c2_math_506 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field4, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field4a,lw_variable[I].lv_cname);
      break;
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
    printf("\nc2z_math.c c2_math_506 E-804 field4 Not Found = %s\n",field4);
    printf("c2z_math.c c2_math_506 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }
 
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field5, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field5a,lw_variable[I].lv_cname);
      break;
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
    printf("\nc2z_math.c c2_math_506 E-805 field5 Not Found = %s\n",field5);
    printf("c2z_math.c c2_math_506  rct = %d p_string = %s\n",rct,p_string);
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
    strcpy(trace_1, "c2z_math.c #600");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #601");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #602");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #603");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, ar_field7);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #604");
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
    strcpy(trace_1, "c2z_math.c #605");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #606");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field4a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field4);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #607");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #608");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "C");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #609");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #610");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #611");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #612");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #613");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #614");
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
    strcpy(trace_1, "c2z_math.c #615");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #616");
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
    strcpy(trace_1, "c2z_math.c #617");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #618");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #619");
    trace_rec_3();
  }

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #620");
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
    strcpy(trace_1, "c2z_math.c #621");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #622");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #623");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #624");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field5a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field5);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #625");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #626");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #627");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R3,0(R9)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #628");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R6,R3");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #629");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R6)");
  src_line();
  if (puncde == 1) 
  { 
    strcpy(trace_1, "c2z_math.c #630");
    trace_rec_3();
  }
  return;
}



/* *****************************************************
*  Punch xxx[] = yyy[]                                 *
* **************************************************** */
void c2_math_507()			/* p_string[I] = prog_name[z];	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_507 START");
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
    printf("\nc2z_math.c c2_math_507 math-125 field1 Not Found = %s\n", field1);
    printf("c2z_math.c c2_math_507 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_507 math-128 field2 Not Found = %s\n", field2);
      printf("c2z_math.c c2_math_507 rct = %d p_string = %s", rct, p_string);
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
    printf("\nc2z_math.c c2_math_507 math-126 field3 Not Found = %s\n", field3);
    printf("c2z_math.c c2_math_507 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_507 math-127 field4 Not Found = %s\n", field4);
      printf("c2z_math.c c2_math_507 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

/*
printf("\nc2z.math.c math_507 rct = %d p_string = %s",rct,p_string);
printf("c2z.math.c math_507 field1 = %s m5fd1_type = %d\n",field1,m5fd1_type);
printf("c2z_math.c math_507 field2 = %s m5fd2_type = %d\n",field2,m5fd2_type);
printf("c2z_math.c math_507 field3 = %s m5fd3_type = %d\n",field3,m5fd3_type);
printf("c2z_math.c math_507 field4 = %s m5fd4_type = %d\n",field4,m5fd4_type);
*/

  if ((m5fd1_type == 3) && (m5fd2_type == 2) && (m5fd3_type == 3) && (m5fd4_type == 2)) 
  {
    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #701");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #702");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #703");
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
      strcpy(trace_1, "c2z_math.c #704");
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
      strcpy(trace_1, "c2z_math.c #705");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #706");
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
            strcpy(trace_1, "c2z_math.c #707");
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
            strcpy(trace_1, "c2z_math.c #708");
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
        printf("\nc2z_math.c c2_math_507 math-128 field2 Not Found = %s\n", field2);
        printf("c2z_math.c c2_math_507 rct = %d p_string = %s", rct, p_string);
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
        strcpy(trace_1, "c2z_math.c #709");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #710");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #711");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #712");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #713");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #714");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #715");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #716");
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
      strcpy(trace_1, "c2z_math.c #717");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #718");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #719");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #720");
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
      strcpy(trace_1, "c2z_math.c #721");
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
      strcpy(trace_1, "c2z_math.c #722");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #723");
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
          strcpy(trace_1, "c2z_math.c #724");
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
        printf("\nc2z_math.c c2_math_507 math-129 field4 Not Found = %s\n", field4);
        printf("c2z_math.c c2_math_507 rct = %d p_string = %s", rct, p_string);
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
        strcpy(trace_1, "c2z_math.c #725");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #726");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #727");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R5,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #728");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #729");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #730");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #731");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #732");
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
      strcpy(trace_1, "c2z_math.c #733");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #734");
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
      strcpy(trace_1, "c2z_math.c #735");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #736");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #737");
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
      strcpy(trace_1, "c2z_math.c #738");
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
      strcpy(trace_1, "c2z_math.c #739");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #40");
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
            strcpy(trace_1, "c2z_math.c #741");
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
            strcpy(trace_1, "c2z_math.c #742");
            trace_rec_3();
          }
          break;
        }
      }
*/

printf("FIX FIX FIX c2_math_507 #56b\n");
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
        printf("\nc2z_math.c c2_math_507 math-130 field2 Not Found = %s\n", field2);
        printf("c2z_math.c c2_math_507 rct = %d p_string = %s", rct, p_string);
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
        strcpy(trace_1, "c2z_math.c #743");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #744");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #745");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #746");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #747");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #748");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #749");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #750");
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
      strcpy(trace_1, "c2z_math.c #751");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #752");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #753");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #754");
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
      strcpy(trace_1, "c2z_math.c #755");
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
      strcpy(trace_1, "c2z_math.c #756");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #757");
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
          strcpy(trace_1, "c2z_math.c #758");
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
            strcpy(trace_1, "c2z_math.c #759");
            trace_rec_3();
          }
          break;
        }
      }
    }
*/

printf("FIX FIX FIX c2_math_507 #73\n");
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
        strcpy(trace_1, "c2z_math.c #760");
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
        strcpy(trace_1, "c2z_math.c #761");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #762");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #763");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R5,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #764");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #765");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #766");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #767");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #768");
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
      strcpy(trace_1, "c2z_math.c #769");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R5)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #770");
      trace_rec_3();
    }

    convert = 1;
  }

  if ((m5fd1_type == 2) && (m5fd2_type == 2) && (m5fd3_type == 2) && (m5fd4_type == 2)) 
  {
    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #771");
      trace_rec_3();
    }
    work_use_ct[48]++;
  
/* #3333 */
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */ ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #772");
      trace_rec_3();
    }
 
    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #773");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #774");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R5,0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #775");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */ ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #776");
      trace_rec_3();
    }

    strcpy(a_string, "         IC    R0,0(R8,(R5))");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #777");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #778");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         STC   R0,0(0,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #779");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #780");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */ ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #781");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #782");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #783");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R2,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #784");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */ ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #785");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R1,R9");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #786");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R1,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #787");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #788");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         MVC   0(1,R1),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #789");
      trace_rec_3();
    }
  }
}


/* ************************************
*   x = 7;                            *
************************************* */

void c2_math_508()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_508 START");
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
    printf("\nc2z_math.c c2_math_508 math-005 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_math.c c2_math_508 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #800");
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
      strcpy(trace_1, "c2z_math.c #802");
      trace_rec_3();
    }

    if (fd1_id == 3) 
    {
      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #803");
        trace_rec_3();
      }
    }

    if (fd1_id == 2) 
    {
      printf("\nc2z_math.c c2_math_508 math-006 rct = %d fd1_id = 2 NOT CODED\n", rct);
      printf("c2z_math.c c2_math_508 rct = %d p_string = %s", rct, p_string);
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
      printf("\nc2z_math.c c2_math_508 math-007 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_math.c c2_math_508 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #804");
      trace_rec_3();
    }
    
    if (fd2_type == 2) 
    {
      strcpy(a_string, "        LAEY  R5,");
      strcat(a_string, tfield2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #805");
        trace_rec_3();
      }

      strcpy(a_string, "        LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #806");
        trace_rec_3();
      }
      work_use_ct[48]++;
  
      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #807");
        trace_rec_3();
      }

      strcpy(a_string, "          LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #808");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #809");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "        ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #810");
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
      strcpy(trace_1, "c2z_math.c #811");
      trace_rec_3();
    }
 
    if ((fd1_type == 1) && (fd2_type == 1) && (fd1_status == 1)) 
    {
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #812");
        trace_rec_3();
      }
    }

    if(fd1_status == 2)
    {
      strcpy(a_string, "         MVC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #813");
        trace_rec_3();
      }
    }

    if ((fd1_id == 2) && (fd2_id == 2)) 
    {
      strcpy(a_string, "         LD    R2,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #814");
        trace_rec_3();
      }

      strcpy(a_string, "         STD   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #815");
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
      strcpy(trace_1, "c2z_math.c #816");
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
        strcpy(trace_1, "c2z_math.c #817");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #818");
        trace_rec_3();
      }
      work_use_ct[48]++;
  
      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #819");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #820");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #821");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #822");
        trace_rec_3();
      }
    }

    if ((fd1_type == 1)  && (fd2_type == 2))
    {
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #823");
        trace_rec_3();
      }
    }

    if ((fd1_type == 2) && (fd2_type == 2)) 
    {
      strcpy(a_string, "         LD    R2,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #824");
        trace_rec_3();
      }

      strcpy(a_string, "         STD   R2,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #825");
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
      strcpy(trace_1, "c2z_math.c #826");
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
      strcpy(trace_1, "c2z_math.c #827");
      trace_rec_3();
    }
   
    strcpy(a_string, "         MVC   0(R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #828");
      trace_rec_3();
    }
    convert = 1;
    return;
  }
}




void c2_math_509()		/* array equal calling subroutine iv_stack[ndx] = rdp_set()  	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_509 START");
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
      break;
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
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("c2z_math.c c2_math_509 math-091 field1 Not Found = %s\n", field1);
    printf("c2z_math.c c2_math_509 rct = %d p_string = %s", rct, p_string);
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
          strcpy(trace_1, "c2z_math.c #900");
          trace_rec_3();
        }
      }
    }
*/

printf("FIX FIX FIX c2_math_509 #11\n");
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
        break;
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("c2z_math.c c2_math_509 math-092 field2 Not Found = %s\n", field2);
      printf("c2z_math.c c2_math_509 rct = %d p_string = %s", rct, p_string);
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
        break;
      }
    }

    if (x3 == 0) 
    {
      printf("c2z_math.c c2_math_509 math-093 field3 function Not Found = %s\n",field3);
      printf("c2z_math.c c2_math_509 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #901");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #902");
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
        break;
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
          break;
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
        break;
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
          break;
        }
      }
    }

/*
printf("\nc2z_math.c math_509 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c math_509 field1 = %s\n",field1);
printf("c2z_math.c math_509 field2 = %s\n",field2);
printf("c2z_math.c math_509 field3 = %s\n",field3);
printf("c2z_math.c math_509 field4 = %s field4a = %s wk_sv_func = %s\n",field4,field4a,wk_sv_func);
printf("c2z_math.c math_509 x10 = %d\n",x10);
*/

    if (x3 == 0) 
    {
      printf("c2z_math.c c2_math_509 math-094 field4 Not Found = %s\n", field4);
      printf("c2z_math.c c2_math_509 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK2"); 		/*  store return value back into call sub	*/
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #903");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string,"         LARL  R8,"); 			/* return value from called sub 	*/
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #904");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #383");
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
          break;
        }
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #905");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #906");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #907");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #908");
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
        break;
      }
    }
    x4 = 250;

    strcpy(a_string, "         LA    R5,");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #909");
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
      strcpy(trace_1, "c2z_math.c #910");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #911");
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
      strcpy(trace_1, "c2z_math.c #912");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #913");
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
      strcpy(trace_1, "c2z_math.c #914");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #915");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #916");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #917");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #918");
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
      strcpy(trace_1, "c2z_math.c #919");
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
      strcpy(trace_1, "c2z_math.c #920");
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
      strcpy(trace_1, "c2z_math.c #921");
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
        break;
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #922");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #923");
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
      strcpy(trace_1, "c2z_math.c #924");
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
        break;
      }
    }

    if (x3 == 0) 
    {
      printf("c2z_math.c c2_math_509 math-095 field3 function Not Found = %s\n",field3);
      printf("c2z_math.c c2_math_509 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #925");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #926");
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
        break;
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
          break;
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
        break;
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("c2z_math.c c2_math_509 math-096 field4 Not Found = %s\n", field4);
      printf("c2z_math.c c2_math_509 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK2"); 		/*  store return value back into call sub	*/
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #927");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string,"         LARL  R8,"); 			/* return value from called sub 	*/
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #928");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #929");
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
          break;
        }
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #930");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #931");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #932");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #933");
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
        break;
      }
    }
    x4 = 250;

    strcpy(a_string, "         LA    R5,");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #934");
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
      strcpy(trace_1, "c2z_math.c #935");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #936");
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
      strcpy(trace_1, "c2z_math.c #937");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #938");
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
      strcpy(trace_1, "c2z_math.c #939");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #940");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #941");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #942");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #943");
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
      strcpy(trace_1, "c2z_math.c #944");
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
      strcpy(trace_1, "c2z_math.c #945");
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
      strcpy(trace_1, "c2z_math.c #946");
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
        break;
      }
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #947");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         ZAP   0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #948");
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
      strcpy(trace_1, "c2z_math.c #949");
      trace_rec_3();
    }
    convert = 1;
  }
}


void c2_math_510()
{
   int x3 = 0;
   int I;
   int fd1_type = 0;
   int fd3_type = 0;
   int fd5_type = 0;
   int ret;
   int ret1;
   int ret2;
   int x2;
   int x6;
   int pi;
   int pi2;
   int fn_loc  = 0;
   int operand_1 = 0;

  char ch;
  char *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield4a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char wk_sv_func[VAR_LGTH];

    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_math.c c2_math_505 Proc #1");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while((ch == ' ') || (ch == '\t'))
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    x2 = 0;
    fd1_type = 0;
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
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

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

    fn_loc = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ' ')
    {
      fn_loc = 1;
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != ' ')
    {
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != '(')
    {
      fn_loc = 2;
      tfield4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield1a, lw_variable[I].lv_cname);
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("c2z_math.c c2_math_510 math-091 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_math.c c2_math_510 rct = %d p_string = %s", rct, p_string);
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
        break;
     }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        x6 = strcmp(tfield2, gw_variable[I].gv_name);
        if (x6 == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, gw_variable[I].gv_cname);
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("c2z_math.c c2_math_510 math-091 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_math.c c2_math_510 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "+");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "-");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "*");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "/");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if(fn_loc == 2)
    {
      if (fn_ct > 0) 
      {
        x3 = 0;
        for (I = 0; I < fn_ct; I++) 
        {
          ret = strcmp(tfield4, w_function[I].fn_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield4a, w_function[I].fn_cname);
            strcpy(tfield5, w_function[I].fn_ret_var);
            strcpy(tfield6, w_function[I].fn_fd1); 
            strcpy(wk_sv_func, tfield4); 
            break;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_math.c c2_math_510 E-900 tfield4 (function) Not Found = %s\n",tfield4);
        printf("c2z_math.c c2_math_510 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

/*
printf("\nc2z_math.c math_510 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c math_510 tfield1 = %s tfield1a = %s fd1_type = %d\n",tfield1,tfield1a,fd1_type);
printf("c2z_math.c math_510 tfield2 = %s tfield2a = %s fd2_type = %d\n",tfield2,tfield2a,fd2_type);
printf("c2z_math.c math_510 tfield3 = %s operand_1 = %d\n",tfield3,operand_1);
printf("c2z_math.c math_510 tfield4 = %s fn_loc = %d\n",tfield4,fn_loc);
printf("c2z_math.c math_510 tfield5 = %s fd5_type = %d wk_sv_func = %s\n",tfield5,fd5_type,wk_sv_func);
printf("c2z_math.c math_510 tfield6 = %s\n",tfield6);
*/


    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1000");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1001");
      trace_rec_3();
    }

    fd5_type = 0;
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
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if (ret2 == 0) 
        {
          fd5_type = 1;	/* numeric */
        } 
        ret2 = strcmp("C", lw_variable[I].lv_type);
        if (ret2 == 0) 
        {
          fd5_type = 2;	/* char    */
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
          gw_variable[I].gv_use_ct++;
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if (ret2 == 0) 
          {
            fd5_type = 1;	/* numeric */  
          } 
          ret2 = strcmp("C", gw_variable[I].gv_type);
          if (ret2 == 0) 
          {
            fd5_type = 2;	/* char    */
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_510 E-902 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_math.c c2_math_505 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_math.c #1002");
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
      strcpy(trace_1, "c2z_math.c #1003");
      trace_rec_3();
    }

/*
printf("c2z_math.c math_510 tfield1 = %s tfield1a = %s fd1_type = %d\n",tfield1,tfield1a,fd1_type);
printf("c2z_math.c math_510 tfield5 = %s fd5_type = %d\n",tfield5,fd5_type);
*/

    if((fd1_type == 1) && (fd5_type == 1))
    {
      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #1004");
        trace_rec_3();
      }
    }

    if((fd1_type == 2) && (fd5_type == 2))
    {
      strcpy(a_string, "         MVC2  ");
      strcat(a_string, tfield1a);
      strcat(a_string, ",");
      strcat(a_string, tfield5a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #1005");
        trace_rec_3();
      }
    }

    if((fd1_type == 1) && (fd3_type == 2))
    {
      printf("c2z_math.c c2_math_510 Return Variable Mis_Match E-986\n");
      printf("rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if((fd1_type == 2) && (fd3_type == 1))
    {
      printf("c2z_math.c c2_math_510 Return Variable Mis_Match E-987\n");
      printf("rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if(operand_1 == 1)
    {
      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #1006");
        trace_rec_3();
      }
    }

    if(operand_1 == 2)
    {
      strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #1007");
        trace_rec_3();
      }
    }

    if(operand_1 == 3)
    {
      strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #1008");
        trace_rec_3();
      }
    }

    if(operand_1 == 4)
    {
      strcpy(a_string, "         LARL  R9,C370DEND");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #1009");
        trace_rec_3();
      }
      work_use_ct[40]++;

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #1010");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(7,R9),0(6,R8) ");  
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #1011");
        trace_rec_3();
      }

    strcpy(a_string, "         LARL  R9,C370ISOR");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1012");
      trace_rec_3();
    }
    work_use_ct[43]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1013");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8) ");  
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1014");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370DEND");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1015");
      trace_rec_3();
    }
    work_use_ct[40]++;

    strcpy(a_string, "         LARL  R8,C370ISOR");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1016");
      trace_rec_3();
    }
    work_use_ct[43]++;

    strcpy(a_string, "         DP    0(7,R9),0(6,R8) ");  
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1017");
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
      strcpy(trace_1, "c2z_math.c #1018");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370IENT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1019");
      trace_rec_3();
    }
    work_use_ct[41]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(1,R8) ");  
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1020");
      trace_rec_3();
    }
  }
}



void c2_math_511()			/*  char  test[2] = 444;   */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math.c c2_math_511");
    trace_rec_1();
  }

  char ch;
  char *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field2b[VAR_LGTH];
  char field2c[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];

  int pi;
  int pi2;
  int x2 = 0;
  int x3 = 0;
  int x10 = 0;
  int x11 = 0;
  int x12 = 0;
  int m5_3 = 0;
  int m5_6 = 0;
  int m5fd2_type = 0;
  int m5fd2c_type = 0;
  int m5fd3_type = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int operand_1 = 0;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

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
      break;
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
        break;
      }
    }
  }

  if (m5_3 == 0) 
  {
    printf("\nc2z_math.c c2_math_511 math-024 field1 Not Found = %s\n", field1);
    printf("c2z_math.c c2_math_511 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi++;
  ch = p_string[pi];
  pi2 = 0;
  m5fd2_type = 0;
  x2 = 0;
  x12 = 0;
  while (ch != ']') 
  {
    if(ch == ' ')
    {
      x12 = 1;
      break;
    }
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

  if(x12 == 1)		/*  p_string[loc + 1] */
  {
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }
 
    pi2 = 0;
    while(ch != ' ')
    {
      field2b[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2b[pi2] = '\0';

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    m5fd2c_type = 0;
    x2 = 0;
    pi2 = 0;
    while(ch != ']')
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          m5fd2c_type = 2;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          m5fd2c_type = 1;
          x2 = 1;
        }
      }
      field2c[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2c[pi2] = '\0';
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
        lw_variable[I].lv_use_ct++;
        break;
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
          break;
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("\nc2z_math.c c2_math_511 math-025 field2 Not Found = %s\n", field2);
      printf("c2z_math.c c2_math_511 rct = %d p_string = %s", rct, p_string);
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
  m5fd3_type = 0;
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
        break;
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
          break;
        }
      }
    }

    if (m5_3 == 0) 
    {
      printf("\nc2z_math.c c2_math_511 math-026 field3 Not Found = %s\n", field3);
      printf("c2z_math.c c2_math_511 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

/*
if(rct == 500)
{
printf("\nc2z_math.c math_511 rct = %d p_string = %s",rct,p_string);
printf("c2z_math.c math_511 field1 = %s field1a = %s\n",field1,field1a);
printf("c2z_math.c math_511 field2 = %s field2a = %s m5fd2_type = %d\n",field2,field2a,m5fd2_type);
printf("c2z_math.c math_511 field2b = %s\n",field2b);
printf("c2z_math.c math_511 field2c = %s m5fd2c_type = %d\n",field2c,m5fd2c_type);
printf("c2z_math.c math_511 field3 = %s m5fd3_type = %d\n",field3,m5fd3_type);
}
*/

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field1a, lw_variable[I].lv_cname);
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
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_math.c c2_math_511 math-028 field1 Not Found = %s\n", field1);
    printf("c2z_math.c c2_math_511 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }
  

  if(m5fd2_type == 2)
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_511 math-028 field2 Not Found = %s\n", field2);
      printf("c2z_math.c c2_math_511 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if((m5fd3_type == 1) && (x10 == 0))
  {
    printf("\nc2z_math.c c2_math_511 m5fd3_type == 1 NOT CODED\n");
    printf("c2z_math.c c2_math_511 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if((m5fd3_type == 2) && (x10 == 0))
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field3, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field3a, lw_variable[I].lv_cname);
        break;
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
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_math.c c2_math_511 math-028 field3 Not Found = %s\n", field3);
      printf("c2z_math.c c2_math_511 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if((m5fd3_type == 1) && (x11 == 0))
  {
    p = strstr(field3, "\n");
    if(p)
    {
      x11 = 1;
    }
  }

  if((m5fd3_type == 1) && (x10 == 1))
  {
    p = strstr(field3, "\0");
    if(p)
    {
      strcpy(field3, "C370EOF");
      m5fd3_type = 2;
    }
  }

/*
  if((m5fd3_type == 1) && (x10 == 1))
  {
    p = strstr(field3, "\0");
    if(p)
    {
      strcpy(field3, "C370EOF");
      m5fd3_type = 2;
    }
  }
*/

   if(x12 == 1)
   {  
     strcpy(a_string, "         LARL  R9,C370NWK2");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_math_c #1100");
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
       strcpy(trace_1, "c2z_math.c #1101");
       trace_rec_3();
     }

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_math_c #1102");
       trace_rec_3();
     }
  }

  if(x12 == 1)
  {
    if(m5fd2c_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field2c);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #1103");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #1104");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #1105");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #1106");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #1107");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math_c #1108");
        trace_rec_3();
      }

      operand_1 = 0;
      p = strstr(field2b, "+");
      if(p)
      {
        operand_1 = 1;
      }

      p = strstr(field2b, "-");
      if(p)
      {
        operand_1 = 2;
      }

      p = strstr(field2b, "*");
      if(p)
      {
        operand_1 = 3;
      }

      p = strstr(field2b, "/");
      if(p)
      {
        operand_1 = 4;
      }

      if(operand_1 == 1)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field2a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field2);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #1109");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math_c #1110");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math_c #1111");
          trace_rec_3();
        }
      }
    }


    if(m5fd2c_type == 2)
    {
       printf("c2z_math.c math_511 m5fd2c_type == 2 NOT CODED\n");
       printf("c2z_math.c math_511 rct = %d p_string = %s\n",rct,p_string);
    }
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_c #1112");
    trace_rec_3();
  }
  work_use_ct[48]++;

  if(m5fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1113");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1114");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1115");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1116");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1117");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1118");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1119");
      trace_rec_3();
    }
    work_use_ct[49]++;
  }

  if(m5fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1120");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_c #1121");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370U");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_c #1122");
    trace_rec_3();
  }
  work_use_ct[48]++;

  strcpy(a_string, "         CVB   R2,0(R9)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_c #1123");
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
    strcpy(trace_1, "c2z_math.c #1124");
    trace_rec_3();
  }

  strcpy(a_string, "         LR    R1,R9");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_c #1125");
    trace_rec_3();
  }

  strcpy(a_string, "         AR    R1,R2");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_c #1126");
    trace_rec_3();
  }

  if(x10 == 0)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1127");
      trace_rec_3();
    }
  }

  if(x10 == 1)
  {
    if(m5fd3_type == 0)
    {
      strcpy(a_string, "         LARL  R8,C370B1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #1128");
        trace_rec_3();
      }
    }
  }
 
  if(x10 == 1)
  {
    if(m5fd3_type == 2)
    {
      p = strstr(field3, "n'");
      if(p)
      {
        strcpy(a_string, "         LARL  R8,C370B1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #1129");
          trace_rec_3();
        }
      }
      
      if((m5fd3_type == 2) && (!p))
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field3);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field3);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_math.c #1129");
          trace_rec_3();
        }
      }
    }
  }

  strcpy(a_string, "         MVC   0(1,R1),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_c #1130");
    trace_rec_3();
  }

  if(x12 == 1)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #1131");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #1132");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math_c #1133");
      trace_rec_3();
    }
  } 
}



