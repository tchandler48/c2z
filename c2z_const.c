/* ***************************************************
*  c2z : c2z_const.c :                               *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out CONST statement                         *
* ************************************************** */
void c2_const(void) 
{
  if (debug_lv >= 3) 
  {
    printf("c2z_const.c c2_const rct = %d START\n", rct);
  }

  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_const.c c2_const");
    trace_rec_1();
  }
  convert = 1;
}
