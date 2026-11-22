 
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

  strcpy(fielda, "abcdefghijhkl");
  printf("fielda = %s ",fielda);

  len = strlen(fielda);
  printf("len fielda = %d\n",len);

  I = 0;
  strcpy(sn_stack[I], fielda);
  printf("sn_stack I = %s\n",sn_stack[I]);

  len = strlen(sn_stack[I]);
  printf("len sn_stack[I] = %d\n",len);
 
  ii = 0;
  strcpy(array1[ii], fielda);
  printf("array1 = %s\n",array1[ii]);


  I++;
  strcpy(sn_stack[I],fielda);
  printf("sn_stack 1 = %s\n",sn_stack[1]);


 

  ii = 1;
  strcpy(array1[ii], "98765");
  printf("array1 = %s\n",array1[ii];
  
 


  printf("End of ctest23\n");

}
