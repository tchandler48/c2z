/* ***************************************************
*  c2z : c2z_case.c :                                *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out CASE statement                          *
* ************************************************** */
void c2_case(void) 
{
  if_case = 0;

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_case.c c2_case START");
    trace_rec_1();
  }

  char ch;
  char *p1;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  int fd1_type = 0;
  int pi;
  int pi2;
  int x = 0;
  int x80 = 0;
  int x81 = 0;
  int I = 0;
  int ret;

  field1a[0] = '\0';

  if_case = 1;
  pi = 0;
  ch = p_string[pi];
  p1 = strstr(p_string, "{");
  if (p1) 
  {
    while (ch != '{') 
    {
      pi++;
      ch = p_string[pi];
    }
    pi++;
    ch = p_string[pi];
  }

  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  fd1_type = 0;
  x = 0;
  while (ch != ':') 
  {
    if (ch == '\'') 
    {
      x = 2;
      fd1_type = 0;
    }
    if ((isdigit(ch)) && (x == 0)) 
    {
      fd1_type = 1;
      x = 1;
    }
    if ((isalpha(ch)) && (x == 0)) 
    {
      fd1_type = 2;
      x = 1;
    }

    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  if (fd1_type == 1) 				/* literal  */
  {
    strcpy(save_case_break, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(save_case_break, wk_strg);
    strcat(save_case_break, "E");

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, sw_field);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_case.c #1");
      trace_rec_3();
    }

    x80 = 0;

    if(x80 == 1)
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_case.c #2");
        trace_rec_3();
      }
    }

    x81 = 0;

    if(x80 == 0)
    {
      ret = strcmp("-1", field1);
      if(ret == 0)
      {  
        x81 = 1;
      }

      if(x81 == 1)
      {
        strcpy(a_string, "         LARL  R7,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_case.c #3");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R6,C370NONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_case.c #4");
          trace_rec_3();
        }
        work_use_ct[82]++;

        strcpy(a_string, "         ZAP   0(6,R7),0(6,R6)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_case.c #5");
          trace_rec_3();
        }
        work_use_ct[81]++;
      }
  
      if(x81 == 0)
      {
        strcpy(a_string, "         LAEY  R5,");
        strcat(a_string, field1);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_case.c #6");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_case.c #7");
          trace_rec_3();
        }
        work_use_ct[48]++;
  
        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_case.c #8");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_case.c #9");
          trace_rec_3();
        }
        work_use_ct[49]++;

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_case.c #10");
          trace_rec_3();
        }
        work_use_ct[48]++;

        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_case.c #11");
          trace_rec_3();
        }
      }
    }

    strcpy(a_string, "         CP    ");
    strcat(a_string, "0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_case.c #12");
      trace_rec_3();
    }

    strcpy(a_string, "         JNE   ");
    strcat(a_string, save_case_break);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_case.c #13");
      trace_rec_3();
    }
  }

  if (fd1_type == 2) /*variable  */
  {
    strcpy(save_case_break, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(save_case_break, wk_strg);
    strcat(save_case_break, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_case.c #14");
      trace_rec_3();
    }
  }

  if (fd1_type == 0) /* special character  */
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_case.c c2_case fd1_type == 0");
      trace_rec_1();
    }

    strcpy(save_case_break, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(save_case_break, wk_strg);
    strcat(save_case_break, "E");

    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(field1, w_charlit[I].clit_cname);
        /* x3 = w_charlit[I].clit_lgth; */
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, sw_field);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_case.c #15");
      trace_rec_3();
    }

    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(field1, w_charlit[I].clit_cname);
        /* x3 = w_charlit[I].clit_lgth; */
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field1);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_case.c #16");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   ");
    strcat(a_string, "0(1,R8),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_case.c #17");
      trace_rec_3();
    }

    strcpy(a_string, "         JLNE  ");
    strcat(a_string, save_case_break);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_case.c #18");
      trace_rec_3();
    }
  }
}



