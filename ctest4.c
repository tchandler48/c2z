
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

	int x;
      char a[20];
      char *p;
	 
int main(int argc, char *argv[])
	{
		printf("Hello Z390 World\n");
		printf("ctest4 strcpy test");

		strcpy(a, "abcdefghijklmnopq");
		printf("a = %s\n",a);

		p = strstr(a, "cde");
              if(p)
              {
                 printf("found cde in string a\n");
              }

              p = strstr(a, "xyz");
              if(p)
              {
                 printf("found zyz in string a\n");
              }
  
              if(!p)
              {
                 printf("xyz not found in string a\n");
              }
		
		printf("End of ctest4\n");
		
	}
