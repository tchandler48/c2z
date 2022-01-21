/* ***************************************************
*  c2z : c2z_return.c :                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out RETRUN code                             *
* ************************************************** */
void c2_return() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_return.c c2_return START");
    trace_rec_1();
  }

  char ch;
  char *p1;
  char tfield1[VAR_LGTH];
  char tfield5a[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int ret = 0;

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

  p1 = strstr(tfield1, ";");
  if (!p1) 
  {
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ';') 
    {
      /* tfield2[pi2] = ch;
      pi2++; */
      pi++;
      ch = p_string[pi];
    }
  }

  if (fn_ct > 0) 
  {
    for (I = 0; I < fn_ct; I++) 
    {
      ret = strcmp(sv_func, w_function[I].fn_name);
      if (ret == 0) 
      {
        strcpy(tfield5a, w_function[I].fn_loop);
      }
    }
  }

  ret = strcmp("main", sv_func);

  if (ret != 0) 
  {
    strcpy(a_string, "         PR");
    strcpy(wk_remark, " sub rtn  */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_return.c #1");
      trace_rec_3();
    }
  }

  convert = 1;
}
