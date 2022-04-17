  int abc;
  int x;
  int y;
  int col;
  int row;
  int I;
 

  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;

  int value;
  int i9;
  int jj;

  char tt[8];

 char sheet[99][26][18]   = {0};
  int spreadsheet[99][26] = 0;

int main () 
{

    strcpy(tt, "1234");
    a = atoi(tt);
    printf("a = %d\n",a);

    strcpy(sheet[2][3], "B");
    printf("B %s\n",sheet[2][3];

    sheet[1][1] = 'A';
    printf("A %s\n",sheet[1][1];

   sheet[2][1] = 'M';
   sheet[3][2] = 'N';
   sheet[4][3] = 'P';
   sheet[5][4] = 'Q';
   strcpy(sheet[5][5], "TOMCH");
   
   row = 5;
   col = 5;

   if((strlen(sheet[row][col]) > 12)
   {
     printf("inside = %d\n",a);
   }

   printf("b4 18\n");
   printf("%18s\n",sheet[2][1];
   printf("%18s\n",sheet[4][3];
   printf("%18s\n",sheet[5][4];

   x = 3;
   y = 2;
   printf("%18s\n",sheet[x][y];
   printf("%18s\n",sheet[5][5];
  
  for(I = 0; I < 5; I++)
   {
      printf("I #1 = %d\n",I);
   }

   b = 5;
   for(I = 0; I < b; I++)
   {
      printf("I #2 = %d\n",I);
   }

   b = 1;

   if((a == 1) || (b == 1) || (c == 1) || (d == 1))
   {
      printf("inside if\n");
   }

   i9 = 2;
   jj = 10;
   spreadsheet[i9][jj] = 0;

   printf("#a spreadsheet = %d\n",spreadsheet[i9][jj]);

   printf("%18d\n",spreadsheet[i9][jj];

   value = spreadsheet[i9][jj];
   printf("value = %d\n",value);

   sprintf(sheet[i9][jj], "%.2f", value);

   printf("sheet = %s\n",sheet[x][y]);


}

