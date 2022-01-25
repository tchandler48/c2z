
  int *iv_stack;


int main () 
{
   int  test;
   char age[5];

   strcpy(age,"123");
   test = atoi(age);

   printf("age = %s\n",age);
   printf("test = %d\n",test);

   iv_stack[0] = test;
   printf("iv_stack[0] = %d\n",iv_stack[0]);

 
   return(0);

}
