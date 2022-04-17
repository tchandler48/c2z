 
  
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
   int a;
   int b;
   int c;
   int d;
   int a1;
   int c1;

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

   printf("ctest13 Testing...\n");

   strcpy(age,"123");
   test = atoi(age);
   printf("age = %s\n",age);
   printf("test = %d\n",test);
   iv_stack[0] = test;
   
   for(I = 0; I < 1; I++)
   {
      printf("#2 iv_stack[I] = %d\n",iv_stack[I]);
   }

   z = 20;
   x = 2;
   y = 4;

   spreadsheet[x][y] = z;
   printf("A spreadsheet = %d\n",spreadsheet[x][y]);
   
   x = 1;
   y = 10;
   spreadsheet[x][y] = 87;
   printf("B spreadsheet = %d\n",spreadsheet[x][y]);
   
   row = 4;
   col = 6;
   if(isNumber(age))        /*  numeric cell */
   {
     spreadsheet[row][col] = atoi(age);
   }

   row = 1;
   col = 10;

   printf("C spreadsheet = %d\n",spreadsheet[row][col]);

   a = 2;
   b = 5;
   a1 = 1;
   flag[a][b] = a1;

   c = 3;
   d = 10;
   c1 = 2;
   spreadsheet[c][d] = c1;

   I = 0;
   if(flag[a][b] == 1)
   {
     I = 9999;
   }
   printf "#1 I = %d\n", I);

   I = 0;
   printf("a = %d\n",a);
   printf("b = %d\n",b);
   if((flag[a][b] == 1) && (spreadsheet[c][d] == 2))
   {
     I = 1234;
   }
   printf("D I = %d\n",I);

   i = 5;
   j = 10;
   sheet[i][j] = '_';

   printf("sheet E = %s\n",sheet[i][j]);
   return;
}

int isNumber(char str)
{
   int i,j,k,flag = 1;
  
   flag = 1;

   return flag;
}


