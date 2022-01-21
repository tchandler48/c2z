/* ***************************************************
*  c2z  : c2z_localtime.c :                          *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  localtime                                         *
* ************************************************** */
void c2_localtime() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_localtime.c c2_localtime");
    trace_rec_1();
  }

  strcpy(a_string, "         TIME  TS,C370TIME");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_int.c c2_localtime #1");
    trace_rec_3();
  }
  convert = 1;
  return;
}

