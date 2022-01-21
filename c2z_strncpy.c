/* ***************************************************
*  c2z : c2z_strncpy.c :                             *
*                                                    *
*  next error - strncpy-004                          *
*  Copyright TCCS (c) 2015 - 2022                    *
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

  tot_strncpy++;

  p1 = strstr(p_string, "+");

  if (!p1) 
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t')) 
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
      field1[pi2] = ch;
      pi2++;
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
          printf("c2z_strncpy.c c2_strncpy E-521 field1 Not Character = %s",field1);
          c2_error();
        }
        if (x1 == 0)
        {
          x = 1;
        }
      }
    }

    if (x == 0) 
    {
      printf("\nc2z_strncpy.c c2_strncpy strncpy-001 field1 Not Found = %s", field1);
      printf("c2z_strncpy.c c2_strncpy rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
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
    {
      strcpy(trace_1, "c2z_strncpy.c c2_strncpy #1");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, field1);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
    strcat(a_string, wk_strg);
    strcat(a_string, "),=CL");
    strcat(a_string, wk_strg);
    strcat(a_string, "' '");
    strcpy(wk_remark, " strncpy  */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #1");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, field1);
    strcat(a_string, "(");
    strcat(a_string, field3);
    strcat(a_string, "),");
    strcat(a_string, field2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #2");
      trace_rec_3();
    }

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #3");
      trace_rec_3();
    }
  }

  if (p1) 
  {
    pi = 0;
    ch = p_string[pi];
    while ((ch == ' ') || (ch == '\t')) 
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
      field1[pi2] = ch;
      pi2++;
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
          printf("c2z_strncpy.c c2_strncpy strncpy-002 field1 Not Character = %s",field1);
          printf("c2z_strncpy.c c2_strncpy rct = %d p_string = %s\n",rct,p_string);
          erct++;
          convert = 1;
          return;
        }
        if (x1 == 0)
        {
          x = 1;
        }
      }
    }

    if (x == 0) 
    {
      printf("c2z_strncpy.c c2_strncpy strncpy-003 field1 Not Found = %s", field1);
      printf("c2z_strncpy.c c2_strncpy rct = %d p_string = %s\n",rct,p_string);
      erct++;
      convert = 1;
      return;
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
    {
      strcpy(trace_1, "c2z_strncpy.c #4");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, field1);
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x4);
    strcat(a_string, wk_strg);
    strcat(a_string, "),=CL");
    strcat(a_string, wk_strg);
    strcat(a_string, "' '");
    strcpy(wk_remark, " strncpy  */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #5");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   ");
    strcat(a_string, field1);
    strcat(a_string, "(");
    strcat(a_string, field3);
    strcat(a_string, "),");
    strcat(a_string, field2);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #6");
      trace_rec_3();
    }

    strcpy(a_string, "*");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_strncpy.c #7");
      trace_rec_3();
    }
  }
}
