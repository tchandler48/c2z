 
/*	vmex.c		*/

#include "c2z_time.h"

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
    int z2;
    int z3;
    int z4;
    int i;
    int j;
    int pi;
    int s;
    int cmd_byte = 0;
    int pgm_byte = 0;
    int t,i1,j1,i2,j2,k,l,m,n,row,col;
    int jj,i9;

    char ch;

    char day[2];
    char month[2];
    char year[4];

    char hour[2];
    char min[2];
    char sec[2];
 
    char input[18];
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
 
  while(1)
  {

start1:
    printf("Enter the CMD or cell id: -> \n");
    scanf("%s",cellnum);

    s = strlen(cellnum);
    s--;
  
    I = 0;
    ch = cellnum[I];
    while(ch != ' ')
    {
      toupper(ch);
      cellnum[I] = ch;
      I++;
      ch = cellnum[I];
    }
    cellnum[I] = '\0';

    cmd_byte = 0;
    process = 0;
    if(strcmp(cellnum, "*EXIT") == 0)
    {
      cmd_byte = 1;
      process = 1;
    }

    if(strcmp(cellnum, "*CELL") == 0)
    {
      cmd_byte = 2;
      process = 1;
    }

    if(strcmp(cellnum, "*PROG") == 0)
    {
      cmd_byte = 3;
      process = 1;
    }

    if(strcmp(cellnum, "*FLAG") == 0)
    {
      cmd_byte = 4;
      process = 1;
    }

    if(strcmp(cellnum, "*MATH") == 0)
    {
      cmd_byte = 5;
      process = 1;
    }

    if(strcmp(cellnum, "*SAVE") == 0)
    {
      cmd_byte = 6;
      process = 1;
    }

    if(strcmp(cellnum, "*LOAD") == 0)
    {
      cmd_byte = 7;
      process = 1;
    }

    if(strcmp(cellnum, "*VIEW") == 0)
    {
      cmd_byte = 8;
      process = 1;
    }

    if(strcmp(cellnum, "*CLEAR") == 0)
    {
      cmd_byte = 9;
      process = 1;
    }

    if(strcmp(cellnum, "*HOME") == 0)
    {
      cmd_byte = 10;
      process = 1;
    }

    if(strcmp(cellnum, "*TOP") == 0)
    {
      cmd_byte = 11;
      process = 1;
    }

    if(strcmp(cellnum, "*BOT") == 0)
    {
       cmd_byte = 12;
       process = 1;
    }

    if(strcmp(cellnum, "*UP") == 0)
    {
      cmd_byte = 13;
      process = 1;
    }

    if(strcmp(cellnum, "*DOWN") == 0)
    {
      cmd_byte = 14;
      process = 1;
    }

    if(strcmp(cellnum, "*LEFT") == 0)
    {
      cmd_byte = 15;
      process = 1;
    }

    if(strcmp(cellnum, "*RIGHT") == 0)
    {
      cmd_byte = 16;
      process = 1;
    }

    if(strcmp(cellnum, "*PRINT") == 0)
    {
      cmd_byte = 17;
      process = 1;
    }

    switch(cmd_byte)
    {   
       case 1:      
         exit;
         break;

       case 2:             
         goto skip_save; 
         break;

       case 3:            
         Prog_dsp();
         goto start1;
         break;

       case 4:             
         break;            

       case 5:             
         Math_dsp();
         goto start1;
         break;

       case 6:             
         printf("Saved Workspace Name --> \n");
         scanf("%s",wkspace);
         Save_wsp();
         strcpy(wsp_name, wkspace);
         goto skip_save;          
         break;

       case 7:             
         printf("Load Workspace Name --> \n");
         scanf("%s",wkspace);
         Load_wsp();
         strcpy(wsp_name, wkspace);
         goto skip_save;          
         break;

       case 8:             
         View_dsp();
         goto start1;
         break;

       case 9:             
         Clear_pr();
         goto skip_save;           
         break;

       case 10:             
         rct = 0;
         cct = 1;
         goto skip_save;
         break;

       case 11:            
         Top_proc();
         goto skip_save;
         break;

       case 12:             
         Bot_proc();
         goto skip_save;
         break;

       case 13:             
         Up_proc();
         goto skip_save;
         break;

       case 14:             
         Down_pr();
         goto skip_save;
         break;

       case 15:             
         Left_pr();
         goto skip_save;
         break;

       case 16:            
         Right_pr();
         goto skip_save;
         break;

       case 17:             
         Print_pr();
         goto print_loop;
         break;
    }

    Cell_cvt();

    opa = 0;
    ops = 0;
    opm = 0;
    opd = 0;

    printf("Enter the value to be inserted -> \n");
    scanf("%s", input);
    s = strlen(input);
    s--;

printf("#2 input = %s\n",input);
printf("#2 input s = %d\n",s);
printf("#2 row = %d\n",row);
printf("#2 col = %d\n",col);

    /*  load source (program) */
    strcpy(src[row][col], input);
printf("B %s\n",src[row][col];



    p = strstr(input, "=");
    if(!p) 
    {
      p2 = strstr(input, "-");
      if(p2)
      {
        p1 = strstr(input, ".");
        if(p1)
        {
          value = atof(input);
          spreadsheet[row][col] = value;
          flag[row][col] = 1;
          sprintf(sheet[row][col], "%.2f", value);
        }
        else
        {
          z4 = atoi(input);
          sprintf(sheet[row][col], "%d", z4);
          flag[row][col] = 1; 
          spreadsheet[row][col] = z4;
        }
      }
    }
 
    if(!p) 
    { 
        strcpy(sheet[row][col], input);
        if(strlen(sheet[row][col]) > 17)
        {
          sheet[row][col][17] = '\0';
        }
    }

skip_save:

    /* *** Re-Compute *** */
       
    for(i9 = 1; i9 <= 99; i9++)
    {
      for(jj = 1; jj <= 26; jj++)  		
      {
        proc_cel = 0;
        strcpy(input, src[i9][jj]);
        p = strstr(input, "_");
        if(!p)
        { 
          opa = 0;
          ops = 0;
          opm = 0;
          opd = 0;

          p = strstr(input, "+");
          if(p)
          {
            opa = 1;
          }

          p = strstr(input, "-");
          if(p)
          {
            opa = 1;
          }
                
          p = strstr(input, "*");
          if(p)
          { 
            opa = 1;
          }

          p = strstr(input, "/");
          if(p)
          {
             opa = 1;
          }

          if((opa == 1) || (ops == 1) || (opm == 1) || (opd == 1))
          {
             pi = 0;
             z3 = 1;
             z4 = 1;
          }

          p1 = strstr(input, "=");
          p2 = strstr(input, "-");

          if((!p1) && (p2))
          {
            p1 = strstr(input, ".");
            if(p1)
            {
              value = spreadsheet[i9][jj];
              sprintf(sheet[i9][jj], "%.2f", value);
            }
            else
            {
              z4 = spreadsheet[i9][jj];
              sprintf(sheet[i9][jj], "%d", z4);
            }
          }
      
          pgm_byte = 0;
          p = strstr(input, "SUM");
          if(p)
          {
             pgm_byte = 1; 
          }

          switch(pgm_byte)
          {   
             case 1:             /* SUM */
               Sum_proc();
               break;

          }
        }
      }
    }

print_loop:
                  
     strcpy(sheet_nm, "*CELL");
     Cell_dsp();
   }

   return;
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


void Prog_dsp()
{
  int i, j;

  Get_date();
  Get_time();
    
  strcpy(sheet_nm, "*PROG");
  printf(" %s",f_date);
  printf("     Sheet Name -> %s",sheet_nm);
  printf("    Workspace Name -> %s",wsp_name);
  printf("       %s\n",f_time);
  printf("   \n");
  
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

  for(i = rct; i <= rct+15; i++)
  {
     printf("%d",i);
     for(j = cct; j <= cct+3; j++)
     {
       printf("%18s",src[i][j]);
     }
     printf("\n");
  }

  footer();
}


void Math_dsp()
{
  int i, j;

  Get_date();
   
  strcpy(sheet_nm, "*MATH");
  printf(" %s",f_date);
  printf("     Sheet Name -> %s",sheet_nm);
  printf("    Workspace Name -> %s",wsp_name);
  printf("       %s\n",f_time);
  printf("   \n");

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

  for(i = rct; i <= rct+15; i++)
  {
    printf(" %d ",i);

    for(j = cct; j <= cct+3; j++)
    {
      printf("%18d",spreadsheet[i][j]);
    }
    printf(" \n");
  }

  footer();
}



void Save_wsp()
{

}

void Load_wsp()
{

}

void View_dsp()
{

}

void Clear_pr()
{

}

void Top_proc()
{

}

void Bot_proc()
{

}

void Up_proc()
{

}

void Down_pr()
{

}

void Left_pr()
{
  cct = cct - 4;
  if(cct <= 3)
  {
    cct = 1;
  }
}


void Right_pr()
{
  cct = cct + 4;
  if(cct >= 24)
  (
    cct = 23;
  }
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


void Cell_cvt()
{
  ch = cellnum[0];
printf("ch #1 = %s\n",ch);

  if(ch == 'A')
  {
     col = 1;       
printf("col  #1 = %d\n",col);
  }

  if(ch == 'B')
  {
     col = 2;       
printf("col  #2 = %d\n",col);
  }

  if(ch == 'C')
  {
     col = 3;       
printf("col  #3 = %d\n",col);
  }

  if(ch == 'D')
  {
     col = 4;       
printf("col  #4 = %d\n",col);
  }

  I = 1;
  s = 0;
  ch = cellnum[I];
  while(ch != '\0')
  {
     varname[s] = ch;
     s++;
     I++;
     ch = cellnum[I];
   }
   varname[s] = '\0';
printf("varname = %s\n",varname);

   row = atoi(varname);
   
  printf("row #R1 = %d\n",row); 

}


int isNumber(char str)
{
  int i;
  int j;
  int k,flag = 1;

  for(i = 0; str[i] != '\0'; i++)
  {
    if((str[i] >= '0' && str[i] <= '9') || (str[i] == '.'))
    {
       flag = 1;
    }
    else
    {
       flag = 0;
    }
  }
  return flag;
}


void footer()
{
  printf(" Cmds:  *EXIT  *LOAD  *SAVE");
  printf("  *HOME  *CLEAR  *PROG  *CELL  *MATH\n");
  printf("       ");
  printf(" *VIEW  *TOP   *BOT   *UP    *DOWN   *LEFT  *RIGHT \n");
}


int rdp_start()
{
  int value;

  value = Expression();

  return value;
}



int Expression()	
{
  char ch;
   
  int Value;

  z1 = 0;
  z4 = 0;
 
  ch = input[pi];
  if(ch != '=')
  {
     Value = 0;
     return;
  }

  while(ch != '=')
  {
     pi++;
     ch = input[pi];
  }
  pi++; 
  ch = input[pi];		
  varname[0] = ch;
  varname[1] = '\0';
  epos = pi;
  if(IsAddop(ch))
  {  
     Value = 0;  		
  }
  else
  {
    Value = Term();
    pi = epos;
    ch = input[pi];
  }

  while(IsAddop(ch))
  {
    switch(ch)
    {
      case '+':
        Match('+');
        Value = Value + Term();
        break;
    
      case '-':
        Match('-');
        Value = Value - Term();
        break;

      default:
        break;
    }
    pi = epos;
    ch = input[pi];
  }
  return Value;
}



int Term()		
{   
  char ch;
  int pi;
  int Value;

  Value = Factor();

  pi = epos;
  ch = input[pi];
  while(IsMultop(ch))
  {
    switch(ch)
    {
      case '*':
        Match('*');
        Value = Value * Factor();   
        break;
    
      case '/':
        Match('/');
        Value = Value / Factor();   
        break;

      case '^':
        Match('^');
        Value = pow(Value, Factor()); 
        break;

      default:
        break;
    }
    pi = epos;
    ch = input[pi];
  }
  return Value;
}



int Factor()                        
{ 
   int pi;
   int value;
   int x;
   int z2;
   int z1;
   int z3;
   int z4;

   pi = epos; 
   ch = input[pi];

   if(ch == '(')
   {
     Match('(');
     value = Expression();
     Match(')');
   }
   else
   {
     if(isalpha(ch))			
     {
        z2 = 0;
        z1 = 0;
        ch = input[pi];
        x = strlen(input);

        for(z3 = z4; z3 <= x; z3++)
        {
           if(ch == ' ')
           {
              break;
           }
           if(ch == '+')
           {
              break;
           }
           if(ch == '-')
           {
              break;
           }
           if(ch == '*')
           {
              break;
           }
           if(ch == '/')
           {
              break;
           }
           if(ch == ' ')
           {
              break;
           }
           
           if(ch != '=')
           {
              wk_row[z2] = ch;
              z2++;
           }
           z1++;
           pi++;
           ch = input[pi];
        }
        wk_row[z2] = '\0';

        z3++;
        z3++;
        z4 = z3;

        x = strlen(wk_row);
        if(x == 2)
        {
             if((wk_row[0] >= 'A') && (wk_row[0] <= 'Z'))
             {
                z2 = 0;
                for(z1 = 1; z1 <= 26; z1++)
                {
                   if(wk_row[0] == sheet[z2][z1])
                   {
                      mcol = z1;
                      break;
                   }
                }
             }
             else
             {
                z2 = 0;
                for(z1 = 1; z1 <= 26; z1++)
                {
                   if(wk_row[0] == sheet[z2][z1])
                   {
                      mcol = z1;
                      break;
                   }
                }
         /*     mrow = wk_row[1] - '1'+1;  */
              }
        }

        if(x == 3)
        {
             if((wk_row[0] >= 'A') && (wk_row[0] <= 'Z'))
             {
                z2 = 0; */
/*                      */
/*                for(z1 = 1; z1 <= 26; z1++) */
/*                {          */
/*                   if(wk_row[0] == sheet[z2][z1]) */
/*                   {  */
/*                      mcol = z1; */
/*                      break; */
/*                   } */
/*                } *;
             }
             else
             {
                z2 = 0;

/*                for(z1 = 1; z1 <= 26; z1++) */
/*                {  */
/*                   if(wk_row[0] == sheet[z2][z1])  */
/*                   {  */
/*                      mcol = z1; */
/*                      break;  */
/*                   }  */
/*                }  */

/*                wk_row1[0] = wk_row[1];  */
/*                wk_row1[1] = wk_row[2];  */
/*                wk_row1[2] = '\0';  */
/*                mrow = atoi(wk_row1);  */

              }  
           }  

          value = spreadsheet[mrow][mcol];

          epos = pi;
     }
     else				
     {
         value = GetNum(); 
     }
  }
  return value;
}


int GetNum()			
{   
   char ch;
   int pi;
   int value = 0;

   pi = epos;
   ch = input[pi];
   if((!isdigit(ch)) && (ch != '.'))
   {
     /*strcpy(t_holder, "Numeric Value"); */
     
   }
   value = asc_2_dbl();
   return value;
}


int asc_2_dbl()
{   
   char ch, cvalue[33];
   int pi, vi_pos=0;
   int fvalue;

   pi = epos;
   ch = input[pi];
   while((isdigit(ch)) || (ch == '.') && (vi_pos <= 32))
   {
     cvalue[vi_pos] = ch;
     pi++;
     vi_pos++;
     ch = input[pi];
   }
   cvalue[vi_pos] = '\0';
   fvalue = atof(cvalue);                 
   epos = pi;
   return fvalue;
}


int IsAddop(char ch) 		
{   
   int rval=0;

   if((ch == '+') || (ch == '-'))
   {
     rval = 1;
   }
   return rval;
}



int IsMultop(char ch) 		
{   
  int rval = 0;

  if(ch == '\0')
  {                       
    rval = 0;           
  }
  else if(strchr("*^/%", ch))
  {
    rval = 1;
  }
  return rval;
}



void Match(char x)             
{   
   char ch, string[6];
   int pi;

   pi = epos;
   ch = input[pi];
   if(ch != x)
   {
     strcpy(string, "\" \"");
     string[1] = x;
   }
   else
   {
     _GetChar();
     SkipWhite();
   }
}



void SkipWhite() 	
{   
   char ch;
   int pi;

   pi = epos;
   ch = input[pi];
   while(Is_White(ch))
   {
     _GetChar();
     pi = epos;
     ch = input[pi];
   }
}



void _GetChar()
{
  epos++;
}


int Is_White(char ch)
{   
   int test=0;

   if((ch == ' ') || (ch == '\t'))
   {
     test = -1;
   }
   return test;
}


void Sum_proc()
{
printf("input = %s\n",input);

   sum = 0;
   sub = strstr(input,"(");
   if(sub == NULL)
   {
      printf("SUM Input Error!\n");
   }
   else
   {
      z1 = 0;
      z4 = 0;
      z2 = 0;
      ch = input[z1];
      while(ch != '(')
      {
         z1++;
         ch = input[z1];
      }
      z1++;
      ch = input[z1];
      while(ch != ',')
      {
         wk_row[z2] = ch;
         z1++;
         z2++;
         ch = input[z1];
      }
      wk_row[z2] = '\0';

      x = strlen(wk_row);

      if(x == 2)
      {
         if((wk_row[0] >= 'A') && (wk_row[0] <= 'Z'))
         {      
                z2 = 0;
                z4 = 1;
                
                for(z4 = 1; z4 <= 26; z4++)
                {
                   if(wk_row[0] == sheet[z2][z4])
                   {
                      j1 = z4;
                      break;
                   }
                }
           /*   i1 = wk_row[1] - '1'+1;  */
          }
      }

      if(x == 3)
      {
             ch = wk_row[0];

             if((ch >= 'A') && (ch <= 'Z'))
             {
                z2 = 0;
                z4 = 1;
                for(z4 = 1; z4 <= 26; z4++)
                {
                   if(ch == sheet[z2][z4])
                   {
                      j1 = z4;
                      break;
                   }
                }

             wk_row[0] = wk_row[1];
             wk_row[1] = wk_row[2];
             wk_row[2] = '\0';
             i1 = atoi(wk_row);        /* now have row number */
             }
      }


      z2 = 0;
      z1++;
      ch = input[z1];
      while(ch != ')')
      {
         wk_row[z2] = ch;
         z1++;
         z2++;
         ch = input[z1];
      }
      wk_row[z2] = '\0';

      x = strlen(wk_row);
      if(x == 2)
      {
         if((wk_row[0] >= 'A') && (wk_row[0] <= 'Z'))
         {      
                z2 = 0;
                z4 = 1;
                for(z4 = 1; z4 <= 26; z4++)
                {
                   if(wk_row[0] == sheet[z2][z4])
                   {
                      j2 = z4;
                      break;
                   }
                }
          /*    i2 = wk_row[1] - '1'+1;  */
          }
      }

      if(x == 3)
      {
             if((wk_row[0] >= 'A') && (wk_row[0] <= 'Z'))
             {
                z2 = 0;
                z4 = 1;
                for(z4 = 1; z4 <= 26; z4++)
                {
                   if(wk_row[0] == sheet[z2][z4])
                   {
                      j2 = z4;
                      break;
                   }
                }

             wk_row[0] = wk_row[1];
             wk_row[1] = wk_row[2];
             wk_row[2] = '\0';
             i2 = atoi(wk_row);       
             }
      }


      if(i2 == i1)
      {
         for(j = j1; j <= j2; j++)
         {
            if(flag[i1][j] == 1)
            {
               sum += spreadsheet[i1][j];
               cnt++;
            }
         }
      }

      if(j2 == j1)
      {
         for(i = i1; i <= i2; i++)
         {
            if(flag[i][j1] == 1)
            {
               sum += spreadsheet[i][j1];
               cnt++;
            }
         }
      }

      sprintf(sheet[i9][jj],"%.2f",sum);
      if(strlen(sheet[i9][jj]) > 12)
      {
         sheet[i9][jj][12] = '\0';
      }
   }
}
       