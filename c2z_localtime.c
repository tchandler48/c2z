/* ***************************************************
*  c2z  : c2z_localtime.c :                          *
*                                                    *
*  Copyright TCCS (c) 2015 - 2020                    *
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
  convert = 1;
}


/*
#include <stdio.h>
#include <time.h>


int main(void)
{
    time_t     now;
    struct tm *ts;
    char       buf[80];

  
    now = time(NULL);

   * Format and print the time, "ddd yyyy-mm-dd hh:mm:ss zzz" 
    ts = localtime(&now);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", ts);
    puts(buf);

    return 0;
}

 * The result should look something like
 * Fri 2008-08-22 15:21:59 WAST

*/
