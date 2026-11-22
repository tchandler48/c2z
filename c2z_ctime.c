/* ***************************************************
*  c2z  : c2z_ctime.c :                              *
*                                                    *
*  next error - ctime-004                            *
*  Copyright TCCS (c) 2015 - 2026                    *
**************************************************** */

/* ***************************************************
*  time                                              *
* ************************************************** */
void c2_time() 
{
  strcpy(trace_1, "c2z_ctime c2_time");
  trace_rec_1();
  
  int pi;
  int pi2;
  int x3 = 0;
  int I = 0;
  int x2 = 0;
  int ret = 0;
  int ret1 = 0;
  int s = 0;
  int size = 0;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ')')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';


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
        }
      }
    }

    if (x3 == 0) 
    {
      c_name++;
      snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
      strcpy(c_wkname, "C37F");
      strcat(c_wkname, wk_strg);
      s = strlen(c_wkname);
      c_wkname[s] = '\0';
      strcpy(field1a, c_wkname);

      if (global_st == 0) 
      {
        if (gv_ct == 0) 
        {
          size = 1;
          gw_variable = malloc(size * sizeof(struct variables));
        } 
        else 
        {
          size = gv_ct + 1;
          gw_variable = realloc(gw_variable, size * sizeof(struct variables));
        }
        gw_variable[gv_ct].gv_rct = rct;
        strcpy(gw_variable[gv_ct].gv_cname, field1a);
        strcpy(gw_variable[gv_ct].gv_name, field1);
        strcpy(gw_variable[gv_ct].gv_type, "C");
        gw_variable[gv_ct].gv_lgth = s;
        gw_variable[gv_ct].gv_current_lgth = s;
        strcpy(gw_variable[gv_ct].gv_value, null_field);
        strcpy(gw_variable[gv_ct].gv_literal, null_field);
        gw_variable[gv_ct].gv_init = 0;
        gw_variable[gv_ct].gv_use_ct = 0;
        strcpy(gw_variable[gv_ct].gv_dsect, null_field);
        gw_variable[gv_ct].gv_row = 0;
        gw_variable[gv_ct].gv_column = 0;
        strcpy(gw_variable[gv_ct].gv_label, null_field);
        strcpy(gw_variable[gv_ct].gv_table, null_field);
        strcpy(gw_variable[gv_ct].gv_aname, null_field);
        strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
        strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
        gw_variable[gv_ct].gv_dec = 0;
        gw_variable[gv_ct].gv_id = 3;
        gv_ct++;
        convert = 1;
      }

      if (global_st == 1) 
      {
        if (lv_ct == 0) 
        {
          size = 1;
          lw_variable = malloc(size * sizeof(struct var));
        } 
        else 
        {
          size = lv_ct + 1;
          lw_variable = realloc(lw_variable, size * sizeof(struct var));
        }
        lw_variable[lv_ct].lv_rct = rct;
        strcpy(lw_variable[lv_ct].lv_cname, field1a);
        strcpy(lw_variable[lv_ct].lv_name, field1);
        strcpy(lw_variable[lv_ct].lv_type, "C");
        lw_variable[lv_ct].lv_lgth = s;
        lw_variable[lv_ct].lv_current_lgth = s;
        lw_variable[lv_ct].lv_use_ct = 0;
        strcpy(lw_variable[lv_ct].lv_func, sv_func);
        lw_variable[lv_ct].lv_dec = 0;
        lw_variable[lv_ct].lv_id = 3;
        lv_ct++;
        convert = 1;
      }
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      x2 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (x2 == 0)) 
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
      printf("\nc2z_ctime c2_ctime #001 field1 = %s\n", field1);
      printf("c2z_ctime c2_ctime rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "*");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #1");
    trace_rec_3();

    strcpy(a_string, "         LARL  R2,C370DWRK");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #2");
    trace_rec_3();
 
    strcpy(a_string, "         LARL  R3,C370DTTM");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #3");
    trace_rec_3();

    strcpy(a_string, "         TIME  DEC,(R3),LINKAGE=SYSTEM,DATETYPE=MMDDYYYY");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #4");
    trace_rec_3();
 
    strcpy(a_string, "         LARL  R3,C370DTTM");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #5");
    trace_rec_3();
    work_use_ct[30]++;

    strcpy(a_string, "         LARL  R5,C370PTIM");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #6");
    trace_rec_3();
    work_use_ct[31]++;

    strcpy(a_string, "         LARL  R6,C370TWRK");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #7");
    trace_rec_3();
    work_use_ct[47]++;

    strcpy(a_string, "         LARL  R2,C370DTIM");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #8");
    trace_rec_3();

    strcpy(a_string, "         MVC   0(5,R5),0(R3)");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #9");
    trace_rec_3();

    strcpy(a_string, "         MVI   5(R5),X'0F'");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #10");
    trace_rec_3();

    strcpy(a_string, "         UNPK  0(11,R6),0(6,R5)");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #11");
    trace_rec_3();

    strcpy(a_string, "         MVC   0(2,R2),0(R6)");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #12");
    trace_rec_3();

    strcpy(a_string, "         MVI   2(R2),C':'");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #13");
    trace_rec_3();

    strcpy(a_string, "         MVC   3(2,R2),2(R6)");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #14");
    trace_rec_3();

    strcpy(a_string, "         MVI   5(R2),C':'");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #15");
    trace_rec_3();

    strcpy(a_string, "         MVC   6(2,R2),4(R6)");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #16");
    trace_rec_3();

    strcpy(a_string, "         MVI   8(R2),C':'");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #17");
    trace_rec_3();

    strcpy(a_string, "         MVC   9(2,R2),6(R6)");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #18");
    trace_rec_3();

    strcpy(a_string, "         MVI   11(R2),C':'");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #19");
    trace_rec_3();

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #20");
    trace_rec_3();
   
    strcpy(a_string, "         LARL  R8,C370DTIM");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #21");
    trace_rec_3();
    work_use_ct[30]++;

    strcpy(a_string, "         MVC   0(11,R9),0(R8)");
    src_line();
    strcpy(trace_1, "c2z_ctime c2_time #22");
    trace_rec_3();
  
  work_use_ct[28]++;
  convert = 1;
  return;
}


/* ***************************************************
*  date                                              *
* ************************************************** */
void c2_date() 
{
  strcpy(trace_1, "c2z_ctime c2_date");
  trace_rec_1();
 
  int pi;
  int pi2;
  int x3 = 0;
  int I = 0;
  int x2 = 0;
  int ret = 0;
  int ret1 = 0;
  int s = 0;
  int size = 0;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ')')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

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
      }
    }
  }

  if (x3 == 0) 
  {
    c_name++;
    snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
    strcpy(c_wkname, "C37F");
    strcat(c_wkname, wk_strg);
    s = strlen(c_wkname);
    c_wkname[s] = '\0';
    strcpy(field1a, c_wkname);

    if (global_st == 0) 
    {
      if (gv_ct == 0) 
      {
        size = 1;
        gw_variable = malloc(size * sizeof(struct variables));
      } 
      else 
      {
        size = gv_ct + 1;
        gw_variable = realloc(gw_variable, size * sizeof(struct variables));
      }
      gw_variable[gv_ct].gv_rct = rct;
      strcpy(gw_variable[gv_ct].gv_cname, field1a);
      strcpy(gw_variable[gv_ct].gv_name, field1);
      strcpy(gw_variable[gv_ct].gv_type, "C");
      gw_variable[gv_ct].gv_lgth = s;
      gw_variable[gv_ct].gv_current_lgth = s;
      strcpy(gw_variable[gv_ct].gv_value, null_field);
      strcpy(gw_variable[gv_ct].gv_literal, null_field);
      gw_variable[gv_ct].gv_init = 0;
      gw_variable[gv_ct].gv_use_ct = 0;
      strcpy(gw_variable[gv_ct].gv_dsect, null_field);
      gw_variable[gv_ct].gv_row = 0;
      gw_variable[gv_ct].gv_column = 0;
      strcpy(gw_variable[gv_ct].gv_label, null_field);
      strcpy(gw_variable[gv_ct].gv_table, null_field);
      strcpy(gw_variable[gv_ct].gv_aname, null_field);
      strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
      strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
      strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
      gw_variable[gv_ct].gv_dec = 0;
      gw_variable[gv_ct].gv_id = 3;
      gv_ct++;
      convert = 1;
    }

    if (global_st == 1) 
    {
      if (lv_ct == 0) 
      {
        size = 1;
        lw_variable = malloc(size * sizeof(struct var));
      } 
      else 
      {
        size = lv_ct + 1;
        lw_variable = realloc(lw_variable, size * sizeof(struct var));
      }
      lw_variable[lv_ct].lv_rct = rct;
      strcpy(lw_variable[lv_ct].lv_cname, field1a);
      strcpy(lw_variable[lv_ct].lv_name, field1);
      strcpy(lw_variable[lv_ct].lv_type, "C");
      lw_variable[lv_ct].lv_lgth = s;
      lw_variable[lv_ct].lv_current_lgth = s;
      lw_variable[lv_ct].lv_use_ct = 0;
      strcpy(lw_variable[lv_ct].lv_func, sv_func);
      lw_variable[lv_ct].lv_dec = 0;
      lw_variable[lv_ct].lv_id = 3;
      lv_ct++;
      convert = 1;
    }
  }

  strcpy(a_string, "         LARL  R2,C370DWRK");
  src_line();
  strcpy(trace_1, "c2z_ctime c2_date #1");
  trace_rec_3();
 
  strcpy(a_string, "         LARL  R3,C370DTTM");
  src_line();
  strcpy(trace_1, "c2z_ctime c2_date #2");
  trace_rec_3();

  strcpy(a_string, "         TIME  DEC,(R3),LINKAGE=SYSTEM,DATETYPE=MMDDYYYY");
  src_line();
  strcpy(trace_1, "c2z_ctime c2_date #3");
  trace_rec_3();
  
  strcpy(a_string, "         LA    R3,8(,R3)");
  src_line();
  strcpy(trace_1, "c2z_ctime c2_date #4");
  trace_rec_3();

  strcpy(a_string, "         UNPK  0(9,R2),0(5,R3)");
  src_line();
  strcpy(trace_1, "c2z_ctime c2_date #5");
  trace_rec_3();
  
  strcpy(a_string, "         LARL  R4,C370DDTE");
  src_line();
  strcpy(trace_1, "c2z_ctime c2_date #6");
  trace_rec_3();
 
  
  strcpy(a_string, "         MVC   0(2,R4),0(R2)");
  src_line();
  strcpy(trace_1, "c2z_ctimec c2_date #7");
  trace_rec_3();
  
  strcpy(a_string, "         MVC   3(2,R4),2(R2)");
  src_line();
  strcpy(trace_1, "c2z_ctimec c2_date #8");
  trace_rec_3();
  
  strcpy(a_string, "         MVC   6(2,R4),6(R2)");
  src_line();
  strcpy(trace_1, "c2z_ctimec c2_date #9");
  trace_rec_3();
  
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field1, lw_variable[I].lv_name);
    x2 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (x2 == 0)) 
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
    printf("\nc2z_ctime c2_date #001 field1 = %s\n", field1);
    printf("c2z_ctime c2_date rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, field1a);
  src_line();
  strcpy(trace_1, "c2z_ctimec c2_date #10");
  trace_rec_3();
   
  strcpy(a_string, "         MVC   0(8,R9),0(R4)");
  src_line();
  strcpy(trace_1, "c2z_ctimec c2_date #11");
  trace_rec_3();
  
  work_use_ct[27]++;
  convert = 1;
  return;
}



