
  int x;
  int t;
  int i = 1;
  int j = 3;

 char abc[20];
 char def[25];
	 
int main(int argc, char *argv[])
{
   printf("Hello Z390 World\n");

   x = 1 + 2 + 3;
   printf("x = %d\n",x);

   x = i * j;
   printf(("x = %d\n",x);

   strcpy(abc,"don$");
   x = strlen(abc);
   printf("x = %d\n",x);

   t = 0;
   def[t] = 'T';
   t = 1;
   def[t] = 'E';
   t = 2;
  
   def[t] = '\0';
   printf("def = %s\n",def);
   x = strlen(def);
   printf("x = %d\n",x);

}
