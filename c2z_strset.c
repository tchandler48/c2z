/* ***************************************************
*  c2z : c2z_strset.c :                              *
*                                                    *
*  next error - strset-003                           *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out STRSET                                  *
* ************************************************** */
void c2_strset(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_strset.c c2_strset");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];

  int pi;
  int pi2;
  int x = 0;
  int x1 = 0;
  int x3 = 0;
  int I = 0;
  int ret = 0;

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
      x1 = strcmp(gw_variable[I].gv_type, "C");
      if (x1 != 0) 
      {
        printf("\nc2z_strset.c c2_strset strset-001 field1 Not Character = %s\n",field1);
        printf("c2z_strset.c c2_strset rct = %d p_string = %s\n",rct,p_string);
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
    printf("c2z_strset.c c2_strset strset-002 field1 Not Found = %s\n", field1);
    printf("c2z_strset.c c2_strset rct = %d p_string = %s\n",rct,p_string);
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
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ')') 
  {
    if (ch != '\'') 
    {
      field2[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(gw_variable[I].gv_name, field1);
    if (ret == 0) 
    {
      x3 = gw_variable[I].gv_lgth;
    }
  }

  x3--;
  strcpy(a_string, "         MVI   ");
  strcat(a_string, field1);
  strcat(a_string, ",C'");
  strcat(a_string, field2);
  strcat(a_string, "'");
  strcpy(wk_remark, " strset  */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strset.c c2_strset #1");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   ");
  strcat(a_string, field1);
  strcat(a_string, "+1(");
  snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
  strcat(a_string, wk_strg);
  strcat(a_string, "),");
  strcat(a_string, field1);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strset.c c2_strset #2");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_strset.c c2_strset #3");
    trace_rec_3();
  }
}
