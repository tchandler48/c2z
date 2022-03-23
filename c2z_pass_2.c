/* ***************************************************
*  c2z : c2z_pass_2.c :                              *
*                                                    *
*  next error - pass2-062                            *
*  Copyright TCCS (c) 2015 - 2022                    *
**************************************************** */


void c2_pass_2_1()
{
   if (traceflg == 1) 
   {
     strcpy(trace_1, "c2z_pass_2.c c2_pass_2_1");
     trace_rec_1();
   }

   char ch;
   char field3[VAR_LGTH];
   char field3a[VAR_LGTH];

    int I;
    int s;
    int s1;
    int pi2;
    int size;

   I = 0;
   s = strlen(p_string);
   for(; I < s; I++)
   {
      ch = p_string[I];
      if(ch == '\'')
      {
         break;
      }
   }

   if(I >= s)			/* end of file */
   {
      convert = 1;
      return;
   }

   pi2 = 0;
   I++;
   ch = p_string[I];
   while(ch != '\'')
   {
      field3[pi2] = ch;
      pi2++;
      I++;
      ch = p_string[I];
   }
   field3[pi2] = '\0';

   s1 = strlen(field3);
   if(s1 == 1)
   {
      strcpy(field3a, field3);
   }
   else
   {
     if((field3[0] == '\\') && (field3[1] == '0'))
     {
        strcpy(field3a, field3);
     }
     else
     {
        field3a[0] = field3[1];
        field3a[1] = '\0';
     }
   }

   c_name++;
   snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
   strcpy(c_wkname, "C37F");
   strcat(c_wkname, wk_strg);
   s1 = strlen(c_wkname);
   c_wkname[s1] = '\0';

   size = 0;
   if (char_ct == 0) 
   {
     size = 1;
     w_charlit = malloc(size * sizeof(struct charlit));
   } 
   else 
   {
     size = char_ct + 1;
     w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
   }

   w_charlit[char_ct].clit_rct = rct;
   w_charlit[char_ct].clit_type = 3;
   strcpy(w_charlit[char_ct].clit_cname, c_wkname);
   strcpy(w_charlit[char_ct].clit_value, field3a);
   w_charlit[char_ct].clit_lgth = 1;
   w_charlit[char_ct].clit_uct = 1;
   char_ct++;

   I++;
   for(; I < s; I++)
   {
      ch = p_string[I];
      if(ch == '\'')
      {
         break;
      }
   }

   if(I >= s)			/* end of file */
   {
      convert = 1;
      return;
   }

   pi2 = 0;
   I++;
   ch = p_string[I];
   while(ch != '\'')
   {
      field3[pi2] = ch;
      pi2++;
      I++;
      ch = p_string[I];
   }
   field3[pi2] = '\0';

   if((field3[0] == '\\') && (field3[1] == '0'))
   {
      strcpy(field3a, field3);
   }
   else
   {
      field3a[0] = field3[1];
      field3a[1] = '\0';
   }

   c_name++;
   snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
   strcpy(c_wkname, "C37F");
   strcat(c_wkname, wk_strg);
   s1 = strlen(c_wkname);
   c_wkname[s1] = '\0';

   size = 0;
   if (char_ct == 0) 
   {
     size = 1;
     w_charlit = malloc(size * sizeof(struct charlit));
   } 
   else 
   {
     size = char_ct + 1;
     w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
   }

   w_charlit[char_ct].clit_rct = rct;
   w_charlit[char_ct].clit_type = 3;
   strcpy(w_charlit[char_ct].clit_cname, c_wkname);
   strcpy(w_charlit[char_ct].clit_value, field3a);
   w_charlit[char_ct].clit_lgth = 1;
   w_charlit[char_ct].clit_uct = 2;
   char_ct++;

   I++;
   for(; I < s; I++)
   {
      ch = p_string[I];
      if(ch == '\'')
      {
         break;
      }
   }

   if(I >= s)			/* end of file */
   {
      convert = 1;
      return;
   }

printf("\nc22_pass_2.c c2_pass_2_if  NONE rct = %d p_string = %s\n",rct,p_string);

   convert = 1;
   return;

}



void c2_pass_2_2()
{
   if (traceflg == 1) 
   {
     strcpy(trace_1, "c2z_pass_2.c c2_pass_2_2");
     trace_rec_1();
   }

   char ch;
   char field3[VAR_LGTH];
   char field3a[VAR_LGTH];

    int I;
    int s;
    int s1;
    int s2;
    int pi2;
    int size;

   s = 0;
   I = 0;
   s = strlen(p_string);
   for(; I < s; I++)
   {
      ch = p_string[I];
      if(ch == '\"')
      {
         break;
      }
   }

   if(I >= s)			/* end of file */
   {
      convert = 1;
      return;
   }

   pi2 = 0;
   I++;
   ch = p_string[I];
   while(ch != '\"')
   {
      field3[pi2] = ch;
      pi2++;
      I++;
      ch = p_string[I];
   }
   field3[pi2] = '\0';

   s2 = strlen(field3);
   if((field3[0] == '\\') && (field3[1] == '0'))
   {
      strcpy(field3a, field3);
   }
   else
   {
      if(s2 < 2)
      {
        field3a[0] = field3[1];
        field3a[1] = '\0';
      }
      else
      {
        strcpy(field3a,field3);
      }
   }

   c_name++;
   snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
   strcpy(c_wkname, "C37F");
   strcat(c_wkname, wk_strg);
   s1 = strlen(c_wkname);
   c_wkname[s1] = '\0';

   size = 0;
   if (char_ct == 0) 
   {
     size = 1;
     w_charlit = malloc(size * sizeof(struct charlit));
   } 
   else 
   {
     size = char_ct + 1;
     w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
   }

   w_charlit[char_ct].clit_rct = rct;
   w_charlit[char_ct].clit_type = 3;
   strcpy(w_charlit[char_ct].clit_cname, c_wkname);
   strcpy(w_charlit[char_ct].clit_value, field3a);
   w_charlit[char_ct].clit_lgth = s2;
   w_charlit[char_ct].clit_uct = 1;
   char_ct++;

   I++;
   for(; I < s; I++)
   {
      ch = p_string[I];
      if(ch == '\"')
      {
         break;
      }
   }

   if(I >= s)			/* end of file */
   {
      convert = 1;
      return;
   }

printf("c2z_pass_2 strcat NONE PROCESS  rct = %d p_string = %s\n",rct,p_string);

   convert = 1;
   return;
}



void c2_pass_2_3()
{
   if (traceflg == 1) 
   {
     strcpy(trace_1, "c2z_pass_2.c c2_pass_2_3");
     trace_rec_1();
   }

   char ch;
   char field3[VAR_LGTH];
   char field3a[VAR_LGTH];

    int I;
    int s;
    int s1;
    int s2;
    int s3;
    int pi2;
    int size;

   s = 0;
   I = 0;
   s = strlen(p_string);
   for(; I < s; I++)
   {
      ch = p_string[I];
      if(ch == '\"')
      {
         break;
      }
   }

   if(I >= s)			/* end of file */
   {
      convert = 1;
      return;
   }

   pi2 = 0;
   I++;
   ch = p_string[I];
   while(ch != '\"')
   {
      field3[pi2] = ch;
      pi2++;
      I++;
      ch = p_string[I];
   }
   field3[pi2] = '\0';

   s2 = strlen(field3);
   s3 = 1;
   c_name++;
   snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
   strcpy(c_wkname, "C37F");
   strcat(c_wkname, wk_strg);
   s1 = strlen(c_wkname);
   c_wkname[s1] = '\0';
   
   field3a[0] = field3[0];
   field3a[1] = '\0';

   size = 0;
   if (char_ct == 0) 
   {
     size = 1;
     w_charlit = malloc(size * sizeof(struct charlit));
   } 
   else 
   {
     size = char_ct + 1;
     w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
   }

   w_charlit[char_ct].clit_rct = rct;
   w_charlit[char_ct].clit_type = 3;
   strcpy(w_charlit[char_ct].clit_cname, c_wkname);
   strcpy(w_charlit[char_ct].clit_value, field3a);
   w_charlit[char_ct].clit_lgth = s2;
   w_charlit[char_ct].clit_uct = 1;
   char_ct++;

   s3++;

   if(s3 <= s2)
   {
     c_name++;
     snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
     strcpy(c_wkname, "C37F");
     strcat(c_wkname, wk_strg);
     s1 = strlen(c_wkname);
     c_wkname[s1] = '\0';
   
     field3a[0] = field3[1];
     field3a[1] = '\0';

     size = 0;
     if (char_ct == 0) 
     {
       size = 1;
       w_charlit = malloc(size * sizeof(struct charlit));
     } 
     else 
     {
       size = char_ct + 1;
       w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
     }

     w_charlit[char_ct].clit_rct = rct;
     w_charlit[char_ct].clit_type = 3;
     strcpy(w_charlit[char_ct].clit_cname, c_wkname);
     strcpy(w_charlit[char_ct].clit_value, field3a);
     w_charlit[char_ct].clit_lgth = s2;
     w_charlit[char_ct].clit_uct = 2;
     char_ct++;

     s3++;
  }

   if(s3 <= s2)
   {
     c_name++;
     snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
     strcpy(c_wkname, "C37F");
     strcat(c_wkname, wk_strg);
     s1 = strlen(c_wkname);
     c_wkname[s1] = '\0';
   
     field3a[0] = field3[2];
     field3a[1] = '\0';

     size = 0;
     if (char_ct == 0) 
     {
       size = 1;
       w_charlit = malloc(size * sizeof(struct charlit));
     } 
     else 
     {
       size = char_ct + 1;
       w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
     }

     w_charlit[char_ct].clit_rct = rct;
     w_charlit[char_ct].clit_type = 3;
     strcpy(w_charlit[char_ct].clit_cname, c_wkname);
     strcpy(w_charlit[char_ct].clit_value, field3a);
     w_charlit[char_ct].clit_lgth = s2;
     w_charlit[char_ct].clit_uct = 3;
     char_ct++;

     s3++;
   }

   if(s3 <= s2)
   {
     c_name++;
     snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
     strcpy(c_wkname, "C37F");
     strcat(c_wkname, wk_strg);
     s1 = strlen(c_wkname);
     c_wkname[s1] = '\0';
   
     field3a[0] = field3[3];
     field3a[1] = '\0';

     size = 0;
     if (char_ct == 0) 
     {
       size = 1;
       w_charlit = malloc(size * sizeof(struct charlit));
     } 
     else 
     {
       size = char_ct + 1;
       w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
     }

     w_charlit[char_ct].clit_rct = rct;
     w_charlit[char_ct].clit_type = 3;
     strcpy(w_charlit[char_ct].clit_cname, c_wkname);
     strcpy(w_charlit[char_ct].clit_value, field3a);
     w_charlit[char_ct].clit_lgth = s2;
     w_charlit[char_ct].clit_uct = 4;
     char_ct++;

     s3++;
   }

   if(s3 <= s2)
   {
     c_name++;
     snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
     strcpy(c_wkname, "C37F");
     strcat(c_wkname, wk_strg);
     s1 = strlen(c_wkname);
     c_wkname[s1] = '\0';
   
     field3a[0] = field3[4];
     field3a[1] = '\0';

     size = 0;
     if (char_ct == 0) 
     {
       size = 1;
       w_charlit = malloc(size * sizeof(struct charlit));
     } 
     else 
     {
       size = char_ct + 1;
       w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
     }

     w_charlit[char_ct].clit_rct = rct;
     w_charlit[char_ct].clit_type = 3;
     strcpy(w_charlit[char_ct].clit_cname, c_wkname);
     strcpy(w_charlit[char_ct].clit_value, field3a);
     w_charlit[char_ct].clit_lgth = s2;
     w_charlit[char_ct].clit_uct = 5;
     char_ct++;

     s3++;
   }

   if(s3 <= s2)
   {
     c_name++;
     snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
     strcpy(c_wkname, "C37F");
     strcat(c_wkname, wk_strg);
     s1 = strlen(c_wkname);
     c_wkname[s1] = '\0';
   
     field3a[0] = field3[5];
     field3a[1] = '\0';

     size = 0;
     if (char_ct == 0) 
     {
       size = 1;
       w_charlit = malloc(size * sizeof(struct charlit));
     } 
     else 
     {
       size = char_ct + 1;
       w_charlit = realloc(w_charlit, size * sizeof(struct charlit));
     }

     w_charlit[char_ct].clit_rct = rct;
     w_charlit[char_ct].clit_type = 3;
     strcpy(w_charlit[char_ct].clit_cname, c_wkname);
     strcpy(w_charlit[char_ct].clit_value, field3a);
     w_charlit[char_ct].clit_lgth = s2;
     w_charlit[char_ct].clit_uct = 6;
     char_ct++;

     s3++;
   }


   convert = 1;
   return;
}


/* ***************************************************
*  RETURN capture return variable                    *
* ************************************************** */
void c2_return_2() 
{
  if (traceflg == 1) 
  {
    strcpy(trace_1, "c2z_pass_2.c c2_return_2 START");
    trace_rec_1();
  }

  int I = 0;
  int ret = 0;
  int pi;
  int pi2;

  char ch;
  char *p1;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];

  field2[0] = '\0';

  pi = 0;
  ch = p_string[pi];
  while ((ch == ' ') || (ch == '\t') || (ch == '{')) 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    if(ch == ';')
    {
      break;
    }
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  p1 = strstr(field1, ";");
  if (!p1) 
  {
    pi2 = 0;
    pi++;
    ch = p_string[pi];
    while (ch != ';') 
    {
      field2[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field2[pi2] = '\0';

    if (fn_ct > 0) 
    {
      for (I = 0; I < fn_ct; I++) 
      {
        ret = strcmp(sv_func, w_function[I].fn_name);
        if (ret == 0) 
        {
          strcpy(w_function[I].fn_ret_var, field2);
        }
      }
    }
  }

  convert = 1;
}

