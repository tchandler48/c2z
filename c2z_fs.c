/* ***************************************************
*  c2z : c2z_fs.c :                                  *
*                                                    *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

/* ***************************************************
*  Scan fsscr                                        *
* ************************************************** */


void c2_fs_1(void)
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.fs.c c2_fs_1 START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

   int pi;
   int pi2;
   int x3;
   int size;
   int s;
   int I;
   int ret;
   int ret1;

   pi = 0;
   ch = p_string[pi];
   while(ch != '=')
   {
     pi++;
     ch = p_string[pi];
   }

   pi++;
   ch = p_string[pi];
   while(ch == ' ')
   {
     pi++;
     ch = p_string[pi];
   }

   pi2 = 0;
   while(ch != ';')
   {
     if(ch != '\"')
     {
       field1[pi2] = ch;
       pi2++;
     }
     pi++;
     ch = p_string[pi];
   }
   field1[pi2] = '\0';

   c_name++;
   snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
   strcpy(c_wkname, "C37F");
   strcat(c_wkname, wk_strg);
   s = strlen(c_wkname);
   c_wkname[s] = '\0';
   strcpy(field1a, c_wkname);

   x3 = 0;
   for (I = 0; I < lv_ct; I++) 
   {
     ret = strcmp(field1, lw_variable[I].lv_name);
     ret1 = strcmp(sv_func, lw_variable[I].lv_func);
     if ((ret == 0) && (ret1 == 0)) 
     {
       x3 = 1;
       strcpy(field1a, lw_variable[I].lv_cname);
       lw_variable[I].lv_use_ct++;
       break;
     }
   }

   if (x3 == 0) 
   {
     for (I = 0; I < gv_ct; I++) 
     {
       ret = strcmp(field1, gw_variable[I].gv_name);
       if (ret == 0) 
       {
         x3 = 1;
         strcpy(field1a, gw_variable[I].gv_cname);
         gw_variable[I].gv_use_ct++;
         break;
       }
     }
   }

   if (x3 == 0) 
   {
     if (global_st == 0) 
     {
       size = 0;
       if (fs_map_ct == 0) 
       {
         size = 1;
         w_fs_map = malloc(size * sizeof(struct fs_map));
       } 
       else 
       {
         size = fs_map_ct + 1;
         w_fs_map = realloc(w_fs_map, size * sizeof(struct fs_map));
       }
       w_fs_map[fs_map_ct].fs_rct = rct;
       strcpy(w_fs_map[fs_map_ct].fs_name, field1);
       strcpy(w_fs_map[fs_map_ct].fs_cname, field1a);
       fs_map_ct++;
     }

     if (global_st == 1) 
     {
       size = 0;
       if (fs_map_ct == 0) 
       {
         size = 1;
         w_fs_map = malloc(size * sizeof(struct fs_map));
       } 
       else 
       {
         size = fs_map_ct + 1;
         w_fs_map = realloc(w_fs_map, size * sizeof(struct fs_map));
       }
       w_fs_map[fs_map_ct].fs_rct = rct;
       strcpy(w_fs_map[fs_map_ct].fs_name, field1);
       strcpy(w_fs_map[fs_map_ct].fs_cname, field1a);
       fs_map_ct++;
     }
   }

   convert = 1;
}


void c2_fs_2(void)
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.fs.c c2_fs_2 START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];

   int pi;
   int pi2;
   int s;
   int x3;
   int size;
   int tadd = 0;
   int w_row = 0;
   int w_col = 0;
   int ret2;
   int ret1;
   int ret;
   int v;
   int x5;
 
  pi = 0;
  ch = p_string[pi];
  while(ch != '=')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ',')
  {
    if(ch != '\"')
    {
      field1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ',')
  {
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ',')
  {
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ',')
  {
    if(ch != '\"')
    {
      field4[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ',')
  {
    field5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field5[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ',')
  {
    field6[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field6[pi2] = '\0';

  w_row = atoi(field5);
  w_col = atoi(field6);
  if(w_row == 1)
  { 
    tadd = w_col;
  }
  if(w_row > 1)
  {
    tadd = ((w_row - 1) * 80)  + w_col;
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ';')
  {
    if(ch != '\"')
    {
      field7[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field7[pi2] = '\0';

printf("\nw_row = %d w_col = %d\n",w_row,w_col);
printf("tadd = %d\n",tadd);
printf("address = %s\n",T3270[tadd]);
printf("color = %s\n",field7);

  
/*
printf("\nc2z_fs.c fs_2 rct = %d p_string = %s",rct,p_string);
printf("c2z_fs.c fs_2 rct = %d MAP_NAME field1 = %s\n",rct,field1);
printf("c2z_fs.c fs_2 rct = %d IN/OUT field2 = %s\n",rct,field2);
printf("c2z_fs.c fs_2 rct = %d TYPE field3 = %s\n",rct,field3);
printf("c2z_fs.c fs_2 rct = %d FD_NAME/LITERAL field4 = %s\n",rct,field4);
printf("c2z_fs.c fs_2 rct = %d ROW field5 = %s\n",rct,field5);
printf("c2z_fs.c fs_2 rct = %d COL field6 = %s\n",rct,field6);
printf("c2z_fs.c fs_2 rct = %d COLOR field7 = %s\n",rct,field7);
*/

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(field1a, c_wkname);

  x3 = 0;

   if (x3 == 0) 
   {
     if (global_st == 0) 
     {
       size = 0;
       if (fs_field_ct == 0) 
       {
         size = 1;
         w_fs_field = malloc(size * sizeof(struct fs_field));
       } 
       else 
       {
         size = fs_field_ct + 1;
         w_fs_field = realloc(w_fs_field, size * sizeof(struct fs_field));
       }
       w_fs_field[fs_field_ct].fs_fd_rct = rct;
       strcpy(w_fs_field[fs_field_ct].fs_fd_map, field1);
       strcpy(w_fs_field[fs_field_ct].fs_fd_cname, field1a);
       strcpy(w_fs_field[fs_field_ct].fs_fd_io, field2);
       strcpy(w_fs_field[fs_field_ct].fs_fd_type, field3);
       strcpy(w_fs_field[fs_field_ct].fs_fd_field, field4);
       w_fs_field[fs_field_ct].fs_fd_row = atoi(field5);
       w_fs_field[fs_field_ct].fs_fd_col = atoi(field6);
       strcpy(w_fs_field[fs_field_ct].fs_fd_color, field7);
       strcpy(w_fs_field[fs_field_ct].fs_fd_address, T3270[tadd]);
       fs_field_ct++;
     }

     if (global_st == 1) 
     {
       size = 0;
       if (fs_field_ct == 0) 
       {
         size = 1;
         w_fs_field = malloc(size * sizeof(struct fs_field));
       } 
       else 
       {
         size = fs_field_ct + 1;
         w_fs_field = realloc(w_fs_field, size * sizeof(struct fs_field));
       }
       w_fs_field[fs_field_ct].fs_fd_rct = rct;
       strcpy(w_fs_field[fs_field_ct].fs_fd_map, field1);
       strcpy(w_fs_field[fs_field_ct].fs_fd_cname, field1a);
       strcpy(w_fs_field[fs_field_ct].fs_fd_io, field2);
       strcpy(w_fs_field[fs_field_ct].fs_fd_type, field3);
       strcpy(w_fs_field[fs_field_ct].fs_fd_field, field4);
       w_fs_field[fs_field_ct].fs_fd_row = atoi(field5);
       w_fs_field[fs_field_ct].fs_fd_col = atoi(field6);
       strcpy(w_fs_field[fs_field_ct].fs_fd_color, field7);
       strcpy(w_fs_field[fs_field_ct].fs_fd_address, T3270[tadd]);
       fs_field_ct++;
     }
   }

printf("field3 = %s\n",field2);
   ret2 = strcmp(field3, "V");
   if(ret2 == 0)
   {
/*
struct fs_scr_field
{
   char fs_scr_name[VAR_LGTH];
   char fs_scr_cname[VAR_LGTH];
};
struct fs_scr_field *w_fs_scr_field;
*/
     size = 0;
     if (T3270_ct == 0) 
     {
       size = 1;
       w_fs_scr_field = malloc(size * sizeof(struct fs_scr_field));
     } 
     else 
     {
       size = T3270_ct + 1;
       w_fs_scr_field = realloc(w_fs_scr_field, size * sizeof(struct fs_scr_field));
     }
     strcpy(w_fs_scr_field[T3270_ct].fs_scr_name, field4);
     strcpy(field8,"T3270_");
     snprintf(wk_strg, sizeof(wk_strg), "%d", T3270_ct);
     strcat(field8, wk_strg);
     strcpy(w_fs_scr_field[T3270_ct].fs_scr_cname, field8);
     T3270_ct++;
     
     x3 = 0;
     for (v = 0; v < lv_ct; v++) 
     {
       ret = strcmp(field4, lw_variable[v].lv_name);
       ret1 = strcmp(sv_func, lw_variable[v].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         strcpy(field4a, lw_variable[v].lv_cname);
         x5 = lw_variable[v].lv_current_lgth;
         x3 = 1;
         break;
       }
     }

     if (x3 == 0) 
     {
       for (v = 0; v < gv_ct; v++) 
       {
         ret = strcmp(field4, gw_variable[v].gv_name);
         if (ret == 0) 
         {
           strcpy(field4a, gw_variable[v].gv_cname);
           x5 = gw_variable[v].gv_current_lgth;
           x3 = 1;
           break;
         }
       }
     }

     strcpy(a_string, "          LARL  R9,");
     strcat(a_string, field4a);
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_eoj.c #9015");
       trace_rec_3();
     }

     strcpy(a_string, "          LARL  R8,");
     strcat(a_string, field8);
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_eoj.c #9016");
       trace_rec_3();
     }

     strcpy(a_string, "          MVC   0(14,R8),0(R9)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_eoj.c #9017");
       trace_rec_3();
     }
   }

   convert = 1;
}


void c2_fs_3(void)
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.fs.c c2_fs_3 START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];

   int pi;
   int pi2;
 
  pi = 0;
  ch = p_string[pi];
  while(ch != '=')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ';')
  {
    if(ch != '\"')
    {
      field1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  strcpy(field2, field1);
  strcat(field2, "OL");

  strcpy(a_string, "         TPUT  ");
  strcat(a_string, field1);
  strcat(a_string, "O");
  strcat(a_string, ",");
  strcat(a_string, field2);
  strcat(a_string, ",FULLSCR");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fs.c c2_fs_3 #1");
    trace_rec_3();
  }

/*        TPUT  STREAM,STREAMLN,FULLSCR  */

  convert = 1;
}


void c2_fs_4(void)
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.fs.c c2_fs_4 START");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];

   int pi;
   int pi2;

  pi = 0;
  ch = p_string[pi];
  while(ch != '=')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ';')
  {
    if(ch != '\"')
    {
      field1[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  strcpy(field2, field1);
  strcat(field2, "IL");

  strcpy(a_string, "         TGET  ");
  strcat(a_string, field1);
  strcat(a_string, "I");
  strcat(a_string, ",");
  strcat(a_string, field2);
  strcat(a_string, ",ASIS");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_fs.c c2_fs_3 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         STLINENO LINE=1");
  src_line();
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.c pass 3");
    trace_rec_3();
  }

/*       TGET  INBUF,INBUFLN,ASIS */

  convert = 1;
}


void c2_fs_5(void)
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z.fs.c c2_fs_5 START");
    trace_rec_1();
  }

/* row  1  col 1 thru 80 */
  strcpy(T3270[1], "4040");			/* 1  */
  strcpy(T3270[2], "40C1");			/* 2  */
  strcpy(T3270[3], "40C2");			/* 3  */
  strcpy(T3270[4], "40C3");			/* 4  */
  strcpy(T3270[5], "40C4");			/* 5  */
  strcpy(T3270[6], "40C5");			/* 6  */
  strcpy(T3270[7], "40C6"); 		/* 7  */
  strcpy(T3270[8], "40C7");			/* 8  */
  strcpy(T3270[9], "40C8");			/* 9  */
  strcpy(T3270[10], "40C9");		/* 10  */
  strcpy(T3270[11], "404A");		/* 11  */
  strcpy(T3270[12], "404B");		/* 12  */
  strcpy(T3270[13], "404C");		/* 13  */
  strcpy(T3270[14], "404D");		/* 14  */
  strcpy(T3270[15], "404E");		/* 15  */
  strcpy(T3270[16], "404F");		/* 16  */
  strcpy(T3270[17], "4050");		/* 17  */
  strcpy(T3270[18], "40D1");		/* 18  */
  strcpy(T3270[19], "40D2");		/* 19  */
  strcpy(T3270[20], "40D3");		/* 20  */
  strcpy(T3270[21], "40D4");		/* 21  */
  strcpy(T3270[22], "40D5");		/* 22  */
  strcpy(T3270[23], "40D6");		/* 23  */
  strcpy(T3270[24], "40D7");		/* 24  */
  strcpy(T3270[25], "40D8");		/* 25  */
  strcpy(T3270[26], "40D9");		/* 26  */
  strcpy(T3270[27], "405A");		/* 27  */
  strcpy(T3270[28], "405B");		/* 28  */
  strcpy(T3270[29], "405C");		/* 29  */
  strcpy(T3270[30], "405D");		/* 30  */
  strcpy(T3270[31], "405E");		/* 31  */
  strcpy(T3270[32], "405F");		/* 32  */
  strcpy(T3270[33], "4060");		/* 33  */
  strcpy(T3270[34], "4061");		/* 34  */
  strcpy(T3270[35], "40E2");		/* 35  */
  strcpy(T3270[36], "40E3");		/* 36  */
  strcpy(T3270[37], "40E4");		/* 37  */
  strcpy(T3270[38], "40E5");		/* 38  */
  strcpy(T3270[39], "40E6");		/* 39  */
  strcpy(T3270[40], "40E7");		/* 40  */
  strcpy(T3270[41], "40E8");		/* 41  */
  strcpy(T3270[42], "40E9");		/* 42  */
  strcpy(T3270[43], "406A");		/* 43  */
  strcpy(T3270[44], "406B");		/* 44  */
  strcpy(T3270[45], "406C");		/* 45  */
  strcpy(T3270[46], "406D");		/* 46  */
  strcpy(T3270[47], "406E");		/* 47  */
  strcpy(T3270[48], "406F");		/* 48  */
  strcpy(T3270[49], "40F0");		/* 49  */
  strcpy(T3270[50], "40F1");		/* 50  */
  strcpy(T3270[51], "40F2");		/* 51  */
  strcpy(T3270[52], "40F3");		/* 52  */
  strcpy(T3270[53], "40F4");		/* 53  */
  strcpy(T3270[54], "40F5");		/* 54  */
  strcpy(T3270[55], "40F6");		/* 55  */
  strcpy(T3270[56], "40F7");		/* 56  */
  strcpy(T3270[57], "40F8");		/* 57  */
  strcpy(T3270[58], "40F9");		/* 58  */
  strcpy(T3270[59], "407A");		/* 59  */
  strcpy(T3270[60], "407B");		/* 60  */
  strcpy(T3270[61], "407C");		/* 61  */
  strcpy(T3270[62], "407D");		/* 62  */
  strcpy(T3270[63], "407E");		/* 63  */
  strcpy(T3270[64], "407F");		/* 64  */
  strcpy(T3270[65], "C140");		/* 65  */
  strcpy(T3270[66], "C1C1");		/* 66  */
  strcpy(T3270[67], "C1C2");		/* 67  */
  strcpy(T3270[68], "C1C3");		/* 68  */
  strcpy(T3270[69], "C1C4");		/* 69  */
  strcpy(T3270[70], "C1C5");		/* 70  */
  strcpy(T3270[71], "C1C6");		/* 71  */
  strcpy(T3270[72], "C1C7");		/* 72  */
  strcpy(T3270[73], "C1C8");		/* 73  */
  strcpy(T3270[74], "C1C9");		/* 74  */
  strcpy(T3270[75], "C14A");		/* 75  */
  strcpy(T3270[76], "C14B");		/* 76  */
  strcpy(T3270[77], "C14C");		/* 77  */
  strcpy(T3270[78], "C14D");		/* 78  */
  strcpy(T3270[79], "C14E");		/* 79  */
  strcpy(T3270[80], "C14F");		/* 80  */


/* row  2  col 1 thru 80 */
  strcpy(T3270[81], "C150");		/* 1  */
  strcpy(T3270[82], "C1D1");		/* 2  */
  strcpy(T3270[83], "C1D2");		/* 3  */
  strcpy(T3270[84], "C1D3");		/* 4  */
  strcpy(T3270[85], "C1D4");		/* 5  */
  strcpy(T3270[86], "C1D5");		/* 6  */
  strcpy(T3270[87], "C1D6");		/* 7  */
  strcpy(T3270[88], "C1D7");		/* 8  */
  strcpy(T3270[89], "C1D8");		/* 9  */
  strcpy(T3270[90], "C1D9");		/* 10  */
  strcpy(T3270[91], "C15A");		/* 11  */
  strcpy(T3270[92], "C15B");		/* 12  */
  strcpy(T3270[93], "C15C");		/* 13  */
  strcpy(T3270[94], "C15D");		/* 14  */
  strcpy(T3270[95], "C15E");		/* 15  */
  strcpy(T3270[96], "C15F");		/* 16  */
  strcpy(T3270[97], "C160");		/* 17  */
  strcpy(T3270[98], "C161");		/* 18  */
  strcpy(T3270[99], "C1E2");		/* 19  */
  strcpy(T3270[100], "C1E3");		/* 20  */
  strcpy(T3270[101], "C1E4");		/* 21  */
  strcpy(T3270[102], "C1E5");		/* 22  */
  strcpy(T3270[103], "C1E6");		/* 23  */
  strcpy(T3270[104], "C1E7");		/* 24  */
  strcpy(T3270[105], "C1E8");		/* 25  */
  strcpy(T3270[106], "C1E9");		/* 26  */
  strcpy(T3270[107], "C16A");		/* 27  */
  strcpy(T3270[108], "C16B");		/* 28  */
  strcpy(T3270[109], "C16C");		/* 29  */
  strcpy(T3270[110], "C16D");		/* 30  */
  strcpy(T3270[111], "C16E");		/* 31  */
  strcpy(T3270[112], "C16F");		/* 32  */
  strcpy(T3270[113], "C1F0");		/* 33  */
  strcpy(T3270[114], "C1F1");		/* 34  */
  strcpy(T3270[115], "C1F2");		/* 35  */
  strcpy(T3270[116], "C1F3");		/* 36  */
  strcpy(T3270[117], "C1F4");		/* 37  */
  strcpy(T3270[118], "C1F5");		/* 38  */
  strcpy(T3270[119], "C1F6");		/* 39  */
  strcpy(T3270[120], "C1F7");		/* 40  */
  strcpy(T3270[121], "C1F8");		/* 41  */
  strcpy(T3270[122], "C1F9");		/* 42  */
  strcpy(T3270[123], "C17A");		/* 43  */
  strcpy(T3270[124], "C17B");		/* 44  */
  strcpy(T3270[125], "C17C");		/* 45  */
  strcpy(T3270[126], "C17D");		/* 46  */
  strcpy(T3270[127], "C17E");		/* 47  */
  strcpy(T3270[128], "C17F");		/* 48  */
  strcpy(T3270[129], "C240");		/* 49  */
  strcpy(T3270[130], "C2C1");		/* 50  */
  strcpy(T3270[131], "C2C2");		/* 51  */
  strcpy(T3270[132], "C2C3");		/* 52  */
  strcpy(T3270[133], "C2C4");		/* 53  */
  strcpy(T3270[134], "C2C5");		/* 54  */
  strcpy(T3270[135], "C2C6");		/* 55  */
  strcpy(T3270[136], "C2C7");		/* 56  */
  strcpy(T3270[137], "C2C8");		/* 57  */
  strcpy(T3270[138], "C2C9");		/* 58  */
  strcpy(T3270[139], "C24A");		/* 59  */
  strcpy(T3270[140], "C24B");		/* 60  */
  strcpy(T3270[141], "C24C");		/* 61  */
  strcpy(T3270[142], "C24D");		/* 62  */
  strcpy(T3270[143], "C24E");		/* 63  */
  strcpy(T3270[144], "C24F");		/* 64  */
  strcpy(T3270[145], "C250");		/* 65  */
  strcpy(T3270[146], "C2D1");		/* 66  */
  strcpy(T3270[147], "C2D2");		/* 67  */
  strcpy(T3270[148], "C2D3");		/* 68  */
  strcpy(T3270[149], "C2D4");		/* 69  */
  strcpy(T3270[150], "C2D5");		/* 70  */
  strcpy(T3270[151], "C2D6");		/* 71  */
  strcpy(T3270[152], "C2D7");		/* 72  */
  strcpy(T3270[153], "C2D8");		/* 73  */
  strcpy(T3270[154], "C2D9");		/* 74  */
  strcpy(T3270[155], "C25A");		/* 75  */
  strcpy(T3270[156], "C25B");		/* 76  */
  strcpy(T3270[157], "C25C");		/* 77  */
  strcpy(T3270[158], "C25D");		/* 78  */
  strcpy(T3270[159], "C25E");		/* 79  */
  strcpy(T3270[160], "C25F");		/* 80  */


/* row  3  col 1 thru 80 */
  strcpy(T3270[161], "C260");		/* 1  */
  strcpy(T3270[162], "C261");		/* 2  */
  strcpy(T3270[163], "C2E2");		/* 3  */
  strcpy(T3270[164], "C2E3");		/* 4  */
  strcpy(T3270[165], "C2E4");		/* 5  */
  strcpy(T3270[166], "C2E5");		/* 6  */
  strcpy(T3270[167], "C2E6");		/* 7  */
  strcpy(T3270[168], "C2E7");		/* 8  */
  strcpy(T3270[169], "C2E8");		/* 9  */
  strcpy(T3270[170], "C2E9");		/* 10  */
  strcpy(T3270[171], "C26A");		/* 11  */
  strcpy(T3270[172], "C26B");		/* 12  */
  strcpy(T3270[173], "C26C");		/* 13  */
  strcpy(T3270[174], "C26D");		/* 14  */
  strcpy(T3270[175], "C26E");		/* 15  */
  strcpy(T3270[176], "C26F");		/* 16  */
  strcpy(T3270[177], "C2F0");		/* 17  */
  strcpy(T3270[178], "C2F1");		/* 18  */
  strcpy(T3270[179], "C2F2");		/* 19  */
  strcpy(T3270[180], "C2F3");		/* 20  */
  strcpy(T3270[181], "C2F4");		/* 21  */
  strcpy(T3270[182], "C2F5");		/* 22  */
  strcpy(T3270[183], "C2F6");		/* 23  */
  strcpy(T3270[184], "C2F7");		/* 24  */
  strcpy(T3270[185], "C2F8");		/* 25  */
  strcpy(T3270[186], "C2F9");		/* 26  */
  strcpy(T3270[187], "C27A");		/* 27  */
  strcpy(T3270[188], "C27B");		/* 28  */
  strcpy(T3270[189], "C27C");		/* 29  */
  strcpy(T3270[190], "C27D");		/* 30  */
  strcpy(T3270[191], "C27E");		/* 31  */
  strcpy(T3270[192], "C27F");		/* 32  */
  strcpy(T3270[193], "C340");		/* 33  */
  strcpy(T3270[194], "C3C1");		/* 34  */
  strcpy(T3270[195], "C3C2");		/* 35  */
  strcpy(T3270[196], "C3C3");		/* 36  */
  strcpy(T3270[197], "C3C4");		/* 37  */
  strcpy(T3270[198], "C3C5");		/* 38  */
  strcpy(T3270[199], "C3C6");		/* 39  */
  strcpy(T3270[200], "C3C7");		/* 40  */
  strcpy(T3270[201], "C3C8");		/* 41  */
  strcpy(T3270[202], "C3C9");		/* 42  */
  strcpy(T3270[203], "C34A");		/* 43  */
  strcpy(T3270[204], "C34B");		/* 44  */
  strcpy(T3270[205], "C34C");		/* 45  */
  strcpy(T3270[206], "C34D");		/* 46  */
  strcpy(T3270[207], "C34E");		/* 47  */
  strcpy(T3270[208], "C34F");		/* 48  */
  strcpy(T3270[209], "C350");		/* 49  */
  strcpy(T3270[210], "C3D1");		/* 50  */
  strcpy(T3270[211], "C3D2");		/* 51  */
  strcpy(T3270[212], "C3D3");		/* 52  */
  strcpy(T3270[213], "C3D4");		/* 53  */
  strcpy(T3270[214], "C3D5");		/* 54  */
  strcpy(T3270[215], "C3D6");		/* 55  */
  strcpy(T3270[216], "C3D7");		/* 56  */
  strcpy(T3270[217], "C3D8");		/* 57  */
  strcpy(T3270[218], "C3D9");		/* 58  */
  strcpy(T3270[219], "C35A");		/* 59  */
  strcpy(T3270[220], "C35B");		/* 60  */
  strcpy(T3270[221], "C35C");		/* 61  */
  strcpy(T3270[222], "C35D");		/* 62  */
  strcpy(T3270[223], "C35E");		/* 63  */
  strcpy(T3270[224], "C35F");		/* 64  */
  strcpy(T3270[225], "C360");		/* 65  */
  strcpy(T3270[226], "C361");		/* 66  */
  strcpy(T3270[227], "C3E2");		/* 67  */
  strcpy(T3270[228], "C3E3");		/* 68  */
  strcpy(T3270[229], "C3E4");		/* 69  */
  strcpy(T3270[230], "C3E5");		/* 70  */
  strcpy(T3270[231], "C3E6");		/* 71  */
  strcpy(T3270[232], "C3E7");		/* 72  */
  strcpy(T3270[233], "C3E8");		/* 73  */
  strcpy(T3270[234], "C3E9");		/* 74  */
  strcpy(T3270[235], "C36A");		/* 75  */
  strcpy(T3270[236], "C36B");		/* 76  */
  strcpy(T3270[237], "C36C");		/* 77  */
  strcpy(T3270[238], "C36D");		/* 78  */
  strcpy(T3270[239], "C36E");		/* 79  */
  strcpy(T3270[240], "C36F");		/* 80  */


/* row  4  col 1 thru 80 */
  strcpy(T3270[241], "C3F0");		/* 1  */
  strcpy(T3270[242], "C3F1");		/* 2  */
  strcpy(T3270[243], "C3F2");		/* 3  */
  strcpy(T3270[244], "C3F3");		/* 4  */
  strcpy(T3270[245], "C3F4");		/* 5  */
  strcpy(T3270[246], "C3F5");		/* 6  */
  strcpy(T3270[247], "C3F6");		/* 7  */
  strcpy(T3270[248], "C3F7");		/* 8  */
  strcpy(T3270[249], "C3F8");		/* 9  */
  strcpy(T3270[250], "C3F9");		/* 10  */
  strcpy(T3270[251], "C37A");		/* 11  */
  strcpy(T3270[252], "C37B");		/* 12  */
  strcpy(T3270[253], "C37C");		/* 13  */
  strcpy(T3270[254], "C37D");		/* 14  */
  strcpy(T3270[255], "C37E");		/* 15  */
  strcpy(T3270[256], "C37F");		/* 16  */
  strcpy(T3270[257], "C440");		/* 17  */
  strcpy(T3270[258], "C4C1");		/* 18  */
  strcpy(T3270[259], "C4C2");		/* 19  */
  strcpy(T3270[260], "C4C3");		/* 20  */
  strcpy(T3270[261], "C4C4");		/* 21  */
  strcpy(T3270[262], "C4C5");		/* 22  */
  strcpy(T3270[263], "C4C6");		/* 23  */
  strcpy(T3270[264], "C4C7");		/* 24  */
  strcpy(T3270[265], "C4C8");		/* 25  */
  strcpy(T3270[266], "C4C9");		/* 26  */
  strcpy(T3270[267], "C44A");		/* 27  */
  strcpy(T3270[268], "C44B");		/* 28  */
  strcpy(T3270[269], "C44C");		/* 29  */
  strcpy(T3270[270], "C44D");		/* 30  */
  strcpy(T3270[271], "C44E");		/* 31  */
  strcpy(T3270[272], "C44F");		/* 32  */
  strcpy(T3270[273], "C450");		/* 33  */
  strcpy(T3270[274], "C4D1");		/* 34  */
  strcpy(T3270[275], "C4D2");		/* 35  */
  strcpy(T3270[276], "C4D3");		/* 36  */
  strcpy(T3270[277], "C4D4");		/* 37  */
  strcpy(T3270[278], "C4D5");		/* 38  */
  strcpy(T3270[279], "C4D6");		/* 39  */
  strcpy(T3270[280], "C4D7");		/* 40  */
  strcpy(T3270[281], "C4D8");		/* 41  */
  strcpy(T3270[282], "C4D9");		/* 42  */
  strcpy(T3270[283], "C45A");		/* 43  */
  strcpy(T3270[284], "C45B");		/* 44  */
  strcpy(T3270[285], "C45C");		/* 45  */
  strcpy(T3270[286], "C45D");		/* 46  */
  strcpy(T3270[287], "C45E");		/* 47  */
  strcpy(T3270[288], "C45F");		/* 48  */
  strcpy(T3270[289], "C460");		/* 49  */
  strcpy(T3270[290], "C461");		/* 50  */
  strcpy(T3270[291], "C4E2");		/* 51  */
  strcpy(T3270[292], "C4E3");		/* 52  */
  strcpy(T3270[293], "C4E4");		/* 53  */
  strcpy(T3270[294], "C4E5");		/* 54  */
  strcpy(T3270[295], "C4E6");		/* 55  */
  strcpy(T3270[296], "C4E7");		/* 56  */
  strcpy(T3270[297], "C4E8");		/* 57  */
  strcpy(T3270[298], "C4E9");		/* 58  */
  strcpy(T3270[299], "C46A");		/* 59  */
  strcpy(T3270[300], "C46B");		/* 60  */
  strcpy(T3270[301], "C46C");		/* 61  */
  strcpy(T3270[302], "C46D");		/* 62  */
  strcpy(T3270[303], "C46E");		/* 63  */
  strcpy(T3270[304], "C46F");		/* 64  */
  strcpy(T3270[305], "C4F0");		/* 65  */
  strcpy(T3270[306], "C4F1");		/* 66  */
  strcpy(T3270[307], "C4F2");		/* 67  */
  strcpy(T3270[308], "C4F3");		/* 68  */
  strcpy(T3270[309], "C4F4");		/* 69  */
  strcpy(T3270[310], "C4F5");		/* 70  */
  strcpy(T3270[311], "C4D6");		/* 71  */
  strcpy(T3270[312], "C4F7");		/* 72  */
  strcpy(T3270[313], "C4F8");		/* 73  */
  strcpy(T3270[314], "C4F9");		/* 74  */
  strcpy(T3270[315], "C47A");		/* 75  */
  strcpy(T3270[316], "C47B");		/* 76  */
  strcpy(T3270[317], "C47C");		/* 77  */
  strcpy(T3270[318], "C47D");		/* 78  */
  strcpy(T3270[319], "C47E");		/* 79  */
  strcpy(T3270[320], "C47F");		/* 80  */


/* row  5  col 1 thru 80 */
  strcpy(T3270[321], "C540");		/* 1  */
  strcpy(T3270[322], "C5C1");		/* 2  */
  strcpy(T3270[323], "C5C2");		/* 3  */
  strcpy(T3270[324], "C5C3");		/* 4  */
  strcpy(T3270[325], "C5C4");		/* 5  */
  strcpy(T3270[326], "C5C5");		/* 6  */
  strcpy(T3270[327], "C5C6");		/* 7  */
  strcpy(T3270[328], "C5C7");		/* 8  */
  strcpy(T3270[329], "C5C8");		/* 9  */
  strcpy(T3270[330], "C5C9");		/* 10  */
  strcpy(T3270[331], "C54A");		/* 11  */
  strcpy(T3270[332], "C54B");		/* 12  */
  strcpy(T3270[333], "C54C");		/* 13  */
  strcpy(T3270[334], "C54D");		/* 14  */
  strcpy(T3270[335], "C54E");		/* 15  */
  strcpy(T3270[336], "C54F");		/* 16  */
  strcpy(T3270[337], "C550");		/* 17  */
  strcpy(T3270[338], "C5D1");		/* 18  */
  strcpy(T3270[339], "C5D2");		/* 19  */
  strcpy(T3270[340], "C5D3");		/* 20  */
  strcpy(T3270[341], "C5D4");		/* 21  */
  strcpy(T3270[342], "C5D5");		/* 22  */
  strcpy(T3270[343], "C5D6");		/* 23  */
  strcpy(T3270[344], "C5D7");		/* 24  */
  strcpy(T3270[345], "C5D8");		/* 25  */
  strcpy(T3270[346], "C5D9");		/* 26  */
  strcpy(T3270[347], "C55A");		/* 27  */
  strcpy(T3270[348], "C55B");		/* 28  */
  strcpy(T3270[349], "C55C");		/* 29  */
  strcpy(T3270[350], "C55D");		/* 30  */
  strcpy(T3270[351], "C55E");		/* 31  */
  strcpy(T3270[352], "C55F");		/* 32  */
  strcpy(T3270[353], "C560");		/* 33  */
  strcpy(T3270[354], "C561");		/* 34  */
  strcpy(T3270[355], "C5E2");		/* 35  */
  strcpy(T3270[356], "C5E3");		/* 36  */
  strcpy(T3270[357], "C5E4");		/* 37  */
  strcpy(T3270[358], "C5E5");		/* 38  */
  strcpy(T3270[359], "C5E6");		/* 39  */
  strcpy(T3270[360], "C5E7");		/* 40  */
  strcpy(T3270[361], "C5E8");		/* 41  */
  strcpy(T3270[362], "C5E9");		/* 42  */
  strcpy(T3270[363], "C56A");		/* 43  */
  strcpy(T3270[364], "C56B");		/* 44  */
  strcpy(T3270[365], "C56C");		/* 45  */
  strcpy(T3270[366], "C56D");		/* 46  */
  strcpy(T3270[367], "C56E");		/* 47  */
  strcpy(T3270[368], "C56F");		/* 48  */
  strcpy(T3270[369], "C5F0");		/* 49  */
  strcpy(T3270[370], "C5F1");		/* 50  */
  strcpy(T3270[371], "C5F2");		/* 51  */
  strcpy(T3270[372], "C5F3");		/* 52  */
  strcpy(T3270[373], "C5F4");		/* 53  */
  strcpy(T3270[374], "C5F5");		/* 54  */
  strcpy(T3270[375], "C5F6");		/* 55  */
  strcpy(T3270[376], "C5F7");		/* 56  */
  strcpy(T3270[377], "C5F8");		/* 57  */
  strcpy(T3270[378], "C5F9");		/* 58  */
  strcpy(T3270[379], "C57A");		/* 59  */
  strcpy(T3270[380], "C57B");		/* 60  */
  strcpy(T3270[381], "C57C");		/* 61  */
  strcpy(T3270[382], "C57D");		/* 62  */
  strcpy(T3270[383], "C57E");		/* 63  */
  strcpy(T3270[384], "C57F");		/* 64  */
  strcpy(T3270[385], "C640");		/* 65  */
  strcpy(T3270[386], "C6C1");		/* 66  */
  strcpy(T3270[387], "C6C2");		/* 67  */
  strcpy(T3270[388], "C6C3");		/* 68  */
  strcpy(T3270[389], "C6C4");		/* 69  */
  strcpy(T3270[390], "C6C5");		/* 70  */
  strcpy(T3270[391], "C6C6");		/* 71  */
  strcpy(T3270[392], "C6C7");		/* 72  */
  strcpy(T3270[393], "C6C8");		/* 73  */
  strcpy(T3270[394], "C6C9");		/* 74  */
  strcpy(T3270[395], "C64A");		/* 75  */
  strcpy(T3270[396], "C64B");		/* 76  */
  strcpy(T3270[397], "C64C");		/* 77  */
  strcpy(T3270[398], "C64D");		/* 78  */
  strcpy(T3270[399], "C64E");		/* 79  */
  strcpy(T3270[400], "C64F");		/* 80  */


/* row  6  col 1 thru 80 */
  strcpy(T3270[401], "C650");		/* 1  */
  strcpy(T3270[402], "C6D1");		/* 2  */
  strcpy(T3270[403], "C6D2");		/* 3  */
  strcpy(T3270[404], "C6D3");		/* 4  */
  strcpy(T3270[405], "C6D4");		/* 5  */
  strcpy(T3270[406], "C6D5");		/* 6  */
  strcpy(T3270[407], "C6D6");		/* 7  */
  strcpy(T3270[408], "C6D7");		/* 8  */
  strcpy(T3270[409], "C6D8");		/* 9  */
  strcpy(T3270[410], "C6D9");		/* 10  */
  strcpy(T3270[411], "C65A");		/* 11  */
  strcpy(T3270[412], "C65B");		/* 12  */
  strcpy(T3270[413], "C65C");		/* 13  */
  strcpy(T3270[414], "C65D");		/* 14  */
  strcpy(T3270[415], "C65E");		/* 15  */
  strcpy(T3270[416], "C65F");		/* 16  */
  strcpy(T3270[417], "C660");		/* 17  */
  strcpy(T3270[418], "C661");		/* 18  */
  strcpy(T3270[419], "C6E2");		/* 19  */
  strcpy(T3270[420], "C6E3");		/* 20  */
  strcpy(T3270[421], "C6E4");		/* 21  */
  strcpy(T3270[422], "C6E5");		/* 22  */
  strcpy(T3270[423], "C6E6");		/* 23  */
  strcpy(T3270[424], "C6E7");		/* 24  */
  strcpy(T3270[425], "C6E8");		/* 25  */
  strcpy(T3270[426], "C6E9");		/* 26  */
  strcpy(T3270[427], "C66A");		/* 27  */
  strcpy(T3270[428], "C66B");		/* 28  */
  strcpy(T3270[429], "C66C");		/* 29  */
  strcpy(T3270[430], "C66D");		/* 30  */
  strcpy(T3270[431], "C66E");		/* 31  */
  strcpy(T3270[432], "C66F");		/* 32  */
  strcpy(T3270[433], "C6F0");		/* 33  */
  strcpy(T3270[434], "C6F1");		/* 34  */
  strcpy(T3270[435], "C6F2");		/* 35  */
  strcpy(T3270[436], "C6F3");		/* 36  */
  strcpy(T3270[437], "C6F4");		/* 37  */
  strcpy(T3270[438], "C6F5");		/* 38  */
  strcpy(T3270[439], "C6F6");		/* 39  */
  strcpy(T3270[440], "C6F7");		/* 40  */
  strcpy(T3270[441], "C6F8");		/* 41  */
  strcpy(T3270[442], "C6F9");		/* 42  */
  strcpy(T3270[443], "C67A");		/* 43  */
  strcpy(T3270[444], "C67B");		/* 44  */
  strcpy(T3270[445], "C67C");		/* 45  */
  strcpy(T3270[446], "C67D");		/* 46  */
  strcpy(T3270[447], "C67E");		/* 47  */
  strcpy(T3270[448], "C67F");		/* 48  */
  strcpy(T3270[449], "C740");		/* 49  */
  strcpy(T3270[450], "C7C1");		/* 50  */
  strcpy(T3270[451], "C7C2");		/* 51  */
  strcpy(T3270[452], "C7C3");		/* 52  */
  strcpy(T3270[453], "C7C4");		/* 53  */
  strcpy(T3270[454], "C7C5");		/* 54  */
  strcpy(T3270[455], "C7C6");		/* 55  */
  strcpy(T3270[456], "C7C7");		/* 56  */
  strcpy(T3270[457], "C7C8");		/* 57  */
  strcpy(T3270[458], "C7C9");		/* 58  */
  strcpy(T3270[459], "C74A");		/* 59  */
  strcpy(T3270[460], "C74B");		/* 60  */
  strcpy(T3270[461], "C74C");		/* 61  */
  strcpy(T3270[462], "C74D");		/* 62  */
  strcpy(T3270[463], "C74E");		/* 63  */
  strcpy(T3270[464], "C74F");		/* 64  */
  strcpy(T3270[465], "C750");		/* 65  */
  strcpy(T3270[466], "C7D1");		/* 66  */
  strcpy(T3270[467], "C7D2");		/* 67  */
  strcpy(T3270[468], "C7D3");		/* 68  */
  strcpy(T3270[469], "C7D4");		/* 69  */
  strcpy(T3270[470], "C7D5");		/* 70  */
  strcpy(T3270[471], "C7D6");		/* 71  */
  strcpy(T3270[472], "C7D7");		/* 72  */
  strcpy(T3270[473], "C7D8");		/* 73  */
  strcpy(T3270[474], "C7D9");		/* 74  */
  strcpy(T3270[475], "C75A");		/* 75  */
  strcpy(T3270[476], "C75B");		/* 76  */
  strcpy(T3270[477], "C75C");		/* 77  */
  strcpy(T3270[478], "C75D");		/* 78  */
  strcpy(T3270[479], "C75E");		/* 79  */
  strcpy(T3270[480], "C75F");		/* 80  */


/* row  7  col 1 thru 80 */
  strcpy(T3270[481], "C760");		/* 1  */
  strcpy(T3270[482], "C761");		/* 2  */
  strcpy(T3270[483], "C7E2");		/* 3  */
  strcpy(T3270[484], "C7E3");		/* 4  */
  strcpy(T3270[485], "C7E4");		/* 5  */
  strcpy(T3270[486], "C7E5");		/* 6  */
  strcpy(T3270[487], "C7E6");		/* 7  */
  strcpy(T3270[488], "C7E7");		/* 8  */
  strcpy(T3270[489], "C7E8");		/* 9  */
  strcpy(T3270[490], "C7E9");		/* 10  */
  strcpy(T3270[491], "C76A");		/* 11  */
  strcpy(T3270[492], "C76B");		/* 12  */
  strcpy(T3270[493], "C76C");		/* 13  */
  strcpy(T3270[494], "C76D");		/* 14  */
  strcpy(T3270[495], "C76E");		/* 15  */
  strcpy(T3270[496], "C76F");		/* 16  */
  strcpy(T3270[497], "C7F0");		/* 17  */
  strcpy(T3270[498], "C7F1");		/* 18  */
  strcpy(T3270[499], "C7F2");		/* 19  */
  strcpy(T3270[500], "C7F3");		/* 20  */
  strcpy(T3270[501], "C7F4");		/* 21  */
  strcpy(T3270[502], "C7F5");		/* 22  */
  strcpy(T3270[503], "C7F6");		/* 23  */
  strcpy(T3270[504], "C7F7");		/* 24  */
  strcpy(T3270[505], "C7F8");		/* 25  */
  strcpy(T3270[506], "C7F9");		/* 26  */
  strcpy(T3270[507], "C77A");		/* 27  */
  strcpy(T3270[508], "C77B");		/* 28  */
  strcpy(T3270[509], "C77C");		/* 29  */
  strcpy(T3270[510], "C77D");		/* 30  */
  strcpy(T3270[511], "C77E");		/* 31  */
  strcpy(T3270[512], "C77F");		/* 32  */
  strcpy(T3270[513], "C840");		/* 33  */
  strcpy(T3270[514], "C8C1");		/* 34  */
  strcpy(T3270[515], "C8C2");		/* 35  */
  strcpy(T3270[516], "C8C3");		/* 36  */
  strcpy(T3270[517], "C8C4");		/* 37  */
  strcpy(T3270[518], "C8C5");		/* 38  */
  strcpy(T3270[519], "C8C6");		/* 39  */
  strcpy(T3270[520], "C8C7");		/* 40  */
  strcpy(T3270[521], "C8C8");		/* 41  */
  strcpy(T3270[522], "C8C9");		/* 42  */
  strcpy(T3270[523], "C84A");		/* 43  */
  strcpy(T3270[524], "C84B");		/* 44  */
  strcpy(T3270[525], "C84C");		/* 45  */
  strcpy(T3270[526], "C84D");		/* 46  */
  strcpy(T3270[527], "C84E");		/* 47  */
  strcpy(T3270[528], "C84F");		/* 48  */
  strcpy(T3270[529], "C850");		/* 49  */
  strcpy(T3270[530], "C8D1");		/* 50  */
  strcpy(T3270[531], "C8D2");		/* 51  */
  strcpy(T3270[532], "C8D3");		/* 52  */
  strcpy(T3270[533], "C8D4");		/* 53  */
  strcpy(T3270[534], "C8D5");		/* 54  */
  strcpy(T3270[535], "C8D6");		/* 55  */
  strcpy(T3270[536], "C8D7");		/* 56  */
  strcpy(T3270[537], "C8D8");		/* 57  */
  strcpy(T3270[538], "C8D9");		/* 58  */
  strcpy(T3270[539], "C85A");		/* 59  */
  strcpy(T3270[540], "C85B");		/* 60  */
  strcpy(T3270[541], "C85C");		/* 61  */
  strcpy(T3270[542], "C85D");		/* 62  */
  strcpy(T3270[543], "C85E");		/* 63  */
  strcpy(T3270[544], "C85F");		/* 64  */
  strcpy(T3270[545], "C860");		/* 65  */
  strcpy(T3270[546], "C861");		/* 66  */
  strcpy(T3270[547], "C8E2");		/* 67  */
  strcpy(T3270[548], "C8E3");		/* 68  */
  strcpy(T3270[549], "C8E4");		/* 69  */
  strcpy(T3270[550], "C8E5");		/* 70  */
  strcpy(T3270[551], "C8E6");		/* 71  */
  strcpy(T3270[552], "C8E7");		/* 72  */
  strcpy(T3270[553], "C8E8");		/* 73  */
  strcpy(T3270[554], "C8E9");		/* 74  */
  strcpy(T3270[555], "C86A");		/* 75  */
  strcpy(T3270[556], "C86B");		/* 76  */
  strcpy(T3270[557], "C86C");		/* 77  */
  strcpy(T3270[558], "C86D");		/* 78  */
  strcpy(T3270[559], "C86E");		/* 79  */
  strcpy(T3270[560], "C86F");		/* 80  */


/* row  8  col 1 thru 80 */
  strcpy(T3270[561], "C8F0");		/* 1  */
  strcpy(T3270[562], "C8F1");		/* 2  */
  strcpy(T3270[563], "C8F2");		/* 3  */
  strcpy(T3270[564], "C8F3");		/* 4  */
  strcpy(T3270[565], "C8F4");		/* 5  */
  strcpy(T3270[566], "C8F5");		/* 6  */
  strcpy(T3270[567], "C8F6");		/* 7  */
  strcpy(T3270[568], "C8F7");		/* 8  */
  strcpy(T3270[569], "C8F8");		/* 9  */
  strcpy(T3270[570], "C8F9");		/* 10  */
  strcpy(T3270[571], "C87A");		/* 11  */
  strcpy(T3270[572], "C87B");		/* 12  */
  strcpy(T3270[573], "C87C");		/* 13  */
  strcpy(T3270[574], "C87D");		/* 14  */
  strcpy(T3270[575], "C87E");		/* 15  */
  strcpy(T3270[576], "C87F");		/* 16  */
  strcpy(T3270[577], "C940");		/* 17  */
  strcpy(T3270[578], "C9C1");		/* 18  */
  strcpy(T3270[579], "C9C2");		/* 19  */
  strcpy(T3270[580], "C9C3");		/* 20  */
  strcpy(T3270[581], "C9C4");		/* 21  */
  strcpy(T3270[582], "C9C5");		/* 22  */
  strcpy(T3270[583], "C9C6");		/* 23  */
  strcpy(T3270[584], "C9C7");		/* 24  */
  strcpy(T3270[585], "C9C8");		/* 25  */
  strcpy(T3270[586], "C9C9");		/* 26  */
  strcpy(T3270[587], "C94A");		/* 27  */
  strcpy(T3270[588], "C94B");		/* 28  */
  strcpy(T3270[589], "C94C");		/* 29  */
  strcpy(T3270[590], "C94D");		/* 30  */
  strcpy(T3270[591], "C94E");		/* 31  */
  strcpy(T3270[592], "C94F");		/* 32  */
  strcpy(T3270[593], "C950");		/* 33  */
  strcpy(T3270[594], "C9D1");		/* 34  */
  strcpy(T3270[595], "C9D2");		/* 35  */
  strcpy(T3270[596], "C9D3");		/* 36  */
  strcpy(T3270[597], "C9D4");		/* 37  */
  strcpy(T3270[598], "C9D5");		/* 38  */
  strcpy(T3270[599], "C9D6");		/* 39  */
  strcpy(T3270[600], "C9D7");		/* 40  */
  strcpy(T3270[601], "C9D8");		/* 41  */
  strcpy(T3270[602], "C9D9");		/* 42  */
  strcpy(T3270[603], "C95A");		/* 43  */
  strcpy(T3270[604], "C95B");		/* 44  */
  strcpy(T3270[605], "C95C");		/* 45  */
  strcpy(T3270[606], "C95D");		/* 46  */
  strcpy(T3270[607], "C95E");		/* 47  */
  strcpy(T3270[608], "C95F");		/* 48  */
  strcpy(T3270[609], "C960");		/* 49  */
  strcpy(T3270[610], "C961");		/* 50  */
  strcpy(T3270[611], "C9E2");		/* 51  */
  strcpy(T3270[612], "C9E3");		/* 52  */
  strcpy(T3270[613], "C9E4");		/* 53  */
  strcpy(T3270[614], "C9E5");		/* 54  */
  strcpy(T3270[615], "C9E6");		/* 55  */
  strcpy(T3270[616], "C9E7");		/* 56  */
  strcpy(T3270[617], "C9E8");		/* 57  */
  strcpy(T3270[618], "C9E9");		/* 58  */
  strcpy(T3270[619], "C96A");		/* 59  */
  strcpy(T3270[620], "C95B");		/* 60  */
  strcpy(T3270[621], "C96C");		/* 61  */
  strcpy(T3270[622], "C96D");		/* 62  */
  strcpy(T3270[623], "C96E");		/* 63  */
  strcpy(T3270[624], "C96F");		/* 64  */
  strcpy(T3270[625], "C9F0");		/* 65  */
  strcpy(T3270[626], "C9F1");		/* 66  */
  strcpy(T3270[627], "C9F2");		/* 67  */
  strcpy(T3270[628], "C9F3");		/* 68  */
  strcpy(T3270[629], "C9F4");		/* 69  */
  strcpy(T3270[630], "C9F5");		/* 70  */
  strcpy(T3270[631], "C9F6");		/* 71  */
  strcpy(T3270[632], "C9F7");		/* 72  */
  strcpy(T3270[633], "C9F8");		/* 73  */
  strcpy(T3270[634], "C9F9");		/* 74  */
  strcpy(T3270[635], "C97A");		/* 75  */
  strcpy(T3270[636], "C97B");		/* 76  */
  strcpy(T3270[637], "C97C");		/* 77  */
  strcpy(T3270[638], "C97D");		/* 78  */
  strcpy(T3270[639], "C97E");		/* 79  */
  strcpy(T3270[640], "C97F");		/* 80  */


/* row  9  col 1 thru 80 */
  strcpy(T3270[641], "4A40");		/* 1  */
  strcpy(T3270[642], "4AC1");		/* 2  */
  strcpy(T3270[643], "4AC2");		/* 3  */
  strcpy(T3270[644], "4AC3");		/* 4  */
  strcpy(T3270[645], "4AC4");		/* 5  */
  strcpy(T3270[646], "4AC5");		/* 6  */
  strcpy(T3270[647], "4AC6");		/* 7  */
  strcpy(T3270[648], "4AC7");		/* 8  */
  strcpy(T3270[649], "4AC8");		/* 9  */
  strcpy(T3270[650], "4AC9");		/* 10  */
  strcpy(T3270[651], "4A4A");		/* 11  */
  strcpy(T3270[652], "4A4B");		/* 12  */
  strcpy(T3270[653], "4A4C");		/* 13  */
  strcpy(T3270[654], "4A4D");		/* 14  */
  strcpy(T3270[655], "4A4E");		/* 15  */
  strcpy(T3270[656], "4A4F");		/* 16  */
  strcpy(T3270[657], "4A50");		/* 17  */
  strcpy(T3270[658], "4AD1");		/* 18  */
  strcpy(T3270[659], "4AD2");		/* 19  */
  strcpy(T3270[660], "4AD3");		/* 20  */
  strcpy(T3270[661], "4AD4");		/* 21  */
  strcpy(T3270[662], "4AD5");		/* 22  */
  strcpy(T3270[663], "4AD6");		/* 23  */
  strcpy(T3270[664], "4AD7");		/* 24  */
  strcpy(T3270[665], "4AD8");		/* 25  */
  strcpy(T3270[666], "4AD9");		/* 26  */
  strcpy(T3270[667], "4A5A");		/* 27  */
  strcpy(T3270[668], "4A5B");		/* 28  */
  strcpy(T3270[669], "4A5C");		/* 29  */
  strcpy(T3270[670], "4A5D");		/* 30  */
  strcpy(T3270[671], "4A5E");		/* 31  */
  strcpy(T3270[672], "4A5F");		/* 32  */
  strcpy(T3270[673], "4A60");		/* 33  */
  strcpy(T3270[674], "4A61");		/* 34  */
  strcpy(T3270[675], "4AE2");		/* 35  */
  strcpy(T3270[676], "4AE3");		/* 36  */
  strcpy(T3270[677], "4AE4");		/* 37  */
  strcpy(T3270[678], "4AE5");		/* 38  */
  strcpy(T3270[679], "4AE6");		/* 39  */
  strcpy(T3270[680], "4AE7");		/* 40  */
  strcpy(T3270[681], "4AE8");		/* 41  */
  strcpy(T3270[682], "4AE9");		/* 42  */
  strcpy(T3270[683], "4A6A");		/* 43  */
  strcpy(T3270[684], "4A6B");		/* 44  */
  strcpy(T3270[685], "4A6C");		/* 45  */
  strcpy(T3270[686], "4A6D");		/* 46  */
  strcpy(T3270[687], "4A6E");		/* 47  */
  strcpy(T3270[688], "4A6F");		/* 48  */
  strcpy(T3270[689], "4AF0");		/* 49  */
  strcpy(T3270[690], "4AF1");		/* 50  */
  strcpy(T3270[691], "4AF2");		/* 51  */
  strcpy(T3270[692], "4AF3");		/* 52  */
  strcpy(T3270[693], "4AF4");		/* 53  */
  strcpy(T3270[694], "4AF5");		/* 54  */
  strcpy(T3270[695], "4AF6");		/* 55  */
  strcpy(T3270[696], "4AF7");		/* 56  */
  strcpy(T3270[697], "4AF8");		/* 57  */
  strcpy(T3270[698], "4AF9");		/* 58  */
  strcpy(T3270[699], "4A7A");		/* 59  */
  strcpy(T3270[700], "4A7B");		/* 60  */
  strcpy(T3270[701], "C96C");		/* 61  */
  strcpy(T3270[702], "C96D");		/* 62  */
  strcpy(T3270[703], "C96E");		/* 63  */
  strcpy(T3270[704], "C96F");		/* 64  */
  strcpy(T3270[705], "C9F0");		/* 65  */
  strcpy(T3270[706], "C9F1");		/* 66  */
  strcpy(T3270[707], "C9F2");		/* 67  */
  strcpy(T3270[708], "C9F3");		/* 68  */
  strcpy(T3270[709], "C9F4");		/* 69  */
  strcpy(T3270[710], "C9F5");		/* 70  */
  strcpy(T3270[711], "C9F6");		/* 71  */
  strcpy(T3270[712], "C9F7");		/* 72  */
  strcpy(T3270[713], "C9F8");		/* 73  */
  strcpy(T3270[714], "C9F9");		/* 74  */
  strcpy(T3270[715], "C97A");		/* 75  */
  strcpy(T3270[716], "C97B");		/* 76  */
  strcpy(T3270[717], "C97C");		/* 77  */
  strcpy(T3270[718], "C97D");		/* 78  */
  strcpy(T3270[719], "C97E");		/* 79  */
  strcpy(T3270[720], "C97F");		/* 80  */


/* row  10  col 1 thru 80 */
  strcpy(T3270[721], "4B50");		/* 1  */
  strcpy(T3270[722], "4BD1");		/* 2  */
  strcpy(T3270[723], "4BD2");		/* 3  */
  strcpy(T3270[724], "4BD3");		/* 4  */
  strcpy(T3270[725], "4BD4");		/* 5  */
  strcpy(T3270[726], "4BD5");		/* 6  */
  strcpy(T3270[727], "4BD6");		/* 7  */
  strcpy(T3270[728], "4BD7");		/* 8  */
  strcpy(T3270[729], "4BD8");		/* 9  */
  strcpy(T3270[730], "4BD9");		/* 10  */
  strcpy(T3270[731], "4A4A");		/* 11  */
  strcpy(T3270[732], "4A4B");		/* 12  */
  strcpy(T3270[733], "4A4C");		/* 13  */
  strcpy(T3270[734], "4A4D");		/* 14  */
  strcpy(T3270[735], "4A4E");		/* 15  */
  strcpy(T3270[736], "4A4F");		/* 16  */
  strcpy(T3270[737], "4A50");		/* 17  */
  strcpy(T3270[738], "4AD1");		/* 18  */
  strcpy(T3270[739], "4AD2");		/* 19  */
  strcpy(T3270[740], "4AD3");		/* 20  */
  strcpy(T3270[741], "4AD4");		/* 21  */
  strcpy(T3270[742], "4AD5");		/* 22  */
  strcpy(T3270[743], "4AD6");		/* 23  */
  strcpy(T3270[744], "4AD7");		/* 24  */
  strcpy(T3270[745], "4AD8");		/* 25  */
  strcpy(T3270[746], "4AD9");		/* 26  */
  strcpy(T3270[747], "4A5A");		/* 27  */
  strcpy(T3270[748], "4A5B");		/* 28  */
  strcpy(T3270[749], "4A5C");		/* 29  */
  strcpy(T3270[750], "4A5D");		/* 30  */
  strcpy(T3270[751], "4A5E");		/* 31  */
  strcpy(T3270[752], "4A5F");		/* 32  */
  strcpy(T3270[753], "4A60");		/* 33  */
  strcpy(T3270[754], "4A61");		/* 34  */
  strcpy(T3270[755], "4AE2");		/* 35  */
  strcpy(T3270[756], "4AE3");		/* 36  */
  strcpy(T3270[757], "4AE4");		/* 37  */
  strcpy(T3270[758], "4AE5");		/* 38  */
  strcpy(T3270[759], "4AE6");		/* 39  */
  strcpy(T3270[760], "4AE7");		/* 40  */
  strcpy(T3270[761], "4AE8");		/* 41  */
  strcpy(T3270[762], "4AE9");		/* 42  */
  strcpy(T3270[763], "4A6A");		/* 43  */
  strcpy(T3270[764], "4A6B");		/* 44  */
  strcpy(T3270[765], "4A6C");		/* 45  */
  strcpy(T3270[766], "4A6D");		/* 46  */
  strcpy(T3270[767], "4A6E");		/* 47  */
  strcpy(T3270[768], "4A6F");		/* 48  */
  strcpy(T3270[769], "4AF0");		/* 49  */
  strcpy(T3270[770], "4AF1");		/* 50  */
  strcpy(T3270[771], "4AF2");		/* 51  */
  strcpy(T3270[772], "4AF3");		/* 52  */
  strcpy(T3270[773], "4AF4");		/* 53  */
  strcpy(T3270[774], "4AF5");		/* 54  */
  strcpy(T3270[775], "4AF6");		/* 55  */
  strcpy(T3270[776], "4AF7");		/* 56  */
  strcpy(T3270[777], "4AF8");		/* 57  */
  strcpy(T3270[778], "4AF9");		/* 58  */
  strcpy(T3270[779], "4A7A");		/* 59  */
  strcpy(T3270[780], "4A7B");		/* 60  */
  strcpy(T3270[781], "C96C");		/* 61  */
  strcpy(T3270[782], "C96D");		/* 62  */
  strcpy(T3270[783], "C96E");		/* 63  */
  strcpy(T3270[784], "C96F");		/* 64  */
  strcpy(T3270[785], "C9F0");		/* 65  */
  strcpy(T3270[786], "C9F1");		/* 66  */
  strcpy(T3270[787], "C9F2");		/* 67  */
  strcpy(T3270[788], "C9F3");		/* 68  */
  strcpy(T3270[789], "C9F4");		/* 69  */
  strcpy(T3270[790], "C9F5");		/* 70  */
  strcpy(T3270[791], "C9F6");		/* 71  */
  strcpy(T3270[792], "C9F7");		/* 72  */
  strcpy(T3270[793], "C9F8");		/* 73  */
  strcpy(T3270[794], "C9F9");		/* 74  */
  strcpy(T3270[795], "C97A");		/* 75  */
  strcpy(T3270[796], "C97B");		/* 76  */
  strcpy(T3270[797], "C97C");		/* 77  */
  strcpy(T3270[798], "C97D");		/* 78  */
  strcpy(T3270[799], "C97E");		/* 79  */
  strcpy(T3270[800], "C97F");		/* 80  */




/* row 13  col 1 thru 80 */
  strcpy(T3270[833],"4BF0");  		/* 33 */

/*  row 15 col 1 thru 80 */
  strcpy(T3270[1210],"D1E9");		/* 10 */
  
}



