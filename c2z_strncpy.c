/* ***************************************************
*  c2z : c2z_strncpy.c :                             *
*                                                    *
*  next error - strncpy-004                          *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* ***************************************************
*  Punch out STRNCPY                                 *
* ************************************************** */
void c2_strncpy(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strncpy.c c2_strncpy");
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

  int pi;
  int pi2;
  int x = 0;
  int x1 = 0;
  int x2 = 0;
  int x3 = 0;
/*  int x4 = 0; */
  int I = 0;
  int ret = 0;
  int s = 0;
  int x30 = 0;
  int x31 = 0;
/*  int fd1_type = 0; */
/*  int fd2_type = 0; */
  int fd3_type = 0;
/*  int fd4_type = 0; */

  tot_strncpy++;

  x30 = 0;
  x31 = 0;
  s = strlen(p_string);
  for(I= 0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '[')
    {
      x30++;
    }
    if(ch == ']')
    {
      x30++;
    }
    if(ch == '(')
    {
      x31++;
    }
    if(ch == ')')
    {
      x31++;
    }
  }

  if((x30 == 2) && (x31 == 2))
  {
    pi = 0;
    ch = p_string[pi];

    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi++;
    ch = p_string[pi];
    pi2 = 0;
/*    fd1_type = 0; */
    while (ch != ',') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
/*          fd1_type = 1; */
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
/*          fd1_type = 2; */
          x2 = 1;
        }
      }
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x1 = 0;
 /*   x4 = 0; */
    x = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(field1a, gw_variable[I].gv_cname);
     /*   x4 = gw_variable[I].gv_lgth; */
        x1 = strcmp(gw_variable[I].gv_type, "C");
        x = 1;
      }
    }

    if(x == 0)
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        if (ret == 0) 
        {
          strcpy(field1a, lw_variable[I].lv_cname);
    /*      x4 = lw_variable[I].lv_lgth; */
          x1 = strcmp(lw_variable[I].lv_type, "C");
        }
      }
    }

    if (x1 != 0) 
    {
      printf("\nc2z_strncpy.c c2_strncpy strncpy-002 field1 Not Character = %s\n", field1);
      printf("c2z_strncpy.c c2_strncpy rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if (x == 0) 
    {
      printf("\nc2z_strncpy.c c2_strncpy strncpy-001 field1 Not Found = %s\n", field1);
      printf("c2z_strncpy.c c2_strncpy rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    x2 = 0;
/*    fd2_type = 0; */
    while (ch != '[') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
     /*     fd2_type = 1; */
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
    /*      fd2_type = 2; */
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
    pi2 = 0;
    x2 = 0;
    fd3_type = 0;
    while (ch != ']') 
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
    while(ch != ',')
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    x2 = 0;
/*    fd4_type = 0; */
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
  /*        fd4_type = 1; */
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
 /*         fd4_type = 2; */
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
    if (gv_ct > 0) 
    {
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
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strncpy.c c2_strncpy strncpy-002 field2 Not Found = %s\n", field2);
      printf("c2z_strncpy.c c2_strncpy rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
/*    x4 = 0; */
    x = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(field3a, gw_variable[I].gv_cname);
 /*       x4 = gw_variable[I].gv_lgth; */
        x3 = 1;
      }
    }

    if(x3 == 0)
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        if (ret == 0) 
        {
          strcpy(field3a, lw_variable[I].lv_cname);
 /*         x4 = lw_variable[I].lv_lgth; */
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strncpy.c c2_strncpy strncpy-003 field3 Not Found = %s\n", field3);
      printf("c2z_strncpy.c c2_strncpy rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
/*    x4 = 0; */
    x = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field4, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(field4a, gw_variable[I].gv_cname);
      /*  x4 = gw_variable[I].gv_lgth; */
        x3 = 1;
      }
    }

    if(x3 == 0)
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field4, lw_variable[I].lv_name);
        if (ret == 0) 
        {
          strcpy(field4a, lw_variable[I].lv_cname);
     /*     x4 = lw_variable[I].lv_lgth; */
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strncpy.c c2_strncpy strncpy-004 field4 Not Found = %s\n", field4);
      printf("c2z_strncpy.c c2_strncpy rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #2");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */ ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #4");
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
      strcpy(trace_1, "c2z_strncpy.c #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */ ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #7");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #8");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #11");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #12");
      trace_rec_3();
    }

    strcat(field2,"L");
    strcpy(a_string, "         LA    R6,");
    strcat(a_string, field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #13");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #14");
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
      strcpy(trace_1, "c2z_strncpy.c #15");
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
      strcpy(trace_1, "c2z_strncpy.c #21");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */ ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #22");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R8");
    strcat(a_string, ",R9),0(R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #2");
      trace_rec_3();
    }
    convert = 1;
    return;
  }

 
  if((x31 == 2) && (x30 == 0))
  {
    pi = 0;
    ch = p_string[pi];

    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi++;
    ch = p_string[pi];
    pi2 = 0;
/*    fd1_type = 0; */
    while (ch != ',') 
    {
      if (ch != ' ')
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
     /*       fd1_type = 1; */
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
    /*        fd1_type = 2; */
            x2 = 1;
          }
        }
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    x2 = 0;
/*    fd2_type = 0; */
    while (ch != ',') 
    {
      if (ch != ' ')
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
     /*       fd2_type = 1; */
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
    /*        fd2_type = 2; */
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

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    x2 = 0;
    fd3_type = 0;
    while (ch != ')') 
    {
      if (ch != ' ')
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
      }
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    x3 = 0;
 /*   x4 = 0; */
    x = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(field1a, gw_variable[I].gv_cname);
     /*   x4 = gw_variable[I].gv_lgth; */
        x3 = 1;
      }
    }

    if(x3 == 0)
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field1, lw_variable[I].lv_name);
        if (ret == 0) 
        {
          strcpy(field1a, lw_variable[I].lv_cname);
     /*     x4 = lw_variable[I].lv_lgth; */
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strncpy.c c2_strncpy strncpy-104 field1 Not Found = %s\n", field1);
      printf("c2z_strncpy.c c2_strncpy rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
/*    x4 = 0; */
    x = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(field2a, gw_variable[I].gv_cname);
     /*   x4 = gw_variable[I].gv_lgth; */
        x3 = 1;
      }
    }

    if(x3 == 0)
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        if (ret == 0) 
        {
          strcpy(field2a, lw_variable[I].lv_cname);
   /*       x4 = lw_variable[I].lv_lgth; */
          x3 = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_strncpy.c c2_strncpy strncpy-105 field2 Not Found = %s\n", field2);
      printf("c2z_strncpy.c c2_strncpy rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if(fd3_type == 1)
    {
      x3 = 0;
  /*    x4 = 0; */
      x = 0;
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field3, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(field3a, gw_variable[I].gv_cname);
     /*     x4 = gw_variable[I].gv_lgth; */
          x3 = 1;
        }
      }

      if(x3 == 0)
      {
        for (I = 0; I < lv_ct; I++) 
        {
          ret = strcmp(field3, lw_variable[I].lv_name);
          if (ret == 0) 
          {
            strcpy(field3a, lw_variable[I].lv_cname);
     /*       x4 = lw_variable[I].lv_lgth; */
            x3 = 1;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_strncpy.c c2_strncpy strncpy-106 field3 Not Found = %s\n", field3);
        printf("c2z_strncpy.c c2_strncpy rct = %d p_string = %s\n",rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LARL  R7,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */ ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strncpy.c #100");
        trace_rec_3();
      }
    }

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field3);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strncpy.c #100");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strncpy.c #100");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strncpy.c #100");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strncpy.c #100");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strncpy.c #100");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strncpy.c #100");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strncpy.c #100");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */ ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #100");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */ ");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #101");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R7");
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #103");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #100");
      trace_rec_3();
    }

    if(fd3_type == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field3);
      strcat(wk_remark, " */ ");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strncpy.c #101");
        trace_rec_3();
      }
    }

    if(fd3_type == 2)
    {
      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_strncpy.c #101");
        trace_rec_3();
      }
    }

    strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #101");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #100");
      trace_rec_3();
    }

    strcpy(a_string, "         CVB   R2,0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #100");
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
      strcpy(trace_1, "c2z_strncpy.c #101");
      trace_rec_3();
    }

    strcpy(a_string, "         LR    R1,R9");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #100");
      trace_rec_3();
    }

    strcpy(a_string, "         AR    R1,R2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #100");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370EOF");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #100");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R9,R1),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #100");
      trace_rec_3();
    }

    convert = 1;
    return;
  }
}
