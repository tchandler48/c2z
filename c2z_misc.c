/* ***************************************************
*  c2z : c2_misc.c                                   *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Punch out Register EQU's                          *
* ************************************************** */
void c2_regs() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_misc.c c2_regs");
    trace_rec_1();
  }

  strcpy(a_string, "R0       EQU  0\n");
  src_line();
  strcpy(a_string, "R1       EQU  1\n");
  src_line();
  strcpy(a_string, "R2       EQU  2\n");
  src_line();
  strcpy(a_string, "R3       EQU  3\n");
  src_line();
  strcpy(a_string, "R4       EQU  4\n");
  src_line();
  strcpy(a_string, "R5       EQU  5\n");
  src_line();
  strcpy(a_string, "R6       EQU  6\n");
  src_line();
  strcpy(a_string, "R7       EQU  7\n");
  src_line();
  strcpy(a_string, "R8       EQU  8\n");
  src_line();
  strcpy(a_string, "R9       EQU  9\n");
  src_line();
  strcpy(a_string, "R10      EQU  10\n");
  src_line();
  strcpy(a_string, "R11      EQU  11\n");
  src_line();
  strcpy(a_string, "R12      EQU  12\n");
  src_line();
  strcpy(a_string, "R13      EQU  13\n");
  src_line();
  strcpy(a_string, "R14      EQU  14\n");
  src_line();
  strcpy(a_string, "R15      EQU  15\n");
  src_line();
}
