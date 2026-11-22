

   char ch;
   char ln_holder[20];
    int x;

int main(int argc, char *argv[])
{
 
   printf("ctest20 test program\n");
   strcpy(ch, "a");
   ln_holder[2] = ch;
   printf("ch = %s\n",ch);
   printf(ln_holder[2] = %s\n",ln_holder[2]);


   x = 5;
   strcpy(ch, "a");
   ln_holder[x] = ch;
   printf("ch = %s\n",ch);
   x = 5;
   printf(ln_holder[x] = %s\n",ln_holder[x]);
 
   printf("ctest20 end program\n");
}
