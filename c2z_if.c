/* ***************************************************
*  c2z : c2z_if.c :                                  *
*                                                    *
*  next error if-191                                 *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */

/* ***************************************************
*  Punch out IF statement                            *
* ************************************************** */

void c2_if(void) 
{
  char ch;
  char *p, *p7, *p8, *p9;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];

  tfield1a[0] = '\0';

  int pi;
  int pi2;
  if_convert = 0;
  int I = 0;
  int s;
  int ret = 0;
  int bracket_ct = 0;
  int if_complex = 0;
  int x90 = 0;
  int x91 = 0;
  int x92 = 0;
  int x95 = 0;
  int x96 = 0;
  int x97 = 0;
  int x98 = 0;
  int x99 = 0;

  if_opr = 0;
  convert = 0;
  if_complex = 0;

  if ((if_opr == 0) && (convert == 0)) 
  {
    p7 = strstr(p_string, "isdigit");
    if (p7) 
    {
      if_opr = 7;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p8 = strstr(p_string, "isalpha");
    if (p8) 
    {
      if_opr = 8;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p8 = strstr(p_string, "eof");
    if (p8) 
    {
      if_opr = 9;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p8 = strstr(p_string, "strcmp");
    if (p8) 
    {
      if_opr = 10;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p7 = strstr(p_string, "isupper");
    if (p7) 
    {
      if_opr = 22;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p7 = strstr(p_string, "isalnum");
    if (p7) 
    {
      if_opr = 23;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p7 = strstr(p_string, "strchr");
    if (p7) 
    {
      if_opr = 30;
    }
  }

  if ((if_opr == 0) && (convert == 0)) 
  {
    p7 = strstr(p_string, "IsAddop");
    if (p7) 
    {
      if_opr = 12;
    }
  }

  p9 = strstr(p_string, "&&");
  if (p9) 
  {
    if_complex = 1;
  }

  p9 = strstr(p_string, "||");
  if (p9) 
  {
    if_complex = 1;
  }

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];

    if (ch == '\'')
    {
      I++;
      ch = p_string[I];
      while(ch != '\'')
      {
        I++;
        ch = p_string[I];
      }
      I++;
      ch = p_string[I];
    }

    if (ch == '(') 
    {
      x98++;
    }

    if (ch == ')') 
    {
      x98++;
    }

    if (ch == '[') 
    {
      bracket_ct++;
      x91 = I;
    }

    if (ch == ']')
    {
      bracket_ct++;
    }

    if (ch == '.')
    {
      x95++;
    }

    if (ch == '=')
    {
      x92 = I;
      x96++;
    }
    if(ch == '<')
    {
      x96++;
    }
    if(ch == '>')
    {
      x96++;
    }
    if(ch == '!')
    {
      x96++;
    }
    if(ch == ',')
    {
      x90++;
    }
  }

/*
printf("c2z_if.c rct = %d p_string = %s",rct,p_string);
printf("c2z_if.c x98 = %d bracket_ct = %d if_opr = %d if_complex = %d x95 = %d x96 = %d x91 = %d x92 = %d x90 = %d\n",x98,bracket_ct,if_opr,if_complex,x95,x96,x91,x92,x90);  
*/

/*	if_case_1		if(aa op bb)				 */
/*     if_case_2		if(temp_byte[ii] != 0)		 */
/*     if_case_7            isdigit        			 */
/*     if_case_8            isalpha             			 */
/*     if_case_9            eof                 			 */
/*     if_case_10           strcmp              			 */
/*     if_case_11           if(in_stack[ndx][0] == '\0')	 */
/*     if_case_12           if(IsAddop(ch))			 */
/*     if_case_13           if((ch == '+') || (ch == '-'))	 */
/*     if_case_22           isupper				 */
/*     if_case_23           isalnum				 */
/*     if_case_30           strchr      				 */
/*     if_case_40           if((temp_byte[ndx] == 13 || (temp_byte[ndx] == 14)) */
/*     if_case_41		if((pi < len) && (temp_byte[ii] != 0))  */
/*     if_case_42           if(ch == alpha[1])                  */
/*     if_case_43           if(cellnum[0] == sheet[z2][z1][0])  */



  if ((x98 == 2) && (if_complex == 0) && (if_opr == 0) && (bracket_ct == 0))		/*  if(aa op bb)	*/   
  {
    if_case_1();
    if_convert = 1;
    convert = 1;
    return;
  }
                                                                      		
  if ((x98 == 2) && (bracket_ct == 2) && (x95 == 0) && (x96 ==  2) && (x91 < x92)) 			
  {
    if_case_2();
    if_convert = 1;
    convert = 1;
    return;
  }

  if ((if_opr == 7) && (x98 != 10) && (if_convert == 0))				/*  isdigit		*/ 
  {
    if_case_7();
    if_convert = 1;
    convert = 1;
    return;
  }

  if ((if_opr == 8) && (if_convert == 0))							/*  isalpha		*/ 
  {
    if_case_8();
    if_convert = 1;
    convert = 1;
    return;
  }

  if ((if_opr == 9) && (if_convert == 0))							/*  eof		*/ 
  {
    if_case_9();
    if_convert = 1;
    convert = 1;
    return;
  }

  if ((if_opr == 10) && (if_convert == 0)) 						/*  strcmp		*/
  {
    if_case_10();
    if_convert = 1;
    convert = 1;
    return;
  }

  if ((x98 == 2) && (bracket_ct == 4) && (convert == 0))				/*   if(in_stack[ndx][0] == '\0')	*/ 
  {
    if_case_11();
    convert = 1;
    return;
  }

  if ((if_opr == 12) && (if_convert == 0)) 					/*   if(IsAddop(ch))		*/
  {
    if_case_12();
    if_convert = 1;
    convert = 1;
    return;
  }

  if ((x98 == 6) && (if_complex == 1) && (bracket_ct == 0) && (if_convert == 0)) 	/*  if((ch == '+') || (ch == '-')) */
  {
    if_case_13();
    if_convert = 1;
    convert = 1;
    return;
  }

  if ((if_opr == 22) && (if_convert == 0))						/*  isupper		*/ 
  {
    if_case_22();
    if_convert = 1;
    convert = 1;
    return;
  }

  if ((if_opr == 23) && (if_convert == 0))						/*  isalnum		*/ 
  {
    if_case_23();
    if_convert = 1;
    convert = 1;
    return;
  }

  if ((if_opr == 30) && (if_convert == 0))						/*  strchr		*/ 
  {
    if_case_30();
    if_convert = 1;
    convert = 1;
    return;
  }

  if ((x98 == 6) && (if_complex == 1) && (bracket_ct == 4) && (if_convert == 0)) 	/*  if((ch == '+') || (ch == '-')) */
  {
    if_case_40();
    if_convert = 1;
    convert = 1;
    return;
  }

  if ((x98 == 6) && (if_complex == 1) && (bracket_ct == 2) && (x91 > x92) && (if_convert == 0)) 	/*  if((pi < len) && (temp_byte[ii] != 0)) */
  {
    if_case_41();
    if_convert = 1;
    convert = 1;
    return;
  }

  if((bracket_ct == 2) && (x92 < x91))
  {
    if_case_42();
    convert = 1;
    return;
  }

  if((bracket_ct == 8) && (convert == 0))
  {
    if_case_43();
    convert = 1;
    return;
  }

  if((x98 == 6) && (bracket_ct == 2) && (x96 == 1) && (convert == 0))	/* if((temp_byte[uu] != 0) && (pi < len)) */
  {
    if_case_44();
    if_convert = 1;
    convert = 1;
    return;
  }

  if ((x98 == 6) && (if_complex == 1) && (bracket_ct == 2) && (x91 < x92) && (if_convert == 0)) 	/*  if((temp_byte[ii] != 0) && (pi < len)) */
  {
    if_case_45();
    if_convert = 1;
    convert = 1;
    return;
  }

  if((x98 == 10) && (if_complex == 1) && (if_convert == 0))		/* if((isdigit(ch)) || (isaddop(ch))) */
  {
printf("\nc2z_if.c if_case_46 HERE rct = %d p_string = %s\n",rct,p_string);
    if_convert = 1;
    erct++;
    convert = 1;
    return;
  }

  p = strstr(p_string, "+");
  if((x98 == 4) && (p) && (if_convert == 0))				/* if((left + count) > len) */
  {
    if_case_47();
    if_convert = 1;
    convert = 1;
    return;
  }

  if (if_convert == 0) 
  {
    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    for (I = 0; I < fn_ct; I++)
    {
      ret = strcmp(tfield1, w_function[I].fn_name);
      if (ret == 0) 
      {
        strcpy(tfield1a, w_function[I].fn_cname);
        if_opr = 12;
      }
    }
  }


printf("\nc2z_if.c ERROR GOTO HERE\n");
printf("c2z_if.c rct = %d p_string = %s",rct,p_string);

/*  above is new correct code */

  p = strstr(p_string, "&&");
  if (p)
  {
    x97 = 1;
  }

  p = strstr(p_string, "||");
  if (p)
  {
    x97 = 1;
  }

  if ((x98 == 2) && (x99 == 0) && (x97 == 0)) 
  {
    if_case_24();
    convert = 1;
  }

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
  }

  if ((if_opr == 3) && (if_convert == 0)) 
  {
    if_case_3();
    if_convert = 1;
  }

  if ((if_opr == 4) && (if_convert == 0) && (convert == 0))
  {
    if_case_4();
    if_convert = 1;
  }

  if ((if_opr == 10) && (if_convert == 0)) 
  {
    if_case_10();
    if_convert = 1;
  }
  convert = 1;
}


/* ***************************************************
*  if_case_1                                         *
* ************************************************** */
void if_case_1() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_1 START");
    trace_rec_1();
  }

  char *p, *p2, *p3, *p5, *p6, *p8;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field97[VAR_LGTH];
  char field99[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int if_comma = 0;
  int if_complex = 0;
  int if_blank = 0;
  int if_quote = 0;
  int if_convert = 0;
  int if_and = 0;
  int if_or = 0;
  int negfd = 0;

  int fd1_type = 0;
  int fd2_type = 0;
  int operand_1 = 0;

 /* int s = 0; */
  int x = 0;
  int x2 = 0;
  int x3 = 0;
  int x4 = 0;
  int x5 = 0;
  int x6 = 0;
  int x80 = 0;
  int x98;
  int x99;
  int eol_1 = 0;
  int ret = 0;
  int ret1 = 0;

  p = strstr(p_string, "&&");
  if (p) 
  {
    if_complex = 1;
    if_and = 1;
  }

  if_complex = 0;
  p = strstr(p_string, "||");
  if (p) 
  {
    if_complex = 1;
    if_or = 1;
  }

  p6 = strstr(p_string, "[");

  if ((if_complex == 0) && (p6)) 
  {
    printf("c2z_if.c if_case_1 if-001 if_complex = 0 & p6 NOT CODED\n");
    printf("c2Z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
  }

  if ((if_complex == 0) && (!p6)) 
  {
    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    p3 = strstr(p_string, "((");
    if (p3) 
    {
      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }
      convert = 1;
      return;
    }

    eol_1 = 0;
    pi2 = 0;
    x3 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      if(ch == ')')
      {
        eol_1++;
        break;
      }
      if ((ch == '_') && (x3 == 0)) 
      {
        x3 = 1;
      }

      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          fd1_type = 1;
          x2 = 1;
        }
        if (isalpha(ch)) 
        {
          fd1_type = 2;
          x2 = 1;
        }
      }
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    negfd = 0;
    if(eol_1 == 1)
    {
      p = strstr(field1, "!");
      if(p)
      {
        negfd = 1;
        strcpy(field97,field1);
        x98 = 0;
        x99 = 0;
        ch = field1[x98];
        while(ch != '\0')
        {
           if(ch != '!')
           {
             field99[x99] = ch;
             x99++;
           }
           x98++;
           ch = field1[x98];
         }
           field99[x99] = '\0';
           strcpy(field1,field99);
      }
    }

    x3 = 0;
    x4 = 0;
    x5 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        x5 = strcmp("I", lw_variable[I].lv_type);
        if (x5 == 0)
        {
          x4 = 1;
        }
        x5 = strcmp("C", lw_variable[I].lv_type);
        if (x5 == 0)
        {
          x4 = 2;
        }
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
          x5 = strcmp("I", gw_variable[I].gv_type);
          if (x5 == 0)
          {
            x4 = 1;
          }
          x5 = strcmp("C", gw_variable[I].gv_type);
          if (x5 == 0)
          {
            x4 = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_1 if-002 field1 Not Found = %s\n", field1);
      printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if(eol_1 == 1)
    {
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcpy(o_string, a_string);
       
      if(negfd == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #500");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ZERO");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #501");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #502");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string,o_string);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #503");
          trace_rec_3();
        }
        return;
      }

      if(negfd == 1)
      {
        strcpy(field1, field97);
     
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #504");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #505");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #506");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string,o_string);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #507");
          trace_rec_3();
        }

        convert = 1;
        return;
      }
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          fd2_type = 1;
          x2 = 1;
        }
        if (isalpha(ch)) 
        {
          fd2_type = 2;
          x2 = 1;
        }
      }
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    if_comma = 0;
    if_blank = 0;

    p5 = strstr(field2, " ");
    if (p5) 
    {
      if_blank = 1;
    }

    p5 = strstr(field2, ",");
    if (p5) 
    {
      if_comma = 1;
    }

    p5 = strstr(field2, ";");
    if (p5) 
    {
      if_comma = 2;
    }

    p5 = strchr(field2, '\'');
    if (p5) 
    {
      if_quote = 1;
      fd2_type = 1;
    }

    strcpy(field2a, field2);

    if ((if_comma == 0) && (if_blank == 0) && (fd2_type == 2) && (if_quote == 0)) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x = strcmp(lw_variable[I].lv_type, "I");
          if (x == 0) 
          {
            fd1_type = 2;
            x6 = 1;
            x80 = 1;
          } 
          else 
          {
            x6 = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field2, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            x = strcmp(gw_variable[I].gv_type, "I");
            if (x == 0) 
            {
              fd1_type = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_1 if-003 field2 Not Found = %s\n", field2);
        printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(field3, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }
 

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(o_string, a_string);

    if ((if_comma == 0) && (fd2_type == 2) && (if_convert == 0)) 
    {
      if (fd2_type == 1) 
      {
        strcat(a_string, "=P'");
        strcat(a_string, field2);
        strcat(a_string, "'");
      }

      if (fd2_type == 2) 
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #1");
          trace_rec_3();
        }

        p8 = strstr(field2, "NULL");
        if (p8) 
        {
          strcpy(a_string, "         LARL  R8,NULL");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c case_1 #2");
            trace_rec_3();
          }
        } 
        else 
        {
          strcpy(a_string, "         LARL  R8,");
          strcat(a_string, field2a);
          strcpy(wk_remark, " ");
          strcat(wk_remark, field2);
          strcat(wk_remark, " */");
          write_remark();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c case_1 #3");
            trace_rec_3();
          }
        }

        if ((x4 != 2) && (x6 != 2)) 
        {
          strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        }

        if ((x4 == 2) && (x6 == 2)) 
        {
          strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        }
      }

      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_1 #4");
        trace_rec_3();
      }

      if_convert = 1;
    }

    if ((if_comma == 0) && (fd2_type == 1) && (convert == 0)) 
    {
      if ((fd1_type == 2) && (fd2_type == 1) && (x4 == 2)) 
      {
          x3 = 0;
          x4 = 0;
          x5 = 0;
          for (I = 0; I < lv_ct; I++) 
          {
            ret = strcmp(field1, lw_variable[I].lv_name);
            ret1 = strcmp(sv_func, lw_variable[I].lv_func);
            if ((ret == 0) && (ret1 == 0)) 
            {
              x3 = 1;
              strcpy(field1a, lw_variable[I].lv_cname);
              lw_variable[I].lv_use_ct++;
              x5 = strcmp("I", lw_variable[I].lv_type);
              if (x5 == 0)
              {
                x4 = 1;
              }
              x5 = strcmp("C", lw_variable[I].lv_type);
             if (x5 == 0)
             {
               x4 = 2;
             }
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
               x5 = strcmp("I", gw_variable[I].gv_type);
               if (x5 == 0)
               {
                 x4 = 1;
               }
               x5 = strcmp("C", gw_variable[I].gv_type);
               if (x5 == 0)
               {
                 x4 = 2;
               }
             }
           }
         }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #5");
          trace_rec_3();
        }
      }

      if ((fd1_type == 2) && (fd2_type == 1) && (x4 == 1)) 
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #6");
          trace_rec_3();
        }
      }

      if ((fd1_type == 2) && (fd2_type == 1) && (x4 == 2)) 
      {
        if ((field2[1] == '\\') && (field2[2] == '0'))
        {
          strcpy(a_string, "         LARL  R8,C370EOF");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c case_1 #7");
            trace_rec_3();
          }
          goto skip_case1b;
        }

        for (I = 0; I < char_ct; I++) 
        {
          if (w_charlit[I].clit_rct == rct) 
          {
            strcpy(field2a, w_charlit[I].clit_cname);
            x3 = w_charlit[I].clit_lgth;
          }
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field2a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #7");
          trace_rec_3();
        }

   skip_case1b:

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #8");
          trace_rec_3();
        }

        if(operand_1 == 1)
        {
          strcpy(a_string, "         JLNE  ");
          strcat(a_string, o_string);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c case_1 #9");
            trace_rec_3();
          }
        }

        if(operand_1 == 2)
        {
          strcpy(a_string, "         JLE   ");
          strcat(a_string, o_string);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c case_1 #10");
            trace_rec_3();
          }
        }
      }

      if ((fd1_type == 2) && (fd2_type == 1) && (x4 == 1)) 
      {
        x80 = 1;

        strcpy(a_string, "         LAEY  R5,");
        strcat(a_string, field2);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #11");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #12");
          trace_rec_3();
        }

        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #13");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #14");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #15");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #16");
          trace_rec_3();
        }

        if(x80 == 0)
        {
          strcpy(a_string, "         CLC   0(1,R9),0(R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c case_1 #16");
            trace_rec_3();
          }
        }

        if(x80 == 1)
        {
          strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c case_1 #17");
            trace_rec_3();
          }
        }

        if(operand_1 == 1)
        {
          strcpy(a_string, "         JLNE  ");
          strcat(a_string, o_string);
          src_line();
          if(puncde == 1)
          {
            strcpy(trace_1, "c2z_if.c case_1 #18");
            trace_rec_3();
          }
        }

        if(operand_1 == 2)
        {
          strcpy(a_string, "         JLE   ");
          strcat(a_string, o_string);
          src_line();
          if(puncde == 1)
          {
            strcpy(trace_1, "c2z_if.c case_1 #19");
            trace_rec_3();
          }
        }


        if(operand_1 == 6)
        {
          strcpy(a_string, "         JLE   ");
          strcat(a_string, o_string);
          src_line();
          if(puncde == 1)
          {
            strcpy(trace_1, "c2z_if.c case_1 #20");
            trace_rec_3();
          }

          strcpy(a_string, "         JLH   ");
          strcat(a_string, o_string);
          src_line();
          if(puncde == 1)
          {
            strcpy(trace_1, "c2z_if.c case_1 #21");
            trace_rec_3();
          }
        }

        if(operand_1 == 7)
        {
          strcpy(a_string, "         JLE   ");
          strcat(a_string, o_string);
          src_line();
          if(puncde == 1)
          {
            strcpy(trace_1, "c2z_if.c case_1 #22");
            trace_rec_3();
          }

          strcpy(a_string, "         JLL   ");
          strcat(a_string, o_string);
          src_line();
          if(puncde == 1)
          {
            strcpy(trace_1, "c2z_if.c case_1 #23");
            trace_rec_3();
          }
        }
        
        if_convert = 1;
      }

      convert = 1;
      return;
    }

    if ((if_comma == 0) && (fd2_type == 1) && (if_quote == 0) && (if_convert == 0)) 
    {
      strcpy(a_string, "         CP    ");
      if (fd1_type == 2) 
      {
        strcat(a_string, field1a);
      }

      strcat(a_string, ",");
      if (fd2_type == 2) 
      {
        p8 = strstr(field2, "null");
        if (p8) 
        {
          strcat(a_string, "=P'-1'");
        } 
        else 
        {
          strcat(a_string, field2a);
        }
      }

      if (fd2_type == 1) 
      {
        strcat(a_string, "=P'");
        strcat(a_string, field2);
        strcat(a_string, "'");
      }

      src_line();
      if (puncde == 1)
      {
        strcpy(trace_1, "c2z_if.c case_1 #21");
        trace_rec_3();
      }

      if_convert = 1;
    }

    /*
    printf("\nc2z_if.c if_case_1_simple rct = %d p_string = %s",rct,p_string);
    printf("c2z_if.c if_case_1_simple field1 = %s\n",field1);
    printf("c2z_if.c if_case_1_simple field1a = %s\n",field1a);
    printf("c2z_if.c if_case_1_simple field2 = %s\n",field2);
    printf("c2z_if.c if_case_1_simple field2a = %s\n",field2a);
    printf("c2z_if.c if_case_1_simple if_comma = %d\n",if_comma);
    printf("c2z_if.c if_case_1_simple if_blank = %d\n",if_blank);
    printf("c2z_if.c if_case_1_simple fd1_type = %d\n",fd1_type);
    printf("c2z_if.c if_case_1_simple fd2_type = %d\n",fd2_type);
    printf("c2z_if.c if_case_1_simple if_convert = %d\n",if_convert);
    */

    if ((if_comma == 1) || (if_comma == 2)) 
    {
      if ((fd2_type == 1) && (if_convert == 0)) 
      {
        
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */*");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #22");
          trace_rec_3();
        }

        for (I = 0; I < char_ct; I++) 
        {
          if (w_charlit[I].clit_rct == rct) 
          {
            strcpy(field2a, w_charlit[I].clit_cname);
            x3 = w_charlit[I].clit_lgth;
          }
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field2a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #23");
          trace_rec_3();
        }

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_1 #24");
          trace_rec_3();
        }
        if_convert = 1;
      }
    }

    if ((if_comma == 1) && (if_blank == 0) && (if_convert == 0)) 
    {
      strcpy(a_string, "         CLC   ");
      strcat(a_string, "=C");
      strcat(a_string, field2);
      strcat(a_string, ",");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_1 #25");
        trace_rec_3();
      }

      if_convert = 1;
    }

    if (operand_1 == 1) 			/* ==	*/
    {
      strcpy(a_string, "         JLNE  ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_1 #26");
        trace_rec_3();
      }
    }

    if (operand_1 == 2) 			/* !=	*/
    {
      strcpy(a_string, "         JLE   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_1 #27");
        trace_rec_3();
      }
    }

    if (operand_1 == 3) 			/* <=	*/
    {
      strcpy(a_string, "         JLH   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_1 #28");
        trace_rec_3();
      }
    }

    if (operand_1 == 4) 			/* >=	*/
    {
      strcpy(a_string, "         JLL   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_1 #29");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_1 #30");
        trace_rec_3();
      }
    }

    if (operand_1 == 5) 			/* =	*/
    {
      printf("\nc2z_if.c if_case_1 if-004 operand_1 = Error#5\n");
      printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 6) 			/* <	*/
    {
      strcpy(a_string, "         JLE   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_1 #30");
        trace_rec_3();
      }

      strcpy(a_string, "         JLH   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_1 #31");
        trace_rec_3();
      }
    }

    if (operand_1 == 7) 			/* >	*/
    {
      strcpy(a_string, "         JLL   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_1 #32");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_1 #33");
        trace_rec_3();
      }
    }
  }

  if ((if_complex == 1) && (if_convert == 0)) 
  {
    int operand_1 = 0;
    int operand_2 = 0;

    int if_2 = 0;
    int if_3 = 0;
    int if_4 = 0;

    int if_fd1_type = 0;

    int if_literal_1 = 0;
    int if_literal_2 = 0;

    int v = 0;

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    if_2 = 0;
    while (ch != ' ') 
    {
      if (if_2 == 0) 
      {
        if (isdigit(ch)) 
        {
          if_fd1_type = 1;
          if_2 = 1;
        }

        if (isalpha(ch)) 
        {
          if_fd1_type = 2;
          if_2 = 1;
        }
      }
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ')') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    if_2 = 0;
    while (ch != ' ') 
    {
      field5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ')
   {
      field6[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field6[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ')') 
    {
      field7[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field7[pi2] = '\0';

    operand_1 = 0;

    if (operand_1 == 0) 
    {
      p = strstr(field2, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    operand_2 = 0;

    if (operand_2 == 0) 
    {
      p = strstr(field6, "==");
      if (p)
      {
        operand_2 = 1;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field6, "!=");
      if (p)
      {
        operand_2 = 2;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field6, "<=");
      if (p)
      {
        operand_2 = 3;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field6, ">=");
      if (p)
      {
        operand_2 = 4;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field6, "=");
      if (p)
      {
        operand_2 = 5;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field6, "<");
      if (p)
      {
        operand_2 = 6;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field6, ">");
      if (p)
      {
        operand_2 = 7;
      }
    }

    if_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        if_4 = strcmp(field1, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((if_4 == 0) && (ret1 == 0)) 
        {
          if_3 = 1;
          strcpy(field1a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
    }

    if (if_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          if_4 = strcmp(field1, gw_variable[v].gv_name);
          if (if_4 == 0) 
          {
            if_3 = 1;
            strcpy(field1a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
    }

    if (if_3 == 0) 
    {
      printf("\nc2z_if.c if_case_1 if-005 COMPLEX field1 Not Found = %s\n", field1);
      printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if_3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        if_4 = strcmp(field5, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((if_4 == 0) && (ret1 == 0)) 
        {
          if_3 = 1;
          strcpy(field5a, lw_variable[v].lv_cname);
          lw_variable[v].lv_use_ct++;
        }
      }
    }

    if (if_3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          if_4 = strcmp(field5, gw_variable[v].gv_name);
          if (if_4 == 0) 
          {
            if_3 = 1;
            strcpy(field5a, gw_variable[v].gv_cname);
            gw_variable[v].gv_use_ct++;
          }
        }
      }
    }

    if (if_3 == 0) 
    {
      printf("\nc2z_if.c if_case_1 if-006 COMPLEX field5 Not Found = %s\n", field5);
      printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    p2 = strchr(field3, '\'');
    if (p2) 
    {
      if_literal_1 = 1;
    } 
    else 
    {
      if_literal_1 = 2;
      printf("\nc2z_if.c if_case_1 if-007 complex field3 ERROR FIX\n");
      printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    p2 = strchr(field7, '\'');
    if (p2) 
    {
      if_literal_2 = 1;
    } 
    else 
    {
      if_literal_2 = 2;
      printf("\nc2z_if.c if_case_1 if-008 complex field7 ERROR FIX\n");
      printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (if_fd1_type == 1) 
    {
      printf("\nc2z_if.c if_case_1 if-009 complex if_fd1_type == 1 ERROR\n");
      printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (if_fd1_type == 2) 
    {
      strcpy(a_string, "         CLC   ");
      strcat(a_string, field1a);
      strcat(a_string, ",");

      if (if_literal_1 == 1) 
      {
        strcat(a_string, "=CL1");
        strcat(a_string, field3);
      }

      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_1 complex #1");
        trace_rec_3();
      }

      if (if_literal_1 == 2) 
      {
        printf("\nc2z_if.c c2_if_case_1 if-010 complex punch error on if_literal_1\n");
        printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if ((operand_1 == 1) && (if_or == 1)) 			/* ==	*/
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "B");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_1 complex #2");
          trace_rec_3();
        }

        strcpy(a_string, "         CLC   ");
        strcat(a_string, field5a);
        strcat(a_string, ",");
        if (if_literal_2 == 1) 
        {
          strcat(a_string, "=CL1");
          strcat(a_string, field7);
        }
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_1 complex #3");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "B");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_1 complex #4");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_1 complex #5");
          trace_rec_3();
        }

        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "B");
        check_length();
        strcat(a_string, "DS     0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_1 complex #6");
          trace_rec_3();
        }
      }

      if ((operand_1 == 1) && (if_and == 1)) 
      {
        printf("\nc2z_if.c if_case_1 if-011 complex operand_1 == 1 && if_and == 1 NOT CODED\n");
        printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 2) 				/* <=	*/
      {
        printf("\nc2z_if.c if_case_1 if-012 complex operand_1 <= Error#2\n");
        printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 3) 				/* <=	*/
      {
        printf("\nc2z_if.c if_case_1 if-013 complex operand_1 <= Error#3\n");
        printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 4) 				/* >=	*/
      {
        printf("\nc2z_if.c if_case_1 if-014 complex operand_1 <= Error#4\n");
        printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 5) 				/* =	*/
      {
        printf("\nc2z_if.c if_case_1 if-015 complex operand_1 <= Error#5\n");
        printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 6) 				/* <	*/
      {
        printf("\nc2z_if.c if_case_1 if-016 complex operand_1 <= Error#6\n");
        printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 7) 				/* >	*/
      {
        printf("\nc2z_if.c if_case_1 if-017 complex operand_1 <= Error#7\n");
        printf("c2z_if.c if_case_1 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }
  }

  convert = 1;
  return;
}

/* ***************************************************
*  if_case_2                                         *
* ************************************************** */
void if_case_2() 					/* if(temp_byte[ii] != 0)	 */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2");
    trace_rec_1();
  }

  int pi = 0;
  int x2 = 0;
  int pi2 = 0;
  int x3 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  /* int fd1_type = 0; */
  /* int fd2_type = 0; */
  int fd4_type = 0;
  int operand_1 = 0;
  
  char ch;
  char *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield4[VAR_LGTH]; 

  char ar_field5[32];
  char ar_field6[32];
  char ar_field7[32];
  char ar_field8[32];
  char ar_field9[32];
  char ar_field10[32];
  char ar_field11[32];

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != '[') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        /* fd1_type = 1; */
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
       /*  fd1_type = 2; */
        x2 = 1;
      }
    }
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ']') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        /* fd2_type = 1; */
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
      /*   fd2_type = 2; */
        x2 = 1;
      }
    }
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  fd4_type = 0;
  pi2 = 0;
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (x2 == 0) 
    {
      if (isalpha(ch)) 
      {
        fd4_type = 1; 
        x2 = 1;
      }

      if (isdigit(ch)) 
      {
        fd4_type = 2; 
        x2 = 1;
      }
    }
    tfield4[pi2] = ch; 
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield4[pi2] = '\0'; 

  operand_1 = 0;
  if (operand_1 == 0) 
  {
    p = strstr(tfield3, "==");
    if (p)
    {
      operand_1 = 1;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield3, "!=");
    if (p)
    {
      operand_1 = 2;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield3, "<=");
    if (p)
    {
      operand_1 = 3;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield3, ">=");
    if (p)
    {
      operand_1 = 4;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield3, "=");
    if (p)
    {
      operand_1 = 5;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield3, "<");
    if (p)
    {
      operand_1 = 6;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(tfield3, ">");
    if (p)
    {
      operand_1 = 7;
    }
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield1a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
        strcpy(ar_field5, gw_variable[I].gv_dsect);
        strcpy(ar_field6, gw_variable[I].gv_label);
        strcpy(ar_field7, gw_variable[I].gv_table);
        strcpy(ar_field8, gw_variable[I].gv_aname);
        strcpy(ar_field9, gw_variable[I].gv_sv_reg);
        strcpy(ar_field10, gw_variable[I].gv_wk_reg);
        strcpy(ar_field11, gw_variable[I].gv_wk_strg);
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_2 if-018 tfield1 Not Found = %s\n",tfield1);
    printf("c2z_if.c if_case_2 rct = %d p_string = %s", rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield2, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(tfield2a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield2a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_2 if-019 tfield2 Not Found = %s\n",tfield2);
    printf("c2z_if.c if_case_2 rct = %d p_string = %s", rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, ar_field7);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #4");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #6");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, tfield2a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield2);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #7");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #8");
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, "L");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #9");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #10");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #11");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #12");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LAEY  R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #14");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #15");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_2 #16");
    trace_rec_3();
  }

  if(fd4_type == 1)
  {
     printf("c2z_if.c case_2 NOT CODED\n");
     printf("c2z_if.c case_2 rct = %d p_string = %s\n",rct,p_string);
     convert = 1;
     erct++;
     return;
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, tfield4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_2 #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_2 #18");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_2 #19");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_2 #20");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_2 #21");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_2 #22");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R8),0(6,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_2 #23");
      trace_rec_3();
    }

    if(operand_1 == 1)
    {
      strcpy(a_string, "         JLNE  ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
         strcpy(trace_1, "c2z_if.c if_case_2 #9");
         trace_rec_3();
      }
    }

    if(operand_1 == 2)
    {
      strcpy(a_string, "         JLE   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
         strcpy(trace_1, "c2z_if.c if_case_2 #9");
         trace_rec_3();
      }
    }

    if(operand_1 == 3)
    {
      printf("c2z_if.c case_2 This operand NOT CODED operand_1 = %d\n",operand_1);
      printf("c2z_if.c case_2 rct = %d p_string = %s\n", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if(operand_1 == 4)
    {
      printf("c2z_if.c case_2 This operand NOT CODED operand_1 = %d\n",operand_1);
      printf("c2z_if.c case_2 rct = %d p_string = %s\n", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if(operand_1 == 5)
    {
      printf("c2z_if.c case_2 This operand NOT CODED operand_1 = %d\n",operand_1);
      printf("c2z_if.c case_2 rct = %d p_string = %s\n", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if(operand_1 == 6)
    {
      printf("c2z_if.c case_2 This operand NOT CODED operand_1 = %d\n",operand_1);
      printf("c2z_if.c case_2 rct = %d p_string = %s\n", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    if(operand_1 == 7)
    {
      printf("c2z_if.c case_2 This operand NOT CODED operand_1 = %d\n",operand_1);
      printf("c2z_if.c case_2 rct = %d p_string = %s\n", rct,p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  convert = 1;
  return;
}


/* ***************************************************
*  if_case_3                                         *
* ************************************************** */
void if_case_3() 						/* >  */
{
  if (traceflg == 1) {
    strcpy(trace_1, "c2z_if.c if_case_3");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];

  int pi;
  int pi2;
  int fd1_type = 0;
  int fd2_type = 0;
  int I = 0;
  int x = 0;
  int x2 = 0;
  int x3 = 0;
  int ret = 0;
  int ret1 = 0;

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x3 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    if ((ch == '_') && (x3 == 0)) 
    {
      x3 = 1;
    }
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
      x = strcmp(lw_variable[I].lv_type, "I");
      if (x == 0) 
      {
        fd1_type = 2;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_3 if-020 field1 Not Found = %s\n", field1);
    printf("c2z_if.c if_case_3 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(gw_variable[I].gv_name, field1);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field1a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
        x = strcmp(gw_variable[I].gv_type, "I");
        if (x == 0) 
        {
          fd1_type = 2;
        } 
        else 
        {
          fd1_type = 1;
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_3 if-021 field1 Not Found = %s\n", field1);
    printf("c2z_if.c if_case_3 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  while (ch != ')') 
  {
    if (x2 == 0) 
    {
      if (isdigit(ch)) 
      {
        fd2_type = 1;
        x2 = 1;
      }

      if (isalpha(ch)) 
      {
        fd2_type = 2;
        x2 = 1;
      }
    }
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field2, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field2a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
      x = strcmp(lw_variable[I].lv_type, "I");
      if (x == 0) 
      {
        fd1_type = 2;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_3 if-022 field2 Not Found = %s\n", field2);
    printf("c2z_if.c if_case_3 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field2a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
        x = strcmp(gw_variable[I].gv_type, "I");
        if (x == 0) 
        {
          fd2_type = 2;
        }
      }
    }
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcpy(o_string, a_string);
  check_length();
  strcat(a_string, "EQU    *");

  if (fd1_type == 2) 
  {
    strcpy(a_string, "         CP    ");
    strcat(a_string, field1);
  }
  if (fd1_type == 1) 
  {
    printf("\nc2z_if.c if_case_3 if-023 fd1_type == 1 NOT coded\n");
    printf("c2z_if.c if_case_3 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  strcat(a_string, ",");
  if (fd2_type == 2) 
  {
    strcat(a_string, field2);
  }

  if (fd2_type == 1) 
  {
    strcat(a_string, "=P'");
    strcat(a_string, field2);
    strcat(a_string, "'");
  }

  src_line();
  if (puncde == 1)
  {
    trace_rec_3();
  }

  strcpy(a_string, "         JLH   ");
  strcat(a_string, o_string);
  src_line();
  if (puncde == 1)
    trace_rec_3();

  convert = 1;
  return;
}

/* ***************************************************
*  if_case_4                                         *
* ************************************************** */
void if_case_4() 			/* <  */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_4 START");
    trace_rec_1();
  }

  char *p, *p4;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field6a[VAR_LGTH];

  int pi;
  int pi2;
  int fd1_type = 0;
  int fd2_type = 0;
  int I = 0;
  int x = 0;
  int x2 = 0;
  int x3 = 0;
  int x80 = 0;
  int ret = 0;
  int ret1 = 0;
  int complex_if = 0;
  int operand_1 = 0;
  int operand_2 = 0;

  p4 = strstr(p_string, "&&");
  if (p4)
  {
    complex_if = 1;
  }

  p4 = strstr(p_string, "||");
  if (p4)
  {
    complex_if = 2;
  }

  if ((complex_if == 1) || (complex_if == 2)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_4 subroutine #1 START");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ')') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      field4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field4[pi2] = '\0';

    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      field5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';

    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ')') 
    {
      field6[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field6[pi2] = '\0';

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(field2, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    operand_2 = 0;
    if (operand_2 == 0) 
    {
      p = strstr(field5, "==");
      if (p)
      {
        operand_2 = 1;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, "!=");
      if (p)
      {
        operand_2 = 2;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, "<=");
      if (p)
      {
        operand_2 = 3;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, ">=");
      if (p)
      {
        operand_2 = 4;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, "=");
      if (p)
      {
        operand_2 = 5;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, "<");
      if (p)
      {
        operand_2 = 6;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(field5, ">");
      if (p)
      {
        operand_2 = 7;
      }
    }

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
      printf("\nc2z_if.c if_case_4 Eif-024 field1 Not Found = %s\n", field1);
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field4a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field4a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_4 if=025 field4 Not Found = %s\n", field4);
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field6, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field6a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field6, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field6a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_4 if-026 field6 Not Found = %s\n", field6);
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         CLC   ");
    strcat(a_string, "=C'");
    strcat(a_string, "\"");
    strcat(a_string, "'");
    strcat(a_string, ",");
    strcat(a_string, field1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_4 #1");
      trace_rec_3();
    }

    if (operand_1 == 1) 
    {
      printf("\nc2z_if.c if_case_4 if-027 operand_1 == 1 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 2) 
    {
      strcpy(a_string, "         JLE   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 #2");
        trace_rec_3();
      }
    }

    if (operand_1 == 3) 
    {
      printf("\nc2z_if.c if_case_4 if-028 operand_1 == 3 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 4) 
    {
      printf("\nc2z_if.c if_case_4 if-029 operand_1 == 4 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 5) 
    {
      printf("\nc2z_if.c if_case_4 if-030 operand_1 == 5 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 6) 
    {
      printf("\nc2z_if.c if_case_4 if-031 operand_1 == 6 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 7) 
    {
      printf("\nc2z_if.c if_case_4 if-032 operand_1 == 7 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9");
    strcat(a_string, field4a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_4 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8");
    strcat(a_string, field6a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_4 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_4 #5");
      trace_rec_3();
    }

    if (operand_2 == 1) 
    {
      printf("\nc2z_if.c if_case_4 if-033 operand_2 == 1 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_2 == 2) 
    {
      printf("\nc2z_if.c if_case_4 if-034 operand_2 == 2 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_2 == 3) 
    {
      printf("\nc2z_if.c if_case_4 if-035 operand_2 == 3 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_2 == 4) 
    {
      printf("\nc2z_if.c if_case_4 if-036 operand_2 == 4 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_2 == 5) 
    {
      printf("\nc2z_if.c if_case_4 if-037 operand_2 == 5 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_2 == 6) 
    {
      strcpy(a_string, "         JLE   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 #6");
        trace_rec_3();
      }

      strcpy(a_string, "         JLH   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 #7");
        trace_rec_3();
      }
    }

    if (operand_2 == 7) 
    {
      printf("\nc2z_if.c if_case_4 if-038 operand_2 == 7 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if (complex_if == 0) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_4 subroutine #2 START");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    x3 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      if ((ch == '_') && (x3 == 0)) 
      {
        x3 = 1;
      }
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
        x = strcmp(lw_variable[I].lv_type, "I");
        if (x == 0) 
        {
          fd1_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(gw_variable[I].gv_name, field1);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x = strcmp(gw_variable[I].gv_type, "I");
          if (x == 0) 
          {
            fd1_type = 2;
          } 
          else 
          {
            fd1_type = 1;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_4 if-039 field1 Not Found = %s\n", field1);
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          fd2_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          fd2_type = 2;
          x2 = 1;
        }
      }
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    if (fd2_type == 2) 
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 subroutine #3 START");
        trace_rec_1();
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          x = strcmp(lw_variable[I].lv_type, "I");
          if (x == 0) 
          {
            fd1_type = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field2, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            x = strcmp(gw_variable[I].gv_type, "I");
            if (x == 0) 
            {
              fd2_type = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_4 if-040 field2 Not Found = %s\n", field2);
        printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(field3, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(o_string, a_string);
    check_length();
    strcat(a_string, "EQU    *");

    if (fd1_type == 2) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, field1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #1");
        trace_rec_3();
      }
    }

    if (fd1_type == 1) 
    {
      printf("\nc2z_if.c if_case_4 if-041 fd1_type == 1 NOT Coded\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcat(a_string, ",");
    if (fd2_type == 2) 
    {
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #2");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #3");
        trace_rec_3();
      }
    }

    if (fd2_type == 1) 
    {
      x80 = 0;
      ret = strcmp("0", field2);
      if(ret == 0)
      {
        strcpy(field2a, "C370ZERO");
        x80 = 1;
      }

      if(x80 == 0)
      {
        ret = strcmp("1", field2);
        if(ret == 0)
        {
          strcpy(field2a, "C370ONE");
          x80 = 1;
        }
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, field2a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #4");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #5");
        trace_rec_3();
      }
    }

    if (operand_1 == 1) 				/* ==	*/
    {
      strcpy(a_string, "         JNE  ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #6");
        trace_rec_3();
      }
    }

    if (operand_1 == 2) 				/* !=	*/
    {
      strcpy(a_string, "         JLE  ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #7");
        trace_rec_3();
      }
    }

    if (operand_1 == 3) 				/* <=	*/
    {
      printf("\nc2z_if.c if_case_4 if-042 complex = 0 E-131 operand_1 == 3 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 4) 				/* >=	*/
    {
      printf("\nc2z_if.c if_case_4 if-043 complex = 0 E-132 operand_1 == 4 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 5) 				/* =	*/
    {
      printf("\nc2z_if.c if_case_4 if-044 complex = 0 E-133 operand_1 == 5 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 6) 				/* <	*/
    {
      strcpy(a_string, "         JLE   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #8");
        trace_rec_3();
      }

      strcpy(a_string, "         JLH   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_4 complex_if == 0 #9");
        trace_rec_3();
      }
    }

    if (operand_1 == 7) 				/* >	*/
    {
      printf("\nc2z_if.c if_case_4 if-045 complex = 0 E-134 operand_1 == 7 NOT CODED\n");
      printf("c2z_if.c if_case_4 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }
  convert = 1;
  return;
}

/* ***************************************************
*  if_case_6                                         *
* ************************************************** */
void if_case_6() 				/* <=  */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_6");
    trace_rec_1();
  }

  char *p;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field6a[VAR_LGTH];

  int pi;
  int pi2;
  int fd1_type = 0;
  int fd2_type = 0;
  int I = 0;
  int if_10 = 0;
  int x = 0;
  int x2 = 0;
  int x3 = 0;
  int ret = 0;
  int ret1 = 0;

  p = strstr(p_string, "&&");
  if (p)
  {
    if_10 = 1;
  }

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    if (ch != '(') 
    {
      field1[pi2] = ch;
      pi2++;
    }
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
      x = strcmp(lw_variable[I].lv_type, "I");
      if (x == 0) 
      {
        fd1_type = 2;
      }
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(gw_variable[I].gv_name, field1);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field1a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
        x = strcmp(gw_variable[I].gv_type, "I");
        if (x == 0) 
        {
          fd1_type = 2;
        } 
        else 
        {
          fd1_type = 1;
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if_c if_case_6 if-046 field1 Not Found = %s\n", field1);
    printf("c2z_if.c if_case_6 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  while (ch != ')') 
  {
    if (x2 == 0) 
    {
      if (isdigit(ch)) 
      {
        fd2_type = 1;
        x2 = 1;
      }

      if (isalpha(ch)) 
      {
        fd2_type = 2;
        x2 = 1;
      }
    }
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  if (fd2_type == 1) 
  {
    strcpy(field2a, field2);
  }

  if (fd2_type == 2) 
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
        x = strcmp(lw_variable[I].lv_type, "I");
        if (x == 0) 
        {
          fd1_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x = strcmp(gw_variable[I].gv_type, "I");
          if (x == 0) 
          {
            fd2_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_6 if-047 field2 Not Found = %s\n", field2);
      printf("c2z_if.c if_case_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcpy(o_string, a_string);
  check_length();
  strcat(a_string, "EQU    *");

  if (fd1_type == 2) 
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_6 #1");
      trace_rec_3();
    }
  }

  if (fd1_type == 1) 
  {
    printf("\nc2z_if.c if_case_6 if-048 fd1_type == 1 NOT Coded\n");
    printf("c2z_if.c if_case_6 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (fd2_type == 2) 
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_6 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_6 #3");
      trace_rec_3();
    }
  }

  if (fd2_type == 1) 
  {
    strcat(a_string, "=P'");
    strcat(a_string, field2a);
    strcat(a_string, "'");
  }

  strcpy(a_string, "         JLH   ");
  strcat(a_string, o_string);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_6 #4");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ");
  strcat(a_string, o_string);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_6 #5");
    trace_rec_3();
  }

  if (if_10 == 1) 			/* combined statement	*/
  {
    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      field4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field4[pi2] = '\0';

    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field4, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field4a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
        x = strcmp(gw_variable[I].gv_type, "I");
        if (x == 0) 
        {
          fd1_type = 2;
        } 
        else 
        {
          fd1_type = 1;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_6 if-049 field4 Not Found = %s\n", field4);
      printf("c2z_if.c if_case_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while (ch != ' ') 
    {
      field5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';
    strcpy(field5a, null_field);

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          fd2_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          fd2_type = 2;
          x2 = 1;
        }
      }
      field6[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field6[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field6, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field6a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
        x = strcmp(gw_variable[I].gv_type, "I");
        if (x == 0) 
        {
          fd1_type = 2;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_6 if-050 field6 Not Found = %s\n", field6);
      printf("c2z_if.c if_case_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field6, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field6a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          x = strcmp(gw_variable[I].gv_type, "I");
          if (x == 0) 
          {
            fd2_type = 2;
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_6 if-051 field6 Not Found = %s\n", field6);
      printf("c2z_if.c if_case_6 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    ret = strcmp("<", field5);
    if (ret == 0) 
    {
      if (fd2_type == 2) 
      {
        strcpy(a_string, "         CP    ");
        strcat(a_string, field4a);
      }

      if (fd2_type == 1) 
      {
        printf("\nc2z_if.c if_case_6 if-052 fd2_type == 1 NOT Coded\n");
        printf("c2z_if.c if_case_6 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcat(a_string, ",");
      if (fd2_type == 2) 
      {
        strcat(a_string, field6a);
      }

      if (fd2_type == 1) 
      {
        strcat(a_string, "=P'");
        strcat(a_string, field6a);
        strcat(a_string, "'");
      }

      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_6 #6");
        trace_rec_3();
      }

      strcpy(a_string, "         JNL   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_6 #7");
        trace_rec_3();
      }
    }
  }
  convert = 1;
  return;
}

/* ***************************************************
*  if_case_7                                         *
* ************************************************** */
void if_case_7() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_7 START");
    trace_rec_1();
  }

  char *p, *p7;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];

  char wk_sv_func[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield4a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield11[VAR_LGTH];

  int pi;
  int pi2;
  int operand_1 = 0;
  int I = 0;
  int x2 = 0;
  int x3 = 0;
  int v = 0;
  int if_complex = 0;
  int if_short = 0;
  int if_negative = 0;
  int ret = 0;
  int ret1 = 0;
  int set_math = 0;
  int x40 = 0;
  int fd6_type;

  var_use[10]++;

  p = strstr(p_string, "&&");
  if (p)
  {
    if_complex = 1;
  }

  p = strstr(p_string, "||");
  if (p)
  {
    if_complex = 1;
  }

  if (if_complex == 0) 
  {
    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
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
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_7 if-053 field1 Not Found = %s\n", field1);
      printf("c2z_if.c if_case_7 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi++;
    ch = p_string[pi];
    if (ch == ')') 
    {
      if_short = 1;
    }

    if (if_short == 1) 
    {
      p7 = strstr(p_string, "!isdigit");
      if (p7)
      {
        if_negative = 1;
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcpy(o_string, a_string);
      check_length();
      strcat(a_string, "DS     0H");

      if (if_negative == 0) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #1");
          trace_rec_1();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #2");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #3");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #4");
          trace_rec_3();
        }
        work_use_ct[2]++;
      }

      if (if_negative == 1) 
      {
        if (traceflg == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_7 subroutine #3");
          trace_rec_1();
        }

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #5");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field1a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #6");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #7");
          trace_rec_3();
        }
        work_use_ct[2]++;
      }

      strcpy(a_string, "         LARL  R15,ISDIGIT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_7 #8");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_7 #8");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370DIGT");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_7 #9");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_7 #10");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_7 #11");
        trace_rec_3();
      }
      work_use_ct[31]++;

      if (if_negative == 1) 
      {
        strcpy(a_string, "         JLE   ");
        strcat(a_string, o_string);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #12");
          trace_rec_3();
        }
      }

      if (if_negative == 0) 
      {
        strcpy(a_string, "         JNE   ");
        strcat(a_string, o_string);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #13");
          trace_rec_3();
        }
      }
    }

    if (if_short == 0) 
    {
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ' ') 
      {
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field2[pi2] = '\0';

      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      while (ch != ')') 
      {
        pi++;
        ch = p_string[pi];
      }

      operand_1 = 0;
      if (operand_1 == 0) 
      {
        p = strstr(field2, "==");
        if (p)
        {
          operand_1 = 1;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, "!=");
        if (p)
        {
          operand_1 = 2;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, "<=");
        if (p)
        {
          operand_1 = 3;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, ">=");
        if (p)
        {
          operand_1 = 4;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, "=");
        if (p)
        {
          operand_1 = 5;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, "<");
        if (p)
        {
          operand_1 = 6;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(field2, ">");
        if (p)
        {
          operand_1 = 7;
        }
      }

      if (operand_1 == 1) 
      {
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcpy(o_string, a_string);
        check_length();
        strcat(a_string, "DS     0H");

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #100");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field1a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #101");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #102");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         LARL  R15,ISDIGIT");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #103");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #103");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370DIGT");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #104");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #105");
          trace_rec_3();
        }
        work_use_ct[33]++;

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #106");
          trace_rec_3();
        }
        work_use_ct[31]++;

        strcpy(a_string, "         JLE   ");
        strcat(a_string, o_string);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #107");
          trace_rec_3();
        }
      }

      if (operand_1 == 2) 
      {
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcpy(o_string, a_string);
        check_length();
        strcat(a_string, "DS     0H");

        strcpy(a_string, "         LARL  R9,C370L1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 short #9");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, field1a);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 short #10");
          trace_rec_3();
        }

        strcpy(a_string, "         MVC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 short #11");
          trace_rec_3();
        }
        work_use_ct[2]++;

        strcpy(a_string, "         LARL  R15,ISDIGIT");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 short #12");
          trace_rec_3();
        }

        strcpy(a_string, "         BAKR  0,R15");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 short #12");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,C370ISDG");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 short #13");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370ONE");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 short #14");
          trace_rec_3();
        }
        work_use_ct[33]++;

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 short #15");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, o_string);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 short #16");
          trace_rec_3();
        }
      }

      if (operand_1 == 3) 
      {
        printf("\nc2z_if.c if_case_7 if-054 NON-Short operand_1 = 3 NOT CODED\n");
        printf("c2z_if.c if_case_7 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 4) 
      {
        printf("\nc2z_if.c if_case_7 if-055 NON-Short operand_1 = 4 NOT CODED\n");
        printf("c2z_if.c if_case_7 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 5) 
      {
        printf("\nc2z_if.c if_case_7 if-056 NON-Short operand_1 = 5 NOT CODED\n");
        printf("c2z_if.c if_case_7 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 6) 
      {
        printf("\nc2z_if.c if_case_7 if-057 NON-Short operand_1 = 6 NOT CODED\n");
        printf("c2z_if.c if_case_7 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 7) 
      {
        printf("\nc2z_if.c if_case_7 if-058 NON-Short operand_1 = 7 NOT CODED\n");
        printf("c2z_if.c if_case_7 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }
    convert = 1;
    return;
  }

  if (if_complex == 1) 
  {
    /* if((! isdigit(ch)) && (ch != '.')) */
    /* else if((isdigit(ch)) || (IsAddop(ch)))    works  */

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ')') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      if (ch == ' ') 
      {
        break;
      }
      tfield4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

    set_math = 0;
    p = strstr(p_string, "!=");
    if (p) 
    {
      set_math = 1;
    }

    p = strstr(p_string, "==");
    if (p) 
    {
      set_math = 1;
    }

    if (set_math == 0) 
    {
      x40 = 0;
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if (ch == '\'') 
        {
          x40 = 1;
        }

        tfield6[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield6[pi2] = '\0';
    }

    if (set_math == 1) 
    {
      pi++;
      ch = p_string[pi];
      while (ch == ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      ch = p_string[pi];
      while(ch != ' ')
      {
        tfield5[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield5[pi2] = '\0';

      ch = p_string[pi];
      while (ch != ' ') 
      {
        pi++;
        ch = p_string[pi];
      }

      fd6_type = 0;
      x2 = 0;
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        if (ch == '\'') 
        {
          x40 = 1;
        }
        if((x2 == 0) && (x40 != 1))
        {
          if (isalpha(ch)) 
          {
            fd6_type = 1;
            x2 = 1;
          }

          if (isdigit(ch)) 
          {
            fd6_type = 2;
            x2 = 1;
          }
        }
        tfield6[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      tfield6[pi2] = '\0';
    }

    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield2, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield2a, lw_variable[v].lv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield2, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield2a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_7 complex == 1 if-059 tfield2 Not Found = %s\n",tfield2);
      printf("c2z_if.c if_case_7 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    x3 = 0;
    if (lv_ct > 0) 
    {
      for (v = 0; v < lv_ct; v++) 
      {
        ret = strcmp(tfield4, lw_variable[v].lv_name);
        ret1 = strcmp(sv_func, lw_variable[v].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield4a, lw_variable[v].lv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (v = 0; v < gv_ct; v++) 
        {
          ret = strcmp(tfield4, gw_variable[v].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield4a, gw_variable[v].gv_cname);
          }
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_7 complex == 1 if-060 tfield4 Not Found = %s\n",tfield4);
      printf("c2z_if.c if_case_7 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(tfield5, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield5, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield5, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield5, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield5, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield5, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield5, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_7 #700");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark,tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_7 #701");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_7 #702");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,ISDIGIT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_7 #703");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_7 #704");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370DIGT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_7 #705");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_7 #706");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_7 #707");
      trace_rec_3();
    }
    work_use_ct[31]++;

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "         JLNE  L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_7 #708");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < fn_ct; I++) 
    {
      ret = strcmp(tfield4, w_function[I].fn_name);
      if (ret == 0) 
      {
        strcpy(tfield4a, w_function[I].fn_cname);
        strcpy(tfield11, w_function[I].fn_ret_var);
        strcpy(wk_sv_func, tfield4);
      }
    }

    if (x40 == 0) 
    {
      x3 = 0;
      if (lv_ct > 0) 
      {
        for (v = 0; v < lv_ct; v++) 
        {
          ret = strcmp(tfield6, lw_variable[v].lv_name);
          ret1 = strcmp(wk_sv_func, lw_variable[v].lv_func);
          if ((ret == 0) && (ret1 == 0)) 
          {
            x3 = 1;
            strcpy(tfield6a, lw_variable[v].lv_cname);
          }
        }
      }

      if (x3 == 0) 
      {
        if (gv_ct > 0) 
        {
          for (v = 0; v < gv_ct; v++) 
          {
            ret = strcmp(tfield6, gw_variable[v].gv_name);
            if (ret == 0) 
            {
              x3 = 1;
              strcpy(tfield6a, gw_variable[v].gv_cname);
            }
          }
        }
      }
    }

    if(x40 == 1)
    {
       for (I = 0; I < char_ct; I++) 
       {
         if (w_charlit[I].clit_rct == rct) 
         {
            strcpy(tfield6a, w_charlit[I].clit_cname);
            x3 = w_charlit[I].clit_lgth;
         }
       }
    }

    if(fd6_type == 2)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield6);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield6);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_7 #709a");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_7 #709b");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_7 #709c");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK2");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_7 #709d");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_7 #709e");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_7 #709f");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield4a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield4);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_7 #709g");
        trace_rec_3();
      }
     
      if(operand_1 == 1)
      {
        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #709h");
          trace_rec_3();
        }
 
        strcpy(a_string, "         JLNE  L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_7 #709i");
          trace_rec_3();
        }
      }
    }
  }
 
  convert = 1;
  return;
}



/* ***************************************************
*  if_case_8                                         *
* ************************************************** */
void if_case_8() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_8 isalpha");
    trace_rec_1();
  }

  char *p4, *wkp;
  char *p;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field4[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int x2 = 0;
  int x3 = 0;
  int fd4_type = 0;
  int complex_if = 0;
  int ret = 0;
  int ret1 = 0;
  int s = 0;
  int L_par = 0;
  int R_par = 0;
  int operand_1 = 0;

  p4 = strstr(p_string, "&&");
  if (p4)
  {
    complex_if = 1;
  }

  p4 = strstr(p_string, "||");
  if (p4)
  {
    complex_if = 2;
  }

  s = strlen(p_string);
  for(I = 0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '(')
    {
      L_par++;
    }
    if(ch== ')')
    {
      R_par++;
    }
  }

  if((L_par == 5) && (R_par == 5))
  {
    goto skip_case_8;
  }

  if (complex_if == 0) 
  {
    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    x3 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if ((ch == '_') && (x3 == 0)) 
      {
        x3 = 1;
      }
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
      printf("\nc2c_if.c c2_case_8 if-060 field1 Not Found = %s\n", field1);
      printf("c2z_if.c if_case_8 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    /* test end of if )) */
    operand_1 = 0;
    pi++;
    ch = p_string[pi];
    if(ch == ')')
    {
      goto skip_case8a;
    }

    pi++;
    ch = p_string[pi];
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while(ch != ' ')
    {
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    fd4_type = 0;
    pi2 = 0;
    while(ch != ')')
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          x2 = 1;
        }
      }
      field4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field4[pi2] = '\0';

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(field3, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field3, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    skip_case8a:

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_8 isalpha #1");
      trace_rec_3();
    }
    work_use_ct[59]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_8 isalpha #2");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_8 isalpha #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,ISALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_8 isalpha #4");
      trace_rec_3();
    }
    var_use[9]++;

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_8 isalpha #4");
      trace_rec_3();
    }

    if(operand_1 == 0)
    {
      strcpy(a_string, "         LARL  R9,C370ISAL");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_8 isalpha #5");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_8 isalpha #6");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_8 isalpha #7");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_8 isalpha #8");
        trace_rec_3();
      }
    }

    if((operand_1 != 0) && (fd4_type == 0))
    {
      strcpy(a_string, "         LARL  R9,C370ISAL");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_8 isalpha #9");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_8 isalpha #10");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_8 isalpha #11");
        trace_rec_3();
      }

      strcpy(a_string, "         JLNE  ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_8 isalpha #12");
        trace_rec_3();
      }
    }

  }

  if (complex_if == 1) 
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field1, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field1a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(gw_variable[I].gv_name, field1);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field1a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_8 isalpha if=060 field1 Not Found = %s\n",field1);
      printf("c2z_if.c if_case_8 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ')') 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_8 if-062 Field2 Not Found = %s\n", field2);
      printf("c2z_if.c if_case_8 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    var_use[9]++;

    wkp = strstr(p_string, "!");
    if (wkp) 
    {
      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi++;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        field1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';

      strcpy(a_string, "         MVC   C370L1A,");
      strcat(a_string, field1);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #9");
        trace_rec_3();
      }
      work_use_ct[59]++;

      strcpy(a_string, "         LARL  R15,ISALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #10");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #10");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISAL");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #11");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #12");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #13");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #14");
        trace_rec_3();
      }
    }

    if (!wkp) 				/* equal test       */
    {
      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi++;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != ')') 
      {
        field1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';

      strcpy(a_string, "         MVC   C370L1A,");
      strcat(a_string, field1);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #15");
        trace_rec_3();
      }
      work_use_ct[59]++;

      strcpy(a_string, "         LARL  R15,ISALPHA");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #16");
        trace_rec_3();
      }

      strcpy(a_string, "         BAKR  0,R15");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #17");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370ISAL");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #17");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #18");
        trace_rec_3();
      }
      work_use_ct[33]++;

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #19");
        trace_rec_3();
      }

      strcpy(a_string, "         JNE   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_8 isalpha #20");
        trace_rec_3();
      }
    }
    convert = 1;
    return;
  }

  skip_case_8:

  if((L_par == 5) && (R_par == 5))
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 L5 & R5 isalpha START");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while(ch != '(')
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    pi++;

    pi2 = 0;
    ch = p_string[pi];
    while(ch != '(')
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while(ch != ')')
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    pi++;
    pi++;
    ch = p_string[pi];
    while(ch == ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    while(ch != ' ')
    {
      pi++;
      ch = p_string[pi];
    }

    while(ch != '(')
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
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
      field5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field5[pi2] = '\0';

    strcpy(a_string, "         LARL  R9,C370L1A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #820");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_8 L_par & R_par if-063 Field2 Not Found = %s\n", field2);
      printf("c2z_if.c if_case_8 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #821");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #822");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,ISALPHA");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 isalpha #16");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 isalpha #17");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370ISAL");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #824");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #825");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #826");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370L1A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #827");
      trace_rec_3();
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field5, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret == 0)) 
      {
        x3 = 1;
        strcpy(field5a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field5, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field5a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_8 L_par & R_par if-064 Field5 Not Found = %s\n", field5);
      printf("c2z_if.c if_case_8 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field5a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #828");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #829");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,ISDIGIT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #830");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #829");
      trace_rec_3();
    }
     
    strcpy(a_string, "         LARL  R9,C370DIGT");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #831");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #832");
      trace_rec_3();
    }

    strcpy(a_string, "         JLNE  L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "e");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #826");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "C");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_8 #830");
      trace_rec_3();
    }

    convert = 1;
    return;
  }
}


/* ***************************************************
*  if_case_9                                         *
* ************************************************** */
void if_case_9() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_9");
    trace_rec_1();
  }

  char *p8;
  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];

  int pi;
  int pi2;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int x3 = 0;

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != '(') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field2, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      strcpy(field2a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(field2a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  p8 = strstr(field1, "!");
  if (p8) 
  {

  } 
  else 
  {
    printf("\nc2z_if.c if_case_9 if-173 NO ! in FEOF\n");
    erct++;
    convert = 1;
    return;
  }
}


/* ***************************************************
*  if_case_10                                        *
* ************************************************** */
void if_case_10() 						/* if(strcmp(token, "END") == 0)	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_10 START");
    trace_rec_1();
  }

  int pi;
  int pi2;
  int if_1 = 0;
  int if_2 = 0;
  int if_4 = 0;
  int I = 0;
  int x3 = 0;
  int x80 = 0;
  int ret = 0;
  int ret1 = 0;
  int operand_1 = 0;

  char *p, *p1;
  char ch;
  char field1a[VAR_LGTH];
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];

  /* if(strcmp(keyword, "LOCATE") == 0) byte=3; */

  x80 = 0;
  p1 = strstr(p_string, ";");
  if (p1) 
  {
    x80 = 1;
  }

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ',') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  if_1 = 0;
  pi2 = 0;
  while (ch != ')') 
  {
    if (ch == '\"') 
    {
      if_1 = 1;
    }
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  ch = p_string[pi];
  while (ch != ' ') 
  {
    tfield3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield3[pi2] = '\0';

  if (if_1 == 1) 
  {
    
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          if_4 = 1;
          strcpy(tfield1a, lw_variable[I].lv_cname);
        }
      }
    }

    if (if_4 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          if_2 = strcmp(tfield1, gw_variable[I].gv_name);
          if (if_2 == 0) 
          {
            if_4 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
          }
        }
      }
    }

    if (if_4 == 0) 
    {
      printf("\nc2z_if.c c2_if_10 if_1 = 1 if-065 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_if.c c2_if_10 if_1 = 1 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    p = strstr(tfield3, "==");
    if (p)
    {
      operand_1 = 1;
    }

    p = strstr(tfield3, "!=");
    if (p)
    {
      operand_1 = 2;
    }

    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(tfield2a, w_charlit[I].clit_cname);
        x3 = w_charlit[I].clit_lgth;
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_10 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_10 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_10 #3");
      trace_rec_3();
    }

    if (operand_1 == 1) 
    {
      strcpy(a_string, "         JNE   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      /* strcat(a_string, "E"); */
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_10 #4");
        trace_rec_3();
      }
    }

    if(operand_1 == 2)
    {
      strcpy(a_string, "         JLE   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      src_line();
      if(puncde == 1)
      {
        strcpy(trace_1, "c2z_if.c case_10 #5");
        trace_rec_3();
      }
    } 

    if (x80 == 0) 
    {
      goto if_case_10_skip;
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    while (ch != ')') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != '=') 
    {
      if(ch != ' ')
      {
        tfield5[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield5[pi2] = '\0';

    pi2 = strlen(tfield5);
   
    pi++;
    ch = p_string[pi];
    while (ch != ';') 
    {
      pi++;
      ch = p_string[pi];
    }

    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield5, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          if_4 = 1;
          strcpy(tfield5a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (if_4 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          if_2 = strcmp(tfield5, gw_variable[I].gv_name);
          if (if_2 == 0) 
          {
            if_4 = 1;
            strcpy(tfield5a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (if_4 == 0) 
    {
      printf("\nc2z_if.c c2_if_10 if-066 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_if.c c2_if_10 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield5a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_10 #6");
      trace_rec_3();
    }

/*
    for (I = 0; I < math_lit_ct; I++) 
    {
      if (rct == w_mathlit[I].lit_rct) 
      {
        strcpy(tfield6a, w_mathlit[I].lit_use_cname);
        break;
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield6a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_10 #7");
      trace_rec_3();
    }
*/
    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_10 #8");
      trace_rec_3();
    }

  if_case_10_skip:

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_10 #9");
      trace_rec_3();
    }

    convert = 1;
  }

  if (if_1 == 0) 			/* literal for strcmp field1  	*/
  {
    if_4 = 0;
    if (lv_ct > 0) 
    {
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          if_4 = 1;
          strcpy(tfield2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }
    }

    if (if_4 == 0) 
    {
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          if_2 = strcmp(tfield2, gw_variable[I].gv_name);
          if (if_2 == 0) 
          {
            if_4 = 1;
            strcpy(tfield2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }
    }

    if (if_4 == 0) 
    {
      printf("\nc2z_if.c c2_if_10 if_1 = 0 if-067 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_if.c c2_if_10 if_1 = 0 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    for (I = 0; I < char_ct; I++) 
    {
      if (w_charlit[I].clit_rct == rct) 
      {
        strcpy(field1a, w_charlit[I].clit_cname);
        x3 = w_charlit[I].clit_lgth;
      }
    }

    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field1a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_10 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_10 #11");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x3);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R8),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_10 #12");
      trace_rec_3();
    }

    strcpy(a_string, "         JNE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_10 #13");
      trace_rec_3();
    }

    convert = 1;
  }
}

/* ***************************************************
*  Punch out DEFAULT in CASE                         *
* ************************************************** */
void c2_case_default(void) 
{
  if (if_case == 1) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_if.c c2_case_default");
      trace_rec_1();
    }

    /* generate sv_case_break */
    strcpy(save_case_break, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(save_case_break, wk_strg);
    strcat(save_case_break, "E");
  }
}

/* ***************************************************
*  Punch out SWITCH END statement                    *
* ************************************************** */
void c2_case_end(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c c2_case_end");
    trace_rec_1();
  }

  strcpy(a_string, sw_tag);
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c c2_case_end #1");
    trace_rec_3();
  }

  if_case = 0;
  convert = 1;
}

/* ***************************************************
*  Punch out SWITCH statement                        *
* ************************************************** */
void c2_switch(void) 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c c2_switch");
    trace_rec_1();
  }

  if_case = 0;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  int pi;
  int pi2;
  int x3 = 0;
  int x4 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int size = 0;

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  x4 = strlen(c_wkname);
  c_wkname[x4] = '\0';
  strcpy(field1a, c_wkname);

  x3 = 0;
  if (gv_ct > 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        strcpy(field1a, gw_variable[I].gv_cname);
        x3 = 1;
      }
    }
  }

  if (x3 == 0) {
    if (lv_ct > 0) {
      for (I = 0; I < lv_ct; I++) {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) {
          strcpy(field1a, lw_variable[I].lv_cname);
          x3 = 1;
        }
      }
    }
  }

  if ((global_st == 0) && (x3 == 0)) {
    if (gv_ct == 0) {
      size = 1;
      gw_variable = malloc(size * sizeof(struct variables));
    } else {
      size = gv_ct + 1;
      gw_variable = realloc(gw_variable, size * sizeof(struct variables));
    }

    gw_variable[gv_ct].gv_rct = rct;
    strcpy(gw_variable[gv_ct].gv_cname, field1a);
    strcpy(gw_variable[gv_ct].gv_name, field1);
    strcpy(gw_variable[gv_ct].gv_type, "I");
    gw_variable[gv_ct].gv_lgth = 0;
    gw_variable[gv_ct].gv_current_lgth = 0;
    strcpy(gw_variable[gv_ct].gv_value, "0");
    gw_variable[gv_ct].gv_init = 0;
    strcpy(gw_variable[gv_ct].gv_literal, null_field);
    gw_variable[gv_ct].gv_use_ct = 0;
    strcpy(gw_variable[gv_ct].gv_dsect, null_field);
    gw_variable[gv_ct].gv_row = 0;
    gw_variable[gv_ct].gv_column = 0;
    strcpy(gw_variable[gv_ct].gv_dsect, null_field);
    strcpy(gw_variable[gv_ct].gv_label, null_field);
    strcpy(gw_variable[gv_ct].gv_aname, null_field);
    strcpy(gw_variable[gv_ct].gv_sv_reg, null_field);
    strcpy(gw_variable[gv_ct].gv_wk_reg, null_field);
    strcpy(gw_variable[gv_ct].gv_wk_strg, null_field);
    gw_variable[gv_ct].gv_dec = 0;
    gv_ct++;

    x3 = 1;
  }

  if ((global_st == 1) && (x3 == 0)) /* local variable	*/
  {
    x3 = 0;
    if (lv_ct > 0) {
      for (I = 0; I < lv_ct; I++) {
        ret = strcmp(field1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) {
          strcpy(field1a, lw_variable[I].lv_cname);
          x3 = 1;
        }
      }
    }

    if (x3 == 0) {
      if (lv_ct == 0) {
        size = 1;
        lw_variable = malloc(size * sizeof(struct var));
      } else {
        size = lv_ct + 1;
        lw_variable = realloc(lw_variable, size * sizeof(struct var));
      }

      lw_variable[lv_ct].lv_rct = rct;
      strcpy(lw_variable[lv_ct].lv_cname, field1a);
      strcpy(lw_variable[lv_ct].lv_name, field1);
      strcpy(lw_variable[lv_ct].lv_type, "I");
      lw_variable[lv_ct].lv_lgth = 0;
      strcpy(lw_variable[lv_ct].lv_value, "0");
      lw_variable[lv_ct].lv_current_lgth = 0;
      lw_variable[lv_ct].lv_init = 0;
      strcpy(lw_variable[lv_ct].lv_literal, null_field);
      lw_variable[lv_ct].lv_use_ct = 0;
      lv_ct++;
    }
  }

  /*  save switch field value */
  strcpy(sw_field, field1a);

  /*  save rct for end of case label */
  strcpy(sw_tag, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(sw_tag, wk_strg);
  strcat(sw_tag, "E");

  if_case = 1;
}

/* ***************************************************
*  Punch out if(in_stack[ndx][0] == '\0'             *
* ************************************************** */
void if_case_11() 					/*	if(in_stack[ndx][0] == '\0' 	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_11");
    trace_rec_1();
  }

  char *p;
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field11[VAR_LGTH];

  int pi;
  int pi2;
  int fd3_type = 0;
  int if_complex = 0;
  int I = 0;
  int x2 = 0;
  int x3 = 0;
  int x92 = 0;
  int x96 = 0;
  int operand_1 = 0;
  int operand_2 = 0;
  int ret = 0;
  int ret1 = 0;
  int fd4_type = 0;
  int fd9_type = 0;
  int y1 = 0;
  int y2 = 0;
  int y3 = 0;
  int y4 = 0;
  int y5 = 0;

  char tfield1[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield7[VAR_LGTH]; 
  char tfield8[VAR_LGTH];
  char tfield9[VAR_LGTH];
  char tfield10[VAR_LGTH];
  char tfield11[VAR_LGTH];

  char ar_field5[32];
  char ar_field6[32];
  char ar_field7[32];
  char ar_field8[32];
  char ar_field9[32];
  char ar_field10[32];
  char ar_field11[32];
  char ar_field11a[32];

  if_complex = 0;
  p = strstr(p_string, "&&");
  if (p) 
  {
    if_complex = 1;
  }

  p = strstr(p_string, "||");
  if (p) 
  {
    if_complex = 2;
  }

  if (if_complex == 0) 
  {
    pi = 0;
    y1 = strlen(p_string);
    ch = p_string[pi];
    for(y2 = 0; y2 < y1; y2++)
    {
      if(ch == '.')
      {
        y4++;
      }
      if(ch == '[')
      {
        y3++;
      }
      if(ch == ']')
      {
        y5++;
      }
      pi++;
      ch = p_string[pi];
    }

    if((y4 == 0) && (y3 == 2) && (y5 == 2))   /* if(fp[ii][0] == '\0') */
    {
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
      while(ch != '[')
      {
        field1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while(ch != ']')
      {
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field2[pi2] = '\0';

      pi++;
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while(ch != ']')
      {
        field3[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field3[pi2] = '\0';

      while(ch == ' ')
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while(ch != ' ')
      {
        pi2++;
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
      while(ch != ' ')
      {
        field4[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field4[pi2] = '\0';

      while(ch == ' ')
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while(ch != ')')
      {
        if(ch != '\'')
        {
           pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
 
      if (gv_ct > 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            strcpy(tfield5, gw_variable[I].gv_dsect);
            strcpy(tfield6, gw_variable[I].gv_label);
            strcpy(tfield7, gw_variable[I].gv_table);
            strcpy(tfield8, gw_variable[I].gv_aname);
            strcpy(tfield9, gw_variable[I].gv_sv_reg);
            strcpy(tfield10, gw_variable[I].gv_wk_reg);
            strcpy(tfield11, gw_variable[I].gv_wk_strg);
            gw_variable[I].gv_flag = 0;
            x3 = 1;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_11 complex == 0 if-188 field2 Not Found = %s\n",field1);
        printf("c2z_if.c if_case_11 complex == 0 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }

       x3 = 0;
       for (I = 0; I < lv_ct; I++) 
       {
         ret = strcmp(field2, lw_variable[I].lv_name);
         ret1 = strcmp(sv_func, lw_variable[I].lv_func);
         if ((ret == 0) && (ret1 == 0)) 
         {
           x3 = 1;
           strcpy(field2a, lw_variable[I].lv_cname);
           lw_variable[I].lv_use_ct++;
         }
       }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field2, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_11 complex == 0 if-189 field2 Not Found = %s\n",field2);
      printf("c2z_if.c if_case_11 complex == 0 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(field4, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #750");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370ZERO");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #751");
       trace_rec_3();
     }

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #752");
       trace_rec_3();
     }

      strcpy(a_string, "         LAEY  R6,");
      strcat(a_string, tfield7);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_11 #753");
        trace_rec_3();
      }

     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcpy(a_string, "L");
     strcat(a_string, wk_strg);
     strcat(a_string, "B");
     check_length();
     strcat(a_string, "DS    0H");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #754");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #755");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,");
     strcat(a_string, field2a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field2);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #756");
       trace_rec_3();
     }

     strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #757");
       trace_rec_3();
     }

     strcpy(a_string, "         JLE   L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "F");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #758");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #759");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370ONE");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #760");
       trace_rec_3();
     }

     strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #761");
       trace_rec_3();
     }

     strcpy(a_string, "         LA    R6,");
     strcat(a_string, tfield6);
     strcat(a_string, "(R0,R6)");
     strcpy(wk_remark, " ");
     strcat(wk_remark, field1);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #762");
       trace_rec_3();
     }

     strcpy(a_string, "         JLU   ");
     strcat(a_string, "L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "B");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #763");
       trace_rec_3();
     }

     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcpy(a_string, "L");
     strcat(a_string, wk_strg);
     strcat(a_string, "F");
     check_length();
     strcat(a_string, "DS    0H");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #764");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370EOF");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #765");
       trace_rec_3();
     }

     strcpy(a_string, "         CLC   0(1,R9),0(R6)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #766");
       trace_rec_3();
     }

     strcpy(a_string, "         JLNE  L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #767");
       trace_rec_3();
     }

      convert = 1;
      return;
    }

 
    if((y4 == 1) && (y3 == 2) && (y5 == 2))   /* else if(fp[ii].path[0] == '\0') */
    {
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
      while(ch != '[')
      {
        field1[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field1[pi2] = '\0';

      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while(ch != ']')
      {
        field2[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field2[pi2] = '\0';

      pi++;
      pi2 = 0;
      pi++;
      ch = p_string[pi];
      while(ch != '[')
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
      while(ch != ']')
      {
        field4[pi2] = ch;
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      field4[pi2] = '\0';

      pi++;
      ch = p_string[pi];
      while(ch == ' ')
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      while(ch != ' ')
      {
        pi2++;
        pi++;
        ch = p_string[pi];
      }
      
      while(ch == ' ')
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      while(ch != ')')
      {
        if(ch != '\'')
        {
          pi2++;
        }
        pi++;
        ch = p_string[pi];
      }
     
      x3 = 0;
      for (I = 0; I < m_struc_ct; I++) 
      {
        ret = strcmp(field1,w_struc[I].st_name);
        if(ret == 0)
        {
          strcpy(field1a, w_struc[I].st_cname);
          x3 = 1;
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_11 complex == 0 if-153 field1 Stucture Not Found = %s\n",field1);
        printf("c2z_if.c if_case_11 complex == 0 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }
  
       x3 = 0;
       for (I = 0; I < lv_ct; I++) 
       {
         ret = strcmp(field2, lw_variable[I].lv_name);
         ret1 = strcmp(sv_func, lw_variable[I].lv_func);
         if ((ret == 0) && (ret1 == 0)) 
         {
           x3 = 1;
           strcpy(field2a, lw_variable[I].lv_cname);
           lw_variable[I].lv_use_ct++;
         }
       }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field2, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_11 complex == 0 if-173 field2 Not Found = %s\n",field2);
      printf("c2z_if.c if_case_11 complex == 0 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #650");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370ZERO");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #651");
       trace_rec_3();
     }

     strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #652");
       trace_rec_3();
     }

     strcpy(a_string, "         LAEY  R6,");
     strcat(a_string, field1a);
     strcat(a_string, "T");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #653");
       trace_rec_3();
     }

     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcpy(a_string, "L");
     strcat(a_string, wk_strg);
     strcat(a_string, "A");
     check_length();
     strcat(a_string, "DS    0H");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #654");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #655");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,");
     strcat(a_string, field2a);
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #656");
       trace_rec_3();
     }

     strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #657");
       trace_rec_3();
     }

     strcpy(a_string, "         JLE   L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     strcat(a_string, "B");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #658");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #659");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370ONE");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #660");
       trace_rec_3();
     }

     strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #661");
       trace_rec_3();
     }

    strcpy(a_string, "         LAEY  R6,");
    strcat(a_string, field1a);
    strcat(a_string, "L");
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #662");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #663");
      trace_rec_3();
    }

     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcpy(a_string, "L");
     strcat(a_string, wk_strg);
     strcat(a_string, "B");
     check_length();
     strcat(a_string, "DS    0H");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #664");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C370EOF");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c if_case_11 #665");
       trace_rec_3();
     }

     x3 = 0;
     for (I = 0; I < m_struc_ct; I++) 
     {
      ret = strcmp(field1, w_struc[I].st_wname);
      ret1 = strcmp(field3, w_struc[I].st_field_name);
      if ((ret == 0) && (ret1 == 0)) 
      {
         x3 = 1;
         strcpy(field1a, w_struc[I].st_field_cname);
         x92 = w_struc[I].st_field_lgth;
         x96 = w_struc[I].st_disp;
      }
    }

    
    strcpy(a_string, "         MVC   1");
    strcat(a_string, "(");
    snprintf(wk_strg, sizeof(wk_strg), "%d", x92);
    strcat(a_string, wk_strg);
    strcat(a_string, ",R6),");
    x96 = 0;
    snprintf(wk_strg, sizeof(wk_strg), "%d", x96);
    strcat(a_string, wk_strg);
    strcat(a_string, "(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #666");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    strcat(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #667");
      trace_rec_3();
    }

      convert = 1;
      return;
    }

    if((y4 == 0) && (y3 == 2) && (y5 == 2))   /* else if(fp[ii][0] == '\0') */
    {
      pi = 0;
      ch = p_string[pi];
      while (ch != '(') 
      {
        pi++;
        ch = p_string[pi];
      }

      pi2 = 0;
      x3 = 0;
      pi++;
      ch = p_string[pi];
      while (ch != '[') 
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
          strcpy(ar_field5, gw_variable[I].gv_dsect);
          strcpy(ar_field6, gw_variable[I].gv_label);
          strcpy(ar_field7, gw_variable[I].gv_table);
          strcpy(ar_field8, gw_variable[I].gv_aname);
          strcpy(ar_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar_field11, gw_variable[I].gv_wk_strg);
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_11 complex == 0 if-0154 field1 Not Found = %s\n",field1);
      printf("c2z_if.c if_case_11 complex == 0 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          x2 = 1;
        }
      }
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

/*
printf("c2z_if.c case_11 rct = %d field2 = %s\n",rct,field2);
printf("c2z_if.c case_11 complex = 0 HERE #2 rct = %d field2 = %s x2 = %d p_string = %s\n",rct,field2,x2,p_string);
*/

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("c2z_if.c nif_case_11 complex == 0 if-069 field2 Not Found = %s\n",field2);
      printf("c2z_if.c if_case_11 complex == 0 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    pi2 = 0;
    x2 = 0;
    pi++;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd3_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          fd3_type = 2;
          x2 = 1;
        }
      }
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';
/* printf("c2z_if.c case_11 complex = 0 rct = %d field3 = %s fd3_type = %d p_string = %s\n",rct,field3,fd3_type,p_string); */

    if (fd3_type == 1) 			/* character field value	*/
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field3, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field3a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_11 complex == 0 id-070 field3 Not Found = %s\n",field3);
        printf("c2z_if.c if_case_11 complex == 0 rct = %d p_string = %s", rct,p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(ar_field11, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(ar_field11a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(ar_field11, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(ar_field11a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_11 complex == 0 if-071 field11 Not Found = %s\n",field11);
      printf("c2z_if.c if_case_11 complex == 0 rct = %d p_string = %s", rct,p_string);
      erct++;
      convert = 1;
      return;
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      field4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field4[pi2] = '\0';

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(field4, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field4, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    ch = p_string[pi];
    while (ch != '\'') 
    {
      pi++;
      ch = p_string[pi];
    }

    ch = p_string[pi];
    while (ch != ')') 
    {
      pi++;
      ch = p_string[pi];
    }

    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 complex = 0");
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "M");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #1");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #5");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "T");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #7");
      trace_rec_3();
    }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field2, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #8");
      trace_rec_3();
    }


    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #9");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #11");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #12");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #13");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "T");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #14");
      trace_rec_3();
    }


    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "U");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #15");
      trace_rec_3();
    }


/*
3  46     c2z_macro.c c2_free array-char                                  free(in_stack)
3  46     c2z_free.c c2_free array_char #1FR4      DS    0H                                                       0000219
3  46     c2z_free.c c2_free array_char #3         LARL  R6,A374T                           0000220
3  46     c2z_free.c c2_free array_char #4         LA    R5,100                                                   0000221
3  46     c2z_free.c c2_free array_char #5FR4L     DS    0H                                                       0000222
3  46     c2z_free.c c2_free array_char #6         LARL  R9,C370B1                                                0000223
3  46     c2z_free.c c2_free array_char #7         MVC   0(1,R6),0(R9)                                            0000224
3  46     c2z_free.c c2_free array_char #8         MVC   1(31,R6),0(R6)                                           0000225
3  46     c2z_free.c c2_free array_char #9         LARL  R8,C370EOF                                               0000226
3  46     c2z_free.c c2_free array_char #10         MVC   0(1,R6),0(R8)                                            0000227
3  46     c2z_free.c c2_free array_char #11         LA    R6,A374L(R0,R6)                                          0000228
3  46     c2z_free.c c2_free array_char #12         JCT   R5,FR4L                                                  0000229
*/


    strcpy(a_string, "         LARL  R9,C370B1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #16");
      trace_rec_3();
    }
    work_use_ct[52]++;

    strcpy(a_string, "         CLC   0(1,R6),0(R9)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #17");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #18");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #19");
      trace_rec_3();
    }

    if (operand_1 == 2) 		/* !=	*/
    {
      printf("\nc2z_if.c if_case_11 if-072 operand_1 == 2 Not Coded\n");
      printf("c2z_if.c if_cass_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 3) 		/* <=	*/
    {
      printf("\nc2z_if.c if_case_11 if-073 operand_1 == 3 Not Coded\n");
      printf("c2z_if.c if_cass_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 4) 		/* >=	*/
    {
      printf("\nc2z_if.c if_case_11 if-074 operand_1 == 4 Not Coded\n");
      printf("c2z_if.c if_cass_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 5) 		/* =	*/
    {
      printf("\nc2z_if.c if_case_11 if-075 operand_1 == 5 Not Coded\n");
      printf("c2z_if.c if_cass_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 6)		 /* <	*/
    {
      printf("\nc2z_if.c if_case_11 if-076 operand_1 == 6 Not Coded\n");
      printf("c2z_if.c if_cass_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 7) 		/* >	*/
    {
      printf("\nc2z_if.c if_case_11 if-077 operand_1 == 7 Not Coded\n");
      printf("c2z_if.c if_cass_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "E");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #20");
      trace_rec_3();
    }
   }
  }

  if (if_complex == 1) 
  {
    printf("c2z_if.c if_case_11 if-078 while_complex == 1 NOT Coded\n");
    printf("c2z_fi.c if_case_11 rct = %d p_string = %s", rct, p_string);
  }

  if (if_complex == 2) 
  {
    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    x2 = 0;
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd4_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          fd4_type = 2;
          x2 = 1;
        }
      }
      tfield4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      pi2++;
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      pi2++;
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      tfield7[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield7[pi2] = '\0';
/* printf("c2z_if.c if_case_11 #00 rct = %d pi = %d tfield7 = %s\n",rct,pi,tfield7); */

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      tfield8[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield8[pi2] = '\0';

    x2 = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (ch != ' ') 
      {
        if (x2 == 0)
        {
          if (isalpha(ch)) 
          {
            fd9_type = 1;
            x2 = 1;
          }

          if (isdigit(ch)) 
          {
            fd9_type = 2;
            x2 = 1;
          }
        }
      }
      tfield9[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield9[pi2] = '\0';

    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      ret1 = strcmp("G", gw_variable[I].gv_type);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field1a, gw_variable[I].gv_cname);
        strcpy(ar_field5, gw_variable[I].gv_dsect);
        strcpy(ar_field6, gw_variable[I].gv_label);
        strcpy(ar_field7, gw_variable[I].gv_table);
        strcpy(ar_field8, gw_variable[I].gv_aname);
        strcpy(ar_field9, gw_variable[I].gv_sv_reg);
        strcpy(ar_field10, gw_variable[I].gv_wk_reg);
        strcpy(ar_field11, gw_variable[I].gv_wk_strg);
        gw_variable[I].gv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_11 if-079 tfield1 Not Found = %s\n", tfield1);
      printf("c2z_if.c if_case_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #1");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #2");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #4");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(start_while, a_string);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #6");
      trace_rec_3();
    }
    work_use_ct[49]++;

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_11 if-080 tfield2 Not Found = %s\n", tfield2);
      printf("c2z_if.c if_case_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, tfield2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #7");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "F");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #10");
      trace_rec_3();
    }
    work_use_ct[49]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #11");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #12");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #13");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1)
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #14");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(start_while, a_string);
    strcat(a_string, "F");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #15");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #16");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #17");
      trace_rec_3();
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    if (operand_1 == 1) 				/* ==	*/
    {
      if (if_complex == 1) 
      {
        printf("\nc2z_if.c if_case_11 if-081 operand == 1 & if_complex == 1 NOT CODED\n");
        printf("c2z_if.c if_case_11 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (if_complex == 2) 
      {
        if (fd4_type == 1) 
        {
          printf("\nc2z_if.c if_case_11 if-082 if_complex == 2 operand_1 == 1 fd4_type == 1 NOT CODED\n");
          printf("c2z_if.c if_case_11 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        if (fd4_type == 2) 
        {
          strcpy(a_string, "         LA    R5,");
          strcat(a_string, tfield4);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #100");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #101");
            trace_rec_3();
          }
  
          strcpy(a_string, "         CVD   R5,0(R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #102");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R8,C370NWK2");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #103");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #104");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #105");
            trace_rec_3();
          }

          strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #106");
            trace_rec_3();
          }
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "T");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_11 #107");
          trace_rec_3();
        }
      }
    }

    if (operand_1 == 2) 				/* !=	*/
    {
      printf("/nc2z_if.c if_case_11 if-083 operand_1 == 2 Not Coded\n");
      printf("c2z_if.c if_cass_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 3) 				/* <=	*/
    {
      printf("\nc2z_if.c if_case_11 if-084 operand_1 == 3 Not Coded\n");
      printf("c2z_if.c if_cass_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 4) 				/* >=	*/
    {
      printf("\nc2z_if.c if_case_11 if-085 operand_1 == 4 Not Coded\n");
      printf("c2z_if.c if_cass_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 5) 				/* =	*/
    {
      printf("\nc2z_if.c if_case_11 if-086 operand_1 == 5 Not Coded\n");
      printf("c2z_if.c if_cass_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 6) 				/* <	*/
    {
      printf("\nc2z_if.c if_case_11 if-087 operand_1 == 6 Not Coded\n");
      printf("c2z_if.c if_cass_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 7) 				/* >	*/
    {
      printf("\nc2z_if.c if_case_11 if-088 operand_1 == 7 Not Coded\n");
      printf("c2z_if.c if_cass_11 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    operand_2 = 0;
    if (operand_2 == 0) 
    {
      p = strstr(tfield8, "==");
      if (p)
      {
        operand_2 = 1;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield8, "!=");
      if (p)
      {
        operand_2 = 2;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield8, "<=");
      if (p)
      {
        operand_2 = 3;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield8, ">=");
      if (p)
      {
        operand_2 = 4;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield8, "=");
      if (p)
      {
        operand_2 = 5;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield8, "<");
      if (p)
      {
        operand_2 = 6;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield8, ">");
      if (p)
      {
        operand_2 = 7;
      }
    }

    if (operand_2 == 1) 				/* ==	*/
    {
      if (if_complex == 1) 
      {
        printf("\nc2z_if.c if_case_11 if-089 operand_2 == 1 & if_complex == 1 NOT CODED\n");
        printf("c2z_if.c if_case_11 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (if_complex == 2) 
      {
        if (fd9_type == 1) 
        {
          printf("\nc2z_if.c if_case_11 if-090 if_complex == 2 operand_1 == 1 fd4_type == 1 NOT CODED\n");
          printf("c2z_if.c if_case_11 rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        if (fd9_type == 2) 
        {
          if (fd9_type == 1) 
          {
            printf("\nc2z_if.c if_case_11 if-091 fd9_type == 1 NOT CODED\n");
            printf("c2z_if.c if_case_11 rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }
        }

        if (fd9_type == 2) 
        {
          strcpy(a_string, "         LA    R5,");
          strcat(a_string, tfield9);
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #108");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #109");
            trace_rec_3();
          }
  
          strcpy(a_string, "         CVD   R5,0(R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #110");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R8,C370NWK2");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #111");
            trace_rec_3();
          }

          strcpy(a_string, "         LARL  R7,C370U");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #112");
            trace_rec_3();
          }

          strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_11 #113");
            trace_rec_3();
          }
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_11 #115");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        strcat(a_string, "T");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_11 #116");
          trace_rec_3();
        }

        strcpy(a_string, "         JLU   L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_11 #117");
          trace_rec_3();
        }
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(start_while, a_string);
    strcat(a_string, "T");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_11 #118");
      trace_rec_3();
    }
  }
  convert = 1;
  return;
}

/* ***************************************************
*  Punch out if(isaddop(ch) user function            *
* ************************************************** */
void if_case_12() 				/*	if(isaddop(ch)) 	*/
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_12");
    trace_rec_1();
  }

  int pi;
  int pi2;
  int I = 0;
  int x3 = 0;
  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
  int fd3_type = 0;

  char ch;
  char wk_sv_func[VAR_LGTH];
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4a[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != '(') 
  {
    tfield1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';
  strcpy(wk_sv_func, tfield1);

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    tfield2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  tfield2[pi2] = '\0';

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield2a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_12 if-092 tfield2 Not Found = %s\n", tfield2);
    printf("c2z_if.c if_case_12 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  if (lv_ct > 0) 
  {
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield2, lw_variable[I].lv_name);
      ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield4a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    if (gv_ct > 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield2, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield4a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_12 if-093 tfield4a Not Found = %s\n", tfield4a);
    printf("c2z_if.c if_case_12 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield4a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_12 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, tfield2a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, tfield2);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_12 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         MVC   0(1,R9),0(R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_12 #3");
    trace_rec_3();
  }

  for (I = 0; I < fn_ct; I++) 
  {
    ret = strcmp(tfield1, w_function[I].fn_name);
    if (ret == 0) 
    {
      strcpy(tfield1a, w_function[I].fn_cname);
    }
  }

    strcpy(a_string, "         LARL  R15,");
    strcat(a_string, tfield1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_12 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_12 #5");
      trace_rec_3();
    }

  for (I = 0; I < fn_ct; I++) 
  {
    ret = strcmp(tfield1, w_function[I].fn_name);
    if (ret == 0) 
    {
      strcpy(tfield3, w_function[I].fn_ret_var);
      strcpy(wk_sv_func, tfield1);
    }
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield3, lw_variable[I].lv_name);
    ret1 = strcmp(wk_sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(tfield3a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
      ret2 = strcmp("I", lw_variable[I].lv_type);
      if (ret2 == 0) 
      {
        fd3_type = 1;
      }
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield3a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_12 if-094 tfield3 Not Found = %s\n", tfield3);
    printf("c2z_if.c if_case_12 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (fd3_type == 1) 				/* integer variable		*/
  {
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, tfield3a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, tfield3);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_12 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_12 #7");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_12 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         JNE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_12 #9");
      trace_rec_3();
    }
  }

  if (fd3_type == 2) /* character variable	*/
  {
    printf("\nc2z_if.c if_case_12 if-095 Character variable NOT CODED\n");
    printf("c2z_if.c if_case_12 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }
}


void if_case_13() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_13 START");
    trace_rec_1();
  }

  char *p;
  char ch;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];
  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];
  char tfield3[VAR_LGTH];
  char tfield3a[VAR_LGTH];
  char tfield4[VAR_LGTH];
  char tfield4a[VAR_LGTH];
  char tfield5[VAR_LGTH];
  char tfield5a[VAR_LGTH];
  char tfield6[VAR_LGTH];
  char tfield6a[VAR_LGTH];
  char tfield7[VAR_LGTH];
  char tfield7a[VAR_LGTH];

  char ar_field5[VAR_LGTH];
  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];

  int fd1_type = 0;
  int fd2_type = 0;
  int fd3_type = 0;
  int fd4_type = 0;
  int fd5_type = 0;
  int fd6_type = 0;
  int fd7_type = 0;

  int I;
  int s;
  int pi = 0;
  int pi2 = 0;
  int x2 = 0;
  int x3 = 0;
  int x20 = 0;
  int x22 = 0;
  int x33 = 0;
  int x80 = 0;
  int x81 = 0;
  int ret = 0;
  int ret1 = 0;
  int ret2 = 0;
  int operand_1 = 0;
  int operand_2 = 0;
  int neg_flg1 = 0;
  int neg_flg2 = 0;
  int eol_1 = 0;
  int eol_2 = 0;

  s = strlen(p_string);
  for (I = 0; I < s; I++) 
  {
    ch = p_string[I];
    if (ch == '[') 
    {
      x80 = I;
    }

    if (ch == '&') 
    {
      x81 = I;
    }

    if (ch == '|') 
    {
      x81 = I;
    }
  }

  if (x80 == 0) 
  {
    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    eol_1 = 0;
    fd1_type = 0;
    x2 = 0;
    pi2 = 0;
    neg_flg1 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      if (ch == ')')
      {
        eol_1 = 1;
        break;
      }
      if(ch != '!')
      {
        if (x2 == 0) 
        {
          if (isalpha(ch)) 
          {
            fd1_type = 1;
            x2 = 1;
          }
          if (isdigit(ch)) 
          {
            fd1_type = 2;
            x2 = 1;
          }
        }
      }
      if(ch == '!')
      {
        neg_flg1 = 1;
      }
      if(ch != '!')
      {
        tfield1[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

    if(eol_1 == 1)
    {
      goto skip_if_4;
    }

    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

    fd3_type = 0;
    x2 = 0;
    pi++;
    pi2 = 0;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if(ch == '\\')
      {
        goto loop109;
      }
      if (ch == '\'') 
      {
        fd3_type = 3;
        x2 = 1;
        goto loop109;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd3_type = 1;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd3_type = 2;
          x2 = 1;
        }
      }
      tfield3[pi2] = ch;
      pi2++;
loop109:
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

   if (fd3_type == 3) 
   {
      for (I = 0; I < char_ct; I++) 
      {
        if ((w_charlit[I].clit_rct == rct) && (w_charlit[I].clit_uct == 1)) 
        {
          strcpy(tfield3a, w_charlit[I].clit_cname);
          x33 = w_charlit[I].clit_lgth;
        }
      }
    }

skip_if_4:

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      if(ch != '\'')
      {
        if(ch != ')')
        {
          tfield4[pi2] = ch;
          pi2++;
        }
      }
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    eol_2 = 0;
    x2 = 0;
    pi2 = 0;
    fd5_type = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      if (ch == ')')
      { eol_2 = 1;
        break;
      }
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd5_type = 1;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd5_type = 2;
          x2 = 1;
        }
      }
      tfield5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield5[pi2] = '\0';

    if(eol_2 == 1)
    {
      goto skip_if_7;
    }

    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      tfield6[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield6[pi2] = '\0';

    fd7_type = 0;
    x2 = 0;
    pi2= 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
       if (x2 == 0) 
       {
        if (isalpha(ch)) 
        {
          fd7_type = 1;
          x2 = 1;
        }
        if (isdigit(ch)) 
        {
          fd7_type = 2;
          x2 = 1;
        }
      }
      if(ch != ' ')
      {
        tfield7[pi2] = ch;
        pi2++;
      }
      pi++;
      ch = p_string[pi];
    }
    tfield7[pi2] = '\0';

    p = strstr(tfield7, "'");
    if(p)
    {
      fd7_type = 3;
    }

skip_if_7:

    if(eol_1 == 0)
    {
      operand_1 = 0;
      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "==");
        if (p)
        {
          operand_1 = 1;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "!=");
        if (p)
        {
          operand_1 = 2;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "<=");
        if (p)
        {
          operand_1 = 3;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, ">=");
        if (p)
        {
          operand_1 = 4;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "=");
        if (p)
        {
          operand_1 = 5;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, "<");
        if (p)
        {
          operand_1 = 6;
        }
      }

      if (operand_1 == 0) 
      {
        p = strstr(tfield2, ">");
        if (p)
        {
          operand_1 = 7;
        }
      }
    }

    if(eol_2 == 0)
    {
      operand_2 = 0;
      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "==");
        if (p)
        {
          operand_2 = 1;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "!=");
        if (p)
        {
          operand_2 = 2;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "<");
        if (p)
        {
          operand_2 = 6;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, ">");
        if (p)
        {
          operand_2 = 7;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "<=");
        if (p)
        {
          operand_2 = 3;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, ">=");
        if (p)
        {
          operand_2 = 4;
        }
      }

      if (operand_2 == 0) 
      {
        p = strstr(tfield6, "=");
        if (p)
        {
          operand_2 = 5;
        }
      }
    }

    if(fd1_type == 1)
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-096 x80 tfield1 Not Found = %s\n", tfield1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if((eol_1 == 1) && (fd1_type == 1))
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #N200");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #N201");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #N202");
        trace_rec_3();
      }

      if(neg_flg1 == 0)
      {
        strcpy(a_string, "         JLNE  L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #N203");
          trace_rec_3();
        }
      }
      else
      {
        strcpy(a_string, "         JLE  L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #N204");
          trace_rec_3();
        }
      }
    }

    if((eol_2 == 1) && (fd5_type == 1))
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield5, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield5a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield5, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield5a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-097 tfield5 Not Found = %s\n", tfield5);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #N205");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #N205");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #N206");
        trace_rec_3();
      }

      if(neg_flg2 == 0)
      {
        strcpy(a_string, "         JLNE  L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #N207");
          trace_rec_3();
        }
      }
      else
      {
        strcpy(a_string, "         JLE  L");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #N208");
          trace_rec_3();
        }
      }
    }

    if ((fd1_type == 1) && (fd3_type == 3) && (fd5_type == 1) && (fd7_type == 3))  /* if((ch == '+') || (ch == '-')) */
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #700");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #701");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", x33);
      strcpy(a_string, "         CLC   0(");
      strcat(a_string, wk_strg);
      strcat(a_string, ",R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #702");
        trace_rec_3();
      }

      if (operand_1 == 1) 				/*  == */
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "B");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #703");
          trace_rec_3();
        }
      }

      if (operand_1 == 2) 				/*  != */
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #704");
          trace_rec_3();
        }
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield5, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield5a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield5, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield5a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-097 tfield5 Not Found = %s\n", tfield5);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield5a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #705");
        trace_rec_3();
      }

      for (I = 0; I < char_ct; I++) 
      {
        if ((w_charlit[I].clit_rct == rct) && (w_charlit[I].clit_uct == 2)) 
        {
          strcpy(tfield7a, w_charlit[I].clit_cname);
          x33 = w_charlit[I].clit_lgth;
        }
      }
   
      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield7a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #706");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", x33);
      strcpy(a_string, "         CLC   0(");
      strcat(a_string, wk_strg);
      strcat(a_string, ",R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #707");
        trace_rec_3();
      }

      if (operand_2 == 1) 				/*  == */
      {
        strcpy(a_string, "         JLNE  ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #708");
          trace_rec_3();
        }
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "B");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #709");
        trace_rec_3();
      }

      convert = 1;
      return;
    }


 
    if ((fd1_type == 1) && (fd3_type == 3) && (fd5_type == 1) && (fd7_type == 1)) 	 /* if((ch != '\"') || (pi == stlen)) */
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #710");
        trace_rec_3();
      }

      for (I = 0; I < char_ct; I++) 
      {
        if ((w_charlit[I].clit_rct == rct) && (w_charlit[I].clit_uct == 1)) 
        {
          strcpy(tfield3a, w_charlit[I].clit_cname);
          x33 = w_charlit[I].clit_lgth;
        }
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #711");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", x33);
      strcpy(a_string, "         CLC   0(");
      strcat(a_string, wk_strg);
      strcat(a_string, ",R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #712");
        trace_rec_3();
      }

      if (operand_1 == 1) 				/*  == */
      {
        strcpy(a_string, "         JLNE  ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #713");
          trace_rec_3();
        }
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield5, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield5a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield5, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield5a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-098 tfield5 Not Found = %s\n", tfield5);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #714");
        trace_rec_3();
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield7, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield7a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield7, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield7a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-099 tfield7 Not Found = %s\n", tfield7);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield7a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield7);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #715");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #716");
        trace_rec_3();
      }

      if (operand_2 == 1) 				/*  == */
      {
        strcpy(a_string, "         JLNE  ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #717");
          trace_rec_3();
        }
      }

      if (operand_2 == 6) 			/*  < */
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #717");
          trace_rec_3();
        }

        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #717");
          trace_rec_3();
        }
      }

      convert = 1;
     
    }

    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(tfield5, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(tfield5a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(tfield5, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(tfield5a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_13 if-100 x80 tfield5 Not Found = %s\n", tfield5);
      printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    p = strstr(tfield7, "'");
    if(p)
    {
      fd7_type = 3;
     
      for (I = 0; I < char_ct; I++) 
      {
        if ((w_charlit[I].clit_rct == rct) && (w_charlit[I].clit_uct == 2)) 
        {
          strcpy(tfield7a, w_charlit[I].clit_cname);
        }
      }
    }

    if(fd7_type == 1)
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield7, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield7a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield7, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield7a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-101 x80 tfield7 Not Found = %s\n", tfield7);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }


    if ((fd5_type == 1) && (fd7_type == 2) && (fd1_type != 1) && (fd3_type != 2))
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #730");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield7);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield7);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #731");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #732");
        trace_rec_3();
      }
  
      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #733");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #734");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #735");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #736");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #737");
        trace_rec_3();
      }
     
      if (operand_2 == 1) 
      {
        strcpy(a_string, "         JLNE  ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #738");
          trace_rec_3();
        }
      }

      if (operand_2 == 2) 
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #739");
          trace_rec_3();
        }
      }

      if (operand_2 == 3) 
      {
        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #740");
          trace_rec_3();
        }
      }

      if (operand_2 == 4) 
      {
        printf("\nc2z_if.c if_case_13 if-102 operand (4) NOT CODED operand_1 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 5) 
      {
        printf("\nc2z_if.c if_case_13 if-103 operand (5) NOT CODED operand_1 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 6) 
      {
        strcpy(a_string, "*         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #741");
          trace_rec_3();
        }

        strcpy(a_string, "*         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #742");
          trace_rec_3();
        }
      }

      if (operand_2 == 7) 
      {

        strcpy(a_string, "*         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #742");
          trace_rec_3();
        }

        strcpy(a_string, "*         JLL   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #741");
          trace_rec_3();
        }
      }

      convert = 1;
      return;
    }

    if ((fd1_type == 1) && (fd3_type == 0) && (fd4_type == 1) && (fd6_type == 1) && (convert == 0)) 
    {
      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #743");
        trace_rec_3();
      }

      if (fd3_type == 0) 
      {
        for (I = 0; I < char_ct; I++) 
        {
          if (w_charlit[I].clit_rct == rct) 
          {
            strcpy(tfield3a, w_charlit[I].clit_cname);
            x3 = w_charlit[I].clit_lgth;
          }
        }
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #744");
        trace_rec_3();
      }

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #745");
        trace_rec_3();
      }

      if (operand_1 == 1) 
      {
        strcpy(a_string, "         JLNE  ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #746");
          trace_rec_3();
        }
      }

      if (operand_1 == 2) 
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #747");
          trace_rec_3();
        }
      }

      if (operand_1 == 3) 
      {
        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #748");
          trace_rec_3();
        }
      }

      if (operand_1 == 4) 
      {
        printf("\nc2z_if.c if_case_13 if-105 operand (4) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 5) 
      {
        printf("\nc2z_if.c if_case_13 if-106 operand (5) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 6) 
      {
        printf("\nc2z_if.c if_case_13 if-107 operand (6) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 7) 
      {
        printf("\nc2z_if.c if_case_13 if-108 operand (7) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield4, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield4a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x20 = 1;
          }
          ret2 = strcmp("C", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x20 = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield4, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield4a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x20 = 1;
            }
            ret2 = strcmp("C", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x20 = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-109 x80 E-384 tfield4 Not Found = %s\n",tfield4);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield6, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield6a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x22 = 1;
          }
          ret2 = strcmp("C", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x22 = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield6, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x22 = 1;
            }
            ret2 = strcmp("C", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x22 = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-110 x80 E-385 tfield6 Not Found = %s\n",tfield6);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield4a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #749");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield6a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #750");
        trace_rec_3();
      }

      if ((x20 == 1) && (x22 == 1)) 
      {
        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #751");
          trace_rec_3();
        }
      }

      if ((x20 == 2) && (x22 == 2)) 
      {
        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #752");
          trace_rec_3();
        }
      }

      if (operand_2 == 1) 
      {
        strcpy(a_string, "         JLNE  ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #753");
          trace_rec_3();
        }
      }

      if (operand_2 == 2) 
      {
        printf("\nc2z_if.c if_case_13 if-111 operand (2) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 3) 
      {
        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #754");
          trace_rec_3();
        }
      }

      if (operand_2 == 4) 
      {
        printf("\nc2z_if.c if_case_13 if-112 operand(4)  NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 5) 
      {
        printf("\nc2z_if.c if_case_13 if-113 operand (5) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 6) 
      {
        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #755");
          trace_rec_3();
        }
      }

      if (operand_2 == 7) 
      {
        printf("\nc2z_if.c if_case_13 if-114 operand (7) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    if ((fd1_type == 1) && (fd3_type == 2) && (fd5_type == 1) && (fd7_type == 1)) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-115 x80 tfield1 Not Found = %s\n",tfield1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #756");
        trace_rec_3();
      }

      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, tfield3);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #757");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #758");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #759");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #760");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R7,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #761");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #762");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #763");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #764");
        trace_rec_3();
      }

      if (operand_1 == 1) 
      {
        printf("\nc2z_if.c if_case_13 if-116 operand (1) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 2) 
      {
        printf("\nc2z_if.c if_case_13 if-117 operand (2) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 3) 
      {
        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #765");
          trace_rec_3();
        }
      }

      if (operand_1 == 4) 
      {
        printf("\nc2z_if.c if_case_13 if-118 operand (4) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 5) 
      {
        printf("\nc2z_if.c if_case_13 if-119 operand (5) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 6) 
      {
        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #766");
          trace_rec_3();
        }
      }

      if (operand_1 == 7) 
      {
        strcpy(a_string, "         JLL   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #767");
          trace_rec_3();
        }
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield5, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield5a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x20 = 1;
          }
          ret2 = strcmp("C", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x20 = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield5, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield5a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x20 = 1;
            }
            ret2 = strcmp("C", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x20 = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-120 x80 E-396 tfield5 Not Found = %s\n",tfield5);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield7, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield7a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x22 = 1;
          }
          ret2 = strcmp("C", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x22 = 2;
          }
          break;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield7, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield7a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x22 = 1;
            }
            ret2 = strcmp("C", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x22 = 2;
            }
            break;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-121 E-397 tfield7 Not Found = %s\n",tfield7);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #768");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield7a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield7);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #769");
        trace_rec_3();
      }

      if ((x20 == 1) && (x22 == 1)) 
      {
        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #770");
          trace_rec_3();
        }
      }

      if (operand_2 == 1) 
      {
        printf("\nc2z_if.c if_case_13 if-122 operand (1) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 2) 
      {
        printf("\nc2z_if.c if_case_13 if-123 operand (2) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 3) 
      {
        printf("\nc2z_if.c if_case_13 if-124 operand (3) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 4) 
      {
        printf("\nc2z_if.c if_case_13 if-125 operand (4) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 5) 
      {
        printf("\nc2z_if.c if_case_13 if-126 operand (5) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
      }

      if (operand_2 == 6) 
      {
        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #771");
          trace_rec_3();
        }
      }

      if (operand_2 == 7) 
      {
        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #772");
          trace_rec_3();
        }
      }
    }



    if ((fd1_type == 1) && (fd3_type == 0) && (fd4_type == 1) && (fd6_type == 0) && (convert == 0)) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-127 E-404 tfield1 Not Found = %s\n",tfield1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (fd3_type == 0) 
      {
        for (I = 0; I < char_ct; I++) 
        {
          if (w_charlit[I].clit_rct == rct) 
          {
            strcpy(tfield3a, w_charlit[I].clit_cname);
            x3 = w_charlit[I].clit_lgth;
          }
        }
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #773");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #774");
        trace_rec_3();
      }

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #775");
        trace_rec_3();
      }

      if (operand_1 == 1) 
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "C");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #776");
          trace_rec_3();
        }
      }

      if (operand_1 == 2) 
      {
        printf("\nc2z_if.c if_case_13 if-128 operand (2) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 3) 
      {
        printf("\nc2z_if.c if_case_13 if-129 operand (3) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 4) 
      {
        printf("\nc2z_if.c if_case_13 if-130 operand (4) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 5) 
      {
        printf("\nc2z_if.c if_case_13 if-131 operand (5) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 6) 
      {
        printf("\nc2z_if.c if_case_13 if-132 operand (6) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 7) 
      {
        printf("\nc2z_if.c if_case_13 if-133 operand (7) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield4, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield4a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield4, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield4a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-134 x80 if-173 tfield4 Not Found = %s\n",tfield4);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield4a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #777");
        trace_rec_3();
      }

      if (fd6_type == 0) 
      {
        for (I = 0; I < char_ct; I++) 
        {
          if ((w_charlit[I].clit_rct == rct) && (w_charlit[I].clit_uct == 2)) 
          {
            strcpy(tfield6a, w_charlit[I].clit_cname);
          }
        }
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield6a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #778");
        trace_rec_3();
      }

      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #779");
        trace_rec_3();
      }

      if (operand_2 == 1) 
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "C");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #780");
          trace_rec_3();
        }
      }

      if (operand_2 == 2) 
      {
        printf("\nc2z_if.c if_case_13 if-135 operand (2) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 3) 
      {
        printf("\nc2z_if.c if_case_13 if-136 operand (3) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 4) 
      {
        printf("\nc2z_if.c if_case_13 if-137 operand (4) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 5) 
      {
        printf("\nc2z_if.c if_case_13 if-138 operand (5) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 6) 
      {
        printf("\nc2z_if.c if_case_13 if-139 operand (6) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 7) 
      {
        printf("\nc2z_if.c if_case_13 if-140 operand (7) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         JLNE  ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #781");
        trace_rec_3();
      }

      strcpy(a_string, "L");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "C");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #782");
        trace_rec_3();
      }
    }


    if ((fd1_type == 1) && (fd3_type == 1) && (fd5_type == 1) && (fd7_type == 1) && (convert == 0))
    {
      x20 = 0;
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x20 = 1;
            break;
          }
          ret2 = strcmp("C", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x20 = 2;
            break;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x20 = 1;
            }
            ret2 = strcmp("C", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x20 = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-141 x80 tfield1 Not Found = %s\n",tfield1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x22 = 0;
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x22 = 1;
          }
          ret2 = strcmp("C", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x22 = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield3, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield3a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x22 = 1;
            }
            ret2 = strcmp("C", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x22 = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-142 x80 tfield1 Not Found = %s\n",tfield1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield1a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield1);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #783");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield3a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield3);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #784");
        trace_rec_3();
      }

      
      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #785");
        trace_rec_3();
      }

      if ((x20 == 2) && (x22 == 2)) 
      {
        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #786");
          trace_rec_3();
        }
      }

      if (operand_1 == 1) 
      {
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "A");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #787");
          trace_rec_3();
        }
      }

      if (operand_1 == 2) 
      {
        printf("c2z_if.c if_case_13 if-143 operand (2) NOT CODED operand_1 = %d\n",operand_1);
        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #787");
          trace_rec_3();
        }
      }

      if (operand_1 == 3) 
      {
        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #788");
          trace_rec_3();
        }
      }

      if (operand_1 == 4) 
      {
        printf("\nc2z_if.c if_case_13 if-144 operand (4) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 5) 
      {
        printf("\nc2z_if.c if_case_13 if-145 operand (5) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 6) 
      {
        printf("\nc2z_if.c if_case_13 if-146 operand (6) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 7) 
      {
        strcpy(a_string, "         JLL   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #789");
          trace_rec_3();
        }
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield5, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield5a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x20 = 1;
          }
          ret2 = strcmp("C", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x20 = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield5, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield5a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x20 = 1;
            }
            ret2 = strcmp("C", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x20 = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-147 x80 E-396 tfield5 Not Found = %s\n",tfield5);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield7, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield7a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
          ret2 = strcmp("I", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x22 = 1;
          }
          ret2 = strcmp("C", lw_variable[I].lv_type);
          if (ret2 == 0) 
          {
            x22 = 2;
          }
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield7, gw_variable[I].gv_name);
          if (ret == 0) {
            x3 = 1;
            strcpy(tfield7a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            ret2 = strcmp("I", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x22 = 1;
            }
            ret2 = strcmp("C", gw_variable[I].gv_type);
            if (ret2 == 0) 
            {
              x22 = 2;
            }
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-148 x80 tfield7 Not Found = %s\n",tfield7);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield5a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield5);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #790");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield7a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, tfield7);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #791");
        trace_rec_3();
      }

      if ((x20 == 1) && (x22 == 1)) 
      {
        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #792");
          trace_rec_3();
        }
      }

      if (operand_2 == 1) 
      {
        strcpy(a_string, "         JLNE  ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #793");
          trace_rec_3();
        }
      }

      if (operand_2 == 2) 
      {
        printf("\nc2z_if.c if_case_13 if-149 operand (2) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 3) 
      {
        printf("\nc2z_if.c if_case_13 if-150 operand (3) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 4) 
      {
        printf("\nc2z_if.c if_case_13 if-151 operand (4) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 5) 
      {
        printf("\nc2z_if.c if_case_13 if-152 operand (5) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 6) 
      {
        strcpy(a_string, "         JLH   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #794");
          trace_rec_3();
        }
      }

      if (operand_2 == 7) 
      {
        strcpy(a_string, "         JLL   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_13 #795");
          trace_rec_3();
        }
      }
   
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_13 #796");
        trace_rec_3();
      }
      convert = 1;
      return; 
    }
 

    if((fd1_type == 1) && (fd3_type == 2) && (fd5_type == 1) && (fd7_type == 2))
    {
      if (traceflg == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 1 & 1 & 1 & 1");
        trace_rec_1();
      }
      if(fd1_type == 1)
      {
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcpy(o_string, a_string);

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #900");
          trace_rec_3();
        }
      }

      if(fd1_type == 2)
      {
printf("c2z_if.c if_case_13 #900 fd1_type == 2 NOT CODED\n");
      }

      if(fd3_type == 1)
      {
printf("c2z_if.c if_case_13 #900 fd3_type == 1 NOT CODED\n");
      }
  
      if(fd3_type == 2)
      {
        strcpy(a_string, "         LAEY  R5,");
        strcat(a_string, tfield3);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield3);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #901");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #902");
          trace_rec_3();
        }

        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #903");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #904");
          trace_rec_3();
        }
        work_use_ct[50]++;

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #905");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #906");
          trace_rec_3();
        }
      }

      if(operand_1 == 1)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #907");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #908");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #909");
          trace_rec_3();
        }

        strcpy(a_string, "         JLNE  ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "A");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #910");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   ");
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcat(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "B");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #910B");
          trace_rec_3();
        }
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #910A");
        trace_rec_3();
      }


      if (operand_1 == 2) 
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield1a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield1);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #911");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #912");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #913");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, o_string);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #914");
          trace_rec_3();
        }
      }

      if (operand_1 == 3) 
      {
        printf("\nc2z_if.c if_case_13 if-950 operand (3) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 4) 
      {
        printf("\nc2z_if.c if_case_13 if-951 operand (4) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 5) 
      {
        printf("\nc2z_if.c if_case_13 if-952 operand (5) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 6) 
      {
        printf("\nc2z_if.c if_case_13 if-953 operand (6) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_1 == 7) 
      {
        printf("\nc2z_if.c if_case_13 if-954 operand (7) NOT CODED operand_1 = %d\n",operand_1);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if(fd5_type == 1)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield5a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield5);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #915");
          trace_rec_3();
        }
      }

      if(fd5_type == 2)
      {
printf("c2z_if.c if_case_13 #900 fd5_type == 2 NOT CODED\n");
      }

      if(fd7_type == 1)
      {
printf("c2z_if.c if_case_13 #900 fd7_type == 1 NOT CODED\n");
      }
  
      if(fd7_type == 2)
      {
        strcpy(a_string, "         LAEY  R5,");
        strcat(a_string, tfield7);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield7);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #916");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #917");
          trace_rec_3();
        }

        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #918");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #919");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #920");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #921");
          trace_rec_3();
        }
      }

      if (operand_2 == 1) 
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield5a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield5);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #922");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #923");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #924");
          trace_rec_3();
        }

        strcpy(a_string, "         JLNE  ");
        strcat(a_string, o_string);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #925");
          trace_rec_3();
        }
        snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
        strcpy(a_string, "L");
        strcat(a_string, wk_strg);
        strcat(a_string, "B");
        check_length();
        strcat(a_string, "DS    0H");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #925A");
          trace_rec_3();
        }
      }

      if(operand_2 == 2)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, tfield5a);
        strcpy(wk_remark, " ");
        strcat(wk_remark, tfield5);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #926");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #927");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #928");
          trace_rec_3();
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, o_string);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #929");
          trace_rec_3();
        }
      }

      if (operand_2 == 3) 
      {
        printf("\nc2z_if.c if_case_13 if-980 operand (3) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 4) 
      {
        printf("\nc2z_if.c if_case_13 if-981 operand (4) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 5) 
      {
        printf("\nc2z_if.c if_case_13 if-982 operand (5) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 6) 
      {
        printf("\nc2z_if.c if_case_13 if-983 operand (6) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      if (operand_2 == 7) 
      {
        printf("\nc2z_if.c if_case_13 if-984 operand (7) NOT CODED operand_2 = %d\n",operand_2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      convert = 1;
      return;
    }


  if ((x80 > 0) && (x80 < x81) && (convert == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_13 x81");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != '[') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd1_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          fd1_type = 2;
          x2 = 1;
        }
      }
      tfield1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield1[pi2] = '\0';

printf("c2z_if.c if_case_13 x81 rct = %d fd1_type = %d tfield1 = %s\n",rct,fd1_type,tfield1);

    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ']') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd2_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          fd2_type = 2;
          x2 = 1;
        }
      }
      tfield2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield2[pi2] = '\0';

printf("c2z_if.c if_case_13 x81 rct = %d fd2_type = %d tfield2 = %s\n",rct,fd2_type, tfield2);

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      tfield3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield3[pi2] = '\0';

printf("c2z_if.c if_case_13 x81 rct = %d tfield3 = %s\n",rct,tfield3);

    pi2 = 0;
    x2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd4_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          fd4_type = 2;
          x2 = 1;
        }
      }
      tfield4[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield4[pi2] = '\0';

printf("c2z_if.c if_case_13 x81 rct = %d fd4_type = %d tfield4 = %s\n",rct,fd4_type, tfield4);

    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd5_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          fd5_type = 2;
          x2 = 1;
        }
      }
      tfield5[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield5[pi2] = '\0';

printf("c2z_if.c if_case_13 x81 rct = %d fd5_type = %d tfield5 = %s\n",rct,fd5_type,tfield5);

    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      tfield6[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield6[pi2] = '\0';

printf("c2z_if.c if_case_13 x81 rct = %d tfield6 = %s\n",rct,tfield6);

    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd7_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          fd7_type = 2;
          x2 = 1;
        }
      }
      tfield7[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    tfield7[pi2] = '\0';

printf("c2z_if.c if_case_13 x81 rct = %d fd7_type = %d tfield7 = %s\n",rct,fd7_type, tfield7);

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(tfield3, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    operand_2 = 0;
    if (operand_2 == 0) 
    {
      p = strstr(tfield6, "==");
      if (p)
      {
        operand_2 = 1;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield6, "!=");
      if (p)
      {
        operand_2 = 2;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield6, "<=");
      if (p)
      {
        operand_2 = 3;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield6, ">=");
      if (p)
      {
        operand_2 = 4;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield6, "=");
      if (p)
      {
        operand_2 = 5;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield6, "<");
      if (p)
      {
        operand_2 = 6;
      }
    }

    if (operand_2 == 0) 
    {
      p = strstr(tfield6, ">");
      if (p)
      {
        operand_2 = 7;
      }
    }


    if ((fd1_type == 1) && (fd2_type == 1) && (fd4_type == 2) && (fd5_type == 1) && (fd7_type == 1)) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield1, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield1a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield1, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield1a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
            strcpy(ar_field5, gw_variable[I].gv_dsect);
            strcpy(ar_field6, gw_variable[I].gv_label);
            strcpy(ar_field7, gw_variable[I].gv_table);
            strcpy(ar_field8, gw_variable[I].gv_aname);
            strcpy(ar_field9, gw_variable[I].gv_sv_reg);
            strcpy(ar_field10, gw_variable[I].gv_wk_reg);
            strcpy(ar_field11, gw_variable[I].gv_wk_strg);
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-153 x81 tfield4 Not Found = %s\n",tfield4);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield2, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield2a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield2, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-154 x81 tfield2 Not Found = %s\n",tfield2);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }


      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield5, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield5a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield5, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield5a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-155 x81 tfield5 Not Found = %s\n",tfield5);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(tfield7, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(tfield7a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(tfield7, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(tfield7a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_13 if-156 x81 tfield7 Not Found = %s\n",tfield7);
        printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #797");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ZERO");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #798");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #799");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R6,");
      strcat(a_string, ar_field7);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #800");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #801");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #802");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield2a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #803");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #804");
        trace_rec_3();
      }

      strcpy(a_string, "         JLE   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "B");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #805");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #806");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370ONE");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #807");
        trace_rec_3();
      }

      strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #808");
        trace_rec_3();
      }

      strcpy(a_string, "         LA    R6,");
      strcat(a_string, ar_field6);
      strcat(a_string, "(R0,R6)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #809");
        trace_rec_3();
      }

      strcpy(a_string, "         JLU   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "A");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #810");
        trace_rec_3();
      }

      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcpy(a_string, "L");
      strcat(a_string, wk_strg);
      strcat(a_string, "B");
      check_length();
      strcat(a_string, "DS    0H");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #811");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,");
      strcat(a_string, tfield5a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #812");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,");
      strcat(a_string, tfield7a);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #814");
        trace_rec_3();
      }

      if(operand_2 == 6)
      {
        strcpy(a_string, "         CP    0(6,r9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_13 #815");
          trace_rec_3();
        }
      }

      strcpy(a_string, "         JLE   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #816");
        trace_rec_3();
      }

      strcpy(a_string, "         JLH   ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
      strcat(a_string, "L");
      strcat(a_string, wk_strg);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_13 #817");
        trace_rec_3();
      }
    }

    convert = 1;
    return;
  }
}
}

/* ***************************************************
*  if_case_22                                        *
* ************************************************** */
void if_case_22() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_22 START");
    trace_rec_1();
  }

  char ch;
  char *p, *p1;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];

  int pi;
  int pi2;
  int fd1_type = 0;
  int fd2_type = 0;
  int fd3_type = 0;
  int I = 0;
  int x2 = 0;
  int x3 = 0;
  int if_complex = 0;
  int if_math = 0;
  int operand_1 = 0;
  int ret = 0;
  int ret1 = 0;

  p = strstr(p_string, "&&");
  if (p) 
  {
    if_complex = 1;
  }

  p = strstr(p_string, "||");
  if (p) 
  {
    if_complex = 1;
  }

  p1 = strstr(p_string, "==");
  if (p1) 
  {
    if_math = 1;
  }

  p1 = strstr(p_string, "!=");
  if (p1) 
  {
    if_math = 1;
  }

  p1 = strstr(p_string, "<=");
  if (p1) 
  {
    if_math = 1;
  }

  p1 = strstr(p_string, ">=");
  if (p1) 
  {
    if_math = 1;
  }

  p1 = strstr(p_string, "<");
  if (p1) 
  {
    if_math = 1;
  }

  p1 = strstr(p_string, ">");
  if (p1) 
  {
    if_math = 1;
  }

  if ((if_complex == 0) && (if_math == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 0");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd1_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          fd1_type = 2;
          x2 = 1;
        }
      }
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
        ret = strcmp(gw_variable[I].gv_name, field1);
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
      printf("\nc2z_if.c if_case_22 if-157 Complex = 0 Math = 0 field1 Not Found = %s\n",field1);
      printf("c2z_if.c if_case_13 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_22 #1");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_22 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_22 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,ISUPPER");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_22 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_22 #5");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(o_string, a_string);
    check_length();
    strcat(a_string, "DS     0H");

    strcpy(a_string, "         LARL  R9,C370ISAL");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_22 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_22 #7");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_22 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    strcat(a_string, o_string);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_22 #9");
      trace_rec_3();
    }
    var_use[20]++;

    convert = 1;
  }

  if ((if_complex == 0) && (if_math == 1) && (convert == 0)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_22 comp = 0 math = 1");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isalpha(ch)) 
        {
          fd1_type = 1;
          x2 = 1;
        }

        if (isdigit(ch)) 
        {
          fd1_type = 2;
          x2 = 1;
        }
      }

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
        ret = strcmp(gw_variable[I].gv_name, field1);
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
      printf("\nc2z_if.c if_case_22 if-158 field1 Not Found = %s\n", field1);
      printf("c2z_if.c if_case_22 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    while (ch != ' ') 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          fd3_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          fd3_type = 2;
          x2 = 1;
        }
      }
      field3[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field3[pi2] = '\0';

    if (fd3_type == 2) 
    {
      x3 = 0;
      for (I = 0; I < lv_ct; I++) 
      {
        ret = strcmp(field3, lw_variable[I].lv_name);
        ret1 = strcmp(sv_func, lw_variable[I].lv_func);
        if ((ret == 0) && (ret1 == 0)) 
        {
          x3 = 1;
          strcpy(field3a, lw_variable[I].lv_cname);
          lw_variable[I].lv_use_ct++;
        }
      }

      if (x3 == 0) 
      {
        for (I = 0; I < gv_ct; I++) 
        {
          ret = strcmp(field3, gw_variable[I].gv_name);
          if (ret == 0) 
          {
            x3 = 1;
            strcpy(field3a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
          }
        }
      }

      if (x3 == 0) 
      {
        printf("\nc2z_if.c if_case_22 if-159 field3 Not Found = %s\n", field4);
        printf("c2z_if.c if_case_22 rct = %d p_string = %s", rct, p_string);
        erct++;
        convert = 1;
        return;
      }
    }

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_22 #100");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_22 #101");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2s_if.c if_case_22 #102");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,ISUPPER");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_22 #103");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_22 #104");
      trace_rec_3();
    }

    operand_1 = 0;
    if (operand_1 == 0) 
    {
      p = strstr(field2, "==");
      if (p)
      {
        operand_1 = 1;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "!=");
      if (p)
      {
        operand_1 = 2;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "<=");
      if (p)
      {
        operand_1 = 3;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, ">=");
      if (p)
      {
        operand_1 = 4;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "=");
      if (p)
      {
        operand_1 = 5;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, "<");
      if (p)
      {
        operand_1 = 6;
      }
    }

    if (operand_1 == 0) 
    {
      p = strstr(field2, ">");
      if (p)
      {
        operand_1 = 7;
      }
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(o_string, a_string);
    check_length();
    strcat(a_string, "DS     0H");

    strcpy(a_string, "         LARL  R9,C370ISAL");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_22 #105");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ZERO");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_22 #106");
      trace_rec_3();
    }
    work_use_ct[32]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_22 #107");
      trace_rec_3();
    }

    if (operand_1 == 1) 
    {
      strcpy(a_string, "         JLNE  ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_22 #108");
        trace_rec_3();
      }
    }

    if (operand_1 == 2) 
    {
      strcpy(a_string, "         JLE   ");
      strcat(a_string, o_string);
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_22 #108");
        trace_rec_3();
      }
    }

    if (operand_1 == 3) 
    {
      printf("\nc2z_if.c if_case_22 if-161 Complex = 0 <= NOT CODED\n");
      printf("c2z_if.c if_case_22 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 4) 
    {
      printf("\nc2z_if.c if_case_22 if-162 Complex = 0 >= NOT CODED\n");
      printf("c2z_if.c if_case_22 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 6) 
    {
      printf("\nc2z_if.c if_case_22 if-163 Complex = 0 < NOT CODED\n");
      printf("c2z_if.c if_case_22 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_1 == 7) 
    {
      printf("\nc2z_if.c if_case_22 if-164 Complex = 0 > NOT CODED\n");
      printf("c2z_if.c if_case_22 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
    var_use[20]++;
  }

  if (if_complex == 1) 
  {
    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      field1[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field1[pi2] = '\0';

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch == ' ') 
    {
      pi++;
      ch = p_string[pi];
    }

    x2 = 0;
    pi2 = 0;
    while (ch != ')') 
    {
      if (x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          fd2_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          fd2_type = 2;
          x2 = 1;
        }
      }
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    printf("\nif_case_2 complex == 1 if-165 NEED TO FINISH Second Half\n");
    printf("c2z_if.c if_case_22 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(o_string, a_string);
    check_length();
    strcat(a_string, "DS     0H");

    if (fd1_type == 2) 
    {
      strcpy(a_string, "*         CP    ");
      strcat(a_string, field1a);
    }

    if (fd1_type == 1) 
    {
      strcpy(a_string, "*         CLC   ");
      strcat(a_string, field1a);
    }

    strcat(a_string, ",");
    if (fd2_type == 2) 
    {
      strcat(a_string, field2a);
    }

    if (fd2_type == 1) 
    {
      strcat(a_string, "=P'");
      strcat(a_string, field2);
      strcat(a_string, "'");
    }

    src_line();
    if (puncde == 1)
    {
      trace_rec_3();
    }
  }

  if_convert = 1;
  convert = 1;
}

/* ***************************************************
*  if_case_23    isalnum                             *
* ************************************************** */
void if_case_23() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_23");
    trace_rec_1();
  }

  char ch;
  char *p, *p1;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  int pi;
  int pi2;
  int if_complex = 0;
  int if_short = 0;
  int x3 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;

  p = strstr(p_string, "&&");
  if (p) 
  {
    if_complex = 1;
  }

  p = strstr(p_string, "||");
  if (p) 
  {
    if_complex = 1;
  }

  p1 = strstr(p_string, "))");
  if (p1) 
  {
    if_short = 1;
  }

  if ((if_complex == 0) && (if_short == 1)) 
  {
    if (traceflg == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_23 0 / 0");
      trace_rec_1();
    }

    pi = 0;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi++;
    ch = p_string[pi];
    while (ch != '(') 
    {
      pi++;
      ch = p_string[pi];
    }

    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ')') 
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
      printf("\nc2z_if.c if_case_23 if-166 field1 Not Found = %s\n", field1);
      printf("c2z_if.c if_case_23 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcpy(o_string, a_string);
    check_length();
    strcat(a_string, "DS     0H");

    strcpy(a_string, "         LARL  R9,C370L1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #1");
      trace_rec_3();
    }
    work_use_ct[2]++;

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field1a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #2");
      trace_rec_3();
    }

    strcpy(a_string, "         MVC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R15,ISALNUM");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         BAKR  0,R15");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #4");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370ISAL");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #5");
      trace_rec_3();
    }
    work_use_ct[1]++;

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #6");
      trace_rec_3();
    }
    work_use_ct[33]++;

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #7");
      trace_rec_3();
    }

    strcpy(a_string, "         JNE    ");
    strcat(a_string, o_string);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_23 0 / 0 #8");
      trace_rec_3();
    }

    convert = 1;
    if_convert = 1;
  }

  if ((if_complex == 0) && (if_short == 0)) 
  {
    printf("\nc2z_if.c if_case_23 if-167 complex == 0 short == 0 NOT CODED\n");
    printf("c2z_if.c if_case_23 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (if_complex == 1) 
  {
    printf("\nc2z_if.c if_case_23 if-168 complex == 1 NOT CODED\n");
    printf("c2z_if.c if_case_23 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  convert = 1;
  if_convert = 1;
  return;
}

/* ***************************************************
*  if_case_24    logical if                          *
* ************************************************** */
void if_case_24() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_24 logical");
    trace_rec_1();
  }

  char ch;
  char *p;
  char tfield1[VAR_LGTH];
  char tfield1a[VAR_LGTH];

  int pi;
  int pi2;
  int x3;
  int I;
  int ret;
  int ret1;
  int notset = 0;

  p = strstr(p_string, "(!");
  if (p)
  {
    notset = 1;
  }

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ')') 
  {
    if (ch != '(') 
    {
      if (ch != '!') 
      {
        tfield1[pi2] = ch;
        pi2++;
      }
    }
    pi++;
    ch = p_string[pi];
  }
  tfield1[pi2] = '\0';
printf("c2z_if.c case_24 rct = %d p_string %s",rct,p_string);
printf("c2z_if.c case_24 tfield1 = %s\n",tfield1);

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(tfield1, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(tfield1a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(tfield1, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(tfield1a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_24 if-169 tfield1 Not Found = %s\n", tfield1);
    printf("c2z_if.c if_case_24 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, tfield1a);
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_24 logical #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_24 logical #2");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_24 logical #3");
    trace_rec_3();
  }

  if (notset == 0) 
  {
    strcpy(a_string, "         JLNE  L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_24 logical #4");
      trace_rec_3();
    }
  }

  if (notset == 1) 
  {
    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_24 logical #5");
      trace_rec_3();
    }
  }
  convert = 1;
  return;
}

/* ***************************************************
*  if_case_30    strchr                              *
* ************************************************** */
void if_case_30() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_30 strchr");
    trace_rec_1();
  }

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];

  int pi;
  int pi2;
  int x3 = 0;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int s = 0;
  int s1 = 0;
  int y = 0;

  use_strchr++;

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  y = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (y != 2) 
  {
    if (ch == '\"') 
    {
      y++;
    }

    if (y == 2) 
    {
      break;
    }

    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  s = strlen(field1);
  s = s - 1;

  while (ch != ',') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while (ch != ')') 
  {
    if (ch != ' ') 
    {
      field2[pi2] = ch;
      pi2++;
    }
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  I = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field2, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field2a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field2a, gw_variable[I].gv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_30 if-170 field2 Not Found = %s\n", field2);
    printf("c2z_if.c if_case_30 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  s1 = 0;
  if (s1 < s) 
  {
    s1++;
    for (I = 0; I < char_ct; I++) 
    {
      if ((rct == w_charlit[I].clit_rct) && (w_charlit[I].clit_uct == 1)) 
      {
        strcpy(a_string, "* 1st character compare");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_30 strchr #0");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, w_charlit[I].clit_cname);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_30 strchr #1");
          trace_rec_3();
        }
        break;
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #2");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #3");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #4");
      trace_rec_3();
    }
  }

  if (s1 < s) 
  {
    s1++;
    for (I = 0; I < char_ct; I++) 
    {
      if ((rct == w_charlit[I].clit_rct) && (w_charlit[I].clit_uct == 2)) 
      {
        strcpy(a_string, "* 2nd character compare");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_30 strchr #5");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, w_charlit[I].clit_cname);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_30 strchr #6");
          trace_rec_3();
        }
        break;
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #7");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #8");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #9");
      trace_rec_3();
    }
  }

  if (s1 < s) 
  {
    s1++;
    for (I = 0; I < char_ct; I++) 
    {
      if ((rct == w_charlit[I].clit_rct) && (w_charlit[I].clit_uct == 3)) 
      {
        strcpy(a_string, "* 3rd character compare");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_30 strchr #10");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, w_charlit[I].clit_cname);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_30 strchr #11");
          trace_rec_3();
        }
        break;
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #12");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #13");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #14");
      trace_rec_3();
    }
  }

  if (s1 < s) 
  {
    s1++;
    for (I = 0; I < char_ct; I++) 
    {
      if ((rct == w_charlit[I].clit_rct) && (w_charlit[I].clit_uct == 4)) 
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, w_charlit[I].clit_cname);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_30 strchr #15");
          trace_rec_3();
        }
        break;
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #16");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1)
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #17");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #18");
      trace_rec_3();
    }
  }

  if (s1 < s) 
  {
    s1++;
    for (I = 0; I < char_ct; I++) 
    {
      if ((rct == w_charlit[I].clit_rct) && (w_charlit[I].clit_uct == 5)) 
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, w_charlit[I].clit_cname);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_30 strchr #19");
          trace_rec_3();
        }
        break;
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #20");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #21");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #22");
      trace_rec_3();
    }
  }

  if (s1 < s) 
  {
    s1++;
    for (I = 0; I < char_ct; I++) 
    {
      if ((rct == w_charlit[I].clit_rct) && (w_charlit[I].clit_uct == 6)) 
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, w_charlit[I].clit_cname);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c case_30 strchr #23");
          trace_rec_3();
        }
        break;
      }
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #24");
      trace_rec_3();
    }

    strcpy(a_string, "         CLC   0(1,R9),0(R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #25");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_30 strchr #26");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         JLU   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
     strcpy(trace_1, "c2z_if.c case_30 strchr #27");
     trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_30 strchr #28");
    trace_rec_3();
  }

  if (s > 6) 
  {
    printf("\nc2z_if.c c2_if_case_30 s > 6 if-171 Not Coded\n");
    printf("c2z_if.c c2_if_case_30 rct = %d s = %d p_string = %s\n",rct,s,p_string);
    erct++;
  }
 
  convert = 1;
  return;
}



void if_case_40() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 START");
    trace_rec_1();
  }

  int pi;
  int pi2;
  int I = 0;
  int ret = 0;
  int ret1 = 0;
  int x2 = 0;
  int x3 = 0;
  int operand_1 = 0;
  int operand_2 = 0;
  int fd4_type = 0;
/*  int fd7_type = 0; */
  int fd9_type = 0;

  char ch;
  char *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field6a[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
/*  char field9a[VAR_LGTH]; */

  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];
  char ar_field12[VAR_LGTH];

  pi = 0;
  ch = p_string[pi];
  while(ch != '(')
  {
     pi++;
     ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while(ch != '[')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  fd4_type = 0;
  x2 = 0;
  pi2 = 0;
  while(ch != ')')
  {
    if(x2 == 0) 
    {
       if (isdigit(ch)) 
       {
         fd4_type = 1;
         x2 = 1;
       }

       if (isalpha(ch)) 
       {
         fd4_type = 2;
         x2 = 1;
       }
    }
    field4[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    pi2++;
    pi++;
    ch = p_string[pi];
  }

  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != '[')
  {
    field6[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field6[pi2] = '\0';

/*  fd7_type = 0; */
  pi2 = 0;
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    if(x2 == 0) 
    {
       if (isdigit(ch)) 
       {
     /*    fd7_type = 1; */
         x2 = 1;
       }

       if (isalpha(ch)) 
       {
 /*        fd7_type = 2; */
         x2 = 1;
       }
    }
    field7[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field7[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    field8[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field8[pi2] = '\0';

  pi2 = 0;
  fd9_type = 0;
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ')')
  {
    if(ch != ' ')
    {
      if(x2 == 0) 
      {
        if (isdigit(ch)) 
        {
          fd9_type = 1;
          x2 = 1;
        }

        if (isalpha(ch)) 
        {
          fd9_type = 2;
          x2 = 1;
        }
      }
      field9[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
  }
  field9[pi2] = '\0';

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
          strcpy(ar_field6, gw_variable[I].gv_label);
          strcpy(ar_field7, gw_variable[I].gv_table);
          strcpy(ar_field8, gw_variable[I].gv_aname);
          strcpy(ar_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar_field11, gw_variable[I].gv_wk_strg);
          strcpy(ar_field12, gw_variable[I].gv_type);
       }
     }
   }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_40 if-174 field1 Not Found = %s\n", field1);
    printf("c2z_if.c if_case_40 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

/*
printf("c2z_if.c case_40 START rct = %d p_string = %s\n",rct,p_string);
printf("c2z_if.c case_40 rct = %d field1 = %s\n",rct,field1);
printf("c2z_if.c case_40 rct = %d ar_field6 = %s\n",rct,ar_field6);
printf("c2z_if.c case_40 rct = %d ar_field7 = %s\n",rct,ar_field7);
printf("c2z_if.c case_40 rct = %d ar_field8 = %s\n",rct,ar_field8);
printf("c2z_if.c case_40 rct = %d ar_field9 = %s\n",rct,ar_field9);
printf("c2z_if.c case_40 rct = %d ar_field10 = %s\n",rct,ar_field10);
printf("c2z_if.c case_40 rct = %d ar_field11 = %s\n",rct,ar_field11);
printf("c2z_if.c case_40 rct = %d ar_field12 = %s\n",rct,ar_field12);
*/

  I = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field2, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field2a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field2, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field2a, gw_variable[I].gv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_40 if-175 field2 Not Found = %s\n", field2);
    printf("c2z_if.c if_case_40 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  operand_1 = 0;
  if (operand_1 == 0) 
  {
    p = strstr(field3, "==");
    if (p)
    {
      operand_1 = 1;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, "!=");
    if (p)
    {
      operand_1 = 2;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, "<=");
    if (p)
    {
      operand_1 = 3;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, ">=");
    if (p)
    {
      operand_1 = 4;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, "=");
    if (p)
    {
      operand_1 = 5;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, "<");
    if (p)
    {
      operand_1 = 6;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, ">");
    if (p)
    {
      operand_1 = 7;
    }
  }

  I = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field6, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field6a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field6, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field6a, gw_variable[I].gv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_40 if-177 field6 Not Found = %s\n", field6);
    printf("c2z_if.c if_case_40 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  I = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field7, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field7a, lw_variable[I].lv_cname);
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field7, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field7a, gw_variable[I].gv_cname);
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_40 if-178 field2 Not Found = %s\n", field2);
    printf("c2z_if.c if_case_40 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  operand_2 = 0;
  if (operand_2 == 0) 
  {
    p = strstr(field8, "==");
    if (p)
    {
      operand_2 = 1;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field8, "!=");
    if (p)
    {
      operand_2 = 2;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field8, "<=");
    if (p)
    {
      operand_2 = 3;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field8, ">=");
    if (p)
    {
      operand_2 = 4;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field8, "=");
    if (p)
    {
      operand_2 = 5;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field8, "<");
    if (p)
    {
      operand_2 = 6;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field8, ">");
    if (p)
    {
      operand_2 = 7;
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #550");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #551");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #552");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, ar_field7);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #553");
    trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #554");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #555");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field2a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field2);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #556");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #557");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #557");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #558");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #559");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #560");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
     strcpy(trace_1, "c2z_if.c if_case_40 #561");
     trace_rec_3();
  }

  strcpy(a_string, "         JLH   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, "L");
  strcat(a_string, wk_strg);
  src_line();
  if (puncde == 1) 
  {
     strcpy(trace_1, "c2z_if.c if_case_13 #562a");
     trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
     strcpy(trace_1, "c2z_if.c if_case_13 #562b");
     trace_rec_3();
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
     strcpy(trace_1, "c2z_if.c if_case_40 #563");
     trace_rec_3();
  }

  if(fd4_type == 1)
  {
    strcpy(a_string, "         LARL  R5,");
    strcat(a_string, field4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #564a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #564b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #564c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #564d");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #564e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #564f");
      trace_rec_3();
    }
  }

  if(fd4_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field4a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #564");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R6),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #565");
    trace_rec_3();
  }

  if (operand_1 == 1) 
  {
    strcpy(a_string, "         JLE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "M");
    src_line();
    if (puncde == 1) 
    {
       strcpy(trace_1, "c2z_if.c if_case_40 #566");
       trace_rec_3();
    }
  }

  if (operand_1 == 2) 
  {
    printf("\nc2z_if.c if_case_40 if-177 operand_1 == 2 NOT CODED\n");
    printf("c2z_if.c if_case_40 rct = %d p_string = %s\n", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 3) 
  {
    printf("\nc2z_if.c if_case_40 if-178 operand_1 == 3 NOT CODED\n");
    printf("c2z_if.c if_case_40 rct = %d p_string = %s\n", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

    if (operand_1 == 4) 
    {
      printf("\nc2z_if.c if_case_40 if-179 operand_1 == 4  NOT CODED\n");
      printf("c2z_if.c if_case_40 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

  if (operand_1 == 6) 
  {
    printf("\nc2z_if.c if_case_40 if-180 operand_1 == 6 NOT CODED\n");
    printf("c2z_if.c if_case_40 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_1 == 7) 
  {
    printf("\nc2z_if.c if_case_40 if-181 operand_1 == 7  NOT CODED\n");
    printf("c2z_if.c if_case_40 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  strcpy(a_string, "L");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  strcat(a_string, "D");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
     strcpy(trace_1, "c2z_if.c if_case_40 #567");
     trace_rec_3();
  }

  if(fd4_type == 1)
  {
    strcpy(a_string, "         LARL  R5,");
    strcat(a_string, field9);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field9);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #568a");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #568b");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #568c");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK2");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #568d");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #568e");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #568f");
      trace_rec_3();
    }
  }

  if(fd9_type == 2)
  {
    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field7a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field7);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_40 #568g");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         CP    0(6,R6),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_40 #569");
    trace_rec_3();
  }

  if (operand_2 == 1) 
  {
    strcpy(a_string, "         JLNE  ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    src_line();
    if (puncde == 1) 
    {
       strcpy(trace_1, "c2z_if.c if_case_40 #570");
       trace_rec_3();
    }
  }

  if (operand_2 == 2) 
  {
    printf("\nc2z_if.c if_case_40 if-182 operand_2 == 2 NOT CODED\n");
    printf("c2z_if.c if_case_40 rct = %d p_string = %s\n", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if (operand_2 == 3) 
  {
    printf("\nc2z_if.c if_case_40 if-183 operand_2 == 3 NOT CODED\n");
    printf("c2z_if.c if_case_40 rct = %d p_string = %s\n", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

    if (operand_2 == 4) 
    {
      printf("\nc2z_if.c if_case_40 if-184 operand_2 == 4 >= NOT CODED\n");
      printf("c2z_if.c if_case_40 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_2 == 6) 
    {
      printf("\nc2z_if.c if_case_40 if-185 operand_2 == 6 < NOT CODED\n");
      printf("c2z_if.c if_case_40 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    if (operand_2 == 7) 
    {
      printf("\nc2z_if.c if_case_40 if-186 operand_2 == 7 > NOT CODED\n");
      printf("c2z_if.c if_case_40 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    strcpy(a_string, "L");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, wk_strg);
    strcat(a_string, "M");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
       strcpy(trace_1, "c2z_if.c if_case_40 #571");
       trace_rec_3();
    }

  convert = 1;
  return;
}


void if_case_41() 
{
  if (traceflg == 1)     /* if((pi < len) && (temp_byte[ii] != 0)) */
  {
    strcpy(trace_1, "c2z_if.c if_case_41 START");
    trace_rec_1();
  }

   int x2;
   int x3;
   int x80;
   int pi;
   int pi2;
   int ret;
   int ret1;
   int I;
   int fd7_type;
   int operand_1;
   int operand_2;

  char ch;
  char *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];

  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];
  char ar_field12[VAR_LGTH];

  x2 = 0;
  pi = 0;
  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while(ch != ' ')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ' ')
  {
   field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ')')
  {
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != '[')
  {
    field4[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    field5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field5[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  ch = p_string[pi];
  while(ch != ' ')
  {
   field6[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field6[pi2] = '\0';

  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  fd7_type = 0;
  ch = p_string[pi];
  while(ch != ')')
  {
    if (x2 == 0) 
    {
       if (isdigit(ch)) 
       {
         fd7_type = 1;
         x2 = 1;
       }

       if (isalpha(ch)) 
       {
         fd7_type = 2;
         x2 = 1;
       }
    }
    field7[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field7[pi2] = '\0';

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
    printf("\nc2z_if.c if_case_41 if-188 field1 Not Found = %s\n", field1);
    printf("c2z_if.c if_case_41 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  I = 0;
  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field3, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field3a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field3a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_41 if-189 field3 Not Found = %s\n", field3);
    printf("c2z_if.c if_case_41 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  operand_1 = 0;
  if (operand_1 == 0) 
  {
    p = strstr(field2, "==");
    if (p)
    {
      operand_1 = 1;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, "!=");
    if (p)
    {
      operand_1 = 2;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, "<=");
    if (p)
    {
      operand_1 = 3;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, ">=");
    if (p)
    {
      operand_1 = 4;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, "=");
    if (p)
    {
      operand_1 = 5;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, "<");
    if (p)
    {
      operand_1 = 6;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field2, ">");
    if (p)
    {
      operand_1 = 7;
    }
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
     ret = strcmp(field4, lw_variable[I].lv_name);
     ret1 = strcmp(sv_func, lw_variable[I].lv_func);
     if ((ret == 0) && (ret1 == 0)) 
     {
       x3 = 1;
       strcpy(field4a, lw_variable[I].lv_cname);
       lw_variable[I].lv_use_ct++;
     }
   }

   if (x3 == 0) 
   {
     for (I = 0; I < gv_ct; I++) 
     {
       ret = strcmp(field4, gw_variable[I].gv_name);
       if (ret == 0) 
       {
          x3 = 1;
          strcpy(field4a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          strcpy(ar_field6, gw_variable[I].gv_label);
          strcpy(ar_field7, gw_variable[I].gv_table);
          strcpy(ar_field8, gw_variable[I].gv_aname);
          strcpy(ar_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar_field11, gw_variable[I].gv_wk_strg);
          strcpy(ar_field12, gw_variable[I].gv_type);
       }
     }
   }
 
  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_41 if-190 field4 Not Found = %s\n", field4);
    printf("c2z_if.c if_case_41 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
     ret = strcmp(field5, lw_variable[I].lv_name);
     ret1 = strcmp(sv_func, lw_variable[I].lv_func);
     if ((ret == 0) && (ret1 == 0)) 
     {
       x3 = 1;
       strcpy(field5a, lw_variable[I].lv_cname);
       lw_variable[I].lv_use_ct++;
     }
   }

   if (x3 == 0) 
   {
     for (I = 0; I < gv_ct; I++) 
     {
       ret = strcmp(field5, gw_variable[I].gv_name);
       if (ret == 0) 
       {
          x3 = 1;
          strcpy(field5a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
       }
     }
   }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_41 if-191 field5 Not Found = %s\n", field5);
    printf("c2z_if.c if_case_41 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  operand_2 = 0;
  if (operand_2 == 0) 
  {
    p = strstr(field6, "==");
    if (p)
    {
      operand_2 = 1;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "!=");
    if (p)
    {
      operand_2 = 2;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "<=");
    if (p)
    {
      operand_2 = 3;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, ">=");
    if (p)
    {
      operand_2 = 4;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "=");
    if (p)
    {
      operand_2 = 5;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "<");
    if (p)
    {
      operand_2 = 6;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, ">");
    if (p)
    {
      operand_2 = 7;
    }
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcpy(o_string, a_string);

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, field1a);
  strcpy(wk_remark, " "); 
  strcat(wk_remark, field1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_41 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field3a);
  strcpy(wk_remark, " "); 
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_41 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    ");
  strcat(a_string, "0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
     strcpy(trace_1, "c2z_if.c if_case_41 #3");
     trace_rec_3();
  }

  if(operand_1 == 6)
  {
    strcpy(a_string, "         JLH   ");
    strcat(a_string, o_string);
    src_line();
    if(puncde == 1)
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #4");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_41 #5");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_41 #6");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #7");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #8");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field5a);
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #11");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #12");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #13");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #14");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #15");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #16");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #17");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #18");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_41 #19");
      trace_rec_3();
    }

    if (fd7_type == 1) 
    {
        x80 = 1;

        strcpy(a_string, "         LAEY  R5,");
        strcat(a_string, field7);
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_41 #20");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_41 #21");
          trace_rec_3();
        }

        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_41 #22");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK1");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_41 #23");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_41 #24");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_41 #25");
          trace_rec_3();
        }

        if(x80 == 0)
        {
          strcpy(a_string, "         CLC   0(1,R9),0(R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_41 #26");
            trace_rec_3();
          }
        }

        if(x80 == 1)
        {
          strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
          src_line();
          if (puncde == 1) 
          {
            strcpy(trace_1, "c2z_if.c if_case_41 #27");
            trace_rec_3();
          }
        }

        if(operand_2 == 2)
        {
          strcpy(a_string, "         JLE   ");
          strcat(a_string, o_string);
          src_line();
          if(puncde == 1)
          {
            strcpy(trace_1, "c2z_if.c if_case_41 #28");
            trace_rec_3();
          }
        }
    }

  convert = 1;
  return;
}


/* ***************************************************
*  if_case_42                                        *
* ************************************************** */
void if_case_42()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_42 START");
    trace_rec_1();
  }

   int pi;
   int pi2;
   int x2;
   int x3;
   int I;
   int ret;
   int ret1;
   int fd4_type;

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char f3type[2];

  pi = 0;
  ch = p_string[pi];
  while (ch != '(') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ' ')
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
    printf("\nc2z_if.c if_case_42 if-001 field1 Not Found = %s\n", field1);
    printf("c2z_if.c if_case_42 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    pi2++;
    pi++;
    ch = p_string[pi];
  }

  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

 
  pi2 = 0;
  while(ch != '[')
  {
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
     ret = strcmp(field3, lw_variable[I].lv_name);
     ret1 = strcmp(sv_func, lw_variable[I].lv_func);
     if ((ret == 0) && (ret1 == 0)) 
     {
       x3 = 1;
       strcpy(field3a, lw_variable[I].lv_cname);
       lw_variable[I].lv_use_ct++;
       strcpy(f3type, lw_variable[I].lv_type);
     }
   }

   if (x3 == 0) 
   {
     for (I = 0; I < gv_ct; I++) 
     {
       ret = strcmp(field3, gw_variable[I].gv_name);
       if (ret == 0) 
       {
          x3 = 1;
          strcpy(field3a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
          strcpy(f3type, gw_variable[I].gv_type);
       }
     }
   }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_42 if-002 field3 Not Found = %s\n", field3);
    printf("c2z_if.c if_case_42 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  x2 = 0;
  fd4_type = 0;
  pi2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    if (x2 == 0) 
    {
       if (isdigit(ch)) 
       {
         fd4_type = 1;
         x2 = 1;
       }

       if (isalpha(ch)) 
       {
         fd4_type = 2;
         x2 = 1;
       }
    }

    field4[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';

  if(fd4_type == 1)
  {
printf("c2z_if.c case_42 NOT CODED fd4_type == 1\n");
  }

  if(fd4_type == 2)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field4a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field4a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_42 if-003 field4 Not Found = %s\n", field3);
      printf("c2z_if.c if_case_42 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }

    ret = strcmp("C",f3type);
    if(fd4_type == 1)
    {
      strcpy(a_string, "         LAEY  R5,");
      strcat(a_string, field4a);
      strcpy(wk_remark, " ");
      strcat(wk_remark, field4);
      strcat(wk_remark, " */");
      write_remark();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_42 #1");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_42 #2");
        trace_rec_3();
      }

      strcpy(a_string, "         CVD   R5,0(R9)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_42 #3");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R9,C370NWK1");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_42 #4");
        trace_rec_3();
      }

      strcpy(a_string, "         LARL  R8,C370U");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_42 #5");
        trace_rec_3();
      }

      strcpy(a_string, "         ZAP   0(6,R9),0(8,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c case_42 #6");
        trace_rec_3();
      }
    }

    if(fd4_type == 2)
    {
       strcpy(a_string, "         LARL  R9,C370NWK1");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_if.c case_42 #6a");
         trace_rec_3();
       }

       strcpy(a_string, "         LARL  R8,");
       strcat(a_string, field4a);
       strcpy(wk_remark, " ");
       strcat(wk_remark, field4);
       strcat(wk_remark, " */");
       write_remark();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_if.c case_42 #6b");
         trace_rec_3();
       }

       strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
       src_line();
       if (puncde == 1) 
       {
         strcpy(trace_1, "c2z_if.c case_42 #6c");
         trace_rec_3();
       }
    }

     strcpy(a_string, "         LARL  R9,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #7");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370NWK1");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #8");
       trace_rec_3();
     }

     strcpy(a_string, "         ZAP   0(8,R9),2(4,R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #9");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C370U");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #10");
       trace_rec_3();
     }

     strcpy(a_string, "         CVB   R5,0(R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #11");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,");
     strcat(a_string, field3a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field3);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #12");
       trace_rec_3();
     }

     strcpy(a_string, "         IC    R0,0(R8,(R5))");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #13");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,C37M002");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #14");
       trace_rec_3();
     }

     strcpy(a_string, "         STC   R0,0(0,R9)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #15");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R9,");
     strcat(a_string, field1a);
     strcpy(wk_remark, " ");
     strcat(wk_remark, field1);
     strcat(wk_remark, " */");
     write_remark();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #16");
       trace_rec_3();
     }

     strcpy(a_string, "         LARL  R8,C37M002");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #17");
       trace_rec_3();
     }

     strcpy(a_string, "         CLC   0(1,R9),0(R8)");
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #18");
       trace_rec_3();
     }
   
     strcpy(a_string, "         JLNE  L");
     snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
     strcat(a_string, wk_strg);
     src_line();
     if (puncde == 1) 
     {
       strcpy(trace_1, "c2z_if.c case_42 #19");
       trace_rec_3();
     }
   }
}


/* ***************************************************
*  if_case_43                                        *
* ************************************************** */
void if_case_43()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_43 START");
    trace_rec_1();
  }

printf("c2z_if.c case_43 rct = %d p_string = %s",rct,p_string);

  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];

   int pi;
   int pi2;
   int fd2_type;
   int x2;

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
  while(ch != '[')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';
printf("c2z_if.c case_43 field1 = %s\n",field1);

  fd2_type = 0;
  pi2 = 0;
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    if (x2 == 0) 
    {
       if (isdigit(ch)) 
       {
         fd2_type = 1;
         x2 = 1;
       }

       if (isalpha(ch)) 
       {
         fd2_type = 2;
         x2 = 1;
       }
    }
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';
printf("c2z_if.c case_43 field2 = %s    fd2_type = %d\n",field2,fd2_type);

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }


  convert = 1;
  return;
}


/* ***************************************************
*  if_case_44                                        *
* ************************************************** */
void if_case_44()
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 START");
    trace_rec_1();
  }

   int x2;
   int x3;
   int x80;
   int pi;
   int pi2;
   int ret;
   int ret1;
   int I;
   int fd2_type;
   int fd4_type;
   int fd5_type;
   int fd7_type;
   int operand_1;
   int operand_2;

  char ch;
  char *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
 /* char field3a[VAR_LGTH]; */
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];

  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];
  char ar_field12[VAR_LGTH];

  x2 = 0;
  pi = 0;
  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while(ch != '[')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  fd2_type = 0;
  pi2 = 0;
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
   if (x2 == 0) 
    {
       if (isdigit(ch)) 
       {
         fd2_type = 1;
         x2 = 1;
       }
       if (isalpha(ch)) 
       {
         fd2_type = 2;
         x2 = 1;
       }
    }
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  fd4_type = 0;
  pi2 = 0;
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ')')
  {
    if (x2 == 0) 
    {
       if (isdigit(ch)) 
       {
         fd4_type = 1;
         x2 = 1;
       }

       if (isalpha(ch)) 
       {
         fd4_type = 2;
         x2 = 1;
       }
    }
    field4[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  fd5_type = 0;
  pi2 = 0;
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ' ')
  {
   if (x2 == 0) 
    {
       if (isdigit(ch)) 
       {
         fd5_type = 1;
         x2 = 1;
       }
       if (isalpha(ch)) 
       {
         fd5_type = 2;
         x2 = 1;
       }
    }
    field5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field5[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  ch = p_string[pi];
  while(ch != ' ')
  {
    field6[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field6[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  fd7_type = 0;
  pi2 = 0;
  x2 = 0;
  ch = p_string[pi];
  while(ch != ')')
  {
   if (x2 == 0) 
    {
       if (isdigit(ch)) 
       {
         fd7_type = 1;
         x2 = 1;
       }

       if (isalpha(ch)) 
       {
         fd7_type = 2;
         x2 = 1;
       }
    }
    field7[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field7[pi2] = '\0';

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
          strcpy(ar_field6, gw_variable[I].gv_label);
          strcpy(ar_field7, gw_variable[I].gv_table);
          strcpy(ar_field8, gw_variable[I].gv_aname);
          strcpy(ar_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar_field11, gw_variable[I].gv_wk_strg);
          strcpy(ar_field12, gw_variable[I].gv_type);
       }
     }
   }
 
  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_44 if-4401 field1 Not Found = %s\n", field1);
    printf("c2z_if.c if_case_44 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if(fd2_type == 2)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
       ret = strcmp(field2, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         x3 = 1;
         strcpy(field2a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
       }
     }

     if (x3 == 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(field2, gw_variable[I].gv_name);
         if (ret == 0) 
         {
            x3 = 1;
            strcpy(field2a, gw_variable[I].gv_cname);
            gw_variable[I].gv_use_ct++;
         }
       }
     }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_44 if-E4402 field2 Not Found = %s\n", field2);
      printf("c2z_if.c if_case_44 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd4_type == 2)
  {
    I = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field4a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field4a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_44 E4404 field4 Not Found = %s\n", field4);
      printf("c2z_if.c if_case_44 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd5_type == 2)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
       ret = strcmp(field5, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         x3 = 1;
         strcpy(field5a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
       }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field5, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field5a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_44 E4405 field5 Not Found = %s\n", field5);
      printf("c2z_if.c if_case_44 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  if(fd7_type == 2)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
       ret = strcmp(field7, lw_variable[I].lv_name);
       ret1 = strcmp(sv_func, lw_variable[I].lv_func);
       if ((ret == 0) && (ret1 == 0)) 
       {
         x3 = 1;
         strcpy(field7a, lw_variable[I].lv_cname);
         lw_variable[I].lv_use_ct++;
       }
     }

     if (x3 == 0) 
     {
       for (I = 0; I < gv_ct; I++) 
       {
         ret = strcmp(field7, gw_variable[I].gv_name);
         if (ret == 0) 
         {
           x3 = 1;
           strcpy(field7a, gw_variable[I].gv_cname);
           gw_variable[I].gv_use_ct++;
         }
       }
     }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_44 E4407 field7 Not Found = %s\n", field7);
      printf("c2z_if.c if_case_44 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  operand_1 = 0;
  if (operand_1 == 0) 
  {
    p = strstr(field3, "==");
    if (p)
    {
      operand_1 = 1;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, "!=");
    if (p)
    {
      operand_1 = 2;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, "<=");
    if (p)
    {
      operand_1 = 3;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, ">=");
    if (p)
    {
      operand_1 = 4;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, "=");
    if (p)
    {
      operand_1 = 5;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, "<");
    if (p)
    {
      operand_1 = 6;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, ">");
    if (p)
    {
      operand_1 = 7;
    }
  }

  operand_2 = 0;
  if (operand_2 == 0) 
  {
    p = strstr(field6, "==");
    if (p)
    {
      operand_2 = 1;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "!=");
    if (p)
    {
      operand_2 = 2;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "<=");
    if (p)
    {
      operand_2 = 3;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, ">=");
    if (p)
    {
      operand_2 = 4;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "=");
    if (p)
    {
      operand_2 = 5;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "<");
    if (p)
    {
      operand_2 = 6;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, ">");
    if (p)
    {
      operand_2 = 7;
    }
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcpy(o_string, a_string);

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #4");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #5");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #6");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R6,");
  strcat(a_string, ar_field7);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #7");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #8");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #9");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field2a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field2);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #10");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #11");
    trace_rec_3();
  }

  strcpy(a_string, "         JLE   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #12");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #13");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ONE");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #14");
    trace_rec_3();
  }

  strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #15");
    trace_rec_3();
  }

  strcpy(a_string, "         LA    R6,");
  strcat(a_string, ar_field6);
  strcat(a_string, "(R0,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #16");
    trace_rec_3();
  }

  strcpy(a_string, "         JLU   ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "A");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #17");
    trace_rec_3();
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcat(a_string, "B");
  check_length();
  strcat(a_string, "DS    0H");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #18");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #19");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R6)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #20");
    trace_rec_3();
  }

  if (fd4_type == 1) 
  {
    x80 = 1;

    strcpy(a_string, "         LAEY  R5,");
    strcat(a_string, field4);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field4);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_44 #21");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_44 #22");
      trace_rec_3();
    }

    strcpy(a_string, "         CVD   R5,0(R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_44 #23");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_44 #24");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R7,C370U");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_44 #25");
      trace_rec_3();
    }

    strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_44 #26");
      trace_rec_3();
    }

    if(x80 == 0)
    {
      strcpy(a_string, "         CLC   0(1,R9),0(R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_44 #27");
        trace_rec_3();
      }
    }

    if(x80 == 1)
    {
      strcpy(a_string, "         LARL  R9,C370NWK3");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_44 #28");
        trace_rec_3();
      }

      strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
      src_line();
      if (puncde == 1) 
      {
        strcpy(trace_1, "c2z_if.c if_case_44 #29");
        trace_rec_3();
      }
    }

    if(operand_1 == 2)
    {
      strcpy(a_string, "         JLE   ");
      strcat(a_string, o_string);
      src_line();
      if(puncde == 1)
      {
        strcpy(trace_1, "c2z_if.c if_case_44 #30");
        trace_rec_3();
      }
    }
  }

  strcpy(a_string, "         LARL  R9,");
  strcat(a_string, field5a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field5);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #25");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field7a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field7);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_44 #26");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    ");
  strcat(a_string, "0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
     strcpy(trace_1, "c2z_if.c if_case_44 #27");
     trace_rec_3();
  }

  if(operand_2 == 6)
  {
    strcpy(a_string, "         JLH   ");
    strcat(a_string, o_string);
    src_line();
    if(puncde == 1)
    {
      strcpy(trace_1, "c2z_if.c if_case_44 #4");
      trace_rec_3();
    }
  }

  convert = 1;
  return;
}


void if_case_45()
{
  if (traceflg == 1)     /* if((temp_byte[ii] != 0) && (pi < len)) */
  {
    strcpy(trace_1, "c2z_if.c if_case_45 START");
    trace_rec_1();
  }

   int x2;
   int x3;
/*   int x80; */
   int pi;
   int pi2;
   int ret;
   int ret1;
   int I;
/*   int fd2_type; */
   int fd4_type;
   int fd5_type;
   int fd7_type;
   int operand_1;
   int operand_2;

  char ch;
  char *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field2a[VAR_LGTH];
  char field3[VAR_LGTH];
/*  char field3a[VAR_LGTH]; */
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field7a[VAR_LGTH];

  char ar_field6[VAR_LGTH];
  char ar_field7[VAR_LGTH];
  char ar_field8[VAR_LGTH];
  char ar_field9[VAR_LGTH];
  char ar_field10[VAR_LGTH];
  char ar_field11[VAR_LGTH];
  char ar_field12[VAR_LGTH];

  x2 = 0;
  pi = 0;
  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while(ch != '[')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  pi2 = 0;
/*  fd2_type = 0; */
  x2 = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ']')
  {
    if (x2 == 0) 
    {
       if (isdigit(ch)) 
       {
/*         fd2_type = 1; */
         x2 = 1;
       }

       if (isalpha(ch)) 
       {
  /*       fd2_type = 2; */
         x2 = 1;
       }
    }
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  x2 = 0;
  pi2 = 0;
  while(ch != ' ')
  {
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  pi2 = 0;
  x2 = 0;
  fd4_type = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ')')
  {
    if (x2 == 0) 
    {
       if (isdigit(ch)) 
       {
         fd4_type = 1;
         x2 = 1;
       }

       if (isalpha(ch)) 
       {
         fd4_type = 2;
         x2 = 1;
       }
    }
    field4[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  fd5_type = 0;
  pi++;
  ch = p_string[pi];
  while(ch != ' ')
  {
    if (x2 == 0) 
    {
       if (isdigit(ch)) 
       {
         fd5_type = 1;
         x2 = 1;
       }

       if (isalpha(ch)) 
       {
         fd5_type = 2;
         x2 = 1;
       }
    }
    field5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field5[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  ch = p_string[pi];
  while(ch != ' ')
  {
   field6[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field6[pi2] = '\0';

  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  x2 = 0;
  fd7_type = 0;
  ch = p_string[pi];
  while(ch != ')')
  {
    if (x2 == 0) 
    {
       if (isdigit(ch)) 
       {
         fd7_type = 1;
         x2 = 1;
       }

       if (isalpha(ch)) 
       {
         fd7_type = 2;
         x2 = 1;
       }
    }
    field7[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field7[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
     ret = strcmp(field1, lw_variable[I].lv_name);
     ret1 = strcmp(sv_func, lw_variable[I].lv_func);
     if ((ret == 0) && (ret1 == 0)) 
     {
       x3 = 1;
       strcpy(field4a, lw_variable[I].lv_cname);
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
          strcpy(ar_field6, gw_variable[I].gv_label);
          strcpy(ar_field7, gw_variable[I].gv_table);
          strcpy(ar_field8, gw_variable[I].gv_aname);
          strcpy(ar_field9, gw_variable[I].gv_sv_reg);
          strcpy(ar_field10, gw_variable[I].gv_wk_reg);
          strcpy(ar_field11, gw_variable[I].gv_wk_strg);
          strcpy(ar_field12, gw_variable[I].gv_type);
       }
     }
   }
 
  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_45 if-200 field1 Not Found = %s\n", field1);
    printf("c2z_if.c if_case_45 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
     ret = strcmp(field2, lw_variable[I].lv_name);
     ret1 = strcmp(sv_func, lw_variable[I].lv_func);
     if ((ret == 0) && (ret1 == 0)) 
     {
       x3 = 1;
       strcpy(field2a, lw_variable[I].lv_cname);
       lw_variable[I].lv_use_ct++;
     }
   }

   if (x3 == 0) 
   {
     for (I = 0; I < gv_ct; I++) 
     {
       ret = strcmp(field2, gw_variable[I].gv_name);
       if (ret == 0) 
       {
          x3 = 1;
          strcpy(field2a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
       }
     }
   }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c if_case_45 if-201 field2 Not Found = %s\n", field2);
    printf("c2z_if.c if_case_41 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  if(fd4_type == 2)
  {
    I = 0;
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field4, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field4a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field4, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field4a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_45 if-189 field4 Not Found = %s\n", field4);
      printf("c2z_if.c if_case_45 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }


  operand_1 = 0;
  if (operand_1 == 0) 
  {
    p = strstr(field3, "==");
    if (p)
    {
      operand_1 = 1;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, "!=");
    if (p)
    {
      operand_1 = 2;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, "<=");
    if (p)
    {
      operand_1 = 3;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, ">=");
    if (p)
    {
      operand_1 = 4;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, "=");
    if (p)
    {
      operand_1 = 5;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, "<");
    if (p)
    {
      operand_1 = 6;
    }
  }

  if (operand_1 == 0) 
  {
    p = strstr(field3, ">");
    if (p)
    {
      operand_1 = 7;
    }
  }

  if(fd5_type == 1)
  {
    printf("c2z_if.c case_45 Fd5_type == 1 NOT CODED\n");
    printf("c2z_if.c case_45 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  if(fd5_type == 2)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field5, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field5a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field5, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field5a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_45 if-191 field5 Not Found = %s\n", field5);
      printf("c2z_if.c if_case_45 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  operand_2 = 0;
  if (operand_2 == 0) 
  {
    p = strstr(field6, "==");
    if (p)
    {
      operand_2 = 1;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "!=");
    if (p)
    {
      operand_2 = 2;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "<=");
    if (p)
    {
      operand_2 = 3;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, ">=");
    if (p)
    {
      operand_2 = 4;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "=");
    if (p)
    {
      operand_2 = 5;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, "<");
    if (p)
    {
      operand_2 = 6;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field6, ">");
    if (p)
    {
      operand_2 = 7;
    }
  }

  if(fd7_type == 1)
  {
    printf("c2z_if.c case_45 fd7_type == 1 NOT CODED\n");
    printf("c2z_if.c case_45 rct = %d p_string = %s\n",rct,p_string);
    erct++;
    convert = 1;
    return;
  }

  if(fd7_type == 2)
  {
    x3 = 0;
    for (I = 0; I < lv_ct; I++) 
    {
      ret = strcmp(field7, lw_variable[I].lv_name);
      ret1 = strcmp(sv_func, lw_variable[I].lv_func);
      if ((ret == 0) && (ret1 == 0)) 
      {
        x3 = 1;
        strcpy(field7a, lw_variable[I].lv_cname);
        lw_variable[I].lv_use_ct++;
      }
    }

    if (x3 == 0) 
    {
      for (I = 0; I < gv_ct; I++) 
      {
        ret = strcmp(field7, gw_variable[I].gv_name);
        if (ret == 0) 
        {
          x3 = 1;
          strcpy(field7a, gw_variable[I].gv_cname);
          gw_variable[I].gv_use_ct++;
        }
      }
    }

    if (x3 == 0) 
    {
      printf("\nc2z_if.c if_case_45 if-192 field7 Not Found = %s\n", field7);
      printf("c2z_if.c if_case_45 rct = %d p_string = %s", rct, p_string);
      erct++;
      convert = 1;
      return;
    }
  }

  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcpy(a_string, "L");
  strcat(a_string, wk_strg);
  strcpy(o_string, a_string);

  strcpy(a_string, "         LARL  R9,C370NWK1");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_45 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,C370ZERO");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c if_case_45 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #3");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R6,");
    strcat(a_string, ar_field7);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field1);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #4");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #5");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #6");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field2a);
    strcpy(wk_remark, " ");
    strcat(wk_remark, field2);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #7");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #8");
      trace_rec_3();
    }

    strcpy(a_string, "         JLE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #9");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R9,C370NWK1");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #10");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,C370ONE");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #11");
      trace_rec_3();
    }

    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #12");
      trace_rec_3();
    }

    strcpy(a_string, "         LA    R6,");
    strcat(a_string, ar_field6);
    strcat(a_string, "(R0,R6)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #13");
      trace_rec_3();
    }

    strcpy(a_string, "         JLU   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "A");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #14");
      trace_rec_3();
    }

    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcpy(a_string, "L");
    strcat(a_string, wk_strg);
    strcat(a_string, "B");
    check_length();
    strcat(a_string, "DS    0H");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #15");
      trace_rec_3();
    }

    if (fd4_type == 1) 
    {
        strcpy(a_string, "         LAEY  R5,");
        strcat(a_string, field4);
        strcpy(wk_remark, " ");
        strcat(wk_remark, field4);
        strcat(wk_remark, " */");
        write_remark();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_45 #16a");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_45 #16b");
          trace_rec_3();
        }

        strcpy(a_string, "         CVD   R5,0(R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_45 #16c");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R8,C370NWK2");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_45 #16d");
          trace_rec_3();
        }

        strcpy(a_string, "         LARL  R7,C370U");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_45 #16e");
          trace_rec_3();
        }

        strcpy(a_string, "         ZAP   0(6,R8),0(8,R7)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_45 #16f");
          trace_rec_3();
        }

        strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
        src_line();
        if (puncde == 1) 
        {
          strcpy(trace_1, "c2z_if.c if_case_45 #16g");
          trace_rec_3();
        }
      }

      if(operand_1 == 2)
      {
        strcpy(a_string, "         JLE   ");
        strcat(a_string, o_string);
        src_line();
        if(puncde == 1)
        {
          strcpy(trace_1, "c2z_if.c if_case_45 #17");
          trace_rec_3();
        }
      }
   
    strcpy(a_string, "         LARL  R9,");
    strcat(a_string, field5a);
    strcpy(wk_remark, " "); 
    strcat(wk_remark, field5);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #18");
      trace_rec_3();
    }

    strcpy(a_string, "         LARL  R8,");
    strcat(a_string, field7a);
    strcpy(wk_remark, " "); 
    strcat(wk_remark, field7);
    strcat(wk_remark, " */");
    write_remark();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c if_case_45 #19");
      trace_rec_3();
    }

    strcpy(a_string, "         CP    ");
    strcat(a_string, "0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
       strcpy(trace_1, "c2z_if.c if_case_45 #20");
       trace_rec_3();
    }

    if(operand_2 == 6)
    {
      strcpy(a_string, "         JLH   ");
      strcat(a_string, o_string);
      src_line();
      if(puncde == 1)
      {
        strcpy(trace_1, "c2z_if.c if_case_45 #21");
        trace_rec_3();
      }
 
      strcpy(a_string, "         JLE   ");
      strcat(a_string, o_string);
      src_line();
      if(puncde == 1)
      {
        strcpy(trace_1, "c2z_if.c if_case_45 #22");
        trace_rec_3();
      }
    }

  convert = 1;
  return;
}


/* ***************************************************
*  if_case_47                                        *
* ************************************************** */
void if_case_47() 		/* if((left + count) > len) */
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_47 START");
    trace_rec_1();
  }

  char ch;
  char *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];
  char field3a[VAR_LGTH];
  char field4[VAR_LGTH];
  char field5[VAR_LGTH];
  char field5a[VAR_LGTH];

   int pi;
   int pi2;
   int operand_1;
   int operand_2;
   int I;
   int x3;
   int ret;
   int ret1;

  pi = 0;
  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  pi++;
  pi++;
  ch = p_string[pi];
  while(ch != ' ')
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    field2[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field2[pi2] = '\0';

  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ')')
  {
    field3[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field3[pi2] = '\0';

  pi++;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    field4[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field4[pi2] = '\0';

  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ')')
  {
    field5[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field5[pi2] = '\0';

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
    printf("\nc2z_if.c case_47 E-471 field1 Not Found = %s\n", field1);
    printf("c2z_if.c case_47 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field3, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field3a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field3, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field3a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c case_47 E-472 field3 Not Found = %s\n", field3);
    printf("c2z_if.c case_47 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  x3 = 0;
  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(field5, lw_variable[I].lv_name);
    ret1 = strcmp(sv_func, lw_variable[I].lv_func);
    if ((ret == 0) && (ret1 == 0)) 
    {
      x3 = 1;
      strcpy(field5a, lw_variable[I].lv_cname);
      lw_variable[I].lv_use_ct++;
    }
  }

  if (x3 == 0) 
  {
    for (I = 0; I < gv_ct; I++) 
    {
      ret = strcmp(field5, gw_variable[I].gv_name);
      if (ret == 0) 
      {
        x3 = 1;
        strcpy(field5a, gw_variable[I].gv_cname);
        gw_variable[I].gv_use_ct++;
      }
    }
  }

  if (x3 == 0) 
  {
    printf("\nc2z_if.c case_47 E-473 field5 Not Found = %s\n", field5);
    printf("c2z_if.c case_47 rct = %d p_string = %s", rct, p_string);
    erct++;
    convert = 1;
    return;
  }

  operand_1 = 0;
  p = strstr(field2, "+");
  if(p)
  {
    operand_1 = 1;
  }

  operand_2 = 0;
  if (operand_2 == 0) 
  {
    p = strstr(field4, "==");
    if (p)
    {
      operand_2 = 1;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field4, "!=");
    if (p)
    {
      operand_2 = 2;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field4, "<=");
    if (p)
    {
      operand_2 = 3;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field4, ">=");
    if (p)
    {
      operand_2 = 4;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field4, "=");
    if (p)
    {
      operand_2 = 5;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field4, "<");
    if (p)
    {
      operand_2 = 6;
    }
  }

  if (operand_2 == 0) 
  {
    p = strstr(field4, ">");
    if (p)
    {
      operand_2 = 7;
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_47 #1");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field1a);
  strcpy(wk_remark, " "); 
  strcat(wk_remark, field1);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_47 #2");
    trace_rec_3();
  }

  strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_47 #3");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_47 #4");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field3a);
  strcpy(wk_remark, " "); 
  strcat(wk_remark, field3);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_47 #5");
    trace_rec_3();
  }

  if(operand_1 == 1)
  {
    strcpy(a_string, "         AP    0(6,R9),0(6,R8)");
    src_line();
    if (puncde == 1) 
    {
      strcpy(trace_1, "c2z_if.c case_47 #6");
      trace_rec_3();
    }
  }

  strcpy(a_string, "         LARL  R9,C370NWK3");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_47 #7");
    trace_rec_3();
  }

  strcpy(a_string, "         LARL  R8,");
  strcat(a_string, field5a);
  strcpy(wk_remark, " "); 
  strcat(wk_remark, field5);
  strcat(wk_remark, " */");
  write_remark();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_47 #8");
    trace_rec_3();
  }

  strcpy(a_string, "         CP    0(6,R9),0(6,R8)");
  src_line();
  if (puncde == 1) 
  {
    strcpy(trace_1, "c2z_if.c case_47 #9");
    trace_rec_3();
  }

  if(operand_2 == 7)
  {
    strcpy(a_string, "         JLL   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    src_line();
    if(puncde == 1)
    {
      strcpy(trace_1, "c2z_if.c case_47 #10");
      trace_rec_3();
    }
 
    strcpy(a_string, "         JLE   ");
    snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
    strcat(a_string, "L");
    strcat(a_string, wk_strg);
    src_line();
    if(puncde == 1)
    {
      strcpy(trace_1, "c2z_if.c case_47 #11");
      trace_rec_3();
    }
  }

  convert = 1;
  if_convert = 1;
  return;
}


