
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

    double sum = 0;
    double avg = 0;
    double value;

    int num_row = 99;
    int num_col = 26;
    int num_lgth = 20;
    int maxm = 0;
    int minm = 0;
    int proc_cel = 0;
    int cnt = 0;
    int epos = 0;
    int mrow = 0;
    int mcol = 0;
    int rct = 0;		
    int cct = 1;		
    int row;
    int col;
    int x;
    int z1;
    int z2;
    int z3;
    int z4;
    int i;
    int j;
    int pi;
    int cmd_byte = 0;
    int pgm_byte = 0;
    int day, month, year;
    int hour, min, sec;
    int t,i1,j1,i2,j2,k,l,m,n,row,col;
    int jj,i9;

    char input[20];
    char cellnum[6];
    char varname[4];
    char wkspace[9];
    char *sub;
    char wk_row[4];
    char wk_row1[4];
    char ch;
    char wk_file[12];
    char *p;
    char *p1;
    char *p2;
    char sheet_nm[9];
    char wsp_name[9];
    char f_date[11];
    char f_mth[3];
    char f_day[3];
    char f_yr[5];
    char f_time[9];
    char f_hr[3];
    char f_min[3];
    char f_sec[3];

    double spreadsheet[99][26] = 0;
      char sheet[99][26][20]   = {0};
      char src[num_row][num_col][num_lgth]     = {0};
       int flag[99][26]        = 0;
      
      FILE *fp;

int main(int argc, char *argv[])
{
       int opa, ops, opm, opd;
           
       char *sub;
      
       strcpy(sheet_nm, "This is a TEST");
       strcpy(wsp_name, "EMPTY");

       i = 0;
       j = 1;
       src[i][j][0] = 'A';

       i = 0;
       j = 2;
       src[i][j][0] = 'B';

       i = 1;
       j = 1;
       src[i][j][0] = '_';

       i = 1;
       j = 2;
       src[i][j][0] = '_';

       i = 0;
       j = 1;
       printf("src = %s\n",src[i][j][0]);
       
       i = 0;
       j = 2;   
       printf("src = %s\n",src[i][j][0]);

       i = 1;
       j = 1;
       printf("src = %s\n",src[i][j][0]);

       i = 1;
       j = 2;
       printf("src = %s\n",src[i][j][0]);

       src[12][2][0] = 'This is a test';
       printf("src = %s\n",src[12][2][0]);
 
}


