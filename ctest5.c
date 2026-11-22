

      char ch;
  
	 
int main(int argc, char *argv[])
{
   printf("ctest5 test");

   strcpy(ch, "A");
   if(isdigit(ch) == 0)
   {
     printf("this is numeric\n");
   }
   else
   {
     printf("this NOT numeric\n");
   }

   if(!isdigit(ch) == 0)
   {
      printf("is not\n")
   }
   else
   {
      printf("it is\n");
   }

   strcpy(ch, "1");
   if(isdigit(ch) == 0)
   {
     printf("this is numeric\n");
   }
   else
   {
     printf("this NOT numeric\n");
   }


   printf("End of ctest5\n");
}
