
    int z2;
    int z3;
    int z4;
    int i;
    int j;
    int pi;
    int s;
    int cmd_byte = 0;
    int pgm_byte = 0;
 /*   int day, month, year; */
 /*   int hour, min, sec; */
    int t,i1,j1,i2,j2,k,l,m,n,row,col;
    int jj,i9;

    char ch;

    char day[2];
    char month[2];
    char year[4];

    char hour[2];
    char min[2];
    char sec[2];
 
    char input[18];#include "c2z_time.h"

    int sum = 0;
    int avg = 0;
    int value;

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
    int I;
    int x;
    int z1;

    char cellnum[7];
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
    char str[20];

    char f_date[11];
    char f_mth[3];
    char f_day[3];
    char f_yr[5];

    char f_time[9];
    char f_hr[3];
    char f_min[3];
    char f_sec[3];

 
      char sheet[99][26][18]   = {0};
      char src[99][26][18]     = {0};
       int flag[99][26]        = {0};
       int spreadsheet[99][26] = {0};

      FILE *fp;

     double Expression(void);
       int IsAddop(char);
    double Term(void);
    double Factor(void);
      void Match(char);
       int IsAddop(char);
       int IsMultop(char);
       int Is_White(char);
      void SkipWhite(void);
      void _GetChar(void);
    double GetNum(void);
      void Save_wsp(void);
      void Load_wsp(void);
      void Prog_dsp(void);
      void Get_date(void);
      void Get_time(void);
      void Math_dsp(void);
      void Cell_dsp(void);
      void View_dsp(void);
      void Clear_pr(void);
      void Top_proc(void);
      void Bot_proc(void);
      void Sum_proc(void);
      void Avg_proc(void);
      void Rng_proc(void);
      void Sqrt_pr(void);
      void Date_pr(void);
      void Mth_proc(void);
      void Day_proc(void);
      void Yr_proc(void);
      void Time_pr(void);
      void Hour_pr(void);
      void Min_proc(void);
      void Sec_proc(void);
      void Up_proc(void);
      void Down_pr(void);
      void Left_pr(void);
      void Right_pr(void);
      void Print_pr(void);
    double asc_2_dbl(void);
      void Pow_dsp(void);
      void Load_hdr(void);
       int isNumber(char *);
    double Expression(void);	
    double Term(void);
      void Get_Time(void);
      void Save_wsp(void);	
      void Load_wsp(void);
      void Cell_cvt(void);
      void footer(void);


int main(int argc, char *argv[])
{
  int opa, ops, opm, opd;
  int process = 0;
           
  char *sub;
  
  strcpy(sheet_nm, "*CELL");
  strcpy(wsp_name, "EMPTY");

  Load_hdr();  

  strcpy(sheet_nm, "EMPTY");
  strcpy(wsp_name, "EMPTY ");
  rct = 0;
  cct = 1;
  Cell_dsp();


}


void Cell_dsp()
{
  printf("  \n");

  Get_date();
  Get_time();
 
  printf("   %s",f_date);

  printf("     Sheet Name -> %s",sheet_nm);
  printf("    Workspace Name -> %s ",wsp_name);
  printf("   %s\n",f_time);
  printf("  \n");
  
  sheet[2][1] = 'M';
  sheet[3][2] = 'N';
  sheet[4][3] = 'P';
  sheet[5][4] = 'Q';
  sheet[5][5] = 'R';
  strcpy(sheet[6][1], "TOMC");
  strcpy(sheet[13][3], "CHANDLER");

  i = 0;

  printf("          "); 
  for(j = cct; j <= cct+3; j++)
  {
     printf("%18s",sheet[i][j]); 
  }
  printf(" \n");
  printf(" \n");

  if(rct == 0)
  {
    rct = 1;
  }

  j = 0;

  for(i = rct; i <= rct+15; i++)
  {
    printf("%d",i);
    for(j = cct; j <= cct+3; j++)
    {
      printf("%18s",sheet[i][j]);
    }
    printf("\n");
  }

  footer();     
}

void Load_hdr()
{
  sheet[0][1] = 'A';
  sheet[0][2] = 'B';
  sheet[0][3] = 'C';
  sheet[0][4] = 'D';
  sheet[0][5] = 'E';
  sheet[0][6] = 'F';
  sheet[0][7] = 'G';
  sheet[0][8] = 'H';
  sheet[0][9] = 'I';
  sheet[0][10] = 'J';
  sheet[0][11] = 'K';
  sheet[0][12] = 'L';
  sheet[0][13] = 'M';
  sheet[0][14] = 'N';
  sheet[0][15] = 'O';
  sheet[0][16] = 'P';
  sheet[0][17] = 'Q';
  sheet[0][18] = 'R';
  sheet[0][19] = 'S';
  sheet[0][20] = 'T';
  sheet[0][21] = 'U';
  sheet[0][22] = 'V';
  sheet[0][23] = 'W';
  sheet[0][24] = 'X';
  sheet[0][25] = 'Y';
  sheet[0][26] = 'Z';

  printf("Loading..\n");
  for(i = 1; i <= 99; i++)      
  {
    printf(".");
    for(j = 1; j < 26; j++)
    {
      sheet[i][j] = '_';
      src[i][j] = '_'; 
   /*   flag[i][j] = 0; */
      printf(".");
    }
    printf(".\n");
  }
}

void footer()
{
  printf(" Cmds:  *EXIT  *LOAD  *SAVE");
  printf("  *HOME  *CLEAR  *PROG  *CELL  *MATH\n");
  printf("       ");
  printf(" *VIEW  *TOP   *BOT   *UP    *DOWN   *LEFT  *RIGHT \n");
}



void Get_date()
{
  char tmp_var2[2];
  char tmp_var4[4];
  char date[8];
 
  date = *localtime("date");
  printf("month #1 = %s\n",tm[0].tm_mon);
  printf("day   #1 = %s\n",tm[0].tm_mday);
  printf("year  #1 = %s\n",tm[0].tm_year);

  strcpy(f_date, tm[0].tm_mon);
  strcat(f_date, "/");
  strcat(f_date, tm[0].tm_mday); 
  strcat(f_date, "/");          
  strcat(f_date, tm[0].tm_year); */
}


void Get_time()
{
  char tmp_var2[2];
  char tmp_var4[4];
  char time[8];

  time = *localtime("time");
  printf("hour  #1 = %s\n",tm[0].tm_hour);
  printf("min   #1 = %s\n",tm[0].tm_min);
  printf("sec   #1 = %s\n",tm[0].tm_sec);

  strcpy(f_time, tm[0].tm_hour);
  strcat(f_time, ":");
  strcat(f_time, tm[0].tm_min);
  strcat(f_time, ":");
  strcat(f_time, tm[0].tm_sec);
}

