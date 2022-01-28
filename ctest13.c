
  
   int *iv_stack;
  char **in_stack;
   int imax_vars = 0;
  char str[20];

   int I;
   int x;
   int y;
   int z;
   int row;
   int col;
   int maxm;
   int i;
   int j;


   int spreadsheet[99][26] = {0};
   int flag[99][26] = {0};
  char sheet[99][26][20]   = {0};

   int isNumber(char *);


int main () 
{
   int  test;
   int  syear;
   char age[5];
   char year[5];

   strcpy(age,"123");
   test = atoi(age);
   printf("age = %s\n",age);
   printf("test = %d\n",test);
   iv_stack[0] = test;
   
   for(I = 0; I < 5; I++)
   {
      printf("#2 iv_stack[I] = %d\n",iv_stack[I]);
   }

   z = 20;
   x = 2;
   y = 4;

   spreadsheet[x][y] = z;
   printf("#0 spreadsheet = %d\n",spreadsheet[x][y]);
   
   x = 1;
   y = 10;
   spreadsheet[x][y] = 87;
   printf("#1 spreadsheet = %d\n",spreadsheet[x][y]);
   
   row = 4;
   col = 6;
   if(isNumber(age))        /*  numeric cell */
   {
     spreadsheet[row][col] = atoi(age);
   }

   row = 4;
   col = 6;

   printf("#2 spreadsheet = %d\n",spreadsheet[row][col]);

   if((flag[row][col] == 1) && (spreadsheet[x][y] == 2))
   {
     I = 9999;
   }

   i = 5;
   j = 10;
   sheet[i][j] = '_';

   strcpy(sheet[row][col],age);


   return;
}

int isNumber(char str)
{
   int i,j,k,flag = 1;
  
   flag = 1;

   return flag;
}


