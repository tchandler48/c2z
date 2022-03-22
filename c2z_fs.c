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


printf("\nc2z_fs.c fs_2 rct = %d p_string = %s",rct,p_string);
printf("c2z_fs.c fs_2 rct = %d MAP_NAME field1 = %s\n",rct,field1);
printf("c2z_fs.c fs_2 rct = %d IN/OUT field2 = %s\n",rct,field2);
printf("c2z_fs.c fs_2 rct = %d TYPE field3 = %s\n",rct,field3);
printf("c2z_fs.c fs_2 rct = %d FD_NAME/LITERAL field4 = %s\n",rct,field4);
printf("c2z_fs.c fs_2 rct = %d ROW field5 = %s\n",rct,field5);
printf("c2z_fs.c fs_2 rct = %d COL field6 = %s\n",rct,field6);
printf("c2z_fs.c fs_2 rct = %d COLOR field7 = %s\n",rct,field7);

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

         L     R0,ROW
         L     R1,COL
         BCTR  R0,0 
         BCTR  R1,0 
         MH    R0,=H'80' 
         AR    R1,R0 
         SLL   R1,2 
         STCM  R1,B'0010',SBACMD 
         SRL   R1,2 
         STCM  R1,B'0001',SBACMD+1 
         NC    SBACMD(2),=X'3F3F' 
         TR    SBACMD(2),TBL3270 
SBACMD   DC    XL2'0000'

 

TBL3270  DC    X'40C1C2C3C4C5C6C7C8C94A4B4C4D4E4F' 
         DC    X'50D1D2D3D4D5D6D7D8D95A5B5C5D5E5F' 
         DC    X'6061E2E3E4E5E6E7E8E96A6B6C6D6E6F'       
         DC    X'F0F1F2F3F4F5F6F7F8F97A7B7C7D7E7F'
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


