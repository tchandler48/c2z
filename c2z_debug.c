/* ***************************************************
*  c2Z  : c2z_debug.c :                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

void c2_debug()
{
     if(trace_flag == 1)
     {
        strcpy(trace_1, "c2_debug");
	 trace_rec_1();
     }

     char p_strg[6];

      int I = 0;
      int s = 0;
      int v = 0;
      int tot = 0;
      int ret = 0;
		
      fprintf(c_src, "\n\n\n------ Global Variables Not Used -------\n");
      for(I=0; I < gv_ct; I++)
      {
         if(gw_variable[I].gv_use_ct == 0)
	  {
	     strcpy(a_string, "Rec - ");
	     snprintf(wk_strg, sizeof(wk_strg), "%d",gw_variable[I].gv_rct);

	     strcat(a_string, wk_strg);
	     s = strlen(a_string);
				
	     if(s < 12)
	     {
	        for(v = s; v < 12; v++)
		 {
		    strcat(a_string, " ");
		 }
	     }
	     strcat(a_string, "Name - ");
	     strcat(a_string, gw_variable[I].gv_name);
			
	     s = strlen(a_string);
	     for(v = s; v < 38; v++)
	     {
	        strcat(a_string, " ");
	     }
	     strcat(a_string, "CName - ");
	     strcat(a_string, gw_variable[I].gv_cname);
	     s = strlen(a_string);
	     for(v = s; v < 55; v++)
	     {
	        strcat(a_string, " ");
	     }
	     strcat(a_string, "Type - ");
	     strcat(a_string, gw_variable[I].gv_type);
            strcat(a_string, "\n");
	     fputs(a_string, c_src);
	     tot++;
	  }
      }
      fprintf(c_src, "\nTotal Non_used variables = %d\n",tot);

      fprintf(c_src, "\n---------- C Function Useage-----\n\n");
      if(var_use[13] != 0)
         fprintf(c_src, "atoi      - %d\n", var_use[13]);
      if(tot_case != 0)
         fprintf(c_src, "case      - %d\n", tot_case);
      if(tot_char != 0)
         fprintf(c_src, "char      - %d\n", tot_char);
      if(tot_localtime != 0)
         fprintf(c_src, "ctime     - %d\n", tot_localtime);
      if(var_use[17] != 0)
			fprintf(c_src, "define    - %d\n", var_use[17]);
		if(tot_double != 0)
			fprintf(c_src, "double    - %d\n", tot_double);
		if(var_use[6] != 0)
			fprintf(c_src, "fclose    - %d\n", var_use[6]);
		if(var_use[18] != 0)
			fprintf(c_src, "fgets     - %d\n", var_use[18]);
		if(var_use[5] != 0)
			fprintf(c_src, "fopen     - %d\n", var_use[5]);
		if(tot_for != 0)
			fprintf(c_src, "for       - %d\n", tot_for);
		if(var_use[2] != 0)
			fprintf(c_src, "fprintf   - %d\n", var_use[2]);
		if(var_use[14] != 0)
			fprintf(c_src, "free      - %d\n", var_use[14]);
		if(tot_goto != 0)
			fprintf(c_src, "goto      - %d\n", tot_goto);
		if(var_use[7] != 0)
			fprintf(c_src, "if        - %d\n", var_use[7]);
		if(tot_int != 0)
			fprintf(c_src, "int       - %d\n", tot_int);
		if(var_use[9] != 0)
			fprintf(c_src, "isalpha   - %d\n", var_use[9]);
		if(var_use[10] != 0)
			fprintf(c_src, "isdigit   - %d\n", var_use[10]);
		if(var_use[11] != 0)
			fprintf(c_src,"isspace   - %d\n", var_use[11]);
		if(tot_memcpy != 0)
			fprintf(c_src, "memcpy    - %d\n", tot_memcpy);
		if(tot_memmove != 0)
			fprintf(c_src, "memmove   - %d\n", tot_memmove);
		if(var_use[1] != 0)
			fprintf(c_src, "printf    - %d\n", var_use[1]);
		if(tot_sizeof != 0)
			fprintf(c_src, "sizeof    - %d\n", tot_sizeof);
		if(var_use[15] != 0)
			fprintf(c_src, "strcat    - %d\n", var_use[15]);
		if(tot_strchr != 0)
			fprintf(c_src, "strchr    - %d\n", tot_strchr);
		if(tot_strcmp != 0)
			fprintf(c_src, "strcmp    - %d\n", tot_strcmp);
		if(var_use[9] != 0)
			fprintf(c_src, "strcpy    - %d\n", var_use[9]);
		if(var_use[16] != 0)
			fprintf(c_src, "strlen    - %d\n", var_use[16]);
		if(tot_strncpy != 0)
			fprintf(c_src, "strncpy   - %d\n", tot_strncpy);
		if(tot_switch != 0)
			fprintf(c_src, "switch    - %d\n", tot_switch);
		if(tot_time != 0)
			fprintf(c_src, "time      - %d\n", tot_time);
		if(tot_while != 0)
			fprintf(c_src, "while     - %d\n", tot_while);
		fprintf(c_src, "\n");


		fprintf(c_src, "\n---------- Define -------------------\n");
		for(I=0; I < fld_ct; I++)
			{
				fprintf(c_src, "\nRec - %d", w_define[I].d_rct);
				fprintf(c_src, "    Field Name  - %s", w_define[I].d_name);
				fprintf(c_src, "    Field Value - %s", w_define[I].d_value);						
			}

						
		fprintf(c_src, "\n\n---------- fopen --------------------\n");
		for(I=0; I < f_ct; I++)
			{
				fprintf(c_src, "\nRec  - %d", w_file[I].f_rct);
				fprintf(c_src, "   F Name - %s", w_file[I].f_name);
				fprintf(c_src, "   C Name - %s", w_file[I].f_cname);
				fprintf(c_src, "   Type   - %s", w_file[I].f_type);
				fprintf(c_src, "   Buf Ct - %d", w_file[I].f_buf_ct);
				fprintf(c_src, "   Perm   - %s\n", w_file[I].f_perm);
			}


		fprintf(c_src, "\n\n---------- fclose -------------------\n");
		for(I = 0; I < fclose_ct; I++)
			{
				fprintf(c_src, "\ncl_rct = %d", w_fclose_table[I].cl_rct);
				fprintf(c_src, "    cl_buf_ct = %d", w_fclose_table[I].cl_buf_ct);
			}

	

		fprintf(c_src, "\n\n---------- functions ----------------\n\n");
		fprintf(c_src,"Rct   Function       CName          Start  Sv_reg    Sv_Var    fd1         fd2          fd3\n");
              fprintf(c_src,"----  -------------  -------------  -----  --------  --------  ----------  -----------  ------------\n");
		for(I=0; I < fn_ct; I++)
			{
				snprintf(wk_strg, sizeof(wk_strg), "%d",w_function[I].fn_rct);
				strcpy(a_string, wk_strg);
				s = strlen(a_string);
				if(s < 6)
					{
						for(v = s; v < 6; v++)
							{
								strcat(a_string, " ");
							}
					}
				strcat(a_string, w_function[I].fn_name);

				s = strlen(a_string);
				if(s < 21)
					{
						for(v = s; v < 21; v++)
							{
								strcat(a_string, " ");
							}
					}
				strcat(a_string, w_function[I].fn_cname);
				
				s = strlen(a_string);
				if(s < 36)
					{
						for(v = s; v < 36; v++)
							{
								strcat(a_string, " ");
							}
					}
				snprintf(wk_strg, sizeof(wk_strg), "%d",w_function[I].fn_start);
				strcat(a_string, wk_strg);

				s = strlen(a_string);
				if(s < 43)
					{
						for(v = s; v < 43; v++)
							{
								strcat(a_string, " ");
							}
					}
				strcat(a_string, w_function[I].fn_sv_reg_1);
	
				s = strlen(a_string);
				if(s < 53)
					{
						for(v = s; v < 53; v++)
							{
								strcat(a_string, " ");
							}
					}
				strcat(a_string, w_function[I].fn_ret_var);

				s = strlen(a_string);
				if(s < 63)
					{
						for(v = s; v < 63; v++)
							{
								strcat(a_string, " ");
							}
					}
				strcat(a_string, w_function[I].fn_fd1);

				s = strlen(a_string);
				if(s < 75)
					{
						for(v = s; v < 75; v++)
							{
								strcat(a_string, " ");
							}
					}
				strcat(a_string, w_function[I].fn_fd2);

				s = strlen(a_string);
				if(s < 85)
					{
						for(v = s; v < 85; v++)
							{
								strcat(a_string, " ");
							}
					}
				strcat(a_string, w_function[I].fn_fd3);

				strcat(a_string, "\n");
				fputs(a_string, c_src);
			}


		fprintf(c_src, "\n\n---------- constant -----------------\n");
		for(I=0; I < v_const; I++)
			{
				fprintf(c_src, "\nRec - %d", w_constant[I].const_rct);
				fprintf(c_src, "   Current  - %s", w_constant[I].const_current);
				fprintf(c_src, "   Use      - %s", w_constant[I].const_use);
			}


		fprintf(c_src, "\n\n------------------------------ Global Variables -------------------------------\n");
		fprintf(c_src, "Rec     Name                   CName         Type  Lgth   Dec    ID   Value   Literal\n");
		fprintf(c_src, "-----  ----------------------  ------------  ----  ----  ----    --   ------  -------------\n");

		for(I=0; I < gv_ct; I++)
			{
				snprintf(wk_strg, sizeof(wk_strg), "%d",gw_variable[I].gv_rct);
				strcpy(a_string, wk_strg);
				s = strlen(a_string);
				if(s < 7)
					{
						for(v = s; v < 7; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, gw_variable[I].gv_name);
				s = strlen(a_string);
				if(s < 31)
					{
						for(v = s; v < 31; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, gw_variable[I].gv_cname);
				s = strlen(a_string);
				if(s < 47)
					{
						for(v = s; v < 47; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, gw_variable[I].gv_type);
				s = strlen(a_string);
				if(s < 53)
					{
						for(v = s; v < 53; v++)
							{
								strcat(a_string, " ");
							}
					}
				snprintf(p_strg, sizeof(p_strg), "%d",gw_variable[I].gv_lgth);
				strcat(a_string, p_strg);

				s = strlen(a_string);
				if(s < 59)
					{
						for(v = s; v < 59; v++)
							{
								strcat(a_string, " ");
							}
					}
				snprintf(p_strg, sizeof(p_strg), "%d",gw_variable[I].gv_dec);
				strcat(a_string, p_strg);

				s = strlen(a_string);
				if(s < 66)
					{
						for(v = s; v < 66; v++)
							{
								strcat(a_string, " ");
							}
					}
				snprintf(p_strg, sizeof(p_strg), "%d",gw_variable[I].gv_id);
				strcat(a_string, p_strg);
	
				s = strlen(a_string);
				if(s < 71)
					{
						for(v = s; v < 71; v++)
							{
								strcat(a_string, " ");
							}
					}
				strcat(a_string, gw_variable[I].gv_value);
		
				s = strlen(a_string);
				if(s < 81)
					{
						for(v = s; v < 81; v++)
							{
								strcat(a_string, " ");
							}
					}
	
				strcat(a_string, gw_variable[I].gv_literal);
	
				strcat(a_string, "\n");
				fputs(a_string, c_src);
			}
		fprintf(c_src, "\nTotal Global Variables = %d\n", I);


		fprintf(c_src, "\n\n------------------------------------ Local Variables ------------------------------------------\n");
		fprintf(c_src, "Rec     Name                   CName          Function         Type  Lgth   Dec    ID      Value/Literal\n");
		fprintf(c_src, "-----  ----------------------  -------------  ---------------  ----  ----  -----   ---     -------------\n");

		for(I=0; I < lv_ct; I++)
			{
				snprintf(wk_strg, sizeof(wk_strg), "%d",lw_variable[I].lv_rct);
				strcpy(a_string, wk_strg);
				s = strlen(a_string);
				if(s < 7)
					{
						for(v = s; v < 7; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, lw_variable[I].lv_name);
				s = strlen(a_string);
				if(s < 31)
					{
						for(v = s; v < 31; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, lw_variable[I].lv_cname);
				s = strlen(a_string);
				if(s < 47)
					{
						for(v = s; v < 47; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, lw_variable[I].lv_func);
				s = strlen(a_string);
				if(s < 65)
					{
						for(v = s; v < 65; v++)
							{
								strcat(a_string, " ");
							}
					}
				strcat(a_string, lw_variable[I].lv_type);

				s = strlen(a_string);
				if(s < 70)
					{
						for(v = s; v < 70; v++)
							{
								strcat(a_string, " ");
							}
					}
				snprintf(p_strg, sizeof(p_strg), "%d",lw_variable[I].lv_lgth);
				strcat(a_string, p_strg);

				s = strlen(a_string);
				if(s < 76)
					{
						for(v = s; v < 77; v++)
							{
								strcat(a_string, " ");
							}
					}
				snprintf(p_strg, sizeof(p_strg), "%d",lw_variable[I].lv_dec);
				strcat(a_string, p_strg);

				s = strlen(a_string);
				if(s < 84)
					{
						for(v = s; v < 84; v++)
							{
								strcat(a_string, " ");
							}
					}
				snprintf(p_strg, sizeof(p_strg), "%d",lw_variable[I].lv_id);
				strcat(a_string, p_strg);

				s = strlen(a_string);
				if(s < 90)
					{
						for(v = s; v < 90; v++)
							{
								strcat(a_string, " ");
							}
					}

				ret = strcmp(lw_variable[I].lv_type, "I");
				if(ret == 0)
					{
						strcat(a_string, lw_variable[I].lv_literal);
					}
				
				ret = strcmp(lw_variable[I].lv_type, "L");
				if(ret == 0)
					{
						strcat(a_string, lw_variable[I].lv_value);
					}
				strcat(a_string, "\n");
				fputs(a_string, c_src);
			}
		fprintf(c_src, "\nTotal Local Variables = %d\n", I);


		fprintf(c_src, "\n\n---------- includes -----------------\n");
		for(I=0; I < i_ct; I++)
			{
				fprintf(c_src, "\nRec  - %d", w_include[I].include_rct);
				fprintf(c_src, "   Pgm    - %s", w_include[I].include_name);
			}


		fprintf(c_src, "\n\n---------- if table -----------------\n");
		for(I=0; I < wif_ct; I++)
			{
				fprintf(c_src, "IF rct - %d",w_if_table[I].wif_rct);
				fprintf(c_src, " Level - %d",w_if_table[I].wif_level);
				fprintf(c_src, " EOF1 - %d",w_if_table[I].wif_eof1);
				fprintf(c_src, " ELSE - %d", w_if_table[I].wif_else);
				fprintf(c_src, " EOF2 - %d",w_if_table[I].wif_eof2);
				fprintf(c_src, " RCT - %s",w_if_table[I].wif_p_string);

			}


		fprintf(c_src, "\n\n---------- while table --------------\n");
		for(I=0; I < wh_ct; I++)
			{
				fprintf(c_src,"WHILE = %d", w_while_table[I].wh_rct);
				fprintf(c_src, " Level - %d", w_while_table[I].wh_level);
				fprintf(c_src, " EOF - %d", w_while_table[I].wh_eof1);
				fprintf(c_src, " RCT - %s", w_while_table[I].wh_p_string);
			}

							
		fprintf(c_src, "\n\n---------- Function Start -----------\n");
		for(I=0; I < fns_ct; I++)
			{
				fprintf(c_src,"\nRct = %d", w_func_start[I].fns_rct);
				fprintf(c_src, " Name - %s", w_func_start[I].fns_name);
			}

		fprintf(c_src, "\n\n------------------------  Math Literals  ----------------------\n");
		fprintf(c_src, "Rct    Use       Name       CName     Value     Dec  Uct   Type\n");

		for(I=0; I < lit_ct; I++)
			{
				snprintf(p_strg, sizeof(p_strg), "%d",w_literal[I].lit_rct );
				strcpy(a_string, p_strg);
				s = strlen(a_string);
				if(s < 8)
					{
						for(v = s; v < 8; v++)
							{
								strcat(a_string, " ");
							}
					}

				snprintf(p_strg, sizeof(p_strg), "%d",w_literal[I].lit_use_rct );
				strcat(a_string, p_strg);
				s = strlen(a_string);
				if(s < 16)
					{
						for(v = s; v < 16; v++)
							{
								strcat(a_string, " ");
							}
					}
				
				strcat(a_string, w_literal[I].lit_use_cname);
				s = strlen(a_string);
				if(s < 28)
					{
						for(v = s; v < 28; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, w_literal[I].lit_cname);
				s = strlen(a_string);
				if(s < 38)
					{
						for(v = s; v < 38; v++)
							{
								strcat(a_string, " ");
							}
					}
				
 				strcat(a_string, w_literal[I].lit_value);
				s = strlen(a_string);
				if(s < 49)
					{
						for(v = s; v < 49; v++)
							{
								strcat(a_string, " ");
							}
					}

				snprintf(p_strg, sizeof(p_strg), "%d",w_literal[I].lit_dec);
				strcat(a_string, p_strg);
				s = strlen(a_string);
				if(s < 54)
					{
						for(v = s; v < 54; v++)
							{
								strcat(a_string, " ");
							}
					}

				snprintf(p_strg, sizeof(p_strg), "%d",w_literal[I].lit_uct);
				strcat(a_string, p_strg);
				s = strlen(a_string);
				if(s < 60)
					{
						for(v = s; v < 60; v++)
							{
								strcat(a_string, " ");
							}
					}
				snprintf(p_strg, sizeof(p_strg), "%d",w_literal[I].lit_type);
				strcat(a_string, p_strg);

				strcat(a_string, "\n");
				fputs(a_string, c_src);

			}
		fprintf(c_src, "\n\n-----------  Character Literals  ---------\n");
		fprintf(c_src, "Rct     Cname       Value     Lgth     Type\n");

		for(I=0; I < char_ct; I++)
			{
				snprintf(p_strg, sizeof(p_strg), "%d",w_charlit[I].clit_rct );
				strcpy(a_string, p_strg);
				s = strlen(a_string);
				if(s < 8)
					{
						for(v = s; v < 8; v++)
							{
								strcat(a_string, " ");
							}
					}
				
				strcat(a_string, w_charlit[I].clit_cname);
				s = strlen(a_string);
				if(s < 20)
					{
						for(v = s; v < 20; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, w_charlit[I].clit_value);
				s = strlen(a_string);
				if(s < 32)
					{
						for(v = s; v < 32; v++)
							{
								strcat(a_string, " ");
							}
					}

				snprintf(p_strg, sizeof(p_strg), "%d",w_charlit[I].clit_lgth);
				strcat(a_string, p_strg);
				s = strlen(a_string);
				if(s < 40)
					{
						for(v = s; v < 40; v++)
							{
								strcat(a_string, " ");
							}
					}
				snprintf(p_strg, sizeof(p_strg), "%d",w_charlit[I].clit_type);
				strcat(a_string, p_strg);
				
				strcat(a_string, "\n");
				fputs(a_string, c_src);

			}
 

		fprintf(c_src, "\n");

		fprintf(c_src, "\n\n--------------- Structures ---------------\n");
		fprintf(c_src, "Rec    Name          CName              WName          WCName       Field Name         Field CName      Id  Type  Lgth  Disp\n");
		fprintf(c_src, "-----  ------------  -----------------  ------------  ------------  -----------------  --------------- ---- ----  ----  ----\n");

		for(I=0; I < m_struc_ct; I++)
			{
				
				snprintf(wk_strg, sizeof(wk_strg), "%d",w_struc[I].st_rct);
				strcpy(a_string, wk_strg);
				s = strlen(a_string);
				if(s < 7)
					{
						for(v = s; v < 7; v++)
							{
								strcat(a_string, " ");
							}
					}


				strcat(a_string, w_struc[I].st_name);
				s = strlen(a_string);   
				if(s < 21)
					{
						for(v = s; v < 21; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, w_struc[I].st_cname);
				
				s = strlen(a_string);
				if(s < 40)
					{
						for(v = s; v < 40; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, w_struc[I].st_wname);
				s = strlen(a_string);
				if(s < 54)
					{
						for(v = s; v < 54; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, w_struc[I].st_cwname);
				s = strlen(a_string);
				if(s < 68)
					{
						for(v = s; v < 68; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, w_struc[I].st_field_name);
				s = strlen(a_string);
				if(s < 87)
					{
						for(v = s; v < 87; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, w_struc[I].st_field_cname);
				s = strlen(a_string);
				if(s < 105)
					{
						for(v = s; v < 105; v++)
							{
								strcat(a_string, " ");
							}
					}
	
		
				strcat(a_string, w_struc[I].st_id);
				s = strlen(a_string);
				if(s < 110)
					{
						for(v = s; v < 110; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, w_struc[I].st_type);
				s = strlen(a_string);
				if(s < 115)
					{
						for(v = s; v < 115; v++)
							{
								strcat(a_string, " ");
							}
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d",w_struc[I].st_field_lgth);
				strcat(a_string, wk_strg);
				s = strlen(a_string);
				if(s < 120)
					{
						for(v = s; v < 120; v++)
							{
								strcat(a_string, " ");
							}
					}

				snprintf(wk_strg, sizeof(wk_strg), "%d",w_struc[I].st_disp);
				strcat(a_string, wk_strg);
				s = strlen(a_string);
				if(s < 125)
					{
						for(v = s; v < 125; v++)
							{
								strcat(a_string, " ");
							}
					}

				strcat(a_string, w_struc[I].st_field_value);
						
				strcat(a_string, "\n");
				fputs(a_string, c_src);
			}
		fprintf(c_src, "\n");

		fclose(c_src);
	}


void c2_print_files()
	{
		int I;

		for(I=0; I < f_ct; I++)
			{
				printf("\nRec  - %d", w_file[I].f_rct);
				printf(" F Name - %s", w_file[I].f_name);
				printf(" C Name - %s", w_file[I].f_cname);
				printf(" Type   - %s", w_file[I].f_type);
				printf(" Buf Ct - %d", w_file[I].f_buf_ct);
				printf(" Perm   - %s\n", w_file[I].f_perm);
			}


	}

