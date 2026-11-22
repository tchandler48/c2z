/* ***************************************************
*  c2z : c2z_eoj.c :                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2026                    *
**************************************************** */

/* ***************************************************
*  Punch out EOJ code                                *
* ************************************************** */
void c2_eoj() 
{

  int I = 0;
  int v = 0;
  int ret = 0;
  int ret1 = 0;
  int s = 0;
  int x = 0;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int x10 = 0;

 char field1[VAR_LGTH];
 char tfield2[VAR_LGTH];
 char tfield3[VAR_LGTH];
 char tfield6[VAR_LGTH];
 char tfield9[VAR_LGTH];

  if (var_use[21] > 0) 
  {
    c2_rdp_main();
  }

  if (var_use[11] > 0) 
  {
    c2_isspace();
  }

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj");
  trace_rec_3();
    
  strcpy(a_string, "         EQUREGS");
  src_line();
  strcpy(trace_1, "c2z_eoj EQUREGS #1");
  trace_rec_3();

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj EQUREGS #2");
  trace_rec_3();

  if(var_use[16] > 0)
  {

    strcpy(a_string, "         DC    0D");
    src_line();
    strcpy(trace_1, "c2z_eoj STRLEN #1");
    trace_rec_3();

    strcpy(a_string, "SPCTBL   DC    256X'00'");
    src_line();
    strcpy(trace_1, "c2z_eoj STRLEN #2");
    trace_rec_3();

    strcpy(a_string, "         ORG   SPCTBL+X'40'");
    src_line();
    strcpy(trace_1, "c2z_eoj STRLEN #3");
    trace_rec_3();

    strcpy(a_string, "         DC    X'FF'");
    src_line();
    strcpy(trace_1, "c2z_eoj STRLEN #4");
    trace_rec_3();

    strcpy(a_string, "         ORG   ,");
    src_line();
    strcpy(trace_1, "c2z_eoj STRLEN #5");
    trace_rec_3();
  }
  
  if(work_use_ct[87] > 0)
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj OUTBIG0 #20");
    trace_rec_3();
          
    strcpy(a_string, "OUTBIG0  DS    CL15");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj OUTBIG0 #21");
    trace_rec_3();
          
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj OUTBIG0 #22");
    trace_rec_3();
          
    strcpy(a_string, "EDMASK   DC    X'40'");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj EDMASK #23");
    trace_rec_3();
          
    strcpy(a_string, "         DC    X'20',X'20'");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj EDMASK #24");
    trace_rec_3();
         
    strcpy(a_string, "         DC    X'6B'");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj EDMASK #25");
    trace_rec_3();
          
    strcpy(a_string, "         DC    X'20',X'20',X'20'");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj EDMASK #26");
    trace_rec_3();
          
    strcpy(a_string, "         DC    X'6B'");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj EDMASK #27");
    trace_rec_3();
          
    strcpy(a_string, "         DC    X'20',X'20',X'20'");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj EDMASK #28");
    trace_rec_3();
  
    strcpy(a_string, "         DC    X'6B'");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj EDMASK #29");
    trace_rec_3();
          
    strcpy(a_string, "         DC    X'20',X'21'");
    strcpy(wk_remark, "/* c2a gen variable ");
    write_short();
    strcpy(trace_1, "c2z_eoj EDMASK #30");
    trace_rec_3();
          
    strcpy(a_string, "         DC    X'20'");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj EDMASK #31");
    trace_rec_3();
          
    strcpy(a_string, "         DC    X'C3D9'");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj EDMASK #32");
    trace_rec_3();
          
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "/* c2a gen variable");
    write_short();
    strcpy(trace_1, "c2z_eoj EDMASK #33");
    trace_rec_3();

    strcpy(a_string, "*");
    src_line();
    strcpy(trace_1, "c2z_eoj EDMASK #34");
    trace_rec_3();
  }

/*
  strcpy(a_string, "WKAR1    DS    D");
  src_line();
  strcpy(trace_1, "c2z Parser Var #23");
  trace_rec_3();
*/

  if (var_use[21] > 0) 
  {
    strcpy(a_string, "         DS    0F");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #21a");
    trace_rec_3();

    strcpy(a_string, "SV_RDP   DS    F");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #21b");
    trace_rec_3();

    strcpy(a_string, "         DS    0F");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #21c");
    trace_rec_3();

    strcpy(a_string, "SV_EXP   DS    F");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #21d");
    trace_rec_3();

    strcpy(a_string, "         DS    0F");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #21e");
    trace_rec_3();

    strcpy(a_string, "SV_TRM   DS    F");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #21f");
    trace_rec_3();

    strcpy(a_string, "         DS    0F");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #21g");
    trace_rec_3();

    strcpy(a_string, "SV_FACT  DS    F");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #21h");
    trace_rec_3();

    strcpy(a_string, "         DS    0F");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #21i");
    trace_rec_3();

    strcpy(a_string, "SV_MAT   DS    F");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #21j");
    trace_rec_3();

    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #XXX");
    trace_rec_3();

    strcpy(a_string, "MLF001   DC    6PL'0'");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #XXX");
    trace_rec_3();

    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #XXX");
    trace_rec_3();

    strcpy(a_string, "MLF002   DC    C' '");
    src_line();
    strcpy(trace_1, "c2z_eoj rdp-main #XXX");
    trace_rec_3();


  }

  if(sv_ct > 0)
  {
    strcpy(a_string, "         DS    0F");
    src_line();
    strcpy(trace_1, "c2z_eoj save_reg #1");
    trace_rec_3();
  }
  
  for(I = 0; I < sv_ct; I++)
  {
    strcpy(a_string, "SVSUB_");
    snprintf(wk_strg, sizeof(wk_strg), "%d", I);
    strcat(a_string, wk_strg);
    check_length();
    strcat(a_string, "DS    F");
    src_line();
    strcpy(trace_1, "c2z_eoj save_reg");
    trace_rec_3();
  }

  
  strcpy(a_string, "* Character Literals ");
  src_line();
  strcpy(trace_1, "c2z_eoj Char Literal #1");
  trace_rec_3();
  
  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj Char Literal #2");
  trace_rec_3();
  
  for (I = 0; I < lit_ct; I++) 
  {
    s = strlen(w_charlit[I].clit_value);
    if(s == 0)
    {
      strcpy(w_charlit[I].clit_value, " ");
    }

    strcpy(a_string, w_charlit[I].clit_cname);
    check_length();
    strcat(a_string, "DC    C'");
    strcat(a_string, w_charlit[I].clit_value);
    strcat(a_string, "'");
    src_line();
    strcpy(trace_1, "c2z_eoj Char Literal #3");
    trace_rec_3();
    
    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z_eoj Cbar Literal #4");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj Math Literal #7");
  trace_rec_3();
  
  for (I = 0; I < gv_ct; I++) 
  {
    convert = 0;
    ret = strcmp(gw_variable[I].gv_type, "I");
    if (ret == 0) 
    {
      strcpy(wk_strg, gw_variable[I].gv_cname);
      strcpy(field1, gw_variable[I].gv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();
      strcat(a_string, "DC    ");
      x = atoi(gw_variable[I].gv_value);
      if (x == 0) 
      {
        strcat(a_string, "PL6'0'");
      } 
      else 
      {
        strcat(a_string, "PL6'");
        strcat(a_string, gw_variable[I].gv_value);
        strcat(a_string, "'");
      }
      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, gw_variable[I].gv_name);
      strcat(a_string, "  */");
      src_line();
      strcpy(trace_1, "c2z_eoj Math Literal #8");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         DS    0H");
  src_line();
  strcpy(trace_1, "c2z_eoj GLOBAL #1");
  trace_rec_3();
  
  for (I = 0; I < gv_ct; I++) 
  {
    convert = 0;
    ret = strcmp(gw_variable[I].gv_type, "U");
    if (ret == 0) 
    {
      strcpy(wk_strg, gw_variable[I].gv_cname);
      strcpy(field1, gw_variable[I].gv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();
      strcat(a_string, "DC    ");
      x = atoi(gw_variable[I].gv_value);
      if (x == 0) 
      {
        strcat(a_string, "PL6'0'");
      } 
      else 
      {
        strcat(a_string, "PL6'");
        strcat(a_string, gw_variable[I].gv_value);
        strcat(a_string, "'");
      }
      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, gw_variable[I].gv_name);
      strcat(a_string, "  */");
      src_line();
      strcpy(trace_1, "c2z_eoj Math Literal #8");
      trace_rec_3();
    }
  }

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj GLOBAL #2");
  trace_rec_3();
  
  strcpy(a_string, "* Global Variables ");
  src_line();
  strcpy(trace_1, "c2z_eoj GLOBAL #3");
  trace_rec_3();
  
  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj GLOBAL #4");
  trace_rec_3();
  
  for (I = 0; I < gv_ct; I++) 
  {
    convert = 0;
    x = 0;
    x2 = 0;
    x4 = 0;
    ret = strcmp(gw_variable[I].gv_type, "L");
    if (ret == 0) 
    {
      for (x3 = 0; x3 < v_const; x3++) 
      {
        strcpy(wk_strg, gw_variable[I].gv_name);
        strcpy(field1, gw_variable[I].gv_name);
        strcpy(a_string, wk_strg);
        check_length();
        /*  see if field1 is in w_constant */
        x2 = strcmp(field1, w_constant[x3].const_current);
        if (x2 == 0) 
        {
          x4 = 1;
          x = strcmp(field1, w_constant[x3].const_use);
          if (x == 0) 
          {
            x10 = strlen(gw_variable[I].gv_literal);
            strcat(a_string, "DC    ");
            strcat(a_string, "C");
            strcat(a_string, "'");
            if (x10 == 0) 
            {
              strcat(a_string, " ");
            }

            if (x10 != 0) 
            {
              strcat(a_string, gw_variable[I].gv_literal);
            }

            strcat(a_string, "'");
            src_line();
            strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #5");
            trace_rec_3();
            
            x5 = gw_variable[I].gv_lgth;
            x5++;

            strcpy(a_string, "         DS    0H");
            src_line();
            strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #6");
            trace_rec_3();
            break;
          }
        }
      }

      if (x4 != 1) 
      {
        strcpy(a_string, gw_variable[I].gv_name);
        check_length();
        strcat(a_string, "DC    ");
        strcat(a_string, "C");
        strcat(a_string, "'");
        strcat(a_string, gw_variable[I].gv_literal);
        strcat(a_string, " '");
        src_line();
        strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #7");
        trace_rec_3();
        
        x5 = gw_variable[I].gv_lgth;
        x5++;

        strcpy(a_string, "         DS    0H");
        src_line();
        strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #8");
        trace_rec_3();
      }
    }
  }

  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp("A", gw_variable[I].gv_type);
    if (ret == 0) 
    {
      strcpy(a_string, gw_variable[I].gv_table);
      check_length();
      strcat(a_string, "DS    ");

      snprintf(wk_strg, sizeof(wk_strg), "%d", gw_variable[I].gv_row);
      strcat(a_string, wk_strg);
      strcat(a_string, "CL(");
      strcat(a_string, gw_variable[I].gv_label);
      strcat(a_string, ")");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #11");
      trace_rec_3();
      
      strcpy(a_string, "*");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #12");
      trace_rec_3();
      
      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();
      strcat(a_string, "DS    ");
      strcat(a_string, "PL6'0'");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #12a");
      trace_rec_3();
    }
  }

  for (I = 0; I < gv_ct; I++) 
  {
    convert = 0;
    ret = strcmp(gw_variable[I].gv_type, "G");
    if ((ret == 0) && (convert == 0)) 
    {
      strcpy(a_string, "         DS    0H");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #13");
      trace_rec_3();
     
      strcpy(field1, gw_variable[I].gv_name);
      for (v = 0; v < gv_ct; v++) 
      {
        ret = strcmp(field1, gw_variable[v].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          x = gw_variable[v].gv_row;
        }
      }

      strcpy(a_string, gw_variable[I].gv_table);
      check_length();
      strcat(a_string, "DC    ");

      x = arry_sz;

      snprintf(wk_strg, sizeof(wk_strg), "%d", x);
      strcat(a_string, wk_strg);
      strcat(a_string, "PL6'0'");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #14");
      trace_rec_3();
      
      strcpy(a_string, "*");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #15");
      trace_rec_3();
    }
  }

  for (I = 0; I < m_struc_ct; I++) 
  {
    convert = 0;
    x3 = 0;
    ret = strcmp(w_struc[I].st_id, "M");
    if ((ret == 0) && (convert == 0)) 
    {
      strcpy(tfield9, w_struc[I].st_name);
      strcat(tfield9, "_max_ct");
      if (x3 == 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield9, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            x2 = atoi(gw_variable[v].gv_value);
          }
        }
      }

      strcpy(a_string, "         DS    0H");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj STRUCTURE #1");
      trace_rec_3();
      
      x2 = 25;
      strcpy(a_string, w_struc[I].st_cwname);
      strcat(a_string, "T");
      check_length();
      strcat(a_string, "DS    ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", x2);
      strcat(a_string, wk_strg);
      strcat(a_string, "CL(");
      strcpy(tfield2, w_struc[I].st_cwname);
      strcat(tfield2, "L");
      strcat(a_string, tfield2);
      strcat(a_string, ")");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj STRUCTURE #2");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         DS    0H");
  src_line();
  strcpy(trace_1, "c2z_eoj c2_eoj STRUCTURE #3");
  trace_rec_3();
  
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp("D", gw_variable[I].gv_type);
    if (ret == 0) 
    {
      strcpy(wk_strg, gw_variable[I].gv_cname);
      strcpy(field1, gw_variable[I].gv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();
      strcat(a_string, "DS    ");
      x = strlen(gw_variable[I].gv_value);

      strcat(a_string, "PL6'0'");
     
      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, gw_variable[I].gv_name);
      strcat(a_string, "  */");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj global #18");
      trace_rec_3();
      
      strcpy(a_string, "         DS    0H");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj STRUCTURE #4");
      trace_rec_3();
    }
  }

  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp("D", lw_variable[I].lv_type);
    if (ret == 0) 
    {
      strcpy(wk_strg, lw_variable[I].lv_cname);
      strcpy(field1, lw_variable[I].lv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, lw_variable[I].lv_cname);
      check_length();
      strcat(a_string, "DS    ");
      x = strlen(lw_variable[I].lv_value);

      strcat(a_string, "PL6'0'");
     
      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, lw_variable[I].lv_name);
      strcat(a_string, "  */");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #18");
      trace_rec_3();
      
      strcpy(a_string, "         DS    0H");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #21");
      trace_rec_3();
    }
  }

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #20");
  trace_rec_3();
  
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(gw_variable[I].gv_type, "F");
    if (ret == 0) 
    {
      strcpy(wk_strg, gw_variable[I].gv_cname);
      strcpy(field1, gw_variable[I].gv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();

      strcat(a_string, "DS    ");
      x = strlen(gw_variable[I].gv_value);
      if (x == 0) 
      {
        strcat(a_string, "F'0'");
      }
      else 
      {
        strcat(a_string, "F'");
        strcat(a_string, gw_variable[I].gv_value);
        strcat(a_string, "'");
      }

      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, gw_variable[I].gv_name);
      strcat(a_string, "  */");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #19");
      trace_rec_3();
      
      convert = 1;
    }
  }

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #22");
  trace_rec_3();
  
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(gw_variable[I].gv_type, "C");
    if (ret == 0) 
    {
      strcpy(wk_strg, gw_variable[I].gv_cname);
      strcpy(field1, gw_variable[I].gv_cname);
      strcpy(a_string, field1);
      check_length();
      strcat(a_string, "DC    ");
      strcat(a_string, "CL");
      snprintf(wk_strg, sizeof(wk_strg), "%d", gw_variable[I].gv_lgth);
      strcat(a_string, wk_strg);

      /* check for value field to see if char is being set	*/

      strcat(a_string, "' '"); 
      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }

      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #23");
      trace_rec_3();
      
      if (gw_variable[I].gv_lgth % 2 == 0) 
      {
      } 
      else 
      {
        strcpy(a_string, "         DS    0H");
        src_line();
        strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #21");
        trace_rec_3();
      }
      convert = 1;
    }
  }

  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(gw_variable[I].gv_type, "X");
    if (ret == 0) 
    {
      strcpy(wk_strg, gw_variable[I].gv_cname);
      strcpy(field1, gw_variable[I].gv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();

      strcat(a_string, "DC    ");
      strcat(a_string, "X'");
      strcat(a_string, gw_variable[I].gv_value);
      strcat(a_string, "'");

      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj GLOBAL #22");
      trace_rec_3();
    }
  }

  for (I = 0; I < m_struc_ct; I++) 
  {
    x3 = 0;
    ret = strcmp(w_struc[I].st_id, "N");
    if (ret == 0)
    {
      ret1 = strcmp(w_struc[I].st_type, "I");
      if(ret1 == 0)
      {
        strcpy(a_string, "         DS    0H");
        src_line();
        strcpy(trace_1, "c2z_eoj c2_eoj struct #10");
        trace_rec_3();
        
        strcpy(a_string, w_struc[I].st_field_cname);
        check_length();
        strcat(a_string, "DC    PL6'0'");
        strcpy(wk_remark, " ");
        strcat(wk_remark, w_struc[I].st_field_name);
        strcat(wk_remark, " */");
        write_remark();
        strcpy(trace_1, "c2z_eoj c2_eoj struct #11");
        trace_rec_3();
      }

      ret1 = strcmp(w_struc[I].st_type, "C");
      if(ret1 == 0)
      {
        strcpy(a_string, "         DS    0H");
        src_line();
        strcpy(trace_1, "c2z_eoj c2_eoj struct #12");
        trace_rec_3();
        
        strcpy(a_string, w_struc[I].st_field_cname);
        check_length();
        strcat(a_string, "DC    CL");
        snprintf(wk_strg, sizeof(wk_strg), "%d", w_struc[I].st_field_lgth);
        strcat(a_string, wk_strg);
        strcat(a_string, "' '");
        strcpy(wk_remark, " ");
        strcat(wk_remark, w_struc[I].st_field_name);
        strcat(wk_remark, " */");
        write_remark();
        strcpy(trace_1, "c2z_eoj c2_eoj struct #13");
        trace_rec_3();
      }
    }
  }

  for (I = 0; I < gv_ct; I++) 
  {
    x3 = 0;

    ret1 = strcmp(gw_variable[I].gv_type, "3");
    if(ret1 == 0)
    {
      strcpy(a_string, "         DS    0H");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj 3D Char #1");
      trace_rec_3();
     
      strcpy(a_string, gw_variable[I].gv_cname);
      check_length();
      strcat(a_string, "DS    ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", gw_variable[I].gv_lgth);
      strcat(a_string, wk_strg);
      strcat(a_string, "C");
      strcpy(wk_remark, " ");
      strcat(wk_remark, gw_variable[I].gv_name);
      strcat(wk_remark, " */");
      write_remark();
      strcpy(trace_1, "c2z_eoj c2_eoj 3D Char #2");
      trace_rec_3();
    }
  }

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj c2_eoj Local Varialbles");
  trace_rec_3();
  
  strcpy(a_string, "* Local Variables ");
  src_line();
  strcpy(trace_1, "c2z_eoj c2_eoj Local Varialbles");
  trace_rec_3();

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj c2_eoj Local Varialbles");
  trace_rec_3();
  
  strcpy(a_string, "         DS    0H");
  src_line();
  strcpy(trace_1, "c2z_eoj c2_eoj Local Varialbles");
  trace_rec_3();
  
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(lw_variable[I].lv_type, "I");
    if (ret == 0) 
    {
      strcpy(a_string, "         DS    0H");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj Local Varialbles");
      trace_rec_3();
  
      strcpy(wk_strg, lw_variable[I].lv_cname);
      strcpy(field1, lw_variable[I].lv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, lw_variable[I].lv_cname);
      check_length();

      strcat(a_string, "DC    ");
      x = atoi(lw_variable[I].lv_value);
      if (x == 0) 
      {
        strcat(a_string, "PL6'0'");
      } 
      else 
      {
        strcat(a_string, "PL6'");
        strcat(a_string, lw_variable[I].lv_value);
        strcat(a_string, "'");
      }

      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj Local Varialbles");
      trace_rec_3();
    }
  }
  
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(lw_variable[I].lv_type, "U");
    if (ret == 0) 
    {
      strcpy(a_string, "         DS    0H");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj Local Varialbles");
      trace_rec_3();
       
      strcpy(wk_strg, lw_variable[I].lv_cname);
      strcpy(field1, lw_variable[I].lv_cname);
      strcpy(a_string, wk_strg);
      s = strlen(wk_strg);
      strcpy(a_string, lw_variable[I].lv_cname);
      check_length();

      strcat(a_string, "DC    ");
      x = atoi(lw_variable[I].lv_value);
      if (x == 0) 
      {
        strcat(a_string, "PL6'0'");
      } 
      else 
      {
        strcat(a_string, "PL6'");
        strcat(a_string, lw_variable[I].lv_value);
        strcat(a_string, "'");
      }

      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj Local Varialbles");
      trace_rec_3();
    }
  }

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj c2_eoj Local Varialbles");
  trace_rec_3();

  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(lw_variable[I].lv_type, "C");
    if (ret == 0) 
    {
      strcpy(wk_strg, lw_variable[I].lv_cname);
      strcpy(field1, lw_variable[I].lv_cname);
      strcpy(a_string, field1);
      check_length();

      strcat(a_string, "DC    ");
      strcat(a_string, "CL");
      if (lw_variable[I].lv_lgth == 0) 
      {
        lw_variable[I].lv_lgth = 1;
      }
      snprintf(wk_strg, sizeof(wk_strg), "%d", lw_variable[I].lv_lgth);
      strcat(a_string, wk_strg);


      ret1 = strcmp(" ", lw_variable[I].lv_value);
      if (ret1 != 0) 
      {
        strcat(a_string, "'");
        strcat(a_string, lw_variable[I].lv_value);
        strcat(a_string, " '");
      }

      s = strlen(a_string);
      x = 37 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, lw_variable[I].lv_name);

      strcat(a_string, "  */");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj Local Varialbles");
      trace_rec_3();
     
      if (lw_variable[I].lv_lgth % 2 == 0) 
      {
      }
      else 
      {
        strcpy(a_string, "         DS    0H");
        src_line();
        strcpy(trace_1, "c2z_eoj c2_eoj Local Varialbles");
        trace_rec_3();
      }
    }
  }

  strcpy(a_string, "         LTORG");
  src_line();
  strcpy(trace_1, "c2z Parser Var #1");
  trace_rec_3();
  
  if (work_use_ct[1] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z Parser Var #2");
    trace_rec_3();
    
    strcpy(a_string, "C370ISAL DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #3");
    trace_rec_3();
  }

  if (work_use_ct[2] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z Parser Var #4");
    trace_rec_3();
    
    strcpy(a_string, "C370L1   DC    C' '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #5");
    trace_rec_3();
  }

  if (work_use_ct[2] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z Parser Var #6");
    trace_rec_3();
    
    strcpy(a_string, "C370L2   DC    C' '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #7");
    trace_rec_3();
  }

  if (work_use_ct[4] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z Parser Var #8");
    trace_rec_3();
    
    strcpy(a_string, "*C370L3   DC    C'   '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #9");
    trace_rec_3();
  }

  if (work_use_ct[5] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z Parser Var #10");
    trace_rec_3();
    
    strcpy(a_string, "*C370L4   DC    C'    '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #11");
    trace_rec_3();
  }

  if (work_use_ct[6] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z Parser Var #12");
    trace_rec_3();
   
    strcpy(a_string, "*C370L5   DC    C'     '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #13");
    trace_rec_3();
  }

  if (work_use_ct[7] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z Parser Var #14");
    trace_rec_3();
    
    strcpy(a_string, "*C370L6   DC    C'      '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #15");
    trace_rec_3();
  }

  if (work_use_ct[8] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #16");
    trace_rec_3();
    
    strcpy(a_string, "C370L8A  DC    CL8' '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #17");
    trace_rec_3();
  }

  if (work_use_ct[9] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #18");
    trace_rec_3();
    
    strcpy(a_string, "C370L8   DC    C'        '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #19");
    trace_rec_3();
  }

  if (work_use_ct[10] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #20");
    trace_rec_3();
    
    strcpy(a_string, "C370L80  DC    CL80' '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #21");
    trace_rec_3();
  }

  if (work_use_ct[11] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #20");
    trace_rec_3();
    
    strcpy(a_string, "C370MTOT DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #21");
    trace_rec_3();
  }

  if (work_use_ct[12] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #22");
    trace_rec_3();
    
    strcpy(a_string, "C370THR  DC    PL6'3'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #23");
    trace_rec_3();
  }

  if (work_use_ct[13] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #24");
    trace_rec_3();
    
    strcpy(a_string, "C370FOUR DC    PL6'4'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #25");
    trace_rec_3();
  }

  if (work_use_ct[14] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #26");
    trace_rec_3();
    
    strcpy(a_string, "C370MT3  DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #27");
    trace_rec_3();
  }

  if (work_use_ct[15] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #28");
    trace_rec_3();
    
    strcpy(a_string, "C370MT4  DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #29");
    trace_rec_3();
  }

  if (work_use_ct[16] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #30");
    trace_rec_3();
    
    strcpy(a_string, "C370MT5  DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #31");
    trace_rec_3();
  }

  if (work_use_ct[17] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #32");
    trace_rec_3();
    
    strcpy(a_string, "C370PTOT DC    PL6'0'");
    strcpy(wk_remark, "cz2 gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #33");
    trace_rec_3();
  }

  if (work_use_ct[18] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #34");
    trace_rec_3();
    
    strcpy(a_string, "C370PT1  DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #35");
    trace_rec_3();
  }

  if (work_use_ct[19] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #36");
    trace_rec_3();
    
    strcpy(a_string, "C370PT2  DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #37");
    trace_rec_3();
  }

  if (work_use_ct[20] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #38");
    trace_rec_3();
    
    strcpy(a_string, "C370PT3  DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #39");
    trace_rec_3();
  }

  if (work_use_ct[21] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #40");
    trace_rec_3();
    
    strcpy(a_string, "C370PT4  DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #41");
    trace_rec_3();
  }

  if (work_use_ct[23] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #44");
    trace_rec_3();
    
    strcpy(a_string, "*C370CLCT DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #45");
    trace_rec_3();
  }

  if (work_use_ct[24] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #46");
    trace_rec_3();
    
    strcpy(a_string, "C370FIVE DC    PL6'5'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #47");
    trace_rec_3();
  }

  if (work_use_ct[25] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #46");
    trace_rec_3();
    
    strcpy(a_string, "C370EDW2 DC    X'40202120'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #47");
    trace_rec_3();
  }

  if (work_use_ct[26] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z.eoj Parser Var #46");
    trace_rec_3();
    
    strcpy(a_string, "C370RET  DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z.eoj Parser Var #47");
    trace_rec_3();
  }


  if (work_use_ct[29] > 0) 
  {
    strcpy(a_string, "         DS    0F");
    src_line();
    strcpy(trace_1, "c2z Parser Var #29a");
    trace_rec_3();
    
    strcpy(a_string, "SAVEAREA DS    F");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #29b");
    trace_rec_3();

    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z Parser Var #29c");
    trace_rec_3();

    strcpy(a_string, "INBUF    DC    CL70' '");
    src_line();
    strcpy(trace_1, "c2z Parser Var #29d");
    trace_rec_3();
  }

  if (work_use_ct[30] > 0) 
  {
    strcpy(a_string, "         DS    0F");
    src_line();
    strcpy(trace_1, "c2z Parser Var #30a");
    trace_rec_3();
    
    strcpy(a_string, "C370DTIM DC    C'HH:MM:SS:TH '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #30b");
    trace_rec_3();
  }

  if (work_use_ct[31] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z Parser Var #30a");
    trace_rec_3();
    
    strcpy(a_string, "C370PTIM DS    PL5");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #30b");
    trace_rec_3();
  }


  if (work_use_ct[32] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #60");
    trace_rec_3();
    
    strcpy(a_string, "C370ZERO DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #61");
    trace_rec_3();
  }

  if (work_use_ct[33] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #62");
    trace_rec_3();
    
    strcpy(a_string, "C370ONE  DC    PL6'1'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #63");
    trace_rec_3();
  }

  if (work_use_ct[34] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #64");
    trace_rec_3();
    
    strcpy(a_string, "C370TWO  DC    PL6'2'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #65");
    trace_rec_3();
  }

  if (work_use_ct[35] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #66");
    trace_rec_3();
    
    strcpy(a_string, "C370UCA  DC    C'A'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #67");
    trace_rec_3();
  }

  if (work_use_ct[36] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #36");
    trace_rec_3();
    
    strcpy(a_string, "C370UCZ  DC    C'Z'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #36");
    trace_rec_3();
  }

  if (work_use_ct[37] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #70");
    trace_rec_3();
    
    strcpy(a_string, "C370LCA  DC    C'a'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #71");
    trace_rec_3();
  }

  if (work_use_ct[38] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #72");
    trace_rec_3();
    
    strcpy(a_string, "C370LCZ  DC    C'z'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #73");
    trace_rec_3();
  }

  if (work_use_ct[39] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #74");
    trace_rec_3();
   
    strcpy(a_string, "C370MATH DC    PL9'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #75");
    trace_rec_3();
  }

  if (work_use_ct[40] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #76");
    trace_rec_3();
   
    strcpy(a_string, "C370DEND DS    0CL13");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #77");
    trace_rec_3();
    
    strcpy(a_string, "C370IENT DS    PL7");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #78");
    trace_rec_3();
       
    strcpy(a_string, "REMAINDR DS    PL6");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #79");
    trace_rec_3();
  }

  if (work_use_ct[43] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #84");
    trace_rec_3();
    
    strcpy(a_string, "C370ISOR DS    PL6");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #85");
    trace_rec_3();
  }

  if (work_use_ct[44] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #86");
    trace_rec_3();
   
    strcpy(a_string, "C370MLT1 DS    PL8");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #87");
    trace_rec_3();
  }

  if (work_use_ct[45] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #88");
    trace_rec_3();
    
    strcpy(a_string, "C370MLT2 DS    PL8");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #89");
    trace_rec_3();
  }

  if (work_use_ct[46] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #90");
    trace_rec_3();
    
    strcpy(a_string, "C370MLT3 DS    PL8");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #91");
    trace_rec_3();
  }

  if (work_use_ct[47] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z Parser Var #47a");
    trace_rec_3();
    
    strcpy(a_string, "C370TWRK  DS    CL10");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #47b");
    trace_rec_3();
  }


  if (work_use_ct[48] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #94");
    trace_rec_3();
    
    strcpy(a_string, "C370U    DS    D");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #95");
    trace_rec_3();
  }

  if (work_use_ct[49] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #96");
    trace_rec_3();
    
    strcpy(a_string, "C370NWK1 DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #97");
    trace_rec_3();
  }

  if (work_use_ct[50] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #50a");
    trace_rec_3();
    
    strcpy(a_string, "C370NWK2 DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #50b");
    trace_rec_3();
  }

  if (work_use_ct[51] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #51a");
    trace_rec_3();
    
    strcpy(a_string, "INBUF     DC    CL70' '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #51b");
    trace_rec_3();
  }


  if (work_use_ct[52] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #102");
    trace_rec_3();
    
    strcpy(a_string, "C370B1   DC    C' '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #103");
    trace_rec_3();
  }

  if (work_use_ct[53] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #104");
    trace_rec_3();
    
    strcpy(a_string, "C370B8   DC    C'        '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #105");
    trace_rec_3();
  }

  if (work_use_ct[54] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #54");
    trace_rec_3();
    
    strcpy(a_string, "C370L10  DC    CL' '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #54");
    trace_rec_3();
  }

  if (work_use_ct[59] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #116");
    trace_rec_3();
    
    strcpy(a_string, "C370L1A  DC    C' '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #117");
    trace_rec_3();
  }

  if (work_use_ct[60] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #118");
    trace_rec_3();
   
    strcpy(a_string, "C370TDD3 DC    C'      '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #119");
    trace_rec_3();
  }

  if (work_use_ct[61] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #120");
    trace_rec_3();
    
    strcpy(a_string, "C370D3DW DC    X'21204B202020'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #121");
    trace_rec_3();
  }

  if (work_use_ct[62] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #62a");
    trace_rec_3();
    
    strcpy(a_string, "WKAR1    DC    C' '");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #62b");
    trace_rec_3();
  }
  

  if (work_use_ct[63] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #124");
    trace_rec_3();
    
    strcpy(a_string, "C370LNIN DC    C'9'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #125");
    trace_rec_3();
  }

  if (work_use_ct[65] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #126");
    trace_rec_3();
    
    strcpy(a_string, "C370NN3  DC    PL6'-999'");
    strcpy(wk_remark, "c2z neg(3)  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #127");
    trace_rec_3();
  }

  if ((work_use_ct[66] > 0) || (work_use_ct[67] > 0)) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #66a");
    trace_rec_3();
    
    strcpy(a_string, "MLF001   DC    PL6'0'");
    strcpy(wk_remark, "c2z neg(3)  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #66b");
    trace_rec_3();

    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #67a");
    trace_rec_3();
    
    strcpy(a_string, "MLF002   DC    PL6'0'");
    strcpy(wk_remark, "c2z neg(3)  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #67b");
    trace_rec_3();

    strcpy(a_string, "         DS    0F");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #67c");
    trace_rec_3();

    strcpy(a_string, "SVSUB_1  DS    F");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #67d");
    trace_rec_3();
  }

  if (work_use_ct[68] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #68a");
    trace_rec_3();
    
    strcpy(a_string, "MLF003   DC    C' '");
    strcpy(wk_remark, " ch */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #68b");
    trace_rec_3();

    strcpy(a_string, "         DS    0F");
    src_line();
    strcpy(trace_1, "c2z Parser Var #68c");
    trace_rec_3();

    strcpy(a_string, "SVSUB_2  DS    F");
    strcpy(wk_remark, " SVSUB_2 */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #68d");
    trace_rec_3();
  }

  if (work_use_ct[69] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z Parser Var #69a");
    trace_rec_3();
    
    strcpy(a_string, "MLF004   DC    PL6'0'");
    strcpy(wk_remark, " pi */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #69b");
    trace_rec_3();
  }

  if (work_use_ct[70] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    src_line();
    strcpy(trace_1, "c2z Parser Var #70a");
    trace_rec_3();
    
    strcpy(a_string, "MLF005   DC    PL6'0'");
    strcpy(wk_remark, " p_string */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #70b");
    trace_rec_3();
  }


  if (work_use_ct[72] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #138");
    trace_rec_3();
    
    strcpy(a_string, "C370XXX  DC    C''''");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #139");
    trace_rec_3();
  }

  if (work_use_ct[73] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #140");
    trace_rec_3();
    
    strcpy(a_string, "C370LPCT DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #141");
    trace_rec_3();
  }

  if (work_use_ct[74] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #142");
    trace_rec_3();
    
    strcpy(a_string, "C370EOF  DC    X'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #143");
    trace_rec_3();
  }

  if (work_use_ct[75] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();  
    strcpy(trace_1, "c2z Parser Var #144");
    trace_rec_3();
    
    strcpy(a_string, "C370PER  DC    C'.'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #145");
    trace_rec_3();
  }

  if (work_use_ct[78] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();  
    strcpy(trace_1, "c2z Parser Var #150");
    trace_rec_3();
    
    strcpy(a_string, "C370NWK3 DC    PL6'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #151");
    trace_rec_3();
  }

  if (work_use_ct[79] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();  
    strcpy(trace_1, "c2z Parser Var #152");
    trace_rec_3();
    
    strcpy(a_string, "C370FONE DC    F'1'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #153");
    trace_rec_3();
  }

  if (work_use_ct[80] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();  
    strcpy(trace_1, "c2z Parser Var #154");
    trace_rec_3();
    
    strcpy(a_string, "C370DIGT DC    PL6'0'");
    strcpy(wk_remark, "ISDIGIT ret */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #155");
    trace_rec_3();
  }

  if (work_use_ct[81] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();  
    strcpy(trace_1, "c2z Parser Var #156");
    trace_rec_3();
    
    strcpy(a_string, "C370COLN DC    C':'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #157");
    trace_rec_3();
 }

  if (work_use_ct[82] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();  
    strcpy(trace_1, "c2z Parser Var #158");
    trace_rec_3();
    
    strcpy(a_string, "C370NONE DC    PL6'-1'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #159");
    trace_rec_3();
  }

  if ((work_use_ct[27] > 0) || (work_use_ct[28] > 0)) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #164");
    trace_rec_3();
    
    strcpy(a_string, "C370DTTM DC    XL16'00'"); 
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #165");
    trace_rec_3();
    
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #166");
    trace_rec_3();
    
    strcpy(a_string, "C370DWRK DC    XL9'00'"); 
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #167");
    trace_rec_3();
    
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #168");
    trace_rec_3();
    
    strcpy(a_string, "C370DDTE DC    C'MM/DD/YY'");
    src_line();
    strcpy(trace_1, "c2z Parser Var #169");
    trace_rec_3();
  }

  if(work_use_ct[28] > 0)
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #168");
    trace_rec_3();
 
    strcpy(a_string,"C370MTIM  DC    C' ',X'2120',C':',X'2020',C':',X'2020',C':',X'2020'");
    src_line();
    strcpy(trace_1, "c2z Parser Var #169a");
    trace_rec_3();
  }

  if (work_use_ct[86] > 0) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #162");
    trace_rec_3();
    
    strcpy(a_string, "C370ECB  DC    F'0'");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #163");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z Parser Var #300");
  trace_rec_3();
  
  strcpy(a_string, "         DS    0H");
  strcpy(wk_remark, "c2z gen variable  */");
  write_short();
  strcpy(trace_1, "c2z Parser Var #301");
  trace_rec_3();
  
  strcpy(a_string, "C370WTO  DC    AL2(C370WTOE-*,0)");
  strcpy(wk_remark, "c2z gen variable  */");
  write_short();
  strcpy(trace_1, "c2z Parser Var #302");
  trace_rec_3();
  
  strcpy(a_string, "C370WTOB DC    CL78' '");
  strcpy(wk_remark, "c2z gen variable  */");
  write_short();
  strcpy(trace_1, "c2z Parser Var #302");
  trace_rec_3();
  
  strcpy(a_string, "C370WTOE EQU   *");
  strcpy(wk_remark, "c2z gen variable  */");
  write_short();
  strcpy(trace_1, "c2z Parser Var #303");
  trace_rec_3();
  
  strcpy(a_string, "C370WTOL EQU   *-C370WTOB");
  strcpy(wk_remark, "c2z gen variable  */");
  write_short();
  strcpy(trace_1, "c2z Parser Var #303");
  trace_rec_3();
  
  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z Parser Var #304");
  trace_rec_3();
  
  for (I = 0; I < cary_ct; I++) 
  {
    strcpy(a_string, "         DS    0H");
    strcpy(wk_remark, "c2z gen variable  */");
    write_short();
    strcpy(trace_1, "c2z Parser Var #89");
    trace_rec_3();
    
    strcpy(a_string, w_carry[I].carry_cname);
    check_length();
    strcat(a_string, "DC    ");
    strcat(a_string, "C'");
    strcat(a_string, w_carry[I].carry_literal);
    strcat(a_string, "'");
    src_line();
    strcpy(trace_1, "c2z Parser Var #112");
    trace_rec_3();
  }

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z Parser Var #112");
  trace_rec_3();
  
  for (I = 0; I < gv_ct; I++) 
  {
    convert = 0;
    ret = strcmp(gw_variable[I].gv_type, "A");
    if ((ret == 0) && (convert == 0)) 
    {
      strcpy(a_string, gw_variable[I].gv_dsect);
      check_length();
      strcat(a_string, "DSECT");
      strcpy(wk_remark, " ");
      strcpy(wk_remark, gw_variable[I].gv_table);
      strcpy(wk_remark, " */");
      write_remark();
      strcpy(trace_1, "c2z_eoj c2_eoj char array #1");
      trace_rec_3();
      
      strcpy(a_string, gw_variable[I].gv_aname);
      check_length();
      strcat(a_string, "DS    CL");
      snprintf(wk_strg, sizeof(wk_strg), "%d", gw_variable[I].gv_column);
      strcat(a_string, wk_strg);
      strcat(a_string, "' '");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj char array #2");
      trace_rec_3();
     
      strcpy(a_string, gw_variable[I].gv_label);
      check_length();
      strcat(a_string, "EQU   *-");
      strcat(a_string, gw_variable[I].gv_dsect);
      src_line();
      strcpy(trace_1, "c2z_eoj.c c2_eoj char array #3");
      trace_rec_3();
      
      strcpy(a_string, "         DS    0H");
      src_line();
      strcpy(trace_1, "c2z_eoj.c c2_eoj char array #4");
      trace_rec_3();
      
      strcpy(a_string, "*");
      src_line();
      strcpy(trace_1, "c2z_eoj.c c2_eoj char array #5");
      trace_rec_3();
    }
  }

  for (I = 0; I < gv_ct; I++) 
  {
    convert = 0;
    ret = strcmp(gw_variable[I].gv_type, "G");
    if ((ret == 0) && (convert == 0)) 
    {
      strcpy(a_string, gw_variable[I].gv_dsect);
      check_length();
      strcat(a_string, "DSECT");
      strcpy(wk_remark, " ");
      strcpy(wk_remark, gw_variable[I].gv_table);
      strcpy(wk_remark, " */");
      write_remark();
      strcpy(trace_1, "c2z_eoj.c c2_eoj int array #1");
      trace_rec_3();
      
      strcpy(a_string, gw_variable[I].gv_aname);
      check_length();
      strcat(a_string, "DS    PL6'0'");
      src_line();
      strcpy(trace_1, "c2z_eoj.c c2_eoj int array #2");
      trace_rec_3();
      
      strcpy(a_string, gw_variable[I].gv_label);
      check_length();
      strcat(a_string, "EQU   *-");
      strcat(a_string, gw_variable[I].gv_dsect);
      src_line();
      strcpy(trace_1, "c2z_eoj.c c2_eoj int array #3");
      trace_rec_3();
      
      if (gw_variable[I].gv_column % 2 == 0) 
      {
      } else 
      {
        strcpy(a_string, "         DS    0H");
        src_line();
        strcpy(trace_1, "c2z_eoj.c c2_eoj int array #4");
        trace_rec_3();
      }

      strcpy(a_string, "*");
      src_line();
      strcpy(trace_1, "c2z_eoj.c c2_eoj int array #5");
      trace_rec_3();
    }
  }

  x = 0;
  for (I = 0; I < m_struc_ct; I++) 
  {
    convert = 0;
    ret = strcmp(w_struc[I].st_id, "M");
    if ((ret == 0) && (convert == 0)) 
    {
      if (x != 0) {
        strcpy(tfield3, tfield2);
        strcat(tfield3, "L");
        strcpy(a_string, tfield3);
        check_length();
        strcat(a_string, "EQU   *-");
        strcat(a_string, tfield2);
        src_line();
        strcpy(trace_1, "c2z_eoj c2_eoj structure #1");
        trace_rec_3();
        
        strcpy(a_string, "*");
        src_line();
        strcpy(trace_1, "c2z_eoj c2_eoj structure #2");
        trace_rec_3();
      }

      x++;
      strcpy(a_string, w_struc[I].st_cwname);
      strcpy(tfield2, w_struc[I].st_cwname);
      check_length();
      strcat(a_string, "DSECT");
      src_line();
      strcpy(trace_1, "c2z_eoj c2_eoj structure #3");
      trace_rec_3();
    }

    ret = strcmp(w_struc[I].st_id, "N");
    if (ret == 0) 
    {
      ret1 = strcmp(w_struc[I].st_type, "I");
      if (ret1 == 0) 
      {
        stru_ct++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", stru_ct);
        strcpy(c_wkname, "ST");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(tfield6, c_wkname);

        strcpy(a_string, tfield6);
        check_length();
        strcat(a_string, "DS    PL6'0'");
        src_line();
        strcpy(trace_1, "c2z_eoj c2_eoj structure #4");
        trace_rec_3();
      }

      ret1 = strcmp(w_struc[I].st_type, "C");
      if (ret1 == 0) 
      {
        stru_ct++;
        snprintf(wk_strg, sizeof(wk_strg), "%d", stru_ct);
        strcpy(c_wkname, "ST");
        strcat(c_wkname, wk_strg);
        s = strlen(c_wkname);
        c_wkname[s] = '\0';
        strcpy(tfield6, c_wkname);

        strcpy(a_string, tfield6);
        check_length();
        strcat(a_string, "DS    CL");
        snprintf(wk_strg, sizeof(wk_strg), "%d", w_struc[I].st_field_lgth);
        strcat(a_string, wk_strg);
        strcat(a_string, "' '");
        src_line();
        strcpy(trace_1, "c2z_eoj.c c2_eoj structure #5");
        trace_rec_3();
      }
    }
  }

  if (x > 0) 
  {
    strcpy(tfield3, tfield2);
    strcat(tfield3, "L");
    strcpy(a_string, tfield3);
    check_length();
    strcat(a_string, "EQU   *-");
    strcat(a_string, tfield2);
    src_line();
    strcpy(trace_1, "c2z_eoj.c c2_eoj structure #6");
    trace_rec_3();
    
    strcpy(a_string, "*");
    src_line();
    strcpy(trace_1, "c2z_eoj.c c2_eoj structure #7");
    trace_rec_3();
  }

    strcpy(a_string, "         TN3270 SYMBOLS DEFINE TN3290 CONTROL AND ATTRIBUTE CODES");
    src_line();
    strcpy(trace_1, "c2z_eoj c2_eoj TN3270");
    trace_rec_3();
    
    strcpy(a_string, "         GUAM   SYMBOLS DEFINE GUI MCS, SCREEN, AND GRAPH CODES");
    src_line();
    strcpy(trace_1, "c2z_eoj c2_eoj GUAM");
    trace_rec_3();
   
  /* *************************************************
  *  Punch out ASM end statement                     *
  * ************************************************ */
  strcpy(a_string, "         END");
  src_line();
  strcpy(trace_1, "c2z_eoj c2_eoj End of Parser");
  trace_rec_3();
  
  /* ************************************************
  *  Close all files used by the parser.            *
  * *********************************************** */
  fclose(pgm);
  fclose(cc370);

  x4 = 0;
  strcpy(a_string, "*  c2z Complete - C Lines of code - ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  s = strlen(a_string);
  if (s < 46) 
  {
    for (v = s; v < 46; v++) 
    {
      strcat(a_string, " ");
    }
  }
  strcat(a_string, "*");
  printf("%s\n", a_string);

  strcpy(a_string, "*               MLC Lines of code - ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", var_use[1]);
  strcat(a_string, wk_strg);
  s = strlen(a_string);
  if (s < 46) 
  {
    for (v = s; v < 46; v++) 
    {
      strcat(a_string, " ");
    }
  }
  strcat(a_string, "*");
  printf("%s\n", a_string);

  strcpy(a_string, "*               Global Variables  - ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", gv_ct);
  strcat(a_string, wk_strg);
  s = strlen(a_string);
  if (s < 46) 
  {
    for (v = s; v < 46; v++) 
    {
      strcat(a_string, " ");
    }
  }
  strcat(a_string, "*");
  printf("%s\n", a_string);

  strcpy(a_string, "*               Local Variables   - ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", lv_ct);
  strcat(a_string, wk_strg);
  s = strlen(a_string);
  if (s < 46) 
  {
    for (v = s; v < 46; v++) 
    {
      strcat(a_string, " ");
    }
  }
  strcat(a_string, "*");
  printf("%s\n", a_string);

  strcpy(a_string, "*               Character Literal - ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", lit_ct);
  strcat(a_string, wk_strg);
  s = strlen(a_string);
  if (s < 46) 
  {
    for (v = s; v < 46; v++) 
    {
      strcat(a_string, " ");
    }
  }
  strcat(a_string, "*");
  printf("%s\n", a_string);

  printf("*\t\t\t\t\t      *\n");
  printf("*\t  C\t\t c2z\t\t      *\n");
  printf("*\tFiles\t\tFiles\t\t      *\n");
  for (I = 0; I < f_ct; I++) 
  {
    printf("*\t%s \t\t%s\t\t      *\n", w_file[I].f_name, w_file[I].f_cname);
  }

  printf("***********************************************\n");

  /* ********************************************************
  *  if debug is turned on print out the various structs.   *
  *  debug == 1  (on)                                       *
  *  debug == 0  (off)                                      *
  * ******************************************************* */

  c2_debug();
 
}
