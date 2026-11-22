    
  int x;
  int y;
 
 char ch;
 char quote='\"';

 char str_a[32];
 char str_b[32];
	  
int main(int argc, char *argv[])
{
   printf("Hello Z390 World\n");

   x = 2;

   if(x == 1)
   {
     printf("if(x == TRUE x = %d\n",x);
   }
   else
   {
     printf("if(x != FALSE x != %d\n",x);
   }

   strcpy(ch, "6");
   if(isdigit(ch))
   {
     printf("isdigit = TRUE ch = %s\n",ch);
   }
   else
   {
     printf("isdigit != FALSE ch = %s\n",ch);
   }

   strcpy(ch, quote);
   if(isalpha(quote))
   {
     printf("isalpha = TRUE ch = %s\n",ch);
   }
   else
   {
     printf("isalpha != FALSE ch = %s\n",ch);
   }

   strcpy(ch, "(");
   if(isalnum(ch))
   {
     printf("isalnum = TRUE ch = %s\n",ch);
   }
   else
   {
     printf("isalnum != FALSE ch = %s\n",ch);
   }

   strcpy(str_a, "abcdefghijklmnopq");
   printf("str_a = %s\n",str_a);

   y = 7;
   strncpy(str_b, str_a, y);
   printf("str_b = %s\n",str_b);

   strncpy(str_b, str_a, 4);
   printf("str_b = %s\n",str_b);

 
}
