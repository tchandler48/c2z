/* ***************************************************
*  c2z : c2_parameter.c                              *
*                                                    *
*  Copyright (c) 2015 - 2020                         *
**************************************************** */

/* ***************************************************
*  SCAN ()                                           *
* ************************************************** */
void c2_param_ct() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_parameter.c c2_param_ct START");
    trace_rec_1();
  }
  
  int I = 0;
  int s = 0;
  int ret = 0;

  char ch;
  char *p, *p1, *p8;

  if_convert = 0;

  s = strlen(p_string);
  s++;
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '{')
    {
      param_l++;
    }
    if (ch == '}')
    {
      param_r++;
    }
  }

  p = strstr(p_string, "{");
  if(p)
  {
    return;
  }

  p1 = strstr(p_string, "}");
  if(p1)
  {

/*
printf("c2z_parameter.c rct = %d l_start[1] = %d l_start[2] = %d l_start[3] = %d l_start[4] = %d l_start[5] = %d\n",rct,l_start[1],l_start[2],l_start[3],l_start[4],l_start[5]);
printf("c2z_parameter.c rct = %d l_start[6] = %d l_start[7] = %d l_start[8] = %d l_start[9] = %d l_start[10] = %d\n",rct,l_start[6],l_start[7],l_start[8],l_start[9],l_start[10]);

printf("c2z_parameter.c rct = %d l_type[1] = %d l_type[2] = %d l_type[3] = %d l_type[4] = %d l_type[5] = %d\n",rct,l_type[1],l_type[2],l_type[3],l_type[4],l_type[5]);
printf("c2z_parameter.c rct = %d l_type[6] = %d l_type[7] = %d l_type[8] = %d l_type[9] = %d l_type[10] = %d\n",rct,l_type[6],l_type[7],l_type[8],l_type[9],l_type[10]);
*/

/************************************************
*  Start Level 10                               *
*********************************************** */
    if((l_start[10] != 0) && (if_convert == 0))
    {
      if(l_type[10] == 1)
      {
        if(l_else[10] == 0)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[10] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof1 = rct;
            }
          }
        }

        if(l_else[10] == 1)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[10] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof2 = rct;
              l_else[10] = 0;
            }
          }
        }

   skip_if_10:

        s = 0;
        fgets(p_string, BUFSIZE, pgm);
        rct++;
        if(feof(pgm))
        {
          if_convert = 1;
          goto skip_10_loop;
        }

        s = strlen(p_string);
        if (s < 2) 
        {
          goto skip_if_10;
        }

        p8 = strstr(p_string, "else");

        if(!p8)
        {
          l_start[10] = 0;
          l_type[10] = 0;
          skip_read = 1;
        }

        if(p8)
        {
           if (wif_ct > 0) 
           {
             for (I = 0; I < wif_ct; I++) 
             {
               if (l_start[10] == w_if_table[I].wif_rct) 
               {
                  w_if_table[I].wif_else1 = rct;
                  l_else[10] = 1;
               }
             }
           }
        }
        if_convert = 1;
      }
     
      if((l_type[10] == 2) && (if_convert == 0))
      {
        for (I = 0; I < wh_ct; I++) 
        {
          ret = w_while_table[I].wh_rct;
          if (l_start[10] == ret) 
          {
            w_while_table[I].wh_eof1 = rct;
          }
        }
        l_start[10] = 0;
        l_type[10] = 0;
        if_convert = 1;
      }

      if(l_type[10] == 3)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c FOR/End Loop #10");
          trace_rec_1();
        }

        for (I = 0; I < for_ct; I++) 
        {
          ret = w_for_table[I].for_rct;
          if (l_start[10] == ret) 
          {
            w_for_table[I].for_eof1 = rct;
          }
        }
        l_start[10] = 0;
        l_type[10] = 0;
        convert = 1;
      }

     if(l_type[10] == 4)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c Switch Loop #10");
          trace_rec_1();
        }

        for (I = 0; I < switch_ct; I++) 
        {
          ret = w_switch_table[I].switch_rct;
          if (l_start[10] == ret) 
          {
            w_switch_table[I].switch_eof1 = rct;
          }
        }
        l_start[10] = 0;
        l_type[10] = 0;
        if_convert = 1;
      }
    }
    skip_10_loop:


/************************************************
*  Start Level 9                                *
*********************************************** */
    if((l_start[9] != 0) && (if_convert == 0))
    {
      if(l_type[9] == 1)
      {
        if(l_else[9] == 0)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[9] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof1 = rct;
            }
          }
        }

        if(l_else[9] == 1)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[9] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof2 = rct;
              l_else[9] = 0;
            }
          }
        }

   skip_if_9:

        s = 0;
        fgets(p_string, BUFSIZE, pgm);
        rct++;
        if(feof(pgm))
        {
          if_convert = 1;
          goto skip_9_loop;
        }

        s = strlen(p_string);
        if (s < 2) 
        {
          goto skip_if_9;
        }

        p8 = strstr(p_string, "else");

        if(!p8)
        {
          l_start[9] = 0;
          l_type[9] = 0;
          skip_read = 1;
        }

        if(p8)
        {
           if (wif_ct > 0) 
           {
             for (I = 0; I < wif_ct; I++) 
             {
               if (l_start[9] == w_if_table[I].wif_rct) 
               {
                  w_if_table[I].wif_else1 = rct;
                  l_else[9] = 1;
               }
             }
           }
        }
        if_convert = 1;
      }
     
      if((l_type[9] == 2) && (if_convert == 0))
      {
        for (I = 0; I < wh_ct; I++) 
        {
          ret = w_while_table[I].wh_rct;
          if (l_start[9] == ret) 
          {
            w_while_table[I].wh_eof1 = rct;
          }
        }
        l_start[9] = 0;
        l_type[9] = 0;
        if_convert = 1;
      }

      if(l_type[9] == 3)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c FOR/End Loop #8");
          trace_rec_1();
        }

        for (I = 0; I < for_ct; I++) 
        {
          ret = w_for_table[I].for_rct;
          if (l_start[9] == ret) 
          {
            w_for_table[I].for_eof1 = rct;
          }
        }
        l_start[9] = 0;
        l_type[9] = 0;
        convert = 1;
      }

     if(l_type[9] == 4)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c Switch Loop #9");
          trace_rec_1();
        }

        for (I = 0; I < switch_ct; I++) 
        {
          ret = w_switch_table[I].switch_rct;
          if (l_start[9] == ret) 
          {
            w_switch_table[I].switch_eof1 = rct;
          }
        }
        l_start[9] = 0;
        l_type[9] = 0;
        if_convert = 1;
      }
    }
    skip_9_loop:


/************************************************
*  Start Level 8                                *
*********************************************** */
    if((l_start[8] != 0) && (if_convert == 0))
    {
      if(l_type[8] == 1)
      {
        if(l_else[8] == 0)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[8] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof1 = rct;
            }
          }
        }

        if(l_else[8] == 1)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[8] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof2 = rct;
              l_else[8] = 0;
            }
          }
        }


   skip_if_8:

        s = 0;
        fgets(p_string, BUFSIZE, pgm);
        rct++;
        if(feof(pgm))
        {
          if_convert = 1;
          goto skip_8_loop;
        }

        s = strlen(p_string);
        if (s < 2) 
        {
          goto skip_if_8;
        }

        p8 = strstr(p_string, "else");

        if(!p8)
        {
          l_start[8] = 0;
          l_type[8] = 0;
          skip_read = 1;
        }

        if(p8)
        {
           if (wif_ct > 0) 
           {
             for (I = 0; I < wif_ct; I++) 
             {
               if (l_start[8] == w_if_table[I].wif_rct) 
               {
                  w_if_table[I].wif_else1 = rct;
                  l_else[8] = 1;
               }
             }
           }
        }
        if_convert = 1;
      }
     
      if((l_type[8] == 2) && (if_convert == 0))
      {
        for (I = 0; I < wh_ct; I++) 
        {
          ret = w_while_table[I].wh_rct;
          if (l_start[8] == ret) 
          {
            w_while_table[I].wh_eof1 = rct;
          }
        }
        l_start[8] = 0;
        l_type[8] = 0;
        if_convert = 1;
      }

      if(l_type[8] == 3)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c FOR/End Loop #8");
          trace_rec_1();
        }

        for (I = 0; I < for_ct; I++) 
        {
          ret = w_for_table[I].for_rct;
          if (l_start[8] == ret) 
          {
            w_for_table[I].for_eof1 = rct;
          }
        }
        l_start[8] = 0;
        l_type[8] = 0;
        convert = 1;
      }

     if(l_type[8] == 4)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c Switch Loop #8");
          trace_rec_1();
        }

        for (I = 0; I < switch_ct; I++) 
        {
          ret = w_switch_table[I].switch_rct;
          if (l_start[8] == ret) 
          {
            w_switch_table[I].switch_eof1 = rct;
          }
        }
        l_start[8] = 0;
        l_type[8] = 0;
        if_convert = 1;
      }
    }
    skip_8_loop:

/************************************************
*  Start Level 7                                *
*********************************************** */
    if((l_start[7] != 0) && (if_convert == 0))
    {
      if(l_type[7] == 1)
      {
        if(l_else[7] == 0)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[7] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof1 = rct;
            }
          }
        }

        if(l_else[7] == 1)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[7] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof2 = rct;
              l_else[7] = 0;
            }
          }
        }


   skip_if_7:

        s = 0;
        fgets(p_string, BUFSIZE, pgm);
        rct++;
        if(feof(pgm))
        {
          if_convert = 1;
          goto skip_7_loop;
        }

        s = strlen(p_string);
        if (s < 2) 
        {
          goto skip_if_7;
        }

        p8 = strstr(p_string, "else");

        if(!p8)
        {
          l_start[7] = 0;
          l_type[7] = 0;
          skip_read = 1;
        }

        if(p8)
        {
           if (wif_ct > 0) 
           {
             for (I = 0; I < wif_ct; I++) 
             {
               if (l_start[7] == w_if_table[I].wif_rct) 
               {
                  w_if_table[I].wif_else1 = rct;
                  l_else[7] = 1;
               }
             }
           }
        }
        if_convert = 1;
      }
     
      if((l_type[7] == 2) && (if_convert == 0))
      {
        for (I = 0; I < wh_ct; I++) 
        {
          ret = w_while_table[I].wh_rct;
          if (l_start[7] == ret) 
          {
            w_while_table[I].wh_eof1 = rct;
          }
        }
        l_start[7] = 0;
        l_type[7] = 0;
        if_convert = 1;
      }

      if(l_type[7] == 3)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c FOR/End Loop #7");
          trace_rec_1();
        }

        for (I = 0; I < for_ct; I++) 
        {
          ret = w_for_table[I].for_rct;
          if (l_start[7] == ret) 
          {
            w_for_table[I].for_eof1 = rct;
          }
        }
        l_start[7] = 0;
        l_type[7] = 0;
        if_convert = 1;
      }

      if(l_type[7] == 4)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c Switch Loop #7");
          trace_rec_1();
        }

        for (I = 0; I < switch_ct; I++) 
        {
          ret = w_switch_table[I].switch_rct;
          if (l_start[7] == ret) 
          {
            w_switch_table[I].switch_eof1 = rct;
          }
        }
        l_start[7] = 0;
        l_type[7] = 0;
        if_convert = 1;
      }
   }
   skip_7_loop:

/************************************************
*  Start Level 6                                *
*********************************************** */
    if((l_start[6] != 0) && (if_convert == 0))
    {
      if(l_type[6] == 1)
      {
        if(l_else[6] == 0)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[6] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof1 = rct;
            }
          }
        }

        if(l_else[6] == 1)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[6] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof2 = rct;
              l_else[6] = 0;
            }
          }
        }


   skip_if_6:

        s = 0;
        fgets(p_string, BUFSIZE, pgm);
        rct++;
        if(feof(pgm))
        {
          if_convert = 1;
          goto skip_6_loop;
        }

        s = strlen(p_string);
        if (s < 2) 
        {
          goto skip_if_6;
        }

        p8 = strstr(p_string, "else");

        if(!p8)
        {
          l_start[6] = 0;
          l_type[6] = 0;
          skip_read = 1;
        }

        if(p8)
        {
           if (wif_ct > 0) 
           {
             for (I = 0; I < wif_ct; I++) 
             {
               if (l_start[6] == w_if_table[I].wif_rct) 
               {
                  w_if_table[I].wif_else1 = rct;
                  l_else[6] = 1;
               }
             }
           }
        }
        if_convert = 1;
      }
     
      if((l_type[6] == 2) && (if_convert == 0))
      {
        for (I = 0; I < wh_ct; I++) 
        {
          ret = w_while_table[I].wh_rct;
          if (l_start[6] == ret) 
          {
            w_while_table[I].wh_eof1 = rct;
          }
        }
        l_start[6] = 0;
        l_type[6] = 0;
        if_convert = 1;
      }

     if(l_type[6] == 3)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c FOR/End Loop #6");
          trace_rec_1();
        }

        for (I = 0; I < for_ct; I++) 
        {
          ret = w_for_table[I].for_rct;
          if (l_start[6] == ret) 
          {
            w_for_table[I].for_eof1 = rct;
          }
        }
        l_start[6] = 0;
        l_type[6] = 0;
        if_convert = 1;
      }

      if(l_type[6] == 4)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c Switch Loop #6");
          trace_rec_1();
        }

        for (I = 0; I < switch_ct; I++) 
        {
          ret = w_switch_table[I].switch_rct;
          if (l_start[6] == ret) 
          {
            w_switch_table[I].switch_eof1 = rct;
          }
        }
        l_start[6] = 0;
        l_type[6] = 0;
        if_convert = 1;
      }
    }
    skip_6_loop:

/************************************************
*  Start Level 5                                *
*********************************************** */
    if((l_start[5] != 0) && (if_convert == 0))
    {
      if(l_type[5] == 1)
      {
        if(l_else[5] == 0)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[5] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof1 = rct;
            }
          }
        }

        if(l_else[5] == 1)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[5] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof2 = rct;
              l_else[5] = 0;
            }
          }
        }


   skip_if_5:

        s = 0;
        fgets(p_string, BUFSIZE, pgm);
        rct++;
        if(feof(pgm))
        {
          if_convert = 1;
          goto skip_5_loop;
        }

        s = strlen(p_string);
        if (s < 2) 
        {
          goto skip_if_5;
        }

        p8 = strstr(p_string, "else");

        if(!p8)
        {
          l_start[5] = 0;
          l_type[5] = 0;
          skip_read = 1;
        }

        if(p8)
        {
           if (wif_ct > 0) 
           {
             for (I = 0; I < wif_ct; I++) 
             {
               if (l_start[5] == w_if_table[I].wif_rct) 
               {
                  w_if_table[I].wif_else1 = rct;
                  l_else[5] = 1;
               }
             }
           }
        }
        if_convert = 1;
      }
     
      if((l_type[5] == 2) && (if_convert == 0))
      {
        for (I = 0; I < wh_ct; I++) 
        {
          ret = w_while_table[I].wh_rct;
          if (l_start[5] == ret) 
          {
            w_while_table[I].wh_eof1 = rct;
          }
        }
        l_start[5] = 0;
        l_type[5] = 0;
        if_convert = 1;
      }

     if(l_type[5] == 3)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c FOR/End Loop #5");
          trace_rec_1();
        }

        for (I = 0; I < for_ct; I++) 
        {
          ret = w_for_table[I].for_rct;
          if (l_start[5] == ret) 
          {
            w_for_table[I].for_eof1 = rct;
          }
        }
        l_start[5] = 0;
        l_type[5] = 0;
        if_convert = 1;
      }

      if(l_type[5] == 4)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c Switch Loop #5");
          trace_rec_1();
        }

        for (I = 0; I < switch_ct; I++) 
        {
          ret = w_switch_table[I].switch_rct;
          if (l_start[5] == ret) 
          {
            w_switch_table[I].switch_eof1 = rct;
          }
        }
        l_start[5] = 0;
        l_type[5] = 0;
        if_convert = 1;
      }
    }
    skip_5_loop:

/************************************************
*  Start Level 4                                *
*********************************************** */
    if((l_start[4] != 0) && (if_convert == 0))
    {
      if(l_type[4] == 1)
      {
        if(l_else[4] == 0)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[4] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof1 = rct;
              if_convert = 1;
            }
          }
        }

        if((l_else[4] == 1) && (if_convert == 0))
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[4] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof2 = rct;
              l_else[4] = 0;
            }
          }
        }


   skip_if_4:

        s = 0;
        fgets(p_string, BUFSIZE, pgm);
        rct++;
        if(feof(pgm))
        {
          if_convert = 1;
          goto skip_4_loop;
        }

        s = strlen(p_string);
        if (s < 2) 
        {
          goto skip_if_4;
        }

        p8 = strstr(p_string, "else");

        if(!p8)
        {
          l_start[4] = 0;
          l_type[4] = 0;
          skip_read = 1;
        }

        if(p8)
        {
           if (wif_ct > 0) 
           {
             for (I = 0; I < wif_ct; I++) 
             {
               if (l_start[4] == w_if_table[I].wif_rct) 
               {
                  w_if_table[I].wif_else1 = rct;
                  l_else[4] = 1;
               }
             }
           }
        }
        if_convert = 1;
      }
     

      if((l_type[4] == 2) && (if_convert == 0))
      {
        for (I = 0; I < wh_ct; I++) 
        {
          ret = w_while_table[I].wh_rct;
          if (l_start[4] == ret) 
          {
            w_while_table[I].wh_eof1 = rct;
          }
        }
        l_start[4] = 0;
        l_type[4] = 0;
        if_convert = 1;
      }

      if(l_type[4] == 3)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c FOR/End Loop #4");
          trace_rec_1();
        }

        for (I = 0; I < for_ct; I++) 
        {
          ret = w_for_table[I].for_rct;
          if (l_start[4] == ret) 
          {
            w_for_table[I].for_eof1 = rct;
          }
        }
        l_start[4] = 0;
        l_type[4] = 0;
        if_convert = 1;
      }

      if(l_type[4] == 4)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c Switch Loop #4");
          trace_rec_1();
        }

        for (I = 0; I < switch_ct; I++) 
        {
          ret = w_switch_table[I].switch_rct;
          if (l_start[4] == ret) 
          {
            w_switch_table[I].switch_eof1 = rct;
          }
        }
        l_start[4] = 0;
        l_type[4] = 0;
        if_convert = 1;
      }
    }
    skip_4_loop:

/************************************************
*  Start Level 3                                *
*********************************************** */
    if((l_start[3] != 0) && (if_convert == 0))
    {
      if(l_type[3] == 1)
      {
        if(l_else[3] == 0)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[3] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof1 = rct;
            }
          }
        }

        if(l_else[3] == 1)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[3] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof2 = rct;
              l_else[3] = 0;
            }
          }
        }


   skip_if_3:

        s = 0;
        fgets(p_string, BUFSIZE, pgm);
        rct++;
 
        if(feof(pgm))
        {
          if_convert = 1;
          goto skip_3_loop;
        }

        s = strlen(p_string);
        if (s < 2) 
        {
          goto skip_if_3;
        }

        p8 = strstr(p_string, "else");

        if(!p8)
        {
          l_start[3] = 0;
          l_type[3] = 0;
          skip_read = 1;
        }

        if(p8)
        {
           if (wif_ct > 0) 
           {
             for (I = 0; I < wif_ct; I++) 
             {
               if (l_start[3] == w_if_table[I].wif_rct) 
               {
                  w_if_table[I].wif_else1 = rct;
                  l_else[3] = 1;
               }
             }
           }
        }
        if_convert = 1;
      }

      if((l_type[3] == 2) && (if_convert == 0))
      {
        for (I = 0; I < wh_ct; I++) 
        {
          ret = w_while_table[I].wh_rct;
          if (l_start[3] == ret) 
          {
            w_while_table[I].wh_eof1 = rct;
          }
        }
        l_start[3] = 0;
        l_type[3] = 0;
        if_convert = 1;
      }

      if(l_type[3] == 3)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c FOR/End Loop #3");
          trace_rec_1();
        }

        for (I = 0; I < for_ct; I++) 
        {
          ret = w_for_table[I].for_rct;
          if (l_start[3] == ret) 
          {
            w_for_table[I].for_eof1 = rct;
          }
        }
        l_start[3] = 0;
        l_type[3] = 0;
        if_convert = 1;
      }

      if(l_type[3] == 4)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c Switch Loop #3");
          trace_rec_1();
        }

        for (I = 0; I < switch_ct; I++) 
        {
          ret = w_switch_table[I].switch_rct;
          if (l_start[3] == ret) 
          {
            w_switch_table[I].switch_eof1 = rct;
          }
        }
        l_start[3] = 0;
        l_type[3] = 0;
        if_convert = 1;
      }
    }
    skip_3_loop:

/************************************************
*  Start Level 2                                *
*********************************************** */
    if((l_start[2] != 0) && (if_convert == 0))
    {
      if(l_type[2] == 1)
      {
        if(l_else[2] == 0)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[2] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof1 = rct;
            }
          }
        }

        if(l_else[2] == 1)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[2] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof2 = rct;
              l_else[2] = 0;
            }
          }
        }


   skip_if_2:

        s = 0;
        fgets(p_string, BUFSIZE, pgm);
        rct++;
        if(feof(pgm))
        {
          if_convert = 1;
          goto skip_2_loop;
        }

        s = strlen(p_string);
        if (s < 2) 
        {
          goto skip_if_2;
        }

        p8 = strstr(p_string, "else");

        if(!p8)
        {
          l_start[2] = 0;
          l_type[2] = 0;
          skip_read = 1;
        }

        if(p8)
        {
           if (wif_ct > 0) 
           {
             for (I = 0; I < wif_ct; I++) 
             {
               if (l_start[2] == w_if_table[I].wif_rct) 
               {
                  w_if_table[I].wif_else1 = rct;
                  l_else[2] = 1;
               }
             }
           }
        }
        if_convert = 1;
      }

      if(l_type[2] == 2)
      {
        if(wh_ct > 0)
        {
          for (I = 0; I < wh_ct; I++) 
          {
            if (l_start[2] == w_while_table[I].wh_rct) 
            {
              w_while_table[I].wh_eof1 = rct;
              
            }
          }
        }
        l_start[2] = 0;
        l_type[2] = 0;
        if_convert = 1;
      }

      if(l_type[2] == 3)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c FOR/End Loop #2");
          trace_rec_1();
        }

        for (I = 0; I < for_ct; I++) 
        {
          ret = w_for_table[I].for_rct;
          if (l_start[2] == ret) 
          {
            w_for_table[I].for_eof1 = rct;
          }
        }
        l_start[2] = 0;
        l_type[2] = 0;
        if_convert = 1;
      }

      if(l_type[2] == 4)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c Switch Loop #2");
          trace_rec_1();
        }

        for (I = 0; I < switch_ct; I++) 
        {
          ret = w_switch_table[I].switch_rct;
          if (l_start[2] == ret) 
          {
            w_switch_table[I].switch_eof1 = rct;
          }
        }
        l_start[2] = 0;
        l_type[2] = 0;
        if_convert = 1;
      }
    }
    skip_2_loop:  

/************************************************
*  Start Level 1                                *
*********************************************** */
    if((l_start[1] != 0) && (if_convert == 0))
    {
      if(l_type[1] == 1)
      {
        if(l_else[1] == 0)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[1] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof1 = rct;
            }
          }
        }

        if(l_else[1] == 1)
        {
          for (I = 0; I < wif_ct; I++) 
          {
            if (l_start[1] == w_if_table[I].wif_rct) 
            {
              w_if_table[I].wif_eof2 = rct;
              l_else[1] = 0;
            }
          }
        }

        s = 0;
        fgets(p_string, BUFSIZE, pgm);
        rct++;
  
        p8 = strstr(p_string, "else");

        if(!p8)
        {
          l_start[1] = 0;
          l_type[1] = 0;
          skip_read = 1;
        }

        if(p8)
        {
           if (wif_ct > 0) 
           {
             for (I = 0; I < wif_ct; I++) 
             {
               if (l_start[1] == w_if_table[I].wif_rct) 
               {
                  w_if_table[I].wif_else1 = rct;
                  l_else[1] = 1;
               }
             }
           }
        }
        if_convert = 1;
      }

      if(l_type[1] == 2)
      {
        for (I = 0; I < wh_ct; I++) 
        {
          ret = w_while_table[I].wh_rct;
          if (l_start[1] == ret) 
          {
            w_while_table[I].wh_eof1 = rct;
          }
        }
        l_start[1] = 0;
        l_type[1] = 0;
        if_convert = 1;
      }

      if(l_type[1] == 3)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c FOR/End Loop #1");
          trace_rec_1();
        }

        for (I = 0; I < for_ct; I++) 
        {
          ret = w_for_table[I].for_rct;
          if (l_start[1] == ret) 
          {
            w_for_table[I].for_eof1 = rct;
          }
        }
        l_start[1] = 0;
        l_type[1] = 0;
        if_convert = 1;
      }

      if(l_type[1] == 4)
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2.c Switch Loop #1");
          trace_rec_1();
        }

        for (I = 0; I < switch_ct; I++) 
        {
          ret = w_switch_table[I].switch_rct;
          if (l_start[1] == ret) 
          {
            w_switch_table[I].switch_eof1 = rct;
          }
        }
        l_start[1] = 0;
        l_type[1] = 0;
        if_convert = 1;
      }
    }
  }
}

