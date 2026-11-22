
   char abc[10];
   int x;
   int x1;
   int d;

int main(int argc, char *argv[])
{
 
   printf("ctest14 test program\n");
   d = 3;
   while(x < d)
   {
     printf("x = %d\n",x);
   
     while(x1 < d)
     {
       printf("x1 = %d\n",x1);
       x1++;
     }
     x++;

   }
   printf("end of loop");
 
   printf("ctest14 end program\n");
}
