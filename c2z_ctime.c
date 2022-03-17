/* ***************************************************
*  c2z  : c2z_ctime.c :                              *
*                                                    *
*  next error - ctime-004                            *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  ctime                                             *
* ************************************************** */
void c2_ctime() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_ctime.c c2_ctime");
    trace_rec_1();
  }

  int pi;
  int pi2;
  int x3 = 0;
  int I = 0;
  int x2 = 0;
  int ret = 0;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while((ch == ' ') || (ch == '\t') || (ch == '{'))
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    pi2++;
    pi++;
    ch = p_string[pi];
  }
 
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

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

  pi2 = 0;
  while(ch != '(')
  {
    pi2++;
    pi++;
    ch = p_string[pi];
  }
 
  strcpy(a_string, "         LARL  R9,C370DTTM");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #1");
    trace_rec_3();
  }
  work_use_ct[85]++;

  strcpy(a_string, "         TIME  DEC,R9,LINKAGE=SYSTEM,DATETYPE=MMDDYYYY");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #2");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370DWRK");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370DTTM");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #4");
    trace_rec_3();
  }
  work_use_ct[85]++;


/*         UNPK  DWORK(9),TIMEDATE+8(5) */

  strcpy(a_string, "         UNPK  0(5,R9),8(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370DDTE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #6");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370DTTM");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #7");
    trace_rec_3();
  }
  work_use_ct[85]++;

  strcpy(a_string, "         MVC   0(2,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #8");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   3(2,R9),2(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #8");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   6(2,R9),6(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #8");
    trace_rec_3();
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    x2 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x2 == 0)) 
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
    printf("\nc2z_ctime.c c2_ctime ctime-001 field1 Not Found = %s\n", field1);
    printf("c2z_ctime.c c2_ctime rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, field1a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #8");
    trace_rec_3();
  }
 
  strcpy(a_string, "         LARL  R8,C370DDTE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #8");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(8,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_ctimec c2_time #8");
    trace_rec_3();
  }

  convert = 1;
}


void c2_time_t()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_ctime.c c2_time_t");
    trace_rec_1();
  }

  int pi;
  int pi2;

  char ch;
 /* char field1[VAR_LGTH]; */

  pi = 0;
  ch = p_string[pi];
  while((ch == ' ') || (ch == '\t') || (ch == '{'))
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
 /*   field1[pi2] = ch; */
    pi2++;
    pi++;
    ch = p_string[pi];
  }
/*  field1[pi2] = '\0'; */

  convert = 1;

}



void c2_time_t_punch()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_ctime.c c2_time_t_punch");
    trace_rec_1();
  }
  convert = 1;
}



