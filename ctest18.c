
   char abc[10];
   char ch;

   int x;
   int d;
   int pi;

int main(int argc, char *argv[])
{
 
   printf("ctest17 test program\n");

   x = 0;
   strcpy(abc, "    abc");
   pi = 0;
   ch = abc[pi];
 
   while(isspace(ch))
   {
      x++;
      pi++;
      ch = abc[pi];
   }
   printf("x = %d\n",x);

   pi = 0;
   ch = abc[pi];
   if(isspace(ch)
   {
      d++;
   }
   printf("d = %d\n",d);

   printf("ctest17 end program\n");
}
