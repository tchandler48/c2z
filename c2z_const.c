/* ***************************************************
*  c2z : c2z_const.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out CONST statement                         *
* ************************************************** */
void c2_const(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_const.c c2_const");
    trace_rec_1();
  }
  convert = 1;
}
