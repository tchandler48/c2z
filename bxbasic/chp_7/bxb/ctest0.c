    
  int x;

 char ch;
	  
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

   strcpy(ch, "a");
   if(isdigit(ch))
   {
     printf("isdigit = TRUE ch = %s\n",ch);
   }
   else
   {
     printf("isdigit != FALSE ch = %s\n",ch);
   }

   strcpy(ch, "9");
   if(isalpha(ch))
   {
     printf("isalpha = TRUE ch = %s\n",ch);
   }
   else
   {
     printf("isalpha != FALSE ch = %s\n",ch);
   }

   strcpy(ch, "#");
   if(isalnum(ch))
   {
     printf("isalnum = TRUE ch = %s\n",ch);
   }
   else
   {
     printf("isalnum != FALSE ch = %s\n",ch);
   }
 
}
