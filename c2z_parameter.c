/* ***************************************************
*  c2z : c2_parameter.c                              *
*                                                    *
*  Copyright (c) 2015 - 2021                         *
**************************************************** */


/* ***************************************************
*  SCAN ()                                           *
* ************************************************** */		
void c2_param_ct()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2z_parameter.c c2_param_ct");
        trace_rec_1();
     }

      int I = 0;
      int s = 0;
      int x = 0;
      int param_l = 0;
      int param_r = 0;

      if_parm1 = 0;
      if_parm2 = 0;
      if_parm3 = 0;
      if_parm4 = 0;
      if_parm5 = 0;
      if_parm6 = 0;
      if_parm7 = 0;
      if_parm8 = 0;
      if_parm9 = 0;
      if_parm10 = 0;

     char ch;
     char *p7, *p8;

     s = strlen(p_string);
     for(I=0; I < s; I++)
     {
        ch = p_string[I];
        if(ch == '{')
           param_l++;
        if(ch == '}')
           param_r++;
     }

     x = 0;
     x = x + if_level;
     x = x + inside_if1;
     x = x + inside_if2;
     x = x + inside_if3;
     x = x + inside_if4;
     x = x + inside_if5;
     x = x + inside_if6;
     x = x + inside_if7;
     x = x + inside_if8;
     x = x + inside_if9;
     x = x + inside_if10;

     if((param_l == 0) && (param_r == 1) && (x == 0))
     {
        convert = 1;
        return;
     }

     if((param_l > 0) && (if_level == 1) && (inside_if1 == 1))
     {
        if_parm1++;
     }

     if((param_l > 0) && (if_level == 2) && (inside_if2 == 1))
     {
        if_parm2++;
     }

     if((param_l > 0) && (if_level == 3) && (inside_if3 == 1))
     {
        if_parm3++;
     }

     if((param_l > 0) && (if_level == 4) && (inside_if4 == 1))
     {
        if_parm4++;
     }

     if((param_l > 0) && (if_level == 5) && (inside_if5 == 1))
     {
        if_parm5++;
     }

     if((param_l > 0) && (if_level == 6) && (inside_if6 == 1))
     {
        if_parm6++;
     }

     if((param_l > 0) && (if_level == 7) && (inside_if7 == 1))
     {
        if_parm7++;
     }

     if((param_l > 0) && (if_level == 8) && (inside_if8 == 1))
     {
        if_parm8++;
     }

     if((param_l > 0) && (if_level == 9) && (inside_if9 == 1))
     {
        if_parm9++;
     }

     if((param_l > 0) && (if_level == 10) && (inside_if10 == 1))
     {
        if_parm10++;
     }

     /* *** START OF 1ST IF LOOP	*** */
     if((param_r > 0) && (if_level == 1) && (inside_if1 == 1))
     {
        if_parm1 = 0;
  
        /* test if_parm1 == 0, then update if_table */
        if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 1))
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z_parameter.c c2_param_ct if-1");
              trace_rec_1();
           }

           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start1 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof2 = rct;
                 }
              }
           }
           inside_if1 = 0;
           if_start1 = 0;
           if_else_flag1 = 0;
           if_level--;
        }

        if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 0))
        {
           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start1 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof1 = rct;
                    w_if_table[I].wif_else = 0;
                    w_if_table[I].wif_eof2 = 0;
                    break;
                 }
              }
           }

           fgets(p_string, BUFSIZE, pgm);
           rct++;
           if(prt_ln == 1)
           {
              printf("c2z_Parm IF1 if_level = %d rct = %d p_string = %s",if_level,rct,p_string);
           }

           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z_parameter.c c2_param_ct if-1 READ");
              trace_rec_1();
           }

           p8 = strstr(p_string, "else");
           if(!p8)
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2_parameter.c c2_param_ct if-1 NOELSE");
                 trace_rec_1();
              }
              skip_read = 1;
              inside_if1 = 0;
              if_start1 = 0;
              if_level--;
              p7 = strstr(p_string, "}");
              if(p7)
              {
                 skip_read = 0;
                 if_level--;
                 convert = 1;
                 return;
              }
              convert = 1;
              return;

           }

           if(p8)
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z_parameter.c c2_param_ct if-1 ELSE-1");
                 trace_rec_1();
              }
              if_else_flag1 = 1;
              /* update w_if_else start */
              if(wif_ct > 0)
              {
                 for(I = 0; I < wif_ct; I++)
                 {
                    if(if_start1 == w_if_table[I].wif_rct)
                    {
                       w_if_table[I].wif_else = rct;
                    }
                 }
              }
           }
        }
     }
/* *** END OF 1ST FOR LOOP  *** */

/* *** START OF 2ND IF LOOP *** */
     if((param_r > 0) && (if_level == 2) && (inside_if2 == 1))
     {
        if_parm2 = 0;

        /* test if_parm2 == 0, then update if_table */
        if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 1))
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z_parameter.c c2_param_ct if-2");
              trace_rec_1();
           }
           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start2 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof2 = rct;
                 }
              }
           }
           inside_if2 = 0;
           if_start2 = 0;
           if_else_flag2 = 0;
           if_level--;
        }

        if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 0))
        {
           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start2 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof1 = rct;
                    w_if_table[I].wif_else = 0;
                    w_if_table[I].wif_eof2 = 0;
                    break;
                 }
              }
           }

           fgets(p_string, BUFSIZE, pgm);
           rct++;
           if(prt_ln == 1)
           {
              printf("Pass 2 IF2 if_level = %d rct = %d p_string = %s",if_level,rct,p_string);
           }

           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z_parameter.c c2_param_ct if-2 READ");
              trace_rec_1();
           }

           p8 = strstr(p_string, "else");
           if(!p8)
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z_parameter.c c2_param_ct if-2 NOELSE");
                 trace_rec_1();
              }
              skip_read = 1;
              inside_if2 = 0;
              if_start2 = 0;
              if_level--;
              p7 = strstr(p_string, "}");
              if(p7)
              {
                 skip_read = 0;
                 if_level--;
                 convert = 1;
                 return;
              }
              convert = 1;
              return;
           }

           if(p8)
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z_parameter.c c2_param_ct if-2 ELSE");
                 trace_rec_1();
              }
              if_else_flag2 = 1;

              /* update w_if_else start */
              if(wif_ct > 0)
              {
                 for(I = 0; I < wif_ct; I++)
                 {
                    if(if_start2 == w_if_table[I].wif_rct)
                    {
                       w_if_table[I].wif_else = rct;
                    }
                 }
              }
           }
        }
     }
/* *** END OF 2ND FOR LOOP *** */


/* *** START OF 3RD IF LOOP *** */
     if((param_r > 0) && (if_level == 3) && (inside_if3 == 1))
     {
        if_parm3 = 0;

        /* test if_parm3 == 0, then update if_table */
        if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 1))
        {
           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z_parameter.c c2_param_ct if-3");
              trace_rec_1();
           }

           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start3 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof2 = rct;
                 }
              }
           }
           inside_if3 = 0;
           if_start3 = 0;
           if_else_flag3 = 0;
           if_level--;
        }

        if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 0))
        {
           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start3 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof1 = rct;
                    w_if_table[I].wif_else = 0;
                    w_if_table[I].wif_eof2 = 0;
                    break;
                 }
              }
           }

           fgets(p_string, BUFSIZE, pgm);
           rct++;
           if(prt_ln == 1)
           {
              printf("Pass 2 IF3 rct = %d p_string = %s",rct,p_string);
           }

           if(trace_flag == 1)
           {
              strcpy(trace_1, "c2z_parameter.c c2_param_ct if-3 READ");
              trace_rec_1();
           }

           p8 = strstr(p_string, "else");
           if(!p8)
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z_parameter.c c2_param_ct if-3 NOELSE");
                 trace_rec_1();
              }

              skip_read = 1;
              inside_if3 = 0;
              if_start3 = 0;
              if_level--;
              p7 = strstr(p_string, "}");
              if(p7)
              {
                 skip_read = 0;
                 if_level--;
                 convert = 1;
                 return;
              }
              convert = 1;
              return;

           }

           if(p8)
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z_parameter.c c2_param_ct if-3 ELSE");
                 trace_rec_1();
              }
              if_else_flag3 = 1;
              if(wif_ct > 0)
              {
                 for(I = 0; I < wif_ct; I++)
                 {
                    if(if_start3 == w_if_table[I].wif_rct)
                    {
                       w_if_table[I].wif_else = rct;
                    }
                 }
              }
           }
        }
     }
/* *** END OF 3RD FOR LOOP *** */


/* *** START OF 4TH IF LOOP *** */
     if((param_r > 0) && (if_level == 4) && (inside_if4 == 1))
     {
         if_parm4 = 0;

         /* test if_parm4 == 0, then update if_table */
         if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 1))
         {
            if(trace_flag == 1)
            {
               strcpy(trace_1, "c2z_parameter.c c2_param_ct if-4");
               trace_rec_1();
            }

            if(wif_ct > 0)
            {
               for(I = 0; I < wif_ct; I++)
               {
                  if(if_start4 == w_if_table[I].wif_rct)
                  {
                     w_if_table[I].wif_eof2 = rct;
                  }
               }
            }
            inside_if4 = 0;
            if_start4 = 0;
            if_else_flag4 = 0;
            if_level--;
         }

         if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 0))
         {
            if(wif_ct > 0)
            {
               for(I = 0; I < wif_ct; I++)
               {
                  if(if_start4 == w_if_table[I].wif_rct)
                  {
                     w_if_table[I].wif_eof1 = rct;
                     w_if_table[I].wif_else = 0;
                     w_if_table[I].wif_eof2 = 0;
                     break;
                  }
               }
            }

            fgets(p_string, BUFSIZE, pgm);
            rct++;
            if(prt_ln == 1)
            {
               printf("Pass 2 if_level = %d IF4 rct = %d p_string = %s",if_level,rct,p_string);
            }

            if(trace_flag == 1)
            {
               strcpy(trace_1, "c2z_parameter.c c2_param_ct if-4 READ");
               trace_rec_1();
            } 

            p8 = strstr(p_string, "else");
            if(!p8)
            {
               if(trace_flag == 1)
               {
                  strcpy(trace_1, "c2z_parameter.c c2_param_ct if-4 NOELSE");
                  trace_rec_1();
               }
               skip_read = 1;
               inside_if4 = 0;
               if_start4 = 0;
               if_level--;
               p7 = strstr(p_string, "}");
               if(p7)
              {
                 skip_read = 0;
                 if_level--;
                 convert = 1;
                 return;
              }
               convert = 1;
               return;
            }

            if(p8)
            {
               if(trace_flag == 1)
               {
                  strcpy(trace_1, "c2z_parameter.c c2_param_ct if-4 ELSE");
                  trace_rec_1();
               }

               if_else_flag4 = 1;
               if(wif_ct > 0)
               {
                  for(I = 0; I < wif_ct; I++)
                  {
                     if(if_start4 == w_if_table[I].wif_rct)
                     {
                        w_if_table[I].wif_else = rct;
                     }
                  }
               }
            }
        }
     }
/* *** END OF 4TH FOR LOOP *** */


/* *** START OF 5TH IF LOOP *** */
     if((param_r > 0) && (if_level == 5) && (inside_if5 == 1))
     {
        if_parm5 = 0;

        /* test if_parm5 == 0, then update if_table */
        if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 1))
        {
           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start5 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof2 = rct;
                 }
              }
           }
           inside_if5 = 0;
           if_start5 = 0;
           if_else_flag5 = 0;
           if_level--;
        }

        if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 0))
        {
           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start5 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof1 = rct;
                    w_if_table[I].wif_else = 0;
                    w_if_table[I].wif_eof2 = 0;
                    break;
                 }
              }
           }

           fgets(p_string, BUFSIZE, pgm);
           rct++;
           if(prt_ln == 1)
           {
              printf("Pass 2 IF5 rct = %d p_string = %s",rct,p_string);
           }

           if(trace_flag == 1)
           {
               strcpy(trace_1, "c2z_parameter.c c2_param_ct if-5 READ");
               trace_rec_1();
           } 

           p8 = strstr(p_string, "else");
           if(!p8)
           {
               if(trace_flag == 1)
               {
                  strcpy(trace_1, "c2z_parameter.c c2_param_ct if-5 NOELSE");
                  trace_rec_1();
               }
              skip_read = 1;
              inside_if5 = 0;
              if_start5 = 0;
              if_level--;
              p7 = strstr(p_string, "}");
              if(p7)
              {
                 skip_read = 0;
                 if_level--;
                 convert = 1;
                 return;
              }

              convert = 1;
              return;
           }

           if(p8)
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z_parameter.c c2_param_ct if-5 ELSE-5");
                 trace_rec_1();
              }
              if_else_flag5 = 1;
              if(wif_ct > 0)
              {
                 for(I = 0; I < wif_ct; I++)
                 {
                    if(if_start5 == w_if_table[I].wif_rct)
                    {
                       w_if_table[I].wif_else = rct;
                    }
                 }
              }
           }
        }
     }

/* *** END OF 5TH FOR LOOP *** */


/* *** START OF 6TH IF LOOP *** */
     if((param_r > 0) && (if_level == 6) && (inside_if6 == 1))
     {
        if_parm6 = 0;

        /* test if_parm6 == 0, then update if_table */
        if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 1))
        {
           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start6 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof2 = rct;
                 }
              }
           }
           inside_if6 = 0;
           if_start6 = 0;
           if_else_flag6 = 0;
           if_level--;
        }

        if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 0))
        {
           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start6 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof1 = rct;
                    w_if_table[I].wif_else = 0;
                    w_if_table[I].wif_eof2 = 0;
                    break;
                 }
		}
           }

           fgets(p_string, BUFSIZE, pgm);
           rct++;
           if(prt_ln == 1)
           {
              printf("Pass 2 IF6 rct = %d p_string = %s",rct,p_string);
           }

           p8 = strstr(p_string, "else");
           if(!p8)
           {
              skip_read = 1;
              inside_if6 = 0;
              if_start6 = 0;
              if_level--;
              p7 = strstr(p_string, "}");
              if(p7)
              {
                 skip_read = 0;
                 if_level--;
                 convert = 1;
                 return;
              }

              convert = 1;
              return;
           }

           if(p8)
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z_parameter.c c2_param_ct ELSE-6");
                 trace_rec_1();
              }
              if_else_flag6 = 1;
              if(wif_ct > 0)
              {
                 for(I = 0; I < wif_ct; I++)
                 {
                    if(if_start6 == w_if_table[I].wif_rct)
                    {
                       w_if_table[I].wif_else = rct;
                    }
                 }
              }
           }
        }
     }

/* *** END OF 6TH FOR LOOP *** */


/* *** START OF 7TH IF LOOP *** */
     if((param_r > 0) && (if_level == 7) && (inside_if7 == 1))
     {
        if_parm7 = 0;

        /* test if_parm7 == 0, then update if_table */
        if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 1))
        {
           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start7 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof2 = rct;
                 }
              }
           }
           inside_if7 = 0;
           if_start7 = 0;
           if_else_flag7 = 0;
           if_level--;
        }

        if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 0))
        {
           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start7 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof1 = rct;
                    w_if_table[I].wif_else = 0;
                    w_if_table[I].wif_eof2 = 0;
                    break;
                 }
              }
           }

           fgets(p_string, BUFSIZE, pgm);
           rct++;
           printf("Pass 2 IF7 rct = %d p_string = %s",rct,p_string);

           p8 = strstr(p_string, "else");
           if(!p8)
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z_parameter.c c2_param_ct ELSE-7");
                 trace_rec_1();
              }
              skip_read = 1;
              inside_if7 = 0;
              if_start7 = 0;
              if_level--;
              p7 = strstr(p_string, "}");
              if(p7)
              {
                 skip_read = 0;
                 if_level--;
                 convert = 1;
                 return;
              }

              convert = 1;
              return;
           }

           if(p8)
           {
              if_else_flag7 = 1;
              if(wif_ct > 0)
              {
                 for(I = 0; I < wif_ct; I++)
                 {
                    if(if_start7 == w_if_table[I].wif_rct)
                    {
                       w_if_table[I].wif_else = rct;
                    }
                 }
              }
           }
        }
     }

/* *** END OF 7TH FOR LOOP *** */

/* *** START OF 8TH IF LOOP *** */
     if((param_r > 0) && (if_level == 8) && (inside_if8 == 1))
     {
        if_parm8 = 0;

        /* test if_parm8 == 0, then update if_table */
        if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 1))
        {
           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start8 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof2 = rct;
                 }
              }
           }
           inside_if8 = 0;
           if_start8 = 0;
           if_else_flag8 = 0;
           if_level--;
        }

        if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 0))
        {
           if(wif_ct > 0)
           {
              for(I = 0; I < wif_ct; I++)
              {
                 if(if_start8 == w_if_table[I].wif_rct)
                 {
                    w_if_table[I].wif_eof1 = rct;
                    w_if_table[I].wif_else = 0;
                    w_if_table[I].wif_eof2 = 0;
                 }
              }
           }

           fgets(p_string, BUFSIZE, pgm);
           printf("Pass 2 IF8 rct = %d p_string = %s",rct,p_string);
           rct++;

           p8 = strstr(p_string, "else");
           if(!p8)
           {
              if(trace_flag == 1)
              {
                 strcpy(trace_1, "c2z_parameter.c c2_param_ct ELSE-8");
                 trace_rec_1();
              }
              skip_read = 1;
              inside_if8 = 0;
              if_start8 = 0;
              if_level--;
              p7 = strstr(p_string, "}");
              if(p7)
              {
                 skip_read = 0;
                 if_level--;
                 convert = 1;
                 return;
              }
              convert = 1;
              return;
	}

       if(p8)
       {
          if_else_flag8 = 1;
          if(wif_ct > 0)
          {
             for(I = 0; I < wif_ct; I++)
             {
                if(if_start8 == w_if_table[I].wif_rct)
                {
                   w_if_table[I].wif_else = rct;
                }
             }
          }
       }
    }
}

/* *** END OF 8TH FOR LOOP *** */


/* ************************************** START OF 9TH IF LOOP ****************************************** */
						if((param_r > 0) && (if_level == 9) && (inside_if9 == 1))
							{
								if_parm9 = 0;
							
								/* test if_parm9 == 0, then update if_table */

								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag9 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										inside_if9 = 0;
										if_start9 = 0;
										if_else_flag9 = 0;
										if_level--;
									}

								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}
								
										fgets(p_string, BUFSIZE, pgm);
                                                       printf("Pass 2 IF9 rct = %d p_string = %s",rct,p_string);
 
										rct++;
										
										p8 = strstr(p_string, "else");
										if(!p8)
											{
                                                                                   skip_read = 1;
												inside_if9 = 0;
												if_start9 = 0;
												if_level--;

					 p7 = strstr(p_string, "}");
              if(p7)
              {
                 skip_read = 0;
                 if_level--;
                 convert = 1;
                 return;
              }
						
                                            convert = 1;
                                                 return;

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2z_parameter.c c2_param_ct ELSE-9");
														trace_rec_1();
													}

												if_else_flag9 = 1;
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start9 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;
																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 9TH FOR LOOP ******************************************* */


/* ************************************** START OF 10TH IF LOOP ***************************************** */
						if((param_r > 0) && (if_level == 10) && (inside_if10 == 1))
							{
								if_parm10 = 0;
							
								/* test if_parm10 == 0, then update if_table */

								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										inside_if10 = 0;
										if_start10 = 0;
										if_else_flag10 = 0;
										if_level--;
									}

								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}
								
										fgets(p_string, BUFSIZE, pgm);
                                        printf("Pass 2 IF10 rct = %d p_string = %s",rct,p_string);

										rct++;
										
										p8 = strstr(p_string, "else");
										if(!p8)
											{
                                                                         skip_read = 1;
												inside_if10 = 0;
												if_start10 = 0;
												if_level--;
					 p7 = strstr(p_string, "}");
              if(p7)
              {
                 skip_read = 0;
                 if_level--;
                 convert = 1;
                 return;
              }

											
                                             convert = 1;
                                             return;

											}

										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2z_parameter.c c2_param_ct ELSE-10");
														trace_rec_1();
													}

												if_else_flag10 = 1;
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start10 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;
																	}
															}
													}
											}
									}
							}
/* ************************************** END OF 10TH FOR LOOP ******************************************* */


/* ************************************** START OF WHILE LOOP ****************************************** */
						if((param_l > 0) && (while_level == 1) && (inside_wh1 == 1))
							{
								while_parm1++;
							}
						if((param_l > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2++;
							}
						if((param_l > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3++;
							}
						if((param_l > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4++;
							}
						if((param_l > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5++;
							}
						if((param_l > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6++;
							}
						if((param_l > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7++;
							}
						if((param_l > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8++;
							}
						if((param_l > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9++;
							}
						if((param_l > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10++;
							}

/* ************************************** START OF 1TH WHILE LOOP *************************************** */
					if((param_r > 0) && (while_level == 1) && (inside_wh1 == 1))
							{
								while_parm1 = 0;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_parameter.c c2_param_ct WHILE-1");
										trace_rec_1();
									}

								/* test while_parm1 == 0, then update if_table */

								if((while_parm1 == 0) && (inside_wh1 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start1 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										inside_wh1 = 0;
										while_start1 = 0;
										while_level--;
									}
							}


/* ************************************** END OF 1ST WHILE LOOP ***************************************** */

/* ************************************** START OF 2ND WHILE LOOP *************************************** */
					if((param_r > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2 = 0;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_parameter.c c2_param_ct WHILE-2");
										trace_rec_1();
									}

								/* test while_parm2 == 0, then update if_table */

								if((while_parm2 == 0) && (inside_wh2 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start2 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										inside_wh2 = 0;
										while_start2 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 2ND WHILE LOOP ***************************************** */						

/* ************************************** START OF 3ND WHILE LOOP *************************************** */
					if((param_r > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3 = 0;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_parameter.c c2_param_ct WHILE-3");
										trace_rec_1();
									}

								/* test while_parm3 == 0, then update if_table */

								if((while_parm3 == 0) && (inside_wh3 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start3 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										inside_wh3 = 0;
										while_start3 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 3ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 4ND WHILE LOOP *************************************** */
					if((param_r > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4 = 0;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_parameter.c c2_param_ct WHILE-4");
										trace_rec_1();
									}

								/* test while_parm4 == 0, then update if_table */

								if((while_parm4 == 0) && (inside_wh4 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start4 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										inside_wh4 = 0;
										while_start4 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 4ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 5ND WHILE LOOP *************************************** */
					if((param_r > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5 = 0;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_parameter.c c2_param_ct WHILE-5");
										trace_rec_1();
									}

								/* test while_parm5 == 0, then update if_table */

								if((while_parm5 == 0) && (inside_wh5 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start5 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										inside_wh5 = 0;
										while_start5 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 5ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 6ND WHILE LOOP *************************************** */
					if((param_r > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6 = 0;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_parameter.c c2_param_ct WHILE-6");
										trace_rec_1();
									}

								/* test while_parm6 == 0, then update if_table */

								if((while_parm6 == 0) && (inside_wh6 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start6 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										inside_wh6 = 0;
										while_start6 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 6ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 7ND WHILE LOOP *************************************** */
					if((param_r > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7 = 0;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_parameter.c c2_param_ct WHILE-7");
										trace_rec_1();
									}

								/* test while_parm7 == 0, then update if_table */

								if((while_parm7 == 0) && (inside_wh7 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start7 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										inside_wh7 = 0;
										while_start7 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 7ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 8ND WHILE LOOP *************************************** */
					if((param_r > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8 = 0;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_parameter.c c2_param_ct WHILE-8");
										trace_rec_1();
									}

								/* test while_parm8 == 0, then update if_table */

								if((while_parm8 == 0) && (inside_wh8 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start8 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										inside_wh8 = 0;
										while_start8 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 8ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 9ND WHILE LOOP *************************************** */
					if((param_r > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9 = 0;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_parameter.c c2_param_ct WHILE-9");
										trace_rec_1();
									}

								/* test while_parm9 == 0, then update if_table */

								if((while_parm9 == 0) && (inside_wh9 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start9 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										inside_wh9 = 0;
										while_start9 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 9ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 10ND WHILE LOOP *************************************** */
					if((param_r > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10 = 0;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2z_parameter.c c2_param_ct WHILE-10");
										trace_rec_1();
									}

								/* test while_parm10 == 0, then update if_table */

								if((while_parm10 == 0) && (inside_wh10== 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start10 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										inside_wh10 = 0;
										while_start10 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 10ND WHILE LOOP ***************************************** */		

					}

/* ************************************** END OF WHILE LOOP ********************************************* */

void c2_param_ct_2()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2_param_ct_2 ");
				trace_rec_1();
			}

		int I = 0;
		int x = 0;
		int x1 = 0;
		int s = 0;

		char ch;
		char *p7, *p8;

		x = 0;
		x1 = 0;
		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '{')
					x++;
				if(ch == '}')
					x1++;
			}

		
		/* test for if counts */
		if((x > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1++;
			}

		if((x > 0) && (if_level == 2) && (inside_if2 == 1))
			{
				if_parm2++;
			}

		if((x > 0) && (if_level == 3) && (inside_if3 == 1))
			{
				if_parm3++;
			}

		if((x > 0) && (if_level == 4) && (inside_if4 == 1))
			{
				if_parm4++;
			}

		if((x > 0) && (if_level == 5) && (inside_if5 == 1))
			{
				if_parm5++;
			}

		if((x > 0) && (if_level == 6) && (inside_if6 == 1))
			{
				if_parm6++;
			}

		if((x > 0) && (if_level == 7) && (inside_if7 == 1))
			{
				if_parm7++;
			}

		if((x > 0) && (if_level == 8) && (inside_if8 == 1))
			{
				if_parm8++;
			}

		if((x > 0) && (if_level == 9) && (inside_if9 == 1))
			{
				if_parm9++;
			}

		if((x > 0) && (if_level == 10) && (inside_if10 == 1))
			{
				if_parm10++;
			}


/* ******************************* START OF 1ST IF LOOP	*************************************** */
		if((x1 > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1--;
							
				/* test if_parm1 == 0, then update if_table */
								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-1 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}


										/* clear flags  */
										inside_if1 = 0;
										if_start1 = 0;
										if_else_flag1 = 0;
										if_level--;
									}


								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 0))
									{

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
																break;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
                                               printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										rct++;
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-2 READ ");
												trace_rec_1();
											}

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct if-2 NOREAD ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if1 = 0;
												if_start1 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_3();
											}
		
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag1 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start1 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;

																	}
															}
													}
											}


									}
							}

/* ************************************** END OF 1ST FOR LOOP  ******************************************* */

/* ************************************** START OF 2ND IF LOOP ******************************************* */


						if((x1 > 0) && (if_level == 2) && (inside_if2 == 1))
							{

								if_parm2--;
							
								/* test if_parm2 == 0, then update if_table */

								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct_2 if-2 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if2 = 0;
										if_start2 = 0;
										if_else_flag2 = 0;
										if_level--;
									}


								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
                                                             printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 if-2 READ ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if2 = 0;
												if_start2 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_3();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag2 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start2 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 2ND FOR LOOP ******************************************* */


/* ************************************** START OF 3RD IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 3) && (inside_if3 == 1))
							{
								if_parm3--;
							
								/* test if_parm3 == 0, then update if_table */

								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if3 = 0;
										if_start3 = 0;
										if_else_flag3 = 0;
										if_level--;
									}


								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
                                                      printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												skip_read = 1;
												inside_if3 = 0;
												if_start3 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_3();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-3 ");
														trace_rec_1();
													}

												if_else_flag3 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start3 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 3RD FOR LOOP ******************************************* */


/* ************************************** START OF 4TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 4) && (inside_if4 == 1))
							{
								if_parm4--;
							
								/* test if_parm4 == 0, then update if_table */

								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if4 = 0;
										if_start4 = 0;
										if_else_flag4 = 0;
										if_level--;
									}


								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
                                                  printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-4 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if4 = 0;
												if_start4 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_3();

											}
										if(p8)
											{
												if_else_flag4 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start4 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 4TH FOR LOOP ******************************************* */


/* ************************************** START OF 5TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 5) && (inside_if5 == 1))
							{
								if_parm4--;
							
								/* test if_parm5 == 0, then update if_table */

								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if5 = 0;
										if_start5 = 0;
										if_else_flag5 = 0;
										if_level--;
									}


								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);

										rct++;
                                                          printf("Pass 2 rct = %d p_string = %s",rct,p_string);
 
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if5 = 0;
												if_start5 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_3();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-5 ");
														trace_rec_1();
													}

												if_else_flag5 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start5 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 5TH FOR LOOP ******************************************* */


/* ************************************** START OF 6TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 6) && (inside_if6 == 1))
							{
								if_parm6--;
							
								/* test if_parm6 == 0, then update if_table */

								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if6 = 0;
										if_start6 = 0;
										if_else_flag6 = 0;
										if_level--;
									}


								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
                                                               printf("Pass 2 rct = %d p_string = %s",rct,p_string);
        
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if6 = 0;
												if_start6 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_3();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-6 ");
														trace_rec_1();
													}

												if_else_flag6 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start6 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 6TH FOR LOOP ******************************************* */


/* ************************************** START OF 7TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 7) && (inside_if7 == 1))
							{
								if_parm7--;
							
								/* test if_parm7 == 0, then update if_table */

								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if7 = 0;
										if_start7 = 0;
										if_else_flag7 = 0;
										if_level--;
									}


								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
                                                               printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-7 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if7 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_3();

											}
										if(p8)
											{
												if_else_flag7 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start7 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 7TH FOR LOOP ******************************************* */


/* ************************************** START OF 8TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 8) && (inside_if8 == 1))
							{
								if_parm8--;
							
								/* test if_parm8 == 0, then update if_table */

								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if8 = 0;
										if_start8 = 0;
										if_else_flag8 = 0;
										if_level--;
									}


								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
                                                                      printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-8 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if8 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_3();

											}
										if(p8)
											{
												if_else_flag8 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start8 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 8TH FOR LOOP ******************************************* */



/* ************************************** START OF 9TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 9) && (inside_if9 == 1))
							{
								if_parm9--;
							
								/* test if_parm9 == 0, then update if_table */

								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag9 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if9 = 0;
										if_start9 = 0;
										if_else_flag9 = 0;
										if_level--;
									}


								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
                                                                     printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if9 = 0;
												if_start9 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_3();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-9 ");
														trace_rec_1();
													}

												if_else_flag9 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start9 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 9TH FOR LOOP ******************************************* */


/* ************************************** START OF 10TH IF LOOP ***************************************** */
						if((x1 > 0) && (if_level == 10) && (inside_if10 == 1))
							{
								if_parm10--;
							
								/* test if_parm10 == 0, then update if_table */

								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if10 = 0;
										if_start10 = 0;
										if_else_flag10 = 0;
										if_level--;
									}


								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
                                                                       printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if10 = 0;
												if_start10 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_3();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-10 ");
														trace_rec_1();
													}

												if_else_flag10 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start10 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}
/* ************************************** END OF 10TH FOR LOOP ******************************************* */


/* ************************************** START OF WHILE LOOP ****************************************** */

						if((x > 0) && (while_level == 1) && (inside_wh1 == 1))
							{
								while_parm1++;
							}
						if((x > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2++;
							}
						if((x > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3++;
							}
						if((x > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4++;
							}
						if((x > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5++;
							}
						if((x > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6++;
							}
						if((x > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7++;
							}
						if((x > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8++;
							}
						if((x > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9++;
							}
						if((x > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10++;
							}

/* ************************************** START OF 1TH WHILE LOOP *************************************** */
					if((x1 > 0) && (while_level == 1) && (inside_wh1 == 1))
							{

								while_parm1--;

								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-1 ");
										trace_rec_1();
									}

								/* test while_parm1 == 0, then update if_table */

								if((while_parm1 == 0) && (inside_wh1 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start1 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh1 = 0;
										while_start1 = 0;
										while_level--;
									}
							}


/* ************************************** END OF 1ST WHILE LOOP ***************************************** */



/* ************************************** START OF 2ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-2 ");
										trace_rec_1();
									}

								/* test while_parm2 == 0, then update if_table */

								if((while_parm2 == 0) && (inside_wh2 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start2 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh2 = 0;
										while_start2 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 2ND WHILE LOOP ***************************************** */						


/* ************************************** START OF 3ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-3 ");
										trace_rec_1();
									}

								/* test while_parm3 == 0, then update if_table */

								if((while_parm3 == 0) && (inside_wh3 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start3 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh3 = 0;
										while_start3 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 3ND WHILE LOOP ***************************************** */		



/* ************************************** START OF 4ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-4 ");
										trace_rec_1();
									}

								/* test while_parm4 == 0, then update if_table */

								if((while_parm4 == 0) && (inside_wh4 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start4 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh4 = 0;
										while_start4 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 4ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 5ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-5 ");
										trace_rec_1();
									}

								/* test while_parm5 == 0, then update if_table */

								if((while_parm5 == 0) && (inside_wh5 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start5 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh5 = 0;
										while_start5 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 5ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 6ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-6 ");
										trace_rec_1();
									}

								/* test while_parm6 == 0, then update if_table */

								if((while_parm6 == 0) && (inside_wh6 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start6 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh6 = 0;
										while_start6 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 6ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 7ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-7 ");
										trace_rec_1();
									}

								/* test while_parm7 == 0, then update if_table */

								if((while_parm7 == 0) && (inside_wh7 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start7 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh7 = 0;
										while_start7 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 7ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 8ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-8 ");
										trace_rec_1();
									}

								/* test while_parm8 == 0, then update if_table */

								if((while_parm8 == 0) && (inside_wh8 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start8 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh8 = 0;
										while_start8 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 8ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 9ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-9 ");
										trace_rec_1();
									}

								/* test while_parm9 == 0, then update if_table */

								if((while_parm9 == 0) && (inside_wh9 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start9 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh9 = 0;
										while_start9 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 9ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 10ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-10 ");
										trace_rec_1();
									}

								/* test while_parm10 == 0, then update if_table */

								if((while_parm10 == 0) && (inside_wh10== 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start10 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh10 = 0;
										while_start10 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 10ND WHILE LOOP ***************************************** */		


					}
/* ************************************** END OF WHILE LOOP ********************************************* */

	

void c2_param_ct_3()
	{

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2_param_ct_3 ");
				trace_rec_1();
			}

		int I = 0;
		int x = 0;
		int x1 = 0;
		int s = 0;

		char ch;
		char *p7, *p8;

		x = 0;
		x1 = 0;
		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '{')
					x++;
				if(ch == '}')
					x1++;
			}

		
		/* test for if counts */
		if((x > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1++;
			}

		if((x > 0) && (if_level == 2) && (inside_if2 == 1))
			{
				if_parm2++;
			}

		if((x > 0) && (if_level == 3) && (inside_if3 == 1))
			{
				if_parm3++;
			}

		if((x > 0) && (if_level == 4) && (inside_if4 == 1))
			{
				if_parm4++;
			}

		if((x > 0) && (if_level == 5) && (inside_if5 == 1))
			{
				if_parm5++;
			}

		if((x > 0) && (if_level == 6) && (inside_if6 == 1))
			{
				if_parm6++;
			}

		if((x > 0) && (if_level == 7) && (inside_if7 == 1))
			{
				if_parm7++;
			}

		if((x > 0) && (if_level == 8) && (inside_if8 == 1))
			{
				if_parm8++;
			}

		if((x > 0) && (if_level == 9) && (inside_if9 == 1))
			{
				if_parm9++;
			}

		if((x > 0) && (if_level == 10) && (inside_if10 == 1))
			{
				if_parm10++;
			}


/* ******************************* START OF 1ST IF LOOP	*************************************** */
		if((x1 > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1--;
							
				/* test if_parm1 == 0, then update if_table */
								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-1 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}


										/* clear flags  */
										inside_if1 = 0;
										if_start1 = 0;
										if_else_flag1 = 0;
										if_level--;
									}


								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 0))
									{

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
																break;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
                                                                   printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-2 READ ");
												trace_rec_1();
											}

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct if-2 NOREAD ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if1 = 0;
												if_start1 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_4();
											}
		
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag1 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start1 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;

																	}
															}
													}
											}


									}
							}

/* ************************************** END OF 1ST FOR LOOP  ******************************************* */

/* ************************************** START OF 2ND IF LOOP ******************************************* */


						if((x1 > 0) && (if_level == 2) && (inside_if2 == 1))
							{

								if_parm2--;
							
								/* test if_parm2 == 0, then update if_table */

								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct_2 if-2 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if2 = 0;
										if_start2 = 0;
										if_else_flag2 = 0;
										if_level--;
									}


								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
                                                                    printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 if-2 READ ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if2 = 0;
												if_start2 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_4();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag2 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start2 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 2ND FOR LOOP ******************************************* */


/* ************************************** START OF 3RD IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 3) && (inside_if3 == 1))
							{
								if_parm3--;
							
								/* test if_parm3 == 0, then update if_table */

								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if3 = 0;
										if_start3 = 0;
										if_else_flag3 = 0;
										if_level--;
									}


								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
                                                                        printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												skip_read = 1;
												inside_if3 = 0;
												if_start3 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_4();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-3 ");
														trace_rec_1();
													}

												if_else_flag3 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start3 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 3RD FOR LOOP ******************************************* */


/* ************************************** START OF 4TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 4) && (inside_if4 == 1))
							{
								if_parm4--;
							
								/* test if_parm4 == 0, then update if_table */

								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if4 = 0;
										if_start4 = 0;
										if_else_flag4 = 0;
										if_level--;
									}


								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
                                                                      printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-4 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if4 = 0;
												if_start4 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_4();

											}
										if(p8)
											{
												if_else_flag4 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start4 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 4TH FOR LOOP ******************************************* */


/* ************************************** START OF 5TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 5) && (inside_if5 == 1))
							{
								if_parm4--;
							
								/* test if_parm5 == 0, then update if_table */

								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if5 = 0;
										if_start5 = 0;
										if_else_flag5 = 0;
										if_level--;
									}


								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;

                                                                   printf("Pass 2 rct = %d p_string = %s",rct,p_string);
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if5 = 0;
												if_start5 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_4();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-5 ");
														trace_rec_1();
													}

												if_else_flag5 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start5 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 5TH FOR LOOP ******************************************* */


/* ************************************** START OF 6TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 6) && (inside_if6 == 1))
							{
								if_parm6--;
							
								/* test if_parm6 == 0, then update if_table */

								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if6 = 0;
										if_start6 = 0;
										if_else_flag6 = 0;
										if_level--;
									}


								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
                                                                     printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if6 = 0;
												if_start6 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_4();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-6 ");
														trace_rec_1();
													}

												if_else_flag6 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start6 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 6TH FOR LOOP ******************************************* */


/* ************************************** START OF 7TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 7) && (inside_if7 == 1))
							{
								if_parm7--;
							
								/* test if_parm7 == 0, then update if_table */

								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if7 = 0;
										if_start7 = 0;
										if_else_flag7 = 0;
										if_level--;
									}


								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
                                                                       printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-7 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if7 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_4();

											}
										if(p8)
											{
												if_else_flag7 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start7 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 7TH FOR LOOP ******************************************* */


/* ************************************** START OF 8TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 8) && (inside_if8 == 1))
							{
								if_parm8--;
							
								/* test if_parm8 == 0, then update if_table */

								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if8 = 0;
										if_start8 = 0;
										if_else_flag8 = 0;
										if_level--;
									}


								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
                                                                      printf("Pass 2 rct = %d p_string = %s",rct,p_string);

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-8 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if8 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_4();

											}
										if(p8)
											{
												if_else_flag8 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start8 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 8TH FOR LOOP ******************************************* */



/* ************************************** START OF 9TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 9) && (inside_if9 == 1))
							{
								if_parm9--;
							
								/* test if_parm9 == 0, then update if_table */

								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag9 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if9 = 0;
										if_start9 = 0;
										if_else_flag9 = 0;
										if_level--;
									}


								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if9 = 0;
												if_start9 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_4();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-9 ");
														trace_rec_1();
													}

												if_else_flag9 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start9 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 9TH FOR LOOP ******************************************* */


/* ************************************** START OF 10TH IF LOOP ***************************************** */
						if((x1 > 0) && (if_level == 10) && (inside_if10 == 1))
							{
								if_parm10--;
							
								/* test if_parm10 == 0, then update if_table */

								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if10 = 0;
										if_start10 = 0;
										if_else_flag10 = 0;
										if_level--;
									}


								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if10 = 0;
												if_start10 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_4();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-10 ");
														trace_rec_1();
													}

												if_else_flag10 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start10 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}
/* ************************************** END OF 10TH FOR LOOP ******************************************* */


/* ************************************** START OF WHILE LOOP ****************************************** */

						if((x > 0) && (while_level == 1) && (inside_wh1 == 1))
							{
								while_parm1++;
							}
						if((x > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2++;
							}
						if((x > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3++;
							}
						if((x > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4++;
							}
						if((x > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5++;
							}
						if((x > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6++;
							}
						if((x > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7++;
							}
						if((x > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8++;
							}
						if((x > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9++;
							}
						if((x > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10++;
							}

/* ************************************** START OF 1TH WHILE LOOP *************************************** */
					if((x1 > 0) && (while_level == 1) && (inside_wh1 == 1))
							{

								while_parm1--;

								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-1 ");
										trace_rec_1();
									}

								/* test while_parm1 == 0, then update if_table */

								if((while_parm1 == 0) && (inside_wh1 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start1 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh1 = 0;
										while_start1 = 0;
										while_level--;
									}
							}


/* ************************************** END OF 1ST WHILE LOOP ***************************************** */



/* ************************************** START OF 2ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-2 ");
										trace_rec_1();
									}

								/* test while_parm2 == 0, then update if_table */

								if((while_parm2 == 0) && (inside_wh2 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start2 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh2 = 0;
										while_start2 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 2ND WHILE LOOP ***************************************** */						


/* ************************************** START OF 3ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-3 ");
										trace_rec_1();
									}

								/* test while_parm3 == 0, then update if_table */

								if((while_parm3 == 0) && (inside_wh3 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start3 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh3 = 0;
										while_start3 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 3ND WHILE LOOP ***************************************** */		



/* ************************************** START OF 4ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-4 ");
										trace_rec_1();
									}

								/* test while_parm4 == 0, then update if_table */

								if((while_parm4 == 0) && (inside_wh4 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start4 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh4 = 0;
										while_start4 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 4ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 5ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-5 ");
										trace_rec_1();
									}

								/* test while_parm5 == 0, then update if_table */

								if((while_parm5 == 0) && (inside_wh5 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start5 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh5 = 0;
										while_start5 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 5ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 6ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-6 ");
										trace_rec_1();
									}

								/* test while_parm6 == 0, then update if_table */

								if((while_parm6 == 0) && (inside_wh6 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start6 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh6 = 0;
										while_start6 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 6ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 7ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-7 ");
										trace_rec_1();
									}

								/* test while_parm7 == 0, then update if_table */

								if((while_parm7 == 0) && (inside_wh7 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start7 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh7 = 0;
										while_start7 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 7ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 8ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-8 ");
										trace_rec_1();
									}

								/* test while_parm8 == 0, then update if_table */

								if((while_parm8 == 0) && (inside_wh8 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start8 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh8 = 0;
										while_start8 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 8ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 9ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-9 ");
										trace_rec_1();
									}

								/* test while_parm9 == 0, then update if_table */

								if((while_parm9 == 0) && (inside_wh9 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start9 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh9 = 0;
										while_start9 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 9ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 10ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-10 ");
										trace_rec_1();
									}

								/* test while_parm10 == 0, then update if_table */

								if((while_parm10 == 0) && (inside_wh10== 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start10 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh10 = 0;
										while_start10 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 10ND WHILE LOOP ***************************************** */		


					}
/* ************************************** END OF WHILE LOOP ********************************************* */


void c2_param_ct_4()
	{

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2_param_ct_4 ");
				trace_rec_1();
			}

		int I = 0;
		int x = 0;
		int x1 = 0;
		int s = 0;

		char ch;
		char *p7, *p8;

		x = 0;
		x1 = 0;
		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '{')
					x++;
				if(ch == '}')
					x1++;
			}

		
		/* test for if counts */
		if((x > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1++;
			}

		if((x > 0) && (if_level == 2) && (inside_if2 == 1))
			{
				if_parm2++;
			}

		if((x > 0) && (if_level == 3) && (inside_if3 == 1))
			{
				if_parm3++;
			}

		if((x > 0) && (if_level == 4) && (inside_if4 == 1))
			{
				if_parm4++;
			}

		if((x > 0) && (if_level == 5) && (inside_if5 == 1))
			{
				if_parm5++;
			}

		if((x > 0) && (if_level == 6) && (inside_if6 == 1))
			{
				if_parm6++;
			}

		if((x > 0) && (if_level == 7) && (inside_if7 == 1))
			{
				if_parm7++;
			}

		if((x > 0) && (if_level == 8) && (inside_if8 == 1))
			{
				if_parm8++;
			}

		if((x > 0) && (if_level == 9) && (inside_if9 == 1))
			{
				if_parm9++;
			}

		if((x > 0) && (if_level == 10) && (inside_if10 == 1))
			{
				if_parm10++;
			}


/* ******************************* START OF 1ST IF LOOP	*************************************** */
		if((x1 > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1--;
							
				/* test if_parm1 == 0, then update if_table */
								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-1 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}


										/* clear flags  */
										inside_if1 = 0;
										if_start1 = 0;
										if_else_flag1 = 0;
										if_level--;
									}


								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 0))
									{

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
																break;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-2 READ ");
												trace_rec_1();
											}

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct if-2 NOREAD ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if1 = 0;
												if_start1 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_5();
											}
		
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag1 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start1 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;

																	}
															}
													}
											}


									}
							}

/* ************************************** END OF 1ST FOR LOOP  ******************************************* */

/* ************************************** START OF 2ND IF LOOP ******************************************* */


						if((x1 > 0) && (if_level == 2) && (inside_if2 == 1))
							{

								if_parm2--;
							
								/* test if_parm2 == 0, then update if_table */

								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct_2 if-2 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if2 = 0;
										if_start2 = 0;
										if_else_flag2 = 0;
										if_level--;
									}


								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 if-2 READ ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if2 = 0;
												if_start2 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_5();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag2 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start2 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 2ND FOR LOOP ******************************************* */


/* ************************************** START OF 3RD IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 3) && (inside_if3 == 1))
							{
								if_parm3--;
							
								/* test if_parm3 == 0, then update if_table */

								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if3 = 0;
										if_start3 = 0;
										if_else_flag3 = 0;
										if_level--;
									}


								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												skip_read = 1;
												inside_if3 = 0;
												if_start3 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_5();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-3 ");
														trace_rec_1();
													}

												if_else_flag3 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start3 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 3RD FOR LOOP ******************************************* */


/* ************************************** START OF 4TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 4) && (inside_if4 == 1))
							{
								if_parm4--;
							
								/* test if_parm4 == 0, then update if_table */

								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if4 = 0;
										if_start4 = 0;
										if_else_flag4 = 0;
										if_level--;
									}


								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-4 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if4 = 0;
												if_start4 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_5();

											}
										if(p8)
											{
												if_else_flag4 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start4 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 4TH FOR LOOP ******************************************* */


/* ************************************** START OF 5TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 5) && (inside_if5 == 1))
							{
								if_parm4--;
							
								/* test if_parm5 == 0, then update if_table */

								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if5 = 0;
										if_start5 = 0;
										if_else_flag5 = 0;
										if_level--;
									}


								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if5 = 0;
												if_start5 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_5();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-5 ");
														trace_rec_1();
													}

												if_else_flag5 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start5 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 5TH FOR LOOP ******************************************* */


/* ************************************** START OF 6TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 6) && (inside_if6 == 1))
							{
								if_parm6--;
							
								/* test if_parm6 == 0, then update if_table */

								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if6 = 0;
										if_start6 = 0;
										if_else_flag6 = 0;
										if_level--;
									}


								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if6 = 0;
												if_start6 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_5();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-6 ");
														trace_rec_1();
													}

												if_else_flag6 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start6 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 6TH FOR LOOP ******************************************* */


/* ************************************** START OF 7TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 7) && (inside_if7 == 1))
							{
								if_parm7--;
							
								/* test if_parm7 == 0, then update if_table */

								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if7 = 0;
										if_start7 = 0;
										if_else_flag7 = 0;
										if_level--;
									}


								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-7 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if7 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_5();

											}
										if(p8)
											{
												if_else_flag7 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start7 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 7TH FOR LOOP ******************************************* */


/* ************************************** START OF 8TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 8) && (inside_if8 == 1))
							{
								if_parm8--;
							
								/* test if_parm8 == 0, then update if_table */

								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if8 = 0;
										if_start8 = 0;
										if_else_flag8 = 0;
										if_level--;
									}


								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-8 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if8 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_5();

											}
										if(p8)
											{
												if_else_flag8 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start8 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 8TH FOR LOOP ******************************************* */



/* ************************************** START OF 9TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 9) && (inside_if9 == 1))
							{
								if_parm9--;
							
								/* test if_parm9 == 0, then update if_table */

								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag9 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if9 = 0;
										if_start9 = 0;
										if_else_flag9 = 0;
										if_level--;
									}


								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if9 = 0;
												if_start9 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_5();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-9 ");
														trace_rec_1();
													}

												if_else_flag9 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start9 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 9TH FOR LOOP ******************************************* */


/* ************************************** START OF 10TH IF LOOP ***************************************** */
						if((x1 > 0) && (if_level == 10) && (inside_if10 == 1))
							{
								if_parm10--;
							
								/* test if_parm10 == 0, then update if_table */

								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if10 = 0;
										if_start10 = 0;
										if_else_flag10 = 0;
										if_level--;
									}


								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if10 = 0;
												if_start10 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_5();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-10 ");
														trace_rec_1();
													}

												if_else_flag10 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start10 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}
/* ************************************** END OF 10TH FOR LOOP ******************************************* */


/* ************************************** START OF WHILE LOOP ****************************************** */

						if((x > 0) && (while_level == 1) && (inside_wh1 == 1))
							{
								while_parm1++;
							}
						if((x > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2++;
							}
						if((x > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3++;
							}
						if((x > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4++;
							}
						if((x > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5++;
							}
						if((x > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6++;
							}
						if((x > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7++;
							}
						if((x > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8++;
							}
						if((x > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9++;
							}
						if((x > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10++;
							}

/* ************************************** START OF 1TH WHILE LOOP *************************************** */
					if((x1 > 0) && (while_level == 1) && (inside_wh1 == 1))
							{

								while_parm1--;

								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-1 ");
										trace_rec_1();
									}

								/* test while_parm1 == 0, then update if_table */

								if((while_parm1 == 0) && (inside_wh1 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start1 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh1 = 0;
										while_start1 = 0;
										while_level--;
									}
							}


/* ************************************** END OF 1ST WHILE LOOP ***************************************** */



/* ************************************** START OF 2ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-2 ");
										trace_rec_1();
									}

								/* test while_parm2 == 0, then update if_table */

								if((while_parm2 == 0) && (inside_wh2 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start2 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh2 = 0;
										while_start2 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 2ND WHILE LOOP ***************************************** */						


/* ************************************** START OF 3ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-3 ");
										trace_rec_1();
									}

								/* test while_parm3 == 0, then update if_table */

								if((while_parm3 == 0) && (inside_wh3 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start3 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh3 = 0;
										while_start3 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 3ND WHILE LOOP ***************************************** */		



/* ************************************** START OF 4ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-4 ");
										trace_rec_1();
									}

								/* test while_parm4 == 0, then update if_table */

								if((while_parm4 == 0) && (inside_wh4 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start4 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh4 = 0;
										while_start4 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 4ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 5ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-5 ");
										trace_rec_1();
									}

								/* test while_parm5 == 0, then update if_table */

								if((while_parm5 == 0) && (inside_wh5 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start5 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh5 = 0;
										while_start5 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 5ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 6ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-6 ");
										trace_rec_1();
									}

								/* test while_parm6 == 0, then update if_table */

								if((while_parm6 == 0) && (inside_wh6 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start6 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh6 = 0;
										while_start6 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 6ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 7ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-7 ");
										trace_rec_1();
									}

								/* test while_parm7 == 0, then update if_table */

								if((while_parm7 == 0) && (inside_wh7 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start7 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh7 = 0;
										while_start7 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 7ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 8ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-8 ");
										trace_rec_1();
									}

								/* test while_parm8 == 0, then update if_table */

								if((while_parm8 == 0) && (inside_wh8 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start8 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh8 = 0;
										while_start8 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 8ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 9ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-9 ");
										trace_rec_1();
									}

								/* test while_parm9 == 0, then update if_table */

								if((while_parm9 == 0) && (inside_wh9 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start9 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh9 = 0;
										while_start9 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 9ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 10ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-10 ");
										trace_rec_1();
									}

								/* test while_parm10 == 0, then update if_table */

								if((while_parm10 == 0) && (inside_wh10== 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start10 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh10 = 0;
										while_start10 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 10ND WHILE LOOP ***************************************** */		


					}
/* ************************************** END OF WHILE LOOP ********************************************* */




void c2_param_ct_5()
	{

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2_param_ct_5 ");
				trace_rec_1();
			}

		int I = 0;
		int x = 0;
		int x1 = 0;
		int s = 0;

		char ch;
		char *p7, *p8;

		x = 0;
		x1 = 0;
		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '{')
					x++;
				if(ch == '}')
					x1++;
			}

		
		/* test for if counts */
		if((x > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1++;
			}

		if((x > 0) && (if_level == 2) && (inside_if2 == 1))
			{
				if_parm2++;
			}

		if((x > 0) && (if_level == 3) && (inside_if3 == 1))
			{
				if_parm3++;
			}

		if((x > 0) && (if_level == 4) && (inside_if4 == 1))
			{
				if_parm4++;
			}

		if((x > 0) && (if_level == 5) && (inside_if5 == 1))
			{
				if_parm5++;
			}

		if((x > 0) && (if_level == 6) && (inside_if6 == 1))
			{
				if_parm6++;
			}

		if((x > 0) && (if_level == 7) && (inside_if7 == 1))
			{
				if_parm7++;
			}

		if((x > 0) && (if_level == 8) && (inside_if8 == 1))
			{
				if_parm8++;
			}

		if((x > 0) && (if_level == 9) && (inside_if9 == 1))
			{
				if_parm9++;
			}

		if((x > 0) && (if_level == 10) && (inside_if10 == 1))
			{
				if_parm10++;
			}


/* ******************************* START OF 1ST IF LOOP	*************************************** */
		if((x1 > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1--;
							
				/* test if_parm1 == 0, then update if_table */
								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-1 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}


										/* clear flags  */
										inside_if1 = 0;
										if_start1 = 0;
										if_else_flag1 = 0;
										if_level--;
									}


								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 0))
									{

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
																break;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-2 READ ");
												trace_rec_1();
											}

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct if-2 NOREAD ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if1 = 0;
												if_start1 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_6();
											}
		
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag1 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start1 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;

																	}
															}
													}
											}


									}
							}

/* ************************************** END OF 1ST FOR LOOP  ******************************************* */

/* ************************************** START OF 2ND IF LOOP ******************************************* */


						if((x1 > 0) && (if_level == 2) && (inside_if2 == 1))
							{

								if_parm2--;
							
								/* test if_parm2 == 0, then update if_table */

								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct_2 if-2 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if2 = 0;
										if_start2 = 0;
										if_else_flag2 = 0;
										if_level--;
									}


								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 if-2 READ ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if2 = 0;
												if_start2 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_6();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag2 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start2 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 2ND FOR LOOP ******************************************* */


/* ************************************** START OF 3RD IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 3) && (inside_if3 == 1))
							{
								if_parm3--;
							
								/* test if_parm3 == 0, then update if_table */

								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if3 = 0;
										if_start3 = 0;
										if_else_flag3 = 0;
										if_level--;
									}


								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												skip_read = 1;
												inside_if3 = 0;
												if_start3 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_6();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-3 ");
														trace_rec_1();
													}

												if_else_flag3 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start3 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 3RD FOR LOOP ******************************************* */


/* ************************************** START OF 4TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 4) && (inside_if4 == 1))
							{
								if_parm4--;
							
								/* test if_parm4 == 0, then update if_table */

								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if4 = 0;
										if_start4 = 0;
										if_else_flag4 = 0;
										if_level--;
									}


								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-4 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if4 = 0;
												if_start4 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_6();

											}
										if(p8)
											{
												if_else_flag4 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start4 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 4TH FOR LOOP ******************************************* */


/* ************************************** START OF 5TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 5) && (inside_if5 == 1))
							{
								if_parm4--;
							
								/* test if_parm5 == 0, then update if_table */

								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if5 = 0;
										if_start5 = 0;
										if_else_flag5 = 0;
										if_level--;
									}


								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if5 = 0;
												if_start5 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_6();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-5 ");
														trace_rec_1();
													}

												if_else_flag5 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start5 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 5TH FOR LOOP ******************************************* */


/* ************************************** START OF 6TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 6) && (inside_if6 == 1))
							{
								if_parm6--;
							
								/* test if_parm6 == 0, then update if_table */

								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if6 = 0;
										if_start6 = 0;
										if_else_flag6 = 0;
										if_level--;
									}


								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if6 = 0;
												if_start6 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_6();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-6 ");
														trace_rec_1();
													}

												if_else_flag6 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start6 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 6TH FOR LOOP ******************************************* */


/* ************************************** START OF 7TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 7) && (inside_if7 == 1))
							{
								if_parm7--;
							
								/* test if_parm7 == 0, then update if_table */

								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if7 = 0;
										if_start7 = 0;
										if_else_flag7 = 0;
										if_level--;
									}


								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-7 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if7 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_6();

											}
										if(p8)
											{
												if_else_flag7 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start7 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 7TH FOR LOOP ******************************************* */


/* ************************************** START OF 8TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 8) && (inside_if8 == 1))
							{
								if_parm8--;
							
								/* test if_parm8 == 0, then update if_table */

								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if8 = 0;
										if_start8 = 0;
										if_else_flag8 = 0;
										if_level--;
									}


								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-8 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if8 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_6();

											}
										if(p8)
											{
												if_else_flag8 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start8 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 8TH FOR LOOP ******************************************* */



/* ************************************** START OF 9TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 9) && (inside_if9 == 1))
							{
								if_parm9--;
							
								/* test if_parm9 == 0, then update if_table */

								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag9 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if9 = 0;
										if_start9 = 0;
										if_else_flag9 = 0;
										if_level--;
									}


								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if9 = 0;
												if_start9 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_6();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-9 ");
														trace_rec_1();
													}

												if_else_flag9 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start9 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 9TH FOR LOOP ******************************************* */


/* ************************************** START OF 10TH IF LOOP ***************************************** */
						if((x1 > 0) && (if_level == 10) && (inside_if10 == 1))
							{
								if_parm10--;
							
								/* test if_parm10 == 0, then update if_table */

								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if10 = 0;
										if_start10 = 0;
										if_else_flag10 = 0;
										if_level--;
									}


								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if10 = 0;
												if_start10 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_6();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-10 ");
														trace_rec_1();
													}

												if_else_flag10 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start10 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}
/* ************************************** END OF 10TH FOR LOOP ******************************************* */


/* ************************************** START OF WHILE LOOP ****************************************** */

						if((x > 0) && (while_level == 1) && (inside_wh1 == 1))
							{
								while_parm1++;

							}
						if((x > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2++;
							}
						if((x > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3++;
							}
						if((x > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4++;
							}
						if((x > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5++;
							}
						if((x > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6++;
							}
						if((x > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7++;
							}
						if((x > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8++;
							}
						if((x > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9++;
							}
						if((x > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10++;
							}

/* ************************************** START OF 1TH WHILE LOOP *************************************** */
					if((x1 > 0) && (while_level == 1) && (inside_wh1 == 1))
							{

								while_parm1--;

								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-1 ");
										trace_rec_1();
									}

								/* test while_parm1 == 0, then update if_table */

								if((while_parm1 == 0) && (inside_wh1 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start1 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh1 = 0;
										while_start1 = 0;
										while_level--;
									}
							}


/* ************************************** END OF 1ST WHILE LOOP ***************************************** */



/* ************************************** START OF 2ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-2 ");
										trace_rec_1();
									}

								/* test while_parm2 == 0, then update if_table */

								if((while_parm2 == 0) && (inside_wh2 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start2 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh2 = 0;
										while_start2 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 2ND WHILE LOOP ***************************************** */						


/* ************************************** START OF 3ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-3 ");
										trace_rec_1();
									}

								/* test while_parm3 == 0, then update if_table */

								if((while_parm3 == 0) && (inside_wh3 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start3 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh3 = 0;
										while_start3 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 3ND WHILE LOOP ***************************************** */		



/* ************************************** START OF 4ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-4 ");
										trace_rec_1();
									}

								/* test while_parm4 == 0, then update if_table */

								if((while_parm4 == 0) && (inside_wh4 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start4 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh4 = 0;
										while_start4 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 4ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 5ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-5 ");
										trace_rec_1();
									}

								/* test while_parm5 == 0, then update if_table */

								if((while_parm5 == 0) && (inside_wh5 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start5 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh5 = 0;
										while_start5 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 5ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 6ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-6 ");
										trace_rec_1();
									}

								/* test while_parm6 == 0, then update if_table */

								if((while_parm6 == 0) && (inside_wh6 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start6 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh6 = 0;
										while_start6 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 6ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 7ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-7 ");
										trace_rec_1();
									}

								/* test while_parm7 == 0, then update if_table */

								if((while_parm7 == 0) && (inside_wh7 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start7 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh7 = 0;
										while_start7 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 7ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 8ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-8 ");
										trace_rec_1();
									}

								/* test while_parm8 == 0, then update if_table */

								if((while_parm8 == 0) && (inside_wh8 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start8 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh8 = 0;
										while_start8 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 8ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 9ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-9 ");
										trace_rec_1();
									}

								/* test while_parm9 == 0, then update if_table */

								if((while_parm9 == 0) && (inside_wh9 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start9 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh9 = 0;
										while_start9 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 9ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 10ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-10 ");
										trace_rec_1();
									}

								/* test while_parm10 == 0, then update if_table */

								if((while_parm10 == 0) && (inside_wh10== 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start10 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh10 = 0;
										while_start10 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 10ND WHILE LOOP ***************************************** */		


					}
/* ************************************** END OF WHILE LOOP ********************************************* */



void c2_param_ct_6()
	{

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2_param_ct_6 ");
				trace_rec_1();
			}

		int I = 0;
		int x = 0;
		int x1 = 0;
		int s = 0;

		char ch;
		char *p7, *p8;

		x = 0;
		x1 = 0;
		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '{')
					x++;
				if(ch == '}')
					x1++;
			}

		
		/* test for if counts */
		if((x > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1++;
			}

		if((x > 0) && (if_level == 2) && (inside_if2 == 1))
			{
				if_parm2++;
			}

		if((x > 0) && (if_level == 3) && (inside_if3 == 1))
			{
				if_parm3++;
			}

		if((x > 0) && (if_level == 4) && (inside_if4 == 1))
			{
				if_parm4++;
			}

		if((x > 0) && (if_level == 5) && (inside_if5 == 1))
			{
				if_parm5++;
			}

		if((x > 0) && (if_level == 6) && (inside_if6 == 1))
			{
				if_parm6++;
			}

		if((x > 0) && (if_level == 7) && (inside_if7 == 1))
			{
				if_parm7++;
			}

		if((x > 0) && (if_level == 8) && (inside_if8 == 1))
			{
				if_parm8++;
			}

		if((x > 0) && (if_level == 9) && (inside_if9 == 1))
			{
				if_parm9++;
			}

		if((x > 0) && (if_level == 10) && (inside_if10 == 1))
			{
				if_parm10++;
			}


/* ******************************* START OF 1ST IF LOOP	*************************************** */
		if((x1 > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1--;
							
				/* test if_parm1 == 0, then update if_table */
								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-1 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}


										/* clear flags  */
										inside_if1 = 0;
										if_start1 = 0;
										if_else_flag1 = 0;
										if_level--;
									}


								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 0))
									{

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
																break;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-2 READ ");
												trace_rec_1();
											}

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct if-2 NOREAD ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if1 = 0;
												if_start1 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_7();
											}
		
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag1 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start1 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;

																	}
															}
													}
											}


									}
							}

/* ************************************** END OF 1ST FOR LOOP  ******************************************* */

/* ************************************** START OF 2ND IF LOOP ******************************************* */


						if((x1 > 0) && (if_level == 2) && (inside_if2 == 1))
							{

								if_parm2--;
							
								/* test if_parm2 == 0, then update if_table */

								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct_2 if-2 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if2 = 0;
										if_start2 = 0;
										if_else_flag2 = 0;
										if_level--;
									}


								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 if-2 READ ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if2 = 0;
												if_start2 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_7();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag2 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start2 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 2ND FOR LOOP ******************************************* */


/* ************************************** START OF 3RD IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 3) && (inside_if3 == 1))
							{
								if_parm3--;
							
								/* test if_parm3 == 0, then update if_table */

								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if3 = 0;
										if_start3 = 0;
										if_else_flag3 = 0;
										if_level--;
									}


								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												skip_read = 1;
												inside_if3 = 0;
												if_start3 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_7();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-3 ");
														trace_rec_1();
													}

												if_else_flag3 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start3 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 3RD FOR LOOP ******************************************* */


/* ************************************** START OF 4TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 4) && (inside_if4 == 1))
							{
								if_parm4--;
							
								/* test if_parm4 == 0, then update if_table */

								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if4 = 0;
										if_start4 = 0;
										if_else_flag4 = 0;
										if_level--;
									}


								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-4 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if4 = 0;
												if_start4 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_7();

											}
										if(p8)
											{
												if_else_flag4 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start4 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 4TH FOR LOOP ******************************************* */


/* ************************************** START OF 5TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 5) && (inside_if5 == 1))
							{
								if_parm4--;
							
								/* test if_parm5 == 0, then update if_table */

								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if5 = 0;
										if_start5 = 0;
										if_else_flag5 = 0;
										if_level--;
									}


								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if5 = 0;
												if_start5 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_7();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-5 ");
														trace_rec_1();
													}

												if_else_flag5 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start5 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 5TH FOR LOOP ******************************************* */


/* ************************************** START OF 6TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 6) && (inside_if6 == 1))
							{
								if_parm6--;
							
								/* test if_parm6 == 0, then update if_table */

								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if6 = 0;
										if_start6 = 0;
										if_else_flag6 = 0;
										if_level--;
									}


								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if6 = 0;
												if_start6 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_7();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-6 ");
														trace_rec_1();
													}

												if_else_flag6 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start6 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 6TH FOR LOOP ******************************************* */


/* ************************************** START OF 7TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 7) && (inside_if7 == 1))
							{
								if_parm7--;
							
								/* test if_parm7 == 0, then update if_table */

								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if7 = 0;
										if_start7 = 0;
										if_else_flag7 = 0;
										if_level--;
									}


								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-7 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if7 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_7();

											}
										if(p8)
											{
												if_else_flag7 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start7 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 7TH FOR LOOP ******************************************* */


/* ************************************** START OF 8TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 8) && (inside_if8 == 1))
							{
								if_parm8--;
							
								/* test if_parm8 == 0, then update if_table */

								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if8 = 0;
										if_start8 = 0;
										if_else_flag8 = 0;
										if_level--;
									}


								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-8 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if8 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_7();

											}
										if(p8)
											{
												if_else_flag8 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start8 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 8TH FOR LOOP ******************************************* */



/* ************************************** START OF 9TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 9) && (inside_if9 == 1))
							{
								if_parm9--;
							
								/* test if_parm9 == 0, then update if_table */

								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag9 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if9 = 0;
										if_start9 = 0;
										if_else_flag9 = 0;
										if_level--;
									}


								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if9 = 0;
												if_start9 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_7();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-9 ");
														trace_rec_1();
													}

												if_else_flag9 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start9 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 9TH FOR LOOP ******************************************* */


/* ************************************** START OF 10TH IF LOOP ***************************************** */
						if((x1 > 0) && (if_level == 10) && (inside_if10 == 1))
							{
								if_parm10--;
							
								/* test if_parm10 == 0, then update if_table */

								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if10 = 0;
										if_start10 = 0;
										if_else_flag10 = 0;
										if_level--;
									}


								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if10 = 0;
												if_start10 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_7();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-10 ");
														trace_rec_1();
													}

												if_else_flag10 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start10 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}
/* ************************************** END OF 10TH FOR LOOP ******************************************* */


/* ************************************** START OF WHILE LOOP ****************************************** */

						if((x > 0) && (while_level == 1) && (inside_wh1 == 1))
							{
								while_parm1++;
							}
						if((x > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2++;
							}
						if((x > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3++;
							}
						if((x > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4++;
							}
						if((x > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5++;
							}
						if((x > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6++;
							}
						if((x > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7++;
							}
						if((x > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8++;
							}
						if((x > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9++;
							}
						if((x > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10++;
							}

/* ************************************** START OF 1TH WHILE LOOP *************************************** */
					if((x1 > 0) && (while_level == 1) && (inside_wh1 == 1))
							{

								while_parm1--;

								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-1 ");
										trace_rec_1();
									}

								/* test while_parm1 == 0, then update if_table */

								if((while_parm1 == 0) && (inside_wh1 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start1 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh1 = 0;
										while_start1 = 0;
										while_level--;
									}
							}


/* ************************************** END OF 1ST WHILE LOOP ***************************************** */



/* ************************************** START OF 2ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-2 ");
										trace_rec_1();
									}

								/* test while_parm2 == 0, then update if_table */

								if((while_parm2 == 0) && (inside_wh2 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start2 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh2 = 0;
										while_start2 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 2ND WHILE LOOP ***************************************** */						


/* ************************************** START OF 3ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-3 ");
										trace_rec_1();
									}

								/* test while_parm3 == 0, then update if_table */

								if((while_parm3 == 0) && (inside_wh3 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start3 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh3 = 0;
										while_start3 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 3ND WHILE LOOP ***************************************** */		



/* ************************************** START OF 4ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-4 ");
										trace_rec_1();
									}

								/* test while_parm4 == 0, then update if_table */

								if((while_parm4 == 0) && (inside_wh4 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start4 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh4 = 0;
										while_start4 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 4ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 5ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-5 ");
										trace_rec_1();
									}

								/* test while_parm5 == 0, then update if_table */

								if((while_parm5 == 0) && (inside_wh5 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start5 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh5 = 0;
										while_start5 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 5ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 6ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-6 ");
										trace_rec_1();
									}

								/* test while_parm6 == 0, then update if_table */

								if((while_parm6 == 0) && (inside_wh6 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start6 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh6 = 0;
										while_start6 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 6ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 7ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-7 ");
										trace_rec_1();
									}

								/* test while_parm7 == 0, then update if_table */

								if((while_parm7 == 0) && (inside_wh7 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start7 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh7 = 0;
										while_start7 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 7ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 8ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-8 ");
										trace_rec_1();
									}

								/* test while_parm8 == 0, then update if_table */

								if((while_parm8 == 0) && (inside_wh8 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start8 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh8 = 0;
										while_start8 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 8ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 9ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-9 ");
										trace_rec_1();
									}

								/* test while_parm9 == 0, then update if_table */

								if((while_parm9 == 0) && (inside_wh9 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start9 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh9 = 0;
										while_start9 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 9ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 10ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-10 ");
										trace_rec_1();
									}

								/* test while_parm10 == 0, then update if_table */

								if((while_parm10 == 0) && (inside_wh10== 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start10 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh10 = 0;
										while_start10 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 10ND WHILE LOOP ***************************************** */		


					}
/* ************************************** END OF WHILE LOOP ********************************************* */




void c2_param_ct_7()
	{

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2_param_ct_7 ");
				trace_rec_1();
			}

		int I = 0;
		int x = 0;
		int x1 = 0;
		int s = 0;

		char ch;
		char *p7, *p8;

		x = 0;
		x1 = 0;
		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '{')
					x++;
				if(ch == '}')
					x1++;
			}

		
		/* test for if counts */
		if((x > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1++;
			}

		if((x > 0) && (if_level == 2) && (inside_if2 == 1))
			{
				if_parm2++;
			}

		if((x > 0) && (if_level == 3) && (inside_if3 == 1))
			{
				if_parm3++;
			}

		if((x > 0) && (if_level == 4) && (inside_if4 == 1))
			{
				if_parm4++;
			}

		if((x > 0) && (if_level == 5) && (inside_if5 == 1))
			{
				if_parm5++;
			}

		if((x > 0) && (if_level == 6) && (inside_if6 == 1))
			{
				if_parm6++;
			}

		if((x > 0) && (if_level == 7) && (inside_if7 == 1))
			{
				if_parm7++;
			}

		if((x > 0) && (if_level == 8) && (inside_if8 == 1))
			{
				if_parm8++;
			}

		if((x > 0) && (if_level == 9) && (inside_if9 == 1))
			{
				if_parm9++;
			}

		if((x > 0) && (if_level == 10) && (inside_if10 == 1))
			{
				if_parm10++;
			}


/* ******************************* START OF 1ST IF LOOP	*************************************** */
		if((x1 > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1--;
							
				/* test if_parm1 == 0, then update if_table */
								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-1 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}


										/* clear flags  */
										inside_if1 = 0;
										if_start1 = 0;
										if_else_flag1 = 0;
										if_level--;
									}


								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 0))
									{

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
																break;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-2 READ ");
												trace_rec_1();
											}

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct if-2 NOREAD ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if1 = 0;
												if_start1 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_8();
											}
		
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag1 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start1 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;

																	}
															}
													}
											}


									}
							}

/* ************************************** END OF 1ST FOR LOOP  ******************************************* */

/* ************************************** START OF 2ND IF LOOP ******************************************* */


						if((x1 > 0) && (if_level == 2) && (inside_if2 == 1))
							{

								if_parm2--;
							
								/* test if_parm2 == 0, then update if_table */

								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct_2 if-2 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if2 = 0;
										if_start2 = 0;
										if_else_flag2 = 0;
										if_level--;
									}


								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 if-2 READ ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if2 = 0;
												if_start2 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_8();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag2 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start2 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 2ND FOR LOOP ******************************************* */


/* ************************************** START OF 3RD IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 3) && (inside_if3 == 1))
							{
								if_parm3--;
							
								/* test if_parm3 == 0, then update if_table */

								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if3 = 0;
										if_start3 = 0;
										if_else_flag3 = 0;
										if_level--;
									}


								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												skip_read = 1;
												inside_if3 = 0;
												if_start3 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_8();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-3 ");
														trace_rec_1();
													}

												if_else_flag3 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start3 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 3RD FOR LOOP ******************************************* */


/* ************************************** START OF 4TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 4) && (inside_if4 == 1))
							{
								if_parm4--;
							
								/* test if_parm4 == 0, then update if_table */

								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if4 = 0;
										if_start4 = 0;
										if_else_flag4 = 0;
										if_level--;
									}


								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-4 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if4 = 0;
												if_start4 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_8();

											}
										if(p8)
											{
												if_else_flag4 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start4 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 4TH FOR LOOP ******************************************* */


/* ************************************** START OF 5TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 5) && (inside_if5 == 1))
							{
								if_parm4--;
							
								/* test if_parm5 == 0, then update if_table */

								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if5 = 0;
										if_start5 = 0;
										if_else_flag5 = 0;
										if_level--;
									}


								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if5 = 0;
												if_start5 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_8();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-5 ");
														trace_rec_1();
													}

												if_else_flag5 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start5 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 5TH FOR LOOP ******************************************* */


/* ************************************** START OF 6TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 6) && (inside_if6 == 1))
							{
								if_parm6--;
							
								/* test if_parm6 == 0, then update if_table */

								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if6 = 0;
										if_start6 = 0;
										if_else_flag6 = 0;
										if_level--;
									}


								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if6 = 0;
												if_start6 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_8();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-6 ");
														trace_rec_1();
													}

												if_else_flag6 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start6 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 6TH FOR LOOP ******************************************* */


/* ************************************** START OF 7TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 7) && (inside_if7 == 1))
							{
								if_parm7--;
							
								/* test if_parm7 == 0, then update if_table */

								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if7 = 0;
										if_start7 = 0;
										if_else_flag7 = 0;
										if_level--;
									}


								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-7 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if7 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_8();

											}
										if(p8)
											{
												if_else_flag7 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start7 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 7TH FOR LOOP ******************************************* */


/* ************************************** START OF 8TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 8) && (inside_if8 == 1))
							{
								if_parm8--;
							
								/* test if_parm8 == 0, then update if_table */

								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if8 = 0;
										if_start8 = 0;
										if_else_flag8 = 0;
										if_level--;
									}


								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-8 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if8 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_8();

											}
										if(p8)
											{
												if_else_flag8 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start8 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 8TH FOR LOOP ******************************************* */



/* ************************************** START OF 9TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 9) && (inside_if9 == 1))
							{
								if_parm9--;
							
								/* test if_parm9 == 0, then update if_table */

								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag9 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if9 = 0;
										if_start9 = 0;
										if_else_flag9 = 0;
										if_level--;
									}


								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if9 = 0;
												if_start9 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_8();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-9 ");
														trace_rec_1();
													}

												if_else_flag9 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start9 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 9TH FOR LOOP ******************************************* */


/* ************************************** START OF 10TH IF LOOP ***************************************** */
						if((x1 > 0) && (if_level == 10) && (inside_if10 == 1))
							{
								if_parm10--;
							
								/* test if_parm10 == 0, then update if_table */

								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if10 = 0;
										if_start10 = 0;
										if_else_flag10 = 0;
										if_level--;
									}


								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if10 = 0;
												if_start10 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_8();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-10 ");
														trace_rec_1();
													}

												if_else_flag10 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start10 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}
/* ************************************** END OF 10TH FOR LOOP ******************************************* */


/* ************************************** START OF WHILE LOOP ****************************************** */

						if((x > 0) && (while_level == 1) && (inside_wh1 == 1))
							{
								while_parm1++;
							}
						if((x > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2++;
							}
						if((x > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3++;
							}
						if((x > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4++;
							}
						if((x > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5++;
							}
						if((x > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6++;
							}
						if((x > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7++;
							}
						if((x > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8++;
							}
						if((x > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9++;
							}
						if((x > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10++;
							}

/* ************************************** START OF 1TH WHILE LOOP *************************************** */
					if((x1 > 0) && (while_level == 1) && (inside_wh1 == 1))
							{

								while_parm1--;

								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-1 ");
										trace_rec_1();
									}

								/* test while_parm1 == 0, then update if_table */

								if((while_parm1 == 0) && (inside_wh1 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start1 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh1 = 0;
										while_start1 = 0;
										while_level--;
									}
							}


/* ************************************** END OF 1ST WHILE LOOP ***************************************** */



/* ************************************** START OF 2ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-2 ");
										trace_rec_1();
									}

								/* test while_parm2 == 0, then update if_table */

								if((while_parm2 == 0) && (inside_wh2 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start2 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh2 = 0;
										while_start2 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 2ND WHILE LOOP ***************************************** */						


/* ************************************** START OF 3ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-3 ");
										trace_rec_1();
									}

								/* test while_parm3 == 0, then update if_table */

								if((while_parm3 == 0) && (inside_wh3 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start3 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh3 = 0;
										while_start3 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 3ND WHILE LOOP ***************************************** */		



/* ************************************** START OF 4ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-4 ");
										trace_rec_1();
									}

								/* test while_parm4 == 0, then update if_table */

								if((while_parm4 == 0) && (inside_wh4 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start4 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh4 = 0;
										while_start4 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 4ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 5ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-5 ");
										trace_rec_1();
									}

								/* test while_parm5 == 0, then update if_table */

								if((while_parm5 == 0) && (inside_wh5 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start5 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh5 = 0;
										while_start5 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 5ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 6ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-6 ");
										trace_rec_1();
									}

								/* test while_parm6 == 0, then update if_table */

								if((while_parm6 == 0) && (inside_wh6 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start6 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh6 = 0;
										while_start6 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 6ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 7ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-7 ");
										trace_rec_1();
									}

								/* test while_parm7 == 0, then update if_table */

								if((while_parm7 == 0) && (inside_wh7 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start7 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh7 = 0;
										while_start7 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 7ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 8ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-8 ");
										trace_rec_1();
									}

								/* test while_parm8 == 0, then update if_table */

								if((while_parm8 == 0) && (inside_wh8 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start8 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh8 = 0;
										while_start8 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 8ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 9ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-9 ");
										trace_rec_1();
									}

								/* test while_parm9 == 0, then update if_table */

								if((while_parm9 == 0) && (inside_wh9 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start9 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh9 = 0;
										while_start9 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 9ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 10ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-10 ");
										trace_rec_1();
									}

								/* test while_parm10 == 0, then update if_table */

								if((while_parm10 == 0) && (inside_wh10== 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start10 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh10 = 0;
										while_start10 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 10ND WHILE LOOP ***************************************** */		


					}
/* ************************************** END OF WHILE LOOP ********************************************* */



void c2_param_ct_8()
	{

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2_param_ct_8 ");
				trace_rec_1();
			}

		int I = 0;
		int x = 0;
		int x1 = 0;
		int s = 0;

		char ch;
		char *p7, *p8;

		x = 0;
		x1 = 0;
		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '{')
					x++;
				if(ch == '}')
					x1++;
			}

		
		/* test for if counts */
		if((x > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1++;
			}

		if((x > 0) && (if_level == 2) && (inside_if2 == 1))
			{
				if_parm2++;
			}

		if((x > 0) && (if_level == 3) && (inside_if3 == 1))
			{
				if_parm3++;
			}

		if((x > 0) && (if_level == 4) && (inside_if4 == 1))
			{
				if_parm4++;
			}

		if((x > 0) && (if_level == 5) && (inside_if5 == 1))
			{
				if_parm5++;
			}

		if((x > 0) && (if_level == 6) && (inside_if6 == 1))
			{
				if_parm6++;
			}

		if((x > 0) && (if_level == 7) && (inside_if7 == 1))
			{
				if_parm7++;
			}

		if((x > 0) && (if_level == 8) && (inside_if8 == 1))
			{
				if_parm8++;
			}

		if((x > 0) && (if_level == 9) && (inside_if9 == 1))
			{
				if_parm9++;
			}

		if((x > 0) && (if_level == 10) && (inside_if10 == 1))
			{
				if_parm10++;
			}


/* ******************************* START OF 1ST IF LOOP	*************************************** */
		if((x1 > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1--;
							
				/* test if_parm1 == 0, then update if_table */
								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-1 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}


										/* clear flags  */
										inside_if1 = 0;
										if_start1 = 0;
										if_else_flag1 = 0;
										if_level--;
									}


								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 0))
									{

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
																break;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-2 READ ");
												trace_rec_1();
											}

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct if-2 NOREAD ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if1 = 0;
												if_start1 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_9();
											}
		
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag1 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start1 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;

																	}
															}
													}
											}


									}
							}

/* ************************************** END OF 1ST FOR LOOP  ******************************************* */

/* ************************************** START OF 2ND IF LOOP ******************************************* */


						if((x1 > 0) && (if_level == 2) && (inside_if2 == 1))
							{

								if_parm2--;
							
								/* test if_parm2 == 0, then update if_table */

								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct_2 if-2 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if2 = 0;
										if_start2 = 0;
										if_else_flag2 = 0;
										if_level--;
									}


								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 if-2 READ ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if2 = 0;
												if_start2 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_9();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag2 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start2 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 2ND FOR LOOP ******************************************* */


/* ************************************** START OF 3RD IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 3) && (inside_if3 == 1))
							{
								if_parm3--;
							
								/* test if_parm3 == 0, then update if_table */

								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if3 = 0;
										if_start3 = 0;
										if_else_flag3 = 0;
										if_level--;
									}


								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												skip_read = 1;
												inside_if3 = 0;
												if_start3 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_9();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-3 ");
														trace_rec_1();
													}

												if_else_flag3 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start3 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 3RD FOR LOOP ******************************************* */


/* ************************************** START OF 4TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 4) && (inside_if4 == 1))
							{
								if_parm4--;
							
								/* test if_parm4 == 0, then update if_table */

								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if4 = 0;
										if_start4 = 0;
										if_else_flag4 = 0;
										if_level--;
									}


								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-4 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if4 = 0;
												if_start4 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_9();

											}
										if(p8)
											{
												if_else_flag4 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start4 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 4TH FOR LOOP ******************************************* */


/* ************************************** START OF 5TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 5) && (inside_if5 == 1))
							{
								if_parm4--;
							
								/* test if_parm5 == 0, then update if_table */

								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if5 = 0;
										if_start5 = 0;
										if_else_flag5 = 0;
										if_level--;
									}


								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if5 = 0;
												if_start5 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_9();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-5 ");
														trace_rec_1();
													}

												if_else_flag5 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start5 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 5TH FOR LOOP ******************************************* */


/* ************************************** START OF 6TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 6) && (inside_if6 == 1))
							{
								if_parm6--;
							
								/* test if_parm6 == 0, then update if_table */

								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if6 = 0;
										if_start6 = 0;
										if_else_flag6 = 0;
										if_level--;
									}


								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if6 = 0;
												if_start6 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_9();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-6 ");
														trace_rec_1();
													}

												if_else_flag6 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start6 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 6TH FOR LOOP ******************************************* */


/* ************************************** START OF 7TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 7) && (inside_if7 == 1))
							{
								if_parm7--;
							
								/* test if_parm7 == 0, then update if_table */

								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if7 = 0;
										if_start7 = 0;
										if_else_flag7 = 0;
										if_level--;
									}


								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-7 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if7 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_9();

											}
										if(p8)
											{
												if_else_flag7 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start7 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 7TH FOR LOOP ******************************************* */


/* ************************************** START OF 8TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 8) && (inside_if8 == 1))
							{
								if_parm8--;
							
								/* test if_parm8 == 0, then update if_table */

								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if8 = 0;
										if_start8 = 0;
										if_else_flag8 = 0;
										if_level--;
									}


								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-8 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if8 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_9();

											}
										if(p8)
											{
												if_else_flag8 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start8 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 8TH FOR LOOP ******************************************* */



/* ************************************** START OF 9TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 9) && (inside_if9 == 1))
							{
								if_parm9--;
							
								/* test if_parm9 == 0, then update if_table */

								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag9 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if9 = 0;
										if_start9 = 0;
										if_else_flag9 = 0;
										if_level--;
									}


								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if9 = 0;
												if_start9 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_9();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-9 ");
														trace_rec_1();
													}

												if_else_flag9 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start9 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 9TH FOR LOOP ******************************************* */


/* ************************************** START OF 10TH IF LOOP ***************************************** */
						if((x1 > 0) && (if_level == 10) && (inside_if10 == 1))
							{
								if_parm10--;
							
								/* test if_parm10 == 0, then update if_table */

								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if10 = 0;
										if_start10 = 0;
										if_else_flag10 = 0;
										if_level--;
									}


								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if10 = 0;
												if_start10 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_9();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-10 ");
														trace_rec_1();
													}

												if_else_flag10 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start10 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}
/* ************************************** END OF 10TH FOR LOOP ******************************************* */


/* ************************************** START OF WHILE LOOP ****************************************** */

						if((x > 0) && (while_level == 1) && (inside_wh1 == 1))
							{
								while_parm1++;
							}
						if((x > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2++;
							}
						if((x > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3++;
							}
						if((x > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4++;
							}
						if((x > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5++;
							}
						if((x > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6++;
							}
						if((x > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7++;
							}
						if((x > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8++;
							}
						if((x > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9++;
							}
						if((x > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10++;
							}

/* ************************************** START OF 1TH WHILE LOOP *************************************** */
					if((x1 > 0) && (while_level == 1) && (inside_wh1 == 1))
							{

								while_parm1--;

								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-1 ");
										trace_rec_1();
									}

								/* test while_parm1 == 0, then update if_table */

								if((while_parm1 == 0) && (inside_wh1 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start1 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh1 = 0;
										while_start1 = 0;
										while_level--;
									}
							}


/* ************************************** END OF 1ST WHILE LOOP ***************************************** */



/* ************************************** START OF 2ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-2 ");
										trace_rec_1();
									}

								/* test while_parm2 == 0, then update if_table */

								if((while_parm2 == 0) && (inside_wh2 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start2 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh2 = 0;
										while_start2 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 2ND WHILE LOOP ***************************************** */						


/* ************************************** START OF 3ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-3 ");
										trace_rec_1();
									}

								/* test while_parm3 == 0, then update if_table */

								if((while_parm3 == 0) && (inside_wh3 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start3 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh3 = 0;
										while_start3 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 3ND WHILE LOOP ***************************************** */		



/* ************************************** START OF 4ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-4 ");
										trace_rec_1();
									}

								/* test while_parm4 == 0, then update if_table */

								if((while_parm4 == 0) && (inside_wh4 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start4 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh4 = 0;
										while_start4 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 4ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 5ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-5 ");
										trace_rec_1();
									}

								/* test while_parm5 == 0, then update if_table */

								if((while_parm5 == 0) && (inside_wh5 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start5 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh5 = 0;
										while_start5 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 5ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 6ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-6 ");
										trace_rec_1();
									}

								/* test while_parm6 == 0, then update if_table */

								if((while_parm6 == 0) && (inside_wh6 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start6 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh6 = 0;
										while_start6 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 6ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 7ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-7 ");
										trace_rec_1();
									}

								/* test while_parm7 == 0, then update if_table */

								if((while_parm7 == 0) && (inside_wh7 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start7 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh7 = 0;
										while_start7 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 7ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 8ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-8 ");
										trace_rec_1();
									}

								/* test while_parm8 == 0, then update if_table */

								if((while_parm8 == 0) && (inside_wh8 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start8 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh8 = 0;
										while_start8 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 8ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 9ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-9 ");
										trace_rec_1();
									}

								/* test while_parm9 == 0, then update if_table */

								if((while_parm9 == 0) && (inside_wh9 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start9 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh9 = 0;
										while_start9 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 9ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 10ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-10 ");
										trace_rec_1();
									}

								/* test while_parm10 == 0, then update if_table */

								if((while_parm10 == 0) && (inside_wh10== 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start10 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh10 = 0;
										while_start10 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 10ND WHILE LOOP ***************************************** */		


					}
/* ************************************** END OF WHILE LOOP ********************************************* */



void c2_param_ct_9()
	{

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2_param_ct_9 ");
				trace_rec_1();
			}

		int I = 0;
		int x = 0;
		int x1 = 0;
		int s = 0;

		char ch;
		char *p7, *p8;

		x = 0;
		x1 = 0;
		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '{')
					x++;
				if(ch == '}')
					x1++;
			}

		
		/* test for if counts */
		if((x > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1++;
			}

		if((x > 0) && (if_level == 2) && (inside_if2 == 1))
			{
				if_parm2++;
			}

		if((x > 0) && (if_level == 3) && (inside_if3 == 1))
			{
				if_parm3++;
			}

		if((x > 0) && (if_level == 4) && (inside_if4 == 1))
			{
				if_parm4++;
			}

		if((x > 0) && (if_level == 5) && (inside_if5 == 1))
			{
				if_parm5++;
			}

		if((x > 0) && (if_level == 6) && (inside_if6 == 1))
			{
				if_parm6++;
			}

		if((x > 0) && (if_level == 7) && (inside_if7 == 1))
			{
				if_parm7++;
			}

		if((x > 0) && (if_level == 8) && (inside_if8 == 1))
			{
				if_parm8++;
			}

		if((x > 0) && (if_level == 9) && (inside_if9 == 1))
			{
				if_parm9++;
			}

		if((x > 0) && (if_level == 10) && (inside_if10 == 1))
			{
				if_parm10++;
			}


/* ******************************* START OF 1ST IF LOOP	*************************************** */
		if((x1 > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1--;
							
				/* test if_parm1 == 0, then update if_table */
								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-1 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}


										/* clear flags  */
										inside_if1 = 0;
										if_start1 = 0;
										if_else_flag1 = 0;
										if_level--;
									}


								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 0))
									{

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
																break;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-2 READ ");
												trace_rec_1();
											}

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct if-2 NOREAD ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if1 = 0;
												if_start1 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_10();
											}
		
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag1 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start1 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;

																	}
															}
													}
											}


									}
							}

/* ************************************** END OF 1ST FOR LOOP  ******************************************* */

/* ************************************** START OF 2ND IF LOOP ******************************************* */


						if((x1 > 0) && (if_level == 2) && (inside_if2 == 1))
							{

								if_parm2--;
							
								/* test if_parm2 == 0, then update if_table */

								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct_2 if-2 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if2 = 0;
										if_start2 = 0;
										if_else_flag2 = 0;
										if_level--;
									}


								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 if-2 READ ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if2 = 0;
												if_start2 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_10();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag2 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start2 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 2ND FOR LOOP ******************************************* */


/* ************************************** START OF 3RD IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 3) && (inside_if3 == 1))
							{
								if_parm3--;
							
								/* test if_parm3 == 0, then update if_table */

								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if3 = 0;
										if_start3 = 0;
										if_else_flag3 = 0;
										if_level--;
									}


								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												skip_read = 1;
												inside_if3 = 0;
												if_start3 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_10();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-3 ");
														trace_rec_1();
													}

												if_else_flag3 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start3 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 3RD FOR LOOP ******************************************* */


/* ************************************** START OF 4TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 4) && (inside_if4 == 1))
							{
								if_parm4--;
							
								/* test if_parm4 == 0, then update if_table */

								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if4 = 0;
										if_start4 = 0;
										if_else_flag4 = 0;
										if_level--;
									}


								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-4 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if4 = 0;
												if_start4 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_10();

											}
										if(p8)
											{
												if_else_flag4 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start4 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 4TH FOR LOOP ******************************************* */


/* ************************************** START OF 5TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 5) && (inside_if5 == 1))
							{
								if_parm4--;
							
								/* test if_parm5 == 0, then update if_table */

								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if5 = 0;
										if_start5 = 0;
										if_else_flag5 = 0;
										if_level--;
									}


								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if5 = 0;
												if_start5 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_10();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-5 ");
														trace_rec_1();
													}

												if_else_flag5 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start5 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 5TH FOR LOOP ******************************************* */


/* ************************************** START OF 6TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 6) && (inside_if6 == 1))
							{
								if_parm6--;
							
								/* test if_parm6 == 0, then update if_table */

								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if6 = 0;
										if_start6 = 0;
										if_else_flag6 = 0;
										if_level--;
									}


								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if6 = 0;
												if_start6 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_10();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-6 ");
														trace_rec_1();
													}

												if_else_flag6 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start6 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 6TH FOR LOOP ******************************************* */


/* ************************************** START OF 7TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 7) && (inside_if7 == 1))
							{
								if_parm7--;
							
								/* test if_parm7 == 0, then update if_table */

								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if7 = 0;
										if_start7 = 0;
										if_else_flag7 = 0;
										if_level--;
									}


								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-7 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if7 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_10();

											}
										if(p8)
											{
												if_else_flag7 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start7 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 7TH FOR LOOP ******************************************* */


/* ************************************** START OF 8TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 8) && (inside_if8 == 1))
							{
								if_parm8--;
							
								/* test if_parm8 == 0, then update if_table */

								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if8 = 0;
										if_start8 = 0;
										if_else_flag8 = 0;
										if_level--;
									}


								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-8 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if8 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_10();

											}
										if(p8)
											{
												if_else_flag8 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start8 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 8TH FOR LOOP ******************************************* */



/* ************************************** START OF 9TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 9) && (inside_if9 == 1))
							{
								if_parm9--;
							
								/* test if_parm9 == 0, then update if_table */

								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag9 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if9 = 0;
										if_start9 = 0;
										if_else_flag9 = 0;
										if_level--;
									}


								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if9 = 0;
												if_start9 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_10();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-9 ");
														trace_rec_1();
													}

												if_else_flag9 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start9 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 9TH FOR LOOP ******************************************* */


/* ************************************** START OF 10TH IF LOOP ***************************************** */
						if((x1 > 0) && (if_level == 10) && (inside_if10 == 1))
							{
								if_parm10--;
							
								/* test if_parm10 == 0, then update if_table */

								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if10 = 0;
										if_start10 = 0;
										if_else_flag10 = 0;
										if_level--;
									}


								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if10 = 0;
												if_start10 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_10();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-10 ");
														trace_rec_1();
													}

												if_else_flag10 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start10 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}
/* ************************************** END OF 10TH FOR LOOP ******************************************* */


/* ************************************** START OF WHILE LOOP ****************************************** */

						if((x > 0) && (while_level == 1) && (inside_wh1 == 1))
							{
								while_parm1++;
							}
						if((x > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2++;
							}
						if((x > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3++;
							}
						if((x > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4++;
							}
						if((x > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5++;
							}
						if((x > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6++;
							}
						if((x > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7++;
							}
						if((x > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8++;
							}
						if((x > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9++;
							}
						if((x > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10++;
							}

/* ************************************** START OF 1TH WHILE LOOP *************************************** */
					if((x1 > 0) && (while_level == 1) && (inside_wh1 == 1))
							{

								while_parm1--;

								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-1 ");
										trace_rec_1();
									}

								/* test while_parm1 == 0, then update if_table */

								if((while_parm1 == 0) && (inside_wh1 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start1 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh1 = 0;
										while_start1 = 0;
										while_level--;
									}
							}


/* ************************************** END OF 1ST WHILE LOOP ***************************************** */



/* ************************************** START OF 2ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-2 ");
										trace_rec_1();
									}

								/* test while_parm2 == 0, then update if_table */

								if((while_parm2 == 0) && (inside_wh2 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start2 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh2 = 0;
										while_start2 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 2ND WHILE LOOP ***************************************** */						


/* ************************************** START OF 3ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-3 ");
										trace_rec_1();
									}

								/* test while_parm3 == 0, then update if_table */

								if((while_parm3 == 0) && (inside_wh3 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start3 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh3 = 0;
										while_start3 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 3ND WHILE LOOP ***************************************** */		



/* ************************************** START OF 4ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-4 ");
										trace_rec_1();
									}

								/* test while_parm4 == 0, then update if_table */

								if((while_parm4 == 0) && (inside_wh4 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start4 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh4 = 0;
										while_start4 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 4ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 5ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-5 ");
										trace_rec_1();
									}

								/* test while_parm5 == 0, then update if_table */

								if((while_parm5 == 0) && (inside_wh5 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start5 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh5 = 0;
										while_start5 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 5ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 6ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-6 ");
										trace_rec_1();
									}

								/* test while_parm6 == 0, then update if_table */

								if((while_parm6 == 0) && (inside_wh6 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start6 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh6 = 0;
										while_start6 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 6ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 7ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-7 ");
										trace_rec_1();
									}

								/* test while_parm7 == 0, then update if_table */

								if((while_parm7 == 0) && (inside_wh7 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start7 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh7 = 0;
										while_start7 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 7ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 8ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-8 ");
										trace_rec_1();
									}

								/* test while_parm8 == 0, then update if_table */

								if((while_parm8 == 0) && (inside_wh8 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start8 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh8 = 0;
										while_start8 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 8ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 9ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-9 ");
										trace_rec_1();
									}

								/* test while_parm9 == 0, then update if_table */

								if((while_parm9 == 0) && (inside_wh9 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start9 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh9 = 0;
										while_start9 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 9ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 10ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-10 ");
										trace_rec_1();
									}

								/* test while_parm10 == 0, then update if_table */

								if((while_parm10 == 0) && (inside_wh10== 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start10 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh10 = 0;
										while_start10 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 10ND WHILE LOOP ***************************************** */		


					}
/* ************************************** END OF WHILE LOOP ********************************************* */


void c2_param_ct_10()
	{

		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2_param_ct_10 ");
				trace_rec_1();
			}

		int I = 0;
		int x = 0;
		int x1 = 0;
		int s = 0;

		char ch;
		char *p7, *p8;

		x = 0;
		x1 = 0;
		s = strlen(p_string);
		for(I=0; I < s; I++)
			{
				ch = p_string[I];
				if(ch == '{')
					x++;
				if(ch == '}')
					x1++;
			}

		
		/* test for if counts */
		if((x > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1++;
			}

		if((x > 0) && (if_level == 2) && (inside_if2 == 1))
			{
				if_parm2++;
			}

		if((x > 0) && (if_level == 3) && (inside_if3 == 1))
			{
				if_parm3++;
			}

		if((x > 0) && (if_level == 4) && (inside_if4 == 1))
			{
				if_parm4++;
			}

		if((x > 0) && (if_level == 5) && (inside_if5 == 1))
			{
				if_parm5++;
			}

		if((x > 0) && (if_level == 6) && (inside_if6 == 1))
			{
				if_parm6++;
			}

		if((x > 0) && (if_level == 7) && (inside_if7 == 1))
			{
				if_parm7++;
			}

		if((x > 0) && (if_level == 8) && (inside_if8 == 1))
			{
				if_parm8++;
			}

		if((x > 0) && (if_level == 9) && (inside_if9 == 1))
			{
				if_parm9++;
			}

		if((x > 0) && (if_level == 10) && (inside_if10 == 1))
			{
				if_parm10++;
			}


/* ******************************* START OF 1ST IF LOOP	*************************************** */
		if((x1 > 0) && (if_level == 1) && (inside_if1 == 1))
			{
				if_parm1--;
							
				/* test if_parm1 == 0, then update if_table */
								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-1 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}


										/* clear flags  */
										inside_if1 = 0;
										if_start1 = 0;
										if_else_flag1 = 0;
										if_level--;
									}


								if((if_parm1 == 0) && (inside_if1 == 1) && (if_else_flag1 == 0))
									{

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start1 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
																break;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct if-2 READ ");
												trace_rec_1();
											}

										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct if-2 NOREAD ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if1 = 0;
												if_start1 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_11();
											}
		
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag1 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start1 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;

																	}
															}
													}
											}


									}
							}

/* ************************************** END OF 1ST FOR LOOP  ******************************************* */

/* ************************************** START OF 2ND IF LOOP ******************************************* */


						if((x1 > 0) && (if_level == 2) && (inside_if2 == 1))
							{

								if_parm2--;
							
								/* test if_parm2 == 0, then update if_table */

								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 1))
									{
										if(trace_flag == 1)
											{
												strcpy(trace_1, "c2_param_ct_2 if-2 ");
												trace_rec_1();
											}

										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if2 = 0;
										if_start2 = 0;
										if_else_flag2 = 0;
										if_level--;
									}


								if((if_parm2 == 0) && (inside_if2 == 1) && (if_else_flag2 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start2 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 if-2 READ ");
														trace_rec_1();
													}

												skip_read = 1;
												/* clear flags  */
												inside_if2 = 0;
												if_start2 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_11();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-2 ");
														trace_rec_1();
													}

												if_else_flag2 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start2 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 2ND FOR LOOP ******************************************* */


/* ************************************** START OF 3RD IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 3) && (inside_if3 == 1))
							{
								if_parm3--;
							
								/* test if_parm3 == 0, then update if_table */

								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if3 = 0;
										if_start3 = 0;
										if_else_flag3 = 0;
										if_level--;
									}


								if((if_parm3 == 0) && (inside_if3 == 1) && (if_else_flag3 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start3 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												skip_read = 1;
												inside_if3 = 0;
												if_start3 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_11();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-3 ");
														trace_rec_1();
													}

												if_else_flag3 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start3 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 3RD FOR LOOP ******************************************* */


/* ************************************** START OF 4TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 4) && (inside_if4 == 1))
							{
								if_parm4--;
							
								/* test if_parm4 == 0, then update if_table */

								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if4 = 0;
										if_start4 = 0;
										if_else_flag4 = 0;
										if_level--;
									}


								if((if_parm4 == 0) && (inside_if4 == 1) && (if_else_flag4 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start4 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-4 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if4 = 0;
												if_start4 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_11();

											}
										if(p8)
											{
												if_else_flag4 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start4 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 4TH FOR LOOP ******************************************* */


/* ************************************** START OF 5TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 5) && (inside_if5 == 1))
							{
								if_parm4--;
							
								/* test if_parm5 == 0, then update if_table */

								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if5 = 0;
										if_start5 = 0;
										if_else_flag5 = 0;
										if_level--;
									}


								if((if_parm5 == 0) && (inside_if5 == 1) && (if_else_flag5 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start5 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if5 = 0;
												if_start5 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_11();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-5 ");
														trace_rec_1();
													}

												if_else_flag5 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start5 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 5TH FOR LOOP ******************************************* */


/* ************************************** START OF 6TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 6) && (inside_if6 == 1))
							{
								if_parm6--;
							
								/* test if_parm6 == 0, then update if_table */

								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if6 = 0;
										if_start6 = 0;
										if_else_flag6 = 0;
										if_level--;
									}


								if((if_parm6 == 0) && (inside_if6 == 1) && (if_else_flag6 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start6 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if6 = 0;
												if_start6 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_11();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-6 ");
														trace_rec_1();
													}

												if_else_flag6 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start6 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 6TH FOR LOOP ******************************************* */


/* ************************************** START OF 7TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 7) && (inside_if7 == 1))
							{
								if_parm7--;
							
								/* test if_parm7 == 0, then update if_table */

								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if7 = 0;
										if_start7 = 0;
										if_else_flag7 = 0;
										if_level--;
									}


								if((if_parm7 == 0) && (inside_if7 == 1) && (if_else_flag7 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start7 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-7 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if7 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_11();

											}
										if(p8)
											{
												if_else_flag7 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start7 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 7TH FOR LOOP ******************************************* */


/* ************************************** START OF 8TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 8) && (inside_if8 == 1))
							{
								if_parm8--;
							
								/* test if_parm8 == 0, then update if_table */

								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if8 = 0;
										if_start8 = 0;
										if_else_flag8 = 0;
										if_level--;
									}


								if((if_parm8 == 0) && (inside_if8 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start8 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof1 = rct;
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-8 ");
														trace_rec_1();
													}

												/* clear flags  */
												inside_if8 = 0;
												if_start7 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_11();

											}
										if(p8)
											{
												if_else_flag8 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start8 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 8TH FOR LOOP ******************************************* */



/* ************************************** START OF 9TH IF LOOP ****************************************** */
						if((x1 > 0) && (if_level == 9) && (inside_if9 == 1))
							{
								if_parm9--;
							
								/* test if_parm9 == 0, then update if_table */

								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag9 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if9 = 0;
										if_start9 = 0;
										if_else_flag9 = 0;
										if_level--;
									}


								if((if_parm9 == 0) && (inside_if9 == 1) && (if_else_flag8 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start9 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if9 = 0;
												if_start9 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_11();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-9 ");
														trace_rec_1();
													}

												if_else_flag9 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start9 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}

/* ************************************** END OF 9TH FOR LOOP ******************************************* */


/* ************************************** START OF 10TH IF LOOP ***************************************** */
						if((x1 > 0) && (if_level == 10) && (inside_if10 == 1))
							{
								if_parm10--;
							
								/* test if_parm10 == 0, then update if_table */

								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 1))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_eof2 = rct;
															}
													}
											}

										/* clear flags  */
										inside_if10 = 0;
										if_start10 = 0;
										if_else_flag10 = 0;
										if_level--;
									}


								if((if_parm10 == 0) && (inside_if10 == 1) && (if_else_flag10 == 0))
									{
										if(wif_ct > 0)
											{
												for(I = 0; I < wif_ct; I++)
													{
														if(if_start10 == w_if_table[I].wif_rct)
															{
																w_if_table[I].wif_else = 0;
																w_if_table[I].wif_eof2 = 0;
															}
													}
											}


										/*  get next record and change case */
										fgets(p_string, BUFSIZE, pgm);
										rct++;
										
										/* test for ELSE */
										p8 = strstr(p_string, "else");
										if(!p8)
											{
												/* clear flags  */
												inside_if10 = 0;
												if_start10 = 0;
												if_level--;
												p7 = strchr(p_string, '}');
												if(p7)
													c2_param_ct_11();

											}
										if(p8)
											{
												if(trace_flag == 1)
													{
														strcpy(trace_1, "c2_param_ct_2 ELSE-10 ");
														trace_rec_1();
													}

												if_else_flag10 = 1;
												/* update w_if_else start */
												if(wif_ct > 0)
													{
														for(I = 0; I < wif_ct; I++)
															{
																if(if_start10 == w_if_table[I].wif_rct)
																	{
																		w_if_table[I].wif_else = rct;



																	}
															}
													}
											}
									}
							}
/* ************************************** END OF 10TH FOR LOOP ******************************************* */


/* ************************************** START OF WHILE LOOP ****************************************** */

						if((x > 0) && (while_level == 1) && (inside_wh1 == 1))
							{
								while_parm1++;
							}
						if((x > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2++;
							}
						if((x > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3++;
							}
						if((x > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4++;
							}
						if((x > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5++;
							}
						if((x > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6++;
							}
						if((x > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7++;
							}
						if((x > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8++;
							}
						if((x > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9++;
							}
						if((x > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10++;
							}

/* ************************************** START OF 1TH WHILE LOOP *************************************** */
					if((x1 > 0) && (while_level == 1) && (inside_wh1 == 1))
							{

								while_parm1--;

								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-1 ");
										trace_rec_1();
									}

								/* test while_parm1 == 0, then update if_table */

								if((while_parm1 == 0) && (inside_wh1 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start1 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh1 = 0;
										while_start1 = 0;
										while_level--;
									}
							}


/* ************************************** END OF 1ST WHILE LOOP ***************************************** */



/* ************************************** START OF 2ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 2) && (inside_wh2 == 1))
							{
								while_parm2--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-2 ");
										trace_rec_1();
									}

								/* test while_parm2 == 0, then update if_table */

								if((while_parm2 == 0) && (inside_wh2 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start2 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh2 = 0;
										while_start2 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 2ND WHILE LOOP ***************************************** */						


/* ************************************** START OF 3ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 3) && (inside_wh3 == 1))
							{
								while_parm3--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-3 ");
										trace_rec_1();
									}

								/* test while_parm3 == 0, then update if_table */

								if((while_parm3 == 0) && (inside_wh3 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start3 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh3 = 0;
										while_start3 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 3ND WHILE LOOP ***************************************** */		



/* ************************************** START OF 4ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 4) && (inside_wh4 == 1))
							{
								while_parm4--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-4 ");
										trace_rec_1();
									}

								/* test while_parm4 == 0, then update if_table */

								if((while_parm4 == 0) && (inside_wh4 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start4 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh4 = 0;
										while_start4 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 4ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 5ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 5) && (inside_wh5 == 1))
							{
								while_parm5--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-5 ");
										trace_rec_1();
									}

								/* test while_parm5 == 0, then update if_table */

								if((while_parm5 == 0) && (inside_wh5 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start5 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh5 = 0;
										while_start5 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 5ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 6ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 6) && (inside_wh6 == 1))
							{
								while_parm6--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-6 ");
										trace_rec_1();
									}

								/* test while_parm6 == 0, then update if_table */

								if((while_parm6 == 0) && (inside_wh6 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start6 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh6 = 0;
										while_start6 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 6ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 7ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 7) && (inside_wh7 == 1))
							{
								while_parm7--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-7 ");
										trace_rec_1();
									}

								/* test while_parm7 == 0, then update if_table */

								if((while_parm7 == 0) && (inside_wh7 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start7 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh7 = 0;
										while_start7 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 7ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 8ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 8) && (inside_wh8 == 1))
							{
								while_parm8--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-8 ");
										trace_rec_1();
									}

								/* test while_parm8 == 0, then update if_table */

								if((while_parm8 == 0) && (inside_wh8 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start8 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh8 = 0;
										while_start8 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 8ND WHILE LOOP ***************************************** */		


/* ************************************** START OF 9ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 9) && (inside_wh9 == 1))
							{
								while_parm9--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-9 ");
										trace_rec_1();
									}

								/* test while_parm9 == 0, then update if_table */

								if((while_parm9 == 0) && (inside_wh9 == 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start9 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh9 = 0;
										while_start9 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 9ND WHILE LOOP ***************************************** */		

/* ************************************** START OF 10ND WHILE LOOP *************************************** */

					if((x1 > 0) && (while_level == 10) && (inside_wh10 == 1))
							{
								while_parm10--;
								if(trace_flag == 1)
									{
										strcpy(trace_1, "c2_param_ct_2 WHILE-10 ");
										trace_rec_1();
									}

								/* test while_parm10 == 0, then update if_table */

								if((while_parm10 == 0) && (inside_wh10== 1))
									{
										if(wh_ct > 0)
											{
												for(I = 0; I < wh_ct; I++)
													{
														if(while_start10 == w_while_table[I].wh_rct)
															{
																w_while_table[I].wh_eof1 = rct;
															}
													}
											}

										/* clear flags  */
										inside_wh10 = 0;
										while_start10 = 0;
										while_level--;
									}
							}

/* ************************************** END OF 10ND WHILE LOOP ***************************************** */		


					}
/* ************************************** END OF WHILE LOOP ********************************************* */

void c2_param_ct_11()
	{
		printf("c2_param_ct_11 PARAMETER ERROR\n");
		printf("c2_param_ct_11 rct = %d p_string = %s",rct,p_string);
		exit(1);

	}