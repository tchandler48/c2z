int c2_math_start()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math_lib.c c2_math_start START");
    trace_rec_1();
  }

  strcpy(a_string, "         LARL  15,rdp_main");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_lib.c rdp_main #1");
    trace_rec_3();
  }

  strcpy(a_string, "        BAKR   0,R15");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_lib.c rdp_main #1");
    trace_rec_3();
  }
/*
  int value;
printf("c2_math_start rct = %d p_string = %s\n",rct,p_string);
  value = c2_Expression();
  convert = 1;
  return value;
*/
}

void c2_rdp_main()
{
  strcpy(a_string, "rdp_main DS   0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_lib.c rdp_main #1");
    trace_rec_3();
  }

  strcpy(a_string, "         PR");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_math_lib.c rdp_main #2");
    trace_rec_3();
  }

}


int c2_Expression()	
{
   char ch;
   int pi;
   int Value;
printf("c2_Expression STARTing\n");

   return Value;
}
