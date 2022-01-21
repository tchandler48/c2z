/* ***************************************************
*  c2z : c2z_atol.c :                                *
*                                                    *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

/* *************************************************** 
*  Punch out atol                                    *
* ************************************************** */
void c2_atol(void)
{
   if(debug_lv >= 3)
   {
      printf("c2z_atol.c c2_atol rct = %d START\n",rct);
   }

   if(traceflg == 1)		
   {
      strcpy(trace_1, "c2z.atoi.c c2_atol START");
      trace_rec_1();
   }
  
   convert = 1;

}


void c2_atol_punch(void)
{
   if(debug_lv >= 3)
   {
      printf("c2z_atol.c c2_atol_punch rct = %d START\n",rct);
   }

   if(traceflg == 1)		
   {
      strcpy(trace_1, "c2z.atoi.c c2_atol_punch START");
      trace_rec_1();
   }

   convert = 1;
}



