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
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];

   int pi;
   int pi2;
   int s;
   int x3;
   int size;
   int tadd = 0;
   int w_row = 0;
   int w_col = 0;
 
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
  else
  {
    tadd = (w_row * 80) + w_col;
  }
printf("w_row = %d w_col = %d\n",w_row,w_col);
printf("tadd = %d\n",tadd);
printf("address = %s\n",T3270[tadd]);

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


/*
    "STREAM"  =  name
    O 		=  O = Output  I = Input
    L		=  L = Literal, V = Variable
    "xx"	=  L literal or V variable name
    5		=  row position
   30		=  column position
   RED		=  COLOR
*/

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
  strcpy(T3270[163], "C1D2");		/* 3  */
  strcpy(T3270[164], "C1D3");		/* 4  */
  strcpy(T3270[165], "C1D4");		/* 5  */
  strcpy(T3270[166], "C1D5");		/* 6  */
  strcpy(T3270[167], "C1D6");		/* 7  */
  strcpy(T3270[168], "C1D7");		/* 8  */
  strcpy(T3270[169], "C1D8");		/* 9  */
  strcpy(T3270[170], "C1D9");		/* 10  */
  strcpy(T3270[171], "C15A");		/* 11  */
  strcpy(T3270[172], "C15B");		/* 12  */
  strcpy(T3270[173], "C15C");		/* 13  */
  strcpy(T3270[174], "C15D");		/* 14  */
  strcpy(T3270[175], "C15E");		/* 15  */
  strcpy(T3270[176], "C15F");		/* 16  */
  strcpy(T3270[177], "C160");		/* 17  */
  strcpy(T3270[178], "C161");		/* 18  */
  strcpy(T3270[179], "C1E2");		/* 19  */
  strcpy(T3270[180], "C1E3");		/* 20  */
  strcpy(T3270[181], "C1E4");		/* 21  */
  strcpy(T3270[182], "C1E5");		/* 22  */
  strcpy(T3270[183], "C1E6");		/* 23  */
  strcpy(T3270[184], "C1E7");		/* 24  */
  strcpy(T3270[185], "C1E8");		/* 25  */
  strcpy(T3270[186], "C1E9");		/* 26  */
  strcpy(T3270[187], "C16A");		/* 27  */
  strcpy(T3270[188], "C16B");		/* 28  */
  strcpy(T3270[189], "C16C");		/* 29  */
  strcpy(T3270[190], "C16D");		/* 30  */
  strcpy(T3270[191], "C16E");		/* 31  */
  strcpy(T3270[192], "C16F");		/* 32  */
  strcpy(T3270[193], "C1F0");		/* 33  */
  strcpy(T3270[194], "C1F1");		/* 34  */
  strcpy(T3270[195], "C1F2");		/* 35  */
  strcpy(T3270[196], "C1F3");		/* 36  */
  strcpy(T3270[197], "C1F4");		/* 37  */
  strcpy(T3270[198], "C1F5");		/* 38  */
  strcpy(T3270[199], "C1F6");		/* 39  */
  strcpy(T3270[200], "C1F7");		/* 40  */
  strcpy(T3270[201], "C1F8");		/* 41  */
  strcpy(T3270[202], "C1F9");		/* 42  */
  strcpy(T3270[203], "C17A");		/* 43  */
  strcpy(T3270[204], "C17B");		/* 44  */
  strcpy(T3270[205], "C17C");		/* 45  */
  strcpy(T3270[206], "C17D");		/* 46  */
  strcpy(T3270[207], "C17E");		/* 47  */
  strcpy(T3270[208], "C17F");		/* 48  */
  strcpy(T3270[209], "C240");		/* 49  */
  strcpy(T3270[210], "C2C1");		/* 50  */
  strcpy(T3270[211], "C2C2");		/* 51  */
  strcpy(T3270[212], "C2C3");		/* 52  */
  strcpy(T3270[213], "C2C4");		/* 53  */
  strcpy(T3270[214], "C2C5");		/* 54  */
  strcpy(T3270[215], "C2C6");		/* 55  */
  strcpy(T3270[216], "C2C7");		/* 56  */
  strcpy(T3270[217], "C2C8");		/* 57  */
  strcpy(T3270[218], "C2C9");		/* 58  */
  strcpy(T3270[219], "C24A");		/* 59  */
  strcpy(T3270[220], "C24B");		/* 60  */
  strcpy(T3270[221], "C24C");		/* 61  */
  strcpy(T3270[222], "C24D");		/* 62  */
  strcpy(T3270[223], "C24E");		/* 63  */
  strcpy(T3270[224], "C24F");		/* 64  */
  strcpy(T3270[225], "C250");		/* 65  */
  strcpy(T3270[226], "C2D1");		/* 66  */
  strcpy(T3270[227], "C2D2");		/* 67  */
  strcpy(T3270[228], "C2D3");		/* 68  */
  strcpy(T3270[229], "C2D4");		/* 69  */
  strcpy(T3270[230], "C2D5");		/* 70  */
  strcpy(T3270[231], "C2D6");		/* 71  */
  strcpy(T3270[232], "C2D7");		/* 72  */
  strcpy(T3270[233], "C2D8");		/* 73  */
  strcpy(T3270[234], "C2D9");		/* 74  */
  strcpy(T3270[235], "C25A");		/* 75  */
  strcpy(T3270[236], "C25B");		/* 76  */
  strcpy(T3270[237], "C25C");		/* 77  */
  strcpy(T3270[238], "C25D");		/* 78  */
  strcpy(T3270[239], "C25E");		/* 79  */
  strcpy(T3270[240], "C25F");		/* 80  */



/* row 13  col 1 thru 80 */
  strcpy(T3270[833],"4BF0");  		/* 33 */

/*  row 15 col 1 thru 80 */
  strcpy(T3270[1210],"D1E9");		/* 10 */
  
}



