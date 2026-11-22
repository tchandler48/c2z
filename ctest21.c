 
#define BUFSIZE             80
#define LINE_NUM            6
#define TOKEN_LEN           21
#define VAR_NAME            64
#define LLEN                33
#define TOKEN_LEN           21
#define MAX_VARS            30

   char r_string[BUFSIZE];
   char fielda[32];
   char fieldc[10];
   char varname[32];
   int  fieldb;
   int  I;
   int  len;
   int  xyz;
   int  def;
   int  ghi;
   int  jkl;
   int  mno;
   int  pqr;
   int  ii;
  
   char sn_stack[MAX_VARS][VAR_NAME];
    int sv_stack[MAX_VARS];

   char in_stack[MAX_VARS][VAR_NAME];
    int iv_stack[MAX_VARS];
 
   char array1[MAX_VARS][VAR_NAME];

	
int main(int argc, char *argv[])
{

  printf("Hello Z390 World\n");

  strcpy(fielda, "abcdefghi");
  printf("fielda = %s ",fielda);

  len = strlen(fielda);
  printf("len fielda = %d\n",len);

  I = 0;
  strcpy(varname, "fielda");
  strcpy(sn_stack[I], varname);
  printf("sn_stack 0 = %s\n",sn_stack[0]);

  I++;
  strcpy(sn_stack[I],fielda);
  printf("sn_stack 1 = %s\n",sn_stack[1]);


  ii = 0;
  strcpy(array1[ii], fielda);
  printf("array1 = %s\n",array1[ii]);

  ii = 1;
  strcpy(array1[ii], "98765");
  printf("array1 = %s\n",array1[ii];
  
  xyz = 12;
  printf("xyz = %d\n",xyz);

  I = 0;
  iv_stack[I] = 98;

  printf("iv_stack = %d\n",iv_stack[I]);

  I = 3;
  iv_stack[I] = 6758;
  printf("iv_stack = %d\n",iv_stack[I]);


  for(I = 0; I < 5; I++)
  {
     printf("I = %d\n",iv_stack[I]);
  }

   I = 0;
   sv_stack[I] = 11123;

   printf("sv_stack = %d\n",sv_stack[I]);



  printf("End of ctest21\n");

}
