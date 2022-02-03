  
  int abc;

  int def;
  int x;
  int y;
  int z;

  char xyz[25];

 char sheet[99][26][20]   = {0};
 char **in_stack;

  int *temp_byte;
  int flag[99][26]        = {0};


int main () 
{

   abc = 123;
   printf("abc = %d",abc);

   def = 9876;
   printf(" def = %d\n",def);

   strcpy(xyz,"abcdefghijklmnopqrst");
   printf("xyz = %s\n",xyz);

   x = 1;
   temp_byte[x] = 8976;
   printf("temp_byte = %d\n",temp_byte[x];

   x = 5;
   temp_byte[x] = 10045;
   printf("temp_byte = %d\n",temp_byte[x];

   temp_byte[3] = 123;
   printf("temp_byte = %d\n",temp_byte[3];

   x = 4;
   strcpy(in_stack[x], "This is entry 4");
   printf("in_stack = %s",in_stack[x]);

   strcpy(in_stack[2], "Entry 2");
   printf(" in_stack = %s",in_stack[2]);

   printf(" abc = %d\n",abc);

   x = 9999;
   y = 1;
   z = 2;
   flag[y][z] = x;
   printf("flag = %d \n",flag[y][z]);

   x = 8765;
   flag[3][8] = x;
   printf("flag = %d \n",flag[3][8]);

   y = 2;
   z = 1;
   strcpy(sheet[y][z], "test of sheet");
   printf("sheet = %s ",sheet[y][z]); 

   y = 3;
   z = 5;
   strcpy(sheet[y][z], xyz);
   printf("sheet = %s \n",sheet[y][z]); 


   return;

}
