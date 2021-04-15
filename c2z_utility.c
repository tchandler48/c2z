/* ***************************************************
*  c2z : c2z_utility.c :                             *
*                                                    *
*  Copyright (c) 2015 - 2021                         *
**************************************************** */

void write_remark() 
{
  int x = 0;
  int I = 0;
  int s = 0;
  int s1 = 0;

  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  var_use[1]++;

  s = strlen(a_string);
  if (s < 40) 
  {
    x = 45 - s;

    for (I = 0; I < x; I++) 
    {
      strcat(a_string, " ");
    }

    s1 = strlen(wk_remark);
    if(s1 > 21)
    {
      wk_remark[21] = '\0';
    }

    strcat(a_string, "/* ");
    strcat(a_string, wk_remark);
  }

  s = strlen(a_string);
  if(s > 72)
  {
     s = 72;
  }
  if (s < 72) 
  {
    x = 72 - s;
    for (I = 0; I < x; I++) 
    {
      strcat(a_string, " ");
    }

    snprintf(tfield2, sizeof(wk_strg), "%d", var_use[1]);
    s = strlen(tfield2);

    if (s == 1) 
    {
      strcpy(tfield2a, "000000");
      strcat(tfield2a, tfield2);
    }

    if (s == 2) 
    {
      strcpy(tfield2a, "00000");
      strcat(tfield2a, tfield2);
    }

    if (s == 3) 
    {
      strcpy(tfield2a, "0000");
      strcat(tfield2a, tfield2);
    }

    if (s == 4) 
    {
      strcpy(tfield2a, "000");
      strcat(tfield2a, tfield2);
    }

    if (s == 5) 
    {
      strcpy(tfield2a, "00");
      strcat(tfield2a, tfield2);
    }

    if (s == 6) 
    {
      strcpy(tfield2a, "0");
      strcat(tfield2a, tfield2);
    }

    if (s == 7) 
    {
      strcpy(tfield2a, tfield2);
    }

    strcat(a_string, tfield2a);
  }

  strcat(a_string, "\n");
  fputs(a_string, cc370);
  fflush(cc370);
}

void src_line() 
{

  int s99;
  int x99;
  int I99;

  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  var_use[1]++;

  s99 = strlen(a_string);
  if (s99 < 72) 
  {
    x99 = 72 - s99;
    for (I99 = 0; I99 < x99; I99++) 
    {
      strcat(a_string, " ");
    }
  }

  snprintf(tfield2, sizeof(wk_strg), "%d", var_use[1]);
  s99 = strlen(tfield2);

  if (s99 == 1) 
  {
    strcpy(tfield2a, "000000");
    strcat(tfield2a, tfield2);
  }

  if (s99 == 2) 
  {
    strcpy(tfield2a, "00000");
    strcat(tfield2a, tfield2);
  }

  if (s99 == 3) 
  {
    strcpy(tfield2a, "0000");
    strcat(tfield2a, tfield2);
  }

  if (s99 == 4) 
  {
    strcpy(tfield2a, "000");
    strcat(tfield2a, tfield2);
  }

  if (s99 == 5) 
  {
    strcpy(tfield2a, "00");
    strcat(tfield2a, tfield2);
  }

  if (s99 == 6) 
  {
    strcpy(tfield2a, "0");
    strcat(tfield2a, tfield2);
  }

  if (s99 == 7) 
  {
    strcpy(tfield2a, tfield2);
  }

  strcat(a_string, tfield2a);

  strcat(a_string, "\n");
  fputs(a_string, cc370);
  fflush(cc370);
}

void write_variable() 
{
  int x = 0;
  int I = 0;
  int s = 0;

  s = strlen(a_string);
  x = 47 - s;

  for (I = 0; I < x; I++) 
  {
    strcat(a_string, " ");
  }

  strcat(a_string, "/* ");
  strcat(a_string, wk_remark);
  fputs(a_string, cc370);
  fflush(cc370);
}

void write_short() 
{
  int x = 0;
  int I = 0;
  int s = 0;
  int s99 = 0;
  int x99 = 0;
  int I99 = 0;

  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  var_use[1]++;

  s = strlen(a_string);
  x = 47 - s;

  for (I = 0; I < x; I++) 
  {
    strcat(a_string, " ");
  }

  strcat(a_string, "/* ");
  strcat(a_string, wk_remark);

  s99 = strlen(a_string);
  if (s99 < 72) 
  {
    x99 = 72 - s99;
    for (I99 = 0; I99 < x99; I99++) 
    {
      strcat(a_string, " ");
    }
  }

  snprintf(tfield2, sizeof(wk_strg), "%d", var_use[1]);
  s99 = strlen(tfield2);

  if (s99 == 1) 
  {
    strcpy(tfield2a, "000000");
    strcat(tfield2a, tfield2);
  }

  if (s99 == 2) 
  {
    strcpy(tfield2a, "00000");
    strcat(tfield2a, tfield2);
  }

  if (s99 == 3) 
  {
    strcpy(tfield2a, "0000");
    strcat(tfield2a, tfield2);
  }

  if (s99 == 4) 
  {
    strcpy(tfield2a, "000");
    strcat(tfield2a, tfield2);
  }

  if (s99 == 5) 
  {
    strcpy(tfield2a, "00");
    strcat(tfield2a, tfield2);
  }

  if (s99 == 6) 
  {
    strcpy(tfield2a, "0");
    strcat(tfield2a, tfield2);
  }

  if (s99 == 7) 
  {
    strcpy(tfield2a, tfield2);
  }

  strcat(a_string, tfield2a);

  strcat(a_string, "\n");
  fputs(a_string, cc370);
  fflush(cc370);
}

void check_blank(void) 
{
  char ch;

  int pi;

  while ((ch == ' ') || (ch == '\t')) 
  {
    pi++;
    ch = p_string[pi];
  }
}

void check_length(void) 
{
  int s = 0;

  s = strlen(a_string);

  if (s == 1)
    strcat(a_string, "        ");
  if (s == 2)
    strcat(a_string, "       ");
  if (s == 3)
    strcat(a_string, "      ");
  if (s == 4)
    strcat(a_string, "     ");
  if (s == 5)
    strcat(a_string, "    ");
  if (s == 6)
    strcat(a_string, "   ");
  if (s == 7)
    strcat(a_string, "  ");
  if (s == 8)
    strcat(a_string, " ");
}

void check_continuation() 
{
  int x = 0;
  int I = 0;
  int s = 0;

  s = strlen(a_string);
  x = 71 - s;

  for (I = 0; I < x; I++) 
  {
    strcat(a_string, " ");
  }

  strcat(a_string, "x");
}

void change_case() 
{
  char ch;

  int pi;
  int s = 0;

  pi = 0;
  s = strlen(p_string);
  for (; pi < s; pi++) 
  {
    ch = p_string[pi];
    if (ch >= 'a' && ch <= 'z') 
    {
      ch2 = ('A' + ch - 'a');
    } 
    else 
    {
      ch2 = ch;
    }
    a_string[pi] = ch2;
  }
  a_string[pi] = '\0';
  strcpy(p_string, a_string);
}

void verbose() 
{
  char v_string[90];
  int x = 0;
  int I = 0;
  int s = 0;

  strcpy(v_string, "Rct - ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(a_string, wk_strg);
  s = strlen(v_string);
  x = 10 - s;
  for (I = 0; I < x; I++) 
  {
    strcat(v_string, " ");
  }
  strcat(v_string, a_string);
  printf("%s", a_string);
}



void trace_rec_1() 
{
  char t_string[150];
  int x = 0;
  int I = 0;
  int s = 0;

  strcpy(t_string, trace_2);
  strcat(t_string, "  ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(t_string, wk_strg);
  s = strlen(t_string);
  x = 10 - s;
  for (I = 0; I < x; I++) 
  {
    strcat(t_string, " ");
  }
  strcat(t_string, trace_1);

  s = strlen(t_string);
  x = 70 - s;
  for (I = 0; I < x; I++) 
  {
    strcat(t_string, " ");
  }
  strcat(t_string, p_string);
  fprintf(c_src, "%s", t_string);
  fflush(c_src);
}

void trace_rec_2() 
{
  char t_string[150];
  int x = 0;
  int I = 0;
  int s = 0;

  strcpy(t_string, "\n");
  strcat(t_string, trace_2);
  strcat(t_string, "  ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(t_string, wk_strg);
  s = strlen(t_string);
  x = 10 - s;
  for (I = 0; I < x; I++) 
  {
    strcat(t_string, " ");
  }
  strcat(t_string, trace_1);
  s = strlen(t_string);
  x = 70 - s;
  for (I = 0; I < x; I++) 
  {
    strcat(t_string, " ");
  }
  strcat(t_string, p_string);

  fprintf(c_src, "%s", t_string);
  fflush(c_src);
}

void trace_rec_3() 
{
  char t_string[150];
  int x = 0;
  int I = 0;
  int s = 0;

  strcpy(t_string, trace_2);
  strcat(t_string, "  ");
  snprintf(wk_strg, sizeof(wk_strg), "%d", rct);
  strcat(t_string, wk_strg);
  s = strlen(t_string);
  x = 10 - s;
  for (I = 0; I < x; I++) 
  {
    strcat(t_string, " ");
  }
  strcat(t_string, trace_1);
  s = strlen(t_string);
  x = 42 - s;
  for (I = 0; I < x; I++) 
  {
    strcat(t_string, " ");
  }
  strcat(t_string, a_string);

  fprintf(c_src, "%s", t_string);
  fflush(c_src);
}

void c2_white() 
{

  char ch;

  int pi;

  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }
}

void c2_error() 
{
  printf("rct = %d p_string = %s", rct, p_string);
  c2_debug();
  exit(1);
}


void c2_count_bracket()
{
  int I, s;
  int x;
  char ch;

  x = 0;
  s = strlen(p_string);
  for(I=0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '{')
    {
      x++;
    }
    if(ch == ']')
    {
      x--;
    }
  }

  if(x != 0)
  {
    printf("Unbalanced [] in rct = %d p_string = %s",rct,p_string);
    c2_debug();
    exit(1);
  }
}


void c2_count_paren()
{
  int I, s;
  int x;
  char ch;

  x = 0;
  s = strlen(p_string);
  for(I=0; I < s; I++)
  {
    ch = p_string[I];
    if(ch == '(')
    {
      x++;
    }
    if(ch == ')')
    {
      x--;
    }
  }

  if(x != 0)
  {
    printf("Unbalanced () in rct = %d p_string = %s",rct,p_string);
    c2_debug();
    exit(1);
  }
}

void pgm_label() 
{
  int s = 0;
  int x;
  int x1;
  int I;

  char ch;
  char tmp_rct[6];

  s = strlen(p_string);

  x = 0;
  ch = p_string[x];
  while ((ch == ' ') || (p_string[x] == '\t'))
  {
    x++;
    ch = p_string[x];
  }

  x1 = 0;
  for(I = x; I < s; I++)
  {
    ch = p_string[I];
    o_string[x1] = ch;
    x1++;
  }
  o_string[x1] = '\0';

  snprintf(tmp_rct, sizeof(tmp_rct), "%d", rct);

  strcpy(a_string, "*  ");
  strcat(a_string, tmp_rct);
  strcat(a_string, "  ");
  strcat(a_string, o_string);
  s = strlen(a_string);
  if(s > 72)
  {
    a_string[71] = '\n';
    a_string[72] = '\0';
  }
 
  fputs(a_string, cc370);
  fflush(cc370);
}


