/* ***************************************************
*  c2z : c2z_mem.c :                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out MEMCPY                                  *
* ************************************************** */
void c2_memcpy(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_mem.c c2_memcpy");
    trace_rec_1();
  }

  char ch;
  char *p1;
  char tfield1[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield3[VAR_LGTH];

  int pi;
  int pi2;
  int x = 0;
  int x1 = 0;
  int x4 = 0;
  int I = 0;
  int ret = 0;

  p1 = strstr(p_string, "+");

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

  pi++;
  ch = p_string[pi];
  pi2 = 0;
  while (ch != ',') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  x = 0;
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(tfield1, gw_variable[I].gv_name);
    if (ret == 0) 
    {
      x4 = gw_variable[I].gv_lgth;
      x1 = strcmp(gw_variable[I].gv_type, "C");
      if (x1 != 0) 
      {
        printf("c2z_mem.c c2_memcpy tfield1 Not Character = %s\n", tfield1);
        printf("c2z_mem.c c2_memcpy rct = %d p_string = %s", rct, p_string);
        c2_debug();
        exit(1);
      }
      if (x1 == 0)
      {
        x = 1;
      }
    }
  }

  if (x == 0) 
  {
    printf("c2z_mem.c c2_memcpy tfield1 Not Found = %s\n", tfield1);
    printf("c2z_mem.c c2_memcpy rct = %d p_string = %s", rct, p_string);
    c2_debug();
    exit(1);
  }

  if (!p1) 
  {
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while (ch != ',') 
    {
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

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while (ch != ')') 
    {

      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_mem.c c2_memcpy #1");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, tfield1);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
    strcat(a_string, wk_strg);
    strcat(a_string, "),=CL");
    strcat(a_string, wk_strg);
    strcat(a_string, "' '");
    strcpy(wk_remark, " memcpy   */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_mem.c c2_memcpy #2");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, tfield1);
    strcat(a_string, "(");
    strcat(a_string, tfield3);
    strcat(a_string, "),");
    strcat(a_string, tfield2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_mem.c c2_memcpy #3");
      trace_rec_3();
    }

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_mem.c c2_memcpy #4");
      trace_rec_3();
    }
  }

  if (p1) 
  {
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

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while (ch != ',') 
    {
      if (ch != '_') 
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    x = 0;
    x4 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0)
      {
        x4 = gw_variable[I].gv_lgth;
        x1 = strcmp(gw_variable[I].gv_type, "C");
        if (x1 != 0) 
        {
          printf("c2z_mem.c c2_memcpy tfield1 Not Character = %s\n", tfield1);
          printf("c2z_mem.c c2_memcpy rct = %d p_string = %s", rct, p_string);
          c2_debug();
          exit(1);
        }
        if (x1 == 0)
        {
          x = 1;
        }
      }
    }

    if (x == 0) 
    {
      printf("c2z_mem.c c2_memcpy tfield1 Not Found = %s\n", tfield1);
      printf("c2z_mem.c c2_memcpy rct = %d p_string = %s", rct, p_string);
      c2_debug();
      exit(1);
    }

    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while (ch != ',') 
    {
      if (ch != '_') 
      {
        tfield2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while (ch != ')') 
    {
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_mem.c c2_memcpy #5");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, tfield1);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
    strcat(a_string, wk_strg);
    strcat(a_string, "),=CL");
    strcat(a_string, wk_strg);
    strcat(a_string, "' '");
    strcat(a_string, "' '");
    strcpy(wk_remark, " memcpy   */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_mem.c c2_memcpy #6");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, tfield1);
    strcat(a_string, "(");
    strcat(a_string, tfield3);
    strcat(a_string, "),");
    strcat(a_string, tfield2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_mem.c c2_memcpy #7");
      trace_rec_3();
    }

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_mem.c c2_memcpy #8");
      trace_rec_3();
    }
  }
}

/* ***************************************************
*  Punch out                                         *
* ************************************************** */
void c2_memmove(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_mem.c c2_memmove");
    trace_rec_1();
  }

  char ch;
  char *p1;

  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];

  int pi;
  int pi2;
  int x = 0;
  int x1 = 0;
  int x4 = 0;
  int I = 0;
  int ret = 0;

  p1 = strstr(p_string, "+");

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

  pi++;
  ch = p_string[pi];
  pi2 = 0;
  while (ch != ',') 
  {
    if (ch != '_') 
    {
      field1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  x = 0;
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(field1, gw_variable[I].gv_name);
    if (ret == 0) 
    {
      x4 = gw_variable[I].gv_lgth;
      x1 = strcmp(gw_variable[I].gv_type, "C");
      if (x1 != 0) 
      {
        printf("c2z_mem.c c2_memmove field1 Not Character = %s\n", field1);
        printf("c2z_mem.c c2_memmove rct = %d p_string = %s", rct, p_string);
        c2_debug();
        exit(1);
      }
      if (x1 == 0)
      {
        x = 1;
      }
    }
  }

  if (x == 0) 
  {
    printf("c2z_mem.c c2_memmove field1 Not Found = %s\n", field1);
    printf("c2z_mem.c c2_memmove rct = %d p_string = %s", rct, p_string);
    c2_debug();
    exit(1);
  }

  if (!p1) 
  {
    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while (ch != ',') 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    while (ch != ',')
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while (ch != ')') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1)
      trace_rec_3();

    strcpy(a_string, "         MVC   ");
    strcat(a_string, field1);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
    strcat(a_string, wk_strg);
    strcat(a_string, "),=CL");
    strcat(a_string, wk_strg);
    strcat(a_string, "' '");
    strcpy(wk_remark, " memmove  */");
    write_remark();
    if (puncde == 1)
      trace_rec_3();

    strcpy(a_string, "         MVC   ");
    strcat(a_string, field1);
    strcat(a_string, "(");
    strcat(a_string, field3);
    strcat(a_string, "),");
    strcat(a_string, field2);
    src_line();
    if (puncde == 1)
      trace_rec_3();

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1)
      trace_rec_3();
  }

  if (p1) 
  {
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

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while (ch != ',') 
    {
      if (ch != '_') 
      {
        field1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    x = 0;
    x4 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x4 = gw_variable[I].gv_lgth;
        x1 = strcmp(gw_variable[I].gv_type, "C");
        if (x1 != 0) 
        {
          printf("c2z_mem.c c2_memmove field1 Not Character = %s\n", field1);
          printf("c2z_mem.c c2_memmove rct = %d p_string = %s", rct, p_string);
          c2_debug();
          exit(1);
        }
        if (x1 == 0)
        {
          x = 1;
        }
      }
    }

    if (x == 0) 
    {
      printf("c2z_mem.c c2_memmove field1 Not Found = %s\n", field1);
      printf("c2z_mem.c c2_memmove rct = %d p_string = %s", rct, p_string);
      c2_debug();
      exit(1);
    }

    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while (ch != ',') 
    {
      if (ch != '_') 
      {
        field2[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    while (ch != ',') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while (ch != ')') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1)
      trace_rec_3();

    strcpy(a_string, "         MVC   ");
    strcat(a_string, field1);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
    strcat(a_string, wk_strg);
    strcat(a_string, "),=CL");
    strcat(a_string, wk_strg);
    strcat(a_string, "' '");
    strcpy(wk_remark, " memmove  */");
    write_remark();
    if (puncde == 1)
      trace_rec_3();

    strcpy(a_string, "         MVC   ");
    strcat(a_string, field1);
    strcat(a_string, "(");
    strcat(a_string, field3);
    strcat(a_string, "),");
    strcat(a_string, field2);
    src_line();
    if (puncde == 1)
      trace_rec_3();

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1)
      trace_rec_3();
  }
}
