/* ***************************************************
*  c2z : c2z_strcmp.c :                              *
*                                                    *
*  next error - strcmp-018                           *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out STRCMP                                  *
* ************************************************** */
void c2_strcmp() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp");
    trace_rec_1();
  }

  char ch;

  int pi;
  int scmp_1 = 0;
  int scmp_2 = 0;
  int scmp_4 = 0;
  int scmp_5 = 0;
  int I = 0;
  int s = 0;

  s = strlen(p_string);
  pi = 0;
  scmp_1 = 0;
  scmp_2 = 0;

  int L1 = 0;
  int R1 = 0;
  ch = p_string[pi];
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == ',') 
    {
      scmp_4 = I;
    }
    if ((ch != '=') && (scmp_2 != 1) && (scmp_1 != 1)) 
    {
      if (ch == '[') 
      {
        L1 = 1;
        scmp_2 = 1;
      }
    }

    if (ch == '=') 
    {
      scmp_1 = 1;
    }

    if ((scmp_1 == 1) && (ch != ';')) 
    {
      if (ch == '[') 
      {
        R1 = 1;
        scmp_5 = I;
      }
    }
  }

  if ((L1 == 0) && (R1 == 0)) 				/*  x = strcmp(field1,field2)		*/
  {
    c2_strcmp_1();
  }

  if ((L1 == 0) && (R1 == 1) && (scmp_4 < scmp_5)) 	/*  x = strcmp(field1,field2[xx])		*/
  {
    c2_strcmp_2();
  }

  if ((L1 == 0) && (R1 == 1) && (scmp_4 > scmp_5)) 	/* xtest = strcmp(array2[pi],gtl_holder	*/
  {
    c2_strcmp_3();
  }
}

void c2_strcmp_1() 						/*  x = strcmp(field1,field2)		*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1");
    trace_rec_1();
  }

  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];

  int pi;
  int pi2;
  int x = 0;
  int x1 = 0;
  int x2 = 0;
  int x9 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
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

  x = 0;
  x2 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
      x1 = strcmp(lw_variable[I].lv_type, "I");
      if (x1 != 0) 
      {
        printf("c2z_strcmp.c c2_strcmp_1 E-533 tfield1 Not Numeric = %s\n",tfield1);
        printf("c2z_strcmp.c c2_strcmp_1 rct = %d p_string = %s", rct,p_string);
        c2_debug();
        exit(1);
      }
    }
  }

  if (x == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x = 1;
        strcpy(tfield1a, gw_variable[I].gv_cname);
        x1 = strcmp(gw_variable[I].gv_type, "I");
        if (x1 != 0) 
        {
          printf("c2z_strcmp.c c2_strcmp_1 E-534 tfield1 Not Numeric = %s\n",tfield1);
          printf("c2z_strcmp.c c2_strcmp_1 rct = %d p_string = %s", rct,p_string);
          c2_debug();
          exit(1);
        }
      }
    }
  }

  if (x == 0) 
  {
    printf("\nc2z_strcmp.c c2_strcmp_1 strcmp-005 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_strcmp.c c2_strcmp_1 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
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
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  x = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield2, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x = 1;
      strcpy(tfield2a, lw_variable[I].lv_cname);
      x9 = lw_variable[I].lv_current_lgth;
      x1 = strcmp("C", lw_variable[I].lv_type);
      if (x1 != 0) 
      {
        printf("\nc2z_strcmp.c c2_strcmp_1 strcmp-006 tfield2 Not Character = %s\n",tfield2);
        printf("c2z_strcmp.c c2_strcmp_1 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }
  }

  if (x == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(tfield2a, gw_variable[I].gv_cname);
        x = 1;
        x1 = strcmp("C", gw_variable[I].gv_type);
        x9 = gw_variable[I].gv_current_lgth;
        if (x1 != 0) 
        {
          printf("\nc2z_strcmp.c c2_strcmp_1 strcmp-007 tfield2 Not Character = %s\n",tfield2);
          printf("c2z_strcmp.c c2_strcmp_1 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }
      }
    }
  }

  if (x == 0) 
  {
    printf("\nc2z_strcmp.c c2_strcmp_1 strcmp-008 tfield2 Not Found = %s\n", tfield2);
    printf("c2z_strcmp.c c2_strcmp_1 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi2 = 0;
  pi++;
  x2 = 0;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (ch != '"') 
    {
      if (ch != ' ') 
      {
        tfield3[pi2] = ch;
        pi2++;
      }
    } 
    else 
    {
      x2 = 1;
    }
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  if (x2 != 1) 
  {
    x = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield3, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x = 1;
        strcpy(tfield3a, lw_variable[I].lv_cname);
        x1 = strcmp("C", lw_variable[I].lv_type);
        if (x1 != 0) 
        {
          printf("\nc2z_strcmp.c c2_strcmp_1 strcmp-009 tfield3 Not Character = %s\n",tfield3);
          printf("c2z_strcmp.c c2_strcmp_1 rct = %d p_string = %s", rct,p_string);
          erct++;
          convert = 1;
          return;
        }
      }
    }

    if (x == 0) 
    {
      for (I = 0; I < gv_ct; I++) {
        ret = strcmp(tfield3, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          strcpy(tfield3a, gw_variable[I].gv_cname);
          x = 1;
          x1 = strcmp("C", gw_variable[I].gv_type);
          if (x1 != 0) 
          {
            printf("c2z_strcmp.c c2_strcmp_1 E-540 tfield3 Not Character = %s\n",tfield3);
            printf("c2z_strcmp.c c2_strcmp_1 rct = %d p_string = %s", rct, p_string);
            c2_debug();
            exit(1);
          }
        }
      }
    }

    if (x == 0) 
    {
      printf("\nc2z_strcmp.c c2_strcmp_1 strcmp-010 tfield3 Not Found = %s\n", tfield3);
      printf("c2z_strcmp.c c2_strcmp_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  loop_strcmp++;

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield2a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield2);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #1");
    trace_rec_3();
  }

  if (x2 == 0) 
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #2");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CLC   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x9);
  strcat(a_string, "0(");
  strcat(a_string, wk_strg);
  strcat(a_string, ",R9)");
  strcat(a_string, ",0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #3");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ");
  strcat(a_string, "CMP");
  snprintf(wk_strg, sizeof(wk_strg), "%d", loop_strcmp);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #4");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   ");
  strcat(a_string, "CMP");
  snprintf(wk_strg, sizeof(wk_strg), "%d", loop_strcmp);
  strcat(a_string, wk_strg);
  strcat(a_string, "H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #5");
    trace_rec_3();
  }

  strcpy(a_string, "         JLL   ");
  strcat(a_string, "CMP");
  snprintf(wk_strg, sizeof(wk_strg), "%d", loop_strcmp);
  strcat(a_string, wk_strg);
  strcat(a_string, "L");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #6");
    trace_rec_3();
  }

  strcpy(a_string, "CMP");
  snprintf(wk_strg, sizeof(wk_strg), "%d", loop_strcmp);
  strcat(a_string, wk_strg);
  strcat(a_string, "E");
  strcat(a_string, "    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #7");
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
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #9");
    trace_rec_3();
  }
  work_use_ct[32]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #10");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "END");
  snprintf(wk_strg, sizeof(wk_strg), "%d", loop_strcmp);
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #11");
    trace_rec_3();
  }

  strcpy(a_string, "CMP");
  snprintf(wk_strg, sizeof(wk_strg), "%d", loop_strcmp);
  strcat(a_string, wk_strg);
  strcat(a_string, "H");
  strcat(a_string, "    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #12");
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
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #14");
    trace_rec_3();
  }
  work_use_ct[33]++;

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #15");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  strcat(a_string, "END");
  snprintf(wk_strg, sizeof(wk_strg), "%d", loop_strcmp);
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #16");
    trace_rec_3();
  }

  strcpy(a_string, "CMP");
  snprintf(wk_strg, sizeof(wk_strg), "%d", loop_strcmp);
  strcat(a_string, wk_strg);
  strcat(a_string, "L");
  strcat(a_string, "    DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #17");
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
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #18");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,NULL");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #19");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #20");
    trace_rec_3();
  }

  strcpy(a_string, "END");
  snprintf(wk_strg, sizeof(wk_strg), "%d", loop_strcmp);
  strcat(a_string, wk_strg);
  strcat(a_string, "     DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_1 #19");
    trace_rec_3();
  }
}

void c2_strcmp_2() 					/*  x = strcmp(field1,field2[xx])		*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2");
    trace_rec_1();
  }

   int pi;
   int x2;
   int pi2;
   int fd1_type;
   int fd2_type;
   int fd3_type;
   int fd4_type;
   int I;
   int ret;
   int ret1;
   int x1;
   int x50;

  char ch;
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
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field11[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    if (x2 == 0) 
    {
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

  pi++;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
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

  x2 = 0;
  pi2 = 0;
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

  x2 = 0;
  pi2 = 0;
  while (ch != ']') 
  {
    if(ch != '[')
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
    }
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';

  if ((fd1_type == 2) && (fd2_type == 2)) 
  {
    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcmp.c c2_strcmp_2 strcmp-012 field1 Not Found = %s\n", field1);
      printf("c2z_strcmp.c c2_strcmp_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        strcpy(field2b, lw_variable[I].lv_type);
        x50 = lw_variable[I].lv_current_lgth;
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
          strcpy(field2a, gw_variable[I].gv_cname);
          strcpy(field2b, gw_variable[I].gv_type);
          x50 = gw_variable[I].gv_current_lgth;

        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcmp.c c2_strcmp_2 strcmp-013 field2 Not Found = %s\n", field2);
      printf("c2z_strcmp.c c2_strcmp_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  x1 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field3, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x1 = 1;
      strcpy(field3a, lw_variable[I].lv_cname);
    }
  }

  if (x1 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x1 = 1;
        strcpy(field3a, gw_variable[I].gv_cname);
      }
    }
  }
  
  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field3a, gw_variable[I].gv_cname);
      if (ret == 0) 
      {
          strcpy(field5, gw_variable[I].gv_dsect);
          strcpy(field6, gw_variable[I].gv_label);
          strcpy(field7, gw_variable[I].gv_table);
          strcpy(field8, gw_variable[I].gv_aname);
          strcpy(field9, gw_variable[I].gv_sv_reg);
          strcpy(field10, gw_variable[I].gv_wk_reg);
          strcpy(field11, gw_variable[I].gv_wk_strg);
          gw_variable[I].gv_flag = 1;
      }
    }
  }

  if (fd4_type == 2) 
  {
    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field4a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(field4a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcmp.c c2_strcmp_2 strcmp-015 field4 Not Found = %s\n", field4);
      printf("c2z_strcmp.c c2_strcmp_2 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

   array_clear = 1;

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #2");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #3");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #4");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #6");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #7");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #7A");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #7B");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #7C");
      trace_rec_3();
    }

    strcpy(a_string, "         JLNE  L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "D");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #7D");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(2,R9),0(R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #9");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "Z");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #9A");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #10A");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #11");
      trace_rec_3();
    }
    work_use_ct[50]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #12");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #13");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #14");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #15");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #16");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #18");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #19");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_2 #19A");
      trace_rec_3();
    }

    while_array = 1;
    strcpy(while_array_name, field10);
    strcpy(while_array_table, field7);

    convert = 1;
    x50 = 1;
 
}

void c2_strcmp_3() 					/* xtest = strcmp(array2[pi],gtl_holder	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3");
    trace_rec_1();
  }

  char ch;
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
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field11[VAR_LGTH];
  char field11a[VAR_LGTH];

  int pi;
  int pi2;
  int x1 = 0;
  int x2 = 0;
  int x50 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int fd1_type = 0;
  int fd2_type = 0;
  int fd3_type = 0;
  int fd4_type = 0;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    if (x2 == 0) 
    {
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

  pi++;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != '[') 
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
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch != ',') 
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
  while (ch != ')') 
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

  if ((fd1_type == 2) && (fd2_type == 2) && (fd3_type == 2) && (fd4_type == 2)) 
  {
    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field1, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcmp.c c2_strcmp_3 strcmp-012 field1 Not Found = %s\n", field1);
      printf("c2z_strcmp.c c2_strcmp_3 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        strcpy(field2b, lw_variable[I].lv_type);
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
          strcpy(field2a, gw_variable[I].gv_cname);
          strcpy(field2b, gw_variable[I].gv_type);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcmp.c c2_strcmp_3 strcmp-013 field2 Not Found = %s\n", field2);
      printf("c2z_strcmp.c c2_strcmp_3 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field3, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field3a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field3, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(field3a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcmp.c c2_strcmp_3 strcmp-014 field3 Not Found = %s\n", field3);
      printf("c2z_strcmp.c c2_strcmp_3 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field4a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(field4a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcmp.c c2_strcmp_3 strcmp-015 field4 Not Found = %s\n", field4);
      printf("c2z_strcmp.c c2_strcmp_3 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2a, gw_variable[I].gv_cname);
        if (ret == 0) 
        {
          strcpy(field5, gw_variable[I].gv_dsect);
          strcpy(field6, gw_variable[I].gv_label);
          strcpy(field7, gw_variable[I].gv_table);
          strcpy(field8, gw_variable[I].gv_aname);
          strcpy(field9, gw_variable[I].gv_sv_reg);
          strcpy(field10, gw_variable[I].gv_wk_reg);
          strcpy(field11, gw_variable[I].gv_wk_strg);
          gw_variable[I].gv_flag = 1;
        }
      }
    }

    x1 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field11, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x1 = 1;
        strcpy(field11a, lw_variable[I].lv_cname);
      }
    }

    if (x1 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field11, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x1 = 1;
          strcpy(field11a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x1 == 0) 
    {
      printf("\nc2z_strcmp.c c2_strcmp_3 strcmp-016 field4 Not Found = %s\n", field4);
      printf("c2z_strcmp.c c2_strcmp_3 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    array_clear = 1;

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #4");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #5");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #6");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #7");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #11");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #12");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #13");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #14");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #15");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #16");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field4a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #18");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(5,R6),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #19");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "G");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #20");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    strcat(a_string, sv_while);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #21");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #22");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #23");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #24");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #25");
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
      strcpy(trace_1, "c2z_strcmp.c c2_strcmp_3 #26");
      trace_rec_3();
    }

    while_array = 1;
    strcpy(while_array_name, field10);
    strcpy(while_array_table, field7);

    convert = 1;
    x50 = 1;
  }

  if (x50 == 0) 
  {
    printf("\nc2z_strcmp.c c2_strcmp_3 strcmp-017 Option Not Coded\n");
    printf("c2z_strcmp.c c2_strcmp_3 fd1_type = %d\n", fd1_type);
    printf("c2z_strcmp.c c2_strcmp_3 fd2_type = %d\n", fd2_type);
    printf("c2z_strcmp.c c2_strcmp_3 fd3_type = %d\n", fd3_type);
    printf("c2z_strcmp.c c2_strcmp_3 fd4_type = %d\n", fd4_type);
    printf("c2z_strcmp.c c2_strcmp_3 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }
}
