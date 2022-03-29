/* ***************************************************
*  c2z : c2z_goto.c                                  *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out goto statement                          *
* ************************************************** */
void c2_goto() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_goto.c c2_goto");
    trace_rec_1();
  }

  char ch;

  int pi;
  int pi2;
  int x3;
  int I;
  int ret;

  pi = 0;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch == '\t') 
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

  pi2 = 0;
  while (ch != ';') 
  {
    wk_string[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  wk_string[pi2] = '\0';

  x3 = 0;
  for(I = 0; I < goto_label_ct; I++)
  {
    ret = strcmp(w_goto_label[I].goto_org_lb, wk_string);
    if(ret == 0)
    {
      strcpy(wk_strg, w_goto_label[I].goto_label_1);
      x3 = 1;
    }
  }

  if(x3 == 0)
  {
    printf("\nc2z_goto.c c2_goto_label-001 Label Not Foundr\n");
    printf("c2z_goto.c rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }
 
  strcpy(a_string, "         JLU   ");
  strcat(a_string, wk_strg);
  strcpy(wk_remark, " goto     */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_goto.c #1");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_goto.c #2");
    trace_rec_3();
  }

  convert = 1;
}

/* **************************************************
*  Punch out goto label statement                   *
* ************************************************* */
void c2_goto_label() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_goto.c c2_goto_label");
    trace_rec_1();
  }

  char ch;

  int pi;
  int pi2;
  int I;
  int x3;
  int ret;

  pi = 0;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch == '\t') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ':') 
  {
    wk_string[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  wk_string[pi2] = '\0';

  x3 = 0;
  for(I = 0; I < goto_label_ct; I++)
  {
    ret = strcmp(w_goto_label[I].goto_org_lb, wk_string);
    if(ret == 0)
    {
      strcpy(wk_strg, w_goto_label[I].goto_label_1);
      x3 = 1;
    }
  }

  if(x3 == 0)
  {
    printf("\nc2z_goto.c c2_goto_label-001 Label Not Foundr\n");
    printf("c2z_goto.c rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, wk_strg);
  check_length();
  strcat(a_string, "DS     0H");
  strcpy(wk_remark, " goto label */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_goto.c #3");
    trace_rec_3();
  }

  convert = 1;
}


void goto_label_scan()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_goto.c c2_goto_label_scan");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];

   int pi;
   int pi2;
   int x3 = 0;
   int size = 0;

  pi = 0;
  ch = p_string[pi];
  while((ch == ' ') || (ch == '\t'))
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ':')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  x3 = 0;

  if (global_st == 0) 
  {
    if (goto_label_ct == 0) 
    {
      size = 1;
      w_goto_label = malloc(size * sizeof(struct goto_label));
    } 
    else 
    {
      size = goto_label_ct + 1;
      w_goto_label = realloc(w_goto_label, size * sizeof(struct goto_label));
    }
    w_goto_label[goto_label_ct].goto_label_rct = rct;
    strcpy(w_goto_label[goto_label_ct].goto_org_lb, field1);
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct); 
    strcpy(w_goto_label[goto_label_ct].goto_label_1, "L");
    strcat(w_goto_label[goto_label_ct].goto_label_1, wk_strg);
    goto_label_ct++;
    x3 = 1;
  }

  if ((global_st == 1) && (x3 == 0)) 
  {
      if (x3 == 0) 
      {
        if (goto_label_ct == 0) 
        {
          size = 1;
          w_goto_label = malloc(size * sizeof(struct goto_label));
        } 
        else 
        {
          size = goto_label_ct + 1;
          w_goto_label = realloc(w_goto_label, size * sizeof(struct goto_label));
        }
        w_goto_label[goto_label_ct].goto_label_rct = rct;
        strcpy(w_goto_label[goto_label_ct].goto_org_lb, field1);
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct); 
        strcpy(w_goto_label[goto_label_ct].goto_label_1, "L");
        strcat(w_goto_label[goto_label_ct].goto_label_1, wk_strg);
        goto_label_ct++;
      }
    }

  convert = 1;
  return; 
}
