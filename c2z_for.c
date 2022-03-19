/* ***************************************************
*  c2z : c2Z_for.c :                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out FOR statement                           *
* ************************************************** */
void c2_for(void) 
{
   int pi = 0;
   int s;
   int x100 = 0;
   int x101 = 0;
   int x102 = 0;

  char ch;

  s = strlen(p_string);
  x100 = 0;
  x101 = 0;
  x102 = 0;
  pi = 0;
  while(pi <= s)
  {
    ch = p_string[pi];
    if(ch == '[')
    {
       x100++;
    }
    if(ch == ']')
    {
       x100++;
    }
    if(ch == '(')
    {
       x101++;
    }
    if(ch == ')')
    {
       x101++;
    }
    if(ch == '+')
    {
       x102++;
    }
    pi++;
  }

/*
printf("\nc2z_for.c  rct = %d p_string = %s",rct,p_string);
printf("c2z_for.c [] x100 = %d\n",x100);
printf("c2z_for.c () x101 = %d\n",x101);
printf("c2z_for.c +  x102 = %d\n",x102);
*/

/* ************************************************************************** *
 *	x100	x101	x102                                                     *
 *      []    ()       +                                                      *
 *       0     2       1   c2_for_021   for(; From <= Final; From != Inc)     *
 *       0     2       2   c2_for_022   for(i9 = 0; i9 < x; i9++)             *
 *       0     2       3   c2_for_023   for(i9 = 0: 19 < x + 1; i9++)         *
 *       0     2       4   c2_for_024   for9i9 - 0; ii < count; i++; left++)  *
 *       2     2       2   c2_for_222   for(i9 = 0; str[I] != x; i++)         *
 **************************************************************************** */


  if((x100 == 0) && (x101 == 2) && (x102 == 1))
  {
     c2_for_021();
     convert = 1;
     return;
  }

  if((x100 == 0) && (x101 == 2) && (x102 == 2))
  {
     c2_for_022();
     convert = 1;
     return;
  }

  if((x100 == 0) && (x101 == 2) && (x102 == 3))
  {
     c2_for_023();
     convert = 1;
     return;
  }

  if((x100 == 0) && (x101 == 2) && (x102 == 4))
  {
     c2_for_024();
     convert = 1;
     return;
  }


  if((x100 == 2) && (x101 == 2) && (x102 == 2))
  {
     c2_for_222();
     convert = 1;
     return;
  }


  printf("\nc2z_for.c NO MATCH\n");
  printf("c2z_for.c  rct = %d p_string = %s",rct,p_string);
  printf("c2z_for.c [] x100 = %d\n",x100);
  printf("c2z_for.c () x101 = %d\n",x101);
  printf("c2z_for.c +  x102 = %d\n",x102);
  printf("\n");
}



void c2_for_023()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_for.c c2_for_023 START");
    trace_rec_1();
  }

   int pi;
   int pi2;
   int pi3;
   int pi4;
   int pi5;
   int pi6;
   int x;
   int x2;
   int x3;
   int x10;
   int x11;
   int x20;
   int I;
   int fd1_type = 0;
   int fd2_type = 0;
   int fd3_type = 0;
   int fd5_type = 0;
   int fd6_type = 0;
   int fd7_type = 0;
   int ret;
   int ret1;
   int s;
   int v;
   int size;

  char *p,*p6;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield5b[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];
  char tfield20[VAR_LGTH];
  char wk_strg1[6];

  pi = 0;
  ch = p_string[pi];

  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  x10 = 0;
  p = strstr(p_string, "(;");
  if (p) 
  {
    x10 = 1;
  }

  if (x10 == 0)
  {
    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '=') 
    {
      if (ch != ' ') 
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
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

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
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for_023 E-001 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_for.c c2_for_023 rct = %d p_string = %s\n", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ';') 
    {
      if (ch != ' ') 
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd2_type = 1;
            x2 = 1;
          }

          if (isdigit(ch)) 
          {
            fd2_type = 2;
            x2 = 1;
          }
        }
        tfield2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    inside_for = 1;

 
    if (fd2_type == 1) 
    {
      x3 = 0;
      x2 = 0;
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
        x3 = 0;
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
        printf("\nc2z_for.c c2_for_023 E-002 tfield2 Not Found = %s\n", tfield2);
        printf("c2z_for.c c2_for_023 rct = %d p_string = %s\n", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }
  }

  strcpy(sv_for_return, "L");
  strcat(sv_for_return, wk_strg);
 
  /* ************************************************
   * for(; From <= Final; From += Inc)              *
   ************************************************ */
  if (x10 == 1)
  {
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    inside_for = 1;
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  while (ch != ' ') 
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
    if (ch == '<') 
    {
      goto skip_for_1;
    }
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
skip_for_1:
  tfield3[pi2] = '\0';

  x3 = 0;
  x2 = 0;
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
      ret = strcmp(tfield3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield3a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_for.c c2_for_023 E-59 tfield3 Not Found = %s\n", tfield3);
    printf("c2z_for.c c2_for_023 rct = %d p_string = %s", rct, p_string);
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
  while (ch != ' ') 
  {
    if (ch != ';') 
    {
      tfield4[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

  for_opr = 0;
  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "<=");
    if (p6) 
    {
      for_opr = 6;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, ">=");
    if (p6) 
    {
      for_opr = 5;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "<");
    if (p6) 
    {
      for_opr = 4;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, ">");
    if (p6) 
    {
      for_opr = 3;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "!=");
    if (p6) 
    {
      for_opr = 2;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "==");
    if (p6) 
    {
      for_opr = 1;
    }
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  fd5_type = 0;
  pi2 = 0;
  x2 = 0;
  while (ch != ';') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd5_type = 1;
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
        fd5_type = 2;
        x2 = 1;
      }
    }
    if (ch == ')') 
    {
      break;
    }
    tfield5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield5[pi2] = '\0';

  pi3 = 0;
  p = strstr(tfield5, "+");
  if(p)
  {
    pi3 = 1;
  }
  p = strstr(tfield5, "-");
  if(p)
  {
    pi3 = 2;
  }

/* printf("c2z_for.c case_023 #201 pi3 = %d tfield5 = %s\n",pi3,tfield5); */
  if(pi3 != 0)
  {
    pi4 = 0;
    pi5 = 0;
    pi6 = 0;

    strcat(tfield5,";");
    ch = tfield5[pi4];
    while(ch != ' ')
    {
      if(ch == '+')
      {
        pi5 = 1;
        break;
      }
      if(pi5 == 0)
      {
        tfield5a[pi6] = ch;
        pi6++;
        pi4++;
        ch = tfield5[pi4];
      }
    }
    tfield5a[pi6] = '\0';
/* printf("c2z_for.c case_023 #202 tfield5a = %s\n",tfield5a); */

    pi6 = 0;
    pi4++;
    ch = tfield5[pi4];
    while(ch != ';')
    {
      tfield7[pi6] = ch;
      pi6++;
      pi4++;
      ch = tfield5[pi4];
    }
    tfield7[pi6] = '\0';

/*
printf("c2z.for.c case_023 #203 tfield7 = %s\n",tfield7);
printf("c2z.for.c case_023 #204 tfield5 = %s tfield5a = %s\n",tfield5,tfield5a);
*/

    strcpy(tfield5, tfield5a);

/* printf("c2z.for.c case_023 #205 tfield5 = %s tfield5a = %s\n",tfield5,tfield5a); */

  }

  if (fd5_type == 1) 
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
      x3 = 0;
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
      printf("\nc2z_for.c c2_for_023 E-62 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_for.c c2_for_023 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (ch == ')') 
  {
    goto skip_for_2;
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  fd6_type = 0;
  x20 = 0;
  pi2 = 0;
  while (ch != ')') 
  {
    if (ch == ',') 
    {
      x20 = 1;
      break;
    }

    if (ch == ' ') 
    {
      break;
    }

    if (ch != ' ') 
    {
      if (ch != '+') 
      {
        if (ch != '-') 
        {
          if (x2 == 0) 
          {
            if (isalpha(ch)) 
            {
              fd6_type = 1;
              x2 = 1;
            }
            if (isdigit(ch)) 
            {
              fd6_type = 2;
              x2 = 1;
            }
          }
          tfield6[pi2] = ch;
          pi2++;
        }
      }
    }
    pi++;
    ch = p_string[pi];
  }
  tfield6[pi2] = '\0';
  
  if((fd6_type == 0) || (fd6_type == 1) || (fd6_type == 2))
  {
    fd6_type++;
  }


  if (x20 == 1)   /* for(ii=0; ii < count; ii++, left++)  */
  {
    for_2nd_ct = 0;

    pi2 = 0;
    fd7_type = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '+') 
    {
      if(ch != ' ')
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd7_type = 1;
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
            fd7_type = 2;
            x2 = 1;
          }
        }
        tfield7[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield7[pi2] = '\0';

    x3 = 0;
    x2 = 0; 
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield7, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield7a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        for_2nd_ct = 1;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield7, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield7a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          for_2nd_ct = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for_023 E-165 tfield7 Not Found = %s\n", tfield7);
      printf("c2z_for.c c2_for_023 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_rct) 
      {
        strcpy(w_for_table[v].for_rt_field2, tfield7a);
        w_for_table[v].for_type = 1;
      }
    }
  }

  x3 = 0;
  x2 = 0;
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
      ret = strcmp(tfield6, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield6a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_for.c c2_for_023 E-65 tfield6 Not Found = %s\n", tfield6);
    printf("c2z_for.c c2_for_023 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  v = 0;
  for (v = 0; v < for_ct; v++) 
  {
    if (rct == w_for_table[v].for_rct) 
    {
      strcpy(w_for_table[v].for_rt_field, tfield6a);
      w_for_table[v].for_type = 1;
    }
  }


skip_for_2:

  x11 = 0;
  p = strstr(p_string, "+=");
  if (p) 
  {
    x11 = 1;
  }

  if (x11 == 1) 
  {
    pi++;
    ch = p_string[pi];
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

    fd7_type = 0;
    pi2 = 0;
    x2 = 0;
   
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd7_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          fd7_type = 2;
          x2 = 1;
        }
      }
      tfield7[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield7[pi2] = '\0';

    x3 = 0;
    if (fd7_type == 1) 
    {
      x2 = 0;
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield7, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield7a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          break;
        }
      }

      if (x3 == 0) 
      {
        x3 = 0;
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield7, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield7a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            break;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_for.c c2_for_023 E-62 tfield7 Not Found = %s\n", tfield7);
        printf("c2z_for.c c2_for_023 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }
  }

/*
printf("\nc2z_for.c #1 rct = %d p_string = %s",rct,p_string);
printf("c2z_for.c c2_for_023 #1 tfield1 = %s tfield1a = %s fd1_type = %d\n",tfield1,tfield1a,fd1_type);
printf("c2z_for.c c2_for_023 #2 tfield2 = %s fd2_type = %d\n",tfield2,fd2_type);
printf("c2z_for.c c2_for_023 #3 tfield3 = %s tfield3a = %s fd3_type = %d\n",tfield3,tfield3a,fd3_type);
printf("c2z_for.c #4 tfield4 = %s\n",tfield4);
printf("c2z_for.c #5 tfield5 = %s tfield5a = %s fd5_type = %d\n",tfield5,tfield5a,fd5_type);
printf("c2z_for.c #6 tfield6 = %s tfield6a = %s fd6_type = %d\n",tfield6,tfield6a,fd6_type);
printf("c2z_for.c #7 tfield7 = %s fd7_type = %d\n",tfield7,fd7_type);
*/

  if(fd5_type == 1)
  {
    c_name++;
    snprintf(wk_strg1, sizeof(wk_strg1), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg1);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield5b, c_wkname);
  
    x3 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield5b, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
      }
    }

    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(tfield5b, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      if (global_st == 0) 
      {
        if (gv_ct == 0) 
        {
          size = 1;
          gw_variable = malloc(size * sizeof(struct variables));
        } 
        else 
        {
          size = gv_ct + 1;
          gw_variable = realloc(gw_variable, size * sizeof(struct variables));
        }

        gw_variable[gv_ct].gv_rct = rct;
        strcpy(gw_variable[gv_ct].gv_name, tfield5b);
        strcpy(gw_variable[gv_ct].gv_cname, tfield5b);
        strcpy(gw_variable[gv_ct].gv_type, "I");
        gw_variable[gv_ct].gv_lgth = 0;
        gw_variable[gv_ct].gv_current_lgth = 0;
        strcpy(gw_variable[gv_ct].gv_value, "0");
        gw_variable[gv_ct].gv_init = 0;
        strcpy(gw_variable[gv_ct].gv_literal, null_field);
        gw_variable[gv_ct].gv_use_ct = 0;
        strcpy(gw_variable[gv_ct].gv_dsect, null_field);
        gw_variable[gv_ct].gv_row = 0;
        gw_variable[gv_ct].gv_column = 0;
        strcpy(gw_variable[gv_ct].gv_label, null_field);
        strcpy(gw_variable[gv_ct].gv_table, null_field);
        strcpy(gw_variable[gv_ct].gv_aname, null_field);
        strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
        gw_variable[gv_ct].gv_flag = 0;
        gw_variable[gv_ct].gv_dec = 0;
        gw_variable[gv_ct].gv_id = 1;
        gv_ct++;
      }

      if (global_st == 1) 
      {
        if (lv_ct == 0) 
        {
          size = 1;
          lw_variable = malloc(size * sizeof(struct var));
        } 
        else 
        {
          size = lv_ct + 1;
          lw_variable = realloc(lw_variable, size * sizeof(struct var));
        }

        lw_variable[lv_ct].lv_rct = rct;
        strcpy(lw_variable[lv_ct].lv_cname, tfield5b);
        strcpy(lw_variable[lv_ct].lv_name, tfield5b);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        lw_variable[lv_ct].lv_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, "0");
        lw_variable[lv_ct].lv_use_ct = 0;
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 1;
        lw_variable[lv_ct].lv_init = 0;
        lv_ct++;
      }
    }

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_rct) 
      {
        strcpy(w_for_table[v].for_rt_field5b, tfield5b);
        w_for_table[v].for_type = 1;
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield5b);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield5b);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2302");
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
      strcpy(trace_1, "c2z_for.c #2303");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2304");
      trace_rec_3();
    }

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_rct) 
      {
        strcpy(w_for_table[v].for_rt_field5c, tfield5a);
        w_for_table[v].for_type = 1;
      }
    }
  }

  strcpy(a_string, "         LARL  R9,C370LPCT");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2305");
    trace_rec_3();
  }
  work_use_ct[73]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2306");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2307");
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
    strcpy(trace_1, "c2z_for.c #2308");
    trace_rec_3();
  }

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
      strcpy(trace_1, "c2z_for.c #2309");
      trace_rec_3();
    }
  }

  if (fd2_type == 2) 
  {
    ret = strcmp("0", tfield2);
    if (ret == 0) 
    {
      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2310");
        trace_rec_3();
      }
      x = 1;
      work_use_ct[32]++;
    } 
    else
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2311");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2312");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2313");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2314");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2315");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2316");
        trace_rec_3();
      }
    }
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2317");
    trace_rec_3();
  }
 
  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2318");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2319");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2320");
    trace_rec_3();
  }

  if (for_opr == 1) 
  {
    if (fd1_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */ ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2321");
        trace_rec_3();
      }
    }

    if (fd1_type == 2) 
    {
      printf("\nc2z_for.c c2_for E-66 fd1_type == 2 NOT Coded\n");
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd2_type == 1) 
    {
      printf("\nc2z_for.c c2_for E-67 fd1_type == 1 NOT Coded\n");
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd2_type == 2) 
    {
      x = 0;
      strcpy(a_string, "         LA     R5,");
      strcat(a_string, tfield2);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2322");
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
        strcpy(trace_1, "c2z_for.c #2324");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    ");
    strcat(a_string, tfield1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2425");
      trace_rec_3();
    }

    strcpy(a_string, "         JNE   ");
    strcat(a_string, while_tag);
    strcat(a_string, "E");
  }

  if (for_opr == 2) 
  {
    strcpy(a_string, "         JLE   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
  }

  if (for_opr == 3) 
  {
    printf("\nc2z_for.c c2_for E-68 for_opr == 3 NOT CODED\n");
    printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (for_opr == 4) 
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2326");
      trace_rec_3();
    }

    if (fd3_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2327");
        trace_rec_3();
      }
      strcpy(sv_for_incr, tfield3a);
    }

    if (fd5_type == 2) 
    {
      x = 0;

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield5);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2328");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2329");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2330");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2331");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2332");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2333");
        trace_rec_3();
      }

      x = 1;
    }

    if (fd5_type == 2)
    {
      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2334");
        trace_rec_3();
      }

    }

    if (fd5_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2335");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2336");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2337");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2338");
      trace_rec_3();
    }
  }

  if (for_opr == 5) 
  {

    if (fd3_type == 1)
    {
	printf("\nc2z_for #98  NOT CODED\n");
       printf("c2z_for.c for_opr = %d rct = %d p_string = %s\n",for_opr,rct,p_string);
    }

    if (fd3_type == 2) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2339");
        trace_rec_3();
      }
    }

    if (fd5_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2340");
        trace_rec_3();
      }
    }

    if (fd5_type == 2) 
    {
      x = 0;
      ret = strcmp("0", tfield5);
      if(ret == 0)
      {
        strcpy(tfield5a,"C370ZERO");
        x = 1;
      }

      if(x == 0)
      {
        ret = strcmp("1", tfield5);
        if(ret == 0)
        {
          strcpy(tfield5a,"C370ONE");
          x = 1;
        }
      }

      if(x == 1)
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, tfield5a);
        src_line();
        if (puncde == 1) 
        {
           strcpy(trace_1, "c2z_for.c #2341");
           trace_rec_3();
        }
      }

      strcpy(a_string, "         LA     R5,");
      strcat(a_string, tfield6);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2342");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2343");
      trace_rec_3();
    }

    strcpy(a_string, "         JLL   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2344");
      trace_rec_3();
    }
  }

  strcpy(sv_for_incr, tfield6a);

  if (for_opr == 6)
  {
    if (fd5_type == 2) 
    {
      x = 0;

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield5);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2345");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2346");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2347");
        trace_rec_3();
      }

      if(lp_ct == 0)
      {
        strcpy(a_string, "         LARL  R8,C370NWK5");
        strcpy(tfield20, "C370NWK5");
      }
      if(lp_ct == 1)
      {
        strcpy(a_string, "         LARL  R8,C370NWK4");
        strcpy(tfield20, "C370NWK4");
      }
      lp_ct = lp_ct + 1;

      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2348");
        trace_rec_3();
      }
      work_use_ct[95]++;


      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2349");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2350");
        trace_rec_3();
      }

      x = 1;
    }

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2351");
        trace_rec_3();
      }
    }

    if (fd5_type == 1) 
    {
        if(pi3 == 0)
        {
          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, tfield5a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield5);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2352");
            trace_rec_3();
          }
        }

        if(pi3 == 1)
        {
          strcpy(a_string, "         LAEY  R5,");
          strcat(a_string, tfield7);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield7);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2353");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2354");
            trace_rec_3();
          }

          strcpy(a_string, "         CVD   R5,0(R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2355");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R6,C370NWK5");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2356");
            trace_rec_3();
          }
          work_use_ct[95]++;
          strcpy(tfield20,"C370NWK5");

          strcpy(a_string, "         LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2357");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R6),0(8,R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2358");
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
            strcpy(trace_1, "c2z_for.c #2359");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R7,");
          strcat(a_string, tfield20);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2360");
            trace_rec_3();
          }

          strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2361");
            trace_rec_3();
          }
        }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2362");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield6a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2363");
      trace_rec_3();
    }

    if(fd5_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string,tfield20);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2364");
        trace_rec_3();
      }
    }

    if(fd5_type == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2365");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2366");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2367");
      trace_rec_3();
    }
  }
}



void c2_for_022()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_for.c c2_for_022 START");
    trace_rec_1();
  }

   int pi;
   int pi2;
   int x;
   int x2;
   int x3;
   int x99;
   int I;
   int ret;
   int ret1;
   int ret2;
   int v;
   int fd1_type = 0;
   int fd2_type = 0;
   int fd3_type = 0;
   int fd5_type = 0;

  char *p6;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield5b[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield20[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];

  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  x99 = 0;
  pi2 = 0;
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != '=') 
  {
    if(ch == ';')
    {
      x99 = 1;
      break;
    }
    if (ch != ' ') 
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
    }
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  tfield1a[0] = '\0';
  if(x99 == 0)
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
        ret2 = strcmp(lw_variable[I].lv_type, "I");
        if (ret2 != 0) 
        {
          printf("\nc2z_for.c c2_for_022 E-54 tfield1 Not Numeric %s\n", tfield1);
          printf("c2z_for.c c2_for_022 rct = %d p_string = %s\n", rct, p_string);
          erct++;
          convert = 1;
          return;
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
          ret1 = strcmp(gw_variable[I].gv_type, "I");
          if (ret1 != 0) 
          {
            printf("\nc2z_for.c c2_for_022 E-55 tfield1 Not Numeric %s\n", tfield1);
            printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for_022 E-003 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_for.c c2_for_022 rct = %d p_string = %s\n", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(x99 == 0)
  {
    pi2 = 0;
    x2 = 0;
    fd2_type = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ';') 
    {
      if (ch != ' ') 
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd2_type = 1;
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
            fd2_type = 2;
            x2 = 1;
          }
        }
        tfield2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';
  }

  inside_for = 1;

  if (fd2_type == 1) 
  {
    x3 = 0;
    x2 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        ret2 = strcmp("I", lw_variable[I].lv_type);
        if (ret2 != 0) 
        {
          printf("\nc2z_for.c c2_for_022 E-60 tfield2 Not Numeric %s\n", tfield2);
          printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        break;
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
          ret1 = strcmp(gw_variable[I].gv_type, "I");
          if (ret1 != 0) 
          {
            printf("\nc2z_for.c c2_for_022 E-61 tfield2 Not Numeric %s\n", tfield2);
            printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }
          x3 = 1;
          strcpy(tfield2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for_022 E-62 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  strcpy(sv_for_return, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(sv_for_return, wk_strg);
 
  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  while (ch != ' ') 
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
    if (ch == '<') 
    {
      goto skip_for_1;
    }
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
skip_for_1:
  tfield3[pi2] = '\0';

  x3 = 0;
  x2 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield3, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      ret2 = strcmp("I", lw_variable[I].lv_type);
      if (ret2 != 0) 
      {
        printf("\nc2z_for.c c2_for_022 E-57 tfield3 Not Numeric %s\n", tfield3);
        printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
      x3 = 1;
      strcpy(tfield3a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
      break;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        ret1 = strcmp("I", gw_variable[I].gv_type);
        if (ret1 != 0) {
          printf("\nc2z_for.c c2_for_022 E-58 tfield3 Not Numeric %s\n", tfield3);
          printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
        x3 = 1;
        strcpy(tfield3a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
        break;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_for.c c2_for_022 E-59 tfield3 Not Found = %s\n", tfield3);
    printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
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
  while (ch != ' ') 
  {
    if (ch != ';') 
    {
      tfield4[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

  for_opr = 0;
  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "<=");
    if (p6) 
    {
      for_opr = 6;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, ">=");
    if (p6) 
    {
      for_opr = 5;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "<");
    if (p6) 
    {
      for_opr = 4;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, ">");
    if (p6) 
    {
      for_opr = 3;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "!=");
    if (p6) 
    {
      for_opr = 2;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "==");
    if (p6) 
    {
      for_opr = 1;
    }
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  fd5_type = 0;
  pi2 = 0;
  x2 = 0;
  while (ch != ';') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd5_type = 1;
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
        fd5_type = 2;
        x2 = 1;
      }
    }
    if (ch == ')') 
    {
      break;
    }
    tfield5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield5[pi2] = '\0';
  
  if(fd5_type == 1)
  {
    x3 = 0;
    x2 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield5, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        ret2 = strcmp(lw_variable[I].lv_type, "I");
        if (ret2 != 0) 
        {
          printf("\nc2z_for.c c2_for_022 E-63 tfield5 Not Numeric %s\n", tfield5);
          printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
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
          ret1 = strcmp("I", gw_variable[I].gv_type);
          if (ret1 != 0) 
          {
            printf("\nc2z_for.c c2_for_022 E-64 tfield5 Not Numeric %s\n", tfield5);
            printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }
          x3 = 1;
          strcpy(tfield5a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for_022 E-65 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd5_type == 2)
  {
    tfield5a[0] = '\0';
    tfield5b[0] = '\0';
  }


/*
  pi3 = 0;
  p = strstr(tfield5, "+");
  if(p)
  {
    pi3 = 1;
  }
  p = strstr(tfield5, "-");
  if(p)
  {
    pi3 = 2;
  }
*/

  if (ch == ')') 
  {
    goto skip_for_2;
  }

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
    if (ch == ',') 
    {
      break;
    }

    if (ch == ' ') 
    {
      break;
    }

    if (ch != ' ') 
    {
      if (ch != '+') 
      {
        if (ch != '-') 
        {
          tfield6[pi2] = ch;
          pi2++;
        }
      }
    }
    pi++;
    ch = p_string[pi];
  }
  tfield6[pi2] = '\0';

  x3 = 0;
  x2 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield6, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      ret2 = strcmp(lw_variable[I].lv_type, "I");
      if (ret2 != 0) 
      {
        printf("\nc2z_for.c c2_for_022 E-63 tfield6 Not Numeric %s\n", tfield3);
        printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
      x3 = 1;
      strcpy(tfield6a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield6, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        ret1 = strcmp("I", gw_variable[I].gv_type);
        if (ret1 != 0) 
        {
          printf("\nc2z_for.c c2_for_022 E-64 tfield6 Not Numeric %s\n", tfield6);
          printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }
        x3 = 1;
        strcpy(tfield6a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_for.c c2_for_022 E-65 tfield6 Not Found = %s\n", tfield6);
    printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  v = 0;
  for (v = 0; v < for_ct; v++) 
  {
    if (rct == w_for_table[v].for_rct) 
    {
      strcpy(w_for_table[v].for_rt_field, tfield6a);
      w_for_table[v].for_type = 0;
      strcpy(w_for_table[v].for_rt_field2," ");
      break;
    }
  }

skip_for_2:

/*
if(rct == 718)
{
printf("\nc2z_for.c for_022 rct = %d p_string = %s",rct,p_string);
printf("c2z_for.c for_022 tfield1 = %s tfield1a = %s fd1_type = %d\n",tfield1,tfield1a,fd1_type);
printf("c2z_for.c for_022 tfield2 = %s fd2_type = %d\n",tfield2,fd2_type);
printf("c2z_for.c for_022 tfield3 = %s tfield3a = %s fd3_type = %d\n",tfield3,tfield3a,fd3_type);
printf("c2z_for.c for_022 tfield4 = %s\n",tfield4);
printf("c2z_for.c for_022 tfield5 = %s tfield5a = %s fd5_type = %d\n",tfield5,tfield5a,fd5_type);
printf("c2z_for.c for_022 tfield6 = %s tfield6a = %s\n",tfield6,tfield6a);
}
*/


/*
  if(fd5_type == 2)
  {
printf("c2z_for.c for_022 INSIDE fd5_type = 2\n");
  }
*/


  v = 0;
  for (v = 0; v < for_ct; v++) 
  {
    if (rct == w_for_table[v].for_rct) 
    {
      strcpy(w_for_table[v].for_rt_field5b, tfield5b);
      w_for_table[v].for_type = 0;
      break;
    }
  }


/*
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield5b);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield5b);
    strcat(wk_remark, " ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2200");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield5a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield5);
    strcat(wk_remark, " ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2201");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2202");
      trace_rec_3();
    }
*/

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_rct) 
      {
        strcpy(w_for_table[v].for_rt_field5c, tfield5a);
        w_for_table[v].for_type = 0;
      }
    }

  strcpy(a_string, "         LARL  R9,C370LPCT");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2203");
    trace_rec_3();
  }
  work_use_ct[73]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2204");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2205");
    trace_rec_3();
  }

  if(x99 == 0)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2206");
      trace_rec_3();
    }

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
        strcpy(trace_1, "c2z_for.c #2207");
        trace_rec_3();
      }
    }

    if (fd2_type == 2) 
    {

/*      ret = strcmp("0", tfield2); */
      if (ret == 0) 
      {
/*
        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_for.c #2208");
          trace_rec_3();
        }
        x = 1;
        work_use_ct[32]++;
*/
      } 
      else
      {
        strcpy(a_string, "         LAEY  R5,");
        strcat(a_string, tfield2);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield2);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_for.c #2209");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_for.c #2210");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_for.c #2211");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NCVT");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_for.c #2212");
          trace_rec_3();
        }
        work_use_ct[104]++;

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_for.c #2213");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_for.c #2214");
          trace_rec_3();
        }
      }
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2215");
      trace_rec_3();
    }
  }
 
  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2216");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2217");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2218");
    trace_rec_3();
  }

  if (for_opr == 1) 
  {
    if (fd1_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */ ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2219");
        trace_rec_3();
      }
    }

    if (fd1_type == 2) 
    {
      printf("\nc2z_for.c c2_for_022 E-66 fd1_type == 2 NOT Coded\n");
      printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd2_type == 1) 
    {
      printf("\nc2z_for.c c2_for_022 E-67 fd1_type == 1 NOT Coded\n");
      printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd2_type == 2) 
    {
      x = 0;
      strcpy(a_string, "         LAEY   R5,");
      strcat(a_string, tfield2);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2220");
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
        strcpy(trace_1, "c2z_for.c #2221");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    ");
    strcat(a_string, tfield1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2222");
      trace_rec_3();
    }

    strcpy(a_string, "         JNE   ");
    strcat(a_string, while_tag);
    strcat(a_string, "E");
  }

  if (for_opr == 2) 
  {
    strcpy(a_string, "         JLE   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
  }

  if (for_opr == 3) 
  {
    printf("\nc2z_for.c c2_for_022 E-68 for_opr == 3 NOT CODED\n");
    printf("c2z_for.c c2_for_022 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (for_opr == 4) 
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2223");
      trace_rec_3();
    }

/*
    if (fd3_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2224");
        trace_rec_3();
      }
      strcpy(sv_for_incr, tfield3a);
    }
*/

    if (fd5_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2225");
        trace_rec_3();
      }
      strcpy(sv_for_incr, tfield3a);
    }

    if (fd5_type == 2) 
    {
      x = 0;

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield5);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2226");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2227");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2228");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2229");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2230");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2231");
        trace_rec_3();
      }
      x = 1;
    }

    if (fd5_type == 2)
    {
      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2232");
        trace_rec_3();
      }
    }

    if (fd5_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2233");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2234");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2235");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2236");
      trace_rec_3();
    }
  }

  if (for_opr == 5) 
  {
    if (fd3_type == 1)
    {
	printf("\nc2z_for #2 fd3_type NOT CODED\n");
       printf("c2z_for.c for_opr = %d rct = %d p_string = %s\n",for_opr,rct,p_string);
    }

    if (fd3_type == 2) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2237");
        trace_rec_3();
      }
    }

    if (fd5_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2238");
        trace_rec_3();
      }
    }

    if (fd5_type == 2) 
    {
      x = 0;
      ret = strcmp("0", tfield5);
      if(ret == 0)
      {
        strcpy(tfield5a,"C370ZERO");
        x = 1;
      }

      if(x == 0)
      {
        ret = strcmp("1", tfield5);
        if(ret == 0)
        {
          strcpy(tfield5a,"C370ONE");
          x = 1;
        }
      }

      if(x == 1)
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, tfield5a);
        src_line();
        if (puncde == 1) 
        {
           strcpy(trace_1, "c2z_for.c #2239");
           trace_rec_3();
        }
      }

      strcpy(a_string, "         LA     R5,");
      strcat(a_string, tfield6);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2240");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2241");
      trace_rec_3();
    }

    strcpy(a_string, "         JLL   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2242");
      trace_rec_3();
    }
  }

  strcpy(sv_for_incr, tfield6a);

  if (for_opr == 6)
  {
    if (fd5_type == 2) 
    {
      x = 0;
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield5);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2243");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2244");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2245");
        trace_rec_3();
      }

/*      if(lp_ct == 0)
      {
*/
        strcpy(a_string, "         LARL  R8,C370NWK5");
        strcpy(tfield20, "C370NWK5");
/*
      }
      if(lp_ct == 1)
      {
        strcpy(a_string, "         LARL  R8,C370NWK4");
        strcpy(tfield20, "C370NWK4");
      }
*/

      lp_ct = lp_ct + 1;

      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2246");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2247");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2248");
        trace_rec_3();
      }
      x = 1;
    }

    if(fd3_type == 1)
    {
      strcpy(a_string, "*         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2249");
        trace_rec_3();
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2250");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield6a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2251");
      trace_rec_3();
    }

    if(fd5_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string,tfield20);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2252");
        trace_rec_3();
      }
    }

    if(fd5_type == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2253");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2254");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2255");
      trace_rec_3();
    }
  }

  return;
}



void c2_for_222()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_for.c c2_for_222 START");
    trace_rec_1();
  }

   int pi;
   int pi2;
   int x2;
   int fd1_type;
   int fd3_type;
   int fd4_type;
   int fd5_type;
   int fd7_type;
   int fd8_type;
   int x3;
   int v;
   int I;
   int ret;
   int ret1;
   int operand_1;
   int operand_2;
   int operand_3;
   int y50;
   int y51;

  char ch;
  char *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];
  char field8[VAR_LGTH];
  char field8a[VAR_LGTH];
  char field9[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  fd1_type = 0;
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ' ')
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
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  fd3_type = 0;
  ch = p_string[pi];
  while(ch != ';')
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

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  fd4_type = 0;
  pi2 = 0;
  ch = p_string[pi];
  while(ch != '[')
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd4_type = 1;
        x2 = 1;
      }

      if (isdigit(ch)) 
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

  x2 = 0;
  fd5_type = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd5_type = 1;
        x2 = 1;
      }

      if (isdigit(ch)) 
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
    field6[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field6[pi2] = '\0';

  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  fd7_type = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ';')
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd7_type = 1;
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
        fd7_type = 2;
        x2 = 1;
      }
    }
    field7[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field7[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  fd8_type = 0;
  pi2 = 0;
  ch = p_string[pi];
  while(isalpha(ch))
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd8_type = 1;
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
        fd8_type = 2;
        x2 = 1;
      }
    }
    field8[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field8[pi2] = '\0';

  pi2 = 0;
  ch = p_string[pi];
  while(ch != ')')
  {
    field9[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field9[pi2] = '\0';

/*
printf("\nc2z_for.c case_222 rct = %d p_string = %s",rct,p_string);
printf("c2z_for.c case_222 field1 = %s fd1_type = %d\n",field1,fd1_type);
printf("c2z_for.c case_222 field2 = %s\n",field2);
printf("c2z_for.c case_222 field3 = %s fd3_type = %d\n",field3,fd3_type);
printf("c2z_for.c case_222 field4 = %s fd4_type = %d\n",field4,fd4_type);
printf("c2z_for.c case_222 field5 = %s fd5_type = %d\n",field5,fd5_type);
printf("c2z_for.c case_222 field6 = %s\n",field6);
printf("c2z_for.c case_222 field7 = %s fd7_type = %d\n",field7,fd7_type);
printf("c2z_for.c case_222 field8 = %s fd8_type = %d\n",field8,fd8_type);
printf("c2z_for.c case_222 field9 = %s\n",field9);
*/

  if(fd1_type == 1)
  {
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
      printf("\nc2z_for.c c2_for_222 E-65 field1 Not Found = %s\n", field1);
      printf("c2z_for.c c2_for_222 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  operand_1 = 0;
  if (operand_1 == 0) 
  {
    p = strstr(field2, "==");
    if (p)
    {
      operand_1 = 1;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, "!=");
    if (p)
    {
      operand_1 = 2;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, "<=");
    if (p)
    {
      operand_1 = 3;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, ">=");
    if (p)
    {
      operand_1 = 4;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, "=");
    if (p)
    {
      operand_1 = 5;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, "<");
    if (p)
    {
      operand_1 = 6;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, ">");
    if (p)
    {
      operand_1 = 7;
    }
  }

  x3 = 0;
  if(fd3_type == 1)
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field3, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field3a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
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
           gw_variable[I].gv_use_ct++;
           break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for_222 E-65 field3 Not Found = %s\n", field3);
      printf("c2z_for.c c2_for_222 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd4_type == 1)
  {
    y50 = 0;
    y51 = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field4a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;

        y50 = strcmp(lw_variable[I].lv_type, "I");
        if(y50 == 0)
        {
          y51 = 1;
        }
        y50 = strcmp(lw_variable[I].lv_type, "C");
        if(y50 == 0)
        {
          y51 = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
           x3 = 1;
           strcpy(field4a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
           y50 = strcmp(lw_variable[I].lv_type, "I");
           if(y50 == 0)
           {
             y51 = 1;
           }
           y50 = strcmp(lw_variable[I].lv_type, "C");
           if(y50 == 0)
           {
             y51 = 2;
           }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for_222 E-65 field4 Not Found = %s\n", field4);
      printf("c2z_for.c c2_for_222 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd5_type == 1)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field5, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field5a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        break;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field5, gw_variable[I].gv_name);
        if (ret == 0) 
        {
           x3 = 1;
           strcpy(field5a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
           break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for_222 E-65 field5 Not Found = %s\n", field5);
      printf("c2z_for.c c2_for_222 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  operand_2 = 0;
  if (operand_2 == 0) 
  {
    p = strstr(field6, "==");
    if (p)
    {
      operand_2 = 1;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "!=");
    if (p)
    {
      operand_2 = 2;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "<=");
    if (p)
    {
      operand_2 = 3;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, ">=");
    if (p)
    {
      operand_2 = 4;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "=");
    if (p)
    {
      operand_2 = 5;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "<");
    if (p)
    {
      operand_2 = 6;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, ">");
    if (p)
    {
      operand_2 = 7;
    }
  }

  if(fd7_type == 0)
  {
    printf("c2z_for.c case_222 fd7_type == 0 NOT CODED\n");
    printf("c2z_for.c case_222 rct = %d p_string = %s\n",rct,p_string);
  }

  if(fd7_type == 1)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field7, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field7a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        break;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field7, gw_variable[I].gv_name);
        if (ret == 0) 
        {
           x3 = 1;
           strcpy(field7a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
           break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for_222 E-65 field7 Not Found = %s\n", field7);
      printf("c2z_for.c c2_for_222 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd8_type == 1)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field8, lw_variable[I].lv_name);
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
        ret = strcmp(field8, gw_variable[I].gv_name);
        if (ret == 0) 
        {
           x3 = 1;
           strcpy(field8a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
           break;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for_222 E-65 field8 Not Found = %s\n", field8);
      printf("c2z_for.c c2_for_222 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  operand_3 = 0;
  if (operand_3 == 0) 
  {
    p = strstr(field9, "++");
    if (p)
    {
      operand_3 = 1;
    }
  }

  if (operand_3 == 0) 
  {
    p = strstr(field9, "--");
    if (p)
    {
      operand_3 = 2;
    }
  }

  v = 0;
  for (v = 0; v < for_ct; v++) 
  {
    if (rct == w_for_table[v].for_rct) 
    {
      strcpy(w_for_table[v].for_rt_field, field8a);
      w_for_table[v].for_type = 0;
      break;
    }
  }

  strcpy(a_string, "         LARL  R9,C370LPCT");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #22201");
    trace_rec_3();
  }
  work_use_ct[73]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #22202");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #22203");
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
    strcpy(trace_1, "c2z_for.c #22204");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #22205");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #22206");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #22207");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #22208");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #22209");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcpy(while_tag, a_string);
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #22210");
    trace_rec_3();
  }

  if(y51 == 1)		/* numeric compare condition */ /* for(i = 0; str[i] != '\0'; i++) */
  {
    printf("c2z_for.c case_222 y51 NOT CODED\n");
    printf("c2z_for.c case_222 rct = %d p_string = %s\n",rct,p_string);
  }

  if(y51 == 2)		/* character compare condition */ /* for(i = 0; str[i] != '\0'; i++) */
  {
    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #22211");
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
      strcpy(trace_1, "c2z_for.c #22212");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #22213");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #22214");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVB   R5,0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #22215");
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
      strcpy(trace_1, "c2z_for.c #22216");
      trace_rec_3();
    }

    strcpy(a_string, "         IC    R0,0(R8,(R5))");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #22217");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #22218");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         STC   R0,0(0,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #22219");
      trace_rec_3();
    }
  }

  if(y51 == 1)		/* numeric */
  {
/*
   LARL  R9,C37F6                        I                    
   LARL  R8,C370NCVT                                              
   CP    0(6,R9),0(6,R8)                                          
*/
  }

  if(y51 == 2)		/* character */
  {
    p = strstr(field7, "\0");
    if(p)
    {
      strcpy(a_string, "         LARL  R9,C370L1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #22220");
        trace_rec_3();
      }
      work_use_ct[2]++;

      strcpy(a_string, "         LARL  R8,C370EOF");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #22221");
        trace_rec_3();
      }
      work_use_ct[74]++;

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #22222");
        trace_rec_3();
      }
    }
  }

  if(operand_2 == 1)
  {
    printf("c2z_for.c case_222 operand_2 = 1 NOT CODED\n");
    printf("c2z_for.c case_222 rct = %d p_string = %s\n",rct,p_string);
  }

  if(operand_2 == 2)
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "         JLE   L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #22223");
      trace_rec_3();
    }
  }

  if(operand_2 == 3)
  {
    printf("c2z_for.c case_222 operand_2 = 3 NOT CODED\n");
    printf("c2z_for.c case_222 rct = %d p_string = %s\n",rct,p_string);
  }

  if(operand_2 == 4)
  {
    printf("c2z_for.c case_222 operand_2 = 4 NOT CODED\n");
    printf("c2z_for.c case_222 rct = %d p_string = %s\n",rct,p_string);
  }

  if(operand_2 == 5)
  {
    printf("c2z_for.c case_222 operand_2 = 5 NOT CODED\n");
    printf("c2z_for.c case_222 rct = %d p_string = %s\n",rct,p_string);
  }

  if(operand_2 == 6)
  {
    printf("c2z_for.c case_222 operand_2 = 6 NOT CODED\n");
    printf("c2z_for.c case_222 rct = %d p_string = %s\n",rct,p_string);
  }

  if(operand_2 == 7)
  {
    printf("c2z_for.c case_222 operand_2 = 7 NOT CODED\n");
    printf("c2z_for.c case_222 rct = %d p_string = %s\n",rct,p_string);
  }

  strcpy(w_for_table[v].for_rt_field, field8a);
  strcpy(sv_for_incr, field8a);
}



void c2_for_021()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_for.c c2_for_021 START");
    trace_rec_1();
  }

   int pi;
   int pi2;
   int pi3;
   int pi4;
   int pi5;
   int pi6;
   int x;
   int x2;
   int x3;
   int x10;
   int x11;
   int x20;
   int I;
   int fd1_type = 0;
   int fd2_type = 0;
   int fd3_type = 0;
   int fd5_type = 0;
   int fd6_type = 0;
   int fd7_type = 0;
   int ret;
   int ret1;
   int s;
   int v;
   int size;

  char *p,*p6;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield5b[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];
  char tfield20[VAR_LGTH];
  char wk_strg1[6];

  pi = 0;
  ch = p_string[pi];

  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  x10 = 0;
  p = strstr(p_string, "(;");
  if (p) 
  {
    x10 = 1;
  }

  if (x10 == 0)
  {
    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '=') 
    {
      if (ch != ' ') 
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
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

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
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for E-56 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }


    pi2 = 0;
    x2 = 0;
    fd2_type = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ';') 
    {
      if (ch != ' ') 
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd2_type = 1;
            x2 = 1;
          }

          if (isdigit(ch)) 
          {
            fd2_type = 2;
            x2 = 1;
          }
        }
        tfield2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';
 
    if (fd2_type == 1) 
    {
      x3 = 0;
      x2 = 0;
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
        x3 = 0;
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
        printf("\nc2z_for.c c2_for E-62 tfield2 Not Found = %s\n", tfield2);
        printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }
  }

  inside_for = 1;
  strcpy(sv_for_return, "L");
  strcat(sv_for_return, wk_strg);

  if(x10 == 1)
  {
    tfield1[0] = '\0';
    tfield1a[0] = '\0';
    tfield2[0] = '\0';
    tfield2a[0] = '\0';
  }
 
  /* ************************************************
   * for(; From <= Final; From += Inc)              *
   ************************************************ */
  if (x10 == 1)
  {
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    inside_for = 1;
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  while (ch != ' ') 
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
    if (ch == '<') 
    {
      goto skip_for_1;
    }
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
skip_for_1:
  tfield3[pi2] = '\0';

  x3 = 0;
  x2 = 0;
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
      ret = strcmp(tfield3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield3a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_for.c c2_for_021 E-59 tfield3 Not Found = %s\n", tfield3);
    printf("c2z_for.c c2_for_021 rct = %d p_string = %s", rct, p_string);
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
  while (ch != ' ') 
  {
    if (ch != ';') 
    {
      tfield4[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

  for_opr = 0;
  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "<=");
    if (p6) 
    {
      for_opr = 6;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, ">=");
    if (p6) 
    {
      for_opr = 5;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "<");
    if (p6) 
    {
      for_opr = 4;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, ">");
    if (p6) 
    {
      for_opr = 3;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "!=");
    if (p6) 
    {
      for_opr = 2;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "==");
    if (p6) 
    {
      for_opr = 1;
    }
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  fd5_type = 0;
  pi2 = 0;
  x2 = 0;
  while (ch != ';') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd5_type = 1;
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
        fd5_type = 2;
        x2 = 1;
      }
    }
    if (ch == ')') 
    {
      break;
    }
    tfield5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield5[pi2] = '\0';

  pi3 = 0;
  p = strstr(tfield5, "+");
  if(p)
  {
    pi3 = 1;
  }
  p = strstr(tfield5, "-");
  if(p)
  {
    pi3 = 2;
  }

  if(pi3 != 0)
  {
    pi4 = 0;
    pi5 = 0;
    pi6 = 0;

    strcat(tfield5,";");
    ch = tfield5[pi4];
    while(ch != ' ')
    {
      if(ch == '+')
      {
        pi5 = 1;
        break;
      }
      if(pi5 == 0)
      {
        tfield5a[pi6] = ch;
        pi6++;
        pi4++;
        ch = tfield5[pi4];
      }
    }
    tfield5a[pi6] = '\0';

    pi6 = 0;
    pi4++;
    ch = tfield5[pi4];
    while(ch != ';')
    {
      tfield7[pi6] = ch;
      pi6++;
      pi4++;
      ch = tfield5[pi4];
    }
    tfield7[pi6] = '\0';

    strcpy(tfield5, tfield5a);

/* printf("c2z.for.c case_023 #205 tfield5 = %s tfield5a = %s\n",tfield5,tfield5a); */

  }


  if (fd5_type == 1) 
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
      x3 = 0;
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
      printf("\nc2z_for.c c2_for_023 E-62 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_for.c c2_for_023 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (ch == ')') 
  {
    goto skip_for_2;
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  fd6_type = 0;
  x20 = 0;
  pi2 = 0;
  while (ch != ')') 
  {
    if (ch == ',') 
    {
      x20 = 1;
      break;
    }

    if (ch == ' ') 
    {
      break;
    }

    if (ch != ' ') 
    {
      if (ch != '+') 
      {
        if (ch != '-') 
        {
          if (x2 == 0) 
          {
            if (isalpha(ch)) 
            {
              fd6_type = 1;
              x2 = 1;
            }
            if (isdigit(ch)) 
            {
              fd6_type = 2;
              x2 = 1;
            }
          }
          tfield6[pi2] = ch;
          pi2++;
        }
      }
    }
    pi++;
    ch = p_string[pi];
  }
  tfield6[pi2] = '\0';
  
  if((fd6_type == 0) || (fd6_type == 1) || (fd6_type == 2))
  {
    fd6_type++;
  }

  if (x20 == 1)   /* for(ii=0; ii < count; ii++, left++)  */
  {
    for_2nd_ct = 0;

    pi2 = 0;
    fd7_type = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '+') 
    {
      if(ch != ' ')
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd7_type = 1;
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
            fd7_type = 2;
            x2 = 1;
          }
        }
        tfield7[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield7[pi2] = '\0';

    x3 = 0;
    x2 = 0; 
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield7, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield7a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        for_2nd_ct = 1;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield7, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield7a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          for_2nd_ct = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for E-165 tfield7 Not Found = %s\n", tfield7);
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_rct) 
      {
        strcpy(w_for_table[v].for_rt_field2, tfield7a);
        w_for_table[v].for_type = 1;
      }
    }
  }

  x3 = 0;
  x2 = 0;
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
      ret = strcmp(tfield6, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield6a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_for.c c2_for E-65 tfield6 Not Found = %s\n", tfield6);
    printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  v = 0;
  for (v = 0; v < for_ct; v++) 
  {
    if (rct == w_for_table[v].for_rct) 
    {
      strcpy(w_for_table[v].for_rt_field, tfield6a);
      w_for_table[v].for_type = 1;
    }
  }


skip_for_2:

  x11 = 0;
  p = strstr(p_string, "+=");
  if (p) 
  {
    x11 = 1;
  }

  if (x11 == 1) 
  {
    pi++;
    ch = p_string[pi];
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

    fd7_type = 0;
    pi2 = 0;
    x2 = 0;
   
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd7_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          fd7_type = 2;
          x2 = 1;
        }
      }
      tfield7[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield7[pi2] = '\0';

    x3 = 0;
    if (fd7_type == 1) 
    {
      x2 = 0;
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield7, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield7a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        x3 = 0;
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield7, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield7a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_for.c c2_for E-62 tfield7 Not Found = %s\n", tfield7);
        printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }
  }

/*
printf("\nc2z_for.c #1 rct = %d p_string = %s",rct,p_string);
printf("c2z_for.c #1 tfield1 = %s tfield1a = %s fd1_type = %d\n",tfield1,tfield1a,fd1_type);
printf("c2z_for.c #2 tfield2 = %s fd2_type = %d\n",tfield2,fd2_type);
printf("c2z_for.c #3 tfield3 = %s tfield3a = %s fd3_type = %d\n",tfield3,tfield3a,fd3_type);
printf("c2z_for.c #4 tfield4 = %s\n",tfield4);
printf("c2z_for.c #5 tfield5 = %s tfield5a = %s fd5_type = %d\n",tfield5,tfield5a,fd5_type);
printf("c2z_for.c #6 tfield6 = %s tfield6a = %s fd6_type = %d\n",tfield6,tfield6a,fd6_type);
printf("c2z_for.c #7 tfield7 = %s fd7_type = %d\n",tfield7,fd7_type);
*/

  if(fd5_type == 1)
  {
    c_name++;
    snprintf(wk_strg1, sizeof(wk_strg1), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg1);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield5b, c_wkname);
  
    x3 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield5b, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
      }
    }

    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(tfield5b, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      if (global_st == 0) 
      {
        if (gv_ct == 0) 
        {
          size = 1;
          gw_variable = malloc(size * sizeof(struct variables));
        } 
        else 
        {
          size = gv_ct + 1;
          gw_variable = realloc(gw_variable, size * sizeof(struct variables));
        }

        gw_variable[gv_ct].gv_rct = rct;
        strcpy(gw_variable[gv_ct].gv_name, tfield5b);
        strcpy(gw_variable[gv_ct].gv_cname, tfield5b);
        strcpy(gw_variable[gv_ct].gv_type, "I");
        gw_variable[gv_ct].gv_lgth = 0;
        gw_variable[gv_ct].gv_current_lgth = 0;
        strcpy(gw_variable[gv_ct].gv_value, "0");
        gw_variable[gv_ct].gv_init = 0;
        strcpy(gw_variable[gv_ct].gv_literal, null_field);
        gw_variable[gv_ct].gv_use_ct = 0;
        strcpy(gw_variable[gv_ct].gv_dsect, null_field);
        gw_variable[gv_ct].gv_row = 0;
        gw_variable[gv_ct].gv_column = 0;
        strcpy(gw_variable[gv_ct].gv_label, null_field);
        strcpy(gw_variable[gv_ct].gv_table, null_field);
        strcpy(gw_variable[gv_ct].gv_aname, null_field);
        strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
        gw_variable[gv_ct].gv_flag = 0;
        gw_variable[gv_ct].gv_dec = 0;
        gw_variable[gv_ct].gv_id = 1;
        gv_ct++;
      }

      if (global_st == 1) 
      {
        if (lv_ct == 0) 
        {
          size = 1;
          lw_variable = malloc(size * sizeof(struct var));
        } 
        else 
        {
          size = lv_ct + 1;
          lw_variable = realloc(lw_variable, size * sizeof(struct var));
        }

        lw_variable[lv_ct].lv_rct = rct;
        strcpy(lw_variable[lv_ct].lv_cname, tfield5b);
        strcpy(lw_variable[lv_ct].lv_name, tfield5b);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        lw_variable[lv_ct].lv_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, "0");
        lw_variable[lv_ct].lv_use_ct = 0;
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 1;
        lw_variable[lv_ct].lv_init = 0;
        lv_ct++;
      }
    }

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_rct) 
      {
        strcpy(w_for_table[v].for_rt_field5b, tfield5b);
        w_for_table[v].for_type = 1;
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield5b);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield5b);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2301");
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
      strcpy(trace_1, "c2z_for.c #2302");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2303");
      trace_rec_3();
    }

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_rct) 
      {
        strcpy(w_for_table[v].for_rt_field5c, tfield5a);
        w_for_table[v].for_type = 1;
      }
    }
  }

  strcpy(a_string, "         LARL  R9,C370LPCT");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2304");
    trace_rec_3();
  }
  work_use_ct[73]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2305");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2306");
    trace_rec_3();
  }

  if(fd1_type == 1)
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2307");
      trace_rec_3();
    }
  }

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
      strcpy(trace_1, "c2z_for.c #2308");
      trace_rec_3();
    }
  }

  if (fd2_type == 2) 
  {
    ret = strcmp("0", tfield2);
    if (ret == 0) 
    {
      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2309");
        trace_rec_3();
      }
      x = 1;
      work_use_ct[32]++;
    } 
    else
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2310");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2311");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2312");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2313");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2314");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2315");
        trace_rec_3();
      }
    }
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2316");
    trace_rec_3();
  }
 
  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2317");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2318");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2319");
    trace_rec_3();
  }

  if (for_opr == 1) 
  {
    if (fd1_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */ ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2320");
        trace_rec_3();
      }
    }

    if (fd1_type == 2) 
    {
      printf("\nc2z_for.c c2_for E-66 fd1_type == 2 NOT Coded\n");
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd2_type == 1) 
    {
      printf("\nc2z_for.c c2_for E-67 fd1_type == 1 NOT Coded\n");
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd2_type == 2) 
    {
      x = 0;
      strcpy(a_string, "         LAEY   R5,");
      strcat(a_string, tfield2);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2321");
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
        strcpy(trace_1, "c2z_for.c #2322");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    ");
    strcat(a_string, tfield1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2423");
      trace_rec_3();
    }

    strcpy(a_string, "         JNE   ");
    strcat(a_string, while_tag);
    strcat(a_string, "E");
  }

  if (for_opr == 2) 
  {
    strcpy(a_string, "         JLE   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
  }

  if (for_opr == 3) 
  {
    printf("\nc2z_for.c c2_for E-68 for_opr == 3 NOT CODED\n");
    printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (for_opr == 4) 
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2324");
      trace_rec_3();
    }

    if (fd3_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2325");
        trace_rec_3();
      }
      strcpy(sv_for_incr, tfield3a);
    }

    if (fd5_type == 2) 
    {
      x = 0;

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield5);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2326");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2327");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2328");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2329");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2330");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2331");
        trace_rec_3();
      }

      x = 1;
    }

    if (fd5_type == 2)
    {
      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2332");
        trace_rec_3();
      }

    }

    if (fd5_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2333");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2334");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2335");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2336");
      trace_rec_3();
    }
  }

  if (for_opr == 5) 
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2337");
      trace_rec_3();
    }

    if (fd3_type == 1)
    {
	
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2338");
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
        strcpy(trace_1, "c2z_for.c #2339");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2340");
        trace_rec_3();
      }

      strcpy(a_string, "         JLL   ");
      strcat(a_string, sv_for_return);
      strcat(a_string, "E");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2341");
        trace_rec_3();
      }
    }

    if (fd3_type == 2) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2342");
        trace_rec_3();
      }
    }

/*
    if (fd5_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2343");
        trace_rec_3();
      }
    }
*/

    if (fd5_type == 2) 
    {
      x = 0;
      ret = strcmp("0", tfield5);
      if(ret == 0)
      {
        strcpy(tfield5a,"C370ZERO");
        x = 1;
      }

      if(x == 0)
      {
        ret = strcmp("1", tfield5);
        if(ret == 0)
        {
          strcpy(tfield5a,"C370ONE");
          x = 1;
        }
      }

      if(x == 1)
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, tfield5a);
        src_line();
        if (puncde == 1) 
        {
           strcpy(trace_1, "c2z_for.c #2344");
           trace_rec_3();
        }
      }

      strcpy(a_string, "         LAEY   R5,");
      strcat(a_string, tfield6);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2345");
        trace_rec_3();
      }
    }

/*
    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2346");
      trace_rec_3();
    }

    strcpy(a_string, "         JLL   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2347");
      trace_rec_3();
    }
*/
  }

  strcpy(sv_for_incr, tfield6a);

  if (for_opr == 6)
  {
    if (fd5_type == 2) 
    {
      x = 0;

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield5);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2348");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2349");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2350");
        trace_rec_3();
      }

      if(lp_ct == 0)
      {
        strcpy(a_string, "         LARL  R8,C370NWK5");
        strcpy(tfield20, "C370NWK5");
      }
      if(lp_ct == 1)
      {
        strcpy(a_string, "         LARL  R8,C370NWK4");
        strcpy(tfield20, "C370NWK4");
      }
      lp_ct = lp_ct + 1;

      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2351");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2352");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2353");
        trace_rec_3();
      }

      x = 1;
    }

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2354");
        trace_rec_3();
      }
    }

    if (fd5_type == 1) 
    {
        if(pi3 == 0)
        {
          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, tfield5a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield5);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2355");
            trace_rec_3();
          }
        }

        if(pi3 == 1)
        {
          strcpy(a_string, "         LAEY  R5,");
          strcat(a_string, tfield7);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield7);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2356");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2357");
            trace_rec_3();
          }

          strcpy(a_string, "         CVD   R5,0(R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2358");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R6,C370NWK5");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2359");
            trace_rec_3();
          }
          work_use_ct[95]++;
          strcpy(tfield20,"C370NWK5");

          strcpy(a_string, "         LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2360");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R6),0(8,R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2361");
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
            strcpy(trace_1, "c2z_for.c #2362");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R7,");
          strcat(a_string, tfield20);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2363");
            trace_rec_3();
          }

          strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2364");
            trace_rec_3();
          }
        }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2365");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield6a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2366");
      trace_rec_3();
    }

    if(fd5_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string,tfield20);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2367");
        trace_rec_3();
      }
    }

    if(fd5_type == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2368");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2369");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2370");
      trace_rec_3();
    }
  }
}



void c2_for_024()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_for.c c2_for_024 START");
    trace_rec_1();
  }

   int pi;
   int pi2;
   int pi3;
   int pi4;
   int pi5;
   int pi6;
   int x;
   int x2;
   int x3;
   int x10;
   int x11;
   int x20;
   int I;
   int fd1_type = 0;
   int fd2_type = 0;
   int fd3_type = 0;
   int fd5_type = 0;
   int fd6_type = 0;
   int fd7_type = 0;
   int ret;
   int ret1;
   int s;
   int v;
   int size;

  char *p,*p6;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield5b[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];
  char tfield20[VAR_LGTH];
  char wk_strg1[6];

  pi = 0;
  ch = p_string[pi];

  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  x10 = 0;
  p = strstr(p_string, "(;");
  if (p) 
  {
    x10 = 1;
  }

  if (x10 == 0)
  {
    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '=') 
    {
      if (ch != ' ') 
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
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

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
        ret = strcmp(tfield1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for E-56 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ';') 
    {
      if (ch != ' ') 
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd2_type = 1;
            x2 = 1;
          }

          if (isdigit(ch)) 
          {
            fd2_type = 2;
            x2 = 1;
          }
        }
        tfield2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    inside_for = 1;

 
    if (fd2_type == 1) 
    {
      x3 = 0;
      x2 = 0;
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
        x3 = 0;
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
        printf("\nc2z_for.c c2_for E-62 tfield2 Not Found = %s\n", tfield2);
        printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }
  }

  strcpy(sv_for_return, "L");
  strcat(sv_for_return, wk_strg);
 
  /* ************************************************
   * for(; From <= Final; From += Inc)              *
   ************************************************ */
  if (x10 == 1)
  {
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2301");
      trace_rec_3();
    }

    inside_for = 1;
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  while (ch != ' ') 
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
    if (ch == '<') 
    {
      goto skip_for_1;
    }
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
skip_for_1:
  tfield3[pi2] = '\0';

  x3 = 0;
  x2 = 0;
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
      ret = strcmp(tfield3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield3a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_for.c c2_for E-59 tfield3 Not Found = %s\n", tfield3);
    printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
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
  while (ch != ' ') 
  {
    if (ch != ';') 
    {
      tfield4[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

  for_opr = 0;
  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "<=");
    if (p6) 
    {
      for_opr = 6;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, ">=");
    if (p6) 
    {
      for_opr = 5;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "<");
    if (p6) 
    {
      for_opr = 4;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, ">");
    if (p6) 
    {
      for_opr = 3;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "!=");
    if (p6) 
    {
      for_opr = 2;
    }
  }

  if (for_opr == 0) 
  {
    p6 = strstr(tfield4, "==");
    if (p6) 
    {
      for_opr = 1;
    }
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  fd5_type = 0;
  pi2 = 0;
  x2 = 0;
  while (ch != ';') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd5_type = 1;
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
        fd5_type = 2;
        x2 = 1;
      }
    }
    if (ch == ')') 
    {
      break;
    }
    tfield5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield5[pi2] = '\0';

  pi3 = 0;
  p = strstr(tfield5, "+");
  if(p)
  {
    pi3 = 1;
  }
  p = strstr(tfield5, "-");
  if(p)
  {
    pi3 = 2;
  }

/* printf("c2z_for.c case_023 #201 pi3 = %d tfield5 = %s\n",pi3,tfield5); */
  if(pi3 != 0)
  {
    pi4 = 0;
    pi5 = 0;
    pi6 = 0;

    strcat(tfield5,";");
    ch = tfield5[pi4];
    while(ch != ' ')
    {
      if(ch == '+')
      {
        pi5 = 1;
        break;
      }
      if(pi5 == 0)
      {
        tfield5a[pi6] = ch;
        pi6++;
        pi4++;
        ch = tfield5[pi4];
      }
    }
    tfield5a[pi6] = '\0';
/* printf("c2z_for.c case_023 #202 tfield5a = %s\n",tfield5a); */

    pi6 = 0;
    pi4++;
    ch = tfield5[pi4];
    while(ch != ';')
    {
      tfield7[pi6] = ch;
      pi6++;
      pi4++;
      ch = tfield5[pi4];
    }
    tfield7[pi6] = '\0';

/*
printf("c2z.for.c case_023 #203 tfield7 = %s\n",tfield7);
printf("c2z.for.c case_023 #204 tfield5 = %s tfield5a = %s\n",tfield5,tfield5a);
*/

    strcpy(tfield5, tfield5a);

/* printf("c2z.for.c case_023 #205 tfield5 = %s tfield5a = %s\n",tfield5,tfield5a); */

  }

  if (fd5_type == 1) 
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
      x3 = 0;
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
      printf("\nc2z_for.c c2_for_023 E-62 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_for.c c2_for_023 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (ch == ')') 
  {
    goto skip_for_2;
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  fd6_type = 0;
  x20 = 0;
  pi2 = 0;
  while (ch != ')') 
  {
    if (ch == ',') 
    {
      x20 = 1;
      break;
    }

    if (ch == ' ') 
    {
      break;
    }

    if (ch != ' ') 
    {
      if (ch != '+') 
      {
        if (ch != '-') 
        {
          if (x2 == 0) 
          {
            if (isalpha(ch)) 
            {
              fd6_type = 1;
              x2 = 1;
            }
            if (isdigit(ch)) 
            {
              fd6_type = 2;
              x2 = 1;
            }
          }
          tfield6[pi2] = ch;
          pi2++;
        }
      }
    }
    pi++;
    ch = p_string[pi];
  }
  tfield6[pi2] = '\0';
  
  if((fd6_type == 0) || (fd6_type == 1) || (fd6_type == 2))
  {
    fd6_type++;
  }


  if (x20 == 1)   /* for(ii=0; ii < count; ii++, left++)  */
  {
    for_2nd_ct = 0;

    pi2 = 0;
    fd7_type = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '+') 
    {
      if(ch != ' ')
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd7_type = 1;
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
            fd7_type = 2;
            x2 = 1;
          }
        }
        tfield7[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield7[pi2] = '\0';

    x3 = 0;
    x2 = 0; 
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield7, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield7a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        for_2nd_ct = 1;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield7, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield7a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          for_2nd_ct = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_for.c c2_for E-165 tfield7 Not Found = %s\n", tfield7);
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_rct) 
      {
        strcpy(w_for_table[v].for_rt_field2, tfield7a);
        w_for_table[v].for_type = 1;
      }
    }
  }

  x3 = 0;
  x2 = 0;
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
      ret = strcmp(tfield6, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield6a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_for.c c2_for E-65 tfield6 Not Found = %s\n", tfield6);
    printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  v = 0;
  for (v = 0; v < for_ct; v++) 
  {
    if (rct == w_for_table[v].for_rct) 
    {
      strcpy(w_for_table[v].for_rt_field, tfield6a);
      w_for_table[v].for_type = 1;
    }
  }


skip_for_2:

  x11 = 0;
  p = strstr(p_string, "+=");
  if (p) 
  {
    x11 = 1;
  }

  if (x11 == 1) 
  {
    pi++;
    ch = p_string[pi];
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

    fd7_type = 0;
    pi2 = 0;
    x2 = 0;
   
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd7_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          fd7_type = 2;
          x2 = 1;
        }
      }
      tfield7[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield7[pi2] = '\0';

    x3 = 0;
    if (fd7_type == 1) 
    {
      x2 = 0;
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield7, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield7a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        x3 = 0;
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield7, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield7a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_for.c c2_for E-62 tfield7 Not Found = %s\n", tfield7);
        printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }
  }

/*
printf("\nc2z_for.c #1 rct = %d p_string = %s",rct,p_string);
printf("c2z_for.c #1 tfield1 = %s tfield1a = %s fd1_type = %d\n",tfield1,tfield1a,fd1_type);
printf("c2z_for.c #2 tfield2 = %s fd2_type = %d\n",tfield2,fd2_type);
printf("c2z_for.c #3 tfield3 = %s tfield3a = %s fd3_type = %d\n",tfield3,tfield3a,fd3_type);
printf("c2z_for.c #4 tfield4 = %s\n",tfield4);
printf("c2z_for.c #5 tfield5 = %s tfield5a = %s fd5_type = %d\n",tfield5,tfield5a,fd5_type);
printf("c2z_for.c #6 tfield6 = %s tfield6a = %s fd6_type = %d\n",tfield6,tfield6a,fd6_type);
printf("c2z_for.c #7 tfield7 = %s fd7_type = %d\n",tfield7,fd7_type);
*/

  if(fd5_type == 1)
  {
    c_name++;
    snprintf(wk_strg1, sizeof(wk_strg1), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg1);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(tfield5b, c_wkname);
  
    x3 = 0;
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(tfield5b, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
      }
    }

    if (x3 == 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(tfield5b, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      if (global_st == 0) 
      {
        if (gv_ct == 0) 
        {
          size = 1;
          gw_variable = malloc(size * sizeof(struct variables));
        } 
        else 
        {
          size = gv_ct + 1;
          gw_variable = realloc(gw_variable, size * sizeof(struct variables));
        }

        gw_variable[gv_ct].gv_rct = rct;
        strcpy(gw_variable[gv_ct].gv_name, tfield5b);
        strcpy(gw_variable[gv_ct].gv_cname, tfield5b);
        strcpy(gw_variable[gv_ct].gv_type, "I");
        gw_variable[gv_ct].gv_lgth = 0;
        gw_variable[gv_ct].gv_current_lgth = 0;
        strcpy(gw_variable[gv_ct].gv_value, "0");
        gw_variable[gv_ct].gv_init = 0;
        strcpy(gw_variable[gv_ct].gv_literal, null_field);
        gw_variable[gv_ct].gv_use_ct = 0;
        strcpy(gw_variable[gv_ct].gv_dsect, null_field);
        gw_variable[gv_ct].gv_row = 0;
        gw_variable[gv_ct].gv_column = 0;
        strcpy(gw_variable[gv_ct].gv_label, null_field);
        strcpy(gw_variable[gv_ct].gv_table, null_field);
        strcpy(gw_variable[gv_ct].gv_aname, null_field);
        strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
        gw_variable[gv_ct].gv_flag = 0;
        gw_variable[gv_ct].gv_dec = 0;
        gw_variable[gv_ct].gv_id = 1;
        gv_ct++;
      }

      if (global_st == 1) 
      {
        if (lv_ct == 0) 
        {
          size = 1;
          lw_variable = malloc(size * sizeof(struct var));
        } 
        else 
        {
          size = lv_ct + 1;
          lw_variable = realloc(lw_variable, size * sizeof(struct var));
        }

        lw_variable[lv_ct].lv_rct = rct;
        strcpy(lw_variable[lv_ct].lv_cname, tfield5b);
        strcpy(lw_variable[lv_ct].lv_name, tfield5b);
        strcpy(lw_variable[lv_ct].lv_type, "I");
        lw_variable[lv_ct].lv_lgth = 0;
        strcpy(lw_variable[lv_ct].lv_value, "0");
        lw_variable[lv_ct].lv_use_ct = 0;
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        strcpy(lw_variable[lv_ct].lv_literal, null_field);
        lw_variable[lv_ct].lv_current_lgth = 0;
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 1;
        lw_variable[lv_ct].lv_init = 0;
        lv_ct++;
      }
    }

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_rct) 
      {
        strcpy(w_for_table[v].for_rt_field5b, tfield5b);
        w_for_table[v].for_type = 1;
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield5b);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield5b);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2302");
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
      strcpy(trace_1, "c2z_for.c #2303");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2304");
      trace_rec_3();
    }

    v = 0;
    for (v = 0; v < for_ct; v++) 
    {
      if (rct == w_for_table[v].for_rct) 
      {
        strcpy(w_for_table[v].for_rt_field5c, tfield5a);
        w_for_table[v].for_type = 1;
      }
    }
  }

  strcpy(a_string, "         LARL  R9,C370LPCT");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2305");
    trace_rec_3();
  }
  work_use_ct[73]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2306");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2307");
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
    strcpy(trace_1, "c2z_for.c #2308");
    trace_rec_3();
  }

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
      strcpy(trace_1, "c2z_for.c #2309");
      trace_rec_3();
    }
  }

  if (fd2_type == 2) 
  {
    ret = strcmp("0", tfield2);
    if (ret == 0) 
    {
      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2310");
        trace_rec_3();
      }
      x = 1;
      work_use_ct[32]++;
    } 
    else
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2311");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2312");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2313");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2314");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2315");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2316");
        trace_rec_3();
      }
    }
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2317");
    trace_rec_3();
  }
 
  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2318");
    trace_rec_3();
  }
  work_use_ct[78]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2319");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_for.c #2320");
    trace_rec_3();
  }

  if (for_opr == 1) 
  {
    if (fd1_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */ ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2321");
        trace_rec_3();
      }
    }

    if (fd1_type == 2) 
    {
      printf("\nc2z_for.c c2_for E-66 fd1_type == 2 NOT Coded\n");
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd2_type == 1) 
    {
      printf("\nc2z_for.c c2_for E-67 fd1_type == 1 NOT Coded\n");
      printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (fd2_type == 2) 
    {
      x = 0;
      strcpy(a_string, "         LA     R5,");
      strcat(a_string, tfield2);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2322");
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
        strcpy(trace_1, "c2z_for.c #2324");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    ");
    strcat(a_string, tfield1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2425");
      trace_rec_3();
    }

    strcpy(a_string, "         JNE   ");
    strcat(a_string, while_tag);
    strcat(a_string, "E");
  }

  if (for_opr == 2) 
  {
    strcpy(a_string, "         JLE   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
  }

  if (for_opr == 3) 
  {
    printf("\nc2z_for.c c2_for E-68 for_opr == 3 NOT CODED\n");
    printf("c2z_for.c c2_for rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (for_opr == 4) 
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2326");
      trace_rec_3();
    }

    if (fd3_type == 1) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2327");
        trace_rec_3();
      }
      strcpy(sv_for_incr, tfield3a);
    }

    if (fd5_type == 2) 
    {
      x = 0;

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield5);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2328");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2329");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2330");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2331");
        trace_rec_3();
      }
      work_use_ct[104]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2332");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2333");
        trace_rec_3();
      }

      x = 1;
    }

    if (fd5_type == 2)
    {
      strcpy(a_string, "         LARL  R8,C370NCVT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2334");
        trace_rec_3();
      }

    }

    if (fd5_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2335");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2336");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2337");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2338");
      trace_rec_3();
    }
  }

  if (for_opr == 5) 
  {

    if (fd3_type == 1)
    {
	printf("c2z_for fd3_type NOT CODED\n");
    }

    if (fd3_type == 2) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2339");
        trace_rec_3();
      }
    }

    if (fd5_type == 1) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2340");
        trace_rec_3();
      }
    }

    if (fd5_type == 2) 
    {
      x = 0;
      ret = strcmp("0", tfield5);
      if(ret == 0)
      {
        strcpy(tfield5a,"C370ZERO");
        x = 1;
      }

      if(x == 0)
      {
        ret = strcmp("1", tfield5);
        if(ret == 0)
        {
          strcpy(tfield5a,"C370ONE");
          x = 1;
        }
      }

      if(x == 1)
      {
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, tfield5a);
        src_line();
        if (puncde == 1) 
        {
           strcpy(trace_1, "c2z_for.c #2341");
           trace_rec_3();
        }
      }

      strcpy(a_string, "         LA     R5,");
      strcat(a_string, tfield6);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2342");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2343");
      trace_rec_3();
    }

    strcpy(a_string, "         JLL   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2344");
      trace_rec_3();
    }
  }

  strcpy(sv_for_incr, tfield6a);

  if (for_opr == 6)
  {
    if (fd5_type == 2) 
    {
      x = 0;

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield5);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2345");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2346");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2347");
        trace_rec_3();
      }

      if(lp_ct == 0)
      {
        strcpy(a_string, "         LARL  R8,C370NWK5");
        strcpy(tfield20, "C370NWK5");
      }
      if(lp_ct == 1)
      {
        strcpy(a_string, "         LARL  R8,C370NWK4");
        strcpy(tfield20, "C370NWK4");
      }
      lp_ct = lp_ct + 1;

      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2348");
        trace_rec_3();
      }
      work_use_ct[95]++;


      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2349");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2350");
        trace_rec_3();
      }

      x = 1;
    }

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2351");
        trace_rec_3();
      }
    }

    if (fd5_type == 1) 
    {
        if(pi3 == 0)
        {
          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, tfield5a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield5);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2352");
            trace_rec_3();
          }
        }

        if(pi3 == 1)
        {
          strcpy(a_string, "         LAEY  R5,");
          strcat(a_string, tfield7);
          strcpy(wk_remark, " ");
          strcat(wk_remark, tfield7);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2353");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2354");
            trace_rec_3();
          }

          strcpy(a_string, "         CVD   R5,0(R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2355");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R6,C370NWK5");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2356");
            trace_rec_3();
          }
          work_use_ct[95]++;
          strcpy(tfield20,"C370NWK5");

          strcpy(a_string, "         LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2357");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R6),0(8,R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2358");
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
            strcpy(trace_1, "c2z_for.c #2359");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R7,");
          strcat(a_string, tfield20);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2360");
            trace_rec_3();
          }

          strcpy(a_string, "         AP    0(6,R8),0(6,R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_for.c #2361");
            trace_rec_3();
          }
        }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(while_tag, a_string);
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2362");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield6a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield6);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2363");
      trace_rec_3();
    }

    if(fd5_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string,tfield20);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2364");
        trace_rec_3();
      }
    }

    if(fd5_type == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_for.c #2365");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2366");
      trace_rec_3();
    }

    strcpy(a_string, "         JLH   ");
    strcat(a_string, sv_for_return);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_for.c #2367");
      trace_rec_3();
    }
  }
}


