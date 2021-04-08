/* ***************************************************
*  c2z : c2z_fclose.c :                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out FCLOSE                                  *
* ************************************************** */
void c2_close() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_close.c c2_close");
    trace_rec_1();
  }

  /* pgm_label(); */

  int pi;
  int y0 = 0;

  char ch;

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    pi++;
    ch = p_string[pi];
  }

  if (fclose_ct > 0) 
  {
    for (y0 = 0; y0 < fclose_ct; y0++) 
    {
      if (rct == w_fclose_table[y0].cl_rct) 
      {
        strcpy(a_string, "L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_fclose.c c2_close #1");
          trace_rec_3();
        }
      }
    }
  }

  convert = 1;
}

