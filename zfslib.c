
/*  fslib.c                                          */

#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void c2_fs_1(void);
void c2_fs_2(void);
void c2_fs_3(void);
void c2_fs_4(void);
void c2_fs_5(void);
void c2_fs_6(void);
void src_line(void);
void write_remark(void);
void check_length(void); 

FILE *pgm;
FILE *mlc;
FILE *f_in;
FILE *f_out;

#define BUFSIZE    128
#define VAR_LGTH    32

  char ch;
  char *p;
  char p_string[128];
  char a_string[128];
  char filename[18];
  char wk_strg[6];
  char c_wkname[8];
  char sv_func[12];
  char wk_remark[22];
  char w_address[5];
  char null_field[2];


  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field4[VAR_LGTH];
  char tfield4[VAR_LGTH];


  int rct;
  int convert;
  int traceflg;
  int c_name;
  int s;
  int global_st;
  int erct;
  int var_use;
  int I;
  int x;
  int x3;
  int x4;
  int x5;
  int x7;
  int x97;
  int x98;
  int ret;
  int ret1;
  int v;
  int k1;
  int k;
  int p_ct;
  int II;


  int lv_ct;
  int gv_ct;
  int w_lgth = 0;

  int fs_map_ct = 0;
  int fs_field_ct = 0;
  int T3270_ct = 0;
  int fsaid_ct = 0;
  int scr_loop_ct = 0;
  int goto_label_ct = 0;

 char T3270[1922][5];


struct var 
{
   int lv_rct;
  char lv_name[VAR_LGTH];
  char lv_cname[9];
  char lv_func[VAR_LGTH];
  char lv_type[2];
   int lv_lgth;
   int lv_current_lgth;
  char lv_value[VAR_LGTH];
   int lv_init;
  char lv_literal[BUFSIZE];
   int lv_use_ct;
   int lv_dec;
   int lv_id;
};
struct var *lw_variable;

struct fs_map
{
    int fs_rct;
   char fs_name[VAR_LGTH];
   char fs_cname[VAR_LGTH];
};
struct fs_map *w_fs_map;


struct fs_field
{
   int fs_fd_rct;
  char fs_fd_map[VAR_LGTH];
  char fs_fd_name[VAR_LGTH];
  char fs_fd_cname[VAR_LGTH];
  char fs_fd_io[2];
  char fs_fd_type[2];
  char fs_fd_field[VAR_LGTH];  
   int fs_fd_row;		   
   int fs_fd_col;	
   int fs_fd_lgth;	   
  char fs_fd_color[VAR_LGTH];
  char fs_fd_address[5];
  char fs_fd_attr[3];
};
struct fs_field *w_fs_field;

struct fs_scr_field
{
   char fs_scr_map[VAR_LGTH];
   char fs_scr_name[VAR_LGTH];
   char fs_scr_cname[VAR_LGTH];
};
struct fs_scr_field *w_fs_scr_field;

struct fs_fsaid
{
   char fs_fsaid_map[VAR_LGTH];
   char fs_fsaid_attr[VAR_LGTH];
   char fs_fsaid_label[VAR_LGTH];
};
struct fs_fsaid *w_fs_fsaid;

struct goto_label 
{
   int goto_label_rct;
  char goto_org_lb[VAR_LGTH];
  char goto_label_1[VAR_LGTH];
};
struct goto_label *w_goto_label;


int main(int argc, char *argv[]) 
{

  if(argc > 2)
  {
     printf("ERROR\n");
  }
  
  c2_fs_5();
  null_field[0] = '\0';

  strcpy(filename, argv[1]);

  pgm = fopen(filename, "rb");

  mlc = fopen("HELLO1.TMP", "w");

  while (1) 
  {
    if (feof(pgm)) 
    {
      break;
    }

    fgets(p_string, BUFSIZE, pgm);
    rct++;

    if(p_string[0] == '*')
    {
       fputs(p_string, mlc);
       goto read_on;
    }

    p = strstr(p_string, "fsdefine");
    if(!p)
    {
      p = strstr(p_string, "FSDEFINE");
    }
    if(p)
    {
      c2_fs_1();
      goto read_on;
    }

    p = strstr(p_string, "fsfield");
    if(!p)
    {
      p = strstr(p_string, "FSFIELD");
    }
    if(p)
    {
      c2_fs_2();
      goto read_on;
    }

    fputs(p_string, mlc);

read_on:

    I++;
 
  }

  fclose (pgm);
  fclose (mlc);

  f_in = fopen("HELLO1.TMP", "r");

  f_out = fopen("HELLO1.MLC", "w");


  while(!feof(f_in))
  {
    fgets(p_string, BUFSIZE, f_in);
    rct++;

    if(p_string[0] == '*')
    {
       fputs(p_string, f_out);
       goto pass2_on;
    }

    p = strstr(p_string, "fsdisplay");
    if(!p)
    {
      p = strstr(p_string, "FSDISPLAY");
    }
    if(p)
    {
      c2_fs_3();
      goto pass2_on;
    }

    p = strstr(p_string, "fsread");
    if(!p)
    {
      p = strstr(p_string, "FSREAD");
    }
    if(p)
    {
      c2_fs_4();
      goto pass2_on;
    }

    p = strstr(p_string, "end");
    if(!p)
    {
      p = strstr(p_string, "END");
    }
    if(p)
    {
      if(fs_field_ct > 0)
      {
        for(II = 0; II < fs_field_ct; II++)
        {
/*
      printf("\nfs_fd_rct = %d\n",w_fs_field[II].fs_fd_rct);
      printf("fs_fd_map = %s\n",w_fs_field[II].fs_fd_map);
      printf("fs_fd_color = %s\n",w_fs_field[II].fs_fd_color);
*/

        }
      }

      strcpy(a_string, "*");
      src_line();


      if(fs_map_ct > 0)
      {
        x3 = 0;
        I = 0;
        for (; I < fs_map_ct; I++) 
        {
          p_ct = 0;
          strcpy(a_string, w_fs_map[I].fs_name);
          strcat(a_string, "O");
          check_length();
          strcat(a_string, " DS    0C");
          src_line();

          strcpy(a_string, "          DC    X'27'");
          strcpy(wk_remark, " ");
          strcat(wk_remark, "ESCAPE CHAR");
          strcat(wk_remark, " ");
          write_remark();
     
          strcpy(a_string, "          DC    X'F1'");
          strcpy(wk_remark, " ");
          strcat(wk_remark, "ERASE/WRITE");
          strcat(wk_remark, " ");
          write_remark();
     
          strcpy(a_string, "          DC    X'C3'");
          strcpy(wk_remark, " ");
          strcat(wk_remark, "WCC");
          strcat(wk_remark, " ");
          write_remark();
     
          strcpy(a_string, "          DC    X'114040'");
          strcpy(wk_remark, " ");
          strcat(wk_remark, "CLEAR SCR");
          strcat(wk_remark, " ");
          write_remark();
      
          strcpy(a_string, "          DC    X'3C4040'");
          strcpy(wk_remark, " ");
          strcat(wk_remark, "CLEAR SCR");
          strcat(wk_remark, " ");
          write_remark();
      
          strcpy(a_string, "          DC    C' '");
          strcpy(wk_remark, " ");
          strcat(wk_remark, "CLEAR SCR");
          strcat(wk_remark, " ");
          write_remark();
      
          strcpy(a_string, "          DC    X'1140401DF0'");
          strcpy(wk_remark, " ");
          strcat(wk_remark, "WCC");
          strcat(wk_remark, " ");
          write_remark();

          strcpy(a_string, "          DC    X'1DF8'");
          strcpy(wk_remark, " ");
          strcat(wk_remark, "WCC");
          strcat(wk_remark, " ");
          write_remark();
      
          x97 = 17;

          while(p_ct < fs_field_ct)
          {
            x7 = 0;
            ret =  strcmp(w_fs_field[p_ct].fs_fd_map, w_fs_map[I].fs_name);
            if(ret == 0)
            {

              strcpy(tfield4, w_fs_field[p_ct].fs_fd_field);
              strcpy(w_address, w_fs_field[p_ct].fs_fd_address);
              x7 = 1;
            }
 
            if(x7 == 1)
            {
              strcpy(a_string, "          DC    X'11");
              strcat(a_string, w_address);
              strcat(a_string, "'");
              strcpy(wk_remark, " ");
              strcat(wk_remark, "SBA");
              strcat(wk_remark, " ");
              write_remark();
              x97 = x97 + 3;

              ret = strcmp(w_fs_field[p_ct].fs_fd_io, "O");
              if(ret == 0)
              {
                strcpy(a_string, "          DC    X'1DF0'");
                strcpy(wk_remark, " ");
                strcat(wk_remark, "SF START FIELD");
                strcat(wk_remark, " ");
                write_remark();
                x97 = x97 + 2;
              }

              ret = strcmp(w_fs_field[p_ct].fs_fd_io, "I");
              if(ret == 0)
              {
                strcpy(a_string, "          DC    X'1D40'");
                strcpy(wk_remark, " ");
                strcat(wk_remark, "BASIC = UNPROTECTED");
                strcat(wk_remark, " ");
                write_remark();
                x97 = x97 + 2;
              }

              ret =  strcmp(w_fs_field[p_ct].fs_fd_attr, "IC");
              if(ret == 0)
              {
                strcpy(a_string, "          DC    X'13'");
                strcpy(wk_remark, " ");
                strcat(wk_remark, "IC");
                strcat(wk_remark, " ");
                write_remark();
                x97++;
              }

              ret = strcmp(w_fs_field[p_ct].fs_fd_io, "I");
              if(ret == 0)
              {
                strcpy(a_string, "          DC    X'05'");
                strcpy(wk_remark, " ");
                strcat(wk_remark, "TAB");
                strcat(wk_remark, " ");
                write_remark();
                x97 = x97 + 1;
              }

              ret = strcmp(w_fs_field[p_ct].fs_fd_color, "DEFAULT");
              if(ret == 0)
              {
                strcpy(a_string, "          DC    X'284200'");
                strcpy(wk_remark, " ");
                strcat(wk_remark, "DEFAULT");
                strcat(wk_remark, " ");
                write_remark();
                x97 = x97 + 3;
              }

              ret = strcmp(w_fs_field[p_ct].fs_fd_color, "BLUE");
              if(ret == 0)
              {
                strcpy(a_string, "          DC    X'2842F1'");
                strcpy(wk_remark, " ");
                strcat(wk_remark, "BLUE");
                strcat(wk_remark, " ");
                write_remark();
                x97 = x97 + 3;
              }

              ret = strcmp(w_fs_field[p_ct].fs_fd_color, "RED");
              if(ret == 0)
              {
                strcpy(a_string, "          DC    X'2842F2'");
                strcpy(wk_remark, " ");
                strcat(wk_remark, "RED");
                strcat(wk_remark, " ");
                write_remark();
                x97 = x97 + 3;
              }

              ret = strcmp(w_fs_field[p_ct].fs_fd_color, "PINK");
              if(ret == 0)
              {
                strcpy(a_string, "          DC    X'2842F3'");
                strcpy(wk_remark, " ");
                strcat(wk_remark, "PINK");
                strcat(wk_remark, " ");
                write_remark();
                x97 = x97 + 3;
              }

              ret = strcmp(w_fs_field[p_ct].fs_fd_color, "GREEN");
              if(ret == 0)
              {
                strcpy(a_string, "          DC    X'2842F4'");
                strcpy(wk_remark, " ");
                strcat(wk_remark, "GREEN");
                strcat(wk_remark, " ");
                write_remark();
                x97 = x97 + 3;
              }

              ret = strcmp(w_fs_field[p_ct].fs_fd_color, "TURQUOISE");
              if(ret == 0)
              {
                strcpy(a_string, "          DC    X'2842F5'");
                strcpy(wk_remark, " ");
                strcat(wk_remark, "TURQUOISE");
                strcat(wk_remark, " ");
                write_remark();
                x97 = x97 + 3;
              }

              ret = strcmp(w_fs_field[p_ct].fs_fd_color, "YELLOW");
              if(ret == 0)
              {
                strcpy(a_string, "          DC    X'2842F6'");
                strcpy(wk_remark, " ");
                strcat(wk_remark, "YELLOW");
                strcat(wk_remark, " ");
                write_remark();
                x97 = x97 + 3;
              }

              ret = strcmp(w_fs_field[p_ct].fs_fd_color, "WHITE");
              if(ret == 0)
              {
                strcpy(a_string, "          DC    X'2842F7'");
                strcpy(wk_remark, " ");
                strcat(wk_remark, "WHITE");
                strcat(wk_remark, " ");
                write_remark();
                x97 = x97 + 3;
              }

              ret = strcmp(w_fs_field[p_ct].fs_fd_type, "L");
              if(ret == 0)
              {
                k1 = 0;
                k = 0;
                ch = w_fs_field[p_ct].fs_fd_field[k];
                while(ch != '\0')
                {
                  k1++;
                  k++;
                  ch = w_fs_field[p_ct].fs_fd_field[k];
                }
                x97 = x97 + k1;
 
                strcpy(a_string, "          DC    C'");
                strcat(a_string, w_fs_field[p_ct].fs_fd_field);
                strcat(a_string, "'");
                src_line();
              }

              ret = strcmp(w_fs_field[p_ct].fs_fd_type, "C");
              if(ret == 0)
              {
                if(x97 % 2 == 0)
                {
               
                }
                else
                {
                  strcpy(a_string, "          DC    C' '");
                  src_line();
                  x97++;
                }

                strcpy(field1, w_fs_field[p_ct].fs_fd_map);           
                strcpy(field2, w_fs_field[p_ct].fs_fd_field);
printf("\nfs_1 #1 eoj inside type C field1 = %s field2 = %s\n",field1,field2);

                for(v = 0; v < T3270_ct; v++)
                {
                  ret = strcmp(field1, w_fs_scr_field[v].fs_scr_map);
                  ret1 = strcmp(field2, w_fs_scr_field[v].fs_scr_name);
                  if((ret == 0) && (ret1 == 0))
                  {
                    strcpy(field4, w_fs_scr_field[v].fs_scr_cname);
                    break;
                  }
                }
printf("\nfs_1 #2 eoj inside type C field1 = %s field2 = %s field4 = %s\n",field1,field2,field4);

                strcpy(field1, w_fs_field[p_ct].fs_fd_field);
printf("fs_1 #3 field1 = %s\n",field1);
                x3 = 0;
                for (v = 0; v < lv_ct; v++) 
                {
                  ret = strcmp(field1, lw_variable[v].lv_name);
                  if(ret == 0)
                  {
                    strcpy(field1a, lw_variable[v].lv_cname);
                    x5 = lw_variable[v].lv_lgth;
                    x3 = 1;
                    x98 = lw_variable[v].lv_id;
                    break;
                  }
                }
printf("fs_1 #4 field4 = %s field1 = %s field1a = %s x98 = %d x3 = %d \n",field4,field1,field1a,x98,x3);
     
              if(x98 == 1)
              {
                x5 = 10;
              }

              if(x97 % 2 == 0)
              {
             
              }
              else
              {
                strcpy(a_string, "          DC    C' '");
                src_line();
              }

              strcpy(a_string, field4);
              check_length();
              strcat(a_string, " DC    CL");
              snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
              strcat(a_string, wk_strg);
              strcat(a_string, "' '");
              src_line();
              x97 = x97 + x5;

              strcpy(a_string, "          DC    X'1DF0'");
              strcpy(wk_remark, " ");
              strcat(wk_remark, "SF END FIELD");
              strcat(wk_remark, " ");
              write_remark();
              x97 = x97 + 2;
            }

          } 	 /* if(x7 == 1)  */

            x7 = 0;
            p_ct++;


          }   /* while(p_ct < fs_field_ct) */

          strcpy(a_string, w_fs_map[I].fs_name);
          strcat(a_string, "OL ");
          check_length();
          strcat(a_string, " EQU   *-");
          strcat(a_string, w_fs_map[I].fs_name);
          strcat(a_string, "O");
          src_line();
      
          strcpy(a_string, "*");
          src_line();

          if(x97 % 2 == 0)
          {
             
          }
          else
          {
            strcpy(a_string, "          DC    C' '");
            src_line();
          }

          strcpy(a_string, w_fs_map[I].fs_name);
          strcat(a_string, "I");
          check_length();
          strcat(a_string, " DS    XL1930");
          src_line();
           
          strcpy(a_string, w_fs_map[I].fs_name);
          strcat(a_string, "IL ");
          check_length();
          strcat(a_string, " EQU   *-");
          strcat(a_string, w_fs_map[I].fs_name);
          strcat(a_string, "I");
          src_line();
      
          strcpy(a_string, "*");
          src_line();
         
        }	/* for (; I < fs_map_ct; I++) */

      }	/* if(fs_map_ct > 0) */
 
    }		/* if(p) */
 
    p = strstr(p_string, "END");
    if(!p)
    {
      s = strlen(p_string);
      if(s > 2)
      {
        fputs(p_string, f_out);
      }
    }

pass2_on:


    I++;

  }		/* while(1) */


  for (I = 0; I < lv_ct; I++) 
  {
    ret = strcmp(lw_variable[I].lv_type, "C");
    if (ret == 0) 
    {
      if (lw_variable[I].lv_lgth % 2 == 0) 
      {
      }
      else 
      {
        strcpy(a_string, "          DS    0H");
        src_line();
      }

      strcpy(wk_strg, lw_variable[I].lv_cname);
      strcpy(field1, lw_variable[I].lv_cname);
      strcpy(a_string, field1);
      check_length();
      strcat(a_string, " DC    ");
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
      x = 33 - s;
      for (x4 = 0; x4 < x; x4++) 
      {
        strcat(a_string, " ");
      }
      strcat(a_string, "/* ");
      strcat(a_string, lw_variable[I].lv_name);
      strcat(a_string, "  - ");
      snprintf(wk_strg, sizeof(wk_strg), "%d", lw_variable[I].lv_rct);
      strcat(a_string, wk_strg);
      strcat(a_string, "  */");
      src_line();

 
    }
  }

  strcpy(p_string, "          END");
  fputs(p_string, f_out);



  fclose(f_in);
  fclose(f_out);

  exit(0);
}


void c2_fs_1(void)
{
  char ch;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];

   int pi;
   int pi2;
   int size;
   int s;

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

   c_name++;
   snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
   strcpy(c_wkname, "C37F");
   strcat(c_wkname, wk_strg);
   s = strlen(c_wkname);
   c_wkname[s] = '\0';
   strcpy(field1a, c_wkname);

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


void c2_fs_2(void)
{
  char ch;
  char *p;
  char field1[VAR_LGTH];
  char field1a[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];
  char field4[VAR_LGTH];
  char field5[VAR_LGTH];
  char field6[VAR_LGTH];
  char field7[VAR_LGTH];
  char field8[VAR_LGTH];
  char field9[VAR_LGTH];
  char field10[VAR_LGTH];
  char field11[VAR_LGTH];

   int pi;
   int pi2;
   int s;
   int size;
   int tadd = 0;
   int w_row = 0;
   int w_col = 0;
   int ret2;
 
  pi = 0;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    pi++;
    ch = p_string[pi];
  }

field_loop:
  
  fgets(p_string, BUFSIZE, pgm);
  rct++;

  p = strstr(p_string, "{");
  if(p)
  {
    goto field_loop;
  }

  pi = 0;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != '(')
  {
    field10[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field10[pi2] = '\0';

  p = strstr(field10, "fsmap");
  if(p)
  {
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while(ch != ')')
    {
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';
    strcpy(field1,field11);
    goto field_end;
  }
  
  p = strstr(field10, "fsio");
  if(p)
  {
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while(ch != ')')
    {
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';
    strcpy(field2,field11);
    goto field_end;
  }

  p = strstr(field10, "fstype");
  if(p)
  {
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while(ch != ')')
    {
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';
    strcpy(field3,field11);
    goto field_end;
  }

  p = strstr(field10, "fsname");
  if(p)
  {
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while(ch != ')')
    {
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';
    strcpy(field4,field11);
    goto field_end;
  }

  p = strstr(field10, "fsloc");
  if(p)
  {
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while(ch != ',')
    {
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';
    w_row = atoi(field11);
    strcpy(field5,field11);

    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while(ch != ')')
    {
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';
    w_col = atoi(field11);
    strcpy(field6,field11);
 
    if(w_row == 1)
    { 
      tadd = w_col;
    }
    if(w_row > 1)
    {
      tadd = ((w_row - 1) * 80)  + w_col;
    }

    goto field_end;
  }

  p = strstr(field10, "fscolor");
  if(p)
  {
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while(ch != ')')
    {
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';
    strcpy(field7,field11);
    goto field_end;
  }

  p = strstr(field10, "fsattr");
  if(p)
  {
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while(ch != ')')
    {
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';
    strcpy(field9,field11);
    goto field_end;
  }

  p = strstr(field10, "fslgth");
  if(p)
  {
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while(ch != ')')
    {
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';
    w_lgth = atoi(field11);
    strcpy(field9,field11);
    goto field_end;
  }



field_end:

  p = strstr(p_string, "};");
  if(!p)
  {
     goto field_loop;
  }


printf("\nc2z_fs.c fs_2 rct = %d p_string = %s",rct,p_string);
printf("c2z_fs.c fs_2 rct = %d MAP_NAME field1 = %s\n",rct,field1);
printf("c2z_fs.c fs_2 rct = %d IN/OUT field2 = %s\n",rct,field2);
printf("c2z_fs.c fs_2 rct = %d TYPE field3 = %s\n",rct,field3);
printf("c2z_fs.c fs_2 rct = %d FD_NAME/LITERAL field4 = %s\n",rct,field4);
printf("c2z_fs.c fs_2 rct = %d ROW field5 = %s\n",rct,field5);
printf("c2z_fs.c fs_2 rct = %d COL field6 = %s\n",rct,field6);
printf("c2z_fs.c fs_2 rct = %d LGTH w_lgth = %d\n",rct,w_lgth);
printf("c2z_fs.c fs_2 rct = %d COLOR field7 = %s\n",rct,field7);
printf("c2z_fs.c fs_2 rct = %d TADD = %d\n",rct,tadd);
printf("c2z_fs.c fs_2 rct = %d T3270 = %s\n",rct,T3270[tadd]);


  c_name++;
  snprintf(wk_strg, sizeof(wk_strg), "%d", c_name);
  strcpy(c_wkname, "C37F");
  strcat(c_wkname, wk_strg);
  s = strlen(c_wkname);
  c_wkname[s] = '\0';
  strcpy(field1a, c_wkname);

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
  strcpy(w_fs_field[fs_field_ct].fs_fd_attr, field9);
  w_fs_field[fs_field_ct].fs_fd_lgth = w_lgth;
  fs_field_ct++;

  field9[0] = '\0';
   
  if(field3[0] == 'C')
  {
printf("fs_2 #88 field3 = %s\n",field3);

    size = 0;
    if (T3270_ct == 0) 
    {
      size = 1;
      w_fs_scr_field = malloc(size * sizeof(struct fs_scr_field));
    } 
    else 
    {
      size = T3270_ct + 1;
      w_fs_scr_field = realloc(w_fs_scr_field, size * sizeof(struct fs_scr_field));
    }
    strcpy(w_fs_scr_field[T3270_ct].fs_scr_map, field1);
    strcpy(w_fs_scr_field[T3270_ct].fs_scr_name, field4);
    strcpy(field8,"T3270_");
    snprintf(wk_strg, sizeof(wk_strg), "%d", T3270_ct);
    strcat(field8, wk_strg);
    strcpy(w_fs_scr_field[T3270_ct].fs_scr_cname, field8);
    T3270_ct++;
  

printf("fs_2 field1 = %s field1a = %s\n",field1,field1a);

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
    strcpy(lw_variable[lv_ct].lv_name, field4);
    strcpy(lw_variable[lv_ct].lv_cname, field1a);
    strcpy(lw_variable[lv_ct].lv_type, "C");
    lw_variable[lv_ct].lv_lgth = w_lgth;
    lw_variable[lv_ct].lv_current_lgth = w_lgth;
    strcpy(lw_variable[lv_ct].lv_value, null_field);
    lw_variable[lv_ct].lv_init = 0;
    strcpy(lw_variable[lv_ct].lv_literal, null_field);
    lw_variable[lv_ct].lv_use_ct = 0;
    lw_variable[lv_ct].lv_dec = 0;
    lw_variable[lv_ct].lv_id = 3;
    lv_ct++;
  }

  w_lgth = 0;
  convert = 1;
}



void c2_fs_3(void)
{
  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field8[VAR_LGTH];

   int pi;
   int pi2;
   int x3;
   int p_ct = 0;
   int ret;
   int ret1;
   int v;
   int x5;
   int x99;
   int x7;
   int x98;

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

  strcpy(field2, field1);
  strcat(field2, "OL");

  if(fs_map_ct > 0)
  {
    x3 = 0;
    p_ct = 0;

    while(p_ct < fs_field_ct)
    {
      x7 = 0;

      ret =  strcmp(w_fs_field[p_ct].fs_fd_map, field1);
      ret1 = strcmp(w_fs_field[p_ct].fs_fd_type, "V");
      if((ret == 0) && (ret1 == 0))
      {
         strcpy(field4, w_fs_field[p_ct].fs_fd_field);
         x7 = 1;
      }

      if(x7 == 1)
      {
        ret = strcmp(w_fs_field[p_ct].fs_fd_type, "V");
        if(ret == 0)
        {
          x3 = 0;
          for (v = 0; v < lv_ct; v++) 
          {
            ret = strcmp(field4, lw_variable[v].lv_name);
            if (ret == 0) 
            {
              strcpy(field4a, lw_variable[v].lv_cname);
              x5 = lw_variable[v].lv_current_lgth;
              x98 = lw_variable[v].lv_lgth;
              x99 = lw_variable[v].lv_id;
              x3 = 1;
              break;
            }
          }

          if (x3 == 0) 
          {
            printf("\nc2z_fs.c c2_fs_2_2 fs_2-001 field4 Not Found = %s\n", field4);
            printf("c2z_fs.c c2_fs_2_2 rct = %d p_string = %s", rct, p_string);
            erct++;
            convert = 1;
            return;
          }

          for(v = 0; v < T3270_ct; v++)
          {
            ret = strcmp(field4, w_fs_scr_field[v].fs_scr_name);
            ret1 = strcmp(field1, w_fs_scr_field[v].fs_scr_map);
            if((ret == 0) && (ret1 == 0))
            {
              strcpy(field8, w_fs_scr_field[v].fs_scr_cname);
              break;
            }
          }
     
          if(x99 == 3)
          {
            strcpy(a_string, "         LARL  R9,");
            strcat(a_string, field8);
            src_line();
 
            strcpy(a_string, "         LARL  R8,C370B1");
            src_line();
 
            strcpy(a_string, "         MVC   0(1,R9),0(R8)");
            src_line();

            strcpy(a_string, "         MVC   1(");
            x98--;
            snprintf(wk_strg, sizeof(wk_strg), "%d", x98);
            strcat(a_string, wk_strg);
            strcat(a_string, ",R9),0(R9)");
            src_line();
 
            ret = strcmp(w_fs_field[p_ct].fs_fd_io, "O");
            if(ret == 0)
            {
              strcpy(a_string, "         LARL  R9,");
              strcat(a_string, field4a);
              strcpy(wk_remark, " ");
              strcat(wk_remark, field4);
              strcat(wk_remark, " ");
              write_remark();
             
              strcpy(a_string, "         LARL  R8,");
              strcat(a_string, field8);
              src_line();
               
              strcpy(a_string, "         MVC   0(");
              snprintf(wk_strg, sizeof(wk_strg), "%d", x98);
              strcat(a_string, wk_strg);
              strcat(a_string, ",R8),0(R9)");
              src_line();
            }

            ret = strcmp(w_fs_field[p_ct].fs_fd_io, "C");
            if(ret == 0)
            {
              strcpy(a_string, "         LARL  R9,");
              strcat(a_string, field4a);
              strcpy(wk_remark, " ");
              strcat(wk_remark, field4);
              strcat(wk_remark, " ");
              write_remark();
             
              strcpy(a_string, "         LARL  R8,");
              strcat(a_string, field8);
              src_line();
          
              strcpy(a_string, "         MVC   0(");
              snprintf(wk_strg, sizeof(wk_strg), "%d", x98);
              strcat(a_string, wk_strg);
              strcat(a_string, ",R8),0(R9)");
              src_line();
            }
          }

          if(x99 == 1)
          {
             strcpy(a_string, "         LARL  R9,C370EDN");
             src_line();
             
             strcpy(a_string, "         LARL  R8,");
             strcat(a_string, field4a);
             src_line();
             
             strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
             src_line();
             
             strcpy(a_string, "         LARL  R15,WTOIMVC");
             src_line();
             
             strcpy(a_string, "         BAKR  0,R15");
             src_line();
             
             strcpy(a_string, "         LARL  R9,C370L10");
             src_line();
             
             strcpy(a_string, "         LARL  R8,");
             strcat(a_string, field8);
             src_line();
             
             x5 = 10;
             strcpy(a_string, "         MVC   0(");
             snprintf(wk_strg, sizeof(wk_strg), "%d", x5);
             strcat(a_string, wk_strg);
             strcat(a_string, ",R8),0(R9)");
             src_line();
          }
        }
      }
      p_ct++;
      x7 = 0;
    }
  }

  strcpy(a_string, "         TPUT  ");
  strcat(a_string, field1);
  strcat(a_string, "O");
  strcat(a_string, ",");
  strcat(a_string, field2);
  strcat(a_string, ",FULLSCR");
  src_line();

}


void c2_fs_4(void)
{
  char ch;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field4[VAR_LGTH];
  char field4a[VAR_LGTH];
  char field8[VAR_LGTH];

   int pi;
   int pi2;
   int I;
   int J;
   int x3;
   int ret;
   int ret1;
   int ret2;
   int p_ct;
   int x7;
   int v;
   int x98;
   int x99;
   int i_in = 0;

  pi = 0;
  ch = p_string[pi];
  while(ch != '(')
  {
    pi++;
    ch = p_string[pi];
  }

  pi++;
  ch = p_string[pi];
  pi2 = 0;
  while(ch != ')')
  {
    field1[pi2] = ch;
    pi2++;
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
  strcat(a_string, ",ASIS,WAIT"); 
  src_line();

  for(I = 0; I < fsaid_ct; I++)
  {
    if(strcmp(w_fs_fsaid[I].fs_fsaid_map, field1) == 0)
    {
      if(strcmp(w_fs_fsaid[I].fs_fsaid_attr, "PF1") == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1);
        strcat(a_string, "I");
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, "PF1");
        src_line();

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();

        x3 = 0;
        for(J = 0; J < goto_label_ct; J++)
        {
          ret = strcmp(w_goto_label[J].goto_org_lb, w_fs_fsaid[I].fs_fsaid_label);
          if(ret == 0)
          {
            strcpy(wk_strg, w_goto_label[J].goto_label_1);
            x3 = 1;
          }
        }
   
        if(x3 == 0)
        {
          printf("\nc2z_fs.c c2_fs_4 label-001 Label Not Foundr\n");
          printf("c2z_fs.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, wk_strg);
        src_line();
      } 

      if(strcmp(w_fs_fsaid[I].fs_fsaid_attr, "PF2") == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1);
        strcat(a_string, "I");
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, "PF2");
        src_line();
 
        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
 
        x3 = 0;
        for(J = 0; J < goto_label_ct; J++)
        {
          ret = strcmp(w_goto_label[J].goto_org_lb, w_fs_fsaid[I].fs_fsaid_label);
          if(ret == 0)
          {
            strcpy(wk_strg, w_goto_label[J].goto_label_1);
            x3 = 1;
          }
        }
   
        if(x3 == 0)
        {
          printf("\nc2z_fs.c c2_fs_4 label-002 Label Not Foundr\n");
          printf("c2z_fs.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         JLE    ");
        strcat(a_string, wk_strg);
        src_line();
      } 

      if(strcmp(w_fs_fsaid[I].fs_fsaid_attr, "PF3") == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1);
        strcat(a_string, "I");
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, "PF3");
        src_line();
 
        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();

        x3 = 0;
        for(J = 0; J < goto_label_ct; J++)
        {
          ret = strcmp(w_goto_label[J].goto_org_lb, w_fs_fsaid[I].fs_fsaid_label);
          if(ret == 0)
          {
            strcpy(wk_strg, w_goto_label[J].goto_label_1);
            x3 = 1;
          }
        }
   
        if(x3 == 0)
        {
          printf("\nc2z_fs.c c2_fs_4 label-003 Label Not Foundr\n");
          printf("c2z_fs.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, wk_strg);
        src_line();
      } 

      if(strcmp(w_fs_fsaid[I].fs_fsaid_attr, "PF4") == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1);
        strcat(a_string, "I");
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, "PF4");
        src_line();

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
       
        x3 = 0;
        for(J = 0; J < goto_label_ct; J++)
        {
          ret = strcmp(w_goto_label[J].goto_org_lb, w_fs_fsaid[I].fs_fsaid_label);
          if(ret == 0)
          {
            strcpy(wk_strg, w_goto_label[J].goto_label_1);
            x3 = 1;
          }
        }
   
        if(x3 == 0)
        {
          printf("\nc2z_fs.c c2_fs_4 label-004 Label Not Foundr\n");
          printf("c2z_fs.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, wk_strg);
        src_line();
      } 

      if(strcmp(w_fs_fsaid[I].fs_fsaid_attr, "PF5") == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1);
        strcat(a_string, "I");
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, "PF5");
        src_line();

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();

        x3 = 0;
        for(J = 0; J < goto_label_ct; J++)
        {
          ret = strcmp(w_goto_label[J].goto_org_lb, w_fs_fsaid[I].fs_fsaid_label);
          if(ret == 0)
          {
            strcpy(wk_strg, w_goto_label[J].goto_label_1);
            x3 = 1;
          }
        }
   
        if(x3 == 0)
        {
          printf("\nc2z_fs.c c2_fs_4 label-005 Label Not Foundr\n");
          printf("c2z_fs.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, wk_strg);
        src_line();
      } 

      if(strcmp(w_fs_fsaid[I].fs_fsaid_attr, "PF6") == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1);
        strcat(a_string, "I");
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, "PF6");
        src_line();

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
 
        x3 = 0;
        for(J = 0; J < goto_label_ct; J++)
        {
          ret = strcmp(w_goto_label[J].goto_org_lb, w_fs_fsaid[I].fs_fsaid_label);
          if(ret == 0)
          {
            strcpy(wk_strg, w_goto_label[J].goto_label_1);
            x3 = 1;
          }
        }
   
        if(x3 == 0)
        {
          printf("\nc2z_fs.c c2_fs_4 label-006 Label Not Foundr\n");
          printf("c2z_fs.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, wk_strg);
        src_line();
      } 

      if(strcmp(w_fs_fsaid[I].fs_fsaid_attr, "PF7") == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1);
        strcat(a_string, "I");
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, "PF7");
        src_line();
 
        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
 
        x3 = 0;
        for(J = 0; J < goto_label_ct; J++)
        {
          ret = strcmp(w_goto_label[J].goto_org_lb, w_fs_fsaid[I].fs_fsaid_label);
          if(ret == 0)
          {
            strcpy(wk_strg, w_goto_label[J].goto_label_1);
            x3 = 1;
          }
        }

        if(x3 == 0)
        {
          printf("\nc2z_fs.c c2_fs_label-007 Label Not Foundr\n");
          printf("c2z_fs.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, wk_strg);
        src_line();
      }

      if(strcmp(w_fs_fsaid[I].fs_fsaid_attr, "PF8") == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1);
        strcat(a_string, "I");
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, "PF8");
        src_line();

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();

        x3 = 0;
        for(J = 0; J < goto_label_ct; J++)
        {
          ret = strcmp(w_goto_label[J].goto_org_lb, w_fs_fsaid[I].fs_fsaid_label);
          if(ret == 0)
          {
            strcpy(wk_strg, w_goto_label[J].goto_label_1);
            x3 = 1;
          }
        }
   
        if(x3 == 0)
        {
          printf("\nc2z_fs.c c2_fs_4 label-008 Label Not Foundr\n");
          printf("c2z_fs.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, wk_strg);
        src_line();
      }

      if(strcmp(w_fs_fsaid[I].fs_fsaid_attr, "PF9") == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1);
        strcat(a_string, "I");
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, "PF9");
        src_line();
 
        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
 
        x3 = 0;
        for(J = 0; J < goto_label_ct; J++)
        {
          ret = strcmp(w_goto_label[J].goto_org_lb, w_fs_fsaid[I].fs_fsaid_label);
          if(ret == 0)
          {
            strcpy(wk_strg, w_goto_label[J].goto_label_1);
            x3 = 1;
          }
        }
   
        if(x3 == 0)
        {
          printf("\nc2z_fs.c c2_fs_4 label-009 Label Not Foundr\n");
          printf("c2z_fs.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, wk_strg);
        src_line();
      } 
 
      if(strcmp(w_fs_fsaid[I].fs_fsaid_attr, "PF10") == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1);
        strcat(a_string, "I");
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();
 
        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, "PF10");
        src_line();

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
  
        x3 = 0;
        for(J = 0; J < goto_label_ct; J++)
        {
          ret = strcmp(w_goto_label[J].goto_org_lb, w_fs_fsaid[I].fs_fsaid_label);
          if(ret == 0)
          {
            strcpy(wk_strg, w_goto_label[J].goto_label_1);
            x3 = 1;
          }
        }
   
        if(x3 == 0)
        {
          printf("\nc2z_fs.c c2_fs_4 label-001 Label Not Foundr\n");
          printf("c2z_fs.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, wk_strg);
        src_line();
      } 

      if(strcmp(w_fs_fsaid[I].fs_fsaid_attr, "PF11") == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1);
        strcat(a_string, "I");
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, "PF11");
        src_line();
 
        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();
 
        x3 = 0;
        for(J = 0; J < goto_label_ct; J++)
        {
          ret = strcmp(w_goto_label[J].goto_org_lb, w_fs_fsaid[I].fs_fsaid_label);
          if(ret == 0)
          {
            strcpy(wk_strg, w_goto_label[J].goto_label_1);
            x3 = 1;
          }
        }
   
        if(x3 == 0)
        {
          printf("\nc2z_fs.c c2_fs_4 label-001 Label Not Foundr\n");
          printf("c2z_fs.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, wk_strg);
        src_line();
      } 

      if(strcmp(w_fs_fsaid[I].fs_fsaid_attr, "PF12") == 0)
      {
        strcpy(a_string, "         LARL  R9,");
        strcat(a_string, field1);
        strcat(a_string, "I");
        strcpy(wk_remark, " ");
        strcat(wk_remark, field1);
        strcat(wk_remark, " */");
        write_remark();

        strcpy(a_string, "         LARL  R8,");
        strcat(a_string, "PF12");
        src_line();

        strcpy(a_string, "         CLC   0(1,R9),0(R8)");
        src_line();

        x3 = 0;
        for(J = 0; J < goto_label_ct; J++)
        {
          ret = strcmp(w_goto_label[J].goto_org_lb, w_fs_fsaid[I].fs_fsaid_label);
          if(ret == 0)
          {
            strcpy(wk_strg, w_goto_label[J].goto_label_1);
            x3 = 1;
          }
        }
   
        if(x3 == 0)
        {
          printf("\nc2z_fs.c c2_fs_4 label-001 Label Not Foundr\n");
          printf("c2z_fs.c rct = %d p_string = %s", rct, p_string);
          erct++;
          convert = 1;
          return;
        }

        strcpy(a_string, "         JLE   ");
        strcat(a_string, wk_strg);
        src_line();
      } 
    }
  }

  p_ct = 0;
  i_in = 0;
  while(p_ct < fs_field_ct)
  {
     x7 = 0;
     ret =  strcmp(w_fs_field[p_ct].fs_fd_map, field1);
     ret1 = strcmp(w_fs_field[p_ct].fs_fd_type, "V");
     ret2 = strcmp(w_fs_field[p_ct].fs_fd_io, "I");
     if((ret == 0) && (ret1 == 0) && (ret2 == 0))
     {
        strcpy(field4, w_fs_field[p_ct].fs_fd_field);
        x7 = 1;
     }

     if(x7 == 1)
     {

       ret = strcmp(w_fs_field[p_ct].fs_fd_type, "V");
       if(ret == 0)
       {
         x3 = 0;
         for (v = 0; v < lv_ct; v++) 
         {
           ret = strcmp(field4, lw_variable[v].lv_name);
           ret1 = strcmp(sv_func, lw_variable[v].lv_func);
           if ((ret == 0) && (ret1 == 0)) 
           {
             strcpy(field4a, lw_variable[v].lv_cname);
             x5 = lw_variable[v].lv_current_lgth;
             x98 = lw_variable[v].lv_lgth;
             x99 = lw_variable[v].lv_id;
             x3 = 1;
             break;
           }
         }
     
         if (x3 == 0) 
         {
           printf("\nc2z_fs.c c2_fs_2_2 fs_2-001 field4 Not Found = %s\n", field4);
           printf("c2z_fs.c c2_fs_2_2 rct = %d p_string = %s", rct, p_string);
           erct++;
           convert = 1;
           return;
         }

          for(v = 0; v < T3270_ct; v++)
          {
            ret = strcmp(field4, w_fs_scr_field[v].fs_scr_name);
            ret1 = strcmp(field1, w_fs_scr_field[v].fs_scr_map);
            if((ret == 0) && (ret1 == 0))
            {
              strcpy(field8, w_fs_scr_field[v].fs_scr_cname);
              break;
            }
          }
     
          if(x99 == 3)
          {
            strcpy(a_string, "         LARL  R9,");
            strcat(a_string, field4a);
            strcpy(wk_remark, " ");
            strcat(wk_remark, field4);
            strcat(wk_remark, " */");
            write_remark();

            strcpy(a_string, "         LARL  R8,");
            strcat(a_string, field1);
            strcat(a_string, "I");
            strcpy(wk_remark, " ");
            strcat(wk_remark, field1);
            strcat(wk_remark, " */");
            write_remark();

            strcpy(a_string, "         MVC   ");
            strcat(a_string, "0(");
            snprintf(wk_strg, sizeof(wk_strg), "%d", x98);
            strcat(a_string, wk_strg);
            strcat(a_string, ",R9),");
            if(i_in == 0)
            {
              strcat(a_string, "3(R8)");
            }
            else
            {
              snprintf(wk_strg, sizeof(wk_strg), "%d", i_in - 1);
              strcat(a_string, wk_strg);
              strcat(a_string, "(R8)");
            }
            src_line();
            i_in = i_in + x98;
          }
        }
     }
     p_ct++;
     x7 = 0;
  }


  strcpy(a_string, "         STLINENO LINE=1");
  src_line();

  convert = 1;
}








void c2_fs_6(void)
{
  char ch;
  char *p;
  char field1[VAR_LGTH];
  char field2[VAR_LGTH];
  char field3[VAR_LGTH];
  char field10[VAR_LGTH];
  char field11[VAR_LGTH];

   int pi;
   int pi2;
   int x3;
   int size;
 
  pi = 0;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != ' ')
  {
    pi++;
    ch = p_string[pi];
  }

field_loop:
  
  fgets(p_string, BUFSIZE, pgm);
  rct++;

  p = strstr(p_string, "{");
  if(p)
  {
    goto field_loop;
  }

  pi = 0;
  ch = p_string[pi];
  while(ch == ' ')
  {
    pi++;
    ch = p_string[pi];
  }

  pi2 = 0;
  while(ch != '(')
  {
    field10[pi2] = ch;
    pi2++;
    pi++;
    ch = p_string[pi];
  }
  field10[pi2] = '\0';

  p = strstr(field10, "fsaid_map");
  if(p)
  {
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while(ch != ')')
    {
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';
    strcpy(field1,field11);
    goto field_end;
  }
  
  p = strstr(field10, "fsaid_attr");
  if(p)
  {
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while(ch != ')')
    {
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';
    strcpy(field2,field11);
    goto field_end;
  }

  p = strstr(field10, "fsaid_label");
  if(p)
  {
    pi++;
    ch = p_string[pi];
    pi2 = 0;
    while(ch != ')')
    {
      field11[pi2] = ch;
      pi2++;
      pi++;
      ch = p_string[pi];
    }
    field11[pi2] = '\0';
    strcpy(field3,field11);
    goto field_end;
  }

field_end:

  p = strstr(p_string, "};");
  if(!p)
  {
     goto field_loop;
  }

/*  
printf("c2z_fs.c fs_2 rct = %d MAP_NAME field1 = %s\n",rct,field1);
printf("c2z_fs.c fs_2 rct = %d ATTR field2 = %s\n",rct,field2);
printf("c2z_fs.c fs_2 rct = %d LABEL field3 = %s\n",rct,field3);
*/

  x3 = 0;
  if (x3 == 0) 
  {
    if (global_st == 0) 
    {
      size = 0;
      if (fsaid_ct == 0) 
      {
        size = 1;
        w_fs_fsaid = malloc(size * sizeof(struct fs_fsaid));
      } 
      else 
      {
        size = fsaid_ct + 1;
        w_fs_fsaid = realloc(w_fs_fsaid, size * sizeof(struct fs_fsaid));
      }
      strcpy(w_fs_fsaid[fsaid_ct].fs_fsaid_map, field1);
      strcpy(w_fs_fsaid[fsaid_ct].fs_fsaid_attr, field2);
      strcpy(w_fs_fsaid[fsaid_ct].fs_fsaid_label, field3);
      fsaid_ct++;
    }

    if (global_st == 1) 
    {
      size = 0;
      if (fsaid_ct == 0) 
      {
        size = 1;
        w_fs_fsaid = malloc(size * sizeof(struct fs_fsaid));
      } 
      else 
      {
        size = fsaid_ct + 1;
        w_fs_fsaid = realloc(w_fs_fsaid, size * sizeof(struct fs_fsaid));
      }
      strcpy(w_fs_fsaid[fsaid_ct].fs_fsaid_map, field1);
      strcpy(w_fs_fsaid[fsaid_ct].fs_fsaid_attr, field2);
      strcpy(w_fs_fsaid[fsaid_ct].fs_fsaid_label, field3);
      fsaid_ct++;
    }
  }

  convert = 1;

}



void c2_fs_5(void)
{

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
  strcpy(T3270[163], "C2E2");		/* 3  */
  strcpy(T3270[164], "C2E3");		/* 4  */
  strcpy(T3270[165], "C2E4");		/* 5  */
  strcpy(T3270[166], "C2E5");		/* 6  */
  strcpy(T3270[167], "C2E6");		/* 7  */
  strcpy(T3270[168], "C2E7");		/* 8  */
  strcpy(T3270[169], "C2E8");		/* 9  */
  strcpy(T3270[170], "C2E9");		/* 10  */
  strcpy(T3270[171], "C26A");		/* 11  */
  strcpy(T3270[172], "C26B");		/* 12  */
  strcpy(T3270[173], "C26C");		/* 13  */
  strcpy(T3270[174], "C26D");		/* 14  */
  strcpy(T3270[175], "C26E");		/* 15  */
  strcpy(T3270[176], "C26F");		/* 16  */
  strcpy(T3270[177], "C2F0");		/* 17  */
  strcpy(T3270[178], "C2F1");		/* 18  */
  strcpy(T3270[179], "C2F2");		/* 19  */
  strcpy(T3270[180], "C2F3");		/* 20  */
  strcpy(T3270[181], "C2F4");		/* 21  */
  strcpy(T3270[182], "C2F5");		/* 22  */
  strcpy(T3270[183], "C2F6");		/* 23  */
  strcpy(T3270[184], "C2F7");		/* 24  */
  strcpy(T3270[185], "C2F8");		/* 25  */
  strcpy(T3270[186], "C2F9");		/* 26  */
  strcpy(T3270[187], "C27A");		/* 27  */
  strcpy(T3270[188], "C27B");		/* 28  */
  strcpy(T3270[189], "C27C");		/* 29  */
  strcpy(T3270[190], "C27D");		/* 30  */
  strcpy(T3270[191], "C27E");		/* 31  */
  strcpy(T3270[192], "C27F");		/* 32  */
  strcpy(T3270[193], "C340");		/* 33  */
  strcpy(T3270[194], "C3C1");		/* 34  */
  strcpy(T3270[195], "C3C2");		/* 35  */
  strcpy(T3270[196], "C3C3");		/* 36  */
  strcpy(T3270[197], "C3C4");		/* 37  */
  strcpy(T3270[198], "C3C5");		/* 38  */
  strcpy(T3270[199], "C3C6");		/* 39  */
  strcpy(T3270[200], "C3C7");		/* 40  */
  strcpy(T3270[201], "C3C8");		/* 41  */
  strcpy(T3270[202], "C3C9");		/* 42  */
  strcpy(T3270[203], "C34A");		/* 43  */
  strcpy(T3270[204], "C34B");		/* 44  */
  strcpy(T3270[205], "C34C");		/* 45  */
  strcpy(T3270[206], "C34D");		/* 46  */
  strcpy(T3270[207], "C34E");		/* 47  */
  strcpy(T3270[208], "C34F");		/* 48  */
  strcpy(T3270[209], "C350");		/* 49  */
  strcpy(T3270[210], "C3D1");		/* 50  */
  strcpy(T3270[211], "C3D2");		/* 51  */
  strcpy(T3270[212], "C3D3");		/* 52  */
  strcpy(T3270[213], "C3D4");		/* 53  */
  strcpy(T3270[214], "C3D5");		/* 54  */
  strcpy(T3270[215], "C3D6");		/* 55  */
  strcpy(T3270[216], "C3D7");		/* 56  */
  strcpy(T3270[217], "C3D8");		/* 57  */
  strcpy(T3270[218], "C3D9");		/* 58  */
  strcpy(T3270[219], "C35A");		/* 59  */
  strcpy(T3270[220], "C35B");		/* 60  */
  strcpy(T3270[221], "C35C");		/* 61  */
  strcpy(T3270[222], "C35D");		/* 62  */
  strcpy(T3270[223], "C35E");		/* 63  */
  strcpy(T3270[224], "C35F");		/* 64  */
  strcpy(T3270[225], "C360");		/* 65  */
  strcpy(T3270[226], "C361");		/* 66  */
  strcpy(T3270[227], "C3E2");		/* 67  */
  strcpy(T3270[228], "C3E3");		/* 68  */
  strcpy(T3270[229], "C3E4");		/* 69  */
  strcpy(T3270[230], "C3E5");		/* 70  */
  strcpy(T3270[231], "C3E6");		/* 71  */
  strcpy(T3270[232], "C3E7");		/* 72  */
  strcpy(T3270[233], "C3E8");		/* 73  */
  strcpy(T3270[234], "C3E9");		/* 74  */
  strcpy(T3270[235], "C36A");		/* 75  */
  strcpy(T3270[236], "C36B");		/* 76  */
  strcpy(T3270[237], "C36C");		/* 77  */
  strcpy(T3270[238], "C36D");		/* 78  */
  strcpy(T3270[239], "C36E");		/* 79  */
  strcpy(T3270[240], "C36F");		/* 80  */


/* row  4  col 1 thru 80 */
  strcpy(T3270[241], "C3F0");		/* 1  */
  strcpy(T3270[242], "C3F1");		/* 2  */
  strcpy(T3270[243], "C3F2");		/* 3  */
  strcpy(T3270[244], "C3F3");		/* 4  */
  strcpy(T3270[245], "C3F4");		/* 5  */
  strcpy(T3270[246], "C3F5");		/* 6  */
  strcpy(T3270[247], "C3F6");		/* 7  */
  strcpy(T3270[248], "C3F7");		/* 8  */
  strcpy(T3270[249], "C3F8");		/* 9  */
  strcpy(T3270[250], "C3F9");		/* 10  */
  strcpy(T3270[251], "C37A");		/* 11  */
  strcpy(T3270[252], "C37B");		/* 12  */
  strcpy(T3270[253], "C37C");		/* 13  */
  strcpy(T3270[254], "C37D");		/* 14  */
  strcpy(T3270[255], "C37E");		/* 15  */
  strcpy(T3270[256], "C37F");		/* 16  */
  strcpy(T3270[257], "C440");		/* 17  */
  strcpy(T3270[258], "C4C1");		/* 18  */
  strcpy(T3270[259], "C4C2");		/* 19  */
  strcpy(T3270[260], "C4C3");		/* 20  */
  strcpy(T3270[261], "C4C4");		/* 21  */
  strcpy(T3270[262], "C4C5");		/* 22  */
  strcpy(T3270[263], "C4C6");		/* 23  */
  strcpy(T3270[264], "C4C7");		/* 24  */
  strcpy(T3270[265], "C4C8");		/* 25  */
  strcpy(T3270[266], "C4C9");		/* 26  */
  strcpy(T3270[267], "C44A");		/* 27  */
  strcpy(T3270[268], "C44B");		/* 28  */
  strcpy(T3270[269], "C44C");		/* 29  */
  strcpy(T3270[270], "C44D");		/* 30  */
  strcpy(T3270[271], "C44E");		/* 31  */
  strcpy(T3270[272], "C44F");		/* 32  */
  strcpy(T3270[273], "C450");		/* 33  */
  strcpy(T3270[274], "C4D1");		/* 34  */
  strcpy(T3270[275], "C4D2");		/* 35  */
  strcpy(T3270[276], "C4D3");		/* 36  */
  strcpy(T3270[277], "C4D4");		/* 37  */
  strcpy(T3270[278], "C4D5");		/* 38  */
  strcpy(T3270[279], "C4D6");		/* 39  */
  strcpy(T3270[280], "C4D7");		/* 40  */
  strcpy(T3270[281], "C4D8");		/* 41  */
  strcpy(T3270[282], "C4D9");		/* 42  */
  strcpy(T3270[283], "C45A");		/* 43  */
  strcpy(T3270[284], "C45B");		/* 44  */
  strcpy(T3270[285], "C45C");		/* 45  */
  strcpy(T3270[286], "C45D");		/* 46  */
  strcpy(T3270[287], "C45E");		/* 47  */
  strcpy(T3270[288], "C45F");		/* 48  */
  strcpy(T3270[289], "C460");		/* 49  */
  strcpy(T3270[290], "C461");		/* 50  */
  strcpy(T3270[291], "C4E2");		/* 51  */
  strcpy(T3270[292], "C4E3");		/* 52  */
  strcpy(T3270[293], "C4E4");		/* 53  */
  strcpy(T3270[294], "C4E5");		/* 54  */
  strcpy(T3270[295], "C4E6");		/* 55  */
  strcpy(T3270[296], "C4E7");		/* 56  */
  strcpy(T3270[297], "C4E8");		/* 57  */
  strcpy(T3270[298], "C4E9");		/* 58  */
  strcpy(T3270[299], "C46A");		/* 59  */
  strcpy(T3270[300], "C46B");		/* 60  */
  strcpy(T3270[301], "C46C");		/* 61  */
  strcpy(T3270[302], "C46D");		/* 62  */
  strcpy(T3270[303], "C46E");		/* 63  */
  strcpy(T3270[304], "C46F");		/* 64  */
  strcpy(T3270[305], "C4F0");		/* 65  */
  strcpy(T3270[306], "C4F1");		/* 66  */
  strcpy(T3270[307], "C4F2");		/* 67  */
  strcpy(T3270[308], "C4F3");		/* 68  */
  strcpy(T3270[309], "C4F4");		/* 69  */
  strcpy(T3270[310], "C4F5");		/* 70  */
  strcpy(T3270[311], "C4D6");		/* 71  */
  strcpy(T3270[312], "C4F7");		/* 72  */
  strcpy(T3270[313], "C4F8");		/* 73  */
  strcpy(T3270[314], "C4F9");		/* 74  */
  strcpy(T3270[315], "C47A");		/* 75  */
  strcpy(T3270[316], "C47B");		/* 76  */
  strcpy(T3270[317], "C47C");		/* 77  */
  strcpy(T3270[318], "C47D");		/* 78  */
  strcpy(T3270[319], "C47E");		/* 79  */
  strcpy(T3270[320], "C47F");		/* 80  */


/* row  5  col 1 thru 80 */
  strcpy(T3270[321], "C540");		/* 1  */
  strcpy(T3270[322], "C5C1");		/* 2  */
  strcpy(T3270[323], "C5C2");		/* 3  */
  strcpy(T3270[324], "C5C3");		/* 4  */
  strcpy(T3270[325], "C5C4");		/* 5  */
  strcpy(T3270[326], "C5C5");		/* 6  */
  strcpy(T3270[327], "C5C6");		/* 7  */
  strcpy(T3270[328], "C5C7");		/* 8  */
  strcpy(T3270[329], "C5C8");		/* 9  */
  strcpy(T3270[330], "C5C9");		/* 10  */
  strcpy(T3270[331], "C54A");		/* 11  */
  strcpy(T3270[332], "C54B");		/* 12  */
  strcpy(T3270[333], "C54C");		/* 13  */
  strcpy(T3270[334], "C54D");		/* 14  */
  strcpy(T3270[335], "C54E");		/* 15  */
  strcpy(T3270[336], "C54F");		/* 16  */
  strcpy(T3270[337], "C550");		/* 17  */
  strcpy(T3270[338], "C5D1");		/* 18  */
  strcpy(T3270[339], "C5D2");		/* 19  */
  strcpy(T3270[340], "C5D3");		/* 20  */
  strcpy(T3270[341], "C5D4");		/* 21  */
  strcpy(T3270[342], "C5D5");		/* 22  */
  strcpy(T3270[343], "C5D6");		/* 23  */
  strcpy(T3270[344], "C5D7");		/* 24  */
  strcpy(T3270[345], "C5D8");		/* 25  */
  strcpy(T3270[346], "C5D9");		/* 26  */
  strcpy(T3270[347], "C55A");		/* 27  */
  strcpy(T3270[348], "C55B");		/* 28  */
  strcpy(T3270[349], "C55C");		/* 29  */
  strcpy(T3270[350], "C55D");		/* 30  */
  strcpy(T3270[351], "C55E");		/* 31  */
  strcpy(T3270[352], "C55F");		/* 32  */
  strcpy(T3270[353], "C560");		/* 33  */
  strcpy(T3270[354], "C561");		/* 34  */
  strcpy(T3270[355], "C5E2");		/* 35  */
  strcpy(T3270[356], "C5E3");		/* 36  */
  strcpy(T3270[357], "C5E4");		/* 37  */
  strcpy(T3270[358], "C5E5");		/* 38  */
  strcpy(T3270[359], "C5E6");		/* 39  */
  strcpy(T3270[360], "C5E7");		/* 40  */
  strcpy(T3270[361], "C5E8");		/* 41  */
  strcpy(T3270[362], "C5E9");		/* 42  */
  strcpy(T3270[363], "C56A");		/* 43  */
  strcpy(T3270[364], "C56B");		/* 44  */
  strcpy(T3270[365], "C56C");		/* 45  */
  strcpy(T3270[366], "C56D");		/* 46  */
  strcpy(T3270[367], "C56E");		/* 47  */
  strcpy(T3270[368], "C56F");		/* 48  */
  strcpy(T3270[369], "C5F0");		/* 49  */
  strcpy(T3270[370], "C5F1");		/* 50  */
  strcpy(T3270[371], "C5F2");		/* 51  */
  strcpy(T3270[372], "C5F3");		/* 52  */
  strcpy(T3270[373], "C5F4");		/* 53  */
  strcpy(T3270[374], "C5F5");		/* 54  */
  strcpy(T3270[375], "C5F6");		/* 55  */
  strcpy(T3270[376], "C5F7");		/* 56  */
  strcpy(T3270[377], "C5F8");		/* 57  */
  strcpy(T3270[378], "C5F9");		/* 58  */
  strcpy(T3270[379], "C57A");		/* 59  */
  strcpy(T3270[380], "C57B");		/* 60  */
  strcpy(T3270[381], "C57C");		/* 61  */
  strcpy(T3270[382], "C57D");		/* 62  */
  strcpy(T3270[383], "C57E");		/* 63  */
  strcpy(T3270[384], "C57F");		/* 64  */
  strcpy(T3270[385], "C640");		/* 65  */
  strcpy(T3270[386], "C6C1");		/* 66  */
  strcpy(T3270[387], "C6C2");		/* 67  */
  strcpy(T3270[388], "C6C3");		/* 68  */
  strcpy(T3270[389], "C6C4");		/* 69  */
  strcpy(T3270[390], "C6C5");		/* 70  */
  strcpy(T3270[391], "C6C6");		/* 71  */
  strcpy(T3270[392], "C6C7");		/* 72  */
  strcpy(T3270[393], "C6C8");		/* 73  */
  strcpy(T3270[394], "C6C9");		/* 74  */
  strcpy(T3270[395], "C64A");		/* 75  */
  strcpy(T3270[396], "C64B");		/* 76  */
  strcpy(T3270[397], "C64C");		/* 77  */
  strcpy(T3270[398], "C64D");		/* 78  */
  strcpy(T3270[399], "C64E");		/* 79  */
  strcpy(T3270[400], "C64F");		/* 80  */


/* row  6  col 1 thru 80 */
  strcpy(T3270[401], "C650");		/* 1  */
  strcpy(T3270[402], "C6D1");		/* 2  */
  strcpy(T3270[403], "C6D2");		/* 3  */
  strcpy(T3270[404], "C6D3");		/* 4  */
  strcpy(T3270[405], "C6D4");		/* 5  */
  strcpy(T3270[406], "C6D5");		/* 6  */
  strcpy(T3270[407], "C6D6");		/* 7  */
  strcpy(T3270[408], "C6D7");		/* 8  */
  strcpy(T3270[409], "C6D8");		/* 9  */
  strcpy(T3270[410], "C6D9");		/* 10  */
  strcpy(T3270[411], "C65A");		/* 11  */
  strcpy(T3270[412], "C65B");		/* 12  */
  strcpy(T3270[413], "C65C");		/* 13  */
  strcpy(T3270[414], "C65D");		/* 14  */
  strcpy(T3270[415], "C65E");		/* 15  */
  strcpy(T3270[416], "C65F");		/* 16  */
  strcpy(T3270[417], "C660");		/* 17  */
  strcpy(T3270[418], "C661");		/* 18  */
  strcpy(T3270[419], "C6E2");		/* 19  */
  strcpy(T3270[420], "C6E3");		/* 20  */
  strcpy(T3270[421], "C6E4");		/* 21  */
  strcpy(T3270[422], "C6E5");		/* 22  */
  strcpy(T3270[423], "C6E6");		/* 23  */
  strcpy(T3270[424], "C6E7");		/* 24  */
  strcpy(T3270[425], "C6E8");		/* 25  */
  strcpy(T3270[426], "C6E9");		/* 26  */
  strcpy(T3270[427], "C66A");		/* 27  */
  strcpy(T3270[428], "C66B");		/* 28  */
  strcpy(T3270[429], "C66C");		/* 29  */
  strcpy(T3270[430], "C66D");		/* 30  */
  strcpy(T3270[431], "C66E");		/* 31  */
  strcpy(T3270[432], "C66F");		/* 32  */
  strcpy(T3270[433], "C6F0");		/* 33  */
  strcpy(T3270[434], "C6F1");		/* 34  */
  strcpy(T3270[435], "C6F2");		/* 35  */
  strcpy(T3270[436], "C6F3");		/* 36  */
  strcpy(T3270[437], "C6F4");		/* 37  */
  strcpy(T3270[438], "C6F5");		/* 38  */
  strcpy(T3270[439], "C6F6");		/* 39  */
  strcpy(T3270[440], "C6F7");		/* 40  */
  strcpy(T3270[441], "C6F8");		/* 41  */
  strcpy(T3270[442], "C6F9");		/* 42  */
  strcpy(T3270[443], "C67A");		/* 43  */
  strcpy(T3270[444], "C67B");		/* 44  */
  strcpy(T3270[445], "C67C");		/* 45  */
  strcpy(T3270[446], "C67D");		/* 46  */
  strcpy(T3270[447], "C67E");		/* 47  */
  strcpy(T3270[448], "C67F");		/* 48  */
  strcpy(T3270[449], "C740");		/* 49  */
  strcpy(T3270[450], "C7C1");		/* 50  */
  strcpy(T3270[451], "C7C2");		/* 51  */
  strcpy(T3270[452], "C7C3");		/* 52  */
  strcpy(T3270[453], "C7C4");		/* 53  */
  strcpy(T3270[454], "C7C5");		/* 54  */
  strcpy(T3270[455], "C7C6");		/* 55  */
  strcpy(T3270[456], "C7C7");		/* 56  */
  strcpy(T3270[457], "C7C8");		/* 57  */
  strcpy(T3270[458], "C7C9");		/* 58  */
  strcpy(T3270[459], "C74A");		/* 59  */
  strcpy(T3270[460], "C74B");		/* 60  */
  strcpy(T3270[461], "C74C");		/* 61  */
  strcpy(T3270[462], "C74D");		/* 62  */
  strcpy(T3270[463], "C74E");		/* 63  */
  strcpy(T3270[464], "C74F");		/* 64  */
  strcpy(T3270[465], "C750");		/* 65  */
  strcpy(T3270[466], "C7D1");		/* 66  */
  strcpy(T3270[467], "C7D2");		/* 67  */
  strcpy(T3270[468], "C7D3");		/* 68  */
  strcpy(T3270[469], "C7D4");		/* 69  */
  strcpy(T3270[470], "C7D5");		/* 70  */
  strcpy(T3270[471], "C7D6");		/* 71  */
  strcpy(T3270[472], "C7D7");		/* 72  */
  strcpy(T3270[473], "C7D8");		/* 73  */
  strcpy(T3270[474], "C7D9");		/* 74  */
  strcpy(T3270[475], "C75A");		/* 75  */
  strcpy(T3270[476], "C75B");		/* 76  */
  strcpy(T3270[477], "C75C");		/* 77  */
  strcpy(T3270[478], "C75D");		/* 78  */
  strcpy(T3270[479], "C75E");		/* 79  */
  strcpy(T3270[480], "C75F");		/* 80  */


/* row  7  col 1 thru 80 */
  strcpy(T3270[481], "C760");		/* 1  */
  strcpy(T3270[482], "C761");		/* 2  */
  strcpy(T3270[483], "C7E2");		/* 3  */
  strcpy(T3270[484], "C7E3");		/* 4  */
  strcpy(T3270[485], "C7E4");		/* 5  */
  strcpy(T3270[486], "C7E5");		/* 6  */
  strcpy(T3270[487], "C7E6");		/* 7  */
  strcpy(T3270[488], "C7E7");		/* 8  */
  strcpy(T3270[489], "C7E8");		/* 9  */
  strcpy(T3270[490], "C7E9");		/* 10  */
  strcpy(T3270[491], "C76A");		/* 11  */
  strcpy(T3270[492], "C76B");		/* 12  */
  strcpy(T3270[493], "C76C");		/* 13  */
  strcpy(T3270[494], "C76D");		/* 14  */
  strcpy(T3270[495], "C76E");		/* 15  */
  strcpy(T3270[496], "C76F");		/* 16  */
  strcpy(T3270[497], "C7F0");		/* 17  */
  strcpy(T3270[498], "C7F1");		/* 18  */
  strcpy(T3270[499], "C7F2");		/* 19  */
  strcpy(T3270[500], "C7F3");		/* 20  */
  strcpy(T3270[501], "C7F4");		/* 21  */
  strcpy(T3270[502], "C7F5");		/* 22  */
  strcpy(T3270[503], "C7F6");		/* 23  */
  strcpy(T3270[504], "C7F7");		/* 24  */
  strcpy(T3270[505], "C7F8");		/* 25  */
  strcpy(T3270[506], "C7F9");		/* 26  */
  strcpy(T3270[507], "C77A");		/* 27  */
  strcpy(T3270[508], "C77B");		/* 28  */
  strcpy(T3270[509], "C77C");		/* 29  */
  strcpy(T3270[510], "C77D");		/* 30  */
  strcpy(T3270[511], "C77E");		/* 31  */
  strcpy(T3270[512], "C77F");		/* 32  */
  strcpy(T3270[513], "C840");		/* 33  */
  strcpy(T3270[514], "C8C1");		/* 34  */
  strcpy(T3270[515], "C8C2");		/* 35  */
  strcpy(T3270[516], "C8C3");		/* 36  */
  strcpy(T3270[517], "C8C4");		/* 37  */
  strcpy(T3270[518], "C8C5");		/* 38  */
  strcpy(T3270[519], "C8C6");		/* 39  */
  strcpy(T3270[520], "C8C7");		/* 40  */
  strcpy(T3270[521], "C8C8");		/* 41  */
  strcpy(T3270[522], "C8C9");		/* 42  */
  strcpy(T3270[523], "C84A");		/* 43  */
  strcpy(T3270[524], "C84B");		/* 44  */
  strcpy(T3270[525], "C84C");		/* 45  */
  strcpy(T3270[526], "C84D");		/* 46  */
  strcpy(T3270[527], "C84E");		/* 47  */
  strcpy(T3270[528], "C84F");		/* 48  */
  strcpy(T3270[529], "C850");		/* 49  */
  strcpy(T3270[530], "C8D1");		/* 50  */
  strcpy(T3270[531], "C8D2");		/* 51  */
  strcpy(T3270[532], "C8D3");		/* 52  */
  strcpy(T3270[533], "C8D4");		/* 53  */
  strcpy(T3270[534], "C8D5");		/* 54  */
  strcpy(T3270[535], "C8D6");		/* 55  */
  strcpy(T3270[536], "C8D7");		/* 56  */
  strcpy(T3270[537], "C8D8");		/* 57  */
  strcpy(T3270[538], "C8D9");		/* 58  */
  strcpy(T3270[539], "C85A");		/* 59  */
  strcpy(T3270[540], "C85B");		/* 60  */
  strcpy(T3270[541], "C85C");		/* 61  */
  strcpy(T3270[542], "C85D");		/* 62  */
  strcpy(T3270[543], "C85E");		/* 63  */
  strcpy(T3270[544], "C85F");		/* 64  */
  strcpy(T3270[545], "C860");		/* 65  */
  strcpy(T3270[546], "C861");		/* 66  */
  strcpy(T3270[547], "C8E2");		/* 67  */
  strcpy(T3270[548], "C8E3");		/* 68  */
  strcpy(T3270[549], "C8E4");		/* 69  */
  strcpy(T3270[550], "C8E5");		/* 70  */
  strcpy(T3270[551], "C8E6");		/* 71  */
  strcpy(T3270[552], "C8E7");		/* 72  */
  strcpy(T3270[553], "C8E8");		/* 73  */
  strcpy(T3270[554], "C8E9");		/* 74  */
  strcpy(T3270[555], "C86A");		/* 75  */
  strcpy(T3270[556], "C86B");		/* 76  */
  strcpy(T3270[557], "C86C");		/* 77  */
  strcpy(T3270[558], "C86D");		/* 78  */
  strcpy(T3270[559], "C86E");		/* 79  */
  strcpy(T3270[560], "C86F");		/* 80  */


/* row  8  col 1 thru 80 */
  strcpy(T3270[561], "C8F0");		/* 1  */
  strcpy(T3270[562], "C8F1");		/* 2  */
  strcpy(T3270[563], "C8F2");		/* 3  */
  strcpy(T3270[564], "C8F3");		/* 4  */
  strcpy(T3270[565], "C8F4");		/* 5  */
  strcpy(T3270[566], "C8F5");		/* 6  */
  strcpy(T3270[567], "C8F6");		/* 7  */
  strcpy(T3270[568], "C8F7");		/* 8  */
  strcpy(T3270[569], "C8F8");		/* 9  */
  strcpy(T3270[570], "C8F9");		/* 10  */
  strcpy(T3270[571], "C87A");		/* 11  */
  strcpy(T3270[572], "C87B");		/* 12  */
  strcpy(T3270[573], "C87C");		/* 13  */
  strcpy(T3270[574], "C87D");		/* 14  */
  strcpy(T3270[575], "C87E");		/* 15  */
  strcpy(T3270[576], "C87F");		/* 16  */
  strcpy(T3270[577], "C940");		/* 17  */
  strcpy(T3270[578], "C9C1");		/* 18  */
  strcpy(T3270[579], "C9C2");		/* 19  */
  strcpy(T3270[580], "C9C3");		/* 20  */
  strcpy(T3270[581], "C9C4");		/* 21  */
  strcpy(T3270[582], "C9C5");		/* 22  */
  strcpy(T3270[583], "C9C6");		/* 23  */
  strcpy(T3270[584], "C9C7");		/* 24  */
  strcpy(T3270[585], "C9C8");		/* 25  */
  strcpy(T3270[586], "C9C9");		/* 26  */
  strcpy(T3270[587], "C94A");		/* 27  */
  strcpy(T3270[588], "C94B");		/* 28  */
  strcpy(T3270[589], "C94C");		/* 29  */
  strcpy(T3270[590], "C94D");		/* 30  */
  strcpy(T3270[591], "C94E");		/* 31  */
  strcpy(T3270[592], "C94F");		/* 32  */
  strcpy(T3270[593], "C950");		/* 33  */
  strcpy(T3270[594], "C9D1");		/* 34  */
  strcpy(T3270[595], "C9D2");		/* 35  */
  strcpy(T3270[596], "C9D3");		/* 36  */
  strcpy(T3270[597], "C9D4");		/* 37  */
  strcpy(T3270[598], "C9D5");		/* 38  */
  strcpy(T3270[599], "C9D6");		/* 39  */
  strcpy(T3270[600], "C9D7");		/* 40  */
  strcpy(T3270[601], "C9D8");		/* 41  */
  strcpy(T3270[602], "C9D9");		/* 42  */
  strcpy(T3270[603], "C95A");		/* 43  */
  strcpy(T3270[604], "C95B");		/* 44  */
  strcpy(T3270[605], "C95C");		/* 45  */
  strcpy(T3270[606], "C95D");		/* 46  */
  strcpy(T3270[607], "C95E");		/* 47  */
  strcpy(T3270[608], "C95F");		/* 48  */
  strcpy(T3270[609], "C960");		/* 49  */
  strcpy(T3270[610], "C961");		/* 50  */
  strcpy(T3270[611], "C9E2");		/* 51  */
  strcpy(T3270[612], "C9E3");		/* 52  */
  strcpy(T3270[613], "C9E4");		/* 53  */
  strcpy(T3270[614], "C9E5");		/* 54  */
  strcpy(T3270[615], "C9E6");		/* 55  */
  strcpy(T3270[616], "C9E7");		/* 56  */
  strcpy(T3270[617], "C9E8");		/* 57  */
  strcpy(T3270[618], "C9E9");		/* 58  */
  strcpy(T3270[619], "C96A");		/* 59  */
  strcpy(T3270[620], "C95B");		/* 60  */
  strcpy(T3270[621], "C96C");		/* 61  */
  strcpy(T3270[622], "C96D");		/* 62  */
  strcpy(T3270[623], "C96E");		/* 63  */
  strcpy(T3270[624], "C96F");		/* 64  */
  strcpy(T3270[625], "C9F0");		/* 65  */
  strcpy(T3270[626], "C9F1");		/* 66  */
  strcpy(T3270[627], "C9F2");		/* 67  */
  strcpy(T3270[628], "C9F3");		/* 68  */
  strcpy(T3270[629], "C9F4");		/* 69  */
  strcpy(T3270[630], "C9F5");		/* 70  */
  strcpy(T3270[631], "C9F6");		/* 71  */
  strcpy(T3270[632], "C9F7");		/* 72  */
  strcpy(T3270[633], "C9F8");		/* 73  */
  strcpy(T3270[634], "C9F9");		/* 74  */
  strcpy(T3270[635], "C97A");		/* 75  */
  strcpy(T3270[636], "C97B");		/* 76  */
  strcpy(T3270[637], "C97C");		/* 77  */
  strcpy(T3270[638], "C97D");		/* 78  */
  strcpy(T3270[639], "C97E");		/* 79  */
  strcpy(T3270[640], "C97F");		/* 80  */


/* row  9  col 1 thru 80 */
  strcpy(T3270[641], "4A40");		/* 1  */
  strcpy(T3270[642], "4AC1");		/* 2  */
  strcpy(T3270[643], "4AC2");		/* 3  */
  strcpy(T3270[644], "4AC3");		/* 4  */
  strcpy(T3270[645], "4AC4");		/* 5  */
  strcpy(T3270[646], "4AC5");		/* 6  */
  strcpy(T3270[647], "4AC6");		/* 7  */
  strcpy(T3270[648], "4AC7");		/* 8  */
  strcpy(T3270[649], "4AC8");		/* 9  */
  strcpy(T3270[650], "4AC9");		/* 10  */
  strcpy(T3270[651], "4A4A");		/* 11  */
  strcpy(T3270[652], "4A4B");		/* 12  */
  strcpy(T3270[653], "4A4C");		/* 13  */
  strcpy(T3270[654], "4A4D");		/* 14  */
  strcpy(T3270[655], "4A4E");		/* 15  */
  strcpy(T3270[656], "4A4F");		/* 16  */
  strcpy(T3270[657], "4A50");		/* 17  */
  strcpy(T3270[658], "4AD1");		/* 18  */
  strcpy(T3270[659], "4AD2");		/* 19  */
  strcpy(T3270[660], "4AD3");		/* 20  */
  strcpy(T3270[661], "4AD4");		/* 21  */
  strcpy(T3270[662], "4AD5");		/* 22  */
  strcpy(T3270[663], "4AD6");		/* 23  */
  strcpy(T3270[664], "4AD7");		/* 24  */
  strcpy(T3270[665], "4AD8");		/* 25  */
  strcpy(T3270[666], "4AD9");		/* 26  */
  strcpy(T3270[667], "4A5A");		/* 27  */
  strcpy(T3270[668], "4A5B");		/* 28  */
  strcpy(T3270[669], "4A5C");		/* 29  */
  strcpy(T3270[670], "4A5D");		/* 30  */
  strcpy(T3270[671], "4A5E");		/* 31  */
  strcpy(T3270[672], "4A5F");		/* 32  */
  strcpy(T3270[673], "4A60");		/* 33  */
  strcpy(T3270[674], "4A61");		/* 34  */
  strcpy(T3270[675], "4AE2");		/* 35  */
  strcpy(T3270[676], "4AE3");		/* 36  */
  strcpy(T3270[677], "4AE4");		/* 37  */
  strcpy(T3270[678], "4AE5");		/* 38  */
  strcpy(T3270[679], "4AE6");		/* 39  */
  strcpy(T3270[680], "4AE7");		/* 40  */
  strcpy(T3270[681], "4AE8");		/* 41  */
  strcpy(T3270[682], "4AE9");		/* 42  */
  strcpy(T3270[683], "4A6A");		/* 43  */
  strcpy(T3270[684], "4A6B");		/* 44  */
  strcpy(T3270[685], "4A6C");		/* 45  */
  strcpy(T3270[686], "4A6D");		/* 46  */
  strcpy(T3270[687], "4A6E");		/* 47  */
  strcpy(T3270[688], "4A6F");		/* 48  */
  strcpy(T3270[689], "4AF0");		/* 49  */
  strcpy(T3270[690], "4AF1");		/* 50  */
  strcpy(T3270[691], "4AF2");		/* 51  */
  strcpy(T3270[692], "4AF3");		/* 52  */
  strcpy(T3270[693], "4AF4");		/* 53  */
  strcpy(T3270[694], "4AF5");		/* 54  */
  strcpy(T3270[695], "4AF6");		/* 55  */
  strcpy(T3270[696], "4AF7");		/* 56  */
  strcpy(T3270[697], "4AF8");		/* 57  */
  strcpy(T3270[698], "4AF9");		/* 58  */
  strcpy(T3270[699], "4A7A");		/* 59  */
  strcpy(T3270[700], "4A7B");		/* 60  */
  strcpy(T3270[701], "C96C");		/* 61  */
  strcpy(T3270[702], "C96D");		/* 62  */
  strcpy(T3270[703], "C96E");		/* 63  */
  strcpy(T3270[704], "C96F");		/* 64  */
  strcpy(T3270[705], "C9F0");		/* 65  */
  strcpy(T3270[706], "C9F1");		/* 66  */
  strcpy(T3270[707], "C9F2");		/* 67  */
  strcpy(T3270[708], "C9F3");		/* 68  */
  strcpy(T3270[709], "C9F4");		/* 69  */
  strcpy(T3270[710], "C9F5");		/* 70  */
  strcpy(T3270[711], "C9F6");		/* 71  */
  strcpy(T3270[712], "C9F7");		/* 72  */
  strcpy(T3270[713], "C9F8");		/* 73  */
  strcpy(T3270[714], "C9F9");		/* 74  */
  strcpy(T3270[715], "C97A");		/* 75  */
  strcpy(T3270[716], "C97B");		/* 76  */
  strcpy(T3270[717], "C97C");		/* 77  */
  strcpy(T3270[718], "C97D");		/* 78  */
  strcpy(T3270[719], "C97E");		/* 79  */
  strcpy(T3270[720], "C97F");		/* 80  */


/* row  10  col 1 thru 80 */
  strcpy(T3270[721], "4B50");		/* 1  */
  strcpy(T3270[722], "4BD1");		/* 2  */
  strcpy(T3270[723], "4BD2");		/* 3  */
  strcpy(T3270[724], "4BD3");		/* 4  */
  strcpy(T3270[725], "4BD4");		/* 5  */
  strcpy(T3270[726], "4BD5");		/* 6  */
  strcpy(T3270[727], "4BD6");		/* 7  */
  strcpy(T3270[728], "4BD7");		/* 8  */
  strcpy(T3270[729], "4BD8");		/* 9  */
  strcpy(T3270[730], "4BD9");		/* 10  */
  strcpy(T3270[731], "4B5A");		/* 11  */
  strcpy(T3270[732], "4B5B");		/* 12  */
  strcpy(T3270[733], "4B5C");		/* 13  */
  strcpy(T3270[734], "4B5D");		/* 14  */
  strcpy(T3270[735], "4B5E");		/* 15  */
  strcpy(T3270[736], "4B5F");		/* 16  */
  strcpy(T3270[737], "4B60");		/* 17  */
  strcpy(T3270[738], "4B61");		/* 18  */
  strcpy(T3270[739], "4BE2");		/* 19  */
  strcpy(T3270[740], "4BE3");		/* 20  */
  strcpy(T3270[741], "4BE4");		/* 21  */
  strcpy(T3270[742], "4BE5");		/* 22  */
  strcpy(T3270[743], "4BE6");		/* 23  */
  strcpy(T3270[744], "4BE7");		/* 24  */
  strcpy(T3270[745], "4BE8");		/* 25  */
  strcpy(T3270[746], "4BE9");		/* 26  */
  strcpy(T3270[747], "4B6A");		/* 27  */
  strcpy(T3270[748], "4B6B");		/* 28  */
  strcpy(T3270[749], "4B6C");		/* 29  */
  strcpy(T3270[750], "4B6D");		/* 30  */
  strcpy(T3270[751], "4B6E");		/* 31  */
  strcpy(T3270[752], "4B6F");		/* 32  */
  strcpy(T3270[753], "4BF0");		/* 33  */
  strcpy(T3270[754], "4BF1");		/* 34  */
  strcpy(T3270[755], "4BF2");		/* 35  */
  strcpy(T3270[756], "4BF3");		/* 36  */
  strcpy(T3270[757], "4BF4");		/* 37  */
  strcpy(T3270[758], "4BF5");		/* 38  */
  strcpy(T3270[759], "4BF6");		/* 39  */
  strcpy(T3270[760], "4BF7");		/* 40  */
  strcpy(T3270[761], "4BF8");		/* 41  */
  strcpy(T3270[762], "4BF9");		/* 42  */
  strcpy(T3270[763], "4B7A");		/* 43  */
  strcpy(T3270[764], "4B7B");		/* 44  */
  strcpy(T3270[765], "4B7C");		/* 45  */
  strcpy(T3270[766], "4B7D");		/* 46  */
  strcpy(T3270[767], "4B7E");		/* 47  */
  strcpy(T3270[768], "4B7F");		/* 48  */
  strcpy(T3270[769], "4C40");		/* 49  */
  strcpy(T3270[770], "4CC1");		/* 50  */
  strcpy(T3270[771], "4CC2");		/* 51  */
  strcpy(T3270[772], "4CC3");		/* 52  */
  strcpy(T3270[773], "4CC4");		/* 53  */
  strcpy(T3270[774], "4CC5");		/* 54  */
  strcpy(T3270[775], "4CC6");		/* 55  */
  strcpy(T3270[776], "4CC7");		/* 56  */
  strcpy(T3270[777], "4CC8");		/* 57  */
  strcpy(T3270[778], "4CC9");		/* 58  */
  strcpy(T3270[779], "4C4A");		/* 59  */
  strcpy(T3270[780], "4C4B");		/* 60  */
  strcpy(T3270[781], "4C4C");		/* 61  */
  strcpy(T3270[782], "4C4D");		/* 62  */
  strcpy(T3270[783], "4C4E");		/* 63  */
  strcpy(T3270[784], "4C4F");		/* 64  */
  strcpy(T3270[785], "4C50");		/* 65  */
  strcpy(T3270[786], "4CD1");		/* 66  */
  strcpy(T3270[787], "4CD2");		/* 67  */
  strcpy(T3270[788], "4CD3");		/* 68  */
  strcpy(T3270[789], "4CD4");		/* 69  */
  strcpy(T3270[790], "4CD5");		/* 70  */
  strcpy(T3270[791], "4CD6");		/* 71  */
  strcpy(T3270[792], "4CD7");		/* 72  */
  strcpy(T3270[793], "4CD8");		/* 73  */
  strcpy(T3270[794], "4CD9");		/* 74  */
  strcpy(T3270[795], "4C5A");		/* 75  */
  strcpy(T3270[796], "4C5B");		/* 76  */
  strcpy(T3270[797], "4C5C");		/* 77  */
  strcpy(T3270[798], "4C5D");		/* 78  */
  strcpy(T3270[799], "4C5E");		/* 79  */
  strcpy(T3270[800], "4C5F");		/* 80  */


/* row  11  col 1 thru 80 */
  strcpy(T3270[801], "4C60");		/* 1  */
  strcpy(T3270[802], "4C61");		/* 2  */
  strcpy(T3270[803], "4CE2");		/* 3  */
  strcpy(T3270[804], "4CE3");		/* 4  */
  strcpy(T3270[805], "4CE4");		/* 5  */
  strcpy(T3270[806], "4CE5");		/* 6  */
  strcpy(T3270[807], "4CE6");		/* 7  */
  strcpy(T3270[808], "4CE7");		/* 8  */
  strcpy(T3270[809], "4CE8");		/* 9  */
  strcpy(T3270[810], "4CE9");		/* 10  */
  strcpy(T3270[811], "4C6A");		/* 11  */
  strcpy(T3270[812], "4C6B");		/* 12  */
  strcpy(T3270[813], "4C6C");		/* 13  */
  strcpy(T3270[814], "4C6D");		/* 14  */
  strcpy(T3270[815], "4C6E");		/* 15  */
  strcpy(T3270[816], "4C6F");		/* 16  */
  strcpy(T3270[817], "4CF0");		/* 17  */
  strcpy(T3270[818], "4CF1");		/* 18  */
  strcpy(T3270[819], "4CF2");		/* 19  */
  strcpy(T3270[820], "4CF3");		/* 20  */
  strcpy(T3270[821], "4CF4");		/* 21  */
  strcpy(T3270[822], "4CF5");		/* 22  */
  strcpy(T3270[823], "4CF6");		/* 23  */
  strcpy(T3270[824], "4CF7");		/* 24  */
  strcpy(T3270[825], "4CF8");		/* 25  */
  strcpy(T3270[826], "4CF9");		/* 26  */
  strcpy(T3270[827], "4C7A");		/* 27  */
  strcpy(T3270[828], "4C7B");		/* 28  */
  strcpy(T3270[829], "4C7C");		/* 29  */
  strcpy(T3270[830], "4C7D");		/* 30  */
  strcpy(T3270[831], "4C7E");		/* 31  */
  strcpy(T3270[832], "4C7F");		/* 32  */
  strcpy(T3270[833], "4D40");		/* 33  */
  strcpy(T3270[834], "4DC1");		/* 34  */
  strcpy(T3270[835], "4DC2");		/* 35  */
  strcpy(T3270[836], "4DC3");		/* 36  */
  strcpy(T3270[837], "4DC4");		/* 37  */
  strcpy(T3270[838], "4DC5");		/* 38  */
  strcpy(T3270[839], "4DC6");		/* 39  */
  strcpy(T3270[840], "4DC7");		/* 40  */
  strcpy(T3270[841], "4DC8");		/* 41  */
  strcpy(T3270[842], "4DC9");		/* 42  */
  strcpy(T3270[843], "4D4A");		/* 43  */
  strcpy(T3270[844], "4D4B");		/* 44  */
  strcpy(T3270[845], "4D4C");		/* 45  */
  strcpy(T3270[846], "4D4D");		/* 46  */
  strcpy(T3270[847], "4D4E");		/* 47  */
  strcpy(T3270[848], "4D4F");		/* 48  */
  strcpy(T3270[849], "4D50");		/* 49  */
  strcpy(T3270[850], "4DD1");		/* 50  */
  strcpy(T3270[851], "4DD2");		/* 51  */
  strcpy(T3270[852], "4DD3");		/* 52  */
  strcpy(T3270[853], "4DD4");		/* 53  */
  strcpy(T3270[854], "4DD5");		/* 54  */
  strcpy(T3270[855], "4DD6");		/* 55  */
  strcpy(T3270[856], "4DD7");		/* 56  */
  strcpy(T3270[857], "4DD8");		/* 57  */
  strcpy(T3270[858], "4DD9");		/* 58  */
  strcpy(T3270[859], "4D5A");		/* 59  */
  strcpy(T3270[860], "4D5B");		/* 60  */
  strcpy(T3270[861], "4D5C");		/* 61  */
  strcpy(T3270[862], "4D5D");		/* 62  */
  strcpy(T3270[863], "4D5E");		/* 63  */
  strcpy(T3270[864], "4D5F");		/* 64  */
  strcpy(T3270[865], "4D60");		/* 65  */
  strcpy(T3270[866], "4D61");		/* 66  */
  strcpy(T3270[867], "4DE2");		/* 67  */
  strcpy(T3270[868], "4DE3");		/* 68  */
  strcpy(T3270[869], "4DE4");		/* 69  */
  strcpy(T3270[870], "4DE5");		/* 70  */
  strcpy(T3270[871], "4DE6");		/* 71  */
  strcpy(T3270[872], "4DE7");		/* 72  */
  strcpy(T3270[873], "4DE8");		/* 73  */
  strcpy(T3270[874], "4DE9");		/* 74  */
  strcpy(T3270[875], "4D6A");		/* 75  */
  strcpy(T3270[876], "4D6B");		/* 76  */
  strcpy(T3270[877], "4D6C");		/* 77  */
  strcpy(T3270[878], "4D6D");		/* 78  */
  strcpy(T3270[879], "4D6E");		/* 79  */
  strcpy(T3270[880], "4D6F");		/* 80  */


/* row  12  col 1 thru 80 */
  strcpy(T3270[881], "4DF0");		/* 1  */
  strcpy(T3270[882], "4DF1");		/* 2  */
  strcpy(T3270[883], "4DF2");		/* 3  */
  strcpy(T3270[884], "4DF3");		/* 4  */
  strcpy(T3270[885], "4DF4");		/* 5  */
  strcpy(T3270[886], "4DF5");		/* 6  */
  strcpy(T3270[887], "4DF6");		/* 7  */
  strcpy(T3270[888], "4DF7");		/* 8  */
  strcpy(T3270[889], "4DF8");		/* 9  */
  strcpy(T3270[890], "4DF9");		/* 10  */
  strcpy(T3270[891], "4D7A");		/* 11  */
  strcpy(T3270[892], "4D7B");		/* 12  */
  strcpy(T3270[893], "4D7C");		/* 13  */
  strcpy(T3270[894], "4D7D");		/* 14  */
  strcpy(T3270[895], "4D7E");		/* 15  */
  strcpy(T3270[896], "4D7F");		/* 16  */
  strcpy(T3270[897], "4E40");		/* 17  */
  strcpy(T3270[898], "4EC1");		/* 18  */
  strcpy(T3270[899], "4EC2");		/* 19  */
  strcpy(T3270[900], "4EC3");		/* 20  */
  strcpy(T3270[901], "4EC4");		/* 21  */
  strcpy(T3270[902], "4EC5");		/* 22  */
  strcpy(T3270[903], "4EC6");		/* 23  */
  strcpy(T3270[904], "4EC7");		/* 24  */
  strcpy(T3270[905], "4EC8");		/* 25  */
  strcpy(T3270[906], "4EC9");		/* 26  */
  strcpy(T3270[907], "4E4A");		/* 27  */
  strcpy(T3270[908], "4E4B");		/* 28  */
  strcpy(T3270[909], "4E4C");		/* 29  */
  strcpy(T3270[910], "4E4D");		/* 30  */
  strcpy(T3270[911], "4E4E");		/* 31  */
  strcpy(T3270[912], "4E4F");		/* 32  */
  strcpy(T3270[913], "4E50");		/* 33  */
  strcpy(T3270[914], "4ED1");		/* 34  */
  strcpy(T3270[915], "4ED2");		/* 35  */
  strcpy(T3270[916], "4ED3");		/* 36  */
  strcpy(T3270[917], "4ED4");		/* 37  */
  strcpy(T3270[918], "4ED5");		/* 38  */
  strcpy(T3270[919], "4ED6");		/* 39  */
  strcpy(T3270[920], "4ED7");		/* 40  */
  strcpy(T3270[921], "4ED8");		/* 41  */
  strcpy(T3270[922], "4ED9");		/* 42  */
  strcpy(T3270[923], "4E5A");		/* 43  */
  strcpy(T3270[924], "4E5B");		/* 44  */
  strcpy(T3270[925], "4E5C");		/* 45  */
  strcpy(T3270[926], "4E5D");		/* 46  */
  strcpy(T3270[927], "4E5E");		/* 47  */
  strcpy(T3270[928], "4E5F");		/* 48  */
  strcpy(T3270[929], "4E60");		/* 49  */
  strcpy(T3270[930], "4E61");		/* 50  */
  strcpy(T3270[931], "4EE2");		/* 51  */
  strcpy(T3270[932], "4EE3");		/* 52  */
  strcpy(T3270[933], "4EE4");		/* 53  */
  strcpy(T3270[934], "4EE5");		/* 54  */
  strcpy(T3270[935], "4EE6");		/* 55  */
  strcpy(T3270[936], "4EE7");		/* 56  */
  strcpy(T3270[937], "4EE8");		/* 57  */
  strcpy(T3270[938], "4EE9");		/* 58  */
  strcpy(T3270[939], "4E6A");		/* 59  */
  strcpy(T3270[940], "4E6B");		/* 60  */
  strcpy(T3270[941], "4E6C");		/* 61  */
  strcpy(T3270[942], "4E6D");		/* 62  */
  strcpy(T3270[943], "4E6E");		/* 63  */
  strcpy(T3270[944], "4E6F");		/* 64  */
  strcpy(T3270[945], "4EF0");		/* 65  */
  strcpy(T3270[946], "4EF1");		/* 66  */
  strcpy(T3270[947], "4EF2");		/* 67  */
  strcpy(T3270[948], "4EF3");		/* 68  */
  strcpy(T3270[949], "4EF4");		/* 69  */
  strcpy(T3270[950], "4EF5");		/* 70  */
  strcpy(T3270[951], "4EF6");		/* 71  */
  strcpy(T3270[952], "4EF7");		/* 72  */
  strcpy(T3270[953], "4EF8");		/* 73  */
  strcpy(T3270[954], "4EF9");		/* 74  */
  strcpy(T3270[955], "4E7A");		/* 75  */
  strcpy(T3270[956], "4E7B");		/* 76  */
  strcpy(T3270[957], "4E7C");		/* 77  */
  strcpy(T3270[958], "4E7D");		/* 78  */
  strcpy(T3270[959], "4E7E");		/* 79  */
  strcpy(T3270[960], "4E7F");		/* 80  */


/* row  13  col 1 thru 80 */
  strcpy(T3270[961], "4F40");		/* 1  */
  strcpy(T3270[962], "4FC1");		/* 2  */
  strcpy(T3270[963], "4FC2");		/* 3  */
  strcpy(T3270[964], "4FC3");		/* 4  */
  strcpy(T3270[965], "4FC4");		/* 5  */
  strcpy(T3270[966], "4FC5");		/* 6  */
  strcpy(T3270[967], "4FC6");		/* 7  */
  strcpy(T3270[968], "4FC7");		/* 8  */
  strcpy(T3270[969], "4FC8");		/* 9  */
  strcpy(T3270[970], "4FC9");		/* 10  */
  strcpy(T3270[971], "4F4A");		/* 11  */
  strcpy(T3270[972], "4F4B");		/* 12  */
  strcpy(T3270[973], "4F4C");		/* 13  */
  strcpy(T3270[974], "4F4D");		/* 14  */
  strcpy(T3270[975], "4F4E");		/* 15  */
  strcpy(T3270[976], "4F4F");		/* 16  */
  strcpy(T3270[977], "4F50");		/* 17  */
  strcpy(T3270[978], "4DF1");		/* 18  */
  strcpy(T3270[979], "4FD2");		/* 19  */
  strcpy(T3270[980], "4FD3");		/* 20  */
  strcpy(T3270[981], "4FD4");		/* 21  */
  strcpy(T3270[982], "4FD5");		/* 22  */
  strcpy(T3270[983], "4FD6");		/* 23  */
  strcpy(T3270[984], "4FD7");		/* 24  */
  strcpy(T3270[985], "4FD8");		/* 25  */
  strcpy(T3270[986], "4FD9");		/* 26  */
  strcpy(T3270[987], "4F5A");		/* 27  */
  strcpy(T3270[988], "4F5B");		/* 28  */
  strcpy(T3270[989], "4F5C");		/* 29  */
  strcpy(T3270[990], "4F5D");		/* 30  */
  strcpy(T3270[991], "4F5E");		/* 31  */
  strcpy(T3270[992], "4F5F");		/* 32  */
  strcpy(T3270[993], "4F60");		/* 33  */
  strcpy(T3270[994], "4F61");		/* 34  */
  strcpy(T3270[995], "4FE2");		/* 35  */
  strcpy(T3270[996], "4FE3");		/* 36  */
  strcpy(T3270[997], "4FE4");		/* 37  */
  strcpy(T3270[998], "4FE5");		/* 38  */
  strcpy(T3270[999], "4FE6");		/* 39  */
  strcpy(T3270[1000], "4FE7");		/* 40  */
  strcpy(T3270[1001], "4FE8");		/* 41  */
  strcpy(T3270[1002], "4FE9");		/* 42  */
  strcpy(T3270[1003], "4F6A");		/* 43  */
  strcpy(T3270[1004], "4F6B");		/* 44  */
  strcpy(T3270[1005], "4F6C");		/* 45  */
  strcpy(T3270[1006], "4F6D");		/* 46  */
  strcpy(T3270[1007], "4F6E");		/* 47  */
  strcpy(T3270[1008], "4F6F");		/* 48  */
  strcpy(T3270[1009], "4FF0");		/* 49  */
  strcpy(T3270[1010], "4FF1");		/* 50  */
  strcpy(T3270[1011], "4FF2");		/* 51  */
  strcpy(T3270[1012], "4FF3");		/* 52  */
  strcpy(T3270[1013], "4FF4");		/* 53  */
  strcpy(T3270[1014], "4FF5");		/* 54  */
  strcpy(T3270[1015], "4FF6");		/* 55  */
  strcpy(T3270[1016], "4FF7");		/* 56  */
  strcpy(T3270[1017], "4FF8");		/* 57  */
  strcpy(T3270[1018], "4FF9");		/* 58  */
  strcpy(T3270[1019], "4F7A");		/* 59  */
  strcpy(T3270[1020], "4F7B");		/* 60  */
  strcpy(T3270[1021], "4F7C");		/* 61  */
  strcpy(T3270[1022], "4F7D");		/* 62  */
  strcpy(T3270[1023], "4F7E");		/* 63  */
  strcpy(T3270[1024], "4F7F");		/* 64  */
  strcpy(T3270[1025], "5040");		/* 65  */
  strcpy(T3270[1026], "50C1");		/* 66  */
  strcpy(T3270[1027], "50C2");		/* 67  */
  strcpy(T3270[1028], "50C3");		/* 68  */
  strcpy(T3270[1029], "50C4");		/* 69  */
  strcpy(T3270[1030], "50C5");		/* 70  */
  strcpy(T3270[1031], "50C6");		/* 71  */
  strcpy(T3270[1032], "50C7");		/* 72  */
  strcpy(T3270[1033], "50C8");		/* 73  */
  strcpy(T3270[1034], "50C9");		/* 74  */
  strcpy(T3270[1035], "504A");		/* 75  */
  strcpy(T3270[1036], "504B");		/* 76  */
  strcpy(T3270[1037], "504C");		/* 77  */
  strcpy(T3270[1038], "504D");		/* 78  */
  strcpy(T3270[1039], "504E");		/* 79  */
  strcpy(T3270[1040], "504F");		/* 80  */


/* row  14  col 1 thru 80 */
  strcpy(T3270[1041], "5050");		/* 1  */
  strcpy(T3270[1042], "50D1");		/* 2  */
  strcpy(T3270[1043], "50D2");		/* 3  */
  strcpy(T3270[1044], "50D3");		/* 4  */
  strcpy(T3270[1045], "50D4");		/* 5  */
  strcpy(T3270[1046], "50D5");		/* 6  */
  strcpy(T3270[1047], "50D6");		/* 7  */
  strcpy(T3270[1048], "50D7");		/* 8  */
  strcpy(T3270[1049], "50D8");		/* 9  */
  strcpy(T3270[1050], "50D9");		/* 10  */
  strcpy(T3270[1051], "505A");		/* 11  */
  strcpy(T3270[1052], "505B");		/* 12  */
  strcpy(T3270[1053], "505C");		/* 13  */
  strcpy(T3270[1054], "505D");		/* 14  */
  strcpy(T3270[1055], "505E");		/* 15  */
  strcpy(T3270[1056], "505F");		/* 16  */
  strcpy(T3270[1057], "5060");		/* 17  */
  strcpy(T3270[1058], "5061");		/* 18  */
  strcpy(T3270[1059], "50E2");		/* 19  */
  strcpy(T3270[1060], "50E3");		/* 20  */
  strcpy(T3270[1061], "50E4");		/* 21  */
  strcpy(T3270[1062], "50E5");		/* 22  */
  strcpy(T3270[1063], "50E6");		/* 23  */
  strcpy(T3270[1064], "50E7");		/* 24  */
  strcpy(T3270[1065], "50E8");		/* 25  */
  strcpy(T3270[1066], "50E9");		/* 26  */
  strcpy(T3270[1067], "506A");		/* 27  */
  strcpy(T3270[1068], "506B");		/* 28  */
  strcpy(T3270[1069], "506C");		/* 29  */
  strcpy(T3270[1070], "506D");		/* 30  */
  strcpy(T3270[1071], "506E");		/* 31  */
  strcpy(T3270[1072], "506F");		/* 32  */
  strcpy(T3270[1073], "50F0");		/* 33  */
  strcpy(T3270[1074], "50F1");		/* 34  */
  strcpy(T3270[1075], "50F2");		/* 35  */
  strcpy(T3270[1076], "50F3");		/* 36  */
  strcpy(T3270[1077], "50F4");		/* 37  */
  strcpy(T3270[1078], "50F5");		/* 38  */
  strcpy(T3270[1079], "50F6");		/* 39  */
  strcpy(T3270[1080], "50F7");		/* 40  */
  strcpy(T3270[1081], "50F8");		/* 41  */
  strcpy(T3270[1082], "50F9");		/* 42  */
  strcpy(T3270[1083], "507A");		/* 43  */
  strcpy(T3270[1084], "507B");		/* 44  */
  strcpy(T3270[1085], "507C");		/* 45  */
  strcpy(T3270[1086], "507D");		/* 46  */
  strcpy(T3270[1087], "507E");		/* 47  */
  strcpy(T3270[1088], "507F");		/* 48  */
  strcpy(T3270[1089], "D140");		/* 49  */
  strcpy(T3270[1090], "D1C1");		/* 50  */
  strcpy(T3270[1091], "D1C2");		/* 51  */
  strcpy(T3270[1092], "D1C3");		/* 52  */
  strcpy(T3270[1093], "D1C4");		/* 53  */
  strcpy(T3270[1094], "D1C5");		/* 54  */
  strcpy(T3270[1095], "D1C6");		/* 55  */
  strcpy(T3270[1096], "D1C7");		/* 56  */
  strcpy(T3270[1097], "D1C8");		/* 57  */
  strcpy(T3270[1098], "D1C9");		/* 58  */
  strcpy(T3270[1099], "D14A");		/* 59  */
  strcpy(T3270[1100], "D14B");		/* 60  */
  strcpy(T3270[1101], "D14C");		/* 61  */
  strcpy(T3270[1102], "D14D");		/* 62  */
  strcpy(T3270[1103], "D14E");		/* 63  */
  strcpy(T3270[1104], "D14F");		/* 64  */
  strcpy(T3270[1105], "D150");		/* 65  */
  strcpy(T3270[1106], "D1D1");		/* 66  */
  strcpy(T3270[1107], "D1D2");		/* 67  */
  strcpy(T3270[1108], "D1D3");		/* 68  */
  strcpy(T3270[1109], "D1D4");		/* 69  */
  strcpy(T3270[1110], "D1D5");		/* 70  */
  strcpy(T3270[1111], "D1D6");		/* 71  */
  strcpy(T3270[1112], "D1D7");		/* 72  */
  strcpy(T3270[1113], "D1D8");		/* 73  */
  strcpy(T3270[1114], "D1D9");		/* 74  */
  strcpy(T3270[1115], "D15A");		/* 75  */
  strcpy(T3270[1116], "D15B");		/* 76  */
  strcpy(T3270[1117], "D15C");		/* 77  */
  strcpy(T3270[1118], "D15D");		/* 78  */
  strcpy(T3270[1119], "D15E");		/* 79  */
  strcpy(T3270[1120], "D15F");		/* 80  */


/* row  15  col 1 thru 80 */
  strcpy(T3270[1121], "D160");		/* 1  */
  strcpy(T3270[1122], "D161");		/* 2  */
  strcpy(T3270[1123], "D1E2");		/* 3  */
  strcpy(T3270[1124], "D1E3");		/* 4  */
  strcpy(T3270[1125], "D1E4");		/* 5  */
  strcpy(T3270[1126], "D1E5");		/* 6  */
  strcpy(T3270[1127], "D1E6");		/* 7  */
  strcpy(T3270[1128], "D1E7");		/* 8  */
  strcpy(T3270[1129], "D1E8");		/* 9  */
  strcpy(T3270[1130], "D1E9");		/* 10  */
  strcpy(T3270[1131], "D16A");		/* 11  */
  strcpy(T3270[1132], "D16B");		/* 12  */
  strcpy(T3270[1133], "D16C");		/* 13  */
  strcpy(T3270[1134], "D16D");		/* 14  */
  strcpy(T3270[1135], "D16E");		/* 15  */
  strcpy(T3270[1136], "D16F");		/* 16  */
  strcpy(T3270[1137], "D1F0");		/* 17  */
  strcpy(T3270[1138], "D1F1");		/* 18  */
  strcpy(T3270[1139], "D1F2");		/* 19  */
  strcpy(T3270[1140], "D1F3");		/* 20  */
  strcpy(T3270[1141], "D1F4");		/* 21  */
  strcpy(T3270[1142], "D1F5");		/* 22  */
  strcpy(T3270[1143], "D1F6");		/* 23  */
  strcpy(T3270[1144], "D1F7");		/* 24  */
  strcpy(T3270[1145], "D1F8");		/* 25  */
  strcpy(T3270[1146], "D1F9");		/* 26  */
  strcpy(T3270[1147], "D17A");		/* 27  */
  strcpy(T3270[1148], "D17B");		/* 28  */
  strcpy(T3270[1149], "D17C");		/* 29  */
  strcpy(T3270[1150], "D17D");		/* 30  */
  strcpy(T3270[1151], "D17E");		/* 31  */
  strcpy(T3270[1152], "D17F");		/* 32  */
  strcpy(T3270[1153], "D240");		/* 33  */
  strcpy(T3270[1154], "D2C1");		/* 34  */
  strcpy(T3270[1155], "D2C2");		/* 35  */
  strcpy(T3270[1156], "D2C3");		/* 36  */
  strcpy(T3270[1157], "D2C4");		/* 37  */
  strcpy(T3270[1158], "D2C5");		/* 38  */
  strcpy(T3270[1159], "D2C6");		/* 39  */
  strcpy(T3270[1160], "D2C7");		/* 40  */
  strcpy(T3270[1161], "D2C8");		/* 41  */
  strcpy(T3270[1162], "D2C9");		/* 42  */
  strcpy(T3270[1163], "D24A");		/* 43  */
  strcpy(T3270[1164], "D24B");		/* 44  */
  strcpy(T3270[1165], "D24C");		/* 45  */
  strcpy(T3270[1166], "D24D");		/* 46  */
  strcpy(T3270[1167], "D24E");		/* 47  */
  strcpy(T3270[1168], "D24F");		/* 48  */
  strcpy(T3270[1169], "D250");		/* 49  */
  strcpy(T3270[1170], "D2D1");		/* 50  */
  strcpy(T3270[1171], "D2D2");		/* 51  */
  strcpy(T3270[1172], "D2D3");		/* 52  */
  strcpy(T3270[1173], "D2D4");		/* 53  */
  strcpy(T3270[1174], "D2D5");		/* 54  */
  strcpy(T3270[1175], "D2D6");		/* 55  */
  strcpy(T3270[1176], "D2D7");		/* 56  */
  strcpy(T3270[1177], "D2D8");		/* 57  */
  strcpy(T3270[1178], "D2D9");		/* 58  */
  strcpy(T3270[1179], "D25A");		/* 59  */
  strcpy(T3270[1180], "D25B");		/* 60  */
  strcpy(T3270[1181], "D25C");		/* 61  */
  strcpy(T3270[1182], "D25D");		/* 62  */
  strcpy(T3270[1183], "D25E");		/* 63  */
  strcpy(T3270[1184], "D25F");		/* 64  */
  strcpy(T3270[1185], "D260");		/* 65  */
  strcpy(T3270[1186], "D261");		/* 66  */
  strcpy(T3270[1187], "D2E2");		/* 67  */
  strcpy(T3270[1188], "D2E3");		/* 68  */
  strcpy(T3270[1189], "D2E4");		/* 69  */
  strcpy(T3270[1190], "D2E5");		/* 70  */
  strcpy(T3270[1191], "D2E6");		/* 71  */
  strcpy(T3270[1192], "D2E7");		/* 72  */
  strcpy(T3270[1193], "D2E8");		/* 73  */
  strcpy(T3270[1194], "D2E9");		/* 74  */
  strcpy(T3270[1195], "D26A");		/* 75  */
  strcpy(T3270[1196], "D26B");		/* 76  */
  strcpy(T3270[1197], "D26C");		/* 77  */
  strcpy(T3270[1198], "D26D");		/* 78  */
  strcpy(T3270[1199], "D26E");		/* 79  */
  strcpy(T3270[1200], "D26F");		/* 80  */


/* row  16  col 1 thru 80 */
  strcpy(T3270[1201], "D2F0");		/* 1  */
  strcpy(T3270[1202], "D2F1");		/* 2  */
  strcpy(T3270[1203], "D2F2");		/* 3  */
  strcpy(T3270[1204], "D2F3");		/* 4  */
  strcpy(T3270[1205], "D2F4");		/* 5  */
  strcpy(T3270[1206], "D2F5");		/* 6  */
  strcpy(T3270[1207], "D2F6");		/* 7  */
  strcpy(T3270[1208], "D2F7");		/* 8  */
  strcpy(T3270[1209], "D2F8");		/* 9  */
  strcpy(T3270[1210], "D2F9");		/* 10  */
  strcpy(T3270[1211], "D27A");		/* 11  */
  strcpy(T3270[1212], "D27B");		/* 12  */
  strcpy(T3270[1213], "D27C");		/* 13  */
  strcpy(T3270[1214], "D27D");		/* 14  */
  strcpy(T3270[1215], "D27E");		/* 15  */
  strcpy(T3270[1216], "D27F");		/* 16  */
  strcpy(T3270[1217], "D340");		/* 17  */
  strcpy(T3270[1218], "D3C1");		/* 18  */
  strcpy(T3270[1219], "D3C2");		/* 19  */
  strcpy(T3270[1220], "D3C3");		/* 20  */
  strcpy(T3270[1221], "D3C4");		/* 21  */
  strcpy(T3270[1222], "D3C5");		/* 22  */
  strcpy(T3270[1223], "D3C6");		/* 23  */
  strcpy(T3270[1224], "D3C7");		/* 24  */
  strcpy(T3270[1225], "D3C8");		/* 25  */
  strcpy(T3270[1226], "D3C9");		/* 26  */
  strcpy(T3270[1227], "D34A");		/* 27  */
  strcpy(T3270[1228], "D34B");		/* 28  */
  strcpy(T3270[1229], "D34C");		/* 29  */
  strcpy(T3270[1230], "D34D");		/* 30  */
  strcpy(T3270[1231], "D34E");		/* 31  */
  strcpy(T3270[1232], "D34F");		/* 32  */
  strcpy(T3270[1233], "D350");		/* 33  */
  strcpy(T3270[1234], "D3D1");		/* 34  */
  strcpy(T3270[1235], "D3D2");		/* 35  */
  strcpy(T3270[1236], "D3D3");		/* 36  */
  strcpy(T3270[1237], "D3D4");		/* 37  */
  strcpy(T3270[1238], "D3D5");		/* 38  */
  strcpy(T3270[1239], "D3D6");		/* 39  */
  strcpy(T3270[1240], "D3D7");		/* 40  */
  strcpy(T3270[1241], "D3D8");		/* 41  */
  strcpy(T3270[1242], "D3D9");		/* 42  */
  strcpy(T3270[1243], "D35A");		/* 43  */
  strcpy(T3270[1244], "D35B");		/* 44  */
  strcpy(T3270[1245], "D35C");		/* 45  */
  strcpy(T3270[1246], "D35D");		/* 46  */
  strcpy(T3270[1247], "D35E");		/* 47  */
  strcpy(T3270[1248], "D35F");		/* 48  */
  strcpy(T3270[1249], "D360");		/* 49  */
  strcpy(T3270[1250], "D361");		/* 50  */
  strcpy(T3270[1251], "D3E2");		/* 51  */
  strcpy(T3270[1252], "D3E3");		/* 52  */
  strcpy(T3270[1253], "D3E4");		/* 53  */
  strcpy(T3270[1254], "D3E5");		/* 54  */
  strcpy(T3270[1255], "D3E6");		/* 55  */
  strcpy(T3270[1256], "D3E7");		/* 56  */
  strcpy(T3270[1257], "D3E8");		/* 57  */
  strcpy(T3270[1258], "D3E9");		/* 58  */
  strcpy(T3270[1259], "D36A");		/* 59  */
  strcpy(T3270[1260], "D36B");		/* 60  */
  strcpy(T3270[1261], "D36C");		/* 61  */
  strcpy(T3270[1262], "D36D");		/* 62  */
  strcpy(T3270[1263], "D36E");		/* 63  */
  strcpy(T3270[1264], "D36F");		/* 64  */
  strcpy(T3270[1265], "D3F0");		/* 65  */
  strcpy(T3270[1266], "D3F1");		/* 66  */
  strcpy(T3270[1267], "D3F2");		/* 67  */
  strcpy(T3270[1268], "D3F3");		/* 68  */
  strcpy(T3270[1269], "D3F4");		/* 69  */
  strcpy(T3270[1270], "D3F5");		/* 70  */
  strcpy(T3270[1271], "D3F6");		/* 71  */
  strcpy(T3270[1272], "D3F7");		/* 72  */
  strcpy(T3270[1273], "D3F8");		/* 73  */
  strcpy(T3270[1274], "D3F9");		/* 74  */
  strcpy(T3270[1275], "D37A");		/* 75  */
  strcpy(T3270[1276], "D37B");		/* 76  */
  strcpy(T3270[1277], "D37C");		/* 77  */
  strcpy(T3270[1278], "D37D");		/* 78  */
  strcpy(T3270[1279], "D37E");		/* 79  */
  strcpy(T3270[1280], "D37F");		/* 80  */


/* row  17  col 1 thru 80 */
  strcpy(T3270[1281], "D440");		/* 1  */
  strcpy(T3270[1282], "D4C1");		/* 2  */
  strcpy(T3270[1283], "D4C2");		/* 3  */
  strcpy(T3270[1284], "D4C3");		/* 4  */
  strcpy(T3270[1285], "D4C4");		/* 5  */
  strcpy(T3270[1286], "D4C5");		/* 6  */
  strcpy(T3270[1287], "D4C6");		/* 7  */
  strcpy(T3270[1288], "D4C7");		/* 8  */
  strcpy(T3270[1289], "D4C8");		/* 9  */
  strcpy(T3270[1290], "D4C9");		/* 10  */
  strcpy(T3270[1291], "D44A");		/* 11  */
  strcpy(T3270[1292], "D44B");		/* 12  */
  strcpy(T3270[1293], "D44C");		/* 13  */
  strcpy(T3270[1294], "D44D");		/* 14  */
  strcpy(T3270[1295], "D44E");		/* 15  */
  strcpy(T3270[1296], "D44F");		/* 16  */
  strcpy(T3270[1297], "D450");		/* 17  */
  strcpy(T3270[1298], "D4D1");		/* 18  */
  strcpy(T3270[1299], "D4D2");		/* 19  */
  strcpy(T3270[1300], "D4D3");		/* 20  */
  strcpy(T3270[1301], "D4D4");		/* 21  */
  strcpy(T3270[1302], "D4D5");		/* 22  */
  strcpy(T3270[1303], "D4D6");		/* 23  */
  strcpy(T3270[1304], "D4D7");		/* 24  */
  strcpy(T3270[1305], "D4D8");		/* 25  */
  strcpy(T3270[1306], "D4D9");		/* 26  */
  strcpy(T3270[1307], "D45A");		/* 27  */
  strcpy(T3270[1308], "D45B");		/* 28  */
  strcpy(T3270[1309], "D45C");		/* 29  */
  strcpy(T3270[1310], "D45D");		/* 30  */
  strcpy(T3270[1311], "D45E");		/* 31  */
  strcpy(T3270[1312], "D45F");		/* 32  */
  strcpy(T3270[1313], "D460");		/* 33  */
  strcpy(T3270[1314], "D461");		/* 34  */
  strcpy(T3270[1315], "D4E2");		/* 35  */
  strcpy(T3270[1316], "D4E3");		/* 36  */
  strcpy(T3270[1317], "D4E4");		/* 37  */
  strcpy(T3270[1318], "D4E5");		/* 38  */
  strcpy(T3270[1319], "D4E6");		/* 39  */
  strcpy(T3270[1320], "D4E7");		/* 40  */
  strcpy(T3270[1321], "D4E8");		/* 41  */
  strcpy(T3270[1322], "D4E9");		/* 42  */
  strcpy(T3270[1323], "D46A");		/* 43  */
  strcpy(T3270[1324], "D46B");		/* 44  */
  strcpy(T3270[1325], "D46C");		/* 45  */
  strcpy(T3270[1326], "D46D");		/* 46  */
  strcpy(T3270[1327], "D46E");		/* 47  */
  strcpy(T3270[1328], "D46F");		/* 48  */
  strcpy(T3270[1329], "D4F0");		/* 49  */
  strcpy(T3270[1330], "D4F1");		/* 50  */
  strcpy(T3270[1331], "D4F2");		/* 51  */
  strcpy(T3270[1332], "D4F3");		/* 52  */
  strcpy(T3270[1333], "D4F4");		/* 53  */
  strcpy(T3270[1334], "D4F5");		/* 54  */
  strcpy(T3270[1335], "D4F6");		/* 55  */
  strcpy(T3270[1336], "D4F7");		/* 56  */
  strcpy(T3270[1337], "D4F8");		/* 57  */
  strcpy(T3270[1338], "D4F9");		/* 58  */
  strcpy(T3270[1339], "D47A");		/* 59  */
  strcpy(T3270[1340], "D47B");		/* 60  */
  strcpy(T3270[1341], "D47C");		/* 61  */
  strcpy(T3270[1342], "D47D");		/* 62  */
  strcpy(T3270[1343], "D47E");		/* 63  */
  strcpy(T3270[1344], "D47F");		/* 64  */
  strcpy(T3270[1345], "D540");		/* 65  */
  strcpy(T3270[1346], "D5C1");		/* 66  */
  strcpy(T3270[1347], "D5C2");		/* 67  */
  strcpy(T3270[1348], "D5C3");		/* 68  */
  strcpy(T3270[1349], "D5C4");		/* 69  */
  strcpy(T3270[1350], "D5C5");		/* 70  */
  strcpy(T3270[1351], "D5C6");		/* 71  */
  strcpy(T3270[1352], "D5C7");		/* 72  */
  strcpy(T3270[1353], "D5C8");		/* 73  */
  strcpy(T3270[1354], "D5C9");		/* 74  */
  strcpy(T3270[1355], "D54A");		/* 75  */
  strcpy(T3270[1356], "D54B");		/* 76  */
  strcpy(T3270[1357], "D54C");		/* 77  */
  strcpy(T3270[1358], "D54D");		/* 78  */
  strcpy(T3270[1359], "D54E");		/* 79  */
  strcpy(T3270[1360], "D54F");		/* 80  */


/* row  18  col 1 thru 80 */
  strcpy(T3270[1361], "D550");		/* 1  */
  strcpy(T3270[1362], "D5D1");		/* 2  */
  strcpy(T3270[1363], "D5D2");		/* 3  */
  strcpy(T3270[1364], "D5D3");		/* 4  */
  strcpy(T3270[1365], "D5D4");		/* 5  */
  strcpy(T3270[1366], "D5D5");		/* 6  */
  strcpy(T3270[1367], "D5D6");		/* 7  */
  strcpy(T3270[1368], "D5D7");		/* 8  */
  strcpy(T3270[1369], "D5D8");		/* 9  */
  strcpy(T3270[1370], "D5D9");		/* 10  */
  strcpy(T3270[1371], "D55A");		/* 11  */
  strcpy(T3270[1372], "D55B");		/* 12  */
  strcpy(T3270[1373], "D55C");		/* 13  */
  strcpy(T3270[1374], "D55D");		/* 14  */
  strcpy(T3270[1375], "D55E");		/* 15  */
  strcpy(T3270[1376], "D55F");		/* 16  */
  strcpy(T3270[1377], "D560");		/* 17  */
  strcpy(T3270[1378], "D561");		/* 18  */
  strcpy(T3270[1379], "D5E2");		/* 19  */
  strcpy(T3270[1300], "D5E3");		/* 20  */
  strcpy(T3270[1381], "D4D4");		/* 21  */
  strcpy(T3270[1382], "D4D5");		/* 22  */
  strcpy(T3270[1383], "D4D6");		/* 23  */
  strcpy(T3270[1384], "D4D7");		/* 24  */
  strcpy(T3270[1385], "D4D8");		/* 25  */
  strcpy(T3270[1386], "D4D9");		/* 26  */
  strcpy(T3270[1387], "D45A");		/* 27  */
  strcpy(T3270[1388], "D45B");		/* 28  */
  strcpy(T3270[1389], "D45C");		/* 29  */
  strcpy(T3270[1390], "D45D");		/* 30  */
  strcpy(T3270[1391], "D45E");		/* 31  */
  strcpy(T3270[1392], "D45F");		/* 32  */
  strcpy(T3270[1393], "D5F0");		/* 33  */
  strcpy(T3270[1394], "D5F1");		/* 34  */
  strcpy(T3270[1395], "D5F2");		/* 35  */
  strcpy(T3270[1396], "D5F3");		/* 36  */
  strcpy(T3270[1397], "D5F4");		/* 37  */
  strcpy(T3270[1398], "D5F5");		/* 38  */
  strcpy(T3270[1399], "D5F6");		/* 39  */
  strcpy(T3270[1400], "D5F7");		/* 40  */
  strcpy(T3270[1401], "D5F8");		/* 41  */
  strcpy(T3270[1402], "D5F9");		/* 42  */
  strcpy(T3270[1403], "D57A");		/* 43  */
  strcpy(T3270[1404], "D57B");		/* 44  */
  strcpy(T3270[1405], "D57C");		/* 45  */
  strcpy(T3270[1406], "D57D");		/* 46  */
  strcpy(T3270[1407], "D57E");		/* 47  */
  strcpy(T3270[1408], "D57F");		/* 48  */
  strcpy(T3270[1409], "D640");		/* 49  */
  strcpy(T3270[1410], "D6C1");		/* 50  */
  strcpy(T3270[1411], "D6C2");		/* 51  */
  strcpy(T3270[1412], "D6C3");		/* 52  */
  strcpy(T3270[1413], "D6C4");		/* 53  */
  strcpy(T3270[1414], "D6C5");		/* 54  */
  strcpy(T3270[1415], "D6C6");		/* 55  */
  strcpy(T3270[1416], "D6C7");		/* 56  */
  strcpy(T3270[1417], "D6C8");		/* 57  */
  strcpy(T3270[1418], "D6C9");		/* 58  */
  strcpy(T3270[1419], "D64A");		/* 59  */
  strcpy(T3270[1420], "D64B");		/* 60  */
  strcpy(T3270[1421], "D64C");		/* 61  */
  strcpy(T3270[1422], "D64D");		/* 62  */
  strcpy(T3270[1423], "D64E");		/* 63  */
  strcpy(T3270[1424], "D64F");		/* 64  */
  strcpy(T3270[1425], "D650");		/* 65  */
  strcpy(T3270[1426], "D6D1");		/* 66  */
  strcpy(T3270[1427], "D6D2");		/* 67  */
  strcpy(T3270[1428], "D6D3");		/* 68  */
  strcpy(T3270[1429], "D6D4");		/* 69  */
  strcpy(T3270[1430], "D6D5");		/* 70  */
  strcpy(T3270[1431], "D6D6");		/* 71  */
  strcpy(T3270[1432], "D6D7");		/* 72  */
  strcpy(T3270[1433], "D6D8");		/* 73  */
  strcpy(T3270[1434], "D6D9");		/* 74  */
  strcpy(T3270[1435], "D65A");		/* 75  */
  strcpy(T3270[1436], "D65B");		/* 76  */
  strcpy(T3270[1437], "D65C");		/* 77  */
  strcpy(T3270[1438], "D65D");		/* 78  */
  strcpy(T3270[1439], "D65E");		/* 79  */
  strcpy(T3270[1440], "D65F");		/* 80  */


/* row  19  col 1 thru 80 */
  strcpy(T3270[1441], "D660");		/* 1  */
  strcpy(T3270[1442], "D661");		/* 2  */
  strcpy(T3270[1443], "D6E2");		/* 3  */
  strcpy(T3270[1444], "D6E3");		/* 4  */
  strcpy(T3270[1445], "D6E4");		/* 5  */
  strcpy(T3270[1446], "D6E5");		/* 6  */
  strcpy(T3270[1447], "D6E6");		/* 7  */
  strcpy(T3270[1448], "D6E7");		/* 8  */
  strcpy(T3270[1449], "D6E8");		/* 9  */
  strcpy(T3270[1450], "D6E9");		/* 10  */
  strcpy(T3270[1451], "D66A");		/* 11  */
  strcpy(T3270[1452], "D66B");		/* 12  */
  strcpy(T3270[1453], "D66C");		/* 13  */
  strcpy(T3270[1454], "D66D");		/* 14  */
  strcpy(T3270[1455], "D66E");		/* 15  */
  strcpy(T3270[1456], "D66F");		/* 16  */
  strcpy(T3270[1457], "D6F0");		/* 17  */
  strcpy(T3270[1458], "D6F1");		/* 18  */
  strcpy(T3270[1459], "D6F2");		/* 19  */
  strcpy(T3270[1460], "D6F3");		/* 20  */
  strcpy(T3270[1461], "D6F4");		/* 21  */
  strcpy(T3270[1462], "D6F5");		/* 22  */
  strcpy(T3270[1463], "D6F6");		/* 23  */
  strcpy(T3270[1464], "D6F7");		/* 24  */
  strcpy(T3270[1465], "D6F8");		/* 25  */
  strcpy(T3270[1466], "D6F9");		/* 26  */
  strcpy(T3270[1467], "D67A");		/* 27  */
  strcpy(T3270[1468], "D67B");		/* 28  */
  strcpy(T3270[1469], "D67C");		/* 29  */
  strcpy(T3270[1470], "D67D");		/* 30  */
  strcpy(T3270[1471], "D67E");		/* 31  */
  strcpy(T3270[1472], "D67F");		/* 32  */
  strcpy(T3270[1473], "D740");		/* 33  */
  strcpy(T3270[1474], "D7C1");		/* 34  */
  strcpy(T3270[1475], "D7C2");		/* 35  */
  strcpy(T3270[1476], "D7C3");		/* 36  */
  strcpy(T3270[1477], "D7C4");		/* 37  */
  strcpy(T3270[1478], "D7C5");		/* 38  */
  strcpy(T3270[1479], "D7C6");		/* 39  */
  strcpy(T3270[1480], "D7C7");		/* 40  */
  strcpy(T3270[1481], "D7C8");		/* 41  */
  strcpy(T3270[1482], "D7C9");		/* 42  */
  strcpy(T3270[1483], "D74A");		/* 43  */
  strcpy(T3270[1484], "D74B");		/* 44  */
  strcpy(T3270[1485], "D74C");		/* 45  */
  strcpy(T3270[1486], "D74D");		/* 46  */
  strcpy(T3270[1487], "D74E");		/* 47  */
  strcpy(T3270[1488], "D74F");		/* 48  */
  strcpy(T3270[1489], "D750");		/* 49  */
  strcpy(T3270[1490], "D7D1");		/* 50  */
  strcpy(T3270[1491], "D7D2");		/* 51  */
  strcpy(T3270[1492], "D7D3");		/* 52  */
  strcpy(T3270[1493], "D7D4");		/* 53  */
  strcpy(T3270[1494], "D7D5");		/* 54  */
  strcpy(T3270[1495], "D7D6");		/* 55  */
  strcpy(T3270[1496], "D7D7");		/* 56  */
  strcpy(T3270[1497], "D7D8");		/* 57  */
  strcpy(T3270[1498], "D7D9");		/* 58  */
  strcpy(T3270[1499], "D75A");		/* 59  */
  strcpy(T3270[1500], "D75B");		/* 60  */
  strcpy(T3270[1501], "D75C");		/* 61  */
  strcpy(T3270[1502], "D75D");		/* 62  */
  strcpy(T3270[1503], "D75E");		/* 63  */
  strcpy(T3270[1504], "D75F");		/* 64  */
  strcpy(T3270[1505], "D760");		/* 65  */
  strcpy(T3270[1506], "D761");		/* 66  */
  strcpy(T3270[1507], "D7E2");		/* 67  */
  strcpy(T3270[1508], "D7E3");		/* 68  */
  strcpy(T3270[1509], "D7E4");		/* 69  */
  strcpy(T3270[1510], "D7E5");		/* 70  */
  strcpy(T3270[1511], "D7E6");		/* 71  */
  strcpy(T3270[1512], "D7E7");		/* 72  */
  strcpy(T3270[1513], "D7E8");		/* 73  */
  strcpy(T3270[1514], "D7E9");		/* 74  */
  strcpy(T3270[1515], "D76A");		/* 75  */
  strcpy(T3270[1516], "D76B");		/* 76  */
  strcpy(T3270[1517], "D76C");		/* 77  */
  strcpy(T3270[1518], "D76D");		/* 78  */
  strcpy(T3270[1519], "D76E");		/* 79  */
  strcpy(T3270[1520], "D76F");		/* 80  */


/* row  20  col 1 thru 80 */
  strcpy(T3270[1521], "D7F0");		/* 1  */
  strcpy(T3270[1522], "D7F1");		/* 2  */
  strcpy(T3270[1523], "D7F2");		/* 3  */
  strcpy(T3270[1524], "D7F3");		/* 4  */
  strcpy(T3270[1525], "D7F4");		/* 5  */
  strcpy(T3270[1526], "D7F5");		/* 6  */
  strcpy(T3270[1527], "D7F6");		/* 7  */
  strcpy(T3270[1528], "D7F7");		/* 8  */
  strcpy(T3270[1529], "D7F8");		/* 9  */
  strcpy(T3270[1530], "D7F9");		/* 10  */
  strcpy(T3270[1531], "D77A");		/* 11  */
  strcpy(T3270[1532], "D77B");		/* 12  */
  strcpy(T3270[1533], "D77C");		/* 13  */
  strcpy(T3270[1534], "D77D");		/* 14  */
  strcpy(T3270[1535], "D77E");		/* 15  */
  strcpy(T3270[1536], "D77F");		/* 16  */
  strcpy(T3270[1537], "D840");		/* 17  */
  strcpy(T3270[1538], "D8C1");		/* 18  */
  strcpy(T3270[1539], "D8C2");		/* 19  */
  strcpy(T3270[1540], "D8C3");		/* 20  */
  strcpy(T3270[1541], "D8C4");		/* 21  */
  strcpy(T3270[1542], "D8C5");		/* 22  */
  strcpy(T3270[1543], "D8C6");		/* 23  */
  strcpy(T3270[1544], "D8C7");		/* 24  */
  strcpy(T3270[1545], "DC88");		/* 25  */
  strcpy(T3270[1546], "D8C9");		/* 26  */
  strcpy(T3270[1547], "D84A");		/* 27  */
  strcpy(T3270[1548], "D84B");		/* 28  */
  strcpy(T3270[1549], "D84C");		/* 29  */
  strcpy(T3270[1550], "D84D");		/* 30  */
  strcpy(T3270[1551], "D84E");		/* 31  */
  strcpy(T3270[1552], "D84F");		/* 32  */
  strcpy(T3270[1553], "D850");		/* 33  */
  strcpy(T3270[1554], "D8D1");		/* 34  */
  strcpy(T3270[1555], "D8D2");		/* 35  */
  strcpy(T3270[1556], "D8D3");		/* 36  */
  strcpy(T3270[1557], "D8D4");		/* 37  */
  strcpy(T3270[1558], "D8D5");		/* 38  */
  strcpy(T3270[1559], "D8D6");		/* 39  */
  strcpy(T3270[1560], "D8D7");		/* 40  */
  strcpy(T3270[1561], "D8D8");		/* 41  */
  strcpy(T3270[1562], "D8D9");		/* 42  */
  strcpy(T3270[1563], "D85A");		/* 43  */
  strcpy(T3270[1564], "D85B");		/* 44  */
  strcpy(T3270[1565], "D85C");		/* 45  */
  strcpy(T3270[1566], "D85D");		/* 46  */
  strcpy(T3270[1567], "D85E");		/* 47  */
  strcpy(T3270[1568], "D85F");		/* 48  */
  strcpy(T3270[1569], "D860");		/* 49  */
  strcpy(T3270[1570], "D861");		/* 50  */
  strcpy(T3270[1571], "D8E2");		/* 51  */
  strcpy(T3270[1572], "D8E3");		/* 52  */
  strcpy(T3270[1573], "D8E4");		/* 53  */
  strcpy(T3270[1574], "D8E5");		/* 54  */
  strcpy(T3270[1575], "D8E6");		/* 55  */
  strcpy(T3270[1576], "D8E7");		/* 56  */
  strcpy(T3270[1577], "D8E8");		/* 57  */
  strcpy(T3270[1578], "D8E9");		/* 58  */
  strcpy(T3270[1579], "D86A");		/* 59  */
  strcpy(T3270[1580], "D86B");		/* 60  */
  strcpy(T3270[1581], "D86C");		/* 61  */
  strcpy(T3270[1582], "D86D");		/* 62  */
  strcpy(T3270[1583], "D86E");		/* 63  */
  strcpy(T3270[1584], "D86F");		/* 64  */
  strcpy(T3270[1585], "D8F0");		/* 65  */
  strcpy(T3270[1586], "D8F1");		/* 66  */
  strcpy(T3270[1587], "D8F2");		/* 67  */
  strcpy(T3270[1588], "D8F3");		/* 68  */
  strcpy(T3270[1589], "D8F4");		/* 69  */
  strcpy(T3270[1590], "D8F5");		/* 70  */
  strcpy(T3270[1591], "D8F6");		/* 71  */
  strcpy(T3270[1592], "D8F7");		/* 72  */
  strcpy(T3270[1593], "D8F8");		/* 73  */
  strcpy(T3270[1594], "D8F9");		/* 74  */
  strcpy(T3270[1595], "D87A");		/* 75  */
  strcpy(T3270[1596], "D87B");		/* 76  */
  strcpy(T3270[1597], "D87C");		/* 77  */
  strcpy(T3270[1598], "D87D");		/* 78  */
  strcpy(T3270[1599], "D87E");		/* 79  */
  strcpy(T3270[1600], "D87F");		/* 80  */


/* row  21  col 1 thru 80 */
  strcpy(T3270[1601], "D940");		/* 1  */
  strcpy(T3270[1602], "D9C1");		/* 2  */
  strcpy(T3270[1603], "D9C2");		/* 3  */
  strcpy(T3270[1604], "D9C3");		/* 4  */
  strcpy(T3270[1605], "D9C4");		/* 5  */
  strcpy(T3270[1606], "D9C5");		/* 6  */
  strcpy(T3270[1607], "D9C6");		/* 7  */
  strcpy(T3270[1608], "D9C7");		/* 8  */
  strcpy(T3270[1609], "D9C8");		/* 9  */
  strcpy(T3270[1610], "D9C9");		/* 10  */
  strcpy(T3270[1611], "D94A");		/* 11  */
  strcpy(T3270[1612], "D94B");		/* 12  */
  strcpy(T3270[1613], "D94C");		/* 13  */
  strcpy(T3270[1614], "D94D");		/* 14  */
  strcpy(T3270[1615], "D94E");		/* 15  */
  strcpy(T3270[1616], "D94F");		/* 16  */
  strcpy(T3270[1617], "D950");		/* 17  */
  strcpy(T3270[1618], "D9D1");		/* 18  */
  strcpy(T3270[1619], "D9D2");		/* 19  */
  strcpy(T3270[1620], "D9D3");		/* 20  */
  strcpy(T3270[1621], "D9D4");		/* 21  */
  strcpy(T3270[1622], "D9D5");		/* 22  */
  strcpy(T3270[1623], "D9D6");		/* 23  */
  strcpy(T3270[1624], "D9D7");		/* 24  */
  strcpy(T3270[1625], "D9D8");		/* 25  */
  strcpy(T3270[1626], "D9D9");		/* 26  */
  strcpy(T3270[1627], "D95A");		/* 27  */
  strcpy(T3270[1628], "D95B");		/* 28  */
  strcpy(T3270[1629], "D95C");		/* 29  */
  strcpy(T3270[1630], "D95D");		/* 30  */
  strcpy(T3270[1631], "D95E");		/* 31  */
  strcpy(T3270[1632], "D95F");		/* 32  */
  strcpy(T3270[1633], "D960");		/* 33  */
  strcpy(T3270[1634], "D961");		/* 34  */
  strcpy(T3270[1635], "D9E2");		/* 35  */
  strcpy(T3270[1636], "D9E3");		/* 36  */
  strcpy(T3270[1637], "D9E4");		/* 37  */
  strcpy(T3270[1638], "D9E5");		/* 38  */
  strcpy(T3270[1639], "D9E6");		/* 39  */
  strcpy(T3270[1640], "D9E7");		/* 40  */
  strcpy(T3270[1641], "D9E8");		/* 41  */
  strcpy(T3270[1642], "D9E9");		/* 42  */
  strcpy(T3270[1643], "D96A");		/* 43  */
  strcpy(T3270[1644], "D96B");		/* 44  */
  strcpy(T3270[1645], "D96C");		/* 45  */
  strcpy(T3270[1646], "D96D");		/* 46  */
  strcpy(T3270[1647], "D96E");		/* 47  */
  strcpy(T3270[1648], "D96F");		/* 48  */
  strcpy(T3270[1649], "D9F0");		/* 49  */
  strcpy(T3270[1650], "D9F1");		/* 50  */
  strcpy(T3270[1651], "D9F2");		/* 51  */
  strcpy(T3270[1652], "D9F3");		/* 52  */
  strcpy(T3270[1653], "D9F4");		/* 53  */
  strcpy(T3270[1654], "D9F5");		/* 54  */
  strcpy(T3270[1655], "D9F6");		/* 55  */
  strcpy(T3270[1656], "D9F7");		/* 56  */
  strcpy(T3270[1657], "D9F8");		/* 57  */
  strcpy(T3270[1658], "D9F9");		/* 58  */
  strcpy(T3270[1659], "D97A");		/* 59  */
  strcpy(T3270[1660], "D97B");		/* 60  */
  strcpy(T3270[1661], "D97C");		/* 61  */
  strcpy(T3270[1662], "D97D");		/* 62  */
  strcpy(T3270[1663], "D97E");		/* 63  */
  strcpy(T3270[1664], "D97F");		/* 64  */
  strcpy(T3270[1665], "5A40");		/* 65  */
  strcpy(T3270[1666], "5AC1");		/* 66  */
  strcpy(T3270[1667], "5AC2");		/* 67  */
  strcpy(T3270[1668], "5AC3");		/* 68  */
  strcpy(T3270[1669], "5AC4");		/* 69  */
  strcpy(T3270[1670], "5AC5");		/* 70  */
  strcpy(T3270[1671], "5AC6");		/* 71  */
  strcpy(T3270[1672], "5AC7");		/* 72  */
  strcpy(T3270[1673], "5AC8");		/* 73  */
  strcpy(T3270[1674], "5AC9");		/* 74  */
  strcpy(T3270[1675], "5A4A");		/* 75  */
  strcpy(T3270[1676], "5A4B");		/* 76  */
  strcpy(T3270[1677], "5A4C");		/* 77  */
  strcpy(T3270[1678], "5A4D");		/* 78  */
  strcpy(T3270[1679], "5A4E");		/* 79  */
  strcpy(T3270[1680], "5A4F");		/* 80  */


/* row  22  col 1 thru 80 */
  strcpy(T3270[1681], "5A50");		/* 1  */
  strcpy(T3270[1682], "5AD1");		/* 2  */
  strcpy(T3270[1683], "5AD2");		/* 3  */
  strcpy(T3270[1684], "5AD3");		/* 4  */
  strcpy(T3270[1685], "5AD4");		/* 5  */
  strcpy(T3270[1686], "5AD5");		/* 6  */
  strcpy(T3270[1687], "5AD6");		/* 7  */
  strcpy(T3270[1688], "5AD7");		/* 8  */
  strcpy(T3270[1689], "5AD8");		/* 9  */
  strcpy(T3270[1690], "5AD9");		/* 10  */
  strcpy(T3270[1691], "5A5A");		/* 11  */
  strcpy(T3270[1692], "5A5B");		/* 12  */
  strcpy(T3270[1693], "5A5C");		/* 13  */
  strcpy(T3270[1694], "5A5D");		/* 14  */
  strcpy(T3270[1695], "5A5E");		/* 15  */
  strcpy(T3270[1696], "5A5F");		/* 16  */
  strcpy(T3270[1697], "5A60");		/* 17  */
  strcpy(T3270[1698], "5A61");		/* 18  */
  strcpy(T3270[1699], "5AE2");		/* 19  */
  strcpy(T3270[1700], "5AE3");		/* 20  */
  strcpy(T3270[1701], "5AE4");		/* 21  */
  strcpy(T3270[1702], "5AE5");		/* 22  */
  strcpy(T3270[1703], "5AE6");		/* 23  */
  strcpy(T3270[1704], "5AE7");		/* 24  */
  strcpy(T3270[1705], "5AE8");		/* 25  */
  strcpy(T3270[1706], "5AE9");		/* 26  */
  strcpy(T3270[1707], "5A6A");		/* 27  */
  strcpy(T3270[1708], "5A6B");		/* 28  */
  strcpy(T3270[1709], "5A6C");		/* 29  */
  strcpy(T3270[1710], "5A6D");		/* 30  */
  strcpy(T3270[1711], "5A6E");		/* 31  */
  strcpy(T3270[1712], "5A6F");		/* 32  */
  strcpy(T3270[1713], "5AF0");		/* 33  */
  strcpy(T3270[1714], "5AF1");		/* 34  */
  strcpy(T3270[1715], "5AF2");		/* 35  */
  strcpy(T3270[1716], "5AF3");		/* 36  */
  strcpy(T3270[1717], "5AF4");		/* 37  */
  strcpy(T3270[1718], "5AF5");		/* 38  */
  strcpy(T3270[1719], "5AF6");		/* 39  */
  strcpy(T3270[1720], "5AF7");		/* 40  */
  strcpy(T3270[1721], "5AF8");		/* 41  */
  strcpy(T3270[1722], "5AF9");		/* 42  */
  strcpy(T3270[1723], "5A7A");		/* 43  */
  strcpy(T3270[1724], "5A7B");		/* 44  */
  strcpy(T3270[1725], "5A7C");		/* 45  */
  strcpy(T3270[1726], "5A7D");		/* 46  */
  strcpy(T3270[1727], "5A7E");		/* 47  */
  strcpy(T3270[1728], "5A7F");		/* 48  */
  strcpy(T3270[1729], "5B40");		/* 49  */
  strcpy(T3270[1730], "5BC1");		/* 50  */
  strcpy(T3270[1731], "5BC2");		/* 51  */
  strcpy(T3270[1732], "5BC3");		/* 52  */
  strcpy(T3270[1733], "5BC4");		/* 53  */
  strcpy(T3270[1734], "5BC5");		/* 54  */
  strcpy(T3270[1735], "5BC6");		/* 55  */
  strcpy(T3270[1736], "5BC7");		/* 56  */
  strcpy(T3270[1737], "5BC8");		/* 57  */
  strcpy(T3270[1738], "5BC9");		/* 58  */
  strcpy(T3270[1739], "5B4A");		/* 59  */
  strcpy(T3270[1740], "5B4B");		/* 60  */
  strcpy(T3270[1741], "5B4C");		/* 61  */
  strcpy(T3270[1742], "5B4D");		/* 62  */
  strcpy(T3270[1743], "5B4E");		/* 63  */
  strcpy(T3270[1744], "5B4F");		/* 64  */
  strcpy(T3270[1745], "5B50");		/* 65  */
  strcpy(T3270[1746], "5BD1");		/* 66  */
  strcpy(T3270[1747], "5BD2");		/* 67  */
  strcpy(T3270[1748], "5BD3");		/* 68  */
  strcpy(T3270[1749], "5BD4");		/* 69  */
  strcpy(T3270[1750], "5BD5");		/* 70  */
  strcpy(T3270[1751], "5BD6");		/* 71  */
  strcpy(T3270[1752], "5BD7");		/* 72  */
  strcpy(T3270[1753], "5BD8");		/* 73  */
  strcpy(T3270[1754], "5BD9");		/* 74  */
  strcpy(T3270[1755], "5B5A");		/* 75  */
  strcpy(T3270[1756], "5B5B");		/* 76  */
  strcpy(T3270[1757], "5B5C");		/* 77  */
  strcpy(T3270[1758], "5B5D");		/* 78  */
  strcpy(T3270[1759], "5B5E");		/* 79  */
  strcpy(T3270[1760], "5B5F");		/* 80  */


/* row  23  col 1 thru 80 */
  strcpy(T3270[1761], "5B60");		/* 1  */
  strcpy(T3270[1762], "5B61");		/* 2  */
  strcpy(T3270[1763], "5BE2");		/* 3  */
  strcpy(T3270[1764], "5BE3");		/* 4  */
  strcpy(T3270[1765], "5BE4");		/* 5  */
  strcpy(T3270[1766], "5BE5");		/* 6  */
  strcpy(T3270[1767], "5BE6");		/* 7  */
  strcpy(T3270[1768], "5BE7");		/* 8  */
  strcpy(T3270[1769], "5BE8");		/* 9  */
  strcpy(T3270[1770], "5BE9");		/* 10  */
  strcpy(T3270[1771], "5B6A");		/* 11  */
  strcpy(T3270[1772], "5B6B");		/* 12  */
  strcpy(T3270[1773], "5B6C");		/* 13  */
  strcpy(T3270[1774], "5B6D");		/* 14  */
  strcpy(T3270[1775], "5B6E");		/* 15  */
  strcpy(T3270[1776], "5B6F");		/* 16  */
  strcpy(T3270[1777], "5BF0");		/* 17  */
  strcpy(T3270[1778], "5BF1");		/* 18  */
  strcpy(T3270[1779], "5BF2");		/* 19  */
  strcpy(T3270[1780], "5BF3");		/* 20  */
  strcpy(T3270[1781], "5BF4");		/* 21  */
  strcpy(T3270[1782], "5BF5");		/* 22  */
  strcpy(T3270[1783], "5BF6");		/* 23  */
  strcpy(T3270[1784], "5BF7");		/* 24  */
  strcpy(T3270[1785], "5BF8");		/* 25  */
  strcpy(T3270[1786], "5BF9");		/* 26  */
  strcpy(T3270[1787], "5B7A");		/* 27  */
  strcpy(T3270[1788], "5B7B");		/* 28  */
  strcpy(T3270[1789], "5B7C");		/* 29  */
  strcpy(T3270[1790], "5B7D");		/* 30  */
  strcpy(T3270[1791], "5B7E");		/* 31  */
  strcpy(T3270[1792], "5B7F");		/* 32  */
  strcpy(T3270[1793], "5C40");		/* 33  */
  strcpy(T3270[1794], "5CC1");		/* 34  */
  strcpy(T3270[1795], "5CC2");		/* 35  */
  strcpy(T3270[1796], "5CC3");		/* 36  */
  strcpy(T3270[1797], "5CC4");		/* 37  */
  strcpy(T3270[1798], "5CC5");		/* 38  */
  strcpy(T3270[1799], "5CC6");		/* 39  */
  strcpy(T3270[1800], "5CC7");		/* 40  */
  strcpy(T3270[1801], "5CC8");		/* 41  */
  strcpy(T3270[1802], "5CC9");		/* 42  */
  strcpy(T3270[1803], "5C4A");		/* 43  */
  strcpy(T3270[1804], "5C4B");		/* 44  */
  strcpy(T3270[1805], "5C4C");		/* 45  */
  strcpy(T3270[1806], "5C4D");		/* 46  */
  strcpy(T3270[1807], "5C4E");		/* 47  */
  strcpy(T3270[1808], "5C4F");		/* 48  */
  strcpy(T3270[1809], "5C50");		/* 49  */
  strcpy(T3270[1810], "5CD1");		/* 50  */
  strcpy(T3270[1811], "5CD2");		/* 51  */
  strcpy(T3270[1812], "5CD3");		/* 52  */
  strcpy(T3270[1813], "5CD4");		/* 53  */
  strcpy(T3270[1814], "5CD5");		/* 54  */
  strcpy(T3270[1815], "5CD6");		/* 55  */
  strcpy(T3270[1816], "5CD7");		/* 56  */
  strcpy(T3270[1817], "5CD8");		/* 57  */
  strcpy(T3270[1818], "5CD9");		/* 58  */
  strcpy(T3270[1819], "5C5A");		/* 59  */
  strcpy(T3270[1820], "5C5B");		/* 60  */
  strcpy(T3270[1821], "5C5C");		/* 61  */
  strcpy(T3270[1822], "5C5D");		/* 62  */
  strcpy(T3270[1823], "5C5E");		/* 63  */
  strcpy(T3270[1824], "5C5F");		/* 64  */
  strcpy(T3270[1825], "5C60");		/* 65  */
  strcpy(T3270[1826], "5C61");		/* 66  */
  strcpy(T3270[1827], "5CE2");		/* 67  */
  strcpy(T3270[1828], "5CE3");		/* 68  */
  strcpy(T3270[1829], "5CE4");		/* 69  */
  strcpy(T3270[1830], "5CE5");		/* 70  */
  strcpy(T3270[1831], "5CE6");		/* 71  */
  strcpy(T3270[1832], "5CE7");		/* 72  */
  strcpy(T3270[1833], "5CE8");		/* 73  */
  strcpy(T3270[1834], "5CE9");		/* 74  */
  strcpy(T3270[1835], "5C6A");		/* 75  */
  strcpy(T3270[1836], "5C6B");		/* 76  */
  strcpy(T3270[1837], "5C6C");		/* 77  */
  strcpy(T3270[1838], "5C6D");		/* 78  */
  strcpy(T3270[1839], "5C6E");		/* 79  */
  strcpy(T3270[1840], "5C6F");		/* 80  */


/* row  24  col 1 thru 80 */
  strcpy(T3270[1841], "5CF0");		/* 1  */
  strcpy(T3270[1842], "5CF1");		/* 2  */
  strcpy(T3270[1843], "5CF2");		/* 3  */
  strcpy(T3270[1844], "5CF3");		/* 4  */
  strcpy(T3270[1845], "5CF4");		/* 5  */
  strcpy(T3270[1846], "5CF5");		/* 6  */
  strcpy(T3270[1847], "5CF6");		/* 7  */
  strcpy(T3270[1848], "5CF7");		/* 8  */
  strcpy(T3270[1849], "5CF8");		/* 9  */
  strcpy(T3270[1850], "5CF9");		/* 10  */
  strcpy(T3270[1851], "5C7A");		/* 11  */
  strcpy(T3270[1852], "5C7B");		/* 12  */
  strcpy(T3270[1853], "5C7C");		/* 13  */
  strcpy(T3270[1854], "5C7D");		/* 14  */
  strcpy(T3270[1855], "5C7E");		/* 15  */
  strcpy(T3270[1856], "5C7F");		/* 16  */
  strcpy(T3270[1857], "5D40");		/* 17  */
  strcpy(T3270[1858], "5DC1");		/* 18  */
  strcpy(T3270[1859], "5DC2");		/* 19  */
  strcpy(T3270[1860], "5DC3");		/* 20  */
  strcpy(T3270[1861], "5DC4");		/* 21  */
  strcpy(T3270[1862], "5DC5");		/* 22  */
  strcpy(T3270[1863], "5DC6");		/* 23  */
  strcpy(T3270[1864], "5DC7");		/* 24  */
  strcpy(T3270[1865], "5DC8");		/* 25  */
  strcpy(T3270[1866], "5DC9");		/* 26  */
  strcpy(T3270[1867], "5D4A");		/* 27  */
  strcpy(T3270[1868], "5D4B");		/* 28  */
  strcpy(T3270[1869], "5D4C");		/* 29  */
  strcpy(T3270[1870], "5D4D");		/* 30  */
  strcpy(T3270[1871], "5D4E");		/* 31  */
  strcpy(T3270[1872], "5D4F");		/* 32  */
  strcpy(T3270[1873], "5D50");		/* 33  */
  strcpy(T3270[1874], "5DD1");		/* 34  */
  strcpy(T3270[1875], "5DD2");		/* 35  */
  strcpy(T3270[1876], "5DD3");		/* 36  */
  strcpy(T3270[1877], "5DD4");		/* 37  */
  strcpy(T3270[1878], "5DD5");		/* 38  */
  strcpy(T3270[1879], "5DD6");		/* 39  */
  strcpy(T3270[1880], "5DD7");		/* 40  */
  strcpy(T3270[1881], "5DD8");		/* 41  */
  strcpy(T3270[1882], "5DD9");		/* 42  */
  strcpy(T3270[1883], "5D5A");		/* 43  */
  strcpy(T3270[1884], "5D5B");		/* 44  */
  strcpy(T3270[1885], "5D5C");		/* 45  */
  strcpy(T3270[1886], "5D5D");		/* 46  */
  strcpy(T3270[1887], "5D5E");		/* 47  */
  strcpy(T3270[1888], "5D5F");		/* 48  */
  strcpy(T3270[1889], "5D60");		/* 49  */
  strcpy(T3270[1890], "5D61");		/* 50  */
  strcpy(T3270[1891], "5DE2");		/* 51  */
  strcpy(T3270[1892], "5DE3");		/* 52  */
  strcpy(T3270[1893], "5DE4");		/* 53  */
  strcpy(T3270[1894], "5DE5");		/* 54  */
  strcpy(T3270[1895], "5DE6");		/* 55  */
  strcpy(T3270[1896], "5DE7");		/* 56  */
  strcpy(T3270[1897], "5DE8");		/* 57  */
  strcpy(T3270[1898], "5DE9");		/* 58  */
  strcpy(T3270[1899], "5D6A");		/* 59  */
  strcpy(T3270[1900], "5D6B");		/* 60  */
  strcpy(T3270[1901], "5D6C");		/* 61  */
  strcpy(T3270[1902], "5D6D");		/* 62  */
  strcpy(T3270[1903], "5D6E");		/* 63  */
  strcpy(T3270[1904], "5D6F");		/* 64  */
  strcpy(T3270[1905], "5DF0");		/* 65  */
  strcpy(T3270[1906], "5DF1");		/* 66  */
  strcpy(T3270[1907], "5DF2");		/* 67  */
  strcpy(T3270[1908], "5DF3");		/* 68  */
  strcpy(T3270[1909], "5DF4");		/* 69  */
  strcpy(T3270[1910], "5DF5");		/* 70  */
  strcpy(T3270[1911], "5DF6");		/* 71  */
  strcpy(T3270[1912], "5DF7");		/* 72  */
  strcpy(T3270[1913], "5DF8");		/* 73  */
  strcpy(T3270[1914], "5DF9");		/* 74  */
  strcpy(T3270[1915], "5D7A");		/* 75  */
  strcpy(T3270[1916], "5D7B");		/* 76  */
  strcpy(T3270[1917], "5D7C");		/* 77  */
  strcpy(T3270[1918], "5D7D");		/* 78  */
  strcpy(T3270[1919], "5D7E");		/* 79  */
  strcpy(T3270[1920], "5D7F");		/* 80  */

}


void src_line() 
{

  int s99;
  int x99;
  int I99;

  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  s99 = strlen(a_string);
  if (s99 < 72) 
  {
    x99 = 72 - s99;
    for (I99 = 0; I99 < x99; I99++) 
    {
      strcat(a_string, " ");
    }
  }

  snprintf(tfield2, sizeof(wk_strg), "%d", var_use);
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
  fputs(a_string, f_out);
  fflush(f_out);
}


void write_remark() 
{
  int x = 0;
  int I = 0;
  int s = 0;
  int s1 = 0;

  char tfield2[VAR_LGTH];
  char tfield2a[VAR_LGTH];

  var_use++;

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

    snprintf(tfield2, sizeof(wk_strg), "%d", var_use);
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
  fputs(a_string, f_out);
  fflush(f_out);
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


