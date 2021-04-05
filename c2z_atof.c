/* ***************************************************
*  c2z : c2z_atof.c :                                *
*                                                    *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* ***************************************************
*  Punch out atof                                    *
* ************************************************** */
void c2_atof(void) 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_atof.c c2_atof rct = %d START\n", rct);
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.atoi.c c2_atof START");
    trace_rec_1();
  }

  convert = 1;
}

void c2_atof_punch(void) 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_atof.c c2_atof_punch rct = %d START\n", rct);
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.atoi.c c2_atof_punch START");
    trace_rec_1();
  }

  convert = 1;
}
