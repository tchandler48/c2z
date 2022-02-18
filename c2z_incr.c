/* ***************************************************
*  c2z : c2z_incr.c :                                *
*                                                    *
*  next error - incr-002                             *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch ++ statement                                *
* ************************************************** */
void c2_plus() 
{

  char ch;

  int I = 0;
  int s;
  int x90 = 0;
  int x98 = 0;
  int bracket_ct = 0;

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];

    if (ch == '(') 
    {
      x98++;
    }

    if (ch == ')') 
    {
      x98++;
    }

    if (ch == '[') 
    {
      bracket_ct++;
    }

    if (ch == ']')
    {
      bracket_ct++;
    }

    if(ch == '.')
    {
      x90++;
    }
  }

  if((bracket_ct == 0) && (x90 == 0) && (x98 == 0))
  {
    c2_plus_00();
    convert = 1;
    return;
  }

  if((bracket_ct == 2) && (x90 == 0) && (x98 == 0))
  {
    c2_plus_01();
    convert = 1;
    return;
  }

  if((bracket_ct == 4) && (x90 == 0) && (x98 == 0))
  {
    c2_plus_04();
    convert = 1;
    return;
  }

  if((bracket_ct == 2) && (x90 == 1) && (x98 == 0))
  {
    c2_plus_05();
    convert = 1;
    return;
  }


printf("\nc2z_incr.c NO MATCH\n");
printf("\nc2z_incr.c rct = %d p_string = %s",rct,p_string);
printf("c2z_incr.c []      bracket_ct = %d\n",bracket_ct);
printf("c2z_incr.c .       x90 = %d\n",x90);
printf("c2z_incr.c ()      x98 = %d\n",x98);

}


void c2_plus_00()  
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.incr.c plus_00 START");
    trace_rec_1();
  }

  char ch;
  char *p;
  char *p1;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];

  int pi;
  int pi2;
  int pl1 = 0;
  int pl3 = 0;
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
  while (ch != '+') 
  {
    if(ch == '+')
    {
      break;
    }
    if(ch == '-')
    {
      break;
    }
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
  while(ch != ';')
  {
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  pl1 = 0;
  pl3 = 0;
  if (lv_ct > 0) 
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        pl1 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        lw_variable[I].lv_current_lgth++;
      }
    }
  }

  if (pl1 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        pl3 = strcmp(field1, gw_variable[I].gv_name);
        if (pl3 == 0) 
        {
          pl1 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          gw_variable[I].gv_current_lgth++;
        }
      }
    }
  }

  if (pl1 == 0) 
  {
    printf("\nc2z_incr.c c2_plus incr-001 field1 Not Found = %s sv_func = %s\n", field1,sv_func);
    printf("c2z_incr.c c2_plus rct = %d p_string = %s", rct, p_string);
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
    strcpy(trace_1, "c2z_incr.c #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #2");
    trace_rec_3();
  }
  work_use_ct[33]++;

  p = strstr(field2, "++");
  if(p)
  {
    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #3");
      trace_rec_3();
    }
  }

  p1 = strstr(field2, "--");
  if(p1)
  { 
    strcpy(a_string, "         SP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #4");
      trace_rec_3();
    }
  }
}


void c2_plus_01()		/*  int array[x]++;	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.incr.c plus_01 START");
    trace_rec_1();
  }

  char ch;
  char *p;
  char *p1;
 
  char tfield1[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield8[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield11[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int x2 = 0;
  int fd2_type = 0;
  int ret = 0;
  int ret1 = 0;
  int x3;

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

  pi++;
  pi2 = 0;
  ch = p_string[pi];
  while(ch != ';')
  {
    tfield3[pi2] = ch;
    pi2++;
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
      printf("\nc2z_incr.c c2_incr_01 if-002 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_incr.c c2_incr_01 rct = %d p_string = %s", rct, p_string);
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
    strcpy(trace_1, "c2z_incr_c #100");
    trace_rec_3();
  }
  work_use_ct[49]++;

  
  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #101");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #102");
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
      strcpy(trace_1, "c2z_incr.c #103");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #104");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #105");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", for_loop_ct);
    strcpy(a_string, "         LARL  R9,C370R");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #106");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #107");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #108");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, tfield7);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #109");
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
    strcpy(trace_1, "c2z_incr.c #110");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr_c #111");
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
      strcpy(trace_1, "c2z_incr.c #112");
      trace_rec_3();
    }
  }

  if (fd2_type == 1) 			/* variable */
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #113");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #114");
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
    strcpy(trace_1, "c2z_incr.c #115");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr_c #116");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #117");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #118");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, tfield6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #119");
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
    strcpy(trace_1, "c2z_incr.c #120");
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
    strcpy(trace_1, "c2z_incr.c #121");
    trace_rec_3();
  }

  p = strstr(tfield3, "++");
  if(p)
  {
    strcpy(a_string, "         LARL  R9,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #122");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         AP    0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #123");
      trace_rec_3();
    }
  }

  p1 = strstr(tfield3, "--");
  if(p1)
  {
    strcpy(a_string, "         LARL  R9,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #124");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         SP    0(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #125");
      trace_rec_3();
    }
  }
}



void c2_plus_04()  
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.incr.c plus_04 START");
    trace_rec_1();
  }

  char ch;
  char *p;
  char *p1;
 
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
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

  int pi;
  int pi2;
  int I = 0;
  int x2 = 0;
  int fd2_type = 0;
  int fd3_type = 0;
  int ret = 0;
  int ret1 = 0;
  int x3;
  int x102;

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

  pi++;
  pi++;
  fd3_type = 0;
  pi2 = 0;
  x2 = 0;
  ch = p_string[pi];
  while(ch != ']')
  {
    if (x2 == 0) 
    {
      if ((isdigit(ch)) && (x2 == 0)) 
      {
        fd3_type = 2;
        x2 = 1;
      }
      if ((isalpha(ch)) && (x2 == 0)) 
      {
        fd3_type = 1;
        x2 = 1;
      }
    }
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ';')
  {
    tfield4[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

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
      printf("\nc2z_incr.c c2_incr_01 if-002 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_incr.c c2_incr_01 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd3_type == 1)
  {
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
      printf("\nc2z_incr.c c2_incr_01 if-002 tfield3 Not Found = %s\n", tfield3);
      printf("c2z_incr.c c2_incr_01 rct = %d p_string = %s", rct, p_string);
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

/*
printf("\nc2z_incr.c c2_plus_04 rct = %d p_string = %s",rct,p_string);
printf("c2z_incr.c c2_plus_04 tfield1 = %s\n",tfield1);
printf("c2z_incr.c c2_plus_04 tfield2 = %s fd2_type = %d\n",tfield2,fd2_type);
printf("c2z_incr.c c2_plus_04 tfield3 = %s fd3_type = %d\n",tfield3,fd3_type);
printf("c2z_incr.c c2_plus_04 tfield4 = %s\n",tfield4);
*/

/*  find displacement in array  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #4000");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #4001");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #4002");
      trace_rec_3();
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4003");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4004");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4005");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4006");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4007");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4008");
        trace_rec_3();
      }
    }

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield2a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4009");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #4010");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #4011");
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
      strcpy(trace_1, "c2z_incr.c #4012");
      trace_rec_3();
    }

/* ROW IS ZERO, SO JUST ADD COLUMNS THEN BRANCH OUT */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #4013");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4014");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4015");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4016");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4017");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4018");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4019");
        trace_rec_3();
      }
    }

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #4020");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #4021");
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
      strcpy(trace_1, "c2z_incr.c #4022");
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
      strcpy(trace_1, "c2z_incr.c #4023");
      trace_rec_3();
    }

    if(fd2_type == 2)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield2);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield2);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4024");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4025");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4026");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4027");
        trace_rec_3();
      }
      work_use_ct[49]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4028");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4029");
        trace_rec_3();
      }
    }

    if(fd2_type == 1)
    {
      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4030");
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
        strcpy(trace_1, "c2z_incr.c #4031");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_incr.c #4032");
        trace_rec_3();
      }
    }

     if (gv_ct > 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(tfield1, gw_variable[I].gv_name);
         if (ret == 0) 
         {
           x2 = 1;
           strcpy(tfield1a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
           strcpy(tfield5, gw_variable[I].gv_dsect);
           strcpy(tfield6, gw_variable[I].gv_label);
           strcpy(tfield7, gw_variable[I].gv_table);
           strcpy(tfield8, gw_variable[I].gv_aname);
           strcpy(tfield9, gw_variable[I].gv_sv_reg);
           strcpy(tfield10, gw_variable[I].gv_wk_reg);
           strcpy(tfield11, gw_variable[I].gv_wk_strg);
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
         strcpy(trace_1, "c2z_incr.c #4033");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R7,C370U");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_incr.c #4034");
         trace_rec_3();
       }
       work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4035");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4036");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4037");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4038");
      trace_rec_3();
    }
  

/*  C370NWK2 CONTAINS 26 TO MULTIPLY BY VALUE OF ROW  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4039");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4040");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         MP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4041");
      trace_rec_3();
    }

/* C370NWK1 CONTAINS 26 * NUMBER OF ROWS  */

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4042");
      trace_rec_3();
    }
    work_use_ct[49]++;

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield3);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #4043");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #4044");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #4045");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK5");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #4046");
        trace_rec_3();
      }
      work_use_ct[95]++;

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #4047");
        trace_rec_3();
      }
      work_use_ct[48]++;

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #4048");
        trace_rec_3();
      }
    }

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #4049");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4050");
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
      strcpy(trace_1, "c2z_math.c #4051");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4052");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4053");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4054");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, tfield7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4055");
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
      strcpy(trace_1, "c2z_math.c #4056");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4057");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4058");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4059");
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
      strcpy(trace_1, "c2z_math.c #4060");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4061");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4062");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4063");
      trace_rec_3();
    }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, tfield6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math.c #4064");
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
    strcpy(trace_1, "c2z_math.c #4065");
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
    strcpy(trace_1, "c2z_math.c #4066");
    trace_rec_3();
  }

    strcpy(a_string, "         LARL  R9,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_math.c #4067");
      trace_rec_3();
    }
    work_use_ct[33]++;

    p = strstr(tfield4, "++");
    if(p)
    {
      strcpy(a_string, "         AP    0(6,R6),0(6,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #4068");
        trace_rec_3();
      }
    }

    p1 = strstr(tfield4, "--");
    if(p1)
    {
      strcpy(a_string, "         SP    0(6,R6),0(6,R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_math.c #4069");
        trace_rec_3();
      }
    }
}

void c2_plus_05()  
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.incr.c plus_05 START");
    trace_rec_1();
  }

  char ch;
  char *p;
  char *p1;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];
  char tfield8[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield11[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int x2 = 0;
  int x80 = 0;
  int fd2_type = 0;
  int m5fd5_type = 0;
  int ret = 0;
  int ret1 = 0;
  int x3;

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

  pi++;
  pi++;
  pi2 = 0;
  x2 = 0;
  ch = p_string[pi];
  while(ch != ';')
  {
    if(ch == '+')
    {
      break;
    }
    if(ch == '-')
    {
      break;
    }
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  pi2 = 0;
  ch = p_string[pi];
  while(ch != ';')
  {
    tfield4[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0';

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
      printf("\nc2z_incr.c c2_incr_01 if-002 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_incr.c c2_incr_01 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
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
    printf("\nc2z_math.c c2z_math_501 Structure math-029 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_math.c c2_math_501 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
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

/*
printf("\nc2z_incr.c c2_plus_04 rct = %d p_string = %s",rct,p_string);
printf("c2z_incr.c c2_plus_05 tfield1 = %s tfield1a = %s\n",tfield1,tfield1a);
printf("c2z_incr.c c2_plus_05 tfield2 = %s fd2_type = %d\n",tfield2,fd2_type);
printf("c2z_incr.c c2_plus_05 tfield3 = %s\n",tfield3);
printf("c2z_incr.c c2_plus_05 tfield4 = %s\n",tfield4);
printf("c2z_incr.c c2_plus_05 tfield6a = %s\n",tfield6a);
printf("c2z_incr.c c2_plus_05 tfield7a = %s\n",tfield7a);
*/

  if (fd2_type == 2)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5000");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5001");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5002");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5003");
      trace_rec_3();
    }
    work_use_ct[78]++;

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5004");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5005");
      trace_rec_3();
    }
    strcpy(tfield5a,"C370NWK3");
  }

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
      printf("\nc2z_incr.c c2_incr_05 incr-033 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_incr.c c2_incr_05 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #5006");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #5007");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #5008");
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
    strcpy(trace_1, "c2z_incr.c #5009");
    trace_rec_3();
  }

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5010");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5011");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         CVD   R5,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5012");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5013");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5014");
      trace_rec_3();
    }
    work_use_ct[48]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5015");
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
    strcpy(trace_1, "c2z_incr.c #5016");
    trace_rec_3();
  }


  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #5017");
    trace_rec_3();
  }
  work_use_ct[49]++;

  if(fd2_type == 1)
  {
    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5018");
      trace_rec_3();
    }
    work_use_ct[50]++;
  }

  if(fd2_type == 2)
  {
    strcpy(a_string, "         LARL  R8,C370NWK3");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5019");
      trace_rec_3();
    }
    work_use_ct[78]++;
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #5020");
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
    strcpy(trace_1, "c2z_incr.c #5021");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #5022");
    trace_rec_3();
  }
  work_use_ct[49]++;

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #5023");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #5024");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, tfield1a);
  strcat(a_string, "L");
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_incr.c #5025");
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
    strcpy(trace_1, "c2z_incr.c #5026");
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
    strcpy(trace_1, "c2z_incr.c #5027");
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
    printf("/nc2z_incr.c c2z_incr_05 incr-034 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_incr.c c2z_incr_05 tfield3 Not Found = %s\n",tfield3);
    printf("c2z_incr.c c2_incr_05 rct = %d p_string = %s", rct, p_string);
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
      strcpy(trace_1, "c2z_incr.c #5028");
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
      strcpy(trace_1, "c2z_incr.c #5029");
      trace_rec_3();
    }
  }

  p = strstr(tfield4, "++");
  if(p)
  {
    strcpy(a_string, "         LARL  R9,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5030");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
    strcat(a_string, wk_strg);
    strcat(a_string, "(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5031");
      trace_rec_3();
    }
  }

  p1 = strstr(tfield4, "--");
  if(p1)
  {
    strcpy(a_string, "         LARL  R9,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5032");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         SP    ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x80);
    strcat(a_string, wk_strg);
    strcat(a_string, "(6,R6),0(6,R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_incr.c #5033");
      trace_rec_3();
    }
  }
}


