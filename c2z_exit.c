/* ***************************************************
*  c2z  : c2z_exit.c                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out EXIT                                    *
* ************************************************** */
void c2_exit() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_exit.c c2_exit");
    trace_rec_1();
  }

  strcpy(a_string, "         JLU   C370EXIT");
  strcpy(wk_remark, " exit     */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_exit.c #1");
    trace_rec_3();
  }
}
