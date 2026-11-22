/* ***************************************************
*  c2z : c2z_goto.c                                  *
*                                                    *
*  Copyright TCCS (c) 2015 - 2026                    *
**************************************************** */

/* ***************************************************
*  Punch out goto statement                          *
* ************************************************** */
void c2_goto() 
{
  strcpy(trace_1, "c2z_goto c2_goto");
  trace_rec_1();

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  int pi;
  int pi2;
  int x3;
  int I;
  int ret;

  pi = 0;
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

  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ';') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(field1, w_gto_label[I].gto_org_lb);
    if (ret == 0) 
    {
      x3 = 1;
      strcpy(field1a, w_gto_label[I].gto_label_1);
    }
  }

  if(x3 == 0)
  {
     printf("error!!!");
  }

  strcpy(a_string, "         J     ");
  strcat(a_string, field1a);
  strcpy(wk_remark, " ");
  strcat(wk_remark, field1);
  strcat(wk_remark, " */");
  write_remark();
  strcpy(trace_1, "c2z_goto c2_goto #1");
  trace_rec_3();
  
  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_goto c2_goto #2");
  trace_rec_3();
  
  convert = 1;
}

/* **************************************************
*  Punch out goto label statement                   *
* ************************************************* */
void c2_goto_label() 
{
  strcpy(trace_1, "c2z_goto c2_goto_label");
  trace_rec_1();
  
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

  int pi;
  int pi2;
  int x3;
  int I;
  int ret;

  pi = 0;
  ch = p_string[pi];
  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  while (ch == '\t') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ':') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

  x3 = 0;
  for (I = 0; I < gv_ct; I++) 
  {
    ret = strcmp(field1, w_gto_label[I].gto_org_lb);
    if (ret == 0) 
    {
      x3 = 1;
      strcpy(field1a, w_gto_label[I].gto_label_1);
    }
  }

  if(x3 == 0)
  {
     printf("error!!!");
  }


  strcpy(a_string, field1a);
  check_length();
  strcat(a_string, "DS     0H");
  strcpy(wk_remark, " ");
  strcat(wk_remark, field1);
  strcat(wk_remark, " */");
  write_remark();
  strcpy(trace_1, "c2z_goto c2_goto_label #1");
  trace_rec_3();
  
  convert = 1;
}

/* ***************************************************
*  Punch out goto pass2 statement                    *
* ************************************************** */
void c2_goto_pass2() 
{
  strcpy(trace_1, "c2z_goto c2_goto_pass2");
  trace_rec_1();

  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  
  int pi;
  int pi2;
  int x3;
  int I;
  int ret;
  int s;
  int size;

  pi = 0;
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

  while (ch == ' ') 
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while (ch != ';') 
  {
    field1[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field1[pi2] = '\0';

 
  x3 = 0;
  for (I = 0; I < w_gtolabel_ct; I++) 
  {
    ret = strcmp(field1, w_gto_label[I].gto_org_lb);
    if (ret == 0) 
    {
      x3 = 1;
      strcpy(field1a, w_gto_label[I].gto_label_1);
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

    if (w_gtolabel_ct == 0) 
    {
      size = 1;
      w_gto_label = malloc(size * sizeof(struct gto_label));
    } 
    else 
    {
      size = w_gtolabel_ct + 1;
       w_gto_label = realloc(w_gto_label, size * sizeof(struct gto_label));
    }
    w_gto_label[w_gtolabel_ct].gto_label_rct = rct;
    strcpy(w_gto_label[w_gtolabel_ct].gto_org_lb, field1);
    strcpy(w_gto_label[w_gtolabel_ct].gto_label_1, field1a);
    w_gtolabel_ct++;
    convert = 1;
  }
  convert = 1;
}


/* ***************************************************
*  Pass2 goto label statement                    *
* ************************************************** */
void c2_goto_pass2_label() 
{
  strcpy(trace_1, "c2z_goto c2_goto_pass2_label");
  trace_rec_1();

/*
struct gto_label 
{
   int gto_label_rct;
  char gto_org_lb[VAR_LGTH];
  char gto_label_1[VAR_LGTH];
};
struct gto_label *w_gto_label;
int w_gtolabel_ct = 0;

*/
  convert = 1;
}

