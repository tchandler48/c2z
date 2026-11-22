

   char ch;


int main(int argc, char *argv[])
{
 
   printf("ctest10 test program\n");
   strcpy(ch, "3");
   if(isalpha(ch))
   {
      printf("ch is true\n");
   }
   else
   {
      printf("ch is NOT true\n");
   }

   strcpy(ch, "T");
   if(isalpha(ch))
   {
      printf("ch is true\n");
   }
   else
   {
      printf("ch is NOT true\n");
   }

   printf("ctest10 end program\n");
}
