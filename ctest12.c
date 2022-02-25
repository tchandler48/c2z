
  
   int *iv_stack;
  char **in_stack;
   int imax_vars = 0;

   int I;
   int x;


int main () 
{
   int  test;
   int  syear;
   char age[5];
   char year[5];
   printf("ctest12 Testing...\n");

   strcpy(age,"123");
   test = atoi(age);

   printf("age = %s\n",age);
   printf("test = %d\n",test);

   iv_stack[0] = test;
   x = 0;
   printf("#0 iv_stack[x] = %d\n",iv_stack[x]);
   printf("#0a iv_stack[0] = %d\n",iv_stack[0]);

   strcpy(year, "2021");
   x = 1;
   iv_stack[x] = atoi(year); 

   iv_stack[3] = atoi(year);

   for(I = 0; I < 5; I++)
   {
      printf("#2 iv_stack[I] = %d\n",iv_stack[I]);
   }
 
 
   return(0);

}
