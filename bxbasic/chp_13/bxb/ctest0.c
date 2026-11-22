	  
  int x;
  int y;

 char ch;
 char quote='\"';

 char str_a[32];
 char str_b[32];

 char name[32];
 char number[8];
	  
int main(int argc, char *argv[])
{
   printf("Hello Z390 World\n");

   strcpy(str_a, "abcdefghijk");
   printf("str_a = %s\n",str_a);

   for(x=0; x < 25; x++)
   {
     printf("x = %d\n",x);
   }  
}
