/* ***************************************************
*  c2Z  : c2z_debug.c :                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */

void c2_debug() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2_debug");
    trace_rec_1();
  }

  char p_strg[6];

  int I = 0;
  int s = 0;
  int v = 0;
  int ret = 0;

  fprintf(c_src, "\n\n---------- Define -------------------\n");
  for (I = 0; I < fld_ct; I++) 
  {
    fprintf(c_src, "\nRec - %d", w_define[I].d_rct);
    fprintf(c_src, "    Field Name  - %s", w_define[I].d_name);
    fprintf(c_src, "    Field Value - %s", w_define[I].d_value);
  }


  fprintf(c_src, "\n\n---------- fopen --------------------\n");
  for (I = 0; I < f_ct; I++) 
  {
    fprintf(c_src, "\nRec  - %d", w_file[I].f_rct);
    fprintf(c_src, "   F Name - %s", w_file[I].f_name);
    fprintf(c_src, "   C Name - %s", w_file[I].f_cname);
    fprintf(c_src, "   Type   - %s", w_file[I].f_type);
    fprintf(c_src, "   Buf Ct - %d", w_file[I].f_buf_ct);
    fprintf(c_src, "   Perm   - %s\n", w_file[I].f_perm);
  }

  fprintf(c_src, "\n\n---------- fclose -------------------\n");
  for (I = 0; I < fclose_ct; I++) 
  {
    fprintf(c_src, "\ncl_rct = %d", w_fclose_table[I].cl_rct);
    fprintf(c_src, "    cl_buf_ct = %d", w_fclose_table[I].cl_buf_ct);
  }

  fprintf(c_src, "\n\n---------- functions ----------------\n\n");
  fprintf(c_src, "Rct   Function                 CName          Start  Sv_Var    fd1         fd2          fd3\n");
  fprintf(c_src, "----  -----------------------  -------------  -----  --------  ----------  -----------  ------------\n");
  for (I = 0; I < fn_ct; I++) 
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_function[I].fn_rct);
    strcpy(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 6) 
    {
      for (v = s; v < 6; v++) 
      {
        strcat(a_string, " ");
      }
    }
    strcat(a_string, w_function[I].fn_name);

    s = strlen(a_string);
    if (s < 31) 
    {
      for (v = s; v < 31; v++) 
      {
        strcat(a_string, " ");
      }
    }
    strcat(a_string, w_function[I].fn_cname);

    s = strlen(a_string);
    if (s < 46) 
    {
      for (v = s; v < 46; v++) 
      {
        strcat(a_string, " ");
      }
    }
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_function[I].fn_start);
    strcat(a_string, wk_strg);

    s = strlen(a_string);
    if (s < 53) 
    {
      for (v = s; v < 53; v++) 
      {
        strcat(a_string, " ");
      }
    }
    strcat(a_string, w_function[I].fn_ret_var);

    s = strlen(a_string);
    if (s < 63) 
    {
      for (v = s; v < 63; v++) 
      {
        strcat(a_string, " ");
      }
    }
    strcat(a_string, w_function[I].fn_fd1);

    s = strlen(a_string);
    if (s < 73) 
    {
      for (v = s; v < 73; v++) 
      {
        strcat(a_string, " ");
      }
    }
    strcat(a_string, w_function[I].fn_fd2);

    s = strlen(a_string);
    if (s < 89) 
    {
      for (v = s; v < 89; v++) 
      {
        strcat(a_string, " ");
      }
    }
    strcat(a_string, w_function[I].fn_fd3);

    strcat(a_string, "\n");
    fputs(a_string, c_src);
  }

  fprintf(c_src, "\n\n---------- constant -----------------\n");
  for (I = 0; I < v_const; I++) 
  {
    fprintf(c_src, "\nRec - %d", w_constant[I].const_rct);
    fprintf(c_src, "   Current  - %s", w_constant[I].const_current);
    fprintf(c_src, "   Use      - %s", w_constant[I].const_use);
  }

  fprintf(c_src, "\n\n-----------  Dynamic Character Literals  ---------\n");
  fprintf(c_src, "Rct     Cname       Value     Lgth  Literal\n");

  for (I = 0; I < cary_ct; I++) 
  {
    snprintf(p_strg, sizeof(p_strg), "%d", w_carry[I].carry_rct);
    strcpy(a_string, p_strg);
    s = strlen(a_string);
    if (s < 8) 
    {
      for (v = s; v < 8; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_carry[I].carry_name);
    s = strlen(a_string);
    if (s < 20) 
    {
      for (v = s; v < 20; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_carry[I].carry_cname);
    s = strlen(a_string);
    if (s < 32) 
    {
      for (v = s; v < 32; v++) 
      {
        strcat(a_string, " ");
      }
    }

    snprintf(p_strg, sizeof(p_strg), "%d", w_carry[I].carry_ct);
    strcat(a_string, p_strg);
    s = strlen(a_string);
    if (s < 37) 
    {
      for (v = s; v < 36; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_carry[I].carry_literal);

    strcat(a_string, "\n");
    fputs(a_string, c_src);
  }
  fprintf(c_src, "\n");


  fprintf(c_src, "\n\n----------------  Character Literals  --------------\n");
  fprintf(c_src, "Rct     Cname       Value               Lgth     Type\n");

  for (I = 0; I < char_ct; I++) 
  {
    snprintf(p_strg, sizeof(p_strg), "%d", w_charlit[I].clit_rct);
    strcpy(a_string, p_strg);
    s = strlen(a_string);
    if (s < 8) 
    {
      for (v = s; v < 8; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_charlit[I].clit_cname);
    s = strlen(a_string);
    if (s < 20) 
    {
      for (v = s; v < 20; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_charlit[I].clit_value);
    s = strlen(a_string);
    if (s < 42) 
    {
      for (v = s; v < 42; v++) 
      {
        strcat(a_string, " ");
      }
    }

    snprintf(p_strg, sizeof(p_strg), "%d", w_charlit[I].clit_lgth);
    strcat(a_string, p_strg);
    s = strlen(a_string);
    if (s < 50) 
    {
      for (v = s; v < 50; v++) 
      {
        strcat(a_string, " ");
      }
    }
    snprintf(p_strg, sizeof(p_strg), "%d", w_charlit[I].clit_type);
    strcat(a_string, p_strg);

    s = strlen(a_string);
    if (s < 60) 
    {
      for (v = s; v < 60; v++) 
      {
        strcat(a_string, " ");
      }
    }
    snprintf(p_strg, sizeof(p_strg), "%d", w_charlit[I].clit_uct);
    strcat(a_string, p_strg);

    strcat(a_string, "\n");
    fputs(a_string, c_src);
  }
  fprintf(c_src, "\n");



  fprintf(c_src, "\n\n---------- Unused Global Variables -----------\n");
  fprintf(c_src, "Rct    ");
  fprintf(c_src, "Name     ");
  fprintf(c_src, "         CName    \n");
 
  for (I = 0; I < gv_ct; I++) 
  {
    if(gw_variable[I].gv_use_ct == 0)
    {
      snprintf(wk_strg, sizeof(wk_strg), "%d", gw_variable[I].gv_rct);
      strcpy(a_string, wk_strg);
      s = strlen(a_string);
      if (s < 7) 
      {
        for (v = s; v < 7; v++) 
        {
          strcat(a_string, " ");
        }
      }

      strcat(a_string, gw_variable[I].gv_name);
      s = strlen(a_string);
      if (s < 25) 
      {
        for (v = s; v < 25; v++) 
        {
          strcat(a_string, " ");
        }
      }

      strcat(a_string, gw_variable[I].gv_cname);
      s = strlen(a_string);
      if (s < 35) 
      {
        for (v = s; v < 35; v++) 
        {
          strcat(a_string, " ");
        }
      }

      strcat(a_string, "\n");
      fputs(a_string, c_src);
    }
  }



  fprintf(c_src, "\n\n------------------------------ Global Variables -------------------------------\n");
  fprintf(c_src, "Rec     Name                   CName         Type  Lgth  Clgth   ID   Value   Literal\n");
  fprintf(c_src, "-----  ----------------------  ------------  ----  ----  ----    --   ------  -------------\n");

  for (I = 0; I < gv_ct; I++) 
  {  
    snprintf(wk_strg, sizeof(wk_strg), "%d", gw_variable[I].gv_rct);
    strcpy(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 7) 
    {
      for (v = s; v < 7; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, gw_variable[I].gv_name);
    s = strlen(a_string);
    if (s < 31) 
    {
      for (v = s; v < 31; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, gw_variable[I].gv_cname);
    s = strlen(a_string);
    if (s < 46) 
    {
      for (v = s; v < 46; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, gw_variable[I].gv_type);
    s = strlen(a_string);
    strcat(a_string, " ");
    snprintf(p_strg, sizeof(p_strg), "%d", gw_variable[I].gv_id);
    strcat(a_string, p_strg);
    if (s < 53) 
    {
      for (v = s; v < 53; v++) 
      {
        strcat(a_string, " ");
      }
    }
    snprintf(p_strg, sizeof(p_strg), "%d", gw_variable[I].gv_lgth);
    strcat(a_string, p_strg);

    s = strlen(a_string);
    if (s < 59) 
    {
      for (v = s; v < 59; v++) 
      {
        strcat(a_string, " ");
      }
    }
    snprintf(p_strg, sizeof(p_strg), "%d", gw_variable[I].gv_current_lgth);
    strcat(a_string, p_strg);

    s = strlen(a_string);
    if (s < 66) 
    {
      for (v = s; v < 66; v++) 
      {
        strcat(a_string, " ");
      }
    }
    snprintf(p_strg, sizeof(p_strg), "%d", gw_variable[I].gv_id);
    strcat(a_string, p_strg);

    s = strlen(a_string);
    if (s < 71) 
    {
      for (v = s; v < 71; v++) 
      {
        strcat(a_string, " ");
      }
    }
    strcat(a_string, gw_variable[I].gv_value);

    s = strlen(a_string);
    if (s < 81) 
    {
      for (v = s; v < 81; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, gw_variable[I].gv_literal);

    strcat(a_string, "\n");
    fputs(a_string, c_src);
  }
  fprintf(c_src, "\nTotal Global Variables = %d\n", I);


  fprintf(c_src, "\n\n---------- Unused Local Variables -----------\n");
  fprintf(c_src, "Rct    ");
  fprintf(c_src, "Name     ");
  fprintf(c_src, "         CName    ");
  fprintf(c_src, " Function\n");

  for (I = 0; I < lv_ct; I++) 
  {
    if(lw_variable[I].lv_use_ct == 0)
    {
      snprintf(wk_strg, sizeof(wk_strg), "%d", lw_variable[I].lv_rct);
      strcpy(a_string, wk_strg);
      s = strlen(a_string);
      if (s < 7) 
      {
        for (v = s; v < 7; v++) 
        {
          strcat(a_string, " ");
        }
      }

      strcat(a_string, lw_variable[I].lv_name);
      s = strlen(a_string);
      if (s < 25) 
      {
        for (v = s; v < 25; v++) 
        {
          strcat(a_string, " ");
        }
      }

      strcat(a_string, lw_variable[I].lv_cname);
      s = strlen(a_string);
      if (s < 35) 
      {
        for (v = s; v < 35; v++) 
        {
          strcat(a_string, " ");
        }
      }

      strcat(a_string, lw_variable[I].lv_func);
      strcat(a_string, "\n");

      fputs(a_string, c_src);
    }
  }




  fprintf(c_src, "\n\n------------------------------------ Local Variables ------------------------------------------\n");
  fprintf(c_src, "Rec     Name                   CName          Function         Type  Lgth  Clgth   ID      Value/Literal\n");
  fprintf(c_src, "-----  ----------------------  -------------  ---------------  ----  ----  -----   ---     -------------\n");


  for (I = 0; I < lv_ct; I++) 
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", lw_variable[I].lv_rct);
    strcpy(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 7) 
    {
      for (v = s; v < 7; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, lw_variable[I].lv_name);
    s = strlen(a_string);
    if (s < 31) 
    {
      for (v = s; v < 31; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, lw_variable[I].lv_cname);
    s = strlen(a_string);
    if (s < 47) 
    {
      for (v = s; v < 47; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, lw_variable[I].lv_func);
    s = strlen(a_string);
    if (s < 64) 
    {
      for (v = s; v < 64; v++) 
      {
        strcat(a_string, " ");
      }
    }
    strcat(a_string, lw_variable[I].lv_type);
    strcat(a_string, " ");
    snprintf(p_strg, sizeof(p_strg), "%d", lw_variable[I].lv_id);
    strcat(a_string, p_strg);

    s = strlen(a_string);
    if (s < 71) 
    {
      for (v = s; v < 71; v++) 
      {
        strcat(a_string, " ");
      }
    }
    snprintf(p_strg, sizeof(p_strg), "%d", lw_variable[I].lv_lgth);
    strcat(a_string, p_strg);


    s = strlen(a_string);
    if (s < 76) 
    {
      for (v = s; v < 77; v++) 
      {
        strcat(a_string, " ");
      }
    }
    snprintf(p_strg, sizeof(p_strg), "%d", lw_variable[I].lv_current_lgth);
    strcat(a_string, p_strg);
/*
    s = strlen(a_string);
    if (s < 84) 
    {
      for (v = s; v < 84; v++) 
      {
        strcat(a_string, " ");
      }
    }
    snprintf(p_strg, sizeof(p_strg), "%d", lw_variable[I].lv_id);
    strcat(a_string, p_strg);

    s = strlen(a_string);
    if (s < 90) 
    {
      for (v = s; v < 90; v++) 
      {
        strcat(a_string, " ");
      }
    }

    ret = strcmp(lw_variable[I].lv_type, "I");
    if (ret == 0) 
    {
      strcat(a_string, lw_variable[I].lv_literal);
    }

    ret = strcmp(lw_variable[I].lv_type, "L");
    if (ret == 0) 
    {
      strcat(a_string, lw_variable[I].lv_value);
    }
*/
    strcat(a_string, "\n");
    fputs(a_string, c_src);
  }

  fprintf(c_src, "\nTotal Local Variables = %d\n", I);


  fprintf(c_src, "\n\n---------- includes -----------------\n");
  for (I = 0; I < i_ct; I++) 
  {
    fprintf(c_src, "\nRec  - %d", w_include[I].include_rct);
    fprintf(c_src, "   Pgm    - %s", w_include[I].include_name);
  }

  if(I == 0)
  {
    fprintf(c_src, "         No Includes\n");
  }

  fprintf(c_src, "\n\n-------------------------------- IF table "
                 "-----------------------------------\n");
  fprintf(c_src, "Rec     Level    EOF1    ELSE1   EOF2   ELSE2   Code \n");
  fprintf(c_src, "-----  -------  ------  ------  ------ -------  "
                 "-------------------------------\n");

  for (I = 0; I < wif_ct; I++) 
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[I].wif_rct);
    strcpy(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 10) 
    {
      for (v = s; v < 10; v++) 
      {
        strcat(a_string, " ");
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[I].wif_level);
    strcat(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 18) 
    {
      for (v = s; v < 18; v++) 
      {
        strcat(a_string, " ");
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[I].wif_eof1);
    strcat(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 26) 
    {
      for (v = s; v < 26; v++) 
      {
        strcat(a_string, " ");
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[I].wif_else1);
    strcat(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 34) 
    {
      for (v = s; v < 34; v++) 
      {
        strcat(a_string, " ");
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", w_if_table[I].wif_eof2);
    strcat(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 42) 
    {
      for (v = s; v < 42; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, "\n");
    fputs(a_string, c_src);
  }

  fprintf(c_src, "\n\n---------- goto table  --------------\n");
  for (I = 0; I < goto_label_ct; I++) 
  {
    fprintf(c_src, "Label RCT = %d", w_goto_label[I].goto_label_rct);
    fprintf(c_src, " Org - %s", w_goto_label[I].goto_org_lb);
    fprintf(c_src, " New - %s\n", w_goto_label[I].goto_label_1);
  }


  fprintf(c_src, "\n\n---------- while table --------------\n");
  for (I = 0; I < wh_ct; I++) 
  {
    fprintf(c_src, "WHILE = %d", w_while_table[I].wh_rct);
    fprintf(c_src, " Level - %d", w_while_table[I].wh_level);
    fprintf(c_src, " EOF - %d", w_while_table[I].wh_eof1);
    fprintf(c_src, " RCT - %s", w_while_table[I].wh_p_string);
  }

  fprintf(c_src, "\n\n----------   for table --------------\n");
  fprintf(c_src, "FOR  Lvl  EOF     INCR     TWO         5b       5c   Type       CODE\n");
  for (I = 0; I < for_ct; I++) 
  {
    s = 0;
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_for_table[I].for_rct);
    strcpy(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 6) 
    {
      for (v = s; v < 6; v++) 
      {
        strcat(a_string, " ");
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", w_for_table[I].for_level);
    strcat(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 10) 
    {
      for (v = s; v < 10; v++) 
      {
        strcat(a_string, " ");
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", w_for_table[I].for_eof1);
    strcat(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 16) 
    {
      for (v = s; v < 16 ; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_for_table[I].for_rt_field);
    s = strlen(a_string);
    if (s < 25) 
    {
      for (v = s; v < 25; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_for_table[I].for_rt_field2);
    s = strlen(a_string);
    if (s < 35) 
    {
      for (v = s; v < 35; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_for_table[I].for_rt_field5b);
    s = strlen(a_string);
    if (s < 45) 
    {
      for (v = s; v < 45; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_for_table[I].for_rt_field5c);
    s = strlen(a_string);
    if (s < 55) 
    {
      for (v = s; v < 55; v++) 
      {
        strcat(a_string, " ");
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", w_for_table[I].for_type);
    strcat(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 61) 
    {
      for (v = s; v < 61 ; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_for_table[I].for_p_string);

     fputs(a_string, c_src);
  }


  fprintf(c_src, "\n\n----------   switch table --------------\n");
  for (I = 0; I < switch_ct; I++) 
  {
    fprintf(c_src, "FOR  = %d", w_switch_table[I].switch_rct);
    fprintf(c_src, " Level - %d", w_switch_table[I].switch_level);
    fprintf(c_src, " EOF - %d", w_switch_table[I].switch_eof1);
    fprintf(c_src, " RCT - %s", w_switch_table[I].switch_p_string);
  }
 


  fprintf(c_src, "\n\n---------- Function Start -----------\n");
  for (I = 0; I < fns_ct; I++) 
  {
    fprintf(c_src, "\nRct = %d", w_func_start[I].fns_rct);
    fprintf(c_src, " Name - %s", w_func_start[I].fns_name);
  }



  fprintf(c_src, "\n\n--------------- Structures ---------------\n");
  fprintf(c_src, "Rec    Name          CName              WName          "
                 "WCName       Field Name         Field CName      Id  Type  "
                 "Lgth  Disp\n");
  fprintf(c_src, "-----  ------------  -----------------  ------------  "
                 "------------  -----------------  --------------- ---- ----  "
                 "----  ----\n");

  for (I = 0; I < m_struc_ct; I++) 
  {
    snprintf(wk_strg, sizeof(wk_strg), "%d", w_struc[I].st_rct);
    ret = strcmp(w_struc[I].st_id, "M");
    if(ret == 0)
    {
        fprintf(c_src, "\n");
    }
    strcpy(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 7) 
    {
      for (v = s; v < 7; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_struc[I].st_name);
    s = strlen(a_string);
    if (s < 23) 
    {
      for (v = s; v < 23; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_struc[I].st_cname);
    s = strlen(a_string);
    if (s < 40) 
    {
      for (v = s; v < 40; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_struc[I].st_wname);
    s = strlen(a_string);
    if (s < 54) 
    {
      for (v = s; v < 54; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_struc[I].st_cwname);
    s = strlen(a_string);
    if (s < 68) 
    {
      for (v = s; v < 68; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_struc[I].st_field_name);
    s = strlen(a_string);
    if (s < 87) 
    {
      for (v = s; v < 87; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_struc[I].st_field_cname);
    s = strlen(a_string);
    if (s < 105) 
    {
      for (v = s; v < 105; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_struc[I].st_id);
    s = strlen(a_string);
    if (s < 110) 
    {
      for (v = s; v < 110; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_struc[I].st_type);
    s = strlen(a_string);
    if (s < 115) 
    {
      for (v = s; v < 115; v++) 
      {
        strcat(a_string, " ");
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", w_struc[I].st_field_lgth);
    strcat(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 120) 
    {
      for (v = s; v < 120; v++) 
      {
        strcat(a_string, " ");
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", w_struc[I].st_disp);
    strcat(a_string, wk_strg);
    s = strlen(a_string);
    if (s < 125) 
    {
      for (v = s; v < 125; v++) 
      {
        strcat(a_string, " ");
      }
    }

    strcat(a_string, w_struc[I].st_field_value);

    strcat(a_string, "\n");
    fputs(a_string, c_src);
  }
  fprintf(c_src, "\n");



  fprintf(c_src, "\n\n---------- TM Value -----------\n");

  strcpy(a_string, "\nRct  = ");
  strcat(a_string, "\n");
  fputs(a_string,c_src);
 
  strcpy(a_string, "Month = ");
 /* strcat(a_string, tm[0].tm_mon); */
  strcat(a_string, "\n");
  fputs(a_string, c_src);
 


  fclose(c_src);
}

void c2_print_files() 
{
  int I;

  for (I = 0; I < f_ct; I++) 
  {
    printf("\nRec  - %d", w_file[I].f_rct);
    printf(" F Name - %s", w_file[I].f_name);
    printf(" C Name - %s", w_file[I].f_cname);
    printf(" Type   - %s", w_file[I].f_type);
    printf(" Buf Ct - %d", w_file[I].f_buf_ct);
    printf(" Perm   - %s\n", w_file[I].f_perm);
  }
}
