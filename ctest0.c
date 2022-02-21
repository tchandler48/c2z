
  int x;
  int y;

 char xyz[20];

 int *iv_stack;
	 
 char **sv_stack;

int main(int argc, char *argv[])
{
   printf("Line Number One\n");

   x = 1 + 2 + 3;
   printf("x = %d",x);

   printf("Line Number Two\n");

   printf("Line Number Three\n");

   y = 0;
   strcpy(sv_stack[y], "abcde");
   printf("sv_stack[y] = %s \n",sv_stack[y]);

   y = 1;
   strcpy(sv_stack[y], "12345");
   printf("sv_stack[y] = %s \n",sv_stack[y]);

  
   printf("sv_stack[0] = %s ",sv_stack[0]);

   printf("x = %d \n",x);

   y = 0;
   iv_stack[y] = 123;

   printf(" iv_stack[y] = %d",iv_stack[y]);

   printf(" iv_stack[0] = %d\n",iv_stack[0]);

}

