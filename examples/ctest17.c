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
  int age = 0;

  int value;
  int i9;
  int jj;

  char tt[20];
  


 char sheet[99][26][18]   = {0};
  int spreadsheet[99][26] = 0;

  int *iv_stack;

int main () 
{
    printf("Enter age -> \n");
    scanf("%d",age);
    printf("age = %d\n",age);

    strcpy(tt, "987");
    a = atoi(tt);
    printf("a = %d\n",a);

    i9 = 2;
    jj = 4;
    spreadsheet[i9][jj] = atoi(tt);
    printf("spreadsheet = %d\n",spreadsheet[i9][jj]);
}

