/* ***************************************************
*  c2z : c2z_math_func.c :                           *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Scan for cos                                      *
* ************************************************** */
void c2_cos_pass2(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.math_func.c c2_cos_pass2 START");
    trace_rec_1();
  }

  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}

/* ***************************************************
*  Punch cos                                         *
* ************************************************** */
void c2_cos_punch(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math_func.c c2_cos_punch START");
    trace_rec_1();
  }

  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}

/* ***************************************************
*  Scan for rand                                     *
* ************************************************** */
void c2_rand_pass2(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math_func.c c2_rand_pass2 START");
    trace_rec_1();
  }

  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}

/* ***************************************************
*  Scan for pow                                      *
* ************************************************** */
void c2_pow_pass2(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math_func.c c2_pow_pass2 START");
    trace_rec_1();
  }

  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}

/* ***************************************************
*  Punch pow                                         *
* ************************************************** */
void c2_pow_punch(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math_func.c c2_pow_punch START");
    trace_rec_1();
  }

  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}

/* ***************************************************
*  Punch rand                                        *
* ************************************************** */
void c2_rand_punch(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math_func.c c2_rand_punch START");
    trace_rec_1();
  }

  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}

/* ***************************************************
*  Scan for sin                                      *
* ************************************************** */
void c2_sin_pass2(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math_func.c c2_sin_pass2 START");
    trace_rec_1();
  }

  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}

/* ***************************************************
*  Punch sin                                         *
* ************************************************** */
void c2_sin_punch(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math_func.c c2_sin_punch START");
    trace_rec_1();
  }

  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}

/* ***************************************************
*  Scan for sqrtf                                    *
* ************************************************** */
void c2_sqrt_pass2(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math_func.c c2_sqrt_pass2 START");
    trace_rec_1();
  }

  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}

/* ***************************************************
*  Punch sqrtf                                       *
* ************************************************** */
void c2_sqrt_punch(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math_func.c c2_sqrt_punch START");
    trace_rec_1();
  }

  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}

/* ***************************************************
*  Scan for tan                                      *
* ************************************************** */
void c2_tan_pass2(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math_func.c c2_tan_pass2 START");
    trace_rec_1();
  }

  int pi;

  char ch;
 
  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}

/* ***************************************************
*  Punch tan                                         *
* ************************************************** */
void c2_tan_punch(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_math_func.c c2_tan_punch START");
    trace_rec_1();
  }

  int pi;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  convert = 1;
}
