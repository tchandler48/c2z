/* ***************************************************
*  c2z : c2_time.c :                                 *
*                                                    *
*  next error - time-002                             *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out TIME                                    *
* ************************************************** */
void c2_time() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_time.c c2_time START");
    trace_rec_1();
  }

printf("c2z_time.c c2_time rct = %d p_string = %s",rct,p_string);

   int pi = 0;
   int pi2 = 0;
   int x3 = 0;
   int v = 0;
   int ret = 0;
   int ret1 = 0;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while((ch == ' ') || (ch == '{') || (ch == '\t'))
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';
printf("c2z_time.c c2_time field1 = %s\n",field1);

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (v = 0; v < lv_ct; v++) 
    {
      ret = strcmp(field1, lw_variable[v].lv_name);
      ret1 = strcmp(sv_func, lw_variable[v].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        strcpy(field1a, lw_variable[v].lv_cname);
        lw_variable[v].lv_use_ct++;
        x3 = 1;
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field1, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          strcpy(field1a, gw_variable[v].gv_cname);
          gw_variable[v].gv_use_ct++;
          x3 = 1;
        }
      }
    }
  }

    if (x3 == 0) 
    {
      printf("\nc2z_time.c c2_time time-001 field1 Not Found = %s\n", field1);
      printf("c2z_time.c c2_time rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }


  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, field1a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_time.c c2_time #1");
    trace_rec_3();
  }


  strcpy(a_string, "         TIME  CLOCK,");
  strcat(a_string, "R9,CLOCKTYPE=STCK");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_time.c c2_time #2");
    trace_rec_3();
  }

  convert = 1;
}

/* ***************************************************
*  Punch out time variables                          *
* ************************************************** */
void c2_compute_time() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "Pass_3 c2_compute_time START");
    trace_rec_1();
  }

  int size = 0;

  /*  put C370TIME & C370PWK into v_variable  */
  if ((tot_localtime == 0) && (tot_time == 0)) 
  {
    if (gv_ct == 0) 
    {
      size = 1;
      gw_variable = malloc(size * sizeof(struct variables));
    } 
    else 
    {
      size = gv_ct + 1;
      gw_variable = realloc(gw_variable, size * sizeof(struct variables));
    }

    gw_variable[gv_ct].gv_rct = rct;
    strcpy(gw_variable[gv_ct].gv_name, "C370TIME");
    strcpy(gw_variable[gv_ct].gv_type, "L");
    gw_variable[gv_ct].gv_lgth = 11;
    strcpy(gw_variable[gv_ct].gv_literal, "  hh:mm:ss");
    gw_variable[gv_ct].gv_dec = 0;
    gv_ct++;
  }
}

void c2_clock_pass2() 
{

  if (traceflg == 1) 
  {
    strcpy(trace_1, "Pass_2 c2z_time.c c2_clock_pass2 START");
    trace_rec_1();
  }
}

void c2_clock_punch() 
{

  if (traceflg == 1) 
  {
    strcpy(trace_1, "Pass_3 c2z_time.c c2_clock_punch START");
    trace_rec_1();
  }
}