

   char ch;


int main(int argc, char *argv[])
{
 
   printf("ctest11 test program\n");
   strcpy(ch, "A");
   printf("ch = %s\n",ch);

   while(isupper(ch))
   {
      printf("ch is true\n");
   }
  

   strcpy(ch, "z");
   printf("ch = %s\n",ch);

   while(!isupper(ch))
   {
      printf("ch is true\n");
   }
  

   printf("ctest11 end program\n");
}
