  
#define BUFSIZE             80
#define LINE_NUM            6
#define TOKEN_LEN           21
#define VAR_NAME            64
#define LLEN                33
#define TOKEN_LEN           21
#define MAX_VARS            30


  int abc;

  int def;
  int x;
  int y;
  int z;

  char xyz[25];

 char sheet[99][26][20]   = {0};
 char in_stack[MAX_VARS];

  int temp_byte[MAX_VARS];
  int flag[99][26]        = {0};


int main(int argc, char *argv[])
{

   printf("ctest19 Testing...\n");

   abc = 123;
   printf("abc = %d",abc);

   def = 9876;
   printf("def = %d\n",def);

   strcpy(xyz,"abcdefghijklmnopqrst");
   printf("xyz = %s\n",xyz);

   x = 1;
   temp_byte[x] = 8976;
   x = 1;
   printf("temp_byte1 = %d\n",temp_byte[x]);

   x = 5;
   temp_byte[x] = 10045;
   x = 5;
   printf("temp_byte5 = %d\n",temp_byte[x]);

   temp_byte[3] = 123;
   printf("temp_byte3 = %d\n",temp_byte[3]);

   x = 4;
   strcpy(in_stack[x], "This is entry 4");
   x = 4;
   printf("in_stack = %s",in_stack[x]);

   strcpy(in_stack[2], "Entry 2");
   printf(" in_stack = %s\n",in_stack[2]);




   printf("ctest19 End Testing...\n");


}
